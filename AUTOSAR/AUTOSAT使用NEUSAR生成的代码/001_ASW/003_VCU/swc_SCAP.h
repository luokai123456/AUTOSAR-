/*
 * File: swc_SCAP.h
 *
 * Code generated for Simulink model 'swc_SCAP'.
 *
 * Model version                  : 6.223
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Aug 14 10:27:28 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_SCAP_h_
#define RTW_HEADER_swc_SCAP_h_
#ifndef swc_SCAP_COMMON_INCLUDES_
#define swc_SCAP_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_swc_SCAP.h"
#endif                                 /* swc_SCAP_COMMON_INCLUDES_ */

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
  float32 hvbd_pct_BookChrgnTarValFb;
  boolean hvbd_b_CampModeFb;
  uint8 hvbd_st_CampModeFbFailrReason;
  uint8 hvbd_st_otaHvOnOFFReqSts;
  uint8 hvbd_st_otaHvOnOffFailInfo;
} vcsb_HVSM;

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

/* PublicStructure Variables for Internal Data, for system '<S6>/SwitchRampMOTMaxPeakTrq' */
typedef struct {
  uint8 is_c11_Ricardo_SW_dev_lib;     /* '<S20>/Chart' */
  uint8 is_U2_TO_U1;                   /* '<S20>/Chart' */
  uint8 is_U1_TO_U2;                   /* '<S20>/Chart' */
  uint8 is_active_c11_Ricardo_SW_dev_li;/* '<S20>/Chart' */
} ARID_DEF_switch_ramp_swc_SCAP_T;

/* PublicStructure Variables for Internal Data, for system '<S6>/SwitchRampMOTMaxTrq' */
typedef struct {
  uint8 is_c11_Ricardo_SW_dev_lib;     /* '<S22>/Chart' */
  uint8 is_U2_TO_U1;                   /* '<S22>/Chart' */
  uint8 is_U1_TO_U2;                   /* '<S22>/Chart' */
  uint8 is_active_c11_Ricardo_SW_dev_li;/* '<S22>/Chart' */
} ARID_DEF_switch_ramp_swc_SC_f_T;

/* PublicStructure Variables for Internal Data, for system '<S6>/SwitchRampMOTMinPeakTrq' */
typedef struct {
  uint8 is_c11_Ricardo_SW_dev_lib;     /* '<S24>/Chart' */
  uint8 is_U2_TO_U1;                   /* '<S24>/Chart' */
  uint8 is_U1_TO_U2;                   /* '<S24>/Chart' */
  uint8 is_active_c11_Ricardo_SW_dev_li;/* '<S24>/Chart' */
} ARID_DEF_switch_ramp_swc_SC_k_T;

/* PublicStructure Variables for Internal Data, for system '<S6>/SwitchRampMOTMinTrq' */
typedef struct {
  uint8 is_c11_Ricardo_SW_dev_lib;     /* '<S26>/Chart' */
  uint8 is_U2_TO_U1;                   /* '<S26>/Chart' */
  uint8 is_U1_TO_U2;                   /* '<S26>/Chart' */
  uint8 is_active_c11_Ricardo_SW_dev_li;/* '<S26>/Chart' */
} ARID_DEF_switch_ramp_swc_SC_d_T;

/* PublicStructure Variables for Internal Data, for system '<S19>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S35>/Unit Delay' */
} ARID_DEF_SR_latch_swc_SCAP_T;

/* PublicStructure Variables for Internal Data, for system '<S19>/SwitchRampMOTMaxTrq1' */
typedef struct {
  uint8 is_c11_Ricardo_SW_dev_lib;     /* '<S39>/Chart' */
  uint8 is_U2_TO_U1;                   /* '<S39>/Chart' */
  uint8 is_U1_TO_U2;                   /* '<S39>/Chart' */
  uint8 is_active_c11_Ricardo_SW_dev_li;/* '<S39>/Chart' */
} ARID_DEF_switch_ramp_swc_S_dk_T;

/* PublicStructure Variables for Internal Data, for system '<S62>/switch_ramp' */
typedef struct {
  uint8 is_c11_Ricardo_SW_dev_lib;     /* '<S76>/Chart' */
  uint8 is_U2_TO_U1;                   /* '<S76>/Chart' */
  uint8 is_U1_TO_U2;                   /* '<S76>/Chart' */
  uint8 is_active_c11_Ricardo_SW_dev_li;/* '<S76>/Chart' */
} ARID_DEF_switch_ramp_swc_SC_c_T;

/* PublicStructure Variables for Internal Data, for system '<S118>/SwitchRampMOTMaxTrqLim' */
typedef struct {
  uint8 is_c11_Ricardo_SW_dev_lib;     /* '<S123>/Chart' */
  uint8 is_U2_TO_U1;                   /* '<S123>/Chart' */
  uint8 is_U1_TO_U2;                   /* '<S123>/Chart' */
  uint8 is_active_c11_Ricardo_SW_dev_li;/* '<S123>/Chart' */
} ARID_DEF_switch_ramp_swc_SC_h_T;

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  ARID_DEF_switch_ramp_swc_SC_h_T ARID_DEF_SwitchRampMOTMinTrqLi;/* '<S118>/SwitchRampMOTMinTrqLim' */
  ARID_DEF_switch_ramp_swc_SC_h_T ARID_DEF_SwitchRampMOTMaxTrqLi;/* '<S118>/SwitchRampMOTMaxTrqLim' */
  ARID_DEF_switch_ramp_swc_S_dk_T ARID_DEF_switch_ramp;/* '<S58>/switch_ramp' */
  ARID_DEF_switch_ramp_swc_SC_c_T ARID_DEF_switch_ramp_m;/* '<S62>/switch_ramp' */
  ARID_DEF_switch_ramp_swc_S_dk_T ARID_DEF_SwitchRampMOTMaxTrq1;/* '<S19>/SwitchRampMOTMaxTrq1' */
  ARID_DEF_SR_latch_swc_SCAP_T ARID_DEF_SR_latch1;/* '<S19>/SR_latch1' */
  ARID_DEF_SR_latch_swc_SCAP_T ARID_DEF_SR_latch;/* '<S19>/SR_latch' */
  ARID_DEF_switch_ramp_swc_SC_d_T ARID_DEF_SwitchRampMOTMinTrq;/* '<S6>/SwitchRampMOTMinTrq' */
  ARID_DEF_switch_ramp_swc_SC_k_T ARID_DEF_SwitchRampMOTMinPeakT;/* '<S6>/SwitchRampMOTMinPeakTrq' */
  ARID_DEF_switch_ramp_swc_SC_f_T ARID_DEF_SwitchRampMOTMaxTrq;/* '<S6>/SwitchRampMOTMaxTrq' */
  ARID_DEF_switch_ramp_swc_SCAP_T ARID_DEF_SwitchRampMOTMaxPeakT;/* '<S6>/SwitchRampMOTMaxPeakTrq' */
  float32 DataTypeConversion2;         /* '<Root>/Data Type Conversion2' */
  float32 DataTypeConversion16;        /* '<Root>/Data Type Conversion16' */
  float32 DataTypeConversion46;        /* '<Root>/Data Type Conversion46' */
  float32 DataTypeConversion30;        /* '<Root>/Data Type Conversion30' */
  float32 DataTypeConversion31;        /* '<Root>/Data Type Conversion31' */
  float32 DataTypeConversion34;        /* '<Root>/Data Type Conversion34' */
  float32 DataTypeConversion38;        /* '<Root>/Data Type Conversion38' */
  float32 DataTypeConversion65;        /* '<Root>/Data Type Conversion65' */
  float32 DataTypeConversion49;        /* '<Root>/Data Type Conversion49' */
  float32 DataTypeConversion66;        /* '<Root>/Data Type Conversion66' */
  float32 DataTypeConversion68;        /* '<Root>/Data Type Conversion68' */
  float32 DataTypeConversion67;        /* '<Root>/Data Type Conversion67' */
  float32 DataTypeConversion69;        /* '<Root>/Data Type Conversion69' */
  float32 y;                           /* '<S125>/Chart' */
  float32 y_o;                         /* '<S123>/Chart' */
  float32 y_o2;                        /* '<S98>/Chart' */
  float32 y_b;                         /* '<S76>/Chart' */
  float32 y_j;                         /* '<S39>/Chart' */
  float32 UnitDelay1_DSTATE;           /* '<S80>/Unit Delay1' */
  float32 UnitDelay1_DSTATE_f;         /* '<S81>/Unit Delay1' */
  float32 t_wait;                      /* '<S89>/timed_delay' */
  float32 t_wait_b;                    /* '<S88>/timed_delay' */
  float32 t_wait_bk;                   /* '<S87>/timed_delay' */
  float32 t_wait_a;                    /* '<S86>/timed_delay' */
  float32 t_wait_l;                    /* '<S38>/timed_delay' */
  uint8 DataTypeConversion71;          /* '<Root>/Data Type Conversion71' */
  ElMac DataTypeConversion60;          /* '<Root>/Data Type Conversion60' */
  DriveDir DataTypeConversion8;        /* '<Root>/Data Type Conversion8' */
  uint8 is_c14_Ricardo_SW_dev_lib;     /* '<S89>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_li;/* '<S89>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib_h;   /* '<S88>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev__n;/* '<S88>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib_i;   /* '<S87>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev__i;/* '<S87>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib_i5;  /* '<S86>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev__f;/* '<S86>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib_d;   /* '<S38>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_fv;/* '<S38>/timed_delay' */
  boolean DataTypeConversion160;       /* '<Root>/Data Type Conversion160' */
  boolean DataTypeConversion58;        /* '<Root>/Data Type Conversion58' */
  boolean DataTypeConversion12;        /* '<Root>/Data Type Conversion12' */
  boolean DataTypeConversion28;        /* '<Root>/Data Type Conversion28' */
  boolean DataTypeConversion70;        /* '<Root>/Data Type Conversion70' */
  boolean DataTypeConversion138;       /* '<Root>/Data Type Conversion138' */
  boolean DataTypeConversion57;        /* '<Root>/Data Type Conversion57' */
  boolean DataTypeConversion52;        /* '<Root>/Data Type Conversion52' */
  boolean DelayInput1_DSTATE;          /* '<S90>/Delay Input1' */
  boolean DelayInput1_DSTATE_h;        /* '<S91>/Delay Input1' */
  boolean DelayInput1_DSTATE_g;        /* '<S9>/Delay Input1' */
  boolean DelayInput1_DSTATE_l;        /* '<S10>/Delay Input1' */
  boolean DelayInput1_DSTATE_e;        /* '<S11>/Delay Input1' */
  boolean DelayInput1_DSTATE_d;        /* '<S12>/Delay Input1' */
  boolean Relay2_Mode;                 /* '<S7>/Relay2' */
  boolean Relay1_Mode;                 /* '<S7>/Relay1' */
  boolean Relay_Mode;                  /* '<S7>/Relay' */
} ARID_DEF_swc_SCAP_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S109>/2-D Lookup Table5'
   *   '<S110>/2-D Lookup Table4'
   *   '<S68>/2-D Lookup Table5'
   *   '<S69>/2-D Lookup Table4'
   */
  uint32 pooled6[2];
} ConstP_swc_SCAP_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_swc_SCAP_T swc_SCAP_ARID_DEF;

/* Constant parameters (default storage) */
extern const ConstP_swc_SCAP_T swc_SCAP_ConstP;

/* Exported data declaration */
#define swc_SCAP_START_SEC_CONST_VOLATILE
#include "swc_SCAP_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_CAL */
extern const volatile boolean eadc_b_disMot2BrkTqDurgESP;/* Referenced by: '<S7>/Constant3' */

/* Disable Secondary EAD Braking Torque during ESP Intervention */
extern const volatile boolean eadc_b_disMot2BstTqDurgESP;/* Referenced by: '<S7>/Constant1' */

/* Disable Secondary EAD Boosting Torque during ESP Intervention */
extern const volatile boolean eadc_b_disMot2TqInGear0;/* Referenced by: '<S7>/Constant4' */

/* Disable Secondary EAD Torque when actual gear is 0 */
extern const volatile boolean eadc_b_enaMot2GenGearR;/* Referenced by: '<S7>/Constant6' */

/* Enable Secondary EAD generation in gear R */
extern const volatile boolean eadc_b_enaMot2GenInEVGearR;/* Referenced by: '<S7>/Constant7' */

/* Enable Secondary EAD generation in gear R during EV mode */
extern const volatile boolean eadc_b_enaMot2Tq;/* Referenced by: '<S7>/Constant12' */

/* Enable Secondary EAD Torque */
extern const volatile boolean eadc_b_useActTq2SwtOffMot2;/* Referenced by:
                                                          * '<S6>/Constant11'
                                                          * '<S6>/Constant12'
                                                          * '<S6>/Constant15'
                                                          * '<S6>/Constant19'
                                                          */

/* Use Actual Torque to switch-off Secondary EAD Motor */
extern const volatile float32 eadc_n_mot2GenDisHiThdRev_rpm;/* Referenced by: '<S7>/Relay1' */

/* Secondary EAD high speed threshold for EAD generation disabling in reverse gear */
extern const volatile float32 eadc_n_mot2GenDisLoThdRev_rpm;/* Referenced by: '<S7>/Relay1' */

/* Secondary EAD low speed threshold for EAD generation disabling in reverse gear */
extern const volatile float32 eadc_n_mot2GenEnaHiThdFwd_rpm;/* Referenced by: '<S7>/Relay' */

/* Secondary EAD high speed threshold for EAD generation enabling in forward gear */
extern const volatile float32 eadc_n_mot2GenEnaLoThdFwd_rpm;/* Referenced by: '<S7>/Relay' */

/* Secondary EAD low speed threshold for EAD generation enabling in forward gear */
extern const volatile float32 eadc_tq_mot2MnTqDecGrad_Nmps;/* Referenced by:
                                                            * '<S6>/Constant21'
                                                            * '<S6>/Constant5'
                                                            */

/* Secondary EAD min torque decrease gradient when enabled */
extern const volatile float32 eadc_tq_mot2MnTqIncGradESP_Nmps;/* Referenced by:
                                                               * '<S6>/Constant13'
                                                               * '<S6>/Constant20'
                                                               */

/* Secondary EAD min torque increase gradient during ESP intervention */
extern const volatile float32 eadc_tq_mot2MnTqIncGrad_Nmps;/* Referenced by:
                                                            * '<S6>/Constant10'
                                                            * '<S6>/Constant18'
                                                            */

/* Secondary EAD min torque increase gradient when disabled */
extern const volatile float32 eadc_tq_mot2MxTqDecGradESP_Nmps;/* Referenced by:
                                                               * '<S6>/Constant24'
                                                               * '<S6>/Constant25'
                                                               */

/* Secondary EAD max torque decrease gradient during ESP intervention */
extern const volatile float32 eadc_tq_mot2MxTqDecGrad_Nmps;/* Referenced by:
                                                            * '<S6>/Constant23'
                                                            * '<S6>/Constant6'
                                                            */

/* Secondary EAD max torque decrease gradient when disabled */
extern const volatile float32 eadc_tq_mot2MxTqIncGrad_Nmps;/* Referenced by:
                                                            * '<S6>/Constant14'
                                                            * '<S6>/Constant4'
                                                            */

/* Secondary EAD max torque increase gradient when enabled */
extern const volatile float32 eadc_tq_mot2SwtOffThd_Nm;/* Referenced by: '<S6>/Constant9' */

/* Motor torque threshold for Secondary EAD switch-off */
extern const volatile float32 eadf_mot2MnTqLim_X_motSpd_rpm[11];
                                   /* Referenced by: '<S8>/1-D Lookup Table3' */

/* Secondary EAD Min Torque Limit Map - EAD Speed Axis */
extern const volatile float32 eadf_mot2MnTqLim_Y_Nm[11];
                                   /* Referenced by: '<S8>/1-D Lookup Table3' */

/* Secondary EAD Min Torque Limit Map - torque */
extern const volatile float32 eadf_mot2MxTqLim_X_motSpd_rpm[11];
                                   /* Referenced by: '<S8>/1-D Lookup Table2' */

/* Secondary EAD Max Torque Limit Map - EAD Speed Axis */
extern const volatile float32 eadf_mot2MxTqLim_Y_Nm[11];
                                   /* Referenced by: '<S8>/1-D Lookup Table2' */

/* Secondary EAD Max Torque Limit Map - torque */
extern const volatile float32 ptla_ead2Eff_Y_MotSpd_rpm[21];/* Referenced by:
                                                             * '<S109>/2-D Lookup Table5'
                                                             * '<S110>/2-D Lookup Table4'
                                                             * '<S68>/2-D Lookup Table5'
                                                             * '<S69>/2-D Lookup Table4'
                                                             */

/* Secondary EAD Motor Efficiency - Motor Speed Axis */
extern const volatile boolean ptlc_b_enaHVBSTPwrLimIn4WDMod;/* Referenced by: '<S58>/Constant5' */

/* Enable HVB Short-term Power limits in 4WD Mode */
extern const volatile boolean ptlc_b_enaHVBSTPwrLimInEVMod;/* Referenced by: '<S58>/Constant4' */

/* Enable HVB Short-term Power limits in EV Mode */
extern const volatile boolean ptlc_b_enaHVBSTPwrLimInSportMod;/* Referenced by: '<S58>/Constant2' */

/* Enable HVB Short-term Power limits in Sport Mode */
extern const volatile boolean ptlc_b_enaMotSTPwrLimIn4WDMod;/* Referenced by: '<S57>/Constant5' */

/* Enable Motors Short-term Power limits in 4WD Mode */
extern const volatile boolean ptlc_b_enaMotSTPwrLimInEVMod;/* Referenced by: '<S57>/Constant4' */

/* Enable Motors Short-term Power limits in EV Mode */
extern const volatile boolean ptlc_b_enaMotSTPwrLimInSportMod;/* Referenced by: '<S57>/Constant1' */

/* Enable Motors Short-term Power limits in Sport Mode */
extern const volatile float32 ptlc_f_bmsMaxChgCurrPreFidLvl1Factor;/* Referenced by: '<S58>/Constant59' */

/* Bms charge Current high level 1 pre FID */
extern const volatile float32 ptlc_f_bmsMaxChgCurrPreFidLvl2Factor;/* Referenced by: '<S58>/Constant62' */

/* Bms charge Current high level 2 pre FID */
extern const volatile float32 ptlc_f_bmsMaxDischCurrPreFidLvl1Factor;/* Referenced by: '<S58>/Constant27' */

/* Bms discharge Current high level 1 pre FID */
extern const volatile float32 ptlc_f_bmsMaxDischCurrPreFidLvl2Factor;/* Referenced by: '<S58>/Constant31' */

/* Bms discharge Current high level 2 pre FID */
extern const volatile float32 ptlc_fact_vehLvl2DerateDecGrad;/* Referenced by:
                                                              * '<S58>/Constant16'
                                                              * '<S62>/Constant16'
                                                              */

/* Vehicle level 2 fault discharge power derating factor decrease gradient */
extern const volatile float32 ptlc_fact_vehLvl2DerateIncGrad;/* Referenced by:
                                                              * '<S58>/Constant14'
                                                              * '<S62>/Constant14'
                                                              */

/* Vehicle level 2 fault discharge power derating factor increase gradient */
extern const volatile float32 ptlc_frac_hvbChEff;/* Referenced by: '<S58>/Constant1' */

/* Battery charge efficiency */
extern const volatile float32 ptlc_frac_hvbDischEff;/* Referenced by: '<S58>/Constant3' */

/* Battery discharge efficiency */
extern const volatile float32 ptlc_frac_motBrkEffGain;/* Referenced by:
                                                       * '<S109>/Constant3'
                                                       * '<S68>/Constant3'
                                                       */
extern const volatile float32 ptlc_frac_motBstEffGain;/* Referenced by:
                                                       * '<S110>/Constant5'
                                                       * '<S69>/Constant5'
                                                       */
extern const volatile float32 ptlc_pct_bmsCurrLimitPctPreFid;/* Referenced by: '<S81>/Constant54' */

/* power limit percent of bms current Pre FID */
extern const volatile float32 ptlc_s_preFidDlyTm_s;/* Referenced by:
                                                    * '<S58>/Constant28'
                                                    * '<S58>/Constant32'
                                                    * '<S58>/Constant60'
                                                    * '<S58>/Constant63'
                                                    */

/* Pre FID delay on time */
extern const volatile float32 ptlf_X_hvbSocForDerate_pct[7];
                                  /* Referenced by: '<S58>/1-D Lookup Table3' */

/* HVB Discharge Power Derating f(SOC) Map - SOC Axis */
extern const volatile float32 ptlf_Y_hvbDsChrgDerate_fact[7];
                                  /* Referenced by: '<S58>/1-D Lookup Table3' */

/* HVB Discharge Power Derating f(SOC) Map - factor */
extern const volatile float32 ptlf_ead2BrkEff_X_MotTrq_Nm[21];/* Referenced by:
                                                               * '<S109>/2-D Lookup Table5'
                                                               * '<S68>/2-D Lookup Table5'
                                                               */

/* Secondary EAD Motor Brake Efficiency - Motor Torque Axis */
extern const volatile float32 ptlf_ead2BstEff_X_MotTrq_Nm[21];/* Referenced by:
                                                               * '<S110>/2-D Lookup Table4'
                                                               * '<S69>/2-D Lookup Table4'
                                                               */

/* Secondary EAD Motor Boost Efficiency - Motor Torque Axis */
extern const volatile float32 ptlf_ead2MaxTqCorrSOC_X_SOC_pct[4];
                                  /* Referenced by: '<S62>/1-D Lookup Table6' */

/* Secondary EAD Max Torque Correction f(SOC) Map - SOC Axis */
extern const volatile float32 ptlf_ead2MaxTqCorrSOC_Y_frac[4];
                                  /* Referenced by: '<S62>/1-D Lookup Table6' */

/* Secondary EAD Max Torque Correction f(SOC) Map - factor */
extern const volatile float32 ptlf_ead2MaxTqLmtTemp_Y_factor[2];
                                  /* Referenced by: '<S62>/1-D Lookup Table1' */

/* Secondary EAD Max Torque Limit f(Moter Temperature) Map - factor */
extern const volatile float32 ptlf_ead2MaxTqLmt_X_MotTemp_C[2];
                                  /* Referenced by: '<S62>/1-D Lookup Table1' */

/* Secondary EAD Max Torque Limit f(Moter Temperature) Map - Temp Axis */
extern const volatile float32 ptlf_ead2MinTqCorrSOC_X_SOC_pct[4];
                                  /* Referenced by: '<S62>/1-D Lookup Table7' */

/* Secondary EAD Min Torque Correction f(SOC) Map - SOC Axis */
extern const volatile float32 ptlf_ead2MinTqCorrSOC_Y_frac[4];
                                  /* Referenced by: '<S62>/1-D Lookup Table7' */

/* Secondary EAD Min Torque Correction f(SOC) Map - factor */
extern const volatile float32 ptlf_ead2MinTqCorr_X_VehSpd_kph[5];
                                  /* Referenced by: '<S62>/1-D Lookup Table4' */

/* Secondary EAD Min Torque Correction f(Spd) Map - Vehicle Speed Axis */
extern const volatile float32 ptlf_ead2MinTqCorr_Y_frac[5];
                                  /* Referenced by: '<S62>/1-D Lookup Table4' */

/* Secondary EAD Min Torque Correction f(Spd) Map - factor */
extern const volatile float32 ptlm_ead2BrkEff_Z_frac[441];/* Referenced by:
                                                           * '<S109>/2-D Lookup Table5'
                                                           * '<S68>/2-D Lookup Table5'
                                                           */

/* Secondary EAD Motor Brake Efficiency */
extern const volatile float32 ptlm_ead2BstEff_Z_frac[441];/* Referenced by:
                                                           * '<S110>/2-D Lookup Table4'
                                                           * '<S69>/2-D Lookup Table4'
                                                           */

/* Secondary EAD Motor Boost Efficiency */
extern const volatile boolean scap_eadc_b_useFctCfgMot;/* Referenced by:
                                                        * '<S8>/Constant1'
                                                        * '<S8>/Constant13'
                                                        */
extern const volatile boolean scap_eadc_b_useGetEventSts;/* Referenced by: '<S3>/Constant3' */
extern const volatile float32 scap_eadc_tm_pwrOffCmdLmtDly_s;/* Referenced by: '<S19>/Constant28' */
extern const volatile float32 scap_eadc_tq_PwrOffCmdDecGrad_Nmps;/* Referenced by: '<S19>/Constant30' */
extern const volatile float32 scap_eadc_tq_PwrOffCmdIncGrad_Nmps;/* Referenced by: '<S19>/Constant27' */
extern const volatile float32 scap_eadc_tq_mot2LmtPwrOffCmd_Nm;/* Referenced by:
                                                                * '<S19>/Constant1'
                                                                * '<S19>/Constant26'
                                                                */
extern const volatile float32 scap_eadc_v_pwrOffCmdVspdThd_kmh;/* Referenced by: '<S19>/Constant3' */
extern const volatile float32 scap_eadf_mot2MnTqLimMotTyp2_X_rpm[13];
                                   /* Referenced by: '<S8>/1-D Lookup Table4' */
extern const volatile float32 scap_eadf_mot2MnTqLimMotTyp2_Y_Nm[13];
                                   /* Referenced by: '<S8>/1-D Lookup Table4' */
extern const volatile float32 scap_eadf_mot2MxTqLimMotTyp2_X_rpm[13];
                                   /* Referenced by: '<S8>/1-D Lookup Table1' */
extern const volatile float32 scap_eadf_mot2MxTqLimMotTyp2_Y_Nm[13];
                                   /* Referenced by: '<S8>/1-D Lookup Table1' */
extern const volatile float32 scap_ptlc_pct_bmsCurrChgLmtPctPreFid;/* Referenced by: '<S80>/Constant54' */

/* power limit percent of bms current Pre FID */
extern const volatile boolean swcscap_eadc_b_adcOvrCtlPmt;/* Referenced by: '<S7>/Constant8' */
extern const volatile float32 swcscap_eadc_n_mot2GenEnaHiThdAdc_rpm;/* Referenced by: '<S7>/Relay2' */

/* Secondary EAD high speed threshold for EAD generation enabling in Adc Controll */
extern const volatile float32 swcscap_eadc_n_mot2GenEnaLoThdAdc_rpm;/* Referenced by: '<S7>/Relay2' */

/* Secondary EAD low speed threshold for EAD generation enabling in Adc Controll */
extern const volatile boolean swcscap_ptlc_b_adcOvrCtlPmt;/* Referenced by: '<S62>/Constant8' */
extern const volatile boolean swcscap_ptlc_b_useHvAttpwr;/* Referenced by: '<S58>/Constant22' */
extern const volatile float32 swcscap_ptlf_ead2MinTqCorrAdc_X_VehSpd_kph[5];
                                  /* Referenced by: '<S62>/1-D Lookup Table2' */

/* Secondary EAD Min Torque Correction f(Spd) Map - Vehicle Speed Axis */
extern const volatile float32 swcscap_ptlf_ead2MinTqCorrAdc_Y_frac[5];
                                  /* Referenced by: '<S62>/1-D Lookup Table2' */

/* Secondary EAD Min Torque Correction f(Spd) Map - factor */
extern const volatile boolean tqlc_b_enaEADMot2In2WDMod;/* Referenced by: '<S119>/Constant1' */

/* Enable Secondary EAD Motor in 2WD Mode */
extern const volatile float32 tqlc_tq_eadMot2MnTqDecGrad_Nmps;/* Referenced by: '<S118>/Constant3' */

/* Secondary EAD min torque decrease gradient when enabled */
extern const volatile float32 tqlc_tq_eadMot2MnTqIncGrad_Nmps;/* Referenced by: '<S118>/Constant4' */

/* Secondary EAD min torque increase gradient when disabled */
extern const volatile float32 tqlc_tq_eadMot2MxTqDecGrad_Nmps;/* Referenced by: '<S118>/Constant2' */

/* Secondary EAD max torque decrease gradient when disabled */
extern const volatile float32 tqlc_tq_eadMot2MxTqIncGrad_Nmps;/* Referenced by: '<S118>/Constant6' */

/* Secondary EAD max torque increase gradient when enabled */
#define swc_SCAP_STOP_SEC_CONST_VOLATILE
#include "swc_SCAP_MemMap.h"
#define swc_SCAP_START_SEC_VAR
#include "swc_SCAP_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_SIG */
extern boolean eadd_b_mot2BrkTqEnad;   /* '<S7>/Logical Operator1' */

/* Secondary EAD Brake Torque Enabled */
extern boolean eadd_b_mot2BstTqEnad;   /* '<S7>/Logical Operator20' */

/* Secondary EAD Boost Torque Enabled */
extern boolean eadd_b_mot2TqOff;       /* '<S6>/Relational Operator' */

/* Secondary EAD Torque Off */
extern float32 eadd_tq_mot2MaxLTTqLimd_Nm;/* '<S8>/MinMax10' */

/* Secondary EAD Max Long-term Limited Motoring Torque */
extern float32 eadd_tq_mot2MaxLTTq_Nm; /* '<S22>/Chart' */

/* Secondary EAD Max Long-term Motoring Torque */
extern float32 eadd_tq_mot2MaxSTTqLimd_Nm;/* '<S8>/MinMax1' */

/* Secondary EAD Max Short-term Limited Motoring Torque */
extern float32 eadd_tq_mot2MaxSTTq_Nm; /* '<S20>/Chart' */

/* Secondary EAD Max Short-term Motoring Torque */
extern float32 eadd_tq_mot2MinLTTqLimd_Nm;/* '<S8>/MinMax11' */

/* Secondary EAD Max Long-term Limited Generating Torque */
extern float32 eadd_tq_mot2MinLTTq_Nm; /* '<S26>/Chart' */

/* Secondary EAD Max Long-term Generating Torque */
extern float32 eadd_tq_mot2MinSTTqLimd_Nm;/* '<S8>/MinMax2' */

/* Secondary EAD Max Short-term Limited Generating Torque */
extern float32 eadd_tq_mot2MinSTTq_Nm; /* '<S24>/Chart' */

/* Secondary EAD Max Short-term Generating Torque */
extern float32 ptld_fact_hvbFltDegrd;  /* '<S58>/switch_ramp' */

/* Vehicle Fault Level Power Degradation Factor */
extern float32 ptld_frac_ead2MaxBrkEff;/* '<S68>/MinMax2' */

/* Secondary EAD Max Brake Efficiency */
extern float32 ptld_frac_ead2MaxBrkEffFinal;/* '<S109>/MinMax2' */

/* Secondary EAD Max Brake Efficiency Final */
extern float32 ptld_frac_ead2MaxBstEff;/* '<S69>/MinMax2' */

/* Secondary EAD Max Boost Efficiency */
extern float32 ptld_frac_ead2MaxBstEffFinal;/* '<S110>/MinMax2' */

/* Secondary EAD Max Boost Efficiency Final */
extern float32 ptld_pwr_ead2ChrgAvail_kW;/* '<S73>/Product' */

/* Secondary EAD Available Charge Power */
extern float32 ptld_pwr_ead2DischAvail_kW;/* '<S72>/Product' */

/* Secondary EAD Available Discharge Power */
extern float32 ptld_pwr_ead2PwrMax_kW; /* '<S107>/Switch2' */

/* Secondary EAD Max Power (motor) */
extern float32 ptld_pwr_ead2PwrMin_kW; /* '<S59>/Gain4' */

/* Secondary EAD Min Power (generator) */
extern float32 ptld_pwr_hvbChrgAvail_kW;/* '<S80>/Switch9' */

/* HVB Available Charge Power */
extern float32 ptld_pwr_hvbDischAvail_kW;/* '<S81>/Switch9' */

/* HVB Available Discharge Power */
extern float32 ptld_tq_ead2MaxTqLimd_Nm;/* '<S62>/Product4' */

/* Secondary EAD Max Torque Limit */
extern float32 ptld_tq_ead2MinTqLimd_Nm;/* '<S62>/Product5' */

/* Secondary EAD Min Torque Limit */
extern float32 ptld_tq_ead2TqMaxRaw_Nm;/* '<S60>/Product7' */

/* Secondary EAD Max Torque Raw */
extern float32 ptld_tq_ead2TqMax_Nm;   /* '<S60>/Product5' */

/* Secondary EAD Max Torque */
extern float32 ptld_tq_ead2TqMinRaw_Nm;/* '<S60>/Product9' */

/* Secondary EAD Min Torque Raw */
extern float32 ptld_tq_ead2TqMin_Nm;   /* '<S60>/Product10' */

/* Secondary EAD Min Torque */
extern boolean scap_eadd_b_ehbMsgErrDebd;/* '<S3>/Logical Operator1' */
extern boolean scap_eadd_b_tqLmtPwrOffCmd_flg;/* '<S19>/SR_latch' */
extern uint8 scap_eadd_st_getEhbMsgErrSts;/* '<S3>/C Caller1' */
extern float32 scap_eadd_tq_mot2LmPwrOffCmd_Nm;/* '<S19>/Switch1' */
extern float32 scap_eadd_tq_mot2MaxLmtEnaOff_Nm;/* '<S19>/Switch8' */
extern boolean swcscap_pltd_b_PwrPreLimitLvl1ChgCurr;/* '<S89>/timed_delay' */
extern boolean swcscap_pltd_b_PwrPreLimitLvl1DischCurr;/* '<S86>/timed_delay' */
extern boolean swcscap_pltd_b_PwrPreLimitLvl2ChgCurr;/* '<S87>/timed_delay' */
extern boolean swcscap_pltd_b_PwrPreLimitLvl2DischCurr;/* '<S88>/timed_delay' */
extern float32 swcscap_pltd_i_hvbMaxChgCurr_A;/* '<S58>/Product10' */

/* HV Battery Available Charge Current */
extern float32 swcscap_pltd_i_hvbMaxDischCurr_A;/* '<S58>/Product3' */

/* HV Battery Available Discharge Current */
extern float32 swcscap_ptld_pwr_hvbChrgAvailRaw_kW;/* '<S58>/Product5' */

/* HVB Available Charge Power */
extern float32 swcscap_ptld_pwr_hvbDischAvailRaw_kW;/* '<S58>/Product2' */

/* HVB Available Discharge Power */
extern boolean tqld_b_eadMot2TqEnad;   /* '<S119>/Logical Operator10' */

/* Secondary EAD Torque enabled */
extern float32 tqld_tq_axle2MaxTq_Nm;  /* '<S117>/Product2' */

/* Secondary Axle Max Torque */
extern float32 tqld_tq_axle2MinTq_Nm;  /* '<S117>/Product1' */

/* Secondary Axle Min Torque */
extern float32 tqld_tq_eadMot2AllwdMaxTq_Nm;/* '<S118>/SwitchRampMOTMaxTrqLim' */

/* Secondary EAD Max Allowed Torque */
extern float32 tqld_tq_eadMot2AllwdMinTq_Nm;/* '<S118>/SwitchRampMOTMinTrqLim' */

/* Secondary EAD Min Allowed Torque */
extern float32 tqld_tq_whlMax_Nm;      /* '<S116>/MinMax3' */

/* Wheel Max Torque */
extern float32 tqld_tq_whlMin_Nm;      /* '<S116>/MinMax4' */

/* Wheel Min Torque */
#define swc_SCAP_STOP_SEC_VAR
#include "swc_SCAP_MemMap.h"

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
 * '<Root>' : 'swc_SCAP'
 * '<S1>'   : 'swc_SCAP/SCAP__System_Capacity'
 * '<S2>'   : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2'
 * '<S3>'   : 'swc_SCAP/SCAP__System_Capacity/GetEventStatus'
 * '<S4>'   : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation'
 * '<S5>'   : 'swc_SCAP/SCAP__System_Capacity/TQL_TorqueLimitsConversion'
 * '<S6>'   : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation'
 * '<S7>'   : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueEnablingConditions'
 * '<S8>'   : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueLimitation'
 * '<S9>'   : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/Detect Decrease'
 * '<S10>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/Detect Decrease1'
 * '<S11>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/Detect Decrease2'
 * '<S12>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/Detect Decrease3'
 * '<S13>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/SwitchRampMOTMaxPeakTrq'
 * '<S14>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/SwitchRampMOTMaxTrq'
 * '<S15>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/SwitchRampMOTMinPeakTrq'
 * '<S16>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/SwitchRampMOTMinTrq'
 * '<S17>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/abs_val1'
 * '<S18>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/abs_val2'
 * '<S19>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/mot2MaxLmtTqPwrOffCmd'
 * '<S20>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/SwitchRampMOTMaxPeakTrq/switch_ramp'
 * '<S21>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/SwitchRampMOTMaxPeakTrq/switch_ramp/Chart'
 * '<S22>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/SwitchRampMOTMaxTrq/switch_ramp'
 * '<S23>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/SwitchRampMOTMaxTrq/switch_ramp/Chart'
 * '<S24>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/SwitchRampMOTMinPeakTrq/switch_ramp'
 * '<S25>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/SwitchRampMOTMinPeakTrq/switch_ramp/Chart'
 * '<S26>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/SwitchRampMOTMinTrq/switch_ramp'
 * '<S27>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/SwitchRampMOTMinTrq/switch_ramp/Chart'
 * '<S28>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/abs_val1/neg'
 * '<S29>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/abs_val1/pos'
 * '<S30>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/abs_val2/neg'
 * '<S31>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/abs_val2/pos'
 * '<S32>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/mot2MaxLmtTqPwrOffCmd/Compare To Constant1'
 * '<S33>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/mot2MaxLmtTqPwrOffCmd/Compare To Constant2'
 * '<S34>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/mot2MaxLmtTqPwrOffCmd/Compare To Constant3'
 * '<S35>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/mot2MaxLmtTqPwrOffCmd/SR_latch'
 * '<S36>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/mot2MaxLmtTqPwrOffCmd/SR_latch1'
 * '<S37>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/mot2MaxLmtTqPwrOffCmd/SwitchRampMOTMaxTrq1'
 * '<S38>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/mot2MaxLmtTqPwrOffCmd/turnON_delay'
 * '<S39>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/mot2MaxLmtTqPwrOffCmd/SwitchRampMOTMaxTrq1/switch_ramp'
 * '<S40>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/mot2MaxLmtTqPwrOffCmd/SwitchRampMOTMaxTrq1/switch_ramp/Chart'
 * '<S41>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueDeactivation/mot2MaxLmtTqPwrOffCmd/turnON_delay/timed_delay'
 * '<S42>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueEnablingConditions/Compare To Constant'
 * '<S43>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueEnablingConditions/Compare To Constant1'
 * '<S44>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueEnablingConditions/Compare To Constant4'
 * '<S45>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueEnablingConditions/Enumerated Constant'
 * '<S46>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueEnablingConditions/Enumerated Constant1'
 * '<S47>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueEnablingConditions/Enumerated Constant2'
 * '<S48>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueEnablingConditions/Enumerated Constant3'
 * '<S49>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueEnablingConditions/Enumerated Constant4'
 * '<S50>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueEnablingConditions/Enumerated Constant6'
 * '<S51>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueEnablingConditions/Enumerated Constant8'
 * '<S52>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueLimitation/Compare To Constant1'
 * '<S53>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueLimitation/Compare To Constant5'
 * '<S54>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueLimitation/abs_val'
 * '<S55>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueLimitation/abs_val/neg'
 * '<S56>'  : 'swc_SCAP/SCAP__System_Capacity/EAD_TorqueLimitsMot2/TorqueLimitation/abs_val/pos'
 * '<S57>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation'
 * '<S58>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation'
 * '<S59>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/PowerLimitsArbitration'
 * '<S60>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/PowerToTorqueLimitsConversion'
 * '<S61>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/model_info1'
 * '<S62>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/EAD2PowerLim'
 * '<S63>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/abs_val'
 * '<S64>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/EAD2PowerLim/Compare To Constant'
 * '<S65>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/EAD2PowerLim/Compare To Constant1'
 * '<S66>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/EAD2PowerLim/Enumerated Constant4'
 * '<S67>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/EAD2PowerLim/abs_val2'
 * '<S68>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/EAD2PowerLim/ead2MaxBrkEff'
 * '<S69>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/EAD2PowerLim/ead2MaxBstEff'
 * '<S70>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/EAD2PowerLim/rpm2radps1'
 * '<S71>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/EAD2PowerLim/switch_ramp'
 * '<S72>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/EAD2PowerLim/xx2kxx2'
 * '<S73>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/EAD2PowerLim/xx2kxx3'
 * '<S74>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/EAD2PowerLim/abs_val2/neg'
 * '<S75>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/EAD2PowerLim/abs_val2/pos'
 * '<S76>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/EAD2PowerLim/switch_ramp/switch_ramp'
 * '<S77>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/EAD2PowerLim/switch_ramp/switch_ramp/Chart'
 * '<S78>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/abs_val/neg'
 * '<S79>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/ElectricalMotorsPowerLimitation/abs_val/pos'
 * '<S80>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/ChrgPowerRampLimit'
 * '<S81>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/DischPowerRampLimit'
 * '<S82>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/abs_val'
 * '<S83>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/abs_val1'
 * '<S84>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/abs_val2'
 * '<S85>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/switch_ramp'
 * '<S86>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/turnON_delay1'
 * '<S87>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/turnON_delay10'
 * '<S88>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/turnON_delay8'
 * '<S89>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/turnON_delay9'
 * '<S90>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/ChrgPowerRampLimit/Detect Increase'
 * '<S91>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/DischPowerRampLimit/Detect Increase'
 * '<S92>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/abs_val/neg'
 * '<S93>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/abs_val/pos'
 * '<S94>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/abs_val1/neg'
 * '<S95>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/abs_val1/pos'
 * '<S96>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/abs_val2/neg'
 * '<S97>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/abs_val2/pos'
 * '<S98>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/switch_ramp/switch_ramp'
 * '<S99>'  : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/switch_ramp/switch_ramp/Chart'
 * '<S100>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/turnON_delay1/timed_delay'
 * '<S101>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/turnON_delay10/timed_delay'
 * '<S102>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/turnON_delay8/timed_delay'
 * '<S103>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/HVBatteryPowerLimitation/turnON_delay9/timed_delay'
 * '<S104>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/PowerLimitsArbitration/ChargePowerCoordination'
 * '<S105>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/PowerLimitsArbitration/DischargePowerCoordination'
 * '<S106>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/PowerLimitsArbitration/ChargePowerCoordination/saturation_dynamic1'
 * '<S107>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/PowerLimitsArbitration/DischargePowerCoordination/saturation_dynamic1'
 * '<S108>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/PowerToTorqueLimitsConversion/abs_val'
 * '<S109>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/PowerToTorqueLimitsConversion/ead2MaxBrkEffFinal'
 * '<S110>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/PowerToTorqueLimitsConversion/ead2MaxBstEffFinal'
 * '<S111>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/PowerToTorqueLimitsConversion/kxx2xx1'
 * '<S112>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/PowerToTorqueLimitsConversion/kxx2xx3'
 * '<S113>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/PowerToTorqueLimitsConversion/rpm2radps1'
 * '<S114>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/PowerToTorqueLimitsConversion/abs_val/neg'
 * '<S115>' : 'swc_SCAP/SCAP__System_Capacity/PTL_PowerLimitation/PowerToTorqueLimitsConversion/abs_val/pos'
 * '<S116>' : 'swc_SCAP/SCAP__System_Capacity/TQL_TorqueLimitsConversion/AxleDrive2Whl_Conv'
 * '<S117>' : 'swc_SCAP/SCAP__System_Capacity/TQL_TorqueLimitsConversion/EADShaft2SecondaryAxle_Conv'
 * '<S118>' : 'swc_SCAP/SCAP__System_Capacity/TQL_TorqueLimitsConversion/SecondaryEADMotorAllowedTorque'
 * '<S119>' : 'swc_SCAP/SCAP__System_Capacity/TQL_TorqueLimitsConversion/TorqueEnable'
 * '<S120>' : 'swc_SCAP/SCAP__System_Capacity/TQL_TorqueLimitsConversion/model_info1'
 * '<S121>' : 'swc_SCAP/SCAP__System_Capacity/TQL_TorqueLimitsConversion/SecondaryEADMotorAllowedTorque/SwitchRampMOTMaxTrqLim'
 * '<S122>' : 'swc_SCAP/SCAP__System_Capacity/TQL_TorqueLimitsConversion/SecondaryEADMotorAllowedTorque/SwitchRampMOTMinTrqLim'
 * '<S123>' : 'swc_SCAP/SCAP__System_Capacity/TQL_TorqueLimitsConversion/SecondaryEADMotorAllowedTorque/SwitchRampMOTMaxTrqLim/switch_ramp'
 * '<S124>' : 'swc_SCAP/SCAP__System_Capacity/TQL_TorqueLimitsConversion/SecondaryEADMotorAllowedTorque/SwitchRampMOTMaxTrqLim/switch_ramp/Chart'
 * '<S125>' : 'swc_SCAP/SCAP__System_Capacity/TQL_TorqueLimitsConversion/SecondaryEADMotorAllowedTorque/SwitchRampMOTMinTrqLim/switch_ramp'
 * '<S126>' : 'swc_SCAP/SCAP__System_Capacity/TQL_TorqueLimitsConversion/SecondaryEADMotorAllowedTorque/SwitchRampMOTMinTrqLim/switch_ramp/Chart'
 */
#endif                                 /* RTW_HEADER_swc_SCAP_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

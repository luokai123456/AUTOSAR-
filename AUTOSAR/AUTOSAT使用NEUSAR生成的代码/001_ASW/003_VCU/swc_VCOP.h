/*
 * File: swc_VCOP.h
 *
 * Code generated for Simulink model 'swc_VCOP'.
 *
 * Model version                  : 6.918
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Sep  8 10:53:00 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_VCOP_h_
#define RTW_HEADER_swc_VCOP_h_
#ifndef swc_VCOP_COMMON_INCLUDES_
#define swc_VCOP_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_swc_VCOP.h"
#endif                                 /* swc_VCOP_COMMON_INCLUDES_ */

#include "Rte_Type.h"

/* Includes for objects with custom storage classes */
#include "const_ImportFromFile.h"
#include "const_ImportedDefine.h"

/* Forward declaration for rtModel */
typedef struct tag_RTM_swc_VCOP_T RT_MODEL_swc_VCOP_T;

/* user code (top of header file) */
#include "Platform_Types.h"
#include "enum_Type.h"
#include "Rte_swc_rte_dem.h"
#include "Aes_Encypt.h"
#include "AES_Lib.h"
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

#ifndef DEFINED_TYPEDEF_FOR_vcsb_ATAU_
#define DEFINED_TYPEDEF_FOR_vcsb_ATAU_

typedef struct {
  KeyAuthStatus pmmd_e_authenticationStatus;
  uint8 pmmd_b_ePTRelease_flg;
} vcsb_ATAU;

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

#ifndef DEFINED_TYPEDEF_FOR_vcsb_MEST_
#define DEFINED_TYPEDEF_FOR_vcsb_MEST_

typedef struct {
  uint8 masd_st_vehOverLoadSts;
  float32 masd_m_vehWeight_kg;
  uint16 masd_st_vehCalNum;
  boolean masd_b_vehOvrLoadEnbl;
} vcsb_MEST;

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

#ifndef DEFINED_TYPEDEF_FOR_vcob_VCOP_
#define DEFINED_TYPEDEF_FOR_vcob_VCOP_

typedef struct {
  uint8 PMS_IsgModReq;
  uint8 PMS_FrntHeatPwrAllwd;
  boolean FrntHeatModEnad;
  boolean PMS_MCUActvdReq;
  uint16 PMS_IsgTqReq;
  uint8 PMS_Command_AliveCounter_EV;
  uint8 PMS_Command_Checksum_EV;
  uint8 VCU_BMSH_StsModeReq;
  uint8 VCU_BMSH_DCChgRelayVolt;
  uint8 VCU_CrashOutputSts;
  uint16 VCU_ActInputVolt;
  uint8 VCU_BMSH_Ctrl_AliveCounter;
  uint8 VCU_BMSH_Ctrl_CheckSum;
  uint8 PMS_DCDCCutOffLV;
  boolean PMS_DcDcActvdReq;
  uint8 PMS_DCDCPwrLmt;
  uint8 PMS_DCDC_Ctrl_AliveCounter;
  uint8 PMS_DCDC_Ctrl_Checksum;
  boolean PMS_ePTReady_EV;
  uint8 VCU_BMSH_AllowChgCurrentMax;
  uint8 VCU_ChargeDepthReq;
  uint8 VCU_VehicleInfo_AliveCounter;
  uint8 VCU_VehicleInfo_CheckSum;
  uint16 VCU_Odometerbackup_EV;
  uint8 PEPS_PowerModeValidity;
  uint8 PEPS_PowerMode;
  uint16 EHB_VehicleSpeed;
  boolean EHB_VehicleSpeedInvalid;
  uint8 EGSM_Status_AliveCounter_EV;
  uint8 EGSM_Status_Checksum_EV;
  uint8 PMS_SlidingmomentrSetReq;
  uint8 PMS_Command_AliveCounter;
  uint8 PMS_Command_Checksum;
  uint16 PMS_RegenTrqPot;
  uint16 PMS_RegenTrqAct;
  boolean PMS_EPBClosedReq;
  boolean PMS_DriverGearAbort;
  boolean PMS_RegenTarTrqPotQualifier;
  boolean PMS_RegenTrqActQualifier;
  boolean PMS_RegenTrqPotQualifier;
  boolean PMS_AccelPedalPositionInvalid;
  uint8 PMS_AccelPedalPosition;
  uint16 PMS_RegenTarTrqPot;
  uint8 PMS_CSControl2_AliveCounter;
  uint8 PMS_CSControl2_CheckSum;
  uint8 PMS_DriveModeInd;
  uint8 PMS_VehicleSysErrorLevel;
  uint8 PMS_GearOperateErr;
  boolean PMS_BrkSysErr;
  uint8 PMS_ePTModeSelect;
  uint8 PMS_ePTModeActual;
  boolean PMS_DriverRemind;
  boolean PMS_ChargerFault;
  boolean PMS_ePTReady;
  uint8 PMS_ePTReleaseSig;
  uint8 PMS_ePTRegencyLevInd;
  boolean PMS_DoubleFlashLampOn;
  boolean PMS_TurtleLampOn;
  boolean PMS_ePTFault;
  uint8 PMS_Ctrl_AliveCounter;
  uint8 PMS_Ctrl_Checksum;
  uint8 PMS_Real_PedalPosition;
  uint8 PMS_ModeGearDisplaySts;
  uint8 PMS_ADCCtrlSts;
  boolean PMS_CANBus_RecSta;
  uint8 PMS_ACC_BeControlled_Status;
  uint8 PMS_CurrentGearPosition;
  boolean PMS_CurrentGearPosition_Valid;
  boolean PMS_Gear_intervene;
  uint8 PMS_ChargeHV_Status;
  boolean PMS_APA_BeControlled_Status;
  boolean PMS_Real_PedalPositionInvalid;
  uint8 PMS_ModeControl_AliveCounter;
  uint8 PMS_ModeControl_CheckSum;
  uint16 PMS_ActualPTTorque;
  uint16 PMS_DriverDemandTorque;
  boolean PMS_GP_Ovrd;
  boolean PMS_ActualPTTorqueInvalid;
  boolean PMS_DriverDemandTorqueInvalid;
  uint8 PMS_VacuumSystemsta;
  uint16 PMS_VacuumPressure;
  uint8 PMS_EngTrqReqSrc;
  boolean PMS_LimpHomeSts;
  uint8 PMS_EngControl_AliveCounter;
  uint8 PMS_EngControl_CheckSum;
  uint16 PMS_MinPTTorqueAllowed;
  uint16 PMS_MaxPTTorqueAllowed;
  boolean PMS_StartActive;
  uint8 PMS_CruiseControlSts;
  boolean PMS_CruiseSwitchSts;
  uint8 PMS_ControlSetSpeed;
  uint8 PMS_DM_FailureReasonAndSysFaultFBK;
  uint8 PMS_CSControl1_AliveCounter;
  uint8 PMS_CSControl1_CheckSum;
  uint16 PMS_EVDTEodometer;
  uint16 PMS_PTResiduePwrInd;
  uint8 PMS_EpedalActive;
  uint8 PMS_EPedlDrvrIndcnMsg;
  uint16 DrvPfmncRedn;
  uint8 PMS_DrvrGearLvrLockIndcn;
  boolean PMS_HvBattCooltLvl;
  uint8 PMS_V2XDchaSwtFb1;
  uint16 PMS_BookChrgnTarValFb;
  uint16 PMS_DchaEgyAct;
  uint16 PMS_DchaEgyStrg;
  uint8 PMS_ACCMEnable;
  uint8 PMS_PTCEnable;
  uint8 BMSH_HvBattThermMod;
  uint8 PMS_CoolingFanPWMSpd;
  uint8 PMS_HvCoolgPwrAllwd;
  uint8 BMSH_Inlet_WaterTemp;
  uint8 BMSH_Outlet_WaterTemp;
  uint8 BMSH_HvBattCooltTReq;
  uint8 PMS_DriveCircuitTemp;
  uint8 PMS_HvHeatgPwrAllwd;
  uint8 PMS_LTCoolingFanFB;
  uint8 PMS_AuthResult;
  uint8 PMS_RespResult;
  uint64 PMS_ReqSeed;
  uint8 PMS_ExecuteLockVehResults;
  uint8 PMS_LockVehSts;
  uint8 PMS_FunLockVehActive;
  uint8 PMS_FunAnti_DismantleActive;
  uint8 PMS_LockVehType;
  uint8 PMS_LockLimResult;
  uint8 PMS_IntelligentChargeState;
  uint8 PMS_IntelligentChargeQuit;
  uint8 PMS_IntelligentChargeExitReq;
  boolean PMS_TBOX_HVILState;
  uint16 PMS_Odometerbackup;
  uint8 BMSH_BattSOH;
  uint16 BMSH_BattCurr;
  uint16 BMSH_HVBusVolt;
  boolean BMSH_HvShutdownReq;
  uint16 BMSH_BattVolt;
  uint8 BMSH_VoltCurr_AliveCounter;
  uint8 BMSH_VoltCurr_Checksum;
  uint16 BMSH_BattRemainEnergy;
  uint16 BMSH_BattSOC;
  uint8 BMSH_Cell_TotalNum;
  uint8 BMSH_Battery_Performance_AliveCounter;
  uint8 BMSH_Battery_Performance_Checksum;
  uint8 IPU_BattFaultLampState;
  uint16 IPU_IsgTqActIsgTqAct;
  uint16 IPU_IsgSpdActSgn;
  uint8 IPU_IsgModSts;
  uint8 IPU_TrqSpd_AliveCounter;
  uint8 IPU_TrqSpd_CheckSum;
  boolean ODP_DcDcStsAlm;
  uint8 ODP_DCDC_stCtrl;
  uint8 BMSH_BattFaultLampState;
  boolean BMSH_Vehicle_HVILSts_PHEV;
  uint8 BMSH_stMode;
  uint8 BMSH_FastChgCC2ConntState;
  uint16 BMSH_ACChgTimeRemain;
  boolean BMSH_ThermalOutofControl;
  boolean BMSH_ChargeToBeFinished;
  uint8 BMSH_BattTempAvg;
  uint8 BMSH_TempSensor_MaxTemp;
  uint8 BMSH_TempSensor_MinTemp;
  uint8 BMSH_ChargeLEDCtrl;
  uint8 BMSH_Charge_Over_Current;
  uint8 BMSH_InsulationRes_Fault;
  uint8 BMSH_DCChgminusSocketTempSensing_Failure;
  uint8 BMSH_DCChgplusSocketTempSensing_Failure;
  uint16 BMSH_ChgTimeRemain;
  boolean IPU_IsgOverTemp;
  uint64 PMS_PEPSAuth;
  uint8 EGSM_ParkReq;
  uint8 EGSM_ShiftleverFailSt;
  uint8 EGSM_LeverPosition;
  uint8 EGSM_Status_AliveCounter;
  uint8 EGSM_Status_Checksum;
  uint8 PMS_EDCPEnable;
  uint8 PMS_HBCPEnable;
  uint8 PMS_EDCPPWMCtrl;
  uint8 PMS_HBCPPWMCtrl;
  uint8 EDCP_Flt;
  uint8 EDCP_FltLevel;
  uint8 EDCP_State;
  uint8 EDCP_PWMFB;
  uint8 HBCP_Flt;
  uint8 HBCP_FltLevel;
  uint8 HBCP_State;
  uint8 HBCP_PWMFB;
  uint8 PMS_MHGV_PosSet;
  boolean PMS_MHGV_EnableReq;
  boolean PMS_MHGV_ReqMotorEmgyStop;
  boolean PMS_MHGV_ReqMotorOptRecovery;
  boolean PMS_FWFV_MoveEnable;
  uint8 PMS_FWFV_ReqMovePos;
  boolean MHGV_RESP_ERROR;
  boolean MHGV_OverVoltageFlt;
  boolean MHGV_OverCurrentFlt;
  boolean MHGV_OverTempFlt;
  boolean MHGV_UnderVoltageFlt;
  boolean MHGV_InitState;
  boolean MHGV_CCWFlg;
  boolean MHGV_MotorState;
  uint8 MHGV_CurrentPos;
  boolean FWFV_RESP_ERROR;
  boolean FWFV_OverVoltageFlt;
  boolean FWFV_OverCurrentFlt;
  boolean FWFV_OverTempFlt;
  boolean FWFV_UnderVoltageFlt;
  boolean FWFV_InitState;
  boolean FWFV_CCWFlg;
  boolean FWFV_MotorState;
  uint8 FWFV_CurrentPos;
  boolean O_S_PIN88;
  boolean O_S_PIN83;
  boolean O_S_PIN89;
  boolean O_S_PIN110;
  uint16 O_T_PIN82_Duty;
  uint32 O_T_PIN82_Period;
  uint16 O_T_PIN118_Duty;
  uint32 O_T_PIN118_Period;
  uint16 O_T_PIN77_Duty;
  uint32 O_T_PIN77_Period;
  uint16 O_T_PIN104_Duty;
  uint32 O_T_PIN104_Period;
  uint16 O_T_PIN103_Duty;
  uint32 O_T_PIN103_Period;
  uint16 O_T_PIN14_Duty;
  uint16 O_T_PIN28_Duty;
  uint32 O_T_PIN14_Period;
  uint32 O_T_PIN28_Period;
  uint8 st_ShtDown;
  uint8 PMS_MHGV_PosSet_LIN;
  boolean PMS_MHGV_EnableReq_LIN;
  boolean PMS_MHGV_ReqMotorEmgyStop_LIN;
  boolean PMS_MHGV_ReqMotorOptRecovery_LIN;
  boolean PMS_FWFV_MoveEnable_LIN;
  uint8 PMS_FWFV_ReqMovePos_LIN;
  boolean PMS_TBOX_HVILState_3A1;
  uint8 PMS_AppSts;
  boolean PMS_HVIL1Sts_EV;
  boolean PMS_HVIL1Sts_UB_EV;
  boolean PMS_HVIL2Sts_EV;
  boolean PMS_HVIL2Sts_UB_EV;
  uint8 PMS_SelfCheckSts_EV;
  uint8 PMS_CurrentGearPosition_EV;
  boolean PMS_CurrentGearPosition_Valid_EV;
  boolean PMS_HVILSts_EV;
  boolean PMS_HVILSts_UB_EV;
  uint8 PMS_DriveCircuitTemp_EV;
  uint8 PMS_EDCPEnable_EV;
  uint8 PMS_EDCPPWMCtrl_EV;
  uint8 VCU_DCInputCurrent_EV;
  uint8 PMS_ThermalReq;
  uint8 PMS_IsgActvDampgModReq_EV;
  uint8 PMS_PTCEnable_EV;
  uint8 IPK_Second_EV;
  uint8 IPK_Minute_EV;
  uint8 IPK_Hour_EV;
  uint8 IPK_Day_EV;
  uint8 IPK_Month_EV;
  uint8 IPK_Year_EV;
  uint16 EHB_FLWheelSpeedKPH_EV;
  boolean EHB_FLWheelSpeedInvalid_EV;
  uint8 EHB_FLWheelDirection_EV;
  uint16 EHB_FRWheelSpeedKPH_EV;
  boolean EHB_FRWheelSpeedInvalid_EV;
  uint8 EHB_FRWheelDirection_EV;
  uint8 EHB_FrontWheelSpeedsKPH_AliveCounter_EV;
  uint8 EHB_FrontWheelSpeedsKPH_CheckSum_EV;
  uint16 EHB_RLWheelSpeedKPH_EV;
  boolean EHB_RLWheelSpeedInvalid_EV;
  uint8 EHB_RLWheelDirection_EV;
  uint16 EHB_RRWheelSpeedKPH_EV;
  boolean EHB_RRWheelSpeedInvalid_EV;
  uint8 EHB_RRWheelDirection_EV;
  uint8 EHB_RearWheelSpeedsKPH_AliveCounter_EV;
  uint8 EHB_RearWheelSpeedsKPH_CheckSum_EV;
  boolean PMS_IgnONSts_EV;
  uint8 PMS_ACC1PosVol_EV;
  uint8 PMS_ACC2PosVol_EV;
  uint8 PMS_BatteryVol_EV;
  uint8 PMS_HVPRASts_EV;
  uint8 PMS_AppSts_EV;
  uint8 PMS_HBCP_PWMCtrl_EV;
  uint8 PMS_ChargWakeupSts_EV;
  uint8 PMS_EDCP_PWMCtrl_EV;
  uint8 PMS_HBCP_FaultFB_EV;
  uint8 PMS_EDCP_FaultFB_EV;
  uint8 PMS_BattPackInCoolTempback_EV;
  uint8 PMS_BattPackOutCoolTempback_EV;
  uint8 PMS_CPSRU_EV;
  uint8 PMS_FAN_PWMCtrl_EV;
  uint8 PMS_DDwaterPump_PWMCtrl_EV;
  uint8 PMS_VacuumPump_FB_EV;
  uint16 PMS_VehicleSpeed_EV;
  boolean PMS_CPSREn_EV;
  boolean PMS_VacuumPumpCmd_EV;
  boolean PMS_VehicleSpeedInvalid_EV;
  uint8 PMS_MCUTemp_EV;
  boolean PMS_HVILSts;
  boolean PMS_HVILSts_UB;
  uint8 BMSH_TempSensor_TotalNum;
  uint8 IsgTqActCntr;
  boolean IsgTqAct_UB;
  boolean IsgCluSts_UB;
  uint8 IsgTqActChks;
  uint8 IsgTqActQualityFactor;
  uint16 IsgTqActIsgTqAct;
  uint8 IsgModSts;
  boolean IsgModSts_UB;
  uint8 IsgCluSts;
  boolean IsgSpdActSgn_UB;
  uint16 IsgSpdActSgn;
  uint8 PMS_MCUFlowFeedback_EV;
  uint16 SAS_SteerWheelAngle_EV;
  uint8 SAS_Status_AliveCounter_EV;
  uint8 SAS_Status_CheckSum_EV;
  uint64 PMS_SwapAuth_EV;
  uint8 EHB_Mcylinder_Pressure_EV;
  boolean EHB_Mcylinder_PressureInvalid_EV;
  uint8 EHB_EPBStatus_EV;
  uint8 EHB_Status_AliveCounter_EV;
  uint8 EHB_Status_Checksum_EV;
  sint16 PMS_EPS_SteeringAngleValue_EV;
  boolean PMS_EPS_SteeringAngleValueInvalid_EV;
  uint8 PMS_EPS_SystemSts_AliveCounter_EV;
  uint8 PMS_EPS_SystemSts_CheckSum_EV;
  uint8 PMS_DischargeEnable_EV;
  boolean PMS_0X16A_TimeoutFlag_EV;
  uint8 PMS_ModeGearDisplaySts_EV;
  uint8 PMS_ModeControl_AliveCounter_EV;
  uint8 PMS_ModeControl_CheckSum_EV;
  boolean PMS_StsBrkSwitch1_EV;
  uint8 PMS_StsSwapFault_EV;
  uint8 PMS_SwapAuthRelease_EV;
  uint8 PMS_StsSwap_EV;
  boolean PMS_PackTypeUnmatch_EV;
  uint8 PMS_StsSwap_AliveCounter_EV;
  uint8 PMS_StsSwap_CheckSum_EV;
  boolean PMS_IPK_HandBrakeSts_EV;
  boolean BCM_Central_Lock_CMD_EV;
  boolean BCM_Central_unLock_CMD_EV;
  boolean BCM_FrontLeftDoorAjarStatus_EV;
  uint8 BCM_DoorLockStatusDrv_EV;
  boolean BCM_FrontRightDoorAjarStatus_EV;
  uint8 BCM_DoorLockStatusPass_EV;
  boolean AC_AmbientTemperatureInvalid_EV;
  uint8 AC_AmbientTemperature_EV;
  uint16 PMS_BMSH_BattSOCDisp_EV;
  uint8 PMS_PEPS_PowerModeValidity_EV;
  uint8 PMS_PEPS_PowerMode_EV;
  boolean PEPS_RemoteControlSt_EV;
  boolean PEPS_EngForbidWarn_EV;
  boolean PEPS_EngineforbidSt_EV;
  boolean PMS_PEPS_0x1E2_TimeoutFlag_EV;
  uint16 PMS_BMSH_BattSOH_EV;
  uint16 PMS_BMSH_BattRemainEnergy_EV;
  uint16 BMSH_ICU_BatteryElectricDTE;
  uint8 BMSH_PackCode_ID;
  uint8 BMSH_PackCode1;
  uint8 BMSH_PackCode2;
  uint8 BMSH_PackCode3;
  uint8 BMSH_PackCode4;
  uint8 BMSH_PackCode5;
  uint8 BMSH_PackCode6;
  uint8 BMSH_PackCode7;
  uint8 BMSH_BatSwapPosTemp;
  uint8 BMSH_BatSwapNegTemp;
  uint8 BMSH_DisChgOverCurrent;
  uint8 BMSH_MainPosRelayFault;
  uint8 BMSH_MainNegRelayFault;
  uint8 BMSH_DCChgRelayFault;
  boolean BMSH_TBOX_BatStoreSysFault;
  boolean BMSH_TBOX_BatLowTemp;
  uint8 BMSH_VCU_StsMainHVIL;
  uint8 VCU_PMS_APPowerActual_EV;
  uint8 BMS_CellVoltFrameNum;
  uint8 BMS_VoltCellNum;
  uint16 BMS_CellVoltN1;
  uint16 BMS_CellVoltN2;
  uint16 BMS_CellVoltN3;
  uint8 IsgTqActCntr_ADC;
  boolean IsgTqAct_UB_ADC;
  boolean IsgCluSts_UB_ADC;
  uint8 IsgTqActChks_ADC;
  uint8 IsgTqActQualityFactor_ADC;
  uint16 IsgTqActIsgTqAct_ADC;
  uint8 IsgModSts_ADC;
  boolean IsgModSts_UB_ADC;
  uint8 IsgCluSts_ADC;
  boolean IsgSpdActSgn_UB_ADC;
  uint16 IsgSpdActSgn_ADC;
  uint8 PMS_BMS_ReignLockSts;
  boolean PMS_DcDc1ActvdReq_EV;
  uint8 PMS_Wakeup_reasons;
  boolean PMS_NMSts;
  uint32 PMS_Stayawake_reasons;
  uint8 PMS_BMS_Reignstatus1;
  uint8 PMS_BMS_Reignstatus2;
  uint8 PMS_ChargeLimitResponse;
  uint16 BMSH_InsulationRes;
  uint16 IPU_HVBusVolt;
  uint16 IPU_HVBusCur;
  uint8 BMS_MaxVoltCellNum;
  uint8 BMS_MinVoltCellNum;
  uint16 BMS_MaxCellVolt;
  uint16 BMS_MinCellVolt;
  uint8 BMS_MaxTemp1SnsNum;
  uint8 BMS_MinxTemp1SnsNum;
  uint8 BMSH_Over_SOC;
  boolean BMSH_SOC_Hop;
  uint8 BMSH_Low_SOC;
  boolean BMSH_CellTemp_Uniformity;
  uint8 BMSH_Cell_UnderVol;
  uint8 BMSH_Cell_OverVol;
  uint8 BMSH_Pack_UnderVoltage;
  uint8 BMSH_Pack_OverVoltage;
  uint8 BMSH_Over_Temperature;
  uint8 BMSH_CellVolt_Uniformity;
  boolean IPU_IPUTAlm;
  boolean PMS_StsBrkSwitch1_PMS;
  boolean PMS_StsBrkSwitch1Invalid_PMS;
  uint8 PMS_LockVehPerFlag_PMS;
  uint8 PMS_VersionConversionFlag_PMS;
  uint8 PMS_SpdLmtLevel_PMS;
  uint8 PMS_InventorySpdLmtSts_PMS;
  uint8 PMS_StartBattChgRes_PMS;
  uint8 PMS_Life_PMS;
  uint8 PMS_VehicleSysErrorLevelG_PMS;
  boolean ODP_TBOX_TDcDcAlm_PMS;
  boolean ODP_TBOX_DcDcStsAlm_PMS;
  boolean IPU_MotorTempHighFault1_PMS;
  boolean IPU_MCUTempHighAlarm1_PMS;
  boolean BMSH_TBOX_BatTempUniformity2_PMS;
  boolean BMSH_TBOX_BatOverSOC2_PMS;
  boolean BMSH_TBOX_SOCHop2_PMS;
  boolean BMSH_TBOX_BatLowSOC2_PMS;
  boolean BMSH_TBOX_BatOverCharge2_PMS;
  boolean BMSH_TBOX_BatUniformity2_PMS;
  boolean BMSH_TBOX_CellUnderVoltage2_PMS;
  boolean BMSH_TBOX_BatUnderVoltage2_PMS;
  boolean BMSH_TBOX_BatOverTemp2_PMS;
  boolean BMSH_TBOX_BatIsoAlarm2_PMS;
  boolean BMSH_TBOX_BatOverVoltage2_PMS;
  boolean BMSH_TBOX_CellOverVoltage2_PMS;
  boolean BMS_BattPackMatchFault_PMS;
  boolean PMS_TBOX_BrkSysErr_PMS;
  boolean PMS_TBOX_HVILSts_PMS;
  boolean PMS_StsBrkSwitch1Invalid_EV;
  boolean PMS_AccessoryCtrlCommand_EV;
  boolean PMS_PTC2Enable_EV;
  boolean PMS_PTC3Enable_EV;
  boolean PMS_BatCoolType_EV;
  boolean PMS_ZeroPwr_Fb_EV;
  boolean PMS_DisChrgrSwtSt_EV;
  boolean PMS_CruisingDstSwtFb_EV;
  uint8 PMS_VINMessageNum_S_EV;
  uint8 PMS_VINCode1_8_15_S_EV;
  uint8 PMS_VINCode2_9_16_S_EV;
  uint8 PMS_VINCode3_10_17_S_EV;
  uint8 PMS_VINCode4_11_S_EV;
  uint8 PMS_VINCode5_12_S_EV;
  uint8 PMS_VINCode6_13_S_EV;
  uint8 PMS_VINCode7_14_S_EV;
  uint8 PMS_EngRecMode_Fb_EV;
  uint8 AC_BMSH_ThermReqFb_EV;
  uint8 PMS_StsBatLockSensor_EV;
  boolean PMS_DCDCAwake_HW_EV;
  uint8 PMS_CoolingFanFaultFB_PMS;
  uint16 PMS_ErrCode_PMS;
  uint16 PMS_GrossComVehWeight_PMS;
  uint8 PMS_OverloadInd_PMS;
  float32 EXT_PO_PWM_1_DutyCycle;
  float32 EXT_PO_PWM_2_DutyCycle;
  float32 EXT_PO_HVIL_1_DutyCycle;
  boolean EXT_DO_RELAY_LS_10;
  boolean EXT_DO_RELAY_LS_9;
  boolean EXT_DO_RELAY_LS_12;
  float32 EXT_PO_PWM_4_DutyCycle;
  boolean EXT_DO_KEY_HS_05;
  boolean EXT_DO_RELAY_LS_7;
  float32 EXT_PO_PWM_1_Period;
  float32 EXT_PO_PWM_2_Period;
  float32 EXT_PO_PWM_4_Period;
  float32 EXT_PO_HVIL_1_Period;
  boolean EXT_DO_RELAY_HS_11;
  uint8 PMS_PTC1ConnStsFb_EV;
  uint8 PMS_PTC1RelayFlt_EV;
  uint8 PMS_PTC3ConnStsFb_EV;
  uint8 PMS_PTC3RelayFlt_EV;
  uint8 PMS_AccessoryConnStsFb_EV;
  uint8 PMS_AccessoryRelayFlt_EV;
  uint8 PMS_PreAccessoryConnStsFb_EV;
  uint8 PMS_PreAccessoryRelayFlt_EV;
  boolean EXT_DO_RELAY_HS_9;
  boolean EXT_DO_RELAY_HS_8;
  boolean EXT_DO_RELAY_HS_6;
  uint8 PMS_PTCRelayVoltSampSwich;
  uint8 PMS_AcceRelayVoltSampSwich;
  boolean PMS_BBM_FaultStatus_EV;
  boolean PMS_BBM_WorkSts_EV;
  uint8 PMS_DrivingTakeEleSts_EV;
  boolean PMS_BBMPowerSupplyEn_Ctrl_EV;
  boolean O_S_PIN123;
  boolean O_S_PIN98;
  boolean EXT_DO_KEY_HS_03;
  boolean PMS_BBMAllowEnable_Ctrl_EV;
  uint8 PMS_BBM1CtrlCmd_EV;
  boolean PMS_BBM_HVReq_EV;
  boolean PMS_StsBrkSwitch2;
  uint32 IPK_IPKTotalOdometer_EV;
  uint8 VCU_BMSH_Inlet_WaterTemp_EV;
  uint8 VCU_BMSH_Outlet_WaterTemp_EV;
  boolean VCU_EVCAN_InhibitFBL_EV;
  boolean VCU_BMSH_FaultResetReq_EV;
  uint8 VCU_ChargeModeReq_EV;
  uint8 VCU_EVCAN_StsSwap_EV;
  uint8 PMS_LockVehPerRxSts_PMS;
  uint8 PMS_VersionConversionRxSts_PMS;
  uint8 PMS_SpdLmtLevelRxSts_PMS;
  uint8 PMS_InventorySpdLmtRxSts_PMS;
  uint8 PMS_TBOX_LifeSts_PMS;
  uint16 PMS_AveragePowerConsumption;
  boolean PMS_0X16A_TimeoutFlag_PMS;
  uint16 PMS_VehicleSpeed_PMS;
  boolean PMS_VehicleSpeedInvalid_PMS;
  uint16 PMS_AveragePowerConsumption_PMS;
  uint8 PMS_PreAccessoryCtrl_EV;
  uint16 PMS_EVDTEodometer_EV;
  uint8 PMS_LockVehExecutedSts_PMS;
  uint16 PMS_ChargPwr_PMS;
  uint8 PMS_VINMessageNum_S_PMS;
  uint8 PMS_VINCode1_8_15_S_PMS;
  uint8 PMS_VINCode2_9_16_S_PMS;
  uint8 PMS_VINCode3_10_17_S_PMS;
  uint8 PMS_VINCode4_11_S_PMS;
  uint8 PMS_VINCode5_12_S_PMS;
  uint8 PMS_VINCode6_13_S_PMS;
  uint8 PMS_VINCode7_14_S_PMS;
  uint8 PMS_HardwareMajorVer_PMS;
  uint8 PMS_HardwareMinorVer_PMS;
  uint8 PMS_SoftwareMajorVer_PMS;
  uint8 PMS_SoftwareMinorVer_PMS;
  uint8 PMS_SWCompileYear_PMS;
  uint8 PMS_SWCompileMonth_PMS;
  uint8 PMS_SWCompileDay_PMS;
  uint32 PMS_IPKTotalOdometer_PMS;
  boolean PMS_OdometerbackupEnable_PMS;
  uint8 PMS_PowerOffCmdSts_PMS;
  uint8 PMS_PowerOffCmdRxSts_PMS;
  boolean PMS_Brake1Switch_PMS;
  boolean PMS_Brake2Switch_PMS;
  uint8 TBOX_ChrgSoftSwCtrlst_EV;
  uint8 PMS_LockVehExecutedSts;
  uint8 PMS_RemChrgCmdFailrPrompt;
  uint8 TBOX_ReservationChrgnSts_EV;
  uint8 PMS_ChargPwr;
  uint8 AC_EWP_SpeedReq;
  uint8 AC_EWP_SpeedReq_LIN;
  uint8 AC_EWP_Heat;
  uint8 AC_EWP_Heat_LIN;
  uint8 AC_EWP_Temp;
  uint8 AC_EWP_Temp_LIN;
  uint8 AC_EWP_Run;
  uint8 AC_EWP_Run_LIN;
  uint8 AC_EWP_HeatrPwrCnsAllwd;
  uint8 AC_EWP_HeatrPwrCnsAllwd_LIN;
  uint8 PMS_Torque_Ovrd_Active;
  uint8 PMS_Torque_Ovrd_Type;
  uint8 PMS_RegulationSpeed_PMS;
  uint8 PMS_AcceSuppressionSts_PMS;
  boolean PMS_TakeEleSwtIndReq_PMS;
  uint8 PMS_CPSRU;
  boolean PMS_Fn1GearRlyDrvStsFb;
  boolean PMS_Fn2GearRlyDrvStsFb;
  boolean PMS_CampModeFb;
  uint8 PMS_CampModeFbFailrReason;
  boolean EXT_DO_RELAY_LS_5;
  uint8 PMS_VehicleSysErrorLevelG1_PMS;
  uint8 ODP_TBOX_TDcDcAlm1_PMS;
  uint8 ODP_TBOX_DcDcStsAlm1_PMS;
  uint8 IPU_MotorTempHighFault2_PMS;
  uint8 IPU_MCUTempHighAlarm2_PMS;
  uint8 BMSH_TBOX_BatTempUniformity3_PMS;
  uint8 BMSH_TBOX_BatOverSOC3_PMS;
  uint8 BMSH_TBOX_SOCHop3_PMS;
  uint8 BMSH_TBOX_BatLowSOC3_PMS;
  uint8 BMSH_TBOX_BatOverCharge3_PMS;
  uint8 BMSH_TBOX_BatUniformity3_PMS;
  uint8 BMSH_TBOX_CellUnderVoltage3_PMS;
  uint8 BMSH_TBOX_BatUnderVoltage3_PMS;
  uint8 BMSH_TBOX_BatOverTemp3_PMS;
  uint8 BMSH_TBOX_BatIsoAlarm3_PMS;
  uint8 BMSH_TBOX_BatOverVoltage3_PMS;
  uint8 BMSH_TBOX_CellOverVoltage3_PMS;
  uint8 PMS_TBOX_BrkSysErr1_PMS;
  uint8 PMS_TBOX_HVILSts1_PMS;
  uint8 BMSH_TBOX_FireAlarm2_PMS;
  uint8 PMS_32960FltNum_PMS;
  uint8 IPU_MotorOverSpdFlt1_PMS;
  uint8 IPU_MotorOverCurrFlt1_PMS;
  uint8 BMSH_BattSysNum_PMS;
  uint8 BMSH_BattPackNum_PMS;
} vcob_VCOP;

#endif

/* PublicStructure Variables for Internal Data, for system '<S53>/SR_latch1' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S61>/Unit Delay' */
} ARID_DEF_SR_latch_swc_VCOP_T;

/* PublicStructure Variables for Internal Data, for system '<S54>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S68>/Unit Delay' */
} ARID_DEF_SR_latch_swc_VCOP_d_T;

/* PublicStructure Variables for Internal Data, for system '<S56>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S74>/Unit Delay' */
} ARID_DEF_SR_latch_swc_VCOP_m_T;

/* PublicStructure Variables for Internal Data, for system '<S40>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S46>/Unit Delay' */
} ARID_DEF_SR_latch_swc_VCOP_p_T;

/* PublicStructure Variables for Internal Data, for system '<S103>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S138>/Unit Delay' */
} ARID_DEF_SR_latch_swc_VCOP_k_T;

/* PublicStructure Variables for Internal Data, for system '<S107>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S148>/Unit Delay' */
} ARID_DEF_SR_latch_swc_VCOP_dk_T;

/* PublicStructure Variables for Internal Data, for system '<S20>/debounce' */
typedef struct {
  float32 t_wait;                      /* '<S26>/timed_debounce' */
  uint8 is_c6_Ricardo_SW_dev_lib;      /* '<S26>/timed_debounce' */
  uint8 is_active_c6_Ricardo_SW_dev_lib;/* '<S26>/timed_debounce' */
} ARID_DEF_debounce_swc_VCOP_T;

/* PublicStructure Variables for Internal Data, for system '<S79>/timed_delay' */
typedef struct {
  float32 t_wait;                      /* '<S79>/timed_delay' */
  uint8 is_c12_Ricardo_SW_dev_lib;     /* '<S79>/timed_delay' */
  uint8 is_active_c12_Ricardo_SW_dev_li;/* '<S79>/timed_delay' */
} ARID_DEF_timed_delay_swc_VCOP_T;

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  ARID_DEF_timed_delay_swc_VCOP_T ARID_DEF_timed_delay;/* '<S80>/timed_delay' */
  ARID_DEF_timed_delay_swc_VCOP_T ARID_DEF_timed_delay_m;/* '<S79>/timed_delay' */
  ARID_DEF_debounce_swc_VCOP_T ARID_DEF_debounce;/* '<S32>/debounce' */
  ARID_DEF_debounce_swc_VCOP_T ARID_DEF_debounce_c;/* '<S20>/debounce' */
  ARID_DEF_SR_latch_swc_VCOP_dk_T ARID_DEF_SR_latch;/* '<S107>/SR_latch' */
  ARID_DEF_SR_latch_swc_VCOP_k_T ARID_DEF_SR_latch_k;/* '<S103>/SR_latch' */
  ARID_DEF_SR_latch_swc_VCOP_p_T ARID_DEF_SR_latch_c;/* '<S40>/SR_latch' */
  ARID_DEF_SR_latch_swc_VCOP_m_T ARID_DEF_SR_latch_b;/* '<S56>/SR_latch' */
  ARID_DEF_SR_latch_swc_VCOP_d_T ARID_DEF_SR_latch_p;/* '<S54>/SR_latch' */
  ARID_DEF_SR_latch_swc_VCOP_T ARID_DEF_SR_latch1;/* '<S53>/SR_latch1' */
  float64 DataTypeConversion11;        /* '<Root>/Data Type Conversion11' */
  float64 DataTypeConversion116;       /* '<Root>/Data Type Conversion116' */
  float64 DataTypeConversion129;       /* '<Root>/Data Type Conversion129' */
  float64 DataTypeConversion131;       /* '<Root>/Data Type Conversion131' */
  float64 DataTypeConversion134;       /* '<Root>/Data Type Conversion134' */
  float64 DataTypeConversion155;       /* '<Root>/Data Type Conversion155' */
  float64 DataTypeConversion156;       /* '<Root>/Data Type Conversion156' */
  float64 DataTypeConversion157;       /* '<Root>/Data Type Conversion157' */
  float64 DataTypeConversion161;       /* '<Root>/Data Type Conversion161' */
  float64 DataTypeConversion164;       /* '<Root>/Data Type Conversion164' */
  float64 DataTypeConversion18;        /* '<Root>/Data Type Conversion18' */
  float64 DataTypeConversion181;       /* '<Root>/Data Type Conversion181' */
  float64 DataTypeConversion212;       /* '<Root>/Data Type Conversion212' */
  float64 DataTypeConversion214;       /* '<Root>/Data Type Conversion214' */
  float64 DataTypeConversion229;       /* '<Root>/Data Type Conversion229' */
  float64 DataTypeConversion241;       /* '<Root>/Data Type Conversion241' */
  float64 DataTypeConversion242;       /* '<Root>/Data Type Conversion242' */
  float64 DataTypeConversion243;       /* '<Root>/Data Type Conversion243' */
  float64 DataTypeConversion244;       /* '<Root>/Data Type Conversion244' */
  float64 DataTypeConversion4;         /* '<Root>/Data Type Conversion4' */
  float64 DataTypeConversion532;       /* '<Root>/Data Type Conversion532' */
  float64 DataTypeConversion537;       /* '<Root>/Data Type Conversion537' */
  float64 DataTypeConversion539;       /* '<Root>/Data Type Conversion539' */
  float64 DataTypeConversion83;        /* '<Root>/Data Type Conversion83' */
  float64 DataTypeConversion91;        /* '<Root>/Data Type Conversion91' */
  float64 srud_st_turtleLmpReq;        /* '<S12>/Signal Conversion13' */
  float64 SignalConversion1;           /* '<S104>/Signal Conversion1' */
  float64 SignalConversion;            /* '<S104>/Signal Conversion' */
  float64 UnitDelay_DSTATE;            /* '<S41>/Unit Delay' */
  float32 DataTypeConversion10;        /* '<Root>/Data Type Conversion10' */
  float32 DataTypeConversion100;       /* '<Root>/Data Type Conversion100' */
  float32 DataTypeConversion102;       /* '<Root>/Data Type Conversion102' */
  float32 DataTypeConversion103;       /* '<Root>/Data Type Conversion103' */
  float32 DataTypeConversion106;       /* '<Root>/Data Type Conversion106' */
  float32 DataTypeConversion108;       /* '<Root>/Data Type Conversion108' */
  float32 DataTypeConversion110;       /* '<Root>/Data Type Conversion110' */
  float32 DataTypeConversion117;       /* '<Root>/Data Type Conversion117' */
  float32 DataTypeConversion118;       /* '<Root>/Data Type Conversion118' */
  float32 DataTypeConversion120;       /* '<Root>/Data Type Conversion120' */
  float32 DataTypeConversion122;       /* '<Root>/Data Type Conversion122' */
  float32 DataTypeConversion124;       /* '<Root>/Data Type Conversion124' */
  float32 DataTypeConversion125;       /* '<Root>/Data Type Conversion125' */
  float32 DataTypeConversion135;       /* '<Root>/Data Type Conversion135' */
  float32 DataTypeConversion162;       /* '<Root>/Data Type Conversion162' */
  float32 DataTypeConversion163;       /* '<Root>/Data Type Conversion163' */
  float32 DataTypeConversion169;       /* '<Root>/Data Type Conversion169' */
  float32 DataTypeConversion171;       /* '<Root>/Data Type Conversion171' */
  float32 DataTypeConversion172;       /* '<Root>/Data Type Conversion172' */
  float32 DataTypeConversion173;       /* '<Root>/Data Type Conversion173' */
  float32 DataTypeConversion174;       /* '<Root>/Data Type Conversion174' */
  float32 DataTypeConversion176;       /* '<Root>/Data Type Conversion176' */
  float32 DataTypeConversion177;       /* '<Root>/Data Type Conversion177' */
  float32 DataTypeConversion178;       /* '<Root>/Data Type Conversion178' */
  float32 DataTypeConversion179;       /* '<Root>/Data Type Conversion179' */
  float32 DataTypeConversion180;       /* '<Root>/Data Type Conversion180' */
  float32 DataTypeConversion182;       /* '<Root>/Data Type Conversion182' */
  float32 DataTypeConversion183;       /* '<Root>/Data Type Conversion183' */
  float32 DataTypeConversion184;       /* '<Root>/Data Type Conversion184' */
  float32 DataTypeConversion188;       /* '<Root>/Data Type Conversion188' */
  float32 DataTypeConversion190;       /* '<Root>/Data Type Conversion190' */
  float32 DataTypeConversion191;       /* '<Root>/Data Type Conversion191' */
  float32 DataTypeConversion193;       /* '<Root>/Data Type Conversion193' */
  float32 DataTypeConversion194;       /* '<Root>/Data Type Conversion194' */
  float32 DataTypeConversion195;       /* '<Root>/Data Type Conversion195' */
  float32 DataTypeConversion199;       /* '<Root>/Data Type Conversion199' */
  float32 DataTypeConversion200;       /* '<Root>/Data Type Conversion200' */
  float32 DataTypeConversion204;       /* '<Root>/Data Type Conversion204' */
  float32 DataTypeConversion206;       /* '<Root>/Data Type Conversion206' */
  float32 DataTypeConversion215;       /* '<Root>/Data Type Conversion215' */
  float32 DataTypeConversion218;       /* '<Root>/Data Type Conversion218' */
  float32 DataTypeConversion221;       /* '<Root>/Data Type Conversion221' */
  float32 DataTypeConversion222;       /* '<Root>/Data Type Conversion222' */
  float32 DataTypeConversion225;       /* '<Root>/Data Type Conversion225' */
  float32 DataTypeConversion226;       /* '<Root>/Data Type Conversion226' */
  float32 DataTypeConversion231;       /* '<Root>/Data Type Conversion231' */
  float32 DataTypeConversion237;       /* '<Root>/Data Type Conversion237' */
  float32 DataTypeConversion238;       /* '<Root>/Data Type Conversion238' */
  float32 DataTypeConversion251;       /* '<Root>/Data Type Conversion251' */
  float32 DataTypeConversion266;       /* '<Root>/Data Type Conversion266' */
  float32 DataTypeConversion49;        /* '<Root>/Data Type Conversion49' */
  float32 DataTypeConversion50;        /* '<Root>/Data Type Conversion50' */
  float32 DataTypeConversion57;        /* '<Root>/Data Type Conversion57' */
  float32 DataTypeConversion61;        /* '<Root>/Data Type Conversion61' */
  float32 DataTypeConversion62;        /* '<Root>/Data Type Conversion62' */
  float32 DataTypeConversion71;        /* '<Root>/Data Type Conversion71' */
  float32 DataTypeConversion74;        /* '<Root>/Data Type Conversion74' */
  float32 DataTypeConversion86;        /* '<Root>/Data Type Conversion86' */
  float32 DataTypeConversion93;        /* '<Root>/Data Type Conversion93' */
  float32 DataTypeConversion94;        /* '<Root>/Data Type Conversion94' */
  float32 DataTypeConversion96;        /* '<Root>/Data Type Conversion96' */
  float32 DataTypeConversion97;        /* '<Root>/Data Type Conversion97' */
  float32 DataTypeConversion98;        /* '<Root>/Data Type Conversion98' */
  float32 TmpBufferAtGround1Outport1;
  float32 SignalConversion4;           /* '<S12>/Signal Conversion4' */
  float32 SignalConversion9;           /* '<S12>/Signal Conversion9' */
  float32 SignalConversion10;          /* '<S12>/Signal Conversion10' */
  float32 SignalConversion11;          /* '<S12>/Signal Conversion11' */
  float32 thmd_t_hvbHdInCoolTemp_C;    /* '<S13>/Switch9' */
  float32 thmd_t_hvbHdOutCoolTemp_C;   /* '<S13>/Switch10' */
  float32 SignalConversion6;           /* '<S13>/Signal Conversion6' */
  float32 Switch2;                     /* '<S13>/Switch2' */
  float32 SignalConversion_e;          /* '<S13>/Signal Conversion' */
  float32 SignalConversion1_g;         /* '<S13>/Signal Conversion1' */
  float32 SignalConversion7;           /* '<S13>/Signal Conversion7' */
  float32 thmd_pwr_accmHvClPwrAllwd_kW;/* '<S13>/Signal Conversion8' */
  float32 thmd_pwr_ptcHvHtPwrAllwd_kW; /* '<S13>/Signal Conversion9' */
  float32 t_wait;                      /* '<S37>/timed_debounce' */
  float32 t_wait_i;                    /* '<S35>/timed_debounce' */
  uint32 DataTypeConversion132;        /* '<Root>/Data Type Conversion132' */
  uint32 presentTicks;                 /* '<S12>/Chart' */
  uint32 elapsedTicks;                 /* '<S12>/Chart' */
  uint32 previousTicks;                /* '<S12>/Chart' */
  uint8 DataTypeConversion1;           /* '<Root>/Data Type Conversion1' */
  uint8 DataTypeConversion105;         /* '<Root>/Data Type Conversion105' */
  uint8 DataTypeConversion107;         /* '<Root>/Data Type Conversion107' */
  uint8 DataTypeConversion112;         /* '<Root>/Data Type Conversion112' */
  uint8 DataTypeConversion12;          /* '<Root>/Data Type Conversion12' */
  uint8 DataTypeConversion128;         /* '<Root>/Data Type Conversion128' */
  uint8 DataTypeConversion13;          /* '<Root>/Data Type Conversion13' */
  uint8 DataTypeConversion133;         /* '<Root>/Data Type Conversion133' */
  uint8 DataTypeConversion14;          /* '<Root>/Data Type Conversion14' */
  uint8 DataTypeConversion151;         /* '<Root>/Data Type Conversion151' */
  uint8 DataTypeConversion16;          /* '<Root>/Data Type Conversion16' */
  uint8 DataTypeConversion165;         /* '<Root>/Data Type Conversion165' */
  uint8 DataTypeConversion168;         /* '<Root>/Data Type Conversion168' */
  uint8 DataTypeConversion17;          /* '<Root>/Data Type Conversion17' */
  uint8 DataTypeConversion170;         /* '<Root>/Data Type Conversion170' */
  uint8 DataTypeConversion19;          /* '<Root>/Data Type Conversion19' */
  uint8 DataTypeConversion2;           /* '<Root>/Data Type Conversion2' */
  uint8 DataTypeConversion20;          /* '<Root>/Data Type Conversion20' */
  uint8 DataTypeConversion21;          /* '<Root>/Data Type Conversion21' */
  uint8 DataTypeConversion22;          /* '<Root>/Data Type Conversion22' */
  uint8 DataTypeConversion232;         /* '<Root>/Data Type Conversion232' */
  uint8 DataTypeConversion234;         /* '<Root>/Data Type Conversion234' */
  uint8 DataTypeConversion236;         /* '<Root>/Data Type Conversion236' */
  uint8 DataTypeConversion3;           /* '<Root>/Data Type Conversion3' */
  uint8 DataTypeConversion41;          /* '<Root>/Data Type Conversion41' */
  uint8 DataTypeConversion518;         /* '<Root>/Data Type Conversion518' */
  uint8 DataTypeConversion58;          /* '<Root>/Data Type Conversion58' */
  uint8 DataTypeConversion59;          /* '<Root>/Data Type Conversion59' */
  uint8 DataTypeConversion87;          /* '<Root>/Data Type Conversion87' */
  uint8 DataTypeConversion90;          /* '<Root>/Data Type Conversion90' */
  uint8 DataTypeConversion92;          /* '<Root>/Data Type Conversion92' */
  uint8 DataTypeConversion95;          /* '<Root>/Data Type Conversion95' */
  uint8 TmpBufferAtGround2Outport1;
  uint8 Switch;                        /* '<S15>/Switch' */
  uint8 SignalConversion_a;            /* '<S12>/Signal Conversion' */
  uint8 Add16;                         /* '<S12>/Add16' */
  uint8 Max;                           /* '<S12>/Max' */
  uint8 Switch_a;                      /* '<S12>/Switch' */
  uint8 Switch2_o;                     /* '<S12>/Switch2' */
  uint8 Switch1;                       /* '<S77>/Switch1' */
  uint8 Switch9;                       /* '<S77>/Switch9' */
  uint8 SignalConversion5;             /* '<S12>/Signal Conversion5' */
  uint8 SignalConversion6_l;           /* '<S12>/Signal Conversion6' */
  uint8 SignalConversion7_m;           /* '<S12>/Signal Conversion7' */
  uint8 SignalConversion8;             /* '<S12>/Signal Conversion8' */
  uint8 Switch4;                       /* '<S12>/Switch4' */
  uint8 Switch6;                       /* '<S76>/Switch6' */
  uint8 Add;                           /* '<S12>/Add' */
  uint8 Add1;                          /* '<S12>/Add1' */
  uint8 Add8;                          /* '<S12>/Add8' */
  uint8 Add9;                          /* '<S12>/Add9' */
  uint8 VINCode1;                      /* '<S12>/Chart' */
  uint8 VINCode2;                      /* '<S12>/Chart' */
  uint8 VINCode3;                      /* '<S12>/Chart' */
  uint8 VINCode4;                      /* '<S12>/Chart' */
  uint8 VINCode5;                      /* '<S12>/Chart' */
  uint8 VINCode6;                      /* '<S12>/Chart' */
  uint8 VINCode7;                      /* '<S12>/Chart' */
  uint8 VINMessageNum;                 /* '<S12>/Chart' */
  uint8 acud_st_acuCrashOutput;        /* '<S5>/Switch' */
  uint8 dspd_st_gearOptErr;            /* '<S7>/Signal Conversion' */
  uint8 Switch_c;                      /* '<S105>/Switch' */
  uint8 Switch8;                       /* '<S105>/Switch8' */
  uint8 bmsd_e_modeTgt;                /* '<S10>/bmsd_e_modeTgt' */
  uint8 Switch_p;                      /* '<S10>/Switch' */
  PmmStatus DataTypeConversion7;       /* '<Root>/Data Type Conversion7' */
  ParkingStatus DataTypeConversion52;  /* '<Root>/Data Type Conversion52' */
  GearLeverPos DataTypeConversion524;  /* '<Root>/Data Type Conversion524' */
  ElMac DataTypeConversion6;           /* '<Root>/Data Type Conversion6' */
  DriveDir DataTypeConversion5;        /* '<Root>/Data Type Conversion5' */
  DCDCMode DataTypeConversion515;      /* '<Root>/Data Type Conversion515' */
  uint8 UnitDelay_DSTATE_h;            /* '<S77>/Unit Delay' */
  uint8 is_c3_swc_VCOP;                /* '<S12>/Chart' */
  uint8 is_VIN_SEND;                   /* '<S12>/Chart' */
  uint8 is_active_c3_swc_VCOP;         /* '<S12>/Chart' */
  uint8 temporalCounter_i1;            /* '<S12>/Chart' */
  uint8 is_c6_Ricardo_SW_dev_lib;      /* '<S37>/timed_debounce' */
  uint8 is_active_c6_Ricardo_SW_dev_lib;/* '<S37>/timed_debounce' */
  uint8 is_c6_Ricardo_SW_dev_lib_e;    /* '<S35>/timed_debounce' */
  uint8 is_active_c6_Ricardo_SW_dev_l_b;/* '<S35>/timed_debounce' */
  boolean DataTypeConversion115;       /* '<Root>/Data Type Conversion115' */
  boolean DataTypeConversion121;       /* '<Root>/Data Type Conversion121' */
  boolean DataTypeConversion123;       /* '<Root>/Data Type Conversion123' */
  boolean DataTypeConversion130;       /* '<Root>/Data Type Conversion130' */
  boolean DataTypeConversion145;       /* '<Root>/Data Type Conversion145' */
  boolean DataTypeConversion167;       /* '<Root>/Data Type Conversion167' */
  boolean DataTypeConversion185;       /* '<Root>/Data Type Conversion185' */
  boolean DataTypeConversion186;       /* '<Root>/Data Type Conversion186' */
  boolean DataTypeConversion187;       /* '<Root>/Data Type Conversion187' */
  boolean DataTypeConversion189;       /* '<Root>/Data Type Conversion189' */
  boolean DataTypeConversion192;       /* '<Root>/Data Type Conversion192' */
  boolean DataTypeConversion196;       /* '<Root>/Data Type Conversion196' */
  boolean DataTypeConversion197;       /* '<Root>/Data Type Conversion197' */
  boolean DataTypeConversion198;       /* '<Root>/Data Type Conversion198' */
  boolean DataTypeConversion201;       /* '<Root>/Data Type Conversion201' */
  boolean DataTypeConversion202;       /* '<Root>/Data Type Conversion202' */
  boolean DataTypeConversion220;       /* '<Root>/Data Type Conversion220' */
  boolean DataTypeConversion223;       /* '<Root>/Data Type Conversion223' */
  boolean DataTypeConversion224;       /* '<Root>/Data Type Conversion224' */
  boolean DataTypeConversion227;       /* '<Root>/Data Type Conversion227' */
  boolean DataTypeConversion228;       /* '<Root>/Data Type Conversion228' */
  boolean DataTypeConversion233;       /* '<Root>/Data Type Conversion233' */
  boolean DataTypeConversion239;       /* '<Root>/Data Type Conversion239' */
  boolean DataTypeConversion250;       /* '<Root>/Data Type Conversion250' */
  boolean DataTypeConversion42;        /* '<Root>/Data Type Conversion42' */
  boolean DataTypeConversion44;        /* '<Root>/Data Type Conversion44' */
  boolean DataTypeConversion519;       /* '<Root>/Data Type Conversion519' */
  boolean DataTypeConversion535;       /* '<Root>/Data Type Conversion535' */
  boolean DataTypeConversion54;        /* '<Root>/Data Type Conversion54' */
  boolean SignalConversion1_k;         /* '<S12>/Signal Conversion1' */
  boolean RelationalOperator16;        /* '<S12>/Relational Operator16' */
  boolean RelationalOperator17;        /* '<S12>/Relational Operator17' */
  boolean RelationalOperator18;        /* '<S12>/Relational Operator18' */
  boolean RelationalOperator19;        /* '<S12>/Relational Operator19' */
  boolean RelationalOperator20;        /* '<S12>/Relational Operator20' */
  boolean RelationalOperator21;        /* '<S12>/Relational Operator21' */
  boolean RelationalOperator22;        /* '<S12>/Relational Operator22' */
  boolean RelationalOperator23;        /* '<S12>/Relational Operator23' */
  boolean RelationalOperator24;        /* '<S12>/Relational Operator24' */
  boolean RelationalOperator25;        /* '<S12>/Relational Operator25' */
  boolean RelationalOperator26;        /* '<S12>/Relational Operator26' */
  boolean RelationalOperator28;        /* '<S12>/Relational Operator28' */
  boolean RelationalOperator29;        /* '<S12>/Relational Operator29' */
  boolean RelationalOperator27;        /* '<S12>/Relational Operator27' */
  boolean SignalConversion2;           /* '<S12>/Signal Conversion2' */
  boolean SignalConversion3;           /* '<S12>/Signal Conversion3' */
  boolean dspd_b_gearPosVld;           /* '<S7>/Signal Conversion1' */
  boolean Switch2_g;                   /* '<S10>/Switch2' */
  boolean Relay4_Mode;                 /* '<S225>/Relay4' */
  boolean Relay_Mode;                  /* '<S41>/Relay' */
} ARID_DEF_swc_VCOP_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint64 DataTypeConversion237;  /* '<S1>/Data Type Conversion237' */
  const uint64 DataTypeConversion335;  /* '<S1>/Data Type Conversion335' */
  uint32 PMS_ReqSeed;                  /* '<S1>/Data Type Conversion238' */
  uint32 PMS_PEPSAuth;                 /* '<S1>/Data Type Conversion336' */
  const float32 DataTypeConversion9;   /* '<Root>/Data Type Conversion9' */
  const float32 t_delay_off;           /* '<S80>/Saturation1' */
  const uint8 DataTypeConversion11;    /* '<S1>/Data Type Conversion11' */
  uint8 PMS_Command_AliveCounter_EV;   /* '<S1>/Data Type Conversion12' */
  const uint8 DataTypeConversion13;    /* '<S1>/Data Type Conversion13' */
  uint8 PMS_Command_Checksum_EV;       /* '<S1>/Data Type Conversion14' */
  const uint8 DataTypeConversion23;    /* '<S1>/Data Type Conversion23' */
  uint8 VCU_BMSH_Ctrl_AliveCounter;    /* '<S1>/Data Type Conversion24' */
  const uint8 DataTypeConversion25;    /* '<S1>/Data Type Conversion25' */
  uint8 VCU_BMSH_Ctrl_CheckSum;        /* '<S1>/Data Type Conversion26' */
  const uint8 DataTypeConversion33;    /* '<S1>/Data Type Conversion33' */
  uint8 PMS_DCDC_Ctrl_AliveCounter;    /* '<S1>/Data Type Conversion34' */
  const uint8 DataTypeConversion35;    /* '<S1>/Data Type Conversion35' */
  uint8 PMS_DCDC_Ctrl_Checksum;        /* '<S1>/Data Type Conversion36' */
  const uint8 DataTypeConversion44;    /* '<S1>/Data Type Conversion44' */
  uint8 VCU_VehicleInfo_AliveCounte;   /* '<S1>/Data Type Conversion45' */
  const uint8 DataTypeConversion46;    /* '<S1>/Data Type Conversion46' */
  uint8 VCU_VehicleInfo_CheckSum;      /* '<S1>/Data Type Conversion47' */
  const uint8 DataTypeConversion66;    /* '<S1>/Data Type Conversion66' */
  uint8 PMS_Command_AliveCounter;      /* '<S1>/Data Type Conversion67' */
  const uint8 DataTypeConversion68;    /* '<S1>/Data Type Conversion68' */
  uint8 PMS_Command_Checksum;          /* '<S1>/Data Type Conversion69' */
  const uint8 DataTypeConversion77;    /* '<S1>/Data Type Conversion77' */
  const uint8 DataTypeConversion79;    /* '<S1>/Data Type Conversion79' */
  const uint8 DataTypeConversion81;    /* '<S1>/Data Type Conversion81' */
  const uint8 DataTypeConversion83;    /* '<S1>/Data Type Conversion83' */
  const uint8 DataTypeConversion92;    /* '<S1>/Data Type Conversion92' */
  uint8 PMS_CSControl2_AliveCounter;   /* '<S1>/Data Type Conversion93' */
  const uint8 DataTypeConversion94;    /* '<S1>/Data Type Conversion94' */
  uint8 PMS_CSControl2_CheckSum;       /* '<S1>/Data Type Conversion96' */
  const uint8 DataTypeConversion466;   /* '<S1>/Data Type Conversion466' */
  uint8 PMS_GearOperateErr;            /* '<S1>/Data Type Conversion467' */
  const uint8 DataTypeConversion470;   /* '<S1>/Data Type Conversion470' */
  uint8 PMS_ePTModeSelect;             /* '<S1>/Data Type Conversion100' */
  const uint8 DataTypeConversion101;   /* '<S1>/Data Type Conversion101' */
  uint8 PMS_ePTModeActual;             /* '<S1>/Data Type Conversion102' */
  const uint8 DataTypeConversion103;   /* '<S1>/Data Type Conversion103' */
  const uint8 DataTypeConversion105;   /* '<S1>/Data Type Conversion105' */
  const uint8 DataTypeConversion119;   /* '<S1>/Data Type Conversion119' */
  uint8 PMS_Ctrl_AliveCounter;         /* '<S1>/Data Type Conversion120' */
  const uint8 DataTypeConversion121;   /* '<S1>/Data Type Conversion121' */
  uint8 PMS_Ctrl_Checksum;             /* '<S1>/Data Type Conversion122' */
  const uint8 DataTypeConversion131;   /* '<S1>/Data Type Conversion131' */
  uint8 PMS_ACC_BeControlled_Status;   /* '<S1>/Data Type Conversion132' */
  const uint8 DataTypeConversion141;   /* '<S1>/Data Type Conversion141' */
  const uint8 DataTypeConversion3;     /* '<S1>/Data Type Conversion3' */
  uint8 PMS_ModeControl_AliveCounte;   /* '<S1>/Data Type Conversion4' */
  const uint8 DataTypeConversion147;   /* '<S1>/Data Type Conversion147' */
  uint8 PMS_ModeControl_CheckSum;      /* '<S1>/Data Type Conversion148' */
  const uint8 DataTypeConversion155;   /* '<S1>/Data Type Conversion155' */
  const uint8 DataTypeConversion157;   /* '<S1>/Data Type Conversion157' */
  const uint8 DataTypeConversion163;   /* '<S1>/Data Type Conversion163' */
  uint8 PMS_EngTrqReqSrc;              /* '<S1>/Data Type Conversion164' */
  const uint8 DataTypeConversion165;   /* '<S1>/Data Type Conversion165' */
  const uint8 DataTypeConversion167;   /* '<S1>/Data Type Conversion167' */
  uint8 PMS_EngControl_AliveCounter;   /* '<S1>/Data Type Conversion168' */
  const uint8 DataTypeConversion169;   /* '<S1>/Data Type Conversion169' */
  uint8 PMS_EngControl_CheckSum;       /* '<S1>/Data Type Conversion170' */
  const uint8 DataTypeConversion175;   /* '<S1>/Data Type Conversion175' */
  const uint8 DataTypeConversion177;   /* '<S1>/Data Type Conversion177' */
  uint8 PMS_CruiseControlSts;          /* '<S1>/Data Type Conversion178' */
  const uint8 DataTypeConversion179;   /* '<S1>/Data Type Conversion179' */
  const uint8 DataTypeConversion181;   /* '<S1>/Data Type Conversion181' */
  uint8 PMS_ControlSetSpeed;           /* '<S1>/Data Type Conversion182' */
  const uint8 DataTypeConversion183;   /* '<S1>/Data Type Conversion183' */
  uint8 PMS_DM_FailureReasonAndSysF;   /* '<S1>/Data Type Conversion184' */
  const uint8 DataTypeConversion185;   /* '<S1>/Data Type Conversion185' */
  uint8 PMS_CSControl1_AliveCounter;   /* '<S1>/Data Type Conversion186' */
  const uint8 DataTypeConversion187;   /* '<S1>/Data Type Conversion187' */
  uint8 PMS_CSControl1_CheckSum;       /* '<S1>/Data Type Conversion188' */
  const uint8 DataTypeConversion193;   /* '<S1>/Data Type Conversion193' */
  uint8 PMS_EpedalActive;              /* '<S1>/Data Type Conversion194' */
  const uint8 DataTypeConversion195;   /* '<S1>/Data Type Conversion195' */
  uint8 PMS_EPedlDrvrIndcnMsg;         /* '<S1>/Data Type Conversion196' */
  const uint8 DataTypeConversion201;   /* '<S1>/Data Type Conversion201' */
  const uint8 DataTypeConversion233;   /* '<S1>/Data Type Conversion233' */
  uint8 PMS_AuthResult;                /* '<S1>/Data Type Conversion234' */
  const uint8 DataTypeConversion235;   /* '<S1>/Data Type Conversion235' */
  uint8 PMS_RespResult;                /* '<S1>/Data Type Conversion236' */
  const uint8 DataTypeConversion239;   /* '<S1>/Data Type Conversion239' */
  uint8 PMS_ExecuteLockVehResults;     /* '<S1>/Data Type Conversion240' */
  const uint8 DataTypeConversion267;   /* '<S1>/Data Type Conversion267' */
  const uint8 DataTypeConversion271;   /* '<S1>/Data Type Conversion271' */
  uint8 BMSH_VoltCurr_AliveCounter;    /* '<S1>/Data Type Conversion272' */
  const uint8 DataTypeConversion273;   /* '<S1>/Data Type Conversion273' */
  uint8 BMSH_VoltCurr_Checksum;        /* '<S1>/Data Type Conversion274' */
  const uint8 DataTypeConversion281;   /* '<S1>/Data Type Conversion281' */
  uint8 BMSH_Battery_Performance_Al;   /* '<S1>/Data Type Conversion282' */
  const uint8 DataTypeConversion283;   /* '<S1>/Data Type Conversion283' */
  uint8 BMSH_Battery_Performance_Ch;   /* '<S1>/Data Type Conversion284' */
  const uint8 DataTypeConversion313;   /* '<S1>/Data Type Conversion313' */
  const uint8 DataTypeConversion483;   /* '<S1>/Data Type Conversion483' */
  const uint8 DataTypeConversion489;   /* '<S1>/Data Type Conversion489' */
  uint8 PMS_CurrentGearPosition_EV;    /* '<S1>/Data Type Conversion490' */
  const uint8 DataTypeConversion491;   /* '<S1>/Data Type Conversion491' */
  const uint8 DataTypeConversion495;   /* '<S1>/Data Type Conversion495' */
  uint8 EDCP_FltLevel;                 /* '<S1>/Data Type Conversion498' */
  const uint8 DataTypeConversion499;   /* '<S1>/Data Type Conversion499' */
  uint8 PMS_EDCPEnable_EV;             /* '<S1>/Data Type Conversion500' */
  uint8 PMS_EDCPPWMCtrl_EV;            /* '<S1>/Data Type Conversion502' */
  const uint8 DataTypeConversion507;   /* '<S1>/Data Type Conversion507' */
  uint8 EDCP_State;                    /* '<S1>/Data Type Conversion508' */
  uint8 PMS_BattPackInCoolTempback_;   /* '<S1>/Data Type Conversion540' */
  uint8 PMS_BattPackOutCoolTempback;   /* '<S1>/Data Type Conversion542' */
  uint8 PMS_DDwaterpump_PWMCtrl_EV;    /* '<S1>/Data Type Conversion548' */
  const uint8 DataTypeConversion769;   /* '<S1>/Data Type Conversion769' */
  const uint8 Switch5;                 /* '<S12>/Switch5' */
  const uint8 DataTypeConversion501;   /* '<S1>/Data Type Conversion501' */
  const uint8 DataTypeConversion547;   /* '<S1>/Data Type Conversion547' */
  const uint8 DataTypeConversion539;   /* '<S1>/Data Type Conversion539' */
  const uint8 DataTypeConversion541;   /* '<S1>/Data Type Conversion541' */
  const uint8 DataTypeConversion497;   /* '<S1>/Data Type Conversion497' */
  const boolean DataTypeConversion8;   /* '<Root>/Data Type Conversion8' */
  boolean PMS_DriverGearAbort;         /* '<S1>/Data Type Conversion78' */
  boolean PMS_RegenTarTrqPotQualifier; /* '<S1>/Data Type Conversion80' */
  boolean PMS_RegenTrqActQualifier;    /* '<S1>/Data Type Conversion82' */
  boolean PMS_RegenTrqPotQualifier;    /* '<S1>/Data Type Conversion85' */
  boolean PMS_DriverRemind;            /* '<S1>/Data Type Conversion104' */
  boolean PMS_ChargerFault;            /* '<S1>/Data Type Conversion106' */
  boolean PMS_APA_BeControlled_Status; /* '<S1>/Data Type Conversion142' */
  boolean PMS_ActualPTTorqueInvalid;   /* '<S1>/Data Type Conversion156' */
  boolean PMS_DriverDemandTorqueInval; /* '<S1>/Data Type Conversion6' */
  boolean PMS_LimpHomeSts;             /* '<S1>/Data Type Conversion166' */
  boolean PMS_StartActive;             /* '<S1>/Data Type Conversion176' */
  boolean PMS_CruiseSwitchSts;         /* '<S1>/Data Type Conversion180' */
  boolean PMS_HvBattCooltLvl;          /* '<S1>/Data Type Conversion202' */
  boolean BMSH_HvShutdownReq;          /* '<S1>/Data Type Conversion268' */
  boolean BMSH_ChargeToBeFinished;     /* '<S1>/Data Type Conversion314' */
  boolean PMS_TBOX_HVILState_3A1;      /* '<S1>/Data Type Conversion484' */
  boolean PMS_CurrentGearPosition_Val; /* '<S1>/Data Type Conversion492' */
  boolean PMS_HVILSts_UB_EV;           /* '<S1>/Data Type Conversion496' */
  const boolean DataTypeConversion740; /* '<S1>/Data Type Conversion740' */
  boolean PMS_0X16A_TimeoutFlag_EV;    /* '<S1>/Data Type Conversion741' */
  boolean PMS_PEPS_0x1E2_TimeoutFlag_; /* '<S1>/Data Type Conversion770' */
  const boolean DataTypeConversion55;  /* '<S1>/Data Type Conversion55' */
  boolean BMS_BattPackMatchFault_PMS;  /* '<S1>/Data Type Conversion58' */
  const boolean RelationalOperator32;  /* '<S12>/Relational Operator32' */
  const boolean RelationalOperator33;  /* '<S12>/Relational Operator33' */
  const boolean RelationalOperator34;  /* '<S12>/Relational Operator34' */
  const boolean RelationalOperator35;  /* '<S12>/Relational Operator35' */
  const boolean RelationalOperator12;  /* '<S12>/Relational Operator12' */
  const boolean RelationalOperator11;  /* '<S12>/Relational Operator11' */
  const boolean LogicalOperator6;      /* '<S12>/Logical Operator6' */
  const boolean RelationalOperator14;  /* '<S12>/Relational Operator14' */
  const boolean RelationalOperator13;  /* '<S12>/Relational Operator13' */
  const boolean LogicalOperator7;      /* '<S12>/Logical Operator7' */
} ConstB_swc_VCOP_T;

/* Real-time Model Data Structure */
struct tag_RTM_swc_VCOP_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32 clockTick0;
  } Timing;
};

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_swc_VCOP_T swc_VCOP_ARID_DEF;
extern const ConstB_swc_VCOP_T swc_VCOP_ConstB;/* constant block i/o */

/* Exported data declaration */
#define swc_VCOP_START_SEC_CONST_VOLATILE
#include "swc_VCOP_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_CAL */
extern const volatile uint8 dccc_e_dcdcReqModeDflt;/* Referenced by: '<S6>/Constant3' */

/* DC/DC Request Mode default value */
extern const volatile float32 dspc_t_ipcSgnlTrnOffDly_s;/* Referenced by:
                                                         * '<S23>/Constant1'
                                                         * '<S24>/Constant1'
                                                         */

/* Display Turn Off Delay Time */
extern const volatile float32 dspc_t_ipcSgnlTrnOnDly_s;/* Referenced by:
                                                        * '<S20>/Constant'
                                                        * '<S23>/Constant'
                                                        * '<S24>/Constant'
                                                        * '<S32>/Constant'
                                                        */

/* Display Turn On Delay Time */
extern const volatile boolean eadc_b_enbSflEad2TqLmt;/* Referenced by: '<S39>/Constant5' */

/* SFL torque Limit Enable */
extern const volatile boolean eadc_b_newWkModEnb;/* Referenced by: '<S41>/Constant34' */

/* New Work Mode Enable */
extern const volatile uint8 eadc_st_inv2ModeReqDft;/* Referenced by: '<S8>/Constant5' */

/* Secondary EAD Requested Mode default value */
extern const volatile uint8 epbc_st_parkStatusDflt;/* Referenced by: '<S9>/Constant2' */

/* EPB Parking Status default value */
extern const volatile float32 hvbc_pwr_cntnrDisThld_kW;/* Referenced by: '<S53>/Constant37' */

/* HVB Discharge Power Container Control Disable Lower Threshold */
extern const volatile float32 hvbc_pwr_cntnrEnaThld_kW;/* Referenced by: '<S53>/Constant36' */

/* HVB Discharge Power Container Control Enable Upper Threshold */
extern const volatile uint16 swcvcop_vilc_tq_vscESCMotTqRef_Nm;/* Referenced by: '<S236>/Constant32' */

/* Reference Motor Torque */
extern const volatile float32 thmc_t_ptcTempSettingPTCDis_C;/* Referenced by: '<S86>/EP3_HiSpd1' */

/* VCU BPTC Temperature Setting when PTC disable */
extern const volatile float32 thmc_t_ptcTempSettingPTCEna_C;/* Referenced by: '<S86>/EP3_HiSpd3' */

/* VCU BPTC Temperature Setting when PTC enable */
extern const volatile float32 vild_u_RelayClose_V;/* Referenced by:
                                                   * '<S371>/Constant'
                                                   * '<S372>/Constant'
                                                   * '<S373>/Constant'
                                                   */
extern const volatile boolean volc_12VbatRlyReq_ovrdval;
                         /* Referenced by: '<S181>/volc_WatPmpEP3PWM_ovrdval' */

/* Override value for signal 12VbatRlyReq */
extern const volatile boolean volc_12vDCDCEn_ovrdval;
                            /* Referenced by: '<S182>/volc_12vDCDCEn_ovrdval' */

/* Override value for signal 12vDCDCEn */
extern const volatile boolean volc_24vDCDCEn_ovrdval;
                            /* Referenced by: '<S183>/volc_24vDCDCEn_ovrdval' */

/* Override value for signal 24vDCDCEn */
extern const volatile uint8 volc_AC_EWP_Heat_ovrdval;
                /* Referenced by: '<S374>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile float32 volc_AC_EWP_HeatrPwrCnsAllwd_ovrdval;
                /* Referenced by: '<S375>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile uint8 volc_AC_EWP_Run_ovrdval;
                /* Referenced by: '<S376>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile uint8 volc_AC_EWP_SpeedReq_ovrdval;
                /* Referenced by: '<S377>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile float32 volc_AC_EWP_Temp_ovrdval;
                /* Referenced by: '<S378>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile float32 volc_BMSH_ACChgTimeRemain_ovrdval;
                 /* Referenced by: '<S718>/volc_BMSH_ACChgTimeRemain_ovrdval' */
extern const volatile float32 volc_BMSH_BattCurr_ovrdval;
                        /* Referenced by: '<S719>/volc_BMSH_BattCurr_ovrdval' */
extern const volatile uint8 volc_BMSH_BattFaultLampState_ovrdval;
              /* Referenced by: '<S720>/volc_BMSH_BattFaultLampState_ovrdval' */
extern const volatile uint8 volc_BMSH_CCM_ThermalManageReq_ovrdval;
            /* Referenced by: '<S721>/volc_BMSH_CCM_ThermalManageReq_ovrdval' */
extern const volatile uint8 volc_BMSH_Cell_TotalNum_ovrdval;
                   /* Referenced by: '<S722>/volc_BMSH_Cell_TotalNum_ovrdval' */
extern const volatile uint8 volc_BMSH_ChargeLEDCtrl_ovrdval;
                   /* Referenced by: '<S723>/volc_BMSH_ChargeLEDCtrl_ovrdval' */
extern const volatile uint8 volc_BMSH_Charge_Over_Current_ovrdval;
             /* Referenced by: '<S724>/volc_BMSH_Charge_Over_Current_ovrdval' */
extern const volatile uint8 volc_BMSH_ChgTimeRemain_ovrdval;
                   /* Referenced by: '<S725>/volc_BMSH_ChgTimeRemain_ovrdval' */
extern const volatile uint8
  volc_BMSH_DCChgminusSocketTempSensing_Failure_ovrdval;
/* Referenced by: '<S726>/volc_BMSH_DCChgminusSocketTempSensing_Failure_ovrdval' */
extern const volatile uint8 volc_BMSH_DCChgplusSocketTempSensing_Failure_ovrdval;
/* Referenced by: '<S727>/volc_BMSH_DCChgplusSocketTempSensing_Failure_ovrdval' */
extern const volatile uint8 volc_BMSH_FastChgCC2ConntState_ovrdval;
            /* Referenced by: '<S728>/volc_BMSH_FastChgCC2ConntState_ovrdval' */
extern const volatile uint8 volc_BMSH_HvBattThermMod_ovrdval;
                       /* Referenced by: '<S407>/volc_PMS_ThermalReq_ovrdval' */
extern const volatile uint8 volc_BMSH_InsulationRes_Fault_ovrdval;
             /* Referenced by: '<S729>/volc_BMSH_InsulationRes_Fault_ovrdval' */
extern const volatile boolean volc_BMSH_ThermalOutofControl_ovrdval;
             /* Referenced by: '<S730>/volc_BMSH_ThermalOutofControl_ovrdval' */
extern const volatile boolean volc_BMSH_Vehicle_HVILSts_PHEV_ovrdval;
            /* Referenced by: '<S731>/volc_BMSH_Vehicle_HVILSts_PHEV_ovrdval' */
extern const volatile uint8 volc_EDCP_Flt_ovrdval;
                             /* Referenced by: '<S401>/volc_EDCP_Flt_ovrdval' */
extern const volatile uint8 volc_HBCPFlt_ovrdval;
                       /* Referenced by: '<S402>/volc_PMS_ThermalReq_ovrdval' */
extern const volatile uint8 volc_PMS_32960FltNum_ovrdval;
                      /* Referenced by: '<S732>/volc_PMS_32960FltNum_ovrdval' */
extern const volatile uint8 volc_PMS_AcceRelayVoltSampSwich_ovrdval;
           /* Referenced by: '<S855>/volc_PMS_AcceRelayVoltSampSwich_ovrdval' */
extern const volatile uint8 volc_PMS_AcceSuppressionSts_ovrdval;
                 /* Referenced by: '<S379>/volc_VCU_DriveCircuitTemp_ovrdval' */
extern const volatile float32 volc_PMS_Acceleration_ovrdval;
                     /* Referenced by: '<S162>/volc_PMS_Acceleration_ovrdval' */
extern const volatile uint8 volc_PMS_AccessoryConnStsFb_ovrdval;
               /* Referenced by: '<S577>/volc_PMS_AccessoryConnStsFb_ovrdval' */
extern const volatile boolean volc_PMS_AccessoryCtrlCommand_ovrdval;
             /* Referenced by: '<S258>/volc_PMS_AccessoryCtrlCommand_ovrdval' */
extern const volatile uint8 volc_PMS_AccessoryRelayFlt_ovrdval;
                /* Referenced by: '<S578>/volc_PMS_AccessoryRelayFlt_ovrdval' */
extern const volatile float32 volc_PMS_ActualPTTorque_ovrdval;
                   /* Referenced by: '<S733>/volc_PMS_ActualPTTorque_ovrdval' */
extern const volatile boolean volc_PMS_BBM_FaultStatus_ovrdval;
                  /* Referenced by: '<S259>/volc_PMS_BBM_FaultStatus_ovrdval' */
extern const volatile boolean volc_PMS_BBM_WorkSts_ovrdval;
                      /* Referenced by: '<S260>/volc_PMS_BBM_WorkSts_ovrdval' */
extern const volatile uint8 volc_PMS_BMS_Reignstatus1_ovrdval;
                         /* Referenced by: '<S734>/volc_PMS_ePTFault_ovrdval' */
extern const volatile uint8 volc_PMS_BMS_Reignstatus2_ovrdval;
                         /* Referenced by: '<S735>/volc_PMS_ePTFault_ovrdval' */
extern const volatile boolean volc_PMS_Brake_LightsRequest_ovrdval;
              /* Referenced by: '<S736>/volc_PMS_Brake_LightsRequest_ovrdval' */
extern const volatile uint8 volc_PMS_CPSRU_ovrdval;
                 /* Referenced by: '<S380>/volc_VCU_DriveCircuitTemp_ovrdval' */
extern const volatile uint8 volc_PMS_CampModeFbFailrReason_ovrdval;
            /* Referenced by: '<S738>/volc_PMS_CampModeFbFailrReason_ovrdval' */
extern const volatile boolean volc_PMS_CampModeFb_ovrdval;
                       /* Referenced by: '<S737>/volc_PMS_CampModeFb_ovrdval' */
extern const volatile float32 volc_PMS_ChargPwr_ovrdval;
                /* Referenced by: '<S381>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile uint8 volc_PMS_ChargeLimitResponse_ovrdval;
                   /* Referenced by: '<S739>/volc_PMS_VacuumPressure_ovrdval' */
extern const volatile boolean volc_PMS_CruisingDstSwtFb_ovrdval;
                 /* Referenced by: '<S740>/volc_PMS_CruisingDstSwtFb_ovrdval' */
extern const volatile boolean volc_PMS_CurrentGearPositionValid_ovrdval;
         /* Referenced by: '<S639>/volc_PMS_CurrentGearPositionValid_ovrdval' */
extern const volatile float32 volc_PMS_DriverDemandTorque_ovrdval;
               /* Referenced by: '<S741>/volc_PMS_DriverDemandTorque_ovrdval' */
extern const volatile uint8 volc_PMS_DrivingTakeEleSts_ovrdval;
                /* Referenced by: '<S261>/volc_PMS_DrivingTakeEleSts_ovrdval' */
extern const volatile uint16 volc_PMS_DrvPfmncRedn_ovrdval;
                     /* Referenced by: '<S742>/volc_PMS_DrvPfmncRedn_ovrdval' */
extern const volatile boolean volc_PMS_EPBClosedReq_PMS_ovrdval;
                 /* Referenced by: '<S743>/volc_PMS_EPBClosedReq_PMS_ovrdval' */
extern const volatile boolean volc_PMS_Fn1GearRlyDrvStsFb_ovrdval;
                 /* Referenced by: '<S382>/volc_VCU_DriveCircuitTemp_ovrdval' */
extern const volatile boolean volc_PMS_Fn2GearRlyDrvStsFb_ovrdval;
                 /* Referenced by: '<S383>/volc_VCU_DriveCircuitTemp_ovrdval' */
extern const volatile boolean volc_PMS_FrntHeatModEnad_ovrdval;
                  /* Referenced by: '<S163>/volc_PMS_FrntHeatModEnad_ovrdval' */
extern const volatile float32 volc_PMS_FrntHeatPwrAllwd_ovrdval;
                 /* Referenced by: '<S164>/volc_PMS_FrntHeatPwrAllwd_ovrdval' */
extern const volatile boolean volc_PMS_GearIntervene_ovrdval;
                 /* Referenced by: '<S744>/volc_BMSH_ACChgTimeRemain_ovrdval' */
extern const volatile float32 volc_PMS_GrossComVehWeight_ovrdval;
                /* Referenced by: '<S745>/volc_PMS_GrossComVehWeight_ovrdval' */
extern const volatile boolean volc_PMS_HVIL1Sts_EV_ovrdval;
                      /* Referenced by: '<S165>/volc_PMS_HVIL1Sts_EV_ovrdval' */
extern const volatile boolean volc_PMS_HVIL1Sts_UB_ovrdval;
                      /* Referenced by: '<S166>/volc_PMS_HVIL1Sts_UB_ovrdval' */
extern const volatile boolean volc_PMS_HVIL2Sts_EV_ovrdval;
                      /* Referenced by: '<S167>/volc_PMS_HVIL2Sts_EV_ovrdval' */
extern const volatile boolean volc_PMS_HVIL2Sts_UB_ovrdval;
                      /* Referenced by: '<S168>/volc_PMS_HVIL2Sts_UB_ovrdval' */
extern const volatile boolean volc_PMS_HVILSts_EV_ovrdval;
                       /* Referenced by: '<S169>/volc_PMS_HVILSts_EV_ovrdval' */
extern const volatile float32 volc_PMS_HvCoolgPwrAllwd_ovrdval;
                  /* Referenced by: '<S403>/volc_PMS_HvCoolgPwrAllwd_ovrdval' */
extern const volatile float32 volc_PMS_HvHeatgPwrAllwd_ovrdval;
                  /* Referenced by: '<S404>/volc_PMS_HvHeatgPwrAllwd_ovrdval' */
extern const volatile float32 volc_PMS_IPKTotalOdometer_ovrdval;
                 /* Referenced by: '<S746>/volc_PMS_IPKTotalOdometer_ovrdval' */
extern const volatile uint8 volc_PMS_InventorySpdLmtRxSts_ovrdval;
             /* Referenced by: '<S747>/volc_PMS_InventorySpdLmtRxSts_ovrdval' */
extern const volatile uint8 volc_PMS_InventorySpdLmtSts_ovrdval;
               /* Referenced by: '<S748>/volc_PMS_InventorySpdLmtSts_ovrdval' */
extern const volatile uint8 volc_PMS_IsgActvDampgModReq_ovrdval;
               /* Referenced by: '<S487>/volc_PMS_IsgActvDampgModReq_ovrdval' */
extern const volatile uint8 volc_PMS_Life_ovrdval;
                             /* Referenced by: '<S749>/volc_PMS_Life_ovrdval' */
extern const volatile uint8 volc_PMS_LockVehExecutedSts_ovrdval;
                /* Referenced by: '<S384>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile uint8 volc_PMS_LockVehPerFlag_ovrdval;
                   /* Referenced by: '<S750>/volc_PMS_LockVehPerFlag_ovrdval' */
extern const volatile uint8 volc_PMS_LockVehPerRxSts_ovrdval;
                  /* Referenced by: '<S751>/volc_PMS_LockVehPerRxSts_ovrdval' */
extern const volatile float32 volc_PMS_MCUFlowFeedback_EV_ovrdval;
               /* Referenced by: '<S405>/volc_PMS_MCUFlowFeedback_EV_ovrdval' */
extern const volatile float32 volc_PMS_MaxPTTorqueAllowed_ovrdval;
               /* Referenced by: '<S752>/volc_PMS_MaxPTTorqueAllowed_ovrdval' */
extern const volatile float32 volc_PMS_MinPTTorqueAllowed_ovrdval;
               /* Referenced by: '<S753>/volc_PMS_MinPTTorqueAllowed_ovrdval' */
extern const volatile uint8 volc_PMS_OTAInstrucStsReminder_ovrdval;
            /* Referenced by: '<S754>/volc_PMS_OTAInstrucStsReminder_ovrdval' */
extern const volatile uint8 volc_PMS_OTAInstructRxnSts_ovrdval;
                /* Referenced by: '<S755>/volc_PMS_OTAInstructRxnSts_ovrdval' */
extern const volatile boolean volc_PMS_OdometerbackupEnable_ovrdval;
             /* Referenced by: '<S757>/volc_PMS_OdometerbackupEnable_ovrdval' */
extern const volatile float32 volc_PMS_Odometerbackup_ovrdval;
                   /* Referenced by: '<S756>/volc_PMS_Odometerbackup_ovrdval' */

/* Override value  */
extern const volatile uint8 volc_PMS_PTC1ConnStsFb_ovrdval;
                    /* Referenced by: '<S579>/volc_PMS_PTC1ConnStsFb_ovrdval' */
extern const volatile uint8 volc_PMS_PTC1RelayFlt_ovrdval;
                     /* Referenced by: '<S580>/volc_PMS_PTC1RelayFlt_ovrdval' */
extern const volatile uint8 volc_PMS_PTC3ConnStsFb_ovrdval;
                    /* Referenced by: '<S581>/volc_PMS_PTC3ConnStsFb_ovrdval' */
extern const volatile uint8 volc_PMS_PTC3RelayFlt_ovrdval;
                     /* Referenced by: '<S582>/volc_PMS_PTC3RelayFlt_ovrdval' */
extern const volatile uint8 volc_PMS_PTCRelayVoltSampSwich_ovrdval;
            /* Referenced by: '<S856>/volc_PMS_PTCRelayVoltSampSwich_ovrdval' */
extern const volatile uint8 volc_PMS_PowerOffCmdRxSts_ovrdval;
                 /* Referenced by: '<S758>/volc_PMS_PowerOffCmdRxSts_ovrdval' */
extern const volatile uint8 volc_PMS_PowerOffCmdSts_ovrdval;
                   /* Referenced by: '<S759>/volc_PMS_PowerOffCmdSts_ovrdval' */
extern const volatile uint8 volc_PMS_PreAccessoryConnStsFb_ovrdval;
            /* Referenced by: '<S583>/volc_PMS_PreAccessoryConnStsFb_ovrdval' */
extern const volatile uint8 volc_PMS_PreAccessoryRelayFlt_ovrdval;
             /* Referenced by: '<S584>/volc_PMS_PreAccessoryRelayFlt_ovrdval' */
extern const volatile boolean volc_PMS_Real_PedalPositionInvalid_ovrdval;
        /* Referenced by: '<S452>/volc_PMS_Real_PedalPositionInvalid_ovrdval' */
extern const volatile float32 volc_PMS_Real_PedalPosition_ovrdval;
               /* Referenced by: '<S451>/volc_PMS_Real_PedalPosition_ovrdval' */
extern const volatile float32 volc_PMS_RegenTarTrqPot_ovrdval;
                   /* Referenced by: '<S760>/volc_PMS_RegenTarTrqPot_ovrdval' */
extern const volatile float32 volc_PMS_RegenTrqAct_ovrdval;
                      /* Referenced by: '<S761>/volc_PMS_RegenTrqAct_ovrdval' */
extern const volatile float32 volc_PMS_RegenTrqPot_ovrdval;
                      /* Referenced by: '<S762>/volc_PMS_RegenTrqPot_ovrdval' */
extern const volatile uint8 volc_PMS_RegulationSpeed_ovrdval;
                 /* Referenced by: '<S385>/volc_VCU_DriveCircuitTemp_ovrdval' */
extern const volatile uint8 volc_PMS_RemChrgCmdFailrPrompt_ovrdval;
                /* Referenced by: '<S386>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile uint8 volc_PMS_SpdLmtLevelRxSts_ovrdval;
                 /* Referenced by: '<S764>/volc_PMS_SpdLmtLevelRxSts_ovrdval' */
extern const volatile uint8 volc_PMS_SpdLmtLevel_ovrdval;
                      /* Referenced by: '<S763>/volc_PMS_SpdLmtLevel_ovrdval' */
extern const volatile uint8 volc_PMS_StsBatLockSensor_ovrdval;
                 /* Referenced by: '<S170>/volc_PMS_StsBatLockSensor_ovrdval' */
extern const volatile boolean volc_PMS_TBOX_HVILState_ovrdval;
                   /* Referenced by: '<S765>/volc_PMS_TBOX_HVILState_ovrdval' */
extern const volatile uint8 volc_PMS_TBOX_LifeSts_ovrdval;
                     /* Referenced by: '<S766>/volc_PMS_TBOX_LifeSts_ovrdval' */
extern const volatile boolean volc_PMS_TakeEleSwtIndReq_ovrdval;
                 /* Referenced by: '<S387>/volc_VCU_DriveCircuitTemp_ovrdval' */
extern const volatile uint8 volc_PMS_ThermalReq_ovrdval;
                       /* Referenced by: '<S406>/volc_PMS_ThermalReq_ovrdval' */
extern const volatile uint8 volc_PMS_Torque_Ovrd_Active_ovrdval;
                 /* Referenced by: '<S388>/volc_VCU_DriveCircuitTemp_ovrdval' */
extern const volatile uint8 volc_PMS_Torque_Ovrd_Type_ovrdval;
                 /* Referenced by: '<S389>/volc_VCU_DriveCircuitTemp_ovrdval' */
extern const volatile uint8 volc_PMS_V2XDchaSwtFb1_ovrdval;
                 /* Referenced by: '<S767>/volc_BMSH_ACChgTimeRemain_ovrdval' */
extern const volatile uint8 volc_PMS_VINCode1_8_15_S_ovrdval;
                  /* Referenced by: '<S768>/volc_PMS_VINCode1_8_15_S_ovrdval' */
extern const volatile uint8 volc_PMS_VINCode2_9_16_S_ovrdval;
                  /* Referenced by: '<S769>/volc_PMS_VINCode2_9_16_S_ovrdval' */
extern const volatile uint8 volc_PMS_VINCode3_10_17_S_ovrdval;
                 /* Referenced by: '<S770>/volc_PMS_VINCode3_10_17_S_ovrdval' */
extern const volatile uint8 volc_PMS_VINCode4_11_S_ovrdval;
                    /* Referenced by: '<S771>/volc_PMS_VINCode4_11_S_ovrdval' */
extern const volatile uint8 volc_PMS_VINCode5_12_S_ovrdval;
                    /* Referenced by: '<S772>/volc_PMS_VINCode5_12_S_ovrdval' */
extern const volatile uint8 volc_PMS_VINCode6_13_S_ovrdval;
                    /* Referenced by: '<S773>/volc_PMS_VINCode6_13_S_ovrdval' */
extern const volatile uint8 volc_PMS_VINCode7_14_S_ovrdval;
                    /* Referenced by: '<S774>/volc_PMS_VINCode7_14_S_ovrdval' */
extern const volatile uint8 volc_PMS_VINMessageNum_S_ovrdval;
                  /* Referenced by: '<S775>/volc_PMS_VINMessageNum_S_ovrdval' */
extern const volatile float32 volc_PMS_VacuumPressure_ovrdval;
                   /* Referenced by: '<S776>/volc_PMS_VacuumPressure_ovrdval' */
extern const volatile float32 volc_PMS_VacuumPump_FB_ovrdval;
                    /* Referenced by: '<S777>/volc_PMS_VacuumPump_FB_ovrdval' */
extern const volatile uint8 volc_PMS_VacuumSystemsta_ovrdval;
                  /* Referenced by: '<S778>/volc_PMS_VacuumSystemsta_ovrdval' */
extern const volatile uint8 volc_PMS_VehicleSysErrorLevelG_ovrdval;
                /* Referenced by: '<S398>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile uint8 volc_PMS_VersionConversionFlag_ovrdval;
            /* Referenced by: '<S779>/volc_PMS_VersionConversionFlag_ovrdval' */
extern const volatile uint8 volc_PMS_VersionConversionRxSts_ovrdval;
           /* Referenced by: '<S780>/volc_PMS_VersionConversionRxSts_ovrdval' */
extern const volatile boolean volc_PMS_ePTFault_ovrdval;
                         /* Referenced by: '<S781>/volc_PMS_ePTFault_ovrdval' */
extern const volatile uint8 volc_TBOX_ChrgSoftSwCtrlst_ovrdval;
                /* Referenced by: '<S390>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile uint8 volc_TBOX_ReservationChrgnSts_ovrdval;
                /* Referenced by: '<S391>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile uint8 volc_VCU_12VATS1Enable_ovrdval;
                    /* Referenced by: '<S431>/volc_VCU_12VATS1Enable_ovrdval' */

/* Override value for signal VCU_12VATS1Enable */
extern const volatile float32 volc_VCU_12VATS1_PWMRequest_ovrdval;
               /* Referenced by: '<S432>/volc_VCU_12VATS1_PWMRequest_ovrdval' */

/* Override value for signal VCU_12VATS1_PWMRequest */
extern const volatile uint8 volc_VCU_12VDCDCCutOffLV_ovrdval;
                  /* Referenced by: '<S535>/volc_VCU_12VDCDCCutOffLV_ovrdval' */

/* Override value for signal VCU_12VDCDCCutOffLV */
extern const volatile uint8 volc_VCU_12VDCDCEnableOut_ovrdval;
                 /* Referenced by: '<S536>/volc_VCU_12VDCDCEnableOut_ovrdval' */

/* Override value for signal VCU_12VDCDCEnableOut */
extern const volatile uint8 volc_VCU_24V_Switch_ovrdval;/* Referenced by:
                                                         * '<S249>/volc_VCU_CabinLoopVal1_FBV6_ovrdval'
                                                         * '<S679>/volc_VCU_CabinLoopVal1_FBV6_ovrdval'
                                                         */

/* Override value for signal VCU_24V_Switch */
extern const volatile uint8 volc_VCU_ACActiveReq_ovrdval;
                      /* Referenced by: '<S453>/volc_VCU_ACActiveReq_ovrdval' */

/* Override value for signal VCU_ACActiveReq */
extern const volatile float32 volc_VCU_ACC1PosVol_ovrdval;
                       /* Referenced by: '<S564>/volc_VCU_ACC1PosVol_ovrdval' */

/* Override value for signal VCU_ACC1PosVol */
extern const volatile float32 volc_VCU_ACC2PosVol_ovrdval;
                       /* Referenced by: '<S565>/volc_VCU_ACC2PosVol_ovrdval' */

/* Override value for signal VCU_ACC2PosVol */
extern const volatile uint8 volc_VCU_ACCMEnable_ovrdval;
                       /* Referenced by: '<S408>/volc_VCU_ACCMEnable_ovrdval' */

/* Override value for signal ACCMEnable */
extern const volatile uint8 volc_VCU_ACCY1CtrlCmd_ovrdval;
                     /* Referenced by: '<S262>/volc_VCU_ACCY1CtrlCmd_ovrdval' */

/* Override value for signal VCU_ACCY1CtrlCmd */
extern const volatile boolean volc_VCU_ACCYEnableIn_ovrdval;
                     /* Referenced by: '<S263>/volc_VCU_ACCYEnableIn_ovrdval' */

/* Override value for signal VCU_ACCYEnableIn */
extern const volatile boolean volc_VCU_ACUCrashfz_Back_dftval;
                   /* Referenced by: '<S224>/volc_VCU_ACUCrashfz_Back_dftval' */
extern const volatile boolean volc_VCU_ACUCrashfz_Back_ovrdval;
                  /* Referenced by: '<S264>/volc_VCU_ACUCrashfz_Back_ovrdval' */

/* Override value for signal VCU_ACUCrashfz_Back */
extern const volatile float32 volc_VCU_AEC_ovrdval;
                              /* Referenced by: '<S527>/volc_VCU_AEC_ovrdval' */

/* Override value for signal VCU_AEC */
extern const volatile boolean volc_VCU_APUSWILED_Ctrl_dftval;
                    /* Referenced by: '<S224>/volc_VCU_APUSWILED_Ctrl_dftval' */
extern const volatile boolean volc_VCU_APUSWILED_Ctrl_ovrdval;
                   /* Referenced by: '<S265>/volc_VCU_APUSWILED_Ctrl_ovrdval' */

/* Override value for signal VCU_APUSWILED_Ctrl */
extern const volatile uint8 volc_VCU_ATS1Enable_ovrdval;
                       /* Referenced by: '<S433>/volc_VCU_ATS1Enable_ovrdval' */

/* Override value for signal VCU_ATS1Enable */
extern const volatile float32 volc_VCU_ATS1_PWMRequest_ovrdval;
                  /* Referenced by: '<S434>/volc_VCU_ATS1_PWMRequest_ovrdval' */

/* Override value for signal VCU_ATS1_PWMRequest */
extern const volatile uint8 volc_VCU_ATS2Enable_ovrdval;
                       /* Referenced by: '<S435>/volc_VCU_ATS2Enable_ovrdval' */

/* Override value for signal VCU_ATS2Enable */
extern const volatile float32 volc_VCU_ATS2_PWMRequest_ovrdval;
                  /* Referenced by: '<S436>/volc_VCU_ATS2_PWMRequest_ovrdval' */

/* Override value for signal VCU_ATS2_PWMRequest */
extern const volatile uint8 volc_VCU_ATS3Enable_ovrdval;
                       /* Referenced by: '<S437>/volc_VCU_ATS3Enable_ovrdval' */

/* Override value for signal VCU_ATS3Enable */
extern const volatile float32 volc_VCU_ATS3_PWMRequest_ovrdval;
                  /* Referenced by: '<S438>/volc_VCU_ATS3_PWMRequest_ovrdval' */

/* Override value for signal VCU_ATS3_PWMRequest */
extern const volatile uint8 volc_VCU_ATS4Enable_ovrdval;
                       /* Referenced by: '<S439>/volc_VCU_ATS4Enable_ovrdval' */

/* Override value for signal VCU_ATS4Enable */
extern const volatile float32 volc_VCU_ATS4_PWMRequest_ovrdval;
                  /* Referenced by: '<S440>/volc_VCU_ATS4_PWMRequest_ovrdval' */

/* Override value for signal VCU_ATS4_PWMRequest */
extern const volatile boolean volc_VCU_AWB_ovrdval;
                    /* Referenced by: '<S614>/volc_VCU_AccePedalPosE_ovrdval' */

/* Override value for signal VCU_AWB */
extern const volatile float32 volc_VCU_AccePedalPosD_ovrdval;
                    /* Referenced by: '<S626>/volc_VCU_AccePedalPosD_ovrdval' */

/* Override value for signal VCU_AccePedalPosD */
extern const volatile float32 volc_VCU_AccePedalPosE_ovrdval;
                    /* Referenced by: '<S627>/volc_VCU_AccePedalPosE_ovrdval' */

/* Override value for signal VCU_AccePedalPosE */
extern const volatile float32 volc_VCU_AcceleratorPedalPosition_ovrdval;
         /* Referenced by: '<S454>/volc_VCU_AcceleratorPedalPosition_ovrdval' */

/* Override value for signal VCU_AcceleratorPedalPosition */
extern const volatile boolean volc_VCU_AcceleratorPedal_flag_ovrdval;
            /* Referenced by: '<S455>/volc_VCU_AcceleratorPedal_flag_ovrdval' */

/* Override value for signal VCU_AcceleratorPedal_flag */
extern const volatile boolean volc_VCU_AccyAllowEnable_Ctrl_ovrdval;
             /* Referenced by: '<S266>/volc_VCU_AccyAllowEnable_Ctrl_ovrdval' */

/* Override value for signal VCU_AccyAllowEnable_Ctrl */
extern const volatile boolean volc_VCU_AccyPower_back_ovrdval;
                   /* Referenced by: '<S267>/volc_VCU_AccyPower_back_ovrdval' */

/* Override value for signal VCU_AccyPower_back */
extern const volatile uint8 volc_VCU_ActualGear_ovrdval;
                       /* Referenced by: '<S868>/volc_VCU_ActualGear_ovrdval' */

/* Override value for signal VCU_ActualGear */
extern const volatile uint8 volc_VCU_Address_ovrdval;
                    /* Referenced by: '<S615>/volc_VCU_AccePedalPosD_ovrdval' */

/* Override value for signal VCU_Address */
extern const volatile uint8 volc_VCU_AllowChg_ovrdval;
                         /* Referenced by: '<S537>/volc_VCU_AllowChg_ovrdval' */

/* Override value for signal VCU_AllowChg */
extern const volatile uint16 volc_VCU_AppSts_ovrdval;
                       /* Referenced by: '<S566>/volc_VCU_ACC2PosVol_ovrdval' */

/* Override value for signal VCU_AppSts */
extern const volatile float32 volc_VCU_AvgEVConsume_ovrdval;
                     /* Referenced by: '<S268>/volc_VCU_AvgEVConsume_ovrdval' */

/* Override value for signal VCU_AvgEVConsume */
extern const volatile float32 volc_VCU_AvgFuelVF_dftval;
                         /* Referenced by: '<S224>/volc_VCU_AvgFuelVF_dftval' */
extern const volatile float32 volc_VCU_AvgFuelVF_ovrdval;
                        /* Referenced by: '<S269>/volc_VCU_AvgFuelVF_ovrdval' */

/* Override value for signal VCU_AvgFuelVF */
extern const volatile uint8 volc_VCU_BMSHVOnOffReq_ovrdval;
                    /* Referenced by: '<S538>/volc_VCU_BMSHVOnOffReq_ovrdval' */

/* Override value for signal VCU_BMSHVOnOffReq */
extern const volatile float32 volc_VCU_BMSH_DCChgRelayVolt_ovrdval;
              /* Referenced by: '<S539>/volc_VCU_BMSH_DCChgRelayVolt_ovrdval' */
extern const volatile float32 volc_VCU_BMS_SOC_ovrdval;
                          /* Referenced by: '<S335>/volc_VCU_BMS_SOC_ovrdval' */

/* Override value for signal VCU_BMS_SOC */
extern const volatile float32 volc_VCU_BMS_voltage_ovrdval;
                      /* Referenced by: '<S336>/volc_VCU_BMS_voltage_ovrdval' */

/* Override value for signal VCU_BMS_voltage */
extern const volatile uint8 volc_VCU_BPTCCtrlCmd_ovrdval;
                      /* Referenced by: '<S561>/volc_VCU_BPTCCtrlCmd_ovrdval' */

/* Override value for signal VCU_BPTCCtrlCmd */
extern const volatile boolean volc_VCU_BPTCEnable_ovrdval;
                      /* Referenced by: '<S859>/volc_VCU_HVBC_Enable_ovrdval' */

/* Override value for signal VCU_BPTCEnable */
extern const volatile uint8 volc_VCU_BPTCPowerRatio_dftval;
                    /* Referenced by: '<S849>/volc_VCU_BPTCPowerRatio_dftval' */

/* Default value for signal VCU_BPTCPowerRatio */
extern const volatile uint8 volc_VCU_BPTCPowerRatio_ovrdval;
                  /* Referenced by: '<S860>/volc_VCU_HVBC_COpenValue_ovrdval' */

/* Override value for signal VCU_BPTCPowerRatio */
extern const volatile uint8 volc_VCU_BPTCTempSetting_ovrdval;
                  /* Referenced by: '<S861>/volc_VCU_HVBC_COpenValue_ovrdval' */

/* Override value for signal VCU_BPTCTempSetting */
extern const volatile uint16 volc_VCU_BattCoolVal3_FBV5_ovrdval;/* Referenced by:
                                                                 * '<S243>/volc_VCU_BattCoolVal3_FBV5_ovrdval'
                                                                 * '<S597>/volc_VCU_BattCoolVal3_FBV5_ovrdval'
                                                                 */

/* Override value for signal VCU_BattCoolVal3_FBV5 */
extern const volatile uint16 volc_VCU_BattCoolVal3_FBV6_ovrdval;/* Referenced by:
                                                                 * '<S243>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
                                                                 * '<S598>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
                                                                 */

/* Override value for signal VCU_BattCoolVal3_FBV6 */
extern const volatile uint16 volc_VCU_BattHeatVal2_FBV5_ovrdval;/* Referenced by:
                                                                 * '<S243>/volc_VCU_BattHeatVal2_FBV5_ovrdval'
                                                                 * '<S599>/volc_VCU_BattHeatVal2_FBV5_ovrdval'
                                                                 */

/* Override value for signal VCU_BattHeatVal2_FBV5 */
extern const volatile uint16 volc_VCU_BattHeatVal2_FBV6_ovrdval;/* Referenced by:
                                                                 * '<S243>/volc_VCU_BattHeatVal2_FBV6_ovrdval'
                                                                 * '<S600>/volc_VCU_BattHeatVal2_FBV6_ovrdval'
                                                                 */

/* Override value for signal VCU_BattHeatVal2_FBV6 */
extern const volatile float32 volc_VCU_BattMaxTemp_ovrdval;
                      /* Referenced by: '<S337>/volc_VCU_BattMaxTemp_ovrdval' */

/* Override value for signal VCU_BattMaxTemp */
extern const volatile float32 volc_VCU_BattMinTemp_ovrdval;
                      /* Referenced by: '<S338>/volc_VCU_BattMinTemp_ovrdval' */

/* Override value for signal VCU_BattMinTemp */
extern const volatile float32 volc_VCU_BattPackInCoolTemp_ovrdval;
               /* Referenced by: '<S409>/volc_VCU_BattPackInCoolTemp_ovrdval' */

/* Override value for signal VCU_BattPackInCoolTemp */
extern const volatile float32 volc_VCU_BattPackInCoolTempback_ovrdval;
           /* Referenced by: '<S270>/volc_VCU_BattPackInCoolTempback_ovrdval' */

/* Override value for signal VCU_BattPackInCoolTempback */
extern const volatile float32 volc_VCU_BattPackOutCoolTemp_ovrdval;
              /* Referenced by: '<S410>/volc_VCU_BattPackoutCoolTemp_ovrdval' */

/* Override value for signal VCU_BattPackOutCoolTemp */
extern const volatile float32 volc_VCU_BattPackoutCoolTempback_ovrdval;
          /* Referenced by: '<S271>/volc_VCU_BattPackoutCoolTempback_ovrdval' */

/* Override value for signal VCU_BattPackoutCoolTempback */
extern const volatile float32 volc_VCU_BattVol_ovrdval;
                          /* Referenced by: '<S339>/volc_VCU_BattVol_ovrdval' */

/* Override value for signal VCU_BattVol */
extern const volatile float32 volc_VCU_BatteryCoolentTemp_ovrdval;
               /* Referenced by: '<S411>/volc_VCU_BatteryCoolentTemp_ovrdval' */

/* Override value for signal VCU_BatteryCoolentTemp */
extern const volatile float32 volc_VCU_BatteryVol_ovrdval;
                       /* Referenced by: '<S567>/volc_VCU_ACC2PosVol_ovrdval' */

/* Override value for signal VCU_BatteryVol */
extern const volatile boolean volc_VCU_Batty_Charge_DisChargeState_ovrdval;
      /* Referenced by: '<S340>/volc_VCU_Batty_Charge_DisChargeState_ovrdval' */

/* Override value for signal VCU_Batty_Charge_DisChargeState */
extern const volatile boolean volc_VCU_Batty_ThermalMangeActive_dftval;
          /* Referenced by: '<S226>/volc_VCU_Batty_ThermalMangeActive_dftval' */

/* Default value for signal VCU_Batty_ThermalMangeActive */
extern const volatile boolean volc_VCU_Batty_ThermalMangeActive_ovrdval;
         /* Referenced by: '<S341>/volc_VCU_Batty_ThermalMangeActive_ovrdval' */

/* Override value for signal VCU_Batty_ThermalMangeActive */
extern const volatile uint8 volc_VCU_Batty_ThermalMangeReq_ovrdval;
            /* Referenced by: '<S412>/volc_VCU_Batty_ThermalMangeReq_ovrdval' */

/* Override value for signal VCU_Batty_ThermalMangeReq */
extern const volatile uint8 volc_VCU_Batty_ThermalMangeWorkMode_ovrdval;
       /* Referenced by: '<S342>/volc_VCU_Batty_ThermalMangeWorkMode_ovrdval' */

/* Override value for signal VCU_Batty_ThermalMangeWorkMode */
extern const volatile uint8 volc_VCU_BrakSwitchSts_ovrdval;
                    /* Referenced by: '<S456>/volc_VCU_BrakSwitchSts_ovrdval' */

/* Override value for signal VCU_BrakSwitchSts */
extern const volatile float32 volc_VCU_Brake1PosVol_ovrdval;
                     /* Referenced by: '<S592>/volc_VCU_Brake1PosVol_ovrdval' */

/* Override value for signal VCU_Brake1PosVol */
extern const volatile boolean volc_VCU_Brake1Sts_ovrdval;
                        /* Referenced by: '<S568>/volc_VCU_Brake1Sts_ovrdval' */

/* Override value for signal VCU_Brake1Sts */
extern const volatile float32 volc_VCU_Brake2PosVol_ovrdval;
                     /* Referenced by: '<S593>/volc_VCU_Brake2PosVol_ovrdval' */

/* Override value for signal VCU_Brake2PosVol */
extern const volatile boolean volc_VCU_Brake2Sts_ovrdval;
                        /* Referenced by: '<S569>/volc_VCU_Brake2Sts_ovrdval' */

/* Override value for signal VCU_Brake2Sts */
extern const volatile float32 volc_VCU_BrakePedalPosition_ovrdval;
               /* Referenced by: '<S457>/volc_VCU_BrakePedalPosition_ovrdval' */

/* Override value for signal VCU_BrakePedalPosition */
extern const volatile uint8 volc_VCU_BrkSysErr_ovrdval;
                        /* Referenced by: '<S640>/volc_VCU_BrkSysErr_ovrdval' */

/* Override value for signal VCU_BrkSysErr */
extern const volatile uint8 volc_VCU_CCFb_ovrdval;
                             /* Referenced by: '<S585>/volc_VCU_CCFb_ovrdval' */

/* Override value for signal VCU_CCFb */
extern const volatile float32 volc_VCU_CC_Acceleration_ovrdval;
                  /* Referenced by: '<S314>/volc_VCU_CC_Acceleration_ovrdval' */

/* Override value for signal VCU_CC_Acceleration */
extern const volatile boolean volc_VCU_Cab_ThermalMangeReq_ovrdval;/* Referenced by:
                                                                    * '<S226>/volc_VCU_Cab_ThermalMangeReq_ovrdval'
                                                                    * '<S343>/volc_VCU_Cab_ThermalMangeReq_ovrdval'
                                                                    */

/* Override value for signal VCU_Cab_ThermalMangeReq */
extern const volatile uint16 volc_VCU_CabinLoopVal1_FBV6_ovrdval;/* Referenced by:
                                                                  * '<S243>/volc_VCU_CabinLoopVal1_FBV6_ovrdval'
                                                                  * '<S601>/volc_VCU_CabinLoopVal1_FBV6_ovrdval'
                                                                  */

/* Override value for signal VCU_CabinLoopVal1_FBV6 */
extern const volatile uint16 volc_VCU_CabinLoopVal2_FBV5_ovrdval;/* Referenced by:
                                                                  * '<S243>/volc_VCU_CabinLoopVal2_FBV5_ovrdval'
                                                                  * '<S602>/volc_VCU_CabinLoopVal2_FBV5_ovrdval'
                                                                  */

/* Override value for signal VCU_CabinLoopVal2_FBV5 */
extern const volatile uint8 volc_VCU_Cabin_PumpFb_ovrdval;
                     /* Referenced by: '<S586>/volc_VCU_Cabin_PumpFb_ovrdval' */

/* Override value for signal VCU_Cabin_PumpFb */
extern const volatile uint8 volc_VCU_CalibrationMajorVer1;/* Referenced by: '<S159>/Constant5' */
extern const volatile uint8 volc_VCU_CalibrationMajorVer1_ovrdval;
                     /* Referenced by: '<S691>/volc_VCU_SWCompileDay_ovrdval' */
extern const volatile uint8 volc_VCU_CalibrationMajorVer2;/* Referenced by: '<S159>/Constant1' */
extern const volatile uint8 volc_VCU_CalibrationMajorVer2_ovrdval;
                     /* Referenced by: '<S692>/volc_VCU_SWCompileDay_ovrdval' */
extern const volatile uint8 volc_VCU_CalibrationMajorVer3;/* Referenced by: '<S159>/Constant2' */
extern const volatile uint8 volc_VCU_CalibrationMajorVer3_ovrdval;
                     /* Referenced by: '<S693>/volc_VCU_SWCompileDay_ovrdval' */
extern const volatile uint8 volc_VCU_CalibrationMinorVer1;/* Referenced by: '<S159>/Constant8' */
extern const volatile uint8 volc_VCU_CalibrationMinorVer1_ovrdval;
                     /* Referenced by: '<S694>/volc_VCU_SWCompileDay_ovrdval' */
extern const volatile uint8 volc_VCU_CalibrationMinorVer2;/* Referenced by: '<S159>/Constant3' */
extern const volatile uint8 volc_VCU_CalibrationMinorVer2_ovrdval;
                     /* Referenced by: '<S695>/volc_VCU_SWCompileDay_ovrdval' */
extern const volatile uint8 volc_VCU_CalibrationMinorVer3;/* Referenced by: '<S159>/Constant7' */
extern const volatile uint8 volc_VCU_CalibrationMinorVer3_ovrdval;
                     /* Referenced by: '<S696>/volc_VCU_SWCompileDay_ovrdval' */
extern const volatile float32 volc_VCU_Cell_Avg_Temp_ovrdval;
                    /* Referenced by: '<S344>/volc_VCU_Cell_Avg_Temp_ovrdval' */

/* Override value for signal VCU_Cell_Avg_Temp */
extern const volatile uint8 volc_VCU_ChargWakeupSts_ovrdval;
                   /* Referenced by: '<S587>/volc_VCU_ChargWakeupSts_ovrdval' */

/* Override value for signal VCU_ChargWakeupSts */
extern const volatile uint8 volc_VCU_ChargeDepthReq_ovrdval;
                /* Referenced by: '<S400>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile uint8 volc_VCU_Charger_Connected_ovrdval;
                /* Referenced by: '<S345>/volc_VCU_Charger_Connected_ovrdval' */

/* Override value for signal VCU_Charger_Connected */
extern const volatile uint8 volc_VCU_ControlSetSpeed_Mode_ovrdval;
             /* Referenced by: '<S476>/volc_VCU_ControlSetSpeed_Mode_ovrdval' */

/* Override value for signal VCU_ControlSetSpeed_Mode */
extern const volatile float32 volc_VCU_ControlSetSpeed_ovrdval;
                  /* Referenced by: '<S475>/volc_VCU_ControlSetSpeed_ovrdval' */

/* Override value for signal VCU_ControlSetSpeed */
extern const volatile uint8 volc_VCU_Cooling_Control_Request_dftval;
           /* Referenced by: '<S226>/volc_VCU_Cooling_Control_Request_dftval' */

/* Default value for signal VCU_Cooling_Control_Request */
extern const volatile uint8 volc_VCU_Cooling_Control_Request_ovrdval;
          /* Referenced by: '<S346>/volc_VCU_Cooling_Control_Request_ovrdval' */

/* Override value for signal VCU_Cooling_Control_Request */
extern const volatile uint8 volc_VCU_CrashOutputSts_ovrdval;
                   /* Referenced by: '<S782>/volc_VCU_CrashOutputSts_ovrdval' */
extern const volatile uint8 volc_VCU_CruiseControlSts_ovrdval;
                 /* Referenced by: '<S477>/volc_VCU_CruiseControlSts_ovrdval' */

/* Override value for signal VCU_CruiseControlSts */
extern const volatile uint8 volc_VCU_CruiseSwSts_ovrdval;
                      /* Referenced by: '<S478>/volc_VCU_CruiseSwSts_ovrdval' */

/* Override value for signal VCU_CruiseSwSts */
extern const volatile uint8 volc_VCU_CruiseSwerrorSts_ovrdval;
                 /* Referenced by: '<S479>/volc_VCU_CruiseSwerrorSts_ovrdval' */

/* Override value for signal VCU_CruiseSwerrorSts */
extern const volatile float32 volc_VCU_DCDCPwrLmt_ovrdval;
                       /* Referenced by: '<S540>/volc_VCU_DCDCPwrLmt_ovrdval' */

/* Override value for signal VCU_DCDCPwrLmt */
extern const volatile uint8 volc_VCU_DCDC_WorkSts_ovrdval;
                     /* Referenced by: '<S641>/volc_VCU_DCDC_WorkSts_ovrdval' */

/* Override value for signal VCU_DCDC_WorkSts */
extern const volatile float32 volc_VCU_DTE_ovrdval;
                              /* Referenced by: '<S528>/volc_VCU_DTE_ovrdval' */

/* Override value for signal VCU_DTE */
extern const volatile uint8 volc_VCU_DischargeEnable_ovrdval;
                /* Referenced by: '<S397>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile sint16 volc_VCU_DriveCircuitTemp_ovrdval;
                 /* Referenced by: '<S392>/volc_VCU_DriveCircuitTemp_ovrdval' */

/* Override value for signal VCU_DriveCircuitTemp */
extern const volatile uint16 volc_VCU_DriveCircuitVol_ovrdval;
                  /* Referenced by: '<S603>/volc_VCU_DriveCircuitVol_ovrdval' */

/* Override value for signal VCU_DriveCircuitVol */
extern const volatile uint8 volc_VCU_DriveModeInd_ovrdval;
                     /* Referenced by: '<S642>/volc_VCU_DriveModeInd_ovrdval' */

/* Override value for signal VCU_DriveModeInd */
extern const volatile uint8 volc_VCU_DrivePwrCircuitInd_ovrdval;
               /* Referenced by: '<S643>/volc_VCU_DrivePwrCircuitInd_ovrdval' */

/* Override value for signal VCU_DrivePwrCircuitInd */
extern const volatile float32 volc_VCU_DriveReqTrqPercent_ovrdval;
               /* Referenced by: '<S488>/volc_VCU_DriveReqTrqPercent_ovrdval' */

/* Override value for signal VCU_DriveReqTrqPercent */
extern const volatile uint8 volc_VCU_DriverOperationReminder_ovrdval;
          /* Referenced by: '<S458>/volc_VCU_DriverOperationReminder_ovrdval' */

/* Override value for signal VCU_DriverOperationReminder */
extern const volatile uint8 volc_VCU_DrivingTakeForceSts_dftval;
               /* Referenced by: '<S853>/volc_VCU_DrivingTakeForceSts_dftval' */

/* Default value for signal VCU_DrivingTakeForceSts */
extern const volatile uint8 volc_VCU_DrivingTakeForceSts_ovrdval;
              /* Referenced by: '<S871>/volc_VCU_DrivingTakeForceSts_ovrdval' */

/* Override value for signal VCU_DrivingTakeForceSts */
extern const volatile boolean volc_VCU_ECOMode_ovrdval;
                          /* Referenced by: '<S570>/volc_VCU_ECOMode_ovrdval' */

/* Override value for signal VCU_ECOMode */
extern const volatile boolean volc_VCU_ECOmodeSWILED_Ctrl_dftval;
                /* Referenced by: '<S224>/volc_VCU_ECOmodeSWILED_Ctrl_dftval' */
extern const volatile boolean volc_VCU_ECOmodeSWILED_Ctrl_ovrdval;
               /* Referenced by: '<S272>/volc_VCU_ECOmodeSWILED_Ctrl_ovrdval' */

/* Override value for signal VCU_ECOmodeSWILED_Ctrl */
extern const volatile float32 volc_VCU_ECPM_FaultFB_ovrdval;
                     /* Referenced by: '<S273>/volc_VCU_ECPM_FaultFB_ovrdval' */

/* Override value for signal VCU_ECPM_FaultFB */
extern const volatile boolean volc_VCU_EDCP_Enable_ovrdval;
                      /* Referenced by: '<S875>/volc_VCU_HVBC_Enable_ovrdval' */

/* Override value for signal VCU_EDCP_Enable */
extern const volatile float32 volc_VCU_EDCP_FaultFB_ovrdval;
                     /* Referenced by: '<S274>/volc_VCU_EDCP_FaultFB_ovrdval' */

/* Override value for signal VCU_EDCP_FaultFB */
extern const volatile float32 volc_VCU_EDCP_PWMCtrl_ovrdval;
                  /* Referenced by: '<S876>/volc_VCU_HVBC_COpenValue_ovrdval' */

/* Override value for signal VCU_EDCP_PWMCtrl */
extern const volatile uint8 volc_VCU_EM1CtrlMode_ovrdval;
                      /* Referenced by: '<S489>/volc_VCU_EM1CtrlMode_ovrdval' */
extern const volatile uint8 volc_VCU_EM1WorkMode_ovrdval;
                      /* Referenced by: '<S490>/volc_VCU_EM1WorkMode_ovrdval' */
extern const volatile uint8 volc_VCU_EMCtrlMode_ovrdval;
                       /* Referenced by: '<S491>/volc_VCU_EMCtrlMode_ovrdval' */

/* Override value for signal VCU_EMCtrlMode */
extern const volatile uint8 volc_VCU_EMWorkMode_ovrdval;
                       /* Referenced by: '<S492>/volc_VCU_EMWorkMode_ovrdval' */

/* Override value for signal VCU_EMWorkMode */
extern const volatile uint8 volc_VCU_EManualStartSwi_ovrdval;/* Referenced by:
                                                              * '<S241>/volc_VCU_EManualStartSwi_ovrdval'
                                                              * '<S588>/volc_VCU_EManualStartSwi_ovrdval'
                                                              */

/* Override value for signal VCU_EManualStartSwi */
extern const volatile float32 volc_VCU_EVDTEodometer_ovrdval;
                    /* Referenced by: '<S275>/volc_VCU_EVDTEodometer_ovrdval' */

/* Override value for signal VCU_EVDTEodometer */
extern const volatile uint8 volc_VCU_EV_Switch_ovrdval;
                /* Referenced by: '<S680>/volc_VCU_BattHeatVal2_FBV6_ovrdval' */

/* Override value for signal VCU_EV_Switch */
extern const volatile uint8 volc_VCU_EVanualStartSwi_dftval;
                   /* Referenced by: '<S248>/volc_VCU_EVanualStartSwi_dftval' */

/* Default value for signal VCU_EVanualStartSwi */
extern const volatile uint8 volc_VCU_EVanualStartSwi_ovrdval;
                  /* Referenced by: '<S644>/volc_VCU_EVanualStartSwi_ovrdval' */

/* Override value for signal VCU_EVanualStartSwi */
extern const volatile uint8 volc_VCU_EmergencyStop_ovrdval;
                    /* Referenced by: '<S594>/volc_VCU_EmergencyStop_ovrdval' */

/* Override value for signal VCU_EmergencyStop */
extern const volatile float32 volc_VCU_EngFuelInstCons_ovrdval;
                  /* Referenced by: '<S347>/volc_VCU_EngFuelInstCons_ovrdval' */

/* Override value for signal VCU_EngFuelInstCons */
extern const volatile float32 volc_VCU_ErrCode_ovrdval;
                          /* Referenced by: '<S529>/volc_VCU_ErrCode_ovrdval' */

/* Override value for signal VCU_ErrCode */
extern const volatile float32 volc_VCU_ExternalAccDemand_ovrdval;
                /* Referenced by: '<S315>/volc_VCU_ExternalAccDemand_ovrdval' */

/* Override value for signal VCU_ExternalAccDemand */
extern const volatile float32 volc_VCU_FanPWM_Ctrl_ovrdval;
                 /* Referenced by: '<S681>/volc_VCU_HTCoolingFanCtrl_ovrdval' */

/* Override value for signal VCU_FanPWM_Ctrl */
extern const volatile float32 volc_VCU_FuleDTEodometer_dftval;
                   /* Referenced by: '<S224>/volc_VCU_FuleDTEodometer_dftval' */
extern const volatile float32 volc_VCU_FuleDTEodometer_ovrdval;
                  /* Referenced by: '<S276>/volc_VCU_FuleDTEodometer_ovrdval' */

/* Override value for signal VCU_FuleDTEodometer */
extern const volatile uint8 volc_VCU_FunAnti_DismantleActive_ovrdval;
          /* Referenced by: '<S604>/volc_VCU_FunAnti_DismantleActive_ovrdval' */

/* Override value for signal VCU_FunAnti_DismantleActive */
extern const volatile uint8 volc_VCU_FunLockVehActive_ovrdval;
                 /* Referenced by: '<S605>/volc_VCU_FunLockVehActive_ovrdval' */

/* Override value for signal VCU_FunLockVehActive */
extern const volatile boolean volc_VCU_GP_Override_ovrdval;
                      /* Referenced by: '<S316>/volc_VCU_GP_Override_ovrdval' */

/* Override value for signal VCU_GP_Override */
extern const volatile uint8 volc_VCU_GearOperateErr_ovrdval;
                   /* Referenced by: '<S645>/volc_VCU_GearOperateErr_ovrdval' */

/* Override value for signal VCU_GearOperateErr */
extern const volatile uint8 volc_VCU_GearPositionInd_ovrdval;
                  /* Referenced by: '<S646>/volc_VCU_GearPositionInd_ovrdval' */

/* Override value for signal VCU_GearPositionInd */
extern const volatile float32 volc_VCU_GearPositionInput_ovrdval;
                /* Referenced by: '<S595>/volc_VCU_GearPositionInput_ovrdval' */

/* Override value for signal VCU_GearPositionInput */
extern const volatile uint8 volc_VCU_Gearshift_Resp_ovrdval;/* Referenced by:
                                                             * '<S853>/volc_VCU_Gearshift_Resp_ovrdval'
                                                             * '<S872>/volc_VCU_Gearshift_Resp_ovrdval'
                                                             */

/* Override value for signal VCU_Gearshift_Resp */
extern const volatile boolean volc_VCU_HBCP_Enable_ovrdval;
                       /* Referenced by: '<S877>/volc_VCU_ICE_Enable_ovrdval' */

/* Override value for signal VCU_HBCP_Enable */
extern const volatile float32 volc_VCU_HBCP_FaultFB_ovrdval;
                     /* Referenced by: '<S277>/volc_VCU_HBCP_FaultFB_ovrdval' */

/* Override value for signal VCU_HBCP_FaultFB */
extern const volatile float32 volc_VCU_HBCP_PWMCtrl_ovrdval;
                  /* Referenced by: '<S878>/volc_VCU_HVBC_BOpenValue_ovrdval' */

/* Override value for signal VCU_HBCP_PWMCtrl */
extern const volatile float32 volc_VCU_HTCoolingFan1FB_ovrdval;
                  /* Referenced by: '<S278>/volc_VCU_HTCoolingFan1FB_ovrdval' */

/* Override value for signal VCU_HTCoolingFan1FB */
extern const volatile uint8 volc_VCU_HVB_PumpFb_ovrdval;
                       /* Referenced by: '<S589>/volc_VCU_HVB_PumpFb_ovrdval' */

/* Override value for signal VCU_HVB_PumpFb */
extern const volatile float32 volc_VCU_HVILReturn_ovrdval;
                       /* Referenced by: '<S596>/volc_VCU_HVILReturn_ovrdval' */

/* Override value for signal VCU_HVILReturn */
extern const volatile boolean volc_VCU_HVOnOffReq_ovrdval;
                       /* Referenced by: '<S348>/volc_VCU_HVOnOffReq_ovrdval' */

/* Override value for signal VCU_HVOnOffReq */
extern const volatile uint16 volc_VCU_HVPRASts_ovrdval;
                       /* Referenced by: '<S571>/volc_VCU_ACC2PosVol_ovrdval' */

/* Override value for signal VCU_HVBVarCtrl */
extern const volatile uint8 volc_VCU_HV_Status_ovrdval;
                        /* Referenced by: '<S279>/volc_VCU_HV_Status_ovrdval' */

/* Override value for signal VCU_HV_Status */
extern const volatile uint8 volc_VCU_HandbrakeSts2_ovrdval;
                    /* Referenced by: '<S459>/volc_VCU_HandbrakeSts2_ovrdval' */

/* Override value for signal VCU_HandbrakeSts2 */
extern const volatile uint8 volc_VCU_HandbrakeSts_ovrdval;
                     /* Referenced by: '<S647>/volc_VCU_HandbrakeSts_ovrdval' */

/* Override value for signal VCU_HandbrakeSts */
extern const volatile uint8 volc_VCU_HardwareMajorVer_ovrdval;
                 /* Referenced by: '<S697>/volc_VCU_HardwareMajorVer_ovrdval' */

/* Override value for signal VCU_HardwareMajorVer */
extern const volatile uint8 volc_VCU_HardwareMinorVer_ovrdval;
                 /* Referenced by: '<S698>/volc_VCU_HardwareMinorVer_ovrdval' */

/* Override value for signal VCU_HardwareMinorVer */
extern const volatile uint8 volc_VCU_HybridReady_ovrdval;
                      /* Referenced by: '<S349>/volc_VCU_HybridReady_ovrdval' */

/* Override value for signal VCU_HybridReady */
extern const volatile uint8 volc_VCU_Idle_Switch_ovrdval;/* Referenced by:
                                                          * '<S249>/volc_VCU_BattCoolVal3_FBV5_ovrdval'
                                                          * '<S682>/volc_VCU_BattCoolVal3_FBV5_ovrdval'
                                                          */

/* Override value for signal VCU_Idle_Switch */
extern const volatile boolean volc_VCU_IgnONSts_ovrdval;
                         /* Referenced by: '<S572>/volc_VCU_IgnONSts_ovrdval' */

/* Override value for signal VCU_IgnONSts */
extern const volatile uint8 volc_VCU_IgniteSts_ovrdval;
                        /* Referenced by: '<S648>/volc_VCU_IgniteSts_ovrdval' */

/* Override value for signal VCU_IgniteSts */
extern const volatile uint8 volc_VCU_InhibitHybrid_Switch_ovrdval;/* Referenced by:
                                                                   * '<S249>/volc_VCU_BattHeatVal2_FBV5_ovrdval'
                                                                   * '<S683>/volc_VCU_BattHeatVal2_FBV5_ovrdval'
                                                                   */

/* Override value for signal VCU_InhibitHybrid_Switch */
extern const volatile uint8 volc_VCU_IntelLockLoopSts_dftval;
                  /* Referenced by: '<S238>/volc_VCU_IntelLockLoopSts_dftval' */

/* Default value for signal VCU_IntelLockLoopSts */
extern const volatile uint8 volc_VCU_IntelLockLoopSts_ovrdval;
                 /* Referenced by: '<S542>/volc_VCU_IntelLockLoopSts_ovrdval' */

/* Override value for signal VCU_IntelLockLoopSts */
extern const volatile uint8 volc_VCU_IntelligentChargeExitReq_ovrdval;
         /* Referenced by: '<S280>/volc_VCU_IntelligentChargeExitReq_ovrdval' */

/* Override value for signal VCU_IntelligentChargeExitReq */
extern const volatile uint8 volc_VCU_IntelligentChargeQuit_ovrdval;
            /* Referenced by: '<S281>/volc_VCU_IntelligentChargeQuit_ovrdval' */

/* Override value for signal VCU_IntelligentChargeQuit */
extern const volatile uint8 volc_VCU_IntelligentChargeState_ovrdval;
           /* Referenced by: '<S282>/volc_VCU_IntelligentChargeState_ovrdval' */

/* Override value for signal VCU_IntelligentChargeState */
extern const volatile uint8 volc_VCU_LTCoolingFan2FB_ovrdval;
                  /* Referenced by: '<S283>/volc_VCU_LTCoolingFan2FB_ovrdval' */

/* Override value for signal VCU_LTCoolingFan2FB */
extern const volatile uint8 volc_VCU_LockLimResult_ovrdval;
                    /* Referenced by: '<S606>/volc_VCU_LockLimResult_ovrdval' */

/* Override value for signal VCU_LockLimResult */
extern const volatile uint8 volc_VCU_LockVehSts_ovrdval;
                       /* Referenced by: '<S607>/volc_VCU_LockVehSts_ovrdval' */

/* Override value for signal VCU_LockVehSts */
extern const volatile uint8 volc_VCU_LockVehType_ovrdval;
                      /* Referenced by: '<S608>/volc_VCU_LockVehType_ovrdval' */

/* Override value for signal VCU_LockVehType */
extern const volatile uint8 volc_VCU_MCU1EnableReq_ovrdval;
                    /* Referenced by: '<S493>/volc_VCU_MCU1EnableReq_ovrdval' */
extern const volatile uint8 volc_VCU_MCUActiveDischg_ovrdval;
                  /* Referenced by: '<S350>/volc_VCU_MCUActiveDischg_ovrdval' */

/* Override value for signal VCU_MCUActiveDischg */
extern const volatile uint8 volc_VCU_MCUEnableReq_ovrdval;
                     /* Referenced by: '<S494>/volc_VCU_MCUEnableReq_ovrdval' */

/* Override value for signal VCU_MCUEnableReq */
extern const volatile uint16 volc_VCU_MCUMaxTrq_ovrdval;
                        /* Referenced by: '<S495>/volc_VCU_MCUMaxTrq_ovrdval' */

/* Override value for signal VCU_MCUMaxTrq */
extern const volatile float32 volc_VCU_MCUSpdRampRate_dftval;
                    /* Referenced by: '<S236>/volc_VCU_MCUSpdRampRate_dftval' */

/* Default value for signal VCU_MCUSpdRampRate */
extern const volatile float32 volc_VCU_MCUSpdRampRate_ovrdval;
                   /* Referenced by: '<S496>/volc_VCU_MCUSpdRampRate_ovrdval' */

/* Override value for signal VCU_MCUSpdRampRate */
extern const volatile float32 volc_VCU_MCUTqRampRate_dftval;
                     /* Referenced by: '<S236>/volc_VCU_MCUTqRampRate_dftval' */

/* Default value for signal VCU_MCUTqRampRate */
extern const volatile float32 volc_VCU_MCUTqRampRate_ovrdval;
                    /* Referenced by: '<S497>/volc_VCU_MCUTqRampRate_ovrdval' */

/* Override value for signal VCU_MCUTqRampRate */
extern const volatile float32 volc_VCU_MCU_MotorActTrqPercent_ovrdval;
           /* Referenced by: '<S498>/volc_VCU_MCU_MotorActTrqPercent_ovrdval' */

/* Override value for signal VCU_MCU_MotorActTrqPercent */
extern const volatile float32 volc_VCU_MCU_PumpPWM_Ctrl_ovrdval;
               /* Referenced by: '<S684>/volc_VCU_CabinLoopVal2_FBV5_ovrdval' */

/* Override value for signal VCU_MCU_PumpPWM_Ctrl */
extern const volatile uint8 volc_VCU_MCU_RelayCtrl_Ctrl_ovrdval;
                 /* Referenced by: '<S685>/volc_VCU_HTCoolingFanCtrl_ovrdval' */

/* Override value for signal VCU_MCU_RelayCtrl_Ctrl */
extern const volatile uint8 volc_VCU_MILTelltale_dftval;
                       /* Referenced by: '<S246>/volc_VCU_MILTelltale_dftval' */

/* Default value for signal VCU_MILTelltale */
extern const volatile uint8 volc_VCU_MILTelltale_ovrdval;
                      /* Referenced by: '<S628>/volc_VCU_MILTelltale_ovrdval' */

/* Override value for signal VCU_MILTelltale */
extern const volatile uint8 volc_VCU_MainPosCtrlCommand_ovrdval;
               /* Referenced by: '<S543>/volc_VCU_MainPosCtrlCommand_ovrdval' */

/* Override value for signal VCU_MainPosCtrlCommand */
extern const volatile uint8 volc_VCU_Main_Contactor_Control_ovrdval;
           /* Referenced by: '<S351>/volc_VCU_Main_Contactor_Control_ovrdval' */

/* Override value for signal VCU_Main_Contactor_Control */
extern const volatile float32 volc_VCU_MaxEMPwrLmt_ovrdval;
                      /* Referenced by: '<S499>/volc_VCU_MaxEMPwrLmt_ovrdval' */

/* Override value for signal VCU_MaxEMPwrLmt */
extern const volatile float32 volc_VCU_MinEMPwrLmt_ovrdval;
                      /* Referenced by: '<S500>/volc_VCU_MinEMPwrLmt_ovrdval' */

/* Override value for signal VCU_MinEMPwrLmt */
extern const volatile float32 volc_VCU_MotorSpeed_ovrdval;
                       /* Referenced by: '<S501>/volc_VCU_MotorSpeed_ovrdval' */

/* Override value for signal VCU_MotorSpeed */
extern const volatile float32 volc_VCU_MotorTorque_ovrdval;
                      /* Referenced by: '<S502>/volc_VCU_MotorTorque_ovrdval' */

/* Override value for signal VCU_MotorTorque */
extern const volatile boolean volc_VCU_NMSts_ovrdval;
                  /* Referenced by: '<S616>/volc_VCU_DTCClearInhibit_ovrdval' */

/* Override value for signal VCU_NMSts */
extern const volatile uint8 volc_VCU_Oil_HV_OFF_ovrdval;
                  /* Referenced by: '<S870>/volc_VCU_HVBC_COpenValue_ovrdval' */

/* Override value for signal VCU_Oil_HV_OFF */
extern const volatile float32 volc_VCU_PMS_APPowerActual_EV_ovrdval;
             /* Referenced by: '<S413>/volc_VCU_PMS_APPowerActual_EV_ovrdval' */
extern const volatile boolean volc_VCU_PTC2Enable_ovrdval;
                /* Referenced by: '<S394>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile boolean volc_VCU_PTC3Enable_ovrdval;
                /* Referenced by: '<S395>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile uint8 volc_VCU_PTCEnable_ovrdval;
                        /* Referenced by: '<S414>/volc_VCU_PTCEnable_ovrdval' */

/* Override value for signal PTCEnable */
extern const volatile uint8 volc_VCU_PTHVSysErrorLampStsInd_ovrdval;/* Referenced by:
                                                                     * '<S248>/volc_VCU_PTHVSysErrorLampStsInd_ovrdval'
                                                                     * '<S649>/volc_VCU_PTHVSysErrorLampStsInd_ovrdval'
                                                                     */

/* Override value for signal VCU_PTHVSysErrorLampStsInd */
extern const volatile uint8 volc_VCU_PTModeInd_ovrdval;
                        /* Referenced by: '<S650>/volc_VCU_PTModeInd_ovrdval' */

/* Override value for signal VCU_PTModeInd */
extern const volatile uint8 volc_VCU_PTReadyInd_ovrdval;
                       /* Referenced by: '<S651>/volc_VCU_PTReadyInd_ovrdval' */

/* Override value for signal VCU_PTReadyInd */
extern const volatile float32 volc_VCU_PTResiPwr_ovrdval;
                        /* Referenced by: '<S530>/volc_VCU_PTResiPwr_ovrdval' */

/* Override value for signal VCU_PTResiPwr */
extern const volatile float32 volc_VCU_PTSysElecPwrInd_ovrdval;/* Referenced by:
                                                                * '<S248>/volc_VCU_PTSysElecPwrInd_ovrdval'
                                                                * '<S652>/volc_VCU_PTSysElecPwrInd_ovrdval'
                                                                */

/* Override value for signal VCU_PTSysElecPwrInd */
extern const volatile uint8 volc_VCU_PreRelay_Ctrl_ovrdval;/* Referenced by:
                                                            * '<S249>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
                                                            * '<S686>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
                                                            */

/* Override value for signal VCU_PreRelay_Ctrl */
extern const volatile uint8 volc_VCU_PressureSwi1Sts_ovrdval;
                  /* Referenced by: '<S590>/volc_VCU_PressureSwi1Sts_ovrdval' */

/* Override value for signal VCU_PressureSwi1Sts */
extern const volatile uint8 volc_VCU_PressureSwi2Sts_ovrdval;
                  /* Referenced by: '<S591>/volc_VCU_PressureSwi2Sts_ovrdval' */

/* Override value for signal VCU_PressureSwi2Sts */
extern const volatile boolean volc_VCU_PropulSysActive_dftval;
                   /* Referenced by: '<S224>/volc_VCU_PropulSysActive_dftval' */
extern const volatile boolean volc_VCU_PropulSysActive_ovrdval;
                  /* Referenced by: '<S284>/volc_VCU_PropulSysActive_ovrdval' */

/* Override value for signal VCU_PropulSysActive */
extern const volatile float32 volc_VCU_QuitControlSpeed_ovrdval;
                 /* Referenced by: '<S480>/volc_VCU_QuitControlSpeed_ovrdval' */

/* Override value for signal VCU_QuitControlSpeed */
extern const volatile boolean volc_VCU_RMR_ovrdval;
                    /* Referenced by: '<S617>/volc_VCU_AccePedalPosD_ovrdval' */

/* Override value for signal VCU_RMR */
extern const volatile uint8 volc_VCU_RelayCtrl_Ctrl_ovrdval;
                 /* Referenced by: '<S687>/volc_VCU_HTCoolingFanCtrl_ovrdval' */

/* Override value for signal VCU_RelayCtrl_Ctrl */
extern const volatile float32 volc_VCU_ReqSpdOrLmt_ovrdval;/* Referenced by:
                                                            * '<S236>/volc_VCU_ReqSpdOrLmt_ovrdval'
                                                            * '<S503>/volc_VCU_ReqSpdOrLmt_ovrdval'
                                                            */

/* Override value for signal VCU_ReqSpdOrLmt */
extern const volatile float32 volc_VCU_ReqTrqOrLmt_ovrdval;
                      /* Referenced by: '<S504>/volc_VCU_ReqTrqOrLmt_ovrdval' */

/* Override value for signal VCU_ReqTrqOrLmt */
extern const volatile float32 volc_VCU_SDCACOutFreq_ovrdval;
                     /* Referenced by: '<S544>/volc_VCU_SDCACOutFreq_ovrdval' */

/* Override value for signal VCU_SDCACOutFreq */
extern const volatile uint8 volc_VCU_SWCompileDay_ovrdval;
                     /* Referenced by: '<S699>/volc_VCU_SWCompileDay_ovrdval' */

/* Override value for signal VCU_SWCompileDay */
extern const volatile uint8 volc_VCU_SWCompileMonth_ovrdval;
                   /* Referenced by: '<S700>/volc_VCU_SWCompileMonth_ovrdval' */

/* Override value for signal VCU_SWCompileMonth */
extern const volatile float32 volc_VCU_SWCompileYear_ovrdval;
                    /* Referenced by: '<S701>/volc_VCU_SWCompileYear_ovrdval' */

/* Override value for signal VCU_SWCompileYear */
extern const volatile uint8 volc_VCU_SelfCheckSts_ovrdval;
                     /* Referenced by: '<S546>/volc_VCU_SelfCheckSts_ovrdval' */

/* Override value for signal VCU_SelfCheckSts */
extern const volatile float32 volc_VCU_Set_Temp_ovrdval;
                         /* Referenced by: '<S352>/volc_VCU_Set_Temp_ovrdval' */

/* Override value for signal VCU_Set_Temp */
extern const volatile boolean volc_VCU_ShiftClimbing;
                            /* Referenced by: '<S240>/volc_VCU_ShiftClimbing' */

/* Default value for signal VCU_ShiftClimbing */
extern const volatile boolean volc_VCU_ShiftClimbing_ovrdval;
                          /* Referenced by: '<S573>/volc_VCU_ECOMode_ovrdval' */

/* Override value for signal VCU_ShiftClimbing */
extern const volatile boolean volc_VCU_ShiftD;
                                   /* Referenced by: '<S240>/volc_VCU_ShiftD' */

/* Default value for signal VCU_ShiftD */
extern const volatile boolean volc_VCU_ShiftD_ovrdval;
                         /* Referenced by: '<S574>/volc_VCU_StartSts_ovrdval' */

/* Override value for signal VCU_ShiftD */
extern const volatile boolean volc_VCU_ShiftR;
                                   /* Referenced by: '<S240>/volc_VCU_ShiftR' */

/* Default value for signal VCU_ShiftR */
extern const volatile boolean volc_VCU_ShiftR_ovrdval;
                         /* Referenced by: '<S575>/volc_VCU_StartSts_ovrdval' */

/* Override value for signal VCU_ShiftR */
extern const volatile uint8 volc_VCU_SoftwareMajorVer_ovrdval;
                 /* Referenced by: '<S702>/volc_VCU_SoftwareMajorVer_ovrdval' */

/* Override value for signal VCU_SoftwareMajorVer */
extern const volatile uint8 volc_VCU_SoftwareMinorVer_ovrdval;
                 /* Referenced by: '<S703>/volc_VCU_SoftwareMinorVer_ovrdval' */

/* Override value for signal VCU_SoftwareMinorVer */
extern const volatile boolean volc_VCU_StartSts_ovrdval;
                         /* Referenced by: '<S576>/volc_VCU_StartSts_ovrdval' */

/* Override value for signal VCU_StartSts */
extern const volatile uint32 volc_VCU_Stayawake_reasons_ovrdval;
                    /* Referenced by: '<S618>/volc_VCU_AccePedalPosE_ovrdval' */

/* Override value for signal VCU_Stayawake_reasons */
extern const volatile boolean volc_VCU_StsBrkSwitch1Invalid_ovrdval;
             /* Referenced by: '<S460>/volc_VCU_StsBrkSwitch1Invalid_ovrdval' */
extern const volatile boolean volc_VCU_TotalOdometerInvalid_ovrdval;
             /* Referenced by: '<S630>/volc_VCU_TotalOdometerInvalid_ovrdval' */

/* Override value for signal VCU_TotalOdometerInvalid */
extern const volatile float32 volc_VCU_TotalOdometer_ovrdval;
                    /* Referenced by: '<S629>/volc_VCU_TotalOdometer_ovrdval' */

/* Override value for signal VCU_TotalOdometer */
extern const volatile uint8 volc_VCU_TurtleLampReq_ovrdval;
                    /* Referenced by: '<S653>/volc_VCU_TurtleLampReq_ovrdval' */

/* Override value for signal VCU_TurtleLampReq */
extern const volatile boolean volc_VCU_VLC_Active_ovrdval;
                       /* Referenced by: '<S317>/volc_VCU_VLC_Active_ovrdval' */

/* Override value for signal VCU_VLC_Active */
extern const volatile boolean volc_VCU_VLC_Available_ovrdval;/* Referenced by:
                                                              * '<S225>/volc_VCU_VLC_Available_ovrdval'
                                                              * '<S318>/volc_VCU_VLC_Available_ovrdval'
                                                              */

/* Override value for signal VCU_VLC_Available */
extern const volatile float32 volc_VCU_VLC_InternalTargetACCeleration_ovrdval;
   /* Referenced by: '<S319>/volc_VCU_VLC_InternalTargetACCeleration_ovrdval' */

/* Override value for signal VCU_VLC_InternalTargetACCeleration */
extern const volatile float32 volc_VCU_VLC_VCUTargetACCeleration_ovrdval;
        /* Referenced by: '<S320>/volc_VCU_VLC_VCUTargetACCeleration_ovrdval' */

/* Override value for signal VCU_VLC_VCUTargetACCeleration */
extern const volatile float32 volc_VCU_VehCruisingDistance_ovrdval;
                /* Referenced by: '<S688>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */

/* Override value for signal VCU_VehCruisingDistance */
extern const volatile uint8 volc_VCU_VehicleAbnormalSts_ovrdval;/* Referenced by:
                                                                 * '<S248>/volc_VCU_VehicleAbnormalSts_ovrdval'
                                                                 * '<S654>/volc_VCU_VehicleAbnormalSts_ovrdval'
                                                                 */

/* Override value for signal VCU_VehicleAbnormalSts */
extern const volatile float32 volc_VCU_VehicleIdentification_ovrdval;
            /* Referenced by: '<S689>/volc_VCU_VehicleIdentification_ovrdval' */

/* Override value for signal VCU_VehicleIdentification */
extern const volatile uint8 volc_VCU_VehicleRunMode_ovrdval;
                   /* Referenced by: '<S655>/volc_VCU_VehicleRunMode_ovrdval' */

/* Override value for signal VCU_VehicleRunMode */
extern const volatile uint8 volc_VCU_VehicleSlipWarning_ovrdval;/* Referenced by:
                                                                 * '<S248>/volc_VCU_VehicleSlipWarning'
                                                                 * '<S656>/volc_VCU_VehicleSlipWarning'
                                                                 */

/* Override value for signal VCU_VehicleSlipWarning */
extern const volatile boolean volc_VCU_VehicleSpd_flag_ovrdval;
                  /* Referenced by: '<S462>/volc_VCU_VehicleSpd_flag_ovrdval' */

/* Override value for signal VCU_VehicleSpd_flag */
extern const volatile float32 volc_VCU_VehicleSpd_ovrdval;
                       /* Referenced by: '<S461>/volc_VCU_VehicleSpd_ovrdval' */

/* Override value for signal VCU_VehicleSpd */
extern const volatile uint8 volc_VCU_VehicleSubSysErrorLevel_dftval;
           /* Referenced by: '<S248>/volc_VCU_VehicleSubSysErrorLevel_dftval' */

/* Default value for signal VCU_VehicleSubSysErrorLevel */
extern const volatile uint8 volc_VCU_VehicleSubSysErrorLevel_ovrdval;
          /* Referenced by: '<S657>/volc_VCU_VehicleSubSysErrorLevel_ovrdval' */

/* Override value for signal VCU_VehicleSubSysErrorLevel */
extern const volatile uint8 volc_VCU_VehicleSysErrorLevel_ovrdval;
             /* Referenced by: '<S658>/volc_VCU_VehicleSysErrorLevel_ovrdval' */

/* Override value for signal VCU_VehicleSysErrorLevel */
extern const volatile uint8 volc_VCU_VehicleSysFltLevel_ovrdval;
               /* Referenced by: '<S636>/volc_VCU_VehicleSysFltLevel_ovrdval' */

/* Override value for signal VCU_VehicleSysFltLevel */
extern const volatile uint8 volc_VCU_WPCtrl_ovrdval;
                           /* Referenced by: '<S415>/volc_VCU_WPCtrl_ovrdval' */

/* Override value for signal WPCtrl */
extern const volatile uint8 volc_VCU_Wakeup_reasons_ovrdval;
                  /* Referenced by: '<S619>/volc_VCU_DTCClearInhibit_ovrdval' */

/* Override value for signal VCU_Wakeup_reasons */
extern const volatile uint8 volc_VCU_XBRControlMode_ovrdval;
                   /* Referenced by: '<S321>/volc_VCU_XBRControlMode_ovrdval' */

/* Override value for signal VCU_XBRControlMode */
extern const volatile uint8 volc_VCU_XBREBIMode_ovrdval;
                       /* Referenced by: '<S322>/volc_VCU_XBREBIMode_ovrdval' */

/* Override value for signal VCU_XBREBIMode */
extern const volatile uint8 volc_VCU_XBRPriority_dftval;
                       /* Referenced by: '<S225>/volc_VCU_XBRPriority_dftval' */

/* Default value for signal VCU_XBRPriority */
extern const volatile uint8 volc_VCU_XBRPriority_ovrdval;
                      /* Referenced by: '<S323>/volc_VCU_XBRPriority_ovrdval' */

/* Override value for signal VCU_XBRPriority */
extern const volatile boolean volc_VCU_ZeroPwr_Fb_ovrdval;
                /* Referenced by: '<S396>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile float32 volc_VCU_bmshAlwChgCurrMax_ovrdval;
                /* Referenced by: '<S399>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile uint8 volc_VCU_ePTRegencyLevInd_ovrdval;
                /* Referenced by: '<S717>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
extern const volatile uint8 volc_VCU_ePTReleaseSig_ovrdval;
                    /* Referenced by: '<S285>/volc_VCU_ePTReleaseSig_ovrdval' */

/* Override value for signal VCU_ePTReleaseSig */
extern const volatile float32 volc_acc_vehAccXBRDisa_mps2;/* Referenced by: '<S225>/Relay4' */

/* Deceleration threshold to disable XBR control */
extern const volatile float32 volc_acc_vehAccXBREna_mps2;/* Referenced by: '<S225>/Relay4' */

/* Deceleration threshold to enable XBR control */
extern const volatile boolean volc_b_12VbatRlyReq_invert;
                       /* Referenced by: '<S181>/vilc_b_ResrAirSwitch_invert' */

/* Invert flag for signal 12VbatRlyReq */
extern const volatile boolean volc_b_12VbatRlyReq_ovrdflg;
                       /* Referenced by: '<S181>/volc_b_WatPmpEP3PWM_ovrdflg' */

/* Override flag for signal 12VbatRlyReq */
extern const volatile boolean volc_b_12vDCDCEn_invert;
                           /* Referenced by: '<S182>/volc_b_12vDCDCEn_invert' */

/* Invert flag for signal b_12vDCDCEn */
extern const volatile boolean volc_b_12vDCDCEn_ovrdflg;
                          /* Referenced by: '<S182>/volc_b_12vDCDCEn_ovrdflg' */

/* Override flag for signal b_12vDCDCEn */
extern const volatile boolean volc_b_24vDCDCEn_invert;
                           /* Referenced by: '<S183>/volc_b_24vDCDCEn_invert' */

/* Invert flag for signal b_24vDCDCEn */
extern const volatile boolean volc_b_24vDCDCEn_ovrdflg;
                          /* Referenced by: '<S183>/volc_b_24vDCDCEn_ovrdflg' */

/* Override flag for signal b_24vDCDCEn */
extern const volatile boolean volc_b_AC_EWP_Heat_ovrdflg;
              /* Referenced by: '<S374>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_AC_EWP_HeatrPwrCnsAllwd_ovrdflg;
              /* Referenced by: '<S375>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_AC_EWP_Run_ovrdflg;
              /* Referenced by: '<S376>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_AC_EWP_SpeedReq_ovrdflg;
              /* Referenced by: '<S377>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_AC_EWP_Temp_ovrdflg;
              /* Referenced by: '<S378>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_AccPedal_1_ovrdflg;
                     /* Referenced by: '<S205>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */

/* Override flag for signal pct_AccPedal_1 */
extern const volatile boolean volc_b_AccPedal_2_ovrdflg;
                     /* Referenced by: '<S206>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */

/* Override flag for signal pct_AccPedal_2 */
extern const volatile boolean volc_b_BMSH_ACChgTimeRemain_ovrdflg;
             /* Referenced by: '<S718>/volc_flg_BMSH_ACChgTimeRemain_ovrdflg' */
extern const volatile boolean volc_b_BMSH_BattCurr_ovrdflg;
                    /* Referenced by: '<S719>/volc_flg_BMSH_BattCurr_ovrdflg' */
extern const volatile boolean volc_b_BMSH_BattFaultLampState_ovrdflg;
          /* Referenced by: '<S720>/volc_flg_BMSH_BattFaultLampState_ovrdflg' */
extern const volatile boolean volc_b_BMSH_CCM_ThermalManageReq_ovrdflg;
        /* Referenced by: '<S721>/volc_flg_BMSH_CCM_ThermalManageReq_ovrdflg' */
extern const volatile boolean volc_b_BMSH_Cell_TotalNum_ovrdflg;
               /* Referenced by: '<S722>/volc_flg_BMSH_Cell_TotalNum_ovrdflg' */
extern const volatile boolean volc_b_BMSH_ChargeLEDCtrl_ovrdflg;
               /* Referenced by: '<S723>/volc_flg_BMSH_ChargeLEDCtrl_ovrdflg' */
extern const volatile boolean volc_b_BMSH_Charge_Over_Current_ovrdflg;
         /* Referenced by: '<S724>/volc_flg_BMSH_Charge_Over_Current_ovrdflg' */
extern const volatile boolean volc_b_BMSH_ChgTimeRemain_ovrdflg;
               /* Referenced by: '<S725>/volc_flg_BMSH_ChgTimeRemain_ovrdflg' */
extern const volatile boolean
  volc_b_BMSH_DCChgminusSocketTempSensing_Failure_ovrdflg;
/* Referenced by: '<S726>/volc_flg_BMSH_DCChgminusSocketTempSensing_Failure_ovrdflg' */
extern const volatile boolean
  volc_b_BMSH_DCChgplusSocketTempSensing_Failure_ovrdflg;
/* Referenced by: '<S727>/volc_flg_BMSH_DCChgplusSocketTempSensing_Failure_ovrdflg' */
extern const volatile boolean volc_b_BMSH_FastChgCC2ConntState_ovrdflg;
        /* Referenced by: '<S728>/volc_flg_BMSH_FastChgCC2ConntState_ovrdflg' */
extern const volatile boolean volc_b_BMSH_HvBattThermMod_ovrdflg;
                     /* Referenced by: '<S407>/volc_b_PMS_ThermalReq_ovrdflg' */
extern const volatile boolean volc_b_BMSH_InsulationRes_Fault_ovrdflg;
         /* Referenced by: '<S729>/volc_flg_BMSH_InsulationRes_Fault_ovrdflg' */
extern const volatile boolean volc_b_BMSH_ThermalOutofControl_ovrdflg;
         /* Referenced by: '<S730>/volc_flg_BMSH_ThermalOutofControl_ovrdflg' */
extern const volatile boolean volc_b_BMSH_Vehicle_HVILSts_PHEV_ovrdflg;
        /* Referenced by: '<S731>/volc_flg_BMSH_Vehicle_HVILSts_PHEV_ovrdflg' */
extern const volatile boolean volc_b_BrkPedal_1_ovrdflg;
                     /* Referenced by: '<S207>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */

/* Override flag for signal pct_BrkPedal_1 */
extern const volatile boolean volc_b_BrkPedal_2_ovrdflg;
                     /* Referenced by: '<S208>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */

/* Override flag for signal pct_BrkPedal_2 */
extern const volatile boolean volc_b_EDCP_Flt_ovrdflg;
                           /* Referenced by: '<S401>/volc_b_EDCP_Flt_ovrdflg' */
extern const volatile boolean volc_b_HBCPFlt_ovrdflg;
                     /* Referenced by: '<S402>/volc_b_PMS_ThermalReq_ovrdflg' */
extern const volatile boolean volc_b_PMS_32960FltNum_ovrdflg;
                  /* Referenced by: '<S732>/volc_flg_PMS_32960FltNum_ovrdflg' */
extern const volatile boolean volc_b_PMS_AcceRelayVoltSampSwich_ovrdflg;
         /* Referenced by: '<S855>/volc_b_PMS_AcceRelayVoltSampSwich_ovrdflg' */
extern const volatile boolean volc_b_PMS_AcceSuppressionSts_ovrdflg;
               /* Referenced by: '<S379>/volc_b_VCU_DriveCircuitTemp_ovrdflg' */
extern const volatile boolean volc_b_PMS_Acceleration_ovrdflg;
                   /* Referenced by: '<S162>/volc_b_PMS_Acceleration_ovrdflg' */
extern const volatile boolean volc_b_PMS_AccessoryConnStsFb_ovrdflg;
             /* Referenced by: '<S577>/volc_b_PMS_AccessoryConnStsFb_ovrdflg' */
extern const volatile boolean volc_b_PMS_AccessoryCtrlCommand_ovrdflg;
           /* Referenced by: '<S258>/volc_b_PMS_AccessoryCtrlCommand_ovrdflg' */
extern const volatile boolean volc_b_PMS_AccessoryRelayFlt_ovrdflg;
              /* Referenced by: '<S578>/volc_b_PMS_AccessoryRelayFlt_ovrdflg' */
extern const volatile boolean volc_b_PMS_ActualPTTorque_ovrdflg;
               /* Referenced by: '<S733>/volc_flg_PMS_ActualPTTorque_ovrdflg' */
extern const volatile boolean volc_b_PMS_BBM_FaultStatus_ovrdflg;
                /* Referenced by: '<S259>/volc_b_PMS_BBM_FaultStatus_ovrdflg' */
extern const volatile boolean volc_b_PMS_BBM_WorkSts_ovrdflg;
                    /* Referenced by: '<S260>/volc_b_PMS_BBM_WorkSts_ovrdflg' */
extern const volatile boolean volc_b_PMS_BMS_Reignstatus1_ovrdflg;
                     /* Referenced by: '<S734>/volc_flg_PMS_ePTFault_ovrdflg' */
extern const volatile boolean volc_b_PMS_BMS_Reignstatus2_ovrdflg;
                     /* Referenced by: '<S735>/volc_flg_PMS_ePTFault_ovrdflg' */
extern const volatile boolean volc_b_PMS_Brake_LightsRequest_ovrdflg;
           /* Referenced by: '<S736>/volc_flg_PMS_Brake_LightsReques_ovrdflg' */
extern const volatile boolean volc_b_PMS_CPSRU_ovrdflg;
               /* Referenced by: '<S380>/volc_b_PMS_TakeEleSwtIndReq_ovrdflg' */
extern const volatile boolean volc_b_PMS_CampModeFbFailrReason_ovrdflg;
          /* Referenced by: '<S738>/volc_b_PMS_CampModeFbFailrReason_ovrdflg' */
extern const volatile boolean volc_b_PMS_CampModeFb_ovrdflg;
                     /* Referenced by: '<S737>/volc_b_PMS_CampModeFb_ovrdflg' */
extern const volatile boolean volc_b_PMS_ChargPwr_ovrdflg;
              /* Referenced by: '<S381>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_PMS_ChargeLimitResponse_ovrdflg;
               /* Referenced by: '<S739>/volc_flg_PMS_VacuumPressure_ovrdflg' */
extern const volatile boolean volc_b_PMS_CruisingDstSwtFb_ovrdflg;
             /* Referenced by: '<S740>/volc_flg_PMS_CruisingDstSwtFb_ovrdflg' */
extern const volatile boolean volc_b_PMS_CurrentGearPositionValid_ovrdflg;
     /* Referenced by: '<S639>/volc_flg_PMS_CurrentGearPositionValid_ovrdflg' */
extern const volatile boolean volc_b_PMS_DriverDemandTorque_ovrdflg;
           /* Referenced by: '<S741>/volc_flg_PMS_DriverDemandTorque_ovrdflg' */
extern const volatile boolean volc_b_PMS_DrivingTakeEleSts_ovrdflg;
              /* Referenced by: '<S261>/volc_b_PMS_DrivingTakeEleSts_ovrdflg' */
extern const volatile boolean volc_b_PMS_DrvPfmncRed_ovrdflg;
                 /* Referenced by: '<S742>/volc_flg_PMS_DrvPfmncRedn_ovrdflg' */
extern const volatile boolean volc_b_PMS_EPBClosedReq_PMS_ovrdflg;
             /* Referenced by: '<S743>/volc_flg_PMS_EPBClosedReq_PMS_ovrdflg' */
extern const volatile boolean volc_b_PMS_Fn1GearRlyDrvStsFb_ovrdflg;
               /* Referenced by: '<S382>/volc_b_PMS_TakeEleSwtIndReq_ovrdflg' */
extern const volatile boolean volc_b_PMS_Fn2GearRlyDrvStsFb_ovrdflg;
               /* Referenced by: '<S383>/volc_b_PMS_TakeEleSwtIndReq_ovrdflg' */
extern const volatile boolean volc_b_PMS_FrntHeatModEnad_ovrdflg;
              /* Referenced by: '<S163>/volc_flg_PMS_FrntHeatModEnad_ovrdflg' */
extern const volatile boolean volc_b_PMS_FrntHeatPwrAllwd_ovrdflg;
             /* Referenced by: '<S164>/volc_flg_PMS_FrntHeatPwrAllwd_ovrdflg' */
extern const volatile boolean volc_b_PMS_GearIntervene_ovrdflg;
             /* Referenced by: '<S744>/volc_flg_BMSH_ACChgTimeRemain_ovrdflg' */
extern const volatile boolean volc_b_PMS_GrossComVehWeight_ovrdflg;
            /* Referenced by: '<S745>/volc_flg_PMS_GrossComVehWeight_ovrdflg' */
extern const volatile boolean volc_b_PMS_HVIL1Sts_EV_ovrdflg;
                  /* Referenced by: '<S165>/volc_flg_PMS_HVIL1Sts_EV_ovrdflg' */
extern const volatile boolean volc_b_PMS_HVIL1Sts_UB_ovrdflg;
                    /* Referenced by: '<S166>/volc_b_PMS_HVIL1Sts_UB_ovrdflg' */
extern const volatile boolean volc_b_PMS_HVIL2Sts_EV_ovrdflg;
                  /* Referenced by: '<S167>/volc_flg_PMS_HVIL2Sts_EV_ovrdflg' */
extern const volatile boolean volc_b_PMS_HVIL2Sts_UB_ovrdflg;
                    /* Referenced by: '<S168>/volc_b_PMS_HVIL2Sts_UB_ovrdflg' */
extern const volatile boolean volc_b_PMS_HVILSts_EV_ovrdflg;
                   /* Referenced by: '<S169>/volc_flg_PMS_HVILSts_EV_ovrdflg' */
extern const volatile boolean volc_b_PMS_HvCoolgPwrAllwd_ovrdflg;
              /* Referenced by: '<S403>/volc_flg_PMS_HvCoolgPwrAllwd_ovrdflg' */
extern const volatile boolean volc_b_PMS_HvHeatgPwrAllwd_ovrdflg;
              /* Referenced by: '<S404>/volc_flg_PMS_HvHeatgPwrAllwd_ovrdflg' */
extern const volatile boolean volc_b_PMS_IPKTotalOdometer_ovrdflg;
               /* Referenced by: '<S746>/volc_b_PMS_IPKTotalOdometer_ovrdflg' */
extern const volatile boolean volc_b_PMS_InventorySpdLmtRxSts_ovrdflg;
         /* Referenced by: '<S747>/volc_flg_PMS_InventorySpdLmtRxSts_ovrdflg' */
extern const volatile boolean volc_b_PMS_InventorySpdLmtSts_ovrdflg;
           /* Referenced by: '<S748>/volc_flg_PMS_InventorySpdLmtSts_ovrdflg' */
extern const volatile boolean volc_b_PMS_IsgActvDampgModReq_ovrdflg;
           /* Referenced by: '<S487>/volc_flg_PMS_IsgActvDampgModReq_ovrdflg' */
extern const volatile boolean volc_b_PMS_Life_ovrdflg;
                         /* Referenced by: '<S749>/volc_flg_PMS_Life_ovrdflg' */
extern const volatile boolean volc_b_PMS_LockVehExecutedSts_ovrdflg;
              /* Referenced by: '<S384>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_PMS_LockVehPerFlag_ovrdflg;
               /* Referenced by: '<S750>/volc_flg_PMS_LockVehPerFlag_ovrdflg' */
extern const volatile boolean volc_b_PMS_LockVehPerRxSts_ovrdflg;
              /* Referenced by: '<S751>/volc_flg_PMS_LockVehPerRxSts_ovrdflg' */
extern const volatile boolean volc_b_PMS_MCUFlowFeedback_EV_ovrdflg;
           /* Referenced by: '<S405>/volc_flg_PMS_MCUFlowFeedback_EV_ovrdflg' */
extern const volatile boolean volc_b_PMS_MaxPTTorqueAllowed_ovrdflg;
           /* Referenced by: '<S752>/volc_flg_PMS_MaxPTTorqueAllowed_ovrdflg' */
extern const volatile boolean volc_b_PMS_MinPTTorqueAllowed_ovrdflg;
           /* Referenced by: '<S753>/volc_flg_PMS_MinPTTorqueAllowed_ovrdflg' */
extern const volatile boolean volc_b_PMS_OTAInstrucStsReminder_ovrdflg;
        /* Referenced by: '<S754>/volc_flg_PMS_OTAInstrucStsReminder_ovrdflg' */
extern const volatile boolean volc_b_PMS_OTAInstructRxnSts_ovrdflg;
            /* Referenced by: '<S755>/volc_flg_PMS_OTAInstructRxnSts_ovrdflg' */
extern const volatile boolean volc_b_PMS_OdometerbackupEnable_ovrdflg;
           /* Referenced by: '<S757>/volc_b_PMS_OdometerbackupEnable_ovrdflg' */
extern const volatile boolean volc_b_PMS_Odometerbackup_ovrdflg;
               /* Referenced by: '<S756>/volc_flg_PMS_Odometerbackup_ovrdflg' */

/* Override flag  */
extern const volatile boolean volc_b_PMS_PTC1ConnStsFb_ovrdflg;
                  /* Referenced by: '<S579>/volc_b_PMS_PTC1ConnStsFb_ovrdflg' */
extern const volatile boolean volc_b_PMS_PTC1RelayFlt_ovrdflg;
                   /* Referenced by: '<S580>/volc_b_PMS_PTC1RelayFlt_ovrdflg' */
extern const volatile boolean volc_b_PMS_PTC3ConnStsFb_ovrdflg;
                  /* Referenced by: '<S581>/volc_b_PMS_PTC3ConnStsFb_ovrdflg' */
extern const volatile boolean volc_b_PMS_PTC3RelayFlt_ovrdflg;
                   /* Referenced by: '<S582>/volc_b_PMS_PTC3RelayFlt_ovrdflg' */
extern const volatile boolean volc_b_PMS_PTCRelayVoltSampSwich_ovrdflg;
          /* Referenced by: '<S856>/volc_b_PMS_PTCRelayVoltSampSwich_ovrdflg' */
extern const volatile boolean volc_b_PMS_PowerOffCmdRxSts_ovrdflg;
               /* Referenced by: '<S758>/volc_b_PMS_PowerOffCmdRxSts_ovrdflg' */
extern const volatile boolean volc_b_PMS_PowerOffCmdSts_ovrdflg;
                 /* Referenced by: '<S759>/volc_b_PMS_PowerOffCmdSts_ovrdflg' */
extern const volatile boolean volc_b_PMS_PreAccessoryConnStsFb_ovrdflg;
          /* Referenced by: '<S583>/volc_b_PMS_PreAccessoryConnStsFb_ovrdflg' */
extern const volatile boolean volc_b_PMS_PreAccessoryRelayFlt_ovrdflg;
           /* Referenced by: '<S584>/volc_b_PMS_PreAccessoryRelayFlt_ovrdflg' */
extern const volatile boolean volc_b_PMS_Real_PedalPositionInvalid_ovrdflg;
    /* Referenced by: '<S452>/volc_flg_PMS_Real_PedalPositionInvalid_ovrdflg' */
extern const volatile float32 volc_b_PMS_Real_PedalPosition_ovrdflg;
           /* Referenced by: '<S451>/volc_flg_PMS_Real_PedalPosition_ovrdflg' */
extern const volatile boolean volc_b_PMS_RegenTarTrqPot_ovrdflg;
               /* Referenced by: '<S760>/volc_flg_PMS_RegenTarTrqPot_ovrdflg' */
extern const volatile boolean volc_b_PMS_RegenTrqAct_ovrdflg;
                  /* Referenced by: '<S761>/volc_flg_PMS_RegenTrqAct_ovrdflg' */
extern const volatile boolean volc_b_PMS_RegenTrqPot_ovrdflg;
                  /* Referenced by: '<S762>/volc_flg_PMS_RegenTrqPot_ovrdflg' */
extern const volatile boolean volc_b_PMS_RegulationSpeed_ovrdflg;
               /* Referenced by: '<S385>/volc_b_VCU_DriveCircuitTemp_ovrdflg' */
extern const volatile boolean volc_b_PMS_RemChrgCmdFailrPrompt_ovrdflg;
              /* Referenced by: '<S386>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_PMS_SpdLmtLevelRxSts_ovrdflg;
             /* Referenced by: '<S764>/volc_flg_PMS_SpdLmtLevelRxSts_ovrdflg' */
extern const volatile boolean volc_b_PMS_SpdLmtLevel_ovrdflg;
                  /* Referenced by: '<S763>/volc_flg_PMS_SpdLmtLevel_ovrdflg' */
extern const volatile boolean volc_b_PMS_StsBatLockSensor_ovrdflg;
             /* Referenced by: '<S170>/volc_flg_PMS_StsBatLockSensor_ovrdflg' */
extern const volatile boolean volc_b_PMS_TBOX_HVILState_ovrdflg;
               /* Referenced by: '<S765>/volc_flg_PMS_TBOX_HVILState_ovrdflg' */
extern const volatile boolean volc_b_PMS_TBOX_LifeSts_ovrdflg;
                 /* Referenced by: '<S766>/volc_flg_PMS_TBOX_LifeSts_ovrdflg' */
extern const volatile boolean volc_b_PMS_TakeEleSwtIndReq_ovrdflg;
               /* Referenced by: '<S387>/volc_b_PMS_TakeEleSwtIndReq_ovrdflg' */
extern const volatile boolean volc_b_PMS_ThermalReq_ovrdflg;
                     /* Referenced by: '<S406>/volc_b_PMS_ThermalReq_ovrdflg' */
extern const volatile boolean volc_b_PMS_Torque_Ovrd_Active_ovrdflg;
               /* Referenced by: '<S388>/volc_b_VCU_DriveCircuitTemp_ovrdflg' */
extern const volatile boolean volc_b_PMS_Torque_Ovrd_Type_ovrdflg;
               /* Referenced by: '<S389>/volc_b_VCU_DriveCircuitTemp_ovrdflg' */
extern const volatile boolean volc_b_PMS_V2XDchaSwtFb1_ovrdflg;
             /* Referenced by: '<S767>/volc_flg_BMSH_ACChgTimeRemain_ovrdflg' */
extern const volatile boolean volc_b_PMS_VINCode1_8_15_S_ovrdflg;
              /* Referenced by: '<S768>/volc_flg_PMS_VINCode1_8_15_S_ovrdflg' */
extern const volatile boolean volc_b_PMS_VINCode2_9_16_S_ovrdflg;
              /* Referenced by: '<S769>/volc_flg_PMS_VINCode2_9_16_S_ovrdflg' */
extern const volatile boolean volc_b_PMS_VINCode3_10_17_S_ovrdflg;
             /* Referenced by: '<S770>/volc_flg_PMS_VINCode3_10_17_S_ovrdflg' */
extern const volatile boolean volc_b_PMS_VINCode4_11_S_ovrdflg;
                /* Referenced by: '<S771>/volc_flg_PMS_VINCode4_11_S_ovrdflg' */
extern const volatile boolean volc_b_PMS_VINCode5_12_S_ovrdflg;
                /* Referenced by: '<S772>/volc_flg_PMS_VINCode5_12_S_ovrdflg' */
extern const volatile boolean volc_b_PMS_VINCode6_13_S_ovrdflg;
                /* Referenced by: '<S773>/volc_flg_PMS_VINCode6_13_S_ovrdflg' */
extern const volatile boolean volc_b_PMS_VINCode7_14_S_ovrdflg;
                /* Referenced by: '<S774>/volc_flg_PMS_VINCode7_14_S_ovrdflg' */
extern const volatile boolean volc_b_PMS_VINMessageNum_S_ovrdflg;
              /* Referenced by: '<S775>/volc_flg_PMS_VINMessageNum_S_ovrdflg' */
extern const volatile boolean volc_b_PMS_VacuumPressure_ovrdflg;
               /* Referenced by: '<S776>/volc_flg_PMS_VacuumPressure_ovrdflg' */
extern const volatile boolean volc_b_PMS_VacuumPump_FB_ovrdflg;
                  /* Referenced by: '<S777>/volc_b_PMS_VacuumPump_FB_ovrdflg' */
extern const volatile boolean volc_b_PMS_VacuumSystemsta_ovrdflg;
              /* Referenced by: '<S778>/volc_flg_PMS_VacuumSystemsta_ovrdflg' */
extern const volatile boolean volc_b_PMS_VehicleSysErrorLevelG_ovrdflg;
              /* Referenced by: '<S398>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_PMS_VersionConversionFlag_ovrdflg;
        /* Referenced by: '<S779>/volc_flg_PMS_VersionConversionFlag_ovrdflg' */
extern const volatile boolean volc_b_PMS_VersionConversionRxSts_ovrdflg;
       /* Referenced by: '<S780>/volc_flg_PMS_VersionConversionRxSts_ovrdflg' */
extern const volatile boolean volc_b_PMS_ePTFault_ovrdflg;
                     /* Referenced by: '<S781>/volc_flg_PMS_ePTFault_ovrdflg' */
extern const volatile boolean volc_b_ResetHSDFRA16A17_invert;
                         /* Referenced by: '<S186>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal b_ResetHSDFRA16A17 */
extern const volatile boolean volc_b_ResetHSDFRA16A17_ovrdflg;
                        /* Referenced by: '<S186>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal b_ResetHSDFRA16A17 */
extern const volatile boolean volc_b_ResetHSDFRA16A17_ovrdval;
                        /* Referenced by: '<S186>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal b_ResetHSDFRA16A17 */
extern const volatile boolean volc_b_ResetHSDFRA1A2_invert;
                         /* Referenced by: '<S187>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal b_ResetHSDFRA1A2 */
extern const volatile boolean volc_b_ResetHSDFRA1A2_ovrdflg;
                        /* Referenced by: '<S187>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal b_ResetHSDFRA1A2 */
extern const volatile boolean volc_b_ResetHSDFRA1A2_ovrdval;
                        /* Referenced by: '<S187>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal b_ResetHSDFRA1A2 */
extern const volatile boolean volc_b_ResetHSDFRA31A32_invert;
                         /* Referenced by: '<S188>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal b_ResetHSDFRA31A32 */
extern const volatile boolean volc_b_ResetHSDFRA31A32_ovrdflg;
                        /* Referenced by: '<S188>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal b_ResetHSDFRA31A32 */
extern const volatile boolean volc_b_ResetHSDFRA31A32_ovrdval;
                        /* Referenced by: '<S188>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal b_ResetHSDFRA31A32 */
extern const volatile boolean volc_b_ResetHSDFRA46A47_invert;
                         /* Referenced by: '<S189>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal b_ResetHSDFRA46A47 */
extern const volatile boolean volc_b_ResetHSDFRA46A47_ovrdflg;
                        /* Referenced by: '<S189>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal b_ResetHSDFRA46A47 */
extern const volatile boolean volc_b_ResetHSDFRA46A47_ovrdval;
                        /* Referenced by: '<S189>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal b_ResetHSDFRA46A47 */
extern const volatile boolean volc_b_ShtDown_ovrdflg;
                      /* Referenced by: '<S216>/vilc_b_ResrAirSwitch_ovrdflg' */
extern const volatile boolean volc_b_TBOX_ChrgSoftSwCtrlst_ovrdflg;
              /* Referenced by: '<S390>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_TBOX_ReservationChrgnSts_ovrdflg;
              /* Referenced by: '<S391>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_VCU_12VATS1Enable_ovrdflg;
                /* Referenced by: '<S431>/volc_flg_VCU_12VATS1Enable_ovrdflg' */

/* Override flag for signal b_VCU_12VATS1Enable */
extern const volatile boolean volc_b_VCU_12VATS1_PWMRequest_ovrdflg;
           /* Referenced by: '<S432>/volc_flg_VCU_12VATS1_PWMRequest_ovrdflg' */

/* Override flag for signal b_VCU_12VATS1_PWMRequest */
extern const volatile boolean volc_b_VCU_12VDCDCCutOffLV_ovrdflg;
              /* Referenced by: '<S535>/volc_flg_VCU_12VDCDCCutOffLV_ovrdflg' */

/* Override flag for signal b_VCU_12VDCDCCutOffLV */
extern const volatile boolean volc_b_VCU_12VDCDCEnableOut_ovrdflg;
             /* Referenced by: '<S536>/volc_flg_VCU_12VDCDCEnableOut_ovrdflg' */

/* Override flag for signal b_VCU_12VDCDCEnableOut */
extern const volatile boolean volc_b_VCU_24V_Switch_ovrdflg;
             /* Referenced by: '<S679>/volc_b_VCU_CabinLoopVal1_FBV6_ovrdflg' */

/* Override flag for signal VCU_24V_Switch */
extern const volatile boolean volc_b_VCU_ACActiveReq_ovrdflg;
                  /* Referenced by: '<S453>/volc_flg_VCU_ACActiveReq_ovrdflg' */

/* Override flag for signal b_VCU_ACActiveReq */
extern const volatile boolean volc_b_VCU_ACC1PosVol_ovrdflg;
                     /* Referenced by: '<S564>/volc_b_VCU_ACC1PosVol_ovrdflg' */

/* Override flag for signal b_VCU_ACC1PosVol */
extern const volatile boolean volc_b_VCU_ACC2PosVol_ovrdflg;
                     /* Referenced by: '<S565>/volc_b_VCU_ACC2PosVol_ovrdflg' */

/* Override flag for signal b_VCU_ACC2PosVol */
extern const volatile boolean volc_b_VCU_ACCMEnable_ovrdflg;
                     /* Referenced by: '<S408>/volc_b_VCU_ACCMEnable_ovrdflg' */

/* Override flag for signal ACCMEnable */
extern const volatile boolean volc_b_VCU_ACCY1CtrlCmd_ovrdflg;
                   /* Referenced by: '<S262>/volc_b_VCU_ACCY1CtrlCmd_ovrdflg' */

/* Override flag for signal VCU_ACCY1CtrlCmd */
extern const volatile boolean volc_b_VCU_ACCYEnableIn_ovrdflg;
                   /* Referenced by: '<S263>/volc_b_VCU_ACCYEnableIn_ovrdflg' */

/* Override flag for signal VCU_ACCYEnableIn */
extern const volatile boolean volc_b_VCU_ACUCrashfz_Back_ovrdflg;
                /* Referenced by: '<S264>/volc_b_VCU_ACUCrashfz_Back_ovrdflg' */

/* Override flag for signal VCU_ACUCrashfz_Back */
extern const volatile boolean volc_b_VCU_AEC_ovrdflg;
                          /* Referenced by: '<S527>/volc_flg_VCU_AEC_ovrdflg' */

/* Override flag for signal b_VCU_AEC */
extern const volatile boolean volc_b_VCU_APUSWILED_Ctrl_ovrdflg;
                 /* Referenced by: '<S265>/volc_b_VCU_APUSWILED_Ctrl_ovrdflg' */

/* Override flag for signal VCU_APUSWILED_Ctrl */
extern const volatile boolean volc_b_VCU_ATS1Enable_ovrdflg;
                   /* Referenced by: '<S433>/volc_flg_VCU_ATS1Enable_ovrdflg' */

/* Override flag for signal b_VCU_ATS1Enable */
extern const volatile boolean volc_b_VCU_ATS1_PWMRequest_ovrdflg;
              /* Referenced by: '<S434>/volc_flg_VCU_ATS1_PWMRequest_ovrdflg' */

/* Override flag for signal b_VCU_ATS1_PWMRequest */
extern const volatile boolean volc_b_VCU_ATS2Enable_ovrdflg;
                   /* Referenced by: '<S435>/volc_flg_VCU_ATS2Enable_ovrdflg' */

/* Override flag for signal b_VCU_ATS2Enable */
extern const volatile boolean volc_b_VCU_ATS2_PWMRequest_ovrdflg;
              /* Referenced by: '<S436>/volc_flg_VCU_ATS2_PWMRequest_ovrdflg' */

/* Override flag for signal b_VCU_ATS2_PWMRequest */
extern const volatile boolean volc_b_VCU_ATS3Enable_ovrdflg;
                   /* Referenced by: '<S437>/volc_flg_VCU_ATS3Enable_ovrdflg' */

/* Override flag for signal b_VCU_ATS3Enable */
extern const volatile boolean volc_b_VCU_ATS3_PWMRequest_ovrdflg;
              /* Referenced by: '<S438>/volc_flg_VCU_ATS3_PWMRequest_ovrdflg' */

/* Override flag for signal b_VCU_ATS3_PWMRequest */
extern const volatile boolean volc_b_VCU_ATS4Enable_ovrdflg;
                   /* Referenced by: '<S439>/volc_flg_VCU_ATS4Enable_ovrdflg' */

/* Override flag for signal b_VCU_ATS4Enable */
extern const volatile boolean volc_b_VCU_ATS4_PWMRequest_ovrdflg;
              /* Referenced by: '<S440>/volc_flg_VCU_ATS4_PWMRequest_ovrdflg' */

/* Override flag for signal b_VCU_ATS4_PWMRequest */
extern const volatile boolean volc_b_VCU_AWB_ovrdflg;
                /* Referenced by: '<S614>/volc_flg_VCU_AccePedalPosE_ovrdflg' */

/* Override flag for signal VCU_AWB */
extern const volatile boolean volc_b_VCU_AccePedalPosD_ovrdflg;
                /* Referenced by: '<S626>/volc_flg_VCU_AccePedalPosD_ovrdflg' */

/* Override flag for signal VCU_AccePedalPosD */
extern const volatile boolean volc_b_VCU_AccePedalPosE_ovrdflg;
                /* Referenced by: '<S627>/volc_flg_VCU_AccePedalPosE_ovrdflg' */

/* Override flag for signal VCU_AccePedalPosE */
extern const volatile boolean volc_b_VCU_AcceleratorPedalPosition_ovrdflg;
     /* Referenced by: '<S454>/volc_flg_VCU_AcceleratorPedalPosition_ovrdflg' */

/* Override flag for signal b_VCU_AcceleratorPedalPosition */
extern const volatile boolean volc_b_VCU_AcceleratorPedal_flag_ovrdflg;
        /* Referenced by: '<S455>/volc_flg_VCU_AcceleratorPedal_flag_ovrdflg' */

/* Override flag for signal VCU_AcceleratorPedal_flag */
extern const volatile boolean volc_b_VCU_AccyAllowEnable_Ctrl_ovrdflg;
           /* Referenced by: '<S266>/volc_b_VCU_AccyAllowEnable_Ctrl_ovrdflg' */

/* Override flag for signal VCU_AccyAllowEnable_Ctrl */
extern const volatile boolean volc_b_VCU_AccyPower_back_ovrdflg;
                 /* Referenced by: '<S267>/volc_b_VCU_AccyPower_back_ovrdflg' */

/* Override flag for signal VCU_AccyPower_back */
extern const volatile boolean volc_b_VCU_ActualGear_ovrdflg;
                   /* Referenced by: '<S868>/volc_flg_VCU_ActualGear_ovrdflg' */

/* Override flag for signal b_VCU_ActualGear */
extern const volatile boolean volc_b_VCU_Address_ovrdflg;
                /* Referenced by: '<S615>/volc_flg_VCU_AccePedalPosD_ovrdflg' */

/* Override flag for signal VCU_Address */
extern const volatile boolean volc_b_VCU_AllowChg_ovrdflg;
                     /* Referenced by: '<S537>/volc_flg_VCU_AllowChg_ovrdflg' */

/* Override flag for signal b_VCU_AllowChg */
extern const volatile boolean volc_b_VCU_AppSts_ovrdflg;
                     /* Referenced by: '<S566>/volc_b_VCU_ACC2PosVol_ovrdflg' */

/* Override flag for signal VCU_AppSts */
extern const volatile boolean volc_b_VCU_AvgEVConsume_ovrdflg;
                   /* Referenced by: '<S268>/volc_b_VCU_AvgEVConsume_ovrdflg' */

/* Override flag for signal VCU_AvgEVConsume */
extern const volatile boolean volc_b_VCU_AvgFuelVF_ovrdflg;
                      /* Referenced by: '<S269>/volc_b_VCU_AvgFuelVF_ovrdflg' */

/* Override flag for signal VCU_AvgFuelVF */
extern const volatile boolean volc_b_VCU_BMSHVOnOffReq_ovrdflg;
                /* Referenced by: '<S538>/volc_flg_VCU_BMSHVOnOffReq_ovrdflg' */

/* Override flag for signal b_VCU_BMSHVOnOffReq */
extern const volatile boolean volc_b_VCU_BMSH_DCChgRelayVolt_ovrdflg;
            /* Referenced by: '<S539>/volc_b_VCU_BMSH_DCChgRelayVolt_ovrdflg' */
extern const volatile boolean volc_b_VCU_BMS_SOC_ovrdflg;
                        /* Referenced by: '<S335>/volc_b_VCU_BMS_SOC_ovrdflg' */

/* Override flag for signal VCU_BMS_SOC */
extern const volatile boolean volc_b_VCU_BMS_voltage_ovrdflg;
                    /* Referenced by: '<S336>/volc_b_VCU_BMS_voltage_ovrdflg' */

/* Override flag for signal VCU_BMS_voltage */
extern const volatile boolean volc_b_VCU_BPTCCtrlCmd_ovrdflg;
                    /* Referenced by: '<S561>/volc_b_VCU_BPTCCtrlCmd_ovrdflg' */

/* Override flag for signal VCU_BPTCCtrlCmd */
extern const volatile boolean volc_b_VCU_BPTCEnable_invert;
                     /* Referenced by: '<S859>/volc_b_VCU_HVBC_Enable_invert' */

/* Invert flag for signal VCU_BPTCEnable */
extern const volatile boolean volc_b_VCU_BPTCEnable_ovrdflg;
                    /* Referenced by: '<S859>/volc_b_VCU_HVBC_Enable_ovrdflg' */

/* Override flag for signal VCU_BPTCEnable */
extern const volatile boolean volc_b_VCU_BPTCPowerRatio_ovrdflg;
                /* Referenced by: '<S860>/volc_b_VCU_HVBC_COpenValue_ovrdflg' */

/* Override flag for signal VCU_BPTCPowerRatio */
extern const volatile boolean volc_b_VCU_BPTCTempSetting_ovrdflg;
                /* Referenced by: '<S861>/volc_b_VCU_HVBC_COpenValue_ovrdflg' */

/* Override flag for signal VCU_BPTCTempSetting */
extern const volatile boolean volc_b_VCU_BattCoolVal3_FBV5_ovrdflg;
              /* Referenced by: '<S597>/volc_b_VCU_BattCoolVal3_FBV5_ovrdflg' */

/* Override flag for signal b_VCU_BattCoolVal3_FBV5 */
extern const volatile boolean volc_b_VCU_BattCoolVal3_FBV6_ovrdflg;
              /* Referenced by: '<S598>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */

/* Override flag for signal b_VCU_BattCoolVal3_FBV6 */
extern const volatile boolean volc_b_VCU_BattHeatVal2_FBV5_ovrdflg;
              /* Referenced by: '<S599>/volc_b_VCU_BattHeatVal2_FBV5_ovrdflg' */

/* Override flag for signal b_VCU_BattHeatVal2_FBV5 */
extern const volatile boolean volc_b_VCU_BattHeatVal2_FBV6_ovrdflg;
              /* Referenced by: '<S600>/volc_b_VCU_BattHeatVal2_FBV6_ovrdflg' */

/* Override flag for signal b_VCU_BattHeatVal2_FBV6 */
extern const volatile boolean volc_b_VCU_BattMaxTemp_ovrdflg;
                  /* Referenced by: '<S337>/volc_flg_VCU_BattMaxTemp_ovrdflg' */

/* Override flag for signal VCU_BattMaxTemp */
extern const volatile boolean volc_b_VCU_BattMinTemp_ovrdflg;
                  /* Referenced by: '<S338>/volc_flg_VCU_BattMinTemp_ovrdflg' */

/* Override flag for signal VCU_BattMinTemp */
extern const volatile boolean volc_b_VCU_BattPackInCoolTemp_ovrdflg;
             /* Referenced by: '<S409>/volc_b_VCU_BattPackInCoolTemp_ovrdflg' */

/* Override flag for signal VCU_BattPackInCoolTemp */
extern const volatile boolean volc_b_VCU_BattPackInCoolTempback_ovrdflg;
         /* Referenced by: '<S270>/volc_b_VCU_BattPackInCoolTempback_ovrdflg' */

/* Override flag for signal VCU_BattPackInCoolTempback */
extern const volatile boolean volc_b_VCU_BattPackOutCoolTemp_ovrdflg;
            /* Referenced by: '<S410>/volc_b_VCU_BattPackoutCoolTemp_ovrdflg' */

/* Override flag for signal VCU_BattPackOutCoolTemp */
extern const volatile boolean volc_b_VCU_BattPackoutCoolTempback_ovrdflg;
        /* Referenced by: '<S271>/volc_b_VCU_BattPackoutCoolTempback_ovrdflg' */

/* Override flag for signal VCU_BattPackoutCoolTempback */
extern const volatile boolean volc_b_VCU_BattVol_ovrdflg;
                      /* Referenced by: '<S339>/volc_flg_VCU_BattVol_ovrdflg' */

/* Override flag for signal VCU_BattVol */
extern const volatile boolean volc_b_VCU_BatteryCoolentTemp_ovrdflg;
           /* Referenced by: '<S411>/volc_flg_VCU_BatteryCoolentTemp_ovrdflg' */

/* Override flag for signal b_VCU_BatteryCoolentTemp */
extern const volatile boolean volc_b_VCU_BatteryVol_ovrdflg;
                     /* Referenced by: '<S567>/volc_b_VCU_ACC2PosVol_ovrdflg' */

/* Override flag for signal b_VCU_BatteryVol */
extern const volatile boolean volc_b_VCU_Batty_Charge_DisChargeState_ovrdflg;
  /* Referenced by: '<S340>/volc_flg_VCU_Batty_Charge_DisChargeState_ovrdflg' */

/* Override flag for signal VCU_Batty_Charge_DisChargeState */
extern const volatile boolean volc_b_VCU_Batty_ThermalMangeActive_ovrdflg;
     /* Referenced by: '<S341>/volc_flg_VCU_Batty_ThermalMangeActive_ovrdflg' */

/* Override flag for signal VCU_Batty_ThermalMangeActive */
extern const volatile boolean volc_b_VCU_Batty_ThermalMangeReq_ovrdflg;
        /* Referenced by: '<S412>/volc_flg_VCU_Batty_ThermalMangeReq_ovrdflg' */

/* Override flag for signal b_VCU_Batty_ThermalMangeReq */
extern const volatile boolean volc_b_VCU_Batty_ThermalMangeWorkMode_ovrdflg;
   /* Referenced by: '<S342>/volc_flg_VCU_Batty_ThermalMangeWorkMode_ovrdflg' */

/* Override flag for signal VCU_Batty_ThermalMangeWorkMode */
extern const volatile boolean volc_b_VCU_BrakSwitchSts_ovrdflg;
                /* Referenced by: '<S456>/volc_flg_VCU_BrakSwitchSts_ovrdflg' */

/* Override flag for signal b_VCU_BrakSwitchSts */
extern const volatile boolean volc_b_VCU_Brake1PosVol_ovrdflg;
                   /* Referenced by: '<S592>/volc_b_VCU_Brake1PosVol_ovrdflg' */

/* Override flag for signal b_VCU_Brake1PosVol */
extern const volatile boolean volc_b_VCU_Brake1Sts_invert;
                       /* Referenced by: '<S568>/volc_b_VCU_Brake1Sts_invert' */

/* Invert flag for signal b_VCU_Brake1Sts */
extern const volatile boolean volc_b_VCU_Brake1Sts_ovrdflg;
                      /* Referenced by: '<S568>/volc_b_VCU_Brake1Sts_ovrdflg' */

/* Override flag for signal b_VCU_Brake1Sts */
extern const volatile boolean volc_b_VCU_Brake2PosVol_ovrdflg;
                   /* Referenced by: '<S593>/volc_b_VCU_Brake2PosVol_ovrdflg' */

/* Override flag for signal b_VCU_Brake2PosVol */
extern const volatile boolean volc_b_VCU_Brake2Sts_invert;
                       /* Referenced by: '<S569>/volc_b_VCU_Brake2Sts_invert' */

/* Invert flag for signal b_VCU_Brake2Sts */
extern const volatile boolean volc_b_VCU_Brake2Sts_ovrdflg;
                      /* Referenced by: '<S569>/volc_b_VCU_Brake2Sts_ovrdflg' */

/* Override flag for signal b_VCU_Brake2Sts */
extern const volatile boolean volc_b_VCU_BrakePedalPosition_ovrdflg;
           /* Referenced by: '<S457>/volc_flg_VCU_BrakePedalPosition_ovrdflg' */

/* Override flag for signal b_VCU_BrakePedalPosition */
extern const volatile boolean volc_b_VCU_BrkSysErr_ovrdflg;
                    /* Referenced by: '<S640>/volc_flg_VCU_BrkSysErr_ovrdflg' */

/* Override flag for signal b_VCU_BrkSysErr */
extern const volatile boolean volc_b_VCU_CCFb_ovrdflg;
                           /* Referenced by: '<S585>/volc_b_VCU_CCFb_ovrdflg' */

/* Override flag for signal b_VCU_CCFb */
extern const volatile boolean volc_b_VCU_CC_Acceleration_ovrdflg;
                /* Referenced by: '<S314>/volc_b_VCU_CC_Acceleration_ovrdflg' */

/* Override flag for signal VCU_CC_Acceleration */
extern const volatile boolean volc_b_VCU_Cab_ThermalMangeReq_ovrdflg;
          /* Referenced by: '<S343>/volc_flg_VCU_Cab_ThermalMangeReq_ovrdflg' */

/* Override flag for signal VCU_Cab_ThermalMangeReq */
extern const volatile boolean volc_b_VCU_CabinLoopVal1_FBV6_ovrdflg;
             /* Referenced by: '<S601>/volc_b_VCU_CabinLoopVal1_FBV6_ovrdflg' */

/* Override flag for signal b_VCU_CabinLoopVal1_FBV6 */
extern const volatile boolean volc_b_VCU_CabinLoopVal2_FBV5_ovrdflg;
             /* Referenced by: '<S602>/volc_b_VCU_CabinLoopVal2_FBV5_ovrdflg' */

/* Override flag for signal b_VCU_CabinLoopVal2_FBV5 */
extern const volatile boolean volc_b_VCU_Cabin_PumpFb_ovrdflg;
                   /* Referenced by: '<S586>/volc_b_VCU_Cabin_PumpFb_ovrdflg' */

/* Override flag for signal b_VCU_Cabin_PumpFb */
extern const volatile boolean volc_b_VCU_CalNum_ovrdflg;
                         /* Referenced by: '<S862>/volc_b_VCU_CalNum_ovrdflg' */

/* Override flag for signal VCU_CalNum */
extern const volatile boolean volc_b_VCU_CalibrationMajorVer1_ovrdflg;
                 /* Referenced by: '<S691>/volc_flg_VCU_SWCompileDay_ovrdflg' */
extern const volatile boolean volc_b_VCU_CalibrationMajorVer2_ovrdflg;
                 /* Referenced by: '<S692>/volc_flg_VCU_SWCompileDay_ovrdflg' */
extern const volatile boolean volc_b_VCU_CalibrationMajorVer3_ovrdflg;
                 /* Referenced by: '<S693>/volc_flg_VCU_SWCompileDay_ovrdflg' */
extern const volatile boolean volc_b_VCU_CalibrationMinorVer1_ovrdflg;
                 /* Referenced by: '<S694>/volc_flg_VCU_SWCompileDay_ovrdflg' */
extern const volatile boolean volc_b_VCU_CalibrationMinorVer2_ovrdflg;
                 /* Referenced by: '<S695>/volc_flg_VCU_SWCompileDay_ovrdflg' */
extern const volatile boolean volc_b_VCU_CalibrationMinorVer3_ovrdflg;
                 /* Referenced by: '<S696>/volc_flg_VCU_SWCompileDay_ovrdflg' */
extern const volatile boolean volc_b_VCU_Cell_Avg_Temp_ovrdflg;
                /* Referenced by: '<S344>/volc_flg_VCU_Cell_Avg_Temp_ovrdflg' */

/* Override flag for signal VCU_Cell_Avg_Temp */
extern const volatile boolean volc_b_VCU_ChargWakeupSts_ovrdflg;
                 /* Referenced by: '<S587>/volc_b_VCU_ChargWakeupSts_ovrdflg' */

/* Override flag for signal b_VCU_ChargWakeupSts */
extern const volatile boolean volc_b_VCU_ChargeDepthReq_ovrdflg;
              /* Referenced by: '<S400>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_VCU_Charger_Connected_ovrdflg;
            /* Referenced by: '<S345>/volc_flg_VCU_Charger_Connected_ovrdflg' */

/* Override flag for signal VCU_Charger_Connected */
extern const volatile boolean volc_b_VCU_ControlSetSpeed_Mode_ovrdflg;
         /* Referenced by: '<S476>/volc_flg_VCU_ControlSetSpeed_Mode_ovrdflg' */

/* Override flag for signal VCU_ControlSetSpeed_Mode */
extern const volatile boolean volc_b_VCU_ControlSetSpeed_ovrdflg;
              /* Referenced by: '<S475>/volc_flg_VCU_ControlSetSpeed_ovrdflg' */

/* Override flag for signal VCU_ControlSetSpeed */
extern const volatile boolean volc_b_VCU_Cooling_Control_Request_ovrdflg;
      /* Referenced by: '<S346>/volc_flg_VCU_Cooling_Control_Request_ovrdflg' */

/* Override flag for signal VCU_Cooling_Control_Request */
extern const volatile boolean volc_b_VCU_CrashOutputSts_ovrdflg;
               /* Referenced by: '<S782>/volc_flg_VCU_CrashOutputSts_ovrdflg' */
extern const volatile boolean volc_b_VCU_CruiseControlSts_ovrdflg;
               /* Referenced by: '<S477>/volc_b_VCU_CruiseControlSts_ovrdflg' */

/* Override flag for signal VCU_CruiseControlSts */
extern const volatile boolean volc_b_VCU_CruiseSwSts_ovrdflg;
                  /* Referenced by: '<S478>/volc_flg_VCU_CruiseSwSts_ovrdflg' */

/* Override flag for signal VCU_CruiseSwSts */
extern const volatile boolean volc_b_VCU_CruiseSwerrorSts_ovrdflg;
               /* Referenced by: '<S479>/volc_b_VCU_CruiseSwerrorSts_ovrdflg' */

/* Override flag for signal VCU_CruiseSwerrorSts */
extern const volatile boolean volc_b_VCU_DCDCPwrLmt_ovrdflg;
                   /* Referenced by: '<S540>/volc_flg_VCU_DCDCPwrLmt_ovrdflg' */

/* Override flag for signal b_VCU_DCDCPwrLmt */
extern const volatile boolean volc_b_VCU_DCDC_WorkSts_ovrdflg;
                 /* Referenced by: '<S641>/volc_flg_VCU_DCDC_WorkSts_ovrdflg' */

/* Override flag for signal VCU_DCDC_WorkSts */
extern const volatile boolean volc_b_VCU_DTE_ovrdflg;
                          /* Referenced by: '<S528>/volc_flg_VCU_DTE_ovrdflg' */

/* Override flag for signal b_VCU_DTE */
extern const volatile boolean volc_b_VCU_DischargeEnable_ovrdflg;
              /* Referenced by: '<S397>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_VCU_DriveCircuitTemp_ovrdflg;
               /* Referenced by: '<S392>/volc_b_VCU_DriveCircuitTemp_ovrdflg' */

/* Override flag for signal b_VCU_DriveCircuitTemp */
extern const volatile boolean volc_b_VCU_DriveCircuitVol_ovrdflg;
                /* Referenced by: '<S603>/volc_b_VCU_DriveCircuitVol_ovrdflg' */

/* Override flag for signal b_VCU_DriveCircuitVol */
extern const volatile boolean volc_b_VCU_DriveModeInd_ovrdflg;
                 /* Referenced by: '<S642>/volc_flg_VCU_DriveModeInd_ovrdflg' */

/* Override flag for signal b_VCU_DriveModeInd */
extern const volatile boolean volc_b_VCU_DrivePwrCircuitInd_ovrdflg;
           /* Referenced by: '<S643>/volc_flg_VCU_DrivePwrCircuitInd_ovrdflg' */

/* Override flag for signal b_VCU_DrivePwrCircuitInd */
extern const volatile boolean volc_b_VCU_DriveReqTrqPercent_ovrdflg;
             /* Referenced by: '<S488>/volc_b_VCU_DriveReqTrqPercent_ovrdflg' */

/* Override flag for signal VCU_DriveReqTrqPercent */
extern const volatile boolean volc_b_VCU_DriverOperationReminder_ovrdflg;
      /* Referenced by: '<S458>/volc_flg_VCU_DriverOperationReminder_ovrdflg' */

/* Override flag for signal b_VCU_DriverOperationReminder */
extern const volatile boolean volc_b_VCU_DrivingTakeForceSts_ovrdflg;
            /* Referenced by: '<S871>/volc_b_VCU_DrivingTakeForceSts_ovrdflg' */

/* Override flag for signal VCU_DrivingTakeForceSts */
extern const volatile boolean volc_b_VCU_ECOMode_invert;
                         /* Referenced by: '<S570>/volc_b_VCU_ECOMode_invert' */

/* Invert flag for signal b_VCU_ECOMode */
extern const volatile boolean volc_b_VCU_ECOMode_ovrdflg;
                        /* Referenced by: '<S570>/volc_b_VCU_ECOMode_ovrdflg' */

/* Override flag for signal b_VCU_ECOMode */
extern const volatile boolean volc_b_VCU_ECOmodeSWILED_Ctrl_ovrdflg;
             /* Referenced by: '<S272>/volc_b_VCU_ECOmodeSWILED_Ctrl_ovrdflg' */

/* Override flag for signal VCU_ECOmodeSWILED_Ctrl */
extern const volatile boolean volc_b_VCU_ECPM_FaultFB_ovrdflg;
                   /* Referenced by: '<S273>/volc_b_VCU_ECPM_FaultFB_ovrdflg' */

/* Override flag for signal VCU_ECPM_FaultFB */
extern const volatile boolean volc_b_VCU_EDCP_Enable_invert;
                     /* Referenced by: '<S875>/volc_b_VCU_HVBC_Enable_invert' */

/* Invert flag for signal VCU_EDCP_Enable */
extern const volatile boolean volc_b_VCU_EDCP_Enable_ovrdflg;
                    /* Referenced by: '<S875>/volc_b_VCU_HVBC_Enable_ovrdflg' */

/* Override flag for signal VCU_EDCP_Enable */
extern const volatile boolean volc_b_VCU_EDCP_FaultFB_ovrdflg;
                   /* Referenced by: '<S274>/volc_b_VCU_EDCP_FaultFB_ovrdflg' */

/* Override flag for signal VCU_EDCP_FaultFB */
extern const volatile boolean volc_b_VCU_EDCP_PWMCtrl_ovrdflg;
                /* Referenced by: '<S876>/volc_b_VCU_HVBC_COpenValue_ovrdflg' */

/* Override flag for signal VCU_EDCP_PWMCtrl */
extern const volatile boolean volc_b_VCU_EM1CtrlMode_ovrdflg;
                    /* Referenced by: '<S489>/volc_b_VCU_EM1CtrlMode_ovrdflg' */
extern const volatile boolean volc_b_VCU_EM1WorkMode_ovrdflg;
                    /* Referenced by: '<S490>/volc_b_VCU_EM1WorkMode_ovrdflg' */
extern const volatile boolean volc_b_VCU_EMCtrlMode_ovrdflg;
                   /* Referenced by: '<S491>/volc_flg_VCU_EMCtrlMode_ovrdflg' */

/* Override flag for signal b_VCU_EMCtrlMode */
extern const volatile boolean volc_b_VCU_EMWorkMode_ovrdflg;
                   /* Referenced by: '<S492>/volc_flg_VCU_EMWorkMode_ovrdflg' */

/* Override flag for signal b_VCU_EMWorkMode */
extern const volatile boolean volc_b_VCU_EManualStartSwi_ovrdflg;
                /* Referenced by: '<S588>/volc_b_VCU_EManualStartSwi_ovrdflg' */

/* Override flag for signal b_VCU_EManualStartSwi */
extern const volatile boolean volc_b_VCU_EVDTEodometer_ovrdflg;
                  /* Referenced by: '<S275>/volc_b_VCU_EVDTEodometer_ovrdflg' */

/* Override flag for signal VCU_EVDTEodometer */
extern const volatile boolean volc_b_VCU_EV_Switch_ovrdflg;
              /* Referenced by: '<S680>/volc_b_VCU_BattHeatVal2_FBV6_ovrdflg' */

/* Override flag for signal VCU_EV_Switch */
extern const volatile boolean volc_b_VCU_EVanualStartSwi_ovrdflg;
                /* Referenced by: '<S644>/volc_b_VCU_EVanualStartSwi_ovrdflg' */

/* Override flag for signal VCU_EVanualStartSwi */
extern const volatile boolean volc_b_VCU_EmergencyStop_ovrdflg;
                  /* Referenced by: '<S594>/volc_b_VCU_EmergencyStop_ovrdflg' */

/* Override flag for signal b_VCU_EmergencyStop */
extern const volatile boolean volc_b_VCU_EngFuelInstCons_ovrdflg;
                /* Referenced by: '<S347>/volc_b_VCU_EngFuelInstCons_ovrdflg' */

/* Override flag for signal VCU_EngFuelInstCons */
extern const volatile boolean volc_b_VCU_ErrCode_ovrdflg;
                      /* Referenced by: '<S529>/volc_flg_VCU_ErrCode_ovrdflg' */

/* Override flag for signal b_VCU_ErrCode */
extern const volatile boolean volc_b_VCU_ExternalAccDemand_ovrdflg;
            /* Referenced by: '<S315>/volc_flg_VCU_ExternalAccDemand_ovrdflg' */

/* Override flag for signal VCU_ExternalAccDemand */
extern const volatile boolean volc_b_VCU_FanPWM_Ctrl_ovrdflg;
               /* Referenced by: '<S681>/volc_b_VCU_HTCoolingFanCtrl_ovrdflg' */

/* Override flag for signal VCU_FanPWM_Ctrl */
extern const volatile boolean volc_b_VCU_FuleDTEodometer_ovrdflg;
                /* Referenced by: '<S276>/volc_b_VCU_FuleDTEodometer_ovrdflg' */

/* Override flag for signal VCU_FuleDTEodometer */
extern const volatile boolean volc_b_VCU_FunAnti_DismantleActive_ovrdflg;
        /* Referenced by: '<S604>/volc_b_VCU_FunAnti_DismantleActive_ovrdflg' */

/* Override flag for signal VCU_FunAnti_DismantleActive */
extern const volatile boolean volc_b_VCU_FunLockVehActive_ovrdflg;
               /* Referenced by: '<S605>/volc_b_VCU_FunLockVehActive_ovrdflg' */

/* Override flag for signal VCU_FunLockVehActive */
extern const volatile boolean volc_b_VCU_GP_Override_ovrdflg;
                    /* Referenced by: '<S316>/volc_b_VCU_GP_Override_ovrdflg' */

/* Override flag for signal VCU_GP_Override */
extern const volatile boolean volc_b_VCU_GearOperateErr_ovrdflg;
               /* Referenced by: '<S645>/volc_flg_VCU_GearOperateErr_ovrdflg' */

/* Override flag for signal b_VCU_GearOperateErr */
extern const volatile boolean volc_b_VCU_GearPositionInd_ovrdflg;
              /* Referenced by: '<S646>/volc_flg_VCU_GearPositionInd_ovrdflg' */

/* Override flag for signal b_VCU_GearPositionInd */
extern const volatile boolean volc_b_VCU_GearPositionInput_ovrdflg;
              /* Referenced by: '<S595>/volc_b_VCU_GearPositionInput_ovrdflg' */

/* Override flag for signal b_VCU_GearPositionInput */
extern const volatile boolean volc_b_VCU_Gearshift_Resp_ovrdflg;
                 /* Referenced by: '<S872>/volc_b_VCU_Gearshift_Resp_ovrdflg' */

/* Override flag for signal VCU_Gearshift_Resp */
extern const volatile boolean volc_b_VCU_HBCP_Enable_invert;
                      /* Referenced by: '<S877>/volc_b_VCU_ICE_Enable_invert' */

/* Invert flag for signal VCU_HBCP_Enable */
extern const volatile boolean volc_b_VCU_HBCP_Enable_ovrdflg;
                     /* Referenced by: '<S877>/volc_b_VCU_ICE_Enable_ovrdflg' */

/* Override flag for signal VCU_HBCP_Enable */
extern const volatile boolean volc_b_VCU_HBCP_FaultFB_ovrdflg;
                   /* Referenced by: '<S277>/volc_b_VCU_HBCP_FaultFB_ovrdflg' */

/* Override flag for signal VCU_HBCP_FaultFB */
extern const volatile boolean volc_b_VCU_HBCP_PWMCtrl_ovrdflg;
                /* Referenced by: '<S878>/volc_b_VCU_HVBC_BOpenValue_ovrdflg' */

/* Override flag for signal VCU_HBCP_PWMCtrl */
extern const volatile boolean volc_b_VCU_HTCoolingFan1FB_ovrdflg;
                /* Referenced by: '<S278>/volc_b_VCU_HTCoolingFan1FB_ovrdflg' */

/* Override flag for signal VCU_HTCoolingFan1FB */
extern const volatile boolean volc_b_VCU_HVB_PumpFb_ovrdflg;
                     /* Referenced by: '<S589>/volc_b_VCU_HVB_PumpFb_ovrdflg' */

/* Override flag for signal b_VCU_HVB_PumpFb */
extern const volatile boolean volc_b_VCU_HVILReturn_ovrdflg;
                     /* Referenced by: '<S596>/volc_b_VCU_HVILReturn_ovrdflg' */

/* Override flag for signal b_VCU_HVILReturn */
extern const volatile boolean volc_b_VCU_HVOnOffReq_ovrdflg;
                   /* Referenced by: '<S348>/volc_flg_VCU_HVOnOffReq_ovrdflg' */

/* Override flag for signal VCU_HVOnOffReq */
extern const volatile boolean volc_b_VCU_HVPRASts_ovrdflg;
                     /* Referenced by: '<S571>/volc_b_VCU_ACC2PosVol_ovrdflg' */

/* Override flag for signal VCU_HVBVarCtrl */
extern const volatile boolean volc_b_VCU_HV_Status_ovrdflg;
                      /* Referenced by: '<S279>/volc_b_VCU_HV_Status_ovrdflg' */

/* Override flag for signal VCU_HV_Status */
extern const volatile boolean volc_b_VCU_HandbrakeSts2_ovrdflg;
                /* Referenced by: '<S459>/volc_flg_VCU_HandbrakeSts2_ovrdflg' */

/* Override flag for signal b_VCU_HandbrakeSts2 */
extern const volatile boolean volc_b_VCU_HandbrakeSts_ovrdflg;
                 /* Referenced by: '<S647>/volc_flg_VCU_HandbrakeSts_ovrdflg' */

/* Override flag for signal b_VCU_HandbrakeSts */
extern const volatile boolean volc_b_VCU_HardwareMajorVer_ovrdflg;
             /* Referenced by: '<S697>/volc_flg_VCU_HardwareMajorVer_ovrdflg' */

/* Override flag for signal b_VCU_HardwareMajorVer */
extern const volatile boolean volc_b_VCU_HardwareMinorVer_ovrdflg;
             /* Referenced by: '<S698>/volc_flg_VCU_HardwareMinorVer_ovrdflg' */

/* Override flag for signal b_VCU_HardwareMinorVer */
extern const volatile boolean volc_b_VCU_HazardReq_ovrdflg;
                      /* Referenced by: '<S541>/volc_b_VCU_HazardReq_ovrdflg' */

/* Override flag for signal VCU_HazardReq */
extern const volatile boolean volc_b_VCU_HazardReq_ovrdval;
                      /* Referenced by: '<S541>/volc_b_VCU_HazardReq_ovrdval' */

/* Override value for signal VCU_HazardReq */
extern const volatile boolean volc_b_VCU_HybridReady_ovrdflg;
                    /* Referenced by: '<S349>/volc_b_VCU_HybridReady_ovrdflg' */

/* Override flag for signal VCU_HybridReady */
extern const volatile boolean volc_b_VCU_Idle_Switch_ovrdflg;
              /* Referenced by: '<S682>/volc_b_VCU_BattCoolVal3_FBV5_ovrdflg' */

/* Override flag for signal VCU_Idle_Switch */
extern const volatile boolean volc_b_VCU_IgnONSts_invert;
                        /* Referenced by: '<S572>/volc_b_VCU_IgnONSts_invert' */

/* Invert flag for signal b_VCU_IgnONSts */
extern const volatile boolean volc_b_VCU_IgnONSts_ovrdflg;
                       /* Referenced by: '<S572>/volc_b_VCU_IgnONSts_ovrdflg' */

/* Override flag for signal b_VCU_IgnONSts */
extern const volatile boolean volc_b_VCU_IgniteSts_ovrdflg;
                    /* Referenced by: '<S648>/volc_flg_VCU_IgniteSts_ovrdflg' */

/* Override flag for signal b_VCU_IgniteSts */
extern const volatile boolean volc_b_VCU_InhibitHybrid_Switch_ovrdflg;
              /* Referenced by: '<S683>/volc_b_VCU_BattHeatVal2_FBV5_ovrdflg' */

/* Override flag for signal VCU_InhibitHybrid_Switch */
extern const volatile boolean volc_b_VCU_IntelLockLoopSts_ovrdflg;
               /* Referenced by: '<S542>/volc_b_VCU_IntelLockLoopSts_ovrdflg' */

/* Override flag for signal VCU_IntelLockLoopSts */
extern const volatile boolean volc_b_VCU_IntelligentChargeExitReq_ovrdflg;
       /* Referenced by: '<S280>/volc_b_VCU_IntelligentChargeExitReq_ovrdflg' */

/* Override flag for signal VCU_IntelligentChargeExitReq */
extern const volatile boolean volc_b_VCU_IntelligentChargeQuit_ovrdflg;
          /* Referenced by: '<S281>/volc_b_VCU_IntelligentChargeQuit_ovrdflg' */

/* Override flag for signal VCU_IntelligentChargeQuit */
extern const volatile boolean volc_b_VCU_IntelligentChargeState_ovrdflg;
         /* Referenced by: '<S282>/volc_b_VCU_IntelligentChargeState_ovrdflg' */

/* Override flag for signal VCU_IntelligentChargeState */
extern const volatile boolean volc_b_VCU_LTCoolingFan2FB_ovrdflg;
                /* Referenced by: '<S283>/volc_b_VCU_LTCoolingFan2FB_ovrdflg' */

/* Override flag for signal VCU_LTCoolingFan2FB */
extern const volatile boolean volc_b_VCU_LockLimResult_ovrdflg;
                  /* Referenced by: '<S606>/volc_b_VCU_LockLimResult_ovrdflg' */

/* Override flag for signal VCU_LockLimResult */
extern const volatile boolean volc_b_VCU_LockVehSts_ovrdflg;
                     /* Referenced by: '<S607>/volc_b_VCU_LockVehSts_ovrdflg' */

/* Override flag for signal VCU_LockVehSts */
extern const volatile boolean volc_b_VCU_LockVehType_ovrdflg;
                    /* Referenced by: '<S608>/volc_b_VCU_LockVehType_ovrdflg' */

/* Override flag for signal VCU_LockVehType */
extern const volatile boolean volc_b_VCU_MCU1EnableReq_ovrdflg;
                /* Referenced by: '<S493>/volc_flg_VCU_MCU1EnableReq_ovrdflg' */
extern const volatile boolean volc_b_VCU_MCUActiveDischg_ovrdflg;
              /* Referenced by: '<S350>/volc_flg_VCU_MCUActiveDischg_ovrdflg' */

/* Override flag for signal VCU_MCUActiveDischg */
extern const volatile boolean volc_b_VCU_MCUEnableReq_ovrdflg;
                 /* Referenced by: '<S494>/volc_flg_VCU_MCUEnableReq_ovrdflg' */

/* Override flag for signal b_VCU_MCUEnableReq */
extern const volatile boolean volc_b_VCU_MCUMaxTrq_ovrdflg;
                      /* Referenced by: '<S495>/volc_b_VCU_MCUMaxTrq_ovrdflg' */

/* Override flag for signal VCU_MCUMaxTrq */
extern const volatile boolean volc_b_VCU_MCUSpdRampRate_ovrdflg;
               /* Referenced by: '<S496>/volc_flg_VCU_MCUSpdRampRate_ovrdflg' */

/* Override flag for signal VCU_MCUSpdRampRate */
extern const volatile boolean volc_b_VCU_MCUTqRampRate_ovrdflg;
                /* Referenced by: '<S497>/volc_flg_VCU_MCUTqRampRate_ovrdflg' */

/* Override flag for signal VCU_MCUTqRampRate */
extern const volatile boolean volc_b_VCU_MCU_MotorActTrqPercent_ovrdflg;
         /* Referenced by: '<S498>/volc_b_VCU_MCU_MotorActTrqPercent_ovrdflg' */

/* Override flag for signal VCU_MCU_MotorActTrqPercent */
extern const volatile boolean volc_b_VCU_MCU_PumpPWM_Ctrl_ovrdflg;
             /* Referenced by: '<S684>/volc_b_VCU_CabinLoopVal2_FBV5_ovrdflg' */

/* Override flag for signal VCU_MCU_PumpPWM_Ctrl */
extern const volatile boolean volc_b_VCU_MCU_RelayCtrl_Ctrl_ovrdflg;
               /* Referenced by: '<S685>/volc_b_VCU_HTCoolingFanCtrl_ovrdflg' */

/* Override flag for signal VCU_MCU_RelayCtrl_Ctrl */
extern const volatile boolean volc_b_VCU_MILTelltale_ovrdflg;
                    /* Referenced by: '<S628>/volc_b_VCU_MILTelltale_ovrdflg' */

/* Override flag for signal VCU_MILTelltale */
extern const volatile boolean volc_b_VCU_MainPosCtrlCommand_ovrdflg;
           /* Referenced by: '<S543>/volc_flg_VCU_MainPosCtrlCommand_ovrdflg' */

/* Override flag for signal b_VCU_MainPosCtrlCommand */
extern const volatile boolean volc_b_VCU_Main_Contactor_Control_ovrdflg;
       /* Referenced by: '<S351>/volc_flg_VCU_Main_Contactor_Control_ovrdflg' */

/* Override flag for signal VCU_Main_Contactor_Control */
extern const volatile boolean volc_b_VCU_MaxEMPwrLmt_ovrdflg;
                  /* Referenced by: '<S499>/volc_flg_VCU_MaxEMPwrLmt_ovrdflg' */

/* Override flag for signal b_VCU_MaxEMPwrLmt */
extern const volatile boolean volc_b_VCU_MinEMPwrLmt_ovrdflg;
                  /* Referenced by: '<S500>/volc_flg_VCU_MinEMPwrLmt_ovrdflg' */

/* Override flag for signal b_VCU_MinEMPwrLmt */
extern const volatile boolean volc_b_VCU_MotorSpeed_ovrdflg;
                   /* Referenced by: '<S501>/volc_flg_VCU_MotorSpeed_ovrdflg' */

/* Override flag for signal VCU_MotorSpeed */
extern const volatile boolean volc_b_VCU_MotorTorque_ovrdflg;
                  /* Referenced by: '<S502>/volc_flg_VCU_MotorTorque_ovrdflg' */

/* Override flag for signal VCU_MotorTorque */
extern const volatile boolean volc_b_VCU_NMSts_ovrdflg;
                /* Referenced by: '<S616>/volc_b_VCU_DTCClearInhibit_ovrdflg' */

/* Override flag for signal VCU_NMSts */
extern const volatile boolean volc_b_VCU_Oil_HV_OFF_ovrdflg;
                /* Referenced by: '<S870>/volc_b_VCU_HVBC_COpenValue_ovrdflg' */

/* Override flag for signal VCU_Oil_HV_OFF */
extern const volatile boolean volc_b_VCU_OverloadInd_ovrdflg;
                    /* Referenced by: '<S863>/volc_b_VCU_OverloadInd_ovrdflg' */

/* Override flag for signal VCU_OverloadInd */
extern const volatile boolean volc_b_VCU_PMS_APPowerActual_EV_ovrdflg;
         /* Referenced by: '<S413>/volc_flg_VCU_PMS_APPowerActual_EV_ovrdflg' */
extern const volatile boolean volc_b_VCU_PTC2Enable_ovrdflg;
              /* Referenced by: '<S394>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_VCU_PTC3Enable_ovrdflg;
              /* Referenced by: '<S395>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_VCU_PTCEnable_ovrdflg;
                      /* Referenced by: '<S414>/volc_b_VCU_PTCEnable_ovrdflg' */

/* Override flag for signal PTCEnable */
extern const volatile boolean volc_b_VCU_PTHVSysErrorLampStsInd_ovrdflg;
       /* Referenced by: '<S649>/volc_flg_VCU_PTHVSysErrorLampStsInd_ovrdflg' */

/* Override flag for signal b_VCU_PTHVSysErrorLampStsInd */
extern const volatile boolean volc_b_VCU_PTModeInd_ovrdflg;
                    /* Referenced by: '<S650>/volc_flg_VCU_PTModeInd_ovrdflg' */

/* Override flag for signal b_VCU_PTModeInd */
extern const volatile boolean volc_b_VCU_PTReadyInd_ovrdflg;
                   /* Referenced by: '<S651>/volc_flg_VCU_PTReadyInd_ovrdflg' */

/* Override flag for signal b_VCU_PTReadyInd */
extern const volatile boolean volc_b_VCU_PTResiPwr_ovrdflg;
                      /* Referenced by: '<S530>/volc_b_VCU_PTResiPwr_ovrdflg' */

/* Override flag for signal VCU_PTResiPwr */
extern const volatile boolean volc_b_VCU_PTSysElecPwrInd_ovrdflg;
              /* Referenced by: '<S652>/volc_flg_VCU_PTSysElecPwrInd_ovrdflg' */

/* Override flag for signal b_VCU_PTSysElecPwrInd */
extern const volatile boolean volc_b_VCU_PreRelay_Ctrl_ovrdflg;
              /* Referenced by: '<S686>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */

/* Override flag for signal VCU_PreRelay_Ctrl */
extern const volatile boolean volc_b_VCU_PressureSwi1Sts_ovrdflg;
                /* Referenced by: '<S590>/volc_b_VCU_PressureSwi1Sts_ovrdflg' */

/* Override flag for signal b_VCU_PressureSwi1Sts */
extern const volatile boolean volc_b_VCU_PressureSwi2Sts_ovrdflg;
                /* Referenced by: '<S591>/volc_b_VCU_PressureSwi2Sts_ovrdflg' */

/* Override flag for signal b_VCU_PressureSwi2Sts */
extern const volatile boolean volc_b_VCU_PropulSysActive_ovrdflg;
                /* Referenced by: '<S284>/volc_b_VCU_PropulSysActive_ovrdflg' */

/* Override flag for signal VCU_PropulSysActive */
extern const volatile boolean volc_b_VCU_QuitControlSpeed_ovrdflg;
             /* Referenced by: '<S480>/volc_flg_VCU_QuitControlSpeed_ovrdflg' */

/* Override flag for signal VCU_QuitControlSpeed */
extern const volatile boolean volc_b_VCU_RMR_ovrdflg;
                /* Referenced by: '<S617>/volc_flg_VCU_AccePedalPosD_ovrdflg' */

/* Override flag for signal VCU_RMR */
extern const volatile boolean volc_b_VCU_RelayCtrl_Ctrl_ovrdflg;
               /* Referenced by: '<S687>/volc_b_VCU_HTCoolingFanCtrl_ovrdflg' */

/* Override flag for signal VCU_RelayCtrl_Ctrl */
extern const volatile boolean volc_b_VCU_ReqSpdOrLmt_ovrdflg;
                  /* Referenced by: '<S503>/volc_flg_VCU_ReqSpdOrLmt_ovrdflg' */

/* Override flag for signal b_VCU_ReqSpdOrLmt */
extern const volatile boolean volc_b_VCU_ReqTrqOrLmt_ovrdflg;
                  /* Referenced by: '<S504>/volc_flg_VCU_ReqTrqOrLmt_ovrdflg' */

/* Override flag for signal b_VCU_ReqTrqOrLmt */
extern const volatile boolean volc_b_VCU_SDCACOutFreq_ovrdflg;
                 /* Referenced by: '<S544>/volc_flg_VCU_SDCACOutFreq_ovrdflg' */

/* Override flag for signal b_VCU_SDCACOutFreq */
extern const volatile boolean volc_b_VCU_SDCACStopFault_ovrdflg;
                 /* Referenced by: '<S545>/volc_b_VCU_SDCACStopFault_ovrdflg' */

/* Override flag for signal VCU_SDCACStopFault */
extern const volatile boolean volc_b_VCU_SDCACStopFault_ovrdval;
                 /* Referenced by: '<S545>/volc_b_VCU_SDCACStopFault_ovrdval' */

/* Override value for signal VCU_SDCACStopFault */
extern const volatile boolean volc_b_VCU_SWCompileDay_ovrdflg;
                 /* Referenced by: '<S699>/volc_flg_VCU_SWCompileDay_ovrdflg' */

/* Override flag for signal b_VCU_SWCompileDay */
extern const volatile boolean volc_b_VCU_SWCompileMonth_ovrdflg;
               /* Referenced by: '<S700>/volc_flg_VCU_SWCompileMonth_ovrdflg' */

/* Override flag for signal b_VCU_SWCompileMonth */
extern const volatile boolean volc_b_VCU_SWCompileYear_ovrdflg;
                /* Referenced by: '<S701>/volc_flg_VCU_SWCompileYear_ovrdflg' */

/* Override flag for signal b_VCU_SWCompileYear */
extern const volatile boolean volc_b_VCU_SelfCheckSts_ovrdflg;
                 /* Referenced by: '<S546>/volc_flg_VCU_SelfCheckSts_ovrdflg' */

/* Override flag for signal b_VCU_SelfCheckSts */
extern const volatile boolean volc_b_VCU_Set_Temp_ovrdflg;
                     /* Referenced by: '<S352>/volc_flg_VCU_Set_Temp_ovrdflg' */

/* Override flag for signal VCU_Set_Temp */
extern const volatile boolean volc_b_VCU_ShiftClimbing_invert;
                         /* Referenced by: '<S573>/volc_b_VCU_ECOMode_invert' */

/* Invert flag for signal VCU_ShiftClimbing */
extern const volatile boolean volc_b_VCU_ShiftClimbing_ovrdflg;
                        /* Referenced by: '<S573>/volc_b_VCU_ECOMode_ovrdflg' */

/* Override flag for signal VCU_ShiftClimbing */
extern const volatile boolean volc_b_VCU_ShiftD_invert;
                        /* Referenced by: '<S574>/volc_b_VCU_StartSts_invert' */

/* Invert flag for signal VCU_ShiftD */
extern const volatile boolean volc_b_VCU_ShiftD_ovrdflg;
                       /* Referenced by: '<S574>/volc_b_VCU_StartSts_ovrdflg' */

/* Override flag for signal VCU_ShiftD */
extern const volatile boolean volc_b_VCU_ShiftR_invert;
                        /* Referenced by: '<S575>/volc_b_VCU_StartSts_invert' */

/* Invert flag for signal VCU_ShiftR */
extern const volatile boolean volc_b_VCU_ShiftR_ovrdflg;
                       /* Referenced by: '<S575>/volc_b_VCU_StartSts_ovrdflg' */

/* Override flag for signal VCU_ShiftR */
extern const volatile boolean volc_b_VCU_SoftwareMajorVer_ovrdflg;
             /* Referenced by: '<S702>/volc_flg_VCU_SoftwareMajorVer_ovrdflg' */

/* Override flag for signal b_VCU_SoftwareMajorVer */
extern const volatile boolean volc_b_VCU_SoftwareMinorVer_ovrdflg;
             /* Referenced by: '<S703>/volc_flg_VCU_SoftwareMinorVer_ovrdflg' */

/* Override flag for signal b_VCU_SoftwareMinorVer */
extern const volatile boolean volc_b_VCU_StartSts_invert;
                        /* Referenced by: '<S576>/volc_b_VCU_StartSts_invert' */

/* Invert flag for signal b_VCU_StartSts */
extern const volatile boolean volc_b_VCU_StartSts_ovrdflg;
                       /* Referenced by: '<S576>/volc_b_VCU_StartSts_ovrdflg' */

/* Override flag for signal b_VCU_StartSts */
extern const volatile boolean volc_b_VCU_Stayawake_reasons_ovrdflg;
                /* Referenced by: '<S618>/volc_flg_VCU_AccePedalPosE_ovrdflg' */

/* Override flag for signal VCU_Stayawake_reasons */
extern const volatile boolean volc_b_VCU_StsBrkSwitch1Invalid_ovrdflg;
         /* Referenced by: '<S460>/volc_flg_VCU_StsBrkSwitch1Invalid_ovrdflg' */
extern const volatile boolean volc_b_VCU_TotalOdometerInvalid_ovrdflg;
           /* Referenced by: '<S630>/volc_b_VCU_TotalOdometerInvalid_ovrdflg' */

/* Override flag for signal VCU_TotalOdometerInvalid */
extern const volatile boolean volc_b_VCU_TotalOdometer_ovrdflg;
                  /* Referenced by: '<S629>/volc_b_VCU_TotalOdometer_ovrdflg' */

/* Override flag for signal VCU_TotalOdometer */
extern const volatile boolean volc_b_VCU_TurtleLampReq_ovrdflg;
                /* Referenced by: '<S653>/volc_flg_VCU_TurtleLampReq_ovrdflg' */

/* Override flag for signal b_VCU_TurtleLampReq */
extern const volatile boolean volc_b_VCU_VLC_Active_ovrdflg;
                     /* Referenced by: '<S317>/volc_b_VCU_VLC_Active_ovrdflg' */

/* Override flag for signal VCU_VLC_Active */
extern const volatile boolean volc_b_VCU_VLC_Available_ovrdflg;
                  /* Referenced by: '<S318>/volc_b_VCU_VLC_Available_ovrdflg' */

/* Override flag for signal VCU_VLC_Available */
extern const volatile boolean volc_b_VCU_VLC_InternalTargetACCeleration_ovrdflg;
/* Referenced by: '<S319>/volc_b_VCU_VLC_InternalTargetACCeleration_ovrdflg' */

/* Override flag for signal VCU_VLC_InternalTargetACCeleration */
extern const volatile boolean volc_b_VCU_VLC_VCUTargetACCeleration_ovrdflg;
      /* Referenced by: '<S320>/volc_b_VCU_VLC_VCUTargetACCeleration_ovrdflg' */

/* Override flag for signal VCU_VLC_VCUTargetACCeleration */
extern const volatile boolean volc_b_VCU_VehCruisingDistance_ovrdflg;
              /* Referenced by: '<S688>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */

/* Override flag for signal VCU_VehCruisingDistance */
extern const volatile boolean volc_b_VCU_VehicleAbnormalSts_ovrdflg;
           /* Referenced by: '<S654>/volc_flg_VCU_VehicleAbnormalSts_ovrdflg' */

/* Override flag for signal b_VCU_VehicleAbnormalSts */
extern const volatile boolean volc_b_VCU_VehicleIdentification_ovrdflg;
        /* Referenced by: '<S689>/volc_flg_VCU_VehicleIdentification_ovrdflg' */

/* Override flag for signal b_VCU_VehicleIdentification */
extern const volatile boolean volc_b_VCU_VehicleRunMode_ovrdflg;
               /* Referenced by: '<S655>/volc_flg_VCU_VehicleRunMode_ovrdflg' */

/* Override flag for signal b_VCU_VehicleRunMode */
extern const volatile boolean volc_b_VCU_VehicleSlipWarning_ovrdflg;
                   /* Referenced by: '<S656>/volc_flg_VCU_VehicleSlipWarning' */

/* Override flag for signal b_VCU_VehicleSlipWarning */
extern const volatile boolean volc_b_VCU_VehicleSpd_flag_ovrdflg;
              /* Referenced by: '<S462>/volc_flg_VCU_VehicleSpd_flag_ovrdflg' */

/* Override flag for signal VCU_VehicleSpd_flag */
extern const volatile boolean volc_b_VCU_VehicleSpd_ovrdflg;
                   /* Referenced by: '<S461>/volc_flg_VCU_VehicleSpd_ovrdflg' */

/* Override flag for signal b_VCU_VehicleSpd */
extern const volatile boolean volc_b_VCU_VehicleSubSysErrorLevel_ovrdflg;
        /* Referenced by: '<S657>/volc_b_VCU_VehicleSubSysErrorLevel_ovrdflg' */

/* Override flag for signal VCU_VehicleSubSysErrorLevel */
extern const volatile boolean volc_b_VCU_VehicleSysErrorLevel_ovrdflg;
         /* Referenced by: '<S658>/volc_flg_VCU_VehicleSysErrorLevel_ovrdflg' */

/* Override flag for signal b_VCU_VehicleSysErrorLevel */
extern const volatile boolean volc_b_VCU_VehicleSysFltLevel_ovrdflg;
           /* Referenced by: '<S636>/volc_flg_VCU_VehicleSysFltLevel_ovrdflg' */

/* Override flag for signal b_VCU_VehicleSysFltLevel */
extern const volatile boolean volc_b_VCU_VehicleWeight_ovrdflg;
                  /* Referenced by: '<S864>/volc_b_VCU_VehicleWeight_ovrdflg' */

/* Override flag for signal VCU_VehicleWeight */
extern const volatile boolean volc_b_VCU_WPCtrl_ovrdflg;
                         /* Referenced by: '<S415>/volc_b_VCU_WPCtrl_ovrdflg' */

/* Override flag for signal WPCtrl */
extern const volatile boolean volc_b_VCU_Wakeup_reasons_ovrdflg;
                /* Referenced by: '<S619>/volc_b_VCU_DTCClearInhibit_ovrdflg' */

/* Override flag for signal VCU_Wakeup_reasons */
extern const volatile boolean volc_b_VCU_XBRControlMode_ovrdflg;
               /* Referenced by: '<S321>/volc_flg_VCU_XBRControlMode_ovrdflg' */

/* Override flag for signal VCU_XBRControlMode */
extern const volatile boolean volc_b_VCU_XBREBIMode_ovrdflg;
                     /* Referenced by: '<S322>/volc_b_VCU_XBREBIMode_ovrdflg' */

/* Override flag for signal VCU_XBREBIMode */
extern const volatile boolean volc_b_VCU_XBRPriority_ovrdflg;
                  /* Referenced by: '<S323>/volc_flg_VCU_XBRPriority_ovrdflg' */

/* Override flag for signal VCU_XBRPriority */
extern const volatile boolean volc_b_VCU_ZeroPwr_Fb_ovrdflg;
              /* Referenced by: '<S396>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_VCU_bmsModeStsReq_ovrdflg;
                  /* Referenced by: '<S547>/volc_b_VCU_bmsModeStsReq_ovrdflg' */
extern const volatile boolean volc_b_VCU_bmshAlwChgCurrMax_ovrdflg;
              /* Referenced by: '<S399>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_VCU_ePTRegencyLevInd_ovrdflg;
              /* Referenced by: '<S717>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
extern const volatile boolean volc_b_VCU_ePTReleaseSig_ovrdflg;
                  /* Referenced by: '<S285>/volc_b_VCU_ePTReleaseSig_ovrdflg' */

/* Override flag for signal VCU_ePTReleaseSig */
extern const volatile boolean volc_b_VacPumpRlyEn_invert;
                         /* Referenced by: '<S191>/volc_b_cntnrPwrEna_invert' */
extern const volatile boolean volc_b_VacPumpRlyEn_ovrdflg;
                        /* Referenced by: '<S191>/volc_b_cntnrPwrEna_ovrdflg' */
extern const volatile boolean volc_b_VacPumpRlyEn_ovrdval;
                        /* Referenced by: '<S191>/volc_b_cntnrPwrEna_ovrdval' */
extern const volatile boolean volc_b_acHvilDtyOutpt_ovrdflg;
                   /* Referenced by: '<S184>/volc_flg_acHvilDtyOutpt_ovrdflg' */
extern const volatile boolean volc_b_acHvilPrdOutpt_ovrdflg;
                   /* Referenced by: '<S185>/volc_flg_acHvilPrdOutpt_ovrdflg' */
extern const volatile boolean volc_b_accyPreRlyCmd_invert;
                         /* Referenced by: '<S192>/volc_b_cntnrPwrEna_invert' */
extern const volatile boolean volc_b_accyPreRlyCmd_ovrdflg;
                        /* Referenced by: '<S192>/volc_b_cntnrPwrEna_ovrdflg' */
extern const volatile boolean volc_b_accyPreRlyCmd_ovrdval;
                        /* Referenced by: '<S192>/volc_b_cntnrPwrEna_ovrdval' */
extern const volatile boolean volc_b_brkPmpEn_invert;
                            /* Referenced by: '<S201>/volc_b_brkPmpEn_invert' */

/* Invert flag for signal b_brkPmpEn */
extern const volatile boolean volc_b_brkPmpEn_ovrdflg;
                           /* Referenced by: '<S201>/volc_b_brkPmpEn_ovrdflg' */

/* Override flag for signal b_brkPmpEn */
extern const volatile boolean volc_b_cntnrCtrlEna_invert;
                         /* Referenced by: '<S193>/volc_b_cntnrPwrEna_invert' */

/* Invert flag for signal b_cntnrCtrlEna */
extern const volatile boolean volc_b_cntnrCtrlEna_ovrdflg;
                        /* Referenced by: '<S193>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal b_cntnrCtrlEna */
extern const volatile boolean volc_b_cntnrCtrlEna_ovrdval;
                        /* Referenced by: '<S193>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal b_cntnrCtrlEna */
extern const volatile boolean volc_b_cntnrPwrEna_invert;
                         /* Referenced by: '<S194>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal cntnrPwrEna */
extern const volatile boolean volc_b_cntnrPwrEna_ovrdflg;
                        /* Referenced by: '<S194>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal cntnrPwrEna */
extern const volatile boolean volc_b_cntnrPwrEna_ovrdval;
                        /* Referenced by: '<S194>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal cntnrPwrEna */
extern const volatile boolean volc_b_emergStopEn_invert;
                         /* Referenced by: '<S202>/volc_b_emergStopEn_invert' */

/* Invert flag for signal b_emergStopEn */
extern const volatile boolean volc_b_emergStopEn_ovrdflg;
                        /* Referenced by: '<S202>/volc_b_emergStopEn_ovrdflg' */

/* Override flag for signal b_emergStopEn */
extern const volatile boolean volc_b_fan1TgtSpd_invert;
                   /* Referenced by: '<S209>/volc_b_waterValveTV4V3_V_invert' */

/* Invert flag for Fan1 target speed */
extern const volatile boolean volc_b_fan1TgtSpd_ovrdflg;
                     /* Referenced by: '<S209>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */
extern const volatile boolean volc_b_fan2TgtSpd_invert;
                   /* Referenced by: '<S210>/volc_b_waterValveTV4V3_V_invert' */

/* Invert flag for Fan2 target speed */
extern const volatile boolean volc_b_fan2TgtSpd_ovrdflg;
                     /* Referenced by: '<S210>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */
extern const volatile boolean volc_b_fan3TgtSpd_invert;
                   /* Referenced by: '<S211>/volc_b_waterValveTV4V3_V_invert' */

/* Invert flag for Fan3 target speed */
extern const volatile boolean volc_b_fan3TgtSpd_ovrdflg;
                     /* Referenced by: '<S211>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */
extern const volatile boolean volc_b_flgFnctnConfgBMSWaterTemp;/* Referenced by: '<S13>/Constant' */
extern const volatile boolean volc_b_heater3EnaHW_invert;
                         /* Referenced by: '<S195>/volc_b_cntnrPwrEna_invert' */
extern const volatile boolean volc_b_heater3EnaHW_ovrdflg;
                        /* Referenced by: '<S195>/volc_b_cntnrPwrEna_ovrdflg' */
extern const volatile boolean volc_b_heater3EnaHW_ovrdval;
                        /* Referenced by: '<S195>/volc_b_cntnrPwrEna_ovrdval' */
extern const volatile boolean volc_b_heaterEnaHW_invert;
                         /* Referenced by: '<S196>/volc_b_cntnrPwrEna_invert' */
extern const volatile boolean volc_b_heaterEnaHW_ovrdflg;
                        /* Referenced by: '<S196>/volc_b_cntnrPwrEna_ovrdflg' */
extern const volatile boolean volc_b_heaterEnaHW_ovrdval;
                        /* Referenced by: '<S196>/volc_b_cntnrPwrEna_ovrdval' */
extern const volatile boolean volc_b_highSpdFanRlyReq_invert;
                         /* Referenced by: '<S197>/volc_b_cntnrPwrEna_invert' */
extern const volatile boolean volc_b_highSpdFanRlyReq_ovrdflg;
                        /* Referenced by: '<S197>/volc_b_cntnrPwrEna_ovrdflg' */
extern const volatile boolean volc_b_highSpdFanRlyReq_ovrdval;
                        /* Referenced by: '<S197>/volc_b_cntnrPwrEna_ovrdval' */
extern const volatile boolean volc_b_mainPosRlyReq_invert;
                         /* Referenced by: '<S198>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal mainPosRlyReq */
extern const volatile boolean volc_b_mainPosRlyReq_ovrdflg;
                        /* Referenced by: '<S198>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal mainPosRlyReq */
extern const volatile boolean volc_b_mainPosRlyReq_ovrdval;
                        /* Referenced by: '<S198>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal mainPosRlyReq */
extern const volatile boolean volc_b_motFanRlyReq_invert;
                         /* Referenced by: '<S199>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal motFanRlyReq */
extern const volatile boolean volc_b_motFanRlyReq_ovrdflg;
                        /* Referenced by: '<S199>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal motFanRlyReq */
extern const volatile boolean volc_b_motFanRlyReq_ovrdval;
                        /* Referenced by: '<S199>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal motFanRlyReq */
extern const volatile boolean volc_b_odpHvilDtyOutpt_ovrdflg;
                  /* Referenced by: '<S203>/volc_flg_odpHvilDtyOutpt_ovrdflg' */
extern const volatile boolean volc_b_odpHvilPrdOutpt_ovrdflg;
                  /* Referenced by: '<S204>/volc_flg_odpHvilPrdOutpt_ovrdflg' */
extern const volatile boolean volc_b_pmpEP1TgtSpd_ovrdflg;
                     /* Referenced by: '<S212>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */
extern const volatile boolean volc_b_pmpEP2TgtSpd_pct1_ovrdflg;
                  /* Referenced by: '<S213>/volc_b_pmpEP2TgtSpd_pct1_ovrdflg' */

/* Override flag for signal b_pmpEP2TgtSpd_pct1 */
extern const volatile boolean volc_b_pmpEP3TgtFre_Hz_ovrdflg;
                   /* Referenced by: '<S214>/volc_b_pmpEP3TgtSpd_pct_ovrdflg' */

/* Override flag for signal pmpEP3TgtFre_Hz */
extern const volatile boolean volc_b_pmpEP3TgtSpd_pct_ovrdflg;
                   /* Referenced by: '<S215>/volc_b_pmpEP3TgtSpd_pct_ovrdflg' */

/* Override flag for signal b_pmpEP3TgtSpd_pct */
extern const volatile boolean volc_b_preChrgRlyReq_dftval;
                       /* Referenced by: '<S180>/volc_b_preChrgRlyReq_dftval' */

/* Default value for signal preChrgRlyReq */
extern const volatile boolean volc_b_preChrgRlyReq_invert;
                         /* Referenced by: '<S200>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal preChrgRlyReq */
extern const volatile boolean volc_b_preChrgRlyReq_ovrdflg;
                        /* Referenced by: '<S200>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal preChrgRlyReq */
extern const volatile boolean volc_b_preChrgRlyReq_ovrdval;
                        /* Referenced by: '<S200>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal preChrgRlyReq */
extern const volatile boolean volc_b_steerPumpEn_invert;
                         /* Referenced by: '<S217>/volc_b_steerPumpEn_invert' */

/* Invert flag for signal b_steerPumpEn */
extern const volatile boolean volc_b_steerPumpEn_ovrdflg;
                        /* Referenced by: '<S217>/volc_b_steerPumpEn_ovrdflg' */

/* Override flag for signal b_steerPumpEn */
extern const volatile boolean volc_b_vcuWkUpCmd_invert;
                       /* Referenced by: '<S190>/vilc_b_ResrAirSwitch_invert' */

/* Inversion flag for signal vcuWkUpCmd */
extern const volatile boolean volc_b_vcuWkUpCmd_ovrdflg;
                      /* Referenced by: '<S190>/vilc_b_ResrAirSwitch_ovrdflg' */

/* Override flag for signal vcuWkUpCmd */
extern const volatile boolean volc_b_vcuWkUpCmd_ovrdval;
                      /* Referenced by: '<S190>/vilc_b_ResrAirSwitch_ovrdval' */

/* Override value for signal vcuWkUpCmd */
extern const volatile boolean volc_b_waterValveTV1V3_V_ovrdflg;
                  /* Referenced by: '<S218>/volc_b_waterValveTV1V3_V_ovrdflg' */

/* Override flag for signal b_waterValveTV1V3_V */
extern const volatile boolean volc_b_waterValveTV2V2_V_ovrdflg;
                  /* Referenced by: '<S219>/volc_b_waterValveTV2V2_V_ovrdflg' */

/* Override flag for signal b_waterValveTV2V2_V */
extern const volatile boolean volc_brkPmpEn_ovrdval;
                             /* Referenced by: '<S201>/volc_brkPmpEn_ovrdval' */

/* Override value for signal brkPmpEn */
extern const volatile boolean volc_emergStopEn_ovrdval;
                          /* Referenced by: '<S202>/volc_emergStopEn_ovrdval' */

/* Override value for signal emergStopEn */
extern const volatile float32 volc_frq_pmpEP3TgtFre_Hz_dftval;
                   /* Referenced by: '<S180>/volc_frq_pmpEP3TgtFre_Hz_dftval' */

/* Default value for signal pmpEP3TgtFre_Hz */
extern const volatile uint8 volc_n_SWCompileDay;/* Referenced by: '<S159>/Constant37' */
extern const volatile uint8 volc_n_SWCompileMonth;/* Referenced by: '<S159>/Constant36' */
extern const volatile float32 volc_n_SWCompileYear;/* Referenced by: '<S159>/Constant35' */
extern const volatile uint16 volc_n_Spd3_pct;/* Referenced by: '<S180>/Constant7' */
extern const volatile uint16 volc_n_Spd4_pct;/* Referenced by: '<S180>/Constant10' */
extern const volatile uint16 volc_n_Spd5_pct;/* Referenced by: '<S1>/Constant13' */
extern const volatile uint8 volc_pct_AccPedal_1_dftval;
                        /* Referenced by: '<S180>/volc_pct_AccPedal_1_dftval' */

/* Default value for signal pct_AccPedal_1 */
extern const volatile uint8 volc_pct_AccPedal_1_ovrdval;
                   /* Referenced by: '<S205>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */

/* Override value for signal pct_AccPedal_1 */
extern const volatile uint8 volc_pct_AccPedal_2_dftval;
                        /* Referenced by: '<S180>/volc_pct_AccPedal_2_dftval' */

/* Default value for signal pct_AccPedal_2 */
extern const volatile uint8 volc_pct_AccPedal_2_ovrdval;
                   /* Referenced by: '<S206>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */

/* Override value for signal pct_AccPedal_2 */
extern const volatile uint8 volc_pct_BrkPedal_1_dftval;
                        /* Referenced by: '<S180>/volc_pct_BrkPedal_1_dftval' */

/* Default value for signal pct_BrkPedal_1 */
extern const volatile uint8 volc_pct_BrkPedal_1_ovrdval;
                   /* Referenced by: '<S207>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */

/* Override value for signal pct_BrkPedal_1 */
extern const volatile uint8 volc_pct_BrkPedal_2_dftval;
                        /* Referenced by: '<S180>/volc_pct_BrkPedal_2_dftval' */

/* Default value for signal pct_BrkPedal_2 */
extern const volatile uint8 volc_pct_BrkPedal_2_ovrdval;
                   /* Referenced by: '<S208>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */

/* Override value for signal pct_BrkPedal_2 */
extern const volatile float32 volc_pct_acHvilDtyOutpt_ovrdval;
                   /* Referenced by: '<S184>/volc_pct_acHvilDtyOutpt_ovrdval' */
extern const volatile float32 volc_pct_fan1TgtSpd_ovrdval;
                   /* Referenced by: '<S209>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */
extern const volatile float32 volc_pct_fan2TgtSpd_ovrdval;
                   /* Referenced by: '<S210>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */
extern const volatile uint8 volc_pct_fan3TgtSpd_dftval;
                        /* Referenced by: '<S180>/volc_pct_fan3TgtSpd_dftval' */

/* Default value for signal fan3TgtSpd_pct */
extern const volatile float32 volc_pct_fan3TgtSpd_ovrdval;
                   /* Referenced by: '<S211>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */
extern const volatile float32 volc_pct_odpHvilDtyOutpt_ovrdval;
                  /* Referenced by: '<S203>/volc_pct_odpHvilDtyOutpt_ovrdval' */
extern const volatile float32 volc_pct_pmpEP1TgtSpd_ovrdval;
                   /* Referenced by: '<S212>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */
extern const volatile float32 volc_pmpEP2TgtSpd_pct1_ovrdval;
                    /* Referenced by: '<S213>/volc_pmpEP2TgtSpd_pct1_ovrdval' */

/* Override value for signal pmpEP2TgtSpd_pct1 */
extern const volatile float32 volc_pmpEP3TgtFre_Hz_ovrdval;
                     /* Referenced by: '<S214>/volc_pmpEP3TgtSpd_pct_ovrdval' */

/* Override value for signal pmpEP3TgtFre_Hz */
extern const volatile float32 volc_pmpEP3TgtSpd_pct_ovrdval;
                     /* Referenced by: '<S215>/volc_pmpEP3TgtSpd_pct_ovrdval' */

/* Override value for signal pmpEP3TgtSpd_pct */
extern const volatile uint32 volc_pmpTgtPeriod2_us;/* Referenced by: '<S1>/Constant2' */

/* PWM period Set */
extern const volatile uint32 volc_pmpTgtPeriod3_us;/* Referenced by: '<S1>/Constant6' */

/* PWM period Set */
extern const volatile uint32 volc_pmpTgtPeriod4_us;/* Referenced by: '<S180>/Constant1' */

/* PWM period Set */
extern const volatile uint32 volc_pmpTgtPeriod5_us;/* Referenced by: '<S180>/Constant11' */

/* PWM period Set */
extern const volatile uint32 volc_pmpTgtPeriod6_us;/* Referenced by: '<S1>/Constant9' */

/* PWM period Set */
extern const volatile uint32 volc_pmpTgtPeriod7_us;/* Referenced by: '<S1>/Constant12' */

/* PWM period Set */
extern const volatile uint32 volc_pmpTgtPeriod_us;/* Referenced by: '<S1>/Constant3' */

/* PWM period Set */
extern const volatile uint8 volc_st_ShtDown_ovrdval;
                      /* Referenced by: '<S216>/vilc_b_ResrAirSwitch_ovrdval' */
extern const volatile uint16 volc_st_VCU_CalNum_ovrdval;
                        /* Referenced by: '<S862>/volc_st_VCU_CalNum_ovrdval' */

/* Override value for signal VCU_CalNum */
extern const volatile uint8 volc_st_VCU_OverloadInd_ovrdval;
                   /* Referenced by: '<S863>/volc_st_VCU_OverloadInd_ovrdval' */

/* Override value for signal VCU_OverloadInd */
extern const volatile uint8 volc_st_VCU_bmsModeStsReq_ovrdval;
                 /* Referenced by: '<S547>/volc_st_VCU_bmsModeStsReq_ovrdval' */
extern const volatile boolean volc_steerPumpEn_ovrdval;
                          /* Referenced by: '<S217>/volc_steerPumpEn_ovrdval' */

/* Override value for signal steerPumpEn */
extern const volatile float32 volc_tm_acHvilPrdOutpt_ovrdval;
                    /* Referenced by: '<S185>/volc_tm_acHvilPrdOutpt_ovrdval' */
extern const volatile float32 volc_tm_dlyForRsrChgSt_s;/* Referenced by: '<S77>/Constant28' */
extern const volatile float32 volc_tm_odpHvilPrdOutpt_ovrdval;
                   /* Referenced by: '<S204>/volc_tm_odpHvilPrdOutpt_ovrdval' */
extern const volatile float32 volc_tq_rgnDisTqThd_Nm;/* Referenced by:
                                                      * '<S41>/Relay'
                                                      * '<S41>/Unit Delay'
                                                      */
extern const volatile float32 volc_tq_rgnEnbTqThd_Nm;/* Referenced by: '<S41>/Relay' */
extern const volatile float32 volc_w_VCU_VehicleWeight_ovrdval;
                  /* Referenced by: '<S864>/volc_w_VCU_VehicleWeight_ovrdval' */

/* Override value for signal VCU_VehicleWeight */
extern const volatile boolean volc_waterValveTV1V3_V_ovrdval;
                    /* Referenced by: '<S218>/volc_waterValveTV1V3_V_ovrdval' */

/* Override value for signal waterValveTV1V3_V */
extern const volatile boolean volc_waterValveTV2V2_V_ovrdval;
                    /* Referenced by: '<S219>/volc_waterValveTV2V2_V_ovrdval' */

/* Override value for signal waterValveTV2V2_V */
extern const volatile uint8 vold_VCU_XBREBIMode_dftval;
                        /* Referenced by: '<S225>/vold_VCU_XBREBIMode_dftval' */

/* Default value for signal VCU_XBREBIMode */
#define swc_VCOP_STOP_SEC_CONST_VOLATILE
#include "swc_VCOP_MemMap.h"
#define swc_VCOP_START_SEC_VAR
#include "swc_VCOP_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_SIG */
extern boolean dccd_b_dcdcEna;         /* '<S6>/Relational Operator' */

/* DCDC Enable */
extern float32 dccd_pwr_outPwrLmt_KW;  /* '<S6>/Data Type Conversion' */

/* DC/DC Out Power Limit */
extern uint8 dccd_st_modeReq;          /* '<S18>/Switch' */

/* DC/DC Mode Request */
extern boolean dspd_b_ECOBttnWrkLgt;   /* '<S20>/Relational Operator' */

/* ECO Mode Work Light */
extern boolean dspd_b_gearInvert;      /* '<S21>/Logical Operator4' */
extern boolean dspd_b_hndbrkSt;        /* '<S35>/timed_debounce' */

/* Hand Brake Status */
extern boolean dspd_b_ignSt;           /* '<S37>/timed_debounce' */

/* Ignite Status */
extern uint8 dspd_st_PTModeInd;        /* '<S25>/Switch' */

/* Power Train Mode */
extern uint8 dspd_st_drvMod;           /* '<S20>/Switch1' */

/* Drive Mode */
extern uint8 dspd_st_gearPosnInd;      /* '<S32>/Switch1' */

/* Gear Position */
extern float32 dspd_t_battCooltTemp_C; /* '<S19>/Gain' */

/* Battery Coolent Temperature */
extern boolean eadd_b_ead2Ena;         /* '<S46>/Logical Operator3' */

/* Secondary EAD Control Enable */
extern uint8 eadd_st_ead2PTImmoRlsSts; /* '<S8>/Signal Conversion' */

/* Electric Powertrain Release Status */
extern uint8 eadd_st_inv2EmCtrlMod;    /* '<S42>/Switch' */

/* Secondary EAD Mode Request to CAN out */
extern uint8 eadd_st_inv2EmWMod;       /* '<S41>/Switch5' */

/* Secondary EAD Work Mode to CAN out */
extern float32 eadd_tq_mot2TgtTqReqOutpAbs_Nm;/* '<S39>/Signal Conversion2' */

/* Secondary EAD Absolute Torque Request to CAN out */
extern float32 eadd_tq_mot2TgtTqReqOutp_Nm;/* '<S39>/Switch1' */

/* Secondary EAD Torque Request to CAN out */
extern uint8 epbd_st_parkingSts;       /* '<S52>/Switch' */

/* EPB Status */
extern boolean hvbd_b_HVRdy;           /* '<S68>/Logical Operator3' */

/* HV Ready */
extern boolean hvbd_b_cntnrCtrlEna;    /* '<S61>/Logical Operator3' */

/* Container Control Enable Flag */
extern boolean hvbd_b_hcmRlyEna;       /* '<S74>/Logical Operator3' */

/* HCM Relay Enable */
extern boolean hvbd_b_sdcacEna;        /* '<S10>/Signal Conversion' */

/* SDCAC Relay Enable */
extern uint8 hvbd_st_hvbIntelChgSt;    /* '<S55>/Switch1' */

/* HVB Intelligent Charge State */
extern float32 ptld_pwr_ead21PwrMaxOutp_kW;/* '<S75>/Switch6' */

/* Secondary EAD Max Power (motor) for CAN output */
extern float32 ptld_pwr_ead21PwrMinOutp_kW;/* '<S75>/Signal Conversion1' */

/* Secondary EAD Min Power (generator) for CAN output */
extern float32 ptld_pwr_ead2PwrMaxOutp_kW;/* '<S75>/Switch4' */

/* Secondary EAD Max Power (motor) for CAN output */
extern float32 ptld_pwr_ead2PwrMinOutp_kW;/* '<S75>/Signal Conversion' */

/* Secondary EAD Min Power (generator) for CAN output */
extern boolean srud_b_hvbPmsHvilSts;   /* '<S12>/Logical Operator1' */
extern boolean srud_b_hvbVehHvilSts;   /* '<S12>/Signal Conversion12' */
extern uint8 srud_st_hvbBattFltLampSt; /* '<S12>/Switch1' */
extern boolean thmd_b_FWFVEna;         /* '<S13>/Signal Conversion2' */

/* FWFV enable */
extern boolean thmd_b_MHGVEna;         /* '<S13>/Logical Operator' */

/* MHGV enable */
extern boolean thmd_b_highSpdFanRlyReq;/* '<S138>/Logical Operator3' */
extern boolean thmd_b_motFanRlyReq;    /* '<S148>/Logical Operator3' */

/* TMM Fan Relaty Request */
extern float32 thmd_n_12vAts1PwmReq_pct;/* '<S83>/Multiport Switch1' */

/* 12v ATS1 PWM */
extern float32 thmd_n_ats1PwmReq_pct;  /* '<S85>/Multiport Switch1' */

/* ATS1 PWM */
extern float32 thmd_n_fan1TgtSpdOutp_pct;/* '<S100>/Multiport Switch1' */

/* Fan1 Target Speed PWM */
extern float32 thmd_n_fan2TgtSpdOutp_pct;/* '<S101>/Multiport Switch1' */

/* Fan2 Target Speed PWM */
extern uint8 thmd_st_ats1Ena;          /* '<S84>/Multiport Switch1' */

/* ATS1 Enable */
extern uint8 thmd_st_hvbThermMngWorkMod;/* '<S106>/Switch1' */

/* THM Work Mode Request */
extern float32 thmd_t_ptcTempSetting;  /* '<S86>/Switch1' */

/* VCU BPTC Temperature Setting */
extern uint8 trad_st_gearLvrPos;       /* '<S149>/Switch' */

/* Gear Lever Position mapped for CAN */
extern boolean vold_12VbatRlyReq;      /* '<S181>/Switch2' */
extern boolean vold_12vDCDCEn;         /* '<S182>/Switch2' */
extern boolean vold_24vDCDCEn;         /* '<S183>/Switch2' */
extern uint8 vold_AC_EWP_Heat;         /* '<S374>/Switch2' */
extern float32 vold_AC_EWP_HeatrPwrCnsAllwd;/* '<S375>/Switch2' */
extern uint8 vold_AC_EWP_Run;          /* '<S376>/Switch2' */
extern uint8 vold_AC_EWP_SpeedReq;     /* '<S377>/Switch2' */
extern float32 vold_AC_EWP_Temp;       /* '<S378>/Switch2' */
extern float32 vold_BMSH_ACChgTimeRemain;/* '<S783>/Switch2' */
extern float32 vold_BMSH_BattCurr;     /* '<S784>/Switch2' */
extern uint8 vold_BMSH_BattFaultLampState;/* '<S785>/Switch2' */
extern uint8 vold_BMSH_CCM_ThermalManageReq;/* '<S786>/Switch2' */
extern uint8 vold_BMSH_Cell_TotalNum;  /* '<S787>/Switch2' */
extern uint8 vold_BMSH_ChargeLEDCtrl;  /* '<S788>/Switch2' */
extern uint8 vold_BMSH_Charge_Over_Current;/* '<S789>/Switch2' */
extern float32 vold_BMSH_ChgTimeRemain;/* '<S790>/Switch2' */
extern uint8 vold_BMSH_DCChgminusSocketTempSensing_Failure;/* '<S791>/Switch2' */
extern uint8 vold_BMSH_DCChgplusSocketTempSensing_Failure;/* '<S792>/Switch2' */
extern uint8 vold_BMSH_FastChgCC2ConntState;/* '<S793>/Switch2' */
extern uint8 vold_BMSH_HvBattThermMod; /* '<S422>/Switch2' */
extern uint8 vold_BMSH_InsulationRes_Fault;/* '<S794>/Switch2' */
extern boolean vold_BMSH_TBOX_BatIsoAlarm2;/* '<S160>/Signal Conversion12' */
extern boolean vold_BMSH_TBOX_BatLowSOC2;/* '<S160>/Signal Conversion6' */
extern boolean vold_BMSH_TBOX_BatOverCharge2;/* '<S160>/Signal Conversion7' */
extern boolean vold_BMSH_TBOX_BatOverSOC2;/* '<S160>/Signal Conversion4' */
extern boolean vold_BMSH_TBOX_BatOverTemp2;/* '<S160>/Signal Conversion11' */
extern boolean vold_BMSH_TBOX_BatOverVoltage2;/* '<S160>/Signal Conversion13' */
extern boolean vold_BMSH_TBOX_BatTempUniformity2;/* '<S160>/Signal Conversion3' */
extern boolean vold_BMSH_TBOX_BatUnderVoltage2;/* '<S160>/Signal Conversion10' */
extern boolean vold_BMSH_TBOX_BatUniformity2;/* '<S160>/Signal Conversion8' */
extern boolean vold_BMSH_TBOX_CellOverVoltage2;/* '<S160>/Signal Conversion14' */
extern boolean vold_BMSH_TBOX_CellUnderVoltage2;/* '<S160>/Signal Conversion9' */
extern boolean vold_BMSH_TBOX_SOCHop2; /* '<S160>/Signal Conversion5' */
extern boolean vold_BMSH_ThermalOutofControl;/* '<S795>/Switch2' */
extern boolean vold_BMSH_Vehicle_HVILSts_PHEV;/* '<S796>/Switch2' */
extern uint8 vold_BMSH_stMode;         /* '<S160>/Signal Conversion' */
extern uint8 vold_EDCP_Flt;            /* '<S416>/Switch2' */
extern uint8 vold_HBCP_Flt;            /* '<S417>/Switch2' */
extern boolean vold_IPU_MCUTempHighAlarm1;/* '<S160>/Signal Conversion2' */
extern boolean vold_IPU_MotorTempHighFault1;/* '<S160>/Signal Conversion1' */
extern uint8 vold_PMS_32960FltNum;     /* '<S797>/Switch2' */
extern uint8 vold_PMS_AcceRelayVoltSampSwich;/* '<S857>/Switch2' */
extern uint8 vold_PMS_AcceSuppressionSts;/* '<S379>/Switch2' */
extern float32 vold_PMS_Acceleration;  /* '<S171>/Switch2' */
extern uint8 vold_PMS_AccessoryConnStsFb;/* '<S577>/Switch2' */
extern boolean vold_PMS_AccessoryCtrlCommand;/* '<S286>/Switch2' */
extern uint8 vold_PMS_AccessoryRelayFlt;/* '<S578>/Switch2' */
extern float32 vold_PMS_ActualPTTorque;/* '<S798>/Switch2' */
extern boolean vold_PMS_BBM_FaultStatus;/* '<S287>/Switch2' */
extern boolean vold_PMS_BBM_WorkSts;   /* '<S288>/Switch2' */
extern uint8 vold_PMS_BMS_Reignstatus1;/* '<S799>/Switch2' */
extern uint8 vold_PMS_BMS_Reignstatus2;/* '<S800>/Switch2' */
extern boolean vold_PMS_Brake_LightsRequest;/* '<S801>/Switch2' */
extern float32 vold_PMS_CPSRU;         /* '<S380>/Switch2' */
extern boolean vold_PMS_CampModeFb;    /* '<S802>/Switch2' */
extern uint8 vold_PMS_CampModeFbFailrReason;/* '<S803>/Switch2' */
extern float32 vold_PMS_ChargPwr;      /* '<S381>/Switch2' */
extern uint8 vold_PMS_ChargeLimitResponse;/* '<S804>/Switch2' */
extern boolean vold_PMS_CruisingDstSwtFb;/* '<S805>/Switch2' */
extern boolean vold_PMS_CurrentGearPositionValid;/* '<S659>/Switch2' */
extern float32 vold_PMS_DriverDemandTorque;/* '<S806>/Switch2' */
extern uint8 vold_PMS_DrivingTakeEleSts;/* '<S289>/Switch2' */
extern uint16 vold_PMS_DrvPfmncRedn;   /* '<S807>/Switch2' */
extern boolean vold_PMS_EPBClosedReq_PMS;/* '<S808>/Switch2' */
extern boolean vold_PMS_Fn1GearRlyDrvStsFb;/* '<S382>/Switch2' */
extern boolean vold_PMS_Fn2GearRlyDrvStsFb;/* '<S383>/Switch2' */
extern boolean vold_PMS_FrntHeatModEnad;/* '<S172>/Switch2' */
extern float32 vold_PMS_FrntHeatPwrAllwd;/* '<S173>/Switch2' */
extern boolean vold_PMS_GearIntervene; /* '<S809>/Switch2' */
extern float32 vold_PMS_GrossComVehWeight;/* '<S810>/Switch2' */
extern boolean vold_PMS_HVIL1Sts_EV;   /* '<S174>/Switch2' */
extern boolean vold_PMS_HVIL1Sts_UB;   /* '<S175>/Switch2' */
extern boolean vold_PMS_HVIL2Sts_EV;   /* '<S176>/Switch2' */
extern boolean vold_PMS_HVIL2Sts_UB;   /* '<S177>/Switch2' */
extern boolean vold_PMS_HVILSts_EV;    /* '<S178>/Switch2' */
extern float32 vold_PMS_HvCoolgPwrAllwd;/* '<S418>/Switch2' */

/* indicated power limiting allowed */
extern float32 vold_PMS_HvHeatgPwrAllwd;/* '<S419>/Switch2' */

/* indicated power limiting allowed */
extern float32 vold_PMS_IPKTotalOdometer;/* '<S811>/Switch2' */
extern uint8 vold_PMS_InventorySpdLmtRxSts;/* '<S812>/Switch2' */
extern uint8 vold_PMS_InventorySpdLmtSts;/* '<S813>/Switch2' */
extern uint8 vold_PMS_IsgActvDampgModReq;/* '<S509>/Switch2' */
extern uint8 vold_PMS_Life;            /* '<S814>/Switch2' */
extern uint8 vold_PMS_LockVehExecutedSts;/* '<S384>/Switch2' */
extern uint8 vold_PMS_LockVehPerFlag;  /* '<S815>/Switch2' */
extern uint8 vold_PMS_LockVehPerRxSts; /* '<S816>/Switch2' */
extern float32 vold_PMS_MCUFlowFeedback_EV;/* '<S420>/Switch2' */
extern float32 vold_PMS_MaxPTTorqueAllowed;/* '<S817>/Switch2' */
extern float32 vold_PMS_MinPTTorqueAllowed;/* '<S818>/Switch2' */
extern uint8 vold_PMS_OTAInstrucStsReminder;/* '<S819>/Switch2' */
extern uint8 vold_PMS_OTAInstructRxnSts;/* '<S820>/Switch2' */
extern float32 vold_PMS_Odometerbackup;/* '<S821>/Switch2' */
extern boolean vold_PMS_OdometerbackupEnable;/* '<S822>/Switch2' */
extern uint8 vold_PMS_PTC1ConnStsFb;   /* '<S579>/Switch2' */
extern uint8 vold_PMS_PTC1RelayFlt;    /* '<S580>/Switch2' */
extern uint8 vold_PMS_PTC3ConnStsFb;   /* '<S581>/Switch2' */
extern uint8 vold_PMS_PTC3RelayFlt;    /* '<S582>/Switch2' */
extern uint8 vold_PMS_PTCRelayVoltSampSwich;/* '<S858>/Switch2' */
extern uint8 vold_PMS_PowerOffCmdRxSts;/* '<S823>/Switch2' */
extern uint8 vold_PMS_PowerOffCmdSts;  /* '<S824>/Switch2' */
extern uint8 vold_PMS_PreAccessoryConnStsFb;/* '<S583>/Switch2' */
extern uint8 vold_PMS_PreAccessoryRelayFlt;/* '<S584>/Switch2' */
extern float32 vold_PMS_Real_PedalPosition;/* '<S463>/Switch2' */
extern boolean vold_PMS_Real_PedalPositionInvalid;/* '<S464>/Switch2' */
extern float32 vold_PMS_RegenTarTrqPot;/* '<S825>/Switch2' */
extern float32 vold_PMS_RegenTrqAct;   /* '<S826>/Switch2' */
extern float32 vold_PMS_RegenTrqPot;   /* '<S827>/Switch2' */
extern uint8 vold_PMS_RegulationSpeed; /* '<S385>/Switch2' */
extern uint8 vold_PMS_RemChrgCmdFailrPrompt;/* '<S386>/Switch2' */
extern uint8 vold_PMS_SpdLmtLevel;     /* '<S828>/Switch2' */
extern uint8 vold_PMS_SpdLmtLevelRxSts;/* '<S829>/Switch2' */
extern uint8 vold_PMS_StsBatLockSensor;/* '<S179>/Switch2' */
extern boolean vold_PMS_TBOX_HVILState;/* '<S830>/Switch2' */
extern uint8 vold_PMS_TBOX_LifeSts;    /* '<S831>/Switch2' */
extern boolean vold_PMS_TakeEleSwtIndReq;/* '<S387>/Switch2' */
extern uint8 vold_PMS_ThermalReq;      /* '<S421>/Switch2' */
extern uint8 vold_PMS_Torque_Ovrd_Active;/* '<S388>/Switch2' */
extern uint8 vold_PMS_Torque_Ovrd_Type;/* '<S389>/Switch2' */
extern uint8 vold_PMS_V2XDchaSwtFb1;   /* '<S832>/Switch2' */
extern uint8 vold_PMS_VINCode1_8_15_S; /* '<S833>/Switch2' */
extern uint8 vold_PMS_VINCode2_9_16_S; /* '<S834>/Switch2' */
extern uint8 vold_PMS_VINCode3_10_17_S;/* '<S835>/Switch2' */
extern uint8 vold_PMS_VINCode4_11_S;   /* '<S836>/Switch2' */
extern uint8 vold_PMS_VINCode5_12_S;   /* '<S837>/Switch2' */
extern uint8 vold_PMS_VINCode6_13_S;   /* '<S838>/Switch2' */
extern uint8 vold_PMS_VINCode7_14_S;   /* '<S839>/Switch2' */
extern uint8 vold_PMS_VINMessageNum_S; /* '<S840>/Switch2' */
extern float32 vold_PMS_VacuumPressure;/* '<S841>/Switch2' */
extern float32 vold_PMS_VacuumPump_FB; /* '<S842>/Switch2' */
extern uint8 vold_PMS_VacuumSystemsta; /* '<S843>/Switch2' */
extern uint8 vold_PMS_VehicleSysErrorLevelG;/* '<S398>/Switch2' */
extern uint8 vold_PMS_VersionConversionFlag;/* '<S844>/Switch2' */
extern uint8 vold_PMS_VersionConversionRxSts;/* '<S845>/Switch2' */
extern boolean vold_PMS_ePTFault;      /* '<S846>/Switch2' */
extern uint8 vold_TBOX_ChrgSoftSwCtrlst;/* '<S390>/Switch2' */
extern uint8 vold_TBOX_ReservationChrgnSts;/* '<S391>/Switch2' */
extern uint8 vold_VCU_12VATS1Enable;   /* '<S441>/Switch2' */
extern float32 vold_VCU_12VATS1_PWMRequest;/* '<S442>/Switch2' */
extern uint8 vold_VCU_12VDCDCCutOffLV; /* '<S548>/Switch2' */
extern uint8 vold_VCU_12VDCDCEnableOut;/* '<S549>/Switch2' */
extern uint8 vold_VCU_24V_Switch;      /* '<S679>/Switch2' */
extern uint8 vold_VCU_ACActiveReq;     /* '<S465>/Switch2' */
extern float32 vold_VCU_ACC1PosVol;    /* '<S564>/Switch2' */
extern float32 vold_VCU_ACC2PosVol;    /* '<S565>/Switch2' */
extern uint8 vold_VCU_ACCMEnable;      /* '<S423>/Switch2' */
extern uint8 vold_VCU_ACCY1CtrlCmd;    /* '<S290>/Switch2' */
extern uint8 vold_VCU_ACCYEnableIn;    /* '<S291>/Switch2' */
extern boolean vold_VCU_ACUCrashfz_Back;/* '<S292>/Switch2' */
extern float32 vold_VCU_AEC;           /* '<S531>/Switch2' */
extern boolean vold_VCU_APUSWILED_Ctrl;/* '<S293>/Switch2' */
extern uint8 vold_VCU_ATS1Enable;      /* '<S443>/Switch2' */
extern float32 vold_VCU_ATS1_PWMRequest;/* '<S444>/Switch2' */
extern uint8 vold_VCU_ATS2Enable;      /* '<S445>/Switch2' */
extern float32 vold_VCU_ATS2_PWMRequest;/* '<S446>/Switch2' */
extern uint8 vold_VCU_ATS3Enable;      /* '<S447>/Switch2' */
extern float32 vold_VCU_ATS3_PWMRequest;/* '<S448>/Switch2' */
extern uint8 vold_VCU_ATS4Enable;      /* '<S449>/Switch2' */
extern float32 vold_VCU_ATS4_PWMRequest;/* '<S450>/Switch2' */
extern boolean vold_VCU_AWB;           /* '<S620>/Switch2' */
extern float32 vold_VCU_AccePedalPosD; /* '<S631>/Switch2' */
extern float32 vold_VCU_AccePedalPosE; /* '<S632>/Switch2' */
extern float32 vold_VCU_AcceleratorPedalPosition;/* '<S466>/Switch2' */
extern boolean vold_VCU_AcceleratorPedal_flag;/* '<S467>/Switch2' */
extern boolean vold_VCU_AccyAllowEnable_Ctrl;/* '<S294>/Switch2' */
extern boolean vold_VCU_AccyPower_back;/* '<S295>/Switch2' */
extern uint8 vold_VCU_ActualGear;      /* '<S869>/Switch2' */
extern uint8 vold_VCU_Address;         /* '<S621>/Switch2' */
extern uint8 vold_VCU_AllowChg;        /* '<S550>/Switch2' */
extern uint16 vold_VCU_AppSts;         /* '<S566>/Switch2' */
extern float32 vold_VCU_AvgEVConsume;  /* '<S296>/Switch2' */
extern float32 vold_VCU_AvgFuelVF;     /* '<S297>/Switch2' */
extern float32 vold_VCU_BMSHAllowChgCurrentMax;/* '<S399>/Switch2' */
extern uint8 vold_VCU_BMSHVOnOffReq;   /* '<S551>/Switch2' */
extern float32 vold_VCU_BMSH_DCChgRelayVolt;/* '<S552>/Switch2' */
extern float32 vold_VCU_BMS_SOC;       /* '<S353>/Switch2' */

/* BMS SOC */
extern float32 vold_VCU_BMS_voltage;   /* '<S354>/Switch2' */

/* BMS Voltage */
extern uint8 vold_VCU_BPTCCtrlCmd;     /* '<S563>/Switch2' */
extern boolean vold_VCU_BPTCEnable;    /* '<S859>/Switch2' */
extern float32 vold_VCU_BPTCPowerRatio;/* '<S849>/Saturation0' */
extern float32 vold_VCU_BPTCTempSetting;/* '<S861>/Switch2' */
extern uint16 vold_VCU_BattCoolVal3_FBV5;/* '<S597>/Switch2' */
extern uint16 vold_VCU_BattCoolVal3_FBV6;/* '<S598>/Switch2' */
extern uint16 vold_VCU_BattHeatVal2_FBV5;/* '<S599>/Switch2' */
extern uint16 vold_VCU_BattHeatVal2_FBV6;/* '<S600>/Switch2' */
extern float32 vold_VCU_BattMaxTemp;   /* '<S355>/Switch2' */

/* Battery Maximum Temperature */
extern float32 vold_VCU_BattMinTemp;   /* '<S356>/Switch2' */

/* Battery Minimum Temperature */
extern float32 vold_VCU_BattPackInCoolTemp;/* '<S424>/Switch2' */
extern float32 vold_VCU_BattPackInCoolTempback;/* '<S298>/Switch2' */
extern float32 vold_VCU_BattPackOutCoolTemp;/* '<S425>/Switch2' */
extern float32 vold_VCU_BattPackoutCoolTempback;/* '<S299>/Switch2' */
extern float32 vold_VCU_BattVol;       /* '<S357>/Switch2' */

/* Battery Voltage */
extern float32 vold_VCU_BatteryCoolentTemp;/* '<S426>/Switch2' */
extern float32 vold_VCU_BatteryVol;    /* '<S567>/Switch2' */
extern boolean vold_VCU_Batty_Charge_DisChargeState;/* '<S358>/Switch2' */

/* Baterry Charge and Discharge State Flag */
extern boolean vold_VCU_Batty_ThermalMangeActive;/* '<S359>/Switch2' */

/* Battery Thermal Management Active Flag */
extern uint8 vold_VCU_Batty_ThermalMangeReq;/* '<S427>/Switch2' */
extern uint8 vold_VCU_Batty_ThermalMangeWorkMode;/* '<S360>/Switch2' */

/* Battery Thermal Management Work Mode */
extern uint8 vold_VCU_BrakSwitchSts;   /* '<S468>/Switch2' */
extern float32 vold_VCU_Brake1PosVol;  /* '<S592>/Switch2' */
extern boolean vold_VCU_Brake1Sts;     /* '<S568>/Switch2' */
extern float32 vold_VCU_Brake2PosVol;  /* '<S593>/Switch2' */
extern boolean vold_VCU_Brake2Sts;     /* '<S569>/Switch2' */
extern float32 vold_VCU_BrakePedalPosition;/* '<S469>/Switch2' */
extern uint8 vold_VCU_BrkSysErr;       /* '<S660>/Switch2' */
extern uint8 vold_VCU_CCFb;            /* '<S585>/Switch2' */
extern float32 vold_VCU_CC_Acceleration;/* '<S324>/Switch2' */
extern boolean vold_VCU_Cab_ThermalMangeReq;/* '<S361>/Switch2' */

/* Cabin Thermal Management Request */
extern uint16 vold_VCU_CabinLoopVal1_FBV6;/* '<S601>/Switch2' */
extern uint16 vold_VCU_CabinLoopVal2_FBV5;/* '<S602>/Switch2' */
extern uint8 vold_VCU_Cabin_PumpFb;    /* '<S586>/Switch2' */
extern uint16 vold_VCU_CalNum;         /* '<S865>/Switch2' */
extern uint8 vold_VCU_CalibrationMajorVer1;/* '<S704>/Switch2' */
extern uint8 vold_VCU_CalibrationMajorVer2;/* '<S705>/Switch2' */
extern uint8 vold_VCU_CalibrationMajorVer3;/* '<S706>/Switch2' */
extern uint8 vold_VCU_CalibrationMinorVer1;/* '<S707>/Switch2' */
extern uint8 vold_VCU_CalibrationMinorVer2;/* '<S708>/Switch2' */
extern uint8 vold_VCU_CalibrationMinorVer3;/* '<S709>/Switch2' */
extern float32 vold_VCU_Cell_Avg_Temp; /* '<S362>/Switch2' */

/* Cell Average Temperature */
extern uint8 vold_VCU_ChargWakeupSts;  /* '<S587>/Switch2' */
extern uint8 vold_VCU_ChargeDepthReq;  /* '<S400>/Switch2' */
extern uint8 vold_VCU_Charger_Connected;/* '<S363>/Switch2' */

/* Charger Connected State */
extern float32 vold_VCU_ControlSetSpeed;/* '<S481>/Switch2' */

/* Cruise Control Target Set Speed */
extern uint8 vold_VCU_ControlSetSpeed_Mode;/* '<S482>/Switch2' */

/* Cruise Control Speed Mode */
extern uint8 vold_VCU_Cooling_Control_Request;/* '<S364>/Switch2' */

/* VCU Cooling Control Request */
extern uint8 vold_VCU_CrashOutputSts;  /* '<S847>/Switch2' */
extern uint8 vold_VCU_CruiseControlSts;/* '<S483>/Switch2' */

/* Cruise Control Status */
extern uint8 vold_VCU_CruiseSwSts;     /* '<S484>/Switch2' */

/* Cruise Control Button Status */
extern uint8 vold_VCU_CruiseSwerrorSts;/* '<S485>/Switch2' */

/* Cruise Control Button Status Error */
extern float32 vold_VCU_DCDCPwrLmt;    /* '<S553>/Switch2' */
extern uint8 vold_VCU_DCDC_WorkSts;    /* '<S661>/Switch2' */

/* DCDC Working Status */
extern float32 vold_VCU_DTE;           /* '<S532>/Switch2' */
extern uint8 vold_VCU_DischargeEnable; /* '<S397>/Switch2' */
extern sint16 vold_VCU_DriveCircuitTemp;/* '<S392>/Switch2' */
extern uint16 vold_VCU_DriveCircuitVol;/* '<S603>/Switch2' */
extern uint8 vold_VCU_DriveModeInd;    /* '<S662>/Switch2' */
extern uint8 vold_VCU_DrivePwrCircuitInd;/* '<S663>/Switch2' */
extern float32 vold_VCU_DriveReqTrqPercent;/* '<S510>/Switch2' */

/* Drive Request Torque Percentage */
extern uint8 vold_VCU_DriverOperationReminder;/* '<S470>/Switch2' */
extern uint8 vold_VCU_DrivingTakeForceSts;/* '<S873>/Switch2' */
extern boolean vold_VCU_ECOMode;       /* '<S570>/Switch2' */
extern boolean vold_VCU_ECOmodeSWILED_Ctrl;/* '<S300>/Switch2' */
extern float32 vold_VCU_ECPM_FaultFB;  /* '<S301>/Switch2' */
extern boolean vold_VCU_EDCP_Enable;   /* '<S875>/Switch2' */
extern float32 vold_VCU_EDCP_FaultFB;  /* '<S302>/Switch2' */
extern float32 vold_VCU_EDCP_PWMCtrl;  /* '<S854>/Saturation0' */
extern uint8 vold_VCU_EM1CtrlMode;     /* '<S511>/Switch2' */
extern uint8 vold_VCU_EM1WorkMode;     /* '<S512>/Switch2' */
extern uint8 vold_VCU_EMCtrlMode;      /* '<S513>/Switch2' */
extern uint8 vold_VCU_EMWorkMode;      /* '<S514>/Switch2' */
extern uint8 vold_VCU_EManualStartSwi; /* '<S588>/Switch2' */
extern float32 vold_VCU_EVDTEodometer; /* '<S303>/Switch2' */
extern uint8 vold_VCU_EV_Switch;       /* '<S680>/Switch2' */
extern uint8 vold_VCU_EVanualStartSwi; /* '<S664>/Switch2' */
extern uint8 vold_VCU_EmergencyStop;   /* '<S594>/Switch2' */
extern float32 vold_VCU_EngFuelInstCons;/* '<S365>/Switch2' */

/* Engine Instantaneous Fuel Consumption */
extern float32 vold_VCU_ErrCode;       /* '<S533>/Switch2' */
extern float32 vold_VCU_ExternalAccDemand;/* '<S325>/Switch2' */

/* External Acceleration Demand */
extern float32 vold_VCU_FanPWM_Ctrl;   /* '<S681>/Switch2' */
extern float32 vold_VCU_FuleDTEodometer;/* '<S304>/Switch2' */
extern uint8 vold_VCU_FunAnti_DismantleActive;/* '<S609>/Switch2' */
extern uint8 vold_VCU_FunLockVehActive;/* '<S610>/Switch2' */
extern boolean vold_VCU_GP_Override;   /* '<S326>/Switch2' */
extern uint8 vold_VCU_GearOperateErr;  /* '<S665>/Switch2' */
extern uint8 vold_VCU_GearPositionInd; /* '<S666>/Switch2' */
extern float32 vold_VCU_GearPositionInput;/* '<S595>/Switch2' */
extern uint8 vold_VCU_Gearshift_Resp;  /* '<S874>/Switch2' */
extern boolean vold_VCU_HBCP_Enable;   /* '<S877>/Switch2' */
extern float32 vold_VCU_HBCP_FaultFB;  /* '<S305>/Switch2' */
extern float32 vold_VCU_HBCP_PWMCtrl;  /* '<S878>/Switch2' */
extern float32 vold_VCU_HTCoolingFan1FB;/* '<S306>/Switch2' */
extern uint8 vold_VCU_HVB_PumpFb;      /* '<S589>/Switch2' */
extern float32 vold_VCU_HVILReturn;    /* '<S596>/Switch2' */
extern boolean vold_VCU_HVOnOffReq;    /* '<S366>/Switch2' */

/* VCU HV ON/OFF Request */
extern uint16 vold_VCU_HVPRASts;       /* '<S571>/Switch2' */
extern uint8 vold_VCU_HV_Status;       /* '<S307>/Switch2' */
extern uint8 vold_VCU_HandbrakeSts;    /* '<S667>/Switch2' */
extern uint8 vold_VCU_HandbrakeSts2;   /* '<S471>/Switch2' */
extern uint8 vold_VCU_HardwareMajorVer;/* '<S710>/Switch2' */
extern uint8 vold_VCU_HardwareMinorVer;/* '<S711>/Switch2' */
extern boolean vold_VCU_HazardReq;     /* '<S554>/Switch2' */
extern uint8 vold_VCU_HybridReady;     /* '<S367>/Switch2' */

/* VCU Hybrid Mode Ready */
extern uint8 vold_VCU_Idle_Switch;     /* '<S682>/Switch2' */
extern boolean vold_VCU_IgnONSts;      /* '<S572>/Switch2' */
extern uint8 vold_VCU_IgniteSts;       /* '<S668>/Switch2' */
extern uint8 vold_VCU_InhibitHybrid_Switch;/* '<S683>/Switch2' */
extern uint8 vold_VCU_IntelLockLoopSts;/* '<S555>/Switch2' */
extern uint8 vold_VCU_IntelligentChargeExitReq;/* '<S308>/Switch2' */
extern uint8 vold_VCU_IntelligentChargeQuit;/* '<S309>/Switch2' */
extern uint8 vold_VCU_IntelligentChargeState;/* '<S310>/Switch2' */
extern uint8 vold_VCU_LTCoolingFan2FB; /* '<S311>/Switch2' */
extern uint8 vold_VCU_LockLimResult;   /* '<S611>/Switch2' */
extern uint8 vold_VCU_LockVehSts;      /* '<S612>/Switch2' */
extern uint8 vold_VCU_LockVehType;     /* '<S613>/Switch2' */
extern uint8 vold_VCU_MCU1EnableReq;   /* '<S515>/Switch2' */
extern uint8 vold_VCU_MCUActiveDischg; /* '<S368>/Switch2' */

/* MCU Active Discharge State */
extern uint8 vold_VCU_MCUEnableReq;    /* '<S516>/Switch2' */
extern uint16 vold_VCU_MCUMaxTrq;      /* '<S517>/Switch2' */

/* Motor Maximum Torque */
extern float32 vold_VCU_MCUSpdRampRate;/* '<S518>/Switch2' */

/* MCU Speed Ramp Rate */
extern float32 vold_VCU_MCUTqRampRate; /* '<S519>/Switch2' */

/* MCU Torque Ramp Rate */
extern float32 vold_VCU_MCU_MotorActTrqPercent;/* '<S520>/Switch2' */

/* Motor Actual Torque Percentage */
extern float32 vold_VCU_MCU_PumpPWM_Ctrl;/* '<S684>/Switch2' */
extern uint8 vold_VCU_MCU_RelayCtrl_Ctrl;/* '<S685>/Switch2' */
extern uint8 vold_VCU_MILTelltale;     /* '<S633>/Switch2' */
extern uint8 vold_VCU_MainPosCtrlCommand;/* '<S556>/Switch2' */
extern uint8 vold_VCU_Main_Contactor_Control;/* '<S369>/Switch2' */

/* VCU Main Contactor Control Request */
extern float32 vold_VCU_MaxEMPwrLmt;   /* '<S521>/Switch2' */
extern float32 vold_VCU_MinEMPwrLmt;   /* '<S522>/Switch2' */
extern float32 vold_VCU_MotorSpeed;    /* '<S523>/Switch2' */

/* VCU Motor Speed Request */
extern float32 vold_VCU_MotorTorque;   /* '<S524>/Switch2' */

/* VCU Motor Torque Request */
extern boolean vold_VCU_NMSts;         /* '<S622>/Switch2' */
extern uint8 vold_VCU_Oil_HV_OFF;      /* '<S870>/Switch2' */

/* VCU Oil HV Off */
extern uint8 vold_VCU_OverloadInd;     /* '<S866>/Switch2' */
extern float32 vold_VCU_PMS_APPowerActual_EV;/* '<S428>/Switch2' */
extern boolean vold_VCU_PTC2Enable;    /* '<S394>/Switch2' */
extern boolean vold_VCU_PTC3Enable;    /* '<S395>/Switch2' */
extern uint8 vold_VCU_PTCEnable;       /* '<S429>/Switch2' */
extern uint8 vold_VCU_PTHVSysErrorLampStsInd;/* '<S669>/Switch2' */
extern uint8 vold_VCU_PTModeInd;       /* '<S670>/Switch2' */
extern uint8 vold_VCU_PTReadyInd;      /* '<S671>/Switch2' */
extern float32 vold_VCU_PTResiPwr;     /* '<S534>/Switch2' */
extern float32 vold_VCU_PTSysElecPwrInd;/* '<S672>/Switch2' */
extern uint8 vold_VCU_PreRelay_Ctrl;   /* '<S686>/Switch2' */
extern uint8 vold_VCU_PressureSwi1Sts; /* '<S590>/Switch2' */
extern uint8 vold_VCU_PressureSwi2Sts; /* '<S591>/Switch2' */
extern boolean vold_VCU_PropulSysActive;/* '<S312>/Switch2' */
extern float32 vold_VCU_QuitControlSpeed;/* '<S486>/Switch2' */

/* Quit Cruise Control Target Speed */
extern boolean vold_VCU_RMR;           /* '<S623>/Switch2' */
extern uint8 vold_VCU_RelayCtrl_Ctrl;  /* '<S687>/Switch2' */
extern float32 vold_VCU_ReqSpdOrLmt;   /* '<S525>/Switch2' */
extern float32 vold_VCU_ReqTrqOrLmt;   /* '<S526>/Switch2' */
extern float32 vold_VCU_SDCACOutFreq;  /* '<S557>/Switch2' */
extern boolean vold_VCU_SDCACStopFault;/* '<S558>/Switch2' */
extern uint8 vold_VCU_SWCompileDay;    /* '<S712>/Switch2' */
extern uint8 vold_VCU_SWCompileMonth;  /* '<S713>/Switch2' */
extern float32 vold_VCU_SWCompileYear; /* '<S714>/Switch2' */
extern uint8 vold_VCU_SelfCheckSts;    /* '<S559>/Switch2' */
extern float32 vold_VCU_Set_Temp;      /* '<S370>/Switch2' */

/* VCU Set Temperature */
extern boolean vold_VCU_ShiftClimbing; /* '<S573>/Switch2' */
extern boolean vold_VCU_ShiftD;        /* '<S574>/Switch2' */
extern boolean vold_VCU_ShiftR;        /* '<S575>/Switch2' */
extern uint8 vold_VCU_SoftwareMajorVer;/* '<S715>/Switch2' */
extern uint8 vold_VCU_SoftwareMinorVer;/* '<S716>/Switch2' */
extern boolean vold_VCU_StartSts;      /* '<S576>/Switch2' */
extern uint32 vold_VCU_Stayawake_reasons;/* '<S624>/Switch2' */
extern boolean vold_VCU_StsBrkSwitch1Invalid;/* '<S472>/Switch2' */
extern float32 vold_VCU_TotalOdometer; /* '<S634>/Switch2' */
extern boolean vold_VCU_TotalOdometerInvalid;/* '<S635>/Switch2' */
extern uint8 vold_VCU_TurtleLampReq;   /* '<S673>/Switch2' */
extern boolean vold_VCU_VLC_Active;    /* '<S327>/Switch2' */
extern boolean vold_VCU_VLC_Available; /* '<S328>/Switch2' */
extern float32 vold_VCU_VLC_InternalTargetACCeleration;/* '<S329>/Switch2' */
extern float32 vold_VCU_VLC_VCUTargetACCeleration;/* '<S330>/Switch2' */
extern float32 vold_VCU_VehCruisingDistance;/* '<S688>/Switch2' */
extern uint8 vold_VCU_VehicleAbnormalSts;/* '<S674>/Switch2' */
extern float32 vold_VCU_VehicleIdentification;/* '<S690>/Switch2' */
extern uint8 vold_VCU_VehicleRunMode;  /* '<S675>/Switch2' */
extern uint8 vold_VCU_VehicleSlipWarning;/* '<S676>/Switch2' */
extern float32 vold_VCU_VehicleSpd;    /* '<S473>/Switch2' */
extern boolean vold_VCU_VehicleSpd_flag;/* '<S474>/Switch2' */
extern uint8 vold_VCU_VehicleSubSysErrorLevel;/* '<S677>/Switch2' */
extern uint8 vold_VCU_VehicleSysErrorLevel;/* '<S678>/Switch2' */
extern uint8 vold_VCU_VehicleSysFltLevel;/* '<S637>/Switch2' */
extern float32 vold_VCU_VehicleWeight; /* '<S867>/Switch2' */
extern uint8 vold_VCU_WPCtrl;          /* '<S430>/Switch2' */
extern uint8 vold_VCU_Wakeup_reasons;  /* '<S625>/Switch2' */
extern uint8 vold_VCU_XBRControlMode;  /* '<S331>/Switch2' */

/* External Brake Control Mode */
extern uint8 vold_VCU_XBREBIMode;      /* '<S332>/Switch2' */
extern uint8 vold_VCU_XBRPriority;     /* '<S333>/Switch2' */

/* External Brake Priority */
extern boolean vold_VCU_ZeroPwr_Fb;    /* '<S396>/Switch2' */
extern uint8 vold_VCU_bmsModeStsReq;   /* '<S560>/Switch2' */
extern uint8 vold_VCU_ePTRegencyLevInd;/* '<S717>/Switch2' */
extern uint8 vold_VCU_ePTReleaseSig;   /* '<S313>/Switch2' */
extern boolean vold_b_CpsrCtrl;        /* '<S180>/Signal Conversion1' */
extern boolean vold_b_ResetHSDFRA16A17;/* '<S186>/Switch2' */
extern boolean vold_b_ResetHSDFRA1A2;  /* '<S187>/Switch2' */
extern boolean vold_b_ResetHSDFRA31A32;/* '<S188>/Switch2' */
extern boolean vold_b_ResetHSDFRA46A47;/* '<S189>/Switch2' */
extern boolean vold_b_VacPumpRlyEn;    /* '<S191>/Switch2' */
extern boolean vold_b_accyPreRlyCmd;   /* '<S192>/Switch2' */
extern boolean vold_b_cntnrCtrlEna;    /* '<S193>/Switch2' */
extern boolean vold_b_cntnrPwrEna;     /* '<S194>/Switch2' */
extern boolean vold_b_heater3EnaHW;    /* '<S195>/Switch2' */
extern boolean vold_b_heaterEnaHW;     /* '<S196>/Switch2' */
extern boolean vold_b_highSpdFanRlyReq;/* '<S197>/Switch2' */
extern boolean vold_b_mainPosRlyReq;   /* '<S198>/Switch2' */

/* Main Positive Relay Request */
extern boolean vold_b_motFanRlyReq;    /* '<S199>/Switch2' */

/* Motor Fan Relay Request */
extern boolean vold_b_preChrgRlyReq;   /* '<S200>/Switch2' */

/* Precharge Relay Request */
extern boolean vold_brkPmpEn;          /* '<S201>/Switch2' */
extern boolean vold_emergStopEn;       /* '<S202>/Switch2' */
extern float32 vold_fan1TgtSpd_pct;    /* '<S209>/Switch2' */
extern float32 vold_fan2TgtSpd_pct;    /* '<S210>/Switch2' */
extern float32 vold_fan3TgtSpd_pct;    /* '<S211>/Switch2' */
extern uint8 vold_pct_AccPedal_1;      /* '<S205>/Switch2' */

/* Accelerator Pedal Position 1 */
extern uint8 vold_pct_AccPedal_2;      /* '<S206>/Switch2' */

/* Accelerator Pedal Position 2 */
extern uint8 vold_pct_BrkPedal_1;      /* '<S207>/Switch2' */

/* Brake Pedal Position 1 */
extern uint8 vold_pct_BrkPedal_2;      /* '<S208>/Switch2' */

/* Brake Pedal Position 2 */
extern float32 vold_pct_acHvilDtyOutpt;/* '<S220>/Switch2' */
extern float32 vold_pct_odpHvilDtyOutpt;/* '<S222>/Switch2' */
extern float32 vold_pmpEP1TgtSpd_pct;  /* '<S212>/Switch2' */
extern float32 vold_pmpEP2TgtSpd_pct;  /* '<S213>/Switch2' */
extern float32 vold_pmpEP3TgtFre_Hz;   /* '<S214>/Switch2' */

/* EP3 Motor Water Pump Target Frequency */
extern float32 vold_pmpEP3TgtSpd_pct;  /* '<S215>/Switch2' */
extern uint8 vold_st_ShtDown;          /* '<S216>/Switch2' */
extern boolean vold_steerPumpEn;       /* '<S217>/Switch2' */
extern float32 vold_tm_acHvilPrdOutpt; /* '<S221>/Switch2' */
extern float32 vold_tm_odpHvilPrdOutpt;/* '<S223>/Switch2' */
extern boolean vold_waterValveTV1V3_V; /* '<S218>/Switch2' */
extern boolean vold_waterValveTV2V2_V; /* '<S219>/Switch2' */
extern float32 vscd_tq_axle2ActRgnTq_Nm;/* '<S154>/Saturation1' */
extern float32 vscd_tq_axle2ActTq_Nm;  /* '<S154>/Saturation5' */

/* Secondary Axle Actual Torque */
extern float32 vscd_v_vscVehSpdOutp_kph;/* '<S155>/Switch' */

/* Vehicle Speed For CAN Output */
#define swc_VCOP_STOP_SEC_VAR
#include "swc_VCOP_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_swc_VCOP_T *const swc_VCOP_M;

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
 * '<Root>' : 'swc_VCOP'
 * '<S1>'   : 'swc_VCOP/VCOP__VCU_Outputs_Processing'
 * '<S2>'   : 'swc_VCOP/VCOP__VCU_Outputs_Processing/Compare To Constant'
 * '<S3>'   : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs'
 * '<S4>'   : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer'
 * '<S5>'   : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/ACU_OutputsProcessing'
 * '<S6>'   : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DCC_OutputsProcessing'
 * '<S7>'   : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing'
 * '<S8>'   : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EAD_OutputsProcessingMot2'
 * '<S9>'   : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EPB_OutputsProcessing'
 * '<S10>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing'
 * '<S11>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/PTL_OutputsProcessing'
 * '<S12>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/SRU_OutputsProcessing'
 * '<S13>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing'
 * '<S14>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/TRA_OutputsProcessingTrsm1'
 * '<S15>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/VAC_OutputsProcessing'
 * '<S16>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/VSC_OutputsProcessing'
 * '<S17>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DCC_OutputsProcessing/Enumerated Constant3'
 * '<S18>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DCC_OutputsProcessing/state_mapping'
 * '<S19>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/BattCooltTemp'
 * '<S20>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/DrvModDbnc'
 * '<S21>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/GearIntervene'
 * '<S22>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/GearLeverDeterminationForDisp'
 * '<S23>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/HndBrkDbnc'
 * '<S24>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/IgnStDbnc'
 * '<S25>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/PTModeInd'
 * '<S26>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/DrvModDbnc/debounce'
 * '<S27>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/DrvModDbnc/debounce/timed_debounce'
 * '<S28>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/GearLeverDeterminationForDisp/Enumerated Constant1'
 * '<S29>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/GearLeverDeterminationForDisp/Enumerated Constant2'
 * '<S30>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/GearLeverDeterminationForDisp/Enumerated Constant3'
 * '<S31>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/GearLeverDeterminationForDisp/Enumerated Constant9'
 * '<S32>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/GearLeverDeterminationForDisp/GearPosnIndDbnc'
 * '<S33>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/GearLeverDeterminationForDisp/GearPosnIndDbnc/debounce'
 * '<S34>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/GearLeverDeterminationForDisp/GearPosnIndDbnc/debounce/timed_debounce'
 * '<S35>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/HndBrkDbnc/debounce'
 * '<S36>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/HndBrkDbnc/debounce/timed_debounce'
 * '<S37>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/IgnStDbnc/debounce'
 * '<S38>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/DSP_OutputsProcessing/IgnStDbnc/debounce/timed_debounce'
 * '<S39>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EAD_OutputsProcessingMot2/EAD2Arbitration'
 * '<S40>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EAD_OutputsProcessingMot2/EAD2Enable'
 * '<S41>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EAD_OutputsProcessingMot2/MotoModeDetermination'
 * '<S42>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EAD_OutputsProcessingMot2/state_mapping'
 * '<S43>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EAD_OutputsProcessingMot2/EAD2Enable/Enumerated Constant'
 * '<S44>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EAD_OutputsProcessingMot2/EAD2Enable/Enumerated Constant1'
 * '<S45>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EAD_OutputsProcessingMot2/EAD2Enable/Enumerated Constant2'
 * '<S46>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EAD_OutputsProcessingMot2/EAD2Enable/SR_latch'
 * '<S47>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EAD_OutputsProcessingMot2/MotoModeDetermination/Enumerated Constant'
 * '<S48>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EAD_OutputsProcessingMot2/MotoModeDetermination/Enumerated Constant1'
 * '<S49>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EAD_OutputsProcessingMot2/MotoModeDetermination/Enumerated Constant2'
 * '<S50>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EAD_OutputsProcessingMot2/MotoModeDetermination/Enumerated Constant3'
 * '<S51>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EAD_OutputsProcessingMot2/MotoModeDetermination/Enumerated Constant5'
 * '<S52>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/EPB_OutputsProcessing/state_mapping'
 * '<S53>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/HvbContainerPowerEnable'
 * '<S54>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/HvbReady'
 * '<S55>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/IntelligentChargeStatus'
 * '<S56>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/RelayEnable'
 * '<S57>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/HvbContainerPowerEnable/Compare To Constant6'
 * '<S58>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/HvbContainerPowerEnable/Compare To Constant8'
 * '<S59>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/HvbContainerPowerEnable/Enumerated Constant2'
 * '<S60>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/HvbContainerPowerEnable/Enumerated Constant3'
 * '<S61>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/HvbContainerPowerEnable/SR_latch1'
 * '<S62>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/HvbReady/Enumerated Constant'
 * '<S63>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/HvbReady/Enumerated Constant1'
 * '<S64>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/HvbReady/Enumerated Constant2'
 * '<S65>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/HvbReady/Enumerated Constant3'
 * '<S66>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/HvbReady/Enumerated Constant4'
 * '<S67>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/HvbReady/Enumerated Constant5'
 * '<S68>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/HvbReady/SR_latch'
 * '<S69>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/IntelligentChargeStatus/Compare To Constant1'
 * '<S70>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/IntelligentChargeStatus/Compare To Constant2'
 * '<S71>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/IntelligentChargeStatus/Enumerated Constant'
 * '<S72>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/RelayEnable/Enumerated Constant'
 * '<S73>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/RelayEnable/Enumerated Constant2'
 * '<S74>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/HVB_OutputsProcessing/RelayEnable/SR_latch'
 * '<S75>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/PTL_OutputsProcessing/MotorPowerLimitation'
 * '<S76>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/SRU_OutputsProcessing/BMSH_stMode'
 * '<S77>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/SRU_OutputsProcessing/ChargeLEDControl'
 * '<S78>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/SRU_OutputsProcessing/Chart'
 * '<S79>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/SRU_OutputsProcessing/ChargeLEDControl/turnOFF_delay'
 * '<S80>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/SRU_OutputsProcessing/ChargeLEDControl/turnOFF_delay1'
 * '<S81>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/SRU_OutputsProcessing/ChargeLEDControl/turnOFF_delay/timed_delay'
 * '<S82>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/SRU_OutputsProcessing/ChargeLEDControl/turnOFF_delay1/timed_delay'
 * '<S83>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/12vAts1PwmReq'
 * '<S84>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/AtsEna'
 * '<S85>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/AtsPwmReq'
 * '<S86>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/BPTCTemperatureSetting'
 * '<S87>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/EDCP_Flt'
 * '<S88>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Enumerated Constant1'
 * '<S89>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Enumerated Constant10'
 * '<S90>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Enumerated Constant11'
 * '<S91>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Enumerated Constant12'
 * '<S92>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Enumerated Constant2'
 * '<S93>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Enumerated Constant3'
 * '<S94>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Enumerated Constant4'
 * '<S95>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Enumerated Constant5'
 * '<S96>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Enumerated Constant6'
 * '<S97>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Enumerated Constant7'
 * '<S98>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Enumerated Constant8'
 * '<S99>'  : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Enumerated Constant9'
 * '<S100>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Fan1TgtSpd'
 * '<S101>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Fan2TgtSpd'
 * '<S102>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HBCP_Flt'
 * '<S103>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HighFanRelayRequest'
 * '<S104>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/PTCCmdEna'
 * '<S105>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Subsystem'
 * '<S106>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/THMWorkModeRequest'
 * '<S107>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/TMMFanRelayRequest'
 * '<S108>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/EDCP_Flt/Compare To Constant1'
 * '<S109>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/EDCP_Flt/Compare To Constant10'
 * '<S110>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/EDCP_Flt/Compare To Constant11'
 * '<S111>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/EDCP_Flt/Compare To Constant12'
 * '<S112>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/EDCP_Flt/Compare To Constant13'
 * '<S113>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/EDCP_Flt/Compare To Constant14'
 * '<S114>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/EDCP_Flt/Compare To Constant2'
 * '<S115>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/EDCP_Flt/Compare To Constant3'
 * '<S116>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/EDCP_Flt/Compare To Constant4'
 * '<S117>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/EDCP_Flt/Compare To Constant5'
 * '<S118>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/EDCP_Flt/Compare To Constant6'
 * '<S119>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/EDCP_Flt/Compare To Constant7'
 * '<S120>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/EDCP_Flt/Compare To Constant8'
 * '<S121>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/EDCP_Flt/Compare To Constant9'
 * '<S122>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HBCP_Flt/Compare To Constant1'
 * '<S123>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HBCP_Flt/Compare To Constant10'
 * '<S124>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HBCP_Flt/Compare To Constant11'
 * '<S125>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HBCP_Flt/Compare To Constant12'
 * '<S126>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HBCP_Flt/Compare To Constant13'
 * '<S127>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HBCP_Flt/Compare To Constant14'
 * '<S128>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HBCP_Flt/Compare To Constant2'
 * '<S129>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HBCP_Flt/Compare To Constant3'
 * '<S130>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HBCP_Flt/Compare To Constant4'
 * '<S131>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HBCP_Flt/Compare To Constant5'
 * '<S132>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HBCP_Flt/Compare To Constant6'
 * '<S133>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HBCP_Flt/Compare To Constant7'
 * '<S134>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HBCP_Flt/Compare To Constant8'
 * '<S135>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HBCP_Flt/Compare To Constant9'
 * '<S136>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HighFanRelayRequest/Enumerated Constant1'
 * '<S137>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HighFanRelayRequest/Enumerated Constant2'
 * '<S138>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/HighFanRelayRequest/SR_latch'
 * '<S139>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Subsystem/Compare To Constant'
 * '<S140>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Subsystem/Compare To Constant1'
 * '<S141>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Subsystem/Compare To Constant2'
 * '<S142>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Subsystem/Compare To Constant3'
 * '<S143>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Subsystem/Compare To Constant4'
 * '<S144>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Subsystem/Compare To Constant5'
 * '<S145>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/Subsystem/Compare To Constant7'
 * '<S146>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/TMMFanRelayRequest/Enumerated Constant1'
 * '<S147>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/TMMFanRelayRequest/Enumerated Constant2'
 * '<S148>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/THM_OutputsProcessing/TMMFanRelayRequest/SR_latch'
 * '<S149>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/TRA_OutputsProcessingTrsm1/GearLvrPos'
 * '<S150>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/TRA_OutputsProcessingTrsm1/GearLvrPos/Enumerated Constant1'
 * '<S151>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/TRA_OutputsProcessingTrsm1/GearLvrPos/Enumerated Constant2'
 * '<S152>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/TRA_OutputsProcessingTrsm1/GearLvrPos/Enumerated Constant3'
 * '<S153>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/TRA_OutputsProcessingTrsm1/GearLvrPos/Enumerated Constant9'
 * '<S154>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/VSC_OutputsProcessing/RearAxleTorques'
 * '<S155>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/VSC_OutputsProcessing/VehicleSpeed'
 * '<S156>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VCO__Vehicle_Control_Outputs/VSC_OutputsProcessing/RearAxleTorques/Enumerated Constant1'
 * '<S157>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN'
 * '<S158>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW'
 * '<S159>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN'
 * '<S160>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD'
 * '<S161>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN'
 * '<S162>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_Acceleration'
 * '<S163>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_FrntHeatModEnad'
 * '<S164>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_FrntHeatPwrAllwd'
 * '<S165>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_HVIL1Sts_EV'
 * '<S166>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_HVIL1Sts_UB'
 * '<S167>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_HVIL2Sts_EV'
 * '<S168>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_HVIL2Sts_UB'
 * '<S169>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_HVILSts_EV'
 * '<S170>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_StsBatLockSensor'
 * '<S171>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_Acceleration/override_signal'
 * '<S172>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_FrntHeatModEnad/override_signal'
 * '<S173>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_FrntHeatPwrAllwd/override_signal'
 * '<S174>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_HVIL1Sts_EV/override_signal'
 * '<S175>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_HVIL1Sts_UB/override_signal'
 * '<S176>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_HVIL2Sts_EV/override_signal'
 * '<S177>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_HVIL2Sts_UB/override_signal'
 * '<S178>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_HVILSts_EV/override_signal'
 * '<S179>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/EV_CAN/Ovrd_PMS_StsBatLockSensor/override_signal'
 * '<S180>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW'
 * '<S181>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_12VbatRlyReq'
 * '<S182>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_12vDCDCEn'
 * '<S183>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_24vDCDCEn'
 * '<S184>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_acHvilDtyOutpt'
 * '<S185>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_acHvilPrdOutpt'
 * '<S186>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_b_ResetHSDFRA16A17'
 * '<S187>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_b_ResetHSDFRA1A2'
 * '<S188>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_b_ResetHSDFRA31A32'
 * '<S189>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_b_ResetHSDFRA46A47'
 * '<S190>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_b_VCUPwrModeCmd'
 * '<S191>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_b_VacPumpRlyEn'
 * '<S192>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_b_accyPreRlyCmd'
 * '<S193>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_b_cntnrCtrlEna'
 * '<S194>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_b_cntnrPwrEna'
 * '<S195>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_b_heater3EnaHW'
 * '<S196>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_b_heaterEnaHW'
 * '<S197>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_b_highSpdFanRlyReq'
 * '<S198>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_b_mainPosRlyReq'
 * '<S199>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_b_motFanRlyReq'
 * '<S200>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_b_preChrgRlyReq'
 * '<S201>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_brkPmpEn'
 * '<S202>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_emergStopEn'
 * '<S203>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_odpHvilDtyOutpt'
 * '<S204>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_odpHvilPrdOutpt'
 * '<S205>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_pct_AccPedal_1'
 * '<S206>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_pct_AccPedal_2'
 * '<S207>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_pct_BrkPedal_1'
 * '<S208>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_pct_BrkPedal_2'
 * '<S209>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_pct_fan1TgtSpd'
 * '<S210>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_pct_fan2TgtSpd'
 * '<S211>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_pct_fan3TgtSpd'
 * '<S212>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_pct_pmpEP1TgtSpd'
 * '<S213>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_pmpEP2TgtSpd_pct1'
 * '<S214>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_pmpEP3TgtFre_Hz'
 * '<S215>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_pmpEP3TgtSpd_pct'
 * '<S216>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_st_ShtDown'
 * '<S217>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_steerPumpEn'
 * '<S218>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_waterValveTV1V3_V'
 * '<S219>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_waterValveTV2V2_V'
 * '<S220>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_acHvilDtyOutpt/override_signal'
 * '<S221>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_acHvilPrdOutpt/override_signal'
 * '<S222>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_odpHvilDtyOutpt/override_signal'
 * '<S223>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/HW/HW/Ovrd_odpHvilPrdOutpt/override_signal'
 * '<S224>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output'
 * '<S225>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function'
 * '<S226>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output'
 * '<S227>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD'
 * '<S228>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMS_Ctrl1'
 * '<S229>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMS_DischargeEnable'
 * '<S230>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMS_NEWADD2'
 * '<S231>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMS_VehicleInfo'
 * '<S232>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl'
 * '<S233>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control'
 * '<S234>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo'
 * '<S235>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_CSControl1'
 * '<S236>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl'
 * '<S237>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ErrCode&TMCtrl'
 * '<S238>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl'
 * '<S239>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl2'
 * '<S240>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor1'
 * '<S241>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2'
 * '<S242>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor3'
 * '<S243>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor4'
 * '<S244>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_LockVehInfor'
 * '<S245>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_NWM'
 * '<S246>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_OBD_RequireInfo'
 * '<S247>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PFCUCtrl'
 * '<S248>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate'
 * '<S249>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_Test1'
 * '<S250>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_Test2'
 * '<S251>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VIN'
 * '<S252>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo'
 * '<S253>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ePTRegencyLevInd'
 * '<S254>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Enumerated Constant'
 * '<S255>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Enumerated Constant1'
 * '<S256>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Enumerated Constant2'
 * '<S257>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Enumerated Constant3'
 * '<S258>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_PMS_AccessoryCtrlCommand'
 * '<S259>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_PMS_BBM_FaultStatus'
 * '<S260>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_PMS_BBM_WorkSts'
 * '<S261>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_PMS_DrivingTakeEleSts'
 * '<S262>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_ACCY1CtrlCmd'
 * '<S263>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_ACCYEnableIn'
 * '<S264>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_ACUCrashfz_Back'
 * '<S265>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_APUSWILED_Ctrl'
 * '<S266>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_AccyAllowEnable_Ctrl'
 * '<S267>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_AccyPower_back'
 * '<S268>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_AvgEVConsume'
 * '<S269>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_AvgFuelVF'
 * '<S270>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_BattPackInCoolTempback'
 * '<S271>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_BattPackoutCoolTempback'
 * '<S272>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_ECOmodeSWILED_Ctrl'
 * '<S273>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_ECPM_FaultFB'
 * '<S274>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_EDCP_FaultFB'
 * '<S275>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_EVDTEodometer'
 * '<S276>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_FuleDTEodometer'
 * '<S277>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_HBCP_FaultFB'
 * '<S278>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_HTCoolingFan1FB'
 * '<S279>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_HV_Status'
 * '<S280>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_IntelligentChargeExitReq'
 * '<S281>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_IntelligentChargeQuit'
 * '<S282>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_IntelligentChargeState'
 * '<S283>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_LTCoolingFan2FB'
 * '<S284>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_PropulSysActive'
 * '<S285>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_ePTReleaseSig'
 * '<S286>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_PMS_AccessoryCtrlCommand/override_signal'
 * '<S287>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_PMS_BBM_FaultStatus/override_signal'
 * '<S288>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_PMS_BBM_WorkSts/override_signal'
 * '<S289>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_PMS_DrivingTakeEleSts/override_signal'
 * '<S290>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_ACCY1CtrlCmd/override_signal'
 * '<S291>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_ACCYEnableIn/override_signal'
 * '<S292>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_ACUCrashfz_Back/override_signal'
 * '<S293>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_APUSWILED_Ctrl/override_signal'
 * '<S294>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_AccyAllowEnable_Ctrl/override_signal'
 * '<S295>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_AccyPower_back/override_signal'
 * '<S296>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_AvgEVConsume/override_signal'
 * '<S297>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_AvgFuelVF/override_signal'
 * '<S298>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_BattPackInCoolTempback/override_signal'
 * '<S299>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_BattPackoutCoolTempback/override_signal'
 * '<S300>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_ECOmodeSWILED_Ctrl/override_signal'
 * '<S301>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_ECPM_FaultFB/override_signal'
 * '<S302>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_EDCP_FaultFB/override_signal'
 * '<S303>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_EVDTEodometer/override_signal'
 * '<S304>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_FuleDTEodometer/override_signal'
 * '<S305>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_HBCP_FaultFB/override_signal'
 * '<S306>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_HTCoolingFan1FB/override_signal'
 * '<S307>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_HV_Status/override_signal'
 * '<S308>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_IntelligentChargeExitReq/override_signal'
 * '<S309>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_IntelligentChargeQuit/override_signal'
 * '<S310>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_IntelligentChargeState/override_signal'
 * '<S311>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_LTCoolingFan2FB/override_signal'
 * '<S312>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_PropulSysActive/override_signal'
 * '<S313>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/8TREEV_BEV_Output/Ovrd_VCU_ePTReleaseSig/override_signal'
 * '<S314>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_CC_Acceleration'
 * '<S315>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_ExternalAccDemand'
 * '<S316>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_GP_Override'
 * '<S317>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_VLC_Active'
 * '<S318>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_VLC_Available'
 * '<S319>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_VLC_InternalTargetACCeleration'
 * '<S320>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_VLC_VCUTargetACCeleration'
 * '<S321>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_XBRControlMode'
 * '<S322>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_XBREBIMode'
 * '<S323>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_XBRPriority'
 * '<S324>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_CC_Acceleration/override_signal'
 * '<S325>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_ExternalAccDemand/override_signal'
 * '<S326>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_GP_Override/override_signal'
 * '<S327>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_VLC_Active/override_signal'
 * '<S328>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_VLC_Available/override_signal'
 * '<S329>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_VLC_InternalTargetACCeleration/override_signal'
 * '<S330>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_VLC_VCUTargetACCeleration/override_signal'
 * '<S331>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_XBRControlMode/override_signal'
 * '<S332>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_XBREBIMode/override_signal'
 * '<S333>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/ACC_Function/Ovrd_VCU_XBRPriority/override_signal'
 * '<S334>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Enumerated Constant3'
 * '<S335>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_BMS_SOC'
 * '<S336>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_BMS_voltage'
 * '<S337>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_BattMaxTemp'
 * '<S338>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_BattMinTemp'
 * '<S339>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_BattVol'
 * '<S340>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Batty_Charge_DisChargeState'
 * '<S341>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Batty_ThermalMangeActive'
 * '<S342>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Batty_ThermalMangeWorkMode'
 * '<S343>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Cab_ThermalMangeReq'
 * '<S344>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Cell_Avg_Temp'
 * '<S345>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Charger_Connected'
 * '<S346>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Cooling_Control_Request'
 * '<S347>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_EngFuelInstCons'
 * '<S348>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_HVOnOffReq'
 * '<S349>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_HybridReady'
 * '<S350>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_MCUActiveDischg'
 * '<S351>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Main_Contactor_Control'
 * '<S352>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Set_Temp'
 * '<S353>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_BMS_SOC/override_signal'
 * '<S354>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_BMS_voltage/override_signal'
 * '<S355>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_BattMaxTemp/override_signal'
 * '<S356>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_BattMinTemp/override_signal'
 * '<S357>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_BattVol/override_signal'
 * '<S358>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Batty_Charge_DisChargeState/override_signal'
 * '<S359>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Batty_ThermalMangeActive/override_signal'
 * '<S360>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Batty_ThermalMangeWorkMode/override_signal'
 * '<S361>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Cab_ThermalMangeReq/override_signal'
 * '<S362>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Cell_Avg_Temp/override_signal'
 * '<S363>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Charger_Connected/override_signal'
 * '<S364>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Cooling_Control_Request/override_signal'
 * '<S365>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_EngFuelInstCons/override_signal'
 * '<S366>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_HVOnOffReq/override_signal'
 * '<S367>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_HybridReady/override_signal'
 * '<S368>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_MCUActiveDischg/override_signal'
 * '<S369>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Main_Contactor_Control/override_signal'
 * '<S370>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/P2_Output/Ovrd_VCU_Set_Temp/override_signal'
 * '<S371>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Compare To Constant'
 * '<S372>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Compare To Constant1'
 * '<S373>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Compare To Constant2'
 * '<S374>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_AC_EWP_Heat'
 * '<S375>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_AC_EWP_HeatrPwrCnsAllwd'
 * '<S376>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_AC_EWP_Run'
 * '<S377>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_AC_EWP_SpeedReq'
 * '<S378>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_AC_EWP_Temp'
 * '<S379>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_PMS_AcceSuppressionSts'
 * '<S380>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_PMS_CPSRU'
 * '<S381>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_PMS_ChargPwr'
 * '<S382>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_PMS_Fn1GearRlyDrvStsFb'
 * '<S383>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_PMS_Fn2GearRlyDrvStsFb'
 * '<S384>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_PMS_LockVehExecutedSts'
 * '<S385>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_PMS_RegulationSpeed'
 * '<S386>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_PMS_RemChrgCmdFailrPrompt'
 * '<S387>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_PMS_TakeEleSwtIndReq'
 * '<S388>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_PMS_Torque_Ovrd_Active'
 * '<S389>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_PMS_Torque_Ovrd_Type'
 * '<S390>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_TBOX_ChrgSoftSwCtrlst'
 * '<S391>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_TBOX_ReservationChrgnSts'
 * '<S392>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/Ovrd_VCU_DriveCircuitTemp'
 * '<S393>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMSNEW_ADD/kxx2xx'
 * '<S394>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMS_Ctrl1/Ovrd_VCU_PTC2Enable'
 * '<S395>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMS_Ctrl1/Ovrd_VCU_PTC3Enable'
 * '<S396>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMS_Ctrl1/Ovrd_VCU_ZeroPwr_Fb'
 * '<S397>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMS_DischargeEnable/Ovrd_VCU_DischargeEnable'
 * '<S398>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMS_NEWADD2/Ovrd_PMS_VehicleSysErrorLevelG'
 * '<S399>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMS_VehicleInfo/Ovrd_VCU_BMSHAllowChgCurrentMax'
 * '<S400>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/PMS_VehicleInfo/Ovrd_VCU_ChargeDepthReq'
 * '<S401>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_EDCP_Flt'
 * '<S402>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_HBCP_Flt'
 * '<S403>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_PMS_HvCoolgPwrAllwd'
 * '<S404>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_PMS_HvHeatgPwrAllwd'
 * '<S405>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_PMS_MCUFlowFeedback_EV'
 * '<S406>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_PMS_ThermalReq'
 * '<S407>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_PMS_ThermalReq1'
 * '<S408>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_ACCMEnable'
 * '<S409>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_BattPackInCoolTemp'
 * '<S410>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_BattPackoutCoolTemp'
 * '<S411>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_BatteryCoolentTemp'
 * '<S412>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_Batty_ThermalMangeReq'
 * '<S413>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_PMS_APPowerActual_EV'
 * '<S414>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_PTCEnable'
 * '<S415>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_WPCtrl'
 * '<S416>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_EDCP_Flt/override_signal'
 * '<S417>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_HBCP_Flt/override_signal'
 * '<S418>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_PMS_HvCoolgPwrAllwd/override_signal'
 * '<S419>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_PMS_HvHeatgPwrAllwd/override_signal'
 * '<S420>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_PMS_MCUFlowFeedback_EV/override_signal'
 * '<S421>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_PMS_ThermalReq/override_signal'
 * '<S422>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_PMS_ThermalReq1/override_signal'
 * '<S423>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_ACCMEnable/override_signal'
 * '<S424>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_BattPackInCoolTemp/override_signal'
 * '<S425>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_BattPackoutCoolTemp/override_signal'
 * '<S426>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_BatteryCoolentTemp/override_signal'
 * '<S427>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_Batty_ThermalMangeReq/override_signal'
 * '<S428>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_PMS_APPowerActual_EV/override_signal'
 * '<S429>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_PTCEnable/override_signal'
 * '<S430>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ACCtrl/Ovrd_VCU_WPCtrl/override_signal'
 * '<S431>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_12VATS1Enable'
 * '<S432>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_12VATS1_PWMRequest'
 * '<S433>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS1Enable'
 * '<S434>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS1_PWMRequest'
 * '<S435>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS2Enable'
 * '<S436>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS2_PWMRequest'
 * '<S437>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS3Enable'
 * '<S438>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS3_PWMRequest'
 * '<S439>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS4Enable'
 * '<S440>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS4_PWMRequest'
 * '<S441>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_12VATS1Enable/override_signal'
 * '<S442>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_12VATS1_PWMRequest/override_signal'
 * '<S443>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS1Enable/override_signal'
 * '<S444>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS1_PWMRequest/override_signal'
 * '<S445>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS2Enable/override_signal'
 * '<S446>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS2_PWMRequest/override_signal'
 * '<S447>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS3Enable/override_signal'
 * '<S448>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS3_PWMRequest/override_signal'
 * '<S449>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS4Enable/override_signal'
 * '<S450>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ATS_Control/Ovrd_VCU_ATS4_PWMRequest/override_signal'
 * '<S451>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_PMS_Real_PedalPosition'
 * '<S452>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_PMS_Real_PedalPositionInvalid'
 * '<S453>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_ACActiveReq'
 * '<S454>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_AcceleratorPedalPosition'
 * '<S455>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_AcceleratorPedal_flag'
 * '<S456>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_BrakSwitchSts'
 * '<S457>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_BrakePedalPosition'
 * '<S458>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_DriverOperationReminder'
 * '<S459>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_HandbrakeSts2'
 * '<S460>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_StsBrkSwitch1Invalid'
 * '<S461>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_VehicleSpd'
 * '<S462>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_VehicleSpd_flag'
 * '<S463>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_PMS_Real_PedalPosition/override_signal'
 * '<S464>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_PMS_Real_PedalPositionInvalid/override_signal'
 * '<S465>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_ACActiveReq/override_signal'
 * '<S466>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_AcceleratorPedalPosition/override_signal'
 * '<S467>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_AcceleratorPedal_flag/override_signal'
 * '<S468>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_BrakSwitchSts/override_signal'
 * '<S469>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_BrakePedalPosition/override_signal'
 * '<S470>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_DriverOperationReminder/override_signal'
 * '<S471>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_HandbrakeSts2/override_signal'
 * '<S472>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_StsBrkSwitch1Invalid/override_signal'
 * '<S473>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_VehicleSpd/override_signal'
 * '<S474>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_BodyControlInfo/Ovrd_VCU_VehicleSpd_flag/override_signal'
 * '<S475>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_CSControl1/Ovrd_VCU_ControlSetSpeed'
 * '<S476>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_CSControl1/Ovrd_VCU_ControlSetSpeed_Mode'
 * '<S477>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_CSControl1/Ovrd_VCU_CruiseControlSts'
 * '<S478>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_CSControl1/Ovrd_VCU_CruiseSwSts'
 * '<S479>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_CSControl1/Ovrd_VCU_CruiseSwerrorSts'
 * '<S480>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_CSControl1/Ovrd_VCU_QuitControlSpeed'
 * '<S481>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_CSControl1/Ovrd_VCU_ControlSetSpeed/override_signal'
 * '<S482>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_CSControl1/Ovrd_VCU_ControlSetSpeed_Mode/override_signal'
 * '<S483>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_CSControl1/Ovrd_VCU_CruiseControlSts/override_signal'
 * '<S484>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_CSControl1/Ovrd_VCU_CruiseSwSts/override_signal'
 * '<S485>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_CSControl1/Ovrd_VCU_CruiseSwerrorSts/override_signal'
 * '<S486>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_CSControl1/Ovrd_VCU_QuitControlSpeed/override_signal'
 * '<S487>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_PMS_IsgActvDampgModReq'
 * '<S488>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_DriveReqTrqPercent'
 * '<S489>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_EM1CtrlMode'
 * '<S490>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_EM1WorkMode'
 * '<S491>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_EMCtrlMode'
 * '<S492>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_EMWorkMode'
 * '<S493>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MCU1EnableReq'
 * '<S494>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MCUEnableReq'
 * '<S495>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MCUMaxTrq'
 * '<S496>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MCUSpdRampRate'
 * '<S497>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MCUTqRampRate'
 * '<S498>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MCU_MotorActTrqPercent'
 * '<S499>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MaxEMPwrLmt'
 * '<S500>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MinEMPwrLmt'
 * '<S501>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MotorSpeed'
 * '<S502>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MotorTorque'
 * '<S503>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_ReqSpdOrLmt'
 * '<S504>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_ReqTrqOrLmt'
 * '<S505>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Subsystem1'
 * '<S506>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Subsystem2'
 * '<S507>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Subsystem3'
 * '<S508>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Subsystem5'
 * '<S509>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_PMS_IsgActvDampgModReq/override_signal'
 * '<S510>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_DriveReqTrqPercent/override_signal'
 * '<S511>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_EM1CtrlMode/override_signal'
 * '<S512>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_EM1WorkMode/override_signal'
 * '<S513>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_EMCtrlMode/override_signal'
 * '<S514>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_EMWorkMode/override_signal'
 * '<S515>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MCU1EnableReq/override_signal'
 * '<S516>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MCUEnableReq/override_signal'
 * '<S517>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MCUMaxTrq/override_signal'
 * '<S518>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MCUSpdRampRate/override_signal'
 * '<S519>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MCUTqRampRate/override_signal'
 * '<S520>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MCU_MotorActTrqPercent/override_signal'
 * '<S521>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MaxEMPwrLmt/override_signal'
 * '<S522>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MinEMPwrLmt/override_signal'
 * '<S523>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MotorSpeed/override_signal'
 * '<S524>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_MotorTorque/override_signal'
 * '<S525>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_ReqSpdOrLmt/override_signal'
 * '<S526>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_EMTrqSpdCtrl/Ovrd_VCU_ReqTrqOrLmt/override_signal'
 * '<S527>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ErrCode&TMCtrl/Ovrd_VCU_AEC'
 * '<S528>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ErrCode&TMCtrl/Ovrd_VCU_DTE'
 * '<S529>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ErrCode&TMCtrl/Ovrd_VCU_ErrCode'
 * '<S530>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ErrCode&TMCtrl/Ovrd_VCU_PTResiPwr'
 * '<S531>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ErrCode&TMCtrl/Ovrd_VCU_AEC/override_signal'
 * '<S532>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ErrCode&TMCtrl/Ovrd_VCU_DTE/override_signal'
 * '<S533>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ErrCode&TMCtrl/Ovrd_VCU_ErrCode/override_signal'
 * '<S534>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ErrCode&TMCtrl/Ovrd_VCU_PTResiPwr/override_signal'
 * '<S535>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_12VDCDCCutOffLV'
 * '<S536>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_12VDCDCEnableOut'
 * '<S537>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_AllowChg'
 * '<S538>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_BMSHVOnOffReq'
 * '<S539>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_BMSH_DCChgRelayVolt'
 * '<S540>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_DCDCPwrLmt'
 * '<S541>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_HazardReq'
 * '<S542>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_IntelLockLoopSts'
 * '<S543>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_MainPosCtrlCommand'
 * '<S544>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_SDCACOutFreq'
 * '<S545>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_SDCACStopFault'
 * '<S546>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_SelfCheckSts'
 * '<S547>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_bmsModeStsReq'
 * '<S548>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_12VDCDCCutOffLV/override_signal'
 * '<S549>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_12VDCDCEnableOut/override_signal'
 * '<S550>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_AllowChg/override_signal'
 * '<S551>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_BMSHVOnOffReq/override_signal'
 * '<S552>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_BMSH_DCChgRelayVolt/override_signal'
 * '<S553>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_DCDCPwrLmt/override_signal'
 * '<S554>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_HazardReq/override_signal'
 * '<S555>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_IntelLockLoopSts/override_signal'
 * '<S556>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_MainPosCtrlCommand/override_signal'
 * '<S557>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_SDCACOutFreq/override_signal'
 * '<S558>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_SDCACStopFault/override_signal'
 * '<S559>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_SelfCheckSts/override_signal'
 * '<S560>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl/Ovrd_VCU_bmsModeStsReq/override_signal'
 * '<S561>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl2/Ovrd_VCU_BPTCCtrlCmd'
 * '<S562>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl2/Subsystem2'
 * '<S563>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HVFunctionCtrl2/Ovrd_VCU_BPTCCtrlCmd/override_signal'
 * '<S564>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor1/Ovrd_VCU_ACC1PosVol'
 * '<S565>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor1/Ovrd_VCU_ACC2PosVol'
 * '<S566>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor1/Ovrd_VCU_AppSts'
 * '<S567>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor1/Ovrd_VCU_BatteryVol'
 * '<S568>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor1/Ovrd_VCU_Brake1Sts'
 * '<S569>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor1/Ovrd_VCU_Brake2Sts'
 * '<S570>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor1/Ovrd_VCU_ECOMode'
 * '<S571>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor1/Ovrd_VCU_HVPRASts'
 * '<S572>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor1/Ovrd_VCU_IgnONSts'
 * '<S573>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor1/Ovrd_VCU_ShiftClimbing'
 * '<S574>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor1/Ovrd_VCU_ShiftD'
 * '<S575>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor1/Ovrd_VCU_ShiftR'
 * '<S576>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor1/Ovrd_VCU_StartSts'
 * '<S577>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2/Ovrd_PMS_AccessoryConnStsFb'
 * '<S578>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2/Ovrd_PMS_AccessoryRelayFlt'
 * '<S579>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2/Ovrd_PMS_PTC1ConnStsFb'
 * '<S580>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2/Ovrd_PMS_PTC1RelayFlt'
 * '<S581>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2/Ovrd_PMS_PTC3ConnStsFb'
 * '<S582>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2/Ovrd_PMS_PTC3RelayFlt'
 * '<S583>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2/Ovrd_PMS_PreAccessoryConnStsFb'
 * '<S584>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2/Ovrd_PMS_PreAccessoryRelayFlt'
 * '<S585>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2/Ovrd_VCU_CCFb'
 * '<S586>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2/Ovrd_VCU_Cabin_PumpFb'
 * '<S587>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2/Ovrd_VCU_ChargWakeupSts'
 * '<S588>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2/Ovrd_VCU_EManualStartSwi'
 * '<S589>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2/Ovrd_VCU_HVB_PumpFb'
 * '<S590>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2/Ovrd_VCU_PressureSwi1Sts'
 * '<S591>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor2/Ovrd_VCU_PressureSwi2Sts'
 * '<S592>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor3/Ovrd_VCU_Brake1PosVol'
 * '<S593>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor3/Ovrd_VCU_Brake2PosVol'
 * '<S594>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor3/Ovrd_VCU_EmergencyStop'
 * '<S595>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor3/Ovrd_VCU_GearPositionInput'
 * '<S596>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor3/Ovrd_VCU_HVILReturn'
 * '<S597>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor4/Ovrd_VCU_BattCoolVal3_FBV5'
 * '<S598>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor4/Ovrd_VCU_BattCoolVal3_FBV6'
 * '<S599>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor4/Ovrd_VCU_BattHeatVal2_FBV5'
 * '<S600>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor4/Ovrd_VCU_BattHeatVal2_FBV6'
 * '<S601>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor4/Ovrd_VCU_CabinLoopVal1_FBV6'
 * '<S602>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor4/Ovrd_VCU_CabinLoopVal2_FBV5'
 * '<S603>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_HardInfor4/Ovrd_VCU_DriveCircuitVol'
 * '<S604>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_LockVehInfor/Ovrd_VCU_FunAnti_DismantleActive'
 * '<S605>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_LockVehInfor/Ovrd_VCU_FunLockVehActive'
 * '<S606>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_LockVehInfor/Ovrd_VCU_LockLimResult'
 * '<S607>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_LockVehInfor/Ovrd_VCU_LockVehSts'
 * '<S608>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_LockVehInfor/Ovrd_VCU_LockVehType'
 * '<S609>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_LockVehInfor/Ovrd_VCU_FunAnti_DismantleActive/override_signal'
 * '<S610>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_LockVehInfor/Ovrd_VCU_FunLockVehActive/override_signal'
 * '<S611>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_LockVehInfor/Ovrd_VCU_LockLimResult/override_signal'
 * '<S612>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_LockVehInfor/Ovrd_VCU_LockVehSts/override_signal'
 * '<S613>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_LockVehInfor/Ovrd_VCU_LockVehType/override_signal'
 * '<S614>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_NWM/Ovrd_VCU_AWB'
 * '<S615>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_NWM/Ovrd_VCU_Address'
 * '<S616>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_NWM/Ovrd_VCU_NMSts'
 * '<S617>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_NWM/Ovrd_VCU_RMR'
 * '<S618>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_NWM/Ovrd_VCU_Stayawake_reasons'
 * '<S619>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_NWM/Ovrd_VCU_Wakeup_reasons'
 * '<S620>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_NWM/Ovrd_VCU_AWB/override_signal'
 * '<S621>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_NWM/Ovrd_VCU_Address/override_signal'
 * '<S622>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_NWM/Ovrd_VCU_NMSts/override_signal'
 * '<S623>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_NWM/Ovrd_VCU_RMR/override_signal'
 * '<S624>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_NWM/Ovrd_VCU_Stayawake_reasons/override_signal'
 * '<S625>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_NWM/Ovrd_VCU_Wakeup_reasons/override_signal'
 * '<S626>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_OBD_RequireInfo/Ovrd_VCU_AccePedalPosD'
 * '<S627>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_OBD_RequireInfo/Ovrd_VCU_AccePedalPosE'
 * '<S628>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_OBD_RequireInfo/Ovrd_VCU_MILTelltale'
 * '<S629>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_OBD_RequireInfo/Ovrd_VCU_TotalOdometer'
 * '<S630>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_OBD_RequireInfo/Ovrd_VCU_TotalOdometerInvalid'
 * '<S631>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_OBD_RequireInfo/Ovrd_VCU_AccePedalPosD/override_signal'
 * '<S632>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_OBD_RequireInfo/Ovrd_VCU_AccePedalPosE/override_signal'
 * '<S633>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_OBD_RequireInfo/Ovrd_VCU_MILTelltale/override_signal'
 * '<S634>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_OBD_RequireInfo/Ovrd_VCU_TotalOdometer/override_signal'
 * '<S635>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_OBD_RequireInfo/Ovrd_VCU_TotalOdometerInvalid/override_signal'
 * '<S636>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PFCUCtrl/Ovrd_VCU_VehicleSysFltLevel'
 * '<S637>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PFCUCtrl/Ovrd_VCU_VehicleSysFltLevel/override_signal'
 * '<S638>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Compare To Constant1'
 * '<S639>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_PMS_CurrentGearPositionValid'
 * '<S640>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_BrkSysErr'
 * '<S641>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_DCDC_WorkSts'
 * '<S642>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_DriveModeInd'
 * '<S643>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_DrivePwrCircuitInd'
 * '<S644>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_EVanualStartSwi'
 * '<S645>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_GearOperateErr'
 * '<S646>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_GearPositionInd'
 * '<S647>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_HandbrakeSts'
 * '<S648>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_IgniteSts'
 * '<S649>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_PTHVSysErrorLampStsInd'
 * '<S650>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_PTModeInd'
 * '<S651>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_PTReadyInd'
 * '<S652>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_PTSysElecPwrInd'
 * '<S653>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_TurtleLampReq'
 * '<S654>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_VehicleAbnormalSts'
 * '<S655>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_VehicleRunMode'
 * '<S656>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_VehicleSlipWarning'
 * '<S657>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_VehicleSubSysErrorLevel'
 * '<S658>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_VehicleSysErrorLevel'
 * '<S659>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_PMS_CurrentGearPositionValid/override_signal'
 * '<S660>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_BrkSysErr/override_signal'
 * '<S661>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_DCDC_WorkSts/override_signal'
 * '<S662>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_DriveModeInd/override_signal'
 * '<S663>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_DrivePwrCircuitInd/override_signal'
 * '<S664>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_EVanualStartSwi/override_signal'
 * '<S665>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_GearOperateErr/override_signal'
 * '<S666>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_GearPositionInd/override_signal'
 * '<S667>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_HandbrakeSts/override_signal'
 * '<S668>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_IgniteSts/override_signal'
 * '<S669>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_PTHVSysErrorLampStsInd/override_signal'
 * '<S670>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_PTModeInd/override_signal'
 * '<S671>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_PTReadyInd/override_signal'
 * '<S672>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_PTSysElecPwrInd/override_signal'
 * '<S673>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_TurtleLampReq/override_signal'
 * '<S674>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_VehicleAbnormalSts/override_signal'
 * '<S675>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_VehicleRunMode/override_signal'
 * '<S676>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_VehicleSlipWarning/override_signal'
 * '<S677>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_VehicleSubSysErrorLevel/override_signal'
 * '<S678>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_PTInfoIndicate/Ovrd_VCU_VehicleSysErrorLevel/override_signal'
 * '<S679>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_Test1/Ovrd_VCU_24V_Switch'
 * '<S680>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_Test1/Ovrd_VCU_EV_Switch'
 * '<S681>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_Test1/Ovrd_VCU_FanPWM_Ctrl'
 * '<S682>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_Test1/Ovrd_VCU_Idle_Switch'
 * '<S683>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_Test1/Ovrd_VCU_InhibitHybrid_Switch'
 * '<S684>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_Test1/Ovrd_VCU_MCU_PumpPWM_Ctrl'
 * '<S685>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_Test1/Ovrd_VCU_MCU_RelayCtrl_Ctrl'
 * '<S686>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_Test1/Ovrd_VCU_PreRelay_Ctrl'
 * '<S687>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_Test1/Ovrd_VCU_RelayCtrl_Ctrl'
 * '<S688>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_Test2/Ovrd_VCU_VehCruisingDistance'
 * '<S689>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VIN/Ovrd_VCU_VehicleIdentification'
 * '<S690>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VIN/Ovrd_VCU_VehicleIdentification/override_signal'
 * '<S691>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_CalibrationMajorVer1'
 * '<S692>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_CalibrationMajorVer2'
 * '<S693>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_CalibrationMajorVer3'
 * '<S694>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_CalibrationMinorVer1'
 * '<S695>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_CalibrationMinorVer2'
 * '<S696>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_CalibrationMinorVer3'
 * '<S697>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_HardwareMajorVer'
 * '<S698>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_HardwareMinorVer'
 * '<S699>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_SWCompileDay'
 * '<S700>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_SWCompileMonth'
 * '<S701>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_SWCompileYear'
 * '<S702>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_SoftwareMajorVer'
 * '<S703>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_SoftwareMinorVer'
 * '<S704>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_CalibrationMajorVer1/override_signal'
 * '<S705>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_CalibrationMajorVer2/override_signal'
 * '<S706>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_CalibrationMajorVer3/override_signal'
 * '<S707>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_CalibrationMinorVer1/override_signal'
 * '<S708>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_CalibrationMinorVer2/override_signal'
 * '<S709>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_CalibrationMinorVer3/override_signal'
 * '<S710>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_HardwareMajorVer/override_signal'
 * '<S711>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_HardwareMinorVer/override_signal'
 * '<S712>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_SWCompileDay/override_signal'
 * '<S713>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_SWCompileMonth/override_signal'
 * '<S714>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_SWCompileYear/override_signal'
 * '<S715>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_SoftwareMajorVer/override_signal'
 * '<S716>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_VerInfo/Ovrd_VCU_SoftwareMinorVer/override_signal'
 * '<S717>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/Hybrid_CAN/VCU_ePTRegencyLevInd/Ovrd_VCU_ePTRegencyLevInd'
 * '<S718>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_ACChgTimeRemain'
 * '<S719>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_BattCurr'
 * '<S720>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_BattFaultLampState'
 * '<S721>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_CCM_ThermalManageReq'
 * '<S722>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_Cell_TotalNum'
 * '<S723>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_ChargeLEDCtrl'
 * '<S724>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_Charge_Over_Current'
 * '<S725>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_ChgTimeRemain'
 * '<S726>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_DCChgminusSocketTempSensing_Failure'
 * '<S727>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_DCChgplusSocketTempSensing_Failure'
 * '<S728>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_FastChgCC2ConntState'
 * '<S729>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_InsulationRes_Fault'
 * '<S730>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_ThermalOutofControl'
 * '<S731>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_Vehicle_HVILSts_PHEV'
 * '<S732>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_32960FltNum'
 * '<S733>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_ActualPTTorque'
 * '<S734>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_BMS_Reignstatus1'
 * '<S735>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_BMS_Reignstatus2'
 * '<S736>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_Brake_LightsRequest'
 * '<S737>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_CampModeFb'
 * '<S738>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_CampModeFbFailrReason'
 * '<S739>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_ChargeLimitResponse'
 * '<S740>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_CruisingDstSwtFb'
 * '<S741>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_DriverDemandTorque'
 * '<S742>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_DrvPfmncRedn'
 * '<S743>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_EPBClosedReq_PMS'
 * '<S744>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_GearIntervene'
 * '<S745>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_GrossComVehWeight'
 * '<S746>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_IPKTotalOdometer'
 * '<S747>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_InventorySpdLmtRxSts'
 * '<S748>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_InventorySpdLmtSts'
 * '<S749>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_Life'
 * '<S750>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_LockVehPerFlag'
 * '<S751>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_LockVehPerRxSts'
 * '<S752>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_MaxPTTorqueAllowed'
 * '<S753>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_MinPTTorqueAllowed'
 * '<S754>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_OTAInstrucStsReminder'
 * '<S755>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_OTAInstructRxnSts'
 * '<S756>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_Odometerbackup'
 * '<S757>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_OdometerbackupEnable'
 * '<S758>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_PowerOffCmdRxSts'
 * '<S759>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_PowerOffCmdSts'
 * '<S760>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_RegenTarTrqPot'
 * '<S761>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_RegenTrqAct'
 * '<S762>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_RegenTrqPot'
 * '<S763>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_SpdLmtLevel'
 * '<S764>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_SpdLmtLevelRxSts'
 * '<S765>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_TBOX_HVILState'
 * '<S766>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_TBOX_LifeSts'
 * '<S767>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_V2XDchaSwtFb1'
 * '<S768>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINCode1_8_15_S'
 * '<S769>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINCode2_9_16_S'
 * '<S770>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINCode3_10_17_S'
 * '<S771>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINCode4_11_S'
 * '<S772>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINCode5_12_S'
 * '<S773>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINCode6_13_S'
 * '<S774>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINCode7_14_S'
 * '<S775>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINMessageNum_S'
 * '<S776>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VacuumPressure'
 * '<S777>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VacuumPump_FB'
 * '<S778>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VacuumSystemsta'
 * '<S779>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VersionConversionFlag'
 * '<S780>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VersionConversionRxSts'
 * '<S781>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_ePTFault'
 * '<S782>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_VCU_CrashOutputSts'
 * '<S783>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_ACChgTimeRemain/override_signal'
 * '<S784>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_BattCurr/override_signal'
 * '<S785>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_BattFaultLampState/override_signal'
 * '<S786>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_CCM_ThermalManageReq/override_signal'
 * '<S787>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_Cell_TotalNum/override_signal'
 * '<S788>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_ChargeLEDCtrl/override_signal'
 * '<S789>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_Charge_Over_Current/override_signal'
 * '<S790>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_ChgTimeRemain/override_signal'
 * '<S791>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_DCChgminusSocketTempSensing_Failure/override_signal'
 * '<S792>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_DCChgplusSocketTempSensing_Failure/override_signal'
 * '<S793>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_FastChgCC2ConntState/override_signal'
 * '<S794>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_InsulationRes_Fault/override_signal'
 * '<S795>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_ThermalOutofControl/override_signal'
 * '<S796>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_BMSH_Vehicle_HVILSts_PHEV/override_signal'
 * '<S797>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_32960FltNum/override_signal'
 * '<S798>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_ActualPTTorque/override_signal'
 * '<S799>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_BMS_Reignstatus1/override_signal'
 * '<S800>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_BMS_Reignstatus2/override_signal'
 * '<S801>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_Brake_LightsRequest/override_signal'
 * '<S802>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_CampModeFb/override_signal'
 * '<S803>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_CampModeFbFailrReason/override_signal'
 * '<S804>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_ChargeLimitResponse/override_signal'
 * '<S805>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_CruisingDstSwtFb/override_signal'
 * '<S806>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_DriverDemandTorque/override_signal'
 * '<S807>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_DrvPfmncRedn/override_signal'
 * '<S808>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_EPBClosedReq_PMS/override_signal'
 * '<S809>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_GearIntervene/override_signal'
 * '<S810>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_GrossComVehWeight/override_signal'
 * '<S811>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_IPKTotalOdometer/override_signal'
 * '<S812>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_InventorySpdLmtRxSts/override_signal'
 * '<S813>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_InventorySpdLmtSts/override_signal'
 * '<S814>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_Life/override_signal'
 * '<S815>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_LockVehPerFlag/override_signal'
 * '<S816>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_LockVehPerRxSts/override_signal'
 * '<S817>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_MaxPTTorqueAllowed/override_signal'
 * '<S818>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_MinPTTorqueAllowed/override_signal'
 * '<S819>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_OTAInstrucStsReminder/override_signal'
 * '<S820>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_OTAInstructRxnSts/override_signal'
 * '<S821>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_Odometerbackup/override_signal'
 * '<S822>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_OdometerbackupEnable/override_signal'
 * '<S823>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_PowerOffCmdRxSts/override_signal'
 * '<S824>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_PowerOffCmdSts/override_signal'
 * '<S825>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_RegenTarTrqPot/override_signal'
 * '<S826>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_RegenTrqAct/override_signal'
 * '<S827>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_RegenTrqPot/override_signal'
 * '<S828>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_SpdLmtLevel/override_signal'
 * '<S829>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_SpdLmtLevelRxSts/override_signal'
 * '<S830>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_TBOX_HVILState/override_signal'
 * '<S831>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_TBOX_LifeSts/override_signal'
 * '<S832>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_V2XDchaSwtFb1/override_signal'
 * '<S833>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINCode1_8_15_S/override_signal'
 * '<S834>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINCode2_9_16_S/override_signal'
 * '<S835>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINCode3_10_17_S/override_signal'
 * '<S836>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINCode4_11_S/override_signal'
 * '<S837>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINCode5_12_S/override_signal'
 * '<S838>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINCode6_13_S/override_signal'
 * '<S839>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINCode7_14_S/override_signal'
 * '<S840>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VINMessageNum_S/override_signal'
 * '<S841>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VacuumPressure/override_signal'
 * '<S842>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VacuumPump_FB/override_signal'
 * '<S843>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VacuumSystemsta/override_signal'
 * '<S844>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VersionConversionFlag/override_signal'
 * '<S845>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_VersionConversionRxSts/override_signal'
 * '<S846>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_PMS_ePTFault/override_signal'
 * '<S847>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PMS_CANFD/Ovrd_VCU_CrashOutputSts/override_signal'
 * '<S848>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/PMS_RelaySampSwich'
 * '<S849>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_BPTCCtrlCmd'
 * '<S850>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_MassEstimation'
 * '<S851>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_PBSC'
 * '<S852>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_PFCUCtrl'
 * '<S853>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_TCU_TC1'
 * '<S854>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_WPC_CtrlCmd'
 * '<S855>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/PMS_RelaySampSwich/Ovrd_PMS_AcceRelayVoltSampSwich'
 * '<S856>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/PMS_RelaySampSwich/Ovrd_PMS_PTCRelayVoltSampSwich'
 * '<S857>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/PMS_RelaySampSwich/Ovrd_PMS_AcceRelayVoltSampSwich/override_signal'
 * '<S858>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/PMS_RelaySampSwich/Ovrd_PMS_PTCRelayVoltSampSwich/override_signal'
 * '<S859>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_BPTCCtrlCmd/Ovrd_VCU_BPTCEnable'
 * '<S860>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_BPTCCtrlCmd/Ovrd_VCU_BPTCPowerRatio'
 * '<S861>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_BPTCCtrlCmd/Ovrd_VCU_BPTCTempSetting'
 * '<S862>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_MassEstimation/Ovrd_VCU_CalNum'
 * '<S863>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_MassEstimation/Ovrd_VCU_OverloadInd'
 * '<S864>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_MassEstimation/Ovrd_VCU_VehicleWeight'
 * '<S865>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_MassEstimation/Ovrd_VCU_CalNum/override_signal'
 * '<S866>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_MassEstimation/Ovrd_VCU_OverloadInd/override_signal'
 * '<S867>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_MassEstimation/Ovrd_VCU_VehicleWeight/override_signal'
 * '<S868>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_PBSC/Ovrd_VCU_ActualGear'
 * '<S869>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_PBSC/Ovrd_VCU_ActualGear/override_signal'
 * '<S870>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_PFCUCtrl/Ovrd_VCU_Oil_HV_OFF'
 * '<S871>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_TCU_TC1/Ovrd_VCU_DrivingTakeForceSts'
 * '<S872>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_TCU_TC1/Ovrd_VCU_Gearshift_Resp'
 * '<S873>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_TCU_TC1/Ovrd_VCU_DrivingTakeForceSts/override_signal'
 * '<S874>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_TCU_TC1/Ovrd_VCU_Gearshift_Resp/override_signal'
 * '<S875>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_WPC_CtrlCmd/Ovrd_VCU_EDCP_Enable'
 * '<S876>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_WPC_CtrlCmd/Ovrd_VCU_EDCP_PWMCtrl'
 * '<S877>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_WPC_CtrlCmd/Ovrd_VCU_HBCP_Enable'
 * '<S878>' : 'swc_VCOP/VCOP__VCU_Outputs_Processing/VOL__VCU_Output_Layer/PT_CAN/VCU_WPC_CtrlCmd/Ovrd_VCU_HBCP_PWMCtrl'
 */
#endif                                 /* RTW_HEADER_swc_VCOP_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

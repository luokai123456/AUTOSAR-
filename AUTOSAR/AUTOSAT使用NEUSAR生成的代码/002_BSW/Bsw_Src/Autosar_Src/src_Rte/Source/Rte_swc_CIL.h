 
/*
************************************************************************************************************************
*
* File name: Rte_swc_CIL.h
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
#ifndef RTE_SWC_CIL_H_
#define RTE_SWC_CIL_H_

#include "Rte_swc_CIL_Type.h"
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
extern VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_CIL_BMC_UCell_BMC_UCell;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ChAllwd_BSOF_ChAllwd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_DirChAndDcha_BSOF_DirChAndDcha;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_EChSng_BSOF_EChSng;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChImpo_BSOF_ErrChImpo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrIDe_BSOF_ErrIDe;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrUAbno_BSOF_ErrUAbno;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrUndfnd_BSOF_ErrUndfnd;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IChrgr_BSOF_IChrgr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IChrgrMax_BSOF_IChrgrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IChrgrMin_BSOF_IChrgrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IDchaMax_BSOF_IDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IDchaMin_BSOF_IDchaMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_NrChrgrComVers_BSOF_NrChrgrComVers;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_SocDchaMax_BSOF_SocDchaMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_SocDchaMin_BSOF_SocDchaMin;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_BSOF_TiChAccumd_BSOF_TiChAccumd;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UChrgr_BSOF_UChrgr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UChrgrMax_BSOF_UChrgrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UChrgrMin_BSOF_UChrgrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UDchaMax_BSOF_UDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UDchaMin_BSOF_UDchaMin;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrChDetd_BSOF_bEnaMsgChrgrChDetd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrChSt_BSOF_bEnaMsgChrgrChSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrChSuspd_BSOF_bEnaMsgChrgrChSuspd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrDetnCnct_BSOF_bEnaMsgChrgrDetnCnct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrErr_BSOF_bEnaMsgChrgrErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrHdshk_BSOF_bEnaMsgChrgrHdshk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrMaxOut_BSOF_bEnaMsgChrgrMaxOut;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrMaxOutPgtn_BSOF_bEnaMsgChrgrMaxOutPgtn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrRcgtn_BSOF_bEnaMsgChrgrRcgtn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrRdy_BSOF_bEnaMsgChrgrRdy;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrStstc_BSOF_bEnaMsgChrgrStstc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrStstcForPgtn_BSOF_bEnaMsgChrgrStstcForPgtn;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bErrMsgTout_BSOF_bErrMsgTout;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_ActInputVolt_CIL_ActInputVolt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_BMSH_StsModeReq_CIL_BMSH_StsModeReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_BatCoolType_CIL_BatCoolType;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_CP_Vol_CIL_CP_Vol;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_CfgLvl2_CIL_CfgLvl2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ChargeDepthReq_CIL_ChargeDepthReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ChgCCSts_CIL_ChgCCSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DayRtc_CIL_DayRtc;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_DayTelbox_CIL_DayTelbox;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_DucycCrash_CIL_DucycCrash;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DucycCtlPilot_CIL_DucycCtlPilot;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_DucycHvil_CIL_DucycHvil;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_ElectroniclockVolt_CIL_ElectroniclockVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_ErrInfoBSW_CIL_ErrInfoBSW;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_FrqCrash_CIL_FrqCrash;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_FrqHvil_CIL_FrqHvil;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HWVerVeh_CIL_HWVerVeh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HourRtc_CIL_HourRtc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HourTelbox_CIL_HourTelbox;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHvRaw_CIL_IBatHvRaw;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_IDcdcLvAct_CIL_IDcdcLvAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IEACAct_CIL_IEACAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IObcChOutp_CIL_IObcChOutp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_MilgTot_CIL_MilgTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MinuRtc_CIL_MinuRtc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MinuTelbox_CIL_MinuTelbox;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ModeMotDrv_CIL_ModeMotDrv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ModeSysWup_CIL_ModeSysWup;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MonthRtc_CIL_MonthRtc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MonthTelbox_CIL_MonthTelbox;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_OnBdCPline_CIL_OnBdCPline;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_PowerMode_CIL_PowerMode;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_PwrEACAct_CIL_PwrEACAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_PwrPtcAct_CIL_PwrPtcAct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_RAcChCnctn_CIL_RAcChCnctn;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw;
extern VAR(SInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_RDisChCnctn_CIL_RDisChCnctn;
extern VAR(SInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RIslnNeg_CIL_RIslnNeg;
extern VAR(SInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RIslnPos_CIL_RIslnPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_RngElec_CIL_RngElec;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_SWVerVeh_CIL_SWVerVeh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_SecRtc_CIL_SecRtc;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_SecTelbox_CIL_SecTelbox;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_SpdMot_CIL_SpdMot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_SpdVeh_CIL_SpdVeh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StAcChCnct_CIL_StAcChCnct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StBatHvReq_CIL_StBatHvReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq;
extern VAR(rt_Array_UInt8_54, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellT_CIL_StCellT;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StChAllwd_CIL_StChAllwd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StChWup_CIL_StChWup;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCrash_CIL_StCrash;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StMsgToutForObc_CIL_StMsgToutForObc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StObc_CIL_StObc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StProj_CIL_StProj;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StPtIndcr_CIL_StPtIndcr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StPtcW_CIL_StPtcW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StRtcFlt_CIL_StRtcFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StTrml15_CIL_StTrml15;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TAcChPointNeg_CIL_TAcChPointNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TAcChPointPos_CIL_TAcChPointPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TBd_CIL_TBd;
extern VAR(rt_Array_Float_32, RTE_VAR_INIT) Rte_swc_CIL_CIL_TBdSnsr_CIL_TBdSnsr;
extern VAR(SInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr;
extern VAR(SInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TDcChPointNeg_CIL_TDcChPointNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TDcChPointPos_CIL_TDcChPointPos;
extern VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_CIL_CIL_TMdul_CIL_TMdul;
extern VAR(rt_Array_Float_32, RTE_VAR_INIT) Rte_swc_CIL_CIL_TMdulCtlr_CIL_TMdulCtlr;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_CIL_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE;
extern VAR(SInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_TSnsrI_CIL_TSnsrI;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_TiSysRun_CIL_TiSysRun;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UDcdcLvAct_CIL_UDcdcLvAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UEACAct_CIL_UEACAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UObcChInp_CIL_UObcChInp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UObcChOutp_CIL_UObcChOutp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UTrml30_CIL_UTrml30;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_VehicleSpeedInvalid_CIL_VehicleSpeedInvalid;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_YearRtc_CIL_YearRtc;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_YearTelbox_CIL_YearTelbox;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_ZeroPwrFb_CIL_ZeroPwrFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bAcvRstDiag_CIL_bAcvRstDiag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bCANWakeUp_CIL_bCANWakeUp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bDCDCW_CIL_bDCDCW;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bKCNegClsSts_CIL_bKCNegClsSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bMainNegClsSts_CIL_bMainNegClsSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldBatIHv_CIL_bVldBatIHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldIslnR_CIL_bVldIslnR;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_ClL_InletWaterTemp_ClL_InletWaterTemp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_ClL_OutletWaterTemp_ClL_OutletWaterTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrAFETot_MCC_NrAFETot;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCellByMdul_MCC_NrCellByMdul;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCellTot_MCC_NrCellTot;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrSnsrTTot_MCC_NrSnsrTTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_StMdulCu_MCC_StMdulCu;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_NvM_Save_Ok_NvM_Save_Ok;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_STHW_ErrFLg_STHW_ErrFLg;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Service0x14_Count_Service0x14_Count;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_StsElectroniclockContor_StsElectroniclockContor;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_WeakUpFlg_WeakUpFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_bCANWakeUp_bCANWakeUp;
extern VAR(rt_Array_UInt16_130, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BMUCell_BMUCell;
extern VAR(rt_Array_UInt32_4, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BMUCellVSt_BMUCellVSt;
extern VAR(rt_Array_SInt16_8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BMUChipTemp_BMUChipTemp;
extern VAR(rt_Array_SInt16_32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BMUTemp_BMUTemp;
extern VAR(rt_Array_UInt8_32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BMUTempSt_BMUTempSt;
extern VAR(rt_Array_SInt16_8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BalanceTemp_BalanceTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_CellTEffective_CellTEffective;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_CellTempException_CellTempException;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_CellVEffective_CellVEffective;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_CellVoltException_CellVoltException;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_IDriftZero_CTC_IDriftZero;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
extern VAR(SInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_RelayKHVoltage_RelayKHVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidBat_U8_SampleValidBat_U8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidKC_U8_SampleValidKC_U8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidKH_U8_SampleValidKH_U8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidKM_U8_SampleValidKM_U8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidKN_U8_SampleValidKN_U8;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_NowSystemTick_NowSystemTick;
extern VAR(SInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_RTCStateFault_RTCStateFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadDay_ReadDay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadHour_ReadHour;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadMinute_ReadMinute;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadMonth_ReadMonth;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadSecond_ReadSecond;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadYear_ReadYear;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BatCoolType_PMS_BatCoolType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Wakeup_reasons_PMS_Wakeup_reasons;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_VCU_ActInputVolt_VCU_ActInputVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_ChargeDepthReq_VCU_ChargeDepthReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_CrashOutputSts_VCU_CrashOutputSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ChargeModeReq_CIL_ChargeModeReq;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_BCM_DoorLockStatusDrv_BCM_LDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_BCM_DoorLockStatusPass_BCM_RDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CRO_ChargerReady_CRO_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint32, RTE_VAR_INIT) Rte_ComBuffer_CHM_ProtocolVersion_CHM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CCS_ChargeAllow_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortByUser_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortAchiveCondition_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortByFault_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortErrorVoltage_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortErrorCurrent_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultEnergeTransmit_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultConnetor_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultChargerTemp_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultChargerInnerTemp_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultOther_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultChargerStop_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CCS_ChargeTotalTime_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CCS_OutputCurrent_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_VehicleSpeed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VehicleSpeedInvalid_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_TotalCurr_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_HCM_ShuntTemp_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_NegInsulateVal_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_PosInsulateVal_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_FastChgBackVolt_HCM_OtherRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_MainPosBackVolt_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_MainNegBackVolt_HCM_OtherRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint32, RTE_VAR_INIT) Rte_ComBuffer_HCM_InsulateCounter_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_MainPosFrtVolt_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Day_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Hour_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Minute_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Month_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Second_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Year_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CML_OutputCurrentMax_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CML_OutpuVoltageMax_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CML_OutputCurrentMin_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CML_OutputVoltageMin_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_CCvalue_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_ChgCCSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_ChrgrSt_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_DischargeCCvalue_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_Elock_Stmode_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdCCline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdCPline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdDisChrgrCCline_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdOuptI_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdOuptU_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_OBC_uInAct_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CSD_OutputEnerge_CSD_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_PEPS_PowerMode_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CRM_RecognitionResult_CRM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_ChrgSoftSwCtrlSt_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_ReservationChrgnSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BatteryChargeRequireTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BatteryParameterTimout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BatteryStateTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BMSIdentifyTimout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BMSFinishChargeTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BMSChargeStatisticsTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BMSAbortChargeTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CCS_OutputVoltage_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_DischgState_IPU_DischgState;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_App1_Task_50ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_50ms_Core2_QM;
extern VAR(Rte_ts_App1_Task_100ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_100ms_Core2_QM;
extern VAR(Rte_ts_App1_Task_10ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_10ms_Core2_QM;
extern VAR(Rte_ts_SWC_Init_Task_Core2, RTE_VAR_NOINIT) Rte_SWC_Init_Task_Core2;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
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
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_CIL_HvSysSample_SampleCountInsRes_U16_SampleCountInsRes_U16(P2VAR(UInt16, AUTOMATIC, RTE_swc_CIL_APPL_DATA) data);
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
#define Rte_IRead_CIL_50ms_BCM_DoorLockStatusDrv_BCM_DoorLockStatusDrv() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BCM_DoorLockStatusDrv_BCM_DoorLockStatusDrv.value)

#define Rte_IRead_CIL_50ms_BCM_DoorLockStatusPass_BCM_DoorLockStatusPass() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BCM_DoorLockStatusPass_BCM_DoorLockStatusPass.value)

#define Rte_IWrite_CIL_100ms_BMC_UCell_BMC_UCell(data) \
  RteIWrite_CIL_100ms_BMC_UCell_BMC_UCell(data)

#define RteIWrite_CIL_100ms_BMC_UCell_BMC_UCell(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BMC_UCell_BMC_UCell.value, data, sizeof(rt_Array_Float_255)) \
)

#define Rte_IWriteRef_CIL_100ms_BMC_UCell_BMC_UCell() \
  (&((*RteIWriteRef_CIL_100ms_BMC_UCell_BMC_UCell())[0]))

#define RteIWriteRef_CIL_100ms_BMC_UCell_BMC_UCell() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BMC_UCell_BMC_UCell.value \
)

#define Rte_IWrite_CIL_10ms_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd.value \
)

#define Rte_IWrite_CIL_10ms_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms.value \
)

#define Rte_IWrite_CIL_10ms_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd.value \
)

#define Rte_IWrite_CIL_10ms_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt.value \
)

#define Rte_IWrite_CIL_50ms_BSOF_ChAllwd_BSOF_ChAllwd(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_ChAllwd_BSOF_ChAllwd.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_BSOF_ChAllwd_BSOF_ChAllwd() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_ChAllwd_BSOF_ChAllwd.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_DirChAndDcha_BSOF_DirChAndDcha(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_DirChAndDcha_BSOF_DirChAndDcha.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_DirChAndDcha_BSOF_DirChAndDcha() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_DirChAndDcha_BSOF_DirChAndDcha.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_EChSng_BSOF_EChSng(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_EChSng_BSOF_EChSng.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_EChSng_BSOF_EChSng() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_EChSng_BSOF_EChSng.value \
)

#define Rte_IWrite_CIL_10ms_BSOF_ErrChImpo_BSOF_ErrChImpo(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrChImpo_BSOF_ErrChImpo.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_BSOF_ErrChImpo_BSOF_ErrChImpo() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrChImpo_BSOF_ErrChImpo.value \
)

#define Rte_IWrite_CIL_10ms_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt.value \
)

#define Rte_IWrite_CIL_10ms_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt.value \
)

#define Rte_IWrite_CIL_10ms_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt.value \
)

#define Rte_IWrite_CIL_10ms_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy.value \
)

#define Rte_IWrite_CIL_10ms_BSOF_ErrIDe_BSOF_ErrIDe(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrIDe_BSOF_ErrIDe.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_BSOF_ErrIDe_BSOF_ErrIDe() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrIDe_BSOF_ErrIDe.value \
)

#define Rte_IWrite_CIL_10ms_BSOF_ErrUAbno_BSOF_ErrUAbno(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrUAbno_BSOF_ErrUAbno.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_BSOF_ErrUAbno_BSOF_ErrUAbno() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrUAbno_BSOF_ErrUAbno.value \
)

#define Rte_IWrite_CIL_10ms_BSOF_ErrUndfnd_BSOF_ErrUndfnd(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrUndfnd_BSOF_ErrUndfnd.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_BSOF_ErrUndfnd_BSOF_ErrUndfnd() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_ErrUndfnd_BSOF_ErrUndfnd.value \
)

#define Rte_IWrite_CIL_50ms_BSOF_IChrgr_BSOF_IChrgr(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_IChrgr_BSOF_IChrgr.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_BSOF_IChrgr_BSOF_IChrgr() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_IChrgr_BSOF_IChrgr.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_IChrgrMax_BSOF_IChrgrMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_IChrgrMax_BSOF_IChrgrMax.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_IChrgrMax_BSOF_IChrgrMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_IChrgrMax_BSOF_IChrgrMax.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_IChrgrMin_BSOF_IChrgrMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_IChrgrMin_BSOF_IChrgrMin.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_IChrgrMin_BSOF_IChrgrMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_IChrgrMin_BSOF_IChrgrMin.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_IDchaMax_BSOF_IDchaMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_IDchaMax_BSOF_IDchaMax.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_IDchaMax_BSOF_IDchaMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_IDchaMax_BSOF_IDchaMax.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_IDchaMin_BSOF_IDchaMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_IDchaMin_BSOF_IDchaMin.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_IDchaMin_BSOF_IDchaMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_IDchaMin_BSOF_IDchaMin.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_NrChrgrComVers_BSOF_NrChrgrComVers(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_NrChrgrComVers_BSOF_NrChrgrComVers.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_NrChrgrComVers_BSOF_NrChrgrComVers() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_NrChrgrComVers_BSOF_NrChrgrComVers.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_SocDchaMax_BSOF_SocDchaMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_SocDchaMax_BSOF_SocDchaMax.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_SocDchaMax_BSOF_SocDchaMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_SocDchaMax_BSOF_SocDchaMax.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_SocDchaMin_BSOF_SocDchaMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_SocDchaMin_BSOF_SocDchaMin.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_SocDchaMin_BSOF_SocDchaMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_SocDchaMin_BSOF_SocDchaMin.value \
)

#define Rte_IWrite_CIL_50ms_BSOF_TiChAccumd_BSOF_TiChAccumd(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_TiChAccumd_BSOF_TiChAccumd.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_BSOF_TiChAccumd_BSOF_TiChAccumd() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_TiChAccumd_BSOF_TiChAccumd.value \
)

#define Rte_IWrite_CIL_50ms_BSOF_UChrgr_BSOF_UChrgr(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_UChrgr_BSOF_UChrgr.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_BSOF_UChrgr_BSOF_UChrgr() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_UChrgr_BSOF_UChrgr.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_UChrgrMax_BSOF_UChrgrMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_UChrgrMax_BSOF_UChrgrMax.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_UChrgrMax_BSOF_UChrgrMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_UChrgrMax_BSOF_UChrgrMax.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_UChrgrMin_BSOF_UChrgrMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_UChrgrMin_BSOF_UChrgrMin.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_UChrgrMin_BSOF_UChrgrMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_UChrgrMin_BSOF_UChrgrMin.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_UDchaMax_BSOF_UDchaMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_UDchaMax_BSOF_UDchaMax.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_UDchaMax_BSOF_UDchaMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_UDchaMax_BSOF_UDchaMax.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_UDchaMin_BSOF_UDchaMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_UDchaMin_BSOF_UDchaMin.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_UDchaMin_BSOF_UDchaMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_UDchaMin_BSOF_UDchaMin.value \
)

#define Rte_IWrite_CIL_50ms_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr.value \
)

#define Rte_IWrite_CIL_50ms_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_bEnaMsgChrgrChDetd_BSOF_bEnaMsgChrgrChDetd(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrChDetd_BSOF_bEnaMsgChrgrChDetd.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_bEnaMsgChrgrChDetd_BSOF_bEnaMsgChrgrChDetd() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrChDetd_BSOF_bEnaMsgChrgrChDetd.value \
)

#define Rte_IWrite_CIL_50ms_BSOF_bEnaMsgChrgrChSt_BSOF_bEnaMsgChrgrChSt(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_bEnaMsgChrgrChSt_BSOF_bEnaMsgChrgrChSt.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_BSOF_bEnaMsgChrgrChSt_BSOF_bEnaMsgChrgrChSt() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSOF_bEnaMsgChrgrChSt_BSOF_bEnaMsgChrgrChSt.value \
)

#define Rte_IWrite_CIL_10ms_BSOF_bEnaMsgChrgrChSuspd_BSOF_bEnaMsgChrgrChSuspd(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_bEnaMsgChrgrChSuspd_BSOF_bEnaMsgChrgrChSuspd.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_BSOF_bEnaMsgChrgrChSuspd_BSOF_bEnaMsgChrgrChSuspd() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSOF_bEnaMsgChrgrChSuspd_BSOF_bEnaMsgChrgrChSuspd.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_bEnaMsgChrgrDetnCnct_BSOF_bEnaMsgChrgrDetnCnct(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrDetnCnct_BSOF_bEnaMsgChrgrDetnCnct.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_bEnaMsgChrgrDetnCnct_BSOF_bEnaMsgChrgrDetnCnct() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrDetnCnct_BSOF_bEnaMsgChrgrDetnCnct.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_bEnaMsgChrgrErr_BSOF_bEnaMsgChrgrErr(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrErr_BSOF_bEnaMsgChrgrErr.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_bEnaMsgChrgrErr_BSOF_bEnaMsgChrgrErr() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrErr_BSOF_bEnaMsgChrgrErr.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_bEnaMsgChrgrHdshk_BSOF_bEnaMsgChrgrHdshk(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrHdshk_BSOF_bEnaMsgChrgrHdshk.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_bEnaMsgChrgrHdshk_BSOF_bEnaMsgChrgrHdshk() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrHdshk_BSOF_bEnaMsgChrgrHdshk.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_bEnaMsgChrgrMaxOut_BSOF_bEnaMsgChrgrMaxOut(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrMaxOut_BSOF_bEnaMsgChrgrMaxOut.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_bEnaMsgChrgrMaxOut_BSOF_bEnaMsgChrgrMaxOut() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrMaxOut_BSOF_bEnaMsgChrgrMaxOut.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_bEnaMsgChrgrMaxOutPgtn_BSOF_bEnaMsgChrgrMaxOutPgtn(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrMaxOutPgtn_BSOF_bEnaMsgChrgrMaxOutPgtn.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_bEnaMsgChrgrMaxOutPgtn_BSOF_bEnaMsgChrgrMaxOutPgtn() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrMaxOutPgtn_BSOF_bEnaMsgChrgrMaxOutPgtn.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_bEnaMsgChrgrRcgtn_BSOF_bEnaMsgChrgrRcgtn(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrRcgtn_BSOF_bEnaMsgChrgrRcgtn.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_bEnaMsgChrgrRcgtn_BSOF_bEnaMsgChrgrRcgtn() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrRcgtn_BSOF_bEnaMsgChrgrRcgtn.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_bEnaMsgChrgrRdy_BSOF_bEnaMsgChrgrRdy(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrRdy_BSOF_bEnaMsgChrgrRdy.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_bEnaMsgChrgrRdy_BSOF_bEnaMsgChrgrRdy() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrRdy_BSOF_bEnaMsgChrgrRdy.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_bEnaMsgChrgrStstc_BSOF_bEnaMsgChrgrStstc(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrStstc_BSOF_bEnaMsgChrgrStstc.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_bEnaMsgChrgrStstc_BSOF_bEnaMsgChrgrStstc() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrStstc_BSOF_bEnaMsgChrgrStstc.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_bEnaMsgChrgrStstcForPgtn_BSOF_bEnaMsgChrgrStstcForPgtn(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrStstcForPgtn_BSOF_bEnaMsgChrgrStstcForPgtn.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_bEnaMsgChrgrStstcForPgtn_BSOF_bEnaMsgChrgrStstcForPgtn() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bEnaMsgChrgrStstcForPgtn_BSOF_bEnaMsgChrgrStstcForPgtn.value \
)

#define Rte_IWrite_CIL_100ms_BSOF_bErrMsgTout_BSOF_bErrMsgTout(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bErrMsgTout_BSOF_bErrMsgTout.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_BSOF_bErrMsgTout_BSOF_bErrMsgTout() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSOF_bErrMsgTout_BSOF_bErrMsgTout.value \
)

#define Rte_IRead_CIL_50ms_BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_ACUCom_ErrFLg_ACUCom_ErrFLg() \
  (0U)

#define Rte_IRead_CIL_50ms_BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg.value)

#define Rte_IRead_CIL_100ms_BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime.value)

#define Rte_IRead_CIL_100ms_BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime.value)

#define Rte_IRead_CIL_100ms_BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime.value)

#define Rte_IRead_CIL_100ms_BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime.value)

#define Rte_IRead_CIL_100ms_BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime.value)

#define Rte_IRead_CIL_100ms_BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime.value)

#define Rte_IRead_CIL_100ms_BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime.value)

#define Rte_IRead_CIL_100ms_BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime.value)

#define Rte_IRead_CIL_100ms_BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime.value)

#define Rte_IRead_CIL_100ms_BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime.value)

#define Rte_IRead_CIL_10ms_BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_Com_PMS_BMSH_Ctrl_Timeout_PMS_BMSH_Ctrl_Timeout() \
  (0U)

#define Rte_IRead_CIL_50ms_BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_HCME2E_ErrFLg_HCME2E_ErrFLg() \
  (FALSE)

#define Rte_IRead_CIL_50ms_BSWIOSP_HCMbusoff_ErrFLg_HCMbusoff_ErrFLg() \
  (FALSE)

#define Rte_IRead_CIL_50ms_BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_NvM_Save_Ok_NvM_Save_Ok() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_NvM_Save_Ok_NvM_Save_Ok.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_STHW_ErrFLg_STHW_ErrFLg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_STHW_ErrFLg_STHW_ErrFLg.value)

#define Rte_IRead_CIL_10ms_BSWIOSP_Service0x14_Count_Service0x14_Count() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSWIOSP_Service0x14_Count_Service0x14_Count.value)

#define Rte_IRead_CIL_10ms_BSWIOSP_StsElectroniclockContor_StsElectroniclockContor() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_BSWIOSP_StsElectroniclockContor_StsElectroniclockContor.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_WeakUpFlg_WeakUpFlg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_WeakUpFlg_WeakUpFlg.value)

#define Rte_IRead_CIL_50ms_BSWIOSP_bCANWakeUp_bCANWakeUp() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BSWIOSP_bCANWakeUp_bCANWakeUp.value)

#define Rte_IRead_CIL_100ms_BmuSample_BMUCell_BMUCell() \
  (&((*RteIRead_CIL_100ms_BmuSample_BMUCell_BMUCell())[0]))

#define RteIRead_CIL_100ms_BmuSample_BMUCell_BMUCell() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BmuSample_BMUCell_BMUCell.value)

#define Rte_IRead_CIL_50ms_BmuSample_BMUCellVSt_BMUCellVSt() \
  (&((*RteIRead_CIL_50ms_BmuSample_BMUCellVSt_BMUCellVSt())[0]))

#define RteIRead_CIL_50ms_BmuSample_BMUCellVSt_BMUCellVSt() \
  (&Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BmuSample_BMUCellVSt_BMUCellVSt.value)

#define Rte_IRead_CIL_100ms_BmuSample_BMUChipTemp_BMUChipTemp() \
  (&((*RteIRead_CIL_100ms_BmuSample_BMUChipTemp_BMUChipTemp())[0]))

#define RteIRead_CIL_100ms_BmuSample_BMUChipTemp_BMUChipTemp() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BmuSample_BMUChipTemp_BMUChipTemp.value)

#define Rte_IRead_CIL_100ms_BmuSample_BMUTemp_BMUTemp() \
  (&((*RteIRead_CIL_100ms_BmuSample_BMUTemp_BMUTemp())[0]))

#define RteIRead_CIL_100ms_BmuSample_BMUTemp_BMUTemp() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BmuSample_BMUTemp_BMUTemp.value)

#define Rte_IRead_CIL_100ms_BmuSample_BMUTempSt_BMUTempSt() \
  (&((*RteIRead_CIL_100ms_BmuSample_BMUTempSt_BMUTempSt())[0]))

#define RteIRead_CIL_100ms_BmuSample_BMUTempSt_BMUTempSt() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BmuSample_BMUTempSt_BMUTempSt.value)

#define Rte_IRead_CIL_100ms_BmuSample_BalanceTemp_BalanceTemp() \
  (&((*RteIRead_CIL_100ms_BmuSample_BalanceTemp_BalanceTemp())[0]))

#define RteIRead_CIL_100ms_BmuSample_BalanceTemp_BalanceTemp() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_BmuSample_BalanceTemp_BalanceTemp.value)

#define Rte_IRead_CIL_50ms_BmuSample_CellTEffective_CellTEffective() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BmuSample_CellTEffective_CellTEffective.value)

#define Rte_IRead_CIL_50ms_BmuSample_CellTempException_CellTempException() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BmuSample_CellTempException_CellTempException.value)

#define Rte_IRead_CIL_50ms_BmuSample_CellVEffective_CellVEffective() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BmuSample_CellVEffective_CellVEffective.value)

#define Rte_IRead_CIL_50ms_BmuSample_CellVoltException_CellVoltException() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_BmuSample_CellVoltException_CellVoltException.value)

#define Rte_IRead_CIL_100ms_CCD_Chg_Direction_CCD_Chg_Direction() \
  (0U)

#define Rte_IRead_CIL_100ms_CCD_Max_Allow_Soc_CCD_Max_Allow_Soc() \
  (0U)

#define Rte_IRead_CIL_100ms_CCD_Min_Allow_Soc_CCD_Min_Allow_Soc() \
  (0U)

#define Rte_IWrite_CIL_50ms_CIL_ActInputVolt_CIL_ActInputVolt(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ActInputVolt_CIL_ActInputVolt.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_ActInputVolt_CIL_ActInputVolt() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ActInputVolt_CIL_ActInputVolt.value \
)

#define Rte_IWrite_CIL_50ms_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax.value \
)

#define Rte_IWrite_CIL_50ms_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq.value \
)

#define Rte_IWrite_CIL_100ms_CIL_BMSH_StsModeReq_CIL_BMSH_StsModeReq(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_BMSH_StsModeReq_CIL_BMSH_StsModeReq.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_BMSH_StsModeReq_CIL_BMSH_StsModeReq() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_BMSH_StsModeReq_CIL_BMSH_StsModeReq.value \
)

#define Rte_IWrite_CIL_100ms_CIL_BatCoolType_CIL_BatCoolType(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_BatCoolType_CIL_BatCoolType.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_BatCoolType_CIL_BatCoolType() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_BatCoolType_CIL_BatCoolType.value \
)

#define Rte_IWrite_CIL_50ms_CIL_CP_Vol_CIL_CP_Vol(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_CP_Vol_CIL_CP_Vol.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_CP_Vol_CIL_CP_Vol() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_CP_Vol_CIL_CP_Vol.value \
)

#define Rte_IWrite_CIL_100ms_CIL_CfgLvl2_CIL_CfgLvl2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_CfgLvl2_CIL_CfgLvl2.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_CfgLvl2_CIL_CfgLvl2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_CfgLvl2_CIL_CfgLvl2.value \
)

#define Rte_IWrite_CIL_Init_CIL_CfgLvl2_CIL_CfgLvl2(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_CfgLvl2_CIL_CfgLvl2.value = (data) \
)

#define Rte_IWriteRef_CIL_Init_CIL_CfgLvl2_CIL_CfgLvl2() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_CfgLvl2_CIL_CfgLvl2.value \
)

#define Rte_IWrite_CIL_50ms_CIL_ChargeDepthReq_CIL_ChargeDepthReq(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ChargeDepthReq_CIL_ChargeDepthReq.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_ChargeDepthReq_CIL_ChargeDepthReq() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ChargeDepthReq_CIL_ChargeDepthReq.value \
)

#define Rte_IWrite_CIL_100ms_CIL_ChargeModeReq_CIL_ChargeModeReq(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ChargeModeReq_CIL_ChargeModeReq.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_ChargeModeReq_CIL_ChargeModeReq() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ChargeModeReq_CIL_ChargeModeReq.value \
)

#define Rte_IWrite_CIL_100ms_CIL_ChgCCSts_CIL_ChgCCSts(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ChgCCSts_CIL_ChgCCSts.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_ChgCCSts_CIL_ChgCCSts() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ChgCCSts_CIL_ChgCCSts.value \
)

#define Rte_IWrite_CIL_100ms_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt.value \
)

#define Rte_IWrite_CIL_50ms_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg.value \
)

#define Rte_IWrite_CIL_50ms_CIL_DayRtc_CIL_DayRtc(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DayRtc_CIL_DayRtc.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_DayRtc_CIL_DayRtc() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DayRtc_CIL_DayRtc.value \
)

#define Rte_IWrite_CIL_100ms_CIL_DayTelbox_CIL_DayTelbox(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_DayTelbox_CIL_DayTelbox.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_DayTelbox_CIL_DayTelbox() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_DayTelbox_CIL_DayTelbox.value \
)

#define Rte_IWrite_CIL_50ms_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv.value \
)

#define Rte_IWrite_CIL_50ms_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass.value \
)

#define Rte_IWrite_CIL_50ms_CIL_DucycCrash_CIL_DucycCrash(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DucycCrash_CIL_DucycCrash.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_DucycCrash_CIL_DucycCrash() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DucycCrash_CIL_DucycCrash.value \
)

#define Rte_IWrite_CIL_50ms_CIL_DucycCtlPilot_CIL_DucycCtlPilot(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DucycCtlPilot_CIL_DucycCtlPilot.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_DucycCtlPilot_CIL_DucycCtlPilot() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DucycCtlPilot_CIL_DucycCtlPilot.value \
)

#define Rte_IWrite_CIL_50ms_CIL_DucycHvil_CIL_DucycHvil(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DucycHvil_CIL_DucycHvil.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_DucycHvil_CIL_DucycHvil() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_DucycHvil_CIL_DucycHvil.value \
)

#define Rte_IWrite_CIL_50ms_CIL_ElectroniclockVolt_CIL_ElectroniclockVolt(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ElectroniclockVolt_CIL_ElectroniclockVolt.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_ElectroniclockVolt_CIL_ElectroniclockVolt() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ElectroniclockVolt_CIL_ElectroniclockVolt.value \
)

#define Rte_IWrite_CIL_100ms_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC.value \
)

#define Rte_IWrite_CIL_50ms_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT.value \
)

#define Rte_IWrite_CIL_50ms_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT.value \
)

#define Rte_IWrite_CIL_50ms_CIL_ErrInfoBSW_CIL_ErrInfoBSW(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ErrInfoBSW_CIL_ErrInfoBSW.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_ErrInfoBSW_CIL_ErrInfoBSW() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ErrInfoBSW_CIL_ErrInfoBSW.value \
)

#define Rte_IWrite_CIL_50ms_CIL_FrqCrash_CIL_FrqCrash(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_FrqCrash_CIL_FrqCrash.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_FrqCrash_CIL_FrqCrash() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_FrqCrash_CIL_FrqCrash.value \
)

#define Rte_IWrite_CIL_50ms_CIL_FrqHvil_CIL_FrqHvil(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_FrqHvil_CIL_FrqHvil.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_FrqHvil_CIL_FrqHvil() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_FrqHvil_CIL_FrqHvil.value \
)

#define Rte_IWrite_CIL_100ms_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl.value \
)

#define Rte_IWrite_CIL_Init_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl.value = (data) \
)

#define Rte_IWriteRef_CIL_Init_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl.value \
)

#define Rte_IWrite_CIL_100ms_CIL_HWVerVeh_CIL_HWVerVeh(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_HWVerVeh_CIL_HWVerVeh.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_HWVerVeh_CIL_HWVerVeh() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_HWVerVeh_CIL_HWVerVeh.value \
)

#define Rte_IWrite_CIL_Init_CIL_HWVerVeh_CIL_HWVerVeh(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_HWVerVeh_CIL_HWVerVeh.value = (data) \
)

#define Rte_IWriteRef_CIL_Init_CIL_HWVerVeh_CIL_HWVerVeh() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_HWVerVeh_CIL_HWVerVeh.value \
)

#define Rte_IWrite_CIL_50ms_CIL_HourRtc_CIL_HourRtc(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_HourRtc_CIL_HourRtc.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_HourRtc_CIL_HourRtc() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_HourRtc_CIL_HourRtc.value \
)

#define Rte_IWrite_CIL_100ms_CIL_HourTelbox_CIL_HourTelbox(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_HourTelbox_CIL_HourTelbox.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_HourTelbox_CIL_HourTelbox() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_HourTelbox_CIL_HourTelbox.value \
)

#define Rte_IWrite_CIL_10ms_CIL_IBatHv_CIL_IBatHv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_IBatHv_CIL_IBatHv.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_CIL_IBatHv_CIL_IBatHv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_IBatHv_CIL_IBatHv.value \
)

#define Rte_IWrite_CIL_10ms_CIL_IBatHvRaw_CIL_IBatHvRaw(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_IBatHvRaw_CIL_IBatHvRaw.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_CIL_IBatHvRaw_CIL_IBatHvRaw() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_IBatHvRaw_CIL_IBatHvRaw.value \
)

#define Rte_IWrite_CIL_50ms_CIL_IDcdcLvAct_CIL_IDcdcLvAct(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_IDcdcLvAct_CIL_IDcdcLvAct.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_IDcdcLvAct_CIL_IDcdcLvAct() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_IDcdcLvAct_CIL_IDcdcLvAct.value \
)

#define Rte_IWrite_CIL_100ms_CIL_IEACAct_CIL_IEACAct(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_IEACAct_CIL_IEACAct.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_IEACAct_CIL_IEACAct() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_IEACAct_CIL_IEACAct.value \
)

#define Rte_IWrite_CIL_100ms_CIL_IObcChOutp_CIL_IObcChOutp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_IObcChOutp_CIL_IObcChOutp.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_IObcChOutp_CIL_IObcChOutp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_IObcChOutp_CIL_IObcChOutp.value \
)

#define Rte_IWrite_CIL_100ms_CIL_MilgTot_CIL_MilgTot(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_MilgTot_CIL_MilgTot.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_MilgTot_CIL_MilgTot() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_MilgTot_CIL_MilgTot.value \
)

#define Rte_IWrite_CIL_50ms_CIL_MinuRtc_CIL_MinuRtc(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_MinuRtc_CIL_MinuRtc.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_MinuRtc_CIL_MinuRtc() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_MinuRtc_CIL_MinuRtc.value \
)

#define Rte_IWrite_CIL_100ms_CIL_MinuTelbox_CIL_MinuTelbox(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_MinuTelbox_CIL_MinuTelbox.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_MinuTelbox_CIL_MinuTelbox() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_MinuTelbox_CIL_MinuTelbox.value \
)

#define Rte_IWrite_CIL_10ms_CIL_ModeMotDrv_CIL_ModeMotDrv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_ModeMotDrv_CIL_ModeMotDrv.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_CIL_ModeMotDrv_CIL_ModeMotDrv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_ModeMotDrv_CIL_ModeMotDrv.value \
)

#define Rte_IWrite_CIL_50ms_CIL_ModeSysWup_CIL_ModeSysWup(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ModeSysWup_CIL_ModeSysWup.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_ModeSysWup_CIL_ModeSysWup() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_ModeSysWup_CIL_ModeSysWup.value \
)

#define Rte_IWrite_CIL_50ms_CIL_MonthRtc_CIL_MonthRtc(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_MonthRtc_CIL_MonthRtc.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_MonthRtc_CIL_MonthRtc() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_MonthRtc_CIL_MonthRtc.value \
)

#define Rte_IWrite_CIL_100ms_CIL_MonthTelbox_CIL_MonthTelbox(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_MonthTelbox_CIL_MonthTelbox.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_MonthTelbox_CIL_MonthTelbox() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_MonthTelbox_CIL_MonthTelbox.value \
)

#define Rte_IWrite_CIL_100ms_CIL_OnBdCPline_CIL_OnBdCPline(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_OnBdCPline_CIL_OnBdCPline.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_OnBdCPline_CIL_OnBdCPline() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_OnBdCPline_CIL_OnBdCPline.value \
)

#define Rte_IWrite_CIL_100ms_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline.value \
)

#define Rte_IWrite_CIL_100ms_CIL_PowerMode_CIL_PowerMode(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_PowerMode_CIL_PowerMode.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_PowerMode_CIL_PowerMode() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_PowerMode_CIL_PowerMode.value \
)

#define Rte_IWrite_CIL_100ms_CIL_PwrEACAct_CIL_PwrEACAct(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_PwrEACAct_CIL_PwrEACAct.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_PwrEACAct_CIL_PwrEACAct() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_PwrEACAct_CIL_PwrEACAct.value \
)

#define Rte_IWrite_CIL_100ms_CIL_PwrPtcAct_CIL_PwrPtcAct(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_PwrPtcAct_CIL_PwrPtcAct.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_PwrPtcAct_CIL_PwrPtcAct() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_PwrPtcAct_CIL_PwrPtcAct.value \
)

#define Rte_IWrite_CIL_100ms_CIL_RAcChCnctn_CIL_RAcChCnctn(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_RAcChCnctn_CIL_RAcChCnctn.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_RAcChCnctn_CIL_RAcChCnctn() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_RAcChCnctn_CIL_RAcChCnctn.value \
)

#define Rte_IWrite_CIL_50ms_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw.value \
)

#define Rte_IWrite_CIL_50ms_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg.value \
)

#define Rte_IWrite_CIL_100ms_CIL_RDisChCnctn_CIL_RDisChCnctn(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_RDisChCnctn_CIL_RDisChCnctn.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_RDisChCnctn_CIL_RDisChCnctn() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_RDisChCnctn_CIL_RDisChCnctn.value \
)

#define Rte_IWrite_CIL_50ms_CIL_RIslnNeg_CIL_RIslnNeg(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_RIslnNeg_CIL_RIslnNeg.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_RIslnNeg_CIL_RIslnNeg() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_RIslnNeg_CIL_RIslnNeg.value \
)

#define Rte_IWrite_CIL_50ms_CIL_RIslnPos_CIL_RIslnPos(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_RIslnPos_CIL_RIslnPos.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_RIslnPos_CIL_RIslnPos() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_RIslnPos_CIL_RIslnPos.value \
)

#define Rte_IWrite_CIL_100ms_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts.value \
)

#define Rte_IWrite_CIL_50ms_CIL_RngElec_CIL_RngElec(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_RngElec_CIL_RngElec.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_RngElec_CIL_RngElec() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_RngElec_CIL_RngElec.value \
)

#define Rte_IWrite_CIL_100ms_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl.value \
)

#define Rte_IWrite_CIL_Init_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl.value = (data) \
)

#define Rte_IWriteRef_CIL_Init_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl.value \
)

#define Rte_IWrite_CIL_100ms_CIL_SWVerVeh_CIL_SWVerVeh(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_SWVerVeh_CIL_SWVerVeh.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_SWVerVeh_CIL_SWVerVeh() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_SWVerVeh_CIL_SWVerVeh.value \
)

#define Rte_IWrite_CIL_Init_CIL_SWVerVeh_CIL_SWVerVeh(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_SWVerVeh_CIL_SWVerVeh.value = (data) \
)

#define Rte_IWriteRef_CIL_Init_CIL_SWVerVeh_CIL_SWVerVeh() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_SWVerVeh_CIL_SWVerVeh.value \
)

#define Rte_IWrite_CIL_50ms_CIL_SecRtc_CIL_SecRtc(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_SecRtc_CIL_SecRtc.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_SecRtc_CIL_SecRtc() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_SecRtc_CIL_SecRtc.value \
)

#define Rte_IWrite_CIL_100ms_CIL_SecTelbox_CIL_SecTelbox(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_SecTelbox_CIL_SecTelbox.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_SecTelbox_CIL_SecTelbox() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_SecTelbox_CIL_SecTelbox.value \
)

#define Rte_IWrite_CIL_50ms_CIL_SpdMot_CIL_SpdMot(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_SpdMot_CIL_SpdMot.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_SpdMot_CIL_SpdMot() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_SpdMot_CIL_SpdMot.value \
)

#define Rte_IWrite_CIL_50ms_CIL_SpdVeh_CIL_SpdVeh(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_SpdVeh_CIL_SpdVeh.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_SpdVeh_CIL_SpdVeh() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_SpdVeh_CIL_SpdVeh.value \
)

#define Rte_IWrite_CIL_100ms_CIL_StAcChCnct_CIL_StAcChCnct(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StAcChCnct_CIL_StAcChCnct.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_StAcChCnct_CIL_StAcChCnct() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StAcChCnct_CIL_StAcChCnct.value \
)

#define Rte_IWrite_CIL_100ms_CIL_StBatHvReq_CIL_StBatHvReq(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StBatHvReq_CIL_StBatHvReq.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_StBatHvReq_CIL_StBatHvReq() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StBatHvReq_CIL_StBatHvReq.value \
)

#define Rte_IWrite_CIL_100ms_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq.value \
)

#define Rte_IWrite_CIL_100ms_CIL_StCellT_CIL_StCellT(data) \
  RteIWrite_CIL_100ms_CIL_StCellT_CIL_StCellT(data)

#define RteIWrite_CIL_100ms_CIL_StCellT_CIL_StCellT(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StCellT_CIL_StCellT.value, data, sizeof(rt_Array_UInt8_54)) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_StCellT_CIL_StCellT() \
  (&((*RteIWriteRef_CIL_100ms_CIL_StCellT_CIL_StCellT())[0]))

#define RteIWriteRef_CIL_100ms_CIL_StCellT_CIL_StCellT() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StCellT_CIL_StCellT.value \
)

#define Rte_IWrite_CIL_50ms_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn.value \
)

#define Rte_IWrite_CIL_50ms_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul(data) \
  RteIWrite_CIL_50ms_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul(data)

#define RteIWrite_CIL_50ms_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul(data) \
( \
  Rte_MemCpy(Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul.value, data, sizeof(rt_Array_UInt8_24)) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul() \
  (&((*RteIWriteRef_CIL_50ms_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul())[0]))

#define RteIWriteRef_CIL_50ms_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul.value \
)

#define Rte_IWrite_CIL_50ms_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn.value \
)

#define Rte_IWrite_CIL_100ms_CIL_StChAllwd_CIL_StChAllwd(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StChAllwd_CIL_StChAllwd.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_StChAllwd_CIL_StChAllwd() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StChAllwd_CIL_StChAllwd.value \
)

#define Rte_IWrite_CIL_50ms_CIL_StChWup_CIL_StChWup(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StChWup_CIL_StChWup.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_StChWup_CIL_StChWup() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StChWup_CIL_StChWup.value \
)

#define Rte_IWrite_CIL_10ms_CIL_StCrash_CIL_StCrash(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_StCrash_CIL_StCrash.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_CIL_StCrash_CIL_StCrash() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_StCrash_CIL_StCrash.value \
)

#define Rte_IWrite_CIL_50ms_CIL_StMsgToutForObc_CIL_StMsgToutForObc(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StMsgToutForObc_CIL_StMsgToutForObc.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_StMsgToutForObc_CIL_StMsgToutForObc() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StMsgToutForObc_CIL_StMsgToutForObc.value \
)

#define Rte_IWrite_CIL_50ms_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS.value \
)

#define Rte_IWrite_CIL_100ms_CIL_StObc_CIL_StObc(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StObc_CIL_StObc.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_StObc_CIL_StObc() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StObc_CIL_StObc.value \
)

#define Rte_IWrite_CIL_100ms_CIL_StProj_CIL_StProj(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StProj_CIL_StProj.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_StProj_CIL_StProj() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StProj_CIL_StProj.value \
)

#define Rte_IWrite_CIL_Init_CIL_StProj_CIL_StProj(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_StProj_CIL_StProj.value = (data) \
)

#define Rte_IWriteRef_CIL_Init_CIL_StProj_CIL_StProj() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_StProj_CIL_StProj.value \
)

#define Rte_IWrite_CIL_100ms_CIL_StPtIndcr_CIL_StPtIndcr(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StPtIndcr_CIL_StPtIndcr.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_StPtIndcr_CIL_StPtIndcr() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StPtIndcr_CIL_StPtIndcr.value \
)

#define Rte_IWrite_CIL_100ms_CIL_StPtcW_CIL_StPtcW(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StPtcW_CIL_StPtcW.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_StPtcW_CIL_StPtcW() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_StPtcW_CIL_StPtcW.value \
)

#define Rte_IWrite_CIL_50ms_CIL_StRtcFlt_CIL_StRtcFlt(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StRtcFlt_CIL_StRtcFlt.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_StRtcFlt_CIL_StRtcFlt() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StRtcFlt_CIL_StRtcFlt.value \
)

#define Rte_IWrite_CIL_50ms_CIL_StTrml15_CIL_StTrml15(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StTrml15_CIL_StTrml15.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_StTrml15_CIL_StTrml15() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_StTrml15_CIL_StTrml15.value \
)

#define Rte_IWrite_CIL_10ms_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor.value \
)

#define Rte_IWrite_CIL_50ms_CIL_TAcChPointNeg_CIL_TAcChPointNeg(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TAcChPointNeg_CIL_TAcChPointNeg.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_TAcChPointNeg_CIL_TAcChPointNeg() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TAcChPointNeg_CIL_TAcChPointNeg.value \
)

#define Rte_IWrite_CIL_50ms_CIL_TAcChPointPos_CIL_TAcChPointPos(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TAcChPointPos_CIL_TAcChPointPos.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_TAcChPointPos_CIL_TAcChPointPos() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TAcChPointPos_CIL_TAcChPointPos.value \
)

#define Rte_IWrite_CIL_50ms_CIL_TBd_CIL_TBd(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TBd_CIL_TBd.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_TBd_CIL_TBd() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TBd_CIL_TBd.value \
)

#define Rte_IWrite_CIL_100ms_CIL_TBdSnsr_CIL_TBdSnsr(data) \
  RteIWrite_CIL_100ms_CIL_TBdSnsr_CIL_TBdSnsr(data)

#define RteIWrite_CIL_100ms_CIL_TBdSnsr_CIL_TBdSnsr(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TBdSnsr_CIL_TBdSnsr.value, data, sizeof(rt_Array_Float_32)) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_TBdSnsr_CIL_TBdSnsr() \
  (&((*RteIWriteRef_CIL_100ms_CIL_TBdSnsr_CIL_TBdSnsr())[0]))

#define RteIWriteRef_CIL_100ms_CIL_TBdSnsr_CIL_TBdSnsr() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TBdSnsr_CIL_TBdSnsr.value \
)

#define Rte_IWrite_CIL_100ms_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr.value \
)

#define Rte_IWrite_CIL_100ms_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr.value \
)

#define Rte_IWrite_CIL_50ms_CIL_TDcChPointNeg_CIL_TDcChPointNeg(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_TDcChPointNeg_CIL_TDcChPointNeg() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg.value \
)

#define Rte_IWrite_CIL_50ms_CIL_TDcChPointPos_CIL_TDcChPointPos(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TDcChPointPos_CIL_TDcChPointPos.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_TDcChPointPos_CIL_TDcChPointPos() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TDcChPointPos_CIL_TDcChPointPos.value \
)

#define Rte_IWrite_CIL_100ms_CIL_TMdul_CIL_TMdul(data) \
  RteIWrite_CIL_100ms_CIL_TMdul_CIL_TMdul(data)

#define RteIWrite_CIL_100ms_CIL_TMdul_CIL_TMdul(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TMdul_CIL_TMdul.value, data, sizeof(rt_Array_Float_54)) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_TMdul_CIL_TMdul() \
  (&((*RteIWriteRef_CIL_100ms_CIL_TMdul_CIL_TMdul())[0]))

#define RteIWriteRef_CIL_100ms_CIL_TMdul_CIL_TMdul() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TMdul_CIL_TMdul.value \
)

#define Rte_IWrite_CIL_100ms_CIL_TMdulCtlr_CIL_TMdulCtlr(data) \
  RteIWrite_CIL_100ms_CIL_TMdulCtlr_CIL_TMdulCtlr(data)

#define RteIWrite_CIL_100ms_CIL_TMdulCtlr_CIL_TMdulCtlr(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TMdulCtlr_CIL_TMdulCtlr.value, data, sizeof(rt_Array_Float_32)) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_TMdulCtlr_CIL_TMdulCtlr() \
  (&((*RteIWriteRef_CIL_100ms_CIL_TMdulCtlr_CIL_TMdulCtlr())[0]))

#define RteIWriteRef_CIL_100ms_CIL_TMdulCtlr_CIL_TMdulCtlr() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TMdulCtlr_CIL_TMdulCtlr.value \
)

#define Rte_IWrite_CIL_100ms_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE(data) \
  RteIWrite_CIL_100ms_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE(data)

#define RteIWrite_CIL_100ms_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE() \
  (&((*RteIWriteRef_CIL_100ms_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE())[0]))

#define RteIWriteRef_CIL_100ms_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE.value \
)

#define Rte_IWrite_CIL_Init_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE(data) \
  RteIWrite_CIL_Init_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE(data)

#define RteIWrite_CIL_Init_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_CIL_Init_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE() \
  (&((*RteIWriteRef_CIL_Init_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE())[0]))

#define RteIWriteRef_CIL_Init_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE.value \
)

#define Rte_IWrite_CIL_50ms_CIL_TSnsrI_CIL_TSnsrI(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TSnsrI_CIL_TSnsrI.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_TSnsrI_CIL_TSnsrI() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TSnsrI_CIL_TSnsrI.value \
)

#define Rte_IWrite_CIL_50ms_CIL_TiSysRun_CIL_TiSysRun(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TiSysRun_CIL_TiSysRun.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_TiSysRun_CIL_TiSysRun() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_TiSysRun_CIL_TiSysRun.value \
)

#define Rte_IWrite_CIL_50ms_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv.value \
)

#define Rte_IWrite_CIL_50ms_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv.value \
)

#define Rte_IWrite_CIL_50ms_CIL_UDcdcLvAct_CIL_UDcdcLvAct(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UDcdcLvAct_CIL_UDcdcLvAct.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_UDcdcLvAct_CIL_UDcdcLvAct() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UDcdcLvAct_CIL_UDcdcLvAct.value \
)

#define Rte_IWrite_CIL_100ms_CIL_UEACAct_CIL_UEACAct(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_UEACAct_CIL_UEACAct.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_UEACAct_CIL_UEACAct() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_UEACAct_CIL_UEACAct.value \
)

#define Rte_IWrite_CIL_50ms_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv.value \
)

#define Rte_IWrite_CIL_10ms_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly.value \
)

#define Rte_IWrite_CIL_50ms_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv.value \
)

#define Rte_IWrite_CIL_50ms_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv.value \
)

#define Rte_IWrite_CIL_10ms_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly.value \
)

#define Rte_IWrite_CIL_10ms_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value \
)

#define Rte_IWrite_CIL_50ms_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv.value \
)

#define Rte_IWrite_CIL_50ms_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv.value \
)

#define Rte_IWrite_CIL_50ms_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv.value \
)

#define Rte_IWrite_CIL_50ms_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv.value \
)

#define Rte_IWrite_CIL_100ms_CIL_UObcChInp_CIL_UObcChInp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_UObcChInp_CIL_UObcChInp.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_UObcChInp_CIL_UObcChInp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_UObcChInp_CIL_UObcChInp.value \
)

#define Rte_IWrite_CIL_100ms_CIL_UObcChOutp_CIL_UObcChOutp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_UObcChOutp_CIL_UObcChOutp.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_UObcChOutp_CIL_UObcChOutp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_UObcChOutp_CIL_UObcChOutp.value \
)

#define Rte_IWrite_CIL_10ms_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh.value \
)

#define Rte_IWrite_CIL_10ms_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg.value \
)

#define Rte_IWrite_CIL_10ms_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat.value \
)

#define Rte_IWrite_CIL_50ms_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv.value \
)

#define Rte_IWrite_CIL_50ms_CIL_UTrml30_CIL_UTrml30(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UTrml30_CIL_UTrml30.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_UTrml30_CIL_UTrml30() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_UTrml30_CIL_UTrml30.value \
)

#define Rte_IWrite_CIL_100ms_CIL_VehicleSpeedInvalid_CIL_VehicleSpeedInvalid(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_VehicleSpeedInvalid_CIL_VehicleSpeedInvalid.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_VehicleSpeedInvalid_CIL_VehicleSpeedInvalid() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_VehicleSpeedInvalid_CIL_VehicleSpeedInvalid.value \
)

#define Rte_IWrite_CIL_50ms_CIL_YearRtc_CIL_YearRtc(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_YearRtc_CIL_YearRtc.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_YearRtc_CIL_YearRtc() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_YearRtc_CIL_YearRtc.value \
)

#define Rte_IWrite_CIL_100ms_CIL_YearTelbox_CIL_YearTelbox(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_YearTelbox_CIL_YearTelbox.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_YearTelbox_CIL_YearTelbox() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_YearTelbox_CIL_YearTelbox.value \
)

#define Rte_IWrite_CIL_100ms_CIL_ZeroPwrFb_CIL_ZeroPwrFb(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ZeroPwrFb_CIL_ZeroPwrFb.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_ZeroPwrFb_CIL_ZeroPwrFb() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_ZeroPwrFb_CIL_ZeroPwrFb.value \
)

#define Rte_IWrite_CIL_10ms_CIL_bAcvRstDiag_CIL_bAcvRstDiag(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_bAcvRstDiag_CIL_bAcvRstDiag.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_CIL_bAcvRstDiag_CIL_bAcvRstDiag() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_bAcvRstDiag_CIL_bAcvRstDiag.value \
)

#define Rte_IWrite_CIL_50ms_CIL_bCANWakeUp_CIL_bCANWakeUp(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bCANWakeUp_CIL_bCANWakeUp.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_bCANWakeUp_CIL_bCANWakeUp() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bCANWakeUp_CIL_bCANWakeUp.value \
)

#define Rte_IWrite_CIL_100ms_CIL_bDCDCW_CIL_bDCDCW(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_bDCDCW_CIL_bDCDCW.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_CIL_bDCDCW_CIL_bDCDCW() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_CIL_bDCDCW_CIL_bDCDCW.value \
)

#define Rte_IWrite_CIL_50ms_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv.value \
)

#define Rte_IWrite_CIL_50ms_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv.value \
)

#define Rte_IWrite_CIL_10ms_CIL_bKCNegClsSts_CIL_bKCNegClsSts(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_bKCNegClsSts_CIL_bKCNegClsSts.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_CIL_bKCNegClsSts_CIL_bKCNegClsSts() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_bKCNegClsSts_CIL_bKCNegClsSts.value \
)

#define Rte_IWrite_CIL_10ms_CIL_bMainNegClsSts_CIL_bMainNegClsSts(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_bMainNegClsSts_CIL_bMainNegClsSts.value = (data) \
)

#define Rte_IWriteRef_CIL_10ms_CIL_bMainNegClsSts_CIL_bMainNegClsSts() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CIL_bMainNegClsSts_CIL_bMainNegClsSts.value \
)

#define Rte_IWrite_CIL_50ms_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd.value \
)

#define Rte_IWrite_CIL_50ms_CIL_bVldBatIHv_CIL_bVldBatIHv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldBatIHv_CIL_bVldBatIHv.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_bVldBatIHv_CIL_bVldBatIHv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldBatIHv_CIL_bVldBatIHv.value \
)

#define Rte_IWrite_CIL_50ms_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg.value \
)

#define Rte_IWrite_CIL_50ms_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg.value \
)

#define Rte_IWrite_CIL_50ms_CIL_bVldIslnR_CIL_bVldIslnR(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldIslnR_CIL_bVldIslnR.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_bVldIslnR_CIL_bVldIslnR() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldIslnR_CIL_bVldIslnR.value \
)

#define Rte_IWrite_CIL_50ms_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly.value \
)

#define Rte_IWrite_CIL_50ms_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly.value \
)

#define Rte_IWrite_CIL_50ms_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly.value \
)

#define Rte_IWrite_CIL_50ms_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh.value \
)

#define Rte_IWrite_CIL_50ms_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat.value \
)

#define Rte_IRead_CIL_100ms_CMLP_Max_DCCur_CMLP_Max_DCCur() \
  (0U)

#define Rte_IRead_CIL_100ms_CMLP_Max_DCV_CMLP_Max_DCV() \
  (0U)

#define Rte_IRead_CIL_100ms_CMLP_Min_DCCur_CMLP_Min_DCCur() \
  (0U)

#define Rte_IRead_CIL_100ms_CMLP_Min_DCV_CMLP_Min_DCV() \
  (0U)

#define Rte_IRead_CIL_10ms_CTC_IDriftZero_CTC_IDriftZero() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CTC_IDriftZero_CTC_IDriftZero.value)

#define Rte_IRead_CIL_10ms_CTC_StLoopHv_CTC_StLoopHv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value)

#define Rte_IRead_CIL_100ms_ChargerReadyForCharging_ChargerReadyForCharging() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_ChargerReadyForCharging_ChargerReadyForCharging.value)

#define Rte_IRead_CIL_100ms_ChargerRevision_ChargerRevision() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_ChargerRevision_ChargerRevision.value)

#define Rte_IWrite_CIL_100ms_ClL_InletWaterTemp_ClL_InletWaterTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_ClL_InletWaterTemp_ClL_InletWaterTemp.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_ClL_InletWaterTemp_ClL_InletWaterTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_ClL_InletWaterTemp_ClL_InletWaterTemp.value \
)

#define Rte_IWrite_CIL_100ms_ClL_OutletWaterTemp_ClL_OutletWaterTemp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_ClL_OutletWaterTemp_ClL_OutletWaterTemp.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_ClL_OutletWaterTemp_ClL_OutletWaterTemp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_ClL_OutletWaterTemp_ClL_OutletWaterTemp.value \
)

#define Rte_IRead_CIL_50ms_CrgChargingPermissible_CrgChargingPermissible() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CrgChargingPermissible_CrgChargingPermissible.value)

#define Rte_IRead_CIL_10ms_CrgSuspCause_Artificial_CrgSuspCause_Artificial() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspCause_Artificial_CrgSuspCause_Artificial.value)

#define Rte_IRead_CIL_10ms_CrgSuspCause_BmsActiveSusp_CrgSuspCause_BmsActiveSusp() \
  (0U)

#define Rte_IRead_CIL_10ms_CrgSuspCause_ChargerCond_CrgSuspCause_ChargerCond() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspCause_ChargerCond_CrgSuspCause_ChargerCond.value)

#define Rte_IRead_CIL_10ms_CrgSuspCause_Fault_CrgSuspCause_Fault() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspCause_Fault_CrgSuspCause_Fault.value)

#define Rte_IRead_CIL_10ms_CrgSuspError_AbnormalVoltage_CrgSuspError_AbnormalVoltage() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspError_AbnormalVoltage_CrgSuspError_AbnormalVoltage.value)

#define Rte_IRead_CIL_10ms_CrgSuspError_CurrentMismatch_CrgSuspError_CurrentMismatch() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspError_CurrentMismatch_CrgSuspError_CurrentMismatch.value)

#define Rte_IRead_CIL_10ms_CrgSuspFault_CannotSupply_CrgSuspFault_CannotSupply() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspFault_CannotSupply_CrgSuspFault_CannotSupply.value)

#define Rte_IRead_CIL_10ms_CrgSuspFault_ChargeConn_CrgSuspFault_ChargeConn() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspFault_ChargeConn_CrgSuspFault_ChargeConn.value)

#define Rte_IRead_CIL_10ms_CrgSuspFault_CrgTemp_CrgSuspFault_CrgTemp() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspFault_CrgTemp_CrgSuspFault_CrgTemp.value)

#define Rte_IRead_CIL_10ms_CrgSuspFault_CrgTempInt_CrgSuspFault_CrgTempInt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspFault_CrgTempInt_CrgSuspFault_CrgTempInt.value)

#define Rte_IRead_CIL_10ms_CrgSuspFault_OtherFault_CrgSuspFault_OtherFault() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspFault_OtherFault_CrgSuspFault_OtherFault.value)

#define Rte_IRead_CIL_10ms_CrgSuspFault_SuddenStop_CrgSuspFault_SuddenStop() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_CrgSuspFault_SuddenStop_CrgSuspFault_SuddenStop.value)

#define Rte_IRead_CIL_50ms_CumulativeChargingTime_CumulativeChargingTime() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CumulativeChargingTime_CumulativeChargingTime.value)

#define Rte_IRead_CIL_50ms_CurrentOutputValue_CurrentOutputValue() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_CurrentOutputValue_CurrentOutputValue.value)

#define Rte_IRead_CIL_50ms_EHB_VehicleSpeed_EHB_VehicleSpeed() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_EHB_VehicleSpeed_EHB_VehicleSpeed.value)

#define Rte_IRead_CIL_100ms_EHB_VehicleSpeedInvalid_EHB_VehicleSpeedInvalid() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_EHB_VehicleSpeedInvalid_EHB_VehicleSpeedInvalid.value)

#define Rte_IRead_CIL_10ms_HvSysSample_Current_Current() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_HvSysSample_Current_Current.value)

#define Rte_IRead_CIL_50ms_HvSysSample_Current_sensorTemp_Current_sensorTemp() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_Current_sensorTemp_Current_sensorTemp.value)

#define Rte_IRead_CIL_50ms_HvSysSample_NegInsulationRes_NegInsulationRes() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_NegInsulationRes_NegInsulationRes.value)

#define Rte_IRead_CIL_50ms_HvSysSample_PosInsulationRes_PosInsulationRes() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_PosInsulationRes_PosInsulationRes.value)

#define Rte_IRead_CIL_10ms_HvSysSample_RelayKCNegClsSts_U8_RelayKCNegClsSts_U8() \
  (0U)

#define Rte_IRead_CIL_10ms_HvSysSample_RelayKCNegVoltage_RelayKCNegVoltage() \
  (0)

#define Rte_IRead_CIL_10ms_HvSysSample_RelayKCVoltage_RelayKCVoltage() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_HvSysSample_RelayKCVoltage_RelayKCVoltage.value)

#define Rte_IRead_CIL_10ms_HvSysSample_RelayKHVoltage_RelayKHVoltage() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_HvSysSample_RelayKHVoltage_RelayKHVoltage.value)

#define Rte_IRead_CIL_10ms_HvSysSample_RelayKMVoltage_RelayKMVoltage() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_HvSysSample_RelayKMVoltage_RelayKMVoltage.value)

#define Rte_IRead_CIL_10ms_HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8.value)

#define Rte_IRead_CIL_10ms_HvSysSample_RelayKNVoltage_RelayKNVoltage() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_HvSysSample_RelayKNVoltage_RelayKNVoltage.value)

#define Rte_IRead_CIL_50ms_HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16.value)

#define Rte_IRead_CIL_50ms_HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16.value)

#define Rte_IRead_CIL_50ms_HvSysSample_SampleValidBat_U8_SampleValidBat_U8() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleValidBat_U8_SampleValidBat_U8.value)

#define Rte_IRead_CIL_50ms_HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8.value)

#define Rte_IRead_CIL_50ms_HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8.value)

#define Rte_IRead_CIL_50ms_HvSysSample_SampleValidKC_U8_SampleValidKC_U8() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleValidKC_U8_SampleValidKC_U8.value)

#define Rte_IRead_CIL_50ms_HvSysSample_SampleValidKH_U8_SampleValidKH_U8() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleValidKH_U8_SampleValidKH_U8.value)

#define Rte_IRead_CIL_50ms_HvSysSample_SampleValidKM_U8_SampleValidKM_U8() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleValidKM_U8_SampleValidKM_U8.value)

#define Rte_IRead_CIL_50ms_HvSysSample_SampleValidKN_U8_SampleValidKN_U8() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_HvSysSample_SampleValidKN_U8_SampleValidKN_U8.value)

#define Rte_IRead_CIL_10ms_HvSysSample_TotalVoltage_TotalVoltage() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_HvSysSample_TotalVoltage_TotalVoltage.value)

#define Rte_IRead_CIL_100ms_IPK_Day_IPK_Day() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_IPK_Day_IPK_Day.value)

#define Rte_IRead_CIL_100ms_IPK_Hour_IPK_Hour() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_IPK_Hour_IPK_Hour.value)

#define Rte_IRead_CIL_100ms_IPK_IPKTotalOdometer_IPK_IPKTotalOdometer() \
  (0U)

#define Rte_IRead_CIL_100ms_IPK_Minute_IPK_Minute() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_IPK_Minute_IPK_Minute.value)

#define Rte_IRead_CIL_100ms_IPK_Month_IPK_Month() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_IPK_Month_IPK_Month.value)

#define Rte_IRead_CIL_100ms_IPK_Second_IPK_Second() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_IPK_Second_IPK_Second.value)

#define Rte_IRead_CIL_100ms_IPK_Year_IPK_Year() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_IPK_Year_IPK_Year.value)

#define Rte_IRead_CIL_10ms_IPU_DischgState_IPU_DischgState() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_IPU_DischgState_IPU_DischgState.value)

#define Rte_IRead_CIL_50ms_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn.value)

#define Rte_IWrite_CIL_100ms_MCC_NrAFETot_MCC_NrAFETot(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrAFETot_MCC_NrAFETot.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_MCC_NrAFETot_MCC_NrAFETot() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrAFETot_MCC_NrAFETot.value \
)

#define Rte_IWrite_CIL_Init_MCC_NrAFETot_MCC_NrAFETot(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrAFETot_MCC_NrAFETot.value = (data) \
)

#define Rte_IWriteRef_CIL_Init_MCC_NrAFETot_MCC_NrAFETot() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrAFETot_MCC_NrAFETot.value \
)

#define Rte_IWrite_CIL_100ms_MCC_NrCellByMdul_MCC_NrCellByMdul(data) \
  RteIWrite_CIL_100ms_MCC_NrCellByMdul_MCC_NrCellByMdul(data)

#define RteIWrite_CIL_100ms_MCC_NrCellByMdul_MCC_NrCellByMdul(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrCellByMdul_MCC_NrCellByMdul.value, data, sizeof(rt_Array_UInt8_24)) \
)

#define Rte_IWriteRef_CIL_100ms_MCC_NrCellByMdul_MCC_NrCellByMdul() \
  (&((*RteIWriteRef_CIL_100ms_MCC_NrCellByMdul_MCC_NrCellByMdul())[0]))

#define RteIWriteRef_CIL_100ms_MCC_NrCellByMdul_MCC_NrCellByMdul() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrCellByMdul_MCC_NrCellByMdul.value \
)

#define Rte_IWrite_CIL_Init_MCC_NrCellByMdul_MCC_NrCellByMdul(data) \
  RteIWrite_CIL_Init_MCC_NrCellByMdul_MCC_NrCellByMdul(data)

#define RteIWrite_CIL_Init_MCC_NrCellByMdul_MCC_NrCellByMdul(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrCellByMdul_MCC_NrCellByMdul.value, data, sizeof(rt_Array_UInt8_24)) \
)

#define Rte_IWriteRef_CIL_Init_MCC_NrCellByMdul_MCC_NrCellByMdul() \
  (&((*RteIWriteRef_CIL_Init_MCC_NrCellByMdul_MCC_NrCellByMdul())[0]))

#define RteIWriteRef_CIL_Init_MCC_NrCellByMdul_MCC_NrCellByMdul() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrCellByMdul_MCC_NrCellByMdul.value \
)

#define Rte_IWrite_CIL_100ms_MCC_NrCellTot_MCC_NrCellTot(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrCellTot_MCC_NrCellTot.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_MCC_NrCellTot_MCC_NrCellTot() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrCellTot_MCC_NrCellTot.value \
)

#define Rte_IWrite_CIL_Init_MCC_NrCellTot_MCC_NrCellTot(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrCellTot_MCC_NrCellTot.value = (data) \
)

#define Rte_IWriteRef_CIL_Init_MCC_NrCellTot_MCC_NrCellTot() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrCellTot_MCC_NrCellTot.value \
)

#define Rte_IWrite_CIL_100ms_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul(data) \
  RteIWrite_CIL_100ms_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul(data)

#define RteIWrite_CIL_100ms_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul.value, data, sizeof(rt_Array_UInt8_24)) \
)

#define Rte_IWriteRef_CIL_100ms_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul() \
  (&((*RteIWriteRef_CIL_100ms_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul())[0]))

#define RteIWriteRef_CIL_100ms_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul.value \
)

#define Rte_IWrite_CIL_Init_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul(data) \
  RteIWrite_CIL_Init_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul(data)

#define RteIWrite_CIL_Init_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul.value, data, sizeof(rt_Array_UInt8_24)) \
)

#define Rte_IWriteRef_CIL_Init_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul() \
  (&((*RteIWriteRef_CIL_Init_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul())[0]))

#define RteIWriteRef_CIL_Init_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul.value \
)

#define Rte_IWrite_CIL_100ms_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot.value \
)

#define Rte_IWrite_CIL_Init_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot.value = (data) \
)

#define Rte_IWriteRef_CIL_Init_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot.value \
)

#define Rte_IWrite_CIL_100ms_MCC_NrMdulTot_MCC_NrMdulTot(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_MCC_NrMdulTot_MCC_NrMdulTot() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value \
)

#define Rte_IWrite_CIL_Init_MCC_NrMdulTot_MCC_NrMdulTot(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value = (data) \
)

#define Rte_IWriteRef_CIL_Init_MCC_NrMdulTot_MCC_NrMdulTot() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value \
)

#define Rte_IWrite_CIL_100ms_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul(data) \
  RteIWrite_CIL_100ms_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul(data)

#define RteIWrite_CIL_100ms_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul.value, data, sizeof(rt_Array_UInt8_24)) \
)

#define Rte_IWriteRef_CIL_100ms_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul() \
  (&((*RteIWriteRef_CIL_100ms_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul())[0]))

#define RteIWriteRef_CIL_100ms_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul.value \
)

#define Rte_IWrite_CIL_Init_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul(data) \
  RteIWrite_CIL_Init_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul(data)

#define RteIWrite_CIL_Init_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul.value, data, sizeof(rt_Array_UInt8_24)) \
)

#define Rte_IWriteRef_CIL_Init_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul() \
  (&((*RteIWriteRef_CIL_Init_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul())[0]))

#define RteIWriteRef_CIL_Init_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul.value \
)

#define Rte_IWrite_CIL_100ms_MCC_NrSnsrTTot_MCC_NrSnsrTTot(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrSnsrTTot_MCC_NrSnsrTTot.value = (data) \
)

#define Rte_IWriteRef_CIL_100ms_MCC_NrSnsrTTot_MCC_NrSnsrTTot() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MCC_NrSnsrTTot_MCC_NrSnsrTTot.value \
)

#define Rte_IWrite_CIL_Init_MCC_NrSnsrTTot_MCC_NrSnsrTTot(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrSnsrTTot_MCC_NrSnsrTTot.value = (data) \
)

#define Rte_IWriteRef_CIL_Init_MCC_NrSnsrTTot_MCC_NrSnsrTTot() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CIL_CIL_Init.Rte_MCC_NrSnsrTTot_MCC_NrSnsrTTot.value \
)

#define Rte_IWrite_CIL_50ms_MCC_StMdulCu_MCC_StMdulCu(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_MCC_StMdulCu_MCC_StMdulCu.value = (data) \
)

#define Rte_IWriteRef_CIL_50ms_MCC_StMdulCu_MCC_StMdulCu() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_MCC_StMdulCu_MCC_StMdulCu.value \
)

#define Rte_IRead_CIL_100ms_MaxOutputCurrent_MaxOutputCurrent() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MaxOutputCurrent_MaxOutputCurrent.value)

#define Rte_IRead_CIL_100ms_MaxOutputVoltage_MaxOutputVoltage() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MaxOutputVoltage_MaxOutputVoltage.value)

#define Rte_IRead_CIL_100ms_MinOutputCurrent_MinOutputCurrent() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MinOutputCurrent_MinOutputCurrent.value)

#define Rte_IRead_CIL_100ms_MinOutputVoltage_MinOutputVoltage() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_MinOutputVoltage_MinOutputVoltage.value)

#define Rte_IRead_CIL_100ms_OBC_CCvalue_OBC_CCvalue() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_CCvalue_OBC_CCvalue.value)

#define Rte_IRead_CIL_100ms_OBC_ChgCCSts_OBC_ChgCCSts() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_ChgCCSts_OBC_ChgCCSts.value)

#define Rte_IRead_CIL_100ms_OBC_ChrgrSt_OBC_ChrgrSt() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_ChrgrSt_OBC_ChrgrSt.value)

#define Rte_IRead_CIL_100ms_OBC_DischargeCCvalue_OBC_DischargeCCvalue() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_DischargeCCvalue_OBC_DischargeCCvalue.value)

#define Rte_IRead_CIL_100ms_OBC_Elock_Stmode_OBC_Elock_Stmode() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_Elock_Stmode_OBC_Elock_Stmode.value)

#define Rte_IRead_CIL_100ms_OBC_OnBdCCline_OBC_OnBdCCline() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_OnBdCCline_OBC_OnBdCCline.value)

#define Rte_IRead_CIL_100ms_OBC_OnBdCPline_OBC_OnBdCPline() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_OnBdCPline_OBC_OnBdCPline.value)

#define Rte_IRead_CIL_100ms_OBC_OnBdDisChrgrCCline_OBC_OnBdDisChrgrCCline() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_OnBdDisChrgrCCline_OBC_OnBdDisChrgrCCline.value)

#define Rte_IRead_CIL_100ms_OBC_OnBdOuptI_OBC_OnBdOuptI() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_OnBdOuptI_OBC_OnBdOuptI.value)

#define Rte_IRead_CIL_100ms_OBC_OnBdOuptU_OBC_OnBdOuptU() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_OnBdOuptU_OBC_OnBdOuptU.value)

#define Rte_IRead_CIL_100ms_OBC_uInAct_OBC_uInAct() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OBC_uInAct_OBC_uInAct.value)

#define Rte_IRead_CIL_100ms_OutputEnergy_OutputEnergy() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_OutputEnergy_OutputEnergy.value)

#define Rte_IRead_CIL_100ms_PEPS_PowerMode_PEPS_PowerMode() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_PEPS_PowerMode_PEPS_PowerMode.value)

#define Rte_IRead_CIL_100ms_PMS_BatCoolType_PMS_BatCoolType() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_PMS_BatCoolType_PMS_BatCoolType.value)

#define Rte_IRead_CIL_100ms_PMS_Wakeup_reasons_PMS_Wakeup_reasons() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_PMS_Wakeup_reasons_PMS_Wakeup_reasons.value)

#define Rte_IRead_CIL_100ms_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb.value)

#define Rte_IRead_CIL_50ms_RTC_NowSystemTick_NowSystemTick() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_NowSystemTick_NowSystemTick.value)

#define Rte_IRead_CIL_50ms_RTC_RTCStateFault_RTCStateFault() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_RTCStateFault_RTCStateFault.value)

#define Rte_IRead_CIL_50ms_RTC_ReadDay_ReadDay() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_ReadDay_ReadDay.value)

#define Rte_IRead_CIL_50ms_RTC_ReadHour_ReadHour() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_ReadHour_ReadHour.value)

#define Rte_IRead_CIL_50ms_RTC_ReadMinute_ReadMinute() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_ReadMinute_ReadMinute.value)

#define Rte_IRead_CIL_50ms_RTC_ReadMonth_ReadMonth() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_ReadMonth_ReadMonth.value)

#define Rte_IRead_CIL_50ms_RTC_ReadSecond_ReadSecond() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_ReadSecond_ReadSecond.value)

#define Rte_IRead_CIL_50ms_RTC_ReadYear_ReadYear() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_RTC_ReadYear_ReadYear.value)

#define Rte_IRead_CIL_100ms_RecognitionResult_RecognitionResult() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_RecognitionResult_RecognitionResult.value)

#define Rte_IRead_CIL_100ms_TBOX_ChrgSoftSwCtrlSt_TBOX_ChrgSoftSwCtrlSt() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_TBOX_ChrgSoftSwCtrlSt_TBOX_ChrgSoftSwCtrlSt.value)

#define Rte_IRead_CIL_100ms_TBOX_ReservationChrgnSts_TBOX_ReservationChrgnSts() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_TBOX_ReservationChrgnSts_TBOX_ReservationChrgnSts.value)

#define Rte_IRead_CIL_100ms_Timeout_BCL_Timeout_BCL() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_Timeout_BCL_Timeout_BCL.value)

#define Rte_IRead_CIL_100ms_Timeout_BCP_Timeout_BCP() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_Timeout_BCP_Timeout_BCP.value)

#define Rte_IRead_CIL_100ms_Timeout_BCS_Timeout_BCS() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_Timeout_BCS_Timeout_BCS.value)

#define Rte_IRead_CIL_100ms_Timeout_BRM_Timeout_BRM() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_Timeout_BRM_Timeout_BRM.value)

#define Rte_IRead_CIL_100ms_Timeout_BRO_Timeout_BRO() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_Timeout_BRO_Timeout_BRO.value)

#define Rte_IRead_CIL_100ms_Timeout_BSD_Timeout_BSD() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_Timeout_BSD_Timeout_BSD.value)

#define Rte_IRead_CIL_100ms_Timeout_BSM_Timeout_BSM() \
  (0U)

#define Rte_IRead_CIL_100ms_Timeout_BST_Timeout_BST() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_Timeout_BST_Timeout_BST.value)

#define Rte_IRead_CIL_50ms_VCU_ActInputVolt_VCU_ActInputVolt() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_VCU_ActInputVolt_VCU_ActInputVolt.value)

#define Rte_IRead_CIL_50ms_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax.value)

#define Rte_IRead_CIL_50ms_VCU_BMSH_FaultResetReq_VCU_BMSH_FaultResetReq() \
  (FALSE)

#define Rte_IRead_CIL_100ms_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp.value)

#define Rte_IRead_CIL_100ms_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp.value)

#define Rte_IRead_CIL_100ms_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq.value)

#define Rte_IRead_CIL_50ms_VCU_ChargeDepthReq_VCU_ChargeDepthReq() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_VCU_ChargeDepthReq_VCU_ChargeDepthReq.value)

#define Rte_IRead_CIL_100ms_VCU_ChargeModeReq_VCU_ChargeModeReq() \
  (0U)

#define Rte_IRead_CIL_10ms_VCU_CrashOutputSts_VCU_CrashOutputSts() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_10ms.Rte_VCU_CrashOutputSts_VCU_CrashOutputSts.value)

#define Rte_IRead_CIL_100ms_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_100ms.Rte_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual.value)

#define Rte_IRead_CIL_50ms_VoltageOutputValue_VoltageOutputValue() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_CIL_CIL_50ms.Rte_VoltageOutputValue_VoltageOutputValue.value)

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
#define Rte_Read_HvSysSample_SampleCountInsRes_U16_SampleCountInsRes_U16 Rte_Read_swc_CIL_HvSysSample_SampleCountInsRes_U16_SampleCountInsRes_U16
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
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, swc_GetInputInterface_CODE) If_AdcConvertValueInput_GetAdcConvertValue(VAR(UInt32, RTE_swc_GetInputInterface_APPL_DATA) NumId, P2VAR(SInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) value);
FUNC(void, swc_GetInputInterface_CODE) If_IcuDutyValueInput_GetIcuDutyValue(VAR(UInt32, RTE_swc_GetInputInterface_APPL_DATA) NumId, P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) value);
FUNC(void, swc_GetInputInterface_CODE) If_IcuPeriodValueInput_GetIcuPeriodValue(VAR(UInt32, RTE_swc_GetInputInterface_APPL_DATA) NumId, P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) value);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifndef RTE_CORE
#define Rte_Call_If_AdcConvertValueInput_GetAdcConvertValue Rte_Call_swc_CIL_If_AdcConvertValueInput_GetAdcConvertValue
#define Rte_Call_swc_CIL_If_AdcConvertValueInput_GetAdcConvertValue(arg1, arg2) (If_AdcConvertValueInput_GetAdcConvertValue(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_If_IcuDutyValueInput_GetIcuDutyValue Rte_Call_swc_CIL_If_IcuDutyValueInput_GetIcuDutyValue
#define Rte_Call_swc_CIL_If_IcuDutyValueInput_GetIcuDutyValue(arg1, arg2) (If_IcuDutyValueInput_GetIcuDutyValue(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_If_IcuPeriodValueInput_GetIcuPeriodValue Rte_Call_swc_CIL_If_IcuPeriodValueInput_GetIcuPeriodValue
#define Rte_Call_swc_CIL_If_IcuPeriodValueInput_GetIcuPeriodValue(arg1, arg2) (If_IcuPeriodValueInput_GetIcuPeriodValue(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#endif /* !defined(RTE_CORE) */

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
FUNC(void, swc_CIL_CODE) CIL_100ms(void);
FUNC(void, swc_CIL_CODE) CIL_10ms(void);
FUNC(void, swc_CIL_CODE) CIL_50ms(void);
FUNC(void, swc_CIL_CODE) CIL_Init(void);
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
#endif /* RTE_SWC_CIL_H_ */
 
 
 

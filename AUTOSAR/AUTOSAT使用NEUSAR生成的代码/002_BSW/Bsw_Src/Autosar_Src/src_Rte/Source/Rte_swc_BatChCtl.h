 
/*
************************************************************************************************************************
*
* File name: Rte_swc_BatChCtl.h
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
#ifndef RTE_SWC_BATCHCTL_H_
#define RTE_SWC_BATCHCTL_H_

#include "Rte_swc_BatChCtl_Type.h"
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
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_AcvCellURchd_BCC_AcvCellURchd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_AcvSocRchd_BCC_AcvSocRchd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_AcvUTotRchd_BCC_AcvUTotRchd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ChgCCSts_BCC_ChgCCSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_EChSng_BCC_EChSng;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ElectroniclockContorFault_BCC_ElectroniclockContorFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ElectroniclockSt_BCC_ElectroniclockSt;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ErrInfo_BCC_ErrInfo;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_IChReq_BCC_IChReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_IDchaReq_BCC_IDchaReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_IObcLimn_BCC_IObcLimn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ModeCh_BCC_ModeCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_StAcChReq_BCC_StAcChReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_StAcSys_BCC_StAcSys;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_StCh_BCC_StCh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_UChReq_BCC_UChReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_UObcLimn_BCC_UObcLimn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_bAcvDig10_BCC_bAcvDig10;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_bS2Ctrl_BCC_bS2Ctrl;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCTE_TiBatChMaxByHour_BCTE_TiBatChMaxByHour;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCTE_TiBatChMaxByMinu_BCTE_TiBatChMaxByMinu;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ChMode_EVCSH_ChMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_IChrgrSp_EVCSH_IChrgrSp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StBatRdy_EVCSH_StBatRdy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StDcCh_EVCSH_StDcCh;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StInt_EVCSH_StInt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_UChrgrSp_EVCSH_UChrgrSp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvVeh2VehDcha_EVCSH_bAcvVeh2VehDcha;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_TimeOut_CRO00_BCC_TimeOutCRO00;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_TimeOut_CROAA_BCC_TimeOutCROAA;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_CMdulAbsv_BCF_CMdulAbsv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLim_BCF_IChLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohPack_BCF_SohPack;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_IAct_BPP_IAct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_DirChAndDcha_BSOF_DirChAndDcha;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChImpo_BSOF_ErrChImpo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrUndfnd_BSOF_ErrUndfnd;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IChrgrMax_BSOF_IChrgrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IChrgrMin_BSOF_IChrgrMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UChrgrMax_BSOF_UChrgrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UChrgrMin_BSOF_UChrgrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UDchaMax_BSOF_UDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UDchaMin_BSOF_UDchaMin;
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
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_ErrChEnd_BTHM_ErrChEnd;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StSys_BTHM_StSys;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TPack_BTHM_TPack;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_BatCoolType_CIL_BatCoolType;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_CP_Vol_CIL_CP_Vol;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ChgCCSts_CIL_ChgCCSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DucycCtlPilot_CIL_DucycCtlPilot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_IDcdcLvAct_CIL_IDcdcLvAct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_OnBdCPline_CIL_OnBdCPline;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_PwrEACAct_CIL_PwrEACAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_PwrPtcAct_CIL_PwrPtcAct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_RAcChCnctn_CIL_RAcChCnctn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_RDisChCnctn_CIL_RDisChCnctn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StAcChCnct_CIL_StAcChCnct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StBatHvReq_CIL_StBatHvReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StChAllwd_CIL_StChAllwd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StChWup_CIL_StChWup;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StMsgToutForObc_CIL_StMsgToutForObc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StObc_CIL_StObc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TAcChPointNeg_CIL_TAcChPointNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TAcChPointPos_CIL_TAcChPointPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TDcChPointNeg_CIL_TDcChPointNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TDcChPointPos_CIL_TDcChPointPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UDcdcLvAct_CIL_UDcdcLvAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UObcChInp_CIL_UObcChInp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyCh_CTC_StRlyCh;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StSysInt_CTC_StSysInt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd4_DEH_ErrCfmd4;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvAcChInh_DEH_bAcvAcChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvChInh_DEH_bAcvChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvDcChInh_DEH_bAcvDcChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIsln_ELHPN_StIsln;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCellTot_MCC_NrCellTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_BatChCtl_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq(UInt8 data);
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
#define Rte_IWrite_BCC_10ms_BCC_AcvCellURchd_BCC_AcvCellURchd(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_AcvCellURchd_BCC_AcvCellURchd.value = (data) \
)

#define Rte_IWriteRef_BCC_10ms_BCC_AcvCellURchd_BCC_AcvCellURchd() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_AcvCellURchd_BCC_AcvCellURchd.value \
)

#define Rte_IWrite_BCC_10ms_BCC_AcvSocRchd_BCC_AcvSocRchd(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_AcvSocRchd_BCC_AcvSocRchd.value = (data) \
)

#define Rte_IWriteRef_BCC_10ms_BCC_AcvSocRchd_BCC_AcvSocRchd() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_AcvSocRchd_BCC_AcvSocRchd.value \
)

#define Rte_IWrite_BCC_10ms_BCC_AcvUTotRchd_BCC_AcvUTotRchd(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_AcvUTotRchd_BCC_AcvUTotRchd.value = (data) \
)

#define Rte_IWriteRef_BCC_10ms_BCC_AcvUTotRchd_BCC_AcvUTotRchd() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_AcvUTotRchd_BCC_AcvUTotRchd.value \
)

#define Rte_IWrite_AC_10ms_BCC_ChgCCSts_BCC_ChgCCSts(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_ChgCCSts_BCC_ChgCCSts.value = (data) \
)

#define Rte_IWriteRef_AC_10ms_BCC_ChgCCSts_BCC_ChgCCSts() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_ChgCCSts_BCC_ChgCCSts.value \
)

#define Rte_IWrite_BCC_10ms_BCC_EChSng_BCC_EChSng(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_EChSng_BCC_EChSng.value = (data) \
)

#define Rte_IWriteRef_BCC_10ms_BCC_EChSng_BCC_EChSng() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_EChSng_BCC_EChSng.value \
)

#define Rte_IWrite_AC_10ms_BCC_ElectroniclockContorFault_BCC_ElectroniclockContorFault(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_ElectroniclockContorFault_BCC_ElectroniclockContorFault.value = (data) \
)

#define Rte_IWriteRef_AC_10ms_BCC_ElectroniclockContorFault_BCC_ElectroniclockContorFault() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_ElectroniclockContorFault_BCC_ElectroniclockContorFault.value \
)

#define Rte_IWrite_AC_10ms_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ.value = (data) \
)

#define Rte_IWriteRef_AC_10ms_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ.value \
)

#define Rte_IWrite_AC_10ms_BCC_ElectroniclockSt_BCC_ElectroniclockSt(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_ElectroniclockSt_BCC_ElectroniclockSt.value = (data) \
)

#define Rte_IWriteRef_AC_10ms_BCC_ElectroniclockSt_BCC_ElectroniclockSt() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_ElectroniclockSt_BCC_ElectroniclockSt.value \
)

#define Rte_IWrite_DC_10ms_BCC_ErrInfo_BCC_ErrInfo(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BCC_ErrInfo_BCC_ErrInfo.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_BCC_ErrInfo_BCC_ErrInfo() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BCC_ErrInfo_BCC_ErrInfo.value \
)

#define Rte_IWrite_BCC_10ms_BCC_IChReq_BCC_IChReq(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_IChReq_BCC_IChReq.value = (data) \
)

#define Rte_IWriteRef_BCC_10ms_BCC_IChReq_BCC_IChReq() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_IChReq_BCC_IChReq.value \
)

#define Rte_IWrite_BCC_10ms_BCC_IDchaReq_BCC_IDchaReq(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_IDchaReq_BCC_IDchaReq.value = (data) \
)

#define Rte_IWriteRef_BCC_10ms_BCC_IDchaReq_BCC_IDchaReq() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_IDchaReq_BCC_IDchaReq.value \
)

#define Rte_IWrite_AC_10ms_BCC_IObcLimn_BCC_IObcLimn(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_IObcLimn_BCC_IObcLimn.value = (data) \
)

#define Rte_IWriteRef_AC_10ms_BCC_IObcLimn_BCC_IObcLimn() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_IObcLimn_BCC_IObcLimn.value \
)

#define Rte_IWrite_BCC_10ms_BCC_ModeCh_BCC_ModeCh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_ModeCh_BCC_ModeCh.value = (data) \
)

#define Rte_IWriteRef_BCC_10ms_BCC_ModeCh_BCC_ModeCh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_ModeCh_BCC_ModeCh.value \
)

#define Rte_IWrite_AC_10ms_BCC_StAcChReq_BCC_StAcChReq(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_StAcChReq_BCC_StAcChReq.value = (data) \
)

#define Rte_IWriteRef_AC_10ms_BCC_StAcChReq_BCC_StAcChReq() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_StAcChReq_BCC_StAcChReq.value \
)

#define Rte_IWrite_AC_10ms_BCC_StAcSys_BCC_StAcSys(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_StAcSys_BCC_StAcSys.value = (data) \
)

#define Rte_IWriteRef_AC_10ms_BCC_StAcSys_BCC_StAcSys() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_StAcSys_BCC_StAcSys.value \
)

#define Rte_IWrite_BCC_Init_BCC_StAcSys_BCC_StAcSys(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_BCC_StAcSys_BCC_StAcSys.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_BCC_StAcSys_BCC_StAcSys() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_BCC_StAcSys_BCC_StAcSys.value \
)

#define Rte_IWrite_BCC_10ms_BCC_StCh_BCC_StCh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_StCh_BCC_StCh.value = (data) \
)

#define Rte_IWriteRef_BCC_10ms_BCC_StCh_BCC_StCh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_StCh_BCC_StCh.value \
)

#define Rte_IWrite_AC_10ms_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq.value = (data) \
)

#define Rte_IWriteRef_AC_10ms_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq.value \
)

#define Rte_IWrite_DC_10ms_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq.value \
)

#define Rte_IWrite_BCC_Init_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq.value \
)

#define Rte_IWrite_BCC_10ms_BCC_UChReq_BCC_UChReq(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_UChReq_BCC_UChReq.value = (data) \
)

#define Rte_IWriteRef_BCC_10ms_BCC_UChReq_BCC_UChReq() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_UChReq_BCC_UChReq.value \
)

#define Rte_IWrite_AC_10ms_BCC_UObcLimn_BCC_UObcLimn(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_UObcLimn_BCC_UObcLimn.value = (data) \
)

#define Rte_IWriteRef_AC_10ms_BCC_UObcLimn_BCC_UObcLimn() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_UObcLimn_BCC_UObcLimn.value \
)

#define Rte_IWrite_AC_10ms_BCC_bAcvDig10_BCC_bAcvDig10(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_bAcvDig10_BCC_bAcvDig10.value = (data) \
)

#define Rte_IWriteRef_AC_10ms_BCC_bAcvDig10_BCC_bAcvDig10() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_bAcvDig10_BCC_bAcvDig10.value \
)

#define Rte_IWrite_BCC_10ms_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull.value = (data) \
)

#define Rte_IWriteRef_BCC_10ms_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull.value \
)

#define Rte_IWrite_AC_10ms_BCC_bS2Ctrl_BCC_bS2Ctrl(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_bS2Ctrl_BCC_bS2Ctrl.value = (data) \
)

#define Rte_IWriteRef_AC_10ms_BCC_bS2Ctrl_BCC_bS2Ctrl() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCC_bS2Ctrl_BCC_bS2Ctrl.value \
)

#define Rte_IRead_BCC_10ms_BCF_CMdulAbsv_BCF_CMdulAbsv() \
  (&((*RteIRead_BCC_10ms_BCF_CMdulAbsv_BCF_CMdulAbsv())[0]))

#define RteIRead_BCC_10ms_BCF_CMdulAbsv_BCF_CMdulAbsv() \
  (&Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCF_CMdulAbsv_BCF_CMdulAbsv.value)

#define Rte_IRead_BCC_10ms_BCF_IChLim_BCF_IChLim() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCF_IChLim_BCF_IChLim.value)

#define Rte_IRead_BCC_10ms_BCF_SocPack_BCF_SocPack() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCF_SocPack_BCF_SocPack.value)

#define Rte_IRead_DC_10ms_BCF_SocPack_BCF_SocPack() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BCF_SocPack_BCF_SocPack.value)

#define Rte_IRead_AC_10ms_BCF_SocPackScld_BCF_SocPackScld() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCF_SocPackScld_BCF_SocPackScld.value)

#define Rte_IRead_BCC_10ms_BCF_SocPackScld_BCF_SocPackScld() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCF_SocPackScld_BCF_SocPackScld.value)

#define Rte_IRead_DC_10ms_BCF_SocPackScld_BCF_SocPackScld() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BCF_SocPackScld_BCF_SocPackScld.value)

#define Rte_IRead_BCC_10ms_BCF_SohPack_BCF_SohPack() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCF_SohPack_BCF_SohPack.value)

#define Rte_IRead_AC_10ms_BCF_UBatTotInt_BCF_UBatTotInt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value)

#define Rte_IRead_BCC_10ms_BCF_UBatTotInt_BCF_UBatTotInt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value)

#define Rte_IRead_DC_10ms_BCF_UBatTotInt_BCF_UBatTotInt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value)

#define Rte_IWrite_BCC_10ms_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot.value = (data) \
)

#define Rte_IWriteRef_BCC_10ms_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot.value \
)

#define Rte_IWrite_BCC_10ms_BCTE_TiBatChMaxByHour_BCTE_TiBatChMaxByHour(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCTE_TiBatChMaxByHour_BCTE_TiBatChMaxByHour.value = (data) \
)

#define Rte_IWriteRef_BCC_10ms_BCTE_TiBatChMaxByHour_BCTE_TiBatChMaxByHour() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCTE_TiBatChMaxByHour_BCTE_TiBatChMaxByHour.value \
)

#define Rte_IWrite_BCC_10ms_BCTE_TiBatChMaxByMinu_BCTE_TiBatChMaxByMinu(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCTE_TiBatChMaxByMinu_BCTE_TiBatChMaxByMinu.value = (data) \
)

#define Rte_IWriteRef_BCC_10ms_BCTE_TiBatChMaxByMinu_BCTE_TiBatChMaxByMinu() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCTE_TiBatChMaxByMinu_BCTE_TiBatChMaxByMinu.value \
)

#define Rte_IWrite_BCC_10ms_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot.value = (data) \
)

#define Rte_IWriteRef_BCC_10ms_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot.value \
)

#define Rte_IRead_BCC_10ms_BPIU_UCellMax_BPIU_UCellMax() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BPIU_UCellMax_BPIU_UCellMax.value)

#define Rte_IRead_DC_10ms_BPP_IAct_BPP_IAct() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BPP_IAct_BPP_IAct.value)

#define Rte_IRead_DC_10ms_BSOF_DirChAndDcha_BSOF_DirChAndDcha() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_DirChAndDcha_BSOF_DirChAndDcha.value)

#define Rte_IRead_DC_10ms_BSOF_ErrChImpo_BSOF_ErrChImpo() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_ErrChImpo_BSOF_ErrChImpo.value)

#define Rte_IRead_DC_10ms_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt.value)

#define Rte_IRead_DC_10ms_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt.value)

#define Rte_IRead_DC_10ms_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt.value)

#define Rte_IRead_DC_10ms_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy.value)

#define Rte_IRead_DC_10ms_BSOF_ErrUndfnd_BSOF_ErrUndfnd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_ErrUndfnd_BSOF_ErrUndfnd.value)

#define Rte_IRead_DC_10ms_BSOF_IChrgrMax_BSOF_IChrgrMax() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_IChrgrMax_BSOF_IChrgrMax.value)

#define Rte_IRead_DC_10ms_BSOF_IChrgrMin_BSOF_IChrgrMin() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_IChrgrMin_BSOF_IChrgrMin.value)

#define Rte_IRead_DC_10ms_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn.value)

#define Rte_IRead_DC_10ms_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy.value)

#define Rte_IRead_DC_10ms_BSOF_UChrgrMax_BSOF_UChrgrMax() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_UChrgrMax_BSOF_UChrgrMax.value)

#define Rte_IRead_DC_10ms_BSOF_UChrgrMin_BSOF_UChrgrMin() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_UChrgrMin_BSOF_UChrgrMin.value)

#define Rte_IRead_DC_10ms_BSOF_UDchaMax_BSOF_UDchaMax() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_UDchaMax_BSOF_UDchaMax.value)

#define Rte_IRead_DC_10ms_BSOF_UDchaMin_BSOF_UDchaMin() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_UDchaMin_BSOF_UDchaMin.value)

#define Rte_IRead_AC_10ms_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg.value)

#define Rte_IRead_BCC_10ms_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg.value)

#define Rte_IRead_DC_10ms_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg.value)

#define Rte_IRead_DC_10ms_BSOF_bEnaMsgChrgrChDetd_BSOF_bEnaMsgChrgrChDetd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrChDetd_BSOF_bEnaMsgChrgrChDetd.value)

#define Rte_IRead_DC_10ms_BSOF_bEnaMsgChrgrChSt_BSOF_bEnaMsgChrgrChSt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrChSt_BSOF_bEnaMsgChrgrChSt.value)

#define Rte_IRead_DC_10ms_BSOF_bEnaMsgChrgrChSuspd_BSOF_bEnaMsgChrgrChSuspd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrChSuspd_BSOF_bEnaMsgChrgrChSuspd.value)

#define Rte_IRead_DC_10ms_BSOF_bEnaMsgChrgrDetnCnct_BSOF_bEnaMsgChrgrDetnCnct() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrDetnCnct_BSOF_bEnaMsgChrgrDetnCnct.value)

#define Rte_IRead_DC_10ms_BSOF_bEnaMsgChrgrErr_BSOF_bEnaMsgChrgrErr() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrErr_BSOF_bEnaMsgChrgrErr.value)

#define Rte_IRead_DC_10ms_BSOF_bEnaMsgChrgrHdshk_BSOF_bEnaMsgChrgrHdshk() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrHdshk_BSOF_bEnaMsgChrgrHdshk.value)

#define Rte_IRead_DC_10ms_BSOF_bEnaMsgChrgrMaxOut_BSOF_bEnaMsgChrgrMaxOut() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrMaxOut_BSOF_bEnaMsgChrgrMaxOut.value)

#define Rte_IRead_DC_10ms_BSOF_bEnaMsgChrgrMaxOutPgtn_BSOF_bEnaMsgChrgrMaxOutPgtn() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrMaxOutPgtn_BSOF_bEnaMsgChrgrMaxOutPgtn.value)

#define Rte_IRead_DC_10ms_BSOF_bEnaMsgChrgrRcgtn_BSOF_bEnaMsgChrgrRcgtn() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrRcgtn_BSOF_bEnaMsgChrgrRcgtn.value)

#define Rte_IRead_DC_10ms_BSOF_bEnaMsgChrgrRdy_BSOF_bEnaMsgChrgrRdy() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrRdy_BSOF_bEnaMsgChrgrRdy.value)

#define Rte_IRead_DC_10ms_BSOF_bEnaMsgChrgrStstc_BSOF_bEnaMsgChrgrStstc() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrStstc_BSOF_bEnaMsgChrgrStstc.value)

#define Rte_IRead_DC_10ms_BSOF_bEnaMsgChrgrStstcForPgtn_BSOF_bEnaMsgChrgrStstcForPgtn() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bEnaMsgChrgrStstcForPgtn_BSOF_bEnaMsgChrgrStstcForPgtn.value)

#define Rte_IRead_DC_10ms_BSOF_bErrMsgTout_BSOF_bErrMsgTout() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSOF_bErrMsgTout_BSOF_bErrMsgTout.value)

#define Rte_IRead_AC_10ms_BSTC_StBcu_BSTC_StBcu() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BSTC_StBcu_BSTC_StBcu.value)

#define Rte_IRead_DC_10ms_BSTC_StBcu_BSTC_StBcu() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BSTC_StBcu_BSTC_StBcu.value)

#define Rte_IRead_AC_10ms_BTHM_ErrChEnd_BTHM_ErrChEnd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BTHM_ErrChEnd_BTHM_ErrChEnd.value)

#define Rte_IRead_DC_10ms_BTHM_ErrChEnd_BTHM_ErrChEnd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BTHM_ErrChEnd_BTHM_ErrChEnd.value)

#define Rte_IRead_AC_10ms_BTHM_StSys_BTHM_StSys() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BTHM_StSys_BTHM_StSys.value)

#define Rte_IRead_BCC_10ms_BTHM_StSys_BTHM_StSys() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BTHM_StSys_BTHM_StSys.value)

#define Rte_IRead_DC_10ms_BTHM_StSys_BTHM_StSys() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BTHM_StSys_BTHM_StSys.value)

#define Rte_IRead_BCC_10ms_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr.value)

#define Rte_IRead_BCC_10ms_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr.value)

#define Rte_IRead_AC_10ms_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value)

#define Rte_IRead_BCC_10ms_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value)

#define Rte_IRead_DC_10ms_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value)

#define Rte_IRead_AC_10ms_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value)

#define Rte_IRead_BCC_10ms_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value)

#define Rte_IRead_DC_10ms_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value)

#define Rte_IRead_BCC_10ms_BTHM_TPack_BTHM_TPack() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_BTHM_TPack_BTHM_TPack.value)

#define Rte_IRead_AC_10ms_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax.value)

#define Rte_IRead_DC_10ms_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax.value)

#define Rte_IRead_BCC_10ms_CIL_BatCoolType_CIL_BatCoolType() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_CIL_BatCoolType_CIL_BatCoolType.value)

#define Rte_IRead_AC_10ms_CIL_CP_Vol_CIL_CP_Vol() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_CP_Vol_CIL_CP_Vol.value)

#define Rte_IRead_DC_10ms_CIL_ChgCCSts_CIL_ChgCCSts() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_ChgCCSts_CIL_ChgCCSts.value)

#define Rte_IRead_AC_10ms_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt.value)

#define Rte_IRead_AC_10ms_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv.value)

#define Rte_IRead_AC_10ms_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass.value)

#define Rte_IRead_AC_10ms_CIL_DucycCtlPilot_CIL_DucycCtlPilot() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_DucycCtlPilot_CIL_DucycCtlPilot.value)

#define Rte_IRead_DC_10ms_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC.value)

#define Rte_IRead_AC_10ms_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT.value)

#define Rte_IRead_DC_10ms_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT.value)

#define Rte_IRead_AC_10ms_CIL_IBatHv_CIL_IBatHv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_IBatHv_CIL_IBatHv.value)

#define Rte_IRead_BCC_10ms_CIL_IBatHv_CIL_IBatHv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_CIL_IBatHv_CIL_IBatHv.value)

#define Rte_IRead_AC_10ms_CIL_IDcdcLvAct_CIL_IDcdcLvAct() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_IDcdcLvAct_CIL_IDcdcLvAct.value)

#define Rte_IRead_DC_10ms_CIL_IDcdcLvAct_CIL_IDcdcLvAct() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_IDcdcLvAct_CIL_IDcdcLvAct.value)

#define Rte_IRead_AC_10ms_CIL_OnBdCPline_CIL_OnBdCPline() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_OnBdCPline_CIL_OnBdCPline.value)

#define Rte_IRead_AC_10ms_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline.value)

#define Rte_IRead_AC_10ms_CIL_PwrEACAct_CIL_PwrEACAct() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_PwrEACAct_CIL_PwrEACAct.value)

#define Rte_IRead_DC_10ms_CIL_PwrEACAct_CIL_PwrEACAct() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_PwrEACAct_CIL_PwrEACAct.value)

#define Rte_IRead_AC_10ms_CIL_PwrPtcAct_CIL_PwrPtcAct() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_PwrPtcAct_CIL_PwrPtcAct.value)

#define Rte_IRead_DC_10ms_CIL_PwrPtcAct_CIL_PwrPtcAct() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_PwrPtcAct_CIL_PwrPtcAct.value)

#define Rte_IRead_AC_10ms_CIL_RAcChCnctn_CIL_RAcChCnctn() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_RAcChCnctn_CIL_RAcChCnctn.value)

#define Rte_IRead_AC_10ms_CIL_RDisChCnctn_CIL_RDisChCnctn() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_RDisChCnctn_CIL_RDisChCnctn.value)

#define Rte_IRead_AC_10ms_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts.value)

#define Rte_IRead_AC_10ms_CIL_StAcChCnct_CIL_StAcChCnct() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_StAcChCnct_CIL_StAcChCnct.value)

#define Rte_IRead_BCC_10ms_CIL_StAcChCnct_CIL_StAcChCnct() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_CIL_StAcChCnct_CIL_StAcChCnct.value)

#define Rte_IRead_DC_10ms_CIL_StAcChCnct_CIL_StAcChCnct() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_StAcChCnct_CIL_StAcChCnct.value)

#define Rte_IRead_AC_10ms_CIL_StBatHvReq_CIL_StBatHvReq() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_StBatHvReq_CIL_StBatHvReq.value)

#define Rte_IRead_DC_10ms_CIL_StBatHvReq_CIL_StBatHvReq() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_StBatHvReq_CIL_StBatHvReq.value)

#define Rte_IRead_AC_10ms_CIL_StChAllwd_CIL_StChAllwd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_StChAllwd_CIL_StChAllwd.value)

#define Rte_IRead_DC_10ms_CIL_StChAllwd_CIL_StChAllwd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_StChAllwd_CIL_StChAllwd.value)

#define Rte_IRead_AC_10ms_CIL_StChWup_CIL_StChWup() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_StChWup_CIL_StChWup.value)

#define Rte_IRead_BCC_10ms_CIL_StChWup_CIL_StChWup() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_CIL_StChWup_CIL_StChWup.value)

#define Rte_IRead_DC_10ms_CIL_StChWup_CIL_StChWup() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_StChWup_CIL_StChWup.value)

#define Rte_IRead_AC_10ms_CIL_StMsgToutForObc_CIL_StMsgToutForObc() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_StMsgToutForObc_CIL_StMsgToutForObc.value)

#define Rte_IRead_AC_10ms_CIL_StObc_CIL_StObc() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_StObc_CIL_StObc.value)

#define Rte_IRead_AC_10ms_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor.value)

#define Rte_IRead_AC_10ms_CIL_TAcChPointNeg_CIL_TAcChPointNeg() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_TAcChPointNeg_CIL_TAcChPointNeg.value)

#define Rte_IRead_AC_10ms_CIL_TAcChPointPos_CIL_TAcChPointPos() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_TAcChPointPos_CIL_TAcChPointPos.value)

#define Rte_IRead_DC_10ms_CIL_TDcChPointNeg_CIL_TDcChPointNeg() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg.value)

#define Rte_IRead_DC_10ms_CIL_TDcChPointPos_CIL_TDcChPointPos() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_TDcChPointPos_CIL_TDcChPointPos.value)

#define Rte_IRead_AC_10ms_CIL_UDcdcLvAct_CIL_UDcdcLvAct() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_UDcdcLvAct_CIL_UDcdcLvAct.value)

#define Rte_IRead_DC_10ms_CIL_UDcdcLvAct_CIL_UDcdcLvAct() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CIL_UDcdcLvAct_CIL_UDcdcLvAct.value)

#define Rte_IRead_AC_10ms_CIL_UObcChInp_CIL_UObcChInp() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CIL_UObcChInp_CIL_UObcChInp.value)

#define Rte_IRead_AC_10ms_CTC_StHvbat_CTC_StHvbat() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CTC_StHvbat_CTC_StHvbat.value)

#define Rte_IRead_BCC_10ms_CTC_StHvbat_CTC_StHvbat() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_CTC_StHvbat_CTC_StHvbat.value)

#define Rte_IRead_DC_10ms_CTC_StHvbat_CTC_StHvbat() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CTC_StHvbat_CTC_StHvbat.value)

#define Rte_IRead_AC_10ms_CTC_StLoopHv_CTC_StLoopHv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value)

#define Rte_IRead_DC_10ms_CTC_StLoopHv_CTC_StLoopHv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value)

#define Rte_IRead_DC_10ms_CTC_StRlyCh_CTC_StRlyCh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CTC_StRlyCh_CTC_StRlyCh.value)

#define Rte_IRead_DC_10ms_CTC_StSysInt_CTC_StSysInt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_CTC_StSysInt_CTC_StSysInt.value)

#define Rte_IRead_AC_10ms_DEH_EnaDiagGlb_DEH_EnaDiagGlb() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value)

#define Rte_IRead_DC_10ms_DEH_EnaDiagGlb_DEH_EnaDiagGlb() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value)

#define Rte_IRead_DC_10ms_DEH_ErrCfmd1_DEH_ErrCfmd1() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value)

#define Rte_IRead_AC_10ms_DEH_ErrCfmd3_DEH_ErrCfmd3() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value)

#define Rte_IRead_DC_10ms_DEH_ErrCfmd3_DEH_ErrCfmd3() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value)

#define Rte_IRead_DC_10ms_DEH_ErrCfmd4_DEH_ErrCfmd4() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_ErrCfmd4_DEH_ErrCfmd4.value)

#define Rte_IRead_AC_10ms_DEH_RstDiagGlb_DEH_RstDiagGlb() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value)

#define Rte_IRead_DC_10ms_DEH_RstDiagGlb_DEH_RstDiagGlb() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value)

#define Rte_IRead_AC_10ms_DEH_bAcvAcChInh_DEH_bAcvAcChInh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_bAcvAcChInh_DEH_bAcvAcChInh.value)

#define Rte_IRead_AC_10ms_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh.value)

#define Rte_IRead_AC_10ms_DEH_bAcvChInh_DEH_bAcvChInh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_bAcvChInh_DEH_bAcvChInh.value)

#define Rte_IRead_BCC_10ms_DEH_bAcvChInh_DEH_bAcvChInh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_DEH_bAcvChInh_DEH_bAcvChInh.value)

#define Rte_IRead_DC_10ms_DEH_bAcvChInh_DEH_bAcvChInh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_bAcvChInh_DEH_bAcvChInh.value)

#define Rte_IRead_BCC_10ms_DEH_bAcvDcChInh_DEH_bAcvDcChInh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_DEH_bAcvDcChInh_DEH_bAcvDcChInh.value)

#define Rte_IRead_DC_10ms_DEH_bAcvDcChInh_DEH_bAcvDcChInh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_bAcvDcChInh_DEH_bAcvDcChInh.value)

#define Rte_IRead_DC_10ms_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh.value)

#define Rte_IRead_AC_10ms_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1.value)

#define Rte_IRead_DC_10ms_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1.value)

#define Rte_IRead_AC_10ms_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_AC_10ms.Rte_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2.value)

#define Rte_IRead_DC_10ms_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2.value)

#define Rte_IRead_DC_10ms_ELHPN_StIsln_ELHPN_StIsln() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_ELHPN_StIsln_ELHPN_StIsln.value)

#define Rte_IWrite_DC_10ms_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_ChMode_EVCSH_ChMode(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ChMode_EVCSH_ChMode.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_ChMode_EVCSH_ChMode() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ChMode_EVCSH_ChMode.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_IChrgrSp_EVCSH_IChrgrSp(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_IChrgrSp_EVCSH_IChrgrSp.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_IChrgrSp_EVCSH_IChrgrSp() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_IChrgrSp_EVCSH_IChrgrSp.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_StBatRdy_EVCSH_StBatRdy(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_StBatRdy_EVCSH_StBatRdy.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_StBatRdy_EVCSH_StBatRdy() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_StBatRdy_EVCSH_StBatRdy.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_StBatRdy_EVCSH_StBatRdy(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_StBatRdy_EVCSH_StBatRdy.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_StBatRdy_EVCSH_StBatRdy() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_StBatRdy_EVCSH_StBatRdy.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_StDcCh_EVCSH_StDcCh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_StDcCh_EVCSH_StDcCh.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_StDcCh_EVCSH_StDcCh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_StDcCh_EVCSH_StDcCh.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_StInt_EVCSH_StInt(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_StInt_EVCSH_StInt.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_StInt_EVCSH_StInt() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_StInt_EVCSH_StInt.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_StInt_EVCSH_StInt(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_StInt_EVCSH_StInt.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_StInt_EVCSH_StInt() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_StInt_EVCSH_StInt.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_UChrgrSp_EVCSH_UChrgrSp(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_UChrgrSp_EVCSH_UChrgrSp.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_UChrgrSp_EVCSH_UChrgrSp() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_UChrgrSp_EVCSH_UChrgrSp.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bAcvVeh2VehDcha_EVCSH_bAcvVeh2VehDcha(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bAcvVeh2VehDcha_EVCSH_bAcvVeh2VehDcha.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bAcvVeh2VehDcha_EVCSH_bAcvVeh2VehDcha() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bAcvVeh2VehDcha_EVCSH_bAcvVeh2VehDcha.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc.value \
)

#define Rte_IWrite_BCC_Init_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT.value \
)

#define Rte_IWrite_DC_10ms_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU.value \
)

#define Rte_IRead_BCC_10ms_MCC_NrCellTot_MCC_NrCellTot() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_MCC_NrCellTot_MCC_NrCellTot.value)

#define Rte_IRead_BCC_10ms_MCC_NrMdulTot_MCC_NrMdulTot() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_BCC_10ms.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value)

#define Rte_IWrite_DC_10ms_TimeOut_CRO00_BCC_TimeOutCRO00(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_TimeOut_CRO00_BCC_TimeOutCRO00.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_TimeOut_CRO00_BCC_TimeOutCRO00() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_TimeOut_CRO00_BCC_TimeOutCRO00.value \
)

#define Rte_IWrite_BCC_Init_TimeOut_CRO00_BCC_TimeOutCRO00(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_TimeOut_CRO00_BCC_TimeOutCRO00.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_TimeOut_CRO00_BCC_TimeOutCRO00() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_TimeOut_CRO00_BCC_TimeOutCRO00.value \
)

#define Rte_IWrite_DC_10ms_TimeOut_CROAA_BCC_TimeOutCROAA(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_TimeOut_CROAA_BCC_TimeOutCROAA.value = (data) \
)

#define Rte_IWriteRef_DC_10ms_TimeOut_CROAA_BCC_TimeOutCROAA() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatChCtl_DC_10ms.Rte_TimeOut_CROAA_BCC_TimeOutCROAA.value \
)

#define Rte_IWrite_BCC_Init_TimeOut_CROAA_BCC_TimeOutCROAA(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_TimeOut_CROAA_BCC_TimeOutCROAA.value = (data) \
)

#define Rte_IWriteRef_BCC_Init_TimeOut_CROAA_BCC_TimeOutCROAA() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatChCtl_BCC_Init.Rte_TimeOut_CROAA_BCC_TimeOutCROAA.value \
)

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
#define Rte_Write_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq Rte_Write_swc_BatChCtl_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
************************************************************************************************************************
*/
#ifndef RTE_CORE
#define Rte_Call_RequestElectcContorCls_client_RequestElectcContorCls Rte_Call_swc_BatChCtl_RequestElectcContorCls_client_RequestElectcContorCls
#define Rte_Call_swc_BatChCtl_RequestElectcContorCls_client_RequestElectcContorCls(arg1) (RTE_E_UNCONNECTED)
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
FUNC(void, swc_BatChCtl_CODE) AC_10ms(void);
FUNC(void, swc_BatChCtl_CODE) BCC_10ms(void);
FUNC(void, swc_BatChCtl_CODE) BCC_Init(void);
FUNC(void, swc_BatChCtl_CODE) DC_10ms(void);
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
#endif /* RTE_SWC_BATCHCTL_H_ */
 
 
 

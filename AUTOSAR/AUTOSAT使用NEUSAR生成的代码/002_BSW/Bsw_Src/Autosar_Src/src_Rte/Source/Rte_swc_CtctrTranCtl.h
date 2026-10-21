 
/*
************************************************************************************************************************
*
* File name: Rte_swc_CtctrTranCtl.h
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
#ifndef RTE_SWC_CTCTRTRANCTL_H_
#define RTE_SWC_CTCTRTRANCTL_H_

#include "Rte_swc_CtctrTranCtl_Type.h"
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
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrInfo_CTC_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyCh_CTC_ErrRlyCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyHeat_CTC_ErrRlyHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyNeg_CTC_ErrRlyNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyPos_CTC_ErrRlyPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyPrech_CTC_ErrRlyPrech;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_IDriftZero_CTC_IDriftZero;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiCh_CTC_PctgCtctrAgiCh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiHeat_CTC_PctgCtctrAgiHeat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiNeg_CTC_PctgCtctrAgiNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiPos_CTC_PctgCtctrAgiPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiPrech_CTC_PctgCtctrAgiPrech;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyCh_CTC_ReqRlyCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyChNeg_CTC_ReqRlyChNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyHeat_CTC_ReqRlyHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyNeg_CTC_ReqRlyNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyPos_CTC_ReqRlyPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyPrech_CTC_ReqRlyPrech;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqZeroPwr_CTC_ReqZeroPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyCh_CTC_StRlyCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyChNeg_CTC_StRlyChNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyChkCh_CTC_StRlyChkCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyChkHeat_CTC_StRlyChkHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyChkPos_CTC_StRlyChkPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyHeat_CTC_StRlyHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyNeg_CTC_StRlyNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyPos_CTC_StRlyPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyPrech_CTC_StRlyPrech;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StSysInt_CTC_StSysInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvBswCtl_CTC_bAcvBswCtl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvCh_CTC_bAcvCh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiCh_CTC_bErrRlyAgiCh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiHeat_CTC_bErrRlyAgiHeat;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiNeg_CTC_bErrRlyAgiNeg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiPos_CTC_bErrRlyAgiPos;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiPrech_CTC_bErrRlyAgiPrech;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrToutForMotDcha_CTC_bErrToutForMotDcha;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiCh_CTC_bWarnRlyAgiCh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiHeat_CTC_bWarnRlyAgiHeat;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiNeg_CTC_bWarnRlyAgiNeg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiPos_CTC_bWarnRlyAgiPos;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiPrech_CTC_bWarnRlyAgiPrech;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_StAcSys_BCC_StAcSys;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_TiBatOff_BSTC_TiBatOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvObcOff_BSTC_bAcvObcOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_ReqRePrech_BTHM_ReqRePrech;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StRlyMain_BTHM_StRlyMain;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHvRaw_CIL_IBatHvRaw;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ModeMotDrv_CIL_ModeMotDrv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StBatHvReq_CIL_StBatHvReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StChWup_CIL_StChWup;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StTrml15_CIL_StTrml15;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UTrml30_CIL_UTrml30;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_ZeroPwrFb_CIL_ZeroPwrFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bKCNegClsSts_CIL_bKCNegClsSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bMainNegClsSts_CIL_bMainNegClsSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrRlyWlddErrRstDiag_DEH_CtrRlyWlddErrRstDiag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd2_DEH_ErrCfmd2;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd4_DEH_ErrCfmd4;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyCh_DEH_ReqRlyCh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyNeg_DEH_ReqRlyNeg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyPos_DEH_ReqRlyPos;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyPrech_DEH_ReqRlyPrech;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPowupInh_DEH_bAcvPowupInh;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StInt_EVCSH_StInt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UPrechAccumd_NVM_UPrechAccumd;
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
#define Rte_IRead_CTC_10ms_BCC_StAcSys_BCC_StAcSys() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BCC_StAcSys_BCC_StAcSys.value)

#define Rte_IRead_CTC_10ms_BCF_UBatTotInt_BCF_UBatTotInt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value)

#define Rte_IRead_CTC_10ms_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg.value)

#define Rte_IRead_CTC_10ms_BSTC_StBcu_BSTC_StBcu() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSTC_StBcu_BSTC_StBcu.value)

#define Rte_IRead_CTC_10ms_BSTC_TiBatOff_BSTC_TiBatOff() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSTC_TiBatOff_BSTC_TiBatOff.value)

#define Rte_IRead_CTC_10ms_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm.value)

#define Rte_IRead_CTC_10ms_BSTC_bAcvObcOff_BSTC_bAcvObcOff() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSTC_bAcvObcOff_BSTC_bAcvObcOff.value)

#define Rte_IRead_CTC_10ms_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm.value)

#define Rte_IRead_CTC_10ms_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy.value)

#define Rte_IRead_CTC_10ms_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun.value)

#define Rte_IRead_CTC_10ms_BTHM_ReqRePrech_BTHM_ReqRePrech() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BTHM_ReqRePrech_BTHM_ReqRePrech.value)

#define Rte_IRead_CTC_10ms_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq.value)

#define Rte_IRead_CTC_10ms_BTHM_StRlyMain_BTHM_StRlyMain() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_BTHM_StRlyMain_BTHM_StRlyMain.value)

#define Rte_IRead_CTC_10ms_CIL_IBatHv_CIL_IBatHv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_IBatHv_CIL_IBatHv.value)

#define Rte_IRead_CTC_10ms_CIL_IBatHvRaw_CIL_IBatHvRaw() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_IBatHvRaw_CIL_IBatHvRaw.value)

#define Rte_IRead_CTC_10ms_CIL_ModeMotDrv_CIL_ModeMotDrv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_ModeMotDrv_CIL_ModeMotDrv.value)

#define Rte_IRead_CTC_10ms_CIL_StBatHvReq_CIL_StBatHvReq() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_StBatHvReq_CIL_StBatHvReq.value)

#define Rte_IRead_CTC_10ms_CIL_StChWup_CIL_StChWup() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_StChWup_CIL_StChWup.value)

#define Rte_IRead_CTC_10ms_CIL_StTrml15_CIL_StTrml15() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_StTrml15_CIL_StTrml15.value)

#define Rte_IRead_CTC_10ms_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv.value)

#define Rte_IRead_CTC_10ms_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv.value)

#define Rte_IRead_CTC_10ms_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv.value)

#define Rte_IRead_CTC_10ms_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv.value)

#define Rte_IRead_CTC_10ms_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv.value)

#define Rte_IRead_CTC_10ms_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly.value)

#define Rte_IRead_CTC_10ms_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value)

#define Rte_IRead_CTC_10ms_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv.value)

#define Rte_IRead_CTC_10ms_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv.value)

#define Rte_IRead_CTC_10ms_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv.value)

#define Rte_IRead_CTC_10ms_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv.value)

#define Rte_IRead_CTC_10ms_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh.value)

#define Rte_IRead_CTC_10ms_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg.value)

#define Rte_IRead_CTC_10ms_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat.value)

#define Rte_IRead_CTC_10ms_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv.value)

#define Rte_IRead_CTC_10ms_CIL_UTrml30_CIL_UTrml30() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_UTrml30_CIL_UTrml30.value)

#define Rte_IRead_CTC_10ms_CIL_ZeroPwrFb_CIL_ZeroPwrFb() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_ZeroPwrFb_CIL_ZeroPwrFb.value)

#define Rte_IRead_CTC_10ms_CIL_bKCNegClsSts_CIL_bKCNegClsSts() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_bKCNegClsSts_CIL_bKCNegClsSts.value)

#define Rte_IRead_CTC_10ms_CIL_bMainNegClsSts_CIL_bMainNegClsSts() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CIL_bMainNegClsSts_CIL_bMainNegClsSts.value)

#define Rte_IWrite_CTC_10ms_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv.value \
)

#define Rte_IWrite_CTC_Init_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv.value = (data) \
)

#define Rte_IWriteRef_CTC_Init_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv.value \
)

#define Rte_IWrite_CTC_10ms_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv.value \
)

#define Rte_IWrite_CTC_Init_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv.value = (data) \
)

#define Rte_IWriteRef_CTC_Init_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv.value \
)

#define Rte_IWrite_CTC_10ms_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv.value \
)

#define Rte_IWrite_CTC_Init_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv.value = (data) \
)

#define Rte_IWriteRef_CTC_Init_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv.value \
)

#define Rte_IWrite_CTC_10ms_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv.value \
)

#define Rte_IWrite_CTC_Init_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv.value = (data) \
)

#define Rte_IWriteRef_CTC_Init_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv.value \
)

#define Rte_IWrite_CTC_10ms_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv.value \
)

#define Rte_IWrite_CTC_Init_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv.value = (data) \
)

#define Rte_IWriteRef_CTC_Init_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv.value \
)

#define Rte_IWrite_CTC_10ms_CTC_ErrInfo_CTC_ErrInfo(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrInfo_CTC_ErrInfo.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_ErrInfo_CTC_ErrInfo() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrInfo_CTC_ErrInfo.value \
)

#define Rte_IWrite_CTC_10ms_CTC_ErrRlyCh_CTC_ErrRlyCh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrRlyCh_CTC_ErrRlyCh.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_ErrRlyCh_CTC_ErrRlyCh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrRlyCh_CTC_ErrRlyCh.value \
)

#define Rte_IWrite_CTC_10ms_CTC_ErrRlyHeat_CTC_ErrRlyHeat(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrRlyHeat_CTC_ErrRlyHeat.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_ErrRlyHeat_CTC_ErrRlyHeat() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrRlyHeat_CTC_ErrRlyHeat.value \
)

#define Rte_IWrite_CTC_10ms_CTC_ErrRlyNeg_CTC_ErrRlyNeg(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrRlyNeg_CTC_ErrRlyNeg.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_ErrRlyNeg_CTC_ErrRlyNeg() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrRlyNeg_CTC_ErrRlyNeg.value \
)

#define Rte_IWrite_CTC_10ms_CTC_ErrRlyPos_CTC_ErrRlyPos(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrRlyPos_CTC_ErrRlyPos.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_ErrRlyPos_CTC_ErrRlyPos() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrRlyPos_CTC_ErrRlyPos.value \
)

#define Rte_IWrite_CTC_10ms_CTC_ErrRlyPrech_CTC_ErrRlyPrech(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrRlyPrech_CTC_ErrRlyPrech.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_ErrRlyPrech_CTC_ErrRlyPrech() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ErrRlyPrech_CTC_ErrRlyPrech.value \
)

#define Rte_IWrite_CTC_10ms_CTC_IDriftZero_CTC_IDriftZero(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_IDriftZero_CTC_IDriftZero.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_IDriftZero_CTC_IDriftZero() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_IDriftZero_CTC_IDriftZero.value \
)

#define Rte_IWrite_CTC_Init_CTC_IDriftZero_CTC_IDriftZero(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_IDriftZero_CTC_IDriftZero.value = (data) \
)

#define Rte_IWriteRef_CTC_Init_CTC_IDriftZero_CTC_IDriftZero() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_CtctrTranCtl_CTC_Init.Rte_CTC_IDriftZero_CTC_IDriftZero.value \
)

#define Rte_IWrite_CTC_10ms_CTC_PctgCtctrAgiCh_CTC_PctgCtctrAgiCh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_PctgCtctrAgiCh_CTC_PctgCtctrAgiCh.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_PctgCtctrAgiCh_CTC_PctgCtctrAgiCh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_PctgCtctrAgiCh_CTC_PctgCtctrAgiCh.value \
)

#define Rte_IWrite_CTC_10ms_CTC_PctgCtctrAgiHeat_CTC_PctgCtctrAgiHeat(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_PctgCtctrAgiHeat_CTC_PctgCtctrAgiHeat.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_PctgCtctrAgiHeat_CTC_PctgCtctrAgiHeat() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_PctgCtctrAgiHeat_CTC_PctgCtctrAgiHeat.value \
)

#define Rte_IWrite_CTC_10ms_CTC_PctgCtctrAgiNeg_CTC_PctgCtctrAgiNeg(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_PctgCtctrAgiNeg_CTC_PctgCtctrAgiNeg.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_PctgCtctrAgiNeg_CTC_PctgCtctrAgiNeg() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_PctgCtctrAgiNeg_CTC_PctgCtctrAgiNeg.value \
)

#define Rte_IWrite_CTC_10ms_CTC_PctgCtctrAgiPos_CTC_PctgCtctrAgiPos(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_PctgCtctrAgiPos_CTC_PctgCtctrAgiPos.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_PctgCtctrAgiPos_CTC_PctgCtctrAgiPos() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_PctgCtctrAgiPos_CTC_PctgCtctrAgiPos.value \
)

#define Rte_IWrite_CTC_10ms_CTC_PctgCtctrAgiPrech_CTC_PctgCtctrAgiPrech(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_PctgCtctrAgiPrech_CTC_PctgCtctrAgiPrech.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_PctgCtctrAgiPrech_CTC_PctgCtctrAgiPrech() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_PctgCtctrAgiPrech_CTC_PctgCtctrAgiPrech.value \
)

#define Rte_IWrite_CTC_10ms_CTC_ReqRlyCh_CTC_ReqRlyCh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyCh_CTC_ReqRlyCh.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_ReqRlyCh_CTC_ReqRlyCh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyCh_CTC_ReqRlyCh.value \
)

#define Rte_IWrite_CTC_10ms_CTC_ReqRlyChNeg_CTC_ReqRlyChNeg(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyChNeg_CTC_ReqRlyChNeg.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_ReqRlyChNeg_CTC_ReqRlyChNeg() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyChNeg_CTC_ReqRlyChNeg.value \
)

#define Rte_IWrite_CTC_10ms_CTC_ReqRlyHeat_CTC_ReqRlyHeat(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyHeat_CTC_ReqRlyHeat.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_ReqRlyHeat_CTC_ReqRlyHeat() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyHeat_CTC_ReqRlyHeat.value \
)

#define Rte_IWrite_CTC_10ms_CTC_ReqRlyNeg_CTC_ReqRlyNeg(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyNeg_CTC_ReqRlyNeg.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_ReqRlyNeg_CTC_ReqRlyNeg() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyNeg_CTC_ReqRlyNeg.value \
)

#define Rte_IWrite_CTC_10ms_CTC_ReqRlyPos_CTC_ReqRlyPos(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyPos_CTC_ReqRlyPos.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_ReqRlyPos_CTC_ReqRlyPos() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyPos_CTC_ReqRlyPos.value \
)

#define Rte_IWrite_CTC_10ms_CTC_ReqRlyPrech_CTC_ReqRlyPrech(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyPrech_CTC_ReqRlyPrech.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_ReqRlyPrech_CTC_ReqRlyPrech() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqRlyPrech_CTC_ReqRlyPrech.value \
)

#define Rte_IWrite_CTC_10ms_CTC_ReqZeroPwr_CTC_ReqZeroPwr(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqZeroPwr_CTC_ReqZeroPwr.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_ReqZeroPwr_CTC_ReqZeroPwr() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_ReqZeroPwr_CTC_ReqZeroPwr.value \
)

#define Rte_IWrite_CTC_10ms_CTC_StHvbat_CTC_StHvbat(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StHvbat_CTC_StHvbat.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_StHvbat_CTC_StHvbat() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StHvbat_CTC_StHvbat.value \
)

#define Rte_IWrite_CTC_10ms_CTC_StLoopHv_CTC_StLoopHv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_StLoopHv_CTC_StLoopHv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value \
)

#define Rte_IWrite_CTC_10ms_CTC_StRlyCh_CTC_StRlyCh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyCh_CTC_StRlyCh.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_StRlyCh_CTC_StRlyCh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyCh_CTC_StRlyCh.value \
)

#define Rte_IWrite_CTC_10ms_CTC_StRlyChNeg_CTC_StRlyChNeg(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyChNeg_CTC_StRlyChNeg.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_StRlyChNeg_CTC_StRlyChNeg() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyChNeg_CTC_StRlyChNeg.value \
)

#define Rte_IWrite_CTC_10ms_CTC_StRlyChkCh_CTC_StRlyChkCh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyChkCh_CTC_StRlyChkCh.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_StRlyChkCh_CTC_StRlyChkCh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyChkCh_CTC_StRlyChkCh.value \
)

#define Rte_IWrite_CTC_10ms_CTC_StRlyChkHeat_CTC_StRlyChkHeat(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyChkHeat_CTC_StRlyChkHeat.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_StRlyChkHeat_CTC_StRlyChkHeat() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyChkHeat_CTC_StRlyChkHeat.value \
)

#define Rte_IWrite_CTC_10ms_CTC_StRlyChkPos_CTC_StRlyChkPos(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyChkPos_CTC_StRlyChkPos.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_StRlyChkPos_CTC_StRlyChkPos() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyChkPos_CTC_StRlyChkPos.value \
)

#define Rte_IWrite_CTC_10ms_CTC_StRlyHeat_CTC_StRlyHeat(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyHeat_CTC_StRlyHeat.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_StRlyHeat_CTC_StRlyHeat() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyHeat_CTC_StRlyHeat.value \
)

#define Rte_IWrite_CTC_10ms_CTC_StRlyNeg_CTC_StRlyNeg(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyNeg_CTC_StRlyNeg.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_StRlyNeg_CTC_StRlyNeg() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyNeg_CTC_StRlyNeg.value \
)

#define Rte_IWrite_CTC_10ms_CTC_StRlyPos_CTC_StRlyPos(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyPos_CTC_StRlyPos.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_StRlyPos_CTC_StRlyPos() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyPos_CTC_StRlyPos.value \
)

#define Rte_IWrite_CTC_10ms_CTC_StRlyPrech_CTC_StRlyPrech(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyPrech_CTC_StRlyPrech.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_StRlyPrech_CTC_StRlyPrech() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StRlyPrech_CTC_StRlyPrech.value \
)

#define Rte_IWrite_CTC_10ms_CTC_StSysInt_CTC_StSysInt(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StSysInt_CTC_StSysInt.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_StSysInt_CTC_StSysInt() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_StSysInt_CTC_StSysInt.value \
)

#define Rte_IWrite_CTC_10ms_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv.value \
)

#define Rte_IWrite_CTC_10ms_CTC_bAcvBswCtl_CTC_bAcvBswCtl(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bAcvBswCtl_CTC_bAcvBswCtl.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_bAcvBswCtl_CTC_bAcvBswCtl() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bAcvBswCtl_CTC_bAcvBswCtl.value \
)

#define Rte_IWrite_CTC_10ms_CTC_bAcvCh_CTC_bAcvCh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bAcvCh_CTC_bAcvCh.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_bAcvCh_CTC_bAcvCh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bAcvCh_CTC_bAcvCh.value \
)

#define Rte_IWrite_CTC_10ms_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd.value \
)

#define Rte_IWrite_CTC_10ms_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk.value \
)

#define Rte_IWrite_CTC_10ms_CTC_bErrRlyAgiCh_CTC_bErrRlyAgiCh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrRlyAgiCh_CTC_bErrRlyAgiCh.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_bErrRlyAgiCh_CTC_bErrRlyAgiCh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrRlyAgiCh_CTC_bErrRlyAgiCh.value \
)

#define Rte_IWrite_CTC_10ms_CTC_bErrRlyAgiHeat_CTC_bErrRlyAgiHeat(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrRlyAgiHeat_CTC_bErrRlyAgiHeat.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_bErrRlyAgiHeat_CTC_bErrRlyAgiHeat() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrRlyAgiHeat_CTC_bErrRlyAgiHeat.value \
)

#define Rte_IWrite_CTC_10ms_CTC_bErrRlyAgiNeg_CTC_bErrRlyAgiNeg(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrRlyAgiNeg_CTC_bErrRlyAgiNeg.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_bErrRlyAgiNeg_CTC_bErrRlyAgiNeg() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrRlyAgiNeg_CTC_bErrRlyAgiNeg.value \
)

#define Rte_IWrite_CTC_10ms_CTC_bErrRlyAgiPos_CTC_bErrRlyAgiPos(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrRlyAgiPos_CTC_bErrRlyAgiPos.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_bErrRlyAgiPos_CTC_bErrRlyAgiPos() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrRlyAgiPos_CTC_bErrRlyAgiPos.value \
)

#define Rte_IWrite_CTC_10ms_CTC_bErrRlyAgiPrech_CTC_bErrRlyAgiPrech(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrRlyAgiPrech_CTC_bErrRlyAgiPrech.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_bErrRlyAgiPrech_CTC_bErrRlyAgiPrech() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrRlyAgiPrech_CTC_bErrRlyAgiPrech.value \
)

#define Rte_IWrite_CTC_10ms_CTC_bErrToutForMotDcha_CTC_bErrToutForMotDcha(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrToutForMotDcha_CTC_bErrToutForMotDcha.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_bErrToutForMotDcha_CTC_bErrToutForMotDcha() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bErrToutForMotDcha_CTC_bErrToutForMotDcha.value \
)

#define Rte_IWrite_CTC_10ms_CTC_bWarnRlyAgiCh_CTC_bWarnRlyAgiCh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bWarnRlyAgiCh_CTC_bWarnRlyAgiCh.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_bWarnRlyAgiCh_CTC_bWarnRlyAgiCh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bWarnRlyAgiCh_CTC_bWarnRlyAgiCh.value \
)

#define Rte_IWrite_CTC_10ms_CTC_bWarnRlyAgiHeat_CTC_bWarnRlyAgiHeat(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bWarnRlyAgiHeat_CTC_bWarnRlyAgiHeat.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_bWarnRlyAgiHeat_CTC_bWarnRlyAgiHeat() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bWarnRlyAgiHeat_CTC_bWarnRlyAgiHeat.value \
)

#define Rte_IWrite_CTC_10ms_CTC_bWarnRlyAgiNeg_CTC_bWarnRlyAgiNeg(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bWarnRlyAgiNeg_CTC_bWarnRlyAgiNeg.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_bWarnRlyAgiNeg_CTC_bWarnRlyAgiNeg() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bWarnRlyAgiNeg_CTC_bWarnRlyAgiNeg.value \
)

#define Rte_IWrite_CTC_10ms_CTC_bWarnRlyAgiPos_CTC_bWarnRlyAgiPos(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bWarnRlyAgiPos_CTC_bWarnRlyAgiPos.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_bWarnRlyAgiPos_CTC_bWarnRlyAgiPos() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bWarnRlyAgiPos_CTC_bWarnRlyAgiPos.value \
)

#define Rte_IWrite_CTC_10ms_CTC_bWarnRlyAgiPrech_CTC_bWarnRlyAgiPrech(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bWarnRlyAgiPrech_CTC_bWarnRlyAgiPrech.value = (data) \
)

#define Rte_IWriteRef_CTC_10ms_CTC_bWarnRlyAgiPrech_CTC_bWarnRlyAgiPrech() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_CTC_bWarnRlyAgiPrech_CTC_bWarnRlyAgiPrech.value \
)

#define Rte_IRead_CTC_10ms_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag.value)

#define Rte_IRead_CTC_10ms_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag.value)

#define Rte_IRead_CTC_10ms_DEH_CtrRlyWlddErrRstDiag_DEH_CtrRlyWlddErrRstDiag() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_CtrRlyWlddErrRstDiag_DEH_CtrRlyWlddErrRstDiag.value)

#define Rte_IRead_CTC_10ms_DEH_EnaDiagGlb_DEH_EnaDiagGlb() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value)

#define Rte_IRead_CTC_10ms_DEH_ErrCfmd1_DEH_ErrCfmd1() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value)

#define Rte_IRead_CTC_10ms_DEH_ErrCfmd2_DEH_ErrCfmd2() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ErrCfmd2_DEH_ErrCfmd2.value)

#define Rte_IRead_CTC_10ms_DEH_ErrCfmd4_DEH_ErrCfmd4() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ErrCfmd4_DEH_ErrCfmd4.value)

#define Rte_IRead_CTC_10ms_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag.value)

#define Rte_IRead_CTC_10ms_DEH_ReqRlyCh_DEH_ReqRlyCh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ReqRlyCh_DEH_ReqRlyCh.value)

#define Rte_IRead_CTC_10ms_DEH_ReqRlyHeat_DEH_ReqRlyHeat() \
  (FALSE)

#define Rte_IRead_CTC_10ms_DEH_ReqRlyNeg_DEH_ReqRlyNeg() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ReqRlyNeg_DEH_ReqRlyNeg.value)

#define Rte_IRead_CTC_10ms_DEH_ReqRlyPos_DEH_ReqRlyPos() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ReqRlyPos_DEH_ReqRlyPos.value)

#define Rte_IRead_CTC_10ms_DEH_ReqRlyPrech_DEH_ReqRlyPrech() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_ReqRlyPrech_DEH_ReqRlyPrech.value)

#define Rte_IRead_CTC_10ms_DEH_RstDiagGlb_DEH_RstDiagGlb() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value)

#define Rte_IRead_CTC_10ms_DEH_bAcvPowupInh_DEH_bAcvPowupInh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_DEH_bAcvPowupInh_DEH_bAcvPowupInh.value)

#define Rte_IRead_CTC_10ms_EVCSH_StInt_EVCSH_StInt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_EVCSH_StInt_EVCSH_StInt.value)

#define Rte_IRead_CTC_10ms_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq.value)

#define Rte_IRead_CTC_10ms_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh.value)

#define Rte_IRead_CTC_10ms_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat.value)

#define Rte_IRead_CTC_10ms_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg.value)

#define Rte_IRead_CTC_10ms_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos.value)

#define Rte_IRead_CTC_10ms_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech.value)

#define Rte_IRead_CTC_10ms_NVM_UPrechAccumd_NVM_UPrechAccumd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_CtctrTranCtl_CTC_10ms.Rte_NVM_UPrechAccumd_NVM_UPrechAccumd.value)

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
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, swc_SetOutputInterface_CODE) If_DiscreteValueOutput_SetDiscreteValue(VAR(UInt32, RTE_swc_SetOutputInterface_APPL_DATA) NumId, VAR(UInt32, RTE_swc_SetOutputInterface_APPL_DATA) value);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifndef RTE_CORE
#define Rte_Call_If_DiscreteValueOutput_SetDiscreteValue Rte_Call_swc_CtctrTranCtl_If_DiscreteValueOutput_SetDiscreteValue
#define Rte_Call_swc_CtctrTranCtl_If_DiscreteValueOutput_SetDiscreteValue(arg1, arg2) (If_DiscreteValueOutput_SetDiscreteValue(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
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
FUNC(void, swc_CtctrTranCtl_CODE) CTC_10ms(void);
FUNC(void, swc_CtctrTranCtl_CODE) CTC_Init(void);
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
#endif /* RTE_SWC_CTCTRTRANCTL_H_ */
 
 
 

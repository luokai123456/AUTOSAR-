 
/*
************************************************************************************************************************
*
* File name: Rte_swc_BatCoreFct.h
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
#ifndef RTE_SWC_BATCOREFCT_H_
#define RTE_SWC_BATCOREFCT_H_

#include "Rte_swc_BatCoreFct_Type.h"
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
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_CMdulAbsv_BCF_CMdulAbsv;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ChIIntglNv_BCF_ChIIntglNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_DeltAhNv_BCF_DeltAhNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_EPackRmng_BCF_EPackRmng;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_EnaPack_BCF_EnaPack;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo_BCF_ErrInfo;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo1_BCF_ErrInfo1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo2_BCF_ErrInfo2;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo3_BCF_ErrInfo3;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo4_BCF_ErrInfo4;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo5_BCF_ErrInfo5;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo6_BCF_ErrInfo6;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_FullChgSOHNv_BCF_FullChgSOHNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLim_BCF_IChLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLimInt_BCF_IChLimInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLimMap_BCF_IChLimMap;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChMax_BCF_IChMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChPredLim_BCF_IChPredLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChPredLimInt_BCF_IChPredLimInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaLim_BCF_IDchaLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaLimInt_BCF_IDchaLimInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaLimMap_BCF_IDchaLimMap;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaMax_BCF_IDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaPredLim_BCF_IDchaPredLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IIntglNv_BCF_IIntglNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_NrMdulMax_BCF_NrMdulMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_PwrChLim_BCF_PwrChLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_PwrChPredLim_BCF_PwrChPredLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_PwrDchaLim_BCF_PwrDchaLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_PwrDchaPredLim_BCF_PwrDchaPredLim;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_PwrMdulLoss_BCF_PwrMdulLoss;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_RPackInt_BCF_RPackInt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv;
extern VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCell_BCF_SocCell;
extern VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCellDelta_BCF_SocCellDelta;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCellMax_BCF_SocCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCellMin_BCF_SocCellMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCnsActNv_BCF_SocCnsActNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocLimMax_BCF_SocLimMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocLimMin_BCF_SocLimMin;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocMdul_BCF_SocMdul;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocUOcIniNv_BCF_SocUOcIniNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohCalNv_BCF_SohCalNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohCycNv_BCF_SohCycNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohPack_BCF_SohPack;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohPackNv_BCF_SohPackNv;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv;
extern VAR(rt_Array_Float_144, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_StAryFlsNv_BCF_StAryFlsNv;
extern VAR(rt_Array_UInt8_4, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_StLimnId_BCF_StLimnId;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TCooltMdulOut_BCF_TCooltMdulOut;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TMdulEstimd_BCF_TMdulEstimd;
extern VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv;
extern VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiBatOffNv_BCF_TiBatOffNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiChFullOff_BCF_TiChFullOff;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UCellAvg_BCF_UCellAvg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UChLim_BCF_UChLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UChLimInt_BCF_UChLimInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UChPredLim_BCF_UChPredLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UChPredLimInt_BCF_UChPredLimInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UDchaLim_BCF_UDchaLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UDchaLimInt_BCF_UDchaLimInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UDchaPredLim_BCF_UDchaPredLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UMdul_BCF_UMdul;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UPackCircOpen_BCF_UPackCircOpen;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv;
extern VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_ICellBaln_BBC_ICellBaln;
extern VAR(rt_Array_Boolean_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull;
extern VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_CIL_BMC_UCell_BMC_UCell;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_bAcvCTest_BPP_bAcvCTest;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_RstCmd100_BSTC_RstCmd100;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_TiBatOff_BSTC_TiBatOff;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_MfCoolt_BTHM_MfCoolt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StSys_BTHM_StSys;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr;
extern VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulCorrn_BTHM_TMdulCorrn;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TPack_BTHM_TPack;
extern VAR(rt_Array_Boolean_24, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_bAcvTAbno_BTHM_bAcvTAbno;
extern VAR(rt_Array_Boolean_24, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_bErrSnsrT_BTHM_bErrSnsrT;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_SecRtc_CIL_SecRtc;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrPackSocSetDiag_DEH_CtrPackSocSetDiag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd2_DEH_ErrCfmd2;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd6_DEH_ErrCfmd6;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrHisCfmd_DEH_ErrHisCfmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StSocCal_DEH_StSocCal;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StsIninNv_DEH_StsIninNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_TiChFullOff_DEH_TiChFullOff;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ValPackSoc_DEH_ValPackSoc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvBdNew_DEH_bAcvBdNew;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvDchaInh_DEH_bAcvDchaInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvRecupInh_DEH_bAcvRecupInh;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCellByMdul_MCC_NrCellByMdul;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_ChIIntglFls_NVM_ChIIntglFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_ChgDeltAh_NVM_ChgDeltAh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_DeltAh_NVM_DeltAh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_EBatChTot_NVM_EBatChTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_FullChgSOH_NVM_FullChgSOH;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_IIntglFls_NVM_IIntglFls;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocCnsAct_NVM_SocCnsAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocPackScld_NVM_SocPackScld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocUOcIni_NVM_SocUOcIni;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohCalFls_NVM_SohCalFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohCycFls_NVM_SohCycFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohPackFls_NVM_SohPackFls;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohRDeltaFls_NVM_SohRDeltaFls;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls;
extern VAR(rt_Array_Float_144, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_StAryFls_NVM_StAryFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TPackFls_NVM_TPackFls;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatOffFls_NVM_TiBatOffFls;
extern VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls;
extern VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_App1_Task_100ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_100ms_Core2_QM;
extern VAR(Rte_ts_SWC_Init_Task_Core2, RTE_VAR_NOINIT) Rte_SWC_Init_Task_Core2;
extern VAR(Rte_ts_App1_Task_10ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_10ms_Core2_QM;
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
#define Rte_IRead_BCF_100ms_BBC_ICellBaln_BBC_ICellBaln() \
  (&((*RteIRead_BCF_100ms_BBC_ICellBaln_BBC_ICellBaln())[0]))

#define RteIRead_BCF_100ms_BBC_ICellBaln_BBC_ICellBaln() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BBC_ICellBaln_BBC_ICellBaln.value)

#define Rte_IRead_BCF_100ms_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln() \
  (&((*RteIRead_BCF_100ms_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln())[0]))

#define RteIRead_BCF_100ms_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln.value)

#define Rte_IRead_BCF_100ms_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull.value)

#define Rte_IWrite_BCF_100ms_BCF_CMdulAbsv_BCF_CMdulAbsv(data) \
  RteIWrite_BCF_100ms_BCF_CMdulAbsv_BCF_CMdulAbsv(data)

#define RteIWrite_BCF_100ms_BCF_CMdulAbsv_BCF_CMdulAbsv(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_CMdulAbsv_BCF_CMdulAbsv.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_CMdulAbsv_BCF_CMdulAbsv() \
  (&((*RteIWriteRef_BCF_100ms_BCF_CMdulAbsv_BCF_CMdulAbsv())[0]))

#define RteIWriteRef_BCF_100ms_BCF_CMdulAbsv_BCF_CMdulAbsv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_CMdulAbsv_BCF_CMdulAbsv.value \
)

#define Rte_IWrite_BCF_Init_BCF_CMdulAbsv_BCF_CMdulAbsv(data) \
  RteIWrite_BCF_Init_BCF_CMdulAbsv_BCF_CMdulAbsv(data)

#define RteIWrite_BCF_Init_BCF_CMdulAbsv_BCF_CMdulAbsv(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_CMdulAbsv_BCF_CMdulAbsv.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_Init_BCF_CMdulAbsv_BCF_CMdulAbsv() \
  (&((*RteIWriteRef_BCF_Init_BCF_CMdulAbsv_BCF_CMdulAbsv())[0]))

#define RteIWriteRef_BCF_Init_BCF_CMdulAbsv_BCF_CMdulAbsv() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_CMdulAbsv_BCF_CMdulAbsv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv(data) \
  RteIWrite_BCF_100ms_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv(data)

#define RteIWrite_BCF_100ms_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv() \
  (&((*RteIWriteRef_BCF_100ms_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv())[0]))

#define RteIWriteRef_BCF_100ms_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_ChIIntglNv_BCF_ChIIntglNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ChIIntglNv_BCF_ChIIntglNv.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_ChIIntglNv_BCF_ChIIntglNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ChIIntglNv_BCF_ChIIntglNv.value \
)

#define Rte_IWrite_BCF_Init_BCF_ChIIntglNv_BCF_ChIIntglNv(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ChIIntglNv_BCF_ChIIntglNv.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_ChIIntglNv_BCF_ChIIntglNv() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ChIIntglNv_BCF_ChIIntglNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_DeltAhNv_BCF_DeltAhNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_DeltAhNv_BCF_DeltAhNv.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_DeltAhNv_BCF_DeltAhNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_DeltAhNv_BCF_DeltAhNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_EPackRmng_BCF_EPackRmng(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_EPackRmng_BCF_EPackRmng.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_EPackRmng_BCF_EPackRmng() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_EPackRmng_BCF_EPackRmng.value \
)

#define Rte_IWrite_BCF_Init_BCF_EPackRmng_BCF_EPackRmng(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_EPackRmng_BCF_EPackRmng.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_EPackRmng_BCF_EPackRmng() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_EPackRmng_BCF_EPackRmng.value \
)

#define Rte_IWrite_BCF_100ms_BCF_EnaPack_BCF_EnaPack(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_EnaPack_BCF_EnaPack.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_EnaPack_BCF_EnaPack() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_EnaPack_BCF_EnaPack.value \
)

#define Rte_IWrite_BCF_100ms_BCF_ErrInfo_BCF_ErrInfo(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo_BCF_ErrInfo.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_ErrInfo_BCF_ErrInfo() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo_BCF_ErrInfo.value \
)

#define Rte_IWrite_BCF_Init_BCF_ErrInfo_BCF_ErrInfo(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo_BCF_ErrInfo.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_ErrInfo_BCF_ErrInfo() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo_BCF_ErrInfo.value \
)

#define Rte_IWrite_BCF_100ms_BCF_ErrInfo1_BCF_ErrInfo1(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo1_BCF_ErrInfo1.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_ErrInfo1_BCF_ErrInfo1() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo1_BCF_ErrInfo1.value \
)

#define Rte_IWrite_BCF_Init_BCF_ErrInfo1_BCF_ErrInfo1(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo1_BCF_ErrInfo1.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_ErrInfo1_BCF_ErrInfo1() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo1_BCF_ErrInfo1.value \
)

#define Rte_IWrite_BCF_100ms_BCF_ErrInfo2_BCF_ErrInfo2(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo2_BCF_ErrInfo2.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_ErrInfo2_BCF_ErrInfo2() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo2_BCF_ErrInfo2.value \
)

#define Rte_IWrite_BCF_Init_BCF_ErrInfo2_BCF_ErrInfo2(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo2_BCF_ErrInfo2.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_ErrInfo2_BCF_ErrInfo2() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo2_BCF_ErrInfo2.value \
)

#define Rte_IWrite_BCF_100ms_BCF_ErrInfo3_BCF_ErrInfo3(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo3_BCF_ErrInfo3.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_ErrInfo3_BCF_ErrInfo3() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo3_BCF_ErrInfo3.value \
)

#define Rte_IWrite_BCF_Init_BCF_ErrInfo3_BCF_ErrInfo3(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo3_BCF_ErrInfo3.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_ErrInfo3_BCF_ErrInfo3() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo3_BCF_ErrInfo3.value \
)

#define Rte_IWrite_BCF_100ms_BCF_ErrInfo4_BCF_ErrInfo4(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo4_BCF_ErrInfo4.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_ErrInfo4_BCF_ErrInfo4() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo4_BCF_ErrInfo4.value \
)

#define Rte_IWrite_BCF_Init_BCF_ErrInfo4_BCF_ErrInfo4(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo4_BCF_ErrInfo4.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_ErrInfo4_BCF_ErrInfo4() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo4_BCF_ErrInfo4.value \
)

#define Rte_IWrite_BCF_100ms_BCF_ErrInfo5_BCF_ErrInfo5(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo5_BCF_ErrInfo5.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_ErrInfo5_BCF_ErrInfo5() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo5_BCF_ErrInfo5.value \
)

#define Rte_IWrite_BCF_Init_BCF_ErrInfo5_BCF_ErrInfo5(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo5_BCF_ErrInfo5.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_ErrInfo5_BCF_ErrInfo5() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo5_BCF_ErrInfo5.value \
)

#define Rte_IWrite_BCF_100ms_BCF_ErrInfo6_BCF_ErrInfo6(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo6_BCF_ErrInfo6.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_ErrInfo6_BCF_ErrInfo6() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_ErrInfo6_BCF_ErrInfo6.value \
)

#define Rte_IWrite_BCF_Init_BCF_ErrInfo6_BCF_ErrInfo6(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo6_BCF_ErrInfo6.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_ErrInfo6_BCF_ErrInfo6() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_ErrInfo6_BCF_ErrInfo6.value \
)

#define Rte_IWrite_BCF_100ms_BCF_FullChgSOHNv_BCF_FullChgSOHNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_FullChgSOHNv_BCF_FullChgSOHNv.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_FullChgSOHNv_BCF_FullChgSOHNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_FullChgSOHNv_BCF_FullChgSOHNv.value \
)

#define Rte_IWrite_BCF_10ms_BCF_IChLim_BCF_IChLim(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_IChLim_BCF_IChLim.value = (data) \
)

#define Rte_IWriteRef_BCF_10ms_BCF_IChLim_BCF_IChLim() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_IChLim_BCF_IChLim.value \
)

#define Rte_IWrite_BCF_100ms_BCF_IChLimInt_BCF_IChLimInt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IChLimInt_BCF_IChLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_IChLimInt_BCF_IChLimInt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IChLimInt_BCF_IChLimInt.value \
)

#define Rte_IWrite_BCF_Init_BCF_IChLimInt_BCF_IChLimInt(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IChLimInt_BCF_IChLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_IChLimInt_BCF_IChLimInt() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IChLimInt_BCF_IChLimInt.value \
)

#define Rte_IWrite_BCF_100ms_BCF_IChLimMap_BCF_IChLimMap(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IChLimMap_BCF_IChLimMap.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_IChLimMap_BCF_IChLimMap() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IChLimMap_BCF_IChLimMap.value \
)

#define Rte_IWrite_BCF_Init_BCF_IChLimMap_BCF_IChLimMap(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IChLimMap_BCF_IChLimMap.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_IChLimMap_BCF_IChLimMap() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IChLimMap_BCF_IChLimMap.value \
)

#define Rte_IWrite_BCF_100ms_BCF_IChMax_BCF_IChMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IChMax_BCF_IChMax.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_IChMax_BCF_IChMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IChMax_BCF_IChMax.value \
)

#define Rte_IWrite_BCF_Init_BCF_IChMax_BCF_IChMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IChMax_BCF_IChMax.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_IChMax_BCF_IChMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IChMax_BCF_IChMax.value \
)

#define Rte_IWrite_BCF_10ms_BCF_IChPredLim_BCF_IChPredLim(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_IChPredLim_BCF_IChPredLim.value = (data) \
)

#define Rte_IWriteRef_BCF_10ms_BCF_IChPredLim_BCF_IChPredLim() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_IChPredLim_BCF_IChPredLim.value \
)

#define Rte_IWrite_BCF_100ms_BCF_IChPredLimInt_BCF_IChPredLimInt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IChPredLimInt_BCF_IChPredLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_IChPredLimInt_BCF_IChPredLimInt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IChPredLimInt_BCF_IChPredLimInt.value \
)

#define Rte_IWrite_BCF_Init_BCF_IChPredLimInt_BCF_IChPredLimInt(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IChPredLimInt_BCF_IChPredLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_IChPredLimInt_BCF_IChPredLimInt() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IChPredLimInt_BCF_IChPredLimInt.value \
)

#define Rte_IWrite_BCF_10ms_BCF_IDchaLim_BCF_IDchaLim(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_IDchaLim_BCF_IDchaLim.value = (data) \
)

#define Rte_IWriteRef_BCF_10ms_BCF_IDchaLim_BCF_IDchaLim() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_IDchaLim_BCF_IDchaLim.value \
)

#define Rte_IWrite_BCF_100ms_BCF_IDchaLimInt_BCF_IDchaLimInt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IDchaLimInt_BCF_IDchaLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_IDchaLimInt_BCF_IDchaLimInt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IDchaLimInt_BCF_IDchaLimInt.value \
)

#define Rte_IWrite_BCF_Init_BCF_IDchaLimInt_BCF_IDchaLimInt(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IDchaLimInt_BCF_IDchaLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_IDchaLimInt_BCF_IDchaLimInt() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IDchaLimInt_BCF_IDchaLimInt.value \
)

#define Rte_IWrite_BCF_100ms_BCF_IDchaLimMap_BCF_IDchaLimMap(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IDchaLimMap_BCF_IDchaLimMap.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_IDchaLimMap_BCF_IDchaLimMap() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IDchaLimMap_BCF_IDchaLimMap.value \
)

#define Rte_IWrite_BCF_Init_BCF_IDchaLimMap_BCF_IDchaLimMap(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IDchaLimMap_BCF_IDchaLimMap.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_IDchaLimMap_BCF_IDchaLimMap() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IDchaLimMap_BCF_IDchaLimMap.value \
)

#define Rte_IWrite_BCF_100ms_BCF_IDchaMax_BCF_IDchaMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IDchaMax_BCF_IDchaMax.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_IDchaMax_BCF_IDchaMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IDchaMax_BCF_IDchaMax.value \
)

#define Rte_IWrite_BCF_Init_BCF_IDchaMax_BCF_IDchaMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IDchaMax_BCF_IDchaMax.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_IDchaMax_BCF_IDchaMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IDchaMax_BCF_IDchaMax.value \
)

#define Rte_IWrite_BCF_10ms_BCF_IDchaPredLim_BCF_IDchaPredLim(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_IDchaPredLim_BCF_IDchaPredLim.value = (data) \
)

#define Rte_IWriteRef_BCF_10ms_BCF_IDchaPredLim_BCF_IDchaPredLim() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_IDchaPredLim_BCF_IDchaPredLim.value \
)

#define Rte_IWrite_BCF_100ms_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt.value \
)

#define Rte_IWrite_BCF_Init_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt.value \
)

#define Rte_IWrite_BCF_100ms_BCF_IIntglNv_BCF_IIntglNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IIntglNv_BCF_IIntglNv.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_IIntglNv_BCF_IIntglNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_IIntglNv_BCF_IIntglNv.value \
)

#define Rte_IWrite_BCF_Init_BCF_IIntglNv_BCF_IIntglNv(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IIntglNv_BCF_IIntglNv.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_IIntglNv_BCF_IIntglNv() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_IIntglNv_BCF_IIntglNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_NrMdulMax_BCF_NrMdulMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_NrMdulMax_BCF_NrMdulMax.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_NrMdulMax_BCF_NrMdulMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_NrMdulMax_BCF_NrMdulMax.value \
)

#define Rte_IWrite_BCF_10ms_BCF_PwrChLim_BCF_PwrChLim(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_PwrChLim_BCF_PwrChLim.value = (data) \
)

#define Rte_IWriteRef_BCF_10ms_BCF_PwrChLim_BCF_PwrChLim() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_PwrChLim_BCF_PwrChLim.value \
)

#define Rte_IWrite_BCF_10ms_BCF_PwrChPredLim_BCF_PwrChPredLim(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_PwrChPredLim_BCF_PwrChPredLim.value = (data) \
)

#define Rte_IWriteRef_BCF_10ms_BCF_PwrChPredLim_BCF_PwrChPredLim() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_PwrChPredLim_BCF_PwrChPredLim.value \
)

#define Rte_IWrite_BCF_10ms_BCF_PwrDchaLim_BCF_PwrDchaLim(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_PwrDchaLim_BCF_PwrDchaLim.value = (data) \
)

#define Rte_IWriteRef_BCF_10ms_BCF_PwrDchaLim_BCF_PwrDchaLim() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_PwrDchaLim_BCF_PwrDchaLim.value \
)

#define Rte_IWrite_BCF_10ms_BCF_PwrDchaPredLim_BCF_PwrDchaPredLim(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_PwrDchaPredLim_BCF_PwrDchaPredLim.value = (data) \
)

#define Rte_IWriteRef_BCF_10ms_BCF_PwrDchaPredLim_BCF_PwrDchaPredLim() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_PwrDchaPredLim_BCF_PwrDchaPredLim.value \
)

#define Rte_IWrite_BCF_100ms_BCF_PwrMdulLoss_BCF_PwrMdulLoss(data) \
  RteIWrite_BCF_100ms_BCF_PwrMdulLoss_BCF_PwrMdulLoss(data)

#define RteIWrite_BCF_100ms_BCF_PwrMdulLoss_BCF_PwrMdulLoss(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_PwrMdulLoss_BCF_PwrMdulLoss.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_PwrMdulLoss_BCF_PwrMdulLoss() \
  (&((*RteIWriteRef_BCF_100ms_BCF_PwrMdulLoss_BCF_PwrMdulLoss())[0]))

#define RteIWriteRef_BCF_100ms_BCF_PwrMdulLoss_BCF_PwrMdulLoss() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_PwrMdulLoss_BCF_PwrMdulLoss.value \
)

#define Rte_IWrite_BCF_Init_BCF_PwrMdulLoss_BCF_PwrMdulLoss(data) \
  RteIWrite_BCF_Init_BCF_PwrMdulLoss_BCF_PwrMdulLoss(data)

#define RteIWrite_BCF_Init_BCF_PwrMdulLoss_BCF_PwrMdulLoss(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_PwrMdulLoss_BCF_PwrMdulLoss.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_Init_BCF_PwrMdulLoss_BCF_PwrMdulLoss() \
  (&((*RteIWriteRef_BCF_Init_BCF_PwrMdulLoss_BCF_PwrMdulLoss())[0]))

#define RteIWriteRef_BCF_Init_BCF_PwrMdulLoss_BCF_PwrMdulLoss() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_PwrMdulLoss_BCF_PwrMdulLoss.value \
)

#define Rte_IWrite_BCF_100ms_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv(data) \
  RteIWrite_BCF_100ms_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv(data)

#define RteIWrite_BCF_100ms_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv() \
  (&((*RteIWriteRef_BCF_100ms_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv())[0]))

#define RteIWriteRef_BCF_100ms_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_RPackInt_BCF_RPackInt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_RPackInt_BCF_RPackInt.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_RPackInt_BCF_RPackInt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_RPackInt_BCF_RPackInt.value \
)

#define Rte_IWrite_BCF_Init_BCF_RPackInt_BCF_RPackInt(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_RPackInt_BCF_RPackInt.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_RPackInt_BCF_RPackInt() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_RPackInt_BCF_RPackInt.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SocCell_BCF_SocCell(data) \
  RteIWrite_BCF_100ms_BCF_SocCell_BCF_SocCell(data)

#define RteIWrite_BCF_100ms_BCF_SocCell_BCF_SocCell(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocCell_BCF_SocCell.value, data, sizeof(rt_Array_Float_255)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SocCell_BCF_SocCell() \
  (&((*RteIWriteRef_BCF_100ms_BCF_SocCell_BCF_SocCell())[0]))

#define RteIWriteRef_BCF_100ms_BCF_SocCell_BCF_SocCell() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocCell_BCF_SocCell.value \
)

#define Rte_IWrite_BCF_Init_BCF_SocCell_BCF_SocCell(data) \
  RteIWrite_BCF_Init_BCF_SocCell_BCF_SocCell(data)

#define RteIWrite_BCF_Init_BCF_SocCell_BCF_SocCell(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocCell_BCF_SocCell.value, data, sizeof(rt_Array_Float_255)) \
)

#define Rte_IWriteRef_BCF_Init_BCF_SocCell_BCF_SocCell() \
  (&((*RteIWriteRef_BCF_Init_BCF_SocCell_BCF_SocCell())[0]))

#define RteIWriteRef_BCF_Init_BCF_SocCell_BCF_SocCell() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocCell_BCF_SocCell.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SocCellDelta_BCF_SocCellDelta(data) \
  RteIWrite_BCF_100ms_BCF_SocCellDelta_BCF_SocCellDelta(data)

#define RteIWrite_BCF_100ms_BCF_SocCellDelta_BCF_SocCellDelta(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocCellDelta_BCF_SocCellDelta.value, data, sizeof(rt_Array_Float_255)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SocCellDelta_BCF_SocCellDelta() \
  (&((*RteIWriteRef_BCF_100ms_BCF_SocCellDelta_BCF_SocCellDelta())[0]))

#define RteIWriteRef_BCF_100ms_BCF_SocCellDelta_BCF_SocCellDelta() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocCellDelta_BCF_SocCellDelta.value \
)

#define Rte_IWrite_BCF_Init_BCF_SocCellDelta_BCF_SocCellDelta(data) \
  RteIWrite_BCF_Init_BCF_SocCellDelta_BCF_SocCellDelta(data)

#define RteIWrite_BCF_Init_BCF_SocCellDelta_BCF_SocCellDelta(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocCellDelta_BCF_SocCellDelta.value, data, sizeof(rt_Array_Float_255)) \
)

#define Rte_IWriteRef_BCF_Init_BCF_SocCellDelta_BCF_SocCellDelta() \
  (&((*RteIWriteRef_BCF_Init_BCF_SocCellDelta_BCF_SocCellDelta())[0]))

#define RteIWriteRef_BCF_Init_BCF_SocCellDelta_BCF_SocCellDelta() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocCellDelta_BCF_SocCellDelta.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SocCellMax_BCF_SocCellMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocCellMax_BCF_SocCellMax.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SocCellMax_BCF_SocCellMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocCellMax_BCF_SocCellMax.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SocCellMin_BCF_SocCellMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocCellMin_BCF_SocCellMin.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SocCellMin_BCF_SocCellMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocCellMin_BCF_SocCellMin.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SocCnsActNv_BCF_SocCnsActNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocCnsActNv_BCF_SocCnsActNv.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SocCnsActNv_BCF_SocCnsActNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocCnsActNv_BCF_SocCnsActNv.value \
)

#define Rte_IWrite_BCF_Init_BCF_SocCnsActNv_BCF_SocCnsActNv(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocCnsActNv_BCF_SocCnsActNv.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_SocCnsActNv_BCF_SocCnsActNv() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocCnsActNv_BCF_SocCnsActNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SocLimMax_BCF_SocLimMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocLimMax_BCF_SocLimMax.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SocLimMax_BCF_SocLimMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocLimMax_BCF_SocLimMax.value \
)

#define Rte_IWrite_BCF_Init_BCF_SocLimMax_BCF_SocLimMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocLimMax_BCF_SocLimMax.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_SocLimMax_BCF_SocLimMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocLimMax_BCF_SocLimMax.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SocLimMin_BCF_SocLimMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocLimMin_BCF_SocLimMin.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SocLimMin_BCF_SocLimMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocLimMin_BCF_SocLimMin.value \
)

#define Rte_IWrite_BCF_Init_BCF_SocLimMin_BCF_SocLimMin(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocLimMin_BCF_SocLimMin.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_SocLimMin_BCF_SocLimMin() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocLimMin_BCF_SocLimMin.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SocMdul_BCF_SocMdul(data) \
  RteIWrite_BCF_100ms_BCF_SocMdul_BCF_SocMdul(data)

#define RteIWrite_BCF_100ms_BCF_SocMdul_BCF_SocMdul(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocMdul_BCF_SocMdul.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SocMdul_BCF_SocMdul() \
  (&((*RteIWriteRef_BCF_100ms_BCF_SocMdul_BCF_SocMdul())[0]))

#define RteIWriteRef_BCF_100ms_BCF_SocMdul_BCF_SocMdul() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocMdul_BCF_SocMdul.value \
)

#define Rte_IWrite_BCF_Init_BCF_SocMdul_BCF_SocMdul(data) \
  RteIWrite_BCF_Init_BCF_SocMdul_BCF_SocMdul(data)

#define RteIWrite_BCF_Init_BCF_SocMdul_BCF_SocMdul(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocMdul_BCF_SocMdul.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_Init_BCF_SocMdul_BCF_SocMdul() \
  (&((*RteIWriteRef_BCF_Init_BCF_SocMdul_BCF_SocMdul())[0]))

#define RteIWriteRef_BCF_Init_BCF_SocMdul_BCF_SocMdul() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SocMdul_BCF_SocMdul.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SocPack_BCF_SocPack(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocPack_BCF_SocPack.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SocPack_BCF_SocPack() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocPack_BCF_SocPack.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SocPackScld_BCF_SocPackScld(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocPackScld_BCF_SocPackScld.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SocPackScld_BCF_SocPackScld() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocPackScld_BCF_SocPackScld.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SocUOcIniNv_BCF_SocUOcIniNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocUOcIniNv_BCF_SocUOcIniNv.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SocUOcIniNv_BCF_SocUOcIniNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SocUOcIniNv_BCF_SocUOcIniNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SohCalNv_BCF_SohCalNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohCalNv_BCF_SohCalNv.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SohCalNv_BCF_SohCalNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohCalNv_BCF_SohCalNv.value \
)

#define Rte_IWrite_BCF_Init_BCF_SohCalNv_BCF_SohCalNv(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SohCalNv_BCF_SohCalNv.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_SohCalNv_BCF_SohCalNv() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SohCalNv_BCF_SohCalNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SohCycNv_BCF_SohCycNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohCycNv_BCF_SohCycNv.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SohCycNv_BCF_SohCycNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohCycNv_BCF_SohCycNv.value \
)

#define Rte_IWrite_BCF_Init_BCF_SohCycNv_BCF_SohCycNv(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SohCycNv_BCF_SohCycNv.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_SohCycNv_BCF_SohCycNv() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SohCycNv_BCF_SohCycNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SohPack_BCF_SohPack(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohPack_BCF_SohPack.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SohPack_BCF_SohPack() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohPack_BCF_SohPack.value \
)

#define Rte_IWrite_BCF_Init_BCF_SohPack_BCF_SohPack(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SohPack_BCF_SohPack.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_SohPack_BCF_SohPack() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SohPack_BCF_SohPack.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SohPackNv_BCF_SohPackNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohPackNv_BCF_SohPackNv.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SohPackNv_BCF_SohPackNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohPackNv_BCF_SohPackNv.value \
)

#define Rte_IWrite_BCF_Init_BCF_SohPackNv_BCF_SohPackNv(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SohPackNv_BCF_SohPackNv.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_SohPackNv_BCF_SohPackNv() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_SohPackNv_BCF_SohPackNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv(data) \
  RteIWrite_BCF_100ms_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv(data)

#define RteIWrite_BCF_100ms_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv() \
  (&((*RteIWriteRef_BCF_100ms_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv())[0]))

#define RteIWriteRef_BCF_100ms_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv(data) \
  RteIWrite_BCF_100ms_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv(data)

#define RteIWrite_BCF_100ms_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv() \
  (&((*RteIWriteRef_BCF_100ms_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv())[0]))

#define RteIWriteRef_BCF_100ms_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_StAryFlsNv_BCF_StAryFlsNv(data) \
  RteIWrite_BCF_100ms_BCF_StAryFlsNv_BCF_StAryFlsNv(data)

#define RteIWrite_BCF_100ms_BCF_StAryFlsNv_BCF_StAryFlsNv(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_StAryFlsNv_BCF_StAryFlsNv.value, data, sizeof(rt_Array_Float_144)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_StAryFlsNv_BCF_StAryFlsNv() \
  (&((*RteIWriteRef_BCF_100ms_BCF_StAryFlsNv_BCF_StAryFlsNv())[0]))

#define RteIWriteRef_BCF_100ms_BCF_StAryFlsNv_BCF_StAryFlsNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_StAryFlsNv_BCF_StAryFlsNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_StLimnId_BCF_StLimnId(data) \
  RteIWrite_BCF_100ms_BCF_StLimnId_BCF_StLimnId(data)

#define RteIWrite_BCF_100ms_BCF_StLimnId_BCF_StLimnId(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_StLimnId_BCF_StLimnId.value, data, sizeof(rt_Array_UInt8_4)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_StLimnId_BCF_StLimnId() \
  (&((*RteIWriteRef_BCF_100ms_BCF_StLimnId_BCF_StLimnId())[0]))

#define RteIWriteRef_BCF_100ms_BCF_StLimnId_BCF_StLimnId() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_StLimnId_BCF_StLimnId.value \
)

#define Rte_IWrite_BCF_Init_BCF_StLimnId_BCF_StLimnId(data) \
  RteIWrite_BCF_Init_BCF_StLimnId_BCF_StLimnId(data)

#define RteIWrite_BCF_Init_BCF_StLimnId_BCF_StLimnId(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_StLimnId_BCF_StLimnId.value, data, sizeof(rt_Array_UInt8_4)) \
)

#define Rte_IWriteRef_BCF_Init_BCF_StLimnId_BCF_StLimnId() \
  (&((*RteIWriteRef_BCF_Init_BCF_StLimnId_BCF_StLimnId())[0]))

#define RteIWriteRef_BCF_Init_BCF_StLimnId_BCF_StLimnId() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_StLimnId_BCF_StLimnId.value \
)

#define Rte_IWrite_BCF_100ms_BCF_TCooltMdulOut_BCF_TCooltMdulOut(data) \
  RteIWrite_BCF_100ms_BCF_TCooltMdulOut_BCF_TCooltMdulOut(data)

#define RteIWrite_BCF_100ms_BCF_TCooltMdulOut_BCF_TCooltMdulOut(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TCooltMdulOut_BCF_TCooltMdulOut.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_TCooltMdulOut_BCF_TCooltMdulOut() \
  (&((*RteIWriteRef_BCF_100ms_BCF_TCooltMdulOut_BCF_TCooltMdulOut())[0]))

#define RteIWriteRef_BCF_100ms_BCF_TCooltMdulOut_BCF_TCooltMdulOut() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TCooltMdulOut_BCF_TCooltMdulOut.value \
)

#define Rte_IWrite_BCF_Init_BCF_TCooltMdulOut_BCF_TCooltMdulOut(data) \
  RteIWrite_BCF_Init_BCF_TCooltMdulOut_BCF_TCooltMdulOut(data)

#define RteIWrite_BCF_Init_BCF_TCooltMdulOut_BCF_TCooltMdulOut(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_TCooltMdulOut_BCF_TCooltMdulOut.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_Init_BCF_TCooltMdulOut_BCF_TCooltMdulOut() \
  (&((*RteIWriteRef_BCF_Init_BCF_TCooltMdulOut_BCF_TCooltMdulOut())[0]))

#define RteIWriteRef_BCF_Init_BCF_TCooltMdulOut_BCF_TCooltMdulOut() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_TCooltMdulOut_BCF_TCooltMdulOut.value \
)

#define Rte_IWrite_BCF_100ms_BCF_TMdulEstimd_BCF_TMdulEstimd(data) \
  RteIWrite_BCF_100ms_BCF_TMdulEstimd_BCF_TMdulEstimd(data)

#define RteIWrite_BCF_100ms_BCF_TMdulEstimd_BCF_TMdulEstimd(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TMdulEstimd_BCF_TMdulEstimd.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_TMdulEstimd_BCF_TMdulEstimd() \
  (&((*RteIWriteRef_BCF_100ms_BCF_TMdulEstimd_BCF_TMdulEstimd())[0]))

#define RteIWriteRef_BCF_100ms_BCF_TMdulEstimd_BCF_TMdulEstimd() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TMdulEstimd_BCF_TMdulEstimd.value \
)

#define Rte_IWrite_BCF_Init_BCF_TMdulEstimd_BCF_TMdulEstimd(data) \
  RteIWrite_BCF_Init_BCF_TMdulEstimd_BCF_TMdulEstimd(data)

#define RteIWrite_BCF_Init_BCF_TMdulEstimd_BCF_TMdulEstimd(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_TMdulEstimd_BCF_TMdulEstimd.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_Init_BCF_TMdulEstimd_BCF_TMdulEstimd() \
  (&((*RteIWriteRef_BCF_Init_BCF_TMdulEstimd_BCF_TMdulEstimd())[0]))

#define RteIWriteRef_BCF_Init_BCF_TMdulEstimd_BCF_TMdulEstimd() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_TMdulEstimd_BCF_TMdulEstimd.value \
)

#define Rte_IWrite_BCF_100ms_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv(data) \
  RteIWrite_BCF_100ms_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv(data)

#define RteIWrite_BCF_100ms_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv.value, data, sizeof(rt_Array_UInt32_24)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv() \
  (&((*RteIWriteRef_BCF_100ms_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv())[0]))

#define RteIWriteRef_BCF_100ms_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv(data) \
  RteIWrite_BCF_100ms_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv(data)

#define RteIWrite_BCF_100ms_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv.value, data, sizeof(rt_Array_UInt32_24)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv() \
  (&((*RteIWriteRef_BCF_100ms_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv())[0]))

#define RteIWriteRef_BCF_100ms_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_TiBatOffNv_BCF_TiBatOffNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TiBatOffNv_BCF_TiBatOffNv.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_TiBatOffNv_BCF_TiBatOffNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TiBatOffNv_BCF_TiBatOffNv.value \
)

#define Rte_IWrite_BCF_Init_BCF_TiBatOffNv_BCF_TiBatOffNv(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_TiBatOffNv_BCF_TiBatOffNv.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_TiBatOffNv_BCF_TiBatOffNv() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_TiBatOffNv_BCF_TiBatOffNv.value \
)

#define Rte_IWrite_BCF_100ms_BCF_TiChFullOff_BCF_TiChFullOff(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TiChFullOff_BCF_TiChFullOff.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_TiChFullOff_BCF_TiChFullOff() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_TiChFullOff_BCF_TiChFullOff.value \
)

#define Rte_IWrite_BCF_100ms_BCF_UBatTotInt_BCF_UBatTotInt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_UBatTotInt_BCF_UBatTotInt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value \
)

#define Rte_IWrite_BCF_100ms_BCF_UCellAvg_BCF_UCellAvg(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UCellAvg_BCF_UCellAvg.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_UCellAvg_BCF_UCellAvg() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UCellAvg_BCF_UCellAvg.value \
)

#define Rte_IWrite_BCF_10ms_BCF_UChLim_BCF_UChLim(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_UChLim_BCF_UChLim.value = (data) \
)

#define Rte_IWriteRef_BCF_10ms_BCF_UChLim_BCF_UChLim() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_UChLim_BCF_UChLim.value \
)

#define Rte_IWrite_BCF_100ms_BCF_UChLimInt_BCF_UChLimInt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UChLimInt_BCF_UChLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_UChLimInt_BCF_UChLimInt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UChLimInt_BCF_UChLimInt.value \
)

#define Rte_IWrite_BCF_Init_BCF_UChLimInt_BCF_UChLimInt(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UChLimInt_BCF_UChLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_UChLimInt_BCF_UChLimInt() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UChLimInt_BCF_UChLimInt.value \
)

#define Rte_IWrite_BCF_10ms_BCF_UChPredLim_BCF_UChPredLim(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_UChPredLim_BCF_UChPredLim.value = (data) \
)

#define Rte_IWriteRef_BCF_10ms_BCF_UChPredLim_BCF_UChPredLim() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_UChPredLim_BCF_UChPredLim.value \
)

#define Rte_IWrite_BCF_100ms_BCF_UChPredLimInt_BCF_UChPredLimInt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UChPredLimInt_BCF_UChPredLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_UChPredLimInt_BCF_UChPredLimInt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UChPredLimInt_BCF_UChPredLimInt.value \
)

#define Rte_IWrite_BCF_Init_BCF_UChPredLimInt_BCF_UChPredLimInt(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UChPredLimInt_BCF_UChPredLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_UChPredLimInt_BCF_UChPredLimInt() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UChPredLimInt_BCF_UChPredLimInt.value \
)

#define Rte_IWrite_BCF_10ms_BCF_UDchaLim_BCF_UDchaLim(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_UDchaLim_BCF_UDchaLim.value = (data) \
)

#define Rte_IWriteRef_BCF_10ms_BCF_UDchaLim_BCF_UDchaLim() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_UDchaLim_BCF_UDchaLim.value \
)

#define Rte_IWrite_BCF_100ms_BCF_UDchaLimInt_BCF_UDchaLimInt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UDchaLimInt_BCF_UDchaLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_UDchaLimInt_BCF_UDchaLimInt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UDchaLimInt_BCF_UDchaLimInt.value \
)

#define Rte_IWrite_BCF_Init_BCF_UDchaLimInt_BCF_UDchaLimInt(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UDchaLimInt_BCF_UDchaLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_UDchaLimInt_BCF_UDchaLimInt() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UDchaLimInt_BCF_UDchaLimInt.value \
)

#define Rte_IWrite_BCF_10ms_BCF_UDchaPredLim_BCF_UDchaPredLim(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_UDchaPredLim_BCF_UDchaPredLim.value = (data) \
)

#define Rte_IWriteRef_BCF_10ms_BCF_UDchaPredLim_BCF_UDchaPredLim() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BCF_UDchaPredLim_BCF_UDchaPredLim.value \
)

#define Rte_IWrite_BCF_100ms_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt.value \
)

#define Rte_IWrite_BCF_Init_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt.value \
)

#define Rte_IWrite_BCF_100ms_BCF_UMdul_BCF_UMdul(data) \
  RteIWrite_BCF_100ms_BCF_UMdul_BCF_UMdul(data)

#define RteIWrite_BCF_100ms_BCF_UMdul_BCF_UMdul(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UMdul_BCF_UMdul.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_UMdul_BCF_UMdul() \
  (&((*RteIWriteRef_BCF_100ms_BCF_UMdul_BCF_UMdul())[0]))

#define RteIWriteRef_BCF_100ms_BCF_UMdul_BCF_UMdul() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UMdul_BCF_UMdul.value \
)

#define Rte_IWrite_BCF_Init_BCF_UMdul_BCF_UMdul(data) \
  RteIWrite_BCF_Init_BCF_UMdul_BCF_UMdul(data)

#define RteIWrite_BCF_Init_BCF_UMdul_BCF_UMdul(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UMdul_BCF_UMdul.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BCF_Init_BCF_UMdul_BCF_UMdul() \
  (&((*RteIWriteRef_BCF_Init_BCF_UMdul_BCF_UMdul())[0]))

#define RteIWriteRef_BCF_Init_BCF_UMdul_BCF_UMdul() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UMdul_BCF_UMdul.value \
)

#define Rte_IWrite_BCF_100ms_BCF_UPackCircOpen_BCF_UPackCircOpen(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UPackCircOpen_BCF_UPackCircOpen.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_UPackCircOpen_BCF_UPackCircOpen() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_UPackCircOpen_BCF_UPackCircOpen.value \
)

#define Rte_IWrite_BCF_Init_BCF_UPackCircOpen_BCF_UPackCircOpen(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UPackCircOpen_BCF_UPackCircOpen.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_UPackCircOpen_BCF_UPackCircOpen() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_UPackCircOpen_BCF_UPackCircOpen.value \
)

#define Rte_IWrite_BCF_100ms_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind.value \
)

#define Rte_IWrite_BCF_100ms_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg.value = (data) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg.value \
)

#define Rte_IWrite_BCF_Init_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg.value = (data) \
)

#define Rte_IWriteRef_BCF_Init_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg.value \
)

#define Rte_IWrite_BCF_100ms_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls(data) \
  RteIWrite_BCF_100ms_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls(data)

#define RteIWrite_BCF_100ms_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls.value, data, sizeof(rt_Array_UInt8_24)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls() \
  (&((*RteIWriteRef_BCF_100ms_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls())[0]))

#define RteIWriteRef_BCF_100ms_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls.value \
)

#define Rte_IWrite_BCF_Init_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls(data) \
  RteIWrite_BCF_Init_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls(data)

#define RteIWrite_BCF_Init_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls.value, data, sizeof(rt_Array_UInt8_24)) \
)

#define Rte_IWriteRef_BCF_Init_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls() \
  (&((*RteIWriteRef_BCF_Init_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls())[0]))

#define RteIWriteRef_BCF_Init_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatCoreFct_BCF_Init.Rte_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls.value \
)

#define Rte_IWrite_BCF_100ms_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv(data) \
  RteIWrite_BCF_100ms_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv(data)

#define RteIWrite_BCF_100ms_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv.value, data, sizeof(rt_Array_UInt8_24)) \
)

#define Rte_IWriteRef_BCF_100ms_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv() \
  (&((*RteIWriteRef_BCF_100ms_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv())[0]))

#define RteIWriteRef_BCF_100ms_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv.value \
)

#define Rte_IRead_BCF_100ms_BMC_UCell_BMC_UCell() \
  (&((*RteIRead_BCF_100ms_BMC_UCell_BMC_UCell())[0]))

#define RteIRead_BCF_100ms_BMC_UCell_BMC_UCell() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BMC_UCell_BMC_UCell.value)

#define Rte_IRead_BCF_100ms_BPIU_UCellMax_BPIU_UCellMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BPIU_UCellMax_BPIU_UCellMax.value)

#define Rte_IRead_BCF_100ms_BPIU_UCellMin_BPIU_UCellMin() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BPIU_UCellMin_BPIU_UCellMin.value)

#define Rte_IRead_BCF_100ms_BPP_bAcvCTest_BPP_bAcvCTest() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BPP_bAcvCTest_BPP_bAcvCTest.value)

#define Rte_IRead_BCF_100ms_BSTC_RstCmd100_BSTC_RstCmd100() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BSTC_RstCmd100_BSTC_RstCmd100.value)

#define Rte_IRead_BCF_100ms_BSTC_StBcu_BSTC_StBcu() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BSTC_StBcu_BSTC_StBcu.value)

#define Rte_IRead_BCF_100ms_BSTC_TiBatOff_BSTC_TiBatOff() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BSTC_TiBatOff_BSTC_TiBatOff.value)

#define Rte_IRead_BCF_100ms_BTHM_MfCoolt_BTHM_MfCoolt() \
  (&((*RteIRead_BCF_100ms_BTHM_MfCoolt_BTHM_MfCoolt())[0]))

#define RteIRead_BCF_100ms_BTHM_MfCoolt_BTHM_MfCoolt() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BTHM_MfCoolt_BTHM_MfCoolt.value)

#define Rte_IRead_BCF_10ms_BTHM_StSys_BTHM_StSys() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_BTHM_StSys_BTHM_StSys.value)

#define Rte_IRead_BCF_100ms_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr.value)

#define Rte_IRead_BCF_100ms_BTHM_TMdulCorrn_BTHM_TMdulCorrn() \
  (&((*RteIRead_BCF_100ms_BTHM_TMdulCorrn_BTHM_TMdulCorrn())[0]))

#define RteIRead_BCF_100ms_BTHM_TMdulCorrn_BTHM_TMdulCorrn() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BTHM_TMdulCorrn_BTHM_TMdulCorrn.value)

#define Rte_IRead_BCF_100ms_BTHM_TPack_BTHM_TPack() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BTHM_TPack_BTHM_TPack.value)

#define Rte_IRead_BCF_100ms_BTHM_bAcvTAbno_BTHM_bAcvTAbno() \
  (&((*RteIRead_BCF_100ms_BTHM_bAcvTAbno_BTHM_bAcvTAbno())[0]))

#define RteIRead_BCF_100ms_BTHM_bAcvTAbno_BTHM_bAcvTAbno() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BTHM_bAcvTAbno_BTHM_bAcvTAbno.value)

#define Rte_IRead_BCF_100ms_BTHM_bErrSnsrT_BTHM_bErrSnsrT() \
  (&((*RteIRead_BCF_100ms_BTHM_bErrSnsrT_BTHM_bErrSnsrT())[0]))

#define RteIRead_BCF_100ms_BTHM_bErrSnsrT_BTHM_bErrSnsrT() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_BTHM_bErrSnsrT_BTHM_bErrSnsrT.value)

#define Rte_IRead_BCF_100ms_CIL_IBatHv_CIL_IBatHv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_CIL_IBatHv_CIL_IBatHv.value)

#define Rte_IRead_BCF_100ms_CIL_SecRtc_CIL_SecRtc() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_CIL_SecRtc_CIL_SecRtc.value)

#define Rte_IRead_BCF_100ms_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul() \
  (&((*RteIRead_BCF_100ms_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul())[0]))

#define RteIRead_BCF_100ms_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul.value)

#define Rte_IRead_BCF_100ms_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg.value)

#define Rte_IRead_BCF_100ms_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg.value)

#define Rte_IRead_BCF_100ms_CTC_StHvbat_CTC_StHvbat() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_CTC_StHvbat_CTC_StHvbat.value)

#define Rte_IRead_BCF_10ms_CTC_StHvbat_CTC_StHvbat() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_CTC_StHvbat_CTC_StHvbat.value)

#define Rte_IRead_BCF_100ms_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag.value)

#define Rte_IRead_BCF_100ms_DEH_CtrPackSocSetDiag_DEH_CtrPackSocSetDiag() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_CtrPackSocSetDiag_DEH_CtrPackSocSetDiag.value)

#define Rte_IRead_BCF_100ms_DEH_EnaDiagGlb_DEH_EnaDiagGlb() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value)

#define Rte_IRead_BCF_100ms_DEH_ErrCfmd1_DEH_ErrCfmd1() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value)

#define Rte_IRead_BCF_100ms_DEH_ErrCfmd2_DEH_ErrCfmd2() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_ErrCfmd2_DEH_ErrCfmd2.value)

#define Rte_IRead_BCF_100ms_DEH_ErrCfmd3_DEH_ErrCfmd3() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value)

#define Rte_IRead_BCF_100ms_DEH_ErrCfmd6_DEH_ErrCfmd6() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_ErrCfmd6_DEH_ErrCfmd6.value)

#define Rte_IRead_BCF_100ms_DEH_ErrHisCfmd_DEH_ErrHisCfmd() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_ErrHisCfmd_DEH_ErrHisCfmd.value)

#define Rte_IRead_BCF_100ms_DEH_RstDiagGlb_DEH_RstDiagGlb() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value)

#define Rte_IRead_BCF_100ms_DEH_StSocCal_DEH_StSocCal() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_StSocCal_DEH_StSocCal.value)

#define Rte_IRead_BCF_100ms_DEH_StsIninNv_DEH_StsIninNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_StsIninNv_DEH_StsIninNv.value)

#define Rte_IRead_BCF_100ms_DEH_TiChFullOff_DEH_TiChFullOff() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_TiChFullOff_DEH_TiChFullOff.value)

#define Rte_IRead_BCF_100ms_DEH_ValPackSoc_DEH_ValPackSoc() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_ValPackSoc_DEH_ValPackSoc.value)

#define Rte_IRead_BCF_100ms_DEH_bAcvBdNew_DEH_bAcvBdNew() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value)

#define Rte_IRead_BCF_10ms_DEH_bAcvDchaInh_DEH_bAcvDchaInh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_DEH_bAcvDchaInh_DEH_bAcvDchaInh.value)

#define Rte_IRead_BCF_10ms_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1.value)

#define Rte_IRead_BCF_10ms_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2.value)

#define Rte_IRead_BCF_10ms_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1.value)

#define Rte_IRead_BCF_10ms_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2.value)

#define Rte_IRead_BCF_10ms_DEH_bAcvRecupInh_DEH_bAcvRecupInh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_10ms.Rte_DEH_bAcvRecupInh_DEH_bAcvRecupInh.value)

#define Rte_IRead_BCF_100ms_MCC_NrCellByMdul_MCC_NrCellByMdul() \
  (&((*RteIRead_BCF_100ms_MCC_NrCellByMdul_MCC_NrCellByMdul())[0]))

#define RteIRead_BCF_100ms_MCC_NrCellByMdul_MCC_NrCellByMdul() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_MCC_NrCellByMdul_MCC_NrCellByMdul.value)

#define Rte_IRead_BCF_100ms_MCC_NrMdulTot_MCC_NrMdulTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value)

#define Rte_IRead_BCF_100ms_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul() \
  (&((*RteIRead_BCF_100ms_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul())[0]))

#define RteIRead_BCF_100ms_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul.value)

#define Rte_IRead_BCF_100ms_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls() \
  (&((*RteIRead_BCF_100ms_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls())[0]))

#define RteIRead_BCF_100ms_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls.value)

#define Rte_IRead_BCF_100ms_NVM_ChIIntglFls_NVM_ChIIntglFls() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_ChIIntglFls_NVM_ChIIntglFls.value)

#define Rte_IRead_BCF_100ms_NVM_ChgDeltAh_NVM_ChgDeltAh() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_ChgDeltAh_NVM_ChgDeltAh.value)

#define Rte_IRead_BCF_100ms_NVM_DeltAh_NVM_DeltAh() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_DeltAh_NVM_DeltAh.value)

#define Rte_IRead_BCF_100ms_NVM_EBatChTot_NVM_EBatChTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_EBatChTot_NVM_EBatChTot.value)

#define Rte_IRead_BCF_100ms_NVM_FullChgSOH_NVM_FullChgSOH() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_FullChgSOH_NVM_FullChgSOH.value)

#define Rte_IRead_BCF_100ms_NVM_IIntglFls_NVM_IIntglFls() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_IIntglFls_NVM_IIntglFls.value)

#define Rte_IRead_BCF_100ms_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls() \
  (&((*RteIRead_BCF_100ms_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls())[0]))

#define RteIRead_BCF_100ms_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls.value)

#define Rte_IRead_BCF_100ms_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg.value)

#define Rte_IRead_BCF_100ms_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg.value)

#define Rte_IRead_BCF_100ms_NVM_SocCnsAct_NVM_SocCnsAct() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SocCnsAct_NVM_SocCnsAct.value)

#define Rte_IRead_BCF_100ms_NVM_SocPackScld_NVM_SocPackScld() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SocPackScld_NVM_SocPackScld.value)

#define Rte_IRead_BCF_100ms_NVM_SocUOcIni_NVM_SocUOcIni() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SocUOcIni_NVM_SocUOcIni.value)

#define Rte_IRead_BCF_100ms_NVM_SohCalFls_NVM_SohCalFls() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SohCalFls_NVM_SohCalFls.value)

#define Rte_IRead_BCF_100ms_NVM_SohCycFls_NVM_SohCycFls() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SohCycFls_NVM_SohCycFls.value)

#define Rte_IRead_BCF_100ms_NVM_SohPackFls_NVM_SohPackFls() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SohPackFls_NVM_SohPackFls.value)

#define Rte_IRead_BCF_100ms_NVM_SohRDeltaFls_NVM_SohRDeltaFls() \
  (&((*RteIRead_BCF_100ms_NVM_SohRDeltaFls_NVM_SohRDeltaFls())[0]))

#define RteIRead_BCF_100ms_NVM_SohRDeltaFls_NVM_SohRDeltaFls() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SohRDeltaFls_NVM_SohRDeltaFls.value)

#define Rte_IRead_BCF_100ms_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls() \
  (&((*RteIRead_BCF_100ms_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls())[0]))

#define RteIRead_BCF_100ms_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls.value)

#define Rte_IRead_BCF_100ms_NVM_StAryFls_NVM_StAryFls() \
  (&((*RteIRead_BCF_100ms_NVM_StAryFls_NVM_StAryFls())[0]))

#define RteIRead_BCF_100ms_NVM_StAryFls_NVM_StAryFls() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_StAryFls_NVM_StAryFls.value)

#define Rte_IRead_BCF_100ms_NVM_TPackFls_NVM_TPackFls() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_TPackFls_NVM_TPackFls.value)

#define Rte_IRead_BCF_100ms_NVM_TiBatOffFls_NVM_TiBatOffFls() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_TiBatOffFls_NVM_TiBatOffFls.value)

#define Rte_IRead_BCF_100ms_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls() \
  (&((*RteIRead_BCF_100ms_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls())[0]))

#define RteIRead_BCF_100ms_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls.value)

#define Rte_IRead_BCF_100ms_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls() \
  (&((*RteIRead_BCF_100ms_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls())[0]))

#define RteIRead_BCF_100ms_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls.value)

#define Rte_IRead_BCF_100ms_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls() \
  (&((*RteIRead_BCF_100ms_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls())[0]))

#define RteIRead_BCF_100ms_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatCoreFct_BCF_100ms.Rte_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls.value)

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
FUNC(void, swc_BatCoreFct_CODE) BCF_100ms(void);
FUNC(void, swc_BatCoreFct_CODE) BCF_10ms(void);
FUNC(void, swc_BatCoreFct_CODE) BCF_Init(void);
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
#endif /* RTE_SWC_BATCOREFCT_H_ */
 
 
 

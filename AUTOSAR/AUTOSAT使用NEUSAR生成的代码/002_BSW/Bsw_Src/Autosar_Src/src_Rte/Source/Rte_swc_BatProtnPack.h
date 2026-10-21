 
/*
************************************************************************************************************************
*
* File name: Rte_swc_BatProtnPack.h
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
#ifndef RTE_SWC_BATPROTNPACK_H_
#define RTE_SWC_BATPROTNPACK_H_

#include "Rte_swc_BatProtnPack_Type.h"
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
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrCellT_BPP_ErrCellT;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrInfo_BPP_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrPackU_BPP_ErrPackU;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrSocJmp_BPP_ErrSocJmp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrSocVal_BPP_ErrSocVal;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_IAct_BPP_IAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_IChAct_BPP_IChAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_IDchaAct_BPP_IDchaAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_PwrAct_BPP_PwrAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_SocLimMax_BPP_SocLimMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_SocLimMin_BPP_SocLimMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_TCellMaxLim_BPP_TCellMaxLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_TCellMinLim_BPP_TCellMinLim;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_bAcvCTest_BPP_bAcvCTest;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_EnaPack_BCF_EnaPack;
extern VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCell_BCF_SocCell;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohPack_BCF_SohPack;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd2_DEH_ErrCfmd2;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCellTot_MCC_NrCellTot;
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
extern VAR(Rte_ts_App1_Task_50ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_50ms_Core2_QM;
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
#define Rte_IRead_BPP_100ms_BCF_EnaPack_BCF_EnaPack() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BCF_EnaPack_BCF_EnaPack.value)

#define Rte_IRead_BPP_100ms_BCF_SocCell_BCF_SocCell() \
  (&((*RteIRead_BPP_100ms_BCF_SocCell_BCF_SocCell())[0]))

#define RteIRead_BPP_100ms_BCF_SocCell_BCF_SocCell() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BCF_SocCell_BCF_SocCell.value)

#define Rte_IRead_BPP_100ms_BCF_SocPackScld_BCF_SocPackScld() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BCF_SocPackScld_BCF_SocPackScld.value)

#define Rte_IRead_BPP_100ms_BCF_SohPack_BCF_SohPack() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BCF_SohPack_BCF_SohPack.value)

#define Rte_IRead_BPP_50ms_BCF_UBatTotInt_BCF_UBatTotInt() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value)

#define Rte_IWrite_BPP_100ms_BPP_ErrCellT_BPP_ErrCellT(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_ErrCellT_BPP_ErrCellT.value = (data) \
)

#define Rte_IWriteRef_BPP_100ms_BPP_ErrCellT_BPP_ErrCellT() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_ErrCellT_BPP_ErrCellT.value \
)

#define Rte_IWrite_BPP_50ms_BPP_ErrInfo_BPP_ErrInfo(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_ErrInfo_BPP_ErrInfo.value = (data) \
)

#define Rte_IWriteRef_BPP_50ms_BPP_ErrInfo_BPP_ErrInfo() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_ErrInfo_BPP_ErrInfo.value \
)

#define Rte_IWrite_BPP_50ms_BPP_ErrPackU_BPP_ErrPackU(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_ErrPackU_BPP_ErrPackU.value = (data) \
)

#define Rte_IWriteRef_BPP_50ms_BPP_ErrPackU_BPP_ErrPackU() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_ErrPackU_BPP_ErrPackU.value \
)

#define Rte_IWrite_BPP_100ms_BPP_ErrSocJmp_BPP_ErrSocJmp(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_ErrSocJmp_BPP_ErrSocJmp.value = (data) \
)

#define Rte_IWriteRef_BPP_100ms_BPP_ErrSocJmp_BPP_ErrSocJmp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_ErrSocJmp_BPP_ErrSocJmp.value \
)

#define Rte_IWrite_BPP_100ms_BPP_ErrSocVal_BPP_ErrSocVal(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_ErrSocVal_BPP_ErrSocVal.value = (data) \
)

#define Rte_IWriteRef_BPP_100ms_BPP_ErrSocVal_BPP_ErrSocVal() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_ErrSocVal_BPP_ErrSocVal.value \
)

#define Rte_IWrite_BPP_50ms_BPP_IAct_BPP_IAct(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_IAct_BPP_IAct.value = (data) \
)

#define Rte_IWriteRef_BPP_50ms_BPP_IAct_BPP_IAct() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_IAct_BPP_IAct.value \
)

#define Rte_IWrite_BPP_50ms_BPP_IChAct_BPP_IChAct(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_IChAct_BPP_IChAct.value = (data) \
)

#define Rte_IWriteRef_BPP_50ms_BPP_IChAct_BPP_IChAct() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_IChAct_BPP_IChAct.value \
)

#define Rte_IWrite_BPP_50ms_BPP_IDchaAct_BPP_IDchaAct(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_IDchaAct_BPP_IDchaAct.value = (data) \
)

#define Rte_IWriteRef_BPP_50ms_BPP_IDchaAct_BPP_IDchaAct() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_IDchaAct_BPP_IDchaAct.value \
)

#define Rte_IWrite_BPP_50ms_BPP_PwrAct_BPP_PwrAct(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_PwrAct_BPP_PwrAct.value = (data) \
)

#define Rte_IWriteRef_BPP_50ms_BPP_PwrAct_BPP_PwrAct() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_PwrAct_BPP_PwrAct.value \
)

#define Rte_IWrite_BPP_100ms_BPP_SocLimMax_BPP_SocLimMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_SocLimMax_BPP_SocLimMax.value = (data) \
)

#define Rte_IWriteRef_BPP_100ms_BPP_SocLimMax_BPP_SocLimMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_SocLimMax_BPP_SocLimMax.value \
)

#define Rte_IWrite_BPP_Init_BPP_SocLimMax_BPP_SocLimMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnPack_BPP_Init.Rte_BPP_SocLimMax_BPP_SocLimMax.value = (data) \
)

#define Rte_IWriteRef_BPP_Init_BPP_SocLimMax_BPP_SocLimMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnPack_BPP_Init.Rte_BPP_SocLimMax_BPP_SocLimMax.value \
)

#define Rte_IWrite_BPP_100ms_BPP_SocLimMin_BPP_SocLimMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_SocLimMin_BPP_SocLimMin.value = (data) \
)

#define Rte_IWriteRef_BPP_100ms_BPP_SocLimMin_BPP_SocLimMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_SocLimMin_BPP_SocLimMin.value \
)

#define Rte_IWrite_BPP_Init_BPP_SocLimMin_BPP_SocLimMin(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnPack_BPP_Init.Rte_BPP_SocLimMin_BPP_SocLimMin.value = (data) \
)

#define Rte_IWriteRef_BPP_Init_BPP_SocLimMin_BPP_SocLimMin() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnPack_BPP_Init.Rte_BPP_SocLimMin_BPP_SocLimMin.value \
)

#define Rte_IWrite_BPP_100ms_BPP_TCellMaxLim_BPP_TCellMaxLim(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_TCellMaxLim_BPP_TCellMaxLim.value = (data) \
)

#define Rte_IWriteRef_BPP_100ms_BPP_TCellMaxLim_BPP_TCellMaxLim() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_TCellMaxLim_BPP_TCellMaxLim.value \
)

#define Rte_IWrite_BPP_Init_BPP_TCellMaxLim_BPP_TCellMaxLim(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnPack_BPP_Init.Rte_BPP_TCellMaxLim_BPP_TCellMaxLim.value = (data) \
)

#define Rte_IWriteRef_BPP_Init_BPP_TCellMaxLim_BPP_TCellMaxLim() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnPack_BPP_Init.Rte_BPP_TCellMaxLim_BPP_TCellMaxLim.value \
)

#define Rte_IWrite_BPP_100ms_BPP_TCellMinLim_BPP_TCellMinLim(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_TCellMinLim_BPP_TCellMinLim.value = (data) \
)

#define Rte_IWriteRef_BPP_100ms_BPP_TCellMinLim_BPP_TCellMinLim() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BPP_TCellMinLim_BPP_TCellMinLim.value \
)

#define Rte_IWrite_BPP_Init_BPP_TCellMinLim_BPP_TCellMinLim(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnPack_BPP_Init.Rte_BPP_TCellMinLim_BPP_TCellMinLim.value = (data) \
)

#define Rte_IWriteRef_BPP_Init_BPP_TCellMinLim_BPP_TCellMinLim() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnPack_BPP_Init.Rte_BPP_TCellMinLim_BPP_TCellMinLim.value \
)

#define Rte_IWrite_BPP_50ms_BPP_bAcvCTest_BPP_bAcvCTest(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_bAcvCTest_BPP_bAcvCTest.value = (data) \
)

#define Rte_IWriteRef_BPP_50ms_BPP_bAcvCTest_BPP_bAcvCTest() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BPP_bAcvCTest_BPP_bAcvCTest.value \
)

#define Rte_IRead_BPP_100ms_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value)

#define Rte_IRead_BPP_100ms_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw.value)

#define Rte_IRead_BPP_50ms_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw.value)

#define Rte_IRead_BPP_50ms_CIL_IBatHv_CIL_IBatHv() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_CIL_IBatHv_CIL_IBatHv.value)

#define Rte_IRead_BPP_50ms_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value)

#define Rte_IRead_BPP_50ms_CTC_StHvbat_CTC_StHvbat() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_CTC_StHvbat_CTC_StHvbat.value)

#define Rte_IRead_BPP_100ms_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag.value)

#define Rte_IRead_BPP_100ms_DEH_EnaDiagGlb_DEH_EnaDiagGlb() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value)

#define Rte_IRead_BPP_50ms_DEH_EnaDiagGlb_DEH_EnaDiagGlb() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value)

#define Rte_IRead_BPP_100ms_DEH_ErrCfmd1_DEH_ErrCfmd1() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value)

#define Rte_IRead_BPP_50ms_DEH_ErrCfmd1_DEH_ErrCfmd1() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value)

#define Rte_IRead_BPP_100ms_DEH_ErrCfmd2_DEH_ErrCfmd2() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_DEH_ErrCfmd2_DEH_ErrCfmd2.value)

#define Rte_IRead_BPP_50ms_DEH_ErrCfmd3_DEH_ErrCfmd3() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value)

#define Rte_IRead_BPP_100ms_DEH_RstDiagGlb_DEH_RstDiagGlb() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value)

#define Rte_IRead_BPP_50ms_DEH_RstDiagGlb_DEH_RstDiagGlb() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value)

#define Rte_IRead_BPP_100ms_MCC_NrCellTot_MCC_NrCellTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_100ms.Rte_MCC_NrCellTot_MCC_NrCellTot.value)

#define Rte_IRead_BPP_50ms_MCC_NrCellTot_MCC_NrCellTot() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnPack_BPP_50ms.Rte_MCC_NrCellTot_MCC_NrCellTot.value)

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
FUNC(void, swc_BatProtnPack_CODE) BPP_100ms(void);
FUNC(void, swc_BatProtnPack_CODE) BPP_50ms(void);
FUNC(void, swc_BatProtnPack_CODE) BPP_Init(void);
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
#endif /* RTE_SWC_BATPROTNPACK_H_ */
 
 
 

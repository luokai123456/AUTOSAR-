 
/*
************************************************************************************************************************
*
* File name: Rte_swc_BatWntyLogtcData.h
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
#ifndef RTE_SWC_BATWNTYLOGTCDATA_H_
#define RTE_SWC_BATWNTYLOGTCDATA_H_

#include "Rte_swc_BatWntyLogtcData_Type.h"
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
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatChTot_BWLD_CBatChTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatChTotNv_BWLD_CBatChTotNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatDchaTot_BWLD_CBatDchaTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrCh_BWLD_CtrCh;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrChNv_BWLD_CtrChNv;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrDcha_BWLD_CtrDcha;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrDchaNv_BWLD_CtrDchaNv;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrMdulWrNv_BWLD_CtrMdulWrNv;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatChDrvCyc_BWLD_EBatChDrvCyc;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatChTot_BWLD_EBatChTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatChTotNv_BWLD_EBatChTotNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatDchaTot_BWLD_EBatDchaTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatChMax_BWLD_IBatChMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatDchaMax_BWLD_IBatDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatChMax_BWLD_PBatChMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatDchaMax_BWLD_PBatDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMax_BWLD_SocBatMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMin_BWLD_SocBatMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMinNv_BWLD_SocBatMinNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TiBatAgi_BWLD_TiBatAgi;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMax_BWLD_UCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMaxNv_BWLD_UCellMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMin_BWLD_UCellMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMinNv_BWLD_UCellMinNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_IAct_BPP_IAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_PwrAct_BPP_PwrAct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_TrigCh_BSTC_TrigCh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvCh_CTC_bAcvCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_LvlErr_DEH_LvlErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StsIninNv_DEH_StsIninNv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvBdNew_DEH_bAcvBdNew;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_StMdulCu_MCC_StMdulCu;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CBatChTot_NVM_CBatChTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CBatDchaTot_NVM_CBatDchaTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCh_NVM_CtrCh;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrDcha_NVM_CtrDcha;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_EBatChTot_NVM_EBatChTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_EBatDchaTot_NVM_EBatDchaTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_IBatChMax_NVM_IBatChMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_IBatDchaMax_NVM_IBatDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_PBatChMax_NVM_PBatChMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_PBatDchaMax_NVM_PBatDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocBatMax_NVM_SocBatMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocBatMin_NVM_SocBatMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatAgi_NVM_TiBatAgi;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UCellMax_NVM_UCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UCellMin_NVM_UCellMin;
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
extern VAR(Rte_ts_App1_Task_1000ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_1000ms_Core2_QM;
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
#define Rte_IRead_BWLD_100ms_BCF_SocPack_BCF_SocPack() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BCF_SocPack_BCF_SocPack.value)

#define Rte_IRead_BWLD_100ms_BPIU_UCellMax_BPIU_UCellMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BPIU_UCellMax_BPIU_UCellMax.value)

#define Rte_IRead_BWLD_100ms_BPIU_UCellMin_BPIU_UCellMin() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BPIU_UCellMin_BPIU_UCellMin.value)

#define Rte_IRead_BWLD_100ms_BPP_IAct_BPP_IAct() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BPP_IAct_BPP_IAct.value)

#define Rte_IRead_BWLD_100ms_BPP_PwrAct_BPP_PwrAct() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BPP_PwrAct_BPP_PwrAct.value)

#define Rte_IRead_BWLD_100ms_BSTC_StBcu_BSTC_StBcu() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BSTC_StBcu_BSTC_StBcu.value)

#define Rte_IRead_BWLD_100ms_BSTC_TrigCh_BSTC_TrigCh() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BSTC_TrigCh_BSTC_TrigCh.value)

#define Rte_IRead_BWLD_100ms_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value)

#define Rte_IRead_BWLD_100ms_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value)

#define Rte_IWrite_BWLD_100ms_BWLD_CBatChTot_BWLD_CBatChTot(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatChTot_BWLD_CBatChTot.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_CBatChTot_BWLD_CBatChTot() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatChTot_BWLD_CBatChTot.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_CBatChTotNv_BWLD_CBatChTotNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatChTotNv_BWLD_CBatChTotNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_CBatChTotNv_BWLD_CBatChTotNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatChTotNv_BWLD_CBatChTotNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_CBatDchaTot_BWLD_CBatDchaTot(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatDchaTot_BWLD_CBatDchaTot.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_CBatDchaTot_BWLD_CBatDchaTot() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatDchaTot_BWLD_CBatDchaTot.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_CtrCh_BWLD_CtrCh(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrCh_BWLD_CtrCh.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_CtrCh_BWLD_CtrCh() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrCh_BWLD_CtrCh.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_CtrChNv_BWLD_CtrChNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrChNv_BWLD_CtrChNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_CtrChNv_BWLD_CtrChNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrChNv_BWLD_CtrChNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_CtrDcha_BWLD_CtrDcha(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrDcha_BWLD_CtrDcha.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_CtrDcha_BWLD_CtrDcha() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrDcha_BWLD_CtrDcha.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_CtrDchaNv_BWLD_CtrDchaNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrDchaNv_BWLD_CtrDchaNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_CtrDchaNv_BWLD_CtrDchaNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrDchaNv_BWLD_CtrDchaNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_CtrMdulWrNv_BWLD_CtrMdulWrNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrMdulWrNv_BWLD_CtrMdulWrNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_CtrMdulWrNv_BWLD_CtrMdulWrNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrMdulWrNv_BWLD_CtrMdulWrNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_EBatChDrvCyc_BWLD_EBatChDrvCyc(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatChDrvCyc_BWLD_EBatChDrvCyc.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_EBatChDrvCyc_BWLD_EBatChDrvCyc() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatChDrvCyc_BWLD_EBatChDrvCyc.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_EBatChTot_BWLD_EBatChTot(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatChTot_BWLD_EBatChTot.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_EBatChTot_BWLD_EBatChTot() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatChTot_BWLD_EBatChTot.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_EBatChTotNv_BWLD_EBatChTotNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatChTotNv_BWLD_EBatChTotNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_EBatChTotNv_BWLD_EBatChTotNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatChTotNv_BWLD_EBatChTotNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_EBatDchaTot_BWLD_EBatDchaTot(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatDchaTot_BWLD_EBatDchaTot.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_EBatDchaTot_BWLD_EBatDchaTot() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatDchaTot_BWLD_EBatDchaTot.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_IBatChMax_BWLD_IBatChMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_IBatChMax_BWLD_IBatChMax.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_IBatChMax_BWLD_IBatChMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_IBatChMax_BWLD_IBatChMax.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_IBatDchaMax_BWLD_IBatDchaMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_IBatDchaMax_BWLD_IBatDchaMax.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_IBatDchaMax_BWLD_IBatDchaMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_IBatDchaMax_BWLD_IBatDchaMax.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_PBatChMax_BWLD_PBatChMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_PBatChMax_BWLD_PBatChMax.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_PBatChMax_BWLD_PBatChMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_PBatChMax_BWLD_PBatChMax.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_PBatDchaMax_BWLD_PBatDchaMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_PBatDchaMax_BWLD_PBatDchaMax.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_PBatDchaMax_BWLD_PBatDchaMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_PBatDchaMax_BWLD_PBatDchaMax.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_SocBatMax_BWLD_SocBatMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_SocBatMax_BWLD_SocBatMax.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_SocBatMax_BWLD_SocBatMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_SocBatMax_BWLD_SocBatMax.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_SocBatMin_BWLD_SocBatMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_SocBatMin_BWLD_SocBatMin.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_SocBatMin_BWLD_SocBatMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_SocBatMin_BWLD_SocBatMin.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_SocBatMinNv_BWLD_SocBatMinNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_SocBatMinNv_BWLD_SocBatMinNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_SocBatMinNv_BWLD_SocBatMinNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_SocBatMinNv_BWLD_SocBatMinNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv.value \
)

#define Rte_IWrite_BWLD_1000ms_BWLD_TiBatAgi_BWLD_TiBatAgi(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_1000ms.Rte_BWLD_TiBatAgi_BWLD_TiBatAgi.value = (data) \
)

#define Rte_IWriteRef_BWLD_1000ms_BWLD_TiBatAgi_BWLD_TiBatAgi() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_1000ms.Rte_BWLD_TiBatAgi_BWLD_TiBatAgi.value \
)

#define Rte_IWrite_BWLD_1000ms_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_1000ms.Rte_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_1000ms_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_1000ms.Rte_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_UCellMax_BWLD_UCellMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UCellMax_BWLD_UCellMax.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_UCellMax_BWLD_UCellMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UCellMax_BWLD_UCellMax.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_UCellMaxNv_BWLD_UCellMaxNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UCellMaxNv_BWLD_UCellMaxNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_UCellMaxNv_BWLD_UCellMaxNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UCellMaxNv_BWLD_UCellMaxNv.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_UCellMin_BWLD_UCellMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UCellMin_BWLD_UCellMin.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_UCellMin_BWLD_UCellMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UCellMin_BWLD_UCellMin.value \
)

#define Rte_IWrite_BWLD_100ms_BWLD_UCellMinNv_BWLD_UCellMinNv(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UCellMinNv_BWLD_UCellMinNv.value = (data) \
)

#define Rte_IWriteRef_BWLD_100ms_BWLD_UCellMinNv_BWLD_UCellMinNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_BWLD_UCellMinNv_BWLD_UCellMinNv.value \
)

#define Rte_IRead_BWLD_100ms_CIL_IBatHv_CIL_IBatHv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_CIL_IBatHv_CIL_IBatHv.value)

#define Rte_IRead_BWLD_100ms_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value)

#define Rte_IRead_BWLD_1000ms_CTC_StHvbat_CTC_StHvbat() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_1000ms.Rte_CTC_StHvbat_CTC_StHvbat.value)

#define Rte_IRead_BWLD_100ms_CTC_StHvbat_CTC_StHvbat() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_CTC_StHvbat_CTC_StHvbat.value)

#define Rte_IRead_BWLD_100ms_CTC_StLoopHv_CTC_StLoopHv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value)

#define Rte_IRead_BWLD_100ms_CTC_bAcvCh_CTC_bAcvCh() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_CTC_bAcvCh_CTC_bAcvCh.value)

#define Rte_IRead_BWLD_100ms_DEH_LvlErr_DEH_LvlErr() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_DEH_LvlErr_DEH_LvlErr.value)

#define Rte_IRead_BWLD_1000ms_DEH_StsIninNv_DEH_StsIninNv() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_1000ms.Rte_DEH_StsIninNv_DEH_StsIninNv.value)

#define Rte_IRead_BWLD_100ms_DEH_StsIninNv_DEH_StsIninNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_DEH_StsIninNv_DEH_StsIninNv.value)

#define Rte_IRead_BWLD_1000ms_DEH_bAcvBdNew_DEH_bAcvBdNew() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_1000ms.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value)

#define Rte_IRead_BWLD_100ms_DEH_bAcvBdNew_DEH_bAcvBdNew() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value)

#define Rte_IRead_BWLD_100ms_MCC_StMdulCu_MCC_StMdulCu() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_MCC_StMdulCu_MCC_StMdulCu.value)

#define Rte_IRead_BWLD_100ms_NVM_CBatChTot_NVM_CBatChTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_CBatChTot_NVM_CBatChTot.value)

#define Rte_IRead_BWLD_100ms_NVM_CBatDchaTot_NVM_CBatDchaTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_CBatDchaTot_NVM_CBatDchaTot.value)

#define Rte_IRead_BWLD_100ms_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot.value)

#define Rte_IRead_BWLD_100ms_NVM_CtrCh_NVM_CtrCh() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_CtrCh_NVM_CtrCh.value)

#define Rte_IRead_BWLD_100ms_NVM_CtrDcha_NVM_CtrDcha() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_CtrDcha_NVM_CtrDcha.value)

#define Rte_IRead_BWLD_100ms_NVM_EBatChTot_NVM_EBatChTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_EBatChTot_NVM_EBatChTot.value)

#define Rte_IRead_BWLD_100ms_NVM_EBatDchaTot_NVM_EBatDchaTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_EBatDchaTot_NVM_EBatDchaTot.value)

#define Rte_IRead_BWLD_100ms_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot.value)

#define Rte_IRead_BWLD_100ms_NVM_IBatChMax_NVM_IBatChMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_IBatChMax_NVM_IBatChMax.value)

#define Rte_IRead_BWLD_100ms_NVM_IBatDchaMax_NVM_IBatDchaMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_IBatDchaMax_NVM_IBatDchaMax.value)

#define Rte_IRead_BWLD_100ms_NVM_PBatChMax_NVM_PBatChMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_PBatChMax_NVM_PBatChMax.value)

#define Rte_IRead_BWLD_100ms_NVM_PBatDchaMax_NVM_PBatDchaMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_PBatDchaMax_NVM_PBatDchaMax.value)

#define Rte_IRead_BWLD_100ms_NVM_SocBatMax_NVM_SocBatMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_SocBatMax_NVM_SocBatMax.value)

#define Rte_IRead_BWLD_100ms_NVM_SocBatMin_NVM_SocBatMin() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_SocBatMin_NVM_SocBatMin.value)

#define Rte_IRead_BWLD_100ms_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax.value)

#define Rte_IRead_BWLD_100ms_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin.value)

#define Rte_IRead_BWLD_1000ms_NVM_TiBatAgi_NVM_TiBatAgi() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_1000ms.Rte_NVM_TiBatAgi_NVM_TiBatAgi.value)

#define Rte_IRead_BWLD_100ms_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax.value)

#define Rte_IRead_BWLD_100ms_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin.value)

#define Rte_IRead_BWLD_100ms_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax.value)

#define Rte_IRead_BWLD_100ms_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin.value)

#define Rte_IRead_BWLD_100ms_NVM_UCellMax_NVM_UCellMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_UCellMax_NVM_UCellMax.value)

#define Rte_IRead_BWLD_100ms_NVM_UCellMin_NVM_UCellMin() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatWntyLogtcData_BWLD_100ms.Rte_NVM_UCellMin_NVM_UCellMin.value)

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
FUNC(void, swc_BatWntyLogtcData_CODE) BWLD_1000ms(void);
FUNC(void, swc_BatWntyLogtcData_CODE) BWLD_100ms(void);
FUNC(void, swc_BatWntyLogtcData_CODE) BWLD_Init(void);
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
#endif /* RTE_SWC_BATWNTYLOGTCDATA_H_ */
 
 
 

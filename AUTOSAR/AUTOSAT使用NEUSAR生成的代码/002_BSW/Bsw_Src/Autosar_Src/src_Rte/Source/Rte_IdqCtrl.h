 
/*
************************************************************************************************************************
*
* File name: Rte_IdqCtrl.h
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
#ifndef RTE_IDQCTRL_H_
#define RTE_IDQCTRL_H_

#include "Rte_IdqCtrl_Type.h"
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

#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_bUSqrtLimActv_IdqCtrl_bUSqrtLimActv;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_facOverModlnMaxSqd_IdqCtrl_facOverModlnMaxSqd;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uDa_IdqCtrl_uDa;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uDaSclg_IdqCtrl_uDaSclg;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uQa_IdqCtrl_uQa;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uQaSclg_IdqCtrl_uQaSclg;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uStr_IdqCtrl_uStr;
extern VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_agRotate_AngSwDecod_agRotate;
extern VAR(Float, RTE_VAR_INIT) Rte_DynFrq_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_HrmcInj_HrmcInj_iQaDesWithHrmcInj_HrmcInj_iQaDesWithHrmcInj;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iAa_IdqAct_iAa;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iBa_IdqAct_iBa;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uDaPI_IdqCtrl_uDaPI;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uPwmMax_IdqCtrl_uPwmMax;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uQaPI_IdqCtrl_uQaPI;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uRsv_IdqCtrl_uRsv;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uSqrtMax_IdqCtrl_uSqrtMax;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uSqrtRsvSclg_IdqCtrl_uSqrtRsvSclg;
extern VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec;
extern VAR(SInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr;
extern VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
extern VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iDa_IdqAct_iDa;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iQa_IdqAct_iQa;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_iDaDes_IdqDes_iDaDes;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_iQaDes_IdqDes_iQaDes;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_indtDa_IdqDes_indtDa;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_indtQa_IdqDes_indtQa;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_mflxExct_IdqDes_mflxExct;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_omRtr_IdqDes_omRtr;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_resStr_IdqDes_resStr;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_AngSwDecod_agRotate_AngSwDecod_agRotate(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr(P2VAR(UInt8, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_HrmcInj_iQaDesWithHrmcInj_HrmcInj_iQaDesWithHrmcInj(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqAct_iAa_IdqAct_iAa(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqAct_iBa_IdqAct_iBa(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqAct_iDa_IdqAct_iDa(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqAct_iQa_IdqAct_iQa(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_bUSqrtLimActv_IdqCtrl_bUSqrtLimActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_facOverModlnMaxSqd_IdqCtrl_facOverModlnMaxSqd(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uDa_IdqCtrl_uDa(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uDaPI_IdqCtrl_uDaPI(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uDaSclg_IdqCtrl_uDaSclg(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uPwmMax_IdqCtrl_uPwmMax(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uQa_IdqCtrl_uQa(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uQaPI_IdqCtrl_uQaPI(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uQaSclg_IdqCtrl_uQaSclg(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uRsv_IdqCtrl_uRsv(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uSqrtMax_IdqCtrl_uSqrtMax(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uSqrtRsvSclg_IdqCtrl_uSqrtRsvSclg(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uStr_IdqCtrl_uStr(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqDes_iDaDes_IdqDes_iDaDes(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqDes_iQaDes_IdqDes_iQaDes(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqDes_indtDa_IdqDes_indtDa(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqDes_indtQa_IdqDes_indtQa(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqDes_mflxExct_IdqDes_mflxExct(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqDes_omRtr_IdqDes_omRtr(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqDes_resStr_IdqDes_resStr(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data);
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
#define Rte_Read_AngSwDecod_agRotate_AngSwDecod_agRotate Rte_Read_IdqCtrl_AngSwDecod_agRotate_AngSwDecod_agRotate
#define Rte_Read_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec Rte_Read_IdqCtrl_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec
#define Rte_Read_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd Rte_Read_IdqCtrl_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd
#define Rte_Read_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp Rte_Read_IdqCtrl_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp
#define Rte_Read_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr Rte_Read_IdqCtrl_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr
#define Rte_Read_HrmcInj_iQaDesWithHrmcInj_HrmcInj_iQaDesWithHrmcInj Rte_Read_IdqCtrl_HrmcInj_iQaDesWithHrmcInj_HrmcInj_iQaDesWithHrmcInj
#define Rte_Read_HvInvDev_uPhyHV_HvInvDev_uPhyHV Rte_Read_IdqCtrl_HvInvDev_uPhyHV_HvInvDev_uPhyHV
#define Rte_Read_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd Rte_Read_IdqCtrl_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd
#define Rte_Read_IdqAct_iAa_IdqAct_iAa Rte_Read_IdqCtrl_IdqAct_iAa_IdqAct_iAa
#define Rte_Read_IdqAct_iBa_IdqAct_iBa Rte_Read_IdqCtrl_IdqAct_iBa_IdqAct_iBa
#define Rte_Read_IdqAct_iDa_IdqAct_iDa Rte_Read_IdqCtrl_IdqAct_iDa_IdqAct_iDa
#define Rte_Read_IdqAct_iQa_IdqAct_iQa Rte_Read_IdqCtrl_IdqAct_iQa_IdqAct_iQa
#define Rte_Read_IdqDes_iDaDes_IdqDes_iDaDes Rte_Read_IdqCtrl_IdqDes_iDaDes_IdqDes_iDaDes
#define Rte_Read_IdqDes_iQaDes_IdqDes_iQaDes Rte_Read_IdqCtrl_IdqDes_iQaDes_IdqDes_iQaDes
#define Rte_Read_IdqDes_indtDa_IdqDes_indtDa Rte_Read_IdqCtrl_IdqDes_indtDa_IdqDes_indtDa
#define Rte_Read_IdqDes_indtQa_IdqDes_indtQa Rte_Read_IdqCtrl_IdqDes_indtQa_IdqDes_indtQa
#define Rte_Read_IdqDes_mflxExct_IdqDes_mflxExct Rte_Read_IdqCtrl_IdqDes_mflxExct_IdqDes_mflxExct
#define Rte_Read_IdqDes_omRtr_IdqDes_omRtr Rte_Read_IdqCtrl_IdqDes_omRtr_IdqDes_omRtr
#define Rte_Read_IdqDes_resStr_IdqDes_resStr Rte_Read_IdqCtrl_IdqDes_resStr_IdqDes_resStr
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
#define Rte_Write_IdqCtrl_bUSqrtLimActv_IdqCtrl_bUSqrtLimActv Rte_Write_IdqCtrl_IdqCtrl_bUSqrtLimActv_IdqCtrl_bUSqrtLimActv
#define Rte_Write_IdqCtrl_facOverModlnMaxSqd_IdqCtrl_facOverModlnMaxSqd Rte_Write_IdqCtrl_IdqCtrl_facOverModlnMaxSqd_IdqCtrl_facOverModlnMaxSqd
#define Rte_Write_IdqCtrl_uDa_IdqCtrl_uDa Rte_Write_IdqCtrl_IdqCtrl_uDa_IdqCtrl_uDa
#define Rte_Write_IdqCtrl_uDaPI_IdqCtrl_uDaPI Rte_Write_IdqCtrl_IdqCtrl_uDaPI_IdqCtrl_uDaPI
#define Rte_Write_IdqCtrl_uDaSclg_IdqCtrl_uDaSclg Rte_Write_IdqCtrl_IdqCtrl_uDaSclg_IdqCtrl_uDaSclg
#define Rte_Write_IdqCtrl_uPwmMax_IdqCtrl_uPwmMax Rte_Write_IdqCtrl_IdqCtrl_uPwmMax_IdqCtrl_uPwmMax
#define Rte_Write_IdqCtrl_uQa_IdqCtrl_uQa Rte_Write_IdqCtrl_IdqCtrl_uQa_IdqCtrl_uQa
#define Rte_Write_IdqCtrl_uQaPI_IdqCtrl_uQaPI Rte_Write_IdqCtrl_IdqCtrl_uQaPI_IdqCtrl_uQaPI
#define Rte_Write_IdqCtrl_uQaSclg_IdqCtrl_uQaSclg Rte_Write_IdqCtrl_IdqCtrl_uQaSclg_IdqCtrl_uQaSclg
#define Rte_Write_IdqCtrl_uRsv_IdqCtrl_uRsv Rte_Write_IdqCtrl_IdqCtrl_uRsv_IdqCtrl_uRsv
#define Rte_Write_IdqCtrl_uSqrtMax_IdqCtrl_uSqrtMax Rte_Write_IdqCtrl_IdqCtrl_uSqrtMax_IdqCtrl_uSqrtMax
#define Rte_Write_IdqCtrl_uSqrtRsvSclg_IdqCtrl_uSqrtRsvSclg Rte_Write_IdqCtrl_IdqCtrl_uSqrtRsvSclg_IdqCtrl_uSqrtRsvSclg
#define Rte_Write_IdqCtrl_uStr_IdqCtrl_uStr Rte_Write_IdqCtrl_IdqCtrl_uStr_IdqCtrl_uStr
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
FUNC(void, IdqCtrl_CODE) IdqCtrl_Init(void);
FUNC(void, IdqCtrl_CODE) fc_IdqCtrl(void);
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
#endif /* RTE_IDQCTRL_H_ */
 
 
 

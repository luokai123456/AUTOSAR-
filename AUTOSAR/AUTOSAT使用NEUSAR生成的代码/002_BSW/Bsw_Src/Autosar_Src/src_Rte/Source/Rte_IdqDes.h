 
/*
************************************************************************************************************************
*
* File name: Rte_IdqDes.h
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
#ifndef RTE_IDQDES_H_
#define RTE_IDQDES_H_

#include "Rte_IdqDes_Type.h"
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

#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_agCurrDaQa_IdqDes_agCurrDaQa;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_facFlxExctSclg_IdqDes_facFlxExctSclg;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_indtQaSubtDa_IdqDes_indtQaSubtDa;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_omRtrRecpr_IdqDes_omRtrRecpr;
extern VAR(SInt8, RTE_VAR_INIT) Rte_IdqDes_IdqDes_stSgnTqEmDes_IdqDes_stSgnTqEmDes;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_tqEmDes_IdqDes_tqEmDes;
extern VAR(Float, RTE_VAR_INIT) Rte_Dchrg_Dchrg_iDchrg_Dchrg_iDchrg;
extern VAR(Float, RTE_VAR_INIT) Rte_EmTq_EmTq_tqEmLost_EmTq_tqEmLost;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_AngOfstCal_AngOfstCal_iDaDes_AngOfstCal_iDaDes;
extern VAR(Float, RTE_VAR_INIT) Rte_AngOfstCal_AngOfstCal_iQaDes_AngOfstCal_iQaDes;
extern VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec;
extern VAR(SInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
extern VAR(SInt8, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir;
extern VAR(Boolean, RTE_VAR_INIT) Rte_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr;
extern VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iDaFiltd_IdqAct_iDaFiltd;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iQaFiltd_IdqAct_iQaFiltd;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uPwmMax_IdqCtrl_uPwmMax;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uRsv_IdqCtrl_uRsv;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uSqrtMax_IdqCtrl_uSqrtMax;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uSqrtRsvSclg_IdqCtrl_uSqrtRsvSclg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta;
extern VAR(Boolean, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUDischgEn_cmd_MMC_MCUDischgEn_cmd;
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
extern VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhyMot_TempDev_tPhyMot;
extern VAR(Float, RTE_VAR_INIT) Rte_TqDemCoorn_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_AngOfstCal_iDaDes_AngOfstCal_iDaDes(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_AngOfstCal_iQaDes_AngOfstCal_iQaDes(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir(P2VAR(SInt8, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_Dchrg_iDchrg_Dchrg_iDchrg(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr(P2VAR(Boolean, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_EmTq_tqEmLost_EmTq_tqEmLost(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_IdqAct_iDaFiltd_IdqAct_iDaFiltd(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_IdqAct_iQaFiltd_IdqAct_iQaFiltd(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_IdqCtrl_uPwmMax_IdqCtrl_uPwmMax(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_IdqCtrl_uRsv_IdqCtrl_uRsv(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_IdqCtrl_uSqrtMax_IdqCtrl_uSqrtMax(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_IdqCtrl_uSqrtRsvSclg_IdqCtrl_uSqrtRsvSclg(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_agCurrDaQa_IdqDes_agCurrDaQa(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_facFlxExctSclg_IdqDes_facFlxExctSclg(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_iDaDes_IdqDes_iDaDes(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_iQaDes_IdqDes_iQaDes(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_indtDa_IdqDes_indtDa(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_indtQa_IdqDes_indtQa(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_indtQaSubtDa_IdqDes_indtQaSubtDa(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_mflxExct_IdqDes_mflxExct(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_omRtr_IdqDes_omRtr(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_omRtrRecpr_IdqDes_omRtrRecpr(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_resStr_IdqDes_resStr(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_stSgnTqEmDes_IdqDes_stSgnTqEmDes(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqDes_IdqDes_tqEmDes_IdqDes_tqEmDes(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_MMC_MCUDischgEn_cmd_MMC_MCUDischgEn_cmd(P2VAR(Boolean, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_TempDev_tPhyMot_TempDev_tPhyMot(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqDes_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd(P2VAR(Float, AUTOMATIC, RTE_IdqDes_APPL_DATA) data);
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
#define Rte_Read_AngOfstCal_iDaDes_AngOfstCal_iDaDes Rte_Read_IdqDes_AngOfstCal_iDaDes_AngOfstCal_iDaDes
#define Rte_Read_AngOfstCal_iQaDes_AngOfstCal_iQaDes Rte_Read_IdqDes_AngOfstCal_iQaDes_AngOfstCal_iQaDes
#define Rte_Read_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec Rte_Read_IdqDes_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec
#define Rte_Read_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd Rte_Read_IdqDes_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd
#define Rte_Read_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir Rte_Read_IdqDes_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir
#define Rte_Read_Dchrg_iDchrg_Dchrg_iDchrg Rte_Read_IdqDes_Dchrg_iDchrg_Dchrg_iDchrg
#define Rte_Read_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr Rte_Read_IdqDes_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr
#define Rte_Read_EmTq_tqEmLost_EmTq_tqEmLost Rte_Read_IdqDes_EmTq_tqEmLost_EmTq_tqEmLost
#define Rte_Read_HvInvDev_uPhyHV_HvInvDev_uPhyHV Rte_Read_IdqDes_HvInvDev_uPhyHV_HvInvDev_uPhyHV
#define Rte_Read_IdqAct_iDaFiltd_IdqAct_iDaFiltd Rte_Read_IdqDes_IdqAct_iDaFiltd_IdqAct_iDaFiltd
#define Rte_Read_IdqAct_iQaFiltd_IdqAct_iQaFiltd Rte_Read_IdqDes_IdqAct_iQaFiltd_IdqAct_iQaFiltd
#define Rte_Read_IdqCtrl_uPwmMax_IdqCtrl_uPwmMax Rte_Read_IdqDes_IdqCtrl_uPwmMax_IdqCtrl_uPwmMax
#define Rte_Read_IdqCtrl_uRsv_IdqCtrl_uRsv Rte_Read_IdqDes_IdqCtrl_uRsv_IdqCtrl_uRsv
#define Rte_Read_IdqCtrl_uSqrtMax_IdqCtrl_uSqrtMax Rte_Read_IdqDes_IdqCtrl_uSqrtMax_IdqCtrl_uSqrtMax
#define Rte_Read_IdqCtrl_uSqrtRsvSclg_IdqCtrl_uSqrtRsvSclg Rte_Read_IdqDes_IdqCtrl_uSqrtRsvSclg_IdqCtrl_uSqrtRsvSclg
#define Rte_Read_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta Rte_Read_IdqDes_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta
#define Rte_Read_MMC_MCUDischgEn_cmd_MMC_MCUDischgEn_cmd Rte_Read_IdqDes_MMC_MCUDischgEn_cmd_MMC_MCUDischgEn_cmd
#define Rte_Read_TempDev_tPhyMot_TempDev_tPhyMot Rte_Read_IdqDes_TempDev_tPhyMot_TempDev_tPhyMot
#define Rte_Read_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd Rte_Read_IdqDes_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd
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
#define Rte_Write_IdqDes_agCurrDaQa_IdqDes_agCurrDaQa Rte_Write_IdqDes_IdqDes_agCurrDaQa_IdqDes_agCurrDaQa
#define Rte_Write_IdqDes_facFlxExctSclg_IdqDes_facFlxExctSclg Rte_Write_IdqDes_IdqDes_facFlxExctSclg_IdqDes_facFlxExctSclg
#define Rte_Write_IdqDes_iDaDes_IdqDes_iDaDes Rte_Write_IdqDes_IdqDes_iDaDes_IdqDes_iDaDes
#define Rte_Write_IdqDes_iQaDes_IdqDes_iQaDes Rte_Write_IdqDes_IdqDes_iQaDes_IdqDes_iQaDes
#define Rte_Write_IdqDes_indtDa_IdqDes_indtDa Rte_Write_IdqDes_IdqDes_indtDa_IdqDes_indtDa
#define Rte_Write_IdqDes_indtQa_IdqDes_indtQa Rte_Write_IdqDes_IdqDes_indtQa_IdqDes_indtQa
#define Rte_Write_IdqDes_indtQaSubtDa_IdqDes_indtQaSubtDa Rte_Write_IdqDes_IdqDes_indtQaSubtDa_IdqDes_indtQaSubtDa
#define Rte_Write_IdqDes_mflxExct_IdqDes_mflxExct Rte_Write_IdqDes_IdqDes_mflxExct_IdqDes_mflxExct
#define Rte_Write_IdqDes_omRtr_IdqDes_omRtr Rte_Write_IdqDes_IdqDes_omRtr_IdqDes_omRtr
#define Rte_Write_IdqDes_omRtrRecpr_IdqDes_omRtrRecpr Rte_Write_IdqDes_IdqDes_omRtrRecpr_IdqDes_omRtrRecpr
#define Rte_Write_IdqDes_resStr_IdqDes_resStr Rte_Write_IdqDes_IdqDes_resStr_IdqDes_resStr
#define Rte_Write_IdqDes_stSgnTqEmDes_IdqDes_stSgnTqEmDes Rte_Write_IdqDes_IdqDes_stSgnTqEmDes_IdqDes_stSgnTqEmDes
#define Rte_Write_IdqDes_tqEmDes_IdqDes_tqEmDes Rte_Write_IdqDes_IdqDes_tqEmDes_IdqDes_tqEmDes
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
FUNC(void, IdqDes_CODE) IdqDes_Init(void);
FUNC(void, IdqDes_CODE) fc_IdqDes(void);
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
#endif /* RTE_IDQDES_H_ */
 
 
 

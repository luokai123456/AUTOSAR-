 
/*
************************************************************************************************************************
*
* File name: Rte_EmTq.h
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
#ifndef RTE_EMTQ_H_
#define RTE_EMTQ_H_

#include "Rte_EmTq_Type.h"
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
extern VAR(Float, RTE_VAR_INIT) Rte_EmTq_EmTq_tqEmFiltd_EmTq_tqEmFiltd;
extern VAR(Float, RTE_VAR_INIT) Rte_EmTq_EmTq_tqEmLost_EmTq_tqEmLost;
extern VAR(Float, RTE_VAR_INIT) Rte_EmTq_EmTq_tqMecl_EmTq_tqMecl;
extern VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqFric_ExtTqDes_tqFric;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_indtQaSubtDa_IdqDes_indtQaSubtDa;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec;
extern VAR(UInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs;
extern VAR(SInt8, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iDaFiltd_IdqAct_iDaFiltd;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iQaFiltd_IdqAct_iQaFiltd;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iSqrt_IdqAct_iSqrt;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_EmTq_EmTq_tqEm_EmTq_tqEm;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_mflxExct_IdqDes_mflxExct;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs(P2VAR(UInt16, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir(P2VAR(SInt8, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr(P2VAR(UInt8, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EmTq_EmTq_tqEm_EmTq_tqEm(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EmTq_EmTq_tqEmFiltd_EmTq_tqEmFiltd(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EmTq_EmTq_tqEmLost_EmTq_tqEmLost(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EmTq_EmTq_tqMecl_EmTq_tqMecl(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_ExtTqDes_tqFric_ExtTqDes_tqFric(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_IdqAct_iDaFiltd_IdqAct_iDaFiltd(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_IdqAct_iQaFiltd_IdqAct_iQaFiltd(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_IdqAct_iSqrt_IdqAct_iSqrt(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_IdqDes_indtQaSubtDa_IdqDes_indtQaSubtDa(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmTq_IdqDes_mflxExct_IdqDes_mflxExct(P2VAR(Float, AUTOMATIC, RTE_EmTq_APPL_DATA) data);
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
#define Rte_Read_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec Rte_Read_EmTq_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec
#define Rte_Read_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs Rte_Read_EmTq_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs
#define Rte_Read_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir Rte_Read_EmTq_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir
#define Rte_Read_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt Rte_Read_EmTq_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt
#define Rte_Read_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt Rte_Read_EmTq_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt
#define Rte_Read_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt Rte_Read_EmTq_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt
#define Rte_Read_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt Rte_Read_EmTq_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt
#define Rte_Read_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt Rte_Read_EmTq_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt
#define Rte_Read_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt Rte_Read_EmTq_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt
#define Rte_Read_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr Rte_Read_EmTq_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr
#define Rte_Read_ExtTqDes_tqFric_ExtTqDes_tqFric Rte_Read_EmTq_ExtTqDes_tqFric_ExtTqDes_tqFric
#define Rte_Read_IdqAct_iDaFiltd_IdqAct_iDaFiltd Rte_Read_EmTq_IdqAct_iDaFiltd_IdqAct_iDaFiltd
#define Rte_Read_IdqAct_iQaFiltd_IdqAct_iQaFiltd Rte_Read_EmTq_IdqAct_iQaFiltd_IdqAct_iQaFiltd
#define Rte_Read_IdqAct_iSqrt_IdqAct_iSqrt Rte_Read_EmTq_IdqAct_iSqrt_IdqAct_iSqrt
#define Rte_Read_IdqDes_indtQaSubtDa_IdqDes_indtQaSubtDa Rte_Read_EmTq_IdqDes_indtQaSubtDa_IdqDes_indtQaSubtDa
#define Rte_Read_IdqDes_mflxExct_IdqDes_mflxExct Rte_Read_EmTq_IdqDes_mflxExct_IdqDes_mflxExct
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
#define Rte_Write_EmTq_tqEm_EmTq_tqEm Rte_Write_EmTq_EmTq_tqEm_EmTq_tqEm
#define Rte_Write_EmTq_tqEmFiltd_EmTq_tqEmFiltd Rte_Write_EmTq_EmTq_tqEmFiltd_EmTq_tqEmFiltd
#define Rte_Write_EmTq_tqEmLost_EmTq_tqEmLost Rte_Write_EmTq_EmTq_tqEmLost_EmTq_tqEmLost
#define Rte_Write_EmTq_tqMecl_EmTq_tqMecl Rte_Write_EmTq_EmTq_tqMecl_EmTq_tqMecl
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
FUNC(void, EmTq_CODE) EmTq_Init(void);
FUNC(void, EmTq_CODE) fc_EmTq(void);
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
#endif /* RTE_EMTQ_H_ */
 
 
 

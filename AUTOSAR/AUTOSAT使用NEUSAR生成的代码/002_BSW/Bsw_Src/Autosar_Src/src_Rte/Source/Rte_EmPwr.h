 
/*
************************************************************************************************************************
*
* File name: Rte_EmPwr.h
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
#ifndef RTE_EMPWR_H_
#define RTE_EMPWR_H_

#include "Rte_EmPwr_Type.h"
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
extern VAR(Float, RTE_VAR_INIT) Rte_EmPwr_EmPwr_iDCLnk_EmPwr_iDCLnk;
extern VAR(Float, RTE_VAR_INIT) Rte_EmPwr_EmPwr_iDCLnkFiltd_EmPwr_iDCLnkFiltd;
extern VAR(Float, RTE_VAR_INIT) Rte_EmPwr_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(SInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
extern VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iDa_IdqAct_iDa;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iQa_IdqAct_iQa;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uDaPI_IdqCtrl_uDaPI;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uQaPI_IdqCtrl_uQaPI;
extern VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU;
extern VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV;
extern VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW;
extern VAR(Float, RTE_VAR_INIT) Rte_VoltModlnGen_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU;
extern VAR(Float, RTE_VAR_INIT) Rte_VoltModlnGen_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV;
extern VAR(Float, RTE_VAR_INIT) Rte_VoltModlnGen_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_EmPwr_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EmPwr_EmPwr_iDCLnk_EmPwr_iDCLnk(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EmPwr_EmPwr_iDCLnkFiltd_EmPwr_iDCLnkFiltd(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EmPwr_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_IdqAct_iDa_IdqAct_iDa(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_IdqAct_iQa_IdqAct_iQa(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_IdqCtrl_uDaPI_IdqCtrl_uDaPI(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_IdqCtrl_uQaPI_IdqCtrl_uQaPI(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EmPwr_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW(P2VAR(Float, AUTOMATIC, RTE_EmPwr_APPL_DATA) data);
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
#define Rte_Read_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd Rte_Read_EmPwr_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd
#define Rte_Read_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd Rte_Read_EmPwr_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd
#define Rte_Read_IdqAct_iDa_IdqAct_iDa Rte_Read_EmPwr_IdqAct_iDa_IdqAct_iDa
#define Rte_Read_IdqAct_iQa_IdqAct_iQa Rte_Read_EmPwr_IdqAct_iQa_IdqAct_iQa
#define Rte_Read_IdqCtrl_uDaPI_IdqCtrl_uDaPI Rte_Read_EmPwr_IdqCtrl_uDaPI_IdqCtrl_uDaPI
#define Rte_Read_IdqCtrl_uQaPI_IdqCtrl_uQaPI Rte_Read_EmPwr_IdqCtrl_uQaPI_IdqCtrl_uQaPI
#define Rte_Read_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU Rte_Read_EmPwr_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU
#define Rte_Read_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV Rte_Read_EmPwr_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV
#define Rte_Read_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW Rte_Read_EmPwr_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW
#define Rte_Read_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd Rte_Read_EmPwr_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd
#define Rte_Read_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU Rte_Read_EmPwr_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU
#define Rte_Read_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV Rte_Read_EmPwr_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV
#define Rte_Read_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW Rte_Read_EmPwr_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW
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
#define Rte_Write_EmPwr_iDCLnk_EmPwr_iDCLnk Rte_Write_EmPwr_EmPwr_iDCLnk_EmPwr_iDCLnk
#define Rte_Write_EmPwr_iDCLnkFiltd_EmPwr_iDCLnkFiltd Rte_Write_EmPwr_EmPwr_iDCLnkFiltd_EmPwr_iDCLnkFiltd
#define Rte_Write_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk Rte_Write_EmPwr_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk
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
FUNC(void, EmPwr_CODE) EmPwr_Init(void);
FUNC(void, EmPwr_CODE) fc_EmPwr(void);
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
#endif /* RTE_EMPWR_H_ */
 
 
 

 
/*
************************************************************************************************************************
*
* File name: Rte_AngOfstCal.h
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
#ifndef RTE_ANGOFSTCAL_H_
#define RTE_ANGOFSTCAL_H_

#include "Rte_AngOfstCal_Type.h"
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
extern VAR(Float, RTE_VAR_INIT) Rte_AngOfstCal_AngOfstCal_agOfst_AngOfstCal_agOfst;
extern VAR(Float, RTE_VAR_INIT) Rte_AngOfstCal_AngOfstCal_stOfstCalFns_AngOfstCal_stOfstCalFns;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_AngOfstCal_AngOfstCal_iDaDes_AngOfstCal_iDaDes;
extern VAR(Float, RTE_VAR_INIT) Rte_AngOfstCal_AngOfstCal_iQaDes_AngOfstCal_iQaDes;
extern VAR(SInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uDaPI_IdqCtrl_uDaPI;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uQaPI_IdqCtrl_uQaPI;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngOfstCal_AngOfstCal_agOfst_AngOfstCal_agOfst(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngOfstCal_AngOfstCal_iDaDes_AngOfstCal_iDaDes(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngOfstCal_AngOfstCal_iQaDes_AngOfstCal_iQaDes(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngOfstCal_AngOfstCal_stOfstCalFns_AngOfstCal_stOfstCalFns(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngOfstCal_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_AngOfstCal_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngOfstCal_IdqCtrl_uDaPI_IdqCtrl_uDaPI(P2VAR(Float, AUTOMATIC, RTE_AngOfstCal_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngOfstCal_IdqCtrl_uQaPI_IdqCtrl_uQaPI(P2VAR(Float, AUTOMATIC, RTE_AngOfstCal_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngOfstCal_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_AngOfstCal_APPL_DATA) data);
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
#define Rte_Read_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd Rte_Read_AngOfstCal_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd
#define Rte_Read_IdqCtrl_uDaPI_IdqCtrl_uDaPI Rte_Read_AngOfstCal_IdqCtrl_uDaPI_IdqCtrl_uDaPI
#define Rte_Read_IdqCtrl_uQaPI_IdqCtrl_uQaPI Rte_Read_AngOfstCal_IdqCtrl_uQaPI_IdqCtrl_uQaPI
#define Rte_Read_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta Rte_Read_AngOfstCal_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta
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
#define Rte_Write_AngOfstCal_agOfst_AngOfstCal_agOfst Rte_Write_AngOfstCal_AngOfstCal_agOfst_AngOfstCal_agOfst
#define Rte_Write_AngOfstCal_iDaDes_AngOfstCal_iDaDes Rte_Write_AngOfstCal_AngOfstCal_iDaDes_AngOfstCal_iDaDes
#define Rte_Write_AngOfstCal_iQaDes_AngOfstCal_iQaDes Rte_Write_AngOfstCal_AngOfstCal_iQaDes_AngOfstCal_iQaDes
#define Rte_Write_AngOfstCal_stOfstCalFns_AngOfstCal_stOfstCalFns Rte_Write_AngOfstCal_AngOfstCal_stOfstCalFns_AngOfstCal_stOfstCalFns
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
FUNC(void, AngOfstCal_CODE) AngOfstCal_Init(void);
FUNC(void, AngOfstCal_CODE) fc_AngOfstCal(void);
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
#endif /* RTE_ANGOFSTCAL_H_ */
 
 
 

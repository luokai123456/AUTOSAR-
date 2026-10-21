 
/*
************************************************************************************************************************
*
* File name: Rte_AntiRollBack.h
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
#ifndef RTE_ANTIROLLBACK_H_
#define RTE_ANTIROLLBACK_H_

#include "Rte_AntiRollBack_Type.h"
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_AntiRollBack_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv;
extern VAR(Float, RTE_VAR_INIT) Rte_AntiRollBack_AntiRollBack_tqCmdAntiRoll_AntiRollBack_tqCmdAntiRoll;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stDrvGear_ComRx_stDrvGear;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(SInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_stMcuFltLvl_Diag_stMcuFltLvl;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stBrkSwt_ComRx_stBrkSwt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stHndbrk_ComRx_stHndbrk;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tqDes_ComRx_tqDes;
extern VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhyMot_TempDev_tPhyMot;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AntiRollBack_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AntiRollBack_AntiRollBack_tqCmdAntiRoll_AntiRollBack_tqCmdAntiRoll(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq(P2VAR(Boolean, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_ComRx_stBrkSwt_ComRx_stBrkSwt(P2VAR(Boolean, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_ComRx_stDrvGear_ComRx_stDrvGear(P2VAR(UInt8, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_ComRx_stHndbrk_ComRx_stHndbrk(P2VAR(Boolean, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_ComRx_tqDes_ComRx_tqDes(P2VAR(Float, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_Diag_stMcuFltLvl_Diag_stMcuFltLvl(P2VAR(UInt8, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AntiRollBack_TempDev_tPhyMot_TempDev_tPhyMot(P2VAR(Float, AUTOMATIC, RTE_AntiRollBack_APPL_DATA) data);
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
#define Rte_Read_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd Rte_Read_AntiRollBack_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd
#define Rte_Read_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq Rte_Read_AntiRollBack_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq
#define Rte_Read_ComRx_stBrkSwt_ComRx_stBrkSwt Rte_Read_AntiRollBack_ComRx_stBrkSwt_ComRx_stBrkSwt
#define Rte_Read_ComRx_stDrvGear_ComRx_stDrvGear Rte_Read_AntiRollBack_ComRx_stDrvGear_ComRx_stDrvGear
#define Rte_Read_ComRx_stHndbrk_ComRx_stHndbrk Rte_Read_AntiRollBack_ComRx_stHndbrk_ComRx_stHndbrk
#define Rte_Read_ComRx_tqDes_ComRx_tqDes Rte_Read_AntiRollBack_ComRx_tqDes_ComRx_tqDes
#define Rte_Read_Diag_stMcuFltLvl_Diag_stMcuFltLvl Rte_Read_AntiRollBack_Diag_stMcuFltLvl_Diag_stMcuFltLvl
#define Rte_Read_TempDev_tPhyMot_TempDev_tPhyMot Rte_Read_AntiRollBack_TempDev_tPhyMot_TempDev_tPhyMot
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
#define Rte_Write_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv Rte_Write_AntiRollBack_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv
#define Rte_Write_AntiRollBack_tqCmdAntiRoll_AntiRollBack_tqCmdAntiRoll Rte_Write_AntiRollBack_AntiRollBack_tqCmdAntiRoll_AntiRollBack_tqCmdAntiRoll
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
FUNC(void, AntiRollBack_CODE) AntiRollBack_Init(void);
FUNC(void, AntiRollBack_CODE) fc_AntiRollBack(void);
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
#endif /* RTE_ANTIROLLBACK_H_ */
 
 
 

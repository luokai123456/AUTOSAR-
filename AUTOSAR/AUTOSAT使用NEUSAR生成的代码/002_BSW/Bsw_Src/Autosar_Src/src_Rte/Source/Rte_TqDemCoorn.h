 
/*
************************************************************************************************************************
*
* File name: Rte_TqDemCoorn.h
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
#ifndef RTE_TQDEMCOORN_H_
#define RTE_TQDEMCOORN_H_

#include "Rte_TqDemCoorn_Type.h"
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_TqDemCoorn_TqDemCoorn_bTqCrosZrActv_TqDemCoorn_bTqCrosZrActv;
extern VAR(Float, RTE_VAR_INIT) Rte_ActvDampg_ActvDampg_tqDampgCalc_ActvDampg_tqDampgCalc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_AntiRollBack_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv;
extern VAR(Float, RTE_VAR_INIT) Rte_AntiRollBack_AntiRollBack_tqCmdAntiRoll_AntiRollBack_tqCmdAntiRoll;
extern VAR(Float, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_tqEmMax_DernCoorn_tqEmMax;
extern VAR(Float, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_tqEmMin_DernCoorn_tqEmMin;
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_bCurrDernCtrl_DernEm_bCurrDernCtrl;
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_facDernCurr_DernEm_facDernCurr;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_TqDemCoorn_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd;
extern VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_ActvDampg_tqDampgCalc_ActvDampg_tqDampgCalc(P2VAR(Float, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs(P2VAR(UInt16, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_AntiRollBack_AntiRollCnt_AntiRollBack_AntiRollCnt(P2VAR(UInt8, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv(P2VAR(Boolean, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_AntiRollBack_tqCmdAntiRoll_AntiRollBack_tqCmdAntiRoll(P2VAR(Float, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_DernCoorn_tqEmMax_DernCoorn_tqEmMax(P2VAR(Float, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_DernCoorn_tqEmMin_DernCoorn_tqEmMin(P2VAR(Float, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_DernEm_bCurrDernCtrl_DernEm_bCurrDernCtrl(P2VAR(Float, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_DernEm_facDernCurr_DernEm_facDernCurr(P2VAR(Float, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr(P2VAR(UInt8, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg(P2VAR(Float, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqDemCoorn_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_TqDemCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TqDemCoorn_TqDemCoorn_bTqCrosZrActv_TqDemCoorn_bTqCrosZrActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TqDemCoorn_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd(Float data);
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
#define Rte_Read_ActvDampg_tqDampgCalc_ActvDampg_tqDampgCalc Rte_Read_TqDemCoorn_ActvDampg_tqDampgCalc_ActvDampg_tqDampgCalc
#define Rte_Read_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs Rte_Read_TqDemCoorn_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs
#define Rte_Read_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv Rte_Read_TqDemCoorn_AntiRollBack_bAntiRollActv_AntiRollBack_bAntiRollActv
#define Rte_Read_AntiRollBack_tqCmdAntiRoll_AntiRollBack_tqCmdAntiRoll Rte_Read_TqDemCoorn_AntiRollBack_tqCmdAntiRoll_AntiRollBack_tqCmdAntiRoll
#define Rte_Read_DernCoorn_tqEmMax_DernCoorn_tqEmMax Rte_Read_TqDemCoorn_DernCoorn_tqEmMax_DernCoorn_tqEmMax
#define Rte_Read_DernCoorn_tqEmMin_DernCoorn_tqEmMin Rte_Read_TqDemCoorn_DernCoorn_tqEmMin_DernCoorn_tqEmMin
#define Rte_Read_DernEm_bCurrDernCtrl_DernEm_bCurrDernCtrl Rte_Read_TqDemCoorn_DernEm_bCurrDernCtrl_DernEm_bCurrDernCtrl
#define Rte_Read_DernEm_facDernCurr_DernEm_facDernCurr Rte_Read_TqDemCoorn_DernEm_facDernCurr_DernEm_facDernCurr
#define Rte_Read_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr Rte_Read_TqDemCoorn_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr
#define Rte_Read_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg Rte_Read_TqDemCoorn_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg
#define Rte_Read_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta Rte_Read_TqDemCoorn_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta
#define Rte_Read_AntiRollBack_AntiRollCnt_AntiRollBack_AntiRollCnt Rte_Read_TqDemCoorn_AntiRollBack_AntiRollCnt_AntiRollBack_AntiRollCnt
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
#define Rte_Write_TqDemCoorn_bTqCrosZrActv_TqDemCoorn_bTqCrosZrActv Rte_Write_TqDemCoorn_TqDemCoorn_bTqCrosZrActv_TqDemCoorn_bTqCrosZrActv
#define Rte_Write_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd Rte_Write_TqDemCoorn_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd
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
FUNC(void, TqDemCoorn_CODE) TqDemCoorn_Init(void);
FUNC(void, TqDemCoorn_CODE) fc_TqDemCoorn(void);
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
#endif /* RTE_TQDEMCOORN_H_ */
 
 
 

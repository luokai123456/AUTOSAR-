 
/*
************************************************************************************************************************
*
* File name: Rte_ExtTqDes.h
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
#ifndef RTE_EXTTQDES_H_
#define RTE_EXTTQDES_H_

#include "Rte_ExtTqDes_Type.h"
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_bMaxLimActv_ExtTqDes_bMaxLimActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_bMinLimActv_ExtTqDes_bMinLimActv;
extern VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqEmDes_ExtTqDes_tqEmDes;
extern VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqEmMax_ExtTqDes_tqEmMax;
extern VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqEmMin_ExtTqDes_tqEmMin;
extern VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqFric_ExtTqDes_tqFric;
extern VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqPwrDcLnk_ExtTqDes_tqPwrDcLnk;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_facTqSlopMax_ComRx_facTqSlopMax;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_iEfcDes_ComRx_iEfcDes;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stDrvCtrlDes_ComRx_stDrvCtrlDes;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stDrvGear_ComRx_stDrvGear;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tqMaxLim_ComRx_tqMaxLim;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tqMinLim_ComRx_tqMinLim;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_uDCLnkDes_ComRx_uDCLnkDes;
extern VAR(Float, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_tqEmMax_DernCoorn_tqEmMax;
extern VAR(Float, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_tqEmMin_DernCoorn_tqEmMin;
extern VAR(Float, RTE_VAR_INIT) Rte_EmPwr_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd;
extern VAR(SInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
extern VAR(SInt8, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir;
extern VAR(Boolean, RTE_VAR_INIT) Rte_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr;
extern VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
extern VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_bHvRdy_ExtTqDes_bHvRdy;
extern VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg;
extern VAR(SInt16, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_nDes_ComRx_nDes;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tqDes_ComRx_tqDes;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir(P2VAR(SInt8, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_facTqSlopMax_ComRx_facTqSlopMax(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_iEfcDes_ComRx_iEfcDes(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_nDes_ComRx_nDes(P2VAR(SInt16, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_stDrvCtrlDes_ComRx_stDrvCtrlDes(P2VAR(UInt8, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_stDrvGear_ComRx_stDrvGear(P2VAR(UInt8, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_tqDes_ComRx_tqDes(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_tqMaxLim_ComRx_tqMaxLim(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_tqMinLim_ComRx_tqMinLim(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_ComRx_uDCLnkDes_ComRx_uDCLnkDes(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_DernCoorn_tqEmMax_DernCoorn_tqEmMax(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_DernCoorn_tqEmMin_DernCoorn_tqEmMin(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr(P2VAR(Boolean, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_bHvRdy_ExtTqDes_bHvRdy(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_bMaxLimActv_ExtTqDes_bMaxLimActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_bMinLimActv_ExtTqDes_bMinLimActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_tqEmDes_ExtTqDes_tqEmDes(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_tqEmMax_ExtTqDes_tqEmMax(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_tqEmMin_ExtTqDes_tqEmMin(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_tqFric_ExtTqDes_tqFric(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ExtTqDes_ExtTqDes_tqPwrDcLnk_ExtTqDes_tqPwrDcLnk(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd(P2VAR(Float, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ExtTqDes_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_ExtTqDes_APPL_DATA) data);
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
#define Rte_Read_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd Rte_Read_ExtTqDes_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd
#define Rte_Read_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd Rte_Read_ExtTqDes_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd
#define Rte_Read_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir Rte_Read_ExtTqDes_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir
#define Rte_Read_ComRx_facTqSlopMax_ComRx_facTqSlopMax Rte_Read_ExtTqDes_ComRx_facTqSlopMax_ComRx_facTqSlopMax
#define Rte_Read_ComRx_iEfcDes_ComRx_iEfcDes Rte_Read_ExtTqDes_ComRx_iEfcDes_ComRx_iEfcDes
#define Rte_Read_ComRx_nDes_ComRx_nDes Rte_Read_ExtTqDes_ComRx_nDes_ComRx_nDes
#define Rte_Read_ComRx_stDrvCtrlDes_ComRx_stDrvCtrlDes Rte_Read_ExtTqDes_ComRx_stDrvCtrlDes_ComRx_stDrvCtrlDes
#define Rte_Read_ComRx_stDrvGear_ComRx_stDrvGear Rte_Read_ExtTqDes_ComRx_stDrvGear_ComRx_stDrvGear
#define Rte_Read_ComRx_tqDes_ComRx_tqDes Rte_Read_ExtTqDes_ComRx_tqDes_ComRx_tqDes
#define Rte_Read_ComRx_tqMaxLim_ComRx_tqMaxLim Rte_Read_ExtTqDes_ComRx_tqMaxLim_ComRx_tqMaxLim
#define Rte_Read_ComRx_tqMinLim_ComRx_tqMinLim Rte_Read_ExtTqDes_ComRx_tqMinLim_ComRx_tqMinLim
#define Rte_Read_ComRx_uDCLnkDes_ComRx_uDCLnkDes Rte_Read_ExtTqDes_ComRx_uDCLnkDes_ComRx_uDCLnkDes
#define Rte_Read_DernCoorn_tqEmMax_DernCoorn_tqEmMax Rte_Read_ExtTqDes_DernCoorn_tqEmMax_DernCoorn_tqEmMax
#define Rte_Read_DernCoorn_tqEmMin_DernCoorn_tqEmMin Rte_Read_ExtTqDes_DernCoorn_tqEmMin_DernCoorn_tqEmMin
#define Rte_Read_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr Rte_Read_ExtTqDes_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr
#define Rte_Read_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk Rte_Read_ExtTqDes_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk
#define Rte_Read_HvInvDev_uPhyHV_HvInvDev_uPhyHV Rte_Read_ExtTqDes_HvInvDev_uPhyHV_HvInvDev_uPhyHV
#define Rte_Read_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd Rte_Read_ExtTqDes_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd
#define Rte_Read_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd Rte_Read_ExtTqDes_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd
#define Rte_Read_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta Rte_Read_ExtTqDes_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta
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
#define Rte_Write_ExtTqDes_bHvRdy_ExtTqDes_bHvRdy Rte_Write_ExtTqDes_ExtTqDes_bHvRdy_ExtTqDes_bHvRdy
#define Rte_Write_ExtTqDes_bMaxLimActv_ExtTqDes_bMaxLimActv Rte_Write_ExtTqDes_ExtTqDes_bMaxLimActv_ExtTqDes_bMaxLimActv
#define Rte_Write_ExtTqDes_bMinLimActv_ExtTqDes_bMinLimActv Rte_Write_ExtTqDes_ExtTqDes_bMinLimActv_ExtTqDes_bMinLimActv
#define Rte_Write_ExtTqDes_tqEmDes_ExtTqDes_tqEmDes Rte_Write_ExtTqDes_ExtTqDes_tqEmDes_ExtTqDes_tqEmDes
#define Rte_Write_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg Rte_Write_ExtTqDes_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg
#define Rte_Write_ExtTqDes_tqEmMax_ExtTqDes_tqEmMax Rte_Write_ExtTqDes_ExtTqDes_tqEmMax_ExtTqDes_tqEmMax
#define Rte_Write_ExtTqDes_tqEmMin_ExtTqDes_tqEmMin Rte_Write_ExtTqDes_ExtTqDes_tqEmMin_ExtTqDes_tqEmMin
#define Rte_Write_ExtTqDes_tqFric_ExtTqDes_tqFric Rte_Write_ExtTqDes_ExtTqDes_tqFric_ExtTqDes_tqFric
#define Rte_Write_ExtTqDes_tqPwrDcLnk_ExtTqDes_tqPwrDcLnk Rte_Write_ExtTqDes_ExtTqDes_tqPwrDcLnk_ExtTqDes_tqPwrDcLnk
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
FUNC(void, ExtTqDes_CODE) ExtTqDes_Init(void);
FUNC(void, ExtTqDes_CODE) fc_ExtTqDes(void);
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
#endif /* RTE_EXTTQDES_H_ */
 
 
 

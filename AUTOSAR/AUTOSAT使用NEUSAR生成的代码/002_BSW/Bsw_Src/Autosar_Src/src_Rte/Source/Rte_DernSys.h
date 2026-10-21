 
/*
************************************************************************************************************************
*
* File name: Rte_DernSys.h
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
#ifndef RTE_DERNSYS_H_
#define RTE_DERNSYS_H_

#include "Rte_DernSys_Type.h"
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernSys_DernSys_bIdcGenLimActv_DernSys_bIdcGenLimActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernSys_DernSys_bIdcMotLimActv_DernSys_bIdcMotLimActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernSys_DernSys_bSpdOverLimActv_DernSys_bSpdOverLimActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernSys_DernSys_bUdcOverTqLimActv_DernSys_bUdcOverTqLimActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernSys_DernSys_bUdcOverTqLimZeroActv_DernSys_bUdcOverTqLimZeroActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernSys_DernSys_bUdcUnderTqLim_DernSys_bUdcUnderTqLim;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernSys_DernSys_bUdcUnderTqLimZero_DernSys_bUdcUnderTqLimZero;
extern VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_facAntiSlipDern_DernSys_facAntiSlipDern;
extern VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_facGenSpdOverLim_DernSys_facGenSpdOverLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_facGenUdcLim_DernSys_facGenUdcLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_facMotSpdOverLim_DernSys_facMotSpdOverLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_facMotUdcLim_DernSys_facMotUdcLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_pwrGenIdcLim_DernSys_pwrGenIdcLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_pwrMotIdcLim_DernSys_pwrMotIdcLim;
extern VAR(Float, RTE_VAR_INIT) Rte_EmPwr_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(SInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
extern VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernSys_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_DernSys_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_bIdcGenLimActv_DernSys_bIdcGenLimActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_bIdcMotLimActv_DernSys_bIdcMotLimActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_bSpdOverLimActv_DernSys_bSpdOverLimActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_bUdcOverTqLimActv_DernSys_bUdcOverTqLimActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_bUdcOverTqLimZeroActv_DernSys_bUdcOverTqLimZeroActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_bUdcUnderTqLim_DernSys_bUdcUnderTqLim(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_bUdcUnderTqLimZero_DernSys_bUdcUnderTqLimZero(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_facAntiSlipDern_DernSys_facAntiSlipDern(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_facGenSpdOverLim_DernSys_facGenSpdOverLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_facGenUdcLim_DernSys_facGenUdcLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_facMotSpdOverLim_DernSys_facMotSpdOverLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_facMotUdcLim_DernSys_facMotUdcLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_pwrGenIdcLim_DernSys_pwrGenIdcLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernSys_DernSys_pwrMotIdcLim_DernSys_pwrMotIdcLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernSys_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk(P2VAR(Float, AUTOMATIC, RTE_DernSys_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernSys_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd(P2VAR(Float, AUTOMATIC, RTE_DernSys_APPL_DATA) data);
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
#define Rte_Read_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd Rte_Read_DernSys_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd
#define Rte_Read_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk Rte_Read_DernSys_EmPwr_pwrDCLnk_EmPwr_pwrDCLnk
#define Rte_Read_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd Rte_Read_DernSys_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd
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
#define Rte_Write_DernSys_bIdcGenLimActv_DernSys_bIdcGenLimActv Rte_Write_DernSys_DernSys_bIdcGenLimActv_DernSys_bIdcGenLimActv
#define Rte_Write_DernSys_bIdcMotLimActv_DernSys_bIdcMotLimActv Rte_Write_DernSys_DernSys_bIdcMotLimActv_DernSys_bIdcMotLimActv
#define Rte_Write_DernSys_bSpdOverLimActv_DernSys_bSpdOverLimActv Rte_Write_DernSys_DernSys_bSpdOverLimActv_DernSys_bSpdOverLimActv
#define Rte_Write_DernSys_bUdcOverTqLimActv_DernSys_bUdcOverTqLimActv Rte_Write_DernSys_DernSys_bUdcOverTqLimActv_DernSys_bUdcOverTqLimActv
#define Rte_Write_DernSys_bUdcOverTqLimZeroActv_DernSys_bUdcOverTqLimZeroActv Rte_Write_DernSys_DernSys_bUdcOverTqLimZeroActv_DernSys_bUdcOverTqLimZeroActv
#define Rte_Write_DernSys_bUdcUnderTqLim_DernSys_bUdcUnderTqLim Rte_Write_DernSys_DernSys_bUdcUnderTqLim_DernSys_bUdcUnderTqLim
#define Rte_Write_DernSys_bUdcUnderTqLimZero_DernSys_bUdcUnderTqLimZero Rte_Write_DernSys_DernSys_bUdcUnderTqLimZero_DernSys_bUdcUnderTqLimZero
#define Rte_Write_DernSys_facAntiSlipDern_DernSys_facAntiSlipDern Rte_Write_DernSys_DernSys_facAntiSlipDern_DernSys_facAntiSlipDern
#define Rte_Write_DernSys_facGenSpdOverLim_DernSys_facGenSpdOverLim Rte_Write_DernSys_DernSys_facGenSpdOverLim_DernSys_facGenSpdOverLim
#define Rte_Write_DernSys_facGenUdcLim_DernSys_facGenUdcLim Rte_Write_DernSys_DernSys_facGenUdcLim_DernSys_facGenUdcLim
#define Rte_Write_DernSys_facMotSpdOverLim_DernSys_facMotSpdOverLim Rte_Write_DernSys_DernSys_facMotSpdOverLim_DernSys_facMotSpdOverLim
#define Rte_Write_DernSys_facMotUdcLim_DernSys_facMotUdcLim Rte_Write_DernSys_DernSys_facMotUdcLim_DernSys_facMotUdcLim
#define Rte_Write_DernSys_pwrGenIdcLim_DernSys_pwrGenIdcLim Rte_Write_DernSys_DernSys_pwrGenIdcLim_DernSys_pwrGenIdcLim
#define Rte_Write_DernSys_pwrMotIdcLim_DernSys_pwrMotIdcLim Rte_Write_DernSys_DernSys_pwrMotIdcLim_DernSys_pwrMotIdcLim
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
FUNC(void, DernSys_CODE) DernSys_Init(void);
FUNC(void, DernSys_CODE) fc_DernSys(void);
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
#endif /* RTE_DERNSYS_H_ */
 
 
 

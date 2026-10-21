 
/*
************************************************************************************************************************
*
* File name: Rte_DernCoorn.h
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
#ifndef RTE_DERNCOORN_H_
#define RTE_DERNCOORN_H_

#include "Rte_DernCoorn_Type.h"
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
extern VAR(UInt8, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_stPwrMaxLimCoord_DernCoorn_stPwrMaxLimCoord;
extern VAR(UInt8, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_stPwrMinLimCoord_DernCoorn_stPwrMinLimCoord;
extern VAR(UInt8, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_stTqEmGenCoord_DernCoorn_stTqEmGenCoord;
extern VAR(UInt8, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_stTqEmMotCoord_DernCoorn_stTqEmMotCoord;
extern VAR(Float, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_tqEmMax_DernCoorn_tqEmMax;
extern VAR(Float, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_tqEmMin_DernCoorn_tqEmMin;
extern VAR(Float, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_tqMeclMax_DernCoorn_tqMeclMax;
extern VAR(Float, RTE_VAR_INIT) Rte_DernCoorn_DernCoorn_tqMeclMin_DernCoorn_tqMeclMin;
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_facGenTempRtrLim_DernEm_facGenTempRtrLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_facGenTempStrLim_DernEm_facGenTempStrLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_facMotTempRtrLim_DernEm_facMotTempRtrLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_facMotTempStrLim_DernEm_facMotTempStrLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_tqGenExtChartcLim_DernEm_tqGenExtChartcLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_tqMotExtChartcLim_DernEm_tqMotExtChartcLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facGenTempIvtrCooltLim_DernInv_facGenTempIvtrCooltLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facGenTempSicLim_DernInv_facGenTempSicLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facGeniSqrtLim_DernInv_facGeniSqrtLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facMotTempIvtrCooltLim_DernInv_facMotTempIvtrCooltLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facMotTempSicLim_DernInv_facMotTempSicLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facMotiSqrtLim_DernInv_facMotiSqrtLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_facAntiSlipDern_DernSys_facAntiSlipDern;
extern VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_facGenSpdOverLim_DernSys_facGenSpdOverLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_facGenUdcLim_DernSys_facGenUdcLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_facMotSpdOverLim_DernSys_facMotSpdOverLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_facMotUdcLim_DernSys_facMotUdcLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_pwrGenIdcLim_DernSys_pwrGenIdcLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernSys_DernSys_pwrMotIdcLim_DernSys_pwrMotIdcLim;
extern VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqEmMax_ExtTqDes_tqEmMax;
extern VAR(Float, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_tqEmMin_ExtTqDes_tqEmMin;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec;
extern VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd;
extern VAR(UInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_facDiagTqDern_Diag_facDiagTqDern;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs(P2VAR(UInt16, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_stPwrMaxLimCoord_DernCoorn_stPwrMaxLimCoord(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_stPwrMinLimCoord_DernCoorn_stPwrMinLimCoord(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_stTqEmGenCoord_DernCoorn_stTqEmGenCoord(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_stTqEmMotCoord_DernCoorn_stTqEmMotCoord(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_tqEmMax_DernCoorn_tqEmMax(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_tqEmMin_DernCoorn_tqEmMin(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_tqMeclMax_DernCoorn_tqMeclMax(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernCoorn_DernCoorn_tqMeclMin_DernCoorn_tqMeclMin(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernEm_facGenTempRtrLim_DernEm_facGenTempRtrLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernEm_facGenTempStrLim_DernEm_facGenTempStrLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernEm_facMotTempRtrLim_DernEm_facMotTempRtrLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernEm_facMotTempStrLim_DernEm_facMotTempStrLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernEm_tqGenExtChartcLim_DernEm_tqGenExtChartcLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernEm_tqMotExtChartcLim_DernEm_tqMotExtChartcLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernInv_facGenTempIvtrCooltLim_DernInv_facGenTempIvtrCooltLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernInv_facGenTempSicLim_DernInv_facGenTempSicLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernInv_facGeniSqrtLim_DernInv_facGeniSqrtLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernInv_facMotTempIvtrCooltLim_DernInv_facMotTempIvtrCooltLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernInv_facMotTempSicLim_DernInv_facMotTempSicLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernInv_facMotiSqrtLim_DernInv_facMotiSqrtLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernSys_facAntiSlipDern_DernSys_facAntiSlipDern(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernSys_facGenSpdOverLim_DernSys_facGenSpdOverLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernSys_facGenUdcLim_DernSys_facGenUdcLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernSys_facMotSpdOverLim_DernSys_facMotSpdOverLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernSys_facMotUdcLim_DernSys_facMotUdcLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernSys_pwrGenIdcLim_DernSys_pwrGenIdcLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_DernSys_pwrMotIdcLim_DernSys_pwrMotIdcLim(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_Diag_facDiagTqDern_Diag_facDiagTqDern(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr(P2VAR(UInt8, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_ExtTqDes_tqEmMax_ExtTqDes_tqEmMax(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernCoorn_ExtTqDes_tqEmMin_ExtTqDes_tqEmMin(P2VAR(Float, AUTOMATIC, RTE_DernCoorn_APPL_DATA) data);
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
#define Rte_Read_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec Rte_Read_DernCoorn_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec
#define Rte_Read_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd Rte_Read_DernCoorn_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd
#define Rte_Read_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs Rte_Read_DernCoorn_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs
#define Rte_Read_DernEm_facGenTempRtrLim_DernEm_facGenTempRtrLim Rte_Read_DernCoorn_DernEm_facGenTempRtrLim_DernEm_facGenTempRtrLim
#define Rte_Read_DernEm_facGenTempStrLim_DernEm_facGenTempStrLim Rte_Read_DernCoorn_DernEm_facGenTempStrLim_DernEm_facGenTempStrLim
#define Rte_Read_DernEm_facMotTempRtrLim_DernEm_facMotTempRtrLim Rte_Read_DernCoorn_DernEm_facMotTempRtrLim_DernEm_facMotTempRtrLim
#define Rte_Read_DernEm_facMotTempStrLim_DernEm_facMotTempStrLim Rte_Read_DernCoorn_DernEm_facMotTempStrLim_DernEm_facMotTempStrLim
#define Rte_Read_DernEm_tqGenExtChartcLim_DernEm_tqGenExtChartcLim Rte_Read_DernCoorn_DernEm_tqGenExtChartcLim_DernEm_tqGenExtChartcLim
#define Rte_Read_DernEm_tqMotExtChartcLim_DernEm_tqMotExtChartcLim Rte_Read_DernCoorn_DernEm_tqMotExtChartcLim_DernEm_tqMotExtChartcLim
#define Rte_Read_DernInv_facGenTempIvtrCooltLim_DernInv_facGenTempIvtrCooltLim Rte_Read_DernCoorn_DernInv_facGenTempIvtrCooltLim_DernInv_facGenTempIvtrCooltLim
#define Rte_Read_DernInv_facGenTempSicLim_DernInv_facGenTempSicLim Rte_Read_DernCoorn_DernInv_facGenTempSicLim_DernInv_facGenTempSicLim
#define Rte_Read_DernInv_facGeniSqrtLim_DernInv_facGeniSqrtLim Rte_Read_DernCoorn_DernInv_facGeniSqrtLim_DernInv_facGeniSqrtLim
#define Rte_Read_DernInv_facMotTempIvtrCooltLim_DernInv_facMotTempIvtrCooltLim Rte_Read_DernCoorn_DernInv_facMotTempIvtrCooltLim_DernInv_facMotTempIvtrCooltLim
#define Rte_Read_DernInv_facMotTempSicLim_DernInv_facMotTempSicLim Rte_Read_DernCoorn_DernInv_facMotTempSicLim_DernInv_facMotTempSicLim
#define Rte_Read_DernInv_facMotiSqrtLim_DernInv_facMotiSqrtLim Rte_Read_DernCoorn_DernInv_facMotiSqrtLim_DernInv_facMotiSqrtLim
#define Rte_Read_DernSys_facAntiSlipDern_DernSys_facAntiSlipDern Rte_Read_DernCoorn_DernSys_facAntiSlipDern_DernSys_facAntiSlipDern
#define Rte_Read_DernSys_facGenSpdOverLim_DernSys_facGenSpdOverLim Rte_Read_DernCoorn_DernSys_facGenSpdOverLim_DernSys_facGenSpdOverLim
#define Rte_Read_DernSys_facGenUdcLim_DernSys_facGenUdcLim Rte_Read_DernCoorn_DernSys_facGenUdcLim_DernSys_facGenUdcLim
#define Rte_Read_DernSys_facMotSpdOverLim_DernSys_facMotSpdOverLim Rte_Read_DernCoorn_DernSys_facMotSpdOverLim_DernSys_facMotSpdOverLim
#define Rte_Read_DernSys_facMotUdcLim_DernSys_facMotUdcLim Rte_Read_DernCoorn_DernSys_facMotUdcLim_DernSys_facMotUdcLim
#define Rte_Read_DernSys_pwrGenIdcLim_DernSys_pwrGenIdcLim Rte_Read_DernCoorn_DernSys_pwrGenIdcLim_DernSys_pwrGenIdcLim
#define Rte_Read_DernSys_pwrMotIdcLim_DernSys_pwrMotIdcLim Rte_Read_DernCoorn_DernSys_pwrMotIdcLim_DernSys_pwrMotIdcLim
#define Rte_Read_Diag_facDiagTqDern_Diag_facDiagTqDern Rte_Read_DernCoorn_Diag_facDiagTqDern_Diag_facDiagTqDern
#define Rte_Read_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr Rte_Read_DernCoorn_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr
#define Rte_Read_ExtTqDes_tqEmMax_ExtTqDes_tqEmMax Rte_Read_DernCoorn_ExtTqDes_tqEmMax_ExtTqDes_tqEmMax
#define Rte_Read_ExtTqDes_tqEmMin_ExtTqDes_tqEmMin Rte_Read_DernCoorn_ExtTqDes_tqEmMin_ExtTqDes_tqEmMin
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
#define Rte_Write_DernCoorn_stPwrMaxLimCoord_DernCoorn_stPwrMaxLimCoord Rte_Write_DernCoorn_DernCoorn_stPwrMaxLimCoord_DernCoorn_stPwrMaxLimCoord
#define Rte_Write_DernCoorn_stPwrMinLimCoord_DernCoorn_stPwrMinLimCoord Rte_Write_DernCoorn_DernCoorn_stPwrMinLimCoord_DernCoorn_stPwrMinLimCoord
#define Rte_Write_DernCoorn_stTqEmGenCoord_DernCoorn_stTqEmGenCoord Rte_Write_DernCoorn_DernCoorn_stTqEmGenCoord_DernCoorn_stTqEmGenCoord
#define Rte_Write_DernCoorn_stTqEmMotCoord_DernCoorn_stTqEmMotCoord Rte_Write_DernCoorn_DernCoorn_stTqEmMotCoord_DernCoorn_stTqEmMotCoord
#define Rte_Write_DernCoorn_tqEmMax_DernCoorn_tqEmMax Rte_Write_DernCoorn_DernCoorn_tqEmMax_DernCoorn_tqEmMax
#define Rte_Write_DernCoorn_tqEmMin_DernCoorn_tqEmMin Rte_Write_DernCoorn_DernCoorn_tqEmMin_DernCoorn_tqEmMin
#define Rte_Write_DernCoorn_tqMeclMax_DernCoorn_tqMeclMax Rte_Write_DernCoorn_DernCoorn_tqMeclMax_DernCoorn_tqMeclMax
#define Rte_Write_DernCoorn_tqMeclMin_DernCoorn_tqMeclMin Rte_Write_DernCoorn_DernCoorn_tqMeclMin_DernCoorn_tqMeclMin
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
FUNC(void, DernCoorn_CODE) DernCoorn_Init(void);
FUNC(void, DernCoorn_CODE) fc_DernCoorn(void);
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
#endif /* RTE_DERNCOORN_H_ */
 
 
 

 
/*
************************************************************************************************************************
*
* File name: Rte_AngSwDecod.h
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
#ifndef RTE_ANGSWDECOD_H_
#define RTE_ANGSWDECOD_H_

#include "Rte_AngSwDecod_Type.h"
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
extern VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_agRotate_AngSwDecod_agRotate;
extern VAR(Boolean, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_bSigDegratn_AngSwDecod_bSigDegratn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_bSigLoss_AngSwDecod_bSigLoss;
extern VAR(Boolean, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_bTrckgLoss_AngSwDecod_bTrckgLoss;
extern VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp;
extern VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp;
extern VAR(Float, RTE_VAR_INIT) Rte_AngOfstCal_AngOfstCal_agOfst_AngOfstCal_agOfst;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_agRotateBsw_BIfRx_agRotateBsw;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tiGroupDly_BIfRx_tiGroupDly;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tiStamp_BIfRx_tiStamp;
extern VAR(Float, RTE_VAR_INIT) Rte_DynFrq_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec;
extern VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd;
extern VAR(SInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
extern VAR(UInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs;
extern VAR(SInt8, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_iDaDes_IdqDes_iDaDes;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_iQaDes_IdqDes_iQaDes;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_AngOfstCal_agOfst_AngOfstCal_agOfst(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_agRotate_AngSwDecod_agRotate(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_bSigDegratn_AngSwDecod_bSigDegratn(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_bSigLoss_AngSwDecod_bSigLoss(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_bTrckgLoss_AngSwDecod_bTrckgLoss(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(SInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir(SInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_BIfRx_agRotateBsw_BIfRx_agRotateBsw(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt(P2VAR(Boolean, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt(P2VAR(Boolean, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt(P2VAR(Boolean, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt(P2VAR(Boolean, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_BIfRx_tiGroupDly_BIfRx_tiGroupDly(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_BIfRx_tiStamp_BIfRx_tiStamp(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_IdqDes_iDaDes_IdqDes_iDaDes(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_IdqDes_iQaDes_IdqDes_iQaDes(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data);
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
#define Rte_Read_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp Rte_Read_AngSwDecod_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp
#define Rte_Read_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp Rte_Read_AngSwDecod_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp
#define Rte_Read_AngOfstCal_agOfst_AngOfstCal_agOfst Rte_Read_AngSwDecod_AngOfstCal_agOfst_AngOfstCal_agOfst
#define Rte_Read_BIfRx_agRotateBsw_BIfRx_agRotateBsw Rte_Read_AngSwDecod_BIfRx_agRotateBsw_BIfRx_agRotateBsw
#define Rte_Read_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt Rte_Read_AngSwDecod_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt
#define Rte_Read_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt Rte_Read_AngSwDecod_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt
#define Rte_Read_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt Rte_Read_AngSwDecod_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt
#define Rte_Read_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt Rte_Read_AngSwDecod_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt
#define Rte_Read_BIfRx_tiGroupDly_BIfRx_tiGroupDly Rte_Read_AngSwDecod_BIfRx_tiGroupDly_BIfRx_tiGroupDly
#define Rte_Read_BIfRx_tiStamp_BIfRx_tiStamp Rte_Read_AngSwDecod_BIfRx_tiStamp_BIfRx_tiStamp
#define Rte_Read_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp Rte_Read_AngSwDecod_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp
#define Rte_Read_IdqDes_iDaDes_IdqDes_iDaDes Rte_Read_AngSwDecod_IdqDes_iDaDes_IdqDes_iDaDes
#define Rte_Read_IdqDes_iQaDes_IdqDes_iQaDes Rte_Read_AngSwDecod_IdqDes_iQaDes_IdqDes_iQaDes
#define Rte_Read_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta Rte_Read_AngSwDecod_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta
#define Rte_Read_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd Rte_Read_AngSwDecod_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd
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
#define Rte_Write_AngSwDecod_agRotate_AngSwDecod_agRotate Rte_Write_AngSwDecod_AngSwDecod_agRotate_AngSwDecod_agRotate
#define Rte_Write_AngSwDecod_bSigDegratn_AngSwDecod_bSigDegratn Rte_Write_AngSwDecod_AngSwDecod_bSigDegratn_AngSwDecod_bSigDegratn
#define Rte_Write_AngSwDecod_bSigLoss_AngSwDecod_bSigLoss Rte_Write_AngSwDecod_AngSwDecod_bSigLoss_AngSwDecod_bSigLoss
#define Rte_Write_AngSwDecod_bTrckgLoss_AngSwDecod_bTrckgLoss Rte_Write_AngSwDecod_AngSwDecod_bTrckgLoss_AngSwDecod_bTrckgLoss
#define Rte_Write_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec Rte_Write_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec
#define Rte_Write_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd Rte_Write_AngSwDecod_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd
#define Rte_Write_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd Rte_Write_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd
#define Rte_Write_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs Rte_Write_AngSwDecod_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs
#define Rte_Write_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir Rte_Write_AngSwDecod_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir
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
FUNC(void, AngSwDecod_CODE) AngSwDecod_Init(void);
FUNC(void, AngSwDecod_CODE) fc_AngSwDecod(void);
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
#endif /* RTE_ANGSWDECOD_H_ */
 
 
 

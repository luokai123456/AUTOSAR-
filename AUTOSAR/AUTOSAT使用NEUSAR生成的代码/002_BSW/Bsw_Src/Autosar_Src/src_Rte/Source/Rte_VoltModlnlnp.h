 
/*
************************************************************************************************************************
*
* File name: Rte_VoltModlnlnp.h
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
#ifndef RTE_VOLTMODLNLNP_H_
#define RTE_VOLTMODLNLNP_H_

#include "Rte_VoltModlnlnp_Type.h"
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
extern VAR(Float, RTE_VAR_INIT) Rte_VoltModlnlnp_VoltModlnlnp_uAlpha_VoltModlnlnp_uAlpha;
extern VAR(Float, RTE_VAR_INIT) Rte_VoltModlnlnp_VoltModlnlnp_uAlphaCmp_VoltModlnlnp_uAlphaCmp;
extern VAR(Float, RTE_VAR_INIT) Rte_VoltModlnlnp_VoltModlnlnp_uBeta_VoltModlnlnp_uBeta;
extern VAR(Float, RTE_VAR_INIT) Rte_VoltModlnlnp_VoltModlnlnp_uBetaCmp_VoltModlnlnp_uBetaCmp;
extern VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_agRotate_AngSwDecod_agRotate;
extern VAR(Float, RTE_VAR_INIT) Rte_DynFrq_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uDaSclg_IdqCtrl_uDaSclg;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uQaSclg_IdqCtrl_uQaSclg;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec;
extern VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iDa_IdqAct_iDa;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iQa_IdqAct_iQa;
extern VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU;
extern VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV;
extern VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_AngSwDecod_agRotate_AngSwDecod_agRotate(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_IdqAct_iDa_IdqAct_iDa(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_IdqAct_iQa_IdqAct_iQa(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_IdqCtrl_uDaSclg_IdqCtrl_uDaSclg(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_IdqCtrl_uQaSclg_IdqCtrl_uQaSclg(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_VoltModlnlnp_VoltModlnlnp_uAlpha_VoltModlnlnp_uAlpha(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_VoltModlnlnp_VoltModlnlnp_uAlphaCmp_VoltModlnlnp_uAlphaCmp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_VoltModlnlnp_VoltModlnlnp_uBeta_VoltModlnlnp_uBeta(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_VoltModlnlnp_VoltModlnlnp_uBetaCmp_VoltModlnlnp_uBetaCmp(Float data);
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
#define Rte_Read_AngSwDecod_agRotate_AngSwDecod_agRotate Rte_Read_VoltModlnlnp_AngSwDecod_agRotate_AngSwDecod_agRotate
#define Rte_Read_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec Rte_Read_VoltModlnlnp_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec
#define Rte_Read_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp Rte_Read_VoltModlnlnp_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp
#define Rte_Read_HvInvDev_uPhyHV_HvInvDev_uPhyHV Rte_Read_VoltModlnlnp_HvInvDev_uPhyHV_HvInvDev_uPhyHV
#define Rte_Read_IdqAct_iDa_IdqAct_iDa Rte_Read_VoltModlnlnp_IdqAct_iDa_IdqAct_iDa
#define Rte_Read_IdqAct_iQa_IdqAct_iQa Rte_Read_VoltModlnlnp_IdqAct_iQa_IdqAct_iQa
#define Rte_Read_IdqCtrl_uDaSclg_IdqCtrl_uDaSclg Rte_Read_VoltModlnlnp_IdqCtrl_uDaSclg_IdqCtrl_uDaSclg
#define Rte_Read_IdqCtrl_uQaSclg_IdqCtrl_uQaSclg Rte_Read_VoltModlnlnp_IdqCtrl_uQaSclg_IdqCtrl_uQaSclg
#define Rte_Read_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU Rte_Read_VoltModlnlnp_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU
#define Rte_Read_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV Rte_Read_VoltModlnlnp_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV
#define Rte_Read_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW Rte_Read_VoltModlnlnp_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW
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
#define Rte_Write_VoltModlnlnp_uAlpha_VoltModlnlnp_uAlpha Rte_Write_VoltModlnlnp_VoltModlnlnp_uAlpha_VoltModlnlnp_uAlpha
#define Rte_Write_VoltModlnlnp_uAlphaCmp_VoltModlnlnp_uAlphaCmp Rte_Write_VoltModlnlnp_VoltModlnlnp_uAlphaCmp_VoltModlnlnp_uAlphaCmp
#define Rte_Write_VoltModlnlnp_uBeta_VoltModlnlnp_uBeta Rte_Write_VoltModlnlnp_VoltModlnlnp_uBeta_VoltModlnlnp_uBeta
#define Rte_Write_VoltModlnlnp_uBetaCmp_VoltModlnlnp_uBetaCmp Rte_Write_VoltModlnlnp_VoltModlnlnp_uBetaCmp_VoltModlnlnp_uBetaCmp
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
FUNC(void, VoltModlnlnp_CODE) VoltModlnlnp_Init(void);
FUNC(void, VoltModlnlnp_CODE) fc_VoltModlnInp(void);
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
#endif /* RTE_VOLTMODLNLNP_H_ */
 
 
 

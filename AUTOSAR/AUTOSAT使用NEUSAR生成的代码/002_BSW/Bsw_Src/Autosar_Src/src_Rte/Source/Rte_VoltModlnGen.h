 
/*
************************************************************************************************************************
*
* File name: Rte_VoltModlnGen.h
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
#ifndef RTE_VOLTMODLNGEN_H_
#define RTE_VOLTMODLNGEN_H_

#include "Rte_VoltModlnGen_Type.h"
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
extern VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_bIGBTDrvHBridgFlt_Diag_bIGBTDrvHBridgFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bIGBTDrvLBridgFlt_Diag_bIGBTDrvLBridgFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_VoltModlnlnp_VoltModlnlnp_uAlpha_VoltModlnlnp_uAlpha;
extern VAR(Float, RTE_VAR_INIT) Rte_VoltModlnlnp_VoltModlnlnp_uBeta_VoltModlnlnp_uBeta;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_VoltModlnGen_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU;
extern VAR(Float, RTE_VAR_INIT) Rte_VoltModlnGen_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV;
extern VAR(Float, RTE_VAR_INIT) Rte_VoltModlnGen_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW;
extern VAR(Boolean, RTE_VAR_INIT) Rte_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr;
extern VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnGen_Diag_bIGBTDrvHBridgFlt_Diag_bIGBTDrvHBridgFlt(P2VAR(UInt8, AUTOMATIC, RTE_VoltModlnGen_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnGen_Diag_bIGBTDrvLBridgFlt_Diag_bIGBTDrvLBridgFlt(P2VAR(Float, AUTOMATIC, RTE_VoltModlnGen_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnGen_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr(P2VAR(Boolean, AUTOMATIC, RTE_VoltModlnGen_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnGen_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr(P2VAR(UInt8, AUTOMATIC, RTE_VoltModlnGen_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnGen_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_VoltModlnGen_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_VoltModlnGen_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_VoltModlnGen_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_VoltModlnGen_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnGen_VoltModlnlnp_uAlpha_VoltModlnlnp_uAlpha(P2VAR(Float, AUTOMATIC, RTE_VoltModlnGen_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnGen_VoltModlnlnp_uBeta_VoltModlnlnp_uBeta(P2VAR(Float, AUTOMATIC, RTE_VoltModlnGen_APPL_DATA) data);
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
#define Rte_Read_Diag_bIGBTDrvHBridgFlt_Diag_bIGBTDrvHBridgFlt Rte_Read_VoltModlnGen_Diag_bIGBTDrvHBridgFlt_Diag_bIGBTDrvHBridgFlt
#define Rte_Read_Diag_bIGBTDrvLBridgFlt_Diag_bIGBTDrvLBridgFlt Rte_Read_VoltModlnGen_Diag_bIGBTDrvLBridgFlt_Diag_bIGBTDrvLBridgFlt
#define Rte_Read_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr Rte_Read_VoltModlnGen_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr
#define Rte_Read_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr Rte_Read_VoltModlnGen_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr
#define Rte_Read_HvInvDev_uPhyHV_HvInvDev_uPhyHV Rte_Read_VoltModlnGen_HvInvDev_uPhyHV_HvInvDev_uPhyHV
#define Rte_Read_VoltModlnlnp_uAlpha_VoltModlnlnp_uAlpha Rte_Read_VoltModlnGen_VoltModlnlnp_uAlpha_VoltModlnlnp_uAlpha
#define Rte_Read_VoltModlnlnp_uBeta_VoltModlnlnp_uBeta Rte_Read_VoltModlnGen_VoltModlnlnp_uBeta_VoltModlnlnp_uBeta
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
#define Rte_Write_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU Rte_Write_VoltModlnGen_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU
#define Rte_Write_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV Rte_Write_VoltModlnGen_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV
#define Rte_Write_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW Rte_Write_VoltModlnGen_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW
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
FUNC(void, VoltModlnGen_CODE) VoltModlnGen_Init(void);
FUNC(void, VoltModlnGen_CODE) fc_VoltModlnGen(void);
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
#endif /* RTE_VOLTMODLNGEN_H_ */
 
 
 

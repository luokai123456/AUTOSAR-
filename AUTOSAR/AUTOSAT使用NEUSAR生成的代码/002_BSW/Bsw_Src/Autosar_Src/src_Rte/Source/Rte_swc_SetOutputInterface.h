 
/*
************************************************************************************************************************
*
* File name: Rte_swc_SetOutputInterface.h
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
#ifndef RTE_SWC_SETOUTPUTINTERFACE_H_
#define RTE_SWC_SETOUTPUTINTERFACE_H_

#include "Rte_swc_SetOutputInterface_Type.h"
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
*    declaration of application error code
************************************************************************************************************************
*/

#ifndef RTE_E_Ram_Service_NOT_OK
#define RTE_E_Ram_Service_NOT_OK (1U)
#endif


/*
************************************************************************************************************************
*    extern declaration of RTE buffers
************************************************************************************************************************
*/

#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Mode_Request_shutdown_Request_shutdown;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCL_Request_BCL;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCP_Request_BCP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCPP_Request_BCPP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCS_Request_BCS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCSP_Request_BCSP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BDC_Request_BDC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BEM_Request_BEM;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BHM_Request_BHM;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BMT_Request_BMT;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BMV_Request_BMV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BRM_Request_BRM;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BRO_Request_BRO;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BSD_Request_BSD;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BSM_Request_BSM;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BSP_Request_BSP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BST_Request_BST;
extern VAR(rt_Array_UInt32_9, RTE_VAR_INIT) Rte_swc_COL_BmuControl_BalanceControl_BalanceControl;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Mode_Request_shutdown_Request_shutdown(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BCL_Request_BCL(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BCP_Request_BCP(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BCPP_Request_BCPP(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BCS_Request_BCS(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BCSP_Request_BCSP(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BDC_Request_BDC(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BEM_Request_BEM(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BHM_Request_BHM(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BMT_Request_BMT(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BMV_Request_BMV(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BRM_Request_BRM(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BRO_Request_BRO(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BSD_Request_BSD(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BSM_Request_BSM(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BSP_Request_BSP(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BST_Request_BST(P2VAR(UInt8, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_swc_SetOutputInterface_BmuControl_BalanceControl_BalanceControl(P2VAR(uint32, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) data);
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
#define Rte_Read_BSWIOSP_Mode_Request_shutdown_Request_shutdown Rte_Read_swc_SetOutputInterface_BSWIOSP_Mode_Request_shutdown_Request_shutdown
#define Rte_Read_BSWIOSP_Request_BCL_Request_BCL Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BCL_Request_BCL
#define Rte_Read_BSWIOSP_Request_BCP_Request_BCP Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BCP_Request_BCP
#define Rte_Read_BSWIOSP_Request_BCPP_Request_BCPP Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BCPP_Request_BCPP
#define Rte_Read_BSWIOSP_Request_BCS_Request_BCS Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BCS_Request_BCS
#define Rte_Read_BSWIOSP_Request_BCSP_Request_BCSP Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BCSP_Request_BCSP
#define Rte_Read_BSWIOSP_Request_BDC_Request_BDC Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BDC_Request_BDC
#define Rte_Read_BSWIOSP_Request_BEM_Request_BEM Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BEM_Request_BEM
#define Rte_Read_BSWIOSP_Request_BHM_Request_BHM Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BHM_Request_BHM
#define Rte_Read_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo
#define Rte_Read_BSWIOSP_Request_BMT_Request_BMT Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BMT_Request_BMT
#define Rte_Read_BSWIOSP_Request_BMV_Request_BMV Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BMV_Request_BMV
#define Rte_Read_BSWIOSP_Request_BRM_Request_BRM Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BRM_Request_BRM
#define Rte_Read_BSWIOSP_Request_BRO_Request_BRO Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BRO_Request_BRO
#define Rte_Read_BSWIOSP_Request_BSD_Request_BSD Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BSD_Request_BSD
#define Rte_Read_BSWIOSP_Request_BSM_Request_BSM Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BSM_Request_BSM
#define Rte_Read_BSWIOSP_Request_BSP_Request_BSP Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BSP_Request_BSP
#define Rte_Read_BSWIOSP_Request_BST_Request_BST Rte_Read_swc_SetOutputInterface_BSWIOSP_Request_BST_Request_BST
#define Rte_Read_BmuControl_BalanceControl_BalanceControl Rte_Read_swc_SetOutputInterface_BmuControl_BalanceControl_BalanceControl
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
FUNC(void, swc_SetOutputInterface_CODE) swc_SetOutputInterface_50ms(void);
FUNC(void, swc_SetOutputInterface_CODE) swc_SetOutputInterface_100ms(void);
FUNC(void, swc_SetOutputInterface_CODE) swc_SetOutputInterface_10ms(void);
FUNC(void, swc_SetOutputInterface_CODE) swc_SetOutputInterface_Init(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Operation Invocation Runnable entities
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, swc_SetOutputInterface_CODE) If_DiscreteValueOutput_SetDiscreteValue(VAR(UInt32, RTE_swc_SetOutputInterface_APPL_DATA) NumId, VAR(UInt32, RTE_swc_SetOutputInterface_APPL_DATA) value);
FUNC(void, swc_SetOutputInterface_CODE) If_PwmValueOutput_SetPwmValue(VAR(UInt32, RTE_swc_SetOutputInterface_APPL_DATA) NumId, VAR(UInt32, RTE_swc_SetOutputInterface_APPL_DATA) Period, VAR(UInt32, RTE_swc_SetOutputInterface_APPL_DATA) Ducy);
FUNC(void, swc_SetOutputInterface_CODE) If_SetRtcWakeUp_SetWakeUpTime(VAR(UInt16, RTE_swc_SetOutputInterface_APPL_DATA) minute);
FUNC(Std_ReturnType, swc_SetOutputInterface_CODE) Ram_Service_ReadStatus(VAR(UInt32_T, RTE_swc_SetOutputInterface_APPL_DATA) BlockId, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) blockstatus);
FUNC(Std_ReturnType, swc_SetOutputInterface_CODE) Ram_Service_Write(VAR(UInt32_T, RTE_swc_SetOutputInterface_APPL_DATA) block_Id, VAR(UInt8_T, RTE_swc_SetOutputInterface_APPL_DATA) write);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Exclusive Areas.
************************************************************************************************************************
*/

#ifdef __cplusplus
}                  
#endif            
#endif /* RTE_SWC_SETOUTPUTINTERFACE_H_ */
 
 
 

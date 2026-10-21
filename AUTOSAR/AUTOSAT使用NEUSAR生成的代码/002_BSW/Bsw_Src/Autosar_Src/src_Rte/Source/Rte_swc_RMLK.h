 
/*
************************************************************************************************************************
*
* File name: Rte_swc_RMLK.h
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
#ifndef RTE_SWC_RMLK_H_
#define RTE_SWC_RMLK_H_

#include "Rte_swc_RMLK_Type.h"
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

#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_b_LockVehSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_b_rmtCtrlAccPedlOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_b_rmtCtrlTqOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_b_rmtCtrlTurtleLampOn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_FunLockVehActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_LockLimResult;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_LockVehType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_st_LockVehExecutedSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcWakeUp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXFunLockVehActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockLimSet;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockVehCtrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockVehType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_actWorkSts1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehCfg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_App1_Task_10ms_Core1_QM, RTE_VAR_NOINIT) Rte_App1_Task_10ms_Core1_QM;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
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
#define Rte_IRead_swc_RMLK_Step_vcib_VCIP_obcd_b_obcWakeUp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_obcd_b_obcWakeUp.value)

#define Rte_IRead_swc_RMLK_Step_vcib_VCIP_pmmd_b_ignOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value)

#define Rte_IRead_swc_RMLK_Step_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive.value)

#define Rte_IRead_swc_RMLK_Step_vcib_VCIP_vild_st_TBOXFunLockVehActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vild_st_TBOXFunLockVehActive.value)

#define Rte_IRead_swc_RMLK_Step_vcib_VCIP_vild_st_TBOXLockLimSet() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vild_st_TBOXLockLimSet.value)

#define Rte_IRead_swc_RMLK_Step_vcib_VCIP_vild_st_TBOXLockVehCtrl() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vild_st_TBOXLockVehCtrl.value)

#define Rte_IRead_swc_RMLK_Step_vcib_VCIP_vild_st_TBOXLockVehType() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vild_st_TBOXLockVehType.value)

#define Rte_IRead_swc_RMLK_Step_vcib_VCIP_vild_st_actWorkSts1() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vild_st_actWorkSts1.value)

#define Rte_IRead_swc_RMLK_Step_vcib_VCIP_vild_st_flgFctCfgVehCfg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg.value)

#define Rte_IRead_swc_RMLK_Step_vcib_VCIP_vscd_v_vehSpd_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value)

#define Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_b_LockVehSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_b_LockVehSts.value = (data) \
)

#define Rte_IWriteRef_swc_RMLK_Step_vcsb_RMLK_rlcd_b_LockVehSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_b_LockVehSts.value \
)

#define Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_b_rmtCtrlAccPedlOff(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_b_rmtCtrlAccPedlOff.value = (data) \
)

#define Rte_IWriteRef_swc_RMLK_Step_vcsb_RMLK_rlcd_b_rmtCtrlAccPedlOff() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_b_rmtCtrlAccPedlOff.value \
)

#define Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_b_rmtCtrlTqOff(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_b_rmtCtrlTqOff.value = (data) \
)

#define Rte_IWriteRef_swc_RMLK_Step_vcsb_RMLK_rlcd_b_rmtCtrlTqOff() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_b_rmtCtrlTqOff.value \
)

#define Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_b_rmtCtrlTurtleLampOn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_b_rmtCtrlTurtleLampOn.value = (data) \
)

#define Rte_IWriteRef_swc_RMLK_Step_vcsb_RMLK_rlcd_b_rmtCtrlTurtleLampOn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_b_rmtCtrlTurtleLampOn.value \
)

#define Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive.value = (data) \
)

#define Rte_IWriteRef_swc_RMLK_Step_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive.value \
)

#define Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_num_FunLockVehActive(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_num_FunLockVehActive.value = (data) \
)

#define Rte_IWriteRef_swc_RMLK_Step_vcsb_RMLK_rlcd_num_FunLockVehActive() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_num_FunLockVehActive.value \
)

#define Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_num_LockLimResult(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_num_LockLimResult.value = (data) \
)

#define Rte_IWriteRef_swc_RMLK_Step_vcsb_RMLK_rlcd_num_LockLimResult() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_num_LockLimResult.value \
)

#define Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_num_LockVehType(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_num_LockVehType.value = (data) \
)

#define Rte_IWriteRef_swc_RMLK_Step_vcsb_RMLK_rlcd_num_LockVehType() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_num_LockVehType.value \
)

#define Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_st_LockVehExecutedSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_st_LockVehExecutedSts.value = (data) \
)

#define Rte_IWriteRef_swc_RMLK_Step_vcsb_RMLK_rlcd_st_LockVehExecutedSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_st_LockVehExecutedSts.value \
)

#define Rte_IWrite_swc_RMLK_Step_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph.value = (data) \
)

#define Rte_IWriteRef_swc_RMLK_Step_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_RMLK_swc_RMLK_Step.Rte_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph.value \
)

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
FUNC(void, swc_RMLK_CODE) swc_RMLK_Step(void);
FUNC(void, swc_RMLK_CODE) swc_RMLK_Init(void);
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
#endif /* RTE_SWC_RMLK_H_ */
 
 
 

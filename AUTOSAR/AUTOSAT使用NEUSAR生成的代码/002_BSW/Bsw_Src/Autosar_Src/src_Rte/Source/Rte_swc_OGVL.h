 
/*
************************************************************************************************************************
*
* File name: Rte_swc_OGVL.h
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
#ifndef RTE_SWC_OGVL_H_
#define RTE_SWC_OGVL_H_

#include "Rte_swc_OGVL_Type.h"
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
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_invSpdLmtRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_inventorySpdLmtReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_lifeCnt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_lockVehPer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_lockVehPerRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_pwrOffCmd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_pwrOffCmdRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_spdLmtLevelReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_spdLmtLvRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_tboxLifeSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_verCvsRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_versionConversion;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_v_dstSpdLim_kph;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_obcWakeUpActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_tboxPowOffCmd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_actWorkSts1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehCfg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxInventorySpdLmtReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxLife;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxLockVehPerFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxSpdLmtLevelReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxVersionConversionFlag;
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
#define Rte_IRead_swc_OGVL_Step_vcib_VCIP_pmmd_b_ignOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value)

#define Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_b_obcWakeUpActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_b_obcWakeUpActv.value)

#define Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_b_tboxPowOffCmd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_b_tboxPowOffCmd.value)

#define Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_st_actWorkSts1() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_st_actWorkSts1.value)

#define Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_st_flgFctCfgVehCfg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg.value)

#define Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_st_tboxInventorySpdLmtReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_st_tboxInventorySpdLmtReq.value)

#define Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_st_tboxLife() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_st_tboxLife.value)

#define Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_st_tboxLockVehPerFlag() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_st_tboxLockVehPerFlag.value)

#define Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_st_tboxSpdLmtLevelReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_st_tboxSpdLmtLevelReq.value)

#define Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_st_tboxVersionConversionFlag() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vild_st_tboxVersionConversionFlag.value)

#define Rte_IRead_swc_OGVL_Step_vcib_VCIP_vscd_v_vehSpd_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value)

#define Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_invSpdLmtRxSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_invSpdLmtRxSts.value = (data) \
)

#define Rte_IWriteRef_swc_OGVL_Step_vcsb_OGVL_dtld_st_invSpdLmtRxSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_invSpdLmtRxSts.value \
)

#define Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_inventorySpdLmtReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_inventorySpdLmtReq.value = (data) \
)

#define Rte_IWriteRef_swc_OGVL_Step_vcsb_OGVL_dtld_st_inventorySpdLmtReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_inventorySpdLmtReq.value \
)

#define Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_lifeCnt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_lifeCnt.value = (data) \
)

#define Rte_IWriteRef_swc_OGVL_Step_vcsb_OGVL_dtld_st_lifeCnt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_lifeCnt.value \
)

#define Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_lockVehPer(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_lockVehPer.value = (data) \
)

#define Rte_IWriteRef_swc_OGVL_Step_vcsb_OGVL_dtld_st_lockVehPer() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_lockVehPer.value \
)

#define Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_lockVehPerRxSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_lockVehPerRxSts.value = (data) \
)

#define Rte_IWriteRef_swc_OGVL_Step_vcsb_OGVL_dtld_st_lockVehPerRxSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_lockVehPerRxSts.value \
)

#define Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_pwrOffCmd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_pwrOffCmd.value = (data) \
)

#define Rte_IWriteRef_swc_OGVL_Step_vcsb_OGVL_dtld_st_pwrOffCmd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_pwrOffCmd.value \
)

#define Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_pwrOffCmdRxSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_pwrOffCmdRxSts.value = (data) \
)

#define Rte_IWriteRef_swc_OGVL_Step_vcsb_OGVL_dtld_st_pwrOffCmdRxSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_pwrOffCmdRxSts.value \
)

#define Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_spdLmtLevelReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_spdLmtLevelReq.value = (data) \
)

#define Rte_IWriteRef_swc_OGVL_Step_vcsb_OGVL_dtld_st_spdLmtLevelReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_spdLmtLevelReq.value \
)

#define Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_spdLmtLvRxSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_spdLmtLvRxSts.value = (data) \
)

#define Rte_IWriteRef_swc_OGVL_Step_vcsb_OGVL_dtld_st_spdLmtLvRxSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_spdLmtLvRxSts.value \
)

#define Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_tboxLifeSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_tboxLifeSts.value = (data) \
)

#define Rte_IWriteRef_swc_OGVL_Step_vcsb_OGVL_dtld_st_tboxLifeSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_tboxLifeSts.value \
)

#define Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_verCvsRxSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_verCvsRxSts.value = (data) \
)

#define Rte_IWriteRef_swc_OGVL_Step_vcsb_OGVL_dtld_st_verCvsRxSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_verCvsRxSts.value \
)

#define Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_versionConversion(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_versionConversion.value = (data) \
)

#define Rte_IWriteRef_swc_OGVL_Step_vcsb_OGVL_dtld_st_versionConversion() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_st_versionConversion.value \
)

#define Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_v_dstSpdLim_kph(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_v_dstSpdLim_kph.value = (data) \
)

#define Rte_IWriteRef_swc_OGVL_Step_vcsb_OGVL_dtld_v_dstSpdLim_kph() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_OGVL_swc_OGVL_Step.Rte_vcsb_OGVL_dtld_v_dstSpdLim_kph.value \
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
FUNC(void, swc_OGVL_CODE) swc_OGVL_Step(void);
FUNC(void, swc_OGVL_CODE) swc_OGVL_Init(void);
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
#endif /* RTE_SWC_OGVL_H_ */
 
 
 

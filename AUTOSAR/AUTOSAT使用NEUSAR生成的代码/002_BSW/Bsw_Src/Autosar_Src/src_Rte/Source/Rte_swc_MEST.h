 
/*
************************************************************************************************************************
*
* File name: Rte_swc_MEST.h
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
#ifndef RTE_SWC_MEST_H_
#define RTE_SWC_MEST_H_

#include "Rte_swc_MEST_Type.h"
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_MEST_vcsb_MEST_masd_b_vehOvrLoadEnbl;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_MEST_vcsb_MEST_masd_m_vehWeight_kg;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_MEST_vcsb_MEST_masd_st_vehCalNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_MEST_vcsb_MEST_masd_st_vehOverLoadSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2ActTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_u_busInv2HVAct_V;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flg2FctCfgVehTyp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRun;
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
#define Rte_IRead_swc_MEST_Step_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A.value)

#define Rte_IRead_swc_MEST_Step_vcib_VCIP_eadd_n_mot2ActSpd_rpm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm.value)

#define Rte_IRead_swc_MEST_Step_vcib_VCIP_eadd_tq_mot2ActTq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm.value)

#define Rte_IRead_swc_MEST_Step_vcib_VCIP_eadd_u_busInv2HVAct_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcib_VCIP_eadd_u_busInv2HVAct_V.value)

#define Rte_IRead_swc_MEST_Step_vcib_VCIP_pmmd_b_ignOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value)

#define Rte_IRead_swc_MEST_Step_vcib_VCIP_vild_st_flg2FctCfgVehTyp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp.value)

#define Rte_IRead_swc_MEST_Step_vcib_VCIP_vscd_v_vehSpd_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value)

#define Rte_IWrite_swc_MEST_Step_vcsb_MEST_masd_b_vehOvrLoadEnbl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcsb_MEST_masd_b_vehOvrLoadEnbl.value = (data) \
)

#define Rte_IWriteRef_swc_MEST_Step_vcsb_MEST_masd_b_vehOvrLoadEnbl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcsb_MEST_masd_b_vehOvrLoadEnbl.value \
)

#define Rte_IWrite_swc_MEST_Step_vcsb_MEST_masd_m_vehWeight_kg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcsb_MEST_masd_m_vehWeight_kg.value = (data) \
)

#define Rte_IWriteRef_swc_MEST_Step_vcsb_MEST_masd_m_vehWeight_kg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcsb_MEST_masd_m_vehWeight_kg.value \
)

#define Rte_IWrite_swc_MEST_Step_vcsb_MEST_masd_st_vehCalNum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcsb_MEST_masd_st_vehCalNum.value = (data) \
)

#define Rte_IWriteRef_swc_MEST_Step_vcsb_MEST_masd_st_vehCalNum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcsb_MEST_masd_st_vehCalNum.value \
)

#define Rte_IWrite_swc_MEST_Step_vcsb_MEST_masd_st_vehOverLoadSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcsb_MEST_masd_st_vehOverLoadSts.value = (data) \
)

#define Rte_IWriteRef_swc_MEST_Step_vcsb_MEST_masd_st_vehOverLoadSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcsb_MEST_masd_st_vehOverLoadSts.value \
)

#define Rte_IRead_swc_MEST_Step_vcsb_VOMM_vsmd_b_VehRun() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_MEST_swc_MEST_Step.Rte_vcsb_VOMM_vsmd_b_VehRun.value)

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
FUNC(void, swc_MEST_CODE) swc_MEST_Step(void);
FUNC(void, swc_MEST_CODE) swc_MEST_Init(void);
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
#endif /* RTE_SWC_MEST_H_ */
 
 
 

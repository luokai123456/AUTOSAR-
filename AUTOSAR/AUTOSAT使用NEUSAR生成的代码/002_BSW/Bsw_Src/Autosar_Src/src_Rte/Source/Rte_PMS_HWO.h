 
/*
************************************************************************************************************************
*
* File name: Rte_PMS_HWO.h
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
#ifndef RTE_PMS_HWO_H_
#define RTE_PMS_HWO_H_

#include "Rte_PMS_HWO_Type.h"
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9(P2VAR(Boolean, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PMS_HWO_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period(P2VAR(Float, AUTOMATIC, RTE_PMS_HWO_APPL_DATA) data);
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
#define Rte_Read_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03 Rte_Read_PMS_HWO_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03
#define Rte_Read_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05 Rte_Read_PMS_HWO_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05
#define Rte_Read_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11 Rte_Read_PMS_HWO_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11
#define Rte_Read_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6 Rte_Read_PMS_HWO_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6
#define Rte_Read_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8 Rte_Read_PMS_HWO_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8
#define Rte_Read_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9 Rte_Read_PMS_HWO_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9
#define Rte_Read_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10 Rte_Read_PMS_HWO_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10
#define Rte_Read_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12 Rte_Read_PMS_HWO_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12
#define Rte_Read_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5 Rte_Read_PMS_HWO_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5
#define Rte_Read_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7 Rte_Read_PMS_HWO_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7
#define Rte_Read_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9 Rte_Read_PMS_HWO_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9
#define Rte_Read_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle Rte_Read_PMS_HWO_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle
#define Rte_Read_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period Rte_Read_PMS_HWO_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period
#define Rte_Read_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle Rte_Read_PMS_HWO_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle
#define Rte_Read_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period Rte_Read_PMS_HWO_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period
#define Rte_Read_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle Rte_Read_PMS_HWO_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle
#define Rte_Read_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period Rte_Read_PMS_HWO_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period
#define Rte_Read_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle Rte_Read_PMS_HWO_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle
#define Rte_Read_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period Rte_Read_PMS_HWO_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period
#define Rte_Read_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle Rte_Read_PMS_HWO_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle
#define Rte_Read_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period Rte_Read_PMS_HWO_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period
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
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_KEY_HS_03_PMSHWO_SetDOHS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_KEY_HS_05_PMSHWO_SetDOHS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_HS_11_PMSHWO_SetDOHS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_HS_6_PMSHWO_SetDOHS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_HS_8_PMSHWO_SetDOHS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_HS_9_PMSHWO_SetDOHS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_LS_10_PMSHWO_SetDOLS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_LS_12_PMSHWO_SetDOLS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_LS_5_PMSHWO_SetDOLS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_LS_7_PMSHWO_SetDOLS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_LS_9_PMSHWO_SetDOLS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_PO_HVIL_1_PMSHWO_SetPWM(VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) Frequency, VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) DutyCycle);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_PO_HVIL_2_PMSHWO_SetPWM(VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) Frequency, VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) DutyCycle);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_PO_PWM_1_PMSHWO_SetPWM(VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) Frequency, VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) DutyCycle);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_PO_PWM_2_PMSHWO_SetPWM(VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) Frequency, VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) DutyCycle);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_PO_PWM_4_PMSHWO_SetPWM(VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) Frequency, VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) DutyCycle);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifndef RTE_CORE
#define Rte_Call_PMSHWO_DO_KEY_HS_03_PMSHWO_SetDOHS Rte_Call_PMS_HWO_PMSHWO_DO_KEY_HS_03_PMSHWO_SetDOHS
#define Rte_Call_PMS_HWO_PMSHWO_DO_KEY_HS_03_PMSHWO_SetDOHS(arg1) (PMSHWO_DO_KEY_HS_03_PMSHWO_SetDOHS(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWO_DO_KEY_HS_05_PMSHWO_SetDOHS Rte_Call_PMS_HWO_PMSHWO_DO_KEY_HS_05_PMSHWO_SetDOHS
#define Rte_Call_PMS_HWO_PMSHWO_DO_KEY_HS_05_PMSHWO_SetDOHS(arg1) (PMSHWO_DO_KEY_HS_05_PMSHWO_SetDOHS(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWO_DO_RELAY_HS_11_PMSHWO_SetDOHS Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_HS_11_PMSHWO_SetDOHS
#define Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_HS_11_PMSHWO_SetDOHS(arg1) (PMSHWO_DO_RELAY_HS_11_PMSHWO_SetDOHS(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWO_DO_RELAY_HS_6_PMSHWO_SetDOHS Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_HS_6_PMSHWO_SetDOHS
#define Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_HS_6_PMSHWO_SetDOHS(arg1) (PMSHWO_DO_RELAY_HS_6_PMSHWO_SetDOHS(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWO_DO_RELAY_HS_8_PMSHWO_SetDOHS Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_HS_8_PMSHWO_SetDOHS
#define Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_HS_8_PMSHWO_SetDOHS(arg1) (PMSHWO_DO_RELAY_HS_8_PMSHWO_SetDOHS(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWO_DO_RELAY_HS_9_PMSHWO_SetDOHS Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_HS_9_PMSHWO_SetDOHS
#define Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_HS_9_PMSHWO_SetDOHS(arg1) (PMSHWO_DO_RELAY_HS_9_PMSHWO_SetDOHS(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWO_DO_RELAY_LS_10_PMSHWO_SetDOLS Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_LS_10_PMSHWO_SetDOLS
#define Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_LS_10_PMSHWO_SetDOLS(arg1) (PMSHWO_DO_RELAY_LS_10_PMSHWO_SetDOLS(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWO_DO_RELAY_LS_12_PMSHWO_SetDOLS Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_LS_12_PMSHWO_SetDOLS
#define Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_LS_12_PMSHWO_SetDOLS(arg1) (PMSHWO_DO_RELAY_LS_12_PMSHWO_SetDOLS(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWO_DO_RELAY_LS_5_PMSHWO_SetDOLS Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_LS_5_PMSHWO_SetDOLS
#define Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_LS_5_PMSHWO_SetDOLS(arg1) (PMSHWO_DO_RELAY_LS_5_PMSHWO_SetDOLS(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWO_DO_RELAY_LS_7_PMSHWO_SetDOLS Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_LS_7_PMSHWO_SetDOLS
#define Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_LS_7_PMSHWO_SetDOLS(arg1) (PMSHWO_DO_RELAY_LS_7_PMSHWO_SetDOLS(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWO_DO_RELAY_LS_9_PMSHWO_SetDOLS Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_LS_9_PMSHWO_SetDOLS
#define Rte_Call_PMS_HWO_PMSHWO_DO_RELAY_LS_9_PMSHWO_SetDOLS(arg1) (PMSHWO_DO_RELAY_LS_9_PMSHWO_SetDOLS(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWO_PO_HVIL_1_PMSHWO_SetPWM Rte_Call_PMS_HWO_PMSHWO_PO_HVIL_1_PMSHWO_SetPWM
#define Rte_Call_PMS_HWO_PMSHWO_PO_HVIL_1_PMSHWO_SetPWM(arg1, arg2) (PMSHWO_PO_HVIL_1_PMSHWO_SetPWM(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWO_PO_HVIL_2_PMSHWO_SetPWM Rte_Call_PMS_HWO_PMSHWO_PO_HVIL_2_PMSHWO_SetPWM
#define Rte_Call_PMS_HWO_PMSHWO_PO_HVIL_2_PMSHWO_SetPWM(arg1, arg2) (PMSHWO_PO_HVIL_2_PMSHWO_SetPWM(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWO_PO_PWM_1_PMSHWO_SetPWM Rte_Call_PMS_HWO_PMSHWO_PO_PWM_1_PMSHWO_SetPWM
#define Rte_Call_PMS_HWO_PMSHWO_PO_PWM_1_PMSHWO_SetPWM(arg1, arg2) (PMSHWO_PO_PWM_1_PMSHWO_SetPWM(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWO_PO_PWM_2_PMSHWO_SetPWM Rte_Call_PMS_HWO_PMSHWO_PO_PWM_2_PMSHWO_SetPWM
#define Rte_Call_PMS_HWO_PMSHWO_PO_PWM_2_PMSHWO_SetPWM(arg1, arg2) (PMSHWO_PO_PWM_2_PMSHWO_SetPWM(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWO_PO_PWM_4_PMSHWO_SetPWM Rte_Call_PMS_HWO_PMSHWO_PO_PWM_4_PMSHWO_SetPWM
#define Rte_Call_PMS_HWO_PMSHWO_PO_PWM_4_PMSHWO_SetPWM(arg1, arg2) (PMSHWO_PO_PWM_4_PMSHWO_SetPWM(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#endif /* !defined(RTE_CORE) */

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
FUNC(void, PMS_HWO_CODE) PMS_HWO_Step(void);
FUNC(void, PMS_HWO_CODE) PMS_HWO_Init(void);
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
#endif /* RTE_PMS_HWO_H_ */
 
 
 

 
/*
************************************************************************************************************************
*
* File name: Rte_PMS_HWI.h
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
#ifndef RTE_PMS_HWI_H_
#define RTE_PMS_HWI_H_

#include "Rte_PMS_HWI_Type.h"
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
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_BATTERY_TEMPH_5_EXT_AI_BATTERY_TEMPH_5;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_BATTERY_TEMPH_6_EXT_AI_BATTERY_TEMPH_6;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_MID_COOLING_TEMPH_8_EXT_AI_MID_COOLING_TEMPH_8;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_SENSOR_1_EXT_AI_SENSOR_1;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_SENSOR_2_EXT_AI_SENSOR_2;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_SENSOR_6_EXT_AI_SENSOR_6;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AI_SWITCH_1_EXT_AI_SWITCH_1;
extern VAR(UInt16, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AO_TRACKING_5V_01_EXT_AO_TRACKING_5V_01;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_AO_TRACKING_5V_02_EXT_AO_TRACKING_5V_02;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_CHARGE_ON_AI_EXT_CHARGE_ON_AI;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_04_EXT_DI_HS_04;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_05_EXT_DI_HS_05;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_06_EXT_DI_HS_06;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_07_EXT_DI_HS_07;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_08_EXT_DI_HS_08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_DI_HS_10_EXT_DI_HS_10;
extern VAR(UInt16, RTE_VAR_INIT) Rte_PMS_HWI_EXT_IGN_ON_AI_EXT_IGN_ON_AI;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_HWI_EXT_IGN_ON_DI_EXT_IGN_ON_DI;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_HVIL_1_DutyCycle_EXT_PI_HVIL_1_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_HVIL_1_Period_EXT_PI_HVIL_1_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_HVIL_2_DutyCycle_EXT_PI_HVIL_2_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_HVIL_2_Period_EXT_PI_HVIL_2_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_PWM_1_DutyCycle_EXT_PI_PWM_1_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_PWM_1_Period_EXT_PI_PWM_1_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_PWM_2_DutyCycle_EXT_PI_PWM_2_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_EXT_PI_PWM_2_Period_EXT_PI_PWM_2_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_HWI_KL30_KL30;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AI_BATTERY_TEMPH_5_EXT_AI_BATTERY_TEMPH_5(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AI_BATTERY_TEMPH_6_EXT_AI_BATTERY_TEMPH_6(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AI_MID_COOLING_TEMPH_8_EXT_AI_MID_COOLING_TEMPH_8(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AI_SENSOR_1_EXT_AI_SENSOR_1(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AI_SENSOR_2_EXT_AI_SENSOR_2(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AI_SENSOR_6_EXT_AI_SENSOR_6(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AI_SWITCH_1_EXT_AI_SWITCH_1(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AO_TRACKING_5V_01_EXT_AO_TRACKING_5V_01(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_AO_TRACKING_5V_02_EXT_AO_TRACKING_5V_02(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_CHARGE_ON_AI_EXT_CHARGE_ON_AI(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_DI_HS_04_EXT_DI_HS_04(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_DI_HS_05_EXT_DI_HS_05(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_DI_HS_06_EXT_DI_HS_06(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_DI_HS_07_EXT_DI_HS_07(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_DI_HS_08_EXT_DI_HS_08(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_DI_HS_10_EXT_DI_HS_10(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_IGN_ON_AI_EXT_IGN_ON_AI(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_IGN_ON_DI_EXT_IGN_ON_DI(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_HVIL_1_DutyCycle_EXT_PI_HVIL_1_DutyCycle(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_HVIL_1_Period_EXT_PI_HVIL_1_Period(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_HVIL_2_DutyCycle_EXT_PI_HVIL_2_DutyCycle(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_HVIL_2_Period_EXT_PI_HVIL_2_Period(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_PWM_1_DutyCycle_EXT_PI_PWM_1_DutyCycle(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_PWM_1_Period_EXT_PI_PWM_1_Period(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_PWM_2_DutyCycle_EXT_PI_PWM_2_DutyCycle(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_EXT_PI_PWM_2_Period_EXT_PI_PWM_2_Period(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_HWI_KL30_KL30(Float data);
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
#define Rte_Write_EXT_AI_BATTERY_TEMPH_5_EXT_AI_BATTERY_TEMPH_5 Rte_Write_PMS_HWI_EXT_AI_BATTERY_TEMPH_5_EXT_AI_BATTERY_TEMPH_5
#define Rte_Write_EXT_AI_BATTERY_TEMPH_6_EXT_AI_BATTERY_TEMPH_6 Rte_Write_PMS_HWI_EXT_AI_BATTERY_TEMPH_6_EXT_AI_BATTERY_TEMPH_6
#define Rte_Write_EXT_AI_MID_COOLING_TEMPH_8_EXT_AI_MID_COOLING_TEMPH_8 Rte_Write_PMS_HWI_EXT_AI_MID_COOLING_TEMPH_8_EXT_AI_MID_COOLING_TEMPH_8
#define Rte_Write_EXT_AI_SENSOR_1_EXT_AI_SENSOR_1 Rte_Write_PMS_HWI_EXT_AI_SENSOR_1_EXT_AI_SENSOR_1
#define Rte_Write_EXT_AI_SENSOR_2_EXT_AI_SENSOR_2 Rte_Write_PMS_HWI_EXT_AI_SENSOR_2_EXT_AI_SENSOR_2
#define Rte_Write_EXT_AI_SENSOR_6_EXT_AI_SENSOR_6 Rte_Write_PMS_HWI_EXT_AI_SENSOR_6_EXT_AI_SENSOR_6
#define Rte_Write_EXT_AI_SWITCH_1_EXT_AI_SWITCH_1 Rte_Write_PMS_HWI_EXT_AI_SWITCH_1_EXT_AI_SWITCH_1
#define Rte_Write_EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02 Rte_Write_PMS_HWI_EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02
#define Rte_Write_EXT_AO_TRACKING_5V_01_EXT_AO_TRACKING_5V_01 Rte_Write_PMS_HWI_EXT_AO_TRACKING_5V_01_EXT_AO_TRACKING_5V_01
#define Rte_Write_EXT_AO_TRACKING_5V_02_EXT_AO_TRACKING_5V_02 Rte_Write_PMS_HWI_EXT_AO_TRACKING_5V_02_EXT_AO_TRACKING_5V_02
#define Rte_Write_EXT_CHARGE_ON_AI_EXT_CHARGE_ON_AI Rte_Write_PMS_HWI_EXT_CHARGE_ON_AI_EXT_CHARGE_ON_AI
#define Rte_Write_EXT_DI_HS_04_EXT_DI_HS_04 Rte_Write_PMS_HWI_EXT_DI_HS_04_EXT_DI_HS_04
#define Rte_Write_EXT_DI_HS_05_EXT_DI_HS_05 Rte_Write_PMS_HWI_EXT_DI_HS_05_EXT_DI_HS_05
#define Rte_Write_EXT_DI_HS_06_EXT_DI_HS_06 Rte_Write_PMS_HWI_EXT_DI_HS_06_EXT_DI_HS_06
#define Rte_Write_EXT_DI_HS_07_EXT_DI_HS_07 Rte_Write_PMS_HWI_EXT_DI_HS_07_EXT_DI_HS_07
#define Rte_Write_EXT_DI_HS_08_EXT_DI_HS_08 Rte_Write_PMS_HWI_EXT_DI_HS_08_EXT_DI_HS_08
#define Rte_Write_EXT_DI_HS_10_EXT_DI_HS_10 Rte_Write_PMS_HWI_EXT_DI_HS_10_EXT_DI_HS_10
#define Rte_Write_EXT_IGN_ON_AI_EXT_IGN_ON_AI Rte_Write_PMS_HWI_EXT_IGN_ON_AI_EXT_IGN_ON_AI
#define Rte_Write_EXT_IGN_ON_DI_EXT_IGN_ON_DI Rte_Write_PMS_HWI_EXT_IGN_ON_DI_EXT_IGN_ON_DI
#define Rte_Write_EXT_PI_HVIL_1_DutyCycle_EXT_PI_HVIL_1_DutyCycle Rte_Write_PMS_HWI_EXT_PI_HVIL_1_DutyCycle_EXT_PI_HVIL_1_DutyCycle
#define Rte_Write_EXT_PI_HVIL_1_Period_EXT_PI_HVIL_1_Period Rte_Write_PMS_HWI_EXT_PI_HVIL_1_Period_EXT_PI_HVIL_1_Period
#define Rte_Write_EXT_PI_HVIL_2_DutyCycle_EXT_PI_HVIL_2_DutyCycle Rte_Write_PMS_HWI_EXT_PI_HVIL_2_DutyCycle_EXT_PI_HVIL_2_DutyCycle
#define Rte_Write_EXT_PI_HVIL_2_Period_EXT_PI_HVIL_2_Period Rte_Write_PMS_HWI_EXT_PI_HVIL_2_Period_EXT_PI_HVIL_2_Period
#define Rte_Write_EXT_PI_PWM_1_DutyCycle_EXT_PI_PWM_1_DutyCycle Rte_Write_PMS_HWI_EXT_PI_PWM_1_DutyCycle_EXT_PI_PWM_1_DutyCycle
#define Rte_Write_EXT_PI_PWM_1_Period_EXT_PI_PWM_1_Period Rte_Write_PMS_HWI_EXT_PI_PWM_1_Period_EXT_PI_PWM_1_Period
#define Rte_Write_EXT_PI_PWM_2_DutyCycle_EXT_PI_PWM_2_DutyCycle Rte_Write_PMS_HWI_EXT_PI_PWM_2_DutyCycle_EXT_PI_PWM_2_DutyCycle
#define Rte_Write_EXT_PI_PWM_2_Period_EXT_PI_PWM_2_Period Rte_Write_PMS_HWI_EXT_PI_PWM_2_Period_EXT_PI_PWM_2_Period
#define Rte_Write_KL30_KL30 Rte_Write_PMS_HWI_KL30_KL30
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_BATTERY_TEMPH_5_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_BATTERY_TEMPH_6_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_EXT_IGN_ON_AI_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_MID_COOLING_TEMPH_8_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_SENSOR_1_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_SENSOR_2_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_SENSOR_6_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_SWITCH_1_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AO_LDO_5V_02_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AO_TRACKING_5V_01_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AO_TRACKING_5V_02_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_CHARGE_ON_AI_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_DI_HS_04_PMSHWI_GetDI(P2VAR(boolean, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) RawResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_DI_HS_05_PMSHWI_GetDI(P2VAR(boolean, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) RawResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_DI_HS_06_PMSHWI_GetDI(P2VAR(boolean, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) RawResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_DI_HS_07_PMSHWI_GetDI(P2VAR(boolean, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) RawResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_DI_HS_08_PMSHWI_GetDI(P2VAR(boolean, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) RawResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_DI_HS_10_PMSHWI_GetDI(P2VAR(boolean, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) RawResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_IGN_ON_DI_PMSHWI_GetDI(P2VAR(boolean, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) RawResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_KL30_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_PI_HVIL_1_PMSHWI_GetPWM(P2VAR(uint8, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numDuty, P2VAR(uint32, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numFreq);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_PI_HVIL_2_PMSHWI_GetPWM(P2VAR(uint8, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numDuty, P2VAR(uint32, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numFreq);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_PI_PWM_1_PMSHWI_GetPWM(P2VAR(uint8, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numDuty, P2VAR(uint32, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numFreq);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_PI_PWM_2_PMSHWI_GetPWM(P2VAR(uint8, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numDuty, P2VAR(uint32, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numFreq);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifndef RTE_CORE
#define Rte_Call_PMSHWI_AI_BATTERY_TEMPH_5_PMSHWI_GetAI Rte_Call_PMS_HWI_PMSHWI_AI_BATTERY_TEMPH_5_PMSHWI_GetAI
#define Rte_Call_PMS_HWI_PMSHWI_AI_BATTERY_TEMPH_5_PMSHWI_GetAI(arg1) (PMSHWI_AI_BATTERY_TEMPH_5_PMSHWI_GetAI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_AI_BATTERY_TEMPH_6_PMSHWI_GetAI Rte_Call_PMS_HWI_PMSHWI_AI_BATTERY_TEMPH_6_PMSHWI_GetAI
#define Rte_Call_PMS_HWI_PMSHWI_AI_BATTERY_TEMPH_6_PMSHWI_GetAI(arg1) (PMSHWI_AI_BATTERY_TEMPH_6_PMSHWI_GetAI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_AI_EXT_IGN_ON_AI_PMSHWI_GetAI Rte_Call_PMS_HWI_PMSHWI_AI_EXT_IGN_ON_AI_PMSHWI_GetAI
#define Rte_Call_PMS_HWI_PMSHWI_AI_EXT_IGN_ON_AI_PMSHWI_GetAI(arg1) (PMSHWI_AI_EXT_IGN_ON_AI_PMSHWI_GetAI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_AI_MID_COOLING_TEMPH_8_PMSHWI_GetAI Rte_Call_PMS_HWI_PMSHWI_AI_MID_COOLING_TEMPH_8_PMSHWI_GetAI
#define Rte_Call_PMS_HWI_PMSHWI_AI_MID_COOLING_TEMPH_8_PMSHWI_GetAI(arg1) (PMSHWI_AI_MID_COOLING_TEMPH_8_PMSHWI_GetAI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_AI_SENSOR_1_PMSHWI_GetAI Rte_Call_PMS_HWI_PMSHWI_AI_SENSOR_1_PMSHWI_GetAI
#define Rte_Call_PMS_HWI_PMSHWI_AI_SENSOR_1_PMSHWI_GetAI(arg1) (PMSHWI_AI_SENSOR_1_PMSHWI_GetAI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_AI_SENSOR_2_PMSHWI_GetAI Rte_Call_PMS_HWI_PMSHWI_AI_SENSOR_2_PMSHWI_GetAI
#define Rte_Call_PMS_HWI_PMSHWI_AI_SENSOR_2_PMSHWI_GetAI(arg1) (PMSHWI_AI_SENSOR_2_PMSHWI_GetAI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_AI_SENSOR_6_PMSHWI_GetAI Rte_Call_PMS_HWI_PMSHWI_AI_SENSOR_6_PMSHWI_GetAI
#define Rte_Call_PMS_HWI_PMSHWI_AI_SENSOR_6_PMSHWI_GetAI(arg1) (PMSHWI_AI_SENSOR_6_PMSHWI_GetAI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_AI_SWITCH_1_PMSHWI_GetAI Rte_Call_PMS_HWI_PMSHWI_AI_SWITCH_1_PMSHWI_GetAI
#define Rte_Call_PMS_HWI_PMSHWI_AI_SWITCH_1_PMSHWI_GetAI(arg1) (PMSHWI_AI_SWITCH_1_PMSHWI_GetAI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_AO_LDO_5V_02_PMSHWI_GetAI Rte_Call_PMS_HWI_PMSHWI_AO_LDO_5V_02_PMSHWI_GetAI
#define Rte_Call_PMS_HWI_PMSHWI_AO_LDO_5V_02_PMSHWI_GetAI(arg1) (PMSHWI_AO_LDO_5V_02_PMSHWI_GetAI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_AO_TRACKING_5V_01_PMSHWI_GetAI Rte_Call_PMS_HWI_PMSHWI_AO_TRACKING_5V_01_PMSHWI_GetAI
#define Rte_Call_PMS_HWI_PMSHWI_AO_TRACKING_5V_01_PMSHWI_GetAI(arg1) (PMSHWI_AO_TRACKING_5V_01_PMSHWI_GetAI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_AO_TRACKING_5V_02_PMSHWI_GetAI Rte_Call_PMS_HWI_PMSHWI_AO_TRACKING_5V_02_PMSHWI_GetAI
#define Rte_Call_PMS_HWI_PMSHWI_AO_TRACKING_5V_02_PMSHWI_GetAI(arg1) (PMSHWI_AO_TRACKING_5V_02_PMSHWI_GetAI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_CHARGE_ON_AI_PMSHWI_GetAI Rte_Call_PMS_HWI_PMSHWI_CHARGE_ON_AI_PMSHWI_GetAI
#define Rte_Call_PMS_HWI_PMSHWI_CHARGE_ON_AI_PMSHWI_GetAI(arg1) (PMSHWI_CHARGE_ON_AI_PMSHWI_GetAI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_DI_HS_04_PMSHWI_GetDI Rte_Call_PMS_HWI_PMSHWI_DI_HS_04_PMSHWI_GetDI
#define Rte_Call_PMS_HWI_PMSHWI_DI_HS_04_PMSHWI_GetDI(arg1) (PMSHWI_DI_HS_04_PMSHWI_GetDI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_DI_HS_05_PMSHWI_GetDI Rte_Call_PMS_HWI_PMSHWI_DI_HS_05_PMSHWI_GetDI
#define Rte_Call_PMS_HWI_PMSHWI_DI_HS_05_PMSHWI_GetDI(arg1) (PMSHWI_DI_HS_05_PMSHWI_GetDI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_DI_HS_06_PMSHWI_GetDI Rte_Call_PMS_HWI_PMSHWI_DI_HS_06_PMSHWI_GetDI
#define Rte_Call_PMS_HWI_PMSHWI_DI_HS_06_PMSHWI_GetDI(arg1) (PMSHWI_DI_HS_06_PMSHWI_GetDI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_DI_HS_07_PMSHWI_GetDI Rte_Call_PMS_HWI_PMSHWI_DI_HS_07_PMSHWI_GetDI
#define Rte_Call_PMS_HWI_PMSHWI_DI_HS_07_PMSHWI_GetDI(arg1) (PMSHWI_DI_HS_07_PMSHWI_GetDI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_DI_HS_08_PMSHWI_GetDI Rte_Call_PMS_HWI_PMSHWI_DI_HS_08_PMSHWI_GetDI
#define Rte_Call_PMS_HWI_PMSHWI_DI_HS_08_PMSHWI_GetDI(arg1) (PMSHWI_DI_HS_08_PMSHWI_GetDI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_DI_HS_10_PMSHWI_GetDI Rte_Call_PMS_HWI_PMSHWI_DI_HS_10_PMSHWI_GetDI
#define Rte_Call_PMS_HWI_PMSHWI_DI_HS_10_PMSHWI_GetDI(arg1) (PMSHWI_DI_HS_10_PMSHWI_GetDI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_IGN_ON_DI_PMSHWI_GetDI Rte_Call_PMS_HWI_PMSHWI_IGN_ON_DI_PMSHWI_GetDI
#define Rte_Call_PMS_HWI_PMSHWI_IGN_ON_DI_PMSHWI_GetDI(arg1) (PMSHWI_IGN_ON_DI_PMSHWI_GetDI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_KL30_PMSHWI_GetAI Rte_Call_PMS_HWI_PMSHWI_KL30_PMSHWI_GetAI
#define Rte_Call_PMS_HWI_PMSHWI_KL30_PMSHWI_GetAI(arg1) (PMSHWI_KL30_PMSHWI_GetAI(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_PI_HVIL_1_PMSHWI_GetPWM Rte_Call_PMS_HWI_PMSHWI_PI_HVIL_1_PMSHWI_GetPWM
#define Rte_Call_PMS_HWI_PMSHWI_PI_HVIL_1_PMSHWI_GetPWM(arg1, arg2) (PMSHWI_PI_HVIL_1_PMSHWI_GetPWM(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_PI_HVIL_2_PMSHWI_GetPWM Rte_Call_PMS_HWI_PMSHWI_PI_HVIL_2_PMSHWI_GetPWM
#define Rte_Call_PMS_HWI_PMSHWI_PI_HVIL_2_PMSHWI_GetPWM(arg1, arg2) (PMSHWI_PI_HVIL_2_PMSHWI_GetPWM(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_PI_PWM_1_PMSHWI_GetPWM Rte_Call_PMS_HWI_PMSHWI_PI_PWM_1_PMSHWI_GetPWM
#define Rte_Call_PMS_HWI_PMSHWI_PI_PWM_1_PMSHWI_GetPWM(arg1, arg2) (PMSHWI_PI_PWM_1_PMSHWI_GetPWM(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_PMSHWI_PI_PWM_2_PMSHWI_GetPWM Rte_Call_PMS_HWI_PMSHWI_PI_PWM_2_PMSHWI_GetPWM
#define Rte_Call_PMS_HWI_PMSHWI_PI_PWM_2_PMSHWI_GetPWM(arg1, arg2) (PMSHWI_PI_PWM_2_PMSHWI_GetPWM(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
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
FUNC(void, PMS_HWI_CODE) PMS_HWI_Step(void);
FUNC(void, PMS_HWI_CODE) PMS_HWI_Init(void);
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
#endif /* RTE_PMS_HWI_H_ */
 
 
 

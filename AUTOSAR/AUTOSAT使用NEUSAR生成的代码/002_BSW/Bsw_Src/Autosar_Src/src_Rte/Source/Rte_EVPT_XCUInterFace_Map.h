 
/*
************************************************************************************************************************
*
* File name: Rte_EVPT_XCUInterFace_Map.h
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
#ifndef RTE_EVPT_XCUINTERFACE_MAP_H_
#define RTE_EVPT_XCUINTERFACE_MAP_H_

#include "Rte_EVPT_XCUInterFace_Map_Type.h"
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
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_BattPackNum_EV_BMSH_BattPackNum_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_BattSysNum_EV_BMSH_BattSysNum_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_BattTempAvg_EV_BMSH_BattTempAvg_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatIsoAlarm2_EV_BMSH_TBOX_BatIsoAlarm2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatLowSOC2_EV_BMSH_TBOX_BatLowSOC2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverCharge2_EV_BMSH_TBOX_BatOverCharge2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverSOC2_EV_BMSH_TBOX_BatOverSOC2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverTemp2_EV_BMSH_TBOX_BatOverTemp2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverVoltage2_EV_BMSH_TBOX_BatOverVoltage2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatTempUniformity2_EV_BMSH_TBOX_BatTempUniformity2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUnderVoltage2_EV_BMSH_TBOX_BatUnderVoltage2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUniformity2_EV_BMSH_TBOX_BatUniformity2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_ID_EV_BMSH_TBOX_CellA_ID_EV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_Volt_EV_BMSH_TBOX_CellA_Volt_EV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellB_Volt_EV_BMSH_TBOX_CellB_Volt_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_ID_EV_BMSH_TBOX_CellC_ID_EV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_Volt_EV_BMSH_TBOX_CellC_Volt_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellOverVoltage2_EV_BMSH_TBOX_CellOverVoltage2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_CellUnderVoltage2_EV_BMSH_TBOX_CellUnderVoltage2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_FireAlarm_EV_BMSH_TBOX_FireAlarm_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMSH_TBOX_SOCHop2_EV_BMSH_TBOX_SOCHop2_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_BMS_DelayDataUpldEnb_EV_BMS_DelayDataUpldEnb_EV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_HVBusCur_EV_IPU_HVBusCur_EV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_HVBusVolt_EV_IPU_HVBusVolt_EV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_HVBusVolt_IPUSts_IPU_HVBusVolt_IPUSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_MCUTempHighAlarm1_EV_IPU_MCUTempHighAlarm1_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_MotorOverCurrFlt_EV_IPU_MotorOverCurrFlt_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_MotorOverSpdFlt_EV_IPU_MotorOverSpdFlt_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EVPT_XCUInterFace_Map_IPU_MotorTempHighFault1_EV_IPU_MotorTempHighFault1_EV;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BattPackNum_BMSH_BattPackNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BattSysNum_BMSH_BattSysNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BattTempAvg_BMSH_BattTempAvg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_HVBusCur_IPU_HVBusCur;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_HVBusVolt_20_IPU_HVBusVolt_20;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_HVBusVolt_500_IPU_HVBusVolt_500;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_BattPackNum_BMSH_BattPackNum(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_BattPackNum_EV_BMSH_BattPackNum_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_BattSysNum_BMSH_BattSysNum(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_BattSysNum_EV_BMSH_BattSysNum_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_BattTempAvg_BMSH_BattTempAvg(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_BattTempAvg_EV_BMSH_BattTempAvg_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatIsoAlarm2_EV_BMSH_TBOX_BatIsoAlarm2_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatLowSOC2_EV_BMSH_TBOX_BatLowSOC2_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverCharge2_EV_BMSH_TBOX_BatOverCharge2_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverSOC2_EV_BMSH_TBOX_BatOverSOC2_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverTemp2_EV_BMSH_TBOX_BatOverTemp2_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverVoltage2_EV_BMSH_TBOX_BatOverVoltage2_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatTempUniformity2_EV_BMSH_TBOX_BatTempUniformity2_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUnderVoltage2_EV_BMSH_TBOX_BatUnderVoltage2_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUniformity2_EV_BMSH_TBOX_BatUniformity2_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_ID_EV_BMSH_TBOX_CellA_ID_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt(P2VAR(UInt16, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_Volt_EV_BMSH_TBOX_CellA_Volt_EV(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt(P2VAR(UInt16, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellB_Volt_EV_BMSH_TBOX_CellB_Volt_EV(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_ID_EV_BMSH_TBOX_CellC_ID_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt(P2VAR(UInt16, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_Volt_EV_BMSH_TBOX_CellC_Volt_EV(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellOverVoltage2_EV_BMSH_TBOX_CellOverVoltage2_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellUnderVoltage2_EV_BMSH_TBOX_CellUnderVoltage2_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_FireAlarm_EV_BMSH_TBOX_FireAlarm_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_SOCHop2_EV_BMSH_TBOX_SOCHop2_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_BMS_DelayDataUpldEnb_EV_BMS_DelayDataUpldEnb_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_IPU_HVBusCur_IPU_HVBusCur(P2VAR(UInt16, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_IPU_HVBusCur_EV_IPU_HVBusCur_EV(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_IPU_HVBusVolt_20_IPU_HVBusVolt_20(P2VAR(UInt16, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_IPU_HVBusVolt_500_IPU_HVBusVolt_500(P2VAR(UInt16, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_IPU_HVBusVolt_EV_IPU_HVBusVolt_EV(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_IPU_HVBusVolt_IPUSts_IPU_HVBusVolt_IPUSts(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_IPU_MCUTempHighAlarm1_EV_IPU_MCUTempHighAlarm1_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_IPU_MotorOverCurrFlt_EV_IPU_MotorOverCurrFlt_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_IPU_MotorOverSpdFlt_EV_IPU_MotorOverSpdFlt_EV(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EVPT_XCUInterFace_Map_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1(P2VAR(UInt8, AUTOMATIC, RTE_EVPT_XCUInterFace_Map_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EVPT_XCUInterFace_Map_IPU_MotorTempHighFault1_EV_IPU_MotorTempHighFault1_EV(UInt8 data);
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
#define Rte_Read_BMSH_BattPackNum_BMSH_BattPackNum Rte_Read_EVPT_XCUInterFace_Map_BMSH_BattPackNum_BMSH_BattPackNum
#define Rte_Read_BMSH_BattSysNum_BMSH_BattSysNum Rte_Read_EVPT_XCUInterFace_Map_BMSH_BattSysNum_BMSH_BattSysNum
#define Rte_Read_BMSH_BattTempAvg_BMSH_BattTempAvg Rte_Read_EVPT_XCUInterFace_Map_BMSH_BattTempAvg_BMSH_BattTempAvg
#define Rte_Read_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2 Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2
#define Rte_Read_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2 Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2
#define Rte_Read_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2 Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2
#define Rte_Read_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2 Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2
#define Rte_Read_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2 Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2
#define Rte_Read_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2 Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2
#define Rte_Read_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2 Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2
#define Rte_Read_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2 Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2
#define Rte_Read_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2 Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2
#define Rte_Read_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID
#define Rte_Read_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt
#define Rte_Read_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt
#define Rte_Read_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID
#define Rte_Read_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt
#define Rte_Read_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2 Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2
#define Rte_Read_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2 Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2
#define Rte_Read_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm
#define Rte_Read_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2 Rte_Read_EVPT_XCUInterFace_Map_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2
#define Rte_Read_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb Rte_Read_EVPT_XCUInterFace_Map_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb
#define Rte_Read_IPU_HVBusCur_IPU_HVBusCur Rte_Read_EVPT_XCUInterFace_Map_IPU_HVBusCur_IPU_HVBusCur
#define Rte_Read_IPU_HVBusVolt_20_IPU_HVBusVolt_20 Rte_Read_EVPT_XCUInterFace_Map_IPU_HVBusVolt_20_IPU_HVBusVolt_20
#define Rte_Read_IPU_HVBusVolt_500_IPU_HVBusVolt_500 Rte_Read_EVPT_XCUInterFace_Map_IPU_HVBusVolt_500_IPU_HVBusVolt_500
#define Rte_Read_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1 Rte_Read_EVPT_XCUInterFace_Map_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1
#define Rte_Read_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt Rte_Read_EVPT_XCUInterFace_Map_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt
#define Rte_Read_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt Rte_Read_EVPT_XCUInterFace_Map_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt
#define Rte_Read_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1 Rte_Read_EVPT_XCUInterFace_Map_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1
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
#define Rte_Write_BMSH_BattPackNum_EV_BMSH_BattPackNum_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_BattPackNum_EV_BMSH_BattPackNum_EV
#define Rte_Write_BMSH_BattSysNum_EV_BMSH_BattSysNum_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_BattSysNum_EV_BMSH_BattSysNum_EV
#define Rte_Write_BMSH_BattTempAvg_EV_BMSH_BattTempAvg_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_BattTempAvg_EV_BMSH_BattTempAvg_EV
#define Rte_Write_BMSH_TBOX_BatIsoAlarm2_EV_BMSH_TBOX_BatIsoAlarm2_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatIsoAlarm2_EV_BMSH_TBOX_BatIsoAlarm2_EV
#define Rte_Write_BMSH_TBOX_BatLowSOC2_EV_BMSH_TBOX_BatLowSOC2_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatLowSOC2_EV_BMSH_TBOX_BatLowSOC2_EV
#define Rte_Write_BMSH_TBOX_BatOverCharge2_EV_BMSH_TBOX_BatOverCharge2_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverCharge2_EV_BMSH_TBOX_BatOverCharge2_EV
#define Rte_Write_BMSH_TBOX_BatOverSOC2_EV_BMSH_TBOX_BatOverSOC2_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverSOC2_EV_BMSH_TBOX_BatOverSOC2_EV
#define Rte_Write_BMSH_TBOX_BatOverTemp2_EV_BMSH_TBOX_BatOverTemp2_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverTemp2_EV_BMSH_TBOX_BatOverTemp2_EV
#define Rte_Write_BMSH_TBOX_BatOverVoltage2_EV_BMSH_TBOX_BatOverVoltage2_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatOverVoltage2_EV_BMSH_TBOX_BatOverVoltage2_EV
#define Rte_Write_BMSH_TBOX_BatTempUniformity2_EV_BMSH_TBOX_BatTempUniformity2_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatTempUniformity2_EV_BMSH_TBOX_BatTempUniformity2_EV
#define Rte_Write_BMSH_TBOX_BatUnderVoltage2_EV_BMSH_TBOX_BatUnderVoltage2_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUnderVoltage2_EV_BMSH_TBOX_BatUnderVoltage2_EV
#define Rte_Write_BMSH_TBOX_BatUniformity2_EV_BMSH_TBOX_BatUniformity2_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_BatUniformity2_EV_BMSH_TBOX_BatUniformity2_EV
#define Rte_Write_BMSH_TBOX_CellA_ID_EV_BMSH_TBOX_CellA_ID_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_ID_EV_BMSH_TBOX_CellA_ID_EV
#define Rte_Write_BMSH_TBOX_CellA_Volt_EV_BMSH_TBOX_CellA_Volt_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellA_Volt_EV_BMSH_TBOX_CellA_Volt_EV
#define Rte_Write_BMSH_TBOX_CellB_Volt_EV_BMSH_TBOX_CellB_Volt_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellB_Volt_EV_BMSH_TBOX_CellB_Volt_EV
#define Rte_Write_BMSH_TBOX_CellC_ID_EV_BMSH_TBOX_CellC_ID_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_ID_EV_BMSH_TBOX_CellC_ID_EV
#define Rte_Write_BMSH_TBOX_CellC_Volt_EV_BMSH_TBOX_CellC_Volt_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellC_Volt_EV_BMSH_TBOX_CellC_Volt_EV
#define Rte_Write_BMSH_TBOX_CellOverVoltage2_EV_BMSH_TBOX_CellOverVoltage2_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellOverVoltage2_EV_BMSH_TBOX_CellOverVoltage2_EV
#define Rte_Write_BMSH_TBOX_CellUnderVoltage2_EV_BMSH_TBOX_CellUnderVoltage2_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_CellUnderVoltage2_EV_BMSH_TBOX_CellUnderVoltage2_EV
#define Rte_Write_BMSH_TBOX_FireAlarm_EV_BMSH_TBOX_FireAlarm_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_FireAlarm_EV_BMSH_TBOX_FireAlarm_EV
#define Rte_Write_BMSH_TBOX_SOCHop2_EV_BMSH_TBOX_SOCHop2_EV Rte_Write_EVPT_XCUInterFace_Map_BMSH_TBOX_SOCHop2_EV_BMSH_TBOX_SOCHop2_EV
#define Rte_Write_BMS_DelayDataUpldEnb_EV_BMS_DelayDataUpldEnb_EV Rte_Write_EVPT_XCUInterFace_Map_BMS_DelayDataUpldEnb_EV_BMS_DelayDataUpldEnb_EV
#define Rte_Write_IPU_HVBusCur_EV_IPU_HVBusCur_EV Rte_Write_EVPT_XCUInterFace_Map_IPU_HVBusCur_EV_IPU_HVBusCur_EV
#define Rte_Write_IPU_HVBusVolt_EV_IPU_HVBusVolt_EV Rte_Write_EVPT_XCUInterFace_Map_IPU_HVBusVolt_EV_IPU_HVBusVolt_EV
#define Rte_Write_IPU_HVBusVolt_IPUSts_IPU_HVBusVolt_IPUSts Rte_Write_EVPT_XCUInterFace_Map_IPU_HVBusVolt_IPUSts_IPU_HVBusVolt_IPUSts
#define Rte_Write_IPU_MCUTempHighAlarm1_EV_IPU_MCUTempHighAlarm1_EV Rte_Write_EVPT_XCUInterFace_Map_IPU_MCUTempHighAlarm1_EV_IPU_MCUTempHighAlarm1_EV
#define Rte_Write_IPU_MotorOverCurrFlt_EV_IPU_MotorOverCurrFlt_EV Rte_Write_EVPT_XCUInterFace_Map_IPU_MotorOverCurrFlt_EV_IPU_MotorOverCurrFlt_EV
#define Rte_Write_IPU_MotorOverSpdFlt_EV_IPU_MotorOverSpdFlt_EV Rte_Write_EVPT_XCUInterFace_Map_IPU_MotorOverSpdFlt_EV_IPU_MotorOverSpdFlt_EV
#define Rte_Write_IPU_MotorTempHighFault1_EV_IPU_MotorTempHighFault1_EV Rte_Write_EVPT_XCUInterFace_Map_IPU_MotorTempHighFault1_EV_IPU_MotorTempHighFault1_EV
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
FUNC(void, EVPT_XCUInterFace_Map_CODE) EVPT_XCUInterFace_Map_Init(void);
FUNC(void, EVPT_XCUInterFace_Map_CODE) EVPT_XCUInterFace_Map_Runnable(void);
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
#endif /* RTE_EVPT_XCUINTERFACE_MAP_H_ */
 
 
 

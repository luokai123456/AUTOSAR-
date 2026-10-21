 
/*
************************************************************************************************************************
*
* File name: Rte_MCU_DID.h
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
#ifndef RTE_MCU_DID_H_
#define RTE_MCU_DID_H_

#include "Rte_MCU_DID_Type.h"
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

#ifndef RTE_E_IPU_DTC_0x0402_CS_NOT_OK
#define RTE_E_IPU_DTC_0x0402_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_IPU_DischgState_0X04CF_CS_NOT_OK
#define RTE_E_IPU_DischgState_0X04CF_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_IPU_HVBusCur_0x0409_CS_NOT_OK
#define RTE_E_IPU_HVBusCur_0x0409_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_IPU_HVBusVolt_500_0x0408_CS_NOT_OK
#define RTE_E_IPU_HVBusVolt_500_0x0408_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_IPU_IsgInvrT_0x040C_CS_NOT_OK
#define RTE_E_IPU_IsgInvrT_0x040C_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_IPU_IsgMotT_0x040B_CS_NOT_OK
#define RTE_E_IPU_IsgMotT_0x040B_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_IPU_IsgSpdActSgn_0x0403_CS_NOT_OK
#define RTE_E_IPU_IsgSpdActSgn_0x0403_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_IPU_IsgTqActIsgTqAct_0x0404_CS_NOT_OK
#define RTE_E_IPU_IsgTqActIsgTqAct_0x0404_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_IPU_MotorTemp_0x040D_CS_NOT_OK
#define RTE_E_IPU_MotorTemp_0x040D_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_IPU_TqAvlIsgMax_0x0406_CS_NOT_OK
#define RTE_E_IPU_TqAvlIsgMax_0x0406_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_IPU_TqAvlIsgMin_0x0407_CS_NOT_OK
#define RTE_E_IPU_TqAvlIsgMin_0x0407_CS_NOT_OK (1U)
#endif

#ifndef RTE_E_PMS_DriverDemandTorque_0x0405_CS_NOT_OK
#define RTE_E_PMS_DriverDemandTorque_0x0405_CS_NOT_OK (1U)
#endif


/*
************************************************************************************************************************
*    extern declaration of RTE buffers
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriverDemandTorque_PMS_DriverDemandTorque;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_DTC_IPU_DTC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_DischgState_IPU_DischgState;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_HVBusCur_IPU_HVBusCur;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_HVBusVolt_500_IPU_HVBusVolt_500;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax;
extern VAR(UInt16, RTE_VAR_INIT) Rte_ComTx_CAN_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_DTC_IPU_DTC(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_DischgState_IPU_DischgState(P2VAR(UInt8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_HVBusCur_IPU_HVBusCur(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_HVBusVolt_500_IPU_HVBusVolt_500(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_IsgInvrT_IPU_IsgInvrT(P2VAR(UInt8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_IsgMotT_IPU_IsgMotT(P2VAR(UInt8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_PMS_DriverDemandTorque_PMS_DriverDemandTorque(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data);
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
#define Rte_Read_IPU_DTC_IPU_DTC Rte_Read_MCU_DID_IPU_DTC_IPU_DTC
#define Rte_Read_IPU_DischgState_IPU_DischgState Rte_Read_MCU_DID_IPU_DischgState_IPU_DischgState
#define Rte_Read_IPU_HVBusCur_IPU_HVBusCur Rte_Read_MCU_DID_IPU_HVBusCur_IPU_HVBusCur
#define Rte_Read_IPU_HVBusVolt_500_IPU_HVBusVolt_500 Rte_Read_MCU_DID_IPU_HVBusVolt_500_IPU_HVBusVolt_500
#define Rte_Read_IPU_IsgInvrT_IPU_IsgInvrT Rte_Read_MCU_DID_IPU_IsgInvrT_IPU_IsgInvrT
#define Rte_Read_IPU_IsgMotT_IPU_IsgMotT Rte_Read_MCU_DID_IPU_IsgMotT_IPU_IsgMotT
#define Rte_Read_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn Rte_Read_MCU_DID_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn
#define Rte_Read_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct Rte_Read_MCU_DID_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct
#define Rte_Read_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax Rte_Read_MCU_DID_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax
#define Rte_Read_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin Rte_Read_MCU_DID_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin
#define Rte_Read_PMS_DriverDemandTorque_PMS_DriverDemandTorque Rte_Read_MCU_DID_PMS_DriverDemandTorque_PMS_DriverDemandTorque
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
/*
************************************************************************************************************************
*    Operation Invocation Runnable entities
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
#if 0 //UDS不使用
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_DTC_0x0402_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_DTC_0x0402_CS_ReadData Rte_Call_MCU_DID_IPU_DTC_0x0402_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_DTC_0x0402_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_DischgState_0X04CF_CS_ReadData Rte_Call_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_DischgState_0X04CF_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_HVBusCur_0x0409_CS_ReadData Rte_Call_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_HVBusCur_0x0409_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_HVBusVolt_500_0x0408_CS_ReadData Rte_Call_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_HVBusVolt_500_0x0408_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_IsgInvrT_0x040C_CS_ReadData Rte_Call_MCU_DID_IPU_IsgInvrT_0x040C_CS_ReadData
#define Rte_Call_MCU_DID_IPU_IsgInvrT_0x040C_CS_ReadData IPU_IsgInvrT_0x040C_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_IsgInvrT_0x040C_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_IsgMotT_0x040B_CS_ReadData Rte_Call_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_IsgMotT_0x040B_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_IsgSpdActSgn_0x0403_CS_ReadData Rte_Call_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_IsgSpdActSgn_0x0403_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData Rte_Call_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_MotorTemp_0x040D_CS_ReadData Rte_Call_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_MotorTemp_0x040D_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_TqAvlIsgMax_0x0406_CS_ReadData Rte_Call_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_TqAvlIsgMax_0x0406_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_TqAvlIsgMin_0x0407_CS_ReadData Rte_Call_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_TqAvlIsgMin_0x0407_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DriverDemandTorque_0x0405_CS_ReadData Rte_Call_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) PMS_DriverDemandTorque_0x0405_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#else
#define Rte_Call_IPU_DTC_0x0402_CS_ReadData Rte_Call_MCU_DID_IPU_DTC_0x0402_CS_ReadData
#define Rte_Call_MCU_DID_IPU_DTC_0x0402_CS_ReadData IPU_DTC_0x0402_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_DTC_0x0402_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_DischgState_0X04CF_CS_ReadData Rte_Call_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData
#define Rte_Call_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData IPU_DischgState_0X04CF_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_DischgState_0X04CF_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_HVBusCur_0x0409_CS_ReadData Rte_Call_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData
#define Rte_Call_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData IPU_HVBusCur_0x0409_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_HVBusCur_0x0409_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_HVBusVolt_500_0x0408_CS_ReadData Rte_Call_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData
#define Rte_Call_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData IPU_HVBusVolt_500_0x0408_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_HVBusVolt_500_0x0408_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_IsgInvrT_0x040C_CS_ReadData Rte_Call_MCU_DID_IPU_IsgInvrT_0x040C_CS_ReadData
#define Rte_Call_MCU_DID_IPU_IsgInvrT_0x040C_CS_ReadData IPU_IsgInvrT_0x040C_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_IsgInvrT_0x040C_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_IsgMotT_0x040B_CS_ReadData Rte_Call_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData
#define Rte_Call_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData IPU_IsgMotT_0x040B_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_IsgMotT_0x040B_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_IsgSpdActSgn_0x0403_CS_ReadData Rte_Call_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData
#define Rte_Call_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData IPU_IsgSpdActSgn_0x0403_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_IsgSpdActSgn_0x0403_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData Rte_Call_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData
#define Rte_Call_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_MotorTemp_0x040D_CS_ReadData Rte_Call_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData
#define Rte_Call_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData IPU_MotorTemp_0x040D_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_MotorTemp_0x040D_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_TqAvlIsgMax_0x0406_CS_ReadData Rte_Call_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData
#define Rte_Call_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData IPU_TqAvlIsgMax_0x0406_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_TqAvlIsgMax_0x0406_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_TqAvlIsgMin_0x0407_CS_ReadData Rte_Call_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData
#define Rte_Call_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData IPU_TqAvlIsgMin_0x0407_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_TqAvlIsgMin_0x0407_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DriverDemandTorque_0x0405_CS_ReadData Rte_Call_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData
#define Rte_Call_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData PMS_DriverDemandTorque_0x0405_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) PMS_DriverDemandTorque_0x0405_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#endif
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
#endif /* RTE_MCU_DID_H_ */
 
 
 

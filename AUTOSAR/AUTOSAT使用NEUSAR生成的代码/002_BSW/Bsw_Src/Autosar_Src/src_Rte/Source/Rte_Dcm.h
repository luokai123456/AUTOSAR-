/*
************************************************************************************************************************
*
* File name: Rte_Dcm.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
************************************************************************************************************************
*
* History
*-----------------------------------------------------------------------------------------------------------------------
************************************************************************************************************************
* Version: 3.0
* Author/Date : WangJP/2021.11.11
* Change: New created.
* Cause: New
************************************************************************************************************************
* Version: 4.0
* Author/Date: LanZG/2024.03.18
* Change: Upgrade template.
* Cause: Update
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    double include preventio and include files
************************************************************************************************************************
*/
#ifndef _RTE_DCM_H
#define _RTE_DCM_H

/*
************************************************************************************************************************
*    Include Swc headers
************************************************************************************************************************
*/
#include "Rte_Dcm_Type.h"
#include "Rte_DataHandleType.h"
#include "Rte_Type.h"

/*
************************************************************************************************************************
*    Init Values for unqueued S/R communication (primitive types only)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Data structures for mode management
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    API prototypes
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_Mode_<p>_<m>
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Switch_<p>_<m>
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Runnable entities
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
#if 0 //UDS不使用
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0501_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0502_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0503_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0504_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(Std_ReturnType, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0505_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0507_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x050A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0525_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0526_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0527_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0528_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0529_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x052B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x052D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x052E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0530_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0531_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0532_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0533_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0534_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0535_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0536_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0537_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0538_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0539_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x053B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x053C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x053D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x053E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0542_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0543_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0544_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0545_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0547_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0552_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x055A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x055C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x055D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0585_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0586_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0587_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0588_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0589_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058F_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0590_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0591_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0592_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0593_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0594_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0595_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0596_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0597_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0598_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0599_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059F_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A5_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A6_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A7_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A8_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A9_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AA_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AB_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AC_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AD_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AE_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AF_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B0_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B5_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B6_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B7_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B8_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B9_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BA_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BB_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BC_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BD_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BE_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BF_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C0_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C5_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C6_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C7_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C8_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C9_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CA_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CB_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CC_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CD_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CE_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CF_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05D0_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05D1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05D2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05D3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05D4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xCF00_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xCF05_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xCF06_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xCF07_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDD00_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF00_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF01_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF02_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF03_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF04_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF06_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF09_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_Real_PedalPosition_0x0310_CS_ReadData Rte_Call_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_Brake1Switch_0x0311_CS_ReadData Rte_Call_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_EHB_EPBStatus_0x0312_CS_ReadData Rte_Call_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_CPSREn_0x0313_CS_ReadData Rte_Call_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_IsgTqReq_0x0314_CS_ReadData Rte_Call_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_PTResiduePwrInd_0x0315_CS_ReadData Rte_Call_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_ModeGearDisplaySts_0x0316_CS_ReadData Rte_Call_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DriveModeInd_0x0317_CS_ReadData Rte_Call_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_FunLockVehActive_0x0318_CS_ReadData Rte_Call_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PEPS_PowerMode_0x0319_CS_ReadData Rte_Call_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_EDCPPWMCtrl_0x031A_CS_ReadData Rte_Call_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_HBCPPWMCtrl_0x031B_CS_ReadData Rte_Call_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData Rte_Call_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_ACCMEnable_0x031D_CS_ReadData Rte_Call_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_PTCEnable_0x031E_CS_ReadData Rte_Call_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_PTC2Enable_0x031F_CS_ReadData Rte_Call_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_PTC3Enable_0x0320_CS_ReadData Rte_Call_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_SelfCheckSts_0x0321_CS_ReadData Rte_Call_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_HVIL1Sts_0x0322_CS_ReadData Rte_Call_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_HVIL2Sts_0x0323_CS_ReadData Rte_Call_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData Rte_Call_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_EngRecMode_Fb_0x0325_CS_ReadData Rte_Call_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_VCU_Odometerbackup_0x0326_CS_ReadData Rte_Call_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_VehicleSpeed_0x0327_CS_ReadData Rte_Call_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_AC_ACCM_ActPower_0x0328_CS_ReadData Rte_Call_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData Rte_Call_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_SelfChkSts_0x032A_CS_ReadData Rte_Call_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_BMSH_SelfCheckFault_0x032B_CS_ReadData Rte_Call_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_DCDC_SelfChkSts_0x032C_CS_ReadData Rte_Call_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DcDcActvdReq_0x032D_CS_ReadData Rte_Call_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DCDCCutOffLV_0x032E_CS_ReadData Rte_Call_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_IsgModReq_0x032F_CS_ReadData Rte_Call_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_VCU_BMSH_StsModeReq_0x0330_CS_ReadData Rte_Call_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_BatteryVol_0x0331_CS_ReadData Rte_Call_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_IgnONSts_0x0332_CS_ReadData Rte_Call_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_Brake2Switch_0x0333_CS_ReadData Rte_Call_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_IPKTotalOdometer_0x0334_CS_ReadData Rte_Call_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) ClearNumOfOdometer_0x0335_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_ClearNumOfOdometer_0x0335_CS_ReadData ClearNumOfOdometer_0x0335_CS_ReadData
#define Rte_Call_ClearNumOfOdometer_0x0335_CS_ReadData Rte_Call_PMS_DID_ClearNumOfOdometer_0x0335_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData(VAR(UInt8_T, RTE_MCU_UDS_Interface_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_UDS_Interface_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_UDS_Interface_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0400_ReadData Rte_Call_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_DTC_0x0402_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_DTC_0x0402_CS_ReadData Rte_Call_MCU_DID_IPU_DTC_0x0402_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_IsgSpdActSgn_0x0403_CS_ReadData Rte_Call_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData Rte_Call_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DriverDemandTorque_0x0405_CS_ReadData Rte_Call_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_TqAvlIsgMax_0x0406_CS_ReadData Rte_Call_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_TqAvlIsgMin_0x0407_CS_ReadData Rte_Call_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_HVBusVolt_500_0x0408_CS_ReadData Rte_Call_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_HVBusCur_0x0409_CS_ReadData Rte_Call_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_IsgMotT_0x040B_CS_ReadData Rte_Call_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_IsgInvrT_0x040C_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_MCU_DID_IPU_IsgInvrT_0x040C_CS_ReadData IPU_IsgInvrT_0x040C_CS_ReadData
#define Rte_Call_IPU_IsgInvrT_0x040C_CS_ReadData Rte_Call_MCU_DID_IPU_IsgInvrT_0x040C_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_MotorTemp_0x040D_CS_ReadData Rte_Call_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_IPU_DischgState_0X04CF_CS_ReadData Rte_Call_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x03E2_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x03E2_Stop Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4000_Start(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x4000_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4000_Start
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x400F_Start(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x400F_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x400F_Start
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x4F02_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x4F03_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x4F04_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x14_Operation(void);
#define Rte_Call_ServiceCheckRule_0x14_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x14_Operation
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x28_Operation(void);
#define Rte_Call_ServiceCheckRule_0x28_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x28_Operation
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x85_Operation(void);
#define Rte_Call_ServiceCheckRule_0x85_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x85_Operation
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x1002_Operation(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond);
#define Rte_Call_ServiceCheckRule_0x1002_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x1002_Operation
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x1003_Operation(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond);
#define Rte_Call_ServiceCheckRule_0x1003_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x1003_Operation
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x11_Operation(void);
#define Rte_Call_ServiceCheckRule_0x11_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x11_Operation
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x22_Operation(void);
#define Rte_Call_ServiceCheckRule_0x22_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x22_Operation
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x31_Operation(void);
#define Rte_Call_ServiceCheckRule_0x31_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x31_Operation
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x27_Operation(void);
#define Rte_Call_ServiceCheckRule_0x27_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x27_Operation
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x2E_Operation(void);
#define Rte_Call_ServiceCheckRule_0x2E_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x2E_Operation
#else
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0501_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData SWC_TestDCM_DataServices_DspData_0x0501_22_RE
#define Rte_Call_DataServices_DspData_0x0501_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0502_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData SWC_TestDCM_DataServices_DspData_0x0502_22_RE
#define Rte_Call_DataServices_DspData_0x0502_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0503_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData SWC_TestDCM_DataServices_DspData_0x0503_22_RE
#define Rte_Call_DataServices_DspData_0x0503_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0504_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData SWC_TestDCM_DataServices_DspData_0x0504_22_RE
#define Rte_Call_DataServices_DspData_0x0504_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0505_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(Std_ReturnType, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData SWC_TestDCM_DataServices_DspData_0x0505_22_RE
#define Rte_Call_DataServices_DspData_0x0505_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0507_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData SWC_TestDCM_DataServices_DspData_0x0507_22_RE
#define Rte_Call_DataServices_DspData_0x0507_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x050A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData SWC_TestDCM_DataServices_DspData_0x050A_22_RE
#define Rte_Call_DataServices_DspData_0x050A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0525_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData SWC_TestDCM_DataServices_DspData_0x0525_22_RE
#define Rte_Call_DataServices_DspData_0x0525_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0526_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData SWC_TestDCM_DataServices_DspData_0x0526_22_RE
#define Rte_Call_DataServices_DspData_0x0526_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0527_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData SWC_TestDCM_DataServices_DspData_0x0527_22_RE
#define Rte_Call_DataServices_DspData_0x0527_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0528_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData SWC_TestDCM_DataServices_DspData_0x0528_22_RE
#define Rte_Call_DataServices_DspData_0x0528_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0529_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData SWC_TestDCM_DataServices_DspData_0x0529_22_RE
#define Rte_Call_DataServices_DspData_0x0529_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x052B_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData SWC_TestDCM_DataServices_DspData_0x052B_22_RE
#define Rte_Call_DataServices_DspData_0x052B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x052D_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData SWC_TestDCM_DataServices_DspData_0x052D_22_RE
#define Rte_Call_DataServices_DspData_0x052D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x052E_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData SWC_TestDCM_DataServices_DspData_0x052E_22_RE
#define Rte_Call_DataServices_DspData_0x052E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0530_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData SWC_TestDCM_DataServices_DspData_0x0530_22_RE
#define Rte_Call_DataServices_DspData_0x0530_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0531_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData SWC_TestDCM_DataServices_DspData_0x0531_22_RE
#define Rte_Call_DataServices_DspData_0x0531_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0532_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData SWC_TestDCM_DataServices_DspData_0x0532_22_RE
#define Rte_Call_DataServices_DspData_0x0532_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0533_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData SWC_TestDCM_DataServices_DspData_0x0533_22_RE
#define Rte_Call_DataServices_DspData_0x0533_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0534_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData SWC_TestDCM_DataServices_DspData_0x0534_22_RE
#define Rte_Call_DataServices_DspData_0x0534_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0535_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData SWC_TestDCM_DataServices_DspData_0x0535_22_RE
#define Rte_Call_DataServices_DspData_0x0535_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0536_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData SWC_TestDCM_DataServices_DspData_0x0536_22_RE
#define Rte_Call_DataServices_DspData_0x0536_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0537_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData SWC_TestDCM_DataServices_DspData_0x0537_22_RE
#define Rte_Call_DataServices_DspData_0x0537_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0538_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData SWC_TestDCM_DataServices_DspData_0x0538_22_RE
#define Rte_Call_DataServices_DspData_0x0538_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0539_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData SWC_TestDCM_DataServices_DspData_0x0539_22_RE
#define Rte_Call_DataServices_DspData_0x0539_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x053B_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData SWC_TestDCM_DataServices_DspData_0x053B_22_RE
#define Rte_Call_DataServices_DspData_0x053B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x053C_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData SWC_TestDCM_DataServices_DspData_0x053C_22_RE
#define Rte_Call_DataServices_DspData_0x053C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x053D_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData SWC_TestDCM_DataServices_DspData_0x053D_22_RE
#define Rte_Call_DataServices_DspData_0x053D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x053E_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData SWC_TestDCM_DataServices_DspData_0x053E_22_RE
#define Rte_Call_DataServices_DspData_0x053E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0542_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData SWC_TestDCM_DataServices_DspData_0x0542_22_RE
#define Rte_Call_DataServices_DspData_0x0542_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0543_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData SWC_TestDCM_DataServices_DspData_0x0543_22_RE
#define Rte_Call_DataServices_DspData_0x0543_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0544_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData SWC_TestDCM_DataServices_DspData_0x0544_22_RE
#define Rte_Call_DataServices_DspData_0x0544_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0545_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData SWC_TestDCM_DataServices_DspData_0x0545_22_RE
#define Rte_Call_DataServices_DspData_0x0545_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0547_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData SWC_TestDCM_DataServices_DspData_0x0547_22_RE
#define Rte_Call_DataServices_DspData_0x0547_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0552_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData SWC_TestDCM_DataServices_DspData_0x0552_22_RE
#define Rte_Call_DataServices_DspData_0x0552_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x055A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData SWC_TestDCM_DataServices_DspData_0x055A_22_RE
#define Rte_Call_DataServices_DspData_0x055A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x055C_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData SWC_TestDCM_DataServices_DspData_0x055C_22_RE
#define Rte_Call_DataServices_DspData_0x055C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x055D_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData SWC_TestDCM_DataServices_DspData_0x055D_22_RE
#define Rte_Call_DataServices_DspData_0x055D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0585_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData SWC_TestDCM_DataServices_DspData_0x0585_22_RE
#define Rte_Call_DataServices_DspData_0x0585_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0586_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData SWC_TestDCM_DataServices_DspData_0x0586_22_RE
#define Rte_Call_DataServices_DspData_0x0586_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0587_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData SWC_TestDCM_DataServices_DspData_0x0587_22_RE
#define Rte_Call_DataServices_DspData_0x0587_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0588_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData SWC_TestDCM_DataServices_DspData_0x0588_22_RE
#define Rte_Call_DataServices_DspData_0x0588_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0589_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData SWC_TestDCM_DataServices_DspData_0x0589_22_RE
#define Rte_Call_DataServices_DspData_0x0589_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData SWC_TestDCM_DataServices_DspData_0x058A_22_RE
#define Rte_Call_DataServices_DspData_0x058A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058B_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData SWC_TestDCM_DataServices_DspData_0x058B_22_RE
#define Rte_Call_DataServices_DspData_0x058B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058C_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData SWC_TestDCM_DataServices_DspData_0x058C_22_RE
#define Rte_Call_DataServices_DspData_0x058C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058D_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData SWC_TestDCM_DataServices_DspData_0x058D_22_RE
#define Rte_Call_DataServices_DspData_0x058D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058E_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData SWC_TestDCM_DataServices_DspData_0x058E_22_RE
#define Rte_Call_DataServices_DspData_0x058E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058F_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData SWC_TestDCM_DataServices_DspData_0x058F_22_RE
#define Rte_Call_DataServices_DspData_0x058F_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0590_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData SWC_TestDCM_DataServices_DspData_0x0590_22_RE
#define Rte_Call_DataServices_DspData_0x0590_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0591_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData SWC_TestDCM_DataServices_DspData_0x0591_22_RE
#define Rte_Call_DataServices_DspData_0x0591_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0592_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData SWC_TestDCM_DataServices_DspData_0x0592_22_RE
#define Rte_Call_DataServices_DspData_0x0592_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0593_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData SWC_TestDCM_DataServices_DspData_0x0593_22_RE
#define Rte_Call_DataServices_DspData_0x0593_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0594_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData SWC_TestDCM_DataServices_DspData_0x0594_22_RE
#define Rte_Call_DataServices_DspData_0x0594_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0595_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData SWC_TestDCM_DataServices_DspData_0x0595_22_RE
#define Rte_Call_DataServices_DspData_0x0595_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0596_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData SWC_TestDCM_DataServices_DspData_0x0596_22_RE
#define Rte_Call_DataServices_DspData_0x0596_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0597_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData SWC_TestDCM_DataServices_DspData_0x0597_22_RE
#define Rte_Call_DataServices_DspData_0x0597_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0598_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData SWC_TestDCM_DataServices_DspData_0x0598_22_RE
#define Rte_Call_DataServices_DspData_0x0598_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0599_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData SWC_TestDCM_DataServices_DspData_0x0599_22_RE
#define Rte_Call_DataServices_DspData_0x0599_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData SWC_TestDCM_DataServices_DspData_0x059A_22_RE
#define Rte_Call_DataServices_DspData_0x059A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059B_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData SWC_TestDCM_DataServices_DspData_0x059B_22_RE
#define Rte_Call_DataServices_DspData_0x059B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059C_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData SWC_TestDCM_DataServices_DspData_0x059C_22_RE
#define Rte_Call_DataServices_DspData_0x059C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059D_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData SWC_TestDCM_DataServices_DspData_0x059D_22_RE
#define Rte_Call_DataServices_DspData_0x059D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059E_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData SWC_TestDCM_DataServices_DspData_0x059E_22_RE
#define Rte_Call_DataServices_DspData_0x059E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059F_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData SWC_TestDCM_DataServices_DspData_0x059F_22_RE
#define Rte_Call_DataServices_DspData_0x059F_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A1_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A1_22_RE
#define Rte_Call_DataServices_DspData_0x05A1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A2_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A2_22_RE
#define Rte_Call_DataServices_DspData_0x05A2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A3_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A3_22_RE
#define Rte_Call_DataServices_DspData_0x05A3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A4_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A4_22_RE
#define Rte_Call_DataServices_DspData_0x05A4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A5_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A5_22_RE
#define Rte_Call_DataServices_DspData_0x05A5_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A6_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A6_22_RE
#define Rte_Call_DataServices_DspData_0x05A6_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A7_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A7_22_RE
#define Rte_Call_DataServices_DspData_0x05A7_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A8_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A8_22_RE
#define Rte_Call_DataServices_DspData_0x05A8_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A9_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A9_22_RE
#define Rte_Call_DataServices_DspData_0x05A9_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AA_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData SWC_TestDCM_DataServices_DspData_0x05AA_22_RE
#define Rte_Call_DataServices_DspData_0x05AA_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AB_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData SWC_TestDCM_DataServices_DspData_0x05AB_22_RE
#define Rte_Call_DataServices_DspData_0x05AB_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AC_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData SWC_TestDCM_DataServices_DspData_0x05AC_22_RE
#define Rte_Call_DataServices_DspData_0x05AC_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AD_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData SWC_TestDCM_DataServices_DspData_0x05AD_22_RE
#define Rte_Call_DataServices_DspData_0x05AD_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AE_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData SWC_TestDCM_DataServices_DspData_0x05AE_22_RE
#define Rte_Call_DataServices_DspData_0x05AE_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AF_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData SWC_TestDCM_DataServices_DspData_0x05AF_22_RE
#define Rte_Call_DataServices_DspData_0x05AF_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B0_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B0_22_RE
#define Rte_Call_DataServices_DspData_0x05B0_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B1_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B1_22_RE
#define Rte_Call_DataServices_DspData_0x05B1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B2_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B2_22_RE
#define Rte_Call_DataServices_DspData_0x05B2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B3_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B3_22_RE
#define Rte_Call_DataServices_DspData_0x05B3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B4_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B4_22_RE
#define Rte_Call_DataServices_DspData_0x05B4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B5_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B5_22_RE
#define Rte_Call_DataServices_DspData_0x05B5_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B6_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B6_22_RE
#define Rte_Call_DataServices_DspData_0x05B6_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B7_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B7_22_RE
#define Rte_Call_DataServices_DspData_0x05B7_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B8_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B8_22_RE
#define Rte_Call_DataServices_DspData_0x05B8_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B9_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B9_22_RE
#define Rte_Call_DataServices_DspData_0x05B9_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BA_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData SWC_TestDCM_DataServices_DspData_0x05BA_22_RE
#define Rte_Call_DataServices_DspData_0x05BA_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BB_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData SWC_TestDCM_DataServices_DspData_0x05BB_22_RE
#define Rte_Call_DataServices_DspData_0x05BB_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BC_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData SWC_TestDCM_DataServices_DspData_0x05BC_22_RE
#define Rte_Call_DataServices_DspData_0x05BC_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BD_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData SWC_TestDCM_DataServices_DspData_0x05BD_22_RE
#define Rte_Call_DataServices_DspData_0x05BD_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BE_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData SWC_TestDCM_DataServices_DspData_0x05BE_22_RE
#define Rte_Call_DataServices_DspData_0x05BE_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BF_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData SWC_TestDCM_DataServices_DspData_0x05BF_22_RE
#define Rte_Call_DataServices_DspData_0x05BF_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C0_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C0_22_RE
#define Rte_Call_DataServices_DspData_0x05C0_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C1_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C1_22_RE
#define Rte_Call_DataServices_DspData_0x05C1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C2_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C2_22_RE
#define Rte_Call_DataServices_DspData_0x05C2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C3_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C3_22_RE
#define Rte_Call_DataServices_DspData_0x05C3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C4_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C4_22_RE
#define Rte_Call_DataServices_DspData_0x05C4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C5_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C5_22_RE
#define Rte_Call_DataServices_DspData_0x05C5_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C6_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C6_22_RE
#define Rte_Call_DataServices_DspData_0x05C6_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C7_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C7_22_RE
#define Rte_Call_DataServices_DspData_0x05C7_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C8_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C8_22_RE
#define Rte_Call_DataServices_DspData_0x05C8_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C9_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C9_22_RE
#define Rte_Call_DataServices_DspData_0x05C9_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CA_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData SWC_TestDCM_DataServices_DspData_0x05CA_22_RE
#define Rte_Call_DataServices_DspData_0x05CA_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CB_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData SWC_TestDCM_DataServices_DspData_0x05CB_22_RE
#define Rte_Call_DataServices_DspData_0x05CB_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CC_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData SWC_TestDCM_DataServices_DspData_0x05CC_22_RE
#define Rte_Call_DataServices_DspData_0x05CC_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CD_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData SWC_TestDCM_DataServices_DspData_0x05CD_22_RE
#define Rte_Call_DataServices_DspData_0x05CD_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CE_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData SWC_TestDCM_DataServices_DspData_0x05CE_22_RE
#define Rte_Call_DataServices_DspData_0x05CE_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CF_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData SWC_TestDCM_DataServices_DspData_0x05CF_22_RE
#define Rte_Call_DataServices_DspData_0x05CF_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05D0_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData SWC_TestDCM_DataServices_DspData_0x05D0_22_RE
#define Rte_Call_DataServices_DspData_0x05D0_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05D1_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData SWC_TestDCM_DataServices_DspData_0x05D1_22_RE
#define Rte_Call_DataServices_DspData_0x05D1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05D2_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData SWC_TestDCM_DataServices_DspData_0x05D2_22_RE
#define Rte_Call_DataServices_DspData_0x05D2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05D3_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData SWC_TestDCM_DataServices_DspData_0x05D3_22_RE
#define Rte_Call_DataServices_DspData_0x05D3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05D4_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData SWC_TestDCM_DataServices_DspData_0x05D4_22_RE
#define Rte_Call_DataServices_DspData_0x05D4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xCF00_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData SWC_TestDCM_DataServices_DspData_0xCF00_22_RE
#define Rte_Call_DataServices_DspData_0xCF00_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xCF05_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData SWC_TestDCM_DataServices_DspData_0xCF05_22_RE
#define Rte_Call_DataServices_DspData_0xCF05_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xCF06_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData SWC_TestDCM_DataServices_DspData_0xCF06_22_RE
#define Rte_Call_DataServices_DspData_0xCF06_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xCF07_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData SWC_TestDCM_DataServices_DspData_0xCF07_22_RE
#define Rte_Call_DataServices_DspData_0xCF07_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDD00_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData SWC_TestDCM_DataServices_DspData_0xDD00_22_RE
#define Rte_Call_DataServices_DspData_0xDD00_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF00_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF00_22_RE
#define Rte_Call_DataServices_DspData_0xDF00_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF01_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF01_22_RE
#define Rte_Call_DataServices_DspData_0xDF01_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF02_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF02_22_RE
#define Rte_Call_DataServices_DspData_0xDF02_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF03_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF03_22_RE
#define Rte_Call_DataServices_DspData_0xDF03_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF04_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF04_22_RE
#define Rte_Call_DataServices_DspData_0xDF04_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF06_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF06_22_RE
#define Rte_Call_DataServices_DspData_0xDF06_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF09_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF09_22_RE
#define Rte_Call_DataServices_DspData_0xDF09_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_Real_PedalPosition_0x0310_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData PMS_Real_PedalPosition_0x0310_CS_ReadData
#define Rte_Call_PMS_Real_PedalPosition_0x0310_CS_ReadData Rte_Call_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_Brake1Switch_0x0311_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData PMS_Brake1Switch_0x0311_CS_ReadData
#define Rte_Call_PMS_Brake1Switch_0x0311_CS_ReadData Rte_Call_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) EHB_EPBStatus_0x0312_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData EHB_EPBStatus_0x0312_CS_ReadData
#define Rte_Call_EHB_EPBStatus_0x0312_CS_ReadData Rte_Call_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_CPSREn_0x0313_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData PMS_CPSREn_0x0313_CS_ReadData
#define Rte_Call_PMS_CPSREn_0x0313_CS_ReadData Rte_Call_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_IsgTqReq_0x0314_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData PMS_IsgTqReq_0x0314_CS_ReadData
#define Rte_Call_PMS_IsgTqReq_0x0314_CS_ReadData Rte_Call_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_PTResiduePwrInd_0x0315_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData PMS_PTResiduePwrInd_0x0315_CS_ReadData
#define Rte_Call_PMS_PTResiduePwrInd_0x0315_CS_ReadData Rte_Call_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_ModeGearDisplaySts_0x0316_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData PMS_ModeGearDisplaySts_0x0316_CS_ReadData
#define Rte_Call_PMS_ModeGearDisplaySts_0x0316_CS_ReadData Rte_Call_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_DriveModeInd_0x0317_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData PMS_DriveModeInd_0x0317_CS_ReadData
#define Rte_Call_PMS_DriveModeInd_0x0317_CS_ReadData Rte_Call_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_FunLockVehActive_0x0318_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData PMS_FunLockVehActive_0x0318_CS_ReadData
#define Rte_Call_PMS_FunLockVehActive_0x0318_CS_ReadData Rte_Call_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PEPS_PowerMode_0x0319_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData PEPS_PowerMode_0x0319_CS_ReadData
#define Rte_Call_PEPS_PowerMode_0x0319_CS_ReadData Rte_Call_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_EDCPPWMCtrl_0x031A_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData PMS_EDCPPWMCtrl_0x031A_CS_ReadData
#define Rte_Call_PMS_EDCPPWMCtrl_0x031A_CS_ReadData Rte_Call_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_HBCPPWMCtrl_0x031B_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData PMS_HBCPPWMCtrl_0x031B_CS_ReadData
#define Rte_Call_PMS_HBCPPWMCtrl_0x031B_CS_ReadData Rte_Call_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_CoolingFanPWMSpd_0x031C_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData PMS_CoolingFanPWMSpd_0x031C_CS_ReadData
#define Rte_Call_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData Rte_Call_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_ACCMEnable_0x031D_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData PMS_ACCMEnable_0x031D_CS_ReadData
#define Rte_Call_PMS_ACCMEnable_0x031D_CS_ReadData Rte_Call_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_PTCEnable_0x031E_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData PMS_PTCEnable_0x031E_CS_ReadData
#define Rte_Call_PMS_PTCEnable_0x031E_CS_ReadData Rte_Call_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_PTC2Enable_0x031F_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData PMS_PTC2Enable_0x031F_CS_ReadData
#define Rte_Call_PMS_PTC2Enable_0x031F_CS_ReadData Rte_Call_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_PTC3Enable_0x0320_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData PMS_PTC3Enable_0x0320_CS_ReadData
#define Rte_Call_PMS_PTC3Enable_0x0320_CS_ReadData Rte_Call_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_SelfCheckSts_0x0321_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData PMS_SelfCheckSts_0x0321_CS_ReadData
#define Rte_Call_PMS_SelfCheckSts_0x0321_CS_ReadData Rte_Call_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_HVIL1Sts_0x0322_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData PMS_HVIL1Sts_0x0322_CS_ReadData
#define Rte_Call_PMS_HVIL1Sts_0x0322_CS_ReadData Rte_Call_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_HVIL2Sts_0x0323_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData PMS_HVIL2Sts_0x0323_CS_ReadData
#define Rte_Call_PMS_HVIL2Sts_0x0323_CS_ReadData Rte_Call_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData
#define Rte_Call_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData Rte_Call_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_EngRecMode_Fb_0x0325_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData PMS_EngRecMode_Fb_0x0325_CS_ReadData
#define Rte_Call_PMS_EngRecMode_Fb_0x0325_CS_ReadData Rte_Call_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) VCU_Odometerbackup_0x0326_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData VCU_Odometerbackup_0x0326_CS_ReadData
#define Rte_Call_VCU_Odometerbackup_0x0326_CS_ReadData Rte_Call_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_VehicleSpeed_0x0327_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData PMS_VehicleSpeed_0x0327_CS_ReadData
#define Rte_Call_PMS_VehicleSpeed_0x0327_CS_ReadData Rte_Call_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) AC_ACCM_ActPower_0x0328_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData AC_ACCM_ActPower_0x0328_CS_ReadData
#define Rte_Call_AC_ACCM_ActPower_0x0328_CS_ReadData Rte_Call_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData
#define Rte_Call_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData Rte_Call_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) IPU_SelfChkSts_0x032A_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData IPU_SelfChkSts_0x032A_CS_ReadData
#define Rte_Call_IPU_SelfChkSts_0x032A_CS_ReadData Rte_Call_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) BMSH_SelfCheckFault_0x032B_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData BMSH_SelfCheckFault_0x032B_CS_ReadData
#define Rte_Call_BMSH_SelfCheckFault_0x032B_CS_ReadData Rte_Call_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) DCDC_SelfChkSts_0x032C_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData DCDC_SelfChkSts_0x032C_CS_ReadData
#define Rte_Call_DCDC_SelfChkSts_0x032C_CS_ReadData Rte_Call_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_DcDcActvdReq_0x032D_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData PMS_DcDcActvdReq_0x032D_CS_ReadData
#define Rte_Call_PMS_DcDcActvdReq_0x032D_CS_ReadData Rte_Call_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_DCDCCutOffLV_0x032E_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData PMS_DCDCCutOffLV_0x032E_CS_ReadData
#define Rte_Call_PMS_DCDCCutOffLV_0x032E_CS_ReadData Rte_Call_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_IsgModReq_0x032F_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData PMS_IsgModReq_0x032F_CS_ReadData
#define Rte_Call_PMS_IsgModReq_0x032F_CS_ReadData Rte_Call_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) VCU_BMSH_StsModeReq_0x0330_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData VCU_BMSH_StsModeReq_0x0330_CS_ReadData
#define Rte_Call_VCU_BMSH_StsModeReq_0x0330_CS_ReadData Rte_Call_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_BatteryVol_0x0331_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData PMS_BatteryVol_0x0331_CS_ReadData
#define Rte_Call_PMS_BatteryVol_0x0331_CS_ReadData Rte_Call_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_IgnONSts_0x0332_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData PMS_IgnONSts_0x0332_CS_ReadData
#define Rte_Call_PMS_IgnONSts_0x0332_CS_ReadData Rte_Call_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_Brake2Switch_0x0333_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData PMS_Brake2Switch_0x0333_CS_ReadData
#define Rte_Call_PMS_Brake2Switch_0x0333_CS_ReadData Rte_Call_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) PMS_IPKTotalOdometer_0x0334_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData PMS_IPKTotalOdometer_0x0334_CS_ReadData
#define Rte_Call_PMS_IPKTotalOdometer_0x0334_CS_ReadData Rte_Call_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData
FUNC(Std_ReturnType, PMS_DID_CODE) ClearNumOfOdometer_0x0335_CS_ReadData(VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode);
#define Rte_Call_PMS_DID_ClearNumOfOdometer_0x0335_CS_ReadData ClearNumOfOdometer_0x0335_CS_ReadData
#define Rte_Call_ClearNumOfOdometer_0x0335_CS_ReadData Rte_Call_PMS_DID_ClearNumOfOdometer_0x0335_CS_ReadData
FUNC(Std_ReturnType, MCU_UDS_Interface_CODE) SWC_TestDCM_DataServices_DspData_0x0400_22_RE(VAR(UInt8_T, RTE_MCU_UDS_Interface_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_UDS_Interface_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_UDS_Interface_APPL_DATA) ErrorCode);
#define Rte_Call_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData SWC_TestDCM_DataServices_DspData_0x0400_22_RE
#define Rte_Call_DataServices_DspData_0x0400_ReadData Rte_Call_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_DTC_0x0402_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_MCU_DID_IPU_DTC_0x0402_CS_ReadData IPU_DTC_0x0402_CS_ReadData
#define Rte_Call_IPU_DTC_0x0402_CS_ReadData Rte_Call_MCU_DID_IPU_DTC_0x0402_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_IsgSpdActSgn_0x0403_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData IPU_IsgSpdActSgn_0x0403_CS_ReadData
#define Rte_Call_IPU_IsgSpdActSgn_0x0403_CS_ReadData Rte_Call_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData
#define Rte_Call_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData Rte_Call_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) PMS_DriverDemandTorque_0x0405_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData PMS_DriverDemandTorque_0x0405_CS_ReadData
#define Rte_Call_PMS_DriverDemandTorque_0x0405_CS_ReadData Rte_Call_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_TqAvlIsgMax_0x0406_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData IPU_TqAvlIsgMax_0x0406_CS_ReadData
#define Rte_Call_IPU_TqAvlIsgMax_0x0406_CS_ReadData Rte_Call_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_TqAvlIsgMin_0x0407_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData IPU_TqAvlIsgMin_0x0407_CS_ReadData
#define Rte_Call_IPU_TqAvlIsgMin_0x0407_CS_ReadData Rte_Call_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_HVBusVolt_500_0x0408_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData IPU_HVBusVolt_500_0x0408_CS_ReadData
#define Rte_Call_IPU_HVBusVolt_500_0x0408_CS_ReadData Rte_Call_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_HVBusCur_0x0409_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData IPU_HVBusCur_0x0409_CS_ReadData
#define Rte_Call_IPU_HVBusCur_0x0409_CS_ReadData Rte_Call_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_IsgMotT_0x040B_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData IPU_IsgMotT_0x040B_CS_ReadData
#define Rte_Call_IPU_IsgMotT_0x040B_CS_ReadData Rte_Call_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_IsgInvrT_0x040C_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_MCU_DID_IPU_IsgInvrT_0x040C_CS_ReadData IPU_IsgInvrT_0x040C_CS_ReadData
#define Rte_Call_IPU_IsgInvrT_0x040C_CS_ReadData Rte_Call_MCU_DID_IPU_IsgInvrT_0x040C_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_MotorTemp_0x040D_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData IPU_MotorTemp_0x040D_CS_ReadData
#define Rte_Call_IPU_MotorTemp_0x040D_CS_ReadData Rte_Call_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData
FUNC(Std_ReturnType, MCU_DID_CODE) IPU_DischgState_0X04CF_CS_ReadData(VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode);
#define Rte_Call_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData IPU_DischgState_0X04CF_CS_ReadData
#define Rte_Call_IPU_DischgState_0X04CF_CS_ReadData Rte_Call_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x03E2_Start_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start RoutineServices_0x03E2_Start_Services
#define Rte_Call_RoutineServices_0x03E2_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x03E2_Stop_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop RoutineServices_0x03E2_Stop_Services
#define Rte_Call_RoutineServices_0x03E2_Stop Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x4000_Start_Services(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4000_Start RoutineServices_0x4000_Start_Services
#define Rte_Call_RoutineServices_0x4000_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4000_Start
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x400F_Start_Services(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x400F_Start RoutineServices_0x400F_Start_Services
#define Rte_Call_RoutineServices_0x400F_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x400F_Start
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x4F02_Start_Services(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start RoutineServices_0x4F02_Start_Services
#define Rte_Call_RoutineServices_0x4F02_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x4F03_Start_Services(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start RoutineServices_0x4F03_Start_Services
#define Rte_Call_RoutineServices_0x4F03_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x4F04_Start_Services(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start RoutineServices_0x4F04_Start_Services
#define Rte_Call_RoutineServices_0x4F04_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x14_Operation(void);
#define Rte_Call_PMS_DID_ServiceCheckRule_0x14_Operation ServiceCheckRule_0x14_Operation
#define Rte_Call_ServiceCheckRule_0x14_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x14_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x28_Operation(void);
#define Rte_Call_PMS_DID_ServiceCheckRule_0x28_Operation ServiceCheckRule_0x28_Operation
#define Rte_Call_ServiceCheckRule_0x28_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x28_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x85_Operation(void);
#define Rte_Call_PMS_DID_ServiceCheckRule_0x85_Operation ServiceCheckRule_0x85_Operation
#define Rte_Call_ServiceCheckRule_0x85_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x85_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x1002_Operation(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond);
#define Rte_Call_PMS_DID_ServiceCheckRule_0x1002_Operation ServiceCheckRule_0x1002_Operation
#define Rte_Call_ServiceCheckRule_0x1002_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x1002_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x1003_Operation(P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond);
#define Rte_Call_PMS_DID_ServiceCheckRule_0x1003_Operation ServiceCheckRule_0x1003_Operation
#define Rte_Call_ServiceCheckRule_0x1003_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x1003_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x11_Operation(void);
#define Rte_Call_PMS_DID_ServiceCheckRule_0x11_Operation ServiceCheckRule_0x11_Operation
#define Rte_Call_ServiceCheckRule_0x11_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x11_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x22_Operation(void);
#define Rte_Call_PMS_DID_ServiceCheckRule_0x22_Operation ServiceCheckRule_0x22_Operation
#define Rte_Call_ServiceCheckRule_0x22_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x22_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x31_Operation(void);
#define Rte_Call_PMS_DID_ServiceCheckRule_0x31_Operation ServiceCheckRule_0x31_Operation
#define Rte_Call_ServiceCheckRule_0x31_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x31_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x27_Operation(void);
#define Rte_Call_PMS_DID_ServiceCheckRule_0x27_Operation ServiceCheckRule_0x27_Operation
#define Rte_Call_ServiceCheckRule_0x27_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x27_Operation
FUNC(Std_ReturnType, PMS_DID_CODE) ServiceCheckRule_0x2E_Operation(void);
#define Rte_Call_PMS_DID_ServiceCheckRule_0x2E_Operation ServiceCheckRule_0x2E_Operation
#define Rte_Call_ServiceCheckRule_0x2E_Operation Rte_Call_PMS_DID_ServiceCheckRule_0x2E_Operation
#endif
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#endif

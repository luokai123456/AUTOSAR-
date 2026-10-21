/*
********************************************************************************
*
* File name: Dcm_Callback.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: Tanlx/20190501
* Change: Autosar
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: lqiao/20220831
* Change: Dcm_37_RoutineFunction
* Cause: Add function declare
********************************************************************************
* Version: 3.0
* Author/Date: LQiao/2023.2.13
* Change: DCM_SERVICE_38
* Cause: Optimization
********************************************************************************
*/
#ifndef DCM_CALLBACK_H_
#define DCM_CALLBACK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Dcm_Cbk.h"
#include "ComStack_Types.h"
#include "Dcm.h"

#if( STD_ON == DCM_DEM_SUPPORT )
#include "Dem_Dcm.h"
#endif

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/*
********************************************************************************
*    Global Types
********************************************************************************
*/

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
#define DCM_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if ( STD_ON == DCM_SERVICE_01_ENABLED )
	

#endif /* STD_ON == DCM_SERVICE_01_ENABLED */

#if ( STD_ON == DCM_SERVICE_02_ENABLED )


#endif /* STD_ON == DCM_SERVICE_02_ENABLED */

#if ( STD_ON == DCM_SERVICE_09_ENABLED )

	
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_InfotypeServices_Pid02 (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) data, P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA)pLen, uint8 pidIndex);

#endif /* STD_ON == DCM_SERVICE_09_ENABLED */

#if (STD_ON == DCM_SERVICE_10_ENABLED)
extern FUNC(uint8, DCM_CODE) Dcm_Check10SubProgrammingFunc(void);
extern FUNC(uint8, DCM_CODE) Dcm_Check10SubextendedFunc(void);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_Check10WithPara(uint8 Subfunc, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_SetProgConditions(Dcm_OpStatusType OpStatus, P2VAR(Dcm_ProgConditionsType, AUTOMATIC, DCM_APPL_DATA) ProgConditions);
extern FUNC(void, DCM_CODE) Dcm_10_JumpToBootWithAppResp(void);
extern FUNC(void, DCM_CODE) Dcm_10_JumpToBootWithBootResp(void);
extern FUNC(void, DCM_CODE) Dcm_OnChangeParameter(uint8 stateGroupIdx, uint8 newStateIdx);
extern FUNC(void, DCM_CODE) Dcm_10_SessionChangedCallBack(void);
extern FUNC(void, DCM_CODE) Dcm_SessionChangedMode(uint8 sessionMode);
#endif /* STD_ON == DCM_SERVICE_10_ENABLED */

#if (STD_ON == DCM_SERVICE_11_ENABLED)
extern FUNC(uint8, DCM_CODE) Dcm_Check11SubResetFunc(void);
extern FUNC(uint8, DCM_CODE) Dcm_PrepareResetFunc(void);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_Check11WithPara(uint8 Subfunc, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(void, DCM_CODE) Dcm_EcuResetMode(uint8 acRequestedMode);
#endif /* STD_ON == DCM_SERVICE_11_ENABLED */

#if (STD_ON == DCM_SERVICE_14_ENABLED)
extern FUNC(uint8, DCM_CODE) Dcm_14_CheckRuleFunc(void);
extern FUNC(void, DCM_CODE) Dcm_ClearCallBackFunc(void);
#endif /* STD_ON == DCM_SERVICE_14_ENABLED */

 
#if ( (STD_ON == DCM_SERVICE_22_ENABLED) || (STD_ON == DCM_SERVICE_2E_ENABLED) || (STD_ON == DCM_SERVICE_2A_ENABLED) || (STD_ON == DCM_SERVICE_2C_ENABLED) )
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F199_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F199_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F199_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F187_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F187_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F187_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F18A_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F18A_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F18A_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F190_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F190_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F190_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F190_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F190_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F1A2_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F1A2_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F1A2_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F1A2_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F1A2_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F191_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F191_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F191_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F189_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F189_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F189_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F193_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F193_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F193_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F195_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F195_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F195_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F180_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F180_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F180_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F112_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F112_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F112_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F112_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F112_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F198_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F198_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F198_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F197_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F197_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F197_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F197_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F197_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F113_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F113_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F113_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F182_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F182_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F182_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F186_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F186_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F186_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F18B_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F18B_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F18B_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F18C_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F18C_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F18C_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0200_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0200_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0200_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0201_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0201_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0201_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFEC_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFEC_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFEC_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFEC_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFEC_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFED_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFED_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFED_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFED_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFED_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFEE_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFEE_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFEE_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFEE_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFEE_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFEF_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFEF_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFEF_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFEF_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DFEF_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F101_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F101_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F101_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F101_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F101_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F110_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F110_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F110_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F110_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F110_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F1A3_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F1A3_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F1A3_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F1A4_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F1A4_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F1A4_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F1A5_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F1A5_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F1A5_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_D135_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_D135_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_D135_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_D136_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_D136_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_D136_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0280_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0280_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0280_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0310_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0310_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0310_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0311_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0311_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0311_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0312_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0312_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0312_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0313_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0313_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0313_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0314_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0314_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0314_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0315_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0315_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0315_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0316_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0316_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0316_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0317_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0317_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0317_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0318_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0318_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0318_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0319_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0319_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0319_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031A_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031A_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031A_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031B_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031B_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031B_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031C_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031C_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031C_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031D_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031D_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031D_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031E_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031E_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031E_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031F_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031F_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_031F_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0320_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0320_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0320_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0321_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0321_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0321_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0322_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0322_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0322_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0323_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0323_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0323_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0324_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0324_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0324_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0325_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0325_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0325_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0326_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0326_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0326_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0327_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0327_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0327_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0328_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0328_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0328_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0329_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0329_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0329_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032A_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032A_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032A_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032B_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032B_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032B_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032C_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032C_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032C_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032D_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032D_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032D_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032E_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032E_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032E_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032F_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032F_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_032F_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0330_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0330_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0330_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0331_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0331_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0331_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0332_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0332_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0332_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0333_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0333_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0333_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0334_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0334_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0334_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0335_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0335_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0335_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF00_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF00_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF00_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0501_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0501_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0501_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0502_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0502_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0502_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0503_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0503_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0503_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0504_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0504_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0504_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0507_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0507_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0507_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_050A_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_050A_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_050A_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_CF00_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_CF00_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_CF00_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_CF05_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_CF05_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_CF05_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF09_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF09_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF09_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0525_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0525_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0525_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0526_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0526_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0526_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0527_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0527_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0527_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0528_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0528_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0528_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0529_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0529_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0529_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_CF06_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_CF06_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_CF06_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_052B_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_052B_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_052B_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_CF07_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_CF07_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_CF07_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_052D_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_052D_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_052D_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0530_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0530_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0530_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0531_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0531_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0531_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0532_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0532_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0532_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0533_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0533_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0533_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0534_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0534_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0534_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0535_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0535_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0535_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0536_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0536_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0536_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0537_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0537_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0537_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0538_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0538_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0538_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0539_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0539_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0539_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0505_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0505_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0505_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_053B_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_053B_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_053B_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_053C_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_053C_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_053C_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_053D_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_053D_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_053D_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_053E_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_053E_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_053E_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0542_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0542_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0542_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0543_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0543_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0543_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0544_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0544_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0544_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0545_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0545_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0545_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0547_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0547_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0547_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0552_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0552_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0552_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_055A_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_055A_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_055A_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_055C_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_055C_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_055C_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_055D_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_055D_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_055D_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0585_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0585_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0585_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0586_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0586_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0586_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0587_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0587_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0587_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0588_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0588_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0588_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0589_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0589_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0589_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058A_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058A_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058A_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058B_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058B_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058B_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058C_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058C_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058C_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058D_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058D_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058D_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058E_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058E_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058E_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058F_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058F_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_058F_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0590_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0590_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0590_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0591_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0591_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0591_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0592_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0592_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0592_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0593_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0593_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0593_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0594_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0594_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0594_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0595_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0595_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0595_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0596_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0596_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0596_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0597_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0597_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0597_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0598_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0598_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0598_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0599_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0599_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0599_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059A_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059A_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059A_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059B_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059B_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059B_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059D_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059D_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059D_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059E_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059E_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059E_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059F_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059F_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059F_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DD00_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DD00_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DD00_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A1_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A2_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A3_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A3_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A4_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A4_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A4_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A5_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A5_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A5_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A6_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A6_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A6_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A7_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A7_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A7_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A8_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A8_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A8_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A9_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A9_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05A9_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AA_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AA_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AA_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AB_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AB_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AB_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AC_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AC_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AD_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AD_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AD_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AE_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AE_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AE_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AF_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AF_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05AF_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B0_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B0_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B0_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B1_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B2_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B3_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B3_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B4_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B4_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B4_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B5_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B5_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B5_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B6_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B6_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B6_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B7_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B7_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B7_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B8_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B8_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B8_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B9_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B9_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05B9_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BA_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BA_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BA_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BB_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BB_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BB_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BC_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BC_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BD_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BD_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BD_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BE_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BE_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BE_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BF_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BF_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05BF_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C0_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C0_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C0_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C1_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C2_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C3_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C3_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C4_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C4_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C4_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C5_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C5_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C5_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C6_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C6_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C6_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C7_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C7_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C7_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C8_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C8_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C8_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C9_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C9_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05C9_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CA_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CA_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CA_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CB_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CB_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CB_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CC_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CC_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CD_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CD_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CD_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CE_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CE_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CE_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CF_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CF_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05CF_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D0_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D0_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D0_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D1_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D2_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D3_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D3_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D4_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D4_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D4_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF01_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF01_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF01_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF02_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF02_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF02_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF03_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF03_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF03_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF04_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF04_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF04_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF06_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF06_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF06_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D5_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D5_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D5_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D5_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D5_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D6_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D6_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D6_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D6_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D6_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D7_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D7_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D7_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D7_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D7_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D8_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D8_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D8_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D8_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D8_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D9_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D9_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D9_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D9_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05D9_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05DA_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05DA_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05DA_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05DA_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05DA_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05DB_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05DB_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05DB_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05DB_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_05DB_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059C_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059C_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_059C_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_052E_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_052E_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_052E_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF0A_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF0A_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF0A_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF0B_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF0B_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF0B_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF0C_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF0C_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF0C_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF0D_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF0D_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF0D_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF0E_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF0E_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_DF0E_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0402_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0402_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0402_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0403_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0403_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0403_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0404_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0404_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0404_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0405_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0405_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0405_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0406_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0406_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0406_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0407_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0407_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0407_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0408_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0408_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0408_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0409_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0409_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0409_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_040B_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_040B_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_040B_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_040C_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_040C_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_040C_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_040D_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_040D_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_040D_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_04CF_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_04CF_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_04CF_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F800_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F800_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F800_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F802_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F802_ReadData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F802_WriteData(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F802_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_F802_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0400_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0400_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_0400_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_04DC_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_04DC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_04DC_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_04DD_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_04DD_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_04DD_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_04DE_ReadDataLength(P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_04DE_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgr_04DE_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
#endif /* (STD_ON == DCM_SERVICE_22_ENABLED) || (STD_ON == DCM_SERVICE_2E_ENABLED) || (STD_ON == DCM_SERVICE_2A_ENABLED) || (STD_ON == DCM_SERVICE_2C_ENABLED) */
 
#if (STD_ON == DCM_SERVICE_27_ENABLED)
/* Polyspace-begin MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5"  Polyspace-begin MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_Rule5.1" */
/* Polyspace +1 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_Rule5.1" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_SecurityAccess_Level_01_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_SecurityAccess_Level_01_CompareKey(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_SecurityAccess_Level_01_GetAttemptCounter(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) AttemptCounter);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_SecurityAccess_Level_01_SetAttemptCounter(Dcm_OpStatusType OpStatus, uint8 AttemptCounter);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(uint8, DCM_CODE) Dcm_SecurityAccess_Level_01_CheckRule(void);
extern FUNC(void, DCM_CODE) Dcm_SecurityAcces_CalcRand(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) ranSeed);
/* Polyspace-end MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5"  Polyspace-end MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_Rule5.1" */
#endif /* STD_ON == DCM_SERVICE_27_ENABLED */
 
#if (STD_ON == DCM_SERVICE_2F_ENABLED)
extern VAR(uint8,DCM_CODE) Dcm_Check2FSubIOFunc(void);
#endif/* STD_ON == DCM_SERVICE_2F_ENABLED */
 
#if (STD_ON == DCM_SERVICE_31_ENABLED)
/* Polyspace-begin MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) StartRoutineFunc_0x03E0(P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) DataInVar, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) DataOutVar, uint16 CurrentLengthDataInVar, P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) CurrentLengthDataOutVar, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorPtr);
extern FUNC(Std_ReturnType, DCM_CODE) StartRoutineFunc_0x03E1(P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) DataInVar, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) DataOutVar, uint16 CurrentLengthDataInVar, P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) CurrentLengthDataOutVar, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorPtr);
extern FUNC(Std_ReturnType, DCM_CODE) StartRoutineFunc_0x03E2(P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) DataInVar, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) DataOutVar, uint16 CurrentLengthDataInVar, P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) CurrentLengthDataOutVar, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorPtr);
extern FUNC(Std_ReturnType, DCM_CODE) StopRoutineFunc_0x03E2(P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) DataInVar, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) DataOutVar, uint16 CurrentLengthDataInVar, P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) CurrentLengthDataOutVar, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorPtr);
extern FUNC(Std_ReturnType, DCM_CODE) StartRoutineFunc_0x03E4(P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) DataInVar, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) DataOutVar, uint16 CurrentLengthDataInVar, P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) CurrentLengthDataOutVar, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorPtr);
extern FUNC(Std_ReturnType, DCM_CODE) StartRoutineFunc_0x400F(P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) DataInVar, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) DataOutVar, uint16 CurrentLengthDataInVar, P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) CurrentLengthDataOutVar, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorPtr);
extern FUNC(Std_ReturnType, DCM_CODE) StartRoutineFunc_0x4000(P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) DataInVar, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) DataOutVar, uint16 CurrentLengthDataInVar, P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) CurrentLengthDataOutVar, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorPtr);
extern FUNC(Std_ReturnType, DCM_CODE) StartRoutineFunc_0x4F02(P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) DataInVar, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) DataOutVar, uint16 CurrentLengthDataInVar, P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) CurrentLengthDataOutVar, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorPtr);
extern FUNC(Std_ReturnType, DCM_CODE) StartRoutineFunc_0x4F03(P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) DataInVar, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) DataOutVar, uint16 CurrentLengthDataInVar, P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) CurrentLengthDataOutVar, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorPtr);
extern FUNC(Std_ReturnType, DCM_CODE) StartRoutineFunc_0x4F04(P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) DataInVar, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) DataOutVar, uint16 CurrentLengthDataInVar, P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) CurrentLengthDataOutVar, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorPtr);
/* Polyspace-end MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
#endif /* STD_ON == DCM_SERVICE_31_ENABLED */

#if (STD_ON == DCM_SERVICE_28_ENABLED)
extern FUNC(uint8, DCM_CODE) Dcm_Check28SubComMFunc(void);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_Check28WithPara(uint8 Subfunc, uint8 Comtype, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_OnChgModeComControl(uint8 subfunc, uint8 comtype);
#endif /* STD_ON == DCM_SERVICE_28_ENABLED */

#if ( STD_ON == DCM_SERVICE_85_ENABLED )
extern FUNC(uint8, DCM_CODE) Dcm_Check85SubDtcSettingFunc(void);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_Notify85SubDtcSettingFunc(uint8 subFunc);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_OnChgModeCtrlDTCSetting(uint8 subFunc);
#endif /* STD_ON == DCM_SERVICE_85_ENABLED */

#if (STD_ON == DCM_SERVICE_87_ENABLED)
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_LinkControl_01_02_03(Dcm_OpStatusType OpStatus, uint8 ID, uint8 LinkControlModeId, uint32* LinkRecord, Dcm_NegativeResponseCodeType* ErrorCode);
#endif /* STD_ON == DCM_SERVICE_87_ENABLED */



#if (STD_ON == DCM_SERVICE_34_ENABLED)
extern FUNC(void, DCM_CODE) Dcm_34_PreConditionCheckRead
(
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_ProcessRequestDownload
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Dcm_OpStatusType OpStatus,
    uint8 DataFormatIdentifier,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    P2VAR(uint32, AUTOMATIC, DCM_APPL_DATA) BlockLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);

#endif /* STD_ON == DCM_SERVICE_34_ENABLED */

#if (STD_ON == DCM_SERVICE_35_ENABLED)
extern FUNC(void, DCM_CODE) Dcm_35_PreConditionCheckRead
(
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);
extern FUNC(uint8, DCM_CODE) Dcm_ProcessRequestUpload
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier,
    uint8 MemoryIdentifier, uint32 MemoryAddress, uint32 MemorySize,
    P2VAR(uint32, AUTOMATIC, DCM_APPL_DATA) BlockLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);
#endif /* STD_ON == DCM_SERVICE_35_ENABLED */

#if ( (STD_ON == DCM_SERVICE_10_ENABLED) || (STD_ON == DCM_SERVICE_28_ENABLED) )
/* Polyspace +1 MISRA-C3:8.5 [Justified:Unset] "NSCA_Polyspace_Dcm_8.5" */
extern FUNC(void, DCM_CODE) Dcm_ControlCommunication(uint8 subfunc, uint8 comtype);  /* PRQA S 3451 */ /* NSCA_QAC_Dcm_Rule8.5 */
#endif /* (STD_ON == DCM_SERVICE_10_ENABLED) || (STD_ON == DCM_SERVICE_28_ENABLED) */	

#if (STD_ON == DCM_SERVICE_36_ENABLED)
extern FUNC(Dcm_ReturnWriteMemoryType, DCM_CODE) Dcm_WriteMemory
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Dcm_OpStatusType OpStatus,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) MemoryData,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);
extern FUNC(Dcm_ReturnReadMemoryType, DCM_CODE) Dcm_36_RoutineFunctionForDcm35
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Dcm_OpStatusType OpStatus,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) MemoryData,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);
                                        
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_36_RoutineFunctionForDcm38(uint8 seqNum, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorPtr);
#endif /* STD_ON == DCM_SERVICE_36_ENABLED */

#if (STD_ON == DCM_SERVICE_37_ENABLED)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_ProcessRequestTransferExit
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) transferRequestParameterRecord,
    uint32 transferRequestParameterRecordSize,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) transferResponseParameterRecord,
    P2VAR(uint32, AUTOMATIC, DCM_APPL_DATA) transferResponseParameterRecordSize,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);
extern FUNC(uint8, DCM_CODE) Dcm_37_RoutineFunctionForDcm35(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) DataBuffer, P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataBufferLen, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_37_RoutineFunctionForDcm38(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorPtr);
#endif/* STD_ON == DCM_SERVICE_37_ENABLED */

#if (STD_ON == DCM_SERVICE_29_ENABLED)






#endif /* STD_ON == DCM_SERVICE_29_ENABLED */

#if (STD_ON == DCM_SERVICE_2C_ENABLED)
#endif /* STD_ON == DCM_SERVICE_2C_ENABLED */

#if (STD_ON == DCM_SERVICE_38_ENABLED)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_38_Info_Trans(P2CONST(Dcm_38_ServiceInfoType_Req, AUTOMATIC, DCM_APPL_DATA) DataInVar, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorPtr);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_38_Info_Capture(P2VAR(Dcm_38_ServiceInfoType_Res, AUTOMATIC, DCM_APPL_DATA) DataOutVar, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorPtr);
#endif/* STD_ON == DCM_SERVICE_38_ENABLED */

#if ( STD_ON == DCM_REQUESTMANUFACTURERNOTIFICATION_ENABLED )
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDsdServiceRequestManufacturerNotification_Ind
(
    uint8 SID,
    P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) RequestData,
    uint16 DataSize,
    uint8 ReqType,
    uint16 SourceAddress,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDsdServiceRequestManufacturerNotification_Conf
(
    uint8 SID,
    uint8 ReqType,
    uint16 SourceAddress,
    Std_ReturnType ConfirmationStatus  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
);
#endif /* STD_ON == DCM_REQUESTMANUFACTURERNOTIFICATION_ENABLED */

#if ( STD_ON == DCM_REQUESTSUPPLIERNOTIFICATION_ENABLED )
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDsdServiceRequestSupplierNotification_Ind
(
    uint8 SID,
    P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) RequestData,
    uint16 DataSize,
    uint8 ReqType,
    uint16 SourceAddress,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDsdServiceRequestSupplierNotification_Conf
(
    uint8 SID,
    uint8 ReqType,
    uint16 SourceAddress,
    Std_ReturnType ConfirmationStatus  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
);
#endif /* STD_ON == DCM_REQUESTSUPPLIERNOTIFICATION_ENABLED */

extern FUNC(uint8, DCM_CODE) Dcm_10_CheckRule(void);
extern FUNC(uint8, DCM_CODE) Dcm_11_CheckRule(void);
extern FUNC(uint8, DCM_CODE) Dcm_14_CheckRule(void);
extern FUNC(uint8, DCM_CODE) Dcm_19_CheckRule(void);
extern FUNC(uint8, DCM_CODE) Dcm_22_CheckRule(void);
extern FUNC(uint8, DCM_CODE) Dcm_27_CheckRule(void);
extern FUNC(uint8, DCM_CODE) Dcm_28_CheckRule(void);
extern FUNC(uint8, DCM_CODE) Dcm_2E_CheckRule(void);
extern FUNC(uint8, DCM_CODE) Dcm_31_CheckRule(void);
extern FUNC(uint8, DCM_CODE) Dcm_3E_CheckRule(void);
extern FUNC(uint8, DCM_CODE) Dcm_85_CheckRule(void);
extern FUNC(uint8, DCM_CODE) Dcm_01_CheckRule(void);
extern FUNC(uint8, DCM_CODE) Dcm_09_CheckRule(void);

#if (ENABLE_HSM == 1)
typedef enum
{
    SECU_OPERATIONMODE_START = 0x01U,
    SECU_OPERATIONMODE_UPDATE = 0x02U,
    SECU_OPERATIONMODE_FINISH = 0x04U,
    SECU_OPERATIONMODE_SINGLECALL = 0x07U
} Secu_OperationModeType;

extern Std_ReturnType SecuAuth_Calculate_AesCmacGenerate
(
    uint32 cryptoKeyId,
	Secu_OperationModeType eOptMode,
    const uint8 *pInput,
    uint32 inputLen,
	uint8 *pOutput,
    uint32 *pOutputLen
);
extern Std_ReturnType SecuAuth_RandomGenerate
(
	uint8 *outputPtr,
    uint32 outputLength   
);

extern uint8 Randc[8];
extern uint8 Dcm_security_seed_Rand[16];
extern volatile uint8 DCM_RANDNUM_RETURNValue;
extern void DCM_27_Security_Access_Specification(void);
#else
extern uint8 Randc[8];
extern uint8 Rands[8];
extern uint8 Dcm_security_seed_Rand[16];
extern uint8 Respones_Key[16];
extern void DCM_27_Security_Get_Seed(uint8 *Seed);
extern void DCM_27_Security_Access_Specification(void);
#endif

#define DCM_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#endif /* DCM_CALLBACK_H_ */
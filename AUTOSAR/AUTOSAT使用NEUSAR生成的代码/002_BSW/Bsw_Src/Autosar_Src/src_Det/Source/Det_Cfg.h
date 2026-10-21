/*
********************************************************************************
*
* File name: Det_Cfg.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2019.6.18
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: FangT/2020.11.05
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.1
* Author/Date : FangT/2020.11.06
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: ZengJX/2024.07.18
* Change: 1.Modify copyright information.
*         2.Fix Det memmap issue.
* Cause: Optimization
********************************************************************************
*/
#ifndef DET_CFG_H_
#define DET_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Det_2.5" */
#define USE_DET                                  (STD_ON)
#define DET_FORWARD_TO_DLT                       (STD_ON)
#define DET_VERSION_INFO_API                     (STD_ON)
#define DET_ERR_HOOK_ENABLE                      (STD_OFF)
#define DET_RUNTIME_ERR_ENABLE                   (STD_ON)
#define DET_TRANSIENT_FAULT_ENABLE               (STD_ON)
#define DET_RUNTIME_ERR_CALLOUT_NUM              (1)
#define DET_TRANSIENT_FAULT_CALLOUT_NUM          (1)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Det_2.5" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef Std_ReturnType (* Det_CalloutTableType)(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

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
#define DET_START_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"
extern CONST(Det_CalloutTableType, DET_CONFIG_DATA) Det_RuntimeErrorCalloutTable[DET_RUNTIME_ERR_CALLOUT_NUM];
extern CONST(Det_CalloutTableType, DET_CONFIG_DATA) Det_TransientFaultCalloutTable[DET_TRANSIENT_FAULT_CALLOUT_NUM];

#define DET_STOP_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
#define DET_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"
extern FUNC(Std_ReturnType, DET_CODE) RunTime_fun(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

extern FUNC(Std_ReturnType, DET_CODE) Transient_fun(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

#define DET_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"

#endif  /* DET_CFG_H_ */


/*
********************************************************************************
*
* File name: ComM_Nm.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: Tanlx/2019.05.01
* Change: Autosar
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: jiafeng/2020.07.02
* Change: Nothing
* Cause: Update to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: fangtao/2020.10.28
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: HeHao/2024.04.02
* Change: Modify comments.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: TianL/2024.05.15
* Change: 1. Add a MemMap paragraph definition to the function declaration.
*         2. Modify coding specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: TianL/2024.8.5
* Change: Modify copyright.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: TianL/2025.6.16
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef COMM_NM_H_
#define COMM_NM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComM_Cfg.h"

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
#define COMM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"

extern FUNC(void, COMM_CODE) ComM_Nm_BusSleepMode(NetworkHandleType Channel);
extern FUNC(void, COMM_CODE) ComM_Nm_NetworkMode(NetworkHandleType Channel);
extern FUNC(void, COMM_CODE) ComM_Nm_PrepareBusSleepMode(NetworkHandleType Channel);
extern FUNC(void, COMM_CODE) ComM_Nm_NetworkStartIndication(NetworkHandleType Channel);
extern FUNC(void, COMM_CODE) ComM_Nm_RestartIndication(NetworkHandleType Channel);

#define COMM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"

#endif  /* COMM_NM_H_ */

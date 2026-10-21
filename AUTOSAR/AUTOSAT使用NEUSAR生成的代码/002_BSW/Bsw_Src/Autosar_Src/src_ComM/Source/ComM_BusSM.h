/*
********************************************************************************
*
* File name: ComM_BusSM.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: TanLX/20190505
* Change: New
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: JiaFeng/2020.07.02
* Change: Nothing
* Cause: Update to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: HeHao/2024.03.11
* Change: 1. Change P2CONST's ptrclass from XXX_APPL_CONST to XXX_APPL_DATA.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: HeHao/2024.04.02
* Change: Modify comments.
* Cause: Update
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
#ifndef COMM_BUSSM_H_
#define COMM_BUSSM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComM_Types.h"

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

extern FUNC(void, COMM_CODE) ComM_BusSM_ModeIndication
(
    NetworkHandleType Channel,
    P2CONST(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
);

#define COMM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"

#endif  /* COMM_BUSSM_H_ */

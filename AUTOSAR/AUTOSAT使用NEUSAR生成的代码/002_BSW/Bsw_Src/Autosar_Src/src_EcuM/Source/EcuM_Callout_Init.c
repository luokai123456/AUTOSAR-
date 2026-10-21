/*
********************************************************************************
*
* File name: EcuM_Callout_Init.c
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
*  Version: 3.0
*  Author/Date : yong.zhang/2020.10.24
*  Change: New created
*  Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: TianL/2024.8.5
* Change: Modify copyright.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "EcuM.h"
#include "EcuM_Callout_Init.h"
#include "Evpt_EcuM.h"
/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/*
********************************************************************************
*    Local Types
********************************************************************************
*/
/*
********************************************************************************
*    Local Variables
********************************************************************************
*/
/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
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
/* polyspace-begin MISRA-C3:8.4 [Justified:Unset] "NSCA_Polyspace_EcuM_Rule8.4" */
/* polyspace-begin MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_EcuM_Rule8.7" */
/* polyspace-begin VARIABLE:* [Justified:Unset] "NSCA_Polyspace_EcuM_UsedNonSharedVariable" */
#define ECUM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


FUNC(void, ECUM_CODE) EcuM_InitZero_core0(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */
}

FUNC(void, ECUM_CODE) EcuM_InitZero_core1(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */
}

FUNC(void, ECUM_CODE) EcuM_InitZero_core2(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */
}

FUNC(void, ECUM_CODE) EcuM_InitZero_core3(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */
}

FUNC(void, ECUM_CODE) EcuM_InitZero_core4(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */
}

FUNC(void, ECUM_CODE) EcuM_InitZero_core5(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */
}

FUNC(void, ECUM_CODE) EcuM_InitOne_core0(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */

	EcuM_DriverInit_core0();
}

FUNC(void, ECUM_CODE) EcuM_InitOne_core1(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */

	EcuM_DriverInit_core1();
}

FUNC(void, ECUM_CODE) EcuM_InitOne_core2(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */

	EcuM_DriverInit_core2();
}

FUNC(void, ECUM_CODE) EcuM_InitOne_core3(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */
	EcuM_DriverInit_core3();
}

FUNC(void, ECUM_CODE) EcuM_InitOne_core4(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */
	EcuM_DriverInit_core4();
	
}

FUNC(void, ECUM_CODE) EcuM_InitOne_core5(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */
	EcuM_DriverInit_core5();
}

#define ECUM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define ECUM_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

CONST(EcuM_DriverInitFuncSt,ECUM_CONFIG_DATA) EcuM_DriverInitFuncTbl[ECUM_NUMBER_OF_CORES]=  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */
{
	{0, EcuM_InitZero_core0, EcuM_InitOne_core0},
	{1, EcuM_InitZero_core1, EcuM_InitOne_core1},
	{2, EcuM_InitZero_core2, EcuM_InitOne_core2},
	{3, EcuM_InitZero_core3, EcuM_InitOne_core3},
	{4, EcuM_InitZero_core4, EcuM_InitOne_core4},
	{5, EcuM_InitZero_core5, EcuM_InitOne_core5},
};

/* polyspace-end MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_EcuM_Rule8.7" */
/* polyspace-end MISRA-C3:8.4 [Justified:Unset] "NSCA_Polyspace_EcuM_Rule8.4" */
/* polyspace-end VARIABLE:* [Justified:Unset] "NSCA_Polyspace_EcuM_UsedNonSharedVariable" */
#define ECUM_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


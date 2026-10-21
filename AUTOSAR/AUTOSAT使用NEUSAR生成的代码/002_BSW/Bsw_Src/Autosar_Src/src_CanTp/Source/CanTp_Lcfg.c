/*
********************************************************************************
*
* File name: CanTp_Lcfg.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : Tanlx/2019.03.10
* Change: New
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : Songqw/2019.11.11
* Change: Add the tx pduId to the CanTpRxSdu structure.
* Cause: update
********************************************************************************
* Version: 1.2
* Author/Date : Liuziyang/2019.11.19
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 3.0
* Author/Date: LiuZY/2020.11.03
* Change: Modify the incorrectly defined part of the code format.
* Cause: Optimization
********************************************************************************
* Version: 3.1
* Author/Date: YanCL/2024.7.3
* Change: Update copyright information.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanTp_Lcfg.h"
#include "CanIf.h"

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
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANTP_START_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* Polyspace-begin VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanTp_GlobalVariables" */


VAR(CanTpRxNSdu_st, CANTP_VAR_INIT) CanTpRxSdu[CANTP_RXSDU_NUM + 1] = /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{ 0, 0U, 281, CANTP_STANDARD, CANTP_PHYSICAL, CANTP_ON, 64U, 0U, 255U, 25U, 35U, 150U, 10U, 0U }, 
	{ 1, 0U, 287, CANTP_STANDARD, CANTP_FUNCTIONAL, CANTP_ON, 64U, 0U, 255U, 25U, 35U, 150U, 10U, 0U }, 
	{ 2, 1U, 288, CANTP_STANDARD, CANTP_PHYSICAL, CANTP_ON, 64U, 0U, 255U, 25U, 35U, 150U, 10U, 1U }, 
	{ 0xFFFF, 0xFFFF, 0xFFFF, 0xFF, 0xFF, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0 }
};

VAR(CanTpTxNSdu_st, CANTP_VAR_INIT) CanTpTxSdu[CANTP_TXSDU_NUM + 1] = /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{ 0, 233, 266, CANTP_STANDARD, CANTP_PHYSICAL, CANTP_ON, 8U, 25U, 75U, 100U, 0U, CANTP_CANFD, CanIf_Transmit }, 
	{ 1, 239, 267, CANTP_STANDARD, CANTP_PHYSICAL, CANTP_ON, 8U, 25U, 75U, 100U, 1U, CANTP_CANFD, CanIf_Transmit }, 
	{ 0xFFFF, 0xFFFF, 0xFFFF, 0xFF, 0xFF, 0xFF, 0, 0, 0, 0, 0, CANTP_CAN20, CanIf_Transmit }
};

/* Polyspace-end VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanTp_GlobalVariables" */

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANTP_STOP_SEC_VAR_INIT 
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/


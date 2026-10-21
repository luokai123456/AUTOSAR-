/*
********************************************************************************
*
* File name: CanSM_Lcfg.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: WangCong/2019.10.01
* Change: New
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: TianL/2024.8.5
* Change: Modify copyright.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Include
********************************************************************************
*/
#include "CanSM_Lcfg.h"

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

#define CANSM_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanSM_UsedNonSharedVariable" */
CONST(CanSM_ManagerNetworkType, CANSM_CONFIG_DATA) CanSM_ManagerNetworkCfg[CANSM_MANAGER_NW_NUM] = {
{
	0,FALSE,0xFFU,1U,TRUE,FALSE,10U,(100U/CANSM_MAINFUNC_PERIOD),(1000U/CANSM_MAINFUNC_PERIOD),0x0U,6000U/CANSM_MAINFUNC_PERIOD,FALSE},
{
	1,FALSE,0xFFU,2U,TRUE,FALSE,10U,(100U/CANSM_MAINFUNC_PERIOD),(1000U/CANSM_MAINFUNC_PERIOD),32892U,6000U/CANSM_MAINFUNC_PERIOD,FALSE},
{
	2,FALSE,0xFFU,3U,TRUE,FALSE,10U,(100U/CANSM_MAINFUNC_PERIOD),(1000U/CANSM_MAINFUNC_PERIOD),0x0U,6000U/CANSM_MAINFUNC_PERIOD,FALSE},
{
	3,FALSE,0xFFU,4U,TRUE,FALSE,10U,(100U/CANSM_MAINFUNC_PERIOD),(1000U/CANSM_MAINFUNC_PERIOD),0x0U,6000U/CANSM_MAINFUNC_PERIOD,FALSE},
{
	4,FALSE,0xFFU,5U,TRUE,FALSE,10U,(100U/CANSM_MAINFUNC_PERIOD),(1000U/CANSM_MAINFUNC_PERIOD),32936U,6000U/CANSM_MAINFUNC_PERIOD,FALSE},
{
	5,FALSE,0xFFU,6U,TRUE,FALSE,10U,(100U/CANSM_MAINFUNC_PERIOD),(1000U/CANSM_MAINFUNC_PERIOD),32891U,6000U/CANSM_MAINFUNC_PERIOD,FALSE},
};
#define CANSM_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */



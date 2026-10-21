/*
********************************************************************************
*
* nvmFile name: LinSM_Lcfg.c
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJP/2020.04.07
* Change: new created.
* Cause: New
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "LinSM_Cfg.h"

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
#define LINSM_START_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinSM_UsedNonSharedVariable" */
VAR(LinSM_Managment_st, LINSM_VAR_NO_INIT) LinSM_Management_Tab[LINSM_NETWORK_TOTAL_NUMBER];

#define LINSM_STOP_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define LINSM_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
	/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinSM_UsedNonSharedVariable" */
CONST(uint8, LINSM_CONFIG_DATA) LinSM_ScheduleIdx_Info[LINSM_SCHEDLE_NUMBER] =
{
	0U,
	1U,
};

	/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinSM_UsedNonSharedVariable" */
CONST(LinSM_Channl_Config_st, LINSM_CONFIG_DATA) LinSM_Channl_Cfg_Tab[LINSM_NETWORK_TOTAL_NUMBER] = 
{
	{
		0U,
		10000U,
		FALSE,
		0U,
		2U,
		2U,
		LINSM_CHANNEL_MASTER
	},
};
#define LINSM_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


/*
********************************************************************************
*
*  File name: WdgM_Lcfg.c
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangCong/2019.04.12
* Change: New
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: Baowanglong/2020.03.27
* Change: Only version update to V3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: Baowanglong/2020.05.25
* Change: Modify the file according to the code specification.
* Cause: Optimization.
********************************************************************************
* Version: 3.2
* Author/Date: WuZB/2020.11.03
* Change: Modify code format.
* Cause: Optimization.
********************************************************************************
* Version: 3.3
* Author/Date : WuZB/2020.12.1
* Change: Modify WdgM_ExternalLogicalSupervisionType to WdgM_ExLogicalSupervisionType.
* Cause: Optimization.
********************************************************************************
* Version: 3.4
* Author/Date : WuZB/2020.12.10
* Change: Modify code format.
* Cause: Optimization.
********************************************************************************
* Version: 3.5
* Author/Date: LQiao/2022.7.28
* Change: Add MULICORE.
* Cause: Optimization.
********************************************************************************
* Version: 3.6
* Author/Date: ZhangZL/2024.3.15
* Change: Add WdgM_SupervisedEntityIdType.
* Cause: Optimization.
********************************************************************************
*/
/*
********************************************************************************
*    Include
********************************************************************************
*/
#include "WdgM_Lcfg.h"

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
#define WDGM_START_SEC_GLOBAL_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
static VAR(WdgM_SEVariableType, WDGM_VAR_NO_INIT) WdgM_SEVariable[WDGM_SE_ALL_NUM + WDGM_VALUE_ONE];


#define WDGM_STOP_SEC_GLOBAL_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define WDGM_START_SEC_GLOBAL_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
static VAR(WdgM_LocalStatusCnt, WDGM_VAR_INIT) LocalStatusCore0 = {
    0,
    0,
    0,
    0
};
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
static VAR(WdgM_LocalStatusCnt, WDGM_VAR_INIT) LocalStatusCore1 = {
    0,
    0,
    0,
    0
};
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
static VAR(WdgM_LocalStatusCnt, WDGM_VAR_INIT) LocalStatusCore2 = {
    0,
    0,
    0,
    0
};
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
static VAR(WdgM_LocalStatusCnt, WDGM_VAR_INIT) LocalStatusCore3 = {
    0,
    0,
    0,
    0
};
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
static VAR(WdgM_LocalStatusCnt, WDGM_VAR_INIT) LocalStatusCore4 = {
    0,
    0,
    0,
    0
};
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
static VAR(WdgM_LocalStatusCnt, WDGM_VAR_INIT) LocalStatusCore5 = {
    0,
    0,
    0,
    0
};

#define WDGM_STOP_SEC_GLOBAL_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
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
#define WDGM_START_SEC_GLOBAL_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
P2VAR(WdgM_LocalStatusCnt, AUTOMATIC, WDGM_APPL_DATA) WdgM_LocalStatusCnt_Array[WDGM_CORE_NUM]=
{
    &LocalStatusCore0,
    &LocalStatusCore1,
    &LocalStatusCore2,
    &LocalStatusCore3,
    &LocalStatusCore4,
    &LocalStatusCore5
};


#define WDGM_STOP_SEC_GLOBAL_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define WDGM_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* polyspace +4 DEFECT:HARD_CODED_BUFFER_SIZE [Justified:Unset] "NSCA_Polyspace_WdgM_HARD_CODED_BUFFER_SIZE" */
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_AliveSupervisionType, WDGM_CONFIG_DATA) WdgM_AliveSupervision_Name0[30] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{
		{
			0,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			1,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			2,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			3,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			4,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			11,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			12,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			13,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			14,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			15,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			22,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			23,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			24,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			25,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			26,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			33,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			34,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			35,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			36,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			37,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			44,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			45,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			46,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			47,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			48,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			55,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			56,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			57,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			58,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	{
		{
			59,
			0
		},
		5,
		1,
		1,
		5,
		3,
	},
	
};

/* polyspace +4 DEFECT:HARD_CODED_BUFFER_SIZE [Justified:Unset] "NSCA_Polyspace_WdgM_HARD_CODED_BUFFER_SIZE" */
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_DeadLineSupervisionType, WDGM_CONFIG_DATA) WdgM_DeadLineSupv_Name0[30] = 
{
	{
		{
			5,
			0
		},
		{
			5,
			1
		},
		0,
		8,
	},
	{
		{
			6,
			0
		},
		{
			6,
			1
		},
		0,
		8,
	},
	{
		{
			7,
			0
		},
		{
			7,
			1
		},
		0,
		8,
	},
	{
		{
			8,
			0
		},
		{
			8,
			1
		},
		0,
		8,
	},
	{
		{
			9,
			0
		},
		{
			9,
			1
		},
		0,
		8,
	},
	{
		{
			16,
			0
		},
		{
			16,
			1
		},
		0,
		8,
	},
	{
		{
			17,
			0
		},
		{
			17,
			1
		},
		0,
		8,
	},
	{
		{
			18,
			0
		},
		{
			18,
			1
		},
		0,
		8,
	},
	{
		{
			19,
			0
		},
		{
			19,
			1
		},
		0,
		8,
	},
	{
		{
			20,
			0
		},
		{
			20,
			1
		},
		0,
		8,
	},
	{
		{
			27,
			0
		},
		{
			27,
			1
		},
		0,
		8,
	},
	{
		{
			28,
			0
		},
		{
			28,
			1
		},
		0,
		8,
	},
	{
		{
			29,
			0
		},
		{
			29,
			1
		},
		0,
		8,
	},
	{
		{
			30,
			0
		},
		{
			30,
			1
		},
		0,
		8,
	},
	{
		{
			31,
			0
		},
		{
			31,
			1
		},
		0,
		8,
	},
	{
		{
			38,
			0
		},
		{
			38,
			1
		},
		0,
		8,
	},
	{
		{
			39,
			0
		},
		{
			39,
			1
		},
		0,
		8,
	},
	{
		{
			40,
			0
		},
		{
			40,
			1
		},
		0,
		8,
	},
	{
		{
			41,
			0
		},
		{
			41,
			1
		},
		0,
		8,
	},
	{
		{
			42,
			0
		},
		{
			42,
			1
		},
		0,
		8,
	},
	{
		{
			49,
			0
		},
		{
			49,
			1
		},
		0,
		8,
	},
	{
		{
			50,
			0
		},
		{
			50,
			1
		},
		0,
		8,
	},
	{
		{
			51,
			0
		},
		{
			51,
			1
		},
		0,
		8,
	},
	{
		{
			52,
			0
		},
		{
			52,
			1
		},
		0,
		8,
	},
	{
		{
			53,
			0
		},
		{
			53,
			1
		},
		0,
		8,
	},
	{
		{
			60,
			0
		},
		{
			60,
			1
		},
		0,
		8,
	},
	{
		{
			61,
			0
		},
		{
			61,
			1
		},
		0,
		8,
	},
	{
		{
			62,
			0
		},
		{
			62,
			1
		},
		0,
		8,
	},
	{
		{
			63,
			0
		},
		{
			63,
			1
		},
		0,
		8,
	},
	{
		{
			64,
			0
		},
		{
			64,
			1
		},
		0,
		8,
	},
	
};




/* Polyspace-begin MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_WdgM_Rule11.8" */
/* Polyspace-end MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_WdgM_Rule11.8" */

	
/* polyspace +5 DEFECT:HARD_CODED_BUFFER_SIZE [Justified:Unset] "NSCA_Polyspace_WdgM_HARD_CODED_BUFFER_SIZE" */
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SupervisedEntityIdType, WDGM_CONFIG_DATA) WdgM_Mode_LocalStatusSupervisedEntity_Name0[66] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65
};

	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_TriggerType, WDGM_CONFIG_DATA) WdgM_Trigger_Name0[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{
		0U,
		500,
		WDGIF_FAST_MODE,
		0,
		65535,
		65535,
		1,
		NULL_PTR
	},
	
};


/* Polyspace-begin MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_WdgM_Rule11.8" */
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_ModeStructType, WDGM_CONFIG_DATA) WdgM_Mode_Name0 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	3,
	0,
	10,
	30,
	(WdgM_AliveSupervisionType*)&WdgM_AliveSupervision_Name0[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	30,
	(WdgM_DeadLineSupervisionType*)&WdgM_DeadLineSupv_Name0[0],
	0,
	NULL_PTR,
	66,
	(WdgM_SupervisedEntityIdType*)&WdgM_Mode_LocalStatusSupervisedEntity_Name0[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_TriggerType*)&WdgM_Trigger_Name0[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	NULL_PTR,
	20,
	0,
	NULL_PTR,
};
/* Polyspace-end MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_WdgM_Rule11.8" */

	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name5[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name6[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name7[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name8[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name9[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name10[5] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	{1,2},
	{2,3},
	{3,4},
	{4,5},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name16[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name17[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name18[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name19[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name20[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name21[5] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	{1,2},
	{2,3},
	{3,4},
	{4,5},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name27[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name28[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name29[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name30[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name31[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name32[5] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	{1,2},
	{2,3},
	{3,4},
	{4,5},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name38[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name39[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name40[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name41[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name42[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name43[5] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	{1,2},
	{2,3},
	{3,4},
	{4,5},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name49[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name50[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name51[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name52[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name53[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name54[5] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	{1,2},
	{2,3},
	{3,4},
	{4,5},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name60[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name61[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name62[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name63[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name64[1] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	
};
	
/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_InternalTransitionType, WDGM_CONFIG_DATA) WdgM_LogicalSupv_Name65[5] =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	{0,1},
	{1,2},
	{2,3},
	{3,4},
	{4,5},
	
};

/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE5[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE6[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE7[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE8[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE9[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE10[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	5
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE16[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE17[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE18[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE19[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE20[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE21[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	5
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE27[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE28[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE29[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE30[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE31[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE32[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	5
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE38[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE39[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE40[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE41[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE42[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE43[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	5
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE49[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE50[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE51[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE52[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE53[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE54[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	5
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE60[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE61[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE62[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE63[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE64[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	1
};
/* polyspace +4 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +3 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_CheckpointIdType, WDGM_CONFIG_DATA) InternalCheckpointFinalArray_SE65[1] =  /* PRQA S 0777,0779,3408 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.1,NSCA_QAC_WdgM_Rule8.4 */
{
	5
};

/* Polyspace-begin MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_WdgM_Rule11.8" */
/* Polyspace-begin MISRA-C3:10.5 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name0_Core0 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	0,
	(CounterType)SYSTEMTIMER_CORE0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[0],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name1_Core0 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	1,
	(CounterType)SYSTEMTIMER_CORE0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[1],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name2_Core0 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	2,
	(CounterType)SYSTEMTIMER_CORE0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[2],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name3_Core0 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	3,
	(CounterType)SYSTEMTIMER_CORE0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[3],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name4_Core0 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	4,
	(CounterType)SYSTEMTIMER_CORE0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[4],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name5_Core0 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	5,
	(CounterType)SYSTEMTIMER_CORE0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE5[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name5[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[5],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name6_Core0 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	6,
	(CounterType)SYSTEMTIMER_CORE0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE6[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name6[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[6],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name7_Core0 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	7,
	(CounterType)SYSTEMTIMER_CORE0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE7[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name7[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[7],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name8_Core0 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	8,
	(CounterType)SYSTEMTIMER_CORE0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE8[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name8[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[8],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name9_Core0 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	9,
	(CounterType)SYSTEMTIMER_CORE0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE9[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name9[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[9],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name10_Core0 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	10,
	(CounterType)SYSTEMTIMER_CORE0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	6,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE10[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	5,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name10[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[10],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name11_Core1 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	11,
	(CounterType)SYSTEMTIMER_CORE1,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[11],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name12_Core1 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	12,
	(CounterType)SYSTEMTIMER_CORE1,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[12],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name13_Core1 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	13,
	(CounterType)SYSTEMTIMER_CORE1,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[13],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name14_Core1 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	14,
	(CounterType)SYSTEMTIMER_CORE1,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[14],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name15_Core1 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	15,
	(CounterType)SYSTEMTIMER_CORE1,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[15],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name16_Core1 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	16,
	(CounterType)SYSTEMTIMER_CORE1,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE16[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name16[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[16],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name17_Core1 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	17,
	(CounterType)SYSTEMTIMER_CORE1,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE17[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name17[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[17],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name18_Core1 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	18,
	(CounterType)SYSTEMTIMER_CORE1,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE18[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name18[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[18],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name19_Core1 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	19,
	(CounterType)SYSTEMTIMER_CORE1,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE19[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name19[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[19],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name20_Core1 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	20,
	(CounterType)SYSTEMTIMER_CORE1,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE20[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name20[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[20],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name21_Core1 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	21,
	(CounterType)SYSTEMTIMER_CORE1,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	6,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE21[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	5,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name21[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[21],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name22_Core2 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	22,
	(CounterType)SYSTEMTIMER_CORE2,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[22],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name23_Core2 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	23,
	(CounterType)SYSTEMTIMER_CORE2,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[23],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name24_Core2 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	24,
	(CounterType)SYSTEMTIMER_CORE2,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[24],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name25_Core2 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	25,
	(CounterType)SYSTEMTIMER_CORE2,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[25],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name26_Core2 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	26,
	(CounterType)SYSTEMTIMER_CORE2,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[26],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name27_Core2 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	27,
	(CounterType)SYSTEMTIMER_CORE2,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE27[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name27[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[27],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name28_Core2 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	28,
	(CounterType)SYSTEMTIMER_CORE2,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE28[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name28[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[28],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name29_Core2 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	29,
	(CounterType)SYSTEMTIMER_CORE2,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE29[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name29[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[29],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name30_Core2 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	30,
	(CounterType)SYSTEMTIMER_CORE2,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE30[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name30[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[30],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name31_Core2 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	31,
	(CounterType)SYSTEMTIMER_CORE2,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE31[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name31[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[31],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name32_Core2 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	32,
	(CounterType)SYSTEMTIMER_CORE2,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	6,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE32[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	5,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name32[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[32],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name33_Core3 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	33,
	(CounterType)SYSTEMTIMER_CORE3,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[33],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name34_Core3 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	34,
	(CounterType)SYSTEMTIMER_CORE3,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[34],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name35_Core3 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	35,
	(CounterType)SYSTEMTIMER_CORE3,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[35],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name36_Core3 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	36,
	(CounterType)SYSTEMTIMER_CORE3,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[36],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name37_Core3 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	37,
	(CounterType)SYSTEMTIMER_CORE3,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[37],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name38_Core3 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	38,
	(CounterType)SYSTEMTIMER_CORE3,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE38[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name38[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[38],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name39_Core3 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	39,
	(CounterType)SYSTEMTIMER_CORE3,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE39[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name39[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[39],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name40_Core3 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	40,
	(CounterType)SYSTEMTIMER_CORE3,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE40[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name40[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[40],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name41_Core3 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	41,
	(CounterType)SYSTEMTIMER_CORE3,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE41[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name41[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[41],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name42_Core3 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	42,
	(CounterType)SYSTEMTIMER_CORE3,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE42[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name42[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[42],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name43_Core3 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	43,
	(CounterType)SYSTEMTIMER_CORE3,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	6,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE43[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	5,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name43[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[43],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name44_Core4 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	44,
	(CounterType)SYSTEMTIMER_CORE4,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[44],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name45_Core4 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	45,
	(CounterType)SYSTEMTIMER_CORE4,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[45],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name46_Core4 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	46,
	(CounterType)SYSTEMTIMER_CORE4,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[46],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name47_Core4 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	47,
	(CounterType)SYSTEMTIMER_CORE4,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[47],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name48_Core4 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	48,
	(CounterType)SYSTEMTIMER_CORE4,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[48],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name49_Core4 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	49,
	(CounterType)SYSTEMTIMER_CORE4,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE49[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name49[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[49],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name50_Core4 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	50,
	(CounterType)SYSTEMTIMER_CORE4,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE50[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name50[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[50],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name51_Core4 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	51,
	(CounterType)SYSTEMTIMER_CORE4,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE51[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name51[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[51],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name52_Core4 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	52,
	(CounterType)SYSTEMTIMER_CORE4,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE52[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name52[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[52],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name53_Core4 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	53,
	(CounterType)SYSTEMTIMER_CORE4,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE53[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name53[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[53],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name54_Core4 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	54,
	(CounterType)SYSTEMTIMER_CORE4,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	6,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE54[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	5,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name54[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[54],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name55_Core5 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	55,
	(CounterType)SYSTEMTIMER_CORE5,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[55],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name56_Core5 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	56,
	(CounterType)SYSTEMTIMER_CORE5,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[56],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name57_Core5 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	57,
	(CounterType)SYSTEMTIMER_CORE5,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[57],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name58_Core5 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	58,
	(CounterType)SYSTEMTIMER_CORE5,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[58],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name59_Core5 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	59,
	(CounterType)SYSTEMTIMER_CORE5,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	1,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	0,
	NULL_PTR,
	&WdgM_SEVariable[59],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name60_Core5 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	60,
	(CounterType)SYSTEMTIMER_CORE5,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE60[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name60[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[60],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name61_Core5 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	61,
	(CounterType)SYSTEMTIMER_CORE5,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE61[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name61[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[61],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name62_Core5 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	62,
	(CounterType)SYSTEMTIMER_CORE5,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE62[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name62[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[62],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name63_Core5 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	63,
	(CounterType)SYSTEMTIMER_CORE5,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE63[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name63[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[63],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name64_Core5 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	64,
	(CounterType)SYSTEMTIMER_CORE5,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	2,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE64[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name64[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[64],
	NULL_PTR,
};
	/* polyspace +3 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
/* Polyspace +1 MISRA-C3:8.4 [JUstified:Unset] "NSCA_Polyspace_WdgM_Rule8.4" */
CONST(WdgM_SEGType, WDGM_CONFIG_DATA) WdgM_SEG_Name65_Core5 =  /* PRQA S 3408 */ /* NSCA_QAC_WdgM_Rule8.4 */
{
	65,
	(CounterType)SYSTEMTIMER_CORE5,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	FALSE,
	(ApplicationType)0,  /* PRQA S 4332 */ /* NSCA_QAC_WdgM_Rule10.5 */
	6,
	0,  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	1,
	(WdgM_CheckpointIdType*)&InternalCheckpointFinalArray_SE65[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	5,
	(WdgM_InternalTransitionType*)&WdgM_LogicalSupv_Name65[0],  /* PRQA S 0311 */ /* NSCA_QAC_WdgM_Rule11.8 */
	&WdgM_SEVariable[65],
	NULL_PTR,
};
/* Polyspace-end MISRA-C3:10.5 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
/* Polyspace-end MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_WdgM_Rule11.8" */

/* polyspace +2 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
CONSTP2CONST(WdgM_SEGType, WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_SEG_Core0_Ptr[CORE0_SE_NUM + WDGM_VALUE_ONE] =
{
    &WdgM_SEG_Name0_Core0,
    &WdgM_SEG_Name1_Core0,
    &WdgM_SEG_Name2_Core0,
    &WdgM_SEG_Name3_Core0,
    &WdgM_SEG_Name4_Core0,
    &WdgM_SEG_Name5_Core0,
    &WdgM_SEG_Name6_Core0,
    &WdgM_SEG_Name7_Core0,
    &WdgM_SEG_Name8_Core0,
    &WdgM_SEG_Name9_Core0,
    &WdgM_SEG_Name10_Core0,
    NULL_PTR
};
/* polyspace +2 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
CONSTP2CONST(WdgM_SEGType, WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_SEG_Core1_Ptr[CORE1_SE_NUM + WDGM_VALUE_ONE] =
{
    &WdgM_SEG_Name11_Core1,
    &WdgM_SEG_Name12_Core1,
    &WdgM_SEG_Name13_Core1,
    &WdgM_SEG_Name14_Core1,
    &WdgM_SEG_Name15_Core1,
    &WdgM_SEG_Name16_Core1,
    &WdgM_SEG_Name17_Core1,
    &WdgM_SEG_Name18_Core1,
    &WdgM_SEG_Name19_Core1,
    &WdgM_SEG_Name20_Core1,
    &WdgM_SEG_Name21_Core1,
    NULL_PTR
};
/* polyspace +2 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
CONSTP2CONST(WdgM_SEGType, WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_SEG_Core2_Ptr[CORE2_SE_NUM + WDGM_VALUE_ONE] =
{
    &WdgM_SEG_Name22_Core2,
    &WdgM_SEG_Name23_Core2,
    &WdgM_SEG_Name24_Core2,
    &WdgM_SEG_Name25_Core2,
    &WdgM_SEG_Name26_Core2,
    &WdgM_SEG_Name27_Core2,
    &WdgM_SEG_Name28_Core2,
    &WdgM_SEG_Name29_Core2,
    &WdgM_SEG_Name30_Core2,
    &WdgM_SEG_Name31_Core2,
    &WdgM_SEG_Name32_Core2,
    NULL_PTR
};
/* polyspace +2 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
CONSTP2CONST(WdgM_SEGType, WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_SEG_Core3_Ptr[CORE3_SE_NUM + WDGM_VALUE_ONE] =
{
    &WdgM_SEG_Name33_Core3,
    &WdgM_SEG_Name34_Core3,
    &WdgM_SEG_Name35_Core3,
    &WdgM_SEG_Name36_Core3,
    &WdgM_SEG_Name37_Core3,
    &WdgM_SEG_Name38_Core3,
    &WdgM_SEG_Name39_Core3,
    &WdgM_SEG_Name40_Core3,
    &WdgM_SEG_Name41_Core3,
    &WdgM_SEG_Name42_Core3,
    &WdgM_SEG_Name43_Core3,
    NULL_PTR
};
/* polyspace +2 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
CONSTP2CONST(WdgM_SEGType, WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_SEG_Core4_Ptr[CORE4_SE_NUM + WDGM_VALUE_ONE] =
{
    &WdgM_SEG_Name44_Core4,
    &WdgM_SEG_Name45_Core4,
    &WdgM_SEG_Name46_Core4,
    &WdgM_SEG_Name47_Core4,
    &WdgM_SEG_Name48_Core4,
    &WdgM_SEG_Name49_Core4,
    &WdgM_SEG_Name50_Core4,
    &WdgM_SEG_Name51_Core4,
    &WdgM_SEG_Name52_Core4,
    &WdgM_SEG_Name53_Core4,
    &WdgM_SEG_Name54_Core4,
    NULL_PTR
};
/* polyspace +2 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
CONSTP2CONST(WdgM_SEGType, WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_SEG_Core5_Ptr[CORE5_SE_NUM + WDGM_VALUE_ONE] =
{
    &WdgM_SEG_Name55_Core5,
    &WdgM_SEG_Name56_Core5,
    &WdgM_SEG_Name57_Core5,
    &WdgM_SEG_Name58_Core5,
    &WdgM_SEG_Name59_Core5,
    &WdgM_SEG_Name60_Core5,
    &WdgM_SEG_Name61_Core5,
    &WdgM_SEG_Name62_Core5,
    &WdgM_SEG_Name63_Core5,
    &WdgM_SEG_Name64_Core5,
    &WdgM_SEG_Name65_Core5,
    NULL_PTR
};

	/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
CONSTP2CONST(WdgM_ModeStructType, WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_Mode_Ptr[WDGM_MODE_ALL_NUM + WDGM_VALUE_ONE] =
{
	&WdgM_Mode_Name0,
	NULL_PTR
};
/* Polyspace +2 MISRA-C3:20.7 [Justified:Unset] "NSCA_Polyspace_WdgM_20.7" */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
CONSTP2CONST( CONSTP2CONST(WdgM_SEGType, WDGM_CONFIG_DATA, WDGM_APPL_CONST), WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_SEG_Core_Ptr_Array[WDGM_CORE_NUM + WDGM_VALUE_ONE]=
{
    &WdgM_SEG_Core0_Ptr[0],
    &WdgM_SEG_Core1_Ptr[0],
    &WdgM_SEG_Core2_Ptr[0],
    &WdgM_SEG_Core3_Ptr[0],
    &WdgM_SEG_Core4_Ptr[0],
    &WdgM_SEG_Core5_Ptr[0],
    NULL_PTR
};
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_UsedNonSharedVariable" */
CONST(WdgM_SENumType, WDGM_CONFIG_DATA) SENumInCore[WDGM_CORE_NUM]=
{
    CORE0_SE_NUM,
    CORE1_SE_NUM,
    CORE2_SE_NUM,
    CORE3_SE_NUM,
    CORE4_SE_NUM,
    CORE5_SE_NUM
};

/* This Must be generated. END */
#define WDGM_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define WDGM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */



#define WDGM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


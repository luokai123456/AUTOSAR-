/*
********************************************************************************
*
*  File name: Csm_Cfg.c
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
*  Version: 1.0
*  Author/Date : JiaF/2020.03.03
*  Change: New created
*  Cause: New
********************************************************************************
*  Version: 3.0
*  Author/Date : JiaF/2020.07.02
*  Change: Nothing
*  Cause: Update
********************************************************************************
*  Version: 3.01
*  Author/Date: MengY/2024.04.02
*  Change: Remove the unused variables.
*  Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Csm.h"
#include "Rte_Cbk.h"
#include "Rte_Csm.h"
#include "Dcm_Callback.h"
#include "SecOC.h"

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
#define CSM_START_SEC_VAR_NO_INIT
#include "Csm_MemMap.h"
/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
static VAR(Csm_QueueType, CSM_VAR_NO_INIT) csmQueuedList0[10];

#define CSM_STOP_SEC_VAR_NO_INIT
#include "Csm_MemMap.h"

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
#define CSM_START_SEC_CONFIG_DATA
#include "Csm_MemMap.h"

/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
static CONST(Crypto_JobInfoType, CSM_CONFIG_DATA) cryptoJobInfo[CSM_NUMBER_OF_JOBS] =
{
	{
		0,
		1U
	},
};

/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
static CONST(Crypto_PrimitiveInfoType, CSM_CONFIG_DATA) cryptoPrimitiveInfo[CSM_NUMBER_OF_PRIMITIVES] =
{
	{
		128,
		CRYPTO_DECRYPT,
		{
			CRYPTO_ALGOFAM_AES,
			CRYPTO_ALGOFAM_NOT_SET,
			0,
			CRYPTO_ALGOMODE_ECB,
		}
	},
};

/* Polyspace-begin MISRA-C3:7.2 [Justified:Unset] " NSCA_Polyspace_Csm_Dir7.2 " */
/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
static CONST(Crypto_JobPrimitiveInfoType, CSM_CONFIG_DATA) cryptoJobPrimitiveInfomation[CSM_NUMBER_OF_JOBS] =
{
	{
		0U,
		&cryptoPrimitiveInfo[0],
		0U,
		CRYPTO_PROCESSING_ASYNC,
		STD_OFF,
	},
};
/* Polyspace-end MISRA-C3:7.2 [Justified:Unset] " NSCA_Polyspace_Csm_Dir7.2 " */

#define CSM_STOP_SEC_CONFIG_DATA
#include "Csm_MemMap.h"

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
#define CSM_START_SEC_VAR_NO_INIT
#include "Csm_MemMap.h"

/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
VAR(Crypto_JobRedirectionInfoType, CSM_VAR_NO_INIT) cryptoJobRedirectionInfo[CSM_NUMBER_OF_INOUTREDIRECTIONS_CONFIG];
#define CSM_STOP_SEC_VAR_NO_INIT
#include "Csm_MemMap.h"


#define CSM_START_SEC_VAR_INIT
#include "Csm_MemMap.h"

/* Polyspace +2 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
/* Polyspace +1 MISRA-C3:8.4 [Justified:Unset] " NSCA_Polyspace_Csm_Dir8.4 " */
VAR(Crypto_JobType, CSM_VAR_INIT) csmJob[CSM_NUMBER_OF_JOBS] =  /* PRQA S 3408 */ /* NSCA_QAC_KeyM_Rule_8.4 */
{
	{
		0U,
		CRYPTO_JOBSTATE_IDLE,
		{
			NULL_PTR,
			CSM_ZERO,
			NULL_PTR,
			CSM_ZERO,
			NULL_PTR,
			CSM_ZERO,
			NULL_PTR,
			NULL_PTR,
			NULL_PTR,
			NULL_PTR,
			CSM_ZERO,
			NULL_PTR,
			NULL_PTR,
			CRYPTO_OPERATIONMODE_IDLE,
			CSM_INVALID_IDX_U32,
			CSM_INVALID_IDX_U32 
		},
	&cryptoJobPrimitiveInfomation[0],
	&cryptoJobInfo[0],
	CSM_INVALID_IDX_U32,
	CSM_INVALID_IDX_U32,
	NULL_PTR,
	},
};
/* Polyspace +2 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
/* Polyspace +1 MISRA-C3:8.4 [Justified:Unset] " NSCA_Polyspace_Csm_Dir8.4 " */
VAR(Csm_JobQueueType, CSM_VAR_INIT) csmJobList[CSM_NUMBER_OF_QUEUES] =  /* PRQA S 3408 */ /* NSCA_QAC_KeyM_Rule_8.4 */
{
	{
		0,
		csmQueuedList0,
		10,
		0,
		0U
	},
};
/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
P2VAR(Crypto_JobType, CSM_CONFIG_DATA, CSM_VAR_INIT) cryptoJob[CSM_NUMBER_OF_JOBS] =
{
	&csmJob[0],
};
/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
P2VAR(Csm_JobQueueType, CSM_CONFIG_DATA, CSM_VAR_INIT) csmJobQueue[CSM_NUMBER_OF_QUEUES] =
{
	&csmJobList[0],
};


#define CSM_STOP_SEC_VAR_INIT
#include "Csm_MemMap.h"

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define CSM_START_SEC_CONFIG_DATA
#include "Csm_MemMap.h"
/* Polyspace-begin VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
CONST(Csm_KeyConfigType, CSM_CONFIG_DATA) csmKey[CSM_NUMBER_OF_KEYS] =
{
	{0,    FALSE,    0},
};
/* Polyspace-end VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */

/* Polyspace +2 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
/* Polyspace +1 MISRA-C3:8.4 [Justified:Unset] " NSCA_Polyspace_Csm_Dir8.4 " */
CONST(Csm_QueueConfigType, CSM_CONFIG_DATA) csmQueue[CSM_NUMBER_OF_QUEUES] =  /* PRQA S 3408 */ /* NSCA_QAC_KeyM_Rule_8.4 */
{
	{10,    0},
};
/* Polyspace-begin MISRA-C3:9.3 [Justified:Unset] " NSCA_Polyspace_Csm_Dir9.3 " */
/* Polyspace +2 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
/* Polyspace +1 MISRA-C3:8.4 [Justified:Unset] " NSCA_Polyspace_Csm_Dir8.4 " */
CONST(Csm_CallbackConfigType, CSM_CONFIG_DATA) csmCallback[CSM_NUMBER_OF_CALLBACKS] =  /* PRQA S 3408 */ /* NSCA_QAC_KeyM_Rule_8.4 */
{
	{0,    NULL_PTR},
};
/* Polyspace-end MISRA-C3:9.3 [Justified:Unset] " NSCA_Polyspace_Csm_Dir9.3 " */

/* Polyspace-begin MISRA-C3:9.3 [Justified:Unset] " NSCA_Polyspace_Csm_Dir9.3 " */
/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
CONST(Crypto_JobRedirectionInfoType, CSM_CONFIG_DATA) cryptoInOutRedirectionConfig[CSM_NUMBER_OF_INOUTREDIRECTIONS] =
{
	{
		CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT | 
		CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT | 
		CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT | 
		CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT | 
		CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT,
		CSM_INVALID_IDX_U32,
		0,
		CSM_INVALID_IDX_U32,
		0,
		CSM_INVALID_IDX_U32,
		0,
		CSM_INVALID_IDX_U32,
		0,
		CSM_INVALID_IDX_U32,
		0,
	},
};
/* Polyspace-end MISRA-C3:9.3 [Justified:Unset] " NSCA_Polyspace_Csm_Dir9.3 " */

/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
CONST(Csm_JobConfigType, CSM_CONFIG_DATA) csmJobConfig[CSM_NUMBER_OF_JOBS] =
{
	{
		&cryptoJobInfo[0],
		CRYPTO_USE_PORT_OPTIMIZED,
		CSM_INVALID_IDX_U32,
		NULL_PTR,
		FALSE,
		0,
		0,
		CRYPTO_PROCESSING_ASYNC,
		CSM_U32_NO_CFG
	},
};

/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
CONST(Csm_CallbackFuncType, CSM_CONFIG_DATA) csmJobCbkService[CSM_NUMBER_OF_JOBS] =
{
	Csm_CallBack_CallbackNotification,
};

#define CSM_STOP_SEC_CONFIG_DATA
#include "Csm_MemMap.h"


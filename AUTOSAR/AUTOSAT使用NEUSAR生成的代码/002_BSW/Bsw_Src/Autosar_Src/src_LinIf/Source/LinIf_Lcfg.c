/*
********************************************************************************
*
*  File name: LinIf_Lcfg.c
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
*  Version: 3.0
*  Author/Date : WangJP/2021.8.14
*  Change: New created
*  Cause: New
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "LinIf_Cfg.h"
#include "LinIf_Lcfg.h"
#include "PduR_LinIf.h"

#include "LinSM_Cbk.h"

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
#define LINIF_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UnusedVariable" */
VAR(uint8, LINIF_VAR_INIT) LinIf_SporTransmitFlags[LINIF_SPORADIC_FRM_NUMBER] ={0};

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
	
VAR(uint32, LINIF_VAR_INIT) LinIf_Channel_WakeupSouceInfo[LINIF_CHANNEL_NUMTOTAL] =
{
	0U,
};
#endif
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UsedNonSharedVariable" */
VAR(LinIf_ResponseErrorSignalChangedFuncType , LINIF_VAR_INIT) LinIfResponseErrorSignalChangedCallout = NULL_PTR;
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UsedNonSharedVariable" */
static VAR(uint8, LINIF_VAR_INIT) LinIf_FrameIdDataChannel_VE21_N72_PMS_LIN_LDF_T34TDK[LINIF_FRAME_NUM_CHANNEL_VE21_N72_PMS_LIN_LDF_T34TDK] = /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
{
    36U,
    37U,
    38U,
    56U,
    57U
};

	


/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UsedNonSharedVariable" */
P2CONST(LinIf_SlaveChannel_Nc_ConfigType, LINIF_VAR_INIT, LINIF_CONFIG_DATA) LinIf_SlaveChannel_Nc_ConfigData[LINIF_CHANNEL_NUMTOTAL] = 
{
	NULL_PTR
};
#define LINIF_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


#define LINIF_START_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UsedNonSharedVariable" */ 
VAR(LinIf_ChannelDataType, LINIF_VAR_NO_INIT) LinIf_ChannelData[LINIF_CHANNEL_NUMTOTAL];

#define LINIF_STOP_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define LINIF_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UsedNonSharedVariable" */
CONST(LinIf_Channel_Config_st, LINIF_CONFIG_DATA) LinIf_Channl_Cfg_Tab[LINIF_CHANNEL_NUMTOTAL] =
{
	{
		5U,
		LINIF_NOTREF_TRCV,
		0U,
		5U,
		0U,
		2U,
		2U,
		0U,
		0U,
		0U,
		0U,
		10U,
		0U,
		0U,
		0U,
		FALSE,
		LinSM_GotoSleepConfirmation,
		LinSM_ScheduleRequestConfirmation,
		LinSM_WakeupConfirmation,
		0U,
		0U,
		LinIf_FrameIdDataChannel_VE21_N72_PMS_LIN_LDF_T34TDK,
		LINIF_CHANNEL_MASTER,
		NULL_PTR,
		4000U/LINIF_TIMEBASE_CHANNEL0,
		LINIF_INVALID_COMSIGNALID,
		LINIF_INVALID_FRAMEID,
		0U
	}
};

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UsedNonSharedVariable" */
CONST(LINIf_Frame_Table_st, LINIF_CONFIG_DATA) LINIf_Frame_Cfg_Tab[LINIF_FRAME_NUMBER] =
{
	{
		0U,
		LIN_ENHANCED_CS,
		LINIF_MSR_MASTER_RESPONSE,
		LINIF_FRMTYPE_UNCONDITIONALFRAME,
		8U,
		36U,
		0U,
		FALSE,
		PduR_LinIfTxConfirmation,
		PduR_LinIfTriggerTransmit,
		NULL_PTR,
		0U,
	},
	{
		0U,
		LIN_ENHANCED_CS,
		LINIF_MSR_SLAVE_RESPONSE,
		LINIF_FRMTYPE_UNCONDITIONALFRAME,
		8U,
		37U,
		1U,
		FALSE,
		NULL_PTR,
		NULL_PTR,
		PduR_LinIfRxIndication,
		0U,
	},
	{
		0U,
		LIN_ENHANCED_CS,
		LINIF_MSR_SLAVE_RESPONSE,
		LINIF_FRMTYPE_UNCONDITIONALFRAME,
		8U,
		38U,
		2U,
		FALSE,
		NULL_PTR,
		NULL_PTR,
		PduR_LinIfRxIndication,
		0U,
	},
	{
		0U,
		LIN_ENHANCED_CS,
		LINIF_MSR_MASTER_RESPONSE,
		LINIF_FRMTYPE_UNCONDITIONALFRAME,
		8U,
		56U,
		3U,
		FALSE,
		PduR_LinIfTxConfirmation,
		PduR_LinIfTriggerTransmit,
		NULL_PTR,
		0U,
	},
	{
		0U,
		LIN_ENHANCED_CS,
		LINIF_MSR_SLAVE_RESPONSE,
		LINIF_FRMTYPE_UNCONDITIONALFRAME,
		8U,
		57U,
		4U,
		FALSE,
		NULL_PTR,
		NULL_PTR,
		PduR_LinIfRxIndication,
		0U,
	},
};

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UsedNonSharedVariable" */
CONST(LinIf_EntryType, LINIF_CONFIG_DATA) LinIf_Entry[LINIF_ENTRY_NUMBER] =
{
	{0U,    (10U/LINIF_TIMEBASE_CHANNEL0)},
	{1U,    (10U/LINIF_TIMEBASE_CHANNEL0)},
	{2U,    (10U/LINIF_TIMEBASE_CHANNEL0)},
	{3U,    (10U/LINIF_TIMEBASE_CHANNEL0)},
	{4U,    (60U/LINIF_TIMEBASE_CHANNEL0)},
};

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UsedNonSharedVariable" */
CONST(LinIf_ScheduleTableListType, LINIF_CONFIG_DATA) LinIf_ScheduleTableList[LINIF_SCHEDULETABLE_NUMBER] =
{
	{
		LINIF_NO_ENTRYSTARTIDXOFSCHEDULETABLELIST,
		LINIF_NO_ENTRYENDIDXOFSCHEDULETABLELIST,
		0U,
		0U,
		LINIF_RUNMODE_RUNCONTINUOUS
	},
	{
		0U,
		4U,
		5U,
		0U,
		LINIF_RUNMODE_RUNCONTINUOUS
	}
};

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UnusedVariable" */
CONST(LinIf_ChannelIndTableType, LINIF_CONFIG_DATA) LinIf_ChannelIndTable[LINIF_CHANNEL_NUMTOTAL] =
{
	{
		0U,
		0U
	}
};

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UsedNonSharedVariable" */
CONST(uint16, LINIF_CONFIG_DATA) LinIf_ScheduleTableListInd[LINIF_SCHEDULETABLE_NUMBER] =
{
	0U,
	1U
};

/* LinIf_SporUncFrameByHandleList. */

/* LinIf_SporUncFrameByPriorityList. */






/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UnusedVariable" */
CONST(uint8, LINIF_CONFIG_DATA) LinIf_FixedFrameSduList[LINIF_FIEXDFRAME_NUMBER] =
{
	0U
};

#if ( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON )
CONST(LinIf_LinMultipeDrvInfoType, LINIF_CONFIG_DATA) LinIf_LinMultipeDrvInfo[LINIF_CONTROLLER_NUM] =
{
	{
		Lin_SendFrame,
		Lin_GetStatus,
		Lin_GoToSleep,
		Lin_GoToSleepInternal,
		Lin_Wakeup,
		Lin_WakeupInternal,
		Lin_CheckWakeup
	}
};
#endif  /* LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UnusedVariable" */
CONST(uint8, LINIF_CONFIG_DATA) LinIf_FrameLengthDelayList[8] =
{
	1U,
	1U,
	2U,
	2U,
	2U,
	2U,
	2U,
	2U
};



#define LINIF_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


#define LINIF_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* polyspace +1 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
FUNC(void, LINIF_CODE) LinIf_MainFunction_VE21_N72_PMS_LIN_ldf_T34TDk(void)
{
	(void)LinIf_MainFunction((uint8)0);
}




#define LINIF_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


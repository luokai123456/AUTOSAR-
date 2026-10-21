/*
********************************************************************************
*
* File name: J1939Tp_Lcfg.c
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: lizhiheng/2020.03.30
* Change: Clear the module configurations.
* Cause: Release version V3.0
********************************************************************************
* Version: 3.1
* Author/Date: YanCL/2024/6/25
* Change: Update copyright information.
* Cause: Update
********************************************************************************
*/
/*
*******************************************************************************
*    Include
*******************************************************************************
*/
#include "J1939Tp_Cfg.h"
#include "CanIf.h"
#include "PduR_J1939Tp.h"
#include "J1939Tp_Int.h"

/*
*******************************************************************************
*    Local Macros
*******************************************************************************
*/
/*
*******************************************************************************
*    Local Types
*******************************************************************************
*/
/*
*******************************************************************************
*    Local Variables
*******************************************************************************
*/
/*
*******************************************************************************
*    Local Constants
*******************************************************************************
*/
/*
*******************************************************************************
*    Local Functions
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Variable
*******************************************************************************
*/
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define J1939TP_START_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* Polyspace-begin VARIABLE:* [Justified:Unset] "NSCA_Polyspace_J1939Tp_GlobalVariables" */

VAR(J1939Tp_RxPduStateType, J1939TP_VAR_INIT) J1939Tp_RxPduState[J1939TP_RXPDU_NUM + 1U] = {0U};
VAR(J1939Tp_RxSduStateType, J1939TP_VAR_INIT) J1939Tp_RxSduState[J1939TP_RXNSDU_NUMBER + 1U] = {0U};
VAR(J1939Tp_TxPduStateType, J1939TP_VAR_INIT) J1939Tp_TxPduState[J1939TP_TXPDU_NUM + 1U] = {0U};
VAR(J1939Tp_TxSduStateType, J1939TP_VAR_INIT) J1939Tp_TxSduState[J1939TP_TXNSDU_NUMBER + 1U ] = {0U};

/* Polyspace-end VARIABLE:* [Justified:Unset] "NSCA_Polyspace_J1939Tp_GlobalVariables" */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define J1939TP_STOP_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
*******************************************************************************
*    Global Constants
*******************************************************************************
*/
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define J1939TP_START_SEC_CONFIG_DATA
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* Polyspace-begin MISRA-C3:9.3 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule9.3" */
/* Polyspace-begin VARIABLE:* [Justified:Unset] "NSCA_Polyspace_J1939Tp_GlobalVariables" */

CONST(J1939Tp_RxChannelType, J1939TP_CONFIG_DATA) J1939Tp_RxChannel[J1939TP_RXCHANNEL_NUMBER + 1U] = {
	{
		0U
	}
};

CONST(J1939Tp_RxSdu_Type, J1939TP_CONFIG_DATA) J1939Tp_RxSduInfo[J1939TP_RXNSDU_NUMBER + 1U] =
{
	{
		0U
	}
};

CONST(J1939Tp_RxPduType, J1939TP_CONFIG_DATA) J1939Tp_RxPdu[J1939TP_RXPDU_NUM + 1U] =
{
	{
		9U,
		J1939TP_PROTOCOL_CMDT,
		J1939TP_TPCM_PDUTYPEOFTXPDU
	},
	{
		0U
	}
};

CONST(J1939Tp_TxChannelType, J1939TP_CONFIG_DATA) J1939Tp_TxChannel[J1939TP_TXCHANNEL_NUMBER + 1U] =
{
	{
		FALSE,
		86U,
		FALSE,
		255U,
		J1939TP_PROTOCOL_CMDT,
		FALSE,
		244U,
		0x0U,
		0x0U,
		0x1U,
		0U,
		6U
	},
	{
		0U
	}
};

CONST(J1939Tp_TxSdu_Type, J1939TP_CONFIG_DATA) J1939Tp_TxSduInfo[J1939TP_TXNSDU_NUMBER + 1U] =
{
	{
		FALSE,
		0x1700,
		6U,
		0U,
		16U,
		4U,
		J1939TP_NO_CFG_DIRECT
	},
	{
		FALSE,
		0x1600,
		10U,
		0U,
		16U,
		4U,
		J1939TP_NO_CFG_DIRECT
	},
	{
		FALSE,
		0x1500,
		11U,
		0U,
		512U,
		4U,
		J1939TP_NO_CFG_DIRECT
	},
	{
		FALSE,
		0x1100,
		13U,
		0U,
		9U,
		4U,
		J1939TP_NO_CFG_DIRECT
	},
	{
		FALSE,
		0x600,
		16U,
		0U,
		13U,
		4U,
		J1939TP_NO_CFG_DIRECT
	},
	{
		FALSE,
		0x200,
		17U,
		0U,
		49U,
		4U,
		J1939TP_NO_CFG_DIRECT
	},
	{
		0U
	}
};

CONST(J1939Tp_TxPduType, J1939TP_CONFIG_DATA) J1939Tp_TxPdu[J1939TP_TXPDU_NUM + 1U] =
{
	{
		0x3U,
		J1939TP_TPCM_PDUTYPEOFTXPDU
	},
	{
		0x2U,
		J1939TP_TPDT_PDUTYPEOFTXPDU
	},
	{
		0U
	}
};

/* Polyspace-end VARIABLE:* [Justified:Unset] "NSCA_Polyspace_J1939Tp_GlobalVariables" */
/* Polyspace-end MISRA-C3:9.3 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule9.3" */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define J1939TP_STOP_SEC_CONFIG_DATA
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


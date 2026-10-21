/*
********************************************************************************
*
*  File name: LinTp_Lcfg.c
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
#include "LinIf.h"
#include "LinTp_Lcfg.h"

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
/* LinTp_Ctrl */
#define LINIF_START_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UsedNonSharedVariable" */
VAR(uLinTp_CtrlType, LINIF_VAR_NO_INIT) LinTp_Ctrl;

#define LINIF_STOP_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define LINIF_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UsedNonSharedVariable" */
P2CONST(LinTp_ChannelConfigType, LINIF_VAR_INIT, LINIF_CONFIG_DATA) LinTp_ChannelConfigData[LINTP_CHANNEL_NUMBER] = 
{
	&LinTp_ChannelConfigData_0
};


#define LINIF_STOP_SEC_VAR_INIT
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
CONST(uint8, LINIF_CONFIG_DATA) LinTp_LinIfToLinTpChannel[LINTP_CHANNEL_NUMBER] = 
{
	0U
};

/* LinTp_RxNSdu */
/*
  \var    LinTp_RxNSdu
  \brief  List of all LinTp RxNsdus sorted by their PduId
  \details
  Element            Description
  CtrlIdx            the index of the 1:1 relation pointing to LinTp_Ctrl
  Ncr                Ncr timeout in ticks
  UpperLayerPduId    RxNSdu external ID (SNV)
  NAD                NAD
*/
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UsedNonSharedVariable" */
CONST(LinTp_RxNSduType, LINIF_CONFIG_DATA) LinTp_RxNSdu[LINTP_MAXRXNSDU_CNT] = 
{
	{
		0U
	}
};

/* LinTp_TxNSdu */
/*
  \var    LinTp_TxNSdu
  \brief  List of all LinTp TxNsdus sorted by their PduId
  \details
  Element               Description
  CtrlIdx               the index of the 1:1 relation pointing to LinTp_Ctrl
  Nas                   Nas timeout in ticks
  Ncs                   Ncs timeout in ticks
  AssociatedRxNSduId
  UpperLayerPduId
  NAD                   NAD
*/
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UsedNonSharedVariable" */
CONST(LinTp_TxNSduType, LINIF_CONFIG_DATA) LinTp_TxNSdu[LINTP_MAXTXNSDU_CNT] = 
{
	{
		0U
	}
};
/* polyspace +2 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_LinIf_UsedNonSharedVariable" */
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
CONST(LinTp_ChannelConfigType, LINIF_CONFIG_DATA) LinTp_ChannelConfigData_0 = 
{
	FALSE,
	FALSE,
	50U/LINIF_TIMEBASE_CHANNEL0,
	50U/LINIF_TIMEBASE_CHANNEL0,
	20U
};


#define LINIF_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


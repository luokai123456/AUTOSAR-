/*
********************************************************************************
*                                                                              
*  File name:   CanXcp_Lcfg.c                                                  
*                                                                              
*  Copyright    Neusoft Reach Corporation. All rights reserved.                
*                                                                              
********************************************************************************
*                                                                              
* History                                                                      
*------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: Sunpengfei/2018.07.10
* Change: New
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: fangtao/2020.09.15
* Change: Add release software number.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: fangtao/2020.09.15
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: FangT/2021.03.03
* Change: Add checksum and Multi pudid functions.
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Include
********************************************************************************
*/
#include "CanXcp_Lcfg.h"
#include "Xcp_Swc.h"
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
#define XCP_START_SEC_VAR_NO_INIT
#include "Xcp_MemMap.h"

VAR(CanXcp_msgvar_st, XCP_VAR_NO_INIT) XCP_gstCAN_msgvar_rx;
VAR(CanXcp_msgvar_st, XCP_VAR_NO_INIT) XCP_gstCAN_msgvar_tx;

#define XCP_STOP_SEC_VAR_NO_INIT
#include "Xcp_MemMap.h"

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define XCP_START_SEC_CONFIG_DATA
#include "Xcp_MemMap.h"

CONST(CanXcp_XcpPdu_st, XCP_CONFIG_DATA) CanXcp_TxPduInfo[XCP_TXPDU_LIST] =
{
	
	{0, &XCP_gstCAN_msgvar_tx,XCP_gcaCAN_Msg_DTO},
};

CONST(CanXcp_XcpPdu_st, XCP_CONFIG_DATA) CanXcp_RxPduInfo[XCP_RXPDU_LIST] =
{
	
	{0, &XCP_gstCAN_msgvar_rx,XCP_gcaCAN_Msg_CRO},
};

#define XCP_STOP_SEC_CONFIG_DATA
#include "Xcp_MemMap.h"


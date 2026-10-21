/*
********************************************************************************
*
*  File name: LinTp_Lcfg.h
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : lizhiheng/2020.06.09
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date : Li.ZH/2021.8.16
* Change: Modification code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.1
* Author/Date: SunHQ/2022.12.9
* Change: Remove the redundant header files.
* Cause: Optimization.
********************************************************************************
*/
#ifndef LINTP_LCFG_H_
#define LINTP_LCFG_H_
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "LinTp_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/*
********************************************************************************
*    Local Types
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
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define LINIF_START_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
extern VAR(uLinTp_CtrlType, LINIF_VAR_NO_INIT) LinTp_Ctrl;
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
extern CONST(uint8, LINIF_CONFIG_DATA) LinTp_LinIfToLinTpChannel[LINTP_CHANNEL_NUMBER];
extern CONST(LinTp_RxNSduType, LINIF_CONFIG_DATA) LinTp_RxNSdu[LINTP_MAXRXNSDU_CNT];
extern CONST(LinTp_TxNSduType, LINIF_CONFIG_DATA) LinTp_TxNSdu[LINTP_MAXTXNSDU_CNT];
	
extern CONST(LinTp_ChannelConfigType, LINIF_CONFIG_DATA) LinTp_ChannelConfigData_0;
#define LINIF_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define LINIF_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
	
extern P2CONST(LinTp_ChannelConfigType, LINIF_VAR_INIT, LINIF_CONFIG_DATA) LinTp_ChannelConfigData[LINTP_CHANNEL_NUMBER];
#define LINIF_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif /* LINTP_LCFG_H_ */



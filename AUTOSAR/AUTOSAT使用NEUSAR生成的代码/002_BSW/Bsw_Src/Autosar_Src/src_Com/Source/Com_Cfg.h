/*
********************************************************************************
*
* File name: Com_Cfg.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJp/2021.08.14
* Change: New created
* Cause: New
********************************************************************************
*/
#ifndef COM_CFG_H_
#define COM_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComStack_Types.h"
#include "Com_Cbk.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* PolySpace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define COM_RXPDUCALLOUTINFO                           (STD_ON)
#define COM_GWSIGNAL_SUPPORT                           (STD_ON)
#define COM_RXUPDATEBITCFG_SUPPORT                     (STD_OFF)
#define COM_INVALIDACTION_SUPPORT                      (STD_OFF)
#define COM_RXREPLACESIGOFRXTIMEOUTINFO                (STD_ON)
#define COM_RXREPLACESIGGROUPOFRXTIMEOUTINFO           (STD_OFF)
#define COM_TXSIGGROUPINFO                             (STD_OFF)
#define COM_RXSIGGROUPINFO                             (STD_OFF)
#define COM_RXSIGFILTERINFO                            (STD_OFF)
#define COM_TXPDU_TPTYPE_SUPPORT                       (STD_ON)
#define COM_TXPDU_CBKNOTIFTY_SUPPORT                   (STD_OFF)
#define COM_TXPDU_TRIGGERCALLOUT_SUPPORT               (STD_OFF)
#define COM_RXPDU_SIGPRCS_IMMEDIATE_SUPPORT            (STD_OFF)
#define COM_TXUPDATEBITCFG_SUPPORT                     (STD_OFF)
#define COM_RXSIGINVLAIDACTION_SUPPORT                 (STD_OFF)
	
#define COM_DEV_ERROR_REPORT                           (STD_ON)
#define COM_VERSIONINFOAPI_SUPPORT                     (STD_OFF)
#define COM_RETRY_FAILED_TRANSMIT_REQUESTS             (STD_ON)
#define COM_METADATA_SUPPORT                           (STD_ON)
#define COM_SIGNALGROUPARRAY_SUPPORT                   (STD_ON)
#define COM_CANCELLATIONSUPPORT                        (STD_OFF)
#define COM_GWSIGNAL_NUM                               (4U)
#define COM_GWSIGNALDSCP_NUM                           (0U)
#define COM_MULTICORE_SUPPORT                          (STD_OFF)
#define COM_CORE_NUM                                   (1U)
#define COM_IPDUGROUPSNUM_SUPPORTED                    (14U)
#define COM_TXSIGNALFILTER_SUPPORTED                   (STD_OFF)
#define COM_TXSIGNALFILTER_NUM                         (0U)
#define COM_PERFOPTMZ_SUPPORT                          (STD_OFF)
#define COM_TXPDU_MDT_SUPPORT                          (STD_ON)
#define COM_TXSIGGRP_NOTIFICATION_SUPPORT              (STD_OFF)
#define COM_TXSIGGRP_ERRNOTIFICATION_SUPPORT           (STD_OFF)
#define COM_TXSIGGRP_TIMEOUT_NOTIFICATION_SUPPORT      (STD_OFF)
#define COM_TXSIG_NOTIFICATION_SUPPORT                 (STD_OFF)
#define COM_TXSIG_ERRNOTIFICATION_SUPPORT              (STD_OFF)
#define COM_TXSIG_TIMEOUTNOTIFICATION_SUPPORT          (STD_OFF)
#define COM_RXSIGGRP_ERRORNOTIFICATION_SUPPORT         (STD_OFF)
#define COM_RXSIGGRP_NOTIFICATION_SUPPORT              (STD_OFF)
#define COM_RXSIGGRP_INVALIDNOTIFICATION_SUPPORT       (STD_OFF)
#define COM_RXSIGGRP_TIMEOUTNOTIFICATION_SUPPORT       (STD_OFF)
#define COM_RXSIG_INVALIDNOTIFICATION_SUPPORT          (STD_OFF)
#define COM_RXSIG_ERRNOTIFICATION_SUPPORT              (STD_OFF)
#define COM_RXSIG_TIMEOUTNOTIFICATION_SUPPORT          (STD_ON)
#define COM_RXSIG_NOTIFICATION_SUPPORT                 (STD_ON)
#define Com_SigStartByte                               uint16
#define Com_SigByteLength                              uint16
#define COM_TXMETADATA_NUM                             (6U)
#define COM_TRIGRESETCYCTIMER_SUPPORT                  (STD_ON)
#define COM_RXWITHOUTSHADOWVALUE                       (STD_OFF)
#define COM_GWONLYTXMODETRUE                           (STD_ON)
#define COM_GWROUTETIMEOUTVALUE_SUPPORT                (STD_OFF)
#define COM_SIGGRP_RTEGROUP_OPERATE                    (STD_OFF)
/* PolySpace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/*
********************************************************************************
*    Global Types
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

#endif /* COM_CFG_H_ */


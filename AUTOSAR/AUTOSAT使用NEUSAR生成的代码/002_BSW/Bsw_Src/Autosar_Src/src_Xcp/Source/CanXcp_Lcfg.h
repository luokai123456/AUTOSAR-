/*
********************************************************************************
*
*  File name:   CanXcp_Lcfg.h
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
* Change: Add xxxxxxxxx
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
* Version: 3.4
* Author/Date : FangT/2021.10.28
* Change: Modify the code header file specification.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date : FangT/2021.10.29
* Change: Modify coding style.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date : FangT/2021.11.1
* Change: Modify coding style.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date : ShiRong/2022.09.16
* Change: Add XcpOnCANFD function.
* Cause: Update
*******************************************************************************
* Version: 3.8
* Author/Date : ShiRong/2022.10.12
* Change: Delete array declaration.
* Cause: Update
*******************************************************************************
*/
#ifndef CANXCP_LCFG_H_
#define CANXCP_LCFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanXcp_Types.h"
#include "CanXcp_Cfg.h"
//#include "Com_Cbk.h"
//#include "CanIf.h"
#include "Xcp_Lcfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* Variables for monitoring. */
typedef struct
{
   uint8   msgstate;     /* message state            */
   uint8   Checksum;     /* calculate checksum       */
   uint8   Alivenew;     /* calculate alive counter  */
   uint8   FiltChecksum; /* filter for checksum      */
   uint8   FiltAlive;    /* filter for alive counter */
   uint8   FiltDlc;      /* filter for dlc counter   */
} CanXcp_msgvarstate_st;

/* Variables for scheduling. */
typedef struct
{
   uint32  Id;                  /* message identifier         */
   uint16  mailboxNo;           /* can message mailbox number */
   uint16  ticycle;             /* time counter               */
   uint16  recdDLC;             /* received dlc               */
   uint8   msgmode;             /* message mode               */
   CanXcp_msgvarstate_st msgstate;  /* state variables            */
} CanXcp_msgvar_st;

typedef struct
{
    uint16        pduID;                /* pduID */
    CanXcp_msgvar_st *msgsig;           /* pointer to msg struct      */
    uint8        *data;                 /* pointer to dataraw         */
} CanXcp_XcpPdu_st;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
extern VAR(CanXcp_msgvar_st, XCP_VAR_NO_INIT) XCP_gstCAN_msgvar_rx;
extern VAR(CanXcp_msgvar_st, XCP_VAR_NO_INIT) XCP_gstCAN_msgvar_tx;

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
extern CONST(CanXcp_XcpPdu_st, XCP_CONFIG_DATA) CanXcp_TxPduInfo[XCP_TXPDU_LIST];
extern CONST(CanXcp_XcpPdu_st, XCP_CONFIG_DATA) CanXcp_RxPduInfo[XCP_RXPDU_LIST];

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* CANXCP_LCFG_H_ */

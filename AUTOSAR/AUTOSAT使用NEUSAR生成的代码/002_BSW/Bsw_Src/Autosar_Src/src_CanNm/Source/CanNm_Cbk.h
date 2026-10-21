/*
********************************************************************************
*
*  File name: CanNm_Cbk.h
*                                                                              
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History                                                               
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2018.12.13
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: jiafeng/2020.07.02
* Change: Nothing
* Cause: Update to V3.0
********************************************************************************
*  Version: 3.1
*  Author/Date: jiaF/2021.9.1
*  Change: Delete not used macro.
*  Cause: Update
********************************************************************************
*  Version: 3.2
*  Author/Date: TianSL/2024.4.02
*  Change: Modify the label of P2CONST member.
*  Cause: Update
********************************************************************************
*  Version: 3.3
*  Author/Date: TianSL/2024.5.20
*  Change: Add Memmap segment definition.
*  Cause: Update
********************************************************************************
*  Version: 3.4
*  Author/Date: TianSL/2024.7.1
*  Change: Modify copyright.
*  Cause: Update
********************************************************************************
*  Version: 3.5
*  Author/Date: TianSL/2025.6.4
*  Change: Add the polyspace deviation suppression comment.
*  Cause: Update
********************************************************************************
*/
#ifndef CANNM_CBK_H_
#define CANNM_CBK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanNm_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Definition of Callback API-Ids. */
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANNM_SID_TXCONFIRMATION        (0x40U)
#define CANNM_SID_RXINDICATION          (0x42U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

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
#define CANNM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"

extern FUNC(void, CANNM_CODE) CanNm_RxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_DATA) PduInfoPtr
);

#if( (CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_IMMEDIATE_TXCONF_ENABLED == STD_OFF) )
extern FUNC(void, CANNM_CODE) CanNm_TxConfirmation(PduIdType TxPduId);
#endif

#define CANNM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"

#endif  /* CANNM_CBK_H_ */

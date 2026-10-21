/*
********************************************************************************
*
* File name: CanTp_Cbk.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: TanLX/2018.12.10
* Change: New
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: TanLX/2019.10.12
* Change: Modify MIRSA-C code.
* Cause: Modify
********************************************************************************
* Version: 1.2
* Author/Date: LiuZY/2019.11.19
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 1.3
* Author/Date: TanLX/2019.12.13
* Change: Delete invalid function "CanTp_TxIsIdle". Bug:NEUSCCORE-96.
* Cause: Checking out code according to Autosar article.
********************************************************************************
* Version: 1.4
* Author/Date: SongQW/2019.12.23
* Change: Add "CanTp_GetTxSduData", "CanTp_GetRxSduData" and
*         "CanTp_GetTxPduIdToPdur" and "CanTp_GetTxSduDataByTxPduId" functions.
* Cause: Bugfix
********************************************************************************
* Version: 1.5
* Author/Date: SongQW/2020.02.28
* Change: Add Common_MemCmp function.
* Cause: Compare scenes.
********************************************************************************
* Version: 3.0
* Author/Date: SongQW/2020.05.15
* Change: Modify the coding specification.
* Cause: Optimize
********************************************************************************
* Version: 3.1
* Author/Date: ZhuCHY/2020.09.16
* Change: Add function of MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: ZhuCHY/2020.09.18
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: liuZY/2020.10.26
* Change: Modify the code specification format
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: LiuZY/2020.11.02
* Change: Modify the interface declaration position according to the document.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LiuZY/2020.11.03
* Change: Modify the incorrectly defined part of the code format.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: YanCL/2024.4.2
* Change: 1.Modify the P2CONST incorrect labels.
*         2.Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: YanCL/2024.7.3
* Change: 1.Add Memmap segment definition.
*         2.Update copyright information.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: YanCL/2025.06.23
* Change: #include "CanTp_MemMap.h" add suppression comments.
* Cause: Update
********************************************************************************
*/
#ifndef CANTP_CBK_H_
#define CANTP_CBK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanTp.h"
#include "CanTp_Lcfg.h"
#include "PduR_CanTp.h"

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

#define CANTP_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"

extern FUNC(void, CANTP_CODE) CanTp_RxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr
);
extern FUNC(void, CANTP_CODE) CanTp_TxConfirmation(PduIdType TxPduId);

#define CANTP_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"

#endif  /* CANTP_CBK_H_ */

/*
********************************************************************************
*
* File name: J1939Tp_Cbk.h
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2019.3.18
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: li.zhiheng/2020.03.30
* Change: Nothing
* Cause: Update to 3.0.
********************************************************************************
* Version: 3.1
* Author/Date: li.zhiheng/2020.05.20
* Change: Modification code specification.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: li.zhiheng/2020.10.15
* Change: 1.Modify coding standards.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: YanCL/2024.4.2
* Change: 1.Modify the P2CONST incorrect labels.
*         2.Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: YanCL/2024.5.23
* Change: Adjusting the parameter positions of function declarations.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: YanCL/2024.6.25
* Change: 1.Add Memmap segment definition.
*         2.Add copyright information.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: YanCL/2025.06.23
* Change: #include "J1939Tp_MemMap.h" add suppression comments.
* Cause: Update
********************************************************************************
*/
#ifndef J1939TP_CBK_H_
#define J1939TP_CBK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "J1939Tp_Cfg.h"

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
*    Global variable
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

#define J1939TP_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"

extern FUNC(void, J1939TP_CODE) J1939Tp_RxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) PduInfoPtr
);
extern FUNC(void, J1939TP_CODE) J1939Tp_TxConfirmation(PduIdType TxPduId);

#define J1939TP_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"

#endif /* J1939TP_CBK_H_ */

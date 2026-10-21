/*
********************************************************************************
*
* File name: J1939Tp_Cmdt.h
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
* Cause: Update to 3.0
********************************************************************************
* Version: 3.1
* Author/Date: li.zhiheng/2020.05.20
* Change: Modification code specification.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: li.zhiheng/2020.09.26
* Change: Add code related to MEMAP.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: li.zhiheng/2020.10.15
* Change: 1.Modify coding standards.
*         2.Modify QAC warning.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: LiZH/2020.11.04
* Change: Delete the function declaration contained in MemMap.h.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: LiZH/2020.5.25
* Change: Modifty J1939Tp_CmdtTransmit, J1939Tp_CmdtRxMain function declaration.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: Li.ZH/2021.8.16
* Change: Modification code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.7
* Author/Date: TongXY/2023.3.14
* Change: Fix coding specification problems.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: YanCL/2024.3.19
* Change: Modify the P2CONST incorrect labels.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: YanCL/2024.4.2
* Change: 1.Modify the P2CONST incorrect labels.
*         2.Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: YanCL/2024.5.23
* Change: Adjusting the parameter positions of function declarations.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: YanCL/2024.6.25
* Change: 1.Add Memmap segment definition.
*         2.Add copyright information.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: YanCL/2025.06.23
* Change: #include "J1939Tp_MemMap.h" add suppression comments.
* Cause: Update
********************************************************************************
*/
#ifndef J1939TP_CMDT_H_
#define J1939TP_CMDT_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "J1939Tp.h"
#include "ComStack_Types.h"
#include "J1939Tp_Types.h"

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

#define J1939TP_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"

#if (J1939TP_CMDT_TX_ENABLED == STD_ON)
extern FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_CmdtTransmit
(
    PduIdType sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint8 sa,
    uint8 da,
    uint8 pri
);
#endif
extern FUNC(void, J1939TP_CODE) J1939Tp_CmdtTxMain(PduIdType sduIdx);
extern FUNC(void, J1939TP_CODE) J1939Tp_CmdtRxMain(PduIdType sduIdx);
extern FUNC(void, J1939TP_CODE) J1939Tp_CmdtTxConfirmation
(
    PduIdType sduIdx,
    uint8 pduType,
    J1939Tp_NSduType sduType
);
extern FUNC(void, J1939TP_CODE) J1939Tp_CmdtRxIndication
(
    PduIdType pduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint8 pduType,
    uint8 sa,
    uint8 da
);

#define J1939TP_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"

#endif /* J1939TP_CMDT_H_ */


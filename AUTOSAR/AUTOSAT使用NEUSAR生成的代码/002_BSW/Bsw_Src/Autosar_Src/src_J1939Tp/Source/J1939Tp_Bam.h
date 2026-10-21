/*
********************************************************************************
*
* File name: J1939Tp_Bam.h
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: li.zhiheng/2019.11.06
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: li.zhiheng/2021.5.25
* Change: 1.Updata to 3.1.
*         2.Add the J1939Tp_BamTransmit function declaration.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: YanCL/2024.3.19
* Change: Modify the P2CONST incorrect labels.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: YanCL/2024.4.2
* Change: 1.Modify the P2CONST incorrect labels.
*         2.Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: YanCL/2024.5.23
* Change: Adjusting the parameter positions of function declarations.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: YanCL/2024.6.25
* Change: 1.Add Memmap segment definition.
*         2.Add copyright information.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: YanCL/2025.06.23
* Change: #include "J1939Tp_MemMap.h" add suppression comments.
* Cause: Update
********************************************************************************
*/
#ifndef J1939TP_BAM_H_
#define J1939TP_BAM_H_

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

#if (J1939TP_BAM_TX_ENABLED == STD_ON)
extern FUNC(void, J1939TP_CODE) J1939Tp_BamTxMain(PduIdType sduIdx);
extern FUNC(Std_ReturnType, J1939TP_CODE) J1939Tp_BamTransmit
(
    PduIdType sduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint8 sa,
    uint8 pri
);
extern FUNC(void, J1939TP_CODE) J1939Tp_BamTxConfirmation
(
    PduIdType sduIdx,
    uint8 pduType
);
#endif  /* J1939TP_BAM_TX_ENABLED == STD_ON */

#if (J1939TP_BAM_RX_ENABLED == STD_ON)
extern FUNC(void, J1939TP_CODE) J1939Tp_BamRxIndication
(
    PduIdType pduIdx,
    P2CONST(PduInfoType, AUTOMATIC, J1939TP_APPL_DATA) info,
    uint8 pduType,
    uint8 sa,
    uint8 da
);
extern FUNC(void, J1939TP_CODE) J1939Tp_BamRxMain(PduIdType sduIdx);
#endif  /* J1939TP_BAM_RX_ENABLED == STD_ON */

#define J1939TP_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"

#endif /* J1939TP_BAM_H_ */


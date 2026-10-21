/*
********************************************************************************
*
*  File name: PduR_Queue.h
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: SunHQ/2022.09.20
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: SunHQ/2023.02.10
* Change: Modify the macro that controls the code implementation.
* Cause: Clear compile warning.
********************************************************************************
* Version: 3.2
* Author/Date: SunHQ/2023.02.28
* Change: Add an argument(bufferSizePtr) to the PduR_Queue_LoTpCopyRxData
*         function.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: LuQ/2024.04.02
* Change: 1. Modify the comments format.
*         2. Modify P2CONST member labels.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: LuQ/2024.05.13
* Change: Add Memmap segment definition.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LuQ/2024.09.20
* Change: 1. Add function PduR_Queue_LoTpStartOfReceptionCheck.
*         2. Modify copyright information.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LuQ/2024.09.23
* Change: Clear compile error.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LuQ/2025.03.27
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: LuQ/2025.06.23
* Change: Modify the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef PDUR_QUEUE_H_
#define PDUR_QUEUE_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "PduR_Types.h"

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
/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_START_SEC_GLOBAL_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"

/* PolySpace +1 MISRA-C3:8.6 [Justified:Unset] "NSCA_Polyspace_PduR_8.6" */
extern P2VAR(uint8, PDUR_VAR_INIT, PDUR_APPL_DATA) PduR_RoutingPathFlagTable;

/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_STOP_SEC_GLOBAL_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"

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
#if (STD_OFF == PDUR_ZERO_COST_OPERATION)
/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"
extern FUNC(void, PDUR_CODE) PduR_Queue_Init
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_CONST) buffer
);
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_Queue_UpCancelReceive
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_CONST) buffer,
    PduIdType id
);
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_Queue_UpCancelTransmit
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_CONST) buffer,
    PduIdType id
);
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_Queue_UpTransmit
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_CONST) buffer,
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
);
extern FUNC(void, PDUR_CODE) PduR_Queue_LoTxConfirmation
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_CONST) buffer,
    PduIdType id
);
extern FUNC(void, PDUR_CODE) PduR_Queue_LoRxIndication
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_CONST) buffer,
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
);
extern FUNC(void, PDUR_CODE) PduR_Queue_LoTpRxIndication
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_CONST) buffer,
    PduIdType id,
    Std_ReturnType result
);
extern FUNC(void, PDUR_CODE) PduR_Queue_LoTpTxConfirmation
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_CONST) buffer,
    PduIdType id,
    Std_ReturnType result
);
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Queue_LoTpCopyRxData
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_CONST) buffer,
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Queue_LoTpStartOfReception
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_CONST) buffer,
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength
);
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_Queue_LoTpStartOfReceptionCheck
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_CONST) buffer,
    P2CONST(PduRDestPdu_Type, AUTOMATIC, PDUR_APPL_CONST) dstPduPtr,
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength
);
extern FUNC(void, PDUR_CODE) PduR_Queue_Process
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_CONST) buffer
);
/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"
#endif /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */

#endif /* #ifndef PDUR_QUEUE_H_ */

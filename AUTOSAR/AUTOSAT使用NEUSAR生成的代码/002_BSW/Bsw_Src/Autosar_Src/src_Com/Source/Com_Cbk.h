/*
********************************************************************************
*
* File name: Com_Cbk.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : Sunpengfei/2018.09.25
* Change: Add
* Cause: New
********************************************************************************
* Version: 2.0
* Author/Date : Sunpengfei/2019.04.15
* Change: V2.0 release.
* Cause: Update
********************************************************************************
* Version: 3.0
* Author/Date : lizhiheng/2019.12.24
* Change: Modify some macro definitions and types.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date : lizhiheng/2020.05.07
* Change: Delete #include "typedefs.h".
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date : lizhiheng/2020.05.11
* Change: Modify code specification.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date : lizhiheng/2020.09.30
* Change: Modify the coding style of AutoSar.
* Cause: Updata.
********************************************************************************
* Version: 3.4
* Author/Date : lizhiheng/2020.10.13
* Change: Remove non-pointer coding modification.
* Cause: Updata.
********************************************************************************
* Version: 3.5
* Author/Date : LiZH/2020.11.05
* Change: Modify the incorrectly defined part of the code format.
* Cause: Optimization.
********************************************************************************
* Version: 3.6
* Author/Date : LuQ/2024.04.02
* Change: 1. Modify P2CONST member labels.
*         2. Modify the comments format.
* Cause: Optimization.
********************************************************************************
* Version: 3.7
* Author/Date: LuQ/2024.09.19
* Change: Add Memmap segment definition.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: LuQ/2024.10.10
* Change: Modify Memmap segment definition.
* Cause: Optimization
********************************************************************************
*/
#ifndef COM_CBK_H_
#define COM_CBK_H_

/*
*******************************************************************************
*    Includes
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Macros
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Types
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Variables
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Constants
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Functions
*******************************************************************************
*/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
extern FUNC(Std_ReturnType, COM_CODE) Com_TriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
extern FUNC(void, COM_CODE) Com_RxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
extern FUNC(void, COM_CODE) Com_TpRxIndication
(
    PduIdType id,
    Std_ReturnType result
);
extern FUNC(void, COM_CODE) Com_TxConfirmation
(
    PduIdType TxPduId
);
extern FUNC(void, COM_CODE) Com_TpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
);
extern FUNC(BufReq_ReturnType, COM_CODE) Com_StartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) bufferSizePtr
);
extern FUNC(BufReq_ReturnType, COM_CODE) Com_CopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_CONST) info,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) bufferSizePtr
);
extern FUNC(BufReq_ReturnType, COM_CODE) Com_CopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, COM_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) availableDataPtr
);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#endif /* COM_CBK_ */

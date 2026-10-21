/*
********************************************************************************
*
* File name: Com_Write.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: TianG/2024.03.22
* Change: Add
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: LuQ/2024.09.20
* Change: Modify CONST member labels.
* Cause: Optimization
********************************************************************************
* Version: 1.2
* Author/Date: LuQ/2024.09.30
* Change: Correct the coding specifications.
* Cause: Optimization
********************************************************************************
* Version: 1.3
* Author/Date: LuQ/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 1.4
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 1.5
* Author/Date: LuQ/2025.06.23
* Change: Modify the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
* Include
********************************************************************************
*/
#include "Com_Write.h"

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
#define COM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"
static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */


static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */
static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_TxAssignSignal_BOOLEAN
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U64_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S64_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U64_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_S64_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_F32_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_F32_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_F64_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_F64_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_TxAssignSignal_U8N
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

#define COM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
#define COM_START_SEC_CONST
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Signal assign to pdu function table. */
CONST(Com_TxAssignSignal_Func, COM_APPL_CONST) Com_TxAssignSignal_FuncTable[COM_TXASSIGNSIGNAL_FUNC_NUM] =
{
    Com_TxAssignSignal_BOOLEAN,                                      /* Assign bool value to pdu. */
    Com_TxAssignSignal_U8_PosFullByte_BE,                            /* Assign uint8 type value to pdu of big endian type. */
    Com_TxAssignSignal_U8_PosToHighBit_BE,                           /* Assign uint8 type value to pdu of big endian type. */
    Com_TxAssignSignal_U8_PosToLowhBit_BE,                           /* Assign uint8 type value to pdu of big endian type. */
    Com_TxAssignSignal_U8_PosInMidBit_BE,                            /* Assign uint8 type value to pdu of big endian type. */
    Com_TxAssignSignal_U8_PosCrossBytes_BE,                          /* Assign uint8 type value to pdu of big endian type. */
    Com_TxAssignSignal_U16_PosFullByte_BE,                           /* Assign uint16 type value to pdu of big endian type. */
    Com_TxAssignSignal_U16_PosToHighBit_BE,                          /* Assign uint16 type value to pdu of big endian type. */
    Com_TxAssignSignal_U16_PosToLowhBit_BE,                          /* Assign uint16 type value to pdu of big endian type. */
    Com_TxAssignSignal_U16_PosInMidBit_BE,                           /* Assign uint16 type value to pdu of big endian type. */
    Com_TxAssignSignal_U16_PosCrossBytes_BE,                         /* Assign uint16 type value to pdu of big endian type. */
    Com_TxAssignSignal_U24_PosFullByte_BE,                           /* Assign uint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_U24_PosToHighBit_BE,                          /* Assign uint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_U24_PosToLowhBit_BE,                          /* Assign uint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_U24_PosInMidBit_BE,                           /* Assign uint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_U24_PosCrossBytes_BE,                         /* Assign uint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_U32_PosFullByte_BE,                           /* Assign uint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_U32_PosToHighBit_BE,                          /* Assign uint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_U32_PosToLowhBit_BE,                          /* Assign uint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_U32_PosInMidBit_BE,                           /* Assign uint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_U32_PosCrossBytes_BE,                         /* Assign uint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_U64_BE,                                       /* Assign uint64 type value to pdu of big endian type. */
    Com_TxAssignSignal_S8_PosFullByte_BE,                            /* Assign sint8 type value to pdu of big endian type. */
    Com_TxAssignSignal_S8_PosToHighBit_BE,                           /* Assign sint8 type value to pdu of big endian type. */
    Com_TxAssignSignal_S8_PosToLowhBit_BE,                           /* Assign sint8 type value to pdu of big endian type. */
    Com_TxAssignSignal_S8_PosInMidBit_BE,                            /* Assign sint8 type value to pdu of big endian type. */
    Com_TxAssignSignal_S8_PosCrossBytes_BE,                          /* Assign sint8 type value to pdu of big endian type. */
    Com_TxAssignSignal_S16_PosFullByte_BE,                           /* Assign sint16 type value to pdu of big endian type. */
    Com_TxAssignSignal_S16_PosToHighBit_BE,                          /* Assign sint16 type value to pdu of big endian type. */
    Com_TxAssignSignal_S16_PosToLowhBit_BE,                          /* Assign sint16 type value to pdu of big endian type. */
    Com_TxAssignSignal_S16_PosInMidBit_BE,                           /* Assign sint16 type value to pdu of big endian type. */
    Com_TxAssignSignal_S16_PosCrossBytes_BE,                         /* Assign sint16 type value to pdu of big endian type. */
    Com_TxAssignSignal_S24_PosFullByte_BE,                           /* Assign sint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_S24_PosToHighBit_BE,                          /* Assign sint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_S24_PosToLowhBit_BE,                          /* Assign sint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_S24_PosInMidBit_BE,                           /* Assign sint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_S24_PosCrossBytes_BE,                         /* Assign sint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_S32_PosFullByte_BE,                           /* Assign sint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_S32_PosToHighBit_BE,                          /* Assign sint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_S32_PosToLowhBit_BE,                          /* Assign sint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_S32_PosInMidBit_BE,                           /* Assign sint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_S32_PosCrossBytes_BE,                         /* Assign sint32 type value to pdu of big endian type. */
    Com_TxAssignSignal_S64_BE,                                       /* Assign sint64 type value to pdu of big endian type. */
    Com_TxAssignSignal_F32_BE,                                       /* Assign float32 type value to pdu of big endian type. */
    Com_TxAssignSignal_F64_BE,                                       /* Assign float64 type value to pdu of big endian type. */
    Com_TxAssignSignal_U8_PosFullByte_LE,                            /* Assign uint8 type value to pdu of little endian type. */
    Com_TxAssignSignal_U8_PosToHighBit_LE,                           /* Assign uint8 type value to pdu of little endian type. */
    Com_TxAssignSignal_U8_PosToLowhBit_LE,                           /* Assign uint8 type value to pdu of little endian type. */
    Com_TxAssignSignal_U8_PosInMidBit_LE,                            /* Assign uint8 type value to pdu of little endian type. */
    Com_TxAssignSignal_U8_PosCrossBytes_LE,                          /* Assign uint8 type value to pdu of little endian type. */
    Com_TxAssignSignal_U16_PosFullByte_LE,                           /* Assign uint16 type value to pdu of little endian type. */
    Com_TxAssignSignal_U16_PosToHighBit_LE,                          /* Assign uint16 type value to pdu of little endian type. */
    Com_TxAssignSignal_U16_PosToLowhBit_LE,                          /* Assign uint16 type value to pdu of little endian type. */
    Com_TxAssignSignal_U16_PosInMidBit_LE,                           /* Assign uint16 type value to pdu of little endian type. */
    Com_TxAssignSignal_U16_PosCrossBytes_LE,                         /* Assign uint16 type value to pdu of little endian type. */
    Com_TxAssignSignal_U24_PosFullByte_LE,                           /* Assign uint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_U24_PosToHighBit_LE,                          /* Assign uint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_U24_PosToLowhBit_LE,                          /* Assign uint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_U24_PosInMidBit_LE,                           /* Assign uint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_U24_PosCrossBytes_LE,                         /* Assign uint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_U32_PosFullByte_LE,                           /* Assign uint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_U32_PosToHighBit_LE,                          /* Assign uint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_U32_PosToLowhBit_LE,                          /* Assign uint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_U32_PosInMidBit_LE,                           /* Assign uint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_U32_PosCrossBytes_LE,                         /* Assign uint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_U64_LE,                                       /* Assign uint64 type value to pdu of little endian type. */
    Com_TxAssignSignal_S8_PosFullByte_LE,                            /* Assign sint8 type value to pdu of little endian type. */
    Com_TxAssignSignal_S8_PosToHighBit_LE,                           /* Assign sint8 type value to pdu of little endian type. */
    Com_TxAssignSignal_S8_PosToLowhBit_LE,                           /* Assign sint8 type value to pdu of little endian type. */
    Com_TxAssignSignal_S8_PosInMidBit_LE,                            /* Assign sint8 type value to pdu of little endian type. */
    Com_TxAssignSignal_S8_PosCrossBytes_LE,                          /* Assign sint8 type value to pdu of little endian type. */
    Com_TxAssignSignal_S16_PosFullByte_LE,                           /* Assign sint16 type value to pdu of little endian type. */
    Com_TxAssignSignal_S16_PosToHighBit_LE,                          /* Assign sint16 type value to pdu of little endian type. */
    Com_TxAssignSignal_S16_PosToLowhBit_LE,                          /* Assign sint16 type value to pdu of little endian type. */
    Com_TxAssignSignal_S16_PosInMidBit_LE,                           /* Assign sint16 type value to pdu of little endian type. */
    Com_TxAssignSignal_S16_PosCrossBytes_LE,                         /* Assign sint16 type value to pdu of little endian type. */
    Com_TxAssignSignal_S24_PosFullByte_LE,                           /* Assign sint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_S24_PosToHighBit_LE,                          /* Assign sint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_S24_PosToLowhBit_LE,                          /* Assign sint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_S24_PosInMidBit_LE,                           /* Assign sint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_S24_PosCrossBytes_LE,                         /* Assign sint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_S32_PosFullByte_LE,                           /* Assign sint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_S32_PosToHighBit_LE,                          /* Assign sint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_S32_PosToLowhBit_LE,                          /* Assign sint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_S32_PosInMidBit_LE,                           /* Assign sint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_S32_PosCrossBytes_LE,                         /* Assign sint32 type value to pdu of little endian type. */
    Com_TxAssignSignal_S64_LE,                                       /* Assign sint64 type value to pdu of little endian type. */
    Com_TxAssignSignal_F32_LE,                                       /* Assign float32 type value to pdu of little endian type. */
    Com_TxAssignSignal_F64_LE,                                       /* Assign float64 type value to pdu of little endian type. */
    Com_TxAssignSignal_U8N                                           /* Assign Uint8_N type value to pdu of little endian type. */
};
#define COM_STOP_SEC_CONST
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
#define COM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U8_PosFullByte_BE
*
* Explanation: Assign a unsigned char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    /* Assign uint8 value to pdu. */
    destBuffer[signalBaseRef->sigStartByte] = (uint8)(srcBuffer[COM_INIT_ZERO]);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S8_PosFullByte_BE
*
* Explanation: Assign a signed char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    /* Assign sint8 value to pdu. */
    destBuffer[signalBaseRef->sigStartByte] = (uint8)(srcBuffer[COM_INIT_ZERO]);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U8_PosFullByte_LE
*
* Explanation: Assign a unsigned char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    /* Assign uint8 value to pdu. */
    destBuffer[signalBaseRef->sigStartByte] = (uint8)(srcBuffer[COM_INIT_ZERO]);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S8_PosFullByte_LE
*
* Explanation: Assign a signed char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    /* Assign sint8 value to pdu. */
    destBuffer[signalBaseRef->sigStartByte] = (uint8)(srcBuffer[COM_INIT_ZERO]);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U8_PosToHighBit_BE
*
* Explanation: Assign a unsigned char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U8 &= (uint8)(~(uint8)(COM_INIT_FF << bitSize));
    /* Clear valid bits of pdu. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign valid value to pdu. */
    destBuffer[bytePos] |= (uint8)(tmpSignData_U8 << bitPos);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S8_PosToHighBit_BE
*
* Explanation: Assign a signed char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U8 &= (uint8)(~(uint8)(COM_INIT_FF << bitSize));
    /* Clear valid bits of pdu. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign valid value to pdu. */
    destBuffer[bytePos] |= (uint8)(tmpSignData_U8 << bitPos);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U8_PosToHighBit_LE
*
* Explanation: Assign a unsigned char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U8 &= (uint8)(~(uint8)(COM_INIT_FF << bitSize));
    /* Clear valid bits of pdu. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign valid value to pdu. */
    destBuffer[bytePos] |= (uint8)(tmpSignData_U8 << bitPos);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S8_PosToHighBit_LE
*
* Explanation: Assign a signed char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U8 &= (uint8)(~(uint8)(COM_INIT_FF << bitSize));
    /* Clear valid bits of pdu. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign valid value to pdu. */
    destBuffer[bytePos] |= (uint8)(tmpSignData_U8 << bitPos);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U8_PosToLowhBit_BE
*
* Explanation: Assign a unsigned char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Clear invalid bits of signal value. */
    tmpSignData_U8 &= (uint8)(~(uint8)(COM_INIT_FF << bitSize));
    /* Clear valid bits of pdu. */
    destBuffer[bytePos] &= (uint8)(COM_INIT_FF << bitSize);
    /* Assign valid value to pdu. */
    destBuffer[bytePos] |= tmpSignData_U8;

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S8_PosToLowhBit_BE
*
* Explanation: Assign a signed char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Clear invalid bits of signal value. */
    tmpSignData_U8 &= (uint8)(~(uint8)(COM_INIT_FF << bitSize));
    /* Clear valid bits of pdu. */
    destBuffer[bytePos] &= (uint8)(COM_INIT_FF << bitSize);
    /* Assign valid value to pdu. */
    destBuffer[bytePos] |= tmpSignData_U8;

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U8_PosToLowhBit_LE
*
* Explanation: Assign a unsigned char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Clear invalid bits of signal value. */
    tmpSignData_U8 &= (uint8)(~(uint8)(COM_INIT_FF << bitSize));
    /* Clear valid bits of pdu. */
    destBuffer[bytePos] &= (uint8)(COM_INIT_FF << bitSize);
    /* Assign valid value to pdu. */
    destBuffer[bytePos] |= tmpSignData_U8;

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S8_PosToLowhBit_LE
*
* Explanation: Assign a signed char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Clear invalid bits of signal value. */
    tmpSignData_U8 &= (uint8)(~(uint8)(COM_INIT_FF << bitSize));
    /* Clear valid bits of pdu. */
    destBuffer[bytePos] &= (uint8)(COM_INIT_FF << bitSize);
    /* Assign valid value to pdu. */
    destBuffer[bytePos] |= tmpSignData_U8;

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U8_PosInMidBit_BE
*
* Explanation: Assign a unsigned char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint8 mask = (uint8)((COM_INIT_FF << (bitPos + bitSize))) | (uint8)(~(uint8)(COM_INIT_FF << bitPos));

    /* Clear invalid bits of signal value. */
    tmpSignData_U8 &= (uint8)(~(uint8)(COM_INIT_FF << bitSize));
    /* Clear valid bits of pdu. */
    destBuffer[bytePos] &= mask;
    /* Assign valid value to pdu. */
    destBuffer[bytePos] |= (uint8)(tmpSignData_U8 << bitPos);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S8_PosInMidBit_BE
*
* Explanation: Assign a signed char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint8 mask = (uint8)((COM_INIT_FF << (bitPos + bitSize))) | (uint8)(~(uint8)(COM_INIT_FF << bitPos));

    /* Clear invalid bits of signal value. */
    tmpSignData_U8 &= (uint8)(~(uint8)(COM_INIT_FF << bitSize));
    /* Clear valid bits of pdu. */
    destBuffer[bytePos] &= mask;
    /* Assign valid value to pdu. */
    destBuffer[bytePos] |= (uint8)(tmpSignData_U8 << bitPos);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U8_PosInMidBit_LE
*
* Explanation: Assign a unsigned char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint8 mask = (uint8)((COM_INIT_FF << (bitPos + bitSize))) | (uint8)(~(uint8)(COM_INIT_FF << bitPos));

    /* Clear invalid bits of signal value. */
    tmpSignData_U8 &= (uint8)(~(uint8)(COM_INIT_FF << bitSize));
    /* Clear valid bits of pdu. */
    destBuffer[bytePos] &= mask;
    /* Assign valid value to pdu. */
    destBuffer[bytePos] |= (uint8)(tmpSignData_U8 << bitPos);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S8_PosInMidBit_LE
*
* Explanation: Assign a signed char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint8 mask = (uint8)((COM_INIT_FF << (bitPos + bitSize))) | (uint8)(~(uint8)(COM_INIT_FF << bitPos));

    /* Clear invalid bits of signal value. */
    tmpSignData_U8 &= (uint8)(~(uint8)(COM_INIT_FF << bitSize));
    /* Clear valid bits of pdu. */
    destBuffer[bytePos] &= mask;
    /* Assign valid value to pdu. */
    destBuffer[bytePos] |= (uint8)(tmpSignData_U8 << bitPos);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U8_PosCrossBytes_BE
*
* Explanation: Assign a unsigned char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint16 tmpVal;

    /* Clear invalid bits of signal value. */
    tmpVal = (uint16)(tmpSignData_U8 & (uint8)(~(uint8)(COM_INIT_FF << bitSize)));  /* PRQA S 4391 */ /* NSCA_QAC_Com_Rule10.8 */

    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint8)(tmpVal << bitPos) & COM_INIT_FF);

    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_1BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] |= (uint8)(((tmpVal >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF));

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S8_PosCrossBytes_BE
*
* Explanation: Assign a signed char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint16 tmpVal;

    /* Clear invalid bits of signal value. */
    tmpVal = (uint16)(tmpSignData_U8 & (uint8)(~(uint8)(COM_INIT_FF << bitSize)));  /* PRQA S 4391 */ /* NSCA_QAC_Com_Rule10.8 */

    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint8)(tmpVal << bitPos) & COM_INIT_FF);

    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_1BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] |= (uint8)(((tmpVal >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF));

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U8_PosCrossBytes_LE
*
* Explanation: Assign a unsigned char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U8_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint16 tmpVal;

    /* Clear invalid bits of signal value. */
    tmpVal = (uint16)(tmpSignData_U8 & (uint8)(~(uint8)(COM_INIT_FF << bitSize)));  /* PRQA S 4391 */ /* NSCA_QAC_Com_Rule10.8 */

    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint8)(tmpVal << bitPos) & COM_INIT_FF);

    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_1BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] |= (uint8)(((tmpVal >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF));
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S8_PosCrossBytes_LE
*
* Explanation: Assign a signed char value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S8_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8 = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint16 tmpVal;

    /* Clear invalid bits of signal value. */
    tmpVal = (uint16)(tmpSignData_U8 & (uint8)(~(uint8)(COM_INIT_FF << bitSize)));  /* PRQA S 4391 */ /* NSCA_QAC_Com_Rule10.8 */

    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint8)(tmpVal << bitPos) & COM_INIT_FF);

    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_1BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] |= (uint8)(((tmpVal >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF));
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U16_PosFullByte_BE
*
* Explanation: Assign a unsigned short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U16 & COM_INIT_FF;
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U16 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S16_PosFullByte_BE
*
* Explanation: Assign a signed short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U16 & COM_INIT_FF;
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U16 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U16_PosFullByte_LE
*
* Explanation: Assign a unsigned short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U16 & COM_INIT_FF;
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U16 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S16_PosFullByte_LE
*
* Explanation: Assign a signed short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U16 & COM_INIT_FF;
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U16 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U16_PosToHighBit_BE
*
* Explanation: Assign a unsigned short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint16)(tmpSignData_U16 << bitPos) & COM_INIT_FF);
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U16 >> (COM_1BYTE_BITLENGTH - bitPos));
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S16_PosToHighBit_BE
*
* Explanation: Assign a signed short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint16)(tmpSignData_U16 << bitPos) & COM_INIT_FF);
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U16 >> (COM_1BYTE_BITLENGTH - bitPos));
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U16_PosToHighBit_LE
*
* Explanation: Assign a unsigned short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint8)(tmpSignData_U16 << bitPos) & COM_INIT_FF);
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U16 >> (COM_1BYTE_BITLENGTH - bitPos));
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S16_PosToHighBit_LE
*
* Explanation: Assign a signed short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint8)(tmpSignData_U16 << bitPos) & COM_INIT_FF);
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U16 >> (COM_1BYTE_BITLENGTH - bitPos));
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U16_PosToLowhBit_BE
*
* Explanation: Assign a unsigned short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U16 & COM_INIT_FF;
    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] &= (uint8)(COM_INIT_FF << (bitSize - COM_1BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] |= (uint8)((tmpSignData_U16 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S16_PosToLowhBit_BE
*
* Explanation: Assign a signed short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U16 & COM_INIT_FF;
    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] &= (uint8)(COM_INIT_FF << (bitSize - COM_1BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] |= (uint8)((tmpSignData_U16 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U16_PosToLowhBit_LE
*
* Explanation: Assign a unsigned short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U16 & COM_INIT_FF;
    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] &= (uint8)(COM_INIT_FF << (bitSize - COM_1BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] |= (uint8)((tmpSignData_U16 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S16_PosToLowhBit_LE
*
* Explanation: Assign a signed short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U16 & COM_INIT_FF;
    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] &= (uint8)(COM_INIT_FF << (bitSize - COM_1BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] |= (uint8)((tmpSignData_U16 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U16_PosInMidBit_BE
*
* Explanation: Assign a unsigned short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint16)(tmpSignData_U16 << bitPos) & COM_INIT_FF);

    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_1BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] |= (uint8)((tmpSignData_U16 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S16_PosInMidBit_BE
*
* Explanation: Assign a signed short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint16)(tmpSignData_U16 << bitPos) & COM_INIT_FF);

    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_1BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_ONE] |= (uint8)((tmpSignData_U16 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U16_PosInMidBit_LE
*
* Explanation: Assign a unsigned short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint16)(tmpSignData_U16 << bitPos) & COM_INIT_FF);

    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_1BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] |= (uint8)((tmpSignData_U16 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S16_PosInMidBit_LE
*
* Explanation: Assign a signed short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint16)(tmpSignData_U16 << bitPos) & COM_INIT_FF);

    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_1BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_ONE] |= (uint8)((tmpSignData_U16 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U16_PosCrossBytes_BE
*
* Explanation: Assign a unsigned short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint16)(tmpSignData_U16 << bitPos) & COM_INIT_FF);

    /* Assign mid byte of value to the big-endian type pdu mid byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)((tmpSignData_U16 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);

    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_2BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] |= (uint8)((tmpSignData_U16 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S16_PosCrossBytes_BE
*
* Explanation: Assign a signed short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint16)(tmpSignData_U16 << bitPos) & COM_INIT_FF);

    /* Assign mid byte of value to the big-endian type pdu mid byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)((tmpSignData_U16 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);

    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_2BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] |= (uint8)((tmpSignData_U16 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U16_PosCrossBytes_LE
*
* Explanation: Assign a unsigned short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U16_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint16)(tmpSignData_U16 << bitPos) & COM_INIT_FF);

    /* Assign mid byte of value to the little-endian type pdu mid byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)((tmpSignData_U16 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);

    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_2BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] |= (uint8)((tmpSignData_U16 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S16_PosCrossBytes_LE
*
* Explanation: Assign a signed short value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S16_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16 = Com_Make16Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U16 &= (uint16)(~(uint16)(COM_INIT_U16FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((uint16)(tmpSignData_U16 << bitPos) & COM_INIT_FF);

    /* Assign mid byte of value to the little-endian type pdu mid byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)((tmpSignData_U16 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);

    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_2BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] |= (uint8)((tmpSignData_U16 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U24_PosFullByte_BE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)(tmpSignData_U24 & COM_INIT_FF);
    /* Assign mid byte of value to the big-endian type pdu mid byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)((tmpSignData_U24 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF);
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)((tmpSignData_U24 >> COM_2BYTE_BITLENGTH) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S24_PosFullByte_BE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)(tmpSignData_U24 & COM_INIT_FF);
    /* Assign mid byte of value to the big-endian type pdu mid byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)((tmpSignData_U24 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF);
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)((tmpSignData_U24 >> COM_2BYTE_BITLENGTH) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U24_PosFullByte_LE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)(tmpSignData_U24 & COM_INIT_FF);
    /* Assign mid byte of value to the little-endian type pdu mid byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)((tmpSignData_U24 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF);
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)((tmpSignData_U24 >> COM_2BYTE_BITLENGTH) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S24_PosFullByte_LE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)(tmpSignData_U24 & COM_INIT_FF);
    /* Assign mid byte of value to the little-endian type pdu mid byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)((tmpSignData_U24 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF);
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)((tmpSignData_U24 >> COM_2BYTE_BITLENGTH) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U24_PosToHighBit_LE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U24 << bitPos) & COM_INIT_FF);
    /* Assign mid byte of value to the little-endian type pdu mid byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)((tmpSignData_U24 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)((tmpSignData_U24 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U24_PosToHighBit_BE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U24 << bitPos) & COM_INIT_FF);
    /* Assign mid byte of value to the big-endian type pdu mid byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)((tmpSignData_U24 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)((tmpSignData_U24 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S24_PosToHighBit_LE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U24 << bitPos) & COM_INIT_FF);
    /* Assign mid byte of value to the little-endian type pdu mid byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)((tmpSignData_U24 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)((tmpSignData_U24 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S24_PosToHighBit_BE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U24 << bitPos) & COM_INIT_FF);
    /* Assign mid byte of value to the big-endian type pdu mid byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)((tmpSignData_U24 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)((tmpSignData_U24 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U24_PosToLowhBit_LE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U24 & COM_INIT_FF;
    /* Assign mid byte of value to the little-endian type pdu mid byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U24 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;
    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] &= (uint8)(COM_INIT_FF << (bitSize - COM_2BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] |= (uint8)(tmpSignData_U24 >> COM_2BYTE_BITLENGTH);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U24_PosToLowhBit_BE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U24 & COM_INIT_FF;
    /* Assign mid byte of value to the big-endian type pdu mid byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U24 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;
    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] &= (uint8)(COM_INIT_FF << (bitSize - COM_2BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] |= (uint8)(tmpSignData_U24 >> COM_2BYTE_BITLENGTH);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S24_PosToLowhBit_LE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U24 & COM_INIT_FF;
    /* Assign mid byte of value to the little-endian type pdu mid byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U24 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;
    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] &= (uint8)(COM_INIT_FF << (bitSize - COM_2BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] |= (uint8)(tmpSignData_U24 >> COM_2BYTE_BITLENGTH);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S24_PosToLowhBit_BE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U24 & COM_INIT_FF;
    /* Assign mid byte of value to the big-endian type pdu mid byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U24 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;
    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] &= (uint8)(COM_INIT_FF << (bitSize - COM_2BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] |= (uint8)(tmpSignData_U24 >> COM_2BYTE_BITLENGTH);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U24_PosInMidBit_LE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U24 << bitPos) & COM_INIT_FF);
    /* Assign mid byte of value to the little-endian type pdu mid byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U24 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_2BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] |= (uint8)((tmpSignData_U24 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U24_PosInMidBit_BE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U24 << bitPos) & COM_INIT_FF);
    /* Assign mid byte of value to the big-endian type pdu mid byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U24 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_2BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] |= (uint8)((tmpSignData_U24 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S24_PosInMidBit_LE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U24 << bitPos) & COM_INIT_FF);
    /* Assign mid byte of value to the little-endian type pdu mid byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U24 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_2BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_TWO] |= (uint8)((tmpSignData_U24 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S24_PosInMidBit_BE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U24 << bitPos) & COM_INIT_FF);
    /* Assign mid byte of value to the big-endian type pdu mid byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U24 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_2BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_TWO] |= (uint8)((tmpSignData_U24 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U24_PosCrossBytes_LE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U24 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the little-endian type pdu LoHi byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)((tmpSignData_U24 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign HiLo byte of value to the little-endian type pdu HiLo byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)((tmpSignData_U24 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_3BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] |= (uint8)((tmpSignData_U24 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U24_PosCrossBytes_BE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U24_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U24 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the big-endian type pdu LoHi byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)((tmpSignData_U24 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign HiLo byte of value to the big-endian type pdu HiLo byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)((tmpSignData_U24 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_3BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] |= (uint8)((tmpSignData_U24 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S24_PosCrossBytes_LE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U24 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the little-endian type pdu LoHi byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)((tmpSignData_U24 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign HiLo byte of value to the little-endian type pdu HiLo byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)((tmpSignData_U24 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_3BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] |= (uint8)((tmpSignData_U24 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S24_PosCrossBytes_BE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S24_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U24 = Com_Make24Bit(srcBuffer[COM_INIT_ZERO],
                                    srcBuffer[COM_INIT_ONE],srcBuffer[COM_INIT_TWO]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U24 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U24 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the big-endian type pdu LoHi byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)((tmpSignData_U24 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign HiLo byte of value to the big-endian type pdu HiLo byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)((tmpSignData_U24 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_3BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] |= (uint8)((tmpSignData_U24 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U32_PosFullByte_BE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U32 & COM_INIT_FF;
    /* Assign LoHi byte of value to the big-endian type pdu LoHi byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;
    /* Assign HiLo byte of value to the big-endian type pdu HiLo byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> COM_2BYTE_BITLENGTH) & COM_INIT_FF;
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] = (uint8)(tmpSignData_U32 >> COM_3BYTE_BITLENGTH) & COM_INIT_FF;

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S32_PosFullByte_BE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U32 & COM_INIT_FF;
    /* Assign LoHi byte of value to the big-endian type pdu LoHi byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;
    /* Assign HiLo byte of value to the big-endian type pdu HiLo byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> COM_2BYTE_BITLENGTH) & COM_INIT_FF;
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] = (uint8)(tmpSignData_U32 >> COM_3BYTE_BITLENGTH) & COM_INIT_FF;
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U32_PosFullByte_LE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U32 & COM_INIT_FF;
    /* Assign LoHi byte of value to the little-endian type pdu LoHi byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;
    /* Assign HiLo byte of value to the little-endian type pdu HiLo byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> COM_2BYTE_BITLENGTH) & COM_INIT_FF;
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] = (uint8)(tmpSignData_U32 >> COM_3BYTE_BITLENGTH) & COM_INIT_FF;
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S32_PosFullByte_LE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U32 & COM_INIT_FF;
    /* Assign LoHi byte of value to the little-endian type pdu LoHi byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;
    /* Assign HiLo byte of value to the little-endian type pdu HiLo byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> COM_2BYTE_BITLENGTH) & COM_INIT_FF;
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] = (uint8)(tmpSignData_U32 >> COM_3BYTE_BITLENGTH) & COM_INIT_FF;
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U32_PosToHighBit_BE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U32 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the big-endian type pdu LoHi byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)((tmpSignData_U32 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign HiLo byte of value to the big-endian type pdu HiLo byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)((tmpSignData_U32 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] = (uint8)((tmpSignData_U32 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S32_PosToHighBit_BE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U32 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the big-endian type pdu LoHi byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)((tmpSignData_U32 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign HiLo byte of value to the big-endian type pdu HiLo byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)((tmpSignData_U32 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] = (uint8)((tmpSignData_U32 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U32_PosToHighBit_LE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U32 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the little-endian type pdu LoHi byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)((tmpSignData_U32 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign HiLo byte of value to the little-endian type pdu HiLo byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)((tmpSignData_U32 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] = (uint8)((tmpSignData_U32 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S32_PosToHighBit_LE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_INIT_FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U32 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the little-endian type pdu LoHi byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)((tmpSignData_U32 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign HiLo byte of value to the little-endian type pdu HiLo byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)((tmpSignData_U32 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] = (uint8)((tmpSignData_U32 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U32_PosToLowhBit_BE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U32 & COM_INIT_FF;
    /* Assign LoHi byte of value to the big-endian type pdu LoHi byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;
    /* Assign HiLo byte of value to the big-endian type pdu HiLo byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> COM_2BYTE_BITLENGTH) & COM_INIT_FF;
    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] &= (uint8)(COM_INIT_FF << (bitSize - COM_3BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] |= (uint8)(tmpSignData_U32 >> COM_3BYTE_BITLENGTH);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S32_PosToLowhBit_BE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U32 & COM_INIT_FF;
    /* Assign LoHi byte of value to the big-endian type pdu LoHi byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;
    /* Assign HiLo byte of value to the big-endian type pdu HiLo byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> COM_2BYTE_BITLENGTH) & COM_INIT_FF;
    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] &= (uint8)(COM_INIT_FF << (bitSize - COM_3BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] |= (uint8)(tmpSignData_U32 >> COM_3BYTE_BITLENGTH);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U32_PosToLowhBit_LE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U32 & COM_INIT_FF;
    /* Assign LoHi byte of value to the little-endian type pdu LoHi byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;
    /* Assign HiLo byte of value to the little-endian type pdu HiLo byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> COM_2BYTE_BITLENGTH) & COM_INIT_FF;
    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] &= (uint8)(COM_INIT_FF << (bitSize - COM_3BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] |= (uint8)(tmpSignData_U32 >> COM_3BYTE_BITLENGTH);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S32_PosToLowhBit_LE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] = (uint8)tmpSignData_U32 & COM_INIT_FF;
    /* Assign LoHi byte of value to the little-endian type pdu LoHi byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> COM_1BYTE_BITLENGTH) & COM_INIT_FF;
    /* Assign HiLo byte of value to the little-endian type pdu HiLo byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> COM_2BYTE_BITLENGTH) & COM_INIT_FF;
    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] &= (uint8)(COM_INIT_FF << (bitSize - COM_3BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] |= (uint8)(tmpSignData_U32 >> COM_3BYTE_BITLENGTH);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U32_PosInMidBit_BE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(COM_INIT_U32FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U32 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the big-endian type pdu LoHi byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Assign HiLo byte of value to the big-endian type pdu HiLo byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_3BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] |= (uint8)((tmpSignData_U32 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S32_PosInMidBit_BE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(COM_INIT_U32FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U32 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the big-endian type pdu LoHi byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Assign HiLo byte of value to the big-endian type pdu HiLo byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_3BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_THREE] |= (uint8)((tmpSignData_U32 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U32_PosInMidBit_LE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(COM_INIT_U32FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U32 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the little-endian type pdu LoHi byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Assign HiLo byte of value to the little-endian type pdu HiLo byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_3BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] |= (uint8)((tmpSignData_U32 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S32_PosInMidBit_LE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(COM_INIT_U32FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U32 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the little-endian type pdu LoHi byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Assign HiLo byte of value to the little-endian type pdu HiLo byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_3BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_THREE] |= (uint8)((tmpSignData_U32 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U32_PosCrossBytes_BE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(COM_INIT_U32FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U32 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the big-endian type pdu LoHi byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Assign mid byte of value to the big-endian type pdu mid byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Assign HiLo byte of value to the big-endian type pdu HiLo byte. */
    destBuffer[bytePos - COM_INIT_THREE] = (uint8)(tmpSignData_U32 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_FOUR] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_4BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_FOUR] |= (uint8)((tmpSignData_U32 >> (COM_4BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S32_PosCrossBytes_BE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the big-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(COM_INIT_U32FF << bitPos));
    /* Assign low byte of value to the big-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U32 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the big-endian type pdu LoHi byte. */
    destBuffer[bytePos - COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Assign mid byte of value to the big-endian type pdu mid byte. */
    destBuffer[bytePos - COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Assign HiLo byte of value to the big-endian type pdu HiLo byte. */
    destBuffer[bytePos - COM_INIT_THREE] = (uint8)(tmpSignData_U32 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Clear valid bits of the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_FOUR] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_4BYTE_BITLENGTH));
    /* Assign high byte of value to the big-endian type pdu high byte. */
    destBuffer[bytePos - COM_INIT_FOUR] |= (uint8)((tmpSignData_U32 >> (COM_4BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U32_PosCrossBytes_LE
*
* Explanation: Assign a unsigned long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U32_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(COM_INIT_U32FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U32 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the little-endian type pdu LoHi byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Assign mid byte of value to the little-endian type pdu mid byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Assign HiLo byte of value to the little-endian type pdu HiLo byte. */
    destBuffer[bytePos + COM_INIT_THREE] = (uint8)(tmpSignData_U32 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_FOUR] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_4BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_FOUR] |= (uint8)((tmpSignData_U32 >> (COM_4BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S32_PosCrossBytes_LE
*
* Explanation: Assign a signed long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S32_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 tmpSignData_U32 = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                                    srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigBitLengthType bitSize = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_U32 &= (uint32)(~(COM_INIT_U32FF << bitSize));
    /* Clear valid bits of the little-endian type pdu low byte. */
    destBuffer[bytePos] &= (uint8)(~(COM_INIT_U32FF << bitPos));
    /* Assign low byte of value to the little-endian type pdu low byte. */
    destBuffer[bytePos] |= (uint8)((tmpSignData_U32 << bitPos) & COM_INIT_FF);
    /* Assign LoHi byte of value to the little-endian type pdu LoHi byte. */
    destBuffer[bytePos + COM_INIT_ONE] = (uint8)(tmpSignData_U32 >> (COM_1BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Assign mid byte of value to the little-endian type pdu mid byte. */
    destBuffer[bytePos + COM_INIT_TWO] = (uint8)(tmpSignData_U32 >> (COM_2BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Assign HiLo byte of value to the little-endian type pdu HiLo byte. */
    destBuffer[bytePos + COM_INIT_THREE] = (uint8)(tmpSignData_U32 >> (COM_3BYTE_BITLENGTH - bitPos)) & COM_INIT_FF;
    /* Clear valid bits of the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_FOUR] &= (uint8)(COM_INIT_FF << (bitPos + bitSize - COM_4BYTE_BITLENGTH));
    /* Assign high byte of value to the little-endian type pdu high byte. */
    destBuffer[bytePos + COM_INIT_FOUR] |= (uint8)((tmpSignData_U32 >> (COM_4BYTE_BITLENGTH - bitPos)) & COM_INIT_FF);

}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_BOOLEAN
*
* Explanation: Assign a bool value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_BOOLEAN
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    boolean tmpSignData_BOOL = (uint8)(srcBuffer[COM_INIT_ZERO]);
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;

    /* Clear invalid bits of signal value. */
    tmpSignData_BOOL &= COM_OPERAND_ONE;
    /* Clear valid bits of pdu. */
    destBuffer[bytePos] &= (uint8)(~(uint8)(COM_OPERAND_ONE << bitPos));
    /* Assign valid value to pdu. */
    destBuffer[bytePos] |= (uint8)((uint8)(tmpSignData_BOOL << bitPos) & COM_INIT_FF);
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U64_BE
*
* Explanation: Assign a unsigned long long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U64_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint64 sigValueBuf = Com_Make64Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                        srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE], srcBuffer[COM_INIT_FOUR],
                        srcBuffer[COM_INIT_FIVE], srcBuffer[COM_INIT_SIX], srcBuffer[COM_INIT_SEVEN]);
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigByteLengthType sigByteLength = signalBaseRef->sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit = signalBaseRef->sigStartBit;
    Com_SigStartByteType sigStartByte = signalBaseRef->sigStartByte;
    uint64 sigValue = sigValueBuf;
    uint64 clearBit = COM_INIT_U64FF;
    uint64 clearBitLow =  COM_INIT_U64FF;

    sigValue = (sigValue & (COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)));

    if( COM_8BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        sigValue = sigValue >> (COM_1BYTE_BITLENGTH - sigStartBit);
        /* High 4 Byte clearBit. */
        clearBit = ~((COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)) >> (COM_1BYTE_BITLENGTH - sigStartBit));
        /* Low 1 Byte Data. */
        sigValueBuf = sigValueBuf << sigStartBit;
        /* Low 1 Byte clearBit. */
        clearBitLow = ~((uint64)COM_INIT_FF  << sigStartBit);
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_8BYTELENGTH; sigByteLengthIndex++ )
        {
            /* Big endian. */
            destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] =
                (uint8)((uint64)destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] =
                (uint8)((uint64)destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
        }
        destBuffer[sigStartByte] = (uint8)((uint64)destBuffer[sigStartByte] & clearBitLow);
        destBuffer[sigStartByte] = (uint8)((uint64)destBuffer[sigStartByte] | sigValueBuf);
    }
    else
    {
        sigValue = sigValue << (sigStartBit % COM_1BYTE_BITLENGTH);
        clearBit = ~((COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)) << (sigStartBit % COM_1BYTE_BITLENGTH));
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength; sigByteLengthIndex++ )
        {
            /* Big endian. */
            destBuffer[sigStartByte - sigByteLengthIndex] =
                (uint8)((uint64)destBuffer[sigStartByte - sigByteLengthIndex] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte - sigByteLengthIndex] =
                (uint8)((uint64)destBuffer[sigStartByte - sigByteLengthIndex] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S64_BE
*
* Explanation: Assign a long long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S64_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint64 sigValueBuf = Com_Make64Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                        srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE], srcBuffer[COM_INIT_FOUR],
                        srcBuffer[COM_INIT_FIVE], srcBuffer[COM_INIT_SIX], srcBuffer[COM_INIT_SEVEN]);
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigByteLengthType sigByteLength = signalBaseRef->sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit = signalBaseRef->sigStartBit;
    Com_SigStartByteType sigStartByte = signalBaseRef->sigStartByte;
    uint64 sigValue = sigValueBuf;
    uint64 clearBit = COM_INIT_U64FF;
    uint64 clearBitLow =  COM_INIT_U64FF;

    sigValue = (sigValue & (COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)));

    if( COM_8BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        sigValue = sigValue >> (COM_1BYTE_BITLENGTH - sigStartBit);
        /* High 4 Byte clearBit. */
        clearBit = ~((COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)) >> (COM_1BYTE_BITLENGTH - sigStartBit));
        /* Low 1 Byte Data. */
        sigValueBuf = sigValueBuf << sigStartBit;
        /* Low 1 Byte clearBit. */
        clearBitLow = ~((uint64)COM_INIT_FF  << sigStartBit);
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_8BYTELENGTH; sigByteLengthIndex++ )
        {
            /* Big endian. */
            destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] =
                (uint8)((uint64)destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] =
                (uint8)((uint64)destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));

        }
        destBuffer[sigStartByte] = (uint8)((uint64)destBuffer[sigStartByte] & clearBitLow);
        destBuffer[sigStartByte] = (uint8)((uint64)destBuffer[sigStartByte] | sigValueBuf);
    }
    else
    {
        sigValue = sigValue << (sigStartBit % COM_1BYTE_BITLENGTH);
        clearBit = ~((COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)) << (sigStartBit % COM_1BYTE_BITLENGTH));
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength; sigByteLengthIndex++ )
        {
            /* Big endian. */
            destBuffer[sigStartByte - sigByteLengthIndex] =
                (uint8)((uint64)destBuffer[sigStartByte - sigByteLengthIndex] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte - sigByteLengthIndex] =
                (uint8)((uint64)destBuffer[sigStartByte - sigByteLengthIndex] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U64_LE
*
* Explanation: Assign a unsigned long long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U64_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint64 sigValueBuf = Com_Make64Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                        srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE], srcBuffer[COM_INIT_FOUR],
                        srcBuffer[COM_INIT_FIVE], srcBuffer[COM_INIT_SIX], srcBuffer[COM_INIT_SEVEN]);
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigByteLengthType sigByteLength = signalBaseRef->sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit = signalBaseRef->sigStartBit;
    Com_SigStartByteType sigStartByte = signalBaseRef->sigStartByte;
    uint64 sigValue = sigValueBuf;
    uint64 clearBit = COM_INIT_U64FF;
    uint64 clearBitLow =  COM_INIT_U64FF;

    sigValue = (sigValue & (COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)));

    if( COM_8BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        sigValue = sigValue >> (COM_1BYTE_BITLENGTH - sigStartBit);
        /* High 4 Byte clearBit. */
        clearBit = ~((COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)) >> (COM_1BYTE_BITLENGTH - sigStartBit));
        /* Low 1 Byte Data. */
        sigValueBuf = sigValueBuf << sigStartBit;
        /* Low 1 Byte clearBit. */
        clearBitLow = ~((uint64)COM_INIT_FF  << sigStartBit);
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_8BYTELENGTH; sigByteLengthIndex++ )
        {
            /* Little endian */
            destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] =
                (uint8)((uint64)destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] =
                (uint8)((uint64)destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
        }
        destBuffer[sigStartByte] = (uint8)((uint64)destBuffer[sigStartByte] & clearBitLow);
        destBuffer[sigStartByte] = (uint8)((uint64)destBuffer[sigStartByte] | sigValueBuf);
    }
    else
    {
        sigValue = sigValue << (sigStartBit % COM_1BYTE_BITLENGTH);
        clearBit = ~((COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)) << (sigStartBit % COM_1BYTE_BITLENGTH));
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength; sigByteLengthIndex++ )
        {
            /* Little endian */
            destBuffer[sigStartByte + sigByteLengthIndex] =
                (uint8)((uint64)destBuffer[sigStartByte + sigByteLengthIndex] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte + sigByteLengthIndex] =
                (uint8)((uint64)destBuffer[sigStartByte + sigByteLengthIndex] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_S64_LE
*
* Explanation: Assign a long long value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_S64_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint64 sigValueBuf = Com_Make64Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                        srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE], srcBuffer[COM_INIT_FOUR],
                        srcBuffer[COM_INIT_FIVE], srcBuffer[COM_INIT_SIX], srcBuffer[COM_INIT_SEVEN]);
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigByteLengthType sigByteLength = signalBaseRef->sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit = signalBaseRef->sigStartBit;
    Com_SigStartByteType sigStartByte = signalBaseRef->sigStartByte;
    uint64 sigValue = sigValueBuf;
    uint64 clearBit = COM_INIT_U64FF;
    uint64 clearBitLow =  COM_INIT_U64FF;

    sigValue = (sigValue & (COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)));

    if( COM_8BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        sigValue = sigValue >> (COM_1BYTE_BITLENGTH - sigStartBit);
        /* High 4 Byte clearBit. */
        clearBit = ~((COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)) >> (COM_1BYTE_BITLENGTH - sigStartBit));
        /* Low 1 Byte Data. */
        sigValueBuf = sigValueBuf << sigStartBit;
        /* Low 1 Byte clearBit. */
        clearBitLow = ~((uint64)COM_INIT_FF  << sigStartBit);
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_8BYTELENGTH; sigByteLengthIndex++ )
        {
            /* Little endian */
            destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] =
                (uint8)((uint64)destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] =
                (uint8)((uint64)destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
        }
        destBuffer[sigStartByte] = (uint8)((uint64)destBuffer[sigStartByte] & clearBitLow);
        destBuffer[sigStartByte] = (uint8)((uint64)destBuffer[sigStartByte] | sigValueBuf);
    }
    else
    {
        sigValue = sigValue << (sigStartBit % COM_1BYTE_BITLENGTH);
        clearBit = ~((COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)) << (sigStartBit % COM_1BYTE_BITLENGTH));
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength; sigByteLengthIndex++ )
        {
            /* Little endian */
            destBuffer[sigStartByte + sigByteLengthIndex] =
                (uint8)((uint64)destBuffer[sigStartByte + sigByteLengthIndex] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte + sigByteLengthIndex] =
                (uint8)((uint64)destBuffer[sigStartByte + sigByteLengthIndex] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_F32_BE
*
* Explanation: Assign a float value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_F32_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 sigValueBuf = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                               srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigByteLengthType sigByteLength = signalBaseRef->sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit = signalBaseRef->sigStartBit;
    Com_SigStartByteType sigStartByte = signalBaseRef->sigStartByte;
    uint32 sigValue = sigValueBuf;
    uint32 clearBit = COM_INIT_U32FF;
    uint32 clearBitLow =  COM_INIT_U32FF;

    sigValue = (sigValue & (COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength)));

    if( COM_4BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        sigValue = sigValue >> (COM_1BYTE_BITLENGTH - sigStartBit);
        /* High 4 Byte clearBit. */
        clearBit = ~((COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength)) >> (COM_1BYTE_BITLENGTH - sigStartBit));
        /* Low 1 Byte Data. */
        sigValueBuf = sigValueBuf << sigStartBit;
        /* Low 1 Byte clearBit. */
        clearBitLow = ~((uint32)COM_INIT_FF  << (uint32)sigStartBit);
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_4BYTELENGTH; sigByteLengthIndex++ )
        {
            /* Big endian. */
            destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] =
                (uint8)((uint32)destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] =
                (uint8)((uint32)destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
        }
        destBuffer[sigStartByte] = (uint8)((uint32)destBuffer[sigStartByte] & clearBitLow);
        destBuffer[sigStartByte] = (uint8)((uint32)destBuffer[sigStartByte] | sigValueBuf);
    }
    else
    {
        sigValue = sigValue << (sigStartBit % COM_1BYTE_BITLENGTH);
        clearBit = ~((COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength)) << (sigStartBit % COM_1BYTE_BITLENGTH));
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength; sigByteLengthIndex++ )
        {
            /* Big endian. */
            destBuffer[sigStartByte - sigByteLengthIndex] =
                (uint8)((uint32)destBuffer[sigStartByte - sigByteLengthIndex] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte - sigByteLengthIndex] =
                (uint8)((uint32)destBuffer[sigStartByte - sigByteLengthIndex] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_F32_LE
*
* Explanation: Assign a float value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_F32_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 sigValueBuf = Com_Make32Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                               srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE]);
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigByteLengthType sigByteLength = signalBaseRef->sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit = signalBaseRef->sigStartBit;
    Com_SigStartByteType sigStartByte = signalBaseRef->sigStartByte;
    uint32 sigValue = sigValueBuf;
    uint32 clearBit = COM_INIT_U32FF;
    uint32 clearBitLow =  COM_INIT_U32FF;

    sigValue = (sigValue & (COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength)));

    if( COM_4BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        sigValue = sigValue >> (COM_1BYTE_BITLENGTH - sigStartBit);
        /* High 4 Byte clearBit. */
        clearBit = ~((COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength)) >> (COM_1BYTE_BITLENGTH - sigStartBit));
        /* Low 1 Byte Data. */
        sigValueBuf = sigValueBuf << sigStartBit;
        /* Low 1 Byte clearBit. */
        clearBitLow = ~((uint32)COM_INIT_FF  << (uint32)sigStartBit);
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_4BYTELENGTH; sigByteLengthIndex++ )
        {
            /* Little endian */
            destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] =
                (uint8)((uint32)destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] =
                (uint8)((uint32)destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
        }
        destBuffer[sigStartByte] = (uint8)((uint32)destBuffer[sigStartByte] & clearBitLow);
        destBuffer[sigStartByte] = (uint8)((uint32)destBuffer[sigStartByte] | sigValueBuf);
    }
    else
    {
        sigValue = sigValue << (sigStartBit % COM_1BYTE_BITLENGTH);
        clearBit = ~((COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength)) << (sigStartBit % COM_1BYTE_BITLENGTH));
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength; sigByteLengthIndex++ )
        {
            /* Little endian */
            destBuffer[sigStartByte + sigByteLengthIndex] =
                (uint8)((uint32)destBuffer[sigStartByte + sigByteLengthIndex] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte + sigByteLengthIndex] =
                (uint8)((uint32)destBuffer[sigStartByte + sigByteLengthIndex] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_F64_BE
*
* Explanation: Assign a double value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_F64_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint64 sigValueBuf = Com_Make64Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                        srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE], srcBuffer[COM_INIT_FOUR],
                        srcBuffer[COM_INIT_FIVE], srcBuffer[COM_INIT_SIX], srcBuffer[COM_INIT_SEVEN]);
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigByteLengthType sigByteLength = signalBaseRef->sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit = signalBaseRef->sigStartBit;
    Com_SigStartByteType sigStartByte = signalBaseRef->sigStartByte;
    uint64 sigValue = sigValueBuf;
    uint64 clearBit = COM_INIT_U64FF;
    uint64 clearBitLow =  COM_INIT_U64FF;

    sigValue = (sigValue & (COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)));

    if( COM_8BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        sigValue = sigValue >> (COM_1BYTE_BITLENGTH - sigStartBit);
        /* High 4 Byte clearBit. */
        clearBit = ~((COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)) >> (COM_1BYTE_BITLENGTH - sigStartBit));
        /* Low 1 Byte Data. */
        sigValueBuf = sigValueBuf << sigStartBit;
        /* Low 1 Byte clearBit. */
        clearBitLow = ~((uint64)COM_INIT_FF  << sigStartBit);
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_8BYTELENGTH; sigByteLengthIndex++ )
        {
            /* Big endian. */
            destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] =
                (uint8)((uint64)destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] =
                (uint8)((uint64)destBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));

        }
        destBuffer[sigStartByte] = (uint8)((uint64)destBuffer[sigStartByte] & clearBitLow);
        destBuffer[sigStartByte] = (uint8)((uint64)destBuffer[sigStartByte] | sigValueBuf);
    }
    else
    {
        sigValue = sigValue << (sigStartBit % COM_1BYTE_BITLENGTH);
        clearBit = ~((COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)) << (sigStartBit % COM_1BYTE_BITLENGTH));
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength; sigByteLengthIndex++ )
        {
            /* Big endian. */
            destBuffer[sigStartByte - sigByteLengthIndex] =
                (uint8)((uint64)destBuffer[sigStartByte - sigByteLengthIndex] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte - sigByteLengthIndex] =
                (uint8)((uint64)destBuffer[sigStartByte - sigByteLengthIndex] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_F64_LE
*
* Explanation: Assign a double value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_F64_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint64 sigValueBuf = Com_Make64Bit(srcBuffer[COM_INIT_ZERO], srcBuffer[COM_INIT_ONE],
                        srcBuffer[COM_INIT_TWO], srcBuffer[COM_INIT_THREE], srcBuffer[COM_INIT_FOUR],
                        srcBuffer[COM_INIT_FIVE], srcBuffer[COM_INIT_SIX], srcBuffer[COM_INIT_SEVEN]);
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigByteLengthType sigByteLength = signalBaseRef->sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit = signalBaseRef->sigStartBit;
    Com_SigStartByteType sigStartByte = signalBaseRef->sigStartByte;
    uint64 sigValue = sigValueBuf;
    uint64 clearBit = COM_INIT_U64FF;
    uint64 clearBitLow =  COM_INIT_U64FF;

    sigValue = (sigValue & (COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)));

    if( COM_8BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        sigValue = sigValue >> (COM_1BYTE_BITLENGTH - sigStartBit);
        /* High 4 Byte clearBit. */
        clearBit = ~((COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)) >> (COM_1BYTE_BITLENGTH - sigStartBit));
        /* Low 1 Byte Data. */
        sigValueBuf = sigValueBuf << sigStartBit;
        /* Low 1 Byte clearBit. */
        clearBitLow = ~((uint64)COM_INIT_FF  << sigStartBit);
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_8BYTELENGTH; sigByteLengthIndex++ )
        {
            /* Little endian */
            destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] =
                (uint8)((uint64)destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] =
                (uint8)((uint64)destBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
        }
        destBuffer[sigStartByte] = (uint8)((uint64)destBuffer[sigStartByte] & clearBitLow);
        destBuffer[sigStartByte] = (uint8)((uint64)destBuffer[sigStartByte] | sigValueBuf);
    }
    else
    {
        sigValue = sigValue << (sigStartBit % COM_1BYTE_BITLENGTH);
        clearBit = ~((COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigBitLength)) << (sigStartBit % COM_1BYTE_BITLENGTH));
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength; sigByteLengthIndex++ )
        {
            /* Little endian */
            destBuffer[sigStartByte + sigByteLengthIndex] =
                (uint8)((uint64)destBuffer[sigStartByte + sigByteLengthIndex] & (clearBit >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
            destBuffer[sigStartByte + sigByteLengthIndex] =
                (uint8)((uint64)destBuffer[sigStartByte + sigByteLengthIndex] | (sigValue >> (COM_1BYTE_BITLENGTH * sigByteLengthIndex)));
        }
    }
}

/*
********************************************************************************
* Function Name: Com_TxAssignSignal_U8N
*
* Explanation: Assign a Uint8_N value to a pdu.
*
* param: srcValueBuf: Source data.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_TxAssignSignal_U8N
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 index = COM_INIT_ZERO;
    Com_SigStartByteType sigLengthIndex;

    /* uint8_N signal write data to a pdu. */
    for( sigLengthIndex = (uint8)signalBaseRef->sigStartByte;
        sigLengthIndex < ((uint8)signalBaseRef->sigStartByte + signalBaseRef->sigByteLength); sigLengthIndex++ )  /* PRQA S 1891 */ /* NSCA_QAC_Com_Rule10.7 */
    {
        destBuffer[sigLengthIndex] = srcBuffer[index];
        index++;
    }
}

#define COM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */


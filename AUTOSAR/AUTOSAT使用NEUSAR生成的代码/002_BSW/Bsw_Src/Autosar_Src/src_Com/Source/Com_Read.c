/*
********************************************************************************
*
* File name: Com_Read.c
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
* Author/Date: LuQ/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 1.3
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 1.4
* Author/Date: LuQ/2025.06.18
* Change: Modify the type of the forced conversion in the parsing functions
*         Com_RxParseSignal_U8_PosCrossBytes_BE, Com_RxParseSignal_S8_PosCrossBytes_BE,
*         Com_RxParseSignal_U8_PosCrossBytes_LE and Com_RxParseSignal_S8_PosCrossBytes_LE
*         to prevent data truncation.
* Cause: Bugfix
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
#include "Com_Read.h"

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
static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */


static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */
static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */


static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */


static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);  /* PRQA S 0779 */ /* NSCA_QAC_Common_Rule5.2 */

static FUNC(void, COM_CODE) Com_RxParseSignal_BOOLEAN
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U64_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S64_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U64_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_S64_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_F32_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_F32_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_F64_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_F64_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);

static FUNC(void, COM_CODE) Com_RxParseSignal_U8N
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

/* Parse received message data to signal function table. */
CONST(Com_RxParseSignal_Func, COM_APPL_CONST) Com_RxParseSignalFuncTable[COM_RXPARSESIGNAL_FUNC_NUM] =
{
    Com_RxParseSignal_BOOLEAN,                                      /* Parse bool type signal. */
    Com_RxParseSignal_U8_PosFullByte_BE,                            /* Parse big-endian uint8 type signal. */
    Com_RxParseSignal_U8_PosToHighBit_BE,                           /* Parse big-endian uint8 type signal. */
    Com_RxParseSignal_U8_PosToLowhBit_BE,                           /* Parse big-endian uint8 type signal. */
    Com_RxParseSignal_U8_PosInMidBit_BE,                            /* Parse big-endian uint8 type signal. */
    Com_RxParseSignal_U8_PosCrossBytes_BE,                          /* Parse big-endian uint8 type signal. */
    Com_RxParseSignal_U16_PosFullByte_BE,                           /* Parse big-endian uint16 type signal. */
    Com_RxParseSignal_U16_PosToHighBit_BE,                          /* Parse big-endian uint16 type signal. */
    Com_RxParseSignal_U16_PosToLowhBit_BE,                          /* Parse big-endian uint16 type signal. */
    Com_RxParseSignal_U16_PosInMidBit_BE,                           /* Parse big-endian uint16 type signal. */
    Com_RxParseSignal_U16_PosCrossBytes_BE,                         /* Parse big-endian uint16 type signal. */
    Com_RxParseSignal_U24_PosFullByte_BE,                           /* Parse big-endian uint32 type signal. */
    Com_RxParseSignal_U24_PosToHighBit_BE,                          /* Parse big-endian uint32 type signal. */
    Com_RxParseSignal_U24_PosToLowhBit_BE,                          /* Parse big-endian uint32 type signal. */
    Com_RxParseSignal_U24_PosInMidBit_BE,                           /* Parse big-endian uint32 type signal. */
    Com_RxParseSignal_U24_PosCrossBytes_BE,                         /* Parse big-endian uint32 type signal. */
    Com_RxParseSignal_U32_PosFullByte_BE,                           /* Parse big-endian uint32 type signal. */
    Com_RxParseSignal_U32_PosToHighBit_BE,                          /* Parse big-endian uint32 type signal. */
    Com_RxParseSignal_U32_PosToLowhBit_BE,                          /* Parse big-endian uint32 type signal. */
    Com_RxParseSignal_U32_PosInMidBit_BE,                           /* Parse big-endian uint32 type signal. */
    Com_RxParseSignal_U32_PosCrossBytes_BE,                         /* Parse big-endian uint32 type signal. */
    Com_RxParseSignal_U64_BE,                                       /* Parse big-endian uint64 type signal. */
    Com_RxParseSignal_S8_PosFullByte_BE,                            /* Parse big-endian sint8 type signal. */
    Com_RxParseSignal_S8_PosToHighBit_BE,                           /* Parse big-endian sint8 type signal. */
    Com_RxParseSignal_S8_PosToLowhBit_BE,                           /* Parse big-endian sint8 type signal. */
    Com_RxParseSignal_S8_PosInMidBit_BE,                            /* Parse big-endian sint8 type signal. */
    Com_RxParseSignal_S8_PosCrossBytes_BE,                          /* Parse big-endian sint8 type signal. */
    Com_RxParseSignal_S16_PosFullByte_BE,                           /* Parse big-endian sint16 type signal. */
    Com_RxParseSignal_S16_PosToHighBit_BE,                          /* Parse big-endian sint16 type signal. */
    Com_RxParseSignal_S16_PosToLowhBit_BE,                          /* Parse big-endian sint16 type signal. */
    Com_RxParseSignal_S16_PosInMidBit_BE,                           /* Parse big-endian sint16 type signal. */
    Com_RxParseSignal_S16_PosCrossBytes_BE,                         /* Parse big-endian sint16 type signal. */
    Com_RxParseSignal_S24_PosFullByte_BE,                           /* Parse big-endian sint32 type signal. */
    Com_RxParseSignal_S24_PosToHighBit_BE,                          /* Parse big-endian sint32 type signal. */
    Com_RxParseSignal_S24_PosToLowhBit_BE,                          /* Parse big-endian sint32 type signal. */
    Com_RxParseSignal_S24_PosInMidBit_BE,                           /* Parse big-endian sint32 type signal. */
    Com_RxParseSignal_S24_PosCrossBytes_BE,                         /* Parse big-endian sint32 type signal. */
    Com_RxParseSignal_S32_PosFullByte_BE,                           /* Parse big-endian sint32 type signal. */
    Com_RxParseSignal_S32_PosToHighBit_BE,                          /* Parse big-endian sint32 type signal. */
    Com_RxParseSignal_S32_PosToLowhBit_BE,                          /* Parse big-endian sint32 type signal. */
    Com_RxParseSignal_S32_PosInMidBit_BE,                           /* Parse big-endian sint32 type signal. */
    Com_RxParseSignal_S32_PosCrossBytes_BE,                         /* Parse big-endian sint32 type signal. */
    Com_RxParseSignal_S64_BE,                                       /* Parse big-endian sint64 type signal. */
    Com_RxParseSignal_F32_BE,                                       /* Parse big-endian float32 type signal. */
    Com_RxParseSignal_F64_BE,                                       /* Parse big-endian float64 type signal. */
    Com_RxParseSignal_U8_PosFullByte_LE,                            /* Parse little-endian uint8 type signal. */
    Com_RxParseSignal_U8_PosToHighBit_LE,                           /* Parse little-endian uint8 type signal. */
    Com_RxParseSignal_U8_PosToLowhBit_LE,                           /* Parse little-endian uint8 type signal. */
    Com_RxParseSignal_U8_PosInMidBit_LE,                            /* Parse little-endian uint8 type signal. */
    Com_RxParseSignal_U8_PosCrossBytes_LE,                          /* Parse little-endian uint8 type signal. */
    Com_RxParseSignal_U16_PosFullByte_LE,                           /* Parse little-endian uint16 type signal. */
    Com_RxParseSignal_U16_PosToHighBit_LE,                          /* Parse little-endian uint16 type signal. */
    Com_RxParseSignal_U16_PosToLowhBit_LE,                          /* Parse little-endian uint16 type signal. */
    Com_RxParseSignal_U16_PosInMidBit_LE,                           /* Parse little-endian uint16 type signal. */
    Com_RxParseSignal_U16_PosCrossBytes_LE,                         /* Parse little-endian uint16 type signal. */
    Com_RxParseSignal_U24_PosFullByte_LE,                           /* Parse little-endian uint32 type signal. */
    Com_RxParseSignal_U24_PosToHighBit_LE,                          /* Parse little-endian uint32 type signal. */
    Com_RxParseSignal_U24_PosToLowhBit_LE,                          /* Parse little-endian uint32 type signal. */
    Com_RxParseSignal_U24_PosInMidBit_LE,                           /* Parse little-endian uint32 type signal. */
    Com_RxParseSignal_U24_PosCrossBytes_LE,                         /* Parse little-endian uint32 type signal. */
    Com_RxParseSignal_U32_PosFullByte_LE,                           /* Parse little-endian uint32 type signal. */
    Com_RxParseSignal_U32_PosToHighBit_LE,                          /* Parse little-endian uint32 type signal. */
    Com_RxParseSignal_U32_PosToLowhBit_LE,                          /* Parse little-endian uint32 type signal. */
    Com_RxParseSignal_U32_PosInMidBit_LE,                           /* Parse little-endian uint32 type signal. */
    Com_RxParseSignal_U32_PosCrossBytes_LE,                         /* Parse little-endian uint32 type signal. */
    Com_RxParseSignal_U64_LE,                                       /* Parse little-endian uint64 type signal. */
    Com_RxParseSignal_S8_PosFullByte_LE,                            /* Parse little-endian sint8 type signal. */
    Com_RxParseSignal_S8_PosToHighBit_LE,                           /* Parse little-endian sint8 type signal. */
    Com_RxParseSignal_S8_PosToLowhBit_LE,                           /* Parse little-endian sint8 type signal. */
    Com_RxParseSignal_S8_PosInMidBit_LE,                            /* Parse little-endian sint8 type signal. */
    Com_RxParseSignal_S8_PosCrossBytes_LE,                          /* Parse little-endian sint8 type signal. */
    Com_RxParseSignal_S16_PosFullByte_LE,                           /* Parse little-endian sint16 type signal. */
    Com_RxParseSignal_S16_PosToHighBit_LE,                          /* Parse little-endian sint16 type signal. */
    Com_RxParseSignal_S16_PosToLowhBit_LE,                          /* Parse little-endian sint16 type signal. */
    Com_RxParseSignal_S16_PosInMidBit_LE,                           /* Parse little-endian sint16 type signal. */
    Com_RxParseSignal_S16_PosCrossBytes_LE,                         /* Parse little-endian sint16 type signal. */
    Com_RxParseSignal_S24_PosFullByte_LE,                           /* Parse little-endian sint32 type signal. */
    Com_RxParseSignal_S24_PosToHighBit_LE,                          /* Parse little-endian sint32 type signal. */
    Com_RxParseSignal_S24_PosToLowhBit_LE,                          /* Parse little-endian sint32 type signal. */
    Com_RxParseSignal_S24_PosInMidBit_LE,                           /* Parse little-endian sint32 type signal. */
    Com_RxParseSignal_S24_PosCrossBytes_LE,                         /* Parse little-endian sint32 type signal. */
    Com_RxParseSignal_S32_PosFullByte_LE,                           /* Parse little-endian sint32 type signal. */
    Com_RxParseSignal_S32_PosToHighBit_LE,                          /* Parse little-endian sint32 type signal. */
    Com_RxParseSignal_S32_PosToLowhBit_LE,                          /* Parse little-endian sint32 type signal. */
    Com_RxParseSignal_S32_PosInMidBit_LE,                           /* Parse little-endian sint32 type signal. */
    Com_RxParseSignal_S32_PosCrossBytes_LE,                         /* Parse little-endian sint32 type signal. */
    Com_RxParseSignal_S64_LE,                                       /* Parse little-endian sint64 type signal. */
    Com_RxParseSignal_F32_LE,                                       /* Parse little-endian float32 type signal. */
    Com_RxParseSignal_F64_LE,                                       /* Parse little-endian float64 type signal. */
    Com_RxParseSignal_U8N                                           /* Parse little-endian Uint8_N type signal. */
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
* Function Name: Com_RxParseSignal_U8_PosFullByte_BE
*
* Explanation: Parse received message data to unsigned char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8;

    /* Get valid data of the received message data. */
    tmpSignData_U8 = srcBuffer[signalBaseRef->sigStartByte];
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = tmpSignData_U8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S8_PosFullByte_BE
*
* Explanation: Parse received message data to signed char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint8 tmpSignData_S8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    /* Get valid data of the received message data. */
    uint8 unsignVal = srcBuffer[signalBaseRef->sigStartByte];

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S8 = (sint8)((uint8)(unsignVal | (uint8)(COM_INIT_FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S8= (sint8)unsignVal;
    }

    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = (uint8)tmpSignData_S8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U8_PosFullByte_LE
*
* Explanation: Parse received message data to unsigned char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8;

    /* Get valid data of the received message data. */
    tmpSignData_U8 = srcBuffer[signalBaseRef->sigStartByte];
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = tmpSignData_U8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S8_PosFullByte_LE
*
* Explanation: Parse received message data to signed char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint8 tmpSignData_S8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    /* Get valid data of the received message data. */
    uint8 unsignVal = srcBuffer[signalBaseRef->sigStartByte];

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S8 = (sint8)((uint8)(unsignVal | (uint8)(COM_INIT_FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S8= (sint8)unsignVal;
    }
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = (uint8)tmpSignData_S8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U8_PosToHighBit_BE
*
* Explanation: Parse received message data to unsigned char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Get valid data of the received message data. */
    tmpSignData_U8 = (uint8)(srcBuffer[bytePos] >> (COM_1BYTE_BITLENGTH - sigBitLength));
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = tmpSignData_U8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S8_PosToHighBit_BE
*
* Explanation: Parse received message data to signed char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint8 tmpSignData_S8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    /* Get valid data of the received message data. */
    uint8 unsignVal = (uint8)(srcBuffer[bytePos] >> (COM_1BYTE_BITLENGTH - sigBitLength));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S8 = (sint8)((uint8)(unsignVal | (uint8)(COM_INIT_FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S8= (sint8)unsignVal;
    }
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = (uint8)tmpSignData_S8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U8_PosToHighBit_LE
*
* Explanation: Parse received message data to unsigned char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;

    /* Get valid data of the received message data. */
    tmpSignData_U8 = (uint8)(srcBuffer[bytePos] >> (COM_1BYTE_BITLENGTH - sigBitLength));
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = (uint8)tmpSignData_U8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S8_PosToHighBit_LE
*
* Explanation: Parse received message data to signed char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint8 tmpSignData_S8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint8 unsignVal = (uint8)(srcBuffer[bytePos] >> (COM_1BYTE_BITLENGTH - sigBitLength));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S8 = (sint8)((uint8)(unsignVal | (uint8)(COM_INIT_FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S8= (sint8)unsignVal;
    }
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = (uint8)tmpSignData_S8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U8_PosToLowhBit_BE
*
* Explanation: Parse received message data to unsigned char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint8 tmpVal = srcBuffer[bytePos];
    uint8 mask = (uint8)(COM_INIT_FF >> (COM_1BYTE_BITLENGTH - sigBitLength));

    /* Get valid data of the received message data. */
    tmpSignData_U8 = (uint8)(tmpVal & mask);
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = tmpSignData_U8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S8_PosToLowhBit_BE
*
* Explanation: Parse received message data to signed char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint8 tmpSignData_S8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint8 tmpVal = srcBuffer[bytePos];
    uint8 mask = (uint8)(COM_INIT_FF >> (COM_1BYTE_BITLENGTH - sigBitLength));
    uint8 unsignVal = (uint8)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S8 = (sint8)((uint8)(unsignVal | (uint8)(COM_INIT_FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S8= (sint8)unsignVal;
    }
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = (uint8)tmpSignData_S8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U8_PosToLowhBit_LE
*
* Explanation: Parse received message data to unsigned char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint8 tmpVal = srcBuffer[bytePos];
    uint8 mask = (uint8)(COM_INIT_FF >> (COM_1BYTE_BITLENGTH - sigBitLength));

    /* Get valid data of the received message data. */
    tmpSignData_U8 = (uint8)(tmpVal & mask);
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = tmpSignData_U8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S8_PosToLowhBit_LE
*
* Explanation: Parse received message data to signed char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint8 tmpSignData_S8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint8 tmpVal = srcBuffer[bytePos];
    uint8 mask = (uint8)(COM_INIT_FF >> (COM_1BYTE_BITLENGTH - sigBitLength));
    /* Get valid data of the received message data. */
    uint8 unsignVal = (uint8)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S8 = (sint8)((uint8)(unsignVal | (uint8)(COM_INIT_FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S8= (sint8)unsignVal;
    }
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = (uint8)tmpSignData_S8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U8_PosInMidBit_BE
*
* Explanation: Parse received message data to unsigned char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint8 mask = (uint8)(COM_INIT_FF >> (COM_1BYTE_BITLENGTH - sigBitLength));
    /* Get data of the received message data. */
    uint8 tmpVal = srcBuffer[bytePos];

    /* Remove invalid low bits data. */
    tmpVal = (uint8)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    tmpSignData_U8 = (uint8)(tmpVal & mask);
    destBuffer[COM_INIT_ZERO] = tmpSignData_U8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S8_PosInMidBit_BE
*
* Explanation: Parse received message data to signed char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint8 tmpSignData_S8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint8 mask = (uint8)(COM_INIT_FF >> (COM_1BYTE_BITLENGTH - sigBitLength));
    /* Get data of the received message data. */
    uint8 tmpVal = srcBuffer[bytePos];

    /* Remove invalid low bits data. */
    tmpVal = (uint8)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    tmpVal = (uint8)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S8 = (sint8)((uint8)(tmpVal | (uint8)(COM_INIT_FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S8= (sint8)tmpVal;
    }
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = (uint8)tmpSignData_S8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U8_PosInMidBit_LE
*
* Explanation: Parse received message data to unsigned char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint8 mask = (uint8)(COM_INIT_FF >> (COM_1BYTE_BITLENGTH - sigBitLength));
    /* Get data of the received message data. */
    uint8 tmpVal = srcBuffer[bytePos];

    /* Remove invalid low bits data. */
    tmpVal = (uint8)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    tmpSignData_U8 = (uint8)(tmpVal & mask);
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = tmpSignData_U8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S8_PosInMidBit_LE
*
* Explanation: Parse received message data to signed char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint8 tmpSignData_S8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint8 mask = (uint8)(COM_INIT_FF >> (COM_1BYTE_BITLENGTH - sigBitLength));
    /* Get data of the received message data. */
    uint8 tmpVal = srcBuffer[bytePos];

    /* Remove invalid low bits data. */
    tmpVal = (uint8)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    tmpVal = (uint8)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S8 = (sint8)((uint8)(tmpVal | (uint8)(COM_INIT_FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S8= (sint8)tmpVal;
    }
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = (uint8)tmpSignData_S8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U8_PosCrossBytes_BE
*
* Explanation: Parse received message data to unsigned char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint8 mask = (uint8)(COM_INIT_FF >> (COM_1BYTE_BITLENGTH - sigBitLength));
    uint16 tmpVal = srcBuffer[bytePos - COM_INIT_ONE];

    /* Get data of the received big endian type message data. */
    tmpVal = ((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint16)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = tmpVal >> bitPos;
    /* Remove invalid high bits data. */
    tmpSignData_U8 = (uint8)(tmpVal & mask);
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = tmpSignData_U8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S8_PosCrossBytes_BE
*
* Explanation: Parse received message data to signed char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint8 tmpSignData_S8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint8 unsignVal;
    uint8 mask = (uint8)(COM_INIT_FF >> (COM_1BYTE_BITLENGTH - sigBitLength));
    uint16 tmpVal = srcBuffer[bytePos - COM_INIT_ONE];

    /* Get data of the received big endian type message data. */
    tmpVal = ((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint16)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = tmpVal >> bitPos;
    /* Remove invalid high bits data. */
    unsignVal = (uint8)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S8 = (sint8)((uint8)(unsignVal | (uint8)(COM_INIT_FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S8= (sint8)unsignVal;
    }
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = (uint8)tmpSignData_S8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U8_PosCrossBytes_LE
*
* Explanation: Parse received message data to unsigned char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U8_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 tmpSignData_U8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint8 mask = (uint8)(COM_INIT_FF >> (COM_1BYTE_BITLENGTH - sigBitLength));
    uint16 tmpVal = srcBuffer[bytePos + COM_INIT_ONE];

    /* Get data of the received little endian type message data. */
    tmpVal = ((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint16)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = tmpVal >> bitPos;
    /* Remove invalid high bits data. */
    tmpSignData_U8 = (uint8)(tmpVal & mask);
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = tmpSignData_U8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S8_PosCrossBytes_LE
*
* Explanation: Parse received message data to signed char signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S8_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint8 unsignVal;
    sint8 tmpSignData_S8;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint8 mask = (uint8)(COM_INIT_FF >> (COM_1BYTE_BITLENGTH - sigBitLength));
    uint16 tmpVal = srcBuffer[bytePos + COM_INIT_ONE];

    /* Get data of the received little endian type message data. */
    tmpVal = ((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint16)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = tmpVal >> bitPos;
    /* Remove invalid high bits data. */
    unsignVal = (uint8)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S8 = (sint8)((uint8)(unsignVal | (uint8)(COM_INIT_FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S8= (sint8)unsignVal;
    }
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = (uint8)tmpSignData_S8;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U16_PosFullByte_BE
*
* Explanation: Parse received message data to unsigned short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint16 tmpVal = (uint16)srcBuffer[bytePos - COM_INIT_ONE] << COM_1BYTE_BITLENGTH;

    /* Get data of the received big endian type message data. */
    tmpSignData_U16= (tmpVal | (uint8)(srcBuffer[bytePos]));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_U16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_U16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S16_PosFullByte_BE
*
* Explanation: Parse received message data to signed short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint16 tmpSignData_S16;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    uint16 tmpVal = (uint16)srcBuffer[bytePos - COM_INIT_ONE] << COM_1BYTE_BITLENGTH;
    /* Get data of the received big endian type message data. */
    uint16 unsignVal = (tmpVal | (uint8)(srcBuffer[bytePos]));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S16 = (sint16)((uint16)(unsignVal | (uint16)(COM_INIT_U16FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S16 = (sint16)unsignVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_S16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_S16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U16_PosFullByte_LE
*
* Explanation: Parse received message data to unsigned short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint16 tmpVal = (uint16)srcBuffer[bytePos + COM_INIT_ONE] << COM_1BYTE_BITLENGTH;

    /* Get data of the received little endian type message data. */
    tmpSignData_U16 = (tmpVal | (uint8)(srcBuffer[bytePos]));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_U16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_U16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S16_PosFullByte_LE
*
* Explanation: Parse received message data to signed short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint16 tmpSignData_S16;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    uint16 tmpVal = (uint16)srcBuffer[bytePos + COM_INIT_ONE] << COM_1BYTE_BITLENGTH;
    /* Get data of the received little endian type message data. */
    uint16 unsignVal = (tmpVal | (uint8)(srcBuffer[bytePos]));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S16 = (sint16)((uint16)(unsignVal | (uint16)(COM_INIT_U16FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S16 = (sint16)unsignVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_S16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_S16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U16_PosToHighBit_BE
*
* Explanation: Parse received message data to unsigned short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint16 tmpVal = srcBuffer[bytePos - COM_INIT_ONE];

    /* Get data of the received big endian type message data. */
    tmpVal = (uint16)((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpSignData_U16 = (uint16)(tmpVal >> (COM_2BYTE_BITLENGTH - sigBitLength));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_U16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_U16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S16_PosToHighBit_BE
*
* Explanation: Parse received message data to signed short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint16 tmpSignData_S16;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint16 tmpVal = srcBuffer[bytePos - COM_INIT_ONE];

    /* Get data of the received big endian type message data. */
    tmpVal = (uint16)((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint16)(tmpVal >> (COM_2BYTE_BITLENGTH - sigBitLength));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S16 = (sint16)((uint16)(tmpVal | (uint16)(COM_INIT_U16FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S16 = (sint16)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_S16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_S16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U16_PosToHighBit_LE
*
* Explanation: Parse received message data to unsigned short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint16 tmpVal = srcBuffer[bytePos + COM_INIT_ONE];

    /* Get data of the received little endian type message data. */
    tmpVal = ((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpSignData_U16 = (uint16)(tmpVal >> (COM_2BYTE_BITLENGTH - sigBitLength));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_U16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_U16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S16_PosToHighBit_LE
*
* Explanation: Parse received message data to signed short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint16 tmpSignData_S16;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint16 tmpVal = srcBuffer[bytePos + COM_INIT_ONE];

    /* Get data of the received little endian type message data. */
    tmpVal = (uint16)((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint16)(tmpVal >> (COM_2BYTE_BITLENGTH - sigBitLength));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S16 = (sint16)((uint16)(tmpVal | (uint16)(COM_INIT_U16FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S16 = (sint16)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_S16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_S16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U16_PosToLowhBit_BE
*
* Explanation: Parse received message data to unsigned short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint16 mask = (uint16)(COM_INIT_U16FF >> (COM_2BYTE_BITLENGTH - sigBitLength));
    uint16 tmpVal = srcBuffer[bytePos - COM_INIT_ONE];

    /* Get data of the received big endian type message data. */
    tmpVal = ((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid high bits data. */
    tmpSignData_U16 = (uint16)(tmpVal & mask);
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_U16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_U16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S16_PosToLowhBit_BE
*
* Explanation: Parse received message data to signed short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint16 tmpSignData_S16;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint16 mask = (uint16)(COM_INIT_U16FF >> (COM_2BYTE_BITLENGTH - sigBitLength));
    uint16 tmpVal = srcBuffer[bytePos - COM_INIT_ONE];

    /* Get data of the received big endian type message data. */
    tmpVal = ((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid high bits data. */
    tmpVal = (uint16)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S16 = (sint16)((uint16)(tmpVal | (uint16)(COM_INIT_U16FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S16 = (sint16)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_S16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_S16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U16_PosToLowhBit_LE
*
* Explanation: Parse received message data to unsigned short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint16 mask = (uint16)(COM_INIT_U16FF >> (COM_2BYTE_BITLENGTH - sigBitLength));
    uint16 tmpVal = srcBuffer[bytePos + COM_INIT_ONE];

    /* Get data of the received little endian type message data. */
    tmpVal = ((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid high bits data. */
    tmpSignData_U16 = (uint16)(tmpVal & mask);
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_U16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_U16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S16_PosToLowhBit_LE
*
* Explanation: Parse received message data to signed short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint16 tmpSignData_S16;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint16 mask = (uint16)(COM_INIT_U16FF >> (COM_2BYTE_BITLENGTH - sigBitLength));
    uint16 tmpVal = srcBuffer[bytePos + COM_INIT_ONE];

    /* Get data of the received little endian type message data. */
    tmpVal = ((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid high bits data. */
    tmpVal = (uint16)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S16 = (sint16)((uint16)(tmpVal | (uint16)(COM_INIT_U16FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S16 = (sint16)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_S16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_S16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U16_PosInMidBit_BE
*
* Explanation: Parse received message data to unsigned short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint16 mask = (uint16)(COM_INIT_U16FF >> (COM_2BYTE_BITLENGTH - sigBitLength));
    uint16 tmpVal = srcBuffer[bytePos - COM_INIT_ONE];

    /* Get data of the received big endian type message data. */
    tmpVal = ((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint16)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    tmpSignData_U16 = (uint16)(tmpVal & mask);
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_U16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_U16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S16_PosInMidBit_BE
*
* Explanation: Parse received message data to signed short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint16 tmpSignData_S16;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint16 mask = (uint16)(COM_INIT_U16FF >> (COM_2BYTE_BITLENGTH - sigBitLength));
    uint16 tmpVal = srcBuffer[bytePos - COM_INIT_ONE];

    /* Get data of the received big endian type message data. */
    tmpVal = ((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint16)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    tmpVal = (uint16)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S16 = (sint16)((uint16)(tmpVal | (uint16)(COM_INIT_U16FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S16 = (sint16)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_S16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_S16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U16_PosInMidBit_LE
*
* Explanation: Parse received message data to unsigned short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint16 mask = (uint16)(COM_INIT_U16FF >> (COM_2BYTE_BITLENGTH - sigBitLength));
    uint16 tmpVal = srcBuffer[bytePos + COM_INIT_ONE];

    /* Get data of the received little endian type message data. */
    tmpVal = ((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint16)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    tmpSignData_U16= (uint16)(tmpVal & mask);
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_U16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_U16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S16_PosInMidBit_LE
*
* Explanation: Parse received message data to signed short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    sint16 tmpSignData_S16;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint16 mask = (uint16)(COM_INIT_U16FF >> (COM_2BYTE_BITLENGTH - sigBitLength));
    uint16 tmpVal = srcBuffer[bytePos + COM_INIT_ONE];

    /* Get data of the received little endian type message data. */
    tmpVal = ((uint16)(tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint16)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    tmpVal = (uint16)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S16 = (sint16)((uint16)(tmpVal | (uint16)(COM_INIT_U16FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S16 = (sint16)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_S16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_S16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U16_PosCrossBytes_BE
*
* Explanation: Parse received message data to unsigned short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint16 mask = (uint16)(COM_INIT_U16FF >> (COM_2BYTE_BITLENGTH - sigBitLength));
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_TWO];

    /* Get data of the received big endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint32)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    tmpSignData_U16= (uint16)(tmpVal & mask);
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_U16);
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_U16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S16_PosCrossBytes_BE
*
* Explanation: Parse received message data to signed short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 unsignVal;
    sint16 tmpSignData_S16;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint16 mask = (uint16)(COM_INIT_U16FF >> (COM_2BYTE_BITLENGTH - sigBitLength));
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_TWO];

    /* Get data of the received big endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint32)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    unsignVal = (uint16)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S16 = (sint16)((uint16)(unsignVal | (uint16)(COM_INIT_U16FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S16 = (sint16)unsignVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_S16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_S16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U16_PosCrossBytes_LE
*
* Explanation: Parse received message data to unsigned short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U16_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 tmpSignData_U16;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint16 mask = (uint16)(COM_INIT_U16FF >> (COM_2BYTE_BITLENGTH - sigBitLength));
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_TWO];

    /* Get data of the received little endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint32)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    tmpSignData_U16 = (uint16)(tmpVal & mask);
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_U16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_U16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S16_PosCrossBytes_LE
*
* Explanation: Parse received message data to signed short signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S16_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint16 unsignVal;
    sint16 tmpSignData_S16;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint16 mask = (uint16)(COM_INIT_U16FF >> (COM_2BYTE_BITLENGTH - sigBitLength));
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_TWO];

    /* Get data of the received little endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint32)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    unsignVal = (uint16)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S16 = (sint16)((uint16)(unsignVal | (uint16)(COM_INIT_U16FF << sigBitLength)));
    }
    else
    {
        tmpSignData_S16 = (sint16)unsignVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiByte(tmpSignData_S16);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetLoByte(tmpSignData_S16);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U24_PosFullByte_BE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint32 tmpSignData_U24;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_TWO];

    /* Get data of the received big endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos - COM_INIT_ONE];
    tmpSignData_U24 = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S24_PosFullByte_BE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    sint32 tmpSignData_S24;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_TWO];

    /* Get data of the received big endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos - COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S24 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S24 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U24_PosFullByte_LE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint32 tmpSignData_U24;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_TWO];

    /* Get data of the received little endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos + COM_INIT_ONE];
    tmpSignData_U24 = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S24_PosFullByte_LE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    sint32 tmpSignData_S24;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_TWO];

    /* Get data of the received little endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos + COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S24 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S24 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U24_PosToHighBit_LE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint32 tmpSignData_U24;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_TWO];

    /* Get data of the received little endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos + COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid low bits data. */
    tmpSignData_U24 = (uint32)(tmpVal >> (COM_3BYTE_BITLENGTH - sigBitLength));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U24_PosToHighBit_BE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint32 tmpSignData_U24;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_TWO];

    /* Get data of the received big endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos - COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid low bits data. */
    tmpSignData_U24 = (uint32)(tmpVal >> (COM_3BYTE_BITLENGTH - sigBitLength));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S24_PosToHighBit_LE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    sint32 tmpSignData_S24;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_TWO];

    /* Get data of the received little endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos + COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid low bits data. */
    tmpVal = tmpVal >> (COM_3BYTE_BITLENGTH - sigBitLength);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S24 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S24 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S24_PosToHighBit_BE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    sint32 tmpSignData_S24;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_TWO];

    /* Get data of the received big endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos - COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid low bits data. */
    tmpVal = tmpVal >> (COM_3BYTE_BITLENGTH - sigBitLength);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S24 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S24 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U24_PosToLowhBit_LE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint32 tmpSignData_U24;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_TWO];

    /* Get data of the received little endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos + COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid high bits data. */
    tmpSignData_U24 = tmpVal & (COM_INIT_U24FF >> (COM_3BYTE_BITLENGTH - sigBitLength));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U24_PosToLowhBit_BE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint32 tmpSignData_U24;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_TWO];

    /* Get data of the received big endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos - COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid high bits data. */
    tmpSignData_U24 = tmpVal & (COM_INIT_U24FF >> (COM_3BYTE_BITLENGTH - sigBitLength));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S24_PosToLowhBit_LE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    sint32 tmpSignData_S24;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_TWO];

    /* Get data of the received little endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos + COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid high bits data. */
    tmpVal &= (COM_INIT_U24FF >> (COM_3BYTE_BITLENGTH - sigBitLength));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S24 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S24 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S24_PosToLowhBit_BE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    sint32 tmpSignData_S24;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_TWO];

    /* Get data of the received big endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos - COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid high bits data. */
    tmpVal &= (COM_INIT_U24FF >> (COM_3BYTE_BITLENGTH - sigBitLength));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S24 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S24 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U24_PosInMidBit_LE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint32 tmpSignData_U24;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_TWO];

    /* Get data of the received little endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos + COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid low bits data. */
    tmpVal = tmpVal >> bitPos;
    /* Remove invalid high bits data. */
    tmpSignData_U24 = tmpVal & (COM_INIT_U24FF >> (COM_3BYTE_BITLENGTH - sigBitLength));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U24_PosInMidBit_BE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint32 tmpSignData_U24;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_TWO];

    /* Get data of the received big endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos - COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid low bits data. */
    tmpVal = tmpVal >> bitPos;
    /* Remove invalid high bits data. */
    tmpSignData_U24 = tmpVal & (COM_INIT_U24FF >> (COM_3BYTE_BITLENGTH - sigBitLength));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S24_PosInMidBit_LE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    sint32 tmpSignData_S24;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_TWO];

    /* Get data of the received little endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos + COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid low bits data. */
    tmpVal = tmpVal >> bitPos;
    /* Remove invalid high bits data. */
    tmpVal &= (COM_INIT_U24FF >> (COM_3BYTE_BITLENGTH - sigBitLength));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)))
    {
        /* High-order position complement 1. */
        tmpSignData_S24 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S24 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S24_PosInMidBit_BE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    sint32 tmpSignData_S24;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_TWO];

    /* Get data of the received big endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos - COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid low bits data. */
    tmpVal = tmpVal >> bitPos;
    /* Remove invalid high bits data. */
    tmpVal &= (COM_INIT_U24FF >> (COM_3BYTE_BITLENGTH - sigBitLength));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S24 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S24 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U24_PosCrossBytes_LE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint32 tmpSignData_U24;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_THREE];

    /* Get data of the received little endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos + COM_INIT_TWO];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos + COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid low bits data. */
    tmpVal = tmpVal >> bitPos;
    /* Remove invalid high bits data. */
    tmpSignData_U24 = tmpVal & (COM_INIT_U24FF >> (COM_3BYTE_BITLENGTH - sigBitLength));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U24_PosCrossBytes_BE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U24_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint32 tmpSignData_U24;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_THREE];

    /* Get data of the received big endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos - COM_INIT_TWO];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos - COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid low bits data. */
    tmpVal = tmpVal >> bitPos;
    /* Remove invalid high bits data. */
    tmpSignData_U24 = tmpVal & (COM_INIT_U24FF >> (COM_3BYTE_BITLENGTH - sigBitLength));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S24_PosCrossBytes_LE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    sint32 tmpSignData_S24;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_THREE];

    /* Get data of the received little endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos + COM_INIT_TWO];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos + COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid low bits data. */
    tmpVal = tmpVal >> bitPos;
    /* Remove invalid high bits data. */
    tmpVal &= (COM_INIT_U24FF >> (COM_3BYTE_BITLENGTH - sigBitLength));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S24 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S24 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S24_PosCrossBytes_BE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S24_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    sint32 tmpSignData_S24;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_THREE];

    /* Get data of the received big endian type message data. */
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos - COM_INIT_TWO];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos - COM_INIT_ONE];
    tmpVal = (tmpVal << COM_1BYTE_BITLENGTH) | srcBuffer[bytePos];
    /* Remove invalid low bits data. */
    tmpVal = tmpVal >> bitPos;
    /* Remove invalid high bits data. */
    tmpVal &= (COM_INIT_U24FF >> (COM_3BYTE_BITLENGTH - sigBitLength));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (signalBaseRef->sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S24 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S24 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S24);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S24);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S24);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S24);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U32_PosFullByte_BE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint32 tmpSignData_U32;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_THREE];

    /* Get data of the received big endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_ONE]));
    tmpSignData_U32  = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S32_PosFullByte_BE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosFullByte_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    sint32 tmpSignData_S32;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_THREE];

    /* Get data of the received big endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S32 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S32 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U32_PosFullByte_LE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    uint32 tmpSignData_U32;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_THREE];

    /* Get data of the received little endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_ONE]));
    tmpSignData_U32  = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S32_PosFullByte_LE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosFullByte_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    sint32 tmpSignData_S32;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_THREE];

    /* Get data of the received little endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_ONE]));
    tmpVal  = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S32 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S32 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U32_PosToHighBit_BE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    uint32 tmpSignData_U32;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_THREE];

    /* Get data of the received big endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpSignData_U32 = (uint32)(tmpVal >> (COM_4BYTE_BITLENGTH - sigBitLength));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S32_PosToHighBit_BE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosToHighBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    sint32 tmpSignData_S32;
    uint32 unsignVal;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_THREE];

    /* Get data of the received big endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    unsignVal = (uint32)(tmpVal >> (COM_4BYTE_BITLENGTH - sigBitLength));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S32 = (sint32)(unsignVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S32 = (sint32)unsignVal;
    }
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S32);
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S32);
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S32);
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U32_PosToHighBit_LE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{

    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    uint32 tmpSignData_U32;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_THREE];

    /* Get data of the received little endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpSignData_U32 = (uint32)(tmpVal >> (COM_4BYTE_BITLENGTH - sigBitLength));
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S32_PosToHighBit_LE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosToHighBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    sint32 tmpSignData_S32;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_THREE];

    /* Get data of the received little endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (tmpVal >> (COM_4BYTE_BITLENGTH - sigBitLength));

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S32 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S32 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U32_PosToLowhBit_BE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    uint32 tmpSignData_U32;
    uint32 mask = (uint32)(COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength));
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_THREE];

    /* Get data of the received big endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos ]));
    /* Remove invalid high bits data. */
    tmpSignData_U32 = (uint32)(tmpVal & mask);
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S32_PosToLowhBit_BE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosToLowhBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    uint32 mask = (uint32)(COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength));
    sint32 tmpSignData_S32;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_THREE];

    /* Get data of the received big endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid high bits data. */
    tmpVal = (uint32)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S32 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S32 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U32_PosToLowhBit_LE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    uint32 mask = (uint32)(COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength));
    uint32 tmpSignData_U32;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_THREE];

    /* Get data of the received little endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid high bits data. */
    tmpSignData_U32 = (uint32)(tmpVal & mask);
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S32_PosToLowhBit_LE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosToLowhBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    uint32 mask = (uint32)(COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength));
    sint32 tmpSignData_S32;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_THREE];

    /* Get data of the received little endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid high bits data. */
    tmpVal = (uint32)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S32 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S32 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U32_PosInMidBit_BE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint32 mask = (uint32)(COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength));
    uint32 tmpSignData_U32;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_THREE];

    /* Get data of the received big endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint32)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    tmpSignData_U32 = (uint32)(tmpVal & mask);
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S32_PosInMidBit_BE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosInMidBit_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint32 mask = (uint32)(COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength));
    sint32 tmpSignData_S32;
    uint32 tmpVal = srcBuffer[bytePos - COM_INIT_THREE];

    /* Get data of the received big endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint32)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    tmpVal = (uint32)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S32 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S32 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U32_PosInMidBit_LE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{

    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint32 mask = (uint32)(COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength));
    uint32 tmpSignData_U32;
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_THREE];

    /* Get data of the received little endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint32)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    tmpSignData_U32 = (uint32)(tmpVal & mask);
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S32_PosInMidBit_LE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosInMidBit_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    sint32 tmpSignData_S32;
    uint32 mask = (uint32)(COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength));
    uint32 tmpVal = srcBuffer[bytePos + COM_INIT_THREE];

    /* Get data of the received little endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint32)( tmpVal >> bitPos );
    /* Remove invalid high bits data. */
    tmpVal = (uint32)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (tmpVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S32 = (sint32)(tmpVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S32 = (sint32)tmpVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U32_PosCrossBytes_BE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint32 tmpSignData_U32;
    uint32 mask = (uint32)(COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength));
    uint64 tmpVal = srcBuffer[bytePos - COM_INIT_FOUR];

    /* Get data of the received big endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_THREE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint64)(tmpVal >> bitPos);
    /* Remove invalid high bits data. */
    tmpSignData_U32 = (uint32)(tmpVal & mask);
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S32_PosCrossBytes_BE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosCrossBytes_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 unsignVal;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    sint32 tmpSignData_S32;
    uint32 mask = (uint32)(COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength));
    uint64 tmpVal = srcBuffer[bytePos - COM_INIT_FOUR];

    /* Get data of the received big endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_THREE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos - COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint64)( tmpVal >> bitPos );
    /* Remove invalid high bits data. */
    unsignVal = (uint32)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S32 = (sint32)(unsignVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S32 = (sint32)unsignVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U32_PosCrossBytes_LE
*
* Explanation: Parse received message data to unsigned long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U32_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    uint32 tmpSignData_U32;
    uint32 mask = (uint32)(COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength));
    uint64 tmpVal = srcBuffer[bytePos + COM_INIT_FOUR];

    /* Get data of the received little endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_THREE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint64)( tmpVal >> bitPos );
    /* Remove invalid high bits data. */
    tmpSignData_U32 = (uint32)(tmpVal & mask);
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_U32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_U32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_U32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_U32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S32_PosCrossBytes_LE
*
* Explanation: Parse received message data to signed long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S32_PosCrossBytes_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    uint32 unsignVal;
    Com_SigBitLengthType sigBitLength = signalBaseRef->sigBitLength;
    Com_SigStartByteType bytePos = signalBaseRef->sigStartByte;
    Com_SigStartBitType bitPos = signalBaseRef->sigStartBit;
    sint32 tmpSignData_S32;
    uint32 mask = (uint32)(COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigBitLength));
    uint64 tmpVal = srcBuffer[bytePos + COM_INIT_FOUR];

    /* Get data of the received little endian type message data. */
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_THREE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_TWO]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos + COM_INIT_ONE]));
    tmpVal = ((tmpVal << COM_1BYTE_BITLENGTH) | (uint8)(srcBuffer[bytePos]));
    /* Remove invalid low bits data. */
    tmpVal = (uint64)( tmpVal >> bitPos );
    /* Remove invalid high bits data. */
    unsignVal = (uint32)(tmpVal & mask);

    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (sigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S32 = (sint32)(unsignVal | (COM_INIT_U32FF << sigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S32 = (sint32)unsignVal;
    }
    /* Set high byte of signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(tmpSignData_S32);
    /* Set HiLo byte of signal data. */
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(tmpSignData_S32);
    /* Set LoHi byte of signal data. */
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(tmpSignData_S32);
    /* Set low byte of signal data. */
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(tmpSignData_S32);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_BOOLEAN
*
* Explanation: Parse received message data to bool signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_BOOLEAN
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    boolean tmpSignData_BOOL;
    uint8 tmpVal = srcBuffer[signalBaseRef->sigStartByte] >> (signalBaseRef->sigStartBit);

   /* Get valid data of the received message data. */
    tmpSignData_BOOL = (boolean)(tmpVal & COM_OPERAND_ONE);
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = tmpSignData_BOOL;
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U64_BE
*
* Explanation: Parse received message data to unsigned long long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U64_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{

    Com_SigBitLengthType sigsigBitLength;
    Com_SigByteLengthType sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit;
    Com_SigStartByteType sigStartByte;
    uint64 sigValue = COM_INIT_ZERO;
    uint64 tmpSignData_U64;

    sigStartBit =  signalBaseRef->sigStartBit;
    sigsigBitLength = signalBaseRef->sigBitLength;
    sigStartByte = signalBaseRef->sigStartByte;
    sigByteLength = signalBaseRef->sigByteLength;

    if( COM_8BYTELENGTH < sigByteLength )
    {
        /* High 8 Byte Data. */
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_8BYTELENGTH;sigByteLengthIndex++ )
        {
            /* Big endian. */
            sigValue |= ((uint64)srcBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue << (COM_1BYTE_BITLENGTH - sigStartBit );
        /* Low 8 Byte Data. */
        sigValue = sigValue | ((uint64)srcBuffer[sigStartByte] >> sigStartBit );
    }
    else
    {
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength;sigByteLengthIndex++ )
        {
            /* Big endian. */
            sigValue |= ((uint64)srcBuffer[sigStartByte - sigByteLengthIndex]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue >> (sigStartBit);
    }

    tmpSignData_U64 = (sigValue & (COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigsigBitLength)));
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = Com_Get64HiHiByte(tmpSignData_U64);
    destBuffer[COM_INIT_ONE] = Com_Get64HiLoByte(tmpSignData_U64);
    destBuffer[COM_INIT_TWO] = Com_Get64LoHiByte(tmpSignData_U64);
    destBuffer[COM_INIT_THREE] = Com_Get64LoLoByte(tmpSignData_U64);
    destBuffer[COM_INIT_FOUR] = Com_Get64Hi32HiByte(tmpSignData_U64);
    destBuffer[COM_INIT_FIVE] = Com_Get64Hi32LoByte(tmpSignData_U64);
    destBuffer[COM_INIT_SIX] = Com_Get64Lo32HiByte(tmpSignData_U64);
    destBuffer[COM_INIT_SEVEN] = Com_Get64Lo32LoByte(tmpSignData_U64);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S64_BE
*
* Explanation: Parse received message data to long long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S64_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigsigBitLength;
    Com_SigByteLengthType sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit;
    Com_SigStartByteType sigStartByte;
    uint64 sigValue = COM_INIT_ZERO;
    sint64 tmpSignData_S64;
    uint64 unsignVal;

    sigStartBit =  signalBaseRef->sigStartBit;
    sigsigBitLength = signalBaseRef->sigBitLength;
    sigStartByte = signalBaseRef->sigStartByte;
    sigByteLength = signalBaseRef->sigByteLength;

    if( COM_8BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_8BYTELENGTH;sigByteLengthIndex++ )
        {
            /* Big endian. */
            sigValue |= ((uint64)srcBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue << (COM_1BYTE_BITLENGTH - sigStartBit );
        /* Low 4 Byte Data. */
        sigValue = sigValue | ((uint64)srcBuffer[sigStartByte] >> sigStartBit );
    }
    else
    {
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength;sigByteLengthIndex++ )
        {
            /* Big endian. */
            sigValue |= ((uint64)srcBuffer[sigStartByte - sigByteLengthIndex]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue >> (sigStartBit);
    }

    unsignVal  = (sigValue & (COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigsigBitLength)));
    /* Signal value < 0. */
    if( COM_OPERAND_ONE == (unsignVal >> (sigsigBitLength - COM_OPERAND_ONE)) )
    {
        /* High-order position complement 1. */
        tmpSignData_S64 = (sint64)(unsignVal | ((uint64)COM_INIT_U64FF << sigsigBitLength));  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S64 = (sint64)unsignVal;
    }
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = Com_Get64HiHiByte(tmpSignData_S64);
    destBuffer[COM_INIT_ONE] = Com_Get64HiLoByte(tmpSignData_S64);
    destBuffer[COM_INIT_TWO] = Com_Get64LoHiByte(tmpSignData_S64);
    destBuffer[COM_INIT_THREE] = Com_Get64LoLoByte(tmpSignData_S64);
    destBuffer[COM_INIT_FOUR] = Com_Get64Hi32HiByte(tmpSignData_S64);
    destBuffer[COM_INIT_FIVE] = Com_Get64Hi32LoByte(tmpSignData_S64);
    destBuffer[COM_INIT_SIX] = Com_Get64Lo32HiByte(tmpSignData_S64);
    destBuffer[COM_INIT_SEVEN] = Com_Get64Lo32LoByte(tmpSignData_S64);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U64_LE
*
* Explanation: Parse received message data to unsigned long long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U64_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigsigBitLength;
    Com_SigByteLengthType sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit;
    Com_SigStartByteType sigStartByte;
    uint64 sigValue = COM_INIT_ZERO;
    uint64 tmpSignData_U64;

    sigStartBit =  signalBaseRef->sigStartBit;
    sigsigBitLength = signalBaseRef->sigBitLength;
    sigStartByte = signalBaseRef->sigStartByte;
    sigByteLength = signalBaseRef->sigByteLength;

    if( COM_8BYTELENGTH < sigByteLength )
    {
        /* High 8 Byte Data. */
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_8BYTELENGTH;sigByteLengthIndex++ )
        {
            /* Little endian */
            sigValue |= ((uint64)srcBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue << (COM_1BYTE_BITLENGTH - sigStartBit );
        /* Low 8 Byte Data. */
        sigValue = sigValue | ((uint64)srcBuffer[sigStartByte] >> (sigStartBit));
    }
    else
    {
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength;sigByteLengthIndex++ )
        {
            /* Little endian */
            sigValue |= ((uint64)srcBuffer[sigStartByte + sigByteLengthIndex]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue >> (sigStartBit);
    }

    tmpSignData_U64 = (sigValue & (COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigsigBitLength)));
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = Com_Get64HiHiByte(tmpSignData_U64);
    destBuffer[COM_INIT_ONE] = Com_Get64HiLoByte(tmpSignData_U64);
    destBuffer[COM_INIT_TWO] = Com_Get64LoHiByte(tmpSignData_U64);
    destBuffer[COM_INIT_THREE] = Com_Get64LoLoByte(tmpSignData_U64);
    destBuffer[COM_INIT_FOUR] = Com_Get64Hi32HiByte(tmpSignData_U64);
    destBuffer[COM_INIT_FIVE] = Com_Get64Hi32LoByte(tmpSignData_U64);
    destBuffer[COM_INIT_SIX] = Com_Get64Lo32HiByte(tmpSignData_U64);
    destBuffer[COM_INIT_SEVEN] = Com_Get64Lo32LoByte(tmpSignData_U64);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_S64_LE
*
* Explanation: Parse received message data to long long signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_S64_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigsigBitLength;
    Com_SigByteLengthType sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit;
    Com_SigStartByteType sigStartByte;
    uint64 sigValue = COM_INIT_ZERO;
    sint64 tmpSignData_S64;

    sigStartBit =  signalBaseRef->sigStartBit;
    sigsigBitLength = signalBaseRef->sigBitLength;
    sigStartByte = signalBaseRef->sigStartByte;
    sigByteLength = signalBaseRef->sigByteLength;

    if( COM_8BYTELENGTH < sigByteLength )
    {
        /* High 8 Byte Data. */
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_8BYTELENGTH;sigByteLengthIndex++ )
        {
            /* Little endian */
            sigValue |= ((uint64)srcBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue << (COM_1BYTE_BITLENGTH - sigStartBit );
        /* Low 8 Byte Data. */
        sigValue = sigValue | ((uint64)srcBuffer[sigStartByte] >> (sigStartBit));
    }
    else
    {
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength;sigByteLengthIndex++ )
        {
            /* Little endian */
            sigValue |= ((uint64)srcBuffer[sigStartByte + sigByteLengthIndex]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue >> (sigStartBit);
    }

    uint64 unsignVal  = (sigValue & (COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigsigBitLength)));
    if( COM_OPERAND_ONE == (unsignVal >> (sigsigBitLength - COM_OPERAND_ONE)) ) /* Signal value < 0. */
    {
        tmpSignData_S64 = (sint64)(unsignVal | ((uint64)COM_INIT_U64FF << sigsigBitLength)); /* High-order position complement 1. */  /* PRQA S 4394 */ /* NSCA_QAC_Com_Rule10.8 */
    }
    else
    {
        tmpSignData_S64 = (sint64)unsignVal;
    }
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = Com_Get64HiHiByte(tmpSignData_S64);
    destBuffer[COM_INIT_ONE] = Com_Get64HiLoByte(tmpSignData_S64);
    destBuffer[COM_INIT_TWO] = Com_Get64LoHiByte(tmpSignData_S64);
    destBuffer[COM_INIT_THREE] = Com_Get64LoLoByte(tmpSignData_S64);
    destBuffer[COM_INIT_FOUR] = Com_Get64Hi32HiByte(tmpSignData_S64);
    destBuffer[COM_INIT_FIVE] = Com_Get64Hi32LoByte(tmpSignData_S64);
    destBuffer[COM_INIT_SIX] = Com_Get64Lo32HiByte(tmpSignData_S64);
    destBuffer[COM_INIT_SEVEN] = Com_Get64Lo32LoByte(tmpSignData_S64);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_F32_BE
*
* Explanation: Parse received message data to float signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_F32_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigsigBitLength;
    Com_SigByteLengthType sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit;
    Com_SigStartByteType sigStartByte;
    uint32 sigValue = COM_INIT_ZERO;

    sigStartBit =  signalBaseRef->sigStartBit;
    sigsigBitLength = signalBaseRef->sigBitLength;
    sigStartByte = signalBaseRef->sigStartByte;
    sigByteLength = signalBaseRef->sigByteLength;

    if( COM_4BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_4BYTELENGTH;sigByteLengthIndex++ )
        {
            /* Big endian. */
            sigValue |= ((uint32)srcBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue << (COM_1BYTE_BITLENGTH - ((uint32)sigStartBit));
        /* Low 4 Byte Data. */
        sigValue = sigValue | ((uint32)srcBuffer[sigStartByte] >> ((uint32)sigStartBit));
    }
    else
    {
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength;sigByteLengthIndex++ )
        {
            /* Big endian. */
            sigValue |= ((uint32)srcBuffer[sigStartByte - sigByteLengthIndex]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue >> (sigStartBit);
    }

    sigValue = (uint32)(sigValue & (COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigsigBitLength)));
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(sigValue);
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(sigValue);
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(sigValue);
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(sigValue);

}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_F32_LE
*
* Explanation: Parse received message data to float signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_F32_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigsigBitLength;
    Com_SigByteLengthType sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit;
    Com_SigStartByteType sigStartByte;
    uint32 sigValue = COM_INIT_ZERO;

    sigStartBit =  signalBaseRef->sigStartBit;
    sigsigBitLength = signalBaseRef->sigBitLength;
    sigStartByte = signalBaseRef->sigStartByte;
    sigByteLength = signalBaseRef->sigByteLength;

    if( COM_4BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_4BYTELENGTH;sigByteLengthIndex++ )
        {
            /* Little endian */
            sigValue |= ((uint32)srcBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue << (COM_1BYTE_BITLENGTH - ((uint32)sigStartBit));
        /* Low 4 Byte Data. */
        sigValue = sigValue | ((uint32)srcBuffer[sigStartByte] >> ((uint32)sigStartBit));
    }
    else
    {
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength;sigByteLengthIndex++ )
        {
            /* Little endian */
            sigValue |= ((uint32)srcBuffer[sigStartByte + sigByteLengthIndex]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue >> (sigStartBit);
    }

    sigValue = (uint32)(sigValue & (COM_INIT_U32FF >> (COM_4BYTE_BITLENGTH - sigsigBitLength)));
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = Com_GetHiHiByte(sigValue);
    destBuffer[COM_INIT_ONE] = Com_GetHiLoByte(sigValue);
    destBuffer[COM_INIT_TWO] = Com_GetLoHiByte(sigValue);
    destBuffer[COM_INIT_THREE] = Com_GetLoLoByte(sigValue);

}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_F64_BE
*
* Explanation: Parse received message data to double signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_F64_BE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigsigBitLength;
    Com_SigByteLengthType sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit;
    Com_SigStartByteType sigStartByte;
    uint64 sigValue = COM_INIT_ZERO;

    sigStartBit =  signalBaseRef->sigStartBit;
    sigsigBitLength = signalBaseRef->sigBitLength;
    sigStartByte = signalBaseRef->sigStartByte;
    sigByteLength = signalBaseRef->sigByteLength;

    if( COM_8BYTELENGTH < sigByteLength )
    {
        /* High 8 Byte Data. */
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_8BYTELENGTH;sigByteLengthIndex++ )
        {
            /* Big endian. */
            sigValue |= ((uint64)srcBuffer[sigStartByte - sigByteLengthIndex - COM_OPERAND_ONE]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue << (COM_1BYTE_BITLENGTH - sigStartBit );
        /* Low 8 Byte Data. */
        sigValue = sigValue | ((uint64)srcBuffer[sigStartByte] >> sigStartBit );
    }
    else
    {
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength;sigByteLengthIndex++ )
        {
            /* Big endian. */
            sigValue |= ((uint64)srcBuffer[sigStartByte - sigByteLengthIndex]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue >> (sigStartBit);
    }

    sigValue = (sigValue & (COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigsigBitLength)));
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = Com_Get64HiHiByte(sigValue);
    destBuffer[COM_INIT_ONE] = Com_Get64HiLoByte(sigValue);
    destBuffer[COM_INIT_TWO] = Com_Get64LoHiByte(sigValue);
    destBuffer[COM_INIT_THREE] = Com_Get64LoLoByte(sigValue);
    destBuffer[COM_INIT_FOUR] = Com_Get64Hi32HiByte(sigValue);
    destBuffer[COM_INIT_FIVE] = Com_Get64Hi32LoByte(sigValue);
    destBuffer[COM_INIT_SIX] = Com_Get64Lo32HiByte(sigValue);
    destBuffer[COM_INIT_SEVEN] = Com_Get64Lo32LoByte(sigValue);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_F64_BE
*
* Explanation: Parse received message data to double signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_F64_LE
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
)
{
    Com_SigBitLengthType sigsigBitLength;
    Com_SigByteLengthType sigByteLength;
    Com_SigByteLengthType sigByteLengthIndex;
    Com_SigStartBitType sigStartBit;
    Com_SigStartByteType sigStartByte;
    uint64 sigValue = COM_INIT_ZERO;

    sigStartBit =  signalBaseRef->sigStartBit;
    sigsigBitLength = signalBaseRef->sigBitLength;
    sigStartByte = signalBaseRef->sigStartByte;
    sigByteLength = signalBaseRef->sigByteLength;

    if( COM_8BYTELENGTH < sigByteLength )
    {
        /* High 4 Byte Data. */
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < COM_8BYTELENGTH;sigByteLengthIndex++ )
        {
            /* Little endian */
            sigValue |= ((uint64)srcBuffer[sigStartByte + sigByteLengthIndex + COM_OPERAND_ONE]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue << (COM_1BYTE_BITLENGTH - sigStartBit );
        /* Low 4 Byte Data. */
        sigValue = sigValue | ((uint64)srcBuffer[sigStartByte] >> (sigStartBit));
    }
    else
    {
        for( sigByteLengthIndex = COM_INIT_ZERO; sigByteLengthIndex < sigByteLength;sigByteLengthIndex++ )
        {
            /* Little endian */
            sigValue |= ((uint64)srcBuffer[sigStartByte + sigByteLengthIndex]) << (COM_1BYTE_BITLENGTH * sigByteLengthIndex);
        }
        sigValue = sigValue >> (sigStartBit);
    }

    sigValue = (sigValue & (COM_INIT_U64FF >> (COM_8BYTE_BITLENGTH - sigsigBitLength)));
    /* Set signal data. */
    destBuffer[COM_INIT_ZERO] = Com_Get64HiHiByte(sigValue);
    destBuffer[COM_INIT_ONE] = Com_Get64HiLoByte(sigValue);
    destBuffer[COM_INIT_TWO] = Com_Get64LoHiByte(sigValue);
    destBuffer[COM_INIT_THREE] = Com_Get64LoLoByte(sigValue);
    destBuffer[COM_INIT_FOUR] = Com_Get64Hi32HiByte(sigValue);
    destBuffer[COM_INIT_FIVE] = Com_Get64Hi32LoByte(sigValue);
    destBuffer[COM_INIT_SIX] = Com_Get64Lo32HiByte(sigValue);
    destBuffer[COM_INIT_SEVEN] = Com_Get64Lo32LoByte(sigValue);
}

/*
********************************************************************************
* Function Name: Com_RxParseSignal_U8N
*
* Explanation: Parse received message data to Uint8_N signal.
*
* param: srcBuffer: Source buffer.
*        destBuffer: Destination buffer.
*        signalBaseRef: Signal info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, COM_CODE) Com_RxParseSignal_U8N
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef

)
{
    uint8 index = COM_INIT_ZERO;
    Com_SigStartByteType sigLengthIndex;

    /* uint8_N signal write data to a message. */
    for( sigLengthIndex = (uint8)signalBaseRef->sigStartByte;
        sigLengthIndex < ((uint8)signalBaseRef->sigStartByte + signalBaseRef->sigByteLength); sigLengthIndex++ )  /* PRQA S 1891 */ /* NSCA_QAC_Com_Rule10.7 */
    {
        destBuffer[index] = srcBuffer[sigLengthIndex];
        index++;
    }
}

#define COM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */


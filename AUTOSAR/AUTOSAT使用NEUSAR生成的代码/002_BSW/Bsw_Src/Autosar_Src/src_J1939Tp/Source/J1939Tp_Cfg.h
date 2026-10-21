/*
********************************************************************************
*
* File name: J1939Tp_Cfg.h
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
*  Version: 1.0
*  Author/Date : yong.zhang/2019.3.18
*  Change: New created
*  Cause: New
********************************************************************************
*  Version: 1.1
*  Author/Date : li.zhiheng/2020.1.9
*  Change: Add variable in J1939Tp_TxSduType struct.
*  Cause: Update
********************************************************************************
* Version: 3.0
* Author/Date : li.zhiheng/2020.03.30
* Change: Only version updata to 3.0
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date : li.zhiheng/2020.05.20
* Change: Modification code specification.
* Cause: Updata
********************************************************************************
* Version: 3.2
* Author/Date : YanCL/2024.6.25
* Change: 1.Add Memmap segment definition.
*         2.Updata copyright information.
* Cause: Updata
********************************************************************************
*/
#ifndef J1939TP_CFG_H_
#define J1939TP_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComStack_Types.h"
#include "J1939Tp_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Polyspace-begin MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* Dummy statement. */
/* Polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt " */
#define J1939TP_DUMMY_STATEMENT(v)        (v)=(v)

#define J1939Tp_GetPduIdOfTxPdu(Index)    (J1939Tp_TxPdu[(Index)].PduIdOfTxPdu)

/* Different types of timeout descriptions. */
#define J1939Tp_GetTime_T1()              (750U / J1939TP_TIMEBASE)
#define J1939Tp_GetTime_T2()              (1250U / J1939TP_TIMEBASE)
#define J1939Tp_GetTime_T3()              (1250U / J1939TP_TIMEBASE)
#define J1939Tp_GetTime_T4()              (1050U / J1939TP_TIMEBASE)
#define J1939Tp_GetTime_Th()              (500U / J1939TP_TIMEBASE)
#define J1939Tp_GetTime_Tr()              (200U / J1939TP_TIMEBASE)
#define J1939Tp_GetTime_Bam()             (50U / J1939TP_TIMEBASE)
#define J1939Tp_GetTxDtTime()                 (50U / J1939TP_TIMEBASE)

#define J1939TP_DEV_ERROR_REPORT              (TRUE)
#define J1939TP_VERSION_INFO_API              (TRUE)
#define J1939TP_CANCELLATION_SUPPORT          (TRUE)
#define J1939Tp_GetTxConfTimeout()            (1500U/J1939TP_TIMEBASE)
#define J1939TP_TIMEBASE 10U
#define J1939TP_RUNTIME_ERROR_REPORT          (FALSE)
#define J1939TP_RXCHANNEL_NUMBER              (0U)
#define J1939TP_TXCHANNEL_NUMBER              (1U)
#define J1939TP_RXNSDU_NUMBER                 (0U)
#define J1939TP_TXNSDU_NUMBER                 (6U)
#define J1939TP_TXPDU_NUM                     (2U)
#define J1939TP_RXPDU_NUM                     (1U)
#define J1939TP_TX_ENABLED                    (STD_ON)
#define J1939TP_RX_ENABLED                    (STD_ON)
#define J1939TP_DIRECT_ENABLED                (STD_OFF)
#define J1939TP_DIRECT_TX_ENABLED             (STD_OFF)
#define J1939TP_DIRECT_RX_ENABLED             (STD_OFF)
#define J1939TP_BAM_ENABLED                   (STD_OFF)
#define J1939TP_BAM_TX_ENABLED                (STD_OFF)
#define J1939TP_BAM_RX_ENABLED                (STD_OFF)
#define J1939TP_CMDT_ENABLED                  (STD_ON)
#define J1939TP_CMDT_TX_ENABLED               (STD_ON)
#define J1939TP_CMDT_RX_ENABLED               (STD_OFF)
#define J1939TP_DTTIME_TX_ENABLED             (STD_OFF)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* Polyspace-end MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */

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
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define J1939TP_START_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"

extern VAR(J1939Tp_RxPduStateType, J1939TP_VAR_INIT) J1939Tp_RxPduState[J1939TP_RXPDU_NUM + 1U];
extern VAR(J1939Tp_RxSduStateType, J1939TP_VAR_INIT) J1939Tp_RxSduState[J1939TP_RXNSDU_NUMBER + 1U];
extern VAR(J1939Tp_TxPduStateType, J1939TP_VAR_INIT) J1939Tp_TxPduState[J1939TP_TXPDU_NUM + 1U];
extern VAR(J1939Tp_TxSduStateType, J1939TP_VAR_INIT) J1939Tp_TxSduState[J1939TP_TXNSDU_NUMBER + 1U];

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define J1939TP_STOP_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define J1939TP_START_SEC_CONFIG_DATA
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"

extern CONST(J1939Tp_RxChannelType, J1939TP_CONFIG_DATA) J1939Tp_RxChannel[J1939TP_RXCHANNEL_NUMBER + 1U];
extern CONST(J1939Tp_RxSdu_Type, J1939TP_CONFIG_DATA) J1939Tp_RxSduInfo[J1939TP_RXNSDU_NUMBER + 1U];
extern CONST(J1939Tp_TxChannelType, J1939TP_CONFIG_DATA) J1939Tp_TxChannel[J1939TP_TXCHANNEL_NUMBER + 1U];
extern CONST(J1939Tp_TxSdu_Type, J1939TP_CONFIG_DATA) J1939Tp_TxSduInfo[J1939TP_TXNSDU_NUMBER + 1U];
extern CONST(J1939Tp_TxPduType, J1939TP_CONFIG_DATA) J1939Tp_TxPdu[J1939TP_TXPDU_NUM + 1U];
extern CONST(J1939Tp_RxPduType, J1939TP_CONFIG_DATA) J1939Tp_RxPdu[J1939TP_RXPDU_NUM + 1U];

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define J1939TP_STOP_SEC_CONFIG_DATA
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* J1939TP_CFG_H_ */


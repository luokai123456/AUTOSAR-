/*
********************************************************************************
*
* File name: Dem_Event.h
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: ZhiDX/2020.09.08
* Change: New created.
* Cause: Dispart from dem.c
********************************************************************************
* Version: 1.1
* Author/Date: FanHT/2023.02.02
* Change: Add Calibration Macro.
* Cause: Implementation
********************************************************************************
* Version: 1.2
* Author/Date: WangYS/2023.04.01
* Change: Add Calibration Macro.
* Cause: Update
********************************************************************************
* Version: 1.3
* Author/Date: WangYS/2023.04.03
* Change: Modify macro switch name.
* Cause: Optimization
********************************************************************************
* Version: 1.4
* Author/Date: WangYS/2023.04.06
* Change: Modify macro switch.
* Cause: Bugfix
********************************************************************************
* Version: 1.5
* Author/Date: WangYS/2023.04.08
* Change: Modify macro switch.
* Cause: Bugfix
********************************************************************************
* Version: 1.6
* Author/Date: WangYS/2023.04.26
* Change: Add DEM_CFG_J1939SUPPORT macro switch limit.
* Cause: Optimization
********************************************************************************
* Version: 1.7
* Author/Date: WangYS/2023.05.05
* Change: CCOREEDBUG-2814,add new function Dem_J1939DcmCheckClearFilterType.
* Cause: Bugfix
********************************************************************************
* Version: 1.8
* Author/Date: WangYS/2023.05.29
* Change: Adjust code according to code review.
* Cause: Optimization
********************************************************************************
* Version: 1.9
* Author/Date: FanHT/2023.06.09
* Change: Add the declaration of Dem_EventGetCombStatusByteByOld function.
* Cause: Bugfix
********************************************************************************
* Version: 2.0
* Author/Date: ZhangF/2023.08.02
* Change: Add parameters for the Dem_EventQueueEnter function.
* Cause: Bugfix
********************************************************************************
* Version: 2.1
* Author/Date: ZhangF/2023.09.19
* Change: Fix the event queue multitask preemption issue.
* Cause: Bugfix
********************************************************************************
* Version: 2.2
* Author/Date: ZhangF/2023.10.07
* Change: Add the global calibration array for Dem event calibration.
* Cause: Update
********************************************************************************
* Version: 2.3
* Author/Date: ZhangF/2023.10.09
* Change: Fix compile warning.
* Cause: Update
********************************************************************************
* Version: 2.4
* Author/Date: ZengJX/2023.10.27
* Change: Add macro about OBD Pid21 and Pid31 calc parm to fix compile warning.
* Cause: Update
********************************************************************************
* Version: 2.5
* Author/Date: ZengJX/2024.01.11
* Change: Add the declaring of Dem_GeneralEventTriggerEventStatusChangedCbk.
* Cause: Update
********************************************************************************
* Version: 2.6
* Author/Date: ZengJX/2024.01.12
* Change: Modify macro DEM_SET_STORED_DEBCNT.
* Cause: Optimization
********************************************************************************
* Version: 2.7
* Author/Date: ZengJX/2024.04.15
* Change: Optimize comments specifications.
* Cause: Optimization
********************************************************************************
* Version: 2.8
* Author/Date: ZengJX/2024.05.22
* Change: 1.Modify the macro DEM_GET_LAMP_FAILED_CNT and DEM_SET_LAMP_FAILED_CNT.
*         2.Modify the parameters of function Dem_EventCheckWarningIndicatorAct
*           and Dem_EventCheckWarningIndicatorDeAct.
* Cause: Optimization
********************************************************************************
* Version: 2.9
* Author/Date: ZengJX/2024.07.05
* Change: 1.Add macros about enable condition and storage condition.
*         2.Add macros about event avavilablity process split counter.
*         3.Add macros about management of operation cycle queue.
*         4.Add declaration of function Dem_OperCycleEnterQueue(),
*           Dem_OperCycleLeaveQueue().
* Cause: Optimization
********************************************************************************
* Version: 2.10
* Author/Date: ZengJX/2024.07.18
* Change: 1.Modify copyright information.
*         2.Fix Dem memmap issue.
* Cause: Optimization
********************************************************************************
* Version: 2.11
* Author/Date: ZengJX/2024.09.18
* Change: Add macros about operation of getting and setting variable
*         lampfailcntUpdated.
* Cause: Bugfix
********************************************************************************
* Version: 2.12
* Author/Date: ZengJX/2024.10.24
* Change: Declare the function Dem_ObdGetPfcEvtIdx().
* Cause: Update
********************************************************************************
* Version: 2.12
* Author/Date: ZengJX/2024.11.07
* Change: Add macros about getting and setting warmUpCycleCntSinceLastInit value.
* Cause: Bugfix
********************************************************************************
* Version: 2.13
* Author/Date: ZengJX/2025.02.07
* Change: Modify copyright information.
* Cause: Optimization
********************************************************************************
* Version: 2.14
* Author/Date: ZengJX/2025.02.08
* Change: Add macro to get and set Dem_DiagProcDTCIdx.
* Cause: Optimization
********************************************************************************
* Version: 2.15
* Author/Date: ZengJX/2025.03.24
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 2.16
* Author/Date: ZengJX/2025.05.29
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 2.17
* Author/Date: ZengJX/2025.06.05
* Change: Add the macros about getting and setting the counter of warm-up cycle
*         counter during the last driving cycle.
* Cause: Bugfix
********************************************************************************
* Version: 2.18
* Author/Date: ZengJX/2025.05.29
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
*/
#ifndef DEM_EVENT_H_
#define DEM_EVENT_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Dem_2.5" */
/* polyspace-begin MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
/* DTC status bit */
#define DEM_EVENT_DTC_STATUS_TF                             (0x01U)     /* testFailed. */
#define DEM_EVENT_DTC_STATUS_TFTOC                          (0x02U)     /* testFailedThisOperationCycle. */
#define DEM_EVENT_DTC_STATUS_PDTC                           (0x04U)     /* pending dtc. */
#define DEM_EVENT_DTC_STATUS_CDTC                           (0x08U)     /* confirmed dtc. */
#define DEM_EVENT_DTC_STATUS_TNCSLC                         (0x10U)     /* testNotCompletedSinceLastClear. */
#define DEM_EVENT_DTC_STATUS_TFSLC                          (0x20U)     /* testFailedSinceLastClear. */
#define DEM_EVENT_DTC_STATUS_TNCTOC                         (0x40U)     /* testNotCompletedThisOperationCycle. */
#define DEM_EVENT_DTC_STATUS_WIR                            (0x80U)     /* warningIndicatorRequested. */

#define DEM_EVENT_DTC_STATUS_INIT                           (0x50U)
#define DEM_EVENT_DTC_STATUS_PASS                           (0x00U)
#define DEM_EVENT_DTC_STATUS_FAIL                           (0x03U)
#define DEM_EVENT_DTC_STATUS_INVALID                        (0xFFU)

/* Event extend internal data element */
#define DEM_EVENT_EXTEND_STATUS_UC                          (0x01U)     /* UnconfirmedDTC. */
#define DEM_EVENT_EXTEND_STATUS_UCTOC                       (0x02U)     /* UnconfirmedDTC-ThisOperationCyle. */
#define DEM_EVENT_EXTEND_STATUS_UCSLC                       (0x04U)     /* UnconfirmedDTC-SinceLastClear. */
#define DEM_EVENT_EXTEND_STATUS_AGED                        (0x08U)     /* AgedDTC. */
#define DEM_EVENT_EXTEND_STATUS_SSLC                        (0x10U)     /* SymptomSinceLast-Clear. */
#define DEM_EVENT_EXTEND_STATUS_WIRSLC                      (0x20U)     /* WarningIndicator-RequestedSince-LastClear. */
#define DEM_EVENT_EXTEND_STATUS_EMR                         (0x40U)     /* EmissionRelatedDTC. */
#define DEM_EVENT_EXTEND_STATUS_TFSLR                       (0x80U)     /* TestFailedSinceLastClear/Aged. */
#define DEM_EVENT_EXTEND_OCC1                               (0x0100U)   /* Operation Cycle Counter Since Last FDC counter reached 127. */
#define DEM_EVENT_EXTEND_OCC2                               (0x0200U)   /* Test Passed Operation Cycle Counter Since Last FDC counter reached 127. */
#define DEM_EVENT_EXTEND_OCC3                               (0x0400U)   /* Operation Cycle Counter Since First FDC counter reached 127. */
#define DEM_EVENT_EXTEND_OCC4                               (0x0800U)   /* Operation Cycle Counter where FDC counter reached 127. */
#define DEM_EVENT_EXTEND_OCC5                               (0x1000U)   /* Warmup Operation Cycle Counter where MIL is Off Since Last Clear. */
#define DEM_EVENT_EXTEND_OCC6                               (0x2000U)   /* Continous Operation Cycle Counter where FDC counter reached 127. */

/*** Event Queue ***/
#define DEM_EVENT_BSW_QUEUE_LEN                             (DEM_CFG_BSWERRORBUFFERSIZE)
#define DEM_EVENT_QUEUE_LEN                                 (DEM_CFG_EVENT_NUM)
#define DEM_EVENT_QUEUE_IDLE                                (0U)
#define DEM_EVENT_QUEUE_BUSY                                (1U)

#define DEM_EVENT_UNDEFINE                                  (0U)
#define DEM_EVENT_PASSIVE                                   (1U)
#define DEM_EVENT_ACTIVE                                    (2U)

/*** Event Operation cycle request ***/
#define DEM_OPERATION_CYCLE_NONE                            (0U)
#define DEM_OPERATION_CYCLE_START                           (1U)                   
#define DEM_OPERATION_CYCLE_END                             (2U)
#define DEM_OPERATION_CYCLE_RESTART                         (3U)

/*** Event Debounce ***/
#define DEM_DEBOUNCE_COUNTER_ZERO                           (0U)
#define DEM_DEBOUNCE_COUNTER_ONE                            (1U)
#define DEM_DEBOUNCE_COUNTER_NEG_ONE                        (-1)

#define DEM_DEBOUNCE_FDC_HIGH_THRESHOLD                     (127U)
#define DEM_DEBOUNCE_FDC_LOW_THRESHOLD                      (-128)

/*** Event status in Event Memory ***/
#define DEM_EVENT_PENDING                                   (1U)
#define DEM_EVENT_CONFIRMED                                 (2U)
#define DEM_EVENT_HEALING                                   (3U)
#define DEM_EVENT_AGING                                     (4U)

/*** Event condition changed status ***/
#define DEM_EVENT_CONDITION_UNCHANGED                       (0U)
#define DEM_EVENT_CONDITION_OK_TO_NOK                       (1U)
#define DEM_EVENT_CONDITION_NOK_TO_OK                       (2U)

/*** Dem OBD Pid21 and Pid31 Calculating parameter ***/
#define DEM_OBD_CALC_PARM_HUNDRED                           (100U)
#define DEM_OBD_CALC_PARM_THOUSAND                          (1000U)
#define DEM_OBD_CALC_PARM_TWENTY_EIGHT                      (28U)

/*** NVM Block Index definition ***/
#define DEM_EVENT_STATUS_BLOCK                              (1U)

#define DEM_PRIMARY_INFO_BLOCK                              (uint16)(DEM_EVENT_STATUS_BLOCK + 1U)
#define DEM_PRIMARY_ENTRY_BLOCK_START                       (DEM_PRIMARY_INFO_BLOCK + 1U)
#define DEM_PRIMARY_ENTRY_BLOCK_END                         (DEM_PRIMARY_INFO_BLOCK + DEM_CFG_PRIMARY_MAX_NUMBER_EVENT_ENTRY)

#define DEM_USER0_INFO_BLOCK                                (DEM_PRIMARY_ENTRY_BLOCK_END + 1U)
#define DEM_USER0_ENTRY_BLOCK_START                         (uint16)(DEM_USER0_INFO_BLOCK + 1U)    
#define DEM_USER0_ENTRY_BLOCK_END                           (DEM_USER0_INFO_BLOCK + DEM_CFG_USER0_MAX_NUMBER_EVENT_ENTRY)   

#define DEM_USER1_INFO_BLOCK                                (DEM_USER0_ENTRY_BLOCK_END + 1U)
#define DEM_USER1_ENTRY_BLOCK_START                         (DEM_USER1_INFO_BLOCK + 1U) 
#define DEM_USER1_ENTRY_BLOCK_END                           (DEM_USER1_INFO_BLOCK + DEM_CFG_USER1_MAX_NUMBER_EVENT_ENTRY)

/*** Spilt DTCs into segment for query ***/
#define DEM_EVENT_DTC_SPILT_SEGMENT_NUM                     DEM_CFG_DTCACCESSSPILTLIMIT

/* Macros definition for Dem internal structer access */
#define DEM_GET_NVM_STATE()                                 Dem_Manage.nvmBlkSt.evtMemState
#define DEM_SET_NVM_STATE(state)                            Dem_Manage.nvmBlkSt.evtMemState = (state)

#define DEM_GET_NVM_IME_STORE_CNT()                         Dem_Manage.nvmBlkSt.evtMemImeStorCnt
#define DEM_SET_NVM_IME_STORE_CNT(val)                      Dem_Manage.nvmBlkSt.evtMemImeStorCnt = (val)

#define DEM_GET_NVM_STATUS(blkIdx)                          Dem_Manage.nvmBlkSt.nvmBlkStatus[(blkIdx) - DEM_BYTE_ONE]
#define DEM_SET_NVM_STATUS(blkIdx, st)                      Dem_Manage.nvmBlkSt.nvmBlkStatus[(blkIdx) - DEM_BYTE_ONE] = (st)

#define DEM_GET_NVM_ACCESS_BLOCK_IDX()                      Dem_Manage.nvmBlkSt.nvmAccessBlkIdx
#define DEM_SET_NVM_ACCESS_BLOCK_IDX(val)                   Dem_Manage.nvmBlkSt.nvmAccessBlkIdx = (val)

#define DEM_GET_NVM_READ_REQ_STATUS()                       Dem_Manage.nvmBlkSt.nvmReadReqSt
#define DEM_SET_NVM_READ_REQ_STATUS(st)                     Dem_Manage.nvmBlkSt.nvmReadReqSt = (st)

#define DEM_GET_NVM_READ_REQ(blkIdx)                        Dem_Manage.nvmBlkSt.nvmBlkReadReq[(blkIdx) - DEM_BYTE_ONE]
#define DEM_SET_NVM_READ_REQ(blkIdx, req)                   Dem_Manage.nvmBlkSt.nvmBlkReadReq[(blkIdx) - DEM_BYTE_ONE] = (req)

#define DEM_GET_NVM_WRITE_REQ_STATUS()                      Dem_Manage.nvmBlkSt.nvmWriteReqSt
#define DEM_SET_NVM_WRITE_REQ_STATUS(st)                    Dem_Manage.nvmBlkSt.nvmWriteReqSt = (st)

#define DEM_GET_NVM_WRITE_REQ(blkIdx)                       Dem_Manage.nvmBlkSt.nvmBlkWriteReq[(blkIdx) - DEM_BYTE_ONE]
#define DEM_SET_NVM_WRITE_REQ(blkIdx, req)                  Dem_Manage.nvmBlkSt.nvmBlkWriteReq[(blkIdx) - DEM_BYTE_ONE] = (req)

#define DEM_GET_NVM_CLEAR_REQ_STATUS()                      Dem_Manage.nvmBlkSt.nvmClearReqSt
#define DEM_SET_NVM_CLEAR_REQ_STATUS(st)                    Dem_Manage.nvmBlkSt.nvmClearReqSt = (st)

#define DEM_GET_NVM_CLEAR_REQ(blkIdx)                       Dem_Manage.nvmBlkSt.nvmBlkClearReq[(blkIdx) - DEM_BYTE_ONE]
#define DEM_SET_NVM_CLEAR_REQ(blkIdx, req)                  Dem_Manage.nvmBlkSt.nvmBlkClearReq[(blkIdx) - DEM_BYTE_ONE] = (req)

#define DEM_GET_NVM_IME_STORE(blkIdx)                       Dem_Manage.nvmBlkSt.nvmBlkImeStore[(blkIdx) - DEM_BYTE_ONE]
#define DEM_SET_NVM_IME_STORE(blkIdx, req)                  Dem_Manage.nvmBlkSt.nvmBlkImeStore[(blkIdx) - DEM_BYTE_ONE] = (req)

#define DEM_GET_NVM_IME_STORE_REQ()                         Dem_Manage.nvmBlkSt.nvmBlkImeStoreReq
#define DEM_SET_NVM_IME_STORE_REQ(req)                      Dem_Manage.nvmBlkSt.nvmBlkImeStoreReq = (req)

#define DEM_GET_MODULE_INIT_STATE()                         Dem_Manage.initSt

/* Marco about Checking if the enable condition group status changed or not. */
#define DEM_GET_ENCOND_REQ()                                Dem_Manage.evtInfo.evtEnCondReq
#define DEM_SET_ENCOND_REQ(req)                             Dem_Manage.evtInfo.evtEnCondReq = (req)

#define DEM_GET_ENCOND(condIdx)                             Dem_Manage.evtInfo.evtEnCond[(condIdx) - DEM_BYTE_ONE]
#define DEM_SET_ENCOND(condIdx, val)                        Dem_Manage.evtInfo.evtEnCond[(condIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_ENCONDGRP(grpIdx)                           Dem_Manage.evtInfo.evtEnCondGrp[(grpIdx) - DEM_BYTE_ONE]
#define DEM_SET_ENCONDGRP(grpIdx, val)                      Dem_Manage.evtInfo.evtEnCondGrp[(grpIdx) - DEM_BYTE_ONE] = (val)

/* Marco about Checking if the storage condition group status changed or not. */
#define DEM_GET_STORCOND_REQ()                              Dem_Manage.evtInfo.evtStorCondReq
#define DEM_SET_STORCOND_REQ(req)                           Dem_Manage.evtInfo.evtStorCondReq = (req)

#define DEM_GET_STORCOND(condIdx)                           Dem_Manage.evtInfo.evtStorCond[(condIdx) - DEM_BYTE_ONE]
#define DEM_SET_STORCOND(condIdx, val)                      Dem_Manage.evtInfo.evtStorCond[(condIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_STORCONDGRP(grpIdx)                         Dem_Manage.evtInfo.evtStorCondGrp[(grpIdx) - DEM_BYTE_ONE]
#define DEM_SET_STORCONDGRP(grpIdx, val)                    Dem_Manage.evtInfo.evtStorCondGrp[(grpIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_DTCSUPPRESSION(dtcIdx)                      Dem_Manage.evtInfo.evtDtcSupp[(dtcIdx) - DEM_BYTE_ONE]
#define DEM_SET_DTCSUPPRESSION(dtcIdx, val)                 Dem_Manage.evtInfo.evtDtcSupp[(dtcIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_EVENT_STORED(evtIdx, evtMemIdx)             Dem_Manage.evtInfo.evtStored[(evtIdx) - DEM_BYTE_ONE][(evtMemIdx) - DEM_BYTE_ONE]
#define DEM_SET_EVENT_STORED(evtIdx, evtMemIdx, val)        Dem_Manage.evtInfo.evtStored[(evtIdx) - DEM_BYTE_ONE][(evtMemIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_LAMPFAILCNT_UPDATED(evtIdx)                 Dem_Manage.evtInfo.lampfailcntUpdated[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_LAMPFAILCNT_UPDATED(evtIdx, val)            Dem_Manage.evtInfo.lampfailcntUpdated[(evtIdx) - DEM_BYTE_ONE] = (val)
#define DEM_GET_EVENT_ENTRY(evtIdx, evtMemIdx)              Dem_Manage.evtInfo.evtEntryIdx[(evtIdx) - DEM_BYTE_ONE][(evtMemIdx) - DEM_BYTE_ONE]
#define DEM_SET_EVENT_ENTRY(evtIdx, evtMemIdx, val)         Dem_Manage.evtInfo.evtEntryIdx[(evtIdx) - DEM_BYTE_ONE][(evtMemIdx) - DEM_BYTE_ONE] = (val)

#if( DEM_CFG_CALIBSUPPORT == STD_ON )
#define DEM_GET_INITAVAIL(evtIdx)                           Dem_Manage.evtInfo.evtInitAvail[(evtIdx)]
#define DEM_SET_INITAVAIL(evtIdx, val)                      Dem_Manage.evtInfo.evtInitAvail[(evtIdx)] = (val)
#endif

#define DEM_GET_AVAIL(evtIdx)                               Dem_Manage.evtInfo.evtAvail[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_AVAIL(evtIdx, val)                          Dem_Manage.evtInfo.evtAvail[(evtIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_TRIG(evtIdx)                                Dem_Manage.evtInfo.evtTrig[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_TRIG(evtIdx, val)                           Dem_Manage.evtInfo.evtTrig[(evtIdx) - DEM_BYTE_ONE] |= (val)
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_TRIG(evtIdx, val)                         Dem_Manage.evtInfo.evtTrig[(evtIdx) - DEM_BYTE_ONE] &= (val)

#define DEM_GET_FDCCNT(evtIdx)                              Dem_Manage.evtInfo.evtFdcCnt[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_FDCCNT(evtIdx, val)                         Dem_Manage.evtInfo.evtFdcCnt[(evtIdx) - DEM_BYTE_ONE] = (sint8)(val)

#define DEM_GET_FDCCNTMAX_DCC(evtIdx)                       Dem_Manage.evtInfo.evtFdcCntMax_dcc[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_FDCCNTMAX_DCC(evtIdx, val)                  Dem_Manage.evtInfo.evtFdcCntMax_dcc[(evtIdx) - DEM_BYTE_ONE] = (sint8)(val)

#define DEM_GET_DEBTIMER_BUFFER(evtIdx)                     Dem_Manage.evtInfo.evtDebTimerSt[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_DEBTIMER_BUFFER(evtIdx, val)                Dem_Manage.evtInfo.evtDebTimerSt[(evtIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_DEBOUNCE_STATUS(evtIdx)                     Dem_Manage.evtInfo.evtDebSt[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_DEBOUNCE_STATUS(evtIdx, val)                Dem_Manage.evtInfo.evtDebSt[(evtIdx) - DEM_BYTE_ONE] = (val)

/* Macro about trigger init monitor. */
#define DEM_GET_MONITOR_REASON_REQ()                        Dem_Manage.evtInfo.evtMonitorReasonReq
#define DEM_SET_MONITOR_REASON_REQ(req)                     Dem_Manage.evtInfo.evtMonitorReasonReq = (req)

#define DEM_GET_MONITOR_REASON(evtIdx)                      Dem_Manage.evtInfo.evtMonitorReason[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_MONITOR_REASON(evtIdx, val)                 Dem_Manage.evtInfo.evtMonitorReason[(evtIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_INDICATOR(evtIdx, evtIndiIdx)               Dem_Manage.evtInfo.evtIndi[(evtIdx) - DEM_BYTE_ONE][(evtIndiIdx)]
#define DEM_SET_INDICATOR(evtIdx, evtIndiIdx, val)          Dem_Manage.evtInfo.evtIndi[(evtIdx) - DEM_BYTE_ONE][(evtIndiIdx)] = (val)

#define DEM_GET_INDICATOR_STATUS(indiIdx)                   Dem_Manage.evtInfo.indiStatus[(indiIdx) - DEM_BYTE_ONE]
#define DEM_SET_INDICATOR_STATUS(indiIdx, val)              Dem_Manage.evtInfo.indiStatus[(indiIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_INDICATOR_ON_CNT(indiIdx)                   Dem_Manage.evtInfo.indiActCnt[(indiIdx) - DEM_BYTE_ONE]
#define DEM_SET_INDICATOR_ON_CNT(indiIdx, val)              Dem_Manage.evtInfo.indiActCnt[(indiIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_DEBCNT(evtIdx)                              Dem_Manage.evtInfo.evtDebCnt[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_DEBCNT(evtIdx, val)                         Dem_Manage.evtInfo.evtDebCnt[(evtIdx) - DEM_BYTE_ONE] = (sint16)(val)

#define DEM_GET_DEBTIME(evtIdx)                             Dem_Manage.evtInfo.evtDebTime[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_DEBTIME(evtIdx, val)                        Dem_Manage.evtInfo.evtDebTime[(evtIdx) - DEM_BYTE_ONE] = (uint16)(val)

#define DEM_GET_SSDATA_BUFFER_CNT()                         Dem_Manage.evtInfo.ssDataBufCnt
#define DEM_SET_SSDATA_BUFFER_CNT(val)                      Dem_Manage.evtInfo.ssDataBufCnt = (val)

#define DEM_GET_SSDATA_FF_STORED(evtIdx)                    Dem_Manage.evtInfo.evtSsDataFfStored[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_SSDATA_FF_STORED(evtIdx, val)               Dem_Manage.evtInfo.evtSsDataFfStored[(evtIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_SSDATA_EX_STORED(evtIdx)                    Dem_Manage.evtInfo.evtSsDataExStored[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_SSDATA_EX_STORED(evtIdx, val)               Dem_Manage.evtInfo.evtSsDataExStored[(evtIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_SSDATA_OBD_STORED(evtIdx)                   Dem_Manage.evtInfo.evtSsDataObdStored[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_SSDATA_OBD_STORED(evtIdx, val)              Dem_Manage.evtInfo.evtSsDataObdStored[(evtIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_SSDATA_WWHOBD_STORED(evtIdx)                Dem_Manage.evtInfo.evtSsDataWwhObdStored[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_SSDATA_WWHOBD_STORED(evtIdx, val)           Dem_Manage.evtInfo.evtSsDataWwhObdStored[(evtIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_SSDATA_BUFFER_POS(evtIdx)                   Dem_Manage.evtInfo.evtSsDataBufPos[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_SSDATA_BUFFER_POS(evtIdx, val)              Dem_Manage.evtInfo.evtSsDataBufPos[(evtIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_SSDATA_FFDATA_BUF_PTR(pos, offset)          &(Dem_Manage.evtInfo.ssDataBuf[(pos)].ffData[(offset)])

#define DEM_GET_SSDATA_EXDATA_BUF_PTR(pos, offset)          &(Dem_Manage.evtInfo.ssDataBuf[(pos)].exData[(offset)])

#define DEM_GET_SSDATA_OBDFFDATA_BUF_PTR(pos, offset)       &(Dem_Manage.evtInfo.ssDataBuf[(pos)].obdffData[(offset)])

#define DEM_GET_SSDATA_WWHFFDATA_BUF_PTR(pos, offset)       &(Dem_Manage.evtInfo.ssDataBuf[(pos)].wwhObdData[(offset)])

#define DEM_GET_QUEUE_ST()                                  Dem_Manage.evtInfo.evtQue.evtQueSt
#define DEM_SET_QUEUE_ST(st)                                Dem_Manage.evtInfo.evtQue.evtQueSt = (st)

#define DEM_GET_QUEUE_UDS_STATUS(pos)                       Dem_Manage.evtInfo.evtQue.evtQueDtcSt[(pos)]
#define DEM_SET_QUEUE_UDS_STATUS(pos, val)                  Dem_Manage.evtInfo.evtQue.evtQueDtcSt[(pos)] = (val)

#define DEM_GET_QUEUE_POS()                                 Dem_Manage.evtInfo.evtQue.evtQuePos
#define DEM_SET_QUEUE_POS(pos)                              Dem_Manage.evtInfo.evtQue.evtQuePos = ((pos))

#define DEM_GET_QUEUE_BUF(pos)                              Dem_Manage.evtInfo.evtQue.evtQueBuf[(pos)]
#define DEM_SET_QUEUE_BUF(pos, val)                         Dem_Manage.evtInfo.evtQue.evtQueBuf[(pos)] = (val)

#define DEM_GET_COMP_AVAILABLE(compIdx)                     Dem_Manage.evtInfo.compSt.compAvailable[(compIdx) - DEM_BYTE_ONE]
#define DEM_SET_COMP_AVAILABLE(compIdx, val)                Dem_Manage.evtInfo.compSt.compAvailable[(compIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_COMP_FAILED_STATUS(compIdx)                 Dem_Manage.evtInfo.compSt.compFailedStatus[(compIdx) - DEM_BYTE_ONE]
#define DEM_SET_COMP_FAILED_STATUS(compIdx, val)            Dem_Manage.evtInfo.compSt.compFailedStatus[(compIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_COMP_FAILED_EVTIDX(compIdx)                 Dem_Manage.evtInfo.compSt.compFailedEvtIdx[(compIdx) - DEM_BYTE_ONE]
#define DEM_SET_COMP_FAILED_EVTIDX(compIdx, val)            Dem_Manage.evtInfo.compSt.compFailedEvtIdx[(compIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_OPCYC_REQ(opcycIdx)                         Dem_Manage.evtInfo.opcycReq.opcycReqFlg[(opcycIdx) - DEM_BYTE_ONE]
#define DEM_SET_OPCYC_REQ(opcycIdx, val)                    Dem_Manage.evtInfo.opcycReq.opcycReqFlg[(opcycIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_OPCYC_REQ_STATE(opcycIdx)                   Dem_Manage.evtInfo.opcycReq.opcycReqState[(opcycIdx) - DEM_BYTE_ONE]
#define DEM_SET_OPCYC_REQ_STATE(opcycIdx, val)              Dem_Manage.evtInfo.opcycReq.opcycReqState[(opcycIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_DTCCHANGEDNOTIF()                           Dem_Manage.evtInfo.evtDtcChangedNotification
#define DEM_SET_DTCCHANGEDNOTIF(val)                        Dem_Manage.evtInfo.evtDtcChangedNotification = (val)

#define DEM_GET_DTC_CLEAR_STATUS()                          Dem_Manage.evtInfo.dtcClearReq.dtcClearStatus
#define DEM_SET_DTC_CLEAR_STATUS(val)                       Dem_Manage.evtInfo.dtcClearReq.dtcClearStatus = (val)

#define DEM_GET_DTC_CLEAR_EVTMEMIDX()                       Dem_Manage.evtInfo.dtcClearReq.evtMemIdx
#define DEM_SET_DTC_CLEAR_EVTMEMIDX(val)                    Dem_Manage.evtInfo.dtcClearReq.evtMemIdx = (val)

#define DEM_GET_DTC_CLEAR_FORMAT()                          Dem_Manage.evtInfo.dtcClearReq.dtcFormat
#define DEM_SET_DTC_CLEAR_FORMAT(val)                       Dem_Manage.evtInfo.dtcClearReq.dtcFormat = (val)

#define DEM_GET_DTC_CLEAR_CLIENT()                          Dem_Manage.evtInfo.dtcClearReq.dtcClearClient
#define DEM_SET_DTC_CLEAR_CLIENT(val)                       Dem_Manage.evtInfo.dtcClearReq.dtcClearClient = (val)

#define DEM_GET_DTC_CLEAR_GRPIDX()                          Dem_Manage.evtInfo.dtcClearReq.dtcGrpIdx
#define DEM_SET_DTC_CLEAR_GRPIDX(val)                       Dem_Manage.evtInfo.dtcClearReq.dtcGrpIdx = (val)

#define DEM_GET_DTC_CLEAR_DTCVAL()                          Dem_Manage.evtInfo.dtcClearReq.dtcValue
#define DEM_SET_DTC_CLEAR_DTCVAL(val)                       Dem_Manage.evtInfo.dtcClearReq.dtcValue = (val)

#define DEM_GET_DTC_CLEAR_TYPE()                            Dem_Manage.evtInfo.dtcClearReq.dtcType
#define DEM_SET_DTC_CLEAR_TYPE(val)                         Dem_Manage.evtInfo.dtcClearReq.dtcType = (val)

#define DEM_GET_DTC_SETTING_DISABLE()                       Dem_Manage.evtInfo.dtcSettingDis.dtcSetDis
#define DEM_SET_DTC_SETTING_DISABLE(val)                    Dem_Manage.evtInfo.dtcSettingDis.dtcSetDis = (val)

#define DEM_GET_DTC_SETTING_ENABLE()                        Dem_Manage.evtInfo.dtcSettingDis.dtcSetEn
#define DEM_SET_DTC_SETTING_ENABLE(val)                     Dem_Manage.evtInfo.dtcSettingDis.dtcSetEn = (val)

#define DEM_GET_DTC_DISABLE_KIND()                          Dem_Manage.evtInfo.dtcSettingDis.dtcKind
#define DEM_SET_DTC_DISABLE_KIND(val)                       Dem_Manage.evtInfo.dtcSettingDis.dtcKind = (val)

#define DEM_GET_DTC_DISABLE_GROUP_IDX()                     Dem_Manage.evtInfo.dtcSettingDis.dtcGrpIdx
#define DEM_SET_DTC_DISABLE_GROUP_IDX(val)                  Dem_Manage.evtInfo.dtcSettingDis.dtcGrpIdx = (val)

#define DEM_GET_DTC_DISABLE_GROUP()                         Dem_Manage.evtInfo.dtcSettingDis.dtcGroup
#define DEM_SET_DTC_DISABLE_GROUP(val)                      Dem_Manage.evtInfo.dtcSettingDis.dtcGroup = (val)

#define DEM_GET_DTC_FILTER_ENABLE()                         Dem_Manage.evtInfo.dtcFilter.dtcFilterEn
#define DEM_SET_DTC_FILTER_ENABLE(val)                      Dem_Manage.evtInfo.dtcFilter.dtcFilterEn = (val)

#define DEM_GET_DTC_FILTERED(dtcIdx)                        Dem_Manage.evtInfo.dtcFilter.dtcFiltered[(dtcIdx) - DEM_BYTE_ONE]
#define DEM_SET_DTC_FILTERED(dtcIdx, val)                   Dem_Manage.evtInfo.dtcFilter.dtcFiltered[(dtcIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_DTC_FILTER_MASK()                           Dem_Manage.evtInfo.dtcFilter.dtcStsMask
#define DEM_SET_DTC_FILTER_MASK(val)                        Dem_Manage.evtInfo.dtcFilter.dtcStsMask = (val)

#define DEM_GET_DTC_FILTER_KIND()                           Dem_Manage.evtInfo.dtcFilter.dtcKind
#define DEM_SET_DTC_FILTER_KIND(val)                        Dem_Manage.evtInfo.dtcFilter.dtcKind = (val)

#define DEM_GET_DTC_FILTER_FORMAT()                         Dem_Manage.evtInfo.dtcFilter.dtcFormat
#define DEM_SET_DTC_FILTER_FORMAT(val)                      Dem_Manage.evtInfo.dtcFilter.dtcFormat = (val)

#define DEM_GET_DTC_FILTER_ORIGIN()                         Dem_Manage.evtInfo.dtcFilter.dtcOrigin
#define DEM_SET_DTC_FILTER_ORIGIN(val)                      Dem_Manage.evtInfo.dtcFilter.dtcOrigin = (val)

#define DEM_GET_DTC_FILTER_EVTMEMIDX()                      Dem_Manage.evtInfo.dtcFilter.dtcEvtMemIdx
#define DEM_SET_DTC_FILTER_EVTMEMIDX(val)                   Dem_Manage.evtInfo.dtcFilter.dtcEvtMemIdx = (val)

#define DEM_GET_DTC_FILTER_SEVERITY()                       Dem_Manage.evtInfo.dtcFilter.dtcFilterWithSevr
#define DEM_SET_DTC_FILTER_SEVERITY(val)                    Dem_Manage.evtInfo.dtcFilter.dtcFilterWithSevr = (val)

#define DEM_GET_DTC_FILTER_SEVERITY_MASK()                  Dem_Manage.evtInfo.dtcFilter.dtcSevrMask
#define DEM_SET_DTC_FILTER_SEVERITY_MASK(val)               Dem_Manage.evtInfo.dtcFilter.dtcSevrMask = (val)

#define DEM_GET_DTC_FILTER_FDC()                            Dem_Manage.evtInfo.dtcFilter.dtcFilterForFdc
#define DEM_SET_DTC_FILTER_FDC(val)                         Dem_Manage.evtInfo.dtcFilter.dtcFilterForFdc = (val)

#define DEM_GET_DTC_FILTER_SLOT_CNT()                       Dem_Manage.evtInfo.dtcFilter.dtcFilterSlotCnt
#define DEM_SET_DTC_FILTER_SLOT_CNT(val)                    Dem_Manage.evtInfo.dtcFilter.dtcFilterSlotCnt = (val)

#define DEM_GET_DTC_FILTER_MATCH_NUM()                      Dem_Manage.evtInfo.dtcFilter.dtcFilterMatchNum
#define DEM_SET_DTC_FILTER_MATCH_NUM(val)                   Dem_Manage.evtInfo.dtcFilter.dtcFilterMatchNum = (val)

#define DEM_GET_DTC_FILTER_MATCH_NEXT()                     Dem_Manage.evtInfo.dtcFilter.dtcFilterMatchNext
#define DEM_SET_DTC_FILTER_MATCH_NEXT(val)                  Dem_Manage.evtInfo.dtcFilter.dtcFilterMatchNext = (val)

#define DEM_GET_DTC_FILTER_MATCH_CNT()                      Dem_Manage.evtInfo.dtcFilter.dtcFilterMatchCnt
#define DEM_SET_DTC_FILTER_MATCH_CNT(val)                   Dem_Manage.evtInfo.dtcFilter.dtcFilterMatchCnt = (uint16)(val)

#define DEM_GET_DTC_FILTER_MATCH_NEXTIDX()                  Dem_Manage.evtInfo.dtcFilter.dtcFilterMatchNextIdx
#define DEM_SET_DTC_FILTER_MATCH_NEXTIDX(val)               Dem_Manage.evtInfo.dtcFilter.dtcFilterMatchNextIdx = (uint16)(val)

#define DEM_GET_DTC_FILTER_ALL_SUPPORTED()                  Dem_Manage.evtInfo.dtcFilter.dtcFilterAllSupported
#define DEM_SET_DTC_FILTER_ALL_SUPPORTED(val)               Dem_Manage.evtInfo.dtcFilter.dtcFilterAllSupported = (val)

#define DEM_GET_FF_FILTER_ENABLE()                          Dem_Manage.evtInfo.dtcFilter.dtcFreezeFrameFilterEn
#define DEM_SET_FF_FILTER_ENABLE(val)                       Dem_Manage.evtInfo.dtcFilter.dtcFreezeFrameFilterEn = (val)

#define DEM_GET_FF_FILTER_SLOT_CNT()                        Dem_Manage.evtInfo.dtcFilter.ffFilterSlotCnt
#define DEM_SET_FF_FILTER_SLOT_CNT(val)                     Dem_Manage.evtInfo.dtcFilter.ffFilterSlotCnt = (val)

#define DEM_GET_FF_FILTER_FORMAT()                          Dem_Manage.evtInfo.dtcFilter.ffFormat
#define DEM_SET_FF_FILTER_FORMAT(val)                       Dem_Manage.evtInfo.dtcFilter.ffFormat = (val)

#define DEM_GET_FF_FILTER_MATCH_NEXT()                      Dem_Manage.evtInfo.dtcFilter.ffFilterMatchNext
#define DEM_SET_FF_FILTER_MATCH_NEXT(val)                   Dem_Manage.evtInfo.dtcFilter.ffFilterMatchNext= (val)

#define DEM_GET_FF_FILTER_MATCH_NEXT_IDX()                  Dem_Manage.evtInfo.dtcFilter.ffFilterMatchNextRecIdx
#define DEM_SET_FF_FILTER_MATCH_NEXT_IDX(val)               Dem_Manage.evtInfo.dtcFilter.ffFilterMatchNextRecIdx = (val)

#define DEM_GET_DTC_RECORD_ENABLE()                         Dem_Manage.evtInfo.dtcRecEn.dtcRecEnable
#define DEM_SET_DTC_RECORD_ENABLE(val)                      Dem_Manage.evtInfo.dtcRecEn.dtcRecEnable = (val)

#define DEM_GET_DTC_RECORD_ENABLE_DTC()                     Dem_Manage.evtInfo.dtcRecEn.dtcVal
#define DEM_SET_DTC_RECORD_ENABLE_DTC(val)                  Dem_Manage.evtInfo.dtcRecEn.dtcVal = (val)

#define DEM_GET_DTC_RECORD_ENABLE_EMIDX()                   Dem_Manage.evtInfo.dtcRecEn.dtcEvtMemIdx
#define DEM_SET_DTC_RECORD_ENABLE_EMIDX(val)                Dem_Manage.evtInfo.dtcRecEn.dtcEvtMemIdx = (val)

#define DEM_GET_OPCYC_STATE(opcycIdx)                       Dem_EventMemoryStatus.evtOpCycSt[(opcycIdx) - DEM_BYTE_ONE]
#define DEM_SET_OPCYC_STATE(opcycIdx, val)                  Dem_EventMemoryStatus.evtOpCycSt[(opcycIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_UDS_STATUS(evtIdx)                          Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_UDS_STATUS(evtIdx, val)                     Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_STATUS_INDI(evtIdx)                         Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_STATUS_INDI(evtIdx, val)                    Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_UDS_FAILED_CNT(evtIdx)                      Dem_EventMemoryStatus.evtFailedCnt[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_UDS_FAILED_CNT(evtIdx, val)                 Dem_EventMemoryStatus.evtFailedCnt[(evtIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_LAMP_FAILED_CNT(evtIdx, indiIdx)            Dem_EventMemoryStatus.evtLampFailedCnt[(evtIdx) - DEM_BYTE_ONE][(indiIdx)]
#define DEM_SET_LAMP_FAILED_CNT(evtIdx, indiIdx, val)       Dem_EventMemoryStatus.evtLampFailedCnt[(evtIdx) - DEM_BYTE_ONE][(indiIdx)] = (val)

#define DEM_GET_FDCCNTMAX_SLC(evtIdx)                       Dem_EventMemoryStatus.evtFdcCntMax_slc[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_FDCCNTMAX_SLC(evtIdx, val)                  Dem_EventMemoryStatus.evtFdcCntMax_slc[(evtIdx) - DEM_BYTE_ONE] = (sint8)(val)

#define DEM_GET_STORED_DEBCNT(evtIdx)                       Dem_EventMemoryStatus.evtDebCnt[(evtIdx) - DEM_BYTE_ONE]
/* PolySpace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
#define DEM_SET_STORED_DEBCNT(evtIdx, val)                  Dem_EventMemoryStatus.evtDebCnt[(evtIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_AGED_CNT(evtIdx)                            Dem_EventMemoryStatus.evtAgedCnt[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_AGED_CNT(evtIdx, val)                       Dem_EventMemoryStatus.evtAgedCnt[(evtIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_AGED_CNT2(evtIdx)                           Dem_EventMemoryStatus.evtAgedCnt2[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_AGED_CNT2(evtIdx, val)                      Dem_EventMemoryStatus.evtAgedCnt2[(evtIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_UDS_STATUS_TF(evtIdx)                       (Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_DTC_STATUS_TF)
#define DEM_SET_UDS_STATUS_TF(evtIdx)                       Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_DTC_STATUS_TF
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_UDS_STATUS_TF(evtIdx)                     Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_DTC_STATUS_TF)

#define DEM_GET_UDS_STATUS_TFTOC(evtIdx)                    ((Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_DTC_STATUS_TFTOC) >> DEM_BYTE_ONE)
#define DEM_SET_UDS_STATUS_TFTOC(evtIdx)                    Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_DTC_STATUS_TFTOC
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_UDS_STATUS_TFTOC(evtIdx)                  Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_DTC_STATUS_TFTOC)

#define DEM_GET_UDS_STATUS_PDTC(evtIdx)                     ((Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_DTC_STATUS_PDTC) >> DEM_BYTE_TWO)
#define DEM_SET_UDS_STATUS_PDTC(evtIdx)                     Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_DTC_STATUS_PDTC
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_UDS_STATUS_PDTC(evtIdx)                   Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_DTC_STATUS_PDTC)

#define DEM_GET_UDS_STATUS_CDTC(evtIdx)                     ((Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_DTC_STATUS_CDTC)  >> DEM_BYTE_THREE)
#define DEM_SET_UDS_STATUS_CDTC(evtIdx)                     Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_DTC_STATUS_CDTC
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_UDS_STATUS_CDTC(evtIdx)                   Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_DTC_STATUS_CDTC)

#define DEM_GET_UDS_STATUS_TNCSLC(evtIdx)                   ((Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_DTC_STATUS_TNCSLC) >> DEM_BYTE_FOUR)
#define DEM_SET_UDS_STATUS_TNCSLC(evtIdx)                   Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_DTC_STATUS_TNCSLC
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_UDS_STATUS_TNCSLC(evtIdx)                 Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_DTC_STATUS_TNCSLC)

#define DEM_GET_UDS_STATUS_TFSLC(evtIdx)                    ((Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_DTC_STATUS_TFSLC) >> DEM_BYTE_FIVE)
#define DEM_SET_UDS_STATUS_TFSLC(evtIdx)                    Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_DTC_STATUS_TFSLC
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_UDS_STATUS_TFSLC(evtIdx)                  Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_DTC_STATUS_TFSLC)

#define DEM_GET_UDS_STATUS_TNCTOC(evtIdx)                   ((Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_DTC_STATUS_TNCTOC) >> DEM_BYTE_SIX)
#define DEM_SET_UDS_STATUS_TNCTOC(evtIdx)                   Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_DTC_STATUS_TNCTOC
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_UDS_STATUS_TNCTOC(evtIdx)                 Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_DTC_STATUS_TNCTOC)

#define DEM_GET_UDS_STATUS_WIR(evtIdx)                      ((Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_DTC_STATUS_WIR) >> DEM_BYTE_SEVEN)
#define DEM_SET_UDS_STATUS_WIR(evtIdx)                      Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_DTC_STATUS_WIR
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_UDS_STATUS_WIR(evtIdx)                    Dem_EventMemoryStatus.evtDtcSt[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_DTC_STATUS_WIR)

#define DEM_GET_STATUS_INDI_UC(evtIdx)                      (Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_EXTEND_STATUS_UC)
#define DEM_SET_STATUS_INDI_UC(evtIdx)                      Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_EXTEND_STATUS_UC
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_STATUS_INDI_UC(evtIdx)                    Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_EXTEND_STATUS_UC)

#define DEM_GET_STATUS_INDI_UCTOC(evtIdx)                   ((Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_EXTEND_STATUS_UCTOC) >> DEM_BYTE_ONE)
#define DEM_SET_STATUS_INDI_UCTOC(evtIdx)                   Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_EXTEND_STATUS_UCTOC
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_STATUS_INDI_UCTOC(evtIdx)                 Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_EXTEND_STATUS_UCTOC)

#define DEM_GET_STATUS_INDI_UCSLC(evtIdx)                   ((Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_EXTEND_STATUS_UCSLC) >> DEM_BYTE_TWO)
#define DEM_SET_STATUS_INDI_UCSLC(evtIdx)                   Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_EXTEND_STATUS_UCSLC
#define DEM_RESET_STATUS_INDI_UCSLC(evtIdx)                 Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_EXTEND_STATUS_UCSLC)

#define DEM_GET_STATUS_INDI_AGED(evtIdx)                    ((Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_EXTEND_STATUS_AGED) >> DEM_BYTE_THREE)
#define DEM_SET_STATUS_INDI_AGED(evtIdx)                    Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_EXTEND_STATUS_AGED
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_STATUS_INDI_AGED(evtIdx)                  Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_EXTEND_STATUS_AGED)

#define DEM_GET_STATUS_INDI_SSLC(evtIdx)                    ((Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_EXTEND_STATUS_SSLC) >> DEM_BYTE_FOUR)
#define DEM_SET_STATUS_INDI_SSLC(evtIdx)                    Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_EXTEND_STATUS_SSLC
#define DEM_RESET_STATUS_INDI_SSLC(evtIdx)                  Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_EXTEND_STATUS_SSLC)

#define DEM_GET_STATUS_INDI_WIRSLC(evtIdx)                  ((Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_EXTEND_STATUS_WIRSLC) >> DEM_BYTE_FIVE)
#define DEM_SET_STATUS_INDI_WIRSLC(evtIdx)                  Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_EXTEND_STATUS_WIRSLC
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_STATUS_INDI_WIRSLC(evtIdx)                Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_EXTEND_STATUS_WIRSLC)

#define DEM_GET_STATUS_INDI_EMR(evtIdx)                     ((Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_EXTEND_STATUS_EMR) >> DEM_BYTE_SIX)
#define DEM_SET_STATUS_INDI_EMR(evtIdx)                     Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_EXTEND_STATUS_EMR
#define DEM_RESET_STATUS_INDI_EMR(evtIdx)                   Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_EXTEND_STATUS_EMR)

#define DEM_GET_STATUS_INDI_TFSLR(evtIdx)                   ((Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] & DEM_EVENT_EXTEND_STATUS_TFSLR) >> DEM_BYTE_SEVEN)
#define DEM_SET_STATUS_INDI_TFSLR(evtIdx)                   Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] |= DEM_EVENT_EXTEND_STATUS_TFSLR
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_STATUS_INDI_TFSLR(evtIdx)                 Dem_EventMemoryStatus.evtDtcStIndi[(evtIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_EVENT_EXTEND_STATUS_TFSLR)

#define DEM_GET_OBD_IUPR_CYCLE_FLAG()                       Dem_Manage.obdInfo.iuprCycFlag
#define DEM_SET_OBD_IUPR_CYCLE_FLAG(val)                    Dem_Manage.obdInfo.iuprCycFlag = (val)

#define DEM_GET_OBD_PFC_CYCLE_QUALIFIED()                   Dem_Manage.obdInfo.pfcCycQuali
#define DEM_SET_OBD_PFC_CYCLE_QUALIFIED(val)                Dem_Manage.obdInfo.pfcCycQuali = (val)

#define DEM_GET_OBD_IUPR_PTO_STATUS()                       Dem_Manage.obdInfo.ptoStatus
#define DEM_SET_OBD_IUPR_PTO_STATUS(val)                    Dem_Manage.obdInfo.ptoStatus = (val)

/* The opearation of getting and setting the counter of warm-up cycle counter. */
#define DEM_GET_OBD_WARMUP_CYCLE_CNT_SINCELASTINIT()        Dem_Manage.obdInfo.warmUpCycleCntSinceLastInit
#define DEM_SET_OBD_WARMUP_CYCLE_CNT_SINCELASTINIT(val)     Dem_Manage.obdInfo.warmUpCycleCntSinceLastInit = (val)

/* The opearation of getting and setting the counter of warm-up cycle counter during the last driving cycle. */
#define DEM_GET_OBD_WUC_STARTED_LAST_DRICYC()               Dem_Manage.obdInfo.wuCycFlagDuringlastDrvCyc
#define DEM_SET_OBD_WUC_STARTED_LAST_DRICYC(val)            Dem_Manage.obdInfo.wuCycFlagDuringlastDrvCyc = (val)
#define DEM_GET_OBD_PID04_VALUE()                           Dem_Manage.obdInfo.valOfPid04
#define DEM_SET_OBD_PID04_VALUE(val)                        Dem_Manage.obdInfo.valOfPid04 = (val)

#define DEM_GET_OBD_IUPR_CALC_GEN_DEN()                     (Dem_Manage.obdInfo.generalDenoCalcState & DEM_BYTE_MASK_BIT0)
#define DEM_SET_OBD_IUPR_CALC_GEN_DEN()                     Dem_Manage.obdInfo.generalDenoCalcState |= DEM_BYTE_MASK_BIT0
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_OBD_IUPR_CALC_GEN_DEN()                   Dem_Manage.obdInfo.generalDenoCalcState &= (uint8)(~(uint8)DEM_BYTE_MASK_BIT0)

#define DEM_GET_OBD_IUPR_CALC_NUM(ratioIdx)                 (Dem_Manage.obdInfo.iuprCalcState[(ratioIdx) - DEM_BYTE_ONE] & DEM_BYTE_MASK_BIT0)
#define DEM_SET_OBD_IUPR_CALC_NUM(ratioIdx)                 Dem_Manage.obdInfo.iuprCalcState[(ratioIdx) - DEM_BYTE_ONE] |= DEM_BYTE_MASK_BIT0
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_OBD_IUPR_CALC_NUM(ratioIdx)               Dem_Manage.obdInfo.iuprCalcState[(ratioIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_BYTE_MASK_BIT0)

#define DEM_GET_OBD_IUPR_CALC_DEN(ratioIdx)                 ((Dem_Manage.obdInfo.iuprCalcState[(ratioIdx) - DEM_BYTE_ONE] & DEM_BYTE_MASK_BIT1) >> DEM_BYTE_ONE)
#define DEM_SET_OBD_IUPR_CALC_DEN(ratioIdx)                 Dem_Manage.obdInfo.iuprCalcState[(ratioIdx) - DEM_BYTE_ONE] |= DEM_BYTE_MASK_BIT1
/* Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_Dem_UnsignedIntegerConstantOverflow" */
#define DEM_RESET_OBD_IUPR_CALC_DEN(ratioIdx)               Dem_Manage.obdInfo.iuprCalcState[(ratioIdx) - DEM_BYTE_ONE] &= (uint8)(~(uint8)DEM_BYTE_MASK_BIT1)

#define DEM_GET_OBD_IUPR_NUM_COND_ASYM(ratioIdx)            Dem_Manage.obdInfo.iuprNumCondiForAsymEvent[(ratioIdx) - DEM_BYTE_ONE]
#define DEM_SET_OBD_IUPR_NUM_COND_ASYM(ratioIdx, val)       Dem_Manage.obdInfo.iuprNumCondiForAsymEvent[(ratioIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_OBD_IUPR_DEN_COND(conditionId)              Dem_Manage.obdInfo.iuprDenCondition[(conditionId) - DEM_BYTE_ONE]
#define DEM_SET_OBD_IUPR_DEN_COND(conditionId, val)         Dem_Manage.obdInfo.iuprDenCondition[(conditionId) - DEM_BYTE_ONE] = (val)

#define DEM_GET_OBD_IUPR_DEN_PHSY_COND(ratioIdx)            Dem_Manage.obdInfo.iuprDenPhsyCondition[(ratioIdx) - DEM_BYTE_ONE]
#define DEM_SET_OBD_IUPR_DEN_PHSY_COND(ratioIdx, val)       Dem_Manage.obdInfo.iuprDenPhsyCondition[(ratioIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_OBD_EVENT_DISABLE_PID41(evtIdx)             Dem_Manage.obdInfo.evtDisableFor41[(evtIdx) - DEM_BYTE_ONE]
#define DEM_SET_OBD_EVENT_DISABLE_PID41(evtIdx, val)        Dem_Manage.obdInfo.evtDisableFor41[(evtIdx) - DEM_BYTE_ONE] = (val)

#define DEM_GET_WWH_ACT_MODE()                              Dem_Manage.obdInfo.wwhActMode
#define DEM_SET_WWH_ACT_MODE(val)                           Dem_Manage.obdInfo.wwhActMode = (val)

#define DEM_GET_WWH_CONTIMI_DET()                           Dem_Manage.obdInfo.wwhContiMiDetect
#define DEM_SET_WWH_CONTIMI_DET(val)                        Dem_Manage.obdInfo.wwhContiMiDetect = (val)

#define DEM_GET_WWH_CONTIMIOFFCNT_ST()                      Dem_Manage.obdInfo.wwhContiMiOffCntStartTime
#define DEM_SET_WWH_CONTIMIOFFCNT_ST(val)                   Dem_Manage.obdInfo.wwhContiMiOffCntStartTime = (val)

#define DEM_GET_WWH_CONTIMICNT_ST()                         Dem_Manage.obdInfo.wwhContiMiCntStartTime
#define DEM_SET_WWH_CONTIMICNT_ST(val)                      Dem_Manage.obdInfo.wwhContiMiCntStartTime = (val)

#define DEM_GET_WWH_CUMUCONTIMICNT_ST()                     Dem_Manage.obdInfo.wwhCumuContiMiCntStartTime
#define DEM_SET_WWH_CUMUCONTIMICNT_ST(val)                  Dem_Manage.obdInfo.wwhCumuContiMiCntStartTime = (val)

#define DEM_GET_WWH_B1EVENT_DETECT()                        Dem_Manage.obdInfo.wwhB1EventDetect
#define DEM_SET_WWH_B1EVENT_DETECT(val)                     Dem_Manage.obdInfo.wwhB1EventDetect = (val)

#define DEM_GET_WWH_B1COUNTER_ST()                          Dem_Manage.obdInfo.wwhB1CntStartTime
#define DEM_SET_WWH_B1COUNTER_ST(val)                       Dem_Manage.obdInfo.wwhB1CntStartTime = (val)

#define DEM_GET_WWH_AGING_ST(idx)                           Dem_Manage.obdInfo.wwhDtcAgingStartTime[(idx)]
#define DEM_SET_WWH_AGING_ST(idx, val)                      Dem_Manage.obdInfo.wwhDtcAgingStartTime[(idx)] = (val)

#define DEM_GET_OBD_PID42_VALUE()                           Dem_Manage.obdInfo.valOfPid42
#define DEM_SET_OBD_PID42_VALUE(val)                        Dem_Manage.obdInfo.valOfPid42 = (val)

#define DEM_GET_OBD_PID29_VALUE()                           Dem_Manage.obdInfo.valOfPid29
#define DEM_SET_OBD_PID29_VALUE(val)                        Dem_Manage.obdInfo.valOfPid29 = (val)

#define DEM_GET_OBD_DTR_RESULT(dtrIdx)                      Dem_Manage.obdInfo.dtrData[(dtrIdx) - DEM_BYTE_ONE].dtrTestRes
#define DEM_SET_OBD_DTR_RESULT(dtrIdx, val)                 Dem_Manage.obdInfo.dtrData[(dtrIdx) - DEM_BYTE_ONE].dtrTestRes = (val)

#define DEM_GET_OBD_DTR_LOWERLIMIT(dtrIdx)                  Dem_Manage.obdInfo.dtrData[(dtrIdx) - DEM_BYTE_ONE].dtrLowerLimit
#define DEM_SET_OBD_DTR_LOWERLIMIT(dtrIdx, val)             Dem_Manage.obdInfo.dtrData[(dtrIdx) - DEM_BYTE_ONE].dtrLowerLimit = (val)

#define DEM_GET_OBD_DTR_UPPERLIMIT(dtrIdx)                  Dem_Manage.obdInfo.dtrData[(dtrIdx) - DEM_BYTE_ONE].dtrUpperLimit
#define DEM_SET_OBD_DTR_UPPERLIMIT(dtrIdx, val)             Dem_Manage.obdInfo.dtrData[(dtrIdx) - DEM_BYTE_ONE].dtrUpperLimit = (val)

/* Macros about event availability processing split. */
#define DEM_GET_EVTAVAIL_SPLIT_CNT()                        Dem_Manage.evtInfo.evtAvailSplitCnt
#define DEM_SET_EVTAVAIL_SPLIT_CNT(val)                     Dem_Manage.evtInfo.evtAvailSplitCnt = (val)

/* Macros definition for fault memory access. */
#define DEM_GET_EVENT_MEMORY_STATUS_PTR()                   &Dem_EventMemoryStatus
#define DEM_GET_EVENT_MEMORY_INFO_PTR(evtMemIdx)            Dem_EventMemoryInfo[(evtMemIdx) - DEM_BYTE_ONE]
#define DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx)           Dem_EventMemoryEntry[(evtMemIdx) - DEM_BYTE_ONE]
#define DEM_GET_EVENT_MEMORY_PERMANENT_PTR()                &Dem_PermanentEventMemoryEntry

/* Immediate store NvM configuration value. */
#define DEM_IMMEDIATE_STORE_NVM(evtIdx)                     Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acImdiStor

/* Dummy function. */
#ifndef DEM_DUMMY_STATEMENT
/* PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
#define DEM_DUMMY_STATEMENT(v) (v)=(v)
#endif

/* Status of Clear DTC */
#define DEM_EVENT_CLEAR_DTC_STATUS_IDLE                     (0U)
#define DEM_EVENT_CLEAR_DTC_STATUS_PENDING                  (1U)
#define DEM_EVENT_CLEAR_DTC_STATUS_COMPLETE                 (2U)
#define DEM_EVENT_CLEAR_DTC_STATUS_STORING                  (3U)

#define DEM_IMMEDIATE_STORE_ALL_EVENT_STATUS
#define DEM_EVENT_DTC_GROUP_ALL                             ((uint32)(0x00FFFFFFUL))

/* State of Dem memory process */
#define DEM_NVM_STATE_IDLE                                  (0U)
#define DEM_NVM_STATE_READ                                  (1U)
#define DEM_NVM_STATE_CLEAR                                 (2U)
#define DEM_NVM_STATE_WRITE                                 (3U)
#define DEM_NVM_STATE_READ_CHECK                            (4U)
#define DEM_NVM_STATE_CLEAR_CHECK                           (5U)
#define DEM_NVM_STATE_WRITE_CHECK                           (6U)
#define DEM_NVM_STATE_INITIAL                               (7U)
#define DEM_NVM_STATE_FAILED                                (8U)
#define DEM_NVM_STATE_INVALIDATED                           (9U)
#define DEM_NVM_STATE_DONE                                  (10U)

#define DEM_NVM_REQ_NONE                                    (0U)
#define DEM_NVM_REQ_READ                                    (1U)
#define DEM_NVM_REQ_CLEAR                                   (2U)
#define DEM_NVM_REQ_WRITE                                   (3U)

#define DEM_NVM_BLOCK_STATUS_NO_ERROR                       (0U)
#define DEM_NVM_BLOCK_STATUS_ERROR                          (1U)

#define DEM_NVM_REQ_OK                                      NVM_REQ_OK
#define DEM_NVM_REQ_NOT_OK                                  NVM_REQ_NOT_OK
#define DEM_NVM_REQ_PENDING                                 NVM_REQ_PENDING
#define DEM_NVM_REQ_INVALIDATED                             NVM_REQ_NV_INVALIDATED

#define DEM_NVM_STATUS_BLOCK                                (0xFFU)
#define DEM_NVM_INFO_BLOCK                                  (0xFEU)
#define DEM_NVM_PERMANET_BLOCK                              (0xFDU)

/* OBD related */
#define DEM_OBD_PFC_HANDLE_CLEAR_ALL                        (1U)
#define DEM_OBD_PFC_HANDLE_CLEAR                            (2U)
#define DEM_OBD_PFC_HANDLE_ALLOCATE                         (3U)

#define DEM_OBD_WWH_ACTIVATION_MODE_1                       (1U)
#define DEM_OBD_WWH_ACTIVATION_MODE_2                       (2U)
#define DEM_OBD_WWH_ACTIVATION_MODE_3                       (3U)
#define DEM_OBD_WWH_ACTIVATION_MODE_4                       (4U)

#if (DEM_CFG_CALIBSUPPORT == STD_ON)
#define DEM_DTCVALUE_CAL(i)                                 (*Dem_CfgUdsDtcValue[i])
#define DEM_EVTAVAIL_CAL(i)                                 (*Dem_CfgEvtAvail[i])
#define DEM_DEBCNTFAILTHRS_CAL(i)                           (*Dem_CfgDebCntFailThrs[i])
#define DEM_DEBCNTPASSTHRS_CAL(i)                           (*Dem_CfgDebCntPassThrs[i])
#define DEM_DEBCNTINCSTEPSIZE_CAL(i)                        (*Dem_CfgDebCntIncStepSize[i])
#define DEM_DEBCNTDECSTEPSIZE_CAL(i)                        (*Dem_CfgDebCntDecStepSize[i])
#define DEM_DEBCNTJUEN_CAL(i)                               (*Dem_CfgDebCntJuEn[i])
#define DEM_DEBCNTJDEN_CAL(i)                               (*Dem_CfgDebCntJdEn[i])
#define DEM_DEBCNTJUVAL_CAL(i)                              (*Dem_CfgDebCntJuVal[i])
#define DEM_DEBCNTJDVAL_CAL(i)                              (*Dem_CfgDebCntJdVal[i])
#define DEM_ENABLECOND_CAL(i)                               (*Dem_CfgEnableCond[i])
#else
#define DEM_DTCVALUE_CAL(i)                                 (Dem_CfgUdsDtcValue[i])
#define DEM_EVTAVAIL_CAL(i)                                 (Dem_CfgEvtAvail[i])
#define DEM_DEBCNTFAILTHRS_CAL(i)                           (Dem_CfgDebCntFailThrs[i])
#define DEM_DEBCNTPASSTHRS_CAL(i)                           (Dem_CfgDebCntPassThrs[i])
#define DEM_DEBCNTINCSTEPSIZE_CAL(i)                        (Dem_CfgDebCntIncStepSize[i])
#define DEM_DEBCNTDECSTEPSIZE_CAL(i)                        (Dem_CfgDebCntDecStepSize[i])
#define DEM_DEBCNTJUEN_CAL(i)                               (Dem_CfgDebCntJuEn[i])
#define DEM_DEBCNTJDEN_CAL(i)                               (Dem_CfgDebCntJdEn[i])
#define DEM_DEBCNTJUVAL_CAL(i)                              (Dem_CfgDebCntJuVal[i])
#define DEM_DEBCNTJDVAL_CAL(i)                              (Dem_CfgDebCntJdVal[i])
#define DEM_ENABLECOND_CAL(i)                               (Dem_CfgEnableCond[i])
#endif

#if( DEM_CFG_J1939SUPPORT == STD_ON )
/*J193DTC Filter*/
#define DEM_GET_J1939_DTC_FILTER_ENABLE()                    Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcEnable
#define DEM_SET_J1939_DTC_FILTER_ENABLE(val)                 Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcEnable = (val)

#define DEM_SET_J1939_DTC_FILTER_MASK(val)                   Dem_Manage.evtInfo.j1939DtcFilter.dtcStatusFilter = (val)
#define DEM_GET_J1939_DTC_FILTER_MASK()                      Dem_Manage.evtInfo.j1939DtcFilter.dtcStatusFilter

#define DEM_SET_J1939_DTC_NODE(val)                          Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcNode = (val)
#define DEM_GET_J1939_DTC_NODE()                             Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcNode

#define DEM_GET_J1939_DTC_FILTER_MATCH_NUM()                 Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcFilterMatchNum
#define DEM_SET_J1939_DTC_FILTER_MATCH_NUM(val)              Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcFilterMatchNum = (val)

#define DEM_GET_J1939_DTC_FILTER_KIND()                      Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcKind
#define DEM_SET_J1939_DTC_FILTER_KIND(val)                   Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcKind = (val)

#define DEM_GET_J1939_DTC_FILTER_FORMAT()                    Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcFormat
#define DEM_SET_J1939_DTC_FILTER_FORMAT(val)                 Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcFormat = (val)

#define DEM_GET_J1939_DTC_FILTER_MATCH_NEXT()                Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcFilterMatchNext
#define DEM_SET_J1939_DTC_FILTER_MATCH_NEXT(val)             Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcFilterMatchNext = (val)

#define DEM_GET_J1939_DTC_FILTER_MATCH_CNT()                 Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcFilterMatchCnt
#define DEM_SET_J1939_DTC_FILTER_MATCH_CNT(val)              Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcFilterMatchCnt = (val)

#define DEM_GET_J1939_DTC_FILTER_MATCH_NEXTIDX()             Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcFilterMatchNextIdx
#define DEM_SET_J1939_DTC_FILTER_MATCH_NEXTIDX(val)          Dem_Manage.evtInfo.j1939DtcFilter.j1939DtcFilterMatchNextIdx = (uint16)(val)

/* DM31 */
#define DEM_GET_DM31_FILTER_ENABLE()                         Dem_Manage.evtInfo.dm31Filter.dm31Enable
#define DEM_SET_DM31_FILTER_ENABLE(val)                      Dem_Manage.evtInfo.dm31Filter.dm31Enable = (val)

#define DEM_GET_DM31_FILTER_MATCH_CNT()                      Dem_Manage.evtInfo.dm31Filter.dm31FilterMatchCnt
#define DEM_SET_DM31_FILTER_MATCH_CNT(val)                   Dem_Manage.evtInfo.dm31Filter.dm31FilterMatchCnt = (val)

#define DEM_GET_DM31_FILTER_MATCH_NEXT()                     Dem_Manage.evtInfo.dm31Filter.dm31FilterMatchNext
#define DEM_SET_DM31_FILTER_MATCH_NEXT(val)                  Dem_Manage.evtInfo.dm31Filter.dm31FilterMatchNext = (val)

#define DEM_GET_DM31_J1939_NODE()                            Dem_Manage.evtInfo.dm31Filter.j1939Node
#define DEM_SET_DM31_J1939_NODE(val)                         Dem_Manage.evtInfo.dm31Filter.j1939Node = (val)

#define DEM_GET_DM31_FILTER_MATCH_NEXTIDX()                  Dem_Manage.evtInfo.dm31Filter.dm31FilterMatchNextIdx
#define DEM_SET_DM31_FILTER_MATCH_NEXTIDX(val)               Dem_Manage.evtInfo.dm31Filter.dm31FilterMatchNextIdx = (uint16)(val)
#endif

/* Dem Operation Cycle queue. */
#define DEM_GET_OPCYC_QUEUE_ST()                             Dem_Manage.evtInfo.opCycQue.OpCycQueSt
#define DEM_SET_OPCYC_QUEUE_ST(st)                           Dem_Manage.evtInfo.opCycQue.OpCycQueSt = (st)

#define DEM_GET_OPCYC_QUEUE_REQ_STATUS(pos)                  Dem_Manage.evtInfo.opCycQue.OpCycQueReqSt[(pos)]
#define DEM_SET_OPCYC_QUEUE_REQ_STATUS(pos, val)             Dem_Manage.evtInfo.opCycQue.OpCycQueReqSt[(pos)] = (val)

#define DEM_GET_OPCYC_QUEUE_POS()                            Dem_Manage.evtInfo.opCycQue.OpCycQuePos
#define DEM_SET_OPCYC_QUEUE_POS(pos)                         Dem_Manage.evtInfo.opCycQue.OpCycQuePos = (pos)

#define DEM_GET_OPCYC_QUEUE_REQ_IDX(pos)                     Dem_Manage.evtInfo.opCycQue.OpCycQueBuf[(pos)]
#define DEM_SET_OPCYC_QUEUE_REQ_IDX(pos, val)                Dem_Manage.evtInfo.opCycQue.OpCycQueBuf[(pos)] = (val)

/* Record the DTC index of diagnostic service process. */
#define DEM_GET_DIAG_PROC_DTC_IDX()                          Dem_DiagProcDTCIdx
#define DEM_SET_DIAG_PROC_DTC_IDX(val)                       Dem_DiagProcDTCIdx = (val)

/* polyspace-end MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Dem_2.5" */
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
#define DEM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
extern FUNC(void, DEM_CODE) Dem_OperCycleEnterQueue
(
    uint8 opcyIdx,
    uint8 opcycReqState
);
extern FUNC(void, DEM_CODE) Dem_OperCycleLeaveQueue(void);
extern FUNC(void, DEM_CODE) Dem_EventPreInit(void);
extern FUNC(void, DEM_CODE) Dem_EventEnCondInit(void);
extern FUNC(void, DEM_CODE) Dem_EventStorCondInit(void);
extern FUNC(void, DEM_CODE) Dem_EventDtcCtrlInit(void);
extern FUNC(void, DEM_CODE) Dem_EventManageCtrlInit(void);
extern FUNC(void, DEM_CODE) Dem_EventNvmBlockInit(void);
extern FUNC(void, DEM_CODE) Dem_EventIndicatorInit(void);
extern FUNC(void, DEM_CODE) Dem_EventOperCycleInit(void);
extern FUNC(void, DEM_CODE) Dem_EventOperCycleDeInit(void);
extern FUNC(void, DEM_CODE) Dem_EventOperCycleReInit
(
    uint16 EventIdx
);
extern FUNC(void, DEM_CODE) Dem_EventOperCycleReqHandle(void);
extern FUNC(void, DEM_CODE) Dem_EventOperCycleProcess(void);
extern FUNC(void, DEM_CODE) Dem_EventOperCycleStart
(
    uint16 EventIdx,
    uint8 OpcycId
);
extern FUNC(void, DEM_CODE) Dem_EventOperCycleEnd
(
    uint16 EventIdx,
    uint8 OpcycId
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventReportBeforeInit
(
    uint16 EventIdx, 
    Dem_EventStatusType EventStatus
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventReportAfterInit
(
    uint16 EventIdx,
    Dem_EventStatusType EventStatus
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventStatusReport
(
    uint16 EventIdx, 
    Dem_EventStatusType EventStatus
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventQueueEnter
(
    uint16 EventIdx,
    uint16 evtDtcSt
);
extern FUNC(uint8, DEM_CODE) Dem_EventQueueExist
(
    uint16 EventIdx,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) EventPos
);
extern FUNC(void, DEM_CODE) Dem_EventQueueProcBSW(void);
extern FUNC(void, DEM_CODE) Dem_EventQueueProcess(void);
extern FUNC(void, DEM_CODE) Dem_EventProcStatusByte
(
    uint16 EventIdx
);
extern FUNC(void, DEM_CODE) Dem_EventProcMemEntryAsFail
(
    uint16 EventIdx,
    uint8 EventStatusOld
);
extern FUNC(uint8, DEM_CODE) Dem_EventProcMemEntryAsNew
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) EntryIdx
);
extern FUNC(void, DEM_CODE) Dem_EventProcMemEntryAsPass
(
    uint16 EventIdx,
    uint8 EventStatusOld
);
extern FUNC(void, DEM_CODE) Dem_EventProcMemEntryData
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 EntryIdx
);
extern FUNC(void, DEM_CODE) Dem_EventStorCondFailedHandle
(
    uint16 EventIdx
);
extern FUNC(void, DEM_CODE) Dem_EventStorCondPassedHandle
(
    uint16 EventIdx
);
extern FUNC(boolean, DEM_CODE) Dem_EventDebCntBasedJumpDown
(
    uint16 EventIdx
);
extern FUNC(boolean, DEM_CODE) Dem_EventDebCntBasedJumpUp
(
    uint16 EventIdx
);
extern FUNC(uint8, DEM_CODE) Dem_EventDebCntBasedCalc
(
    uint16 EventIdx,
    Dem_EventStatusType EventStatus
);
extern FUNC(void, DEM_CODE) Dem_EventDebCntBasedToFDC
(
    uint16 EventIdx
);
extern FUNC(uint8, DEM_CODE) Dem_EventDebTimeBasedCalc
(
    uint16 EventIdx, 
    Dem_EventStatusType EventStatus
);
extern FUNC(void, DEM_CODE) Dem_EventDebTimeBasedToFDC
(
    uint16 EventIdx
);
extern FUNC(uint8, DEM_CODE) Dem_EventDebMonitorBasedCalc
(
    uint16 EventIdx,
    Dem_EventStatusType EventStatus
);
extern FUNC(void, DEM_CODE) Dem_EventDebTimeBasedProcess(void);
extern FUNC(uint8, DEM_CODE) Dem_EventDebounceExecute
(
    uint16 EventIdx, 
    Dem_EventStatusType EventStatus
);
extern FUNC(void, DEM_CODE) Dem_EventDebounceBehavior
(
    uint16 EventIdx
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventDebounceStatus
(
    uint16 EventIdx,
    Dem_DebounceResetStatusType DebounceResetStatus
);
extern FUNC(void, DEM_CODE) Dem_EventFailedHandle
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 EntryIdx,
    uint8 EventStatusOld
);
#if(DEM_CFG_EXTENDSTATUSBYTE != DEM_INIT_ZERO) 
extern FUNC(void, DEM_CODE) Dem_EventExStatusHandle
(
    uint16 EventIdx
);
#endif
#if(DEM_CFG_RESETCONFIRMEDBITONOVERFLOW == STD_OFF)
extern FUNC(void, DEM_CODE) Dem_EventMemoryEntryAttemptProcess(void);
#endif
extern FUNC(void, DEM_CODE) Dem_EventMemoryEntryOpcycStart
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 OpcycId
);
extern FUNC(void, DEM_CODE) Dem_EventMemoryEntryOpcycEnd
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 OpcycId
);
extern FUNC(void, DEM_CODE) Dem_EventMemoryEntryHealing
(
    uint8 EventMemIdx,
    uint8 EntrySlotIdx
);
extern FUNC(uint8, DEM_CODE) Dem_EventMemoryEntryAging
(
    uint8 EventMemIdx,
    uint8 EntrySlotIdx
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventMemoryEntryExist
(
    uint16 EventIdx
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventMemoryEntryAllocate
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) EntryIdx
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventMemoryEntryDisplace
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) EntryIdx
);
extern FUNC(void, DEM_CODE) Dem_EventMemoryEntryEnter
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 EntryIdx
);
extern FUNC(void, DEM_CODE) Dem_EventMemoryEntrySlotUpdate
(
    Dem_EventIdType EventId,
    uint8 EventMemIdx
);
extern FUNC(void, DEM_CODE) Dem_EventMemoryEntryRemove
(
    uint8 EntryIdx,
    uint8 EventMemIdx
);
extern FUNC(void, DEM_CODE) Dem_EventFreezeFrameDataStore
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 EntryIdx
);
extern FUNC(void, DEM_CODE) Dem_EventExtendedDataStore
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 EntryIdx
);
extern FUNC(void, DEM_CODE) Dem_EventFreezeFrameDataUpdate
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 EntryIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
);
extern FUNC(void, DEM_CODE) Dem_EventExtendedDataRecordUpdate
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 EntryIdx,
    uint8 exDataRecIdx, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
);
extern FUNC(void, DEM_CODE) Dem_EventDataElementAcqusition
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 EntryIdx, 
    uint8 DataEleIdx, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventInternalDataElementAcqusition
(
    uint16 EventIdx, 
    uint8 EventMemIdx,
    uint8 EntryIdx, 
    uint8 DataLen, 
    uint8 InterDataKind,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventExInternalDataElementAcqusition
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 EntryIdx, 
    uint8 InterDataKind,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
);
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
extern FUNC(void, DEM_CODE) Dem_EventSyncFreezeFrameDataStore
(
    uint16 EventIdx
);
extern FUNC(void, DEM_CODE) Dem_EventSyncExtendedDataStore
(
    uint16 EventIdx
);
extern FUNC(void, DEM_CODE) Dem_EventSyncSnapShotDataStore
(
    uint16 EventIdx
);
extern FUNC(void, DEM_CODE) Dem_EventSyncFreezeFrameDataUpdate
(
    uint16 EventIdx, 
    uint16 BufOffset,
    uint16 DataLen,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
);
extern FUNC(void, DEM_CODE) Dem_EventSyncExtendedDataUpdate
(
    uint16 EventIdx, 
    uint16 BufOffset,
    uint16 DataLen,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
);
#endif
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT != DEM_EVCOMB_DISABLED)
extern FUNC(void, DEM_CODE) Dem_EventCombStatusDisplace
(
    uint16 EventIdx
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetCombStatusByteByOld
(
    uint16 EventIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OldStatusByte
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetCombStatusByte
(
    uint16 EventIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) StatusByte
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetCombFDC
(
    uint16 EventIdx,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FdcVal
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetCombMaxFDCDCC
(
    uint16 EventIdx,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FdcVal
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetCombMaxFDCSLC
(
    uint16 EventIdx,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FdcVal
);
#endif
extern FUNC(boolean, DEM_CODE) Dem_EventGetEnCondGrpStatus
(
    uint16 CondGrpIdx
);
extern FUNC(boolean, DEM_CODE) Dem_EventGetStorCondGrpStatus
(
    uint16 CondGrpIdx
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetFFRecordDidData
(
    uint16 EventIdx,
    uint8 RecordNumber,
    uint16 DataId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetFFRecentlyRecordDidData
(
    uint16 EventIdx,
    uint16 DataId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetFFDataByDid
(
    uint8 FfDataIdx,
    uint16 DataId,
    P2CONST(uint8, AUTOMATIC, DEM_APPL_DATA) SrcPtr,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetExRecordData
(
    uint16 EventIdx,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE) Dem_EventGetDTCByOccurrenceTime
(
    Dem_DTCRequestType DTCRequest,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC
);
extern FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE) Dem_DTCGetFFRecordData
(
    uint16 DtcIdx,
    uint8 evtMemIdx,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DTCGetFFRecordSize
(
    uint16 DtcIdx,
    uint8 evtMemIdx,
    uint8 RecordNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
);
extern FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE) Dem_DTCGetExRecordData
(
    uint16 DtcIdx,
    uint8 evtMemIdx,
    uint8 ExtendedDataNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DTCGetExRecordSize
(
    uint16 DtcIdx,
    uint8 evtMemIdx,
    uint8 ExtendedDataNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
);
extern FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE) Dem_DTCGetAllExRecordData
(
    uint16 DtcIdx,
    uint8 evtMemIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DTCGetAllExRecordSize
(
    uint16 DtcIdx,
    uint8 evtMemIdx,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetRecentlyFFRecordData
(
    uint16 EventIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(void, DEM_CODE) Dem_EventSetInitMonitorReason
(
    uint16 EventIdx, 
    Dem_InitMonitorReasonType Reason
);
#if(DEM_CFG_ENCOND_GROUP_NUM > DEM_INIT_ZERO)
extern FUNC(void, DEM_CODE) Dem_EventCheckEnCondGrpChanged(void);
#endif
#if(DEM_CFG_STORCOND_GROUP_NUM > DEM_INIT_ZERO)
extern FUNC(void, DEM_CODE) Dem_EventCheckStorCondGrpChanged(void);
#endif
extern FUNC(void, DEM_CODE) Dem_EventCheckDtcSettingReenable(void);
#if(DEM_CFG_COMP_NUM > DEM_INIT_ZERO)
extern FUNC(void, DEM_CODE) Dem_EventCheckComponetStatusChanged(void);
#endif
extern FUNC(void, DEM_CODE) Dem_EventCheckMonitorTrigger(void);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventCheckDataUpdateTrigger
(
    uint16 EventIdx,
    uint8 TriggerType
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventCheckConsecutiveFault
(
    uint16 EventIdx
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventCheckDTCOriginValid
(
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) EventMemIdx
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventCheckWarningIndicatorAct
(
    uint16 EventIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) IndiFc
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventCheckWarningIndicatorDeAct
(
    uint16 EventIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) IndiHc
);
extern FUNC(uint8, DEM_CODE) Dem_EventCheckDtcFilterMatch
(
    uint16 EventIdx
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventCheckDtcSettingDisable
(
    uint16 EventIdx
);
extern FUNC(boolean, DEM_CODE) Dem_EventCheckIndicatorStator
(
    uint16 EventIdx, 
    uint8 IndicatorIdx
);

extern FUNC(boolean, DEM_CODE) Dem_EventClearAllowedCbk
(
    uint16 EventIdx
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventTriggerGetFDCCbk
(
    uint16 EventIdx, 
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) cnt
);
extern FUNC(void, DEM_CODE) Dem_EventTriggerInitMonitorCbk
(
    uint16 EventIdx, 
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    Dem_InitMonitorReasonType reason
);
extern FUNC(void, DEM_CODE) Dem_EventTriggerEventDataChangedCbk
(
    uint16 EventIdx
);
extern FUNC(void, DEM_CODE) Dem_EventTriggerEventStatusChangedCbk
(
    uint16 EventIdx, 
    Dem_UdsStatusByteType OldStatus,
    Dem_UdsStatusByteType NewStatus
);
#if(DEM_CFG_GENERALINTERFACESUPPORT == STD_ON)
extern FUNC(void, DEM_CODE) Dem_GeneralEventTriggerEventStatusChangedCbk
(
    uint16 EventIdx, 
    Dem_UdsStatusByteType OldStatus,
    Dem_UdsStatusByteType NewStatus
);
#endif
extern FUNC(void, DEM_CODE) Dem_EventTriggerDtcStatusChangedCbk
(
    uint16 EventIdx,
    Dem_UdsStatusByteType OldStatus,
    Dem_UdsStatusByteType NewStatus
);
extern FUNC(void, DEM_CODE) Dem_EventTriggerComponentFailedChangedCbk
(
    uint16 EventCompIdx, 
    boolean EventCompSt
);
extern FUNC(void, DEM_CODE) Dem_EventCalcOccurenceCounter
(
    uint16 EventIdx
);
extern FUNC(uint8, DEM_CODE) Dem_EventCalcDtcStatus
(
    uint32 DTC, 
    uint8 EventMemIdx, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) EventStatus
);
extern FUNC(uint8, DEM_CODE) Dem_EventCalcDTCIndexFromDTC
(
    uint32 DTC, 
    uint8 DTCFormat, 
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) DtcIdx
);
extern FUNC(uint8, DEM_CODE) Dem_EventCalcDtcFilteredNum(void);
extern FUNC(uint8, DEM_CODE) Dem_EventCalcDtcFilteredAllSupportedNum(void);
extern FUNC(uint8, DEM_CODE) Dem_EventCalcDtcNextFilteredAllSupported
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
);
extern FUNC(uint8, DEM_CODE) Dem_EventCalcDtcNextFiltered
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
);
extern FUNC(uint8, DEM_CODE) Dem_EventCalcDtcNextFilteredSpilt
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
);
extern FUNC(uint8, DEM_CODE) Dem_EventCalcDtcAndFdcNextFiltered
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC, 
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) DTCFdc
);
extern FUNC(uint8, DEM_CODE) Dem_EventCalcAllDtcAndFdcNextFiltered
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC, 
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) DTCFdc
);
extern FUNC(uint8, DEM_CODE) Dem_EventCalcDtcAndSeverityNextFiltered
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFuncunit
);
extern FUNC(uint8, DEM_CODE) Dem_EventCalcAllDtcAndSeverityNextFiltered
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFuncunit
);
extern FUNC(uint16, DEM_CODE) Dem_EventCalcDTCFreezeFrameFiltered(void);
extern FUNC(uint8, DEM_CODE) Dem_EventCalcDTCFreezeFrameNextFiltered
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) RecordNum
);
extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_EventClearDTC
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    uint8 EventMemIdx, 
    uint8 ClearClient
);
extern FUNC(uint8, DEM_CODE) Dem_EventClearDTCRequest(void);
extern FUNC(void, DEM_CODE) Dem_EventClearDTCProcess(void);
extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_EventClearDTCResult(void);
extern FUNC(void, DEM_CODE) Dem_EventClearDTCStatus
(
    uint16 EventIdx
);
extern FUNC(void, DEM_CODE) Dem_EventClearDTCEntry
(
    uint16 EventIdx,
    uint8 EntryIdx,
    uint8 EventMemIdx
);
extern FUNC(void, DEM_CODE) Dem_EventClearIndicator
(
    uint16 EventIdx
);
extern FUNC(uint8, DEM_CODE) Dem_EventClearAllDTC(void);
extern FUNC(void, DEM_CODE) Dem_EventClearAllDTCStatus
(
    uint16 EventIdxStart,
    uint16 EventIdxEnd
);
extern FUNC(void, DEM_CODE) Dem_EventClearAllDTCEntry(void);
extern FUNC(uint8, DEM_CODE) Dem_EventClearGroupDTC(void);
extern FUNC(void, DEM_CODE) Dem_EventClearGroupDTCStatus
(
    uint16 EventIdxStart,
    uint16 EventIdxEnd
);
extern FUNC(void, DEM_CODE) Dem_EventClearGroupDTCEntry(void);
extern FUNC(uint8, DEM_CODE) Dem_EventClearSingleDTC(void);
extern FUNC(void, DEM_CODE) Dem_EventClearSingleDTCStatus
(
    uint16 EventIdxStart,
    uint16 EventIdxEnd
);
extern FUNC(void, DEM_CODE) Dem_EventClearSingleDTCEntry(void);
extern FUNC(void, DEM_CODE) Dem_EventMemoryNvmRead(void);
extern FUNC(void, DEM_CODE) Dem_EventMemoryNvmReadCheck(void);
extern FUNC(void, DEM_CODE) Dem_EventMemoryNvmClear(void);
extern FUNC(void, DEM_CODE) Dem_EventMemoryNvmClearCheck(void);
extern FUNC(void, DEM_CODE) Dem_EventMemoryNvmWrite(void);
extern FUNC(void, DEM_CODE) Dem_EventMemoryNvmWriteCheck(void);
extern FUNC(void, DEM_CODE) Dem_EventMemoryNvmProcess(void);
extern FUNC(void, DEM_CODE) Dem_EventMemoryNvmRequest
(
    uint8 OperationType,
    uint16 NvmBlkIdx
);
extern FUNC(uint16, DEM_CODE) Dem_EventMemoryNvmBlkIndex
(
    uint8 EventMemIdx,
    uint8 EntryIdx
);
extern FUNC(void, DEM_CODE) Dem_EventMemoryNvmBlkUpdateReq
(
    uint8 EventMemIdx,
    uint8 EntryIdx,
    uint8 OperationType,
    boolean ImmediateStore
);
extern FUNC(void, DEM_CODE) Dem_EventMemoryNvmInitialize
(
    uint16 NvmBlkIdx
);
extern FUNC(void, DEM_CODE) Dem_EventMemoryNvmStatusBlockInit(void);
extern FUNC(void, DEM_CODE) Dem_EventMemoryNvmInfoBlockInit
(
    P2VAR(Dem_EventMemoryInfo_st, AUTOMATIC, DEM_APPL_DATA) Info_ptr
);
extern FUNC(void, DEM_CODE) Dem_EventMemoryNvmShutDown(void);
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
extern FUNC(void, DEM_CODE) Dem_EventMemoryNvmPermBlockInit
(
    P2VAR(Dem_PermanentEventMemoryEntry_st, AUTOMATIC, DEM_APPL_DATA) Perm_ptr
);
#endif
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventMemoryNvmPrepare
(
    uint16 NvmBlkIdx, 
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) SrcPtr
);
extern FUNC(void, DEM_CODE) Dem_EventMemoryCopy
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DstAddr, 
    P2CONST(uint8, AUTOMATIC, DEM_APPL_DATA) SrcAddr, 
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 Len
);

#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
extern FUNC(void, DEM_CODE) Dem_ObdDrivingCycleStart(void);
extern FUNC(void, DEM_CODE) Dem_ObdWarmUpCycleStart(void);
extern FUNC(void, DEM_CODE) Dem_ObdIgnitionCycleStart(void);
extern FUNC(uint32, DEM_CODE) Dem_ObdGetGeneralData
(
    uint8 DataElementIdx
);
extern FUNC(void, DEM_CODE) Dem_ObdGetInfoTypeValue08
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08BufferSize
);
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
extern FUNC(void, DEM_CODE) Dem_ObdGetInfoTypeValue0B
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0B, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0BBufferSize
);
extern FUNC(void, DEM_CODE) Dem_ObdGetSupportReadiness
(
    uint16 EventIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) SupportGroup
);
extern FUNC(void, DEM_CODE) Dem_ObdGetDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01value
);
extern FUNC(void, DEM_CODE) Dem_ObdGetDataOfPID41
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ObdGetFFRecordPID
(
    uint8 PID,
    uint8 DataElementIndexOfPID,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE) Dem_ObdGetFFRecordData
(
    uint32 DTC,
    uint8 EventMemIdx,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_ObdGetFFRecordSize
(
    uint32 DTC,
    uint8 EventMemIdx,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ObdGetFFRecordDTC
(
    uint8 FrameNumber,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    Dem_DTCFormatType DTCFormat
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ObdGetDtrData
(
    uint8 Obdmid,
    uint8 TIDindex,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) TIDvalue,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) UaSID,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Testvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Lowlimvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Upplimvalue
);
extern FUNC(uint8, DEM_CODE) Dem_ObdGetPfcNum(void);
extern FUNC(uint32, DEM_CODE) Dem_ObdGetPfcVal
(
    uint8 pfcIdx
);
extern FUNC(uint16, DEM_CODE) Dem_ObdGetPfcEvtIdx
(
    uint8 pfcIdx
);
extern FUNC(uint8, DEM_CODE) Dem_ObdGetPfcStatus
(
    uint8 pfcIdx
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ObdSetDtrData
(
    uint16 DTRIdx,
    sint32 TestResult,
    sint32 LowerLimit,
    sint32 UpperLimit,
    Dem_DTRControlType Ctrlval
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ObdSetIUMPRDenPhsyCondition
(
    Dem_RatioIdType RatioID, 
    Dem_IumprDenomCondStatusType ConditionStatus
);
extern FUNC(uint8, DEM_CODE) Dem_ObdCheckDenCondition
(
    uint8 RatioIdx
);
extern FUNC(boolean, DEM_CODE) Dem_ObdCheckPtoStatus
(
    uint8 RatioIdx
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ObdCheckEventDisplace
(
    Dem_EventIdType EventId
);
extern FUNC(void, DEM_CODE) Dem_ObdCalcIUPRNumerator(void);
extern FUNC(void, DEM_CODE) Dem_ObdCalcIUPRDenominator(void);
extern FUNC(void, DEM_CODE) Dem_ObdCalcIUPRGenDenominator(void);
extern FUNC(void, DEM_CODE) Dem_ObdCalcIUPRValue(void);
extern FUNC(void, DEM_CODE) Dem_ObdCalcIUPRCycle(void);
extern FUNC(void, DEM_CODE) Dem_ObdIUPRProcess(void);
extern FUNC(void, DEM_CODE) Dem_ObdCalcDataOfPID21(void);
extern FUNC(void, DEM_CODE) Dem_ObdCalcDataOfPID31(void);
extern FUNC(void, DEM_CODE) Dem_ObdCalcDataOfPID4D(void);
extern FUNC(void, DEM_CODE) Dem_ObdCalcDataOfPID4E(void);
extern FUNC(uint16, DEM_CODE) Dem_ObdCalcDtrData
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DtrIdx,
    sint32 DtrData
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ObdCalcDtrDataNormal
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DTRIdx,
    sint32 TestResult,
    sint32 LowerLimit,
    sint32 UpperLimit
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ObdCalcDtrDataNoMax
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DTRIdx,
    sint32 TestResult,
    sint32 LowerLimit,
    sint32 UpperLimit
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ObdCalcDtrDataNoMin
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DTRIdx,
    sint32 TestResult,
    sint32 LowerLimit,
    sint32 UpperLimit
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ObdCalcDtrDataReset
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DTRIdx
);
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
extern FUNC(void, DEM_CODE) Dem_ObdSyncFreezeFreeDataStore
(
    uint16 EventIdx
);
extern FUNC(void, DEM_CODE) Dem_ObdSyncFreezeFrameDataUpdate
(
    uint16 EventIdx, 
    uint16 BufOffset,
    uint16 DataLen,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
);
#endif
extern FUNC(void, DEM_CODE) Dem_ObdFreezeFrameDataStore
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 EntryIdx
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ObdFreezeFrameDataUpdate
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 EntryIdx
);
extern FUNC(void, DEM_CODE) Dem_ObdPfcHandle
(
    uint16 PfcEventIdx,
    uint8 PfcAction
);
extern FUNC(void, DEM_CODE) Dem_ObdPfcProcess(void);
extern FUNC(void, DEM_CODE) Dem_ObdClearDtrData
(
    uint16 EventIdx
);
extern FUNC(void, DEM_CODE) Dem_ObdClearRelatedInfo(void);
extern FUNC(void, DEM_CODE) Dem_ObdClearLegislativeFreezeFrame(void);
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
extern FUNC(void, DEM_CODE) Dem_ObdCalcWwhContiMiCounter(void);
extern FUNC(void, DEM_CODE) Dem_ObdCalcWwhB1Counter(void);
extern FUNC(void, DEM_CODE) Dem_ObdCalcWwhActMode1
(
    uint8 ActMode
);
extern FUNC(void, DEM_CODE) Dem_ObdCalcWwhActMode2
(
    uint8 ActMode
);
extern FUNC(void, DEM_CODE) Dem_ObdCalcWwhActMode3
(
    uint8 ActMode
);
extern FUNC(void, DEM_CODE) Dem_ObdCalcWwhActMode4
(
    uint8 ActMode
);
extern FUNC(void, DEM_CODE) Dem_ObdCalcWwhActMode(void);
extern FUNC(void, DEM_CODE) Dem_ObdCalcWwhContiMiCounterHaltCycle(void);
extern FUNC(void, DEM_CODE) Dem_ObdCalcWwhAgingHours(void);
extern FUNC(void, DEM_CODE) Dem_ObdClearWwhInfo(void);
extern FUNC(void, DEM_CODE) Dem_ObdAgingWwhContiMiCounter(void);
extern FUNC(void, DEM_CODE) Dem_ObdAgingWwhB1Counter(void);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ObdGetWwhFFDataByDid
(
    uint16 EventIdx,
    uint16 DataId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
extern FUNC(void, DEM_CODE) Dem_ObdWwhSyncFreezeFrameDataStore
(
    uint16 EventIdx
);
extern FUNC(void, DEM_CODE) Dem_ObdWwhSyncFreezeFrameDataUpdate
(
    uint16 EventIdx, 
    uint16 BufOffset,
    uint16 DataLen,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
);
#endif
extern FUNC(void, DEM_CODE) Dem_ObdWwhFreezeFrameDataStore
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 EntryIdx
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ObdWwhFreezeFrameDataUpdate
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 EntryIdx
);
#endif
extern FUNC(void, DEM_CODE) Dem_ObdInit(void);
extern FUNC(void, DEM_CODE) Dem_ObdMainProcess(void);
#endif

#if( DEM_CFG_J1939SUPPORT == STD_ON )
#if( DEM_CFG_J1939READINGDTCSUPPORT == STD_ON )
extern FUNC(void, DEM_CODE) Dem_ReturnLampStatus
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) LampStatus
);
extern FUNC(uint8, DEM_CODE) Dem_EventCalcJ1939DtcFilteredNum(void);

extern FUNC(uint8, DEM_CODE) Dem_EventCalcJ1939DtcNextFiltered
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
);
#endif

#if( DEM_CFG_J1939DM31SUPPORT == STD_ON )
extern FUNC(void, DEM_CODE) Dem_ReturnDM31LampStatus
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) LampStatus,
    uint16 EventIdx
);
extern FUNC(uint8, DEM_CODE) Dem_EventCalcDM31J1939DtcNextFiltered
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Dem_EventIdx
);
#endif

#if( DEM_CFG_J1939CLEARDTCSUPPORT == STD_ON )
extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_EventClearJ1939DTC
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    uint8 EventMemIdx,
    uint8 ClearClient
);
extern FUNC(uint8, DEM_CODE) Dem_J1939DcmCheckClearFilterType
(
    Dem_J1939DcmSetClearFilterType DTCTypeFilter,
    uint16 dtcIdx,
    P2VAR(Dem_ReturnClearDTCType, AUTOMATIC, DEM_APPL_DATA) ClearStatus
);
#endif

extern FUNC(uint8, DEM_CODE) Dem_EventCheckJ1939DtcFilterMatch
(
    uint16 EventIdx
);
extern FUNC(void, DEM_CODE) Dem_J1939EventCalcOccurenceCounter
(
    uint16 EventIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
);
#endif
#define DEM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif /* DEM_EVENT_H_ */


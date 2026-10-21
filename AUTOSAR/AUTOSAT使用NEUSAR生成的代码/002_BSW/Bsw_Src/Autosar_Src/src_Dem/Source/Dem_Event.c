/*
********************************************************************************
*
* File name: Dem_Event.c
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
* Author/Date: ZhiDX/2021.03.18
* Change: 1.In Dem_EventControlProcess, length of local array variable 
*           "evtCompSt" is too small.
*         2.In Dem_EventMemoryEntryAttemptProcess, Missing "()" in if.
*         3.In Dem_EventGetFDC, wrong use of "==".
*         4.In Dem_EventGetComponentFailed, consider component availablity.
*         5.Macro switch before use user define event memory.
* Cause: Bugfix
********************************************************************************
* Version: 1.2
* Author/Date: ZhiDX/2021.03.18
* Change: Using wrong parameters forOperation cycle request.
* Cause: Bugfix
********************************************************************************
* Version: 1.3
* Author/Date: ZhiDX/2021.03.18
* Change: A newer event will be displaced.
* Cause: Bugfix
********************************************************************************
* Version: 1.4
* Author/Date: ZhiDX/2021.03.22
* Change: JIRA bugfixs.
* Cause: Bugfix
********************************************************************************
* Version: 1.5
* Author/Date: ZhiDX/2021.03.23
* Change: Consider storage condition status Before calculate occurence counter.
* Cause: Bugfix
********************************************************************************
* Version: 1.6
* Author/Date: ZhiDX/2021.03.31
* Change: 1.Snap shot data should also be considered when test passed.
*         2.Using DEM_CFG_EVENT_MEMORY_NUM instead of DEM_EVENT_MEMORY_NUM.
*         3.Reset timer debounce infomation.
* Cause: Bugfix
********************************************************************************
* Version: 1.7
* Author/Date: ZhiDX/2021.04.12
* Change: 1.Add nvm block data initialization function.
*         2.Clear DEM_TRIGGER_ON_FDC_THRESHOLD_ONCE bit after Opcyc restart.
*         3.Support of 190A to read all configured DTCs.
* Cause: Bugfix
********************************************************************************
* Version: 1.8
* Author/Date: ZhiDX/2021.04.12
* Change: Unused local variable control by MACRO in Dem_ObdGetFreezeFrameData.
* Cause: Bugfix
********************************************************************************
* Version: 1.9
* Author/Date: ZhiDX/2021.04.13
* Change: To support read all frame freeze data record by DCM.
* Cause: Bugfix
********************************************************************************
* Version: 1.10
* Author/Date: ZhiDX/2021.04.15
* Change: 1.Add environment data SYNCHRONOUS_CAPTURE functionality.
*         2.Update indicator status after one event cleared.
*         3.Clear indicator status when clear DTC.
*         4.Send out Extended data record number when DCM read all extended data.
* Cause: Bugfix
********************************************************************************
* Version: 1.11
* Author/Date: ZhiDX/2021.04.19
* Change: 1.Wrong size calculation when get all extended data by DTC.
*         2.Clear Freeze frame filter when re-set filter.
*         3.Wrong DTC group calculation when clear Group DTC.
* Cause: Bugfix
********************************************************************************
* Version: 1.12
* Author/Date: ZhiDX/2021.04.20
* Change: DTC status mask of filter should be used as (mask & status != 0) 
*         according to ISO-14229.
* Cause: Bugfix
********************************************************************************
* Version: 1.13
* Author/Date: ZhiDX/2021.04.21
* Change: 1.For reading internal data element of extended data, using current
*           value instead of value stored in event memory.
*         2.Wrong judgement of component avaliable status.
*         3.Clear nvm block status after initialization.
* Cause: Bugfix
********************************************************************************
* Version: 1.14
* Author/Date: ZhiDX/2021.04.21
* Change: 1.Wrong "for" loop when setting storage condition.
*         2.Remove enable/storage condition ID avalibility check functions.
* Cause: Bugfix
********************************************************************************
* Version: 1.15
* Author/Date: ZhiDX/2021.04.23
* Change: OBD related code should be controlled by MACRO.
* Cause: Bugfix
********************************************************************************
* Version: 1.16
* Author/Date: ZhiDX/2021.04.25
* Change: OBD freeze frame buffer shoule be read from position 0.
* Cause: Bugfix
********************************************************************************
* Version: 1.17
* Author/Date: ZhiDX/2021.05.29
* Change: Store Nvm block with wrong ram address.
* Cause: Bugfix
********************************************************************************
* Version: 1.18
* Author/Date: ZhiDX/2021.06.09
* Change: Data element endiness.
* Cause: Bugfix
********************************************************************************
* Version: 1.19
* Author/Date: ZhiDX/2021.06.15
* Change: PID data should be cleared when request clear DTC.
* Cause: Bugfix
********************************************************************************
* Version: 1.20
* Author/Date: ZhiDX/2021.06.22
* Change: Component failed status implementation.
* Cause: Bugfix
********************************************************************************
* Version: 1.21
* Author/Date: ZhiDX/2021.06.24
* Change: Child Component should be set failed when parent component failed.
* Cause: Bugfix
********************************************************************************
* Version: 1.22
* Author/Date: ZhiDX/2021.06.24
* Change: 1.Immediate Nvm storage limitation will be checked in
*           Dem_EventMemoryNvmProcess.
*         2.Trigger Nvm update in Dem_ShutDown in case of data changed.
* Cause: Optimization
********************************************************************************
* Version: 1.23
* Author/Date: ZhiDX/2021.07.06
* Change: 1.Re-calculate FDC value according to debounce counter value read
*           from NVM block during init.
*         2.Trigger callback when component status changed.
*         3.Prevent a event is in entryblock but not in infoblock during
*           clear all DTC.
*         4.Trigger entry NVM block update during clear DTC.
*         5.In case of initialize all block with default value, trigger
*           nvm block update by NvM_SetRamBlockStatus.
* Cause: Optimization
********************************************************************************
* Version: 1.24
* Author/Date: ZhiDX/2021.07.15
* Change: Notification of status change during error report and event process.
* Cause: Bugfix
********************************************************************************
* Version: 1.25
* Author/Date: ZhiDX/2021.07.24
* Change: Denominator increament should consider the condition of the 
*         genenal denominator.
* Cause: Bugfix
********************************************************************************
* Version: 1.26
* Author/Date: ZhiDX/2021.07.28
* Change: Missing "&&" in function Dem_ObdCalcIUPR.
* Cause: Bugfix
********************************************************************************
* Version: 1.27
* Author/Date: ZhiDX/2021.07.31
* Change: Remove Polyspace defects and warnings.
* Cause: Bugfix
********************************************************************************
* Version: 1.28
* Author/Date: ZhiDX/2021.08.05
* Change: Store TF bit into NvM if configured, store MAXFDC_SLC into NVM always.
* Cause: Bugfix
********************************************************************************
* Version: 1.29
* Author/Date: ZhiDX/2021.09.01
* Change: Remove Compile warnings and polyspace warnings.
* Cause: Optimization
********************************************************************************
* Version: 1.30
* Author/Date: ZhiDX/2021.09.02
* Change: Clear DTC always trigger Nvm update.
* Cause: Bugfix
********************************************************************************
* Version: 1.31
* Author/Date: ZhiDX/2021.09.06
* Change: NvM block will always be stored during fault report.
* Cause: Bugfix
********************************************************************************
* Version: 1.32
* Author/Date: ZhiDX/2021.09.08
* Change: 1.If requested DTC is not stored, DEM should return OK to DCM.
*         2.Optimization for implementation of DEM_TRIGGER_ON_FDC_THRESHOLD.
* Cause: Bugfix
********************************************************************************
* Version: 1.33
* Author/Date: ZhiDX/2021.09.18
* Change: A request with an invalid FF/EX data record should lead to an error 
*         code.
* Cause: Bugfix
********************************************************************************
* Version: 1.34
* Author/Date: ZhiDX/2021.09.26
* Change: 1.A wrong ff data class index is used for read data by event id.
*         2.Wrong data length limitation for copying extended data.
* Cause: Bugfix
********************************************************************************
* Version: 1.35
* Author/Date: ZhiDX/2021.09.26
* Change: Wrong using array value in function Dem_EventMemoryEntryAttemptProcess.
* Cause: Bugfix
********************************************************************************
* Version: 1.36
* Author/Date: ZhiDX/2021.10.13
* Change: Return the actual extended data size after copy data in function 
*         Dem_EventGetExRecordData.
* Cause: Bugfix
********************************************************************************
* Version: 3.0
* Author/Date: ZhiDX/2021.11.11
* Change: Bugfix of duplicate trigger of event status changed callback function.
* Cause: Bugfix
********************************************************************************
* Version: 3.1
* Author/Date: ZhiDX/2021.11.15
* Change: Implementation of event combination.
* Cause: Implementation
********************************************************************************
* Version: 3.2
* Author/Date: ZhiDX/2021.11.26
* Change: Bugfix of variable is not initialized before used.
* Cause: bugfix
********************************************************************************
* Version: 3.3
* Author/Date: ZhiDX/2021.12.02
* Change: DTC healing and aging will be processed in the end of operation cycle.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: ZhiDX/2021.12.06
* Change: 1.For DEM_EVCOMB_ONSTORAGE, the value of MaxFDCDCC/MaxFDCSLC will be 
*            reported with the max-value of all sub_events for extended data.
*         2.For reading all extended data, the record number will also be 
*            returned.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: ZhiDX/2021.12.06
* Change: Bugfix for activated warning indicator.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: ZhiDX/2022.02.22
* Change: Bugfix for FDC calculation.
* Cause: Bugfix
********************************************************************************
* Version: 3.7
* Author/Date: ZhiDX/2022.02.23
* Change: Bugfix for Nvm initialization.
* Cause: Bugfix
********************************************************************************
* Version: 3.8
* Author/Date: FanHT/2022.06.30
* Change: 1.Bugfix for Indicator Status estimate.
*         2.Bugfix for change PID 01 and 41  to "completeGroup[0] << 4".
*         3.Bugfix for Dem_SetEventStatus() returns E_NOT_OK When Dtc is 
*           disabled.
* Cause: Bugfix
********************************************************************************
* Version: 3.9
* Author/Date: FanHT/2022.08.19
* Change: Clear warnings for variable initialization.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: FanHT/2022.09.15
* Change: 1.Optimization for Dem_EventOperCycleReqHandle().
*         2.Clear static code analysis warnings.
*         3.Bugfix for Local variable initialization when DEM_CFG_OBD_PID_DATA_NUM is zero.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: FanHT/2022.11.03
* Change: 1.Bugfix for PFC clear.
*         2.DataElementReadFunc Remove length.
*         3.Implementation of DEM_CLEAR_MEMORY_ERROR.[SWS_Dem_01057]
* Cause: Bugfix
********************************************************************************
* Version: 3.12
* Author/Date: FanHT/2022.11.18
* Change: Merge The Aged Counter feature of FAW.
* Cause: Implementation
********************************************************************************
* Version: 3.13
* Author/Date: FanHT/2022.11.18
* Change: GAC Calibration.
* Cause: Implementation
********************************************************************************
* Version: 3.14
* Author/Date: FanHT/2023.02.09
* Change: 1.Implemented GAC Calibration 2.
*         2.Implemented InternalDataElement Extend DEM_AGINGCTR_UPCNT2,
*           DEM_OCCCTR2 and DEM_AGEDCTR2.
*         3.Bugfix for Memory out-of-bounds access of Dem_EventNvmBlockInit 
*           due to configurattion of UserDefinedMemory. (CCOREDBUG-2263)
* Cause: Implementation
********************************************************************************
* Version: 3.15
* Author/Date: FanHT/2023.02.10
* Change: 1.Bugfix for DEM_CFG_STORCONDGRP_MAX_REF_STORCOND_NUM
*           in Dem_EventGetStorCondGrpStatus.
*         2.Optimization for Dem_EventMemoryEntryDisplace function
*           due to incorrect memory data read from Nvm Block.
* Cause: Bugfix
********************************************************************************
* Version: 3.16
* Author/Date: FanHT/2023.03.08
* Change: 1.Bugfix for DEM_OCC6 also be cleared when it has reached
*           DemEventFailureCycleCounterThreshold.(CCOREPBUG-2445,CCOREDBUG-2552)
*         2.Bugfix for DEM_OCC6 shall maintain its value 
*           if FDC did not reach -128.(CCOREDBUG-2553)
*         3.Bugfix for OCC4、OCC6 clear.(CCOREPBUG-2438)
*         4.Bugfix for Debounce overflow if debounce counter was over
*           DEM_INT16_MAX or DEM_INT16_MIN.(CCOREDBUG-2548)
*         5.Clear QAC analysis warnings.
* Cause: Bugfix
********************************************************************************
* Version: 3.17
* Author/Date: WangYS/2023.04.01
* Change: 1.Get the Lamp Status.
*         2.Calc the Filterd J1939 DTC number.
*         3.Check J1939 Dtc Filtered Match.
*         4.Calc the value of Occurence Counter.
*         5.Return DM31 Lamp Status.
*         6.Calc DM31 J1939Dtc Next Filtered.
*         7.Calc J1939Dtc Next Filtered.
*         8.J1939 Event Set Indicator.
*         9.J1939 Set DM31 Indicator.
*         10.Clear J1939DTC.
*         11.Callback add J1939 DTC Status changed.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: WangYS/2023.04.03
* Change: 1.Modify macro switch name.
          2.Add header file J1939Dcm.h.
* Cause: Optimization
********************************************************************************
* Version: 3.19
* Author/Date: WangYS/2023.04.06
* Change: 1.Modify the scope of action of J1939 macro switches.
*         2.J1939Dcm_DemTriggerOnDTCStatus added macro switch limit.
* Cause: Bugfix
********************************************************************************
* Version: 3.20
* Author/Date: WangYS/2023.04.08
* Change: 1.Modify the Dem_EventCalcDM31J1939DtcNextFiltered.
*         2.Dem_EventTriggerDtcStatusChangedCbk added macro switch limit.
* Cause: Bugfix
********************************************************************************
* Version: 3.21
* Author/Date: WangYS/2023.04.26
* Change: 1.Add DEM_CFG_J1939SUPPORT macro switch limit.
*         2.Modify the content cleared by J1939.
*         3.Modify function Dem_ReturnLampStatus.
*         4.Optimize J1939DTC clearing function.
*         5.Optimize J1939 functionality and support event interface calculation
*           of DTC.
* Cause: Optimization
********************************************************************************
* Version: 3.22
* Author/Date: WangYS/2023.05.05
* Change: 1.CCOREEDBUG-2807,Modify the judgment logic for obtaining DTC.
*         2.CCOREEDBUG-2810,CCOREEDBUG-2824, Modifying the Byte Order of Lamp
*           Status,refactoring to obtain lamp status byte function and setting 
*           Lamp Status Priority.
*         3.CCOREEDBUG-2843,Modifying Discriminant Logic in Function 
*           Dem_EventCheckJ1939DtcFilterMatch.
*         4.CCOREEDBUG-2842，Modify the judgment criteria for calling function
*           J1939Dcm_DemTriggerOnDTCStatus. Modify DEM_SET_DTCCHANGEDNOTIF the
*           initial value to TRUE.
*         5.CCOREEDBUG-2814，add new function Dem_J1939DcmCheckClearFilterType.
* Cause: Bugfix
********************************************************************************
* Version: 3.23
* Author/Date: FanHT/2023.05.05
* Change: Bugfix for Dem_EventMemoryEntryDisplace function. Shall displace
*         older stored events.[SWS_Dem_00405]
* Cause: Bugfix
********************************************************************************
* Version: 3.24
* Author/Date: FanHT/2023.05.11
* Change: Bugfix for DEM_DISPLACEMENT_FULL strategy shall displace passive
*         events.[SWS_Dem_00404]
* Cause: Bugfix
********************************************************************************
* Version: 3.25
* Author/Date: WangYS/2023.05.16
* Change: Modify Dem_EventTriggerDtcStatusChangedCbk，J1939DTC status change 
*         defaults to reporting J1939Dcm.
* Cause: Optimization
********************************************************************************
* Version: 3.26
* Author/Date: WangYS/2023.05.25
* Change: CCOREDBUG——3036,Remove the J1939 section of the function function
*         using DEM_GET_J1939_DTC_FILTER_FORMAT macros in Dem.
* Cause: Bugfix
********************************************************************************
* Version: 3.27
* Author/Date: WangYS/2023.05.29
* Change: 1.Optimize J1939 partial code specifications.
*         2.Increase the following three functions
*           Dem_EventCheckWarningIndicatorAct,
*           Dem_EventCheckWarningIndicatorDeAct,
*           and Dem_EventClearIndicator for J1939 decoupling differentiation.
*         3.Adjust code according to code review.
* Cause: Optimization
********************************************************************************
* Version: 3.28
* Author/Date: WangYS/2023.05.29
* Change: 1.Adjust code according to code review.
*         2.Assigning initial values to variables within J1939 functions.
*         3.Variable flag type changed to Boolean.
*         4.Modify Dem_J1939EventCalcOccurenceCounter the logic for obtaining
*           OC values.
*         5.Modify the judgment method for UDS DTC status bits.
* Cause: Optimization
********************************************************************************
* Version: 3.29
* Author/Date: WangYS/2023.05.30
* Change: CCOREEDBUG-3180，3181.Modifying function Dem_EventClearSingleDTCStatus
*         and Dem_EventClearSingleDTCEntry.
* Cause: Bugfix
********************************************************************************
* Version: 3.30
* Author/Date: FanHT/2023.05.31
* Change: Do not clear DTC status when DemMemoryDestinationRef
*         is not matched clearing origin.(CCOREDBUG-3114)
* Cause: Bugfix
********************************************************************************
* Version: 3.31
* Author/Date: WangYS/2023.05.31
* Change: Modifying function Dem_J1939DcmCheckClearFilterType consider combining
*         events.
* Cause: Optimization
********************************************************************************
* Version: 3.32
* Author/Date: FanHT/2023.06.09
* Change: Let OCC6 act as Trip Counter in ISO 14229-1. Clear OCC6 immediately
*         instead of the next operation cycle when OCC6 reached ConfirmedLimit.
* Cause: Bugfix
********************************************************************************
* Version: 3.33
* Author/Date: FanHT/2023.06.09
* Change: DemCallbackDTCStatusChanged should not be subject to 86 Services.
*         And the status byte of an event should be calculated as a combined 
*         DTC status byte.(CCOREDBUG-3235,[SWS_Dem_01050],[SWS_Dem_00828])
* Cause: Bugfix
********************************************************************************
* Version: 3.34
* Author/Date: ZhangF/2023.08.02
* Change: 1.Change the method of event position reading in the queue.
            (CCOREDBUG-3507)
          2.Only request to change state when operation cycles state change 
            from start to end.(CCOREDBUG-3421)
* Cause: Bugfix
********************************************************************************
* Version: 3.35
* Author/Date: ZhangF/2023.08.25
* Change: Add memory map to local static variables.
* Cause: Update
********************************************************************************
* Version: 3.36
* Author/Date: ZhangF/2023.09.19
* Change: Fix the event queue multitask preemption issue.
* Cause: Bugfix
********************************************************************************
* Version: 3.37
* Author/Date: ZhangF/2023.09.19
* Change: Fix the event index range incorrect issue when cleaning DTC.
* Cause: Bugfix
********************************************************************************
* Version: 3.38
* Author/Date: ZhangF/2023.10.07
* Change: Add the global calibration array for Dem event calibration.
* Cause: Update
********************************************************************************
* Version: 3.39
* Author/Date: ZhangF/2023.10.09
* Change: Fix compile warning.
* Cause: Update
********************************************************************************
* Version: 3.40
* Author/Date: ZengJX/2023.10.10
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.41
* Author/Date: ZengJX/2023.10.25
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.42
* Author/Date: ZengJX/2023.12.29
* Change: Modifying function Dem_EventMemoryEntryDisplace for looking 
*         for passive event while event memory entry has the same priority 
*         like the reported event.
* Cause: Bugfix
********************************************************************************
* Version: 3.43
* Author/Date: ZengJX/2024.01.02
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.44
* Author/Date: ZengJX/2024.01.11
* Change: 1.Adding function Dem_GeneralEventTriggerEventStatusChangedCbk.
*         2.Adding the invoking of Dem_GeneralEventTriggerEventStatusChangedCbk 
*           while event status is changed.
* Cause: Optimization
********************************************************************************
* Version: 3.45
* Author/Date: ZengJX/2024.01.12
* Change: 1.Modify all local variable evtDebIdx's type from uint8 to uint16 
*           in function of Debounce.
*         2.Delete variable evtDebIdx's type converted from uint16 to uint8.
* Cause: Optimization
********************************************************************************
* Version: 3.46
* Author/Date: ZengJX/2024.02.26
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.47
* Author/Date: ZengJX/2024.02.28
* Change: Fix warning of coding specification.
* Cause: Optimization
********************************************************************************
* Version: 3.48
* Author/Date: ZengJX/2024.03.07
* Change: Optimize Dem_EventOperCycleReqHandle() to fix bug of aging counter
*         increasing repeatedly.
* Cause: Bugfix
********************************************************************************
* Version: 3.49
* Author/Date: ZengJX/2024.04.15
* Change: 1.UDS 14 service could clear both emissions-related and
*           non emissionsrelated DTC information.
*         2.Optimize comments specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.50
* Author/Date: ZengJX/2024.05.06
* Change: 1.Add the function Dem_EventDebCntBasedIncrement() and
*           Dem_EventDebCntBasedDecrement().
*         2.Add the operation of debounce counter increasing and decreasing after
*           debounce counter executing jump-up and jump-dowm.
* Cause: Optimization
********************************************************************************
* Version: 3.51
* Author/Date: ZengJX/2024.05.22
* Change: Modify the function of indicator failed operation and healing operation,
*         all the indicator operation should be processed in the operation cycle
*         that configured extraly.
* Cause: Optimization
********************************************************************************
* Version: 3.52
* Author/Date: ZengJX/2024.05.23
* Change: Fix QAC warning.
* Cause: Optimization
********************************************************************************
* Version: 3.53
* Author/Date: ZengJX/2024.07.05
* Change: 1.Add operation cycle queue for managing operation cycles in
*           Dem_EventOperCycleReqHandle.
*         2.Add event segmentation processing in Dem_EventOperCycleReqHandle().
*         3.Add definition of function Dem_OperCycleEnterQueue() and
*           Dem_OperCycleLeaveQueue().
*         4.Add trigger condition in function Dem_EventSetInitMonitorReason(),
*           Dem_EventCheckEnCondGrpChanged() and Dem_EventCheckStorCondGrpChanged().
* Cause: Optimization
********************************************************************************
* Version: 3.54
* Author/Date: ZengJX/2024.07.18
* Change: 1.Modify copyright information.
*         2.Fix Dem memmap issue.
* Cause: Optimization
********************************************************************************
* Version: 3.55
* Author/Date: ZengJX/2024.07.25
* Change: Modify OCC3 counter incrementing condition.
* Cause: Bugfix
********************************************************************************
* Version: 3.56
* Author/Date: ZengJX/2024.07.26
* Change: Add operation of clearing lamp failed counters when indicators healing.
* Cause: Bugfix
********************************************************************************
* Version: 3.57
* Author/Date: ZengJX/2024.07.31
* Change: Fix bug of setting DTC suppression in function Dem_EventManageCtrlInit(),
*         the DTC is suppressed if all combined events are not available.[SWS_Dem_00915]
* Cause: Bugfix
********************************************************************************
* Version: 3.58
* Author/Date: ZengJX/2024.08.12
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.59
* Author/Date: ZengJX/2024.08.15
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.60
* Author/Date: ZengJX/2024.09.18
* Change: Fix bug of lamp failed counter increasing in error when configuring
*         multiple lamps in the same event.
* Cause: Bugfix
********************************************************************************
* Version: 3.61
* Author/Date: ZengJX/2024.10.23
* Change: 1.PFC could be cleared at the end of warm-up cycle after 14 service
*           when no event is detected.
*         2.Add the function that indicator counter increases continuously.
* Cause: Update
********************************************************************************
* Version: 3.62
* Author/Date: ZengJX/2024.10.24
* Change: Modify the returned DTC format when request DEM_DTC_FORMAT_UDS in 
*         permanent event memory.
* Cause: Update
********************************************************************************
* Version: 3.63
* Author/Date: ZengJX/2024.11.04
* Change: Add the function about Dem OCC7 counter.
* Cause: Update
********************************************************************************
* Version: 3.64
* Author/Date: ZengJX/2024.11.07
* Change: 1.Delete the function about clearing the cntHeal when events aren't 
*           detected during the continuous operation cycles.
*         2.Fix an issue that the Permanent Fault Code was not cleared at the
*           end of the warm-up cycle.
* Cause: Bugfix
********************************************************************************
* Version: 3.65
* Author/Date: ZengJX/2024.11.13
* Change: Delete the check for whether the Tid value is greater than 0, the range
*         of Tid value is in [0, 255].
* Cause: Bugfix
********************************************************************************
* Version: 3.66
* Author/Date: ZengJX/2024.11.13
* Change: Delete the first/most recent confirmed/failed DTC information when
*         processing 14/04 service.
* Cause: Bugfix
********************************************************************************
* Version: 3.67
* Author/Date: ZengJX/2024.11.19
* Change: Add the DTC suppression calculating when DemAvailabilitySupport is
*         configured as DEM_NO_AVAILABILITY.
* Cause: Bugfix
********************************************************************************
* Version: 3.68
* Author/Date: ZengJX/2024.12.05
* Change: Fix the issue that freeze Frame data shall be captured at most once per
*         operation cycle.
* Cause: Bugfix
********************************************************************************
* Version: 3.69
* Author/Date: ZengJX/2024.12.06
* Change: Modify the parameter of the function Dem_GeneralCallbackEventStatusChange
*         from EventIdx to eventId.
* Cause: Bugfix
********************************************************************************
* Version: 3.70
* Author/Date: ZengJX/2024.12.15
* Change: 14 service should clear UDS DTC information when DEM_CFG_J1939SUPPORT
*         is enable.
* Cause: Bugfix
********************************************************************************
* Version: 3.71
* Author/Date: ZengJX/2025.01.14
* Change: Fix the bug that DTC couldn't be cleared when DemSuppressionSupport
*         configured as DEM_NO_SUPPRESSION.
* Cause: Bugfix
********************************************************************************
* Version: 3.72
* Author/Date: ZengJX/2025.01.21
* Change: Set clearing NvM block request status after clearing all events status
*         and entry.
* Cause: Bugfix
********************************************************************************
* Version: 3.73
* Author/Date: ZengJX/2025.02.07
* Change: 1.Optimize the execute time of function Dem_EventCheckEnCondGrpChanged
*           when enable condition status changed.
*         2.Modify copyright information.
* Cause: Optimization
********************************************************************************
* Version: 3.74
* Author/Date: ZengJX/2025.02.08
* Change: Add global variable Dem_DiagProcDTCIdx to record the processed DTC index
*         of diagnostic service.
* Cause: Optimization
********************************************************************************
* Version: 3.75
* Author/Date: ZengJX/2025.02.10
* Change: Fix the issue about the fault counter error when the events reported
*         and the operation cycle switched at the same time.
* Cause: Bugfix
********************************************************************************
* Version: 3.76
* Author/Date: ZengJX/2025.03.03
* Change: According to SWS_Dem_00344, reset the Dem-internal debounce algorithm
*         upon starting a new operation cycle.
* Cause: Bugfix
********************************************************************************
* Version: 3.77
* Author/Date: ZengJX/2025.03.24
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.78
* Author/Date: ZengJX/2025.04.03
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.79
* Author/Date: ZengJX/2025.04.03
* Change: Dem invokes the function NvM_WriteBlock and NvM_ReadBlock only when 
*         DEM_CFG_NVM_RW_SUPPORT is STD_ON.
* Cause: BugFix
********************************************************************************
* Version: 3.80
* Author/Date: ZengJX/2025.05.29
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.81
* Author/Date: ZengJX/2025.06.03
* Change: Add DTC format conversion in Dem_EventCalcDtcNextFilteredAllSupported 
*         to fix the bug that the format of the returned data in OBD 03/07 service
*         is error. 
* Cause: BugFix
********************************************************************************
* Version: 3.82
* Author/Date: ZengJX/2025.06.04
* Change: Fix an issue that the Permanent Fault Code was cleared abnormally after
*         OBD 04 service.
* Cause: BugFix
********************************************************************************
* Version: 3.83
* Author/Date: ZengJX/2025.06.05
* Change: Modify the OBD DTC aging condition.
* Cause: BugFix
********************************************************************************
* Version: 3.84
* Author/Date: ZengJX/2025.06.09
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.85
* Author/Date: ZengJX/2025.06.10
* Change: Fix Greenhills compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.86
* Author/Date: ZengJX/2025.06.16
* Change: Modify the permanent fault code clear condition. Fix the issue when more
*         than one event configure MIL, the permanent fault code couldn't be cleared.
* Cause: Optimization
********************************************************************************
* Version: 3.87
* Author/Date: ZengJX/2025.06.17
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.88
* Author/Date: ZengJX/2025.06.23
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.89
* Author/Date: ZengJX/2025.07.31
* Change: Fix the issue that PDTC bit is set in advance when prefailed is reported
*         multiple times.
* Cause: Bugfix
********************************************************************************
* Version: 3.90
* Author/Date: ZengJX/2025.08.04
* Change: Fix the bug of the first/most recent confirmed/failed DTC in Dem_EventMemoryInfo
*         can not be cleared after DTC aging.
* Cause: Bugfix
********************************************************************************
* Version: 3.91
* Author/Date: ZengJX/2025.08.04
* Change: Add macro DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT when call the function
*         NvM_SetRamBlockStatus.
* Cause: Bugfix
********************************************************************************
* Version: 3.92
* Author/Date: ZengJX/2025.08.20
* Change: Fixed the issue that fault displacement failed when the first DTC 
*         in the event memory with the lowest priority.
* Cause: Bugfix
********************************************************************************
* Version: 3.93
* Author/Date: ZengJX/2025.08.20
* Change: Fixed the issue that the data have location offsets when the 1906 service
*         requesting multiple extended data.
* Cause: Bugfix
********************************************************************************
* Version: 3.94
* Author/Date: ZengJX/2025.08.20
* Change: Clear debounce counter when starting a new operation cycle.
* Cause: Bugfix
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Dem.h"
#include "NvM.h"
#if(DEM_CFG_TRIGGERDLTREPORT == STD_ON)
#include "Dlt.h"
#endif
#if(DEM_CFG_TRIGGERDCMREPORT == STD_ON)
#include "Dcm.h"
#endif
#if( DEM_CFG_J1939SUPPORT == STD_ON )
#include "J1939Dcm.h"
#endif
#if(DEM_CFG_TRIGGERFIMREPORT == STD_ON)
#include "FiM.h"
#endif
#include "Dem_Event.h"
/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/*
********************************************************************************
*    Local Types
********************************************************************************
*/
/*
********************************************************************************
*    Local Variables
********************************************************************************
*/
#define DEM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(boolean, DEM_VAR_INIT) Dem_OperCycleProcessStart = TRUE;
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_GetFFRecDataCombEvtNext = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_GetFFRecDataSize = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_GetFFRecSizeCombEvtNext = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_GetFFRecSize = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_GetExRecDataCombEvtNext = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_GetExRecDataSize = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_GetExRecSizeCombEvtNext = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_GetExRecSize = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_GetAllExRecDataCombEvtNext = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_GetAllExRecDataSize = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_GetAllExRecSizeCombEvtNext = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_GetAllExRecSize = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_EventCalcDtcCnt = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_EventCalcDTCIndexDtcCnt = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_EventClearAllDtcCnt = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_EventClearGroupDTCCnt = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_EventClearSingleDTCCnt = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
#if(( DEM_CFG_MILINDICATORREF > DEM_BYTE_ZERO ) && ( DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT ))
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_PID21VehDriveTime = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint32, DEM_VAR_INIT) Dem_PID21VehDriveDistance = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint32, DEM_VAR_INIT) Dem_PID4DMilOnEngineRunTime = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
#endif
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint16, DEM_VAR_INIT) Dem_PID31VehDriveTime = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint32, DEM_VAR_INIT) Dem_PID31VehDriveDistance = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
/* PolySpace +1 MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Dem_8.9" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
static VAR(uint32, DEM_VAR_INIT) Dem_PID4EMilOnEngineRunTime = DEM_INIT_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Dem_Rule8.9 */
#endif
#if(DEM_CFG_EVENT_NUM > DEM_CFG_MAXEVTNUMPROCSPERCYCLE)
static VAR(uint16, DEM_VAR_INIT) Dem_EventSplitIdxStart = DEM_INIT_ONE;
#endif
#define DEM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define DEM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* Declare function Dem_EventDebCntBasedIncrement(). */
static FUNC(boolean, DEM_CODE) Dem_EventDebCntBasedIncrement
(
    uint16 EventIdx
);
/* Declare function Dem_EventDebCntBasedDecrement(). */
static FUNC(boolean, DEM_CODE) Dem_EventDebCntBasedDecrement
(
    uint16 EventIdx
);
static FUNC(void, DEM_CODE) Dem_EventClearDTCInfo
(
    uint16 EventIdx
);
#define DEM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define DEM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
* Function Name: Dem_EventPreInit
*
* Explanation: Initialization of event process, called in Dem_PreInit
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventPreInit(void)
{
    /* Initialization of enable condition groups status */
    Dem_EventEnCondInit();

    /* Initialization of store condition groups status */
    Dem_EventStorCondInit();

    /* Initializaiton of DTC control */
    Dem_EventDtcCtrlInit();
    
    /* Initialization of EVENT control */
    Dem_EventManageCtrlInit();
}

/*
********************************************************************************
* Function Name: Dem_EventEnCondInit
*
* Explanation: Initialization of event enable condition
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventEnCondInit(void)
{
    uint8 breakFlag = FALSE;
    uint16 grpIdx;
    uint16 condIdx;
    uint16 condCnt;

    /* Initialization of enable condition status. */
    for(condIdx = DEM_INIT_ONE; condIdx <= DEM_CFG_ENCOND_NUM; condIdx++)
    {
        DEM_SET_ENCOND(condIdx, DEM_ENABLECOND_CAL(condIdx));
    }
    /* Initialization of enable condition groups status. */
    for(grpIdx = DEM_INIT_ONE; grpIdx <= DEM_CFG_ENCOND_GROUP_NUM; grpIdx++)
    {
        DEM_SET_ENCONDGRP(grpIdx, TRUE);
        /* Check all enable condition in group. */
        for(condCnt = DEM_INIT_ZERO; condCnt < DEM_CFG_ENCONDGRP_MAX_REF_ENCOND_NUM; condCnt++)
        {
            condIdx = Dem_CfgEnConditionGrpTable[grpIdx].acEnCondIdx[condCnt];
            /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
            if(condIdx > DEM_INIT_ZERO)
            {
                if(FALSE == DEM_GET_ENCOND(condIdx))
                {
                    DEM_SET_ENCONDGRP(grpIdx, FALSE);
                    breakFlag = TRUE;
                }
            /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            }
            else
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                breakFlag = TRUE;
            }
            /* Unified break channel. */
            if(TRUE == breakFlag)
            {
                break;
            }
        }
    }
    /* Set the enable condition request status to TURE. */
    DEM_SET_ENCOND_REQ(TRUE);
}

/*
********************************************************************************
* Function Name: Dem_EventStorCondInit
*
* Explanation: Initialization of event storage condition
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventStorCondInit(void)
{
    uint8 breakFlag = FALSE;
    uint16 grpIdx;
    uint16 condIdx;
    uint16 condCnt;

    /* Initialization of storage condition status. */
    for(condIdx = DEM_INIT_ONE; condIdx <= DEM_CFG_STORCOND_NUM; condIdx++)
    {
        DEM_SET_STORCOND(condIdx, Dem_CfgStorConditionTable[condIdx].acStorCondSt);
    }
    /* Initialization of storage condition groups status. */
    for(grpIdx = DEM_INIT_ONE; grpIdx <= DEM_CFG_STORCOND_GROUP_NUM; grpIdx++)
    {
        DEM_SET_STORCONDGRP(grpIdx, TRUE);
        /* Check all storage condition in group. */
        for(condCnt = DEM_INIT_ZERO; condCnt < DEM_CFG_STORCONDGRP_MAX_REF_STORCOND_NUM; condCnt++)
        {
            condIdx = Dem_CfgStorConditionGrpTable[grpIdx].acStorCondIdx[condCnt];
            /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
            if(condIdx > DEM_INIT_ZERO)
            {
                if(FALSE == DEM_GET_STORCOND(condIdx))
                {
                    DEM_SET_STORCONDGRP(grpIdx, FALSE);
                    breakFlag = TRUE;
                }
            /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            }
            else
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                breakFlag = TRUE;
            }
            /* Unified break channel. */
            if(TRUE == breakFlag)
            {
                break;
            }
        }
    }
    /* Set the storage condition request status to TURE. */
    DEM_SET_STORCOND_REQ(TRUE);
}

/*
********************************************************************************
* Function Name: Dem_EventDtcCtrlInit
*
* Explanation: Initialization of event DTC control
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventDtcCtrlInit(void)
{
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
    uint16 dtcIdx;
#endif

    /* DTC status changed notification */
    DEM_SET_DTCCHANGEDNOTIF(FALSE);
    
    DEM_SET_DTC_CLEAR_STATUS(DEM_EVENT_CLEAR_DTC_STATUS_IDLE);
    
    DEM_SET_DTC_SETTING_DISABLE(FALSE);
    
    DEM_SET_DTC_SETTING_ENABLE(FALSE);
    
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
    /* Initialization of DTCs supression */
    for(dtcIdx = DEM_BYTE_ONE; dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++)
    {
        DEM_SET_DTCSUPPRESSION(dtcIdx, TRUE);
    }
#endif

    /* Initialization of DTC filter setting */
    DEM_SET_DTC_FILTER_ENABLE(FALSE);

    /* Initialization of Freeze frame filter setting */
    DEM_SET_FF_FILTER_ENABLE(FALSE);

    DEM_SET_DTC_RECORD_ENABLE(TRUE);

}

/*
********************************************************************************
* Function Name: Dem_EventManageCtrlInit
*
* Explanation: Initialization of event manage control
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventManageCtrlInit(void)
{
    uint8 indiIdx;
    uint8 evtMemIdx;
    uint16 evtIdx;
    uint16 compIdx;
    uint16 nvmBlkCnt;
    
    /* Initialization of component status. */
    for(compIdx = DEM_BYTE_ONE; compIdx <= DEM_CFG_COMP_NUM; compIdx++)
    {
        DEM_SET_COMP_AVAILABLE(compIdx, TRUE);
        DEM_SET_COMP_FAILED_STATUS(compIdx, FALSE);
        DEM_SET_COMP_FAILED_EVTIDX(compIdx, DEM_INIT_ZERO);
    }
    
    /* Initialization of events. */
    for(evtIdx = DEM_BYTE_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
    {
        /* Initialization of event available status. */
        DEM_SET_AVAIL(evtIdx, DEM_EVTAVAIL_CAL(evtIdx));
#if( DEM_CFG_CALIBSUPPORT == STD_ON )
        DEM_SET_INITAVAIL(evtIdx, DEM_EVTAVAIL_CAL(evtIdx));
#endif
        
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
        /* Calculate DTC suppression on event available status. */
        if(TRUE == DEM_GET_AVAIL(evtIdx))
        {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
            /* If exiting events in combined event group is available, set DTC suppression false.*/
            
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            DEM_SET_DTCSUPPRESSION(Dem_CfgEvtDtcIdx[evtIdx], FALSE);
#endif
        }
#else
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
        /* Init the DTC suppression when DemAvailabilitySupport is DEM_NO_AVAILABILITY. */
        DEM_SET_DTCSUPPRESSION(Dem_CfgEvtDtcIdx[evtIdx], FALSE);
#endif
#endif
        /* Initialization of Internal debounce counter. */
        DEM_SET_DEBCNT(evtIdx, DEM_DEBOUNCE_COUNTER_ZERO);
        DEM_SET_FDCCNT(evtIdx, DEM_DEBOUNCE_COUNTER_ZERO);
        DEM_SET_FDCCNTMAX_DCC(evtIdx, DEM_DEBOUNCE_COUNTER_ZERO);
        DEM_SET_DEBTIME(evtIdx, DEM_DEBOUNCE_COUNTER_ZERO);
        DEM_SET_DEBTIMER_BUFFER(evtIdx, DEM_EVENT_STATUS_NONE);
        DEM_SET_DEBOUNCE_STATUS(evtIdx, DEM_DEBOUNCE_STATUS_RESET);
        
        DEM_SET_MONITOR_REASON(evtIdx, DEM_INIT_MONITOR_NONE);
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
        DEM_SET_SSDATA_BUFFER_POS(evtIdx, DEM_INIT_ZERO);
        DEM_SET_SSDATA_FF_STORED(evtIdx, FALSE);
        DEM_SET_SSDATA_EX_STORED(evtIdx, FALSE);
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
        DEM_SET_SSDATA_OBD_STORED(evtIdx, FALSE);
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
        DEM_SET_SSDATA_WWHOBD_STORED(evtIdx, FALSE);
#endif
#endif
#endif
        DEM_RESET_TRIG(evtIdx, (uint8)DEM_TRIGGER_ON_NONE);

        for(indiIdx = DEM_BYTE_ZERO; indiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; indiIdx++)
        {
            DEM_SET_INDICATOR(evtIdx, indiIdx, FALSE);
        }
        DEM_SET_LAMPFAILCNT_UPDATED(evtIdx, FALSE);
        for(evtMemIdx = DEM_BYTE_ONE; evtMemIdx <= DEM_CFG_EVENT_MEMORY_NUM; evtMemIdx++)
        {
            DEM_SET_EVENT_STORED(evtIdx, evtMemIdx, FALSE);
            DEM_SET_EVENT_ENTRY(evtIdx, evtMemIdx, Dem_CfgEventMemoryTable[evtMemIdx].acEvtMemMaxEntry);
        }
    }

    /* Initialization of nvm block status. */
    for(nvmBlkCnt = DEM_BYTE_ONE; nvmBlkCnt <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkCnt++)
    {
        DEM_SET_NVM_STATUS(nvmBlkCnt, DEM_NVM_BLOCK_STATUS_NO_ERROR);
        DEM_SET_NVM_READ_REQ(nvmBlkCnt, FALSE);
        DEM_SET_NVM_WRITE_REQ(nvmBlkCnt, FALSE);
        DEM_SET_NVM_CLEAR_REQ(nvmBlkCnt, FALSE);
        DEM_SET_NVM_IME_STORE(nvmBlkCnt, FALSE);
    }
    DEM_SET_NVM_IME_STORE_REQ(FALSE);
    DEM_SET_NVM_STATE(DEM_NVM_STATE_IDLE);
    DEM_SET_NVM_IME_STORE_CNT(DEM_INIT_ZERO);
    DEM_SET_NVM_ACCESS_BLOCK_IDX(DEM_INIT_ZERO);
    DEM_SET_NVM_READ_REQ_STATUS(FALSE);
    DEM_SET_NVM_WRITE_REQ_STATUS(FALSE);
    DEM_SET_NVM_CLEAR_REQ_STATUS(FALSE);

    /* Initialization of indicator status. */
    for(indiIdx = DEM_BYTE_ONE; indiIdx <= DEM_CFG_INDICATOR_NUM; indiIdx++)
    {
        DEM_SET_INDICATOR_ON_CNT(indiIdx, DEM_INIT_ZERO);
        DEM_SET_INDICATOR_STATUS(indiIdx, DEM_INDICATOR_OFF);
    }

    /* Initialization of Event queue. */
    DEM_SET_QUEUE_ST(DEM_EVENT_QUEUE_IDLE);
    DEM_SET_QUEUE_POS(DEM_INIT_ZERO);
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
    DEM_SET_SSDATA_BUFFER_CNT(DEM_INIT_ZERO);
#endif

    /* Initialization of Operation Cycle queue. */
    DEM_SET_OPCYC_QUEUE_ST(DEM_EVENT_QUEUE_IDLE);
    DEM_SET_OPCYC_QUEUE_POS(DEM_INIT_ZERO);

    /* Initialization of Event monitor reason request. */
    DEM_SET_MONITOR_REASON_REQ(FALSE);

#if( DEM_CFG_EVENT_NUM > DEM_CFG_MAXEVTNUMPROCSPERCYCLE )
    DEM_SET_EVTAVAIL_SPLIT_CNT(DEM_INIT_ZERO);

    /* Initialization of Event processed start index in Dem_Mainfunction. */
    Dem_EventSplitIdxStart = DEM_INIT_ONE;
#endif /* DEM_CFG_EVENT_NUM > DEM_CFG_MAXEVTNUMPROCSPERCYCLE */

    /* Initialization of Dem_EventOperCycleReqHandle start to process operation cycle. */
    Dem_OperCycleProcessStart = TRUE;
}

/*
********************************************************************************
* Function Name: Dem_EventNvmBlockInit
*
* Explanation: Initialization of nvm blocks, called in Dem_Init
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventNvmBlockInit(void)
{
    uint8 retVal;
    uint8 errStatus = (uint8)DEM_NVM_REQ_NOT_OK;
    uint8 evtMemIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 slotCnt, entryIdx;
    uint8 entryValid[DEM_CFG_MAX_NUMBER_EVENT_ENTRY] = {FALSE};
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 nvmBlkIdx, evtIdx;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
    uint16 dtcIdx, combEvtIdx, combEvtCnt;
#endif
    Dem_EventMemoryInfo_st *info_ptr;
    Dem_EventMemoryEntry_st *entry_ptr;

    /* Check Nvm blocks status */
    for(nvmBlkIdx = DEM_INIT_ONE; nvmBlkIdx <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkIdx++)
    {
        DEM_SET_NVM_READ_REQ(nvmBlkIdx, FALSE);
        
        retVal = NvM_GetErrorStatus(Dem_CfgNvmBlockTable[nvmBlkIdx], &errStatus);

        if((E_NOT_OK == retVal) || (DEM_NVM_REQ_OK != errStatus))
        {
            /* Initialization of Nvm block error happened */
            DEM_SET_NVM_STATUS(nvmBlkIdx, DEM_NVM_BLOCK_STATUS_ERROR);
            break;
        }
    }

    if(nvmBlkIdx <= DEM_CFG_NVM_BLOCK_NUM)
    {
        /* Re-initialize ALL Nvm blocks with default value */
        for(nvmBlkIdx = DEM_INIT_ONE; nvmBlkIdx <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkIdx++)
        {
            DEM_SET_NVM_READ_REQ(nvmBlkIdx, FALSE);
            
            Dem_EventMemoryNvmInitialize(nvmBlkIdx);
        }
        DEM_SET_NVM_STATE(DEM_NVM_STATE_IDLE);
    }
    else
    {
        for(evtMemIdx = DEM_INIT_ONE; evtMemIdx <= DEM_CFG_EVENT_MEMORY_NUM; evtMemIdx++)
        {
            entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);
            info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(evtMemIdx);

            for( entryIdx = DEM_INIT_ZERO; entryIdx < DEM_CFG_MAX_NUMBER_EVENT_ENTRY; entryIdx++ )
            {
                entryValid[entryIdx] = FALSE;
            }

            for(slotCnt = DEM_INIT_ZERO; slotCnt < info_ptr->cntEnSlot; slotCnt++)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if( info_ptr->entryIdx[slotCnt] < Dem_CfgEventMemoryTable[evtMemIdx].acEvtMemMaxEntry )
                {
                    entryIdx = info_ptr->entryIdx[slotCnt];
                    entryValid[entryIdx] = TRUE;
                }
            }

            for(entryIdx = DEM_INIT_ZERO; entryIdx < Dem_CfgEventMemoryTable[evtMemIdx].acEvtMemMaxEntry; entryIdx++)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                if((FALSE == entryValid[entryIdx]) && (entry_ptr[entryIdx].evtId != DEM_INIT_ZERO))
                {
                    entry_ptr[entryIdx].evtId = DEM_INIT_ZERO;
                    /* Request update event memory entry block */
                    Dem_EventMemoryNvmBlkUpdateReq(evtMemIdx,
                                                   entryIdx,
                                                   DEM_NVM_REQ_WRITE,
                                                   FALSE);
                }
                
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                if(entry_ptr[entryIdx].evtId > DEM_INIT_ZERO)
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                    evtIdx = Dem_CfgEventIdTableIndex[entry_ptr[entryIdx].evtId];
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                    DEM_SET_EVENT_STORED(evtIdx, evtMemIdx, TRUE);
                    DEM_SET_EVENT_ENTRY(evtIdx, evtMemIdx, entryIdx);
                    
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
                    dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
                    for(combEvtCnt = DEM_INIT_ZERO; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
                    {
                        combEvtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[combEvtCnt];
                        if(combEvtIdx > DEM_INIT_ZERO)
                        {
                            DEM_SET_EVENT_STORED(combEvtIdx, evtMemIdx, TRUE);
                            DEM_SET_EVENT_ENTRY(combEvtIdx, evtMemIdx, entryIdx);
                        }
                        else
                        {
                            break;
                        }
                    }
#endif
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventIndicatorInit
*
* Explanation: Indicator status init
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventIndicatorInit(void)
{
    uint16 evtIdx;
    uint8 indiIdx;
    uint8 cntFail[DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM];
    
    for(evtIdx = DEM_BYTE_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
    {
        /* Initialization of indicator status */
        if(TRUE == DEM_GET_UDS_STATUS_WIR(evtIdx))
        {
            /* Retrieve all the indicators of the event. */
            for(indiIdx = DEM_INIT_ZERO; indiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; indiIdx++)
            {
                cntFail[indiIdx] = DEM_GET_LAMP_FAILED_CNT(evtIdx, indiIdx);
            }
            (void)Dem_EventCheckWarningIndicatorAct(evtIdx, cntFail);
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventOperCycleInit
*
* Explanation: Init OperCycle (if opercycle status not configure stored,
*              must be set the acCycleEndType to TRUE.(AutoSar limit)).
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventOperCycleInit(void)
{
    uint8 opcycIdx;
    uint16 evtIdx;

    /* For autostart/end type cycle, no need to store the operstatus, just start/end the cylce at init. */
    for(opcycIdx = DEM_INIT_ONE; opcycIdx <= DEM_CFG_OPCYC_NUM; opcycIdx++)
    {
        /* For autostart type, start this cycle. */
        /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(TRUE == Dem_CfgOperationCycleTable[opcycIdx].acCycleStartType)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            /* Push into Operation Cycle queue. */
            Dem_OperCycleEnterQueue(opcycIdx, DEM_OPERATION_CYCLE_START);
            DEM_SET_OPCYC_STATE(opcycIdx, DEM_CYCLE_STATE_END);
        }
        else
        {
#if( DEM_CFG_OPERATIONCYCLESTATUSSTORAGE == STD_OFF )
            /* For no-stored cycle, cycle state set to init. */
            DEM_SET_OPCYC_STATE(opcycIdx, DEM_CYCLE_STATE_END);
#endif
        }
    }

    /* Wait for processing all operation cycle in queue. */
    while(DEM_EVENT_QUEUE_BUSY == DEM_GET_OPCYC_QUEUE_ST())  /* PRQA S 2461 */ /* NSCA_QAC_Dem_Rule14.2 */
    {
        Dem_EventOperCycleReqHandle();
    }
    Dem_OperCycleProcessStart = FALSE;

    for(evtIdx = DEM_INIT_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
    {
        /* Clear TF bit if configured to no stored. */
#if(DEM_CFG_STATUSBITSTORAGETESTFAILED == STD_OFF)
        DEM_RESET_UDS_STATUS_TF(evtIdx);
#endif
        /* Re-calculate FDC according to debounce counter from NVM. */
        if((DEM_DEBOUNCE_COUNTER_BASED == Dem_CfgEvtDebCntCls[evtIdx]) &&
           (TRUE == Dem_CfgDebCounterTable[Dem_CfgEvtDebCntIdx[evtIdx]].acDebCntStor))
        {
            DEM_SET_DEBCNT(evtIdx, DEM_GET_STORED_DEBCNT(evtIdx));
            Dem_EventDebCntBasedToFDC(evtIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventOperCycleDeInit
*
* Explanation: shutdowm OperCycle If DemOperationCycleStatusStorage is set to FALSE
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventOperCycleDeInit(void)
{
    uint8 opcycIdx;

    /* If DemOperationCycleStatusStorage is set to FALSE a call of Dem_Shutdown, */ 
    /* shall end all operation cycles which are not stored in NVM. */
    for(opcycIdx = DEM_INIT_ONE; opcycIdx <= DEM_CFG_OPCYC_NUM; opcycIdx++)
    {
        if(DEM_CYCLE_STATE_START == DEM_GET_OPCYC_STATE(opcycIdx))
        {
#if(DEM_CFG_OPERATIONCYCLESTATUSSTORAGE == STD_OFF)
            /* Push into Operation Cycle queue. */
            Dem_OperCycleEnterQueue(opcycIdx, DEM_OPERATION_CYCLE_END);
#else
            /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
            if((DEM_OPCYC_OBD_DCY == Dem_CfgOperationCycleTable[opcycIdx].acCycType) &&
               (TRUE == Dem_CfgOperationCycleTable[opcycIdx].acCycleEndType))
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                /* Push into Operation Cycle queue. */
                Dem_OperCycleEnterQueue(opcycIdx, DEM_OPERATION_CYCLE_END);
            }
#endif /* DEM_CFG_OPERATIONCYCLESTATUSSTORAGE == STD_OFF */
        }
    }

    /* Wait for processing all operation cycle in queue. */
    while(DEM_EVENT_QUEUE_BUSY == DEM_GET_OPCYC_QUEUE_ST())  /* PRQA S 2461 */ /* NSCA_QAC_Dem_Rule14.2 */
    {
        Dem_EventOperCycleReqHandle();
    }
}

/*
********************************************************************************
* Function Name: Dem_EventOperCycleReInit
*
* Explanation: Re-init when operation cycle start
*
* param: evtIdx: index of event table
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventOperCycleReInit
(
    uint16 EventIdx
)
{
    uint8 failedCounter;
#if(DEM_CFG_INDICATORCNTINCREASEMODE == DEM_INIDICATOR_CNT_CONTINUOUSLY)
    uint8 indIdx;
#endif
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        /* Check event TFTOC bit. */
        if(TRUE == DEM_GET_UDS_STATUS_TFTOC(EventIdx))
        {
            /* Reset event lamp failed counter updated flag. */
            DEM_SET_LAMPFAILCNT_UPDATED(EventIdx, FALSE);
        }
#if(DEM_CFG_INDICATORCNTINCREASEMODE == DEM_INIDICATOR_CNT_CONTINUOUSLY)
        /* Clear the lamp counter when test not failed this operation cycle. */
        else
        {
            for(indIdx = DEM_INIT_ZERO; indIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; indIdx++)
            {
                DEM_SET_LAMP_FAILED_CNT(EventIdx, indIdx, DEM_INIT_ZERO);
            }
        }
#endif

        /* Event failed counter. */
        failedCounter = DEM_GET_UDS_FAILED_CNT(EventIdx);
        if(TRUE == DEM_GET_UDS_STATUS_TFTOC(EventIdx))
        {
            if(failedCounter < Dem_CfgEvtFcThrs[EventIdx])
            {
                failedCounter++;
            }
        }
        else
        {
            if(FALSE == DEM_GET_UDS_STATUS_TNCTOC(EventIdx))
            {
                failedCounter = DEM_INIT_ZERO;
            }
        }
        DEM_SET_UDS_FAILED_CNT(EventIdx, failedCounter);


        /* Clear status bit1 and set bit6. */
        DEM_RESET_UDS_STATUS_TFTOC(EventIdx);
        DEM_SET_UDS_STATUS_TNCTOC(EventIdx);

#if(DEM_CFG_UCTOCSUPPORT == STD_ON)
        if(TRUE == DEM_GET_STATUS_INDI_UCTOC(EventIdx))
        {
            DEM_RESET_STATUS_INDI_UCTOC(EventIdx);
        }
#endif
        /* Trigger the callback of DemInitMonitorForEvent. */
        Dem_EventSetInitMonitorReason(EventIdx, DEM_INIT_MONITOR_RESTART);

        /* Reset max debounce counter during current cycle. */
        DEM_SET_FDCCNTMAX_DCC(EventIdx, DEM_INIT_ZERO);

        /* Clear TRIGGER_ON_FDC_THRESHOLD_ONCE bit. */
        DEM_RESET_TRIG(EventIdx, (uint8)(~(uint8)DEM_TRIGGER_ON_FDC_THRESHOLD_ONCE));
        /* [SWS_Dem_00344] Reset the Dem-internal debounce algorithm upon starting a new operation cycle. */
        DEM_SET_DEBTIME(EventIdx, DEM_INIT_ZERO);
        DEM_SET_DEBTIMER_BUFFER(EventIdx, DEM_EVENT_STATUS_NONE);
        DEM_SET_DEBCNT(EventIdx, DEM_DEBOUNCE_COUNTER_ZERO);
    }
}

/*
********************************************************************************
* Function Name: Dem_EventOperCycleReqHandle
*
* Explanation: Operation cycle requeset handle
*
* param: void
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventOperCycleReqHandle(void)
{
    uint8 opcycIdx;
    uint8 agcycIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 opcycId;
    /* Polyspace +1 DEFECT:PARTIALLY_ACCESSED_ARRAY [JUstified:Unset] "NSCA_Polyspace_Dem_PartiallyAccessedArray" */
    uint8 evtOldSt[DEM_CFG_EVENT_NUM + DEM_BYTE_ONE] = {DEM_INIT_ZERO};
    uint8 opcycReqSt;
    uint8 reqOpcycIdx;
    uint16 evtIdx;
#if(DEM_CFG_EVENT_NUM > DEM_CFG_MAXEVTNUMPROCSPERCYCLE)
    uint16 eventIdxEnd;
#endif /* DEM_CFG_EVENT_NUM > DEM_CFG_MAXEVTNUMPROCSPERCYCLE */

    /* Check if OperCycle Queue status is busy. */
    if((DEM_EVENT_QUEUE_BUSY == DEM_GET_OPCYC_QUEUE_ST()) &&
        (TRUE == Dem_OperCycleProcessStart))
    {
        /* Check if OperCycle Queue is NULL. */
        if(DEM_INIT_ZERO < DEM_GET_OPCYC_QUEUE_REQ_IDX(DEM_INDEX_ZERO))
        {
            /* Get the first OperCycle index in queue. */
            reqOpcycIdx = DEM_GET_OPCYC_QUEUE_REQ_IDX(DEM_INDEX_ZERO);
            /* Get the first OperCycle req in queue. */
            opcycReqSt = DEM_GET_OPCYC_QUEUE_REQ_STATUS(DEM_INDEX_ZERO);

#if(DEM_CFG_EVENT_NUM > DEM_CFG_MAXEVTNUMPROCSPERCYCLE)
            /* Segmentation processing. */
            if((Dem_EventSplitIdxStart + DEM_CFG_MAXEVTNUMPROCSPERCYCLE) < DEM_CFG_EVENT_NUM)
            {
                eventIdxEnd = Dem_EventSplitIdxStart + DEM_CFG_MAXEVTNUMPROCSPERCYCLE - DEM_INDEX_ONE;
            }
            else
            {
                eventIdxEnd = DEM_CFG_EVENT_NUM;
            }
            for(evtIdx = Dem_EventSplitIdxStart; evtIdx <= eventIdxEnd; evtIdx++)
#else
            for(evtIdx = DEM_INDEX_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
#endif /* DEM_CFG_EVENT_NUM > DEM_CFG_MAXEVTNUMPROCSPERCYCLE */
            {
                evtOldSt[evtIdx] = DEM_GET_UDS_STATUS(evtIdx);
                /* Get the event operation cycle index. */
                opcycIdx = Dem_CfgEventTable[evtIdx].acEvtOpcycIdx;
                /* Get the event aging cycle index. */
                agcycIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acAgeOpcycIdx;

                if((reqOpcycIdx == opcycIdx) || (reqOpcycIdx == agcycIdx))
                {
                    /* Aging operation cycle handle. */
                    opcycId = Dem_CfgOperationCycleTable[reqOpcycIdx].acCycleId;
                    if(DEM_OPERATION_CYCLE_START == opcycReqSt)
                    {
                        /* Start operation cycle. */
                        Dem_EventOperCycleStart(evtIdx, opcycId);
                    }
                    else if(DEM_OPERATION_CYCLE_END == opcycReqSt)
                    {
                        /* End operation cycle. */
                        Dem_EventOperCycleEnd(evtIdx, opcycId);
                    }
                    /* Restart operation cycle. */ 
                    else if(DEM_OPERATION_CYCLE_RESTART == opcycReqSt)
                    {
                        /* Restart operation cycle: firstly excute end then start. */
                        Dem_EventOperCycleEnd(evtIdx, opcycId);
                        Dem_EventOperCycleStart(evtIdx, opcycId);
                    }
                    else
                    {
                        /* Do nothing. */
                    }
                }

                if(((DEM_OPERATION_CYCLE_START == opcycReqSt) ||
                    (DEM_OPERATION_CYCLE_RESTART == opcycReqSt)) &&
                   (reqOpcycIdx == Dem_CfgEventTable[evtIdx].acEvtOpcycIdx))
                {
                    Dem_EventOperCycleReInit(evtIdx);
                }

                /* Check if the event dtc is changed. */
                if(evtOldSt[evtIdx] != DEM_GET_UDS_STATUS(evtIdx))
                {
                    Dem_EventTriggerEventStatusChangedCbk(evtIdx, evtOldSt[evtIdx], DEM_GET_UDS_STATUS(evtIdx));
#if( DEM_CFG_GENERALINTERFACESUPPORT == STD_ON )
                    Dem_GeneralEventTriggerEventStatusChangedCbk(evtIdx, evtOldSt[evtIdx], DEM_GET_UDS_STATUS(evtIdx));
#endif /* DEM_CFG_GENERALINTERFACESUPPORT == STD_ON */
                    Dem_EventTriggerDtcStatusChangedCbk(evtIdx, evtOldSt[evtIdx], DEM_GET_UDS_STATUS(evtIdx));

                    /* Trigger EventMemory status block update. */
                    Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO, 
                                                DEM_NVM_STATUS_BLOCK, 
                                                DEM_NVM_REQ_WRITE, 
                                                Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acImdiStor);
                }
            }

#if(DEM_CFG_EVENT_NUM > DEM_CFG_MAXEVTNUMPROCSPERCYCLE)
            /* Segmentation processing is over. */
            if(evtIdx > DEM_CFG_EVENT_NUM)
            {
                Dem_EventOperCycleProcess();
                Dem_EventSplitIdxStart = DEM_INDEX_ONE;
            }
            /* Jump to the next segment. */
            else
            {
                Dem_EventSplitIdxStart = eventIdxEnd + DEM_INDEX_ONE;
            }
#else
            Dem_EventOperCycleProcess();
#endif
        }
    }
    Dem_OperCycleProcessStart = TRUE;
}

/*
********************************************************************************
* Function Name: Dem_OperCycleEnterQueue
*
* Explanation: Process of operation cycle entering into OperCycle queue.
*
* param: uint8 opcyIdx: The index of operation cycle.
*        uint8 opcycReqState: New operation cycle state: (re-)start or end.
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_OperCycleEnterQueue
(
    uint8 opcyIdx,
    uint8 opcycReqState
)
{
    uint8 quePos;

    /* Check if the operation cycle index is vaild. */
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((DEM_INDEX_ZERO < opcyIdx) && (DEM_CFG_OPCYC_NUM >= opcyIdx))
    {
        Dem_EnterCritical_0();
        /* Get the position of OperCycle Queue. */
        quePos = DEM_GET_OPCYC_QUEUE_POS();
        /* Check if overflow the max range of the queue. */
        if(DEM_OPERCYCLE_QUEUE_SIZE > quePos)
        {
            /* Push into queue. */
            DEM_SET_OPCYC_QUEUE_REQ_IDX(quePos, opcyIdx);
            DEM_SET_OPCYC_QUEUE_REQ_STATUS(quePos, opcycReqState);
            DEM_SET_OPCYC_QUEUE_POS(quePos + DEM_INDEX_ONE);
            DEM_SET_OPCYC_QUEUE_ST(DEM_EVENT_QUEUE_BUSY);
        }
        Dem_LeaveCritical_0();
    }
}

/*
********************************************************************************
* Function Name: Dem_OperCycleLeaveQueue
*
* Explanation: Process of operation cycle leaving the OperCycle queue.
*
* param: void
*
* retval: None
********************************************************************************
*/

/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_OperCycleLeaveQueue(void)
{
    uint8 quePos;

    Dem_EnterCritical_0();
    /* Check if OperCycle Queue is empty. */
    if(DEM_INDEX_ZERO < DEM_GET_OPCYC_QUEUE_POS())
    {
        /* Clear the first one of the OperCycle Queue. */
        /* PolySpace +1 MISRA-C3:14.2 [Justified:Unset] "NSCA_Polyspace_Dem_14.2" */
        for(quePos = DEM_INIT_ZERO; (quePos + DEM_INDEX_ONE) < DEM_GET_OPCYC_QUEUE_POS(); quePos++)
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            DEM_SET_OPCYC_QUEUE_REQ_IDX(quePos, DEM_GET_OPCYC_QUEUE_REQ_IDX(quePos + DEM_INDEX_ONE));
            DEM_SET_OPCYC_QUEUE_REQ_STATUS(quePos, DEM_GET_OPCYC_QUEUE_REQ_STATUS(quePos + DEM_INDEX_ONE));
        }
        DEM_SET_OPCYC_QUEUE_REQ_IDX(quePos, DEM_INDEX_ZERO);
        DEM_SET_OPCYC_QUEUE_REQ_STATUS(quePos, DEM_OPERATION_CYCLE_NONE);
        DEM_SET_OPCYC_QUEUE_POS(DEM_GET_OPCYC_QUEUE_POS() - DEM_INDEX_ONE);
    }

    /* If queue is empty, set the queue status as DEM_EVENT_QUEUE_IDLE. */
    if(DEM_INDEX_ZERO == DEM_GET_OPCYC_QUEUE_POS())
    {
        DEM_SET_OPCYC_QUEUE_ST(DEM_EVENT_QUEUE_IDLE);
    }
    Dem_LeaveCritical_0();
}

/*
********************************************************************************
* Function Name: Dem_EventOperCycleProcess
*
* Explanation: Operation cycle request process
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventOperCycleProcess(void)
{
    uint8 opcycReqSt;
    uint8 reqOpcycIdx;

    /* Check if OperCycle Queue Status is busy. */
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if(DEM_EVENT_QUEUE_BUSY == DEM_GET_OPCYC_QUEUE_ST())
    {
        /* Check if OperCycle Queue is NULL. */
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if(DEM_INIT_ZERO < DEM_GET_OPCYC_QUEUE_REQ_IDX(DEM_INDEX_ZERO))
        {
            /* Get the first OperCycle index in queue. */
            reqOpcycIdx = DEM_GET_OPCYC_QUEUE_REQ_IDX(DEM_INDEX_ZERO);
            /* Get the first OperCycle req in queue. */
            opcycReqSt = DEM_GET_OPCYC_QUEUE_REQ_STATUS(DEM_INDEX_ZERO);

            if((DEM_OPERATION_CYCLE_START == opcycReqSt) ||
                (DEM_OPERATION_CYCLE_RESTART == opcycReqSt))
            {
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
                /* Initialization of OBD related. */
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(DEM_OPCYC_OBD_DCY == Dem_CfgOperationCycleTable[reqOpcycIdx].acCycType)
                {
                    Dem_ObdDrivingCycleStart();
                }
                else if(DEM_OPCYC_WARMUP == Dem_CfgOperationCycleTable[reqOpcycIdx].acCycType)
                {
                    Dem_ObdWarmUpCycleStart();
                }
                else if(DEM_OPCYC_IGNITION == Dem_CfgOperationCycleTable[reqOpcycIdx].acCycType)
                {
                    Dem_ObdIgnitionCycleStart();
                }
                else
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    /* Do nothing. */
                }
#endif /* DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT */
                DEM_SET_OPCYC_STATE(reqOpcycIdx, DEM_CYCLE_STATE_START);
            }
            else if(DEM_OPERATION_CYCLE_END == opcycReqSt)
            {
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
                /* Initialization of OBD related. */
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(DEM_OPCYC_OBD_DCY == Dem_CfgOperationCycleTable[reqOpcycIdx].acCycType)
                {
#if( DEM_CFG_WWH_OBD_SUPPORT == STD_ON )
                    Dem_ObdAgingWwhB1Counter();
                    Dem_ObdCalcWwhContiMiCounterHaltCycle();
#endif
                }
                else if(DEM_OPCYC_WARMUP == Dem_CfgOperationCycleTable[reqOpcycIdx].acCycType)
                {
#if( DEM_CFG_WWH_OBD_SUPPORT == STD_ON )
                    Dem_ObdAgingWwhContiMiCounter();
#endif
                }
                else
                {
                    /* Do nothing. */
                }
#endif /* DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT */
                DEM_SET_OPCYC_STATE(reqOpcycIdx, DEM_CYCLE_STATE_END);
            }
            else
            {
                /* Do nothing. */
            }
        }
        Dem_OperCycleLeaveQueue();
    }
}

/*
********************************************************************************
* Function Name: Dem_EventOperCycleStart
*
* Explanation: In case of Operation cycle start detected,
*              start to event process.
*
* param: uint16 EventIdx, index of event table
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventOperCycleStart
(
    uint16 EventIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 OpcycId
)
{
    uint8 evtMemCnt, evtMemIdx;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        for(evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++)
        {
            evtMemIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acEvtMemIdx[evtMemCnt];
            if(evtMemIdx > DEM_INIT_ZERO)
            {
                Dem_EventMemoryEntryOpcycStart(EventIdx, evtMemIdx, OpcycId);
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventOperCycleEnd
*
* Explanation: in case of Operation cycle end detected,
*              start to event process.
*
* param: uint16 EventIdx, index of event table
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventOperCycleEnd
(
    uint16 EventIdx, 
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 OpcycId
)
{
    uint8 evtMemCnt, evtMemIdx;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        for(evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++)
        {
            evtMemIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acEvtMemIdx[evtMemCnt];
            if(evtMemIdx > DEM_INIT_ZERO)
            {
                Dem_EventMemoryEntryOpcycEnd(EventIdx, evtMemIdx, OpcycId);
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventReportBeforeInit
*
* Explanation: Handle of reported event(BSW) before Dem init
*
* param: EventIdx: index of event table.
*        EventStatus: Monitor test result.
*
* retval: E_NOT_OK, report is not accepted;E_OK, report is accepted
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_EventReportBeforeInit
(
    uint16 EventIdx, 
    Dem_EventStatusType EventStatus
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 evtStDeb;

    if(((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM)) &&
       ((DEM_DEBOUNCE_NONE == Dem_CfgEvtDebCntCls[EventIdx]) ||
        ((DEM_DEBOUNCE_COUNTER_BASED == Dem_CfgEvtDebCntCls[EventIdx]) && 
        (FALSE == Dem_CfgDebCounterTable[Dem_CfgEvtDebCntIdx[EventIdx]].acDebCntStor))))
    {
        /* Enable condition is fullfiled and debounce counter is not stored in nvm */
        if((TRUE == Dem_EventGetEnCondGrpStatus(Dem_CfgEventTable[EventIdx].awEvtEnCondGrpIdx)) &&
           (Dem_CfgEventTable[EventIdx].acEvtRepBhv == REPORT_BEFORE_INIT))
        {
            /* Reported test status is accepted, execute debounce */
            DEM_SET_DEBOUNCE_STATUS(EventIdx, DEM_DEBOUNCE_STATUS_RESET);
            evtStDeb = Dem_EventDebounceExecute(EventIdx, EventStatus);

            if((DEM_INIT_ZERO == (DEM_GET_TRIG(EventIdx) & DEM_TRIGGER_ON_FDC_THRESHOLD_ONCE)) &&
               ((DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED == EventStatus) ||
                (DEM_GET_FDCCNT(EventIdx) >=
                 (sint8)Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acFdcEvtMemStorThrs)))
            {
                DEM_SET_TRIG(EventIdx, DEM_TRIGGER_ON_FDC_THRESHOLD);
            }
            
            /* Push into queue */            
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
            if((E_OK == Dem_EventQueueEnter(EventIdx, evtStDeb)) &&
                (DEM_GET_SSDATA_BUFFER_CNT() < DEM_CFG_MAXNUMBEREVENTENTRYEVENTBUFFER))
            {
                Dem_EventSyncSnapShotDataStore(EventIdx); 
            }
#else
            /* PolySpace +1 MISRA-C3:17.7 [Justified:Unset] "NSCA_Polyspace_Dem_17.7" */
            Dem_EventQueueEnter(EventIdx, evtStDeb);  /* PRQA S 3200 */ /* NSCA_QAC_Dem_Rule17.7 */
#endif
            
            ret = E_OK;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventReportAfterInit
*
* Explanation: Handle of reported event after Dem init
*
* param: EventIdx: index of event table.
*        eventStatus: Monitor test result.
*
* retval: E_NOT_OK, report is not accepted;E_OK, report is accepted
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_EventReportAfterInit
(
    uint16 EventIdx, 
    Dem_EventStatusType EventStatus
)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean evtAccept = FALSE;
    uint8 evtStDeb, evtDtcSt;
    
    /* Related Operation cycle has started */
#if(DEM_CFG_OBDSUPPORT == DEM_OBD_NO_OBD_SUPPORT)
    if(((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM)) &&
       (DEM_CYCLE_STATE_START == DEM_GET_OPCYC_STATE(Dem_CfgEventTable[EventIdx].acEvtOpcycIdx)))
#else
    if(((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM)) &&
       /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
       ((DEM_CYCLE_STATE_START == DEM_GET_OPCYC_STATE(Dem_CfgEventTable[EventIdx].acEvtOpcycIdx)) ||
        (((Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acObdDtcIdx > DEM_INIT_ZERO) ||
          (Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acWwhObdClass > DEM_DTC_WWHOBD_CLASS_NOCLASS)) &&
         (DEM_OPCYC_OBD_DCY == Dem_CfgOperationCycleTable[Dem_CfgEventTable[EventIdx].acEvtOpcycIdx].acCycType))))
#endif
    {
        /* Enable condition is fullfiled */
        if((TRUE == Dem_EventGetEnCondGrpStatus(Dem_CfgEventTable[EventIdx].awEvtEnCondGrpIdx)) &&
           (DEM_EVENT_CLEAR_DTC_STATUS_IDLE == DEM_GET_DTC_CLEAR_STATUS()))
        {
            /* Save current status byte and FDC value */
            evtDtcSt = DEM_GET_UDS_STATUS(EventIdx);
            
            /* Reported test status is accepted, execute debounce */
            DEM_SET_DEBOUNCE_STATUS(EventIdx, DEM_DEBOUNCE_STATUS_RESET);
            evtStDeb = Dem_EventDebounceExecute(EventIdx, EventStatus);
            
#if(DEM_CFG_EXTENDSTATUSBYTE != DEM_INIT_ZERO)
            Dem_EventExStatusHandle(EventIdx);
#endif
            if((DEM_INIT_ZERO == (DEM_GET_TRIG(EventIdx) & DEM_TRIGGER_ON_FDC_THRESHOLD_ONCE)) &&
               ((DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED == EventStatus) ||
                (DEM_GET_FDCCNT(EventIdx) >=
                 (sint8)Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acFdcEvtMemStorThrs)))
            {
                DEM_SET_TRIG(EventIdx, DEM_TRIGGER_ON_FDC_THRESHOLD);
            }

            if(DEM_EVENT_STATUS_FAILED == evtStDeb)
            {
                if(E_NOT_OK == Dem_EventCheckConsecutiveFault(EventIdx))
                {
                    DEM_RESET_UDS_STATUS_TNCSLC(EventIdx);
                    DEM_RESET_UDS_STATUS_TNCTOC(EventIdx);
                    DEM_SET_UDS_STATUS_TFTOC(EventIdx);
                    DEM_SET_UDS_STATUS_TFSLC(EventIdx);
                    
                    if(FALSE == DEM_GET_UDS_STATUS_TF(EventIdx))
                    {
                        DEM_SET_UDS_STATUS_TF(EventIdx);
                        DEM_SET_TRIG(EventIdx, DEM_TRIGGER_ON_TEST_FAILED);
                        
                        Dem_EventCalcOccurenceCounter(EventIdx);
                    }
                }
            }
            else if(DEM_EVENT_STATUS_PASSED == evtStDeb)
            {
                DEM_RESET_UDS_STATUS_TNCSLC(EventIdx);
                DEM_RESET_UDS_STATUS_TNCTOC(EventIdx);
                if(TRUE == DEM_GET_UDS_STATUS_TF(EventIdx))
                {
                    DEM_RESET_UDS_STATUS_TF(EventIdx);
                    DEM_SET_TRIG(EventIdx, DEM_TRIGGER_ON_PASSED);
                }
            }
            else
            {
                if(DEM_GET_FDCCNT(EventIdx) >=
                   (sint8)Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acFdcEvtMemStorThrs)
                {
                    evtAccept = TRUE;
                }
            }

            if((evtDtcSt != DEM_GET_UDS_STATUS(EventIdx)) || (TRUE == evtAccept))
            {
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
                if((E_OK == Dem_EventQueueEnter(EventIdx, evtDtcSt)) &&
                   (DEM_GET_SSDATA_BUFFER_CNT() < DEM_CFG_MAXNUMBEREVENTENTRYEVENTBUFFER))
                {
                    Dem_EventSyncSnapShotDataStore(EventIdx);
                }
#else
                
                /* PolySpace +1 MISRA-C3:17.7 [Justified:Unset] "NSCA_Polyspace_Dem_17.7" */
                Dem_EventQueueEnter(EventIdx, evtDtcSt);  /* PRQA S 3200 */ /* NSCA_QAC_Dem_Rule17.7 */
#endif
            }

            ret = E_OK;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventStatusReport
*
* Explanation: The interface has an asynchronous behavior, because
*              the processing of the event is done within the Dem main function.
*              OBD Events Suppression shall be ignored for this computation.
*
* param: EventIdx: index of event table.
*        EventStatus: Monitor test result.
*
* retval: E_NOT_OK, report is not accepted;E_OK, report is accepted
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EventStatusReport
(
    uint16 EventIdx,
    Dem_EventStatusType EventStatus
)
{
    Std_ReturnType ret = E_NOT_OK;
    
    if(E_NOT_OK == Dem_EventCheckDtcSettingDisable(EventIdx))
    {
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
        /* Event is available */
        if(((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM)) &&
           (TRUE == DEM_GET_AVAIL(EventIdx)))
#endif
        {
            /* Events reported before init */
            if(DEM_MODULE_STATE_PREINIT == Dem_Manage.initSt)
            {
                ret = Dem_EventReportBeforeInit(EventIdx, EventStatus);
            }
            else
            {
                ret = Dem_EventReportAfterInit(EventIdx, EventStatus);
            }
        }
    }
    else
    {
        /* In case of DTC setting is disable by DCM, just ignore all events reported and return E_NOT_OK */
        /* Processing the debounce counter according to DemDebounceBehavior */
        Dem_EventDebounceBehavior(EventIdx);
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventQueueEnter
*
* Explanation: Push events into event queue for asynchronous event process.
*
* param: uint16 EventIdx:  Index of event table.
         uint16 *EventPos: The position of the new event in queue buffer.
*
* retval: E_NOT_OK, failed to enter queue; E_OK, success to enter queue
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_EventQueueEnter
(
    uint16 EventIdx,
    uint16 evtDtcSt
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint16 queIdx, quePos, queLen;    

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        if(DEM_MODULE_STATE_PREINIT == DEM_GET_MODULE_INIT_STATE())
        {
            /* Only for BSW events reported before init */
            if((DEM_EVENT_KIND_BSW == Dem_CfgEventTable[EventIdx].acEvtKind) && 
               (REPORT_BEFORE_INIT == Dem_CfgEventTable[EventIdx].acEvtRepBhv))
            {
#if(DEM_EVENT_BSW_QUEUE_LEN > DEM_INIT_ZERO)
                queLen = DEM_EVENT_BSW_QUEUE_LEN;
#else
                queLen = DEM_EVENT_QUEUE_LEN;
#endif
            }
            else
            {
                queLen = DEM_INIT_ZERO;
            }
        }
        else
        {
            queLen = DEM_EVENT_QUEUE_LEN;
        }

        /* Ready to Push into queue */
        Dem_EnterCritical_0();
        quePos = DEM_GET_QUEUE_POS();
        if(quePos < queLen)
        {
            for(queIdx = DEM_INIT_ZERO; queIdx < quePos; queIdx++)
            {                
                if(Dem_CfgEventTable[EventIdx].awEvtId == DEM_GET_QUEUE_BUF(queIdx))
                {
                    /* already in queue */
                    DEM_SET_QUEUE_UDS_STATUS(quePos, (uint8)evtDtcSt);
                    break;
                }
            }
            if(queIdx == quePos)
            {
                /* Push into queue */
                DEM_SET_QUEUE_BUF(quePos, Dem_CfgEventTable[EventIdx].awEvtId);
                DEM_SET_QUEUE_POS(quePos + DEM_BYTE_ONE);
                DEM_SET_QUEUE_ST(DEM_EVENT_QUEUE_BUSY);
                DEM_SET_QUEUE_UDS_STATUS(quePos, (uint8)evtDtcSt);                
            }            
            ret = E_OK;
        }
        Dem_LeaveCritical_0();
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventQueueExist
*
* Explanation: Get the position of requested event in the queue buffer
*
* param: uint16 EventIdx: index of event table.
*        uint16 *EventPos, the position of this event in queue buffer
*
* retval: E_OK, event already in queue, E_NOT_OK, event is not in queue
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventQueueExist
(
    uint16 EventIdx,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) EventPos
)
{
    uint8 ret = E_NOT_OK;
    uint16 queIdx;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        for(queIdx = DEM_INIT_ZERO; queIdx < DEM_GET_QUEUE_POS(); queIdx++)
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            if(Dem_CfgEventTable[EventIdx].awEvtId == DEM_GET_QUEUE_BUF(queIdx))
            {
                ret = E_OK;
                /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                *EventPos = queIdx;
                break;
            }
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventQueueProcBSW
*
* Explanation: Processing of BSW events which reported before init.
*
* param: none
*
* retval: none
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventQueueProcBSW(void)
{
    uint8 evtDtcSt, opcycIdx;
    uint16 quePos, evtIdx;
    
    /* Update UDS DTC status from event queue buffer, if there are events reported before init */
    if(DEM_EVENT_QUEUE_BUSY == DEM_GET_QUEUE_ST())
    {
        for(quePos = DEM_INIT_ZERO; quePos < DEM_GET_QUEUE_POS(); quePos++)
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            if((DEM_GET_QUEUE_BUF(quePos) > DEM_INIT_ZERO) &&
               (DEM_GET_QUEUE_BUF(quePos) <= DEM_CFG_EVENT_ID_MAX))
            {
                evtIdx = Dem_CfgEventIdTableIndex[DEM_GET_QUEUE_BUF(quePos)];
            }
            else
            {
                evtIdx = DEM_INIT_ZERO;
            }
            if((evtIdx > DEM_INIT_ZERO) && (evtIdx <= DEM_CFG_EVENT_NUM))
            {
                opcycIdx = Dem_CfgEventTable[evtIdx].acEvtOpcycIdx;
            }
            else
            {
                opcycIdx = DEM_INIT_ZERO;
            }
            
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
            if((evtIdx > DEM_INIT_ZERO) &&
               (opcycIdx > DEM_INIT_ZERO) &&
               (DEM_CYCLE_STATE_START == DEM_GET_OPCYC_STATE(opcycIdx)))
#else
            if((evtIdx > DEM_INIT_ZERO) &&
               (opcycIdx > DEM_INIT_ZERO) &&
               ((DEM_CYCLE_STATE_START == DEM_GET_OPCYC_STATE(opcycIdx)) ||
                (DEM_OPCYC_OBD_DCY == Dem_CfgOperationCycleTable[opcycIdx].acCycType)))
#endif
            {            
#if(DEM_CFG_EXTENDSTATUSBYTE != DEM_INIT_ZERO)
                Dem_EventExStatusHandle(evtIdx);
#endif
                evtDtcSt = DEM_GET_UDS_STATUS(evtIdx);
                if(DEM_EVENT_STATUS_FAILED == DEM_GET_QUEUE_UDS_STATUS(quePos))
                {                    
                    if(E_NOT_OK == Dem_EventCheckConsecutiveFault(evtIdx))
                    {
                        DEM_RESET_UDS_STATUS_TNCSLC(evtIdx);
                        DEM_RESET_UDS_STATUS_TNCTOC(evtIdx);
                        
                        if(FALSE == DEM_GET_UDS_STATUS_TF(evtIdx))
                        {
                            DEM_SET_UDS_STATUS_TF(evtIdx);
                            DEM_SET_TRIG(evtIdx, DEM_TRIGGER_ON_TEST_FAILED);
                            
                            Dem_EventCalcOccurenceCounter(evtIdx);
                        }
                        DEM_SET_UDS_STATUS_TFTOC(evtIdx);
                        DEM_SET_UDS_STATUS_TFSLC(evtIdx);

                        DEM_SET_QUEUE_UDS_STATUS(quePos, evtDtcSt);
                    }
                    else
                    {
                        DEM_SET_QUEUE_BUF(quePos, DEM_INIT_ZERO);
                    }
                }
                else if(DEM_EVENT_STATUS_PASSED == DEM_GET_QUEUE_UDS_STATUS(quePos))
                {
                    DEM_RESET_UDS_STATUS_TNCSLC(evtIdx);
                    DEM_RESET_UDS_STATUS_TNCTOC(evtIdx);
                    
                    if(TRUE == DEM_GET_UDS_STATUS_TF(evtIdx))
                    {
                        DEM_RESET_UDS_STATUS_TF(evtIdx);
                        DEM_SET_TRIG(evtIdx, DEM_TRIGGER_ON_PASSED);
                    }

                    DEM_SET_QUEUE_UDS_STATUS(quePos, evtDtcSt);
                }
                else
                {
                    if(DEM_GET_FDCCNT(evtIdx) <
                       (sint8)Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acFdcEvtMemStorThrs)
                    {
                        DEM_SET_QUEUE_BUF(quePos, DEM_INIT_ZERO);
                    }
                }
            }
        }
    }

}

/*
********************************************************************************
* Function Name: Dem_EventQueueProcess
*
* Explanation: process reported events in queue buffer.
*
* param: none
*
* retval: none
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventQueueProcess(void)
{
    uint8 oldDtcStatus;
    uint16 queIdx;
    uint16 evtIdx;
    uint16 queBuf;
    uint16 evtCnt;
    
    if(DEM_EVENT_QUEUE_BUSY == DEM_GET_QUEUE_ST())
    {
        /* process queue buffer */
        for(evtCnt = DEM_INIT_ZERO; evtCnt < DEM_BYTE_TWENTY; evtCnt++)
        {
            Dem_EnterCritical_0();
            queIdx = DEM_GET_QUEUE_POS();
            if(DEM_INIT_ZERO == queIdx)
            {
                /* Clear the event queue */
                DEM_SET_QUEUE_ST(DEM_EVENT_QUEUE_IDLE);
                DEM_SET_QUEUE_POS(DEM_INIT_ZERO);
                Dem_LeaveCritical_0();
                break;
            }
            else
            {
                --queIdx;
                DEM_SET_QUEUE_POS(queIdx);
            }
            /* Get event DTC status byte according to queEvtId */
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            oldDtcStatus = DEM_GET_QUEUE_UDS_STATUS(queIdx);            
            queBuf = DEM_GET_QUEUE_BUF(queIdx);
            Dem_LeaveCritical_0();

            if(queBuf <= DEM_CFG_EVENT_ID_MAX)
            {
                evtIdx = Dem_CfgEventIdTableIndex[queBuf];
            }
            else
            {
                evtIdx = DEM_INIT_ZERO;
            }           
            
            if((queBuf > DEM_INIT_ZERO) &&
               ((evtIdx > DEM_INIT_ZERO) && (evtIdx <= DEM_CFG_EVENT_NUM)))
            {
                if(TRUE == Dem_EventGetStorCondGrpStatus(Dem_CfgEventTable[evtIdx].acEvtStorCondGrpIdx))
                {
                    /* Reported as Test Failed or FDC reached */
                    if((DEM_GET_FDCCNT(evtIdx) >=
                        (sint8)Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acFdcEvtMemStorThrs))
                    {
                        Dem_EventProcStatusByte(evtIdx);

                        Dem_EventProcMemEntryAsFail(evtIdx, oldDtcStatus);
                    
                        Dem_EventStorCondPassedHandle(evtIdx);
                    }
                    /* Reported as Test Passed */
                    else
                    {
                        Dem_EventProcMemEntryAsPass(evtIdx, oldDtcStatus);
                    }

                    /* Check if the freezeframe data captured in this operation cycle. */
                    if(DEM_TRIGGER_ON_FDC_THRESHOLD_ONCE == 
                              (DEM_GET_TRIG(evtIdx) & DEM_TRIGGER_ON_FDC_THRESHOLD_ONCE))
                    {
                        /* Reset trigger source. */
                        DEM_RESET_TRIG(evtIdx, DEM_INIT_ZERO);
                        /* Freezeframe shall be captured at most once per operation cycle. */
                        DEM_SET_TRIG(evtIdx, DEM_TRIGGER_ON_FDC_THRESHOLD_ONCE);
                    }
                    else
                    {
                        /* Reset trigger source. */
                        DEM_RESET_TRIG(evtIdx, DEM_INIT_ZERO);
                    }
                }
                else
                {
                    if(DEM_EVENT_KIND_SWC == Dem_CfgEventTable[evtIdx].acEvtKind)
                    {
                        Dem_EventStorCondFailedHandle(evtIdx);
                    }
                }

                /****** Event status changed notification callback ******/
                if(oldDtcStatus != DEM_GET_UDS_STATUS(evtIdx))
                {
                    Dem_EventTriggerEventStatusChangedCbk(evtIdx, oldDtcStatus, DEM_GET_UDS_STATUS(evtIdx));
#if(DEM_CFG_GENERALINTERFACESUPPORT == STD_ON)
                    /* Call the function of GeneralCallbackEventStatusChange. */
                    Dem_GeneralEventTriggerEventStatusChangedCbk(evtIdx, oldDtcStatus, DEM_GET_UDS_STATUS(evtIdx));
#endif
                    Dem_EventTriggerDtcStatusChangedCbk(evtIdx, oldDtcStatus, DEM_GET_UDS_STATUS(evtIdx));

                    /* Trigger EventMemory status block update */
                    Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO, 
                                                   DEM_NVM_STATUS_BLOCK, 
                                                   DEM_NVM_REQ_WRITE, 
                                                   Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acImdiStor);
                }
            }
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
            DEM_SET_SSDATA_BUFFER_POS(evtIdx, DEM_INIT_ZERO);
            DEM_SET_SSDATA_FF_STORED(evtIdx, FALSE);
            DEM_SET_SSDATA_EX_STORED(evtIdx, FALSE);
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
            DEM_SET_SSDATA_OBD_STORED(evtIdx, FALSE);
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
            DEM_SET_SSDATA_WWHOBD_STORED(evtIdx, FALSE);
#endif
#endif
#endif
        }

#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
        DEM_SET_SSDATA_BUFFER_CNT(DEM_INIT_ZERO);
#endif
    }

    return;
}

/*
********************************************************************************
* Function Name: Dem_EventProcStatusByte
*
* Explanation: process DTC status byte for reported event.
*
* param: uint16 EventIdx, index of event table
*
* retval: none
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventProcStatusByte
(
    uint16 EventIdx
)
{
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    uint8 opcycIdx;
#endif
    uint8 lampFailedCnt;
    uint8 evtIndiIdx;
    uint8 indiIdx;
    uint8 cntFail[DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM] = {DEM_INIT_ZERO};
    boolean indiReq = FALSE;
    uint8 failedCounter;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (DEM_GET_FDCCNT(EventIdx) >= (sint8)DEM_DEBOUNCE_FDC_HIGH_THRESHOLD))
    {
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
        opcycIdx = Dem_CfgEventTable[EventIdx].acEvtOpcycIdx;
#endif

        /* Set bit2 "PendingDTC". */
        if((FALSE == DEM_GET_UDS_STATUS_PDTC(EventIdx)) && (TRUE == DEM_GET_UDS_STATUS_TFTOC(EventIdx)))
        {
            DEM_SET_UDS_STATUS_PDTC(EventIdx);
            DEM_SET_TRIG(EventIdx, DEM_TRIGGER_ON_PENDING);
        }

        /* Set bit3 "ConfirmedDTC". */
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
        if((opcycIdx > DEM_INIT_ZERO) &&
           ((DEM_OPCYC_OBD_DCY != Dem_CfgOperationCycleTable[opcycIdx].acCycType) ||
            (DEM_CYCLE_STATE_START == DEM_GET_OPCYC_STATE(opcycIdx))))
#endif
        {
            if(FALSE == DEM_GET_UDS_STATUS_CDTC(EventIdx))
            {
                /* TFTOC has been cleared and failed counter has been added by Dem_EventOperCycleReInit. */
                if(FALSE == DEM_GET_UDS_STATUS_TFTOC(EventIdx))
                {
                    failedCounter = DEM_GET_UDS_FAILED_CNT(EventIdx);
                }
                else
                {
                    /* Event is tested failed in this operation cycle. */
                    failedCounter = DEM_GET_UDS_FAILED_CNT(EventIdx) + DEM_BYTE_ONE;
                }

                if(failedCounter >= Dem_CfgEvtFcThrs[EventIdx])
                {
                    DEM_SET_UDS_STATUS_CDTC(EventIdx);
                    DEM_SET_UDS_FAILED_CNT(EventIdx, DEM_INIT_ZERO);
                    DEM_SET_TRIG(EventIdx, DEM_TRIGGER_ON_CONFIRMED);
                }
            }
        }

        /* Retrieve all the indicators of the event. */
        for(evtIndiIdx = DEM_INIT_ZERO; evtIndiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; evtIndiIdx++)
        {
            indiIdx = Dem_CfgEventTable[EventIdx].acIndiIdx[evtIndiIdx];
            /* Check if the lamp index is valid. */
            if(DEM_INIT_ZERO == indiIdx)
            {
                /* No indicator. */
                break;
            }
            else
            {
                /* Failed counter should process in the operation cycle that configured in acIndFailureOpCycIdx. */
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(DEM_CYCLE_STATE_START == DEM_GET_OPCYC_STATE(Dem_CfgEventTable[EventIdx].acIndFailureOpCycIdx[evtIndiIdx]))
                {
                    /* Set bit7 "WarningIndicator Request" if Warning Indicator On Criteria is Fulfilled. */
                    lampFailedCnt = DEM_GET_LAMP_FAILED_CNT(EventIdx, evtIndiIdx);
                    if((lampFailedCnt < DEM_BYTE_MAX) &&
                       (TRUE == DEM_GET_UDS_STATUS_TF(EventIdx)) &&
                       (FALSE == DEM_GET_LAMPFAILCNT_UPDATED(EventIdx)))
                    {
                        lampFailedCnt++;
                        indiReq = TRUE;
                    }
                    DEM_SET_LAMP_FAILED_CNT(EventIdx, evtIndiIdx, lampFailedCnt);
                    cntFail[evtIndiIdx] = lampFailedCnt;
                }
            }
        }

        if(TRUE == DEM_GET_UDS_STATUS_TF(EventIdx))
        {
            /* Set the flag to TRUE when event test failed during the operation cycle. */
            /* Avoid lamp failed counter increasing repeatedly during one cycle. */
            DEM_SET_LAMPFAILCNT_UPDATED(EventIdx, TRUE);
        }

        /* Check if failure counter process. */
        if(TRUE == indiReq)
        {
            if(E_OK == Dem_EventCheckWarningIndicatorAct(EventIdx, cntFail))
            {
                /* Exist any indicator activated, set bit7 to be 1. */
                DEM_SET_UDS_STATUS_WIR(EventIdx);
#if(DEM_CFG_WIRSLCSUPPORT == STD_ON)
                DEM_SET_STATUS_INDI_WIRSLC(EventIdx);
#endif
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventProcMemEntryAsFail
*
* Explanation: Process of failed reported event.
*
* param: uint8 EventMemIdx, selected event memory index
*        uint8 EventStatusOld, dtc status
*        uint16 EventIdx, index of event table
*
* retval: none
********************************************************************************
*/

/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventProcMemEntryAsFail
(
    uint16 EventIdx,
    uint8 EventStatusOld
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 evtMemCnt, evtMemIdx, entryIdx;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
    Dem_EventMemoryEntry_st *entry_ptr;
#endif

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        for(evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++)
        {
            evtMemIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acEvtMemIdx[evtMemCnt];

            if(evtMemIdx > DEM_INIT_ZERO)
            {
                entryIdx = DEM_GET_EVENT_ENTRY(EventIdx, evtMemIdx);
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
                entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);
                if((TRUE == DEM_GET_EVENT_STORED(EventIdx, evtMemIdx)) &&
                   (entry_ptr[entryIdx].evtId != Dem_CfgEventTable[EventIdx].awEvtId))
                {
                    if(TRUE == DEM_GET_UDS_STATUS_CDTC(EventIdx))
                    {
                        /* Sub combined event can't set bit3 */
                        DEM_RESET_UDS_STATUS_CDTC(EventIdx);
                        DEM_RESET_TRIG(EventIdx, DEM_TRIGGER_ON_CONFIRMED);
                    }
                }
#endif
                if((TRUE == DEM_GET_EVENT_STORED(EventIdx, evtMemIdx)) &&
                   (entryIdx < Dem_CfgEventMemoryTable[evtMemIdx].acEvtMemMaxEntry))
                {
                    if(DEM_GET_FDCCNT(EventIdx) >= (sint8)DEM_DEBOUNCE_FDC_HIGH_THRESHOLD)
                    {
                        Dem_EventFailedHandle(EventIdx, evtMemIdx, entryIdx, EventStatusOld);
                    }
                    /* freeze frame/extended frame data */
                    Dem_EventProcMemEntryData(EventIdx, evtMemIdx, entryIdx);
                }
                else
                {
                    if(E_OK == Dem_EventProcMemEntryAsNew(EventIdx, evtMemIdx, &entryIdx))
                    {
                        /* freeze frame/extended frame data */
                        Dem_EventProcMemEntryData(EventIdx, evtMemIdx, entryIdx);
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventProcMemEntryAsNew
*
* Explanation: Process of new reported event.
*
* param: uint16 EventIdx, index of event table
*
* retval: uint8
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, DEM_CODE) Dem_EventProcMemEntryAsNew
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) EntryIdx
)
{
    uint8 allocateRes = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 entryIdx = DEM_INIT_ZERO;
#if(DEM_CFG_EVENTMEMORYENTRYSTORAGETRIGGER == DEM_TRIGGER_ON_FDC_THRESHOLD)
    uint16 dtcIdx;
#endif
    Dem_EventMemoryInfo_st *info_ptr;
    Dem_EventMemoryEntry_st *entry_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && 
       (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (EventMemIdx > DEM_INIT_ZERO) &&
       (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM) &&
       (EntryIdx != NULL_PTR))
    {
#if(DEM_CFG_EVENTMEMORYENTRYSTORAGETRIGGER == DEM_TRIGGER_ON_FDC_THRESHOLD)
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        if((sint8)Dem_CfgDTCTable[dtcIdx].acFdcEvtMemStorThrs <= DEM_GET_FDCCNT(EventIdx))
        {
            /* Event is not in event memory, try to allocate */
            allocateRes = Dem_EventMemoryEntryAllocate(EventIdx, EventMemIdx, &entryIdx);
        }
#endif
#if(DEM_CFG_EVENTMEMORYENTRYSTORAGETRIGGER == DEM_TRIGGER_ON_TEST_FAILED)
        if(TRUE == DEM_GET_UDS_STATUS_TF(EventIdx))
        {
            /* Event is not in event memory, try to allocate */
            allocateRes = Dem_EventMemoryEntryAllocate(EventIdx, EventMemIdx, &entryIdx);
        }
#endif
#if(DEM_CFG_EVENTMEMORYENTRYSTORAGETRIGGER == DEM_TRIGGER_ON_PENDING)
        if(TRUE == DEM_GET_UDS_STATUS_PDTC(EventIdx))
        {
            /* Event is not in event memory, try to allocate */
            allocateRes = Dem_EventMemoryEntryAllocate(EventIdx, EventMemIdx, &entryIdx);
        }
#endif
#if(DEM_CFG_EVENTMEMORYENTRYSTORAGETRIGGER == DEM_TRIGGER_ON_CONFIRMED)
        if(TRUE == DEM_GET_UDS_STATUS_CDTC(EventIdx))
        {
            /* Event is not in event memory, try to allocate */
            allocateRes = Dem_EventMemoryEntryAllocate(EventIdx, EventMemIdx, &entryIdx);
        }
#endif
        if(E_OK == allocateRes)
        {
            info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(EventMemIdx);
            entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(EventMemIdx);
            *EntryIdx = entryIdx;

            /* Store first and most recently failed event */
            if(TRUE == DEM_GET_UDS_STATUS_TF(EventIdx))
            {
                if(DEM_INIT_ZERO == info_ptr->firstFaliedEvtId)
                {
                    info_ptr->firstFaliedEvtId = Dem_CfgEventTable[EventIdx].awEvtId;
                }
                info_ptr->recentlyFaliedEvtId = Dem_CfgEventTable[EventIdx].awEvtId;
            }

            if(TRUE == DEM_GET_UDS_STATUS_CDTC(EventIdx))
            {                
                /* Store first and most recently confirmed event */
                if(DEM_INIT_ZERO == info_ptr->firstConfirmEvtId)
                {
                    info_ptr->firstConfirmEvtId = Dem_CfgEventTable[EventIdx].awEvtId;
                }
                info_ptr->recentlyConfirmEvtId = Dem_CfgEventTable[EventIdx].awEvtId;
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                entry_ptr[entryIdx].stFault = DEM_EVENT_CONFIRMED;
            }  

            /* Trigger EventMemoryInfo block update */
            Dem_EventMemoryNvmBlkUpdateReq(EventMemIdx,
                                           DEM_NVM_INFO_BLOCK,
                                           DEM_NVM_REQ_WRITE,
                                           Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acImdiStor);

            /* Trigger EventMemoryEntry block update */
            Dem_EventMemoryNvmBlkUpdateReq(EventMemIdx,
                                           entryIdx,
                                           DEM_NVM_REQ_WRITE,
                                           Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acImdiStor);
        }
    }

    return allocateRes;
}

/*
********************************************************************************
* Function Name: Dem_EventProcMemEntryAsPass
*
* Explanation: Process of passed reported event.
*
* param: uint8 EventMemIdx, selected event memory index
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventProcMemEntryAsPass
(
    uint16 EventIdx,
    uint8 EventStatusOld
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 evtMemCnt, evtMemIdx, entryIdx;
    Dem_EventMemoryEntry_st *entry_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        for(evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++)
        {
            evtMemIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acEvtMemIdx[evtMemCnt];

            if(evtMemIdx > DEM_INIT_ZERO)
            {
                if(TRUE == DEM_GET_EVENT_STORED(EventIdx, evtMemIdx))
                {
                    entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);
                    entryIdx = DEM_GET_EVENT_ENTRY(EventIdx, evtMemIdx);

                    /* Update event dtc status and debounce counter in event memory entry */
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    entry_ptr[entryIdx].evtActive = DEM_EVENT_PASSIVE;
                    
#if(DEM_CFG_OCC2SUPPORT == STD_ON)
                    if(((EventStatusOld & DEM_EVENT_DTC_STATUS_TNCTOC) == DEM_EVENT_DTC_STATUS_TNCTOC) &&
                       (FALSE == DEM_GET_UDS_STATUS_TNCTOC(EventIdx)) &&
                       (entry_ptr[entryIdx].cntOCC2 < DEM_BYTE_MAX))
                    {
                        entry_ptr[entryIdx].cntOCC2++;
                    }
#endif
#if(DEM_CFG_OCC7SUPPORT == STD_ON)
                    /* Increase OCC7 counter when event tested passed in one operation cycle.  */
                    if((entry_ptr[entryIdx].cntOCC7 < DEM_BYTE_MAX) &&
                       (entry_ptr[entryIdx].cntOCC7 > DEM_VALUE_ZERO) &&
                       ((EventStatusOld & DEM_EVENT_DTC_STATUS_TNCTOC) == DEM_EVENT_DTC_STATUS_TNCTOC) &&
                       (FALSE == DEM_GET_UDS_STATUS_TNCTOC(EventIdx)))
                    {
                        entry_ptr[entryIdx].cntOCC7++;
                    }
#endif
                    /* PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                    EventStatusOld = EventStatusOld;
                    /* Trigger EventMemoryEntry block update */
                    Dem_EventMemoryNvmBlkUpdateReq(evtMemIdx,
                                                   entryIdx,
                                                   DEM_NVM_REQ_WRITE,
                                                   Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acImdiStor);
                    
                    /* freeze frame/extended frame data */
                    Dem_EventProcMemEntryData(EventIdx, evtMemIdx, entryIdx);
                }
            }
            else
            {
                break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventProcMemEntryData
*
* Explanation: Process of event related data.
*
* param: uint8 EventMemIdx, selected event memory index
*        uint16 EventIdx, index of event table
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventProcMemEntryData
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx
)
{
    uint16 dtcIdx;
    uint32 dtcVal;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        dtcVal = DEM_DTCVALUE_CAL(dtcIdx);

        if((TRUE == DEM_GET_DTC_RECORD_ENABLE()) || 
           (EventMemIdx != DEM_GET_DTC_RECORD_ENABLE_EMIDX()) ||
           (dtcVal != DEM_GET_DTC_RECORD_ENABLE_DTC()))
        {
            if((Dem_CfgDtcFfDataClsIdx[dtcIdx] > DEM_INIT_ZERO) &&
               (Dem_CfgDTCTable[dtcIdx].acFfDataRecClsIdx > DEM_INIT_ZERO))
            {
                Dem_EventFreezeFrameDataStore(EventIdx, EventMemIdx, EntryIdx);
            }

            if(Dem_CfgDTCTable[dtcIdx].acExDataClsIdx > DEM_INIT_ZERO)
            {
                Dem_EventExtendedDataStore(EventIdx, EventMemIdx, EntryIdx);
            }

#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
            if(Dem_CfgDTCTable[dtcIdx].acObdDtcIdx > DEM_INIT_ZERO)
            {
                Dem_ObdFreezeFrameDataStore(EventIdx, EventMemIdx, EntryIdx);     
            }
            
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
            if((Dem_CfgDTCTable[dtcIdx].acWwhObdClass != DEM_DTC_WWHOBD_CLASS_NOCLASS) && 
               (Dem_CfgDTCTable[dtcIdx].acWobdFfDataClsIdx > DEM_INIT_ZERO))
            {
                Dem_ObdWwhFreezeFrameDataStore(EventIdx, EventMemIdx, EntryIdx);
            }
#endif

#endif
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventStorCondFailedHandle
*
* Explanation: Process of event storage condition failed.
*
* param: uint16 evtIdx, index of event table
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventStorCondFailedHandle
(
    uint16 EventIdx
)
{
    uint16 storCondGrpIdx, storCondCnt, storCondIdx;
    uint16 repEvtIdx;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        storCondGrpIdx = Dem_CfgEventTable[EventIdx].acEvtStorCondGrpIdx;
        if((storCondGrpIdx > DEM_INIT_ZERO) && (storCondGrpIdx <= DEM_CFG_STORCOND_GROUP_NUM))
        {
            for(storCondCnt = DEM_INIT_ZERO; storCondCnt < DEM_CFG_STORCONDGRP_MAX_REF_STORCOND_NUM; storCondCnt++)
            {
                storCondIdx = Dem_CfgStorConditionGrpTable[storCondGrpIdx].acStorCondIdx[storCondCnt];
                /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                if((storCondIdx > DEM_INIT_ZERO) && (storCondIdx <= DEM_CFG_STORCOND_NUM))
                {
                    if((FALSE == DEM_GET_STORCOND(storCondIdx)) &&
                       (Dem_CfgStorConditionTable[storCondIdx].acStorCondRepEvtIdx > DEM_INIT_ZERO))
                    {
                        repEvtIdx = Dem_CfgStorConditionTable[storCondIdx].acStorCondRepEvtIdx;
                        (void)Dem_EventStatusReport(repEvtIdx, DEM_EVENT_STATUS_FAILED); 
                    }
                /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                }
                else
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    break;
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventStorCondPassedHandle
*
* Explanation: Process of event storage condition passed.
*
* param: uint16 evtIdx, index of event table
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventStorCondPassedHandle
(
    uint16 EventIdx
)
{
    uint16 storCondGrpIdx, storCondCnt, storCondIdx;
    uint16 repEvtIdx;
    
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        storCondGrpIdx = Dem_CfgEventTable[EventIdx].acEvtStorCondGrpIdx;
        if( (storCondGrpIdx > DEM_INIT_ZERO) && (storCondGrpIdx <= DEM_CFG_STORCOND_GROUP_NUM) )
        {
            for(storCondCnt = DEM_INIT_ZERO; storCondCnt < DEM_CFG_STORCONDGRP_MAX_REF_STORCOND_NUM; storCondCnt++)
            {
                storCondIdx = Dem_CfgStorConditionGrpTable[storCondGrpIdx].acStorCondIdx[storCondCnt];
                /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                if(storCondIdx > DEM_INIT_ZERO)
                {
                    if((TRUE == DEM_GET_STORCOND(storCondIdx)) &&
                       (Dem_CfgStorConditionTable[storCondIdx].acStorCondRepEvtIdx > DEM_INIT_ZERO))
                    {
                        repEvtIdx = Dem_CfgStorConditionTable[storCondIdx].acStorCondRepEvtIdx;
                        (void)Dem_EventStatusReport(repEvtIdx, DEM_EVENT_STATUS_PASSED); 
                    }
                /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                }
                else
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    break;
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventDebCntBasedJumpDown
*
* Explanation: Debounce counter jump down.
*
* param: uint16 evtIdx, index of event table.
*
* retval: If debounce counter updated.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(boolean, DEM_CODE) Dem_EventDebCntBasedJumpDown
(
    uint16 EventIdx
)
{
    uint16 evtDebIdx;
    boolean debCntUpdate = FALSE;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        evtDebIdx = Dem_CfgEvtDebCntIdx[EventIdx];
        /* Debounce counter jump down is enable? */
        if(TRUE == DEM_DEBCNTJDEN_CAL(evtDebIdx))
        {
            if(DEM_GET_DEBCNT(EventIdx) > (sint16)DEM_DEBCNTJDVAL_CAL(evtDebIdx))
            {
                /* Reset to jumpdown value. */
                DEM_SET_DEBCNT(EventIdx, DEM_DEBCNTJDVAL_CAL(evtDebIdx));
                /* Execute operation of performing the pre-passed. */
                debCntUpdate = Dem_EventDebCntBasedDecrement(EventIdx);
            }
        }

        if(FALSE == debCntUpdate)
        {
            /* Execute operation of performing the pre-passed. */
            debCntUpdate = Dem_EventDebCntBasedDecrement(EventIdx);
        }
    }

    return debCntUpdate;
}

/*
********************************************************************************
* Function Name: Dem_EventDebCntBasedJumpUp
*
* Explanation: Debounce counter jump up.
*
* param: uint16 EventIdx, index of event table.
*
* retval: If debounce counter updated.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(boolean, DEM_CODE) Dem_EventDebCntBasedJumpUp
(
    uint16 EventIdx
)
{
    uint16 evtDebIdx;
    boolean debCntUpdate = FALSE;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        evtDebIdx = Dem_CfgEvtDebCntIdx[EventIdx];

        /* Debounce counter jump up is enable? */
        if(TRUE == DEM_DEBCNTJUEN_CAL(evtDebIdx))
        {
            if(DEM_GET_DEBCNT(EventIdx) < (sint16)DEM_DEBCNTJUVAL_CAL(evtDebIdx))
            {
                /* Reset to jumpup value. */
                DEM_SET_DEBCNT(EventIdx, DEM_DEBCNTJUVAL_CAL(evtDebIdx));
                /* Execute operation of performing the pre-failed. */
                debCntUpdate = Dem_EventDebCntBasedIncrement(EventIdx);
            }
        }

        if(FALSE == debCntUpdate)
        {
            /* Execute operation of performing the pre-failed. */
            debCntUpdate = Dem_EventDebCntBasedIncrement(EventIdx);
        }
    }

    return debCntUpdate;
}

/*
********************************************************************************
* Function Name: Dem_EventDebCntBasedDecrement
*
* Explanation: Debounce counter decrement.
*
* param: uint16 EventIdx, index of event table.
*
* retval: If debounce counter updated.
********************************************************************************
*/
static FUNC(boolean, DEM_CODE) Dem_EventDebCntBasedDecrement
(
    uint16 EventIdx
)
{
    uint16 evtDebIdx;
    sint16 tempCnt;
    boolean debCntUpdate = FALSE;

    evtDebIdx = Dem_CfgEvtDebCntIdx[EventIdx];

    /* Check debounce counter if exceed the Passed threshold. */
    if(DEM_GET_DEBCNT(EventIdx) > (sint16)DEM_DEBCNTPASSTHRS_CAL(evtDebIdx))
    {
        /* Overflow check. */
        if( ((sint16)DEM_GET_DEBCNT(EventIdx) <
            ((sint16)DEM_INT16_MIN + (sint16)DEM_DEBCNTDECSTEPSIZE_CAL(evtDebIdx))) )
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            /* Set debounce counter to DEM_INT16_MIN if overflow. */
            tempCnt = (sint16)DEM_INT16_MIN;
        }
        else
        {
            /* Decrement the debounce counter. */
            tempCnt = (sint16)(DEM_GET_DEBCNT(EventIdx) -
                                    (sint16)DEM_DEBCNTDECSTEPSIZE_CAL(evtDebIdx));
        }
        DEM_SET_DEBCNT(EventIdx, tempCnt);
        debCntUpdate = TRUE;
    }

    return debCntUpdate;
}

/*
********************************************************************************
* Function Name: Dem_EventDebCntBasedIncrement
*
* Explanation: Debounce counter increment.
*
* param: uint16 EventIdx, index of event table.
*
* retval: If debounce counter updated.
********************************************************************************
*/
static FUNC(boolean, DEM_CODE) Dem_EventDebCntBasedIncrement
(
    uint16 EventIdx
)
{
    uint16 evtDebIdx;
    sint16 tempCnt;
    boolean debCntUpdate = FALSE;

    evtDebIdx = Dem_CfgEvtDebCntIdx[EventIdx];

    /* Check debounce counter if exceed the Passed threshold. */
    if(DEM_GET_DEBCNT(EventIdx) < (sint16)DEM_DEBCNTFAILTHRS_CAL(evtDebIdx))
    {
        /* Overflow check. */
        if( (sint16)DEM_GET_DEBCNT(EventIdx) >
            ((sint16)DEM_INT16_MAX - (sint16)DEM_DEBCNTINCSTEPSIZE_CAL(evtDebIdx)) )
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            /* Set debounce counter to DEM_INT16_MAX if overflow. */
            tempCnt = (sint16)DEM_INT16_MAX;
        }
        else
        {
            /* Increment the debounce counter. */
            tempCnt = (sint16)(DEM_GET_DEBCNT(EventIdx) +
                                    (sint16)DEM_DEBCNTINCSTEPSIZE_CAL(evtDebIdx));
        }
        DEM_SET_DEBCNT(EventIdx, tempCnt);
        debCntUpdate = TRUE;
    }

    return debCntUpdate;
}

/*
********************************************************************************
* Function Name: Dem_EventDebCntBasedCalc
*
* Explanation: Calculate the debounce counter and estimate the debounced event
*              status, only for counter based debounce algorithm.
*
* param: uint16 evtIdx, index of event table.
*        Dem_EventIdType EventStatus, the reported event status.
*
* retval: The debounce event status.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, DEM_CODE) Dem_EventDebCntBasedCalc
(
    uint16 EventIdx,
    Dem_EventStatusType EventStatus
)
{
    boolean debCntUpdate = FALSE;
    uint8 evtStDeb;
    uint16 evtDebIdx;
    
    evtStDeb = EventStatus;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        evtDebIdx = Dem_CfgEvtDebCntIdx[EventIdx];

        if(DEM_DEBOUNCE_STATUS_FREEZE != DEM_GET_DEBOUNCE_STATUS(EventIdx))
        {
            switch(EventStatus)
            {
                case DEM_EVENT_STATUS_PASSED:
                {
                    /* Reset the debounce counter to passed threshold value */
                    if(DEM_GET_DEBCNT(EventIdx) != DEM_DEBCNTPASSTHRS_CAL(evtDebIdx))
                    {
                        DEM_SET_DEBCNT(EventIdx, DEM_DEBCNTPASSTHRS_CAL(evtDebIdx));
                        debCntUpdate = TRUE;
                    }
                    evtStDeb = DEM_EVENT_STATUS_PASSED;
                    break;
                }
                case DEM_EVENT_STATUS_FAILED:
                {
                    /* Reset the debounce counter to failed threshold value */
                    if(DEM_GET_DEBCNT(EventIdx) != (sint16)DEM_DEBCNTFAILTHRS_CAL(evtDebIdx))
                    {
                        DEM_SET_DEBCNT(EventIdx, DEM_DEBCNTFAILTHRS_CAL(evtDebIdx));
                        debCntUpdate = TRUE;
                    }
                    evtStDeb = DEM_EVENT_STATUS_FAILED;
                    break;
                }
                case DEM_EVENT_STATUS_PREPASSED:
                {
                    debCntUpdate = Dem_EventDebCntBasedJumpDown(EventIdx);
                    if(DEM_GET_DEBCNT(EventIdx) <= DEM_DEBCNTPASSTHRS_CAL(evtDebIdx))
                    {
                        evtStDeb = DEM_EVENT_STATUS_PASSED;
                    }
                    break;
                }
                case DEM_EVENT_STATUS_PREFAILED:
                {
                    debCntUpdate = Dem_EventDebCntBasedJumpUp(EventIdx);
                    if(DEM_GET_DEBCNT(EventIdx) >= (sint16)DEM_DEBCNTFAILTHRS_CAL(evtDebIdx))
                    {
                        evtStDeb = DEM_EVENT_STATUS_FAILED;
                    }
                    break;
                }
                default:
                {
                    break;
                }
            }
        }

        if((TRUE == debCntUpdate) &&
           (TRUE == Dem_CfgDebCounterTable[evtDebIdx].acDebCntStor))
        {
            DEM_SET_STORED_DEBCNT(EventIdx, DEM_GET_DEBCNT(EventIdx));
            /* Trigger EventMemoryStatus block update */
            Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                           DEM_NVM_STATUS_BLOCK,
                                           DEM_NVM_REQ_WRITE,
                                           Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acImdiStor);
        }
    }
    
    return evtStDeb;
}

/*
********************************************************************************
* Function Name: Dem_EventDebCntBasedToFDC
*
* Explanation: Covert debounce counter to FDC linerly
*
* param: uint16 evtIdx, index of event table
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventDebCntBasedToFDC
(
    uint16 EventIdx
)
{
    uint16 evtDebIdx;
    
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        evtDebIdx = Dem_CfgEvtDebCntIdx[EventIdx];
        
        if((sint16)DEM_DEBOUNCE_COUNTER_ZERO != DEM_GET_DEBCNT(EventIdx))
        {
            if(DEM_GET_DEBCNT(EventIdx) >= (sint16)DEM_DEBCNTFAILTHRS_CAL(evtDebIdx))
            {
                DEM_SET_FDCCNT(EventIdx, (sint8)DEM_DEBOUNCE_FDC_HIGH_THRESHOLD);
            }
            else if(DEM_GET_DEBCNT(EventIdx) <= DEM_DEBCNTPASSTHRS_CAL(evtDebIdx))
            {
                DEM_SET_FDCCNT(EventIdx, (sint8)DEM_DEBOUNCE_FDC_LOW_THRESHOLD);
            }
            else
            {
                if(DEM_GET_DEBCNT(EventIdx) > (sint16)DEM_DEBOUNCE_COUNTER_ZERO)
                {
                    if(DEM_DEBCNTFAILTHRS_CAL(evtDebIdx) != (uint16)DEM_INIT_ZERO)
                    {
                        DEM_SET_FDCCNT(EventIdx, 
                                              (uint8)(((uint32)DEM_GET_DEBCNT(EventIdx) * 
                                                      DEM_DEBOUNCE_FDC_HIGH_THRESHOLD) / 
                                                      (uint32)DEM_DEBCNTFAILTHRS_CAL(evtDebIdx)));
                    }
                    else
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    {
                        DEM_SET_FDCCNT(EventIdx, (sint8)DEM_INIT_ZERO);
                    }

                    /* To avoid the fdcCnt value is zero due to the integer calulation */
                    /* error, here we will make sure the faccnt is at least equal to 1 */
                    if((sint8)DEM_DEBOUNCE_COUNTER_ZERO == DEM_GET_FDCCNT(EventIdx))
                    {
                        DEM_SET_FDCCNT(EventIdx, (sint8)DEM_DEBOUNCE_COUNTER_ONE);
                    }
                }
                else
                {
                    if(DEM_DEBCNTPASSTHRS_CAL(evtDebIdx) != (sint16)DEM_INIT_ZERO)
                    {
                        DEM_SET_FDCCNT(EventIdx, 
                                                     (((sint32)DEM_GET_DEBCNT(EventIdx) *
                                                      DEM_DEBOUNCE_FDC_LOW_THRESHOLD) /
                                                       (sint32)DEM_DEBCNTPASSTHRS_CAL(evtDebIdx)));
                    }
                    else
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    {
                        DEM_SET_FDCCNT(EventIdx, (sint8)DEM_INIT_ZERO);
                    }
                    
                    /* To avoid the fdcCnt value is zero due to the integer calulation */
                    /* error, here we will make sure the faccnt is at least equal to -1 */
                    if((sint8)DEM_DEBOUNCE_COUNTER_ZERO == DEM_GET_FDCCNT(EventIdx))
                    {
                        DEM_SET_FDCCNT(EventIdx, (sint8)DEM_DEBOUNCE_COUNTER_NEG_ONE);
                    }
                }
            }
        }
        else
        {
            DEM_SET_FDCCNT(EventIdx, (sint8)DEM_DEBOUNCE_COUNTER_ZERO);
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventDebTimeBasedCalc
*
* Explanation: Calculate the debounce counter and estimate the debounced event
*  status, only for timer based debounce algorithm
*
* param: uint16 EventIdx, index of event table
*        Dem_EventIdType EventStatus, the reported event status
*
* retval: the debounced event status
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, DEM_CODE) Dem_EventDebTimeBasedCalc
(
    uint16 EventIdx,
    Dem_EventStatusType EventStatus
)
{
    uint8 evtStDeb;
    uint16 evtDebIdx;
    
    evtStDeb = EventStatus;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        evtDebIdx = Dem_CfgEvtDebCntIdx[EventIdx];

        if(DEM_DEBOUNCE_STATUS_FREEZE != DEM_GET_DEBOUNCE_STATUS(EventIdx))
        {
            switch(EventStatus)
            {
                case DEM_EVENT_STATUS_PASSED:
                {
                    /* Reset the debounce timer to passed threshold value */
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                    DEM_SET_DEBTIME(EventIdx, Dem_CfgDebTimPassThrs[evtDebIdx]);
                    DEM_SET_DEBTIMER_BUFFER(EventIdx, DEM_EVENT_STATUS_PASSED);
                    evtStDeb = DEM_EVENT_STATUS_PASSED;
                    break;
                }
                case DEM_EVENT_STATUS_FAILED:
                {
                    /* Reset the debounce timer to failed threshold value */
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                    DEM_SET_DEBTIME(EventIdx, Dem_CfgDebTimFailThrs[evtDebIdx]);
                    DEM_SET_DEBTIMER_BUFFER(EventIdx, DEM_EVENT_STATUS_FAILED);
                    evtStDeb = DEM_EVENT_STATUS_FAILED;
                    break;
                }
                case DEM_EVENT_STATUS_PREPASSED:
                {
                    if((DEM_EVENT_STATUS_PREPASSED != DEM_GET_DEBTIMER_BUFFER(EventIdx)) && 
                       (DEM_EVENT_STATUS_PASSED != DEM_GET_DEBTIMER_BUFFER(EventIdx)))
                    {
                        DEM_SET_DEBTIME(EventIdx, DEM_INIT_ZERO);
                        DEM_SET_DEBTIMER_BUFFER(EventIdx, DEM_EVENT_STATUS_PREPASSED);
                    }
                    break;
                }
                case DEM_EVENT_STATUS_PREFAILED:
                {
                    if((DEM_EVENT_STATUS_PREFAILED != DEM_GET_DEBTIMER_BUFFER(EventIdx)) &&
                       (DEM_EVENT_STATUS_FAILED != DEM_GET_DEBTIMER_BUFFER(EventIdx)))
                    {
                        DEM_SET_DEBTIME(EventIdx, DEM_INIT_ZERO);
                        DEM_SET_DEBTIMER_BUFFER(EventIdx, DEM_EVENT_STATUS_PREFAILED);
                    }
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }

    return evtStDeb;
}

/*
********************************************************************************
* Function Name: Dem_EventDebTimeBasedToFDC
*
* Explanation: Covert debounce timer to FDC linerly
*
* param: uint16 evtIdx, index of event table
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventDebTimeBasedToFDC
(
    uint16 EventIdx
)
{
    uint16 evtDebIdx;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        evtDebIdx = Dem_CfgEvtDebCntIdx[EventIdx];

        if((DEM_EVENT_STATUS_PREFAILED == DEM_GET_DEBTIMER_BUFFER(EventIdx)) ||
           (DEM_EVENT_STATUS_FAILED == DEM_GET_DEBTIMER_BUFFER(EventIdx)))
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            if(DEM_GET_DEBTIME(EventIdx) >= Dem_CfgDebTimFailThrs[evtDebIdx])
            {
                DEM_SET_FDCCNT(EventIdx, (sint8)DEM_DEBOUNCE_FDC_HIGH_THRESHOLD);
            }
            else
            {
                DEM_SET_FDCCNT(EventIdx, 
                                           (sint32)DEM_GET_DEBTIME(EventIdx) * 
                                           (sint32)DEM_DEBOUNCE_FDC_HIGH_THRESHOLD /
                                           (sint32)Dem_CfgDebTimFailThrs[evtDebIdx]);
            }
        }
        else if((DEM_EVENT_STATUS_PREPASSED == DEM_GET_DEBTIMER_BUFFER(EventIdx)) ||
                (DEM_EVENT_STATUS_PASSED == DEM_GET_DEBTIMER_BUFFER(EventIdx)))
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            if(DEM_GET_DEBTIME(EventIdx) >= Dem_CfgDebTimPassThrs[evtDebIdx])
            {
                DEM_SET_FDCCNT(EventIdx, (sint8)DEM_DEBOUNCE_FDC_LOW_THRESHOLD);
            }
            else
            {
                DEM_SET_FDCCNT(EventIdx, 
                                          (sint32)DEM_GET_DEBTIME(EventIdx) * 
                                           DEM_DEBOUNCE_FDC_LOW_THRESHOLD /
                                          (sint32)Dem_CfgDebTimPassThrs[evtDebIdx]);
            }
        }
        else
        {
            DEM_SET_FDCCNT(EventIdx, (sint8)DEM_DEBOUNCE_COUNTER_ZERO);
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventDebTimeBasedProcess
*
* Explanation: Process of timer based debounce in Dem_Mainfunciton
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventDebTimeBasedProcess(void)
{
    uint16 evtDebIdx;
    uint16 evtIdx;
    uint32 debTime;

    for(evtIdx = DEM_INIT_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
    {
        if(DEM_DEBOUNCE_TIMER_BASED == Dem_CfgEvtDebCntCls[evtIdx])
        {
            evtDebIdx = Dem_CfgEvtDebCntIdx[evtIdx];
            if(DEM_DEBOUNCE_STATUS_FREEZE != DEM_GET_DEBOUNCE_STATUS(evtIdx))
            {
                if(DEM_EVENT_STATUS_PREPASSED == DEM_GET_DEBTIMER_BUFFER(evtIdx))
                {
                    debTime = DEM_GET_DEBTIME(evtIdx);
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                    if(debTime >= Dem_CfgDebTimPassThrs[evtDebIdx])
                    {
                        (void)Dem_EventStatusReport(evtIdx, DEM_EVENT_STATUS_PASSED);
                        DEM_SET_DEBTIMER_BUFFER(evtIdx, DEM_EVENT_STATUS_PASSED);
                    }
                    else
                    {
                        debTime += DEM_CFG_TASKTIME; 
                    }
                    DEM_SET_DEBTIME(evtIdx, debTime);
                    Dem_EventDebTimeBasedToFDC(evtIdx);
                }
                else if(DEM_EVENT_STATUS_PREFAILED == DEM_GET_DEBTIMER_BUFFER(evtIdx))
                {
                    debTime = DEM_GET_DEBTIME(evtIdx);
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                    if(debTime >= Dem_CfgDebTimFailThrs[evtDebIdx])
                    {
                        (void)Dem_EventStatusReport(evtIdx, DEM_EVENT_STATUS_FAILED);
                        DEM_SET_DEBTIMER_BUFFER(evtIdx, DEM_EVENT_STATUS_FAILED);
                    }
                    else
                    {
                        debTime += DEM_CFG_TASKTIME; 
                    }
                    DEM_SET_DEBTIME(evtIdx, debTime);
                    Dem_EventDebTimeBasedToFDC(evtIdx);
#if(DEM_CFG_EXTENDSTATUSBYTE != DEM_INIT_ZERO)
                    Dem_EventExStatusHandle(evtIdx);
#endif
                }
                else
                {
                    /* do nothing */
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventDebMonitorBasedCalc
*
* Explanation: Calculate the debounce counter and estimate the debounced event
*  status, only for monitor internal
*
* param: uint16 EventIdx, index of event table
*        Dem_EventStatusType EventStatus, the reported event status
*
* retval: the debounced event status
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, DEM_CODE) Dem_EventDebMonitorBasedCalc
(
    uint16 EventIdx,
    Dem_EventStatusType EventStatus
)
{
    uint8 evtStDeb;
    sint8 fdcVal = (sint8)DEM_INIT_ZERO;

    evtStDeb = EventStatus;
    
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        switch(EventStatus)
        {
            case DEM_EVENT_STATUS_PASSED:
            {
                /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                if(E_OK == Dem_EventTriggerGetFDCCbk(EventIdx, &fdcVal))
                {
                    DEM_SET_FDCCNT(EventIdx, fdcVal);
                }
                evtStDeb = DEM_EVENT_STATUS_PASSED;
                break;
            }
            case DEM_EVENT_STATUS_FAILED:
            {
                /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                if(E_OK == Dem_EventTriggerGetFDCCbk(EventIdx, &fdcVal))
                {
                    DEM_SET_FDCCNT(EventIdx, fdcVal);
                }
                evtStDeb = DEM_EVENT_STATUS_FAILED;
                break;
            }
            case DEM_EVENT_STATUS_PREPASSED:
            {
                /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                if(E_OK == Dem_EventTriggerGetFDCCbk(EventIdx, &fdcVal))
                {
                    if(DEM_DEBOUNCE_FDC_LOW_THRESHOLD == fdcVal)
                    {
                        evtStDeb = DEM_EVENT_STATUS_PASSED;
                    }
                    DEM_SET_FDCCNT(EventIdx, fdcVal);
                }
                break;
            }
            case DEM_EVENT_STATUS_PREFAILED:
            {
                /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                if(E_OK == Dem_EventTriggerGetFDCCbk(EventIdx, &fdcVal))
                {
                    if((sint8)DEM_DEBOUNCE_FDC_HIGH_THRESHOLD == fdcVal)
                    {
                        evtStDeb = DEM_EVENT_STATUS_FAILED;
                    }
                    DEM_SET_FDCCNT(EventIdx, fdcVal);
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return evtStDeb;
}

/*
********************************************************************************
* Function Name: Dem_EventDebounceExecute
*
* Explanation: Execute debounce algorithm according to event configurations and
*  return the debounced event status
*
* param: uint16 EventIdx, index of event table
*        Dem_EventIdType EventStatus, the reported event status
*
* retval: the debounced event status
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, DEM_CODE) Dem_EventDebounceExecute
(
    uint16 EventIdx, 
    Dem_EventStatusType EventStatus
)
{
    uint8 evtStDeb, evtDebCls;
    sint8 fdcVal = (sint8)DEM_INIT_ZERO;
    
    evtStDeb = EventStatus;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        evtDebCls = Dem_CfgEvtDebCntCls[EventIdx];

        switch(evtDebCls)
        {
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
            case DEM_DEBOUNCE_COUNTER_BASED:
            {
                evtStDeb = Dem_EventDebCntBasedCalc(EventIdx, EventStatus);

                Dem_EventDebCntBasedToFDC(EventIdx);

                break;
            }
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
            case DEM_DEBOUNCE_TIMER_BASED:
            {
                evtStDeb = Dem_EventDebTimeBasedCalc(EventIdx, EventStatus);
                
                Dem_EventDebTimeBasedToFDC(EventIdx);
                
                break;
            }
#endif
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" */
            case DEM_DEBOUNCE_MONITOR_INTERNAL:
            {
                if(DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED == EventStatus)
                {
                    if(E_OK == Dem_EventTriggerGetFDCCbk(EventIdx, &fdcVal))
                    {
                        if(DEM_DEBOUNCE_FDC_LOW_THRESHOLD == fdcVal)
                        {
                            evtStDeb = DEM_EVENT_STATUS_PASSED;
                        }
                        else if((sint8)DEM_DEBOUNCE_FDC_HIGH_THRESHOLD == fdcVal)
                        {
                            evtStDeb = DEM_EVENT_STATUS_FAILED;
                        }
                        else
                        {
                            /* Do nothing */
                        }
                        DEM_SET_FDCCNT(EventIdx, fdcVal);
                    }
                }
                else
                {
                    evtStDeb = Dem_EventDebMonitorBasedCalc(EventIdx, EventStatus);
                }                
                break;
            }
            default:
            {
                if(DEM_EVENT_STATUS_FAILED == evtStDeb)
                {
                    DEM_SET_FDCCNT(EventIdx, DEM_DEBOUNCE_FDC_HIGH_THRESHOLD);
                }
                else if(DEM_EVENT_STATUS_PASSED == evtStDeb)
                {
                    DEM_SET_FDCCNT(EventIdx, DEM_DEBOUNCE_FDC_LOW_THRESHOLD);
                }
                else
                {
                    /* Do nothing */
                }
                break;
            }
        }
        
        /* Update maximum FDC during current cycle */
        if(DEM_GET_FDCCNT(EventIdx) > DEM_GET_FDCCNTMAX_DCC(EventIdx))
        {
            DEM_SET_FDCCNTMAX_DCC(EventIdx, DEM_GET_FDCCNT(EventIdx));
        }
        /* Update maximum FDC since last clear */
        if(DEM_GET_FDCCNT(EventIdx) > DEM_GET_FDCCNTMAX_SLC(EventIdx))
        {
            DEM_SET_FDCCNTMAX_SLC(EventIdx, DEM_GET_FDCCNT(EventIdx));
            /* Trigger EventMemoryStatus block update */
            Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                           DEM_NVM_STATUS_BLOCK,
                                           DEM_NVM_REQ_WRITE,
                                           Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acImdiStor);
        }
    }

    return evtStDeb;
}

/*
********************************************************************************
* Function Name: Dem_EventDebounceBehavior
*
* Explanation: Process the debounce behavior if enable condition not fullfilled
*
* param: uint16 EventIdx, index of event table
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventDebounceBehavior
(
    uint16 EventIdx
)
{
    uint8 evtDebCls;
    uint16 evtDebIdx;
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    const Dem_ConfigDebCntBasedTable_st *counter_ptr;
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
    const Dem_ConfigDebTimBasedTable_st *timer_ptr;
#endif
    
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        evtDebCls = Dem_CfgEvtDebCntCls[EventIdx];
        evtDebIdx = Dem_CfgEvtDebCntIdx[EventIdx];
        
        switch(evtDebCls)
        {
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
            case DEM_DEBOUNCE_COUNTER_BASED:
            {
                counter_ptr = (const Dem_ConfigDebCntBasedTable_st *)&(Dem_CfgDebCounterTable[evtDebIdx]);

                if(DEM_DEBOUNCE_RESET == counter_ptr->acDebBhv)
                {
                    /* For behavior RESET, reset the counter to 0 */
                    DEM_SET_DEBCNT(EventIdx, DEM_DEBOUNCE_COUNTER_ZERO);
                    DEM_SET_FDCCNT(EventIdx, DEM_DEBOUNCE_COUNTER_ZERO);
                }
                else
                {
                    /* For behavior FREEZE, just keep the current counter value */
                    DEM_SET_DEBOUNCE_STATUS(EventIdx, DEM_DEBOUNCE_STATUS_FREEZE);
                }

                break;
            }
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
            case DEM_DEBOUNCE_TIMER_BASED:
            {
                timer_ptr = (const Dem_ConfigDebTimBasedTable_st *)&(Dem_CfgDebTimeTable[evtDebIdx]);
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                if(DEM_DEBOUNCE_RESET == timer_ptr->acDebBhv)
                {
                    /* For behavior RESET, reset the counter to 0 */
                    DEM_SET_DEBTIME(EventIdx, DEM_DEBOUNCE_COUNTER_ZERO);
                    DEM_SET_DEBTIMER_BUFFER(EventIdx, DEM_EVENT_STATUS_NONE);
                    DEM_SET_FDCCNT(EventIdx, DEM_DEBOUNCE_COUNTER_ZERO);
                }
                else
                {
                    /* For behavior FREEZE, just keep the current counter value */
                    DEM_SET_DEBOUNCE_STATUS(EventIdx, DEM_DEBOUNCE_STATUS_FREEZE);
                }
                break;
            }
#endif
            default:
            {
                break;
            }
        }
    }

}

/*
********************************************************************************
* Function Name: Dem_EventDebounceStatus
*
* Explanation: Process the debounce behavior if enable condition not fullfilled
*
* param: uint16 EventIdx, index of event table
*        Dem_DebounceResetStatusType DebounceResetStatus, requested action of 
*        the debounce algorithm
*
* retval: Std_ReturnType, action result OK or NOT_OK
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EventDebounceStatus
(
    uint16 EventIdx,
    Dem_DebounceResetStatusType DebounceResetStatus
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 evtDebCls;
    
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        evtDebCls = Dem_CfgEvtDebCntCls[EventIdx];
        
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
        /* Event is available */
        if(TRUE == DEM_GET_AVAIL(EventIdx))
#endif
        {
            switch(DebounceResetStatus)
            {
                case DEM_DEBOUNCE_STATUS_FREEZE:
                {
                    /* Freeze action is not relevant for counter-base debouncing */
                    if(DEM_DEBOUNCE_TIMER_BASED == evtDebCls)
                    {
                        DEM_SET_DEBOUNCE_STATUS(EventIdx, DEM_DEBOUNCE_STATUS_FREEZE);
                        ret = E_OK;
                    }
                    break;
                }
                case DEM_DEBOUNCE_STATUS_RESET:
                {
                    DEM_SET_DEBCNT(EventIdx, DEM_DEBOUNCE_COUNTER_ZERO);
                    DEM_SET_FDCCNT(EventIdx, DEM_DEBOUNCE_COUNTER_ZERO);
                    DEM_SET_DEBTIME(EventIdx, DEM_DEBOUNCE_COUNTER_ZERO);
                    DEM_SET_DEBTIMER_BUFFER(EventIdx, DEM_EVENT_STATUS_NONE);
                    DEM_SET_DEBOUNCE_STATUS(EventIdx, DEM_DEBOUNCE_STATUS_RESET);
                    ret = E_OK;
                    break;
                }
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                default:
                {
                    break;
                }
            }     
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventFailedHandle
*
* Explanation: Handle of failed event.
*
* param: uint16 EventIdx, index of event table
*        uint8 EventMemIdx, selected event memory index
*        uint8 EntryIdx, event memory entry index
*        uint8 EventStatusOld, dtc status
*
* retval: void
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventFailedHandle
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx,
    uint8 EventStatusOld
)
{
    boolean infoUpdate = FALSE;
    uint8 indiIdx;
    Dem_EventMemoryInfo_st *info_ptr;
    Dem_EventMemoryEntry_st *entry_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM))
    {
        info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(EventMemIdx);
        entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(EventMemIdx);

        /* Update event dtc status and debounce counter in event memory entry */
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
        entry_ptr[EntryIdx].evtActive = DEM_EVENT_ACTIVE;
        /* Retrieve all the indicators of the event. */
        for(indiIdx = DEM_INIT_ZERO; indiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; indiIdx++)
        {
            entry_ptr[EntryIdx].cntHeal[indiIdx] = DEM_INIT_ZERO;
        }
        entry_ptr[EntryIdx].cntAge = DEM_INIT_ZERO;
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
        entry_ptr[EntryIdx].cntAge2 = DEM_INIT_ZERO;
#endif
        if(TRUE == DEM_GET_UDS_STATUS_TF(EventIdx))
        {
            /* [SWS_Dem_00787] Update slot in chronological order if bit0 changes from 0 to 1 */
            if((EventStatusOld & DEM_EVENT_DTC_STATUS_TF) != DEM_EVENT_DTC_STATUS_TF)
            {
                entry_ptr[EntryIdx].cntCslf = DEM_INIT_ZERO;
                Dem_EventMemoryEntrySlotUpdate(Dem_CfgEventTable[EventIdx].awEvtId, EventMemIdx);
                infoUpdate = TRUE;
            }
            
            /* Store most recently failed event */
            if(entry_ptr[EntryIdx].evtId == Dem_CfgEventTable[EventIdx].awEvtId)
            {
                if(DEM_INIT_ZERO == info_ptr->firstFaliedEvtId)
                {
                    info_ptr->firstFaliedEvtId = Dem_CfgEventTable[EventIdx].awEvtId;
                }
                info_ptr->recentlyFaliedEvtId = Dem_CfgEventTable[EventIdx].awEvtId;
            }
        }

        if((TRUE == DEM_GET_UDS_STATUS_CDTC(EventIdx)) &&
           ((EventStatusOld & DEM_EVENT_DTC_STATUS_CDTC) != DEM_EVENT_DTC_STATUS_CDTC))
        {
            /* Store first and most recently confirmed event */
            if(DEM_INIT_ZERO == info_ptr->firstConfirmEvtId)
            {
                info_ptr->firstConfirmEvtId = Dem_CfgEventTable[EventIdx].awEvtId;
            }
            info_ptr->recentlyConfirmEvtId = Dem_CfgEventTable[EventIdx].awEvtId;
            entry_ptr[EntryIdx].stFault = DEM_EVENT_CONFIRMED;
        }

        if(TRUE == DEM_GET_UDS_STATUS_TFTOC(EventIdx))
        {
            entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(EventMemIdx);
#if(DEM_CFG_OCC1SUPPORT == STD_ON)
            entry_ptr[EntryIdx].cntOCC1 = DEM_INIT_ZERO;
#endif
#if(DEM_CFG_OCC2SUPPORT == STD_ON)
            entry_ptr[EntryIdx].cntOCC2 = DEM_INIT_ZERO;
#endif
#if(DEM_CFG_OCC4SUPPORT == STD_ON)
            if((entry_ptr[EntryIdx].cntOCC4 < DEM_BYTE_MAX) &&
               ((EventStatusOld & DEM_EVENT_DTC_STATUS_TFTOC) != DEM_EVENT_DTC_STATUS_TFTOC))
            {
                entry_ptr[EntryIdx].cntOCC4++;
            }
#endif
#if(DEM_CFG_OCC5SUPPORT == STD_ON)
            entry_ptr[EntryIdx].cntOCC5 = DEM_INIT_ZERO;
#endif
#if(DEM_CFG_OCC6SUPPORT == STD_ON)
            if( (entry_ptr[EntryIdx].cntOCC6 < DEM_BYTE_MAX) &&
                ((EventStatusOld & DEM_EVENT_DTC_STATUS_TFTOC) != DEM_EVENT_DTC_STATUS_TFTOC) )
            {
                entry_ptr[EntryIdx].cntOCC6++;
            }
            if( (entry_ptr[EntryIdx].cntOCC6 >= Dem_CfgEvtFcThrs[EventIdx]) ||
                (TRUE == DEM_GET_UDS_STATUS_CDTC(EventIdx)) )
            {
                entry_ptr[EntryIdx].cntOCC6 = DEM_INIT_ZERO;
            }
#endif
#if(DEM_CFG_OCC7SUPPORT == STD_ON)
            /* Increase OCC7 counter when event test failed in one operation. */
            if((entry_ptr[EntryIdx].cntOCC7 < DEM_BYTE_MAX) &&
               ((EventStatusOld & DEM_EVENT_DTC_STATUS_TFTOC) != DEM_EVENT_DTC_STATUS_TFTOC) &&
               ((EventStatusOld & DEM_EVENT_DTC_STATUS_TNCTOC) == DEM_EVENT_DTC_STATUS_TNCTOC) &&
               (FALSE == DEM_GET_UDS_STATUS_TNCTOC(EventIdx)))
            {
                entry_ptr[EntryIdx].cntOCC7++;
            }
#endif
        }
        if(TRUE == infoUpdate)
        {
            /* Trigger EventMemoryInfo block update */
            Dem_EventMemoryNvmBlkUpdateReq(EventMemIdx,
                                           DEM_NVM_INFO_BLOCK,
                                           DEM_NVM_REQ_WRITE,
                                           Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acImdiStor);
        }                  
        /* Trigger EventMemoryEntry block update */
        Dem_EventMemoryNvmBlkUpdateReq(EventMemIdx,
                                       EntryIdx,
                                       DEM_NVM_REQ_WRITE,
                                       Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acImdiStor);
    }
}

#if(DEM_CFG_EXTENDSTATUSBYTE != DEM_INIT_ZERO)
/*
********************************************************************************
* Function Name: Dem_EventExStatusHandle
*
* Explanation: Extended DTC status indicator handle 
*
* param: uint16 EventIdx, index of event table
*
* retval: void
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventExStatusHandle
(
    uint16 EventIdx
)
{
    boolean nvmUpdate = FALSE;
    uint16 dtcIdx;
    
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        if((DEM_GET_FDCCNT(EventIdx) >= (sint8)Dem_CfgDTCTable[dtcIdx].acFdcEvtMemStorThrs) &&
           (DEM_GET_FDCCNT(EventIdx) < (sint8)DEM_DEBOUNCE_FDC_HIGH_THRESHOLD))
        {
#if(DEM_CFG_UCSUPPORT == STD_ON)
            /* Set Bit0/1/2/4 if FDC is between uncomfirmedlimit and 127*/
            if(FALSE == DEM_GET_STATUS_INDI_UC(EventIdx))
            {
                DEM_SET_STATUS_INDI_UC(EventIdx);
                nvmUpdate = TRUE;
            }
#endif
#if(DEM_CFG_UCTOCSUPPORT == STD_ON)
            if(FALSE == DEM_GET_STATUS_INDI_UCTOC(EventIdx))
            {
                DEM_SET_STATUS_INDI_UCTOC(EventIdx);
                nvmUpdate = TRUE;
            }
#endif
#if(DEM_CFG_UCSLCSUPPORT == STD_ON)
            if(FALSE == DEM_GET_STATUS_INDI_UCSLC(EventIdx))
            {
                DEM_SET_STATUS_INDI_UCSLC(EventIdx);
                nvmUpdate = TRUE;
            }
#endif
#if(DEM_CFG_SSLCSUPPORT == STD_ON)
            if(FALSE == DEM_GET_STATUS_INDI_SSLC(EventIdx))
            {
                DEM_SET_STATUS_INDI_SSLC(EventIdx);
                nvmUpdate = TRUE;
            }
#endif
        }
#if(DEM_CFG_UCSUPPORT == STD_ON)
        else if(DEM_DEBOUNCE_FDC_LOW_THRESHOLD == DEM_GET_FDCCNT(EventIdx))
        {
            if(TRUE == DEM_GET_STATUS_INDI_UC(EventIdx))
            {
                /* Reset Bit0 if FDC is equal to -128 */
                DEM_RESET_STATUS_INDI_UC(EventIdx);
                nvmUpdate = TRUE;
            }
        }
#endif
        else if((sint8)DEM_DEBOUNCE_FDC_HIGH_THRESHOLD == DEM_GET_FDCCNT(EventIdx))
        {
            /* Reset Bit3 if FDC is equal to 127 */
#if(DEM_CFG_AGEDSUPPORT == STD_ON)
            if(TRUE == DEM_GET_STATUS_INDI_AGED(EventIdx))
            {
                DEM_RESET_STATUS_INDI_AGED(EventIdx);
                nvmUpdate = TRUE;
            }
#endif
#if(DEM_CFG_TFSLRSUPPORT == STD_ON)            
            /* Set Bit7 if FDC is equal to 127 */
            if(FALSE == DEM_GET_STATUS_INDI_TFSLR(EventIdx))
            {
                DEM_SET_STATUS_INDI_TFSLR(EventIdx);
                nvmUpdate = TRUE;
            }
#endif
        }
        else
        {
            /* do nothing */
        }
        
#if(DEM_CFG_EMRSUPPORT == STD_ON) 
        /* Set Bit6 in case of report happened */
        if((Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acObdDtcIdx > DEM_INIT_ZERO) ||
           (Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acWwhObdClass > DEM_DTC_WWHOBD_CLASS_NOCLASS))
        {
            if(FALSE == DEM_GET_STATUS_INDI_EMR(EventIdx))
            {
                DEM_SET_STATUS_INDI_EMR(EventIdx);
                nvmUpdate = TRUE;
            }
        }
#endif

        if(TRUE == nvmUpdate)
        {
            /* Trigger EventMemoryStatus block update */
            Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                           DEM_NVM_STATUS_BLOCK,
                                           DEM_NVM_REQ_WRITE,
                                           Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acImdiStor);
        }
    }
}
#endif

#if(DEM_CFG_RESETCONFIRMEDBITONOVERFLOW == STD_OFF)
/*
********************************************************************************
* Function Name: Dem_EventMemoryEntryAttemptProcess
*
* Explanation: Process the removed events from event memory entry
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventMemoryEntryAttemptProcess(void)
{
    uint8 evtMemCnt, evtMemIdx, entryIdx;
    uint16 evtIdx;
    Dem_EventMemoryInfo_st *info_ptr;

    for(evtIdx = DEM_INIT_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
    {
        if((TRUE == DEM_GET_UDS_STATUS_CDTC(evtIdx)) &&
           (FALSE == DEM_GET_UDS_STATUS_TF(evtIdx)))
        {
            for(evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++)
            {
                evtMemIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acEvtMemIdx[evtMemCnt];
                
                if(evtMemIdx > DEM_INIT_ZERO)
                {
                    info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(evtMemIdx);
                    
                    if((FALSE == DEM_GET_EVENT_STORED(evtIdx, evtMemIdx)) && 
                       (info_ptr->cntEnSlot < Dem_CfgEventMemoryTable[evtMemIdx].acEvtMemMaxEntry))
                    {
                        /* Try to allocate again */
                        if(E_OK == Dem_EventMemoryEntryAllocate(evtIdx, evtMemIdx, &entryIdx))
                        {
                            /* Trigger EventMemoryInfo block update */
                            Dem_EventMemoryNvmBlkUpdateReq(evtMemIdx,
                                                           DEM_NVM_INFO_BLOCK,
                                                           DEM_NVM_REQ_WRITE,
                                                           Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acImdiStor);

                            /* Trigger EventMemoryEntry block update */
                            Dem_EventMemoryNvmBlkUpdateReq(evtMemIdx,
                                                           entryIdx,
                                                           DEM_NVM_REQ_WRITE,
                                                           Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acImdiStor);
                        }
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
}
#endif

/*
********************************************************************************
* Function Name: Dem_EventMemoryEntryOpcycStart
*
* Explanation: Event memory entry handle while an operation cycle start.
*
* param: uint8 EventMemIdx, refered event memory index
*        uint16 EventIdx, index of event table
*        uint8 OpcycId, operation cycle ID
*
* retval: none
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryEntryOpcycStart
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 OpcycId
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    boolean nvmUpdate = FALSE;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 slotIdx, opcycIdx, entryIdx;
    Dem_EventMemoryInfo_st *info_ptr;
    Dem_EventMemoryEntry_st *entry_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if(((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM)) &&
       ((EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM)))
    {
        /* Get event memory pointer */
        info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(EventMemIdx);
        entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(EventMemIdx);

        for(slotIdx = DEM_INIT_ZERO; slotIdx < info_ptr->cntEnSlot; slotIdx++)
        {
            /* Event is in event memory currently */
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            if(Dem_CfgEventTable[EventIdx].awEvtId == info_ptr->enSlot[slotIdx])
            {
                opcycIdx = Dem_CfgEventTable[EventIdx].acEvtOpcycIdx;
                entryIdx = info_ptr->entryIdx[slotIdx];

                if(OpcycId == Dem_CfgOperationCycleTable[opcycIdx].acCycleId)
                {                
#if(DEM_CFG_OCC1SUPPORT == STD_ON)
                    /* Increment OCC1 at start of operation cycle. */
                    if(entry_ptr[entryIdx].cntOCC1 < DEM_BYTE_MAX)
                    {
                        entry_ptr[entryIdx].cntOCC1++;
                        nvmUpdate = TRUE;
                    }
#endif
#if(DEM_CFG_OCC3SUPPORT == STD_ON)
                    /* Increment OCC3 since events test failed. */
                    if((entry_ptr[entryIdx].cntOCC3 < DEM_BYTE_MAX) &&
                       (TRUE == DEM_GET_UDS_STATUS_TFSLC(EventIdx)))
                    {
                        entry_ptr[entryIdx].cntOCC3++;
                        nvmUpdate = TRUE;
                    }
#endif
#if(DEM_CFG_OCC6SUPPORT == STD_ON)
                    if( (FALSE == DEM_GET_UDS_STATUS_TFTOC(EventIdx)) && 
                        (FALSE == DEM_GET_UDS_STATUS_TNCTOC(EventIdx)) )
                    {
                        entry_ptr[entryIdx].cntOCC6 = DEM_INIT_ZERO;
                        nvmUpdate = TRUE;
                    }
#endif
                }
                
#if(DEM_CFG_OCC5SUPPORT == STD_ON)
                if(FALSE == DEM_GET_UDS_STATUS_WIR(EventIdx))
                {
                    opcycIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acAgeOpcycIdx;
                    if((DEM_OPCYC_WARMUP == Dem_CfgOperationCycleTable[opcycIdx].acCycType) &&
                       (entry_ptr[entryIdx].cntOCC5 < DEM_BYTE_MAX))
                    {
                        entry_ptr[entryIdx].cntOCC5++;
                        nvmUpdate = TRUE;
                    }
                }
#endif
                /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                if(TRUE == nvmUpdate)
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    /* Trigger EventMemoryEntry block update */
                    Dem_EventMemoryNvmBlkUpdateReq(EventMemIdx,
                                                   entryIdx,
                                                   DEM_NVM_REQ_WRITE,
                                                   DEM_IMMEDIATE_STORE_NVM(EventIdx));
                }
                break;
            }
        }
        
        DEM_DUMMY_STATEMENT(entry_ptr);
    }

    return;
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryEntryOpcycEnd
*
* Explanation: Event memory entry handle while an operation cycle end.
*
* param: uint8 EventMemIdx, refered event memory index
*        uint16 EventIdx, index of event table
*        uint8 OpcycId, operation cycle ID
*
* retval: none
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryEntryOpcycEnd
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 OpcycId
)
{
    boolean nvmUpdate = FALSE;
#if(DEM_CFG_AGINGCYCLECOUNTERPROCESS == DEM_PROCESS_AGINGCTR_INTERN)
    boolean bitWIR, bitTFTOC, bitTNCTOC;
#endif
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 slotIdx, entryIdx, opcycIdx;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
    uint8 statusByte;
#endif
    Dem_EventMemoryInfo_st *info_ptr;
    Dem_EventMemoryEntry_st *entry_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if(((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM)) &&
        ((EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM)))
    {
        opcycIdx = Dem_CfgEventTable[EventIdx].acEvtOpcycIdx;
        /* Reset bit2 "PendingDTC" with condition bit TFTOC and TNCTOC are FALSE */
        if((OpcycId == Dem_CfgOperationCycleTable[opcycIdx].acCycleId) &&
           (TRUE == DEM_GET_UDS_STATUS_PDTC(EventIdx)) &&
           (FALSE == DEM_GET_UDS_STATUS_TFTOC(EventIdx)) &&
           (FALSE == DEM_GET_UDS_STATUS_TNCTOC(EventIdx)))
        {
            DEM_RESET_UDS_STATUS_PDTC(EventIdx);
            /* Trigger EventMemory status block update */
            Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                           DEM_NVM_STATUS_BLOCK,
                                           DEM_NVM_REQ_WRITE,
                                           DEM_IMMEDIATE_STORE_NVM(EventIdx));
        }
        
        /* Get event memory pointer */
        info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(EventMemIdx);
        entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(EventMemIdx);

        for(slotIdx = DEM_INIT_ZERO; slotIdx < info_ptr->cntEnSlot; slotIdx++)
        {
            /* Event is in event memory currently */
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            if(Dem_CfgEventTable[EventIdx].awEvtId == info_ptr->enSlot[slotIdx])
            {
                opcycIdx = Dem_CfgEventTable[EventIdx].acEvtOpcycIdx;
                /* Get entry index of this event in event momery */
                entryIdx = info_ptr->entryIdx[slotIdx];
                
                if(OpcycId == Dem_CfgOperationCycleTable[opcycIdx].acCycleId)
                {
                    /* Reset Bit7 "WarningIndicatorRequested" */
                    Dem_EventMemoryEntryHealing(EventMemIdx, slotIdx);
                    
                    /* Calculation of Counter CSLF */
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    if(DEM_BYTE_MAX > entry_ptr[entryIdx].cntCslf)
                    {
                        entry_ptr[entryIdx].cntCslf++;
                        nvmUpdate = TRUE;
                    }
                    
                    /* Calculation of Counter CSFF */
                    if(DEM_BYTE_MAX > entry_ptr[entryIdx].cntCsff)
                    {
                        entry_ptr[entryIdx].cntCsff++;
                        nvmUpdate = TRUE;
                    }

                    /* Calculation of Counter FC */
                    if(TRUE == DEM_GET_UDS_STATUS_TFTOC(EventIdx))
                    {
                        if(DEM_BYTE_MAX > entry_ptr[entryIdx].cntFc)
                        {
                            entry_ptr[entryIdx].cntFc++;
                            nvmUpdate = TRUE;
                        }
                    }
                }

                /* Aging handle */
#if(DEM_CFG_AGINGCYCLECOUNTERPROCESS == DEM_PROCESS_AGINGCTR_INTERN)
                opcycIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acAgeOpcycIdx;
                if((OpcycId == Dem_CfgOperationCycleTable[opcycIdx].acCycleId) && 
                   (TRUE == Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acAgeAllow))
                {
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
                    if(E_OK == Dem_EventGetCombStatusByte(EventIdx, &statusByte))
                    {
                        bitWIR = (statusByte & DEM_EVENT_DTC_STATUS_WIR) ? TRUE : FALSE;
                        bitTFTOC = (statusByte & DEM_EVENT_DTC_STATUS_TFTOC) ? TRUE : FALSE;
                        bitTNCTOC = (statusByte & DEM_EVENT_DTC_STATUS_TNCTOC) ? TRUE : FALSE;
                    }
#else
                    bitWIR = DEM_GET_UDS_STATUS_WIR(EventIdx);
                    bitTFTOC = DEM_GET_UDS_STATUS_TFTOC(EventIdx);
                    bitTNCTOC = DEM_GET_UDS_STATUS_TNCTOC(EventIdx);
#endif
                    
#if(DEM_CFG_AGINGCOUNTERREQUIRETESTEDCYCLE == STD_ON)
                    if((FALSE == bitWIR) && (FALSE == bitTFTOC) && (FALSE == bitTNCTOC))
#else
                    if((FALSE == bitWIR) && ((TRUE == bitTNCTOC) || (FALSE == bitTFTOC)))
#endif
                    {
                        /* In the case of CDTC bit is 1 and TFTOC is 0, */
                        /* which means this fault was not detected */
                        /* in last operation cycle, increment the aging counter */
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                        if(DEM_BYTE_MAX > entry_ptr[entryIdx].cntAge)
                        {
                            entry_ptr[entryIdx].cntAge++;
                        }
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
                        if(DEM_WORD_MAX > entry_ptr[entryIdx].cntAge2)
                        {
                            entry_ptr[entryIdx].cntAge2++;
                        }
#endif
                        entry_ptr[entryIdx].stFault = DEM_EVENT_AGING;
                        nvmUpdate = TRUE;
                    }

                    if(E_OK == Dem_EventMemoryEntryAging(EventMemIdx, slotIdx))
                    {
                        /* Remove this event from event memory */
                        Dem_EventMemoryEntryRemove(entryIdx, EventMemIdx);
                        /* The aged counter accumulate */
#if(DEM_CFG_AGEDCTRSUPPORT == STD_ON)
                        if(DEM_BYTE_MAX > DEM_GET_AGED_CNT(EventIdx))
                        {
                            DEM_GET_AGED_CNT(EventIdx)++;
                        }
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
                        if(DEM_WORD_MAX > DEM_GET_AGED_CNT2(EventIdx))
                        {
                            DEM_GET_AGED_CNT2(EventIdx)++;
                        }
#endif
#endif

#if(DEM_CFG_AGEDSUPPORT == STD_ON)
                        DEM_SET_STATUS_INDI_AGED(EventIdx);
#endif

#if(DEM_CFG_TFSLRSUPPORT == STD_ON)
                        DEM_RESET_STATUS_INDI_TFSLR(EventIdx);
#endif
                        /* Trigger EventMemoryInfo block update */
                        nvmUpdate = TRUE;
                        
                    }
                }
#endif
                if(TRUE == nvmUpdate)
                {
                    /* Trigger EventMemoryEntry block update */
                    Dem_EventMemoryNvmBlkUpdateReq(EventMemIdx,
                                                   entryIdx,
                                                   DEM_NVM_REQ_WRITE,
                                                   DEM_IMMEDIATE_STORE_NVM(EventIdx));
                    Dem_EventMemoryNvmBlkUpdateReq(EventMemIdx,
                                                   DEM_NVM_INFO_BLOCK,
                                                   DEM_NVM_REQ_WRITE,
                                                   DEM_IMMEDIATE_STORE_NVM(EventIdx));
                }
                break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryEntryHealing
*
* Explanation: Event memory entry healing handle.
*
* param: uint8 EventMemIdx, refered event memory index
*        uint8 EntrySlotIdx, slot index in event memory
*
* retval: none
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryEntryHealing
(
    uint8 EventMemIdx,
    uint8 EntrySlotIdx
)
{
    boolean bitWIR = FALSE;
    boolean bitTFTOC = FALSE;
    boolean bitTNCTOC = TRUE;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 entryIdx;
    uint8 cntHeal[DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM] = {DEM_INIT_ZERO};
    uint8 evtIndiIdx;
    uint8 indiIdx;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
    uint8 statusByte;
    uint16 dtcIdx, combEvtCnt, combEvtIdx;
#endif
    uint16 evtIdx;
    Dem_EventMemoryEntry_st *entry_ptr;
    Dem_EventMemoryInfo_st *info_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM))
    {
        /* Get event memory pointer */
        info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(EventMemIdx);
        entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(EventMemIdx);

        if((EntrySlotIdx < Dem_CfgEventMemoryTable[EventMemIdx].acEvtMemMaxEntry) &&
           (info_ptr->enSlot[EntrySlotIdx] <= DEM_CFG_EVENT_ID_MAX))
        {
            evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[EntrySlotIdx]];
            entryIdx = info_ptr->entryIdx[EntrySlotIdx];

#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
            if(E_OK == Dem_EventGetCombStatusByte(evtIdx, &statusByte))
            {
                bitWIR = (statusByte & DEM_EVENT_DTC_STATUS_WIR) ? TRUE : FALSE;
                bitTFTOC = (statusByte & DEM_EVENT_DTC_STATUS_TFTOC) ? TRUE : FALSE;
                bitTNCTOC = (statusByte & DEM_EVENT_DTC_STATUS_TNCTOC) ? TRUE : FALSE;
            }
#else
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            bitWIR = DEM_GET_UDS_STATUS_WIR(evtIdx);
            bitTFTOC = DEM_GET_UDS_STATUS_TFTOC(evtIdx);
            bitTNCTOC = DEM_GET_UDS_STATUS_TNCTOC(evtIdx);
#endif
            /*** Healing Handle ***/
            if((TRUE == bitWIR) && (FALSE == bitTFTOC) && (FALSE == bitTNCTOC) &&
               (evtIdx > DEM_INIT_ZERO) && (evtIdx <= DEM_CFG_EVENT_NUM))
            {
                for(evtIndiIdx = DEM_INIT_ZERO; evtIndiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; evtIndiIdx++)
                {
                    indiIdx = Dem_CfgEventTable[evtIdx].acIndiIdx[evtIndiIdx];
                    if(DEM_INIT_ZERO == indiIdx)
                    {
                        /* No indicator. */
                        break;
                    }
                    else
                    {
                        /* Healing counter should process in the operation cycle that configured in acIndHealingOpCycIdx. */
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                        if((DEM_CYCLE_STATE_START == DEM_GET_OPCYC_STATE(Dem_CfgEventTable[evtIdx].acIndHealingOpCycIdx[evtIndiIdx])) &&
                          (TRUE == DEM_GET_INDICATOR(evtIdx, evtIndiIdx)))
                        {
                            /* In the case of WIR bit is 1 and TFTOC/TNCTOC is 0, */
                            /* which means this fault was not detected */
                            /* in last operation cycle, increment the healing counter */
                            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                            if(DEM_BYTE_MAX > entry_ptr[entryIdx].cntHeal[evtIndiIdx])
                            {
                                entry_ptr[entryIdx].cntHeal[evtIndiIdx]++;
                            }
                            cntHeal[evtIndiIdx] = entry_ptr[entryIdx].cntHeal[evtIndiIdx];
                        }
                    }
                }
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                entry_ptr[entryIdx].stFault = DEM_EVENT_HEALING;

                if(E_OK == Dem_EventCheckWarningIndicatorDeAct(evtIdx, cntHeal))
                {
                    /* Reset bit7 "WarningIndicatorRequested" when */
                    /* indicator off criteria fullfilled */
                    DEM_RESET_UDS_STATUS_WIR(evtIdx);
#if(DEM_CFG_WIRSLCSUPPORT == STD_ON)
                    DEM_RESET_STATUS_INDI_WIRSLC(evtIdx);
#endif
                }

#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
                for(combEvtCnt = DEM_INIT_ZERO; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
                {
                    combEvtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[combEvtCnt];
                    if(combEvtIdx > DEM_INIT_ZERO)
                    {
                        if(E_OK == Dem_EventCheckWarningIndicatorDeAct(combEvtIdx, cntHeal))
                        {
                            /* Reset bit7 "WarningIndicatorRequested" when */
                            /* indicator off criteria fullfilled */
                            DEM_RESET_UDS_STATUS_WIR(combEvtIdx);

#if(DEM_CFG_WIRSLCSUPPORT == STD_ON)
                            DEM_RESET_STATUS_INDI_WIRSLC(combEvtIdx);
#endif
                        }
                    }
                    else
                    {
                        break;
                    }
                }
#endif
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryEntryAging
*
* Explanation: Event memory entry healing handle.
*
* param: uint8 EventMemIdx, refered event memory index
*        uint8 EntrySlotIdx, slot index in event memory
*
* retval: E_OK, aging criteria fullfilled; E_NOT_OK, aging not fullfilled
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, DEM_CODE) Dem_EventMemoryEntryAging
(
    uint8 EventMemIdx,
    uint8 EntrySlotIdx
)
{
    boolean bitWIR = FALSE;
    boolean indiClearReq = FALSE;
#if(DEM_CFG_STATUSBITHANDLINGTESTFAILEDSINCELASTCLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
    boolean bitTFSLC = FALSE;
    boolean clearTFSLC = FALSE;
#endif
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
    boolean clearCDTC = FALSE;
#endif
    uint8 ret = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 entryIdx;
    uint8 indiIdx;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
    uint8 statusByte;
    uint16 combEvtCnt, combEvtIdx;
#endif
    uint16 evtIdx, dtcIdx;
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    uint8 opcycIdx;
    uint8 opcycOBDIdx = DEM_INIT_ZERO;
    Dem_PermanentEventMemoryEntry_st *ptr;
#endif
    Dem_EventMemoryEntry_st *entry_ptr;
    Dem_EventMemoryInfo_st *info_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM))
    {
        info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(EventMemIdx);
        entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(EventMemIdx);

        if((EntrySlotIdx < Dem_CfgEventMemoryTable[EventMemIdx].acEvtMemMaxEntry) &&
           (info_ptr->enSlot[EntrySlotIdx] <= DEM_CFG_EVENT_ID_MAX))
        {
            evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[EntrySlotIdx]];
            dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
            
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
            /* [SWS_Dem_01184] */
            for(opcycIdx = DEM_INIT_ONE; opcycIdx <= DEM_CFG_OPCYC_NUM; opcycIdx++)
            {
                if(DEM_OPCYC_OBD_DCY == Dem_CfgOperationCycleTable[opcycIdx].acCycType)
                {
                    opcycOBDIdx = opcycIdx;
                }
            }

            if(((DEM_INIT_ZERO == Dem_CfgDTCTable[dtcIdx].acObdDtcIdx) &&
                (DEM_DTC_WWHOBD_CLASS_NOCLASS == Dem_CfgDTCTable[dtcIdx].acWwhObdClass)) ||
               ((opcycOBDIdx > DEM_INIT_ZERO) && 
                (DEM_CYCLE_STATE_END == DEM_GET_OPCYC_STATE(opcycOBDIdx)) && 
                (DEM_INIT_ZERO < DEM_GET_OBD_WUC_STARTED_LAST_DRICYC())))

#endif
            {
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
                if(E_OK == Dem_EventGetCombStatusByte(evtIdx, &statusByte))
                {
                    bitWIR = (statusByte & DEM_EVENT_DTC_STATUS_WIR) ? TRUE : FALSE;
#if(DEM_CFG_STATUSBITHANDLINGTESTFAILEDSINCELASTCLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
                    bitTFSLC = (statusByte & DEM_EVENT_DTC_STATUS_TFSLC) ? TRUE : FALSE;
#endif
                }
#else
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                bitWIR = DEM_GET_UDS_STATUS_WIR(evtIdx);
#if(DEM_CFG_STATUSBITHANDLINGTESTFAILEDSINCELASTCLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
                bitTFSLC = DEM_GET_UDS_STATUS_TFSLC(evtIdx);
#endif
#endif
                if((FALSE == bitWIR) && (evtIdx > DEM_INIT_ZERO) && (evtIdx <= DEM_CFG_EVENT_NUM))
                {
                    entryIdx = info_ptr->entryIdx[EntrySlotIdx];

#if(DEM_CFG_STATUSBITHANDLINGTESTFAILEDSINCELASTCLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
                    /* Reset bit5 "TestFailedSinceLastClear" with condition aging counter reached threshold */
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
                    if((TRUE == bitTFSLC) && 
                       /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                       ((entry_ptr[entryIdx].cntAge >= Dem_CfgDTCTable[dtcIdx].acAgeCycThrsTFSLC) ||
                       (entry_ptr[entryIdx].cntAge2 >= Dem_CfgDTCTable[dtcIdx].acAgeCycThrsTFSLC)))
#else
                    if((TRUE == bitTFSLC) && 
                       (entry_ptr[entryIdx].cntAge >= Dem_CfgDTCTable[dtcIdx].acAgeCycThrsTFSLC))
#endif
                    {
                        DEM_RESET_UDS_STATUS_TFSLC(evtIdx);
#if((DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE) && \
    (DEM_CFG_STATUSBITHANDLINGTESTFAILEDSINCELASTCLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT))
                        clearTFSLC = TRUE;
#endif
                        DEM_DUMMY_STATEMENT(clearTFSLC);
                    }
#endif
                    /* Reset bit3 "ConfirmedDTC" and remove event from event */
                    /* memory when aging counter reached the threshold */
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    if((entry_ptr[entryIdx].cntAge >= Dem_CfgDTCTable[dtcIdx].acAgeCycThrs) ||
                       (entry_ptr[entryIdx].cntAge2 >= Dem_CfgDTCTable[dtcIdx].acAgeCycThrs))
#else
                    if(entry_ptr[entryIdx].cntAge >= Dem_CfgDTCTable[dtcIdx].acAgeCycThrs)
#endif
                    {
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
                        if((Dem_CfgDTCTable[dtcIdx].acObdDtcIdx > DEM_INIT_ZERO) ||
                           (Dem_CfgDTCTable[dtcIdx].acWwhObdClass> DEM_DTC_WWHOBD_CLASS_NOCLASS))
                        {
                            ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
                            /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                            if(Dem_CfgDTCTable[dtcIdx].acWwhObdClass > DEM_DTC_WWHOBD_CLASS_NOCLASS)
                            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                            {
                                /* [SWS_Dem_01176] For wwh OBD DTC, aging will be happened */
                                /* after 200 engine run hours without fault */
                                if(entry_ptr[entryIdx].cntAgeHour >= 200U)
                                {
                                    DEM_RESET_UDS_STATUS_CDTC(evtIdx);
                                    indiClearReq = TRUE;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
                                    clearCDTC = TRUE;
#endif
                                    ret = E_OK;
                                }
                            }
                            else
                            {
                                DEM_RESET_UDS_STATUS_CDTC(evtIdx);
                                indiClearReq = TRUE;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
                                clearCDTC = TRUE;
#endif
                                ret = E_OK;
                            }

                            if((E_OK == ret) && (ptr->freezeframeEvtId == info_ptr->enSlot[EntrySlotIdx]))
                            {
                                Dem_ObdClearLegislativeFreezeFrame();
                            }
                        }
                        else
#endif
                        {
                            DEM_RESET_UDS_STATUS_CDTC(evtIdx);
                            indiClearReq = TRUE;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
                            clearCDTC = TRUE;
#endif
                            ret = E_OK;
                        }
                    }
                    /* Aging criteria fullfilled, clear the indicator failure counter. */
                    if(TRUE == indiClearReq)
                    {
                        for(indiIdx = DEM_INIT_ZERO; indiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; indiIdx++)
                        {
                            DEM_SET_LAMP_FAILED_CNT(evtIdx, indiIdx, DEM_INIT_ZERO);
                        }
                        DEM_SET_LAMPFAILCNT_UPDATED(evtIdx, FALSE);
                    }
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
                    for(combEvtCnt = DEM_INIT_ZERO; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
                    {
                        combEvtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[combEvtCnt];
                        if(combEvtIdx > DEM_INIT_ZERO)
                        {
#if(DEM_CFG_STATUSBITHANDLINGTESTFAILEDSINCELASTCLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
                            if(TRUE == clearTFSLC)
                            {
                                DEM_RESET_UDS_STATUS_TFSLC(combEvtIdx);
                            }
#endif

                            if(TRUE == clearCDTC)
                            {
                                DEM_RESET_UDS_STATUS_CDTC(combEvtIdx);
                                /* Aging criteria fullfilled, clear the indicator failure counter. */
                                for(indiIdx = DEM_INIT_ZERO; indiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; indiIdx++)
                                {
                                    DEM_SET_LAMP_FAILED_CNT(combEvtIdx, indiIdx, DEM_INIT_ZERO);
                                }
                                DEM_SET_LAMPFAILCNT_UPDATED(combEvtIdx, FALSE);
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
#endif
                }
            }
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryEntryExist
*
* Explanation: check whether an event is in event memory currently.
*
* param: uint16 EventIdx, index of event table
*
* retval: E_OK, event is in event memory; E_NOT_OK, event is not in event memory
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_EventMemoryEntryExist
(
    uint16 EventIdx
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 evtMemIdx, evtMemCnt;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        for(evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++)
        {
            /* According to Configuration "DemMemoryDestinationRef", select the event memory origin */
            evtMemIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acEvtMemIdx[evtMemCnt];

            if(evtMemIdx > DEM_INIT_ZERO)
            {
                if(TRUE == DEM_GET_EVENT_STORED(EventIdx, evtMemIdx))
                {
                    ret = E_OK;
                    break;
                }
            }
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryEntryAllocate
*
* Explanation: Try to allocate a entry for a new event into event memory.
*
* param: uint16 EventIdx, index of event table
*
* retval: the result of allocation, E_OK, allocate successfully
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_EventMemoryEntryAllocate
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) EntryIdx
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 evtMemCnt;
    uint8 entryIndex = DEM_INIT_ZERO;
    Dem_EventMemoryEntry_st *entry_ptr;
    Dem_EventMemoryInfo_st *info_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EntryIdx != NULL_PTR) &&
       (EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM))
    {
        for(evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++)
        {
            /* According to Configuration "DemMemoryDestinationRef", select the event memory origin */
            if(EventMemIdx == Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acEvtMemIdx[evtMemCnt])
            {
                /* Get event memory entry pointer */
                entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(EventMemIdx);
                info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(EventMemIdx);
                
                /* check over flow */
                if(info_ptr->cntEnSlot < Dem_CfgEventMemoryTable[EventMemIdx].acEvtMemMaxEntry)
                {
                    /* Find empty entry for new event */
                    for(entryIndex = DEM_INIT_ZERO; entryIndex < Dem_CfgEventMemoryTable[EventMemIdx].acEvtMemMaxEntry; entryIndex++)
                    {
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                        if(DEM_INIT_ZERO == entry_ptr[entryIndex].evtId)
                        {
                            Dem_EventMemoryEntryEnter(EventIdx, EventMemIdx, entryIndex);
                            ret = E_OK;
                            break;
                        }
                    }
                }
                else
                {
                    /* Event memory is full, try displacement */
                    ret = Dem_EventMemoryEntryDisplace(EventIdx, EventMemIdx, &entryIndex);
                }

                if(E_OK == ret)
                {
                    /* allocation successfully */
                    *EntryIdx = entryIndex;
                    break;
                }
            }
        }
    }
    
    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryEntryDisplace
*
* Explanation: Displace a old event in event memory with a higher priority event.
*
* param: uint8 EventMemIdx, event memory index 
*        uint16 EventIdx, index of event table
*
* retval: the result of displace, E_OK, displace successfully
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_EventMemoryEntryDisplace
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) EntryIdx
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 entryDisp = FALSE;
    uint8 entryDispIdx = DEM_INIT_ZERO;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 entryIdx = DEM_INIT_ZERO;
    /* Polyspace +1 DEFECT:PARTIALLY_ACCESSED_ARRAY [JUstified:Unset] "NSCA_Polyspace_Dem_PartiallyAccessedArray" */
    uint8 evtPriLow_old_entryIdx[DEM_CFG_MAX_NUMBER_EVENT_ENTRY + DEM_BYTE_ONE] = {DEM_INIT_ZERO};
    uint8 evtPriLow_old_entryCnt = DEM_INIT_ZERO;
    uint8 evtPriLow_old, evtPriLow_new;
    uint16 evtIdx_new, evtIdx_old, dtcIdx_new, dtcIdx_old;
    Dem_EventMemoryInfo_st *info_ptr;
    Dem_EventMemoryEntry_st *entry_ptr;
    uint8 entryError = FALSE;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM))
    {
        /* Get event memory pointer */
        info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(EventMemIdx);
        entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(EventMemIdx);

        if( (info_ptr->cntEnSlot <= Dem_CfgEventMemoryTable[EventMemIdx].acEvtMemMaxEntry) &&
            (info_ptr->enSlot[entryIdx] > DEM_INIT_ZERO) &&
            (info_ptr->enSlot[entryIdx] <= DEM_CFG_EVENT_ID_MAX) )
        {
            evtIdx_new = EventIdx;
            dtcIdx_new = Dem_CfgEvtDtcIdx[evtIdx_new];
            evtPriLow_new = Dem_CfgDtcPriority[dtcIdx_new];

            evtIdx_old = Dem_CfgEventIdTableIndex[info_ptr->enSlot[entryIdx]];
            dtcIdx_old = Dem_CfgEvtDtcIdx[evtIdx_old];
            evtPriLow_old = Dem_CfgDtcPriority[dtcIdx_old];
            evtPriLow_old_entryCnt++;
            /* First oldest entryIdx. Count from 1. */
            evtPriLow_old_entryIdx[evtPriLow_old_entryCnt] = info_ptr->entryIdx[entryIdx];

#if(DEM_CFG_EVENTDISPLACEMENTSTRATEGY != DEM_DISPLACEMENT_NONE)
            /* Polling to find out the lowest priority events in current event memory. */
            /* Note: entryIdx as slotIdx. */
            for(entryIdx = DEM_BYTE_ONE; entryIdx < info_ptr->cntEnSlot; entryIdx++)
            {
                if( (info_ptr->enSlot[entryIdx] > DEM_INIT_ZERO) &&
                    (info_ptr->enSlot[entryIdx] <= DEM_CFG_EVENT_ID_MAX) )
                {
                    evtIdx_old = Dem_CfgEventIdTableIndex[info_ptr->enSlot[entryIdx]];
                    dtcIdx_old = Dem_CfgEvtDtcIdx[evtIdx_old];

                    /* High value means a lower priority */
                    if(evtPriLow_old < Dem_CfgDtcPriority[dtcIdx_old])
                    {
                        evtPriLow_old_entryCnt = DEM_BYTE_ONE;
                        evtPriLow_old = Dem_CfgDtcPriority[dtcIdx_old];
                        evtPriLow_old_entryIdx[evtPriLow_old_entryCnt] = info_ptr->entryIdx[entryIdx];
                    }
                    else if(evtPriLow_old == Dem_CfgDtcPriority[dtcIdx_old])
                    {
                        evtPriLow_old_entryCnt++;
                        evtPriLow_old_entryIdx[evtPriLow_old_entryCnt] = info_ptr->entryIdx[entryIdx];
                    }
                    else
                    {
                        /* do nothing */
                    }
                }
                else
                {
                    /* Error entry */
                    entryError = TRUE;
                    break;
                }
            }

            if( FALSE == entryError )
            {
                /* if new event priority is higher then the found lowest priority, displace */
                if(evtPriLow_old > evtPriLow_new)
                {
                    /* New event's priority is higher than the lowest priority or equal to it */
#if(DEM_CFG_EVENTDISPLACEMENTSTRATEGY == DEM_DISPLACEMENT_FULL)
                    /* Looking for passive event. Polling from the end of the found entry which is the oldest event for chronological order requirement */
                    for(entryIdx = evtPriLow_old_entryCnt; entryIdx > DEM_INIT_ZERO ; entryIdx--)
                    {
#if((DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT) && (DEM_CFG_OBD_EVENT_DISPLACEMENT == TRUE))
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                        if((E_OK == Dem_ObdCheckEventDisplace(entry_ptr[evtPriLow_old_entryIdx[entryIdx]].evtId)) &&
                        (DEM_EVENT_PASSIVE == entry_ptr[evtPriLow_old_entryIdx[entryIdx]].evtActive))
#else       
                        if(DEM_EVENT_PASSIVE == entry_ptr[evtPriLow_old_entryIdx[entryIdx]].evtActive)
#endif
                        {
                            entryDisp = TRUE;
                            entryDispIdx = evtPriLow_old_entryIdx[entryIdx];
                            break;
                        }
                    }
#endif
                    /* No found passive event or configure to DEM_DISPLACEMENT_PRIO_OCC, displace the oldest event */
                    if(FALSE == entryDisp)
                    {
#if((DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT) && (DEM_CFG_OBD_EVENT_DISPLACEMENT == TRUE))
                        for(entryIdx = evtPriLow_old_entryCnt; entryIdx > DEM_INIT_ZERO ; entryIdx--)
                        {
                            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                            if(E_OK == Dem_ObdCheckEventDisplace(entry_ptr[evtPriLow_old_entryIdx[entryIdx]].evtId))
                            {
                                entryDisp = TRUE;
                                entryDispIdx = evtPriLow_old_entryIdx[entryIdx];
                                break;
                            }
                        }
#else
                        entryDisp = TRUE;
                        entryDispIdx = evtPriLow_old_entryIdx[evtPriLow_old_entryCnt];
#endif
                    }
                }
                else if(evtPriLow_old == evtPriLow_new)
                {
#if(DEM_CFG_EVENTDISPLACEMENTSTRATEGY == DEM_DISPLACEMENT_FULL)
                    /* Looking for passive event. Polling from the end of the found entry which is the oldest event for chronological order requirement */
                    for(entryIdx = evtPriLow_old_entryCnt; entryIdx > DEM_INIT_ZERO ; entryIdx--)
                    {
#if((DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT) && (DEM_CFG_OBD_EVENT_DISPLACEMENT == TRUE))
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                        if((E_OK == Dem_ObdCheckEventDisplace(entry_ptr[evtPriLow_old_entryIdx[entryIdx]].evtId)) &&
                        (DEM_EVENT_PASSIVE == entry_ptr[evtPriLow_old_entryIdx[entryIdx]].evtActive))
#else
                        if(DEM_EVENT_PASSIVE == entry_ptr[evtPriLow_old_entryIdx[entryIdx]].evtActive)
#endif
                        {
                            entryDisp = TRUE;
                            entryDispIdx = evtPriLow_old_entryIdx[entryIdx];
                            break;
                        }
                    }
#endif
                    /* No found passive event or configure to DEM_DISPLACEMENT_PRIO_OCC, Looking for event which is not tested in this OperationCycle */
                    if(FALSE == entryDisp)
                    {
                        /* If an event memory entry has the same priority like the reported event and the existing event */ 
                        /* is not tested in this OperationCycle (TestNot-CompletedThisOperationCycle bit == 1) the Dem */
                        /* module shall displace this event [SWS_Dem_00692] */
                        for(entryIdx = evtPriLow_old_entryCnt; entryIdx > DEM_INIT_ZERO ; entryIdx--)
                        {
                            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                            evtIdx_old = Dem_CfgEventIdTableIndex[entry_ptr[evtPriLow_old_entryIdx[entryIdx]].evtId];

#if((DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT) && (DEM_CFG_OBD_EVENT_DISPLACEMENT == TRUE))
                            if((E_OK == Dem_ObdCheckEventDisplace(entry_ptr[evtPriLow_old_entryIdx[entryIdx]].evtId)) &&
                            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                            (TRUE == DEM_GET_UDS_STATUS_TNCTOC(evtIdx_old)))
#else
                            if(TRUE == DEM_GET_UDS_STATUS_TNCTOC(evtIdx_old))
#endif
                            {
                                entryDisp = TRUE;
                                entryDispIdx = evtPriLow_old_entryIdx[entryIdx];
                                break;
                            }
                        }
                    }
                }
                else
                {
                    /* do nothing */
                }

                if(TRUE == entryDisp)
                {
#if(DEM_CFG_RESETCONFIRMEDBITONOVERFLOW == STD_ON)
                    /* Reset bit2 and bit3 */
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    evtIdx_old = Dem_CfgEventIdTableIndex[entry_ptr[entryDispIdx].evtId];
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                    DEM_RESET_UDS_STATUS_PDTC(evtIdx_old);
                    DEM_RESET_UDS_STATUS_CDTC(evtIdx_old);
#if(DEM_CFG_STATUSBITHANDLINGTESTFAILEDSINCELASTCLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
                    DEM_RESET_UDS_STATUS_TFSLC(evtIdx_old);
#endif
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
                    Dem_EventCombStatusDisplace(evtIdx_old);
#endif
#endif
                    /* Remove displaced eventid from entry slot */
                    Dem_EventMemoryEntryRemove(entryDispIdx, EventMemIdx);
                    /* New event enter */
                    Dem_EventMemoryEntryEnter(EventIdx, EventMemIdx, entryDispIdx);

                    *EntryIdx = entryDispIdx;
                    ret = E_OK;
                }
            }
#endif
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryEntryEnter
*
* Explanation: Put a new event into event memory.
*
* param: uint8 EventMemIdx, event memory index 
*        uint16 EventIdx, index of event table
*        uint8 entryIdx, index of which event memory entry is selected
*
* retval: none
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryEntryEnter
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx
)
{
    uint8 slotIdx;
    uint8 idx;
    uint8 indiIdx;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
    uint16 dtcIdx, combEvtIdx, combEvtCnt;
#endif
    Dem_EventMemoryInfo_st *info_ptr;
    Dem_EventMemoryEntry_st *entry_ptr;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM) &&
       (EntryIdx < Dem_CfgEventMemoryTable[EventMemIdx].acEvtMemMaxEntry))
    {
        /* Get event memory pointer */
        info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(EventMemIdx);
        entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(EventMemIdx);

        /* Event active state based on bit0 of UDS status */
        if(TRUE == DEM_GET_UDS_STATUS_TF(EventIdx))
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
            entry_ptr[EntryIdx].evtActive = DEM_EVENT_ACTIVE;
        }
        else
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
            entry_ptr[EntryIdx].evtActive = DEM_EVENT_PASSIVE;
        }
        /* Event status in event memory set to pending for new event */
        entry_ptr[EntryIdx].stFault = DEM_EVENT_PENDING;
        /* Start Related operation cylce counters with initialization value of 0 */
        entry_ptr[EntryIdx].cntCslf = DEM_INIT_ZERO;
        entry_ptr[EntryIdx].cntCsff = DEM_INIT_ZERO;
        entry_ptr[EntryIdx].cntFc = DEM_INIT_ZERO;
        entry_ptr[EntryIdx].cntOcc = DEM_INIT_ZERO;
        /* Initialize indicator healing counter. */
        for(indiIdx = DEM_INIT_ZERO; indiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; indiIdx++)
        {
            entry_ptr[EntryIdx].cntHeal[indiIdx] = DEM_INIT_ZERO;
        }
        entry_ptr[EntryIdx].cntAge = DEM_INIT_ZERO;
        entry_ptr[EntryIdx].cntAgeHour = DEM_INIT_ZERO;
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
        entry_ptr[EntryIdx].cntAge2 = DEM_INIT_ZERO;
        entry_ptr[EntryIdx].cntOcc2 = DEM_INIT_ZERO;
#endif
#if(DEM_CFG_OCC1SUPPORT == STD_ON)
        entry_ptr[EntryIdx].cntOCC1 = DEM_INIT_ZERO;
#endif
#if(DEM_CFG_OCC2SUPPORT == STD_ON)
        entry_ptr[EntryIdx].cntOCC2 = DEM_INIT_ZERO;
#endif
#if(DEM_CFG_OCC3SUPPORT == STD_ON)
        entry_ptr[EntryIdx].cntOCC3 = DEM_INIT_ZERO;
#endif
#if(DEM_CFG_OCC7SUPPORT == STD_ON)
        /* Increase OCC7 counter after the first time that the event detected. */
        entry_ptr[EntryIdx].cntOCC7 = DEM_INIT_ONE;
#endif
        if(DEM_GET_FDCCNT(EventIdx) >= (sint8)DEM_DEBOUNCE_FDC_HIGH_THRESHOLD)
        {
#if(DEM_CFG_OCC4SUPPORT == STD_ON)
            entry_ptr[EntryIdx].cntOCC4 = DEM_INIT_ONE;
#endif
#if(DEM_CFG_OCC6SUPPORT == STD_ON)
            entry_ptr[EntryIdx].cntOCC6 = DEM_INIT_ONE;
            if( (entry_ptr[EntryIdx].cntOCC6 >= Dem_CfgEvtFcThrs[EventIdx]) ||
                (TRUE == DEM_GET_UDS_STATUS_CDTC(EventIdx)) )
            {
                entry_ptr[EntryIdx].cntOCC6 = DEM_INIT_ZERO;
            }
#endif
        }
        else
        {
#if( DEM_CFG_OCC4SUPPORT == STD_ON )
            entry_ptr[EntryIdx].cntOCC4 = DEM_INIT_ZERO;
#endif
#if( DEM_CFG_OCC6SUPPORT == STD_ON )
            entry_ptr[EntryIdx].cntOCC6 = DEM_INIT_ZERO;
#endif
        }

#if(DEM_CFG_OCC5SUPPORT == STD_ON)
        entry_ptr[EntryIdx].cntOCC5 = DEM_INIT_ZERO;
#endif

        /* Store EventID */
        entry_ptr[EntryIdx].evtId = Dem_CfgEventTable[EventIdx].awEvtId;
        entry_ptr[EntryIdx].datBuf.ffRecIdx = DEM_INIT_ZERO;
        for(idx = DEM_INIT_ZERO; idx < DEM_CFG_FFDATA_MAX_REF_RECORD_NUM; idx++)
        {
            entry_ptr[EntryIdx].datBuf.stFfData[idx] = FALSE;
        }
        for(idx = DEM_INIT_ZERO; idx < DEM_CFG_EXDATA_MAX_REF_EXDATA_RECORD_NUM; idx++)
        {
            entry_ptr[EntryIdx].datBuf.stExData[idx] = FALSE;
        }

        /* for chronological order, new event always allocated at the 1st slot */
        for(slotIdx = info_ptr->cntEnSlot; slotIdx > DEM_INIT_ZERO; slotIdx--)
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            info_ptr->enSlot[slotIdx] = info_ptr->enSlot[slotIdx - DEM_BYTE_ONE];
            info_ptr->entryIdx[slotIdx] = info_ptr->entryIdx[slotIdx - DEM_BYTE_ONE];
        }
        info_ptr->enSlot[slotIdx] = Dem_CfgEventTable[EventIdx].awEvtId;

        /* Store entryIdx into info block */
        info_ptr->entryIdx[slotIdx] = EntryIdx;

        /* entry_ptr[entryIdx].cntOcc */
        if(TRUE == DEM_GET_UDS_STATUS_TF(EventIdx))
        {
#if(DEM_CFG_OCCURRENCECOUNTERPROCESSING == DEM_PROCESS_OCCCTR_CDTC)
            if(TRUE == DEM_GET_UDS_STATUS_CDTC(EventIdx))
            {
                entry_ptr[EntryIdx].cntOcc = DEM_INIT_ONE;
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
                entry_ptr[EntryIdx].cntOcc2 = DEM_INIT_ONE;
#endif
            }
#else
            entry_ptr[EntryIdx].cntOcc = DEM_INIT_ONE;
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
            entry_ptr[EntryIdx].cntOcc2 = DEM_INIT_ONE;
#endif
#endif
        }

        /* Exist entry number increment */
        info_ptr->cntEnSlot++;

        DEM_SET_EVENT_STORED(EventIdx, EventMemIdx, TRUE);
        DEM_SET_EVENT_ENTRY(EventIdx, EventMemIdx, EntryIdx);

#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        for(combEvtCnt = DEM_INIT_ZERO; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
        {
            combEvtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[combEvtCnt];
            if(combEvtIdx > DEM_INIT_ZERO)
            {
                DEM_SET_EVENT_STORED(combEvtIdx, EventMemIdx, TRUE);
                DEM_SET_EVENT_ENTRY(combEvtIdx, EventMemIdx, EntryIdx);
            }
            else
            {
                break;
            }
        }
#endif
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryEntrySlotUpdate
*
* Explanation: Update the exist slot order.
*
* param: uint8 EventMemIdx, event memory index 
*        Dem_EventIdType EventId, the requested event id
*
* retval: ret, E_OK, slot update successfully E_NOT_OK, no need to update slot
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryEntrySlotUpdate
(
    Dem_EventIdType EventId,
    uint8 EventMemIdx
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 slotIdx, slotIdxNew, entryIdx;
    Dem_EventMemoryInfo_st *info_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM))
    {
        /* Get event memory pointer */
        info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(EventMemIdx);

        for(slotIdx = DEM_INIT_ZERO; slotIdx < info_ptr->cntEnSlot; slotIdx++)
        {
            /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 */
            if(EventId == info_ptr->enSlot[slotIdx])
            {
                if(slotIdx != DEM_INIT_ZERO)
                {
                    entryIdx = info_ptr->entryIdx[slotIdx];
                    for(slotIdxNew = slotIdx; slotIdxNew > DEM_INIT_ZERO; slotIdxNew--)
                    {
                        info_ptr->enSlot[slotIdxNew] = info_ptr->enSlot[slotIdxNew - DEM_BYTE_ONE];
                        info_ptr->entryIdx[slotIdxNew] = info_ptr->entryIdx[slotIdxNew - DEM_BYTE_ONE];
                    }
                    info_ptr->enSlot[slotIdxNew] = EventId;
                    info_ptr->entryIdx[slotIdxNew] = entryIdx;
                }
                break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryEntryRemove
*
* Explanation: Remove a event from event memory when related DTC is aged or cleared.
*
* param: uint8 EventMemIdx, event memory index 
*        Dem_EventIdType EventId, the requested event id
*
* retval: none
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryEntryRemove
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx,
    uint8 EventMemIdx
)
{
    uint8 slotIdx;
    uint16 evtIdx;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
    uint16 dtcIdx, combEvtIdx, combEvtCnt;
#endif
    Dem_EventMemoryInfo_st *info_ptr;
    Dem_EventMemoryEntry_st *entry_ptr;

    if((EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM) &&
       (EntryIdx < Dem_CfgEventMemoryTable[EventMemIdx].acEvtMemMaxEntry))
    {
        /* Get event memory pointer */
        info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(EventMemIdx);
        entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(EventMemIdx);

        for(slotIdx = DEM_INIT_ZERO; slotIdx < info_ptr->cntEnSlot; slotIdx++)
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            if(info_ptr->entryIdx[slotIdx] == EntryIdx)
            {
                break;
            }
        }

        if(slotIdx < info_ptr->cntEnSlot)
        {
            info_ptr->cntEnSlot--;
            
            /* Polyspace +1 DEFECT:OVERLAPPING_ASSIGN [Justified:Unset] "NSCA_Polyspace_Dem_OverlappingAssignment" */
            for(slotIdx = slotIdx; slotIdx < info_ptr->cntEnSlot; slotIdx++)
            {
                /* all rear slots shift forward to fill the removed slot */
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                info_ptr->enSlot[slotIdx] = info_ptr->enSlot[slotIdx + DEM_BYTE_ONE];
                info_ptr->entryIdx[slotIdx] = info_ptr->entryIdx[slotIdx + DEM_BYTE_ONE];
            }
            /* Initialize the last slot to 0 */
            info_ptr->enSlot[slotIdx] = DEM_INIT_ZERO;
            info_ptr->entryIdx[slotIdx] = DEM_INIT_ZERO;
            
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
            evtIdx = Dem_CfgEventIdTableIndex[entry_ptr[EntryIdx].evtId];
            entry_ptr[EntryIdx].evtId = DEM_INIT_ZERO;
            
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            DEM_SET_EVENT_STORED(evtIdx, EventMemIdx, FALSE);
            DEM_SET_EVENT_ENTRY(evtIdx, EventMemIdx, Dem_CfgEventMemoryTable[EventMemIdx].acEvtMemMaxEntry);
            
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
            dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
            for(combEvtCnt = DEM_INIT_ZERO; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
            {
                combEvtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[combEvtCnt];
                if(combEvtIdx > DEM_INIT_ZERO)
                {
                    DEM_SET_EVENT_STORED(combEvtIdx, EventMemIdx, FALSE);
                    DEM_SET_EVENT_ENTRY(combEvtIdx, EventMemIdx, Dem_CfgEventMemoryTable[EventMemIdx].acEvtMemMaxEntry);
                }
                else
                {
                    break;
                }
            }
#endif
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventFreezeFrameDataStore
*
* Explanation: Store freeze frame data
*
* param: uint16 EventIdx, index of event table
*        uint8 EventMemIdx, event memory index 
*        uint8 EntryIdx, entry index of this event in event memory
*
* retval: none
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventFreezeFrameDataStore
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx
)
{
    boolean updateFlag = FALSE;
    uint8 trigType;
    uint8 ffDataClsIdx, ffDataRecNumIdx, ffDataRecCnt, ffDataRecIdx;
    uint16 dtcIdx;
    uint8 *ffDatBuf_ptr;
    Dem_EventMemoryEntry_st *entry_ptr;
    
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM) &&
       (EntryIdx < Dem_CfgEventMemoryTable[EventMemIdx].acEvtMemMaxEntry))
    {
        /* Get primary event memory pointer */
        entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(EventMemIdx);
        ffDatBuf_ptr = &(entry_ptr[EntryIdx].datBuf.ffData[DEM_INIT_ZERO]);
        
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        ffDataClsIdx = Dem_CfgDtcFfDataClsIdx[dtcIdx];
        ffDataRecNumIdx = Dem_CfgDTCTable[dtcIdx].acFfDataRecClsIdx;

        for(ffDataRecCnt = DEM_INIT_ZERO; ffDataRecCnt < DEM_CFG_FFDATA_MAX_REF_RECORD_NUM; ffDataRecCnt++)
        {
            ffDataRecIdx = Dem_CfgFfDataRecordNumTable[ffDataRecNumIdx].acFfDataRecordIdx[ffDataRecCnt];
            if(ffDataRecIdx > DEM_INIT_ZERO)
            {
                trigType = Dem_CfgFfDataRecordTable[ffDataRecIdx].acFfDataRecTrig;
                if(E_OK == Dem_EventCheckDataUpdateTrigger(EventIdx, trigType))
                {
                    if((DEM_UPDATE_RECORD_YES == Dem_CfgFfDataRecordTable[ffDataRecIdx].acFfDataRecUpdate) ||
                       /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                       (FALSE == entry_ptr[EntryIdx].datBuf.stFfData[ffDataRecCnt]))
                    {
                        Dem_EventFreezeFrameDataUpdate(EventIdx, EventMemIdx, EntryIdx, ffDatBuf_ptr);
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                        entry_ptr[EntryIdx].datBuf.stFfData[ffDataRecCnt] = TRUE;
                        /* Remember which record is recently happened, this value should add 1, as 0 means nothing */
                        entry_ptr[EntryIdx].datBuf.ffRecIdx = ffDataRecCnt + DEM_BYTE_ONE;
                        updateFlag = TRUE;
                    }
                }
                ffDatBuf_ptr = (uint8 *)&ffDatBuf_ptr[Dem_CfgFfDataTable[ffDataClsIdx].acFfDataLen];
            }
            else
            {
                break;
            }
        }

        if(TRUE == updateFlag)
        {
            /* Trigger EventMemoryEntry block update */
            Dem_EventMemoryNvmBlkUpdateReq(EventMemIdx,
                                           EntryIdx,
                                           DEM_NVM_REQ_WRITE,
                                           DEM_IMMEDIATE_STORE_NVM(EventIdx));
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventExtendedDataStore
*
* Explanation: Store extended data
*
* param: uint16 EventIdx, index of event table
*        uint8 EventMemIdx, event memory index 
*        uint8 EntryIdx, entry index of this event in event memory
*
* retval: none
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventExtendedDataStore
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx
)
{
    boolean updateFlag = FALSE;
    uint8 trigType;
    uint8 exDataClsIdx, exDataRecCnt, exDataRecIdx;
    uint16 dtcIdx;
    uint8 *exDatBuf_ptr;
    Dem_EventMemoryEntry_st *entry_ptr;
    
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM) &&
       (EntryIdx < Dem_CfgEventMemoryTable[EventMemIdx].acEvtMemMaxEntry))
    {
        /* Get primary event memory pointer */
        entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(EventMemIdx);
        exDatBuf_ptr = &(entry_ptr[EntryIdx].datBuf.exData[DEM_INIT_ZERO]);

        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        exDataClsIdx = Dem_CfgDTCTable[dtcIdx].acExDataClsIdx;

        for(exDataRecCnt = DEM_INIT_ZERO; exDataRecCnt < DEM_CFG_EXDATA_MAX_REF_EXDATA_RECORD_NUM; exDataRecCnt++)
        {
            exDataRecIdx = Dem_CfgExDataTable[exDataClsIdx].acExDataRecordIdx[exDataRecCnt];
            if(exDataRecIdx > DEM_INIT_ZERO)
            {
                trigType = Dem_CfgExDataRecordTable[exDataRecIdx].acExDataRecTrig;
                if(E_OK == Dem_EventCheckDataUpdateTrigger(EventIdx, trigType))
                {
                    if((DEM_UPDATE_RECORD_YES == Dem_CfgExDataRecordTable[exDataRecIdx].acExDataRecUpdate) ||
                       /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                       (FALSE == entry_ptr[EntryIdx].datBuf.stExData[exDataRecCnt]))
                    {
                        Dem_EventExtendedDataRecordUpdate(EventIdx, EventMemIdx, EntryIdx, exDataRecIdx, exDatBuf_ptr);
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                        entry_ptr[EntryIdx].datBuf.stExData[exDataRecCnt] = TRUE;
                        updateFlag = TRUE;
                    }
                }
                exDatBuf_ptr = (uint8 *)&exDatBuf_ptr[Dem_CfgExDataRecordTable[exDataRecIdx].acExDataLen];
            }
            else
            {
                break;
            }
        }
        
        if(TRUE == updateFlag)
        {
            /* Trigger EventMemoryEntry block update */
            Dem_EventMemoryNvmBlkUpdateReq(EventMemIdx,
                                           EntryIdx,
                                           DEM_NVM_REQ_WRITE,
                                           DEM_IMMEDIATE_STORE_NVM(EventIdx));
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventFreezeFrameDataUpdate
*
* Explanation: Update event related freeze frame data.
*
* param: uint16 EventIdx, index of event table
*        uint8 EventMemIdx, event memory index 
*        uint8 *DestPtr, desination buffer pointer
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventFreezeFrameDataUpdate
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
)
{
    uint8 ffDidCnt, ffDataClsIdx, ffDidIdx, ffDidEleCnt;
    uint8 ffDidEleIdx;
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
    uint16 dataLen = DEM_INIT_ZERO;
    uint16 bufOffset = DEM_INIT_ZERO;
#endif
    
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (DestPtr != NULL_PTR))
    {
        ffDataClsIdx = Dem_CfgDtcFfDataClsIdx[Dem_CfgEvtDtcIdx[EventIdx]];

        for(ffDidCnt = DEM_INIT_ZERO; ffDidCnt < DEM_CFG_FFDATA_MAX_REF_DID_NUM; ffDidCnt++)
        {
            ffDidIdx = Dem_CfgFfDataTable[ffDataClsIdx].acFfDataDidIdx[ffDidCnt];
            if(DEM_INIT_ZERO != ffDidIdx)
            {
                for(ffDidEleCnt = DEM_INIT_ZERO; ffDidEleCnt < DEM_CFG_DID_MAX_REF_DATA_ELEMENT_NUM; ffDidEleCnt++)
                {
                    ffDidEleIdx = Dem_CfgDidTable[ffDidIdx].acDataElementIdx[ffDidEleCnt];
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:USELESS_IF [JUstified:Unset] "NSCA_Polyspace_Common_UselessIf" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                    if(DEM_INIT_ZERO != ffDidEleIdx)
                    {
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
                        if(((DEM_DATA_EMEMENT_TYPE_EXTERNALCS == Dem_CfgDataElementTable[ffDidEleIdx].acDataType) ||
                            (DEM_DATA_EMEMENT_TYPE_EXTERNALSR == Dem_CfgDataElementTable[ffDidEleIdx].acDataType)) &&
                           (TRUE == DEM_GET_SSDATA_FF_STORED(EventIdx)))
                        {
                            dataLen = Dem_CfgDataElementTable[ffDidEleIdx].acDataSize;
                            Dem_EventSyncFreezeFrameDataUpdate(EventIdx, bufOffset, dataLen, DestPtr);
                        }
                        else
                        {
                            Dem_EventDataElementAcqusition(EventIdx, EventMemIdx, EntryIdx, ffDidEleIdx, DestPtr);
                        }
                        bufOffset += Dem_CfgDataElementTable[ffDidEleIdx].acDataSize;
#else
                        Dem_EventDataElementAcqusition(EventIdx, EventMemIdx, EntryIdx, ffDidEleIdx, DestPtr);
#endif
                        /* PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                        DestPtr = (uint8 *)&DestPtr[Dem_CfgDataElementTable[ffDidEleIdx].acDataSize];
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventExtendedDataRecordUpdate
*
* Explanation: Update event related extended data.
*
* param: uint16 EventIdx, index of event table
*        uint8 EventMemIdx, event memory index 
*        uint8 exDataRecIdx, extended data record index
*        uint8 *DestPtr, desination buffer pointer
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventExtendedDataRecordUpdate
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx,
    uint8 exDataRecIdx, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
)
{
    uint8 exDataEleCnt, exDataEleIdx;
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
    uint16 dataLen = DEM_INIT_ZERO;
    uint16 bufOffset = DEM_INIT_ZERO;
#endif

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (exDataRecIdx <= DEM_CFG_EXDATA_RECORD_NUM) &&
       (DestPtr != NULL_PTR))
    {
        for(exDataEleCnt = DEM_INIT_ZERO; exDataEleCnt < DEM_CFG_EXDATA_MAX_REF_DATA_ELEMENT_NUM; exDataEleCnt++)
        {
            exDataEleIdx = Dem_CfgExDataRecordTable[exDataRecIdx].acExDataElementIdx[exDataEleCnt];
            if(DEM_INIT_ZERO != exDataEleIdx)
            {
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
                if(((Dem_CfgDataElementTable[exDataEleIdx].acDataType == DEM_DATA_EMEMENT_TYPE_EXTERNALCS) ||
                    (Dem_CfgDataElementTable[exDataEleIdx].acDataType == DEM_DATA_EMEMENT_TYPE_EXTERNALSR)) &&
                   (TRUE == DEM_GET_SSDATA_EX_STORED(EventIdx)))
                {
                    dataLen = Dem_CfgDataElementTable[exDataEleIdx].acDataSize;
                    Dem_EventSyncExtendedDataUpdate(EventIdx, bufOffset, dataLen, DestPtr);
                }
                else
                {
                    Dem_EventDataElementAcqusition(EventIdx, EventMemIdx, EntryIdx, exDataEleIdx, DestPtr);
                }
                bufOffset += Dem_CfgDataElementTable[exDataEleIdx].acDataSize;
#else
                Dem_EventDataElementAcqusition(EventIdx, EventMemIdx, EntryIdx, exDataEleIdx, DestPtr);
#endif
                /* PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                DestPtr = (uint8 *)&DestPtr[Dem_CfgDataElementTable[exDataEleIdx].acDataSize];
            }
            else
            {
                break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventDataElementAcqusition
*
* Explanation: Update event related extended data.
*
* param: uint16 EventIdx, index of event table
*        uint8 EventMemIdx, event memory index 
*        uint8 DataEleIdx, data element index
*        uint8 *DestPtr, desination buffer pointer
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventDataElementAcqusition
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx,
    uint8 DataEleIdx, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 dataLen, interDataKind, idx;
    
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM)&&
       (DataEleIdx <= DEM_CFG_DATA_ELEMENT_NUM) &&
       (DestPtr != NULL_PTR))
    {
        dataLen = Dem_CfgDataElementTable[DataEleIdx].acDataSize;
        
        switch(Dem_CfgDataElementTable[DataEleIdx].acDataType)
        {
            case DEM_DATA_EMEMENT_TYPE_INTERNAL:
            {
                interDataKind = Dem_CfgDataElementTable[DataEleIdx].acInterDataElement;
                if(E_NOT_OK == Dem_EventInternalDataElementAcqusition(EventIdx, EventMemIdx, EntryIdx, dataLen, interDataKind, DestPtr))
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    DestPtr[DEM_INIT_ZERO] = DEM_INIT_ZERO;
                }
                break;
            }
            case DEM_DATA_EMEMENT_TYPE_EXTERNALCS:
            {
                if(TRUE == Dem_CfgDataElementTable[DataEleIdx].acDataUsePort)
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    if(NULL_PTR != Dem_CfgDataElementTable[DataEleIdx].DataElementReadPortPtr)
                    {
                        if(E_NOT_OK == Dem_CfgDataElementTable[DataEleIdx].DataElementReadPortPtr(DestPtr))
                        {
                            for(idx = DEM_INIT_ZERO; idx < dataLen; idx++)
                            {
                                DestPtr[idx] = DEM_BYTE_MAX;
                            }
                        }
                        else
                        {
                            Dem_EventTriggerEventDataChangedCbk(EventIdx);
                        }
                    }
                }
                else
                {
                    if(NULL_PTR != Dem_CfgDataElementTable[DataEleIdx].DataElementReadFncPtr)
                    {
                        if(E_NOT_OK == Dem_CfgDataElementTable[DataEleIdx].DataElementReadFncPtr(DestPtr))
                        {
                            for(idx = DEM_INIT_ZERO; idx < dataLen; idx++)
                            {
                                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                                DestPtr[idx] = DEM_BYTE_MAX;
                            }
                        }
                        else
                        {
                            Dem_EventTriggerEventDataChangedCbk(EventIdx);
                        }
                    }
                }
                break;
            }
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            case DEM_DATA_EMEMENT_TYPE_EXTERNALSR:
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            default:
            {
                break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventInternalDataElementAcqusition
*
* Explanation: Get Dem internal data element.
*
* param: uint8 EventMemIdx, event memory index 
*        Dem_EventIdType EventId, the requested event id
*        uint8 EntryIdx, entry index
*        uint8 dataLen, data length
*        uint8 interDataKind, data kind
*        uint8 *dstPtr, desination buffer pointer
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_EventInternalDataElementAcqusition
(
    uint16 EventIdx, 
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */ 
    uint8 DataLen, 
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 InterDataKind,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
)
{
    Std_ReturnType retVal = E_NOT_OK;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    uint8 bufIdx = DEM_INIT_ZERO;
    Dem_EventMemoryEntry_st *entry_ptr;
    Dem_EventMemoryInfo_st *info_ptr;

    if( (EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM) &&
       (EntryIdx < Dem_CfgEventMemoryTable[EventMemIdx].acEvtMemMaxEntry) &&
#if( DEM_CFG_INTDATAEXSUPPORT == STD_OFF )
       (DEM_BYTE_ONE == DataLen) &&
#endif
       (DestPtr != NULL_PTR) )
    {
        /* Get event memory info pointer */
        info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(EventMemIdx);
        entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(EventMemIdx);

        switch(InterDataKind)
        {
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            case DEM_AGINGCTR_DOWNCNT:
            {
                break;
            }
            case DEM_AGINGCTR_UPCNT:
            {
                if(FALSE == Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acAgeAllow)
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    DestPtr[bufIdx] = DEM_INIT_ZERO;
                }
                else
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    DestPtr[bufIdx] = entry_ptr[EntryIdx].cntAge;
                }
                retVal = E_OK;
                break;
            }
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
            case DEM_AGINGCTR_UPCNT2:
            {
                if(FALSE == Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acAgeAllow)
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    DestPtr[bufIdx] = DEM_INIT_ZERO;
                }
                else
                {
                    if( DEM_BYTE_TWO != DataLen )
                    {
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                        DestPtr[bufIdx] = DEM_INIT_ZERO;
                    }
                    else
                    {
#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                        DestPtr[bufIdx + DEM_BYTE_ONE] = (uint8)((entry_ptr[EntryIdx].cntAge2 & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        DestPtr[bufIdx + DEM_BYTE_ZERO] = (uint8)(entry_ptr[EntryIdx].cntAge2 & (uint32)DEM_WORD_LOW_BYTE);
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
                        DestPtr[bufIdx + DEM_BYTE_ZERO] = (uint8)((entry_ptr[EntryIdx].cntAge2 & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        DestPtr[bufIdx + DEM_BYTE_ONE] = (uint8)(entry_ptr[EntryIdx].cntAge2 & (uint32)DEM_WORD_LOW_BYTE);
#else
                        DestPtr[bufIdx + DEM_BYTE_ZERO] = DEM_INIT_ZERO;
                        DestPtr[bufIdx + DEM_BYTE_ONE] = DEM_INIT_ZERO;
#endif
                    }
                }
                retVal = E_OK;
                break;
            }
#endif
            case DEM_CURRENT_FDC:
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                DestPtr[bufIdx] = (uint8)DEM_GET_FDCCNT(EventIdx);
                retVal = E_OK;
                break;
            }
            case DEM_CYCLES_SINCE_FIRST_FAILED:
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                DestPtr[bufIdx] = entry_ptr[EntryIdx].cntCsff;
                retVal = E_OK;
                break;
            }
            case DEM_CYCLES_SINCE_LAST_FAILED:
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                DestPtr[bufIdx] = entry_ptr[EntryIdx].cntCslf;
                retVal = E_OK;
                break;
            }
            case DEM_FAILED_CYCLES:
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                DestPtr[bufIdx] = entry_ptr[EntryIdx].cntFc;
                retVal = E_OK;
                break;
            }
            case DEM_MAX_FDC_DURING_CURRENT_CYCLE:
            {
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
                (void)Dem_EventGetCombMaxFDCDCC(EventIdx, (sint8*)(&DestPtr[bufIdx]));
#else
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                DestPtr[bufIdx] = (uint8)DEM_GET_FDCCNTMAX_DCC(EventIdx);
#endif
                retVal = E_OK;
                break;
            }
            case DEM_MAX_FDC_SINCE_LAST_CLEAR:
            {
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
                (void)Dem_EventGetCombMaxFDCSLC(EventIdx, (sint8*)(&DestPtr[bufIdx]));
#else
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                DestPtr[bufIdx] = (uint8)DEM_GET_FDCCNTMAX_SLC(EventIdx);
#endif
                retVal = E_OK;
                break;
            }
            case DEM_OCCCTR:
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                DestPtr[bufIdx] = entry_ptr[EntryIdx].cntOcc;
                retVal = E_OK;
                break;
            }
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
            case DEM_OCCCTR2:
            {
                if( DEM_BYTE_TWO != DataLen )
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    DestPtr[bufIdx] = DEM_INIT_ZERO;
                }
                else
                {
#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    DestPtr[bufIdx + DEM_BYTE_ONE] = (uint8)((entry_ptr[EntryIdx].cntOcc2 & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                    DestPtr[bufIdx + DEM_BYTE_ZERO] = (uint8)(entry_ptr[EntryIdx].cntOcc2 & (uint32)DEM_WORD_LOW_BYTE);
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
                    DestPtr[bufIdx + DEM_BYTE_ZERO] = (uint8)((entry_ptr[EntryIdx].cntOcc2 & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                    DestPtr[bufIdx + DEM_BYTE_ONE] = (uint8)(entry_ptr[EntryIdx].cntOcc2 & (uint32)DEM_WORD_LOW_BYTE);
#else
                    DestPtr[bufIdx + DEM_BYTE_ZERO] = DEM_INIT_ZERO;
                    DestPtr[bufIdx + DEM_BYTE_ONE] = DEM_INIT_ZERO;
#endif
                }
                retVal = E_OK;
                break;
            }
#endif
            case DEM_OVFLIND:
            {
                if(Dem_CfgEventMemoryTable[EventMemIdx].acEvtMemMaxEntry <= info_ptr->cntEnSlot)
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    DestPtr[bufIdx] = TRUE;
                }
                else
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    DestPtr[bufIdx] = FALSE;
                }
                retVal = E_OK;
                break;
            }
            case DEM_SIGNIFICANCE:
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                DestPtr[bufIdx] = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acDtcSign;
                retVal = E_OK;
                break;
            }
#if(DEM_CFG_AGEDCTRSUPPORT == STD_ON)
            case DEM_AGEDCTR:
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                DestPtr[bufIdx] = DEM_GET_AGED_CNT(EventIdx);
                retVal = E_OK;
                break;
            }
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
            case DEM_AGEDCTR2:
            {
                if( DEM_BYTE_TWO != DataLen )
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    DestPtr[bufIdx] = DEM_INIT_ZERO;
                }
                else
                {
#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    DestPtr[bufIdx + DEM_BYTE_ONE] = (uint8)((DEM_GET_AGED_CNT2(EventIdx) & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                    DestPtr[bufIdx + DEM_BYTE_ZERO] = (uint8)(DEM_GET_AGED_CNT2(EventIdx) & (uint32)DEM_WORD_LOW_BYTE);
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
                    DestPtr[bufIdx + DEM_BYTE_ZERO] = (uint8)((DEM_GET_AGED_CNT2(EventIdx) & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                    DestPtr[bufIdx + DEM_BYTE_ONE] = (uint8)(DEM_GET_AGED_CNT2(EventIdx) & (uint32)DEM_WORD_LOW_BYTE);
#else
                    DestPtr[bufIdx + DEM_BYTE_ZERO] = DEM_INIT_ZERO;
                    DestPtr[bufIdx + DEM_BYTE_ONE] = DEM_INIT_ZERO;
#endif
                }
                retVal = E_OK;
                break;
            }
#endif
#endif
            default:
            {
                retVal = Dem_EventExInternalDataElementAcqusition(EventIdx, EventMemIdx, EntryIdx, InterDataKind, DestPtr);
                break;
            }
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: Dem_EventExInternalDataElementAcqusition
*
* Explanation: Get user defined extend internal data element.
*
* param: uint16 EventIdx, event index 
*        uint8 interDataKind, data kind
*        uint8 *dstPtr, desination buffer pointer
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_EventExInternalDataElementAcqusition
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx, 
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 InterDataKind,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    Std_ReturnType retVal = E_NOT_OK;
    Dem_EventMemoryEntry_st *entry_ptr;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM) &&
       (EntryIdx < Dem_CfgEventMemoryTable[EventMemIdx].acEvtMemMaxEntry) &&
       (DestPtr != NULL_PTR))
    {
        entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(EventMemIdx);
#if((DEM_CFG_EXTENDSTATUSBYTE != DEM_INIT_ZERO) || (DEM_CFG_OCC1SUPPORT == STD_ON) || \
    (DEM_CFG_OCC2SUPPORT == STD_ON) || (DEM_CFG_OCC3SUPPORT == STD_ON) || \
    (DEM_CFG_OCC4SUPPORT == STD_ON) || (DEM_CFG_OCC5SUPPORT == STD_ON) || \
    (DEM_CFG_OCC6SUPPORT == STD_ON) || (DEM_CFG_OCC7SUPPORT == STD_ON))
        switch(InterDataKind)
        {
#if(DEM_CFG_EXTENDSTATUSBYTE != DEM_INIT_ZERO)
            case DEM_DTCSTATUSINDICATOR:
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                DestPtr[DEM_INIT_ZERO] = DEM_GET_STATUS_INDI(EventIdx);
                retVal = E_OK;
                break;
            }
#endif
#if(DEM_CFG_OCC1SUPPORT == STD_ON)
            case DEM_OCC1:
            {
                DestPtr[DEM_INIT_ZERO] = entry_ptr[EntryIdx].cntOCC1;
                retVal = E_OK;
                break;
            }
#endif
#if(DEM_CFG_OCC2SUPPORT == STD_ON)
            case DEM_OCC2:
            {
                DestPtr[DEM_INIT_ZERO] = entry_ptr[EntryIdx].cntOCC2;
                retVal = E_OK;
                break;
            }
#endif
#if(DEM_CFG_OCC3SUPPORT == STD_ON)
            case DEM_OCC3:
            {
                DestPtr[DEM_INIT_ZERO] = entry_ptr[EntryIdx].cntOCC3;
                retVal = E_OK;
                break;
            }
#endif
#if(DEM_CFG_OCC4SUPPORT == STD_ON)
            case DEM_OCC4:
            {
                DestPtr[DEM_INIT_ZERO] = entry_ptr[EntryIdx].cntOCC4;
                retVal = E_OK;
                break;
            }
#endif
#if(DEM_CFG_OCC5SUPPORT == STD_ON)
            case DEM_OCC5:
            {
                DestPtr[DEM_INIT_ZERO] = entry_ptr[EntryIdx].cntOCC5;
                retVal = E_OK;
                break;
            }
#endif
#if(DEM_CFG_OCC6SUPPORT == STD_ON)
            case DEM_OCC6:
            {
                DestPtr[DEM_INIT_ZERO] = entry_ptr[EntryIdx].cntOCC6;
                retVal = E_OK;
                break;
            }
#endif
#if(DEM_CFG_OCC7SUPPORT == STD_ON)
            case DEM_OCC7:
            {
                /* Get the OCC7 counter value. */
                DestPtr[DEM_INIT_ZERO] = entry_ptr[EntryIdx].cntOCC7;
                retVal = E_OK;
                break;
            }
#endif
            default:
            {
                break;
            }
        }
#else
        DEM_DUMMY_STATEMENT(InterDataKind);
#endif
        DEM_DUMMY_STATEMENT(entry_ptr);
    }

    return retVal;
}

#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
/*
********************************************************************************
* Function Name: Dem_EventSyncFreezeFrameDataStore
*SYNCHRONOUS
* Explanation: Store freeze frame data sync
*
* param: uint16 EventIdx, index of event index
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventSyncFreezeFrameDataStore
(
    uint16 EventIdx
)
{
    uint8 syncBufPos;
    uint8 ffDataClsIdx, ffDidCnt, ffDidIdx, ffDidEleCnt, ffDidEleIdx;
    uint8 *ffDatBuf_ptr;
    
    syncBufPos = DEM_GET_SSDATA_BUFFER_CNT();

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (syncBufPos < DEM_CFG_MAXNUMBEREVENTENTRYEVENTBUFFER))
    {
        ffDatBuf_ptr = DEM_GET_SSDATA_FFDATA_BUF_PTR(syncBufPos, DEM_INIT_ZERO);
        ffDataClsIdx = Dem_CfgDtcFfDataClsIdx[Dem_CfgEvtDtcIdx[EventIdx]];

        for(ffDidCnt = DEM_INIT_ZERO; ffDidCnt < DEM_CFG_FFDATA_MAX_REF_DID_NUM; ffDidCnt++)
        {
            ffDidIdx = Dem_CfgFfDataTable[ffDataClsIdx].acFfDataDidIdx[ffDidCnt];
            if(DEM_INIT_ZERO != ffDidIdx)
            {
                for(ffDidEleCnt = DEM_INIT_ZERO; ffDidEleCnt < DEM_CFG_DID_MAX_REF_DATA_ELEMENT_NUM; ffDidEleCnt++)
                {
                    ffDidEleIdx = Dem_CfgDidTable[ffDidIdx].acDataElementIdx[ffDidEleCnt];
                    if(ffDidEleIdx != DEM_INIT_ZERO)
                    {
                        if((Dem_CfgDataElementTable[ffDidEleIdx].acDataType == DEM_DATA_EMEMENT_TYPE_EXTERNALCS) ||
                           (Dem_CfgDataElementTable[ffDidEleIdx].acDataType == DEM_DATA_EMEMENT_TYPE_EXTERNALSR))
                        {
                            Dem_EventDataElementAcqusition(EventIdx, DEM_INIT_ZERO, DEM_INIT_ZERO, ffDidEleIdx, ffDatBuf_ptr);
                            DEM_SET_SSDATA_FF_STORED(EventIdx, TRUE);
                        }
                        
                        ffDatBuf_ptr = (uint8 *)&ffDatBuf_ptr[Dem_CfgDataElementTable[ffDidEleIdx].acDataSize];
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventSyncExtendedDataStore
*SYNCHRONOUS
* Explanation: Store extended data sync
*
* param: uint16 EventIdx, index of event index
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventSyncExtendedDataStore
(
    uint16 EventIdx
)
{
    uint8 syncBufPos;
    uint8 exDataClsIdx, exDataRecCnt, exDataRecIdx, exDataEleCnt, exDataEleIdx;
    uint8 *exDatBuf_ptr;
    
    syncBufPos = DEM_GET_SSDATA_BUFFER_CNT();

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (syncBufPos < DEM_CFG_MAXNUMBEREVENTENTRYEVENTBUFFER))
    {
        exDatBuf_ptr = DEM_GET_SSDATA_EXDATA_BUF_PTR(syncBufPos, DEM_INIT_ZERO);
        exDataClsIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acExDataClsIdx;

        for(exDataRecCnt = DEM_INIT_ZERO; exDataRecCnt < DEM_CFG_EXDATA_MAX_REF_EXDATA_RECORD_NUM; exDataRecCnt++)
        {
            exDataRecIdx = Dem_CfgExDataTable[exDataClsIdx].acExDataRecordIdx[exDataRecCnt];
            if(DEM_INIT_ZERO != exDataRecIdx)
            {
                for(exDataEleCnt = DEM_INIT_ZERO; exDataEleCnt < DEM_CFG_EXDATA_MAX_REF_DATA_ELEMENT_NUM; exDataEleCnt++)
                {
                    exDataEleIdx = Dem_CfgExDataRecordTable[exDataRecIdx].acExDataElementIdx[exDataEleCnt];
                    if(DEM_INIT_ZERO != exDataEleIdx)
                    {
                        if((Dem_CfgDataElementTable[exDataEleIdx].acDataType == DEM_DATA_EMEMENT_TYPE_EXTERNALCS) ||
                           (Dem_CfgDataElementTable[exDataEleIdx].acDataType == DEM_DATA_EMEMENT_TYPE_EXTERNALSR))
                        {
                            Dem_EventDataElementAcqusition(EventIdx, DEM_INIT_ZERO, DEM_INIT_ZERO, exDataEleIdx, exDatBuf_ptr);
                            DEM_SET_SSDATA_EX_STORED(EventIdx, TRUE);
                        }
                        
                        exDatBuf_ptr = (uint8 *)&exDatBuf_ptr[Dem_CfgDataElementTable[exDataEleIdx].acDataSize];
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventSyncSnapShotDataStore
*SYNCHRONOUS
* Explanation: Store snap shot data sync
*
* param: uint16 EventIdx, index of event index
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventSyncSnapShotDataStore
(
    uint16 EventIdx
)
{
    boolean dataStored = FALSE;
    uint8 syncBufPos;
    uint16 dtcIdx;
    
    syncBufPos = DEM_GET_SSDATA_BUFFER_CNT();

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        
        if((Dem_CfgDtcFfDataClsIdx[dtcIdx] > DEM_INIT_ZERO) &&
           (Dem_CfgDTCTable[dtcIdx].acFfDataRecClsIdx > DEM_INIT_ZERO))
        {
            Dem_EventSyncFreezeFrameDataStore(EventIdx);
            dataStored = TRUE;
        }

        if(Dem_CfgDTCTable[dtcIdx].acExDataClsIdx > DEM_INIT_ZERO)
        {
            Dem_EventSyncExtendedDataStore(EventIdx);
            dataStored = TRUE;
        }
        
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
        if(Dem_CfgDTCTable[dtcIdx].acObdDtcIdx > DEM_INIT_ZERO)
        {
            Dem_ObdSyncFreezeFreeDataStore(EventIdx);
            dataStored = TRUE;
        }

#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
        if((Dem_CfgDTCTable[dtcIdx].acWwhObdClass != DEM_DTC_WWHOBD_CLASS_NOCLASS) && 
           (Dem_CfgDTCTable[dtcIdx].acWobdFfDataClsIdx > DEM_INIT_ZERO))
        {
            Dem_ObdWwhSyncFreezeFrameDataStore(EventIdx);
            dataStored = TRUE;
        }
#endif

#endif
        if(TRUE == dataStored)
        {
            DEM_SET_SSDATA_BUFFER_POS(EventIdx, syncBufPos);
            syncBufPos++;
            DEM_SET_SSDATA_BUFFER_CNT(syncBufPos);
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventSyncFreezeFrameDataUpdate
*
* Explanation: Update sync freeze frame data
*
* param: uint16 EventIdx, index of event index
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventSyncFreezeFrameDataUpdate
(
    uint16 EventIdx, 
    uint16 BufOffset,
    uint16 DataLen,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
)
{
    uint8 pos;
    uint16 byteIdx;
    uint8 *srcPtr;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (DestPtr != NULL_PTR))
    {
        pos = DEM_GET_SSDATA_BUFFER_POS(EventIdx);
        srcPtr = DEM_GET_SSDATA_FFDATA_BUF_PTR(pos, BufOffset);

        for(byteIdx = DEM_INIT_ZERO; byteIdx < DataLen; byteIdx++)
        {
            DestPtr[byteIdx] = srcPtr[byteIdx];
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventSyncExtendedDataUpdate
*
* Explanation: Update sync exteneded data
*
* param: uint16 EventIdx, index of event index
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventSyncExtendedDataUpdate
(
    uint16 EventIdx, 
    uint16 BufOffset,
    uint16 DataLen,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
)
{
    uint8 pos;
    uint16 byteIdx;
    uint8 *srcPtr;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (DestPtr != NULL_PTR))
    {
        pos = DEM_GET_SSDATA_BUFFER_POS(EventIdx);
        srcPtr = DEM_GET_SSDATA_EXDATA_BUF_PTR(pos, BufOffset);

        for(byteIdx = DEM_INIT_ZERO; byteIdx < DataLen; byteIdx++)
        {
            DestPtr[byteIdx] = srcPtr[byteIdx];
        }
    }
}
#endif

#if(DEM_CFG_EVENTCOMBINATIONSUPPORT != DEM_EVCOMB_DISABLED)
/*
********************************************************************************
* Function Name: Dem_EventCombDisplace
*
* Explanation: Reset status byte of a combined DTC
*
* param: uint16 EventIdx, event index
*
* retval: void
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventCombStatusDisplace
(
    uint16 EventIdx
)
{
    uint16 dtcIdx, combEvtCnt, combEvtIdx;
    
    dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
    for(combEvtCnt = DEM_INIT_ZERO; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
    {
        combEvtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[combEvtCnt];
        if(combEvtIdx > DEM_INIT_ZERO)
        {
#if(DEM_CFG_RESETCONFIRMEDBITONOVERFLOW == STD_ON)
            /* Reset bit2 and bit3 */
            DEM_RESET_UDS_STATUS_PDTC(combEvtIdx);
            DEM_RESET_UDS_STATUS_CDTC(combEvtIdx);
#if(DEM_CFG_STATUSBITHANDLINGTESTFAILEDSINCELASTCLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
            DEM_RESET_UDS_STATUS_TFSLC(combEvtIdx);
#endif
#endif
        }
        else
        {
            break;
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventGetCombStatusByteByOld
*
* Explanation: Get status byte of a combined DTC
*
* param: EventIdx: event index
*        OldStatusByte: In Event old status byte. And out the combined old status byte. 
*
* retval: E_OK: Get status byte successful.
*         E_NOT_OK: Get status byte failed.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetCombStatusByteByOld
(
    uint16 EventIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OldStatusByte
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint16 dtcIdx, combEvtCnt, combEvtIdx;
    uint8 statusByte = DEM_INIT_ZERO;

    if( (EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
        (OldStatusByte != NULL_PTR) )
    {
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        
        for( combEvtCnt = DEM_INIT_ZERO; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++ )
        {
            combEvtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[combEvtCnt];
            if( combEvtIdx == EventIdx )
            {
                /* Continue. Do not Calculate. */
            }
            else if(combEvtIdx > DEM_INIT_ZERO)
            {
                statusByte |= DEM_GET_UDS_STATUS(combEvtIdx);
            }
            else
            {
                break;
            }
        }

        /* Calculate with the old Status Byte */
        statusByte |= *OldStatusByte;

        if( combEvtCnt > DEM_INIT_ZERO )
        {
            if( (statusByte & DEM_EVENT_DTC_STATUS_TFSLC) == DEM_EVENT_DTC_STATUS_TFSLC )
            {
                statusByte &= (~(uint8)DEM_EVENT_DTC_STATUS_TNCSLC);
            }

            if( (statusByte & DEM_EVENT_DTC_STATUS_TFTOC) == DEM_EVENT_DTC_STATUS_TFTOC )
            {
                statusByte &= (~(uint8)DEM_EVENT_DTC_STATUS_TNCTOC);
            }
        }

        *OldStatusByte = statusByte;

        ret = E_OK;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventGetCombStatusByte
*
* Explanation: Get status byte of a combined DTC
*
* param: uint16 EventIdx, event index
*
* retval: uint8, status byte
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetCombStatusByte
(
    uint16 EventIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) StatusByte
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint16 dtcIdx, combEvtCnt, combEvtIdx;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) && (StatusByte != NULL_PTR))
    {
        *StatusByte = DEM_GET_UDS_STATUS(EventIdx);
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        
        for(combEvtCnt = DEM_INIT_ZERO; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
        {
            combEvtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[combEvtCnt];
            if(combEvtIdx > DEM_INIT_ZERO)
            {
                *StatusByte |= DEM_GET_UDS_STATUS(combEvtIdx);
            }
            else
            {
                break;
            }
        }

        if(combEvtCnt > DEM_INIT_ZERO)
        {
            if((*StatusByte & DEM_EVENT_DTC_STATUS_TFSLC) == DEM_EVENT_DTC_STATUS_TFSLC)
            {
                *StatusByte &= (~(uint8)DEM_EVENT_DTC_STATUS_TNCSLC);
            }

            if((*StatusByte & DEM_EVENT_DTC_STATUS_TFTOC) == DEM_EVENT_DTC_STATUS_TFTOC)
            {
                *StatusByte &= (~(uint8)DEM_EVENT_DTC_STATUS_TNCTOC);
            }
        }
        
        ret = E_OK;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventGetCombFDC
*
* Explanation: Get FDC value of a combined DTC
*
* param: uint16 EventIdx, event index
*
* retval: uint8, status byte
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetCombFDC
(
    uint16 EventIdx,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FdcVal
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint16 dtcIdx, combEvtCnt, combEvtIdx;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) && (FdcVal != NULL_PTR))
    {
        *FdcVal = DEM_GET_FDCCNT(EventIdx);
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        
        for(combEvtCnt = DEM_INIT_ZERO; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
        {
            combEvtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[combEvtCnt];
            if(combEvtIdx > DEM_INIT_ZERO)
            {
                if(DEM_GET_FDCCNT(combEvtIdx) > *FdcVal)
                {
                    *FdcVal = DEM_GET_FDCCNT(combEvtIdx);
                }
            }
            else
            {
                break;
            }
        }
 
        ret = E_OK;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventGetCombMaxFDCDCC
*
* Explanation: Get Max_FDCDCC value of a combined DTC
*
* param: uint16 EventIdx, event index
*
* retval: uint8, status byte
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetCombMaxFDCDCC
(
    uint16 EventIdx,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FdcVal
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint16 dtcIdx, combEvtCnt, combEvtIdx;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) && (FdcVal != NULL_PTR))
    {
        *FdcVal = DEM_GET_FDCCNTMAX_DCC(EventIdx);
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        
        for(combEvtCnt = DEM_INIT_ZERO; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
        {
            combEvtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[combEvtCnt];
            if(combEvtIdx > DEM_INIT_ZERO)
            {
                if(DEM_GET_FDCCNTMAX_DCC(combEvtIdx) > *FdcVal)
                {
                    *FdcVal = DEM_GET_FDCCNTMAX_DCC(combEvtIdx);
                }
            }
            else
            {
                break;
            }
        }
 
        ret = E_OK;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventGetCombMaxFDCSLC
*
* Explanation: Get Max_FDCSLC value of a combined DTC
*
* param: uint16 EventIdx, event index
*
* retval: uint8, status byte
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetCombMaxFDCSLC
(
    uint16 EventIdx,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FdcVal
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint16 dtcIdx, combEvtCnt, combEvtIdx;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) && (FdcVal != NULL_PTR))
    {
        *FdcVal = DEM_GET_FDCCNTMAX_SLC(EventIdx);
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        
        for(combEvtCnt = DEM_INIT_ZERO; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
        {
            combEvtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[combEvtCnt];
            if(combEvtIdx > DEM_INIT_ZERO)
            {
                if(DEM_GET_FDCCNTMAX_SLC(combEvtIdx) > *FdcVal)
                {
                    *FdcVal = DEM_GET_FDCCNTMAX_SLC(combEvtIdx);
                }
            }
            else
            {
                break;
            }
        }
 
        ret = E_OK;
    }

    return ret;
}

#endif

/*
********************************************************************************
* Function Name: Dem_EventGetEnCondGrpStatus
*
* Explanation: Get event enable condition group status
*
* param: uint16 CondGrpIdx, condition group index
*
* retval: boolean
********************************************************************************
*/
FUNC(boolean, DEM_CODE) Dem_EventGetEnCondGrpStatus
(
    uint16 CondGrpIdx
)
{
    boolean condGrpSt = TRUE;
    uint8 breakFlag = FALSE;
    uint16 condCnt;
    uint16 condIdx;

    if((CondGrpIdx > DEM_INIT_ZERO) &&
       (CondGrpIdx <= DEM_CFG_ENCOND_GROUP_NUM))
    {
        for(condCnt = DEM_INIT_ZERO; condCnt < DEM_CFG_ENCONDGRP_MAX_REF_ENCOND_NUM; condCnt++)
        {
            condIdx = Dem_CfgEnConditionGrpTable[CondGrpIdx].acEnCondIdx[condCnt];
            /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
            if(condIdx > DEM_INIT_ZERO)
            {
                if(FALSE == DEM_GET_ENCOND(condIdx))
                {
                    condGrpSt = FALSE;
                    breakFlag = TRUE;
                }
            /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            }
            else
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                breakFlag = TRUE;
            }
            /* Unified break channel. */
            if(TRUE == breakFlag)
            {
                break;
            }
        }
    }

    return condGrpSt;
}

/*
********************************************************************************
* Function Name: Dem_EventGetStorCondGrpStatus
*
* Explanation: Get event storage condition group status
*
* param: uint16 CondGrpIdx, condition group index
*
* retval: boolean
********************************************************************************
*/
FUNC(boolean, DEM_CODE) Dem_EventGetStorCondGrpStatus
(
    uint16 CondGrpIdx
)
{
    boolean condGrpSt = TRUE;
    uint8 breakFlag = FALSE;
    uint16 condCnt;
    uint16 condIdx;

    if((CondGrpIdx > DEM_INIT_ZERO) &&
       (CondGrpIdx <= DEM_CFG_STORCOND_GROUP_NUM))
    {
        for(condCnt = DEM_INIT_ZERO; condCnt < DEM_CFG_STORCONDGRP_MAX_REF_STORCOND_NUM; condCnt++)
        {
            condIdx = Dem_CfgStorConditionGrpTable[CondGrpIdx].acStorCondIdx[condCnt];
            /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
            if(condIdx > DEM_INIT_ZERO)
            {
                if(FALSE == DEM_GET_STORCOND(condIdx))
                {
                    condGrpSt = FALSE;
                    breakFlag = TRUE;
                }
            /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            }
            else
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                breakFlag = TRUE;
            }
            /* Unified break channel. */
            if(TRUE == breakFlag)
            {
                break;
            }
        }
    }

    return condGrpSt;
}

/*
********************************************************************************
* Function Name: Dem_EventGetFFRecordDidData
*
* Explanation: Get requested freeze frame record data 
*
* param: uint16 EventIdx, event index
*        uint8 RecordNumber, event related record number
*        uint16 DataId, event related data ID
*        uint8 *DestBuffer, buffer to receive the data
*        uint16 *BufSize, buffer size in bytes
*
* retval: E_OK, get data successfully; others, failed
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetFFRecordDidData
(
    uint16 EventIdx,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint8 RecordNumber,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint16 DataId,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean recordNumValid = FALSE;
    uint8 breakFlag = FALSE;
    uint8 ffRecNumIdx;
    uint8 ffRecCnt;
    uint8 ffRecIdx;
    uint8 recordNumIdx = DEM_INIT_ZERO;
    uint8 evtMemCnt;
    uint8 evtMemIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 entryIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 ffDataIdx;
    uint16 dtcIdx;
    uint16 srcPtrOfs;
    uint16 destPtrOfs;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dataLen;
    uint8 *srcPtr;
    uint8 *destPtr;
    Dem_EventMemoryEntry_st *entry_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (DestBuffer != NULL_PTR) && (BufSize != NULL_PTR))
    {
        destPtr = &DestBuffer[DEM_INIT_ZERO];
        dataLen = *BufSize;
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        ffDataIdx = Dem_CfgDtcFfDataClsIdx[dtcIdx];
        ffRecNumIdx = Dem_CfgDTCTable[dtcIdx].acFfDataRecClsIdx;
        
        for(ffRecCnt = DEM_INIT_ZERO; ffRecCnt < DEM_CFG_FFDATA_MAX_REF_RECORD_NUM; ffRecCnt++)
        {
            ffRecIdx = Dem_CfgFfDataRecordNumTable[ffRecNumIdx].acFfDataRecordIdx[ffRecCnt];
            if(RecordNumber == Dem_CfgFfDataRecordTable[ffRecIdx].acFfDataRecordNum)
            {
                recordNumValid = TRUE;
                recordNumIdx = ffRecCnt;
                break;
            }
        }

        if(TRUE == recordNumValid)
        {
            destPtrOfs = DEM_INIT_ZERO;
            /* Read out data in every event memory */
            for(evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++)
            {
                evtMemIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acEvtMemIdx[evtMemCnt];

                if(evtMemIdx > DEM_INIT_ZERO)
                {
                    entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);
                    entryIdx = DEM_GET_EVENT_ENTRY(EventIdx, evtMemIdx);

                    if((TRUE == DEM_GET_EVENT_STORED(EventIdx, evtMemIdx)) &&
                       /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                       (TRUE == entry_ptr[entryIdx].datBuf.stFfData[recordNumIdx]))
                    {                        
                        srcPtrOfs = ((uint16)recordNumIdx * Dem_CfgFfDataTable[ffDataIdx].acFfDataLen);
                        srcPtr = &(entry_ptr[entryIdx].datBuf.ffData[srcPtrOfs]);
                        
                        ret = Dem_EventGetFFDataByDid(ffDataIdx, DataId, srcPtr, destPtr, &dataLen);
                        if(E_OK == ret)
                        {
                            destPtrOfs += dataLen;
                            if(*BufSize > destPtrOfs)
                            {
                                dataLen = *BufSize - destPtrOfs;
                                destPtr = &DestBuffer[destPtrOfs];
                            }
                            else
                            {
                                dataLen = DEM_INIT_ZERO;
                            }
                        }
                        else
                        {
                            breakFlag = TRUE;
                        }
                    }
                    else
                    {
                        ret = DEM_E_NODATAAVAILABLE;
                    }
                }
                else
                {
                    ret = DEM_E_NODATAAVAILABLE;
                    breakFlag = TRUE;
                }
                /* Unified break channel. */
                if(TRUE == breakFlag)
                {
                    break;
                }
            }

            if(E_OK == ret)
            {
                *BufSize = destPtrOfs;
            }
        }
        else
        {
            ret = DEM_E_WRONG_RECORDNUMBER;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventGetFFRecentlyRecordDidData
*
* Explanation: Get Recently freeze frame record data 
*
* param: uint16 EventIdx, event index
*        uint16 DataId, event related data ID
*        uint8 *DestBuffer, buffer to receive the data
*        uint16 *BufSize, buffer size in bytes
*
* retval: E_OK, get data successfully; others, failed
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetFFRecentlyRecordDidData
(
    uint16 EventIdx,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint16 DataId,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 breakFlag = FALSE;
    uint8 recordNumIdx;
    uint8 evtMemCnt;
    uint8 evtMemIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 entryIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 ffDataIdx;
    uint16 dtcIdx;
    uint16 srcPtrOfs;
    uint16 destPtrOfs;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dataLen;
    uint8 *srcPtr;
    uint8 *destPtr;
    Dem_EventMemoryEntry_st *entry_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (DestBuffer != NULL_PTR) && (BufSize != NULL_PTR))
    {
        destPtr = &DestBuffer[DEM_INIT_ZERO];
        dataLen = *BufSize;
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        ffDataIdx = Dem_CfgDtcFfDataClsIdx[dtcIdx];

        destPtrOfs = DEM_INIT_ZERO;
        /* Read out data in every event memory */
        for(evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++)
        {
            evtMemIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acEvtMemIdx[evtMemCnt];

            if(evtMemIdx > DEM_INIT_ZERO)
            {
                entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);
                entryIdx = DEM_GET_EVENT_ENTRY(EventIdx, evtMemIdx);

                if((TRUE == DEM_GET_EVENT_STORED(EventIdx, evtMemIdx)) &&
                   /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                   (entry_ptr[entryIdx].datBuf.ffRecIdx > DEM_INIT_ZERO))
                {
                    recordNumIdx = entry_ptr[entryIdx].datBuf.ffRecIdx - DEM_BYTE_ONE;
                    srcPtrOfs = ((uint16)recordNumIdx * Dem_CfgFfDataTable[ffDataIdx].acFfDataLen);
                    srcPtr = &(entry_ptr[entryIdx].datBuf.ffData[srcPtrOfs]);
                    
                    ret = Dem_EventGetFFDataByDid(ffDataIdx, DataId, srcPtr, destPtr, &dataLen);
                    if(E_OK == ret)
                    {
                        destPtrOfs += dataLen;
                        if(*BufSize > destPtrOfs)
                        {
                            dataLen = *BufSize - destPtrOfs;
                            destPtr = &DestBuffer[destPtrOfs];
                        }
                        else
                        {
                            dataLen = DEM_INIT_ZERO;
                        }
                    }
                    else
                    {
                        breakFlag = TRUE;
                    }
                }
                else
                {
                    ret = DEM_E_NODATAAVAILABLE;
                }
            }
            else
            {
                ret = DEM_E_NODATAAVAILABLE;
                breakFlag = TRUE;
            }
            /* Unified break channel. */
            if(TRUE == breakFlag)
            {
                break;
            }
        }

        if(E_OK == ret)
        {
            *BufSize = destPtrOfs;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventGetFFDataByDid
*
* Explanation: Get DID data of requested freeze frame data 
*
* param: uint8 FfDataIdx, freeze frame data class index
*        uint16 DataId, event related data ID
*        const uint8 *SrcPtr, buffer to transmit the data
*        uint8 *DestPtr, buffer to receive the data
*        uint16 *BufSize, buffer size in bytes
*
* retval: E_OK, get data successfully; others, failed
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetFFDataByDid
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 FfDataIdx,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint16 DataId,
    P2CONST(uint8, AUTOMATIC, DEM_APPL_DATA) SrcPtr,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType ret = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 DidCnt, DidIdx;
    uint16 byteIdx;
    uint16 bufOffset = DEM_INIT_ZERO;
    
    if((FfDataIdx > DEM_INIT_ZERO) && 
       (FfDataIdx <= DEM_CFG_FFDATA_NUM) &&
       (SrcPtr != NULL_PTR) &&
       (DestPtr != NULL_PTR) &&
       (BufSize != NULL_PTR))
    {
        for(DidCnt = DEM_INIT_ZERO; DidCnt < DEM_CFG_FFDATA_MAX_REF_DID_NUM; DidCnt++)
        {
            DidIdx = Dem_CfgFfDataTable[FfDataIdx].acFfDataDidIdx[DidCnt];
            if(DataId == Dem_CfgDidTable[DidIdx].acDid)
            {
                if(*BufSize >= Dem_CfgDidTable[DidIdx].acDataLen)
                {
                    for(byteIdx = DEM_INIT_ZERO; byteIdx < Dem_CfgDidTable[DidIdx].acDataLen; byteIdx++)
                    {
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                        DestPtr[byteIdx] = SrcPtr[bufOffset];
                        bufOffset++;
                    }
                    *BufSize = Dem_CfgDidTable[DidIdx].acDataLen;
                    ret = E_OK;
                }
                else
                {
                    ret = DEM_E_WRONG_BUFFERSIZE;
                }
                break;
            }
            else
            {
                bufOffset += Dem_CfgDidTable[DidIdx].acDataLen;
            }
        }

        if(DidCnt >= DEM_CFG_FFDATA_MAX_REF_DID_NUM)
        {
            ret = DEM_E_WRONG_DIDNUMBER;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventGetExRecordData
*
* Explanation: Get requested extended data record data 
*
* param: uint16 EventIdx, event index
*        uint8 RecordNumber, event related record number
*        uint8 *DestBuffer, buffer to receive the data
*        uint16 *BufSize, buffer size in bytes
*
* retval: E_OK, get data successfully; others, failed
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetExRecordData
(
    uint16 EventIdx,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint8 RecordNumber,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean recordNumValid = FALSE;
    uint8 breakFlag = FALSE;
    uint8 evtMemCnt;
    uint8 evtMemIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 entryIdx;
    uint8 exDataIdx;
    uint8 exRecCnt;
    uint8 exRecIdx;
    uint16 exDataLen = DEM_INIT_ZERO;
    uint16 byteIdx;
    uint16 destPtrOfs;
    uint16 srcPtrOfs;
    uint8 *srcPtr;
    uint8 *destPtr;
    Dem_EventMemoryEntry_st *entry_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (DestBuffer != NULL_PTR) && (BufSize != NULL_PTR))
    {
        destPtrOfs = DEM_INIT_ZERO;
        srcPtrOfs = DEM_INIT_ZERO;
        exDataIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acExDataClsIdx;
        
        for(exRecCnt = DEM_INIT_ZERO; exRecCnt < DEM_CFG_EXDATA_MAX_REF_EXDATA_RECORD_NUM; exRecCnt++)
        {
            exRecIdx = Dem_CfgExDataTable[exDataIdx].acExDataRecordIdx[exRecCnt];
            if(RecordNumber == Dem_CfgExDataRecordTable[exRecIdx].acExDataRecNum)
            {
                exDataLen = Dem_CfgExDataRecordTable[exRecIdx].acExDataLen;
                recordNumValid = TRUE;
                break;
            }
            else
            {
                srcPtrOfs += Dem_CfgExDataRecordTable[exRecIdx].acExDataLen;
            }
        }
        
        if(TRUE == recordNumValid)
        {
            /* Read out data in every event memory */
            for(evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++)
            {
                evtMemIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acEvtMemIdx[evtMemCnt];

                if(evtMemIdx > DEM_INIT_ZERO)
                {
                    entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);
                    entryIdx = DEM_GET_EVENT_ENTRY(EventIdx, evtMemIdx);

                    if((TRUE == DEM_GET_EVENT_STORED(EventIdx, evtMemIdx)) &&
                       /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                       (TRUE == entry_ptr[entryIdx].datBuf.stExData[exRecCnt]))
                    {
                        srcPtr = &(entry_ptr[entryIdx].datBuf.exData[srcPtrOfs]);
                        if((*BufSize - destPtrOfs) >= exDataLen)
                        {
                            destPtr = &DestBuffer[destPtrOfs];
                            for(byteIdx = DEM_INIT_ZERO; byteIdx < exDataLen; byteIdx++)
                            {
                                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                                destPtr[byteIdx] = srcPtr[byteIdx];
                            }
                            destPtrOfs += exDataLen;
                            ret = E_OK;
                        }
                        else
                        {
                            ret = DEM_E_WRONG_BUFFERSIZE;
                            breakFlag = TRUE;
                        }
                    }
                    else
                    {
                        ret = DEM_E_NODATAAVAILABLE;
                    }
                }
                else
                {
                    ret = DEM_E_NODATAAVAILABLE;
                    breakFlag = TRUE;
                }
                /* Unified break channel. */
                if(TRUE == breakFlag)
                {
                    break;
                }
            }

            if(E_OK == ret)
            {
                *BufSize = destPtrOfs;
            }
        }
        else
        {
            ret = DEM_E_WRONG_RECORDNUMBER;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventGetDTCByOccurrenceTime
*
* Explanation: Get DTC by occurrence time
*
* param: Dem_DTCRequestType DTCRequest, the occurrence time type
*        uint32 *DTC, to hold the matched DTC
*
* retval: Dem_ReturnGetNextFilteredElementType 
********************************************************************************
*/
FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE) Dem_EventGetDTCByOccurrenceTime
(
    Dem_DTCRequestType DTCRequest,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC
)
{
    Dem_ReturnGetDTCByOccurrenceTimeType ret = DEM_OCCURR_OK;
    uint16 evtIdx, dtcIdx;
    Dem_EventMemoryInfo_st *info_ptr;
    
    info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(DEM_EVENT_MEMORY_PRIMARY);

    switch(DTCRequest)
    {
        case DEM_FIRST_FAILED_DTC:
        {
            if(info_ptr->firstFaliedEvtId != DEM_INIT_ZERO)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                evtIdx = Dem_CfgEventIdTableIndex[info_ptr->firstFaliedEvtId];
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
                {
                    *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                }
                else
                {
                    ret = DEM_OCCURR_NOT_AVAILABLE;
                }
#else
                *DTC = DEM_DTCVALUE_CAL(dtcIdx);
#endif
            }
            else
            {
                ret = DEM_OCCURR_NOT_AVAILABLE;
            }
            break;
        }
        case DEM_MOST_RECENT_FAILED_DTC:

        {
            if(info_ptr->recentlyFaliedEvtId != DEM_INIT_ZERO)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                evtIdx = Dem_CfgEventIdTableIndex[info_ptr->recentlyFaliedEvtId];
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
                {
                    *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                }
                else
                {
                    ret = DEM_OCCURR_NOT_AVAILABLE;
                }
#else
                *DTC = DEM_DTCVALUE_CAL(dtcIdx);
#endif
            }
            else
            {
                ret = DEM_OCCURR_NOT_AVAILABLE;
            }
            break;
        }
        case DEM_FIRST_DET_CONFIRMED_DTC:

        {
            if(info_ptr->firstConfirmEvtId != DEM_INIT_ZERO)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                evtIdx = Dem_CfgEventIdTableIndex[info_ptr->firstConfirmEvtId];
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
                {
                    *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                }
                else
                {
                    ret = DEM_OCCURR_NOT_AVAILABLE;
                }
#else
                *DTC = DEM_DTCVALUE_CAL(dtcIdx);
#endif

            }
            else
            {
                ret = DEM_OCCURR_NOT_AVAILABLE;
            }
            break;
        }
        case DEM_MOST_REC_DET_CONFIRMED_DTC:

        {
            if(info_ptr->recentlyConfirmEvtId != DEM_INIT_ZERO)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                evtIdx = Dem_CfgEventIdTableIndex[info_ptr->recentlyConfirmEvtId];
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
                {
                    *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                }
                else
                {
                    ret = DEM_OCCURR_NOT_AVAILABLE;
                }
#else
                *DTC = DEM_DTCVALUE_CAL(dtcIdx);
#endif

            }
            else
            {
                ret = DEM_OCCURR_NOT_AVAILABLE;
            }
            break;
        }
        default:
        {
            ret = DEM_OCCURR_NOT_AVAILABLE;
            break;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_DTCGetFFRecordData
*
* Explanation: Get freeze frame record data 
*
* param: uint16 DtcIdx, DTC index
*        uint8 evtMemIdx, event memory index
*        uint8 RecordNumber, event related record number
*        uint8 *DestBuffer, buffer to receive the data
*        uint16 *BufSize, buffer size in bytes
*
* retval: E_OK, get data successfully; others, failed
********************************************************************************
*/
FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE) Dem_DTCGetFFRecordData
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DtcIdx,
    uint8 evtMemIdx,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint8 RecordNumber,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Dem_ReturnGetFreezeFrameDataByDTCType ret = DEM_GET_FFDATABYDTC_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
	//多组冻结帧
    uint8 ffDataIdx, ffRecNumIdx, ffRecCnt, ffRecIdx, ffDidCnt, ffDidCnt_ALL,ffDidNum,ffDidNum_ALL,DIDmatch;
    uint8 ffDidIdx=0;
   uint8 ffDidIdx_all=0;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 entryIdx;
    uint16 recDataLen;
    uint16 byteIdx, bufIdx;
    uint16 bufOffset = DEM_INIT_ZERO;
    uint16 bufOffset_data = DEM_INIT_ZERO;//多组冻结帧
    uint16 combEvtCnt, combEvtIdx;
    Dem_EventMemoryEntry_st *entry_ptr;
    
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((DtcIdx <= DEM_CFG_DTC_NUM) && (DestBuffer != NULL_PTR) && (BufSize != NULL_PTR))
    {
        /* Check RecordNumber */
        ffRecNumIdx = Dem_CfgDTCTable[DtcIdx].acFfDataRecClsIdx;
        ffRecIdx = DEM_INIT_ZERO;
        for(ffRecCnt = DEM_INIT_ZERO; ffRecCnt < DEM_CFG_FFDATA_MAX_REF_RECORD_NUM; ffRecCnt++)
        {
            ffRecIdx = Dem_CfgFfDataRecordNumTable[ffRecNumIdx].acFfDataRecordIdx[ffRecCnt];
            if(Dem_CfgFfDataRecordTable[ffRecIdx].acFfDataRecordNum == RecordNumber)
            {
                break;
            }
        }

        if((ffRecCnt < DEM_CFG_FFDATA_MAX_REF_RECORD_NUM) && (ffRecIdx > DEM_INIT_ZERO))
        {
            for(combEvtCnt = Dem_GetFFRecDataCombEvtNext; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
            {
                combEvtIdx = Dem_CfgDTCTable[DtcIdx].combEvtIdx[combEvtCnt];
                if((combEvtIdx > DEM_INIT_ZERO) && 
                   /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                   (TRUE == DEM_GET_EVENT_STORED(combEvtIdx, evtMemIdx)) &&
                   (DEM_GET_EVENT_ENTRY(combEvtIdx, evtMemIdx) < Dem_CfgEventMemoryTable[evtMemIdx].acEvtMemMaxEntry))
                {
                    entryIdx = DEM_GET_EVENT_ENTRY(combEvtIdx, evtMemIdx);
                    entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);
                    ffDataIdx = Dem_CfgDtcFfDataClsIdx[DtcIdx];
                    ffDidNum = DEM_INIT_ZERO;
                    for(ffDidCnt = DEM_INIT_ZERO; ffDidCnt < DEM_CFG_FFDATA_MAX_REF_DID_NUM;ffDidCnt++)
                    {
                        if(DEM_INIT_ZERO == Dem_CfgFfDataTable[ffDataIdx].acFfDataDidIdx[ffDidCnt])
                        {
                            break;
                        }
                        else
                        {
							//多组冻结帧
                            if(DEM_INIT_ZERO != Dem_CfgFfDataTable[RecordNumber].acFfDataDidIdx[ffDidCnt])
                            {
                                ffDidNum++;
                            }
                            ffDidNum_ALL++;
                        }

                    }
					//多组冻结帧
                    // recDataLen = (uint16)Dem_CfgFfDataTable[ffDataIdx].acFfDataLen + DEM_BYTE_TWO + (uint16)((uint16)ffDidNum * DEM_BYTE_TWO);
                    recDataLen = (uint16)Dem_CfgFfDataTable[RecordNumber].acFfDataLen + DEM_BYTE_TWO + (uint16)((uint16)ffDidNum * DEM_BYTE_TWO);
                    /* Check freeze frame data stored */
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    if(TRUE == entry_ptr[entryIdx].datBuf.stFfData[ffRecCnt])
                    {
                        /* Check buffer size */
                        if(*BufSize >= (Dem_GetFFRecDataSize + recDataLen))
                        {
                            bufOffset = (uint16)((uint16)ffRecCnt * (uint16)Dem_CfgFfDataTable[ffDataIdx].acFfDataLen);
                            /* Copy data */
                            bufIdx = Dem_GetFFRecDataSize;
                            DestBuffer[bufIdx] = RecordNumber;
                            bufIdx++;
                            DestBuffer[bufIdx] = ffDidNum;
                            bufIdx++;
                            for(ffDidCnt = DEM_INIT_ZERO; ffDidCnt < ffDidNum; ffDidCnt++)
                            {
								//多组冻结帧
                                bufOffset_data=bufOffset;
                                ffDidIdx = Dem_CfgFfDataTable[RecordNumber].acFfDataDidIdx[ffDidCnt];
                                for(ffDidCnt_ALL = DEM_INIT_ZERO; ffDidCnt_ALL < ffDidNum_ALL; ffDidCnt_ALL++)
                                {
                                    ffDidIdx_all =Dem_CfgFfDataTable[ffDataIdx].acFfDataDidIdx[ffDidCnt_ALL];
                                   if(ffDidIdx==ffDidIdx_all)
                                    {
                                        ffDidIdx = Dem_CfgFfDataTable[RecordNumber].acFfDataDidIdx[ffDidCnt];
                                        DestBuffer[bufIdx] = (uint8)((Dem_CfgDidTable[ffDidIdx].acDid & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                                        bufIdx++;
                                        DestBuffer[bufIdx] = (uint8)(Dem_CfgDidTable[ffDidIdx].acDid & (uint16)DEM_WORD_LOW_BYTE);
                                        bufIdx++;
                                        for(byteIdx = DEM_INIT_ZERO; byteIdx < Dem_CfgDidTable[ffDidIdx].acDataLen; byteIdx++)
                                        {
                                            DestBuffer[bufIdx + byteIdx] = entry_ptr[entryIdx].datBuf.ffData[bufOffset_data];
                                            bufOffset_data++;
                                        }
                                        bufIdx += Dem_CfgDidTable[ffDidIdx].acDataLen;
                                        break;
                                    }
                                    else
                                    {
                                        bufOffset_data +=Dem_CfgDidTable[ffDidIdx_all].acDataLen;  
                                    }
                                }                          
                            }
                            Dem_GetFFRecDataSize += recDataLen;
                        }
                        else
                        {
                            ret = DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE;
                            /* In this case, do not change the value of *BufSize */
                            Dem_GetFFRecDataSize = *BufSize;
                        }
                    }
                    break;
                }
            }
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONRETRIEVAL)
            combEvtCnt++;
            if((combEvtCnt >= DEM_CFG_COMB_DTC_MAX_EVENT_NUM) || (ret != DEM_GET_FFDATABYDTC_OK))
            {
                *BufSize = Dem_GetFFRecDataSize;
                Dem_GetFFRecDataCombEvtNext = DEM_INIT_ZERO;
                Dem_GetFFRecDataSize = DEM_INIT_ZERO;
            }
            else
            {
                if(Dem_CfgDTCTable[DtcIdx].combEvtIdx[combEvtCnt] > DEM_INIT_ZERO)
                {
                    Dem_GetFFRecDataCombEvtNext = combEvtCnt;
                    ret = DEM_GET_FFDATABYDTC_PENDING;
                }
                else
                {
                    *BufSize = Dem_GetFFRecDataSize;
                    Dem_GetFFRecDataCombEvtNext = DEM_INIT_ZERO;
                    Dem_GetFFRecDataSize = DEM_INIT_ZERO;
                }
            }
#else
            *BufSize = Dem_GetFFRecDataSize;
            Dem_GetFFRecDataSize = DEM_INIT_ZERO;
#endif

        }
        else
        {
            ret = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_DTCGetFFRecordSize
*
* Explanation: Get freeze frame record data size
*
* param: uint16 DtcIdx, DTC index
*        uint8 evtMemIdx, event memory index
*        uint8 RecordNumber, event related record number
*        uint16 *SizeOfFreezeFrame, data size in bytes
*
* retval: E_OK, get data successfully; others, failed
********************************************************************************
*/
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DTCGetFFRecordSize
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DtcIdx,
    uint8 evtMemIdx,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint8 RecordNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
)
{
    Dem_ReturnGetSizeOfDataByDTCType ret = DEM_GETSIZEBYDTC_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 ffDataIdx, ffRecNumIdx, ffRecCnt, ffRecIdx, ffDidCnt, ffDidNum;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 entryIdx;
    uint16 combEvtCnt, combEvtIdx;
    Dem_EventMemoryEntry_st *entry_ptr;
    
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if(SizeOfFreezeFrame != NULL_PTR)
    {
        /* Check RecordNumber */
        ffRecNumIdx = Dem_CfgDTCTable[DtcIdx].acFfDataRecClsIdx;
        ffRecIdx = DEM_INIT_ZERO;
        for(ffRecCnt = DEM_INIT_ZERO; ffRecCnt < DEM_CFG_FFDATA_MAX_REF_RECORD_NUM; ffRecCnt++)
        {
            ffRecIdx = Dem_CfgFfDataRecordNumTable[ffRecNumIdx].acFfDataRecordIdx[ffRecCnt];
            if(Dem_CfgFfDataRecordTable[ffRecIdx].acFfDataRecordNum == RecordNumber)
            {
                break;
            }
        }

        if((ffRecCnt < DEM_CFG_FFDATA_MAX_REF_RECORD_NUM) && (ffRecIdx > DEM_INIT_ZERO))
        {
            for(combEvtCnt = Dem_GetFFRecSizeCombEvtNext; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
            {
                combEvtIdx = Dem_CfgDTCTable[DtcIdx].combEvtIdx[combEvtCnt];
                if((combEvtIdx > DEM_INIT_ZERO) && 
                   /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                   (TRUE == DEM_GET_EVENT_STORED(combEvtIdx, evtMemIdx)) &&
                   (DEM_GET_EVENT_ENTRY(combEvtIdx, evtMemIdx) < Dem_CfgEventMemoryTable[evtMemIdx].acEvtMemMaxEntry))
                {
                    entryIdx = DEM_GET_EVENT_ENTRY(combEvtIdx, evtMemIdx);
                    entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);
                    /* Check freeze frame data stored */
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    if(TRUE == entry_ptr[entryIdx].datBuf.stFfData[ffRecCnt])
                    {
                        /* Get data size */
						//多组冻结帧
                        // ffDataIdx = Dem_CfgDtcFfDataClsIdx[DtcIdx];//这个DTC支持的DID组号
                        ffDataIdx = RecordNumber;//
                        ffDidNum = DEM_INIT_ZERO;
                        for(ffDidCnt = DEM_INIT_ZERO; ffDidCnt < DEM_CFG_FFDATA_MAX_REF_DID_NUM;ffDidCnt++)
                        {
                            if(DEM_INIT_ZERO == Dem_CfgFfDataTable[ffDataIdx].acFfDataDidIdx[ffDidCnt])
                            {
                                break;
                            }
                            else
                            {
                                ffDidNum++;
                            }
                        }
                        
                        Dem_GetFFRecSize += (uint16)Dem_CfgFfDataTable[ffDataIdx].acFfDataLen + DEM_BYTE_TWO + (uint16)((uint16)ffDidNum * DEM_BYTE_TWO);
                    }
                    break;
                }
            }

#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONRETRIEVAL)
            combEvtCnt++;
            if(combEvtCnt >= DEM_CFG_COMB_DTC_MAX_EVENT_NUM)
            {
                *SizeOfFreezeFrame = Dem_GetFFRecSize;
                Dem_GetFFRecSizeCombEvtNext = DEM_INIT_ZERO;
                Dem_GetFFRecSize = DEM_INIT_ZERO;
            }
            else
            {
                if(Dem_CfgDTCTable[DtcIdx].combEvtIdx[combEvtCnt] > DEM_INIT_ZERO)
                {
                    Dem_GetFFRecSizeCombEvtNext = combEvtCnt;
                    ret = DEM_GETSIZEBYDTC_PENDING;
                }
                else
                {
                    *SizeOfFreezeFrame = Dem_GetFFRecSize;
                    Dem_GetFFRecSizeCombEvtNext = DEM_INIT_ZERO;
                    Dem_GetFFRecSize = DEM_INIT_ZERO;
                }
            }
#else
            *SizeOfFreezeFrame = Dem_GetFFRecSize;
            Dem_GetFFRecSize = DEM_INIT_ZERO;
#endif
        }
        else
        {
            ret = DEM_GETSIZEBYDTC_WRONG_RECNUM;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_DTCGetExRecordData
*
* Explanation: Get extended record data by DTC
*
* param: uint16 DtcIdx, DTC index
*        uint8 evtMemIdx, event memory index
*        uint8 ExtendedDataNumber, extended data record number
*        uint8 *DestBuffer, buffer to hold the extended data
*        uint16 *BufSize, to hold the extended data length
*
* retval: Dem_ReturnGetExtendedDataRecordByDTCType 
********************************************************************************
*/
FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE) Dem_DTCGetExRecordData
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DtcIdx,
    uint8 evtMemIdx,
    uint8 ExtendedDataNumber,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Dem_ReturnGetExtendedDataRecordByDTCType ret = DEM_RECORD_OK;
    uint8 exDataIdx, exRecCnt, exRecIdx, exDataEleCnt, exDataEleIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 entryIdx; 
    uint16 combEvtCnt, combEvtIdx;
    uint16 byteIdx, recDataLen;
    uint16 bufDestOffset = DEM_INIT_ZERO;
    uint16 bufOffset = DEM_INIT_ZERO;
    Dem_EventMemoryEntry_st *entry_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((DestBuffer != NULL_PTR) && (BufSize != NULL_PTR))
    {
        /* Check RecordNumber */
        exDataIdx = Dem_CfgDTCTable[DtcIdx].acExDataClsIdx;
        exRecIdx = DEM_INIT_ZERO;
        for(exRecCnt = DEM_INIT_ZERO; exRecCnt < DEM_CFG_EXDATA_MAX_REF_EXDATA_RECORD_NUM; exRecCnt++)
        {
            exRecIdx = Dem_CfgExDataTable[exDataIdx].acExDataRecordIdx[exRecCnt];
            if(Dem_CfgExDataRecordTable[exRecIdx].acExDataRecNum == ExtendedDataNumber)
            {
                break;
            }
            else
            {
                bufOffset += Dem_CfgExDataRecordTable[exRecIdx].acExDataLen;
            }
        }

        if((exRecCnt < DEM_CFG_EXDATA_MAX_REF_EXDATA_RECORD_NUM) && (exRecIdx > DEM_INIT_ZERO))
        {
            for(combEvtCnt = Dem_GetExRecDataCombEvtNext; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
            {
                combEvtIdx = Dem_CfgDTCTable[DtcIdx].combEvtIdx[combEvtCnt];
                if((combEvtIdx > DEM_INIT_ZERO) && 
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                   (TRUE == DEM_GET_EVENT_STORED(combEvtIdx, evtMemIdx)) &&
                   (DEM_GET_EVENT_ENTRY(combEvtIdx, evtMemIdx) < Dem_CfgEventMemoryTable[evtMemIdx].acEvtMemMaxEntry))
                {
                    entryIdx = DEM_GET_EVENT_ENTRY(combEvtIdx, evtMemIdx);
                    entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);
                    recDataLen = Dem_CfgExDataRecordTable[exRecIdx].acExDataLen;
                    /* Check extended data stored */
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    if(TRUE == entry_ptr[entryIdx].datBuf.stExData[exRecCnt])
                    {
                        /* Check buffer size */
                        if(*BufSize >= (Dem_GetExRecDataSize + recDataLen))
                        {
                            bufDestOffset = Dem_GetExRecDataSize;
                            Dem_GetExRecDataSize += recDataLen;
     
                            for(exDataEleCnt = DEM_INIT_ZERO; exDataEleCnt < DEM_CFG_EXDATA_MAX_REF_DATA_ELEMENT_NUM; exDataEleCnt++)
                            {
                                exDataEleIdx = Dem_CfgExDataRecordTable[exRecIdx].acExDataElementIdx[exDataEleCnt];
                                if(exDataEleIdx > DEM_INIT_ZERO)
                                {
                                    if(DEM_DATA_EMEMENT_TYPE_INTERNAL == Dem_CfgDataElementTable[exDataEleIdx].acDataType)
                                    {
                                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                                        (void)Dem_EventInternalDataElementAcqusition(Dem_CfgEventIdTableIndex[entry_ptr[entryIdx].evtId],
                                                                               evtMemIdx, 
                                                                               entryIdx,
                                                                               Dem_CfgDataElementTable[exDataEleIdx].acDataSize,
                                                                               Dem_CfgDataElementTable[exDataEleIdx].acInterDataElement,
                                                                               &DestBuffer[bufDestOffset]);

                                        bufDestOffset += Dem_CfgDataElementTable[exDataEleIdx].acDataSize;
                                        bufOffset += Dem_CfgDataElementTable[exDataEleIdx].acDataSize;
                                    }
                                    else
                                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                                    {
                                        /* Copy data */
                                        for(byteIdx = DEM_INIT_ZERO; byteIdx < Dem_CfgDataElementTable[exDataEleIdx].acDataSize; byteIdx++)
                                        {
                                            DestBuffer[bufDestOffset] = entry_ptr[entryIdx].datBuf.exData[bufOffset];
                                            bufDestOffset++;
                                            bufOffset++;
                                        }
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }
                        else
                        {
                            ret = DEM_RECORD_WRONG_BUFFERSIZE;
                            /* In this case, do not change the value of *BufSize */
                            Dem_GetExRecDataSize = *BufSize;
                        }
                    }
                    break;
                }
            }
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONRETRIEVAL)
            combEvtCnt++;
            if((combEvtCnt >= DEM_CFG_COMB_DTC_MAX_EVENT_NUM) || (ret != DEM_RECORD_OK))
            {
                *BufSize = Dem_GetExRecDataSize;
                Dem_GetExRecDataCombEvtNext = DEM_INIT_ZERO;
                Dem_GetExRecDataSize = DEM_INIT_ZERO;
            }
            else
            {
                if(Dem_CfgDTCTable[DtcIdx].combEvtIdx[combEvtCnt] > DEM_INIT_ZERO)
                {
                    Dem_GetExRecDataCombEvtNext = combEvtCnt;
                    ret = DEM_RECORD_PENDING;
                }
                else
                {
                    *BufSize = Dem_GetExRecDataSize;
                    Dem_GetExRecDataCombEvtNext = DEM_INIT_ZERO;
                    Dem_GetExRecDataSize = DEM_INIT_ZERO;
                }
            }
#else
            *BufSize = Dem_GetExRecDataSize;
            Dem_GetExRecDataSize = DEM_INIT_ZERO;
#endif

        }
        else
        {
            ret = DEM_RECORD_WRONG_NUMBER;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_DTCGetExRecordSize
*
* Explanation: Get extended record data by DTC
*
* param: uint16 DtcIdx, DTC index
*        uint8 evtMemIdx, event memory index
*        uint8 ExtendedDataNumber, extended data record number
*        uint16 *SizeOfExtendedDataRecord, to hold the extended data length
*
* retval: Dem_ReturnGetSizeOfDataByDTCType 
********************************************************************************
*/
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DTCGetExRecordSize
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DtcIdx,
    uint8 evtMemIdx,
    uint8 ExtendedDataNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
)
{
    Dem_ReturnGetSizeOfDataByDTCType ret = DEM_GETSIZEBYDTC_OK;
    uint8 exDataIdx, exRecCnt, exRecIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 entryIdx;
    uint16 combEvtCnt, combEvtIdx;
    Dem_EventMemoryEntry_st *entry_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if(SizeOfExtendedDataRecord != NULL_PTR)
    {
        /* Check RecordNumber */
        exDataIdx = Dem_CfgDTCTable[DtcIdx].acExDataClsIdx;
        for(exRecCnt = DEM_INIT_ZERO; exRecCnt < DEM_CFG_EXDATA_MAX_REF_EXDATA_RECORD_NUM; exRecCnt++)
        {
            exRecIdx = Dem_CfgExDataTable[exDataIdx].acExDataRecordIdx[exRecCnt];
            if(Dem_CfgExDataRecordTable[exRecIdx].acExDataRecNum == ExtendedDataNumber)
            {
                break;
            }
        }

        if((exRecCnt < DEM_CFG_EXDATA_MAX_REF_EXDATA_RECORD_NUM) && (exRecIdx > DEM_INIT_ZERO))
        {
            for(combEvtCnt = Dem_GetExRecSizeCombEvtNext; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
            {
                combEvtIdx = Dem_CfgDTCTable[DtcIdx].combEvtIdx[combEvtCnt];
                if((combEvtIdx > DEM_INIT_ZERO) && 
                   /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                   (TRUE == DEM_GET_EVENT_STORED(combEvtIdx, evtMemIdx)) &&
                   (DEM_GET_EVENT_ENTRY(combEvtIdx, evtMemIdx) < Dem_CfgEventMemoryTable[evtMemIdx].acEvtMemMaxEntry))
                {
                    entryIdx = DEM_GET_EVENT_ENTRY(combEvtIdx, evtMemIdx);
                    entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);
                    /* Check extended data stored */
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    if(TRUE == entry_ptr[entryIdx].datBuf.stExData[exRecCnt])
                    {
                        Dem_GetExRecSize += Dem_CfgExDataRecordTable[exRecIdx].acExDataLen;
                    }
                    break;
                }
            }
            
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONRETRIEVAL)
            combEvtCnt++;
            if(combEvtCnt >= DEM_CFG_COMB_DTC_MAX_EVENT_NUM)
            {
                *SizeOfExtendedDataRecord = Dem_GetExRecSize;
                Dem_GetExRecSizeCombEvtNext = DEM_INIT_ZERO;
                Dem_GetExRecSize = DEM_INIT_ZERO;
            }
            else
            {
                if(Dem_CfgDTCTable[DtcIdx].combEvtIdx[combEvtCnt] > DEM_INIT_ZERO)
                {
                    Dem_GetExRecSizeCombEvtNext = combEvtCnt;
                    ret = DEM_GETSIZEBYDTC_PENDING;
                }
                else
                {
                    *SizeOfExtendedDataRecord = Dem_GetExRecSize;
                    Dem_GetExRecSizeCombEvtNext = DEM_INIT_ZERO;
                    Dem_GetExRecSize = DEM_INIT_ZERO;
                }
            }
#else
            *SizeOfExtendedDataRecord = Dem_GetExRecSize;
            Dem_GetExRecSize = DEM_INIT_ZERO;
#endif
        }
        else
        {
            ret = DEM_GETSIZEBYDTC_WRONG_RECNUM;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_DTCGetAllExRecordData
*
* Explanation: Get All extended record data by DTC
*
* param: uint16 DtcIdx, DTC index
*        uint8 evtMemIdx, event memory index
*        uint8 *DestBuffer, buffer to hold the extended data
*        uint16 *BufSize, to hold the extended data length
*
* retval: Dem_ReturnGetExtendedDataRecordByDTCType 
********************************************************************************
*/
FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE) Dem_DTCGetAllExRecordData
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DtcIdx,
    uint8 evtMemIdx,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Dem_ReturnGetExtendedDataRecordByDTCType ret = DEM_RECORD_OK;
    uint8 exDataIdx, exRecCnt, exRecIdx, exDataEleCnt, exDataEleIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 entryIdx; 
    uint16 byteIdx, recDataLen;
    uint16 combEvtCnt, combEvtIdx;
    uint16 bufOffset = DEM_INIT_ZERO;
    uint16 bufDestOffset = DEM_INIT_ZERO;
    Dem_EventMemoryEntry_st *entry_ptr;
    
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((DestBuffer != NULL_PTR) && (BufSize != NULL_PTR))
    {
        for(combEvtCnt = Dem_GetAllExRecDataCombEvtNext; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
        {
            combEvtIdx = Dem_CfgDTCTable[DtcIdx].combEvtIdx[combEvtCnt];
            if((combEvtIdx > DEM_INIT_ZERO) && 
               /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
               (TRUE == DEM_GET_EVENT_STORED(combEvtIdx, evtMemIdx)) &&
               (DEM_GET_EVENT_ENTRY(combEvtIdx, evtMemIdx) < Dem_CfgEventMemoryTable[evtMemIdx].acEvtMemMaxEntry))
            {
                entryIdx = DEM_GET_EVENT_ENTRY(combEvtIdx, evtMemIdx);
                entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);
                
                /* Check RecordNumber */
                exDataIdx = Dem_CfgDTCTable[DtcIdx].acExDataClsIdx;
                for(exRecCnt = DEM_INIT_ZERO; exRecCnt < DEM_CFG_EXDATA_MAX_REF_EXDATA_RECORD_NUM; exRecCnt++)
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    if(TRUE == entry_ptr[entryIdx].datBuf.stExData[exRecCnt])
                    {
                        exRecIdx = Dem_CfgExDataTable[exDataIdx].acExDataRecordIdx[exRecCnt];
                        recDataLen = Dem_CfgExDataRecordTable[exRecIdx].acExDataLen;
                        if(*BufSize >= (Dem_GetAllExRecDataSize + recDataLen))
                        {                          
                            bufDestOffset = Dem_GetAllExRecDataSize;
                            Dem_GetAllExRecDataSize += (recDataLen + DEM_BYTE_ONE);
                            /* Copy record number */
                            DestBuffer[bufDestOffset] = Dem_CfgExDataRecordTable[exRecIdx].acExDataRecNum;
                            bufDestOffset++;
                            for(exDataEleCnt = DEM_INIT_ZERO; exDataEleCnt < DEM_CFG_EXDATA_MAX_REF_DATA_ELEMENT_NUM; exDataEleCnt++)
                            {
                                exDataEleIdx = Dem_CfgExDataRecordTable[exRecIdx].acExDataElementIdx[exDataEleCnt];
                                if(exDataEleIdx > DEM_INIT_ZERO)
                                {
                                    if(DEM_DATA_EMEMENT_TYPE_INTERNAL == Dem_CfgDataElementTable[exDataEleIdx].acDataType)
                                    {
                                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                                        (void)Dem_EventInternalDataElementAcqusition(Dem_CfgEventIdTableIndex[entry_ptr[entryIdx].evtId],
                                                                               evtMemIdx, 
                                                                               entryIdx,
                                                                               Dem_CfgDataElementTable[exDataEleIdx].acDataSize,
                                                                               Dem_CfgDataElementTable[exDataEleIdx].acInterDataElement,
                                                                               &DestBuffer[bufDestOffset]);

                                        bufDestOffset += Dem_CfgDataElementTable[exDataEleIdx].acDataSize;
                                        bufOffset += Dem_CfgDataElementTable[exDataEleIdx].acDataSize;
                                    }
                                    else
                                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                                    {
                                        /* Copy data */
                                        for(byteIdx = DEM_INIT_ZERO; byteIdx < Dem_CfgDataElementTable[exDataEleIdx].acDataSize; byteIdx++)
                                        {
                                            DestBuffer[bufDestOffset] = entry_ptr[entryIdx].datBuf.exData[bufOffset];
                                            bufDestOffset++;
                                            bufOffset++;
                                        }
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }

                        }
                        else
                        {
                            ret = DEM_RECORD_WRONG_BUFFERSIZE;
                            /* In this case, do not change the value of *BufSize */
                            Dem_GetAllExRecDataSize = *BufSize;
                            break;
                        }
                    }
                    else
                    {
                        exRecIdx = Dem_CfgExDataTable[exDataIdx].acExDataRecordIdx[exRecCnt];
                        bufOffset += Dem_CfgExDataRecordTable[exRecIdx].acExDataLen;
                    }
                }
                break;
            }
        }
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONRETRIEVAL)
        combEvtCnt++;
        if((combEvtCnt >= DEM_CFG_COMB_DTC_MAX_EVENT_NUM) || (ret != DEM_RECORD_OK))
        {
            *BufSize = Dem_GetAllExRecDataSize;
            Dem_GetAllExRecDataCombEvtNext = DEM_INIT_ZERO;
            Dem_GetAllExRecDataSize = DEM_INIT_ZERO;
        }
        else
        {
            if(Dem_CfgDTCTable[DtcIdx].combEvtIdx[combEvtCnt] > DEM_INIT_ZERO)
            {
                Dem_GetAllExRecDataCombEvtNext = combEvtCnt;
                ret = DEM_RECORD_PENDING;
            }
            else
            {
                *BufSize = Dem_GetAllExRecDataSize;
                Dem_GetAllExRecDataCombEvtNext = DEM_INIT_ZERO;
                Dem_GetAllExRecDataSize = DEM_INIT_ZERO;
            }
        }
#else
        *BufSize = Dem_GetAllExRecDataSize;
        Dem_GetAllExRecDataSize = DEM_INIT_ZERO;
#endif

    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_DTCGetAllExRecordSize
*
* Explanation: Get all extended record data size by DTC
*
* param: uint16 DtcIdx, DTC index
*        uint8 evtMemIdx, event memory index
*        uint16 *SizeOfExtendedDataRecord, to hold the extended data length
*
* retval: Dem_ReturnGetSizeOfDataByDTCType 
********************************************************************************
*/
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DTCGetAllExRecordSize
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DtcIdx,
    uint8 evtMemIdx,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Dem_ReturnGetSizeOfDataByDTCType ret = DEM_GETSIZEBYDTC_OK;
    uint8 exDataIdx, exRecCnt, exRecIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 entryIdx;
    uint16 combEvtCnt, combEvtIdx;
    Dem_EventMemoryEntry_st *entry_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if(SizeOfExtendedDataRecord != NULL_PTR)
    {
        for(combEvtCnt = Dem_GetAllExRecSizeCombEvtNext; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
        {
            combEvtIdx = Dem_CfgDTCTable[DtcIdx].combEvtIdx[combEvtCnt];
            if((combEvtIdx > DEM_INIT_ZERO) && 
               /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
               (TRUE == DEM_GET_EVENT_STORED(combEvtIdx, evtMemIdx)) &&
               (DEM_GET_EVENT_ENTRY(combEvtIdx, evtMemIdx) < Dem_CfgEventMemoryTable[evtMemIdx].acEvtMemMaxEntry))
            {
                entryIdx = DEM_GET_EVENT_ENTRY(combEvtIdx, evtMemIdx);
                entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);

                /* Check RecordNumber */
                exDataIdx = Dem_CfgDTCTable[DtcIdx].acExDataClsIdx;
                for(exRecCnt = DEM_INIT_ZERO; exRecCnt < DEM_CFG_EXDATA_MAX_REF_EXDATA_RECORD_NUM; exRecCnt++)
                {
                    exRecIdx = Dem_CfgExDataTable[exDataIdx].acExDataRecordIdx[exRecCnt];
                    /* Check extended data stored */
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    if(TRUE == entry_ptr[entryIdx].datBuf.stExData[exRecCnt])
                    {
                        /* Add one byte record number */
                        Dem_GetAllExRecSize++;
                        Dem_GetAllExRecSize += Dem_CfgExDataRecordTable[exRecIdx].acExDataLen;
                    }
                }
                break;
            }
        }
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONRETRIEVAL)
        combEvtCnt++;
        if(combEvtCnt >= DEM_CFG_COMB_DTC_MAX_EVENT_NUM)
        {
            *SizeOfExtendedDataRecord = Dem_GetAllExRecSize;
            Dem_GetAllExRecSizeCombEvtNext = DEM_INIT_ZERO;
            Dem_GetAllExRecSize = DEM_INIT_ZERO;
        }
        else
        {
            if(Dem_CfgDTCTable[DtcIdx].combEvtIdx[combEvtCnt] > DEM_INIT_ZERO)
            {
                Dem_GetAllExRecSizeCombEvtNext = combEvtCnt;
                ret = DEM_GETSIZEBYDTC_PENDING;
            }
            else
            {
                *SizeOfExtendedDataRecord = Dem_GetAllExRecSize;
                Dem_GetAllExRecSizeCombEvtNext = DEM_INIT_ZERO;
                Dem_GetAllExRecSize = DEM_INIT_ZERO;
            }
        }
#else
        *SizeOfExtendedDataRecord = Dem_GetAllExRecSize;
        Dem_GetAllExRecSize = DEM_INIT_ZERO;
#endif

    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventGetRecentlyFFRecordData
*
* Explanation: Get the most recent freeze frame record data
*
* param: uint16 EventIdx, event index
*        uint8* DestBuffer, to hold the return freeze frame data size
*        uint16* BufSize, to hold the return freeze frame data
*
* retval: Std_ReturnType
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EventGetRecentlyFFRecordData
(
    uint16 EventIdx,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType ret = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 evtMemIdx, entryIdx, ffDataIdx, ffRecIdx;
    uint16 bufOffset = DEM_INIT_ZERO;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx, byteIdx;
    Dem_EventMemoryEntry_st *entry_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (DestBuffer != NULL_PTR) && (BufSize != NULL_PTR))
    {
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        /* Only get data from primary event memory */
        evtMemIdx = DEM_EVENT_MEMORY_PRIMARY;
        if((TRUE == DEM_GET_EVENT_STORED(EventIdx, evtMemIdx)) &&
           (DEM_GET_EVENT_ENTRY(EventIdx, evtMemIdx) < Dem_CfgEventMemoryTable[evtMemIdx].acEvtMemMaxEntry))
        {
            entryIdx = DEM_GET_EVENT_ENTRY(EventIdx, evtMemIdx);
            entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);

            ffDataIdx = Dem_CfgDtcFfDataClsIdx[dtcIdx];
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
            ffRecIdx = entry_ptr[entryIdx].datBuf.ffRecIdx;

            if(ffRecIdx > DEM_INIT_ZERO)
            {
                if(*BufSize >= Dem_CfgFfDataTable[ffDataIdx].acFfDataLen)
                {
                    bufOffset = ((uint16)ffRecIdx - DEM_BYTE_ONE) * Dem_CfgFfDataTable[ffDataIdx].acFfDataLen;
                    *BufSize = Dem_CfgFfDataTable[ffDataIdx].acFfDataLen;
                    
                    for(byteIdx = DEM_INIT_ZERO; byteIdx < *BufSize; byteIdx++)
                    {
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                        DestBuffer[byteIdx] = entry_ptr[entryIdx].datBuf.ffData[bufOffset];
                        bufOffset++;
                    }
                    ret = E_OK;
                }
            }
            else
            {
                ret = DEM_E_NODATAAVAILABLE;
            }
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventSetInitMonitorReason
*
* Explanation: set the event monitor initialization reason
*
* param: uint16 evtIdx, event index of configured event table
*        Dem_InitMonitorReasonType reason, reason type
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventSetInitMonitorReason
(
    uint16 EventIdx, 
    Dem_InitMonitorReasonType Reason
)
{
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        if((DEM_INIT_MONITOR_NONE == DEM_GET_MONITOR_REASON(EventIdx)) ||
           (Reason <= DEM_GET_MONITOR_REASON(EventIdx)))
        {
            DEM_SET_MONITOR_REASON(EventIdx, Reason);
            DEM_SET_MONITOR_REASON_REQ(TRUE);
        }
    }
}

#if(DEM_CFG_ENCOND_GROUP_NUM > DEM_INIT_ZERO)
/*
********************************************************************************
* Function Name: Dem_EventCheckEnCondGrpChanged
*
* Explanation: Check if the enable condition group status changed or not 
*
* param: evtIdx: event index
*
* retval: void
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventCheckEnCondGrpChanged(void)
{
    boolean condGrpSt;
    /* Polyspace +1 DEFECT:PARTIALLY_ACCESSED_ARRAY [JUstified:Unset] "NSCA_Polyspace_Dem_PartiallyAccessedArray" */
    uint8 condGrpCheckFlag[DEM_CFG_ENCOND_GROUP_NUM + DEM_BYTE_ONE] = {DEM_INIT_ZERO};
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 condGrpIdx;
    uint16 evtIdx;

    if(TRUE == DEM_GET_ENCOND_REQ())
    {
        DEM_SET_ENCOND_REQ(FALSE);

        for(evtIdx = DEM_BYTE_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
        {
            condGrpIdx = Dem_CfgEventTable[evtIdx].awEvtEnCondGrpIdx;
            if((condGrpIdx > DEM_INIT_ZERO) && (TRUE != condGrpCheckFlag[condGrpIdx - DEM_BYTE_ONE]))
            {
                /* Indicate this condition group has been checked. */
                condGrpCheckFlag[condGrpIdx - DEM_BYTE_ONE] = TRUE;
                condGrpSt = Dem_EventGetEnCondGrpStatus(condGrpIdx);

                if((FALSE == DEM_GET_ENCONDGRP(condGrpIdx)) && (TRUE == condGrpSt))
                {
                    DEM_SET_ENCONDGRP(condGrpIdx, condGrpSt);
                    /* In case of enable condition group status changed from not fullfilled to fullfilled, */
                    /* Set trigger reason for callback function InitMonitorForEvent of the related events */
                    Dem_EventSetInitMonitorReason(evtIdx, DEM_INIT_MONITOR_REENABLED);
                }
                else if((TRUE == DEM_GET_ENCONDGRP(condGrpIdx)) && (FALSE == condGrpSt))
                {
                    DEM_SET_ENCONDGRP(condGrpIdx, condGrpSt);
                    /* In case of enable condition group status changed from fullfilled to not fullfilled */
                    /* and DemDebounceBehavior is set to DEM_DEBOUNCE_RESET, reset the related fault detection counter(s) */
                    Dem_EventDebounceBehavior(evtIdx);
                }
                else
                {
                /* Do nothing */
                }
            }
        }
    }
}
#endif

#if(DEM_CFG_STORCOND_GROUP_NUM > DEM_INIT_ZERO)
/*
********************************************************************************
* Function Name: Dem_EventCheckStorCondGrpChanged
*
* Explanation: Check if the storage condition group status changed or not 
*
* param: evtIdx: event index
*
* retval: void
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventCheckStorCondGrpChanged(void)
{
    boolean condGrpSt;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 condGrpIdx;
    uint16 evtIdx;

    if(TRUE == DEM_GET_STORCOND_REQ())
    {
        DEM_SET_STORCOND_REQ(FALSE);

        for(evtIdx = DEM_BYTE_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
        {
            condGrpIdx = Dem_CfgEventTable[evtIdx].awEvtEnCondGrpIdx;
            if(condGrpIdx > DEM_INIT_ZERO)
            {
                condGrpSt = Dem_EventGetStorCondGrpStatus(condGrpIdx);

                if((FALSE == DEM_GET_STORCONDGRP(condGrpIdx)) && (TRUE == condGrpSt))
                {
                    DEM_SET_STORCONDGRP(condGrpIdx, condGrpSt);
                    /* In case of store condition group status changed from not fullfilled to fullfilled, */
                    /* Set trigger reason for callback function InitMonitorForEvent of the related events */
                    Dem_EventSetInitMonitorReason(evtIdx, DEM_INIT_MONITOR_STORAGE_REENABLED);
                }
            }
        }
    }
}
#endif

/*
********************************************************************************
* Function Name: Dem_EventCheckDtcSettingReenable
*
* Explanation: Check if DTC setting is reenable or not 
*
* param: void
*
* retval: void
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventCheckDtcSettingReenable(void)
{
    uint16 evtIdx;
#if(DEM_CFG_DTC_GROUP_NUM > 0U)
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;
    uint16 dtcGrpIdx;
#endif
    
    /* In case of call API Dem_DcmEnableDTCSetting, trigger the */
    /* callback function InitMonitorForEvent of the related event */
    /*  with reason DEM_INIT_MONITOR_REENABLED */
    if(TRUE == DEM_GET_DTC_SETTING_ENABLE())
    {
        for(evtIdx = DEM_BYTE_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
        {
            if(DEM_EVENT_DTC_GROUP_ALL == DEM_GET_DTC_DISABLE_GROUP())
            {
                Dem_EventSetInitMonitorReason(evtIdx, DEM_INIT_MONITOR_REENABLED);
            }
            else
            {
#if(DEM_CFG_DTC_GROUP_NUM > 0U)                
                dtcGrpIdx = DEM_GET_DTC_DISABLE_GROUP_IDX();
                if((dtcGrpIdx > DEM_INIT_ZERO) && (dtcGrpIdx < DEM_CFG_DTC_GROUP_NUM))
                {
                    dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
                    if((DEM_DTCVALUE_CAL(dtcIdx) >= Dem_CfgDTCGrpTable[dtcGrpIdx]) &&
                       (DEM_DTCVALUE_CAL(dtcIdx) < Dem_CfgDTCGrpTable[dtcGrpIdx + DEM_BYTE_ONE]))
                    {
                        Dem_EventSetInitMonitorReason(evtIdx, DEM_INIT_MONITOR_REENABLED);
                        break;
                    }
                }
#endif
            }
        }

        DEM_SET_DTC_SETTING_ENABLE(FALSE);
    }
}

#if(DEM_CFG_COMP_NUM > DEM_INIT_ZERO)
/*
********************************************************************************
* Function Name: Dem_EventCheckComponetStatusChanged
*
* Explanation: Check if component failed status is changed or not 
*
* param: void
*
* retval: void
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventCheckComponetStatusChanged(void)
{
    uint8 evtCompFailedSt[DEM_CFG_COMP_NUM] = {FALSE};
    uint16 evtIdx;
    uint16 evtCompFailedEvtIdx[DEM_CFG_COMP_NUM] = {DEM_INIT_ZERO};
    uint16 evtCompIdx, evtChildCompIdx, compIdx;
    
    for(evtIdx = DEM_INIT_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
    {
        /* Event component status */
        evtCompIdx = Dem_CfgEventTable[evtIdx].awEvtComIdx;
        if((evtCompIdx > DEM_INIT_ZERO) && (TRUE == DEM_GET_UDS_STATUS_TF(evtIdx)))
        {
            if(TRUE == evtCompFailedSt[evtCompIdx - DEM_INIT_ONE])
            {
                if(FALSE == Dem_ConfigComponentTable[evtCompIdx].compPriIgnor)
                {
                    if((evtCompFailedEvtIdx[evtCompIdx - DEM_INIT_ONE] > DEM_INIT_ZERO) &&
                       (Dem_CfgEventTable[evtIdx].acCompPri < 
                        Dem_CfgEventTable[evtCompFailedEvtIdx[evtCompIdx - DEM_INIT_ONE]].acCompPri))
                    {
                        evtCompFailedEvtIdx[evtCompIdx - DEM_INIT_ONE] = evtIdx;
                    }
                }
            }
            else
            {
                evtCompFailedSt[evtCompIdx - DEM_INIT_ONE] = TRUE;
                evtCompFailedEvtIdx[evtCompIdx - DEM_INIT_ONE] = evtIdx;
                
                /* Set all child components to failed */
                for(evtChildCompIdx = DEM_INIT_ZERO; evtChildCompIdx < DEM_CFG_MAX_CHILD_COMP_NUM; evtChildCompIdx++)
                {
                    if(Dem_ConfigComponentTable[evtCompIdx].childCompIdx[evtChildCompIdx] > DEM_INIT_ZERO)
                    {
                        compIdx = Dem_ConfigComponentTable[evtCompIdx].childCompIdx[evtChildCompIdx];
                        evtCompFailedSt[compIdx - DEM_INIT_ONE] = TRUE;
                        evtCompFailedEvtIdx[compIdx - DEM_INIT_ONE] = DEM_INIT_ZERO;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    /* Component status based on parent-child relationship */
    for(evtCompIdx = DEM_INIT_ONE; evtCompIdx <= DEM_CFG_COMP_NUM; evtCompIdx++)
    {
        if(evtCompFailedEvtIdx[evtCompIdx - DEM_INIT_ONE] != DEM_GET_COMP_FAILED_EVTIDX(evtCompIdx))
        {
            DEM_SET_COMP_FAILED_EVTIDX(evtCompIdx, evtCompFailedEvtIdx[evtCompIdx - DEM_INIT_ONE]);
        }
        
        if(evtCompFailedSt[evtCompIdx - DEM_INIT_ONE] != DEM_GET_COMP_FAILED_STATUS(evtCompIdx))
        {
            DEM_SET_COMP_FAILED_STATUS(evtCompIdx, evtCompFailedSt[evtCompIdx - DEM_INIT_ONE]);

            Dem_EventTriggerComponentFailedChangedCbk(evtCompIdx, evtCompFailedSt[evtCompIdx - DEM_INIT_ONE]);
#if(DEM_CFG_TRIGGERFIMREPORT == STD_ON)
            FiM_DemTriggerOnComponentStatus(evtCompIdx, evtCompFailedSt[evtCompIdx - DEM_INIT_ONE]);
#endif
        }
    }
}
#endif

/*
********************************************************************************
* Function Name: Dem_EventCheckMonitorTrigger
*
* Explanation: Check if monitor trigger is happened or not 
*
* param: void
*
* retval: void
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventCheckMonitorTrigger(void)
{
#if((DEM_CFG_CALIBSUPPORT == STD_ON ) || (DEM_EVENT_MONITOR_ENABLE == STD_ON))
    uint16 evtIdx;
#endif

#if(DEM_CFG_CALIBSUPPORT == STD_ON)
#if(DEM_CFG_EVENT_NUM > DEM_CFG_MAXEVTNUMPROCSPERCYCLE)
    uint16 startEvtIdx, endEvtIdx, evtAvailSplitCnt;

    /* Get the current event available split count. */
    evtAvailSplitCnt = DEM_GET_EVTAVAIL_SPLIT_CNT();
    startEvtIdx = evtAvailSplitCnt + DEM_INIT_ONE;

    /* Segmentation processing. */
    if((evtAvailSplitCnt + DEM_CFG_MAXEVTNUMPROCSPERCYCLE) < DEM_CFG_EVENT_NUM)
    {
        endEvtIdx = evtAvailSplitCnt + DEM_CFG_MAXEVTNUMPROCSPERCYCLE;
        DEM_SET_EVTAVAIL_SPLIT_CNT(endEvtIdx);
    }
    else
    {
        endEvtIdx = DEM_CFG_EVENT_NUM;
        DEM_SET_EVTAVAIL_SPLIT_CNT(DEM_INIT_ZERO);
    }

    for(evtIdx = startEvtIdx; evtIdx <= endEvtIdx; evtIdx++)
#else
    for(evtIdx = DEM_INIT_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
#endif /* DEM_CFG_EVENT_NUM > DEM_CFG_MAXEVTNUMPROCSPERCYCLE */
    {
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
        /* Check if the event availablilty changed. */
        if(DEM_GET_INITAVAIL(evtIdx) != (uint8)DEM_EVTAVAIL_CAL(evtIdx))
        {
            (void)Dem_SetEventAvailable(Dem_CfgEventTable[evtIdx].awEvtId, DEM_EVTAVAIL_CAL(evtIdx));
        }
#endif
    }
#endif /* DEM_CFG_CALIBSUPPORT == STD_ON */
    if(TRUE == DEM_GET_MONITOR_REASON_REQ())
    {
        DEM_SET_MONITOR_REASON_REQ(FALSE);

#if(DEM_EVENT_MONITOR_ENABLE == STD_ON)
        for(evtIdx = DEM_INIT_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
        {
            /* Trigger Init Monitor */
            if(DEM_INIT_MONITOR_NONE != DEM_GET_MONITOR_REASON(evtIdx))
            {
                Dem_EventTriggerInitMonitorCbk(evtIdx, DEM_GET_MONITOR_REASON(evtIdx));
                DEM_SET_MONITOR_REASON(evtIdx, DEM_INIT_MONITOR_NONE);
            }
        }
#endif /* DEM_EVENT_MONITOR_ENABLE == STD_ON */
    }
}

/*
********************************************************************************
* Function Name: Dem_EventCheckDataUpdateTrigger
*
* Explanation: Check if event data update trigger is fullfilled 
*
* param: uint16 EventIdx, index of event table
*        uint8 TriggerType, trigger type
*
* retval: E_NOT_OK, fullfilled; E_OK, Not fullfilled
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_EventCheckDataUpdateTrigger
(
    uint16 EventIdx,
    uint8 TriggerType
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 stTrig;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        stTrig = DEM_GET_TRIG(EventIdx);
        
        switch(TriggerType)
        {
            case DEM_TRIGGER_ON_FDC_THRESHOLD:
            {
                if(DEM_INIT_ZERO != (stTrig & DEM_TRIGGER_ON_FDC_THRESHOLD))
                {
                    ret = E_OK;
                    DEM_SET_TRIG(EventIdx, DEM_TRIGGER_ON_FDC_THRESHOLD_ONCE);
                }
                break;
            }
            case DEM_TRIGGER_ON_TEST_FAILED:
            {
                if(DEM_INIT_ZERO != (stTrig & DEM_TRIGGER_ON_TEST_FAILED))
                {
                    ret = E_OK;
                }
                break;

            }
            case DEM_TRIGGER_ON_PENDING:
            {
                if(DEM_INIT_ZERO != (stTrig & DEM_TRIGGER_ON_PENDING))
                {
                    ret = E_OK;
                }
                break;

            }
            case DEM_TRIGGER_ON_CONFIRMED:
            {
                if(DEM_INIT_ZERO != (stTrig & DEM_TRIGGER_ON_CONFIRMED))
                {
                    ret = E_OK;
                }
                break;

            }
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            case DEM_TRIGGER_ON_MIRROR:
            {
                if(DEM_INIT_ZERO != (stTrig & DEM_TRIGGER_ON_MIRROR))
                {
                    ret = E_OK;
                }
                break;

            }
            case DEM_TRIGGER_ON_PASSED:
            {
                if(DEM_INIT_ZERO != (stTrig & DEM_TRIGGER_ON_PASSED))
                {
                    ret = E_OK;
                }
                break;
            }
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            default:
            {
                break;
            }
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCheckConsecutiveFault
*
* Explanation: Check if requested event is a consecutive fault according to 
*              the component failed status
*
* param: uint16 EventIdx, index of event table
*
* retval: E_NOT_OK, not ConsecutiveFault; E_OK, ConsecutiveFault
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_EventCheckConsecutiveFault
(
    uint16 EventIdx
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint16 evtCompIdx, evtChildCompCnt, evtChildCompIdx;

    if( (EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
        (Dem_CfgEventTable[EventIdx].awEvtComIdx > DEM_INIT_ZERO)  &&
        (Dem_CfgEventTable[EventIdx].awEvtComIdx <= DEM_CFG_COMP_NUM) )
    {
        if(TRUE == DEM_GET_COMP_AVAILABLE(Dem_CfgEventTable[EventIdx].awEvtComIdx))
        {
            evtCompIdx = Dem_CfgEventTable[EventIdx].awEvtComIdx;
            if(TRUE == DEM_GET_COMP_FAILED_STATUS(evtCompIdx))
            {
                if(EventIdx != DEM_GET_COMP_FAILED_EVTIDX(evtCompIdx))
                {
                    if(FALSE == Dem_ConfigComponentTable[evtCompIdx].compPriIgnor)
                    {
                        /* [SWS_Dem_01126] If any other event with higher priority is already failed, */
                        /* treat it as a consecutive fault */
                        if((DEM_INIT_ZERO == DEM_GET_COMP_FAILED_EVTIDX(evtCompIdx)) ||
                           (Dem_CfgEventTable[EventIdx].acCompPri > 
                            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                            Dem_CfgEventTable[DEM_GET_COMP_FAILED_EVTIDX(evtCompIdx)].acCompPri))
                        {
                            ret = E_OK;
                        }
                        else
                        {
                            DEM_SET_COMP_FAILED_EVTIDX(evtCompIdx, EventIdx);
                        }
                    }
                    else
                    {
                        ret = E_OK;
                    }
                }
            }
            else
            {
                DEM_SET_COMP_FAILED_STATUS(evtCompIdx, TRUE);
                DEM_SET_COMP_FAILED_EVTIDX(evtCompIdx, EventIdx);
                Dem_EventTriggerComponentFailedChangedCbk(evtCompIdx, DEM_GET_COMP_FAILED_STATUS(evtCompIdx));
#if(DEM_CFG_TRIGGERFIMREPORT == STD_ON)
                FiM_DemTriggerOnComponentStatus(evtCompIdx, DEM_GET_COMP_FAILED_STATUS(evtCompIdx));
#endif
                /* Set all child components to failed */
                for(evtChildCompCnt = DEM_INIT_ZERO; evtChildCompCnt < DEM_CFG_MAX_CHILD_COMP_NUM; evtChildCompCnt++)
                {
                    evtChildCompIdx = Dem_ConfigComponentTable[evtCompIdx].childCompIdx[evtChildCompCnt];
                    if(evtChildCompIdx > DEM_INIT_ZERO)
                    {
                        if(FALSE == DEM_GET_COMP_FAILED_STATUS(evtChildCompIdx))
                        {
                            DEM_SET_COMP_FAILED_STATUS(evtChildCompIdx, TRUE);
                            Dem_EventTriggerComponentFailedChangedCbk(evtChildCompIdx, DEM_GET_COMP_FAILED_STATUS(evtChildCompIdx));
#if(DEM_CFG_TRIGGERFIMREPORT == STD_ON)
                            FiM_DemTriggerOnComponentStatus(evtChildCompIdx, DEM_GET_COMP_FAILED_STATUS(evtChildCompIdx));
#endif
                        }
                        DEM_SET_COMP_FAILED_EVTIDX(evtChildCompIdx, DEM_INIT_ZERO);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            ret = E_OK;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCheckDTCOriginValid
*
* Explanation: Check if the requested DTCOrigin(event memory type) is valid 
*
* param: Dem_DTCOriginType DTCOrigin, event memory ID
*        uint8 *EventMemIdx, to hold the event memory index
*
* retval: E_NOT_OK, all parameter is invalid;E_OK, all parameter is valid
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EventCheckDTCOriginValid
(
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) EventMemIdx
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 evtMemIdx;

    if((DEM_DTC_ORIGIN_PRIMARY_MEMORY == DTCOrigin) || 
       (DEM_DTC_ORIGIN_USERDEFINED_MEMORY_0 == DTCOrigin) ||
       (DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1 == DTCOrigin))
    {
        for(evtMemIdx = DEM_INIT_ONE; evtMemIdx <= DEM_CFG_EVENT_MEMORY_NUM; evtMemIdx++)
        {
            if(DTCOrigin == Dem_CfgEventMemoryTable[evtMemIdx].acEvtMemId)
            {
                *EventMemIdx = evtMemIdx;
                ret = E_OK;
                break;
            }
        }
    }
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    else if(DEM_DTC_ORIGIN_PERMANENT_MEMORY == DTCOrigin)
    {
        *EventMemIdx = DEM_INIT_ZERO;
        ret = E_OK;
    }
#endif
    else
    {
        /* Mirror is not supported */
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCheckWarningIndicatorAct
*
* Explanation: Check if activate the warning indicator
*
* param: uint16 EventIdx, index of event table
*        uint8 *IndiFc, array of the indicator failure counter
*
* retval: E_NOT_OK, no activate;E_OK, activate
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_EventCheckWarningIndicatorAct
(
    uint16 EventIdx,
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) IndiFc  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 evtIndiIdx;
    uint8 indiIdx;
    uint8 indiOnCnt;

#if( DEM_CFG_J1939SUPPORT == STD_ON )
    uint16 evtIdx = DEM_INIT_ZERO;
#endif

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        /* Retrieve all the indicators of the event. */
        for(evtIndiIdx = DEM_INIT_ZERO; evtIndiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; evtIndiIdx++)
        {
            indiIdx = Dem_CfgEventTable[EventIdx].acIndiIdx[evtIndiIdx];
            if(indiIdx > DEM_INIT_ZERO)
            {
                /* Failed operation cycle should process in the operation cycle that configured in acIndFailureOpCycIdx. */
                if((IndiFc[evtIndiIdx] >= Dem_CfgEventTable[EventIdx].acIndiFccThrs[evtIndiIdx]) &&
                   (FALSE == DEM_GET_INDICATOR(EventIdx, evtIndiIdx)))
                {
                    DEM_SET_INDICATOR(EventIdx, evtIndiIdx, TRUE);

                    indiOnCnt = DEM_GET_INDICATOR_ON_CNT(indiIdx);
                    indiOnCnt++;
                    DEM_SET_INDICATOR_ON_CNT(indiIdx, indiOnCnt);

#if( DEM_CFG_J1939SUPPORT == STD_ON )
                    for( evtIdx = DEM_INIT_ONE; evtIdx < DEM_CFG_EVENT_NUM; evtIdx++ )
                    {
                        if( TRUE == DEM_GET_INDICATOR(evtIdx, evtIndiIdx) )
                        {
                            if( (Dem_CfgEvtIndiBhv[EventIdx][evtIndiIdx] > DEM_GET_INDICATOR_STATUS(indiIdx)) && 
                                (Dem_CfgEvtIndiBhv[EventIdx][evtIndiIdx] != DEM_INDICATOR_NONE) )
#endif

                            {
                                DEM_SET_INDICATOR_STATUS(indiIdx, Dem_CfgEvtIndiBhv[EventIdx][evtIndiIdx]);
                            }

#if( DEM_CFG_J1939SUPPORT == STD_ON )
                        }
                    }
#endif

                    /* If any indicator on criteria is fullfilled, activate WarningIndicator */              
                    ret = E_OK;
                }
            }
            else
            {
                break;
            }
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCheckWarningIndicatorDeAct
*
* Explanation: Check if deactivate the warning indicator
*
* param: uint16 EventIdx, index of event table
*        uint8 *IndiHc, array of the indicator healing counter
*
* retval: E_NOT_OK, no activate;E_OK, activate
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_EventCheckWarningIndicatorDeAct
(
    uint16 EventIdx,
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) IndiHc  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    Std_ReturnType ret = E_OK;
    uint8 evtIndiIdx, indiIdx, indiOnCnt;
#if( DEM_CFG_J1939SUPPORT == STD_ON )
    uint16 evtIdx;
#endif

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        for(evtIndiIdx = DEM_INIT_ZERO; evtIndiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; evtIndiIdx++)
        {
            indiIdx = Dem_CfgEventTable[EventIdx].acIndiIdx[evtIndiIdx];
            if(indiIdx > DEM_INIT_ZERO)
            {
                /* Healing operation cycle should process in the operation cycle that configured in acIndFailureOpCycIdx. */
                if((IndiHc[evtIndiIdx] >= Dem_CfgEventTable[EventIdx].acIndiHccThrs[evtIndiIdx]) &&
                   (TRUE == DEM_GET_INDICATOR(EventIdx, evtIndiIdx)) &&
                   /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                   (DEM_CYCLE_STATE_START == DEM_GET_OPCYC_STATE(Dem_CfgEventTable[EventIdx].acIndHealingOpCycIdx[evtIndiIdx])))
                {
                    DEM_SET_INDICATOR(EventIdx, evtIndiIdx, FALSE);

                    /* Clear lampfailed counter when indicator healing. */
                    DEM_SET_LAMP_FAILED_CNT(EventIdx, evtIndiIdx, DEM_ZERO_VALUE);

                    indiOnCnt = DEM_GET_INDICATOR_ON_CNT(indiIdx);
                    if(DEM_INIT_ZERO == indiOnCnt)
                    {
                        DEM_SET_INDICATOR_STATUS(indiIdx, DEM_INDICATOR_OFF);
                    }
                    else
                    {
                        indiOnCnt--;
                        if(DEM_INIT_ZERO == indiOnCnt)
                        {
                            DEM_SET_INDICATOR_STATUS(indiIdx, DEM_INDICATOR_OFF);
                        }
#if( DEM_CFG_J1939SUPPORT == STD_ON )
                        else
                        {
                            for( evtIdx = DEM_INIT_ONE; evtIdx < DEM_CFG_EVENT_NUM; evtIdx++ )
                            {
                                if( TRUE == DEM_GET_INDICATOR(evtIdx, evtIndiIdx) )
                                {
                                    if( Dem_CfgEvtIndiBhv[EventIdx][evtIndiIdx] > DEM_GET_INDICATOR_STATUS(indiIdx) )
                                    {
                                        DEM_SET_INDICATOR_STATUS(indiIdx, Dem_CfgEvtIndiBhv[EventIdx][evtIndiIdx]);
                                    }
                                }
                            }
                        }
#endif
                        DEM_SET_INDICATOR_ON_CNT(indiIdx, indiOnCnt);
                    }
                }

                if(TRUE == DEM_GET_INDICATOR(EventIdx, evtIndiIdx))
                {
                    /* Only if all indicators off criteria of an event are fullfilled, clear bit7 WarningIndicator. */
                    ret = E_NOT_OK;
                }
            }
            else
            {
                break;
            }
        }
    }
    else
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        ret = E_NOT_OK;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCheckDtcFilterMatch
*
* Explanation: Check if match the DTC filter
*
* param: uint16 EventIdx, event index in event configure table
*
* retval: E_NOT_OK, not match; E_OK, match
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, DEM_CODE) Dem_EventCheckDtcFilterMatch
(
    uint16 EventIdx
)
{
    uint8 ret = E_OK;
    uint8 evtMemCnt;
    uint8 evtStatus = DEM_INIT_ZERO;
    sint8 fdcCnt = DEM_DEBOUNCE_COUNTER_NEG_ONE;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];

        /* Status mask is matched? */
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_DISABLED)
        evtStatus = DEM_GET_UDS_STATUS(EventIdx);
#else
        (void)Dem_EventGetCombStatusByte(EventIdx, &evtStatus);   
#endif
        /* If mask is 0x00, all DTCs are matched */
        if(((uint8)DEM_INIT_ZERO != DEM_GET_DTC_FILTER_MASK()) &&
           (DEM_INIT_ZERO == (evtStatus & DEM_GET_DTC_FILTER_MASK())))
        {
            ret = E_NOT_OK;
        }
        
        /* DTC kind is matched? */
        if((E_OK == ret) &&
           (DEM_DTC_KIND_EMISSION_REL_DTCS == DEM_GET_DTC_FILTER_KIND()) &&
            ((DEM_INIT_ZERO == Dem_CfgDTCTable[dtcIdx].acObdDtcIdx) &&
             (DEM_DTC_WWHOBD_CLASS_NOCLASS == Dem_CfgDTCTable[dtcIdx].acWwhObdClass)))
        {
            ret = E_NOT_OK;
        }

        if(E_OK == ret)
        {
            /* DTC Format is matched? */
            if(DEM_DTC_FORMAT_OBD == DEM_GET_DTC_FILTER_FORMAT())
            {
                if(DEM_INIT_ZERO == Dem_CfgDTCTable[dtcIdx].acObdDtcIdx)
                {
                    ret = E_NOT_OK;
                }
            }
            else
            {
                /* UDS formar is ok */
            }
        }

        if(E_OK == ret)
        {
            /* DTCorigin is matched? */
            ret = E_NOT_OK;
            for(evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++)
            {
                if(DEM_GET_DTC_FILTER_EVTMEMIDX() == Dem_CfgDTCTable[dtcIdx].acEvtMemIdx[evtMemCnt])
                {
                    ret = E_OK;
                    break;
                }
            }
        }
        
        /* Severity is considered */
        if((E_OK == ret) &&
           (TRUE == DEM_GET_DTC_FILTER_SEVERITY()) &&
           (DEM_GET_DTC_FILTER_SEVERITY_MASK() != (Dem_CfgDTCTable[dtcIdx].acDtcSeverity & DEM_GET_DTC_FILTER_SEVERITY_MASK())))
        {
            ret = E_NOT_OK;
        }
        
        /* FDC is considered */
        if((E_OK == ret) && (TRUE == DEM_GET_DTC_FILTER_FDC()))
        {
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT != DEM_EVCOMB_DISABLED)
            (void)Dem_EventGetCombFDC(EventIdx, &fdcCnt);
#else
            fdcCnt = DEM_GET_FDCCNT(EventIdx);
#endif
            if((fdcCnt <= (sint8)DEM_DEBOUNCE_COUNTER_ZERO) ||
               ((sint8)DEM_DEBOUNCE_FDC_HIGH_THRESHOLD == fdcCnt))
            {
                ret = E_NOT_OK;
            }
        }
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCheckDtcSettingDisable
*
* Explanation: Check the dtc clear parameter
*
* param: uint16 EventIdx, event index
*
* retval: E_OK, disable DTC setting; E_NOT_OK, enable DTC setting
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EventCheckDtcSettingDisable
(
    uint16 EventIdx
)
{
    Std_ReturnType ret = E_OK;
#if(DEM_CFG_DTC_GROUP_NUM > 0U)
    uint8 dtcGrpIdx;
#endif
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (TRUE == DEM_GET_DTC_SETTING_DISABLE()))
    {
        if(DEM_EVENT_DTC_GROUP_ALL == DEM_GET_DTC_DISABLE_GROUP())
        {
            if(DEM_DTC_KIND_EMISSION_REL_DTCS == DEM_GET_DTC_DISABLE_KIND())
            {
                dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
                if((DEM_INIT_ZERO == Dem_CfgDTCTable[dtcIdx].acObdDtcIdx) &&
                   (DEM_DTC_WWHOBD_CLASS_NOCLASS == Dem_CfgDTCTable[dtcIdx].acWwhObdClass))
                {
                    ret = E_NOT_OK;
                }
            }
        }
        else
        {
#if(DEM_CFG_DTC_GROUP_NUM > 0U)
            dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
            dtcGrpIdx = DEM_GET_DTC_DISABLE_GROUP_IDX();
            if((dtcGrpIdx > DEM_INIT_ZERO) && (dtcGrpIdx < DEM_CFG_DTC_GROUP_NUM))
            {
                if((DEM_DTCVALUE_CAL(dtcIdx) >= Dem_CfgDTCGrpTable[dtcGrpIdx]) &&
                   (DEM_DTCVALUE_CAL(dtcIdx) < Dem_CfgDTCGrpTable[dtcGrpIdx + DEM_BYTE_ONE]))
                {
                    if(DEM_DTC_KIND_EMISSION_REL_DTCS == DEM_GET_DTC_DISABLE_KIND())
                    {
                        if((DEM_INIT_ZERO == Dem_CfgDTCTable[dtcIdx].acObdDtcIdx) &&
                           (DEM_DTC_WWHOBD_CLASS_NOCLASS == Dem_CfgDTCTable[dtcIdx].acWwhObdClass))
                        {
                            ret = E_NOT_OK;
                        }
                    }
                }
            }
#endif
        }
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCheckIndicatorStator
*
* Explanation: check the indicator status of an event
*
* param: uint16 EventIdx, event index of configure table
*        uint8 IndicatorIdx, indicator index of event refered
*
* retval: TRUE, indicator on; FALSE indicator off
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(boolean, DEM_CODE) Dem_EventCheckIndicatorStator
(
    uint16 EventIdx, 
    uint8 IndicatorIdx
)
{
    boolean ret = FALSE;
    uint8 evtIndiIdx;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        for(evtIndiIdx = DEM_INIT_ZERO; evtIndiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; evtIndiIdx++)
        {
            if(Dem_CfgEventTable[EventIdx].acIndiIdx[evtIndiIdx] > DEM_INIT_ZERO)
            {
                if(IndicatorIdx == Dem_CfgEventTable[EventIdx].acIndiIdx[evtIndiIdx])
                {
                    if((DEM_GET_INDICATOR_STATUS(IndicatorIdx) >= DEM_INDICATOR_CONTINUOUS) &&
                       (DEM_GET_INDICATOR_STATUS(IndicatorIdx) <= DEM_INDICATOR_SHORT))
                    {
                        ret = TRUE;
                    }
                    break;
                }
            }
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventClearAllowedCbk
*
* Explanation: call the callback function of DemCallbackClearAllowed_p
*
* param: uint16 evtIdx: Event index in event configuration table
*
* retval: boolean, clear is allowed or not
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(boolean, DEM_CODE) Dem_EventClearAllowedCbk
(
    uint16 EventIdx
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    boolean allowed = TRUE;
    
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(NULL_PTR != Dem_CfgEventTable[EventIdx].DemCallbackClearAllowed_p)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            if(E_NOT_OK == Dem_CfgEventTable[EventIdx].DemCallbackClearAllowed_p(&allowed))
            {
                allowed = TRUE;
            }
        }
        else
        {
            allowed = TRUE;
        }
    }
    else
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        allowed = FALSE;
    }

    return allowed;
}

/*
********************************************************************************
* Function Name: Dem_EventTriggerGetFDCCbk
*
* Explanation: call the callback function of DemCallbackGetFDC
*
* param: uint16 evtIdx: Event index in event configuration table
*        sint8 *cnt: FDC counter
*
* retval: None
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EventTriggerGetFDCCbk
(
    uint16 EventIdx, 
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) cnt
)
{
    Std_ReturnType ret = E_NOT_OK;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(NULL_PTR != Dem_CfgEventTable[EventIdx].DemCallbackGetFDC)
        {
            ret = Dem_CfgEventTable[EventIdx].DemCallbackGetFDC(cnt);
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventTriggerInitMonitorCbk
*
* Explanation: call the callback function of DemCallbackInitMonitor_p
*
* param: uint16 evtIdx: Event index in event configuration table
*        Dem_InitMonitorReasonType reason: reason of trigger callback
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventTriggerInitMonitorCbk
(
    uint16 EventIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    Dem_InitMonitorReasonType reason
)
{
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(NULL_PTR != Dem_CfgEventTable[EventIdx].DemCallbackInitMonitor_p)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            Dem_CfgEventTable[EventIdx].DemCallbackInitMonitor_p(reason);
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventTriggerEventDataChangedCbk
*
* Explanation: call the callback function of DemCallbackEventDataChanged_p
*
* param: uint16 evtIdx: Event index in event configuration table
*        Dem_UdsStatusByteType oldStatus: old event status
*        Dem_UdsStatusByteType newStatus: new event status
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventTriggerEventDataChangedCbk
(
    uint16 EventIdx
)
{
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(NULL_PTR != Dem_CfgEventTable[EventIdx].DemCallbackEventDataChanged_p)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            Dem_CfgEventTable[EventIdx].DemCallbackEventDataChanged_p(Dem_CfgEventTable[EventIdx].awEvtId);
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventTriggerEventStatusChangedCbk
*
* Explanation: call the callback function of DemCallbackEventStatusChanged_p
*
* param: uint16 evtIdx: Event index in event configuration table
*        Dem_UdsStatusByteType oldStatus: old event status
*        Dem_UdsStatusByteType newStatus: new event status
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventTriggerEventStatusChangedCbk
(
    uint16 EventIdx,
    Dem_UdsStatusByteType OldStatus,
    Dem_UdsStatusByteType NewStatus
)
{
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(NULL_PTR != Dem_CfgEventTable[EventIdx].DemCallbackEventStatusChanged_p)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            Dem_CfgEventTable[EventIdx].DemCallbackEventStatusChanged_p(Dem_CfgEventTable[EventIdx].awEvtId, OldStatus, NewStatus);
        }
#if(DEM_CFG_TRIGGERDLTREPORT == STD_ON)
        Dlt_DemTriggerOnEventStatus(Dem_CfgEventTable[EventIdx].awEvtId, OldStatus, NewStatus);
#endif
#if(DEM_CFG_TRIGGERFIMREPORT == STD_ON)
        FiM_DemTriggerOnEventStatus(Dem_CfgEventTable[EventIdx].awEvtId, OldStatus, NewStatus);
#endif
    }
}

#if(DEM_CFG_GENERALINTERFACESUPPORT == STD_ON)
/*
********************************************************************************
* Function Name: Dem_GeneralEventTriggerEventStatusChangedCbk
*
* Explanation: The interfaces GeneralEvtInfo, GeneralCallbackEventDataChanged
*              and GeneralCallbackEventStatusChange are provided if
*              DemGeneralInterfaceSupport is equal to true. [ECUC_Dem_00880]
*
* param: uint16 evtIdx: Event index in event configuration table
*        Dem_UdsStatusByteType oldStatus: old event status
*        Dem_UdsStatusByteType newStatus: new event status
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_GeneralEventTriggerEventStatusChangedCbk
(
    uint16 EventIdx, 
    Dem_UdsStatusByteType OldStatus,
    Dem_UdsStatusByteType NewStatus
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 eventId;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        eventId = Dem_CfgEventTable[EventIdx].awEvtId;
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:USELESS_IF [JUstified:Unset] "NSCA_Polyspace_Common_UselessIf" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(eventId <= DEM_CFG_EVENT_ID_MAX)
        {
            /*Call the Rte interface of EventStatusChanged. */
            /* PolySpace +1 MISRA-C3:17.7 [Justified:Unset] "NSCA_Polyspace_Dem_17.7" */
            Dem_GeneralCallbackEventStatusChange(eventId, OldStatus, NewStatus);  /* PRQA S 3200 */ /* NSCA_QAC_Dem_Rule17.7 */
        }
    }
}
#endif

/*
********************************************************************************
* Function Name: Dem_EventTriggerDtcChangedNotificationCbk
*
* Explanation: call the callback function of Dcm_DemTriggerOnDTCStatus
*
* param: uint16 evtIdx: Event index in event configuration table
*        Dem_InitMonitorReasonType reason: reason of trigger callback
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventTriggerDtcStatusChangedCbk
(
    uint16 EventIdx,
    Dem_UdsStatusByteType OldStatus,
    Dem_UdsStatusByteType NewStatus
)
{
    uint8 cbkCnt = DEM_INIT_ZERO;

#if( DEM_CFG_J1939SUPPORT == STD_ON )
    uint8 node = DEM_INIT_ZERO;
#endif

    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx = DEM_INIT_ZERO;
    uint32 dtcVal = DEM_INIT_ZERO;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( (EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) )
    {
        dtcIdx =  Dem_CfgEvtDtcIdx[EventIdx];
        dtcVal = DEM_DTCVALUE_CAL(dtcIdx);

        /* [SWS_Dem_01050] */
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT != DEM_EVCOMB_DISABLED)
        (void)Dem_EventGetCombStatusByteByOld(EventIdx, &OldStatus);
        (void)Dem_EventGetCombStatusByte(EventIdx, &NewStatus);
#endif
        if( OldStatus != NewStatus )
        {
#if( DEM_CFG_J1939SUPPORT == STD_ON )
            node = DEM_GET_J1939_DTC_NODE();
            if( (Dem_CfgDTCTable[dtcIdx].acObdDtcIdx > DEM_INIT_ZERO) &&
                (Dem_CfgObdDTCTable[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx].awJ1939DtcVal != DEM_DEF_J1939DTC) )
            {
                for( cbkCnt = DEM_INIT_ONE; cbkCnt <= DEM_CFG_J1939DTC_STATUS_CHANGED_CALLBACK_NUM; cbkCnt++ )
                {
                    if( NULL_PTR != Dem_CfgJ1939DTCStatusChangedPtrTable[cbkCnt].DemCallbackDTCStatusChanged_p )
                    {
                        Dem_CfgJ1939DTCStatusChangedPtrTable[cbkCnt].DemCallbackDTCStatusChanged_p(dtcVal, OldStatus, NewStatus);
                    }
                }
                if( (DEM_UDS_STATUS_TF == (NewStatus & DEM_UDS_STATUS_TF)) && 
                    ((OldStatus & DEM_UDS_STATUS_TF) != DEM_UDS_STATUS_TF) )  /* only TF changed*/
                {
                    J1939Dcm_DemTriggerOnDTCStatus(dtcVal, node);
                }
            }
#endif

            for( cbkCnt = DEM_INIT_ONE; cbkCnt <= DEM_CFG_DTC_STATUS_CHANGED_CALLBACK_NUM; cbkCnt++ )
            {
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                if( NULL_PTR != Dem_CfgDTCStatsuChangedPtrTable[cbkCnt].DemCallbackDTCStatusChanged_p )
                {
                    Dem_CfgDTCStatsuChangedPtrTable[cbkCnt].DemCallbackDTCStatusChanged_p(dtcVal, OldStatus, NewStatus);
                }
            }

            if( (Dem_CfgDTCTable[dtcIdx].acObdDtcIdx > DEM_INIT_ZERO) ||
                (Dem_CfgDTCTable[dtcIdx].acWwhObdClass > DEM_DTC_WWHOBD_CLASS_NOCLASS) )
            {
                /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                for( cbkCnt = DEM_INIT_ONE; cbkCnt <= DEM_CFG_OBDDTC_STATUS_CHANGED_CALLBACK_NUM; cbkCnt++ )
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    if( NULL_PTR != Dem_CfgObdDTCStatusChangedPtrTable[cbkCnt].DemCallbackDTCStatusChanged_p )
                    {
                        Dem_CfgObdDTCStatusChangedPtrTable[cbkCnt].DemCallbackDTCStatusChanged_p(dtcVal, OldStatus, NewStatus);
                    }
                }
            }

            if( TRUE == DEM_GET_DTCCHANGEDNOTIF() )
            {

#if( DEM_CFG_TRIGGERDCMREPORT == STD_ON )
                (void)Dcm_DemTriggerOnDTCStatus(dtcVal, OldStatus, NewStatus);
#endif

            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventTriggerDtcChangedNotificationCbk
*
* Explanation: call the callback function of Dcm_DemTriggerOnDTCStatus
*
* param: uint16 evtIdx: Event index in event configuration table
*        Dem_InitMonitorReasonType reason: reason of trigger callback
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventTriggerComponentFailedChangedCbk
(
    uint16 EventCompIdx, 
    boolean EventCompSt
)
{
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventCompIdx > DEM_INIT_ZERO) && (EventCompIdx <= DEM_CFG_COMP_NUM))
    {
        /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(NULL_PTR != Dem_ConfigComponentTable[EventCompIdx].DemComponentFailedCallbackFnc)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            Dem_ConfigComponentTable[EventCompIdx].DemComponentFailedCallbackFnc(EventCompIdx, EventCompSt);
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventCalcOccurenceCounter
*
* Explanation: Calculate the occurence counter
*
* param: uint16 EventIdx, Event index in event configuration table
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventCalcOccurenceCounter
(
    uint16 EventIdx
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 evtMemCnt, evtMemIdx, entryIdx;
    Dem_EventMemoryEntry_st *entry_ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        for(evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++)
        {
            evtMemIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acEvtMemIdx[evtMemCnt];

            if(evtMemIdx > DEM_INIT_ZERO)
            {
                if(TRUE == DEM_GET_EVENT_STORED(EventIdx, evtMemIdx))
                {
                    entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);
                    entryIdx = DEM_GET_EVENT_ENTRY(EventIdx, evtMemIdx);

                    if(TRUE == DEM_GET_UDS_STATUS_TF(EventIdx))
                    {
#if(DEM_CFG_OCCURRENCECOUNTERPROCESSING == DEM_PROCESS_OCCCTR_CDTC)
                        if(TRUE == DEM_GET_UDS_STATUS_CDTC(EventIdx))
                        {
                            if(DEM_BYTE_MAX > entry_ptr[entryIdx].cntOcc)
                            {
                                entry_ptr[entryIdx].cntOcc++;
                            }
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
                            if(DEM_WORD_MAX > entry_ptr[entryIdx].cntOcc2)
                            {
                                entry_ptr[entryIdx].cntOcc2++;
                            }
#endif
                        }
#else
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                        if(DEM_BYTE_MAX > entry_ptr[entryIdx].cntOcc)
                        {
                            entry_ptr[entryIdx].cntOcc++;
                        }
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
                        if(DEM_WORD_MAX > entry_ptr[entryIdx].cntOcc2)
                        {
                            entry_ptr[entryIdx].cntOcc2++;
                        }
#endif
#endif
                    }
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventCalcDtcStatus
*
* Explanation: Calculate the DTC status by DTC value
*
* param: uint32 DTC, DTC value
*        uint8 *EventStatus, to hold the DTC status value
*
* retval: E_NOT_OK, in calculating; E_OK, calculation finished
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventCalcDtcStatus
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC, 
    uint8 EventMemIdx, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) EventStatus
)
{
    uint8 ret = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */   
    uint16 evtIdx, dtcIdx;

    if((EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM))
    {
#if(DEM_CFG_DTC_NUM <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
        for(dtcIdx = (Dem_EventCalcDtcCnt + DEM_BYTE_ONE); dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++)
        {
            evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[DEM_INIT_ZERO];
            if(DTC == DEM_DTCVALUE_CAL(dtcIdx))
            {
                /* Record the current diagnostic service processed DTC index. */
                DEM_SET_DIAG_PROC_DTC_IDX(dtcIdx);
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
                {
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_DISABLED)
                    *EventStatus = DEM_GET_UDS_STATUS(evtIdx);
#else
                    (void)Dem_EventGetCombStatusByte(evtIdx, EventStatus);   
#endif
                }
                else
                {
                    *EventStatus = DEM_EVENT_DTC_STATUS_INVALID;
                }
#else
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_DISABLED)
                *EventStatus = DEM_GET_UDS_STATUS(evtIdx);
#else
                (void)Dem_EventGetCombStatusByte(evtIdx, EventStatus);   
#endif
#endif
                ret = E_OK;
                break;
            }
        }

        if(E_NOT_OK == ret)
        {
            /* DTC not exist, set DTCstatus to 0xFF */
            *EventStatus = DEM_EVENT_DTC_STATUS_INVALID;
            ret = E_OK;
        }
/* In case of number of event memory entry is large */
#else
        if((DEM_CFG_DTC_NUM - Dem_EventCalcDtcCnt) >= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
        {
            for(dtcIdx = (Dem_EventCalcDtcCnt + DEM_BYTE_ONE); dtcIdx <= (Dem_EventCalcDtcCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM); dtcIdx++)
            {
                evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[DEM_INIT_ZERO];
                if(DTC == DEM_DTCVALUE_CAL(dtcIdx))
                {
                    /* Record the current diagnostic service processed DTC index. */
                    DEM_SET_DIAG_PROC_DTC_IDX(dtcIdx);
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
                    {
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_DISABLED)
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                        *EventStatus = DEM_GET_UDS_STATUS(evtIdx);
#else
                        (void)Dem_EventGetCombStatusByte(evtIdx, EventStatus);   
#endif
                    }
                    else
                    {
                        *EventStatus = DEM_EVENT_DTC_STATUS_INVALID;
                    }
#else
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_DISABLED)
                    *EventStatus = DEM_GET_UDS_STATUS(evtIdx);
#else
                    (void)Dem_EventGetCombStatusByte(evtIdx, EventStatus);   
#endif
#endif
                    ret = E_OK;
                    break;
                }
            }
        }
        else
        {
            for(dtcIdx = (Dem_EventCalcDtcCnt + DEM_BYTE_ONE); dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++)
            {
                evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[DEM_INIT_ZERO];
                if(DTC == DEM_DTCVALUE_CAL(dtcIdx))
                {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
                    {
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_DISABLED)
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                        *EventStatus = DEM_GET_UDS_STATUS(evtIdx);
#else
                        (void)Dem_EventGetCombStatusByte(evtIdx, EventStatus);   
#endif
                    }
                    else
                    {
                        *EventStatus = DEM_EVENT_DTC_STATUS_INVALID;
                    }
#else
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_DISABLED)
                    *EventStatus = DEM_GET_UDS_STATUS(evtIdx);
#else
                    (void)Dem_EventGetCombStatusByte(evtIdx, EventStatus);   
#endif
#endif
                    ret = E_OK;
                    break;
                }
            }
        }
        
        if(E_OK == ret)
        {
            /* Initialize the static local variable */
            Dem_EventCalcDtcCnt = DEM_INIT_ZERO;
        }
        else
        {
            if(dtcIdx > DEM_CFG_DTC_NUM)
            {
                /* Initialize the static local variable */
                Dem_EventCalcDtcCnt = DEM_INIT_ZERO;
                /* DTC not exist, set DTCstatus to 0xFF */
                *EventStatus = DEM_EVENT_DTC_STATUS_INVALID;
                ret = E_OK;
            }
            else
            {
                Dem_EventCalcDtcCnt += DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
            }
        }
#endif
    }
    else
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        ret = E_OK;
        *EventStatus = DEM_EVENT_DTC_STATUS_INVALID;
    }
    
    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCalcDTCIndexFromDTC
*
* Explanation: Calculate the DTC index by DTC value
*
* param: uint32 DTC, DTC value
*        uint8 DTCFormat, dtc format
*        uint16 *dtcIdx, to hold the DTC index value
*
* retval: E_NOT_OK, in calculating; E_OK, calculation finished
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventCalcDTCIndexFromDTC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC, 
    uint8 DTCFormat, 
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) DtcIdx
)
{
    uint8 ret = E_NOT_OK;
    uint16 dtcIdxVal;

    if(DtcIdx != NULL_PTR)
    {
#if(DEM_CFG_DTC_NUM <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
        if( DEM_DTC_FORMAT_UDS == DTCFormat )
        {
            for(dtcIdxVal = (Dem_EventCalcDTCIndexDtcCnt + DEM_INIT_ONE); dtcIdxVal <= DEM_CFG_DTC_NUM; dtcIdxVal++)
            {
                if(DTC == DEM_DTCVALUE_CAL(dtcIdxVal))
                {
                    ret = E_OK;
                    break;
                }
            }
        }
#if( DEM_CFG_J1939SUPPORT == STD_ON )
        else if( DEM_DTC_FORMAT_J1939 == DTCFormat )
        {
            for( dtcIdxVal = (Dem_EventCalcDTCIndexDtcCnt + DEM_INIT_ONE); dtcIdxVal <= DEM_CFG_DTC_NUM; dtcIdxVal++ )
            {
                if( DTC == Dem_CfgObdDTCTable[Dem_CfgDTCTable[dtcIdxVal].acObdDtcIdx].awJ1939DtcVal )
                {
                    ret = E_OK;
                    break;
                }
            }
        }
#endif
        else
        {
            dtcIdxVal = DEM_INIT_ZERO;
        }

        if((dtcIdxVal > DEM_CFG_DTC_NUM) || (E_NOT_OK == ret))
        {
            *DtcIdx = DEM_INIT_ZERO;
            ret = E_OK;
        }
        else
        {
            *DtcIdx = dtcIdxVal;
        }
#else
        if(((DEM_CFG_DTC_NUM - Dem_EventCalcDTCIndexDtcCnt) > DEM_EVENT_DTC_SPILT_SEGMENT_NUM))
        {
            if(DTCFormat == DEM_DTC_FORMAT_UDS)
            {
                for(dtcIdxVal = (Dem_EventCalcDTCIndexDtcCnt + DEM_INIT_ONE); dtcIdxVal <= (Dem_EventCalcDTCIndexDtcCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM); dtcIdxVal++)
                {
                    if(DTC == DEM_DTCVALUE_CAL(dtcIdxVal))
                    {
                        ret = E_OK;
                        break;
                    }
                }
            }
#if( DEM_CFG_J1939SUPPORT == STD_ON )
            else if( DTCFormat == DEM_DTC_FORMAT_J1939 )
            {
                for(dtcIdxVal = (Dem_EventCalcDTCIndexDtcCnt + DEM_INIT_ONE); dtcIdxVal <= (Dem_EventCalcDTCIndexDtcCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM); dtcIdxVal++)
                {
                    if( DTC == Dem_CfgObdDTCTable[Dem_CfgDTCTable[dtcIdxVal].acObdDtcIdx].awJ1939DtcVal )
                    {
                        ret = E_OK;
                        break;
                    }
                }
            }
#endif  
            else
            {
                dtcIdxVal = DEM_CFG_DTC_NUM + DEM_BYTE_ONE;
            }
        }
        else
        {
            for(dtcIdxVal = (Dem_EventCalcDTCIndexDtcCnt + DEM_INIT_ONE); dtcIdxVal <= DEM_CFG_DTC_NUM; dtcIdxVal++)
            {
                if(DTC == DEM_DTCVALUE_CAL(dtcIdxVal))
                {
                    ret = E_OK;
                    break;
                }
            }
        }

        if(E_OK == ret)
        {
            *DtcIdx = dtcIdxVal;
             /* Initialize the static local variable */
             Dem_EventCalcDTCIndexDtcCnt = DEM_INIT_ZERO;
        }
        else
        {
            if(dtcIdxVal > DEM_CFG_DTC_NUM)
            {
                *DtcIdx = DEM_INIT_ZERO;
                /* Initialize the static local variable */
                Dem_EventCalcDTCIndexDtcCnt = DEM_INIT_ZERO;
                ret = E_OK;
            }
            else
            {
                Dem_EventCalcDTCIndexDtcCnt += DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
            }
        }
#endif
    }
    else
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        ret = E_OK;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCalcDtcFilteredNum
*
* Explanation: Calculate the DTC number matching the filter
*
* param: none
*
* retval: E_NOT_OK, in calculating; E_OK, calculation finished
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventCalcDtcFilteredNum(void)
{
    uint8 ret = E_NOT_OK;
    uint8 slotIdx;
    uint8 slotCnt;
    uint16 numMatchedDtc;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx;
    Dem_EventMemoryInfo_st *info_ptr;

#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    if(DEM_DTC_ORIGIN_PERMANENT_MEMORY == DEM_GET_DTC_FILTER_ORIGIN())
    {
        if((DEM_DTC_KIND_EMISSION_REL_DTCS == DEM_GET_DTC_FILTER_KIND()) && 
           (FALSE == DEM_GET_DTC_FILTER_SEVERITY()) &&
           (FALSE == DEM_GET_DTC_FILTER_FDC()))
        {
            numMatchedDtc = Dem_ObdGetPfcNum();
            DEM_SET_DTC_FILTER_MATCH_NUM(numMatchedDtc);
            ret = E_OK;
        }
           
    }
    else
#endif
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(DEM_GET_DTC_FILTER_EVTMEMIDX());
        slotCnt = DEM_GET_DTC_FILTER_SLOT_CNT();
        numMatchedDtc = DEM_GET_DTC_FILTER_MATCH_NUM();
        
#if(DEM_CFG_MAX_NUMBER_EVENT_ENTRY <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
        for(slotIdx = slotCnt; slotIdx < info_ptr->cntEnSlot; slotIdx++)
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
            dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
            {
                if((E_OK == Dem_EventCheckDtcFilterMatch(evtIdx)) &&
                   (FALSE == DEM_GET_DTC_FILTERED(dtcIdx)))
                {
                    DEM_SET_DTC_FILTERED(dtcIdx, TRUE);
                    numMatchedDtc++;
                }
            }
        }

        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if(slotIdx >= info_ptr->cntEnSlot)
        {
            ret = E_OK;
        }
#else
        if((info_ptr->cntEnSlot - slotCnt) > DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
        {
            for(slotIdx = slotCnt; slotIdx < (slotCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM); slotIdx++)
            {
                evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                {
                    if((E_OK == Dem_EventCheckDtcFilterMatch(evtIdx)) &&
                       (FALSE == DEM_GET_DTC_FILTERED(dtcIdx)))
                    {
                        DEM_SET_DTC_FILTERED(dtcIdx, TRUE);
                        numMatchedDtc++;
                    }
                }
            }
        }
        else
        {
            for(slotIdx = slotCnt; slotIdx < info_ptr->cntEnSlot; slotIdx++)
            {
                evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                {
                    if((E_OK == Dem_EventCheckDtcFilterMatch(evtIdx)) &&
                       (FALSE == DEM_GET_DTC_FILTERED(dtcIdx)))
                    {
                        DEM_SET_DTC_FILTERED(dtcIdx, TRUE);
                        numMatchedDtc++;
                    }
                }
            }
        }

        if(slotIdx >= info_ptr->cntEnSlot)
        {
            slotCnt = DEM_INIT_ZERO;
            ret = E_OK;
        }
        else
        {
            slotCnt += DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
        }
#endif
        DEM_SET_DTC_FILTER_SLOT_CNT(slotCnt);
        DEM_SET_DTC_FILTER_MATCH_NUM(numMatchedDtc);
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCalcDtcFilteredNum
*
* Explanation: Calculate the DTC number of all supported DTC
*
* param: none
*
* retval: E_NOT_OK, in calculating; E_OK, calculation finished
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventCalcDtcFilteredAllSupportedNum(void)
{
    uint8 ret = E_NOT_OK;
    uint16 numMatchedDtc;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 filterCnt;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx;
    
    filterCnt = DEM_GET_DTC_FILTER_MATCH_CNT();
    numMatchedDtc = DEM_GET_DTC_FILTER_MATCH_NUM();

#if(DEM_CFG_DTC_NUM <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
    {
        for(dtcIdx = (filterCnt + (uint16)DEM_BYTE_ONE); dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++)
        {
            evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[DEM_INIT_ZERO];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
            if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
            {
                if((E_OK == Dem_EventCheckDtcFilterMatch(evtIdx)) &&
                   (FALSE == DEM_GET_DTC_FILTERED(dtcIdx)))
                {
                    DEM_SET_DTC_FILTERED(dtcIdx, TRUE);
                    numMatchedDtc++;
                }
            }
        }

        ret = E_OK;
    }
#else
    {
        if((DEM_CFG_DTC_NUM - filterCnt) > DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
        {
            for(dtcIdx = (filterCnt + DEM_BYTE_ONE); dtcIdx <= (filterCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM); dtcIdx++)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[DEM_INIT_ZERO];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                {
                    if((E_OK == Dem_EventCheckDtcFilterMatch(evtIdx)) &&
                       (FALSE == DEM_GET_DTC_FILTERED(dtcIdx)))
                    {
                        DEM_SET_DTC_FILTERED(dtcIdx, TRUE);
                        numMatchedDtc++;
                    }
                }
            }
        }
        else
        {
            for(dtcIdx = (filterCnt + DEM_BYTE_ONE); dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++)
            {
                evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[DEM_INIT_ZERO];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                {
                    if((E_OK == Dem_EventCheckDtcFilterMatch(evtIdx)) &&
                       (FALSE == DEM_GET_DTC_FILTERED(dtcIdx)))
                    {
                        DEM_SET_DTC_FILTERED(dtcIdx, TRUE);
                        numMatchedDtc++;
                    }
                }
            }
        }

        if(dtcIdx > DEM_CFG_DTC_NUM)
        {
            filterCnt = DEM_INIT_ZERO;
            ret = E_OK;
        }
        else
        {
            filterCnt += DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
        }
    }
#endif

    DEM_SET_DTC_FILTER_MATCH_CNT(filterCnt);
    DEM_SET_DTC_FILTER_MATCH_NUM(numMatchedDtc);

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCalcDtcNextFilteredAllSupported
*
* Explanation: Calculate the DTC number of all supported DTC
*
* param: none
*
* retval: E_NOT_OK, in calculating; E_OK, calculation finished
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventCalcDtcNextFilteredAllSupported
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
)
{
    uint8 ret = E_NOT_OK;
    uint16 numMatchedDtcNext;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 filterCnt;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx;
    
    filterCnt = DEM_GET_DTC_FILTER_MATCH_CNT();
    numMatchedDtcNext = DEM_GET_DTC_FILTER_MATCH_NEXTIDX();

    if((DTC != NULL_PTR) && (DTCStatus != NULL_PTR))
    {
#if(DEM_CFG_DTC_NUM <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
        for(dtcIdx = (uint16)(numMatchedDtcNext + DEM_BYTE_ONE); dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++)
        {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
            if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
            {
                if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                {
                    DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                    break;
                }
            }
        }

        if(dtcIdx > DEM_CFG_DTC_NUM)
        {
            DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
            numMatchedDtcNext = DEM_INIT_ZERO;
        }
        else
        {
            evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[DEM_INIT_ZERO];
            numMatchedDtcNext = dtcIdx;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_DISABLED)
            *DTCStatus = DEM_GET_UDS_STATUS(evtIdx);
#else
            (void)Dem_EventGetCombStatusByte(evtIdx, DTCStatus);   
#endif
            /* DTC format conversion. */
            if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT())
            {
                *DTC = DEM_DTCVALUE_CAL(dtcIdx);
            }
            else
            {
                *DTC = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
            }

        }
        ret = E_OK;
#else
        if((DEM_CFG_DTC_NUM - filterCnt) > DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
        {
            for(dtcIdx = (numMatchedDtcNext + DEM_BYTE_ONE); dtcIdx <= (filterCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM); dtcIdx++)
            {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                {
                    if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                    {
                        DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                        break;
                    }
                }
            }
        }
        else
        {
            for(dtcIdx = (numMatchedDtcNext + DEM_BYTE_ONE); dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++)
            {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                {
                    if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                    {
                        DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                        break;
                    }
                }
            }
        }

        if(dtcIdx > DEM_CFG_DTC_NUM)
        {
            filterCnt = DEM_INIT_ZERO;
            numMatchedDtcNext = DEM_INIT_ZERO;
            DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
            ret = E_OK;
        }
        else
        {
            if(dtcIdx > (filterCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM))
            {
                numMatchedDtcNext = filterCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
                filterCnt += DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
            }
            else
            {
                evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[DEM_INIT_ZERO];
                numMatchedDtcNext = dtcIdx;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_DISABLED)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                *DTCStatus = DEM_GET_UDS_STATUS(evtIdx);
#else
                (void)Dem_EventGetCombStatusByte(evtIdx, DTCStatus);   
#endif
                /* DTC format conversion */
                if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT())
                {
                    *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                }
                else
                {
                    *DTC = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
                }
                ret = E_OK;
            }
        }
#endif
    }
    else
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        ret = E_OK;
    }

    DEM_SET_DTC_FILTER_MATCH_CNT(filterCnt);
    DEM_SET_DTC_FILTER_MATCH_NEXTIDX(numMatchedDtcNext);

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCalcDtcNextFiltered
*
* Explanation: Calculate the next filtered DTC
*
* param: uint32 *dtc, to hole the matched DTC value
*        uint8 *dtcStatus, to hole the dtc status byte
*
* retval: E_NOT_OK, in calculating; E_OK, calculation finished
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventCalcDtcNextFiltered
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
)
{
    boolean dtcMatched = FALSE;
    uint8 ret = E_NOT_OK;
    uint8 slotIdx;
    uint16 evtIdx = DEM_INIT_ZERO;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx = DEM_INIT_ZERO;
    uint8 numMatchedDtcNext;
    Dem_EventMemoryInfo_st *info_ptr;

    if((DTC != NULL_PTR) && (DTCStatus != NULL_PTR))
    {
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
        if(DEM_DTC_ORIGIN_PERMANENT_MEMORY == DEM_GET_DTC_FILTER_ORIGIN())
        {
            if((DEM_DTC_KIND_EMISSION_REL_DTCS == DEM_GET_DTC_FILTER_KIND()) && 
               (FALSE == DEM_GET_DTC_FILTER_SEVERITY()) &&
               (FALSE == DEM_GET_DTC_FILTER_FDC()))
            {
                numMatchedDtcNext = (uint8)DEM_GET_DTC_FILTER_MATCH_NEXTIDX();
                if(numMatchedDtcNext < Dem_ObdGetPfcNum())
                {
                    /* Check the returned DTC format. */
                    if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT())
                    {
                        /* Return the UDS DTC value. */
                        evtIdx = Dem_ObdGetPfcEvtIdx(numMatchedDtcNext);
                        dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
                        *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                    }
                    else
                    {
                        /* Return the OBD DTC value. */
                        *DTC = Dem_ObdGetPfcVal(numMatchedDtcNext);
                    }
                    *DTCStatus = Dem_ObdGetPfcStatus(numMatchedDtcNext);
                    numMatchedDtcNext++;
                    DEM_SET_DTC_FILTER_MATCH_NEXTIDX(numMatchedDtcNext);
                }
                else
                {
                    numMatchedDtcNext = DEM_INIT_ZERO;
                    DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
                    DEM_SET_DTC_FILTER_MATCH_NEXTIDX(numMatchedDtcNext);
                }
                
                ret = E_OK;
            }
        }
        else
#endif
        {
            /* [SWS_Dem_00653], for following DTCKind and Mask, Calculation will not consider spilt */
            if((DEM_DTC_KIND_EMISSION_REL_DTCS == DEM_GET_DTC_FILTER_KIND()) && 
               ((DEM_UDS_STATUS_PDTC ==DEM_GET_DTC_FILTER_MASK()) ||
                (DEM_UDS_STATUS_CDTC ==DEM_GET_DTC_FILTER_MASK())))
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(DEM_GET_DTC_FILTER_EVTMEMIDX());
                numMatchedDtcNext = (uint8)DEM_GET_DTC_FILTER_MATCH_NEXTIDX();
                
                for(slotIdx = numMatchedDtcNext; slotIdx < info_ptr->cntEnSlot; slotIdx++)
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                    evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
                    dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                    if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                    {
                        if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                        {
                            DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                            dtcMatched = TRUE;
                            break;
                        }
                    }
                }

                if(FALSE == dtcMatched)
                {
                    DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
                    numMatchedDtcNext = DEM_INIT_ZERO;
                    ret = E_OK;
                }
                else
                {
                    numMatchedDtcNext = slotIdx + DEM_BYTE_ONE;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_DISABLED)
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                    *DTCStatus = DEM_GET_UDS_STATUS(evtIdx);
#else
                    (void)Dem_EventGetCombStatusByte(evtIdx, DTCStatus);   
#endif
                    if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT())
                    {
                        *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                    }
                    else
                    {
                        *DTC = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
                    }
                    ret = E_OK;
                }
                
                DEM_SET_DTC_FILTER_MATCH_NEXTIDX(numMatchedDtcNext);
            }
            else
            {
                ret = Dem_EventCalcDtcNextFilteredSpilt(DTC, DTCStatus);
            }

        }
    }
    else
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        ret = E_OK;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCalcDtcNextFilteredSpilt
*
* Explanation: Calculate the next filtered DTC
*
* param: uint32 *dtc, to hole the matched DTC value
*        uint8 *dtcStatus, to hole the dtc status byte
*
* retval: E_NOT_OK, in calculating; E_OK, calculation finished
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, DEM_CODE) Dem_EventCalcDtcNextFilteredSpilt
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
)
{
    boolean dtcMatched = FALSE;
    uint8 ret = E_NOT_OK;
    uint8 slotIdx;
    uint8 slotCnt;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx = DEM_INIT_ZERO, dtcIdx = DEM_INIT_ZERO;
    uint8 numMatchedDtcNext;
    Dem_EventMemoryInfo_st *info_ptr;

    if((DTC != NULL_PTR) && (DTCStatus != NULL_PTR))
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(DEM_GET_DTC_FILTER_EVTMEMIDX());
        slotCnt = DEM_GET_DTC_FILTER_SLOT_CNT();
        numMatchedDtcNext = (uint8)DEM_GET_DTC_FILTER_MATCH_NEXTIDX();

#if(DEM_CFG_MAX_NUMBER_EVENT_ENTRY <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
        {
            for(slotIdx = numMatchedDtcNext; slotIdx < info_ptr->cntEnSlot; slotIdx++)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                {
                    if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                    {
                        DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                        dtcMatched = TRUE;
                        break;
                    }
                }
            }

            if(FALSE == dtcMatched)
            {
                DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
                numMatchedDtcNext = DEM_INIT_ZERO;
                ret = E_OK;
            }
            else
            {
                numMatchedDtcNext = slotIdx + DEM_BYTE_ONE;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_DISABLED)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                *DTCStatus = DEM_GET_UDS_STATUS(evtIdx);
#else
                (void)Dem_EventGetCombStatusByte(evtIdx, DTCStatus);   
#endif
                if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT())
                {
                    *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                }
                else
                {
                    *DTC = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
                }
                ret = E_OK;
            }
        }
#else
        {
            if((info_ptr->cntEnSlot - slotCnt) >= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
            {
                for(slotIdx = numMatchedDtcNext; slotIdx < (slotCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM); slotIdx++)
                {
                    evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
                    dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                    {
                        if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                        {
                            DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                            dtcMatched = TRUE;
                            break;
                        }
                    }
                }
            }
            else
            {
                for(slotIdx = numMatchedDtcNext; slotIdx < info_ptr->cntEnSlot; slotIdx++)
                {
                    evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
                    dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                    {
                        if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                        {
                            DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                            dtcMatched = TRUE;
                            break;
                        }
                    }
                }
            }

            if(slotIdx >= info_ptr->cntEnSlot)
            {
                slotCnt = DEM_INIT_ZERO;
                numMatchedDtcNext = DEM_INIT_ZERO;
                DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
                ret = E_OK;
            }
            else
            {
                if(FALSE == dtcMatched)
                {
                    numMatchedDtcNext = slotIdx;
                    slotCnt += DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
                }
                else
                {
                    numMatchedDtcNext = slotIdx + DEM_BYTE_ONE;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_DISABLED)
                    *DTCStatus = DEM_GET_UDS_STATUS(evtIdx);
#else
                    (void)Dem_EventGetCombStatusByte(evtIdx, DTCStatus);   
#endif
                    if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT())
                    {
                        *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                    }
                    else
                    {
                        *DTC = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
                    }
                    ret = E_OK;
                }
            }
        }
#endif
        DEM_SET_DTC_FILTER_SLOT_CNT(slotCnt);
        DEM_SET_DTC_FILTER_MATCH_NEXTIDX(numMatchedDtcNext);
    }
    else
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        ret = E_OK;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCalcDtcAndFdcNextFiltered
*
* Explanation: Calculate the next filtered DTC and FDC
*
* param: uint32 *dtc, to hole the matched DTC value
*        sint8 *dtcFdc, to hole the fdc value
*
* retval: E_NOT_OK, in calculating; E_OK, calculation finished
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventCalcDtcAndFdcNextFiltered
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC, 
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) DTCFdc
)
{
    boolean dtcMatched = FALSE;
    uint8 ret = E_NOT_OK;
    uint8 slotIdx;
    uint8 slotCnt;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx = DEM_INIT_ZERO, dtcIdx = DEM_INIT_ZERO;
    uint8 numMatchedDtcNext;
    Dem_EventMemoryInfo_st *info_ptr;

    if(DEM_DTC_ORIGIN_PERMANENT_MEMORY == DEM_GET_DTC_FILTER_ORIGIN())
    {
        DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
        ret = E_OK;
    }
    else
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(DEM_GET_DTC_FILTER_EVTMEMIDX());
        slotCnt = DEM_GET_DTC_FILTER_SLOT_CNT();
        numMatchedDtcNext = (uint8)DEM_GET_DTC_FILTER_MATCH_NEXTIDX();

        if((DTC != NULL_PTR) && (DTCFdc != NULL_PTR))
        {
#if(DEM_CFG_MAX_NUMBER_EVENT_ENTRY <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
            for(slotIdx = numMatchedDtcNext; slotIdx < info_ptr->cntEnSlot; slotIdx++)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(info_ptr->enSlot[slotIdx] > DEM_INIT_ZERO)
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                    evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
                    dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                    if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                    {
                        if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                        {
                            DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                            dtcMatched = TRUE;
                            break;
                        }
                    }
                }
            }

            if(FALSE == dtcMatched)
            {
                DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
                numMatchedDtcNext = DEM_INIT_ZERO;
                ret = E_OK;
            }
            else
            {
                numMatchedDtcNext = slotIdx + DEM_BYTE_ONE;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT != DEM_EVCOMB_DISABLED)
                (void)Dem_EventGetCombFDC(evtIdx, DTCFdc);
#else
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                *DTCFdc = DEM_GET_FDCCNT(evtIdx);
#endif
                if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT())
                {
                    *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                }
                else
                {
                    *DTC = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
                }
                ret = E_OK;
            }
#else
            if((info_ptr->cntEnSlot - slotCnt) >= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
            {
                for(slotIdx = numMatchedDtcNext; slotIdx < (slotCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM); slotIdx++)
                {
                    if(info_ptr->enSlot[slotIdx] > DEM_INIT_ZERO)
                    {
                        evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
                        dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                        if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                        {
                            if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                            {
                                DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                                dtcMatched = TRUE;
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                for(slotIdx = numMatchedDtcNext; slotIdx < info_ptr->cntEnSlot; slotIdx++)
                {
                    if(info_ptr->enSlot[slotIdx] > DEM_INIT_ZERO)
                    {
                        evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
                        dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                        if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                        {
                            if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                            {
                                DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                                dtcMatched = TRUE;
                                break;
                            }
                        }
                    }
                }
            }

            if(slotIdx >= info_ptr->cntEnSlot)
            {
                slotCnt = DEM_INIT_ZERO;
                numMatchedDtcNext = DEM_INIT_ZERO;
                DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
                ret = E_OK;
            }
            else
            {
                if(FALSE == dtcMatched)
                {
                    numMatchedDtcNext = slotIdx;
                    slotCnt += DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
                }
                else
                {
                    numMatchedDtcNext = slotIdx + DEM_BYTE_ONE;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT != DEM_EVCOMB_DISABLED)
                    (void)Dem_EventGetCombFDC(evtIdx, DTCFdc);
#else
                    *DTCFdc = DEM_GET_FDCCNT(evtIdx);
#endif
                    if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT())
                    {
                        *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                    }
                    else
                    {
                        *DTC = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
                    }
                    ret = E_OK;
                }
            }
#endif
        }
        else
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            ret = E_OK;
        }
        
        DEM_SET_DTC_FILTER_SLOT_CNT(slotCnt);
        DEM_SET_DTC_FILTER_MATCH_NEXTIDX(numMatchedDtcNext);
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCalcAllDtcAndFdcNextFiltered
*
* Explanation: Calculate the DTC number of all supported DTC
*
* param: uint32 *dtc, to hole the matched DTC value
*        sint8 *dtcFdc, to hole the fdc value
*
* retval: E_NOT_OK, in calculating; E_OK, calculation finished
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventCalcAllDtcAndFdcNextFiltered
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC, 
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) DTCFdc
)
{
    uint8 ret = E_NOT_OK;
    uint16 numMatchedDtcNext;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 filterCnt;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx;
    
    filterCnt = DEM_GET_DTC_FILTER_MATCH_CNT();
    numMatchedDtcNext = DEM_GET_DTC_FILTER_MATCH_NEXTIDX();

    if((DTC != NULL_PTR) && (DTCFdc != NULL_PTR))
    {
#if(DEM_CFG_DTC_NUM <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
        for(dtcIdx = (uint16)(numMatchedDtcNext + DEM_BYTE_ONE); dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++)
        {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
            if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
            {
                if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                {
                    DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                    break;
                }
            }
        }

        if(dtcIdx > DEM_CFG_DTC_NUM)
        {
            numMatchedDtcNext = DEM_INIT_ZERO;
            DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
        }
        else
        {
            evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[DEM_INIT_ZERO];
            numMatchedDtcNext = dtcIdx;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT != DEM_EVCOMB_DISABLED)
             (void)Dem_EventGetCombFDC(evtIdx, DTCFdc);
#else
             *DTCFdc = DEM_GET_FDCCNT(evtIdx);
#endif
             if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT())
             {
                 *DTC = DEM_DTCVALUE_CAL(dtcIdx);
             }
             else
             {
                 *DTC = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
             }
        }
        ret = E_OK;
#else
        if((DEM_CFG_DTC_NUM - filterCnt) > DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
        {
            for(dtcIdx = (numMatchedDtcNext + DEM_BYTE_ONE); dtcIdx <= (filterCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM); dtcIdx++)
            {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                {
                    if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                    {
                        DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                        break;
                    }
                }
            }
        }
        else
        {
            for(dtcIdx = (numMatchedDtcNext + DEM_BYTE_ONE); dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++)
            {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                {
                    if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                    {
                        DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                        break;
                    }
                }
            }
        }

        if(dtcIdx > DEM_CFG_DTC_NUM)
        {
            filterCnt = DEM_INIT_ZERO;
            numMatchedDtcNext = DEM_INIT_ZERO;
            DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
            ret = E_OK;
        }
        else
        {
            if(dtcIdx > (filterCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM))
            {
                numMatchedDtcNext = filterCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
                filterCnt += DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
            }
            else
            {
                evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[DEM_INIT_ZERO];
                numMatchedDtcNext = dtcIdx;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT != DEM_EVCOMB_DISABLED)
                (void)Dem_EventGetCombFDC(evtIdx, DTCFdc);
#else
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                *DTCFdc = DEM_GET_FDCCNT(evtIdx);
#endif
                if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT())
                {
                    *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                }
                else
                {
                    *DTC = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
                }
                ret = E_OK;
            }
        }
#endif
    }
    else
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        ret = E_OK;
    }

    DEM_SET_DTC_FILTER_MATCH_CNT(filterCnt);
    DEM_SET_DTC_FILTER_MATCH_NEXTIDX(numMatchedDtcNext);

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCalcDtcAndSeverityNextFiltered
*
* Explanation: Calculate the next filtered DTC and Severity
*
* param: uint32 *dtc, to hole the matched DTC value
*        sint8 *dtcFdc, to hole the fdc value
*
* retval: E_NOT_OK, in calculating; E_OK, calculation finished
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventCalcDtcAndSeverityNextFiltered
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFuncunit
)
{
    boolean dtcMatched = FALSE;
    uint8 ret = E_NOT_OK;
    uint8 slotIdx;
    uint8 slotCnt;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx = DEM_INIT_ZERO, dtcIdx = DEM_INIT_ZERO;
    uint8 numMatchedDtcNext;
    Dem_EventMemoryInfo_st *info_ptr;

    if(DEM_DTC_ORIGIN_PERMANENT_MEMORY == DEM_GET_DTC_FILTER_ORIGIN())
    {
        DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
        ret = E_OK;
    }
    else
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(DEM_GET_DTC_FILTER_EVTMEMIDX());
        slotCnt = DEM_GET_DTC_FILTER_SLOT_CNT();
        numMatchedDtcNext = (uint8)DEM_GET_DTC_FILTER_MATCH_NEXTIDX();

        if((DTC != NULL_PTR) && (DTCStatus != NULL_PTR) &&
           (DTCSeverity != NULL_PTR) && (DTCFuncunit != NULL_PTR))
        {
#if(DEM_CFG_MAX_NUMBER_EVENT_ENTRY <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
            for(slotIdx = numMatchedDtcNext; slotIdx < info_ptr->cntEnSlot; slotIdx++)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                {
                    if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                    {
                        DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                        dtcMatched = TRUE;
                        break;
                    }
                }
            }

            if(FALSE == dtcMatched)
            {
                DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
                numMatchedDtcNext = DEM_INIT_ZERO;
                ret = E_OK;
            }
            else
            {
                numMatchedDtcNext = slotIdx + DEM_BYTE_ONE;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT != DEM_EVCOMB_DISABLED)
                (void)Dem_EventGetCombStatusByte(evtIdx, DTCStatus);
#else
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                *DTCStatus = DEM_GET_UDS_STATUS(evtIdx);
#endif
                *DTCSeverity = Dem_CfgDTCTable[dtcIdx].acDtcSeverity;
                *DTCFuncunit = Dem_CfgDTCTable[dtcIdx].acFuncId;
                if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT())
                {
                    *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                }
                else
                {
                    *DTC = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
                }
                ret = E_OK;
            }
#else
            if((info_ptr->cntEnSlot - slotCnt) >= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
            {
                for(slotIdx = numMatchedDtcNext; slotIdx < (slotCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM); slotIdx++)
                {
                    evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
                    dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                    {
                        if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                        {
                            DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                            dtcMatched = TRUE;
                            break;
                        }
                    }
                }
            }
            else
            {
                for(slotIdx = numMatchedDtcNext; slotIdx < info_ptr->cntEnSlot; slotIdx++)
                {
                    evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
                    dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                    {
                        if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                        {
                            DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                            dtcMatched = TRUE;
                            break;
                        }
                    }
                }
            }

            if(slotIdx >= info_ptr->cntEnSlot)
            {
                slotCnt = DEM_INIT_ZERO;
                numMatchedDtcNext = DEM_INIT_ZERO;
                DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
                ret = E_OK;
            }
            else
            {
                if(FALSE == dtcMatched)
                {
                    numMatchedDtcNext = slotIdx;
                    slotCnt += DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
                }
                else
                {
                    numMatchedDtcNext = slotIdx + DEM_BYTE_ONE;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT != DEM_EVCOMB_DISABLED)
                    (void)Dem_EventGetCombStatusByte(evtIdx, DTCStatus);
#else
                    *DTCStatus = DEM_GET_UDS_STATUS(evtIdx);
#endif
                    *DTCSeverity = Dem_CfgDTCTable[dtcIdx].acDtcSeverity;
                    *DTCFuncunit = Dem_CfgDTCTable[dtcIdx].acFuncId;
                    if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT())
                    {
                        *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                    }
                    else
                    {
                        *DTC = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
                    }
                    ret = E_OK;
                }
            }
#endif
        }
        else
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            ret = E_OK;
        }
        
        DEM_SET_DTC_FILTER_SLOT_CNT(slotCnt);
        DEM_SET_DTC_FILTER_MATCH_NEXTIDX(numMatchedDtcNext);
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCalcAllDtcAndSeverityNextFiltered
*
* Explanation: Calculate the DTC number of all supported DTC
*
* param: uint32 *dtc, to hole the matched DTC value
*        sint8 *dtcFdc, to hole the fdc value
*
* retval: E_NOT_OK, in calculating; E_OK, calculation finished
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventCalcAllDtcAndSeverityNextFiltered
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFuncunit
)
{
    uint8 ret = E_NOT_OK;
    uint16 numMatchedDtcNext;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 filterCnt;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx;
    
    filterCnt = DEM_GET_DTC_FILTER_MATCH_CNT();
    numMatchedDtcNext = DEM_GET_DTC_FILTER_MATCH_NEXTIDX();

    if((DTC != NULL_PTR) && (DTCStatus != NULL_PTR) &&
       (DTCSeverity != NULL_PTR) && (DTCFuncunit != NULL_PTR))
    {
#if(DEM_CFG_DTC_NUM <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
        for(dtcIdx = (uint16)(numMatchedDtcNext + DEM_BYTE_ONE); dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++)
        {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
            if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
            {
                if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                {
                    DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                    break;
                }
            }
        }

        if(dtcIdx > DEM_CFG_DTC_NUM)
        {
            numMatchedDtcNext = DEM_INIT_ZERO;
            DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
        }
        else
        {
            evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[DEM_INIT_ZERO];
            numMatchedDtcNext = dtcIdx;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT != DEM_EVCOMB_DISABLED)
            (void)Dem_EventGetCombStatusByte(evtIdx, DTCStatus);
#else
            *DTCStatus = DEM_GET_UDS_STATUS(evtIdx);
#endif
            *DTCSeverity = Dem_CfgDTCTable[dtcIdx].acDtcSeverity;
            *DTCFuncunit = Dem_CfgDTCTable[dtcIdx].acFuncId;
            if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT())
            {
                *DTC = DEM_DTCVALUE_CAL(dtcIdx);
            }         
            else
            {
                *DTC = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
            }
        }
        ret = E_OK;
#else
        if((DEM_CFG_DTC_NUM - filterCnt) > DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
        {
            for(dtcIdx = (numMatchedDtcNext + DEM_BYTE_ONE); dtcIdx <= (filterCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM); dtcIdx++)
            {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                {
                    if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                    {
                        DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                        break;
                    }
                }
            }
        }
        else
        {
            for(dtcIdx = (numMatchedDtcNext + DEM_BYTE_ONE); dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++)
            {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
                {
                    if(TRUE == DEM_GET_DTC_FILTERED(dtcIdx))
                    {
                        DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
                        break;
                    }
                }
            }
        }

        if(dtcIdx > DEM_CFG_DTC_NUM)
        {
            filterCnt = DEM_INIT_ZERO;
            numMatchedDtcNext = DEM_INIT_ZERO;
            DEM_SET_DTC_FILTER_MATCH_NEXT(FALSE);
            ret = E_OK;
        }
        else
        {
            if(dtcIdx > (filterCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM))
            {
                numMatchedDtcNext = filterCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
                filterCnt += DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
            }
            else
            {
                evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[DEM_INIT_ZERO];
                numMatchedDtcNext = dtcIdx;
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT != DEM_EVCOMB_DISABLED)
                (void)Dem_EventGetCombStatusByte(evtIdx, DTCStatus);
#else
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                *DTCStatus = DEM_GET_UDS_STATUS(evtIdx);
#endif
                *DTCSeverity = Dem_CfgDTCTable[dtcIdx].acDtcSeverity;
                *DTCFuncunit = Dem_CfgDTCTable[dtcIdx].acFuncId;
                if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT())
                {
                    *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                }
                else
                {
                    *DTC = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
                }
                ret = E_OK;
            }
        }
#endif
    }
    else
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        ret = E_OK;
    }

    DEM_SET_DTC_FILTER_MATCH_CNT(filterCnt);
    DEM_SET_DTC_FILTER_MATCH_NEXTIDX(numMatchedDtcNext);

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventCalcDTCFreezeFrameFiltered
*
* Explanation: Calculate the matched freeze frame record number
*
* param: None
*
* retval: uint16 ffDataRecNum, the matched number
********************************************************************************
*/
FUNC(uint16, DEM_CODE) Dem_EventCalcDTCFreezeFrameFiltered(void)
{
    uint16 ffDataRecNum = DEM_INIT_ZERO;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 slotCnt, entryIdx;
    uint8 ffDataRecCnt;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx;
    uint8 matched = E_OK;
    Dem_EventMemoryInfo_st *info_ptr;
    Dem_EventMemoryEntry_st *entry_ptr;
    
    /* [SWS_Dem_00210] This filter always belongs to primary memory.*/
    info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(DEM_EVENT_MEMORY_PRIMARY);
    entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(DEM_EVENT_MEMORY_PRIMARY);
    
    for(slotCnt = DEM_INIT_ZERO; slotCnt < info_ptr->cntEnSlot; slotCnt++)
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotCnt]];
        dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
        {
            /* DTC Format is matched? */
            if(DEM_DTC_FORMAT_OBD == DEM_GET_FF_FILTER_FORMAT())
            {
                if(DEM_INIT_ZERO == Dem_CfgDTCTable[dtcIdx].acObdDtcIdx)
                {
                    matched = E_NOT_OK;
                }
            }
            else if(DEM_DTC_FORMAT_J1939 == DEM_GET_FF_FILTER_FORMAT())
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                matched = E_NOT_OK;
            }
            else
            {
                /* UDS formar is ok */
            }

            if(E_OK == matched)
            {
                entryIdx = info_ptr->entryIdx[slotCnt];
                
                for(ffDataRecCnt = DEM_INIT_ZERO; ffDataRecCnt < DEM_CFG_FFDATA_MAX_REF_RECORD_NUM; ffDataRecCnt++)
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    if(TRUE == entry_ptr[entryIdx].datBuf.stFfData[ffDataRecCnt])
                    {
                        ffDataRecNum++;
                    }
                }
            }
        }
    }

    return ffDataRecNum;
}


/*
********************************************************************************
* Function Name: Dem_EventCalcDTCFreezeFrameNextFiltered
*
* Explanation: Calculate the Next matched freeze frame record number
*
* param: uint32 *dtcVal, to hold the DTC value
*        uint8 *recNum, to hold the record number value
*
* retval: E_NOT_OK, in calculating; E_OK, calculation finished
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventCalcDTCFreezeFrameNextFiltered
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) RecordNum
)
{
    uint8 ret = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 slotIdx, entryIdx;
    uint8 ffDataRecIdxNext, ffDataRecCnt, ffDataRecIdx;
    uint8 slotCnt;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx, obdDtcIdx;
    uint8 matched = E_OK;
    Dem_EventMemoryInfo_st *info_ptr;
    Dem_EventMemoryEntry_st *entry_ptr;
    
    /* [SWS_Dem_00210] This filter always belongs to primary memory.*/
    info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(DEM_INIT_ONE);
    entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(DEM_INIT_ONE);
    slotCnt = DEM_GET_FF_FILTER_SLOT_CNT();
    ffDataRecIdxNext = DEM_GET_FF_FILTER_MATCH_NEXT_IDX();

    for(slotIdx = slotCnt; slotIdx < info_ptr->cntEnSlot; slotIdx++)
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
        dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
        {
            /* DTC Format is matched? */
            if(DEM_DTC_FORMAT_OBD == DEM_GET_FF_FILTER_FORMAT())
            {
                obdDtcIdx = Dem_CfgDTCTable[dtcIdx].acObdDtcIdx;
                if( (obdDtcIdx > DEM_INIT_ZERO) && (obdDtcIdx <= DEM_CFG_OBD_DTC_NUM) )
                {
                    *DTC = Dem_CfgObdDtcValue[obdDtcIdx];
                }
                else
                {
                    matched = E_NOT_OK;
                }
            }
            else if(DEM_DTC_FORMAT_UDS == DEM_GET_FF_FILTER_FORMAT())
            {
                /* UDS format is ok */
                *DTC = DEM_DTCVALUE_CAL(dtcIdx);
            }
            else
            {
                /* not supported format */
                slotCnt = info_ptr->cntEnSlot;
            }

            if(E_OK == matched)
            {
                /* Find stored freeze frame record */
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                entryIdx = info_ptr->entryIdx[slotCnt];
                
                for(ffDataRecCnt = ffDataRecIdxNext; ffDataRecCnt < DEM_CFG_FFDATA_MAX_REF_RECORD_NUM; ffDataRecCnt++)
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                    if(TRUE == entry_ptr[entryIdx].datBuf.stFfData[ffDataRecCnt])
                    {
                        ret = E_OK;
                        break;
                    }
                }

                if(E_OK == ret)
                {
                    ffDataRecIdx = Dem_CfgFfDataRecordNumTable[Dem_CfgDTCTable[dtcIdx].acFfDataRecClsIdx].acFfDataRecordIdx[ffDataRecCnt];
                    *RecordNum = Dem_CfgFfDataRecordTable[ffDataRecIdx].acFfDataRecordNum;
                    if(DEM_CFG_FFDATA_MAX_REF_RECORD_NUM == (ffDataRecCnt + DEM_INIT_ONE))
                    {
                        ffDataRecIdxNext = DEM_INIT_ZERO;
                        slotCnt = slotIdx + DEM_INIT_ONE;
                    }
                    else
                    {
                        ffDataRecIdxNext = ffDataRecCnt + DEM_INIT_ONE;
                        slotCnt = slotIdx;
                    }
                }
                else
                {
                    ffDataRecIdxNext = DEM_INIT_ZERO;
                    slotCnt = slotIdx + DEM_INIT_ONE;
                }
            }

            if((slotCnt == info_ptr->cntEnSlot) || (E_OK == matched))
            {
                break;
            }
        }
    }

    if(slotIdx >= info_ptr->cntEnSlot)
    {
        slotCnt = DEM_INIT_ZERO;
        ffDataRecIdxNext = DEM_INIT_ZERO;
        DEM_SET_FF_FILTER_MATCH_NEXT(FALSE);
        ret = E_OK;
    }
    
    DEM_SET_FF_FILTER_SLOT_CNT(slotCnt);
    DEM_SET_FF_FILTER_MATCH_NEXT_IDX(ffDataRecIdxNext);

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventClearDTC
*
* Explanation: Clear DTC
*
* param: uint32 DTC, DTC value
*        Dem_DTCFormatType DTCFormat, DTC format
*        uint8 EventMemIdx, event memory index
*        uint8 ClearClient, to indicate who request the clear action
*
* retval: Dem_ReturnClearDTCType, clear result
********************************************************************************
*/
FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_EventClearDTC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    uint8 EventMemIdx, 
    uint8 ClearClient
)
{
    Dem_ReturnClearDTCType ret;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;

    if( DEM_EVENT_CLEAR_DTC_STATUS_IDLE == DEM_GET_DTC_CLEAR_STATUS() )
    {
        DEM_SET_DTC_CLEAR_EVTMEMIDX(EventMemIdx);
        DEM_SET_DTC_CLEAR_FORMAT(DTCFormat);
        DEM_SET_DTC_CLEAR_CLIENT(ClearClient);
        DEM_SET_DTC_CLEAR_DTCVAL(DTC);

        if( E_OK == Dem_EventClearDTCRequest() )
        {
            if( (DEM_CLEAR_DTC_TYPE_SINGLE == DEM_GET_DTC_CLEAR_TYPE()) &&
                (DEM_CLEAR_DTC_CLIENT_DCM == DEM_GET_DTC_CLEAR_CLIENT()) )
            {
                if( E_OK == Dem_EventCalcDTCIndexFromDTC(DTC, DTCFormat, &dtcIdx) )
                {
                    if( dtcIdx > DEM_INIT_ZERO )
                    {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                        if( FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx) )
                        {
                            Dem_EventClearDTCProcess();
                            ret = Dem_EventClearDTCResult();

                        }
                        else
                        {
                            /* Suppress DTC, return WRONG_DTC */
                            ret = DEM_CLEAR_WRONG_DTC;
                        }
#else
                        Dem_EventClearDTCProcess();
                        ret = Dem_EventClearDTCResult();
#endif
                    }
                    else
                    {
                        /* DTC not supported */
                        ret = DEM_CLEAR_WRONG_DTC;
                    }
                }
                else
                {
                    ret = DEM_CLEAR_PENDING;
                }
            }
            else
            {
                Dem_EventClearDTCProcess();
                ret = Dem_EventClearDTCResult();
            }
        }
        else
        {
            ret = DEM_CLEAR_WRONG_DTC;
        }
    }
    else
    {
        /* Current DTC clear request is still on going */
        if( (DTC == DEM_GET_DTC_CLEAR_DTCVAL()) && 
            (DTCFormat == DEM_GET_DTC_CLEAR_FORMAT()) && 
            (EventMemIdx == DEM_GET_DTC_CLEAR_EVTMEMIDX()) && 
            (ClearClient == DEM_GET_DTC_CLEAR_CLIENT()) )
        {
            if( DEM_EVENT_CLEAR_DTC_STATUS_PENDING == DEM_GET_DTC_CLEAR_STATUS() )
            {
                Dem_EventClearDTCProcess();
                ret = Dem_EventClearDTCResult();
            }
            else if( DEM_EVENT_CLEAR_DTC_STATUS_STORING == DEM_GET_DTC_CLEAR_STATUS() )
            {
                ret = Dem_EventClearDTCResult();
            }
            else
            {
                ret = DEM_CLEAR_OK;
            }
        }
        else
        {
            ret = DEM_CLEAR_BUSY;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventClearDTCRequest
*
* Explanation: Request to Clear specific DTC
*
* param: None
*
* retval: E_OK, request accept; E_NOT_OK, request denied
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, DEM_CODE) Dem_EventClearDTCRequest(void)
{
    uint8 ret = E_OK;
#if(DEM_CFG_DTC_GROUP_NUM > 0U)
    uint8 dtcGrpCnt;
#endif
    
    DEM_SET_DTC_CLEAR_TYPE(DEM_CLEAR_DTC_TYPE_NONE);
    
#if( DEM_CFG_CLEARDTCLIMITATION == DEM_ONLY_CLEAR_ALL_DTCS )
    /* [SWS_Dem_00670] */
    if( (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT()) &&
       (DEM_EVENT_DTC_GROUP_ALL == DEM_GET_DTC_CLEAR_DTCVAL()) )
    {
        DEM_SET_DTC_CLEAR_TYPE(DEM_CLEAR_DTC_TYPE_ALL);
    }
    else
    {
        ret = E_NOT_OK;
    }
#else
    switch( DEM_GET_DTC_CLEAR_CLIENT() )
    {
        case DEM_CLEAR_DTC_CLIENT_CDD:
        case DEM_CLEAR_DTC_CLIENT_DCM:
        {
            if( DEM_DTC_FORMAT_UDS < DEM_GET_DTC_CLEAR_FORMAT() )
            {
                ret = E_NOT_OK;
            }
            else
            {
                if( DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT() )
                {
                    if( DEM_EVENT_DTC_GROUP_ALL == DEM_GET_DTC_CLEAR_DTCVAL() )
                    {
                        DEM_SET_DTC_CLEAR_TYPE(DEM_CLEAR_DTC_TYPE_ALL);
                    }
                    else
                    {
#if(DEM_CFG_DTC_GROUP_NUM > 0U)
                        /* Is a DTC group clear request? The last group boundary should not be considered */
                        for( dtcGrpCnt = DEM_INIT_ONE; dtcGrpCnt < DEM_CFG_DTC_GROUP_NUM; dtcGrpCnt++ )
                        {
                            if( Dem_CfgDTCGrpTable[dtcGrpCnt] == DEM_GET_DTC_CLEAR_DTCVAL() )
                            {
                                DEM_SET_DTC_CLEAR_TYPE(DEM_CLEAR_DTC_TYPE_GROUP);
                                DEM_SET_DTC_CLEAR_GRPIDX(dtcGrpCnt);
                                break;
                            }
                        }

                        /* Is a single DTC clear request? */
                        if( dtcGrpCnt >= DEM_CFG_DTC_GROUP_NUM )
#endif
                        {
                            DEM_SET_DTC_CLEAR_TYPE(DEM_CLEAR_DTC_TYPE_SINGLE);
                        }
                    }
                }
                else
                {
                    /* For OBD format from DCM service, only accept type_all */
                    if( DEM_EVENT_DTC_GROUP_ALL == DEM_GET_DTC_CLEAR_DTCVAL() )
                    {
                        DEM_SET_DTC_CLEAR_TYPE(DEM_CLEAR_DTC_TYPE_ALL);
                    }
                    else
                    {
                        ret = E_NOT_OK;
                    }
                }
            }
            break;
        }
        case DEM_CLEAR_DTC_CLIENT_OBD:
        {
            if( DEM_DTC_FORMAT_OBD != DEM_GET_DTC_CLEAR_FORMAT() )
            {
                ret = E_NOT_OK;
            }
            else
            {
                /* For OBD format from OBD service, only accept type_all */
                if( DEM_EVENT_DTC_GROUP_ALL == DEM_GET_DTC_CLEAR_DTCVAL() )
                {
                    DEM_SET_DTC_CLEAR_TYPE(DEM_CLEAR_DTC_TYPE_ALL);
                }
                else
                {
                    ret = E_NOT_OK;
                }
            }
            break;
        }

#if( DEM_CFG_J1939SUPPORT == STD_ON )
        case DEM_CLEAR_DTC_CLIENT_J1939:
        {
            if( DEM_DTC_FORMAT_J1939 != DEM_GET_DTC_CLEAR_FORMAT() )
            {
                ret = E_NOT_OK;
            }
            else
            {
                if( DEM_J1939DTC_CLEAR_ALL == DEM_GET_DTC_CLEAR_DTCVAL() )
                {
                    DEM_SET_DTC_CLEAR_TYPE(DEM_CLEAR_DTC_TYPE_ALL);
                }
                else
                {
#if(DEM_CFG_DTC_GROUP_NUM > 0U)
                    /* Is a DTC group clear request? The last group boundary should not be considered */
                    for( dtcGrpCnt = DEM_INIT_ONE; dtcGrpCnt < DEM_CFG_DTC_GROUP_NUM; dtcGrpCnt++ )
                    {
                        if( Dem_CfgDTCGrpTable[dtcGrpCnt] == DEM_GET_DTC_CLEAR_DTCVAL() )
                        {
                            DEM_SET_DTC_CLEAR_TYPE(DEM_CLEAR_DTC_TYPE_GROUP);
                            DEM_SET_DTC_CLEAR_GRPIDX(dtcGrpCnt);
                            break;
                        }
                    }
                    /* Is a single DTC clear request? */
                    if( dtcGrpCnt >= DEM_CFG_DTC_GROUP_NUM )
#endif
                    {
                        DEM_SET_DTC_CLEAR_TYPE(DEM_CLEAR_DTC_TYPE_SINGLE);
                    }
                }
            }
            break;
        }
#endif

        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        default:
        {
            ret = E_NOT_OK;
            break;
        }
    }
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventClearDTCProcess
*
* Explanation: Processing of clear DTC
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventClearDTCProcess(void)
{
    switch( DEM_GET_DTC_CLEAR_TYPE() )
    {
        case DEM_CLEAR_DTC_TYPE_ALL:
        {
            if( E_OK == Dem_EventClearAllDTC() )
            {
                DEM_SET_DTC_CLEAR_STATUS(DEM_EVENT_CLEAR_DTC_STATUS_COMPLETE);
            }
            else
            {
                DEM_SET_DTC_CLEAR_STATUS(DEM_EVENT_CLEAR_DTC_STATUS_PENDING);
            }
            break;
        }
        case DEM_CLEAR_DTC_TYPE_GROUP:
        {
            if( E_OK == Dem_EventClearGroupDTC() )
            {
                DEM_SET_DTC_CLEAR_STATUS(DEM_EVENT_CLEAR_DTC_STATUS_COMPLETE);
            }
            else
            {
                DEM_SET_DTC_CLEAR_STATUS(DEM_EVENT_CLEAR_DTC_STATUS_PENDING);
            }
            break;
        }
        case DEM_CLEAR_DTC_TYPE_SINGLE:
        {
            if( E_OK == Dem_EventClearSingleDTC() )
            {
                DEM_SET_DTC_CLEAR_STATUS(DEM_EVENT_CLEAR_DTC_STATUS_COMPLETE);
            }
            else
            {
                DEM_SET_DTC_CLEAR_STATUS(DEM_EVENT_CLEAR_DTC_STATUS_PENDING);
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventClearDTCResult
*
* Explanation: Handle of clear process result
*
* param: None
*
* retval: Dem_ReturnClearDTCType
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_EventClearDTCResult(void)
{
    Dem_ReturnClearDTCType ret = DEM_CLEAR_FAILED;

    switch( DEM_GET_DTC_CLEAR_STATUS() )
    {
        case DEM_EVENT_CLEAR_DTC_STATUS_PENDING:
        {
#if( DEM_CFG_CLEARBEHAVIOR == DEM_CLRRESP_VOLATILE )
            DEM_SET_NVM_CLEAR_REQ_STATUS(FALSE);
#endif
            ret = DEM_CLEAR_PENDING;
            break;
        }
        case DEM_EVENT_CLEAR_DTC_STATUS_COMPLETE:
        {
#if( DEM_CFG_CLEARBEHAVIOR == DEM_CLRRESP_NONVOLATILE_FINISH )
            DEM_SET_DTC_CLEAR_STATUS(DEM_EVENT_CLEAR_DTC_STATUS_STORING);
            ret = DEM_CLEAR_PENDING;
#elif( DEM_CFG_CLEARBEHAVIOR == DEM_CLRRESP_NONVOLATILE_TRIGGER )
            DEM_SET_DTC_CLEAR_STATUS(DEM_EVENT_CLEAR_DTC_STATUS_IDLE);
            ret = DEM_CLEAR_OK;
#else
            DEM_SET_NVM_CLEAR_REQ_STATUS(FALSE);
            DEM_SET_DTC_CLEAR_STATUS(DEM_EVENT_CLEAR_DTC_STATUS_IDLE);
            ret = DEM_CLEAR_OK;
#endif
            break;
        }
        case DEM_EVENT_CLEAR_DTC_STATUS_STORING:
        {
            /* Check the Nvm block clear action status */
            if( DEM_NVM_STATE_DONE == DEM_GET_NVM_STATE() )
            {
                DEM_SET_DTC_CLEAR_STATUS(DEM_EVENT_CLEAR_DTC_STATUS_IDLE);
                DEM_SET_NVM_STATE(DEM_NVM_STATE_IDLE);
                ret = DEM_CLEAR_OK;
            }
            else if( DEM_NVM_STATE_FAILED == DEM_GET_NVM_STATE() )
            {
                DEM_SET_DTC_CLEAR_STATUS(DEM_EVENT_CLEAR_DTC_STATUS_IDLE);
                DEM_SET_NVM_STATE(DEM_NVM_STATE_IDLE);
                ret = DEM_CLEAR_FAILED;
            }
            else if( DEM_NVM_STATE_INVALIDATED == DEM_GET_NVM_STATE() )
            {
                DEM_SET_DTC_CLEAR_STATUS(DEM_EVENT_CLEAR_DTC_STATUS_IDLE);
                DEM_SET_NVM_STATE(DEM_NVM_STATE_IDLE);
                ret = DEM_CLEAR_MEMORY_ERROR;
            }
            else
            {
                /* In progress */
                ret = DEM_CLEAR_PENDING;
            }
            break;
        }
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        case DEM_EVENT_CLEAR_DTC_STATUS_IDLE:
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        default:
        {
            break;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventClearDTCStatus
*
* Explanation: Clear event DTC status byte
*
* param: uint16 EventIdx, event index
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventClearDTCStatus
(
    uint16 EventIdx
)
{
    uint8 evtDtcSt;
    uint8 indiIdx;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        evtDtcSt = DEM_GET_UDS_STATUS(EventIdx);

        if(TRUE == Dem_EventClearAllowedCbk(EventIdx))
        {
            /* Clear the first/most recent confirmed/failed DTC in Dem_EventMemoryInfo. */
            Dem_EventClearDTCInfo(EventIdx);
            if(TRUE == DEM_GET_UDS_STATUS_WIR(EventIdx))
            {
                Dem_EventClearIndicator(EventIdx);
            }
            DEM_SET_UDS_STATUS(EventIdx, DEM_EVENT_DTC_STATUS_INIT);
            DEM_SET_UDS_FAILED_CNT(EventIdx, DEM_INIT_ZERO);
            /* Clear all the indicator failure counters of the event. */
            for(indiIdx = DEM_INIT_ZERO; indiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; indiIdx++)
            {
                DEM_SET_LAMP_FAILED_CNT(EventIdx, indiIdx, DEM_INIT_ZERO);
            }
            DEM_SET_LAMPFAILCNT_UPDATED(EventIdx, FALSE);
            DEM_SET_DEBCNT(EventIdx, DEM_DEBOUNCE_COUNTER_ZERO);
            DEM_SET_STORED_DEBCNT(EventIdx, DEM_GET_DEBCNT(EventIdx));
            DEM_SET_FDCCNT(EventIdx, DEM_DEBOUNCE_COUNTER_ZERO);
            if(DEM_GET_FDCCNTMAX_DCC(EventIdx) < (sint8)DEM_DEBOUNCE_COUNTER_ZERO)
            {
                DEM_SET_FDCCNTMAX_DCC(EventIdx, DEM_DEBOUNCE_COUNTER_ZERO);
            }
            DEM_SET_DEBTIME(EventIdx, DEM_DEBOUNCE_COUNTER_ZERO);
            DEM_SET_DEBTIMER_BUFFER(EventIdx, DEM_EVENT_STATUS_NONE);
            DEM_SET_DEBOUNCE_STATUS(EventIdx, DEM_DEBOUNCE_STATUS_RESET);
            DEM_SET_FDCCNTMAX_SLC(EventIdx, DEM_DEBOUNCE_COUNTER_ZERO);

#if(DEM_CFG_EXTENDSTATUSBYTE != DEM_INIT_ZERO)
            DEM_SET_STATUS_INDI(EventIdx, DEM_INIT_ZERO);
#endif

#if(DEM_CFG_AGEDCTRSUPPORT == STD_ON)
            DEM_SET_AGED_CNT(EventIdx, DEM_INIT_ZERO);
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
            DEM_SET_AGED_CNT2(EventIdx, DEM_INIT_ZERO);
#endif
#endif

#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
            Dem_ObdClearDtrData(EventIdx);
#endif
            /* Monitor initialization is always Triggered before return DEM_CLEAR_OK */
#if(DEM_CFG_TRIGGERMONITORINITBEFORECLEAROK == STD_ON)
            Dem_EventSetInitMonitorReason(EventIdx, DEM_INIT_MONITOR_CLEAR);
#endif

#ifdef DEM_IMMEDIATE_STORE_ALL_EVENT_STATUS
            /* Request update event memory status block */
            Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                           DEM_NVM_STATUS_BLOCK,
                                           DEM_NVM_REQ_CLEAR,
                                           FALSE);
#endif
        }
        else
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
            if(DEM_ONLY_THIS_CYCLE_AND_READINESS == Dem_CfgEventTable[EventIdx].acCallbackClrEvtBhv)
            {
                /* Reset bit1/bit4/bit5/bit6 */
                DEM_RESET_UDS_STATUS_TFTOC(EventIdx);
                DEM_RESET_UDS_STATUS_TNCSLC(EventIdx);
                DEM_RESET_UDS_STATUS_TFSLC(EventIdx);
                DEM_RESET_UDS_STATUS_TNCTOC(EventIdx);
#ifdef DEM_IMMEDIATE_STORE_ALL_EVENT_STATUS
                /* Request update event memory status block */
                Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                               DEM_NVM_STATUS_BLOCK,
                                               DEM_NVM_REQ_CLEAR,
                                               FALSE);
#endif
            }
        }

        if(evtDtcSt != DEM_GET_UDS_STATUS(EventIdx))
        {
            Dem_EventTriggerEventStatusChangedCbk(EventIdx, evtDtcSt, DEM_GET_UDS_STATUS(EventIdx));
#if(DEM_CFG_GENERALINTERFACESUPPORT == STD_ON)
            /* Call the function of GeneralCallbackEventStatusChange. */
            Dem_GeneralEventTriggerEventStatusChangedCbk(EventIdx, evtDtcSt, DEM_GET_UDS_STATUS(EventIdx));
#endif
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventClearDTCEntry
*
* Explanation: Clear event memory entry
*
* param: uint16 EventIdx, event index
*        uint8 EventMemIdx, event memory index
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventClearDTCEntry
(
    uint16 EventIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx,
    uint8 EventMemIdx
)
{
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
    uint16 dtcIdx, combEvtCnt, combEvtIdx;
#endif

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if(TRUE == Dem_EventClearAllowedCbk(EventIdx))
        {  
            Dem_EventMemoryEntryRemove(EntryIdx, EventMemIdx);
            
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_ONSTORAGE)
            dtcIdx = Dem_CfgEventIdTableIndex[EventIdx];
            for(combEvtCnt = DEM_INIT_ZERO; combEvtCnt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; combEvtCnt++)
            {
                combEvtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[combEvtCnt];
                if(combEvtIdx > DEM_INIT_ZERO)
                {
                    Dem_EventClearDTCStatus(combEvtIdx);
                }
                else
                {
                    break;
                }
            }
#endif

            /* Request update event memory entry block */
            Dem_EventMemoryNvmBlkUpdateReq(EventMemIdx,
                                           EntryIdx,
                                           DEM_NVM_REQ_CLEAR,
                                           FALSE);
            /* Request update event memory entry Info blcok */
            Dem_EventMemoryNvmBlkUpdateReq(EventMemIdx,
                                           DEM_NVM_INFO_BLOCK,
                                           DEM_NVM_REQ_CLEAR,
                                           FALSE);
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventClearIndicator
*
* Explanation: Check if activate the warning indicator
*
* param: EventIdx: Event index in configure table.
*
* retval: void
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventClearIndicator
(
    uint16 EventIdx
)
{
    uint8 evtIndiIdx, indiIdx, indiOnCnt;

#if( DEM_CFG_J1939SUPPORT == STD_ON )
    uint16 evtIdx = DEM_INIT_ZERO;
#endif

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        for(evtIndiIdx = DEM_INIT_ZERO; evtIndiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; evtIndiIdx++)
        {
            indiIdx = Dem_CfgEventTable[EventIdx].acIndiIdx[evtIndiIdx];
            if(indiIdx > DEM_INIT_ZERO)
            {
                DEM_SET_INDICATOR(EventIdx, evtIndiIdx, FALSE);
                
                indiOnCnt = DEM_GET_INDICATOR_ON_CNT(indiIdx);
                if(DEM_INIT_ZERO == indiOnCnt)
                {
                    DEM_SET_INDICATOR_STATUS(indiIdx, DEM_INDICATOR_OFF);
                }
                else
                {
                    indiOnCnt--;
                    if(DEM_INIT_ZERO == indiOnCnt)
                    {
                        DEM_SET_INDICATOR_STATUS(indiIdx, DEM_INDICATOR_OFF);
                    }

#if( DEM_CFG_J1939SUPPORT == STD_ON )
                    else
                    {
                        for( evtIdx = DEM_INIT_ONE; evtIdx < DEM_CFG_EVENT_NUM; evtIdx++ )
                        {
                            if( TRUE == DEM_GET_INDICATOR(evtIdx, evtIndiIdx) )
                            {
                                if( Dem_CfgEvtIndiBhv[EventIdx][evtIndiIdx] > DEM_GET_INDICATOR_STATUS(indiIdx) )
                                {
                                    DEM_SET_INDICATOR_STATUS(indiIdx, Dem_CfgEvtIndiBhv[EventIdx][evtIndiIdx]);
                                }
                            }
                        }
                    }
#endif

                    DEM_SET_INDICATOR_ON_CNT(indiIdx, indiOnCnt);
                }
            }
            else
            {
                break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventClearAllDTC
*
* Explanation: Clear All DTCs
*
* param: None
*
* retval: uint8, clear result
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, DEM_CODE) Dem_EventClearAllDTC(void)
{
    uint8 ret;

#if(DEM_CFG_EVENT_NUM <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
    /* Clear all event DTC status */
    Dem_EventClearAllDTCStatus((Dem_EventClearAllDtcCnt + DEM_INIT_ONE), DEM_CFG_EVENT_NUM);

    /* Clear event memory entry and entry slot */
    Dem_EventClearAllDTCEntry();
    
    /* Clear reported queue buffer */
    Dem_EnterCritical_0();
    DEM_SET_QUEUE_ST(DEM_EVENT_QUEUE_IDLE);
    DEM_SET_QUEUE_POS(DEM_INIT_ZERO);

    /* Set clearing NvM block request status after clearing all events status and entry. */
    DEM_SET_NVM_CLEAR_REQ_STATUS(TRUE);
    Dem_LeaveCritical_0();

#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    /* Clear OBD related */
    if(DEM_DTC_FORMAT_OBD == DEM_GET_DTC_CLEAR_FORMAT())
    {
        Dem_ObdClearRelatedInfo();
    }
#endif
    ret = E_OK;
#else
    /* Clear all event DTC status */
    if((DEM_CFG_EVENT_NUM - Dem_EventClearAllDtcCnt) > DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
    {
        Dem_EventClearAllDTCStatus((Dem_EventClearAllDtcCnt + DEM_INIT_ONE), (Dem_EventClearAllDtcCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM));
    }
    else
    {
        Dem_EventClearAllDTCStatus((Dem_EventClearAllDtcCnt + DEM_INIT_ONE), DEM_CFG_EVENT_NUM);
    }

    if((DEM_CFG_EVENT_NUM - Dem_EventClearAllDtcCnt) <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
    {
        /* Clear event memory entry and entry slot */
        Dem_EventClearAllDTCEntry();

#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
        /* Clear OBD related */
        if(DEM_DTC_FORMAT_OBD == DEM_GET_DTC_CLEAR_FORMAT())
        {
            Dem_ObdClearRelatedInfo();
        }
#endif

        /* Clear reported queue buffer */
        Dem_EnterCritical_0();
        DEM_SET_QUEUE_ST(DEM_EVENT_QUEUE_IDLE);
        DEM_SET_QUEUE_POS(DEM_INIT_ZERO);

        /* Set clearing NvM block request status after clearing all events status and entry. */
        DEM_SET_NVM_CLEAR_REQ_STATUS(TRUE);
        
        Dem_LeaveCritical_0();
        
        Dem_EventClearAllDtcCnt = DEM_INIT_ZERO;
        ret = E_OK;
    }
    else
    {
        Dem_EventClearAllDtcCnt += DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
        ret = E_NOT_OK;
    }
#endif

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventClearAllDTCStatus
*
* Explanation: Clear All DTCs status
*
* param: uint16 evtIdxStart, start index of clear action
*        uint16 evtIdxEnd, end index of clear action
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventClearAllDTCStatus
(
    uint16 EventIdxStart, 
    uint16 EventIdxEnd
)
{
    boolean isMatchMem = FALSE;
    uint8 breakFlag = FALSE;
    uint8 evtMemIdx;
    uint8 evtMemCnt;
    uint16 evtIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdxStart > DEM_INIT_ZERO) && (EventIdxStart <= DEM_CFG_EVENT_NUM) &&
       (EventIdxEnd > DEM_INIT_ZERO) && (EventIdxEnd <= DEM_CFG_EVENT_NUM))
    {
        for(evtIdx = EventIdxStart; evtIdx <= EventIdxEnd; evtIdx++)
        {
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
            if( (DEM_CLEAR_DTC_CLIENT_CDD != DEM_GET_DTC_CLEAR_CLIENT()) ||
               (TRUE == DEM_GET_AVAIL(evtIdx)) )
#endif
            {
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
                isMatchMem = FALSE;
                for( evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++ )
                {
                    evtMemIdx = Dem_CfgDTCTable[dtcIdx].acEvtMemIdx[evtMemCnt];
                    if( evtMemIdx > DEM_INIT_ZERO )
                    {
                        if( DEM_GET_DTC_CLEAR_EVTMEMIDX() == evtMemIdx )
                        {
                            isMatchMem = TRUE;
                            breakFlag = TRUE;
                        }
                    }
                    else
                    {
                        breakFlag = TRUE;
                    }
                    /* Unified break channel. */
                    if(TRUE == breakFlag)
                    {
                        break;
                    }
                }

                if( TRUE == isMatchMem )
                {

#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                    if((FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)) || 
                    (DEM_CLEAR_DTC_CLIENT_DCM != DEM_GET_DTC_CLEAR_CLIENT()))
                    {
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
                        /* Executing OBD 04 service to clear all DTC. */
                        if( (DEM_DTC_FORMAT_OBD == DEM_GET_DTC_CLEAR_FORMAT()) ||
#if( DEM_CFG_J1939SUPPORT == STD_ON )
                            (DEM_DTC_FORMAT_J1939 == DEM_GET_DTC_CLEAR_FORMAT()) ||
#endif
                            /* Executing UDS 14 service to clear all DTC. */
                            (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT()))

#elif( DEM_CFG_J1939SUPPORT == STD_ON )
                        /* The DTC format of Dem_J1939DcmClearDTC is DEM_DTC_FORMAT_UDS. */
                        if((DEM_DTC_FORMAT_J1939 == DEM_GET_DTC_CLEAR_FORMAT()) ||
                           (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT()))
#else
                        if( DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT() )
#endif
                        {
                            Dem_EventClearDTCStatus(evtIdx);
                        }
                    }
#else
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
                    /* Executing OBD 04 service to clear all DTC. */
                    if( (DEM_DTC_FORMAT_OBD == DEM_GET_DTC_CLEAR_FORMAT()) ||
#if( DEM_CFG_J1939SUPPORT == STD_ON )
                        (DEM_DTC_FORMAT_J1939 == DEM_GET_DTC_CLEAR_FORMAT()) ||
#endif
                        /* Executing UDS 14 service to clear all DTC. */
                        (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT()))
#elif( DEM_CFG_J1939SUPPORT == STD_ON )
                    /* The DTC format of Dem_J1939DcmClearDTC is DEM_DTC_FORMAT_UDS. */
                    if((DEM_DTC_FORMAT_J1939 == DEM_GET_DTC_CLEAR_FORMAT()) ||
                       (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT()))
#else
                    if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT())
#endif
                    {
                        Dem_EventClearDTCStatus(evtIdx);
                    }
#endif
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventClearAllDTCEntry
*
* Explanation: Clear All DTCs entry in event memory
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventClearAllDTCEntry(void)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 slotIdx, evtMemIdx, entryIdx;
    uint8 clearIdx;
    uint8 clearCnt = DEM_INIT_ZERO;
    uint8 clearEntryIdx[DEM_CFG_MAX_NUMBER_EVENT_ENTRY];
    uint16 clearEvtId[DEM_CFG_MAX_NUMBER_EVENT_ENTRY];
    uint16 evtIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx = DEM_INIT_ZERO;
    Dem_EventMemoryInfo_st *info_ptr;
    Dem_EventMemoryEntry_st *entry_ptr;
    
    evtMemIdx = DEM_GET_DTC_CLEAR_EVTMEMIDX();
    info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(evtMemIdx);
    entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);
    
    /* Copy Clear event memory entry and entry slot */
    for(slotIdx = DEM_INIT_ZERO; slotIdx < info_ptr->cntEnSlot; slotIdx++)
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        if(info_ptr->enSlot[slotIdx] > DEM_INIT_ZERO)
        {
            clearEntryIdx[clearCnt] = info_ptr->entryIdx[slotIdx];
            clearEvtId[clearCnt] = info_ptr->enSlot[slotIdx];
            clearCnt++;
        }
    }

    for(clearIdx = DEM_INIT_ZERO; clearIdx < clearCnt; clearIdx++)
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        evtIdx = Dem_CfgEventIdTableIndex[clearEvtId[clearIdx]];
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
        if((DEM_CLEAR_DTC_CLIENT_CDD != DEM_GET_DTC_CLEAR_CLIENT()) ||
           /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
           (TRUE == DEM_GET_AVAIL(evtIdx)))
#endif
        {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
            dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            if((FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)) || 
               (DEM_CLEAR_DTC_CLIENT_DCM != DEM_GET_DTC_CLEAR_CLIENT()))
            {
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
                /* Executing OBD 04 service to clear all DTC. */
                if((DEM_DTC_FORMAT_OBD == DEM_GET_DTC_CLEAR_FORMAT()) ||
#if( DEM_CFG_J1939SUPPORT == STD_ON )
                   (DEM_DTC_FORMAT_J1939 == DEM_GET_DTC_CLEAR_FORMAT()) ||
#endif
                   /* Executing UDS 14 service to clear all DTC. */
                   (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT()))
#elif( DEM_CFG_J1939SUPPORT == STD_ON )
                /* The DTC format of Dem_J1939DcmClearDTC is DEM_DTC_FORMAT_UDS. */
                if((DEM_DTC_FORMAT_J1939 == DEM_GET_DTC_CLEAR_FORMAT()) ||
                   (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT()))
#else
                if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT())
#endif
                {
                    Dem_EventClearDTCEntry(evtIdx, clearEntryIdx[clearIdx], evtMemIdx);
                }
            }
#else
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
            dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
            /* Executing OBD 04 service to clear all DTC. */
            if((DEM_DTC_FORMAT_OBD == DEM_GET_DTC_CLEAR_FORMAT()) ||
#if( DEM_CFG_J1939SUPPORT == STD_ON )
               (DEM_DTC_FORMAT_J1939 == DEM_GET_DTC_CLEAR_FORMAT()) ||
#endif
               /* Executing UDS 14 service to clear all DTC. */
               (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT()))
#elif( DEM_CFG_J1939SUPPORT == STD_ON )
            /* The DTC format of Dem_J1939DcmClearDTC is DEM_DTC_FORMAT_UDS. */
            if((DEM_DTC_FORMAT_J1939 == DEM_GET_DTC_CLEAR_FORMAT()) ||
               (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT()))
#else
            if(DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT())
#endif
            {
                Dem_EventClearDTCEntry(evtIdx, clearEntryIdx[clearIdx], evtMemIdx);
            }
#endif
        }
    }

    /* To prevent a event is in entryblock but not in infoblock */
    for(entryIdx = DEM_INIT_ZERO; entryIdx < Dem_CfgEventMemoryTable[evtMemIdx].acEvtMemMaxEntry; entryIdx++)
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
        if(entry_ptr[entryIdx].evtId != DEM_INIT_ZERO)
        {
            for(slotIdx = DEM_INIT_ZERO; slotIdx < info_ptr->cntEnSlot; slotIdx++)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(entry_ptr[entryIdx].evtId == info_ptr->enSlot[slotIdx])
                {
                    break;
                }
            }
            
            if(slotIdx >= info_ptr->cntEnSlot)
            {
                entry_ptr[entryIdx].evtId = DEM_INIT_ZERO;
#if(DEM_CFG_CLEARBEHAVIOR != DEM_CLRRESP_VOLATILE)
                /* Request update event memory entry block */
                Dem_EventMemoryNvmBlkUpdateReq(evtMemIdx,
                                               entryIdx,
                                               DEM_NVM_REQ_CLEAR,
                                               FALSE);
#endif
            }
        }
    }
    DEM_DUMMY_STATEMENT(dtcIdx);
}

/*
********************************************************************************
* Function Name: Dem_EventClearGroupDTC
*
* Explanation: Clear Group DTCs
*
* param: None
*
* retval: uint8, clear result
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, DEM_CODE) Dem_EventClearGroupDTC(void)
{
    uint8 ret;

#if(DEM_CFG_EVENT_NUM <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
    /* Clear event DTC status */
    Dem_EventClearGroupDTCStatus((Dem_EventClearGroupDTCCnt + DEM_INIT_ONE), DEM_CFG_EVENT_NUM);

    /* Clear event memory entry and entry slot */
    Dem_EventClearGroupDTCEntry();

    /* Set clearing NvM block request status after clearing all events status and entry. */
    DEM_SET_NVM_CLEAR_REQ_STATUS(TRUE);

    ret = E_OK;
#else
    /* Clear all event DTC status */
    if((DEM_CFG_EVENT_NUM - Dem_EventClearGroupDTCCnt) > DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
    {
        Dem_EventClearGroupDTCStatus((Dem_EventClearGroupDTCCnt + DEM_INIT_ONE), (Dem_EventClearGroupDTCCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM));
    }
    else
    {
        Dem_EventClearGroupDTCStatus((Dem_EventClearGroupDTCCnt + DEM_INIT_ONE), DEM_CFG_EVENT_NUM);
    }

    if((DEM_CFG_EVENT_NUM - Dem_EventClearGroupDTCCnt) <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM)
    {
        /* Clear event memory entry and entry slot */
        Dem_EventClearGroupDTCEntry();
        
        Dem_EventClearGroupDTCCnt = DEM_INIT_ZERO;
        ret = E_OK;
    }
    else
    {
        Dem_EventClearGroupDTCCnt += DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
        ret = E_NOT_OK;
    }
    
    /* Set clearing NvM block request status after clearing all events status and entry. */
    DEM_SET_NVM_CLEAR_REQ_STATUS(TRUE);

#endif

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventClearGroupDTCStatus
*
* Explanation: Clear Group DTCs status
*
* param: uint16 evtIdxStart, start index of clear action
*        uint16 evtIdxEnd, end index of clear action
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventClearGroupDTCStatus
(
    uint16 EventIdxStart,
    uint16 EventIdxEnd
)
{
    boolean isMatchMem = FALSE;
    uint8 breakFlag = FALSE;
    uint8 evtMemIdx;
    uint8 evtMemCnt;
    uint8 dtcGrpIdx;
    uint16 evtIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;
    uint32 evtDtcVal;
    uint32 grpDtcVal;

    dtcGrpIdx = DEM_GET_DTC_CLEAR_GRPIDX() + DEM_BYTE_ONE;
    grpDtcVal = DEM_GET_DTC_CLEAR_DTCVAL();

    if( (EventIdxStart > DEM_INIT_ZERO) && (EventIdxStart <= DEM_CFG_EVENT_NUM)
         &&(EventIdxEnd > DEM_INIT_ZERO) && (EventIdxEnd <= DEM_CFG_EVENT_NUM)
         &&(dtcGrpIdx > DEM_INIT_ZERO) && (dtcGrpIdx <= DEM_CFG_DTC_GROUP_NUM) )
    {
        for(evtIdx = EventIdxStart; evtIdx <= EventIdxEnd; evtIdx++)
        {
            /* PolySpace +1 MISRA-C3:20.7 [Justified:Unset] "NSCA_Polyspace_Dem_20.7" */
            evtDtcVal = DEM_DTCVALUE_CAL(Dem_CfgEvtDtcIdx[evtIdx]);
            if((evtDtcVal >= grpDtcVal) && 
               (evtDtcVal < Dem_CfgDTCGrpTable[dtcGrpIdx]))
            {
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
                if((DEM_CLEAR_DTC_CLIENT_CDD != DEM_GET_DTC_CLEAR_CLIENT()) ||
                   (TRUE == DEM_GET_AVAIL(evtIdx)))
#endif
                {
                    dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
                    isMatchMem = FALSE;
                    for( evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++ )
                    {
                        evtMemIdx = Dem_CfgDTCTable[dtcIdx].acEvtMemIdx[evtMemCnt];
                        if( evtMemIdx > DEM_INIT_ZERO )
                        {
                            if( DEM_GET_DTC_CLEAR_EVTMEMIDX() == evtMemIdx )
                            {
                                isMatchMem = TRUE;
                                breakFlag = TRUE;
                            }
                        }
                        else
                        {
                            breakFlag = TRUE;
                        }
                        /* Unified break channel. */
                        if(TRUE == breakFlag)
                        {
                            break;
                        }
                    }

                    if( TRUE == isMatchMem )
                    {

#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                        if( (FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)) || 
                            (DEM_CLEAR_DTC_CLIENT_DCM != DEM_GET_DTC_CLEAR_CLIENT()) )
                        {
#if( DEM_CFG_J1939SUPPORT == STD_ON )
                            if( (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT()) ||
                                (DEM_DTC_FORMAT_J1939 == DEM_GET_DTC_CLEAR_FORMAT()) )
#else
                            /* Executing UDS 14 service to clear DTC group. */
                            if( DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT() )
#endif
                            {
                                Dem_EventClearDTCStatus(evtIdx);
                            }
                        }
#else
#if( DEM_CFG_J1939SUPPORT == STD_ON )
                        if( (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT()) ||
                            (DEM_DTC_FORMAT_J1939 == DEM_GET_DTC_CLEAR_FORMAT()) )
#else
                        /* Executing UDS 14 service to clear DTC group. */
                        if( DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT() )
#endif
                        {
                            Dem_EventClearDTCStatus(evtIdx);
                        }
#endif
                    }
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventClearGroupDTCEntry
*
* Explanation: Clear Group DTCs entry in event memory
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventClearGroupDTCEntry(void)
{
    uint8 slotIdx, evtMemIdx;
    uint8 clearIdx;
    uint8 clearCnt = DEM_INIT_ZERO;
    uint8 clearEntryIdx[DEM_CFG_MAX_NUMBER_EVENT_ENTRY];
    uint8 dtcGrpIdx;
    uint16 clearEvtId[DEM_CFG_MAX_NUMBER_EVENT_ENTRY];
    uint16 evtIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx = DEM_INIT_ZERO; 
    uint32 evtDtcVal, grpDtcVal;
    Dem_EventMemoryInfo_st *info_ptr;
    
    dtcGrpIdx = DEM_GET_DTC_CLEAR_GRPIDX() + DEM_BYTE_ONE;
    grpDtcVal = DEM_GET_DTC_CLEAR_DTCVAL();
    evtMemIdx = DEM_GET_DTC_CLEAR_EVTMEMIDX();
    info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(evtMemIdx);
    
    /* Copy Clear event memory entry and entry slot */
    for(slotIdx = DEM_INIT_ZERO; slotIdx < info_ptr->cntEnSlot; slotIdx++)
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        if(info_ptr->enSlot[slotIdx] > DEM_INIT_ZERO)
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
            /* PolySpace +1 MISRA-C3:20.7 [Justified:Unset] "NSCA_Polyspace_Dem_20.7" */
            evtDtcVal = DEM_DTCVALUE_CAL(Dem_CfgEvtDtcIdx[evtIdx]);
            if( (evtDtcVal >= grpDtcVal) 
                && (dtcGrpIdx > DEM_INIT_ZERO) && (dtcGrpIdx <= DEM_CFG_DTC_GROUP_NUM) 
                && (evtDtcVal < Dem_CfgDTCGrpTable[dtcGrpIdx]) )
            {
                clearEntryIdx[clearCnt] = info_ptr->entryIdx[slotIdx];
                clearEvtId[clearCnt] = info_ptr->enSlot[slotIdx];
                clearCnt++;
            }
        }
    }

    for(clearIdx = DEM_INIT_ZERO; clearIdx < clearCnt; clearIdx++)
    {
        evtIdx = Dem_CfgEventIdTableIndex[clearEvtId[clearIdx]];

#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
        if((DEM_CLEAR_DTC_CLIENT_CDD != DEM_GET_DTC_CLEAR_CLIENT()) ||
           /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
           (TRUE == DEM_GET_AVAIL(evtIdx)))
#endif
        {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
            dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            if((FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)) || 
               (DEM_CLEAR_DTC_CLIENT_DCM != DEM_GET_DTC_CLEAR_CLIENT()))
            {
#if( DEM_CFG_J1939SUPPORT == STD_ON )
                if( (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT()) ||
                    (DEM_DTC_FORMAT_J1939 == DEM_GET_DTC_CLEAR_FORMAT()) )
#else
                /* Executing UDS 14 service to clear DTC group. */
                if( DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT() )
#endif
                {
                    Dem_EventClearDTCEntry(evtIdx, clearEntryIdx[clearIdx], evtMemIdx);
                }
            }
#else
#if( DEM_CFG_J1939SUPPORT == STD_ON )
            if( (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT()) ||
                (DEM_DTC_FORMAT_J1939 == DEM_GET_DTC_CLEAR_FORMAT()) )
#else
            /* Executing UDS 14 service to clear DTC group. */
            if( DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT() )
#endif
            {
                Dem_EventClearDTCEntry(evtIdx, clearEntryIdx[clearIdx], evtMemIdx);
            }
#endif
        }
    }
    DEM_DUMMY_STATEMENT(dtcIdx);
}

/*
********************************************************************************
* Function Name: Dem_EventClearSingleDTC
*
* Explanation: Clear Single DTC
*
* param: None
*
* retval: uint8, clear result
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, DEM_CODE) Dem_EventClearSingleDTC(void)
{
    uint8 ret;

#if( DEM_CFG_EVENT_NUM <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM )
    /* Clear event DTC status */
    Dem_EventClearSingleDTCStatus((Dem_EventClearSingleDTCCnt + DEM_INIT_ONE), DEM_CFG_EVENT_NUM);
    
    /* Clear event memory entry and entry slot */
    Dem_EventClearSingleDTCEntry();
    
    /* Set clearing NvM block request status after clearing all events status and entry. */
    DEM_SET_NVM_CLEAR_REQ_STATUS(TRUE);
    
    ret = E_OK;
#else
    /* Clear all event DTC status */
    if( (DEM_CFG_EVENT_NUM - Dem_EventClearSingleDTCCnt) > DEM_EVENT_DTC_SPILT_SEGMENT_NUM )
    {
        Dem_EventClearSingleDTCStatus((Dem_EventClearSingleDTCCnt + DEM_INIT_ONE), (Dem_EventClearSingleDTCCnt + DEM_EVENT_DTC_SPILT_SEGMENT_NUM) );
    }
    else
    {
        Dem_EventClearSingleDTCStatus((Dem_EventClearSingleDTCCnt + DEM_INIT_ONE), DEM_CFG_EVENT_NUM);
    }
    
    if( (DEM_CFG_EVENT_NUM - Dem_EventClearSingleDTCCnt) <= DEM_EVENT_DTC_SPILT_SEGMENT_NUM )
    {
        /* Clear event memory entry and entry slot */
        Dem_EventClearSingleDTCEntry();

        Dem_EventClearSingleDTCCnt = DEM_INIT_ZERO;
        ret = E_OK;
    }
    else
    {
        Dem_EventClearSingleDTCCnt += DEM_EVENT_DTC_SPILT_SEGMENT_NUM;
        ret = E_NOT_OK;
    }
    
    /* Set clearing NvM block request status after clearing all events status and entry. */
    DEM_SET_NVM_CLEAR_REQ_STATUS(TRUE);

#endif

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventClearSingleDTCStatus
*
* Explanation: Clear Single DTCs status
*
* param: uint16 evtIdxStart, start index of clear action
*        uint16 evtIdxEnd, end index of clear action
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventClearSingleDTCStatus
(
    uint16 EventIdxStart,
    uint16 EventIdxEnd
)
{
    boolean isMatchMem = FALSE;
    uint8 breakFlag = FALSE;
    uint8 evtMemIdx, evtMemCnt;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx;
    uint32 reqDtcVal;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( (EventIdxStart > DEM_INIT_ZERO) && (EventIdxStart <= DEM_CFG_EVENT_NUM) &&
        (EventIdxEnd > DEM_INIT_ZERO) && (EventIdxEnd <= DEM_CFG_EVENT_NUM) )
    {
        reqDtcVal = DEM_GET_DTC_CLEAR_DTCVAL();
        
        for( evtIdx = EventIdxStart; evtIdx <= EventIdxEnd; evtIdx++ )
        {
            dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
            if( (reqDtcVal == DEM_DTCVALUE_CAL(dtcIdx))
#if( DEM_CFG_J1939SUPPORT == STD_ON )
                || (reqDtcVal == Dem_CfgObdDTCTable[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx].awJ1939DtcVal)
#endif
              )
            {
#if( DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY )
                if( (DEM_CLEAR_DTC_CLIENT_CDD != DEM_GET_DTC_CLEAR_CLIENT()) ||
                    (TRUE == DEM_GET_AVAIL(evtIdx)) )
#endif
                {
                    isMatchMem = FALSE;
                    for( evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++ )
                    {
                        evtMemIdx = Dem_CfgDTCTable[dtcIdx].acEvtMemIdx[evtMemCnt];
                        if( evtMemIdx > DEM_INIT_ZERO )
                        {
                            if( DEM_GET_DTC_CLEAR_EVTMEMIDX() == evtMemIdx )
                            {
                                isMatchMem = TRUE;
                                breakFlag = TRUE;
                            }
                        }
                        else
                        {
                            breakFlag = TRUE;
                        }
                        /* Unified break channel. */
                        if(TRUE == breakFlag)
                        {
                            break;
                        }
                    }

                    if( TRUE == isMatchMem )
                    {

#if( DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION )
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                        if( (FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)) || 
                            (DEM_CLEAR_DTC_CLIENT_DCM != DEM_GET_DTC_CLEAR_CLIENT()) )
                        {
                            if( (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT())
#if( DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT )
                            || ((DEM_DTC_FORMAT_OBD == DEM_GET_DTC_CLEAR_FORMAT()) ||
                                ((DEM_INIT_ZERO == Dem_CfgDTCTable[dtcIdx].acObdDtcIdx) &&
                                (DEM_DTC_WWHOBD_CLASS_NOCLASS == Dem_CfgDTCTable[dtcIdx].acWwhObdClass)) ) /* case of OBD related */
#endif
                              )
                            {
                                Dem_EventClearDTCStatus(evtIdx);
                            }
                        }
#else
                        if( (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT())
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
                        || ((DEM_DTC_FORMAT_OBD == DEM_GET_DTC_CLEAR_FORMAT()) ||
                           ((DEM_INIT_ZERO == Dem_CfgDTCTable[dtcIdx].acObdDtcIdx) &&
                            (DEM_DTC_WWHOBD_CLASS_NOCLASS == Dem_CfgDTCTable[dtcIdx].acWwhObdClass))) /* case of OBD related */
#endif
                          )

                        {
                            Dem_EventClearDTCStatus(evtIdx);
                        }
#endif
                    }
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventClearSingleDTCEntry
*
* Explanation: Clear Single DTCs entry in event memory
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventClearSingleDTCEntry(void)
{
    uint8 slotIdx, evtMemIdx;
    uint8 clearIdx;
    uint8 clearCnt = DEM_INIT_ZERO;
    uint8 clearEntryIdx[DEM_CFG_MAX_NUMBER_EVENT_ENTRY];
    uint16 clearEvtId[DEM_CFG_MAX_NUMBER_EVENT_ENTRY];
    uint16 evtIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx = DEM_INIT_ZERO;
    uint32 reqDtcVal;
    Dem_EventMemoryInfo_st *info_ptr;
    
    reqDtcVal = DEM_GET_DTC_CLEAR_DTCVAL();
    evtMemIdx = DEM_GET_DTC_CLEAR_EVTMEMIDX();
    info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(evtMemIdx);
    
    /* Copy Clear event memory entry and entry slot */
    for( slotIdx = DEM_INIT_ZERO; slotIdx < info_ptr->cntEnSlot; slotIdx++ )
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        if( info_ptr->enSlot[slotIdx] > DEM_INIT_ZERO )
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
            dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
            if( (reqDtcVal == DEM_DTCVALUE_CAL(dtcIdx))
#if( DEM_CFG_J1939SUPPORT == STD_ON )
                || (reqDtcVal == Dem_CfgObdDTCTable[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx].awJ1939DtcVal)
#endif
              )
            {
                clearEntryIdx[clearCnt] = info_ptr->entryIdx[slotIdx];
                clearEvtId[clearCnt] = info_ptr->enSlot[slotIdx];
                clearCnt++;
            }
        }
    }

    for( clearIdx = DEM_INIT_ZERO; clearIdx < clearCnt; clearIdx++ )
    {
        evtIdx = Dem_CfgEventIdTableIndex[clearEvtId[clearIdx]];
#if( DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY )
        if( (DEM_CLEAR_DTC_CLIENT_CDD != DEM_GET_DTC_CLEAR_CLIENT()) ||
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            (TRUE == DEM_GET_AVAIL(evtIdx)) )
#endif
        {
#if( DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION )
            dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            if( (FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)) || 
                (DEM_CLEAR_DTC_CLIENT_DCM != DEM_GET_DTC_CLEAR_CLIENT()) )
            {
                if( (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT())
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
                 || ((DEM_DTC_FORMAT_OBD == DEM_GET_DTC_CLEAR_FORMAT()) ||
                    ((DEM_INIT_ZERO == Dem_CfgDTCTable[dtcIdx].acObdDtcIdx) &&
                     (DEM_DTC_WWHOBD_CLASS_NOCLASS == Dem_CfgDTCTable[dtcIdx].acWwhObdClass))) /* case of OBD related */
#endif
                  )
                {
                    Dem_EventClearDTCEntry(evtIdx, clearEntryIdx[clearIdx], evtMemIdx);
                }
            }
#else
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
            dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#endif
            if( (DEM_DTC_FORMAT_UDS == DEM_GET_DTC_CLEAR_FORMAT())
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
                 || ((DEM_DTC_FORMAT_OBD == DEM_GET_DTC_CLEAR_FORMAT()) ||
                    ((DEM_INIT_ZERO == Dem_CfgDTCTable[dtcIdx].acObdDtcIdx) &&
                    (DEM_DTC_WWHOBD_CLASS_NOCLASS == Dem_CfgDTCTable[dtcIdx].acWwhObdClass))) /* case of OBD related */
#endif
                  )
            {
                Dem_EventClearDTCEntry(evtIdx, clearEntryIdx[clearIdx], evtMemIdx);
            }
#endif
        }
    }
    DEM_DUMMY_STATEMENT(dtcIdx);
}

/*
********************************************************************************
* Function Name: Dem_EventClearDTCInfo
*
* Explanation: Clear the first/most recent confirmed/failed DTC information in
*              Dem_EventMemoryInfo.
*
* param: uint16 EventIdx, event index
*
* retval: None
********************************************************************************
*/
static FUNC(void, DEM_CODE) Dem_EventClearDTCInfo
(
    uint16 EventIdx
)
{
    uint8 evtMemIdx;
    Dem_EventMemoryInfo_st *info_ptr;

    /* Get the Dem_EventMemoryInfo. */
    evtMemIdx = DEM_GET_DTC_CLEAR_EVTMEMIDX();
    info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(evtMemIdx);

    /* Check whether the requested DTC is the first/most recent confirmed/failed DTC. */
    if(EventIdx == info_ptr->firstConfirmEvtId)
    {
        info_ptr->firstConfirmEvtId = DEM_INIT_ZERO;
    }
    if(EventIdx == info_ptr->firstFaliedEvtId)
    {
        info_ptr->firstFaliedEvtId = DEM_INIT_ZERO;
    }
    if(EventIdx == info_ptr->recentlyConfirmEvtId)
    {
        info_ptr->recentlyConfirmEvtId = DEM_INIT_ZERO;
    }
    if(EventIdx == info_ptr->recentlyFaliedEvtId)
    {
        info_ptr->recentlyFaliedEvtId = DEM_INIT_ZERO;
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmRead
*
* Explanation: Nvm block read process
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryNvmRead(void)
{
    Std_ReturnType retVal = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 nvmBlkCnt, nvmBlkIdx;
    
    for(nvmBlkCnt = DEM_INIT_ONE; nvmBlkCnt <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkCnt++)
    {
        if(TRUE == DEM_GET_NVM_READ_REQ(nvmBlkCnt))
        {
#if(STD_ON == DEM_CFG_NVM_RW_SUPPORT)
            retVal = NvM_ReadBlock(Dem_CfgNvmBlockTable[nvmBlkCnt], NULL_PTR);
#endif /* STD_ON == DEM_CFG_NVM_RW_SUPPORT */
            DEM_SET_NVM_READ_REQ(nvmBlkCnt, FALSE);
            if(E_OK == retVal)
            {
                DEM_SET_NVM_STATE(DEM_NVM_STATE_READ);
                DEM_SET_NVM_ACCESS_BLOCK_IDX(nvmBlkCnt);
            }
            else
            {
                DEM_SET_NVM_STATUS(nvmBlkCnt, DEM_NVM_BLOCK_STATUS_ERROR);
                DEM_SET_NVM_READ_REQ_STATUS(FALSE);
                /* Nvm error happened, stop further action, clear left read request */
                for(nvmBlkIdx = nvmBlkCnt + DEM_BYTE_ONE; nvmBlkIdx <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkIdx++)
                {
                    DEM_SET_NVM_READ_REQ(nvmBlkIdx, FALSE);
                }
                /* Reuqest to initialize all blocks with default values, set clear flag */
                DEM_SET_NVM_STATE(DEM_NVM_STATE_INITIAL);
                for(nvmBlkIdx = DEM_BYTE_ONE; nvmBlkIdx <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkIdx++)
                {
                    DEM_SET_NVM_CLEAR_REQ(nvmBlkIdx, TRUE);
                }
            }
            break;
        }
    }

    if(nvmBlkCnt > DEM_CFG_NVM_BLOCK_NUM)
    {
        /* All blocks read request finished */
        DEM_SET_NVM_READ_REQ_STATUS(FALSE);
        DEM_SET_NVM_ACCESS_BLOCK_IDX(DEM_INIT_ZERO);
        DEM_SET_NVM_STATE(DEM_NVM_STATE_DONE);
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmReadCheck
*
* Explanation: Nvm block read check process 
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryNvmReadCheck(void)
{
    Std_ReturnType retVal;
    uint8 errStatus = DEM_NVM_REQ_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 nvmBlkCnt, nvmBlkIdx;
    
    nvmBlkIdx = DEM_GET_NVM_ACCESS_BLOCK_IDX();
    if((nvmBlkIdx > DEM_INIT_ZERO) && (nvmBlkIdx <= DEM_CFG_NVM_BLOCK_NUM))
    {
        retVal = NvM_GetErrorStatus(Dem_CfgNvmBlockTable[nvmBlkIdx], &errStatus);

        if(E_OK == retVal)
        {
            if(DEM_NVM_REQ_OK == errStatus)
            {
                Dem_EventMemoryNvmRead();
            }
            else if(DEM_NVM_REQ_PENDING == errStatus)
            {
                /* Do nothing, keep waiting */
            }
            else
            {
                DEM_SET_NVM_STATUS(nvmBlkIdx, DEM_NVM_BLOCK_STATUS_ERROR);
                /* Nvm error happened, stop further action, clear left read request */
                DEM_SET_NVM_READ_REQ_STATUS(FALSE);
                for(nvmBlkCnt = nvmBlkIdx + DEM_BYTE_ONE; nvmBlkCnt <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkCnt++)
                {
                    DEM_SET_NVM_READ_REQ(nvmBlkCnt, FALSE);
                }
                /* Reuqest to initialize all blocks with default values, set clear flag */
                DEM_SET_NVM_STATE(DEM_NVM_STATE_INITIAL);
                for(nvmBlkCnt = DEM_BYTE_ONE; nvmBlkCnt <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkCnt++)
                {
                    DEM_SET_NVM_CLEAR_REQ(nvmBlkCnt, TRUE);
                }
            }
        }
        else
        {
            DEM_SET_NVM_STATUS(nvmBlkIdx, DEM_NVM_BLOCK_STATUS_ERROR);
            /* Nvm error happened, stop further action, clear left read request */
            DEM_SET_NVM_READ_REQ_STATUS(FALSE);
            for(nvmBlkCnt = nvmBlkIdx + DEM_BYTE_ONE; nvmBlkCnt <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkCnt++)
            {
                DEM_SET_NVM_READ_REQ(nvmBlkCnt, FALSE);
            }
            /* Reuqest to initialize all blocks with default values, set clear flag */
            DEM_SET_NVM_STATE(DEM_NVM_STATE_INITIAL);
            for(nvmBlkCnt = DEM_BYTE_ONE; nvmBlkCnt <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkCnt++)
            {
                DEM_SET_NVM_CLEAR_REQ(nvmBlkCnt, TRUE);
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmClear
*
* Explanation: Nvm block clear process
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryNvmClear(void)
{
    Std_ReturnType retVal = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 nvmBlkCnt, nvmBlkIdx;
    uint32 srcPtr = DEM_INIT_ZERO;
    
    for(nvmBlkCnt = (DEM_GET_NVM_ACCESS_BLOCK_IDX() + DEM_BYTE_ONE); nvmBlkCnt <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkCnt++)
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        if(TRUE == DEM_GET_NVM_CLEAR_REQ(nvmBlkCnt))
        {
            DEM_SET_NVM_CLEAR_REQ(nvmBlkCnt, FALSE);
            
            if(E_OK == Dem_EventMemoryNvmPrepare(nvmBlkCnt, &srcPtr))
            {
#if(STD_ON == DEM_CFG_NVM_RW_SUPPORT)
                /* PolySpace +1 MISRA-C3:11.4 [Justified:Unset] "NSCA_Polyspace_Dem_11.4" */
                retVal = NvM_WriteBlock(Dem_CfgNvmBlockTable[nvmBlkCnt], (uint8*)srcPtr);  /* PRQA S 0306 */ /* NSCA_QAC_Dem_VarTypeConvert */
#endif /* STD_ON == DEM_CFG_NVM_RW_SUPPORT */
                if(E_OK == retVal)
                {
                    DEM_SET_NVM_STATE(DEM_NVM_STATE_CLEAR);
                    DEM_SET_NVM_ACCESS_BLOCK_IDX(nvmBlkCnt);
                }
                else
                {
                    DEM_SET_NVM_STATUS(nvmBlkCnt, DEM_NVM_BLOCK_STATUS_ERROR);
                    /* Nvm error happened, stop further action, clear left clear request */
                    for(nvmBlkIdx = nvmBlkCnt + DEM_BYTE_ONE; nvmBlkIdx <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkIdx++)
                    {
                        DEM_SET_NVM_CLEAR_REQ(nvmBlkIdx, FALSE);
                    }
                    DEM_SET_NVM_ACCESS_BLOCK_IDX(DEM_INIT_ZERO);    /* Clear access idx */
                    DEM_SET_NVM_CLEAR_REQ_STATUS(FALSE);
                    DEM_SET_NVM_STATE(DEM_NVM_STATE_FAILED);
                }
                break;
            }
        }
    }

    if(nvmBlkCnt > DEM_CFG_NVM_BLOCK_NUM)
    {
        /* All blocks clear request finished */
        DEM_SET_NVM_CLEAR_REQ_STATUS(FALSE);
        DEM_SET_NVM_ACCESS_BLOCK_IDX(DEM_INIT_ZERO);
#if(DEM_CFG_CLEARBEHAVIOR == DEM_CLRRESP_NONVOLATILE_TRIGGER)
        DEM_SET_NVM_STATE(DEM_NVM_STATE_IDLE);
#else
        DEM_SET_NVM_STATE(DEM_NVM_STATE_DONE);
#endif
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmClearCheck
*
* Explanation: Nvm block clear check process
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryNvmClearCheck(void)
{
    Std_ReturnType retVal;
    uint8 errStatus = DEM_NVM_REQ_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 nvmBlkCnt, nvmBlkIdx;

    nvmBlkIdx = DEM_GET_NVM_ACCESS_BLOCK_IDX();
    if((nvmBlkIdx > DEM_INIT_ZERO) && (nvmBlkIdx <= DEM_CFG_NVM_BLOCK_NUM))
    {
        retVal = NvM_GetErrorStatus(Dem_CfgNvmBlockTable[nvmBlkIdx], &errStatus);

        if(E_OK == retVal)
        {
            if(DEM_NVM_REQ_OK == errStatus)
            {
                Dem_EventMemoryNvmClear();
            }
            else if(DEM_NVM_REQ_PENDING == errStatus)
            {
                /* Do nothing, keep waiting */
            }
            else
            {
                DEM_SET_NVM_STATUS(nvmBlkIdx, DEM_NVM_BLOCK_STATUS_ERROR);
                /* Nvm clear error happened, stop further action, clear left clear request */
                for(nvmBlkCnt = nvmBlkIdx + DEM_BYTE_ONE; nvmBlkCnt <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkCnt++)
                {
                    DEM_SET_NVM_CLEAR_REQ(nvmBlkCnt, FALSE);
                }
                DEM_SET_NVM_ACCESS_BLOCK_IDX(DEM_INIT_ZERO);    /* Clear access idx */
                DEM_SET_NVM_CLEAR_REQ_STATUS(FALSE);
#if(DEM_CFG_CLEARBEHAVIOR == DEM_CLRRESP_NONVOLATILE_TRIGGER)
                DEM_SET_NVM_STATE(DEM_NVM_STATE_IDLE);
#else
                if(DEM_NVM_REQ_INVALIDATED == errStatus)
                {
                    DEM_SET_NVM_STATE(DEM_NVM_STATE_INVALIDATED);
                }
                else
                {
                    DEM_SET_NVM_STATE(DEM_NVM_STATE_FAILED);
                }
#endif
            }
        }
        else
        {
            DEM_SET_NVM_STATUS(nvmBlkIdx, DEM_NVM_BLOCK_STATUS_ERROR);
            /* Nvm clear error happened, stop further action, clear left clear request */
            for(nvmBlkCnt = nvmBlkIdx + DEM_BYTE_ONE; nvmBlkCnt <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkCnt++)
            {
                DEM_SET_NVM_CLEAR_REQ(nvmBlkCnt, FALSE);
            }
            DEM_SET_NVM_ACCESS_BLOCK_IDX(DEM_INIT_ZERO);    /* Clear access idx */
            DEM_SET_NVM_CLEAR_REQ_STATUS(FALSE);
#if(DEM_CFG_CLEARBEHAVIOR == DEM_CLRRESP_NONVOLATILE_TRIGGER)
            DEM_SET_NVM_STATE(DEM_NVM_STATE_IDLE);
#else
            DEM_SET_NVM_STATE(DEM_NVM_STATE_FAILED);
#endif
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmWrite
*
* Explanation: Nvm block write process
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryNvmWrite(void)
{
    Std_ReturnType retVal = E_OK;
    uint8 breakFlag = FALSE;
    uint16 nvmBlkCnt;
    uint32 srcPtr = DEM_INIT_ZERO;

    for(nvmBlkCnt = (DEM_GET_NVM_ACCESS_BLOCK_IDX() + DEM_BYTE_ONE); nvmBlkCnt <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkCnt++)
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        if((TRUE == DEM_GET_NVM_WRITE_REQ(nvmBlkCnt)) &&
           (TRUE == DEM_GET_NVM_IME_STORE(nvmBlkCnt)))
        {
            if(DEM_GET_NVM_IME_STORE_CNT() < DEM_CFG_IMMEDIATENVSTORAGELIMIT)
            {                
                DEM_SET_NVM_WRITE_REQ(nvmBlkCnt, FALSE);
                DEM_SET_NVM_IME_STORE(nvmBlkCnt, FALSE);
                
                if(E_OK == Dem_EventMemoryNvmPrepare(nvmBlkCnt, &srcPtr))
                {
#if(STD_ON == DEM_CFG_NVM_RW_SUPPORT)
                    /* PolySpace +1 MISRA-C3:11.4 [Justified:Unset] "NSCA_Polyspace_Dem_11.4" */
                    retVal = NvM_WriteBlock(Dem_CfgNvmBlockTable[nvmBlkCnt], (uint8 *)srcPtr);  /* PRQA S 0306 */ /* NSCA_QAC_Dem_VarTypeConvert */
#endif /* STD_ON == DEM_CFG_NVM_RW_SUPPORT */
                    if(E_OK == retVal)
                    {
                        DEM_SET_NVM_STATE(DEM_NVM_STATE_WRITE);
                        DEM_SET_NVM_ACCESS_BLOCK_IDX(nvmBlkCnt);
                        breakFlag = TRUE;
                    }
                    else
                    {
                        DEM_SET_NVM_STATUS(nvmBlkCnt, DEM_NVM_BLOCK_STATUS_ERROR);
                        /* Nvm write error happened, try next block */
                    }
                }
            }
            else
            {
                DEM_SET_NVM_WRITE_REQ_STATUS(FALSE);
                DEM_SET_NVM_ACCESS_BLOCK_IDX(DEM_INIT_ZERO);
                DEM_SET_NVM_STATE(DEM_NVM_STATE_IDLE);
                breakFlag = TRUE;
            }
            /* Unified break channel. */
            if(TRUE == breakFlag)
            {
                break;
            }
        }
    }

    if(nvmBlkCnt > DEM_CFG_NVM_BLOCK_NUM)
    {
        /* All blocks write request finished */
        DEM_SET_NVM_WRITE_REQ_STATUS(FALSE);
        DEM_SET_NVM_ACCESS_BLOCK_IDX(DEM_INIT_ZERO);
        DEM_SET_NVM_STATE(DEM_NVM_STATE_IDLE);
        
        if(TRUE == DEM_GET_NVM_IME_STORE_REQ())
        {
            DEM_SET_NVM_IME_STORE_REQ(FALSE);
            DEM_SET_NVM_IME_STORE_CNT(DEM_GET_NVM_IME_STORE_CNT() + DEM_INIT_ONE);
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmWriteCheck
*
* Explanation: Nvm block write check process 
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryNvmWriteCheck(void)
{
    Std_ReturnType retVal;
    uint8 errStatus = DEM_NVM_REQ_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 nvmBlkIdx;

    nvmBlkIdx = DEM_GET_NVM_ACCESS_BLOCK_IDX();
    if((nvmBlkIdx > DEM_INIT_ZERO) && (nvmBlkIdx <= DEM_CFG_NVM_BLOCK_NUM))
    {
        retVal = NvM_GetErrorStatus(Dem_CfgNvmBlockTable[nvmBlkIdx], &errStatus);

        if(E_OK == retVal)
        {
            if(DEM_NVM_REQ_OK == errStatus)
            {
                Dem_EventMemoryNvmWrite();
            }
            else if(DEM_NVM_REQ_PENDING == errStatus)
            {
                /* Do nothing, keep waiting */
            }
            else
            {
                DEM_SET_NVM_STATUS(nvmBlkIdx, DEM_NVM_BLOCK_STATUS_ERROR);
                /* Nvm write error happened, try next block */
                Dem_EventMemoryNvmWrite();
            }
        }
        else
        {
            DEM_SET_NVM_STATUS(nvmBlkIdx, DEM_NVM_BLOCK_STATUS_ERROR);
            /* Nvm write error happened, try next block */
            Dem_EventMemoryNvmWrite();
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmProcess
*
* Explanation: Nvm block read/write process for Dem event memory
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventMemoryNvmProcess(void)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 nvmBlkIdx;
    
    switch(DEM_GET_NVM_STATE())
    {
        case DEM_NVM_STATE_IDLE:
        {
            if(TRUE == DEM_GET_NVM_READ_REQ_STATUS())
            {
                Dem_EventMemoryNvmRead();
            }
            else if(TRUE == DEM_GET_NVM_CLEAR_REQ_STATUS())
            {
                Dem_EventMemoryNvmClear();
            }
            else if(TRUE == DEM_GET_NVM_WRITE_REQ_STATUS())
            {
                Dem_EventMemoryNvmWrite();
            }
            else
            {
                /* No request, do nothing */
            }
            break;
        }
        case DEM_NVM_STATE_READ:
        {
            Dem_EventMemoryNvmReadCheck();
            break;
        }
        case DEM_NVM_STATE_CLEAR:
        {
            Dem_EventMemoryNvmClearCheck();
            break;
        }
        case DEM_NVM_STATE_WRITE:
        {
            Dem_EventMemoryNvmWriteCheck();
            break;
        }
        case DEM_NVM_STATE_INITIAL:
        {
            for(nvmBlkIdx = DEM_INIT_ONE; nvmBlkIdx <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkIdx++)
            {
                if(TRUE == DEM_GET_NVM_CLEAR_REQ(nvmBlkIdx))
                {
                    Dem_EventMemoryNvmInitialize(nvmBlkIdx);
                    DEM_SET_NVM_CLEAR_REQ(nvmBlkIdx, FALSE);
                    DEM_SET_NVM_STATUS(nvmBlkIdx, DEM_NVM_BLOCK_STATUS_NO_ERROR);
                    break;
                }
            }

            if(nvmBlkIdx == DEM_CFG_NVM_BLOCK_NUM)
            {
                DEM_SET_NVM_STATE(DEM_NVM_STATE_DONE);
            }
            break;
        }
        case DEM_NVM_STATE_FAILED:
        case DEM_NVM_STATE_DONE:
        default:
        {
            break;
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmRequest
*
* Explanation: Nvm block access request of Dem event memory
*
* param: uint8 OperationType, access request type
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryNvmRequest
(
    uint8 OperationType, 
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 NvmBlkIdx
)
{
    if((NvmBlkIdx > DEM_INIT_ZERO) && (NvmBlkIdx <= DEM_CFG_NVM_BLOCK_NUM))
    {
        switch(OperationType)
        {
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            case DEM_NVM_REQ_NONE:
            {
                DEM_SET_NVM_READ_REQ_STATUS(DEM_NVM_REQ_NONE);
                break;
            }
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            case DEM_NVM_REQ_READ:
            {
                DEM_SET_NVM_READ_REQ(NvmBlkIdx, TRUE);
                DEM_SET_NVM_READ_REQ_STATUS(TRUE);
                break;
            }
            case DEM_NVM_REQ_CLEAR:
            {
                DEM_SET_NVM_CLEAR_REQ(NvmBlkIdx, TRUE);

                /* Cancel write request */
                DEM_SET_NVM_WRITE_REQ(NvmBlkIdx, FALSE);
                break;
            }
            case DEM_NVM_REQ_WRITE:
            {
                DEM_SET_NVM_WRITE_REQ(NvmBlkIdx, TRUE);
                DEM_SET_NVM_WRITE_REQ_STATUS(TRUE);
                break;
            }
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            default:
            {
                break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmBlkIndex
*
* Explanation: calculate the nvm block index for NVM block update
*
* param: uint8 evtMemIdx, event memory index
*        uint8 entryIdx, entry index, OxFF means event memory info block
*
* retval: uint16 nvmBlkIdx, nvm block index
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint16, DEM_CODE) Dem_EventMemoryNvmBlkIndex
(
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 nvmBlkIdx = DEM_INIT_ZERO;

    /* Nvm blocks in Dem_CfgNvmBlockTable are listed in a sequence of  */
    /*        none                                                     */
    /*        Dem_EventMemoryStatus                                    */
    /*        Dem_PrimaryEventMemoryInfo                               */
    /*        Dem_PrimaryEventMemoryEntry[]                            */
    /*        Dem_User0EventMemoryInfo                                 */
    /*        Dem_User0EventMemoryEntry[]                              */
    /*        Dem_User1EventMemoryInfo                                 */
    /*        Dem_User1EventMemoryEntry[]                              */
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if(EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM)
    {
        switch(Dem_CfgEventMemoryTable[EventMemIdx].acEvtMemType)
        {
            case DEM_EVENT_MEMORY_NONE:
            {
                if(DEM_NVM_STATUS_BLOCK == EntryIdx)
                {
                    /* the index of event status block is 1 */
                    nvmBlkIdx = DEM_EVENT_STATUS_BLOCK;
                }
                else if(DEM_NVM_PERMANET_BLOCK == EntryIdx)
                {
                    /* the index of permanet block */
#if(DEM_CFG_EVENT_MEMORY_NUM == DEM_BYTE_ONE)
                    {
                        nvmBlkIdx = DEM_PRIMARY_ENTRY_BLOCK_END + DEM_INIT_ONE;
                    }
#elif(DEM_CFG_EVENT_MEMORY_NUM == DEM_BYTE_TWO)
                    {
                        nvmBlkIdx = DEM_USER0_ENTRY_BLOCK_END + DEM_INIT_ONE;
                    }
#elif(DEM_CFG_EVENT_MEMORY_NUM == DEM_BYTE_THREE)
                    {
                        nvmBlkIdx = DEM_USER1_ENTRY_BLOCK_END + DEM_INIT_ONE;
                    }
#else
                    {
                        nvmBlkIdx = DEM_INIT_ZERO;
                    }
#endif
                }
                else
                {
                    nvmBlkIdx = DEM_INIT_ZERO;
                }
                break;
            }
            case DEM_EVENT_MEMORY_PRIMARY:
            {
                /* primary event memory block */
                if(DEM_NVM_INFO_BLOCK == EntryIdx)
                {
                    /* the index of primary event memory info block is 2 */
                    nvmBlkIdx = DEM_PRIMARY_INFO_BLOCK;
                }
                else
                {
                    /* calculate the index of primary event memory enrty block */
                    nvmBlkIdx = (uint16)DEM_PRIMARY_ENTRY_BLOCK_START + EntryIdx;
                }
                break;
            }
            case DEM_EVENT_MEMORY_USER:
            {
                /* user defined event memory block */
                if(DEM_BYTE_TWO == EventMemIdx)
                {
                    /* user0 event memory block */
                    if(DEM_NVM_INFO_BLOCK == EntryIdx)
                    {
                        /* the index of user0 event memory info block */
                        nvmBlkIdx = DEM_USER0_INFO_BLOCK;
                    }
                    else
                    {
                        /* calculate the index of user0 event memory enrty block */
                        nvmBlkIdx = DEM_USER0_ENTRY_BLOCK_START + EntryIdx;
                    }
                }
                else
                {
                    /* user1 event memory block */
                    if(DEM_NVM_INFO_BLOCK == EntryIdx)
                    {
                        /* the index of user1 event memory info block */
                        nvmBlkIdx = DEM_USER1_INFO_BLOCK;
                    }
                    else
                    {
                        /* calculate the index of user1 event memory enrty block */
                        nvmBlkIdx = DEM_USER0_ENTRY_BLOCK_START + EntryIdx;
                    }
                }
                break;
            }
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" */
            default:
            {
                nvmBlkIdx = DEM_INIT_ZERO;
                break;
            }
        }
    }

    return nvmBlkIdx;
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmBlkUpdateReq
*
* Explanation: calculate the nvm block index for NVM block update
*
* param: uint8 evtMemIdx, event memory index
*        uint8 entryIdx, entry index, OxFF means event memory info block
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventMemoryNvmBlkUpdateReq
(
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx,
    uint8 OperationType,
    boolean ImmediateStore
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 nvmBlkIdx;
    
    /* Trigger EventMemoryInfo block update */
    nvmBlkIdx = Dem_EventMemoryNvmBlkIndex(EventMemIdx, EntryIdx);
    Dem_EventMemoryNvmRequest(OperationType, nvmBlkIdx);
    /* Immdiate Store? */
    if((TRUE == ImmediateStore) &&
       ((nvmBlkIdx > DEM_INIT_ZERO) && (nvmBlkIdx <= DEM_CFG_NVM_BLOCK_NUM)) &&
       (FALSE == DEM_GET_NVM_IME_STORE(nvmBlkIdx)))
    {
        DEM_SET_NVM_IME_STORE(nvmBlkIdx, TRUE);
        DEM_SET_NVM_IME_STORE_REQ(TRUE);
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmInitialize
*
* Explanation: Initialization of NvRam data when read failed
*
* param: uint16 NvmBlkIdx, NVM block index
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryNvmInitialize
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 NvmBlkIdx
)
{
    if(DEM_EVENT_STATUS_BLOCK == NvmBlkIdx)
    {
        /* Event status block */
        Dem_EventMemoryNvmStatusBlockInit();
#if(DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON)
        (void)NvM_SetRamBlockStatus(Dem_CfgNvmBlockTable[NvmBlkIdx], TRUE);
#endif /* DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON */
    }
    else if(DEM_PRIMARY_INFO_BLOCK == NvmBlkIdx)
    {
        /* Primary event memory info block */
        Dem_EventMemoryNvmInfoBlockInit(&Dem_PrimaryEventMemoryInfo);
#if(DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON)
        (void)NvM_SetRamBlockStatus(Dem_CfgNvmBlockTable[NvmBlkIdx], TRUE);
#endif /* DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON */
    }
    else if((DEM_PRIMARY_ENTRY_BLOCK_START <= NvmBlkIdx) && 
            (DEM_PRIMARY_ENTRY_BLOCK_END >= NvmBlkIdx))
    {
        /* Primary event memory entry block */
        Dem_PrimaryEventMemoryEntry[NvmBlkIdx - DEM_PRIMARY_ENTRY_BLOCK_START].evtId = DEM_INIT_ZERO;
#if(DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON)
        (void)NvM_SetRamBlockStatus(Dem_CfgNvmBlockTable[NvmBlkIdx], TRUE);
#endif /* DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON */
    }
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_ONE)
    else if(DEM_USER0_INFO_BLOCK == NvmBlkIdx)
    {
        /* User0 event memory info block */
        Dem_EventMemoryNvmInfoBlockInit(&Dem_User0EventMemoryInfo);
#if(DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON)
        (void)NvM_SetRamBlockStatus(Dem_CfgNvmBlockTable[NvmBlkIdx], TRUE);
#endif /* DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON */
    }
    else if((DEM_USER0_ENTRY_BLOCK_START <= NvmBlkIdx) &&
            (DEM_USER0_ENTRY_BLOCK_END >= NvmBlkIdx))
    {
        /* User0 event memory entry block */
        Dem_User0EventMemoryEntry[NvmBlkIdx - DEM_USER0_ENTRY_BLOCK_START].evtId = DEM_INIT_ZERO;
#if(DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON)
        (void)NvM_SetRamBlockStatus(Dem_CfgNvmBlockTable[NvmBlkIdx], TRUE);
#endif /* DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON */
    }
#endif
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_TWO)
    else if(DEM_USER1_INFO_BLOCK == NvmBlkIdx)
    {
        /* User1 event memory info block */
        Dem_EventMemoryNvmInfoBlockInit(&Dem_User1EventMemoryInfo);
#if(DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON)
        (void)NvM_SetRamBlockStatus(Dem_CfgNvmBlockTable[NvmBlkIdx], TRUE);
#endif /* DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON */
    }
    else if((DEM_USER1_ENTRY_BLOCK_START <= NvmBlkIdx) &&
            (DEM_USER1_ENTRY_BLOCK_END >= NvmBlkIdx))
    {
        /* User1 event memory entry block */
        Dem_User1EventMemoryEntry[NvmBlkIdx - DEM_USER1_ENTRY_BLOCK_START].evtId = DEM_INIT_ZERO;
#if(DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON)
        (void)NvM_SetRamBlockStatus(Dem_CfgNvmBlockTable[NvmBlkIdx], TRUE);
#endif /* DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON */
    }
#endif
    else
    {
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
#if(DEM_CFG_EVENT_MEMORY_NUM == DEM_BYTE_ONE)
        if((DEM_PRIMARY_ENTRY_BLOCK_END + DEM_INIT_ONE) == NvmBlkIdx)
        {
            /* Permanent event memory info block */
            Dem_EventMemoryNvmPermBlockInit(&Dem_PermanentEventMemoryEntry);
#if(DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON)
            (void)NvM_SetRamBlockStatus(Dem_CfgNvmBlockTable[NvmBlkIdx], TRUE);
#endif /* DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON */
        }
#elif(DEM_CFG_EVENT_MEMORY_NUM == DEM_BYTE_TWO)
        if((DEM_USER0_ENTRY_BLOCK_END + DEM_INIT_ONE) == NvmBlkIdx)
        {
            /* Permanent event memory info block */
            Dem_EventMemoryNvmPermBlockInit(&Dem_PermanentEventMemoryEntry);
#if(DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON)
            (void)NvM_SetRamBlockStatus(Dem_CfgNvmBlockTable[NvmBlkIdx], TRUE);
#endif /* DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON */
        }
#elif(DEM_CFG_EVENT_MEMORY_NUM == DEM_BYTE_THREE)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if((DEM_USER1_ENTRY_BLOCK_END + DEM_INIT_ONE) == NvmBlkIdx)
        {
            /* Permanent event memory info block */
            Dem_EventMemoryNvmPermBlockInit(&Dem_PermanentEventMemoryEntry);
#if(DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON)
            (void)NvM_SetRamBlockStatus(Dem_CfgNvmBlockTable[NvmBlkIdx], TRUE);
#endif /* DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON */
        }
#else
        {
            /* do nothing */
        }
#endif
#endif
    }

}

/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmStatusBlockInit
*
* Explanation: Initialization of Status Block
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryNvmStatusBlockInit(void)
{
    uint8 opcycIdx;
    uint16 evtIdx;

    /* Initializaiton of event memory status blcok RAM structer */
    for(evtIdx = DEM_INIT_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
    {
        DEM_SET_UDS_STATUS(evtIdx, DEM_EVENT_DTC_STATUS_INIT);
#if(DEM_CFG_EXTENDSTATUSBYTE != DEM_INIT_ZERO)
        DEM_SET_STATUS_INDI(evtIdx, DEM_INIT_ZERO);
#endif
        DEM_SET_UDS_FAILED_CNT(evtIdx, DEM_INIT_ZERO);
        DEM_SET_FDCCNTMAX_SLC(evtIdx, DEM_INIT_ZERO);
        DEM_SET_STORED_DEBCNT(evtIdx, DEM_INIT_ZERO);  /* PRQA S 1291 */ /* NSCA_QAC_Common_Rule10.3 */
#if(DEM_CFG_AGEDCTRSUPPORT == STD_ON)
        DEM_SET_AGED_CNT(evtIdx, DEM_INIT_ZERO);
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
        DEM_SET_AGED_CNT2(evtIdx, DEM_INIT_ZERO);
#endif
#endif
    }

    for(opcycIdx = DEM_INIT_ONE; opcycIdx <= DEM_CFG_OPCYC_NUM; opcycIdx++)
    {
        DEM_SET_OPCYC_STATE(opcycIdx, DEM_CYCLE_STATE_END);
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmStatusBlockInit
*
* Explanation: Initialization of Info Block
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryNvmInfoBlockInit
(
    P2VAR(Dem_EventMemoryInfo_st, AUTOMATIC, DEM_APPL_DATA) Info_ptr
)
{
    uint8 slotCnt;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if(Info_ptr != NULL_PTR)
    {
        /* Initializaiton of event memory info blcok RAM structer */
        Info_ptr->cntEnSlot = DEM_INIT_ZERO;
        for(slotCnt = DEM_INIT_ZERO; slotCnt < DEM_CFG_MAX_NUMBER_EVENT_ENTRY; slotCnt++)
        {
            Info_ptr->entryIdx[slotCnt] = DEM_INIT_ZERO;
            Info_ptr->enSlot[slotCnt] = DEM_INIT_ZERO;
        }
        Info_ptr->firstFaliedEvtId = DEM_INIT_ZERO;
        Info_ptr->recentlyFaliedEvtId = DEM_INIT_ZERO;
        Info_ptr->firstConfirmEvtId = DEM_INIT_ZERO;
        Info_ptr->recentlyConfirmEvtId = DEM_INIT_ZERO;
    }
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmShutDown
*
* Explanation: Shut down handle of Nvm Block
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_EventMemoryNvmShutDown(void)
{
    uint16 nvmBlkCnt;

    /* Always restore status block for all events */
    /* Trigger EventMemoryStatus block update */
    Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                   DEM_NVM_STATUS_BLOCK,
                                   DEM_NVM_REQ_WRITE,
                                   FALSE);

    for(nvmBlkCnt = DEM_INIT_ONE; nvmBlkCnt <= DEM_CFG_NVM_BLOCK_NUM; nvmBlkCnt++)
    {
        if((TRUE == DEM_GET_NVM_CLEAR_REQ(nvmBlkCnt)) ||
           (TRUE == DEM_GET_NVM_WRITE_REQ(nvmBlkCnt)))
        {
#if(DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON)
            (void)NvM_SetRamBlockStatus(Dem_CfgNvmBlockTable[nvmBlkCnt], TRUE);
#endif /* DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT == STD_ON */
            DEM_SET_NVM_CLEAR_REQ(nvmBlkCnt, FALSE);
            DEM_SET_NVM_WRITE_REQ(nvmBlkCnt, FALSE);
        }
    }
}

#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmPermBlockInit
*
* Explanation: Initialization of permanent Block
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryNvmPermBlockInit
(
    P2VAR(Dem_PermanentEventMemoryEntry_st, AUTOMATIC, DEM_APPL_DATA) Perm_ptr
)
{
    uint8 ratioCnt;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if(Perm_ptr != NULL_PTR)
    {
        Perm_ptr->drvCycleCnt = DEM_INIT_ZERO;
        Perm_ptr->warmUpCycleCnt = DEM_INIT_ZERO;
        Perm_ptr->freezeframeEvtId = DEM_INIT_ZERO;
        Perm_ptr->pfcCnt = DEM_INIT_ZERO;
        Perm_ptr->genDenominator = DEM_INIT_ZERO;
        for(ratioCnt = DEM_INIT_ZERO; ratioCnt < (DEM_CFG_OBD_RATIO_NUM + DEM_BYTE_ONE); ratioCnt++)
        {
            Perm_ptr->numerator[ratioCnt] = DEM_INIT_ZERO;
            Perm_ptr->denominator[ratioCnt] = DEM_INIT_ZERO;
            Perm_ptr->iuprRatio[ratioCnt] = DEM_INIT_ZERO;
        }
        Perm_ptr->ignitionCycleCnt = DEM_INIT_ZERO;
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
        Perm_ptr->wwhB1CntAge = DEM_INIT_ZERO;
        Perm_ptr->wwhB1Cnt = DEM_INIT_ZERO;
        Perm_ptr->wwhB1CntHighest = DEM_INIT_ZERO;
        Perm_ptr->wwhContiMiOffCnt = DEM_INIT_ZERO;
        Perm_ptr->wwhContiMiCntAge = DEM_INIT_ZERO;
        Perm_ptr->wwhContiMiCntHaltCycle = DEM_INIT_ZERO;
        Perm_ptr->wwhContiMiCnt = DEM_INIT_ZERO;
        Perm_ptr->wwhCumuContiMiCnt = DEM_INIT_ZERO;
#endif
        Perm_ptr->odoMilOn = DEM_INIT_ZERO;
        Perm_ptr->odoSinceDtcClear = DEM_INIT_ZERO;
        Perm_ptr->engineRuntimeWhileMilOn = DEM_INIT_ZERO;
        Perm_ptr->engineRuntimeSinceDtcClear = DEM_INIT_ZERO;
    }
}
#endif

/*
********************************************************************************
* Function Name: Dem_EventMemoryNvmPrepare
*
* Explanation: Preparation of Nvm block update by copying data into srcPtr
*
* param: uint16 nvmBlkIdx, NVM block index
*        uint8 *srcPtr, data buffer of updated data
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_EventMemoryNvmPrepare
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 NvmBlkIdx, 
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) SrcPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 entryIdx;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if(SrcPtr != NULL_PTR)
    {
        if(DEM_EVENT_STATUS_BLOCK == NvmBlkIdx)
        {
            /* Event status block */
            Dem_EventMemoryCopy((uint8*)&Dem_DummyEventMemoryStatus,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                (uint8*)&Dem_EventMemoryStatus,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                (uint16)sizeof(Dem_EventMemoryStatus_st));
            /* PolySpace +1 MISRA-C3:11.4 [Justified:Unset] "NSCA_Polyspace_Dem_11.4" */
            *SrcPtr = (uint32)&Dem_DummyEventMemoryStatus;  /* PRQA S 0306 */ /* NSCA_QAC_Dem_VarTypeConvert */
            ret = E_OK;
        }
        else if(DEM_PRIMARY_INFO_BLOCK == NvmBlkIdx)
        {
            /* Primary event memory info block */
            Dem_EventMemoryCopy((uint8*)&Dem_DummyEventMemoryInfo,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                (uint8*)&Dem_PrimaryEventMemoryInfo,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                (uint16)sizeof(Dem_EventMemoryInfo_st));
            /* PolySpace +1 MISRA-C3:11.4 [Justified:Unset] "NSCA_Polyspace_Dem_11.4" */
            *SrcPtr = (uint32)&Dem_DummyEventMemoryInfo;  /* PRQA S 0306 */ /* NSCA_QAC_Dem_VarTypeConvert */
            ret = E_OK;
        }
        else if((DEM_PRIMARY_ENTRY_BLOCK_START <= NvmBlkIdx) && 
                (DEM_PRIMARY_ENTRY_BLOCK_END >= NvmBlkIdx))
        {
            /* Primary event memory entry block */
            entryIdx = (uint8)(NvmBlkIdx - DEM_PRIMARY_ENTRY_BLOCK_START);
            Dem_EventMemoryCopy((uint8*)&Dem_DummyEventMemoryEntry,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                (uint8*)&Dem_PrimaryEventMemoryEntry[entryIdx],  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                (uint16)sizeof(Dem_EventMemoryEntry_st));
            /* PolySpace +1 MISRA-C3:11.4 [Justified:Unset] "NSCA_Polyspace_Dem_11.4" */
            *SrcPtr = (uint32)&Dem_DummyEventMemoryEntry;  /* PRQA S 0306 */ /* NSCA_QAC_Dem_VarTypeConvert */
            ret = E_OK;
        }
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_ONE)
        else if(DEM_USER0_INFO_BLOCK == NvmBlkIdx)
        {
            /* User0 event memory info block */
            Dem_EventMemoryCopy((uint8*)&Dem_DummyEventMemoryInfo,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                (uint8*)&Dem_User0EventMemoryInfo,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                (uint16)sizeof(Dem_EventMemoryInfo_st));
            /* PolySpace +1 MISRA-C3:11.4 [Justified:Unset] "NSCA_Polyspace_Dem_11.4" */
            *SrcPtr = (uint32)&Dem_DummyEventMemoryInfo;  /* PRQA S 0306 */ /* NSCA_QAC_Dem_VarTypeConvert */
            ret = E_OK;
        }
        else if((DEM_USER0_ENTRY_BLOCK_START <= NvmBlkIdx) &&
                (DEM_USER0_ENTRY_BLOCK_END >= NvmBlkIdx))
        {
            /* User0 event memory entry block */
            entryIdx = (uint8)(NvmBlkIdx - DEM_USER0_ENTRY_BLOCK_START);
            Dem_EventMemoryCopy((uint8*)&Dem_DummyEventMemoryEntry,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                (uint8*)&Dem_User0EventMemoryEntry[entryIdx],  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                (uint16)sizeof(Dem_EventMemoryEntry_st));
            /* PolySpace +1 MISRA-C3:11.4 [Justified:Unset] "NSCA_Polyspace_Dem_11.4" */
            *SrcPtr = (uint32)&Dem_DummyEventMemoryEntry;  /* PRQA S 0306 */ /* NSCA_QAC_Dem_VarTypeConvert */
            ret = E_OK;
        }
#endif
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_TWO)
        else if(DEM_USER1_INFO_BLOCK == NvmBlkIdx)
        {
            /* User1 event memory info block */
            Dem_EventMemoryCopy((uint8*)&Dem_DummyEventMemoryInfo,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                (uint8*)&Dem_User1EventMemoryInfo,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                (uint16)sizeof(Dem_EventMemoryInfo_st));
            /* PolySpace +1 MISRA-C3:11.4 [Justified:Unset] "NSCA_Polyspace_Dem_11.4" */
            *SrcPtr = (uint32)&Dem_DummyEventMemoryInfo;  /* PRQA S 0306 */ /* NSCA_QAC_Dem_VarTypeConvert */
            ret = E_OK;
        }
        else if((DEM_USER1_ENTRY_BLOCK_START <= NvmBlkIdx) &&
                (DEM_USER1_ENTRY_BLOCK_END >= NvmBlkIdx))
        {
            /* User1 event memory entry block */
            entryIdx = (uint8)(NvmBlkIdx - DEM_USER1_ENTRY_BLOCK_START);
            Dem_EventMemoryCopy((uint8*)&Dem_DummyEventMemoryEntry,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                (uint8*)&Dem_User1EventMemoryEntry[entryIdx],  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                (uint16)sizeof(Dem_EventMemoryEntry_st));
            /* PolySpace +1 MISRA-C3:11.4 [Justified:Unset] "NSCA_Polyspace_Dem_11.4" */
            *SrcPtr = (uint32)&Dem_DummyEventMemoryEntry;  /* PRQA S 0306 */ /* NSCA_QAC_Dem_VarTypeConvert */
            ret = E_OK;
        }
#endif
        else
        {
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
#if(DEM_CFG_EVENT_MEMORY_NUM == DEM_BYTE_ONE)
            if((DEM_PRIMARY_ENTRY_BLOCK_END + DEM_INIT_ONE) == NvmBlkIdx)
            {
                /* Permanent event memory block */
                Dem_EventMemoryCopy((uint8*)&Dem_DummyPermanentEventMemoryEntry,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                    (uint8*)&Dem_PermanentEventMemoryEntry,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                    (uint16)sizeof(Dem_PermanentEventMemoryEntry_st));
                *SrcPtr = (uint32)&Dem_DummyPermanentEventMemoryEntry;  /* PRQA S 0306 */ /* NSCA_QAC_Dem_VarTypeConvert */
                ret = E_OK;
            }
#elif(DEM_CFG_EVENT_MEMORY_NUM == DEM_BYTE_TWO)
            if((DEM_USER0_ENTRY_BLOCK_END + DEM_INIT_ONE) == NvmBlkIdx)
            {
                /* Permanent event memory block */
                Dem_EventMemoryCopy((uint8*)&Dem_DummyPermanentEventMemoryEntry,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                    (uint8*)&Dem_PermanentEventMemoryEntry,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                    (uint16)sizeof(Dem_PermanentEventMemoryEntry_st));
                *SrcPtr = (uint32)&Dem_DummyPermanentEventMemoryEntry;  /* PRQA S 0306 */ /* NSCA_QAC_Dem_VarTypeConvert */
                ret = E_OK;
            }
#elif(DEM_CFG_EVENT_MEMORY_NUM == DEM_BYTE_THREE)
            if((DEM_USER1_ENTRY_BLOCK_END + DEM_INIT_ONE) == NvmBlkIdx)
            {
                /* Permanent event memory block */
                Dem_EventMemoryCopy((uint8*)&Dem_DummyPermanentEventMemoryEntry,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                    (uint8*)&Dem_PermanentEventMemoryEntry,  /* PRQA S 0310 */ /* NSCA_QAC_Dem_VarTypeConvert */
                                    (uint16)sizeof(Dem_PermanentEventMemoryEntry_st));
                /* PolySpace +1 MISRA-C3:11.4 [Justified:Unset] "NSCA_Polyspace_Dem_11.4" */
                *SrcPtr = (uint32)&Dem_DummyPermanentEventMemoryEntry;  /* PRQA S 0306 */ /* NSCA_QAC_Dem_VarTypeConvert */
                ret = E_OK;
            }
#else
            {
                /* do nothing */
            }
#endif
#endif
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_EventMemoryCopy
*
* Explanation: Memory copy
*
* param: uint8 *dstAddr, destination address
*        uint8 *srcAddr, source address
*        uint16 len, data length
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_EventMemoryCopy
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DstAddr, 
    P2CONST(uint8, AUTOMATIC, DEM_APPL_DATA) SrcAddr, 
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 Len
)
{
    uint16 idx;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((NULL_PTR != DstAddr) && (NULL_PTR != SrcAddr))
    {
        for(idx = DEM_INIT_ZERO; idx < Len; idx++)
        {
            DstAddr[idx] = SrcAddr[idx];
        }
    }
}

#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
/*
********************************************************************************
* Function Name: Dem_ObdDrivingCycleStart
*
* Explanation: OBD driving cycle start handle
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdDrivingCycleStart(void)
{
    uint8 ratioIdx;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    /* driving cycle counter increament */
    if(ptr->drvCycleCnt < DEM_BYTE_MAX)
    {
        ptr->drvCycleCnt++;

        /* Trigger permanet block update */
        Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                       DEM_NVM_PERMANET_BLOCK,
                                       DEM_NVM_REQ_WRITE,
                                       FALSE);
    }

    /* Initialize the counter of warm-up cycle counter during the last driving cycles. */
    DEM_SET_OBD_WUC_STARTED_LAST_DRICYC(DEM_INIT_ZERO);
    
    /* Reset IUPR calculation request when OBD driving cycle start */
    DEM_SET_OBD_IUPR_CALC_GEN_DEN();
    for(ratioIdx = DEM_INIT_ONE; ratioIdx <= DEM_CFG_OBD_RATIO_NUM; ratioIdx++)
    {
        DEM_SET_OBD_IUPR_CALC_NUM(ratioIdx);
        DEM_SET_OBD_IUPR_CALC_DEN(ratioIdx);
    }

#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
    DEM_SET_WWH_B1EVENT_DETECT(FALSE);
#endif
}

/*
********************************************************************************
* Function Name: Dem_ObdWarmUpCycleStart
*
* Explanation: OBD warmup cycle start handle
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdWarmUpCycleStart(void)
{
    uint8 opcycIdx;
    uint8 wuCycFlagDuringlastDrvCyc = DEM_INIT_ZERO;
    uint8 wupCycCntSinceLastInit = DEM_INIT_ZERO;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    /* Warmup cycle counter increament */
    if(ptr->warmUpCycleCnt < DEM_BYTE_MAX)
    {
        ptr->warmUpCycleCnt++;
        /* Calculate the number of warm-up cycles that passed since the last Dem init. */
        wupCycCntSinceLastInit = DEM_GET_OBD_WARMUP_CYCLE_CNT_SINCELASTINIT();
        wupCycCntSinceLastInit++;
        DEM_SET_OBD_WARMUP_CYCLE_CNT_SINCELASTINIT(wupCycCntSinceLastInit);

        for(opcycIdx = DEM_INIT_ONE; opcycIdx <= DEM_CFG_OPCYC_NUM; opcycIdx++)
        {
            /* Check the status of the Driving Cycle.  */
            if((DEM_OPCYC_OBD_DCY == Dem_CfgOperationCycleTable[opcycIdx].acCycType) &&
                (DEM_CYCLE_STATE_START == DEM_GET_OPCYC_STATE(opcycIdx)))
            {
                /* Calculate the number of warm-up cycles during the last driving cycle. */
                wuCycFlagDuringlastDrvCyc++;
                DEM_SET_OBD_WUC_STARTED_LAST_DRICYC(wuCycFlagDuringlastDrvCyc);
            }
        }

        /* Trigger permanet block update */
        Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                       DEM_NVM_PERMANET_BLOCK,
                                       DEM_NVM_REQ_WRITE,
                                       FALSE);
    }
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
    DEM_SET_WWH_CONTIMI_DET(FALSE);
#endif
}

/*
********************************************************************************
* Function Name: Dem_ObdIgnitionCycleStart
*
* Explanation: OBD Iginition cycle start handle
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdIgnitionCycleStart(void)
{
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    /* Ignition cycle counter increament */
    if(ptr->ignitionCycleCnt >= DEM_WORD_MAX)
    {
        ptr->ignitionCycleCnt = DEM_INIT_ZERO;
    }
    else
    {
        ptr->ignitionCycleCnt++;
    }
    
    /* Trigger permanet block update */
    Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                   DEM_NVM_PERMANET_BLOCK,
                                   DEM_NVM_REQ_WRITE,
                                   FALSE);
}

/*
********************************************************************************
* Function Name: Dem_ObdGetGeneralData
*
* Explanation: Get OBD general data according configurations in OBD general
*
* param: uint8 data, element data index of specific data
*
* retval: return OBD general data in uint32 type
********************************************************************************
*/
FUNC(uint32, DEM_CODE) Dem_ObdGetGeneralData
(
    uint8 DataElementIdx
)
{
    uint32 retData = DEM_INIT_ZERO;
#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS != DEM_EXDATA_OPAQUE)
    uint8 idx;
#endif
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 dataLen;
    uint8 dataBuf[DEM_BYTE_FOUR];

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((DataElementIdx > DEM_INIT_ZERO) && (DataElementIdx <= DEM_CFG_DATA_ELEMENT_NUM))
    {
        dataLen = Dem_CfgDataElementTable[DataElementIdx].acDataSize;

        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if(dataLen <= DEM_BYTE_FOUR)
        {
            if(TRUE == Dem_CfgDataElementTable[DataElementIdx].acDataUsePort)
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                if(NULL_PTR != Dem_CfgDataElementTable[DataElementIdx].DataElementReadPortPtr)
                {
                    if(E_OK == Dem_CfgDataElementTable[DataElementIdx].DataElementReadPortPtr(dataBuf))
                    {
#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
                        for(idx = DEM_INIT_ZERO; idx < dataLen; idx++)
                        {
                            retData |= (uint32)dataBuf[idx] << (idx * DEM_BYTE_EIGHT);
                        }
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
                        for(idx = DEM_INIT_ZERO; idx < dataLen; idx++)
                        {
                            retData |= (uint32)dataBuf[dataLen - idx - DEM_BYTE_ONE] << (idx * DEM_BYTE_EIGHT);
                        }
#else
                        /* nothing */
#endif
                    }
                }
            }
            else
            {
                if(NULL_PTR != Dem_CfgDataElementTable[DataElementIdx].DataElementReadFncPtr)
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    if(E_OK == Dem_CfgDataElementTable[DataElementIdx].DataElementReadFncPtr(dataBuf))
                    {
#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
                        for(idx = DEM_INIT_ZERO; idx < dataLen; idx++)
                        {
                            retData |= (uint32)dataBuf[idx] << (idx * DEM_BYTE_EIGHT);
                        }
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
                        for(idx = DEM_INIT_ZERO; idx < dataLen; idx++)
                        {
                            retData |= (uint32)dataBuf[dataLen - idx - DEM_BYTE_ONE] << (idx * DEM_BYTE_EIGHT);
                        }
#else
                        /* nothing */
#endif
                    }
                }
            }
        }
    }

    return retData;
}

/*
********************************************************************************
* Function Name: Dem_ObdGetInfoTypeValue08
*
* Explanation: Get OBD data of Info-Type $08
*
* param: uint8 OpStatus, element data index of specific data
*        uint8* Iumprdata08, buffer to hold the data of Info-Type $08
*        uint8* Iumprdata08BufferSize, size of the data of Info-Type $08
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdGetInfoTypeValue08
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08BufferSize
)
{
    uint8 ratioIdx;
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx;
#endif
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
    if((*Iumprdata08BufferSize >= DEM_BYTE_FORTY) && (DEM_INIT_ZERO == OpStatus))
    {
        *Iumprdata08BufferSize = DEM_BYTE_FORTY;
        
        Iumprdata08[DEM_BYTE_ZERO] = (uint8)((ptr->genDenominator & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
        Iumprdata08[DEM_BYTE_ONE] = (uint8)(ptr->genDenominator & (uint16)DEM_WORD_LOW_BYTE);
        
        Iumprdata08[DEM_BYTE_TWO] = (uint8)((ptr->ignitionCycleCnt & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
        Iumprdata08[DEM_BYTE_THREE] = (uint8)(ptr->ignitionCycleCnt & (uint16)DEM_WORD_LOW_BYTE);
        
        for(ratioIdx = DEM_INIT_ONE; ratioIdx <= DEM_CFG_OBD_RATIO_NUM; ratioIdx++)
        {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
            evtIdx = Dem_ConfigObdRatioTable[ratioIdx].awEvtIdx;
            dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
            if((DEM_INIT_ZERO == evtIdx) || 
               (FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)))
#endif
            {
                switch(Dem_ConfigObdRatioTable[ratioIdx].acIuprGrp)
                {
                    case DEM_IUMPR_CAT1:
                    {
                        Iumprdata08[DEM_BYTE_FOUR] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_FIVE] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata08[DEM_BYTE_SIX] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_SEVEN] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    case DEM_IUMPR_CAT2:
                    {
                        Iumprdata08[DEM_BYTE_EIGHT] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_NINE] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata08[DEM_BYTE_TEN] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_ELEVEN] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" */
                    case DEM_IUMPR_OXS1:
                    {
                        Iumprdata08[DEM_BYTE_TWELVE] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_THIRTEEN] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata08[DEM_BYTE_FOURTEEN] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_FIFTEEN] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" */
                    case DEM_IUMPR_OXS2:
                    {
                        Iumprdata08[DEM_BYTE_SIXTEEN] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_SEVENTEEN] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata08[DEM_BYTE_EIGHTEEN] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_NINETEEN] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    case DEM_IUMPR_EGR:
                    {
                        Iumprdata08[DEM_BYTE_TWENTY] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_TWENTY_ONE] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata08[DEM_BYTE_TWENTY_TWO] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_TWENTY_THREE] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" */
                    case DEM_IUMPR_SAIR:
                    {
                        Iumprdata08[DEM_BYTE_TWENTY_FOUR] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_TWENTY_FIVE] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata08[DEM_BYTE_TWENTY_SIX] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_TWENTY_SEVEN] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" */
                    case DEM_IUMPR_EVAP:
                    {
                        Iumprdata08[DEM_BYTE_TWENTY_EIGHT] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_TWENTY_NINE] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata08[DEM_BYTE_THIRTY] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_THIRTY_ONE] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable"  Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" */
                    case DEM_IUMPR_SECOXS1:
                    {
                        Iumprdata08[DEM_BYTE_THIRTY_TWO] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_THIRTY_THREE] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata08[DEM_BYTE_THIRTY_FOUR] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_THIRTY_FIVE] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" */
                    case DEM_IUMPR_SECOXS2:
                    {
                        Iumprdata08[DEM_BYTE_THIRTY_SIX] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_THIRTY_SEVEN] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata08[DEM_BYTE_THIRTY_EIGHT] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata08[DEM_BYTE_THIRTY_NINE] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdGetInfoTypeValue0B
*
* Explanation: Get OBD data of Info-Type $0B
*
* param: uint8 OpStatus, element data index of specific data
*        uint8* Iumprdata0B, buffer to hold the data of Info-Type $0B
*        uint8* Iumprdata0BBufferSize, size of the data of Info-Type $0B
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
FUNC(void, DEM_CODE) Dem_ObdGetInfoTypeValue0B
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0B, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0BBufferSize
)
{
    uint8 ratioIdx;
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx;
#endif
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
    if((*Iumprdata0BBufferSize >= DEM_BYTE_THIRTY_SIX)  && (DEM_INIT_ZERO == OpStatus))
    {
        *Iumprdata0BBufferSize = DEM_BYTE_THIRTY_SIX;
            
        Iumprdata0B[DEM_BYTE_ZERO] = (uint8)((ptr->genDenominator & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
        Iumprdata0B[DEM_BYTE_ONE] = (uint8)(ptr->genDenominator & (uint16)DEM_WORD_LOW_BYTE);
        
        Iumprdata0B[DEM_BYTE_TWO] = (uint8)((ptr->ignitionCycleCnt & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
        Iumprdata0B[DEM_BYTE_THREE] = (uint8)(ptr->ignitionCycleCnt & (uint16)DEM_WORD_LOW_BYTE);
    
        for(ratioIdx = DEM_INIT_ONE; ratioIdx <= DEM_CFG_OBD_RATIO_NUM; ratioIdx++)
        {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
            evtIdx = Dem_ConfigObdRatioTable[ratioIdx].awEvtIdx;
            dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
            if((DEM_INIT_ZERO == evtIdx) ||
               (FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)))
#endif
            {
                switch(Dem_ConfigObdRatioTable[ratioIdx].acIuprGrp)
                {
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" */
                    case DEM_IUMPR_NMHCCAT:
                    {
                        Iumprdata0B[DEM_BYTE_FOUR] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_FIVE] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata0B[DEM_BYTE_SIX] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_SEVEN] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" */
                    case DEM_IUMPR_NOXCAT:
                    {
                        Iumprdata0B[DEM_BYTE_EIGHT] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_NINE] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata0B[DEM_BYTE_TEN] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_ELEVEN] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" */
                    case DEM_IUMPR_NOXADSORB:
                    {
                        Iumprdata0B[DEM_BYTE_TWELVE] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_THIRTEEN] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata0B[DEM_BYTE_FOURTEEN] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_FIFTEEN] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" */
                    case DEM_IUMPR_PMFILTER:
                    {
                        Iumprdata0B[DEM_BYTE_SIXTEEN] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_SEVENTEEN] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata0B[DEM_BYTE_EIGHTEEN] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_NINETEEN] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    case DEM_IUMPR_EGSENSOR:
                    {
                        Iumprdata0B[DEM_BYTE_TWENTY] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_TWENTY_ONE] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata0B[DEM_BYTE_TWENTY_TWO] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_TWENTY_THREE] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    case DEM_IUMPR_EGR:
                    {
                        Iumprdata0B[DEM_BYTE_TWENTY_FOUR] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_TWENTY_FIVE] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata0B[DEM_BYTE_TWENTY_SIX] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_TWENTY_SEVEN] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    case DEM_IUMPR_BOOSTPRS:
                    {
                        Iumprdata0B[DEM_BYTE_TWENTY_EIGHT] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_TWENTY_NINE] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata0B[DEM_BYTE_THIRTY] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_THIRTY_ONE] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" */
                    case DEM_IUMPR_FLSYS:
                    {
                        Iumprdata0B[DEM_BYTE_THIRTY_TWO] = (uint8)((ptr->numerator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_THIRTY_THREE] = (uint8)(ptr->numerator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        
                        Iumprdata0B[DEM_BYTE_THIRTY_FOUR] = (uint8)((ptr->denominator[ratioIdx] & (uint16)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                        Iumprdata0B[DEM_BYTE_THIRTY_FIVE] = (uint8)(ptr->denominator[ratioIdx] & (uint16)DEM_WORD_LOW_BYTE);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdGetSupportReadiness
*
* Explanation: Get supported Readiness grouup
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdGetSupportReadiness
(
    uint16 EventIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) SupportGroup
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;
    
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx < DEM_CFG_EVENT_NUM) &&
       (SupportGroup != NULL_PTR))
    {
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        switch(Dem_CfgObdDTCTable[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx].acObbEvtReadinessGrp)
        {
            case DEM_OBD_RDY_MISF:
            {
                SupportGroup[DEM_INIT_ZERO] |= DEM_BYTE_MASK_BIT0;
                break;
            }
            case DEM_OBD_RDY_FLSYS:
            {
                SupportGroup[DEM_INIT_ZERO] |= DEM_BYTE_MASK_BIT1;
                break;
            }
            case DEM_OBD_RDY_CMPRCMPT:
            {
                SupportGroup[DEM_INIT_ZERO] |= DEM_BYTE_MASK_BIT2;
                break;
            }
            case DEM_OBD_RDY_CAT:
            {
                SupportGroup[DEM_INIT_ONE] |= DEM_BYTE_MASK_BIT0;
                break;
            }
            case DEM_OBD_RDY_HTCAT:
            {
                SupportGroup[DEM_INIT_ONE] |= DEM_BYTE_MASK_BIT1;
                break;
            }
            case DEM_OBD_RDY_EVAP:
            {
                SupportGroup[DEM_INIT_ONE] |= DEM_BYTE_MASK_BIT2;
                break;
            }
            case DEM_OBD_RDY_SECAIR:
            {
                SupportGroup[DEM_INIT_ONE] |= DEM_BYTE_MASK_BIT3;
                break;
            }
            case DEM_OBD_RDY_AC:
            {
                SupportGroup[DEM_INIT_ONE] |= DEM_BYTE_MASK_BIT4;
                break;
            }
            case DEM_OBD_RDY_O2SENS:
            {
                SupportGroup[DEM_INIT_ONE] |= DEM_BYTE_MASK_BIT5;
                break;
            }
            case DEM_OBD_RDY_O2SENSHT:
            {
                SupportGroup[DEM_INIT_ONE] |= DEM_BYTE_MASK_BIT6;
                break;
            }
            case DEM_OBD_RDY_ERG:
            {
                SupportGroup[DEM_INIT_ONE] |= DEM_BYTE_MASK_BIT7;
                break;
            }
            default:
            {
                break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdGetDataOfPID01
*
* Explanation: Get the PID01 data
*
* param: uint8* PID01value, buffer to hold the data of PID01
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdGetDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01value
)
{
    uint8 obdDtcCnt = DEM_INIT_ZERO;
    uint8 supportGroup[DEM_BYTE_TWO] = {DEM_INIT_ZERO, DEM_INIT_ZERO};
    uint8 completeGroup[DEM_BYTE_TWO] = {DEM_INIT_ZERO, DEM_INIT_ZERO};
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx;

    for(evtIdx = DEM_INIT_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
    {
        dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        if((FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)) && 
           (Dem_CfgDTCTable[dtcIdx].acObdDtcIdx > DEM_INIT_ZERO))
#else
        if(Dem_CfgDTCTable[dtcIdx].acObdDtcIdx > DEM_INIT_ZERO)
#endif
        {
            if((obdDtcCnt < DEM_BYTE_HALF) && (TRUE == DEM_GET_UDS_STATUS_CDTC(evtIdx)))
            {
                obdDtcCnt++;
            }

            Dem_ObdGetSupportReadiness(evtIdx, supportGroup);

            if(TRUE == DEM_GET_UDS_STATUS_TNCSLC(evtIdx))
            {
                Dem_ObdGetSupportReadiness(evtIdx, completeGroup);
            }
        }
    }
    
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
    PID01value[DEM_BYTE_ZERO] = DEM_INIT_ZERO;
#else
#if(DEM_CFG_MILINDICATORREF > DEM_BYTE_ZERO)
    /* Byte A of PID01: Number of emission-related DTCs and MIL status */
    if(DEM_GET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF) != DEM_INDICATOR_OFF)
    {
        /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
        PID01value[DEM_BYTE_ZERO] = obdDtcCnt | DEM_BYTE_MASK_BIT7;
    }
    else
#endif
    {
        /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
        PID01value[DEM_BYTE_ZERO] = obdDtcCnt;
    }
#endif

    /* Byte B of PID01: Support and status of monitors */
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_COMPRESSION)
    {
        /* Set bit3 "Compression ignition monitoring supported" */
        supportGroup[DEM_INIT_ZERO] |= DEM_BYTE_MASK_BIT3;
    }
#endif
    PID01value[DEM_BYTE_ONE] = (uint8)((supportGroup[DEM_INIT_ZERO] & (uint8)DEM_BYTE_LOW) |
                               ((uint8)(completeGroup[DEM_INIT_ZERO] << DEM_BYTE_FOUR) & (uint8)DEM_BYTE_HIGH));

    /* Byte C and D: Support and status of monitors */
    PID01value[DEM_BYTE_TWO] = supportGroup[DEM_INIT_ONE];
    PID01value[DEM_BYTE_THREE] = completeGroup[DEM_INIT_ONE];
}

/*
********************************************************************************
* Function Name: Dem_ObdGetDataOfPID41
*
* Explanation: Get the PID41 data
*
* param: uint8* PID41value, buffer to hold the data of PID41
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdGetDataOfPID41
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41value
)
{
    uint8 obdDtcCnt = DEM_INIT_ZERO;
    uint8 supportGroup[DEM_BYTE_TWO] = {DEM_INIT_ZERO, DEM_INIT_ZERO};
    uint8 completeGroup[DEM_BYTE_TWO] = {DEM_INIT_ZERO, DEM_INIT_ZERO};
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx;

    for(evtIdx = DEM_INIT_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
    {
        dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        if((FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)) && 
           (FALSE == DEM_GET_OBD_EVENT_DISABLE_PID41(evtIdx)) &&
           (Dem_CfgDTCTable[dtcIdx].acObdDtcIdx > DEM_INIT_ZERO))
#else
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
        if((FALSE == DEM_GET_OBD_EVENT_DISABLE_PID41(evtIdx)) && 
           (TRUE == DEM_GET_AVAIL(evtIdx)) &&
           (Dem_CfgDTCTable[dtcIdx].acObdDtcIdx > DEM_INIT_ZERO))
#else
        if((FALSE == DEM_GET_OBD_EVENT_DISABLE_PID41(evtIdx)) &&
           (Dem_CfgDTCTable[dtcIdx].acObdDtcIdx > DEM_INIT_ZERO))
#endif
#endif
        {
            if((obdDtcCnt < DEM_BYTE_HALF) && (TRUE == DEM_GET_UDS_STATUS_CDTC(evtIdx)))
            {
                obdDtcCnt++;
            }

            Dem_ObdGetSupportReadiness(evtIdx, supportGroup);

            if(TRUE == DEM_GET_UDS_STATUS_TNCTOC(evtIdx))
            {
                Dem_ObdGetSupportReadiness(evtIdx, completeGroup);
            }
        }
    }

#if(DEM_CFG_MILINDICATORREF > DEM_BYTE_ZERO)
    /* Byte A of PID01: Number of emission-related DTCs and MIL status */
    if(DEM_GET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF) != DEM_INDICATOR_OFF)
    {
        /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
        PID41value[DEM_BYTE_ZERO] = obdDtcCnt | DEM_BYTE_MASK_BIT7;
    }
    else
#endif
    {
        /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
        PID41value[DEM_BYTE_ZERO] = obdDtcCnt;
    }

    /* Byte B of PID01: Support and status of monitors */
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_COMPRESSION)
    {
        /* Set bit3 "Compression ignition monitoring supported" */
        supportGroup[DEM_INIT_ZERO] |= DEM_BYTE_MASK_BIT3;
    }
#endif
    PID41value[DEM_BYTE_ONE] = (uint8)((supportGroup[DEM_INIT_ZERO] & DEM_BYTE_LOW) |
                               ((uint8)(completeGroup[DEM_INIT_ZERO] << DEM_BYTE_FOUR) & DEM_BYTE_HIGH));

    /* Byte C and D: Support and status of monitors */
    PID41value[DEM_BYTE_TWO] = supportGroup[DEM_INIT_ONE];
    PID41value[DEM_BYTE_THREE] = completeGroup[DEM_INIT_ONE];
}

/*
********************************************************************************
* Function Name: Dem_ObdGetFFRecordPID
*
* Explanation: Get legislative Freeze Frame by PID
*
* param: uint8 PID, PID value
*        uint8 DataElementIndexOfPID, data element index(zero based)
*        uint8* DestBuffer, buffer to hold the freeze frame data
*        uint16* BufSize, size of the freeze frame data
*
* retval: Std_ReturnType
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ObdGetFFRecordPID
(
    uint8 PID,
    uint8 DataElementIndexOfPID,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx;
#endif
    uint8 pidCnt, pidEleCnt, pidEleIdx, byteIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 offset = DEM_INIT_ZERO;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    if((ptr->freezeframeEvtId > DEM_INIT_ZERO) &&
       (DestBuffer != NULL_PTR) && (BufSize != NULL_PTR))
    {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        evtIdx = Dem_CfgEventIdTableIndex[ptr->freezeframeEvtId];
        dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
        if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
#endif
        {
            for(pidCnt = DEM_INIT_ONE; pidCnt <= DEM_CFG_OBD_PID_DATA_NUM; pidCnt++)
            {
                if(PID == Dem_CfgObdPidDataTable[pidCnt].pidId)
                {
                    for(pidEleCnt = DEM_INIT_ZERO; pidEleCnt < DEM_CFG_PID_MAX_REF_DATA_ELEMENT_NUM; pidEleCnt++)
                    {
                        pidEleIdx = Dem_CfgObdPidDataTable[pidCnt].pidDataElementIdx[pidEleCnt];
                        if(DataElementIndexOfPID == pidEleCnt)
                        {
                            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            if(*BufSize >= Dem_CfgDataElementTable[pidEleIdx].acDataSize)
                            {
                                *BufSize = Dem_CfgDataElementTable[pidEleIdx].acDataSize;
                                for(byteIdx = DEM_INIT_ZERO; byteIdx < *BufSize; byteIdx++)
                                {
                                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                                    DestBuffer[byteIdx] = ptr->freezeframedatBuf[offset + byteIdx];
                                }
                                ret = E_OK;
                            }
                            break;
                        }
                        else
                        {
                            if(pidEleIdx != DEM_INIT_ZERO)
                            {
                                offset += Dem_CfgDataElementTable[pidEleIdx].acDataSize;
                            }
                        }
                    }
                    break;
                }
                else
                {
                    for(pidEleCnt = DEM_INIT_ZERO; pidEleCnt < DEM_CFG_PID_MAX_REF_DATA_ELEMENT_NUM; pidEleCnt++)
                    {
                        pidEleIdx = Dem_CfgObdPidDataTable[pidCnt].pidDataElementIdx[pidEleCnt];
                        if(pidEleIdx != DEM_INIT_ZERO)
                        {
                            offset += Dem_CfgDataElementTable[pidEleIdx].acDataSize;
                        }
                    }
                }
            }
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdGetFFRecordData
*
* Explanation: Get OBD Freeze frame record data by DTC
*
* param: uint32 DTC, DTC value
*        uint8 evtMemIdx, event memory index
*        uint8 RecordNumber, freeze frame data record number
*        uint8 *DestBuffer, buffer to hold the freeze frame data
*        uint16 *BufSize, to the freeze frame data length
*
* retval: Dem_ReturnGetFreezeFrameDataByDTCType 
********************************************************************************
*/
FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE) Dem_ObdGetFFRecordData
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC,
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint8 RecordNumber,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Dem_ReturnGetFreezeFrameDataByDTCType ret = DEM_GET_FFDATABYDTC_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx, byteIdx, bufIdx;
    uint16 bufOffset = DEM_INIT_ZERO;
    uint8 pidCnt, pidEleCnt, pidEleIdx;
    /* Polyspace +1 DEFECT:PARTIALLY_ACCESSED_ARRAY [JUstified:Unset] "NSCA_Polyspace_Dem_PartiallyAccessedArray" */
    uint8 pidDataLen[DEM_CFG_OBD_PID_DATA_NUM + DEM_INIT_ONE];
    uint16 pidDataTotalLen = DEM_INIT_ZERO;
    Dem_PermanentEventMemoryEntry_st *ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((DestBuffer != NULL_PTR) && (BufSize != NULL_PTR))
    {
        if(DEM_INIT_ZERO == EventMemIdx)
        {
            ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
            if(ptr->freezeframeEvtId > DEM_INIT_ZERO)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                dtcIdx = Dem_CfgEvtDtcIdx[Dem_CfgEventIdTableIndex[ptr->freezeframeEvtId]];
                if(DEM_DTCVALUE_CAL(dtcIdx) == DTC)
                {
                    for(pidCnt = DEM_INIT_ONE; pidCnt <= DEM_CFG_OBD_PID_DATA_NUM; pidCnt++)
                    {
                        pidDataLen[pidCnt - DEM_BYTE_ONE] = DEM_INIT_ZERO;
                        for(pidEleCnt = DEM_INIT_ZERO; pidEleCnt < DEM_CFG_PID_MAX_REF_DATA_ELEMENT_NUM; pidEleCnt++)
                        {
                            pidEleIdx = Dem_CfgObdPidDataTable[pidCnt].pidDataElementIdx[pidEleCnt];
                            if(pidEleIdx > DEM_INIT_ZERO)
                            {
                                pidDataLen[pidCnt - DEM_BYTE_ONE] += Dem_CfgDataElementTable[pidEleIdx].acDataSize;
                            }
                            else
                            {
                                break;
                            }
                        }
                        pidDataTotalLen += pidDataLen[pidCnt - DEM_BYTE_ONE];
                    }

                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                    if(*BufSize >= (pidDataTotalLen + DEM_BYTE_TWO + DEM_CFG_OBD_PID_DATA_NUM))
                    {
                        *BufSize = pidDataTotalLen + DEM_BYTE_TWO + DEM_CFG_OBD_PID_DATA_NUM;
                        
                        /* Copy data */
                        DestBuffer[DEM_BYTE_ZERO] = RecordNumber;
                        DestBuffer[DEM_BYTE_ONE] = DEM_CFG_OBD_PID_DATA_NUM;
                        bufIdx = DEM_BYTE_TWO;
                        
                        for(pidCnt = DEM_INIT_ONE; pidCnt <= DEM_CFG_OBD_PID_DATA_NUM; pidCnt++)
                        {
                            DestBuffer[bufIdx] = Dem_CfgObdPidDataTable[pidCnt].pidId;
                            bufIdx++;
                            for(byteIdx = DEM_INIT_ZERO; byteIdx < pidDataLen[pidCnt - DEM_BYTE_ONE]; byteIdx++)
                            {
                                DestBuffer[bufIdx + byteIdx] = ptr->freezeframedatBuf[bufOffset];
                                bufOffset++;
                            }
                            bufIdx += pidDataLen[pidCnt - DEM_BYTE_ONE];
                        }
                    }
                    else
                    {
                        ret = DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE;
                    }
                }
                else
                {
                    ret = DEM_GET_FFDATABYDTC_WRONG_DTC;
                }
            }
            else
            {
                /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                *BufSize = DEM_INIT_ZERO;
            }
        }
        else
        {
            ret = DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdGetFFRecordSize
*
* Explanation: Get OBD Freeze frame record size by DTC
*
* param: uint32 DTC, DTC value
*        uint8 evtMemIdx, event memory index
*        uint8 *DestBuffer, buffer to hold the freeze frame data
*        uint16 *BufSize, to the freeze frame data length
*
* retval: Dem_ReturnGetFreezeFrameDataByDTCType 
********************************************************************************
*/
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_ObdGetFFRecordSize
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC,
    uint8 EventMemIdx,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
)
{
    Dem_ReturnGetSizeOfDataByDTCType ret = DEM_GETSIZEBYDTC_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;
    uint8 pidCnt, pidEleCnt, pidEleIdx;
    /* Polyspace +1 DEFECT:PARTIALLY_ACCESSED_ARRAY [JUstified:Unset] "NSCA_Polyspace_Dem_PartiallyAccessedArray" */
    uint8 pidDataLen[DEM_CFG_OBD_PID_DATA_NUM + DEM_INIT_ONE];
    uint16 pidDataTotalLen = DEM_INIT_ZERO;
    Dem_PermanentEventMemoryEntry_st *ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if(SizeOfFreezeFrame != NULL_PTR)
    {
        if(DEM_INIT_ZERO == EventMemIdx)
        {
            ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
            if(ptr->freezeframeEvtId > DEM_INIT_ZERO)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                dtcIdx = Dem_CfgEvtDtcIdx[Dem_CfgEventIdTableIndex[ptr->freezeframeEvtId]];
                if(DEM_DTCVALUE_CAL(dtcIdx) == DTC)
                {
                    for(pidCnt = DEM_INIT_ONE; pidCnt <= DEM_CFG_OBD_PID_DATA_NUM; pidCnt++)
                    {
                        pidDataLen[pidCnt - DEM_BYTE_ONE] = DEM_INIT_ZERO;
                        for(pidEleCnt = DEM_INIT_ZERO; pidEleCnt < DEM_CFG_PID_MAX_REF_DATA_ELEMENT_NUM; pidEleCnt++)
                        {
                            pidEleIdx = Dem_CfgObdPidDataTable[pidCnt].pidDataElementIdx[pidEleCnt];
                            if(pidEleIdx > DEM_INIT_ZERO)
                            {
                                pidDataLen[pidCnt - DEM_BYTE_ONE] += Dem_CfgDataElementTable[pidEleIdx].acDataSize;
                            }
                            else
                            {
                                break;
                            }
                        }
                        pidDataTotalLen += pidDataLen[pidCnt - DEM_BYTE_ONE];
                    }

                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                    *SizeOfFreezeFrame = pidDataTotalLen + DEM_BYTE_TWO + DEM_CFG_OBD_PID_DATA_NUM;
                }
                else
                {
                    ret = DEM_GETSIZEBYDTC_WRONG_DTC;
                }
            }
            else
            {
                ret = DEM_GETSIZEBYDTC_WRONG_DTC;
            }
        }
        else
        {
            ret = DEM_GETSIZEBYDTC_WRONG_DTCORIGIN;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdGetFFRecordDTC
*
* Explanation: Get DTC which trigger the legislative Freeze Frame
*
* param: uint8 FrameNumber, freeze frame record, only 0x00 is possible
*        uint32* DTC, buffer to hold the DTC value
*        Dem_DTCFormatType DTCFormat, return DTC format
*
* retval: Std_ReturnType
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ObdGetFFRecordDTC
(
    uint8 FrameNumber,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    Dem_DTCFormatType DTCFormat
)
{
    Std_ReturnType ret = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    if(DEM_INIT_ZERO == FrameNumber)
    {
        if(DEM_DTC_FORMAT_OBD == DTCFormat)
        {
            if(DEM_INIT_ZERO != ptr->freezeframeEvtId)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                evtIdx = Dem_CfgEventIdTableIndex[ptr->freezeframeEvtId];
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
                {
                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                    *DTC = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
                    ret = E_OK;
                }
#else
                *DTC = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
                ret = E_OK;
#endif
            }
        }
        else if(DEM_DTC_FORMAT_UDS == DTCFormat)
        {
            if(DEM_INIT_ZERO != ptr->freezeframeEvtId)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                evtIdx = Dem_CfgEventIdTableIndex[ptr->freezeframeEvtId];
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if(FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx))
                {
                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                    *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                    ret = E_OK;
                }
#else
                *DTC = DEM_DTCVALUE_CAL(dtcIdx);
                ret = E_OK;
#endif
            }
        }
        else
        {
            /* Nothing here */
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdGetDtrData
*
* Explanation: Get DTR data of an OBD MID
*
* param: uint8 Obdmid, requested OBDmid
*        uint8 TIDindex, index of TID
*        uint8* TIDvalue, buffer to hold the TID value
*        uint8* UaSID, buffer to hold the UaSID value
*        uint16* Testvalue, buffer to hold the test value
*        uint16* Lowlimvalue, buffer to hold the low limit value
*        uint16* Upplimvalue, buffer to hold the upper limit value
*
* retval: Std_ReturnType
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ObdGetDtrData
(
    uint8 Obdmid,
    uint8 TIDindex,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) TIDvalue,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) UaSID,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Testvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Lowlimvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Upplimvalue
)
{
    Std_ReturnType ret = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtrIdx;
    uint16 midCnt = DEM_INIT_ZERO;
#if((DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY) || (DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION))
    uint16 evtIdx;
#endif

    for(dtrIdx = DEM_INIT_ONE; dtrIdx <= DEM_CFG_DTR_NUM; dtrIdx++)
    {
        if(Obdmid == Dem_ConfigDtrTable[dtrIdx].dtrMid)
        {
            if(midCnt == TIDindex)
            {
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
                evtIdx = Dem_ConfigDtrTable[dtrIdx].dtrEventRefIdx;
                if((evtIdx > DEM_INIT_ZERO) && (TRUE == DEM_GET_AVAIL(evtIdx)))
#endif
                {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    evtIdx = Dem_ConfigDtrTable[dtrIdx].dtrEventRefIdx;
                    if(FALSE == DEM_GET_DTCSUPPRESSION(Dem_CfgEvtDtcIdx[evtIdx]))
#endif
                    {
                        *TIDvalue = Dem_ConfigDtrTable[dtrIdx].dtrTid;
                        *UaSID = Dem_ConfigDtrTable[dtrIdx].dtrUasid;
                        *Testvalue = DEM_GET_OBD_DTR_RESULT(dtrIdx);
                        *Lowlimvalue = DEM_GET_OBD_DTR_LOWERLIMIT(dtrIdx);
                        *Upplimvalue = DEM_GET_OBD_DTR_UPPERLIMIT(dtrIdx);
                        ret = E_OK;
                    }
                }
            }
            midCnt++;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdGetPfcNum
*
* Explanation: Get the number of PFC
*
* param: None
*
* retval: uint8, return the number of PFC
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, DEM_CODE) Dem_ObdGetPfcNum(void)
{
    uint8 ret;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    ret = ptr->pfcCnt;

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdGetPfcVal
*
* Explanation: Get the PFC value
*
* param: uint8 pfcIdx, PFC index in permanent event memory
*
* retval: uint32, return the PFC value
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint32, DEM_CODE) Dem_ObdGetPfcVal
(
    uint8 pfcIdx
)
{
    uint32 ret;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
    ret = ptr->pfcVal[pfcIdx];

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdGetPfcEvtIdx
*
* Explanation: Get the PFC event index.
*
* param: uint8 pfcIdx, PFC index in permanent event memory.
*
* retval: uint32, Return the PFC event index in primary event memory.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint16, DEM_CODE) Dem_ObdGetPfcEvtIdx
(
    uint8 pfcIdx
)
{
    uint16 evtId;
    uint16 evtIdx;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
    evtId = ptr->pfcEvtId[pfcIdx];

    /* Check all events to get the matched event index. */
    for(evtIdx = DEM_INIT_ZERO; evtIdx < DEM_CFG_EVENT_NUM; evtIdx++)
    {
        if(evtId == Dem_CfgEventTable[evtIdx].awEvtId)
        {
            break;
        }
    }
    /* No found. */
    if(evtIdx >= DEM_CFG_EVENT_NUM)
    {
        evtIdx = DEM_VALUE_ZERO;
    }
    return evtIdx;
}

/*
********************************************************************************
* Function Name: Dem_ObdGetPfcStatus
*
* Explanation: Get the DTC status of requested PFC
*
* param: uint8 pfcIdx, PFC index in permanent event memory
*
* retval: uint8
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, DEM_CODE) Dem_ObdGetPfcStatus
(
    uint8 pfcIdx
)
{
    uint8 evtSt = DEM_INIT_ZERO;
    uint16 evtIdx;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
    evtIdx = Dem_CfgEventIdTableIndex[ptr->pfcEvtId[pfcIdx]];
#if(DEM_CFG_EVENTCOMBINATIONSUPPORT == DEM_EVCOMB_DISABLED)
    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
    evtSt = DEM_GET_UDS_STATUS(evtIdx);
#else
    (void)Dem_EventGetCombStatusByte(evtIdx, &evtSt);   
#endif

    return evtSt;
}

/*
********************************************************************************
* Function Name: Dem_ObdSetDtrData
*
* Explanation: Set DTR data
*
* param: uint16 DTRId, DTR id
*        sint32 TestResult, test result
*        sint32 LowerLimit, lower limit
*        sint32 UpperLimit, upper limit
*        Dem_DTRControlType Ctrlval, control type value
*
* retval: Std_ReturnType
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ObdSetDtrData
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DTRIdx,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    sint32 TestResult,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    sint32 LowerLimit,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    sint32 UpperLimit,
/* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    Dem_DTRControlType Ctrlval
)
{
    Std_ReturnType ret = E_NOT_OK;

    switch(Ctrlval)
    {
        case DEM_DTR_CTL_NORMAL:
        {
            ret = Dem_ObdCalcDtrDataNormal(DTRIdx, TestResult, LowerLimit, UpperLimit);
            break;
        }
        case DEM_DTR_CTL_NO_MAX:
        {
            ret = Dem_ObdCalcDtrDataNoMax(DTRIdx, TestResult, LowerLimit, UpperLimit);
            break;
        }
        case DEM_DTR_CTL_NO_MIN:
        {
            ret = Dem_ObdCalcDtrDataNoMin(DTRIdx, TestResult, LowerLimit, UpperLimit);
            break;
        }
        case DEM_DTR_CTL_RESET:
        {
            ret = Dem_ObdCalcDtrDataReset(DTRIdx);
            break;
        }
        case DEM_DTR_CTL_INVISIBLE:
        {
            ret = E_OK;
            break;
        }
        default:
        {
            break;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdSetIUMPRDenPhsyCondition
*
* Explanation: Set asymmetric condition
*
* param: ConditionId, denominator Condition Id
*        ConditionStatus, denominator Condition Status
*
* retval: Std_ReturnType
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ObdSetIUMPRDenPhsyCondition
(
    Dem_RatioIdType RatioID, 
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    Dem_IumprDenomCondStatusType ConditionStatus
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 ratioIdx;
    uint16 evtIdx;

    for(ratioIdx = DEM_INIT_ONE; ratioIdx <= DEM_CFG_OBD_RATIO_NUM; ratioIdx++)
    {
        if(RatioID == Dem_ConfigObdRatioTable[ratioIdx].awRatioId)
        {
            evtIdx = Dem_ConfigObdRatioTable[ratioIdx].awEvtIdx;
            if(evtIdx > DEM_INIT_ZERO)
            {
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
                if(TRUE == DEM_GET_AVAIL(evtIdx))
#endif
                {
                    DEM_SET_OBD_IUPR_DEN_PHSY_COND(ratioIdx, ConditionStatus);
                    ret = E_OK;
                }
            }
            else
            {
                DEM_SET_OBD_IUPR_DEN_PHSY_COND(ratioIdx, ConditionStatus);
                ret = E_OK;
            }
            break;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdCheckDenCondition
*
* Explanation: check denominator condition status
*
* param: uint8 RatioIdx, ratio index
*
* retval: uint8
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, DEM_CODE) Dem_ObdCheckDenCondition
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 RatioIdx
)
{
    uint8 ret = DEM_IUMPR_DEN_STATUS_NOT_REACHED;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((RatioIdx > DEM_INIT_ZERO) && (RatioIdx <= DEM_CFG_OBD_RATIO_NUM))
    {
        if(DEM_IUMPR_DEN_PHYS_API == Dem_ConfigObdRatioTable[RatioIdx].acIuprDenGrp)
        {
            ret = DEM_GET_OBD_IUPR_DEN_PHSY_COND(RatioIdx);
        }
        else if(DEM_IUMPR_DEN_NONE == Dem_ConfigObdRatioTable[RatioIdx].acIuprDenGrp)
        {
            ret = DEM_IUMPR_DEN_STATUS_REACHED;
        }
        else
        {
            ret = DEM_GET_OBD_IUPR_DEN_COND(Dem_ConfigObdRatioTable[RatioIdx].acIuprDenGrp);
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdCheckPtoStatus
*
* Explanation: check PTO status
*
* param: uint8 ratioIdx, ratio index
*
* retval: boolean
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(boolean, DEM_CODE) Dem_ObdCheckPtoStatus
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 RatioIdx
)
{
    uint8 ret = FALSE;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx, obdDtcIdx;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((RatioIdx > DEM_INIT_ZERO) && (RatioIdx <= DEM_CFG_OBD_RATIO_NUM))
    {
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if(Dem_ConfigObdRatioTable[RatioIdx].awEvtIdx > DEM_INIT_ZERO)
        {
            evtIdx = Dem_ConfigObdRatioTable[RatioIdx].awEvtIdx;
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:USELESS_IF [JUstified:Unset] "NSCA_Polyspace_Common_UselessIf" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
            if(Dem_CfgEvtDtcIdx[evtIdx] > DEM_INIT_ZERO)
            {
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:USELESS_IF [JUstified:Unset] "NSCA_Polyspace_Common_UselessIf" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                if(Dem_CfgDTCTable[dtcIdx].acObdDtcIdx > DEM_INIT_ZERO)
                {
                    obdDtcIdx = Dem_CfgDTCTable[dtcIdx].acObdDtcIdx;
                    /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                    if(TRUE == Dem_CfgObdDTCTable[obdDtcIdx].acConsidePto)
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    {
                        ret = DEM_GET_OBD_IUPR_PTO_STATUS();
                    }
                }
            }
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdCheckEventDisplace
*
* Explanation: Check if the obd related event is ok to be displaced
*
* param: EventId: Identification of an event by assigned Event ID.
*
* retval: E_NOT_OK, can not be displaced;E_OK, can be displaced
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_ObdCheckEventDisplace
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    Dem_EventIdType EventId
)
{
    Std_ReturnType ret = E_OK;
    uint16 evtIdx;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    if((EventId > DEM_INIT_ZERO) && (EventId <= DEM_CFG_EVENT_ID_MAX) &&
       (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO))
    {
        evtIdx = Dem_CfgEventIdTableIndex[EventId];
        if((DEM_INIT_ZERO != Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acObdDtcIdx) &&
           ((TRUE == DEM_GET_UDS_STATUS_WIR(evtIdx)) || 
            (TRUE == DEM_GET_UDS_STATUS_PDTC(evtIdx)) ||
            (EventId == ptr->freezeframeEvtId)))
        {
            ret = E_NOT_OK;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcIUPRNumerator
*
* Explanation: IUPR Numerator calculation
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdCalcIUPRNumerator(void)
{
    boolean numCondition = FALSE;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 ratioIdx;
    uint16 evtIdx;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    
    for(ratioIdx = DEM_INIT_ONE; ratioIdx <= DEM_CFG_OBD_RATIO_NUM; ratioIdx++)
    {
        evtIdx = Dem_ConfigObdRatioTable[ratioIdx].awEvtIdx;

        if(evtIdx > DEM_INIT_ZERO)
        {
            /* Numerator increament */
#if(DEM_CFG_PTOSUPPORT == STD_ON)
            if((FALSE == Dem_ObdCheckPtoStatus(ratioIdx)) && 
               (FALSE == DEM_GET_UDS_STATUS_TNCTOC(evtIdx)) &&
               (FALSE == DEM_GET_UDS_STATUS_PDTC(evtIdx)) &&
               (TRUE == DEM_GET_OBD_IUPR_CALC_NUM(ratioIdx)))
#else
            if((TRUE == DEM_GET_OBD_IUPR_CALC_NUM(ratioIdx)) && 
               (FALSE == DEM_GET_UDS_STATUS_TNCTOC(evtIdx)) &&
               (FALSE == DEM_GET_UDS_STATUS_PDTC(evtIdx)))
#endif
            {
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
                if(TRUE == DEM_GET_AVAIL(evtIdx))
#endif
                {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    if(FALSE == DEM_GET_DTCSUPPRESSION(Dem_CfgEvtDtcIdx[evtIdx]))
#endif
                    {
                        if(DEM_RATIO_OBSERVER == Dem_ConfigObdRatioTable[ratioIdx].acRatioKind)
                        {
                            numCondition = TRUE;
                        }
                        /* Polyspace +1 DEFECT:USELESS_IF [JUstified:Unset] "NSCA_Polyspace_Common_UselessIf" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                        else if(DEM_RATIO_API == Dem_ConfigObdRatioTable[ratioIdx].acRatioKind)
                        {
                            if(TRUE == DEM_GET_OBD_IUPR_NUM_COND_ASYM(ratioIdx))
                            {
                                numCondition = TRUE;
                            }
                        }
                        else
                        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                        {
                            /* Do nothing */
                        }
                        
                    }
                }
            }

        }
        else
        {
            /* Numerator increament */
            if((TRUE == DEM_GET_OBD_IUPR_CALC_NUM(ratioIdx)) && 
               (TRUE == DEM_GET_OBD_IUPR_NUM_COND_ASYM(ratioIdx)))
            {
                numCondition = TRUE;
            }
        }

        if(TRUE == numCondition)
        {
            if(ptr->numerator[ratioIdx] >= DEM_WORD_MAX)
            {
                ptr->numerator[ratioIdx] = ptr->numerator[ratioIdx] / DEM_BYTE_TWO;
            }
            else
            {
                ptr->numerator[ratioIdx]++;
            }
            DEM_RESET_OBD_IUPR_CALC_NUM(ratioIdx);
    
            /* Trigger permanet block update */
            Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                           DEM_NVM_PERMANET_BLOCK,
                                           DEM_NVM_REQ_WRITE,
                                           FALSE);
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcIUPRDenominator
*
* Explanation: IUPR Denominator calculation
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdCalcIUPRDenominator(void)
{
    boolean denCondition = FALSE;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 ratioIdx;
    uint16 evtIdx;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    
    for(ratioIdx = DEM_INIT_ONE; ratioIdx <= DEM_CFG_OBD_RATIO_NUM; ratioIdx++)
    {
        evtIdx = Dem_ConfigObdRatioTable[ratioIdx].awEvtIdx;

        if(evtIdx > DEM_INIT_ZERO)
        {
            /* Denominator increament */
            if((DEM_IUMPR_DEN_STATUS_REACHED == Dem_ObdCheckDenCondition(ratioIdx)) && 
               (DEM_IUMPR_DEN_STATUS_REACHED == DEM_GET_OBD_IUPR_DEN_COND(DEM_IUMPR_DEN_GENERAL)) &&
               (TRUE == DEM_GET_OBD_IUPR_CALC_DEN(ratioIdx)) &&
               (FALSE == DEM_GET_UDS_STATUS_PDTC(evtIdx)))
            {
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
                if(TRUE == DEM_GET_AVAIL(evtIdx))
#endif
                {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    if(FALSE == DEM_GET_DTCSUPPRESSION(Dem_CfgEvtDtcIdx[evtIdx]))
#endif
                    {
                        denCondition = TRUE;
                    }
                }
            }

        }
        else
        {
            /* Denominator increament */
            if((DEM_IUMPR_DEN_STATUS_REACHED == Dem_ObdCheckDenCondition(ratioIdx)) && 
               (DEM_IUMPR_DEN_STATUS_REACHED == DEM_GET_OBD_IUPR_DEN_COND(DEM_IUMPR_DEN_GENERAL)) &&
               (TRUE == DEM_GET_OBD_IUPR_CALC_DEN(ratioIdx)))
            {
                denCondition = TRUE;
            }
        }

        if(TRUE == denCondition)
        {
            if(ptr->denominator[ratioIdx] >= DEM_WORD_MAX)
            {
                ptr->denominator[ratioIdx] = ptr->denominator[ratioIdx] / DEM_BYTE_TWO;
            }
            else
            {
                ptr->denominator[ratioIdx]++;
            }
            DEM_RESET_OBD_IUPR_CALC_DEN(ratioIdx);
    
            /* Trigger permanet block update */
            Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                           DEM_NVM_PERMANET_BLOCK,
                                           DEM_NVM_REQ_WRITE,
                                           FALSE);
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcIUPRGenDenominator
*
* Explanation: IUPR Genenal Denominator calculation
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdCalcIUPRGenDenominator(void)
{
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    
    /* Genenal Denominator increament */
    if((TRUE == DEM_GET_OBD_IUPR_CALC_GEN_DEN()) && 
       (DEM_IUMPR_DEN_STATUS_REACHED == DEM_GET_OBD_IUPR_DEN_COND(DEM_IUMPR_DEN_GENERAL)))
    {
        if(ptr->genDenominator >= DEM_WORD_MAX)
        {
            ptr->genDenominator = DEM_INIT_ZERO;
        }
        else
        {
            ptr->genDenominator++;
        }
        DEM_RESET_OBD_IUPR_CALC_GEN_DEN();
    
        /* Trigger permanet block update */
        Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                       DEM_NVM_PERMANET_BLOCK,
                                       DEM_NVM_REQ_WRITE,
                                       FALSE);
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcIUPRValue
*
* Explanation: IUPR value calculation
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdCalcIUPRValue(void)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 ratioIdx;
    uint16 evtIdx;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    
    /* IUPR ratio computation */
    for(ratioIdx = DEM_INIT_ONE; ratioIdx <= DEM_CFG_OBD_RATIO_NUM; ratioIdx++)
    {
        if((FALSE == DEM_GET_OBD_IUPR_CALC_DEN(ratioIdx)) ||
           (FALSE == DEM_GET_OBD_IUPR_CALC_NUM(ratioIdx)))
        {
            evtIdx = Dem_ConfigObdRatioTable[ratioIdx].awEvtIdx;

            if(evtIdx > DEM_INIT_ZERO)
            {
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
                if(TRUE == DEM_GET_AVAIL(evtIdx))
#endif
                {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    if(FALSE == DEM_GET_DTCSUPPRESSION(Dem_CfgEvtDtcIdx[evtIdx]))
#endif
                    {
                        if(ptr->denominator[ratioIdx] > DEM_INIT_ZERO)
                        {
                            ptr->iuprRatio[ratioIdx] = (uint32)((((uint32)ptr->numerator[ratioIdx]) << (uint32)16) / ((uint32)ptr->denominator[ratioIdx]));
        
                            /* Trigger permanet block update */
                            Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                                           DEM_NVM_PERMANET_BLOCK,
                                                           DEM_NVM_REQ_WRITE,
                                                           FALSE);
                        }
                    }
                }
            }
            else
            {
                if(ptr->denominator[ratioIdx] > DEM_INIT_ZERO)
                {
                    ptr->iuprRatio[ratioIdx] = (uint32)((((uint32)ptr->numerator[ratioIdx]) << (uint32)16) / ((uint32)ptr->denominator[ratioIdx]));
        
                    /* Trigger permanet block update */
                    Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                                   DEM_NVM_PERMANET_BLOCK,
                                                   DEM_NVM_REQ_WRITE,
                                                   FALSE);
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcIUPRCycle
*
* Explanation: IUPR cycle flag calculation
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdCalcIUPRCycle(void)
{
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_MASTER_ECU)
    if(DEM_IUMPR_DEN_STATUS_REACHED == DEM_GET_OBD_IUPR_DEN_COND(DEM_IUMPR_DEN_GENERAL))
    {
        DEM_SET_OBD_IUPR_CYCLE_FLAG(TRUE);
    }
    else
    {
        DEM_SET_OBD_IUPR_CYCLE_FLAG(FALSE);
    }
#else
    /* Master ECU should calculate the IUPR cycle flag */
#endif
}

/*
********************************************************************************
* Function Name: Dem_ObdIUPRProcess
*
* Explanation: IUPR process
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdIUPRProcess(void)
{
    Dem_ObdCalcIUPRCycle();
    
    if(TRUE == DEM_GET_OBD_IUPR_CYCLE_FLAG())
    {
        Dem_ObdCalcIUPRGenDenominator();
        
        Dem_ObdCalcIUPRDenominator();

        Dem_ObdCalcIUPRNumerator();

        Dem_ObdCalcIUPRValue();
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcDataOfPID21
*
* Explanation: Calculation of PID21
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdCalcDataOfPID21(void)
{
#if(DEM_CFG_MILINDICATORREF > DEM_BYTE_ZERO)
    uint32 vehSpd;
    Dem_PermanentEventMemoryEntry_st *ptr;
  
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    /* Check MIL status */
    if(DEM_GET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF) != DEM_INDICATOR_OFF)
    {
        /* Distance Calculation will be executed in every 1 second */
        if(Dem_PID21VehDriveTime < (uint16)(DEM_OBD_CALC_PARM_THOUSAND / DEM_CFG_TASKTIME))
        {
            /* Increament until 1sec */
            Dem_PID21VehDriveTime++;
        }
        else
        {
            /* Every second, do the distance calculation. */
            /* Increament uintl the calculated distance equal to 1km, then increament odoMilOn */
            if(Dem_PID21VehDriveDistance < (uint32)(DEM_OBD_CALC_PARM_THOUSAND * DEM_OBD_CALC_PARM_HUNDRED))
            {
                /* calculate MIL on distance with using vehicle speed, must in uint(km/h) */
                vehSpd = Dem_ObdGetGeneralData(DEM_CFG_OBD_VEHICLE_SPD);
                Dem_PID21VehDriveDistance += (uint32)(vehSpd * DEM_OBD_CALC_PARM_TWENTY_EIGHT);
            }
            else
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                if(ptr->odoMilOn < (uint32)DEM_WORD_MAX)
                {
                    ptr->odoMilOn++;
    
                    /* Trigger permanet block update */
                    Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                                   DEM_NVM_PERMANET_BLOCK,
                                                   DEM_NVM_REQ_WRITE,
                                                   FALSE);
                }
                Dem_PID21VehDriveDistance = DEM_INIT_ZERO;
            }
            
            Dem_PID21VehDriveTime = DEM_INIT_ZERO;
        }
    }
    else
    {
        Dem_PID21VehDriveTime = DEM_INIT_ZERO;
    }
#endif
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcDataOfPID31
*
* Explanation: Calculation of PID31
*
* param: None
*
* retval: None
********************************************************************************
*/

FUNC(void, DEM_CODE) Dem_ObdCalcDataOfPID31(void)
{
    uint32 vehSpd;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    
    /* Distance Calculation will be executed in every 1 second */
    if(Dem_PID31VehDriveTime < (uint16)(DEM_OBD_CALC_PARM_THOUSAND / DEM_CFG_TASKTIME))
    {
        /* Increament until 1sec */
        Dem_PID31VehDriveTime++;
    }
    else
    {
        /* Every second, do the distance calculation. */
        /* Increament uintl the calculated distance equal to 1km, then increament odoMilOn */
        if(Dem_PID31VehDriveDistance < (uint32)(DEM_OBD_CALC_PARM_THOUSAND * DEM_OBD_CALC_PARM_HUNDRED))
        {
            /* calculate MIL on distance with using vehicle speed, must in uint(km/h) */
            vehSpd = Dem_ObdGetGeneralData(DEM_CFG_OBD_VEHICLE_SPD);
            Dem_PID31VehDriveDistance += (uint32)(vehSpd * DEM_OBD_CALC_PARM_TWENTY_EIGHT);
        }
        else
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            if(ptr->odoSinceDtcClear < (uint32)DEM_WORD_MAX)
            {
                ptr->odoSinceDtcClear++;
    
                /* Trigger permanet block update */
                Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                               DEM_NVM_PERMANET_BLOCK,
                                               DEM_NVM_REQ_WRITE,
                                               FALSE);
            }
            Dem_PID31VehDriveDistance = DEM_INIT_ZERO;
        }
        
        Dem_PID31VehDriveTime = DEM_INIT_ZERO;
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcDataOfPID4D
*
* Explanation: Calculation of PID4D
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdCalcDataOfPID4D(void)
{
#if(DEM_CFG_MILINDICATORREF > DEM_BYTE_ZERO)
    uint32 engineRunTime;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    /* Check MIL status */
    if(DEM_GET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF) != DEM_INDICATOR_OFF)
    {
        /* Time in unit second */
        engineRunTime = Dem_ObdGetGeneralData(DEM_CFG_OBD_TIME_SINCE_ENGINE_START);
        if(engineRunTime >= Dem_PID4DMilOnEngineRunTime)
        {
            if((engineRunTime - Dem_PID4DMilOnEngineRunTime) >= DEM_BYTE_SIXTY)
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                if(ptr->engineRuntimeWhileMilOn < DEM_BYTE_MAX)
                {
                    ptr->engineRuntimeWhileMilOn++;
    
                    /* Trigger permanet block update */
                    Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                                   DEM_NVM_PERMANET_BLOCK,
                                                   DEM_NVM_REQ_WRITE,
                                                   FALSE);
                }
                Dem_PID4DMilOnEngineRunTime = engineRunTime;
            }
        }
        else
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            Dem_PID4DMilOnEngineRunTime = engineRunTime;
        }
    }
    else
    {
        Dem_PID4DMilOnEngineRunTime = Dem_ObdGetGeneralData(DEM_CFG_OBD_TIME_SINCE_ENGINE_START);
    }
#endif
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcDataOfPID4E
*
* Explanation: Calculation of PID4E
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdCalcDataOfPID4E(void)
{
    uint32 engineRunTime;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    /* Time in unit second */
    engineRunTime = Dem_ObdGetGeneralData(DEM_CFG_OBD_TIME_SINCE_ENGINE_START);
    if(engineRunTime >= Dem_PID4EMilOnEngineRunTime)
    {
        if((engineRunTime - Dem_PID4EMilOnEngineRunTime) >= DEM_BYTE_SIXTY)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            if(ptr->engineRuntimeSinceDtcClear < DEM_BYTE_MAX)
            {
                ptr->engineRuntimeSinceDtcClear++;
    
                /* Trigger permanet block update */
                Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                               DEM_NVM_PERMANET_BLOCK,
                                               DEM_NVM_REQ_WRITE,
                                               FALSE);
            }
            Dem_PID4EMilOnEngineRunTime = engineRunTime;
        }
    }
    else
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        Dem_PID4EMilOnEngineRunTime = engineRunTime;
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcDtrData
*
* Explanation: Calculation of DTR data
*
* param: DtrIdx, dtr index
*        DtrData, dat test result data
*
* retval: computation result
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint16, DEM_CODE) Dem_ObdCalcDtrData
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DtrIdx,
    sint32 DtrData
)
{
    uint16 retValue;
    sint32 tempVal1, tempVal2, tempVal3;

    tempVal1 = DtrData * Dem_ConfigDtrTable[DtrIdx].dtrCompuNumerator1;
    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" Polyspace +1 RTE:OVFL [JUstified:Unset] "NSCA_Polyspace_Dem_Overflow" */
    tempVal2 = tempVal1 + Dem_ConfigDtrTable[DtrIdx].dtrCompuNumerator0;
    if( (sint32)DEM_INIT_ZERO != Dem_ConfigDtrTable[DtrIdx].dtrCompuDenominator0 )
    {
        tempVal3 = tempVal2 / Dem_ConfigDtrTable[DtrIdx].dtrCompuDenominator0;
    }
    else
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        tempVal3 = (sint32)DEM_INIT_ZERO;
    }

    retValue = (uint16)tempVal3;

    return retValue;
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcDtrDataNormal
*
* Explanation: Normal Calculation of DTR data
*
* param: DTRIdx, dtr index
*        TestResult, test result
*        LowerLimit, lower limit
*        UpperLimit, upper limit
*
* retval: computation result
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_ObdCalcDtrDataNormal
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DTRIdx,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    sint32 TestResult,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    sint32 LowerLimit,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    sint32 UpperLimit
)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean dtrUpdate = FALSE;
    uint16 evtIdx;
    uint16 dtrResult, dtrLowerLimit, dtrUpperLimit;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((DTRIdx > DEM_INIT_ZERO) && (DTRIdx <= DEM_CFG_DTR_NUM))
    {
        /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(DEM_DTR_UPDATE_ALWAYS == Dem_ConfigDtrTable[DTRIdx].dtrUpdatekind)
        {
            dtrUpdate = TRUE;
        /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        }
        else
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            evtIdx = Dem_ConfigDtrTable[DTRIdx].dtrEventRefIdx;
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
            if((evtIdx > DEM_INIT_ZERO) && (TRUE == DEM_GET_AVAIL(evtIdx)))
#endif
            {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                if(FALSE == DEM_GET_DTCSUPPRESSION(Dem_CfgEvtDtcIdx[evtIdx]))
#endif
                {
                    if(FALSE == DEM_GET_UDS_STATUS_TNCTOC(evtIdx))
                    {
                        if((TestResult >= LowerLimit) && (TestResult <= UpperLimit))
                        {
                            dtrUpdate = TRUE;
                        }
                        else
                        {
                            if(TRUE == DEM_GET_UDS_STATUS_TFTOC(evtIdx))
                            {
                                dtrUpdate = TRUE;
                            }
                        }
                    }
                }
            }
        }

        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:USELESS_IF [JUstified:Unset] "NSCA_Polyspace_Common_UselessIf" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(TRUE == dtrUpdate)
        {
            dtrLowerLimit = Dem_ObdCalcDtrData(DTRIdx, LowerLimit);
            dtrUpperLimit = Dem_ObdCalcDtrData(DTRIdx, UpperLimit);
            dtrResult = Dem_ObdCalcDtrData(DTRIdx, TestResult);
            if(TestResult < LowerLimit)
            {
                if(dtrResult >= dtrLowerLimit)
                {
                    dtrResult--;
                }
            }
            else if(TestResult > UpperLimit)
            {
                if(dtrResult <= dtrUpperLimit)
                {
                    dtrResult++;
                }
            }
            else
            {
                if(dtrResult < dtrLowerLimit)
                {
                    dtrResult++;
                }
                else if(dtrResult > dtrUpperLimit)
                {
                    dtrResult--;
                }
                else
                {
                    /* do nothing */
                }
            }
            DEM_SET_OBD_DTR_RESULT(DTRIdx, dtrResult);
            DEM_SET_OBD_DTR_LOWERLIMIT(DTRIdx, dtrLowerLimit);
            DEM_SET_OBD_DTR_UPPERLIMIT(DTRIdx, dtrUpperLimit);
            ret = E_OK;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcDtrDataNoMax
*
* Explanation: No max value Calculation of DTR data
*
* param: DTRIdx, dtr index
*        TestResult, test result
*        LowerLimit, lower limit
*        UpperLimit, upper limit
*
* retval: computation result
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_ObdCalcDtrDataNoMax
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DTRIdx,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    sint32 TestResult,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    sint32 LowerLimit,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    sint32 UpperLimit
)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean dtrUpdate = FALSE;
    uint16 evtIdx;
    uint16 dtrResult, dtrLowerLimit;
    
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((DTRIdx > DEM_INIT_ZERO) && (DTRIdx <= DEM_CFG_DTR_NUM))
    {
        /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(DEM_DTR_UPDATE_ALWAYS == Dem_ConfigDtrTable[DTRIdx].dtrUpdatekind)
        {
            dtrUpdate = TRUE;
        /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        }
        else
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            evtIdx = Dem_ConfigDtrTable[DTRIdx].dtrEventRefIdx;
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
            if((evtIdx > DEM_INIT_ZERO) && (TRUE == DEM_GET_AVAIL(evtIdx)))
#endif
            {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                if(FALSE == DEM_GET_DTCSUPPRESSION(Dem_CfgEvtDtcIdx[evtIdx]))
#endif
                {
                    if(FALSE == DEM_GET_UDS_STATUS_TNCTOC(evtIdx))
                    {
                        if((TestResult >= LowerLimit) && (TestResult <= UpperLimit))
                        {
                            dtrUpdate = TRUE;
                        }
                        else
                        {
                            if(TRUE == DEM_GET_UDS_STATUS_TFTOC(evtIdx))
                            {
                                dtrUpdate = TRUE;
                            }
                        }
                    }
                }
            }
        }
        
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:USELESS_IF [JUstified:Unset] "NSCA_Polyspace_Common_UselessIf" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(TRUE == dtrUpdate)
        {
            dtrLowerLimit = Dem_ObdCalcDtrData(DTRIdx, LowerLimit);
            dtrResult = Dem_ObdCalcDtrData(DTRIdx, TestResult);
            if(TestResult < LowerLimit)
            {
                if(dtrResult >= dtrLowerLimit)
                {
                    dtrResult--;
                }
            }
            else
            {
                if(dtrResult < dtrLowerLimit)
                {
                    dtrResult++;
                }
            }
            DEM_SET_OBD_DTR_RESULT(DTRIdx, dtrResult);
            DEM_SET_OBD_DTR_LOWERLIMIT(DTRIdx, dtrLowerLimit);
            ret = E_OK;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcDtrDataNoMin
*
* Explanation: No min value Calculation of DTR data
*
* param: DTRIdx, dtr index
*        TestResult, test result
*        LowerLimit, lower limit
*        UpperLimit, upper limit
*
* retval: computation result
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_ObdCalcDtrDataNoMin
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DTRIdx,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    sint32 TestResult,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    sint32 LowerLimit,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    sint32 UpperLimit
)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean dtrUpdate = FALSE;
    uint16 evtIdx;
    uint16 dtrResult, dtrUpperLimit;
    
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((DTRIdx > DEM_INIT_ZERO) && (DTRIdx <= DEM_CFG_DTR_NUM))
    {
        /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(DEM_DTR_UPDATE_ALWAYS == Dem_ConfigDtrTable[DTRIdx].dtrUpdatekind)
        {
            dtrUpdate = TRUE;
        /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        }
        else
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            evtIdx = Dem_ConfigDtrTable[DTRIdx].dtrEventRefIdx;
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
            if((evtIdx > DEM_INIT_ZERO) && (TRUE == DEM_GET_AVAIL(evtIdx)))
#endif
            {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                if(FALSE == DEM_GET_DTCSUPPRESSION(Dem_CfgEvtDtcIdx[evtIdx]))
#endif
                {
                    if(FALSE == DEM_GET_UDS_STATUS_TNCTOC(evtIdx))
                    {
                        if((TestResult >= LowerLimit) && (TestResult <= UpperLimit))
                        {
                            dtrUpdate = TRUE;
                        }
                        else
                        {
                            if(TRUE == DEM_GET_UDS_STATUS_TFTOC(evtIdx))
                            {
                                dtrUpdate = TRUE;
                            }
                        }
                    }
                }
            }
        }
        
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:USELESS_IF [JUstified:Unset] "NSCA_Polyspace_Common_UselessIf" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(TRUE == dtrUpdate)
        {
            dtrUpperLimit = Dem_ObdCalcDtrData(DTRIdx, UpperLimit);
            dtrResult = Dem_ObdCalcDtrData(DTRIdx, TestResult);
            if(TestResult > UpperLimit)
            {
                if(dtrResult <= dtrUpperLimit)
                {
                    dtrResult++;
                }
            }
            else
            {
                if(dtrResult > dtrUpperLimit)
                {
                    dtrResult--;
                }
            }
            DEM_SET_OBD_DTR_RESULT(DTRIdx, dtrResult);
            DEM_SET_OBD_DTR_UPPERLIMIT(DTRIdx, dtrUpperLimit);
            ret = E_OK;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcDtrDataReset
*
* Explanation: Reset DTR data
*
* param: DTRIdx, dtr index
*
* retval: computation result
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_ObdCalcDtrDataReset
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 DTRIdx
)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean dtrUpdate = FALSE;
    uint16 evtIdx;
    
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((DTRIdx > DEM_INIT_ZERO) && (DTRIdx <= DEM_CFG_DTR_NUM))
    {
        /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(DEM_DTR_UPDATE_ALWAYS == Dem_ConfigDtrTable[DTRIdx].dtrUpdatekind)
        {
            dtrUpdate = TRUE;
        /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        }
        else
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            evtIdx = Dem_ConfigDtrTable[DTRIdx].dtrEventRefIdx;
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
            if((evtIdx > DEM_INIT_ZERO) && (TRUE == DEM_GET_AVAIL(evtIdx)))
#endif
            {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                if(FALSE == DEM_GET_DTCSUPPRESSION(Dem_CfgEvtDtcIdx[evtIdx]))
#endif
                {
                    dtrUpdate = TRUE;
                }
            }
        }

        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:USELESS_IF [JUstified:Unset] "NSCA_Polyspace_Common_UselessIf" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(TRUE == dtrUpdate)
        {
            DEM_SET_OBD_DTR_RESULT(DTRIdx, DEM_INIT_ZERO);
            DEM_SET_OBD_DTR_LOWERLIMIT(DTRIdx, DEM_INIT_ZERO);
            DEM_SET_OBD_DTR_UPPERLIMIT(DTRIdx, DEM_INIT_ZERO);
            ret = E_OK;
        }
    }

    return ret;
}

#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
/*
********************************************************************************
* Function Name: Dem_ObdSyncFreezeFreeDataStore
*
* Explanation: Store OBD legislative Freeze Frame
*
* param: uint16 EventIdx, event index
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdSyncFreezeFreeDataStore
(
    uint16 EventIdx
)
{
    uint8 syncBufPos;
    uint8 pidCnt, pidEleCnt, pidEleIdx;
    uint8 *destPtr;
    
    syncBufPos = DEM_GET_SSDATA_BUFFER_CNT();

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (syncBufPos < DEM_CFG_MAXNUMBEREVENTENTRYEVENTBUFFER))
    {
        destPtr = DEM_GET_SSDATA_OBDFFDATA_BUF_PTR(syncBufPos, DEM_INIT_ZERO);
        for(pidCnt = DEM_INIT_ONE; pidCnt <= DEM_CFG_OBD_PID_DATA_NUM; pidCnt++)
        {
            for(pidEleCnt = DEM_INIT_ZERO; pidEleCnt < DEM_CFG_PID_MAX_REF_DATA_ELEMENT_NUM; pidEleCnt++)
            {
                pidEleIdx = Dem_CfgObdPidDataTable[pidCnt].pidDataElementIdx[pidEleCnt];
                if(pidEleIdx != DEM_INIT_ZERO)
                {
                    if((Dem_CfgDataElementTable[pidEleIdx].acDataType == DEM_DATA_EMEMENT_TYPE_EXTERNALCS) ||
                       (Dem_CfgDataElementTable[pidEleIdx].acDataType == DEM_DATA_EMEMENT_TYPE_EXTERNALSR))
                    {
                        Dem_EventDataElementAcqusition(EventIdx, DEM_INIT_ZERO, DEM_INIT_ZERO, pidEleIdx, destPtr);
                        DEM_SET_SSDATA_OBD_STORED(EventIdx, TRUE);
                    }

                    destPtr = (uint8 *)&destPtr[Dem_CfgDataElementTable[pidEleIdx].acDataSize];
                }
                else
                {
                    break;
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdSyncFreezeFrameDataUpdate
*
* Explanation: Update sync OBD freeze frame data
*
* param: uint16 EventIdx, index of event index
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdSyncFreezeFrameDataUpdate
(
    uint16 EventIdx, 
    uint16 BufOffset,
    uint16 DataLen,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
)
{
    uint8 pos;
    uint16 byteIdx;
    uint8 *srcPtr;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (DestPtr != NULL_PTR))
    {
        pos = DEM_GET_SSDATA_BUFFER_POS(EventIdx);
        srcPtr = DEM_GET_SSDATA_OBDFFDATA_BUF_PTR(pos, BufOffset);

        for(byteIdx = DEM_INIT_ZERO; byteIdx < DataLen; byteIdx++)
        {
            DestPtr[byteIdx] = srcPtr[byteIdx];
        }
    }
}
#endif

/*
********************************************************************************
* Function Name: Dem_ObdFreezeFrameDataStore
*
* Explanation: Store OBD legislative Freeze Frame
*
* param: uint8 EventMemIdx, event memory index
*        uint16 EventIdx, event index
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdFreezeFrameDataStore
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx
)
{
    boolean updateFlag = FALSE;
    uint8 trigType;
    uint8 ffDataRecCnt;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;
    Dem_PermanentEventMemoryEntry_st *ptr;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM))
    {
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

        /* OBD freeze frame record 0x00 update */
        for(ffDataRecCnt = DEM_INIT_ONE; ffDataRecCnt <= DEM_CFG_FFDATA_RECORD_NUM; ffDataRecCnt++)
        {
            if(DEM_INIT_ZERO == Dem_CfgFfDataRecordTable[ffDataRecCnt].acFfDataRecordNum)
            {
                trigType = Dem_CfgFfDataRecordTable[ffDataRecCnt].acFfDataRecTrig;
                if(E_OK == Dem_EventCheckDataUpdateTrigger(EventIdx, trigType))
                {
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:USELESS_IF [JUstified:Unset] "NSCA_Polyspace_Common_UselessIf" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                    if((DEM_UPDATE_RECORD_YES == Dem_CfgFfDataRecordTable[ffDataRecCnt].acFfDataRecUpdate) ||
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                       (DEM_INIT_ZERO == ptr->freezeframeEvtId))
                    {
                        /* Polyspace +1 DEFECT:USELESS_IF [JUstified:Unset] "NSCA_Polyspace_Common_UselessIf" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                        if(Dem_CfgDTCTable[dtcIdx].acWwhObdClass == DEM_DTC_WWHOBD_CLASS_NOCLASS)
                        {
                            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                            if(E_OK == Dem_ObdFreezeFrameDataUpdate(EventIdx, EventMemIdx, EntryIdx))
                            {
                                updateFlag = TRUE;
                            }
                        }
                        else
                        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                        {
                            
                        }
                    }
                }
                break;
            }
        }

        if(TRUE == updateFlag)
        {
            /* Trigger update permanet block */
            Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                           DEM_NVM_PERMANET_BLOCK,
                                           DEM_NVM_REQ_WRITE,
                                           DEM_IMMEDIATE_STORE_NVM(EventIdx));
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdFreezeFrameDataUpdate
*
* Explanation: Update legislative Freeze Frame
*
* param: uint8 EventMemIdx, event memory index
*        Dem_EventIdType EventId, event id
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_ObdFreezeFrameDataUpdate
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 EntryIdx
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 pidCnt, pidEleCnt, pidEleIdx;
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
    uint16 dataLen = DEM_INIT_ZERO;
    uint16 bufOffset = DEM_INIT_ZERO;
#endif
    uint8 *dstPtr;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    dstPtr = &(ptr->freezeframedatBuf[DEM_INIT_ZERO]);

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        /* Legislative Freeze frame */
        for(pidCnt = DEM_INIT_ONE; pidCnt <= DEM_CFG_OBD_PID_DATA_NUM; pidCnt++)
        {
            for(pidEleCnt = DEM_INIT_ZERO; pidEleCnt < DEM_CFG_PID_MAX_REF_DATA_ELEMENT_NUM; pidEleCnt++)
            {
                pidEleIdx = Dem_CfgObdPidDataTable[pidCnt].pidDataElementIdx[pidEleCnt];
                if(pidEleIdx != DEM_INIT_ZERO)
                {
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
                    if(((Dem_CfgDataElementTable[pidEleIdx].acDataType == DEM_DATA_EMEMENT_TYPE_EXTERNALCS) ||
                       (Dem_CfgDataElementTable[pidEleIdx].acDataType == DEM_DATA_EMEMENT_TYPE_EXTERNALSR)) &&
                       (DEM_GET_SSDATA_BUFFER_POS(EventIdx) > DEM_INIT_ZERO))
                    {
                        dataLen = Dem_CfgDataElementTable[pidEleIdx].acDataSize;
                        Dem_ObdSyncFreezeFrameDataUpdate(EventIdx, bufOffset, dataLen, dstPtr);
                    }
                    else
                    {
                        Dem_EventDataElementAcqusition(EventIdx, EventMemIdx, EntryIdx, pidEleIdx, dstPtr);
                    }
                    bufOffset += Dem_CfgDataElementTable[pidEleIdx].acDataSize;
#else
                    Dem_EventDataElementAcqusition(EventIdx, EventMemIdx, EntryIdx, pidEleIdx, dstPtr);
#endif
                    dstPtr = (uint8 *)&dstPtr[Dem_CfgDataElementTable[pidEleIdx].acDataSize];

                    ret = E_OK;
                }
            }
        }

        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:USELESS_IF [JUstified:Unset] "NSCA_Polyspace_Common_UselessIf" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
        if(E_OK == ret)
        {
            ptr->freezeframeEvtId = Dem_CfgEventTable[EventIdx].awEvtId;
        }
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ObdPfcHandle
*
* Explanation: Handle of PFC control
*
* param: uint8 pfcAction, control type of PFC
*        uint16 pfcEvtId, event id of PFC
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdPfcHandle
(
    uint16 PfcEventIdx,
    uint8 PfcAction
)
{
    uint8 pfcCnt;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx, pfcDtcIdx, pfcEvtIdx;
    Dem_PermanentEventMemoryEntry_st *ptr;

    if((PfcEventIdx > DEM_INIT_ZERO) && (PfcEventIdx <= DEM_CFG_EVENT_NUM))
    {
        dtcIdx = Dem_CfgEvtDtcIdx[PfcEventIdx];
        ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    
        switch(PfcAction)
        {
            case DEM_OBD_PFC_HANDLE_ALLOCATE:
            {
                if(ptr->pfcCnt < DEM_CFG_MAXNUMBEREVENTENTRYPERMANENT)
                {
                    for(pfcCnt = DEM_INIT_ZERO; pfcCnt < ptr->pfcCnt; pfcCnt++)
                    {
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                        pfcEvtIdx = Dem_CfgEventIdTableIndex[ptr->pfcEvtId[pfcCnt]];
                        pfcDtcIdx = Dem_CfgEvtDtcIdx[pfcEvtIdx];
                        
                        if(Dem_CfgDTCTable[dtcIdx].acObdDtcIdx == Dem_CfgDTCTable[pfcDtcIdx].acObdDtcIdx)
                        {
                            /* PFC already exist */
                            break;
                        }
                    }

                    if(pfcCnt >= ptr->pfcCnt)
                    {
                        /* Allocate new PFC */
                        ptr->pfcEvtId[pfcCnt] = Dem_CfgEventTable[PfcEventIdx].awEvtId;
                        ptr->pfcVal[pfcCnt] = Dem_CfgObdDtcValue[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx];
                        ptr->pfcCnt++;

                        /* Trigger permanet block update */
                        Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                                       DEM_NVM_PERMANET_BLOCK,
                                                       DEM_NVM_REQ_WRITE,
                                                       DEM_IMMEDIATE_STORE_NVM(PfcEventIdx));
                    }
                }
                else
                {
                    /* permanent event memory overflow */
                }
                break;
            }
            case DEM_OBD_PFC_HANDLE_CLEAR:
            {
                for(pfcCnt = DEM_INIT_ZERO; pfcCnt < ptr->pfcCnt; pfcCnt++)
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                    if(Dem_CfgEventTable[PfcEventIdx].awEvtId == ptr->pfcEvtId[pfcCnt])
                    {
                        /* PFC exist */
                        break;
                    }
                }

                if(pfcCnt < ptr->pfcCnt)
                {
                    /* Remove this PFC */
                    if(pfcCnt == (ptr->pfcCnt - DEM_BYTE_ONE))
                    {
                        ptr->pfcEvtId[pfcCnt] = (uint16)DEM_INIT_ZERO;
                        ptr->pfcVal[pfcCnt] = (uint32)DEM_INIT_ZERO;
                        ptr->pfcCnt--;
                    }
                    else
                    {
                        /* Polyspace +1 DEFECT:OVERLAPPING_ASSIGN [Justified:Unset] "NSCA_Polyspace_Dem_OverlappingAssignment" */
                        for(pfcCnt = pfcCnt; pfcCnt < (ptr->pfcCnt - DEM_BYTE_ONE); pfcCnt++)
                        {
                            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                            ptr->pfcEvtId[pfcCnt] = ptr->pfcEvtId[pfcCnt + DEM_BYTE_ONE];
                            ptr->pfcVal[pfcCnt] = ptr->pfcVal[pfcCnt + DEM_BYTE_ONE];
                        }
                        ptr->pfcCnt--;
                    }

                    /* Trigger permanet block update */
                    Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                                   DEM_NVM_PERMANET_BLOCK,
                                                   DEM_NVM_REQ_CLEAR,
                                                   FALSE);
                }
                break;
            }
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            default:
            {
                break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdPfcProcess
*
* Explanation: Process of PFC control
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdPfcProcess(void)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 slotIdx, pfcIdx, ratioIdx;
    uint8 evtIndiIdx;
    uint8 opCycSt = DEM_BYTE_MAX;
#if(DEM_CFG_PFCCLEAREDINWUPCYCLE == STD_ON)
    uint8 warmUpCycSt = DEM_BYTE_MAX;
    uint8 opCycIdx;
#endif
    uint16 evtIdx;
    Dem_EventMemoryInfo_st *info_ptr;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    if(TRUE == DEM_GET_OBD_PFC_CYCLE_QUALIFIED())
    {
        info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(DEM_EVENT_MEMORY_PRIMARY);
        ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

#if(DEM_CFG_PFCCLEAREDINWUPCYCLE == STD_ON)
        for( opCycIdx = DEM_INIT_ZERO; opCycIdx <= DEM_CFG_OPCYC_NUM; opCycIdx++ )
        {
            if( DEM_OPCYC_WARMUP == Dem_CfgOperationCycleTable[opCycIdx].acCycType )
            {
                /* Get the status of current warm-up cycle. */
                warmUpCycSt = DEM_GET_OPCYC_STATE(opCycIdx);
                break;
            }
        }
#endif
        /* Process PFC store */
        for(slotIdx = DEM_INIT_ZERO; slotIdx < info_ptr->cntEnSlot; slotIdx++)
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
            evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[slotIdx]];
            if(Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acObdDtcIdx > DEM_INIT_ZERO)
            {
                /* OBD related event and request MIL ON */
                if((TRUE == Dem_EventCheckIndicatorStator(evtIdx, DEM_CFG_MILINDICATORREF)) &&
                   (TRUE == DEM_GET_UDS_STATUS_CDTC(evtIdx)))
                {
                    /* Store PFC */
                    Dem_ObdPfcHandle(evtIdx, DEM_OBD_PFC_HANDLE_ALLOCATE);
                }
            }
        }

        /* Process PFC remove */
        if(ptr->pfcCnt > DEM_INIT_ZERO)
        {
            for(pfcIdx = DEM_INIT_ZERO; pfcIdx < ptr->pfcCnt; pfcIdx++)
            {
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                evtIdx = Dem_CfgEventIdTableIndex[ptr->pfcEvtId[pfcIdx]];

                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if((FALSE == DEM_GET_UDS_STATUS_TFSLC(evtIdx)) && 
                   (FALSE == DEM_GET_UDS_STATUS_TNCTOC(evtIdx)) &&
                   (FALSE == DEM_GET_UDS_STATUS_TFTOC(evtIdx)))
                {
                    /* In case of faults information have been cleared */
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                    opCycSt = DEM_GET_OPCYC_STATE(Dem_CfgEventTable[evtIdx].acEvtOpcycIdx);
                    if((DEM_CYCLE_STATE_END == opCycSt) && 
                       (ptr->drvCycleCnt > DEM_INIT_ZERO))
                    {
                        for(ratioIdx = DEM_INIT_ONE; ratioIdx <= DEM_CFG_OBD_RATIO_NUM; ratioIdx++)
                        {
                            if(evtIdx == Dem_ConfigObdRatioTable[ratioIdx].awEvtIdx)
                            {
                                break;
                            }
                        }

                        if(ratioIdx <= DEM_CFG_OBD_RATIO_NUM)
                        {
                            /* If IUPR is required, PFC will be cleared when this fault is tested and */
                            /* no fault detected at the end of operation cycle [J.3.2.5.2 (A)] */
                            Dem_ObdPfcHandle(evtIdx, DEM_OBD_PFC_HANDLE_CLEAR);
                        }
                        else
                        {
#if(DEM_CFG_PFCCLEAREDINWUPCYCLE == STD_ON)
                            /* If IUPR is not required, PFC will be cleared when no event is detected at the */
                            /* end of warm-up cycle. [J.3.2.5.2 (B)]*/
                            if((DEM_CYCLE_STATE_END == warmUpCycSt) &&
                               ((ptr->warmUpCycleCnt > DEM_INIT_ZERO) ||
                                (DEM_INIT_ZERO < DEM_GET_OBD_WARMUP_CYCLE_CNT_SINCELASTINIT())) &&
                               (FALSE == DEM_GET_UDS_STATUS_PDTC(evtIdx)) &&
                               (FALSE == DEM_GET_UDS_STATUS_CDTC(evtIdx)))
                            {
                                Dem_ObdPfcHandle(evtIdx, DEM_OBD_PFC_HANDLE_CLEAR);
                            }
#else
                            if(TRUE == DEM_GET_OBD_IUPR_CYCLE_FLAG())
                            {
                                Dem_ObdPfcHandle(evtIdx, DEM_OBD_PFC_HANDLE_CLEAR);
                            }
#endif
                        }
                    }
                }
                else
                {
#if(DEM_CFG_PFCCLEAREDINWUPCYCLE == STD_ON)
                    if((TRUE == DEM_GET_UDS_STATUS_TFSLC(evtIdx)) &&
                       (FALSE == DEM_GET_UDS_STATUS_TFTOC(evtIdx)) &&
                       (FALSE == DEM_GET_UDS_STATUS_TNCTOC(evtIdx)) &&
                       (TRUE == DEM_GET_UDS_STATUS_CDTC(evtIdx)))
#else
                    /* [J.3.2.5.1] after Healing */
                    if((TRUE == DEM_GET_UDS_STATUS_TFSLC(evtIdx)) && (FALSE == DEM_GET_UDS_STATUS_TFTOC(evtIdx)))
#endif
                    {
                        for(evtIndiIdx = DEM_INIT_ZERO; evtIndiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; evtIndiIdx++)
                        {
                            /* Get the MIL indicator index. */
                            if(DEM_CFG_MILINDICATORREF == Dem_CfgEventTable[evtIdx].acIndiIdx[evtIndiIdx])
                            {
                                /* Check the event indicator status and WIR to clear PFC. */
                                if((FALSE == DEM_GET_UDS_STATUS_WIR(evtIdx)) && (FALSE == DEM_GET_INDICATOR(evtIdx, evtIndiIdx)))
                                {
                                    Dem_ObdPfcHandle(evtIdx, DEM_OBD_PFC_HANDLE_CLEAR);
                                    break;
                                }
                            }
                        }

                    }
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdClearDtrData
*
* Explanation: Clear DTR data
*
* param: uint16 evtIdx, event index
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdClearDtrData
(
    uint16 EventIdx
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtrIdx;
    
    for(dtrIdx = DEM_INIT_ONE; dtrIdx <= DEM_CFG_DTR_NUM; dtrIdx++)
    {
        if((EventIdx == Dem_ConfigDtrTable[dtrIdx].dtrEventRefIdx) ||
           (DEM_INIT_ZERO == Dem_ConfigDtrTable[dtrIdx].dtrEventRefIdx))
        {
            DEM_SET_OBD_DTR_RESULT(dtrIdx, DEM_INIT_ZERO);
            DEM_SET_OBD_DTR_LOWERLIMIT(dtrIdx, DEM_INIT_ZERO);
            DEM_SET_OBD_DTR_UPPERLIMIT(dtrIdx, DEM_INIT_ZERO);  
            /* For ensuring data consistency, an EventId can only be referenced */
            /* by at maximum one DTR. */
            break;
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdClearRelatedInfo
*
* Explanation: Clear OBD related info
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdClearRelatedInfo(void)
{
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    ptr->warmUpCycleCnt = DEM_INIT_ZERO;
    ptr->odoSinceDtcClear = DEM_INIT_ZERO;
    ptr->engineRuntimeSinceDtcClear = DEM_INIT_ZERO;
    
    Dem_ObdClearLegislativeFreezeFrame();
    
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
    Dem_ObdClearWwhInfo();
#endif

#if(DEM_CFG_CLEARBEHAVIOR != DEM_CLRRESP_VOLATILE)
    /* Request update event memory entry block */
    Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                   DEM_NVM_PERMANET_BLOCK,
                                   DEM_NVM_REQ_CLEAR,
                                   FALSE);
#endif

}

/*
********************************************************************************
* Function Name: Dem_ObdClearLegislativeFreezeFrame
*
* Explanation: Clear OBD Legislative Freeze Frame
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, DEM_CODE) Dem_ObdClearLegislativeFreezeFrame(void)
{
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    
    ptr->freezeframeEvtId = DEM_INIT_ZERO;
}

#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
/*
********************************************************************************
* Function Name: Dem_ObdCalcWwhContiMiCounter
*
* Explanation: Calculation of Continuous-MI counter
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdCalcWwhContiMiCounter(void)
{
    uint32 engineRunTime;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    if(DEM_GET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF) == DEM_INDICATOR_CONTINUOUS)
    {
        DEM_SET_WWH_CONTIMI_DET(TRUE);

        if(ptr->wwhContiMiCntHaltCycle >= DEM_BYTE_THREE)
        {
            ptr->wwhContiMiCnt = DEM_INIT_ZERO;
            ptr->wwhContiMiCntHaltCycle = DEM_INIT_ZERO;
        }

        /* Time in unit second */
        engineRunTime = Dem_ObdGetGeneralData(DEM_CFG_OBD_TIME_SINCE_ENGINE_START);
        if(engineRunTime >= DEM_GET_WWH_CONTIMICNT_ST())
        {
            if((engineRunTime - DEM_GET_WWH_CONTIMICNT_ST()) >= 3600)
            {
                if(ptr->wwhContiMiCnt < DEM_BYTE_MAX)
                {
                    ptr->wwhContiMiCnt++;
                }
                DEM_SET_WWH_CONTIMICNT_ST(engineRunTime);
            }
        }
        else
        {
            DEM_SET_WWH_CONTIMICNT_ST(engineRunTime);
        }

        ptr->wwhContiMiOffCnt = DEM_INIT_ZERO;
        DEM_SET_WWH_CONTIMIOFFCNT_ST(engineRunTime);
                            
#if(DEM_CFG_OBDSUPPORT == DEM_OBD_MASTER_ECU)
        /* Calculation of cumulative continuous-MI counter */
        if(engineRunTime >= DEM_GET_WWH_CUMUCONTIMICNT_ST())
        {
            if((engineRunTime - DEM_GET_WWH_CUMUCONTIMICNT_ST()) >= 3600)
            {
                if(ptr->wwhCumuContiMiCnt < DEM_BYTE_MAX)
                {
                    ptr->wwhCumuContiMiCnt++;
                }
                DEM_SET_WWH_CUMUCONTIMICNT_ST(engineRunTime);
            }
        }
        else
        {
            DEM_SET_WWH_CUMUCONTIMICNT_ST(engineRunTime);
        }
#endif
    
        /* Trigger permanet block update */
        Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                       DEM_NVM_PERMANET_BLOCK,
                                       DEM_NVM_REQ_WRITE,
                                       FALSE);
    }
    else
    {
        /* No continuous-MI is commanded to be on, stop counter */
        engineRunTime = Dem_ObdGetGeneralData(DEM_CFG_OBD_TIME_SINCE_ENGINE_START);
        DEM_SET_WWH_CONTIMICNT_ST(engineRunTime);
#if(DEM_CFG_OBDSUPPORT == DEM_OBD_MASTER_ECU)
        DEM_SET_WWH_CUMUCONTIMICNT_ST(engineRunTime);
#endif

        if(engineRunTime >= DEM_GET_WWH_CONTIMIOFFCNT_ST())
        {
            if((engineRunTime - DEM_GET_WWH_CONTIMIOFFCNT_ST()) >= 3600U)
            {
                if(ptr->wwhContiMiOffCnt < 200U)
                {
                    ptr->wwhContiMiOffCnt++;
                }
                else
                {
                    ptr->wwhContiMiCnt = DEM_INIT_ZERO;
                }
                DEM_SET_WWH_CONTIMICNT_ST(engineRunTime);
    
                /* Trigger permanet block update */
                Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                               DEM_NVM_PERMANET_BLOCK,
                                               DEM_NVM_REQ_WRITE,
                                               FALSE);
            }
        }
        else
        {
            DEM_SET_WWH_CONTIMICNT_ST(engineRunTime);
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcWwhB1Counter
*
* Explanation: Calculation of B1 counter
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdCalcWwhB1Counter(void)
{
    uint8 enSlotCnt;
    uint16 evtIdx, dtcIdx;
    uint32 engineRunTime;
    Dem_EventMemoryInfo_st *info_ptr;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(DEM_EVENT_MEMORY_PRIMARY);

    for(enSlotCnt = DEM_INIT_ZERO; enSlotCnt < info_ptr->cntEnSlot; enSlotCnt++)
    {
        evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[enSlotCnt]];
        dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];

        if(Dem_CfgDTCTable[dtcIdx].acObdDtcIdx > DEM_INIT_ZERO)
        {
            if(DEM_DTC_WWHOBD_CLASS_B1 == Dem_CfgDTCTable[dtcIdx].acWwhObdClass)
            {
                if((TRUE == DEM_GET_UDS_STATUS_TF(evtIdx)) &&
                   (TRUE == DEM_GET_UDS_STATUS_CDTC(evtIdx)))
                {
                    /* Time in unit second */
                    engineRunTime = Dem_ObdGetGeneralData(DEM_CFG_OBD_TIME_SINCE_ENGINE_START);
                    if(engineRunTime >= DEM_GET_WWH_B1COUNTER_ST())
                    {
                        if((engineRunTime - DEM_GET_WWH_B1COUNTER_ST()) >= 3600)
                        {
                            if(ptr->wwhB1Cnt < DEM_BYTE_MAX)
                            {
                                ptr->wwhB1Cnt++;
                                if(ptr->wwhB1Cnt > ptr->wwhB1CntHighest)
                                {
                                    ptr->wwhB1CntHighest = ptr->wwhB1Cnt;
                                }
    
                                /* Trigger permanet block update */
                                Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                                               DEM_NVM_PERMANET_BLOCK,
                                                               DEM_NVM_REQ_WRITE,
                                                               FALSE);
                            }
                            DEM_SET_WWH_B1COUNTER_ST(engineRunTime);
                        }
                    }
                    else
                    {
                        DEM_SET_WWH_B1COUNTER_ST(engineRunTime);
                    }
                    
                    DEM_SET_WWH_B1EVENT_DETECT(TRUE);
                    break;
                }
            }
        }
    }

    if(enSlotCnt >= info_ptr->cntEnSlot)
    {
        /* No class B1 event is detected as confirmed and testfailed, update B1COUNTER_STARTTIME */
        /* to latch B1 counter value */
        engineRunTime = Dem_ObdGetGeneralData(DEM_CFG_OBD_TIME_SINCE_ENGINE_START);
        DEM_SET_WWH_B1COUNTER_ST(engineRunTime);

        /* In case of B1 is over 200 and no found B1 event, set to 190 */
        if(ptr->wwhB1Cnt > DEM_BYTE_TWO_HUNDRED)
        {
            ptr->wwhB1Cnt = DEM_BYTE_ONE_HUNDRED_NINTY;
    
            /* Trigger permanet block update */
            Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                           DEM_NVM_PERMANET_BLOCK,
                                           DEM_NVM_REQ_WRITE,
                                           FALSE);
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcWwhActMode1
*
* Explanation: Calculation of WWH activation mode1
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdCalcWwhActMode1
(
    uint8 ActMode
)
{
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    if((ActMode & DEM_BYTE_MASK_BIT4) == DEM_BYTE_MASK_BIT4)
    {
        /* Mode4 conditions are present, set to mode4 */
        DEM_SET_WWH_ACT_MODE(DEM_OBD_WWH_ACTIVATION_MODE_4);
        /*DEM_SET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF, DEM_INDICATOR_CONTINUOUS);*/
        ptr->wwhContiMiCnt = DEM_INIT_ZERO;
        ptr->wwhContiMiCntAge = DEM_INIT_ZERO;
    
        /* Trigger permanet block update */
        Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                       DEM_NVM_PERMANET_BLOCK,
                                       DEM_NVM_REQ_WRITE,
                                       FALSE);
    }
    else if((ActMode & DEM_BYTE_MASK_BIT3) == DEM_BYTE_MASK_BIT3)
    {
        /* Mode3 conditions are present, set to mode3 */
        DEM_SET_WWH_ACT_MODE(DEM_OBD_WWH_ACTIVATION_MODE_3);
        /*DEM_SET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF, DEM_INDICATOR_SHORT);*/
    }
    else if((ActMode & DEM_BYTE_MASK_BIT2) == DEM_BYTE_MASK_BIT2)
    {
        /* Mode2 conditions are present, set to mode2 */
        DEM_SET_WWH_ACT_MODE(DEM_OBD_WWH_ACTIVATION_MODE_2);
        /*DEM_SET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF, DEM_INDICATOR_ON_DEMAND);*/
    }
    else
    {
        /* Keep in mode1 */
        /*DEM_SET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF, DEM_INDICATOR_OFF);*/
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcWwhActMode2
*
* Explanation: Calculation of WWH activation mode2
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdCalcWwhActMode2
(
    uint8 ActMode
)
{
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    if((ActMode & DEM_BYTE_MASK_BIT4) == DEM_BYTE_MASK_BIT4)
    {
        /* Mode4 conditions are present, set to mode4 */
        DEM_SET_WWH_ACT_MODE(DEM_OBD_WWH_ACTIVATION_MODE_4);
        /*DEM_SET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF, DEM_INDICATOR_CONTINUOUS);*/
        ptr->wwhContiMiCnt = DEM_INIT_ZERO;
        ptr->wwhContiMiCntAge = DEM_INIT_ZERO;
    
        /* Trigger permanet block update */
        Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                       DEM_NVM_PERMANET_BLOCK,
                                       DEM_NVM_REQ_WRITE,
                                       FALSE);
    }
    else if((ActMode & DEM_BYTE_MASK_BIT3) == DEM_BYTE_MASK_BIT3)
    {
        /* Mode3 conditions are present, set to mode3 */
        DEM_SET_WWH_ACT_MODE(DEM_OBD_WWH_ACTIVATION_MODE_3);
        /*DEM_SET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF, DEM_INDICATOR_SHORT);*/
    }
    else if((ActMode & DEM_BYTE_MASK_BIT2) != DEM_BYTE_MASK_BIT2)
    {
        /* Mode2 conditions are not present anymore, set to mode1 */
        DEM_SET_WWH_ACT_MODE(DEM_OBD_WWH_ACTIVATION_MODE_1);
        /*DEM_SET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF, DEM_INDICATOR_OFF);*/
    }
    else
    {
        /* Keep in mode2 */
        /*DEM_SET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF, DEM_INDICATOR_ON_DEMAND);*/
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcWwhActMode3
*
* Explanation: Calculation of WWH activation mode3
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdCalcWwhActMode3
(
    uint8 ActMode
)
{
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    if((ActMode & DEM_BYTE_MASK_BIT4) == DEM_BYTE_MASK_BIT4)
    {
        /* Mode4 conditions are present, set to mode4 */
        DEM_SET_WWH_ACT_MODE(DEM_OBD_WWH_ACTIVATION_MODE_4);
        /*DEM_SET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF, DEM_INDICATOR_CONTINUOUS);*/
        ptr->wwhContiMiCnt = DEM_INIT_ZERO;
        ptr->wwhContiMiCntAge = DEM_INIT_ZERO;
    
        /* Trigger permanet block update */
        Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                       DEM_NVM_PERMANET_BLOCK,
                                       DEM_NVM_REQ_WRITE,
                                       FALSE);
    }
    else if((ActMode & DEM_BYTE_MASK_BIT3) != DEM_BYTE_MASK_BIT3)
    {
        /* Mode3 conditions are not present anymore */
        DEM_SET_WWH_ACT_MODE(DEM_OBD_WWH_ACTIVATION_MODE_1);
        /*DEM_SET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF, DEM_INDICATOR_OFF);*/
    }
    else
    {
        /* Keep in mode3 */
        /*DEM_SET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF, DEM_INDICATOR_SHORT);*/
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcWwhActMode4
*
* Explanation: Calculation of WWH activation mode4
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdCalcWwhActMode4
(
    uint8 ActMode
)
{
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    if((ActMode & DEM_BYTE_MASK_BIT4) != DEM_BYTE_MASK_BIT4)
    {
        /* Mode4 conditions are not present anymore, degraded to mode3 */
        DEM_SET_WWH_ACT_MODE(DEM_OBD_WWH_ACTIVATION_MODE_3);
        /*DEM_SET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF, DEM_INDICATOR_SHORT);*/
    }
    else
    {
        /* Keep in mode4 */
        /*DEM_SET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF, DEM_INDICATOR_CONTINUOUS);*/
    }
}


/*
********************************************************************************
* Function Name: Dem_ObdCalcWwhActMode
*
* Explanation: Calculation of WWH activation mode
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdCalcWwhActMode(void)
{
    uint8 enSlotCnt;
    uint8 actMode = DEM_INIT_ZERO;
    uint16 evtIdx, dtcIdx;
    Dem_EventMemoryInfo_st *info_ptr;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(DEM_EVENT_MEMORY_PRIMARY);

    for(enSlotCnt = DEM_INIT_ZERO; enSlotCnt < info_ptr->cntEnSlot; enSlotCnt++)
    {
        evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[enSlotCnt]];
        dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
        
        if(Dem_CfgDTCTable[dtcIdx].acObdDtcIdx > DEM_INIT_ZERO)
        {
            if((TRUE == DEM_GET_UDS_STATUS_TF(evtIdx)) &&
               (TRUE == DEM_GET_UDS_STATUS_CDTC(evtIdx)))
            {
                switch(Dem_CfgDTCTable[dtcIdx].acWwhObdClass)
                {
                    case DEM_DTC_WWHOBD_CLASS_A:
                    {
                        /* mode 4 */
                        actMode |= DEM_BYTE_MASK_BIT4;
                        break;
                    }
                    case DEM_DTC_WWHOBD_CLASS_B1:
                    {
                        /* mode 3 */
                        if(ptr->wwhB1Cnt < 200U )
                        {
                            actMode |= DEM_BYTE_MASK_BIT3;
                        }
                        break;
                    }
                    case DEM_DTC_WWHOBD_CLASS_B2:
                    {
                        /* mode 3 */
                        if(ptr->wwhB1Cnt < 200U )
                        {
                            actMode |= DEM_BYTE_MASK_BIT3;
                        }
                        break;
                    }
                    case DEM_DTC_WWHOBD_CLASS_C:
                    {
                        /* mode 2 */
                        actMode |= DEM_BYTE_MASK_BIT2;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
        }
    }

    if(ptr->wwhB1Cnt >= 200U )
    {
        /* mode 4 */
        actMode |= DEM_BYTE_MASK_BIT4;
    }
    
    switch(DEM_GET_WWH_ACT_MODE())
    {
        case DEM_OBD_WWH_ACTIVATION_MODE_1:
        {
            Dem_ObdCalcWwhActMode1(actMode);
            break;
        }
        case DEM_OBD_WWH_ACTIVATION_MODE_2:
        {
            Dem_ObdCalcWwhActMode2(actMode);
            break;
        }
        case DEM_OBD_WWH_ACTIVATION_MODE_3:
        {
            Dem_ObdCalcWwhActMode3(actMode);
            break;
        }
        case DEM_OBD_WWH_ACTIVATION_MODE_4:
        {
            Dem_ObdCalcWwhActMode4(actMode);
            break;
        }
        default:
        {
            break;
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcWwhContiMiCounterHaltCycle
*
* Explanation: Calculation of Continuous-MI counter
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdCalcWwhContiMiCounterHaltCycle(void)
{
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    /* Continuous-MI counter */
    if(FALSE == DEM_GET_WWH_CONTIMI_DET())
    {
        ptr->wwhContiMiCntHaltCycle++;
    }
    else
    {
        ptr->wwhContiMiCntHaltCycle = DEM_INIT_ZERO;
    }
    
    /* Trigger permanet block update */
    Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                   DEM_NVM_PERMANET_BLOCK,
                                   DEM_NVM_REQ_WRITE,
                                   FALSE);
}

/*
********************************************************************************
* Function Name: Dem_ObdCalcWwhAgingHours
*
* Explanation: Calculation of wwh aging
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdCalcWwhAgingHours(void)
{
    uint8 enSlotCnt, entryIdx;
    uint16 evtIdx;
    uint32 engineRunTime = DEM_INIT_ZERO;
    Dem_EventMemoryInfo_st *info_ptr;
    Dem_EventMemoryEntry_st *entry_ptr;

    /* Get event memory pointer */
    info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(DEM_EVENT_MEMORY_PRIMARY);
    entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(DEM_EVENT_MEMORY_PRIMARY);

    for(enSlotCnt = DEM_INIT_ZERO; enSlotCnt < info_ptr->cntEnSlot; enSlotCnt++)
    {
        evtIdx = Dem_CfgEventIdTableIndex[info_ptr->enSlot[enSlotCnt]];
        entryIdx = info_ptr->entryIdx[enSlotCnt];

        if((Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acObdDtcIdx > DEM_INIT_ZERO) &&
           (Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acWwhObdClass > DEM_DTC_WWHOBD_CLASS_NOCLASS))
        {
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
            if((entry_ptr[entryIdx].cntAge >= Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acAgeCycThrs) ||
               (entry_ptr[entryIdx].cntAge2 >= Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acAgeCycThrs))
#else
            if(entry_ptr[entryIdx].cntAge >= Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[evtIdx]].acAgeCycThrs)
#endif
            {
                /* Time in unit second */
                engineRunTime = Dem_ObdGetGeneralData(DEM_CFG_OBD_TIME_SINCE_ENGINE_START);
                if(engineRunTime >= DEM_GET_WWH_AGING_ST(entryIdx))
                {
                    if((engineRunTime - DEM_GET_WWH_AGING_ST(entryIdx)) >= 3600)
                    {
                        if(entry_ptr[entryIdx].cntAgeHour < DEM_BYTE_MAX)
                        {
                            entry_ptr[entryIdx].cntAgeHour++;
                        }
                        DEM_SET_WWH_AGING_ST(entryIdx, engineRunTime);
                    }
                }
                else
                {
                    DEM_SET_WWH_AGING_ST(entryIdx, engineRunTime);
                }
            }
            else
            {
                entry_ptr[entryIdx].cntAgeHour = DEM_INIT_ZERO;
                DEM_SET_WWH_AGING_ST(entryIdx, engineRunTime);
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdClearWwhInfo
*
* Explanation: Clear wwh related info
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdClearWwhInfo(void)
{
    uint8 idx;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

    DEM_SET_WWH_ACT_MODE(DEM_OBD_WWH_ACTIVATION_MODE_1);

    ptr->wwhContiMiOffCnt = DEM_INIT_ZERO;
    ptr->wwhContiMiCntHaltCycle = DEM_INIT_ZERO;
    ptr->wwhContiMiCnt = DEM_INIT_ZERO;
    ptr->wwhContiMiCntAge = DEM_INIT_ZERO;
    ptr->wwhB1Cnt = DEM_INIT_ZERO;
    ptr->wwhB1CntHighest = DEM_INIT_ZERO;
    ptr->wwhB1CntAge = DEM_INIT_ZERO;
    ptr->wwhFreezeframeEvtId = DEM_INIT_ZERO;
    DEM_SET_WWH_CONTIMI_DET(FALSE);
    DEM_SET_WWH_B1EVENT_DETECT(FALSE);
    DEM_SET_WWH_CONTIMICNT_ST(DEM_INIT_ZERO);
    DEM_SET_WWH_CUMUCONTIMICNT_ST(DEM_INIT_ZERO);
    DEM_SET_WWH_B1COUNTER_ST(DEM_INIT_ZERO);
    for(idx = DEM_INIT_ZERO; idx < DEM_CFG_MAX_NUMBER_EVENT_ENTRY; idx++)
    {
        DEM_SET_WWH_AGING_ST(idx, DEM_INIT_ZERO);
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdAgingWwhContiMiCounter
*
* Explanation: Aging of Continuous-Mi counter
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdAgingWwhContiMiCounter(void)
{
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    /* Continuous-MI counter */
    if(FALSE == DEM_GET_WWH_CONTIMI_DET())
    {
        ptr->wwhContiMiCntAge++;
        if(ptr->wwhContiMiCntAge >= DEM_BYTE_FORTY)
        {
            /* Reset counter after 40 warmup cycle */
            ptr->wwhContiMiCnt = DEM_INIT_ZERO;
            ptr->wwhContiMiCntAge = DEM_INIT_ZERO;
        }
    }
    else
    {
        ptr->wwhContiMiCntAge = DEM_INIT_ZERO;
    }
    
    /* Trigger permanet block update */
    Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                   DEM_NVM_PERMANET_BLOCK,
                                   DEM_NVM_REQ_WRITE,
                                   FALSE);
}

/*
********************************************************************************
* Function Name: Dem_ObdAgingWwhB1Counter
*
* Explanation: Aging of B1 counter
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdAgingWwhB1Counter(void)
{
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    if(FALSE == DEM_GET_WWH_B1EVENT_DETECT())
    {
        ptr->wwhB1CntAge++;
        if(ptr->wwhB1CntAge > DEM_BYTE_THREE)
        {
            /* Reset counter after 3 OBD driving cycle */
            ptr->wwhB1Cnt = DEM_INIT_ZERO;
            ptr->wwhB1CntAge = DEM_INIT_ZERO;
        }
    }
    else
    {
        ptr->wwhB1CntAge = DEM_INIT_ZERO;
    }
    
    /* Trigger permanet block update */
    Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                   DEM_NVM_PERMANET_BLOCK,
                                   DEM_NVM_REQ_WRITE,
                                   FALSE);
}

/*
********************************************************************************
* Function Name: Dem_ObdGetWwhFFDataByDid
*
* Explanation: Get wwh freeze frame record 0 data 
*
* param: uint16 EventIdx, event index
*        uint16 DataId, event related data ID
*        uint8 *DestBuffer, buffer to receive the data
*        uint16 *BufSize, buffer size in bytes
*
* retval: E_OK, get data successfully; others, failed
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ObdGetWwhFFDataByDid
(
    uint16 EventIdx,
    uint16 DataId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 ffDataIdx;
    uint16 dtcIdx;
    uint8 *srcPtr;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    if((EventIdx > DEM_INIT_ZERO) && 
       (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (DestBuffer != NULL_PTR) &&
       (BufSize != NULL_PTR))
    {
        if(Dem_CfgEventTable[EventIdx].awEvtId == ptr->wwhFreezeframeEvtId)
        {
            dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
            ffDataIdx = Dem_CfgDTCTable[dtcIdx].acWobdFfDataClsIdx;
            srcPtr = &(ptr->wwhFreezeframedatBuf[DEM_INIT_ZERO]);
            ret = Dem_EventGetFFDataByDid(ffDataIdx, DataId, srcPtr, DestBuffer, BufSize);
        }
        else
        {
            ret = DEM_E_NODATAAVAILABLE;
        }
    }

    return ret;
}

#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
/*
********************************************************************************
* Function Name: Dem_ObdWwhSyncFreezeFrameDataStore
*
* Explanation: Store wwhOBD legislative Freeze Frame
*
* param: uint16 EventIdx, event index
*        uint8 EventMemIdx, event memory index
*        uint8 EntryIdx, entry index
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdWwhSyncFreezeFrameDataStore
(
    uint16 EventIdx
)
{
    uint8 syncBufPos;
    uint8 ffDataClsIdx;
    uint8 ffDidCnt, ffDidIdx, ffDidEleCnt, ffDidEleIdx;
    uint8 *destPtr;

    syncBufPos = DEM_GET_SSDATA_BUFFER_CNT();
    
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (syncBufPos < DEM_CFG_MAXNUMBEREVENTENTRYEVENTBUFFER))
    {
        destPtr = DEM_GET_SSDATA_WWHFFDATA_BUF_PTR(syncBufPos, DEM_INIT_ZERO);
        ffDataClsIdx = Dem_CfgDtcFfDataClsIdx[Dem_CfgEvtDtcIdx[EventIdx]];
        /* Wwh-OBD freeze frame record 0x00 update */
        for(ffDidCnt = DEM_INIT_ZERO; ffDidCnt < DEM_CFG_FFDATA_MAX_REF_DID_NUM; ffDidCnt++)
        {
            ffDidIdx = Dem_CfgFfDataTable[ffDataClsIdx].acFfDataDidIdx[ffDidCnt];
            if(DEM_INIT_ZERO != ffDidIdx)
            {
                for(ffDidEleCnt = DEM_INIT_ZERO; ffDidEleCnt < DEM_CFG_DID_MAX_REF_DATA_ELEMENT_NUM; ffDidEleCnt++)
                {
                    ffDidEleIdx = Dem_CfgDidTable[ffDidIdx].acDataElementIdx[ffDidEleCnt];
                    if(ffDidEleIdx != DEM_INIT_ZERO)
                    {
                        if((Dem_CfgDataElementTable[ffDidEleIdx].acDataType == DEM_DATA_EMEMENT_TYPE_EXTERNALCS) ||
                           (Dem_CfgDataElementTable[ffDidEleIdx].acDataType == DEM_DATA_EMEMENT_TYPE_EXTERNALSR))
                        {
                            Dem_EventDataElementAcqusition(EventIdx, DEM_INIT_ZERO, DEM_INIT_ZERO, ffDidEleIdx, destPtr);
                            DEM_SET_SSDATA_WWHOBD_STORED(EventIdx, TRUE);
                        }
                        
                        destPtr = (uint8 *)&destPtr[Dem_CfgDataElementTable[ffDidEleIdx].acDataSize];
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdWwhSyncFreezeFrameDataUpdate
*
* Explanation: Store OBD legislative Freeze Frame
*
* param: uint16 EventIdx, event index
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdWwhSyncFreezeFrameDataUpdate
(
    uint16 EventIdx, 
    uint16 BufOffset,
    uint16 DataLen,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestPtr
)
{
    uint8 pos;
    uint16 byteIdx;
    uint8 *srcPtr;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (DestPtr != NULL_PTR))
    {
        pos = DEM_GET_SSDATA_BUFFER_POS(EventIdx);
        srcPtr = DEM_GET_SSDATA_WWHFFDATA_BUF_PTR(pos, BufOffset);

        for(byteIdx = DEM_INIT_ZERO; byteIdx < DataLen; byteIdx++)
        {
            DestPtr[byteIdx] = srcPtr[byteIdx];
        }
    }
}
#endif

/*
********************************************************************************
* Function Name: Dem_ObdFreezeFrameDataStore
*
* Explanation: Store OBD legislative Freeze Frame
*
* param: uint16 EventIdx, event index
*        uint8 EventMemIdx, event memory index
*        uint8 EntryIdx, entry index
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdWwhFreezeFrameDataStore
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 EntryIdx
)
{
    boolean updateFlag = FALSE;
    uint8 trigType;
    uint8 ffDataRecCnt;
    Dem_PermanentEventMemoryEntry_st *ptr;

    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) &&
       (EventMemIdx > DEM_INIT_ZERO) && (EventMemIdx <= DEM_CFG_EVENT_MEMORY_NUM))
    {
        ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

        /* Wwh-OBD freeze frame record 0x00 update */
        for(ffDataRecCnt = DEM_INIT_ONE; ffDataRecCnt <= DEM_CFG_FFDATA_RECORD_NUM; ffDataRecCnt++)
        {
            if(DEM_INIT_ZERO == Dem_CfgFfDataRecordTable[ffDataRecCnt].acFfDataRecordNum)
            {
                trigType = Dem_CfgFfDataRecordTable[ffDataRecCnt].acFfDataRecTrig;
                if(E_OK == Dem_EventCheckDataUpdateTrigger(EventIdx, trigType))
                {
                    /* In case of configure to DEM_UPDATE_RECORD_NO, do not update exist event */
                    if((DEM_UPDATE_RECORD_YES == Dem_CfgFfDataRecordTable[ffDataRecCnt].acFfDataRecUpdate) ||
                       (ptr->freezeframeEvtId > DEM_INIT_ZERO))
                    {
                        if(E_OK == Dem_ObdWwhFreezeFrameDataUpdate(EventIdx, EventMemIdx, EntryIdx))
                        {
                            updateFlag = TRUE;
                        }
                    }
                }
                break;
            }
        }

        if(TRUE == updateFlag)
        {
            /* Trigger update permanet block */
            Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                           DEM_NVM_PERMANET_BLOCK,
                                           DEM_NVM_REQ_WRITE,
                                           DEM_IMMEDIATE_STORE_NVM(EventIdx));
        }
    }
}

/*
********************************************************************************
* Function Name: Dem_ObdWwhFreezeFrameDataUpdate
*
* Explanation: Update legislative Freeze Frame
*
* param: uint8 EventMemIdx, event memory index
*        Dem_EventIdType EventId, event id
*
* retval: None
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ObdWwhFreezeFrameDataUpdate
(
    uint16 EventIdx,
    uint8 EventMemIdx,
    uint8 EntryIdx
)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean obdUpdate = FALSE;
    uint8 ffDataClsIdx, ffDidCnt, ffDidIdx, ffDidEleCnt, ffDidEleIdx;
    uint16 dtcIdx, oldevtIdx, olddtcIdx;
    uint16 dataLen = DEM_INIT_ZERO;
    uint16 bufOffset = DEM_INIT_ZERO;
    uint8 *dstPtr;
    Dem_PermanentEventMemoryEntry_st *ptr;

    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    dstPtr = &(ptr->freezeframedatBuf[DEM_INIT_ZERO]);
    
    if((EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM))
    {
        dtcIdx = Dem_CfgEvtDtcIdx[EventIdx];
        /* WWH-OBD freeze frame */
        ffDataClsIdx = Dem_CfgDTCTable[dtcIdx].acWobdFfDataClsIdx;

        if((ptr->wwhFreezeframeEvtId > DEM_INIT_ZERO) && (ptr->wwhFreezeframeEvtId <= DEM_CFG_EVENT_NUM))
        {
            oldevtIdx = Dem_CfgEventIdTableIndex[ptr->wwhFreezeframeEvtId];
            olddtcIdx = Dem_CfgEvtDtcIdx[oldevtIdx];
            if(Dem_CfgDTCTable[dtcIdx].acWwhObdClass > Dem_CfgDTCTable[olddtcIdx].acWwhObdClass)
            {
                obdUpdate = TRUE;
            }
        }
        else
        {
            /* In case of incorrect event stored, restore an new event */
            if((ffDataClsIdx > DEM_INIT_ZERO) && (ffDataClsIdx <= DEM_CFG_FFDATA_NUM))
            {
                obdUpdate = TRUE;
            }
        }

        if(TRUE == obdUpdate)
        {
            for(ffDidCnt = DEM_INIT_ZERO; ffDidCnt < DEM_CFG_FFDATA_MAX_REF_DID_NUM; ffDidCnt++)
            {
                ffDidIdx = Dem_CfgFfDataTable[ffDataClsIdx].acFfDataDidIdx[ffDidCnt];
                if(DEM_INIT_ZERO != ffDidIdx)
                {
                    for(ffDidEleCnt = DEM_INIT_ZERO; ffDidEleCnt < DEM_CFG_DID_MAX_REF_DATA_ELEMENT_NUM; ffDidEleCnt++)
                    {
                        ffDidEleIdx = Dem_CfgDidTable[ffDidIdx].acDataElementIdx[ffDidEleCnt];
                        if(DEM_INIT_ZERO != ffDidEleIdx)
                        {
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
                            if(((Dem_CfgDataElementTable[ffDidEleIdx].acDataType == DEM_DATA_EMEMENT_TYPE_EXTERNALCS) ||
                               (Dem_CfgDataElementTable[ffDidEleIdx].acDataType == DEM_DATA_EMEMENT_TYPE_EXTERNALSR)) &&
                               (TRUE == DEM_GET_SSDATA_WWHOBD_STORED(EventIdx)))
                            {
                                dataLen = Dem_CfgDataElementTable[ffDidEleIdx].acDataSize;
                                Dem_ObdWwhSyncFreezeFrameDataUpdate(EventIdx, bufOffset, dataLen, dstPtr);
                            }
                            else
                            {
                                Dem_EventDataElementAcqusition(EventIdx, EventMemIdx, EntryIdx, ffDidEleIdx, dstPtr);
                            }
                            bufOffset += Dem_CfgDataElementTable[ffDidEleIdx].acDataSize;
#else
                            Dem_EventDataElementAcqusition(EventIdx, EventMemIdx, EntryIdx, ffDidEleIdx, dstPtr);
#endif
                            dstPtr = (uint8 *)&dstPtr[Dem_CfgDataElementTable[ffDidEleIdx].acDataSize];

                            ret = E_OK;
                        }
                    }
                }
                else
                {
                    break;
                }
            }

            if(E_OK == ret)
            {
                ptr->wwhFreezeframeEvtId = Dem_CfgEventTable[EventIdx].awEvtId;
            }
        }
    }

    return ret;
}
#endif

/*
********************************************************************************
* Function Name: Dem_ObdAgingWwhB1Counter
*
* Explanation: Initialization of OBD
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdInit(void)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 ratioIdx, iuprCondId;
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
    uint8 idx;
#endif
    uint16 evtIdx;
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_MASTER_ECU)
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
#endif
    /* Initialize the counter of warm-up cycle counter. */
    DEM_SET_OBD_WARMUP_CYCLE_CNT_SINCELASTINIT(DEM_INIT_ZERO);
    DEM_SET_OBD_PFC_CYCLE_QUALIFIED(FALSE);

    /* Initialize the counter of warm-up cycle counter during the last driving cycles. */
    DEM_SET_OBD_WUC_STARTED_LAST_DRICYC(DEM_INIT_ZERO);

    /* Initializaiton of IUPR calculation */
    DEM_RESET_OBD_IUPR_CALC_GEN_DEN();
    for(ratioIdx = DEM_INIT_ONE; ratioIdx <= DEM_CFG_OBD_RATIO_NUM; ratioIdx++)
    {
        DEM_RESET_OBD_IUPR_CALC_NUM(ratioIdx);
        DEM_RESET_OBD_IUPR_CALC_DEN(ratioIdx);
        DEM_SET_OBD_IUPR_NUM_COND_ASYM(ratioIdx, FALSE);
        DEM_SET_OBD_IUPR_DEN_PHSY_COND(ratioIdx, DEM_IUMPR_DEN_STATUS_NOT_REACHED);
    }

    /*  Initializaiton of additional IUPR Denominator condition status */
    for(iuprCondId = DEM_INIT_ONE; iuprCondId <= DEM_IUMPR_DEM_NUM; iuprCondId++)
    {
        DEM_SET_OBD_IUPR_DEN_COND(iuprCondId, DEM_IUMPR_DEN_STATUS_NOT_REACHED);
    }

    /* Initializaiton of pid41 disable status */
    for(evtIdx = DEM_INIT_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
    {
        DEM_SET_OBD_EVENT_DISABLE_PID41(evtIdx, FALSE);
    }

#if(DEM_CFG_PTOSUPPORT == STD_ON)
    DEM_SET_OBD_IUPR_PTO_STATUS(FALSE);
#endif
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
    /* Initializaiton of wwh activation mode */
    DEM_SET_WWH_ACT_MODE(DEM_OBD_WWH_ACTIVATION_MODE_1);
    DEM_SET_WWH_CONTIMI_DET(FALSE);
    DEM_SET_WWH_B1EVENT_DETECT(FALSE);
    DEM_SET_WWH_CONTIMICNT_ST(DEM_INIT_ZERO);
    DEM_SET_WWH_CUMUCONTIMICNT_ST(DEM_INIT_ZERO);
    DEM_SET_WWH_B1COUNTER_ST(DEM_INIT_ZERO);
    for(idx = DEM_INIT_ZERO; idx < DEM_CFG_MAX_NUMBER_EVENT_ENTRY; idx++)
    {
        DEM_SET_WWH_AGING_ST(idx, DEM_INIT_ZERO);
    }
#endif

#if(DEM_CFG_OBDSUPPORT != DEM_OBD_MASTER_ECU)
    /* Initialization of PID21 data in case of not master ECU */
    ptr->odoMilOn = 0xFFFFU;
#endif
}

/*
********************************************************************************
* Function Name: Dem_ObdAgingWwhB1Counter
*
* Explanation: Process of OBD
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ObdMainProcess(void)
{
    Dem_ObdPfcProcess();
#if((DEM_CFG_OBDSUPPORT == DEM_OBD_MASTER_ECU) || (DEM_CFG_OBDSUPPORT == DEM_OBD_PRIMARY_ECU))
    Dem_ObdIUPRProcess();
#endif
#if(DEM_CFG_OBDSUPPORT == DEM_OBD_MASTER_ECU)
    Dem_ObdCalcDataOfPID21();
    Dem_ObdCalcDataOfPID31();
    Dem_ObdCalcDataOfPID4D();
    Dem_ObdCalcDataOfPID4E();
#endif
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
    Dem_ObdCalcWwhContiMiCounter();
    Dem_ObdCalcWwhB1Counter();
    Dem_ObdCalcWwhActMode();
    Dem_ObdCalcWwhAgingHours();
#endif

}
#endif

#if( DEM_CFG_J1939SUPPORT == STD_ON )
#if( DEM_CFG_J1939READINGDTCSUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Dem_EventReturnLampStatus
*
* Explanation: The function returns the composite lamp status of the filtered DTC.
*
* param:uint16 LampStatus:The status of lamp.
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ReturnLampStatus
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) LampStatus
)
{
    uint16 lampStatus = DEM_LAMP_INIT;

#if( DEM_CFG_MILINDICATORREF > DEM_VALUE_ZERO )
    if( DEM_INDICATOR_OFF != DEM_GET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF) )
    {
        lampStatus |= (DEM_LAMP_ON << DEM_BYTE_FOURTEEN);  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_MILINDICATORREF > DEM_VALUE_ZERO */
#if( DEM_CFG_REDSTOPLAMPINDICATOR > DEM_VALUE_ZERO )
    if(DEM_INDICATOR_OFF != DEM_GET_INDICATOR_STATUS(DEM_CFG_REDSTOPLAMPINDICATOR))
    {
        lampStatus |= (DEM_LAMP_ON << DEM_BYTE_TWELVE);  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_REDSTOPLAMPINDICATOR > DEM_VALUE_ZERO */
#if( DEM_CFG_AMBERWARNINGLAMPINDICATOR > DEM_VALUE_ZERO )
    if( DEM_INDICATOR_OFF != DEM_GET_INDICATOR_STATUS(DEM_CFG_AMBERWARNINGLAMPINDICATOR) )
    {
        lampStatus |= (DEM_LAMP_ON << DEM_BYTE_TEN);  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_AMBERWARNINGLAMPINDICATOR > DEM_VALUE_ZERO */
#if( DEM_CFG_PROTECTLAMPINDICATOR > DEM_VALUE_ZERO )
    if( DEM_INDICATOR_OFF != DEM_GET_INDICATOR_STATUS(DEM_CFG_PROTECTLAMPINDICATOR) )
    {
        lampStatus |= (DEM_LAMP_ON << DEM_BYTE_EIGHT);  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_PROTECTLAMPINDICATOR > DEM_VALUE_ZERO */

#if( DEM_CFG_MILINDICATORREF > DEM_VALUE_ZERO )
    if( (DEM_INDICATOR_CONTINUOUS == DEM_GET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF)) ||
        (DEM_INDICATOR_OFF == DEM_GET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF)) )
    {
        lampStatus |= (DEM_NO_FLASH << DEM_BYTE_SIX);  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_MILINDICATORREF > DEM_VALUE_ZERO */
#if( DEM_CFG_REDSTOPLAMPINDICATOR > DEM_VALUE_ZERO )
    if( (DEM_INDICATOR_CONTINUOUS == DEM_GET_INDICATOR_STATUS(DEM_CFG_REDSTOPLAMPINDICATOR)) ||
        (DEM_INDICATOR_OFF == DEM_GET_INDICATOR_STATUS(DEM_CFG_REDSTOPLAMPINDICATOR)) )
    {
        lampStatus |= (DEM_NO_FLASH << DEM_BYTE_FOUR);  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_REDSTOPLAMPINDICATOR > DEM_VALUE_ZERO */
#if( DEM_CFG_AMBERWARNINGLAMPINDICATOR > DEM_VALUE_ZERO )
    if( (DEM_INDICATOR_CONTINUOUS == DEM_GET_INDICATOR_STATUS(DEM_CFG_AMBERWARNINGLAMPINDICATOR)) ||
        (DEM_INDICATOR_OFF == DEM_GET_INDICATOR_STATUS(DEM_CFG_AMBERWARNINGLAMPINDICATOR)) )
    {
        lampStatus |= (DEM_NO_FLASH << DEM_BYTE_TWO);  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_AMBERWARNINGLAMPINDICATOR > DEM_VALUE_ZERO */
#if( DEM_CFG_PROTECTLAMPINDICATOR > DEM_VALUE_ZERO )
    if( (DEM_INDICATOR_CONTINUOUS == DEM_GET_INDICATOR_STATUS(DEM_CFG_PROTECTLAMPINDICATOR)) ||
        (DEM_INDICATOR_OFF == DEM_GET_INDICATOR_STATUS(DEM_CFG_PROTECTLAMPINDICATOR)) )
    {
        lampStatus |= DEM_NO_FLASH;  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_PROTECTLAMPINDICATOR > DEM_VALUE_ZERO */

#if( DEM_CFG_MILINDICATORREF > DEM_VALUE_ZERO )
    if( DEM_INDICATOR_SLOW_FLASH == DEM_GET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF) )
    {
        lampStatus |= (DEM_SLOW_FLASH << DEM_BYTE_SIX);  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_MILINDICATORREF > DEM_VALUE_ZERO */
#if( DEM_CFG_REDSTOPLAMPINDICATOR > DEM_VALUE_ZERO )
    if( DEM_INDICATOR_SLOW_FLASH == DEM_GET_INDICATOR_STATUS(DEM_CFG_REDSTOPLAMPINDICATOR) )
    {
        lampStatus |= (DEM_SLOW_FLASH << DEM_BYTE_FOUR);  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_REDSTOPLAMPINDICATOR > DEM_VALUE_ZERO */
#if( DEM_CFG_AMBERWARNINGLAMPINDICATOR > DEM_VALUE_ZERO )
    if( DEM_INDICATOR_SLOW_FLASH == DEM_GET_INDICATOR_STATUS(DEM_CFG_AMBERWARNINGLAMPINDICATOR) )
    {
        lampStatus |= (DEM_SLOW_FLASH << DEM_BYTE_TWO);  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_AMBERWARNINGLAMPINDICATOR > DEM_VALUE_ZERO */
#if( DEM_CFG_PROTECTLAMPINDICATOR > DEM_VALUE_ZERO )
    if( DEM_INDICATOR_SLOW_FLASH == DEM_GET_INDICATOR_STATUS(DEM_CFG_PROTECTLAMPINDICATOR) )
    {
        lampStatus |= DEM_SLOW_FLASH;  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_PROTECTLAMPINDICATOR > DEM_VALUE_ZERO */

#if( DEM_CFG_MILINDICATORREF > DEM_VALUE_ZERO )
    if( DEM_INDICATOR_FAST_FLASH == DEM_GET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF) )
    {
        lampStatus |= (DEM_FAST_FLASH << DEM_BYTE_SIX);  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_MILINDICATORREF > DEM_VALUE_ZERO */
#if( DEM_CFG_REDSTOPLAMPINDICATOR > DEM_VALUE_ZERO )
    if( DEM_INDICATOR_FAST_FLASH == DEM_GET_INDICATOR_STATUS(DEM_CFG_REDSTOPLAMPINDICATOR) )
    {
        lampStatus |= (DEM_FAST_FLASH << DEM_BYTE_FOUR);  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_REDSTOPLAMPINDICATOR > DEM_VALUE_ZERO */
#if( DEM_CFG_AMBERWARNINGLAMPINDICATOR > DEM_VALUE_ZERO )
    if( DEM_INDICATOR_FAST_FLASH == DEM_GET_INDICATOR_STATUS(DEM_CFG_AMBERWARNINGLAMPINDICATOR) )
    {
        lampStatus |= (DEM_FAST_FLASH << DEM_BYTE_TWO);  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_AMBERWARNINGLAMPINDICATOR > DEM_VALUE_ZERO */
#if( DEM_CFG_PROTECTLAMPINDICATOR > DEM_VALUE_ZERO )
    if( DEM_INDICATOR_FAST_FLASH == DEM_GET_INDICATOR_STATUS(DEM_CFG_PROTECTLAMPINDICATOR) )
    {
        lampStatus |= DEM_FAST_FLASH;  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
    }
#endif /* DEM_CFG_PROTECTLAMPINDICATOR > DEM_VALUE_ZERO */

    *LampStatus = lampStatus;  /* PRQA S 4397 */ /* NSCA_QAC_Dem_Rule10.7 */
}

/*
********************************************************************************
* Function Name: Dem_EventJ1939CalcDtcFilteredNum
*
* Explanation: Calculate the Filtered J1939 DTC number.
*
* param: none
*
* retval: E_NOT_OK: In calculating.
*         E_OK: Calculation finished.
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventCalcJ1939DtcFilteredNum(void)
{
    uint8 ret = E_NOT_OK;
    uint8 node = DEM_INIT_ZERO;
    uint16 numMatchedDtc = DEM_INIT_ZERO;
    uint16 evtIdx = DEM_INIT_ZERO;
    uint16 dtcIdx = DEM_INIT_ZERO;
    uint16 numComEvt = DEM_INIT_ZERO;

    numMatchedDtc = DEM_GET_J1939_DTC_FILTER_MATCH_NUM();

    for( dtcIdx = DEM_BYTE_ONE; dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++ )
    {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION )
        if( FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx) )
#endif
        {
            node = DEM_GET_J1939_DTC_NODE();
            if( (node == Dem_CfgDTCTable[dtcIdx].acJ1939DtcNdId) &&
                ((DEM_GET_J1939_DTC_FILTER_KIND() == DEM_DTC_KIND_ALL_DTCS) ||
                 (DEM_INIT_ZERO != Dem_CfgDTCTable[dtcIdx].acObdDtcIdx)) )    /* Judge whether obd is configured */
            {
                for( numComEvt = DEM_INIT_ZERO; numComEvt <= DEM_CFG_COMB_DTC_MAX_EVENT_NUM; numComEvt++ )
                {
                    evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[numComEvt];
                    /* If ComEvt have one event get through,the related DTC should be calced  */
                    if( E_OK == Dem_EventCheckJ1939DtcFilterMatch(evtIdx) )
                    {
                        numMatchedDtc++;
                        break;
                    }
                }
            }
        }
    }

    ret = E_OK;
    DEM_SET_J1939_DTC_FILTER_MATCH_NUM(numMatchedDtc);

    return ret;
}
#endif
/*
********************************************************************************
* Function Name: Dem_EventCheckJ1939DtcFilterMatch
*
* Explanation: Check if match the J1939DTC filter.
*
* param: EventIdx: Event index in event configure table.
*
* retval: E_NOT_OK: not match.
*         E_OK: match.
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventCheckJ1939DtcFilterMatch
(
    uint16 EventIdx
)
{
    boolean flag = FALSE;
    uint8 ret = E_NOT_OK;
    uint16 evtIndiIdx = DEM_INIT_ZERO;

    for( evtIndiIdx = DEM_INIT_ZERO; evtIndiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; evtIndiIdx++ )
    {
        if( DEM_CFG_MILINDICATORREF == Dem_CfgEventTable[EventIdx].acIndiIdx[evtIndiIdx] )
        {
            flag = TRUE;
            break; 
        }
    }

    if( (EventIdx <= DEM_CFG_EVENT_NUM) && (EventIdx > DEM_INIT_ZERO) )
    {
        switch( DEM_GET_J1939_DTC_FILTER_MASK() )
        {
            case DEM_J1939DTC_ACTIVE:
            {
                if( ((TRUE == DEM_GET_UDS_STATUS_CDTC(EventIdx)) &&
                    (TRUE == DEM_GET_UDS_STATUS_TF(EventIdx))) ||
                    ((TRUE == DEM_GET_INDICATOR(EventIdx,evtIndiIdx)) && (TRUE == flag)) )
                {
                    ret = E_OK;
                }
                break;
            }
            case DEM_J1939DTC_PREVIOUSLY_ACTIVE:
            {
                if( (TRUE == DEM_GET_UDS_STATUS_CDTC(EventIdx)) &&
                    (TRUE != DEM_GET_UDS_STATUS_TF(EventIdx)) &&
                    ((FALSE == DEM_GET_INDICATOR(EventIdx,evtIndiIdx)) && (TRUE == flag)) )
                {
                    ret = E_OK;
                }
                break;
            }
            case DEM_J1939DTC_PENDING:
            {
                if( TRUE == DEM_GET_UDS_STATUS_PDTC(EventIdx) )
                {
                    ret = E_OK;
                }
                break;
            }
            case DEM_J1939DTC_PERMANENT:
            {
                /*Not Support*/
                ret = E_NOT_OK;
                break;
            }
            case DEM_J1939DTC_CURRENTLY_ACTIVE:
            {
                if( TRUE == DEM_GET_UDS_STATUS_TF(EventIdx) )
                {
                    ret = E_OK;
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return ret;
}

#if( DEM_CFG_J1939READINGDTCSUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Dem_EventCalcJ1939DtcNextFiltered
*
* Explanation: Calculate the next filtered J1939DTC and OccurenceCounter.
*
* param: DTC: To hole the matched J1939DTC value.
*        OccurenceCounter: To hole the OccurenceCounter value.
*
* retval: E_NOT_OK, In calculating;
*         E_OK, Calculation finished.
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventCalcJ1939DtcNextFiltered
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
)
{
    boolean flag = FALSE;
    uint8 ret = E_NOT_OK;
    uint8 occCnt = DEM_INIT_ZERO;
    uint8 node = DEM_INIT_ZERO;
    uint16 numMatchedDtcNext = DEM_INIT_ZERO;
    uint16 evtIdx = DEM_INIT_ZERO;
    uint16 dtcIdx = DEM_INIT_ZERO;
    uint16 numComEvt = DEM_INIT_ZERO;

    numMatchedDtcNext = DEM_GET_J1939_DTC_FILTER_MATCH_NEXTIDX();

    node = DEM_GET_J1939_DTC_NODE();
    for( dtcIdx = (numMatchedDtcNext + DEM_BYTE_ONE); dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++ )  /*Poll from next matching ID*/
    {
#if( DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION )
    if( FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx) )
#endif
        {
            if( node == Dem_CfgDTCTable[dtcIdx].acJ1939DtcNdId )
            {
                for( numComEvt = DEM_INIT_ZERO; numComEvt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; numComEvt++ )
                {
                    evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[numComEvt];
                    if( (DEM_INIT_ZERO != evtIdx) &&
                        (E_OK == Dem_EventCheckJ1939DtcFilterMatch(evtIdx)) )  /* PRQA S 3415 */ /* NSCA_QAC_Dem_Rule13.5 */
                    {
                        flag = TRUE;
                        break;
                    }
                }
                if( TRUE == flag )
                {
                    break;
                }
            }
        }
    }
    if( dtcIdx > DEM_CFG_DTC_NUM )
    {
        DEM_SET_J1939_DTC_FILTER_MATCH_NEXT(FALSE);
        numMatchedDtcNext = DEM_INIT_ZERO;
    }
    else
    {
        numMatchedDtcNext = dtcIdx;
        Dem_J1939EventCalcOccurenceCounter(evtIdx, &occCnt);
        *OccurenceCounter = occCnt;
        *DTC = Dem_CfgObdDTCTable[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx].awJ1939DtcVal;

        ret = E_OK;
    }

    DEM_SET_J1939_DTC_FILTER_MATCH_NEXTIDX(numMatchedDtcNext);

    return ret;
}
#endif

#if( DEM_CFG_J1939DM31SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Dem_EventCalcDM31J1939DtcNextFiltered
*
* Explanation: Calculate the next filtered J1939DTC and OccurenceCounter.
*
* param: DTC: To hole the matched J1939DTC value.
*        OccurenceCounter: To hole the OccurenceCounter value.
*        Dem_EventIdx: To hole eventIdx.
*
* retval: E_NOT_OK, In calculating;
*         E_OK, Calculation finished.
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_EventCalcDM31J1939DtcNextFiltered
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Dem_EventIdx
)
{
    boolean flag = FALSE;
    uint8 ret = E_NOT_OK;
    uint8 node = DEM_INIT_ZERO;
    uint8 occCnt = DEM_INIT_ZERO;
    uint16 numMatchedDtcNext = DEM_INIT_ZERO;
    uint16 evtIdx = DEM_INIT_ZERO;
    uint16 numComEvt = DEM_INIT_ZERO;
    uint16 dtcIdx = DEM_INIT_ZERO;

    numMatchedDtcNext = DEM_GET_DM31_FILTER_MATCH_NEXTIDX();

    node = DEM_GET_DM31_J1939_NODE();
    for( dtcIdx = (numMatchedDtcNext + DEM_BYTE_ONE); dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++ )    /*Poll from next matching ID*/
    {
#if( DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION )    /*Suppress DTC switch*/
        if( FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx) )
#endif
        {
            if( (node == Dem_CfgDTCTable[dtcIdx].acJ1939DtcNdId) &&
                ((DEM_GET_J1939_DTC_FILTER_KIND() == DEM_DTC_KIND_ALL_DTCS) ||
                 (DEM_INIT_ZERO != Dem_CfgDTCTable[dtcIdx].acObdDtcIdx)) )    /* Judge whether obd is configured */
            {
                for( numComEvt = DEM_INIT_ZERO; numComEvt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; numComEvt++ )
                {
                    evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[numComEvt];
                    
                    if( (DEM_INIT_ZERO != evtIdx) &&
                        (TRUE == DEM_GET_UDS_STATUS_TF(evtIdx)) )
                    {
                        flag = TRUE;
                        break;
                    }
                }
                if( TRUE == flag )
                {
                   break;
                }
            }
        }
    }

    if( dtcIdx > DEM_CFG_DTC_NUM )
    {
        DEM_SET_DM31_FILTER_MATCH_NEXT(FALSE);
        numMatchedDtcNext = DEM_INIT_ZERO;
    }
    else
    {
        numMatchedDtcNext = dtcIdx;
        Dem_J1939EventCalcOccurenceCounter(evtIdx, &occCnt);
        *OccurenceCounter = occCnt;
        *DTC = Dem_CfgObdDTCTable[Dem_CfgDTCTable[dtcIdx].acObdDtcIdx].awJ1939DtcVal;
        *Dem_EventIdx = evtIdx;
        ret = E_OK;
    }

    DEM_SET_DM31_FILTER_MATCH_NEXTIDX(numMatchedDtcNext);

    return ret;
}

/*
********************************************************************************
* Function Name: Dem_ReturnDM31LampStatus
*
* Explanation: The function returns the composite lamp status of the filtered DTCs.
*
* param: LampStatus: The status of lamp.
*        EventIdx: Event index in event configure table.
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ReturnDM31LampStatus
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) LampStatus,
    uint16 EventIdx
)
{
    uint8 pos = DEM_INIT_ZERO;
    uint16 evtIndiIdx = DEM_INIT_ZERO;
    uint16 onOffSts = DEM_INIT_ZERO;
    uint16 flashSts = DEM_INIT_ZERO;

    *LampStatus = DEM_LAMP_OFF;

    for( evtIndiIdx = DEM_INIT_ZERO; evtIndiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; evtIndiIdx++ )
    {
        pos = DEM_INIT_ZERO;
        onOffSts = DEM_LAMP_OFF;

        switch( Dem_CfgEventTable[EventIdx].acIndiIdx[evtIndiIdx] )
        {
            case DEM_CFG_MILINDICATORREF:
                pos = DEM_BYTE_FOURTEEN;
                break;
            case DEM_CFG_REDSTOPLAMPINDICATOR:
                pos = DEM_BYTE_TWELVE;    
                break;
            case DEM_CFG_AMBERWARNINGLAMPINDICATOR:
                pos = DEM_BYTE_TEN;
                break;
            case DEM_CFG_PROTECTLAMPINDICATOR: 
                pos = DEM_BYTE_EIGHT; 
                break;
            default:
                pos = DEM_BYTE_FOURTEEN - (evtIndiIdx * DEM_BYTE_TWO);
                break;          
        }

        if( TRUE == DEM_GET_INDICATOR(EventIdx,evtIndiIdx) )
        {
            onOffSts = DEM_LAMP_ON;

            if( DEM_INDICATOR_CONTINUOUS == Dem_CfgEvtIndiBhv[EventIdx][evtIndiIdx] )
            {
                flashSts = DEM_NO_FLASH;
            }
            else if( DEM_INDICATOR_SLOW_FLASH == Dem_CfgEvtIndiBhv[EventIdx][evtIndiIdx] )
            {
                flashSts = DEM_SLOW_FLASH;
            }
            else if( DEM_INDICATOR_FAST_FLASH == Dem_CfgEvtIndiBhv[EventIdx][evtIndiIdx] )
            {
                flashSts = DEM_FAST_FLASH;
            }
            else
            {
                onOffSts = DEM_LAMP_OFF;
                flashSts = DEM_DEFAULT_FLASH;
            }
        }
        else
        {
            onOffSts = DEM_LAMP_OFF;
            flashSts = DEM_DEFAULT_FLASH;
        }

        *LampStatus |= ( (flashSts << (pos - DEM_BYTE_EIGHT)) | (onOffSts << pos) );
    }
}
#endif

/*
********************************************************************************
* Function Name: Dem_J1939EventCalcOccurenceCounter
*
* Explanation: Calculate the occurence counter.
*
* param: EventIdx: Event index in event configuration table.
*        OccurenceCounter: Get the value of occurence counter.
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_J1939EventCalcOccurenceCounter
(
    uint16 EventIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
)
{
    uint8 evtMemCnt = DEM_INIT_ZERO;
    uint8 evtMemIdx = DEM_INIT_ZERO;
    uint8 entryIdx = DEM_INIT_ZERO;
    Dem_EventMemoryEntry_st* entry_ptr;

    if( (EventIdx > DEM_INIT_ZERO) && (EventIdx <= DEM_CFG_EVENT_NUM) )
    {
        for( evtMemCnt = DEM_INIT_ZERO; evtMemCnt < DEM_CFG_EVENT_MEMORY_NUM; evtMemCnt++ )
        {
            evtMemIdx = Dem_CfgDTCTable[Dem_CfgEvtDtcIdx[EventIdx]].acEvtMemIdx[evtMemCnt];

            if( evtMemIdx > DEM_INIT_ZERO )
            {
                if( TRUE == DEM_GET_EVENT_STORED(EventIdx, evtMemIdx) )
                {
                    entry_ptr = DEM_GET_EVENT_MEMORY_ENTRY_PTR(evtMemIdx);
                    entryIdx = DEM_GET_EVENT_ENTRY(EventIdx, evtMemIdx);

                    if( DEM_MAX_CNT < entry_ptr[entryIdx].cntOcc )
                    {
                        *OccurenceCounter = DEM_MAX_CNT;
                    }
                    else
                    {
                       *OccurenceCounter = entry_ptr[entryIdx].cntOcc;
                    }
                    break;
                }
            }
        }
    }
}

#if( DEM_CFG_J1939CLEARDTCSUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Dem_J1939DcmCheckClearFilterType
*
* Explanation: Calculate whether it is a DM03 service or a DM11 service.
*
* param: DTCTypeFilter: J1939DTC Clear mask.
*        dtcIdx: DTC Idx.
*        ClearStatus: Get Clear Status.
*
* retval: None
********************************************************************************
*/
FUNC(uint8, DEM_CODE) Dem_J1939DcmCheckClearFilterType
(
    Dem_J1939DcmSetClearFilterType DTCTypeFilter,
    uint16 dtcIdx,
    P2VAR(Dem_ReturnClearDTCType, AUTOMATIC, DEM_APPL_DATA) ClearStatus
)
{
    boolean milStatus = FALSE;
    boolean tfStatus = FALSE;
    boolean cdtcStatus = FALSE;
    uint8 ret = E_NOT_OK;
    uint16 evtIdx = DEM_INIT_ZERO;
    uint16 numComEvt = DEM_INIT_ZERO;
    uint16 evtIndiIdx = DEM_INIT_ZERO;

    for( numComEvt = DEM_INIT_ZERO; numComEvt < DEM_CFG_COMB_DTC_MAX_EVENT_NUM; numComEvt++ )
    {
        evtIdx = Dem_CfgDTCTable[dtcIdx].combEvtIdx[numComEvt];

        if( (evtIdx > DEM_INIT_ZERO) && (evtIdx <= DEM_CFG_EVENT_NUM ) )
        {
            for( evtIndiIdx = DEM_INIT_ZERO; evtIndiIdx < DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM; evtIndiIdx++ )
            {
                if( DEM_CFG_MILINDICATORREF == Dem_CfgEventTable[evtIdx].acIndiIdx[evtIndiIdx] )
                {
                    milStatus |= DEM_GET_INDICATOR(evtIdx, evtIndiIdx);
                    break;
                }
            }

            tfStatus |= DEM_GET_UDS_STATUS_TF(evtIdx);
            cdtcStatus |= DEM_GET_UDS_STATUS_CDTC(evtIdx);
        }
    }
    if( (DEM_J1939DTC_CLEAR_ALL == DTCTypeFilter) &&
        ((TRUE == tfStatus) ||
        (TRUE == milStatus)) )
    {
        ret = E_OK;
    }
    else if( (DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE == DTCTypeFilter) &&
             ((TRUE == cdtcStatus) &&
             (FALSE == tfStatus) &&
             (FALSE == milStatus)) )
    {
        ret = E_OK;
    }
    else
    {
        *ClearStatus = DEM_CLEAR_OK;
    }

    return ret;
}
#endif

#endif

#define DEM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


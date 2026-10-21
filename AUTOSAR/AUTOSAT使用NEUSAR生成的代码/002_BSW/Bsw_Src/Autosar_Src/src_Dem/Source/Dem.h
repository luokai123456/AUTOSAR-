/*
********************************************************************************
*
* File name: Dem.h
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: ZhiDX/2020.10.16
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: ZhuCY/2021.10.20
* Change: Modify component version information.
* Cause: Update.
********************************************************************************
* Version: 3.1
* Author/Date: ZhuCY/2021.10.21
* Change: Modify component version information.
* Cause: Update.
********************************************************************************
* Version: 3.2
* Author/Date: ZhuCY/2021.11.01
* Change: Modify version number to 3.3.1.
* Cause: Update.
********************************************************************************
* Version: 3.2
* Author/Date: ZhiDX/2021.11.12
* Change: Update version to 3.3.2.
* Cause: Update.
********************************************************************************
* Version: 3.3
* Author/Date: ZhiDX/2021.11.15
* Change: Implementation of event combination.
* Cause: Implementation
********************************************************************************
* Version: 3.4
* Author/Date: ZhiDX/2021.11.26
* Change: Update version to 3.3.4.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: ZhiDX/2021.12.02
* Change: Wrong spell of DEM_EVCOMB_ONSTORAGE.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: ZhuCY/2021.12.07
* Change: Update version to 3.3.5.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: ZhangDX/2021.12.23
* Change: 1.Update version to 3.3.6.
*         2.Modify the code format.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: ZhiDX/2022.01.14
* Change: Update version to 3.3.7.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: ZhiDX/2022.02.17
* Change: Update version to 3.3.8.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: ZhiDX/2022.02.18
* Change: Update version to 3.3.9.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: ZhiDX/2022.02.22
* Change: Update version to 3.3.10.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: ZhiDX/2022.02.22
* Change: Update version to 3.3.11.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: MengY/2022.06.16
* Change: Update version to 3.3.12.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: FanHT/2022.06.30
* Change: Update version to 3.3.13.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: FanHT/2022.08.19
* Change: Update version to 3.3.14.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: FanHT/2022.09.15
* Change: Update version to 3.3.15.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: FanHT/2022.11.03
* Change: Update version to 3.3.16.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: FanHT/2022.11.18
* Change: Update version to 3.3.17.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: FanHT/2022.11.18
* Change: Update version to 3.3.18.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: FanHT/2023.02.09
* Change: Update version to 3.3.19.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: FanHT/2023.02.10
* Change: Update version to 3.3.20.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: FanHT/2023.03.17
* Change: 1.Update version to 3.3.21. 
*         2.Add DEM_INT16_MAX and DEM_INT16_MIN.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: WangYS/2023.04.01
* Change: Update version to 3.3.22.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: WangYS/2023.04.03
* Change: Modify macro switch name, Update version to 3.3.23.
* Cause: Optimization
********************************************************************************
* Version: 3.24
* Author/Date: WangYS/2023.04.26
* Change: 1.Add DEM_CFG_J1939SUPPORT macro switch limit.
*         2.Add new macro.
*         3.Update version to 3.3.24.
* Cause: Optimization
********************************************************************************
* Version: 3.25
* Author/Date: WangYS/2023.05.05
* Change: 1.Macro value changes related to lamp status.
*         2.Update version to 3.3.25.
* Cause: Optimization
********************************************************************************
* Version: 3.26
* Author/Date: FanHT/2023.05.06
* Change: Update version to 3.3.26.
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date: FanHT/2023.05.11
* Change: Update version to 3.3.27.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: WangYS/2023.05.09
* Change: Update version to 3.3.28.
* Cause: Optimization
********************************************************************************
* Version: 3.29
* Author/Date: WangYS/2023.05.29
* Change: 1.update version to 3.7.0.
*         2.Adjust code according to code review.
* Cause: Optimization
********************************************************************************
* Version: 3.30
* Author/Date: FanHT/2023.06.09
* Change: Update version to 3.8.0.0.
* Cause: Update
********************************************************************************
* Version: 3.31
* Author/Date: FanHT/2023.06.09
* Change: Update version to 3.8.0.1.
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date: ZhangF/2023.08.02
* Change: Update version to 3.8.0.2.
* Cause: Update
********************************************************************************
* Version: 3.33
* Author/Date: ZhangF/2023.08.14
* Change: Fix compile warning.
* Cause: Update.
********************************************************************************
* Version: 3.34
* Author/Date: ZhangF/2023.08.25
* Change: Update version to 3.8.0.4.
* Cause: Update
********************************************************************************
* Version: 3.35
* Author/Date: ZhangF/2023.09.19
* Change: 1.Fix the event queue multitask preemption issue.
*         2.Update version to 3.9.0.5.
* Cause: Bugfix
********************************************************************************
* Version: 3.36
* Author/Date: ZhangF/2023.10.07
* Change: Add the global calibration array for Dem event calibration.
* Cause: Update
********************************************************************************
* Version: 3.37
* Author/Date: ZhangF/2023.10.09
* Change: Fix compile warning.
* Cause: Update
********************************************************************************
* Version: 3.38
* Author/Date: ZengJX/2023.10.27
* Change: Update version to 3.9.0.6.
* Cause: Update
********************************************************************************
* Version: 3.39
* Author/Date: ZengJX/2023.12.29
* Change: Update version to 3.9.0.7.
* Cause: Update
********************************************************************************
* Version: 3.40
* Author/Date: ZengJX/2024.01.11
* Change: Update version to 3.10.0.8.
* Cause: Update
********************************************************************************
* Version: 3.41
* Author/Date: ZengJX/2024.02.05
* Change: Update version to 3.10.0.9.
* Cause: Update
********************************************************************************
* Version: 3.42
* Author/Date: ZengJX/2024.03.07
* Change: Update version to 3.10.0.10.
* Cause: Update
********************************************************************************
* Version: 3.43
* Author/Date: ZengJX/2024.03.18
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.44
* Author/Date: ZengJX/2024.04.02
* Change: 1.Update version to 3.10.0.11.
*         2.Modify P2VAR member labels.
* Cause: Optimization
********************************************************************************
* Version: 3.45
* Author/Date: ZengJX/2024.04.15
* Change: 1.Update version to 3.10.0.12.
*         2.Optimize comments specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.46
* Author/Date: ZengJX/2024.05.22
* Change: 1.Modify struct member evtLampFailedCnt from array to be a
*           two-dimensional arrays.
*         2.Modify struct member cntHeal from uint8 to be an array.
* Cause: Optimization
********************************************************************************
* Version: 3.47
* Author/Date: ZengJX/2024.07.05
* Change: 1.Add macros about DEM_OPERCYCLE_QUEUE_SIZE.
*         2.Add struct Dem_ManageOperCycleQueue_st.
*         3.Add new members for struct Dem_ManageEvent_st.
*         4.Update version to 3.11.0.13.
* Cause: Optimization
********************************************************************************
* Version: 3.48
* Author/Date: ZengJX/2024.07.18
* Change: 1.Modify copyright information.
*         2.Fix Dem memmap issue.
* Cause: Optimization
********************************************************************************
* Version: 3.49
* Author/Date: ZengJX/2024.09.02
* Change: 1.Modify the value of macros about WWHOBD in order to fix the bug of 
*           DTCSeverityAvailabilityMask error.
*         2.Update version to 3.11.2.14.
* Cause: Bugfix
********************************************************************************
* Version: 3.50
* Author/Date: ZengJX/2024.09.18
* Change: 1.Add struct member lampfailcntUpdated in Dem_ManageEvent_st.
*         2.Update version to 3.11.0.15.
* Cause: Bugfix
********************************************************************************
* Version: 3.51
* Author/Date: ZengJX/2024.10.22
* Change: 1.Add macro DEM_BYTE_SIXTY_FOUR and macros about Dem value.
*         2.Update version to 3.12.0.16.
* Cause: Optimization
********************************************************************************
* Version: 3.52
* Author/Date: ZengJX/2024.10.25
* Change: Add macro about Indicator increase mode.
* Cause: Optimization
********************************************************************************
* Version: 3.53
* Author/Date: ZengJX/2024.11.04
* Change: 1.Add macro about Dem OCC7 counter.
*         2.Update version to 3.12.0.17.
* Cause: Update
********************************************************************************
* Version: 3.54
* Author/Date: ZengJX/2024.11.07
* Change: Add member variable warmUpCycleCntSinceLastInit to struct Dem_OBDManage_st.
* Cause: Bugfix
********************************************************************************
* Version: 3.55
* Author/Date: ZengJX/2024.11.14
* Change: Update version to 3.12.0.18.
* Cause: Update
********************************************************************************
* Version: 3.56
* Author/Date: ZengJX/2024.12.05
* Change: Update version to 3.12.0.19.
* Cause: Update
********************************************************************************
* Version: 3.57
* Author/Date: ZengJX/2024.12.15
* Change: Update version to 3.12.0.20.
* Cause: Update
********************************************************************************
* Version: 3.58
* Author/Date: ZengJX/2025.1.14
* Change: Update version to 3.13.0.21.
* Cause: Update
********************************************************************************
* Version: 3.59
* Author/Date: ZengJX/2025.02.07
* Change: 1.Modify copyright information.
*         2.Update version to 3.13.0.22.
* Cause: Optimization
********************************************************************************
* Version: 3.60
* Author/Date: ZengJX/2025.02.08
* Change: Add the declaration of the variable Dem_DiagProcDTCIdx.
* Cause: Optimization
********************************************************************************
* Version: 3.61
* Author/Date: ZengJX/2025.03.03
* Change: Update version to 3.13.0.23.
* Cause: Update
********************************************************************************
* Version: 3.62
* Author/Date: ZengJX/2025.03.24
* Change: 1.Update version to 3.13.0.24.
*         2.Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.63
* Author/Date: ZengJX/2025.04.03
* Change: Update version to 3.13.0.25.
* Cause: Optimization
********************************************************************************
* Version: 3.64
* Author/Date: ZengJX/2025.05.29
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.65
* Author/Date: ZengJX/2025.06.03
* Change: Update version to 3.13.0.26.
* Cause: Updata
********************************************************************************
* Version: 3.66
* Author/Date: ZengJX/2025.06.05
* Change: Add the sturct member wuCycFlagDuringlastDrvCyc in Dem_OBDManage_st.
* Cause: Bugfix
********************************************************************************
* Version: 3.67
* Author/Date: ZengJX/2025.06.16
* Change: Update version to 3.14.0.27.
* Cause: Updata
********************************************************************************
* Version: 3.68
* Author/Date: ZengJX/2025.06.23
* Change: Update version to 3.14.0.28.
* Cause: Updata
********************************************************************************
* Version: 3.69
* Author/Date: ZengJX/2025.08.01
* Change: Update version to 3.15.0.29.
* Cause: Updata
********************************************************************************
* Version: 3.70
* Author/Date: ZengJX/2025.08.20
* Change: Update version to 3.15.0.30.
* Cause: Updata
********************************************************************************
*/
#ifndef DEM_H_
#define DEM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Dem_Types.h"
#include "Dem_Cfg.h"
#include "Dem_Lcfg.h"
#include "Dem_PBcfg.h"
#include "SchM_Dem.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* critical section macros. */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define Dem_EnterCritical_0() SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_0()
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define Dem_LeaveCritical_0() SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_0()

/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Dem_2.5" */

/* Dem Module Info */
#define DEM_INSTANCE_ID                                           (0U)
#define DEM_VENDOR_ID                                             (119U)
#define DEM_MODULE_ID                                             (54U)


/* Component version information. */
#define DEM_SW_MAJOR_VERSION                                      (3U)
#define DEM_SW_MINOR_VERSION                                      (15U)
#define DEM_SW_PATCH_VERSION                                      (0U)
#define DEM_SW_REVISION_VERSION                                   (30U)

#define DEM_AR_RELEASE_MAJOR_VERSION                              (4U)
#define DEM_AR_RELEASE_MINOR_VERSION                              (2U)
#define DEM_AR_RELEASE_REVISION_VERSION                           (2U)

/* Dem Service ID definition */
#define DEM_GETVERSIONINFO_APIID                                  (0x00U)              /* Service ID: Dem_GetVersionInfo(). */
#define DEM_PREINIT_APIID                                         (0x01U)              /* Service ID: Dem_PreInit(). */
#define DEM_INIT_APIID                                            (0x02U)              /* Service ID: Dem_Init(). */
#define DEM_SHUTDOWN_APIID                                        (0x03U)              /* Service ID: Dem_Shutdown(). */
#define DEM_REPORTERRORSTATUS_APIID                               (0x0fU)              /* Service ID: Dem_ReportErrorStatus(). */
#define DEM_SETEVENTAVAILABLE_APIID                               (0x37U)              /* Service ID: Dem_SetEventAvailable(). */
#define DEM_SETEVENTSTATUS_APIID                                  (0x04U)              /* Service ID: Dem_SetEventStatus(). */
#define DEM_RESETEVENTDEBOUNCESTATUS_APIID                        (0x09U)              /* Service ID: Dem_ResetEventDebounceStatus(). */
#define DEM_RESETEVENTSTATUS_APIID                                (0x05U)              /* Service ID: Dem_ResetEventStatus(). */
#define DEM_PRESTOREFREEZEFRAME_APIID                             (0x06U)              /* Service ID: Dem_PrestoreFreezeFrame(). */
#define DEM_CLEARPRESTOREDFREEZEFRAME_APIID                       (0x07U)              /* Service ID: Dem_ClearPrestoredFreezeFrame(). */
#define DEM_SETOPERATIONCYCLESTATE_APIID                          (0x08U)              /* Service ID: Dem_SetOperationCycleState */
#define DEM_GETOPERATIONCYCLESTATE_APIID                          (0x9eU)              /* Service ID: Dem_GetOperationCycleState */
#define DEM_SETAGINGCYCLESTATE_APIID                              (0x11U)              /* Service ID: Dem_SetAgingCycleState */
#define DEM_SETWIRSTATUS_APIID                                    (0x7aU)              /* Service ID: Dem_SetWIRStatus */
#define DEM_GETCOMPONENTFAILED_APIID                              (0x2aU)              /* Service ID: Dem_GetComponentFailed */
#define DEM_GETEVENTSTATUS_APIID                                  (0x0aU)              /* Service ID: Dem_GetEventStatus */
#define DEM_GETEVENTFAILED_APIID                                  (0x0bU)              /* Service ID: Dem_GetEventFailed */
#define DEM_GETEVENTTESTED_APIID                                  (0x0cU)              /* Service ID: Dem_GetEventTested */
#define DEM_GETDEBOUNCINGOFEVENT_APIID                            (0x9fU)              /* Service ID: Dem_GetDebouncingOfEvent */
#define DEM_GETDTCOFEVENT_APIID                                   (0x0dU)              /* Service ID: Dem_GetDTCOfEvent */
#define DEM_SETENABLECONDITION_APIID                              (0x39U)              /* Service ID: Dem_SetEnableCondition */
#define DEM_SETSTORAGECONDITION_APIID                             (0x38U)              /* Service ID: Dem_SetStorageCondition */
#define DEM_GETFAULTDETECTIONCOUNTER_APIID                        (0x3eU)              /* Service ID: Dem_GetFaultDetectionCounter */
#define DEM_GETINDICATORSTATUS_APIID                              (0x29U)              /* Service ID: Dem_GetIndicatorStatus */
#define DEM_DCMGETEVENTFREEZEFRAMEDATAEX                          (0x6eU)              /* Service ID: Dem_GetEventFreezeFrameDataEx */
#define DEM_DCMGETEVENTEXTENDDATARECORDEX                         (0x6dU)              /* Service ID: Dem_GetEventExtendedDataRecordEx */
#define DEM_GETEVENTMEMORYOVERFLOW_APIID                          (0x32U)              /* Service ID: Dem_GetEventMemoryOverflow */
#define DEM_GETNUMBEROFEVENTMEMORYENTRIES_APIID                   (0x35U)              /* Service ID: Dem_GetNumberOfEventMemoryEntries */
#define DEM_SETCOMPONENTAVAILABLE_APIID                           (0x2bU)              /* Service ID: Dem_SetComponentAvailable */
#define DEM_SETDTCSUPPRESSION_APIID                               (0x33U)              /* Service ID: Dem_SetDTCSuppression */
#define DEM_CLEARDTC_APIID                                        (0x23U)              /* Service ID: Dem_ClearDTC */
#define DEM_DCMGETTRANSLATIONTYPE_APIID                           (0x3cU)              /* Service ID: Dem_DcmGetTranslationType */
#define DEM_DCMGETDTCSTATUSAVAILABILITYMASK_APIID                 (0x16U)              /* Service ID: Dem_DcmGetDTCStatusAvailabilityMask */
#define DEM_DCMGETSTATUSOFDTC_APIID                               (0x15U)              /* Service ID: Dem_DcmGetStatusOfDTC */
#define DEM_DCMGETSEVERITYOFDTC_APIID                             (0x0eU)              /* Service ID: Dem_DcmGetSeverityOfDTC */
#define DEM_DCMGETFUNCTIONALUNITOFDTC_APIID                       (0x34U)              /* Service ID: Dem_DcmGetFunctionalUnitOfDTC */
#define DEM_DCMSETDTCFILTER_APIID                                 (0x13U)              /* Service ID: Dem_DcmSetDTCFilter */
#define DEM_DCMGETNUMBEROFFILTEREDDTC_APIID                       (0x17U)              /* Service ID: Dem_DcmGetNumberOfFilteredDTC */
#define DEM_DCMGETNEXTFILTEREDDTC_APIID                           (0x18U)              /* Service ID: Dem_DcmGetNextFilteredDTC */
#define DEM_DCMGETNEXTFILTEREDDTCANDFDC_APIID                     (0x3bU)              /* Service ID: Dem_DcmGetNextFilteredDTCAndFDC */
#define DEM_DCMGETNEXTFILTEREDDTCANDSEVERITY_APIID                (0x3dU)              /* Service ID: Dem_DcmGetNextFilteredDTCAndSeverity */
#define DEM_DCMSETFREEZEFRAMERECORDFILTER_APIID                   (0x3fU)              /* Service ID: Dem_DcmSetFreezeFrameRecordFilter */
#define DEM_DCMGETNEXTFILTEREDRECORD_APIID                        (0x3aU)              /* Service ID: Dem_DcmGetNextFilteredRecord */
#define DEM_DCMGETDTCBYOCCURRENCETIME_APIID                       (0x19U)              /* Service ID: Dem_DcmGetDTCByOccurrenceTime */
#define DEM_DCMCONTROLDTCSTATUSCHANGEDNOTIFICATION_APIID          (0xb0U)              /* Service ID: Dem_DcmControlDTCStatusChangedNotification */
#define DEM_DCMDISABLEDTCRECORDUPDATE_APIID                       (0x1aU)              /* Service ID: Dem_DcmDisableDTCRecordUpdate */
#define DEM_DCMENABLEDTCRECORDUPDATE_APIID                        (0x1bU)              /* Service ID: Dem_DcmEnableDTCRecordUpdate */
#define DEM_DCMGETFREEZEFRAMEDATABYDTC_APIID                      (0x1dU)              /* Service ID: Dem_DcmGetFreezeFrameDataByDTC */
#define DEM_DCMGETSIZEOFFREEZEFRAMEBYDTC_APIID                    (0x1fU)              /* Service ID: Dem_DcmGetSizeOfFreezeFrameByDTC */
#define DEM_DCMGETEXTENDEDDATARECORDBYDTC_APIID                   (0x20U)              /* Service ID: Dem_DcmGetExtendedDataRecordByDTC */
#define DEM_DCMGETSIZEOFEXTENDEDDATARECORDBYDTC_APIID             (0x21U)              /* Service ID: Dem_DcmGetSizeOfExtendedDataRecordByDTC */
#define DEM_DCMCHECKCLEARPAAMETER                                 (0x7bU)              /* Service ID: Dem_DcmCheckClearParameter */
#define DEM_DCMCLEARDTC_APIID                                     (0x22U)              /* Service ID: Dem_DcmClearDTC */
#define DEM_DCMDISABLEDTCSETTING_APIID                            (0x24U)              /* Service ID: Dem_DcmDisableDTCSetting */
#define DEM_DCMENABLEDTCSETTING_APIID                             (0x25U)              /* Service ID: Dem_DcmEnableDTCSetting */
#define DEM_DCMGETINFOTYPEVALUE08_APIID                           (0x6bU)              /* Service ID: Dem_DcmGetInfoTypeValue08 */
#define DEM_DCMGETINFOTYPEVALUE0B_APIID                           (0x6cU)              /* Service ID: Dem_DcmGetInfoTypeValue0B */
#define DEM_DCMREADDATAOFPID01_APIID                              (0x61U)              /* Service ID: Dem_DcmReadDataOfPID01 */
#define DEM_DCMREADDATAOFPID1C_APIID                              (0x63U)              /* Service ID: Dem_DcmReadDataOfPID1C */
#define DEM_DCMREADDATAOFPID21_APIID                              (0x64U)              /* Service ID: Dem_DcmReadDataOfPID21 */
#define DEM_DCMREADDATAOFPID30_APIID                              (0x65U)              /* Service ID: Dem_DcmReadDataOfPID30 */
#define DEM_DCMREADDATAOFPID31_APIID                              (0x66U)              /* Service ID: Dem_DcmReadDataOfPID31 */
#define DEM_DCMREADDATAOFPID41_APIID                              (0x67U)              /* Service ID: Dem_DcmReadDataOfPID41 */
#define DEM_DCMREADDATAOFPID4D_APIID                              (0x68U)              /* Service ID: Dem_DcmReadDataOfPID4D */
#define DEM_DCMREADDATAOFPID4E_APIID                              (0x69U)              /* Service ID: Dem_DcmReadDataOfPID4E */
#define DEM_DCMREADDATAOFPID91_APIID                              (0x6aU)              /* Service ID: Dem_DcmReadDataOfPID91 */
#define DEM_DCMREADDATAOFOBDFREEZEFRAME_APIID                     (0x52U)              /* Service ID: Dem_DcmReadDataOfOBDFreezeFrame */
#define DEM_DCMGETDTCOFOBDFREEZEFRAME_APIID                       (0x53U)              /* Service ID: Dem_DcmGetDTCOfOBDFreezeFrame */
#define DEM_DCMGETAVAILABLEOBDMIDS_APIID                          (0xa3U)              /* Service ID: Dem_DcmGetAvailableOBDMIDs */
#define DEM_DCMGETNUMTIDSOFOBDMID_APIID                           (0xa4U)              /* Service ID: Dem_DcmGetNumTIDsOfOBDMID */
#define DEM_DCMGETDTRDATA_APIID                                   (0xa5U)              /* Service ID: Dem_DcmGetDTRData */
#define DEM_DLTGETMOSTRECENTFREEZEFRAMERECORDDATA_APIID           (0x41U)              /* Service ID: Dem_DltGetMostRecentFreezeFrameRecordData */
#define DEM_DLTGETALLEXTENDEDDATARECORD_APIID                     (0x40U)              /* Service ID: Dem_DltGetAllExtendedDataRecords */
#define DEM_SETEVENTDISABLED_APIID                                (0x51U)              /* Service ID: Dem_SetEventDisabled */
#define DEM_REPIUMPRFAULTDETECT_APIID                             (0x73U)              /* Service ID: Dem_RepIUMPRFaultDetect */
#define DEM_SETIUMPRDENCONDITION_APIID                            (0xaeU)              /* Service ID: Dem_SetIUMPRDenCondition */
#define DEM_GETIUMPRDENCONDITION_APIID                            (0xafU)              /* Service ID: Dem_GetIUMPRDenCondition */
#define DEM_REPIUMPRDENLOCK_APIID                                 (0x71U)              /* Service ID: Dem_RepIUMPRDenLock */
#define DEM_REPIUMPRDENRELEASE_APIID                              (0x72U)              /* Service ID: Dem_RepIUMPRDenRelease */
#define DEM_SETPTOSTATUS_APIID                                    (0x79U)              /* Service ID: Dem_SetPtoStatus */
#define DEM_J1939DCMSETDTCFILTER_APIID                            (0x90U)              /* Service ID: Dem_J1939DcmSetDTCFilter */
#define DEM_J1939DCMGETNUMBEROFFILTEREDDTC_APIID                  (0x91U)              /* Service ID: Dem_J1939DcmGetNumberOfFilteredDTC*/
#define DEM_J1939DCMGETNEXTFILTEREDDTC_APIID                      (0x92U)              /* Service ID: Dem_J1939DcmGetNextFilteredDTC*/
#define DEM_J1939DCMFIRSTDTCWITHLAMPSTATUS_APIID                  (0x93U)              /* Service ID: Dem_J1939DcmFirstDTCwithLampStatus*/
#define DEM_J1939DCMGETNEXTDTCWITHLAMPSTATUS_APIID                (0x94U)              /* Service ID: Dem_J1939DcmgetNextDTCwithLampStatus*/
#define DEM_J1939DCMCLEARDTC_APIID                                (0x95U)              /* Service ID: Dem_J1939DcmClearDTC*/
#define DEM_J1939DCMSETFREEZEFRAMEFILTER_APIID                    (0x96U)              /* Service ID: Dem_J1939DcmSetFreezeFrameFilter */
#define DEM_J1939DCMGETNEXTFREEZEFRAME_APIID                      (0x97U)              /* Service ID: Dem_J1939DcmGetNextFreezeFrame */
#define DEM_J1939DCMGETNEXTSPNINFREEZEFRAME_APIID                 (0x98U)              /* Service ID: Dem_J1939DcmGetNextSPNInFreezeFrame */
#define DEM_J1939DCMSETRATIOFILTER_APIID                          (0x99U)              /* Service ID: Dem_J1939DcmSetRatioFilter */
#define DEM_J1939DCMGETNEXTFILTEREDRATIO_APIID                    (0x9aU)              /* Service ID: Dem_J1939DcmGetNextFilteredRatio*/
#define DEM_J1939DCMREADDIAGNOSTICREADINESS1_APIID                (0x9bU)              /* Service ID: Dem_J1939DcmReadDiagnosticReadiness1*/
#define DEM_J1939DCMREADDIAGNOSTICREADINESS2_APIID                (0x9cU)              /* Service ID: Dem_J1939DcmReadDiagnosticReadiness2*/
#define DEM_J1939DCMREADDIAGNOSTICREADINESS3_APIID                (0x9dU)              /* Service ID: Dem_J1939DcmReadDiagnosticReadiness3*/
#define DEM_READDATAOFPID01_APIID                                 (0xb3U)              /* Service ID: Dem_ReadDataOfPID01 */
#define DEM_GETDATAOFPID21_APIID                                  (0xb1U)              /* Service ID: Dem_GetDataOfPID21 */
#define DEM_SETDATAOFPID21_APIID                                  (0xa6U)              /* Service ID: Dem_SetDataOfPID21 */
#define DEM_SETDATAOFPID31_APIID                                  (0xa7U)              /* Service ID: Dem_SetDataOfPID31 */
#define DEM_SETDATAOFPID4D_APIID                                  (0xa8U)              /* Service ID: Dem_SetDataOfPID4D */
#define DEM_SETDATAOFPID4E_APIID                                  (0xa9U)              /* Service ID: Dem_SetDataOfPID4E */
#define DEM_SETPFCCYCLEQUALIFIED_APIID                            (0xaaU)              /* Service ID: Dem_SetPfcCycleQualified */
#define DEM_GETPFCCYCLEQUALIFIED_APIID                            (0xabU)              /* Service ID: Dem_GetPfcCycleQualified */
#define DEM_SETCLEARDTC_APIID                                     (0xacU)              /* Service ID: Dem_SetClearDTC */
#define DEM_DCMGETDTCSEVERITYAVAILABILITYMASK_APIID               (0xb2U)              /* Service ID: Dem_DcmGetDTCSeverityAvailabilityMask */
#define DEM_GETB1COUNTER_APIID                                    (0xb4U)              /* Service ID: Dem_GetB1Counter */
#define DEM_SETDTR_APIID                                          (0xa2U)              /* Service ID: Dem_SetDTR */
#define DEM_DCMREADDATAOFPID02_APIID                              (0xc0U)              /* Service ID: Dem_DcmReadDataOfPID02 */
#define DEM_DCMREADDATAOFPID04_APIID                              (0xc1U)              /* Service ID: Dem_DcmReadDataOfPID04 */
#define DEM_DCMREADDATAOFPID05_APIID                              (0xc2U)              /* Service ID: Dem_DcmReadDataOfPID05 */
#define DEM_DCMREADDATAOFPID0C_APIID                              (0xc3U)              /* Service ID: Dem_DcmReadDataOfPID0C */
#define DEM_DCMREADDATAOFPID0D_APIID                              (0xc4U)              /* Service ID: Dem_DcmReadDataOfPID0D */
#define DEM_DCMREADDATAOFPID29_APIID                              (0xc5U)              /* Service ID: Dem_DcmReadDataOfPID29 */
#define DEM_DCMREADDATAOFPID42_APIID                              (0xc6U)              /* Service ID: Dem_DcmReadDataOfPID42 */
#define DEM_DCMREADDATAOFPID46_APIID                              (0xc7U)              /* Service ID: Dem_DcmReadDataOfPID46 */
#define DEM_DCMREADDATAOFPID49_APIID                              (0xc8U)              /* Service ID: Dem_DcmReadDataOfPID49 */
#define DEM_SETDATAOFPID04_APIID                                  (0xe0U)              /* Service ID: Dem_SetDataOfPID04 */
#define DEM_SETDATAOFPID29_APIID                                  (0xe1U)              /* Service ID: Dem_SetDataOfPID29 */
#define DEM_SETDATAOFPID42_APIID                                  (0xe2U)              /* Service ID: Dem_SetDataOfPID42 */

/* Error Codes for Det and port interfaces. */
#define DEM_E_NO_ERROR                                            (0x00U)              /* This value is never returned as error code. */
#define DEM_E_NO_DTC_AVAILABLE                                    (0x02U)              /* there is no DTC configured in the requested format. */
#define DEM_E_NO_FDC_AVAILABLE                                    (0x03U)              /* there is no fault detection counter available for the requested event. */
#define DEM_E_WRONG_CONFIGURATION                                 (0x10U)              /* API called with a parameter value which is not allowed in this configuration. */
#define DEM_E_PARAM_POINTER                                       (0x11U)              /* API called with a NULL pointer where NULL pointer is not allowed. */
#define DEM_E_PARAM_DATA                                          (0x12U)              /* API called with an invalid parameter value, e.g. outside the valid range. */
#define DEM_E_PARAM_LENGTH                                        (0x13U)              /* API called with an invalid length or size parameter. */
#define DEM_E_INIT_FAILED                                         (0x14U)              /* Dem initialisation failed. */
#define DEM_E_WRONG_BUFFERSIZE                                    (0x15U)              /* Dem called with an Wrong buffer size. */
#define DEM_E_UNINIT                                              (0x20U)              /* API called in uninitialized state. */
#define DEM_E_NODATAAVAILABLE                                     (0x30U)              /* Data collection failed while storing a DTC. */
#define DEM_E_WRONG_RECORDNUMBER                                  (0x31U)              /* API called with an unsupported record number. */
#define DEM_E_WRONG_DIDNUMBER                                     (0x32U)              /* API called with unsupported data identifier. */
#define DEM_E_WRONG_CONDITION                                     (0x40U)              /* API called with unsatisfied precondition (other than initialization). */

/* Dem Local Variable Init Macro. */
#define DEM_INIT_ZERO                                             (0U)
#define DEM_INIT_ONE                                              (1U)
#define DEM_INIT_FFRAMEREL_PROCESS                                (0U)
#define DEM_INIT_EXTENDDATAREL_PROCESS                            (0U)
#define DEM_INIT_DTC_VALUE                                        (0x00000000U)
#define DEM_INIT_DTCGROUP_VALUE                                   (0x00000000U)
#define DEM_INIT_UINT32                                           (0x00000000U)
#define DEM_INIT_UINT16                                           (0x0000U)
#define DEM_INIT_UINT8                                            (0x00U)
#define DEM_BYTE_ZERO                                             (0U)
#define DEM_BYTE_ONE                                              (1U)
#define DEM_BYTE_TWO                                              (2U)
#define DEM_BYTE_THREE                                            (3U)
#define DEM_BYTE_FOUR                                             (4U)
#define DEM_BYTE_FIVE                                             (5U)
#define DEM_BYTE_SIX                                              (6U)
#define DEM_BYTE_SEVEN                                            (7U)
#define DEM_BYTE_EIGHT                                            (8U)
#define DEM_BYTE_NINE                                             (9U)
#define DEM_BYTE_TEN                                              (10U)
#define DEM_BYTE_ELEVEN                                           (11U)
#define DEM_BYTE_TWELVE                                           (12U)
#define DEM_BYTE_THIRTEEN                                         (13U)
#define DEM_BYTE_FOURTEEN                                         (14U)
#define DEM_BYTE_FIFTEEN                                          (15U)
#define DEM_BYTE_SIXTEEN                                          (16U)
#define DEM_BYTE_SEVENTEEN                                        (17U)
#define DEM_BYTE_EIGHTEEN                                         (18U)
#define DEM_BYTE_NINETEEN                                         (19U)
#define DEM_BYTE_TWENTY                                           (20U)
#define DEM_BYTE_TWENTY_ONE                                       (21U)
#define DEM_BYTE_TWENTY_TWO                                       (22U)
#define DEM_BYTE_TWENTY_THREE                                     (23U)
#define DEM_BYTE_TWENTY_FOUR                                      (24U)
#define DEM_BYTE_TWENTY_FIVE                                      (25U)
#define DEM_BYTE_TWENTY_SIX                                       (26U)
#define DEM_BYTE_TWENTY_SEVEN                                     (27U)
#define DEM_BYTE_TWENTY_EIGHT                                     (28U)
#define DEM_BYTE_TWENTY_NINE                                      (29U)
#define DEM_BYTE_THIRTY                                           (30U)
#define DEM_BYTE_THIRTY_ONE                                       (31U)
#define DEM_BYTE_THIRTY_TWO                                       (32U)
#define DEM_BYTE_THIRTY_THREE                                     (33U)
#define DEM_BYTE_THIRTY_FOUR                                      (34U)
#define DEM_BYTE_THIRTY_FIVE                                      (35U)
#define DEM_BYTE_THIRTY_SIX                                       (36U)
#define DEM_BYTE_THIRTY_SEVEN                                     (37U)
#define DEM_BYTE_THIRTY_EIGHT                                     (38U)
#define DEM_BYTE_THIRTY_NINE                                      (39U)
#define DEM_BYTE_FORTY                                            (40U)
#define DEM_BYTE_FORTY_ONE                                        (41U)
#define DEM_BYTE_FORTY_TWO                                        (42U)
#define DEM_BYTE_FORTY_THREE                                      (43U)
#define DEM_BYTE_FORTY_FOUR                                       (44U)
#define DEM_BYTE_FORTY_FIVE                                       (45U)
#define DEM_BYTE_FORTY_SIX                                        (46U)
#define DEM_BYTE_FORTY_SEVEN                                      (47U)
#define DEM_BYTE_FORTY_EIGHT                                      (48U)
#define DEM_BYTE_FORTY_NINE                                       (49U)
#define DEM_BYTE_FIFTY                                            (50U)
#define DEM_BYTE_SIXTY                                            (60U)
#define DEM_BYTE_SIXTY_FOUR                                       (64U)
#define DEM_BYTE_ONE_HUNDRED_NINTY                                (190U)
#define DEM_BYTE_TWO_HUNDRED                                      (200U)
#define DEM_BYTE_MIN                                              (0x00U)
#define DEM_BYTE_MAX                                              (0xFFU)
#define DEM_BYTE_HALF                                             (0x7FU)
#define DEM_BYTE_MASK_BIT0                                        (0x01U)
#define DEM_BYTE_MASK_BIT1                                        (0x02U)
#define DEM_BYTE_MASK_BIT2                                        (0x04U)
#define DEM_BYTE_MASK_BIT3                                        (0x08U)
#define DEM_BYTE_MASK_BIT4                                        (0x10U)
#define DEM_BYTE_MASK_BIT5                                        (0x20U)
#define DEM_BYTE_MASK_BIT6                                        (0x40U)
#define DEM_BYTE_MASK_BIT7                                        (0x80U)
#define DEM_BYTE_HIGH                                             (0xF0U)
#define DEM_BYTE_LOW                                              (0x0FU)
#define DEM_WORD_MAX                                              (0xFFFFU)
#define DEM_WORD_HIGH_BYTE                                        (0xFF00U)
#define DEM_WORD_LOW_BYTE                                         (0x00FFU)
#define DEM_INT16_MAX                                             (32767U)
#define DEM_INT16_MIN                                             (-32768)

/* Dem value. */
#define DEM_VALUE_ZERO                                            (0U)
#define DEM_VALUE_ONE                                             (1U)
#define DEM_VALUE_TWO                                             (2U)
#define DEM_VALUE_THREE                                           (3U)
#define DEM_VALUE_FOUR                                            (4U)

/* Dem index value. */
#define DEM_INDEX_ZERO                                            (0U)
#define DEM_INDEX_ONE                                             (1U)

#define DEM_J1939DTC_CLEAR_MASK_INIT_VALUE                        (0x03U)
#define DEM_MAX_J1939_FILTER_TYPE                                 (0x04U)
#define DEM_DEF_J1939DTC                                          (0U)
#define DEM_MAX_CNT                                               (0x7FU)
#define DEM_MAX_NODE_NUM                                          (255U)
/*Dem Indictor Status*/
#define DEM_LAMP_INIT                                             (0x0000U)
#define DEM_LAMP_WIR_ON                                           (0x5500U)
#define DEM_LAMP_ALL_OFF                                          (0x00FFU)
#define DEM_LAMP_OFF                                              (0x00U)
#define DEM_LAMP_ON                                               (0x01U)
#define DEM_NO_FLASH                                              (0x03U)
#define DEM_SLOW_FLASH                                            (0x00U)
#define DEM_FAST_FLASH                                            (0x01U)
#define DEM_RESERVED_FLASH                                        (0x10U)
#define DEM_DEFAULT_FLASH                                         (0x03U)
/* Dem Module State */
#define DEM_MODULE_STATE_UNINIT                                   (0U)
#define DEM_MODULE_STATE_PREINIT                                  (1U)
#define DEM_MODULE_STATE_INITED                                   (2U)
#define DEM_MODULE_STATE_SHUTDOWN                                 (3U)

/* Event Kind Type */
#define DEM_EVENT_KIND_NONE                                       (0U)
#define DEM_EVENT_KIND_BSW                                        (1U)
#define DEM_EVENT_KIND_SWC                                        (2U)

/* Report behavior */
#define REPORT_BEFORE_INIT                                        (0U)
#define REPORT_AFTER_INIT                                         (1U)

/* Debounce Algorithm Class */
#define DEM_DEBOUNCE_NONE                                         (0U)
#define DEM_DEBOUNCE_COUNTER_BASED                                (1U)
#define DEM_DEBOUNCE_TIMER_BASED                                  (2U)
#define DEM_DEBOUNCE_MONITOR_INTERNAL                             (3U)
/* Debounce Behavior */
#define DEM_DEBOUNCE_FREEZE                                       (0U)
#define DEM_DEBOUNCE_RESET                                        (1U)

/* Event Memory type */
#define DEM_EVENT_MEMORY_NONE                                     (0U)
#define DEM_EVENT_MEMORY_PRIMARY                                  (1U)
#define DEM_EVENT_MEMORY_USER                                     (2U)
#define DEM_EVENT_MEMORY_NUM                                      (2U)

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
#define DEM_CFG_BIG_ENDIAN                          (STD_OFF)                               /* Little endian. */
#else
#define DEM_CFG_BIG_ENDIAN                          (STD_ON)                                /* Big endian. */
#endif

/***** For Dem General Configurations *****/
/* DemAgingCycleCounterProcessing */
#define    DEM_PROCESS_AGINGCTR_NONE                (0U)    /* no aging process. */
#define    DEM_PROCESS_AGINGCTR_EXTERN              (1U)    /* based on API Dem_SetAgingCycleCounterValue. */
#define    DEM_PROCESS_AGINGCTR_INTERN              (2U)    /* based on reported cycle states. */

/* DemAvailabilitySupport */
#define    DEM_NO_AVAILABILITY                      (0U)
#define    DEM_EVENT_AVAILABILITY                   (1U)

/* DemClearDTCBehavior */
#define    DEM_CLRRESP_VOLATILE                     (0U)    /* Return DEM_CLEAR_OK after volatile event memory data cleared. */
#define    DEM_CLRRESP_NONVOLATILE_FINISH           (1U)    /* Return DEM_CLEAR_OK after volatileand non-volatile event memory data cleared. */
#define    DEM_CLRRESP_NONVOLATILE_TRIGGER          (2U)    /* Return DEM_CLEAR_OK after volatile event memory data cleared and non-volatile event memory clearing is triggered. */

/* DemClearDTCLimitation */
#define    DEM_ALL_SUPPORTED_DTCS                   (0U)
#define    DEM_ONLY_CLEAR_ALL_DTCS                  (1U)

/* DemDataElementDefaultEndianness */
#define    DEM_EXDATA_BIG_ENDIAN                    (0U)
#define    DEM_EXDATA_LITTLE_ENDIAN                 (1U)
#define    DEM_EXDATA_OPAQUE                        (2U)

/* DemEnvironmentDataCapture */
#define    DEM_CAPTURE_ASYNCHRONOUS_TO_REPORTING    (0U)
#define    DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING     (1U)

/* DemEventCombinationSupport [ECUC_Dem_00740] */
#define    DEM_EVCOMB_DISABLED                      (0U)
#define    DEM_EVCOMB_ONRETRIEVAL                   (1U)
#define    DEM_EVCOMB_ONSTORAGE                     (2U)

/* DemEventDisplacementStrategy */
#define    DEM_DISPLACEMENT_FULL                    (0U)    /* Event memory entry displacement isenabled, by consideration of priority active/passive status, and occurrence. */
#define    DEM_DISPLACEMENT_NONE                    (1U)    /* Event memory entry displacement is disabled. */
#define    DEM_DISPLACEMENT_PRIO_OCC                (2U)    /* Event memory entry displacement isenabled, by consideration of priority and occurrence (but without active/passive status). */

/* DemOBDSupport */
#define    DEM_OBD_NO_OBD_SUPPORT                   (0U)    /* OBD is not supported within this ECU. */
#define    DEM_OBD_DEP_SEC_ECU                      (1U)    /* Kind of OBD ECU: OBD Dependend / Secondary ECU. */
#define    DEM_OBD_PRIMARY_ECU                      (2U)    /* Kind of OBD ECU: Pimary ECU. */
#define    DEM_OBD_MASTER_ECU                       (3U)    /* Kind of OBD ECU: Master ECU. */

/* DemOccurrenceCounterProcessing */
#define    DEM_PROCESS_OCCCTR_CDTC                  (0U)    /* the occurrence counter is triggered by the TestFailed bit if the fault confirmation was successful(ConfirmedDTC bit is set). */
#define    DEM_PROCESS_OCCCTR_TF                    (1U)    /* the occurrence counter is only triggered by the TestFailed bit (and the fault confirmation is not considered) This parameter is mandatory in case of J1939. */

/* DemStatusBitHandlingTestFailedSinceLastClear */
#define    DEM_STATUS_BIT_AGING_AND_DISPLACEMENT    (0U)    /* statusbits are reset to 0, if aging or displacement applies. */
#define    DEM_STATUS_BIT_NORMAL                    (1U)    /* aging and displacement has no impacton the "TestFailedSinceLastClear". */

/* DemSuppressionSupport */
#define    DEM_DTC_SUPPRESSION                      (0U)    /* Support suppression by DTC. */
#define    DEM_NO_SUPPRESSION                       (1U)    /* Suppression is not supported. */

/* DemTypeOfFreezeFrameRecordNumeration [ECUC_Dem_00778] */
#define    DEM_FF_RECNUM_CONFIGURED                 (0U)    /* Freeze frame records will be numbered based on the given configuration in their chronological order. */
#define    DEM_FF_RECNUM_CALCULATED                 (1U)    /* Freeze frame records will be numbered consecutive starting by 1 in their chronological order. */

/***** End for Dem General Configurations *****/
/* DemWWHOBDDTCClass */
#define DEM_DTC_WWHOBD_CLASS_NOCLASS                (1U)
#define DEM_DTC_WWHOBD_CLASS_A                      (2U)
#define DEM_DTC_WWHOBD_CLASS_B1                     (4U)
#define DEM_DTC_WWHOBD_CLASS_B2                     (8U)
#define DEM_DTC_WWHOBD_CLASS_C                      (16U)
/* DemDTCSignificance */
#define DEM_EVENT_SIGNIFICANCE_OCCURRENCE           (0U)
#define DEM_EVENT_SIGNIFICANCE_FAULT                (1U)
/* DemClearEventAllowedBehavior */
#define DEM_NO_STATUS_BYTE_CHANGE                   (0U)
#define DEM_ONLY_THIS_CYCLE_AND_READINESS           (1U)
/* DemEventOBDReadinessGroup */
#define DEM_OBD_RDY_NONE                            (0U)
#define DEM_OBD_RDY_AC                              (1U)
#define DEM_OBD_RDY_BOOSTPR                         (2U)
#define DEM_OBD_RDY_CAT                             (3U)
#define DEM_OBD_RDY_CMPRCMPT                        (4U)
#define DEM_OBD_RDY_EGSENS                          (5U)
#define DEM_OBD_RDY_ERG                             (6U)
#define DEM_OBD_RDY_EVAP                            (7U)
#define DEM_OBD_RDY_FLSYS                           (8U)
#define DEM_OBD_RDY_FLSYS_NONCONT                   (9U)
#define DEM_OBD_RDY_HCCAT                           (10U)
#define DEM_OBD_RDY_HTCAT                           (11U)
#define DEM_OBD_RDY_MISF                            (12U)
#define DEM_OBD_RDY_NOXCAT                          (13U)
#define DEM_OBD_RDY_O2SENS                          (14U)
#define DEM_OBD_RDY_O2SENSHT                        (15U)
#define DEM_OBD_RDY_PMFLT                           (16U)
#define DEM_OBD_RDY_SECAIR                          (17U)
/* DemDataElementClasss */
#define DEM_DATA_EMEMENT_TYPE_NONE                  (0U)
#define DEM_DATA_EMEMENT_TYPE_INTERNAL              (1U)
#define DEM_DATA_EMEMENT_TYPE_EXTERNALCS            (2U)
#define DEM_DATA_EMEMENT_TYPE_EXTERNALSR            (3U)
/* DemInternalDataElement */
#define DEM_INTERNAL_DATA_ELEMENT_NONE              (0U)
#define DEM_AGINGCTR_DOWNCNT                        (1U)
#define DEM_AGINGCTR_UPCNT                          (2U)
#define DEM_CURRENT_FDC                             (3U)
#define DEM_CYCLES_SINCE_FIRST_FAILED               (4U)
#define DEM_CYCLES_SINCE_LAST_FAILED                (5U)
#define DEM_FAILED_CYCLES                           (6U)
#define DEM_MAX_FDC_DURING_CURRENT_CYCLE            (7U)
#define DEM_MAX_FDC_SINCE_LAST_CLEAR                (8U)
#define DEM_OCCCTR                                  (9U)
#define DEM_OVFLIND                                 (10U)
#define DEM_SIGNIFICANCE                            (11U)
#define DEM_DTCSTATUSINDICATOR                      (12U)
#define DEM_OCC1                                    (13U)
#define DEM_OCC2                                    (14U)
#define DEM_OCC3                                    (15U)
#define DEM_OCC4                                    (16U)
#define DEM_OCC5                                    (17U)
#define DEM_OCC6                                    (18U)
#define DEM_OCC7                                    (19U)
#define DEM_AGEDCTR                                 (20U)
#define DEM_AGINGCTR_UPCNT2                         (21U)
#define DEM_OCCCTR2                                 (22U)
#define DEM_AGEDCTR2                                (23U)

/* DemExtendedDataRecordTrigger */
#define DEM_TRIGGER_ON_NONE                         (0x00U)
#define DEM_TRIGGER_ON_CONFIRMED                    (0x01U)
#define DEM_TRIGGER_ON_FDC_THRESHOLD                (0x02U)
#define DEM_TRIGGER_ON_MIRROR                       (0x04U)
#define DEM_TRIGGER_ON_PASSED                       (0x08U)
#define DEM_TRIGGER_ON_PENDING                      (0x10U)
#define DEM_TRIGGER_ON_TEST_FAILED                  (0x20U)
#define DEM_TRIGGER_ON_FDC_THRESHOLD_ONCE           (0x80U)
/* DemExtendedDataRecordUpdate */
#define DEM_UPDATE_RECORD_NO                        (0U)
#define DEM_UPDATE_RECORD_YES                       (1U)
/* DemIUMPRDenGroup */
#define DEM_IUMPR_DEN_NONE                          (0U)
#define DEM_IUMPR_DEN_GENERAL                       (1U)
#define DEM_IUMPR_DEN_COLDSTART                     (2U)
#define DEM_IUMPR_DEN_EVAP                          (3U)
#define DEM_IUMPR_DEN_500MILL                       (4U)
#define DEM_IUMPR_DEN_PHYS_API                      (5U)
#define DEM_IUMPR_DEM_NUM                           (6U)
/* DemIUMPRGroup */
#define DEM_IUMPR_GRP_NONE                          (0U)
#define DEM_IUMPR_BOOSTPRS                          (1U)
#define DEM_IUMPR_CAT1                              (2U)
#define DEM_IUMPR_CAT2                              (3U)
#define DEM_IUMPR_EGR                               (4U)
#define DEM_IUMPR_EGSENSOR                          (5U)
#define DEM_IUMPR_EVAP                              (6U)
#define DEM_IUMPR_FLSYS                             (7U)
#define DEM_IUMPR_NMHCCAT                           (8U)
#define DEM_IUMPR_NOXADSORB                         (9U)
#define DEM_IUMPR_NOXCAT                            (10U)
#define DEM_IUMPR_OXS1                              (11U)
#define DEM_IUMPR_OXS2                              (12U)
#define DEM_IUMPR_PMFILTER                          (13U)
#define DEM_IUMPR_PRIVATE                           (14U)
#define DEM_IUMPR_SAIR                              (15U)
#define DEM_IUMPR_SECOXS1                           (16U)
#define DEM_IUMPR_SECOXS2                           (17U)
/* DemRatioKind */
#define DEM_RATIO_NONE                              (0U)
#define DEM_RATIO_API                               (1U)
#define DEM_RATIO_OBSERVER                          (2U)
/* DemDtrUpdateKind */
#define DEM_DTR_UPDATE_ALWAYS                       (0U)
#define DEM_DTR_UPDATE_STEADY                       (1U)
/*DemOBDEngineType*/
#define DEM_IGNITION_COMPRESSION                    (0U)
#define DEM_IGNITION_SPARK                          (1U)

/* DTC clear client */
#define DEM_CLEAR_DTC_CLIENT_NONE                   (0U)
#define DEM_CLEAR_DTC_CLIENT_CDD                    (1U)
#define DEM_CLEAR_DTC_CLIENT_DCM                    (2U)
#define DEM_CLEAR_DTC_CLIENT_OBD                    (3U)
#define DEM_CLEAR_DTC_CLIENT_J1939                  (4U)

/* DTC type */
#define DEM_CLEAR_DTC_TYPE_NONE                     (0U)
#define DEM_CLEAR_DTC_TYPE_SINGLE                   (1U)
#define DEM_CLEAR_DTC_TYPE_GROUP                    (2U)
#define DEM_CLEAR_DTC_TYPE_ALL                      (3U)

/* Supported operation cycle types */
#define DEM_OPCYC_TYPE_NON                          (0U)
#define DEM_OPCYC_IGNITION                          (1U)
#define DEM_OPCYC_OBD_DCY                           (2U)
#define DEM_OPCYC_OTHER                             (3U)
#ifndef DEM_OPCYC_POWER
#define DEM_OPCYC_POWER                             (4U)
#endif
#define DEM_OPCYC_TIME                              (5U)
#define DEM_OPCYC_WARMUP                            (6U)

/* Unused parameters */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
#define DEM_UNUSED_PARAMETER(val)                   ((val) = (val))

#define DEM_DTC_GROUP_ALL_DTCS                      ((uint32)(0x00FFFFFFUL))
#define DEM_ZERO_VALUE                              (0x00U)

/* Indicator counter increase mode. */
#define DEM_INIDICATOR_CNT_CUMULATIVELY             (0U)
#define DEM_INIDICATOR_CNT_CONTINUOUSLY             (1U)

/* Operation cycle queue size */
#define DEM_OPERCYCLE_QUEUE_SIZE                    (16U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Dem_2.5" */
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
#if( DEM_CFG_J1939SUPPORT == STD_ON )
typedef struct
{
    Dem_J1939DcmLampStatusType* LampStatus;
    uint16 j1939DtcFormat;
    uint16 j1939DtcFilterMatchNum;
    uint16 j1939DtcFilterMatchCnt;
    uint16 j1939DtcFilterMatchNextIdx;
    uint16 j1939DtcFilterMatchNextEvtIdx;
    Dem_J1939DcmDTCStatusFilterType dtcStatusFilter;
    uint8 j1939DtcNode;
    uint8 j1939DtcKind;
    boolean j1939DtcEnable;
    boolean j1939DtcFilterMatchNext;
} Dem_ManageJ1939DtcFilter_st;

typedef struct
{
    uint16 dm31FilterMatchCnt;
    uint16 dm31FilterMatchNextIdx;
    uint8 j1939Node;
    boolean dm31Enable;
    boolean dm31FilterMatchNext;
} Dem_ManageDM31Filter_st;
#endif

typedef struct
{
    uint8  evtQueSt;
    uint8  evtQueDtcSt[DEM_CFG_EVENT_NUM];
    uint16 evtQuePos;
    uint16 evtQueBuf[DEM_CFG_EVENT_NUM];
} Dem_ManageEventQueue_st;

typedef struct
{
    boolean dtcFilterEn;            /* DTC filter setting */
    boolean dtcFiltered[DEM_CFG_DTC_NUM];
    Dem_UdsStatusByteType dtcStsMask;
    Dem_DTCKindType dtcKind;
    Dem_DTCFormatType dtcFormat;
    Dem_DTCOriginType dtcOrigin;
    uint8 dtcEvtMemIdx;
    boolean dtcFilterWithSevr;
    Dem_DTCSeverityType dtcSevrMask;
    boolean dtcFilterForFdc;
    uint8 dtcFilterSlotCnt;
    boolean dtcFilterMatchNext;
    boolean dtcFilterAllSupported;
    boolean dtcFreezeFrameFilterEn;            /* Freeze frame filter setting */
    uint8 ffFilterSlotCnt;
    Dem_DTCFormatType ffFormat;
    boolean ffFilterMatchNext;
    uint8 ffFilterMatchNextRecIdx;
    uint16 dtcFilterMatchNum;
    uint16 dtcFilterMatchCnt;
    uint16 dtcFilterMatchNextIdx;
} Dem_ManageDtcFilter_st;

typedef struct
{
    boolean dtcRecEnable;
    uint8  dtcEvtMemIdx;
    uint32 dtcVal;
} Dem_ManageDtcRecordEnable_st;

typedef struct
{
    uint8  dtcClearStatus;
    Dem_DTCOriginType  evtMemIdx;
    Dem_DTCFormatType  dtcFormat;
    uint8  dtcType;
    uint8  dtcClearClient;
    uint8  dtcGrpIdx;
    uint32 dtcValue;
} Dem_ManageDtcClearReq_st;

typedef struct
{
    boolean dtcSetDis;
    boolean dtcSetEn;
    uint8  dtcKind;
    uint8  dtcGrpIdx;
    uint32 dtcGroup;
} Dem_ManageDtcSettingDis_st;

typedef struct
{
    uint8  opcycReqFlg[DEM_CFG_OPCYC_NUM];
    Dem_OperationCycleStateType  opcycReqState[DEM_CFG_OPCYC_NUM];
} Dem_ManageOperCycleReq_st;

typedef struct
{
    boolean  compAvailable[DEM_CFG_COMP_NUM + DEM_BYTE_ONE];
    boolean  compFailedStatus[DEM_CFG_COMP_NUM + DEM_BYTE_ONE];
    uint16  compFailedEvtIdx[DEM_CFG_COMP_NUM + DEM_BYTE_ONE];
} Dem_ManageCompenentSt_st;

#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
typedef struct
{
    uint8  ffData[DEM_CFG_FFDATA_MAX_BYTES];
    uint8  exData[DEM_CFG_EXDATA_MAX_BYTES];
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    uint8  obdffData[(DEM_CFG_OBD_PID_DATA_NUM + DEM_BYTE_ONE) * DEM_BYTE_FOUR];
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
    uint8  wwhObdData[DEM_CFG_FFDATA_MAX_BYTES];
#endif
#endif
} Dem_SnapShortData_st;
#endif

typedef struct
{
    uint8 OpCycQueSt;
    uint8 OpCycQueReqSt[DEM_OPERCYCLE_QUEUE_SIZE];
    uint8 OpCycQuePos;
    uint8 OpCycQueBuf[DEM_OPERCYCLE_QUEUE_SIZE];
} Dem_ManageOperCycleQueue_st;

typedef struct
{
    uint32  evtDebTime[DEM_CFG_EVENT_NUM];
    boolean evtDtcChangedNotification;
    boolean evtEnCond[DEM_CFG_ENCOND_NUM + DEM_BYTE_ONE];
    boolean evtEnCondGrp[DEM_CFG_ENCOND_GROUP_NUM + DEM_BYTE_ONE];
    boolean evtStorCond[DEM_CFG_STORCOND_NUM + DEM_BYTE_ONE];
    boolean evtStorCondGrp[DEM_CFG_STORCOND_GROUP_NUM + DEM_BYTE_ONE];
    boolean evtEnCondReq;    /* Check enable condition status changed or not. */
    boolean evtStorCondReq;    /* Check storage condition status changed or not. */
    boolean evtMonitorReasonReq;    /* Check event monitor initialization reason changed or not. */
    boolean evtDtcSupp[DEM_CFG_DTC_NUM];             /* DTC Suppression status. */
    boolean evtStored[DEM_CFG_EVENT_NUM][DEM_CFG_EVENT_MEMORY_NUM];
    boolean lampfailcntUpdated[DEM_CFG_EVENT_NUM];
    uint8   evtEntryIdx[DEM_CFG_EVENT_NUM][DEM_CFG_EVENT_MEMORY_NUM];
#if( DEM_CFG_CALIBSUPPORT == STD_ON )
    uint8   evtInitAvail[DEM_CFG_EVENT_NUM + DEM_BYTE_ONE];
#endif
    uint8   evtAvail[DEM_CFG_EVENT_NUM];
    uint8   evtTrig[DEM_CFG_EVENT_NUM];
    sint8   evtFdcCnt[DEM_CFG_EVENT_NUM];
    sint8   evtFdcCntMax_dcc[DEM_CFG_EVENT_NUM];  /* Maximum FDC during current cycle */
    uint8   evtDebTimerSt[DEM_CFG_EVENT_NUM];
    uint8   evtDebSt[DEM_CFG_EVENT_NUM];
    uint8   evtMonitorReason[DEM_CFG_EVENT_NUM];
    uint8   evtIndi[DEM_CFG_EVENT_NUM][DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM];
    uint8   indiStatus[DEM_CFG_INDICATOR_NUM + DEM_BYTE_ONE];                 /* Indicator status. */
    uint8   indiActCnt[DEM_CFG_INDICATOR_NUM + DEM_BYTE_ONE];                 /* Indicator activation counters. */
    sint16  evtDebCnt[DEM_CFG_EVENT_NUM];
    Dem_ManageEventQueue_st evtQue;     /* Used for all events reported after init. */
    Dem_ManageOperCycleQueue_st opCycQue;     /* Operation cycle queue management. */
    Dem_ManageCompenentSt_st compSt;
    Dem_ManageDtcSettingDis_st dtcSettingDis;
    Dem_ManageDtcClearReq_st dtcClearReq;
    Dem_ManageDtcFilter_st dtcFilter;
    Dem_ManageDtcRecordEnable_st dtcRecEn;
#if( DEM_CFG_J1939SUPPORT == STD_ON )
    Dem_ManageJ1939DtcFilter_st j1939DtcFilter;
    Dem_ManageDM31Filter_st dm31Filter;
#endif
#if(DEM_CFG_ENVIRONEMNTDATACAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
    uint8  ssDataBufCnt;
    boolean evtSsDataFfStored[DEM_CFG_EVENT_NUM];
    boolean evtSsDataExStored[DEM_CFG_EVENT_NUM];
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    boolean evtSsDataObdStored[DEM_CFG_EVENT_NUM];
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
    boolean evtSsDataWwhObdStored[DEM_CFG_EVENT_NUM];
#endif
#endif
    uint8   evtSsDataBufPos[DEM_CFG_EVENT_NUM];
    Dem_SnapShortData_st ssDataBuf[DEM_CFG_MAXNUMBEREVENTENTRYEVENTBUFFER];
#endif
#if( DEM_CFG_EVENT_NUM > DEM_CFG_MAXEVTNUMPROCSPERCYCLE )
    uint16  evtAvailSplitCnt;
#endif /* DEM_CFG_EVENT_NUM > DEM_CFG_MAXEVTNUMPROCSPERCYCLE */
} Dem_ManageEvent_st;

typedef struct
{
    uint8 evtMemImeStorCnt;
    uint8 evtMemState;
    uint8 nvmReadReqSt;
    uint8 nvmWriteReqSt;
    uint8 nvmClearReqSt;
    uint8 nvmBlkImeStoreReq;
    uint8 nvmBlkImeStore[DEM_CFG_NVM_BLOCK_NUM + DEM_BYTE_ONE];
    uint8 nvmBlkStatus[DEM_CFG_NVM_BLOCK_NUM + DEM_BYTE_ONE];
    uint8 nvmBlkReadReq[DEM_CFG_NVM_BLOCK_NUM + DEM_BYTE_ONE];
    uint8 nvmBlkWriteReq[DEM_CFG_NVM_BLOCK_NUM + DEM_BYTE_ONE];
    uint8 nvmBlkClearReq[DEM_CFG_NVM_BLOCK_NUM + DEM_BYTE_ONE];
    uint16 nvmAccessBlkIdx;
} Dem_ManageNvmBlk_st;

typedef struct
{
    uint8  ffRecIdx;
    uint8  stFfData[DEM_CFG_FFDATA_MAX_REF_RECORD_NUM];     /* To indicate if the data is already in event memory */
    uint8  stExData[DEM_CFG_EXDATA_MAX_REF_EXDATA_RECORD_NUM];
    uint8  ffData[DEM_CFG_FFDATA_MAX_BYTES];
    uint8  exData[DEM_CFG_EXDATA_MAX_BYTES];
} Dem_FaultDataInfo_st;

typedef struct
{
    uint8 evtOpCycSt[DEM_CFG_OPCYC_NUM];
    uint8 evtDtcSt[DEM_CFG_EVENT_NUM];
#if(DEM_CFG_EXTENDSTATUSBYTE != DEM_INIT_ZERO)
    uint8 evtDtcStIndi[DEM_CFG_EVENT_NUM];
#endif
    uint8 evtFailedCnt[DEM_CFG_EVENT_NUM];
    uint8 evtLampFailedCnt[DEM_CFG_EVENT_NUM][DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM];    /* Event indicator failure counter. */
    sint8 evtFdcCntMax_slc[DEM_CFG_EVENT_NUM];  /* maximum FDC since last clear */
    sint16 evtDebCnt[DEM_CFG_EVENT_NUM];
#if(DEM_CFG_AGEDCTRSUPPORT == STD_ON)
    uint8 evtAgedCnt[DEM_CFG_EVENT_NUM];
#if(DEM_CFG_INTDATAEXSUPPORT == STD_ON)
    uint16 evtAgedCnt2[DEM_CFG_EVENT_NUM];
#endif
#endif
} Dem_EventMemoryStatus_st;

typedef struct
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dem_D4.8" */
{
    uint8  cntEnSlot;                                       /* numbers of entries are now currently in event memory */
    uint8  entryIdx[DEM_CFG_MAX_NUMBER_EVENT_ENTRY];
    uint16 enSlot[DEM_CFG_MAX_NUMBER_EVENT_ENTRY];          /* Fault memory entry slot: evtId in chronological order */
    uint16 firstFaliedEvtId;
    uint16 recentlyFaliedEvtId;
    uint16 firstConfirmEvtId;
    uint16 recentlyConfirmEvtId;
} Dem_EventMemoryInfo_st;

typedef struct
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dem_D4.8" */
{
    uint8  evtActive;       /* event is active or passive */
    uint8  stFault;         /* Fault state: pending, confirmed, healing, aging */
    uint8  cntCslf;         /* operation cycles counter of cycle since last failed */
    uint8  cntCsff;         /* operation cycles counter of cycle since first failed */
    uint8  cntFc;           /* operation cycles counter of failed cycle */
    uint8  cntOcc;          /* event occurence counter */
    uint8  cntHeal[DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM];         /* healing counter on operation cycle */
    uint8  cntAge;          /* aging counter on aging operation cycle */
    uint8  cntAgeHour;      /* aging hours counter in engine run without falut */
#if( DEM_CFG_INTDATAEXSUPPORT == STD_ON )
    uint16  cntOcc2;        /* event occurence counter 2 bytes */
    uint16  cntAge2;        /* aging counter on aging operation cycle 2 bytes */
#endif
#if(DEM_CFG_OCC1SUPPORT == STD_ON)
    uint8  cntOCC1;
#endif
#if(DEM_CFG_OCC2SUPPORT == STD_ON)
    uint8  cntOCC2;
#endif
#if(DEM_CFG_OCC3SUPPORT == STD_ON)
    uint8  cntOCC3;
#endif
#if(DEM_CFG_OCC4SUPPORT == STD_ON)
    uint8  cntOCC4;
#endif
#if(DEM_CFG_OCC5SUPPORT == STD_ON)
    uint8  cntOCC5;
#endif
#if(DEM_CFG_OCC6SUPPORT == STD_ON)
    uint8  cntOCC6;
#endif
#if(DEM_CFG_OCC7SUPPORT == STD_ON)
    uint8  cntOCC7;
#endif
    uint16 evtId;           /* Dem Fault Memory Entry: event ID */
    Dem_FaultDataInfo_st datBuf;
} Dem_EventMemoryEntry_st;

#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
typedef struct
{
    uint16 dtrTestRes;
    uint16 dtrLowerLimit;
    uint16 dtrUpperLimit;
} Dem_OBDManageDtr_st;

typedef struct
{
    boolean iuprCycFlag;
    boolean pfcCycQuali;
    boolean ptoStatus;
    uint8 warmUpCycleCntSinceLastInit;
    uint8 wuCycFlagDuringlastDrvCyc;
    uint8 valOfPid04;
    uint8 generalDenoCalcState;
    uint8 iuprCalcState[DEM_CFG_OBD_RATIO_NUM + DEM_BYTE_ONE];
    uint8 iuprNumCondiForAsymEvent[DEM_CFG_OBD_RATIO_NUM + DEM_BYTE_ONE];
    uint8 iuprDenPhsyCondition[DEM_CFG_OBD_RATIO_NUM + DEM_BYTE_ONE];
    uint8 iuprDenCondition[DEM_IUMPR_DEM_NUM];
    uint8 evtDisableFor41[DEM_CFG_EVENT_NUM];
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
    uint8 wwhActMode;
    uint8 wwhContiMiDetect;
    uint8 wwhB1EventDetect;
    uint32 wwhContiMiOffCntStartTime;
    uint32 wwhContiMiCntStartTime;
    uint32 wwhCumuContiMiCntStartTime;
    uint32 wwhB1CntStartTime;
    uint32 wwhDtcAgingStartTime[DEM_CFG_MAX_NUMBER_EVENT_ENTRY];
#endif
    uint16 valOfPid42;
    uint32 valOfPid29;
    Dem_OBDManageDtr_st dtrData[DEM_CFG_DTR_NUM + DEM_BYTE_ONE];
} Dem_OBDManage_st;

typedef struct
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Dem_D4.8" */
{
    uint8  drvCycleCnt;
    uint8  warmUpCycleCnt;
    uint8  pfcCnt;
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
    uint8  wwhB1CntAge;
    uint8  wwhContiMiOffCnt;
    uint8  wwhContiMiCntAge;
    uint8  wwhContiMiCntHaltCycle;
    uint8  wwhFreezeframedatBuf[DEM_CFG_FFDATA_MAX_BYTES];
#endif
    uint8  freezeframedatBuf[(DEM_CFG_OBD_PID_DATA_NUM + DEM_BYTE_ONE) * DEM_BYTE_FOUR];
    uint16 freezeframeEvtId;
    uint16 genDenominator;
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
    uint16 wwhB1Cnt;
    uint16 wwhB1CntHighest;
    uint16 wwhContiMiCnt;
    uint16 wwhCumuContiMiCnt;
    uint16 wwhFreezeframeEvtId;
#endif
    uint16 ignitionCycleCnt;
    uint16 pfcEvtId[DEM_CFG_MAXNUMBEREVENTENTRYPERMANENT];
    uint16 numerator[DEM_CFG_OBD_RATIO_NUM + DEM_BYTE_ONE];
    uint16 denominator[DEM_CFG_OBD_RATIO_NUM + DEM_BYTE_ONE];
    uint32 pfcVal[DEM_CFG_MAXNUMBEREVENTENTRYPERMANENT];
    uint32 iuprRatio[DEM_CFG_OBD_RATIO_NUM + DEM_BYTE_ONE];
    uint32 odoMilOn;     /* MIL on distanse in uint KM */
    uint32 odoSinceDtcClear;   /* distanse since last clear DTC in uint KM */
    uint32 engineRuntimeWhileMilOn;   /* engine run time while MIL on in unit minute */
    uint32 engineRuntimeSinceDtcClear;   /* engine run time since last clear DTC in unit minute */
} Dem_PermanentEventMemoryEntry_st;
#endif

typedef struct
{
    uint8 initSt;                       /* dem initialization state: preinit, inited, shutdown */
    Dem_ManageNvmBlk_st nvmBlkSt;
    Dem_ManageEvent_st evtInfo;
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    Dem_OBDManage_st obdInfo;
#endif
} Dem_Manage_st;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define DEM_START_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
extern VAR(Dem_Manage_st, DEM_VAR_NO_INIT) Dem_Manage;
extern VAR(Dem_EventMemoryStatus_st, DEM_VAR_NO_INIT) Dem_EventMemoryStatus;
extern VAR(Dem_EventMemoryStatus_st, DEM_VAR_NO_INIT) Dem_DummyEventMemoryStatus;
extern VAR(Dem_EventMemoryInfo_st, DEM_VAR_NO_INIT) Dem_PrimaryEventMemoryInfo;
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_ONE)
extern VAR(Dem_EventMemoryInfo_st, DEM_VAR_NO_INIT) Dem_User0EventMemoryInfo;
#endif
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_TWO)
extern VAR(Dem_EventMemoryInfo_st, DEM_VAR_NO_INIT) Dem_User1EventMemoryInfo;
#endif
extern VAR(Dem_EventMemoryInfo_st, DEM_VAR_NO_INIT) Dem_DummyEventMemoryInfo;
extern VAR(Dem_EventMemoryEntry_st, DEM_VAR_NO_INIT) Dem_PrimaryEventMemoryEntry[DEM_CFG_PRIMARY_MAX_NUMBER_EVENT_ENTRY];
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_ONE)
extern VAR(Dem_EventMemoryEntry_st, DEM_VAR_NO_INIT) Dem_User0EventMemoryEntry[DEM_CFG_USER0_MAX_NUMBER_EVENT_ENTRY];
#endif
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_TWO)
extern VAR(Dem_EventMemoryEntry_st, DEM_VAR_NO_INIT) Dem_User1EventMemoryEntry[DEM_CFG_USER1_MAX_NUMBER_EVENT_ENTRY];
#endif
extern VAR(Dem_EventMemoryEntry_st, DEM_VAR_NO_INIT) Dem_DummyEventMemoryEntry;

#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
extern VAR(Dem_PermanentEventMemoryEntry_st, DEM_VAR_NO_INIT) Dem_PermanentEventMemoryEntry;
extern VAR(Dem_PermanentEventMemoryEntry_st, DEM_VAR_NO_INIT) Dem_DummyPermanentEventMemoryEntry;
#endif
#define DEM_STOP_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define DEM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
extern VAR(uint16, DEM_VAR_INIT) Dem_DiagProcDTCIdx;
extern P2VAR(Dem_EventMemoryInfo_st, DEM_VAR_INIT, DEM_APPL_DATA) Dem_EventMemoryInfo[DEM_CFG_EVENT_MEMORY_NUM];
extern P2VAR(Dem_EventMemoryEntry_st, DEM_VAR_INIT, DEM_APPL_DATA) Dem_EventMemoryEntry[DEM_CFG_EVENT_MEMORY_NUM];
#define DEM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
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
extern FUNC(void, DEM_CODE) Dem_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DEM_APPL_DATA) versioninfo
);
extern FUNC(void, DEM_CODE) Dem_PreInit(void);
extern FUNC(void, DEM_CODE) Dem_Init
(
    P2CONST(Dem_ConfigType, AUTOMATIC, DEM_APPL_CONST) ConfigPtr
);
extern FUNC(void, DEM_CODE) Dem_Shutdown(void);
extern FUNC(void, DEM_CODE) Dem_ReportErrorStatus
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
);
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventAvailable
(
    Dem_EventIdType EventId,
    boolean AvailableStatus
);
#endif
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventDebounceStatus
(
    Dem_EventIdType EventId,
    Dem_DebounceResetStatusType DebounceResetStatus
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventStatus
(
    Dem_EventIdType EventId
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetOperationCycleState
(
    uint8 OperationCycleId,
    Dem_OperationCycleStateType CycleState
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetOperationCycleState
(
    uint8 OperationCycleId,
    P2VAR(Dem_OperationCycleStateType, AUTOMATIC, DEM_APPL_DATA) CycleState
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetAgingCycleState
(
    uint8 OperationCycleId
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetComponentFailed
(
    Dem_ComponentIdType ComponentId,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) ComponentFailed
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetWIRStatus
(
    Dem_EventIdType EventId,
    boolean WIRStatus
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventStatus
(
    Dem_EventIdType EventId,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) EventStatusByte
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFailed
(
    Dem_EventIdType EventId,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) EventFailed
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventTested
(
    Dem_EventIdType EventId,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) EventTested
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDebouncingOfEvent
(
    Dem_EventIdType EventId,
    P2VAR(Dem_DebouncingStateType, AUTOMATIC, DEM_APPL_DATA) DebouncingState
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCOfEvent
(
    Dem_EventIdType EventId,
    Dem_DTCFormatType DTCFormat,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTCOfEvent
);
#if(DEM_CFG_ENCOND_NUM > DEM_INIT_ZERO)
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEnableCondition
(
    uint8 EnableConditionID,
    boolean ConditionFulfilled
);
#endif
#if(DEM_CFG_STORCOND_NUM > DEM_INIT_ZERO)
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetStorageCondition
(
    uint8 StorageConditionID,
    boolean ConditionFulfilled
);
#endif
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetFaultDetectionCounter
(
    Dem_EventIdType EventId,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetIndicatorStatus
(
    uint8 IndicatorId,
    P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFreezeFrameDataEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    uint16 DataId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventExtendedDataRecordEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventMemoryOverflow
(
    Dem_DTCOriginType DTCOrigin,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) OverflowIndication
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumberOfEventMemoryEntries
(
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) NumberOfEventMemoryEntries
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetComponentAvailable
(
    Dem_ComponentIdType ComponentId,
    boolean AvailableStatus
);
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTCSuppression
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    boolean SuppressionStatus
);
#endif
extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTC
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DltGetMostRecentFreezeFrameRecordData
(
    Dem_EventIdType EventId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DltGetAllExtendedDataRecords
(
    Dem_EventIdType EventId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventDisabled
(
    Dem_EventIdType EventId
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRFaultDetect
(
    Dem_RatioIdType RatioID
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetIUMPRDenCondition
(
    Dem_IumprDenomCondIdType ConditionId,
    Dem_IumprDenomCondStatusType ConditionStatus
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetIUMPRDenCondition
(
    Dem_IumprDenomCondIdType ConditionId,
    P2VAR(Dem_IumprDenomCondStatusType, AUTOMATIC, DEM_APPL_DATA) ConditionStatus
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenLock
(
    Dem_RatioIdType RatioID
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenRelease
(
    Dem_RatioIdType RatioID
);
#if(DEM_CFG_PTOSUPPORT == STD_ON)
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetPtoStatus
(
    boolean PtoStatus
);
#endif
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ReadDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01value
);
#if((DEM_CFG_OBD_PID21_CENTRALIZED == TRUE) && (DEM_CFG_OBDSUPPORT == DEM_OBD_MASTER_ECU))
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value
);
#endif
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID04
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID04value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID29
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID29value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID31
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID31value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID42
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID42value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4D
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Dvalue
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4E
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Evalue
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetPfcCycleQualified(void);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetPfcCycleQualified
(
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) isqualified
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetClearDTC
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCSeverityAvailabilityMask
(
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverityMask
);
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetB1Counter
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) B1Counter
);
#endif
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTR
(
    uint16 DTRId,
    sint32 TestResult,
    sint32 LowerLimit,
    sint32 UpperLimit,
    Dem_DTRControlType Ctrlval
);
#endif

#if( DEM_CFG_J1939SUPPORT == STD_ON )
#if( DEM_CFG_J1939READINGDTCSUPPORT == STD_ON )
extern FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_J1939DcmSetDTCFilter
(
    Dem_J1939DcmDTCStatusFilterType DTCStatusFilter,
    Dem_DTCKindType DTCKind,
    uint8 node,
    P2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_APPL_DATA) LampStatus
);
extern FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE) Dem_J1939DcmGetNumberOfFilteredDTC
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC
);
extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_J1939DcmGetNextFilteredDTC
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) J1939DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
);
#endif

#if( DEM_CFG_J1939DM31SUPPORT == STD_ON )
extern FUNC(void, DEM_CODE) Dem_J1939DcmFirstDTCwithLampStatus(uint8 node);
extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_J1939DcmGetNextDTCwithLampStatus
(
    P2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_APPL_DATA) LampStatus,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) J1939DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
);
#endif

#if( DEM_CFG_J1939CLEARDTCSUPPORT == STD_ON )
extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_J1939DcmClearDTC
(
    Dem_J1939DcmSetClearFilterType DTCTypeFilter,
    uint8 node
);
#endif
#endif

/* PolySpace +1 MISRA-C3:8.5 [Justified:Unset] "NSCA_Polyspace_Dem_8.5" */
extern FUNC(void, DEM_CODE) Dem_MainFunction(void);
#define DEM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif /* DEM_H_ */


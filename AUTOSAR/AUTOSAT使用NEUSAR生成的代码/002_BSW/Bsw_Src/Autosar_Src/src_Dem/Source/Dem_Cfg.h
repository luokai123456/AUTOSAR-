/*
********************************************************************************
*
* File name: Dem_Cfg.h
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJP/2021.08.14
* Change: New
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: ZengJX/2024.07.18
* Change: Modify copyright information.
* Cause: Optimization
********************************************************************************
* Version: 1.2
* Author/Date: ZengJX/2024.08.22
* Change: Modify copyright information.
* Cause: Bugfix
********************************************************************************
*/
#ifndef DEM_CFG_H_
#define DEM_CFG_H_

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
/* Dem General Configurations */
#define DEM_CFG_AGINGCYCLECOUNTERPROCESS                            (DEM_PROCESS_AGINGCTR_INTERN)
#define DEM_CFG_AGINGCOUNTERREQUIRETESTEDCYCLE                      (STD_OFF)
#define DEM_CFG_AVAILABLITYSUPPORT                                  (DEM_EVENT_AVAILABILITY)
#define DEM_CFG_BSWERRORBUFFERSIZE                                  (255U)
#define DEM_CFG_CLEARBEHAVIOR                                       (DEM_CLRRESP_NONVOLATILE_FINISH)
#define DEM_CFG_CLEARDTCLIMITATION                                  (DEM_ALL_SUPPORTED_DTCS)
#define DEM_CFG_DATAELEMENTDEFAULTENDIANNESS                        (DEM_EXDATA_BIG_ENDIAN)
#define DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT                         (STD_ON)
#define DEM_CFG_DEBOUNCETIMEBASEDSUPPORT                            (STD_ON)
#define DEM_CFG_DEVERRORDETECT                                      (STD_OFF)
#define DEM_CFG_DTCSTATUSAVAILABILITYMASK                           (9U)
#define DEM_CFG_ENVIRONEMNTDATACAPTURE                              (DEM_CAPTURE_ASYNCHRONOUS_TO_REPORTING)
#define DEM_CFG_EVENTCOMBINATIONSUPPORT                             (DEM_EVCOMB_ONSTORAGE)
#define DEM_CFG_EVENTDISPLACEMENTSTRATEGY                           (DEM_DISPLACEMENT_FULL)
#define DEM_CFG_EVENTMEMORYENTRYSTORAGETRIGGER                      (DEM_TRIGGER_ON_CONFIRMED)
#define DEM_CFG_GENERALINTERFACESUPPORT                             (STD_OFF)
#define DEM_CFG_IMMEDIATENVSTORAGELIMIT                             (255U)
#define DEM_CFG_MAXNUMBEREVENTENTRYEVENTBUFFER                      (1U)
#define DEM_CFG_MAXNUMBEREVENTENTRYPERMANENT                        (1U)
#define DEM_CFG_MAXEVTNUMPROCSPERCYCLE                              (300U)
#define DEM_CFG_OBDSUPPORT                                          (DEM_OBD_NO_OBD_SUPPORT)
#define DEM_CFG_INDICATORCNTINCREASEMODE                            (DEM_INIDICATOR_CNT_CUMULATIVELY)
#define DEM_CFG_PFCCLEAREDINWUPCYCLE                                (STD_OFF)
#define DEM_CFG_OCCURRENCECOUNTERPROCESSING                         (DEM_PROCESS_OCCCTR_TF)
#define DEM_CFG_OPERATIONCYCLESTATUSSTORAGE                         (STD_OFF)
#define DEM_CFG_PTOSUPPORT                                          (STD_OFF)
#define DEM_CFG_RESETCONFIRMEDBITONOVERFLOW                         (STD_ON)
#define DEM_CFG_STATUSBITHANDLINGTESTFAILEDSINCELASTCLEAR           (DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
#define DEM_CFG_STATUSBITSTORAGETESTFAILED                          (STD_OFF)
#define DEM_CFG_SUPPRESSIONSUPPORT                                  (DEM_DTC_SUPPRESSION)
#define DEM_CFG_TASKTIME                                            (10U)
#define DEM_CFG_TRIGGERDCMREPORT                                    (STD_OFF)
#define DEM_CFG_TRIGGERDLTREPORT                                    (STD_OFF)
#define DEM_CFG_TRIGGERFIMREPORT                                    (STD_ON)
#define DEM_CFG_NVMSETRAMBLOCKSTATUSAPI_SUPPORT                     (STD_ON)
#define DEM_CFG_FIMSUPPORT                                          (STD_ON)
#define DEM_CFG_TRIGGERMONITORINITBEFORECLEAROK                     (STD_OFF)
#define DEM_CFG_TYPEOFDTCSUPPORTED                                  (DEM_DTC_TRANSLATION_J2012DA_FORMAT_04)
#define DEM_CFG_VERSIONINFOAPI                                      (STD_OFF)
#define DEM_CFG_MILINDICATORREF                                     (0U)
#define DEM_CFG_DTCACCESSSPILTLIMIT                                 (600U)
#define DEM_CFG_EXTENDSTATUSBYTE                                    (0U)
#define DEM_CFG_UCSUPPORT                                           (STD_OFF)
#define DEM_CFG_UCTOCSUPPORT                                        (STD_OFF)
#define DEM_CFG_UCSLCSUPPORT                                        (STD_OFF)
#define DEM_CFG_AGEDSUPPORT                                         (STD_OFF)
#define DEM_CFG_SSLCSUPPORT                                         (STD_OFF)
#define DEM_CFG_WIRSLCSUPPORT                                       (STD_OFF)
#define DEM_CFG_EMRSUPPORT                                          (STD_OFF)
#define DEM_CFG_TFSLRSUPPORT                                        (STD_OFF)
#define DEM_CFG_OCC1SUPPORT                                         (STD_OFF)
#define DEM_CFG_OCC2SUPPORT                                         (STD_OFF)
#define DEM_CFG_OCC3SUPPORT                                         (STD_OFF)
#define DEM_CFG_OCC4SUPPORT                                         (STD_OFF)
#define DEM_CFG_OCC5SUPPORT                                         (STD_OFF)
#define DEM_CFG_OCC6SUPPORT                                         (STD_OFF)
#define DEM_CFG_OCC7SUPPORT                                         (STD_OFF)

/* Dem OBD General Configurations */
#define DEM_CFG_OBD_PID21_CENTRALIZED                 (STD_OFF)
#define DEM_CFG_OBD_PID31_CENTRALIZED                 (STD_OFF)
#define DEM_CFG_OBD_COMPLIANCY                        (0U)
#define DEM_CFG_OBD_ENGINE_TYPE                       (DEM_IGNITION_SPARK)
#define DEM_CFG_OBD_EVENT_DISPLACEMENT                (STD_OFF)
#define DEM_CFG_OBD_EVENT_MEMORY_REF                  (0U)
#define DEM_CFG_OBD_ACC_PEDAL_INFO                    (0U)
#define DEM_CFG_OBD_AMBIENT_PRESSURE                  (0U)
#define DEM_CFG_OBD_AMBIENT_TEMP                      (0U)
#define DEM_CFG_OBD_DISTANCE_INFO                     (0U)
#define DEM_CFG_OBD_ENGINE_SPD                        (0U)
#define DEM_CFG_OBD_ENGINE_TEMP                       (0U)
#define DEM_CFG_OBD_PROGRAM_EVENT                     (0U)
#define DEM_CFG_OBD_VEHICLE_SPD                       (0U)
#define DEM_CFG_OBD_TIME_SINCE_ENGINE_START           (0U)

#define DEM_CFG_WWH_OBD_SUPPORT                       (STD_OFF)

#define DEM_CFG_CALIBSUPPORT                          (STD_OFF)
#define DEM_CFG_AGEDCTRSUPPORT                        (STD_OFF)
#define DEM_CFG_INTDATAEXSUPPORT                      (STD_OFF)

#define DEM_CFG_J1939SUPPORT                                        (STD_OFF)
#define DEM_CFG_J1939CLEARDTCSUPPORT                                (STD_OFF)
#define DEM_CFG_J1939DM31SUPPORT                                    (STD_OFF)
#define DEM_CFG_J1939READINGDTCSUPPORT                              (STD_OFF)
#define DEM_EVENT_MONITOR_ENABLE                                    (STD_OFF)
#define DEM_CFG_NVM_RW_SUPPORT                                      (STD_ON)
#define DEM_CFG_AMBERWARNINGLAMPINDICATOR                           (0U)
#define DEM_CFG_PROTECTLAMPINDICATOR                                (0U)
#define DEM_CFG_REDSTOPLAMPINDICATOR                                (0U)
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

#endif /* DEM_CFG_H_ */


/*
************************************************************************************************************************
*
* File name: Rte_Dem_Type.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
************************************************************************************************************************
*
* History
*-----------------------------------------------------------------------------------------------------------------------
************************************************************************************************************************
* Version: 3.0
* Author/Date : WangJP/2021.11.11
* Change: New created.
* Cause: New
************************************************************************************************************************
* Version: 4.0
* Author/Date: LanZG/2024.03.18
* Change: Upgrade template.
* Cause: Update
************************************************************************************************************************
*/
#ifndef RTE_DEM_TYPE_H_
#define RTE_DEM_TYPE_H_

/*
************************************************************************************************************************
*    Includes
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Global Macros
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Types
************************************************************************************************************************
*/
#ifndef Rte_TypeDef_Dem_OperationCycleStateType
#define Rte_TypeDef_Dem_OperationCycleStateType 
typedef uint8 Dem_OperationCycleStateType;
#endif

#ifndef Rte_TypeDef_Dem_DTCFormatType
#define Rte_TypeDef_Dem_DTCFormatType
typedef uint8 Dem_DTCFormatType;
#endif

#ifndef Rte_TypeDef_Dem_EventIdType
#define Rte_TypeDef_Dem_EventIdType
typedef uint16 Dem_EventIdType;
#endif

#ifndef Rte_TypeDef_Dem_DebouncingStateType
#define Rte_TypeDef_Dem_DebouncingStateType
typedef uint8 Dem_DebouncingStateType;
#endif

#ifndef Rte_TypeDef_Dem_IndicatorStatusType
#define Rte_TypeDef_Dem_IndicatorStatusType
typedef uint8 Dem_IndicatorStatusType;
#endif

#ifndef Rte_TypeDef_Dem_DebounceResetStatusType
#define Rte_TypeDef_Dem_DebounceResetStatusType
typedef uint8 Dem_DebounceResetStatusType;
#endif

#ifndef Rte_TypeDef_Dem_EventStatusType
#define Rte_TypeDef_Dem_EventStatusType
typedef uint8 Dem_EventStatusType;
#endif

#ifndef Rte_TypeDef_Dem_DTRControlType
#define Rte_TypeDef_Dem_DTRControlType
typedef uint8 Dem_DTRControlType;
#endif

#ifndef Rte_TypeDef_Dem_RatioIdType
#define Rte_TypeDef_Dem_RatioIdType
typedef uint16 Dem_RatioIdType;
#endif

#ifndef Rte_TypeDef_Dem_IumprDenomCondIdType
#define Rte_TypeDef_Dem_IumprDenomCondIdType
typedef uint8 Dem_IumprDenomCondIdType;
#endif

#ifndef Rte_TypeDef_Dem_IumprDenomCondStatusType
#define Rte_TypeDef_Dem_IumprDenomCondStatusType
typedef uint8 Dem_IumprDenomCondStatusType;
#endif

#ifndef Rte_TypeDef_Dem_UdsStatusByteType
#define Rte_TypeDef_Dem_UdsStatusByteType
typedef uint8 Dem_UdsStatusByteType;
#endif

/* Dem_UdsStatusByteType */
#ifndef DEM_UDS_STATUS_TF
#define DEM_UDS_STATUS_TF                           ((Dem_UdsStatusByteType)0x01)
#endif
#ifndef DEM_UDS_STATUS_TFTOC
#define DEM_UDS_STATUS_TFTOC                        ((Dem_UdsStatusByteType)0x02)
#endif
#ifndef DEM_UDS_STATUS_PDTC
#define DEM_UDS_STATUS_PDTC                         ((Dem_UdsStatusByteType)0x04)
#endif
#ifndef DEM_UDS_STATUS_CDTC
#define DEM_UDS_STATUS_CDTC                         ((Dem_UdsStatusByteType)0x08)
#endif
#ifndef DEM_UDS_STATUS_TNCSLC
#define DEM_UDS_STATUS_TNCSLC                       ((Dem_UdsStatusByteType)0x10)
#endif
#ifndef DEM_UDS_STATUS_TFSLC
#define DEM_UDS_STATUS_TFSLC                        ((Dem_UdsStatusByteType)0x20)
#endif
#ifndef DEM_UDS_STATUS_TNCTOC
#define DEM_UDS_STATUS_TNCTOC                       ((Dem_UdsStatusByteType)0x40)
#endif
#ifndef DEM_UDS_STATUS_WIR
#define DEM_UDS_STATUS_WIR                          ((Dem_UdsStatusByteType)0x80)
#endif

/* Dem_DTRControlType */
#ifndef DEM_DTR_CTL_NORMAL
#define DEM_DTR_CTL_NORMAL                          ((Dem_DTRControlType)0x00)
#endif
#ifndef DEM_DTR_CTL_NO_MAX
#define DEM_DTR_CTL_NO_MAX                          ((Dem_DTRControlType)0x01)
#endif
#ifndef DEM_DTR_CTL_NO_MIN
#define DEM_DTR_CTL_NO_MIN                          ((Dem_DTRControlType)0x02)
#endif
#ifndef DEM_DTR_CTL_RESET
#define DEM_DTR_CTL_RESET                           ((Dem_DTRControlType)0x03)
#endif
#ifndef DEM_DTR_CTL_INVISIBLE
#define DEM_DTR_CTL_INVISIBLE                       ((Dem_DTRControlType)0x04)
#endif

/* Dem_DebounceResetStatusType */
#ifndef DEM_DEBOUNCE_STATUS_FREEZE
#define DEM_DEBOUNCE_STATUS_FREEZE                  ((Dem_DebounceResetStatusType)0x00U)
#endif
#ifndef DEM_DEBOUNCE_STATUS_RESET
#define DEM_DEBOUNCE_STATUS_RESET                   ((Dem_DebounceResetStatusType)0x01U)
#endif

/* Dem_EventStatusType */
#ifndef DEM_EVENT_STATUS_PASSED
#define DEM_EVENT_STATUS_PASSED                     ((Dem_EventStatusType)0x00U)
#endif
#ifndef DEM_EVENT_STATUS_FAILED
#define DEM_EVENT_STATUS_FAILED                     ((Dem_EventStatusType)0x01U)
#endif
#ifndef DEM_EVENT_STATUS_PREPASSED
#define DEM_EVENT_STATUS_PREPASSED                  ((Dem_EventStatusType)0x02U)
#endif
#ifndef DEM_EVENT_STATUS_PREFAILED
#define DEM_EVENT_STATUS_PREFAILED                  ((Dem_EventStatusType)0x03U)
#endif
#ifndef DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED
#define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED      ((Dem_EventStatusType)0x04U)
#endif
#ifndef DEM_EVENT_STATUS_NONE
#define DEM_EVENT_STATUS_NONE                       ((Dem_EventStatusType)0x05U)
#endif

/* Dem_DebouncingStateType */
#ifndef DEM_TEMPORARILY_DEFECTIVE
#define DEM_TEMPORARILY_DEFECTIVE                   ((Dem_DebouncingStateType)0x01U)
#endif
#ifndef DEM_FINALLY_DEFECTIVE
#define DEM_FINALLY_DEFECTIVE                       ((Dem_DebouncingStateType)0x02U)
#endif
#ifndef DEM_TEMPORARILY_HEALED
#define DEM_TEMPORARILY_HEALED                      ((Dem_DebouncingStateType)0x04U)
#endif
#ifndef DEM_TEST_COMPLETE
#define DEM_TEST_COMPLETE                           ((Dem_DebouncingStateType)0x08U)
#endif
#ifndef DEM_DTR_UPDATE
#define DEM_DTR_UPDATE                              ((Dem_DebouncingStateType)0x10U)
#endif

#ifndef Rte_TypeDef_Dem_InitMonitorReasonType
#define Rte_TypeDef_Dem_InitMonitorReasonType
typedef uint8 Dem_InitMonitorReasonType;
#endif
#ifndef DEM_INIT_MONITOR_NONE
#define DEM_INIT_MONITOR_NONE                       ((Dem_InitMonitorReasonType)0x00U)
#endif
#ifndef DEM_INIT_MONITOR_CLEAR
#define DEM_INIT_MONITOR_CLEAR                      ((Dem_InitMonitorReasonType)0x01U)
#endif
#ifndef DEM_INIT_MONITOR_RESTART
#define DEM_INIT_MONITOR_RESTART                    ((Dem_InitMonitorReasonType)0x02U)
#endif
#ifndef DEM_INIT_MONITOR_REENABLED
#define DEM_INIT_MONITOR_REENABLED                  ((Dem_InitMonitorReasonType)0x03U)
#endif
#ifndef DEM_INIT_MONITOR_STORAGE_REENABLED
#define DEM_INIT_MONITOR_STORAGE_REENABLED          ((Dem_InitMonitorReasonType)0x04U)
#endif

/* Dem_IndicatorStatusType */
#ifndef DEM_INDICATOR_OFF
#define DEM_INDICATOR_OFF                           ((Dem_IndicatorStatusType)0x00U)
#endif
#ifndef DEM_INDICATOR_CONTINUOUS
#define DEM_INDICATOR_CONTINUOUS                    ((Dem_IndicatorStatusType)0x01U)
#endif
#ifndef DEM_INDICATOR_BLINKING
#define DEM_INDICATOR_BLINKING                      ((Dem_IndicatorStatusType)0x02U)
#endif
#ifndef DEM_INDICATOR_BLINK_CONT
#define DEM_INDICATOR_BLINK_CONT                    ((Dem_IndicatorStatusType)0x03U)
#endif
#ifndef DEM_INDICATOR_SLOW_FLASH
#define DEM_INDICATOR_SLOW_FLASH                    ((Dem_IndicatorStatusType)0x04U)
#endif
#ifndef DEM_INDICATOR_FAST_FLASH
#define DEM_INDICATOR_FAST_FLASH                    ((Dem_IndicatorStatusType)0x05U)
#endif
#ifndef DEM_INDICATOR_ON_DEMAND
#define DEM_INDICATOR_ON_DEMAND                     ((Dem_IndicatorStatusType)0x06U)
#endif
#ifndef DEM_INDICATOR_SHORT
#define DEM_INDICATOR_SHORT                         ((Dem_IndicatorStatusType)0x07U)
#endif
#ifndef DEM_INDICATOR_NONE
#define DEM_INDICATOR_NONE                          ((Dem_IndicatorStatusType)0x0FU)
#endif

/* Dem_IumprDenomCondStatusType */
#ifndef DEM_IUMPR_DEN_STATUS_NOT_REACHED
#define DEM_IUMPR_DEN_STATUS_NOT_REACHED            ((Dem_IumprDenomCondStatusType)0x00U)     /* Condition of IUMPRDenominator given by IUMPRDenCondId is not met (yet). */
#endif
#ifndef DEM_IUMPR_DEN_STATUS_REACHED
#define DEM_IUMPR_DEN_STATUS_REACHED                ((Dem_IumprDenomCondStatusType)0x01U)     /* Condition of IUMPRDenominator given by IUMPRDenCondId is met. */
#endif
#ifndef DEM_IUMPR_DEN_STATUS_INHIBITED
#define DEM_IUMPR_DEN_STATUS_INHIBITED              ((Dem_IumprDenomCondStatusType)0x02U)     /* Condition of IUMPRDenominator given by IUMPRDenCondId is inhibited and cannot be reached. */
#endif

/* Dem_IumprDenomCondIdType */
#ifndef DEM_IUMPR_GENERAL_DENOMINATOR
#define DEM_IUMPR_GENERAL_DENOMINATOR               ((Dem_IumprDenomCondIdType)0x01)
#endif
#ifndef DEM_IUMPR_DEN_COND_COLDSTART
#define DEM_IUMPR_DEN_COND_COLDSTART                ((Dem_IumprDenomCondIdType)0x02)
#endif
#ifndef DEM_IUMPR_DEN_COND_EVAP
#define DEM_IUMPR_DEN_COND_EVAP                     ((Dem_IumprDenomCondIdType)0x03)
#endif
#ifndef DEM_IUMPR_DEN_COND_500MI
#define DEM_IUMPR_DEN_COND_500MI                    ((Dem_IumprDenomCondIdType)0x04)
#endif


#ifndef Rte_TypeDef_Dem_PID21valueType
#define Rte_TypeDef_Dem_PID21valueType 
typedef uint8 Dem_PID21valueType;
#endif

#ifndef Rte_TypeDef_Dem_PID31valuetype
#define Rte_TypeDef_Dem_PID31valuetype 
typedef uint8 Dem_PID31valuetype;
#endif

#ifndef Rte_TypeDef_Dem_MaxDataValueType
#define Rte_TypeDef_Dem_MaxDataValueType
typedef uint8 Dem_MaxDataValueType;
#endif

#ifndef Rte_TypeDef_Dem_DTCOriginType
#define Rte_TypeDef_Dem_DTCOriginType
typedef uint8 Dem_DTCOriginType;
#endif

#ifndef Rte_TypeDef_Dem_ComponentIdType
#define Rte_TypeDef_Dem_ComponentIdType
typedef uint16 Dem_ComponentIdType;
#endif

#ifndef Rte_TypeDef_Dem_DTCKindType
#define Rte_TypeDef_Dem_DTCKindType
typedef uint8 Dem_DTCKindType;
#endif

typedef uint8 Dem_ReturnControlDTCSettingType;

typedef uint8 Dem_ReturnClearDTCType;


/* Dem_DTCKindType */
#ifndef DEM_DTC_KIND_ALL_DTCS
#define DEM_DTC_KIND_ALL_DTCS                       ((Dem_DTCKindType)0x01)
#endif
#ifndef DEM_DTC_KIND_EMISSION_REL_DTCS
#define DEM_DTC_KIND_EMISSION_REL_DTCS              ((Dem_DTCKindType)0x02)
#endif

/* Dem_DTCFormatType */
#ifndef DEM_DTC_FORMAT_OBD
#define DEM_DTC_FORMAT_OBD                          ((Dem_DTCFormatType)0U)
#endif
#ifndef DEM_DTC_FORMAT_UDS
#define DEM_DTC_FORMAT_UDS                          ((Dem_DTCFormatType)1U)
#endif
#ifndef DEM_DTC_FORMAT_J1939
#define DEM_DTC_FORMAT_J1939                        ((Dem_DTCFormatType)2U)
#endif

#ifndef DEM_DTC_ORIGIN_PRIMARY_MEMORY
#define DEM_DTC_ORIGIN_PRIMARY_MEMORY               ((Dem_DTCOriginType)0x01)
#endif
#ifndef DEM_DTC_ORIGIN_MIRROR_MEMORY
#define DEM_DTC_ORIGIN_MIRROR_MEMORY                ((Dem_DTCOriginType)0x02)
#endif
#ifndef DEM_DTC_ORIGIN_PERMANENT_MEMORY
#define DEM_DTC_ORIGIN_PERMANENT_MEMORY             ((Dem_DTCOriginType)0x03)
#endif
#ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_0
#define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_0         ((Dem_DTCOriginType)0x10)
#endif
#ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1
#define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1         ((Dem_DTCOriginType)0x11)
#endif

/* Dem_OperationCycleStateType */
#ifndef DEM_CYCLE_STATE_START
#define DEM_CYCLE_STATE_START                       ((Dem_OperationCycleStateType)0x00U)
#endif
#ifndef DEM_CYCLE_STATE_END
#define DEM_CYCLE_STATE_END                         ((Dem_OperationCycleStateType)0x01U)
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0400
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0400
typedef uint8 DataServices_ElementClass_DID_0x0400;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0402
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0402
typedef uint8 DataServices_ElementClass_DID_0x0402;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0403
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0403
typedef uint8 DataServices_ElementClass_DID_0x0403;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0404
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0404
typedef uint8 DataServices_ElementClass_DID_0x0404;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0405
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0405
typedef uint8 DataServices_ElementClass_DID_0x0405;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0406
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0406
typedef uint8 DataServices_ElementClass_DID_0x0406;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0407
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0407
typedef uint8 DataServices_ElementClass_DID_0x0407;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0408
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0408
typedef uint8 DataServices_ElementClass_DID_0x0408;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0409
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0409
typedef uint8 DataServices_ElementClass_DID_0x0409;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x040B
#define Rte_TypeDef_DataServices_ElementClass_DID_0x040B
typedef uint8 DataServices_ElementClass_DID_0x040B;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x040C
#define Rte_TypeDef_DataServices_ElementClass_DID_0x040C
typedef uint8 DataServices_ElementClass_DID_0x040C;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x040D
#define Rte_TypeDef_DataServices_ElementClass_DID_0x040D
typedef uint8 DataServices_ElementClass_DID_0x040D;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x04CF
#define Rte_TypeDef_DataServices_ElementClass_DID_0x04CF
typedef uint8 DataServices_ElementClass_DID_0x04CF;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0505
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0505
typedef uint8 DataServices_ElementClass_DID_0x0505;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0525
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0525
typedef uint8 DataServices_ElementClass_DID_0x0525;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0526
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0526
typedef uint8 DataServices_ElementClass_DID_0x0526;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0527
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0527
typedef uint8 DataServices_ElementClass_DID_0x0527;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0528
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0528
typedef uint8 DataServices_ElementClass_DID_0x0528;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0529
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0529
typedef uint8 DataServices_ElementClass_DID_0x0529;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x052B
#define Rte_TypeDef_DataServices_ElementClass_DID_0x052B
typedef uint8 DataServices_ElementClass_DID_0x052B;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x052D
#define Rte_TypeDef_DataServices_ElementClass_DID_0x052D
typedef uint8 DataServices_ElementClass_DID_0x052D;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0530
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0530
typedef uint8 DataServices_ElementClass_DID_0x0530;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0531
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0531
typedef uint8 DataServices_ElementClass_DID_0x0531;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0532
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0532
typedef uint8 DataServices_ElementClass_DID_0x0532;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0533
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0533
typedef uint8 DataServices_ElementClass_DID_0x0533;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0534
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0534
typedef uint8 DataServices_ElementClass_DID_0x0534;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0535
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0535
typedef uint8 DataServices_ElementClass_DID_0x0535;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0536
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0536
typedef uint8 DataServices_ElementClass_DID_0x0536;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0538
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0538
typedef uint8 DataServices_ElementClass_DID_0x0538;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0539
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0539
typedef uint8 DataServices_ElementClass_DID_0x0539;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x053B
#define Rte_TypeDef_DataServices_ElementClass_DID_0x053B
typedef uint8 DataServices_ElementClass_DID_0x053B;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x053C
#define Rte_TypeDef_DataServices_ElementClass_DID_0x053C
typedef uint8 DataServices_ElementClass_DID_0x053C;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0542
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0542
typedef uint8 DataServices_ElementClass_DID_0x0542;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0543
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0543
typedef uint8 DataServices_ElementClass_DID_0x0543;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0544
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0544
typedef uint8 DataServices_ElementClass_DID_0x0544;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0545
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0545
typedef uint8 DataServices_ElementClass_DID_0x0545;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0547
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0547
typedef uint8 DataServices_ElementClass_DID_0x0547;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x055A
#define Rte_TypeDef_DataServices_ElementClass_DID_0x055A
typedef uint8 DataServices_ElementClass_DID_0x055A;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x055C
#define Rte_TypeDef_DataServices_ElementClass_DID_0x055C
typedef uint8 DataServices_ElementClass_DID_0x055C;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0585
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0585
typedef uint8 DataServices_ElementClass_DID_0x0585;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0586
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0586
typedef uint8 DataServices_ElementClass_DID_0x0586;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0587
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0587
typedef uint8 DataServices_ElementClass_DID_0x0587;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0588
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0588
typedef uint8 DataServices_ElementClass_DID_0x0588;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0589
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0589
typedef uint8 DataServices_ElementClass_DID_0x0589;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x058A
#define Rte_TypeDef_DataServices_ElementClass_DID_0x058A
typedef uint8 DataServices_ElementClass_DID_0x058A;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x058C
#define Rte_TypeDef_DataServices_ElementClass_DID_0x058C
typedef uint8 DataServices_ElementClass_DID_0x058C;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x058D
#define Rte_TypeDef_DataServices_ElementClass_DID_0x058D
typedef uint8 DataServices_ElementClass_DID_0x058D;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x058E
#define Rte_TypeDef_DataServices_ElementClass_DID_0x058E
typedef uint8 DataServices_ElementClass_DID_0x058E;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x058F
#define Rte_TypeDef_DataServices_ElementClass_DID_0x058F
typedef uint8 DataServices_ElementClass_DID_0x058F;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0590
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0590
typedef uint8 DataServices_ElementClass_DID_0x0590;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0592
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0592
typedef uint8 DataServices_ElementClass_DID_0x0592;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0594
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0594
typedef uint8 DataServices_ElementClass_DID_0x0594;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0596
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0596
typedef uint8 DataServices_ElementClass_DID_0x0596;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0597
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0597
typedef uint8 DataServices_ElementClass_DID_0x0597;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0598
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0598
typedef uint8 DataServices_ElementClass_DID_0x0598;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x0599
#define Rte_TypeDef_DataServices_ElementClass_DID_0x0599
typedef uint8 DataServices_ElementClass_DID_0x0599;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x059A
#define Rte_TypeDef_DataServices_ElementClass_DID_0x059A
typedef uint8 DataServices_ElementClass_DID_0x059A;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x059B
#define Rte_TypeDef_DataServices_ElementClass_DID_0x059B
typedef uint8 DataServices_ElementClass_DID_0x059B;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x059C
#define Rte_TypeDef_DataServices_ElementClass_DID_0x059C
typedef uint8 DataServices_ElementClass_DID_0x059C;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x059D
#define Rte_TypeDef_DataServices_ElementClass_DID_0x059D
typedef uint8 DataServices_ElementClass_DID_0x059D;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x059E
#define Rte_TypeDef_DataServices_ElementClass_DID_0x059E
typedef uint8 DataServices_ElementClass_DID_0x059E;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x059F
#define Rte_TypeDef_DataServices_ElementClass_DID_0x059F
typedef uint8 DataServices_ElementClass_DID_0x059F;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05A1
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05A1
typedef uint8 DataServices_ElementClass_DID_0x05A1;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05AA
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05AA
typedef uint8 DataServices_ElementClass_DID_0x05AA;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05AB
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05AB
typedef uint8 DataServices_ElementClass_DID_0x05AB;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05B3
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05B3
typedef uint8 DataServices_ElementClass_DID_0x05B3;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05B4
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05B4
typedef uint8 DataServices_ElementClass_DID_0x05B4;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05B5
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05B5
typedef uint8 DataServices_ElementClass_DID_0x05B5;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05B6
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05B6
typedef uint8 DataServices_ElementClass_DID_0x05B6;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05B9
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05B9
typedef uint8 DataServices_ElementClass_DID_0x05B9;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05BA
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05BA
typedef uint8 DataServices_ElementClass_DID_0x05BA;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05BB
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05BB
typedef uint8 DataServices_ElementClass_DID_0x05BB;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05BC
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05BC
typedef uint8 DataServices_ElementClass_DID_0x05BC;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05BD
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05BD
typedef uint8 DataServices_ElementClass_DID_0x05BD;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05BE
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05BE
typedef uint8 DataServices_ElementClass_DID_0x05BE;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05C0
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05C0
typedef uint8 DataServices_ElementClass_DID_0x05C0;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05C1
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05C1
typedef uint8 DataServices_ElementClass_DID_0x05C1;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05C2
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05C2
typedef uint8 DataServices_ElementClass_DID_0x05C2;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05C3
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05C3
typedef uint8 DataServices_ElementClass_DID_0x05C3;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05C4
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05C4
typedef uint8 DataServices_ElementClass_DID_0x05C4;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05C5
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05C5
typedef uint8 DataServices_ElementClass_DID_0x05C5;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05C6
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05C6
typedef uint8 DataServices_ElementClass_DID_0x05C6;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05C7
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05C7
typedef uint8 DataServices_ElementClass_DID_0x05C7;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05C8
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05C8
typedef uint8 DataServices_ElementClass_DID_0x05C8;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05C9
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05C9
typedef uint8 DataServices_ElementClass_DID_0x05C9;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05CA
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05CA
typedef uint8 DataServices_ElementClass_DID_0x05CA;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05CB
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05CB
typedef uint8 DataServices_ElementClass_DID_0x05CB;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05CC
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05CC
typedef uint8 DataServices_ElementClass_DID_0x05CC;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05CD
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05CD
typedef uint8 DataServices_ElementClass_DID_0x05CD;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05CE
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05CE
typedef uint8 DataServices_ElementClass_DID_0x05CE;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05CF
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05CF
typedef uint8 DataServices_ElementClass_DID_0x05CF;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05D0
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05D0
typedef uint8 DataServices_ElementClass_DID_0x05D0;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05D1
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05D1
typedef uint8 DataServices_ElementClass_DID_0x05D1;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05D2
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05D2
typedef uint8 DataServices_ElementClass_DID_0x05D2;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05D3
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05D3
typedef uint8 DataServices_ElementClass_DID_0x05D3;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0x05D4
#define Rte_TypeDef_DataServices_ElementClass_DID_0x05D4
typedef uint8 DataServices_ElementClass_DID_0x05D4;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xCF00
#define Rte_TypeDef_DataServices_ElementClass_DID_0xCF00
typedef uint8 DataServices_ElementClass_DID_0xCF00;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xCF05
#define Rte_TypeDef_DataServices_ElementClass_DID_0xCF05
typedef uint8 DataServices_ElementClass_DID_0xCF05;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xCF06
#define Rte_TypeDef_DataServices_ElementClass_DID_0xCF06
typedef uint8 DataServices_ElementClass_DID_0xCF06;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xCF07
#define Rte_TypeDef_DataServices_ElementClass_DID_0xCF07
typedef uint8 DataServices_ElementClass_DID_0xCF07;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xDF00
#define Rte_TypeDef_DataServices_ElementClass_DID_0xDF00
typedef uint8 DataServices_ElementClass_DID_0xDF00;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xDF01
#define Rte_TypeDef_DataServices_ElementClass_DID_0xDF01
typedef uint8 DataServices_ElementClass_DID_0xDF01;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xDF02
#define Rte_TypeDef_DataServices_ElementClass_DID_0xDF02
typedef uint8 DataServices_ElementClass_DID_0xDF02;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xDF03
#define Rte_TypeDef_DataServices_ElementClass_DID_0xDF03
typedef uint8 DataServices_ElementClass_DID_0xDF03;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xDF04
#define Rte_TypeDef_DataServices_ElementClass_DID_0xDF04
typedef uint8 DataServices_ElementClass_DID_0xDF04;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xDF06
#define Rte_TypeDef_DataServices_ElementClass_DID_0xDF06
typedef uint8 DataServices_ElementClass_DID_0xDF06;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xDF09
#define Rte_TypeDef_DataServices_ElementClass_DID_0xDF09
typedef uint8 DataServices_ElementClass_DID_0xDF09;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xDF0A
#define Rte_TypeDef_DataServices_ElementClass_DID_0xDF0A
typedef uint8 DataServices_ElementClass_DID_0xDF0A;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xDF0B
#define Rte_TypeDef_DataServices_ElementClass_DID_0xDF0B
typedef uint8 DataServices_ElementClass_DID_0xDF0B;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xDF0C
#define Rte_TypeDef_DataServices_ElementClass_DID_0xDF0C
typedef uint8 DataServices_ElementClass_DID_0xDF0C;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xDF0D
#define Rte_TypeDef_DataServices_ElementClass_DID_0xDF0D
typedef uint8 DataServices_ElementClass_DID_0xDF0D;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xDF0E
#define Rte_TypeDef_DataServices_ElementClass_DID_0xDF0E
typedef uint8 DataServices_ElementClass_DID_0xDF0E;
#endif

#ifndef Rte_TypeDef_DataServices_ElementClass_DID_0xDD00
#define Rte_TypeDef_DataServices_ElementClass_DID_0xDD00
typedef uint8 DataServices_ElementClass_DID_0xDD00;
#endif

/*
************************************************************************************************************************
*    Global Variables
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Constants
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Functions
************************************************************************************************************************
*/

#endif /* RTE_DEM_TYPE_H_ */


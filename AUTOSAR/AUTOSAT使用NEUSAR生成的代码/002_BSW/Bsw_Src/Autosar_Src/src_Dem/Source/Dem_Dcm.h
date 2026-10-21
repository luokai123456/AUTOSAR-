/*
********************************************************************************
*
* File name: Dem_Dcm.h
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
* Version: 1.1
* Author/Date: ZengJX/2024.04.15
* Change: Optimize comments specifications.
* Cause: Optimization
********************************************************************************
* Version: 1.2
* Author/Date: ZengJX/2024.07.18
* Change: 1.Modify copyright information.
*         2.Fix Dem memmap issue.
* Cause: Optimization
********************************************************************************
* Version: 1.3
* Author/Date: ZengJX/2025.02.07
* Change: Modify copyright information.
* Cause: Optimization
********************************************************************************
* Version: 1.4
* Author/Date: ZengJX/2025.03.24
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 1.5
* Author/Date: ZengJX/2025.05.29
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 1.6
* Author/Date: ZengJX/2025.06.23
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
*/
#ifndef DEM_DCM_H_
#define DEM_DCM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Dcm_Cbk.h"

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
extern FUNC(Dem_DTCTranslationFormatType, DEM_CODE) Dem_DcmGetTranslationType(void);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCStatusAvailabilityMask
(
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatusMask
);
extern FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE) Dem_DcmGetStatusOfDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
);
extern FUNC(Dem_ReturnGetSeverityOfDTCType, DEM_CODE) Dem_DcmGetSeverityOfDTC
(
    uint32 DTC, 
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity
);
extern FUNC(Dem_ReturnGetFunctionalUnitOfDTCType, DEM_CODE) Dem_DcmGetFunctionalUnitOfDTC
(
    uint32 DTC, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit
);
extern FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_DcmSetDTCFilter
(
    Dem_UdsStatusByteType DTCStatusMask,
    Dem_DTCKindType DTCKind,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin,
    boolean FilterWithSeverity,
    Dem_DTCSeverityType DTCSeverityMask,
    boolean FilterForFaultDetectionCounter
);
extern FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE) Dem_DcmGetNumberOfFilteredDTC
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC
);
extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredDTC
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC, 
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatus
);
extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredDTCAndFDC
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) DTCFaultDetectionCounter
);
extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredDTCAndSeverity
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatus,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit
);
extern FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_DcmSetFreezeFrameRecordFilter
(
    Dem_DTCFormatType DTCFormat,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredRecords
);
extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredRecord
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) RecordNumber
);
extern FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE) Dem_DcmGetDTCByOccurrenceTime
(
    Dem_DTCRequestType DTCRequest,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC
);
extern FUNC(void, DEM_CODE) Dem_DcmControlDTCStatusChangedNotification
(
    boolean TriggerNotification
);
extern FUNC(Dem_ReturnDisableDTCRecordUpdateType, DEM_CODE) Dem_DcmDisableDTCRecordUpdate
(
    uint32 DTC, 
    Dem_DTCOriginType DTCOrigin
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmEnableDTCRecordUpdate(void);
extern FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE) Dem_DcmGetFreezeFrameDataByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DcmGetSizeOfFreezeFrameByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
);
extern FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE) Dem_DcmGetExtendedDataRecordByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DcmGetSizeOfExtendedDataRecordByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
);  
extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_DcmCheckClearParameter
(
    uint32 DTC, 
    Dem_DTCFormatType DTCFormat, 
    Dem_DTCOriginType DTCOrigin
);
extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_DcmClearDTC
(
    uint32 DTC, 
    Dem_DTCFormatType DTCFormat, 
    Dem_DTCOriginType DTCOrigin
);
extern FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE) Dem_DcmDisableDTCSetting
(
    uint32 DTCGroup, 
    Dem_DTCKindType DTCKind
);
extern FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE) Dem_DcmEnableDTCSetting
(
    uint32 DTCGroup,
    Dem_DTCKindType DTCKind
);
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue08
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08BufferSize
);
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue0B
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0B,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0BBufferSize
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID02
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID02value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID04
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID04value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID05
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID05value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID0C
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID0Cvalue
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID0D
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID0Dvalue
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID1C
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID1Cvalue
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID29
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID29value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID30
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID30value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID31
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID31value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID41
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID42
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID42value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID46
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID46value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID49
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID49value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4D
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Dvalue
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4E
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Evalue
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID91
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID91value
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfOBDFreezeFrame
(
    uint8 PID,
    uint8 DataElementIndexOfPID,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCOfOBDFreezeFrame
(
    uint8 FrameNumber,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    Dem_DTCFormatType DTCFormat
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetAvailableOBDMIDs
(
    uint8 Obdmid, 
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) Obdmidvalue
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetNumTIDsOfOBDMID
(
    uint8 Obdmid, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) numberOfTIDs
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTRData
(
    uint8 Obdmid,
    uint8 TIDindex,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) TIDvalue,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) UaSID,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Testvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Lowlimvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Upplimvalue
);
#endif
extern FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE) Dem_DcmGetAllExtendedDataRecordByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
extern FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DcmGetSizeOfAllExtendedDataRecordByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
);
#define DEM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif /* DEM_DCM_H_ */


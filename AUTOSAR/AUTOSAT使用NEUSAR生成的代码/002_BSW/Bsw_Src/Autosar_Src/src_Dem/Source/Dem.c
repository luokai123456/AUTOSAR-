/*
********************************************************************************
*
* File name: Dem.c
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
* Author/Date: ZhiDX/2021.03.18
* Change: Function Dem_SetEventAvailable should not consider event availability.
* Cause: Bugfix
********************************************************************************
* Version: 1.2
* Author/Date: ZhiDX/2021.03.23
* Change: DEM_VAR_NO_INIT replace DEM_VAR_NOINIT.
* Cause: Bugfix
********************************************************************************
* Version: 1.3
* Author/Date: ZhiDX/2021.04.12
* Change: 1.Add nvm block data initialization in Dem_Init.
*         2.Return value optimizaiton of Dem_ReportErrorStatus/Dem_ResetEventDebounceStatus.
* Cause: Bugfix
********************************************************************************
* Version: 1.4
* Author/Date: ZhiDX/2021.04.15
* Change: Logic and should be used for ger all extended data when judge 
*         extended data record number.
* Cause: Bugfix
********************************************************************************
* Version: 1.5
* Author/Date: ZhiDX/2021.04.19
* Change: In IF Dem_DcmGetNextFilteredDTCAndFDC and 
*         Dem_DcmGetNextFilteredDTCAndSeverity, wrong condition check used.
* Cause: Bugfix
********************************************************************************
* Version: 1.6
* Author/Date: ZhiDX/2021.04.20
* Change: Remove enable/storage condition ID avalibility check.
* Cause: Optimizaiton
********************************************************************************
* Version: 1.7
* Author/Date: ZhiDX/2021.06.08
* Change: Replace Fim_DemInit with FiM_DemInit.
* Cause: Bugfix
********************************************************************************
* Version: 1.8
* Author/Date: ZhiDX/2021.06.25
* Change: Set Nvm Blocks update request during Shutdown.
* Cause: Bugfix
********************************************************************************
* Version: 1.9
* Author/Date: ZhiDX/2021.07.14
* Change: Fim_DemInit should be called after Dem initialized.
* Cause: Bugfix
********************************************************************************
* Version: 1.10
* Author/Date: ZhiDX/2021.07.28
* Change: Missing null pointer judgement in Dem_GetIUMPRDenCondition.
* Cause: Bugfix
********************************************************************************
* Version: 1.11
* Author/Date: ZhiDX/2021.08.23
* Change: OBD PIDs implementation.
* Cause: Implementation
********************************************************************************
* Version: 1.12
* Author/Date: ZhiDX/2021.09.01
* Change: Remove Compile warnings and polyspace warnings.
* Cause: Optimization
********************************************************************************
* Version: 1.13
* Author/Date: ZhiDX/2021.09.18
* Change: Missing return value of getting DTC status, wrong input parameter of
*         getting all extended record data.
* Cause: Bugfix
********************************************************************************
* Version: 3.0
* Author/Date: ZhiDX/2021.11.15
* Change: Implementation of event combination.
* Cause: Implementation
********************************************************************************
* Version: 3.1
* Author/Date: ZhiDX/2021.11.26
* Change: Remove compile warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: ZhiDX/2021.12.23
* Change: Masking the invalid bit of DTC status byte for Dcm.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: ZhiDX/2022.02.18
* Change: Remove Dem_init in main function and Nvm request in Dem_PreInit,
*         all Nvm blocks should be readout during system start-up phase.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: MengY/2022.06.16
* Change: Remove warning, defines variables, but does not use them.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: FanHT/2022.09.15
* Change: Clear static code analysis warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: FanHT/2022.11.18
* Change: Calibration
* Cause: Implementation
********************************************************************************
* Version: 3.7
* Author/Date: FanHT/2023.01.31
* Change: The second calibration scheme generates Dem_PBcfg.c and Dem_PBcfg.h.
* Cause: Implementation
********************************************************************************
* Version: 3.8
* Author/Date: FanHT/2023.03.20
* Change: Clear QAC analysis warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: WangYS/2023.04.01
* Change: Add J1939 API:Dem_J1939DcmSetDTCFilter
*                       Dem_J1939DcmGetNumberOfFilteredDTC
*                       Dem_J1939DcmGetNextFilteredDTC
*                       Dem_J1939DcmFirstDTCwithLampStatus
*                       Dem_J1939DcmGetNextDTCwithLampStatus
*                       Dem_J1939DcmClearDTC.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: WangYS/2023.04.03
* Change: Modify macro switch name.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: WangYS/2023.04.06
* Change: Function Dem_GetDTCOfEvent adds the condition of J1939.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: WangYS/2023.04.26
* Change: 1.Add DEM_CFG_J1939SUPPORT macro switch limit.
*         2.Modify Dem_EvtMemIdx initialization parameter in J1939DcmClearDTC.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: WangYS/2023.05.05
* Change: 1.CCOREEDBUG-2807,Modify the judgment logic for obtaining DTC.
*         2.CCOREEDBUG-2842,Modify the judgment criteria for calling function
*           J1939Dcm_DemTriggerOnDTCStatus.
*         3.CCOREEDBUG-2814,Distinguish between DM3 and DM11.
* Cause: Bugfix
********************************************************************************
* Version: 3.14
* Author/Date: WangYS/2023.05.09
* Change: CCOREEDBUG-2821,Modify Dem_J1939DcmClearDTC return value logic.
* Cause: Bugfix
********************************************************************************
* Version: 3.15
* Author/Date: WangYS/2023.05.12
* Change: CCOREEDBUG-2963,Modify Modifying DM11 to obtain data above issues.
* Cause: Bugfix
********************************************************************************
* Version: 3.16
* Author/Date: WangYS/2023.05.14
* Change: Modifying DM11 to obtain data above issues.
* Cause: Bugfix
********************************************************************************
* Version: 3.17
* Author/Date: WangYS/2023.05.14
* Change: Modify the method of obtaining historical faults.
* Cause: Bugfix
********************************************************************************
* Version: 3.18
* Author/Date: WangYS/2023.05.25
* Change: CCOREEDBUG-3001，Increase the judgment of multiple events associated 
*         with the same DTC.
* Cause: Bugfix
********************************************************************************
* Version: 3.19
* Author/Date: WangYS/2023.05.29
* Change: 1.Optimize J1939 partial code specifications.
*         2.Adjust code according to code review.
* Cause: Optimization
********************************************************************************
* Version: 3.20
* Author/Date: WangYS/2023.05.29
* Change: 1.Adjust code according to code review.
*         2.Variable flag type changed to Boolean.
* Cause: Optimization
********************************************************************************
* Version: 3.21
* Author/Date: WangYS/2023.05.30
* Change: CCOREEDBUG-3180，3181.Modifying function Dem_J1939DcmClearDTC.
* Cause: Bugfix
********************************************************************************
* Version: 3.22
* Author/Date: WangYS/2023.06.02
* Change: Modifying function Dem_J1939DcmClearDTC logic for clearing DTC.
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date: WangYS/2023.06.05
* Change: CCOREEDBUG-3218，Modifying function Dem_J1939DcmClearDTC logic for
*         clearing DTC.
* Cause: Bugfix
********************************************************************************
* Version: 3.24
* Author/Date: ZhangF/2023.08.14
* Change: Fix compile warning.
* Cause: Update.
********************************************************************************
* Version: 3.25
* Author/Date: ZhangF/2023.08.25
* Change: Add memory map to local static variables.
* Cause: Update.
********************************************************************************
* Version: 3.26
* Author/Date: ZhangF/2023.10.07
* Change: Add the global calibration array for Dem event calibration.
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date: ZhangF/2023.10.09
* Change: Fix compile warning.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: ZengJX/2023.10.10
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.29
* Author/Date: ZengJX/2023.10.25
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.30
* Author/Date: ZengJX/2024.01.02
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.31
* Author/Date: ZengJX/2024.02.05
* Change: Add macro DEM_CFG_FIMSUPPORT for function FiM_DemInit.
* Cause: Bugfix
********************************************************************************
* Version: 3.32
* Author/Date: ZengJX/2024.03.18
* Change: Modify P2CONST member labels.
* Cause: Optimization
********************************************************************************
* Version: 3.33
* Author/Date: ZengJX/2024.04.01
* Change: Modify P2VAR member labels.
* Cause: Optimization
********************************************************************************
* Version: 3.34
* Author/Date: ZengJX/2024.04.15
* Change: Optimize comments specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.35
* Author/Date: ZengJX/2024.05.07
* Change: Modify the AvailabilityMask, AvailabilityMask is only used for
*         UDS 0x19 service.
* Cause: Optimization
********************************************************************************
* Version: 3.36
* Author/Date: ZengJX/2024.07.05
* Change: 1.Modify DEM_SET_OPCYC_REQ_STATE to Dem_OperCycleEnterQueue() in
*           function Dem_SetOperationCycleState().
*         2.Add trigger condition in Dem_SetStorageCondition() and
*           Dem_SetEnablCondition().
* Cause: Optimization
********************************************************************************
* Version: 3.37
* Author/Date: ZengJX/2024.07.18
* Change: 1.Modify copyright information.
*         2.Fix Dem memmap issue.
* Cause: Optimization
********************************************************************************
* Version: 3.38
* Author/Date: ZengJX/2024.10.21
* Change: Modify the calculation of the OBD mid available mask in the function
*         Dem_DcmGetAvailableOBDMIDs.
* Cause: Optimization
********************************************************************************
* Version: 3.39
* Author/Date: ZengJX/2024.10.21
* Change: Delete the check for whether the Tid value is greater than 0, the range
*         of Tid value is in [0, 255].
* Cause: Bugfix
********************************************************************************
* Version: 3.40
* Author/Date: ZengJX/2024.11.13
* Change: Delete the break statement called in function Dem_DcmGetAvailableOBDMIDs,
*         avoiding the loop checking is incomplete.
* Cause: Bugfix
********************************************************************************
* Version: 3.41
* Author/Date: ZengJX/2024.11.19
* Change: When the events availability changed, Dem should recalculate whether
*         the suppression of the related DTC needs to be modified.
* Cause: Bugfix
********************************************************************************
* Version: 3.42
* Author/Date: ZengJX/2024.12.06
* Change: When getting the PID21 data in the function Dem_GetDataOfPID21, add
*         checking for endianness.
* Cause: Bugfix
********************************************************************************
* Version: 3.43
* Author/Date: ZengJX/2025.02.07
* Change: Modify copyright information.
* Cause: Optimization
********************************************************************************
* Version: 3.44
* Author/Date: ZengJX/2025.02.08
* Change: Add global variable Dem_DiagProcDTCIdx to record the processed DTC index
*         of diagnostic service.
* Cause: Optimization
********************************************************************************
* Version: 3.45
* Author/Date: ZengJX/2025.03.27
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.46
* Author/Date: ZengJX/2025.05.29
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.47
* Author/Date: ZengJX/2025.06.09
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Dem.h"
#include "Dem_Event.h"
#include "Dem_Dcm.h"
#if(DEM_CFG_DEVERRORDETECT == STD_ON)
#include "Det.h"
#endif
#if(DEM_CFG_TRIGGERDCMREPORT == STD_ON)
#include "Dcm.h"
#endif
#if((DEM_CFG_FIMSUPPORT == STD_ON) || (DEM_CFG_TRIGGERFIMREPORT == STD_ON))
#include "FiM.h"
#endif
#include "NvM.h"
#if(DEM_CFG_TRIGGERDLTREPORT == STD_ON)
#include "Dlt.h"
#endif
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
#if(( DEM_CFG_J1939CLEARDTCSUPPORT == STD_ON ) && ( DEM_CFG_J1939SUPPORT == STD_ON ))
#define DEM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
static VAR(uint8, DEM_VAR_INIT) Dem_StartEvtMemIdx = DEM_INIT_ONE;
static VAR(uint16, DEM_VAR_INIT) Dem_StartDtcIdx = DEM_INIT_ONE;
#define DEM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#endif

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
static FUNC(void, DEM_CODE) Dem_Det_ErrorReport
(
    uint8 apiId,
    uint8 errorId
);
#define DEM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define DEM_START_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
VAR(Dem_Manage_st, DEM_VAR_NO_INIT) Dem_Manage;

/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
VAR(Dem_EventMemoryStatus_st, DEM_VAR_NO_INIT) Dem_EventMemoryStatus;
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
VAR(Dem_EventMemoryStatus_st, DEM_VAR_NO_INIT) Dem_DummyEventMemoryStatus;

/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
VAR(Dem_EventMemoryInfo_st, DEM_VAR_NO_INIT) Dem_PrimaryEventMemoryInfo;
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_ONE)
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
VAR(Dem_EventMemoryInfo_st, DEM_VAR_NO_INIT) Dem_User0EventMemoryInfo;
#endif
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_TWO)
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
VAR(Dem_EventMemoryInfo_st, DEM_VAR_NO_INIT) Dem_User1EventMemoryInfo;
#endif
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
VAR(Dem_EventMemoryInfo_st, DEM_VAR_NO_INIT) Dem_DummyEventMemoryInfo;

/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
VAR(Dem_EventMemoryEntry_st, DEM_VAR_NO_INIT) Dem_PrimaryEventMemoryEntry[DEM_CFG_PRIMARY_MAX_NUMBER_EVENT_ENTRY];
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_ONE)
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
VAR(Dem_EventMemoryEntry_st, DEM_VAR_NO_INIT) Dem_User0EventMemoryEntry[DEM_CFG_USER0_MAX_NUMBER_EVENT_ENTRY];
#endif
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_TWO)
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
VAR(Dem_EventMemoryEntry_st, DEM_VAR_NO_INIT) Dem_User1EventMemoryEntry[DEM_CFG_USER1_MAX_NUMBER_EVENT_ENTRY];
#endif
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
VAR(Dem_EventMemoryEntry_st, DEM_VAR_NO_INIT) Dem_DummyEventMemoryEntry;

#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
VAR(Dem_PermanentEventMemoryEntry_st, DEM_VAR_NO_INIT) Dem_PermanentEventMemoryEntry;
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
VAR(Dem_PermanentEventMemoryEntry_st, DEM_VAR_NO_INIT) Dem_DummyPermanentEventMemoryEntry;
#endif

#define DEM_STOP_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define DEM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
P2VAR(Dem_EventMemoryInfo_st, DEM_VAR_INIT, DEM_APPL_DATA) Dem_EventMemoryInfo[DEM_CFG_EVENT_MEMORY_NUM] = 
{
    &Dem_PrimaryEventMemoryInfo
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_ONE)
   ,&Dem_User0EventMemoryInfo
#endif
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_TWO)
   ,&Dem_User1EventMemoryInfo
#endif
};

/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
P2VAR(Dem_EventMemoryEntry_st, DEM_VAR_INIT, DEM_APPL_DATA) Dem_EventMemoryEntry[DEM_CFG_EVENT_MEMORY_NUM] = 
{
    &Dem_PrimaryEventMemoryEntry[0]
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_ONE)
   ,&Dem_User0EventMemoryEntry[0]
#endif
#if(DEM_CFG_EVENT_MEMORY_NUM > DEM_BYTE_TWO)
   ,&Dem_User1EventMemoryEntry[0]
#endif
};

/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
VAR(uint16, DEM_VAR_INIT) Dem_DiagProcDTCIdx = DEM_INIT_ZERO;

#define DEM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
* Function Name: Dem_Det_ErrorReport
*
* Explanation: Dem used det error report function.
*
* param: apiId: Application id.
*        errorId: Error id.
*
* retval: None
********************************************************************************
*/
static FUNC(void, DEM_CODE) Dem_Det_ErrorReport
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 apiId, 
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId
)
{
#if(DEM_CFG_DEVERRORDETECT == STD_ON)
     /* Error detected. */
    if(errorId != DEM_E_NO_ERROR)
    {
        /* Report error to det. */
        (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID, apiId, errorId);
    }
#else
    {
        DEM_DUMMY_STATEMENT(apiId);
        DEM_DUMMY_STATEMENT(errorId);
    }
#endif /* DEM_DEV_ERROR_DETECT == STD_ON */

}

/*
********************************************************************************
* Function Name: Dem_GetVersionInfo
*
* Explanation: Returns the version information of this module.
*
* param: versioninfo: Pointer to where to store the version 
*                     information of this module.
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DEM_APPL_DATA) versioninfo  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;

    if(versioninfo != NULL_PTR)
    {

#if( DEM_CFG_VERSIONINFOAPI == STD_ON )
        /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
        versioninfo->moduleID = DEM_MODULE_ID;
        versioninfo->vendorID = DEM_VENDOR_ID;
        versioninfo->sw_major_version = DEM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = DEM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = DEM_SW_PATCH_VERSION;
#endif /* DEM_CFG_VERSIONINFOAPI == STD_ON */

    }
    else
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = DEM_E_PARAM_POINTER;
    }
    
    Dem_Det_ErrorReport(DEM_GETVERSIONINFO_APIID, errorId);
}

/*
********************************************************************************
* Function Name: Dem_PreInit
*
* Explanation: Initializes the internal states necessary to 
*              process events reported by BSW-modules.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_PreInit(void)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    uint8 errorId = DEM_E_NO_ERROR;

    Dem_EventPreInit();
    
    Dem_Manage.initSt = DEM_MODULE_STATE_PREINIT;
    
    Dem_Det_ErrorReport(DEM_PREINIT_APIID, errorId);
}

/*
********************************************************************************
* Function Name: Dem_Init
*
* Explanation: Initializes or reinitializes this module.
*
* param: ConfigPtr: Pointer to the configuration set in VARIANT-POSTBUILD.
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_Init
(
    P2CONST(Dem_ConfigType, AUTOMATIC, DEM_APPL_CONST) ConfigPtr
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    uint8 errorId = DEM_E_NO_ERROR;

    DEM_UNUSED_PARAMETER(ConfigPtr);

    Dem_EventNvmBlockInit();

    Dem_EventIndicatorInit();
    
    Dem_EventOperCycleInit();
    
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)   
    Dem_ObdInit();
#endif
    
    /* Process BSW events reported during pre-init */
    Dem_EventQueueProcBSW();
    Dem_EventQueueProcess();
    
    Dem_Manage.initSt = DEM_MODULE_STATE_INITED;

/* FiM module is supported when DemFiMSupport is configured */
#if((DEM_CFG_FIMSUPPORT == STD_ON) || (DEM_CFG_TRIGGERFIMREPORT == STD_ON))
    FiM_DemInit();
#endif

    Dem_Det_ErrorReport(DEM_INIT_APIID, errorId);
}

/*
********************************************************************************
* Function Name: Dem_Shutdown
*
* Explanation: Shuts down this module.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_Shutdown(void)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    uint8 errorId = DEM_E_NO_ERROR;

    Dem_EventOperCycleDeInit();
    Dem_EventMemoryNvmShutDown();
    Dem_Manage.initSt = DEM_MODULE_STATE_SHUTDOWN;
    
    Dem_Det_ErrorReport(DEM_SHUTDOWN_APIID, errorId);
}

/*
********************************************************************************
* Function Name: Dem_ReportErrorStatus
*
* Explanation: Queues the reported events from the BSW modules (not DEM_E_UNINIT).
*
* param: EventId: Identification of an event by assigned Event ID.
*        EventStatus: Monitor test result.
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_ReportErrorStatus
(
    Dem_EventIdType EventId, 
    Dem_EventStatusType EventStatus
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 evtIdx;

    if((DEM_MODULE_STATE_INITED == Dem_Manage.initSt) || 
       (DEM_MODULE_STATE_PREINIT == Dem_Manage.initSt) ||
       (DEM_MODULE_STATE_SHUTDOWN == Dem_Manage.initSt))
    {
        if((EventId > DEM_INIT_ZERO) && (EventId <= DEM_CFG_EVENT_ID_MAX))
        {
            evtIdx = Dem_CfgEventIdTableIndex[EventId];
            if((Dem_CfgEventTable[evtIdx].acEvtKind != DEM_EVENT_KIND_BSW) ||
               (EventStatus > DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED))
            {
                errorId = DEM_E_PARAM_DATA;
            }
            else
            {
                (void)Dem_EventStatusReport(evtIdx, EventStatus);
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_REPORTERRORSTATUS_APIID, errorId);

    return;
}

#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
/*
********************************************************************************
* Function Name: Dem_SetEventAvailable
*
* Explanation: Set the available status of a specific Event.
*
* param: EventId: Identification of an event by assigned EventId.
*        AvailableStatus: This parameter specifies whether the respective
*                        Event shall be available (TRUE) or not (FALSE).
*
* retval: E_OK: Operation was successful.
*         E_NOT_OK: change of available status not accepted.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventAvailable
(
    Dem_EventIdType EventId, 
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    boolean AvailableStatus
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    uint16 evtIdx = EventId;
    uint16 evtCnt;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if(DEM_MODULE_STATE_PREINIT <= Dem_Manage.initSt)
    {
        if((EventId > DEM_INIT_ZERO) &&
           (EventId <= DEM_CFG_EVENT_ID_MAX))
        {
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if((evtIdx > DEM_INIT_ZERO) && (evtIdx <= DEM_CFG_EVENT_NUM))
            {
                if((E_NOT_OK == Dem_EventMemoryEntryExist(evtIdx)) && 
                    (FALSE == DEM_GET_UDS_STATUS_TF(evtIdx)))
                {
                    /* Set event available */
                    DEM_SET_AVAIL(evtIdx, AvailableStatus);

                    if(FALSE == AvailableStatus)
                    {
                        for(evtCnt = DEM_INIT_ONE; evtCnt <= DEM_CFG_EVENT_NUM; evtCnt++)
                        {
                            /* Check whether existing the same DTC related events is available. */
                            if((Dem_CfgEvtDtcIdx[evtIdx] == Dem_CfgEvtDtcIdx[evtCnt]) &&
                               (TRUE == DEM_GET_AVAIL(evtCnt)))
                            {
                                break;
                            }
                        }
                        /* All the same DTC related events' availability is FALSE. */
                        if(evtCnt > DEM_CFG_EVENT_NUM)
                        {
                            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                            DEM_SET_DTCSUPPRESSION(Dem_CfgEvtDtcIdx[evtIdx], TRUE);
                        }
                        /* Change the event's status to 0x00 when event changed its state to unavailable. */
                        DEM_SET_UDS_STATUS(evtIdx, DEM_INIT_ZERO);
                    }
                    else
                    {
                        DEM_SET_UDS_STATUS(evtIdx, DEM_EVENT_DTC_STATUS_INIT);
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                        DEM_SET_DTCSUPPRESSION(Dem_CfgEvtDtcIdx[evtIdx], FALSE);
                    }
#if( DEM_CFG_CALIBSUPPORT == STD_ON )
                    DEM_SET_INITAVAIL(evtIdx, DEM_EVTAVAIL_CAL(evtIdx));
#endif                    
                    returnValue = E_OK;
                }
            }
        }
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }

    Dem_Det_ErrorReport(DEM_SETEVENTAVAILABLE_APIID, errorId);

    return returnValue;
}
#endif

/*
********************************************************************************
* Function Name: Dem_SetEventStatus
*
* Explanation: Processes the events reported by SW-Cs via RTE.
*
* param: EventId: Identification of an event by assigned EventId.
*        EventStatus: Monitor test result.
*
* retval: E_OK: set of event status was successful.
*         E_NOT_OK: set of event status failed or could not be accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus
(
    Dem_EventIdType EventId, 
    Dem_EventStatusType EventStatus
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 evtIdx;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((EventId > DEM_INIT_ZERO) && (EventId <= DEM_CFG_EVENT_ID_MAX))
        {
            evtIdx = Dem_CfgEventIdTableIndex[EventId];
            if((Dem_CfgEventTable[evtIdx].acEvtKind != DEM_EVENT_KIND_SWC) ||
               (EventStatus > DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED))
            {
                errorId = DEM_E_PARAM_DATA;
            }
            else
            {
                returnValue = Dem_EventStatusReport(evtIdx, EventStatus);
            }
        }
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_SETEVENTSTATUS_APIID, errorId);

    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_ResetEventDebounceStatus
*
* Explanation: Control the internal debounce counter/timer by BSW modules and SWCs.
*
* param: EventId: Identification of an event by assigned EventId.
*        DebounceResetStatus: Freeze or reset the internal debounce counter/timer
*                             of the specified event.
*
* retval: E_OK: Operation was successful.
*         E_NOT_OK: Only on development error.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventDebounceStatus
(
    Dem_EventIdType EventId,
    Dem_DebounceResetStatusType DebounceResetStatus
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 evtIdx;

    if((DEM_MODULE_STATE_INITED == Dem_Manage.initSt) || 
       (DEM_MODULE_STATE_PREINIT == Dem_Manage.initSt) ||
       (DEM_MODULE_STATE_SHUTDOWN == Dem_Manage.initSt))
    {
        if((EventId > DEM_INIT_ZERO) && (EventId <= DEM_CFG_EVENT_ID_MAX) &&
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO))
        {
            evtIdx = Dem_CfgEventIdTableIndex[EventId];
            if((DEM_DEBOUNCE_STATUS_FREEZE != DebounceResetStatus) && 
               (DEM_DEBOUNCE_STATUS_RESET != DebounceResetStatus))
            {
                errorId = DEM_E_PARAM_DATA;
            }
            else if((DEM_MODULE_STATE_INITED != Dem_Manage.initSt) && 
                    (TRUE == Dem_CfgDebCounterTable[Dem_CfgEvtDebCntIdx[evtIdx]].acDebCntStor))
            {
                errorId = DEM_E_WRONG_CONDITION;
            }
            else
            {
                returnValue = Dem_EventDebounceStatus(evtIdx, DebounceResetStatus);
            }
            
        }
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_RESETEVENTDEBOUNCESTATUS_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_ResetEventStatus
*
* Explanation: Resets the event failed status (not DEM_E_UNINIT)
*
* param: EventId: Identification of an event by assigned EventId.
*
* retval: E_OK: reset of event status was successful.
*         E_NOT_OK: Reset of event status failed or is not allowed,
*                   because the event is already tested in this
*                   operation cycle.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventStatus
(
    Dem_EventIdType EventId
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 evtIdx;

    if((EventId > DEM_INIT_ZERO) &&
       (EventId <= DEM_CFG_EVENT_ID_MAX) &&
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
       (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO) &&
       (TRUE == DEM_GET_AVAIL(Dem_CfgEventIdTableIndex[EventId])))
#else
       (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO))
#endif
    {
        evtIdx = Dem_CfgEventIdTableIndex[EventId];
        if(TRUE == DEM_GET_UDS_STATUS_TNCTOC(evtIdx))
        {
            DEM_RESET_UDS_STATUS_TF(evtIdx);
            if((DEM_DEBOUNCE_COUNTER_BASED == Dem_CfgEvtDebCntCls[evtIdx]) ||
               (DEM_DEBOUNCE_TIMER_BASED == Dem_CfgEvtDebCntCls[evtIdx]))
            {
                DEM_SET_DEBCNT(evtIdx, DEM_DEBOUNCE_COUNTER_ZERO);
                DEM_SET_FDCCNT(evtIdx, DEM_INIT_ZERO);
                DEM_SET_DEBTIME(evtIdx, DEM_DEBOUNCE_COUNTER_ZERO);
                DEM_SET_DEBTIMER_BUFFER(evtIdx, DEM_EVENT_STATUS_NONE);
                DEM_SET_DEBOUNCE_STATUS(evtIdx, DEM_DEBOUNCE_STATUS_RESET);
            }
            returnValue = E_OK;
        }
    }
    else
    {
        errorId = DEM_E_PARAM_DATA;
    }
    
    Dem_Det_ErrorReport(DEM_RESETEVENTSTATUS_APIID, errorId);

    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_SetOperationCycleState
*
* Explanation: Sets an operation cycle state.
*
* param: OperationCycleId: Identification of operation cycle, like power cycle,driving cycle.
*        CycleState:New operation cycle state: (re-)start or end.
*
* retval: E_OK: Set of operation cycle was accepted and will be handled asynchronously.
*         E_NOT_OK: Set of operation cycle was rejected.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetOperationCycleState
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint8 OperationCycleId, 

    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    Dem_OperationCycleStateType CycleState
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 opcycIdx;

    /* Check if Dem module status is inited. */
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(CycleState > DEM_CYCLE_STATE_END)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_DATA;
        }
        else
        {
            for(opcycIdx = DEM_BYTE_ONE; opcycIdx <= DEM_CFG_OPCYC_NUM; opcycIdx++)
            {
                if(OperationCycleId == Dem_CfgOperationCycleTable[opcycIdx].acCycleId)
                {
                    if(DEM_CYCLE_STATE_START == CycleState)
                    {
                        /* Check if operation cycle autostart is configured. */
                        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:USELESS_IF [JUstified:Unset] "NSCA_Polyspace_Common_UselessIf" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                        if(FALSE == Dem_CfgOperationCycleTable[opcycIdx].acCycleStartType)
                        {
                            if(DEM_CYCLE_STATE_START == DEM_GET_OPCYC_STATE(opcycIdx))
                            {
                                /* Push into Operation Cycle queue. */
                                Dem_OperCycleEnterQueue(opcycIdx, DEM_OPERATION_CYCLE_RESTART);
                            }
                            else
                            {
                                /* Push into Operation Cycle queue. */
                                Dem_OperCycleEnterQueue(opcycIdx, DEM_OPERATION_CYCLE_START);
                            }
                            returnValue = E_OK;
                        }
                    }
                    else
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    {
                        if(DEM_CYCLE_STATE_END != DEM_GET_OPCYC_STATE(opcycIdx))
                        {
                            /* Push into Operation Cycle queue. */
                            Dem_OperCycleEnterQueue(opcycIdx, DEM_OPERATION_CYCLE_END);
                            returnValue = E_OK;
                        }
                    }
                    break;
                }
            }

            if(opcycIdx > DEM_CFG_OPCYC_NUM)
            {
                errorId = DEM_E_PARAM_DATA;
            }
        }
    }
    else
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_SETOPERATIONCYCLESTATE_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_GetOperationCycleState
*
* Explanation: Gets information about the status of a specific operation cycle.
*
* param: OperationCycleId: Identification of operation cycle, like power cycle,driving cycle.
*        CycleState: Cycle status information.
*
* retval: E_OK: Read out of operation cycle was successful.
*         E_NOT_OK: Read out of operation cycle failed.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetOperationCycleState
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint8 OperationCycleId, 
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(Dem_OperationCycleStateType, AUTOMATIC, DEM_APPL_DATA) CycleState
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 opcycIdx;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(CycleState != NULL_PTR)
        {
            for(opcycIdx = DEM_BYTE_ONE; opcycIdx <= DEM_CFG_OPCYC_NUM; opcycIdx++)
            {
                if(OperationCycleId == Dem_CfgOperationCycleTable[opcycIdx].acCycleId)
                {
                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                    *CycleState = DEM_GET_OPCYC_STATE(opcycIdx);
                    returnValue = E_OK;
                    break;
                }
            }

            if(opcycIdx > DEM_CFG_OPCYC_NUM)
            {
                errorId = DEM_E_PARAM_DATA;
            }
        }
        else
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_GETOPERATIONCYCLESTATE_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_SetAgingCycleState
*
* Explanation: Triggers the next aging cycle state.
*
* param: OperationCycleId:Identification of aging cycle.
*
* retval: E_OK: set of aging cycle was successful.
*         E_NOT_OK: set of aging cycle failed.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetAgingCycleState
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint8 OperationCycleId
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        returnValue = Dem_SetOperationCycleState(OperationCycleId, 
                                               DEM_CYCLE_STATE_START);
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_SETAGINGCYCLESTATE_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_SetWIRStatus
*
* Explanation: Sets the WIR status bit via failsafe SW-Cs.
*
* param: EventId: Identification of an event by assigned EventId.
*        WIRStatus: Requested status of event related WIR-bit.
*
* retval: E_OK: The request is accepted.
*         E_NOT_OK: not be accepted (e.g. disabled controlDTCSetting) 
*                   and should be repeated.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetWIRStatus
(
    Dem_EventIdType EventId,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */ 
    boolean WIRStatus
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 evtIdx;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((EventId > DEM_INIT_ZERO) &&
           (EventId <= DEM_CFG_EVENT_ID_MAX) &&
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO) &&
           (TRUE == DEM_GET_AVAIL(Dem_CfgEventIdTableIndex[EventId])))
#else
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO))
#endif
        {
            evtIdx = Dem_CfgEventIdTableIndex[EventId];
            if(E_NOT_OK == Dem_EventCheckDtcSettingDisable(evtIdx))
            {
                if(TRUE == WIRStatus)
                {
                    DEM_SET_UDS_STATUS_WIR(evtIdx);
#if(DEM_CFG_WIRSLCSUPPORT == STD_ON)
                    DEM_SET_STATUS_INDI_WIRSLC(evtIdx);
#endif
                }
                else
                {
                    DEM_RESET_UDS_STATUS_WIR(evtIdx);
#if(DEM_CFG_WIRSLCSUPPORT == STD_ON)
                    DEM_RESET_STATUS_INDI_WIRSLC(evtIdx);
#endif
                }
                returnValue = E_OK;
            }
        }
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_SETWIRSTATUS_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_GetComponentFailed
*
* Explanation: Gets the failed status of a DemComponent.
*
* param: ComponentId: Identification of a DemComponent
*        ComponentFailed:TRUE: failed.
*                        FALSE: not failed
*
* retval: E_OK: getting "ComponentFailed" was successful.
*         E_NOT_OK: getting "ComponentFailed" was not successful.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetComponentFailed
(
    Dem_ComponentIdType ComponentId, 
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) ComponentFailed  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    
    DEM_DUMMY_STATEMENT(ComponentId);
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == ComponentFailed)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
#if(DEM_CFG_COMP_NUM > DEM_INIT_ZERO)
            if((ComponentId > DEM_INIT_ZERO) && 
               (ComponentId <= DEM_CFG_COMP_NUM) &&
               (TRUE == DEM_GET_COMP_AVAILABLE(ComponentId)))
            {
                /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                *ComponentFailed = DEM_GET_COMP_FAILED_STATUS(ComponentId);
                returnValue = E_OK;
            }
            else
#endif
            {
                errorId = DEM_E_PARAM_DATA;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_GETCOMPONENTFAILED_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_GetEventStatus
*
* Explanation: Gets the current extended event status of an event.
*
* param: EventId: Identification of an event by assigned EventId.
*        EventStatusByte: UDS dtcCode status byte of the requested event.
*
* retval: E_OK: Get of event status was successful.
*         E_NOT_OK: Get of event status failed.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventStatus
(
    Dem_EventIdType EventId, 
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) EventStatusByte
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */  
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 evtIdx;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((EventId > DEM_INIT_ZERO) &&
           (EventId <= DEM_CFG_EVENT_ID_MAX) &&
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO) &&
           (TRUE == DEM_GET_AVAIL(Dem_CfgEventIdTableIndex[EventId])))
#else
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO))
#endif
        {
            if(NULL_PTR == EventStatusByte)
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                errorId = DEM_E_PARAM_POINTER;
            }
            else
            {
                evtIdx = Dem_CfgEventIdTableIndex[EventId];
                *EventStatusByte = DEM_GET_UDS_STATUS(evtIdx);
                returnValue = E_OK;
            }
        }
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_GETEVENTSTATUS_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_GetEventFailed
*
* Explanation: Gets the event failed status of an event.
*
* param: EventId: Identification of an event by assigned EventId.
*        EventFailed: TRUE - Last Failed.
*                     FALSE - not Last Failed.
*
* retval: E_OK: Get of "EventFailed" was successful.
*         E_NOT_OK: Get of "EventFailed" was not successful.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFailed
(
    Dem_EventIdType EventId, 
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) EventFailed
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */    
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 evtIdx;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((EventId > DEM_INIT_ZERO) &&
           (EventId <= DEM_CFG_EVENT_ID_MAX) &&
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO) &&
           (TRUE == DEM_GET_AVAIL(Dem_CfgEventIdTableIndex[EventId])))
#else
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO))
#endif
        {
            if(NULL_PTR == EventFailed)
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                errorId = DEM_E_PARAM_POINTER;
            }
            else
            {
                evtIdx = Dem_CfgEventIdTableIndex[EventId];
                *EventFailed = (boolean)DEM_GET_UDS_STATUS_TF(evtIdx);
                returnValue = E_OK;
            }
        }
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_GETEVENTFAILED_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_GetEventTested
*
* Explanation: Identification of an event by assigned EventId.
*
* param: EventId: Identification of an event by assigned EventId.
*        EventTested: TRUE:Event tested this cycle.
*                    FALSE:Event not tested this cycle.
*
* retval: E_OK: Get of event state "tested" successful.
*         E_NOT_OK: Get of event state "tested" failed.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventTested
(
    Dem_EventIdType EventId, 
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) EventTested
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */    
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 evtIdx;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((EventId > DEM_INIT_ZERO) &&
           (EventId <= DEM_CFG_EVENT_ID_MAX) &&
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO) &&
           (TRUE == DEM_GET_AVAIL(Dem_CfgEventIdTableIndex[EventId])))
#else
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO))
#endif
        {
            if(NULL_PTR == EventTested)
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                errorId = DEM_E_PARAM_POINTER;
            }
            else
            {
                evtIdx = Dem_CfgEventIdTableIndex[EventId];
                if(TRUE == DEM_GET_UDS_STATUS_TNCTOC(evtIdx))
                {
                    *EventTested = (boolean)FALSE;
                }
                else
                {
                    *EventTested = (boolean)TRUE;

                }
                returnValue = E_OK;
            }
        }
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_GETEVENTTESTED_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_GetDebouncingOfEvent
*
* Explanation: Gets the debouncing status of an event.
*
* param: EventId: Identification of an event by assigned EventId.
*        DebouncingState:Bit 0: Temporarily Defective (corresponds to 0 < FDC < 127).
*                        Bit 1: finally Defective (corresponds to FDC = 127).
*                        Bit 2: temporarily healed (corresponds to -128 < FDC < 0).
*                        Bit 3: Test complete (corresponds to FDC = -128 or FDC = 127).
*                        Bit 4: DTR Update (= Test complete && Debouncing complete &&
*                               enable conditions / storage conditions fulfilled).
*
* retval: E_OK: Get of debouncing status per event state successful.
*         E_NOT_OK: Get of debouncing per event state failed.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDebouncingOfEvent
(
    Dem_EventIdType EventId, 
    P2VAR(Dem_DebouncingStateType, AUTOMATIC, DEM_APPL_DATA) DebouncingState
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */    
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 enCondSt, storCondSt;
    uint16 evtIdx;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((EventId > DEM_INIT_ZERO) &&
           (EventId <= DEM_CFG_EVENT_ID_MAX) &&
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO) &&
           (TRUE == DEM_GET_AVAIL(Dem_CfgEventIdTableIndex[EventId])))
#else
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO))
#endif
        {
            if(NULL_PTR == DebouncingState)
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                errorId = DEM_E_PARAM_POINTER;
            }
            else
            {
                evtIdx = Dem_CfgEventIdTableIndex[EventId];   
                *DebouncingState = DEM_INIT_ZERO;
                
                if(((sint8)DEM_INIT_ZERO < DEM_GET_FDCCNT(evtIdx)) &&
                   ((sint8)DEM_DEBOUNCE_FDC_HIGH_THRESHOLD > DEM_GET_FDCCNT(evtIdx)))
                {
                    *DebouncingState |= DEM_TEMPORARILY_DEFECTIVE;
                }

                if((sint8)DEM_DEBOUNCE_FDC_HIGH_THRESHOLD == DEM_GET_FDCCNT(evtIdx))
                {
                    *DebouncingState |= DEM_FINALLY_DEFECTIVE;
                }
                
                if(((sint8)DEM_DEBOUNCE_FDC_LOW_THRESHOLD < DEM_GET_FDCCNT(evtIdx)) &&
                   ((sint8)DEM_INIT_ZERO > DEM_GET_FDCCNT(evtIdx)))
                {
                    *DebouncingState |= DEM_TEMPORARILY_HEALED;
                }
                
                if(((sint8)DEM_DEBOUNCE_FDC_LOW_THRESHOLD == DEM_GET_FDCCNT(evtIdx)) ||
                   ((sint8)DEM_DEBOUNCE_FDC_HIGH_THRESHOLD == DEM_GET_FDCCNT(evtIdx)))
                {
                    *DebouncingState |= DEM_TEST_COMPLETE;
                }

                enCondSt = Dem_EventGetEnCondGrpStatus(Dem_CfgEventTable[evtIdx].awEvtEnCondGrpIdx);
                storCondSt = Dem_EventGetStorCondGrpStatus(Dem_CfgEventTable[evtIdx].acEvtStorCondGrpIdx);
                
                if((FALSE == DEM_GET_UDS_STATUS_TNCTOC(evtIdx)) &&
                   (DEM_INIT_ZERO < (*DebouncingState & DEM_BYTE_MASK_BIT3)) &&
                   (TRUE == enCondSt) && (TRUE == storCondSt))
                {
                    *DebouncingState |= DEM_DTR_UPDATE;
                }

                returnValue = E_OK;
            }
        }
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_GETDEBOUNCINGOFEVENT_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_GetDTCOfEvent
*
* Explanation: Gets the DTC of an event.
*
* param: EventId :Identification of an event by assigned EventId.
*        DTCFormat:Defines the output-format of the requested DTC value.
*        DTCOfEvent:Receives the DTC value in respective format returned 
*                   by this function.
*
* retval: E_OK: get of DTC was successful
*         E_NOT_OK: the call was not successful
*         DEM_E_NO_DTC_AVAILABLE: there is no DTC configured in the 
*                                 requested format
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCOfEvent
(
    Dem_EventIdType EventId, 
    Dem_DTCFormatType DTCFormat, 
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTCOfEvent
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx, obdDtcIdx;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((EventId > DEM_INIT_ZERO) &&
           (EventId <= DEM_CFG_EVENT_ID_MAX) &&
           (DTCFormat <= DEM_DTC_FORMAT_J1939) &&
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO) &&
           (TRUE == DEM_GET_AVAIL(Dem_CfgEventIdTableIndex[EventId])))
#else
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO))
#endif
        {
            if(NULL_PTR == DTCOfEvent)
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                errorId = DEM_E_PARAM_POINTER;
            }
            else
            {
                evtIdx = Dem_CfgEventIdTableIndex[EventId];
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
                switch(DTCFormat)
                {
                    case DEM_DTC_FORMAT_OBD:
                    {
                        obdDtcIdx = Dem_CfgDTCTable[dtcIdx].acObdDtcIdx;
                        if( (obdDtcIdx > DEM_INIT_ZERO) && (obdDtcIdx <= DEM_CFG_OBD_DTC_NUM) )
                        {
                            *DTCOfEvent = Dem_CfgObdDtcValue[obdDtcIdx];
                            returnValue = E_OK;
                        }
                        break;
                    }
                    case DEM_DTC_FORMAT_UDS:
                    {
                        if(dtcIdx > DEM_INIT_ZERO)
                        {
                            *DTCOfEvent = DEM_DTCVALUE_CAL(dtcIdx);
                            returnValue = E_OK;
                        }
                        break;
                    }

#if( DEM_CFG_J1939SUPPORT == STD_ON )
                    case DEM_DTC_FORMAT_J1939:
                    {
                        obdDtcIdx = Dem_CfgDTCTable[dtcIdx].acObdDtcIdx;
                        if( obdDtcIdx > DEM_INIT_ZERO )
                        {
                            *DTCOfEvent = Dem_CfgObdDTCTable[obdDtcIdx].awJ1939DtcVal;
                            returnValue = E_OK;
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
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_GETDTCOFEVENT_APIID, errorId);
    
    return returnValue;
}

#if(DEM_CFG_ENCOND_NUM > DEM_INIT_ZERO)  
/*
********************************************************************************
* Function Name: Dem_SetEnableCondition
*
* Explanation: Sets an enable condition
*
* param: EnableConditionID: This parameter identifies the enable condition.
*        ConditionFulfilled: This parameter specifies whether the storage condition
*                           assigned to the StorageConditionID is fulfilled
*                           (TRUE) or not fulfilled (FALSE).
*
* retval: E_OK: In case the storage condition could be set successfully.
*         E_NOT_OK: If the setting of the storage condition failed.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEnableCondition
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint8 EnableConditionID,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    boolean ConditionFulfilled
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 enCondIdx;

    /* Check if Dem module status is inited. */
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        for(enCondIdx = DEM_INIT_ONE; enCondIdx <= DEM_CFG_ENCOND_NUM; enCondIdx++)
        {
            /* Check if the param EnableConditionID is configured. */
            if(EnableConditionID == Dem_CfgEnConditionTable[enCondIdx].acEnCondId)
            {
                DEM_SET_ENCOND(enCondIdx, ConditionFulfilled);
                /* Enable condition status is changed, request status needs set to TRUE. */
                DEM_SET_ENCOND_REQ(TRUE);
                returnValue = E_OK;
                break;
            }
        }

        /* Param EnableConditionID is error. */
        if(enCondIdx > DEM_CFG_ENCOND_NUM)
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_SETENABLECONDITION_APIID, errorId);
  
    return returnValue;
}
#endif 

#if(DEM_CFG_STORCOND_NUM > DEM_INIT_ZERO) 
/*
********************************************************************************
* Function Name: Dem_SetStorageCondition
*
* Explanation: Sets a storage condition.
*
* param: StorageConditionID: This parameter identifies the storage condition.
*        ConditionFulfilled: This parameter specifies whether the storage condition
*                           assigned to the StorageConditionID is fulfilled
*                           (TRUE) or not fulfilled (FALSE).
*
* retval: E_OK: In case the storage condition could be set successfully.
*         E_NOT_OK: If the setting of the storage condition failed.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetStorageCondition
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint8 StorageConditionID,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    boolean ConditionFulfilled
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 storCondIdx;

    /* Check if Dem module status is inited. */
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        for(storCondIdx = DEM_INIT_ONE; storCondIdx <= DEM_CFG_STORCOND_NUM; storCondIdx++)
        {
            /* Check if the param StorageConditionID is configured. */
            if(StorageConditionID == Dem_CfgStorConditionTable[storCondIdx].acStorCondId)
            {
                DEM_SET_STORCOND(storCondIdx, ConditionFulfilled);
                /* Storage condition status is changed, request status needs set to TRUE. */
                DEM_SET_STORCOND_REQ(TRUE);
                returnValue = E_OK;
                break;
            }
        }

        /* Param StorageConditionID is error. */
        if(storCondIdx > DEM_CFG_STORCOND_NUM)
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_SETSTORAGECONDITION_APIID, errorId);

    return returnValue;
}
#endif

/*
********************************************************************************
* Function Name: Dem_GetFaultDetectionCounter
*
* Explanation: Gets the fault detection counter of an event.
*
* param: EventId: Identification of an event by assigned EventId.
*        FaultDetectionCounter: This parameter receives the Fault Detection
*                               Counter information of the requested EventId.
*
* retval:E_OK: Request was successful.
*        E_NOT_OK: Request failed.
*        DEM_E_NO_FDC_AVAILABLE: There is no fault detection counter available
*                                for the requested event.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetFaultDetectionCounter
(
    Dem_EventIdType EventId, 
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 evtIdx;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((EventId > DEM_INIT_ZERO) &&
           (EventId <= DEM_CFG_EVENT_ID_MAX) &&
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO) &&
           (TRUE == DEM_GET_AVAIL(Dem_CfgEventIdTableIndex[EventId])))
#else
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO))
#endif
        {
            if(NULL_PTR == FaultDetectionCounter)
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                errorId = DEM_E_PARAM_POINTER;
            }
            else
            {
                evtIdx = Dem_CfgEventIdTableIndex[EventId];
                /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" Polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                if(DEM_DEBOUNCE_MONITOR_INTERNAL == Dem_CfgEvtDebCntCls[evtIdx])
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    if(E_OK == Dem_EventTriggerGetFDCCbk(evtIdx, FaultDetectionCounter))
                    {
                        returnValue = E_OK;
                    }
                    else
                    {
                        returnValue = DEM_E_NO_FDC_AVAILABLE;
                    }
                }
#if((DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON) && (DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON))
                else if((DEM_DEBOUNCE_COUNTER_BASED == Dem_CfgEvtDebCntCls[evtIdx]) || 
                        (DEM_DEBOUNCE_TIMER_BASED == Dem_CfgEvtDebCntCls[evtIdx]))
                {
                    *FaultDetectionCounter = DEM_GET_FDCCNT(evtIdx);
                    returnValue = E_OK;
                }
#endif
#if((DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON) && (DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_OFF))
                else if(DEM_DEBOUNCE_COUNTER_BASED == Dem_CfgEvtDebCntCls[evtIdx])
                {
                    *FaultDetectionCounter = DEM_GET_FDCCNT(evtIdx);
                    returnValue = E_OK;
                }
#endif
#if((DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_OFF) && (DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON))
                else if(DEM_DEBOUNCE_TIMER_BASED == Dem_CfgEvtDebCntCls[evtIdx])
                {
                    *FaultDetectionCounter = DEM_GET_FDCCNT(evtIdx);
                    returnValue = E_OK;
                } 
#endif
                else
                {
                    /* Do nothing */
                }
            }
        }
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_GETFAULTDETECTIONCOUNTER_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_GetIndicatorStatus
*
* Explanation: Gets the indicator status derived from the event status.
*
* param: IndicatorId: Number of indicator.
*        IndicatorStatus: Status of the indicator, like off, on, or blinking.
*
* retval: E_OK: Operation was successful.
*         E_NOT_OK: Operation failed.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetIndicatorStatus
(
    uint8 IndicatorId, 
    P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 indiIdx;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == IndicatorStatus)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            for(indiIdx = DEM_INIT_ONE; indiIdx <= DEM_CFG_INDICATOR_NUM; indiIdx++)
            {
                if(IndicatorId == Dem_CfgIndicatorTable[indiIdx])
                {
                    break;
                }
            }

            if(indiIdx > DEM_CFG_INDICATOR_NUM)
            {
                errorId = DEM_E_PARAM_DATA;
            }
            else
            {
                *IndicatorStatus = DEM_GET_INDICATOR_STATUS(indiIdx);
                returnValue = E_OK;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_GETINDICATORSTATUS_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_GetEventFreezeFrameDataEx
*
* Explanation: Gets the data of a freeze frame by event.
*
* param: EventId: Identification of an event by assigned EventId.
*        RecordNumber: This parameter is a unique identifier for a freeze frame
*                     record as defined in ISO14229-1.
*        DataId: This parameter specifies the DID (ISO14229-1) that shall be
*               copied to the destination buffer.
*        DestBuffer: This parameter contains a byte pointer that points to the
*                    buffer,to which the extended data shall be written to.
*        BufSize: When the function is called this parameter containsthe maximum
*                number of data bytes that can be written to the buffer.
*
* retval: E_OK: Operation was successful.
*         E_NOT_OK: Operation could not be performed.
*         DEM_E_NODATAAVAILABLE: The requested eventdata is not currently stored 
*                                (but the request was valid).
*         DEM_E_WRONG_RECORDNUMBER: The requested record number is not supported
*                                   by the event.
*         DEM_E_WRONG_DIDNUMBER: The requested DID is not supported 
*                                by the freeze frame.
*         DEM_E_WRONG_BUFFERSIZE: The provided buffer size is too small.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFreezeFrameDataEx
(
    Dem_EventIdType EventId,
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
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 evtIdx;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((EventId > DEM_INIT_ZERO) &&
           (EventId <= DEM_CFG_EVENT_ID_MAX) &&
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO) &&
           (TRUE == DEM_GET_AVAIL(Dem_CfgEventIdTableIndex[EventId])))
#else
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO))
#endif
        {
            if((NULL_PTR == DestBuffer) || (NULL_PTR == BufSize))
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                errorId = DEM_E_PARAM_POINTER;
            }
            else
            {
                evtIdx = Dem_CfgEventIdTableIndex[EventId];
                if(DEM_INIT_ZERO == RecordNumber)
                {
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
                    returnValue = Dem_ObdGetWwhFFDataByDid(evtIdx, DataId, DestBuffer, BufSize);
#else
                    errorId = DEM_E_PARAM_DATA;
#endif
                }
                else if(DEM_BYTE_MAX == RecordNumber)
                {
                    returnValue = Dem_EventGetFFRecentlyRecordDidData(evtIdx, DataId, DestBuffer, BufSize);
                }
                else
                {
                    returnValue = Dem_EventGetFFRecordDidData(evtIdx, RecordNumber, DataId, DestBuffer, BufSize);
                }
            }
        }
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_DCMGETEVENTFREEZEFRAMEDATAEX, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name:Dem_GetEventExtendedDataRecordEx
*
* Explanation: Gets the data of an extended data record by event.
*
* param: EventId: Identification of an event by assigned EventId.
*        RecordNumber: Identification of requested Extended data record.
*        BufSize: When the function is called this parameter contains the 
*                maximum number of data bytes that can be written to the buffer.
*        DestBuffer: This parameter contains a byte pointer that points to the 
*                   buffer, to which the extended data shall be written to.
*
* retval: E_OK: Operation was successful.
*         E_NOT_OK: Operation could not be performed.
*         DEM_E_NODATAAVAILABLE: The requested event data is not currently
*                                stored (but the request was valid).
*         DEM_E_WRONG_RECORDNUMBER: The requested record number is not 
*                                   supported by the event.
*         DEM_E_WRONG_BUFFERSIZE: The provided buffer size is too small.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventExtendedDataRecordEx
(
    Dem_EventIdType EventId,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint8 RecordNumber,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 evtIdx;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((EventId > DEM_INIT_ZERO) &&
           (EventId <= DEM_CFG_EVENT_ID_MAX) &&
           (RecordNumber > DEM_INIT_ZERO) &&
           (RecordNumber < DEM_BYTE_MAX) &&
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO) &&
           (TRUE == DEM_GET_AVAIL(Dem_CfgEventIdTableIndex[EventId])))
#else
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO))
#endif
        {
            if((NULL_PTR == DestBuffer) || (NULL_PTR == BufSize))
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                errorId = DEM_E_PARAM_POINTER;
            }
            else
            {
                evtIdx = Dem_CfgEventIdTableIndex[EventId];
                returnValue = Dem_EventGetExRecordData(evtIdx, RecordNumber, DestBuffer, BufSize);
            }
        }
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_DCMGETEVENTEXTENDDATARECORDEX, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_GetEventMemoryOverflow
*
* Explanation: Gets the event memory overflow indication status.
*
* param: DTCOrigin: If the Dem supports more than one event memory
*                   this parameter is used to select the source memory
*                   the overflow indication shall be read from.
*        OverflowIndication: This parameter returns TRUE if the according
*                            event memory was overflowed, otherwise it returns FALSE.
*
* retval: E_OK: Operation was successful.
*         E_NOT_OK: Operation failed or is not supported.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventMemoryOverflow
(
    Dem_DTCOriginType DTCOrigin, 
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) OverflowIndication
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 evtMemIdx = DEM_INIT_ZERO;
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    Dem_PermanentEventMemoryEntry_st *ptr;
#endif
    Dem_EventMemoryInfo_st *info_ptr;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(E_NOT_OK == Dem_EventCheckDTCOriginValid(DTCOrigin, &evtMemIdx))
        {
            errorId = DEM_E_PARAM_DATA;
        }
        else if(NULL_PTR == OverflowIndication)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            /* Primary or user define event memory */
            if((evtMemIdx > DEM_INIT_ZERO) && (evtMemIdx <= DEM_CFG_EVENT_MEMORY_NUM))
            {
                /* Get event memory info pointer */
                info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(evtMemIdx);
                
                if(info_ptr->cntEnSlot >= Dem_CfgEventMemoryTable[evtMemIdx].acEvtMemMaxEntry)
                {
                    *OverflowIndication = TRUE;
                }
                else
                {
                    *OverflowIndication = FALSE;
                }
                returnValue = E_OK;
            }
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
            else
            {
                /* Permanent event memory */
                ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
                if(ptr->pfcCnt >= DEM_CFG_MAXNUMBEREVENTENTRYPERMANENT)
                {
                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                    *OverflowIndication = TRUE;
                }
                else
                {
                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                    *OverflowIndication = FALSE;
                }
                returnValue = E_OK;
            }
#endif
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_GETEVENTMEMORYOVERFLOW_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_GetNumberOfEventMemoryEntries
*
* Explanation: Returns the number of entries currently stored in the 
*              requested event memory.
*
* param: DTCOrigin: If the Dem supports more than one event memory this parameter
*                   is used to select the source memory the number of entries
*                   shall be read from.
*        NumberOfEventMemoryEntries: Number of entries currently stored in the 
*                                    requested event memory.
*
* retval: E_OK: Operation was successful.
*         E_NOT_OK: Operation failed.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumberOfEventMemoryEntries
(
    Dem_DTCOriginType DTCOrigin, 
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) NumberOfEventMemoryEntries
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 evtMemIdx = DEM_INIT_ZERO;
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    Dem_PermanentEventMemoryEntry_st *ptr;
#endif
    Dem_EventMemoryInfo_st *info_ptr;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(E_NOT_OK == Dem_EventCheckDTCOriginValid(DTCOrigin, &evtMemIdx))
        {
            errorId = DEM_E_PARAM_DATA;
        }
        else if(NULL_PTR == NumberOfEventMemoryEntries)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            /* Primary or user define event memory */
            if((evtMemIdx > DEM_INIT_ZERO) && (evtMemIdx <= DEM_CFG_EVENT_MEMORY_NUM))
            {
                /* Get event memory info pointer */
                info_ptr = DEM_GET_EVENT_MEMORY_INFO_PTR(evtMemIdx);
                *NumberOfEventMemoryEntries = info_ptr->cntEnSlot;
                returnValue = E_OK;
            }
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
            else
            {
                /* Permanent event memory */
                ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
                /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                *NumberOfEventMemoryEntries = ptr->pfcCnt;
                returnValue = E_OK;
            }
#endif
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_GETNUMBEROFEVENTMEMORYENTRIES_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_SetComponentAvailable
*
* Explanation: Set the availability of a specific DemComponent.
*
* param: ComponentId: Identification of a DemComponent.
*        AvailableStatus: This parameter specifies whether the respective
*                         Component shall be available (TRUE) or not(FALSE).
*
* retval: E_OK: Operation was successful.
*         E_NOT_OK: Operation failed.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetComponentAvailable
(
    Dem_ComponentIdType ComponentId, 
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    boolean AvailableStatus
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
#if(DEM_CFG_COMP_NUM > DEM_INIT_ZERO)
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
    uint16 evtIdx;
#endif
#endif

    DEM_DUMMY_STATEMENT(ComponentId);
    DEM_DUMMY_STATEMENT(AvailableStatus);
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
#if(DEM_CFG_COMP_NUM > DEM_INIT_ZERO)
        if((ComponentId > DEM_INIT_ZERO) &&
           (ComponentId <= DEM_CFG_COMP_NUM))
        {
            DEM_SET_COMP_AVAILABLE(ComponentId, AvailableStatus);
            
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
            for(evtIdx = DEM_INIT_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
            {
                if(Dem_CfgEventTable[evtIdx].awEvtComIdx == ComponentId)
                {
                    (void)Dem_SetEventAvailable(Dem_CfgEventIdTableIndex[Dem_CfgEventTable[evtIdx].awEvtId], AvailableStatus);
                }
            }
#endif
            returnValue = E_OK;
        }
        else
#endif
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_SETCOMPONENTAVAILABLE_APIID, errorId);
    
    return returnValue;
}

#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
/*
********************************************************************************
* Function Name: Dem_SetDTCSuppression
*
* Explanation: Set the suppression status of a specific DTC.
*
* param: DTC: Diagnostic Trouble Code.
*        DTCFormat: Defines the input-format of the provided DTC value.
*        SuppressionStatus: This parameter specifies whether the respective
*                           DTC shall be disabled (TRUE) or enabled (FALSE).
* retval: E_OK: Operation was successful.
*         E_NOT_OK: Operation failed or event entry for this DTC still exists.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTCSuppression
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC, 
    Dem_DTCFormatType DTCFormat, 
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    boolean SuppressionStatus
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx, evtIdx;

    DEM_UNUSED_PARAMETER(DTCFormat);
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        for(evtIdx = DEM_INIT_ONE; evtIdx <= DEM_CFG_EVENT_NUM; evtIdx++)
        {
            /* PolySpace +1 MISRA-C3:20.7 [Justified:Unset] "NSCA_Polyspace_Dem_20.7" */
            if(DEM_DTCVALUE_CAL(Dem_CfgEvtDtcIdx[evtIdx]) == DTC)
            {
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
                break;
            }
        }

        if((evtIdx <= DEM_CFG_EVENT_NUM) && (dtcIdx > DEM_INIT_ZERO))
        {
            /* Make sure this event is not in event memory currently */
            if(E_NOT_OK == Dem_EventMemoryEntryExist(evtIdx))
            {
                DEM_SET_DTCSUPPRESSION(dtcIdx, SuppressionStatus);
                returnValue = E_OK;
            }
        }
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_SETDTCSUPPRESSION_APIID, errorId);
    
    return returnValue;
}
#endif

/*
********************************************************************************
* Function Name: Dem_ClearDTC
*
* Explanation: Clears single DTCs, as well as groups of DTCs.
*
* param: DTC: Defines the DTC in respective format, that shall be
*            cleared from the event memory.
*        DTCFormat: Defines the input-format of the provided DTC value.
*        DTCOrigin: If the Dem supports more than one event memory
*                  this parameter is used to select the source memory
*                  the DTCs shall be read from.
*
* retval: DEM_CLEAR_OK: DTC successfully cleared.
*         DEM_CLEAR_WRONG_DTC: DTC value not existing (in this format).
*         DEM_CLEAR_WRONG_DTCORIGIN: Wrong DTC origin.
*         DEM_CLEAR_FAILED: DTC clearing failed.
*         DEM_CLEAR_PENDING: The DTC clearing is performed asynchronously
*                            and still pending. The caller can retry later.
*         DEM_CLEAR_BUSY: DTC not cleared, as another clearing process is
*                         in progress. The caller can retry later.
*         DEM_CLEAR_MEMORY_ERROR: An error occurred during erasing a memory location.
********************************************************************************
*/
FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC, 
    Dem_DTCFormatType DTCFormat, 
    Dem_DTCOriginType DTCOrigin
)
{
    Dem_ReturnClearDTCType returnValue = DEM_CLEAR_FAILED;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 evtMemIdx = DEM_INIT_ZERO;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        /* Permanent event memory is not possible to be cleared via this interface */
        if(DEM_DTC_ORIGIN_PERMANENT_MEMORY == DTCOrigin)
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_CLEAR_WRONG_DTCORIGIN;
        }
        else if(E_NOT_OK == Dem_EventCheckDTCOriginValid(DTCOrigin, &evtMemIdx))
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_CLEAR_WRONG_DTCORIGIN;
        }
        else
        {
            returnValue = Dem_EventClearDTC(DTC, 
                                            DTCFormat, 
                                            evtMemIdx, 
                                            DEM_CLEAR_DTC_CLIENT_CDD);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_CLEARDTC_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetTranslationType
*
* Explanation: Gets the supported DTC formats of the ECU.
*
* param: None
*
* retval: DEM_DTC_TRANSLATION_ISO15031_6:ISO15031-6 DTC format/SAE J2012-DA_DTCFormat_00 DTC format.
*         DEM_DTC_TRANSLATION_ISO14229_1:SO14229-1 DTC format.
*         DEM_DTC_TRANSLATION_SAEJ1939_73:AEJ1939-73 DTC format.
*         DEM_DTC_TRANSLATION_ISO11992_4:SO11992-4 DTC format.
*         DEM_DTC_TRANSLATION_J2012DA_FORMAT_04:AE_J2012-DA_DTCFormat_04 DTC format.
********************************************************************************
*/
FUNC(Dem_DTCTranslationFormatType, DEM_CODE) Dem_DcmGetTranslationType(void)
{
    Dem_Det_ErrorReport(DEM_DCMGETTRANSLATIONTYPE_APIID, DEM_E_NO_ERROR);
    
    return DEM_CFG_TYPEOFDTCSUPPORTED;
}

/*
********************************************************************************
* Function Name:   Dem_DcmGetDTCStatusAvailabilityMask
*
* Explanation: Gets the DTC Status availability mask.
*
* param: DTCStatusMask: The value DTCStatusMask indicates the supported 
*                       DTC status bits from the Dem.
*
* retval: E_OK: Get of DTC status mask was successful.
*         E_NOT_OK: Get of DTC status mask failed.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCStatusAvailabilityMask
(
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatusMask
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == DTCStatusMask)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            *DTCStatusMask = (Dem_UdsStatusByteType)DEM_CFG_DTCSTATUSAVAILABILITYMASK;
            returnValue = E_OK;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETDTCSTATUSAVAILABILITYMASK_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetStatusOfDTC
*
* Explanation: Gets the status of a DTC.
*
* param: DTC: Diagnostic Trouble Code in UDS format.
*        DTCOrigin: If the Dem supports more than one event memory this parameter
*                  is used to select the source memory the DTCs shall be read from.
*        DTCStatus: This parameter receives the status information of the requested DTC.
*
* retval: DEM_STATUS_OK: Status of DTC is OK.
*         DEM_STATUS_WRONG_DTC: DTC value not existing (in this format).
*         DEM_STATUS_WRONG_DTCORIGIN: Wrong DTC origin.
*         DEM_STATUS_FAILED: DTC failed.
*         DEM_STATUS_PENDING: The requested value is calculated asynchronously
*                            and currently not available.
********************************************************************************
*/
FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE) Dem_DcmGetStatusOfDTC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
)
{
    Dem_ReturnGetStatusOfDTCType returnValue = DEM_STATUS_FAILED;
    
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 evtMemIdx = DEM_INIT_ZERO;
    uint8 dtcStatus;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        /* Not support permanent event memory */
        if(DEM_DTC_ORIGIN_PERMANENT_MEMORY == DTCOrigin)
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_STATUS_WRONG_DTCORIGIN;
        }
        else if(E_NOT_OK == Dem_EventCheckDTCOriginValid(DTCOrigin, &evtMemIdx))
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_STATUS_WRONG_DTCORIGIN;
        }
        else if(NULL_PTR == DTCStatus)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            if(E_OK == Dem_EventCalcDtcStatus(DTC, evtMemIdx, &dtcStatus))
            {
                if(DEM_EVENT_DTC_STATUS_INVALID != dtcStatus)
                {
                    *DTCStatus = (uint8)(dtcStatus & DEM_CFG_DTCSTATUSAVAILABILITYMASK);
                    returnValue = DEM_STATUS_OK;
                }
                else
                {
                    returnValue = DEM_STATUS_WRONG_DTC;
                }
            }
            else
            {
                returnValue = DEM_STATUS_PENDING;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETSTATUSOFDTC_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetSeverityOfDTC
*
* Explanation: Gets the severity of the requested DTC.
*
* param: DTC: Diagnostic Trouble Code in UDS format.
*        DTCSeverity: This parameter contains the DTCSeverity according to ISO 14229-1.
*
* retval: DEM_STATUS_OK: Status of DTC is OK.
*         DEM_STATUS_WRONG_DTC: DTC value not existing (in this format).
*         DEM_STATUS_WRONG_DTCORIGIN: Wrong DTC origin.
*         DEM_STATUS_FAILED: DTC failed.
*         DEM_STATUS_PENDING: The requested value is calculated asynchronously
*                            and currently not available.
********************************************************************************
*/
FUNC(Dem_ReturnGetSeverityOfDTCType, DEM_CODE) Dem_DcmGetSeverityOfDTC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC, 
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity
)
{
    Dem_ReturnGetStatusOfDTCType returnValue = DEM_GET_SEVERITYOFDTC_NOSEVERITY;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == DTCSeverity)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            if(E_OK == Dem_EventCalcDTCIndexFromDTC(DTC, DEM_DTC_FORMAT_UDS, &dtcIdx))
            {
                if((dtcIdx > DEM_INIT_ZERO) && (dtcIdx <= DEM_CFG_DTC_NUM))
                {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    if(TRUE == DEM_GET_DTCSUPPRESSION(dtcIdx))
                    {
                        /* Suppress DTC, return WRONG_DTC */
                        returnValue = DEM_GET_SEVERITYOFDTC_WRONG_DTC;
                    }
                    else
                    {
                        *DTCSeverity = Dem_CfgDTCTable[dtcIdx].acDtcSeverity;
                        returnValue = DEM_GET_SEVERITYOFDTC_OK;
                    }
#else
                    *DTCSeverity = Dem_CfgDTCTable[dtcIdx].acDtcSeverity;
                    returnValue = DEM_GET_SEVERITYOFDTC_OK;
#endif
                }
                else
                {
                    returnValue = DEM_GET_SEVERITYOFDTC_WRONG_DTC;
                }
            }
            else
            {
                returnValue = DEM_GET_SEVERITYOFDTC_PENDING;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETSEVERITYOFDTC_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetFunctionalUnitOfDTC
*
* Explanation: Gets the functional unit of the requested DTC.
*
* param: DTC: Diagnostic Trouble Code in UDS format.
*        DTCFunctionalUnit: Functional unit value of this DTC.
*
* retval: DEM_GET_FUNCTIONALUNITOFDTC_OK: Functional unit successfully returned.
*         DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC: DTC value not existing (in UDS format).
********************************************************************************
*/
FUNC(Dem_ReturnGetFunctionalUnitOfDTCType, DEM_CODE) Dem_DcmGetFunctionalUnitOfDTC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit
)
{
    Dem_ReturnGetFunctionalUnitOfDTCType returnValue = DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == DTCFunctionalUnit)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            if(E_OK == Dem_EventCalcDTCIndexFromDTC(DTC, DEM_DTC_FORMAT_UDS, &dtcIdx))
            {
                if((dtcIdx > DEM_INIT_ZERO) && (dtcIdx <= DEM_CFG_DTC_NUM))
                {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    if(TRUE == DEM_GET_DTCSUPPRESSION(dtcIdx))
                    {
                        /* Suppress DTC, return WRONG_DTC */
                        returnValue = DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC;
                    }
                    else
                    {
                        *DTCFunctionalUnit = Dem_CfgDTCTable[dtcIdx].acFuncId;
                        returnValue = DEM_GET_FUNCTIONALUNITOFDTC_OK;
                    }
#else
                    *DTCFunctionalUnit = Dem_CfgDTCTable[dtcIdx].acFuncId;
                    returnValue = DEM_GET_FUNCTIONALUNITOFDTC_OK;
#endif
                }
                else
                {
                    returnValue = DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC;
                }
            }
            else
            {
                returnValue = DEM_GET_FUNCTIONALUNITOFDTC_PENDING;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETFUNCTIONALUNITOFDTC_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmSetDTCFilter
*
* Explanation: Sets the DTC Filter.
*
* param: DTCStatusMask: Status-byte mask for DTC status-byte filtering.
*        DTCKind: Defines the functional group of DTCs to be reported.
*        DTCFormat: Defines the output-format of the requested DTC values
*                   for the sub-sequent API calls.
*        DTCOrigin: If the Dem supports more than one event memory this 
*                   parameter is used to select the source memory the DTCs
*                   shall be read from.
*        FilterWithSeverity: This flag defines whether severity information
*                      (ref.to parameter below) shall be used for filtering.
*        DTCSeverityMask: This parameter contains the DTCSeverityMask 
*                         according to ISO14229-1.
*        FilterForFaultDetectionCounter: This flag defines whether the fault
*                  detection counter information shall be used for filtering.
*
* retval: DEM_FILTER_ACCEPTED: Filter was accepted.
*         DEM_WRONG_FILTER: Wrong filter selected.
********************************************************************************
*/
FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_DcmSetDTCFilter
(
    Dem_UdsStatusByteType DTCStatusMask,
    Dem_DTCKindType DTCKind,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin,
    boolean FilterWithSeverity,
    Dem_DTCSeverityType DTCSeverityMask,
    boolean FilterForFaultDetectionCounter
)
{
    Dem_ReturnSetFilterType returnValue = DEM_WRONG_FILTER;

    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 evtMemIdx = DEM_INIT_ZERO;
    Dem_UdsStatusByteType statusMask;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(E_NOT_OK == Dem_EventCheckDTCOriginValid(DTCOrigin, &evtMemIdx))
        {
            errorId = DEM_E_WRONG_CONFIGURATION;
        }
        else
        {
            DEM_SET_DTC_FILTER_ENABLE(TRUE);
            /* Check if the service is UDS 0x19. */
            if( DEM_DTC_FORMAT_UDS == DTCFormat )
            {
                /* DEM_CFG_DTCSTATUSAVAILABILITYMASK is only used for UDS 0x19 service. */
                statusMask = (Dem_UdsStatusByteType)(DTCStatusMask & DEM_CFG_DTCSTATUSAVAILABILITYMASK);
            }
            else
            {
                statusMask = DTCStatusMask;
            }
            DEM_SET_DTC_FILTER_MASK(statusMask);
            DEM_SET_DTC_FILTER_KIND(DTCKind);
            DEM_SET_DTC_FILTER_FORMAT(DTCFormat);
            DEM_SET_DTC_FILTER_ORIGIN(DTCOrigin);
            DEM_SET_DTC_FILTER_SEVERITY(FilterWithSeverity);
            DEM_SET_DTC_FILTER_SEVERITY_MASK(DTCSeverityMask);
            DEM_SET_DTC_FILTER_FDC(FilterForFaultDetectionCounter);
            DEM_SET_DTC_FILTER_SLOT_CNT(DEM_INIT_ZERO);
            DEM_SET_DTC_FILTER_EVTMEMIDX(evtMemIdx);
            DEM_SET_DTC_FILTER_MATCH_NUM(DEM_INIT_ZERO);
            DEM_SET_DTC_FILTER_MATCH_NEXT(TRUE);
            DEM_SET_DTC_FILTER_MATCH_CNT(DEM_INIT_ZERO);
            DEM_SET_DTC_FILTER_MATCH_NEXTIDX(DEM_INIT_ZERO);
            DEM_SET_DTC_FILTER_ALL_SUPPORTED(FALSE);

            if((DEM_INIT_ZERO == DTCStatusMask) &&
               (DEM_DTC_KIND_ALL_DTCS == DTCKind) &&
               (DEM_DTC_FORMAT_UDS == DTCFormat) &&
               (DEM_DTC_ORIGIN_PRIMARY_MEMORY == DTCOrigin) &&
               (FALSE == FilterWithSeverity) &&
               (FALSE == FilterForFaultDetectionCounter))
            {
                DEM_SET_DTC_FILTER_ALL_SUPPORTED(TRUE);
            }

            for(dtcIdx = DEM_BYTE_ONE; dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++)
            {
                DEM_SET_DTC_FILTERED(dtcIdx, FALSE);
            }
            
            returnValue = DEM_FILTER_ACCEPTED;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMSETDTCFILTER_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetNumberOfFilteredDTC
*
* Explanation: Gets the number of a filtered DTC.
*
* param: NumberOfFilteredDTC: The number of DTCs matching the defined status mask.
*
* retval: DEM_NUMBER_OK: Getting number of filtered DTCs was successful.
*         DEM_NUMBER_FAILED: Getting number of filtered DTCs failed.
*         DEM_NUMBER_PENDING: The requested value is calculated asynchronously
*                            and currently not available. The caller can retry later.
********************************************************************************
*/
FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE) Dem_DcmGetNumberOfFilteredDTC
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC
)
{
    Dem_ReturnGetNumberOfFilteredDTCType returnValue = DEM_NUMBER_FAILED;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == NumberOfFilteredDTC)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            if(TRUE == DEM_GET_DTC_FILTER_ENABLE())
            {
                if(TRUE == DEM_GET_DTC_FILTER_ALL_SUPPORTED())
                {
                    if(E_OK == Dem_EventCalcDtcFilteredAllSupportedNum())
                    {
                        if(DEM_GET_DTC_FILTER_MASK() != DEM_INIT_ZERO)
                        {
                            DEM_SET_DTC_FILTER_ALL_SUPPORTED(FALSE);
                        }
                        /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                        *NumberOfFilteredDTC = DEM_GET_DTC_FILTER_MATCH_NUM();
                        returnValue = DEM_NUMBER_OK;
                    }
                    else
                    {
                        returnValue = DEM_NUMBER_PENDING;
                    }
                }
                else
                {
                    if(E_OK == Dem_EventCalcDtcFilteredNum())
                    {
                        if(DEM_DTC_ORIGIN_PERMANENT_MEMORY != DEM_GET_DTC_FILTER_ORIGIN())
                        {
                            DEM_SET_DTC_FILTER_ALL_SUPPORTED(TRUE);
                            returnValue = DEM_NUMBER_PENDING;
                        }
                        else
                        {
                            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            *NumberOfFilteredDTC = DEM_GET_DTC_FILTER_MATCH_NUM();
                            returnValue = DEM_NUMBER_OK;
                        }
                    }
                    else
                    {
                        returnValue = DEM_NUMBER_PENDING;
                    }
                }
            }
            else
            {
                returnValue = DEM_NUMBER_FAILED;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETNUMBEROFFILTEREDDTC_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetNextFilteredDTC
*
* Explanation: Gets the next filtered DTC matching the filter criteria.
*
* param: DTC: Receives the DTC value in respective format of the filter
*             returned by this function.
*        DTCStatus: This parameter receives the status information
*            of the requested DTC.
*
* retval: DEM_FILTERED_OK: Returned next filtered element.
*         DEM_FILTERED_NO_MATCHING_ELEMENT: No further element (matching the 
*                                           filter criteria) found.
*         DEM_FILTERED_PENDING: The requested value is calculated asynchronously
*                               and currently not available. The caller can retry
*                               later. Only used by asynchronous interfaces.
*         DEM_FILTERED_BUFFER_TOO_SMALL: Buffer in the BufSize parameter is
*                                        not huge enough.
*         DEM_FILTERED_UNINIT: API called in uninitialized state.
*         DEM_FILTERED_PARAM_POINTER: API called with a NULL pointer 
*                                     where NULL pointer is not allowed.
********************************************************************************
*/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredDTC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC, 
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatus
)
{
    Dem_ReturnGetNextFilteredElementType returnValue = DEM_FILTERED_BUFFER_TOO_SMALL;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 dtcStatus = DEM_INIT_ZERO;
    uint32 dtcVal;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((NULL_PTR == DTC) || (NULL_PTR == DTCStatus))
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            if(TRUE == DEM_GET_DTC_FILTER_ENABLE())
            {
                if(TRUE == DEM_GET_DTC_FILTER_ALL_SUPPORTED())
                {
                    if(E_OK == Dem_EventCalcDtcNextFilteredAllSupported(&dtcVal, &dtcStatus))
                    {
                        if(FALSE == DEM_GET_DTC_FILTER_MATCH_NEXT())
                        {
                            if(DEM_GET_DTC_FILTER_MASK() != DEM_INIT_ZERO)
                            {
                                DEM_SET_DTC_FILTER_ALL_SUPPORTED(FALSE);
                            }
                            /* No more matched DTC found */
                            returnValue = DEM_FILTERED_NO_MATCHING_ELEMENT;
                        }
                        else
                        {
                            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            *DTC = dtcVal;
                            /* Check if the service is UDS 0x19. */
                            if( DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT() )
                            {
                                /* DEM_CFG_DTCSTATUSAVAILABILITYMASK is only used for UDS 0x19 service. */
                                /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                                *DTCStatus = (Dem_UdsStatusByteType)(dtcStatus & DEM_CFG_DTCSTATUSAVAILABILITYMASK);
                            }
                            else
                            {
                                /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                                *DTCStatus = dtcStatus;
                            }
                            returnValue = DEM_FILTERED_OK;
                        }
                    }
                    else
                    {
                        returnValue = DEM_FILTERED_PENDING;
                    }
                }
                else
                {
                    if(E_OK == Dem_EventCalcDtcNextFiltered(&dtcVal, &dtcStatus))
                    {
                        if(FALSE == DEM_GET_DTC_FILTER_MATCH_NEXT())
                        {
                            if(DEM_DTC_ORIGIN_PERMANENT_MEMORY != DEM_GET_DTC_FILTER_ORIGIN())
                            {
                                DEM_SET_DTC_FILTER_ALL_SUPPORTED(TRUE);
                                DEM_SET_DTC_FILTER_MATCH_NEXT(TRUE);
                                returnValue = DEM_FILTERED_PENDING;
                            }
                            else
                            {
                                /* No more matched DTC found */
                                returnValue = DEM_FILTERED_NO_MATCHING_ELEMENT;
                            }
                        }
                        else
                        {
                            /* PolySpace +1 MISRA-C3:9.1 [Justified:Unset] "NSCA_Polyspace_Dem_9.1" Polyspace +1 RTE:NIVL [Justified:Unset] "NSCA_Polyspace_Dem_NonInitializedLocalVariable" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            *DTC = dtcVal;
                            /* Check if the service is UDS 0x19. */
                            if( DEM_DTC_FORMAT_UDS == DEM_GET_DTC_FILTER_FORMAT() )
                            {
                                /* DEM_CFG_DTCSTATUSAVAILABILITYMASK is only used for UDS 0x19 service. */
                                /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                                *DTCStatus = (Dem_UdsStatusByteType)(dtcStatus & DEM_CFG_DTCSTATUSAVAILABILITYMASK);
                            }
                            else
                            {
                                /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                                *DTCStatus = dtcStatus;
                            }
                            returnValue = DEM_FILTERED_OK;
                        }
                    }
                    else
                    {
                        returnValue = DEM_FILTERED_PENDING;
                    }
                }
            }
            else
            {
                returnValue = DEM_FILTERED_NO_MATCHING_ELEMENT;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETNEXTFILTEREDDTC_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetNextFilteredDTCAndFDC
*
* Explanation: Gets the next filtered DTC and its associated Fault Detection 
*              Counter (FDC) matching the filter criteria.
*
* param: DTC: Receives the DTC value in respective format of the filter 
*             returned by this function.
*        DTCFaultDetectionCounter: This parameter receives the Fault Detection
*                                 Counter information of the requested DTC.
*
* retval: DEM_FILTERED_OK: Returned next filtered element.
*         DEM_FILTERED_NO_MATCHING_ELEMENT: No further element 
*                        (matching the filter criteria) found.
*         DEM_FILTERED_PENDING: The requested value is calculated asynchronously
*                        and currently not available. The caller can retry later.
*                        Only used by asynchronous interfaces.
*         DEM_FILTERED_BUFFER_TOO_SMALL: Buffer in the BufSize parameter 
*                                        is not huge enough.
*         DEM_FILTERED_UNINIT: API called in uninitialized state.
*         DEM_FILTERED_PARAM_POINTER: API called with a NULL pointer where 
*                                     NULL pointer is not allowed.
********************************************************************************
*/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredDTCAndFDC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) DTCFaultDetectionCounter
)
{
    Dem_ReturnGetNextFilteredElementType returnValue = DEM_FILTERED_BUFFER_TOO_SMALL;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    sint8 dtcFdc = (sint8)DEM_INIT_ZERO;
    uint32 dtcVal;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((NULL_PTR == DTC) || (NULL_PTR == DTCFaultDetectionCounter))
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            if(TRUE == DEM_GET_DTC_FILTER_ENABLE())
            {
                if(TRUE == DEM_GET_DTC_FILTER_ALL_SUPPORTED())
                {
                    if(E_OK == Dem_EventCalcAllDtcAndFdcNextFiltered(&dtcVal, &dtcFdc))
                    {
                        if(FALSE == DEM_GET_DTC_FILTER_MATCH_NEXT())
                        {
                            DEM_SET_DTC_FILTER_ALL_SUPPORTED(FALSE);
                            /* No more matched DTC found */
                            returnValue = DEM_FILTERED_NO_MATCHING_ELEMENT;
                        }
                        else
                        {
                            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            *DTC = dtcVal;
                            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            *DTCFaultDetectionCounter = dtcFdc;
                            returnValue = DEM_FILTERED_OK;
                        }
                    }
                    else
                    {
                        returnValue = DEM_FILTERED_PENDING;
                    }
                }
                else
                {
                    /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                    if(E_OK == Dem_EventCalcDtcAndFdcNextFiltered(&dtcVal, &dtcFdc))
                    {
                        if(FALSE == DEM_GET_DTC_FILTER_MATCH_NEXT())
                        {
                            DEM_SET_DTC_FILTER_ALL_SUPPORTED(TRUE);
                            DEM_SET_DTC_FILTER_MATCH_NEXT(TRUE);
                            returnValue = DEM_FILTERED_PENDING;
                        }
                        else
                        {
                            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            *DTC = dtcVal;
                            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            *DTCFaultDetectionCounter = dtcFdc;
                            returnValue = DEM_FILTERED_OK;
                        }
                    /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    }
                    else
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    {
                        returnValue = DEM_FILTERED_PENDING;
                    }
                }
            }
            else
            {
                returnValue = DEM_FILTERED_NO_MATCHING_ELEMENT;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETNEXTFILTEREDDTCANDFDC_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name:   Dem_DcmGetNextFilteredDTCAndSeverity
* Explanation:
* param: DTC: Receives the DTC value in respective format of the filter
*             returned by this function.
*        DTCStatus: This parameter receives the status information of 
*                   the requested DTC.
*        DTCSeverity: Receives the severity value returned by the function.
*        DTCFunctionalUnit: Receives the functional unit value returned
*                           by the function.
*
* retval: DEM_FILTERED_OK: Returned next filtered element.
*         DEM_FILTERED_NO_MATCHING_ELEMENT: No further element 
*                                           (matching the filter criteria) found.
*         DEM_FILTERED_PENDING: The requested value is calculated asynchronously
*                               and currently not available. The caller can retry
*                               later. Only used by asynchronous interfaces.
*         DEM_FILTERED_BUFFER_TOO_SMALL: Buffer in the BufSize parameter is 
*                                        not huge enough.
*         DEM_FILTERED_UNINIT: API called in uninitialized state.
*         DEM_FILTERED_PARAM_POINTER: API called with a NULL pointer where 
*                                     NULL pointer is not allowed.
********************************************************************************
*/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredDTCAndSeverity
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatus,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit
)
{
    Dem_ReturnGetNextFilteredElementType returnValue = DEM_FILTERED_BUFFER_TOO_SMALL;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 dtcFuncunit;
    Dem_UdsStatusByteType dtcStatus = DEM_INIT_ZERO;
    Dem_DTCSeverityType dtcSeverity;
    uint32 dtcVal;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((NULL_PTR == DTC) || (NULL_PTR == DTCStatus) || 
           (NULL_PTR == DTCSeverity) || (NULL_PTR == DTCFunctionalUnit))
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            if(TRUE == DEM_GET_DTC_FILTER_ENABLE())
            {
                if(TRUE == DEM_GET_DTC_FILTER_ALL_SUPPORTED())
                {
                    if(E_OK == Dem_EventCalcAllDtcAndSeverityNextFiltered(&dtcVal, &dtcStatus, &dtcSeverity, &dtcFuncunit))
                    {
                        if(FALSE == DEM_GET_DTC_FILTER_MATCH_NEXT())
                        {
                            DEM_SET_DTC_FILTER_ALL_SUPPORTED(FALSE);
                            /* No more matched DTC found */
                            returnValue = DEM_FILTERED_NO_MATCHING_ELEMENT;
                        }
                        else
                        {
                            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            *DTC = dtcVal;
                            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            *DTCStatus = (Dem_UdsStatusByteType)(dtcStatus & DEM_CFG_DTCSTATUSAVAILABILITYMASK);
                            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            *DTCSeverity = dtcSeverity;
                            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            *DTCFunctionalUnit = dtcFuncunit;
                            returnValue = DEM_FILTERED_OK;
                        }
                    }
                    else
                    {
                        returnValue = DEM_FILTERED_PENDING;
                    }
                }
                else
                {
                    /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                    if(E_OK == Dem_EventCalcDtcAndSeverityNextFiltered(&dtcVal, &dtcStatus, &dtcSeverity, &dtcFuncunit))
                    {
                        if(FALSE == DEM_GET_DTC_FILTER_MATCH_NEXT())
                        {
                            DEM_SET_DTC_FILTER_ALL_SUPPORTED(TRUE);
                            DEM_SET_DTC_FILTER_MATCH_NEXT(TRUE);
                            returnValue = DEM_FILTERED_PENDING;
                        }
                        else
                        {
                            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            *DTC = dtcVal;
                            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            *DTCStatus = (Dem_UdsStatusByteType)(dtcStatus & DEM_CFG_DTCSTATUSAVAILABILITYMASK);
                            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            *DTCSeverity = dtcSeverity;
                            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                            *DTCFunctionalUnit = dtcFuncunit;
                            returnValue = DEM_FILTERED_OK;
                        }
                    /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    }
                    else
                    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    {
                        returnValue = DEM_FILTERED_PENDING;
                    }
                }
            }
            else
            {
                returnValue = DEM_FILTERED_NO_MATCHING_ELEMENT;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETNEXTFILTEREDDTCANDSEVERITY_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmSetFreezeFrameRecordFilter
*
* Explanation: Sets a freeze frame record filter.
*
* param: DTCFormat: Defines the output-format of the requested DTC values 
*        for the sub-sequent API calls. NumberOfFilteredRecords: Number of
*        freeze frame records currently stored in the event memory.
*
* retval: DEM_FILTER_ACCEPTED: Filter was accepted.
*         DEM_WRONG_FILTER: Wrong filter selected.
********************************************************************************
*/
FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_DcmSetFreezeFrameRecordFilter
(
    Dem_DTCFormatType DTCFormat,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredRecords
)
{
    Dem_ReturnSetFilterType returnValue = DEM_WRONG_FILTER;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == NumberOfFilteredRecords)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else if((DTCFormat >= DEM_DTC_FORMAT_J1939))
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            DEM_SET_FF_FILTER_ENABLE(TRUE);
            DEM_SET_FF_FILTER_SLOT_CNT(DEM_INIT_ZERO);
            DEM_SET_FF_FILTER_FORMAT(DTCFormat);
            DEM_SET_FF_FILTER_MATCH_NEXT(TRUE);
            DEM_SET_FF_FILTER_MATCH_NEXT_IDX(DEM_INIT_ZERO);

            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            *NumberOfFilteredRecords = Dem_EventCalcDTCFreezeFrameFiltered();
            returnValue = DEM_FILTER_ACCEPTED;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMSETFREEZEFRAMERECORDFILTER_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetNextFilteredRecord
*
* Explanation: Gets the next freeze frame record number and its associated DTC
*              stored in the event memory.
*
* param: DTC: Receives the DTC value in respective format of the filter 
*             returned by this function.
*        RecordNumber: Freeze frame record number of the reported DTC.
*
* retval: DEM_FILTERED_OK: Returned next filtered element.
*         DEM_FILTERED_NO_MATCHING_ELEMENT: No further element (matching the 
*                                           filter criteria) found.
*         DEM_FILTERED_PENDING: The requested value is calculated asynchronously
*                               and currently not available. The caller can 
*                           retry later. Only used by asynchronous interfaces.
*         DEM_FILTERED_BUFFER_TOO_SMALL: Buffer in the BufSize parameter is 
*                                        not huge enough.
********************************************************************************
*/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_DcmGetNextFilteredRecord
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) RecordNumber
)
{
    Dem_ReturnGetNextFilteredElementType returnValue = DEM_FILTERED_BUFFER_TOO_SMALL;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 recNum;
    uint32 dtcVal;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((NULL_PTR == DTC) || (NULL_PTR == RecordNumber))
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            if(TRUE == DEM_GET_FF_FILTER_ENABLE())
            {
                if(E_OK == Dem_EventCalcDTCFreezeFrameNextFiltered(&dtcVal, &recNum))
                {
                    if(FALSE == DEM_GET_FF_FILTER_MATCH_NEXT())
                    {
                        /* No more matched DTC found */
                        returnValue = DEM_FILTERED_NO_MATCHING_ELEMENT;
                    }
                    else
                    {
                        /* PolySpace +1 MISRA-C3:9.1 [Justified:Unset] "NSCA_Polyspace_Dem_9.1" Polyspace +1 RTE:NIVL [Justified:Unset] "NSCA_Polyspace_Dem_NonInitializedLocalVariable" Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                        *DTC = dtcVal;
                        /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                        *RecordNumber = recNum;
                        returnValue = DEM_FILTERED_OK;
                    }
                }
                else
                {
                    returnValue = DEM_FILTERED_PENDING;
                }
            }
            else
            {
                returnValue = DEM_FILTERED_NO_MATCHING_ELEMENT;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETNEXTFILTEREDRECORD_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetDTCByOccurrenceTime
*
* Explanation: Gets the DTC by occurrence time.
*
* param: DTCRequest: This parameter defines the request type of the DTC.
*        DTC: Receives the DTC value in UDS format returned by the function.
*
* retval: DEM_OCCURR_OK: Matching DTC available.
*         DEM_OCCURR_NOT_AVAILABLE: No DTC is matching the requested occurrence time.
********************************************************************************
*/
FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE) Dem_DcmGetDTCByOccurrenceTime
(
    Dem_DTCRequestType DTCRequest,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC
)
{
    Dem_ReturnGetDTCByOccurrenceTimeType returnValue = DEM_OCCURR_NOT_AVAILABLE;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == DTC)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            returnValue = Dem_EventGetDTCByOccurrenceTime(DTCRequest, DTC);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETDTCBYOCCURRENCETIME_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmControlDTCStatusChangedNotification
*
* Explanation: Controls the triggering of Dcm_DemTriggerOnDTCStatus.
*
* param: TriggerNotification: This parameter specifies whether the triggering of
*                   the notification shall be enabled (TRUE) or disabled(FALSE).
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_DcmControlDTCStatusChangedNotification
(
    boolean TriggerNotification
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        DEM_SET_DTCCHANGEDNOTIF(TriggerNotification);
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMCONTROLDTCSTATUSCHANGEDNOTIFICATION_APIID, errorId);
    
    return;
}

/*
********************************************************************************
* Function Name: Dem_DcmDisableDTCRecordUpdate
*
* Explanation: Disables the event memory update of a specific DTC 
*              (only one at onetime).
*
* param: DTC: Selects the DTC in UDS format, for which DTC record update
*             shall be disabled.
*        DTCOrigin: If the Dem supports more than one event memory,this 
*                   parameter is used to select the source memory for which 
*                   DTC record update shall be disabled.
*
* retval: DEM_DISABLE_DTCRECUP_OK: Event memory update of DTC successfully disabled
*         DEM_DISABLE_DTCRECUP_WRONG_DTC: DTC value not existing(in UDS format)
*         DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN: Wrong DTC origin
*         DEM_DISABLE_DTCRECUP_PENDING: Disabling is currently not possible
********************************************************************************
*/
FUNC(Dem_ReturnDisableDTCRecordUpdateType, DEM_CODE) Dem_DcmDisableDTCRecordUpdate
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC, 
    Dem_DTCOriginType DTCOrigin
)
{
    Dem_ReturnDisableDTCRecordUpdateType returnValue = DEM_DISABLE_DTCRECUP_WRONG_DTC;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 evtMemIdx;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        /* Not support permanent event memory */
        if(DEM_DTC_ORIGIN_PERMANENT_MEMORY == DTCOrigin)
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN;
        }
        else if(E_NOT_OK == Dem_EventCheckDTCOriginValid(DTCOrigin, &evtMemIdx))
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN;
        }
        else
        {
            if(TRUE == DEM_GET_DTC_RECORD_ENABLE())
            {
                DEM_SET_DTC_RECORD_ENABLE(FALSE);
                DEM_SET_DTC_RECORD_ENABLE_DTC(DTC);
                DEM_SET_DTC_RECORD_ENABLE_EMIDX(evtMemIdx);
                returnValue = DEM_DISABLE_DTCRECUP_OK;
            }
            else
            {
                if(DTC != DEM_GET_DTC_RECORD_ENABLE_DTC())
                {
                    errorId = DEM_E_WRONG_CONDITION;
                }
                else
                {
                    returnValue = DEM_DISABLE_DTCRECUP_OK;
                }
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMDISABLEDTCRECORDUPDATE_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmDisableDTCRecordUpdate
*
* Explanation: Enables the event memory update of the DTC disabled by
*              Dem_DcmDisableDTCRecordUpdate() before.
*
* param: None
*
* retval: Always return E_OK
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmEnableDTCRecordUpdate(void)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        DEM_SET_DTC_RECORD_ENABLE(TRUE);
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMENABLEDTCRECORDUPDATE_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetFreezeFrameDataByDTC
*
* Explanation: Gets freeze frame data by DTC. The function stores the data in
*              the provided DestBuffer.
*
* param: DTC: Diagnostic Trouble Code in UDS format.
*        DTCOrigin: If the Dem supports more than one event memory,
*                   this parameteris used to select the source memory the 
*                   DTCs shall be read from.
*        RecordNumber: This parameter is a unique identifier for a freeze 
*                      frame record as defined.
*        BufSize: The function returns the actual number of written data 
*                 bytes in this parameter.
*        DestBuffer: This parameter contains a byte pointer that points 
*                    to the buffer.
*
* retval: DEM_GET_FFDATABYDTC_OK: Size successfully returned.
*         DEM_GET_FFDATABYDTC_WRONG_DTC: DTC value not existing (in UDS format).
*         DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN: Wrong DTC origin.
*         DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER: Record number is not supported
*                                         by configuration and therefore invalid.
*         DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE: provided buffer size to small.
*         DEM_GET_FFDATABYDTC_PENDING: The requested value is calculated 
*                            asynchronously and currently not available. 
*                                            The caller can retry later.
*         DEM_GET_FFDATABYDTC_UNINIT: API called in uninitialized state.
*         DEM_GET_FFDATABYDTC_PARAM_DATA: API called with an invalid
*                                         parameter value.
*         DEM_GET_FFDATABYDTC_PARAM_POINTER: API called with a NULL pointer 
*                                         where NULL pointer is not allowed.
********************************************************************************
*/
FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE) Dem_DcmGetFreezeFrameDataByDTC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint8 RecordNumber,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Dem_ReturnGetFreezeFrameDataByDTCType returnValue = DEM_GET_FFDATABYDTC_WRONG_DTC;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 evtMemIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((NULL_PTR == DestBuffer) || (NULL_PTR == BufSize))
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
            returnValue = DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE;
        }
        else if(E_NOT_OK == Dem_EventCheckDTCOriginValid(DTCOrigin, &evtMemIdx))
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN;
        }
        else if(0xFFU == RecordNumber)
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
        }
        else
        {
            if(DEM_INIT_ZERO == RecordNumber)
            {
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
                returnValue = Dem_ObdGetFFRecordData(DTC, evtMemIdx, RecordNumber, DestBuffer, BufSize);
#else
                returnValue = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
#endif
            }
            else
            {
                /* Get the current diagnostic service processed DTC index. */
                dtcIdx = DEM_GET_DIAG_PROC_DTC_IDX();  /* PRQA S 4434 */ /* NSCA_QAC_Common_Rule10.3 */
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if((dtcIdx > DEM_INIT_ZERO) && (FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)))
#else
                if(dtcIdx > DEM_INIT_ZERO)
#endif
                {
                    returnValue = Dem_DTCGetFFRecordData(dtcIdx, evtMemIdx, RecordNumber, DestBuffer, BufSize);
                }
                else
                {
                    returnValue = DEM_GET_FFDATABYDTC_WRONG_DTC;
                }
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETFREEZEFRAMEDATABYDTC_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetSizeOfFreezeFrameByDTC
*
* Explanation: Gets the size of freeze frame data by DTC.
*
* param: DTC: Diagnostic Trouble Code in UDS format.
*        DTCOrigin: If the Dem supports more than one event memory,
*                  this parameter is used to select the source memory
*                  the DTCs shall be read from.
*        RecordNumber: This parameter is a unique identifier for a freeze
*                     frame record as defined in ISO 15031-5 and ISO 14229-1.
*        SizeOfFreezeFrame:Number of bytes in the requested freeze frame record.
*
* retval: DEM_GET_FFDATABYDTC_OK: Size successfully returned.
*         DEM_GET_FFDATABYDTC_WRONG_DTC: DTC value not existing (in UDS format).
*         DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN: Wrong DTC origin.
*         DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER: Record number is not supported
*                                        by configuration and therefore invalid.
*         DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE: Provided buffer size to small.
*         DEM_GET_FFDATABYDTC_PENDING: The requested value is calculated 
*                                      asynchronously and currently not available. 
*                                      The caller can retry later.
*         DEM_GET_FFDATABYDTC_UNINIT: API called in uninitialized state.
*         DEM_GET_FFDATABYDTC_PARAM_DATA: API called with an invalid parameter value.
*         DEM_GET_FFDATABYDTC_PARAM_POINTER: called with a NULL pointer where 
*                                            NULL pointer is not allowed.
********************************************************************************
*/
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DcmGetSizeOfFreezeFrameByDTC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint8 RecordNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
)
{
    Dem_ReturnGetSizeOfDataByDTCType returnValue = DEM_GETSIZEBYDTC_WRONG_DTC;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 evtMemIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == SizeOfFreezeFrame)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else if(E_NOT_OK == Dem_EventCheckDTCOriginValid(DTCOrigin, &evtMemIdx))
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_GETSIZEBYDTC_WRONG_DTCORIGIN;
        }
        else
        {
            if(DEM_INIT_ZERO == RecordNumber)
            {
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
                returnValue = Dem_ObdGetFFRecordSize(DTC, evtMemIdx, SizeOfFreezeFrame);
#else
                returnValue = DEM_GETSIZEBYDTC_WRONG_RECNUM;
#endif
            }
            else
            {
                /* Get the current diagnostic service processed DTC index. */
                dtcIdx = DEM_GET_DIAG_PROC_DTC_IDX();  /* PRQA S 4434 */ /* NSCA_QAC_Common_Rule10.3 */
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                if((dtcIdx > DEM_INIT_ZERO) && (FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)))
#else
                if(dtcIdx > DEM_INIT_ZERO)
#endif
                {
                    returnValue = Dem_DTCGetFFRecordSize(dtcIdx, evtMemIdx, RecordNumber, SizeOfFreezeFrame);
                }
                else
                {
                    returnValue = DEM_GETSIZEBYDTC_WRONG_DTC;
                }
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETSIZEOFFREEZEFRAMEBYDTC_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetExtendedDataRecordByDTC
*
* Explanation: Gets extended data by DTC. The function stores the data 
*              in the provided DestBuffer.
*
* param: DTC: Diagnostic Trouble Code in UDS format.
*        DTCOrigin: If the Dem supports more than one event memory,
*                   this parameter is used to select the source memory
*                   the DTCs shall be read from.
*        ExtendedDataNumber: dentification/Number of requested extended data
*                            record. The values 0xFE and 0xFF are not allowed.
*        BufSize: When the function is called this parameter contains the maximum
*                 number of data bytes that can be written to the buffer.
*        DestBuffer: This parameter contains a byte pointer that points to the buffer.
*
* retval: DEM_GETSIZEBYDTC_OK: Size successfully returned.
*         DEM_GETSIZEBYDTC_WRONG_DTC: DTC value not existing (in UDS format).
*         DEM_GETSIZEBYDTC_WRONG_DTCORIGIN: Wrong DTC origin.
*         DEM_GETSIZEBYDTC_WRONG_RECNUM: Record number is not supported by
*                                        configuration and therefore invalid.
*         DEM_GETSIZEBYDTC_PENDING: The requested value is calculated 
*         asynchronously  and currently not available. The caller can retry later.
*         DEM_GETSIZEBYDTC_UNINIT: API called in uninitialized state.
*         DEM_GETSIZEBYDTC_PARAM_POINTER: called with a NULL pointer where
*                                         NULL pointer is not allowed.
********************************************************************************
*/
FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE) Dem_DcmGetExtendedDataRecordByDTC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Dem_ReturnGetExtendedDataRecordByDTCType returnValue = DEM_RECORD_WRONG_DTC;    
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 evtMemIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((NULL_PTR == DestBuffer) || (NULL_PTR == BufSize))
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
            returnValue = DEM_RECORD_WRONG_BUFFERSIZE;
        }
        else if((0xFEU == ExtendedDataNumber) || (0xFFU == ExtendedDataNumber))
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_RECORD_WRONG_NUMBER;
        }
        else if(E_NOT_OK == Dem_EventCheckDTCOriginValid(DTCOrigin, &evtMemIdx))
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_RECORD_WRONG_DTCORIGIN;
        }
        else
        {
            if(E_OK == Dem_EventCalcDTCIndexFromDTC(DTC, DEM_DTC_FORMAT_UDS, &dtcIdx))
            {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                if((dtcIdx != DEM_INIT_ZERO) && (FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)))
#else
                if(dtcIdx != DEM_INIT_ZERO)
#endif
                {
                    returnValue = Dem_DTCGetExRecordData(dtcIdx, evtMemIdx, ExtendedDataNumber, DestBuffer, BufSize);
                }
                else
                {
                    returnValue = DEM_RECORD_WRONG_DTC;
                }
            }
            else
            {
                returnValue = DEM_RECORD_PENDING;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETEXTENDEDDATARECORDBYDTC_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetSizeOfExtendedDataRecordByDTC
*
* Explanation: Gets the size of extended data by DTC.
*
* param: DTC: Diagnostic Trouble Code in UDS format.
*        DTCOrigin: If the Dem supports more than one event memory,this parameter
*                is used to select the source memory the DTCs shall be read from.
*        ExtendedDataNumber: Identification/Number of requested extended data record.
*        SizeOfExtendedDataRecord: Size of the requested extended data
*                                  record(s) including record number size.
*
* retval: DEM_GETSIZEBYDTC_OK: Size successfully returned.
*         DEM_GETSIZEBYDTC_WRONG_DTC: DTC value not existing (in UDS format).
*         DEM_GETSIZEBYDTC_WRONG_DTCORIGIN: Wrong DTC origin.
*         DEM_GETSIZEBYDTC_WRONG_RECNUM: Record number is not supported by
*                                        configuration and therefore invalid.
*         DEM_GETSIZEBYDTC_PENDING: The requested value is calculated asynchronously
*                          and currently not available. The caller can retry later.
*         DEM_GETSIZEBYDTC_UNINIT: API called in uninitialized state.
*         DEM_GETSIZEBYDTC_PARAM_POINTER: called with a NULL pointer where 
*                                         NULL pointer is not allowed.
********************************************************************************
*/
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DcmGetSizeOfExtendedDataRecordByDTC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
)
{
    Dem_ReturnGetSizeOfDataByDTCType returnValue = DEM_GETSIZEBYDTC_WRONG_DTC;    
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 evtMemIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == SizeOfExtendedDataRecord)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else if(E_NOT_OK == Dem_EventCheckDTCOriginValid(DTCOrigin, &evtMemIdx))
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_GETSIZEBYDTC_WRONG_DTCORIGIN;
        }
        else
        {
            if(E_OK == Dem_EventCalcDTCIndexFromDTC(DTC, DEM_DTC_FORMAT_UDS, &dtcIdx))
            {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                if((dtcIdx != DEM_INIT_ZERO) && (FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)))
#else
                if(dtcIdx != DEM_INIT_ZERO)
#endif
                {
                    returnValue = Dem_DTCGetExRecordSize(dtcIdx, evtMemIdx, ExtendedDataNumber, SizeOfExtendedDataRecord);
                }
                else
                {
                    returnValue = DEM_GETSIZEBYDTC_WRONG_DTC;
                }
            }
            else
            {
                returnValue = DEM_GETSIZEBYDTC_PENDING;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETSIZEOFEXTENDEDDATARECORDBYDTC_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmCheckClearParameter
*
* Explanation: Performs a parameter check and gives the result which would also be
*              returned by calling clear with same parameters.
*
* param: DTC: Defines the DTC in respective format, that shall be cleared from
*             the event memory.Either a single DTC or a DTC group may be passed.
*        DTCFormat: Defines the input-format of the provided DTC value.
*        DTCOrigin: This parameter is used to select the source memory the DTCs
*                   shall be cleared from.
*
* retval: DEM_CLEAR_OK: DTC successfully cleared.
*         DEM_CLEAR_WRONG_DTC: DTC value not existing (in this format).
*         DEM_CLEAR_WRONG_DTCORIGIN: Wrong DTC origin.
*         DEM_CLEAR_FAILED: DTC clearing failed.
********************************************************************************
*/
FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_DcmCheckClearParameter
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC, 
    Dem_DTCFormatType DTCFormat, 
    Dem_DTCOriginType DTCOrigin
)
{
    Dem_ReturnClearDTCType returnValue = DEM_CLEAR_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 evtMemIdx = DEM_INIT_ZERO;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        switch(DTCFormat)
        {
            case DEM_DTC_FORMAT_OBD:
            {
                if(DEM_EVENT_DTC_GROUP_ALL != DTC)
                {
                    returnValue = DEM_CLEAR_WRONG_DTC;
                }
                break;
            }
            case DEM_DTC_FORMAT_UDS:
            {
                if(DEM_EVENT_DTC_GROUP_ALL != DTC)
                {
#if(DEM_CFG_CLEARDTCLIMITATION == DEM_ONLY_CLEAR_ALL_DTCS)
                    returnValue = DEM_CLEAR_WRONG_DTC;
#endif
                }
                break;
            }

            case DEM_DTC_FORMAT_J1939:

            default:
            {
                returnValue = DEM_CLEAR_WRONG_DTC;
                break;
            }
        }
        
        if(DEM_CLEAR_OK == returnValue)
        {
            if(E_NOT_OK == Dem_EventCheckDTCOriginValid(DTCOrigin, &evtMemIdx))
            {
                returnValue = DEM_CLEAR_WRONG_DTCORIGIN;
            }
            DEM_DUMMY_STATEMENT(evtMemIdx);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMCHECKCLEARPAAMETER, errorId);

    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmClearDTC
*
* Explanation: Clears single DTCs, as well as groups of DTCs.
*
* param: DTC: Defines the DTC in respective format, that shall be cleared from
*             the event memory.Either a single DTC or a DTC group may be passed.
*        DTCFormat: Defines the input-format of the provided DTC value.
*        DTCOrigin: This parameter is used to select the source memory the DTCs
*                   shall be cleared from.
*
* retval: DEM_CLEAR_OK: DTC successfully cleared.
*         DEM_CLEAR_WRONG_DTC: DTC value not existing (in this format).
*         DEM_CLEAR_WRONG_DTCORIGIN: Wrong DTC origin.
*         DEM_CLEAR_FAILED: DTC clearing failed.
*         DEM_CLEAR_PENDING: The DTC clearing is performed asynchronously
*                            and still pending. The caller can retry later.
*         DEM_CLEAR_BUSY: DTC not cleared, as another clearing process is
*                         in progress. The caller can retry later.
*         DEM_CLEAR_MEMORY_ERROR: An error occurred during erasing a memory location.
********************************************************************************
*/
FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_DcmClearDTC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC, 
    Dem_DTCFormatType DTCFormat, 
    Dem_DTCOriginType DTCOrigin
)
{
    Dem_ReturnClearDTCType returnValue = DEM_CLEAR_FAILED;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 evtMemIdx = DEM_INIT_ZERO;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        /* Permanent event memory is not possible to be cleared via this interface */
        if(DEM_DTC_ORIGIN_PERMANENT_MEMORY == DTCOrigin)
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_CLEAR_WRONG_DTCORIGIN;
        }
        else if(E_NOT_OK == Dem_EventCheckDTCOriginValid(DTCOrigin, &evtMemIdx))
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_CLEAR_WRONG_DTCORIGIN;
        }
        else
        {
            returnValue = Dem_EventClearDTC(DTC, 
                                            DTCFormat, 
                                            evtMemIdx, 
                                            DEM_CLEAR_DTC_CLIENT_DCM);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMCLEARDTC_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmDisableDTCSetting
*
* Explanation: Disable the DTC setting for a DTC group.
*
* param: DTCGroup: Defines the group of DTC that shall be enabled to store in event memory.
*        DTCKind: This parameter defines the requested DTC kind, either only
*                 OBD-relevant DTCs or all DTCs.
*
* retval: DEM_CONTROL_DTC_SETTING_OK: DTC setting control successful.
*         DEM_CONTROL_DTC_SETTING_N_OK: DTC setting control not successful.
*         DEM_CONTROL_DTC_WRONG_DTCGROUP: DTC setting control not successful because
*                                         group of DTC was wrong.
********************************************************************************
*/
FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE) Dem_DcmDisableDTCSetting
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTCGroup, 
    Dem_DTCKindType DTCKind
)
{
    Dem_ReturnControlDTCSettingType returnValue = DEM_CONTROL_DTC_SETTING_N_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
#if(DEM_CFG_DTC_GROUP_NUM > 0U)
    uint8 dtcGrpCnt;
#endif
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(DTCKind > DEM_DTC_KIND_EMISSION_REL_DTCS)
        {
            errorId = DEM_E_PARAM_DATA;
        }
        else
        {
            if(DEM_EVENT_DTC_GROUP_ALL == DTCGroup)
            {
                DEM_SET_DTC_SETTING_DISABLE(TRUE);    
                DEM_SET_DTC_DISABLE_KIND(DTCKind);
                DEM_SET_DTC_DISABLE_GROUP(DTCGroup);
                DEM_SET_DTC_DISABLE_GROUP_IDX(DEM_INIT_ZERO);
                returnValue = DEM_CONTROL_DTC_SETTING_OK;
            }
            else
            {
#if(DEM_CFG_DTC_GROUP_NUM > 0U)
                for(dtcGrpCnt = DEM_INIT_ONE; dtcGrpCnt < DEM_CFG_DTC_GROUP_NUM; dtcGrpCnt++)
                {
                    if(Dem_CfgDTCGrpTable[dtcGrpCnt] == DTCGroup)
                    {
                        DEM_SET_DTC_SETTING_DISABLE(TRUE);    
                        DEM_SET_DTC_DISABLE_KIND(DTCKind);
                        DEM_SET_DTC_DISABLE_GROUP(DTCGroup);
                        DEM_SET_DTC_DISABLE_GROUP_IDX(dtcGrpCnt);
                        returnValue = DEM_CONTROL_DTC_SETTING_OK;
                        break;
                    }
                }

                if(dtcGrpCnt >= DEM_CFG_DTC_GROUP_NUM)
#endif
                {
                    returnValue = DEM_CONTROL_DTC_WRONG_DTCGROUP;
                }
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMDISABLEDTCSETTING_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmEnableDTCSetting
*
* Explanation: Enables the DTC setting for a DTC group.
*
* param: DTCGroup: Defines the group of DTC that shall be enabled to store in event memory.
*        DTCKind: This parameter defines the requested DTC kind, either only
*                 OBD-relevant DTCs or all DTCs.
*
* retval: DEM_CONTROL_DTC_SETTING_OK: DTC setting control successful.
*         DEM_CONTROL_DTC_SETTING_N_OK: DTC setting control not successful.
*         DEM_CONTROL_DTC_WRONG_DTCGROUP: DTC setting control not successful because
*                                         group of DTC was wrong.
********************************************************************************
*/
FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE) Dem_DcmEnableDTCSetting
(
/* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTCGroup,
    Dem_DTCKindType DTCKind
)
{
    Dem_ReturnControlDTCSettingType returnValue = DEM_CONTROL_DTC_SETTING_N_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */    
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(DEM_DTC_KIND_EMISSION_REL_DTCS < DTCKind)
        {
            errorId = DEM_E_PARAM_DATA;
        }
        else
        {
            if(TRUE == DEM_GET_DTC_SETTING_DISABLE())
            {
                if((DTCGroup == DEM_GET_DTC_DISABLE_GROUP()) &&
                   (DTCKind == DEM_GET_DTC_DISABLE_KIND()))
                {
                    DEM_SET_DTC_SETTING_DISABLE(FALSE);
                    DEM_SET_DTC_SETTING_ENABLE(TRUE);
                    returnValue = DEM_CONTROL_DTC_SETTING_OK;
                }
                else
                {
                    returnValue = DEM_CONTROL_DTC_WRONG_DTCGROUP;
                }
            }
            else
            {
                returnValue = DEM_CONTROL_DTC_SETTING_OK;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMENABLEDTCSETTING_APIID, errorId);
    
    return returnValue;
}

#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
/*
********************************************************************************
* Function Name: Dem_DcmGetInfoTypeValue08
*
* Explanation: Service is used for requesting IUMPR data according to Info-
*              Type $08. This interface is derived from the prototype <Module>_
*              GetInfotypeValueData() defined by the Dcm. Therefore Dcm_OpStatusType
*              and Std_ReturnType are contained. API is needed in OBD-relevant ECUs only.
*
* param: OpStatus: Only DCM_INITIAL will appear, because this API behaves synchronous.
*        Iumprdata08BufferSize: The maximum number of data bytes that can be
*                               written to the Iumprdata08 Buffer.
*        Iumprdata08: Buffer containing the number of data elements (as
*                     defined in ISO-15031-5) and contents of InfoType
*                     $08. The buffer is provided by the Dcm.
*
* retval: Always E_OK is returned.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue08
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08BufferSize
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((NULL_PTR == Iumprdata08) || (NULL_PTR == Iumprdata08BufferSize))
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        { 
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            Dem_ObdGetInfoTypeValue08(OpStatus, 
                                      Iumprdata08, 
                                      Iumprdata08BufferSize);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    Dem_Det_ErrorReport(DEM_DCMGETINFOTYPEVALUE08_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetInfoTypeValue0B
*
* Explanation: Service is used for requesting IUMPR data according to Info-
*              Type $0B. This interface is derived from the prototype <Module>_
*              GetInfotypeValueData() defined by the Dcm. Therefore Dcm_OpStatusType
*              and Std_ReturnType are contained. API is needed in OBD-relevant ECUs only.
*
* param: OpStatus: Only DCM_INITIAL will appear, because this API behaves synchronous.
*        Iumprdata0BBufferSize: The maximum number of data bytes that can be
*                               written to the Iumprdata08 Buffer.
*        Iumprdata0B: Buffer containing the number of data elements (as
*                     defined in ISO-15031-5) and contents of InfoType
*                     $0B. The buffer is provided by the Dcm.
*
* retval: Always E_OK is returned.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue0B
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0B,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0BBufferSize
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((NULL_PTR == Iumprdata0B) || (NULL_PTR == Iumprdata0BBufferSize))
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        { 
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            Dem_ObdGetInfoTypeValue0B(OpStatus, 
                                      Iumprdata0B,
                                      Iumprdata0BBufferSize);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETINFOTYPEVALUE0B_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID01
*
* Explanation: Service to report the value of PID $01 computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID01value: Buffer containing the contents of PID $01 computed
*                    by the Dem. The buffer is provided by the Dcm with
*                    the appropriate size, i.e. during configuration, the
*                    Dcm identifies the required size from the largest PID
*                    in order toconfigure a PIDBuffer.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01value
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID01value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            Dem_ObdGetDataOfPID01(PID01value);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID01_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID02
*
* Explanation: Service to report the value of PID $02 computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID02value: Buffer containing the contents of PID $02 computed
*                    by the Dem. The buffer is provided by the Dcm with
*                    the appropriate size, i.e. during configuration, the
*                    Dcm identifies the required size from the largest PID
*                    in order toconfigure a PIDBuffer.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID02
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID02value
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 evtIdx, dtcIdx, obdDtcIdx;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID02value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            if(ptr->freezeframeEvtId > DEM_INIT_ZERO)
            {
                /* PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Dem_18.1" PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Dem_D4.1" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Dem_OutOfBoundArrayIndex" */
                evtIdx = Dem_CfgEventIdTableIndex[ptr->freezeframeEvtId];
                dtcIdx = Dem_CfgEvtDtcIdx[evtIdx];
                obdDtcIdx = Dem_CfgDTCTable[dtcIdx].acObdDtcIdx;
#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
                /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                PID02value[DEM_BYTE_ONE] = (uint8)((Dem_CfgObdDtcValue[obdDtcIdx] & DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                PID02value[DEM_BYTE_ZERO] = (uint8)(Dem_CfgObdDtcValue[obdDtcIdx] & DEM_WORD_LOW_BYTE);
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
                PID02value[DEM_BYTE_ZERO] = (uint8)((Dem_CfgObdDtcValue[obdDtcIdx] & DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
                PID02value[DEM_BYTE_ONE] = (uint8)(Dem_CfgObdDtcValue[obdDtcIdx] & DEM_WORD_LOW_BYTE);
#else
                PID02value[DEM_BYTE_ZERO] = DEM_INIT_ZERO;
                PID02value[DEM_BYTE_ONE] = DEM_INIT_ZERO;
#endif
            }
            else
            {
                /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                PID02value[DEM_BYTE_ZERO] = DEM_INIT_ZERO;
                PID02value[DEM_BYTE_ONE] = DEM_INIT_ZERO;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID02_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID04
*
* Explanation: Service to report the value of PID $04 computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID04value: Buffer containing the contents of PID $04 computed
*                    by the Dem. The buffer is provided by the Dcm with
*                    the appropriate size, i.e. during configuration, the
*                    Dcm identifies the required size from the largest PID
*                    in order toconfigure a PIDBuffer.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID04
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID04value
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID04value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            PID04value[DEM_BYTE_ZERO] = DEM_GET_OBD_PID04_VALUE();
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID04_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID05
*
* Explanation: Service to report the value of PID $05 computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID05value: Buffer containing the contents of PID $05 computed
*                    by the Dem. The buffer is provided by the Dcm with
*                    the appropriate size, i.e. during configuration, the
*                    Dcm identifies the required size from the largest PID
*                    in order toconfigure a PIDBuffer.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID05
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID05value
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID05value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
#if(DEM_CFG_OBD_ENGINE_TEMP > DEM_INIT_ZERO)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            PID05value[DEM_BYTE_ZERO] = (uint8)Dem_ObdGetGeneralData(DEM_CFG_OBD_ENGINE_TEMP);
#else
            PID05value[DEM_BYTE_ZERO] = DEM_INIT_ZERO;
#endif
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID05_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID0C
*
* Explanation: Service to report the value of PID $0C computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID0Cvalue: Buffer containing the contents of PID $0C computed
*                    by the Dem. The buffer is provided by the Dcm with
*                    the appropriate size, i.e. during configuration, the
*                    Dcm identifies the required size from the largest PID
*                    in order toconfigure a PIDBuffer.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID0C
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID0Cvalue
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
#if(DEM_CFG_OBD_ENGINE_SPD > DEM_INIT_ZERO)
    uint16 valOfPid0C;
#endif
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID0Cvalue)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
#if(DEM_CFG_OBD_ENGINE_SPD > DEM_INIT_ZERO)
            valOfPid0C = (uint16)Dem_ObdGetGeneralData(DEM_CFG_OBD_ENGINE_SPD);
#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            PID0Cvalue[DEM_BYTE_ONE] = (uint8)(valOfPid0C >> DEM_BYTE_EIGHT);
            PID0Cvalue[DEM_BYTE_ZERO] = (uint8)valOfPid0C;
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
            PID0Cvalue[DEM_BYTE_ZERO] = (uint8)(valOfPid0C >> DEM_BYTE_EIGHT);
            PID0Cvalue[DEM_BYTE_ONE] = (uint8)valOfPid0C;
#else
            PID0Cvalue[DEM_BYTE_ZERO] = DEM_INIT_ZERO;
            PID0Cvalue[DEM_BYTE_ONE] = DEM_INIT_ZERO;
#endif
#else
            PID0Cvalue[DEM_BYTE_ZERO] = DEM_INIT_ZERO;
            PID0Cvalue[DEM_BYTE_ONE] = DEM_INIT_ZERO;
#endif
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID0C_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID0D
*
* Explanation: Service to report the value of PID $0D computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID0Dvalue: Buffer containing the contents of PID $0D computed
*                    by the Dem. The buffer is provided by the Dcm with
*                    the appropriate size, i.e. during configuration, the
*                    Dcm identifies the required size from the largest PID
*                    in order toconfigure a PIDBuffer.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID0D
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID0Dvalue
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID0Dvalue)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
#if(DEM_CFG_OBD_VEHICLE_SPD > DEM_INIT_ZERO)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            PID0Dvalue[DEM_BYTE_ZERO] = (uint8)Dem_ObdGetGeneralData(DEM_CFG_OBD_VEHICLE_SPD);
#else
            PID0Dvalue[DEM_BYTE_ZERO] = DEM_INIT_ZERO;
#endif
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID0D_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID1C
*
* Explanation: Service to report the value of PID $1C computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID1Cvalue: Buffer containing the contents of PID $1C computed
*                    by the Dem. The value of PID$1C is configuration 
*                    within DemOBDCompliancy.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID1C
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID1Cvalue
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */    
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID1Cvalue)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            *PID1Cvalue = DEM_CFG_OBD_COMPLIANCY;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID1C_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID21
*
* Explanation: Service to report the value of PID $21 computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID21value: Buffer containing the contents of PID $21 computed
*                    by the Dem. The buffer is provided by the Dcm with the 
*                    appropriate size, i.e. during configuration, the Dcm 
*                    identifies the required size from the largest PID
*                    in order to configure a PIDBuffer..
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID21
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint32 milOnDistance;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID21value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

            milOnDistance = ptr->odoMilOn;

#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            PID21value[DEM_BYTE_ONE] = (uint8)((milOnDistance & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
            PID21value[DEM_BYTE_ZERO] = (uint8)(milOnDistance & (uint32)DEM_WORD_LOW_BYTE);
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
            PID21value[DEM_BYTE_ZERO] = (uint8)((milOnDistance & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
            PID21value[DEM_BYTE_ONE] = (uint8)(milOnDistance & (uint32)DEM_WORD_LOW_BYTE);
#else
            PID21value[DEM_BYTE_ZERO] = DEM_INIT_ZERO;
            PID21value[DEM_BYTE_ONE] = DEM_INIT_ZERO;
#endif
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID21_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID29
*
* Explanation: Service to report the value of PID $29 computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID29value: Buffer containing the contents of PID $29 computed
*                    by the Dem. The buffer is provided by the Dcm with the 
*                    appropriate size, i.e. during configuration, the Dcm 
*                    identifies the required size from the largest PID
*                    in order to configure a PIDBuffer..
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID29
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID29value
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint32 valOfPid29;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID29value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            valOfPid29 = DEM_GET_OBD_PID29_VALUE();
#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            PID29value[DEM_BYTE_THREE] = (uint8)(valOfPid29 >> (DEM_BYTE_THREE * DEM_BYTE_EIGHT));
            PID29value[DEM_BYTE_TWO] = (uint8)(valOfPid29 >> (DEM_BYTE_TWO * DEM_BYTE_EIGHT));
            PID29value[DEM_BYTE_ONE] = (uint8)(valOfPid29 >> DEM_BYTE_EIGHT);
            PID29value[DEM_BYTE_ZERO] = (uint8)valOfPid29;
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
            PID29value[DEM_BYTE_ZERO] = (uint8)(valOfPid29 >> (DEM_BYTE_THREE * DEM_BYTE_EIGHT));
            PID29value[DEM_BYTE_ONE] = (uint8)(valOfPid29 >> (DEM_BYTE_TWO * DEM_BYTE_EIGHT));
            PID29value[DEM_BYTE_TWO] = (uint8)(valOfPid29 >> DEM_BYTE_EIGHT);
            PID29value[DEM_BYTE_THREE] = (uint8)valOfPid29;
#else
            PID29value[DEM_BYTE_ZERO] = DEM_INIT_ZERO;
            PID29value[DEM_BYTE_ONE] = DEM_INIT_ZERO;
            PID29value[DEM_BYTE_TWO] = DEM_INIT_ZERO;
            PID29value[DEM_BYTE_THREE] = DEM_INIT_ZERO;
#endif
            
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID21_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID30
*
* Explanation: Service to report the value of PID $30 computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID21value: Buffer containing the contents of PID $30 computed
*                    by the Dem. The buffer is provided by the Dcm with the 
*                    appropriate size, i.e. during configuration, the Dcm 
*                    identifies the required size from the largest PID
*                    in order to configure a PIDBuffer..
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID30
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID30value
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID30value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            PID30value[DEM_BYTE_ZERO] = ptr->warmUpCycleCnt;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID30_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID31
*
* Explanation: Service to report the value of PID $31 computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID31value: Buffer containing the contents of PID $31 computed
*                    by the Dem. The buffer is provided by the Dcm with the 
*                    appropriate size, i.e. during configuration, the Dcm 
*                    identifies the required size from the largest PID
*                    in order to configure a PIDBuffer..
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID31
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID31value
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint32 sinceDtcClearDistance;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID31value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

            sinceDtcClearDistance = ptr->odoSinceDtcClear;

#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            PID31value[DEM_BYTE_ONE] = (uint8)((sinceDtcClearDistance & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
            PID31value[DEM_BYTE_ZERO] = (uint8)(sinceDtcClearDistance & (uint32)DEM_WORD_LOW_BYTE);
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
            PID31value[DEM_BYTE_ZERO] = (uint8)((sinceDtcClearDistance & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
            PID31value[DEM_BYTE_ONE] = (uint8)(sinceDtcClearDistance & (uint32)DEM_WORD_LOW_BYTE);
#else
            PID31value[DEM_BYTE_ZERO] = DEM_INIT_ZERO;
            PID31value[DEM_BYTE_ONE] = DEM_INIT_ZERO;
#endif
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID31_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID41
*
* Explanation: Service to report the value of PID $41 computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID41value: Buffer containing the contents of PID $41 computed
*                    by the Dem. The buffer is provided by the Dcm with the 
*                    appropriate size, i.e. during configuration, the Dcm 
*                    identifies the required size from the largest PID
*                    in order to configure a PIDBuffer..
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID41
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41value
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */    
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID41value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            Dem_ObdGetDataOfPID41(PID41value);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID41_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID42
*
* Explanation: Service to report the value of PID $42 computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID41value: Buffer containing the contents of PID $42 computed
*                    by the Dem. The buffer is provided by the Dcm with the 
*                    appropriate size, i.e. during configuration, the Dcm 
*                    identifies the required size from the largest PID
*                    in order to configure a PIDBuffer..
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID42
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID42value
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 valOfPid42;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID42value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            valOfPid42 = DEM_GET_OBD_PID42_VALUE();
#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            PID42value[DEM_BYTE_ONE] = (uint8)(valOfPid42 >> DEM_BYTE_EIGHT);
            PID42value[DEM_BYTE_ZERO] = (uint8)valOfPid42;
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
            PID42value[DEM_BYTE_ZERO] = (uint8)(valOfPid42 >> DEM_BYTE_EIGHT);
            PID42value[DEM_BYTE_ONE] = (uint8)valOfPid42;
#else
            PID42value[DEM_BYTE_ZERO] = DEM_INIT_ZERO;
            PID42value[DEM_BYTE_ONE] = DEM_INIT_ZERO;
#endif
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID42_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID46
*
* Explanation: Service to report the value of PID $46 computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID46value: Buffer containing the contents of PID $46 computed
*                    by the Dem. The buffer is provided by the Dcm with the 
*                    appropriate size, i.e. during configuration, the Dcm 
*                    identifies the required size from the largest PID
*                    in order to configure a PIDBuffer..
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID46
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID46value
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID46value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
#if(DEM_CFG_OBD_AMBIENT_TEMP > DEM_INIT_ZERO)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            PID46value[DEM_BYTE_ZERO] = (uint8)Dem_ObdGetGeneralData(DEM_CFG_OBD_AMBIENT_TEMP);
#else
            PID46value[DEM_BYTE_ZERO] = DEM_INIT_ZERO;
#endif
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID46_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID49
*
* Explanation: Service to report the value of PID $49 computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID49value: Buffer containing the contents of PID $49 computed
*                    by the Dem. The buffer is provided by the Dcm with the 
*                    appropriate size, i.e. during configuration, the Dcm 
*                    identifies the required size from the largest PID
*                    in order to configure a PIDBuffer..
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID49
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID49value
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID49value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
#if(DEM_CFG_OBD_ACC_PEDAL_INFO > DEM_INIT_ZERO)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            PID49value[DEM_BYTE_ZERO] = (uint8)Dem_ObdGetGeneralData(DEM_CFG_OBD_ACC_PEDAL_INFO);
#else
            PID49value[DEM_BYTE_ZERO] = DEM_INIT_ZERO;
#endif
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID49_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID4D
*
* Explanation: Service to report the value of PID $4D computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID4Dvalue: Buffer containing the contents of PID $4D computed
*                    by the Dem. The buffer is provided by the Dcm with the 
*                    appropriate size, i.e. during configuration, the Dcm 
*                    identifies the required size from the largest PID
*                    in order to configure a PIDBuffer..
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4D
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Dvalue
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint32 engineRuntimeWhileMilOn;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID4Dvalue)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

            engineRuntimeWhileMilOn = ptr->engineRuntimeWhileMilOn;

#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            PID4Dvalue[DEM_BYTE_ONE] = (uint8)((engineRuntimeWhileMilOn & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
            PID4Dvalue[DEM_BYTE_ZERO] = (uint8)(engineRuntimeWhileMilOn & (uint32)DEM_WORD_LOW_BYTE);
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
            PID4Dvalue[DEM_BYTE_ZERO] = (uint8)((engineRuntimeWhileMilOn & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
            PID4Dvalue[DEM_BYTE_ONE] = (uint8)(engineRuntimeWhileMilOn & (uint32)DEM_WORD_LOW_BYTE);
#else
            PID4Dvalue[DEM_BYTE_ZERO] = DEM_INIT_ZERO;
            PID4Dvalue[DEM_BYTE_ONE] = DEM_INIT_ZERO;
#endif
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID4D_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID4E
*
* Explanation: Service to report the value of PID $4E computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID4Evalue: Buffer containing the contents of PID $4E computed
*                    by the Dem. The buffer is provided by the Dcm with the 
*                    appropriate size, i.e. during configuration, the Dcm 
*                    identifies the required size from the largest PID
*                    in order to configure a PIDBuffer..
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4E
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Evalue
)
{
/* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint32 engineRuntimeSinceDtcClear;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID4Evalue)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
            
            engineRuntimeSinceDtcClear = ptr->engineRuntimeSinceDtcClear;
            
#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            PID4Evalue[DEM_BYTE_ONE] = (uint8)((engineRuntimeSinceDtcClear & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
            PID4Evalue[DEM_BYTE_ZERO] = (uint8)(engineRuntimeSinceDtcClear & (uint32)DEM_WORD_LOW_BYTE);
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
            PID4Evalue[DEM_BYTE_ZERO] = (uint8)((engineRuntimeSinceDtcClear & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
            PID4Evalue[DEM_BYTE_ONE] = (uint8)(engineRuntimeSinceDtcClear & (uint32)DEM_WORD_LOW_BYTE);
#else
            PID4Evalue[DEM_BYTE_ZERO] = DEM_INIT_ZERO;
            PID4Evalue[DEM_BYTE_ONE] = DEM_INIT_ZERO;
#endif
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID4E_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID91
*
* Explanation: Service to report the value of PID $91 computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID91value: Buffer containing the contents of PID $91 computed
*                    by the Dem. The buffer is provided by the Dcm with the 
*                    appropriate size, i.e. during configuration, the Dcm 
*                    identifies the required size from the largest PID
*                    in order to configure a PIDBuffer..
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID91
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID91value
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
    Dem_PermanentEventMemoryEntry_st *ptr;
#endif    
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID91value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
            ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();
            /* Byte A, MIL status */
            if(DEM_INDICATOR_OFF == DEM_GET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF))
            {
                PID91value[DEM_BYTE_ZERO] = DEM_BYTE_ZERO;
            }
            else if(DEM_INDICATOR_ON_DEMAND == DEM_GET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF))
            {
                PID91value[DEM_BYTE_ZERO] = DEM_BYTE_ONE;
            }
            else if(DEM_INDICATOR_SHORT == DEM_GET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF))
            {
                PID91value[DEM_BYTE_ZERO] = DEM_BYTE_TWO;
            }
            else if(DEM_INDICATOR_CONTINUOUS == DEM_GET_INDICATOR_STATUS(DEM_CFG_MILINDICATORREF))
            {
                PID91value[DEM_BYTE_ZERO] = DEM_BYTE_THREE;
            }
            else
            {
                PID91value[DEM_BYTE_ZERO] = DEM_BYTE_LOW;
            }

            /* Byte B&C */
            PID91value[DEM_BYTE_ONE] = (uint8)(ptr->wwhContiMiCnt & DEM_BYTE_MAX);
            PID91value[DEM_BYTE_TWO] = (uint8)(ptr->wwhContiMiCnt >> DEM_BYTE_EIGHT);

            /* Byte D&E */
            PID91value[DEM_BYTE_THREE] = (uint8)(ptr->wwhB1CntHighest & DEM_BYTE_MAX);
            PID91value[DEM_BYTE_FOUR] = (uint8)(ptr->wwhB1CntHighest >> DEM_BYTE_EIGHT);
#else
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            PID91value[DEM_BYTE_ZERO] = DEM_BYTE_LOW;
            PID91value[DEM_BYTE_ONE] = DEM_INIT_ZERO;
            PID91value[DEM_BYTE_TWO] = DEM_INIT_ZERO;
            PID91value[DEM_BYTE_THREE] = DEM_INIT_ZERO;
            PID91value[DEM_BYTE_FOUR] = DEM_INIT_ZERO;
#endif
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMREADDATAOFPID91_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmReadDataOfOBDFreezeFrame
*
* Explanation: Gets data element per PID and index of the most important freeze 
*              frame being selected for the output of service $02. The function
*              stores the data in the provided DestBuffer.
*
* param: PID: This parameter is an identifier for a PID as defined in ISO15031-5.
*        DataElementIndexOfPID: Data element index of this PID according to the
*                            Dcm configuration of service $02. It is zero-based
*                            and consecutive, and ordered by the data element
*                            positions.
*        DestBuffer: This parameter contains a byte pointer that points to
*                     the buffer, to which the data element of the PID shall
*                     be written to. The format is raw hexadecimal values
*                     and contains no header-information.
*        BufSize: When the function is called this parameter contains
*                 the maximum number of data bytes that can be
*                 written to the buffer. The function returns the actual number
*                 of written data bytes in this parameter.
*
* retval: E_OK Freeze frame data was successfully reported
*         E_NOT_OK Freeze frame data was not successfully reported
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfOBDFreezeFrame
(
    uint8 PID,
    uint8 DataElementIndexOfPID,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */    
    uint8 errorId = DEM_E_NO_ERROR;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((NULL_PTR == DestBuffer) || (NULL_PTR == BufSize))
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            returnValue = Dem_ObdGetFFRecordPID(PID, 
                                                    DataElementIndexOfPID, 
                                                    DestBuffer, 
                                                    BufSize);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_DCMREADDATAOFOBDFREEZEFRAME_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetDTCOfOBDFreezeFrame
*
* Explanation: Gets DTC by freeze frame record number.
*
* param: FrameNumber: Unique identifier for a freeze frame record as defined
*                     in ISO 15031-5. The value 0x00 indicates the complete
*                     OBD freeze frame. Other values are reserved for future
*                     functionality.
*        DTCFormat: Output format of the DTC value.
*        DTC: Diagnostic Trouble Code in ODB format. If the reture value of 
*             the function is other than E_OK this parameter does not contain
*             valid data.
*
* retval: E_OK: operation was successful
*         E_NOT_OK: no DTC available
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCOfOBDFreezeFrame
(
    uint8 FrameNumber,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    Dem_DTCFormatType DTCFormat
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */    
    uint8 errorId = DEM_E_NO_ERROR;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == DTC)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            returnValue = Dem_ObdGetFFRecordDTC(FrameNumber,
                                                     DTC, 
                                                     DTCFormat);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_DCMGETDTCOFOBDFREEZEFRAME_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetAvailableOBDMIDs
*
* Explanation: Reports the value of a requested "availability-OBDMID" to the DCM
*              upon a Service $06 request. Derived from that the tester displays
*              the supported tests a mechanic can select from. API is needed in
*              OBD-relevant ECUs only.
*
* param: Obdmid: Availablity OBDMID ($00,$20, $40...)
*        Obdmidvalue: Bit coded information on the support of OBDMIDs.
*
* retval: E_OK: Report of DTR result successful
*         E_NOT_OK: Report of DTR result failed
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetAvailableOBDMIDs
(
    uint8 Obdmid, 
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) Obdmidvalue
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 bitMask = DEM_INIT_ZERO;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtrIdx;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == Obdmidvalue)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            if((Obdmid % DEM_BYTE_THIRTY_TWO) == DEM_VALUE_ZERO)
            {
                /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                *Obdmidvalue = DEM_INIT_ZERO;
                for(dtrIdx = DEM_INIT_ONE; dtrIdx <= DEM_CFG_DTR_NUM; dtrIdx++)
                {
                    if((Dem_ConfigDtrTable[dtrIdx].dtrMid > Obdmid) &&
                       (Dem_ConfigDtrTable[dtrIdx].dtrMid < (Obdmid + DEM_BYTE_THIRTY_TWO)))
                    {
                        bitMask = Dem_ConfigDtrTable[dtrIdx].dtrMid - Obdmid;
                        /* The available bits of OBD mid are arranged from high to low. */
                        *Obdmidvalue |= (uint32)DEM_VALUE_ONE << (DEM_BYTE_THIRTY_TWO - bitMask);
                    }
                    /* Check the next range if exists the dtrs. */
                    if((Dem_ConfigDtrTable[dtrIdx].dtrMid > (Obdmid + DEM_BYTE_THIRTY_TWO)) &&
                       (Dem_ConfigDtrTable[dtrIdx].dtrMid < (Obdmid + DEM_BYTE_SIXTY_FOUR)))
                    {
                        *Obdmidvalue |= (uint32)DEM_VALUE_ONE;
                    }
                }

                returnValue = E_OK;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETAVAILABLEOBDMIDS_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetNumTIDsOfOBDMID
*
* Explanation: Gets the number of TIDs per (functional) OBDMID. This can be used
*              by the DCM to iteratively request for OBD/TID result data within
*              a loop from 0....numberOfTIDs-1 API is needed in OBD-relevant ECUs
*              only.
*
* param: Obdmid: Availablity OBDMID ($00,$20, $40...)
*        numberOfTIDs: Number of assigned TIDs for the requested OBDMID.
*                      Used as loop value for the DCM to retrieve all
*                      OBD/TID result data.
*
* retval: E_OK: get number of TIDs successful
*         E_NOT_OK: get number of TIDs failed
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetNumTIDsOfOBDMID
(
    uint8 Obdmid, 
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) numberOfTIDs
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtrIdx;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == numberOfTIDs)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            *numberOfTIDs = DEM_BYTE_ZERO;
    
            for(dtrIdx = DEM_INIT_ONE; dtrIdx <= DEM_CFG_DTR_NUM; dtrIdx++)
            {
                if(Obdmid == Dem_ConfigDtrTable[dtrIdx].dtrMid)
                {
                    *numberOfTIDs += DEM_BYTE_ONE;
                    returnValue = E_OK;
                }
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETNUMTIDSOFOBDMID_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetDTRData
*
* Explanation: Reports a DTR data along with TID-value, UaSID, test result
*              with lower and upper limit.
*
* param: Obdmid: Identification of a DTR element by assigned DTRId.
*        TIDindex: Index of the TID within the DEM. Runs from 0
*                  to "numberOfTIDs" obtained in the call to 
*                  Dem_DcmGetNumTIDsOfOBDMID()
*        TIDvalue: TID to be put on the tester reponse
*        UaSID: UaSID to be put on the tester reponse
*        Testvalue: Latest test result
*        Lowlimvalue: Lower limit value associated to the latest test result
*        Upplimvalue: Upper limit value associated to the latest test result
*
* retval: E_OK: Report of DTR result successful
*         E_NOT_OK: Report of DTR result failed
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTRData
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
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */        
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((NULL_PTR == TIDvalue) || (NULL_PTR == UaSID) ||
           (NULL_PTR == Testvalue) || (NULL_PTR == Lowlimvalue) || 
           (NULL_PTR == Upplimvalue))
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            returnValue = Dem_ObdGetDtrData(Obdmid, 
                                            TIDindex,
                                            TIDvalue, 
                                            UaSID,
                                            Testvalue, 
                                            Lowlimvalue, 
                                            Upplimvalue);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETDTRDATA_APIID, errorId);
    
    return returnValue;
}
#endif

/*
********************************************************************************
* Function Name: Dem_DltGetMostRecentFreezeFrameRecordData
*
* Explanation: Gets the data of an most recent freeze frame record by event.
*              The OBD-II freeze frame is not returned by this function.
*
* param: EventId: Identification of an event by assigned EventId.
*        BufSize: When the function is called this parameter contains
*                 the maximum number of data bytes that can be written
*                 to the buffer. The function returns the actual number 
*                 of written data bytes in this parameter.
*        DestBuffer: This parameter contains a byte pointer that points
*                    to the buffer, to which the freeze frame record shall
*                    be written to. The format is raw hexadecimal values
*                    and contains no header-information.
*
* retval: E_OK: Operation was successful.
*         DEM_E_NODATAAVAILABLE: The requested event data is not currently 
*                                stored (but the request was valid).
*         DEM_E_PENDING: The requested data is currently transported from
*                       NvM and needs to be requested again.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DltGetMostRecentFreezeFrameRecordData
(
    Dem_EventIdType EventId,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 evtIdx;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((EventId > DEM_INIT_ZERO) &&
           (EventId <= DEM_CFG_EVENT_ID_MAX) &&
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO) &&
           (TRUE == DEM_GET_AVAIL(Dem_CfgEventIdTableIndex[EventId])))
#else
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO))
#endif
        {
            if((NULL_PTR == DestBuffer) || (NULL_PTR == BufSize))
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                errorId = DEM_E_PARAM_POINTER;
            }
            else
            {
                evtIdx = Dem_CfgEventIdTableIndex[EventId];
                returnValue = Dem_EventGetRecentlyFFRecordData(evtIdx, DestBuffer, BufSize);
            }
        }
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DLTGETMOSTRECENTFREEZEFRAMERECORDDATA_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DltGetAllExtendedDataRecords
*
* Explanation: Gets the data of all extended data records of an event.
*
* param: EventId: Identification of an event by assigned EventId.
*        BufSize: When the function is called this parameter contains
*                 the maximum number of data bytes that can be written
*                 to the buffer. The function returns the actual number 
*                 of written data bytes in this parameter.
*        DestBuffer: This parameter contains a byte pointer that points
*                    to the buffer, to which the extended data shall
*                    be written to. The format is raw hexadecimal values
*                    and contains no header-information.
*
* retval: E_OK: Operation was successful.
*         DEM_E_NODATAAVAILABLE: The requested event data is not currently 
*                                stored (but the request was valid).
*         DEM_E_PENDING: The requested data is currently transported from
*                       NvM and needs to be requested again.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DltGetAllExtendedDataRecords
(
    Dem_EventIdType EventId,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 evtMemIdx;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((EventId > DEM_INIT_ZERO) &&
           (EventId <= DEM_CFG_EVENT_ID_MAX) &&
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO) &&
           (TRUE == DEM_GET_AVAIL(Dem_CfgEventIdTableIndex[EventId])))
#else
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO))
#endif
        {
            if((NULL_PTR == DestBuffer) || (NULL_PTR == BufSize))
            /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                errorId = DEM_E_PARAM_POINTER;
            }
            else
            {
                dtcIdx = Dem_CfgEvtDtcIdx[Dem_CfgEventIdTableIndex[EventId]];
                /* Only get data from primary event memory */
                evtMemIdx = DEM_EVENT_MEMORY_PRIMARY;
                returnValue = Dem_DTCGetAllExRecordData(dtcIdx, evtMemIdx, DestBuffer, BufSize);
                if(DEM_RECORD_OK == returnValue)
                {
                    returnValue = E_OK;
                }
                /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                else if(DEM_RECORD_WRONG_BUFFERSIZE == returnValue)
                {
                    returnValue = DEM_E_WRONG_BUFFERSIZE;
                /* PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                }
                else
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    returnValue = DEM_E_NODATAAVAILABLE;
                }
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DLTGETALLEXTENDEDDATARECORD_APIID, errorId);
    
    return returnValue;
}


#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
/*
********************************************************************************
* Function Name: Dem_SetEventDisabled
*
* Explanation: Service for reporting the event as disabled to the Dem for 
               the PID $41 computation.
*
* param: EventId: Identification of an event by assigned EventId.
*
* retval: E_OK set of event to disabled was successfull.
*         E_NOT_OK set of event disabled failed.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventDisabled
(
    Dem_EventIdType EventId
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 evtIdx;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((EventId > DEM_INIT_ZERO) &&
           (EventId <= DEM_CFG_EVENT_ID_MAX) &&
#if(DEM_CFG_AVAILABLITYSUPPORT == DEM_EVENT_AVAILABILITY)
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO) &&
           (TRUE == DEM_GET_AVAIL(Dem_CfgEventIdTableIndex[EventId])))
#else
           (Dem_CfgEventIdTableIndex[EventId] > DEM_INIT_ZERO))
#endif
        {
            evtIdx = Dem_CfgEventIdTableIndex[EventId];
            DEM_SET_OBD_EVENT_DISABLE_PID41(evtIdx, TRUE);
            returnValue = E_OK;
        }
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_SETEVENTDISABLED_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_RepIUMPRFaultDetect
*
* Explanation: Service for reporting that faults are possibly found because 
*              all conditions are fullfilled.
*
* param: RatioID: Ratio Identifier reporting that a respective monitor
*                 could have found a fault - only used when interface
*                 option "API" is selected
*
* retval: E_OK report of IUMPR result was successfully reported.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRFaultDetect
(
    Dem_RatioIdType RatioID
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 ratioIdx;
    uint16 evtIdx;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
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
                        DEM_SET_OBD_IUPR_NUM_COND_ASYM(ratioIdx, TRUE);
                        returnValue = E_OK;
                    }
                }
                else
                {
                    DEM_SET_OBD_IUPR_NUM_COND_ASYM(ratioIdx, TRUE);
                    returnValue = E_OK;
                }
                break;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_REPIUMPRFAULTDETECT_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_SetIUMPRDenCondition
*
* Explanation: In order to communicate the status of the (additional) denominator 
*              conditions among the OBD relevant ECUs, the API is used to forward
*              the condition status to a Dem of a particular ECU.
*
* param: ConditionId: Identification of a IUMPR denominator condition ID
*                 (General Denominator, Cold start, EVAP, 500mi).
*        ConditionStatus: Status of the IUMPR denominator condition
*                         (Notreached, reached, not reachable / inhibited)
*
* retval: E_OK: set of IUMPR denominator condition was successful
*         E_NOT_OK: set of IUMPR denominator condition failed or could not 
*                   be accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetIUMPRDenCondition
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    Dem_IumprDenomCondIdType ConditionId,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    Dem_IumprDenomCondStatusType ConditionStatus
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        switch(ConditionId)
        {
            case DEM_IUMPR_GENERAL_DENOMINATOR:
            {
                DEM_SET_OBD_IUPR_DEN_COND(DEM_IUMPR_DEN_GENERAL, ConditionStatus);
                returnValue = E_OK;
                break;
            }
            case DEM_IUMPR_DEN_COND_COLDSTART:
            {
                DEM_SET_OBD_IUPR_DEN_COND(DEM_IUMPR_DEN_COLDSTART, ConditionStatus);
                returnValue = E_OK;
                break;
            }
            case DEM_IUMPR_DEN_COND_EVAP:
            {
                DEM_SET_OBD_IUPR_DEN_COND(DEM_IUMPR_DEN_EVAP, ConditionStatus);
                returnValue = E_OK;
                break;
            }
            case DEM_IUMPR_DEN_COND_500MI:
            {
                DEM_SET_OBD_IUPR_DEN_COND(DEM_IUMPR_DEN_500MILL, ConditionStatus);
                returnValue = E_OK;
                break;
            }
            default:
            {
                break;
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_SETIUMPRDENCONDITION_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_GetIUMPRDenCondition
*
* Explanation: In order to communicate the status of the (additional) denominator 
*              conditions among the OBD relevant ECUs, the API is used to forward
*              the condition status to a Dem of a particular ECU.
*
* param: ConditionId: Identification of a IUMPR denominator condition ID
*                 (General Denominator, Cold start, EVAP, 500mi).
*        ConditionStatus: Status of the IUMPR denominator condition
*                         (Notreached, reached, not reachable / inhibited)
*
* retval: E_OK: set of IUMPR denominator condition was successful
*         E_NOT_OK: set of IUMPR denominator condition failed or could not 
*                   be accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetIUMPRDenCondition
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    Dem_IumprDenomCondIdType ConditionId,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(Dem_IumprDenomCondStatusType, AUTOMATIC, DEM_APPL_DATA) ConditionStatus
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == ConditionStatus)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            switch(ConditionId)
            {
                case DEM_IUMPR_GENERAL_DENOMINATOR:
                {
                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                    *ConditionStatus = DEM_GET_OBD_IUPR_DEN_COND(DEM_IUMPR_DEN_GENERAL);
                    returnValue = E_OK;
                    break;
                }
                case DEM_IUMPR_DEN_COND_COLDSTART:
                {
                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                    *ConditionStatus = DEM_GET_OBD_IUPR_DEN_COND(DEM_IUMPR_DEN_COLDSTART);
                    returnValue = E_OK;
                    break;
                }
                case DEM_IUMPR_DEN_COND_EVAP:
                {
                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                    *ConditionStatus = DEM_GET_OBD_IUPR_DEN_COND(DEM_IUMPR_DEN_EVAP);
                    returnValue = E_OK;
                    break;
                }
                case DEM_IUMPR_DEN_COND_500MI:
                {
                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                    *ConditionStatus = DEM_GET_OBD_IUPR_DEN_COND(DEM_IUMPR_DEN_500MILL);
                    returnValue = E_OK;
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_GETIUMPRDENCONDITION_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_GetIUMPRDenCondition
*
* Explanation: Service is used to lock a denominator of a specific monitor.
*
* param: RatioID: Ratio Identifier reporting that specific denominator
*                 is locked (for physical reasons - e.g. temperature
*                 conditions or minimum activity)
*
* retval: E_OK report of IUMPR denominator status was successfully
*         E_NOK report of IUMPR denominator status was not successfully
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenLock
(
    Dem_RatioIdType RatioID
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */        
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        returnValue = Dem_ObdSetIUMPRDenPhsyCondition(RatioID, 
                                              DEM_IUMPR_DEN_STATUS_NOT_REACHED);
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_REPIUMPRDENLOCK_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_RepIUMPRDenRelease
*
* Explanation: Service is used to release a denominator of a specific monitor.
*
* param: RatioID: Ratio Identifier reporting that specific denominator
*                 is locked (for physical reasons - e.g. temperature
*                 conditions or minimum activity)
*
* retval: E_OK report of IUMPR denominator status was successfully
*         E_NOK report of IUMPR denominator status was not successfully
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenRelease
(
    Dem_RatioIdType RatioID
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */        
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        returnValue = Dem_ObdSetIUMPRDenPhsyCondition(RatioID,
                                            DEM_IUMPR_DEN_STATUS_REACHED);
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_REPIUMPRDENRELEASE_APIID, errorId);
    
    return returnValue;
}

#if(DEM_CFG_PTOSUPPORT == STD_ON)
/*
********************************************************************************
* Function Name: Dem_SetPtoStatus
*
* Explanation: API is needed in OBD-relevant ECUs only
*
* param: PtoStatus: sets the status of the PTO (TRUE==active;FALSE==inactive)
*
* retval: Returns E_OK when the new PTO-status has been 
*         adopted by the Dem; returns E_NOT_OK in all other cases.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetPtoStatus
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    boolean PtoStatus
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */            
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        DEM_SET_OBD_IUPR_PTO_STATUS(PtoStatus);
        returnValue = E_OK;
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_SETPTOSTATUS_APIID, errorId);
    
    return returnValue;
}
#endif

/*
********************************************************************************
* Function Name: Dem_ReadDataOfPID01
*
* Explanation: Service to report the value of PID $01 computed by the Dem.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID01value: Buffer containing the contents of PID $01 computed
*                    by the Dem. The buffer is provided by the application
 *                    with the of 4 bytes.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ReadDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01value
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */    
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID01value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            Dem_ObdGetDataOfPID01(PID01value);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_READDATAOFPID01_APIID, errorId);
    
    return returnValue;
}

#if((DEM_CFG_OBD_PID21_CENTRALIZED == TRUE) && (DEM_CFG_OBDSUPPORT == DEM_OBD_MASTER_ECU))
/*
********************************************************************************
* Function Name: Dem_GetDataOfPID21
*
* Explanation: Service to get the value of PID $21 in the Dem by a software component.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID21value: Content of PID $21 as raw hex value.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value
)
{
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint32 milOnDistance;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID21value)
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

            milOnDistance = ptr->odoMilOn;

#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
            PID21value[DEM_BYTE_ONE] = (uint8)((milOnDistance & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
            PID21value[DEM_BYTE_ZERO] = (uint8)(milOnDistance & (uint32)DEM_WORD_LOW_BYTE);
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
            PID21value[DEM_BYTE_ZERO] = (uint8)((milOnDistance & (uint32)DEM_WORD_HIGH_BYTE) >> DEM_BYTE_EIGHT);
            PID21value[DEM_BYTE_ONE] = (uint8)(milOnDistance & (uint32)DEM_WORD_LOW_BYTE);
#else
            PID21value[DEM_BYTE_ONE] = DEM_VALUE_ZERO;
            PID21value[DEM_BYTE_ZERO] = DEM_VALUE_ZERO;
#endif  /* DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN */
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_GETDATAOFPID21_APIID, errorId);
    
    return returnValue;
}
#endif

/*
********************************************************************************
* Function Name: Dem_SetDataOfPID04
*
* Explanation: Service to set the value of PID $04 in the Dem by a software component.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID04value: Buffer containing the contents of PID $04.
*                    The buffer is provided by the Dcm with the appropriate size,
*                    i.e. during configuration, the Dcm identifies
*                    the required size from the largest PID in order to
*                    configure a PIDBuffer.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID04
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID04value  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */    
    uint8 errorId = DEM_E_NO_ERROR;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID04value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            DEM_SET_OBD_PID04_VALUE(PID04value[DEM_BYTE_ZERO]);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_SETDATAOFPID04_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_SetDataOfPID21
*
* Explanation: Service to set the value of PID $21 in the Dem by a software component.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID21value: Buffer containing the contents of PID $21.
*                    The buffer is provided by the Dcm with the appropriate size,
*                    i.e. during configuration, the Dcm identifies
*                    the required size from the largest PID in order to
*                    configure a PIDBuffer.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID21
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint32 milOnDistance;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID21value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            milOnDistance = (uint32)PID21value[DEM_BYTE_ZERO] + (uint32)((uint32)PID21value[DEM_BYTE_ONE] << DEM_BYTE_EIGHT);
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
            milOnDistance = (uint32)PID21value[DEM_BYTE_ONE] + (uint32)((uint32)PID21value[DEM_BYTE_ZERO] << DEM_BYTE_EIGHT);
#else
            milOnDistance = DEM_INIT_ZERO;
#endif

            ptr->odoMilOn = milOnDistance;
            
            /* Trigger permanet block update */
            Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                           DEM_NVM_PERMANET_BLOCK,
                                           DEM_NVM_REQ_WRITE,
                                           FALSE);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_SETDATAOFPID21_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_SetDataOfPID29
*
* Explanation: Service to set the value of PID $29 in the Dem by a software component.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID29value: Buffer containing the contents of PID $29.
*                    The buffer is provided by the Dcm with the appropriate size,
*                    i.e. during configuration, the Dcm identifies
*                    the required size from the largest PID in order to
*                    configure a PIDBuffer.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID29
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID29value  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint32 valOfPid29;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID29value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            valOfPid29 = ((uint32)PID29value[DEM_BYTE_THREE] << (DEM_BYTE_THREE * DEM_BYTE_EIGHT)) + 
                         ((uint32)PID29value[DEM_BYTE_TWO] << (DEM_BYTE_TWO * DEM_BYTE_EIGHT)) +
                         ((uint32)PID29value[DEM_BYTE_ONE] << DEM_BYTE_EIGHT) +
                         (uint32)PID29value[DEM_BYTE_ZERO];
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
            valOfPid29 = ((uint32)PID29value[DEM_BYTE_ZERO] << (DEM_BYTE_THREE * DEM_BYTE_EIGHT)) + 
                         ((uint32)PID29value[DEM_BYTE_ONE] << (DEM_BYTE_TWO * DEM_BYTE_EIGHT)) +
                         ((uint32)PID29value[DEM_BYTE_TWO] << DEM_BYTE_EIGHT) +
                         (uint32)PID29value[DEM_BYTE_THREE];
#else
            valOfPid29 = DEM_INIT_ZERO;
#endif
            DEM_SET_OBD_PID29_VALUE(valOfPid29);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_SETDATAOFPID29_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_SetDataOfPID31
*
* Explanation: Service to set the value of PID $31 in the Dem by a software component.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID31value: Buffer containing the contents of PID $31.
*                    The buffer is provided by the Dcm with the appropriate size,
*                    i.e. during configuration, the Dcm identifies
*                    the required size from the largest PID in order to
*                    configure a PIDBuffer.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID31
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID31value  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint32 sinceDtcClearDistance;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID31value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            sinceDtcClearDistance = (uint32)PID31value[DEM_BYTE_ZERO] + (uint32)((uint32)PID31value[DEM_BYTE_ONE] << DEM_BYTE_EIGHT);
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
            sinceDtcClearDistance = (uint32)PID31value[DEM_BYTE_ONE] + (uint32)((uint32)PID31value[DEM_BYTE_ZERO] << DEM_BYTE_EIGHT);
#else
            sinceDtcClearDistance = DEM_INIT_ZERO;
#endif

            ptr->odoSinceDtcClear = sinceDtcClearDistance;
            
            /* Trigger permanet block update */
            Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                           DEM_NVM_PERMANET_BLOCK,
                                           DEM_NVM_REQ_WRITE,
                                           FALSE);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_SETDATAOFPID31_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_SetDataOfPID42
*
* Explanation: Service to set the value of PID $42 in the Dem by a software component.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID42value: Buffer containing the contents of PID $42.
*                    The buffer is provided by the Dcm with the appropriate size,
*                    i.e. during configuration, the Dcm identifies
*                    the required size from the largest PID in order to
*                    configure a PIDBuffer.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID42
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID42value  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
/* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 valOfPid42;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID42value)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {    
#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            valOfPid42 = (uint16)PID42value[DEM_BYTE_ZERO] + (uint16)((uint16)PID42value[DEM_BYTE_ONE] << DEM_BYTE_EIGHT);
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
            valOfPid42 = (uint16)PID42value[DEM_BYTE_ONE] + (uint16)((uint16)PID42value[DEM_BYTE_ZERO] << DEM_BYTE_EIGHT);
#else
            valOfPid42 = DEM_INIT_ZERO;
#endif
            DEM_SET_OBD_PID42_VALUE(valOfPid42);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_SETDATAOFPID42_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_SetDataOfPID4D
*
* Explanation: Service to set the value of PID $4D in the Dem by a software component.
*              API is needed in OBD-relevant ECUs only.
*
* param: PID4Dvalue: Buffer containing the contents of PID $4D.
*                    The buffer is provided by the Dcm with the appropriate size,
*                    i.e. during configuration, the Dcm identifies
*                    the required size from the largest PID in order to
*                    configure a PIDBuffer.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4D
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Dvalue  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint32 engineRuntimeWhileMilOn;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID4Dvalue)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            engineRuntimeWhileMilOn = (uint32)PID4Dvalue[DEM_BYTE_ZERO] + (uint32)((uint32)PID4Dvalue[DEM_BYTE_ONE] << DEM_BYTE_EIGHT);
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
            engineRuntimeWhileMilOn = (uint32)PID4Dvalue[DEM_BYTE_ONE] + (uint32)((uint32)PID4Dvalue[DEM_BYTE_ZERO] << DEM_BYTE_EIGHT);
#else
            engineRuntimeWhileMilOn = DEM_INIT_ZERO;
#endif

            ptr->engineRuntimeWhileMilOn = engineRuntimeWhileMilOn;
            
            /* Trigger permanet block update */
            Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                           DEM_NVM_PERMANET_BLOCK,
                                           DEM_NVM_REQ_WRITE,
                                           FALSE);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_SETDATAOFPID4D_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_SetDataOfPID4E
*
* Explanation: Service to set the value of PID $4E in the Dem by a software
*              component. API is needed in OBD-relevant ECUs only.
*
* param: PID4Evalue: Buffer containing the contents of PID $4E.
*                    The buffer is provided by the Dcm with the appropriate size,
*                    i.e. during configuration, the Dcm identifies
*                    the required size from the largest PID in order to
*                    configure a PIDBuffer.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4E
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Evalue  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Dem_UnmodifiedVariableNotConst-qualified" */
    Std_ReturnType returnValue = E_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint32 engineRuntimeSinceDtcClear;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == PID4Evalue)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

#if(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_LITTLE_ENDIAN)
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            engineRuntimeSinceDtcClear = (uint32)PID4Evalue[DEM_BYTE_ZERO] + (uint32)((uint32)PID4Evalue[DEM_BYTE_ONE] << DEM_BYTE_EIGHT);
#elif(DEM_CFG_DATAELEMENTDEFAULTENDIANNESS == DEM_EXDATA_BIG_ENDIAN)
            engineRuntimeSinceDtcClear = (uint32)PID4Evalue[DEM_BYTE_ONE] + (uint32)((uint32)PID4Evalue[DEM_BYTE_ZERO] << DEM_BYTE_EIGHT);
#else
            engineRuntimeSinceDtcClear = DEM_INIT_ZERO;
#endif

            ptr->engineRuntimeWhileMilOn = engineRuntimeSinceDtcClear;
            
            /* Trigger permanet block update */
            Dem_EventMemoryNvmBlkUpdateReq(DEM_INIT_ZERO,
                                           DEM_NVM_PERMANET_BLOCK,
                                           DEM_NVM_REQ_WRITE,
                                           FALSE);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_SETDATAOFPID4E_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_SetPfcCycleQualified
*
* Explanation: Marks the current OBD driving cycle as having met the criteria
*               for the PFC cycle.
*
* param: None
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetPfcCycleQualified(void)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */    
    uint8 errorId = DEM_E_NO_ERROR;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        DEM_SET_OBD_PFC_CYCLE_QUALIFIED(TRUE);
        returnValue = E_OK;
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_SETPFCCYCLEQUALIFIED_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_GetPfcCycleQualified
*
* Explanation: Returns TRUE if the criteria for the PFC cycle have been met 
*              during the current OBD driving cycle.
*
* param: isqualified: TRUE: During the current OBD driving cycle the criteria
*                     for the PFC cycle have been met.
*                     FALSE: During the current OBD driving cycle the criteria
*                     for the PFC cycle have not been met.
*
* retval: Always E_OK is returned, as E_NOT_OK will never appear.
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetPfcCycleQualified
(
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) isqualified
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */    
    uint8 errorId = DEM_E_NO_ERROR;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == isqualified)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
            *isqualified = DEM_GET_OBD_PFC_CYCLE_QUALIFIED();
            returnValue = E_OK;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_GETPFCCYCLEQUALIFIED_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_SetClearDTC
*
* Explanation: API to inform the Dem (of a Dependend / Secondary ECU) about the
*              reception of service $04 execution by a software component.
*
* param: DTC: Defines the DTC in respective format, that has been
*                     cleared from the event memory.
*        DTCFormat: Format of the provided DTC value.
*        DTCOrigin: Event memory (e.g. MIRROR)
*
* retval: Return value unused - only for compatibility with according RTE operation
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetClearDTC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
)
{
    Std_ReturnType returnValue = DEM_CLEAR_FAILED;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 evtMemIdx = DEM_INIT_ZERO;

    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        /* Permanent event memory is not possible to be cleared via this interface */
        if(DEM_DTC_ORIGIN_PERMANENT_MEMORY == DTCOrigin)
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_CLEAR_WRONG_DTCORIGIN;
        }
        else if(E_NOT_OK == Dem_EventCheckDTCOriginValid(DTCOrigin, &evtMemIdx))
        {
            errorId = DEM_E_PARAM_DATA;
            returnValue = DEM_CLEAR_WRONG_DTCORIGIN;
        }
        else
        {
            returnValue = Dem_EventClearDTC(DTC, 
                                            DTCFormat, 
                                            evtMemIdx, 
                                            DEM_CLEAR_DTC_CLIENT_OBD);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_SETCLEARDTC_APIID, errorId);
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetDTCSeverityAvailabilityMask
*
* Explanation: Gets the DTC Severity availability mask.
*
* param: DTCSeverityMask: The value DTCSeverityMask indicates the supported
*                         DTC severity bits from the Dem. All supported
*                         information is indicated by setting the corresponding
*                         status bit to 1. See ISO14229-1.
*
* retval: Std_ReturnType: E_OK: get of DTC severity mask was successful
*                         E_NOT_OK: get of DTC severity mask failed
********************************************************************************
*/

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCSeverityAvailabilityMask
(
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverityMask
)
{
    Std_ReturnType returnValue = E_NOT_OK; 
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */    
    uint8 errorId = DEM_E_NO_ERROR;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == DTCSeverityMask)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            for(dtcIdx = DEM_INIT_ONE; dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++)
            {
                /* DTC serverity information */
                if(DEM_SEVERITY_CHECK_IMMEDIATELY == Dem_CfgDTCTable[dtcIdx].acDtcSeverity)
                {
                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                    *DTCSeverityMask |= DEM_BYTE_MASK_BIT7;
                }
                else if(DEM_SEVERITY_CHECK_AT_NEXT_HALT == Dem_CfgDTCTable[dtcIdx].acDtcSeverity)
                {
                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                    *DTCSeverityMask |= DEM_BYTE_MASK_BIT6;
                }
                else if(DEM_SEVERITY_MAINTENANCE_ONLY == Dem_CfgDTCTable[dtcIdx].acDtcSeverity)
                {
                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                    *DTCSeverityMask |= DEM_BYTE_MASK_BIT5;
                }
                else
                {
                    /* Do nothing */
                }

                /* DTC class information */
                /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                if(DEM_SEVERITY_WWHOBD_CLASS_C == Dem_CfgDTCTable[dtcIdx].acWwhObdClass)
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    *DTCSeverityMask |= DEM_BYTE_MASK_BIT4;
                }
                /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                else if(DEM_SEVERITY_WWHOBD_CLASS_B2 == Dem_CfgDTCTable[dtcIdx].acWwhObdClass)
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    *DTCSeverityMask |= DEM_BYTE_MASK_BIT3;
                }
                /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                else if(DEM_SEVERITY_WWHOBD_CLASS_B1 == Dem_CfgDTCTable[dtcIdx].acWwhObdClass)
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    *DTCSeverityMask |= DEM_BYTE_MASK_BIT2;
                }
                /* Polyspace +1 DEFECT:DEAD_CODE [JUstified:Unset] "NSCA_Polyspace_Common_DEAD_CODE" PolySpace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                else if(DEM_SEVERITY_WWHOBD_CLASS_A == Dem_CfgDTCTable[dtcIdx].acWwhObdClass)
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    *DTCSeverityMask |= DEM_BYTE_MASK_BIT1;
                }
                /* Polyspace +1 DEFECT:USELESS_IF [JUstified:Unset] "NSCA_Polyspace_Common_UselessIf" PolySpace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_Dem_14.3" */
                else if(DEM_SEVERITY_WWHOBD_CLASS_NO_CLASS == Dem_CfgDTCTable[dtcIdx].acWwhObdClass)
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Dem_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Dem_D4.14" */
                    *DTCSeverityMask |= DEM_BYTE_MASK_BIT0;
                }
                else
                /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    /* Do nothing */
                }
            }
            
            returnValue = E_OK;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_DCMGETDTCSEVERITYAVAILABILITYMASK_APIID, errorId);
    
    return returnValue;
}

#if(DEM_CFG_WWH_OBD_SUPPORT == STD_ON)
/*
********************************************************************************
* Function Name: Dem_GetB1Counter
*
* Explanation: Service to report the value of the B1 counter computed by the Dem.
*
* param: B1Counter: Buffer containing the B1 counter. The buffer is provided by 
*                   the application with the size of 2 bytes.
*
* retval: Std_ReturnType: Always E_OK is returned, as E_NOT_OK will never appear
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetB1Counter
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) B1Counter
)
{
    Std_ReturnType returnValue = E_NOT_OK;
    uint8 errorId = DEM_E_NO_ERROR;
    Dem_PermanentEventMemoryEntry_st *ptr;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == B1Counter)
        {
            errorId = DEM_E_PARAM_POINTER;
        }
        else
        {
            ptr = DEM_GET_EVENT_MEMORY_PERMANENT_PTR();

            *B1Counter = ptr->wwhB1Cnt;

            returnValue = E_OK;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_GETB1COUNTER_APIID, errorId);
    
    return returnValue;
}
#endif

/*
********************************************************************************
* Function Name: Dem_SetDTR
*
* Explanation: Reports a DTR result with lower and upper limit. The internal 
*              eventstatus serves as master whether the DTR values are
*              forwarded or ignored, also taking the DTRUpdateKind into account.
*              The EventId that is related to the DTR is assigned per 
*              configuration (and derived from ServiceNeeds).Processing takes
*              enable/storage conditions into account.
*
* param: DTRId: Identification of a DTR element by assigned DTRId.
*        TestResult: Test result of DTR
*        LowerLimit: Lower limit of DTR
*        UpperLimit: Upper limit of DTR
*        Ctrlval: Control value of the DTR to support its interpretation
*                 Dem-internally.
*
* retval: Std_ReturnType: E_OK: Report of DTR result successful
*                         E_NOT_OK: Report of DTR result failed
********************************************************************************
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTR
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint16 DTRId,
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
    Std_ReturnType returnValue = E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint8 errorId = DEM_E_NO_ERROR;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtrIdx;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        for(dtrIdx = DEM_INIT_ONE; dtrIdx <= DEM_CFG_DTR_NUM; dtrIdx++)
        {
            if(DTRId == Dem_ConfigDtrTable[dtrIdx].dtrId)
            {
                break;
            }
        }

        if(dtrIdx <= DEM_CFG_DTR_NUM)
        {
            returnValue = Dem_ObdSetDtrData(dtrIdx, 
                                            TestResult,
                                            LowerLimit, 
                                            UpperLimit, 
                                            Ctrlval);
        }
        else
        {
            errorId = DEM_E_PARAM_DATA;
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }
    
    Dem_Det_ErrorReport(DEM_SETDTR_APIID, errorId);
    
    return returnValue;
}

#endif

/*
********************************************************************************
* Function Name: Dem_MainFunction
*
* Explanation: Processes all not event based Dem internal functions.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_MainFunction(void)
{
    if(Dem_Manage.initSt == DEM_MODULE_STATE_INITED)
    {
        Dem_EventOperCycleReqHandle();

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
        Dem_EventDebTimeBasedProcess();
#endif
        Dem_EventQueueProcess();

        Dem_EventCheckDtcSettingReenable();

#if(DEM_CFG_ENCOND_GROUP_NUM > DEM_INIT_ZERO)
        Dem_EventCheckEnCondGrpChanged();
#endif
#if(DEM_CFG_STORCOND_GROUP_NUM > DEM_INIT_ZERO)
        Dem_EventCheckStorCondGrpChanged();
#endif
#if(DEM_CFG_COMP_NUM > DEM_INIT_ZERO)
        Dem_EventCheckComponetStatusChanged();
#endif

        Dem_EventCheckMonitorTrigger();

#if(DEM_CFG_RESETCONFIRMEDBITONOVERFLOW == STD_OFF)
        Dem_EventMemoryEntryAttemptProcess();
#endif
#if(DEM_CFG_OBDSUPPORT != DEM_OBD_NO_OBD_SUPPORT)
        Dem_ObdMainProcess();
#endif
        Dem_EventMemoryNvmProcess();
    }

}

/*
********************************************************************************
* Function Name: Dem_DcmGetExtendedDataRecordByDTC
*
* Explanation: Gets All extended data by DTC. The function stores the data 
*              in the provided DestBuffer.
*
* param: DTC: Diagnostic Trouble Code in UDS format.
*        DTCOrigin: If the Dem supports more than one event memory,
*                   this parameter is used to select the source memory
*                   the DTCs shall be read from.
*        ExtendedDataNumber: dentification/Number of requested extended data
*                            record. The values 0xFE and 0xFF are not allowed.
*        BufSize: When the function is called this parameter contains the maximum
*                 number of data bytes that can be written to the buffer.
*        DestBuffer: This parameter contains a byte pointer that points to the buffer.
*
* retval: DEM_GETSIZEBYDTC_OK: Size successfully returned.
*         DEM_GETSIZEBYDTC_WRONG_DTC: DTC value not existing (in UDS format).
*         DEM_GETSIZEBYDTC_WRONG_DTCORIGIN: Wrong DTC origin.
*         DEM_GETSIZEBYDTC_WRONG_RECNUM: Record number is not supported by
*                                        configuration and therefore invalid.
*         DEM_GETSIZEBYDTC_PENDING: The requested value is calculated 
*         asynchronously  and currently not available. The caller can retry later.
*         DEM_GETSIZEBYDTC_UNINIT: API called in uninitialized state.
*         DEM_GETSIZEBYDTC_PARAM_POINTER: called with a NULL pointer where
*                                         NULL pointer is not allowed.
********************************************************************************
*/
FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE) Dem_DcmGetAllExtendedDataRecordByDTC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Dem_ReturnGetExtendedDataRecordByDTCType returnValue = DEM_RECORD_WRONG_DTC;
    uint8 evtMemIdx = DEM_INIT_ZERO;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx= DEM_INIT_ZERO;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if((NULL_PTR == DestBuffer) || (NULL_PTR == BufSize))
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            returnValue = DEM_RECORD_WRONG_BUFFERSIZE;
        }
        else if((0xFEU != ExtendedDataNumber) && (0xFFU != ExtendedDataNumber))
        {
            returnValue = DEM_RECORD_WRONG_DTC;
        }
        else if(E_NOT_OK == Dem_EventCheckDTCOriginValid(DTCOrigin, &evtMemIdx))
        {
            returnValue = DEM_RECORD_WRONG_DTCORIGIN;
        }
        else
        {
            if(0xFEU == ExtendedDataNumber)
            {
                /* Currently not support OBD extended data record */
            }
            else
            {
                if(E_OK == Dem_EventCalcDTCIndexFromDTC(DTC, DEM_DTC_FORMAT_UDS, &dtcIdx))
                {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                    if((dtcIdx != DEM_INIT_ZERO) && (FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)))
#else
                    if(dtcIdx != DEM_INIT_ZERO)
#endif
                    {
                        returnValue = Dem_DTCGetAllExRecordData(dtcIdx, evtMemIdx, DestBuffer, BufSize);
                    }
                    else
                    {
                        returnValue = DEM_RECORD_WRONG_DTC;
                    }
                }
                else
                {
                    returnValue = DEM_RECORD_PENDING;
                }
            }
        }
    }
    
    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_DcmGetSizeOfAllExtendedDataRecordByDTC
*
* Explanation: Gets the size of All extended data by DTC.
*
* param: DTC: Diagnostic Trouble Code in UDS format.
*        DTCOrigin: If the Dem supports more than one event memory,this parameter
*                is used to select the source memory the DTCs shall be read from.
*        ExtendedDataNumber: Identification/Number of requested extended data record.
*        SizeOfExtendedDataRecord: Size of the requested extended data
*                                  record(s) including record number size.
*
* retval: DEM_GETSIZEBYDTC_OK: Size successfully returned.
*         DEM_GETSIZEBYDTC_WRONG_DTC: DTC value not existing (in UDS format).
*         DEM_GETSIZEBYDTC_WRONG_DTCORIGIN: Wrong DTC origin.
*         DEM_GETSIZEBYDTC_WRONG_RECNUM: Record number is not supported by
*                                        configuration and therefore invalid.
*         DEM_GETSIZEBYDTC_PENDING: The requested value is calculated asynchronously
*                          and currently not available. The caller can retry later.
*         DEM_GETSIZEBYDTC_UNINIT: API called in uninitialized state.
*         DEM_GETSIZEBYDTC_PARAM_POINTER: called with a NULL pointer where 
*                                         NULL pointer is not allowed.
********************************************************************************
*/
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE) Dem_DcmGetSizeOfAllExtendedDataRecordByDTC
(
    /* PolySpace +1 MISRA-C3:5.3 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" PolySpace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_Dem_Uniqueidentifier" */
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
)
{
    Dem_ReturnGetSizeOfDataByDTCType returnValue = DEM_GETSIZEBYDTC_WRONG_DTC;
    uint8 evtMemIdx = DEM_INIT_ZERO;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dem_D4.5" */
    uint16 dtcIdx = DEM_INIT_ZERO;
    
    if(DEM_MODULE_STATE_INITED == Dem_Manage.initSt)
    {
        if(NULL_PTR == SizeOfExtendedDataRecord)
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            returnValue = DEM_GETSIZEBYDTC_WRONG_DTC;
        }
        else if(E_NOT_OK == Dem_EventCheckDTCOriginValid(DTCOrigin, &evtMemIdx))
        {
            returnValue = DEM_GETSIZEBYDTC_WRONG_DTCORIGIN;
        }
        else if((0xFEU != ExtendedDataNumber) && (0xFFU != ExtendedDataNumber))
        {
            returnValue = DEM_RECORD_WRONG_DTC;
        }
        else
        {
            if(E_OK == Dem_EventCalcDTCIndexFromDTC(DTC, DEM_DTC_FORMAT_UDS, &dtcIdx))
            {
#if(DEM_CFG_SUPPRESSIONSUPPORT == DEM_DTC_SUPPRESSION)
                if((dtcIdx != DEM_INIT_ZERO) && (FALSE == DEM_GET_DTCSUPPRESSION(dtcIdx)))
#else
                if(dtcIdx != DEM_INIT_ZERO)
#endif
                {
                    returnValue = Dem_DTCGetAllExRecordSize(dtcIdx, evtMemIdx, SizeOfExtendedDataRecord);
                }
                else
                {
                    returnValue = DEM_GETSIZEBYDTC_WRONG_DTC;
                }
            }
            else
            {
                returnValue = DEM_GETSIZEBYDTC_PENDING;
            }
        }
    }
    
    return returnValue;
}

#if( DEM_CFG_J1939SUPPORT == STD_ON )
#if( DEM_CFG_J1939READINGDTCSUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Dem_J1939DcmSetDTCFilter
*
* Explanation: Set the DTC filter for a specific node and returns the composite
*              lamp status of the filtered DTCs.
*
* param: DTCStatusFilter:The following types are available:
*                        DEM_J1939DTC_ACTIVE
*                        DEM_J1939DTC_PREVIOUSLY_ACTIVE
*                        DEM_J1939DTC_PENDING
*                        DEM_J1939DTC_PERMANENT
*                        DEM_J1939DTC_CURRENTLY_ACTIVE
*        DTCKind: Defines the functional group of DTCs to be reported.
*        node: Nm node Id.
*        LampStatus:Receives the commulated lamp status.
*
* retval: DEM_FILTER_ACCEPTED: Filter was accepted.
*         DEM_WRONG_FILTER: Wrong filter selected.
********************************************************************************
*/
FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_J1939DcmSetDTCFilter
(
    Dem_J1939DcmDTCStatusFilterType DTCStatusFilter,
    Dem_DTCKindType DTCKind,
    uint8 node,
    P2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_APPL_DATA) LampStatus
)
{
    Dem_ReturnSetFilterType returnValue = DEM_WRONG_FILTER;
    uint8 errorId = DEM_E_NO_ERROR;

    if( DEM_MODULE_STATE_INITED != Dem_Manage.initSt )
    {
        errorId = DEM_E_UNINIT;
    }
    else if( NULL_PTR == LampStatus )
    {
        errorId = DEM_E_PARAM_POINTER;
    }
    else if( (DTCStatusFilter > DEM_MAX_J1939_FILTER_TYPE) ||
             (node > DEM_MAX_NODE_NUM) ||
             ((DTCKind != DEM_DTC_KIND_ALL_DTCS) &&
             (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)) )
    {
        errorId = DEM_E_PARAM_DATA;
    }
    else
    {
        DEM_SET_J1939_DTC_FILTER_ENABLE(TRUE);
        DEM_SET_J1939_DTC_FILTER_KIND(DTCKind);
        DEM_SET_J1939_DTC_FILTER_FORMAT(DEM_DTC_FORMAT_J1939);
        DEM_SET_J1939_DTC_FILTER_MASK(DTCStatusFilter);
        DEM_SET_J1939_DTC_NODE(node);
        DEM_SET_J1939_DTC_FILTER_MATCH_NUM(DEM_INIT_ZERO);
        DEM_SET_J1939_DTC_FILTER_MATCH_NEXT(TRUE);
        DEM_SET_J1939_DTC_FILTER_MATCH_NEXTIDX(DEM_INIT_ZERO);

        Dem_ReturnLampStatus(LampStatus);

        returnValue = DEM_FILTER_ACCEPTED;
    }

    Dem_Det_ErrorReport(DEM_J1939DCMSETDTCFILTER_APIID, errorId);

    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_J1939DcmGetNumberOfFilteredDTC
*
* Explanation: Gets the number of currently filtered DTCs set by the function
*              Dem_J1939DcmSetDTCFilter.
*
* param: NumberOfFilteredDTC: The number of DTCs matching the defined status mask.
*
* retval: DEM_NUMBER_OK: Getting number of filtered DTCs was successful.
*         DEM_NUMBER_FAILED: Getting number of filtered DTCs failed.
*         DEM_NUMBER_PENDING: The requested value is calculated asynchronously
*                             and currently not available. The caller can retry later.
********************************************************************************
*/
FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE) Dem_J1939DcmGetNumberOfFilteredDTC
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC
)
{
    Dem_ReturnGetNumberOfFilteredDTCType returnValue = DEM_NUMBER_FAILED;
    uint8 errorId = DEM_E_NO_ERROR;

    if( DEM_MODULE_STATE_INITED != Dem_Manage.initSt )
    {
        errorId = DEM_E_UNINIT;
    }
    else if( NULL_PTR == NumberOfFilteredDTC )
    {
        errorId = DEM_E_PARAM_POINTER;
    }
    else
    {
        if( TRUE == DEM_GET_J1939_DTC_FILTER_ENABLE() )
        {
            if( E_OK == Dem_EventCalcJ1939DtcFilteredNum() )
            {
                *NumberOfFilteredDTC = DEM_GET_J1939_DTC_FILTER_MATCH_NUM();
                returnValue = DEM_NUMBER_OK;
            }
        }
    }

    Dem_Det_ErrorReport(DEM_J1939DCMGETNUMBEROFFILTEREDDTC_APIID, errorId);

    return returnValue;
}

/*
********************************************************************************
* Function Name: Dem_J1939DcmGetNextFilteredDTC
*
* Explanation: Gets the next filtered J1939 DTC.
*
* param: J1939DTC: Receives the J1939DTC value. If the return value of the function
*                  is other than DEM_FILTERED_OK this parameter does not contain
*                  valid data.
*        OccurenceCounter: This parameter receives the corresponding occurrence
*                          counter. If the return value of the function call
*                          is other than DEM_FILTERED_OK this parameter does not
*                          contain valid data.
*
* retval: DEM_FILTERED_OK: Returned next filtered element.
*         DEM_FILTERED_NO_MATCHING_ELEMENT: No further element (matching the 
*                                           filter criteria) found.
********************************************************************************
*/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_J1939DcmGetNextFilteredDTC
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) J1939DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
)
{
    Dem_ReturnGetNextFilteredElementType returnValue = DEM_FILTERED_NO_MATCHING_ELEMENT;
    uint8 errorId = DEM_E_NO_ERROR;
    uint8 occCnt = DEM_INIT_ZERO;
    uint32 dtcVal = DEM_INIT_ZERO;

    if( DEM_MODULE_STATE_INITED != Dem_Manage.initSt )
    {
        errorId = DEM_E_UNINIT;
    }
    else if( (NULL_PTR == J1939DTC) || (NULL_PTR == OccurenceCounter) )
    {
        errorId = DEM_E_PARAM_POINTER;
    }
    else
    {
        if( TRUE == DEM_GET_J1939_DTC_FILTER_ENABLE() )
        {
            if( E_OK == Dem_EventCalcJ1939DtcNextFiltered(&dtcVal, &occCnt) )
            {
                if( TRUE == DEM_GET_J1939_DTC_FILTER_MATCH_NEXT() )
                {
                    *J1939DTC = dtcVal;
                    *OccurenceCounter = occCnt;
                    returnValue = DEM_FILTERED_OK;
                }
            }
        }
    }

    Dem_Det_ErrorReport(DEM_J1939DCMGETNEXTFILTEREDDTC_APIID, errorId);

    return returnValue;
}
#endif

#if( DEM_CFG_J1939DM31SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Dem_J1939DcmFirstDTCwithLampStatus
*
* Explanation: The function sets the filter to the first applicable DTC for the
*              DM31 response for a specific node.
*
* param: node: Nm node Id of requesting client.
*
* retval: None
********************************************************************************
*/
FUNC(void, DEM_CODE) Dem_J1939DcmFirstDTCwithLampStatus(uint8 node)
{
    uint8 errorId = DEM_E_NO_ERROR;

    if( DEM_MODULE_STATE_INITED == Dem_Manage.initSt )
    {
        if( node > DEM_MAX_NODE_NUM )
        {
            errorId = DEM_E_PARAM_DATA;
        }
        else
        {
            DEM_SET_DM31_FILTER_ENABLE(TRUE);
            DEM_SET_DM31_FILTER_MATCH_NEXT(TRUE);
            DEM_SET_DM31_J1939_NODE(node);
            DEM_SET_DM31_FILTER_MATCH_NEXTIDX(DEM_INIT_ZERO);
        }
    }
    else
    {
        errorId = DEM_E_UNINIT;
    }

    Dem_Det_ErrorReport(DEM_J1939DCMFIRSTDTCWITHLAMPSTATUS_APIID, errorId);
}

/*
********************************************************************************
* Function Name: Dem_J1939DcmGetNextDTCwithLampStatus
*
* Explanation: Gets the next filtered J1939 DTC for DM31 including current LampStatus.
*
* param:  LampStatus: Rceives the lamp status returned by this function. If the
*                     return value of the function is other than DEM_FILTERED_OK
*                     this parameter does not contain valid data.
*         J1939DTC: Receives the J1939DTC value. If the return value ofthe function
*                   is other than DEM_FILTERED_OK this parameter does not contain
*                   valid data.
*         OccurenceCounter: This parameter receives the corresponding occurrence
*                           counter. If the return value of the function call
*                           is other than DEM_FILTERED_OK this parameterdoes not
*                           contain valid data.
*
* retval: DEM_FILTERED_OK: Returned next filtered element.
*         DEM_FILTERED_NO_MATCHING_ELEMENT: No further element (matching the
*                                           filter criteria) found.
*         DEM_FILTERED_PENDING: The requested value is calculated asynchronously
*                               and currently not available. The caller can retry
*                               later. Only used by asynchronous interfaces.
*         DEM_FILTERED_BUFFER_TOO_SMALL: Buffer in the BufSize parameter is
*                                        not huge enough.
********************************************************************************
*/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_J1939DcmGetNextDTCwithLampStatus
(
    P2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_APPL_DATA) LampStatus,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) J1939DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
)
{
    Dem_ReturnGetNextFilteredElementType returnValue = DEM_FILTERED_NO_MATCHING_ELEMENT;
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 evtIdx = DEM_INIT_ZERO;

    if( DEM_MODULE_STATE_INITED != Dem_Manage.initSt )
    {
        errorId = DEM_E_UNINIT;
    }
    else if( (NULL_PTR == J1939DTC) ||
             (NULL_PTR == OccurenceCounter) ||
             (NULL_PTR == LampStatus) )
    {
        errorId = DEM_E_PARAM_POINTER;
    }
    else
    {
        if( TRUE == DEM_GET_DM31_FILTER_ENABLE() )
        {
            if( E_OK == Dem_EventCalcDM31J1939DtcNextFiltered(J1939DTC, OccurenceCounter, &evtIdx) )
            {
                if( TRUE == DEM_GET_DM31_FILTER_MATCH_NEXT() )
                {
                    Dem_ReturnDM31LampStatus(LampStatus, evtIdx);
                    returnValue = DEM_FILTERED_OK;
                }
            }
        }
        else
        {
            errorId;
        }
    }

    Dem_Det_ErrorReport(DEM_J1939DCMGETNEXTDTCWITHLAMPSTATUS_APIID, errorId);

    return returnValue;
}
#endif

#if( DEM_CFG_J1939CLEARDTCSUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: Dem_J1939DcmClearDTC
*
* Explanation: Clears active DTCs as well as previously active DTCs.
*
* param: DTCTypeFilter: The following types are available:
*                       DEM_J1939DTC_CLEAR_ALL
*                       DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE
*        node: Nm node Id of requesting client.
*
* retval: DEM_CLEAR_OK: DTC successfully cleared.
*         DEM_CLEAR_FAILED: DTC clearing failed.
*         DEM_CLEAR_PENDING: The DTC clearing is performed asynchronously
*                            and still pending. The caller can retry later.
********************************************************************************
*/
FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_J1939DcmClearDTC
(
    Dem_J1939DcmSetClearFilterType DTCTypeFilter,
    uint8 node
)
{
    Dem_ReturnClearDTCType returnValue = DEM_CLEAR_OK;
    Dem_ReturnClearDTCType clearStatus = DEM_CLEAR_OK;
    uint8 evtMemIdx = DEM_INIT_ZERO;
    uint8 errorId = DEM_E_NO_ERROR;
    uint16 dtcIdx = DEM_INIT_ONE;
    uint32 dtcValue = DEM_INIT_ZERO;

    if( DEM_MODULE_STATE_INITED != Dem_Manage.initSt )
    {
        errorId = DEM_E_UNINIT;
    }
    else if( (DTCTypeFilter != DEM_J1939DTC_CLEAR_ALL) &&
             (DTCTypeFilter != DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE) )
    {
        errorId = DEM_E_PARAM_DATA;
    }
    else
    {
        for( dtcIdx = Dem_StartDtcIdx; dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++ )
        {
            /* Determine whether J1939DTC is configured */
            if( (node == Dem_CfgDTCTable[dtcIdx].acJ1939DtcNdId) && 
                (DEM_INIT_ZERO != Dem_CfgDTCTable[dtcIdx].acObdDtcIdx) )
            {
                dtcValue = DEM_DTCVALUE_CAL(dtcIdx);
                /* Consider that J1939 will be stored in primary memory permanent memory and user defined */
                for( evtMemIdx = Dem_StartEvtMemIdx; evtMemIdx <= DEM_CFG_EVENT_MEMORY_NUM; evtMemIdx++ )
                {
                    if( E_OK == Dem_J1939DcmCheckClearFilterType(DTCTypeFilter, dtcIdx, &clearStatus) )
                    {
                        returnValue = Dem_EventClearDTC(dtcValue,
                                                        DEM_DTC_FORMAT_UDS,
                                                        evtMemIdx,
                                                        DEM_CLEAR_DTC_CLIENT_DCM);
                        if( DEM_CLEAR_PENDING == returnValue )
                        {
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                if( DEM_CLEAR_PENDING == returnValue )
                {
                    Dem_StartEvtMemIdx = evtMemIdx;
                    break;
                }
                else
                {
                    Dem_StartEvtMemIdx = DEM_INIT_ONE;
                }
            }
        }
        if( DEM_CLEAR_PENDING == returnValue )
        {
            Dem_StartDtcIdx = dtcIdx;
        }
        else
        {
            Dem_StartDtcIdx = DEM_INIT_ONE;
        }
    }

    Dem_Det_ErrorReport(DEM_J1939DCMCLEARDTC_APIID, errorId);

    return returnValue;
}
#endif
#endif

#define DEM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


/*
********************************************************************************
*
* File name: Det.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: ZhangDX/2019.05.15
* Change: New created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: JiaF/2019.11.19
* Change: Modify the file according to the code specification.
* Cause: Optimization
********************************************************************************
* Version: 1.2
* Author/Date: JiaF/2019.11.25
* Change: Modify function. Add function(e.g Det_LogError) and
*         macros(e.g Det_EnterCritical,Det_ExitCritical).
* Cause: Optimization, Reenrant function.
********************************************************************************
* Version: 1.3
* Author/Date: JiaF/2020.03.25
* Change: Modify QAC Check Warning.
* Cause: Revision
********************************************************************************
* Version: 3.0
* Author/Date: JiaF/2020.03.27
* Change: Nothing
* Cause: Update to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: JiaF/2020.09.09
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: JiaF/2020.10.22
* Change: Temporarily delete SchM_Det.h related code.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: FangT/2020.10.28
* Change: Modify function parameter VAR and QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: FangT/2020.11.04
* Change: Modify function parameter VAR and QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: FangT/2020.11.06
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: ZhuCY/2021.10.28
* Change: Modify header file.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LiDY/2022.09.23
* Change: Add multicore function.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: ChenQJ/2023.08.18
* Change: Fix P2CONST ptrclass issue.
* Cause: Bugfix
********************************************************************************
* Version: 3.9
* Author/Date: ChenQJ/2023.09.21
* Change: Change the header file name provided by Dlt.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: LinZhC/2024.03.21
* Change: Fix P2CONST ptrclass issue.
* Cause: Bugfix
********************************************************************************
* Version: 3.11
* Author/Date: ZengJX/2024.07.02
* Change: Fix Det memmap problem.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: ZengJX/2024.07.15
* Change: 1.Modify copyright information.
*         2.Optimize comments specifications.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: ZengJX/2024.09.03
* Change: Modify copyright information.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: ZengJX/2025.03.27
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Bugfix
********************************************************************************
* Version: 3.15
* Author/Date: ZengJX/2025.06.05
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.16
* Author/Date: ZengJX/2025.06.09
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.17
* Author/Date: ZengJX/2025.06.23
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
#include "Det.h"
#include "Rte_Det.h"

#if ( STD_ON == DET_FORWARD_TO_DLT )
#include "Dlt_Det.h"
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


#define DET_NUMBER_OF_CORES                      (OS_CFG_COREPHYSICALID_COUNT)
#define DET_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_Rule20.1 */
/* Brief Det runing state flag. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Det_GlobalVariables" */
static VAR(uint8, DET_VAR_INIT) Det_ModuleState = DET_FALSE;
/* Ram log variables in uninitialized memory. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Det_GlobalVariables" */
static volatile VAR(uint32, DET_VAR_INIT) Det_RamlogIndex = DET_ZERO;

#define DET_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_Rule20.1 */

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
#if( DET_RAMLOG_SIZE > DET_ZERO )
#define DET_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_Rule20.1 */
static FUNC(Std_ReturnType, DET_CODE) Det_LogError
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 ErrorId
);
#define DET_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_Rule20.1 */
#endif

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#if( DET_RAMLOG_SIZE > DET_ZERO )

#define DET_START_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_Rule20.1 */

/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Det_GlobalVariables" */
volatile VAR(Det_EntryType, DET_VAR_NO_INIT) Det_RamLog[DET_RAMLOG_SIZE][DET_NUMBER_OF_CORES];    /* Save ramlog buffer. */

#define DET_STOP_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_Rule20.1 */

#endif

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define DET_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_Rule20.1 */

#if( DET_RAMLOG_SIZE > DET_ZERO )
/*
********************************************************************************
* Function Name : Det_LogError
*
* Explanation   : Service to log error.
*
* param         : ModuleId   -> Module ID of calling module.
*                 InstanceId -> The identifier of the index based instance of a
*                               module, starting from 0, If the module is a single
*                               instance module it shall pass 0 as the InstanceId.
*                 ApiId      -> ID of API service in which error is detected.
*                 ErrorId    -> ID of detected development error.
*
* retval        : E_OK: Operation was successful
*                 E_NOT_OK: Operation failed
********************************************************************************
*/
static FUNC(Std_ReturnType, DET_CODE) Det_LogError
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 ErrorId
)
{
    /* Local Variables. */
    uint8 acRes = DET_E_NOT_OK;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Det_D4.5" Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Det_UnmodifiedVariableNotConst-qualified" */
    CoreIdType coreID = GetCoreID();

    /* If logging is active. */
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( TRUE == Det_ModuleState )
    {
        /* Record error. */
        if( Det_RamlogIndex < DET_RAMLOG_SIZE )
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Det_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Det_PtrBoundary" Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_Det_ArrayAccessWithTaintedIndex" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Det_PtrBoundary4" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Det_OutOfBoundArrayIndex" */
            Det_RamLog[Det_RamlogIndex][coreID].moduleId   = ModuleId;
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Det_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Det_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Det_OutOfBoundArrayIndex" */
            Det_RamLog[Det_RamlogIndex][coreID].instanceId = InstanceId;
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Det_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Det_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Det_OutOfBoundArrayIndex" */
            Det_RamLog[Det_RamlogIndex][coreID].apiId      = ApiId;
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Det_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Det_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_Det_OutOfBoundArrayIndex" */
            Det_RamLog[Det_RamlogIndex][coreID].errorId    = ErrorId;
            Det_RamlogIndex++;
            if( DET_RAMLOG_SIZE == Det_RamlogIndex )
            {
                Det_RamlogIndex = DET_ZERO;
            }
            acRes = DET_E_OK;
        }
    }

    return acRes;
}
#endif

/*
********************************************************************************
* Function Name : Det_Init
*
* Explanation   : Service to initialize the Default Error Tracer.
*
* param         : ConfigPtr -> Pointer to the selected configuration set.
*
* retval        : None
********************************************************************************
*/
FUNC(void, DET_CODE) Det_Init
(
    P2CONST(Det_ConfigType, AUTOMATIC, DET_APPL_DATA) ConfigPtr
)
{
    /* Local variables. */
    uint32 acIndex;
    uint32 ccIndex;

    /* Dummy statement. */
    DET_DUMMY_STATEMENT(ConfigPtr);

#if( DET_RAMLOG_SIZE > DET_ZERO )
    /* Each call of the Det_Init function shall be used to set the Default Error
       Tracer to a defined initial status. */
    Det_RamlogIndex = DET_ZERO;
    for( acIndex = DET_ZERO; acIndex < DET_RAMLOG_SIZE; acIndex++ )
    {
        for (ccIndex = DET_ZERO; ccIndex < DET_NUMBER_OF_CORES; ccIndex++)
        {
            Det_RamLog[acIndex][ccIndex].moduleId = DET_ZERO;
            Det_RamLog[acIndex][ccIndex].instanceId = DET_ZERO;
            Det_RamLog[acIndex][ccIndex].apiId = DET_ZERO;
            Det_RamLog[acIndex][ccIndex].errorId = DET_ZERO;
        }
    }
#endif
    Det_ModuleState = DET_TRUE;
}

/*
********************************************************************************
* Function Name : Det_ReportError
*
* Explanation   : Service to report development errors.
*
* param         : ModuleId   -> Module ID of calling module.
*                 InstanceId -> The identifier of the index based instance of a
*                               module, starting from 0, If the module is a single
*                               instance module it shall pass 0 as the InstanceId.
*                 ApiId      -> ID of API service in which error is detected.
*                 ErrorId    -> ID of detected development error.
*
* retval        : returns always E_OK (is required for services)
********************************************************************************
*/
FUNC(Std_ReturnType, DET_CODE) Det_ReportError
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 ErrorId
)
{
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Det_D4.5" */
    Std_ReturnType detLogError;
#if( STD_ON == DET_ERR_HOOK_ENABLE )
    uint8 acRes;
    uint8 acIndex;
#endif

    /* Judge module state. */
    if( DET_TRUE == Det_ModuleState )
    {

#if ( STD_ON == DET_ERR_HOOK_ENABLE )
        for( acIndex = DET_ZERO; acIndex < DET_ERR_HOOK_NUM; acIndex++ )
        {
            acRes = Det_ErrorHookTable[acIndex](ModuleId, InstanceId, ApiId, ErrorId);/* Error Hooks */
            DET_DUMMY_STATEMENT(acRes);
        }
#endif

        /* Forward to Dlt module. */
#if ( STD_ON == DET_FORWARD_TO_DLT )
        Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, ErrorId);
#endif

        /* Record error. */
#if( DET_RAMLOG_SIZE > DET_ZERO )
        detLogError = Det_LogError(ModuleId,InstanceId,ApiId,ErrorId);
        DET_DUMMY_STATEMENT(detLogError);
#endif

    }
    /* Note: The Default Error Tracer shall never return an error indication 
             (even in case of calling the un-initialized module). */
    return E_OK;
}

/*
********************************************************************************
* Function Name : Det_Start
*
* Explanation   : Service to start the Default Error Tracer.
*                 In case the Default Error Tracer does not require a startup
*                 call the Det_Start function can be empty.
*
* param         : None
*
* retval        : None
********************************************************************************
*/
FUNC(void, DET_CODE) Det_Start(void)
{
    /* Nothing */
}

/*
********************************************************************************
* Function Name : Det_ReportRuntimeError
*
* Explanation   : Service to report runtime errors. If a callout has been
*                 configured then this callout shall be called.
*
* param         : ModuleId   -> Module ID of calling module.
*                 InstanceId -> The identifier of the index based instance of a
*                               module, starting from 0, If the module is a single
*                               instance module it shall pass 0 as the InstanceId.
*                 ApiId      -> ID of API service in which error is detected.
*                 ErrorId    -> ID of detected development error.
*
* retval        : returns always E_OK (is required for services)
********************************************************************************
*/
FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 ErrorId
)
{

#if( STD_ON == DET_RUNTIME_ERR_ENABLE )
    uint8 acIndex = DET_ZERO;
#endif

    /* Judge module state. */
    if( DET_TRUE == Det_ModuleState )
    {

#if( STD_ON == DET_RUNTIME_ERR_ENABLE )
        /* Report runtime error callout. */
        for( acIndex = DET_ZERO; acIndex < DET_RUNTIME_ERR_CALLOUT_NUM; acIndex++ )
        {
            (void)Det_RuntimeErrorCalloutTable[acIndex](ModuleId, InstanceId, ApiId, ErrorId);
        }
#else
        DET_DUMMY_STATEMENT(ModuleId);
        DET_DUMMY_STATEMENT(InstanceId);
        DET_DUMMY_STATEMENT(ApiId);
        DET_DUMMY_STATEMENT(ErrorId);
#endif

        /* Forward to Dlt module. */
#if( STD_ON == DET_FORWARD_TO_DLT )
        Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, ErrorId);
#endif

    }
    /* Note: The Default Error Tracer shall never return an error indication 
      (even in case of calling the un-initialized module). */
    return E_OK;
}

/*
********************************************************************************
* Function Name : Det_ReportTransientFault
*
* Explanation   : Service to report transient faults.
*
* param         : ModuleId   -> Module ID of calling module.
*                 InstanceId -> The identifier of the index based instance of a
*                               module, starting from 0, If the module is a single
*                               instance module it shall pass 0 as the InstanceId.
*                 ApiId      -> ID of API service in which error is detected.
*                 ErrorId    -> ID of detected development error.
*
* retval        : Propagates return value of assigned callout if exists, otherwise E_OK.
********************************************************************************
*/
FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientFault
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 FaultId
)
{
    /* Polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Det_UnmodifiedVariableNotConst-qualified" */
    uint8 acRes = DET_E_OK;

#if ( STD_ON == DET_TRANSIENT_FAULT_ENABLE )
    uint8 acIndex = DET_ZERO;
#endif

    /* Judge module state. */
    if( DET_TRUE == Det_ModuleState )
    {

#if ( STD_ON == DET_TRANSIENT_FAULT_ENABLE )
        /* Execute Transient Fault Callout. */
        for( acIndex = DET_ZERO; acIndex < DET_TRANSIENT_FAULT_CALLOUT_NUM; acIndex++ )
        {
            acRes = Det_TransientFaultCalloutTable[acIndex](ModuleId, InstanceId, ApiId, FaultId);
        }
#else
        DET_DUMMY_STATEMENT(ModuleId);
        DET_DUMMY_STATEMENT(InstanceId);
        DET_DUMMY_STATEMENT(ApiId);
        DET_DUMMY_STATEMENT(FaultId);
#endif

        /* Forward to Dlt module. */
#if( STD_ON == DET_FORWARD_TO_DLT )
        Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, FaultId);
#endif

    }

    return acRes;
}

#if ( STD_ON == DET_VERSION_INFO_API )
/*
********************************************************************************
* Function Name : Det_GetVersionInfo
*
* Explanation   : Returns the version information of this module.(Synchronous)
*
* param         : versioninfo -> Pointer to where to store the version information of this module.
*
* retval        : None
********************************************************************************
*/
FUNC(void, DET_CODE) Det_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DET_APPL_DATA) versioninfo
)
{
    uint8 acChkResult = DET_E_NO_ERR;

    if( NULL_PTR == versioninfo )
    {
        acChkResult = DET_E_PARAM_POINTER;    /* Null parameter pointer. */
    }

    if( DET_E_NO_ERR == acChkResult )	/* Check parameter is null pointer. */
    {
        versioninfo->vendorID = DET_VENDOR_ID;
        versioninfo->moduleID = DET_MODULE_ID;
        versioninfo->sw_major_version = DET_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = DET_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = DET_SW_PATCH_VERSION;
    }
    else
    {
        /* Call Det_ReportError. */
        Det_ReportError(DET_MODULE_ID, DET_INSTANCE_ID, DET_GET_VERSION_INFO_ID, acChkResult);
    }
}
#endif
#define DET_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_Rule20.1 */

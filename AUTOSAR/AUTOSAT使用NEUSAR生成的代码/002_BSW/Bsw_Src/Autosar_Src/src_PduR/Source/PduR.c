/*
********************************************************************************
*
*  File name: PduR.c
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: ZhangDX/2019.08.28
* Change: New create.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: ZhangDX/2019.08.29
* Change: add Api.
* Cause: Update
********************************************************************************
* Version: 1.2
* Author/Date: ZhangDX/2019.09.05
* Change: 1. Increase the buffer.
*         2. Increase demand realization.
* Cause: Update
********************************************************************************
* Version: 1.3
* Author/Date: ZhangDX/2019.09.11
* Change: Add standard API code.
* Cause: Update
********************************************************************************
* Version: 1.4
* Author/Date: ZhangDX/2019.09.12
* Change: Add routing code, add requirement number.
* Cause: Update
********************************************************************************
* Version: 2.1
* Author/Date: ZhangDX/2019.10.01
* Change: version updating & Macro definition location change.
* Cause: Update
********************************************************************************
* Version: 2.2
* Author/Date: ZhangDX/2019.10.12
* Change: Modify the code format.
* Cause: Optimize
********************************************************************************
* Version: 2.3
* Author/Date: ZhangDX/2019.10.29
* Change: 1. Increase the internal initialization function return value
*           judgment, increase the Det error ID.
* Cause: Update
********************************************************************************
* Version: 2.4
* Author/Date: ZhangDX/2019.12.02
* Change: Modify macro compilation options.
* Cause: Update
********************************************************************************
* Version: 2.5
* Author/Date: ZhangDX/2019.12.10
* Change: Update initialization logic.
* Cause: Update
********************************************************************************
* Version: 2.6
* Author/Date: ZhangDX/2019.12.30
* Change: 1. Add PduR_ReportError() PduR_Det_ReportRuntimeError().
*         2. Replace the function PduR_Det_ErrorReport with the PduR_ReportError
*            function.
*         3. 1, 2 in order to achieve SWS_PduR_00100 and SWS_PDUR_00816
*            requirements.
* Cause: Update
********************************************************************************
* Version: 2.7
* Author/Date: ZhangDX/2020.01.09
* Change: 1. Change the method used for parameter checking and initialization
*            checking in the previous version.
*         2. Change the definition location of module-related macro definitions
*            to PduR.h
* Cause: Optimize
********************************************************************************
* Version: 2.8
* Author/Date: ZhangDX/2020.02.19
* Change: 1. Modify the structure definition to support the implementation of
*            API: PduR_DisableRouting.
*         2. Implementation requirement SWS_PDUR_00810.
* Cause: Update
********************************************************************************
* Version: 2.9
* Author/Date: ZhangDX/2020.03.25
* Change: 1. Add notes.
*         2. Perform a QAC check and correct any errors that occur.
* Cause: Optimize
********************************************************************************
* Version: 3.0
* Author/Date: ZhangDX/2020.03.27
* Change: 1. Add notes.
*         2. Perform a QAC check and correct any errors that occur.
* Cause: Bugfix and Clear QAC warning.
********************************************************************************
* Version: 3.1
* Author/Date: ZhangDX/2020.03.30
* Change: Add notes.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: ZhangDX/2020.07.13
* Change: 1. Replace "req" with "Req".
*         2. Replace "PduR_ReportError" with "PDUR_REPORT_DET_ERROR".
*         3. Remove #include "PduR_Rout.h".
*         4. Remove "retVal |= PduR_InitBuffer(void)."
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: ZhangDX/2020.09.25
* Change: 1. Modify the errors that occurred during the code review on 2020.09.23.
*         2. Optimizing the code review on 2020.09.23 is a suggestion item given.
*         3. Optimized the coverage area of PDUR_ZERO_COST_OPERATION.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: ZhangDX/2020.09.27
* Change: Complete AutoSAR code style conversion.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: ZhangDX/2020.09.29
* Change: Add MemMap section.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: ZhangDX/2020.09.30
* Change: Modify the error in converting AutoSAR style.
*         1. Function parameters without pointers need to be converted.
*         2. The memclass used by local variables is AUTOMATIC.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: ZhangDX/2020.10.06
* Change: Add PostBuild function.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: ZhangDX/2020.10.10
* Change: Delete the semicolon at the end of the macro definition part about
*         DET, modify it to the realization of the macro definition.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: ZhangDX/2020.10.12
* Change: 1. Updated version information is 3.2.0.
*         2. Fix the type mismatch problem.
*         3. Restore the AutoSAR style of local variables to the normal style.
* Cause: Clear QAC warning and updata to V3.2.0.
********************************************************************************
* Version: 3.10
* Author/Date: ZhangDX/2020.10.13
* Change: Optimize the implementation of PduRZeroCostOperation function code.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: ZhangDX/2020.10.19
* Change: Modify the problem of repeated initialization of QAC local variables.
* Cause: Update & Clear QAC warning.
********************************************************************************
* Version: 3.12
* Author/Date: ZhangDX/2020.10.29
* Change: Solve the SWS_PduR_00119 requirement implementation error.
* Cause: Bugfix
********************************************************************************
* Version: 3.13
* Author/Date: ZhangDX/2020.11.04
* Change: Modify the wrong part of the segment definition.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: SunHQ/2022.06.20
* Change: Modify the return value of the function that does not need to be used.
* Cause: Clear compile warning.
********************************************************************************
* Version: 3.15
* Author/Date: SunHQ/2022.09.20
* Change: 1. Initialize the multi-core communication queue.
*         2. Implement the PduR_MainFunction function.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: SunHQ/2023.02.10
* Change: Modify the macro that controls the code implementation.
* Cause: Clear compile warning.
********************************************************************************
* Version: 3.17
* Author/Date: LuQ/2024.04.02
* Change: Modify the comments format.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: LuQ/2024.09.23
* Change: Modify the comments format.
* Cause: Optimization
********************************************************************************
* Version: 3.19
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: LuQ/2025.06.23
* Change: Modify the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
/* SWS_PduR_00160 */
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "PduR.h"
#include "PduR_Core.h"

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
#define PDUR_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"

/*
********************************************************************************
* Function Name: PduR_Init
*
* Explanation: Initializes the PDU Router.
* (Synchronous)
*
* param: ConfigPtr-> Pointer to post build configuration.
*
* retval: None.
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_Init
(
    P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_APPL_CONST) ConfigPtr
)
{
    uint8 errorID = PDUR_E_NO_ERROR;
    Std_ReturnType retVal = PDUR_E_OK;

    /* Check parameter is null pointer. */
    PDUR_VALIDATE_POINTER(PDUR_SERVICE_ID_PDUR_INIT, ConfigPtr, retVal);
    /* Check PduR State */
    if( PDUR_ONLINE == PduR_GetInitState() )
    {
        /* Set Det ErrorID. */
        errorID = PDUR_E_INIT_FAILED;
    }
    /* The parameter is not empty and is not initialized. */
    if( (PDUR_E_OK == retVal) && (PDUR_E_NO_ERROR == errorID) )
    {
        /* Req SWS_PduR_00287 PduRZeroCostOperation. */
        /* Set the PDUR module build configuration information. */
        retVal = PduR_InitPBConfigParam(ConfigPtr);
        if( PDUR_E_NOT_OK == retVal )
        {
            errorID = PDUR_E_INIT_FAILED;
        }
        else
        {
            /* Set the PDUR module status to online Req SWS_PduR_00326. */
            PduR_SetInitState(PDUR_ONLINE);
        }
    }

#if ((STD_OFF == PDUR_ZERO_COST_OPERATION) && (STD_ON == PDUR_SUPPORT_MULTICORE))
    if( (PDUR_E_OK == retVal) && (PDUR_E_NO_ERROR == errorID) )
    {
        /* Initialize the queue of current ECUC partition */
        PduR_InitQueue();
    }
#endif /* #if ((STD_OFF == PDUR_ZERO_COST_OPERATION) && (STD_ON == PDUR_SUPPORT_MULTICORE)) */

    /* Report Det Error. */
    PDUR_REPORT_DET_ERROR(PDUR_SERVICE_ID_PDUR_INIT, errorID)
    /* Eliminate the warning. */
    PDUR_UNUSED(errorID);
}

#if (STD_ON == PDUR_VERSION_INFO_API)
/*
********************************************************************************
* Function Name: PduR_GetVersionInfo
*
* Explanation: Returns the version information of this module.
* (Synchronous)
*
* param: versioninfo-> Pointer to where to store the version information of this
*                      module.
*
* retval: None.
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, PDUR_APPL_DATA) versioninfo
)
{
    Std_ReturnType retVal = PDUR_E_OK;
    /* SWS_PduR_00119 */
    /* Check parameter is null pointer. */
    PDUR_VALIDATE_POINTER(PDUR_SERVICE_ID_ENABLE_ROUTING, versioninfo, retVal);
    /* No Error? */
    if( PDUR_E_OK == retVal )
    {
        /* Set PduR Version Info. */
        /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_PduR_TAINTED_PTR" */
        versioninfo->vendorID = (uint16)PDUR_VENDOR_ID;
        versioninfo->moduleID = (uint16)PDUR_MODULE_ID;
        versioninfo->sw_major_version = (uint8)PDUR_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)PDUR_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)PDUR_SW_PATCH_VERSION;
    }
}
#endif  /* #if (STD_ON == PDUR_VERSION_INFO_API) */

/*
********************************************************************************
* Function Name: PduR_GetConfigurationId
*
* Explanation: Returns the unique identifier of the post-build time configuration
*              of the PDU Router.
* (Synchronous)
*
* param: None.
*
* retval: Identifier of the post-build time configuration.
********************************************************************************
*/
FUNC(PduR_PBConfigIdType, PDUR_CODE) PduR_GetConfigurationId(void)
{
    Std_ReturnType retVal = PDUR_E_OK;
    PduR_PBConfigIdType res = PDUR_INIT_0;
    /* Check the initialization status. */
    PDUR_VALIDATE_INITIALIZED(PDUR_SERVICE_ID_ENABLE_ROUTING, retVal);
    /* No Error? */
    if( PDUR_E_OK == retVal )
    {
        /* Req: SWS_PduR_00287. */
        res = (PduR_PBConfigIdType)PduR_GetConfigId();
    }
    return res;
}

/*
********************************************************************************
* Function Name: PduR_EnableRouting
*
* Explanation: Enables a routing path table.
* (Synchronous)
*
* param: id -> Identification of the routing path group. Routing path groups are
*              defined in the PDU router configuration.
*
* retval: None.
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_EnableRouting(PduR_RoutingPathGroupIdType id)
{
    Std_ReturnType retVal = PDUR_E_OK;
    /* Req SWS_PduR_00287 */
#if (STD_OFF == PDUR_ZERO_COST_OPERATION)
    /* Check the initialization status. */
    PDUR_VALIDATE_INITIALIZED(PDUR_SERVICE_ID_ENABLE_ROUTING, retVal);
    /* No Error? */
    if( PDUR_E_OK == retVal )
    {
        /* Req: SWS_PDUR_00827 */
        /* The return value of the function that does not need to be used here */
        (void)PduR_SetPduRIsEnabledAtInit(PDUR_TRUE, id);
    }
#else   /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */
    /* Eliminate the warning. */
    PDUR_UNUSED(id);
#endif  /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */

    /* Eliminate the warning. */
    PDUR_UNUSED(retVal);
}

/*
********************************************************************************
* Function Name: PduR_DisableRouting
*
* Explanation: Enables a routing path table.
* (Synchronous)
*
* param: id -> Identification of the routing path group. Routing path groups are
*              defined in the PDU router configuration.
*        initialize -> true: initialize single buffers to the default value
*                      false: retain current value of single buffers.
*
* retval: None.
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_DisableRouting
(
    PduR_RoutingPathGroupIdType id,
    boolean initialize
)
{
#if (STD_OFF == PDUR_ZERO_COST_OPERATION)
    Std_ReturnType retVal = PDUR_E_OK;
    /* Req: SWS_PduR_00287. */
    /* Check the initialization status. */
    PDUR_VALIDATE_INITIALIZED(PDUR_SERVICE_ID_DISABLE_ROUTING, retVal);
    /* No Error? */
    if( PDUR_E_OK == retVal )
    {
        /* Req SWS_PDUR_00827 */
        retVal = PduR_SetPduRIsEnabledAtInit(PDUR_FALSE, id);
    }
    if( PDUR_E_OK == retVal )
    {

#if (STD_ON == PDUR_SUPPORT_GETWAY)
        /*
        Req: SWS_PDUR_00810
        When a routing path associated with a single buffer (PduRTxBufferDepth == 1)
        is stopped, the according buffer shall be set to the default value if
        PduR_DisableRouting is called with initialize set to true, otherwise the
        current value shall be retained.
        */
        if( PDUR_TRUE == initialize )
        {
            PduR_SetRoutingGroupTxBufferDefault(id);
        }
        /*
        Req: SWS_PduR_00663
        When a routing path associated with a FIFO (PduRTxBufferDepth > 1) is
        stopped, the according FIFO shall be flushed, and the PduR shall report
        PDUR_E_PDU_INSTANCES_LOST to the DET if DET reporting is enabled.
        */
        PduR_RefreshFIFO(id);
#else   /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */
        /* Eliminate the warning. */
        PDUR_UNUSED(initialize);
#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */

    }
#else   /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */
    /* Eliminate the warning. */
    PDUR_UNUSED(id);
    PDUR_UNUSED(initialize);
#endif  /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */
}

/*
********************************************************************************
* Function Name: PduR_MainFunction
*
* Explanation: The main function of PduR, handling requests from other partitions.
* (Synchronous)
*
* param: None.
*
* retval: None.
********************************************************************************
*/
#if (STD_OFF == PDUR_ZERO_COST_OPERATION)

FUNC(void, PDUR_CODE) PduR_MainFunction(void)
{
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
    PduR_MainLoop();
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
}

#endif /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */

#define PDUR_STOP_SEC_CODE
/* MISRA C:2012 Rule-20.1 */
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"

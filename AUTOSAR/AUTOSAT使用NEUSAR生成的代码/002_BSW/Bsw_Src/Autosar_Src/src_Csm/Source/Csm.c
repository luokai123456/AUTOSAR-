/*
********************************************************************************
*
*  File name: Csm.c
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
*  Version: 1.0
*  Author/Date: jia_feng/2020.03.02
*  Change: New created
*  Cause: New
********************************************************************************
*  Version: 3.0
*  Author/Date: jia_feng/2020.07.02
*  Change: Nothing
*  Cause: Update
********************************************************************************
*  Version: 3.1
*  Author/Date: jia_feng/2020.09.10
*  Change: Modify the function name according to the AUTOSAR specification, add
*          MemMap.
*  Cause: Optimization
********************************************************************************
*  Version: 3.2
*  Author/Date: jia_feng/2020.10.12
*  Change: Modify the function of redirection, optimize code structure.
*  Cause: Optimization
********************************************************************************
*  Version: 3.3
*  Author/Date: guoziyang/2020.10.27
*  Change: Modify the code according to the AUTOSAR specification
*  Cause: Optimization
********************************************************************************
*  Version: 3.4
*  Author/Date: ZhangY/2020.11.04
*  Change: Csm_KeyExchangeCalcSecret null pointer judge.
*  Cause: Bugfix
********************************************************************************
*  Version: 3.5
*  Author/Date: ZhangY/2020.11.04
*  Change: Csm_AEADDecrypt use CSM_SID_AEADDECRYPT.
*  Cause: Bugfix
********************************************************************************
*  Version: 3.6
*  Author/Date: ZhangY/2020.11.05
*  Change: Judge Redirection to protect Call Csm_ProcessJobRedirection.
*  Cause: Bugfix
********************************************************************************
*  Version: 3.7
*  Author/Date: jia_feng/2020.11.09
*  Change: Add the judge of dataLength if redirection has been used,
*          modify the judge of redirection job in Csm_Jobxxx function,
*          modify CSM_NUMBER_OF_JOBS to CSM_NUMBER_OF_KEYS in Csm_GetKeyIdIdx.
*  Cause: Bugfix
********************************************************************************
*  Version: 3.8
*  Author/Date: JiaF/2020.11.23
*  Change: Modify compile warning on IAR.
*  Cause: Optimization
********************************************************************************
*  Version: 3.9
*  Author/Date: JiaF/2020.03.03
*  Change: Modify the PolySpace warnings in Csm_ProcessJobRedirection.
*  Cause: Optimization
********************************************************************************
*  Version: 3.10
*  Author/Date: ZhangY/2022.01.05
*  Change: 1.Add micro CSM_KEY_ELEMENT_COPY_PARTIAL to control
*            Csm_KeyElementCopyPartial.
*          2.Add CSM_DUMMY_STATEMENT(errorId).
*          3.Csm_KeyExchangeCalcSecret parameter partnerPublicValuePtr change to
*            P2CONST.
*  Cause: Bugfix
********************************************************************************
*  Version: 3.11
*  Author/Date: LiRQ/2022.12.02
*  Change: Modify the method of refering to CryIfkeyId in Csm_KeyElementGet,
           Csm_KeyElementCopy, Csm_KeyCopy and Csm_KeyElementCopyPartial.
*  Cause: Bugfix
********************************************************************************
*  Version: 3.12
*  Author/Date: NiXM/2022.12.10
*  Change: Modify the method of refering to Csm_KeyElementCopyPartial.
*  Cause: Bugfix
********************************************************************************
*  Version: 3.13
*  Author/Date: NiXM/2023.01.17
*  Change: Eliminate compilation warnings.
*  Cause: Optimization
********************************************************************************
*  Version: 3.14
*  Author/Date: NiXM/2023.01.31
*  Change: Modify codes due to coding standards.
*  Cause: Optimization
********************************************************************************
*  Version: 3.15
*  Author/Date: NiXM/2023.03.22
*  Change: Change CRYPTO_PROCESSING_SYNC to CRYPTO_PROCESSING_ASYNC and byte
*          alignment.
*  Cause: Bug
********************************************************************************
*  Version: 3.16
*  Author/Date: NiXM/2023.04.12
*  Change: Change the parameter of Csm_AEADDecrypt,secondaryOutputLengthPtr to
*          verifyPtr.
*  Cause: Bug
********************************************************************************
*  Version: 3.17
*  Author/Date: MengY/2023.06.13
*  Change: Modify the check of input parameters and setting parameters.
*  Cause: Bugfix
********************************************************************************
*  Version: 3.18
*  Author/Date: MengY/2023.09.18
*  Change: Modify the check of input parameters and setting parameters.
*  Cause: Optimization
********************************************************************************
*  Version: 3.19
*  Author/Date: MengY/2023.11.23
*  Change: Modify the process of callback function notification.
*  Cause: Optimization
********************************************************************************
* Version: 3.20
* Author/Date: MengY/2024.05.08
* Change: Add memmap section for function declaration.
* Cause: Optimization.
********************************************************************************
* Version: 3.21
* Author/Date: MengY/2024.07.16
* Change: Modify macLength in bits from bytes for function Csm_MacVerify
*        (macLength:contains the MAC length in BITS to be verified).
* Cause: Bugfix.
********************************************************************************
* Version: 3.22
* Author/Date: MengY/2024.10.11
* Change: Modify the CRYIF_CODE to CSM_CODE for function.
* Cause: Bugfix.
********************************************************************************
* Version: 3.23
* Author/Date: WangLX/2025.03.31
* Change: Fix QAC and Polyspace warnings and add analysis results.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: LiK/2025.5.26
* Change: Add polyspace Warning inhibition comment.
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Csm.h"

#if( CSM_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
#if( CSM_DEV_ERROR_DETECT == STD_ON )
#define CSM_REPORT_DEV_ERROR(SID, ERROR)     \
        ((void)Det_ReportError(CSM_MODULE_ID, CSM_INSTANCE_ID, (SID), (ERROR)))
#define CSM_REPORTRUNTIME_DEV_ERROR(SID, ERROR)     \
        ((void)Det_ReportRuntimeError(CSM_MODULE_ID, CSM_INSTANCE_ID, (SID), (ERROR)))
#endif

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
#define CSM_START_SEC_VAR_INIT
#include "Csm_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Initialization state with Uninitialized. */
/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_Csm_Unreasonablevariable" */
static VAR(Csm_InitStatusType, CSM_VAR_INIT) Csm_ModuleInitState = CSM_UNINITIALIZED;

#define CSM_STOP_SEC_VAR_INIT
#include "Csm_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
LOCAL_INLINE FUNC(void, CSM_CODE) Csm_LocalInitJobs(uint32 num);
LOCAL_INLINE FUNC(uint32, CSM_CODE) Csm_GetJobIdIdx(uint32 u32JobId);
LOCAL_INLINE FUNC(uint32, CSM_CODE) Csm_GetKeyIdIdx(uint32 u32KeyId);
#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
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
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
* Function Name: Csm_Init
*
* Explanation: Initializes the CSM module.
*
* param: Csm_ConfigType: Pointer to a selected configuration structure.
*
* retval: None
********************************************************************************
*/
FUNC(void ,CSM_CODE) Csm_Init
(
    P2CONST(Csm_ConfigType, AUTOMATIC, CSM_APPL_CONST) configPtr
)
{
    uint8 errorId = CSM_E_NO_ERROR;
    uint8 num;

    CSM_DUMMY_STATEMENT_CONST(configPtr);   /* PRQA S 3112 */ /* NSCA_QAC_Common_DummyStmt */

    if( CSM_UNINITIALIZED == Csm_ModuleInitState )
    {
        for( num = CSM_ZERO; num < CSM_NUMBER_OF_JOBS; num++ )
        {
            Csm_LocalInitJobs(num);
        }
        for( num = CSM_ZERO; num < CSM_NUMBER_OF_INOUTREDIRECTIONS_CONFIG; num++ )
        {
            cryptoJobRedirectionInfo[num].redirectionConfig = CSM_INVALID_IDX_U8;
            cryptoJobRedirectionInfo[num].inputKeyElementId = CSM_INVALID_IDX_U32;
            cryptoJobRedirectionInfo[num].inputKeyId = CSM_INVALID_IDX_U32;
            cryptoJobRedirectionInfo[num].outputKeyElementId = CSM_INVALID_IDX_U32;
            cryptoJobRedirectionInfo[num].outputKeyId = CSM_INVALID_IDX_U32;
            cryptoJobRedirectionInfo[num].secondaryInputKeyElementId = CSM_INVALID_IDX_U32;
            cryptoJobRedirectionInfo[num].secondaryInputKeyId = CSM_INVALID_IDX_U32;
            cryptoJobRedirectionInfo[num].secondaryOutputKeyElementId = CSM_INVALID_IDX_U32;
            cryptoJobRedirectionInfo[num].secondaryOutputKeyId = CSM_INVALID_IDX_U32;
            cryptoJobRedirectionInfo[num].tertiaryInputKeyElementId = CSM_INVALID_IDX_U32;
            cryptoJobRedirectionInfo[num].tertiaryInputKeyId = CSM_INVALID_IDX_U32;
        }
        Csm_Util_InitJobQueues();
        Csm_ModuleInitState = CSM_INITIALIZED;
    }
    else
    {
        errorId = CSM_E_INIT_FAILED;
    }

    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_INIT, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

}

#if( CSM_VERSION_INFO_API == STD_ON )
/*
********************************************************************************
* Function Name: Csm_GetVersionInfo
*
* Explanation: Returns the version information of this module.
*
* param: versioninfo: Pointer to where to store the version information of this
*                     module.
*
* retval: None
********************************************************************************
*/
FUNC(void ,CSM_CODE) Csm_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CSM_APPL_DATA) versionInfo
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;

    /* Check module init */
    if( NULL_PTR == versionInfo )
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        /*  Return vendor ID, module ID and version data */
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_Csm_Dir4.14 " */
        versionInfo->vendorID = (uint16)CSM_VENDOR_ID;
        versionInfo->moduleID = (uint16)CSM_MODULE_ID;

        versionInfo->sw_major_version = (uint8)CSM_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = (uint8)CSM_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = (uint8)CSM_SW_PATCH_VERSION;
    }

    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_GETVERSIONINFO, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

}
#endif /* CSM_VERSION_INFO_API == STD_ON */

/*
********************************************************************************
* Function Name: Csm_ProcessJobRedirection
*
* Explanation: Process inout redirection.
*
* Parameters(in): jobIdx: Job index.
*
* retval: None
********************************************************************************
*/
static FUNC(void ,CSM_CODE) Csm_ProcessJobRedirection
(
    uint32 jobIdx
)
{
    uint32 ioReCfgIdx;
    uint32 retKeyIdx;

    ioReCfgIdx = csmJobConfig[jobIdx].JobInOutRedrectionIdx;
    /* Polyspace +4 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
    /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
    /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
    /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
    if( (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT == (cryptoJob[jobIdx]->jobRedirectionInfoRef->redirectionConfig & (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT) )
    {
        cryptoJob[jobIdx]->jobRedirectionInfoRef->inputKeyElementId = cryptoInOutRedirectionConfig[ioReCfgIdx].inputKeyElementId;
        retKeyIdx = Csm_GetKeyIdIdx(cryptoInOutRedirectionConfig[ioReCfgIdx].inputKeyId);
        if( CSM_INVALID_IDX_U32 != retKeyIdx )
        {
            /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
            /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
            /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
            cryptoJob[jobIdx]->jobRedirectionInfoRef->inputKeyId = csmKey[retKeyIdx].Keyref;
        }
        else
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            cryptoJob[jobIdx]->jobRedirectionInfoRef->inputKeyId = CSM_INVALID_IDX_U32;
        }
    }
    /* Polyspace +4 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
    /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
    /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
    /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
    if( (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT == (cryptoJob[jobIdx]->jobRedirectionInfoRef->redirectionConfig & (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT) )
    {
        cryptoJob[jobIdx]->jobRedirectionInfoRef->secondaryInputKeyElementId = cryptoInOutRedirectionConfig[ioReCfgIdx].secondaryInputKeyElementId;
        retKeyIdx = Csm_GetKeyIdIdx(cryptoInOutRedirectionConfig[ioReCfgIdx].secondaryInputKeyId);
        if( CSM_INVALID_IDX_U32 != retKeyIdx )
        {
            /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
            /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
            /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
            cryptoJob[jobIdx]->jobRedirectionInfoRef->secondaryInputKeyId = csmKey[retKeyIdx].Keyref;
        }
        else
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            cryptoJob[jobIdx]->jobRedirectionInfoRef->secondaryInputKeyId = CSM_INVALID_IDX_U32;
        }
    }
    /* Polyspace +4 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
    /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
    /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
    /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
    if( (uint8)CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT == (cryptoJob[jobIdx]->jobRedirectionInfoRef->redirectionConfig & (uint8)CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT) )
    {
        cryptoJob[jobIdx]->jobRedirectionInfoRef->tertiaryInputKeyElementId = cryptoInOutRedirectionConfig[ioReCfgIdx].tertiaryInputKeyElementId;
        retKeyIdx = Csm_GetKeyIdIdx(cryptoInOutRedirectionConfig[ioReCfgIdx].tertiaryInputKeyId);
        if( CSM_INVALID_IDX_U32 != retKeyIdx )
        {
            /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
            /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
            /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
            cryptoJob[jobIdx]->jobRedirectionInfoRef->tertiaryInputKeyId = csmKey[retKeyIdx].Keyref;
        }
        else
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            cryptoJob[jobIdx]->jobRedirectionInfoRef->tertiaryInputKeyId = CSM_INVALID_IDX_U32;
        }
    }
    /* Polyspace +4 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
    /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
    /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
    /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
    if( (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT == (cryptoJob[jobIdx]->jobRedirectionInfoRef->redirectionConfig & (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT) )
    {
        cryptoJob[jobIdx]->jobRedirectionInfoRef->outputKeyElementId = cryptoInOutRedirectionConfig[ioReCfgIdx].outputKeyElementId;
        retKeyIdx = Csm_GetKeyIdIdx(cryptoInOutRedirectionConfig[ioReCfgIdx].outputKeyId);
        if( CSM_INVALID_IDX_U32 != retKeyIdx )
        {
            /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
            /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
            /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
            cryptoJob[jobIdx]->jobRedirectionInfoRef->outputKeyId = csmKey[retKeyIdx].Keyref;
        }
        else
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            cryptoJob[jobIdx]->jobRedirectionInfoRef->outputKeyId = CSM_INVALID_IDX_U32;
        }
    }
    /* Polyspace +4 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
    /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
    /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
    /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
    if( (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT == (cryptoJob[jobIdx]->jobRedirectionInfoRef->redirectionConfig & (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT) )
    {
        cryptoJob[jobIdx]->jobRedirectionInfoRef->secondaryOutputKeyElementId = cryptoInOutRedirectionConfig[ioReCfgIdx].secondaryOutputKeyElementId;
        retKeyIdx = Csm_GetKeyIdIdx(cryptoInOutRedirectionConfig[ioReCfgIdx].secondaryOutputKeyId);
        if( CSM_INVALID_IDX_U32 != retKeyIdx )
        {
            /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
            /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
            /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
            cryptoJob[jobIdx]->jobRedirectionInfoRef->secondaryOutputKeyId = csmKey[retKeyIdx].Keyref;
        }
        else
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            cryptoJob[jobIdx]->jobRedirectionInfoRef->secondaryOutputKeyId = CSM_INVALID_IDX_U32;
        }
    }
}

/*
********************************************************************************
* Function Name: Csm_ProcessJob
*
* Explanation: Process job of Csm.
*
* Parameters(in): serviceId: Service id.
*                 queueIdx: Queue Index.
*                 job: Job to be processed.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
********************************************************************************
*/
static FUNC(Std_ReturnType ,CSM_CODE) Csm_ProcessJob
(
    uint8 serviceId,
    uint32 jobIdx,
    Crypto_ServiceInfoType service
)
{
    boolean enqueueFlag = FALSE;
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorRtId = CSM_E_NO_ERROR;
    uint8 errorId = CSM_E_NO_ERROR;
    uint32 queueIdx = csmJobConfig[jobIdx].JobQueueRef;
    Crypto_JobStateType jobSta = cryptoJob[jobIdx]->jobState;

    CSM_DUMMY_STATEMENT_CONST(serviceId);   /* PRQA S 3112 */ /* NSCA_QAC_Common_DummyStmt */
    /* Polyspace +5 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
    /* Polyspace +4 RTE:NIP [Justified:Unset] "NSCA_Polyspace_Csm_NIP" */
    /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
    /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
    /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
    if( cryptoJob[jobIdx]->jobPrimitiveInfo->primitiveInfo->service != service )
    {
        errorId = CSM_E_SERVICE_INVALID;
    }
    else
    {
        if( CRYPTO_JOBSTATE_ACTIVE == jobSta )
        {
            retVal = CryIf_ProcessJob(csmJobQueue[queueIdx]->u32ChannelRef, cryptoJob[jobIdx]);
        }
        else
        {
            if( CSM_JOB_QUEUE_NONE_U32 == csmJobQueue[queueIdx]->u32HeadOfQueuedJobs )
            {
                retVal = CryIf_ProcessJob( csmJobQueue[queueIdx]->u32ChannelRef, cryptoJob[jobIdx] );
                /* Polyspace +4 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
                /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
                /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
                /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
                if( CRYPTO_PROCESSING_ASYNC == cryptoJob[jobIdx]->jobPrimitiveInfo->processingType )
                {
                    /*enqueueFlag = ((uint8)retVal == CRYPTO_E_BUSY) || ((uint8)retVal == CRYPTO_E_QUEUE_FULL);*/
                    if( ((uint8)retVal == CRYPTO_E_BUSY) || ((uint8)retVal == CRYPTO_E_QUEUE_FULL))
                    {
                        enqueueFlag = TRUE;
                    }
                    else
                    {
                        enqueueFlag = FALSE;
                    }
                }
            }
            /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
            else if( CRYPTO_PROCESSING_SYNC == cryptoJob[jobIdx]->jobPrimitiveInfo->processingType )
            {
                /* Polyspace +7 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
                /* Polyspace +6 RTE:NIP [Justified:Unset] "NSCA_Polyspace_Csm_NIP" */
                /* Polyspace +5 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
                /* Polyspace +4 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
                /* Polyspace +3 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
                if( (CSM_JOB_QUEUE_NONE_U32 == csmJobQueue[queueIdx]->u32HeadOfQueuedJobs) ||
                    (cryptoJob[jobIdx]->jobInfo->jobPriority >
                    csmJobQueue[queueIdx]->pQueuedJobs[csmJobQueue[queueIdx]->u32HeadOfQueuedJobs].job.jobInfo->jobPriority) )
                {
                    retVal = CryIf_ProcessJob(csmJobQueue[queueIdx]->u32ChannelRef, cryptoJob[jobIdx]);
                }
                else
                {
                    retVal = CRYPTO_E_BUSY;
                }
            }
            else
            {
                enqueueFlag = TRUE;
            }

            if( TRUE == enqueueFlag )
            {
                /* Add to queue */
                if( TRUE == Csm_Util_QueueJob(queueIdx, cryptoJob[jobIdx]) )
                {
                    retVal = E_OK;
                }
                else
                {
                    retVal = CRYPTO_E_QUEUE_FULL;
                    errorRtId = CSM_E_QUEUE_FULL;
                }
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(serviceId, errorId);
    }
    if( CSM_E_NO_ERROR != errorRtId )
    {
        (void)CSM_REPORTRUNTIME_DEV_ERROR(serviceId, errorRtId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
    CSM_DUMMY_STATEMENT(errorRtId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_Hash
*
* Explanation: Uses the given data to perform the hash calculation and stores
*              the hash.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 mode: Indicates which operation mode(s) to perfom.
*                 dataPtr: Contains the pointer to the data for which the hash
*                          shall be computed.
*                 dataLength: Contains the number of bytes to be hashed.
*
* Parameters(inout): resultLengthPtr: Holds a pointer to the memory location in
*                                     which the output length in bytes is stored.
*                                     On calling this function,this parameter
*                                     shall contain the size of the buffer
*                                     provided by resultPtr. When the request has
*                                     finished, the actual length of the returned
*                                     value shall be stored.
*
* Parameters(out): resultPtr: Contains the pointer to the data where the hash
*                             value shall be stored.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
*                         CRYPTO_E_SMALL_BUFFER: The provided buffer is too
*                                                small to store the result
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_Hash
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) dataPtr,
    uint32 dataLength,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) resultPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) resultLengthPtr
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    uint32 jobIdIdx;
    Std_ReturnType retVal = E_NOT_OK;

    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( CRYPTO_OPERATIONMODE_ERROE == mode )       /* [SWS_Csm_01045] */
    {
        errorId = CSM_E_PROCESSING_MODE;
    }
    else if( (CRYPTO_OPERATIONMODE_FINISH == mode) &&
             ((NULL_PTR == resultPtr) ||
             (NULL_PTR == resultLengthPtr)) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else if( (CRYPTO_OPERATIONMODE_UPDATE == mode) &&
             ((NULL_PTR == dataPtr) ||
             ((uint32)CSM_ZERO == dataLength)) )
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            retVal = E_NOT_OK;
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
            {   /* [SWS_Csm_91014] */
                /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_Csm_Dir4.14 " */
                if( (CSM_ZERO != dataLength) || (CSM_ZERO != *resultLengthPtr) )
                {
                    errorId = CSM_E_LENGTH_NOT_ZERO;
                }
                else
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
            }

            if( CSM_E_NO_ERROR == errorId )
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = mode;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputPtr = dataPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputPtr = resultPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputLength = dataLength;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputLengthPtr = resultLengthPtr;

                retVal = Csm_ProcessJob(CSM_SID_HASH, jobIdIdx, CRYPTO_HASH);
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_HASH, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_MacGenerate
*
* Explanation: Uses the given data to perform a MAC generation and stores the
*              MAC in the memory location pointed to by the MAC pointer.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 mode: Indicates which operation mode(s) to perfom.
*                 dataPtr: Contains the pointer to the data for which the MAC
*                          shall be computed.
*                 dataLength: Contains the number of bytes to be hashed.
*
* Parameters(inout): macLengthPtr: Holds a pointer to the memory location in
*                                  which the output length in bytes is stored.
*                                  On calling this function,this parameter shall
*                                  contain the size of the buffer provided by
*                                  resultPtr. When the request has finished,
*                                  the actual length of the returned value shall
*                                  be stored.
*
* Parameters(out): macPtr: Contains the pointer to the data where the mac value
*                          shall be stored.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's
*                                                 state is "invalid"
*                         CRYPTO_E_SMALL_BUFFER:The provided buffer is too small
*                                               to store the result
*                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, a key
*                                                     element has the wrong size
*                         CRYPTO_E_KEY_EMPTY: Request failed because of
*                                             uninitialized source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_MacGenerate
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) dataPtr,
    uint32 dataLength,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) macPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) macLengthPtr
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    uint32 jobIdIdx;
    Std_ReturnType retVal = E_NOT_OK;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( CRYPTO_OPERATIONMODE_ERROE == mode )       /* [SWS_Csm_01045] */
    {
        errorId = CSM_E_PROCESSING_MODE;
    }
    else if( (CRYPTO_OPERATIONMODE_FINISH == mode) &&
             ((NULL_PTR == macPtr) ||
             (NULL_PTR == macLengthPtr)) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else if( (CRYPTO_OPERATIONMODE_UPDATE == mode) &&
             ((NULL_PTR == dataPtr) ||
             ((uint32)CSM_ZERO == dataLength)) )
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            retVal = E_NOT_OK;
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
            {   /* [SWS_Csm_91014] */
                /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_Csm_Dir4.14 " */
                if( (CSM_ZERO != dataLength) || (CSM_ZERO != *macLengthPtr) )
                {
                    errorId = CSM_E_LENGTH_NOT_ZERO;
                }
                else
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
            }
            if( CSM_E_NO_ERROR == errorId )
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = mode;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputPtr = dataPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputPtr = macPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputLength = dataLength;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputLengthPtr = macLengthPtr;

                retVal = Csm_ProcessJob(CSM_SID_MACGENERATE, jobIdIdx, CRYPTO_MACGENERATE);
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_MACGENERATE, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_MacVerify
*
* Explanation: Uses the given data to perform a MAC generation and stores the
*              MAC in the memory location pointed to by the MAC pointer.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 mode: Indicates which operation mode(s) to perfom.
*                 dataPtr: Holds a pointer to the data for which the MAC shall be
*                          verified.
*                 dataLength: Contains the number of data bytes for which the MAC
*                             shall be verified.
*                 macPtr: Holds a pointer to the MAC to be verified.
*                 macLength: Contains the MAC length in BITS to be verified.
*
* Parameters(out): verifyPtr: Holds a pointer to the memory location, which will
*                             hold the result of the MAC verification
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_SMALL_BUFFER:The provided buffer is too small
*                                               to store the result
*                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, a key
*                                                     element has the wrong size
*                         CRYPTO_E_KEY_EMPTY: Request failed because of
*                                             uninitialized source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_MacVerify
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) dataPtr,
    uint32 dataLength,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) macPtr,
    CONST(uint32, CSM_CONST) macLength,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) verifyPtr
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    uint32 jobIdIdx;
    Std_ReturnType retVal = E_NOT_OK;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( CRYPTO_OPERATIONMODE_ERROE == mode )       /* [SWS_Csm_01045] */
    {
        errorId = CSM_E_PROCESSING_MODE;
    }
    else if( (CRYPTO_OPERATIONMODE_FINISH == mode) &&
             ((NULL_PTR == macPtr) ||
             ((uint32)CSM_ZERO == macLength) ||
             (NULL_PTR == verifyPtr)) )
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else if( (CRYPTO_OPERATIONMODE_UPDATE == mode) &&
             ((NULL_PTR == dataPtr) ||
             ((uint32)CSM_ZERO == dataLength)) )
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            retVal = E_NOT_OK;
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
            {
                if( (CSM_ZERO != dataLength) || (CSM_ZERO != macLength) )    /* [SWS_Csm_91014] */
                {
                    errorId = CSM_E_LENGTH_NOT_ZERO;
                }
                else
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
            }

            if( CSM_E_NO_ERROR == errorId )
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = mode;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputPtr = dataPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.secondaryInputPtr = macPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputLength = dataLength;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.secondaryInputLength = macLength;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.verifyPtr = verifyPtr;

                retVal = Csm_ProcessJob(CSM_SID_MACVERIFY, jobIdIdx, CRYPTO_MACVERIFY);
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_MACVERIFY, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;

}

/*
********************************************************************************
* Function Name: Csm_Encrypt
*
* Explanation: Encrypts the given data and store the ciphertext in the memory
*              location pointed by the result pointer.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 mode: Indicates which operation mode(s) to perfom.
*                 dataPtr: Contains the pointer to the data for which the hash
*                          shall be computed.
*                 dataLength: Contains the number of bytes to be hashed.
*
* Parameters(inout): resultLengthPtr: Holds a pointer to the memory location in
*                                     which the output length in bytes is stored.
*                                     On calling this function,this parameter
*                                     shall contain the size of the buffer
*                                     provided by resultPtr. When the request has
*                                     finished, the actual length of the returned
*                                     value shall be stored.
*
* Parameters(out): resultPtr: Contains the pointer to the data where the hash
*                             value shall be stored.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
*                         CRYPTO_E_SMALL_BUFFER: The provided buffer is too small
*                                                to store the result
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, a key
*                                                     element has the wrong size
*                         CRYPTO_E_KEY_EMPTY: Request failed because of
*                                             uninitialized source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_Encrypt
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) dataPtr,
    uint32 dataLength,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) resultPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) resultLengthPtr
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    uint32 jobIdIdx;
    Std_ReturnType retVal = E_NOT_OK;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( CRYPTO_OPERATIONMODE_ERROE == mode )       /* [SWS_Csm_01045] */
    {
        errorId = CSM_E_PROCESSING_MODE;
    }
    else if( (CRYPTO_OPERATIONMODE_FINISH == mode) &&
             ((NULL_PTR == resultPtr) ||
             (NULL_PTR == resultLengthPtr)) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else if( (CRYPTO_OPERATIONMODE_UPDATE == mode) &&
             ((NULL_PTR == dataPtr) ||
             ((uint32)CSM_ZERO == dataLength) ||
             (NULL_PTR == resultPtr) ||
             (NULL_PTR == resultLengthPtr)) )
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            retVal = E_NOT_OK;
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
            {   /* [SWS_Csm_91014] */
                /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_Csm_Dir4.14 " */
                if( (CSM_ZERO != dataLength) || (CSM_ZERO != *resultLengthPtr) )
                {
                    errorId = CSM_E_LENGTH_NOT_ZERO;
                }
                else
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
            }
            if( CSM_E_NO_ERROR == errorId )
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = mode;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputPtr = dataPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputPtr = resultPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputLength = dataLength;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputLengthPtr = resultLengthPtr;

                retVal = Csm_ProcessJob(CSM_SID_ENCRYPT, jobIdIdx, CRYPTO_ENCRYPT);
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_ENCRYPT, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_Decrypt
*
* Explanation: Decrypts the given encrypted data and store the decrypted
*              plaintext in the memory location pointed by the result pointer.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 mode: Indicates which operation mode(s) to perfom.
*                 dataPtr: Contains the pointer to the data to be decrypted.
*                 dataLength: Contains the number of bytes to decrypt.
*
* Parameters(inout): resultLengthPtr: Holds a pointer to the memory location in
*                                     which the output length in bytes is stored.
*                                     On calling this function,this parameter
*                                     shall contain the size of the buffer provided
*                                     by resultPtr. When the request has finished,
*                                     the actual length of the returned value shall
*                                     be stored.
*
* Parameters(out): resultPtr: Contains the pointer to the data where the hash value
*                             shall be stored.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
*                         CRYPTO_E_SMALL_BUFFER: The provided buffer is too small
*                                                to store the result
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, a key
*                                                     element has the wrong size
*                         CRYPTO_E_KEY_EMPTY: Request failed because of
*                                             uninitialized source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_Decrypt
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) dataPtr,
    uint32 dataLength,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) resultPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) resultLengthPtr
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    uint32 jobIdIdx;
    Std_ReturnType retVal = E_NOT_OK;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( CRYPTO_OPERATIONMODE_ERROE == mode )       /* [SWS_Csm_01045] */
    {
        errorId = CSM_E_PROCESSING_MODE;
        retVal = E_NOT_OK;
    }
    else if( (CRYPTO_OPERATIONMODE_FINISH == mode) &&
             ((NULL_PTR == resultPtr) ||
             (NULL_PTR == resultLengthPtr)) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else if( (CRYPTO_OPERATIONMODE_UPDATE == mode) &&
             ((NULL_PTR == dataPtr) ||
             ((uint32)CSM_ZERO == dataLength) ||
             (NULL_PTR == resultPtr) ||
             (NULL_PTR == resultLengthPtr)) )
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            retVal = E_NOT_OK;
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
            {   /* [SWS_Csm_91014] */
                /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_Csm_Dir4.14 " */
                if( (CSM_ZERO != dataLength) || (CSM_ZERO != *resultLengthPtr) )
                {
                    errorId = CSM_E_LENGTH_NOT_ZERO;
                }
                else
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
            }
            if( CSM_E_NO_ERROR == errorId )
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = mode;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputPtr = dataPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputPtr = resultPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputLength = dataLength;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputLengthPtr = resultLengthPtr;

                retVal = Csm_ProcessJob(CSM_SID_DECRYPT, jobIdIdx, CRYPTO_DECRYPT);
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_DECRYPT, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_AEADEncrypt
*
* Explanation: Uses the given input data to perform a AEAD encryption and stores
*              the ciphertext and the MAC in the memory locations pointed by the
*              ciphertext pointer and Tag pointer.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 plaintextPtr: Contains the pointer to the data to be encrypted.
*                 plaintextLength: contains the number of bytes to encrypt.
*                 associatedDataPtr: Contains the pointer to the associated data.
*                 associatedDataLength: Contains the number of bytes of the
*                                       associated data.
*
* Parameters(inout): ciphertextLengthPtr: Holds a pointer to the memory location
*                                         in which the output length in bytes of
*                                         the ciphertext is stored. On calling
*                                         this function, this parameter shall
*                                         contain the size of the buffer in bytes
*                                         provided by resultPtr. When the request
*                                         has finished, the actual length of the
*                                         returned value shall be stored.
*                    tagLengthPtr: Holds a pointer to the memory location in which
*                                  the output length in bytes of the Tag is stored.
*                                  On calling this function, this parameter shall
*                                  contain the size of the buffer in bytes provided
*                                  by resultPtr. When the request has finished, the
*                                  actual length of the returned value shall be
*                                  stored.
* Parameters(out): ciphertextPtr: Contains the pointer to the data where the encrypted
*                                 data shall be stored.
*                  tagPtr: Contains the pointer to the data where the Tag shall be
*                          stored.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
*                         CRYPTO_E_SMALL_BUFFER: The provided buffer is too small
*                                                to store the result
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, a key element
*                                                     has the wrong size
*                         CRYPTO_E_KEY_EMPTY: Request failed because of
*                                             uninitialized source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_AEADEncrypt
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) plaintextPtr,
    uint32 plaintextLength,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) associatedDataPtr,
    uint32 associatedDataLength,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) ciphertextPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) ciphertextLengthPtr,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) tagPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) tagLengthPtr
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    uint32 jobIdIdx;
    Std_ReturnType retVal = E_NOT_OK;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( CRYPTO_OPERATIONMODE_ERROE == mode )       /* [SWS_Csm_01045] */
    {
        errorId = CSM_E_PROCESSING_MODE;
        retVal = E_NOT_OK;
    }
    else if( (CRYPTO_OPERATIONMODE_FINISH == mode) &&
             ((NULL_PTR == associatedDataPtr) ||
             ((uint32)CSM_ZERO == associatedDataLength) ||
             (NULL_PTR == ciphertextPtr) ||
             (NULL_PTR == ciphertextLengthPtr) ||
             (NULL_PTR == tagPtr) ||
             (NULL_PTR == tagLengthPtr)) )
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else if( (CRYPTO_OPERATIONMODE_UPDATE == mode) &&
             ((NULL_PTR == plaintextPtr) ||
             ((uint32)CSM_ZERO == plaintextLength) ||
             (NULL_PTR == ciphertextPtr) ||
             (NULL_PTR == ciphertextLengthPtr)) )
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            retVal = E_NOT_OK;
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
            {   /* [SWS_Csm_91014] */
                /* Polyspace +2 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_Csm_Dir4.14 " */
                if( (CSM_ZERO != plaintextLength) || (CSM_ZERO != associatedDataLength) ||
                    (CSM_ZERO != *ciphertextLengthPtr) || (CSM_ZERO != *tagLengthPtr) )
                {
                    errorId = CSM_E_LENGTH_NOT_ZERO;
                }
                else
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
            }
            if( CSM_E_NO_ERROR == errorId )
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = mode;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputPtr = plaintextPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.secondaryInputPtr = associatedDataPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputPtr = ciphertextPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.secondaryOutputPtr = tagPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputLength = plaintextLength;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.secondaryInputLength = associatedDataLength;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputLengthPtr = ciphertextLengthPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.secondaryOutputLengthPtr = tagLengthPtr;

                retVal = Csm_ProcessJob(CSM_SID_AEADENCRYPT, jobIdIdx, CRYPTO_AEADENCRYPT);
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_AEADENCRYPT, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_AEADDecrypt
*
* Explanation: Uses the given input data to perform a AEAD encryption and stores
*              the ciphertext and the MAC in the memory locations pointed by the
*              ciphertext pointer and Tag pointer.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 plaintextPtr: Contains the pointer to the data to be encrypted.
*                 plaintextLength: contains the number of bytes to encrypt.
*                 associatedDataPtr: Contains the pointer to the associated data.
*                 associatedDataLength: Contains the number of bytes of the associated
*                                       data.
*
* Parameters(inout): ciphertextLengthPtr: Holds a pointer to the memory location
*                                         in which the output length in bytes of
*                                         the ciphertext is stored. On calling
*                                         this function, this parameter shall
*                                         contain the size of the buffer in bytes
*                                         provided by resultPtr. When the request
*                                         has finished, the actual length of the
*                                         returned value shall be stored.
*                    tagLengthPtr: Holds a pointer to the memory location in which
*                                  the output length in bytes of the Tag is stored.
*                                  On calling this function, this parameter shall
*                                  contain the size of the buffer in bytes provided
*                                  by resultPtr. When the request has finished, the
*                                  actual length of the returned value shall be stored.
* Parameters(out): ciphertextPtr: Contains the pointer to the data where the encrypted
*                                 data shall be stored.
*                  tagPtr: Contains the pointer to the data where the Tag shall be stored.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
*                         CRYPTO_E_SMALL_BUFFER: The provided buffer is too
*                                                small to store the result
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, a key element
*                                                     has the wrong size
*                         CRYPTO_E_KEY_EMPTY: Request failed because of
*                                             uninitialized source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_AEADDecrypt
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) ciphertextPtr,
    uint32 ciphertextLength,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) associatedDataPtr,
    uint32 associatedDataLength,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) tagPtr,
    uint32 tagLength,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) plaintextPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) plaintextLengthPtr,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) verifyPtr
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    uint32 jobIdIdx;
    Std_ReturnType retVal = E_NOT_OK;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( CRYPTO_OPERATIONMODE_ERROE == mode )       /* [SWS_Csm_01045] */
    {
        errorId = CSM_E_PROCESSING_MODE;
        retVal = E_NOT_OK;
    }
    else if( (CRYPTO_OPERATIONMODE_FINISH == mode) &&
             ((NULL_PTR == associatedDataPtr) ||
             ((uint32)CSM_ZERO == associatedDataLength) ||
             (NULL_PTR == tagPtr) ||
             ((uint32)CSM_ZERO == tagLength) ||
             (NULL_PTR == plaintextPtr) ||
             (NULL_PTR == plaintextLengthPtr) ||
             (NULL_PTR == verifyPtr)) )
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else if( (CRYPTO_OPERATIONMODE_UPDATE == mode) &&
             ((NULL_PTR == ciphertextPtr) ||
             ((uint32)CSM_ZERO == ciphertextLength) ||
             (NULL_PTR == plaintextPtr) ||
             (NULL_PTR == plaintextLengthPtr)) )
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            retVal = E_NOT_OK;
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
            {   /* [SWS_Csm_91014] */
                if( (CSM_ZERO != ciphertextLength) || (CSM_ZERO != associatedDataLength) ||
                    /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_Csm_Dir4.14 " */
                    (CSM_ZERO != tagLength) || (CSM_ZERO != *plaintextLengthPtr) )
                {
                    errorId = CSM_E_LENGTH_NOT_ZERO;
                }
                else
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
            }
            if( CSM_E_NO_ERROR == errorId )
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = mode;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputPtr = ciphertextPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.secondaryInputPtr = associatedDataPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.tertiaryInputPtr = tagPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputPtr = plaintextPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputLength = ciphertextLength;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.secondaryInputLength = associatedDataLength;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.tertiaryInputLength = tagLength;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputLengthPtr = plaintextLengthPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.verifyPtr = verifyPtr;

                retVal = Csm_ProcessJob(CSM_SID_AEADDECRYPT, jobIdIdx, CRYPTO_AEADDECRYPT);
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_AEADDECRYPT, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_SignatureGenerate
*
* Explanation: Uses the given data to perform the signature calculation and stores
*              the signature in the memory location pointed by the result pointer.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 mode: Indicates which operation mode(s) to perfom.
*                 dataPtr: Contains the pointer to the data for which the hash shall
*                          be computed.
*                 dataLength: Contains the number of bytes to be hashed.
*
* Parameters(inout): resultLengthPtr: Holds a pointer to the memory location in
*                                     which the output length in bytes is stored.
*                                     On calling this function,this parameter shall
*                                     contain the size of the buffer provided by
*                                     resultPtr. When the request has finished, the
*                                     actual length of the returned value shall be
*                                     stored.
*
* Parameters(out): resultPtr: Contains the pointer to the data where the hash value
*                             shall be stored.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
*                         CRYPTO_E_SMALL_BUFFER: The provided buffer is too small
*                                                to store the result
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, a key element
*                                                     has the wrong size
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_SignatureGenerate
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) dataPtr,
    uint32 dataLength,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) resultPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) resultLengthPtr
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    uint32 jobIdIdx;
    Std_ReturnType retVal = E_NOT_OK;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( CRYPTO_OPERATIONMODE_ERROE == mode )       /* [SWS_Csm_01045] */
    {
        errorId = CSM_E_PROCESSING_MODE;
        retVal = E_NOT_OK;
    }
    else if( (CRYPTO_OPERATIONMODE_FINISH == mode) &&
             ((NULL_PTR == resultPtr) ||
             (NULL_PTR == resultLengthPtr)) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else if( (CRYPTO_OPERATIONMODE_UPDATE == mode) &&
             ((NULL_PTR == dataPtr) ||
             ((uint32)CSM_ZERO == dataLength)) )
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            retVal = E_NOT_OK;
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            if( CRYPTO_JOBSTATE_ACTIVE == cryptoJob[jobIdIdx]->jobState)
            {
                retVal = CRYPTO_E_BUSY;
            }
            else
            {
                if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
                {   /* [SWS_Csm_91014] */
                    /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_Csm_Dir4.14 " */
                    if( (CSM_ZERO != dataLength) || (CSM_ZERO != *resultLengthPtr) )
                    {
                        errorId = CSM_E_LENGTH_NOT_ZERO;
                    }
                    else
                    {
                        Csm_ProcessJobRedirection(jobIdIdx);
                    }
                }
                if( CSM_E_NO_ERROR == errorId )
                {
                    cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = mode;
                    cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputPtr = dataPtr;
                    cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputPtr = resultPtr;
                    cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputLength = dataLength;
                    cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputLengthPtr = resultLengthPtr;

                   retVal = Csm_ProcessJob(CSM_SID_SIGNATUREGENERATE, jobIdIdx, CRYPTO_SIGNATUREGENERATE);
               }
            }
        }
    }

    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_SIGNATUREGENERATE, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_SignatureVerify
*
* Explanation: Verifies the given MAC by comparing if the signature is generated
*              with the given data.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 mode: Indicates which operation mode(s) to perfom.
*                 dataPtr: Holds a pointer to the data for which the MAC shall be
*                          verified.
*                 dataLength: Contains the number of data bytes for which the MAC
*                             shall be verified.
*                 signaturePtr: Holds a pointer to the signature to be verified.
*                 signatureLength: Contains the signature length in BITS to be
*                                  verified.
*
* Parameters(out): verifyPtr: Holds a pointer to the memory location, which will
*                             hold the result of the MAC verification.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_SMALL_BUFFER:The provided buffer is too small
*                                               to store the result
*                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, a key element
*                                                     has the wrong size
*                         CRYPTO_E_KEY_EMPTY: Request failed because of
*                                             uninitialized source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_SignatureVerify
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) dataPtr,
    uint32 dataLength,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) signaturePtr,
    uint32 signatureLength,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) verifyPtr
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    uint32 jobIdIdx;
    Std_ReturnType retVal = E_NOT_OK;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( CRYPTO_OPERATIONMODE_ERROE == mode )       /* [SWS_Csm_01045] */
    {
        errorId = CSM_E_PROCESSING_MODE;
        retVal = E_NOT_OK;
    }
    else if( (CRYPTO_OPERATIONMODE_FINISH == mode) &&
             ((NULL_PTR == signaturePtr) ||
             ((uint32)CSM_ZERO == signatureLength) ||
             (NULL_PTR == verifyPtr)) )
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else if( (CRYPTO_OPERATIONMODE_UPDATE == mode) &&
             ((NULL_PTR == dataPtr) ||
             ((uint32)CSM_ZERO == dataLength)) )
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            retVal = E_NOT_OK;
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
            {   /* [SWS_Csm_91014] */
                if( (CSM_ZERO != dataLength) || (CSM_ZERO != signatureLength) )
                {
                    errorId = CSM_E_LENGTH_NOT_ZERO;

                }
                else
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
            }
            if( CSM_E_NO_ERROR == errorId )
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = mode;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputPtr = dataPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.secondaryInputPtr = signaturePtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputLength = dataLength;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.secondaryInputLength = signatureLength;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.verifyPtr = verifyPtr;

                retVal = Csm_ProcessJob(CSM_SID_SIGNATUREVERIFY, jobIdIdx, CRYPTO_SIGNATUREVERIFY);
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_SIGNATUREVERIFY, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_RandomGenerate
*
* Explanation: Generate a random number and stores it in the memory location
*              pointed by the result pointer.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*
* Parameters(inout): resultLengthPtr: Holds a pointer to the memory location in
*                       which the result length in bytes is stored. On calling
*                       this function, this parameter shall contain the number
*                       of random bytes, which shall be stored to the buffer
*                       provided by resultPtr. When the request has finished,
*                       the actual length of the returned value shall be stored.
*
* Parameters(out): resultPtr: Holds a pointer to the memory location which will
*                             hold the result of the random number generation.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
*                         CRYPTO_E_ENTROPY_EXHAUSTION: Request failed, entropy
*                           of random number generator is exhausted
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_RandomGenerate
(
    uint32 jobId,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) resultPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) resultLengthPtr
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    uint32 jobIdIdx;
    Std_ReturnType retVal = E_NOT_OK;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( (NULL_PTR == resultPtr) || (NULL_PTR == resultLengthPtr) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            retVal = E_NOT_OK;
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
            {   /* [SWS_Csm_91014] */
                /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_Csm_Dir4.14 " */
                if( CSM_ZERO != *resultLengthPtr)
                {
                    errorId = CSM_E_LENGTH_NOT_ZERO;
                    retVal = E_NOT_OK;
                }
                else
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
            }
            if( CSM_E_NO_ERROR == errorId )
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputPtr = resultPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputLengthPtr = resultLengthPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL;  /* [SWS_Csm_01054] */
                retVal = Csm_ProcessJob(CSM_SID_RANDOMGENERATE, jobIdIdx, CRYPTO_RANDOMGENERATE);
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_RANDOMGENERATE, errorId);
    }
#else
        CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_KeyElementSet
*
* Explanation: Sets the given key element bytes to the key identified by keyId.
*
* Parameters(in): keyId: Holds the identifier of the key for which a new material
*                        shall be set.
*                 keyElementId: Holds the identifier of the key element to be
*                               written.
*                 keyPtr: Holds the pointer to the key element bytes to be
*                         processed.
*                 keyLength: Contains the number of key element bytes.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
*                         CRYPTO_E_KEY_WRITE_FAIL:Request failed because write
*                                                 access was denied
*                         CRYPTO_E_KEY_NOT_AVAILABLE: Request failed because the
*                                                     key is not available
*                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element
*                                                     size does not match size of
*                                                     provided data
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyElementSet
(
    uint32 keyId,
    uint32 keyElementId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) keyPtr,
    uint32 keyLength
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 keyIdIdx;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( NULL_PTR == keyPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        keyIdIdx = Csm_GetKeyIdIdx(keyId);
        if( CSM_INVALID_IDX_U32 != keyIdIdx )
        {
            retVal = CryIf_KeyElementSet(csmKey[keyIdIdx].Keyref, keyElementId, keyPtr, keyLength);
        }
        else
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_KEYELEMENTSET, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_KeySetValid
*
* Explanation: Sets the key state of the key identified by keyId to valid.
*
* Parameters(in): keyId: Holds the identifier of the key for which a new
*                   material shall be set.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_KeySetValid
(
    uint32 keyId
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 keyIdIdx;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else
    {
        keyIdIdx = Csm_GetKeyIdIdx(keyId);
        if( CSM_INVALID_IDX_U32 != keyIdIdx )
        {
            retVal = CryIf_KeySetValid(csmKey[keyIdIdx].Keyref);
        }
        else
        {
            errorId = CSM_E_PARAM_HANDLE;
            retVal = CRYPTO_E_KEY_NOT_VALID;
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_KEYSETVALID, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_KeyElementGet
*
* Explanation: Retrieves the key element bytes from a specific key element of the
*              key identified by the keyId and stores the key element in the memory
*              location pointed by the key pointer.
*
* Parameters(in): keyId: Holds the identifier of the key for which a new material
shall be set.
*                 keyElementId: Holds the identifier of the key element to be
*                               extracted.
*
* Parameters(inout): keyLengthPtr: Holds a pointer to the memory location in which
*                    the output buffer length in bytes is stored. On calling this
*                    function, this parameter shall contain the buffer length in
*                    bytes of the keyPtr. When the request has finished, the actual
*                    size of the written input bytes shall be stored.
*
* Parameters(inout): keyPtr: Holds the pointer to the memory location where the key
*                            shall be copied to.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
*                         CRYPTO_E_KEY_WRITE_FAIL:Request failed because write
*                                                 access was denied
*                         CRYPTO_E_SMALL_BUFFER: The provided buffer is too small
*                                                to store the result
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyElementGet
(
    uint32 keyId,
    uint32 keyElementId,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) keyPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) keyLengthPtr
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 keyIdIdx;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( (NULL_PTR == keyPtr) || (NULL_PTR == keyLengthPtr) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        keyIdIdx = Csm_GetKeyIdIdx(keyId);
        if( CSM_INVALID_IDX_U32 != keyIdIdx )
        {
            retVal = CryIf_KeyElementGet(csmKey[keyIdIdx].Keyref, keyElementId, keyPtr, keyLengthPtr);
        }
        else
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_KEYELEMENTGET, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_KeyElementCopy
*
* Explanation: This function shall copy a key elements from one key to a target key.
*
* Parameters(in): keyId: Holds the identifier of the key whose key element shall be
*                        the source element.
*                 keyElementId: Holds the identifier of the key element which shall
*                               be the source for the copy operation.
*                 targetKeyId: Holds the identifier of the key whose key element shall
*                              be the destination element
*                 targetKeyElementId: Holds the identifier of the key element which
*                                     shall be the destination for the copy operation.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
*                         CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to
*                                                 extract key element
*                         CRYPTO_E_KEY_WRITE_FAIL:Request failed because write
*                                                 access was denied
*                         CRYPTO_E_KEY_NOT_AVAILABLE: Request failed because the
*                                                     key is not available
*                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element
*                                                     size does not match size of
*                                                     provided data
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyElementCopy
(
    CONST(uint32, CSM_CONST) keyId,
    CONST(uint32, CSM_CONST) keyElementId,
    CONST(uint32, CSM_CONST) targetKeyId,
    CONST(uint32, CSM_CONST) targetKeyElementId
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 keyIdIdx;
    uint32 targetKeyIdIdx;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else
    {
        keyIdIdx = Csm_GetKeyIdIdx(keyId);
        targetKeyIdIdx = Csm_GetKeyIdIdx(targetKeyId);

        if( (CSM_INVALID_IDX_U32 != keyIdIdx) && (CSM_INVALID_IDX_U32 != targetKeyIdIdx) )
        {
            retVal = CryIf_KeyElementCopy(csmKey[keyIdIdx].Keyref, keyElementId,
                                          csmKey[targetKeyIdIdx].Keyref, targetKeyElementId);
        }
        else
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_KEYELEMENTCOPY, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;

}

/*
********************************************************************************
* Function Name: Csm_KeyCopy
*
* Explanation: This function shall copy a key elements from one key to a target key.
*
* Parameters(in): keyId: Holds the identifier of the key whose key element shall be
*                        the source element.
*                 keyElementId: Holds the identifier of the key element which shall
*                               be the source for the copy operation.
*                 targetKeyId: Holds the identifier of the key whose key element
*                              shall be the destination element
*                 targetKeyElementId: Holds the identifier of the key element which
*                                     shall be the destination for the copy operation.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
*                         CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to
*                                                 extract key element
*                         CRYPTO_E_KEY_WRITE_FAIL:Request failed because write
*                                                 access was denied
*                         CRYPTO_E_KEY_NOT_AVAILABLE: Request failed because the
*                                                     key is not available
*                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element
*                                                     size does not match size of
*                                                     provided data
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyCopy
(
    CONST(uint32, CSM_CONST) keyId,
    CONST(uint32, CSM_CONST) targetKeyId
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 keyIdIdx;
    uint32 targetKeyIdIdx;

    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else
    {
        keyIdIdx = Csm_GetKeyIdIdx(keyId);
        targetKeyIdIdx = Csm_GetKeyIdIdx(targetKeyId);
        if( (CSM_INVALID_IDX_U32 != keyIdIdx) && (CSM_INVALID_IDX_U32 != targetKeyIdIdx) )
        {
            retVal = CryIf_KeyCopy(csmKey[keyIdIdx].Keyref, csmKey[targetKeyIdIdx].Keyref);
        }
        else
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_KEYCOPY, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

#if( CSM_KEY_ELEMENT_COPY_PARTIAL == STD_ON )

/*
********************************************************************************
* Function Name: Csm_KeyElementCopyPartial
*
* Explanation: Copies a key element to another key element in the same crypto driver.
*              The keyElementSourceOffset and keyElementCopyLength allows to copy
*              just a part of the source key element into the destination.The offset
*              into the target key is also specified with this function.
*
* Parameters(in): keyId: Holds the identifier of the key whose key element shall be
*                        the source element.
*                 keyElementId: Holds the identifier of the key element which shall
*                               be the source for the copy operation
*                 keyElementSourceOffset: This is the offset of the source key element
*                                         indicating the start index of the copy operation.
*                 keyElementTargetOffset: This is the offset of the destination key element
*                                         indicating the start index of the copy operation.
*                 keyElementCopyLength: Specifies the number of bytes that shall be copied.
*                 targetKeyId: Holds the identifier of the key whose key element shall be
*                              the destination element
*                 targetKeyElementId: Holds the identifier of the key element which shall be
*                                     the destination for the copy operation.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, service is still busy
*                         CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to
*                                                 extract key element
*                         CRYPTO_E_KEY_WRITE_FAIL:Request failed because write
*                                                 access was denied
*                         CRYPTO_E_KEY_NOT_AVAILABLE: Request failed because the
*                                                     key is not available
*                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element
*                                                     size does not match size of
*                                                     provided data
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyElementCopyPartial
(
    uint32 keyId,
    uint32 keyElementId,
    uint32 keyElementSourceOffset,
    uint32 keyElementTargetOffset,
    uint32 keyElementCopyLength,
    uint32 targetKeyId,
    uint32 targetKeyElementId
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;

    uint32 keyIdIdx;
    uint32 targetKeyIdIdx;

    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( (keyElementTargetOffset + keyElementCopyLength) >(CSM_MAX_SIZE_OF_ELEMENT) )
    {
        errorId = CRYPTO_E_KEY_SIZE_MISMATCH;
    }
    else
    {
        keyIdIdx = Csm_GetKeyIdIdx(keyId);
        targetKeyIdIdx = Csm_GetKeyIdIdx(targetKeyId);

        if( (CSM_INVALID_IDX_U32 != keyIdIdx ) && (CSM_INVALID_IDX_U32 != targetKeyIdIdx ) )
        {
            retVal = CryIf_KeyElementCopyPartial(csmKey[keyIdIdx].Keyref, keyElementId, keyElementSourceOffset,
                                                 keyElementTargetOffset, keyElementCopyLength, csmKey[targetKeyIdIdx].Keyref,
                                                 targetKeyElementId);
        }
        else
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_KEYELEMENTCOPYPARTIAL, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}
#endif

/*
********************************************************************************
* Function Name: Csm_RandomSeed
*
* Explanation: Feeds the key element CRYPTO_KE_RANDOM_SEED with a random seed.
*
* Parameters(in): keyId: Holds the identifier of the key for which a new seed shall
*                        be generated.
*                 seedPtr: Holds a pointer to the memory location which contains
*                          the data to feed the seed.
*                 seedLength: Contains the length of the seed in bytes.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is
*                                        busy
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_RandomSeed
(
    uint32 keyId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) seedPtr,
    uint32  seedLength
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 keyIdIdx;

    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( NULL_PTR == seedPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        keyIdIdx = Csm_GetKeyIdIdx(keyId);
        if( CSM_INVALID_IDX_U32 != keyIdIdx )
        {
            retVal = CryIf_RandomSeed(csmKey[keyIdIdx].Keyref, seedPtr, seedLength);
        }
        else
        {
            errorId = CSM_E_PARAM_HANDLE;
            retVal = CRYPTO_E_KEY_NOT_VALID;
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_RANDOMSEED, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_KeyGenerate
*
* Explanation: Generates new key material and store it in the key identified by
*              keyId.
*
* Parameters(in): keyId: Holds the identifier of the key for which a new material
*                 shall be generated.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is
*                                        busy
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyGenerate
(
    uint32 keyId
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 keyIdIdx;

    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else
    {
        keyIdIdx = Csm_GetKeyIdIdx(keyId);
        if( CSM_INVALID_IDX_U32 != keyIdIdx )
        {
            retVal = CryIf_KeyGenerate(csmKey[keyIdIdx].Keyref);
        }
        else
        {
            errorId = CSM_E_PARAM_HANDLE;
            retVal = CRYPTO_E_KEY_NOT_VALID;
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_KEYGENERATE, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_KeyDerive
*
* Explanation: Derives a new key by using the key elements in the given key
*              identified by the keyId.
*              The given key contains the key elements for the password and salt.
*              The derived key is stored in the key element with the id 1 of the key
*              identified by targetCryptoKeyId.
*
* Parameters(in): keyId: Holds the identifier of the key which is used for key derivation.
*                 targetKeyId: Holds the identifier of the key which is used to store the
*                              derived key.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is busy
*                         CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to
*                                                 extract key element
*                         CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to
*                                                  write key element
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element
*                                                     sizes are not compatible
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyDerive
(
    uint32 keyId,
    uint32 targetKeyId
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 keyIdIdx1;
    uint32 keyIdIdx2;

    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else
    {
        keyIdIdx1 = Csm_GetKeyIdIdx(keyId);
        keyIdIdx2 = Csm_GetKeyIdIdx(targetKeyId);
        if( (CSM_INVALID_IDX_U32 != keyIdIdx1) && (CSM_INVALID_IDX_U32 != keyIdIdx2) )
        {
            retVal = CryIf_KeyDerive(csmKey[keyIdIdx1].Keyref, csmKey[keyIdIdx2].Keyref);
        }
        else
        {
            errorId = CSM_E_PARAM_HANDLE;
            retVal = CRYPTO_E_KEY_NOT_VALID;
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_KEYDERIVE, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_KeyExchangeCalcPubVal
*
* Explanation: Calculates the public value of the current user for the key exchange
*              and stores the public key in the memory location pointed by the public
*              value pointer.
*
* Parameters(in): keyId: Holds the identifier of the key which shall be used for
*                 the key exchange protocol.
*
* Parameters(inout): publicValueLengthPtr: Holds a pointer to the memory location in
*                    which the public value length information is stored. On calling
*                    this function, this parameter shall contain the size of the buffer
*                    provided by publicValuePtr. When the request has finished, the actual
*                    length of the returned value shall be stored.
*
* Parameters(out): publicValuePtr: Contains the pointer to the data where the public value
*                                  shall be stored.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is
*                                        busy
*                         CRYPTO_E_SMALL_BUFFER: The provided buffer is too small
*                                                to store the result
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyExchangeCalcPubVal
(
    uint32 keyId,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) publicValuePtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) publicValueLengthPtr
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 keyIdIdx;

    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( (NULL_PTR == publicValuePtr) || (NULL_PTR == publicValueLengthPtr) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        keyIdIdx = Csm_GetKeyIdIdx(keyId);
        if( CSM_INVALID_IDX_U32 != keyIdIdx )
        {
            retVal = CryIf_KeyExchangeCalcPubVal(csmKey[keyIdIdx].Keyref, publicValuePtr, publicValueLengthPtr);
        }
        else
        {
            errorId = CSM_E_PARAM_HANDLE;
            retVal = CRYPTO_E_KEY_NOT_VALID;
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_KEYEXCHANGECALCPUBVAL, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;

}
/*
********************************************************************************
* Function Name: Csm_KeyExchangeCalcSecret
*
* Explanation: Calculates the public value of the current user for the key exchange
*              and stores the public key in the memory location pointed by the public
*              value pointer.
*
* Parameters(in): keyId: Holds the identifier of the key which shall be used for
*                        the key exchange protocol.
*
* Parameters(in): partnerPublicValuePtr: Holds the pointer to the memory location
*                                        which contains the partner's public value.
*
* Parameters(in): partnerPublicValueLength: Contains the length of the partner's public
*                                           value in bytes.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is
*                                        busy
*                         CRYPTO_E_SMALL_BUFFER: The provided buffer is too small
*                                                to store the result
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyExchangeCalcSecret
(
    uint32 keyId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) partnerPublicValuePtr,
    uint32 partnerPublicValueLength
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 keyIdIdx;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( NULL_PTR == partnerPublicValuePtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        keyIdIdx = Csm_GetKeyIdIdx(keyId);
        if( keyIdIdx != CSM_INVALID_IDX_U32 )
        {
            retVal = CryIf_KeyExchangeCalcSecret(csmKey[keyIdIdx].Keyref, partnerPublicValuePtr, partnerPublicValueLength);
        }
        else
        {
            errorId = CSM_E_PARAM_HANDLE;
            retVal = CRYPTO_E_KEY_NOT_VALID;
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_KEYEXCHANGECALCSECRET, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;

}

/*
********************************************************************************
* Function Name: Csm_CertificateParse
*
* Explanation: Calculates the public value of the current user for the key exchange
*              and stores the public key in the memory location pointed by the public
*              value pointer.
*
* Parameters(in): keyId: Holds the identifier of the key which shall be used for the
*                        key exchange protocol.
*
* Parameters(inout): publicValueLengthPtr: Holds a pointer to the memory location in
*                                          which the public value length information is
*                                          stored. On calling this function, this parameter
*                                          shall contain the size of the buffer provided by
*                                          publicValuePtr. When the request has finished,
*                                          the actual length of the returned value shall be
*                                          stored.
*
* Parameters(out): publicValuePtr: Contains the pointer to the data where the public
*                                  value shall be stored.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is
*                                        busy
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_CertificateParse
(

    CONST(uint32, CSM_CONST) keyId
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 keyIdIdx;

    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else
    {
        keyIdIdx = Csm_GetKeyIdIdx(keyId);
        if( CSM_INVALID_IDX_U32 != keyIdIdx )
        {
            retVal = CryIf_CertificateParse(csmKey[keyIdIdx].Keyref);
        }
        else
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_CERTIFICATEPARSE, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;

}

/*
********************************************************************************
* Function Name: Csm_CertificateVerify
*
* Explanation: Verifies the certificate stored in the key referenced by verifyKeyId
*              with the certificate stored in the key referenced by keyId.
*
* Parameters(in): keyId: Holds the identifier of the key which shall be used to
*                        validate the certificate.
*                 verifyCryptoKeyId: Holds the identifier of the key containing the
*                                    certificate to be verified.
*
* Parameters(out): verifyPtr: Holds a pointer to the memory location which will
*                             contain the result of the certificate verification.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is
*                                        busy
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_CertificateVerify
(
    CONST(uint32, CSM_CONST) keyId,
    CONST(uint32, CSM_CONST) verifyCryptoKeyId,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) verifyPtr
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 keyIdIdx1;
    uint32 keyIdIdx2;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( NULL_PTR == verifyPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        keyIdIdx1 = Csm_GetKeyIdIdx(keyId);
        keyIdIdx2 = Csm_GetKeyIdIdx(verifyCryptoKeyId);
        if( (CSM_INVALID_IDX_U32 != keyIdIdx1) && (CSM_INVALID_IDX_U32 != keyIdIdx2) )
        {
            retVal = CryIf_CertificateVerify(csmKey[keyIdIdx1].Keyref, csmKey[keyIdIdx2].Keyref, verifyPtr);
        }
        else
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_CERTIFICATEVERIFY, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;

}

/*
********************************************************************************
* Function Name: Csm_JobKeySetValid
*
* Explanation: Stores the key if necessary and sets the key state of the key
*              identified by keyId to valid.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 keyId: Holds the identifier of the key for which a new material
*                        shall be validated.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is
*                                        busy
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_JobKeySetValid
(
    uint32 jobId,
    uint32 keyId
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 jobIdIdx;
    uint32 keyIdIdx;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            keyIdIdx = Csm_GetKeyIdIdx(keyId);
            if( CSM_INVALID_IDX_U32 == keyIdIdx )
            {
                errorId = CSM_E_PARAM_HANDLE;
            }
            else
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.cryIfKeyId = csmKey[keyIdIdx].Keyref;
                if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
                retVal = Csm_ProcessJob(CSM_SID_JOBKEYSETVALID, jobIdIdx, CRYPTO_KEYSETVALID);
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_JOBKEYSETVALID, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_JobRandomSeed
*
* Explanation: This function shall dispatch the random seed function to the
*              configured crypto driver object.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 keyId: Holds the identifier of the key for which a new material
*                        shall be validated.
*                 seedPtr: Holds a pointer to the memory location which contains
*                          the data to feed the seed.
*                 seedLength: Contains the length of the seed in bytes.
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is
*                                        busy
*                         CRYPTO_E_QUEUE_FULL: Request failed, the queue is full
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_JobRandomSeed
(
    uint32 jobId,
    uint32 keyId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) seedPtr,
    uint32  seedLength
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 jobIdIdx;
    uint32 keyIdIdx;

    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( NULL_PTR == seedPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            keyIdIdx = Csm_GetKeyIdIdx(keyId);
            if( CSM_INVALID_IDX_U32 == keyIdIdx )
            {
                errorId = CSM_E_PARAM_HANDLE;
            }
            else
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.cryIfKeyId = csmKey[keyIdIdx].Keyref;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputPtr = seedPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputLength = seedLength;
               if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
               {
                   Csm_ProcessJobRedirection(jobIdIdx);
               }
               retVal = Csm_ProcessJob(CSM_SID_JOBRANDOMSEED, jobIdIdx, CRYPTO_RANDOMSEED);
           }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_JOBRANDOMSEED, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_JobKeyGenerate
*
* Explanation: Generates new key material and stores it in the key identified by
*              keyId.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 keyId: Holds the identifier of the key for which a new material
*                        shall be validated.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, Crypto Driver Object
*                                        is busy
*                         CRYPTO_E_QUEUE_FULL: Request failed, the queue is full
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_JobKeyGenerate
(
    uint32 jobId,
    uint32 keyId
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 jobIdIdx;
    uint32 keyIdIdx;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            keyIdIdx = Csm_GetKeyIdIdx(keyId);
            if( CSM_INVALID_IDX_U32 == keyIdIdx )
            {
                errorId = CSM_E_PARAM_HANDLE;
                retVal = CRYPTO_E_KEY_NOT_VALID;
            }
            else
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.cryIfKeyId = csmKey[keyIdIdx].Keyref;
                if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
                retVal = Csm_ProcessJob(CSM_SID_JOBKEYGENERATE, jobIdIdx, CRYPTO_KEYGENERATE);
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_JOBKEYGENERATE, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_JobKeyDerive
*
* Explanation: Derives a new key by using the key elements in the given key
*              identified by the keyId. The given key contains the key elements
*              for the password and salt. The derived key is stored in the key
*              element with the id 1 of the key identified by targetCryptoKeyId.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 keyId: Holds the identifier of the key which is used for key
*                        derivation.
*                 targetKeyId: Holds the identifier of the key which is used to
*                              store the derived key.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is
*                                        busy
*                         CRYPTO_E_QUEUE_FULL: Request failed, the queue is full
*                         CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to
*                                                 extract key element
*                         CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to
*                                                  write key element
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element
*                                                     sizes are not compatible
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_JobKeyDerive
(
    uint32 jobId,
    uint32 keyId,
    uint32 targetKeyId
)
{
        /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 jobIdIdx;
    uint32 keyIdIdx;
    uint32 targetKeyIdIdx;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            keyIdIdx = Csm_GetKeyIdIdx(keyId);
            targetKeyIdIdx = Csm_GetKeyIdIdx(targetKeyId);
            if( (CSM_INVALID_IDX_U32 == keyIdIdx) || (CSM_INVALID_IDX_U32 == targetKeyIdIdx) )
            {
                errorId = CSM_E_PARAM_HANDLE;
                retVal = CRYPTO_E_KEY_NOT_VALID;
            }
            else
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.cryIfKeyId = csmKey[keyIdIdx].Keyref;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.targetCryIfKeyId = csmKey[targetKeyIdIdx].Keyref;
                if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
                retVal = Csm_ProcessJob(CSM_SID_JOBKEYDERIVE, jobIdIdx, CRYPTO_KEYDERIVE);
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_JOBKEYDERIVE, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_JobKeyExchangeCalcPubVal
*
* Explanation: Calculates the public value of the current user for the key
*              exchange and stores the public key in the memory location pointed
*              by the public value pointer.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 keyId: Holds the identifier of the key which shall be used for
*                        the key exchange protocol.
*
* Parameters(inout): publicValueLengthPtr: Holds a pointer to the memory location
*                    in which the public value length information is stored. On
*                    calling this function, this parameter shall contain the size
*                    of the buffer provided by publicValuePtr. When the request
*                    has finished, the actual length of the returned value shall
*                    be stored.
*
* Parameters (out): publicValuePtr: Contains the pointer to the data where the
*                                   public value shall be stored.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, Crypto Driver Object
*                                        is busy
*                         CRYPTO_E_QUEUE_FULL: Request failed, the queue is full
*                         CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to
*                                                 extract key element
*                         CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to
*                                                  write key element
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element
*                                                     sizes are not compatible
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_JobKeyExchangeCalcPubVal
(
    uint32 jobId,
    uint32 keyId,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) publicValuePtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) publicValueLengthPtr
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 jobIdIdx;
    uint32 keyIdIdx;

    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( (NULL_PTR == publicValuePtr) || (NULL_PTR == publicValueLengthPtr) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            keyIdIdx = Csm_GetKeyIdIdx(keyId);
            if( CSM_INVALID_IDX_U32 == keyIdIdx )
            {
                errorId = CSM_E_PARAM_HANDLE;
            }
            else
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.cryIfKeyId = csmKey[keyIdIdx].Keyref;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputPtr = publicValuePtr;
                /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_Csm_Dir4.14 " */
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputLength = *publicValueLengthPtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.outputLengthPtr = publicValueLengthPtr;
                if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
                retVal = Csm_ProcessJob(CSM_SID_JOBKEYEXCHANGECALCPUBVAL, jobIdIdx, CRYPTO_KEYEXCHANGECALCPUBVAL);
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_JOBKEYEXCHANGECALCPUBVAL, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_JobKeyExchangeCalcSecret
*
* Explanation: Calculates the shared secret key for the key exchange with the
*              key material of the key identified by the keyId and the partner
*              public key. The shared secret key is stored as a key element in
*              the same key.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 keyId: Holds the identifier of the key which shall be used for
*                        the key exchange protocol.
*                 partnerPublicValuePtr: Holds the pointer to the memory
*                           location which contains the partner's public value.
*                 partnerPublicValueLength: Contains the length of the partner's
*                           public value in bytes.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is
*                                        busy
*                         CRYPTO_E_SMALL_BUFFER: The provided buffer is too small
*                                                to store the result
*                         CRYPTO_E_QUEUE_FULL: Request failed, the queue is full
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_JobKeyExchangeCalcSecret
(
    uint32 jobId,
    uint32 keyId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) partnerPublicValuePtr,
    uint32 partnerPublicValueLength
)
{
        /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 jobIdIdx;
    uint32 keyIdIdx;

    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( NULL_PTR == partnerPublicValuePtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            keyIdIdx = Csm_GetKeyIdIdx(keyId);
            if( CSM_INVALID_IDX_U32 == keyIdIdx )
            {
                errorId = CSM_E_PARAM_HANDLE;
            }
            else
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.cryIfKeyId = csmKey[keyIdIdx].Keyref;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputPtr = partnerPublicValuePtr;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.inputLength = partnerPublicValueLength;
                if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
                retVal = Csm_ProcessJob(CSM_SID_JOBKEYEXCHANGECALCSECRET, jobIdIdx, CRYPTO_KEYEXCHANGECALCSECRET);
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_JOBKEYEXCHANGECALCSECRET, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_JobCertificateParse
*
* Explanation: This function shall dispatch the certificate parse function to
*              the CRYIF.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 keyId: Holds the identifier of the key to be used for the
*                 certificate parsing.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, Crypto Driver Object
*                                        is busy
*                         CRYPTO_E_QUEUE_FULL: Request failed, the queue is full
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_JobCertificateParse
(
    uint32 jobId,
    uint32 keyId
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 jobIdIdx;
    uint32 keyIdIdx;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            keyIdIdx = Csm_GetKeyIdIdx(keyId);
            if( CSM_INVALID_IDX_U32 == keyIdIdx )
            {
                errorId = CSM_E_PARAM_HANDLE;
            }
            else
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.cryIfKeyId = csmKey[keyIdIdx].Keyref;
                if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
                retVal = Csm_ProcessJob(CSM_SID_JOBCERTIFICATEPARSE, jobIdIdx, CRYPTO_CERTIFICATEPARSE);
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_JOBCERTIFICATEPARSE, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_JobCertificateVerify
*
* Explanation: This function shall dispatch the certificate parse function to
*              the CRYIF.
*
* Parameters(in): jobId: Holds the identifier of the job using the CSM service.
*                 keyId: Holds the identifier of the key which shall be used to
*                   validate the certificate.
*                 verifyKeyId: Holds the identifier of the key containing the
*                   certificate to be verified.
*
* Parameters(out): verifyPtr: Holds a pointer to the memory location which will
*                   contain the result of the certificate verification.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is busy
*                         CRYPTO_E_QUEUE_FULL: Request failed, the queue is full
*                         CRYPTO_E_KEY_NOT_VALID: Request failed, the key's state
*                                                 is "invalid"
*                         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized
*                                             source key element
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_JobCertificateVerify
(
    CONST(uint32, CSM_CONST) jobId,
    CONST(uint32, CSM_CONST) keyId,
    CONST(uint32, CSM_CONST) verifyKeyId,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) verifyPtr
)
{
        /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 jobIdIdx;
    uint32 keyIdIdx;
    uint32 verifyKeyIdIdx;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else if( NULL_PTR == verifyPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        jobIdIdx = Csm_GetJobIdIdx(jobId);
        if( CSM_INVALID_IDX_U32 == jobIdIdx )
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
        else
        {
            keyIdIdx = Csm_GetKeyIdIdx(keyId);
            verifyKeyIdIdx = Csm_GetKeyIdIdx(verifyKeyId);
            if( (CSM_INVALID_IDX_U32 == keyIdIdx) || (CSM_INVALID_IDX_U32 == verifyKeyIdIdx) )
            {
                errorId = CSM_E_PARAM_HANDLE;
            }
            else
            {
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.cryIfKeyId = csmKey[keyIdIdx].Keyref;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.targetCryIfKeyId = verifyKeyIdIdx;
                cryptoJob[jobIdIdx]->jobPrimitiveInputOutput.verifyPtr = verifyPtr;
                if( NULL_PTR != cryptoJob[jobIdIdx]->jobRedirectionInfoRef )
                {
                    Csm_ProcessJobRedirection(jobIdIdx);
                }
                retVal = Csm_ProcessJob(CSM_SID_JOBCERTIFICATEVERIFY, jobIdIdx, CRYPTO_CERTIFICATEVERIFY);
            }
        }
    }
        /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
   if( CSM_E_NO_ERROR != errorId )
   {
       (void)CSM_REPORT_DEV_ERROR(CSM_SID_JOBCERTIFICATEVERIFY, errorId);
   }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: Csm_CallbackNotification
*
* Explanation: Cancels the job processing from asynchronous or streaming jobs.
*
* Parameters(in): job: Holds a pointer to the job, which has finished.
*                 result: Contains the result of the cryptographic operation.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_JOB_CANCELED: Immediate cancelation not possible.
*                                                The cancelation will be done at
*                                                next suitable processing step and
*                                                notified via a negative finish
*                                                callback.
********************************************************************************
*/
FUNC(void, CSM_CODE) Csm_CallbackNotification
(
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_DATA) job,
    Csm_ResultType result
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    uint32 JobIdIdx;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_UNINIT;
    }
    else if( NULL_PTR == job )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CSM_E_PARAM_POINTER;
    }
    else
    {
        JobIdIdx = Csm_GetJobIdIdx(job->jobId);
        if( CSM_INVALID_IDX_U32 != JobIdIdx )
        {
            if( (uint8)CRYPTO_USE_PORT_OPTIMIZED == (uint8)csmJobConfig[JobIdIdx].JobInterfaceUsePort )
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                if( ((uint8)CRYPTO_OPERATIONMODE_FINISH == ((uint8)CRYPTO_OPERATIONMODE_FINISH & (uint8)job->jobPrimitiveInputOutput.mode))
                    && ((uint8)CRYPTO_PROCESSING_ASYNC == (uint8)cryptoJob[JobIdIdx]->jobPrimitiveInfo->processingType) )
                {
                    if( csmJobCbkService[JobIdIdx] != NULL_PTR )
                    {
                        csmJobCbkService[JobIdIdx](job, result);
                    }
                    else
                    {
                        /* Nothing */
                    }
                }
            }
            else
            {
                /* Polyspace +5 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
                /* Polyspace +4 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
                /* Polyspace +3 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
                /* Polyspace +2 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
                if( ((uint8)CRYPTO_OPERATIONMODE_UPDATE == ((uint8)CRYPTO_OPERATIONMODE_UPDATE & (uint8)job->jobPrimitiveInputOutput.mode))
                    && (TRUE == job->jobPrimitiveInfo->callbackUpdateNotification) )
                {
                    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    if( NULL_PTR != csmJobConfig[JobIdIdx].JobPrimitiveCallbackRef )
                    {
                        csmJobConfig[JobIdIdx].JobPrimitiveCallbackRef(job, result);
                    }
                }
                else if( (uint8)CRYPTO_OPERATIONMODE_FINISH == ((uint8)CRYPTO_OPERATIONMODE_FINISH & (uint8)job->jobPrimitiveInputOutput.mode) )
                {
                    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    if( NULL_PTR != csmJobConfig[JobIdIdx].JobPrimitiveCallbackRef )
                    {
                        csmJobConfig[JobIdIdx].JobPrimitiveCallbackRef(job, result);
                    }
                }
                else
                {
                    /* Nothing */
                }
            }
        }
        else
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_CANCELJOB, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

}

/*
********************************************************************************
* Function Name: Csm_CancelJob
*
* Explanation: Cancels the job processing from asynchronous or streaming jobs.
*
* Parameters(in): job: Holds the identifier of the job to be canceled
*                 mode: Not used, just for interface compatibility provided.
*
* retval: Std_ReturnType: E_OK: Request successful
*                         E_NOT_OK: Request failed
*                         CRYPTO_E_JOB_CANCELED: Immediate cancelation not possible.
*                                                The cancelation will be done at
*                                                next suitable processing step and
*                                                notified via a negative finish
*                                                callback.
********************************************************************************
*/
FUNC(Std_ReturnType ,CSM_CODE) Csm_CancelJob
(
    uint32 job,
    Crypto_OperationModeType mode
)
{
    /* Local Variables */
    uint8 errorId = CSM_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 JobIdIdx;
    /* Check module init */
    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else
    {
        JobIdIdx = Csm_GetJobIdIdx(job);
        CSM_DUMMY_STATEMENT(mode);
        if( CSM_INVALID_IDX_U32 != JobIdIdx )
        {
            /* Polyspace +4 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
            /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
            /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
            /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
            if( CRYPTO_PROCESSING_SYNC == cryptoJob[JobIdIdx]->jobPrimitiveInfo->processingType )
            {
                errorId = CSM_E_PROCESSING_MODE;
            }
            else
            {
                retVal = CryIf_CancelJob(csmJobQueue[csmJobConfig[JobIdIdx].JobQueueRef]->u32ChannelRef,cryptoJob[JobIdIdx]);
                if( E_OK == retVal )
                {
                    Csm_CallbackNotification(cryptoJob[JobIdIdx], E_JOB_CANCELED);
                }
                retVal = Csm_Util_DequeueJob(csmJobConfig[JobIdIdx].JobQueueRef, cryptoJob[JobIdIdx]->jobInfo);
            }
        }
        else
        {
            errorId = CSM_E_PARAM_HANDLE;
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_CANCELJOB, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

    return retVal;

}

/*
********************************************************************************
* Function Name: Csm_MainFunction
*
* Explanation: API to be called cyclically to process the requested jobs.
*              The Csm_MainFunction shall check the queues for jobs to
*              pass to the underlying CRYIF.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void ,CSM_CODE) Csm_MainFunction(void)
{
    uint8 errorId = CSM_E_NO_ERROR;
    Csm_ResultType retVal;
    uint32 queueIdx = CSM_ZERO;
    uint32 num;
    Crypto_JobType* job;

    if( CSM_INITIALIZED != Csm_ModuleInitState )
    {
        errorId = CSM_E_UNINIT;
    }
    else
    {
        for( num = CSM_ZERO; num < CSM_NUMBER_OF_QUEUES; num ++ )
        {
            if( CSM_JOB_QUEUE_NONE_U32 != csmJobQueue[num]->u32HeadOfQueuedJobs )
            {
                /* process job */
                queueIdx = csmJobQueue[num]->u32HeadOfQueuedJobs;
                job = &(csmJobQueue[num]->pQueuedJobs[queueIdx].job);
                retVal = CryIf_ProcessJob(csmJobQueue[num]->u32ChannelRef, job);
                if( E_OK == retVal )
                {
                    Csm_Util_DequeueHeadJob(num);
                }
            }
        }
    }
    /* Dev error report */
#if( CSM_DEV_ERROR_DETECT == STD_ON )
    if( CSM_E_NO_ERROR != errorId )
    {
        (void)CSM_REPORT_DEV_ERROR(CSM_SID_MAINFUNCTION, errorId);
    }
#else
    CSM_DUMMY_STATEMENT(errorId);
#endif /* CSM_DEV_ERROR_DETECT */

}

/*
********************************************************************************
* Function Name: Csm_LocalInitJobs
*
* Explanation: Init jobs.
*
* param: job: the job number to be initalized.
*
* retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, CSM_CODE) Csm_LocalInitJobs
(
    uint32 num
)
{
    cryptoJob[num]->jobState = CRYPTO_JOBSTATE_IDLE;

    cryptoJob[num]->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_IDLE;
    cryptoJob[num]->jobPrimitiveInputOutput.inputPtr = NULL_PTR;
    cryptoJob[num]->jobPrimitiveInputOutput.output64Ptr = NULL_PTR;
    cryptoJob[num]->jobPrimitiveInputOutput.outputLengthPtr = NULL_PTR;
    cryptoJob[num]->jobPrimitiveInputOutput.secondaryInputPtr = NULL_PTR;
    cryptoJob[num]->jobPrimitiveInputOutput.secondaryOutputPtr = NULL_PTR;
    cryptoJob[num]->jobPrimitiveInputOutput.secondaryOutputLengthPtr = NULL_PTR;
    cryptoJob[num]->jobPrimitiveInputOutput.tertiaryInputPtr = NULL_PTR;
    cryptoJob[num]->jobPrimitiveInputOutput.verifyPtr = NULL_PTR;
    cryptoJob[num]->jobPrimitiveInputOutput.output64Ptr = NULL_PTR;

    cryptoJob[num]->jobPrimitiveInputOutput.cryIfKeyId = CSM_INVALID_IDX_U32;
    cryptoJob[num]->jobPrimitiveInputOutput.targetCryIfKeyId = CSM_INVALID_IDX_U32;
    cryptoJob[num]->jobPrimitiveInputOutput.inputLength = CSM_ZERO;
    cryptoJob[num]->jobPrimitiveInputOutput.secondaryInputLength = CSM_ZERO;
    cryptoJob[num]->jobPrimitiveInputOutput.tertiaryInputLength = CSM_ZERO;
    cryptoJob[num]->jobPrimitiveInputOutput.input64 = CSM_ZERO;

}

/*
********************************************************************************
* Function Name: Csm_GetJobIdIdx
*
* Explanation: Get JobIdx by JobId
*
* param: u32JobId: Job Id
*
* retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(uint32, CSM_CODE) Csm_GetJobIdIdx
(
    uint32 u32JobId
)
{
    uint32 u32RetVal = CSM_INVALID_IDX_U32;
    uint32 u32Counter;

    for( u32Counter = 0U; u32Counter < CSM_NUMBER_OF_JOBS; u32Counter++)
    {
        if (u32JobId == cryptoJob[u32Counter]->jobId)
        {
            u32RetVal = u32Counter;
            break;
        }
    }
    return u32RetVal;
}
/*
********************************************************************************
* Function Name: Csm_GetKeyIdIdx
*
* Explanation: Get KeyIdx by KeyId
*
* param: u32JobId: Key Id
*
* retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(uint32, CSM_CODE) Csm_GetKeyIdIdx
(
    uint32 u32KeyId
)
{
    uint32 u32RetVal = CSM_INVALID_IDX_U32;
    uint32 u32Counter;

    for( u32Counter = 0U; u32Counter < CSM_NUMBER_OF_KEYS; u32Counter++)
    {
        if (u32KeyId == csmKey[u32Counter].KeyId)
        {
            u32RetVal = u32Counter;
            break;
        }
    }
    return u32RetVal;
}

#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

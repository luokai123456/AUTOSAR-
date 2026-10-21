/*
********************************************************************************
*
*  File name: CryIf.c
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
*  Version: 3.0
*  Author/Date: jia_feng/2020.07.02
*  Change: New created.
*  Cause: New
********************************************************************************
*  Version: 3.1
*  Author/Date: jia_feng/2020.09.10
*  Change: Add MemMap.
*  Cause: Optimization
********************************************************************************
*  Version: 3.2
*  Author/Date: jia_feng/2020.10.12
*  Change: Modify the function of redirection, optimize code structure.
*  Cause: Optimization
********************************************************************************
*  Version: 3.3
*  Author/Date: jia_feng/2020.10.13
*  Change: Delete some conflicting requirements code in CryIf_ProcessJob.
*  Cause: Optimization
********************************************************************************
*  Version: 3.4
*  Author/Date: guoziyang/2020.10.27
*  Change: Modify the code according to the AUTOSAR specification.
*  Cause: Optimization
********************************************************************************
*  Version: 3.5
*  Author/Date: jia_feng/2020.11.09
*  Change: Modify the judge of init in CryIf_GetVersionInfo.
*  Cause: Optimization
********************************************************************************
*  Version: 3.6
*  Author/Date: JiaF/2020.11.23
*  Change: Modify the call of CancelJob, Modify compile warning in IAR.
*  Cause: Optimization
********************************************************************************
*  Version: 3.7
*  Author/Date: JiaF/2021.01.27
*  Change: Function CryIf_KeyElementCopyPartialOfDifferentDrivers,
*          Modify (keyElementSourceOffset + keyElementCopyLength) to
*          keyElementCopyLength in CryIf_MemCpy.
*  Cause: Optimization
********************************************************************************
*  Version: 3.8
*  Author/Date: JiaF/2021.03.03
*  Change: Modify the high level warnings of PolySpace about returns of
*          CryIf_GetKeyObjectDriverIdx.
*  Cause: Optimization
********************************************************************************
*  Version: 3.9
*  Author/Date: ZhangY/2021.10.25
*  Change: CryIf_GetObjectId、CryIf_GetObjectDriverIdx、CryIf_GetCryptoKeyId、
*           CryIf_GetKeyObjectDriverIdx,add break.
*  Cause: Optimization
********************************************************************************
*  Version: 3.10
*  Author/Date: ZhangY/2021.11.10
*  Change: In function CryIf_GetCryptoKeyId CryIf_GetKeyObjectDriverIdx,
*           use CRYIF_NUMBER_OF_KEY as loop condition.
*  Cause: Bugfix
********************************************************************************
*  Version: 3.11
*  Author/Date: NiXM/2022.12.21
*  Change: In function CryIf_GetObjectDriverIdx and CryIf_GetKeyObjectDriverIdx,
*           use CryptoChannelIdx and CryptoKeyIdx instead of ObjectDriverIdx.
*  Cause: Bugfix
********************************************************************************
*  Version: 3.12
*  Author/Date: NiXM/2023.02.03
*  Change: Modify codes due to coding standards.
*  Cause: Optimization
********************************************************************************
*  Version: 3.13
*  Author/Date: MengY/2024.04.02
*  Change: Modify the ptrclass of P2VAR.
*  Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date: MengY/2024.05.08
* Change: Add memmap section for function declaration.
* Cause: Optimization.
********************************************************************************
* Version: 3.15
* Author/Date: MengY/2024.10.11
* Change: Modify the CSM_CODE to CRYIF_CODE for function.
* Cause: Optimization.
********************************************************************************
* Version: 3.16
* Author/Date: ZhangXL/2025.03.31
* Change: Fix QAC and Polyspace warnings and add analysis results.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: LiK/2025.5.26
* Change: Add polyspace Warning inhibition comment.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: LiK/2025.5.26
* Change: Modify polyspace Warning inhibition comment.
* Cause: Optimization
********************************************************************************
* Version: 3.19
* Author/Date: LiSK/2025.7.15
* Change: Modify polyspace Warning inhibition comment for #273063.
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CryIf.h"
#include "CryIf_Cbk.h"

#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
#define CRYIF_REPORT_DEV_ERROR(SID, ERROR)     \
        ((void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, (SID), (ERROR)))
#define CRYIF_REPORTRUNTIME_DEV_ERROR(SID, ERROR)     \
        ((void)Det_ReportRuntimeError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID, (SID), (ERROR)))
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
#define CRYIF_START_SEC_VAR_INIT
//wjc:CryIf_MemMap.h

/* Initialization state with Uninitialized. */
/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_CryIf_Unreasonablevariable" */
static VAR(CryIf_InitStatusType, CRYIF_VAR_INIT) CryIf_ModuleInitState = CRYIF_UNINITIALIZED;

#define CRYIF_STOP_SEC_VAR_INIT
//wjc:CryIf_MemMap.h /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define CRYIF_START_SEC_CODE
//wjc:CryIf_MemMap.h /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
LOCAL_INLINE FUNC(uint32 ,CRYIF_CODE) CryIf_GetObjectId(uint32 channelId);
LOCAL_INLINE FUNC(uint32 ,CRYIF_CODE) CryIf_GetObjectDriverIdx(uint32 channelId);
LOCAL_INLINE FUNC(uint32 ,CRYIF_CODE) CryIf_GetCryptoKeyId(uint32 cryIfKeyId);
LOCAL_INLINE FUNC(uint32 ,CRYIF_CODE) CryIf_GetKeyObjectDriverIdx(uint32 cryptoKeyId);
#define CRYIF_STOP_SEC_CODE
//wjc:CryIf_MemMap.h /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
********************************************************************************
*    Global Variable
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/

#define CRYIF_START_SEC_CODE
//wjc:CryIf_MemMap.h /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
********************************************************************************
* Function Name: CryIf_Init
*
* Explanation: Initializes the CryIf module.
*
* param: CryIf_ConfigType: Pointer to a selected configuration structure.
*
* retval: None
********************************************************************************
*/
FUNC(void, CRYIF_CODE) CryIf_Init
(
    P2CONST(CryIf_ConfigType, AUTOMATIC, CRYIF_APPL_CONST) configPtr
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;

    CRYIF_DUMMY_STATEMENT(configPtr);
    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        CryIf_ModuleInitState = CRYIF_INITIALIZED;
    }
    else
    {
        errorId = CRYIF_E_INIT_FAILED;
    }

#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_INIT, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

}

#if( CRYIF_VERSION_INFO_API == STD_ON )
/*
********************************************************************************
* Function Name: CryIf_GetVersionInfo
*
* Explanation: Returns the version information of this module.
*
* param: versioninfo: Pointer to where to store the version information of this
*                     module.
*
* retval: None
********************************************************************************
*/
FUNC(void ,CRYIF_CODE) CryIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CRYIF_APPL_DATA) versioninfo
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;

    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check whether pointer parameter is null pointer. */
    else if( NULL_PTR == versioninfo )
    {
        errorId = CRYIF_E_PARAM_POINTER;
    }
    else
    {
        /*  Return vendor ID, module ID and version data */
        /* Polyspace +1 MISRA-C3:D4.14 [JUstified:Unset] " NSCA_Polyspace_CryIf_Dir4.14 " */
        versioninfo->vendorID = (uint16)CRYIF_VENDOR_ID;
        versioninfo->moduleID = (uint16)CRYIF_MODULE_ID;

        versioninfo->sw_major_version = (uint8)CRYIF_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)CRYIF_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)CRYIF_SW_PATCH_VERSION;
    }

    /* Dev error report */
#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_GETVERSIONINFO, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */
}
#endif /* CRYIF_VERSION_INFO_API == STD_ON */

/*
********************************************************************************
* Function Name: CryIf_ProcessJobRedirection
*
* Explanation: Process inout redirection.
*
* Parameters(in): job: Job to be redireciton.
*
* retval: None
********************************************************************************
*/

static FUNC(void ,CRYIF_CODE) CryIf_ProcessJobRedirection
(
    P2VAR(Crypto_JobType, AUTOMATIC, CRYIF_APPL_DATA) job
)
{
    if( (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT == (job->jobRedirectionInfoRef->redirectionConfig & (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT) )
    {
        job->jobRedirectionInfoRef->inputKeyId = CryIf_GetCryptoKeyId(job->jobRedirectionInfoRef->inputKeyId);
    }
    if( (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT == (job->jobRedirectionInfoRef->redirectionConfig & (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT) )
    {
        job->jobRedirectionInfoRef->secondaryInputKeyId = CryIf_GetCryptoKeyId(job->jobRedirectionInfoRef->secondaryInputKeyId);
    }
    if( (uint8)CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT == (job->jobRedirectionInfoRef->redirectionConfig & (uint8)CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT) )
    {
        job->jobRedirectionInfoRef->tertiaryInputKeyId = CryIf_GetCryptoKeyId(job->jobRedirectionInfoRef->tertiaryInputKeyId);
    }
    if( (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT == (job->jobRedirectionInfoRef->redirectionConfig & (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT) )
    {
        job->jobRedirectionInfoRef->outputKeyId = CryIf_GetCryptoKeyId(job->jobRedirectionInfoRef->outputKeyId);
    }
    if( (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT == (job->jobRedirectionInfoRef->redirectionConfig & (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT) )
    {
        job->jobRedirectionInfoRef->secondaryOutputKeyId = CryIf_GetCryptoKeyId(job->jobRedirectionInfoRef->secondaryOutputKeyId);
    }
}

/*
********************************************************************************
* Function Name: CryIf_ProcessJob
*
* Explanation: This interface dispatches the received jobs to the configured
*              crypto driver object.
*
* param: channelId: Holds the identifier of the crypto channel.
*        job: Pointer to the configuration of the job. Contains structures with
*             user and primitive relevant information.
*
* retval: E_OK: Request successful
*         E_NOT_OK: Request failed
*         CYPTO_E_BUSY: Request failed, Crypro Driver Object is busy
*         CRYPTO_E_KEY_NOT_VALID: Request failed, the key is not valid
*         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, a key element has the
*                                     wrong size
*         CRYPTO_E_QUEUE_FULL: Request failed, the queue is full
*         CRYPTO_E_KEY_READ_FAIL: The service request failed, because key
*                                 element extraction is not allowed
*         CRYPTO_E_KEY_WRITE_FAIL: The service request failed because the
*                                  writing access failed
*         CRYPTO_E_KEY_NOT_AVAILABLE: The service request failed because the key
*                                     is not available
*         CRYPTO_E_SMALL_BUFFER: The provided buffer is too small to store the
*                                result
*         CRYPTO_E_JOB_CANCELED: The service request failed because the
*                                synchronous Job has been canceled
*         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key
*                             element
********************************************************************************
*/
FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_ProcessJob
(
    uint32 channelId,
    P2VAR(Crypto_JobType, AUTOMATIC, CRYIF_APPL_DATA) job
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    uint8 retVal  = E_NOT_OK;
    uint32 objectId;
    uint32 objectDriverIdx;
    uint32 cryptoKeyId;
    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check if ID is out of range. */
    else if( CRYIF_INVALID_ID == CryIf_GetObjectId(channelId) )
    {
        errorId = CRYIF_E_PARAM_HANDLE;
    }
    /* Check whether pointer parameter is null pointer. */
    else if( NULL_PTR == job )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CRYIF_E_PARAM_POINTER;
    }
    else
    {   /* job processing redirection is used. */
        /* [SWS_CryIf_00136] */
        /* Polyspace +2 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        /* Polyspace +1 MISRA-C3:D4.14 [JUstified:Unset] " NSCA_Polyspace_CryIf_Dir4.14 " */
        if( NULL_PTR != job->jobRedirectionInfoRef )
        {
            CryIf_ProcessJobRedirection(job);
        }
        /* Get crypto key id. */
        cryptoKeyId = CryIf_GetCryptoKeyId(job->jobPrimitiveInfo->cryIfKeyId);
        /* cryptoKeyId is defined in 4.3, version compatible. */
        if( CRYIF_INVALID_ID == cryptoKeyId )
        {
            errorId = CRYIF_E_PARAM_HANDLE;
        }
        else
        {
            job->cryptoKeyId = cryptoKeyId;
        }

        if( CRYIF_E_NO_ERROR == errorId )
        {
            objectId = CryIf_GetObjectId(channelId);
            objectDriverIdx = CryIf_GetObjectDriverIdx(channelId);
            if( CRYIF_INVALID_ID != objectDriverIdx )
            {
                retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].ProcessJobFunctionTable(objectId, job);
            }
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                errorId = CRYIF_E_PARAM_HANDLE;
            }
        }
    }

    /* Dev error report */
#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_PROCESSJOB, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_CancelJob
*
* Explanation: This interface dispatches the job cancellation function to the
*              configured crypto driver object.
*
* param: channelId: Holds the identifier of the crypto channel.
*        job: Pointer to the configuration of the job. Contains structures with
*             user and primitive relevant information.
*
* retval: E_OK: Request successful, job has been removed
*         E_NOT_OK: Request failed, job couldn't be removed
********************************************************************************
*/
FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_CancelJob
(
    uint32 channelId,
    P2VAR(Crypto_JobType, AUTOMATIC, CRYIF_APPL_DATA) job
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    uint8 retVal  = E_NOT_OK;
    uint32 objectId;
    uint32 objectDriverIdx;
    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check if ID is out of range. */
    else if( CRYIF_INVALID_ID == CryIf_GetObjectId(channelId) )
    {
        errorId = CRYIF_E_PARAM_HANDLE;
    }
    /* Check whether pointer parameter is null pointer. */
    else if( NULL_PTR == job )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CRYIF_E_PARAM_POINTER;
    }
    else
    {
        objectId = CryIf_GetObjectId(channelId);
        objectDriverIdx = CryIf_GetObjectDriverIdx(channelId);
        if( CRYIF_INVALID_ID != objectDriverIdx )
        {
            /* Polyspace +2 MISRA-C3:D4.14 [JUstified:Unset] " NSCA_Polyspace_CryIf_Dir4.14 " */
            /* Polyspace +1 MISRA-C3:11.8 [JUstified:Unset] " NSCA_Polyspace_CryIf_Rule11.8 " */
            retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].CancelJobFunctionTable(objectId, (Crypto_JobInfoType *)job->jobInfo); /* PRQA S 311 */ /* NSCA_QAC_CryIf_Rule11.8 */
        }
        else
        /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = CRYIF_E_PARAM_HANDLE;
        }
    }

    /* Dev error report */
#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_CANCELJOB, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_KeyElementSet
*
* Explanation: This function shall dispatch the set key element function to the
*              configured crypto driver object.
*
* param: cryIfKeyId: Holds the identifier of the key whose key element shall be
*                    set.
*        keyElementId: Holds the identifier of the key element which shall be
*                      set.
*        keyPtr: Holds the pointer to the key data which shall be set as key
*                element.
*        keyLength: Contains the length of the key element in bytes.
*
* retval: E_OK: Request successful
*         E_NOT_OK: Request failed
********************************************************************************
*/
FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyElementSet
(
    uint32 cryIfKeyId,
    uint32 keyElementId,
    P2CONST(uint8, AUTOMATIC, CRYIF_APPL_CONST) keyPtr,
    uint32 keyLength
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    uint8 retVal  = E_NOT_OK;
    uint32 cryptoKeyId;
    uint32 objectDriverIdx;
    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check if ID is out of range. */
    else if( CRYIF_INVALID_ID == CryIf_GetCryptoKeyId(cryIfKeyId) )
    {
        errorId = CRYIF_E_PARAM_HANDLE;
    }
    /* Check whether pointer parameter is null pointer. */
    else if( NULL_PTR == keyPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CRYIF_E_PARAM_POINTER;
    }
    else if( CRYIF_VALUE_ZERO == keyLength )
    {
        errorId = CRYIF_E_PARAM_VALUE;
    }
    else
    {
        cryptoKeyId = CryIf_GetCryptoKeyId(cryIfKeyId);
        objectDriverIdx = CryIf_GetKeyObjectDriverIdx(cryptoKeyId);
        if( CRYIF_INVALID_ID != objectDriverIdx )
        {
            retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].KeyElementSetFunctionTable(cryptoKeyId, keyElementId, keyPtr, keyLength);
        }
        else
        {
            errorId = CRYIF_E_PARAM_HANDLE;
        }
    }

    /* Dev error report */
#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_KEYELEMENTSET, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_KeySetValid
*
* Explanation: This function shall dispatch the set key valid function to the
*              configured crypto driver object.
*
* param: cryIfKeyId: Holds the identifier of the key whose key element shall be
*                    set.
*
* retval: E_OK: Request successful
*         E_NOT_OK: Request failed
*         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is busy
*         CRYPTO_E_KEY_WRITE_FAIL:Request failed because write access was denied
*         CRYPTO_E_KEY_NOT_AVAILABLE: Request failed because the key is not
*                                     available
*         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element size does not
*                                     match size of provided data
********************************************************************************
*/
FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeySetValid
(
    uint32 cryIfKeyId
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    uint8 retVal  = E_NOT_OK;
    uint32 cryptoKeyId;
    uint32 objectDriverIdx;
    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check if ID is out of range. */
    else if( CRYIF_INVALID_ID == CryIf_GetCryptoKeyId(cryIfKeyId) )
    {
        errorId = CRYIF_E_PARAM_HANDLE;
    }
    else
    {
        cryptoKeyId = CryIf_GetCryptoKeyId(cryIfKeyId);
        objectDriverIdx = CryIf_GetKeyObjectDriverIdx(cryptoKeyId);
        if( CRYIF_INVALID_ID != objectDriverIdx )
        {
            retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].KeySetValidFunctionTable(cryptoKeyId);
        }
        else
        {
            errorId = CRYIF_E_PARAM_HANDLE;
        }
    }

    /* Dev error report */
#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_KEYSETVALID, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_KeyElementGet
*
* Explanation: This function shall dispatch the set key element function to the
*              configured crypto driver object.
*
* param: cryIfKeyId: Holds the identifier of the key whose key element shall be
*                    set.
*        keyElementId: Holds the identifier of the key element which shall be
*                      set.
*        resultPtr: Holds the pointer of the buffer for the returned key
*                   element.
*        resultLengthPtr: Holds a pointer to a memory location in which the
*                         length information is stored. On calling this function
*                         this parameter shall contain the size of the buffer
*                         provided by resultPtr. If the key element is
*                         configured to allow partial access, this parameter
*                         contains the amount of data which should be read from
*                         the key element. The size may not be equal to the size
*                         of the provided buffer anymore.When the request has
*                         finished, the amount of data that has been stored
*                         shall be stored.
*
* retval: E_OK: Request successful
*         E_NOT_OK: Request failed
*         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is busy
*         CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested key element
*                                     is not available
*         CRYPTO_E_KEY_READ_FAIL: Request failed because read access was denied
*         CRYPTO_E_SMALL_BUFFER: The provided buffer is too small to store the
*                                result
*         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key
*                             element
********************************************************************************
*/
FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyElementGet
(
    uint32 cryIfKeyId,
    uint32 keyElementId,
    P2VAR(uint8, AUTOMATIC, CRYIF_APPL_DATA) resultPtr,
    P2VAR(uint32, AUTOMATIC, CRYIF_APPL_DATA) resultLengthPtr
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    uint8 retVal  = E_NOT_OK;
    uint32 cryptoKeyId;
    uint32 objectDriverIdx;
    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check if ID is out of range. */
    else if( CRYIF_INVALID_ID == CryIf_GetCryptoKeyId(cryIfKeyId) )
    {
        errorId = CRYIF_E_PARAM_HANDLE;
    }
    /* Check whether pointer parameter is null pointer. */
    else if( (NULL_PTR == resultPtr) || (NULL_PTR == resultLengthPtr) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CRYIF_E_PARAM_POINTER;
    }
    /* Polyspace +1 MISRA-C3:D4.14 [JUstified:Unset] " NSCA_Polyspace_CryIf_Dir4.14 " */
    else if( CRYIF_VALUE_ZERO == *resultLengthPtr )
    {
        errorId = CRYIF_E_PARAM_VALUE;
    }
    else
    {
        cryptoKeyId = CryIf_GetCryptoKeyId(cryIfKeyId);
        objectDriverIdx = CryIf_GetKeyObjectDriverIdx(cryptoKeyId);
        if( CRYIF_INVALID_ID != objectDriverIdx )
        {
            retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].KeyElementGetFunctionTable(cryptoKeyId, keyElementId, resultPtr, resultLengthPtr);
        }
        else
        {
            errorId = CRYIF_E_PARAM_HANDLE;
        }
    }

    /* Dev error report */
#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_KEYELEMENTGET, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_KeyElementCopy
*
* Explanation: This function shall copy a key elements from one key to a target
*              key.
*
* param: cryIfKeyId: Holds the identifier of the key whose key element shall be
*                    set.
*        keyElementId: Holds the identifier of the key element which shall be
*                      set.
*        targetCryIfKeyId: Holds the identifier of the key whose key element
*                          shall be the destination element.
*        targetKeyElementId: Holds the identifier of the key element which shall
*                            be the destination for the copy operation.
*
* retval: E_OK: Request successful
*         E_NOT_OK: Request failed
*         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is busy
*         CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested key element
*                                     is not available
*         CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to extract key
*                                 element
*         CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to write key
*                                  element
*         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element sizes are
*                                     not compatible
*         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key
*                             element
********************************************************************************
*/
FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyElementCopy
(
    uint32 cryIfKeyId,
    uint32 keyElementId,
    uint32 targetCryIfKeyId,
    uint32 targetKeyElementId
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    uint8 retVal  = E_NOT_OK;
    uint32 cryptoKeyId;
    uint32 targetCryptoKeyId;
    uint32 objectDriverIdx;
    uint32 targetObjectDriverIdx;

    uint8 resultBuffer[CRYIF_MAX_SIZE_OF_KEY_ELEMENT];
    uint32 resultLength = CRYIF_MAX_SIZE_OF_KEY_ELEMENT;
    uint32 cKId = CryIf_GetCryptoKeyId(cryIfKeyId);
    uint32 tcKId = CryIf_GetCryptoKeyId(targetCryIfKeyId);
    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check if ID is out of range. */
    else if( (CRYIF_INVALID_ID == cKId) || (CRYIF_INVALID_ID == tcKId) )
    {
        errorId = CRYIF_E_PARAM_HANDLE;
    }
    else
    {
        cryptoKeyId = CryIf_GetCryptoKeyId(cryIfKeyId);
        targetCryptoKeyId = CryIf_GetCryptoKeyId(targetCryIfKeyId);

        objectDriverIdx = CryIf_GetKeyObjectDriverIdx(cryptoKeyId);
        targetObjectDriverIdx = CryIf_GetKeyObjectDriverIdx(targetCryptoKeyId);
        if( (CRYIF_INVALID_ID == objectDriverIdx) || (CRYIF_INVALID_ID == targetObjectDriverIdx) )
        {
            errorId = CRYIF_E_PARAM_HANDLE;
        }
        else
        {
            /* polyspace +2 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_CryIf_DeadCode" */
            /* Polyspace +1 MISRA-C3:14.3 [JUstified:Unset] " NSCA_Polyspace_CryIf_Rule14.3 " */
            if( objectDriverIdx == targetObjectDriverIdx )
            {
                retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].KeyElementCopyFunctionTable(cryptoKeyId, keyElementId, targetCryptoKeyId, targetKeyElementId);
            /* Polyspace +1 MISRA-C3:2.1 [JUstified:Unset] " NSCA_Polyspace_Common_Unreachable " */
            }
            else /* [SWS_CryIf_00114] */
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].KeyElementGetFunctionTable(cryptoKeyId, keyElementId, resultBuffer, &resultLength);
                if( E_OK == retVal )
                {
                    retVal = CryIf_ObejectDriverFunctionTable[targetObjectDriverIdx].KeyElementSetFunctionTable(targetCryptoKeyId, targetKeyElementId, resultBuffer, resultLength);
                }
            }
        }
    }

    /* Dev error report */
#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_KEYELEMENTCOPY, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

    return retVal;
}

#if( CRYIF_KEY_ELEMENT_COPY_PARTIAL == STD_ON )
/*
********************************************************************************
* Function Name: CryIf_MemCpy
*
* Explanation: Memory copy.
*
* param: dstPtr: Destination pointer.
*        srcPtr: Source pointer.
*        num: Number of data to be copied.
*
* retval: None
********************************************************************************
*/
static FUNC(void ,CRYIF_CODE) CryIf_MemCpy
(
    P2VAR(uint8, AUTOMATIC, CRYIF_APPL_DATA) dstPtr,
    P2CONST(uint8, AUTOMATIC, CRYIF_APPL_CONST) srcPtr,
    uint32 num
)
{
    uint32 counter;

    /* Polyspace +1 MISRA-C3:D4.14 [JUstified:Unset] " NSCA_Polyspace_CryIf_Dir4.14 " */
    for(counter = CRYIF_VALUE_ZERO; counter < num; counter ++ )
    {
        dstPtr[counter] = srcPtr[counter];
    }
}

/*
********************************************************************************
* Function Name: CryIf_MemClr
*
* Explanation: Memory clear.
*
* param: targetPtr : Target pointer.
*        value: Value to be used.
*        num: Number of data to be cleared.
*
* retval: None
********************************************************************************
*/
static FUNC(void ,CRYIF_CODE) CryIf_MemClr
(
    P2VAR(uint8, AUTOMATIC, CRYIF_APPL_DATA) targetPtr,
    uint8 value,
    uint32 num
)
{
    uint32 counter;

    for(counter = CRYIF_VALUE_ZERO; counter < num; counter ++ )
    {
      targetPtr[counter] = value;
    }
}

/*
********************************************************************************
* Function Name: CryIf_KeyElementCopyPartialOfDifferentDrivers
*
* Explanation: This function shall copy all key elements from the source key to
*              a target key if they are in different drivers.
*
* param: cryptoKeyId: Source crypto key id.
*        keyElementId: Source key element id.
*        keyElementSourceOffset: Source offset.
*        keyElementTargetOffset: Target offset.
*        keyElementCopyLength: Length to be copied.
*        targetCryptoKeyId: Target crypto key id.
*        targetKeyElementId: Target key element id.
*
* retval: E_OK: Request successful
*         E_NOT_OK: Request failed
********************************************************************************
*/
static FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyElementCopyPartialOfDifferentDrivers
(
    uint32 cryptoKeyId,
    uint32 keyElementId,
    uint32 keyElementSourceOffset,
    uint32 keyElementTargetOffset,
    uint32 keyElementCopyLength,
    uint32 targetCryptoKeyId,
    uint32 targetKeyElementId
)
{
    Std_ReturnType retVal;
    uint8 elementBuffer[CRYIF_MAX_SIZE_OF_KEY_ELEMENT];
    uint8 targetElementBuffer[CRYIF_MAX_SIZE_OF_KEY_ELEMENT];
    uint32 elementBufferSize = CRYIF_MAX_SIZE_OF_KEY_ELEMENT;
    uint32 targetElementBufferSize = CRYIF_MAX_SIZE_OF_KEY_ELEMENT;
    uint32 objectDriverIdx = CryIf_GetKeyObjectDriverIdx(cryptoKeyId);
    uint32 targetObjectDriverIdx = CryIf_GetKeyObjectDriverIdx(targetCryptoKeyId);

    /* Get key element. */
    if( (CRYIF_INVALID_ID == objectDriverIdx) || (CRYIF_INVALID_ID == targetObjectDriverIdx) )
    {
        retVal = E_NOT_OK;
    }
    else
    {
        retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].KeyElementGetFunctionTable(cryptoKeyId, keyElementId, elementBuffer, &elementBufferSize);
    }

    if( E_OK == retVal )
    {
        if( (keyElementSourceOffset + keyElementCopyLength) <= elementBufferSize )
        {
            retVal = CryIf_ObejectDriverFunctionTable[targetObjectDriverIdx].KeyElementGetFunctionTable(targetCryptoKeyId, targetKeyElementId, targetElementBuffer, &targetElementBufferSize);
            if( E_OK == retVal )
            {
                if( keyElementTargetOffset > targetElementBufferSize )
                {
                    CryIf_MemClr(&targetElementBuffer[targetElementBufferSize], CRYIF_VALUE_ZERO, (keyElementTargetOffset - targetElementBufferSize));
                }
                /* Copy source element data to target element. */
                CryIf_MemCpy(&targetElementBuffer[keyElementTargetOffset], &elementBuffer[keyElementSourceOffset], keyElementCopyLength);

                /* [SWS_Csm_91021] Csm requirement is implemented in the current function. */
                if( (keyElementTargetOffset + keyElementCopyLength) > targetElementBufferSize )
                {
                    targetElementBufferSize = keyElementTargetOffset + keyElementCopyLength;
                }
                /* Set target key element. */
                retVal = CryIf_ObejectDriverFunctionTable[targetObjectDriverIdx].KeyElementSetFunctionTable(targetCryptoKeyId, targetKeyElementId, targetElementBuffer, targetElementBufferSize);
            }
        }
        else
        {
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_KeyElementCopyPartial
*
* Explanation: Copies a key element to another key element. The keyElementOffsets
*              and keyElementCopyLength allows to copy just parts of the source
*              key element into the destination key element.(new in 4.)
*
* param: cryIfKeyId: Holds the identifier of the key whose key element shall be set.
*        keyElementId: Holds the identifier of the key element which shall be set.
*        keyElementSourceOffset: This is the offset of the source key element
*                                indicating the start index of the copy operation.
*        keyElementTargetOffset: This is the offset of the target key element
*                                indicating the start index of the copy operation.
*        keyElementCopyLength: Specifies the number of bytes that shall be copied.
*        targetCryIfKeyId:Holds the identifier of the key whose key element shall
*                         be the destination element.
*        targetKeyElementId:Holds the identifier of the key element which shall
*                           be the destination for the copy operation.
*
* retval: E_OK: Request successful
*         E_NOT_OK: Request failed
*         CRYPTO_E_BUSY: Request failed, Crypto Driver Object is busy
*         CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested key element is
*                                     not available
*         CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to extract key element
*         CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to write key element
*         CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element sizes are not
*                                     compatible
*         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key
*                             element
********************************************************************************
*/
FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyElementCopyPartial
(
    uint32 cryIfKeyId,
    uint32 keyElementId,
    uint32 keyElementSourceOffset,
    uint32 keyElementTargetOffset,
    uint32 keyElementCopyLength,
    uint32 targetCryIfKeyId,
    uint32 targetKeyElementId
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    Std_ReturnType retVal  = E_NOT_OK;
    uint32 cryptoKeyId;
    uint32 targetCryptoKeyId;
    uint32 objectDriverIdx;
    uint32 targetObjectDriverIdx;
    uint32 cKId = CryIf_GetCryptoKeyId(cryIfKeyId);
    uint32 tcKId = CryIf_GetCryptoKeyId(targetCryIfKeyId);

    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check if ID is out of range. */
    else if( (CRYIF_INVALID_ID == cKId) || (CRYIF_INVALID_ID == tcKId) )
    {
        errorId = CRYIF_E_PARAM_HANDLE;
    }
    else
    {
        cryptoKeyId = CryIf_GetCryptoKeyId(cryIfKeyId);
        targetCryptoKeyId = CryIf_GetCryptoKeyId(targetCryIfKeyId);
        objectDriverIdx = CryIf_GetKeyObjectDriverIdx(cryptoKeyId);
        targetObjectDriverIdx = CryIf_GetKeyObjectDriverIdx(targetCryptoKeyId);

        if( (CRYIF_INVALID_ID != objectDriverIdx) && (CRYIF_INVALID_ID != targetObjectDriverIdx) )
        {
            /* Polyspace +1 MISRA-C3:14.3 [JUstified:Unset] " NSCA_Polyspace_CryIf_Rule14.3 " */
            if( objectDriverIdx == targetObjectDriverIdx )
            {
                retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].KeyElementCopyPartialFunctionTable
                         (cryptoKeyId, keyElementId, keyElementSourceOffset, keyElementTargetOffset, keyElementCopyLength, targetCryptoKeyId, targetKeyElementId);
            /* Polyspace +1 MISRA-C3:2.1 [JUstified:Unset] " NSCA_Polyspace_Common_Unreachable " */
            }
            else
            {
                retVal = CryIf_KeyElementCopyPartialOfDifferentDrivers(cryptoKeyId, keyElementId, keyElementSourceOffset, keyElementTargetOffset, keyElementCopyLength, targetCryptoKeyId, targetKeyElementId);
            }
        }
    }

#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_KEYELEMENTCOPYPARTIAL, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

    return retVal;
}
#endif /* CRYIF_KEY_ELEMENT_COPY_PARTIAL == STD_ON */

/*
********************************************************************************
* Function Name: CryIf_KeyCopyOfDifferentDrivers
*
* Explanation: This function shall copy all key elements from the source key to
*              a target key if they are in different drivers.
*
* param: cryIfKeyId: Holds the identifier of the key whose key element shall be
*                    the source element.
*        targetCryIfKeyId: Holds the identifier of the key whose key element
*                          shall be the destination element.
*        objectDriverIdx: Object driver index of source key id.
*
*        targetObjectDriverIdx: Object driver index of target key id.
*
* retval: E_OK: Request successful
*         E_NOT_OK: Request failed
********************************************************************************
*/
static FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyCopyOfDifferentDrivers
(
    uint32 cryptoKeyId,
    uint32 targetCryptoKeyId,
    uint32 objectDriverIdx,
    uint32 targetObjectDriverIdx
)
{
    Std_ReturnType retVal = E_NOT_OK;
    Std_ReturnType retKeyVal;
    Std_ReturnType retTargetKeyVal;
    uint8 elementDataBuffer[CRYIF_MAX_SIZE_OF_KEY_ELEMENT];
    uint32 elementBufferSize = CRYIF_MAX_SIZE_OF_KEY_ELEMENT;
    uint32 elementIdBuffer[CRYIF_NUMBER_OF_ELEMENT];
    uint32 elementIdSize = CRYIF_NUMBER_OF_ELEMENT;
    uint32 targetElementIdBuffer[CRYIF_NUMBER_OF_ELEMENT];
    uint32 targetElemnetIdSize = CRYIF_NUMBER_OF_ELEMENT;
    uint32 cycl_x;
    uint32 cycl_y;

    /* Get element ids for key id. */
    if( (CRYIF_INVALID_ID == objectDriverIdx) || (CRYIF_INVALID_ID == targetObjectDriverIdx) )
    {
        retKeyVal = E_NOT_OK;
        retTargetKeyVal = E_NOT_OK;
    }
    else
    {
        retKeyVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].KeyElementIdsGetFunctionTable(cryptoKeyId, elementIdBuffer, &elementIdSize);
        retTargetKeyVal = CryIf_ObejectDriverFunctionTable[targetObjectDriverIdx].KeyElementIdsGetFunctionTable(targetCryptoKeyId, targetElementIdBuffer, &targetElemnetIdSize);
    }

    if( (E_OK == retKeyVal) && (E_OK == retTargetKeyVal) )
    {
        /* Polyspace +1 MISRA-C3:D4.14 [JUstified:Unset] " NSCA_Polyspace_CryIf_Dir4.14 " */
        for( cycl_x = CRYIF_VALUE_ZERO; cycl_x < elementIdSize ; cycl_x ++ )
        {
            for( cycl_y = CRYIF_VALUE_ZERO; cycl_y < elementIdSize ; cycl_y ++ )
            {
                /* Check if the ids are the same. */
                if( elementIdBuffer[cycl_x] == targetElementIdBuffer[cycl_y] )
                {
                    /* Get the element from source key. */
                    if( E_OK == CryIf_ObejectDriverFunctionTable[objectDriverIdx].KeyElementGetFunctionTable(cryptoKeyId, elementIdBuffer[cycl_x], elementDataBuffer, &elementBufferSize) )
                    {
                        /* Set the element to target key. */
                        if( E_OK == CryIf_ObejectDriverFunctionTable[targetObjectDriverIdx].KeyElementSetFunctionTable(targetCryptoKeyId, targetElementIdBuffer[cycl_y], elementDataBuffer, elementBufferSize) )
                        {
                          retVal = E_OK;
                        }
                    }
                    break;
                }
            }
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_KeyCopy
*
* Explanation: This function shall copy all key elements from the source key to
*              a target key.
*
* param: cryIfKeyId: Holds the identifier of the key whose key element shall be
*                    the source element.
*        targetCryIfKeyId: Holds the identifier of the key whose key element
*                          shall be the destination element.
*
* retval: E_OK: Request successful
*        E_NOT_OK: Request failed
*        CRYPTO_E_BUSY: Request failed, Crypto Driver Object is busy
*        CRYPTO_E_KEY_NOT_AVAILABLE: Request failed, the requested key element is
*                                    not available
*        CRYPTO_E_KEY_READ_FAIL: Request failed, not allowed to extract key element
*        CRYPTO_E_KEY_WRITE_FAIL: Request failed, not allowed to write key element
*        CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element sizes are not
*                                    compatible
*        CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key
*                            element
********************************************************************************
*/
FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyCopy
(
    uint32 cryIfKeyId,
    uint32 targetCryIfKeyId
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    uint8 retVal  = E_NOT_OK;
    uint32 cryptoKeyId;
    uint32 targetCryptoKeyId;
    uint32 objectDriverIdx;
    uint32 targetObjectDriverIdx;
    uint32 cKId = CryIf_GetCryptoKeyId(cryIfKeyId);
    uint32 tcKId = CryIf_GetCryptoKeyId(targetCryIfKeyId);

    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check if ID is out of range. */
    else if( (CRYIF_INVALID_ID == cKId) || (CRYIF_INVALID_ID == tcKId) )
    {
        errorId = CRYIF_E_PARAM_HANDLE;
    }
    else
    {
        cryptoKeyId = CryIf_GetCryptoKeyId(cryIfKeyId);
        targetCryptoKeyId = CryIf_GetCryptoKeyId(targetCryIfKeyId);
        objectDriverIdx = CryIf_GetKeyObjectDriverIdx(cryptoKeyId);
        targetObjectDriverIdx = CryIf_GetKeyObjectDriverIdx(targetCryptoKeyId);
        if( (CRYIF_INVALID_ID != objectDriverIdx) && (CRYIF_INVALID_ID != targetObjectDriverIdx) )
        {
            /* polyspace +2 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_CryIf_DeadCode" */
            /* Polyspace +1 MISRA-C3:14.3 [JUstified:Unset] " NSCA_Polyspace_CryIf_Rule14.3 " */
            if( objectDriverIdx == targetObjectDriverIdx )
            {
                retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].KeyCopyFunctionTable(cryptoKeyId, targetCryptoKeyId);
            /* Polyspace +1 MISRA-C3:2.1 [JUstified:Unset] " NSCA_Polyspace_Common_Unreachable " */
            }
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                retVal = CryIf_KeyCopyOfDifferentDrivers(cryptoKeyId, targetCryptoKeyId, objectDriverIdx, targetObjectDriverIdx);
            }
        }
    }

#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_KEYCOPY, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_RandomSeed
*
* Explanation: This function shall dispatch the random seed function to the
*              configured crypto driver object.
*
* param: cryIfKeyId: Holds the identifier of the key for which a new seed shall be
*                    generated.
*        seedPtr: Holds a pointer to the memory location which contains the data
*                 to feed the seed.
*        seedLength: Contains the length of the seed in bytes.
*
* retval: E_OK: Request successful
*         E_NOT_OK: Request failed
*         E_BUSY: Request failed, Crypto Driver Object is busy
*         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key
*                             element
********************************************************************************
*/
FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_RandomSeed
(
    uint32 cryIfKeyId,
    P2CONST(uint8, AUTOMATIC, CRYIF_APPL_CONST) seedPtr,
    uint32 seedLength
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    uint8 retVal  = E_NOT_OK;
    uint32 cryptoKeyId;
    uint32 objectDriverIdx;
    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check if ID is out of range. */
    else if( CRYIF_INVALID_ID == CryIf_GetCryptoKeyId(cryIfKeyId) )
    {
        errorId = CRYIF_E_PARAM_HANDLE;
    }
    /* Check whether pointer parameter is null pointer. */
    else if( NULL_PTR == seedPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CRYIF_E_PARAM_POINTER;
    }
    else if( CRYIF_VALUE_ZERO == seedLength )
    {
        errorId = CRYIF_E_PARAM_VALUE;
    }
    else
    {
        cryptoKeyId = CryIf_GetCryptoKeyId(cryIfKeyId);
        objectDriverIdx = CryIf_GetKeyObjectDriverIdx(cryptoKeyId);
        if( CRYIF_INVALID_ID != objectDriverIdx )
        {
            retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].RandomSeedFunctionTable(cryptoKeyId, seedPtr, seedLength);
        }
        else
        {
            errorId = CRYIF_E_PARAM_POINTER;
        }
    }

#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_RANDOMSEED, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_KeyGenerate
*
* Explanation: This function shall dispatch the key generate function to the
*              configured crypto driver object.
*
* param: cryIfKeyId: Holds the identifier of the key which is to be updated with
*                    the generated value.
*
* retval: E_OK: Request successful
*         E_NOT_OK: Request failed
*         E_BUSY: Request failed, Crypto Driver Object is busy
*         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key
*                             element
********************************************************************************
*/
FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyGenerate
(
    uint32 cryIfKeyId
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    uint8 retVal  = E_NOT_OK;
    uint32 cryptoKeyId;
    uint32 objectDriverIdx;
    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check if ID is out of range. */
    else if( CRYIF_INVALID_ID == CryIf_GetCryptoKeyId(cryIfKeyId) )
    {
        errorId = CRYIF_E_PARAM_HANDLE;
    }
    else
    {
        cryptoKeyId = CryIf_GetCryptoKeyId(cryIfKeyId);
        objectDriverIdx = CryIf_GetKeyObjectDriverIdx(cryptoKeyId);
        if( CRYIF_INVALID_ID != objectDriverIdx )
        {
            retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].KeyGenerateFunctionTable(cryptoKeyId);
        }
        else
        {
            errorId = CRYIF_E_PARAM_POINTER;
        }
    }

#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_KEYGENERATE, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_KeyDerive
*
* Explanation: This function shall dispatch the key derive function to the configured
*              crypto driver object.
*
* param: cryIfKeyId: Holds the identifier of the key which is used for key derivation.
*        targetCryIfKeyId: Holds the identifier of the key which is used to store
*                          the derived key.
*
* retval: E_OK: Request successful
*         E_NOT_OK: Request failed
*         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key
*                             element
********************************************************************************
*/
FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyDerive
(
    uint32 cryIfKeyId,
    uint32 targetCryIfKeyId
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    uint8 retVal  = E_NOT_OK;
    uint32 cryptoKeyId;
    uint32 objectDriverIdx;
    uint32 targetCryptoKeyId;
    uint32 targetObjectDriverIdx;
    uint32 cKId = CryIf_GetCryptoKeyId(cryIfKeyId);
    uint32 tcKId = CryIf_GetCryptoKeyId(targetCryIfKeyId);

    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check if ID is out of range. */
    else if( (CRYIF_INVALID_ID == cKId) || (CRYIF_INVALID_ID == tcKId) )
    {
        errorId = CRYIF_E_PARAM_HANDLE;
    }
    else
    {
        cryptoKeyId = CryIf_GetCryptoKeyId(cryIfKeyId);
        objectDriverIdx = CryIf_GetKeyObjectDriverIdx(cryptoKeyId);
        targetCryptoKeyId = CryIf_GetCryptoKeyId(targetCryIfKeyId);
        targetObjectDriverIdx = CryIf_GetKeyObjectDriverIdx(targetCryptoKeyId);
        if( (CRYIF_INVALID_ID != objectDriverIdx) && (CRYIF_INVALID_ID != targetObjectDriverIdx) )
        {
            /* polyspace +2 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_CryIf_DeadCode" */
            /* Polyspace +1 MISRA-C3:14.3 [JUstified:Unset] " NSCA_Polyspace_CryIf_Rule14.3 " */
            if( objectDriverIdx == targetObjectDriverIdx )
            {
                retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].KeyDeriveFunctionTable(cryptoKeyId, targetCryptoKeyId);
            /* Polyspace +1 MISRA-C3:2.1 [JUstified:Unset] " NSCA_Polyspace_Common_Unreachable " */
            }
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {   /* If keys are in diferent drivers */
                errorId = CRYIF_E_PARAM_HANDLE;
            }
        }
    }

#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_KEYDERIVE, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_KeyExchangeCalcPubVal
*
* Explanation: This function shall dispatch the key exchange public value calculation
*              function to the configured crypto driver object.
*
* param: cryIfKeyId: Holds the identifier of the key which shall be used for the
*                    key exchange protocol.
*        publicValueLengthPtr: Holds a pointer to the memory location in which the
*                              public value length information is stored. On calling
*                              this function, this parameter shall contain the size
*                              of the buffer provided by publicValuePtr. When the
*                              request has finished, the actual length of the returned
*                              value shall be stored.
*        publicValuePtr: Contains the pointer to the data where the public value shall
*                        be stored.
*
* retval: E_OK: Request successful
*         E_NOT_OK: Request failed
*         E_BUSY: Request failed, Crypto Driver Object is busy
*         CRYPTO_E_SMALL_BUFFER: The provided buffer is too small to store the
*                                result
*         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key
*                             element
********************************************************************************
*/
FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyExchangeCalcPubVal
(
    uint32 cryIfKeyId,
    P2VAR(uint8, AUTOMATIC, CRYIF_APPL_DATA) publicValuePtr,
    P2VAR(uint32, AUTOMATIC, CRYIF_APPL_DATA) publicValueLengthPtr
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    uint8 retVal  = E_NOT_OK;
    uint32 cryptoKeyId;
    uint32 objectDriverIdx;
    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check if ID is out of range. */
    else if( CRYIF_INVALID_ID == CryIf_GetCryptoKeyId(cryIfKeyId) )
    {
        errorId = CRYIF_E_PARAM_HANDLE;
    }
    /* Check whether pointer parameter is null pointer. */
    else if( (NULL_PTR == publicValuePtr) || (NULL_PTR == publicValueLengthPtr) )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CRYIF_E_PARAM_POINTER;
    }
    /* Polyspace +1 MISRA-C3:D4.14 [JUstified:Unset] " NSCA_Polyspace_CryIf_Dir4.14 " */
    else if( CRYIF_VALUE_ZERO == *publicValueLengthPtr )
    {
        errorId = CRYIF_E_PARAM_VALUE;
    }
    else
    {
        cryptoKeyId = CryIf_GetCryptoKeyId(cryIfKeyId);
        objectDriverIdx = CryIf_GetKeyObjectDriverIdx(cryptoKeyId);
        if( CRYIF_INVALID_ID != objectDriverIdx )
        {
            retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].KeyExchangeCalcPubValFunctionTable(cryptoKeyId, publicValuePtr, publicValueLengthPtr);
        }
        else
        {
            errorId = CRYIF_E_PARAM_POINTER;
        }
    }

#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_KEYEXCHANGECALCPUBVAL, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_KeyExchangeCalcPubVal
*
* Explanation: This function shall dispatch the key exchange common shared secret
*              calculation function to the configured crypto driver object.
*
* param: cryIfKeyId: Holds the identifier of the key which shall be used for the
*                    key exchange protocol.
*        partnerPublicValuePtr: Holds the pointer to the memory location which
*                               contains the partner's public value.
*        partnerPublicValueLength: Contains the length of the partner's public
*                                  value in bytes.
*
* retval: E_OK: Request successful
*         E_NOT_OK: Request failed
*         E_BUSY: Request failed, Crypto Driver Object is busy
*         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key
*                             element
********************************************************************************
*/
FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyExchangeCalcSecret
(
    uint32 cryIfKeyId,
    P2CONST(uint8, AUTOMATIC, CRYIF_APPL_CONST) partnerPublicValuePtr,
    uint32 partnerPublicValueLength
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    uint8 retVal  = E_NOT_OK;
    uint32 cryptoKeyId;
    uint32 objectDriverIdx;
    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check if ID is out of range. */
    else if( CRYIF_INVALID_ID == CryIf_GetCryptoKeyId(cryIfKeyId) )
    {
        errorId = CRYIF_E_PARAM_HANDLE;
    }
    /* Check whether pointer parameter is null pointer. */
    else if( NULL_PTR == partnerPublicValuePtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CRYIF_E_PARAM_POINTER;
    }
    else if( CRYIF_VALUE_ZERO == partnerPublicValueLength )
    {
        errorId = CRYIF_E_PARAM_VALUE;
    }
    else
    {
        cryptoKeyId = CryIf_GetCryptoKeyId(cryIfKeyId);
        objectDriverIdx = CryIf_GetKeyObjectDriverIdx(cryptoKeyId);
        if( CRYIF_INVALID_ID != objectDriverIdx )
        {
            retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].KeyExchangeCalcSecretFunctionTable(cryptoKeyId, partnerPublicValuePtr, partnerPublicValueLength);
        }
        else
        {
            errorId = CRYIF_E_PARAM_POINTER;
        }
    }

#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_KEYEXCHANGECALCSECRET, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_CertificateParse
*
* Explanation: This function shall dispatch the certificate parse function to
*              the configured crypto driver object.
*
* param: cryIfKeyId: Holds the identifier of the key which shall be parsed.
*
* retval: E_OK: Request successful
*         E_NOT_OK: Request failed
*         E_BUSY: Request failed, Crypto Driver Object is busy
*         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key
*                             element
********************************************************************************
*/
FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_CertificateParse
(
    uint32 cryIfKeyId
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    uint8 retVal  = E_NOT_OK;
    uint32 cryptoKeyId;
    uint32 objectDriverIdx;
    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check if ID is out of range. */
    else if( CRYIF_INVALID_ID == CryIf_GetCryptoKeyId(cryIfKeyId) )
    {
        errorId = CRYIF_E_PARAM_HANDLE;
    }
    else
    {
        cryptoKeyId = CryIf_GetCryptoKeyId(cryIfKeyId);
        objectDriverIdx = CryIf_GetKeyObjectDriverIdx(cryptoKeyId);
        if( CRYIF_INVALID_ID != objectDriverIdx )
        {
            retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].CertificateParseFunctionTable(cryptoKeyId);
        }
        else
        {
            errorId = CRYIF_E_PARAM_POINTER;
        }
    }

#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_CERTIFICATEPARSE, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_CertificateVerify
*
* Explanation: Verifies the certificate stored in the key referenced by verifyCryIfKeyId
*              with the certificate stored in the key referenced by cryIfKeyId.
*
* param: cryIfKeyId: Holds the identifier of the key which shall be used to validate
*                    the certificate.
*        verifyCryIfKeyId: Holds the identifier of the key containing the certificate
*                          to be verified.
*        verifyPtr: Holds a pointer to the memory location which will contain the
*                   result of the certificate verification.
*
* retval: E_OK: Request successful
*         E_NOT_OK: Request failed
*         E_BUSY: Request failed, Crypto Driver Object is busy
*         CRYPTO_E_KEY_EMPTY: Request failed because of uninitialized source key
*                             element
********************************************************************************
*/
FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_CertificateVerify
(
    uint32 cryIfKeyId,
    uint32 verifyCryIfKeyId,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYIF_APPL_DATA) verifyPtr
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    uint8 retVal  = E_NOT_OK;
    uint32 cryptoKeyId;
    uint32 verifyCryptoKeyId;
    uint32 objectDriverIdx;
    uint32 verifyObjectDriverIdx;
    uint32 cKId = CryIf_GetCryptoKeyId(cryIfKeyId);
    uint32 vcKId = CryIf_GetCryptoKeyId(verifyCryIfKeyId);

    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check if ID is out of range. */
    else if( (CRYIF_INVALID_ID == cKId) || (CRYIF_INVALID_ID == vcKId) )
    {
        errorId = CRYIF_E_PARAM_HANDLE;
    }
    /* Check whether pointer parameter is null pointer. */
    else if( NULL_PTR == verifyPtr )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CRYIF_E_PARAM_POINTER;
    }
    else
    {
        cryptoKeyId = CryIf_GetCryptoKeyId(cryIfKeyId);
        objectDriverIdx = CryIf_GetKeyObjectDriverIdx(cryptoKeyId);
        verifyCryptoKeyId = CryIf_GetCryptoKeyId(verifyCryIfKeyId);
        verifyObjectDriverIdx = CryIf_GetKeyObjectDriverIdx(verifyCryptoKeyId);
        if( (CRYIF_INVALID_ID != objectDriverIdx) && (CRYIF_INVALID_ID != verifyObjectDriverIdx) )
        {
            /* polyspace +2 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_CryIf_DeadCode" */
            /* Polyspace +1 MISRA-C3:14.3 [JUstified:Unset] " NSCA_Polyspace_CryIf_Rule14.3 " */
            if( objectDriverIdx == verifyObjectDriverIdx )
            {
                retVal = CryIf_ObejectDriverFunctionTable[objectDriverIdx].CertificateVerifyFunctionTable(cryptoKeyId, verifyCryptoKeyId, verifyPtr);
            /* Polyspace +1 MISRA-C3:2.1 [JUstified:Unset] " NSCA_Polyspace_Common_Unreachable " */
            }
            else
            /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {   /* If keys are in diferent drivers */
                errorId = CRYIF_E_PARAM_HANDLE;
            }
        }
    }

#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_CERTIFICATEVERIFY, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_CallbackNotification
*
* Explanation: Notifies the CRYIF about the completion of the request with the
*              result of the cryptographic operation.
*
* param: job: Points to the completed job's information structure. It contains a
*             callbackID to identify which job is finished.
*        result: Contains the result of the cryptographic operation.
*
* retval: None
********************************************************************************
*/
FUNC(void ,CRYIF_CODE) CryIf_CallbackNotification
(
    P2VAR(Crypto_JobType,  AUTOMATIC, CRYIF_APPL_DATA) job,
    Std_ReturnType result
)
{
    /* Local Variables */
    uint8 errorId = CRYIF_E_NO_ERROR;
    /* Check module init */
    if( CRYIF_UNINITIALIZED == CryIf_ModuleInitState )
    {
        errorId = CRYIF_E_UNINIT;
    }
    /* Check whether pointer parameter is null pointer. */
    else if( NULL_PTR == job )
    /* Polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CRYIF_E_PARAM_POINTER;
    }
    else
    {
        Csm_CallbackNotification(job, result);
    }

#if( CRYIF_DEV_ERROR_DETECT == STD_ON )
    if( CRYIF_E_NO_ERROR != errorId )
    {
        (void)CRYIF_REPORT_DEV_ERROR(CRYIF_SID_CALLBACKNOTIFICATION, errorId);
    }
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif /* CRYIF_DEV_ERROR_DETECT */

}

/*
********************************************************************************
* Function Name: CryIf_GetObjectIdIdx
*
* Explanation: Returns the ObjectId information of the channel.
*
* param: channelId: Holds the identifier of the crypto channel.
*
* retval: retVal
********************************************************************************
*/
LOCAL_INLINE FUNC(uint32 ,CRYIF_CODE) CryIf_GetObjectId
(
    uint32 channelId
)
{
    /* Local Variables */
    uint32 retVal = CRYIF_INVALID_ID;
    uint32 num;
    const CryIf_ChannelConfigType* cryIfChCfg = CryIf_ChannelConfig;

    for( num = CRYIF_VALUE_ZERO; num < CRYIF_NUMBER_OF_CHANNEL; num ++ )
    {
        /* Find the objectId of the channelId */
        if( cryIfChCfg[num].CryIfChannelId == channelId )
        {
            retVal = cryIfChCfg[num].CryptoDriverObjectRef;
            break;
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_GetObjectDriverIdx
*
* Explanation: Returns the ObjectDriverIdx information of the object id.
*
* param: objectId: Holds the identifier of the crypto object.
*
* retval: retVal
********************************************************************************
*/
LOCAL_INLINE FUNC(uint32 ,CRYIF_CODE) CryIf_GetObjectDriverIdx
(
    uint32 channelId
)
{
    /* Local Variables */
    uint32 retVal = CRYIF_INVALID_ID;
    uint32 num;
    const CryIf_ChannelConfigType* cryIfChCfg = CryIf_ChannelConfig;

    for( num = CRYIF_VALUE_ZERO; num < CRYIF_NUMBER_OF_CHANNEL; num++ )
    {
        /* Find the Driver idx of the channelId */
        if( cryIfChCfg[num].CryIfChannelId == channelId )
        {
            retVal = cryIfChCfg[num].CryptoChannelIdx;
            break;
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_GetCryptoKeyId
*
* Explanation: Returns the Crypto Key Id information of the CyrIf Key Id.
*
* param: cryIfId: Holds the key identifier of the crypto.
*
* retval: retVal
********************************************************************************
*/
LOCAL_INLINE FUNC(uint32 ,CRYIF_CODE) CryIf_GetCryptoKeyId
(
    uint32 cryIfKeyId
)
{
    /* Local Variables */
    uint32 retVal = CRYIF_INVALID_ID;
    uint32 num;
    const CryIf_KeyConfigType* cryIfKeyCfg = CryIf_KeyConfig;

    for( num = CRYIF_VALUE_ZERO; num < CRYIF_NUMBER_OF_KEY; num++ )
    {
        /* Find the cryptoKeyId id of the cryIfKeyId */
        if( cryIfKeyCfg[num].CryIfKeyId == cryIfKeyId )
        {
            retVal = cryIfKeyCfg[num].CryptoKeyRef;
            break;
        }
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: CryIf_GetKeyObjectDriverIdx
*
* Explanation: Returns the ObjectDriverIdx information of the crypto key id.
*
* param: objectId: Holds the identifier of the crypto key.
*
* retval: retVal
********************************************************************************
*/
LOCAL_INLINE FUNC(uint32 ,CRYIF_CODE) CryIf_GetKeyObjectDriverIdx
(
    uint32 cryptoKeyId
)
{
    /* Local Variables */
    uint32 retVal = CRYIF_INVALID_ID;
    uint32 num;
    const CryIf_KeyConfigType* cryIfKeyCfg = CryIf_KeyConfig;

    for( num = CRYIF_VALUE_ZERO; num < CRYIF_NUMBER_OF_KEY; num++ )
    {
        /* Find the Driver idx of the cryptoKeyId */
        if( cryIfKeyCfg[num].CryptoKeyRef == cryptoKeyId )
        {
            retVal = cryIfKeyCfg[num].CryptoKeyIdx;
            break;
        }
    }

    return retVal;
}
#define CRYIF_STOP_SEC_CODE
//wjc:CryIf_MemMap.h /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


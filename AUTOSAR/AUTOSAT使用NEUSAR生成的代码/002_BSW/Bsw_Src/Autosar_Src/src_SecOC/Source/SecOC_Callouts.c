/*
********************************************************************************
*
* File name: SecOC_Callout.c
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : yong.zhang/2020.05.11
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date : FangT/2020.09.01
* Change: Eliminate compilation warnings.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date : FangT/2021.10.29
* Change: Modify coding style.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date : FangT/2021.11.1
* Change: Modify coding style.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date : FangT/2022.12.12
* Change: Add default code function.
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "SecOC.h"

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
#define SECOC_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"

/* polyspace-begin MISRA-C3:2.7 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule2.7" */
/* polyspace-begin DEFECT:UNUSED_PARAMETER [Justified:Unset] "NSCA_Polyspace_SecOC_UNUSED_PARAMETER" */
#if( SECOC_QUERYFRESHNESSVALUE == SECOC_CFUNC )
/*
********************************************************************************
* Function Name: SecOC_GetRxFreshness
*
* Explanation: This interface is used by the SecOC to obtain the current freshness value.
*
* param(in): SecOCFreshnessValueID: Holds the identifier of the freshness value.
* param(in): SecOCTruncatedFreshnessValue: Holds the truncated freshness value that
*                                          was contained in the Secured I-PDU.
* param(in): SecOCTruncatedFreshnessValueLength: Holds the length in bits of
*                                                the truncated freshness value.
* param(in): SecOCAuthVerifyAttempts: Holds the number of authentication verify
*                                     attempts of this PDU since the last reception.
*                                     The value is 0 for the first attempt and
*                                     incremented on every unsuccessful verification attempt.
* param(inout): SecOCFreshnessValueLength: Holds the length in bits of the freshness value.
*
* param(out): SecOCFreshnessValue: Holds the freshness value to be used for
*                                  the calculation of the authenticator.
*
* retval: BufReq_ReturnType: E_OK: request successful.
*                            E_NOT_OK: request failed, a freshness value cannot
*                                      be provided due to general issues for
*                                      freshness or this FreshnessValueId.
*                            E_BUSY: The freshness information can temporarily
*                                    not be provided.
********************************************************************************
*/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_GetRxFreshness
(
    uint16 SecOCFreshnessValueID,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2CONST(uint8, AUTOMATIC, SECOC_APPL_CONST) SecOCTruncatedFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    uint32 SecOCTruncatedFreshnessValueLength,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    uint16 SecOCAuthVerifyAttempts,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    Std_ReturnType retVal = E_OK;
    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_GetRxFreshnessAuthData
*
* Explanation: This interface is used by the SecOC to obtain the current freshness value.
*
* param(in): SecOCFreshnessValueID: Holds the identifier of the freshness value.
* param(in): SecOCTruncatedFreshnessValue: Holds the truncated freshness value
*                                          that was contained in the Secured I-PDU.
* param(in): SecOCTruncatedFreshnessValueLength: Holds the length in bits of the
*                                                truncated freshness value.
* param(in): SecOCAuthDataFreshnessValue: The parameter holds a part of the received,
*                                         not yet authenticated PDU.The parameter is
*                                         optional (see description)
* param(in): SecOCAuthDataFreshnessValueLength : This is the length value in bits that
*                                                holds the freshness from the authentic PDU.
*                                                The parameter is optional (see description).
* param(in): SecOCAuthVerifyAttempts: Holds the number of authentication verify
*                                     attempts of this PDU since the last reception.
*                                     The value is 0 for the first attempt and
*                                     incremented on every unsuccessful verification attempt.
* param(inout): SecOCFreshnessValueLength: Holds the length in bits of the freshness value.
*
* param(out): SecOCFreshnessValue: Holds the freshness value to be used for
*                                  the calculation of the authenticator.
*
* retval: BufReq_ReturnType: E_OK: request successful.
*                            E_NOT_OK: request failed, a freshness value
*                                      cannot be provided due to general
*                                      issues for freshness or this FreshnessValueId.
*                            E_BUSY: The freshness information can temporarily
*                                    not be provided.
********************************************************************************
*/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_GetRxFreshnessAuthData
(
    uint16 SecOCFreshnessValueID,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2CONST(uint8, AUTOMATIC, SECOC_APPL_CONST) SecOCTruncatedFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    uint32 SecOCTruncatedFreshnessValueLength,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2CONST(uint8, AUTOMATIC, SECOC_APPL_CONST) SecOCAuthDataFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    uint16 SecOCAuthDataFreshnessValueLength,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    uint16 SecOCAuthVerifyAttempts,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    Std_ReturnType retVal = E_OK;
    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_GetTxFreshness
*
* Explanation: This API returns the freshness value from the Most Significant
*              Bits in the first byte in the array (SecOCFreshnessValue),
*              in big endian format.
*
* param(in): SecOCFreshnessValueID: Holds the identifier of the freshness value.
* param(inout): SecOCFreshnessValueLength: Holds the length in bits of the freshness value.
* param(out): SecOCFreshnessValue: Holds the freshness value to be used for
*                                  the calculation of the authenticator.
*
* retval: BufReq_ReturnType: E_OK: request successful.
*                            E_NOT_OK: request failed, a freshness value cannot be
*                                      provided due to general issues for freshness
                                       or this FreshnessValueId.
*                            E_BUSY: The freshness information can temporarily
*                                    not be provided.
********************************************************************************
*/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_GetTxFreshness
(
    uint16 SecOCFreshnessValueID,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    Std_ReturnType retVal = E_OK;
    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_GetTxFreshnessTruncData
*
* Explanation: This interface is used by the SecOC to obtain the current freshness value.
*              The interface function provides also the truncated freshness
*              transmitted in the secured I-PDU.
*
* param(in): SecOCFreshnessValueID: Holds the identifier of the freshness value.
* param(inout): SecOCFreshnessValueLength: Holds the length of the provided freshness in bits.
* param(inout): SecOCTruncatedFreshnessValueLength: Provides the truncated freshness length
*                                                   configured for this freshness.The function
*                                                   may adapt the value if needed or can leave
*                                                   it unchanged if the configured length and
*                                                   provided length is the same.
* param(out): SecOCFreshnessValue: Holds the current freshness value.
* param(out): SecOCTruncatedFreshnessValue : Holds the truncated freshness to be included
*                                            into the Secured I-PDU. The parameter is optional.
*
* retval: BufReq_ReturnType: E_OK: request successful.
*                            E_NOT_OK: request failed, a freshness value cannot
*                                      be provided due to general issues for
*                                      freshness or this FreshnessValueId.
********************************************************************************
*/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_GetTxFreshnessTruncData
(
    uint16 SecOCFreshnessValueID,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2CONST(uint32, AUTOMATIC, SECOC_APPL_CONST) SecOCFreshnessValueLength,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2CONST(uint32, AUTOMATIC, SECOC_APPL_CONST) SecOCTruncatedFreshnessValueLength  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    Std_ReturnType retVal = E_OK;
    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_SPduTxConfirmation
*
* Explanation: This interface is used by the SecOC to indicate that the
*              Secured I-PDU has been initiated for transmission.
*
* param(in): SecOCFreshnessValueID: Holds the identifier of the freshness value.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
FUNC(void, SECOC_CODE) SecOC_SPduTxConfirmation(uint16 SecOCFreshnessValueID)
{
    return;
}

#else
/*
********************************************************************************
* Function Name: SecOC_FreshnessManagementGetRxFreshness
*
* Explanation: SecOC uses this interface to obtain the current freshness value through Rte.
*
* param(in): SecOCFreshnessValueID: Holds the identifier of the freshness value.
* param(in): SecOCTruncatedFreshnessValue: Holds the truncated freshness value that
*                                          was contained in the Secured I-PDU.
* param(in): SecOCTruncatedFreshnessValueLength: Holds the length in bits of
*                                                the truncated freshness value.
* param(in): SecOCAuthVerifyAttempts: Holds the number of authentication verify
*                                     attempts of this PDU since the last reception.
*                                     The value is 0 for the first attempt and
*                                     incremented on every unsuccessful verification attempt.
* param(inout): SecOCFreshnessValueLength: Holds the length in bits of the freshness value.
*
* param(out): SecOCFreshnessValue: Holds the freshness value to be used for
*                                  the calculation of the authenticator.
*
* retval: BufReq_ReturnType: E_OK: request successful.
*                            E_NOT_OK: request failed, a freshness value cannot
*                                      be provided due to general issues for
*                                      freshness or this FreshnessValueId.
*                            E_BUSY: The freshness information can temporarily
*                                    not be provided.
********************************************************************************
*/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessManagementGetRxFreshness
(
    uint16 SecOCFreshnessValueID,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2CONST(uint8, AUTOMATIC, SECOC_APPL_CONST) SecOCTruncatedFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    uint32 SecOCTruncatedFreshnessValueLength,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    uint16 SecOCAuthVerifyAttempts,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    /* polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.13" */
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    /* polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.13" */
    P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    uint8 retVal = E_NOT_OK;
    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_FreshnessManagementGetRxFreshnessAuthData
*
* Explanation: This interface is used by the SecOC to obtain the current freshness
*              value through Rte..
*
* param(in): SecOCFreshnessValueID: Holds the identifier of the freshness value.
* param(in): SecOCTruncatedFreshnessValue: Holds the truncated freshness value
*                                          that was contained in the Secured I-PDU.
* param(in): SecOCTruncatedFreshnessValueLength: Holds the length in bits of the
*                                                truncated freshness value.
* param(in): SecOCAuthDataFreshnessValue: The parameter holds a part of the received,
*                                         not yet authenticated PDU.The parameter is
*                                         optional (see description)
* param(in): SecOCAuthDataFreshnessValueLength : This is the length value in bits that
*                                                holds the freshness from the authentic PDU.
*                                                The parameter is optional (see description).
* param(in): SecOCAuthVerifyAttempts: Holds the number of authentication verify
*                                     attempts of this PDU since the last reception.
*                                     The value is 0 for the first attempt and
*                                     incremented on every unsuccessful verification attempt.
* param(inout): SecOCFreshnessValueLength: Holds the length in bits of the freshness value.
*
* param(out): SecOCFreshnessValue: Holds the freshness value to be used for
*                                  the calculation of the authenticator.
*
* retval: BufReq_ReturnType: E_OK: request successful.
*                            E_NOT_OK: request failed, a freshness value
*                                      cannot be provided due to general
*                                      issues for freshness or this FreshnessValueId.
*                            E_BUSY: The freshness information can temporarily
*                                    not be provided.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule5.1" */
FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessManagementGetRxFreshnessAuthData
(
    uint16 SecOCFreshnessValueID,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2CONST(uint8, AUTOMATIC, SECOC_APPL_CONST) SecOCTruncatedFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    uint32 SecOCTruncatedFreshnessValueLength,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2CONST(uint8, AUTOMATIC, SECOC_APPL_CONST) SecOCAuthDataFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    uint16 SecOCAuthDataFreshnessValueLength,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    uint16 SecOCAuthVerifyAttempts,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    /* polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.13" */
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    /* polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.13" */
    P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    uint8 retVal = E_NOT_OK;
    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_FreshnessManagementGetTxFreshness
*
* Explanation: This API returns the freshness value from the Most Significant
*              Bits in the first byte in the array (SecOCFreshnessValue),
*              in big endian format.
*
* param(in): SecOCFreshnessValueID: Holds the identifier of the freshness value.
* param(inout): SecOCFreshnessValueLength: Holds the length in bits of the freshness value.
* param(out): SecOCFreshnessValue: Holds the freshness value to be used for
*                                  the calculation of the authenticator.
*
* retval: BufReq_ReturnType: E_OK: request successful.
*                            E_NOT_OK: request failed, a freshness value cannot be
*                                      provided due to general issues for freshness
                                       or this FreshnessValueId.
*                            E_BUSY: The freshness information can temporarily
*                                    not be provided.
********************************************************************************
*/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessManagementGetTxFreshness
(
    uint16 SecOCFreshnessValueID,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    /* polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.13" */
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    /* polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.13" */
    P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    uint8 retVal = E_NOT_OK;
    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_FreshnessManagementGetTxFreshnessTruncData
*
* Explanation: This interface is used by the SecOC to obtain the current freshness value.
*              The interface function provides also the truncated freshness
*              transmitted in the secured I-PDU.
*
* param(in): SecOCFreshnessValueID: Holds the identifier of the freshness value.
* param(inout): SecOCFreshnessValueLength: Holds the length of the provided freshness in bits.
* param(inout): SecOCTruncatedFreshnessValueLength: Provides the truncated freshness length
*                                                   configured for this freshness.The function
*                                                   may adapt the value if needed or can leave
*                                                   it unchanged if the configured length and
*                                                   provided length is the same.
* param(out): SecOCFreshnessValue: Holds the current freshness value.
* param(out): SecOCTruncatedFreshnessValue : Holds the truncated freshness to be included
*                                            into the Secured I-PDU. The parameter is optional.
*
* retval: BufReq_ReturnType: E_OK: request successful.
*                            E_NOT_OK: request failed, a freshness value cannot
*                                      be provided due to general issues for
*                                      freshness or this FreshnessValueId.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule5.1" */
FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessManagementGetTxFreshnessTruncData
(
    uint16 SecOCFreshnessValueID,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    /* polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.13" */
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2CONST(uint32, AUTOMATIC, SECOC_APPL_CONST) SecOCFreshnessValueLength,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    /* polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.13" */
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValue,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    P2CONST(uint32, AUTOMATIC, SECOC_APPL_CONST) SecOCTruncatedFreshnessValueLength  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    uint8 retVal = E_NOT_OK;
    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_FreshnessManagementSPduTxConfirmation
*
* Explanation: This interface is used by the SecOC to indicate that the
*              Secured I-PDU has been initiated for transmission through Rte..
*
* param(in): SecOCFreshnessValueID: Holds the identifier of the freshness value.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
FUNC(void, SECOC_CODE) SecOC_FreshnessManagementSPduTxConfirmation
(
    uint16 SecOCFreshnessValueID  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
)
{
}
#endif

/*
********************************************************************************
* Function Name: SecOC_VerificationStatusCallout
*
* Explanation: Service is used to propagate the status of each verification
*              attempt from the SecOC module to other modules. This service
*              can be configured such that:
*                   Only: "False" Verification Status is propagated to modules.
*                   Both: "True" and "False" Verification Status are propagated to modules.
*                   None: No Verification Status is propagated.
*
* param(in): verificationStatus: Data structure to bundle the status of a verification
*                                attempt for a specific Freshness Value and Data ID.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
FUNC(void, SECOC_CODE) SecOC_VerificationStatusCallout
(
    SecOC_VerificationStatusType verificationStatus  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
)
{
}

/*
********************************************************************************
* Function Name: SecOC_VerifyByDefaultCode
*
* Explanation: Verification by default code.
*
* param(in): AuthInfo: Pointer to authentication information, which consists of 
*                      freshness value (or part thereof) and authenticator (or part thereof).
*            AuthInfoleng: Length of authentication information.
*            SecOCTruncatedFreshnessValueLength: Holds the length in bits of
*                                                the truncated freshness value.
*            SecOCAuthInfoTruncLength: Contains the MAC length in BITS to be verified.
* param(inout): None
* param(out): None
*
* retval: E_OK: Message Verification succeeded.
*         E_NOT_OK: Message Verification failed.
********************************************************************************
*/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_VerifyByDefaultCode
(
    /* polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.13" */
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) AuthInfo,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    uint32 AuthInfoleng,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    uint32 SecOCTruncatedFreshnessValueLength,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    uint32 SecOCAuthInfoTruncLength  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    uint8 retVal = E_NOT_OK;
    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_AuthenticationByDefaultCode
*
* Explanation: Authentication by default code.
*
* param(in): SecOCTruncatedFreshnessValueLength: Holds the length in bits of
*                                                the truncated freshness value.
*            SecOCAuthInfoTruncLength: Contains the MAC length in Bits to be verified.

* param(inout): None
* param(out): AuthInfo: Pointer to authentication information, which consists of 
*                      freshness value (or part thereof) and authenticator (or part thereof).
*             AuthInfoleng: Length of authentication information, in bytes.
*
* retval: * retval: E_OK: Message authentication succeeded.
*         E_NOT_OK: Message authentication failed.
********************************************************************************
*/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_AuthenticationByDefaultCode
(
    /* polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.13" */
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) AuthInfo,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    /* polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.13" */
    P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) AuthInfoleng,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    uint32 SecOCTruncatedFreshnessValueLength,  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
    uint32 SecOCAuthInfoTruncLength  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    uint8 retVal = E_NOT_OK;
    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_VerificationStatusService
*
* Explanation: Service is used to propagate the status of each verification
*              attempt from the SecOC module to other modules. This service
*              can be configured such that:
*                   Only: "False" Verification Status is propagated to modules.
*                   Both: "True" and "False" Verification Status are propagated to modules.
*                   None: No Verification Status is propagated.
*
* param(in): verificationStatus: Data structure to bundle the status of a verification
*                                attempt for a specific Freshness Value and Data ID.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
FUNC(void, SECOC_CODE) SecOC_VerificationStatusService
(
    SecOC_VerificationStatusType verificationStatus  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
)
{
}

/*
********************************************************************************
* Function Name: SecOC_VerificationStatusIndication
*
* Explanation: Service is used to propagate the status of each verification
*              attempt from the SecOC module to other modules. This service
*              can be configured such that:
*                   Only: "False" Verification Status is propagated to modules.
*                   Both: "True" and "False" Verification Status are propagated to modules.
*                   None: No Verification Status is propagated.
*
* param(in): verificationStatus: Data structure to bundle the status of a verification
*                                attempt for a specific Freshness Value and Data ID.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
FUNC(void, SECOC_CODE) SecOC_VerificationStatusIndication
(
    SecOC_VerificationStatusType verificationStatus  /* PRQA S 3206 */ /* NSCA_QAC_Common_Rule2.7 */
)
{
}

/* polyspace-end DEFECT:UNUSED_PARAMETER [Justified:Unset] "NSCA_Polyspace_SecOC_UNUSED_PARAMETER" */
/* polyspace-end MISRA-C3:2.7 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule2.7" */
#define SECOC_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


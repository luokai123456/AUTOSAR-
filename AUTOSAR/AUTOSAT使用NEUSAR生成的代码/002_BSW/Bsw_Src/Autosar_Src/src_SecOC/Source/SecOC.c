/*
********************************************************************************
*
*  File name: SecOC.c
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2020.05.09
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: yong.zhang/2020.10.29
* Change: 1.delete test code. 2.add get version function.
* Cause: Optimization
********************************************************************************
* Version: 3.1
* Author/Date: yong.zhang/2020.10.30
* Change: 1.add FUNC. 2.add memmap.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: yong.zhang/2020.11.09
* Change: 1.Judge PDU Id. 2.Judge parameter null pointer.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: yong.zhang/2020.11.19
* Change: 1.add rx fv and verify function.2.fix bug.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: yong.zhang/2020.11.20
* Change: Remove warning when compile.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: yong.zhang/2021.07.15
* Change: 1.In function SecOC_GenerateAuthenticator, macBufLen should initiate.
*        2.Standard function add judge of initial.
*        3.#include "Det.h"
*        4.In function SecOC_TpTxConfirmation, call PduR_SecOCIfTxConfirmation.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: FangT/2021.08.05
* Change:1.The SecOC_MainFunctionTx function increases the sending data buffer.
*        2.Improve the processing before SecOC_Verify_MACUsingCSM received
*           data authentication.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: FangT/2021.08.23
* Change:1.Add PduR_SecOC.h header file.
*        2.Modify SecOC_TxConfirmation to be compatible with version 4.2.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: FangT/2021.08.27
* Change:1.Modify Pduid of PduR_SecOCTransmit.
*        2.Modify Pduid of PduR_SecOCRxIndication.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: FangT/2021.08.30
* Change: Modify the Pduid parameter in PduR_SecOCTransmit.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: FangT/2021.09.01
* Change: Eliminate compilation warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: FangT/2021.09.17
* Change: Modify PduR_SecOCIfTxConfirmation input parameters.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: FangT/2021.09.29
* Change: PduR_SecOCIfTxConfirmation changed to version 4.4.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: FangT/2021.09.30
* Change: SecOC_TpTxConfirmation changed to version 4.4.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date: FangT/2021.09.30
* Change: Modify the problem of uploading data after authentication failed.
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date: FangT/2021.10.28
* Change: Modify the code header file specification.
* Cause: Optimization
********************************************************************************
* Version: 3.16
* Author/Date: FangT/2021.10.29
* Change: Modify coding style.
* Cause: Optimization
********************************************************************************
* Version: 3.17
* Author/Date: FangT/2021.11.1
* Change: Modify coding style.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: FangT/2022.08.09
* Change: Modify SecOC_Getfvfromcallout and SecOC_ Copyfvtobuffer code logic
*         improves the receiving authentication function.
* Cause: Optimization
********************************************************************************
* Version: 3.19
* Author/Date: FangT/2022.11.16
* Change: 1.Support Tp transmission function.
*         2.Support PduCollection.
*         3.Add Dem verification fault.
*         4.Add default code function.
* Cause: Optimization
********************************************************************************
* Version: 3.20
* Author/Date: FangT/2022.11.25
* Change: Back to version 3.18.
* Cause: Optimization
********************************************************************************
* Version: 3.21
* Author/Date: FangT/2022.12.12
* Change: 1.Add Dem verification fault.
*         2.Add default code function.
* Cause: Optimization
********************************************************************************
* Version: 3.22
* Author/Date: FangT/2022.12.21
* Change: Clear compilation warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date: FangT/2022.12.23
* Change: Modify the wrong judgment conditions SECOC_E_FRESHNESS_FAILED.
* Cause: Bugfix
********************************************************************************
* Version: 3.24
* Author/Date: FangT/2022.12.27
* Change: Clear QAC static code check warning problems above level 4.
* Cause: Optimization
********************************************************************************
* Version: 3.25
* Author/Date: FangT/2022.12.28
* Change: Clear the polyspace red warning.
* Cause: Optimization
********************************************************************************
* Version: 3.26
* Author/Date: FangT/2022.12.28
* Change: txSecuredPduId type is modified to uint16.
* Cause: Optimization
********************************************************************************
* Version: 3.27
* Author/Date: FangT/2023.01.31
* Change: 1.Modify the length of the Authenticator copy.
*         2.Delete unused variables.
* Cause: Optimization
********************************************************************************
* Version: 3.28
* Author/Date: FangT/2023.02.07
* Change: Eliminate compilation warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.29
* Author/Date: FangT/2023.03.01
* Change: 1.Adapt Rte function.
*         2.Solve the problem of message stop after Busoff.
*         3.When a recoverability error occurs during validation, re-acquire Fv.
* Cause: Optimization
********************************************************************************
* Version: 3.30
* Author/Date: FangT/2023.03.05
* Change: Optimize code clearing QAC 16.3 warning.
* Cause: Optimization
********************************************************************************
* Version: 3.31
* Author/Date: FangT/2023.03.07
* Change: Adapt Rte function,remove redundant macro switch.
* Cause: Optimization
********************************************************************************
* Version: 3.32
* Author/Date: FangT/2023.03.07
* Change: Adapt Rte function,remove redundant macro switch.
* Cause: Optimization
********************************************************************************
* Version: 3.33
* Author/Date: FangT/2023.04.20
* Change: Add SecOC enable and disable functions.
* Cause: Optimization
********************************************************************************
* Version: 3.34
* Author/Date: FangT/2023.04.21
* Change: Optimize code clearing QAC 8.3 warning.
* Cause: Optimization
********************************************************************************
* Version: 3.35
* Author/Date: ZhangF/2024.7.4
* Change: Add the async process for the Csm job.
* Cause: New
********************************************************************************
* Version: 3.36
* Author/Date: ZhangF/2024.7.12
* Change: 1.Optimize the async process for the Csm job.
*         2.Add the attempt operation in the async process.
*         3.Each verifyPtr value of rx pdu must qeual to CRYPTO_E_VER_OK that
*           can determine that the verify is successful.
* Cause: Optimization
********************************************************************************
* Version: 3.37
* Author/Date: TianSL/2024.7.15
* Change: 1.Add Memmap segment definition.
*         2.Modify copyright.
* Cause: Optimization
********************************************************************************
* Version: 3.38
* Author/Date: ZhangF/2024.7.15
* Change: The DataId also need to be included into the authData buffer for 
*         caculation when the message type is a sync message.
* Cause: Bugfix
********************************************************************************
* Version: 3.39
* Author/Date: ZhangF/2024.8.30
* Change: Message need to be sent in SecOC_MainFunction after using the SetMode
*         interface.
* Cause: Bugfix
********************************************************************************
* Version: 3.40
* Author/Date: TianSL/2024.9.3
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.41
* Author/Date: TianSL/2024.9.11
* Change: Fix the bug of asynchronous service receiving message,
*         SecOC_CsmMacVerifiyCallback should assign values to freshnessValueID
*         and secOCDataId.
* Cause: Bugfix
********************************************************************************
* Version: 3.42
* Author/Date: TianSL/2024.9.13
* Change: Fix MAC Verify failure when not in complete bytes.
* Cause: Bugfix
********************************************************************************
* Version: 3.43
* Author/Date: TianSL/2024.9.18
* Change: SecOC transmits the verified state to other modules.
* Cause: Optimization
********************************************************************************
* Version: 3.44
* Author/Date: TianSL/2024.10.11
* Change: Modify coding specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.45
* Author/Date: TianSL/2024.10.16
* Change: SecOC transmits the verified state to other modules.
* Cause: Optimization
********************************************************************************
* Version: 3.46
* Author/Date: TianSL/2024.12.02
* Change: Fix the issue of authpdubuf pointer out of bounds when switching back 
*         and forth between SecOC_Mode.
* Cause: Optimization
********************************************************************************
* Version: 3.47
* Author/Date: TianSL/2025.2.28
* Change: Fix the issue where the verification status does not reflect the 
*         actual authentication result when checking SecOCIgnoreVerifiationResult.
* Cause: Optimization
********************************************************************************
* Version: 3.48
* Author/Date: TianSL/2025.3.12
* Change: Modify SecOC_MainFunction_Tx and SecOC_MainFunction_Rx for
*         performance optimization.
* Cause: Optimization
********************************************************************************
* Version: 3.49
* Author/Date: TianSL/2025.3.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.50
* Author/Date: TianSL/2025.4.11
* Change: Fix compilation errors caused by duplicate definitions of Rte.
* Cause: Bugfix
********************************************************************************
* Version: 3.51
* Author/Date: TianSL/2025.5.12
* Change: SecOC_SetMode and SecOC_GetVersionInfo implement the ability to 
*         report DTCs to Dem when SecOC is uninitialized.
* Cause: Bugfix
********************************************************************************
* Version: 3.52
* Author/Date: TianSL/2025.5.14
* Change: 1.Add the functionality to enable default code verification
*           when SecOC SetMode is set to OFF.
*         2.Add the functionality to clear DTCs after all RxPdu validations pass.
* Cause: Optimization
********************************************************************************
* Version: 3.53
* Author/Date: TianSL/2025.5.19
* Change: Add the functionality of continuous retry for SecOC RxPdu verification.
* Cause: Optimization
********************************************************************************
* Version: 3.54
* Author/Date: TianSL/2025.5.27
* Change: Fix the issue where the transmitted PDU length is incorrect 
*         when SecOC_Mode is set to SecOC_OFF.
* Cause: Optimization
********************************************************************************
* Version: 3.55
* Author/Date: TianSL/2025.6.3
* Change: Fix MAC generation failure retry mechanism absence.
* Cause: Bugfix
********************************************************************************
* Version: 3.56
* Author/Date: TianSL/2025.6.6
* Change: Add the polyspace deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.57
* Author/Date: TianSL/2025.7.16
* Change: Add the polyspace deviation suppression comment.
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "SecOC.h"
#include "PduR_SecOC.h"
#if( SECOC_DEVERRORDETECT == STD_ON )
#include "Det.h"
#endif  /* SECOC_DEVERRORDETECT == STD_ON */

#ifdef SECOC_DEM_ENABLE 
#include "Dem.h"
#endif

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
#if ( SECOC_DEVERRORDETECT == STD_ON )
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define SecOC_ReportDetError(API_ID, ERROR_CODE) \
    ((void) Det_ReportError(SECOC_MODULE_ID, SECOC_INSTANCE_ID_DET, (API_ID), (ERROR_CODE)))
#endif  /* SECOC_DEVERRORDETECT == STD_ON */

/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define SecOC_IsTxPduStateUnauthenticated(txPduId) \
    ((SecOC_TxPduBuf[txPduId].pduState & SECOC_UNAUTHENTICATED_TXPDUSTATE) == SECOC_UNAUTHENTICATED_TXPDUSTATE)

/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define SecOC_IsRxPduStateUnverified(rxPduId) \
    ((SecOC_RxPduBuf[rxPduId].pduState & SECOC_UNVERIFIED_RXPDUSTATE) == SECOC_UNVERIFIED_RXPDUSTATE)

#if( SECOC_IMMEDIATE_RETRY == STD_ON )
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define SecOC_IsRxPduStateValid(rxPduId) \
    ( (SECOC_WAIT_CSM_JOB_PROCESS != SecOC_RxPduBuf[rxPduId].pduState) && \
    (SECOC_IDLE_RXPDUSTATE != SecOC_RxPduBuf[rxPduId].pduState) && \
    (SECOC_DEFAULTCODE_RXPDUSTATE != SecOC_RxPduBuf[rxPduId].pduState) )
#endif  /* SECOC_IMMEDIATE_RETRY == STD_ON */

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
#define SECOC_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"

/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_SecOC_UsedNonSharedVariable" */
static VAR(SecOC_StateType, SECOC_VAR_INIT) SecOCInit = SECOC_UNINIT;

/* polyspace-begin MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.9" polyspace-begin VARIABLE:* [Justified:Unset] "NSCA_Polyspace_SecOC_UsedNonSharedVariable" */
static VAR(uint32, SECOC_VAR_INIT) SecOC_MacGenJobId    = SECOC_INIT_0;  /* PRQA S 3218 */ /* NSCA_QAC_SecOC_Rule8.9 */
static VAR(uint32, SECOC_VAR_INIT) SecOC_MacGenBufLen   = SECOC_INIT_0;  /* PRQA S 3218 */ /* NSCA_QAC_SecOC_Rule8.9 */
static VAR(uint32, SECOC_VAR_INIT) SecOC_MacVerifyJobId = SECOC_INIT_0;  /* PRQA S 3218 */ /* NSCA_QAC_SecOC_Rule8.9 */
static VAR(uint32, SECOC_VAR_INIT) SecOC_MacVerifyLen   = SECOC_INIT_0;  /* PRQA S 3218 */ /* NSCA_QAC_SecOC_Rule8.9 */
/* polyspace-end MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.9" polyspace-end VARIABLE:* [Justified:Unset] "NSCA_Polyspace_SecOC_UsedNonSharedVariable" */

#if( SECOC_SETMODE == STD_ON )
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_SecOC_UsedNonSharedVariable" */
static VAR(SecOC_ModeType, SECOC_VAR_INIT) SecOC_Mode = SECOC_ON;
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_SecOC_UsedNonSharedVariable" */
static VAR(SecOC_DefaultDataType, SECOC_VAR_INIT) SecOC_DefaultData = { SECOC_INIT_0, FALSE };
#endif  /* SECOC_SETMODE == STD_ON */
#if( SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM )
static VAR(boolean, SECOC_VAR_INIT) SecOC_RxPduVerifyFailed = FALSE;
#endif  /* SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM */

#define SECOC_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define SECOC_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
static FUNC(Std_ReturnType, SECOC_CODE) SecOC_GetFVFromCallout
(
    uint16 rxPduId,
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) freshnessVerifyValue
);
static FUNC(void, SECOC_CODE) SecOC_CopyFVToBuffer
(
    uint16 rxPduId,
    P2CONST(uint8, AUTOMATIC, SECOC_APPL_DATA) freshnessVerifyValue
);
static FUNC(void, SECOC_CODE) SecOC_Verify_IncBuildAttempts(uint16 rxPduId);
static FUNC(void, SECOC_CODE) SecOC_Verify_IncAuthentictionAttempts(uint16 rxPduId);
static FUNC(Std_ReturnType, SECOC_CODE) SecOC_Verify_MACUsingCSM(uint16 rxPduId);

#if( SECOC_ENABLEFORCEDPASSOVERRIDE == STD_ON )
static FUNC(Std_ReturnType, SECOC_CODE) SecOC_GetVerifyOverrideStatus
(
    uint16 rxPduId,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, SECOC_APPL_DATA) verifyPtr,
    P2VAR(SecOC_VerificationStatusType, AUTOMATIC, SECOC_APPL_DATA) verificationStatusPtr
);
#endif  /* SECOC_ENABLEFORCEDPASSOVERRIDE == STD_ON */
static FUNC(void, SECOC_CODE) SecOC_ReceiveBufferSet
(
    uint16 rxPduId,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) PduInfoPtr
);

static FUNC(void, SECOC_CODE) SecOC_CopyDataToAuthenticator
(
    uint16 rxPduId
);
static FUNC(void, SECOC_CODE) SecOC_FailedObtainFvProcess(uint16 rxPduId);

static FUNC(void, SECOC_CODE) SecOC_PassAuthenticPDUtoUplayer(uint16 rxPduId);

#endif  /* SECOC_NUM_RXPDUPRO > SECOC_0 */

#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
static FUNC(Std_ReturnType, SECOC_CODE) SecOC_CopyTxFreshnessValues(uint16 txPduId);
static FUNC(void, SECOC_CODE) SecOC_IncAndCheckBuildAttempts(uint16 txPduId);
static FUNC(void, SECOC_CODE) SecOC_ReauthenticationNeeded(uint16 txPduId);
static FUNC(Std_ReturnType, SECOC_CODE) SecOC_GenerateAuthenticator(uint16 txPduId);

static FUNC(Std_ReturnType, SECOC_CODE) SecOC_SendSecurityPDUtoLower(uint16 txPduId);

#if( SECOC_SETMODE == STD_ON )
static FUNC(Std_ReturnType, SECOC_CODE) SecOC_TransmitWithOutAuthenticate
(
    PduIdType txPduId,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) pduInfoPtr
);
#endif  /* SECOC_SETMODE == STD_ON */

#endif  /* SECOC_NUM_TXPDUPRO > SECOC_0 */

#define SECOC_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define SECOC_START_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* [SWS_SecOC_00057] The SecOC module shall provide sufficient buffer
    capacities to store the incoming Authentic I-PDU,
    the outgoing Secured I-PDU and all intermediate data of the authentication
    process according to the process described in SWS_SecOC_00031. */
/* [SWS_SecOC_00146] The SecOC module shall provide separate buffers
    for the Authentic I-PDU and the Secured I-PDU. */
#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_SecOC_UsedNonSharedVariable" polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.7" */
VAR(SecOC_IPDU_BufType, SECOC_VAR_NO_INIT)  SecOC_TxPduBuf[SECOC_NUM_TXPDUPRO];

#if( SECOC_TXPDUTYPE == SECOC_TPPDU )
VAR(uint8, SECOC_VAR_NO_INIT) SecOC_TpTxCopybuff[SECOC_NUM_TXPDUPRO][SECOC_64];
#endif  /* SECOC_TXPDUTYPE == SECOC_TPPDU */
#endif  /* SECOC_NUM_TXPDUPRO > SECOC_0 */

#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_SecOC_UsedNonSharedVariable" polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.7" */
VAR(SecOC_IPDU_BufType, SECOC_VAR_NO_INIT) SecOC_RxPduBuf[SECOC_NUM_RXPDUPRO];
#endif  /* SECOC_NUM_RXPDUPRO > SECOC_0 */

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_SecOC_UsedNonSharedVariable" polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.7" */
VAR(SecOC_TxPduBuffer_st, SECOC_VAR_NO_INIT) SecOC_TxPduBuffer;
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_SecOC_UsedNonSharedVariable" polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.7" */
VAR(SecOC_RxPduBuffer_st, SECOC_VAR_NO_INIT) SecOC_RxPduBuffer;

#define SECOC_STOP_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define SECOC_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
* Function Name: SecOC_GetFVFromCallout
*
* Explanation: Get FressValue From Callout Function.
*
* param(in): rxPduId: received pdu id.
* param(inout): freshnessVerifyValue: A pointer to the start address of Fv.
* param(out): None
*
* retval: Std_ReturnType
********************************************************************************
*/

#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
static FUNC(Std_ReturnType, SECOC_CODE) SecOC_GetFVFromCallout
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    uint16 rxPduId,
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) freshnessVerifyValue
)
{
    Std_ReturnType retVal = E_OK;
    /* polyspace-begin DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    const uint8 *truncatedFV = &SecOC_RxPduBuf[rxPduId].cryptoPduBuf[SECOC_0];
    uint16 SecOCFreshnessValueID = SecOCRxPduProcessingIns[rxPduId].SecOCFreshnessValueId;
    uint16 SecOCAuthVerifyAttempts = SecOC_RxPduBuf[rxPduId].attempCounter;
    uint32 SecOCTruncatedFreshnessValueLength = SecOCRxPduProcessingIns[rxPduId].SecOCFreshnessValueTruncLength;
    /* polyspace-end DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    uint32 SecOCFreshnessValueLength = SecOCRxPduProcessingIns[rxPduId].SecOCFreshnessValueLength;

#if( SECOC_QUERYFRESHNESSVALUE == SECOC_CFUNC )

    if( SECOC_IDLE_RXPDUSTATE != SecOC_RxPduBuf[rxPduId].pduState )
    {
        if( FALSE == SecOCRxPduProcessingIns[rxPduId].SecOCUseAuthDataFreshness )
        {
            retVal = SecOC_GetRxFreshness(SecOCFreshnessValueID,
                                          &truncatedFV[SECOC_0],
                                          SecOCTruncatedFreshnessValueLength,
                                          SecOCAuthVerifyAttempts,
                                          freshnessVerifyValue,
                                          &SecOCFreshnessValueLength);
        }
        else
        {
            retVal = SecOC_GetRxFreshnessAuthData(SecOCFreshnessValueID,
                                                  &truncatedFV[SECOC_0],
                                                  SecOCTruncatedFreshnessValueLength,
                                                  NULL_PTR,
                                                  SECOC_0,
                                                  SecOC_RxPduBuf[rxPduId].attempCounter,
                                                  freshnessVerifyValue,
                                                  &SecOCFreshnessValueLength);
        }
    }
#else

    if( SECOC_IDLE_RXPDUSTATE != SecOC_RxPduBuf[rxPduId].pduState )
    {
        if( FALSE == SecOCRxPduProcessingIns[rxPduId].SecOCUseAuthDataFreshness )
        {
            retVal = SecOC_FreshnessManagementGetRxFreshness(
                         SecOCFreshnessValueID,
                         &truncatedFV[SECOC_0],
                         SecOCTruncatedFreshnessValueLength,
                         SecOCAuthVerifyAttempts,
                         freshnessVerifyValue,
                         &SecOCFreshnessValueLength);
        }
        else
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            retVal = SecOC_FreshnessManagementGetRxFreshnessAuthData(
                         SecOCFreshnessValueID,
                         &truncatedFV[SECOC_0],
                         SecOCTruncatedFreshnessValueLength,
                         NULL_PTR,
                         SECOC_0,
                         SecOC_RxPduBuf[rxPduId].attempCounter,
                         freshnessVerifyValue,
                         &SecOCFreshnessValueLength);
        }
    }

#endif  /* SECOC_QUERYFRESHNESSVALUE == SECOC_CFUNC */

    return retVal;
}
#endif  /* SECOC_NUM_RXPDUPRO > SECOC_0 */

/*
********************************************************************************
* Function Name: SecOC_CopyFVToBuffer
*
* Explanation: Copy FressValue To datatoAuthenticator Buffer.
*
* param(in): rxPduId: Received pdu id.
*            freshnessVerifyValue: A pointer to the start address of Fv.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
static FUNC(void, SECOC_CODE) SecOC_CopyFVToBuffer
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    uint16 rxPduId,
    P2CONST(uint8, AUTOMATIC, SECOC_APPL_DATA) freshnessVerifyValue
)
{
    uint8 fvIndex = SECOC_0;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    uint8 fvLen = SecOCRxPduProcessingIns[rxPduId].SecOCFreshnessValueLength / SECOC_8;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    uint32 authdatalen = SecOC_RxPduBuf[rxPduId].authDataLen;

    for( fvIndex = SECOC_0; fvIndex < fvLen; fvIndex++ )
    {
        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" */
        SecOC_RxPduBuf[rxPduId].authData[authdatalen + fvIndex] = freshnessVerifyValue[fvIndex];
    }
    SecOC_RxPduBuf[rxPduId].authDataLen = SecOC_RxPduBuf[rxPduId].authDataLen + fvLen;

}
#endif  /* SECOC_NUM_RXPDUPRO > SECOC_0 */

/*
********************************************************************************
* Function Name: SecOC_TxPduAuthBufFill
*
* Explanation: Fill the authentication buffer according to the tx pdu index.
*
* param(in): job: The index of pdu buffer which need to be filled.
*
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
static FUNC(void, SECOC_CODE) SecOC_TxPduAuthBufFill(uint16 pduIdx)
{
    uint8 byteToWrite; 
    uint8 copyMask; 
    uint32 destIdx; 
    uint32 srcIdx = SECOC_INIT_0;
    uint32 authtruncLen;
    uint32 fvtruncLen;
    uint32 secureDataLen;
    uint32 bitsToCopy; 
    uint32 msbBitOffset;
    uint32 lsbBitOffset;
    uint32 authtruncLenBytes;
    uint32 fvtruncLenBytes;

    /* Set the basical information for auth buffer writing. */
    authtruncLen = SecOCTxPduProcessingIns[pduIdx].SecOCAuthInfoTruncLength;
    fvtruncLen = SecOCTxPduProcessingIns[pduIdx].SecOCFreshnessValueTruncLength;
    secureDataLen = SecOC_TxPduBuf[pduIdx].authpdubuflen;
    bitsToCopy = authtruncLen;
    msbBitOffset = SECOC_VALUE_8 - (bitsToCopy % SECOC_VALUE_8);
    lsbBitOffset = bitsToCopy % SECOC_VALUE_8;
    fvtruncLenBytes = fvtruncLen / SECOC_VALUE_8;

    /* Set the auth bytes length. */
    if( SECOC_VALUE_0 == (authtruncLen % SECOC_VALUE_8) )
    {
        authtruncLenBytes = authtruncLen / SECOC_VALUE_8;
    }
    else
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        authtruncLenBytes = (authtruncLen / SECOC_VALUE_8) + SECOC_VALUE_1;
    }

    /* Start the auth buffer filling. */
    for( destIdx = secureDataLen + fvtruncLenBytes; destIdx < ((secureDataLen + fvtruncLenBytes) + authtruncLenBytes); destIdx++ )
    {
        /* Bits write. */
        if( SECOC_VALUE_0 != (bitsToCopy & SECOC_VALUE_7) )
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            copyMask = (uint8)(SECOC_VALUE_255 << lsbBitOffset);
            byteToWrite = (uint8)(SecOC_TxPduBuf[pduIdx].Authenticator[srcIdx] >> msbBitOffset);
            byteToWrite = (SecOC_TxPduBuf[pduIdx].authpdubuf[destIdx] & copyMask) | byteToWrite;
            SecOC_TxPduBuf[pduIdx].authpdubuf[destIdx] = byteToWrite;
            /* polyspace +1 DEFECT:BITWISE_ARITH_MIX [Justified:Unset] "NSCA_Polyspace_SecOC_BITWISE_ARITH_MIX" */
            bitsToCopy = bitsToCopy - (bitsToCopy & SECOC_VALUE_7);
        }
        else  /* Bytes write. */
        {
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( (SECOC_VALUE_0 != lsbBitOffset ) && (SECOC_INDEX_0 != srcIdx) )
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                byteToWrite = (uint8)(SecOC_TxPduBuf[pduIdx].Authenticator[srcIdx] >> msbBitOffset);
                byteToWrite = byteToWrite | ((uint8)(SecOC_TxPduBuf[pduIdx].Authenticator[srcIdx - SECOC_INDEX_1] << lsbBitOffset));
                SecOC_TxPduBuf[pduIdx].authpdubuf[destIdx] = byteToWrite;
            }
            else
            {
                /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" */
                SecOC_TxPduBuf[pduIdx].authpdubuf[destIdx] = SecOC_TxPduBuf[pduIdx].Authenticator[srcIdx];
            }
            /* Next byte. */
            bitsToCopy = bitsToCopy - SECOC_VALUE_8;
        }
        srcIdx++;
    }

    /* Save total secure pdu length. */
    SecOC_TxPduBuf[pduIdx].authpdubuflen = secureDataLen + fvtruncLenBytes + authtruncLenBytes;
}

/*
********************************************************************************
* Function Name: SecOC_Verify_IncBuildAttempts
*
* Explanation: Verify MAC Increase Build Attempt Counter.
*
* param(in): rxPduId: received pdu id.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
static FUNC(void, SECOC_CODE) SecOC_Verify_IncBuildAttempts(uint16 rxPduId)
{

    SecOC_VerificationStatusType verifStatus;

    SecOC_RxPduBuf[rxPduId].builtAttempCnt++;
    if( SecOC_RxPduBuf[rxPduId].builtAttempCnt >= SecOCRxPduProcessingIns[rxPduId].SecOCAuthenticationBuildAttempts )
    {
#if( SECOC_ENABLEDEFAULTCODE == STD_OFF )
        SecOC_RxPduBuf[rxPduId].pduState = SECOC_IDLE_RXPDUSTATE;
        SecOC_RxPduBuf[rxPduId].authpdubuflen = SECOC_0;
        SecOC_RxPduBuf[rxPduId].cryptoPduBuflen = SECOC_0;
        
        if( SECOC_OVERRIDE_CANCEL != SecOCRxPduProcessingIns[rxPduId].SecOCRxPduOverrideStatus->SecOCOverrideStatus )
        {
            SecOC_RxPduBuf[rxPduId].pduState = SECOC_UNVERIFIED_RXPDUSTATE;
        }
#else
        SecOC_RxPduBuf[rxPduId].pduState = SECOC_DEFAULTCODE_RXPDUSTATE;
#endif  /* SECOC_ENABLEDEFAULTCODE == STD_OFF */
        /* SWS_SecOC_00240 */
        verifStatus.freshnessValueID = SecOCRxPduProcessingIns[rxPduId].SecOCFreshnessValueId;
        verifStatus.secOCDataId = SecOCRxPduProcessingIns[rxPduId].SecOCDataId;
        verifStatus.verificationStatus = SECOC_AUTHENTICATIONBUILDFAILURE;
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if( SecOCRxPduProcessingIns[rxPduId].SecOCVerificationStatusPropagationMode != SECOC_NONE )
        {
            /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            SecOC_VerificationStatusCallout(verifStatus);
            /* Verification status Service */
            /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            SecOC_VerificationStatusService(verifStatus);
            /* Verification status Indication */
            /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            SecOC_VerificationStatusIndication(verifStatus);
        }
    }
}
#endif  /* SECOC_NUM_RXPDUPRO > SECOC_0 */

/*
********************************************************************************
* Function Name: SecOC_Verify_IncAuthentictionAttempts
*
* Explanation: Verify MAC Increase Build Attempt Counter.
*
* param(in): rxPduId: received pdu id.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
static FUNC(void, SECOC_CODE) SecOC_Verify_IncAuthentictionAttempts(uint16 rxPduId)
{

    SecOC_VerificationStatusType verifStatus;

    SecOC_RxPduBuf[rxPduId].attempCounter++;
    if( SecOC_RxPduBuf[rxPduId].attempCounter >=
        SecOCRxPduProcessingIns[rxPduId].SecOCAuthenticationVerifyAttempts )
    {
#if( SECOC_ENABLEDEFAULTCODE == STD_OFF )
        SecOC_RxPduBuf[rxPduId].pduState = SECOC_IDLE_RXPDUSTATE;
        SecOC_RxPduBuf[rxPduId].authpdubuflen = SECOC_0;
        SecOC_RxPduBuf[rxPduId].cryptoPduBuflen = SECOC_0;

#if( SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM )
        /* Certification failure reports DTC failure. */
        Dem_ReportErrorStatus(SECOC_E_VERIFY_FAILED, DEM_EVENT_STATUS_FAILED);
        /* Set pduVerifyResult to E_NOT_OK and set SecOC_RxPduVerifyFailed to TRUE. */
        SecOC_RxPduBuf[rxPduId].pduVerifyResult = E_NOT_OK;
        SecOC_RxPduVerifyFailed = TRUE;
#endif  /* SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM */

#else
        SecOC_RxPduBuf[rxPduId].pduState = SECOC_DEFAULTCODE_RXPDUSTATE;
#endif  /* SECOC_ENABLEDEFAULTCODE == STD_OFF */
        verifStatus.freshnessValueID = SecOCRxPduProcessingIns[rxPduId].SecOCFreshnessValueId;
        verifStatus.secOCDataId = SecOCRxPduProcessingIns[rxPduId].SecOCDataId;
        verifStatus.verificationStatus = SECOC_VERIFICATIONFAILURE;
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if( SecOCRxPduProcessingIns[rxPduId].SecOCVerificationStatusPropagationMode != SECOC_NONE )
        {
            /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            SecOC_VerificationStatusCallout(verifStatus);
            /* Verification status Service */
            /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            SecOC_VerificationStatusService(verifStatus);
            /* Verification status Indication */
            /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            SecOC_VerificationStatusIndication(verifStatus);
        }
    }
    else
    {
        /* SWS_SecOC_00239 The authentication verify attempt counter shall be incremented
        and the authentication build counter shall be set to 0 */
        SecOC_RxPduBuf[rxPduId].builtAttempCnt = SECOC_0;
    }
}
#endif  /* SECOC_NUM_RXPDUPRO > SECOC_0 */

/*
********************************************************************************
* Function Name: SecOC_Verify_MACUsingCSM
*
* Explanation: Verify MAC Using CSM Module.
*
* param(in): rxPduId: received pdu id.
* param(inout): None
* param(out): None
*
* retval: Std_ReturnType
********************************************************************************
*/
#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
static FUNC(Std_ReturnType, SECOC_CODE) SecOC_Verify_MACUsingCSM(uint16 rxPduId)
{
    Std_ReturnType retVal = E_OK;
    uint8 macRemaindBit;
    uint16 index;
    uint32 cryptoPduLen;
    uint32 macByteNum;
    SecOC_VerificationStatusType verifStatus;

    SecOC_MacVerifyJobId= SecOCRxPduProcessingIns[rxPduId].SecOCRxAuthServiceConfigRef;
    SecOC_MacVerifyLen = SecOCRxPduProcessingIns[rxPduId].SecOCAuthInfoTruncLength;

    cryptoPduLen = SecOCRxPduProcessingIns[rxPduId].SecOCFreshnessValueTruncLength / SECOC_VALUE_8;
    macByteNum = SecOC_MacVerifyLen / SECOC_VALUE_8;
    macRemaindBit = (uint8)(SecOC_MacVerifyLen % SECOC_VALUE_8);
    verifStatus.freshnessValueID = SecOCRxPduProcessingIns[rxPduId].SecOCFreshnessValueId;
    verifStatus.secOCDataId = SecOCRxPduProcessingIns[rxPduId].SecOCDataId;

    if( SECOC_0 != macRemaindBit )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        macByteNum++;
    }
    for( index = SECOC_0; index < macByteNum; index++ )
    {
        /* Copy Mac to Authenticator. */
        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_SecOC_NIV" */
        SecOC_RxPduBuf[rxPduId].Authenticator[index] = SecOC_RxPduBuf[rxPduId].cryptoPduBuf[index + cryptoPduLen];
    }

    if( SECOC_0 != macRemaindBit )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Calculate byte Mac. */
        for(index = SECOC_INDEX_0; index < (macByteNum - SECOC_INDEX_1); index++)
        {
            /* Current byte << excess Fv bits. */
            SecOC_RxPduBuf[rxPduId].Authenticator[index] =
                SecOC_RxPduBuf[rxPduId].Authenticator[index] << (SECOC_VALUE_8 - macRemaindBit);
                /* fill in the low order MAC. */
            SecOC_RxPduBuf[rxPduId].Authenticator[index] |=
                SecOC_RxPduBuf[rxPduId].Authenticator[index + SECOC_VALUE_1] >> macRemaindBit;
        }
        /* Calculate bit Mac. */
        SecOC_RxPduBuf[rxPduId].Authenticator[macByteNum - SECOC_VALUE_1] =
                SecOC_RxPduBuf[rxPduId].Authenticator[macByteNum - SECOC_VALUE_1] << (SECOC_VALUE_8 - macRemaindBit);
    }

    /* Mac verify. */
    if( SECOC_OVERRIDE_CANCEL == SecOCRxPduProcessingIns[rxPduId].SecOCRxPduOverrideStatus->SecOCOverrideStatus )
    {
        SecOC_RxPduBuf[rxPduId].verifyPtr = CRYPTO_E_VER_NOT_OK;
        retVal = Csm_MacVerify(SecOC_MacVerifyJobId,
                       CRYPTO_OPERATIONMODE_SINGLECALL,
                       &SecOC_RxPduBuf[rxPduId].authData[SECOC_INDEX_0],
                       SecOC_RxPduBuf[rxPduId].authDataLen,
                       &SecOC_RxPduBuf[rxPduId].Authenticator[SECOC_INDEX_0],
                       SecOC_MacVerifyLen,
                       &SecOC_RxPduBuf[rxPduId].verifyPtr);
    }
    else
    {
#if( SECOC_ENABLEFORCEDPASSOVERRIDE == STD_ON )
        SecOC_RxPduBuf[rxPduId].verifyPtr = CRYPTO_E_VER_NOT_OK;
        retVal = SecOC_GetVerifyOverrideStatus(rxPduId, &SecOC_RxPduBuf[rxPduId].verifyPtr, &verifStatus);
#else
        retVal = E_NOT_OK;
#endif  /* SECOC_ENABLEFORCEDPASSOVERRIDE == STD_ON */
    }

    /* Csm Job sync process */
    if( ((CRYPTO_PROCESSING_ASYNC != SecOCRxPduProcessingIns[rxPduId].SecOCRxAuthServiceProcType)
#if( SECOC_ENABLEFORCEDPASSOVERRIDE == STD_ON )
         || (SECOC_OVERRIDE_CANCEL != SecOCRxPduProcessingIns[rxPduId].SecOCRxPduOverrideStatus->SecOCOverrideStatus)
#endif  /* SECOC_ENABLEFORCEDPASSOVERRIDE == STD_ON */
        ) && (((E_OK == retVal) && (CRYPTO_E_VER_OK == SecOC_RxPduBuf[rxPduId].verifyPtr)) ||  (SECOC_IGNOREVERIFICATIONRESULT == TRUE)) )
    {
        /* Set the pdu state to SECOC_VERIFY_FINISHED_RXPDUSTATE */
        SecOC_RxPduBuf[rxPduId].pduState = SECOC_VERIFY_FINISHED_RXPDUSTATE;
        if( (E_OK == retVal) && (CRYPTO_E_VER_OK == SecOC_RxPduBuf[rxPduId].verifyPtr) )
        {
            verifStatus.verificationStatus = SECOC_VERIFICATIONSUCCESS;
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( SecOCRxPduProcessingIns[rxPduId].SecOCVerificationStatusPropagationMode == SECOC_BOTH )
            {
                /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                SecOC_VerificationStatusCallout(verifStatus);
                /* Verification status Service */
                /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                SecOC_VerificationStatusService(verifStatus);
                /* Verification status Indication */
                /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                SecOC_VerificationStatusIndication(verifStatus);
            }
        }
        else
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            verifStatus.verificationStatus = SECOC_VERIFICATIONFAILURE;
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if(SecOCRxPduProcessingIns[rxPduId].SecOCVerificationStatusPropagationMode != SECOC_NONE)
            {
                /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                SecOC_VerificationStatusCallout(verifStatus);
                /* Verification status Service */
                /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                SecOC_VerificationStatusService(verifStatus);
                /* Verification status Indication */
                /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                SecOC_VerificationStatusIndication(verifStatus);
            }
        }
    }
    /* polyspace +2 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    else if( (CRYPTO_PROCESSING_ASYNC == SecOCRxPduProcessingIns[rxPduId].SecOCRxAuthServiceProcType) &&
             (E_OK == retVal) )/* Csm Job async process */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Set the pdu state to SECOC_WAIT_CSM_JOB_PROCESS */
        SecOC_RxPduBuf[rxPduId].pduState = SECOC_WAIT_CSM_JOB_PROCESS;
    }
    else if( (E_NOT_OK == retVal) || (CRYPTO_E_KEY_NOT_VALID == retVal) )
    {
#if( SECOC_ENABLEDEFAULTCODE == STD_OFF )
        /* CSM returned none recoverable return value */
        SecOC_RxPduBuf[rxPduId].pduState = SECOC_IDLE_RXPDUSTATE;
        SecOC_RxPduBuf[rxPduId].authpdubuflen = SECOC_VALUE_0;
        SecOC_RxPduBuf[rxPduId].cryptoPduBuflen = SECOC_VALUE_0;
        /* SECOC_E_VERIFY_FAILED */
#if( SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM )
        Dem_ReportErrorStatus(SECOC_E_VERIFY_FAILED, DEM_EVENT_STATUS_FAILED);
        /* Set pduVerifyResult to E_NOT_OK and set SecOC_RxPduVerifyFailed to TRUE. */
        SecOC_RxPduBuf[rxPduId].pduVerifyResult = E_NOT_OK;
        SecOC_RxPduVerifyFailed = TRUE;
#endif  /* SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM */

#else
        SecOC_RxPduBuf[rxPduId].pduState = SECOC_DEFAULTCODE_RXPDUSTATE;
#endif  /* SECOC_ENABLEDEFAULTCODE == STD_OFF */
        verifStatus.verificationStatus = SECOC_VERIFICATIONFAILURE;
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if( SecOCRxPduProcessingIns[rxPduId].SecOCVerificationStatusPropagationMode != SECOC_NONE )
        {
            /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            SecOC_VerificationStatusCallout(verifStatus);
            /* Verification status Service */
            /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            SecOC_VerificationStatusService(verifStatus);
            /* Verification status Indication */
            /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            SecOC_VerificationStatusIndication(verifStatus);
        }
    }
    else
    {
        /* CSM returned recoverable return value SWS_SecOC_00237 */
        SecOC_RxPduBuf[rxPduId].pduState = SECOC_FV_NEEDED_RXPDUSTATE;
        SecOC_Verify_IncBuildAttempts(rxPduId); 
    }

    return retVal;
}
#endif  /* SECOC_NUM_RXPDUPRO > SECOC_0 */

/*
********************************************************************************
* Function Name: SecOC_CopyTxFreshnessValues
*
* Explanation: This function used for copy tx freshness value.
*
* param(in): id: txPduId: tx pdu id.
* param(inout): None
* param(out): None
*
* retval: Std_ReturnType
********************************************************************************
*/
#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
static FUNC(Std_ReturnType, SECOC_CODE) SecOC_CopyTxFreshnessValues(uint16 txPduId)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint8 freshValueLoop;
    uint8 fvByteLen;
    uint8 tfvByteLen;
    uint8 byteToCopy;
    uint8 bitOffset;
    uint8 copyMask;
    uint32 srcValueIdx;
    uint32 iterValue;
    uint32 fvAuthIdx;
    uint32 bitsToCopy = SecOCTxPduProcessingIns[txPduId].SecOCFreshnessValueTruncLength;
    uint32 freshValueLen = SecOCTxPduProcessingIns[txPduId].SecOCFreshnessValueLength;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    uint32 securePduLen = SecOC_TxPduBuf[txPduId].authpdubuflen;
    uint32 firstByteShift = SECOC_0;
    uint32 secondByteShift = SECOC_0;
    uint8 freshnessValue[SECOC_32]= {SECOC_0};
    uint8 truncFreshValue[SECOC_32] = {SECOC_0};

    if( SECOC_0 == (bitsToCopy % SECOC_8) )
    {
        srcValueIdx = (bitsToCopy / SECOC_8) - SECOC_1;
        tfvByteLen = (uint8)(bitsToCopy / SECOC_8);
    }
    else
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        srcValueIdx = bitsToCopy / SECOC_8;
        tfvByteLen = (uint8)(bitsToCopy / SECOC_8) + SECOC_1;
        firstByteShift = SECOC_8 - (bitsToCopy % SECOC_8);
        secondByteShift = bitsToCopy % SECOC_8;
    }

    iterValue = securePduLen + srcValueIdx;

#if( SECOC_QUERYFRESHNESSVALUE == SECOC_CFUNC )

    /* [SWS_SecOC_00221] If SecOCQueryFreshnessValue =
        CFUNC AND SecOCProvideTxTruncatedFreshnessValue= TRUE
        for a PDU configuration, the SecOC calls the interface
        function SecOC_GetTxFreshnessTruncData whenever the
        DataToAuthenticator is constructed for the respective PDU.*/
    if( TRUE == SecOCTxPduProcessingIns[txPduId].SecOCProvideTxTruncatedFreshnessValue )
    {
        retVal = SecOC_GetTxFreshnessTruncData(SecOCTxPduProcessingIns[txPduId].SecOCFreshnessValueId,
                    &freshnessValue[SECOC_0],
                    (const uint32*)&SecOCTxPduProcessingIns[txPduId].SecOCFreshnessValueLength,
                    &truncFreshValue[SECOC_0],
                    (const uint32*)&SecOCTxPduProcessingIns[txPduId].SecOCFreshnessValueTruncLength);
    }
    else
    {
        /* [SWS_SecOC_00222] If SecOCQueryFreshnessValue = CFUNC AND
            SecOCProvideTxTruncatedFreshnessValue= FALSE
            for a PDU configuration, the SecOC calls the interface
            function SecOC_GetTxFreshness whenever the
            DataToAuthenticator is constructed for the respective PDU. */
        retVal = SecOC_GetTxFreshness( SecOCTxPduProcessingIns[txPduId].SecOCFreshnessValueId,
                    &freshnessValue[SECOC_0],
                    &freshValueLen );
        /* [SWS_SecOC_00094] If the parameter SecOCFreshnessValueTruncLength
            is configured to a smaller length than the actual freshness value,
            SecOC shall include only the least significant bits of the freshness
            value up to SecOCFreshnessValueTruncLength within the secured I-PDU. */
        if( E_OK == retVal )
        {
            fvByteLen = (uint8)(freshValueLen / SECOC_8);
            for( freshValueLoop = tfvByteLen; freshValueLoop > SECOC_0; freshValueLoop-- )
            {
                truncFreshValue[freshValueLoop - SECOC_1] = freshnessValue[fvByteLen - SECOC_1];
                fvByteLen--;
            }
        }
    }
#else
    /* [SWS_SecOC_00223] If SecOCQueryFreshnessValue = RTE AND
        SecOCProvideTxTruncatedFreshnessValue= TRUE for a PDU
        configuration, the SecOC calls the service operation
        SecOC_FreshnessManagementGetTxFreshnessTruncData whenever
        the DataToAuthenticator is constructed for the respective PDU. */
    if( TRUE == SecOCTxPduProcessingIns[txPduId].SecOCProvideTxTruncatedFreshnessValue )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        retVal = SecOC_FreshnessManagementGetTxFreshnessTruncData(
                    SecOCTxPduProcessingIns[txPduId].SecOCFreshnessValueId,
                    &freshnessValue[SECOC_0],
                    (const uint32*)&SecOCTxPduProcessingIns[txPduId].SecOCFreshnessValueLength,
                    &truncFreshValue[SECOC_0],
                    (const uint32*)&SecOCTxPduProcessingIns[txPduId].SecOCFreshnessValueTruncLength);
    }
    else
    {
        /* [SWS_SecOC_00224] If SecOCQueryFreshnessValue = RTE AND
           SecOCProvideTxTruncatedFreshnessValue= FALSE for a PDU
           configuration, the SecOC calls the service operation
           FreshnessManagement_GetTxFreshness whenever the DataToAuthenticator
           is constructed for the respective PDU. */
        retVal = SecOC_FreshnessManagementGetTxFreshness(
                     SecOCTxPduProcessingIns[txPduId].SecOCFreshnessValueId,
                     &freshnessValue[SECOC_0],
                     &freshValueLen);
        /* polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule14.3" */
        if( E_OK == retVal )
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            fvByteLen = (uint8)(freshValueLen / SECOC_8);
            for( freshValueLoop = tfvByteLen; freshValueLoop > SECOC_0; freshValueLoop-- )
            {
                truncFreshValue[freshValueLoop - SECOC_1] = freshnessValue[fvByteLen - SECOC_1];
                fvByteLen--;
            }
        }
    }
#endif  /* SECOC_QUERYFRESHNESSVALUE == SECOC_CFUNC */

    /* polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule14.3" */
    if( E_OK == retVal )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Construct DataToAuthenticator. */
        for( fvAuthIdx = SECOC_0; fvAuthIdx < (freshValueLen / SECOC_8); fvAuthIdx++ )
        {
            SecOC_TxPduBuf[txPduId].authData[SecOC_TxPduBuf[txPduId].authDataLen + fvAuthIdx] = freshnessValue[fvAuthIdx];
        }
        SecOC_TxPduBuf[txPduId].authDataLen += freshValueLen / SECOC_8;

        /* Construct SecuredPDU. */
        for( ; iterValue >= securePduLen; iterValue-- )
        {
            if( SECOC_0 != (bitsToCopy & SECOC_7) )
            {
                bitOffset = (uint8)(bitsToCopy & SECOC_7);
                byteToCopy = (uint8)(truncFreshValue[srcValueIdx] << firstByteShift);
                copyMask = (uint8)(SECOC_255 >> secondByteShift);

                byteToCopy = (SecOC_TxPduBuf[txPduId].authpdubuf[iterValue] & copyMask) | byteToCopy;
                SecOC_TxPduBuf[txPduId].authpdubuf[iterValue] = byteToCopy;
                bitsToCopy = bitsToCopy - bitOffset;
            }
            else
            {
                byteToCopy = (uint8)(truncFreshValue[srcValueIdx] << firstByteShift);
                if( SECOC_0 != secondByteShift )
                {
                    byteToCopy = byteToCopy | (truncFreshValue[srcValueIdx + SECOC_1] >> secondByteShift);
                }
                SecOC_TxPduBuf[txPduId].authpdubuf[iterValue] = byteToCopy;
                bitsToCopy = bitsToCopy - SECOC_8;
            }
            srcValueIdx--;
        }
    }

    return retVal;
}
#endif  /* SECOC_NUM_TXPDUPRO > SECOC_0 */

/*
********************************************************************************
* Function Name: SecOC_IncAndCheckBuildAttempts
*
* Explanation: This function used for increase and check build attempt counter.
*
* param(in): id: txPduId: tx pdu id.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
static FUNC(void, SECOC_CODE) SecOC_IncAndCheckBuildAttempts(uint16 txPduId)
{
    SecOC_TxPduBuf[txPduId].attempCounter++;
    if( SecOC_TxPduBuf[txPduId].attempCounter > SecOCTxPduProcessingIns[txPduId].SecOCAuthenticationBuildAttempts )
    {
#if( SECOC_ENABLEDEFAULTCODE == STD_OFF )
        SecOC_TxPduBuf[txPduId].pduState = SECOC_INVALID_SECURED_PDU_TXPDUSTATE;
        SecOC_TxPduBuf[txPduId].txRequest = SECOC_IDLE_TRANSMITREQUEST;
#else
        SecOC_TxPduBuf[txPduId].pduState = SECOC_DEFAULT_CODE_TXPDUSTATE;
#endif  /* SECOC_ENABLEDEFAULTCODE == STD_OFF */
    }
}
#endif  /* SECOC_NUM_TXPDUPRO > SECOC_0 */

/*
********************************************************************************
* Function Name: SecOC_ReauthenticationNeeded
*
* Explanation: This function used for judge if need reauthentication and get
*              the freshness value.
*
* param(in): txPduId: tx pdu id.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
static FUNC(void, SECOC_CODE) SecOC_ReauthenticationNeeded(uint16 txPduId)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 errorId = SECOC_E_NO_ERROR;

    if( SECOC_REAUTHENTICATION_NEEDED_TXPDUSTATE == SecOC_TxPduBuf[txPduId].pduState )
    {
        ret = SecOC_CopyTxFreshnessValues(txPduId);

        /* polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule14.3" */
        if( E_OK == ret )
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            SecOC_TxPduBuf[txPduId].pduState = SECOC_TO_BE_STARTED_TXPDUSTATE;
        }
        /* polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule14.3" */
        else if( E_NOT_OK == ret )
        {
#if( SECOC_ENABLEDEFAULTCODE == STD_OFF )
            SecOC_TxPduBuf[txPduId].pduState= SECOC_INVALID_SECURED_PDU_TXPDUSTATE;
            SecOC_TxPduBuf[txPduId].txRequest = SECOC_IDLE_TRANSMITREQUEST;
            errorId = SECOC_E_FRESHNESS_FAILURE;
#else
            SecOC_TxPduBuf[txPduId].pduState= SECOC_DEFAULT_CODE_TXPDUSTATE;
#endif  /* SECOC_ENABLEDEFAULTCODE == STD_OFF */

#if( SECOC_E_FRESHNESS_FAILED != SECOC_NOUSED_DEM )
            Dem_ReportErrorStatus(SECOC_E_FRESHNESS_FAILED, DEM_EVENT_STATUS_FAILED);
#endif  /* SECOC_E_FRESHNESS_FAILED != SECOC_NOUSED_DEM */
        /* polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        }
        else
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            /* SWS_SecOC_00227 */
            SecOC_IncAndCheckBuildAttempts(txPduId);
            
            if( SecOC_TxPduBuf[txPduId].attempCounter > SecOCTxPduProcessingIns[txPduId].SecOCAuthenticationBuildAttempts )
            {
                errorId = SECOC_E_CRYPTO_FAILURE;
#if( SECOC_E_FRESHNESS_FAILED != SECOC_NOUSED_DEM )
                Dem_ReportErrorStatus(SECOC_E_FRESHNESS_FAILED, DEM_EVENT_STATUS_FAILED);
#endif  /* SECOC_E_FRESHNESS_FAILED != SECOC_NOUSED_DEM */
            }
        }
    }
    
#if( SECOC_DEVERRORDETECT == STD_ON )
    if( errorId != SECOC_E_NO_ERROR )
    {
        SecOC_ReportDetError(SECOC_SID_MAIN_FUNCTION_TX, errorId);
    }
#else
    SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */
}
#endif  /* SECOC_NUM_TXPDUPRO > SECOC_0 */

/*
********************************************************************************
* Function Name: SecOC_GenerateAuthenticator
*
* Explanation: This function used for generate authenticator.
*
* param(in): txPduId: tx pdu id.
* param(inout): None
* param(out): None
*
* retval: Std_ReturnType
********************************************************************************
*/
#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
static FUNC(Std_ReturnType, SECOC_CODE) SecOC_GenerateAuthenticator(uint16 txPduId)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = SECOC_E_NO_ERROR;

    /* Get the mac generation job id. */
    SecOC_MacGenJobId = SecOCTxPduProcessingIns[txPduId].SecOCTxAuthServiceConfigRef;
    /* Set the mac generation buffer length. */
    SecOC_MacGenBufLen = SECOC_VALUE_32;

    /* Generate the mac by Csm module. */
    retVal = Csm_MacGenerate(SecOC_MacGenJobId,CRYPTO_OPERATIONMODE_SINGLECALL,
                &SecOC_TxPduBuf[txPduId].authData[SECOC_INDEX_0],
                SecOC_TxPduBuf[txPduId].authDataLen,
                &SecOC_TxPduBuf[txPduId].Authenticator[SECOC_INDEX_0],
                &SecOC_MacGenBufLen);
    if( E_OK == retVal )
    {
        if( CRYPTO_PROCESSING_ASYNC != SecOCTxPduProcessingIns[txPduId].SecOCTxAuthServiceProcType )
        {
            /* Fill the authentication buffer of tx pdu. */
            SecOC_TxPduAuthBufFill(txPduId); 
            /* Change the tx pdu state to SECOC_AUTHENTICATED_TXPDUSTATE. */
            SecOC_TxPduBuf[txPduId].pduState = SECOC_AUTHENTICATED_TXPDUSTATE;
        }
        else
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            /* Change the tx pdu state to SECOC_WAIT_CSM_JOB_PROCESS. */
            SecOC_TxPduBuf[txPduId].pduState= SECOC_WAIT_CSM_JOB_PROCESS;
        }
    }
    else if( (E_NOT_OK == retVal) || (CRYPTO_E_KEY_NOT_VALID == retVal) )
    {
        /* SecOC authenticate failed*/
        errorId = SECOC_E_CRYPTO_FAILURE;
#if( SECOC_ENABLEDEFAULTCODE == STD_OFF )
        SecOC_TxPduBuf[txPduId].pduState= SECOC_INVALID_SECURED_PDU_TXPDUSTATE;
        SecOC_TxPduBuf[txPduId].txRequest = SECOC_IDLE_TRANSMITREQUEST;
#if( SECOC_E_AUTHENTICATE_FAILED != SECOC_NOUSED_DEM )
        Dem_ReportErrorStatus(SECOC_E_AUTHENTICATE_FAILED, DEM_EVENT_STATUS_FAILED);
#endif  /* SECOC_E_AUTHENTICATE_FAILED != SECOC_NOUSED_DEM */

#else
        SecOC_TxPduBuf[txPduId].pduState= SECOC_DEFAULT_CODE_TXPDUSTATE;
#endif  /* SECOC_ENABLEDEFAULTCODE == STD_OFF */

    }
    else
    {
        /* SWS_SecOC_00227 */
        SecOC_IncAndCheckBuildAttempts(txPduId);
        if( SecOC_TxPduBuf[txPduId].attempCounter > SecOCTxPduProcessingIns[txPduId].SecOCAuthenticationBuildAttempts )
        {
            errorId = SECOC_E_CRYPTO_FAILURE;
#if( SECOC_E_AUTHENTICATE_FAILED != SECOC_NOUSED_DEM )
            Dem_ReportErrorStatus(SECOC_E_AUTHENTICATE_FAILED, DEM_EVENT_STATUS_FAILED);
#endif  /* SECOC_E_AUTHENTICATE_FAILED != SECOC_NOUSED_DEM */
        }
        else
        {
            SecOC_TxPduBuf[txPduId].pduState = SECOC_REAUTHENTICATION_NEEDED_TXPDUSTATE;
            SecOC_TxPduBuf[txPduId].authDataLen -= SecOCTxPduProcessingIns[txPduId].SecOCFreshnessValueLength / SECOC_8;
        }
    }

#if( SECOC_DEVERRORDETECT == STD_ON )
    if( errorId != SECOC_E_NO_ERROR )
    {
        SecOC_ReportDetError(SECOC_SID_MAIN_FUNCTION_TX, errorId);
    }
#else
    SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */
    return retVal;
}
#endif  /* SECOC_NUM_TXPDUPRO > SECOC_0 */

/*
********************************************************************************
* Function Name: SecOC_GetVerifyOverrideStatus
*
* Explanation: Get the verification results after the overrideStatus value.
* param(in): rxPduId: rx pdu id.
* param(inout): verifyPtr: verification result.
*               verificationStatusPtr: Get the verification status after 
*                                      the overrideStatus value.
* param(out): None
*
* retval: E_OK: request successful.
*         E_NOT_OK: request failed.
********************************************************************************
*/
#if( SECOC_ENABLEFORCEDPASSOVERRIDE == STD_ON )
static FUNC(Std_ReturnType, SECOC_CODE) SecOC_GetVerifyOverrideStatus
(
    uint16 rxPduId,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, SECOC_APPL_DATA) verifyPtr,
    P2VAR(SecOC_VerificationStatusType, AUTOMATIC, SECOC_APPL_DATA) verificationStatusPtr
)
{

    Std_ReturnType retValue = E_OK;
    SecOC_OverrideStatusType verifyOverrideStatus = SecOCRxPduProcessingIns[rxPduId].SecOCRxPduOverrideStatus->SecOCOverrideStatus;
    switch( verifyOverrideStatus )
    {
        case SECOC_OVERRIDE_SKIP_UNTIL_LIMIT:
            *verifyPtr = CRYPTO_E_VER_OK;
            if( SECOC_0 == SecOCRxPduProcessingIns[rxPduId].SecOCRxPduOverrideStatus->SecOCNumberOfMessages )
            {
                SecOCRxPduProcessingIns[rxPduId].SecOCRxPduOverrideStatus->SecOCOverrideStatus = SECOC_OVERRIDE_CANCEL;
            }
            SecOCRxPduProcessingIns[rxPduId].SecOCRxPduOverrideStatus->SecOCNumberOfMessages--;
            verificationStatusPtr->verificationStatus = SECOC_NO_VERIFICATION;
            break;
        case SECOC_OVERRIDE_PASS_UNTIL_LIMIT:
            *verifyPtr = CRYPTO_E_VER_OK;
            if( SECOC_0 == SecOCRxPduProcessingIns[rxPduId].SecOCRxPduOverrideStatus->SecOCNumberOfMessages )
            {
                SecOCRxPduProcessingIns[rxPduId].SecOCRxPduOverrideStatus->SecOCOverrideStatus = SECOC_OVERRIDE_CANCEL;
            }
            SecOCRxPduProcessingIns[rxPduId].SecOCRxPduOverrideStatus->SecOCNumberOfMessages--;
            verificationStatusPtr->verificationStatus = SECOC_VERIFICATIONFAILURE_OVERWRITTEN;
            break;
        case SECOC_OVERRIDE_DROP_UNTIL_LIMIT:
            *verifyPtr = CRYPTO_E_VER_NOT_OK;
            if( SECOC_0 == SecOCRxPduProcessingIns[rxPduId].SecOCRxPduOverrideStatus->SecOCNumberOfMessages )
            {
                SecOCRxPduProcessingIns[rxPduId].SecOCRxPduOverrideStatus->SecOCOverrideStatus = SECOC_OVERRIDE_CANCEL;
            }
            SecOCRxPduProcessingIns[rxPduId].SecOCRxPduOverrideStatus->SecOCNumberOfMessages--;
            verificationStatusPtr->verificationStatus = SECOC_NO_VERIFICATION;
            break;
        case SECOC_OVERRIDE_DROP_UNTIL_NOTICE:
            *verifyPtr = CRYPTO_E_VER_NOT_OK;
            verificationStatusPtr->verificationStatus = SECOC_NO_VERIFICATION;
            break;
        case SECOC_OVERRIDE_PASS_UNTIL_NOTICE:
            *verifyPtr = CRYPTO_E_VER_OK;
            verificationStatusPtr->verificationStatus = SECOC_VERIFICATIONFAILURE_OVERWRITTEN;
            break;
        default:
            retValue = E_NOT_OK;
            break;

    }
    
    return retValue;
}
#endif  /* SECOC_ENABLEFORCEDPASSOVERRIDE == STD_ON */

/*
********************************************************************************
* Function Name: SecOC_ReceiveBufferSet
*
* Explanation: After receiving the data, establish a buffer to save data.
*
* param(in): rxPduId: Identifier of the PDU to be reveive.
* param(in): PduInfoPtr: A pointer to a structure with socket related
*                        data: data length and pointer to a data buffer.
* param(inout): None
* param(out): None
*
* retval:None
********************************************************************************
*/
#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
static FUNC(void, SECOC_CODE) SecOC_ReceiveBufferSet
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    uint16 rxPduId,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) PduInfoPtr
)
{
    uint32 loopIdx = SECOC_0;
    uint32 cryptoPduLen;

    cryptoPduLen = (SecOCRxPduProcessingIns[rxPduId].SecOCAuthInfoTruncLength
                   + SecOCRxPduProcessingIns[rxPduId].SecOCFreshnessValueTruncLength) / SECOC_8;
    
    if( NULL_PTR == SecOC_RxPduBuf[rxPduId].authpdubuf )
    {
        SecOC_RxPduBuf[rxPduId].authpdubuf = &SecOC_RxPduBuffer.PduBuffer[SECOC_MAX_RXSECURE_LEN - SecOC_RxPduBuffer.BufferLen];
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
        SecOC_RxPduBuffer.BufferLen = SecOC_RxPduBuffer.BufferLen - PduInfoPtr->SduLength + cryptoPduLen;

        SecOC_RxPduBuf[rxPduId].cryptoPduBuf = &SecOC_RxPduBuffer.PduBuffer[SECOC_MAX_RXSECURE_LEN - SecOC_RxPduBuffer.BufferLen];
        SecOC_RxPduBuffer.BufferLen = SecOC_RxPduBuffer.BufferLen - cryptoPduLen;    
    }
    /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
    SecOC_RxPduBuf[rxPduId].authpdubuflen = PduInfoPtr->SduLength - cryptoPduLen;
    for( loopIdx = SECOC_0; loopIdx < SecOC_RxPduBuf[rxPduId].authpdubuflen; loopIdx++ )
    {
        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" */
        SecOC_RxPduBuf[rxPduId].authpdubuf[loopIdx] = PduInfoPtr->SduDataPtr[loopIdx];
    }

    SecOC_RxPduBuf[rxPduId].cryptoPduBuflen = cryptoPduLen;
    for( loopIdx = SECOC_0; loopIdx < cryptoPduLen; loopIdx++ )
    {
        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" */
        SecOC_RxPduBuf[rxPduId].cryptoPduBuf[loopIdx] = PduInfoPtr->SduDataPtr[loopIdx + SecOC_RxPduBuf[rxPduId].authpdubuflen];
    }

}
#endif  /* SECOC_NUM_RXPDUPRO > SECOC_0 */

/*
********************************************************************************
* Function Name: SecOC_CopyDataToAuthenticator
*
* Explanation: Copy the pdu to the DataToAuthenticator buffer.
*
* param(in): rxPduId: Identifier of the PDU to be reveive.
* param(inout): None
* param(out): None
*
* retval:None
********************************************************************************
*/
#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
static FUNC(void, SECOC_CODE) SecOC_CopyDataToAuthenticator
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    uint16 rxPduId
)
{
    uint16 loopIdx = SECOC_0;
    
    if( NULL_PTR == SecOC_RxPduBuf[rxPduId].authData )
    {
        SecOC_RxPduBuf[rxPduId].authData = &SecOC_RxPduBuffer.PduBuffer[SECOC_MAX_RXSECURE_LEN - SecOC_RxPduBuffer.BufferLen]; 
        /* DataToAuthenticator = Data Identifier(2 bytes) | secured part of the Authentic I-PDU | 
           Complete Freshness Value(8 bytes) */ 
        SecOC_RxPduBuffer.BufferLen = SecOC_RxPduBuffer.BufferLen - SecOC_RxPduBuf[rxPduId].authpdubuflen - SECOC_10;
    }
    
    for( loopIdx = SECOC_0; loopIdx < SecOC_RxPduBuf[rxPduId].authpdubuflen; loopIdx++ )
    {
        /* Copy the auth data from auth pdu buffer. */
        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_SecOC_NIV" */
        SecOC_RxPduBuf[rxPduId].authData[loopIdx + SECOC_INDEX_2] = SecOC_RxPduBuf[rxPduId].authpdubuf[loopIdx];
    }
    SecOC_RxPduBuf[rxPduId].pduState = SECOC_FV_NEEDED_RXPDUSTATE;
}
#endif  /* SECOC_NUM_RXPDUPRO > SECOC_0 */

/*
********************************************************************************
* Function Name: SecOC_PassAuthenticPDUtoUplayer
*
* Explanation: Pass the authentication and transmit to the upper layer.
*
* param(in): rxPduId: Identifier of the PDU to be reveive.
* param(inout): None
* param(out): None
*
* retval:None
********************************************************************************
*/
#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
static FUNC(void, SECOC_CODE) SecOC_PassAuthenticPDUtoUplayer
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    uint16 rxPduId
)
{
    uint16 rxAuthenticId = SECOC_0;
    PduInfoType rxPduInfo;

    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( SECOC_IFPDU == SecOCRxPduProcessingIns[rxPduId].SecOCRxAuthenticPduLayer->SecOCPduType )
    {
        rxPduInfo.SduDataPtr = &(SecOC_RxPduBuf[rxPduId].authpdubuf[SECOC_0]);
        rxPduInfo.SduLength = SecOC_RxPduBuf[rxPduId].authpdubuflen;
        rxAuthenticId =
            SecOCRxPduProcessingIns[rxPduId].SecOCRxAuthenticPduLayer->SecOCRxAuthenticLayerPduRef;
        PduR_SecOCRxIndication(rxAuthenticId, &rxPduInfo);
    }
    
    SecOC_RxPduBuf[rxPduId].pduState = SECOC_IDLE_RXPDUSTATE;
    SecOC_RxPduBuf[rxPduId].authpdubuflen = SECOC_0;
    SecOC_RxPduBuf[rxPduId].cryptoPduBuflen = SECOC_0;

}
#endif  /* SECOC_NUM_RXPDUPRO > SECOC_0 */

/*
********************************************************************************
* Function Name: SecOC_PassAuthenticPDUtoUplayer
*
* Explanation: After failing to obtain Fv, perform error operation.
*
* param(in): rxPduId: Identifier of the PDU to be reveive.
* param(inout): None
* param(out): None
*
* retval:None
********************************************************************************
*/
#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
static FUNC(void, SECOC_CODE) SecOC_FailedObtainFvProcess
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    uint16 rxPduId
)
{

    SecOC_VerificationStatusType verifStatus;

    verifStatus.freshnessValueID = SecOCRxPduProcessingIns[rxPduId].SecOCFreshnessValueId;
    verifStatus.secOCDataId = SecOCRxPduProcessingIns[rxPduId].SecOCDataId;

#if( SECOC_ENABLEDEFAULTCODE == STD_OFF )
    SecOC_RxPduBuf[rxPduId].pduState = SECOC_IDLE_RXPDUSTATE;
    SecOC_RxPduBuf[rxPduId].authpdubuflen = SECOC_0;
    SecOC_RxPduBuf[rxPduId].cryptoPduBuflen = SECOC_0;

    if( SECOC_OVERRIDE_CANCEL != SecOCRxPduProcessingIns[rxPduId].SecOCRxPduOverrideStatus->SecOCOverrideStatus )
    {
        SecOC_RxPduBuf[rxPduId].pduState = SECOC_UNVERIFIED_RXPDUSTATE;
    }

#else
    SecOC_RxPduBuf[rxPduId].pduState = SECOC_DEFAULTCODE_RXPDUSTATE;
#endif  /* SECOC_ENABLEDEFAULTCODE == STD_OFF */
    /* SWS_SecOC_00240 */
    verifStatus.verificationStatus = SECOC_FRESHNESSFAILURE;
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( SecOCRxPduProcessingIns[rxPduId].SecOCVerificationStatusPropagationMode != SECOC_NONE )
    {
        /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
        SecOC_VerificationStatusCallout(verifStatus);
        /* Verification status Service */
        /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
        SecOC_VerificationStatusService(verifStatus);
        /* Verification status Indication */
        /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
        SecOC_VerificationStatusIndication(verifStatus);
    }
    /* SECOC_E_FRESHNESS_FAILED */
#if( SECOC_E_FRESHNESS_FAILED != SECOC_NOUSED_DEM )
    Dem_ReportErrorStatus(SECOC_E_FRESHNESS_FAILED, DEM_EVENT_STATUS_FAILED);
#endif  /* SECOC_E_FRESHNESS_FAILED != SECOC_NOUSED_DEM */

}
#endif  /* SECOC_NUM_RXPDUPRO > SECOC_0 */

/*
********************************************************************************
* Function Name: SecOC_SendSecurityPDUtoLower
*
* Explanation: Transfer security pdu to the low layer.
*
* param(in): txPduId: Identifier of the PDU to be transmit.
* param(inout): None
* param(out): None
*
* retval:Std_ReturnType
********************************************************************************
*/
#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
static FUNC(Std_ReturnType, SECOC_CODE) SecOC_SendSecurityPDUtoLower
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    uint16 txPduId
)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint16 txSecuredPduId = SECOC_0;
    PduInfoType securePdu = {NULL_PTR, SECOC_0};

    securePdu.SduDataPtr = &(SecOC_TxPduBuf[txPduId].authpdubuf[SECOC_0]);
    securePdu.SduLength = SecOC_TxPduBuf[txPduId].authpdubuflen;
    txSecuredPduId =
        SecOCTxPduProcessingIns[txPduId].SecOCTxSecuredPduLayer->SecOCTxSecuredPdu->SecOCTxSecuredLayerPduRef;
    retVal = PduR_SecOCTransmit(txSecuredPduId, &securePdu);

    if( (TRUE == SecOCTxPduProcessingIns[txPduId].SecOCUseTxConfirmation) &&
        (SECOC_BYPASS_TXPDUSTATE != SecOC_TxPduBuf[txPduId].pduState) )
    {
#if( SECOC_QUERYFRESHNESSVALUE == SECOC_CFUNC )
        SecOC_SPduTxConfirmation(SecOCTxPduProcessingIns[txPduId].SecOCFreshnessValueId);
#else
        /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
        SecOC_FreshnessManagementSPduTxConfirmation(SecOCTxPduProcessingIns[txPduId].SecOCFreshnessValueId);
#endif  /* SECOC_QUERYFRESHNESSVALUE == SECOC_CFUNC */
    }

    SecOC_TxPduBuf[txPduId].pduState = SECOC_TRANSMISSION_INITIATED_TXPDUSTATE;

    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_TransmitWithOutAuthenticate
*
* Explanation: Transfer security pdu to the low layer.
*
* param(in): TxPduId: Identifier of the PDU to be transmitted.
* param(in): PduInfoPtr: A pointer to a structure with socket related
*                        data: data length and pointer to a data buffer.
* param(inout): None
* param(out): None
*
* retval:Std_ReturnType
********************************************************************************
*/
#if( SECOC_SETMODE == STD_ON )
static FUNC(Std_ReturnType, SECOC_CODE) SecOC_TransmitWithOutAuthenticate
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    PduIdType txPduId,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) pduInfoPtr
)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    Std_ReturnType retVal = E_OK;
    uint16 loopIdx = SECOC_0;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    uint32 defaultValLen = (SecOCTxPduProcessingIns[txPduId].SecOCFreshnessValueTruncLength + 
                            SecOCTxPduProcessingIns[txPduId].SecOCAuthInfoTruncLength) / SECOC_VALUE_8;

    SecOC_TxPduBuf[txPduId].pduState = SECOC_BYPASS_TXPDUSTATE;
    
    if( NULL_PTR == SecOC_TxPduBuf[txPduId].authpdubuf )
    {
        SecOC_TxPduBuf[txPduId].authpdubuf = &SecOC_TxPduBuffer.PduBuffer[ SECOC_MAX_TXSECURE_LEN - SecOC_TxPduBuffer.BufferLen ];
        /* Secured I-PDU contents with truncated Freshness Counter(16 bytes),Message Linker(8 bytes)
            and truncated Authenticator(8 bytes) */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
        SecOC_TxPduBuffer.BufferLen = SecOC_TxPduBuffer.BufferLen - pduInfoPtr->SduLength - SECOC_32;
    }
    /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
    for( loopIdx = SECOC_0; loopIdx < pduInfoPtr->SduLength; loopIdx++ )
    {
        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" */
        SecOC_TxPduBuf[txPduId].authpdubuf[loopIdx] = pduInfoPtr->SduDataPtr[loopIdx];
    }
    SecOC_TxPduBuf[txPduId].authpdubuflen = pduInfoPtr->SduLength;

    if( TRUE == SecOC_DefaultData.useDefaultVal )
    {
        for( loopIdx = SECOC_INDEX_0; loopIdx < defaultValLen; loopIdx++ )
        {
            /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" */
            SecOC_TxPduBuf[txPduId].authpdubuf[(SecOC_TxPduBuf[txPduId].authpdubuflen + loopIdx)] = SecOC_DefaultData.defaultVal;
        }
    }
    else
    {
        /* Zero padding is applied as there's no user padding requirement. */
        for( loopIdx = SECOC_INDEX_0; loopIdx < defaultValLen; loopIdx++ )
        {
            /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" */
            SecOC_TxPduBuf[txPduId].authpdubuf[(SecOC_TxPduBuf[txPduId].authpdubuflen + loopIdx)] = SECOC_VALUE_0;
        }
    }
    /* Update the security PDU length. */
    SecOC_TxPduBuf[txPduId].authpdubuflen += defaultValLen;

    return retVal;
}
#endif  /* SECOC_SETMODE == STD_ON */

#endif  /* SECOC_NUM_TXPDUPRO > SECOC_0 */
/*
********************************************************************************
* Function Name: SecOC_Init
*
* Explanation: Initializes the the SecOC module. Successful initialization
*              leads to state SecOC_INIT.(Synchronous & Non Reentrant)
*
* param(in): config: Pointer to a selected configuration structure.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
FUNC(void, SECOC_CODE) SecOC_Init
(
    P2CONST(SecOC_ConfigType, AUTOMATIC, SECOC_APPL_CONST) config
)
{
    uint8 errorId = SECOC_E_NO_ERROR;
    uint16 loopIdx = SECOC_0;

    SECOC_DUMMY_STATEMENT(config);
    /* Initialize Pdu buffer. */
    SecOC_RxPduBuffer.BufferLen = SECOC_MAX_RXSECURE_LEN;
    SecOC_TxPduBuffer.BufferLen = SECOC_MAX_TXSECURE_LEN;
    
    if( SECOC_INIT == SecOCInit )
    {
        errorId = SECOC_E_INIT_FAILED;
#if( SECOC_E_INITED_FAILED != SECOC_NOUSED_DEM )
        Dem_ReportErrorStatus(SECOC_E_INITED_FAILED, DEM_EVENT_STATUS_FAILED);
#endif  /* SECOC_E_INITED_FAILED != SECOC_NOUSED_DEM */

    }
    else
    {
        /* Init Rx Pdu */
#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
        for( loopIdx = SECOC_0; loopIdx < SECOC_NUM_RXPDUPRO; loopIdx++ )
        {
            SecOC_RxPduBuf[loopIdx].builtAttempCnt = SECOC_0;
            SecOC_RxPduBuf[loopIdx].attempCounter = SECOC_0;
            SecOC_RxPduBuf[loopIdx].verifyCount = SECOC_0;
            SecOC_RxPduBuf[loopIdx].availableLen = SECOC_0;
            SecOC_RxPduBuf[loopIdx].tpAuthLength = SECOC_0;
            SecOC_RxPduBuf[loopIdx].tpCryptoLength = SECOC_0;
            SecOC_RxPduBuf[loopIdx].tpSduLength = SECOC_0;
            SecOC_RxPduBuf[loopIdx].tpSduCryptoLength = SECOC_0;
            SecOC_RxPduBuf[loopIdx].pduState = SECOC_IDLE_RXPDUSTATE;
            SecOC_RxPduBuf[loopIdx].AuthIPduLen = SecOCRxPduProcessingIns[loopIdx].authDataLen;
            SecOC_RxPduBuf[loopIdx].authData = NULL_PTR;
            SecOC_RxPduBuf[loopIdx].authpdubuf = NULL_PTR;
            SecOC_RxPduBuf[loopIdx].cryptoPduBuf = NULL_PTR;
            SecOC_RxPduBuf[loopIdx].pduVerifyResult = E_OK;
        }
#endif  /* SECOC_NUM_RXPDUPRO > SECOC_0 */
        /* Init Tx Pdu */
#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
        for( loopIdx = SECOC_0; loopIdx < SECOC_NUM_TXPDUPRO; loopIdx++ )
        {
            SecOC_TxPduBuf[loopIdx].attempCounter = SECOC_0;
            SecOC_TxPduBuf[loopIdx].pduState = SECOC_INVALID_SECURED_PDU_TXPDUSTATE;
            SecOC_TxPduBuf[loopIdx].availableLen = SECOC_0;
            SecOC_TxPduBuf[loopIdx].AuthIPduLen = SECOC_0;
            SecOC_TxPduBuf[loopIdx].tpAuthLength = SECOC_0;
            SecOC_TxPduBuf[loopIdx].tpCryptoLength = SECOC_0;
            SecOC_TxPduBuf[loopIdx].tpSduLength = SECOC_0;
            SecOC_TxPduBuf[loopIdx].tpSduCryptoLength = SECOC_0;
            SecOC_TxPduBuf[loopIdx].authData = NULL_PTR;
            SecOC_TxPduBuf[loopIdx].authpdubuf = NULL_PTR;
            SecOC_TxPduBuf[loopIdx].cryptoPduBuf = NULL_PTR;
        }
#endif  /* SECOC_NUM_TXPDUPRO > SECOC_0 */
        /* [SWS_SecOC_00054] Within SecOC_Init, the module shall initialize all
            internal global variables and the buffers of the SecOC I-PDUs. */
        SecOCInit = SECOC_INIT;
    }

#if( SECOC_DEVERRORDETECT == STD_ON )
    if( SECOC_E_NO_ERROR != errorId )
    {
        SecOC_ReportDetError(SECOC_SID_INIT, errorId);
    }
#else
    SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */
}

/*
********************************************************************************
* Function Name: SecOC_DeInit
*
* Explanation: This service stops the secure onboard communication.
*              All buffered I-PDU are removed and have to be obtained again,
*              if needed, after SecOC_Init has been called.By a call to
*              SecOC_DeInit the AUTOSAR SecOC module is put into a not
*              initialized state (SecOC_UNINIT).(Synchronous&Non Reentrant)
*
* param(in): None
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
FUNC(void, SECOC_CODE) SecOC_DeInit(void)
{

    uint16 loopIdx = SECOC_0;
    /* Init Rx Pdu */
#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
    for( loopIdx = SECOC_0; loopIdx < SECOC_NUM_RXPDUPRO; loopIdx++ )
    {
        SecOC_RxPduBuf[loopIdx].builtAttempCnt = SECOC_0;
        SecOC_RxPduBuf[loopIdx].attempCounter = SECOC_0;
        SecOC_RxPduBuf[loopIdx].verifyCount = SECOC_0;
        SecOC_RxPduBuf[loopIdx].availableLen = SECOC_0;
        SecOC_RxPduBuf[loopIdx].tpAuthLength = SECOC_0;
        SecOC_RxPduBuf[loopIdx].tpCryptoLength = SECOC_0;
        SecOC_RxPduBuf[loopIdx].tpSduLength = SECOC_0;
        SecOC_RxPduBuf[loopIdx].tpSduCryptoLength = SECOC_0;
        SecOC_RxPduBuf[loopIdx].pduState = SECOC_IDLE_RXPDUSTATE;
        SecOC_RxPduBuf[loopIdx].AuthIPduLen = SecOCRxPduProcessingIns[loopIdx].authDataLen;
        SecOC_RxPduBuf[loopIdx].authData = NULL_PTR;
        SecOC_RxPduBuf[loopIdx].authpdubuf = NULL_PTR;
        SecOC_RxPduBuf[loopIdx].cryptoPduBuf = NULL_PTR;
        SecOC_RxPduBuf[loopIdx].pduVerifyResult = E_OK;
    }
#endif  /* SECOC_NUM_RXPDUPRO > SECOC_0 */
    /* Init Tx Pdu */
#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
    for( loopIdx = SECOC_0; loopIdx < SECOC_NUM_TXPDUPRO; loopIdx++ )
    {
        SecOC_TxPduBuf[loopIdx].attempCounter = SECOC_0;
        SecOC_TxPduBuf[loopIdx].pduState = SECOC_INVALID_SECURED_PDU_TXPDUSTATE;
        SecOC_TxPduBuf[loopIdx].availableLen = SECOC_0;
        SecOC_TxPduBuf[loopIdx].AuthIPduLen = SECOC_0;
        SecOC_TxPduBuf[loopIdx].tpAuthLength = SECOC_0;
        SecOC_TxPduBuf[loopIdx].tpCryptoLength = SECOC_0;
        SecOC_TxPduBuf[loopIdx].tpSduLength = SECOC_0;
        SecOC_TxPduBuf[loopIdx].tpSduCryptoLength = SECOC_0;
        SecOC_TxPduBuf[loopIdx].authData = NULL_PTR;
        SecOC_TxPduBuf[loopIdx].authpdubuf = NULL_PTR;
        SecOC_TxPduBuf[loopIdx].cryptoPduBuf = NULL_PTR;
    }
#endif  /* SECOC_NUM_TXPDUPRO > SECOC_0 */
    SecOCInit = SECOC_UNINIT;
}

#if( SECOC_VERSIONINFOAPI == STD_ON )
/*
********************************************************************************
* Function Name: SecOC_GetVersionInfo
*
* Explanation: Returns the version information of this module.
*              (Synchronous&Reentrant)
*
* param(in): None
* param(inout): None
* param(out): versioninfo:Pointer to where to store the version information
*                         of this module.
*
* retval: None
********************************************************************************
*/
FUNC(void, SECOC_CODE) SecOC_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, SECOC_APPL_DATA) versioninfo
)
{
    /* Local Variables. */
    uint8 errorId = SECOC_E_NO_ERROR;

    /* Check module init. */
    if( SECOC_INIT != SecOCInit )
    {
        errorId = SECOC_E_UNINIT;
#if( SECOC_E_NOINITED != SECOC_NOUSED_DEM )
        /* Report SECOC_E_NOINITED to Dem. */
        Dem_ReportErrorStatus(SECOC_E_NOINITED, DEM_EVENT_STATUS_FAILED);
#endif  /* SECOC_E_NOINITED != SECOC_NOUSED_DEM */
    }
    else if( NULL_PTR == versioninfo )    /* Check that module is initialized. */
    {
        errorId = SECOC_E_PARAM_POINTER;
    }
    else
    {
        /* Return vendor ID, module ID and version data. */
        versioninfo->vendorID = (uint16)SECOC_VENDOR_ID;
        versioninfo->moduleID = (uint8)SECOC_MODULE_ID;
        versioninfo->sw_major_version = (uint8)SECOC_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)SECOC_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)SECOC_SW_PATCH_VERSION;
    }

    /* Dev error report. */
#if( SECOC_DEVERRORDETECT == STD_ON )
    if( SECOC_E_NO_ERROR != errorId )
    {
        SecOC_ReportDetError(SECOC_SID_GET_VERSION_INFO, errorId);
    }
#else
    SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */
}
#endif  /* SECOC_VERSIONINFOAPI == STD_ON */

/*
********************************************************************************
* Function Name: SecOC_IfTransmit
*
* Explanation: Requests transmission of a PDU.(Synchronous&Reentrant for
*              different PduIds. Non reentrant for the same PduId.)
*
* param(in): TxPduId: Identifier of the PDU to be transmitted.
* param(in): PduInfoPtr: A pointer to a structure with socket related
*                        data: data length and pointer to a data buffer.
* param(inout): None
* param(out): None
*
* retval: Std_ReturnType: E_OK: Transmit request has been accepted.
*                         E_NOT_OK: Transmit request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_IfTransmit
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) PduInfoPtr
)
{
    uint8 errorId = SECOC_E_NO_ERROR;
    Std_ReturnType retValue = E_NOT_OK;
    uint16 loopIdx = SECOC_0;

    if( SECOC_UNINIT == SecOCInit )
    {
        errorId = SECOC_E_UNINIT;
    }
    else if( SECOC_NUM_TXPDUPRO <= TxPduId )
    {
        errorId = SECOC_E_INVALID_PDU_SDU_ID;
    }
    else if( NULL_PTR == PduInfoPtr )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = SECOC_E_PARAM_POINTER;
    }
    else
    {
#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
#if( SECOC_SETMODE == STD_ON )
        if( SECOC_OFF == SecOC_Mode )
        {
            retValue = SecOC_TransmitWithOutAuthenticate(TxPduId, PduInfoPtr);
        }
        else
#endif  /* SECOC_SETMODE == STD_ON */
        {
            if( (SECOC_REAUTHENTICATION_NEEDED_TXPDUSTATE == SecOC_TxPduBuf[TxPduId].pduState)
                || (SECOC_AUTHENTICATED_TXPDUSTATE == SecOC_TxPduBuf[TxPduId].pduState)
                || (SECOC_TRANSMISSION_INITIATED_TXPDUSTATE == SecOC_TxPduBuf[TxPduId].pduState)
                || (SECOC_TRIGGER_TRANSMIT_TXPDUSTATE == SecOC_TxPduBuf[TxPduId].pduState) )
            {
                SecOC_TxPduBuf[TxPduId].pduState = SECOC_INVALID_SECURED_PDU_TXPDUSTATE;
            }

            if( SECOC_INVALID_SECURED_PDU_TXPDUSTATE == SecOC_TxPduBuf[TxPduId].pduState )
            {
                if( NULL_PTR == SecOC_TxPduBuf[TxPduId].authData )
                {
                    /* Reserve enough space to cache data by configuring. */
                    SecOC_TxPduBuf[TxPduId].authData = &SecOC_TxPduBuffer.PduBuffer[ SECOC_MAX_TXSECURE_LEN - SecOC_TxPduBuffer.BufferLen ];
                    /* DataToAuthenticator = Data Identifier(2 bytes) | secured part of the Authentic I-PDU | 
                       Complete Freshness Value(8 bytes) */
                    /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
                    SecOC_TxPduBuffer.BufferLen = SecOC_TxPduBuffer.BufferLen - PduInfoPtr->SduLength - SECOC_10;
                }
                if( NULL_PTR == SecOC_TxPduBuf[TxPduId].authpdubuf )
                {
                    SecOC_TxPduBuf[TxPduId].authpdubuf = &SecOC_TxPduBuffer.PduBuffer[ SECOC_MAX_TXSECURE_LEN - SecOC_TxPduBuffer.BufferLen ];
                    /* Secured I-PDU contents with truncated Freshness Counter(16 bytes),Message Linker(8 bytes)
                        and truncated Authenticator(8 bytes) */
                    /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
                    SecOC_TxPduBuffer.BufferLen = SecOC_TxPduBuffer.BufferLen - PduInfoPtr->SduLength - SECOC_32;
                }
                /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
                for( loopIdx = SECOC_0; loopIdx < PduInfoPtr->SduLength; loopIdx++ )
                {
                    /* Copy the auth data from sdu data buffer. */
                    /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" */
                    SecOC_TxPduBuf[TxPduId].authData[loopIdx + SECOC_INDEX_2] = PduInfoPtr->SduDataPtr[loopIdx];
                    /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" */
                    SecOC_TxPduBuf[TxPduId].authpdubuf[loopIdx] = PduInfoPtr->SduDataPtr[loopIdx];
                }
                SecOC_TxPduBuf[TxPduId].attempCounter = SECOC_0;
                SecOC_TxPduBuf[TxPduId].pduState = SECOC_REAUTHENTICATION_NEEDED_TXPDUSTATE;
                SecOC_TxPduBuf[TxPduId].txRequest = SECOC_TRANSMIT_TRANSMITREQUEST;
                SecOC_TxPduBuf[TxPduId].authpdubuflen = PduInfoPtr->SduLength;
                SecOC_TxPduBuf[TxPduId].AuthIPduLen = PduInfoPtr->SduLength;
                
                /* Fill the DataId into the auth data buffer */
                /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" */
                SecOC_TxPduBuf[TxPduId].authData[SECOC_INDEX_0] = (uint8)(SecOCTxPduProcessingIns[TxPduId].SecOCDataId >> SECOC_VALUE_8);
                /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" */
                SecOC_TxPduBuf[TxPduId].authData[SECOC_INDEX_1] = (uint8)SecOCTxPduProcessingIns[TxPduId].SecOCDataId;
                SecOC_TxPduBuf[TxPduId].authDataLen = PduInfoPtr->SduLength + SECOC_VALUE_2;

                retValue = E_OK;
            }
        }
#endif  /* SECOC_NUM_TXPDUPRO > SECOC_0 */

    }

#if( SECOC_DEVERRORDETECT == STD_ON )
    if(errorId != SECOC_E_NO_ERROR)
    {
        SecOC_ReportDetError(SECOC_SID_IFTRANSMIT, errorId);
    }
#else
    SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */

    return retValue;
}

/*
********************************************************************************
* Function Name: SecOC_TpTransmit
*
* Explanation: Requests transmission of a PDU.
*              (Synchronous&Reentrant for different PduIds. Non reentrant for the same PduId.)
*
* param(in): TxPduId: Identifier of the PDU to be transmitted.
* param(in): PduInfoPtr: Length of and pointer to the PDU data and pointer to MetaData.
* param(inout): None
* param(out): None
*
* retval: Std_ReturnType: E_OK: Transmit request has been accepted.
*                     E_NOT_OK: Transmit request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_TpTransmit
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) PduInfoPtr
)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    Std_ReturnType retVal = E_OK;

    /* To do */
    SECOC_DUMMY_STATEMENT(TxPduId);
    SECOC_DUMMY_STATEMENT(PduInfoPtr);

    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_CancelReceive
*
* Explanation: Requests cancellation of an ongoing reception of a PDU in a
*              lower layer transport protocol module.(Synchronous&Non Reentrant.)
*
* param(in): RxPduId: Identification of the PDU to be cancelled.
* param(inout): None
* param(out): None
*
* retval: Std_ReturnType: E_OK: Cancellation was executed successfully
*                               by the destination module.
*                         E_NOT_OK: Cancellation was rejected by the
*                                   destination module.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
FUNC(Std_ReturnType, SECOC_CODE) SecOC_CancelReceive(PduIdType RxPduId)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    Std_ReturnType retVal = E_OK;
    /* To do nothing*/
    SECOC_DUMMY_STATEMENT(RxPduId);
    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_IfCancelTransmit
*
* Explanation: Requests cancellation of an ongoing transmission of a PDU
*              in a lower layer communication module.(Synchronous&Reentrant
*              for different PduIds. Non reentrant for the same PduId.)
*
* param(in): TxPduId: Identification of the PDU to be cancelled.
* param(inout): None
* param(out): None
*
* retval: Std_ReturnType: E_OK: Cancellation was executed successfully
*                               by the destination module.
*                           E_NOT_OK: Cancellation was rejected by the
*                                     destination module.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
FUNC(Std_ReturnType, SECOC_CODE) SecOC_IfCancelTransmit(PduIdType TxPduId)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    Std_ReturnType retVal = E_OK;
    /* To do */
    SECOC_DUMMY_STATEMENT(TxPduId);
    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_TpCancelTransmit
*
* Explanation: Requests cancellation of an ongoing transmission of a
*              PDU in a lower layer communication module.
*              (Synchronous&Reentrant for different PduIds. Non reentrant for the same PduId.)
*
* param(in): TxPduId: Identification of the PDU to be cancelled.
* param(inout): None
* param(out): None
*
* retval: Std_ReturnType: E_OK: Cancellation was executed successfully
*                               by the destination module.
*                         E_NOT_OK: Cancellation was rejected by the
*                                   destination module.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
FUNC(Std_ReturnType, SECOC_CODE) SecOC_TpCancelTransmit(PduIdType TxPduId)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_SecOC_UNMODIFIED_VAR_NOT_CONST" */
    Std_ReturnType retVal = E_OK;
    /* To do */
    SECOC_DUMMY_STATEMENT(TxPduId);
    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_RxIndication
*
* Explanation: Indication of a received PDU from a lower layer communication
*              interface module.(Synchronous&Reentrant for different PduIds.
*              Non reentrant for the same PduId.)
*
* param(in): RxPduId: ID of the received PDU.
* param(in): PduInfoPtr: Contains the length (SduLength) of the received PDU,
*                        a pointer to a buffer (SduDataPtr) containing the
*                        PDU, and the MetaData related to this PDU.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
FUNC(void, SECOC_CODE) SecOC_RxIndication
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) PduInfoPtr
)
{
    uint8 errorId = SECOC_E_NO_ERROR;
    uint16 rxPduIdx = SECOC_0;
    boolean rxIndication = FALSE;
    
    if( SECOC_UNINIT == SecOCInit )
    {
        errorId = SECOC_E_UNINIT;
    }
    else if( NULL_PTR == PduInfoPtr )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = SECOC_E_PARAM_POINTER;
    }
    else
    {
        /* [SWS_SecOC_00111] Any reception process initiated from the lower
           layer communication module shall overwrite the buffer
           that contains the Secured I-PDU without affecting the
           buffer of the respective Authentic I-PDU. */
        /* [SWS_SecOC_00204] SecOC shall provide separate buffers for the
           incoming Authentic I-PDU, Cryptographic IPDU and the resulting
           Secured I-PDU. */
        /* [SWS_SecOC_00205] For each Secured I-PDU SecOC shall buffer only
           the last Authentic I-PDU and Cryptographic I-PDU it has received.
           If a buffer has already been filled with a previous IPDU,
           the previous I-PDU is overwritten. */
#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
        for( rxPduIdx = SECOC_0; rxPduIdx < SECOC_NUM_RXPDUPRO; rxPduIdx++ )
        {
            if( SecOCRxPduProcessingIns[rxPduIdx].SecOCRxSecuredPduLayer->SecOCRxSecuredPdu->SecOCRxSecuredLayerPduId == RxPduId )
            {
                SecOC_ReceiveBufferSet(rxPduIdx, PduInfoPtr);                    
                rxIndication = TRUE;
                break;
            }
        }

        if( SECOC_NUM_RXPDUPRO <= rxPduIdx )
        {
            errorId = SECOC_E_INVALID_PDU_SDU_ID;
        }
        else
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( TRUE == rxIndication )
            {
#if( SECOC_SETMODE == STD_ON )
                if( SECOC_OFF == SecOC_Mode )
                {
#if( SECOC_ENABLEDEFAULTCODE == STD_ON )
                    /* Authenticate using the default code */
                    SecOC_RxPduBuf[rxPduIdx].pduState = SECOC_DEFAULTCODE_RXPDUSTATE;
#else
                    /* Transmit to the upper layer. */
                    SecOC_PassAuthenticPDUtoUplayer(rxPduIdx);
#endif  /* SECOC_ENABLEDEFAULTCODE == STD_ON */
                }
                else
#endif  /* SECOC_SETMODE == STD_ON */
                {
                    SecOC_RxPduBuf[rxPduIdx].pduState = SECOC_COPY_AUTHENTIC_RXPDUSTATE;
                    SecOC_RxPduBuf[rxPduIdx].attempCounter = SECOC_0;
                    SecOC_RxPduBuf[rxPduIdx].builtAttempCnt = SECOC_0;
                }
            }
        }
#endif   /* SECOC_NUM_RXSECUREDPDUCOLL > SECOC_0 */

    }

#if( SECOC_DEVERRORDETECT == STD_ON )
    if( SECOC_E_NO_ERROR != errorId )
    {
        SecOC_ReportDetError(SECOC_SID_RXINDICATION, errorId);
    }
#else
    SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */

    return;
}

/*
********************************************************************************
* Function Name: SecOC_TpRxIndication
*
* Explanation: Called after an I-PDU has been received via the TP API,
*              the result indicates whether the transmission was successful
*              or not.(Synchronous&Reentrant)
*
* param(in): id: Identification of the received I-PDU.
* param(in): result: Result of the reception.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
FUNC(void, SECOC_CODE) SecOC_TpRxIndication(PduIdType id, Std_ReturnType result)
{
    SECOC_DUMMY_STATEMENT(id);
    SECOC_DUMMY_STATEMENT(result);
}

/*
********************************************************************************
* Function Name: SecOC_TxConfirmation
*
* Explanation: The lower layer communication interface module confirms the
*              transmission of a PDU, or the failure to transmit a PDU.
*              (Synchronous&Reentrant for different PduIds. Non reentrant
*              for the same PduId.)
*
* param(in): TxPduId: ID of the PDU that has been transmitted.
* param(in): result: E_OK: The PDU was transmitted.
                     E_NOT_OK: Transmission of the PDU failed.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
FUNC(void, SECOC_CODE) SecOC_TxConfirmation(PduIdType TxPduId)
{
    uint8 errorId = SECOC_E_NO_ERROR;
    uint16 upTxPduId = SECOC_0;
    uint16 txPduIdx = SECOC_0;
    boolean txConfirmation = FALSE;

    /* [SWS_SecOC_00063] If the PDU Router module notifies the SecOC module that
       the destination lower layer module has either confirmed the transmission
       of the Secured I-PDU or reported an error during transmission by calling
       SecOC_[If|Tp]TxConfirmation, the SecOC module shall pass the received result
       of the respective Authentic I-PDU to the upper layer module by calling
       PduR_SecOC[IfTp]TxConfirmation. */

    if( SECOC_UNINIT == SecOCInit )
    {
        errorId = SECOC_E_UNINIT;
    }
    else
    {
#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
        for( txPduIdx = SECOC_0; txPduIdx < SECOC_NUM_TXPDUPRO; txPduIdx++ )
        {          
            if( SecOCTxPduProcessingIns[txPduIdx].SecOCTxSecuredPduLayer->SecOCTxSecuredPdu->SecOCTxSecuredLayerPduId == TxPduId )
            {
                txConfirmation = TRUE;
                break;
            }
        }
        if( SECOC_NUM_TXPDUPRO <= txPduIdx )
        {
            errorId = SECOC_E_INVALID_PDU_SDU_ID;
        }
        else
        {
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( TRUE == txConfirmation )
            {
                upTxPduId = SecOCTxPduProcessingIns[txPduIdx].SecOCTxAuthenticPduLayer->SecOCTxAuthenticPduRef;
                PduR_SecOCIfTxConfirmation(upTxPduId, E_OK);
                switch( SecOC_TxPduBuf[txPduIdx].pduState)
                {
                    case SECOC_TRANSMISSION_INITIATED_TXPDUSTATE:
                        SecOC_TxPduBuf[txPduIdx].pduState = SECOC_INVALID_SECURED_PDU_TXPDUSTATE;
                        break;
                    case SECOC_TRIGGER_TRANSMIT_TXPDUSTATE:
                        SecOC_TxPduBuf[txPduIdx].attempCounter = SECOC_0;
                        SecOC_TxPduBuf[txPduIdx].pduState = SECOC_REAUTHENTICATION_NEEDED_TXPDUSTATE;
                        break;
                    default:
                        /* Do nothing. */
                        break;
                }
            }
        }
#endif  /* SECOC_NUM_TXPDUPRO > SECOC_0 */
    }

#if( SECOC_DEVERRORDETECT == STD_ON )
    if( errorId != SECOC_E_NO_ERROR )
    {
        SecOC_ReportDetError(SECOC_SID_TX_CONFIRMATION, errorId);
    }
#else
    SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */

    return;
}

/*
********************************************************************************
* Function Name: SecOC_TpTxConfirmation
*
* Explanation: This function is called after the I-PDU has been transmitted
*              on its network, the result indicates whether the transmission
*              was successful or not.(Synchronous&Reentrant)
*
* param(in): id: Identification of the transmitted I-PDU.
* param(in): result: Result of the transmission of the I-PDU.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
FUNC(void, SECOC_CODE) SecOC_TpTxConfirmation(PduIdType id, Std_ReturnType result)
{
    uint8 errorId = SECOC_E_NO_ERROR;
    uint16 upTxPduId = SECOC_0;
    uint16 txPduIdx = SECOC_0;
    boolean txConfirmation = FALSE;

    if( SECOC_UNINIT == SecOCInit )
    {
        errorId = SECOC_E_UNINIT;
    }
    else
    {
#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
        for( txPduIdx = SECOC_0; txPduIdx < SECOC_NUM_TXPDUPRO; txPduIdx++ )
        {
            if( SecOCTxPduProcessingIns[txPduIdx].SecOCTxSecuredPduLayer->SecOCTxSecuredPdu->SecOCTxSecuredLayerPduId == id )
            {
                txConfirmation = TRUE;
                break;
            }
        }
        if( SECOC_NUM_TXPDUPRO <= txPduIdx )
        {
            errorId = SECOC_E_INVALID_PDU_SDU_ID;
        }
        if( TRUE == txConfirmation )
        {
            upTxPduId = SecOCTxPduProcessingIns[txPduIdx].SecOCTxAuthenticPduLayer->SecOCTxAuthenticPduRef;
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( SECOC_IFPDU == SecOCTxPduProcessingIns[txPduIdx].SecOCTxAuthenticPduLayer->SecOCPduType )
            {
                PduR_SecOCIfTxConfirmation(upTxPduId, result);
            }

            if( (SECOC_TRANSMISSION_INITIATED_TXPDUSTATE == SecOC_TxPduBuf[txPduIdx].pduState)
                || (SECOC_COPYING_TXPDUSTATE == SecOC_TxPduBuf[txPduIdx].pduState) )
            {
                SecOC_TxPduBuf[txPduIdx].pduState = SECOC_INVALID_SECURED_PDU_TXPDUSTATE;
            }

            SecOC_TxPduBuf[txPduIdx].tpAuthLength = SECOC_0;
            SecOC_TxPduBuf[txPduIdx].tpCryptoLength = SECOC_0;
        }
#endif    /* SECOC_NUM_TXPDUPRO > SECOC_0 */
    }

#if( SECOC_DEVERRORDETECT == STD_ON )
    if( errorId != SECOC_E_NO_ERROR )
    {
        SecOC_ReportDetError(SECOC_SID_TP_TX_CONFIRMATION, errorId);
    }
#else
    SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */
    SECOC_DUMMY_STATEMENT(result);

    return;
}

/*
********************************************************************************
* Function Name: SecOC_TriggerTransmit
*
* Explanation: Within this API, the upper layer module (called module) shall
*              check whether the available data fits into the buffer size reported
*              by PduInfoPtr->SduLength.If it fits, it shall copy its data into
*              the buffer provided by PduInfoPtr->SduDataPtr and update the length
*              of the actual copied data in PduInfoPtr->SduLength. If not, it
*              returns E_NOT_OK without changing PduInfoPtr.
*              (Synchronous&Reentrant for different PduIds. Non reentrant for the same PduId.)
*
* param(in): TxPduId: ID of the SDU that is requested to be transmitted.
* param(inout): PduInfoPtr: Contains a pointer to a buffer (SduDataPtr) to
*                           where the SDU data shall be copied,and the available
*                           buffer size in SduLengh.On return, the service will
*                           indicate the length of the copied SDU data in SduLength.
* param(out): None
*
* retval: Std_ReturnType: E_OK: SDU has been copied and SduLength indicates
*                               the number of copied bytes.
*                         E_NOT_OK: No SDU data has been copied. PduInfoPtr
*                                   must not be used since it may contain a
*                                   NULL pointer or point to invalid data.
********************************************************************************
*/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_TriggerTransmit
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) PduInfoPtr
)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = SECOC_E_NO_ERROR;
    uint16 txPduIdx = SECOC_0;
    uint32 pduLeng = SECOC_0;
    uint32 loopIdx = SECOC_0;
    uint8 *copyedPtr = NULL_PTR;

    if( SECOC_UNINIT == SecOCInit )
    {
        errorId = SECOC_E_UNINIT;
    }
    else if( NULL_PTR == PduInfoPtr )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = SECOC_E_PARAM_POINTER;
    }
    else
    {
#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
        for( txPduIdx = SECOC_0; txPduIdx < SECOC_NUM_TXPDUPRO; txPduIdx++ )
        {
            if( SecOCTxPduProcessingIns[txPduIdx].SecOCTxSecuredPduLayer->SecOCTxSecuredPdu->SecOCTxSecuredLayerPduId == TxPduId )
            {
                pduLeng = SecOC_TxPduBuf[txPduIdx].authpdubuflen;
                copyedPtr = &SecOC_TxPduBuf[txPduIdx].authpdubuf[SECOC_0];
                break;
            }
        }
        if( (SECOC_NUM_TXPDUPRO <= txPduIdx) || 
            (SecOC_TxPduBuf[txPduIdx].pduState != SECOC_TRANSMISSION_INITIATED_TXPDUSTATE) )
        {
            errorId = SECOC_E_INVALID_PDU_SDU_ID;
        }
        else
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
            if( PduInfoPtr->SduLength >= pduLeng )
            {
                for( loopIdx = SECOC_0; loopIdx < pduLeng; loopIdx++ )
                {
                    /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_SecOC_NIV" */
                    PduInfoPtr->SduDataPtr[loopIdx] = copyedPtr[loopIdx];
                }
                SecOC_TxPduBuf[txPduIdx].pduState = SECOC_TRIGGER_TRANSMIT_TXPDUSTATE;
                PduInfoPtr->SduLength = pduLeng;
                retVal = E_OK;
            }
        }
#endif   /* SECOC_NUM_TXPDUPRO > SECOC_0 */
    }

#if( SECOC_DEVERRORDETECT == STD_ON )
    if( errorId != SECOC_E_NO_ERROR )
    {
        SecOC_ReportDetError(SECOC_SID_TRIGGER_TRANSMIT, errorId);
    }
#else
    SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */


	return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_CopyRxData
*
* Explanation: This function is called to provide the received data
*              of an I-PDU segment (N-PDU) to the upper layer.
*              Each call to this function provides the next part of
*              the I-PDU data. The size of the remaining buffer is written
*              to the position indicated by bufferSizePtr.(Synchronous&Reentrant)
*
* param(in): id: Identification of the received I-PDU.
* param(in): info: Provides the source buffer (SduDataPtr) and the number
*                  of bytes to be copied (SduLength).An SduLength of 0 can be
*                  used to query the current amount of available buffer in the
*                  upper layer module.In this case, the SduDataPtr may be a NULL_PTR.
* param(inout): None
*
* param(out): bufferSizePtr: Available receive buffer after data has been copied.
*
* retval: BufReq_ReturnType: BUFREQ_OK: Data copied successfully.
*                            BUFREQ_E_NOT_OK: Data was not copied because
*                                             an error occurred.
********************************************************************************
*/
FUNC(BufReq_ReturnType, SECOC_CODE) SecOC_CopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) info,
    P2VAR(PduLengthType, AUTOMATIC, SECOC_APPL_DATA) bufferSizePtr
)
{
    uint8 errorId = SECOC_E_NO_ERROR;
    uint16 loopIdx = SECOC_0;
    uint16 pduIndex = SECOC_0;
    uint32 copyedPduLen = SECOC_0;
    uint32 pduLength = SECOC_0;
    BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;

    if( SECOC_UNINIT == SecOCInit )
    {
        errorId = SECOC_E_UNINIT;
    }
    else if( (NULL_PTR == info) || (NULL_PTR == bufferSizePtr) )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = SECOC_E_PARAM_POINTER;
    }
    else
    {
#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
        for( pduIndex = SECOC_0; pduIndex < SECOC_NUM_RXPDUPRO; pduIndex++ )
        {
            if( SecOCRxPduProcessingIns[pduIndex].SecOCRxSecuredPduLayer->SecOCRxSecuredPdu->SecOCRxSecuredLayerPduId == id )
            {
                pduLength = SecOC_RxPduBuf[pduIndex].tpSduLength;
                copyedPduLen = SecOC_RxPduBuf[pduIndex].tpAuthLength;
                break;
            }
        }
        if( SECOC_NUM_RXPDUPRO <= pduIndex )
        {
            errorId = SECOC_E_INVALID_PDU_SDU_ID;
        }
        else
        {
            if( SECOC_COPYING_RXPDUSTATE == SecOC_RxPduBuf[pduIndex].pduState )
            {
                /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
                if( info->SduLength <= (pduLength - copyedPduLen) )
                {
                    for( loopIdx = SECOC_0; loopIdx < info->SduLength; loopIdx++ )
                    {
                        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" */
                        SecOC_RxPduBuf[pduIndex].authpdubuf[loopIdx + copyedPduLen] =
                            info->SduDataPtr[loopIdx];
                    }
                    SecOC_RxPduBuf[pduIndex].authpdubuflen += info->SduLength;
                    SecOC_RxPduBuf[pduIndex].tpAuthLength = copyedPduLen + info->SduLength;
                    /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
                    *bufferSizePtr = pduLength - copyedPduLen;
                    retVal = BUFREQ_OK;
                }
                else
                {
                    retVal = BUFREQ_E_OVFL;
                }
            }
            else
            {
                errorId = SECOC_E_INVALID_PDU_SDU_ID;
                retVal = BUFREQ_E_NOT_OK;
            }
        }
#endif   /* SECOC_NUM_RXPDUPRO > SECOC_0 */
    }

#if( SECOC_DEVERRORDETECT == STD_ON )
    if( SECOC_E_NO_ERROR != errorId )
    {
        SecOC_ReportDetError(SECOC_SID_COPY_RX_DATA, errorId);
    }
#else
    SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */

    return retVal;
}

/*
********************************************************************************
* Function Name: SecOC_CopyTxData
*
* Explanation: This function is called to acquire the transmit data of
*              an I-PDU segment (N-PDU).Each call to this function provides
*              the next part of the I-PDU data unless retry->TpDataState is
*              TP_DATARETRY.In this case the function restarts to copy the
*              data beginning at the offset from the current position indicated
*              by retry->TxTpDataCnt. The size of the remaining data is written
*              to the position indicated by availableDataPtr.(Synchronous&Reentrant)
*
* param(in): id: Identification of the transmitted I-PDU.
* param(in): info: Provides the source buffer (SduDataPtr) and the number of
*            bytes to be copied (SduLength).An SduLength of 0 can be used to
*            query the current amount of available buffer in the upper layer module.
*            In this case, the SduDataPtr may be a NULL_PTR.
* param(in): retry: This parameter is used to acknowledge transmitted data
*                   or to retransmit data after transmission problems.
* param(inout): None
*
* param(out): availableDataPtr: Indicates the remaining number of bytes
*                               that are available in the upper layer module's
*                               Tx buffer.availableDataPtr can be used by TP
*                               modules that support dynamic payload lengths(e.g.FrIsoTp)
*                               to determine the size of the following CFs.
*
* retval: BufReq_ReturnType: BUFREQ_OK: Data has been copied to the transmit
*                                       buffer completely as requested.
*                            BUFREQ_E_BUSY: Request could not be fulfilled,
*                                           because the required amount of
*                                           Tx data is not available.
*                                           The lower layer module may retry
*                                           this call later on. No data has
*                                           been copied.
*                            BUFREQ_E_NOT_OK: Data has not been copied.
*                                             Request failed.
********************************************************************************
*/
FUNC(BufReq_ReturnType, SECOC_CODE) SecOC_CopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) info,
    P2CONST(RetryInfoType, AUTOMATIC, SECOC_APPL_CONST) retry,
    P2VAR(PduLengthType, AUTOMATIC, SECOC_APPL_DATA) availableDataPtr
)
{
    /* [SWS_SecOC_00073] For transmission of Authentic I-PDUs using transport
        protocol, the SecOC module shall copy the NPDUs addressed by
        SecOC_CopyTxData into the buffer of the transport protocol module.
        After each copy process, it returns from SecOC_CopyTxData. */

    uint8 errorId = SECOC_E_NO_ERROR;
    uint16 pduIndex = SECOC_0;
    uint32 copyedPduLen = SECOC_0;
    uint32 pduLength = SECOC_0;
    uint32 loopIdx = SECOC_0;
    BufReq_ReturnType retVal = BUFREQ_OK;

    if( SECOC_UNINIT == SecOCInit )
    {
        errorId = SECOC_E_UNINIT;
        retVal = BUFREQ_E_NOT_OK;
    }
    else if( (NULL_PTR == info) || (NULL_PTR == availableDataPtr) )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = SECOC_E_PARAM_POINTER;
        retVal = BUFREQ_E_NOT_OK;
    }
    else
    {
#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
        for( pduIndex = SECOC_0; pduIndex < SECOC_NUM_TXPDUPRO; pduIndex++ )
        {
            if( SecOCTxPduProcessingIns[pduIndex].SecOCTxSecuredPduLayer->SecOCTxSecuredPdu->SecOCTxSecuredLayerPduId == id )
            {
                pduLength = SecOC_TxPduBuf[pduIndex].authpdubuflen;
                copyedPduLen = SecOC_TxPduBuf[pduIndex].tpAuthLength;
                break;
            }
        }
        if( SECOC_NUM_TXPDUPRO <= pduIndex )
        {
            errorId = SECOC_E_INVALID_PDU_SDU_ID;
            retVal = BUFREQ_E_NOT_OK;
        }
        else
        {
            if( SECOC_TRANSMISSION_INITIATED_TXPDUSTATE == SecOC_TxPduBuf[pduIndex].pduState )
            {
                SecOC_TxPduBuf[pduIndex].pduState = SECOC_COPYING_TXPDUSTATE;
            }
            if( SECOC_COPYING_TXPDUSTATE == SecOC_TxPduBuf[pduIndex].pduState )
            {
                /* 2.Check retry, copy previously copied data again. */
                /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
                if( (NULL_PTR != retry) && (TP_DATARETRY == retry->TpDataState) )
                {
                    if( retry->TxTpDataCnt < copyedPduLen )
                    {
                        copyedPduLen -= retry->TxTpDataCnt;
                    }
                    else
                    {
                        retVal = BUFREQ_E_NOT_OK;
                    }
                }
                if( BUFREQ_OK == retVal )
                {
                    /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
                    if( info->SduLength >= (pduLength - copyedPduLen) )
                    {
                        for( loopIdx = SECOC_0; loopIdx < info->SduLength; loopIdx++ )
                        {
                            /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_SecOC_NIV" */
                            info->SduDataPtr[loopIdx] = SecOC_TxPduBuf[id].authpdubuf[loopIdx + copyedPduLen];
                        }
                        SecOC_TxPduBuf[id].tpAuthLength = copyedPduLen + info->SduLength;
                        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
                        *availableDataPtr = pduLength - copyedPduLen - info->SduLength;
                    }
                    else
                    {
                        SecOC_TxPduBuf[id].tpAuthLength = copyedPduLen;
                        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
                        *availableDataPtr = pduLength - copyedPduLen;
                        retVal = BUFREQ_E_BUSY;
                    }
                }
            }
        }
#endif  /* SECOC_NUM_TXPDUPRO > SECOC_0 */
    }

#if( SECOC_DEVERRORDETECT == STD_ON )
    if( SECOC_E_NO_ERROR != errorId )
    {
        SecOC_ReportDetError(SECOC_SID_COPY_TX_DATA, errorId);
    }
#else
    SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */

    return retVal;
}

#if( SECOC_RXPDUTYPE == SECOC_TPPDU )
/*
********************************************************************************
* Function Name: SecOC_StartOfReception
*
* Explanation: This function is called at the start of receiving an N-SDU.
*              The N-SDU might be fragmented into multiple N-PDUs
*              (FF with one or more following CFs) or might consist of a single N-PDU (SF).
*              The service shall provide the currently available maximum
*              buffer size when invoked with TpSduLength equal to 0.
*
* param(in): id: Identification of the I-PDU.
* param(in): info: Pointer to a PduInfoType structure containing the payload
*                  data (without protocol information) and payload length of the
*                  first frame or single frame of a transport protocol
*                  I-PDU reception, and the MetaData related to this PDU. If neither
*                  first/single frame data nor MetaData are available,
*                  this parameter is set to NULL_PTR..
* param(in): TpSduLength: Total length of the N-SDU to be received.
* param(inout): None
*
* param(out): bufferSizePtr: Available receive buffer in the receiving module.
*                            This parameter will be used to compute the Block
*                            Size (BS) in the transport protocol module.
*
* retval: BufReq_ReturnType: BUFREQ_OK: Connection has been accepted.
*                                       bufferSizePtr indicates the available
*                                       receive buffer;reception is continued.
*                                       If no buffer of the requested size
*                                       is available, a receive buffer size of
*                                       0 shall be indicated by bufferSizePtr.
*                            BUFREQ_E_NOT_OK: Connection has been rejected;
*                                             reception is aborted.
*                                             bufferSizePtr remains unchanged.
*                            BUFREQ_E_OVFL: No buffer of the required length
*                                           can be provided; reception is aborted.
*                                           bufferSizePtr remains unchanged.
********************************************************************************
*/
FUNC(BufReq_ReturnType, SECOC_CODE) SecOC_StartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, SECOC_APPL_DATA) bufferSizePtr
)
{
    uint8 errorId = SECOC_E_NO_ERROR;
    uint16 rxPduIdx = SECOC_0;
    uint16 upPduId = SECOC_0;
    BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
    uint32 cryptoPduLen = SECOC_0;

    if( SECOC_UNINIT == SecOCInit )
    {
        errorId = SECOC_E_UNINIT;
    }
    else if( NULL_PTR == bufferSizePtr )
    {
        errorId = SECOC_E_PARAM_POINTER;
    }
    else if( SECOC_0 == TpSduLength )
    {
        /* Do nothing.SWS_SecOC_00181 */
    }
    else
    {
    
#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
        for( rxPduIdx = SECOC_0; rxPduIdx < SECOC_NUM_RXPDUPRO; rxPduIdx++ )
        {
            if( SecOCRxPduProcessingIns[rxPduIdx].SecOCRxSecuredPduLayer->SecOCRxSecuredPdu->SecOCRxSecuredLayerPduId == id )
            {
                cryptoPduLen = (SecOCRxPduProcessingIns[rxPduIdx].SecOCAuthInfoTruncLength
                                + SecOCRxPduProcessingIns[rxPduIdx].SecOCFreshnessValueTruncLength) / SECOC_8;
                SecOC_RxPduBuf[rxPduIdx].cryptoPduBuflen = cryptoPduLen;
                if( NULL_PTR == SecOC_RxPduBuf[rxPduIdx].authpdubuf )
                {

                    SecOC_RxPduBuf[rxPduIdx].authpdubuf = &SecOC_RxPduBuffer.PduBuffer[ SECOC_MAX_RXSECURE_LEN - SecOC_RxPduBuffer.BufferLen ];
                    SecOC_RxPduBuffer.BufferLen = SecOC_RxPduBuffer.BufferLen - TpSduLength;

                    SecOC_RxPduBuf[rxPduIdx].cryptoPduBuf = &SecOC_RxPduBuffer.PduBuffer[ SECOC_MAX_RXSECURE_LEN - SecOC_RxPduBuffer.BufferLen ];
                    /* Secured I-PDU contents with truncated Freshness Counter(8 bytes) and truncated Authenticator(16 bytes) */
                    SecOC_RxPduBuffer.BufferLen = SecOC_RxPduBuffer.BufferLen - cryptoPduLen;    
                }
                SecOC_RxPduBuf[rxPduIdx].tpSduLength = TpSduLength;
                SecOC_RxPduBuf[rxPduIdx].tpSduCryptoLength = cryptoPduLen;
                break;
            }

        }
        if( SECOC_NUM_RXPDUPRO <= rxPduIdx )
        {
            errorId = SECOC_E_INVALID_PDU_SDU_ID;
        }
        else
        {
            if( NULL_PTR != SecOC_RxPduBuf[rxPduIdx].authpdubuf)
            {
                if( SECOC_IDLE_RXPDUSTATE == SecOC_RxPduBuf[rxPduIdx].pduState )
                {
                    SecOC_RxPduBuf[rxPduIdx].pduState = SECOC_COPYING_RXPDUSTATE;
                    *bufferSizePtr = TpSduLength;
                    if( SECOC_TPPDU == SecOCRxPduProcessingIns[rxPduIdx].SecOCRxAuthenticPduLayer->SecOCPduType )
                    {
                        upPduId = SecOCRxPduProcessingIns[rxPduIdx].SecOCRxAuthenticPduLayer->SecOCRxAuthenticLayerPduRef;
                        retVal = PduR_SecOCStartOfReception(upPduId, info, TpSduLength, bufferSizePtr);
                    }
                    else
                    {
                        retVal = BUFREQ_OK;
                    }
                }
            }
            else
            {
                retVal = BUFREQ_E_OVFL;
            }
        }
#endif   /* SECOC_NUM_RXPDUPRO > SECOC_0 */
    }

#if( SECOC_DEVERRORDETECT == STD_ON )
    if( SECOC_E_NO_ERROR != errorId )
    {
        SecOC_ReportDetError(SECOC_SID_START_OF_RECEPTION, errorId);
    }
#else
    SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */

    return retVal;
}
#endif  /* SECOC_RXPDUTYPE == SECOC_TPPDU */

#if( SECOC_ENABLEFORCEDPASSOVERRIDE == STD_ON )
/*
********************************************************************************
* Function Name: SecOC_VerifyStatusOverride
*
* Explanation: This service provides the ability to force specific behaviour of SecOc: accept or drop an I-PDU with or without performing
*            the verification of authenticator or independent of the authenticator verification result, and to force a specific result
*            for SecOC_VerificationResultType allowing additional fault handling in the application.
*            Option SECOC_OVERRIDE_PASS_UNTIL_NOTICE, SECOC_OVERRIDE_SKIP_UNTIL_LIMIT
*            or SECOC_OVERRIDE_PASS_UNTIL_LIMIT are available only if SecOCEnableForcedPassOverride is set to TRUE.
*           (Synchronous&Non Reentrant for the same FreshnessValueID. Reentrant for different FreshnessValueIDs.)
*
* param(in): ValueID: If SecOCOverrideStatusWithDataId is configured to FALSE, ValueID is the ID of the Freshness Value used to control
                   the verification behaviour of all assigned Secured I-PDUs according to the overrideStatus.
                   If SecOCOverrideStatusWithDataId is configured to TRUE, ValueID is the DataID of a Secured I-PDU
                   that shall be controlled by the overrideStatus.
* param(in): overrideStatus: Defines whether verification is executed and whether the I-PDU is passed on, and for how long the override is active.
* param(in): numberOfMessagesToOverride: Number of sequential verification to override when using a specific counter for authentication
                                     verification. This is only considered when OverrideStatus is equal to
                                     SECOC_OVERRIDE_DROP_UNTIL_LIMIT,
                                     SECOC_OVERRIDE_SKIP_UNTIL_LIMIT or
                                     SECOC_OVERRIDE_PASS_UNTIL_LIMIT.
* param(inout): None
* param(out): None
*
* retval: Std_ReturnType: E_OK: request successful
*                     E_NOT_OK: request failed
********************************************************************************
*/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_VerifyStatusOverride
(
    uint16 ValueID,
    SecOC_OverrideStatusType overrideStatus,
    uint8 numberOfMessagesToOverride
)
{
    uint8 errorId = SECOC_E_NO_ERROR;
    Std_ReturnType retValue = E_NOT_OK;
    uint16 loopIdx = SECOC_0;

    if( SECOC_UNINIT == SecOCInit )
    {
        errorId = SECOC_E_UNINIT;
    }
    else
    {
#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
        for( loopIdx = SECOC_0; loopIdx < SECOC_NUM_RXPDUPRO; loopIdx++ )
        {
            if( ValueID == SecOC_RxPdu_OverrideStatus[loopIdx].SecOCValueId )
            {
                break;
            }
        }
        if( SECOC_NUM_RXPDUPRO > loopIdx )
        {
            if( (SECOC_OVERRIDE_DROP_UNTIL_LIMIT == overrideStatus)
#if (SECOC_ENABLEFORCEDPASSOVERRIDE == STD_ON)
               || (SECOC_OVERRIDE_PASS_UNTIL_NOTICE == overrideStatus)
               || (SECOC_OVERRIDE_SKIP_UNTIL_LIMIT == overrideStatus)
               || (SECOC_OVERRIDE_PASS_UNTIL_LIMIT == overrideStatus)
#endif
              )
            {
                SecOC_RxPdu_OverrideStatus[loopIdx].SecOCNumberOfMessages = numberOfMessagesToOverride;
            }
            SecOC_RxPdu_OverrideStatus[loopIdx].SecOCOverrideStatus = overrideStatus;
            retValue = E_OK;
        }
        else
        {
            errorId = SECOC_E_INVALID_PDU_SDU_ID;
        }
#endif  /* SECOC_NUM_RXPDUPRO > SECOC_0 */
    }

#if( SECOC_DEVERRORDETECT == STD_ON )
    if( errorId != SECOC_E_NO_ERROR )
    {
        SecOC_ReportDetError(SECOC_SID_VERIFY_STATUS_OVERRIDE, errorId);
    }
#else
    SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */

    return retValue;

}
#endif  /* SECOC_ENABLEFORCEDPASSOVERRIDE == STD_ON */

#if( SECOC_SETMODE == STD_ON )
/*
********************************************************************************
* Function Name: SecOC_SetMode
*
* Explanation: Turn off or on SecOC function.
*
* param(in): mode: SECOC_ON/SECOC_OFF
* param(in): defaultVal:Default values for Fv and Mac filling when sending
*                       after SecOC function is turned off.
* param(in): useDefaultVal: Use default code when sending.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
FUNC(void, SECOC_CODE) SecOC_SetMode
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    SecOC_ModeType mode,
    uint8 defaultVal,
    boolean useDefaultVal
)
{
    uint8 errorId = SECOC_E_NO_ERROR;

    if( SECOC_UNINIT == SecOCInit )
    {
        errorId = SECOC_E_UNINIT;
#if( SECOC_E_NOINITED != SECOC_NOUSED_DEM )
        /* Report SECOC_E_NOINITED to Dem. */
        Dem_ReportErrorStatus(SECOC_E_NOINITED, DEM_EVENT_STATUS_FAILED);
#endif  /* SECOC_E_NOINITED != SECOC_NOUSED_DEM */
    }
    else
    {
        SecOC_Mode = mode;
        SecOC_DefaultData.defaultVal = defaultVal;
        SecOC_DefaultData.useDefaultVal = useDefaultVal;
    }
   
#if( SECOC_DEVERRORDETECT == STD_ON )
    if(errorId != SECOC_E_NO_ERROR)
    {
        SecOC_ReportDetError(SECOC_SID_SETMODE, errorId);
    }
#else
    SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */

}
#endif  /* SECOC_SETMODE == STD_ON */

#if( SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM )
/*
********************************************************************************
* Function Name: SecOC_RxPduVerifyResultChk
*
* Explanation: Check all received PDUs to verify whether
*              the MAC verification has passed.
*
* param(in): None
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
static FUNC(Std_ReturnType, SECOC_CODE) SecOC_RxPduVerifyResultChk(void)
{
    Std_ReturnType retValue = E_OK;
    uint16 index = SECOC_INIT_0;

    /* Check the verification status of the RX PDU. */
    for( index = SECOC_INDEX_0; index < SECOC_NUM_RXPDUPRO; index++ )
    {
        /* If there is a PDU with verification failure, terminate the loop.*/
        if( E_NOT_OK == SecOC_RxPduBuf[index].pduVerifyResult )
        {
            retValue = E_NOT_OK;
            break;
        }
    }

    return retValue;
}
#endif  /* SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM */

/*
********************************************************************************
* Function Name: SecOC_SearchTxPduIdxByCsmJob
*
* Explanation: Search the secoc tx pdu index by csm job.
*
* param(in): job: The crypto job id.
* param(inout): None
* param(out): None
*
* retval: E_OK: Search the index successed.
*         E_NOT_OK: Search the index failed.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.13" */
static FUNC(uint16, SECOC_CODE) SecOC_SearchTxPduIdxByCsmJob(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_DATA) job)  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
{
    uint16 pduIdx;

    /* Search the txpdu index. */
    for( pduIdx = SECOC_INDEX_0; pduIdx < SECOC_NUM_TXPDUPRO; pduIdx++ )
    {
        /* The jobid is the same as SecOCTxAuthServiceConfigRef */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
        if( SecOCTxPduProcessingIns[pduIdx].SecOCTxAuthServiceConfigRef == job->jobId )
        {
            break;
        }
    } 

    return pduIdx;
}


/*
********************************************************************************
* Function Name: SecOC_CsmMacGenerateCallback
*
* Explanation: The callback function of mac generation for Csm module.
*
* param(in): job: The crypto job id.
             result: The result value of Csm job.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
FUNC(void, SECOC_CODE) SecOC_CsmMacGenerateCallback(P2VAR(Crypto_JobType, AUTOMATIC, SECOC_APPL_DATA) job, VAR(uint8, AUTOMATIC) result)
{
    uint16 pduIdx;
    uint8 txPduResult;

    /* Search the secoc tx pdu index by csm job. */
    pduIdx = SecOC_SearchTxPduIdxByCsmJob(job);

    /* Process the Csm job if it's in the SECOC_WAIT_CSM_JOB_PROCESS state. */
    if( (pduIdx < SECOC_NUM_TXPDUPRO) && (SECOC_WAIT_CSM_JOB_PROCESS == SecOC_TxPduBuf[pduIdx].pduState) )
    {  
        if(E_OK == result)
        {
            /* Fill the authentication buffer of tx pdu. */
            SecOC_TxPduAuthBufFill(pduIdx); 
            /* Change the tx pdu state to SECOC_AUTHENTICATED_TXPDUSTATE. */
            SecOC_TxPduBuf[pduIdx].pduState = SECOC_AUTHENTICATED_TXPDUSTATE;
            if( SECOC_TRANSMIT_TRANSMITREQUEST == SecOC_TxPduBuf[pduIdx].txRequest )
            {
                /* Send the pdu data to lower layer of PDUR. */
                txPduResult = SecOC_SendSecurityPDUtoLower(pduIdx);
                if( E_OK == txPduResult )
                {
                    /* Change the txRequest to SECOC_IDLE_TRANSMITREQUEST. */
                    SecOC_TxPduBuf[pduIdx].txRequest = SECOC_IDLE_TRANSMITREQUEST;
                }
            }
        }
        else
        {
            /* SecOC authenticate failed*/
            /* SECOC_E_AUTHENTICATE_FAILED */
            /* SWS_SecOC_00227 */
            SecOC_IncAndCheckBuildAttempts(pduIdx);
            if( SecOC_TxPduBuf[pduIdx].attempCounter > SecOCTxPduProcessingIns[pduIdx].SecOCAuthenticationBuildAttempts )
            {    
#if( SECOC_E_AUTHENTICATE_FAILED != SECOC_NOUSED_DEM )
                 Dem_ReportErrorStatus(SECOC_E_AUTHENTICATE_FAILED, DEM_EVENT_STATUS_FAILED);
#endif  /* SECOC_E_AUTHENTICATE_FAILED != SECOC_NOUSED_DEM */
            }
            else
            {
                SecOC_TxPduBuf[pduIdx].pduState = SECOC_REAUTHENTICATION_NEEDED_TXPDUSTATE;
                SecOC_TxPduBuf[pduIdx].authDataLen -= SecOCTxPduProcessingIns[pduIdx].SecOCFreshnessValueLength / SECOC_8;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: SecOC_SearchRxPduIdxByCsmJob
*
* Explanation: Search the secoc rx pdu index by csm job.
*
* param(in): job: The crypto job id.
* param(inout): None
* param(out): None
*
* retval: E_OK: Search the index successed.
*         E_NOT_OK: Search the index failed.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.13" */
static FUNC(uint16, SECOC_CODE) SecOC_SearchRxPduIdxByCsmJob(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_DATA) job)  /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
{
    uint16 pduIdx;

    /* Search the txpdu index. */
    for( pduIdx = SECOC_INDEX_0; pduIdx < SECOC_NUM_RXPDUPRO; pduIdx++ )
    {
        /* The jobid is the same as SecOCRxAuthServiceConfigRef */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
        if( SecOCRxPduProcessingIns[pduIdx].SecOCRxAuthServiceConfigRef == job->jobId )
        {
            break;
        }
    } 

    return pduIdx;
}

/*
********************************************************************************
* Function Name: SecOC_CsmMacVerifyCallback
*
* Explanation: The callback function of mac verifying for Csm module .
*
* param(in): job: The Csm job id.
             result: The result value of Csm job.
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
FUNC(void ,SECOC_CODE) SecOC_CsmMacVerifyCallback(P2VAR(Crypto_JobType, AUTOMATIC, SECOC_APPL_DATA) job, VAR(uint8, AUTOMATIC) result)
{
    uint16 pduIdx;
    SecOC_VerificationStatusType verifyStatus;

    /* Search the secoc rx pdu index by csm job. */
    pduIdx = SecOC_SearchRxPduIdxByCsmJob(job);
    /* Get the FreshnessValueID and secOCDataId. */
    /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_SecOC_OBAI" */
    verifyStatus.freshnessValueID = SecOCRxPduProcessingIns[pduIdx].SecOCFreshnessValueId;
    verifyStatus.secOCDataId = SecOCRxPduProcessingIns[pduIdx].SecOCDataId;

    /* Process the Csm job if it's in the SECOC_WAIT_CSM_JOB_PROCESS state. */
    if( (pduIdx < SECOC_NUM_RXPDUPRO) && (SECOC_WAIT_CSM_JOB_PROCESS == SecOC_RxPduBuf[pduIdx].pduState) )
    {
        if( (((uint8)CRYPTO_E_VER_OK == result) && (CRYPTO_E_VER_OK == SecOC_RxPduBuf[pduIdx].verifyPtr)) || (SECOC_IGNOREVERIFICATIONRESULT == TRUE) )
        {
            /* Verify successfully */
            SecOC_RxPduBuf[pduIdx].pduState = SECOC_VERIFY_FINISHED_RXPDUSTATE;
            if( (E_OK == result) && (CRYPTO_E_VER_OK == SecOC_RxPduBuf[pduIdx].verifyPtr) )
            {
                verifyStatus.verificationStatus = SECOC_VERIFICATIONSUCCESS;
                /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                if( SecOCRxPduProcessingIns[pduIdx].SecOCVerificationStatusPropagationMode == SECOC_BOTH )
                /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    /* Verification status callout */
                    /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                    SecOC_VerificationStatusCallout(verifyStatus);
                    /* Verification status Service */
                    /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                    SecOC_VerificationStatusService(verifyStatus);
                    /* Verification status Indication */
                    /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                    SecOC_VerificationStatusIndication(verifyStatus);
                }
            }
            else
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                verifyStatus.verificationStatus = SECOC_VERIFICATIONFAILURE;
                if( SecOCRxPduProcessingIns[pduIdx].SecOCVerificationStatusPropagationMode != SECOC_NONE )
                {
                    /* Verification status callout */
                    /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                    SecOC_VerificationStatusCallout(verifyStatus);
                    /* Verification status Service */
                    /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                    SecOC_VerificationStatusService(verifyStatus);
                    /* Verification status Indication */
                    /* polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                    SecOC_VerificationStatusIndication(verifyStatus);
                }
            }
            /* Pass the authedticated pdu date to the up layer of PDUR */
            SecOC_PassAuthenticPDUtoUplayer(pduIdx);
#if( SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM )
            /* Set pduVerifyResult to E_OK. */
            SecOC_RxPduBuf[pduIdx].pduVerifyResult = E_OK;
            /* Check whether all Rx PDUs have passed the verification. */
            if( (TRUE == SecOC_RxPduVerifyFailed) && (E_OK == SecOC_RxPduVerifyResultChk()) )
            {
                /* Report to the DEM to clear the DTC. */
                Dem_ReportErrorStatus(SECOC_E_VERIFY_FAILED, DEM_EVENT_STATUS_PASSED);
                SecOC_RxPduVerifyFailed = FALSE;
            }
#endif  /* SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM */
        }
        else
        {
            /* CSM returned recoverable return value SWS_SecOC_00237 */
            SecOC_RxPduBuf[pduIdx].pduState = SECOC_FV_NEEDED_RXPDUSTATE;
            SecOC_Verify_IncAuthentictionAttempts(pduIdx);
        }
    }
}

/*
********************************************************************************
* Function Name: SecOC_MainFunctionRx
*
* Explanation: This function performs the processing of the SecOC module's
*              authentication and verification processing for the Rx path.
*
* param(in): id: None
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
FUNC(void, SECOC_CODE) SecOC_MainFunction_Rx(uint16 SecOCRxPduInfoTableIndex)
{
    uint8 errorId = SECOC_E_NO_ERROR;
    uint16 posIdx = SECOC_0;
    uint16 pduNum = SECOC_0;
    uint16 index  = SECOC_0;

    Std_ReturnType retVal = E_NOT_OK;

	uint8 freshnessVerifyValue[SECOC_8] = { SECOC_0 };
    /* [SWS_SecOC_00079] During reception of a Secured I-PDU that is
       received by means of a lower layer bus interface,the SecOC module
       shall verify the Authenticator according to the overall approach
       specified in SWS_SecOC_00040.The verification shall be processed
       in the scheduled main function. */
    /* [SWS_SecOC_00040] The verification of a Secured I-PDU consists
        of the following six steps:
        1. Parse Authentic I-PDU, Freshness Value and Authenticator
        2. Get Freshness Value from Freshness Manager
        3. Construct Data to Authentication
        4. Verify Authentication Information
        5. Send Confirmation to Freshness Manager
        6. Pass Authentic I-PDU to upper layer */

    if( SECOC_INIT == SecOCInit )
    {
#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
        /* Get pduNum from SecOC_RxPduInfoTable*/
        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_SecOC_OBAI" polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_ARRAY_INDEX" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
        pduNum = SecOC_RxPduInfoTable[SecOCRxPduInfoTableIndex].pduNum;
        for( index = SECOC_0; index < pduNum; index++ )
        {
            posIdx = SecOC_RxPduInfoTable[SecOCRxPduInfoTableIndex].pduRxInfo[index];
            if( SECOC_IDLE_RXPDUSTATE != SecOC_RxPduBuf[posIdx].pduState )
            {
                if( SECOC_COPY_AUTHENTIC_RXPDUSTATE == SecOC_RxPduBuf[posIdx].pduState )
                {
                    SecOC_CopyDataToAuthenticator(posIdx);
                }
            }
#if( SECOC_IMMEDIATE_RETRY == STD_ON )
            /* Cyclic verification of SecOC RxPdu until completion */
            while( SecOC_IsRxPduStateValid(posIdx) )
#endif  /* SECOC_IMMEDIATE_RETRY == STD_ON */
            {
                if( SECOC_FV_NEEDED_RXPDUSTATE == SecOC_RxPduBuf[posIdx].pduState )
                {
                    /* Fill the DataId into the auth data buffer */
                    /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" */
                    SecOC_RxPduBuf[posIdx].authData[SECOC_INDEX_0] = (uint8)(SecOCRxPduProcessingIns[posIdx].SecOCDataId >> SECOC_VALUE_8);
                    /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_SecOC_IDP" */
                    SecOC_RxPduBuf[posIdx].authData[SECOC_INDEX_1] = (uint8)SecOCRxPduProcessingIns[posIdx].SecOCDataId;
                    SecOC_RxPduBuf[posIdx].authDataLen = SecOC_RxPduBuf[posIdx].authpdubuflen + SECOC_VALUE_2;

                    if( TRUE == SecOCRxPduProcessingIns[posIdx].SecOCFreshnessValueSynMessage )
                    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    {
                        SecOC_RxPduBuf[posIdx].pduState = SECOC_UNVERIFIED_RXPDUSTATE;
                    }
                    else
                    {
                        /* Get FreshnessValue from callout */
                        retVal = SecOC_GetFVFromCallout(posIdx, &freshnessVerifyValue[SECOC_0]);
                        if( E_OK == retVal )
                        {
                            SecOC_CopyFVToBuffer(posIdx, &freshnessVerifyValue[SECOC_0]);
                            SecOC_RxPduBuf[posIdx].pduState = SECOC_UNVERIFIED_RXPDUSTATE;
                        }
                        /* polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule14.3" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                        else if( SECOC_E_BUSY == retVal )
                        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                        {
                            SecOC_Verify_IncBuildAttempts(posIdx);
                            /* SECOC_E_FRESHNESS_FAILED */
                            if( SecOC_RxPduBuf[posIdx].builtAttempCnt >= 
                                SecOCRxPduProcessingIns[posIdx].SecOCAuthenticationBuildAttempts )
                            {
                                errorId = SECOC_E_FRESHNESS_FAILURE;
#if( SECOC_E_FRESHNESS_FAILED != SECOC_NOUSED_DEM ) 
                                Dem_ReportErrorStatus(SECOC_E_FRESHNESS_FAILED, DEM_EVENT_STATUS_FAILED);
#endif  /* SECOC_E_FRESHNESS_FAILED != SECOC_NOUSED_DEM */
                            }
                        }
                        else
                        {
                            errorId = SECOC_E_FRESHNESS_FAILURE;
                            SecOC_FailedObtainFvProcess(posIdx);
                        }
                    }

                }
                /* Verify MAC */
                if( SecOC_IsRxPduStateUnverified(posIdx) )
                {
                    retVal = SecOC_Verify_MACUsingCSM(posIdx);

                    if( E_OK == retVal )
                    {
                        /* Csm job sync process */
                        if( CRYPTO_PROCESSING_ASYNC != SecOCRxPduProcessingIns[posIdx].SecOCRxAuthServiceProcType )
                        {
                            if( SECOC_VERIFY_FINISHED_RXPDUSTATE == SecOC_RxPduBuf[posIdx].pduState )
                            {
                                SecOC_PassAuthenticPDUtoUplayer(posIdx);
#if( SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM )
                                /* Set pduVerifyResult to E_OK. */
                                SecOC_RxPduBuf[posIdx].pduVerifyResult = E_OK;
                                /* Check whether all Rx PDUs have passed the verification. */
                                if( (TRUE == SecOC_RxPduVerifyFailed) && (E_OK == SecOC_RxPduVerifyResultChk()) )
                                {
                                    Dem_ReportErrorStatus(SECOC_E_VERIFY_FAILED, DEM_EVENT_STATUS_PASSED);
                                    SecOC_RxPduVerifyFailed = FALSE;
                                }
#endif  /* SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM */
                            }
                            else if( SECOC_FV_NEEDED_RXPDUSTATE == SecOC_RxPduBuf[posIdx].pduState )
                            {
                                SecOC_Verify_IncAuthentictionAttempts(posIdx);
                            }
                            else
                            {
                                /* Do nothing */
                            }
                        }
                        else /* Csm job async process */
                        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                        {
                            /* Do nothing. */
                        }
                    }
                    else
                    {
                        errorId = SECOC_E_CRYPTO_FAILURE;
                    }
                }
            }

#if( SECOC_ENABLEDEFAULTCODE == STD_ON )
            if( SECOC_DEFAULTCODE_RXPDUSTATE == SecOC_RxPduBuf[posIdx].pduState )
            {
                /* Default code authentication through Callout interface. */
                retVal = SecOC_VerifyByDefaultCode(SecOC_RxPduBuf[posIdx].cryptoPduBuf, 
                                                   SecOC_RxPduBuf[posIdx].cryptoPduBuflen,
                                                   SecOCRxPduProcessingIns[posIdx].SecOCFreshnessValueTruncLength,
                                                   SecOCRxPduProcessingIns[posIdx].SecOCAuthInfoTruncLength);
                /* polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule14.3" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                if( E_OK == retVal )
                /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    SecOC_RxPduBuf[posIdx].pduState = SECOC_VERIFY_FINISHED_RXPDUSTATE;
                    SecOC_RxPduBuf[posIdx].verifyCount = SECOC_0;
                    /* Pass the auth data to the up layer of PDUR */
                    SecOC_PassAuthenticPDUtoUplayer(posIdx);
#if( SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM )
                    /* Set pduVerifyResult to E_OK. */
                    SecOC_RxPduBuf[posIdx].pduVerifyResult = E_OK;
                    /* Check whether all Rx PDUs have passed the verification. */
                    if( (TRUE == SecOC_RxPduVerifyFailed) && (E_OK == SecOC_RxPduVerifyResultChk()) )
                    {
                        /* Report to the DEM to clear the DTC. */
                        Dem_ReportErrorStatus(SECOC_E_VERIFY_FAILED, DEM_EVENT_STATUS_PASSED);
                        SecOC_RxPduVerifyFailed = FALSE;
                    }
#endif  /* SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM */
                }
                else
                {
                    /* CSM returned none recoverable return value */
                    SecOC_RxPduBuf[posIdx].pduState = SECOC_IDLE_RXPDUSTATE;
                    SecOC_RxPduBuf[posIdx].authpdubuflen = SECOC_0;
                    SecOC_RxPduBuf[posIdx].cryptoPduBuflen = SECOC_0;
                    SecOC_RxPduBuf[posIdx].verifyCount++;

#if( SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM )
                    if( SECOC_VERIFYATTEMPTS <= SecOC_RxPduBuf[posIdx].verifyCount )
                    {
                        /* Certification failure reports DTC failure. */
                        Dem_ReportErrorStatus(SECOC_E_VERIFY_FAILED, DEM_EVENT_STATUS_FAILED);
                        /* Set pduVerifyResult to E_NOT_OK and set SecOC_RxPduVerifyFailed to TRUE. */
                        SecOC_RxPduBuf[posIdx].pduVerifyResult = E_NOT_OK;
                        SecOC_RxPduVerifyFailed = TRUE;
                        SecOC_RxPduBuf[posIdx].verifyCount = SECOC_0;
                    }
#endif  /* SECOC_E_VERIFY_FAILED != SECOC_NOUSED_DEM */
                }
            }
#endif  /* SECOC_ENABLEDEFAULTCODE == STD_ON */
        }
#endif    /* SECOC_NUM_RXPDUPRO > SECOC_0 */

    }
    else
    {
        errorId = SECOC_E_UNINIT;
    }
    
#if( SECOC_DEVERRORDETECT == STD_ON )
        if( SECOC_E_NO_ERROR != errorId )
        {
            SecOC_ReportDetError(SECOC_SID_MAIN_FUNCTION_RX, errorId);
        }
#else
        SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */
}

/*
********************************************************************************
* Function Name: SecOC_MainFunctionTx
*
* Explanation: This function performs the processing of the SecOC
*              module's authentication and verification processing for the Tx path.
*
* param(in): id: None
* param(inout): None
* param(out): None
*
* retval: None
********************************************************************************
*/
FUNC(void, SECOC_CODE) SecOC_MainFunction_Tx(uint16 SecOCTxPduInfoTableIndex)
{
    uint8 errorId = SECOC_E_NO_ERROR;
    Std_ReturnType retVal = E_NOT_OK;
#if( SECOC_ENABLEDEFAULTCODE == STD_ON )
    uint8 *authInfo = NULL_PTR;
#endif  /* SECOC_ENABLEDEFAULTCODE == STD_ON */
    uint16 posIdx = SECOC_0;
    uint16 index  = SECOC_0;
    uint16 pduNum = SECOC_0;
    /* [SWS_SecOC_00177] If the SecOC module was not previously initialized
       with a call to SecOC_Init, then a call to SecOC_MainFunctionTx
       shall simply return. */
    if( SECOC_INIT == SecOCInit )
    {
        /* [SWS_SecOC_00060] For transmission of Authentic I-PDUs using
            bus interfaces that allow ad-hoc transmission (e.g. CanIf),
            the SecOC module shall calculate the Authenticator in the
            scheduled main function according to the overall approach
            specified in SWS_SecOC_00031. */
        /* [SWS_SecOC_00061] For transmission of Authentic I-PDUs using
           bus interfaces that allow ad-hoc communication (e.g. CanIf),the
           SecOC module shall create the Secured I-PDU in the scheduled main function. */
#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
        /* Get pduNum from SecOC_TxPduInfoTable*/
        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule18.1" polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_SecOC_OBAI" polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_SecOC_TAINTED_ARRAY_INDEX" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.14" */
        pduNum = SecOC_TxPduInfoTable[SecOCTxPduInfoTableIndex].pduNum;
        for( index = SECOC_0; index < pduNum; index++ )
        {
            posIdx = SecOC_TxPduInfoTable[SecOCTxPduInfoTableIndex].pduTxInfo[index];
            /* If it is a synchronous message, only the pdu state is changed, and the FV is not obtained. */
#if( SECOC_SETMODE == STD_ON )
            if( SECOC_BYPASS_TXPDUSTATE == SecOC_TxPduBuf[posIdx].pduState )
            {
                /* polyspace +1 DEFECT:USELESS_WRITE [Justified:Unset] "NSCA_Polyspace_SecOC_USELESS_WRITE" polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                retVal = SecOC_SendSecurityPDUtoLower(posIdx);
            }
            else
#endif
            {
                if( (TRUE == SecOCTxPduProcessingIns[posIdx].SecOCFreshnessValueSynMessage) &&
                    (SECOC_REAUTHENTICATION_NEEDED_TXPDUSTATE == SecOC_TxPduBuf[posIdx].pduState) )
                {
                    SecOC_TxPduBuf[posIdx].pduState = SECOC_TO_BE_STARTED_TXPDUSTATE;
                }
                else
                {
                    SecOC_ReauthenticationNeeded(posIdx);
                }
            }

            if( SecOC_IsTxPduStateUnauthenticated(posIdx) )
            {
                /* Generates MAC and copies the truncated MAC to the Secured Pdu Buffer */
                retVal = SecOC_GenerateAuthenticator(posIdx);
                if( E_OK == retVal )
                {
                    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    if( CRYPTO_PROCESSING_ASYNC != SecOCTxPduProcessingIns[posIdx].SecOCTxAuthServiceProcType )
                    {
                        if( (SECOC_AUTHENTICATED_TXPDUSTATE == SecOC_TxPduBuf[posIdx].pduState ) &&
                            (SECOC_TRANSMIT_TRANSMITREQUEST == SecOC_TxPduBuf[posIdx].txRequest ) )
                        {
                            retVal = SecOC_SendSecurityPDUtoLower(posIdx);
                            if( E_OK == retVal )
                            {
                                SecOC_TxPduBuf[posIdx].txRequest = SECOC_IDLE_TRANSMITREQUEST;
                            }
                        }
                    } 
                }
                else
                {
                    errorId = SECOC_E_CRYPTO_FAILURE;
                }
            }
#if( SECOC_ENABLEDEFAULTCODE == STD_ON )
            if( SECOC_DEFAULT_CODE_TXPDUSTATE == SecOC_TxPduBuf[posIdx].pduState )
            {
                authInfo = &SecOC_TxPduBuf[posIdx].authpdubuf[SecOC_TxPduBuf[posIdx].authpdubuflen];
                retVal = SecOC_AuthenticationByDefaultCode(authInfo,
                                     (uint32 *)&SecOC_TxPduBuf[posIdx].cryptoPduBuflen,
                                     SecOCTxPduProcessingIns[posIdx].SecOCFreshnessValueTruncLength,
                                     SecOCTxPduProcessingIns[posIdx].SecOCAuthInfoTruncLength);
                /* polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule14.3" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                if( E_OK == retVal )
                /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    SecOC_TxPduBuf[posIdx].authpdubuflen += SecOC_TxPduBuf[posIdx].cryptoPduBuflen;
                    SecOC_TxPduBuf[posIdx].pduState = SECOC_AUTHENTICATED_TXPDUSTATE;
                    if( SECOC_TRANSMIT_TRANSMITREQUEST == SecOC_TxPduBuf[posIdx].txRequest )
                    {
                        retVal = SecOC_SendSecurityPDUtoLower(posIdx);
                        if( E_OK == retVal )
                        {
                            SecOC_TxPduBuf[posIdx].txRequest = SECOC_IDLE_TRANSMITREQUEST;
                        }
                    }
                }
                else
                {
                    /* SECOC_E_AUTHENTICATE_FAILED */
                    SecOC_TxPduBuf[posIdx].pduState= SECOC_INVALID_SECURED_PDU_TXPDUSTATE;
                    SecOC_TxPduBuf[posIdx].txRequest = SECOC_IDLE_TRANSMITREQUEST;
#if( SECOC_E_AUTHENTICATE_FAILED != SECOC_NOUSED_DEM )
                    Dem_ReportErrorStatus(SECOC_E_AUTHENTICATE_FAILED, DEM_EVENT_STATUS_FAILED);
#endif  /* SECOC_E_AUTHENTICATE_FAILED != SECOC_NOUSED_DEM */
                }
            }
#endif  /* SECOC_ENABLEDEFAULTCODE == STD_ON */
        }
#endif  /* SECOC_NUM_TXPDUPRO > SECOC_0 */
    }
    else
    {
        errorId = SECOC_E_UNINIT;
    }
    
#if( SECOC_DEVERRORDETECT == STD_ON )
    if( SECOC_E_NO_ERROR != errorId )
    {
        SecOC_ReportDetError(SECOC_SID_MAIN_FUNCTION_TX, errorId);
    }
#else
    SECOC_DUMMY_STATEMENT(errorId);
#endif  /* SECOC_DEVERRORDETECT == STD_ON */

}

#define SECOC_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

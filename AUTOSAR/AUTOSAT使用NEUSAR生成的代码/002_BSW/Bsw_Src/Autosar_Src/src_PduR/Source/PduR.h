/*
********************************************************************************
*
*  File name: PduR.h
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 2.3
* Author/Date: ZhangDX/2019.08.28
* Change: New create.
* Cause: New
********************************************************************************
* Version: 2.4
* Author/Date: ZhangDX/2019.10.12
* Change: Modify the code format.
* Cause: Optimize
********************************************************************************
* Version: 2.5
* Author/Date: ZhangDX/2020.01.06
* Change: 1. Delete the PduR module reference Std_Types.h and replace it with
*            ComStack_Types.h.
*         2. Remove redundant "ComStack_Cfg.h" and "ComStack_Types.h" files.
* Cause: Update
********************************************************************************
* Version: 2.6
* Author/Date: ZhangDX/2020.01.09
* Change: Change the definition location of module-related macro definitions
*         to PduR.h
* Cause: Optimize
********************************************************************************
* Version: 2.7
* Author/Date: ZhangDX/2020.03.18
* Change: 1. The function macro definitions of the upper and lower modules are
*            added.
*         2. The PduR module no longer manually maintains the function definition
*            implementation of the expected interaction module. Let the tool
*            generate it on demand.
* Cause: Optimize
********************************************************************************
* Version: 2.8
* Author/Date: ZhangDX/2020.03.25
* Change: 1. Add notes.
*         2. Remove the call to PduR_ModuleName.h.
*         3. Perform a QAC check and correct any errors that occur.
* Cause: Optimize
********************************************************************************
* Version: 3.0
* Author/Date: ZhangDX/2020.03.27
* Change: 1. Add notes.
*         2. Updated version information is 3.0.0.
*         3. Delete the file containing PduR_MoudleName.h.
*         4. Modify the return value type of the function defined by
*            PDUR_UP_CHANGE_PARAMETER.
*         5. Modify the function parameters defined by PUDR_LOTP_COPY_RX_DATA
*            and PUDR_LOTP_COPY_TX_DATA.
* Cause: Clear QAC warning and updata to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: lizhiheng/2020.06.08
* Change: Add release software number.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: ZhangDX/2020.07.13
* Change: 1. Add function ID provided to other modules
*         2. Adjust the code structure.
*         3. Remove #include "PduR_MemMap.h" and #include "PduR_Lcfg.h".
*         4. Remove the declaration of the function in PduR_Core.c.
*         5. Move the pre-compiled content defined by the relevant function name
*            to the PduR_Core.h file.
*         6. Update the location of PduR Service ID pre-compiled content, defined
*            in PduR_Core.h.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: ZhangDX/2020.09.25
* Change: 1. Modify the errors that occurred during the code review on 2020.09.23.
*         2. Optimizing the code review on 2020.09.23 is a suggestion item given.
*         3. Optimized the coverage area of PDUR_ZERO_COST_OPERATION.
*         4. Move the macro definitions related to the generated function to
*            the PduR_Types.h file.
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
* Author/Date: ZhangDX/2020.10.14
* Change: Modify the function to generate indentation to make the length meet
*         the requirements as much as possible.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: ZhangDX/2020.11.03
* Change: The function declaration part does not need to increase the section
*         definition.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: ZhangDX/2020.11.27
* Change: Adjust the inclusion of Det.h to the PduR.h file.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: LiuHJ/2021.09.13
* Change: For compatible with 4.4, add new function PduR_LoTxConfirmation_44.
* Cause: Bugfix
********************************************************************************
* Version: 3.11
* Author/Date : FangT/2021.10.20
* Change: Modified version number.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date : SunHQ/2022.06.20
* Change: Modified version number.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date : SunHQ/2022.07.05
* Change: Modified version number.
* Cause: Bugfix
********************************************************************************
* Version: 3.14
* Author/Date : SunHQ/2022.09.09
* Change: Modified version number.
* Cause: Bugfix
********************************************************************************
* Version: 3.15
* Author/Date : SunHQ/2022.09.13
* Change: Modified version number.
* Cause: Bugfix
********************************************************************************
* Version: 3.16
* Author/Date : SunHQ/2022.09.20
* Change: 1. Modified version number.
*         2. Declare the PduR_MainFunction function.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date : SunHQ/2023.02.10
* Change: Declare the PduR_Diag_MainFunction function.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date : SunHQ/2023.05.17
* Change: Upgrade version number.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date : SunHQ/2023.05.26
* Change: Add revision version.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: LuQ/2023.10.08
* Change: Modified version number.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: LuQ/2023.10.17
* Change: Modified version number.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: LuQ/2023.12.04
* Change: Modified version number.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: LuQ/2023.12.22
* Change: Modified version number.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: LuQ/2024.01.11
* Change: Modified version number.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: LuQ/2024.03.13
* Change: Modified version number.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: LuQ/2024.04.02
* Change: 1. Modify the comments format.
*         2. Modify the patch number.
*         3. Modify P2CONST member labels.
* Cause: Optimization
********************************************************************************
* Version: 3.27
* Author/Date: LuQ/2024.05.13
* Change: 1. Add Memmap segment definition.
*         2. Modified version number.
* Cause: Optimization
********************************************************************************
* Version: 3.28
* Author/Date: LuQ/2024.07.25
* Change: Modified version number.
* Cause: Update
********************************************************************************
* Version: 3.29
* Author/Date: LuQ/2024.09.20
* Change: 1. Add the function to eliminate compile warning.
*         2. Modified version number.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date: LuQ/2024.09.23
* Change: Modify the comments format.
* Cause: Optimization
********************************************************************************
* Version: 3.31
* Author/Date: LuQ/2024.10.09
* Change: Modified version number.
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date: LuQ/2024.11.08
* Change: Modified version number.
* Cause: Update
********************************************************************************
* Version: 3.33
* Author/Date: LuQ/2025.03.12
* Change: Modified version number.
* Cause: Update
********************************************************************************
* Version: 3.34
* Author/Date: LuQ/2025.03.26
* Change: Modified version number.
* Cause: Update
********************************************************************************
* Version: 3.35
* Author/Date: LuQ/2025.06.17
* Change: 1. Add the polyspace deviation suppression comment.
*         2. Modified version number.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: LuQ/2025.06.23
* Change: 1. Modify MemMap segment definition.
*         2. Update software version to 3.14.0.16.
* Cause: Bugfix
********************************************************************************
*/
#ifndef PDUR_H_
#define PDUR_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "PduR_PBcfg.h"

#if (STD_ON == PDUR_DEV_ERROR_DETECT)
#include "Det.h"
#endif  /* #if (STD_ON == PDUR_DEV_ERROR_DETECT) */

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Version information definition. */
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_VENDOR_ID                              (119U)
#define PDUR_SW_MAJOR_VERSION                       (3U)
#define PDUR_SW_MINOR_VERSION                       (14U)
#define PDUR_SW_PATCH_VERSION                       (0U)
#define PDUR_SW_REVISION_VERSION                    (16U)
#define PDUR_MODULE_ID                              (51U)

/* AUTOSAR Version. */
#define PDUR_AR_RELEASE_MAJOR_VERSION               (4U)
#define PDUR_AR_RELEASE_MINOR_VERSION               (2U)
#define PDUR_AR_RELEASE_REVISION_VERSION            (2U)

#ifndef PDUR_DUMMY_STATEMENT
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt " */
#define PDUR_DUMMY_STATEMENT(v)                     (v)=(v)
#endif
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
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
/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"
extern FUNC(void, PDUR_CODE) PduR_Init
(
    P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_APPL_CONST) ConfigPtr
);

#if (STD_ON == PDUR_VERSION_INFO_API)
extern FUNC(void, PDUR_CODE) PduR_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, PDUR_APPL_DATA) versioninfo
);
#endif /* #if (STD_ON == PDUR_VERSION_INFO_API) */

extern FUNC(PduR_PBConfigIdType, PDUR_CODE) PduR_GetConfigurationId(void);
extern FUNC(void, PDUR_CODE) PduR_EnableRouting(PduR_RoutingPathGroupIdType id);
extern FUNC(void, PDUR_CODE) PduR_DisableRouting
(
    PduR_RoutingPathGroupIdType id,
    boolean initialize
);

#if (STD_OFF == PDUR_ZERO_COST_OPERATION)
/* Route API: */
/* APIs called by upper-layer applications: */
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCancelReceive(PduIdType id);
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCancelTransmit(PduIdType id);
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_UpTransmit
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
);
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_UpChangeParameter
(
    PduIdType id,
    TPParameterType parameter,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
    uint16 value
);
/* APIs called by lower-level applications: */
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
extern FUNC(void, PDUR_CODE) PduR_LoTxConfirmation(PduIdType TxPduId);
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
extern FUNC(void, PDUR_CODE) PduR_LoTxConfirmation_44(PduIdType TxPduId, Std_ReturnType result);
extern FUNC(void, PDUR_CODE) PduR_LoRxIndication
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_LoTriggerTransmit
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
/* API called by the transport protocol layer: */
extern FUNC(void, PDUR_CODE) PduR_LoTpRxIndication(PduIdType id, Std_ReturnType result);
extern FUNC(void, PDUR_CODE) PduR_LoTpTxConfirmation(PduIdType id, Std_ReturnType result);
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) pduInfo,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);
extern FUNC(void, PDUR_CODE) PduR_MainFunction(void);
extern FUNC(void, PDUR_CODE) PduR_Diag_MainFunction(void);
#endif /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */
/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"

#endif /* #define PDUR_H_ */

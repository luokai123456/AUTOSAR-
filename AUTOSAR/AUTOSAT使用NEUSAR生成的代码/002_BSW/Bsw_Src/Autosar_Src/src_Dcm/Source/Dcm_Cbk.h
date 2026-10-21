/*
********************************************************************************
*
* File name: Dcm_Cbk.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : Tanlx/20190513
* Change: Autosar
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : Liuziyang/2019.11.21
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 1.2
* Author/Date : Songqw/2019.12.21
* Change: Modify the included header files according to the AUTOSAR 4.2.
* Cause: Bugfix
********************************************************************************
* Version: 1.3
* Author/Date : Songqw/2019.12.23
* Change: Add the "Dcm_GetTxPduIdByRxPduId" function and modify the parameter
*         type of the "Dcm_GetTxPduId" function.
* Cause: Bugfix
********************************************************************************
* Version: 3.0
* Author/Date: ZhuChunying/2020.09.03
* Change: Modify function Dcm_CopyRxData parameter type.
* Cause: Optimize
********************************************************************************
* Version: 3.1
* Author/Date: ZhuChunying/2020.09.16
* Change: Add function of MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: ZhuChunying/2020.09.18
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: SongQW/2020.12.9
* Change: Add macro "DCM_SERVICE_28_ENABLED" to control Dcm_ComM_FullComModeEntered
*         function.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: SongQW/2021.6.30
* Change: Add the macro switch of module separation.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: SongQW/2021.08.27
* Change: Move the definition position of the function "Dcm_WriteDidData" and
*         "Dcm_ReadDidData".
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: SongQW/2021.10.18
* Change: Change marco "DCM_DEM_SUPPORT" to "DCM_SERVICE_86_ENABLED".
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: SongQW/2022.01.26
* Change: Remove duplicate function declarations for "Dcm_GetSesCtrlType".
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: SongQW/2022.05.01
* Change: Add declaration for "Dcm_StartSecurityCheck" and
*         "Dcm_StopSecurityCheck" functions for security check.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: LuQi/2023.08.02
* Change: Modify macro switch DCM_SERVICE_28_ENABLED to DCM_COMM_SUPPORT.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: LiuY/2023.08.14
* Change: Fix compiler warning by adding header file.
* Cause: Bugfix
********************************************************************************
* Version: 3.11
* Author/Date: LiuY/2024.01.26
* Change: Add the declaration of the function Dcm_DslSetSecurityLevel.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: WuXJ/2024.03.13
* Change: Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: WuXJ/2024.8.7
* Change: Modify copyright information.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date: LiuY/2024.9.19
* Change: Add the declaration of function Dcm_StartOfReceptionCheck.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: WuXJ/2025.6.18
* Change: Add Polyspace annotations.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: WuXJ/2025.6.23
* Change: Add Polyspace annotations.
* Cause: Update
********************************************************************************
*/
#ifndef DCM_CBK_H_
#define DCM_CBK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Dcm_Types.h"
#include "ComStack_Types.h"
#include "Dcm_Cfg.h"

#if( STD_ON == DCM_DEM_SUPPORT )
#include "Dem.h"
#endif

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
*******************************************************************************
*/
#define DCM_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"

extern FUNC(BufReq_ReturnType, DCM_CODE) Dcm_StartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) bufferSizePtr
);
extern FUNC(BufReq_ReturnType, DCM_CODE) Dcm_StartOfReceptionCheck
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) bufferSizePtr
);
extern FUNC(BufReq_ReturnType, DCM_CODE) Dcm_CopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) bufferSizePtr
);
extern FUNC(BufReq_ReturnType, DCM_CODE) Dcm_CopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    P2VAR(RetryInfoType, AUTOMATIC, DCM_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) availableDataPtr
);
extern FUNC(void, DCM_CODE) Dcm_TpRxIndication(PduIdType id, Std_ReturnType result);
extern FUNC(void, DCM_CODE) Dcm_TpTxConfirmation(PduIdType id,Std_ReturnType result);
/* Polyspace +1 MISRA-C3:8.5 [Justified:Unset] "NSCA_Polyspace_Dcm_8.5" */
extern FUNC(void, DCM_CODE) Dcm_MainFunction(void);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(uint8, DCM_CODE) Dcm_GetRxPduIdAdrTyp(PduIdType pduId);
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(uint8, DCM_CODE) Dcm_GetTxPduIdByRxPduId(PduIdType rxPduId, P2VAR(PduIdType, AUTOMATIC, DCM_APPL_DATA) txPduId);
extern FUNC(uint8, DCM_CODE) Dcm_GetCurActiveProtocolIndex(P2VAR(PduIdType, AUTOMATIC, DCM_APPL_DATA) proIndex);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetActiveProtocol(P2VAR(Dcm_ProtocolType, AUTOMATIC, DCM_APPL_DATA) ActiveProtocol);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_SetActiveDiagnostic(boolean active);

#if( STD_ON == DCM_COMM_SUPPORT )
extern FUNC(void, DCM_CODE) Dcm_ComM_FullComModeEntered(uint8 NetworkId);
extern FUNC(void, DCM_CODE) Dcm_ComM_NoComModeEntered(uint8 NetworkId);
extern FUNC(void, DCM_CODE) Dcm_ComM_SilentComModeEntered(uint8 NetworkId);
#endif

extern FUNC(void, DCM_CODE) Dcm_Init( P2CONST(Dcm_ConfigType, AUTOMATIC, DCM_APPL_CONST) ConfigPtr );
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetVin(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);

#if( STD_ON == DCM_SERVICE_86_ENABLED )
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_TriggerOnEvent(uint8 RoeEventId);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DemTriggerOnDTCStatus
(
    uint32 DTC, Dem_UdsStatusByteType DTCStatusOld,
    Dem_UdsStatusByteType DTCStatusNew
);
#endif

extern FUNC(void, DCM_CODE) Dcm_MemSet(P2VAR(void, AUTOMATIC, CANTP_APPL_DATA) destPtr, uint8 val, uint16 cnt);
extern FUNC(uint8, DCM_CODE) Dcm_MemCmp(P2VAR(void, AUTOMATIC, CANTP_APPL_DATA) dataPtr, uint8 val, uint16 cnt);
extern FUNC(void, DCM_CODE) Dcm_MemCpy(P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) destPtr, P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) srcPtr, uint32 cnt);
/* Polyspace +1 MISRA-C3:12.1 [Justified:Unset] "NSCA_Polyspace_Dcm_12.1" */
#if ( STD_ON == DCM_SERVICE_22_ENABLED || STD_ON == DCM_SERVICE_2E_ENABLED )
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_IsDidAvailable
(
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    uint16 DID,Dcm_OpStatusType opStatus,
    P2VAR(Dcm_DidSupportedType, AUTOMATIC, DCM_APPL_DATA) supported
);
#endif /* STD_ON == DCM_SERVICE_22_ENABLED || STD_ON == DCM_SERVICE_2E_ENABLED */

#if ( DCM_SERVICE_10_ENABLED == STD_ON )
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, DCM_APPL_DATA) SesCtrlType);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_ResetToDefaultSession(void);
#endif /* DCM_SERVICE_10_ENABLED == STD_ON */

#if ( DCM_SERVICE_27_ENABLED == STD_ON )
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSecurityLevel(P2VAR(Dcm_SecLevelType, AUTOMATIC, DCM_APPL_DATA) SecLevel);
extern FUNC(void, DCM_CODE) Dcm_DslSetSecurityLevel(VAR(Dcm_SecLevelType, AUTOMATIC) SecurityLevel);
extern FUNC(void, DCM_CODE) Dcm_StartSecurityCheck(void);
extern FUNC(void, DCM_CODE) Dcm_StopSecurityCheck(void);
#endif /* DCM_SERVICE_27_ENABLED == STD_ON */

#if ( DCM_SERVICE_22_ENABLED == STD_ON )
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_ReadDidRangeDataLength
(
    uint16 DID,
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Dcm_OpStatusType opStatus,
    P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) dataLength
);
#endif /* DCM_SERVICE_22_ENABLED == STD_ON */

#if ( (STD_ON == DCM_SERVICE_22_ENABLED) || (STD_ON == DCM_SERVICE_2E_ENABLED) )
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_WriteDidData
(
    uint16 DID,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) data,
/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Dcm_OpStatusType opStatus,
    uint16 dataLength,
    Dcm_NegativeResponseCodeType errorCode
);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_ReadDidData
(
    uint16 DID,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) data,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Dcm_OpStatusType opStatus,
    uint16 dataLength,
    Dcm_NegativeResponseCodeType errorCode
);
#endif /* DCM_SERVICE_2E_ENABLED == STD_ON */

#if ( DCM_SERVICE_14_ENABLED == STD_ON )
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_ClearDTCCheckFnc
(
    uint32 goDTC,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) errorCode
);
#endif /* DCM_SERVICE_14_ENABLED == STD_ON */

#define DCM_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"

#endif  /* DCM_CBK_H_ */

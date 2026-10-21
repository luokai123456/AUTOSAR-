/*
********************************************************************************
*
* File name: LinTp.h
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: lizhiheng/2020.08.25
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: lizhiheng/2020.09.26
* Change: 1.Modify the code to AutoSar coding style.
*         2.Add memap inclusion processing.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: LiZH/2020.10.27
* Change: Modify the precompiled processing of the file.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: SunHQ/2022.12.9
* Change: Modify the included header file.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: LiXB/2023.7.9
* Change: Add missing parameter name of function LinTp_Transmit.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: TianG/2024.6.26
* Change: 1. Add a memory-map label to function.
*         2. Modify copyright.
*         3. Modify the comments format.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: YanCL/2025.06.18
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: YanCL/2025.06.23
* Change: #include "LinIf_MemMap.h" add suppression comments.
* Cause: Update
********************************************************************************
*/
#ifndef LINTP_H_
#define LINTP_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "LinTp_Types.h"

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
********************************************************************************
*/
#if( LINIF_TP_SUPPORTED == STD_ON )
#define LINIF_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"
extern FUNC(void, LINIF_CODE) LinTp_Init
(
    P2CONST(LinTp_ConfigType, AUTOMATIC, LINIF_APPL_CONST) ConfigPtr
);
extern FUNC(Std_ReturnType, LINIF_CODE) LinTp_Transmit
(
    PduIdType LinTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_CONST) LinTpTxInfoPtr
);
extern FUNC(void, LINIF_CODE) LinTp_Shutdown
(
    void
);
extern FUNC(Std_ReturnType, LINIF_CODE) LinTp_CancelTransmit
(
    PduIdType LinTpTxSduId
);
extern FUNC(Std_ReturnType, LINIF_CODE) LinTp_ChangeParameter
(
    PduIdType id,
    TPParameterType parameter,
    uint16 value
);
extern FUNC(Std_ReturnType, LINIF_CODE) LinTp_CancelReceive
(
    PduIdType LinTpRxSduId
);
extern FUNC(void, LINIF_CODE) LinTp_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, LINIF_APPL_DATA) versioninfo
);
#define LINIF_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"
#endif

#endif /* LINTP_H_ */


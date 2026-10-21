/*
********************************************************************************
*
* File name: LinIf.h
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2020.03.26
* Change: New created
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: lizhiheng/2020.06.29
* Change: Optimize code structure.
* Cause: Update
********************************************************************************
* Version: 1.2
* Author/Date: lizhiheng/2020.07.01
* Change: Tab to spaces.
* Cause: Update
********************************************************************************
* Version: 3.0
* Author/Date: lizhiheng/2020.07.01
* Change: Update to 3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: lizhiheng/2020.08.25
* Change: Function updates and modifies coding specifications.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: lizhiheng/2020.09.04
* Change: The referenced header file is added to the precompiled file.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: lizhiheng/2020.09.04
* Change: Add file precompilation.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: lizhiheng/2020.09.26
* Change: 1.Modify the code to AutoSar coding style.
*         2.Add memap inclusion processing.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: LiZH/2020.10.09
* Change: Optimized coding specification.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: LiZH/2020.10.15
* Change: Modify AutoSar style non-pointer type modification.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: LiZH/2020.10.28
* Change: Add macro definition.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: LiZH/2020.11.04
* Change:  Modify the incorrectly defined part of the code format.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: LiZH/2020.11.04
* Change: Optimized coding specification.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: LiZH/2021.01.09
* Change: Cance EcuM.h include conditional judgment.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date : LiZH/2021.04.27
* Change: Modifty version number to 3.2.0.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: LiZH/2021.10.20
* Change: Modified version number.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: SunHQ/2022.12.9
* Change: Modify the included header file.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date : SunHQ/2023.05.17
* Change: Upgrade version number.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date : SunHQ/2023.05.26
* Change: Add revision version.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date : LiXB/2023.06.30
* Change: Update revision version and minor version.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date : LiXB/2023.07.08
* Change: Update revision version and minor version.
*         Add function declaration.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date : LiXB/2023.07.20
* Change: Update revision version and minor version.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date : LiXB/2023.08.02
* Change: Update revision version and minor version.
*         Add macro judgement to function delaration of LinIf_ScheduleRequest
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date : LiXB/2023.08.15
* Change: Update revision version and minor version.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date : LiXB/2023.08.18
* Change: Update revision version and minor version.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date : LiXB/2023.10.25
* Change: 1. Update revision version and minor version.
*         2. Update version to R21-11
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: ZhangXF/2024.01.21
* Change: Update revision version and minor version.
* Cause:  Update
********************************************************************************
* Version: 3.24
* Author/Date: ZhangXF/2024.03.18
* Change: Update revision version and minor version.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: ZhangXF/2024.04.1
* Change: Update revision version and minor version.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: TianG/2024.06.27
* Change: 1. Update version to 3.11.0.11.
*         2. Add a memory-map label to function.
*         3. Modify copyright.
*         4. Modify the comments format.
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date: TianG/2024.09.03
* Change: Update version to 3.11.0.12.
* Cause:  Update
********************************************************************************
* Version: 3.28
* Author/Date: TianG/2024.09.19
* Change: Update version to 3.11.0.13.
* Cause: Update
********************************************************************************
* Version: 3.29
* Author/Date: TianG/2024.10.08
* Change: Update version to 3.11.0.14.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date: TianG/2024.10.23
* Change: Update version to 3.12.0.15.
* Cause: Update
********************************************************************************
* Version: 3.31
* Author/Date: TianG/2025.02.05
* Change: 1. Update version to 3.13.0.16.
*         2. Modify copyright.
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date: TianG/2025.02.21
* Change: Update version to 3.13.0.17.
* Cause: Update
********************************************************************************
* Version: 3.33
* Author/Date: TianG/2025.03.24
* Change: Update version to 3.13.0.18.
* Cause: Update
********************************************************************************
* Version: 3.34
* Author/Date: TianG/2025.06.16
* Change: Update version to 3.14.0.19.
* Cause: Update
********************************************************************************
* Version: 3.35
* Author/Date: YanCL/2025.06.18
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.36
* Author/Date: YanCL/2025.06.23
* Change: Update version to 3.14.0.20.
* Cause: Update
********************************************************************************
* Version: 3.37
* Author/Date: TianG/2025.07.14
* Change: Update version to 3.15.0.21.
* Cause: Update
********************************************************************************
* Version: 3.38
* Author/Date: TianSL/2025.08.18
* Change: Update version to 3.15.0.22.
* Cause: Update
********************************************************************************
*/
#ifndef LINIF_H_
#define LINIF_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "LinIf_Types.h"

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT != STD_ON) && (LINIF_TRCV_WAKEUP_SUPPORT != STD_ON) )
#include "EcuM_Types.h"
#endif

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
#include "EcuM.h"
#endif

#if( LINIF_TRCV_DRIVER_SUPPORTED == STD_ON )
#include "LinTrcv.h"
#endif

#if !defined(LINIF_WAKEUP_SUPPORT)
#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
#define LINIF_WAKEUP_SUPPORT                 (STD_OFF)
#else
#define LINIF_WAKEUP_SUPPORT                 (STD_ON)
#endif
#endif

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* LinIf module ID for Det */
#define LINIF_INSTANCE_ID               (0U)
/* LinIf version information */
#define LINIF_VENDOR_ID                 (119U)
#define LINIF_MODULE_ID                 (62U)
#define LINIF_SW_MAJOR_VERSION          (3U)
#define LINIF_SW_MINOR_VERSION          (15U)
#define LINIF_SW_PATCH_VERSION          (0U)
#define LINIF_SW_REVISION_VERSION       (22U)

/* AUTOSAR Version. */
#define LINIF_AR_RELEASE_MAJOR_VERSION     (21U)
#define LINIF_AR_RELEASE_MINOR_VERSION     (11U)
#define LINIF_AR_RELEASE_REVISION_VERSION  (0U)

#define LINIF_SHIFT_8BIT    (8U)
#define LINIF_LOW_BYTE      (0x00FFU)   /* For shift 8bit */
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* A pointer to an instance of this structure will be used in the initialization of the LIN Interface. */
/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef uint8 LinIf_ConfigType;

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
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define LINIF_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"
extern FUNC(void, LINIF_CODE) LinIf_Init
(
    P2CONST(LinIf_CongfigType, AUTOMATIC, LINIF_APPL_CONST) ConfigPtr
);
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_Transmit
(
    PduIdType LinTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_CONST) PduInfoPtr
);

#if( LINIF_MASTER_SUPPORT == STD_ON )
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_ScheduleRequest
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    LinIf_SchHandleType Schedule
);
#endif /* LINIF_MASTER_SUPPORT == STD_ON */

extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_GotoSleep
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel
);
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_Wakeup
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel
);

#if( LINIF_TRCV_DRIVER_SUPPORTED == STD_ON )
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_SetTrcvMode
(
    NetworkHandleType Channel,
    LinTrcv_TrcvModeType TransceiverMode
);
#endif

#if( LINIF_TRCV_DRIVER_SUPPORTED == STD_ON )
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_GetTrcvMode
(
    NetworkHandleType Channel,
    P2VAR(LinTrcv_TrcvModeType, AUTOMATIC, LINIF_APPL_DATA) TransceiverModePtr
);
#endif

#if( LINIF_TRCV_DRIVER_SUPPORTED == STD_ON )
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_GetTrcvWakeupReason
(
    NetworkHandleType Channel,
    P2VAR(LinTrcv_TrcvWakeupReasonType, AUTOMATIC, LINIF_APPL_DATA) TrcvWuReasonPtr
);
#endif

#if( LINIF_TRCV_DRIVER_SUPPORTED == STD_ON )
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_SetTrcvWakeupMode
(
    NetworkHandleType Channel,
    LinTrcv_TrcvWakeupModeType LinTrcvWakeupMode
);
#endif

extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_CancelTransmit
(
    PduIdType LinTxPduId
);
extern FUNC(void, LINIF_CODE) LinIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, LINIF_APPL_DATA) versioninfo
);

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_CheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
);
#endif

/* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
extern FUNC(void, LINIF_CODE) LinIf_MainFunction(uint8 Channel);

#if( LINIF_SLAVE_SUPPORT == STD_ON )
extern FUNC(void, LINIF_CODE) LinIf_RxIndication
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR) Lin_SduPtr
);
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_HeaderIndication
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_VAR) PduPtr
);
extern FUNC(void, LINIF_CODE) LinIf_LinErrorIndication
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel,
    Lin_SlaveErrorType ErrorStatus
);
extern FUNC(void, LINIF_CODE) LinIf_TxConfirmation
(
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    NetworkHandleType Channel
);
#endif /* LINIF_SLAVE_SUPPORT == STD_ON */

#if( LINIF_ADAPTED_AR_VERSION == LINIF_AR_VERSION_ABOVE_440 )
#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
extern FUNC(void, LINIF_CODE) LinIf_WakeupConfirmation
(
    EcuM_WakeupSourceType WakeupSource
);
#endif
#endif

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT != STD_ON) && (LINIF_TRCV_WAKEUP_SUPPORT != STD_ON) )
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_CheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
);

extern FUNC(void, LINIF_CODE) LinIf_WakeupConfirmation
(
    EcuM_WakeupSourceType WakeupSource
);
#endif

#if( LINIF_SLAVE_SUPPORT != STD_ON )
extern FUNC(void, LINIF_CODE) LinIf_RxIndication
(
    NetworkHandleType Channel,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR) Lin_SduPtr
);

extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_HeaderIndication
(
    NetworkHandleType Channel,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_VAR) PduPtr
);

extern FUNC(void, LINIF_CODE) LinIf_LinErrorIndication
(
    NetworkHandleType Channel,
    Lin_SlaveErrorType ErrorStatus
);

extern FUNC(void, LINIF_CODE) LinIf_TxConfirmation
(
    NetworkHandleType Channel
);
#endif

#if !defined(LINIF_DISABLE_MCAL_COMPAT)
#if( (LINIF_CHANNEL_WAKEUP_SUPPORT != STD_ON) && (LINIF_TRCV_WAKEUP_SUPPORT != STD_ON) )
extern FUNC(Std_ReturnType, LINIF_CODE) Mcal_LinIf_CheckWakeup
(
    VAR(EcuM_WakeupSourceType, LINIF_VAR) WakeupSource
);
extern FUNC(void, LINIF_CODE) Mcal_LinIf_WakeupConfirmation
(
    VAR(EcuM_WakeupSourceType, LINIF_VAR) WakeupSource
);

#define LinIf_CheckWakeup                    Mcal_LinIf_CheckWakeup
#define LinIf_WakeupConfirmation             Mcal_LinIf_WakeupConfirmation
#endif

#if( LINIF_SLAVE_SUPPORT != STD_ON )
extern FUNC(Std_ReturnType, LINIF_CODE) Mcal_LinIf_HeaderIndication
(
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
);
extern FUNC(void, LINIF_CODE) Mcal_LinIf_RxIndication
(
    VAR(NetworkHandleType, AUTOMATIC) Channel,
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr
);
extern FUNC(void, LINIF_CODE) Mcal_LinIf_TxConfirmation
(
    VAR(NetworkHandleType, AUTOMATIC) Channel
);
extern FUNC(void, LINIF_CODE) Mcal_LinIf_LinErrorIndication
(
    VAR(NetworkHandleType, AUTOMATIC) Channel,
    VAR(Lin_SlaveErrorType, AUTOMATIC) ErrorStatus
);

#define LinIf_HeaderIndication               Mcal_LinIf_HeaderIndication
#define LinIf_RxIndication                   Mcal_LinIf_RxIndication
#define LinIf_TxConfirmation                 Mcal_LinIf_TxConfirmation
#define LinIf_LinErrorIndication             Mcal_LinIf_LinErrorIndication
#endif
#endif
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define LINIF_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"

#endif /* LINIF_H_ */


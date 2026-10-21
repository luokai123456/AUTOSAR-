/*
********************************************************************************
*
* File name: CanSM.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangCong/2018.07.21
* Change: New
* Cause: New
********************************************************************************
* Version: 2.0
* Author/Date: WangCong/2018.05.29
* Change: Modify format.
* Cause: Updata to V2.0.
********************************************************************************
* Version: 2.1
* Author/Date: WangCong/2019.10.12
* Change: Modify code format.
* Cause: Unified format.
********************************************************************************
* Version: 3.0
* Author/Date: WangCong/2020.01.19
* Change: Synchronizing code with the DF project(Debugging completed).
* Cause: Updata to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: WangCong/2020.03.25
* Change: Modify header file reference.
* Cause: Clear QAC warning.
********************************************************************************
* Version: 3.2
* Author/Date: WangCong/2020.05.12
* Change: Modify the code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.3
* Author/Date: lizhiheng/2020.06.08
* Change: Add release software number.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: WangC/2020.10.23
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimize
********************************************************************************
* Version: 3.5
* Author/Date: ZhangDX/2020.11.04
* Change: 1. Modify the wrong part of the segment definition.
*         2. Remove the space after the line of code.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: LiuHJ/2021.5.28
* Change: 1. Add Interface to provide internal bus-off recovery level.
*         2. Modify the sw minor version.
* Cause: Customized requirements
********************************************************************************
* Version: 3.15
* Author/Date: LiuHJ/2021.7.15
* Change: Modify the name of function/macros/service ID which are used to provide
*         internal bus-off recovery level.
* Cause: Optimize
********************************************************************************
* Version: 3.16
* Author/Date: LiZH/2021.10.20
* Change: Modified version number.
* Cause: Optimization
********************************************************************************
* Version: 3.17
* Author/Date: LiuHJ/2021.10.28
* Change: Modify header file reference.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: LiZH/2021.11.1
* Change: Update versions.
* Cause: Optimize
********************************************************************************
* Version: 3.19
* Author/Date: ChengWB/2022.8.29
* Change: Update versions.
* Cause: Delete the state of PRE_FULLCOM of CanSM.c.
********************************************************************************
* Version: 3.20
* Author/Date: XieYN/2022.11.7
* Change: Update PATCH version.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: LiX/2023.2.17
* Change: Update PATCH version.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: LiX/2023.2.23
* Change: Update PATCH version.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: LiX/2023.2.26
* Change: Add REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: TianG/2023.8.10
* Change: Add REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: TianL/2023.8.27
* Change: Add REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: TianL/2023.11.27
* Change: Update software version to 3.9.0.2.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: TianL/2024.1.11
* Change: Update software version to 3.10.0.1.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: TianL/2024.1.15
* Change: Update software version.
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date: TianL/2024.1.30
* Change: Update software version to 3.10.0.4.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: TianL/2024.3.20
* Change: Update software version to 3.10.0.5.
* Cause: Update
********************************************************************************
* Version: 3.29
* Author/Date: TianL/2024.4.1
* Change: Update software version to 3.10.0.6.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date: TianL/2024.5.15
* Change: 1. Add a MemMap paragraph definition to the function declaration.
*         2. Modify the MemMap Memory Section of uninitialized variables.
*         3. Modify coding specifications.
*         4. Update software version to 3.11.0.7.
* Cause: Update
********************************************************************************
* Version: 3.31
* Author/Date: TianL/2024.8.5
* Change: 1. Modify copyright information.
*         2. Update software version to 3.11.0.8.
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date: TianL/2024.8.30
* Change: Update software version to 3.11.0.9.
* Cause: Update
********************************************************************************
* Version: 3.33
* Author/Date: TianL/2024.9.14
* Change: Update software version to 3.11.0.10.
* Cause: Update
********************************************************************************
* Version: 3.34
* Author/Date: TianL/2024.12.16
* Change: Update software version to 3.12.0.11.
* Cause: Update
********************************************************************************
* Version: 3.35
* Author/Date: TianL/2025.2.24
* Change: Update software version to 3.13.0.12.
* Cause: Update
********************************************************************************
* Version: 3.36
* Author/Date: TianL/2025.3.27
* Change: Update software version to 3.13.0.13.
* Cause: Update
********************************************************************************
* Version: 3.37
* Author/Date: TianL/2025.6.8
* Change: 1.Add the polyspace deviation suppression comment.
*         2.Update software version to 3.14.0.14.
* Cause: Update
********************************************************************************
* Version: 3.38
* Author/Date: TianL/2025.7.18
* Change: 1.Fix the QAC warning and add the QAC deviation suppression comment.
*         2.Update software version to 3.15.0.15.
* Cause: Update
********************************************************************************
* Version: 3.39
* Author/Date: TianL/2025.8.1
* Change: Update software version to 3.15.0.16.
* Cause: Update
********************************************************************************
*/
#ifndef CANSM_H_
#define CANSM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanSM_Lcfg.h"
#include "CanSM_Cbk.h"
#include "CanIf.h"
#include "ComM_BusSM.h"
#include "BswM_CanSM.h"

#if( CANSM_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif  /* CANSM_DEV_ERROR_DETECT == STD_ON */

#if( CANSM_REPORT_DEM_ENABLE == STD_ON )
#include "Dem.h"
#endif  /* CANSM_REPORT_DEM_ENABLE ==STD_ON */

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANSM_VENDOR_ID                                 (119U)
#define CANSM_MODULE_ID                                 (140U)
#define CANSM_SW_MAJOR_VERSION                          (3U)
#define CANSM_SW_MINOR_VERSION                          (15U)
#define CANSM_SW_PATCH_VERSION                          (0U)
#define CANSM_SW_REVISION_VERSION                       (16U)

/* AUTOSAR Version. */
#define CANSM_AR_RELEASE_MAJOR_VERSION                  (4U)
#define CANSM_AR_RELEASE_MINOR_VERSION                  (2U)
#define CANSM_AR_RELEASE_REVISION_VERSION               (2U)

/* #define CANSM_OSEKNM_ENABLE */
#ifdef CANSM_OSEKNM_ENABLE
#define D_OSEK_CAN_CONTROLLERID                         (0U)
#define D_OSEK_CAN_WAKEUP                               (0U)        /* 0 means wakeup */
#define D_OSEK_CAN_BUSOFF                               (1U)        /* 1 means busoff */
#endif  /* CANSM_OSEKNM_ENABLE */

#define CANSM_NO_BUSOFF                                 ((uint8)0x00U)
#define CANSM_BUSOFFRECOVERY_LEVEL1                     ((uint8)0x01U)
#define CANSM_BUSOFFRECOVERY_LEVEL2                     ((uint8)0x02U)

/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
#ifdef CANSM_OSEKNM_ENABLE
typedef enum
{
    D_Init_BusInit = 0U,
    D_Init_BusShutDown,
    D_Init_BusRestart,
    D_Init_BusSleep,
    D_Init_BusAwake
}D_Init_ParameterType;
#endif  /* CANSM_OSEKNM_ENABLE */

typedef uint8 CanSM_BusOffRecoveryLevelType;

/*
********************************************************************************
*    Global variables
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
#define CANSM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"

extern FUNC(void, CANSM_CODE) CanSM_Init
(
    P2CONST(CanSM_ConfigType, AUTOMATIC, CANSM_APPL_CONST) ConfigPtr
);
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_RequestComMode
(
    NetworkHandleType network,
    ComM_ModeType ComM_Mode
);
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetCurrentComMode
(
    NetworkHandleType network,
    P2VAR(ComM_ModeType, AUTOMATIC, CANSM_APPL_DATA) ComM_ModePtr
);
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_StartWakeupSource
(
    NetworkHandleType network
);
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_StopWakeupSource
(
    NetworkHandleType network
);

#if( CANSM_VERSION_INFO_API == STD_ON )
extern FUNC(void, CANSM_CODE) CanSM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANSM_APPL_DATA) VersionInfo
);
#endif  /* CANSM_VERSION_INFO_API == STD_ON */

#if( CANSM_SET_BAUDRATE_API == STD_ON )
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetBaudrate
(
    NetworkHandleType Network,
    uint16 BaudRateConfigID
);
#endif  /* CANSM_SET_BAUDRATE_API == STD_ON */

extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetIcomConfiguration
(
    NetworkHandleType Network,
    IcomConfigIdType ConfigurationId
);

#if( CANSM_TXOFFLINE_ACT_SUPPORT == STD_ON )
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetEcuPassive
(
    boolean CanSM_Passive
);
#endif  /* CANSM_TXOFFLINE_ACT_SUPPORT == STD_ON */

extern FUNC(void, CANSM_CODE) CanSM_MainFunction
(
    void
);

extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetBusOffRecoveryLevel
(
    NetworkHandleType network,
    P2VAR(CanSM_BusOffRecoveryLevelType, AUTOMATIC, CANSM_APPL_DATA) busOffRecoveryLevelPtr
);

#ifdef CANSM_OSEKNM_ENABLE
/* Start */
extern FUNC(void, CANSM_CODE) D_Init
(
    D_Init_ParameterType initParam
);
extern FUNC(void, CANSM_CODE) D_Online
(
    void
);
extern FUNC(void, CANSM_CODE) D_Offline
(
    void
);
/* End */
#endif  /* CANSM_OSEKNM_ENABLE */

#define CANSM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"

#endif  /* CANSM_H_ */

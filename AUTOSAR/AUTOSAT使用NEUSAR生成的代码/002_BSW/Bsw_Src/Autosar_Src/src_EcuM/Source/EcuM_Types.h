/*
********************************************************************************
*
* File name: EcuM_Types.h
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: GuoZY/2021.12.23
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: WangXG/2022.09.22
* Change: 1. Append ECUM supports processing that supports multi-core synchronization.
*         2. Add EcuM_ConfigParaType EcuM_DriverInitFuncSt.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: WangXG/2022.09.29
* Change: Move the EcuM.h macro definition to here.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: HeHao/2023.12.25
* Change: Add coreId in struct EcuM_WakeupSourceListType.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: HeHao/2024.04.02
* Change: Modify comments.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: TianL/2024.05.16
* Change: Modify coding specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: TianL/2024.8.5
* Change: Modify copyright.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: TianL/2024.8.14
* Change: Move application type definitions to RTE.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: TianL/2025.3.7
* Change: Add Macro ECUM_8BIT_INVALID_VALUE.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: TianL/2025.3.27
* Change: Remove the definition of NULL.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: TianL/2025.6.16
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef ECUM_TYPES_H_
#define ECUM_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Rte_EcuM_Type.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#ifndef NULL  //wjc:necceery add
#define NULL  (0U)
#endif

#define ECUM_ZERO                                   (0U)
#define ECUM_ONE                                    (1U)
#define ECUM_NUMBER_5                               (5U)
#define ECUM_NUMBER_32                              (32U)
#define ECUM_FF                                     (0xFFU)
#define ECUM_INVALID                                (0xFFU)
#define ECUM_8BIT_INVALID_VALUE                     (255U)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef uint8 EcuM_ResetType;                 /* [SWS_EcuM_04044] */
typedef uint8 EcuM_StateType;                 /* [SWS_EcuM_04039] */
typedef uint32 EcuM_WakeupSourceType;       /* [SWS_EcuM_04040] */
typedef uint8 EcuM_WakeupStatusType;        /* [SWS_EcuM_04041] */
typedef uint8 EcuM_CoreIDType;
typedef uint8 EcuM_ResourceType;
/* [SWS_EcuM_04038] */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.8" */
{
    uint32 EcuMPostBuildVariant;           /* [SWS_EcuM_02794] The structure defined in the EcuM_ConfigType type shall
                                            contain an additional post-build configuration variant identifier.
                                           (uint8/uint16/uint32 depending on algorithm to compute the identifier) */
} EcuM_ConfigType;

/* EcuM/EcuMConfiguration/EcuMCommonConfiguration/EcuMWakeupSources */
typedef struct
{
    uint32 checkWakeupTimeout;      /* EcuMCheckWakeupTimeout */
    uint32 validationTimeout;       /* EcuMValidationTimeout */
    uint8 wakeupSourceID;           /* EcuMWakeupSourceId */
    boolean wakeupSourcePolling;    /* EcuMWakeupSourcePolling */
    uint8 comChannelRef;            /* EcuMComMChannelRef */
    uint32 resetReasonRef;          /* EcuMResetReasonRef */
    /* Core that should process this wakeup source's validation timeout. */
    EcuM_CoreIDType coreId;
} EcuM_WakeupSourceListType;

/* EcuM/EcuMConfiguration/EcuMCommonConfiguration/EcuMSleepModes/EcuMSleepMode1 */
typedef struct
{
    uint8 sleepModeID;
    boolean sleepModeSuspend;
    uint8 sleepModeMcuModeRef;
    uint32 wakeupSourceMask;
} EcuM_SleepModeType;

typedef struct
{
    EcuM_CoreIDType CoreID;
    EcuM_ResourceType ResourceID;
} EcuM_ConfigParaType;

typedef struct
{
    EcuM_CoreIDType CoreID;
    void (*EcuM_InitZeroFunc_P)(void);
    void (*EcuM_InitOneFunc_P)(void);
}EcuM_DriverInitFuncSt;

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
#endif  /* ECUM_TYPES_H_ */


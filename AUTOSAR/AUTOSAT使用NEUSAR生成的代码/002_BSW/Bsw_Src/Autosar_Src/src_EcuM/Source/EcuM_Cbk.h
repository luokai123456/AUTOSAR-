/*
********************************************************************************
*
* File name: EcuM_Cbk.h
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 2.0
* Author/Date: yong.zhang/2019.11.26
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: yong.zhang/2020.07.02
* Change: Add release software number.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: fangtao/2020.09.15
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: guoziyang/2021.6.30
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: GuoZY/2021.8.16
* Change: Modify code according to Autosar specification.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: GuoZY/2021.10.28
* Change: Increase the header file to include.(Os.h)
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: GuoZY/2021.12.10
* Change: Add conditional compilation for EcuM_McuSetMode().
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: GuoZY/2021.12.10
* Change: Add EcuM.h.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: GuoZY/2021.12.13
* Change: Optimize Os header file inclusion.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: WangXG/2022.09.22
* Change: Canonical code.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: HeHao/2023.08.01
* Change: Fix redefinition warning.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: HeHao/2024.03.11
* Change: Change P2CONST's ptrclass from XXX_APPL_CONST to XXX_APPL_DATA.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: HeHao/2024.04.02
* Change: 1. Modify comments.
*         2. Change P2CONST's ptrclass.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: TianL/2024.05.16
* Change: Modify coding specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date: TianL/2024.8.5
* Change: Modify copyright.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: TianL/2025.6.16
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef ECUM_CBK_H_
#define ECUM_CBK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "EcuM.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#define DISABLE_MCAL_INTERMODULE_ASR_CHECK
#endif  /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

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
#define ECUM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"

extern FUNC(void, ECUM_CODE) EcuM_AL_SetProgrammableInterrupts(void);
extern FUNC(void, ECUM_CODE) EcuM_AL_DriverInitZero(void);
extern FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne
(
    P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONST) ConfigPtr
);
extern FUNC(boolean, ECUM_CODE) EcuM_LoopDetection(void);
extern FUNC(void, ECUM_CODE) EcuM_StartOS(AppModeType appMode);
extern FUNC(void, ECUM_CODE) EcuM_ShutdownOS(Std_ReturnType ErrCode);
extern FUNC(void, ECUM_CODE) EcuM_AL_SwitchOff(void);
extern FUNC(void, ECUM_CODE) EcuM_AL_Reset(EcuM_ResetType reset);
extern FUNC(void, ECUM_CODE) EcuM_OnGoOffTwo(void);
extern FUNC(void, ECUM_CODE) EcuM_StartCheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
);
extern FUNC(void, ECUM_CODE) EcuM_CheckWakeup
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    EcuM_WakeupSourceType wakeupSource
);
extern FUNC(void, ECUM_CODE) EcuM_EndCheckWakeup
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    EcuM_WakeupSourceType WakeupSource
);
extern FUNC(void, ECUM_CODE) EcuM_AL_DriverRestart
(
    P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONST) ConfigPtr
);
extern FUNC(void, ECUM_CODE) EcuM_GenerateRamHash(void);
extern FUNC(void, ECUM_CODE) EcuM_EnableWakeupSources
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    EcuM_WakeupSourceType wakeupSource
);
extern FUNC(void, ECUM_CODE) EcuM_DisableWakeupSources
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    EcuM_WakeupSourceType wakeupSource
);
extern FUNC(void, ECUM_CODE) EcuM_StartWakeupSources
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    EcuM_WakeupSourceType wakeupSource
);
extern FUNC(void, ECUM_CODE) EcuM_CheckValidation
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    EcuM_WakeupSourceType wakeupSource
);
extern FUNC(void, ECUM_CODE) EcuM_StopWakeupSources
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    EcuM_WakeupSourceType wakeupSource
);

#if( ECUM_NORMAL_MCU_MODEREF != ECUM_FF )
extern FUNC(void, ECUM_CODE) EcuM_McuSetMode(Mcu_ModeType McuMode);
#endif  /* ECUM_NORMAL_MCU_MODEREF != ECUM_FF */

extern FUNC(void, ECUM_CODE) EcuM_SleepActivity(void);
extern FUNC(void, ECUM_CODE) EcuM_ErrorHook(uint16 reason);
extern FUNC(void, ECUM_CODE) EcuM_OnGoOffOne(void);
extern FUNC(uint8, ECUM_CODE) EcuM_CheckRamHash(void);

#define ECUM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"

#endif  /* ECUM_CBK_H_ */


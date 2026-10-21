/*
********************************************************************************
*
* File name: LinSM.h
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
* Version: 3.0
* Author/Date: lizhiheng/2020.07.01
* Change: Update to 3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: lizhiheng/2020.07.16
* Change: Modify coding specification.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: lizhiheng/2020.07.20
* Change: Modify coding specification.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: lizhiheng/2020.09.25
* Change: Modified to AutoSar coding style.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: lizhiheng/2020.10.10
* Change: Optimized coding specification.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: lizhiheng/2020.10.10
* Change: 1.Optimized coding specification.
*         2.Modify QAC warning.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: LiZH/2020.11.04
* Change: The MemMap of the modified function declaration contains.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date : LiZH/2021.04.27
* Change: Modifty version number to 3.2.0.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: LiZH/2021.10.20
* Change: Modified version number.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date : LiZH/2021.11.1
* Change: Update versions.
* Cause: Optimize
********************************************************************************
* Version: 3.10
* Author/Date: LiuZY/2023.01.09
* Change: Modified patch number.
* Cause: Bugfix
********************************************************************************
* Version: 3.11
* Author/Date: LiuZY/2023.03.03
* Change: Modified patch number.
* Cause: Optimize
********************************************************************************
* Version: 3.12
* Author/Date: LiuZY/2023.03.13
* Change: Modified patch number.
* Cause: Optimize
********************************************************************************
* Version: 3.13
* Author/Date: ChenBQ/2023.05.22
* Change: Modified minor number and patch number.
* Cause: Optimize
********************************************************************************
* Version: 3.14
* Author/Date: ChenBQ/2023.05.26
* Change: Add REVISION Version.
* Cause: Optimize
********************************************************************************
* Version: 3.15
* Author/Date: LiXB/2023.07.01
* Change: Update minor number and revision number.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: LiXB/2023.07.08
* Change: Update minor number and revision number.
*         Add function declaration
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: LiXB/2023.07.25
* Change: Update minor number and revision number.
*         Add macro judgement of LinSM_ScheduleRequest declaration.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: LiXB/2023.08.04
* Change: Update minor number and revision number.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date:ZhangXF/2023.10.30
* Change: Update minor number and revision number.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date:ZhangXF/2024.3.18
* Change: Update minor number and revision number.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date:TianG/2024.6.25
* Change: 1. Update version to 3.11.0.7.
*         2. Add a memory-map label to function.
*         3. Modify copyright.
*         4. Modify the comments format.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date:TianG/2024.11.04
* Change: Update version to 3.12.0.8.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date:TianG/2025.03.25
* Change: 1. Update version to 3.13.0.9.
*         2. Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: YanCL/2025.06.16
* Change: 1.Add the polyspace deviation suppression comment.
*         2.Update version to 3.14.0.10.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: YanCL/2025.06.23
* Change: Update version to 3.14.0.11.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: TianG/2025.07.14
* Change: Update version to 3.15.0.12.
* Cause: Update
********************************************************************************
*/
#ifndef LINSM_H_
#define LINSM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComStack_Types.h"
#include "LinSM_Cbk.h"
#include "LinSM_Cfg.h"
#include "ComM.h"
#include "LinIf.h"
//#include "LinIf_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* LinSM module ID for Det */
#define LINSM_INSTANCE_ID               (0U)
/* LinSM version information */
#define LINSM_VENDOR_ID                 (119U)
#define LINSM_MODULE_ID                 (141U)
#define LINSM_SW_MAJOR_VERSION          (3U)
#define LINSM_SW_MINOR_VERSION          (15U)
#define LINSM_SW_PATCH_VERSION          (0U)
#define LINSM_SW_REVISION_VERSION       (12U)

/* AUTOSAR Version. */
#define LINSM_AR_RELEASE_MAJOR_VERSION     (21U)
#define LINSM_AR_RELEASE_MINOR_VERSION     (11U)
#define LINSM_AR_RELEASE_REVISION_VERSION  (0U)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* Data structure type for the post-build configuration parameters. */
typedef uint8 LinSM_ConfigType;

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
#define LINSM_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"
extern FUNC(void, LINSM_CODE) LinSM_Init
(
    P2CONST(LinSM_ConfigType, AUTOMATIC, LINSM_APPL_CONST) ConfigPtr
);

/* Polyspace +1 MISRA-C3:20.9 [Justified:Unset] "NSCA_Polyspace_LinSM_Rule20.9" */
#if( LINSM_MASTER_SUPPORT == STD_ON )  /* PRQA S 3332 */ /* NSCA_QAC_LinSM_Rule20.9 */
extern FUNC(Std_ReturnType, LINSM_CODE) LinSM_ScheduleRequest
(
    NetworkHandleType network,
    LinIf_SchHandleType schedule
);
#endif /* LINSM_MASTER_SUPPORT == STD_ON */

extern FUNC(Std_ReturnType, LINSM_CODE) LinSM_GetCurrentComMode
(
    NetworkHandleType network,
    P2VAR(ComM_ModeType, AUTOMATIC, LINSM_APPL_DATA) mode
);
extern FUNC(Std_ReturnType, LINSM_CODE) LinSM_RequestComMode
(
    NetworkHandleType network,
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Dir4.5" */
    ComM_ModeType mode
);
/* Polyspace +1 MISRA-C3:8.5 [Justified:Unset] "NSCA_Polyspace_LinSM_Rule8.5" */
extern FUNC(void, LINSM_CODE) LinSM_MainFunction
(
    void
);

/* Polyspace +1 MISRA-C3:20.9 [Justified:Unset] "NSCA_Polyspace_LinSM_Rule20.9" */
#if ( LINSM_VERSION_INFO_API == STD_ON )  /* PRQA S 3332 */ /* NSCA_QAC_LinSM_Rule20.9 */
extern FUNC(void, LINSM_CODE) LinSM_GetVersionInfo
(
    Std_VersionInfoType* versioninfo
);
#endif

/* Polyspace +1 MISRA-C3:20.9 [Justified:Unset] "NSCA_Polyspace_LinSM_Rule20.9" */
#if( LINSM_SLAVE_SUPPORT == STD_ON )  /* PRQA S 3332 */ /* NSCA_QAC_LinSM_Rule20.9 */
extern FUNC(void, LINSM_CODE) LinSM_GotoSleepIndication
(
    NetworkHandleType Channel
);
#endif /* LINIF_SLAVE_SUPPORT == STD_ON */
#define LINSM_STOP_SEC_CODE
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"

#endif /* LINSM_H_ */


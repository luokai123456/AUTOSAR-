/*
********************************************************************************
*
*  File name: WdgM.c
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangCong/2019.04.12
* Change: New
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: WangCong/2019.04.30
* Change: 1.Add Functions:
*         WdgM_CheckInternalGraphBelongTo
*         WdgM_CheckExternalGraphBelongTo
*         WdgM_CheckAllCfg
*         2.Modify Functions:
*         WdgM_CheckpointReached
*         WdgM_Init
* Cause: Following to the NEUSAR_WdgM_Software Detail Design Specification_1.0
********************************************************************************
* Version: 1.2
* Author/Date: WangCong/2019.05.15
* Change: 1.Modify Functions:
*         WdgM_CheckDeadLineSpuvInMode
*         WdgM_CheckLogicalSpuvInMode
*         WdgM_InitWdgM_SetMode
*         WdgM_ExLogical_Supervision
*         WdgM_GlobalStatusMachine
*         WdgM_Logical_Supervision
*         WdgM_Det_ErrorReport
*         WdgM_ErrorHandling
*         WdgM_InitWdgM_SetMode
* Cause: QAC Bug Fix
********************************************************************************
* Version: 1.3
* Author/Date: WangCong/2019.05.17
* Change: 1.Modify Functions:
*         WdgM_Alive_Supervision
*         WdgM_CheckpointReached
*         WdgM_DeadLine_Supervision
*         WdgM_CheckAliveSpuvInMode
*         WdgM_CheckDeadLineSpuvInMode
*         WdgM_CheckExLogicalSpuvInMode
* Cause: Following to the NEUSAR_WdgM_Code Review Report_SVN611
********************************************************************************
* Version: 1.4
* Author/Date: WangCong/2019.05.20
* Change: 1.Modify Functions:
*         WdgM_SetMode_Chk
*         WdgM_Logical_Supervision
*         WdgM_GlobalStatusMachine
*         WdgM_CheckExternalGraphBelongTo
*         WdgM_CheckExLogicalSpuvInMode
* Cause: Unit Test Bug Fix
********************************************************************************
* Version: 1.5
* Author/Date: WangCong/2019.06.18
* Change: 1.Modify Functions:
*         WdgM_Init
*         WdgM_DeInit
*         WdgM_GetMode
*         WdgM_GetFirstExpiredSEID
*         WdgM_MainFunction
*         WdgM_Logical_Supervision
*         WdgM_Det_ErrorReport
* Cause: Integration Test Bug Fix
********************************************************************************
* Version: 1.6
* Author/Date: WangCong/2019.06.25
* Change: 1.Modify Functions:
*         WdgM_SetMode
*         WdgM_GetElapsedValue
* Cause: Integration Test Bug Fix
********************************************************************************
* Version: 1.7
* Author/Date: WangCong/2019.07.15
* Change: 1.Modify Functions:
*         WdgM_DeInit
*         WdgM_Init
*         WdgM_MainFunction
*         WdgM_LocalStatusMachine
* Cause: Integration Test Bug Fix
********************************************************************************
* Version: 1.8
* Author/Date: WangCong/2019.07.19
* Change: 1.Modify Functions:
*         WdgM_Init
*         WdgM_SetMode
* Cause: Integration Test Bug Fix
********************************************************************************
* Version: 1.9
* Author/Date: WangCong/2019.07.20
* Change: 1.Modify Functions:
*         WdgM_ErrorHandling
* Cause: Integration Test Bug Fix
********************************************************************************
* Version: 1.10
* Author/Date: WangCong/2019.08.24
* Change: 1.Modify Functions:
*         WdgM_Init
*         WdgM_ExLogical_Supervision
*         WdgM_SetMode_Chk
* Cause: Integration Test and System Bug Fix
********************************************************************************
* Version: 2.0
* Author/Date: baowanglong/2019.11.26
* Change: Modify the code format
* Cause: Coding Standards
********************************************************************************
* Version: 3.0
* Author/Date: Baowanglong/2020.03.27
* Change: WdgM_SetMode_Chk function add WDGM_DUMMY_STATEMENT(CallerID)
* Cause: QAC
********************************************************************************
* Version: 3.1
* Author/Date: Baowanglong/2020.05.25
* Change: Modify the file according to the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: WuZhibin/2020.09.29
* Change: 1.Add function of MemMap
*         2.Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: WuZhibin/2020.10.13
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: WuZB/2020.11.02
* Change: Modify code format.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: WuZB/2020.11.03
* Change: Modify code format.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: WuZB/2020.11.25
* Change: Modify function comment.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: WuZB/2020.11.28
* Change: Modify code format.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: WuZB/2020.12.1
* Change: Modify the macro definition format.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: WuZB/2020.12.10
* Change: Delete redundant assignments.
* Cause: QAC
********************************************************************************
* Version: 3.10
* Author/Date: WuZB/2021.01.29
* Change: Add macro definition switch in WdgM_LocalStatusMachine.
* Cause: Compile Error.
********************************************************************************
* Version: 3.11
* Author/Date: WuZB/2021.04.21
* Change: Modify the name of the macro definition.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: WuZB/2021.10.27
* Change: Delete redundant MemMap files.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: WuZB/2022.01.04
* Change: Modify "WDGM_E_NO_INIT" to "WDGM_E_UNINIT".
* Cause: Bugfix
********************************************************************************
* Version: 3.14
* Author/Date: WangXG/2022.06.20
* Change: Modify the null logic of the input parameter in the function "WdgM_CheckExternalGraphBelongTo", Eliminate compile warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date: WangXG/2022.06.27
* Change: Modify Function WdgM_Logical_Supervision.
* Cause: Corresponding new functions.
********************************************************************************
* Version: 3.16
* Author/Date: WangXG/2022.09.22
* Change: Added WdgM support for multi-core functionality
* Cause: Corresponding new functions.
********************************************************************************
* Version: 3.17
* Author/Date: WangXG/2022.09.30
* Change: Remove OS_Types_Lcfg.h
* Cause: Bugfix
********************************************************************************
* Version: 3.18
* Author/Date: WangXG/2022.10.18
* Change: Remove WDGM_SPIN_LOCK_USED Macros
* Cause: Bugfix
********************************************************************************
* Version: 3.19
* Author/Date: WangXG/2022.10.21
* Change: Remove Spinlock in function GlobalStatusMachine 
* Cause: Bugfix
********************************************************************************
* Version: 3.20
* Author/Date: WangXG/2022.10.25
* Change: Remove Debugtype
* Cause: Optimization
********************************************************************************
* Version: 3.21
* Author/Date: WangXG/2023.03.03
* Change: Initial session supporting multi-core wdg
* Cause: Optimization
********************************************************************************
* Version: 3.22
* Author/Date: XuYH/2023.08.07
* Change: Modify WdgM_MainFunction SetMode Process
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date: XuYH/2023.08.08
* Change: Modify WdgM_CoreSetModeFinishFlag static
* Cause: Optimization
********************************************************************************
* Version: 3.24
* Author/Date : XuYH/2023.11.21
* Change: Modify include Os.h
* Cause: Optimization
********************************************************************************
* Version: 3.25
* Author/Date: LiuY/2024.03.18
* Change: 1. Modify version number.
*         2. Associate supervised entity with mode in logical supervision
*            of internal Graphs.
*         3. Fix compile warning.
*         4. Modify "MULTI_CORE_SUPPORTED" to "STD_ON".
* Cause: Bugfix
********************************************************************************
* Version: 3.26
* Author/Date: LiuY/2024.04.01
* Change: To switch on and off the Logical Supervision of 
*         an Internal Graph depending on the mode(WdgMLocalStatusParams) 
*         and SE(WdgMInternalTransition).
* Cause: Bugfix
********************************************************************************
* Version: 3.27
* Author/Date: LiuY/2024.06.12
* Change: Modify the input parameters of the function WdgM_SetMode to
*         adapt to different AUTOSAR versions.
* Cause: Bugfix
********************************************************************************
* Version: 3.28
* Author/Date: LiuY/2024.07.26
* Change: Add Memmap segment definition.
* Cause: Update
********************************************************************************
* Version: 3.29
* Author/Date: LiuY/2024.08.02
* Change: Update copyright information.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date: LiuY/2024.10.09
* Change: Modify the Memmap of multicore variables.
* Cause: Update
********************************************************************************
* Version: 3.31
* Author/Date: LiuY/2024.10.12
* Change: Fix ptrclass type of function.
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date: Chixp/2025.2.12
* Change: Update code comments.
* Cause: Update
********************************************************************************
* Version: 3.33
* Author/Date: LiuY/2025.02.27
* Change: Add Mode-Switch interfaces for notificating the change of
*         Global/Local Supervision Status.
* Cause: Update
********************************************************************************
* Version: 3.34
* Author/Date: LiuY/2025.03.07
* Change: Add function of the multi-core synchronous monitoring mechanism.
* Cause: Update
********************************************************************************
* Version: 3.35
* Author/Date: LiuY/2025.03.26
* Change: Delete the limitation that WdgM_SetMode function can only be
*         called in the master core.
* Cause: Bugfix
********************************************************************************
* Version: 3.36
* Author/Date: Chixp/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.37
* Author/Date: Chixp/2025.04.03
* Change: Modify WdgM_mainFunction to clear the state of the ALive SE in the previous
*         mode during the same time period after the mode switch is completed.
* Cause: Bugfix
********************************************************************************
* Version: 3.38
* Author/Date: Chixp/2025.06.05
* Change: Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
* Cause: Update
********************************************************************************
* Version: 3.39
* Author/Date: Chixp/2025.06.18
* Change: Update the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.40
* Author/Date: Chixp/2025.06.20
* Change: When checking the alive type of SE in WdgM_CheckpointReached,
*         modify it to use the configuration of the currently retrieved SE for the check.
* Cause: Bugfix
********************************************************************************
* Version: 3.41
* Author/Date: Chixp/2025.06.23
* Change: Update the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.42
* Author/Date: Chixp/2025.06.25
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Include
********************************************************************************
*/
#include "WdgIf.h"
#include "Rte_WdgM.h"
#include "WdgM.h"
#include "SchM_WdgM.h"
#include "Mcu.h"
#include "Os.h"


#ifdef WDGM_DEM_ENABLE 
#include "Dem.h"
#endif

#if( WDGM_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif

#include "BswM_WdgM.h"
#include "ExternalWdg_Ctrl.h"

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
#define WDGM_START_SEC_GLOBAL_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */  /* NSCA_QAC_Common_MemMap */

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_Unreviewed" */
static VAR(WdgM_SEGlobalInfoType, WDGM_VAR_INIT) WdgM_GlobalInfo =
{
    WDGM_VALUE_ZERO
};

#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_Unreviewed" */
static VAR(uint8, WDGM_VAR_INIT) WdgM_CoreSetModeFinishFlag[WDGM_CORE_NUM] = { WDGM_VALUE_ZERO };
#endif

#define WDGM_STOP_SEC_GLOBAL_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */  /* NSCA_QAC_Common_MemMap */

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
#define WDGM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */  /* NSCA_QAC_Common_MemMap */
static FUNC(void, WDGM_CODE) WdgM_Alive_Supervision
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
);
static FUNC(void, WDGM_CODE) WdgM_DeadLine_Supervision
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
);
static FUNC(void, WDGM_CODE) WdgM_Logical_Supervision
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
);
static FUNC(void, WDGM_CODE) WdgM_ExLogical_Supervision
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr,
    P2VAR(WdgM_ExLogicalSupervisionType, AUTOMATIC, WDGM_APPL_DATA) ExternalLogicalSpvCfg
);
static FUNC(void, WDGM_CODE) WdgM_LocalStatusMachine
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
);
static FUNC(void, WDGM_CODE) WdgM_FisrtExpiredSEID_Record
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
);
static FUNC(void, WDGM_CODE) WdgM_GlobalStatusMachine(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr
);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
static FUNC(void, WDGM_CODE) WdgM_Det_ErrorReport(uint8 ApiId, uint8 errorId);
static FUNC_P2CONST(WdgM_SEGType, WDGM_APPL_CONST, WDGM_CODE) WdgM_SEID_Chk
(
    WdgM_SupervisedEntityIdType SEID
);
static FUNC(uint8, WDGM_CODE) WdgM_CheckpointID_Chk
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr,
    WdgM_CheckpointIdType CheckpointID
);
#if ( WDGM_GENERAL_VERSION == WDGM_AUTOSAR422 )
static FUNC_P2CONST(WdgM_ModeStructType, WDGM_APPL_CONST, WDGM_CODE) WdgM_SetMode_Chk
(
    WdgM_ModeType Mode,
    uint16 CallerID,
    P2VAR(uint8, AUTOMATIC, WDGM_APPL_DATA) retBuf
);
#else
static FUNC_P2CONST(WdgM_ModeStructType, WDGM_APPL_CONST, WDGM_CODE) WdgM_SetMode_Chk
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    WdgM_ModeType Mode,
    P2VAR(uint8, AUTOMATIC, WDGM_APPL_DATA) retBuf
);
#endif  /* WDGM_GENERAL_VERSION == WDGM_AUTOSAR422 */
static FUNC(uint8, WDGM_CODE) WdgM_GetElapsedValue
(
    CounterType CounterID,TickRefType Value,
    TickRefType ElapsedValue
);
static FUNC(void, WDGM_CODE) WdgM_ErrorHandling
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr
);
static FUNC(void, WDGM_CODE) WdgM_CheckAliveSpuvInMode
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr,
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
);
static FUNC(void, WDGM_CODE) WdgM_CheckDeadLineSpuvInMode
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr,
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
);
static FUNC(void, WDGM_CODE) WdgM_CheckExLogicalSpuvInMode
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr,
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
);
static FUNC(void, WDGM_CODE) WdgM_CheckLogicalSpuvInMode
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr,
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
);
static FUNC(void, WDGM_CODE) WdgM_SESpuvCfgInMode
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr,
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
);
static FUNC_P2CONST(WdgM_ModeStructType, WDGM_APPL_CONST, WDGM_CODE) WdgM_SearchModePtr
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    WdgM_ModeType Mode
);
static FUNC(boolean, WDGM_CODE) WdgM_CheckInternalGraphBelongTo
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr,
    WdgM_CheckpointIdType CheckpointID,
    P2VAR(boolean, AUTOMATIC, WDGM_APPL_DATA) GetSourceCheckPointTickFlag_Pra
);
static FUNC_P2VAR(WdgM_ExLogicalSupervisionType, WDGM_APPL_DATA, WDGM_CODE) WdgM_CheckExternalGraphBelongTo
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr,
    WdgM_CheckpointRefType CheckpointRef,
    P2VAR(boolean, AUTOMATIC, WDGM_APPL_DATA) ExternalGraphFlagPtr
);
static FUNC(Std_ReturnType, WDGM_CODE) WdgM_CheckAllCfg(void);

#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
static FUNC(Std_ReturnType, WDGM_CODE) WdgM_Exponentiation(uint8 BaseNumber, uint8 ExponentsNumber);
#endif /* WDGM_MULTICORE_SUPPORT == STD_ON */

#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
static FUNC(void, WDGM_CODE) WdgM_SetCoreSetModeFinishFlag(void);
#endif

#if ( WDGM_STATECOMBINER_SUPPORT == STD_ON )
static FUNC(void, WDGIF_CODE) WdgM_StateCombinerSetTriggerCondition
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr,
    uint8 wdgIfModeFilter,
    WdgM_TriggerConditionValueType timeout
);
#endif  /* WDGM_STATECOMBINER_SUPPORT == STD_ON */

#define WDGM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */  /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define WDGM_START_SEC_GLOBAL_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */  /* NSCA_QAC_Common_MemMap */

/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_Unreviewed" */
VAR(uint8, WDGM_VAR_INIT) WdgM_AllCoreInitSync = WDGM_VALUE_ZERO;
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_WdgM_Unreviewed" */
VAR(uint8, WDGM_VAR_INIT) WdgM_AllCoreSetModeSync = WDGM_VALUE_ZERO;

#define WDGM_STOP_SEC_GLOBAL_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */  /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define WDGM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */  /* NSCA_QAC_Common_MemMap */
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: WdgM_SetCoreSetModeFinishFlag
*
* Explanation: WdgM Set Core SetModeFinish Flag.
*
* param: ConfigPtr: None.
*
* retval: None
********************************************************************************
*/
static FUNC(void, WDGM_CODE) WdgM_SetCoreSetModeFinishFlag(void)
{
    WdgM_SENumType seCnt;
    for( seCnt = WDGM_VALUE_ZERO; seCnt < WDGM_CORE_NUM; seCnt++ )
    {
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_WdgM_Rule14.3" */
        if( SENumInCore[seCnt] > WDGM_VALUE_ZERO )
        {
            WdgM_CoreSetModeFinishFlag[seCnt] = TRUE;
        }
    }
}
#endif

/*
********************************************************************************
* Function Name: WdgM_Init
*
* Explanation: WdgM Module Initialize.
*
* param: ConfigPtr: Configuration information.
*
* retval: None
********************************************************************************
*/
FUNC(void, WDGM_CODE) WdgM_Init
(
    P2CONST(WdgM_ConfigType, AUTOMATIC, WDGM_APPL_CONST) ConfigPtr
)
{
    boolean breakFlag = FALSE;
    Std_ReturnType wdgIfstdRet = E_NOT_OK;
    Std_ReturnType stdRet;
    WdgM_TriggerNumType cnt;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    uint8 errorId = WDGM_E_NO_ERR;
    WdgM_SENumType seCnt;
    const WdgM_SEGType* seGPtr;
    const WdgM_ModeStructType* modePtr;
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    WdgM_CoreNumType CoreCnt;
    (void)GetSpinlock(WDGM_SPIN_LOCK);
#else
    WdgM_SENumType seNum = WDGM_SE_ALL_NUM;
#endif/*WDGM_MULTICORE_SUPPORT == STD_ON*/
    WDGM_DUMMY_STATEMENT(ConfigPtr);
    stdRet = WdgM_CheckAllCfg();    /* Check all configurations. */
    if( E_OK == stdRet )
    {
        /* [SWS_WdgM_00135] The function WdgM_Init shall establish the initial mode of the Watchdog Manager module */
        modePtr = WdgM_SearchModePtr(WDGM_INITIAL_MODE);    /* Mode default Cfg:WdgMInitialMode */
        if( NULL_PTR != modePtr )
        {
            /*[SWS_WdgM_00018]  initialize all module variables */
#if( WDGM_MULTICORE_SUPPORT == STD_ON )
        if( MASTER_CORE_ID == (WdgM_CoreIdType)GetCoreID() )
        {
            for( CoreCnt = WDGM_VALUE_ZERO; CoreCnt < WDGM_CORE_NUM; CoreCnt++)
            {
                for( seCnt = WDGM_VALUE_ZERO; seCnt < SENumInCore[CoreCnt]; seCnt++ )
                {
                    seGPtr = WdgM_SEG_Core_Ptr_Array[CoreCnt][seCnt];
#else
                for( seCnt = WDGM_VALUE_ZERO; seCnt < seNum; seCnt++ )
                {
                    seGPtr = WdgM_SEG_Ptr[seCnt];
#endif/*WDGM_MULTICORE_SUPPORT == STD_ON*/
                    seGPtr->SEVariable->AliveFailedCnt = WDGM_VALUE_ZERO;
                    seGPtr->SEVariable->AliveIndicationCnt = WDGM_VALUE_ZERO;
                    seGPtr->SEVariable->AliveSupervisionCycCnt = WDGM_VALUE_ZERO;
                    seGPtr->SEVariable->AliveSpvStatus = WDGM_AlLIVE_CORRECT;
                    seGPtr->SEVariable->CurrentCheckpointId = seGPtr->InternalCheckpointInitial;
                    seGPtr->SEVariable->PreviousCheckpointId = seGPtr->InternalCheckpointInitial;
                    seGPtr->SEVariable->DeadLineSpvStatus = WDGM_DEADLINE_CORRECT;
                    seGPtr->SEVariable->ElapsedTick = WDGM_VALUE_ZERO;
                    seGPtr->SEVariable->LocalStatus = WDGM_LOCAL_STATUS_OK;
                    seGPtr->SEVariable->LogicalSpvStatus = WDGM_LOGICAL_CORRECT;
                    seGPtr->SEVariable->PreviousTick = WDGM_VALUE_ZERO;
                    seGPtr->SEVariable->LogicalActiveFlag = FALSE;  /* [SWS_WdgM_00296] */
                    seGPtr->SEVariable->SupervisedEntityEnable = WDGM_ALL_SPV_DISABLE;
                    WdgM_SESpuvCfgInMode(modePtr,seGPtr);
                }/*for seCnt*/

#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
            }/* FOR CORECNT */
        }/*MASTER_CORE_ID == GetCoreID()*/
#endif/*WDGM_MULTICORE_SUPPORT == STD_ON*/


#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
            if( MASTER_CORE_ID == (WdgM_CoreIdType)GetCoreID() )
#endif
            {
                WdgM_GlobalInfo.ExpiredSupervisionCycCnt = WDGM_VALUE_ZERO;
                WdgM_GlobalInfo.ExpiredSupervisionCycCntCfg = modePtr->ExpiredSupervisionCycCnt;
                WdgM_GlobalInfo.FirstExpFlag = FALSE;
                WdgM_GlobalInfo.FirstExpSEId = WDGM_FIRSTEXPSEID_INVALID;
                WdgM_GlobalInfo.GlobalStatus = WDGM_GLOBAL_STATUS_OK;   /* [SWS_WdgM_00285] */
                WdgM_GlobalInfo.InverseFirstExpSEId = WDGM_FIRSTEXPSEID_INVALID;
                WdgM_GlobalInfo.CurrentModePtr = modePtr;
                WdgM_GlobalInfo.SetModePtr = modePtr;
                WdgM_GlobalInfo.setModeFlag = FALSE;
                WdgM_GlobalInfo.PerformResetFlag = FALSE;
            }
            for( cnt = WDGM_VALUE_ZERO; cnt < modePtr->TriggerNum; cnt++ )
            {
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
                if( modePtr->Trigger[cnt].TriggerCoreRefID == (WdgM_CoreIdType)GetCoreID() )
#endif
                {
                    /* polyspace +1 DEFECT:USELESS_WRITE [Justified:Unset] "NSCA_Polyspace_WdgM_USELESS_WRITE" polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
                    wdgIfstdRet = E_NOT_OK;
                    /* If the WdgMOffModeEnabled switch is not enabled and input mode is WDGIF_OFF_MODE. */
                    /* polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 MISRA-C3:2.2 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_WdgM_Rule14.3" */
                    if( (WDGM_OFFMODE_ENABLE != STD_ON)
                        && (WDGIF_OFF_MODE == modePtr->Trigger[cnt].WatchdogMode) )
                    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                    {
                        errorId = WDGM_E_DISABLE_NOT_ALLOWED;
                        breakFlag = TRUE;
                    }
                    else
                    {
#if ( WDGM_STATECOMBINER_SUPPORT == STD_ON )
                        /* If the trigger is not slave node. */
                        if( (WDGM_STATECOMBINER_MASTERTRIGGER == modePtr->StateCombinerTriggerAssign[cnt]) ||
                            (WDGM_STATECOMBINER_CONFNOTRIGGER == modePtr->StateCombinerTriggerAssign[cnt]) )
                        {
                            wdgIfstdRet = WdgIf_SetMode(modePtr->Trigger[cnt].DeviceIndex,
                                                        modePtr->Trigger[cnt].WatchdogMode);
                        }
                        else
                        {
                            /* If the trigger is slave node, it does not call WdgIf module and return OK. */
                            wdgIfstdRet = E_OK;
                        }
#else
                        /* Based on Mode,activate all WatchDogs. */
                        wdgIfstdRet = WdgIf_SetMode(modePtr->Trigger[cnt].DeviceIndex,
                                                    modePtr->Trigger[cnt].WatchdogMode);
#endif  /* WDGM_STATECOMBINER_SUPPORT == STD_ON */
                        wdgIfstdRet = E_OK;
                        if( E_OK != wdgIfstdRet )
                        {

                            /* report WDGM_E_SET_MODE to Dem. */
#ifdef WDGM_E_SET_MODE_EVENTID
                            Dem_ReportErrorStatus(WDGM_E_SET_MODE_EVENTID, DEM_EVENT_STATUS_FAILED);
#endif /* WDGM_E_SET_MODE_EVENTID */

                            errorId = WDGM_E_SET_MODE;
                            WdgM_GlobalInfo.GlobalStatus = WDGM_GLOBAL_STATUS_STOPPED;  /* SWS_WdgM_00139 */
                            breakFlag = TRUE;
                        }
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
                /*MultiCore Sync*/
                        else
                        {
                            WdgM_AllCoreInitSync |= (uint8)(WDGM_VALUE_ONE<<cnt);
                        } 
#endif
                    }

                    if( TRUE == breakFlag ) /* If there is an error then break loop. */
                    {
                        break;
                    }
                }
            }
            if( (E_OK == wdgIfstdRet) || (WDGM_VALUE_ZERO == modePtr->TriggerNum) )
            {
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
                /*MultiCore Sync*/
                if( (WdgM_AllCoreInitSync == WdgM_Exponentiation(WDGM_VALUE_TWO,modePtr->TriggerNum)) && (WDGM_VALUE_ZERO != modePtr->TriggerNum) )
                {
                    WdgM_GlobalInfo.InitFlag = WDGM_INIT_TRUE; 
                }
                else if( WDGM_VALUE_ZERO == modePtr->TriggerNum )
                /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    WdgM_GlobalInfo.InitFlag = WDGM_INIT_TRUE; 
                }
                else
                {
                    /*do nothing*/
                }
#else
                 WdgM_GlobalInfo.InitFlag = WDGM_INIT_TRUE;    /* set Init Flag to True. */
#endif
#if ( WDGM_STATECOMBINER_SUPPORT == STD_ON )
                /* Initialize state combiner counter variable. */
                for( cnt = WDGM_VALUE_ZERO; cnt < WDGM_TRIGGER_MAXNUM; cnt++ )
                {
                    WdgM_StateCombineCycleCnt[cnt] = WDGM_VALUE_ZERO;
                }
#endif  /* WDGM_STATECOMBINER_SUPPORT == STD_ON */
            }
        }
        else
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = WDGM_E_PARAM_MODE;
        }
    }/*( NULL_PTR != modePtr )*/
    else
    {
        errorId = WDGM_E_MODULE_CONFIG;
    }
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)ReleaseSpinlock(WDGM_SPIN_LOCK);
#endif /*( WDGM_MULTICORE_SUPPORT == STD_ON )*/
    WdgM_Det_ErrorReport(WDGM_SERVICEID_INIT, errorId);
}

/*
********************************************************************************
* Function Name: WdgM_DeInit
*
* Explanation: De-initializes the Watchdog Manager,called by EcuM or BswM,
*              BSW components which are still in-service(like the BswM or the EcuM)
*              have to care about the triggering of the hardware watchdogs
*              while the Watchdog Manager module is deactivated.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, WDGM_CODE) WdgM_DeInit(void)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    uint8 errorId = WDGM_E_NO_ERR;
#if ( WDGM_STATECOMBINER_SUPPORT != STD_ON )
    WdgM_TriggerNumType cnt;
#endif  /* WDGM_STATECOMBINER_SUPPORT != STD_ON */
    const WdgM_ModeStructType* modePtr;

    /* Check if WDGM has been initialized. */
    if( WDGM_INIT_TRUE != WdgM_GlobalInfo.InitFlag )
    {
        errorId = WDGM_E_UNINIT;
    }
    else
    {
        /* If the Global Supervision Status was WDGM_GLOBAL_STATUS_OK. */
        if( WDGM_GLOBAL_STATUS_OK == WdgM_GlobalInfo.GlobalStatus )
        {
            /* [SWS_WdgM_00286] */
            WdgM_GlobalInfo.GlobalStatus = WDGM_GLOBAL_STATUS_DEACTIVATED;
            /* set the trigger conditions of all running watchdogs. */
            modePtr = WdgM_GlobalInfo.CurrentModePtr;
#if ( WDGM_STATECOMBINER_SUPPORT == STD_ON )
            /* Call the WdgM SetTriggerCondition function instead of WdgIf. */
            WdgM_StateCombinerSetTriggerCondition(modePtr, WDGM_STATECOMBINER_WDGIFALLMODE,
                                                  modePtr->Trigger[modePtr->StateCombinerMasterTriggerID].TriggerConditionValue);
#else
            /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
            for( cnt = WDGM_VALUE_ZERO; cnt < modePtr->TriggerNum; cnt++ )
            {
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
                if( modePtr->Trigger[cnt].TriggerCoreRefID == (WdgM_CoreIdType)GetCoreID() )
#endif
                {
                    WdgIf_SetTriggerCondition(modePtr->Trigger[cnt].DeviceIndex, modePtr->Trigger[cnt].TriggerConditionValue);
                }
            }
#endif  /* WDGM_STATECOMBINER_SUPPORT == STD_ON */
        }
    }
    WdgM_Det_ErrorReport(WDGM_SERVICEID_DEINIT, errorId);
}

#if( WDGM_VERSION_INFO_API == STD_ON )
/*
********************************************************************************
* Function Name: WdgM_GetVersionInfo
*
* Explanation: Returns the version information of this module.
*
* param: VersionInfo: Pointer to where to store the version information
*                     of the module WdgM.
*
* retval: None
********************************************************************************
*/
FUNC(void, WDGM_CODE) WdgM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, WDGM_APPL_DATA) VersionInfo
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    uint8 errorId = WDGM_E_NO_ERR;

    if( NULL_PTR == VersionInfo )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = WDGM_E_INV_POINTER;
    }
    else
    {
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_WdgM_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.14" */
        VersionInfo->vendorID = WDGM_VENDOR_ID;
        VersionInfo->moduleID = WDGM_MODULE_ID;
        VersionInfo->sw_major_version = WDGM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = WDGM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = WDGM_SW_PATCH_VERSION;
    }

    WdgM_Det_ErrorReport(WDGM_SERVICEID_GETVERSIONINFO, errorId);
}
#endif  /* WDGM_VERSION_INFO_API == STD_ON */

/*
********************************************************************************
* Function Name: WdgM_SetMode
*
* Explanation: Sets the current mode of Watchdog Manager.
*
* param: Mode: One of the configured Watchdog Manager modes.
*        CallerID: Module ID of the calling module.
*
* retval: E_OK: Successfully changed to the new mode.
*         E_NOT_OK: Changing to the new mode failed.
********************************************************************************
*/
#if ( WDGM_GENERAL_VERSION == WDGM_AUTOSAR422 )
FUNC(Std_ReturnType, WDGM_CODE) WdgM_SetMode(WdgM_ModeType Mode, uint16 CallerID)
#else
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
FUNC(Std_ReturnType, WDGM_CODE) WdgM_SetMode(WdgM_ModeType Mode)
#endif  /* WDGM_GENERAL_VERSION == WDGM_AUTOSAR422 */
{
    boolean breakFlag = FALSE;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    uint8 errorId = WDGM_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;
    Std_ReturnType wdgIfStdRet;
    WdgM_TriggerNumType cnt;
    const WdgM_ModeStructType* modePtr;
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)GetSpinlock(WDGM_SPIN_LOCK);
#endif /* WDGM_MULTICORE_SUPPORT == STD_ON */
    /* Check if the input parameters are correct. */
#if ( WDGM_GENERAL_VERSION == WDGM_AUTOSAR422 )
    modePtr = WdgM_SetMode_Chk(Mode, CallerID, &errorId);
#else
    modePtr = WdgM_SetMode_Chk(Mode, &errorId);
#endif  /* WDGM_GENERAL_VERSION == WDGM_AUTOSAR422 */
    if( (errorId == WDGM_E_NO_ERR) && (NULL_PTR != modePtr) )
    {
          /* [SWS_WdgM_00021]WDGM_E_UNINIT */
        if( WDGM_INIT_TRUE != WdgM_GlobalInfo.InitFlag )
        {
            errorId = WDGM_E_UNINIT;
        }
        else
        {
            /* Check input mode parameter is current mode. */
            if( modePtr != WdgM_GlobalInfo.CurrentModePtr )
            {
                /* [SWS_WdgM_00145] */
                if( (WDGM_GLOBAL_STATUS_OK == WdgM_GlobalInfo.GlobalStatus)
                    || (WDGM_GLOBAL_STATUS_FAILED == WdgM_GlobalInfo.GlobalStatus) )
                {

                    for( cnt = WDGM_VALUE_ZERO; cnt < modePtr->TriggerNum; cnt++ )
                    {
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
                        if( modePtr->Trigger[cnt].TriggerCoreRefID == (WdgM_CoreIdType)GetCoreID() )
#endif
                        {
                            /* If the WdgMOffModeEnabled switch is not enabled
                                and input mode is WDGIF_OFF_MODE. */
                            /* polyspace +1 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_WdgM_Rule14.3" */
                            if( (WDGM_OFFMODE_ENABLE != STD_ON)
                                && (WDGIF_OFF_MODE == modePtr->Trigger[cnt].WatchdogMode) )
                            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                            {
                                stdRet = E_NOT_OK;
                                errorId = WDGM_E_DISABLE_NOT_ALLOWED;
                                breakFlag = TRUE;
                            }
                            else
                            {
#if ( WDGM_STATECOMBINER_SUPPORT == STD_ON )
                                /* If the trigger is not slave node. */
                                if( (WDGM_STATECOMBINER_MASTERTRIGGER == modePtr->StateCombinerTriggerAssign[cnt]) ||
                                    (WDGM_STATECOMBINER_CONFNOTRIGGER == modePtr->StateCombinerTriggerAssign[cnt]) )
                                {
                                    /* Call wdg SetMode function. */
                                    wdgIfStdRet = WdgIf_SetMode(modePtr->Trigger[cnt].DeviceIndex,
                                                                modePtr->Trigger[cnt].WatchdogMode);
                                }
                                else
                                {
                                    /* If the trigger is slave node, it does not call WdgIf module and return OK. */
                                    wdgIfStdRet = E_OK;
                                }
#else
                                /* Call wdg SetMode function. */
                                wdgIfStdRet = WdgIf_SetMode(modePtr->Trigger[cnt].DeviceIndex,
                                                            modePtr->Trigger[cnt].WatchdogMode);
#endif  /* WDGM_MULTICORE_SUPPORT == STD_ON */

                                if( E_OK != wdgIfStdRet )
                                {
                                    /* report WDGM_E_SET_MODE to Dem. */
                                    stdRet = E_NOT_OK;
        #ifdef WDGM_E_SET_MODE_EVENTID
                                    Dem_ReportErrorStatus(WDGM_E_SET_MODE_EVENTID, DEM_EVENT_STATUS_FAILED);
        #endif /* WDGM_E_SET_MODE_EVENTID */

                                    WdgM_GlobalInfo.GlobalStatus = WDGM_GLOBAL_STATUS_STOPPED;  /* SWS_WdgM_00139 */
                                    errorId = WDGM_E_SET_MODE;
                                    breakFlag = TRUE;
                                }
                                else
                                {
        #if ( WDGM_MULTICORE_SUPPORT == STD_ON )
                                    WdgM_AllCoreSetModeSync |= (uint8)(WDGM_VALUE_ONE<<cnt);
        #endif
                                    stdRet = E_OK;
                                }
                            }
                            if( TRUE == breakFlag ) /* If there is an error then break loop. */
                            {
                                break;
                            }
                        }
                    }
                    if( E_OK == stdRet )
                    {
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
                        if( WdgM_AllCoreSetModeSync == WdgM_Exponentiation(WDGM_VALUE_TWO,modePtr->TriggerNum) )
#endif
                        {
#if ( WDGM_STATECOMBINER_SUPPORT == STD_ON )
                            /* Initialize state combiner counter variable. */
                            for( cnt = WDGM_VALUE_ZERO; cnt < WDGM_TRIGGER_MAXNUM; cnt++ )
                            {
                                WdgM_StateCombineCycleCnt[cnt] = WDGM_VALUE_ZERO;
                            }
#endif  /* WDGM_STATECOMBINER_SUPPORT == STD_ON */
                            WdgM_GlobalInfo.SetModePtr = modePtr;
                            WdgM_AllCoreSetModeSync = WDGM_VALUE_ZERO;
                        }
                        WdgM_GlobalInfo.setModeFlag = TRUE;
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
                        WdgM_SetCoreSetModeFinishFlag();
#endif 
                    }
                }
                else
                {
                    WdgM_GlobalInfo.setModeFlag = TRUE;
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
                    WdgM_SetCoreSetModeFinishFlag();
#endif
                    stdRet = E_NOT_OK;
                }
            }
            else
            {
                stdRet = E_OK;
            }
        }
    }
    WdgM_Det_ErrorReport(WDGM_SERVICEID_SETMODE, errorId);
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)ReleaseSpinlock(WDGM_SPIN_LOCK);
#endif /*( WDGM_MULTICORE_SUPPORT == STD_ON )*/
    return stdRet;
}

/*
********************************************************************************
* Function Name: WdgM_GetMode
*
* Explanation: Gets the current mode of Watchdog Manager.
*
* param: Mode: Current mode of the Watchdog Manager.
*
* retval: E_OK: Current mode successfully returned.
*         E_NOT_OK: Returning current mode failed.
********************************************************************************
*/
FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetMode
(
    P2VAR(WdgM_ModeType, AUTOMATIC, WDGM_APPL_DATA) Mode
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    uint8 errorId = WDGM_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)GetSpinlock(WDGM_SPIN_LOCK);
#endif
    if( NULL_PTR == Mode )  /* Check if the input parameters are empty. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = WDGM_E_INV_POINTER;
    }
     /* [SWS_WdgM_00021]WDGM_E_UNINIT */
    else if( WDGM_INIT_TRUE != WdgM_GlobalInfo.InitFlag )
    {
        errorId = WDGM_E_UNINIT;
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_WdgM_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.14" */
        *Mode = WdgM_GlobalInfo.CurrentModePtr->ModeId;
        stdRet = E_OK;
    }
    WdgM_Det_ErrorReport(WDGM_SERVICEID_GETMODE, errorId);
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)ReleaseSpinlock(WDGM_SPIN_LOCK);
#endif /*( WDGM_MULTICORE_SUPPORT == STD_ON )*/
    return stdRet;
}

/*
********************************************************************************
* Function Name: WdgM_CheckpointReached
*
* Explanation: Indicates to the Watchdog Manager that a Checkpoint within a
*              Supervised Entity has been reached.
*
* param: SEID: Identifier of the Supervised Entity that reports a
*              Checkpoint.
*        CheckpointID: Identifier of the Checkpoint within a
*                      Supervised Entity that has been reached.
*
* retval: E_OK: Successfully updated alive counter.
*         E_NOT_OK: Update failed.
********************************************************************************
*/
FUNC(Std_ReturnType, WDGM_CODE) WdgM_CheckpointReached
(
    WdgM_SupervisedEntityIdType SEID,
    WdgM_CheckpointIdType CheckpointID
)
{
    boolean InternalGraphFlag;
    boolean ExternalGraphFlag = FALSE;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    uint8 errorId;
    Std_ReturnType stdRet = E_NOT_OK;
    const WdgM_SEGType* seGPtr;
    const WdgM_ModeStructType* modePtr;
    WdgM_ExLogicalSupervisionType* ExternalLogicalSpvCfg;
    WdgM_CheckpointRefType CheckpointRef = {WDGM_VALUE_ZERO};
    boolean GetSourceCheckPointTickFlag = FALSE;
    modePtr = WdgM_GlobalInfo.CurrentModePtr;
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)GetSpinlock(WDGM_SPIN_LOCK);
#endif
    /* [SWS_WdgM_00279]WDGM_E_UNINIT*/
    if( WDGM_INIT_TRUE != WdgM_GlobalInfo.InitFlag )
    {
        errorId =WDGM_E_UNINIT;
    }
    else
    {
        /* [SWS_WdgM_00278] WDGM_E_PARAM_SEID */
        seGPtr = WdgM_SEID_Chk(SEID);
        if( NULL_PTR != seGPtr )
        {
            /* [SWS_WdgM_00284] WDGM_E_CPID */
            errorId = WdgM_CheckpointID_Chk(seGPtr, CheckpointID);
            if( WDGM_E_NO_ERR == errorId )
            {
                if( WDGM_ALL_SPV_DISABLE == seGPtr->SEVariable->SupervisedEntityEnable )
                {
                    errorId = WDGM_E_SEDEACTIVATED; /* [SWS_WdgM_00319] WDGM_E_SEDEACTIVATED */
                }
                else
                {
                    /* Check if the input check point is belong to alive supervisen. */
                    if( WDGM_VALUE_ZERO
                        != (seGPtr->SEVariable->SupervisedEntityEnable & WDGM_ALIVE_SPV_ENABLE) )
                    {
                        /* [SWS_WdgM_00321] Increment the alive counter. */
                        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_WdgM_UninitializedVariable" */
                        if( CheckpointID == seGPtr->SEVariable->AliveSupervisionCfg->CheckpointIdRef.LogicalCPId )
                        {
                            seGPtr->SEVariable->AliveIndicationCnt++;
                        }
                    }
                    /* Perform the Internal Logical Supervision. */
                    if( WDGM_VALUE_ZERO
                        != (seGPtr->SEVariable->SupervisedEntityEnable & WDGM_LOGICAL_SPV_ENABLE) )
                    {
                        InternalGraphFlag = WdgM_CheckInternalGraphBelongTo(seGPtr, CheckpointID , &GetSourceCheckPointTickFlag);
                        /* [SWS_WdgM_00297]
                         ignore it and not update the result of the Logical Supervision for the Supervised Entity. */
                        if(TRUE == InternalGraphFlag)
                        {
                            seGPtr->SEVariable->PreviousCheckpointId = seGPtr->SEVariable->CurrentCheckpointId;
                            seGPtr->SEVariable->CurrentCheckpointId = CheckpointID;
                            WdgM_Logical_Supervision(seGPtr);   /* Check if internal logical is correct. */
                        }
                    }
                    /* Check if the input checkpoint is belong to deadline supervisen. */
                    if( WDGM_VALUE_ZERO
                        != (seGPtr->SEVariable->SupervisedEntityEnable & WDGM_DEADLINE_SPV_ENABLE) )
                    {
                        /* [SWS_WdgM_00322] Perform the Deadline Supervision. */
                        if( (seGPtr->SEVariable->CurrentCheckpointId != seGPtr->SEVariable->PreviousCheckpointId) || 
                            (TRUE == GetSourceCheckPointTickFlag) )
                        {
                            if( WDGM_VALUE_ZERO != seGPtr->SEVariable->PreviousTick )
                            {
                                errorId = WdgM_GetElapsedValue(seGPtr->OsCounterID,
                                                               (TickRefType)&seGPtr->SEVariable->PreviousTick,
                                                               (TickRefType)&seGPtr->SEVariable->ElapsedTick);
                                if( WDGM_E_NO_ERR == errorId )
                                {
                                    WdgM_DeadLine_Supervision(seGPtr);  /* Check if deadline is correct. */
                                }
                            }
                            else
                            {
                                errorId = WdgM_GetElapsedValue(seGPtr->OsCounterID,
                                                               (TickRefType)&seGPtr->SEVariable->PreviousTick,
                                                               (TickRefType)&seGPtr->SEVariable->ElapsedTick);
                            }
                        }
                    }
                    /* Perform the External Logical Supervision. */
                    if( WDGM_VALUE_ZERO
                        != (seGPtr->SEVariable->SupervisedEntityEnable & WDGM_EXLOGICAL_SPV_ENABLE) )
                    {
                        CheckpointRef.LogicalSEId = SEID;
                        CheckpointRef.LogicalCPId = CheckpointID;
                        ExternalLogicalSpvCfg = WdgM_CheckExternalGraphBelongTo(modePtr,
                                                                                CheckpointRef,
                                                                                &ExternalGraphFlag);
                        /* Check if the external graph is configured. */
                        if( (TRUE == ExternalGraphFlag) && (NULL_PTR != ExternalLogicalSpvCfg) )
                        {
                            /* store the most recently and currently reached Checkpoint. */
                            ExternalLogicalSpvCfg->ExLogicalVariable->ExPreviousCheckpointRef.LogicalSEId
                                = ExternalLogicalSpvCfg->ExLogicalVariable->ExCurrentCheckpointRef.LogicalSEId;

                            ExternalLogicalSpvCfg->ExLogicalVariable->ExPreviousCheckpointRef.LogicalCPId
                                = ExternalLogicalSpvCfg->ExLogicalVariable->ExCurrentCheckpointRef.LogicalCPId;

                            ExternalLogicalSpvCfg->ExLogicalVariable->ExCurrentCheckpointRef.LogicalSEId
                                = SEID;

                            ExternalLogicalSpvCfg->ExLogicalVariable->ExCurrentCheckpointRef.LogicalCPId
                                = CheckpointID;
                            /* Check if external logical is correct. */
                            WdgM_ExLogical_Supervision(seGPtr, ExternalLogicalSpvCfg);
                        }
                    }
                    if( WDGM_VALUE_ZERO == errorId )
                    {
                        stdRet = E_OK;
                    }
                }
            }
            else
            {
                errorId = WDGM_E_CPID;
            }
        }
        else
        {
            errorId = WDGM_E_PARAM_SEID;
        }
    }
    WdgM_Det_ErrorReport(WDGM_SERVICEID_CHECKPOINTREACHED, errorId);
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)ReleaseSpinlock(WDGM_SPIN_LOCK);
#endif/*WDGM_MULTICORE_SUPPORT == STD_ON*/
    return stdRet;
}

/*
********************************************************************************
* Function Name: WdgM_UpdateAliveCounter
*
* Explanation: BEWARE, this API is deprecated. Gives alive indications to
*              the Watchdog Manager.
*
* param: SEID: Identifier of the entity under control of the WdgM whose
*              alive counter shall be updated.
*
* retval: E_OK: Successfully updated alive counter.
*         E_NOT_OK: Update failed.
********************************************************************************
*/
FUNC(Std_ReturnType, WDGM_CODE) WdgM_UpdateAliveCounter
(
    WdgM_SupervisedEntityIdType SEID
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_WdgM_UNMODIFIED_VAR_NOT_CONST" */
    uint8 errorId = WDGM_E_DEPRECATED;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_WdgM_UNMODIFIED_VAR_NOT_CONST" */
    Std_ReturnType stdRet = E_NOT_OK;

    WDGM_DUMMY_STATEMENT(SEID);
    WdgM_Det_ErrorReport(WDGM_SERVICEID_UPDATEALIVECOUNTER, errorId);

    return stdRet;
}

/*
********************************************************************************
* Function Name: WdgM_GetLocalStatus
*
* Explanation: Returns the supervision status of an individual Supervised Entity.
*
* param: SEID: Identifier of the supervised entity whose supervision.
*              status shall be returned.
*        Status: Supervision status of the given supervised entity.
*
* retval: E_OK: Current supervision status successfully returned.
*         E_NOT_OK: Returning current supervision status failed.
********************************************************************************
*/
FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetLocalStatus
(
    WdgM_SupervisedEntityIdType SEID,
    P2VAR(WdgM_LocalStatusType, AUTOMATIC, WDGM_APPL_DATA) Status
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    uint8 errorId = WDGM_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;
    const WdgM_SEGType* seGPtr;
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)GetSpinlock(WDGM_SPIN_LOCK);
#endif
    if( WDGM_INIT_TRUE != WdgM_GlobalInfo.InitFlag )    /* [SWS_WdgM_00173]WDGM_E_UNINIT */
    {
        errorId = WDGM_E_UNINIT;
    }
    else
    {
        if( NULL_PTR != Status )    /* [SWS_WdgM_00257] WDGM_E_PARAM_SEID */
        {
            seGPtr = WdgM_SEID_Chk(SEID);   /* [SWS_WdgM_00172] WDGM_E_PARAM_SEID */
            if( NULL_PTR != seGPtr )
            {
                /* [SWS_WdgM_00171] individual supervision status. */
                /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_WdgM_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.14" */
                *Status = seGPtr->SEVariable->LocalStatus;
                stdRet = E_OK;
            }
            else
            {
                errorId = WDGM_E_PARAM_SEID;
            }
        }
        else
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = WDGM_E_INV_POINTER;
        }
    }
    WdgM_Det_ErrorReport(WDGM_SERVICEID_GETLOCALSTATUS, errorId);
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)ReleaseSpinlock(WDGM_SPIN_LOCK);
#endif/*WDGM_MULTICORE_SUPPORT == STD_ON*/
    return stdRet;
}

/*
********************************************************************************
* Function Name: WdgM_GetGlobalStatus
*
* Explanation: Returns the global supervision status of the Watchdog Manager.
*
* param: Status: Global supervision status of the Watchdog Manager.
*
* retval: E_OK: Current supervision status successfully returned.
*         E_NOT_OK: Returning current supervision status failed.
********************************************************************************
*/
FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetGlobalStatus
(
    P2VAR(WdgM_GlobalStatusType, AUTOMATIC, WDGM_APPL_DATA) Status
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    uint8 errorId = WDGM_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)GetSpinlock(WDGM_SPIN_LOCK);
#endif
    /* [SWS_WdgM_00176]WDGM_E_UNINIT */
    if( WDGM_INIT_TRUE != WdgM_GlobalInfo.InitFlag )
    {
        errorId =WDGM_E_UNINIT;
    }
    else
    {
        /* [SWS_WdgM_00344] [SWS_WdgM_00258] WDGM_E_INV_POINTER */
        if( NULL_PTR != Status )
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_WdgM_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.14" */
            *Status = WdgM_GlobalInfo.GlobalStatus;
            stdRet = E_OK;
        }
        else
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            errorId = WDGM_E_INV_POINTER;
        }
    }
    WdgM_Det_ErrorReport(WDGM_SERVICEID_GETGLOBALSTATUS, errorId);
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)ReleaseSpinlock(WDGM_SPIN_LOCK);
#endif/*( WDGM_MULTICORE_SUPPORT == STD_ON )*/
    return stdRet;
}

/*
********************************************************************************
* Function Name: WdgM_PerformReset
*
* Explanation: Instructs the Watchdog Manager to cause a watchdog reset.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, WDGM_CODE) WdgM_PerformReset(void)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    uint8 errorId= WDGM_E_NO_ERR;
#if ( WDGM_STATECOMBINER_SUPPORT != STD_ON )
    WdgM_TriggerNumType cnt;
#endif  /* WDGM_STATECOMBINER_SUPPORT != STD_ON */
    const WdgM_ModeStructType* modePtr;
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)GetSpinlock(WDGM_SPIN_LOCK);
#endif
    /* [SWS_WdgM_00176]WDGM_E_UNINIT */
    if( WDGM_INIT_TRUE != WdgM_GlobalInfo.InitFlag )
    {
        errorId =WDGM_E_UNINIT;
    }
    else
    {
        modePtr = WdgM_GlobalInfo.CurrentModePtr;
        WdgM_GlobalInfo.PerformResetFlag = TRUE;

#if ( WDGM_STATECOMBINER_SUPPORT == STD_ON )
        /* Call the WdgM SetTriggerCondition function instead of WdgIf. */
        WdgM_StateCombinerSetTriggerCondition(modePtr, WDGM_STATECOMBINER_WDGIFENMODE, WDGM_VALUE_ZERO);
#else
        /* Find all trigger devices in this mode. */
        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
        for( cnt = WDGM_VALUE_ZERO; cnt < modePtr->TriggerNum; cnt++)
        {
            /* Check if trigger is in off mode. */
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( modePtr->Trigger[cnt].WatchdogMode != WDGIF_OFF_MODE )
            {
                /* wait WDG perform reset. */
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
                if( modePtr->Trigger[cnt].TriggerCoreRefID == (WdgM_CoreIdType)GetCoreID() )
#endif
                {
                    WdgIf_SetTriggerCondition(modePtr->Trigger[cnt].DeviceIndex, WDGM_VALUE_ZERO);
                }
            }
        }
#endif  /* WDGM_STATECOMBINER_SUPPORT == STD_ON */
    }
    WdgM_Det_ErrorReport(WDGM_SERVICEID_PERFORMRESET, errorId);
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)ReleaseSpinlock(WDGM_SPIN_LOCK);
#endif/*WDGM_MULTICORE_SUPPORT == STD_ON*/
}

/*
********************************************************************************
* Function Name: WdgM_GetFirstExpiredSEID
*
* Explanation: Returns SEID that first reached the state WDGM_LOCAL_STATUS_EXPIRED.
*
* param: SEID: Identifier of the supervised entity that first reached
*              the state WDGM_LOCAL_STATUS_EXPIRED.
*
* retval: E_OK: SEID successfully returned.
*         E_NOT_OK: Error when returning the SEID.
********************************************************************************
*/
FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetFirstExpiredSEID
(
    P2VAR(WdgM_SupervisedEntityIdType, AUTOMATIC, WDGM_APPL_DATA) SEID
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    uint8 errorId = WDGM_E_NO_ERR;
    Std_ReturnType stdRet = E_NOT_OK;
    WdgM_SupervisedEntityIdType inverse;
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)GetSpinlock(WDGM_SPIN_LOCK);
#endif
    inverse = (~WdgM_GlobalInfo.InverseFirstExpSEId);
    if( NULL_PTR != SEID )  /* [SWS_WdgM_00347] WDGM_E_INV_POINTER  */
    {
         /* [SWS_WdgM_00349] double-inverse */
        if( (TRUE == WdgM_GlobalInfo.FirstExpFlag) && (WdgM_GlobalInfo.FirstExpSEId == inverse) )
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_WdgM_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.14" */
            *SEID = WdgM_GlobalInfo.FirstExpSEId;
            stdRet = E_OK;
        }
        else
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_WdgM_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.14" */
            *SEID = WDGM_VALUE_ZERO;
            stdRet = E_NOT_OK;
        }
    }
    else
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = WDGM_E_INV_POINTER;
    }
    WdgM_Det_ErrorReport(WDGM_SERVICEID_GETFIRSTEXPIREDSEID, errorId);
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)ReleaseSpinlock(WDGM_SPIN_LOCK);
#endif/*WDGM_MULTICORE_SUPPORT == STD_ON*/
    return stdRet;
}

/*
********************************************************************************
* Function Name: WdgM_MainFunction
*
* Explanation: Performs the processing of the cyclic Watchdog Manager jobs.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, WDGM_CODE) WdgM_MainFunction(void)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    uint8 errorId = WDGM_E_NO_ERR;
    WdgM_SENumType seCnt;
    const WdgM_SEGType* seGPtr;
    const WdgM_ModeStructType* modePtr;
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    WdgM_CoreIdType CoreID;
    (void)GetSpinlock(WDGM_SPIN_LOCK);
    CoreID = (WdgM_CoreIdType)GetCoreID();
#else
    WdgM_SENumType seNum = WDGM_SE_ALL_NUM;
#endif/*WDGM_MULTICORE_SUPPORT == STD_ON*/
    modePtr = WdgM_GlobalInfo.CurrentModePtr;
    if( WDGM_INIT_TRUE != WdgM_GlobalInfo.InitFlag )    /* [SWS_WdgM_00039]WDGM_E_UNINIT */
    {
        errorId = WDGM_E_UNINIT;
    }
    else
    {
        /* Check if there a mode switch request. */
        if( TRUE == WdgM_GlobalInfo.setModeFlag )
        {
            WdgM_GlobalInfo.CurrentModePtr = WdgM_GlobalInfo.SetModePtr;  /* WdgM switch mode. */
            modePtr = WdgM_GlobalInfo.CurrentModePtr;
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
            /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_WdgM_OutOfBoundsArrayIndex" polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_WdgM_TAINTED_ARRAY_INDEX" polyspace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_WdgM_TAINTED_LOOP_BOUNDARY" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.14" */
            for( seCnt = WDGM_VALUE_ZERO; seCnt < SENumInCore[CoreID]; seCnt++ )
            {
                /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
                seGPtr = WdgM_SEG_Core_Ptr_Array[CoreID][seCnt];
#else
            for( seCnt = WDGM_VALUE_ZERO; seCnt < seNum; seCnt++ )
            {
                seGPtr = WdgM_SEG_Ptr[seCnt];
#endif/*WDGM_MULTICORE_SUPPORT == STD_ON*/
                WdgM_SESpuvCfgInMode(modePtr, seGPtr);
            }
            /* GLOBAL_STATUS:Expired-->Stopped cycle counter. */
            WdgM_GlobalInfo.ExpiredSupervisionCycCntCfg = modePtr->ExpiredSupervisionCycCnt;
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
            WdgM_CoreSetModeFinishFlag[CoreID] = FALSE;
            for( seCnt = WDGM_VALUE_ZERO; seCnt < WDGM_CORE_NUM; seCnt++ )
            {
                if( TRUE == WdgM_CoreSetModeFinishFlag[seCnt] )
                {
                    break;
                }
            }
            if( seCnt >= WDGM_CORE_NUM )
            {
                WdgM_GlobalInfo.setModeFlag = FALSE;
            }

#else
            WdgM_GlobalInfo.setModeFlag = FALSE;
#endif/*WDGM_MULTICORE_SUPPORT == STD_ON*/

        }
        /* [SWS_WdgM_00063] */
        else if( WDGM_GLOBAL_STATUS_DEACTIVATED != WdgM_GlobalInfo.GlobalStatus )
        {
            if( (WDGM_GLOBAL_STATUS_OK == WdgM_GlobalInfo.GlobalStatus) || (WDGM_GLOBAL_STATUS_FAILED == WdgM_GlobalInfo.GlobalStatus))
            {
                Wdg_30_Sbc_Timer_permissionCounter = 4;
            }
            /* Look for all the SE. */
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
            /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_WdgM_OutOfBoundsArrayIndex" polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_WdgM_TAINTED_ARRAY_INDEX" polyspace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_WdgM_TAINTED_LOOP_BOUNDARY" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.14" */
            for( seCnt = WDGM_VALUE_ZERO; seCnt < SENumInCore[CoreID]; seCnt++ )
            {
                /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
                seGPtr = WdgM_SEG_Core_Ptr_Array[CoreID][seCnt];
#else
            for( seCnt = WDGM_VALUE_ZERO; seCnt < seNum; seCnt++ )
            {
                seGPtr = WdgM_SEG_Ptr[seCnt];
#endif/*WDGM_MULTICORE_SUPPORT == STD_ON*/
                /* Check if the SE is enable. */
                if( WDGM_VALUE_ZERO
                    /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
                    != (seGPtr->SEVariable->SupervisedEntityEnable & WDGM_ALIVE_SPV_ENABLE) )
                {
                    WdgM_Alive_Supervision(seGPtr);    /* [SWS_WdgM_00324] Alive Supervision. */
                }
                /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" */
                /* [SWS_WdgM_00325] Local Supervision Status. */
                WdgM_LocalStatusMachine(seGPtr);
                /* [SWS_WdgM_00351] store the first EXPIRED SEID as a double-inverted value. */
                WdgM_FisrtExpiredSEID_Record(seGPtr);
            }
            /* [SWS_WdgM_00326] Global Supervision status. */
            /* [SWS_WdgM_00214] Wdgm_MainFunction shall calculate the Global Supervision Status in every Supervision cycle. */
            WdgM_GlobalStatusMachine(modePtr);
            /* [SWS_WdgM_00327] error handling. */    /* [SWS_WdgM_00328] */
            if( FALSE == WdgM_GlobalInfo.PerformResetFlag )
            {
                WdgM_ErrorHandling(modePtr);
            }
        }
        else
        {
            /* Do nothing. */
        }
    }
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    (void)ReleaseSpinlock(WDGM_SPIN_LOCK);
#endif/*WDGM_MULTICORE_SUPPORT == STD_ON*/
    WdgM_Det_ErrorReport(WDGM_SERVICEID_MAINFUNCTION, errorId);
}

/*
********************************************************************************
* Function Name: WdgM_Alive_Supervision
*
* Explanation: Alive Supervision.
*
* param: SEGPtr: SE Structure pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, WDGM_CODE) WdgM_Alive_Supervision
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
)
{
    WdgM_SupervisedCycCntType max;
    WdgM_SupervisedCycCntType min;

    SEGPtr->SEVariable->AliveSupervisionCycCnt++;
    /* Detect the Supervision Reference Cycle reached or not. */
    /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_WdgM_Non-initializedVariable" */
    if( SEGPtr->SEVariable->AliveSupervisionCfg->SupervisionRefCyc
        <= SEGPtr->SEVariable->AliveSupervisionCycCnt )
    {
        /* calculate the MAX (Expected -Min Margin;Expected + Max Margin). */
        /* polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_WdgM_Non-initializedVariable" */
        max = SEGPtr->SEVariable->AliveSupervisionCfg->ExpectedAliveIndications
              /* polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_WdgM_Non-initializedVariable" */
              + SEGPtr->SEVariable->AliveSupervisionCfg->MaxMargin;
        /* Check if expect value is large than minmargin. */
        if( SEGPtr->SEVariable->AliveSupervisionCfg->ExpectedAliveIndications
            /* polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_WdgM_Non-initializedVariable" */
            > SEGPtr->SEVariable->AliveSupervisionCfg->MinMargin )
        {
            /* calculate the MIN (Expected - Min Margin;Expected + Max Margin). */
            min = SEGPtr->SEVariable->AliveSupervisionCfg->ExpectedAliveIndications
                  - SEGPtr->SEVariable->AliveSupervisionCfg->MinMargin;
        }
        else
        {
            min = WDGM_VALUE_ZERO;
        }

        if( (min <= SEGPtr->SEVariable->AliveIndicationCnt)
             && (max >= SEGPtr->SEVariable->AliveIndicationCnt) )
        {
            if( WDGM_VALUE_ONE < SEGPtr->SEVariable->AliveFailedCnt )
            {
                /*[SWS_WdgM_00300] decrement the counter for failed supervision reference cycles. */
                SEGPtr->SEVariable->AliveFailedCnt--;
            }
            else if( WDGM_VALUE_ONE == SEGPtr->SEVariable->AliveFailedCnt )
            {
                SEGPtr->SEVariable->AliveFailedCnt--;
                if( WDGM_AlLIVE_INCORRECT_EX != SEGPtr->SEVariable->AliveSpvStatus )
                {
                    SEGPtr->SEVariable->AliveSpvStatus = WDGM_AlLIVE_CORRECT;   /*[SWS_WdgM_00205]*/
                }
            }
            else
            {
                /* Do nothing. */
            }
        }
        else
        {
            /*[SWS_WdgM_00204] increment the counter for failed supervision reference cycles. */
            SEGPtr->SEVariable->AliveFailedCnt++;
            /* polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_WdgM_Non-initializedVariable" */
            if( SEGPtr->SEVariable->AliveSupervisionCfg->FailedAliveSupvRefCycTol
                < SEGPtr->SEVariable->AliveFailedCnt )
            {
                SEGPtr->SEVariable->AliveSpvStatus = WDGM_AlLIVE_INCORRECT_EX;
            }
            else
            {
                SEGPtr->SEVariable->AliveSpvStatus = WDGM_AlLIVE_INCORRECT_NOEX;
            }
        }
        SEGPtr->SEVariable->AliveSupervisionCycCnt = WDGM_VALUE_ZERO;
        SEGPtr->SEVariable->AliveIndicationCnt = WDGM_VALUE_ZERO;
    }
}

/*
********************************************************************************
* Function Name: WdgM_DeadLine_Supervision
*
* Explanation: DeadLine Supervision.
*
* param: SEGPtr: SE Structure pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, WDGM_CODE) WdgM_DeadLine_Supervision
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
)
{
    WdgM_DeadLineSupervisionNumType ddlSpvNum;

    /* Check if input pointer is NULL. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( NULL_PTR != SEGPtr )
    {
        /* check  DeadLine supervision correctness with Cfg. */
        for( ddlSpvNum = WDGM_VALUE_ZERO;
             ddlSpvNum < SEGPtr->SEVariable->DeadLineSupervisionNum; ddlSpvNum++ )
        {
            /* Check if current checkpoint is stop checkpoint and previous checkpoint is start checkpoint. */
            /* polyspace +10 RTE:NIV [Justified:Unset] "NSCA_Polyspace_WdgM_Non-initializedVariable" */
            /* polyspace +9 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" */
            /* polyspace +8 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" */
            /* polyspace +7 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
            /* polyspace +4 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" */
            /* polyspace +3 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" */
            /* polyspace +2 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
            /* polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_WdgM_Non-initializedVariable" */
            if( (SEGPtr->SEVariable->DeadLineSupervisionCfg[ddlSpvNum].DeadlineStartRef.LogicalCPId
                 == SEGPtr->SEVariable->PreviousCheckpointId)
                && (SEGPtr->SEVariable->DeadLineSupervisionCfg[ddlSpvNum].DeadlineStopRef.LogicalCPId
                    == SEGPtr->SEVariable->CurrentCheckpointId) )
            {
                /* Check if the elapsed value is in the range. */
                /* polyspace +10 RTE:NIV [Justified:Unset] "NSCA_Polyspace_WdgM_Non-initializedVariable" */
                /* polyspace +9 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" */
                /* polyspace +8 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" */
                /* polyspace +7 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
                /* polyspace +4 RTE:NIV [Justified:Unset] "NSCA_Polyspace_WdgM_Non-initializedVariable" */
                /* polyspace +3 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" */
                /* polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" */
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
                if( (SEGPtr->SEVariable->DeadLineSupervisionCfg[ddlSpvNum].DeadlineMax
                     >= SEGPtr->SEVariable->ElapsedTick)
                    && (SEGPtr->SEVariable->DeadLineSupervisionCfg[ddlSpvNum].DeadlineMin
                        <= SEGPtr->SEVariable->ElapsedTick) )
                {
                    /* Do nothing. */
                }
                else
                {
                    SEGPtr->SEVariable->DeadLineSpvStatus = WDGM_DEADLINE_INCORRECT;
                }
                break;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: WdgM_Logical_Supervision
*
* Explanation: Logical Supervision of Internal Transition.
*
* param: SEGPtr: SE Structure pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, WDGM_CODE) WdgM_Logical_Supervision
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
)
{
    WdgM_LogicalSupervisionNumType lgcSpvNum;
    WdgM_CheckpointNumType loopFinalCheckPonitNum;

    /* Check if input pointer is NULL. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( NULL_PTR != SEGPtr )
    {
        /* Logical supervision is not activated. */
        if( FALSE == SEGPtr->SEVariable->LogicalActiveFlag )
        {
             /* [SWS_WdgM_00332] */  /* [SWS_WdgM_00273] */
            if( SEGPtr->InternalCheckpointInitial == SEGPtr->SEVariable->CurrentCheckpointId )
            {
                SEGPtr->SEVariable->LogicalActiveFlag = TRUE;
            }
            else    /* [SWS_WdgM_00331] */
            {
                SEGPtr->SEVariable->LogicalSpvStatus = WDGM_LOGICAL_INCORRECT;
            }
        }
        /* Logical supervision is activated. */
        else if( TRUE == SEGPtr->SEVariable->LogicalActiveFlag )
        {
            for( lgcSpvNum = WDGM_VALUE_ZERO;
                  lgcSpvNum < SEGPtr->LogicalSupervisionNum; lgcSpvNum++ )
            {
                /* check  logical supervision correctness with Cfg. */
                /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
                if( (SEGPtr->LogicalSupervisionCfg[lgcSpvNum].transitionSource
                     == SEGPtr->SEVariable->PreviousCheckpointId)
                    && (SEGPtr->LogicalSupervisionCfg[lgcSpvNum].transitionIdDest
                        == SEGPtr->SEVariable->CurrentCheckpointId) )
                {
                    break;
                }
            }
            /* No transtion relationship found. */
            if( lgcSpvNum >= SEGPtr->LogicalSupervisionNum )
            {
                SEGPtr->SEVariable->LogicalSpvStatus = WDGM_LOGICAL_INCORRECT;
            }
            /* [SWS_WdgM_00329] */
            else if( WDGM_VALUE_ONE == SEGPtr->InternalCheckpointFinalNum )
            {
                if( NULL_PTR != &(SEGPtr->InternalCheckpointFinalArray[WDGM_VALUE_ZERO]) )
                {
                    if( (SEGPtr->InternalCheckpointFinalArray[WDGM_VALUE_ZERO]
                    == SEGPtr->SEVariable->CurrentCheckpointId)
                    && (SEGPtr->InternalCheckpointFinalArray[WDGM_VALUE_ZERO]
                    != SEGPtr->InternalCheckpointInitial) )
                    {
                        SEGPtr->SEVariable->LogicalActiveFlag = FALSE;
                    }
                }
            }
            else if( WDGM_VALUE_ONE < SEGPtr->InternalCheckpointFinalNum )
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
                for( loopFinalCheckPonitNum = WDGM_VALUE_ZERO;
                     loopFinalCheckPonitNum < SEGPtr->InternalCheckpointFinalNum;
                     loopFinalCheckPonitNum++ )
                {
                    if( NULL_PTR != &(SEGPtr->InternalCheckpointFinalArray[WDGM_VALUE_ZERO]) )
                    {
                        if( (SEGPtr->InternalCheckpointFinalArray[loopFinalCheckPonitNum]
                        == SEGPtr->SEVariable->CurrentCheckpointId)
                        && (SEGPtr->InternalCheckpointFinalArray[loopFinalCheckPonitNum]
                        != SEGPtr->InternalCheckpointInitial) )
                        {
                            SEGPtr->SEVariable->LogicalActiveFlag = FALSE;
                            break;
                        }
                    }
                }
            }
            else
            {
                /* Do nothing. */
            }
        }
        else
        {
            /* Do nothing. */
        }
    }
}

/*
********************************************************************************
* Function Name: WdgM_ExLogical_Supervision
*
* Explanation: ExLogical Supervision of External Transition.
*
* param: SEGPtr: SE Structure pointer.
*        ExternalLogicalSpvCfg: External Logical Supervision Structure pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, WDGM_CODE) WdgM_ExLogical_Supervision
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr,
    P2VAR(WdgM_ExLogicalSupervisionType, AUTOMATIC, WDGM_APPL_DATA) ExternalLogicalSpvCfg
)
{
    boolean searchFlag = FALSE;
    WdgM_ExternalCPInitialNumType cpInitialCnt;
    WdgM_ExternalCPFinalNumType cpFinalCnt;
    WdgM_ExternalTransitionNumType exTranCnt;

    /* Check if input pointer is NULL. */
    if( (NULL_PTR == SEGPtr) || (NULL_PTR == ExternalLogicalSpvCfg) )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Based on QAC result,delete this code. */
    }
    else
    {
        /* [SWS_WdgM_00332] */  /* [SWS_WdgM_00273] */
        if( FALSE == (ExternalLogicalSpvCfg->ExLogicalVariable->ExLogicalActiveFlag) )
        {
            /* Look for all the initial checkpoint. */
            for( cpInitialCnt = WDGM_VALUE_ZERO;
                 cpInitialCnt < ExternalLogicalSpvCfg->ExternalCPInitialNum;
                 cpInitialCnt++ )
            {
                if( (ExternalLogicalSpvCfg->ExLogicalVariable->ExCurrentCheckpointRef.LogicalSEId
                     == ExternalLogicalSpvCfg->ExternalCheckpointInitialRef[cpInitialCnt].LogicalSEId)
                    && (ExternalLogicalSpvCfg->ExLogicalVariable->ExCurrentCheckpointRef.LogicalCPId
                        == ExternalLogicalSpvCfg->ExternalCheckpointInitialRef[cpInitialCnt].LogicalCPId) )
                {
                    searchFlag = TRUE;
                    break;
                }
            }
            if( TRUE == searchFlag )
            {
                ExternalLogicalSpvCfg->ExLogicalVariable->ExLogicalActiveFlag = TRUE;
            }
            else
            {
                /* [SWS_WdgM_00331] */
                SEGPtr->SEVariable->LogicalSpvStatus = WDGM_LOGICAL_INCORRECT;
            }
        }
        else
        {
            /* Look for all the external transition checkpoint. */
            for( exTranCnt = WDGM_VALUE_ZERO;
                 exTranCnt < ExternalLogicalSpvCfg->ExternalTransitionNum;
                 exTranCnt++ )
            {
                if( (ExternalLogicalSpvCfg->ExLogicalVariable->ExCurrentCheckpointRef.LogicalSEId
                     == ExternalLogicalSpvCfg->ExternalTransitionCfg[exTranCnt].ExternalTransitionDestRef.LogicalSEId)
                    && (ExternalLogicalSpvCfg->ExLogicalVariable->ExCurrentCheckpointRef.LogicalCPId
                        == ExternalLogicalSpvCfg->ExternalTransitionCfg[exTranCnt].ExternalTransitionDestRef.LogicalCPId)
                    && (ExternalLogicalSpvCfg->ExLogicalVariable->ExPreviousCheckpointRef.LogicalSEId
                        == ExternalLogicalSpvCfg->ExternalTransitionCfg[exTranCnt].ExternalTransitionSourceRef.LogicalSEId)
                    && (ExternalLogicalSpvCfg->ExLogicalVariable->ExPreviousCheckpointRef.LogicalCPId
                        == ExternalLogicalSpvCfg->ExternalTransitionCfg[exTranCnt].ExternalTransitionSourceRef.LogicalCPId) )
                {
                    searchFlag = TRUE;
                    break;
                }
            }
            if( FALSE == searchFlag )
            {
                /* [SWS_WdgM_00331] */
                SEGPtr->SEVariable->LogicalSpvStatus = WDGM_LOGICAL_INCORRECT;
            }
            else
            {
                /* Look for all the final checkpoint. */
                for( cpFinalCnt = WDGM_VALUE_ZERO;
                     cpFinalCnt <ExternalLogicalSpvCfg->ExternalCPFinalNum;
                     cpFinalCnt++ )
                {
                    if( (ExternalLogicalSpvCfg->ExLogicalVariable->ExCurrentCheckpointRef.LogicalSEId
                         == ExternalLogicalSpvCfg->ExternalCheckpointFinalRef[cpFinalCnt].LogicalSEId)
                        && (ExternalLogicalSpvCfg->ExLogicalVariable->ExCurrentCheckpointRef.LogicalCPId
                            == ExternalLogicalSpvCfg->ExternalCheckpointFinalRef[cpFinalCnt].LogicalCPId) )
                    {
                        /* [SWS_WdgM_00331] */
                        ExternalLogicalSpvCfg->ExLogicalVariable->ExLogicalActiveFlag = FALSE;
                        break;
                    }
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: WdgM_LocalStatusMachine
*
* Explanation: Determine the Local Supervision Status.
*
* param: SEGPtr: SE Structure pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, WDGM_CODE) WdgM_LocalStatusMachine
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
)
{
#if( STD_ON == WDGM_STATUSCHANGENOTIFICATION_SUPPORT )
    WdgM_LocalStatusType localStatusOrigin;

    localStatusOrigin = SEGPtr->SEVariable->LocalStatus;
#endif  /* STD_ON == WDGM_STATUSCHANGENOTIFICATION_SUPPORT */
    if( WDGM_LOCAL_STATUS_OK == SEGPtr->SEVariable->LocalStatus )
    {
        /* [SWS_WdgM_00202] */
        if( (WDGM_DEADLINE_INCORRECT == SEGPtr->SEVariable->DeadLineSpvStatus)
            || (WDGM_LOGICAL_INCORRECT == SEGPtr->SEVariable->LogicalSpvStatus)
            || (WDGM_AlLIVE_INCORRECT_EX == SEGPtr->SEVariable->AliveSpvStatus) )
        {
            SEGPtr->SEVariable->LocalStatus = WDGM_LOCAL_STATUS_EXPIRED;
        }
        /* [SWS_WdgM_00203] [SWS_WdgM_00204] */
        else if( (WDGM_DEADLINE_CORRECT == SEGPtr->SEVariable->DeadLineSpvStatus)
            && (WDGM_LOGICAL_CORRECT == SEGPtr->SEVariable->LogicalSpvStatus)
            && (WDGM_AlLIVE_INCORRECT_NOEX == SEGPtr->SEVariable->AliveSpvStatus) )
        {
            SEGPtr->SEVariable->LocalStatus = WDGM_LOCAL_STATUS_FAILED;
            if( TRUE == SEGPtr->OsApplicationRestartEnable )
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            {
#ifdef WDGM_E_ECUCPARTITION
                BswM_WdgM_RequestPartitionReset(SEGPtr->EcucPartitionRef);
#endif /* WDGM_E_ECUCPARTITION */
            }
        }
        else
        {
            /* [SWS_WdgM_00201] */
        }
    }
    else if( WDGM_LOCAL_STATUS_FAILED == SEGPtr->SEVariable->LocalStatus )
    {
        /* [SWS_WdgM_00205] */
        if( (WDGM_DEADLINE_CORRECT == SEGPtr->SEVariable->DeadLineSpvStatus)
            && (WDGM_LOGICAL_CORRECT == SEGPtr->SEVariable->LogicalSpvStatus)
            && (WDGM_AlLIVE_CORRECT == SEGPtr->SEVariable->AliveSpvStatus) )
        {
            SEGPtr->SEVariable->LocalStatus = WDGM_LOCAL_STATUS_OK;
        }
        /* [SWS_WdgM_00206] */
        else if( (WDGM_DEADLINE_INCORRECT == SEGPtr->SEVariable->DeadLineSpvStatus)
            || (WDGM_LOGICAL_INCORRECT == SEGPtr->SEVariable->LogicalSpvStatus)
            || (WDGM_AlLIVE_INCORRECT_EX == SEGPtr->SEVariable->AliveSpvStatus) )
        {
            SEGPtr->SEVariable->LocalStatus = WDGM_LOCAL_STATUS_EXPIRED;
        }
        else
        {
            /* [SWS_WdgM_00300] */
        }
    }
    else if( WDGM_LOCAL_STATUS_DEACTIVATED == SEGPtr->SEVariable->LocalStatus )
    {
        /* [SWS_WdgM_00209] */
        if( WDGM_ALL_SPV_DISABLE != SEGPtr->SEVariable->SupervisedEntityEnable )
        {
            SEGPtr->SEVariable->LocalStatus = WDGM_LOCAL_STATUS_OK;
        }
        else
        {
            /*[SWS_WdgM_00208]*/
        }
    }
    else if( WDGM_LOCAL_STATUS_EXPIRED == SEGPtr->SEVariable->LocalStatus )
    {
        /* Do nothing. */
    }
    else
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Do nothing. */
    }

    /* [SWS_WdgM_00207] [SWS_WdgM_00291] */
    if( (WDGM_LOCAL_STATUS_OK == SEGPtr->SEVariable->LocalStatus)
        || (WDGM_LOCAL_STATUS_FAILED == SEGPtr->SEVariable->LocalStatus) )
    {
        if( WDGM_ALL_SPV_DISABLE == SEGPtr->SEVariable->SupervisedEntityEnable )
        {
            SEGPtr->SEVariable->LocalStatus = WDGM_LOCAL_STATUS_DEACTIVATED;
        }
    }

#if( STD_ON == WDGM_STATUSCHANGENOTIFICATION_SUPPORT )
    /* When the Local Supervision Status of a single Supervised Entity changes, report that change via the
       mode port for that Supervised Entity. */
    if( (localStatusOrigin != SEGPtr->SEVariable->LocalStatus) && (NULL_PTR != SEGPtr->WdgM_LocalStatusChangeNotification) )
    {
        SEGPtr->WdgM_LocalStatusChangeNotification(SEGPtr->SEVariable->LocalStatus);
    }
    localStatusOrigin = SEGPtr->SEVariable->LocalStatus;
#endif  /* STD_ON == WDGM_STATUSCHANGENOTIFICATION_SUPPORT */
}

/*
********************************************************************************
* Function Name: WdgM_FisrtExpiredSEID_Record
*
* Explanation: Record the SEID that first reached the state WDGM_LOCAL_STATUS_EXPIRED.
*
* param: SEGPtr: SE Structure pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, WDGM_CODE) WdgM_FisrtExpiredSEID_Record
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
)
{
    /* Check if SE local status and global status expire. */
    if( (WDGM_LOCAL_STATUS_EXPIRED == SEGPtr->SEVariable->LocalStatus)
        && (FALSE == WdgM_GlobalInfo.FirstExpFlag) )
    {
        WdgM_GlobalInfo.FirstExpSEId = SEGPtr->SupervisedEntityId;
        WdgM_GlobalInfo.InverseFirstExpSEId = (~(SEGPtr->SupervisedEntityId));
        WdgM_GlobalInfo.FirstExpFlag = TRUE;
    }
}

/*
********************************************************************************
* Function Name: WdgM_GlobalStatusMachine
*
* Explanation: Determine the Global Supervision status.
*
* param: Mode Structure pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, WDGM_CODE) WdgM_GlobalStatusMachine(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr
)
{
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    WdgM_LocalStatusType  AllLocalStatus = WDGM_LOCAL_STATUS_OK;
    WdgM_CountType AllCoreLocalStatusFailedCnt = WDGM_VALUE_ZERO;
    WdgM_CountType AllCoreLocalStatusExpiredCnt = WDGM_VALUE_ZERO;
    WdgM_CoreNumType CoreNumCnt;
#else
    WdgM_LocalStatusType  AllLocalStatus = WDGM_LOCAL_STATUS_OK;
    WdgM_SENumType seNum = WDGM_SE_ALL_NUM;
#endif
    WdgM_SENumType seCnt;
    const WdgM_SEGType* seGPtr;
#if( STD_ON == WDGM_STATUSCHANGENOTIFICATION_SUPPORT )
    WdgM_LocalStatusType globalStatusOrigin;

    globalStatusOrigin = WdgM_GlobalInfo.GlobalStatus;
#endif  /* STD_ON == WDGM_STATUSCHANGENOTIFICATION_SUPPORT */
    /* Calc the AllLocalStatus. */
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    WdgM_CoreIdType CoreID;
    CoreID = (WdgM_CoreIdType)GetCoreID();
    /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_WdgM_OutOfBoundsArrayIndex" polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_WdgM_TAINTED_ARRAY_INDEX" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.14" */
    WdgM_LocalStatusCnt_Array[CoreID]->WdgM_localStatusFailedCnt = WDGM_VALUE_ZERO;
    WdgM_LocalStatusCnt_Array[CoreID]->WdgM_LocalStatusExpiredCnt = WDGM_VALUE_ZERO;
    WdgM_LocalStatusCnt_Array[CoreID]->WdgM_LocalStatusOKCnt = WDGM_VALUE_ZERO;
    WdgM_LocalStatusCnt_Array[CoreID]->WdgM_LocalStatusDeactivatedCnt = WDGM_VALUE_ZERO;
    /* polyspace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_WdgM_TAINTED_LOOP_BOUNDARY" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.14" */
    for( seCnt = WDGM_VALUE_ZERO; seCnt < SENumInCore[CoreID]; seCnt++ )
    {
        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
        seGPtr = WdgM_SEG_Core_Ptr_Array[CoreID][seCnt];
#else
    for( seCnt = WDGM_VALUE_ZERO; seCnt < seNum; seCnt++ )
    {
        seGPtr = WdgM_SEG_Ptr[seCnt];
#endif
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
        /* polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_WdgM_Rule16.1" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
        switch(seGPtr->SEVariable->LocalStatus)
        {
            case WDGM_LOCAL_STATUS_FAILED:
                WdgM_LocalStatusCnt_Array[CoreID]->WdgM_localStatusFailedCnt++;
                break;
            case WDGM_LOCAL_STATUS_EXPIRED:
                WdgM_LocalStatusCnt_Array[CoreID]->WdgM_LocalStatusExpiredCnt++;
                break;
            case WDGM_LOCAL_STATUS_OK:
                WdgM_LocalStatusCnt_Array[CoreID]->WdgM_LocalStatusOKCnt++;
                break;
            case WDGM_LOCAL_STATUS_DEACTIVATED:
                WdgM_LocalStatusCnt_Array[CoreID]->WdgM_LocalStatusDeactivatedCnt++;
                break;
            /* polyspace +1 MISRA-C3:16.4 [Justified:Unset] "NSCA_Polyspace_WdgM_Rule16.4" polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            default:
                break;
        }
        if( MASTER_CORE_ID == (WdgM_CoreIdType)GetCoreID() )
        {
            for(CoreNumCnt = 0U; CoreNumCnt < WDGM_CORE_NUM; CoreNumCnt++)
            {
                AllCoreLocalStatusFailedCnt += WdgM_LocalStatusCnt_Array[CoreNumCnt]->WdgM_localStatusFailedCnt;
                AllCoreLocalStatusExpiredCnt += WdgM_LocalStatusCnt_Array[CoreNumCnt]->WdgM_LocalStatusExpiredCnt;
            }
            if( AllCoreLocalStatusExpiredCnt > WDGM_VALUE_ZERO )
            {
                AllLocalStatus = WDGM_LOCAL_STATUS_EXPIRED;
            }
            else if( AllCoreLocalStatusFailedCnt > WDGM_VALUE_ZERO )
            {
                AllLocalStatus = WDGM_LOCAL_STATUS_FAILED;
            }
            else
            {
                /* Do nothing. */
            }
        }
#else
        if( WDGM_LOCAL_STATUS_OK == AllLocalStatus )
        {
            if( WDGM_LOCAL_STATUS_FAILED == seGPtr->SEVariable->LocalStatus )
            {
                AllLocalStatus = WDGM_LOCAL_STATUS_FAILED;
            }
            else if( WDGM_LOCAL_STATUS_EXPIRED == seGPtr->SEVariable->LocalStatus )
            {
                AllLocalStatus = WDGM_LOCAL_STATUS_EXPIRED;
            }
            else
            {
                /* Do nothing. */
            }
        }
        else if( WDGM_LOCAL_STATUS_FAILED == AllLocalStatus )
        {
            if( WDGM_LOCAL_STATUS_EXPIRED == seGPtr->SEVariable->LocalStatus )
            {
                AllLocalStatus = WDGM_LOCAL_STATUS_EXPIRED;
            }
            else
            {
                /* Do nothing. */
            }
        }
        else
        {
            break;
        }
#endif
    }


#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    if( MASTER_CORE_ID == (WdgM_CoreIdType)GetCoreID() )
    {
#endif
    if( WDGM_GLOBAL_STATUS_OK == WdgM_GlobalInfo.GlobalStatus )
    {
        if( WDGM_LOCAL_STATUS_OK == AllLocalStatus )
        {
            /* [SWS_WdgM_00078] */
        }
        else if( WDGM_LOCAL_STATUS_FAILED == AllLocalStatus )
        {
            /* [SWS_WdgM_00076] */
            WdgM_GlobalInfo.GlobalStatus = WDGM_GLOBAL_STATUS_FAILED;
        }
        else
        {
            if( WdgM_GlobalInfo.ExpiredSupervisionCycCntCfg
                <= WdgM_GlobalInfo.ExpiredSupervisionCycCnt )
            {
                /* [SWS_WdgM_00216] */
                WdgM_GlobalInfo.GlobalStatus = WDGM_GLOBAL_STATUS_STOPPED;

#ifdef WDGM_E_SUPERVISION_EVENTID
                Dem_ReportErrorStatus(WDGM_E_SUPERVISION_EVENTID, DEM_EVENT_STATUS_FAILED);
#endif  /* WDGM_E_SUPERVISION_EVENTID */

            }
            else
            {
                /* [SWS_WdgM_00215] */
                WdgM_GlobalInfo.GlobalStatus = WDGM_GLOBAL_STATUS_EXPIRED;
                WdgM_GlobalInfo.ExpiredSupervisionCycCnt++;
            }
        }
    }
    else if( WDGM_GLOBAL_STATUS_FAILED == WdgM_GlobalInfo.GlobalStatus )
    {
        /* [SWS_WdgM_00218] */
        if(WDGM_LOCAL_STATUS_OK == AllLocalStatus)
        {
            WdgM_GlobalInfo.GlobalStatus = WDGM_GLOBAL_STATUS_OK;
        }
        else if(WDGM_LOCAL_STATUS_FAILED == AllLocalStatus)
        {
            /* [SWS_WdgM_00217] */
        }
        else
        {
            /* [SWS_WdgM_00117] */
            if( WdgM_GlobalInfo.ExpiredSupervisionCycCntCfg
                <= WdgM_GlobalInfo.ExpiredSupervisionCycCnt )
            {
                WdgM_GlobalInfo.GlobalStatus = WDGM_GLOBAL_STATUS_STOPPED;

#ifdef WDGM_E_SUPERVISION_EVENTID 
                Dem_ReportErrorStatus(WDGM_E_SUPERVISION_EVENTID, DEM_EVENT_STATUS_FAILED);
#endif /* WDGM_E_SUPERVISION_EVENTID */

            }
            else    /* [SWS_WdgM_00077] */
            {
                WdgM_GlobalInfo.GlobalStatus = WDGM_GLOBAL_STATUS_EXPIRED;
                WdgM_GlobalInfo.ExpiredSupervisionCycCnt++;
            }
        }
    }
    else if( WDGM_GLOBAL_STATUS_EXPIRED == WdgM_GlobalInfo.GlobalStatus )
    {
        /* [SWS_WdgM_00220] */
        if( WdgM_GlobalInfo.ExpiredSupervisionCycCntCfg
            <= WdgM_GlobalInfo.ExpiredSupervisionCycCnt )
        {
            WdgM_GlobalInfo.GlobalStatus = WDGM_GLOBAL_STATUS_STOPPED;

#ifdef WDGM_E_SUPERVISION_EVENTID 
            Dem_ReportErrorStatus(WDGM_E_SUPERVISION_EVENTID, DEM_EVENT_STATUS_FAILED);
#endif /* WDGM_E_SUPERVISION_EVENTID */

        }
        else    /* [SWS_WdgM_00219] */
        {
            WdgM_GlobalInfo.GlobalStatus = WDGM_GLOBAL_STATUS_EXPIRED;
            WdgM_GlobalInfo.ExpiredSupervisionCycCnt++;
        }
    }
    /* [SWS_WdgM_00221] */
    else if( WDGM_GLOBAL_STATUS_STOPPED == WdgM_GlobalInfo.GlobalStatus )
    {

#ifdef WDGM_E_SUPERVISION_EVENTID 
        Dem_ReportErrorStatus(WDGM_E_SUPERVISION_EVENTID, DEM_EVENT_STATUS_FAILED);
#endif /* WDGM_E_SUPERVISION_EVENTID */

    }
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    else if( WDGM_GLOBAL_STATUS_DEACTIVATED == WdgM_GlobalInfo.GlobalStatus )
    {
        /* Do nothing. */
    }
    else
    {
        /* Do nothing. */
    }
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    }/*if( MASTER_CORE_ID == GetCoreID() )*/
#endif/*WDGM_MULTICORE_SUPPORT == STD_ON*/

#if( STD_ON == WDGM_STATUSCHANGENOTIFICATION_SUPPORT )
    /* When the Global Supervision Status changes, report that change via the global mode port.*/
    if( (globalStatusOrigin != WdgM_GlobalInfo.GlobalStatus) && (NULL_PTR != modePtr->WdgM_GlobalStatusChangeNotification) )
    {
        modePtr->WdgM_GlobalStatusChangeNotification(WdgM_GlobalInfo.GlobalStatus);
    }
    globalStatusOrigin = WdgM_GlobalInfo.GlobalStatus;
#else
    WDGM_DUMMY_STATEMENT(modePtr);
#endif  /* STD_ON == WDGM_STATUSCHANGENOTIFICATION_SUPPORT */
}

/*
********************************************************************************
* Function Name: WdgM_Det_ErrorReport
*
* Explanation: Report error to Det Module.
*
* param: ApiId: the Api Service Id of WdgM.
*        errorId: Error Id defined in WdgM_Types.h.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
static FUNC(void, WDGM_CODE) WdgM_Det_ErrorReport(uint8 ApiId, uint8 errorId)
{
#if( WDGM_DEV_ERROR_DETECT == STD_ON )

    if( errorId != WDGM_E_NO_ERR )      /* Error detected. */
    {
        (void)Det_ReportError(WDGM_MODULE_ID, WDGM_INSTANCE_ID_DET, ApiId, errorId);    /* Report Error to Det. */
    }
#else
    {
        WDGM_DUMMY_STATEMENT(ApiId);
        WDGM_DUMMY_STATEMENT(errorId);
    }
#endif /* WDG_DEV_ERROR_DETECT == STD_ON */
}

/*
********************************************************************************
* Function Name: WdgM_SEID_Chk
*
* Explanation: Based on SEID find the SE structure pointer.
*
* param: SEID:Identifier of the supervised entity.
*
* retval: SE Structure pointer.
********************************************************************************
*/
static FUNC_P2CONST(WdgM_SEGType, WDGM_APPL_CONST, WDGM_CODE) WdgM_SEID_Chk
(
    WdgM_SupervisedEntityIdType SEID
)
{
    WdgM_SENumType seCnt;
    const WdgM_SEGType* seGPtr;
    const WdgM_SEGType* seGPtrRet = NULL_PTR;

    /* Find the corresponding SE structure according to the incoming SEID parameter. */
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    WdgM_CoreIdType CoreID;
    CoreID = (WdgM_CoreIdType)GetCoreID();
    /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_WdgM_OutOfBoundsArrayIndex" polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_WdgM_TAINTED_ARRAY_INDEX" polyspace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_WdgM_TAINTED_LOOP_BOUNDARY" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.14" */
    for( seCnt = WDGM_VALUE_ZERO; seCnt < SENumInCore[CoreID]; seCnt++ )
    {
        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
        seGPtr = WdgM_SEG_Core_Ptr_Array[CoreID][seCnt];
#else
    WdgM_SENumType SENum = WDGM_SE_ALL_NUM;
    for( seCnt = WDGM_VALUE_ZERO; seCnt < SENum; seCnt++ )
    {
        seGPtr = WdgM_SEG_Ptr[seCnt];
#endif/*WDGM_MULTICORE_SUPPORT == STD_ON*/
        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
        if( seGPtr->SupervisedEntityId == SEID )
        {
            seGPtrRet = seGPtr;
            break;
        }
    }

    return seGPtrRet;
}

/*
********************************************************************************
* Function Name: WdgM_CheckpointID_Chk
*
* Explanation: Based on SE structure pointer and CheckpointID,the function
*              determine the CheckpointID validity.
*
* param: SEGPtr: SE Structure pointer.
*        CheckpointID: CPID.
*
* retval: Error Id defined in WdgM_Types.h.
********************************************************************************
*/
static FUNC(uint8, WDGM_CODE) WdgM_CheckpointID_Chk
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr,
    WdgM_CheckpointIdType CheckpointID
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    uint8 errorId = WDGM_E_NO_ERR;

    if( NULL_PTR != SEGPtr )
    {
        /* Check input CheckpointID is in the range. */
        if( (SEGPtr->CheckpointIdNum) <= CheckpointID )
        {
            errorId = WDGM_E_CPID;
        }
    }
    else
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = WDGM_E_INV_POINTER;
    }

    return errorId;
}

/*
********************************************************************************
* Function Name: WdgM_SetMode_Chk
*
* Explanation: Check parameter validity for the function WdgM_SetMode.
*
* param: Mode: One of the configured Watchdog Manager modes.
*        CallerID: Module ID of the calling module.
*        retBuf: return the Error Id.
*
* retval: Mode Structure pointer.
********************************************************************************
*/
#if ( WDGM_GENERAL_VERSION == WDGM_AUTOSAR422 )
static FUNC_P2CONST(WdgM_ModeStructType, WDGM_APPL_CONST, WDGM_CODE) WdgM_SetMode_Chk
(
    WdgM_ModeType Mode,
    uint16 CallerID,
    P2VAR(uint8, AUTOMATIC, WDGM_APPL_DATA) retBuf
)
#else
static FUNC_P2CONST(WdgM_ModeStructType, WDGM_APPL_CONST, WDGM_CODE) WdgM_SetMode_Chk
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    WdgM_ModeType Mode,
    P2VAR(uint8, AUTOMATIC, WDGM_APPL_DATA) retBuf
)
#endif  /* WDGM_GENERAL_VERSION == WDGM_AUTOSAR422 */
{
    uint16 cnt;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    uint8 errorId = WDGM_E_NO_ERR;
    const WdgM_ModeStructType* modePtr;
#if ( WDGM_GENERAL_VERSION == WDGM_AUTOSAR422 )
    WDGM_DUMMY_STATEMENT(CallerID);
#endif  /* WDGM_GENERAL_VERSION == WDGM_AUTOSAR422 */
    /* Find the corresponding mode structure according to the incoming mode parameter. */
    for( cnt = WDGM_VALUE_ZERO; cnt < WDGM_MODE_ALL_NUM; cnt++ )
    {
        modePtr = WdgM_Mode_Ptr[cnt];
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if( NULL_PTR != modePtr )
        {
            if( modePtr->ModeId == Mode )
            {
                break;
            }
        }
    }
    if( WDGM_MODE_ALL_NUM == cnt )
    {
        errorId = WDGM_E_PARAM_MODE;
    }

    *retBuf = errorId;

    return modePtr;
}

/*
********************************************************************************
* Function Name: WdgM_SearchModePtr
*
* Explanation: Based on ModeId,the function find the Mode Structure pointer.
*
* param: Mode: One of the configured Watchdog Manager modes.
*
* retval: Mode Structure pointer.
********************************************************************************
*/
static FUNC_P2CONST(WdgM_ModeStructType, WDGM_APPL_CONST, WDGM_CODE) WdgM_SearchModePtr
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    WdgM_ModeType Mode
)
{
    uint16 cnt;
    const WdgM_ModeStructType* modePtr;

    /* Poll all configured modes. */
    for( cnt = WDGM_VALUE_ZERO; cnt < WDGM_MODE_ALL_NUM; cnt++ )
    {
        modePtr = WdgM_Mode_Ptr[cnt];

        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if( modePtr->ModeId == Mode )   /* Find initialization mode. */
        {
            break;
        }
    }
    if( WDGM_MODE_ALL_NUM == cnt )  /* Did not find return NULL_PTR. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        modePtr = NULL_PTR;
    }

    return modePtr;
}

/*
********************************************************************************
* Function Name: WdgM_GetElapsedValue
*
* Explanation: Compute the timestamp differences between start Checkpoint and end Checkpoint.
*
* param: CounterID: Based on SE configurations.
*        Value: previous tick.
*        ElapsedValue: the elapsed tick value between the current tick
*                       and the previous tick.
*
* retval: Error Id defined in WdgM_Types.h.
********************************************************************************
*/
static FUNC(uint8, WDGM_CODE) WdgM_GetElapsedValue
(
    CounterType CounterID,TickRefType Value,
    TickRefType ElapsedValue
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    uint8 errorId;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    StatusType status;

    /* Check if input pointer is NULL. */
    if( (NULL_PTR != Value) && (NULL_PTR != ElapsedValue) )
    {
        /* Call GetElapsedValue function get elapsed value. */
        status = GetElapsedValue(CounterID, Value, ElapsedValue);
        if( E_OK == status )
        {
            errorId = WDGM_E_NO_ERR;
        }
        else if( E_OS_ID == status )
        {
            errorId = WDGM_E_GETELAPSEDVALUE_OS_ID;
        }
        else if( E_OS_VALUE == status )
        {
            errorId = WDGM_E_GETELAPSEDVALUE_OS_VALUE;
        }
        else
        {
            errorId = WDGM_E_GETELAPSEDVALUE_OS_EXCEPTION;
        }
    }
    else
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = WDGM_E_INV_POINTER;
    }
    return errorId;
}

/*
********************************************************************************
* Function Name: WdgM_ErrorHandling
*
* Explanation: Based on mode and global status,the function determine how
*              handling the watchdog.
*
* param: modePtr: Mode Structure pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, WDGM_CODE) WdgM_ErrorHandling
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr
)
{
#if ( WDGM_STATECOMBINER_SUPPORT != STD_ON )
    WdgM_TriggerNumType cnt;
#endif  /* WDGM_STATECOMBINER_SUPPORT != STD_ON */

    if( WDGM_GLOBAL_STATUS_STOPPED == WdgM_GlobalInfo.GlobalStatus )
    {
        /* polyspace +1 MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_WdgM_Rule14.3" */
        if( STD_ON == WDGM_IMMEDIATE_RESET )    /* Cfg:WdgMImmediateReset = TRUE */
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
#if( WDGM_IMMEDIATE_RESET == STD_ON )
            (void)Mcu_PerformReset(); /* [SWS_WdgM_00133] */  /* PRQA S 3335 */  /* NSCA_QAC_WdgM_Rule17.3 */
#endif  /* WDGM_IMMEDIATE_RESET == STD_ON */
        }
        else
        {
            Wdg30_Sbc_Timer_SetTimeout();
#if ( WDGM_STATECOMBINER_SUPPORT == STD_ON )
            /* Call the WdgM SetTriggerCondition function instead of WdgIf. */
            WdgM_StateCombinerSetTriggerCondition(modePtr, WDGM_STATECOMBINER_WDGIFENMODE, WDGM_VALUE_ZERO);
#else
            /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
            for( cnt = WDGM_VALUE_ZERO; cnt < modePtr->TriggerNum; cnt++ )
            {
                /* wait WDG perform reset. */
                /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                if( modePtr->Trigger[cnt].WatchdogMode != WDGIF_OFF_MODE )
                {
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
                    if( modePtr->Trigger[cnt].TriggerCoreRefID == (WdgM_CoreIdType)GetCoreID() )
#endif  /* WDGM_MULTICORE_SUPPORT == STD_ON */
                    {
                        WdgIf_SetTriggerCondition(modePtr->Trigger[cnt].DeviceIndex, WDGM_VALUE_ZERO);
                    }
                }
            }
#endif  /* WDGM_STATECOMBINER_SUPPORT == STD_ON */
        }
    }
    else
    {
#if ( WDGM_STATECOMBINER_SUPPORT == STD_ON )
        /* Call the WdgM SetTriggerCondition function instead of WdgIf. */
        WdgM_StateCombinerSetTriggerCondition(modePtr, WDGM_STATECOMBINER_WDGIFENMODE,
                                              modePtr->Trigger[modePtr->StateCombinerMasterTriggerID].TriggerConditionValue);
#else
        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
        for( cnt = WDGM_VALUE_ZERO; cnt < modePtr->TriggerNum; cnt++ )
        {
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( modePtr->Trigger[cnt].WatchdogMode != WDGIF_OFF_MODE )
            {
                /* reset WDG. */
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
                if( modePtr->Trigger[cnt].TriggerCoreRefID == (WdgM_CoreIdType)GetCoreID() )
#endif
                {
                    WdgIf_SetTriggerCondition(modePtr->Trigger[cnt].DeviceIndex,
                                          modePtr->Trigger[cnt].TriggerConditionValue);
                }
            }
        }
#endif  /* WDGM_STATECOMBINER_SUPPORT == STD_ON */
    }
}

/*
********************************************************************************
* Function Name: WdgM_CheckAliveSpuvInMode
*
* Explanation: Based on mode and SE structure pointer, the function determines
*              the configurations of the Alive Supervision for the SE.
*
* param: modePtr: Mode Structure pointer.
*        SEGPtr: SE Structure pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, WDGM_CODE) WdgM_CheckAliveSpuvInMode
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr,
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
)
{
    boolean searchAddrFlag = FALSE;
    WdgM_AliveSupervisionNumType cnt;
    /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
    SEGPtr->SEVariable->AliveSupervisionNum = WDGM_VALUE_ZERO;

    /* Find all alive supervision for mode configuration. */
    /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
    for( cnt = WDGM_VALUE_ZERO; cnt < modePtr->AliveSupervisionNum; cnt++ )
    {
        /* Find the SE that the mode configuration alive supervision belongs to. */
        if( SEGPtr->SupervisedEntityId
            == modePtr->AliveSupervisionCfg[cnt].CheckpointIdRef.LogicalSEId )
        {
            if( FALSE == searchAddrFlag )
            {
                SEGPtr->SEVariable->AliveSupervisionCfg = &modePtr->AliveSupervisionCfg[cnt];
                searchAddrFlag = TRUE;
            }
            SEGPtr->SEVariable->AliveSupervisionNum++;
        }
    }
    if( TRUE == searchAddrFlag )    /* Found the corresponding alive supervision. */
    {
        /* Clear alive supervision internal variable and enable the SE. */
        SEGPtr->SEVariable->AliveFailedCnt = WDGM_VALUE_ZERO;
        SEGPtr->SEVariable->AliveIndicationCnt = WDGM_VALUE_ZERO;
        SEGPtr->SEVariable->AliveSupervisionCycCnt = WDGM_VALUE_ZERO;
        SEGPtr->SEVariable->SupervisedEntityEnable |= WDGM_ALIVE_SPV_ENABLE;
    }
    else
    {
        /* Disable alive supervisionthe of the SE. */
        /* polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_WdgM_UINT_CONSTANT_OVFL" */
        SEGPtr->SEVariable->SupervisedEntityEnable &= (uint8)(~((uint32)WDGM_ALIVE_SPV_ENABLE));
    }
}

/*
********************************************************************************
* Function Name: WdgM_CheckDeadLineSpuvInMode
*
* Explanation: Based on mode and SE structure pointer, the function determines
*              the configurations of the Deadline Supervision for the SE.
*
* param: modePtr: Mode Structure pointer.
*        SEGPtr: SE Structure pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, WDGM_CODE) WdgM_CheckDeadLineSpuvInMode
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr,
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
)
{
    boolean searchAddrFlag = FALSE;
    WdgM_DeadLineSupervisionNumType cnt;
    SEGPtr->SEVariable->DeadLineSupervisionNum  = WDGM_VALUE_ZERO;

    /* Find all deadline supervision for mode configuration. */
    for( cnt = WDGM_VALUE_ZERO; cnt < modePtr->DeadLineSupervisionNum; cnt++ )
    {
        /* Find the SE that the mode configuration deadline supervision belongs to. */
        if( SEGPtr->SupervisedEntityId
            == modePtr->DeadLineSupervisionCfg[cnt].DeadlineStopRef.LogicalSEId )
        {
            if( FALSE == searchAddrFlag )
            {
                SEGPtr->SEVariable->DeadLineSupervisionCfg = &modePtr->DeadLineSupervisionCfg[cnt];
                searchAddrFlag = TRUE;
            }
            SEGPtr->SEVariable->DeadLineSupervisionNum++;
        }
    }
    if( TRUE == searchAddrFlag )    /* Found the corresponding deadline supervision. */
    {
        /* Enable deadline supervisionthe of the SE. */
        SEGPtr->SEVariable->SupervisedEntityEnable |= WDGM_DEADLINE_SPV_ENABLE;
    }
    else
    {
        /* Disable deadline supervisionthe of the SE. */
        /* polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_WdgM_UINT_CONSTANT_OVFL" */
        SEGPtr->SEVariable->SupervisedEntityEnable &= (uint8)(~((uint32)WDGM_DEADLINE_SPV_ENABLE));
    }
}

/*
********************************************************************************
* Function Name: WdgM_CheckExLogicalSpuvInMode
*
* Explanation: Based on mode and SE structure pointer, the function
*              configurate the external logical supervision for the SE.
*
* param: modePtr: Mode Structure pointer.
*        SEGPtr: SE Structure pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, WDGM_CODE) WdgM_CheckExLogicalSpuvInMode
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr,
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
)
{
    boolean searchAddrFlag = FALSE;
    WdgM_ExternalLogicalSupervisionNumType cnt;
    WdgM_ExternalCPInitialNumType cpInitialCnt;
    WdgM_ExternalCPFinalNumType cpFinalCnt;
    WdgM_ExternalTransitionNumType exTranCnt;

    /* Find all external logical supervision for mode configuration. */
    for( cnt = WDGM_VALUE_ZERO; cnt < modePtr->ExternalLogicalSupervisionNum; cnt++ )
    {
        /* Find the initialization checkpoint for external logic supervision. */
        for( cpInitialCnt = WDGM_VALUE_ZERO;
            cpInitialCnt < modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalCPInitialNum;
            cpInitialCnt++ )
        {
            if( SEGPtr->SupervisedEntityId
                == modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalCheckpointInitialRef[cpInitialCnt].LogicalSEId )
            {
                searchAddrFlag = TRUE;
                break;
            }
        }
        if( FALSE == searchAddrFlag )
        {
            /* Find the finished checkpoint for external logic supervision. */
            for( cpFinalCnt = WDGM_VALUE_ZERO;
                 cpFinalCnt < modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalCPFinalNum;
                 cpFinalCnt++ )
            {
                if( SEGPtr->SupervisedEntityId
                    == modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalCheckpointFinalRef[cpFinalCnt].LogicalSEId )
                {
                    searchAddrFlag = TRUE;
                    break;
                }
            }
        }
        if( FALSE == searchAddrFlag )
        {
            /* Find the source or destination checkpoint for external logic supervision. */
            for( exTranCnt = WDGM_VALUE_ZERO;
                 exTranCnt < modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalTransitionNum;
                 exTranCnt++ )
            {
                if( (SEGPtr->SupervisedEntityId
                     == modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalTransitionCfg[exTranCnt].ExternalTransitionDestRef.LogicalSEId)
                     || (SEGPtr->SupervisedEntityId
                         == modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalTransitionCfg[exTranCnt].ExternalTransitionSourceRef.LogicalSEId))
                {
                    searchAddrFlag = TRUE;
                    break;
                }
            }
        }
        if( TRUE == searchAddrFlag )    /* Found the corresponding checkpoint. */
        {
            break;
        }
    }
    if( TRUE == searchAddrFlag )    /* Found the corresponding logical supervision. */
    {
        /* Enable external logic supervisionthe of the SE. */
        SEGPtr->SEVariable->SupervisedEntityEnable |= WDGM_EXLOGICAL_SPV_ENABLE;
    }
    else
    {
        /* Disable external logic supervisionthe of the SE. */
        /* polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_WdgM_UINT_CONSTANT_OVFL" */
        SEGPtr->SEVariable->SupervisedEntityEnable &= (uint8)(~((uint32)WDGM_EXLOGICAL_SPV_ENABLE));
    }
}

/*
********************************************************************************
* Function Name: WdgM_CheckLogicalSpuvInMode
*
* Explanation: Based on SE structure pointer, the function determines the configurations
*              of the internal Logical Supervision for the SE.
*
* param: modePtr: Mode Structure pointer.
*        SEGPtr: SE Structure pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, WDGM_CODE) WdgM_CheckLogicalSpuvInMode
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr,
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
)
{
    WdgM_LocalStatusParamsNumType cnt;

    /* Poll all configured local status parameters in mode. */
    for( cnt = WDGM_VALUE_ZERO; cnt < modePtr->LocalStatusSupervisedEntityNum; cnt++ )
    {
        /* If the mode reference local status parameters which has configured logical supervision. */
        if( (WDGM_VALUE_ZERO < SEGPtr->LogicalSupervisionNum) &&
            ((uint16)(modePtr->LocalStatusSupervisedEntityCfg[cnt]) == SEGPtr->SupervisedEntityId) )
        {
            /* Enable interrnal logic supervisionthe of the SE. */
            SEGPtr->SEVariable->SupervisedEntityEnable |= WDGM_LOGICAL_SPV_ENABLE;
            break;
        }
    }
    /* If no matching entity is found. */
    if( cnt >= modePtr->LocalStatusSupervisedEntityNum )
    {
        /* Disable interrnal logic supervisionthe of the SE. */
        /* polyspace +1 DEFECT:UINT_CONSTANT_OVFL [Justified:Unset] "NSCA_Polyspace_WdgM_UINT_CONSTANT_OVFL" */
        SEGPtr->SEVariable->SupervisedEntityEnable &= (uint8)(~((uint32)WDGM_LOGICAL_SPV_ENABLE));
    }
}

/*
********************************************************************************
* Function Name: WdgM_SESpuvCfgInMode
*
* Explanation: Based on mode and SE structure pointer and global status, the function determines
*              the configurations of all supervision for the SE.
*
* param: modePtr: Mode Structure pointer.
*        SEGPtr: SE Structure pointer.
*
* retval: None
********************************************************************************
*/
static FUNC(void, WDGM_CODE) WdgM_SESpuvCfgInMode
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr,
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr
)
{
    WdgM_CheckAliveSpuvInMode(modePtr,SEGPtr);  /* Check if enable alive supervision. */
    WdgM_CheckDeadLineSpuvInMode(modePtr,SEGPtr);   /* Check if enable deadline supervision. */
    WdgM_CheckExLogicalSpuvInMode(modePtr,SEGPtr);  /* Check if enable external logical supervision. */
    WdgM_CheckLogicalSpuvInMode(modePtr, SEGPtr);    /* Check if enable internal logical supervision. */

    /* Is the SE active or not. */
    if( WDGM_ALL_SPV_DISABLE == SEGPtr->SEVariable->SupervisedEntityEnable )
    {
        if( (WDGM_LOCAL_STATUS_OK == SEGPtr->SEVariable->LocalStatus)
             || (WDGM_LOCAL_STATUS_FAILED == SEGPtr->SEVariable->LocalStatus) )
        {
            /* [SWS_WdgM_00207] [SWS_WdgM_00291] */
            SEGPtr->SEVariable->LocalStatus = WDGM_LOCAL_STATUS_DEACTIVATED;
            /* [SWS_WdgM_00315] */
            SEGPtr->SEVariable->AliveSpvStatus = WDGM_AlLIVE_CORRECT;
            SEGPtr->SEVariable->DeadLineSpvStatus = WDGM_DEADLINE_CORRECT;
            SEGPtr->SEVariable->LogicalSpvStatus = WDGM_LOGICAL_CORRECT;
            SEGPtr->SEVariable->AliveFailedCnt = WDGM_VALUE_ZERO;
        }
    }
    else
    {
        if( WDGM_LOCAL_STATUS_DEACTIVATED == SEGPtr->SEVariable->LocalStatus )
        {
            /* [SWS_WdgM_00209] */
            SEGPtr->SEVariable->LocalStatus = WDGM_LOCAL_STATUS_OK;
        }
    }
}

/*
********************************************************************************
* Function Name: WdgM_CheckInternalGraphBelongTo
*
* Explanation: Based on SE structure pointer and CheckpointID, the function
*              check the CheckpointID belong to internal graph or not.
*
* param: CheckpointID: Identifier of the Checkpoint.
*        SEGPtr: SE Structure pointer.
*
* retval: TRUE: This CheckpointID belong to the graph.
*         FALSE: This CheckpointID do not belong to the graph.
********************************************************************************
*/
static FUNC(boolean, WDGM_CODE) WdgM_CheckInternalGraphBelongTo
(
    P2CONST(WdgM_SEGType, AUTOMATIC, WDGM_APPL_CONST) SEGPtr,
    WdgM_CheckpointIdType CheckpointID,
    P2VAR(boolean, AUTOMATIC, WDGM_APPL_DATA) GetSourceCheckPointTickFlag_Pra
)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    boolean errorId = FALSE;
    WdgM_LogicalSupervisionNumType cnt;

    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( NULL_PTR != SEGPtr )    /* Cheak if input pointer is NULL. */
    {
        for( cnt = WDGM_VALUE_ZERO; cnt < SEGPtr->LogicalSupervisionNum; cnt++ )
        {
            /* Check if the checkpoint is the source or destination. */
            /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
            if( (SEGPtr->LogicalSupervisionCfg[cnt].transitionIdDest == CheckpointID)
                 || (SEGPtr->LogicalSupervisionCfg[cnt].transitionSource == CheckpointID) )
            {
                errorId = TRUE;
                if(SEGPtr->LogicalSupervisionCfg[cnt].transitionSource == CheckpointID)
                {
                    *GetSourceCheckPointTickFlag_Pra = TRUE;
                }
                else{
                    *GetSourceCheckPointTickFlag_Pra = FALSE;
                }
                break;
            }
        }
    }

    return errorId;
}

/*
********************************************************************************
* Function Name: WdgM_CheckExternalGraphBelongTo
*
* Explanation: Based on SE structure pointer and CheckpointRef, the function
*              check the CheckpointID belong to external graph or not.
*
* param: CheckpointRef: CPID and SEID.
*        SEGPtr: SE Structure pointer.
*
* retval: None
********************************************************************************
*/
static FUNC_P2VAR(WdgM_ExLogicalSupervisionType, WDGM_APPL_DATA, WDGM_CODE) WdgM_CheckExternalGraphBelongTo
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr,
    WdgM_CheckpointRefType CheckpointRef,
    P2VAR(boolean, AUTOMATIC, WDGM_APPL_DATA) ExternalGraphFlagPtr
)
{
    boolean breakFlag = FALSE;
    boolean searchFlag = FALSE;
    WdgM_ExternalLogicalSupervisionNumType cnt;
    WdgM_ExternalCPInitialNumType cpInitialCnt;
    WdgM_ExternalCPFinalNumType cpFinalCnt;
    WdgM_ExternalTransitionNumType exTranCnt;
    WdgM_ExLogicalSupervisionType* externalLogicalSpvCfg = NULL_PTR;

    /* Check if input pointer is NULL. */
    if( (NULL_PTR != modePtr) && (NULL_PTR != ExternalGraphFlagPtr) )
    {
        /* Check if external logical supervision number greater than 0. */
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if( modePtr->ExternalLogicalSupervisionNum > WDGM_VALUE_ZERO )
        {
            /* Find all logical supervision. */
            for( cnt = WDGM_VALUE_ZERO; cnt < modePtr->ExternalLogicalSupervisionNum; cnt++ )
            {
                /* Find all initial checkpoint. */
                for( cpInitialCnt = WDGM_VALUE_ZERO;
                     cpInitialCnt < modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalCPInitialNum;
                     cpInitialCnt++ )
                {
                    if( (CheckpointRef.LogicalSEId
                         == modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalCheckpointInitialRef[cpInitialCnt].LogicalSEId)
                        && (CheckpointRef.LogicalCPId
                            == modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalCheckpointInitialRef[cpInitialCnt].LogicalCPId) )
                    {
                        searchFlag = TRUE;
                        break;
                    }
                }
                if( FALSE == searchFlag )   /* If not find initial checkpoint. */
                {
                    /* Find all final checkpoint. */
                    for( cpFinalCnt = WDGM_VALUE_ZERO;
                         cpFinalCnt < modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalCPFinalNum;
                         cpFinalCnt++ )
                    {
                        if( (CheckpointRef.LogicalSEId
                             == modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalCheckpointFinalRef[cpFinalCnt].LogicalSEId)
                            && (CheckpointRef.LogicalCPId
                                == modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalCheckpointFinalRef[cpFinalCnt].LogicalCPId) )
                        {
                            searchFlag = TRUE;
                            break;
                        }
                    }
                }
                if( FALSE == searchFlag )   /* If not find final checkpoint. */
                {
                    /* Find all soure or destination checkpoint. */
                    for( exTranCnt = WDGM_VALUE_ZERO;
                         exTranCnt < modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalTransitionNum;
                         exTranCnt++ )
                    {
                        if( (CheckpointRef.LogicalSEId
                             == modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalTransitionCfg[exTranCnt].ExternalTransitionDestRef.LogicalSEId)
                            && (CheckpointRef.LogicalCPId
                                == modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalTransitionCfg[exTranCnt].ExternalTransitionDestRef.LogicalCPId))
                        {
                            searchFlag = TRUE;
                            breakFlag = TRUE;
                        }
                        if( (CheckpointRef.LogicalSEId
                             == modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalTransitionCfg[exTranCnt].ExternalTransitionSourceRef.LogicalSEId)
                            && (CheckpointRef.LogicalCPId
                                == modePtr->ExternalLogicalSupervisionCfg[cnt].ExternalTransitionCfg[exTranCnt].ExternalTransitionSourceRef.LogicalCPId) )
                        {
                            searchFlag = TRUE;
                            breakFlag = TRUE;
                        }
                        if( TRUE == breakFlag )
                        {
                            break;
                        }
                    }
                }
                if( TRUE == searchFlag )    /* Looking for the corresponding checkpoint. */
                {
                    externalLogicalSpvCfg = &modePtr->ExternalLogicalSupervisionCfg[cnt];
                    break;
                }
            }
            *ExternalGraphFlagPtr = searchFlag;
        }
    }

    return externalLogicalSpvCfg;
}
/*
********************************************************************************
* Function Name: WdgM_CheckAllCfg
*
* Explanation: Based on SE structure pointer and Mode structure pointer, the function
*              check the Mode and SE configurations.
*
* param: None
*
* retval: E_OK: Successful Mode and SE configurations.
*         E_NOT_OK: Failed  Mode and SE configurations.
********************************************************************************
*/
static FUNC(Std_ReturnType, WDGM_CODE) WdgM_CheckAllCfg(void)
{
    boolean breakFlag = FALSE;
    Std_ReturnType stdRet = E_OK;
    uint8 cnt;
    const WdgM_SEGType* seGPtr;
    const WdgM_ModeStructType* modePtr;

    /* SE Cfg check. */
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    WdgM_SENumType seCnt;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.5" */
    WdgM_CoreIdType CoreID;
    CoreID = (WdgM_CoreIdType)GetCoreID();
    /* polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_WdgM_TAINTED_ARRAY_INDEX" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_WdgM_Dir4.14" */
    if( NULL_PTR == WdgM_SEG_Core_Ptr_Array[CoreID])
    {
        stdRet = E_NOT_OK;
        breakFlag = TRUE;
    }
    else
    {
        /* polyspace +3 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" */
        /* polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" */
        /* polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_WdgM_OutOfBoundsArrayIndex" */
        for( seCnt = WDGM_VALUE_ZERO; seCnt < SENumInCore[CoreID]; seCnt++ )
        {
            /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_WdgM_PtrOutside" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_WdgM_IllegallyDereferencedPointer" */
            if( NULL_PTR == WdgM_SEG_Core_Ptr_Array[CoreID][seCnt])
            {
                stdRet = E_NOT_OK;
                breakFlag = TRUE;
            }
            else
            {
                seGPtr = WdgM_SEG_Core_Ptr_Array[CoreID][seCnt];
#else
    WdgM_SENumType seCnt;
    for( seCnt = WDGM_VALUE_ZERO; seCnt < WDGM_SE_ALL_NUM; seCnt++ )
    {
        seGPtr = WdgM_SEG_Ptr[seCnt];
#endif /*WDGM_MULTICORE_SUPPORT == STD_ON */
        /* Check if the SEVariable is empty. */
        if( NULL_PTR == seGPtr->SEVariable )
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            stdRet = E_NOT_OK;
            breakFlag = TRUE;
        }
        else
        {
            /* If the internal logic supervision is configured,
            and check if logic supervises pointer is empty. */
            if( seGPtr->LogicalSupervisionNum > WDGM_VALUE_ZERO )
            {
                if( NULL_PTR == seGPtr->LogicalSupervisionCfg )
                /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                {
                    stdRet = E_NOT_OK;
                    breakFlag = TRUE;
                }
            }
        }
        if( TRUE == breakFlag ) /* If there is an error then break loop. */
        {
            breakFlag = FALSE;
            break;
        }
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
            }
        }
    }
#else
    }
#endif/*WDGM_MULTICORE_SUPPORT == STD_ON*/
    /* Mode Cfg check. */
    if( E_OK == stdRet )
    {
        for( cnt = WDGM_VALUE_ZERO; cnt < WDGM_MODE_ALL_NUM; cnt++ )
        {
            modePtr = WdgM_Mode_Ptr[cnt];
            /* If the alive supervision is configured,
            and check if alive supervises pointer is empty. */
            /* polyspace-begin RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( WDGM_VALUE_ZERO != modePtr->AliveSupervisionNum )
            {
                if( NULL_PTR == modePtr->AliveSupervisionCfg )
                {
                    stdRet = E_NOT_OK;
                    breakFlag = TRUE;
                }
            }
            /* If the deadline supervision is configured,
            and check if deadline supervises pointer is empty. */
            if( WDGM_VALUE_ZERO != modePtr->DeadLineSupervisionNum )
            {
                if( NULL_PTR == modePtr->DeadLineSupervisionCfg )
                {
                    stdRet = E_NOT_OK;
                    breakFlag = TRUE;
                }
            }
            /* If the external logic supervision is configured,
            and check if logic supervises pointer is empty. */
            if( WDGM_VALUE_ZERO != modePtr->ExternalLogicalSupervisionNum )
            {
                if( NULL_PTR == modePtr->ExternalLogicalSupervisionCfg )
                {
                    stdRet = E_NOT_OK;
                    breakFlag = TRUE;
                }
                else
                {
                    if( (WDGM_VALUE_ONE > modePtr->ExternalLogicalSupervisionCfg->ExternalCPInitialNum)
                         || (WDGM_VALUE_ONE > modePtr->ExternalLogicalSupervisionCfg->ExternalCPFinalNum)
                         || (NULL_PTR == modePtr->ExternalLogicalSupervisionCfg->ExternalCheckpointInitialRef)
                         || (NULL_PTR == modePtr->ExternalLogicalSupervisionCfg->ExternalCheckpointFinalRef) )
                    {
                        stdRet = E_NOT_OK;
                        breakFlag = TRUE;
                    }
                    else
                    {
                        if( WDGM_VALUE_ZERO != modePtr->ExternalLogicalSupervisionCfg->ExternalTransitionNum )
                        {
                            if( NULL_PTR == modePtr->ExternalLogicalSupervisionCfg->ExternalTransitionCfg )
                            {
                                stdRet = E_NOT_OK;
                                breakFlag = TRUE;
                            }
                        }
                    }
                }
            }
            /* If the wdgtrigger is configured,
            and check if wdgtrigger pointer is empty. */
            if( WDGM_VALUE_ZERO != modePtr->TriggerNum )
            {
                if( NULL_PTR == modePtr->Trigger )
                {
                    stdRet = E_NOT_OK;
                    breakFlag = TRUE;
                }
            }
            if( TRUE == breakFlag ) /* If there is an error then break loop. */
            {
                break;
            }
            /* polyspace-end RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        }
    }

    return stdRet;
}

#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: WdgM_Exponentiation
*
* Explanation: Power operation function
*
* param: uint8 BaseNumber
         uint8 ExponentsNumber
*
* retval: Power operation result
********************************************************************************
*/
static FUNC(Std_ReturnType, WDGM_CODE) WdgM_Exponentiation(uint8 BaseNumber,uint8 ExponentsNumber)
{
    uint8 loopIndex = WDGM_VALUE_ONE;
    Std_ReturnType retValue = WDGM_VALUE_ONE;
    for( loopIndex = WDGM_VALUE_ONE; loopIndex <= ExponentsNumber; loopIndex++ )
    {
        retValue *= BaseNumber;
    }
    return (retValue - WDGM_VALUE_ONE);
}
#endif /* WDGM_MULTICORE_SUPPORT == STD_ON */

#if ( WDGM_STATECOMBINER_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: WdgM_StateCombinerSetTriggerCondition
*
* Explanation: When enabling the multi-core synchronous monitoring mechanism,
*              use this function instead of WdgIf_SetTriggerCondition
*              and realize feeding dog function.
*
* param: modePtr: Mode Structure pointer.
*        wdgIfModeFilter: WdgMWatchdogMode filter.
*        timeout: Timeout value for setting the trigger counter.
*
* retval: None
********************************************************************************
*/
static FUNC(void, WDGIF_CODE) WdgM_StateCombinerSetTriggerCondition
(
    P2CONST(WdgM_ModeStructType, AUTOMATIC, WDGM_APPL_CONST) modePtr,
    uint8 wdgIfModeFilter,
    WdgM_TriggerConditionValueType timeout
)
{
    uint16 stateCombinerErrFlg = WDGM_VALUE_ZERO;
    Std_ReturnType stdRet = E_OK;
    WdgM_TriggerNumType cnt;
    WdgM_TriggerConditionValueType triggerConditionValue;
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    WdgM_CoreIdType coreId;

    coreId = (WdgM_CoreIdType)GetCoreID();
#endif  /* WDGM_MULTICORE_SUPPORT == STD_ON */

    /* Traverse all trigger belong to current mode. */
    for( cnt = WDGM_VALUE_ZERO; cnt < modePtr->TriggerNum; cnt++ )
    {
        /* If WdgMWatchdogMode of current mode is match to the input parameter
           and this trigger is not participate in multi-core synchronous monitoring. */
        if( (WDGM_VALUE_ZERO != ((uint8)((uint8)WDGM_VALUE_ONE << (uint8)modePtr->Trigger[cnt].WatchdogMode) & wdgIfModeFilter)) &&
            (WDGM_STATECOMBINER_CONFNOTRIGGER == modePtr->StateCombinerTriggerAssign[cnt]) )
        {
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
            /* If this trigger is match to current coreId. */
            if( modePtr->Trigger[cnt].TriggerCoreRefID == coreId )
#endif  /* WDGM_MULTICORE_SUPPORT == STD_ON */
            {
                if( WDGM_VALUE_ZERO != timeout)
                {
                    triggerConditionValue = modePtr->Trigger[cnt].TriggerConditionValue;
                }
                else
                {
                    triggerConditionValue = WDGM_VALUE_ZERO;
                }
                /* Feed dog with input parameters. */
                WdgIf_SetTriggerCondition(modePtr->Trigger[cnt].DeviceIndex, triggerConditionValue);
            }
        }
    }

    /* Traverse all trigger belong to current mode. */
    for( cnt = WDGM_VALUE_ZERO; cnt < modePtr->TriggerNum; cnt++ )
    {
        /* If WdgMWatchdogMode of current mode is match to the input parameter
           and this trigger is participate in multi-core synchronous monitoring. */
        if( (WDGM_VALUE_ZERO != ((uint8)((uint8)WDGM_VALUE_ONE << (uint8)modePtr->Trigger[cnt].WatchdogMode) & wdgIfModeFilter)) &&
            (WDGM_STATECOMBINER_CONFNOTRIGGER != modePtr->StateCombinerTriggerAssign[cnt]) )
        {
#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
            if( modePtr->Trigger[cnt].TriggerCoreRefID == coreId )
#endif  /* WDGM_MULTICORE_SUPPORT == STD_ON */
            {
                /* Each Trigger increase one in every cycle in itself core. */
                WdgM_StateCombineCycleCnt[cnt]++;
                /* Reset the counter if it exceeds its upper limit. */
                if( WdgM_StateCombineCycleCnt[cnt] >= WDGM_STATECOMBINER_CHECKLMT )
                {
                    WdgM_StateCombineCycleCnt[cnt] = modePtr->StateCombinerStartUpSync;
                }
            }

#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
            if( modePtr->Trigger[modePtr->StateCombinerMasterTriggerID].TriggerCoreRefID == coreId )
#endif  /* WDGM_MULTICORE_SUPPORT == STD_ON */
            {
                /* If this Trigger is slave trigger. */
                if( WDGM_STATECOMBINER_SLAVETRIGGER == modePtr->StateCombinerTriggerAssign[cnt] )
                {
                    /* If master trigger's counter is not exceed configed startup synchronized time.*/
                    if( WdgM_StateCombineCycleCnt[modePtr->StateCombinerMasterTriggerID] > modePtr->StateCombinerStartUpSync )
                    {
                        /* The master trigger shall check every slave trigger's counter in every window time. */
                        if( WDGM_VALUE_ZERO == ( (WdgM_StateCombineCycleCnt[modePtr->StateCombinerMasterTriggerID] - modePtr->StateCombinerStartUpSync) %
                            modePtr->Trigger[cnt].StateCombinerCheckWnd) )
                        {
                            /* If the trigger failed, set the corresponding flag. */
                            if( (WdgM_StateCombineCycleCnt[cnt] < modePtr->Trigger[cnt].StateCombinerMinDelta) ||
                                (WdgM_StateCombineCycleCnt[cnt] > modePtr->Trigger[cnt].StateCombinerMaxDelta) )
                            {
                                stateCombinerErrFlg =  stateCombinerErrFlg | (uint16)((uint16)WDGM_VALUE_ONE << (uint16)cnt);
                            }
                            /* Reset the counter. */
                            WdgM_StateCombineCycleCnt[cnt] = WDGM_VALUE_ZERO;
                        }
                    }
                    else
                    {
                        /* Reset the counter. */
                        WdgM_StateCombineCycleCnt[cnt] = WDGM_VALUE_ZERO;
                    }
                }
            }
        }
    }

#if ( WDGM_MULTICORE_SUPPORT == STD_ON )
    /* Only master trigger and its core can call the WdgIf module. */
    if( modePtr->Trigger[modePtr->StateCombinerMasterTriggerID].TriggerCoreRefID == coreId )
#endif  /* WDGM_MULTICORE_SUPPORT == STD_ON */
    {
        /* There are not errors found in multi-core synchronous monitoring mechanism. */
        if( WDGM_VALUE_ZERO == stateCombinerErrFlg )
        {
            WdgIf_SetTriggerCondition(modePtr->Trigger[modePtr->StateCombinerMasterTriggerID].DeviceIndex, timeout);
        }
        else
        {
            triggerConditionValue = WDGM_VALUE_ZERO;
#if ( WDGM_STATECOMBINERUSERPORT_SUPPORT == STD_ON )
            /* Notify the application when errors are found in multi-core synchronous monitoring. */
            if( NULL_PTR != modePtr->Trigger[modePtr->StateCombinerMasterTriggerID].WdgM_StateCombineNotification )
            {
                stdRet = modePtr->Trigger[modePtr->StateCombinerMasterTriggerID].WdgM_StateCombineNotification(modePtr->Trigger[modePtr->StateCombinerMasterTriggerID].DeviceIndex,
                                                                                                               &triggerConditionValue, stateCombinerErrFlg);
            }
            /* If application function return E_OK, WdgM will call WdgIf module with parameter from application. */
            if( E_OK == stdRet)
#endif  /* WDGM_STATECOMBINERUSERPORT_SUPPORT == STD_ON */
            {
                WdgIf_SetTriggerCondition(modePtr->Trigger[modePtr->StateCombinerMasterTriggerID].DeviceIndex,
                                            triggerConditionValue);
            }
        }
    }
}

#endif  /* WDGM_STATECOMBINER_SUPPORT == STD_ON */

#define WDGM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h"  /* PRQA S 5087 */  /* NSCA_QAC_Common_MemMap */

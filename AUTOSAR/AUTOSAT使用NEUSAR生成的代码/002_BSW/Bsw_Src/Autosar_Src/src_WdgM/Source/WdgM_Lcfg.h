/*
********************************************************************************
*
*  File name: WdgM_Lcfg.h
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : WangCong/2019.04.12
* Change: New
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date : Baowanglong/2020.03.27
* Change: Only version update to V3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date : Baowanglong/2020.05.25
* Change: Modify the file according to the code specification.
* Cause: Optimization.
********************************************************************************
* Version: 3.2
* Author/Date: WuZB/2020.11.03
* Change: Modify code format.
* Cause: Optimization.
********************************************************************************
* Version: 3.3
* Author/Date: WuZB/2020.12.10
* Change: Add macro definition.
* Cause: Optimization.
********************************************************************************
* Version: 3.4
* Author/Date: LQiao/2022.7.28
* Change: Add MULICORE.
* Cause: Optimization.
********************************************************************************
* Version: 3.5
* Author/Date: LQiao/2022.12.26
* Change: Add the included header file.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: LiuY/2024.7.26
* Change: Add Memmap segment definition.
* Cause: Optimization
********************************************************************************
*/
#ifndef WDGM_LCFG_H_
#define WDGM_LCFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "WdgM_Types.h"
#include "Os.h"
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define WDGM_SE_ALL_NUM                     (66U)
#define WDGM_MODE_ALL_NUM                   (1U)
#define WDGM_EXLOGICALVARIABLE_NUM          (0U)
#define WDGM_SE0_AliveCounter_C0            (0U)
#define WDGM_SE1_AliveCounter_C0            (1U)
#define WDGM_SE2_AliveCounter_C0            (2U)
#define WDGM_SE3_AliveCounter_C0            (3U)
#define WDGM_SE4_AliveCounter_C0            (4U)
#define WDGM_SE0_Deadline_C0                (5U)
#define WDGM_SE1_Deadline_C0                (6U)
#define WDGM_SE2_Deadline_C0                (7U)
#define WDGM_SE3_Deadline_C0                (8U)
#define WDGM_SE4_Deadline_C0                (9U)
#define WDGM_SE0_ProgramFlow_C0             (10U)
#define WDGM_SE0_AliveCounter_C1            (11U)
#define WDGM_SE1_AliveCounter_C1            (12U)
#define WDGM_SE2_AliveCounter_C1            (13U)
#define WDGM_SE3_AliveCounter_C1            (14U)
#define WDGM_SE4_AliveCounter_C1            (15U)
#define WDGM_SE0_Deadline_C1                (16U)
#define WDGM_SE1_Deadline_C1                (17U)
#define WDGM_SE2_Deadline_C1                (18U)
#define WDGM_SE3_Deadline_C1                (19U)
#define WDGM_SE4_Deadline_C1                (20U)
#define WDGM_SE0_ProgramFlow_C1             (21U)
#define WDGM_SE0_AliveCounter_C2            (22U)
#define WDGM_SE1_AliveCounter_C2            (23U)
#define WDGM_SE2_AliveCounter_C2            (24U)
#define WDGM_SE3_AliveCounter_C2            (25U)
#define WDGM_SE4_AliveCounter_C2            (26U)
#define WDGM_SE0_Deadline_C2                (27U)
#define WDGM_SE1_Deadline_C2                (28U)
#define WDGM_SE2_Deadline_C2                (29U)
#define WDGM_SE3_Deadline_C2                (30U)
#define WDGM_SE4_Deadline_C2                (31U)
#define WDGM_SE0_ProgramFlow_C2             (32U)
#define WDGM_SE0_AliveCounter_C3            (33U)
#define WDGM_SE1_AliveCounter_C3            (34U)
#define WDGM_SE2_AliveCounter_C3            (35U)
#define WDGM_SE3_AliveCounter_C3            (36U)
#define WDGM_SE4_AliveCounter_C3            (37U)
#define WDGM_SE0_Deadline_C3                (38U)
#define WDGM_SE1_Deadline_C3                (39U)
#define WDGM_SE2_Deadline_C3                (40U)
#define WDGM_SE3_Deadline_C3                (41U)
#define WDGM_SE4_Deadline_C3                (42U)
#define WDGM_SE0_ProgramFlow_C3             (43U)
#define WDGM_SE0_AliveCounter_C4            (44U)
#define WDGM_SE1_AliveCounter_C4            (45U)
#define WDGM_SE2_AliveCounter_C4            (46U)
#define WDGM_SE3_AliveCounter_C4            (47U)
#define WDGM_SE4_AliveCounter_C4            (48U)
#define WDGM_SE0_Deadline_C4                (49U)
#define WDGM_SE1_Deadline_C4                (50U)
#define WDGM_SE2_Deadline_C4                (51U)
#define WDGM_SE3_Deadline_C4                (52U)
#define WDGM_SE4_Deadline_C4                (53U)
#define WDGM_SE0_ProgramFlow_C4             (54U)
#define WDGM_SE0_AliveCounter_C5            (55U)
#define WDGM_SE1_AliveCounter_C5            (56U)
#define WDGM_SE2_AliveCounter_C5            (57U)
#define WDGM_SE3_AliveCounter_C5            (58U)
#define WDGM_SE4_AliveCounter_C5            (59U)
#define WDGM_SE0_Deadline_C5                (60U)
#define WDGM_SE1_Deadline_C5                (61U)
#define WDGM_SE2_Deadline_C5                (62U)
#define WDGM_SE3_Deadline_C5                (63U)
#define WDGM_SE4_Deadline_C5                (64U)
#define WDGM_SE0_ProgramFlow_C5             (65U)
#define WdgM_SE0_AliveCounter_C0_Mode0_SE0_Alive_CP_C0 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_AliveCounter_C0_Mode0_SE1_Alive_CP_C0 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_AliveCounter_C0_Mode0_SE2_Alive_CP_C0 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_AliveCounter_C0_Mode0_SE3_Alive_CP_C0 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_AliveCounter_C0_Mode0_SE4_Alive_CP_C0 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_Deadline_C0_Mode0_SE0_Deadline_CP1_C0 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_Deadline_C0_Mode0_SE0_Deadline_CP2_C0 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_Deadline_C0_Mode0_SE1_Deadline_CP1_C0 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_Deadline_C0_Mode0_SE1_Deadline_CP2_C0 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_Deadline_C0_Mode0_SE2_Deadline_CP1_C0 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_Deadline_C0_Mode0_SE2_Deadline_CP2_C0 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_Deadline_C0_Mode0_SE3_Deadline_CP1_C0 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_Deadline_C0_Mode0_SE3_Deadline_CP2_C0 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_Deadline_C0_Mode0_SE4_Deadline_CP1_C0 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_Deadline_C0_Mode0_SE4_Deadline_CP2_C0 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C0_Mode0_SE0_Logical_CP1_C0 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C0_Mode0_SE0_Logical_CP2_C0 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C0_Mode0_SE0_Logical_CP3_C0 (2U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C0_Mode0_SE0_Logical_CP4_C0 (3U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C0_Mode0_SE0_Logical_CP5_C0 (4U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C0_Mode0_SE0_Logical_CP6_C0 (5U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_AliveCounter_C1_Mode0_SE0_Alive_CP_C1 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_AliveCounter_C1_Mode0_SE1_Alive_CP_C1 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_AliveCounter_C1_Mode0_SE2_Alive_CP_C1 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_AliveCounter_C1_Mode0_SE3_Alive_CP_C1 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_AliveCounter_C1_Mode0_SE4_Alive_CP_C1 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_Deadline_C1_Mode0_SE0_Deadline_CP1_C1 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_Deadline_C1_Mode0_SE0_Deadline_CP2_C1 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_Deadline_C1_Mode0_SE1_Deadline_CP1_C1 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_Deadline_C1_Mode0_SE1_Deadline_CP2_C1 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_Deadline_C1_Mode0_SE2_Deadline_CP1_C1 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_Deadline_C1_Mode0_SE2_Deadline_CP2_C1 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_Deadline_C1_Mode0_SE3_Deadline_CP1_C1 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_Deadline_C1_Mode0_SE3_Deadline_CP2_C1 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_Deadline_C1_Mode0_SE4_Deadline_CP1_C1 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_Deadline_C1_Mode0_SE4_Deadline_CP2_C1 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C1_Mode0_SE0_Logical_CP1_C1 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C1_Mode0_SE0_Logical_CP2_C1 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C1_Mode0_SE0_Logical_CP3_C1 (2U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C1_Mode0_SE0_Logical_CP4_C1 (3U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C1_Mode0_SE0_Logical_CP5_C1 (4U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C1_Mode0_SE0_Logical_CP6_C1 (5U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_AliveCounter_C2_Mode0_SE0_Alive_CP_C2 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_AliveCounter_C2_Mode0_SE1_Alive_CP_C2 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_AliveCounter_C2_Mode0_SE2_Alive_CP_C2 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_AliveCounter_C2_Mode0_SE3_Alive_CP_C2 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_AliveCounter_C2_Mode0_SE4_Alive_CP_C2 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_Deadline_C2_Mode0_SE0_Deadline_CP1_C2 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_Deadline_C2_Mode0_SE0_Deadline_CP2_C2 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_Deadline_C2_Mode0_SE1_Deadline_CP1_C2 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_Deadline_C2_Mode0_SE1_Deadline_CP2_C2 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_Deadline_C2_Mode0_SE2_Deadline_CP1_C2 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_Deadline_C2_Mode0_SE2_Deadline_CP2_C2 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_Deadline_C2_Mode0_SE3_Deadline_CP1_C2 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_Deadline_C2_Mode0_SE3_Deadline_CP2_C2 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_Deadline_C2_Mode0_SE4_Deadline_CP1_C2 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_Deadline_C2_Mode0_SE4_Deadline_CP2_C2 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C2_Mode0_SE0_Logical_CP1_C2 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C2_Mode0_SE0_Logical_CP2_C2 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C2_Mode0_SE0_Logical_CP3_C2 (2U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C2_Mode0_SE0_Logical_CP4_C2 (3U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C2_Mode0_SE0_Logical_CP5_C2 (4U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C2_Mode0_SE0_Logical_CP6_C2 (5U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_AliveCounter_C3_Mode0_SE0_Alive_CP_C3 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_AliveCounter_C3_Mode0_SE1_Alive_CP_C3 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_AliveCounter_C3_Mode0_SE2_Alive_CP_C3 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_AliveCounter_C3_Mode0_SE3_Alive_CP_C3 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_AliveCounter_C3_Mode0_SE4_Alive_CP_C3 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_Deadline_C3_Mode0_SE0_Deadline_CP1_C3 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_Deadline_C3_Mode0_SE0_Deadline_CP2_C3 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_Deadline_C3_Mode0_SE1_Deadline_CP1_C3 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_Deadline_C3_Mode0_SE1_Deadline_CP2_C3 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_Deadline_C3_Mode0_SE2_Deadline_CP1_C3 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_Deadline_C3_Mode0_SE2_Deadline_CP2_C3 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_Deadline_C3_Mode0_SE3_Deadline_CP1_C3 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_Deadline_C3_Mode0_SE3_Deadline_CP2_C3 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_Deadline_C3_Mode0_SE4_Deadline_CP1_C3 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_Deadline_C3_Mode0_SE4_Deadline_CP2_C3 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C3_Mode0_SE0_Logical_CP1_C3 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C3_Mode0_SE0_Logical_CP2_C3 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C3_Mode0_SE0_Logical_CP3_C3 (2U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C3_Mode0_SE0_Logical_CP4_C3 (3U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C3_Mode0_SE0_Logical_CP5_C3 (4U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C3_Mode0_SE0_Logical_CP6_C3 (5U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_AliveCounter_C4_Mode0_SE0_Alive_CP_C4 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_AliveCounter_C4_Mode0_SE1_Alive_CP_C4 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_AliveCounter_C4_Mode0_SE2_Alive_CP_C4 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_AliveCounter_C4_Mode0_SE3_Alive_CP_C4 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_AliveCounter_C4_Mode0_SE4_Alive_CP_C4 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_Deadline_C4_Mode0_SE0_Deadline_CP1_C4 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_Deadline_C4_Mode0_SE0_Deadline_CP2_C4 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_Deadline_C4_Mode0_SE1_Deadline_CP1_C4 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_Deadline_C4_Mode0_SE1_Deadline_CP2_C4 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_Deadline_C4_Mode0_SE2_Deadline_CP1_C4 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_Deadline_C4_Mode0_SE2_Deadline_CP2_C4 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_Deadline_C4_Mode0_SE3_Deadline_CP1_C4 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_Deadline_C4_Mode0_SE3_Deadline_CP2_C4 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_Deadline_C4_Mode0_SE4_Deadline_CP1_C4 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_Deadline_C4_Mode0_SE4_Deadline_CP2_C4 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C4_Mode0_SE0_Logical_CP1_C4 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C4_Mode0_SE0_Logical_CP2_C4 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C4_Mode0_SE0_Logical_CP3_C4 (2U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C4_Mode0_SE0_Logical_CP4_C4 (3U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C4_Mode0_SE0_Logical_CP5_C4 (4U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C4_Mode0_SE0_Logical_CP6_C4 (5U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_AliveCounter_C5_Mode0_SE0_Alive_CP_C5 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_AliveCounter_C5_Mode0_SE1_Alive_CP_C5 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_AliveCounter_C5_Mode0_SE2_Alive_CP_C5 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_AliveCounter_C5_Mode0_SE3_Alive_CP_C5 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_AliveCounter_C5_Mode0_SE4_Alive_CP_C5 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_Deadline_C5_Mode0_SE0_Deadline_CP1_C5 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_Deadline_C5_Mode0_SE0_Deadline_CP2_C5 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_Deadline_C5_Mode0_SE1_Deadline_CP1_C5 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE1_Deadline_C5_Mode0_SE1_Deadline_CP2_C5 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_Deadline_C5_Mode0_SE2_Deadline_CP1_C5 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE2_Deadline_C5_Mode0_SE2_Deadline_CP2_C5 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_Deadline_C5_Mode0_SE3_Deadline_CP1_C5 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE3_Deadline_C5_Mode0_SE3_Deadline_CP2_C5 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_Deadline_C5_Mode0_SE4_Deadline_CP1_C5 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE4_Deadline_C5_Mode0_SE4_Deadline_CP2_C5 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C5_Mode0_SE0_Logical_CP1_C5 (0U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C5_Mode0_SE0_Logical_CP2_C5 (1U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C5_Mode0_SE0_Logical_CP3_C5 (2U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C5_Mode0_SE0_Logical_CP4_C5 (3U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C5_Mode0_SE0_Logical_CP5_C5 (4U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WdgM_SE0_ProgramFlow_C5_Mode0_SE0_Logical_CP6_C5 (5U)  /* PRQA S 0779 */ /* NSCA_QAC_WdgM_Rule1.3,NSCA_QAC_WdgM_Rule5.2 */
#define WDGM_WdgMMode0                      (0U)
#define FINAL_CHECKPOINTS_IN_SE0            (0U)
#define FINAL_CHECKPOINTS_IN_SE1            (0U)
#define FINAL_CHECKPOINTS_IN_SE2            (0U)
#define FINAL_CHECKPOINTS_IN_SE3            (0U)
#define FINAL_CHECKPOINTS_IN_SE4            (0U)
#define FINAL_CHECKPOINTS_IN_SE5            (1U)
#define FINAL_CHECKPOINTS_IN_SE6            (1U)
#define FINAL_CHECKPOINTS_IN_SE7            (1U)
#define FINAL_CHECKPOINTS_IN_SE8            (1U)
#define FINAL_CHECKPOINTS_IN_SE9            (1U)
#define FINAL_CHECKPOINTS_IN_SE10           (1U)
#define FINAL_CHECKPOINTS_IN_SE11           (0U)
#define FINAL_CHECKPOINTS_IN_SE12           (0U)
#define FINAL_CHECKPOINTS_IN_SE13           (0U)
#define FINAL_CHECKPOINTS_IN_SE14           (0U)
#define FINAL_CHECKPOINTS_IN_SE15           (0U)
#define FINAL_CHECKPOINTS_IN_SE16           (1U)
#define FINAL_CHECKPOINTS_IN_SE17           (1U)
#define FINAL_CHECKPOINTS_IN_SE18           (1U)
#define FINAL_CHECKPOINTS_IN_SE19           (1U)
#define FINAL_CHECKPOINTS_IN_SE20           (1U)
#define FINAL_CHECKPOINTS_IN_SE21           (1U)
#define FINAL_CHECKPOINTS_IN_SE22           (0U)
#define FINAL_CHECKPOINTS_IN_SE23           (0U)
#define FINAL_CHECKPOINTS_IN_SE24           (0U)
#define FINAL_CHECKPOINTS_IN_SE25           (0U)
#define FINAL_CHECKPOINTS_IN_SE26           (0U)
#define FINAL_CHECKPOINTS_IN_SE27           (1U)
#define FINAL_CHECKPOINTS_IN_SE28           (1U)
#define FINAL_CHECKPOINTS_IN_SE29           (1U)
#define FINAL_CHECKPOINTS_IN_SE30           (1U)
#define FINAL_CHECKPOINTS_IN_SE31           (1U)
#define FINAL_CHECKPOINTS_IN_SE32           (1U)
#define FINAL_CHECKPOINTS_IN_SE33           (0U)
#define FINAL_CHECKPOINTS_IN_SE34           (0U)
#define FINAL_CHECKPOINTS_IN_SE35           (0U)
#define FINAL_CHECKPOINTS_IN_SE36           (0U)
#define FINAL_CHECKPOINTS_IN_SE37           (0U)
#define FINAL_CHECKPOINTS_IN_SE38           (1U)
#define FINAL_CHECKPOINTS_IN_SE39           (1U)
#define FINAL_CHECKPOINTS_IN_SE40           (1U)
#define FINAL_CHECKPOINTS_IN_SE41           (1U)
#define FINAL_CHECKPOINTS_IN_SE42           (1U)
#define FINAL_CHECKPOINTS_IN_SE43           (1U)
#define FINAL_CHECKPOINTS_IN_SE44           (0U)
#define FINAL_CHECKPOINTS_IN_SE45           (0U)
#define FINAL_CHECKPOINTS_IN_SE46           (0U)
#define FINAL_CHECKPOINTS_IN_SE47           (0U)
#define FINAL_CHECKPOINTS_IN_SE48           (0U)
#define FINAL_CHECKPOINTS_IN_SE49           (1U)
#define FINAL_CHECKPOINTS_IN_SE50           (1U)
#define FINAL_CHECKPOINTS_IN_SE51           (1U)
#define FINAL_CHECKPOINTS_IN_SE52           (1U)
#define FINAL_CHECKPOINTS_IN_SE53           (1U)
#define FINAL_CHECKPOINTS_IN_SE54           (1U)
#define FINAL_CHECKPOINTS_IN_SE55           (0U)
#define FINAL_CHECKPOINTS_IN_SE56           (0U)
#define FINAL_CHECKPOINTS_IN_SE57           (0U)
#define FINAL_CHECKPOINTS_IN_SE58           (0U)
#define FINAL_CHECKPOINTS_IN_SE59           (0U)
#define FINAL_CHECKPOINTS_IN_SE60           (1U)
#define FINAL_CHECKPOINTS_IN_SE61           (1U)
#define FINAL_CHECKPOINTS_IN_SE62           (1U)
#define FINAL_CHECKPOINTS_IN_SE63           (1U)
#define FINAL_CHECKPOINTS_IN_SE64           (1U)
#define FINAL_CHECKPOINTS_IN_SE65           (1U)
#define WDGM_CORE_NUM                       (6U)
#define WDGM_SPIN_LOCK                      WDGMSPINLOCK
#define CORE0_SE_NUM                        (11U)
#define CORE1_SE_NUM                        (11U)
#define CORE2_SE_NUM                        (11U)
#define CORE3_SE_NUM                        (11U)
#define CORE4_SE_NUM                        (11U)
#define CORE5_SE_NUM                        (11U)
#define WDGM_TRIGGER_MAXNUM                 (1U)
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
#define WDGM_START_SEC_GLOBAL_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

extern P2VAR(WdgM_LocalStatusCnt,AUTOMATIC, WDGM_APPL_DATA) WdgM_LocalStatusCnt_Array[WDGM_CORE_NUM];  /* PRQA S 3447 */ /* NSCA_QAC_WdgM_Rule8.5 */


#define WDGM_STOP_SEC_GLOBAL_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define WDGM_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
extern CONSTP2CONST(WdgM_ModeStructType, WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_Mode_Ptr[WDGM_MODE_ALL_NUM + WDGM_VALUE_ONE]  /* PRQA S 3447 */ /* NSCA_QAC_WdgM_Rule8.5 */;
/* Polyspace +1 MISRA-C3:20.7 [Justified:Unset] "NSCA_Polyspace_WdgM_20.7" */
extern CONSTP2CONST( CONSTP2CONST(WdgM_SEGType, WDGM_CONFIG_DATA, WDGM_APPL_CONST), WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_SEG_Core_Ptr_Array[WDGM_CORE_NUM + WDGM_VALUE_ONE];  /* PRQA S 3447 */ /* NSCA_QAC_WdgM_Rule8.5 */
extern CONSTP2CONST(WdgM_SEGType, WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_SEG_Core0_Ptr[CORE0_SE_NUM + WDGM_VALUE_ONE];  /* PRQA S 3447 */ /* NSCA_QAC_WdgM_Rule8.5 */
extern CONSTP2CONST(WdgM_SEGType, WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_SEG_Core1_Ptr[CORE1_SE_NUM + WDGM_VALUE_ONE];  /* PRQA S 3447 */ /* NSCA_QAC_WdgM_Rule8.5 */
extern CONSTP2CONST(WdgM_SEGType, WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_SEG_Core2_Ptr[CORE2_SE_NUM + WDGM_VALUE_ONE];  /* PRQA S 3447 */ /* NSCA_QAC_WdgM_Rule8.5 */
extern CONSTP2CONST(WdgM_SEGType, WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_SEG_Core3_Ptr[CORE3_SE_NUM + WDGM_VALUE_ONE];  /* PRQA S 3447 */ /* NSCA_QAC_WdgM_Rule8.5 */
extern CONSTP2CONST(WdgM_SEGType, WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_SEG_Core4_Ptr[CORE4_SE_NUM + WDGM_VALUE_ONE];  /* PRQA S 3447 */ /* NSCA_QAC_WdgM_Rule8.5 */
extern CONSTP2CONST(WdgM_SEGType, WDGM_CONFIG_DATA, WDGM_APPL_CONST) WdgM_SEG_Core5_Ptr[CORE5_SE_NUM + WDGM_VALUE_ONE];  /* PRQA S 3447 */ /* NSCA_QAC_WdgM_Rule8.5 */
extern CONST(WdgM_SENumType, WDGM_CONFIG_DATA) SENumInCore[WDGM_CORE_NUM];  /* PRQA S 3447 */ /* NSCA_QAC_WdgM_Rule8.5 */
#define WDGM_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
#define WDGM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */



#define WDGM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "WdgM_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif /* WDGM_LCFG_H_ */


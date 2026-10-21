/*
********************************************************************************
*
* File name: NeuLib_Def.h
*
* Copyright 2023-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: ZhangDX/2023.08.01
* Change: New
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: TianG/2024.10.12
* Change: Modify copyright.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: KangJH/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: KangJH/2025.05.22
* Change: Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
* Cause: Update
********************************************************************************
*/
#ifndef NEU_DEF_H_
#define NEU_DEF_H_

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/*
********************************************************************************
*    Includes
********************************************************************************
*/
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule20.1" */
#include "Std_Types.h"
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule20.1" */
#include "NeuLib_Cfg.h"
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule20.1" */
#include "SchM_NeuLib.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Used for initialization. */
#define NEULIB_INIT_0                           0U

/* Used for shift. */
#define NEULIB_SHIFT_0                          0U
#define NEULIB_SHIFT_1                          1U
#define NEULIB_SHIFT_2                          2U
#define NEULIB_SHIFT_3                          3U
#define NEULIB_SHIFT_4                          4U
#define NEULIB_SHIFT_8                          8U
#define NEULIB_SHIFT_16                         16U
#define NEULIB_SHIFT_24                         24U

/* Used for count. */
#define NEULIB_CNT_0                            0U
#define NEULIB_CNT_1                            1U
#define NEULIB_CNT_2                            2U
#define NEULIB_CNT_3                            3U
#define NEULIB_CNT_4                            4U
#define NEULIB_CNT_5                            5U
#define NEULIB_CNT_6                            6U
#define NEULIB_CNT_7                            7U
#define NEULIB_CNT_8                            8U
#define NEULIB_CNT_9                            9U
#define NEULIB_CNT_10                           10U
#define NEULIB_CNT_11                           11U
#define NEULIB_CNT_12                           12U
#define NEULIB_CNT_13                           13U
#define NEULIB_CNT_14                           14U
#define NEULIB_CNT_15                           15U
#define NEULIB_CNT_16                           16U
#define NEULIB_CNT_17                           17U
#define NEULIB_CNT_18                           18U
#define NEULIB_CNT_19                           19U
#define NEULIB_CNT_20                           20U
#define NEULIB_CNT_21                           21U
#define NEULIB_CNT_22                           22U
#define NEULIB_CNT_23                           23U
#define NEULIB_CNT_24                           24U
#define NEULIB_CNT_25                           25U
#define NEULIB_CNT_26                           26U
#define NEULIB_CNT_27                           27U
#define NEULIB_CNT_28                           28U
#define NEULIB_CNT_29                           29U
#define NEULIB_CNT_30                           30U
#define NEULIB_CNT_31                           31U
#define NEULIB_CNT_32                           32U

/* The index used for the array. */
#define NEULIB_IDX_0                            0U
#define NEULIB_IDX_1                            1U
#define NEULIB_IDX_2                            2U
#define NEULIB_IDX_3                            3U
#define NEULIB_IDX_4                            4U
#define NEULIB_IDX_5                            5U
#define NEULIB_IDX_6                            6U
#define NEULIB_IDX_7                            7U
#define NEULIB_IDX_8                            8U
#define NEULIB_IDX_9                            9U
#define NEULIB_IDX_10                           10U
#define NEULIB_IDX_11                           11U
#define NEULIB_IDX_12                           12U
#define NEULIB_IDX_13                           13U
#define NEULIB_IDX_14                           14U
#define NEULIB_IDX_15                           15U
#define NEULIB_IDX_16                           16U
#define NEULIB_IDX_17                           17U
#define NEULIB_IDX_18                           18U
#define NEULIB_IDX_19                           19U
#define NEULIB_IDX_20                           20U
#define NEULIB_IDX_21                           21U
#define NEULIB_IDX_22                           22U
#define NEULIB_IDX_23                           23U
#define NEULIB_IDX_24                           24U
#define NEULIB_IDX_25                           25U
#define NEULIB_IDX_26                           26U
#define NEULIB_IDX_27                           27U
#define NEULIB_IDX_28                           28U
#define NEULIB_IDX_29                           29U
#define NEULIB_IDX_30                           30U

#define NEULIB_E_OK                            (E_OK)
#define NEULIB_NOT_OK                          (E_NOT_OK)

/* Used for size or length. */
#define NEULIB_SIZE_0                           0U

/* Critical section entry and exit operations are predefined. */
#ifndef NEULIB_SYS_ARCH_DECL_PROTECT
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define NEULIB_SYS_ARCH_DECL_PROTECT(lev)
#endif  /* NEULIB_SYS_ARCH_DECL_PROTECT */

#ifndef NEULIB_SYS_ARCH_PROTECT
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define NEULIB_SYS_ARCH_PROTECT(lev)            SchM_Enter_NeuLib_NEULIB_EXCLUSIVE_AREA_0()
#endif  /* NEULIB_SYS_ARCH_PROTECT */

#ifndef NEULIB_SYS_ARCH_UNPROTECT
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define NEULIB_SYS_ARCH_UNPROTECT(lev)          SchM_Exit_NeuLib_NEULIB_EXCLUSIVE_AREA_0()
#endif  /* NEULIB_SYS_ARCH_UNPROTECT */

#ifndef NEULIB_ARRAY_SIZE
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define NEULIB_ARRAY_SIZE(_array)               (sizeof(_array) / sizeof(_array[0]))  /* PRQA S 3410 */ /* NSCA_QAC_NeuLib_Rule20.7 */
#endif
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef uint32        NeuLibTick_Type;  /*!< Type for tick count.  */
/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef unsigned long NeuSize_Type;     /*!< Type for size number. */

/* Double List structure. */
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.8" */
struct NeuLibListNode
{
    struct NeuLibListNode *next;        /*!< point to next node. */
    struct NeuLibListNode *prev;        /*!< point to prev node. */
};
typedef struct NeuLibListNode NeuLibList_Type;  /*!< Type for lists. */

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

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* #ifndef NEU_DEF_H_ */

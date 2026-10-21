/*
********************************************************************************
*
* File name: NeuLib_Cfg.h
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
* Author/Date: KangJH/2025.03.28
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: KangJH/2025.05.22
* Change: Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: KangJH/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef NEULIB_CFG_H_
#define NEULIB_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/*
********************************************************************************
*    Includes
********************************************************************************
*/
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/**
 * If the Default Error Tracer (Det) shall be used, this parameter shall be set
 * to TRUE. Otherwise, it shall be set to FALSE.
 */
#define NEULIB_DEV_ERROR_DETECT             (STD_OFF)
#define NEULIB_MEMP_OVERFLOW_CHECK          (STD_OFF)
#define NEULIB_MEMP_STATS_ENABLED           (STD_OFF)
#define NEU_MEM_OVERFLOW_CHECK              (STD_OFF)
/* Choose whether to enable memory optimization. */
/* polyspace +1 MISRA-C3:12.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule12.1" */
#if (CPU_TYPE == CPU_TYPE_32 || CPU_TYPE == CPU_TYPE_64)
#define NEULIB_MEM_OPERATION_OPTIMIZATION   (STD_ON)
#else   /* (CPU_TYPE == CPU_TYPE_32 || CPU_TYPE == CPU_TYPE_64) */
#define NEULIB_MEM_OPERATION_OPTIMIZATION   (STD_OFF)
#endif  /* (CPU_TYPE == CPU_TYPE_32 || CPU_TYPE == CPU_TYPE_64) */

/* Eliminates compiler warning about unused arguments (GCC -Wextra -Wunused). */
/* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define NEU_UNUSED_ARG(x)                   ((x) = (x))

#ifdef NEU_DEBUG
#define FLS     "Fls"
#define FLSAC   "FlsAc"
#define ERROR   "Error"

    #if ELOG_ENABLED
    #define NEULIB_DEBUG_LOG(_tag, _info, ...)                                          \
            do                                                                          \
            {                                                                           \
                elog_debug(_tag, _info, ##__VA_ARGS__);                                 \
            } while (0U)
    /* NeuLib asserts and prints a message. */
    #define NEULIB_ASSERT_MSG(_tag, _message, _expression)                              \
            do                                                                          \
            {                                                                           \
                if (!(_expression))                                                     \
                {                                                                       \
                    elog_assert(_tag,_message);                                         \
                    while (1);                                                          \
                }                                                                       \
            } while (0U)
    #define NEULIB_ASSERT(_message, _assertion)                                         \
        do                                                                              \
        {                                                                               \
            if (!(_assertion))                                                          \
            {                                                                           \
                elog_assert("Assertion \"%s\" failed at line %d in %s\n", _message);    \
                abort();                                                                \
            }                                                                           \
        } while (0)

    #else   /* ELOG_ENABLED */
    /* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule20.1" */
    #include "stdio.h"
    #define NEULIB_DEBUG_LOG(_tag, _info, ...)                                          \
            do                                                                          \
            {                                                                           \
                printf(_tag, ":");                                                      \
                printf(_info, ##__VA_ARGS__);                                           \
            } while (0U)
    /* NeuLib asserts and prints a message. */
    #define NEULIB_ASSERT_MSG(_tag, _message, _expression)                              \
            do                                                                          \
            {                                                                           \
                if (!(_expression))                                                     \
                {                                                                       \
                    printf(_tag, ":");                                                  \
                    printf(_message);                                                   \
                    while (1);                                                          \
                }                                                                       \
            } while (0U)
    #define NEULIB_ASSERT(_message, _assertion)                                         \
        do                                                                              \
        {                                                                               \
            if (!(_assertion))                                                          \
            {                                                                           \
                printf("Assertion \"%s\" failed at line %d in %s\n", _message);         \
                abort();                                                                \
            }                                                                           \
        } while (0)
    #endif  /* ELOG_ENABLED */
#else   /* NEU_DEBUG */

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define FLS
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define MAIN_NEULIB
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define FLSAC
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define ERROR

/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define NEULIB_DEBUG_LOG(_tag, _info, ...)
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define NEULIB_ASSERT(_message, _assertion)
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define NEULIB_ASSERT_MSG(_tag, _message, _expression)
#endif  /* NEU_DEBUG */
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define NEULIB_DUMMY_STATEMENT(v)              ((v)=(v))


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

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* NEULIB_CFG_H_ */

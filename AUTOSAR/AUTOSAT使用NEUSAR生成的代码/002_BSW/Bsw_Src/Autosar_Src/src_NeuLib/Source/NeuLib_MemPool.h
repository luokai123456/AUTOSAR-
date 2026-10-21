/*
********************************************************************************
*
* File name: NeuLib_MemPool.h
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
* Change: 1.Modify copyright.
*         2.Modify FUNC_P2VAR error.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: KangJH/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: KangJH/2025.03.28
* Change: Fix some QAC warnings and remove comments.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: KangJH/2025.05.22
* Change: Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
* Cause: Update
********************************************************************************
*/
#ifndef NEU_MEM_POOL_H_
#define NEU_MEM_POOL_H_

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
#include "stddef.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/**
 * NEULIB_MEM_ALIGNMENT: should be set to the alignment of the CPU for which NEU is compiled. 4 byte alignmentdefine NEULIB_MEM_ALIGNMENT to 4, 2 byte alignmentdefine NEULIB_MEM_ALIGNMENT to 2.
 */
#ifndef NEULIB_MEM_ALIGNMENT
    #if (CPU_TYPE == CPU_TYPE_64)
        #define NEULIB_MEM_ALIGNMENT                8U
    #elif (CPU_TYPE == CPU_TYPE_32)
        #define NEULIB_MEM_ALIGNMENT                4U
    #elif  (CPU_TYPE == CPU_TYPE_16)
        #define NEULIB_MEM_ALIGNMENT                2U
    #elif  (CPU_TYPE == CPU_TYPE_8)
        #define NEULIB_MEM_ALIGNMENT                1U
    #else   /* (CPU_TYPE == CPU_TYPE_64) */
        #define NEULIB_MEM_ALIGNMENT                4U
    #endif  /* (CPU_TYPE == CPU_TYPE_64) */
#endif  /* NEULIB_MEM_ALIGNMENT */

#if (NEULIB_MEMP_OVERFLOW_CHECK == STD_ON)
/** C++ const_cast<target_type>(val) equivalent to remove constness from a value (GCC -Wcast-qual). */
#define NEULIB_CONST_CAST(_targetType, val)         ((_targetType)((ptrdiff_t)val))
/** Get rid of alignment cast warnings (GCC -Wcast-align). */
#define NEULIB_ALIGNMENT_CAST(_targetType, val)     NEULIB_CONST_CAST(_targetType, val)
#endif  /* NEULIB_MEMP_OVERFLOW_CHECK == STD_ON */

/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* polyspace-begin MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
/* Align a memory pointer to the alignment defined by 4u so that ADDR % 4u == 0. */
/* polyspace +1 MISRA-C3:11.6 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" polyspace +1 MISRA-C3:11.4 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
#define NEULIB_MEM_ALIGN(_addr)                     \
        ((void *)(((NeuLibMemPtr_Type)(_addr) + (NEULIB_MEM_ALIGNMENT - 1U)) & ~(NeuLibMemPtr_Type)(NEULIB_MEM_ALIGNMENT - 1U)))

/**
 * Calculate memory _size for an aligned buffer - returns the next highest
 * multiple of NEULIB_MEM_ALIGNMENT (e.g. NEULIB_MEM_ALIGN_SIZE(3) and
 * NEULIB_MEM_ALIGN_SIZE(4) will both yield 4 for NEULIB_MEM_ALIGNMENT == 4).
 */
#define NEULIB_MEM_ALIGN_SIZE(_size)                (((_size) + (NEULIB_MEM_ALIGNMENT - 1U)) & ~(NEULIB_MEM_ALIGNMENT - 1U))

#if (NEU_MEM_OVERFLOW_CHECK || NEULIB_MEMP_OVERFLOW_CHECK)
#define NEULIB_MEM_SANITY_VALUE                     0xCD
/**
 * If NEU_MEM_OVERFLOW_CHECK or NEULIB_MEMP_OVERFLOW_CHECK is turned on, we reserve some
 * bytes at the beginning and at the end of each element, initialize them as 0xcd and check them later.
 *
 * If NEULIB_MEMP_OVERFLOW_CHECK is >= 2, on every call to NeuMemp_malloc or NeuMemp_free,
 * every single element in each pool/heap is checked!
 * This is VERY SLOW but also very helpful.
 */
#define NEU_MEM_SANITY_REGION_BEFORE_ALIGNED        NEULIB_MEM_ALIGN_SIZE(16U)
#define NEU_MEM_SANITY_REGION_AFTER_ALIGNED         NEULIB_MEM_ALIGN_SIZE(16U)

#endif  /* (NEU_MEM_OVERFLOW_CHECK || NEULIB_MEMP_OVERFLOW_CHECK) */

/**
 * Calculate safe memory _size for an aligned buffer when using an unaligned
 * type as storage. This includes a safety-margin on (NEULIB_MEM_ALIGNMENT - 1) at the
 * start (e.g. if buffer is uint8[] and actual data will be uint32*)
 */
#define NEULIB_MEM_ALIGPBUFFER(_size)               ((_size) + NEULIB_MEM_ALIGNMENT - 1U)

#ifdef NEULIB_MEM_STATS_ENABLED
/* MD_MSR_Rule20.10_0342 */
#define NEULIB_MEMPOOL_DECLARE_STATS_INSTANCE(_moduleName, _name)     static VAR(NeuLibMemPoolStats_Type, _moduleName##_VAR_NO_INIT) _name;
#define NEULIB_MEMPOOL_DECLARE_STATS_REFERENCE(_moduleName, _name)    &_name,
#else   /* NEULIB_MEM_STATS_ENABLED */
#define NEULIB_MEMPOOL_DECLARE_STATS_INSTANCE(_moduleName, _name)
#define NEULIB_MEMPOOL_DECLARE_STATS_REFERENCE(_moduleName, _name)
#endif  /* NEULIB_MEM_STATS_ENABLED */

/**
 * Declare a private memory pool
 * Private mempools example:
 *
 * #define DET_START_SEC_VAR_NO_INIT
 * #include "Det_MemMap.h"
 *
 * NEULIB_MEM_POOL_DEF_VAR(DET, Det, 2, 2);
 *
 * #define DET_STOP_SEC_VAR_NO_INIT
 * #include "Det_MemMap.h"
 *
 * #define DET_START_SEC_CONST
 * #include "Det_MemMap.h"
 *
 * NEULIB_MEM_POOL_DEF_CONST(DET, Det, 2, 2);
 *
 * #define DET_STOP_SEC_CONST
 * #include "Det_MemMap.h"
 */
/* polyspace-begin MISRA-C3:20.10 [Justified:Unset] "NSCA_Polyspace_Common_Rule20.10" */
/* MD_MSR_Rule20.10_0342 */
#define NEULIB_MEM_POOL_DEF_VAR(_moduleName, _name, _num, _size)                                                                                    \
        static VAR(uint8, _moduleName##_VAR_NO_INIT) NeuMemp_Memory_##_name##_base[NEULIB_MEM_ALIGPBUFFER((_num) * NEULIB_MEM_ALIGN_SIZE(_size))];  \
        NEULIB_MEMPOOL_DECLARE_STATS_INSTANCE(_moduleName, NeuMemp_Stats_##_name)                                                                   \
        static P2VAR(NeuLibMemPool_Type, _moduleName##_VAR_NO_INIT, _moduleName##_APPL_DATA) NeuMemp_Tab_##_name;  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */

/* MD_MSR_Rule20.10_0342 */
#define NEULIB_MEM_POOL_DEF_CONST(_moduleName, _name, _num, _size)                              \
            static CONST(NeuLibMemPoolDesc_Type, _moduleName##_CONST) NeuMemp_##_name = {       \
                    (_num),                                                                     \
                    NEULIB_MEM_ALIGN_SIZE(_size),                                               \
                    NEULIB_MEMPOOL_DECLARE_STATS_REFERENCE(_moduleName, NeuMemp_Stats_##_name)  \
                    NeuMemp_Memory_##_name##_base,                                              \
                    &NeuMemp_Tab_##_name                                                        \
            }  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */

/* MD_MSR_Rule20.10_0342 */
#define NEU_NeuLibMemPool_Init(_name)       NeuLibMemPool_Init(&NeuMemp_##_name)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
/* MD_MSR_Rule20.10_0342 */
#define NEU_NeuLibMemPool_Malloc(_name)     NeuLibMemPool_Malloc(&NeuMemp_##_name)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
/* MD_MSR_Rule20.10_0342 */
#define NEU_NeuLibMemPool_Free(_name, _mem) NeuLibMemPool_Free(&NeuMemp_##_name, _mem)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
/* polyspace-end MISRA-C3:20.10 [Justified:Unset] "NSCA_Polyspace_Common_Rule20.10" */
/* polyspace-end MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef unsigned int  NeuLibMemPtr_Type;
typedef unsigned long NeuLibMemPoolSize_Type;

/* Memory stats. */
struct NeuLibMemPoolStats
{
    uint32 err;
    uint32 illegal;
    NeuLibMemPoolSize_Type avail;
    NeuLibMemPoolSize_Type used;
    NeuLibMemPoolSize_Type max;
};
/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct NeuLibMemPoolStats NeuLibMemPoolStats_Type;

/* Buffer pool data structure. */
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.8" */
struct NeuLibMemPool_tag
{
    struct NeuLibMemPool_tag* next;
#if (NEULIB_MEMP_OVERFLOW_CHECK == STD_ON)
    const sint8* file;
    uint32 line;
#endif  /* NEULIB_MEMP_OVERFLOW_CHECK == STD_ON */
};
typedef struct NeuLibMemPool_tag NeuLibMemPool_Type;

/* Memory pool descriptor. */
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.8" */
struct NeuLibMemPoolpDesc
{
    uint16                  num;    /*!< Number of elements                                            */
    uint16                  size;   /*!< Element size                                                  */
#if (NEULIB_MEMP_STATS_ENABLED == STD_ON)
    NeuLibMemPoolStats_Type stats;  /*!< Statistics                                                    */
#endif  /* (NEULIB_MEMP_STATS_ENABLED == STD_ON) */
    uint8                   *base;  /*!< Base address                                                  */
    NeuLibMemPool_Type      **tab;  /*!< First free element of each pool. Elements form a linked list. */

};
typedef struct NeuLibMemPoolpDesc NeuLibMemPoolDesc_Type;

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
#define NEULIB_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

FUNC(void, NEULIB_CODE) NeuLibMemPool_Init(
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC_P2VAR(void, NEULIB_APPL_DATA, NEULIB_CODE) NeuLibMemPool_Malloc(
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(void, NEULIB_CODE) NeuLibMemPool_Free(
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc,
    P2VAR(void, AUTOMATIC, NEULIB_APPL_DATA) mem
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* NEU_MEM_POOL_H_ */

/*
********************************************************************************
*
* File name: NeuLib_MemPool.c
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
* Change: 1.Add a memory-map label to function.
*         2.Modify memory-map label error.
*         3.Modify copyright.
*         4.Modify FUNC_P2VAR error.
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
* Version: 3.5
* Author/Date: KangJH/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: KangJH/2025.06.18
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#include "NeuLib_MemPool.h"
#include "NeuLib_Def.h"
#include "NeuLib.h"

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
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_START_SEC_CONST
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_STOP_SEC_CONST
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"

/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
#define NEULIB_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"
#if (NEULIB_MEMP_OVERFLOW_CHECK == STD_ON)
static FUNC(void, NEULIB_CODE) NeuMemP_OverflowCheckElement(
    P2VAR(NeuLibMemPool_Type, AUTOMATIC, NEULIB_APPL_DATA) p,
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc
);
static FUNC(void, NEULIB_CODE) NeuMemP_OverflowInitElement(
    P2VAR(NeuLibMemPool_Type, AUTOMATIC, NEULIB_APPL_DATA) p,
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc
);
static FUNC(void, NEULIB_CODE) NeuMemP_OverflowCheckAll(
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc
);
#endif  /* NEULIB_MEMP_OVERFLOW_CHECK == STD_ON */
#define NEULIB_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define NEULIB_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if (NEULIB_MEMP_OVERFLOW_CHECK == STD_ON)
/*
********************************************************************************
* Function Name: NeuMemP_OverflowCheckElement
*
* Explanation:   Check if a memp element was victim of an overflow or underflow
*                (e.g. the restricted area after/before it has been altered).
* (Synchronous)
*
* param:         p    The memp element to check.
*                desc The pool p comes from.
*
* retval:        None
********************************************************************************
*/
static FUNC(void, NEULIB_CODE) NeuMemP_OverflowCheckElement(
    P2VAR(NeuLibMemPool_Type, AUTOMATIC, NEULIB_APPL_DATA) p,
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc
)
{
#if (NEU_MEM_SANITY_REGION_AFTER_ALIGNED || NEU_MEM_SANITY_REGION_BEFORE_ALIGNED)
    uint16 k;
    uint8 *m;

#if (NEU_MEM_SANITY_REGION_AFTER_ALIGNED > 0)
    m = (uint8*)p + desc->size;
    for (k = 0; k < NEU_MEM_SANITY_REGION_AFTER_ALIGNED; k++)
    {
        NEULIB_ASSERT_MSG("NeuLibMemPool_Assert", "pool", m[k] == NEULIB_MEM_SANITY_VALUE);
    }
#endif  /* (NEU_MEM_SANITY_REGION_AFTER_ALIGNED > 0) */

#if (NEU_MEM_SANITY_REGION_BEFORE_ALIGNED > 0)
    m = (uint8*)p - NEU_MEM_SANITY_REGION_BEFORE_ALIGNED;
    for (k = 0; k < NEU_MEM_SANITY_REGION_BEFORE_ALIGNED; k++)
    {
        NEULIB_ASSERT_MSG("NeuLibMemPool_Assert", "pool", m[k] == NEULIB_MEM_SANITY_VALUE);
    }
#endif  /* (NEU_MEM_SANITY_REGION_BEFORE_ALIGNED > 0) */

#else   /* (NEU_MEM_SANITY_REGION_AFTER_ALIGNED || NEU_MEM_SANITY_REGION_BEFORE_ALIGNED) */
    NEU_UNUSED_ARG(p);
    NEU_UNUSED_ARG(desc);
    NEU_UNUSED_ARG(descr);
#endif  /* (NEU_MEM_SANITY_REGION_AFTER_ALIGNED || NEU_MEM_SANITY_REGION_BEFORE_ALIGNED) */
}

/*
********************************************************************************
* Function Name: NeuMemP_OverflowInitElement
*
* Explanation:   Initialize the restricted area of on memp element.
* (Synchronous)
*
* param:         p    The memp element to check.
*                desc The pool p comes from.
*
* retval:        None
********************************************************************************
*/
static FUNC(void, NEULIB_CODE) NeuMemP_OverflowInitElement(
    P2VAR(NeuLibMemPool_Type, AUTOMATIC, NEULIB_APPL_DATA) p,
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc
)
{
#if (NEU_MEM_SANITY_REGION_BEFORE_ALIGNED > 0 || NEU_MEM_SANITY_REGION_AFTER_ALIGNED > 0)
    uint8 *m;
#if (NEU_MEM_SANITY_REGION_BEFORE_ALIGNED > 0)
    m = (uint8*)p - NEU_MEM_SANITY_REGION_BEFORE_ALIGNED;
    NeuLib_memset(m, NEULIB_MEM_SANITY_VALUE, NEU_MEM_SANITY_REGION_BEFORE_ALIGNED);
#endif  /* (NEU_MEM_SANITY_REGION_BEFORE_ALIGNED > 0) */

#if (NEU_MEM_SANITY_REGION_AFTER_ALIGNED > 0)
    m = (uint8*)p + desc->size;
    NeuLib_memset(m, NEULIB_MEM_SANITY_VALUE, NEU_MEM_SANITY_REGION_AFTER_ALIGNED);
#endif  /* (NEU_MEM_SANITY_REGION_AFTER_ALIGNED > 0) */

#else   /* (NEU_MEM_SANITY_REGION_BEFORE_ALIGNED > 0 || NEU_MEM_SANITY_REGION_AFTER_ALIGNED > 0) */
    NEU_UNUSED_ARG(p);
    NEU_UNUSED_ARG(desc);
#endif  /* (NEU_MEM_SANITY_REGION_BEFORE_ALIGNED > 0 || NEU_MEM_SANITY_REGION_AFTER_ALIGNED > 0) */
}

/*
********************************************************************************
* Function Name: NeuMemP_OverflowCheckAll
*
* Explanation:   Do an overflow check for all elements in every pool.
* (Synchronous)
*
* param:         desc The pool p comes from.
*
* retval:        None
********************************************************************************
*/
static FUNC(void, NEULIB_CODE) NeuMemP_OverflowCheckAll(
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc
)
{
    uint16 idx;
    NeuLibMemPool_Type *p;

    NEULIB_SYS_ARCH_DECL_PROTECT(old_level);
    NEULIB_SYS_ARCH_PROTECT(old_level);

    p = (NeuLibMemPool_Type *)NEULIB_MEM_ALIGN(desc->base);
    for (idx = 0; idx < desc->num; ++idx)
    {
        NeuMemP_OverflowCheckElement(p, desc);
        p = NEULIB_ALIGNMENT_CAST(NeuLibMemPool_Type *, ((uint8 *)p + desc->size + NEU_MEM_SANITY_REGION_AFTER_ALIGNED));
    }
    NEULIB_SYS_ARCH_UNPROTECT(old_level);
}
#endif  /* NEULIB_MEMP_OVERFLOW_CHECK == STD_ON */

/*
********************************************************************************
* Function Name: NeuLibMemPool_Init
*
* Explanation:   Carves out memp_memory into linked lists for each pool-type.
* (Synchronous)
*
* param:         desc Memory pool descriptor.
*
* retval:        None
********************************************************************************
*/
FUNC(void, NEULIB_CODE) NeuLibMemPool_Init(
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc
)
{
    uint16 idx;
    NeuLibMemPool_Type *memp;

    NEULIB_ASSERT_MSG("NeuLibMemPool_Assert", "NeuLibMemPoolPool_Malloc: The type range is incorrect.", desc != NULL_PTR);
    /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
    *desc->tab = NULL_PTR;
    /* polyspace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
    memp = (NeuLibMemPool_Type*)NEULIB_MEM_ALIGN(desc->base);  /* PRQA S 0316, 0306 */ /* NSCA_QAC_NeuLib_Rule11.5, NSCA_QAC_NeuLib_PointerCast */

    /* Create a linked list of memp elements. */
    for (idx = 0u; idx < desc->num; ++idx)
    {
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        memp->next = *desc->tab;
        *desc->tab = memp;
#if (NEULIB_MEMP_OVERFLOW_CHECK == STD_ON)
        NeuMemP_OverflowInitElement(memp, desc);
#endif  /* NEULIB_MEMP_OVERFLOW_CHECK == STD_ON */

        /* Cast through void* to get rid of alignment warnings. */
        /* polyspace +1 MISRA-C3:18.4 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerArithmetic" polyspace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
        memp = (NeuLibMemPool_Type *)(void *)(uint8*)(memp + desc->size  /* PRQA S 0316, 0310, 0488 */ /* NSCA_QAC_NeuLib_Rule11.5, NSCA_QAC_NeuLib_Rule11.3, NSCA_QAC_NeuLib_Rule18.4 */

#if (NEULIB_MEMP_OVERFLOW_CHECK == STD_ON)
        + NEU_MEM_SANITY_REGION_BEFORE_ALIGNED
#endif  /* NEULIB_MEMP_OVERFLOW_CHECK == STD_ON */
        );
    }
#if (NEULIB_MEMP_STATS_ENABLED == STD_ON)
    desc->stats.avail = desc->num;
#endif  /* (NEULIB_MEMP_STATS_ENABLED == STD_ON) */

#if (NEULIB_MEMP_OVERFLOW_CHECK == STD_ON)
    /* Check everything a first time to see if it worked. */
    NeuMemP_OverflowCheckAll(desc);
#endif  /* NEULIB_MEMP_OVERFLOW_CHECK == STD_ON */
}

/*
********************************************************************************
* Function Name: NeuLibMemPool_Malloc
*
* Explanation:   Get an element from a specific pool.
* (Synchronous)
*
* param:         desc Memory pool descriptor.
*
* retval:        A pointer to the allocated memory or a NULL_PTR pointer on funErr.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:15.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule15.5" */
FUNC_P2VAR(void, NEULIB_APPL_DATA, NEULIB_CODE) NeuLibMemPool_Malloc(
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc
)
{
    NeuLibMemPool_Type *memp;

    NEULIB_ASSERT_MSG("NeuLibMemPool_Assert", "NeuLibMemPoolPool_Malloc: The type range is incorrect.", desc != NULL_PTR);

#if (NEULIB_MEMP_OVERFLOW_CHECK == STD_ON)
    NeuMemP_OverflowCheckAll(desc);
#endif  /* NEULIB_MEMP_OVERFLOW_CHECK == STD_ON */

    NEULIB_SYS_ARCH_DECL_PROTECT(oldLevel);
    NEULIB_SYS_ARCH_PROTECT(oldLevel);
    /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
    memp = *desc->tab;
    if (memp != NULL_PTR)
    {
        *desc->tab = memp->next;
        /* memp properly aligned? */
        NEULIB_ASSERT_MSG("NeuLibMemPool_Assert", "NeuLibMemPoolPool_Malloc: memp properly aligned", ((NeuLibMemPtr_Type)memp % NEULIB_MEM_ALIGNMENT) == 0u);

#if (NEULIB_MEMP_STATS_ENABLED == STD_ON)
        desc->stats.used++;
        if (desc->stats.used > desc->stats.max)
        {
            desc->stats.max = desc->stats.used;
        }
#endif  /* (NEULIB_MEMP_STATS_ENABLED == STD_ON) */

        NEULIB_SYS_ARCH_UNPROTECT(oldLevel);
        /* cast through uint8* to get rid of alignment warnings */
        return (void*)memp;
    }
    else
    {
#if (NEULIB_MEMP_STATS_ENABLED == STD_ON)
        desc->stats.err++;
#endif  /* (NEULIB_MEMP_STATS_ENABLED == STD_ON) */
        NEULIB_SYS_ARCH_UNPROTECT(oldLevel);
    }

    return NULL_PTR;
}

/*
********************************************************************************
* Function Name: NeuLibMemPool_Free
*
* Explanation:   Put an element back into its pool.
* (Synchronous)
*
* param:         desc Memory pool descriptor.
*                mem  The memp element to free.
*
* retval:        None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:15.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule15.5" */
FUNC(void, NEULIB_CODE) NeuLibMemPool_Free(
    P2CONST(NeuLibMemPoolDesc_Type, AUTOMATIC, NEULIB_APPL_CONST) desc,
    P2VAR(void, AUTOMATIC, NEULIB_APPL_DATA) mem
)
{
    NeuLibMemPool_Type *memp;

    NEULIB_ASSERT_MSG("NeuLibMemPool_Assert", "NeuLibMemPoolPool_Malloc: The type range is incorrect.", desc != NULL_PTR);
    if (mem == NULL_PTR)
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        return;
    }

#if (NEULIB_MEMP_OVERFLOW_CHECK == STD_ON)
    NeuMemP_OverflowCheckAll(desc);
#endif  /* NEULIB_MEMP_OVERFLOW_CHECK == STD_ON */

        NEULIB_SYS_ARCH_DECL_PROTECT(oldLevel);

        NEULIB_ASSERT_MSG("NeuLibMemPool_Assert", "Buffer length is not aligned.", ((NeuLibMemPtr_Type)mem % NEULIB_MEM_ALIGNMENT) == 0);

        /* Cast through void* to get rid of alignment warnings. */
        /* polyspace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
        memp = (NeuLibMemPool_Type*)mem;  /* PRQA S 0316 */ /* NSCA_QAC_NeuLib_Rule11.5 */

        NEULIB_SYS_ARCH_PROTECT(oldLevel);

#if (NEULIB_MEMP_STATS_ENABLED == STD_ON)
        desc->stats.used--;
#endif  /* (NEULIB_MEMP_STATS_ENABLED == STD_ON) */

        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_NeuLib_UninitializedPointer" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        memp->next = *desc->tab;
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        *desc->tab = memp;

    NEULIB_SYS_ARCH_UNPROTECT(oldLevel);
}

#define NEULIB_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

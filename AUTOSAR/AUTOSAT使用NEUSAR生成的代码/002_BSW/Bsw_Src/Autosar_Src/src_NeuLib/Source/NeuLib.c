/*
********************************************************************************
*
* File name: NeuLib.c
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
* Author/Date: KangJH/2024.08.07
* Change: Add NeuLib_memcpy32 function.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: KangJH/2024.09.03
* Change: Remove the unused local variable "remSize" from the
*         "NeuLib_memcpy32" function.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: TianG/2024.10.12
* Change: 1.Add a memory-map label to function.
*         2.Modify copyright.
*         3.Modify FUNC_P2VAR error.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: KangJH/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: KangJH/2025.05.22
* Change: Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: KangJH/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: KangJH/2025.06.23
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#include "NeuLib.h"
#include "NeuLib_Def.h"

#if (NEULIB_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif  /* (NEULIB_DEV_ERROR_DETECT == STD_ON) */

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
#if (NEULIB_MEM_OPERATION_OPTIMIZATION == STD_ON)
#define MEM_24_BIT_DISPLACEMENT             3U
#define MEM_16_BIT_DISPLACEMENT             2U
#define NEULIB_MEMCOPY_16_BYTE              16U
#define NEULIB_MEMCOPY_32_BYTE              32U

/* Used to mask internal parameters to ensure an upper limit of 3, respectively 31. */
#define NEULIB_MEMCOPY_MASK_3               0x03U
#define NEULIB_MEMCOPY_MASK_31              0x1FU

/* Return the number of bytes that are missing to the next 32-bit boundary */
/* polyspace +1 MISRA-C3:11.6 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule10.3" polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define MEM_ALIGN_OFFSET(ptr)               (uint8_least)((4U - (uint32_least)(ptr)) & NEULIB_MEMCOPY_MASK_3)

#endif  /* (NEULIB_MEM_OPERATION_OPTIMIZATION == STD_ON) */

#ifndef __has_cpp_attribute
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" polyspace +1 MISRA-C3:21.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule21.1" */
#define __has_cpp_attribute(x)  0U  /* PRQA S 0602 */ /* NSCA_QAC_NeuLib_ReservedIdentifier */
#endif  /* __has_cpp_attribute */

#ifndef __has_c_attribute
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" polyspace +1 MISRA-C3:21.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule21.1" */
#define __has_c_attribute(x)    0U  /* PRQA S 0602 */ /* NSCA_QAC_NeuLib_ReservedIdentifier */
#endif  /* __has_c_attribute */

#ifndef __has_attribute
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" polyspace +1 MISRA-C3:21.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule21.1" */
#define __has_attribute(x)      0U  /* PRQA S 0602 */ /* NSCA_QAC_NeuLib_ReservedIdentifier */
#endif  /* __has_attribute */

#if __has_cpp_attribute(fallthrough) || __has_c_attribute(fallthrough)
    #define FALLTHROUGH [[fallthrough]]
#elif __has_attribute(fallthrough)
    #define FALLTHROUGH __attribute__((fallthrough))
/* Note, there could be more branches here, like using `[[gsl::suppress]]` for MSVC */
#else
    #define FALLTHROUGH
#endif  /* __has_cpp_attribute(fallthrough) || __has_c_attribute(fallthrough) */

/* polyspace +1 MISRA-C3:11.4 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define UNALIGNED(X, Y)     (((uint32)(X) & (sizeof(uint32) - NEULIB_SHIFT_1)) | ((uint32)(Y) & (sizeof(uint32) - NEULIB_SHIFT_1)))
#define BIGBLOCKSIZE        (uint8)(sizeof(uint32) << NEULIB_SHIFT_2)
#define LITTLEBLOCKSIZE     (sizeof(uint32))
/* polyspace +1 MISRA-C3:10.7 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule10.7" polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define TOO_SMALL(LEN)      ((LEN) < BIGBLOCKSIZE)

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
#define NEULIB_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"
#if (NEULIB_MEM_OPERATION_OPTIMIZATION == STD_ON)
LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemCopy_8_3(
    P2VAR(uint8, AUTOMATIC, NEULIB_APPL_DATA) pDst8,
    P2CONST(uint8, AUTOMATIC, NEULIB_APPL_CONST) pSrc8,
    uint8_least cnt
);

LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemCopy_8_31(
    P2VAR(uint8, AUTOMATIC, NEULIB_APPL_DATA) pDst8,
    P2CONST(uint8, AUTOMATIC, NEULIB_APPL_CONST) pSrc8,
    uint8_least cnt
);

LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemCopy_8_PartialWord(
    P2VAR(uint8, AUTOMATIC, NEULIB_APPL_DATA) pDst8,
    uint8_least cnt,
    P2VAR(uint32, AUTOMATIC, NEULIB_APPL_DATA) pPrev,
    P2VAR(uint32_least, AUTOMATIC, NEULIB_APPL_DATA) pDPos
);

LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemCopy_32_Aligned(
    P2VAR(uint32, AUTOMATIC, NEULIB_APPL_DATA) pDst32,
    P2CONST(uint32, AUTOMATIC, NEULIB_APPL_CONST) pSrc32,
    uint32_least cnt
);

LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemCopy_32_Unaligned(
    P2VAR(uint8, AUTOMATIC, NEULIB_APPL_DATA) pDst8,
    P2CONST(uint32, AUTOMATIC, NEULIB_APPL_CONST) pSrc32,
    uint32_least cnt,
    uint8_least dstOffset
);

LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemSet_8_3(
    P2VAR(uint8, AUTOMATIC, NEULIB_APPL_DATA) pDst8,
    uint8 value,
    uint8_least cnt
);

LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemSet_8_31(
    P2VAR(uint8, AUTOMATIC, NEULIB_APPL_DATA) pDst8,
    uint8 value,
    uint8_least cnt
);

LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemSet_32_Aligned(
    P2VAR(uint32, AUTOMATIC, NEULIB_APPL_DATA) pDst32,
    uint8 value,
    uint32_least cnt
);
#endif  /* (NEULIB_MEM_OPERATION_OPTIMIZATION == STD_ON) */
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

#if (NEULIB_MEM_OPERATION_OPTIMIZATION == STD_ON)
/*
********************************************************************************
* Function Name: NeuLib_MemCopy_8_3
*
* Explanation:   Copies up to 3 bytes from pSrc8 to pDst8 (any alignment).
* (Synchronous)
*
* param:         pDst8 DstPtr data pointer.
*                pSrc8 Source data.
*                cnt   Copy total length.
*
* retval:        None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemCopy_8_3(
    P2VAR(uint8, AUTOMATIC, NEULIB_APPL_DATA) pDst8,
    P2CONST(uint8, AUTOMATIC, NEULIB_APPL_CONST) pSrc8,
    uint8_least cnt
)
{
    /**
     * MISRA C:2012 16.1
     * All switch statements shall be well-formed.
     * Initialize up to 3 bytes using a jump table.
     */
    /* polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.1" polyspace +1 DEFECT:INAPPROPRIATE_TYPE_IN_SWITCH [Justified:Unset] "NSCA_Polyspace_NeuLib_INAPPROPRIATE_TYPE_IN_SWITCH" */
    switch( cnt )
    {
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_3:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_2] = pSrc8[NEULIB_IDX_2];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_2:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_1] = pSrc8[NEULIB_IDX_1];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_1:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_0] = pSrc8[NEULIB_IDX_0];
        FALLTHROUGH;
        /*!< Intentionally no break. */
    default:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* Do nothing. */
        break;
    }
}

/*
********************************************************************************
* Function Name: NeuLib_MemCopy_8_31
*
* Explanation:   Copy up to 31 bytes from pSrc8 to pDst8 (any alignment).
* (Synchronous)
*
* param:         pDst8 DstPtr data pointer.
*                pSrc8 Source data.
*                cnt   Copy total length.
*
* retval:        None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemCopy_8_31(
    P2VAR(uint8, AUTOMATIC, NEULIB_APPL_DATA) pDst8,
    P2CONST(uint8, AUTOMATIC, NEULIB_APPL_CONST) pSrc8,
    uint8_least cnt
)
{
    /**
     * MISRA C:2012 16.1
     * All switch statements shall be well-formed.
     * Initialize up to 31 bytes using a jump table.
     */
    /* polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.1" polyspace +1 DEFECT:INAPPROPRIATE_TYPE_IN_SWITCH [Justified:Unset] "NSCA_Polyspace_NeuLib_INAPPROPRIATE_TYPE_IN_SWITCH" */
    switch (cnt)
    {
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_31:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_30] = pSrc8[NEULIB_IDX_30];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_30:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_29] = pSrc8[NEULIB_IDX_29];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_29:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_28] = pSrc8[NEULIB_IDX_28];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_28:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_27] = pSrc8[NEULIB_IDX_27];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_27:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_26] = pSrc8[NEULIB_IDX_26];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_26:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_25] = pSrc8[NEULIB_IDX_25];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_25:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_24] = pSrc8[NEULIB_IDX_24];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_24:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_23] = pSrc8[NEULIB_IDX_23];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_23:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_22] = pSrc8[NEULIB_IDX_22];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_22:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_21] = pSrc8[NEULIB_IDX_21];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_21:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_20] = pSrc8[NEULIB_IDX_20];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_20:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_19] = pSrc8[NEULIB_IDX_19];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_19:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_18] = pSrc8[NEULIB_IDX_18];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_18:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_17] = pSrc8[NEULIB_IDX_17];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_17:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_16] = pSrc8[NEULIB_IDX_16];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_16:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_15] = pSrc8[NEULIB_IDX_15];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_15:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_14] = pSrc8[NEULIB_IDX_14];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_14:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_13] = pSrc8[NEULIB_IDX_13];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_13:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_12] = pSrc8[NEULIB_IDX_12];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_12:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_11] = pSrc8[NEULIB_IDX_11];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_11:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_10] = pSrc8[NEULIB_IDX_10];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_10:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_9] = pSrc8[NEULIB_IDX_9];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_9:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_8] = pSrc8[NEULIB_IDX_8];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_8:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_7] = pSrc8[NEULIB_IDX_7];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_7:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_6] = pSrc8[NEULIB_IDX_6];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_6:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_5] = pSrc8[NEULIB_IDX_5];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_5:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_4] = pSrc8[NEULIB_IDX_4];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_4:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_3] = pSrc8[NEULIB_IDX_3];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_3:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_2] = pSrc8[NEULIB_IDX_2];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_2:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_1] = pSrc8[NEULIB_IDX_1];
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_1:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[NEULIB_IDX_0] = pSrc8[NEULIB_IDX_0];
        FALLTHROUGH;
        /*!< Intentionally no break. */
    default:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* Do nothing. */
        break;
    }
}

/*
********************************************************************************
* Function Name: NeuLib_MemCopy_8_PartialWord
*
* Explanation:   Copies a partial word of 1 to 3 bytes from srcPtr to pDst8 to
                 reach a 32-bit boundary (any alignment).
* (Synchronous)
*
* param:         pDst8 8-bit pointer to the memory location to copy to.
*                cnt   Number of bytes to copy, pDst8 must be valid for this amount.
*                pPrev Word to copy from (is modified and used by caller afterwards).
*                pDPos Index for pDst8 to copy to (is modified and used by caller afterwards).
*
* retval:        None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemCopy_8_PartialWord(
    P2VAR(uint8, AUTOMATIC, NEULIB_APPL_DATA) pDst8,
    uint8_least cnt,
    P2VAR(uint32, AUTOMATIC, NEULIB_APPL_DATA) pPrev,
    P2VAR(uint32_least, AUTOMATIC, NEULIB_APPL_DATA) pDPos
)
{
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    /**
     * Copy 1 to 3 bytes using a jump table and adapt '*pDPos' and '*pPrev' for little endian byte order.
     *
     * MISRA C:2012 16.1
     * All switch statements shall be well-formed.
     * Initialize up to 3 bytes using a jump table.
     */
    /* polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.1" polyspace +1 DEFECT:INAPPROPRIATE_TYPE_IN_SWITCH [Justified:Unset] "NSCA_Polyspace_NeuLib_INAPPROPRIATE_TYPE_IN_SWITCH" */
    switch (cnt)
    {
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_3:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[*pDPos] = (uint8)*pPrev;
        (*pDPos)++;
        (*pPrev) >>= NEULIB_SHIFT_8;
        FALLTHROUGH;
        /* Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_2:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[*pDPos] = (uint8)*pPrev;
        (*pDPos)++;
        (*pPrev) >>= NEULIB_SHIFT_8;
        FALLTHROUGH;
        /* Intentionally no break. */
    /* Case 1 - cnt is always in range [1..3] */
    default:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst8[*pDPos] = (uint8)*pPrev;
        (*pDPos)++;
        (*pPrev) >>= NEULIB_SHIFT_8;
        break;
    }

#else   /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */

    /**
     * Copy 1 to 3 bytes using a jump table and adapt '*pDPos' and '*pPrev' for big endian byte order.
     *
     * MISRA C:2012 16.1
     * All switch statements shall be well-formed.
     * Initialize up to 3 bytes using a jump table.
     */
    switch (cnt)
    {
    case NEULIB_CNT_3:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[*pDPos] = (uint8)(*pPrev >> NEULIB_SHIFT_24);
        (*pDPos)++;
        *pPrev <<= NEULIB_SHIFT_8;
        /* Intentionally no break. */
    case NEULIB_CNT_2:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[*pDPos] = (uint8)(*pPrev >> NEULIB_SHIFT_24);
        (*pDPos)++;
        *pPrev <<= NEULIB_SHIFT_8;
        /* Intentionally no break. */
    /* Case 1 - cnt is always in range [1..3] */
    default:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[*pDPos] = (uint8)(*pPrev >> NEULIB_SHIFT_24);
        (*pDPos)++;
        *pPrev <<= NEULIB_SHIFT_8;
        break;
    }
#endif  /* (CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
}

/*
********************************************************************************
* Function Name: NeuLib_MemCopy_32_Aligned
*
* Explanation:   Copy 32-bit aligned data from pSrc32 to pDst32.
* (Synchronous)
*
* param:         pDst32 32-bit pointer to the memory location to copy to.
*                pSrc32 32-bit pointer to the memory location to copy from.
*                cnt:   Number of bytes to copy, pDst32 must be valid for this amount.
*
* retval:        None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemCopy_32_Aligned(
    P2VAR(uint32, AUTOMATIC, NEULIB_APPL_DATA) pDst32,
    P2CONST(uint32, AUTOMATIC, NEULIB_APPL_CONST) pSrc32,
    uint32_least cnt
)
{
    uint32 x0;
    uint32 x1;
    uint32 x2;
    uint32 x3;
    uint32 remSize;
    uint32 dstPos = NEULIB_INIT_0;

    /* Linearly copy 16-byte blocks using 32-bit accesses in a loop. */
    for (remSize = cnt; remSize >= NEULIB_MEMCOPY_16_BYTE; remSize -= 16u)
    {
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        x0 = pSrc32[dstPos + NEULIB_SHIFT_0];
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        x1 = pSrc32[dstPos + NEULIB_SHIFT_1];
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        x2 = pSrc32[dstPos + NEULIB_SHIFT_2];
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        x3 = pSrc32[dstPos + NEULIB_SHIFT_3];
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst32[dstPos + NEULIB_SHIFT_0] = x0;
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst32[dstPos + NEULIB_SHIFT_1] = x1;
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst32[dstPos + NEULIB_SHIFT_2] = x2;
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst32[dstPos + NEULIB_SHIFT_3] = x3;
        dstPos += NEULIB_SHIFT_4;
    }

    /**
     * Copy the remSize block using a jump table.
     *
     * MISRA C:2012 16.1
     * All switch statements shall be well-formed.
     * Initialize the remaining block using a jump table
     */
    /* polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.1" polyspace +1 DEFECT:INAPPROPRIATE_TYPE_IN_SWITCH [Justified:Unset] "NSCA_Polyspace_NeuLib_INAPPROPRIATE_TYPE_IN_SWITCH" */
    switch (remSize)
    {
    case NEULIB_CNT_15:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    case NEULIB_CNT_14:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    case NEULIB_CNT_13:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_12:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst32[dstPos] = pSrc32[dstPos];
        dstPos++;
        FALLTHROUGH;
        /*!< Intentionally no break. */
    case NEULIB_CNT_11:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    case NEULIB_CNT_10:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    case NEULIB_CNT_9:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_8:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst32[dstPos] = pSrc32[dstPos];
        dstPos++;
        FALLTHROUGH;
        /*!< Intentionally no break. */
    case NEULIB_CNT_7:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    case NEULIB_CNT_6:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    case NEULIB_CNT_5:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_4:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        pDst32[dstPos] = pSrc32[dstPos];
        dstPos++;
        FALLTHROUGH;
        /*!< Intentionally no break. */
    case NEULIB_CNT_3:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    case NEULIB_CNT_2:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_1:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        NeuLib_MemCopy_8_3((uint8*)&pDst32[dstPos], (const uint8*)&pSrc32[dstPos], (uint8)(remSize & NEULIB_MEMCOPY_MASK_3));  /* PRQA S 0310 */ /* NSCA_QAC_NeuLib_Rule11.3 */
        FALLTHROUGH;
        /*!< Intentionally no break. */
    default:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* Do nothing. */
        break;
    }
}

/*
********************************************************************************
* Function Name: NeuLib_MemCopy_32_Unaligned
*
* Explanation:   Copies data from 32-bit aligned pSrc to unaligned pDst8.
* (Synchronous)
*
* param:         pDst8     8-bit pointer to the memory location to copy to.
*                pSrc32    32-bit pointer to the memory location to copy from.
*                cnt       Number of bytes to copy, pDst8 must be valid for this amount.
*                dstOffset DstPtr offset to the next 32-bit boundary.
*
* retval:        None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemCopy_32_Unaligned(
    P2VAR(uint8, AUTOMATIC, NEULIB_APPL_DATA) pDst8,
    P2CONST(uint32, AUTOMATIC, NEULIB_APPL_CONST) pSrc32,
    uint32_least cnt,
    uint8_least dstOffset
)
{
    uint32 dstPos = NEULIB_INIT_0;
    uint32 sPos = NEULIB_INIT_0;
    uint32 remSize = cnt;

    /* If more than 32 bytes have to be copied. */
    if (remSize >= NEULIB_MEMCOPY_32_BYTE)
    {
        uint32 prev;
        P2VAR(uint32, AUTOMATIC, NEULIB_VAR_FAR) dst32Ptr;

        /* Copy the first partial word to reach the 32-bit boundary and adjust the destination pointer. */
        /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        prev = pSrc32[sPos];

        remSize -= NEULIB_SHIFT_4;
        NeuLib_MemCopy_8_PartialWord(pDst8, dstOffset, &prev, &dstPos);

        /* At this point 'pDst8[dstPos]' is aligned to a 32-bit boundary */
        /* polyspace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
        dst32Ptr = (uint32 *)(void *)&pDst8[dstPos];  /* PRQA S 0316 */ /* NSCA_QAC_NeuLib_Rule11.5 */
        dstPos = NEULIB_INIT_0;
        sPos++;

        /* Linearly copy 16-byte blocks using 32-bit accesses by correcting the byte displacement of dst and src. */
        if (MEM_24_BIT_DISPLACEMENT == dstOffset) /* 24-bit displacement */
        {
            uint32 x0;
            uint32 x1;
            uint32 x2;
            uint32 x3;
            uint32 x4;

            for (; remSize >= NEULIB_MEMCOPY_16_BYTE; remSize -= NEULIB_SHIFT_16)
            {
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                x1 = pSrc32[sPos + NEULIB_SHIFT_0];
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                x2 = pSrc32[sPos + NEULIB_SHIFT_1];
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                x3 = pSrc32[sPos + NEULIB_SHIFT_2];
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                x4 = pSrc32[sPos + NEULIB_SHIFT_3];

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
                x0 = prev | (x1 << NEULIB_SHIFT_8);
                x1 = (x1 >> NEULIB_SHIFT_24) | (x2 << NEULIB_SHIFT_8);
                x2 = (x2 >> NEULIB_SHIFT_24) | (x3 << NEULIB_SHIFT_8);
                x3 = (x3 >> NEULIB_SHIFT_24) | (x4 << NEULIB_SHIFT_8);
                prev = x4 >> NEULIB_SHIFT_24;
#else   /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
                x0 = prev | (x1 >> NEULIB_SHIFT_8);
                x1 = (x1 << NEULIB_SHIFT_24) | (x2 >> NEULIB_SHIFT_8);
                x2 = (x2 << NEULIB_SHIFT_24) | (x3 >> NEULIB_SHIFT_8);
                x3 = (x3 << NEULIB_SHIFT_24) | (x4 >> NEULIB_SHIFT_8);
                prev = x4 << NEULIB_SHIFT_24;
#endif  /* (CPU_BYTE_ORDER == LOW_BYTE_FIRST) */

                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                dst32Ptr[dstPos + NEULIB_SHIFT_0] = x0;
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                dst32Ptr[dstPos + NEULIB_SHIFT_1] = x1;
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                dst32Ptr[dstPos + NEULIB_SHIFT_2] = x2;
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                dst32Ptr[dstPos + NEULIB_SHIFT_3] = x3;

                sPos += NEULIB_SHIFT_4;
                dstPos += NEULIB_SHIFT_4;
            }
        }
        /* 16-bit displacement */
        else if (MEM_16_BIT_DISPLACEMENT == dstOffset)
        {
            uint32 x0;
            uint32 x1;
            uint32 x2;
            uint32 x3;
            uint32 x4;

            for (; remSize >= NEULIB_MEMCOPY_16_BYTE; remSize -= NEULIB_SHIFT_16)
            {
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                x1 = pSrc32[sPos + NEULIB_SHIFT_0];
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                x2 = pSrc32[sPos + NEULIB_SHIFT_1];
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                x3 = pSrc32[sPos + NEULIB_SHIFT_2];
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                x4 = pSrc32[sPos + NEULIB_SHIFT_3];

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
                x0 = prev | (x1 << NEULIB_SHIFT_16);
                x1 = (x1 >> NEULIB_SHIFT_16) | (x2 << NEULIB_SHIFT_16);
                x2 = (x2 >> NEULIB_SHIFT_16) | (x3 << NEULIB_SHIFT_16);
                x3 = (x3 >> NEULIB_SHIFT_16) | (x4 << NEULIB_SHIFT_16);
                prev = x4 >> 16u;
#else /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
                x0 = prev | (x1 >> NEULIB_SHIFT_16);
                x1 = (x1 << NEULIB_SHIFT_16) | (x2 >> NEULIB_SHIFT_16);
                x2 = (x2 << NEULIB_SHIFT_16) | (x3 >> NEULIB_SHIFT_16);
                x3 = (x3 << NEULIB_SHIFT_16) | (x4 >> NEULIB_SHIFT_16);
                prev = x4 << NEULIB_SHIFT_16;
#endif  /* (CPU_BYTE_ORDER == LOW_BYTE_FIRST) */

                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                dst32Ptr[dstPos + NEULIB_SHIFT_0] = x0;
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                dst32Ptr[dstPos + NEULIB_SHIFT_1] = x1;
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                dst32Ptr[dstPos + NEULIB_SHIFT_2] = x2;
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                dst32Ptr[dstPos + NEULIB_SHIFT_3] = x3;

                dstPos += NEULIB_SHIFT_4;
                sPos += NEULIB_SHIFT_4;
            }
        }
        else /* dstOffset == 1 - 8-bit displacement */
        {
            uint32 x0;
            uint32 x1;
            uint32 x2;
            uint32 x3;
            uint32 x4;

            for (; remSize >= NEULIB_MEMCOPY_16_BYTE; remSize -= NEULIB_SHIFT_16)
            {
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                x1 = pSrc32[sPos + NEULIB_SHIFT_0];
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                x2 = pSrc32[sPos + NEULIB_SHIFT_1];
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                x3 = pSrc32[sPos + NEULIB_SHIFT_2];
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                x4 = pSrc32[sPos + NEULIB_SHIFT_3];

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
                x0 = prev | (x1 << NEULIB_SHIFT_24);
                x1 = (x1 >> NEULIB_SHIFT_8) | (x2 << NEULIB_SHIFT_24);
                x2 = (x2 >> NEULIB_SHIFT_8) | (x3 << NEULIB_SHIFT_24);
                x3 = (x3 >> NEULIB_SHIFT_8) | (x4 << NEULIB_SHIFT_24);
                prev = x4 >> NEULIB_SHIFT_8;
#else /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
                x0 = prev | (x1 >> NEULIB_SHIFT_24);
                x1 = (x1 << NEULIB_SHIFT_8) | (x2 >> NEULIB_SHIFT_24);
                x2 = (x2 << NEULIB_SHIFT_8) | (x3 >> NEULIB_SHIFT_24);
                x3 = (x3 << NEULIB_SHIFT_8) | (x4 >> NEULIB_SHIFT_24);
                prev = x4 << NEULIB_SHIFT_8;
#endif  /* (CPU_BYTE_ORDER == LOW_BYTE_FIRST) */

                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                dst32Ptr[dstPos + NEULIB_SHIFT_0] = x0;
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                dst32Ptr[dstPos + NEULIB_SHIFT_1] = x1;
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                dst32Ptr[dstPos + NEULIB_SHIFT_2] = x2;
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                dst32Ptr[dstPos + NEULIB_SHIFT_3] = x3;

                dstPos += NEULIB_SHIFT_4;
                sPos += NEULIB_SHIFT_4;
            }
        }
        /* Linearly copy the remSize words using a loop. */
        {
            uint32 x0;
            uint32 x1;
            /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_NeuLib_UNMODIFIED_VAR_NOT_CONST" */
            uint8 prevShift = (uint8)((dstOffset << NEULIB_SHIFT_3) & NEULIB_MEMCOPY_MASK_31);
            /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_NeuLib_UNMODIFIED_VAR_NOT_CONST" */
            uint8 xShift = NEULIB_CNT_32 - prevShift;

            /* At this point remSize is < 16 byte */
            for (; remSize >= NEULIB_CNT_4; remSize -= NEULIB_SHIFT_4)
            {
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                x1 = pSrc32[sPos];

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
                x0 = prev | (x1 << xShift);
                prev = x1 >> prevShift;
#else   /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
                x0 = prev | (x1 >> xShift);
                prev = x1 << prevShift;
#endif  /* (CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
                dst32Ptr[dstPos] = x0;

                dstPos++;
                sPos++;
            }
        }

        /* Copy the remSize partial word using a byte-wise algorithm. */
        /* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
        pDst8 = (uint8 *)&dst32Ptr[dstPos];  /* PRQA S 0310 */ /* NSCA_QAC_NeuLib_Rule11.3 */
        dstPos = NEULIB_SHIFT_0;
        NeuLib_MemCopy_8_PartialWord(pDst8, (NEULIB_CNT_4 - dstOffset), &prev, &dstPos);
    }

    /* Copy the remSize bytes using a byte-wise algorithm. */
    NeuLib_MemCopy_8_31(&pDst8[dstPos], (const uint8*)&pSrc32[sPos], (uint8)(remSize & NEULIB_MEMCOPY_MASK_31));  /* PRQA S 0310 */ /* NSCA_QAC_NeuLib_Rule11.3 */
}

/*
********************************************************************************
* Function Name: NeuLib_MemSet_8_3
*
* Explanation:   Initializes up to 3 bytes at dstPtr to the character value (any alignment).
* (Synchronous)
*
* param:         dstPtr 8-bit pointer to the memory location to be initialized.
*                value  The character to be used to initialize the memory.
*                cnt    Number of bytes to initialize, pDst must be valid for this amount.
*
* retval:        None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemSet_8_3(
    P2VAR(uint8, AUTOMATIC, NEULIB_APPL_DATA) pDst8,
    uint8 value,
    uint8_least cnt
)
{
    /**
     * Initialize up to 3 bytes using a jump table.
     *
     * MISRA C:2012 16.1
     * All switch statements shall be well-formed.
     * Initialize up to 3 bytes using a jump table.
     */
    /* polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.1" polyspace +1 DEFECT:INAPPROPRIATE_TYPE_IN_SWITCH [Justified:Unset] "NSCA_Polyspace_NeuLib_INAPPROPRIATE_TYPE_IN_SWITCH" */
    switch( cnt )
    {
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_3:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_2] = value;
        FALLTHROUGH;
        /* Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_2:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_1] = value;
        FALLTHROUGH;
        /* Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_1:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_0] = value;
        FALLTHROUGH;
        /* Intentionally no break. */
    default:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* Do nothing. */
        break;
    }
}

/*
********************************************************************************
* Function Name: NeuLib_MemSet_8_31
*
* Explanation:   Initializes up to 31 bytes at dstPtr to the character value (any alignment).
* (Synchronous)
*
* param:         dstPtr 8-bit pointer to the memory location to be initialized.
*                value  The character to be used to initialize the memory.
*                cnt    Number of bytes to initialize, pDst must be valid for this amount.
*
* retval:        None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemSet_8_31(
    P2VAR(uint8, AUTOMATIC, NEULIB_APPL_DATA) pDst8,
    uint8 value,
    uint8_least cnt
)
{
    /**
     * MISRA C:2012 16.1
     * All switch statements shall be well-formed.
     * Initialize up to 31 bytes using a jump table.
     */
    /* polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.1" polyspace +1 DEFECT:INAPPROPRIATE_TYPE_IN_SWITCH [Justified:Unset] "NSCA_Polyspace_NeuLib_INAPPROPRIATE_TYPE_IN_SWITCH" */
    switch (cnt)
    {
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_31:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_30] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_30:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_29] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_29:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_28] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_28:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_27] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_27:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_26] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_26:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_25] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_25:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_24] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_24:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_23] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_23:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_22] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_22:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_21] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_21:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_20] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_20:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_19] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_19:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_18] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_18:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_17] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_17:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_16] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_16:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_15] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_15:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_14] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_14:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_13] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_13:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_12] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_12:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_11] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_11:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_10] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_10:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_9] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_9:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_8] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_8:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_7] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_7:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_6] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_6:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_5] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_5:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_4] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_4:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_3] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_3:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_2] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_2:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_1] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
        /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_1:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst8[NEULIB_IDX_0] = value;
        FALLTHROUGH;
        /*!< Intentionally no break. */
    default:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* Nothing to do. */
        break;
    }
}

/*
********************************************************************************
* Function Name: NeuLib_MemSet_32_Aligned
*
* Explanation:   Initializes memory at dstPtr to the character value (32-bit aligned).
* (Synchronous)
*
* param:         dstPtr 32-bit pointer to the memory location to be initialized.
*                value  The character to be used to initialize the memory.
*                cnt    Number of bytes to initialize, pDst must be valid for this amount.
*
* retval:        None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLib_MemSet_32_Aligned(
    P2VAR(uint32, AUTOMATIC, NEULIB_APPL_DATA) pDst32,
    uint8 value,
    uint32_least cnt
)
{
    uint32 remSize;
    uint32 dPos    = NEULIB_INIT_0;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_NeuLib_UNMODIFIED_VAR_NOT_CONST" */
    uint32 value32 = (((uint32)value << NEULIB_SHIFT_24) |
                      ((uint32)value << NEULIB_SHIFT_16) |
                      ((uint32)value << NEULIB_SHIFT_8 ) | value);

    /* Linearly initialize 16-byte blocks using 32-bit accesses in a loop. */
    for (remSize = cnt; remSize >= NEULIB_MEMCOPY_16_BYTE; remSize -= NEULIB_SHIFT_16)
    {
        pDst32[dPos + NEULIB_SHIFT_0] = value32;
        pDst32[dPos + NEULIB_SHIFT_1] = value32;
        pDst32[dPos + NEULIB_SHIFT_2] = value32;
        pDst32[dPos + NEULIB_SHIFT_3] = value32;
        dPos += NEULIB_SHIFT_4;
    }

    /**
     * Initialize the remSize block using a jump table.
     *
     * MISRA C:2012 16.1
     * All switch statements shall be well-formed.
     * Initialize the remaining block using a jump table
     */
    /* polyspace +1 MISRA-C3:16.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.1" polyspace +1 DEFECT:INAPPROPRIATE_TYPE_IN_SWITCH [Justified:Unset] "NSCA_Polyspace_NeuLib_INAPPROPRIATE_TYPE_IN_SWITCH" */
    switch (remSize)
    {
    case NEULIB_CNT_15:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    case NEULIB_CNT_14:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    case NEULIB_CNT_13:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_12:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst32[dPos] = value32;
        dPos++;
        FALLTHROUGH;
        /*!< Intentionally no break. */
    case NEULIB_CNT_11:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    case NEULIB_CNT_10:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    case NEULIB_CNT_9:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_8:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst32[dPos] = value32;
        dPos++;
        FALLTHROUGH;
        /*!< Intentionally no break. */
    case NEULIB_CNT_7:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    case NEULIB_CNT_6:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    case NEULIB_CNT_5:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_4:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        pDst32[dPos] = value32;
        dPos++;
        FALLTHROUGH;
        /*!< Intentionally no break. */
    case NEULIB_CNT_3:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    case NEULIB_CNT_2:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
    /* polyspace +1 MISRA-C3:16.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule16.3" */
    case NEULIB_CNT_1:   /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        NeuLib_MemSet_8_3((uint8 *)&pDst32[dPos], value, (uint8_least)(remSize & NEULIB_MEMCOPY_MASK_3));  /* PRQA S 0310 */ /* NSCA_QAC_NeuLib_Rule11.3 */
        FALLTHROUGH;
        /*!< Intentionally no break. */
    default:  /* PRQA S 2003 */ /* NSCA_QAC_NeuLib_Rule16.3 */
        /* Do nothing. */
        break;
    }
}
#endif  /* (NEULIB_MEM_OPERATION_OPTIMIZATION == STD_ON) */

/*
********************************************************************************
* Function Name: NeuLib_memcpy
*
* Explanation:   This function will copy memory content from source address to destination address.
* (Synchronous)
*
* param:         dstPtr The address of destination memory.
*                srcPtr The address of source memory.
*                size   The copied length.
*
* retval:        None
********************************************************************************
*/
FUNC(void, NEULIB_CODE) NeuLib_memcpy(  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
    P2VAR(void, AUTOMATIC, NEULIB_APPL_DATA) dstPtr,
    P2CONST(void, AUTOMATIC, NEULIB_APPL_CONST) srcPtr,
    CONST(uint32, NEULIB_CONST) size
)
{
    uint32 remSize;
#if (NEULIB_MEM_OPERATION_OPTIMIZATION != STD_ON)
    uint8 *dst = (uint8 *)dstPtr;
    uint8 *src = (uint8 *)srcPtr;
    uint32 *alignedDst;
    uint32 *alignedSrc;
    uint32 len = size;
#endif  /* (NEULIB_MEM_OPERATION_OPTIMIZATION == STD_ON) */

    /* Pointer check. */
    NeuLib_CheckDetReturnVoid(dstPtr != NULL_PTR, NEULIB_SID_MEM_COPY, NEULIB_E_PARAM_POINTER);
    NeuLib_CheckDetReturnVoid(srcPtr != NULL_PTR, NEULIB_SID_MEM_COPY, NEULIB_E_PARAM_POINTER);

#if (NEULIB_MEM_OPERATION_OPTIMIZATION == STD_ON)
    remSize = size;
    if (remSize < NEULIB_MEMCOPY_32_BYTE)
    {
        /* Use a byte-wise algorithm. */
        /* polyspace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
        NeuLib_MemCopy_8_31((uint8*)dstPtr, (const uint8*)srcPtr, (uint8_least)(size & NEULIB_MEMCOPY_MASK_31));  /* PRQA S 0316 */ /* NSCA_QAC_NeuLib_Rule11.5 */
    }
    else
    {
        /* Get the source pointer offset to the next 32-bit boundary. */
        /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_NeuLib_UNMODIFIED_VAR_NOT_CONST" */
        uint8 srcOffset = MEM_ALIGN_OFFSET(srcPtr);  /* PRQA S 4461, 0306  */ /* NSCA_QAC_NeuLib_Rule10.3, NSCA_QAC_NeuLib_PointerCast */
        uint8 dstOffset;

        /* If the source is not aligned. */
        if (NEULIB_SHIFT_0 != srcOffset)
        {
            /* Copy the amount of bytes to reach the boundary on 'pSrc' and adjust the pointers. */
            /* polyspace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
            NeuLib_MemCopy_8_3((uint8*)dstPtr, (const uint8*)srcPtr, srcOffset);  /* PRQA S 0316 */ /* NSCA_QAC_NeuLib_Rule11.5 */
            /* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            srcPtr = &((const uint8*)srcPtr)[srcOffset];  /* PRQA S 0316 */ /* NSCA_QAC_NeuLib_Rule11.5 */
            /* polyspace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            dstPtr = &((uint8*)dstPtr)[srcOffset];  /* PRQA S 0316 */ /* NSCA_QAC_NeuLib_Rule11.5 */
            remSize -= srcOffset;
        }

        /* Get the destination pointer offset to the next 32-bit boundary. */
        /* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule10.3" */
        dstOffset = MEM_ALIGN_OFFSET(dstPtr);  /* PRQA S 4461, 0306  */ /* NSCA_QAC_NeuLib_Rule10.3, NSCA_QAC_NeuLib_PointerCast */

        /* If destination is aligned. */
        if (NEULIB_SHIFT_0 == dstOffset)
        {
            /* Both pointers are aligned, use the 32-bit aligned memcpy. */
            /* polyspace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
            NeuLib_MemCopy_32_Aligned((uint32*)dstPtr, (const uint32*)srcPtr, remSize);  /* PRQA S 0316 */ /* NSCA_QAC_NeuLib_Rule11.5 */
        }
        else
        {
            /* Use the 32-bit unaligned memcpy. */
            /* polyspace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
            NeuLib_MemCopy_32_Unaligned((uint8*)dstPtr, (const uint32*)srcPtr, remSize, dstOffset);  /* PRQA S 0316 */ /* NSCA_QAC_NeuLib_Rule11.5 */
        }
    }
#else   /* (NEULIB_MEM_OPERATION_OPTIMIZATION == STD_ON) */

    /**
     * If the size is small, or either SRC or DST is unaligned,
     * then punt into the byte copy loop.  This should be rare.
     */
    if (!TOO_SMALL(len) && !UNALIGNED(src, dst))
    {
        alignedDst = (uint32 *)dst;
        alignedSrc = (uint32 *)src;

        /* Copy 4X uint32 words at a time if possible. */
        while (len >= BIGBLOCKSIZE)
        {
            *alignedDst++ = *alignedSrc++;
            *alignedDst++ = *alignedSrc++;
            *alignedDst++ = *alignedSrc++;
            *alignedDst++ = *alignedSrc++;
            len -= BIGBLOCKSIZE;
        }

        /* Copy one uint32 word at a time if possible. */
        while (len >= LITTLEBLOCKSIZE)
        {
            *alignedDst++ = *alignedSrc++;
            len -= LITTLEBLOCKSIZE;
        }

        /* Pick up any residual with a byte copier. */
        dst = (uint8 *)alignedDst;
        src = (uint8 *)alignedSrc;
    }

    while (len--)
    {
        *dst++ = *src++;
    }

#endif  /* (NEULIB_MEM_OPERATION_OPTIMIZATION == STD_ON) */
}

/*
********************************************************************************
* Function Name: NeuLib_memcpy32
*
* Explanation: 32-bit data copy.
* (Synchronous)
*
* param: dstPtr: The address of destination memory.
*        srcPtr: The address of source memory.
*        size: The copied length.
*
* retval: None
********************************************************************************
*/
FUNC(void, NEULIB_CODE) NeuLib_memcpy32(  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
    P2VAR(void, AUTOMATIC, NEULIB_APPL_DATA) dstPtr,
    P2CONST(void, AUTOMATIC, NEULIB_APPL_CONST) srcPtr,
    CONST(uint32, NEULIB_CONST) size
)
{
    /* polyspace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
    uint8* dst = (uint8*)dstPtr;  /* PRQA S 0316 */ /* NSCA_QAC_NeuLib_Rule11.5 */
    const uint8* src = (const uint8*)srcPtr;  /* PRQA S 0316 */ /* NSCA_QAC_NeuLib_Rule11.5 */
    uint32* alignedDst;
    const uint32* alignedSrc;
    uint32 len = size;

    /* Pointer check. */
    NeuLib_CheckDetReturnVoid(dstPtr != NULL_PTR, NEULIB_SID_MEM_COPY, NEULIB_E_PARAM_POINTER);
    NeuLib_CheckDetReturnVoid(srcPtr != NULL_PTR, NEULIB_SID_MEM_COPY, NEULIB_E_PARAM_POINTER);

    /*
     * If the size is small, or either SRC or DST is unaligned,
     * then punt into the byte copy loop.  This should be rare.
     */
    /* polyspace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule10.1" */
    if( !TOO_SMALL(len) && !UNALIGNED(src, dst) )  /* PRQA S 0306, 4558 */ /* NSCA_QAC_NeuLib_PointerCast, NSCA_QAC_NeuLib_Rule10.1 */
    {
        /* polyspace +1 MISRA-C3:11.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
        alignedDst = (uint32*)dst;  /* PRQA S 0310, 3305 */ /* NSCA_QAC_NeuLib_Rule11.3, NSCA_QAC_NeuLib_Rule11.3 */
        /* polyspace +1 MISRA-C3:11.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
        alignedSrc = (const uint32*)src;  /* PRQA S 0310, 3305 */ /* NSCA_QAC_NeuLib_Rule11.3, NSCA_QAC_NeuLib_Rule11.3 */

        /* Copy 4X uint32 words at a time if possible. */
        /* polyspace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_LOOP_BOUNDARY" polyspace +1 MISRA-C3:10.7 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule10.7" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
        while( len >= BIGBLOCKSIZE )
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 MISRA-C3:13.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule13.3" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
            *alignedDst++ = *alignedSrc++;  /* PRQA S 3440 */ /* NSCA_QAC_NeuLib_Rule13.3 */
            /* polyspace +1 MISRA-C3:13.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule13.3" */
            *alignedDst++ = *alignedSrc++;  /* PRQA S 3440 */ /* NSCA_QAC_NeuLib_Rule13.3 */
            /* polyspace +1 MISRA-C3:13.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule13.3" */
            *alignedDst++ = *alignedSrc++;  /* PRQA S 3440 */ /* NSCA_QAC_NeuLib_Rule13.3 */
            /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:13.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule13.3" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
            *alignedDst++ = *alignedSrc++;  /* PRQA S 3440 */ /* NSCA_QAC_NeuLib_Rule13.3  */
            /* polyspace +1 MISRA-C3:10.7 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule10.7" */
            len -= BIGBLOCKSIZE;
        }

        /* Copy one uint32 word at a time if possible. */
        /* polyspace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_LOOP_BOUNDARY" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
        while( len >= LITTLEBLOCKSIZE )
        {
            /* polyspace +1 MISRA-C3:13.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule13.3" */
            *alignedDst++ = *alignedSrc++;  /* PRQA S 3440 */ /* NSCA_QAC_NeuLib_Rule13.3 */
            len -= LITTLEBLOCKSIZE;
        }

        /* Pick up any residual with a byte copier. */
        dst = (uint8*)alignedDst;  /* PRQA S 0310 */ /* NSCA_QAC_NeuLib_Rule11.3 */
        src = (const uint8*)alignedSrc;  /* PRQA S 0310 */ /* NSCA_QAC_NeuLib_Rule11.3 */
    }
    /* polyspace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_LOOP_BOUNDARY" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
    while( len > NEULIB_CNT_0 )
    {
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:13.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule13.3" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        *dst++ = *src++;  /* PRQA S 3440 */ /* NSCA_QAC_NeuLib_Rule13.3 */
        len--;
    }
}

/*
********************************************************************************
* Function Name: NeuLib_memset
*
* Explanation:   Memory set value.
* (Synchronous)
*
* param:         dstPtr DstPtr data pointer.
*                value  Set value.
*                len    Copy total length.
*
* retval:        None
********************************************************************************
*/
FUNC(void, NEULIB_CODE) NeuLib_memset(  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
    volatile P2VAR(void, AUTOMATIC, NEULIB_APPL_DATA) dstPtr,
    uint8 value,
    CONST(uint32, NEULIB_CONST) len
)
{
    uint32 remSize;
#if (NEULIB_MEM_OPERATION_OPTIMIZATION != STD_ON)
    uint8 *u8DstPtr = (uint8 *)dstPtr;
#endif  /* (NEULIB_MEM_OPERATION_OPTIMIZATION == STD_ON) */

    NeuLib_CheckDetReturnVoid(dstPtr != NULL_PTR, NEULIB_SID_MEM_SET, NEULIB_E_PARAM_POINTER);

    remSize = len;
#if (NEULIB_MEM_OPERATION_OPTIMIZATION == STD_ON)

    /* If less than 32 bytes have to be initialized. */
    if (remSize < NEULIB_MEMCOPY_32_BYTE)
    {
        /* Use a byte-wise algorithm. */
        /* polyspace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule11.8" */
        NeuLib_MemSet_8_31((uint8 *)dstPtr, value, (uint8)(remSize & NEULIB_MEMCOPY_MASK_31));  /* PRQA S 0316, 0312 */ /* NSCA_QAC_NeuLib_Rule11.5, NSCA_QAC_NeuLib_Rule11.8 */
    }
    else
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Get the destination pointer offset to the next 32-bit boundary */
        /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_NeuLib_UNMODIFIED_VAR_NOT_CONST" */
        uint8 dstOffset = MEM_ALIGN_OFFSET(dstPtr);  /* PRQA S 4461, 0303  */ /* NSCA_QAC_NeuLib_Rule10.3, NSCA_QAC_NeuLib_Rule11.4 */

        /* If the destination is not aligned. */
        if (dstOffset != NEULIB_SHIFT_0)
        {
            /* Initialize the amount of bytes to reach the boundary on 'dstPtr' and adjust the pointer */
            /* polyspace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule11.8" */
            NeuLib_MemSet_8_3((uint8 *)dstPtr, value, dstOffset);  /* PRQA S 0316, 0312 */ /* NSCA_QAC_NeuLib_Rule11.5, NSCA_QAC_NeuLib_Rule11.8 */
            /* polyspace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule11.8" polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            dstPtr = &((uint8 *)dstPtr)[dstOffset];  /* PRQA S 0316, 0312 */ /* NSCA_QAC_NeuLib_Rule11.5, NSCA_QAC_NeuLib_Rule11.8 */
            remSize -= dstOffset;
        }

        /* The pointer is aligned, use the 32-bit aligned std_memset. */
        /* polyspace +1 MISRA-C3:11.8 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule11.8" */
        NeuLib_MemSet_32_Aligned((uint32 *)dstPtr, value, remSize);  /* PRQA S 0316, 0312 */ /* NSCA_QAC_NeuLib_Rule11.5, NSCA_QAC_NeuLib_Rule11.8 */
    }
#else   /* (NEULIB_MEM_OPERATION_OPTIMIZATION == STD_ON) */

    while (remSize--)
    {
        *u8DstPtr = value;
        u8DstPtr++;
    }
#endif  /* (NEULIB_MEM_OPERATION_OPTIMIZATION == STD_ON) */
}

/*
********************************************************************************
* Function Name: NeuLib_memcmp
*
* Explanation:   This function will compare two areas of memory.
* (Synchronous)
*
* param:         dstPtr One area of memory.
*                srcPtr Another area of memory.
*                count  The size of the area
*
* retval:        When dstPtr < srcPtr, the return value is <0 FALSE.
*                When dstPtr = srcPtr, the return value = TRUE
*                When dstPtr > srcPtr, the return value is> 0 FALSE.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:15.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule15.5" */
FUNC(boolean, NEULIB_CODE) NeuLib_memcmp(  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
    P2CONST(void, AUTOMATIC, NEULIB_APPL_CONST) dstPtr,
    P2CONST(void, AUTOMATIC, NEULIB_APPL_CONST) srcPtr,
    uint32 count
)
{
    P2CONST(uint8, AUTOMATIC, NEULIB_APPL_CONST) dst;
    P2CONST(uint8, AUTOMATIC, NEULIB_APPL_CONST) src;

    /* Pointer check. */
    NeuLib_CheckDetReturnValue(dstPtr != NULL_PTR, NEULIB_SID_MEM_CMP, NEULIB_E_PARAM_POINTER, FALSE);
    NeuLib_CheckDetReturnValue(srcPtr != NULL_PTR, NEULIB_SID_MEM_CMP, NEULIB_E_PARAM_POINTER, FALSE);
    NeuLib_CheckDetReturnValue(count > NEULIB_CNT_0, NEULIB_SID_MEM_CMP, NEULIB_E_PARAM_POINTER, FALSE);

    dst = (const uint8 *)dstPtr;  /* PRQA S 0316 */ /* NSCA_QAC_NeuLib_Rule11.5 */
    src = (const uint8 *)srcPtr;  /* PRQA S 0316 */ /* NSCA_QAC_NeuLib_Rule11.5 */
    /* polyspace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_LOOP_BOUNDARY" polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
    for (; count > NEULIB_CNT_0; count--)
    {
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
        if (*dst != *src)
        {
            return FALSE;
        }

        /* Move memory. */
        dst++;
        src++;
    }

    return TRUE;
}

/*
********************************************************************************
* Function Name: NeuLib_memmove
*
* Explanation:   This function will move memory content from source address to destination address.
* (Synchronous)
*
* param:         dstPtr The address of destination memory.
*                srcPtr The address of source memory.
*                count  The copied length.
*
* retval:        None
********************************************************************************
*/
FUNC_P2VAR(void, NEULIB_APPL_DATA, NEULIB_CODE) NeuLib_memmove(  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
    P2VAR(void, AUTOMATIC, NEULIB_APPL_DATA) dstPtr,
    P2CONST(void, AUTOMATIC, NEULIB_APPL_CONST) srcPtr,
    uint32 count
)
{
    const sint8 *s;
    sint8 *tmp;

    NeuLib_CheckDetReturnVoid(dstPtr != NULL_PTR, NEULIB_SID_MEM_MOVE, NEULIB_E_PARAM_POINTER);
    NeuLib_CheckDetReturnVoid(srcPtr != NULL_PTR, NEULIB_SID_MEM_MOVE, NEULIB_E_PARAM_POINTER);
    NeuLib_CheckDetReturnVoid(count != 0u, NEULIB_SID_MEM_MOVE, NEULIB_E_PARAM_POINTER);

    /* polyspace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
    tmp = (sint8 *)dstPtr;  /* PRQA S 0316 */ /* NSCA_QAC_NeuLib_Rule11.5 */
    s = (const sint8 *)srcPtr;  /* PRQA S 0316 */ /* NSCA_QAC_NeuLib_Rule11.5 */

    /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 MISRA-C3:18.4 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerArithmetic" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
    if( (s < tmp) && (tmp < (s + count)) )  /* PRQA S 0488 */ /* NSCA_QAC_NeuLib_Rule18.4 */
    {
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 MISRA-C3:18.4 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerArithmetic" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
        tmp += count;  /* PRQA S 0488 */ /* NSCA_QAC_NeuLib_Rule18.4 */
        /* polyspace +1 MISRA-C3:18.4 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerArithmetic" */
        s += count;  /* PRQA S 0488 */ /* NSCA_QAC_NeuLib_Rule18.4 */
        /* polyspace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_LOOP_BOUNDARY" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
        while( count > NEULIB_CNT_0 )
        {
            /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:13.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule13.3" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
            *(--tmp) = *(--s);  /* PRQA S 3440 */ /* NSCA_QAC_NeuLib_Rule13.3 */
            /* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            count--;
        }
    }
    else
    {
        /* polyspace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_LOOP_BOUNDARY" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
        while( count > NEULIB_CNT_0 )
        {
            /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:13.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule13.3" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
            *tmp++ = *s++;  /* PRQA S 3440 */ /* NSCA_QAC_NeuLib_Rule13.3 */
            /* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
            count--;
        }
    }

    return dstPtr;
}

/*
********************************************************************************
* Function Name: NeuLib_strlen
*
* Explanation:   This function will return the length of a string, which terminate
                 will null character.
* (Synchronous)
*
* param:         str The string to be calculated.
*
* retval:        String length (not 0).
********************************************************************************
*/
FUNC(uint32, NEULIB_CODE) NeuLib_strlen(  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
    P2CONST(char, AUTOMATIC, NEULIB_APPL_CONST) str
)
{
    const char* sc;
    NeuLib_CheckDetReturnValue(str != NULL_PTR, NEULIB_SID_STR_LEN, NEULIB_E_PARAM_POINTER, 0);

    /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:14.2 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule14.2" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
    for (sc = str; *sc != '\0'; ++sc)
    {
        /* Do nothing. */
    }

    /* Return length. */
    /* polyspace +1 MISRA-C3:10.8 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
    return (uint32)(sc - str);  /* PRQA S 0488 */ /* NSCA_QAC_NeuLib_Rule18.4 */
}

/*
********************************************************************************
* Function Name: NeuLib_strcmp
*
* Explanation:   Compares the string pointed to by str1 with the string pointed to by str2.
* (Synchronous)
*
* param:         str1 The first string to compare against.
*                str2 The second string to compare against.
*
* retval:        If the return value is less than 0, it means str1 is less than str2.
*                If the return value is greater than 0, it means str1 is greater than str2.
*                If the return value is equal to 0, it means str1 is equal to str2.
********************************************************************************
*/
FUNC(sint8, NEULIB_CODE) NeuLib_strcmp(  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
    P2CONST(char, AUTOMATIC, NEULIB_APPL_CONST) str1,
    P2CONST(char, AUTOMATIC, NEULIB_APPL_CONST) str2
)
{
    /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
    while ((*str1 != '\0') && (*str1 == *str2))
    {
        /* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
        str1++;
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
        str2++;
    }

    /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:OVFL [Justified:Unset] "NSCA_Polyspace_NeuLib_Overflow" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 MISRA-C3:10.8 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" */
    return (sint8)(*str1 - *str2);
}

/*
********************************************************************************
* Function Name: NeuLib_strncmp
*
* Explanation:   Compare str1 and str2, at most the first n bytes.
* (Synchronous)
*
* param:         str1 The first string to compare against.
*                str2 The second string to compare against.
*                cnt  The maximum number of characters to compare.
*
* retval:        If the return value < 0, it means str1 is less than str2.
*                If the return value > 0, it means str1 is greater than str2.
*                If the return value = 0, it means str1 is equal to str2.
********************************************************************************
*/
FUNC(sint8, NEULIB_CODE) NeuLib_strncmp (  /* PRQA S 1503 */ /* NSCA_QAC_Common_Unreachable */
    P2CONST(char, AUTOMATIC, NEULIB_APPL_CONST) str1,
    P2CONST(char, AUTOMATIC, NEULIB_APPL_CONST) str2,
    uint32 cnt
)
{
    sint8 retVal;
    NeuLib_CheckDetReturnValue(str1 != NULL_PTR, NEULIB_SID_STR_NCMP, NEULIB_E_PARAM_POINTER, -1);
    NeuLib_CheckDetReturnValue(str2 != NULL_PTR, NEULIB_SID_STR_NCMP, NEULIB_E_PARAM_POINTER, -1);

    if (NEULIB_CNT_0 == cnt)
    {
        retVal = (sint8)NEULIB_CNT_0;
    }
    else
    {
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 DEFECT:TAINTED_LOOP_BOUNDARY [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_LOOP_BOUNDARY" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" polyspace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule10.1" polyspace +1 MISRA-C3:13.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule13.3" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
        while(--cnt && *str1 && (*str1 == *str2))  /* PRQA S 3440, 4518, 4558 */ /* NSCA_QAC_NeuLib_Rule13.3, NSCA_QAC_NeuLib_Rule10.1 */
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
            str1++;
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
            str2++;
        }
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 RTE:OVFL [Justified:Unset] "NSCA_Polyspace_NeuLib_Overflow" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" polyspace +1 MISRA-C3:10.8 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" */
        retVal = (sint8)(*str1 - *str2);
    }

    return retVal;
}

#define NEULIB_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

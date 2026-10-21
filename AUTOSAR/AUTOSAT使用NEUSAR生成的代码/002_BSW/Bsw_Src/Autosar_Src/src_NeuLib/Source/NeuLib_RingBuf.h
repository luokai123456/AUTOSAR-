/*
********************************************************************************
*
* File name: NeuLib_RingBuf.h
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
* Author/Date: ChenQJ/2023.08.25
* Change: Modify ptrclass definition of NeuLibRb_OutPtrForOffset() and tag name
*         of NeuLibRingBuffer_Type.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: TianG/2024.10.12
* Change: 1.Add a memory-map label to function.
*         2.Modify copyright.
*         3.Modify FUNC_P2VAR error.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: KangJH/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: KangJH/2025.05.22
* Change: Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
* Cause: Update
********************************************************************************
*/
#ifndef NEULIB_RING_BUFFER_H_
#define NEULIB_RING_BUFFER_H_

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

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#ifndef NEULIB_RB_SIZE_TYPE
#define NEULIB_RB_SIZE_TYPE         uint32
#endif  /* NEULIB_RB_SIZE_TYPE */

/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_SCOPE_EXTERN
#define NEULIB_SCOPE_STATIC         static
/**
 * \name NEULIB_RB_DECLARE_XXX
 * \brief
 * It is used to define a circular queue and needs to be used together. Use routine:
 *
 * #define NEULIB_START_SEC_VAR_NO_INIT
 * #include "NeuLib_MemMap.h"
 * NEULIB_RB_DECLARE_BUF(eg, NEULIB, uint8, 1024);
 * #define NEULIB_STOP_SEC_VAR_NO_INIT
 * #include "NeuLib_MemMap.h"
 *
 * #define NEULIB_START_SEC_VAR_INIT
 * #include "NeuLib_MemMap.h"
 * NEULIB_RB_DECLARE_VARIANT(eg, NEULIB);
 * #define NEULIB_STOP_SEC_VAR_INIT
 * #include "NeuLib_MemMap.h"
 *
 * #define NEULIB_START_SEC_CONST
 * #include "NeuLib_MemMap.h"
 * NEULIB_RB_DECLARE_OBJECT(eg, NEULIB, uint8, NEULIB_SCOPE_STATIC);
 * #define NEULIB_STOP_SEC_CONST
 * #include "NeuLib_MemMap.h"
 *
 * \{
 */
/** \brief Defines the memory area for the ring buffer. */
/* polyspace-begin MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
/* polyspace-begin MISRA-C3:20.10 [Justified:Unset] "NSCA_Polyspace_Common_Rule20.10" */
/* MD_MSR_Rule20.10_0342 */
#define NEULIB_RB_DECLARE_BUF(_name, _memName, _type, _size)                            \
        static VAR(_type, _memName##_VAR_NO_INIT) NeuRbBuf_##_name[(((_size) + 3U) & ~3U) + sizeof(_type)];  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */

/** \brief Define a variant of the ring buffer. */
/* MD_MSR_Rule20.10_0342 */
#define NEULIB_RB_DECLARE_VARIANT(_name, _memName)                                      \
        static VAR(NeuRingBufferVariant_Type, _memName##_VAR_INIT) NeuRbV_##_name = {   \
            /* in  */ sizeof(NeuRbBuf_##_name) - 1,                                     \
            /* out */ sizeof(NeuRbBuf_##_name) - 1                                      \
        };  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */

/**
 * \brief The entity of the ring buffer.
 * \note _scope must used NEULIB_SCOPE_EXTERN or NEULIB_SCOPE_STATIC
 */
/* MD_MSR_Rule20.10_0342 */
#define NEULIB_RB_DECLARE_OBJECT(_name, _memName, _type, _scope)                        \
        (_scope) CONST(NeuLibRingBuffer_Type, _memName##_CONST) NeuRb_##_name = {            \
            /* buffer  */ (void *)NeuRbBuf_##_name,                                     \
            /* variant */ &NeuRbV_##_name,                                              \
            /* min     */ sizeof(_type),                                                \
            /* max     */ sizeof(NeuRbBuf_##_name)                                      \
        }  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
/** \} */

/* MD_MSR_Rule20.10_0342 */
#define NEULIB_RB_REF(_name)                    NeuRb_##_name  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
/* MD_MSR_Rule20.10_0342 */
#define NEULIB_RB_EXTERN(_name, _memName)       extern CONST(NeuLibRingBuffer_Type, _memName##_CONST) NeuRb_##_name;  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
#define NEULIB_RB_PUSH(_name, _data, _size)     NeuLibRb_Push(&NeuLibRb_##_name, _data, _size)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
#define NEULIB_RB_POLL(_name, _data, _size)     NeuLibRb_Poll(&NeuLibRb_##_name, _data, _size)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
#define NEULIB_RB_DROP(_name, _size)            NeuLibRb_Drop(&NeuLibRb_##_name, _size)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
#define NEULIB_RB_POP(_name, _data, _size)      NeuLibRb_Pop(&NeuLibRb_##_name, _data, _size)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
#define NEULIB_RB_POPROW(_name, _size)          NeuLibRb_PopRow(&NeuLibRb_##_name, _size)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
#define NEULIB_RB_INIT(_name)                   NeuLibRb_Init(&NeuLibRb_##_name)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
#define NEULIB_RB_LEFT(_name)                   NeuLibRb_Left(&NeuLibRb_##_name)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
#define NEULIB_RB_SIZE(_name)                   NeuLibRb_Size(&NeuLibRb_##_name)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
#define NEULIB_RB_INP(_name)                    NeuLibRb_InP(&NeuLibRb_##_name)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
#define NEULIB_RB_OUTP(_name)                   NeuLibRb_OutP(&NeuLibRb_##_name)  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
#define NEULIB_IS_RB_EMPTY(_name)               ((NeuLibRb_##_name.variant->in)==(NeuLibRb_##_name.variant->out))  /* PRQA S 0342 */ /* NSCA_QAC_Common_Rule20.10_0342 */
/* polyspace-end MISRA-C3:20.10 [Justified:Unset] "NSCA_Polyspace_Common_Rule20.10" */
/* polyspace-end MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef NEULIB_RB_SIZE_TYPE NeuLibRbSize_Type;

/* A variant of the circular queue. */
/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct NeuRingBufferVariant_Type_tag
{
    NeuLibRbSize_Type in;
    NeuLibRbSize_Type out;
} NeuRingBufferVariant_Type;

/* Ring buffer data structure. */
/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct NeuLibRingBuffer_Type_tag
{
    /* A pointer to the actual buffer. */
    void*                      buffer;
    /* Dequeue management information for circular queues. */
    NeuRingBufferVariant_Type* variant;
    /**
     * The minimum idle interval in the ring buffer must be greater than 0.
     * The recommended size is the buffer type size, such as sizeof (uint8).
     */
    NeuLibRbSize_Type          min;
    /* Ring buffer maximum depth, fill in the actual value. */
    NeuLibRbSize_Type          max;
} NeuLibRingBuffer_Type;

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
FUNC(void, NEULIB_CODE) NeuLibRb_Init(
    P2CONST(NeuLibRingBuffer_Type, AUTOMATIC, NEULIB_APPL_CONST) rb
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(NeuLibRbSize_Type, NEULIB_CODE) NeuLibRb_Push(
    P2CONST(NeuLibRingBuffer_Type, AUTOMATIC, NEULIB_APPL_CONST) rb,
    P2CONST(void, AUTOMATIC, NEULIB_APPL_DATA) data,
    NeuLibRbSize_Type len
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(NeuLibRbSize_Type, NEULIB_CODE) NeuLibRb_Pop(
    P2CONST(NeuLibRingBuffer_Type, AUTOMATIC, NEULIB_APPL_CONST) rb,
    P2VAR(void, AUTOMATIC, NEULIB_APPL_DATA) data,
    NeuLibRbSize_Type len
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(NeuLibRbSize_Type, NEULIB_CODE) NeuLibRb_Poll(
    P2CONST(NeuLibRingBuffer_Type, AUTOMATIC, NEULIB_APPL_CONST) rb,
    P2VAR(void, AUTOMATIC, NEULIB_APPL_DATA) data,
    NeuLibRbSize_Type len
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(NeuLibRbSize_Type, NEULIB_CODE) NeuLibRb_Drop(
    P2CONST(NeuLibRingBuffer_Type, AUTOMATIC, NEULIB_APPL_CONST) rb,
    NeuLibRbSize_Type len
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(NeuLibRbSize_Type, NEULIB_CODE) NeuLibRb_PopRow(
    P2CONST(NeuLibRingBuffer_Type, AUTOMATIC, NEULIB_APPL_CONST) rb,
    NeuLibRbSize_Type len
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(NeuLibRbSize_Type, NEULIB_CODE) NeuLibRb_Row(
    P2CONST(NeuLibRingBuffer_Type, AUTOMATIC, NEULIB_APPL_CONST) rb,
    NeuLibRbSize_Type len
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(NeuLibRbSize_Type, NEULIB_CODE) NeuLibRb_Left(
    P2CONST(NeuLibRingBuffer_Type, AUTOMATIC, NEULIB_APPL_CONST) rb
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(NeuLibRbSize_Type, NEULIB_CODE) NeuLibRb_Size(
    P2CONST(NeuLibRingBuffer_Type, AUTOMATIC, NEULIB_APPL_CONST) rb
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC_P2VAR(void, NEULIB_APPL_DATA, NEULIB_CODE) NeuLibRb_OutP(
    P2CONST(NeuLibRingBuffer_Type, AUTOMATIC, NEULIB_APPL_CONST) rb
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC_P2VAR(void, NEULIB_APPL_DATA, NEULIB_CODE) NeuLibRb_OutPtrForOffset(
    P2CONST(NeuLibRingBuffer_Type, AUTOMATIC, NEULIB_APPL_CONST) rb,
    uint16 offset
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC_P2VAR(void, NEULIB_APPL_DATA, NEULIB_CODE) NeuLibRb_InP(
    P2CONST(NeuLibRingBuffer_Type, AUTOMATIC, NEULIB_APPL_CONST) rb
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* #ifndef NEULIB_RING_BUFFER_H_ */

/*
********************************************************************************
*
* File name: NeuLib_Service.h
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
*         2.Modify copyright.
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
#ifndef NEU_LIST_H_
#define NEU_LIST_H_

#ifdef __cplusplus
extern "C" {
#endif

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
 * NEULIB_CONTAINER_OF - return the start address of struct type, while ptr is the member of struct type.
 */
/* polyspace +1 MISRA-C3:11.3 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" polyspace +1 MISRA-C3:11.4 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerCast" polyspace +1 MISRA-C3:18.4 [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerArithmetic" polyspace +1 MISRA-C3:11.9 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule11.9" polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" polyspace +1 MISRA-C3:D4.6 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.6" */
#define NEULIB_CONTAINER_OF(_ptr, _type, _member)     ((_type*)((char*)(_ptr) - (unsigned long)(&((_type*)0)->_member)))  /* PRQA S 3410 */ /* NSCA_QAC_NeuLib_Rule20.7 */
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
#define NEULIB_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
********************************************************************************
* Function Name: NeuLibList_Init
*
* Explanation:   Initialize a list.
* (Synchronous)
*
* param:         l list to be initialized
*
* retval:        None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLibList_Init(
    P2VAR(NeuLibList_Type, AUTOMATIC, NEULIB_APPL_DATA) l
)
{
    /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" */
    l->next = l;
    l->prev = l;
}

/*
********************************************************************************
* Function Name: NeuLibList_InsertAfter
*
* Explanation:   Insert a node after a list.
* (Synchronous)
*
* param:         l List to insert it.
*                n New node to be inserted.
*
* retval:        None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLibList_InsertAfter(
    P2VAR(NeuLibList_Type, AUTOMATIC, NEULIB_APPL_DATA) l,
    P2VAR(NeuLibList_Type, AUTOMATIC, NEULIB_APPL_DATA) n
)
{
    /* polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_NeuLib_UninitializedPointer" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
    l->next->prev = n;
    /* polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_NeuLib_UninitializedPointer" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" */
    n->next = l->next;

    l->next = n;
    n->prev = l;
}

/*
********************************************************************************
* Function Name: NeuLibList_Remove
*
* Explanation:   Remove node from list.
* (Synchronous)
*
* param:         n the node to remove from the list.
*
* retval:        None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, NEULIB_CODE) NeuLibList_Remove(
    P2VAR(NeuLibList_Type, AUTOMATIC, NEULIB_APPL_DATA) n
)
{
    /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NeuLib_TAINTED_PTR" polyspace +1 RTE:NIP [Justified:Unset] "NSCA_Polyspace_NeuLib_UninitializedPointer" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.14" polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
    n->next->prev = n->prev;
    /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_NeuLib_PointerOutBounds" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Dir4.1" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NeuLib_Rule18.1" */
    n->prev->next = n->next;

    n->next = n;
    n->prev = n;
}

/*
********************************************************************************
* Function Name: NeuLibList_IsEmpty
*
* Explanation:   Tests whether a list is empty.
* (Synchronous)
*
* param:         l the list to test.
*
* retval:        None
********************************************************************************
*/
LOCAL_INLINE FUNC(Std_ReturnType, NEULIB_CODE) NeuLibList_IsEmpty(
    P2CONST(NeuLibList_Type, AUTOMATIC, NEULIB_APPL_CONST) l
)
{
    return (l->next == l) ? E_OK : E_NOT_OK;
}
#define NEULIB_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
* Function Name: NeuLibList_Entry
*
* Explanation:   Get the struct for this entry.
* (Synchronous)
*
* param:         node   The entry point.
*                type   The type of structure.
*                member The name of list in structure.
*
* retval:        None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define NeuLibList_Entry(node, type, member)  NEULIB_CONTAINER_OF(node, type, member)

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef NEU_LIST_H_ */

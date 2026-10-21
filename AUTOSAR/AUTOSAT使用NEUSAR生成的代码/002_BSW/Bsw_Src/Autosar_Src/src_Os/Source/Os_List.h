/*
********************************************************************************
*
*  File name: Os_List.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCl/2021.11.23
* Change: Add Autosar
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: WangJP/2022.12.10
* Change: Modification of coding standard.
* Cause: Optimize
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
*/
#ifndef OS_LIST_H_
#define OS_LIST_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Error.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* The list node type. */
typedef struct Os_ListNode
{
    struct Os_ListNode* nextNode;
} Os_ListNodeType;

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
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*
********************************************************************************
* Function Name: Os_List_Init
*
* Explanation: List initialization.
*
* Param: headNode: List head node.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_List_Init
(
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) headNode
)
{
    /* Check the headNode is not NULL_PTR. */
    Os_ParamCheck(NULL_PTR != headNode);
    headNode->nextNode = NULL_PTR;
}

/*
********************************************************************************
* Function Name: Os_List_IsEmpty
*
* Explanation: Check if list is empty.
*
* Param: headNode: List head node.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(boolean, OS_CODE) Os_List_IsEmpty
(
    P2CONST(Os_ListNodeType, AUTOMATIC, OS_APPL_CONST) headNode
)
{
    /* Check list is it empty. */
    return ((NULL_PTR == headNode->nextNode) ? TRUE : FALSE);
}

/*
********************************************************************************
* Function Name: Os_List_Push
*
* Explanation: list push node.
*
* Param: headNode: List head node.
*        dataNode: Data node.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_List_Push
(
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) headNode,
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) dataNode
)
{
    /* The list is pushed form the head. */
    dataNode->nextNode = headNode->nextNode;
    headNode->nextNode = dataNode;
}

/*
********************************************************************************
* Function Name: Os_List_Pop
*
* Explanation: list pop node.
*
* Param: headNode: List head node.
*
* Retval: Data node.
********************************************************************************
*/
LOCAL_INLINE FUNC_P2VAR(Os_ListNodeType, OS_APPL_DATA, OS_CODE) Os_List_Pop
(
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) headNode
)
{
    Os_ListNodeType* dataNode = NULL_PTR;
    /* The list is poped form the head. */
    if( FALSE == Os_List_IsEmpty(headNode) )
    {
        dataNode = headNode->nextNode;
        headNode->nextNode = dataNode->nextNode;
    }

    return dataNode;
}

/*
********************************************************************************
* Function Name: Os_List_GetTop
*
* Explanation: list get node.
*
* Param: headNode: List head node.
*
* Retval: Data node.
********************************************************************************
*/
LOCAL_INLINE FUNC_P2VAR(Os_ListNodeType, OS_APPL_DATA, OS_CODE) Os_List_GetTop
(
    P2VAR(Os_ListNodeType, AUTOMATIC, OS_APPL_DATA) headNode
)
{
    /* The list get first node form the head. */
    return headNode->nextNode;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_LIST_H_ */

/*
********************************************************************************
*
*  File name: Os_PriorityQueue.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.23
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: JiangGL/2022.12.26
* Change: Solve the problem of abnormal system scheduling caused by calling
*         cancelAlarm organic rate.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.2.14
* Change: Remove redundant code.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: JiangGL/2024.1.25
* Change: Add Os_PriQueue_Find function.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiG/2024.4.10
* Change: Modifying static code check issues.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_PriorityQueue.h"

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
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(Os_PriQueueSizeType, OS_CODE) Os_PriQueue_FindLowerNode
(
    P2VAR(Os_PriQueueType, AUTOMATIC, OS_APPL_DATA) priQueue,
    Os_PriQueueSizeType node
);

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

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
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*
********************************************************************************
* Function Name: Os_PriQueue_FindLowerNode
*
* Explanation: Priority queue find lower node
*
* Param: priQueue: Priority queue configuration.
*        node: Node value.
*
* Retval: Lower node.
********************************************************************************
*/
static FUNC(Os_PriQueueSizeType, OS_CODE) Os_PriQueue_FindLowerNode
(
    P2VAR(Os_PriQueueType, AUTOMATIC, OS_APPL_DATA) priQueue,
    Os_PriQueueSizeType node
)
{
    Os_PriQueueSizeType retNode;
    Os_PriQueueSizeType leftNode;
    Os_PriQueueNodeType* leftNodeValue;
    Os_PriQueueNodeType* rightNodeValue;

    /* Get left node number. */
    leftNode = ((Os_PriQueueSizeType)((node + OS_PRIQUEUE_VALUE_ONE) << OS_PRIQUEUE_VALUE_ONE) - OS_PRIQUEUE_VALUE_ONE);
    /* If there is no left node. */
    if( (Os_PriQueueSizeType)((node + OS_PRIQUEUE_VALUE_ONE) << OS_PRIQUEUE_VALUE_ONE) > priQueue->priQueueUseCounter )
    {
        retNode = node;
    }
    /* If there is no right node. */
    else if( (Os_PriQueueSizeType)((node + OS_PRIQUEUE_VALUE_ONE) << OS_PRIQUEUE_VALUE_ONE) == priQueue->priQueueUseCounter )
    {
        retNode = leftNode;
    }
    else
    {
        retNode = leftNode;
        leftNodeValue = priQueue->priQueueNode[leftNode];
        rightNodeValue = priQueue->priQueueNode[leftNode + OS_PRIQUEUE_VALUE_ONE];
        /* If the value of the left node is greater than the value of the right node. */
        if( (leftNodeValue->timebase) > (rightNodeValue->timebase) )
        {
            retNode++;
        }
    }

    return retNode;
}

/*
********************************************************************************
* Function Name: Os_PriQueue_Init
*
* Explanation: Priority queue initialization.
*
* Param: priQueue: Priority queue configuration.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_PriQueue_Init
(
    P2VAR(Os_PriQueueType, AUTOMATIC, OS_APPL_DATA) priQueue
)
{
    Os_PriQueueSizeType index;

    /* Initialize usage amount. */
    priQueue->priQueueUseCounter = OS_PRIQUEUE_INIT;
    /* Initialize queue data. */
    for( index = OS_PRIQUEUE_INIT; index < priQueue->priQueueSize; index++ )
    {
        priQueue->priQueueNode[index] = NULL_PTR;
    }
}

/*
********************************************************************************
* Function Name: Os_PriQueue_PUSH
*
* Explanation: Priority queue push node.
*
* Param: priQueue: Priority queue configuration.
*        nodeValue: node value.
*
* Retval: E_OS_OK: No error.
*         E_OS_BUFFFULL: Queue buffer is full.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_PriQueue_PUSH
(
    P2VAR(Os_PriQueueType, AUTOMATIC, OS_APPL_DATA) priQueue,
    P2VAR(Os_PriQueueNodeType, AUTOMATIC, OS_APPL_DATA) nodeValue
)
{
    Os_StatusType ret = E_OS_OK;
    Os_TickType upTimebase;
    Os_PriQueueSizeType upNode;
    Os_PriQueueSizeType currentNode;

    if( priQueue->priQueueUseCounter != priQueue->priQueueSize )
    {
        /* If it is not the root node. */
        if( priQueue->priQueueUseCounter != OS_PRIQUEUE_INIT )
        {
            /* Set the current node as the last node. */
            currentNode = priQueue->priQueueUseCounter;
            /* Exchange current node and upper node data. */
            priQueue->priQueueNode[currentNode] = nodeValue;
            /* Find the upper node. */
            upNode = (Os_PriQueueSizeType)((priQueue->priQueueUseCounter - OS_PRIQUEUE_VALUE_ONE) >> OS_PRIQUEUE_VALUE_ONE);
            /* Find the upper node data. */
            upTimebase = priQueue->priQueueNode[upNode]->timebase;
            /* Loop to find where to insert data. */
            while( upTimebase > nodeValue->timebase )
            {
                /* Exchange current node and upper node data. */
                priQueue->priQueueNode[currentNode] = priQueue->priQueueNode[upNode];
                /* Update upper node data. */
                priQueue->priQueueNode[upNode] = nodeValue;
                /* Now the current node is set as upper node. */
                currentNode = upNode;
                if( OS_PRIQUEUE_INIT == upNode )
                {
                    break;
                }
                /* Update new upper node. */
                upNode = (Os_PriQueueSizeType)((upNode - OS_PRIQUEUE_VALUE_ONE) >> OS_PRIQUEUE_VALUE_ONE);
                /* Update new upper node data. */
                upTimebase = priQueue->priQueueNode[upNode]->timebase;
            }
        }
        else
        {
            /* Insert to the root node. */
            priQueue->priQueueNode[priQueue->priQueueUseCounter] = nodeValue;
        }
        /* Increase user counter. */
        priQueue->priQueueUseCounter++;
    }
    else
    {
        ret = E_OS_BUFFFULL;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_PriQueue_POP
*
* Explanation: Priority queue pop node.
*
* Param: priQueue: Priority queue configuration.
*        nodeValue: Node value.
*
* Retval: E_OS_OK: No error.
*         E_OS_BUFFEMPTY: Queue buffer is empty.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_PriQueue_POP
(
    P2VAR(Os_PriQueueType, AUTOMATIC, OS_APPL_DATA) priQueue,
    P2VAR(Os_PriQueueNodeType*, AUTOMATIC, OS_APPL_DATA) nodeValue
)
{
    Os_StatusType ret = E_OS_OK;
    Os_PriQueueSizeType lowerNode;
    Os_PriQueueSizeType currentNode;
    Os_PriQueueNodeType* tempNode;

    if( priQueue->priQueueUseCounter != OS_PRIQUEUE_INIT )
    {
        /* Pop the root node value. */
        *nodeValue = priQueue->priQueueNode[OS_PRIQUEUE_INIT];
        /* Update lower node. */
        lowerNode = Os_PriQueue_FindLowerNode(priQueue, OS_PRIQUEUE_INIT);
        /* Update current node. */
        currentNode = (Os_PriQueueSizeType)(priQueue->priQueueUseCounter - OS_PRIQUEUE_VALUE_ONE);
        /* Copy the last node data to the root node. */
        priQueue->priQueueNode[OS_PRIQUEUE_INIT] = priQueue->priQueueNode[currentNode];
        /* Update the current node. */
        currentNode = OS_PRIQUEUE_INIT;

        while( priQueue->priQueueNode[lowerNode]->timebase < priQueue->priQueueNode[currentNode]->timebase )
        {
            tempNode = priQueue->priQueueNode[currentNode];
            /* Copy the lower node data to the current node. */
            priQueue->priQueueNode[currentNode] = priQueue->priQueueNode[lowerNode];
            priQueue->priQueueNode[lowerNode] = tempNode;
            /* Update current node. */
            currentNode = lowerNode;
            /* Update lower node. */
            lowerNode = Os_PriQueue_FindLowerNode(priQueue, currentNode);
        }
        /* Decrease user counter. */
        priQueue->priQueueUseCounter--;
    }
    else
    {
        ret = E_OS_BUFFEMPTY;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_PriQueue_Del
*
* Explanation: Priority queue delete node.
*
* Param: priQueue: Priority queue configuration.
*        nodeValue: Node value.
*
* Retval: E_OS_OK: No error.
*         E_OS_NODATA: Queue buffer is empty.
*         E_OS_BUFFEMPTY: Queue buffer is full.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_PriQueue_Del
(
    P2VAR(Os_PriQueueType, AUTOMATIC, OS_APPL_DATA) priQueue,
    P2VAR(Os_PriQueueNodeType, AUTOMATIC, OS_APPL_DATA) nodeValue
)
{
    Os_StatusType ret = E_OS_OK;
    Os_PriQueueSizeType index;
    Os_PriQueueSizeType lowerNode;
    Os_PriQueueSizeType currentNode;
    Os_PriQueueNodeType* tempNode;

    if( priQueue->priQueueUseCounter != OS_PRIQUEUE_INIT )
    {
        /* Find the node to delete. */
        for( index = OS_PRIQUEUE_INIT; index < priQueue->priQueueUseCounter; index++ )
        {
            /* If the node is found. */
            if( nodeValue == priQueue->priQueueNode[index] )
            {
                break;
            }
        }
        /* If the node is found. */
        if( index != priQueue->priQueueUseCounter )
        {
            /* Update lower node. */
            lowerNode = Os_PriQueue_FindLowerNode(priQueue, index);
            /* Update current node. */
            currentNode = (Os_PriQueueSizeType)(priQueue->priQueueUseCounter - OS_PRIQUEUE_VALUE_ONE);
            /* Copy the last node data to the root node. */
            priQueue->priQueueNode[index] = priQueue->priQueueNode[currentNode];
            /* Update the current node. */
            currentNode = index;

            if( priQueue->priQueueNode[lowerNode]->timebase < priQueue->priQueueNode[currentNode]->timebase )
            {
                while( priQueue->priQueueNode[lowerNode]->timebase < priQueue->priQueueNode[currentNode]->timebase )
                {
                    tempNode = priQueue->priQueueNode[currentNode];
                    /* Copy the lower node data to the current node. */
                    priQueue->priQueueNode[currentNode] = priQueue->priQueueNode[lowerNode];
                    priQueue->priQueueNode[lowerNode] = tempNode;
                    /* Update current node. */
                    currentNode = lowerNode;
                    /* Update lower node. */
                    lowerNode = Os_PriQueue_FindLowerNode(priQueue, currentNode);
                }
            }
            else
            {
                if( (priQueue->priQueueNode[lowerNode]->timebase > priQueue->priQueueNode[currentNode]->timebase) || (lowerNode == currentNode) )
                {
                    /* if delete node isn't zore node */
                    if( OS_PRIQUEUE_INIT != currentNode)
                    {
                        Os_PriQueueSizeType upNode = (Os_PriQueueSizeType)((currentNode - OS_PRIQUEUE_VALUE_ONE) >> OS_PRIQUEUE_VALUE_ONE);
                        Os_TickType upTimebase = priQueue->priQueueNode[upNode]->timebase;
                        nodeValue = priQueue->priQueueNode[currentNode];
                        while( upTimebase > nodeValue->timebase )
                        {
                            /* Exchange current node and upper node data. */
                            priQueue->priQueueNode[currentNode] = priQueue->priQueueNode[upNode];
                            /* Update upper node data. */
                            priQueue->priQueueNode[upNode] = nodeValue;
                            /* Now the current node is set as upper node. */
                            currentNode = upNode;
                            if( OS_PRIQUEUE_INIT == upNode )
                            {
                                break;
                            }
                            /* Update new upper node. */
                            upNode = (Os_PriQueueSizeType)((upNode - OS_PRIQUEUE_VALUE_ONE) >> OS_PRIQUEUE_VALUE_ONE);
                            /* Update new upper node data. */
                            upTimebase = priQueue->priQueueNode[upNode]->timebase;
                        }
                    }
                }
            }
            /* Decrease user counter. */
            priQueue->priQueueUseCounter--;
        }
        else
        {
            ret = E_OS_NODATA;
        }
    }
    else
    {
        ret = E_OS_BUFFEMPTY;
    }

    return ret;
}

/*
********************************************************************************
* Function Name: Os_PriQueue_Find
*
* Explanation: Priority queue find node.
*
* Param: priQueue: Priority queue configuration.
*        nodeValue: Node value.
*
* Retval: E_OS_OK: No error.
*         E_OS_NODATA: Queue buffer is empty.
*         E_OS_BUFFEMPTY: Queue buffer is full.
********************************************************************************
*/
FUNC(Os_StatusType, OS_CODE) Os_PriQueue_Find
(
    P2CONST(Os_PriQueueType, AUTOMATIC, OS_APPL_DATA) priQueue,
    P2CONST(Os_PriQueueNodeType, AUTOMATIC, OS_APPL_DATA) nodeValue
)
{
    Os_StatusType ret;
    Os_PriQueueSizeType index;

    if( priQueue->priQueueUseCounter != OS_PRIQUEUE_INIT )
    {
        ret = E_OS_NODATA;
        /* Searching for nodes from the queue. */
        for( index = OS_PRIQUEUE_INIT; index < priQueue->priQueueUseCounter; index++ )
        {
            /* If the node is found. */
            if( nodeValue == priQueue->priQueueNode[index] )
            {
                ret = E_OS_OK;
                break;
            }
        }
    }
    else
    {
        ret = E_OS_BUFFEMPTY;
    }

    return ret;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

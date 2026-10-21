/*
********************************************************************************
*
*  File name: Os_PriorityQueue.h
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
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.11.21
* Change: Change OS_VAR_NOINIT to OS_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: JiangGL/2024.1.25
* Change: Add function declarations for Os_PriQueue_Find.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: LiG/2024.4.10
* Change: Modifying static code check issues.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
*/
#ifndef OS_PRIORITYQUEUE_H_
#define OS_PRIORITYQUEUE_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Priority queue initial zero value. */
#define OS_PRIQUEUE_INIT                        (0U)
/* Priority queue initial one value. */
#define OS_PRIQUEUE_VALUE_ONE                   (1U)
/* Get priority queue node value. */
#define OS_GETPRIQUEUE_VALUE(priQueueNodeHead)  ((priQueueNodeHead).priQueueNode[0U]->timebase)
/* Determine priority queue is empty. */
#define OS_PRIQUEUEISNOTEMPTY(priQueueNodeHead) ((priQueueNodeHead).priQueueUseCounter != OS_PRIQUEUE_INIT)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef uint16 Os_PriQueueSizeType;

typedef struct{
    Os_TickType timebase;
} Os_PriQueueNodeType;

typedef struct{
    Os_PriQueueNodeType** priQueueNode;
    Os_PriQueueSizeType priQueueUseCounter;
    Os_PriQueueSizeType priQueueSize;
} Os_PriQueueType;

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
extern FUNC(void, OS_CODE) Os_PriQueue_Init
(
    P2VAR(Os_PriQueueType, AUTOMATIC, OS_APPL_DATA) priQueue
);
extern FUNC(Os_StatusType, OS_CODE) Os_PriQueue_PUSH
(
    P2VAR(Os_PriQueueType, AUTOMATIC, OS_APPL_DATA) priQueue,
    P2VAR(Os_PriQueueNodeType, AUTOMATIC, OS_APPL_DATA) nodeValue
);
extern FUNC(Os_StatusType, OS_CODE) Os_PriQueue_POP
(
    P2VAR(Os_PriQueueType, AUTOMATIC, OS_APPL_DATA) priQueue,
    P2VAR(Os_PriQueueNodeType*, AUTOMATIC, OS_APPL_DATA) nodeValue
);
extern FUNC(Os_StatusType, OS_CODE) Os_PriQueue_Del
(
    P2VAR(Os_PriQueueType, AUTOMATIC, OS_APPL_DATA) priQueue,
    P2VAR(Os_PriQueueNodeType, AUTOMATIC, OS_APPL_DATA) nodeValue
);
extern FUNC(Os_StatusType, OS_CODE) Os_PriQueue_Find
(
    P2CONST(Os_PriQueueType, AUTOMATIC, OS_APPL_DATA) priQueue,
    P2CONST(Os_PriQueueNodeType, AUTOMATIC, OS_APPL_DATA) nodeValue
);

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_PRIORITYQUEUE_H_ */

/*
********************************************************************************
*
*  File name: Os_Arch_Exception_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: JiangGL/2025.6.25
* Change: New create.
* Cause: New
********************************************************************************
*/
#ifndef OS_ARCH_EXCEPTION_TYPES_H_
#define OS_ARCH_EXCEPTION_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Arch_Core.h"
#include "Os_Platform_Lcfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Exception error information recording supports macro switches. */
#define OS_ARCH_EXCEPTION_ERRIMFORMATION        (STD_ON)

#if( OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON )
/* Define CAT1 max number. */
#define OS_ARCH_CAT1_ISR_MAX_NUM                (0U)

#ifdef OS_CFG_NUM_CAT1ISR_OSCORE0
#undef OS_ARCH_CAT1_ISR_MAX_NUM
#define OS_ARCH_CAT1_ISR_MAX_NUM    OS_CFG_NUM_CAT1ISR_OSCORE0
#endif /* OS_CFG_NUM_CAT1ISR_OSCORE0 */

#ifdef OS_CFG_NUM_CAT1ISR_OSCORE1
#if( OS_CFG_NUM_CAT1ISR_OSCORE1 > OS_ARCH_CAT1_ISR_MAX_NUM )
#undef OS_ARCH_CAT1_ISR_MAX_NUM
#define OS_ARCH_CAT1_ISR_MAX_NUM    OS_CFG_NUM_CAT1ISR_OSCORE1
#endif /* OS_CFG_NUM_CAT1ISR_OSCORE1 > OS_ARCH_CAT1_ISR_MAX_NUM */
#endif /* OS_CFG_NUM_CAT1ISR_OSCORE1 */

#ifdef OS_CFG_NUM_CAT1ISR_OSCORE2
#if( OS_CFG_NUM_CAT1ISR_OSCORE2 > OS_ARCH_CAT1_ISR_MAX_NUM )
#undef OS_ARCH_CAT1_ISR_MAX_NUM
#define OS_ARCH_CAT1_ISR_MAX_NUM    OS_CFG_NUM_CAT1ISR_OSCORE2
#endif /* OS_CFG_NUM_CAT1ISR_OSCORE2 > OS_ARCH_CAT1_ISR_MAX_NUM */
#endif /* OS_CFG_NUM_CAT1ISR_OSCORE2 */

/* CAT1 ISR and CAT2 ISR max sum. */
#define OS_ARCH_ISR_MAX_NUM    (OS_ARCH_CAT1_ISR_MAX_NUM + (uint32)OS_ISRID_COUNT)

/* Get the stack start address of the core kernal configuration. */
#define OS_ARCH_CORE_GETSTACKSTARTADDR(coreId)          \
    ((uint32)(Os_CoreCfgData[coreId]->contextCfg->stackStartAddr))
/* Critical input exception. */
#define OS_ARCH_EXCEPTION_CRITICALINPUT         (0x01)
/* MachineCheck exception. */
#define OS_ARCH_EXCEPTION_MACHINECHECK          (0x02)
/* Data access exception. */
#define OS_ARCH_EXCEPTION_DATA                  (0x03)
/* Instruction exception. */
#define OS_ARCH_EXCEPTION_INSTRUCTION           (0x04)
/* Alignment exception. */
#define OS_ARCH_EXCEPTION_ALIGNMENT             (0x06)
/* Program exception. */
#define OS_ARCH_EXCEPTION_PROGRAM               (0x07)
/* Performance monitor exception. */
#define OS_ARCH_EXCEPTION_PERFORMANCEMONITOR    (0x08)
/* Debug monitor exception. */
#define OS_ARCH_EXCEPTION_DEBUG                 (0x0A)
/* Embedded Floating-point Data exception. */
#define OS_ARCH_EXCEPTION_EFPU_DATA             (0x0B)
/* Embedded Floating-point Round exception. */
#define OS_ARCH_EXCEPTION_EFPU_ROUND            (0x0C)
/* TBD exception. */
#define OS_ARCH_EXCEPTION_EFPU_TBD              (0x0D)

#endif /* OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* Function pointer data type for call cat1 isr callabck. */
typedef P2FUNC(void, OS_CODE, Os_Arch_Cat1HandlerType)(void);

#if( OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON )
/* The data type of core status when an exception occurs. */
typedef struct
{
    /* PC pointer before generating an exception. */
    uint32 pcAddress;
    /* Address of the data that generated the exception. */
    uint32 excDataAddress;
    /* Record the number of interrupt nesting levels. */
    uint32 isrNestCnt;
    /* The address of the interrupt service function stored in this pointer. */
    uint32 isrFuncAddress[OS_ARCH_ISR_MAX_NUM];
    /* Interrupt priority mask before exception generation. */
    uint32 intPriorityMask;
    /* The state of the global interrupt switch before generating an exception. */
    boolean globalIntSwitch;
    /* Record whether it is a privilege level before generating an exception. */
    boolean privilegesPermissions;
}Os_Arch_ExceptionCoreStatusType;

typedef uint8 Os_Arch_ExceptionSourceType;

/* The data type of OS process when an exception occurs. */
typedef enum
{
    OS_PROC_TASK,
    OS_PROC_ISR_CAT2,
    OS_PROC_ISR_CAT1,
    OS_PROC_ERRORHOOK
}Os_Arch_ExceptionProcType;

/* The data type of exception. */
typedef struct
{
    /* Record the type of exception that occurred. */
    Os_Arch_ExceptionSourceType sourceType;
    /* Record the cause of the abnormality. */
    uint32 causeCode;
}Os_Arch_ExceptionType;

/* The data type of OS status when an exception occurs. */
typedef struct
{
    /* Record the SP pointer that needs to be returned to the site. */
    uint32 currentSp;
    /* Record the type of site before triggering the exception. */
    Os_Arch_ExceptionProcType currentProcType;
    struct
    {
        /* Record the TaskId before triggering the exception. */
        TaskType taskId;
        /* Record the ID of the CAT2 ISRt before triggering the exception. */
        ISRType cat2IsrId;
        /* Record the interrupt Source before triggering an exception. */
        uint32 cat1IsrSource;
        /* Record the errorId before triggering the exception. */
        uint32 errorId;
    }errTargetId;
}Os_ExceptionCurrentType;

/* The data type of exception information. */
typedef struct
{
    /* Record the kernel state when an exception occurs. */
    Os_Arch_ExceptionCoreStatusType exceptionCoreStatus;
    /* Record the cause of the abnormality. */
    Os_Arch_ExceptionType exceptionType;
    /* Record the OS status when an exception occurs. */
    Os_ExceptionCurrentType exceptionCurrent;
}Os_ExceptionImformationType;

#endif /* OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON */

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#if( OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON )
extern volatile Os_ExceptionImformationType Os_CoreExceptionImformationDyn[OS_COREID_COUNT];

#endif /* OS_ARCH_EXCEPTION_ERRIMFORMATION == STD_ON */

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

#endif /* OS_ARCH_EXCEPTION_TYPES_H_ */

/*
********************************************************************************
*
*  File name: Os_Callout_Stubs.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date : HanCL/2021.11.23
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date : ZhangY/2024.11.22
* Change: Implement the function of retaining customized code in hook function.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
/*
********************************************************************************
*    <User_Function_Definition_Begin>
********************************************************************************
*/
#include "Os.h"
#include "Os_Core.h"
#include "Os_Lcfg.h"
#include "Os_Error.h"
#include "EcuM.h"
/*
********************************************************************************
*    <User_Function_Definition_End>
********************************************************************************
*/
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
* Function Name: ErrorHook
*
* Explanation: User hook for centralized application error handling.
*
* param: None.
*
* retval: None.
********************************************************************************
*/
#if(OS_CFG_ERRORHOOK_SYSTEM == STD_ON)
/*
********************************************************************************
*    <User_Function_Definition_Begin>
********************************************************************************
*/
void ErrorHook(StatusType Error)
{
}
/*
********************************************************************************
*    <User_Function_Definition_End>
********************************************************************************
*/
#endif

/*
********************************************************************************
* Function Name: ShutdownHook
*
* Explanation: User hook which is called during system shut down.
*
* param: Fatalerror: error occurred.
*
* retval: None.
********************************************************************************
*/
#if(OS_CFG_SHUTDOWNHOOK_SYSTEM == STD_ON)
/*
********************************************************************************
*    <User_Function_Definition_Begin>
********************************************************************************
*/
void ShutdownHook(StatusType Fatalerror)
{
    EcuM_Shutdown();/* WangM */  //wjc: Add EcuM_Shutdown() to shutdown EcuM.
}
/*
********************************************************************************
*    <User_Function_Definition_End>
********************************************************************************
*/

#endif
/*
********************************************************************************
* Function Name: StartupHook
*
* Explanation: User hook which is called after OS startup and before scheduling.
*
* param: None.
*
* retval: None.
********************************************************************************
*/
#if(OS_CFG_STARTUPHOOK_SYSTEM == STD_ON)
/*
********************************************************************************
*    <User_Function_Definition_Begin>
********************************************************************************
*/
void StartupHook(void)
{
}
/*
********************************************************************************
*    <User_Function_Definition_End>
********************************************************************************
*/
#endif
/*
********************************************************************************
* Function Name: ProtectionHook
*
* Explanation: User hook for protection error handling.
*
* param: Fatalerror: The error which caused the call to the protection hook.
*
* retval: PRO_IGNORE :Do nothing.
*         PRO_TERMINATETASKISR :forcibly terminate the Task/Category 2 ISR which causes the problem.
*         PRO_TERMINATEAPPL :Forcibly terminate the OS-Application the Task/Category 2 ISR belong.
*         PRO_TERMINATEAPPL_RESTART :Optional with restart.
*         PRO_SHUTDOWN :Shutdown the system.
********************************************************************************
*/
#if(OS_CFG_PROTECTIONHOOK_SYSTEM == STD_ON)
/*
********************************************************************************
*    <User_Function_Definition_Begin>
********************************************************************************
*/
ProtectionReturnType ProtectionHook(StatusType Fatalerror)
{
    return PRO_SHUTDOWN;
}
/*
********************************************************************************
*    <User_Function_Definition_End>
********************************************************************************
*/
#endif
void Os_Task_Idle_Task_Core0(void)
{
    while(TRUE)
    {
    }
}
void Os_Task_Idle_Task_Core1(void)
{
    while(TRUE)
    {
    }
}
void Os_Task_Idle_Task_Core2(void)
{
    while(TRUE)
    {
    }
}
void Os_Task_Idle_Task_Core3(void)
{
    while(TRUE)
    {
    }
}
void Os_Task_Idle_Task_Core4(void)
{
    while(TRUE)
    {
    }
}
void Os_Task_Idle_Task_Core5(void)
{
    while(TRUE)
    {
    }
}
#define OS_STOP_SEC_CODE 
#include "Os_MemMap.h"



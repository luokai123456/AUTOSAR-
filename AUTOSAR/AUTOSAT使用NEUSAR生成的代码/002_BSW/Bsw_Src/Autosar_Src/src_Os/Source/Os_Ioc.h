/*
********************************************************************************
*
*  File name: Os_Ioc.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.25
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
* Author/Date: LiG/2023.4.15
* Change: Adapted to GCC compiler.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: LiuZB/2025.02.20
* Change: Optimize space size.
* Cause: Update
********************************************************************************
*/
#ifndef OS_IOC_H_
#define OS_IOC_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Ioc_Types.h"
#include "Os_Ioc_Queue.h"
#include "Os_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Get IOC static configuration. */
#define OS_IOC_GETCFG(iocId) (&Os_IocCfg[iocId])

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
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
#if( OS_CFG_IOC_ENABLE == STD_ON )
extern FUNC(Std_ReturnType, OS_CODE) Os_Ioc_IntlWrite
(
    P2CONST(Os_IocCfgType, AUTOMATIC, OS_APPL_CONST) iocCfg,
    uint32 senderId,
    P2CONST(void* const, AUTOMATIC, OS_APPL_CONST) data
);
extern FUNC(Std_ReturnType, OS_CODE) Os_Ioc_IntlRead
(
    P2CONST(Os_IocCfgType, AUTOMATIC, OS_APPL_CONST) iocCfg,
    P2CONST(void* const, AUTOMATIC, OS_APPL_CONST) data
);
extern FUNC(Std_ReturnType, OS_CODE) Os_Ioc_IntlSend
(
    P2CONST(Os_IocCfgType, AUTOMATIC, OS_APPL_CONST) iocCfg,
    uint32 senderId,
    P2CONST(void* const, AUTOMATIC, OS_APPL_CONST) data
);
extern FUNC(Std_ReturnType, OS_CODE) Os_Ioc_IntlReceive
(
    P2CONST(Os_IocCfgType, AUTOMATIC, OS_APPL_CONST) iocCfg,
    P2CONST(void* const, AUTOMATIC, OS_APPL_CONST) data
);
extern FUNC(void, OS_CODE) Os_Ioc_ClearQueue
(
    P2CONST(Os_IocCfgType, AUTOMATIC, OS_APPL_CONST) iocCfg
);
extern FUNC(Std_ReturnType, OS_CODE) Os_Ioc_Write
(
    P2CONST(Os_IocCfgType, AUTOMATIC, OS_APPL_CONST) iocCfg,
    uint32 senderId,
    P2CONST(void* const, AUTOMATIC, OS_APPL_CONST) data
);
extern FUNC(Std_ReturnType, OS_CODE) Os_Ioc_Read
(
    P2CONST(Os_IocCfgType, AUTOMATIC, OS_APPL_CONST) iocCfg,
    P2CONST(void* const, AUTOMATIC, OS_APPL_CONST) data
);
extern FUNC(Std_ReturnType, OS_CODE) Os_Ioc_Send
(
    P2CONST(Os_IocCfgType, AUTOMATIC, OS_APPL_CONST) iocCfg,
    uint32 senderId,
    P2CONST(void* const, AUTOMATIC, OS_APPL_CONST) data
);
extern FUNC(Std_ReturnType, OS_CODE) Os_Ioc_Receive
(
    P2CONST(Os_IocCfgType, AUTOMATIC, OS_APPL_CONST) iocCfg,
    P2CONST(void* const, AUTOMATIC, OS_APPL_CONST) data
);
extern FUNC(Std_ReturnType, OS_CODE) Os_Ioc_EmptyQueue
(
    P2CONST(Os_IocCfgType, AUTOMATIC, OS_APPL_CONST) iocCfg
);
extern FUNC(void, OS_CODE) Os_Ioc_Init
(
    P2CONST(Os_IocCfgType, AUTOMATIC, OS_APPL_CONST) iocCfg
);
#endif /* OS_CFG_IOC_ENABLE == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_IOC_H_ */

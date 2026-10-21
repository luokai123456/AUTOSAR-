/*
********************************************************************************
*
*  File name: PduR_PBcfg.h
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 2.0
* Author/Date: ZhangDX/2019.08.28
* Change: New create.
* Cause: New
********************************************************************************
* Version: 2.1
* Author/Date: ZhangDX/2019.10.12
* Change: Modify the code format.
* Cause: Optimize
********************************************************************************
* Version: 2.2
* Author/Date: ZhangDX/2019.11.12
* Change: 1. Change code format.
*         2. Add Buffer allocation.
* Cause: Update
********************************************************************************
* Version: 2.3
* Author/Date: ZhangDX/2019.12.03
* Change: Move the contents of the PduR_PBcfg.h file into the PduR_LCfg.h file.
* Cause: Update
********************************************************************************
* Version: 2.4
* Author/Date: ZhangDX/2020.01.06
* Change: 1. Delete the PduR module reference Std_Types.h and replace it with
*            ComStack_Types.h.
*         2. Remove redundant "ComStack_Cfg.h" and "ComStack_Types.h" files.
* Cause: Update
********************************************************************************
* Version: 2.5
* Author/Date: ZhangDX/2020.01.09
* Change: Modify the configuration item name TRIGGER_TRANSMIT-> TRIGGERTRANSMIT.
* Cause: Update
********************************************************************************
* Version: 3.0
* Author/Date: ZhangDX/2020.03.27
* Change: 1. Add notes.
*         2. Updated version information is 3.0.0.
* Cause: Clear QAC warning and updata to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: ZhangDX/2020.07.14
* Change: 1. Update the gateway function of the communication interface layer and
*            the FIFO function of the gateway.
*         2. Update the code format.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: ZhangDX/2020.09.27
* Change: Complete AutoSAR code style conversion.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: ZhangDX/2020.10.06
* Change: Add PostBuild function.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: ZhangDX/2020.10.13
* Change: Optimize the implementation of PduRZeroCostOperation function code.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: ZhangDX/2021.1.11
* Change: Increase the macro definition of the number of routing path groups.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: SunHQ/2022.09.20
* Change: Add new members to PduR_PBConfigType.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: SunHQ/2023.02.10
* Change: Modify the macro that controls the code implementation.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: LuQ/2024.04.02
* Change: Modify the comments format.
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date: LuQ/2024.09.20
* Change: Modify copyright information.
* Cause: Optimization
********************************************************************************
* Version: 3.24
* Author/Date: LuQ/2024.09.23
* Change: Modify the comments format.
* Cause: Optimization
********************************************************************************
*/
#ifndef PDUR_PBCFG_H_
#define PDUR_PBCFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "PduR_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Provide external macro definitions for obtaining the number of routing path groups. */
#define PDUR_ROUTING_GROUP_MAX_CNT  PduR_PBConfigTable->PduR_RoutingTablePtr->PduRMaxRoutingPathGroupCnt

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
struct tag_PduR_PBConfigTypeStruct
{
#if (STD_OFF == PDUR_ZERO_COST_OPERATION)

    CONST(uint16, TYPEDEF) PduR_DstListSize;

#if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST))

    CONST(uint16, TYPEDEF) PduR_DstTpSize;

#endif  /* #if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST)) */

#if ((defined PDUR_SUPPORT_IF_MULICAST) && (STD_ON == PDUR_SUPPORT_IF_MULICAST))

    CONST(uint16, TYPEDEF) PduR_DstIfSize;

#endif  /* #if ((defined PDUR_SUPPORT_IF_MULICAST) && (STD_ON == PDUR_SUPPORT_IF_MULICAST)) */

    P2CONST(PduRRoutingTables_Type, TYPEDEF, PDUR_APPL_CONST) PduR_RoutingTablePtr;

#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))

    /* Tp buffer status stores part of the buffer. */
    CONSTP2VAR(PduR_TpBuffer_Type, TYPEDEF, PDUR_APPL_CONST) PduR_TpBufferStatusPtr;

#endif  /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */

#if (STD_ON == PDUR_SUPPORT_MULTICORE)

    CONSTP2CONST(PduR_BufferType, TYPEDEF, PDUR_APPL_CONST)* PduR_QueuePtr;
    CONSTP2CONST(uint16, TYPEDEF, PDUR_APPL_CONST) PduR_ApplicationPtr;

#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */

#else   /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */

    CONST(uint16, TYPEDEF) PduRConfigurationId; /* 1..1 */

#endif  /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */

};
typedef struct tag_PduR_PBConfigTypeStruct PduR_PBConfigType;

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
#define PDUR_START_SEC_CONFIG_DATA
#include "PduR_MemMap.h"
extern CONST(PduR_PBConfigType, PDUR_CONFIG_DATA) PduR_PBConfigTable;
#define PDUR_STOP_SEC_CONFIG_DATA
#include "PduR_MemMap.h"
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* #define PDUR_PBCFG_H_ */

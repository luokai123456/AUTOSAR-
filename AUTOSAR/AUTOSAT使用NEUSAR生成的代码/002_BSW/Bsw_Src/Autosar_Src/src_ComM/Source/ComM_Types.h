/*
********************************************************************************
*
* File name: ComM_Types.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: Tanlx/2019.05.05
* Change: Autosar
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: jiafeng/2020.07.02
* Change: Update software version to 3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: jiaF/2021.4.10
* Change: Add COMM_PNC_FULL_COMMUNICATION in ComM_PncModeType.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: ZhangY/2021.10.28
* Change: Add #include "Std_Types.h".
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: HeHao/2024.04.02
* Change: Modify comments.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: TianL/2024.05.16
* Change: Modify coding specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: TianL/2024.8.5
* Change: Modify copyright.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: TianL/2025.6.16
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef COMM_TYPES_H_
#define COMM_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Network bus types. */
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define COMM_BUS_TYPE_CAN                 (0U)
#define COMM_BUS_TYPE_FR                  (1U)
#define COMM_BUS_TYPE_LIN                 (3U)
#define COMM_BUS_TYPE_ETH                 (4U)
#define COMM_BUS_TYPE_INTERNAL            (5U)
#define COMM_BUS_TYPE_CDD                 (6U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* ComM channel states. */
#define COMM_NO_COM_NO_PENDING_REQUEST    (0U)
#define COMM_NO_COM_REQUEST_PENDING       (1U)
#define COMM_FULL_COM_NETWORK_REQUESTED   (2U)
#define COMM_FULL_COM_READY_SLEEP         (3U)
#define COMM_SILENT_COM                   (4U)
#define COMM_MAX_NUMBER_OF_STATES         (5U)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* Initialization status type of the ComM. */
typedef enum
{
    COMM_UNINIT = 0U,
    COMM_INIT
} ComM_InitStatusType;
/* Mode type of a PNC. */
typedef enum
{
    COMM_PNC_NO_COMMUNICATION = 0U,
    COMM_PNC_PREPARE_SLEEP,
    COMM_PNC_READY_SLEEP,
    COMM_PNC_REQUESTED,
    COMM_PNC_REQUESTED_PASSIVE,
    COMM_PNC_FULL_COMMUNICATION,
} ComM_PncModeType;
/* Bus type of a channel. */
/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef uint8 ComM_BusType;
/* State type of a channel. */
typedef uint8 ComM_StateType;

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

#endif  /* CANTP_CFG_H_ */

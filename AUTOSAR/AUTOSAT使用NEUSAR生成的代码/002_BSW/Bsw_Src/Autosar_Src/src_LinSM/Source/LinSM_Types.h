/*
********************************************************************************
*
* File name: LinSM_Types.h
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2020.03.26
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: lizhiheng/2020.07.01
* Change: Update to 3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: lizhiheng/2020.07.16
* Change: Modify the naming rules.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date : Li.ZH/2021.8.16
* Change: Modification code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.3
* Author/Date : LiZH/2021.10.28
* Change: Modification #include "ComM.h".
* Cause: Optimize
********************************************************************************
* Version: 3.4
* Author/Date : LiXB/2023.6.29
* Change: 1. Add nodeChannelType to LinSM_Channl_Config_st
*         2. Add macro LINSM_CHANNEL_MASTER and LINSM_CHANNEL_SLAVE
* Cause: Update 
********************************************************************************
* Version: 3.5
* Author/Date : LiXB/2023.8.4
* Change: Add reqMode to LinSM_Managment_st
* Cause: Update 
********************************************************************************
* Version: 3.6
* Author/Date:ZhangXF/2023.10.30
* Change: 1)Add macro LINSM_REQUEST_INVALID and LINSM_REQUEST_SCHEDULE
          2)Modified macro LINSM_E_CONFIRMATION_TIMEOUT and LINSM_E_INIT_FAILED
* Cause: Update 
********************************************************************************
* Version: 3.7
* Author/Date:TianG/2024.6.25
* Change: 1. Modify copyright.
*         2. Modify the comments format.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date:TianG/2024.11.04
* Change: Add macro LINSM_WAKEUP.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: YanCL/2025.06.16
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef LINSM_TYPES_H_
#define LINSM_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComM.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* States and transitions of the LinSM state machine. */
#define LINSM_UNINIT                (0x00U)
#define LINSM_FULL_COM              (0x01U) /* Full communication. */
#define LINSM_NO_COM                (0x02U) /* No communication. */
#define LINSM_RUN_COMMUNICATION     (0x03U)
#define LINSM_GOTO_SLEEP            (0x04U)
#define LINSM_WAKEUP                (0x10U) /* Wakeup state */
#define LINSM_NO_REQUEST            (0x00U)
#define LINSM_NO_STATE              (0x00U)
#define LINSM_REQUEST_SCHEDULE      (0x05U)
#define LINSM_REQUEST_INVALID       (0xFFU)


/* LIN interface API service ID */
#define LINSM_INIT                          (0x01U)
#define LINSM_SCHEDULE_REQUEST              (0x10U)
#define LINSM_GET_VERSION_INFO              (0x02U)
#define LINSM_GET_CURRENT_COM_MODE          (0x11U)
#define LINSM_REQUEST_COM_MODE              (0x12U)
#define LINSM_MAIN_FUNCTION                 (0x30U)
#define LINSM_SCHDULE_REQUEST_CONFIRMATION  (0x20U)
#define LINSM_GOTO_SLEEP_CONFIRMATION       (0x22U)
#define LINSM_WAKEUP_CONFIRMATION           (0x21U)
#define LINSM_GOTO_SLEEP_INDICATION         (0x03U)

/* Dummy function */
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" Polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
#define LINSM_DUMMY_STATEMENT(v)          (v)=(v)

/* Development Errors */
#define LINSM_E_NO_ERR                  (0xFFU) /* No error. */
#define LINSM_E_UNINIT                  (0x00U) /* API called without initialization of LinSM. */
#define LINSM_E_NONEXISTENT_NETWORK     (0x20U) /* Referenced network does not exist (identification is out of range). */
#define LINSM_E_PARAMETER               (0x30U) /* API service called with wrong parameter. */
#define LINSM_E_PARAM_POINTER           (0x40U) /* API service called with invalid pointer. */
#define LINSM_E_CONFIRMATION_TIMEOUT    (0x00U) /* Timeout of the callbacks from LinIf. */
#define LINSM_E_INIT_FAILED             (0x50U) /* Init function failed. */

#define LINSM_START_TIMER   (1U)    /* Start timeout timer. */
#define LINSM_STOP_TIMER    (2U)    /* Stop timeout timer. */
#define LINSM_CONFIRM_TO    (3U)    /* timeout occured. */

#define LINSM_INIT_ZERO     (0U)    /* Used to initialize to zero value, no special meaning. */
#define LINSM_SHIFT_8BIT    (8U)
#define LINSM_LOW_BYTE      (0x00FFU)   /* For shift 8bit */

/* Linif channel node type */
#define LINSM_CHANNEL_MASTER                        ((uint8)0x00U)
#define LINSM_CHANNEL_SLAVE                         ((uint8)0x01U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* Type used to report the current mode to the BswM. */
typedef uint8 LinSM_ModeType;

typedef struct
{
    uint8   networkId;           /* hardware channel number. */
    uint16  confirmTimeout;      /* Timeout in seconds for the goto sleep, wakeup and schedule request calls to LinIf. */
    boolean transPassiveMode;    /* Selects STANDBY (true) or SLEEP (false) transceiver mode when entering LINSM_NO_COM. */
    uint8 scheduleStartIndex;    /* 1:1  relevance LinSM_ScheduleIex_Info start index. */
    uint8 scheduleEndIndex;      /* 1:1  relevance LinSM_ScheduleIex_Info end index. */
    uint8 scheduleNumber;        /* Schedule number. */
    uint8 nodeChannelType;       /* channel node type */
} LinSM_Channl_Config_st;

typedef struct
{
    LinSM_ModeType curState;    /* Current network state */
    LinSM_ModeType subState;    /* Network sub state. */
    ComM_ModeType reqState;     /* Request type. */
    ComM_ModeType reqMode;      /* Request mode. */
    uint8 timerState;           /* Timer status. */
    uint8 retryTimes;           /* Number of timeouts. */
    uint16 timeOutCntr;         /* Timeout counter. */
    uint8 curSchedule;          /* Current schedule */
} LinSM_Managment_st;

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
#endif /* LINSM_TYPES_H_ */


/*
*******************************************************************************
*
*  File name: NmStack_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
*******************************************************************************
*
*  History
*------------------------------------------------------------------------------
*******************************************************************************
* Version: 1.0
* Author/Date: ZhangY/2018.12.13
* Change: New created.
* Cause: New
*******************************************************************************
* Version: 2.0
* Author/Date: ZhangY/2024.4.1
* Change: Perfect code specification.
* Cause: New
*******************************************************************************
* Version: 3.0
* Author/Date: TianSL/2024.6.26
* Change: Modify copyright.
* Cause: Optimization
********************************************************************************
* Version: 3.1
* Author/Date: TianSL/2024.8.14
* Change: Move application type definitions to RTE.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: TianSL/2024.8.28
* Change: Modify copyright.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: TianSL/2025.5.27
* Change: Add the polyspace deviation suppression comment.
* Cause: Optimization
********************************************************************************
*/
#ifndef NM_STACK_TYPES_H_
#define NM_STACK_TYPES_H_

/*
*******************************************************************************
*    Includes
*******************************************************************************
*/
#include "Std_Types.h"
#include "Rte_Nm_Type.h"

/*
*******************************************************************************
*    Global Macros
*******************************************************************************
*/
/* Sleep Bit in the Control Bit Vector. */
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NM_COORD_BIT_SLEEP                            (0x08U)
/* Inverse Sleep Bit Mask in the Control Bit Vector. */
#define NM_COORD_BIT_INV_SLEEP                        (0xF7U)

/* Uninitialized State. */
#define NM_STATE_UNINIT                               (0x00U)
/* Bus Sleep State. */
#define NM_STATE_BUS_SLEEP                            (0x01U)
/* Prepare Bus Sleep State. */
#define NM_STATE_PREPARE_BUS_SLEEP                    (0x02U)
/* Ready Sleep State. */
#define NM_STATE_READY_SLEEP                          (0x03U)
/* Normal Operation State. */
#define NM_STATE_NORMAL_OPERATION                     (0x04U)
/* Repeat Message State. */
#define NM_STATE_REPEAT_MESSAGE                       (0x05U)
/* Synchronized State. */
#define NM_STATE_SYNCHRONIZE                          (0x06U)
/* Offline State. */
#define NM_STATE_OFFLINE                              (0x07U)
/* Check Wake-up State. */
#define NM_STATE_CHECK_WAKEUP                         (0x08U)
/* Wait Start-up State. */
#define NM_STATE_WAIT_STARTUP                         (0x09U)
/* Wait Start-up and gateway messages already activated. */
#define NM_STATE_WAIT_NETWORK_GW_MSG_ACTIVE           (0x0AU)
/* Wait Start-up and gateway plus event triggered messages already activated. */
#define NM_STATE_WAIT_NETWORK_GW_AND_EVENT_MSG_ACTIVE (0x0BU)
/* BusOff. */
#define NM_STATE_BUS_OFF                              (0x0CU)

/* Number of state defines. */
#define NM_STATE_NUMBER_OF_STATES                     (0x0DU)

/* Modes of the network management state machine. */
typedef uint8 Nm_ModeType;
/* Bus-Sleep Mode. */
#define NM_MODE_BUS_SLEEP                             (0x00U)
/* Prepare Bus-Sleep Mode. */
#define NM_MODE_PREPARE_BUS_SLEEP                     (0x01U)
/* Synchronized Mode. */
#define NM_MODE_SYNCHRONIZE                           (0x02U)
/* Network Mode. */
#define NM_MODE_NETWORK                               (0x03U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/* BusNm Type. */
typedef enum
{
    /* CAN NM typ.e */
    NM_BUSNM_CANNM = 0U,
    /* FR NM type. */
    NM_BUSNM_FRNM,
    /* LIN NM type. */
    NM_BUSNM_LINNM,
    /* UDP NM type. */
    NM_BUSNM_UDPNM,
    /* Generic NM type. */
    NM_BUSNM_GENERICNM,
    /* SAE J1939 NM type (address claiming). */
    NM_BUSNM_J1939NM,
    /* NM type undefined. */
    NM_BUSNM_UNDEF = 0xFFU
/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
}Nm_BusNmType;
/*
*******************************************************************************
*    Global Types
*******************************************************************************
*/
/*
*******************************************************************************
*    Global variable
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Constants
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Functions
*******************************************************************************
*/

#endif  /* NM_STACK_TYPES_H */

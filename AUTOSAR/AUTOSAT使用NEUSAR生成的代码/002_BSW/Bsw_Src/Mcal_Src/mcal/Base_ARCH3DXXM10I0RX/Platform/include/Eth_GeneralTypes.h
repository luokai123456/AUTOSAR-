/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : ETH
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    Eth_GeneralTypes.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Eth MCAL driver.
*
*   @addtogroup Eth
*   @{
*/

#ifndef ETH_GENERALTYPES_H
#define ETH_GENERALTYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "derivative.h"
#include "Std_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          The Ethernet driver state.
* @details        A variable of this type holds the state of the Ethernet driver
*                 module. The driver is at the ETH_STATE_UNINIT at the beginning
*                 until the Eth_Init() function is called. The state remains
*                 equal to the ETH_STATE_INIT until the Eth_ControllerInit()
*                 function is called. Then the state is ETH_STATE_ACTIVE.
* @implements     Eth_StateType_enumeration
*/
typedef enum
{
    ETH_STATE_UNINIT = 0, /**< The driver has not been initialized yet */
    ETH_STATE_INIT   = 1  /**< The driver has not been configured and
                               the controller was configured */
} Eth_StateType;

/**
* @brief          The Ethernet controller mode.
* @details        This type is used to store the information whether the
*                 Ethernet controller is stopped or running.
* @implements     Eth_ModeType_enumeration
*/
typedef enum
{
    ETH_MODE_DOWN   = 0,    /**< Controller is shut down */
    ETH_MODE_ACTIVE = 1     /**< Controller is active */
} Eth_ModeType;

/**
* @brief          The Ethernet reception status
* @details        This status is returned by the @c Eth_Receive() function to indicate
*                 whether any frame has been received and if yes, whether there is any
*                 frame still waiting in the queue (for another @c Eth_Receive() call).
* @implements     Eth_RxStatusType_enumeration
*/
typedef enum
{
    ETH_RECEIVED     = 0,   /**< A frame has been received and there are no more frames in the queue */
    ETH_NOT_RECEIVED = 1,   /**< No frames received */
    ETH_RECEIVED_MORE_DATA_AVAILABLE = 2 /**< A frame received and at least another one in the queue detected */
} Eth_RxStatusType;
 /**
* @brief          Action type for PHY address filtering
* @details        The Enumeration type describes the action to be taken
*                 for the MAC address given in *PhysAddrPtr
* @implements     Eth_FilterActionType_enumeration
*/
typedef enum
{
    ETH_ADD_TO_FILTER      = 0,    /**< Add address to the filter */
    ETH_REMOVE_FROM_FILTER = 1   /**< Remove address */
} Eth_FilterActionType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief         Frame type.
* @details       This type is used to pass the value of type or length field in the
*                Ethernet frame header. It is 16 bits long unsigned integer.
*                - Values less than or equal to 1500 represent the length.
*                - Values grater than 1500 represent the type (i.e. 0x800 = IP).
* @implements     Eth_FrameType_type
*/
typedef uint16 Eth_FrameType;

/**
* @brief         Type used to pass transmit or receive data to or from the driver.
* @details       This type was defined as 8 bit wide unsigned integer because
*                this definition is available on all CPU types.
* @implements     Eth_DataType_type
*/
typedef uint8 Eth_DataType;

/**
* @brief         Type used to identify the ethernet buffer. 
* @details       This type was defined for index of buffer used in transmitted and received data.
* @implements     Eth_BufIdxType_type
*/
typedef uint32 Eth_BufIdxType;

/**
* @brief         Type used to statistic counter for diagnostics. 
* @details       Variables of this type are used to statistic counter for diagnostics. 
* @implements    Eth_CounterType_structure
*/
typedef struct
{
    VAR(uint32, AUTOMATIC) DropPktBufOverrun;
    VAR(uint32, AUTOMATIC) DropPktCrc;
    VAR(uint32, AUTOMATIC) UndersizePkt;
    VAR(uint32, AUTOMATIC) OversizePkt;
    VAR(uint32, AUTOMATIC) AlgnmtErr;
    VAR(uint32, AUTOMATIC) SqeTestErr;
    VAR(uint32, AUTOMATIC) DiscInbdPkt;
    VAR(uint32, AUTOMATIC) ErrInbdPkt;
    VAR(uint32, AUTOMATIC) DiscOtbdPkt;
    VAR(uint32, AUTOMATIC) ErrOtbdPkt;
    VAR(uint32, AUTOMATIC) SnglCollPkt;
    VAR(uint32, AUTOMATIC) MultCollPkt;
    VAR(uint32, AUTOMATIC) DfrdPkt;
    VAR(uint32, AUTOMATIC) LatCollPkt;
    VAR(uint32, AUTOMATIC) HwDepCtr0;
    VAR(uint32, AUTOMATIC) HwDepCtr1;
    VAR(uint32, AUTOMATIC) HwDepCtr2;
    VAR(uint32, AUTOMATIC) HwDepCtr3;
} Eth_CounterType;

/**
* @brief         Type used to statistic counter for diagnostics. 
* @details       Variables of this type are used to statistic counter for diagnostics. 
* @implements    Eth_RxStatsType_structure
*/
typedef struct
{
   VAR(uint32, AUTOMATIC) RxStatsDropEvents;
   VAR(uint32, AUTOMATIC) RxStatsOctets;
   VAR(uint32, AUTOMATIC) RxStatsPkts;
   VAR(uint32, AUTOMATIC) RxStatsBroadcastPkts;
   VAR(uint32, AUTOMATIC) RxStatsMulticastPkts;
   VAR(uint32, AUTOMATIC) RxStatsCrcAlignErrors;
   VAR(uint32, AUTOMATIC) RxStatsUndersizePkts;
   VAR(uint32, AUTOMATIC) RxStatsOversizePkts;
   VAR(uint32, AUTOMATIC) RxStatsFragments;
   VAR(uint32, AUTOMATIC) RxStatsJabbers;
   VAR(uint32, AUTOMATIC) RxStatsCollisions;
   VAR(uint32, AUTOMATIC) RxStatsPkts64Octets;
   VAR(uint32, AUTOMATIC) RxStatsPkts65to127Octets;
   VAR(uint32, AUTOMATIC) RxStatsPkts128to255Octets;
   VAR(uint32, AUTOMATIC) RxStatsPkts256to511Octets;
   VAR(uint32, AUTOMATIC) RxStatsPkts512to1023Octets;
   VAR(uint32, AUTOMATIC) RxStatsPkts1024to1518Octets;
   VAR(uint32, AUTOMATIC) RxUnicastFrames;
} Eth_RxStatsType;

/**
* @brief         Type used to statistic counter for diagnostics. 
* @details       Variables of this type are used to statistic counter for diagnostics. 
* @implements    Eth_TxStatsType_structure
*/
typedef struct
{
    VAR(uint32, AUTOMATIC) TxNumberOfOctets;
    VAR(uint32, AUTOMATIC) TxNUcastPkts;
    VAR(uint32, AUTOMATIC) TxUniCastPkts;
} Eth_TxStatsType;

/**
* @brief         Type used to statistic counter for diagnostics. 
* @details       Variables of this type are used to statistic counter for diagnostics. 
* @implements    Eth_TxErrorCounterValuesType_structure
*/
typedef struct
{
    VAR(uint32, AUTOMATIC) TxDroppedNoErrorPkts;
    VAR(uint32, AUTOMATIC) TxDroppedErrorPkts;
    VAR(uint32, AUTOMATIC) TxDeferredTrans;
    VAR(uint32, AUTOMATIC) TxSingleCollision;
    VAR(uint32, AUTOMATIC) TxMultipleCollision;
    VAR(uint32, AUTOMATIC) TxLateCollision;
    VAR(uint32, AUTOMATIC) TxExcessiveCollison;
} Eth_TxErrorCounterValuesType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* ETH_GENERALTYPES_H */
/** @} */

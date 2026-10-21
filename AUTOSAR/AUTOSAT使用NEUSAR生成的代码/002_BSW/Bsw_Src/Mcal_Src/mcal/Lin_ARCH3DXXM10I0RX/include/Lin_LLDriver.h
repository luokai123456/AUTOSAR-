/****************************************************************************
* 

* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : LIN
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : 
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/


/**
*   @file    Lin_LLDriver.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Lin - Low level driver header file.
*   @details This file includes the function prototypes defined in the LIN low level driver for LinFlex.
*
*   @addtogroup MCAL
*   @{
*/

/*PRQA S 1535,1536,1758,1594,1756 EOF*/
#ifndef LINFLEX_H
#define LINFLEX_H

#ifdef __cplusplus
extern "C"
{
#endif

/* ==============================================INCLUDE FILES=======================================*/
#include "Lin_Types.h"
#include "Lin.h"
/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define LIN_LLD_H_VENDOR_ID                            LIN_VENDOR_ID_PLUGIN
#define LIN_LLD_H_AR_REL_MAJOR_VER                     LIN_AR_REL_MJR_VERSION_PLUGIN
#define LIN_LLD_H_AR_REL_MINOR_VER                     LIN_AR_REL_MNR_VERSION_PLUGIN
#define LIN_LLD_H_AR_REL_REV_VER                       LIN_AR_REL_REV_VERSION_PLUGIN
#define LIN_LLD_H_SW_MAJOR_VER                         LIN_SW_MAJOR_VERSION_PLUGIN
#define LIN_LLD_H_SW_MINOR_VER                         LIN_SW_MINOR_VERSION_PLUGIN
#define LIN_LLD_H_SW_PATCH_VER                         LIN_SW_PATCH_VERSION_PLUGIN
/* ============================================FILE VERSION CHECKS=================================== */
#if (LIN_VENDOR_ID_OUTPUT != LIN_LLD_H_VENDOR_ID)
    #error " NON-MATCHED DATA : LIN_LLD_H_VENDOR_ID "
#endif
#if (LIN_AR_REL_MJR_VERSION_PLUGIN != LIN_LLD_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_LLD_H_AR_REL_MAJOR_VER "
#endif
#if (LIN_AR_REL_MNR_VERSION_PLUGIN != LIN_LLD_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_LLD_H_AR_REL_MINOR_VER "
#endif
#if (LIN_AR_REL_REV_VERSION_OUTPUT != LIN_LLD_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : LIN_LLD_H_AR_REL_REV_VER "
#endif
#if (LIN_SW_MAJOR_VERSION_OUTPUT != LIN_LLD_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_LLD_H_SW_MAJOR_VER "
#endif
#if (LIN_SW_MINOR_VERSION_OUTPUT != LIN_LLD_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_LLD_H_SW_MINOR_VER "
#endif
#if (LIN_SW_PATCH_VERSION_OUTPUT != LIN_LLD_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : LIN_LLD_H_SW_PATCH_VER "
#endif
/*=================================================CONSTANTS========================================*/

/*============================================DEFINES AND MACROS====================================*/                                           

#define LIN_DATA_LEN                             8U   /** LIN driver data length **/ /* PRQA S 1534 */

#define LIN_API_MODE_SYNCHRONOUS               0U   /** < @brief Synchronous API.  */
#define LIN_API_MODE_ASYNCHRONOUS              1U   /** < @brief Asynchronous API. */ /* PRQA S 1534 */
#define LIN_API_MODE_BUFFERED_IO               2U   /** < @brief Buffered IO API (only for Serial). */

#define LIN_HW_MAX_AVAILABLE_MODULES           17U

/*===================================================ENUMS==========================================*/
typedef enum
{
    LIN_SLAVE,                                      /**  LINFlex is in slave mode.        */
    LIN_MASTER                                      /**  LINFlex is in master mode.       */
}lin_node_t;

typedef enum
{
    LIN_ENHANCED_CCS,                               /**  Enhanced Checksum covering Identifier and Data fields. */
    LIN_CLASSIC_CCS                                 /**  Classic Checksum covering Data field only.             */
}lin_ccs_t;

typedef enum
{
    LIN_DIR_RECEIVE,                               /**  LINFlexD receives the data and copies them in the BDRs. */
    LIN_DIR_TRANSMIT                               /**  LINFlexD transmits the data from the BDRs.              */
}lin_message_dir_t;

typedef enum
{
    LIN_LIST,                                       /**  FIlter is configured in list mode. */
    LIN_MASK                                        /**  Filter is configured in mask mode. */
}lin_filter_t;

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

typedef struct LinLldDriver LinLldDrivers;  /** Type of a structure representing a LIN driver. **/
typedef void (*lin_callback_t)(uint8  device);
typedef struct Lin_flexDriver Lin_flexDrivers;
typedef uint32 (*linlldclbk_t)(const LinLldDrivers *ldp, uint8 idMessage, uint8 *buf, uint16 len);

typedef union tmpdata /* PRQA S 1536 */
{
    uint32    w;
    uint8  b[4];
}t_data;


typedef struct /* PRQA S 3630 */
{
    uint8                                  value;    /** Value. Filter value, it is in the range[0, 63] **/
    uint8                               datasize;    /** Message data size. It is in the range[1, 8]. **/
    lin_message_dir_t                  direction;    /** Message direction (Transmit, Receive). **/
    lin_ccs_t                                ccs;    /** Message Checksum Data Type **/
    lin_filter_t                            mode;    /** Mask or List **/
    uint8                             mask_value;    /** Mask Value. Mask Filter value, it is in the range[0, 63] **/
}LinLldFilter;

typedef struct /* PRQA S 3630 */
{
    uint8                                  value;    /** Value. Filter value, it is in the range[0, 63] **/
    uint8                               datasize;    /** Message data size. It is in the range[1, 8]. **/
    lin_message_dir_t                  direction;    /** Message direction (Transmit, Receive). **/
    lin_ccs_t                                ccs;    /** Message Checksum Data Type. **/
}No_LinLldFilter;

typedef struct /* PRQA S 3630 */
{
    uint32                                 speed;    /** Bit rate. **/
    lin_node_t                              mode;    /** Lin Driver Mode flags. **/
    uint8                               api_mode;    /** API Mode flags. **/
    uint8                           DmaTxChannel;
    uint8                           DmaRxChannel;
} LinLldConfig;

struct LinLldDriver
{
    const LinLldConfig                   *config;    /** Current configuration data. **/
    uint8                                channel;
    uint8                                *rx_buf;    /** Input Buffer. **/
    uint8                                *tx_buf;    /** Output Buffer. **/
    uint8                        *filter_buf[16];    /** Private buffer of each filter **/
    uint16                                rx_len;    /** Number of bytes to receive. **/
    uint16                                tx_len;    /** Number of bytes to transmit. **/
    uint8                              rx_id_msg;    /** Id of the received message. **/
    uint8                              tx_id_msg;    /** Id of the transmitted message. **/
    uint8                                    ccs;    /** Checksum mode. **/


    volatile struct LINFlexD_tag       *linflexD;
    uint32                                 clock;    /** Clock value for this unit. **/
};


struct Lin_flexDriver{
    uint32                   device;                     /* must be private */
    lin_callback_t rxi_lincallback;                     /* linflex Rx interrupt call back */
    lin_callback_t txi_lincallback;                     /* linflex Tx interrupt call back */
    lin_callback_t err_lincallback;                     /* linflex Err interrupt call back */
};

typedef struct Lin_Config
{
    LinLldDrivers *ldp;
    struct Lin_flexDriver Linflex;
    uint8 mbl; /* Master break length */
    uint8 sbl; /* Slave break length */
    uint8 rto; /* Response TimeOut*/
    uint8 hto; /* Header TimeOut*/
    uint8 DmaSupport;
    uint8 WakeupSupport;
    uint32 WakeupSource;
    Lin_NotificationFunc LinNotificationFunc;
}Lin_Configs;

/*==============================================GLOBAL FUNCTIONS====================================*/

#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
extern volatile VAR(uint8,LIN_VAR)u8Lin_ChStatus[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
extern volatile VAR(uint8,LIN_VAR)u8Lin_ChFrameStatus[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
extern volatile VAR(uint8,LIN_VAR)u8Lin_ChFrameErrorStatus[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
extern VAR(sint8,LIN_VAR)s8Lin_ChannelHardwareMap[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_INIT
#include "Lin_MemMap.h"
extern P2CONST(Lin_ConfigType,LIN_VAR,LIN_APPL_CONST) g_pLin_GenerateConfigPBPtr;
#define LIN_STOP_SEC_VAR_INIT
#include "Lin_MemMap.h"

/* Specification of Lin Driver : [SWS_Lin_00013] */
#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
extern P2CONST(Lin_ChannelConfigType,LIN_VAR,LIN_APPL_CONST)g_pLin_ChannelConfigPtr[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
 
/*===================================FUNCTION PROTOTYPES============================================*/
#ifdef RESOURCE_SUPPORT_LINFLEXD_0
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX0_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX0_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX0_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_0 */

#ifdef RESOURCE_SUPPORT_LINFLEXD_1
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX1_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX1_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX1_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_1 */

#ifdef RESOURCE_SUPPORT_LINFLEXD_2
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX2_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX2_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX2_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_2 */

#ifdef RESOURCE_SUPPORT_LINFLEXD_3
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX3_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX3_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX3_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_3 */

#ifdef RESOURCE_SUPPORT_LINFLEXD_4
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX4_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX4_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX4_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_4 */

#ifdef RESOURCE_SUPPORT_LINFLEXD_5
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX5_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX5_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX5_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_5 */

#ifdef RESOURCE_SUPPORT_LINFLEXD_6
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX6_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX6_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX6_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_6 */

#ifdef RESOURCE_SUPPORT_LINFLEXD_7
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX7_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX7_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX7_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_7 */

#ifdef RESOURCE_SUPPORT_LINFLEXD_8
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX8_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX8_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX8_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_8 */

#ifdef RESOURCE_SUPPORT_LINFLEXD_9
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX9_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX9_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX9_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_9 */

#ifdef RESOURCE_SUPPORT_LINFLEXD_10
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX10_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX10_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX10_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_10 */

#ifdef RESOURCE_SUPPORT_LINFLEXD_11
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX11_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX11_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX11_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_11 */

#ifdef RESOURCE_SUPPORT_LINFLEXD_12
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX12_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX12_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX12_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_12 */

#ifdef RESOURCE_SUPPORT_LINFLEXD_14
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX14_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX14_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX14_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_14 */

#ifdef RESOURCE_SUPPORT_LINFLEXD_15
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX15_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX15_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX15_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_15 */

#ifdef RESOURCE_SUPPORT_LINFLEXD_16
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX16_LLD_RXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX16_LLD_TXI_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
extern ISR(LINFLEX16_LLD_ERR_IRQ_HANDLER);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* RESOURCE_SUPPORT_LINFLEXD_16 */

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(void, LIN_CODE) Lin_LLD_Init(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2CONST(LinLldConfig, AUTOMATIC, LIN_APPL_CONST) sLin_Config);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(void, LIN_CODE) Lin_LLD_Start(CONST(uint8, AUTOMATIC) u8Lin_Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_LLD_Master_Transmit(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) spLin_PduInfoPtr);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_LLD_GoToSleep(CONST(uint8, AUTOMATIC) u8Lin_Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_LLD_GoToSleepInternal(CONST(uint8, AUTOMATIC) u8Lin_Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(void, LIN_CODE) Lin_LLD_WakeupInternal(CONST(uint8, AUTOMATIC) u8Lin_Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_LLD_CheckWakeup(CONST(uint8, AUTOMATIC) u8Lin_Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(void, LIN_CODE) Lin_LLD_Wakeup(CONST(uint8, AUTOMATIC) u8Lin_Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Lin_StatusType, LIN_CODE) Lin_LLD_HardwareGetStatus(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) u8pLin_SduPtr);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
 
#ifdef __cplusplus
}
#endif

#endif /* LINFLEX_H */

/** @} */

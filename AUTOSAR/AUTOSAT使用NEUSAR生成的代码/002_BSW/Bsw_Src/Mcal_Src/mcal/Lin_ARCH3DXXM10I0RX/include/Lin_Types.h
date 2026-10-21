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
*   @file    Lin_Types.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Lin - Isolation level header file for LIN driver.
*   @details Header file for function definition on isolation level betwen high and low level driver.
*
*   @addtogroup LIN
*   @{
*/

/*PRQA S 0722 EOF*/

#ifndef LIN_TYPES_H
#define LIN_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/*==============================================INCLUDE FILES=======================================*/
#include "Std_Types.h"
#include "EcuM_Cbk.h"
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define LIN_INSTANCE_PLUGIN                        0
#define LIN_VENDOR_ID_PLUGIN                       176
#define LIN_AR_REL_MJR_VERSION_PLUGIN              4
#define LIN_AR_REL_MNR_VERSION_PLUGIN              4
#define LIN_AR_REL_REV_VERSION_PLUGIN              0
#define LIN_SW_MAJOR_VERSION_PLUGIN                3
#define LIN_SW_MINOR_VERSION_PLUGIN                0
#define LIN_SW_PATCH_VERSION_PLUGIN                0
/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define LIN_TYPES_H_VENDOR_ID                            LIN_VENDOR_ID_PLUGIN
#define LIN_TYPES_H_AR_REL_MAJOR_VER                     LIN_AR_REL_MJR_VERSION_PLUGIN
#define LIN_TYPES_H_AR_REL_MINOR_VER                     LIN_AR_REL_MNR_VERSION_PLUGIN
#define LIN_TYPES_H_AR_REL_REV_VER                       LIN_AR_REL_REV_VERSION_PLUGIN
#define LIN_TYPES_H_SW_MAJOR_VER                         LIN_SW_MAJOR_VERSION_PLUGIN
#define LIN_TYPES_H_SW_MINOR_VER                         LIN_SW_MINOR_VERSION_PLUGIN
#define LIN_TYPES_H_SW_PATCH_VER                         LIN_SW_PATCH_VERSION_PLUGIN
/* ============================================FILE VERSION CHECKS=================================== */
#if (LIN_VENDOR_ID_PLUGIN != LIN_TYPES_H_VENDOR_ID)
    #error " NON-MATCHED DATA : LIN_TYPES_H_VENDOR_ID "
#endif
#if (LIN_AR_REL_MJR_VERSION_PLUGIN != LIN_TYPES_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_TYPES_H_AR_REL_MAJOR_VER "
#endif
#if (LIN_AR_REL_MNR_VERSION_PLUGIN != LIN_TYPES_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_TYPES_H_AR_REL_MINOR_VER "
#endif
#if (LIN_AR_REL_REV_VERSION_PLUGIN != LIN_TYPES_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : LIN_TYPES_H_AR_REL_REV_VER "
#endif
#if (LIN_SW_MAJOR_VERSION_PLUGIN != LIN_TYPES_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_TYPES_H_SW_MAJOR_VER "
#endif
#if (LIN_SW_MINOR_VERSION_PLUGIN != LIN_TYPES_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_TYPES_H_SW_MINOR_VER "
#endif
#if (LIN_SW_PATCH_VERSION_PLUGIN != LIN_TYPES_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : LIN_TYPES_H_SW_PATCH_VER "
#endif
/*=================================================CONSTANTS========================================*/

/*============================================DEFINES AND MACROS====================================*/
#define LIN_MODULE_ID                            82

/* Master Request Diagnostic Frame ID 0x3C.*/
#define LIN_REQUEST_DIAG_ID_U32     ((uint32)0x3CU)

/* Slave Response Diagnostic Frame ID 0x3D.*/
#define LIN_RESPONSE_DIAG_ID_U32     ((uint32)0x3DU)

/*   Sleep command length frame.*/ 
#define LIN_DATA_LENGTH_8_U32       ((uint32)7U)        

/* Sleep command frame: 0xFF data. */
#define LIN_DATA_255_U32            ((uint32)255U)         

/* Sleep command frame: 0x00 data. */
#define LIN_DATA_0_U32              ((uint32)0U)         

/* Wakeup command frame: 0xF0 data. */
#define LIN_DATA_WAKEUP_U32         ((uint32)0xF0U)

/* 11 Bit break. */
#define LINF_11_BREAK_BIT_U8         ((uint8)11U)     

#define LIN_CH_SLEEP_PENDING    ((uint8)0x01U)
#define LIN_CH_SLEEP_STATE      ((uint8)0x02U)
#define LIN_CH_OPERATIONAL      ((uint8)0x03U)
#define LIN_CH_NOT_READY_STATE     ((uint8)0x04U)
#define LIN_CH_READY_STATE         ((uint8)0x05U)
#define LIN_TX_COMPLETE_STATE      ((uint8)0x06U)
#define LIN_RX_COMPLETE_STATE      ((uint8)0x07U)
#define LIN_CH_RECEIVE_NOTHING_STATE   ((uint8)0x08U)

#define LIN_NO_ERROR               ((uint8)0x00U)
#define LIN_BIT_ERROR              ((uint8)0x01U)
#define LIN_CHECKSUM_ERROR         ((uint8)0x02U)
#define LIN_SYNCH_FIELD_ERROR      ((uint8)0x03U)
#define LIN_BREAK_DELIMITER_ERROR  ((uint8)0x04U)
#define LIN_IDENTIFIER_PARITY_ERROR    ((uint8)0x05U)
#define LIN_FRAMING_ERROR          ((uint8)0x06U)
#define LIN_BUFFER_OVER_RUN_ERROR  ((uint8)0x07U)
#define LIN_NOISE_ERROR            ((uint8)0x08U)
#define LIN_TIMEOUT_ERROR          ((uint8)0x09U)

#define LIN_TX_MASTER_RES_COMMAND_U8  ((uint8)0x01U)
#define LIN_TX_SLAVE_RES_COMMAND_U8   ((uint8)0x02U)
#define LIN_TX_SLAVETOSLAVE_COMMAND_U8   ((uint8)0x03U)
#define LIN_TX_SLEEP_COMMAND_U8       ((uint8)0x04U)
#define LIN_TX_NO_COMMAND_U8          ((uint8)0x05U)

/*===================================================ENUMS==========================================*/

typedef enum
{
    LIN_UNINIT = 0x0U,
    LIN_INIT   = 0x1U
} Lin_DriveState_Type;

typedef enum
{
    LIN_MASTER_NODE       = 0x0U,
    LIN_SLAVE_NODE        = 0x1U
} Lin_NodeType;

typedef enum
{
    LIN_STATE_SLEEP = (uint8)0x00U,
    LIN_STATE_INIT,
    LIN_STATE_IDLE,
    LIN_STATE_BREAK,
    LIN_STATE_DEL,
    LIN_STATE_FIELD,
    LIN_STATE_IDENTIFIER,
    LIN_STATE_HEADER_RT,
    LIN_STATE_DATA_RT,
    LIN_STATE_CCS
}LIN_LINSR_LINSTATE;

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

typedef enum
{
    LIN_NOTIFY_INIT = (uint8)0x00U,
	LIN_NOTIFY_SLEEP
}Lin_NotificationType;

typedef P2FUNC(void, LIN_APPL_CODE, Lin_NotificationFunc)(VAR(uint8, LIN_VAR) u8LinHwChannel, VAR(Lin_NotificationType, LIN_VAR)eLinNotify);

typedef struct
{
        VAR(uint8, LIN_VAR) u8LinChannelID; /*!< Lin Channel ID */
        VAR(uint8, LIN_VAR) u8LinHwChannel; /*!< LIN Hardware Channel.*/
        CONST(Lin_NodeType, LIN_CONST) eLinNodeType; /*!< LIN Node Type.*/
        VAR(uint32, LIN_VAR) u32Lin_BaudRate_RegValue; /*!< LIN baudrate value.*/
        VAR(uint8, LIN_VAR) u16LinChannelWakeupSupport; /*!< Is wake-up supported by the LIN channel ?.*/
        VAR(EcuM_WakeupSourceType, LIN_VAR) LinChannelEcuMWakeupSource; /*!< [SWS_Lin_00098] This parameter contains a reference to the Wakeup Source for this controller as defined in the ECU State Manager.*/
        VAR(uint8, LIN_VAR) u8LinChannelBrkLengthMaster; /*!< These bits indicate the Break length in Master mode.*/
        VAR(uint8, LIN_VAR) u8LinChannelBrkLengthSlave; /*!< These bits indicate the Break length in Slave mode.*/
        VAR(uint8, LIN_VAR) u8ResponseTimeout; /*!< Response timeout value LINTOCR[RTO].*/
        VAR(uint8, LIN_VAR) u8HeaderTimeout; /*!< Header timeout value LINTOCR[HTO].*/
        VAR(uint8, LIN_VAR) u8LinDmaSupport;
        VAR(uint8, LIN_VAR) DmaTxChannel; /*!< LIN DMA Hardware Channel.*/
        VAR(uint8, LIN_VAR) DmaRxChannel; /*!< LIN DMA Hardware Channel.*/
        VAR(Lin_NotificationFunc, LIN_VAR) LinNotificationFunc;
} Lin_ChannelConfigType;

/*====================================GLOBAL VARIABLE DECLARATIONS==================================*/

/*===============================================LOCAL FUNCTIONS====================================*/

/*==============================================GLOBAL FUNCTIONS====================================*/



#ifdef __cplusplus
}
#endif

#endif


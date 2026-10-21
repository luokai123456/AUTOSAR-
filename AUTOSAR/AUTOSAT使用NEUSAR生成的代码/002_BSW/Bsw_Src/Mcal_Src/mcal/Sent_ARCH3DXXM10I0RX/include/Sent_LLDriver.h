/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* @file     srx_lld.h
* @version  3.0.0
* @date     2023 - 01 - 01
* @brief    Initial version.
*
*****************************************************************************/
/*PRQA S 1535 EOF*/
#ifndef LLD_INC_SRX_LLD_H_
#define LLD_INC_SRX_LLD_H_

#include "derivative.h"
#include "Sent_Cfg.h"

#ifdef RESOURCE_SUPPORT_SENT

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SENT_VENDOR_ID_H                     176
#define SENT_MODULE_ID_H                     100
#define SENT_AR_MAJOR_VER_H                  4
#define SENT_AR_MINOR_VER_H                  4
#define SENT_AR_PATCH_VER_H                  0
#define SENT_SW_MAJOR_VER_H                  3
#define SENT_SW_MINOR_VER_H                  0
#define SENT_SW_PATCH_VER_H                  0

/*============================================FILE VERSION CHECKS===================================*/

#if (SENT_VENDOR_ID_H != SENT_VENDOR_ID)
#error "NON-MATCHED DATA : SENT_CFG_VENDOR_ID"
#endif

#if (SENT_AR_MAJOR_VER_H != SENT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_MAJOR_VER"
#endif
#if (SENT_AR_MINOR_VER_H != SENT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_MINOR_VER"
#endif
#if (SENT_AR_PATCH_VER_H != SENT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_PATCH_VER"
#endif

#if (SENT_SW_MAJOR_VER_H != SENT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_MAJOR_VER"
#endif
#if (SENT_SW_MINOR_VER_H != SENT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_MINOR_VER"
#endif
#if (SENT_SW_PATCH_VER_H != SENT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_PATCH_VER"
#endif

#if SENT_DMA_EN
#include "eDma.h"
#endif

#define SENT_DET_ERR(x)                         DEV_ASSERT(x)

typedef  struct SRX_tag                         SRX_Type;

/* IRCOSC - Peripheral instance base addresses */
/** Peripheral SRX0 base address */
#define SRX_0_BASE                              (0xFFE5C000u)
/** Peripheral SRX0  base pointer */
#define SRX0_StPtr                              ((SRX_Type *)SRX_0_BASE)
/** Peripheral SRX1 base address */
#define SRX_1_BASE                              (0xFBE5C000u)
/** Peripheral SRX1 base pointer */
#define SRX1_StPtr                              ((SRX_Type *)SRX_1_BASE)
/** Array initializer of IRCOSC peripheral base addresses */
#define SRX_BASE_ADDRS                          { SRX_0_BASE,SRX_1_BASE }
/** Array initializer of IRCOSC peripheral base pointers */
#define SRX_BASE_PTRS                           { SRX0_StPtr, SRX1_StPtr}

#define SRX_INSTANCE_COUNT                      2u
#define SRX_CLK_CTRL_PRSC_WIDTH                 14u

#ifdef FEATURE_SRX_HAS_COMBINED_IRQ
#define SRX_CH_COUNT                            2u
#define SRX0_CHANNEL_COUNT                      13u
#define SRX1_CHANNEL_COUNT                      12u
#else
#define SRX_CH_COUNT                            2u
#define SRX0_CHANNEL_COUNT                      8u
#define SRX1_CHANNEL_COUNT                      7u
#endif

#define SRX_CHANNEL_COUNT                       GET_MAX((SRX0_CHANNEL_COUNT),(SRX1_CHANNEL_COUNT))

/**
 * Used for bringing the register to a default reset state
 */
#define SRX_GBL_CTRL_RESET_VALUE                (0x00010010u)
#define SRX_CHNL_EN_RESET_VALUE                 (0x00000000u)
#define SRX_DATA_CTRL1_RESET_VALUE              (0x11000000u)
#define SRX_FDMA_CTRL_RESET_VALUE               (0x00000000u)
#define SRX_SDMA_CTRL_RESET_VALUE               (0x00000000u)
#define SRX_FRDY_IE_RESET_VALUE                 (0x00000000u)
#define SRX_SRDY_IE_RESET_VALUE                 (0x00000000u)
#define SRX_CHn_CLK_CTRL_RESET_VALUE            (0x00008000u)
#define SRX_CHn_CONFIG_RESET_VALUE              (0x00000104u)



/**
 * @brief Idle check configuration
 *
 * Contains the possible values use in setting
 * up the IDLE pulse diagnostics.
 *
 * Implements : srx_idle_cnt_cfg_t_Class
 */
typedef enum
{
    SRX_BUS_IDLE_DISABLED,
    SRX_BUS_IDLE_245_CLK_TICKS,
    SRX_BUS_IDLE_508_CLK_TICKS,
    SRX_BUS_IDLE_1016_CLK_TICKS,
    SRX_BUS_IDLE_2032_CLK_TICKS
} srx_idle_cnt_cfg_t;

/**
 * @brief Calibration configuration
 *
 * Contains the allowed values for configuring
 * the variance in the calibration pulse.
 *
 * Implements : srx_calib_pulse_var_cfg_t_Class
 */
typedef enum
{
    SRX_CALIB_VAR_20_PERCENT,
    SRX_CALIB_VAR_25_PERCENT
} srx_calib_pulse_var_cfg_t;

/**
 * @brief Diagnostics pulse configuration
 *
 * Contains the possible value for configuring
 * the diagnostics pulse checks.
 *
 * Implements : srx_pulse_cfg_t_Class
 */
typedef enum
{
    SRX_PULSE_CHECK_BOTH,
    SRX_PULSE_CHECK_PAUSE
} srx_pulse_cfg_t;

/**
 * @brief Pause pulse configuration
 *
 * Contains the possible value of the PAUSE pulse
 * configuration.
 *
 * Implements : srx_pause_pulse_cfg_t_Class
 */
typedef enum
{
    SRX_PAUSE_PULSE_DISABLED,
    SRX_PAUSE_PULSE_ENABLED
} srx_pause_pulse_cfg_t;

/**
 * @brief Successive calibration check method
 *
 * This contains the values use in the configuration
 * for the successive calibration pulse check field.
 *
 * Implements : srx_succ_cal_check_cfg_t_Class
 */
typedef enum
{
    SRX_SUCC_CAL_CHK_LOW_LATENCY,
    SRX_SUCC_CAL_CHK_PREFFERED
} srx_succ_cal_check_cfg_t;

/**
 * @brief Fast/Slow CRC type
 *
 * Contains the possible values for the configuration
 * of the CRC type.
 *
 * Implements : srx_msg_crc_t_Class
 */
typedef enum
{
    SRX_CRC_RECOMMENDED, /* Additional 0 data nibble XORed with the rest of the nibbles */
    SRX_CRC_LEGACY /* No additional 0 data nibble is XORed */
} srx_msg_crc_t;

/**
 * @brief Pause pulse configuration
 *
 * Contains the possible value of the PAUSE pulse
 * configuration.
 *
 * Implements :srx_fcrc_sc_cfg_t_Class
 */
typedef enum
{
    SRX_FCRC_NOT_INCLUDE,
    SRX_FCRC_INCLUDE
} srx_fcrc_sc_cfg_t;

/**
 * @brief Pause pulse configuration
 *
 * Contains the possible value of the PAUSE pulse
 * configuration.
 *
 * Implements : srx_fcrc_check_cfg_t_Class
 */
typedef enum
{
    SRX_FCRC_CHECK_ENABLE,
    SRX_FCRC_CHECK_DISABLE
} srx_fcrc_check_cfg_t;

/**
 * @brief Raw message data type
 *
 * Raw message type. It is the actual format transferred by the
 * DMA peripheral and contained inside the Rx channel registers.
 *
 * Implements : srx_raw_msg_t_Class
 */
typedef struct
{
    uint32 dataField0; /*!< Raw data field [0] */
    uint32 dataField1; /*!< Raw data field [1] */
    uint32 dataField2; /*!< Raw data field [2] */
} srx_raw_msg_t;

/**
 * @brief Actual format for a Fast message
 *
 * Contains the actual fields of a complete FAST message.
 *
 * Implements : srx_fast_msg_t_Class
 */
typedef struct
{
    uint32 data; /*!< Data field formed from all possible nibbles */
    uint32 timeStamp; /*!< Message timestamp */
    uint8 channelNumber; /*!< Channel number, 4 bits */
    uint8 statusField; /*!< Status field for the message, 2 bits */
    uint8 crc; /*!< CRC for the fast message, 4 bits */
} srx_fast_msg_t;

/**
 * @brief Slow message type
 *
 * This is determined by the peripheral, at reception.
 *
 * Implements : srx_slow_msg_type_t_Class
 */
typedef enum
{
    SRX_SLOW_TYPE_SHORT, /*!< Standard 4 bit ID, 8 bit Data */
    SRX_SLOW_TYPE_ENHANCED_4_BIT, /*!< Enhanced 4 bit ID, 16 bit Data */
    SRX_SLOW_TYPE_ENHANCED_8_BIT /*!< Enhanced 8 bit ID, 12 bit Data */
} srx_slow_msg_type_t;

/**
 * @brief Actual format for a Slow message
 *
 * Contains the actual fields of a complete SLOW message
 * Lengths for the actual fields depend on the actual message type
 * Please see the SAE J2716 specification.
 *
 * Implements : srx_slow_msg_t_Class
 */
typedef struct
{
    uint32 timeStamp; /*!< Message timestamp */
    uint16 data; /*!< Data field */
    srx_slow_msg_type_t type; /*!< Message type */
    uint8 id; /*!< Message ID */
    uint8 channelNumber; /*!< Channel number, 4 bits */
    uint8 crc; /*!< CRC for the slow message, max 6 bits */
} srx_slow_msg_t;

/**
 * @brief Input filter settings
 *
 * Contains all the possible values for configuring
 * the channel hardware input filter (glitch filter).
 * It is expressed in a number of protocol clocks
 * during which the signal should maintain it's value
 * to be considered stable.
 *
 * Implements : srx_channel_input_filter_t_Class
 */
typedef enum
{
    SRX_INPUT_FILTER_NONE, /*!< No filtering */
    SRX_INPUT_FILTER_1,
    SRX_INPUT_FILTER_2,
    SRX_INPUT_FILTER_4,
    SRX_INPUT_FILTER_8,
    SRX_INPUT_FILTER_16,
    SRX_INPUT_FILTER_32,
    SRX_INPUT_FILTER_64,
    SRX_INPUT_FILTER_128
} srx_channel_input_filter_t;

/**
 * @brief Type of issued callback
 *
 * Implements : srx_callback_type_t_Class
 */
typedef enum
{
    SRX_CALLBACK_SLOW_DMA_RX_COMPLETE,
    SRX_CALLBACK_FAST_DMA_RX_COMPLETE,
    SRX_CALLBACK_SLOW_RX_COMPLETE,
    SRX_CALLBACK_FAST_RX_COMPLETE,
    SRX_CALLBACK_RX_ERROR
} srx_callback_type_t;

/**
 * @brief Type of callback function
 *
 * Implements : srx_callback_func_t_Class
 */
typedef void(* srx_callback_func_t)(uint32 instance, uint32 channel, srx_callback_type_t type, void * param);

/**
 * @brief Type of callback structure
 *
 * Implements : srx_callback_t_Class
 */
#if SENT_DMA_EN
typedef struct
{
    eDMACallbackType function; /*!< Callback function */
    void * param; /*!< User parameter */
} srx_callback_t;
#else
typedef struct
{
    srx_callback_func_t function; /*!< Callback function */
    void * param; /*!< User parameter */
} srx_callback_t;
#endif

/**
 * @brief Fast messages configuration
 *
 * Contains all the necessary fields used in the
 * configuration of the fast message channel.
 *
 * Implements : srx_fast_msg_config_t_Class
 */
typedef struct
{
    /* Message length */
    uint8 numberOfNibbles; /*!< Number of nibbles for the message. Valid values 1 >= x <= 6 */

    /* DMA enabler for the specific channel */
    boolean dmaEnable; /*!< Enable DMA transfers */

    /* CRC related */
    srx_fcrc_sc_cfg_t crcIncludeStatus; /*!< Include the STATUS nibble in the CRC calculation */
    srx_fcrc_check_cfg_t disableCrcCheck; /*!< Disable CRC checks for the channel */
    srx_msg_crc_t crcType; /*!< CRC type */
} srx_fast_msg_config_t;

/**
 * @brief Slow messages configuration
 *
 * Contains all the necessary fields used in the
 * configuration of the slow message channel.
 *
 * Implements : srx_slow_msg_config_t_Class
 */
typedef struct
{
    /* DMA enabler for the specific channel */
    boolean dmaEnable; /*!< Enable DMA transfers */

    /* CRC related */
    srx_msg_crc_t crcType; /*!< CRC type */
} srx_slow_msg_config_t;

/**
 * @brief Diagnostics configuration
 *
 * Contains all the fields used in the configuration of the
 * diagnostics side of the driver. For a better understanding
 * of these settings, the SAE J2716 specification and
 * the user manual for the current part should be read.
 *
 * Implements : srx_diag_config_t_Class
 */
typedef struct
{
    uint32 diagEvents; /*!< Flags for active diagnostics events */
    srx_idle_cnt_cfg_t idleCount; /*!< Maximum allowed IDLE time */
    srx_calib_pulse_var_cfg_t calibVar; /*!< Valid calibration pulse range */
    srx_pulse_cfg_t diagPulse; /*!< Selection for which diagnostics to run for pulses*/
    srx_pause_pulse_cfg_t pausePulse; /*!< Selection of PAUSE pulse*/
    srx_succ_cal_check_cfg_t succesiveCal; /*!< Successive calibration check method */
} srx_diag_config_t;

/**
 * @brief Channel configuration structure
 *
 * Contains all the required fields for the configuration
 * of a single channel inside the peripheral.
 *
 * Implements : srx_channel_config_t_Class
 */
typedef struct
{
    uint8 channelId; /*!< Designated channel */
    uint8 tickDuration; /*!< Tick duration in microseconds */
    srx_channel_input_filter_t inputFilter; /*!< Channel input filter configuration */
    srx_diag_config_t diagConfig; /*!< Diagnostics configuration structure*/
    srx_fast_msg_config_t fastMsgConfig; /*!< Fast messages configuration structure */
    srx_slow_msg_config_t slowMsgConfig; /*!< Slow messages configuration structure */
} srx_channel_config_t;

/**
 * @brief State structure
 *
 * Contains internal driver state data.
 *
 * Implements : srx_state_t_Class
 */
typedef struct
{
/*! @cond DRIVER_INTERNAL_USE_ONLY */
    /* Configuration data */
    srx_raw_msg_t * fastMsgDmaPtr; /*!< DMA transfer target pointer for fast messages */
    srx_raw_msg_t * slowMsgDmaPtr; /*!< DMA transfer target pointer for slow messages */
    uint8 fastDmaChannel; /*!< DMA channel on which fast message transfers are performed */
    uint8 slowDmaChannel; /*!< DMA channel on which slow message transfers are performed */
    srx_callback_t callbackFunc; /*!< Callback function */
    uint32 channelEvents[SRX_CHANNEL_COUNT]; /*!< Event configuration for each channel */
    boolean activeChannels[SRX_CHANNEL_COUNT]; /*!< Activation state for the specific channel */
    boolean fastDmaEnabled[SRX_CHANNEL_COUNT]; /*!< Holds the state for the Fast DMA channel */
    boolean slowDmaEnabled[SRX_CHANNEL_COUNT]; /*!< Holds the state for the Slow DMA channel */
    uint8 instanceId; /*!< Instance Id number */
/*! @endcond */
} srx_state_t;

/**
 * IRQ IDs
 */
typedef enum {
    SRX_IRQ_FAST = 0,
    SRX_IRQ_SLOW = 1,
    SRX_IRQ_ERROR = 2
} srx_interrupt_id_t;

/**
 * @brief Configuration structure
 *
 * Contains all the fields necessary for a complete
 * configuration of the peripheral
 *
 * Implements : srx_driver_user_config_t_Class
 */
#if SENT_DMA_EN
typedef struct
{
    /* Dma related transfers are common to all channels */
    srx_raw_msg_t * fastMsgDmaPtr; /*!< Initial DMA target buffer */
    srx_raw_msg_t * slowMsgDmaPtr; /*!< Initial DMA target buffer */
    srx_callback_t  fastCallback; /*!< Callback function */
    srx_callback_t  slowCallback; /*!< Callback function */
    uint8 slowDmaChannel; /*!< Assigned DMA channel for slow messages */
    uint8 fastDmaChannel; /*!< Assigned DMA channel for fast messages */
    boolean fastDmaFIFOEnable; /*!< Enable FIFO for Fast DMA transfers */
    uint8 fastDmaFIFOSize; /*!< Minimum FIFO size to trigger a Fast DMA transfer */

    /* Unique instances for each channel */
    const srx_channel_config_t * channelConfig; /*!< Pointer to a channel configuration list */
    uint8 numOfConfigs; /*!< Number of configurations in the channel configuration list */
} srx_driver_user_config_t;
#else
typedef struct
{
    /* Dma related transfers are common to all channels */
    srx_raw_msg_t * fastMsgDmaPtr; /*!< Initial DMA target buffer */
    srx_raw_msg_t * slowMsgDmaPtr; /*!< Initial DMA target buffer */
    srx_callback_t callbackFunc; /*!< Callback function */
    uint8 slowDmaChannel; /*!< Assigned DMA channel for slow messages */
    uint8 fastDmaChannel; /*!< Assigned DMA channel for fast messages */
    boolean fastDmaFIFOEnable; /*!< Enable FIFO for Fast DMA transfers */
    uint8 fastDmaFIFOSize; /*!< Minimum FIFO size to trigger a Fast DMA transfer */

    /* Unique instances for each channel */
    const srx_channel_config_t * channelConfig; /*!< Pointer to a channel configuration list */
    uint8 numOfConfigs; /*!< Number of configurations in the channel configuration list */
} srx_driver_user_config_t;
#endif

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_SetTimestampPrescaler(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) value);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_SetChannelPrescaler(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(uint16 , AUTOMATIC) prescaler);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_SetChannelCompensation(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(boolean , AUTOMATIC) state);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_SetChannelStatus(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(boolean , AUTOMATIC) enable);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_SetPeripheralStatus(CONST(uint8, AUTOMATIC) instance, CONST(boolean, AUTOMATIC) enable);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_SetFastRxInterrupt(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(boolean , AUTOMATIC) enable);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(boolean, SENT_CODE) SRX_HW_GetSlowRxStatus(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_SetSlowRxInterrupt(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(boolean , AUTOMATIC) enable);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_GetFastRawMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, P2VAR(srx_raw_msg_t, AUTOMATIC, SENT_APPL_DATA) rawMsg);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_InitDiag(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, P2CONST(srx_diag_config_t, AUTOMATIC, SENT_APPL_DATA) config);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_InitSlowMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, P2CONST(srx_slow_msg_config_t, AUTOMATIC, SENT_APPL_DATA) config);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_InitFastMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, P2CONST(srx_fast_msg_config_t, AUTOMATIC, SENT_APPL_DATA) config);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(uint8, SENT_CODE) SRX_LLD_CompTimestampPrescaler(CONST(uint32, AUTOMATIC) u32clock);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(uint32, SENT_CODE) SRX_LLD_ComputeChannelPrescaler(CONST(float32, AUTOMATIC) reqTick, CONST(uint32, AUTOMATIC) u32clock);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_IRQ_FastHandler(CONST(uint8 , AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_GetEvents(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel, P2VAR(uint32, AUTOMATIC, SENT_APPL_DATA) events);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_GetFastMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel, P2VAR(srx_fast_msg_t, AUTOMATIC, SENT_APPL_DATA) message);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_GetSlowMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel, P2VAR(srx_slow_msg_t, AUTOMATIC, SENT_APPL_DATA) message);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_GetFastMsgFromRaw(P2VAR(srx_fast_msg_t, AUTOMATIC, SENT_APPL_DATA) msg, P2CONST(srx_raw_msg_t, AUTOMATIC, SENT_APPL_DATA) rawMsg);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_GetSlowMsgFromRaw(P2VAR(srx_slow_msg_t, AUTOMATIC, SENT_APPL_DATA) msg, P2CONST(srx_raw_msg_t, AUTOMATIC, SENT_APPL_DATA) rawMsg);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(boolean, SENT_CODE) SRX_LLD_GetSlowRxStatus(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(boolean, SENT_CODE) SRX_LLD_GetFastRxStatus(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(boolean, SENT_CODE) SRX_LLD_GetErrorStatus(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_Deinit(CONST(uint8, AUTOMATIC) instance);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_IRQ_SlowHandler(CONST(uint8 , AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_IRQ_RxErrHandler(CONST(uint8 , AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#if SENT_DMA_EN
extern VAR(srx_raw_msg_t, SENT_VAR) srxRawMessageBuffer_slow[1];
extern VAR(srx_raw_msg_t, SENT_VAR) srxRawMessageBuffer_fast[1];
extern CONST(srx_driver_user_config_t, SENT_VAR) srx1_InitConfig0;
extern CONST(srx_driver_user_config_t, SENT_VAR) srx1_InitConfig1;

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(boolean, SENT_CODE) SRX_LLD_EDmaConfig ( CONST(uint8, AUTOMATIC) instance, \
    CONST(boolean , AUTOMATIC) fDmaEn,CONST(boolean , AUTOMATIC) sDmaEn, \
    P2CONST(srx_driver_user_config_t, SENT_CONST,SENT_APPL_CONST) DmaconfigPtr);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_SetFastDma(CONST(uint32, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel, CONST(boolean , AUTOMATIC) enable);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_SetSlowDma(CONST(uint32, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel, CONST(boolean , AUTOMATIC) enable);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif /* SENT_DMA_EN */

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX_LLD_SetEventConfig(CONST(uint32, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel, CONST(uint32, AUTOMATIC) events);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#endif /* RESOURCE_SUPPORT_SENT */

#endif /* LLD_INC_SRX_LLD_H_ */

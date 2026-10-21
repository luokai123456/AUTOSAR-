/*PRQA S 0779 EOF*/
/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Fr
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_3_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Fr_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Fr MCAL driver.
*
*   @addtogroup Fr
*   @{
*/

#ifndef FR_CFG_H
#define FR_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "derivative.h"
#ifdef RESOURCE_SUPPORT_FLEXRAY
#include "Fr_GeneralTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/* Version and Check Begin */
/* Version Info Begin */
#define FR_CFG_H_VENDOR_ID                          176
#define FR_CFG_H_AR_RELEASE_MAJOR_VERSION           4
#define FR_CFG_H_AR_RELEASE_MINOR_VERSION           4
#define FR_CFG_H_AR_RELEASE_REVISION_VERSION        0
#define FR_CFG_H_SW_MAJOR_VERSION                   3
#define FR_CFG_H_SW_MINOR_VERSION                   0
#define FR_CFG_H_SW_PATCH_VERSION                   0

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/






#define FR_PRECOMPILE_SUPPORT                 STD_OFF
#define FR_CTRL_TEST_COUNT                    1
#define FR_DEV_ERROR_DETECT                   STD_ON
#define FR_DISABLE_LPDU_SUPPORT               STD_ON
#define FR_PREPARE_LPDU_SUPPORT               STD_ON
#define FR_RECONFIG_LPDU_SUPPORT              STD_ON
#define FR_RXSTRINGENTCHECK                   STD_OFF
#define FR_RX_STRINGENT_LENGTH_CHECK          STD_OFF
#define FR_VERSION_INFO_API                   STD_ON
#define FR_DEM_EVENT_DETECT                   STD_ON
#define FR_INDEX                              0
#define FR_NUM_CTRL_SUPPORTED                 1
#define Crtl_1                                0
#define FR_NUMBER_MB                          128
#define FR_INSTANCE_ID_U8                     0

/* The values are used to determine which message buffers defined in
 a Fr_buffer_info_type structure will be used for the FlexRay module configuration */
typedef VAR(uint16, FR_VAR) Fr_index_selector_type;

/* Type definition for the Fr_FIFO_range_filter_mode field
   of the Fr_FIFO_range_filter_config_type structure. */
typedef enum
{
   FR_ACCEPTANCE = 0U,
   FR_REJECTION
} Fr_FIFO_range_filter_mode_type;

/* Type definition for the FIFO_range_filters_config field
   of the Fr_receive_FIFO_config structure. */
typedef struct
{
    VAR(boolean, FR_VAR) range_filter_enable;                    /* TRUE - Range Filter is enabled */
    VAR(Fr_FIFO_range_filter_mode_type, FR_VAR) range_filter_mode;  /* Acceptance or Rejection mode */
    VAR(uint8, FR_VAR) range_filter_lower_interval;            /* SID0 - Slot ID - Lower interval boundary */
    VAR(uint8, FR_VAR) range_filter_upper_interval;           /* SID1 - Slot ID - Upper interval boundary */
} Fr_FIFO_range_filters_type;

/* Structure of this type contains configuration information
   for receive FIFO structure. */
typedef struct
{
    VAR(Fr_ChannelType, FR_VAR) FIFO_channel;                            /* FIFO channel; Channel A = FR_CHANNEL_A, channel B = FR_CHANNEL_B */
    VAR(uint16, FR_VAR) FIFO_depth;                                       /* FIFO depth */
    VAR(uint8, FR_VAR) FIFO_entry_size;                                  /* FIFO entry size */
    VAR(uint8, FR_VAR) FIFO_message_ID_acceptance_filter_value;         /* FIFO message ID acceptance filter value */
    VAR(uint16, FR_VAR) FIFO_message_ID_acceptance_filter_mask;          /* FIFO message ID acceptance filter mask */
    VAR(uint8, FR_VAR) FIFO_frame_ID_rejection_filter_value;            /* FIFO frame ID rejection filter value */
    VAR(uint16, FR_VAR) FIFO_frame_ID_rejection_filter_mask;             /* FIFO frame ID rejection filter mask */
    VAR(Fr_FIFO_range_filters_type, FR_VAR) FIFO_range_filters_config[4];  /* Reference to range filters configuration structure */
    VAR(boolean, FR_VAR) FIFO_interrupt_enable;                          /* FIFO interrupt enable, can be enabled also by Fr_enable_interrupts() function */
} Fr_FIFO_config_type;

/* Internal FlexRay UNIFIED Driver structure
   The structure contains information about already configured FIFO storages.
   FlexRay driver stores a FIFO configuration data into this structure immediately it configures
   FIFO registers. Driver uses this structure for Data Field Offset calculation. */
typedef struct
{
    VAR(boolean, FR_VAR) FIFO_1_used;            /* The first FIFO already configured? */
    VAR(Fr_ChannelType, FR_VAR) FIFO_1_channel; /* The first configured FIFO - FIFO A or FIFO B */
    VAR(uint16, FR_VAR) FIFO_1_depth;             /* The first configured FIFO - FIFO depth */
    VAR(uint8, FR_VAR) FIFO_1_entry_size;        /* The first configured FIFO - FIFO entry size */
    VAR(boolean, FR_VAR) FIFO_2_used;            /* The second FIFO already configured? */
    VAR(Fr_ChannelType, FR_VAR) FIFO_2_channel; /* The second configured FIFO - FIFO A or FIFO B */
    VAR(uint16, FR_VAR) FIFO_2_depth;             /* The second configured FIFO - FIFO depth */
    VAR(uint8, FR_VAR) FIFO_2_entry_size;        /* The second configured FIFO - FIFO entry size */
} Fr_FIFO_info_type;

/* Structure of this type contains configuration
   information for one receive buffer. */
typedef struct
{
    VAR(uint8, FR_VAR) receive_frame_ID;                    /* Receive frame ID */
    VAR(uint16, FR_VAR) RxSduLength;                   
    VAR(Fr_ChannelType, FR_VAR) receive_channel_enable;     /* Receive channel enable */
    VAR(boolean, FR_VAR) rx_cycle_counter_filter_enable;     /* Receive cycle counter filter enable */
    VAR(uint8, FR_VAR) rx_cycle_counter_filter_value;        /* Receive cycle counter filter value */
    VAR(uint8, FR_VAR) rx_cycle_counter_filter_mask;         /* Receive cycle counter filter mask */
    VAR(boolean, FR_VAR) rx_MB_interrupt_enable;             /* Receive MB interrupt enable */
} Fr_receive_buffer_config_type;

/* Type definition for the transmit_MB_buffering field of
   the Fr_transmit_buffer_config_type structure. */
typedef enum
{
    FR_SINGLE_TRANSMIT_BUFFER = 0U,
    FR_DOUBLE_TRANSMIT_BUFFER
} Fr_transmit_MB_type;

/* Type definition for the transmission_mode field of
   the Fr_transmit_buffer_config_type structure. */
typedef enum
{
    FR_EVENT_TRANSMISSION_MODE = 0U,
    FR_STATE_TRANSMISSION_MODE
} Fr_transmission_type;

/* Type definition for the transmission_commit_mode field
   of the Fr_transmit_buffer_config_type structure. */
typedef enum
{
    FR_STREAMING_COMMIT_MODE = 0U,
    FR_IMMEDIATE_COMMIT_MODE
} Fr_transmission_commit_type;

/* Structure of this type contains configuration
   information for one transmit buffer. */
typedef struct
{
    VAR(uint8, FR_VAR) transmit_frame_ID;                                     /* Transmit frame ID */
    VAR(uint16, FR_VAR) header_CRC;                                           /* Header CRC */
    VAR(uint8, FR_VAR) payload_length;                                        /* Payload length */
    VAR(Fr_transmit_MB_type, FR_VAR) transmit_MB_buffering;                   /* Transmit MB buffering */
    VAR(Fr_transmission_type, FR_VAR) transmission_mode;                      /* Transmission mode */
    VAR(Fr_transmission_commit_type, FR_VAR) transmission_commit_mode;        /* Transmission commit mode */
    VAR(Fr_ChannelType, FR_VAR) transmit_channel_enable;                     /* Transmit channels */
    VAR(boolean, FR_VAR) payload_preamble;                                    /* Payload preamble */
    VAR(boolean, FR_VAR) tx_cycle_counter_filter_enable;                      /* Transmit cycle counter filter enable */
    VAR(uint8, FR_VAR) tx_cycle_counter_filter_value;                         /* Transmit cycle counter filter value */
    VAR(uint8, FR_VAR) tx_cycle_counter_filter_mask;                          /* Transmit cycle counter filter mask */
    VAR(boolean, FR_VAR) tx_MB_interrupt_enable;                              /* Transmit MB interrupt enable */
    /* If tx interrupt is enabled by tx_MB_interrupt_enable parameter, tx_MB_interrupt_transmit_side_enable determines */
    /* whether the interrupt will be enabled at commit side (FALSE - default) or at tranmsit side (TRUE) of the double MB */
    VAR(boolean, FR_VAR) tx_MB_interrupt_transmit_side_enable;   /* Used only for double buffered MB, FALSE - commit side, TRUE - transmit side */
} Fr_transmit_buffer_config_type;

/* Type definition of the configured buffer */
typedef enum
{
    FR_TRANSMIT_BUFFER = 0U,         /* Transmit message buffer */
    FR_RECEIVE_BUFFER,              /* Receive message buffer */
    FR_RECEIVE_FIFO,                /* Receive FIFO buffer */
    FR_RECEIVE_SHADOW               /* Receive shadow buffer */
} Fr_buffer_type;

/* Structure of this type contains configuration
   information for one physical message buffer */
typedef struct
{
    VAR(Fr_buffer_type, FR_VAR) buffer_type;           /* TRANSMIT, RECEIVE, SHADOW or FIFO */
    CONSTP2CONST(void, AUTOMATIC, FR_APPL_CONST) buffer_config_ptr;  /* Reference to buffer configuration structure */
    /* Individual MB - MB index; FIFO buffers - Start index; Receive shadow buffers - no sense */
    VAR(uint8, FR_VAR) buffer_index_init;
    VAR(boolean, FR_VAR) ReconfigureType;
} Fr_buffer_info_type;

/* Type definition of timer ID */
typedef enum
{
    FR_TIMER_T1 = 0U,                /* Timer T1 is selected */
    FR_TIMER_T2                     /* Timer T2 is selected */
} Fr_timer_ID_type;

/* Structure of this type contains configuration
   information of the one low level parameters set */
typedef struct
{
    VAR(uint8, FR_VAR)   G_COLD_START_ATTEMPTS;
    VAR(uint8, FR_VAR)   GD_ACTION_POINT_OFFSET;
    VAR(uint8, FR_VAR)   GD_CAS_RX_LOW_MAX;
    VAR(uint8, FR_VAR)   GD_DYNAMIC_SLOT_IDLE_PHASE;
    VAR(uint8, FR_VAR)   GD_MINISLOT;
    VAR(uint8, FR_VAR)   GD_MINI_SLOT_ACTION_POINT_OFFSET;
    VAR(uint8, FR_VAR)  GD_STATIC_SLOT;
    VAR(uint8, FR_VAR)   GD_SYMBOL_WINDOW;
    VAR(uint8, FR_VAR)   GD_TSS_TRANSMITTER;
    VAR(uint8, FR_VAR)   GD_WAKEUP_SYMBOL_RX_IDLE;
    VAR(uint8, FR_VAR)   GD_WAKEUP_SYMBOL_RX_LOW;
    VAR(uint16, FR_VAR)  GD_WAKEUP_SYMBOL_RX_WINDOW;
    VAR(uint8, FR_VAR)   GD_WAKEUP_SYMBOL_TX_IDLE;
    VAR(uint8, FR_VAR)   GD_WAKEUP_SYMBOL_TX_LOW;
    VAR(uint8, FR_VAR)   G_LISTEN_NOISE;
    VAR(uint16, FR_VAR)  G_MACRO_PER_CYCLE;
    VAR(uint8, FR_VAR)   G_MAX_WITHOUT_CLOCK_CORRECTION_PASSIVE;
    VAR(uint8, FR_VAR)   G_MAX_WITHOUT_CLOCK_CORRECTION_FATAL;
    VAR(uint8, FR_VAR)  G_NUMBER_OF_MINISLOTS;
    VAR(uint8, FR_VAR)  G_NUMBER_OF_STATIC_SLOTS;
    VAR(uint16, FR_VAR)  G_OFFSET_CORRECTION_START;
    VAR(uint8, FR_VAR)   G_PAYLOAD_LENGTH_STATIC;
    VAR(uint8, FR_VAR)   G_SYNC_NODE_MAX;
    VAR(uint8, FR_VAR)   G_NETWORK_MANAGEMENT_VECTOR_LENGTH;
    VAR(boolean, FR_VAR) P_ALLOW_HALT_DUE_TO_CLOCK;
    VAR(uint8, FR_VAR)   P_ALLOW_PASSIVE_TO_ACTIVE;
    VAR(Fr_ChannelType, FR_VAR)  P_CHANNELS;
    VAR(uint8, FR_VAR)  PD_ACCEPTED_STARTUP_RANGE;
    VAR(uint8, FR_VAR)   P_CLUSTER_DRIFT_DAMPING;
    VAR(uint8, FR_VAR)   P_DECODING_CORRECTION;
    VAR(uint8, FR_VAR)   P_DELAY_COMPENSATION_CHA;
    VAR(uint8, FR_VAR)   P_DELAY_COMPENSATION_CHB;
    VAR(uint32, FR_VAR)  PD_LISTEN_TIMEOUT;
    VAR(uint16, FR_VAR)  PD_MAX_DRIFT;
    VAR(uint8, FR_VAR)   P_EXTERN_OFFSET_CORRECTION;
    VAR(uint8, FR_VAR)   P_EXTERN_RATE_CORRECTION;
    VAR(uint8, FR_VAR)  P_KEY_SLOT_ID;
    VAR(boolean, FR_VAR) P_KEY_SLOT_USED_FOR_STARTUP;
    VAR(boolean, FR_VAR) P_KEY_SLOT_USED_FOR_SYNC;
    VAR(uint16, FR_VAR)  P_KEY_SLOT_HEADER_CRC;
    VAR(uint8, FR_VAR)  P_LATEST_TX;
    VAR(uint8, FR_VAR)   P_MACRO_INITIAL_OFFSET_A;
    VAR(uint8, FR_VAR)   P_MACRO_INITIAL_OFFSET_B;
    VAR(uint8, FR_VAR)   P_MICRO_INITIAL_OFFSET_A;
    VAR(uint8, FR_VAR)   P_MICRO_INITIAL_OFFSET_B;
    VAR(uint32, FR_VAR)  P_MICRO_PER_CYCLE;
    VAR(uint16, FR_VAR)  P_OFFSET_CORRECTION_OUT;
    VAR(uint16, FR_VAR)  P_RATE_CORRECTION_OUT;
    VAR(boolean, FR_VAR) P_SINGLE_SLOT_ENABLED;
    VAR(Fr_ChannelType, FR_VAR)  P_WAKEUP_CHANNEL;
    VAR(uint8, FR_VAR)   P_WAKEUP_PATTERN;
    VAR(uint8, FR_VAR)   P_MICRO_PER_MACRO_NOM;
    VAR(uint8, FR_VAR)   P_PAYLOAD_LENGTH_DYN_MAX;
} Fr_low_level_config_type;

/* Type definition for the clock_source field
   of the Fr_HW_config_type structure.
   The values determine the type of used oscillator */
typedef enum
{
    FR_EXTERNAL_OSCILLATOR = 0U,
    FR_INTERNAL_SYSTEM_BUS_CLOCK    /* Only for MC9S12XFR128 CC */
} Fr_clock_source_type;

/* Hardware configuration structure determines used hardware,
   allocated memory addresses and configuration message buffer segments */
typedef struct
{
    VAR(uint32, FR_VAR) CC_base_address;
    VAR(uint32, FR_VAR) CC_FlexRay_memory_base_address;
    VAR(boolean, FR_VAR) synchronization_filtering_enable;     /* Synchronization frame filter enable */
    VAR(Fr_clock_source_type, FR_VAR) clock_source;            /* Protocol engine clock source select */
    VAR(uint8, FR_VAR) prescaler_value;                        /* The value of the PRESCALE or BITRATE bit field in the MCR register */
    VAR(uint8, FR_VAR) MB_segment_1_data_size;                 /* Data size - segment 1 */
    VAR(uint8, FR_VAR) MB_segment_2_data_size;                 /* Data size - segment 2 */
    VAR(uint8, FR_VAR) last_MB_seg_1;                          /* Last MB in segment 1, MBIDXEn with n = [0..last_MB_seg1] */
    VAR(uint8, FR_VAR) last_MB_util;                           /* Last individual MB (Receive, Transmit, Receive Shadow) utilized */
    /* Total number of used MB including FIFO; in range [1..1024] */
    /* E.g. last_MB_util = 20 and FIFO A starts as the 21st MB and it's depth is 10; then */
    /* Number of individual MB = 1 + 20 = 21; Number of FIFO MBs = 10 and */
    /* total_MB_number = 31 */
    VAR(uint8, FR_VAR) total_MB_number;
    VAR(boolean, FR_VAR) allow_cold_start_enable;
    /* The value of the TIMEOUT bit field in the SYMATOR register */
    VAR(uint8, FR_VAR) timeout;                                /* Stored only if the value is not equal to 0 */
    /* Offset of the Sync Frame Table in the FlexRay memory */
    VAR(uint8, FR_VAR) sync_frame_table_offset;               /* Stored only if the value is not equal to 0 */
} Fr_HW_config_type;

/* Structure of this type contains MB configuration parameters which are stored by driver for internal use */
typedef struct
{
    VAR(uint8, FR_VAR) slot_number;             /* Slot number - either 'transmit_frame_ID' or 'receive_frame_ID' */

    VAR(Fr_transmit_MB_type, FR_VAR) transmission_mode;   /* SINGLE or DOUBLE buffered MB */
    VAR(Fr_transmission_type, FR_VAR) transmission_type;  /* STATE or EVENT transmission mode */
    VAR(uint16, FR_VAR) FrifLsduLength;
    VAR(Fr_ChannelType, FR_VAR) Mb_channel_type;
    P2FUNC(void,FR_APPL_CODE,Fr_MB_function_ptr) (VAR(uint8, FR_VAR) buffer_index_init);  /* Callback function with index of MB (except FIFO) */
} Fr_MB_information_internal_type;


/* Structure of this type contains configuration information
   for all receive shadow buffers */
typedef struct
{
    VAR(boolean, FR_VAR) RSBIR_A1_enable;                  /* Rx shadow buffer for channel A, seg 1 - enabled? */
    VAR(boolean, FR_VAR) RSBIR_A2_enable;                  /* Rx shadow buffer for channel A, seg 2 - enabled? */
    VAR(boolean, FR_VAR) RSBIR_B1_enable;                  /* Rx shadow buffer for channel B, seg 1 - enabled? */
    VAR(boolean, FR_VAR) RSBIR_B2_enable;                  /* Rx shadow buffer for channel B, seg 2 - enabled? */
    VAR(uint8, FR_VAR) RSBIR_A1_buffer_number_init;        /* Ch A, seg 1 - the current index of the MB header field */
    VAR(uint8, FR_VAR) RSBIR_A2_buffer_number_init;        /* Ch A, seg 2 - the current index of the MB header field */
    VAR(uint8, FR_VAR) RSBIR_B1_buffer_number_init;        /* Ch B, seg 1 - the current index of the MB header field */
    VAR(uint8, FR_VAR) RSBIR_B2_buffer_number_init;        /* Ch B, seg 2 - the current index of the MB header field */
} Fr_receive_shadow_buffers_config_type;

typedef enum
{
    FR_FIFO_RECEIVED = 0U,
    FR_FIFO_NOT_RECEIVED
} Fr_FIFO_status_type;

/* These values are used to determine if a message buffer has been updated with new data */
typedef enum
{
    FR_TXMB_UPDATED = 0U,
    FR_TXMB_NO_ACCESS
} Fr_tx_MB_status_type;

typedef struct
{
    const VAR(uint32, FR_VAR) CtrlIdx;
    P2CONST(Fr_HW_config_type, AUTOMATIC, *) Fr_HW_config_temp_ptr;
    P2CONST(Fr_low_level_config_type, AUTOMATIC, *) Fr_low_level_config_temp_ptr;
    P2CONST(Fr_buffer_info_type, AUTOMATIC, *) Fr_buffers_config_temp_ptr;
    P2CONST(Fr_index_selector_type, AUTOMATIC, *) Fr_buffer_config_set_temp_ptr;
    P2CONST(Fr_DemErrorType, AUTOMATIC, *) FrDemCtrlTestResultPtr;
} Fr_CtrlCfgType;


typedef struct
{
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, *) Fr_pController[FR_NUM_CTRL_SUPPORTED];
    const VAR(uint32, AUTOMATIC) u32ParCoreId;
} Fr_ConfigType;

#define FR_PB_CONFIG_DECLARATION   extern const VAR(Fr_ConfigType, AUTOMATIC) Fr_cfg;




/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#endif /* RESOURCE_SUPPORT_FLEXRAY */

#ifdef __cplusplus
}
#endif

#endif /*FR_CFG_H*/

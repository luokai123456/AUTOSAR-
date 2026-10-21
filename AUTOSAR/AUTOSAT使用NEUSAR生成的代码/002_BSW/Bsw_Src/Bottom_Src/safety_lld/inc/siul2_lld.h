/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     siul2_lld.h
* @version  1.0
* @date     2023 - 04 - 17
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/
#ifndef SIUL2_LLD_H
#define SIUL2_LLD_H

#include "status.h"
#include "derivative.h"
#ifdef SAFETY_ENABLE
#include "Adc_LLDriver.h"
#include "Port_Cfg.h"
#endif

#ifndef SAFETY_ENABLE
typedef struct SIUL2_tag SIUL2_TagType;/*PRQA S 0631*/
#endif

/* @brief SIUL2 base address */
#define SIUL2_BASEADDR              ((uint32_t)0xFFFC0000UL)

/* @brief SIUL2 base pointer */
#define SIUL2_PTR                   ((SIUL2_TagType *) SIUL2_BASEADDR)

/*
 * @brief Typedef
 */
#ifndef SAFETY_ENABLE
typedef uint16_t pin_index_t;
#endif
typedef void  (* SafcallBackFunction)(void * param);

/*
 * @brief Internal pull registor selection
 */
typedef enum {
    PAD_INTERNAL_PULLDOWN_ENABLED = 0U, /* internal weak pull-down resistor is enabled. */
    PAD_INTERNAL_PULLUP_ENABLED   = 1U, /* internal weak pull-UP resistor is enabled. */
    PAD_INTERNAL_PULL_DISABLED    = 2U  /* internal weak pull resistor is disabled. */
} pad_pull_config_t;

/*
 * @brief Configures the drive strength
 */
typedef enum {
    PAD_WEAK_DRIVE        = 0U, /* weak drive (800 ohm) */
    PAD_MEDIUM_DRIVE      = 1U, /* medium drive (200 ohm) */
    PAD_STRONG_DRIVE      = 2U, /* strong drive (200 ohm) */
    PAD_VERY_STRONG_DRIVE = 3U  /* very strong drive (50 ohm/5ns) */
} pad_drive_strength_t;

/*
 * @brief Configures the output drive control
 */
typedef enum {
    PAD_OUTPUT_BUFFER_DISABLED           = 0U, /* Output drive control disabled */
    PAD_OUTPUT_DRIVE_OPEN_DRAIN          = 1U, /* Output drive open drain */
    PAD_OUTPUT_DRIVE_PUSH_PULL           = 2U, /* Output drive push pull */
    PAD_OUTPUT_DRIVE_OPEN_SOURCE         = 3U, /* Output drive open source */
    PAD_OUTPUT_DRIVE_MSEC_CHANNEL_LVDS   = 4U, /* Output drive microsecond channel lvds */
    PAD_OUTPUT_LFAST_LVDS                = 5U, /* Output drive lfast lvds */
} pad_output_drvie_control_t;

/*
 * @brief Configures the analog pad control
 */
typedef enum {
    PAD_ANALOG_PAD_CONTROL_DISABLED = 0U, /* Diable (the switch is off)*/
    PAD_ANALOG_PAD_CONTROL_ENABLED  = 1U  /* Enable (another module can control the state of the switch) */
} pad_analog_pad_control_t;

/*
 * @brief Configures the safe mode control
 */
typedef enum {
    PAD_SAFE_MODE_DISABLED = 0U, /* Disable (the output buffer returns to its previous state when the chip leaves Safe mode) */
    PAD_SAFE_MODE_ENABLED  = 1U  /* Don't disable */
} pad_safe_mode_t;

/*
 * @brief Configure the input level selection-spiceified the
 *        logic family for the associated pin
 */
typedef enum {
    PAD_INPUT_LEVEL_SELECT_AUTOMOTIVE = 0U, /* input level select Automotive */
    PAD_INPUT_LEVEL_SELECT_TTL        = 1U, /* input level select TTL */
    PAD_INPUT_LEVEL_SELECT_LVDS       = 2U, /* input level select LVDS */
    PAD_INPUT_LEVEL_SELECT_CMOS       = 3U  /* input level select CMOS */
} pad_input_level_select_t;

/*
 * @brief Configures the input buffer
 */
typedef enum {
    PAD_INPUT_BUFFER_DISABLED = 0U, /* disable input buffer */
    PAD_INPUT_BUFFER_ENABLED  = 1U  /* enable input buffer */
} pad_input_buffer_t;

/*
 * @brief Configures the input hysteresis for the associated pin
 */
typedef enum {
    PAD_HYSTERESIS_DISABLED = 0U, /* input hysteresis disabled */
    PAD_HYSTERESIS_ENABLED  = 1U, /* input hysteresis enabled */
} pad_hysteresis_t;

/*
 * @brief Configures the output inverted selected
 */
typedef enum {
    PAD_INVERT_OUTPUT_DISABLED = 0U, /* output inverted diabled */
    PAD_INVERT_OUTPUT_ENABLED  = 1U  /* output inverted enabled */
} pad_inv_output_t;

/*
 * @brief Configures the pad data direction
 */
typedef enum {
    PAD_INPUT_DIRECTION  = 0U,
    PAD_OUTPUT_DIRECTION = 1U
} pad_data_direction_t; /* PRQA S 1535 */

/*
 * @brief pin state enumeration
 */
typedef enum {
    PIN_LOW     = 0U,
    PIN_HIGH    = 1U,
    PIN_UNKNOWN = 2U,
} pin_level_t;

/*
 * @brief Configures the pad mux selection
 */
typedef enum {
    PAD_SSS_0  = 0U,  /* default is configured as GPIO */
    PAD_SSS_1  = 1U,  /* see the reference manual for details */
    PAD_SSS_2  = 2U,  /* see the reference manual for details */
    PAD_SSS_3  = 3U,  /* see the reference manual for details */
    PAD_SSS_4  = 4U,  /* see the reference manual for details */
    PAD_SSS_5  = 5U,  /* see the reference manual for details */
    PAD_SSS_6  = 6U,  /* see the reference manual for details */
    PAD_SSS_7  = 7U,  /* see the reference manual for details */
    PAD_SSS_8  = 8U,  /* see the reference manual for details */
    PAD_SSS_9  = 9U,  /* see the reference manual for details */
    PAD_SSS_10 = 10U, /* see the reference manual for details */
    PAD_SSS_11 = 11U, /* see the reference manual for details */
    PAD_SSS_12 = 12U, /* see the reference manual for details */
    PAD_SSS_13 = 13U, /* see the reference manual for details */
    PAD_SSS_14 = 14U, /* see the reference manual for details */
    PAD_SSS_15 = 15U, /* see the reference manual for details */
    PAD_SSS_16 = 16U, /* see the reference manual for details */
} pad_sss_t;

/*!
 * @brief Configures the Pin input muxing selection
 */
typedef enum
{
    PAD_MUX_ALT0         = 0U,   /*!< Chip-specific.    */
    PAD_MUX_ALT1         = 1U,   /*!< Chip-specific.    */
    PAD_MUX_ALT2         = 2U,   /*!< Chip-specific.    */
    PAD_MUX_ALT3         = 3U,   /*!< Chip-specific.    */
} pad_mux_t; /* PRQA S 1535 */

typedef struct {
    boolean             pin_mux_enable;
    uint32_t            pin_mux_index;
    pad_inv_output_t    invert_output;
    uint32_t            mux_sss_config;
} pad_mux_config_t;

/*
 * @brief Configures the external interrupt or DMA select
 */
typedef enum {
    SIUL2_REQ_USING_INT = 0U,  /* external interrupt request  */
    SIUL2_REQ_USING_DMA = 1U   /* external DMA request */
} siul2_request_select_t;

/*
 * @brief
 */
typedef enum {
    SAF_SIUL2_EVENT_DISABLED     = 0U,  /* request event disabled */
    SAF_SIUL2_EVENT_RISING_EDGE  = 1U,  /* rising edge event is enabled */
    SAF_SIUL2_EVENT_FALLING_EDGE = 2U,  /* falling edge event is enabled */
    SAF_SIUL2_EVENT_EITHER_EDGE  = 3U,  /* request on either edge */
} saf_siul2_request_event_t;

/*
 * @brief Configures the siul2 external interrupt or DMA request
 */
typedef struct { /* PRQA S 3630 */
    uint8_t                eirq_index;
    saf_siul2_request_event_t  event_edge_sel;
    boolean                digital_filter_enable;
    uint8_t                filter_max_count;
    siul2_request_select_t request_sel;
    SafcallBackFunction       eirq_cb;
} siul2_request_config_t;

/*
 * @brief Defines the pad control configuration
 *
 * This structure is used to configure the given pad index
 */
typedef struct { /* PRQA S 3630 */
    pad_drive_strength_t        drive_strength_select;
    pad_output_drvie_control_t  output_derive_control;
    pad_safe_mode_t             safe_mode;
    pad_analog_pad_control_t    analog_pad_control;
    pad_input_level_select_t    input_level_select;
    pad_input_buffer_t          input_buffer_control;
    pad_hysteresis_t            hysteresis_control;
    pad_pull_config_t           pull_config;
    pad_inv_output_t            invert_output;
    pad_sss_t                   sss_config;
    pad_mux_config_t            mux_config;
} pad_control_config_t;

/*
 * @brief Configures the fec mode
 */
typedef enum {
    FEC_USE_RMII = 0U,
    FEC_USE_MII  = 1U
} fec_mode_t;

/*
 * @brief Configures the silu2 soc register
 */
typedef struct { /* PRQA S 3630 */
    fec_mode_t fec_mode;
    uint8_t    esr0_assert;
} siul2_soc_config_t;

/*
 * @brief SIUL2 macros define
 */
#define SIUL2_MSCR_MAX_CNT  512U

/*
 * @brief SIUL2 driver APIs
 */
extern status_t SIUL2_LLD_InitPad(pin_index_t pinIndex, const pad_control_config_t *config);
extern status_t SIUL2_LLD_WritePin(pin_index_t pinIndex, pin_level_t pinLevel);
extern pin_level_t SIUL2_LLD_ReadPin(pin_index_t pinIndex);
extern status_t SIUL2_LLD_TogglePin(pin_index_t pinIndex);
extern status_t SIUL2_LLD_SetPinPullSel(pin_index_t pinIndex, pad_pull_config_t pullConfig);
extern status_t SIUL2_LLD_SetPinOutputDriveControl(pin_index_t pinIndex, pad_output_drvie_control_t driveCtrl);
extern status_t SIUL2_LLD_SetPinInputBuffer(uint16_t pinIndex, boolean enable);
extern void SIUL2_LLD_ConfigSoc(const siul2_soc_config_t *socConfig);
extern void SIUL2_LLD_ConfigFilterClk(uint8_t preScaler);
extern void SIUL2_LLD_SetExtRequest(const siul2_request_config_t *reqConfig);
extern status_t SIUL2_LLD_ClearPinExtRequestFlag(uint8_t eirqIndex);
extern status_t SIUL2_LLD_GetPinExtRequestFlag(uint8_t eirqIndex);
extern uint32_t SIUL2_LLD_GetExtRequestFlag(void);
extern void SIUL2_LLD_ClearExtRequestFlag(void);
void SIUL2_LLD_SetUserAccessAllowed(void);
extern void SAF_SIUL2_EIRQ_0_IRQHandler(void);
extern void SAF_SIUL2_EIRQ_1_IRQHandler(void);

#endif /* LLD_INC_SIUL2_LLD_H_ */

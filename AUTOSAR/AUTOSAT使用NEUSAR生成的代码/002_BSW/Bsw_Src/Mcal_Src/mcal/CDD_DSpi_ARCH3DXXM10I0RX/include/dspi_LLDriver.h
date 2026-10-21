/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30XX
* DESCRIPTION : CCFC30XX dspi low level drivers h file
* HISTORY     : Initial version
* @file     dspi_lld.h
* @version  3.0.0
* @date     2023 - 05 - 30
* @brief    Initial version.
*
*****************************************************************************/
/*PRQA S 1535,1534 EOF*/
#ifndef DSPI_LLD_H_
#define DSPI_LLD_H_

#include "derivative.h"
#include "status.h"
#include "CDD_DSpi_Cfg.h"

/*==================================================================================================
SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DSPI_LLD_H_VENDOR_ID                   176
#define DSPI_LLD_H_AR_MAJOR_VER                4
#define DSPI_LLD_H_AR_MINOR_VER                4
#define DSPI_LLD_H_AR_PATCH_VER                0
#define DSPI_LLD_H_SW_MAJOR_VER                3
#define DSPI_LLD_H_SW_MINOR_VER                0
#define DSPI_LLD_H_SW_PATCH_VER                0
#define DSPI_LLD_H_MODULE_ID                   83
/*==================================================================================================
FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and SPI header file are of the same vendor */
#if (DSPI_LLD_H_VENDOR_ID != CDD_DSPI_VENDOR_ID_OUTPUT)
#error "NON-MATCHED DATA : DSPI_LLD_H_VENDOR_ID"
#endif

/* Check if current file and SPI header file are of the same Autosar version */
#if (DSPI_LLD_H_AR_MAJOR_VER != CDD_DSPI_AR_RELEASE_MAJOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : DSPI_LLD_H_AR_MAJOR_VER"
#endif
#if (DSPI_LLD_H_AR_MINOR_VER != CDD_DSPI_AR_RELEASE_MINOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : DSPI_LLD_H_AR_MINOR_VER"
#endif
#if (DSPI_LLD_H_AR_PATCH_VER != CDD_DSPI_AR_RELEASE_REVISION_VERSION_OUTPUT)
#error "NON-MATCHED DATA : DSPI_LLD_H_AR_PATCH_VER"
#endif

/* Check if current file and SPI header file are of the same Software version */
#if (DSPI_LLD_H_SW_MAJOR_VER != CDD_DSPI_SW_MAJOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : DSPI_LLD_H_AR_PATCH_VER"
#endif
#if (DSPI_LLD_H_SW_MINOR_VER != CDD_DSPI_SW_MINOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : DSPI_LLD_H_SW_MINOR_VER"
#endif
#if (DSPI_LLD_H_SW_PATCH_VER != CDD_DSPI_SW_PATCH_VERSION_OUTPUT)
#error "NON-MATCHED DATA : DSPI_LLD_H_SW_PATCH_VER"
#endif

typedef uint8 edma_channel_t;

/*
 * @brief Type of a structure representing an SPI driver.
 *
 */
typedef struct SPIDriver SPIDriver_t;

/**
 * @brief   SPI notification callback type.
 *
 * @param[in] spip      pointer to the @p SPIDriver_t object triggering the
 *                      callback
 */
typedef FUNC(void, DSPI_CODE) (*spicallback_t)(SPIDriver_t *spip);

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */
/**
 * @name SPI driver related setting
 * @{
 */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==   = */

/**
 * @brief   Enables synchronous APIs.
 * @note    Disabling this option saves both code and data space.
 */

#define SPI_USE_WAIT                TRUE


#define DSPI_FIFO_DEPTH                4U

 /** Number of instances of the DSPI module. */
 
#define DSPI_INSTANCE_COUNT                      (22u)

/**
 * @name    SPI DMA modes
 * @{
 */
#define SPI_DMA_NONE                   0u
#define SPI_DMA_RX_ONLY                1u
#define SPI_DMA_RX_AND_TX              2u

/*------------------------------------------------------------------------ - */

/**
 * @brief   SPI TX/RX status.
 */
#define SPI_TXRX_READY                 0U
#define SPI_TXRX_BUSY                  1U

#if (SPI_USE_WAIT == TRUE)
/**
 * @brief   Sets ready flag.
 * @details This function sets the ready flag when a TX/RX transfer starts.
 *
 * @param[in] spip      pointer to the @p SPI Driver object
 *
 * @notapi
 */
#define SPI_TXRX_IN_PROGRESS(spip)                                        \
  (spip)->ready = SPI_TXRX_BUSY;

/**
 * @brief   Clears ready flag.
 * @details This function clears the ready flag when a TX/RX transfer is
 *          completed.
 *
 * @param[in] spip      pointer to the @p SPI Driver object
 *
 * @notapi
 */
#define SPI_TXRX_DONE(spip)                                               \
  (spip)->ready = SPI_TXRX_READY;

#ifdef __ghs__
#pragma ghs ZO
#endif
/**
 * @brief   Waits for TX/RX completion.
 * @details This function waits till the current TX/RX transfer is completed.
 *
 * @param[in] spip      pointer to the @p SPI Driver object
 *
 * @notapi
 */
#define SPI_WAIT_FOR_TXRX_COMPLETION(spip)                                \
    while ((spip)->ready == SPI_TXRX_BUSY)                                \
    {}
#ifdef __ghs__
#pragma ghs O
#endif
#else /*!SPI_USE_WAIT */
#define SPI_TXRX_IN_PROGRESS(spip)
#define SPI_TXRX_DONE(spip)
#define SPI_WAIT_FOR_TXRX_COMPLETION(spip)
#endif

#define DSPI_EXTENDED_MODE_32bits 1U


/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */
/* Driver constants.                                                         */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */

#ifdef RESOURCE_SUPPORT_GTM_TO_MSC
#if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
#define GTM_MSC_SETi_MSK                   (0x1F1F1F1FUL)
#endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
#endif

/*!
 * @brief Defines the mode of the DSPI (master or slave)
 *
 * Select if the device is used as master or slave.
 *
 */
typedef enum
{
    SPI_SLAVE  = 0U,
    SPI_MASTER = 1U
} spi_functional_mode_t;
/*!
 * @brief Defines the mode of the DSPI (master or slave)
 *
 * Select if the device is used as master or slave.
 *
 */

typedef enum
{
    DSPI_SPI_MODE = 0U,
    DSPI_DSI_MODE = 1U,
    DSPI_CSI_MODE = 2u
} spi_Transmission_mode_t;
/*!
 * @brief Defines the mode of the DSPI (master or slave)
 *
 * Select if the device is used as master or slave.
 *
 */

typedef enum
{
    DSPI_TSBC_DISABLE = 0U,
    DSPI_TSBC_ENABLE = 1U
} spi_TSBC_mode_t;
/*!
 * @brief Defines the mode of the DSPI (master or slave)
 *
 * Select if the device is used as master or slave.
 *
 */

typedef enum
{
    DSPI_ITSBC_DISABLE = 0U,
    DSPI_ITSBC_ENABLE = 1U
} spi_ITSBC_mode_t;

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */
/* Driver data structures and types.                                         */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */

/**
 * @brief SPI mode type.
 */
typedef enum {
#ifdef RESOURCE_SUPPORT_DSPI_0
    CDD_DSPI0 = 0U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_1
    CDD_DSPI1 = 1U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_2
    CDD_DSPI2 = 2U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_3
    CDD_DSPI3 = 3U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_4
    CDD_DSPI4 = 4U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_5
    CDD_DSPI5 = 5U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_6
    CDD_DSPI6 = 6U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_7
    CDD_DSPI7 = 7U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_8
    CDD_DSPI8 = 8U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_9
    CDD_DSPI9 = 9U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_10
    CDD_DSPI10 = 10U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_11
    CDD_DSPI11 = 11U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_12
    CDD_DSPI12 = 12U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_13
    CDD_DSPI13 = 13U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_14
    CDD_DSPI14 = 14U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_15
    CDD_DSPI15 = 15U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_16
    CDD_DSPI16 = 16U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_17
    CDD_DSPI17 = 17U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_18
    CDD_DSPI18 = 18U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_19
    CDD_DSPI19 = 19U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_20
    CDD_DSPI20 = 20U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_21
    CDD_DSPI21 = 21U
#endif
} spi_controller_t;

typedef enum
{
    SPI_INACTIVE_LOW = 0U,
    SPI_INACTIVE_HIGH = 1U
} spi_pcs_polarity_t;

typedef struct
{
    CONST(spi_controller_t, DSPI_CONST)     WhichSpiController;
    CONST(uint32, DSPI_CONST)               Dspi_CoreId;
} mdspi_core_map_t;

/*!
 * @brief Defines the polarity for data signal of DSPI
 *
 * This enum is used to define data polarity
 *
 * Implements : dspi_polarity_t_Class
 */
typedef enum
{
    SPI_ACTIVE_LOW = 0U,
    SPI_ACTIVE_HIGH = 1U
} spi_clock_polarity_t;

/*!
 * @brief Defines shift and capture edges for SPI transfer
 *
 * This enum is used to define the edges used for shifting and captureing
 *
 * Implements : dspi_clock_phase_t_Class
 */
typedef enum
{
    SPI_CLOCK_PHASE_1ST_EDGE = 0U, /*! < Data captured on SCK 1st edge, changed on 2nd. */
    SPI_CLOCK_PHASE_2ND_EDGE = 1U  /*! < Data changed on SCK 1st edge, captured on 2nd. */
} spi_clock_phase_t;

/*!
 * @brief Defines how are handle the RX/TX buffers
 *
 * This typedef defines the available methods to handle RX and TX buffers
 *
 * Implements : dspi_transfer_type_t_Class
 */
typedef enum
{
    SPI_USING_POLLING = 0U,
    SPI_USING_INTERRUPTS = 1U
} spi_transfer_type_t;

/*!
 * @brief Defines how are handle the RX/TX data
 *
 * This typedef defines the available methods to handle RX and TX data
 *
 * Implements : spi_dma_type_t_Class
 */
typedef enum
{
    DSPI_DMA_NONE = 0U,
    DSPI_DMA_RX_ONLY = 1U,
    DSPI_DMA_RX_AND_TX = 2
} spi_dma_type_t;

#ifdef RESOURCE_SUPPORT_GTM_TO_MSC
#if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
typedef struct
{
    VAR(uint32, DSPI_VAR) setIndex;
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) selValue;
} gtm_msc_set_sel_t;

typedef struct
{
    VAR(uint32, DSPI_VAR) mscIndex;
    VAR(uint32, DSPI_VAR) InputLowControl;
    VAR(uint32, DSPI_VAR) InputHighControl;
    VAR(uint32, DSPI_VAR) InputLowExtendedControl;
} gtm_msc_t;
#endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
#endif

/*!
 * @brief Defines the configuration for SPI master mode.
 *
 * This structure is used to configure the DSPI module in SPI master mode. It stores information about
 * transfer type, callback, bus configuration.
 *
 * Implements : dspi_master_config_t_Class
 */
typedef struct /* PRQA S 3630 */
{
    VAR(spi_controller_t, DSPI_VAR) WhichSpiController;
    VAR(uint32, DSPI_VAR) DSpi_Clock;
    VAR(uint32, DSPI_VAR) bitsPerSec;
    VAR(spi_pcs_polarity_t, DSPI_VAR) pcsPolarity;
    VAR(uint16, DSPI_VAR) bitcount;
    VAR(spi_clock_phase_t, DSPI_VAR) clkPhase;
    VAR(spi_clock_polarity_t, DSPI_VAR) clkPolarity;
    VAR(uint8, DSPI_VAR) isClkContinuous;
    VAR(uint8, DSPI_VAR) lsbFirst;
    VAR(spi_transfer_type_t, DSPI_VAR) transferType;
    VAR(spi_dma_type_t, DSPI_VAR) dmaType;
    VAR(spicallback_t, DSPI_VAR) callback;
    VAR(uint8, DSPI_VAR) continuousPCS;
    VAR(uint8, DSPI_VAR) whichPCS;
    /*********************DSI CSI CONFIG****************************/
    VAR(uint8, DSPI_VAR) Dconf;
    VAR(uint8, DSPI_VAR) TSBC;
    VAR(uint8, DSPI_VAR) ITSBC;
    VAR(uint8, DSPI_VAR) DsiDataSource;
    VAR(uint8, DSPI_VAR) isCID;
    VAR(uint8, DSPI_VAR) istrre;
    VAR(uint8, DSPI_VAR) tpol;
    VAR(uint8, DSPI_VAR) Dcont;
    VAR(uint8, DSPI_VAR) DSICTAx;
    VAR(uint8, DSPI_VAR) whichDSIPCS;
    VAR(uint8, DSPI_VAR) TSBCNT;
    VAR(uint8, DSPI_VAR) SDR1En;
    VAR(uint8, DSPI_VAR) DataSelect0En;
    VAR(uint8, DSPI_VAR) DataSelect1En;
    VAR(uint8, DSPI_VAR) whichTSBPCS;
    VAR(spi_functional_mode_t, DSPI_VAR) spi_mode;
#ifdef RESOURCE_SUPPORT_GTM_TO_MSC
#if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
    P2CONST(gtm_msc_t, AUTOMATIC, DSPI_APPL_CONST) MSCConfig;
#endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
#endif
} spi_config_t;

/**
 * @brief   Structure representing an SPI driver.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
struct SPIDriver {

    /**
   * @brief   Current configuration data.
   */
  const spi_config_t    *Cdsiconfig;

  /**
   * @brief   Waiting flag.
   */
  VAR(uint8, DSPI_VAR)           ready;
  /**
   * @brief   Pointer to the DSPI registers block.
   */
  volatile struct DSPI_tag    *dspi;

  /**
   * @brief   EDMA channel used for receive.
   */
  VAR(edma_channel_t, DSPI_VAR)  rx_channel;
  /**
   * @brief   Memory pointer for RX operations.
   */
  union {
    void                *rx_ptr;
    uint8               *rx_ptr8;
    uint16              *rx_ptr16;
    uint32              *rx_ptr32;
  }rx;

  /*
   * @brief   Remaining frames to be received.
   */
  VAR(uint32, DSPI_VAR)                    rx_cnt;
  /**
   * @brief   EDMA channel used for data memory to memory copy.
   */
  VAR(edma_channel_t, DSPI_VAR)            tx1_channel;
  /**
   * @brief   EDMA channel used for transmit.
   */
  VAR(edma_channel_t, DSPI_VAR)            tx2_channel;
  /**
   * @brief   Command for the ongoing TX operation.
   */
  VAR(uint32, DSPI_VAR)                    tx_cmd;
  /**
   * @brief   Last frame of a transmission sequence.
   */
  VAR(uint32, DSPI_VAR)                    tx_last;
  /**
   * @brief   Memory pointer for TX operations.
   */
  union {
    void            *tx_ptr;
    uint8           *tx_ptr8;
    uint16          *tx_ptr16;
    uint32          *tx_ptr32;
  }tx;

  /*
   * @brief   Remaining frames to be transmitted.
   */
  VAR(uint32, DSPI_VAR)                    tx_cnt;
};

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */
/* External declarations.                                                    */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */
#ifdef RESOURCE_SUPPORT_DSPI_0
extern VAR(SPIDriver_t, DSPI_VAR) SPID1;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_1
extern VAR(SPIDriver_t, DSPI_VAR) SPID2;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_2
extern VAR(SPIDriver_t, DSPI_VAR) SPID3;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_3
extern VAR(SPIDriver_t, DSPI_VAR) SPID4;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_4
extern VAR(SPIDriver_t, DSPI_VAR) SPID5;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_5
extern VAR(SPIDriver_t, DSPI_VAR) SPID6;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_6
extern VAR(SPIDriver_t, DSPI_VAR) SPID7;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_7
extern VAR(SPIDriver_t, DSPI_VAR) SPID8;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_8
extern VAR(SPIDriver_t, DSPI_VAR) SPID9;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_9
extern VAR(SPIDriver_t, DSPI_VAR) SPID10;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_10
extern VAR(SPIDriver_t, DSPI_VAR) SPID11;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_11
extern VAR(SPIDriver_t, DSPI_VAR) SPID12;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_12
extern VAR(SPIDriver_t, DSPI_VAR) SPID13;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_13
extern VAR(SPIDriver_t, DSPI_VAR) SPID14;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_14
extern VAR(SPIDriver_t, DSPI_VAR) SPID15;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_15
extern VAR(SPIDriver_t, DSPI_VAR) SPID16;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_16
extern VAR(SPIDriver_t, DSPI_VAR) SPID17;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_17
extern VAR(SPIDriver_t, DSPI_VAR) SPID18;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_18
extern VAR(SPIDriver_t, DSPI_VAR) SPID19;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_19
extern VAR(SPIDriver_t, DSPI_VAR) SPID20;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_20
extern VAR(SPIDriver_t, DSPI_VAR) SPID21;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_21
extern VAR(SPIDriver_t, DSPI_VAR) SPID22;
#endif

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(status_t, DSPI_CODE) SPI_LLD_Deinit
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(status_t, DSPI_CODE) SPI_LLD_Init
(
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) spip,
    P2CONST(spi_config_t, AUTOMATIC, DSPI_APPL_CODE) config,
    VAR(spi_functional_mode_t, DSPI_VAR) spi_mode
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) DSPI_LLD_CSI_TSB_Tx
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint32, DSPI_VAR) tsbcmd_n,
    VAR(uint32, DSPI_VAR) tsbdata_n,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) tsbcmd,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) tsbdata
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) Cdsi_Prefill_ITBC_Tx
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint32, DSPI_VAR) spi_n,
    VAR(uint32, DSPI_VAR) dsi_n,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) txbuf,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) txbuf1,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf1
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) DSPI_LLD_CSI_Send
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint32, DSPI_VAR) spi_n,
    VAR(uint32, DSPI_VAR) dsi_n,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) txbuf,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) txbuf1,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf1
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) DSPI_LLD_DSI_TSB_Send
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint32, DSPI_VAR) n,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) txbuf,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) DSPI_LLD_DSI_Receive
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint32, DSPI_VAR) n,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) SPI_LLD_SetDsiTRGPRD
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint32, DSPI_VAR) trig_period
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) DSPI_LLD_DSI_Send
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint32, DSPI_VAR) n,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) txbuf,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) spi_serve_dma_error_irq
(
    P2CONST(uint32, AUTOMATIC, DSPI_APPL_CODE) p
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(status_t, DSPI_CODE) DSPI_TrannsferFail
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) spi_serve_dspi_tcf
(
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) spip
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) spi_serve_dspi_eoqf
(
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) spip
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Spi_Dspi_Start
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#ifdef RESOURCE_SUPPORT_GTM_TO_MSC
#if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) MSC_SETi_SEL_Set(VAR(uint32, DSPI_VAR) set_index, P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) sel_value);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
#endif

#endif /* LLD_USE_SPI */

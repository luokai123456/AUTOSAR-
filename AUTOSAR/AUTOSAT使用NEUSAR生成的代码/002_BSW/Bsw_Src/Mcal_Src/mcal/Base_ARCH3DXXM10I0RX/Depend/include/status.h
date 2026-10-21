/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx status define
* HISTORY     : Initial version
* @file     status.h
* @version  3.0.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/

#ifndef STATUS_H_
#define STATUS_H_

/*******************************************************************************
 * Definitions
 ******************************************************************************/

typedef enum
{
    /* Generic error codes */
    STATUS_SUCCESS                         = 0x000U,    /*!< Generic operation success status */
    STATUS_ERROR                           = 0x001U,    /*!< Generic operation failure status */
    STATUS_BUSY                            = 0x002U,    /*!< Generic operation busy status */
    STATUS_TIMEOUT                         = 0x003U,    /*!< Generic operation timeout status */
    STATUS_UNSUPPORTED                     = 0x004U,    /*!< Generic operation unsupported status */
	STATUS_INITIALIZED                     = 0x005U,
	STATUS_UNINITIALIZED                   = 0x006U,
    /* MCU specific error codes */
    STATUS_MCU_INVALID_CORE_ID             = 0x100U,    /*!< Core ID is invalid */
    STATUS_MCU_INVALID_CHIP_MODE           = 0x101U,    /*!< Run mode is invalid */
    STATUS_MCU_INVALID_INTC_MODE           = 0x102U,    /*!< Intrrupt mode is invalid */
    STATUS_MCU_INVALID_INTC_NUM            = 0x103U,    /*!< Intrrupt number is invalid */
    STATUS_MCU_INVALID_PRIOR_NUM           = 0x104U,    /*!< Intrrupt priority is invalid */
    STATUS_MCU_UNSUPPORT_DCACHE            = 0x105U,    /*!< unsupport data cache  */
    STATUS_MCU_UNSUPPORT_ICACHE            = 0x106U,    /*!< unsupport instruction cache */
    STATUS_MCU_GATED_OFF                   = 0x107U,    /*!< Module is gated off */
    /* I2C specific error codes */
    STATUS_I2C_RECEIVED_NACK               = 0x200U,  /*!< NACK signal received  */
    STATUS_I2C_TX_UNDERRUN                 = 0x201U,  /*!< TX underrun error */
    STATUS_I2C_RX_OVERRUN                  = 0x202U,  /*!< RX overrun error */
    STATUS_I2C_ARBITRATION_LOST            = 0x203U,  /*!< Arbitration lost */
    STATUS_I2C_ABORTED                     = 0x204U,  /*!< A transfer was aborted */
    STATUS_I2C_BUS_BUSY                    = 0x205U,  /*!< I2C bus is busy, cannot start transfer */
    /* CAN specific error codes */
    STATUS_CAN_BUFF_OUT_OF_RANGE           = 0x300U,  /*!< The specified MB index is out of the configurable range */
    STATUS_CAN_NO_TRANSFER_IN_PROGRESS     = 0x301U,  /*!< There is no transmission or reception in progress */
    /* Security specific error codes */
    STATUS_HSM_GENERAL_ERRPR               = 0x401U,

    STATUS_HSM_SEQUENCE_ERROR              = 0x402U,  /*!< The sequence of commands or subcommands is out of
                                                            sequence */
    STATUS_HSM_KEY_NOT_AVAILABLE           = 0x403U,  /*!< A key is locked due to failed boot measurement or
                                                            an active debugger */
    STATUS_HSM_KEY_INVALID                 = 0x404U,  /*!< A function is called to perform an operation with
                                                            a key that is not allowed for the given operation */
    STATUS_HSM_KEY_EMPTY                   = 0x405U,  /*!< Attempt to use a key that has not been initialized yet */
    STATUS_HSM_NO_SECURE_BOOT              = 0x406U,  /*!< The conditions for a secure boot process are not met */
    STATUS_HSM_KEY_WRITE_PROTECTED         = 0x407U,  /*!< Request for updating a write protected key slot,
                                                            or activating debugger with write protected key(s) */
    STATUS_HSM_KEY_UPDATE_ERROR            = 0x408U,  /*!< Key update did not succeed due to errors in
                                                            verification of the messages */
    STATUS_HSM_RNG_SEED                    = 0x409U,  /*!< Returned by CMD_RND and CMD_DEBUG if the seed has not
                                                            been initialized before */
    STATUS_HSM_DEV_AUTH_FAILED             = 0x40AU,  /*!< Device authentication failed */
    STATUS_HSM_INVALID_COMMAND             = 0x40BU,  /*!< Command value out of range */
    STATUS_HSM_INVALID_PARAM               = 0x40CU,  /*!< Invalid command paramer */
    STATUS_HSM_HSM_FLASH_BLOCK_ERROR       = 0x40DU,  /*!< Error reading, programming or erasing one of the HSM flash blocks */
    STATUS_HSM_NOT_ENOUGH_SPACE            = 0x40EU,
    STATUS_HSM_DECRYPT_FAIL                = 0x40FU,
    STATUS_HSM_NOT_ALLOWED                 = 0x410U,
    STATUS_HSM_NOT_SUPPORTED               = 0x411U,
    STATUS_HSM_NULL_POINTER                = 0x412U,
    STATUS_HSM_VERIFY_FAILED               = 0x413U,
    STATUS_HSM_OPERATION_TIMEOUT           = 0x414U,
    STATUS_HSM_DEV_NOT_AUTHED              = 0x415U,
    STATUS_HSM_SMALL_BUFFER                = 0x416U,
    STATUS_HSM_LENGTH_ERROR				   = 0x417U,
    STATUS_HSM_FLASH_LOCK_BUSY			   = 0x418U,

    STATUS_SEC_SEQUENCE_ERROR              = 0x402U,  /*!< The sequence of commands or subcommands is out of
                                                            sequence */
    STATUS_SEC_KEY_NOT_AVAILABLE           = 0x403U,  /*!< A key is locked due to failed boot measurement or
                                                            an active debugger */
    STATUS_SEC_KEY_INVALID                 = 0x404U,  /*!< A function is called to perform an operation with
                                                            a key that is not allowed for the given operation */
    STATUS_SEC_KEY_EMPTY                   = 0x405U,  /*!< Attempt to use a key that has not been initialized yet */
    STATUS_SEC_NO_SECURE_BOOT              = 0x406U,  /*!< The conditions for a secure boot process are not met */
    STATUS_SEC_KEY_WRITE_PROTECTED         = 0x407U,  /*!< Request for updating a write protected key slot,
                                                            or activating debugger with write protected key(s) */
    STATUS_SEC_KEY_UPDATE_ERROR            = 0x408U,  /*!< Key update did not succeed due to errors in
                                                            verification of the messages */
    STATUS_SEC_RNG_SEED                    = 0x409U,  /*!< Returned by CMD_RND and CMD_DEBUG if the seed has not
                                                            been initialized before */
    STATUS_SEC_NO_DEBUGGING                = 0x40AU,  /*!< DEBUG command authentication failed */
    STATUS_SEC_MEMORY_FAILURE              = 0x40CU,  /*!< General memory technology failure
                                                            (multibit ECC error, common fault detected) */
    STATUS_SEC_HSM_INTERNAL_MEMORY_ERROR   = 0x410U,  /*!< An internal memory error encountered while
                                                           executing the command */
    STATUS_SEC_INVALID_COMMAND             = 0x411U,  /*!< Command value out of range */
    STATUS_SEC_TRNG_ERROR                  = 0x412U,  /*!< One or more statistical tests run on the TRNG output failed */
    STATUS_SEC_HSM_FLASH_BLOCK_ERROR       = 0x413U,  /*!< Error reading, programming or erasing one of the HSM flash blocks */
    STATUS_SEC_INTERNAL_CMD_ERROR          = 0x414U,  /*!< An internal command processor error while executing a command */
    STATUS_SEC_MAC_LENGTH_ERROR            = 0x415U,  /*!< MAC/Message length out of range */
    STATUS_SEC_INVALID_ARG                 = 0x421U,  /*!< Invalid command argument */
    STATUS_SEC_TRNG_CLOCK_ERROR            = 0x423U,  /*!< TRNG not provided with a stable clock */
    /* SPI specific error codes */
    STATUS_SPI_TX_UNDERRUN                 = 0x500U,  /*!< TX underrun error */
    STATUS_SPI_RX_OVERRUN                  = 0x501U,  /*!< RX overrun error */
    STATUS_SPI_ABORTED                     = 0x502U,  /*!< A transfer was aborted */
    /* UART specific error codes */
    STATUS_UART_TX_UNDERRUN                = 0x600U,  /*!< TX underrun error */
    STATUS_UART_RX_OVERRUN                 = 0x601U,  /*!< RX overrun error */
    STATUS_UART_ABORTED                    = 0x602U,  /*!< A transfer was aborted */
	STATUS_UART_FRAMING_ERROR              = 0x603U,  /*!< Framing error */
	STATUS_UART_PARITY_ERROR               = 0x604U,  /*!< Parity error */
	STATUS_UART_NOISE_ERROR                = 0x605U,  /*!< Noise error */
    /* I2S specific error codes */
    STATUS_I2S_TX_UNDERRUN                 = 0x700U,  /*!< TX underrun error */
    STATUS_I2S_RX_OVERRUN                  = 0x701U,  /*!< RX overrun error */
    STATUS_I2S_ABORTED                     = 0x702U,  /*!< A transfer was aborted */
    /* SBC specific error codes */
    SBC_NVN_ERROR                          = 0x801U, /*!< Unsuccessful attempt writing to non volatile memory
                                                          (0x73 and 0x74). Set device to factory settings. */
    SBC_COMM_ERROR                         = 0x802U, /*!< Data transfer was aborted */
    SBC_CMD_ERROR                          = 0x804U, /*!< Wrong command. */
    SBC_ERR_NA                             = 0x808U, /*!< Feature/device not available */
    SBC_MTPNV_LOCKED                       = 0x810U, /*!< Unable to write MTPNV cells, NVMPS = 0 */

    /* FLASH specific error codes */
    STATUS_FLASH_ERROR_ENABLE              = 0x901U, /*!< It's impossible to enable an operation */
    STATUS_FLASH_ERROR_NO_BLOCK            = 0x902U, /*!< No blocks have been enabled for Array Integrity check */
	STATUS_FLASH_ERROR_LOCKED              = 0x903U, /*!< Flash block is locked, can not erase or program */
    STATUS_FLASH_INPROGRESS                = 0x904U, /*!< InProgress status */

    /* SAI specific error codes */
    STATUS_SAI_ABORTED                     = 0xA00U, /*!< SAI aborted status */

    /* ENET specific error codes */
    STATUS_ENET_RX_QUEUE_EMPTY             = 0xA01U, /*!< There is no available frame in the receive queue */
    STATUS_ENET_TX_QUEUE_FULL              = 0xA02U, /*!< There is no available space for the frame in the transmit queue */
    STATUS_ENET_BUFF_NOT_FOUND             = 0xA03U, /*!< The specified buffer was not found in the queue */

    /* FCCU specific error codes */
    STATUS_FCCU_ERROR_CONFIG_TIMEOUT       = 0xB01U, /*!< FCCU triggers TimeOut when try to enter in Config State */
    STATUS_FCCU_ERROR_INIT_FCCU            = 0xB02U, /*!< FCCU Initializing FCCU Module */
    STATUS_FCCU_ERROR_SET_CONFIG           = 0xB03U, /*!< FCCU Fail to Enter in Config Mode  */
    STATUS_FCCU_ERROR_SET_NORMAL           = 0xB04U, /*!< FCCU Fail to Enter in Normal Mode  */
    STATUS_FCCU_ERROR_APPLY_NCF_CONFIG     = 0xB05U, /*!< FCCU Fail to set NoCritical Faults  */
    STATUS_FCCU_ERROR_UPDATE_FREEZE        = 0xB06U, /*!< FCCU Fail to update Freez Status registers */
    STATUS_FCCU_ERROR_CLEAR_FREEZE         = 0xB07U, /*!< FCCU Fail to Clear Freez Status registers */
    STATUS_FCCU_ERROR_SET_EOUT             = 0xB08U, /*!< FCCU Fail to Set Eout Configuration */
    STATUS_FCCU_ERROR_FAULT_DETECTED       = 0xB09U, /*!< FCCU Faults Detected */
    STATUS_FCCU_ERROR_OTHER                = 0xB0AU, /*!< FCCU other Error */

    /* EMIOS specific error codes */
    STATUS_EMIOS_WRONG_MODE                = 0xC00U,   /*!< EMIOS unsuccessful attempt selecting wrong mode. */
    STATUS_EMIOS_CNT_BUS_OVERFLOW          = 0xC01U,   /*!< EMIOS counter bus overflow. */
    STATUS_EMIOS_WRONG_CNT_BUS             = 0xC02U,   /*!< EMIOS unsuccessful attempt selecting wrong counter bus. */
    STATUS_EMIOS_ENABLE_GLOBAL_FRZ         = 0xC03U,   /*!< EMIOS must set global allow enter debug mode first. */
    STATUS_EMIOS_WRONG_INSTANCE            = 0xC04U,   /*!< EMIOS unsuccessful attempt selecting wrong instance. */
    STATUS_EMIOS_WRONG_CHANNEL             = 0xC05U,   /*!< EMIOS unsuccessful attempt selecting wrong channel. */
    STATUS_EMIOS_WRONG_PARAMETER           = 0xC06U,   /*!< EMIOS unsuccessful attempt selecting wrong parameter. */

    /* EEE specific error codes */
    STATUS_EEE_ERROR_NO_ENOUGH_SPACE       = 0xD00U, /*!< The data is too big to fit in any of the block */
    STATUS_EEE_ERROR_NO_ENOUGH_BLOCK       = 0xD01U, /*!< The block numbers is not enough for round robin */
    STATUS_EEE_ERROR_DATA_NOT_FOUND        = 0xD02U, /*!< The required data is not found in the EEPROM emulation */
    STATUS_EEE_ERROR_NOT_IN_CACHE          = 0xD03U, /*!< The required data is not in the cache table */
    STATUS_EEE_ERROR_PROGRAM_INDICATOR     = 0xD04U, /*!< Failed to make block indicator to non-blank for several times */
    STATUS_EEE_HVOP_INPROGRESS             = 0xD05U, /*!< The high voltage operation is in progress */

    /* uSDHC specific error codes */
    STATUS_USDHC_OUT_OF_RANGE              = 0xE00U,    /*!< The size of data to be sent is larger than maximum size of ADMA table */
    STATUS_USDHC_PREPARE_ADMA_FAILED       = 0xE01U,    /*!< Failed to prepare the ADMA table */

    /* TDM specific error codes */
    STATUS_TDM_DIARY_FULL                  = 0xF01U, /*!< No empty flash left in diary region */

    /* PHY specific error codes */
    STATUS_PHY_ACCESS_FAILED               = 0x1001U, /*!< Could not access PHY registers */
    STATUS_PHY_INCOMPATIBLE_DEVICE         = 0x1002U, /*!< The selected PHY driver is not compatible with the device */

    /* ESCI specific error codes */
    STATUS_ESCI_FRAME_FORMAT_ERROR         = 0x1102U,  /*!< Frame format error */

    /* ZIPWIRE specific error codes */
	STATUS_ZIPWIRE_TIMEOUT_ERR             = 0x1300U,    /*!< Channel timeout */
	STATUS_ZIPWIRE_TRANSACTION_ID_ERR      = 0x1301U,    /*!< Transaction ID error */
	STATUS_ZIPWIRE_ACK_ERR                 = 0x1302U,    /*!< Error on received ACK */

	/* CMU specific error codes */
	STATUS_CMU_FREQ_HIGHER                 = 0x1404U,  /*!< Frequency higher than high reference event status */
	STATUS_CMU_FREQ_LOWER                  = 0x1402U,  /*!< Frequency lower than high reference event status */
	STATUS_CMU_OSC_FREQ_LOWER              = 0x1403U,  /*!< Oscillator frequency less than fCLKMT0_RMN / 2CMU_CSR[RCDIV] */
	STATUS_CMU_OSC_FREQ_LOWER_REF_CLOCK    = 0x1401U,  /*!< Frequency less than reference clock event status. */

    /* CMU specific error codes */
    STATUS_ETPU_WRONG_PARAMETER           = 0x1500U,   /*!< ETPU unsuccessful attempt selecting wrong parameter. */
    STATUS_ETPU_WRONG_CODE_SIZE           = 0x1501U,   /*!< ETPU unsuccessful attempt selecting code size. */
    STATUS_ETPU_WRONG_CNT_BUS             = 0x1502U,   /*!< ETPU unsuccessful attempt selecting wrong counter bus. */
    STATUS_ETPU_ENABLE_GLOBAL_FRZ         = 0x1503U,   /*!< ETPU must set global allow enter debug mode first. */
    STATUS_ETPU_WRONG_INSTANCE            = 0x1504U,   /*!< ETPU unsuccessful attempt selecting wrong instance. */
    STATUS_ETPU_WRONG_CHANNEL             = 0x1505U,   /*!< ETPU unsuccessful attempt selecting wrong channel. */

    /* FEC specific error codes */
    STATUS_FEC_INVALID_FEC_ID              = 0x1601U, /*!< FEC id is invalid */
    STATUS_FEC_INVALID_MILL_MODE           = 0x1602U, /*!< MILL mode is invalid */
    STATUS_FEC_INVALID_BUF_SIZE            = 0x1603U, /*!< buffer size is invalid */
    STATUS_FEC_INVALID_TX_DESC             = 0x1604U, /*!< TX buffer is invalid */
    STATUS_FEC_INVALID_RX_DESC             = 0x1605U, /*!< RX buffer is invalid */
    STATUS_FEC_INVALID_DESC_CNT            = 0x1606U, /*!< buffer number is invalid */
    STATUS_FEC_TX_DESC_BUF_NULL            = 0x1607U, /*!< TX buffer is null */
    STATUS_FEC_RX_DESC_BUF_NULL            = 0x1608U, /*!< RX buffer is null */
    STATUS_FEC_MALLOC_TX_BUFFER            = 0x1609U, /*!< malloc TX buffer fail */
    STATUS_FEC_MII_READ_REGISTER           = 0x160aU, /*!< read   PHY register fail */
    STATUS_FEC_MII_WRITE_REGISTER          = 0x160bU, /*!< write   PHY register fail */
    STATUS_FEC_TRANSCEIVER_INIT            = 0x160cU, /*!< init FEC PHY fail */
    STATUS_FEC_NO_RECEIVED_MSG             = 0x160dU, /*!< has none pkt received */

    /* DWMAC specific error codes */
    STATUS_DWMAC_INVALID_DWMAC_ID          = 0x1701U, /*!< DWMAC id is invalid */
    STATUS_DWMAC_INVALID_MILL_MODE         = 0x1702U, /*!< MILL mode is invalid */
    STATUS_DWMAC_INVALID_BUF_SIZE          = 0x1703U, /*!< buffer size is invalid */
    STATUS_DWMAC_INVALID_TX_DESC           = 0x1704U, /*!< TX buffer is invalid */
    STATUS_DWMAC_INVALID_RX_DESC           = 0x1705U, /*!< RX buffer is invalid */
    STATUS_DWMAC_INVALID_DESC_CNT          = 0x1706U, /*!< buffer number is invalid */
    STATUS_DWMAC_TX_DESC_BUF_NULL          = 0x1707U, /*!< TX buffer is null */
    STATUS_DWMAC_RX_DESC_BUF_NULL          = 0x1708U, /*!< RX buffer is null */
    STATUS_DWMAC_MALLOC_TX_BUFFER          = 0x1709U, /*!< malloc TX buffer fail */
    STATUS_DWMAC_MII_READ_REGISTER         = 0x170aU, /*!< read   PHY register fail */
    STATUS_DWMAC_MII_WRITE_REGISTER        = 0x170bU, /*!< write   PHY register fail */
    STATUS_DWMAC_TRANSCEIVER_INIT          = 0x170cU, /*!< init DWMAC PHY fail */
    STATUS_DWMAC_NO_RECEIVED_MSG           = 0x170dU, /*!< has none pkt received */
    STATUS_DWMAC_MSG_SIZE_INVALID          = 0x170eU, /*!< has invalid pkt received */
    STATUS_DWMAC_INVALID_TX_BUFFER         = 0x1710U, /*!< TX   buffer not enough*/
    STATUS_DWMAC_INVALID_RX_BUFFER         = 0x1711U, /*!< RX   buffer not enough*/

    /* PSI5 specific error codes */
    STATUS_PSI5_INVALID_PSI5_ID            = 0x1801U, /*!< PSI5 id is invalid */
    STATUS_PSI5_INVALID_CHANNEL_ID         = 0x1802U, /*!< PSI5 channel id is invalid */
    STATUS_PSI5_INVALID_SLOT_ID            = 0x1803U, /*!< PSI5 slot id is invalid */
    STATUS_PSI5_NO_RX_FRAME                = 0x1804U, /*!< has none pkt received */
    STATUS_PSI5_MALLOC_TX_BUFFER           = 0x1805U, /*!< malloc TX buffer fail */

    /* PSI5S specific error codes */
    STATUS_PSI5S_INVALID_PSI5S_ID          = 0x1901U, /*!< PSI5S id is invalid */
    STATUS_PSI5S_INVALID_CHANNEL_ID        = 0x1902U, /*!< PSI5S channel id is invalid */
    STATUS_PSI5S_INVALID_SLOT_ID           = 0x1903U, /*!< PSI5S slot id is invalid */
    STATUS_PSI5S_NO_RX_FRAME               = 0x1904U, /*!< has none pkt received */
    STATUS_PSI5S_MALLOC_TX_BUFFER          = 0x1905U, /*!< malloc TX buffer fail */
    STATUS_PSI5S_CH_ADDR_ERROR             = 0x1906U, /*!< channel address set fail */
    STATUS_PSI5S_PAYLOAD_LENGTH_ERROR      = 0x1907U, /*!< payload length set fail */

    /* CAN_SAMPLER specific error codes */
    STATUS_CAN_SAMPLER_INVALID_ID          = 0x1A01U, /*!< CAN_SAMPLER invalid id */
    STATUS_CAN_SAMPLER_INVALID_MODE        = 0x1A02U, /*!< CAN_SAMPLER invalid mode */
    STATUS_CAN_SAMPLER_INVALID_PORT        = 0x1A03U, /*!< CAN_SAMPLER invalid port */
    STATUS_CAN_SAMPLER_INVALID_SPEED       = 0x1A04U, /*!< CAN_SAMPLER invalid speed */
    STATUS_CAN_SAMPLER_STATUS_BUSY         = 0x1A05U, /*!< CAN_SAMPLER is busy */
    STATUS_CAN_SAMPLER_WAIT_TIMEOUT        = 0x1A06U, /*!< CAN_SAMPLER wait timeout */
    STATUS_CAN_SAMPLER_PORT_UNSUPPORT      = 0x1A07U, /*!< CAN_SAMPLER port unsupport */
    STATUS_CAN_SAMPLER_DATA_OVERSIZE       = 0x1A08U, /*!< CAN_SAMPLER data oversize */
    STATUS_CAN_SAMPLER_INVALID_SOURCE      = 0x1A09U, /*!< CAN_SAMPLER invalid source */

    /* GMAC specific error codes */
    STATUS_GMAC_INVALID_GMAC_ID           = 0x1B01U, /*!< GMAC id is invalid */
    STATUS_GMAC_INVALID_MILL_MODE         = 0x1B02U, /*!< GMAC MILL mode is invalid */
    STATUS_GMAC_INVALID_BUF_SIZE          = 0x1B03U, /*!< GMAC buffer size is invalid */
    STATUS_GMAC_INVALID_TX_DESC           = 0x1B04U, /*!< GMAC TX buffer is invalid */
    STATUS_GMAC_INVALID_RX_DESC           = 0x1B05U, /*!< GMAC RX buffer is invalid */
    STATUS_GMAC_INVALID_DESC_CNT          = 0x1B06U, /*!< GMAC buffer number is invalid */
    STATUS_GMAC_TX_DESC_BUF_NULL          = 0x1B07U, /*!< GMAC TX buffer is null */
    STATUS_GMAC_RX_DESC_BUF_NULL          = 0x1B08U, /*!< GMAC RX buffer is null */
    STATUS_GMAC_MALLOC_TX_BUFFER          = 0x1B09U, /*!< GMAC malloc TX buffer fail */
    STATUS_GMAC_MII_READ_REGISTER         = 0x1B0aU, /*!< GMAC read   PHY register fail */
    STATUS_GMAC_MII_WRITE_REGISTER        = 0x1B0bU, /*!< GMAC write   PHY register fail */
    STATUS_GMAC_TRANSCEIVER_INIT          = 0x1B0cU, /*!< GMAC init PHY fail */
    STATUS_GMAC_NO_RECEIVED_MSG           = 0x1B0dU, /*!< GMAC has none pkt received */
    STATUS_GMAC_MSG_SIZE_INVALID          = 0x1B0eU, /*!< GMAC has invalid pkt received */
    STATUS_GMAC_INVALID_TX_BUFFER         = 0x1B10U, /*!< GMAC TX   buffer not enough*/
    STATUS_GMAC_INVALID_RX_BUFFER         = 0x1B11U, /*!< GMAC RX   buffer not enough*/
    STATUS_GMAC_INVALID_TRANS_SPEED       = 0x1B12U, /*!< GMAC transmit speed is invalid*/
} status_t;

#endif /* STATUS_H_ */

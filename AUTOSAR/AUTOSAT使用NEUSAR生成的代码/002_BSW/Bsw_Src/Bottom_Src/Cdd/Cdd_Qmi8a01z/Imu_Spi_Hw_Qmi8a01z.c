#include "iohwabs_spi_hw.h"

static void qmi8a01z_spi_init(SpiHwConfig_STR* Ishq_valConfig)
{
    /* reserved */
}

static uint8 qmi8a01z_spi_transfer8(SpiHwConfig_STR* Ishq_valConfig, uint16 Ishq_valLength)
{
    uint8* Ishq_valTxData = (uint8*)Ishq_valConfig->spi_txbuffer;
    uint8* Ishq_valRxData = (uint8*)Ishq_valConfig->spi_rxbuffer;

    if((!Ishq_valConfig) ||\
        (Ishq_valLength > Ishq_valConfig->spi_length)) {
        return FALSE;
    }

    Spi_SetupEB(Ishq_valConfig->spi_channel, Ishq_valTxData, Ishq_valRxData, Ishq_valLength);
    Spi_SyncTransmit(Ishq_valConfig->spi_sequence);

    return TRUE;
}

const SpiHwOps_STR Imu_valSpiHwOps_Mp = {
    .init = qmi8a01z_spi_init,
    .transfer = qmi8a01z_spi_transfer8
};

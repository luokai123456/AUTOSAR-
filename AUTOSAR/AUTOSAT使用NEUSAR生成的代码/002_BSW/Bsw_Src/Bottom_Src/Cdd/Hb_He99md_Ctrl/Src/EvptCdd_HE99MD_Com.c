#include "EvptCdd_HE99MD_Com.h"
#include "IoHwAbs_SPI.h"

void Hbridge_SPI_RW_Function
(
	Spi_ChannelType HB_Channel, Spi_SequenceType HB_Sequence,
	uint16 *HB_TxBuffer, uint16 *HB_RxBuffer, uint8 HB_Len
)
{
	IoHwAbs_Spi_SetupEB(HB_Channel, &HB_TxBuffer[0], &HB_RxBuffer[0], HB_Len);
	IoHwAbs_Spi_SyncTransmit(HB_Sequence);
}


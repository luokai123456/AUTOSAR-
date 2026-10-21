#ifndef __EVPTCDD_HB_HE99MD_COM_H_
#define __EVPTCDD_HB_HE99MD_COM_H_

#include "StandardTypes.h"
#include "EvptCdd_HE99MD_prv.h"


extern void Hbridge_SPI_RW_Function(
	Spi_ChannelType HB_Channel, Spi_SequenceType HB_Sequence,
	uint16 *HB_TxBuffer, uint16 *HB_RxBuffer, uint8 HB_Len);

#endif /*__EVPTCDD_HB_HE99MD_COM_H_*/

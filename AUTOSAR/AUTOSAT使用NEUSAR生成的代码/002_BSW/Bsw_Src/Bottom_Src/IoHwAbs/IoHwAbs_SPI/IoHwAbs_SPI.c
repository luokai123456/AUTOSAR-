/*** create info ***********************
*@ Author : yanxinlong
*@ date :2024-12-03
*@ Description :Abstraction Layer SPI  file.
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : yanxinlong
*@ date :2024-12-03
*@ Modification Description :
初始版本
****************************************/

/*******************************************************************************
 * Includes
 *******************************************************************************/
#include "IoHwAbs_SPI.h"

void IoHwAbs_Spi_Init(void)
{
	Spi_Init(&Spi_Configuration);
}

/*****************************************************************************
**  Service Name     :  IoHwAbs_Spi_SetupEB
**
**  Description      :
**
**  Parameters (in)  :  channel
**
**  Parameters (in) :
**
**  Parameters (out) :  None
**
**  Return value     :  None
**
******************************************************************************/
void IoHwAbs_Spi_SetupEB(uint8 channel,uint16* TxData,uint16* RxData,uint8 length)
{
	Spi_SetupEB(channel, TxData, RxData, length);
}


/**
 * 函数名称: IoHwAbs_Spi_SyncTransmit
 * 参数: Sequence
 * 返回值: void
 * 描述: description
 */
void IoHwAbs_Spi_SyncTransmit(uint8 Sequence)
{
	Spi_SyncTransmit(Sequence);
}










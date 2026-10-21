/*** create info ***********************
*@ Author : yanxinlong
*@ date :2024-12-03
*@ Description :Abstraction Layer SPI H file.
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : yanxinlong
*@ date :2024-12-03
*@ Modification Description :
初始版本
****************************************/

#ifndef IOHWABS_SPI_H_
#define IOHWABS_SPI_H_

/*******************************************************************************
 * Includes
 *******************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Spi.h"


extern void IoHwAbs_Spi_Init(void);
extern void IoHwAbs_Spi_SyncTransmit(Spi_SequenceType Sequence);
extern void IoHwAbs_Spi_SetupEB(uint8 channel,uint16* TxData,uint16* RxData,uint8 length);


#endif /* IOHWABS_SPI_H_ */

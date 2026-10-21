/*** create info ***********************
*@ Author : yanxinlong
*@ date :2024-12-03
*@ Description :Abstraction Layer SPI_HW  H file.
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : yanxinlong
*@ date :2024-12-03
*@ Modification Description :
初始版本
****************************************/
#ifndef __IMU_SPI_HW_H_
#define __IMU_SPI_HW_H_

#include "typedefs.h"
#include "Spi.h"

typedef struct {
    const uint8 spi_cspin;
    const uint8 spi_channel;
    const uint8 spi_sequence;
    const uint8 spi_length;
    void* spi_txbuffer;
    void* spi_rxbuffer;
}SpiHwConfig_STR;

typedef struct {
    void (*init)(SpiHwConfig_STR*);
    uint8 (*transfer)(SpiHwConfig_STR*, uint16);
}SpiHwOps_STR;

#endif /* __IMU_SPI_HW_H_ */

#include "Cdd_Imu_Control.h"

static QMI8A01Z_DevType Imu_valDev_Mp = {
    .base = {
        .state = IMU_DEVICE_STATE_UNINIT,
        .init = Cdd_Imu_QMI8A01Z_DeviceInit,
        .calib = Cdd_Imu_QMI8A01Z_DeviceCalib,
        .process = Cdd_Imu_QMI8A01Z_DeviceProcess,
    },
    .spi_hw_config = {
        .spi_channel = 2,
        .spi_sequence = 2,
        .spi_length = IMU_SPI_BUFFER_SIZE,
    },
};

QMI8A01Z_DevType* Imu_valDevPtr_Mp = &Imu_valDev_Mp;
#define IMU_DEV_INSTANCE ((void*)Imu_valDevPtr_Mp)

void Cdd_Imu_Init(void)
{
    Imu_BaseDevice* Cic_valDev_Lo = NULL;

    Cic_valDev_Lo = &Imu_valDevPtr_Mp->base;
    Cic_valDev_Lo->state = IMU_DEVICE_STATE_INITING;
    if (Cic_valDev_Lo->init && !Cic_valDev_Lo->init(IMU_DEV_INSTANCE))
    {
        Cic_valDev_Lo->state = IMU_DEVICE_STATE_ERROR;
    }
    else
    {
        Cic_valDev_Lo->state = IMU_DEVICE_STATE_READY;
    }
}


void Cdd_Imu_MainFunction_10ms(void)
{
    Imu_BaseDevice* Cic_valDev_Lo = NULL;
    Cic_valDev_Lo = &Imu_valDevPtr_Mp->base;
    if ((IMU_DEVICE_STATE_READY == Cic_valDev_Lo->state) && Cic_valDev_Lo->process) {
        Cic_valDev_Lo->process(IMU_DEV_INSTANCE);
        Cic_valDev_Lo->calib(IMU_DEV_INSTANCE);
    }
}

#ifndef __CDD_IMU_QMI8A01Z_H_
#define __CDD_IMU_QMI8A01Z_H_

#include <string.h>
#include "CalibImuBias.h"
#include "iohwabs_spi_hw.h"
#include "Cdd_Imu_Release.h"

#define IMU_SPI_BUFFER_SIZE         13

/* qmi8a01z六轴传感器的寄存器原始数据 */
typedef struct {
    uint16_t    accel_x;
    uint16_t    accel_y;
    uint16_t    accel_z;
    uint16_t    gyro_x;
    uint16_t    gyro_y;
    uint16_t    gyro_z;
    uint32_t    time_stamp;
}QMI8A01Z_RawDataType;

/* qmi8a01z六轴传感器的转换之后的数据 */
typedef struct {
    float   accel_x;
    float   accel_y;
    float   accel_z;
    float   gyro_x;
    float   gyro_y;
    float   gyro_z;
    float   time_stamp;
}QMI8A01Z_6AxisDataType;

typedef enum {
    IMU_DEVICE_STATE_UNINIT,
    IMU_DEVICE_STATE_INITING,
    IMU_DEVICE_STATE_READY,
    IMU_DEVICE_STATE_ERROR
} Imu_DeviceState;

/* Imu的基础设备类型 */
typedef struct {
    Imu_DeviceState state;
    boolean (*init)(void* dev);
    void (*deinit)(void* dev);// reserved
    boolean (*calib)(void* dev);
    void (*process)(void* dev);
} Imu_BaseDevice;

/* qmi8a01z的设备类型 */
typedef struct {
    Imu_BaseDevice base;
    SpiHwConfig_STR spi_hw_config;
    const SpiHwOps_STR* spi_hw_ops;
    ImuBaseData_ST calib_base;
    CalibImuBiasParam_ST calib_res;
    QMI8A01Z_6AxisDataType proc_lastdata;
    IMU_6AxisData_STR proc_calcdata;
    uint16 calib_time;
    uint16_t reg_rawtemp;
    uint8 bist;
    uint8 step;
    uint8 calib;
    uint8 spi_tx_buf[IMU_SPI_BUFFER_SIZE];
    uint8 spi_rx_buf[IMU_SPI_BUFFER_SIZE];
}QMI8A01Z_DevType;

extern const uint8 Cdd_Imu_AxisCalibration[3];

extern const SpiHwOps_STR Imu_valSpiHwOps_Mp;
extern boolean Cdd_Imu_QMI8A01Z_DeviceInit(void* Idq_valDev);
extern boolean Cdd_Imu_QMI8A01Z_DeviceCalib(void* Idq_valDev);
extern void Cdd_Imu_QMI8A01Z_DeviceProcess(void* Idq_valDev);

#endif /* __CDD_IMU_QMI8A01Z_H_ */



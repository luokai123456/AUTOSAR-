#include "Cdd_Imu_Qmi8a01z.h"
#include "Qmi8a01z_Types.h"
#include "IoHwAbs_DIO_prv.h"
#include "Imu_Filter.h"
#include "Cdd_Imu_MountAngleCalib.h"
#include <math.h>

/* 自检时间很长(400多ms)，可选(默认关闭)*/
#define QMI8A01Z_BIST_SUPPORT		0

/* 寄存器地址 */
typedef enum {
    /* Chip Info */
    QMI8A01Z_WHO_AM_I           = 0x00,
    QMI8A01Z_REVISION_ID        = 0x01,
    /* Ctrl */
    QMI8A01Z_CTRL1              = 0x02,
    QMI8A01Z_CTRL2              = 0x03,
    QMI8A01Z_CTRL3              = 0x04,
    QMI8A01Z_CTRL5              = 0x06,
    QMI8A01Z_CTRL7              = 0x08,
    QMI8A01Z_CTRL8              = 0x09,
    QMI8A01Z_CTRL9              = 0x0a,
    /* Cal */
    QMI8A01Z_CAL1_L             = 0x0b,
    QMI8A01Z_CAL1_H             = 0x0c,
    QMI8A01Z_CAL2_L             = 0x0d,
    QMI8A01Z_CAL2_H             = 0x0e,
    QMI8A01Z_CAL3_L             = 0x0f,
    QMI8A01Z_CAL3_H             = 0x10,
    QMI8A01Z_CAL4_L             = 0x11,
    QMI8A01Z_CAL4_H             = 0x12,
    /* FIFO */
    QMI8A01Z_FIFO_WTM_TH        = 0x13,
    QMI8A01Z_FIFO_CTRL          = 0x14,
    QMI8A01Z_FIFO_SMPL_CNT      = 0x15,
    QMI8A01Z_FIFO_STATUS        = 0x16,
    QMI8A01Z_FIFO_DATA          = 0x17,
    /* Status */
    QMI8A01Z_STATUSINT          = 0x2d,
    QMI8A01Z_STATUS0            = 0x2e,
    QMI8A01Z_STATUS1            = 0x2f,
    /* Timestamp*/
    QMI8A01Z_TIMESTAMP_LOW      = 0x30,
    QMI8A01Z_TIMESTAMP_MID      = 0x31,
    QMI8A01Z_TIMESTAMP_HIGH     = 0x32,
    /* Data Output */
    QMI8A01Z_TEMP_L             = 0x33,
    QMI8A01Z_TEMP_H             = 0x34,
    QMI8A01Z_AX_L               = 0x35,
    QMI8A01Z_AX_H               = 0x36,
    QMI8A01Z_AY_L               = 0x37,
    QMI8A01Z_AY_H               = 0x38,
    QMI8A01Z_AZ_L               = 0x39,
    QMI8A01Z_AZ_H               = 0x3a,
    QMI8A01Z_GX_L               = 0x3b,
    QMI8A01Z_GX_H               = 0x3c,
    QMI8A01Z_GY_L               = 0x3d,
    QMI8A01Z_GY_H               = 0x3e,
    QMI8A01Z_GZ_L               = 0x3f,
    QMI8A01Z_GZ_H               = 0x40,
    /* COD */
    QMI8A01Z_COD_STATUS_L       = 0x46,
    QMI8A01Z_dQW_L              = 0x49,
    QMI8A01Z_dQW_H              = 0x4a,
    QMI8A01Z_dQX_L              = 0x4b,
    QMI8A01Z_dQX_H              = 0x4c,
    QMI8A01Z_dQY_L              = 0x4d,
    QMI8A01Z_dQY_H              = 0x4e,
    QMI8A01Z_dQZ_L              = 0x4f,
    QMI8A01Z_dQZ_H              = 0x50,
    QMI8A01Z_dVX_L              = 0x51,
    QMI8A01Z_dVX_H              = 0x52,
    QMI8A01Z_dVY_L              = 0x53,
    QMI8A01Z_dVY_H              = 0x54,
    QMI8A01Z_dVZ_L              = 0x55,
    QMI8A01Z_dVZ_H              = 0x56,
    /* Activity Detection Output */
    QMI8A01Z_TAP_STATUS         = 0x59,
    /* Reset Register */
    QMI8A01Z_RESET              = 0x60
}QMI8A01Z_RegisterAddressType;

/* 状态机步骤 */
#define QMI8A01Z_STEP_RESET                                 0
#define QMI8A01Z_STEP_RESET_WAIT                            1
#define QMI8A01Z_STEP_INIT                                  2
#define QMI8A01Z_STEP_BIST                                  3
#define QMI8A01Z_STEP_START                                 4
#define QMI8A01Z_STEP_PROC                                  5

/* spi相关 */
#define QMI8A01Z_SPI_WRITE                                  0
#define QMI8A01Z_SPI_READ                                   1
#define QMI8A01Z_SPI_COMBINE_FRAME(rw, addr)                (((rw) << 7) | (addr)) //组包

static void Cdd_Imu_ProcessRawData(
    QMI8A01Z_DevType* Ciq_valDev,
    QMI8A01Z_RawDataType* Ciq_valRawData, 
    QMI8A01Z_6AxisDataType* Ciq_valLastData,
    IMU_6AxisData_STR* Ciq_valResultData
)
{
    int16_t raw_accel[6] = {0};
    int16_t raw_gyro[6] = {0};

    int16_t raw_accel_x = 0;
    int16_t raw_accel_y = 0;
    int16_t raw_accel_z = 0;
    int16_t raw_gyro_x = 0;
    int16_t raw_gyro_y = 0;
    int16_t raw_gyro_z = 0;
    float gravity_x = 0;
    float gravity_y = 0;
    float gravity_z = 0;
    float roll, pitch, yaw;
    QMI8A01Z_6AxisDataType raw_6axis_data = {0};

    if((!Ciq_valDev) || (!Ciq_valRawData) || (!Ciq_valLastData) || (!Ciq_valResultData))
        return;
/****************************坐标轴对齐***********************************/
    raw_accel[0] =   (int16_t)Ciq_valRawData->accel_x;
    raw_accel[1] = - (int16_t)Ciq_valRawData->accel_x;
    raw_accel[2] =   (int16_t)Ciq_valRawData->accel_y;
    raw_accel[3] = - (int16_t)Ciq_valRawData->accel_y;
    raw_accel[4] =   (int16_t)Ciq_valRawData->accel_z;
    raw_accel[5] = - (int16_t)Ciq_valRawData->accel_z;

    raw_gyro[0] =   (int16_t)Ciq_valRawData->gyro_x;
    raw_gyro[1] = - (int16_t)Ciq_valRawData->gyro_x;
    raw_gyro[2] =   (int16_t)Ciq_valRawData->gyro_y;
    raw_gyro[3] = - (int16_t)Ciq_valRawData->gyro_y;
    raw_gyro[4] =   (int16_t)Ciq_valRawData->gyro_z;
    raw_gyro[5] = - (int16_t)Ciq_valRawData->gyro_z;

    raw_accel_x = raw_accel[Cdd_Imu_AxisCalibration[0]];
    raw_accel_y = raw_accel[Cdd_Imu_AxisCalibration[1]];
    raw_accel_z = raw_accel[Cdd_Imu_AxisCalibration[2]];
    raw_gyro_x = raw_gyro[Cdd_Imu_AxisCalibration[0]];
    raw_gyro_y = raw_gyro[Cdd_Imu_AxisCalibration[1]];
    raw_gyro_z = raw_gyro[Cdd_Imu_AxisCalibration[2]];

    /* 2、转换为物理量 */
    raw_6axis_data.accel_x = (float)raw_accel_x / 16384.0f - Ciq_valDev->calib_res.acclBias[0] / GRAVITY;
    raw_6axis_data.accel_y = (float)raw_accel_y / 16384.0f - Ciq_valDev->calib_res.acclBias[1] / GRAVITY;
    raw_6axis_data.accel_z = (float)raw_accel_z / 16384.0f - Ciq_valDev->calib_res.acclBias[2] / GRAVITY;
    raw_6axis_data.gyro_x = (float)raw_gyro_x / 256.0f - Ciq_valDev->calib_res.gyroBias[0] * R2D;
    raw_6axis_data.gyro_y = (float)raw_gyro_y / 256.0f - Ciq_valDev->calib_res.gyroBias[1] * R2D;
    raw_6axis_data.gyro_z = (float)raw_gyro_z / 256.0f - Ciq_valDev->calib_res.gyroBias[2] * R2D;
    raw_6axis_data.time_stamp = (float)Ciq_valRawData->time_stamp;
/*安装角对齐*/    
    Cdd_Imu_ApplyMountAngleRotation(
        &raw_6axis_data.accel_x, &raw_6axis_data.accel_y, &raw_6axis_data.accel_z,
        &raw_6axis_data.gyro_x, &raw_6axis_data.gyro_y, &raw_6axis_data.gyro_z,
        IMU_Angel_Calib_Data.roll_offset,
        - IMU_Angel_Calib_Data.pitch_offset,
        IMU_Angel_Calib_Data.yaw_offset
    );

    /* 3、姿态解算 */
    Imu_Complementary_Filter(&raw_6axis_data, &roll, &pitch, &yaw);

    /* 4、计算重力分量 */
    gravity_x = sin(pitch * M_PI / 180.0f);
    gravity_y = sin(roll * M_PI / 180.0f) * cos(pitch * M_PI / 180.0f);
    gravity_z = cos(pitch * M_PI / 180.0f) * cos(roll * M_PI / 180.0f);

    /* 5、计算线性加速度/根据车上坐标系 */
    Ciq_valResultData->accel_x = raw_6axis_data.accel_x - gravity_x;
    Ciq_valResultData->accel_y = raw_6axis_data.accel_y - gravity_y;
    Ciq_valResultData->accel_z = raw_6axis_data.accel_z - gravity_z;

    Ciq_valResultData->roll_angle = roll;
    Ciq_valResultData->pitch_angle = pitch;
    Ciq_valResultData->yaw_angle = yaw;
    Ciq_valResultData->time_stamp = raw_6axis_data.time_stamp;

    memcpy(Ciq_valLastData, &raw_6axis_data, sizeof(QMI8A01Z_6AxisDataType));
}

static void Cdd_Imu_QMI8A01Z_WriteRegister (
    QMI8A01Z_DevType* Ciq_valDev,
    QMI8A01Z_RegisterAddressType Ciq_valAddr,
    uint8 Ciq_valData
)
{
    uint8* Ciq_valTxDataPtr = &Ciq_valDev->spi_tx_buf[0];

    if(NULL == Ciq_valDev)  return;

    Ciq_valTxDataPtr[0] = QMI8A01Z_SPI_COMBINE_FRAME(QMI8A01Z_SPI_WRITE, Ciq_valAddr);
    Ciq_valTxDataPtr[1] = Ciq_valData;

    Ciq_valDev->spi_hw_ops->transfer(
        &Ciq_valDev->spi_hw_config,
        2   
    );
    memset(Ciq_valTxDataPtr, 0, 2);
}

static void Cdd_Imu_QMI8A01Z_ReadRegister (
    QMI8A01Z_DevType* Ciq_valDev,
    QMI8A01Z_RegisterAddressType Ciq_valAddr,
    uint8 Ciq_valLength
)
{
    uint8* Ciq_valTxDataPtr = &Ciq_valDev->spi_tx_buf[0];

    if((NULL == Ciq_valDev) || (Ciq_valLength > Ciq_valDev->spi_hw_config.spi_length))  return;

    Ciq_valTxDataPtr[0] = QMI8A01Z_SPI_COMBINE_FRAME(QMI8A01Z_SPI_READ, Ciq_valAddr);

    Ciq_valDev->spi_hw_ops->transfer(
        &Ciq_valDev->spi_hw_config,
        Ciq_valLength
    );
    memset(Ciq_valTxDataPtr, 0, 1);
}

static void Cdd_Imu_QMI8A01Z_SoftwareReset(QMI8A01Z_DevType* Ciq_valDev)
{
    Cdd_Imu_QMI8A01Z_WriteRegister(Ciq_valDev, QMI8A01Z_RESET, 0xb0);
    Cdd_Imu_QMI8A01Z_WriteRegister(Ciq_valDev, QMI8A01Z_RESET, 0xb0);
}

static void Cdd_Imu_QMI8A01Z_RegInit(QMI8A01Z_DevType *Ciq_valDev)
{
    uint8 Ciq_valSendData_Lo = 0;

	/* Ctrl7 */
    Ciq_valSendData_Lo = QMI8A01Z_CTRL7_SyncSample_SET(0)\
                            | QMI8A01Z_CTRL7_DRDY_DIS_SET(0)\
                            | QMI8A01Z_CTRL7_gSN_SET(0)\
                            | QMI8A01Z_CTRL7_gEN_SET(0)\
                            | QMI8A01Z_CTRL7_aEN_SET(0);
    Cdd_Imu_QMI8A01Z_WriteRegister(Ciq_valDev, QMI8A01Z_CTRL7, Ciq_valSendData_Lo);

	/* Ctrl1 */
    Ciq_valSendData_Lo = QMI8A01Z_CTRL1_SIM_SET(0)\
                            | QMI8A01Z_CTRL1_ADDR_AI_SET(1)\
                            | QMI8A01Z_CTRL1_BE_SET(1)\
                            | QMI8A01Z_CTRL1_INT2_EN_SET(1)\
                            | QMI8A01Z_CTRL1_INT1_EN_SET(1)\
                            | QMI8A01Z_CTRL1_FIFO_INT_SEL_SET(0)\
                            | QMI8A01Z_CTRL1_SensororDisable_SET(0);
    Cdd_Imu_QMI8A01Z_WriteRegister(Ciq_valDev, QMI8A01Z_CTRL1, Ciq_valSendData_Lo);

	/* Ctrl2 */
    Ciq_valSendData_Lo = QMI8A01Z_CTRL2_aST_SET(0)\
                            | QMI8A01Z_CTRL2_aFS_SET(0)\
                            | QMI8A01Z_CTRL2_aODR_SET(6);
    Cdd_Imu_QMI8A01Z_WriteRegister(Ciq_valDev, QMI8A01Z_CTRL2, Ciq_valSendData_Lo);

	/* Ctrl3 */
    Ciq_valSendData_Lo = QMI8A01Z_CTRL3_gST_SET(0)\
                            | QMI8A01Z_CTRL3_gFS_SET(0)\
                            | QMI8A01Z_CTRL3_gODR_SET(6);
    Cdd_Imu_QMI8A01Z_WriteRegister(Ciq_valDev, QMI8A01Z_CTRL3, Ciq_valSendData_Lo);

	/* Ctrl5 */
    Ciq_valSendData_Lo = QMI8A01Z_CTRL5_gLPF_MODE_SET(3)\
                            | QMI8A01Z_CTRL5_gLPF_EN_SET(1)\
                            | QMI8A01Z_CTRL5_aLPF_MODE_SET(3)\
                            | QMI8A01Z_CTRL5_aLPF_EN_SET(1);
    Cdd_Imu_QMI8A01Z_WriteRegister(Ciq_valDev, QMI8A01Z_CTRL5, Ciq_valSendData_Lo);

	/* FIFO Ctrl */
    Ciq_valSendData_Lo = QMI8A01Z_FIFO_CTRL_FIFO_RD_MODE_SET(0)\
                            | QMI8A01Z_FIFO_CTRL_FIFO_SIZE_SET(0)\
                            | QMI8A01Z_FIFO_CTRL_FIFO_MODE_SET(0);
    Cdd_Imu_QMI8A01Z_WriteRegister(Ciq_valDev, QMI8A01Z_FIFO_CTRL, Ciq_valSendData_Lo);
}

static void Cdd_Imu_QMI8A01Z_RunBist(QMI8A01Z_DevType* Ciq_valDev)
{
    uint8 Ciq_valInt2_Lo = 0;
    uint8 Ciq_valWriteData_Lo = 0;
    uint8* Ciq_valReadDataPtr_Lo = &Ciq_valDev->spi_rx_buf[0];
    uint16 Ciq_valCalData_Lo[3] = {0};

    if(0 == Ciq_valDev->bist)	// Accelerometer Self-Test
    {
        Cdd_Imu_QMI8A01Z_ReadRegister(Ciq_valDev, QMI8A01Z_CTRL2, 2);
        Ciq_valWriteData_Lo = Ciq_valReadDataPtr_Lo[1];
        Ciq_valWriteData_Lo |= QMI8A01Z_CTRL2_aST_SET(1);
        Cdd_Imu_QMI8A01Z_WriteRegister(Ciq_valDev, QMI8A01Z_CTRL2, Ciq_valWriteData_Lo);
        Ciq_valDev->bist++;
    }
    else if(1 == Ciq_valDev->bist)
    {
        //IoHwAbs_DIO_GetChannelValue(IOHWABS_DIOCHANNEL_MCU_IMU_INT2, &Ciq_valInt2_Lo);
    	if(Ciq_valInt2_Lo)
        {
            Cdd_Imu_QMI8A01Z_ReadRegister(Ciq_valDev, QMI8A01Z_CTRL2, 2);
            Ciq_valWriteData_Lo = Ciq_valReadDataPtr_Lo[1];
            Ciq_valWriteData_Lo &= ~QMI8A01Z_CTRL2_aST_SET(1);
            Cdd_Imu_QMI8A01Z_WriteRegister(Ciq_valDev, QMI8A01Z_CTRL2, Ciq_valWriteData_Lo);
            Ciq_valDev->bist++;
    	}
    }
    else if(2 == Ciq_valDev->bist)
    {
        //IoHwAbs_DIO_GetChannelValue(IOHWABS_DIOCHANNEL_MCU_IMU_INT2, &Ciq_valInt2_Lo);
        if(Ciq_valInt2_Lo)
        {
            Cdd_Imu_QMI8A01Z_ReadRegister(Ciq_valDev, QMI8A01Z_dVX_L, 7);
            Ciq_valCalData_Lo[0] = (uint16)((Ciq_valReadDataPtr_Lo[2] << 8) | (Ciq_valReadDataPtr_Lo[1]));
            Ciq_valCalData_Lo[1] = (uint16)((Ciq_valReadDataPtr_Lo[4] << 8) | (Ciq_valReadDataPtr_Lo[3]));
            Ciq_valCalData_Lo[2] = (uint16)((Ciq_valReadDataPtr_Lo[6] << 8) | (Ciq_valReadDataPtr_Lo[5]));
            if(((Ciq_valCalData_Lo[0] / 2) >= 200)\
                && ((Ciq_valCalData_Lo[1] / 2) >= 200)\
                && ((Ciq_valCalData_Lo[2] / 2) >= 200)) {
                Ciq_valDev->bist++;
            }
        }
    }
    else if(3 == Ciq_valDev->bist)	// Gyroscope Self-Test
    {
        Cdd_Imu_QMI8A01Z_ReadRegister(Ciq_valDev, QMI8A01Z_CTRL3, 2);
        Ciq_valWriteData_Lo = Ciq_valReadDataPtr_Lo[1];
        Ciq_valWriteData_Lo |= QMI8A01Z_CTRL3_gST_SET(1);
        Cdd_Imu_QMI8A01Z_WriteRegister(Ciq_valDev, QMI8A01Z_CTRL3, Ciq_valWriteData_Lo);
        Ciq_valDev->bist++;
    }
    else if(4 == Ciq_valDev->bist)
    {
        //IoHwAbs_DIO_GetChannelValue(IOHWABS_DIOCHANNEL_MCU_IMU_INT2, &Ciq_valInt2_Lo);
    	if(Ciq_valInt2_Lo)
        {
    		Cdd_Imu_QMI8A01Z_ReadRegister(Ciq_valDev, QMI8A01Z_CTRL3, 2);
			Ciq_valWriteData_Lo = Ciq_valReadDataPtr_Lo[1];
			Ciq_valWriteData_Lo &= ~QMI8A01Z_CTRL3_gST_SET(1);
			Cdd_Imu_QMI8A01Z_WriteRegister(Ciq_valDev, QMI8A01Z_CTRL3, Ciq_valWriteData_Lo);
			Ciq_valDev->bist++;
        }
    }
    else if(5 == Ciq_valDev->bist)
    {
        //IoHwAbs_DIO_GetChannelValue(IOHWABS_DIOCHANNEL_MCU_IMU_INT2, &Ciq_valInt2_Lo);
    	if(Ciq_valInt2_Lo)
        {
            Cdd_Imu_QMI8A01Z_ReadRegister(Ciq_valDev, QMI8A01Z_dVX_L, 7);
            Ciq_valCalData_Lo[0] = (uint16)((Ciq_valReadDataPtr_Lo[2] << 8) | (Ciq_valReadDataPtr_Lo[1]));
            Ciq_valCalData_Lo[1] = (uint16)((Ciq_valReadDataPtr_Lo[4] << 8) | (Ciq_valReadDataPtr_Lo[3]));
            Ciq_valCalData_Lo[2] = (uint16)((Ciq_valReadDataPtr_Lo[6] << 8) | (Ciq_valReadDataPtr_Lo[5]));
            if(((Ciq_valCalData_Lo[0] / 16) >= 300)\
                && ((Ciq_valCalData_Lo[1] / 16) >= 300)\
                && ((Ciq_valCalData_Lo[2] / 16) >= 300)) {
                Ciq_valDev->step = QMI8A01Z_STEP_START;
                Ciq_valDev->bist++;
            }
        }
    }
}

static void Cdd_Imu_QMI8A01Z_StartDataAcqu(QMI8A01Z_DevType* Ciq_valDev)
{
    uint8* Ciq_valReadDataPtr_Lo = &Ciq_valDev->spi_rx_buf[0];
    uint8 Ciq_valWriteData_Lo = 0;

    /* 加速度计量程 ±2g (aFS=0) */
    Cdd_Imu_QMI8A01Z_ReadRegister(Ciq_valDev, QMI8A01Z_CTRL2, 2);
    Ciq_valWriteData_Lo = Ciq_valReadDataPtr_Lo[1];
    Ciq_valWriteData_Lo &= ~QMI8A01Z_CTRL2_aFS_MASK;
    Ciq_valWriteData_Lo |= QMI8A01Z_CTRL2_aFS_SET(0);
    Cdd_Imu_QMI8A01Z_WriteRegister(Ciq_valDev, QMI8A01Z_CTRL2, Ciq_valWriteData_Lo);

    /* 陀螺仪量程 ±128dps (gFS=3) */
    Cdd_Imu_QMI8A01Z_ReadRegister(Ciq_valDev, QMI8A01Z_CTRL3, 2);
    Ciq_valWriteData_Lo = Ciq_valReadDataPtr_Lo[1];
    Ciq_valWriteData_Lo &= ~QMI8A01Z_CTRL3_gFS_MASK;
    Ciq_valWriteData_Lo |= QMI8A01Z_CTRL3_gFS_SET(3);
    Cdd_Imu_QMI8A01Z_WriteRegister(Ciq_valDev, QMI8A01Z_CTRL3, Ciq_valWriteData_Lo);

    /* 使能读取传感器数据的锁机制，打开惯性采集单元 */
    Cdd_Imu_QMI8A01Z_ReadRegister(Ciq_valDev, QMI8A01Z_CTRL7, 2);
    Ciq_valWriteData_Lo = Ciq_valReadDataPtr_Lo[1];
    Ciq_valWriteData_Lo |= QMI8A01Z_CTRL7_SyncSample_SET(1)\
                            | QMI8A01Z_CTRL7_gEN_SET(1)\
                            | QMI8A01Z_CTRL7_aEN_SET(1);
    Cdd_Imu_QMI8A01Z_WriteRegister(Ciq_valDev, QMI8A01Z_CTRL7, Ciq_valWriteData_Lo);
}

/**
 * @brief: Locking mechanism data reading process
 *  		- Reading to STATUSINT when data is available will trigger the lock mechanism, then we can  contain the sensor data
 *			- Continue to read the temperature
 * @para: none
 */
static void Cdd_Imu_ProcessPipeline(QMI8A01Z_DevType* Ciq_valDev)
{
    uint8_t IMU_valStatus_Lo = 0;
    uint8* Ciq_valReadDataPtr_Lo = &Ciq_valDev->spi_rx_buf[0];
    QMI8A01Z_RawDataType Ciq_valRawData_Lo = {0};

    if(!Ciq_valDev)
        return;

    Cdd_Imu_QMI8A01Z_ReadRegister(Ciq_valDev, QMI8A01Z_STATUSINT, 2);
    Cdd_Imu_QMI8A01Z_ReadRegister(Ciq_valDev, QMI8A01Z_STATUSINT, 2);
    IMU_valStatus_Lo = Ciq_valReadDataPtr_Lo[1];

    if(IMU_valStatus_Lo & QMI8A01Z_STATUSINT_Avail_MASK)
    {
        if(IMU_valStatus_Lo & QMI8A01Z_STATUSINT_Locked_MASK)
        {
            Cdd_Imu_QMI8A01Z_ReadRegister(Ciq_valDev, QMI8A01Z_TIMESTAMP_LOW, 4);
            Ciq_valRawData_Lo.time_stamp = (uint32)((Ciq_valReadDataPtr_Lo[3] << 16) | (Ciq_valReadDataPtr_Lo[2] << 8) | Ciq_valReadDataPtr_Lo[1]);
            Cdd_Imu_QMI8A01Z_ReadRegister(Ciq_valDev, QMI8A01Z_AX_L, 13);
            Ciq_valRawData_Lo.accel_x = ((Ciq_valReadDataPtr_Lo[2] << 8) | Ciq_valReadDataPtr_Lo[1]);
            Ciq_valRawData_Lo.accel_y = ((Ciq_valReadDataPtr_Lo[4] << 8) | Ciq_valReadDataPtr_Lo[3]);
            Ciq_valRawData_Lo.accel_z = ((Ciq_valReadDataPtr_Lo[6] << 8) | Ciq_valReadDataPtr_Lo[5]);
            Ciq_valRawData_Lo.gyro_x = ((Ciq_valReadDataPtr_Lo[8] << 8) | Ciq_valReadDataPtr_Lo[7]);
            Ciq_valRawData_Lo.gyro_y = ((Ciq_valReadDataPtr_Lo[10] << 8) | Ciq_valReadDataPtr_Lo[9]);
            Ciq_valRawData_Lo.gyro_z = ((Ciq_valReadDataPtr_Lo[12] << 8) | Ciq_valReadDataPtr_Lo[11]);
            Cdd_Imu_ProcessRawData(Ciq_valDev,
                                &Ciq_valRawData_Lo,
                                &Ciq_valDev->proc_lastdata,
                                &Ciq_valDev->proc_calcdata
                                );
        }
    }

    Cdd_Imu_QMI8A01Z_ReadRegister(Ciq_valDev, QMI8A01Z_TEMP_L, 3);
    Ciq_valDev->reg_rawtemp = (uint16)((Ciq_valReadDataPtr_Lo[2] << 8) | Ciq_valReadDataPtr_Lo[1]);
}

/* 实现基础设备类的init函数 */
boolean Cdd_Imu_QMI8A01Z_DeviceInit(void* Ciq_valDev)
{
    QMI8A01Z_DevType* Ciq_valDev_Lo = (QMI8A01Z_DevType*)Ciq_valDev;

    Ciq_valDev_Lo->bist = 0;
    Ciq_valDev_Lo->step = QMI8A01Z_STEP_RESET;
    Ciq_valDev_Lo->spi_hw_ops = &Imu_valSpiHwOps_Mp;
    Ciq_valDev_Lo->spi_hw_config.spi_txbuffer = (void*)&Ciq_valDev_Lo->spi_tx_buf[0];
    Ciq_valDev_Lo->spi_hw_config.spi_rxbuffer = (void*)&Ciq_valDev_Lo->spi_rx_buf[0];
    Ciq_valDev_Lo->reg_rawtemp = 0;
    memset(&Ciq_valDev_Lo->proc_lastdata, 0, sizeof(QMI8A01Z_6AxisDataType));
    memset(&Ciq_valDev_Lo->proc_calcdata, 0, sizeof(IMU_6AxisData_STR));
    /* Enable 1V8 */
    IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_1V8_EN, TRUE);
    /* Enable ImuEn */
    IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_IMU_EN, TRUE);

    return TRUE;
}

/* 实现基础设备类的calib函数 */
boolean Cdd_Imu_QMI8A01Z_DeviceCalib(void* Ciq_valDev)
{
    QMI8A01Z_DevType* Ciq_valDev_Lo = (QMI8A01Z_DevType*)Ciq_valDev;

    if(1 == Ciq_valDev_Lo->calib)
    {
        Cdd_Imu_CalibImuBiasStart();
        Ciq_valDev_Lo->calib++;
    }
    else if(2 == Ciq_valDev_Lo->calib)
    {
        if(Ciq_valDev_Lo->calib_time < 2000)
        {
            Ciq_valDev_Lo->calib_base.sysTime = Ciq_valDev_Lo->calib_time;
            Ciq_valDev_Lo->calib_base.accl[0] = Ciq_valDev_Lo->proc_lastdata.accel_x * GRAVITY; // 转换成m/s^2
            Ciq_valDev_Lo->calib_base.accl[1] = Ciq_valDev_Lo->proc_lastdata.accel_y * GRAVITY;
            Ciq_valDev_Lo->calib_base.accl[2] = Ciq_valDev_Lo->proc_lastdata.accel_z * GRAVITY;
            Ciq_valDev_Lo->calib_base.gyro[0] = D2R * Ciq_valDev_Lo->proc_lastdata.gyro_x; // 转换成rad/s
            Ciq_valDev_Lo->calib_base.gyro[1] = D2R * Ciq_valDev_Lo->proc_lastdata.gyro_y;
            Ciq_valDev_Lo->calib_base.gyro[2] = D2R * Ciq_valDev_Lo->proc_lastdata.gyro_z;
            if(Cdd_Imu_CalibImuBias(&Ciq_valDev_Lo->calib_base)) {
                Cdd_Imu_GetImuBiasParam(&Ciq_valDev_Lo->calib_res);
                Cdd_Imu_CalibImuBiasEnd();
                Ciq_valDev_Lo->calib = 0;
                Ciq_valDev_Lo->calib_time = 0;
                return TRUE;
            }
            Ciq_valDev_Lo->calib_time++;
        }
        else
        {
            Cdd_Imu_CalibImuBiasEnd();
            Ciq_valDev_Lo->calib = 0;
            Ciq_valDev_Lo->calib_time = 0;
            return FALSE;
        }
    }
    return FALSE;
}

/* 实现基础设备类的process函数 */
void Cdd_Imu_QMI8A01Z_DeviceProcess(void* Ciq_valDev)
{
    QMI8A01Z_DevType* Ciq_valDev_Lo = (QMI8A01Z_DevType*)Ciq_valDev;

    switch (Ciq_valDev_Lo->step)
    {
    case QMI8A01Z_STEP_RESET:
        Cdd_Imu_QMI8A01Z_SoftwareReset(Ciq_valDev_Lo);
        Ciq_valDev_Lo->step = QMI8A01Z_STEP_RESET_WAIT;
        break;
    case QMI8A01Z_STEP_RESET_WAIT:
        Ciq_valDev_Lo->step = QMI8A01Z_STEP_INIT;
        break;
    case QMI8A01Z_STEP_INIT:
        Cdd_Imu_QMI8A01Z_RegInit(Ciq_valDev_Lo);
        Ciq_valDev_Lo->step = QMI8A01Z_STEP_BIST;
        break;
    case QMI8A01Z_STEP_BIST:
#if QMI8A01Z_BIST_SUPPORT
        Cdd_Imu_QMI8A01Z_RunBist(Ciq_valDev_Lo);
#else
    	Ciq_valDev_Lo->step = QMI8A01Z_STEP_START;
#endif
    	break;
    case QMI8A01Z_STEP_START:
        Cdd_Imu_QMI8A01Z_StartDataAcqu(Ciq_valDev_Lo);
        Ciq_valDev_Lo->step = QMI8A01Z_STEP_PROC;
        break;
    case QMI8A01Z_STEP_PROC:
        Cdd_Imu_ProcessPipeline(Ciq_valDev_Lo);
        break;
    default:
        break;
    }
}

#include "Cdd_Imu_Qmi8a01z.h"
#include "Cdd_Imu_Control.h"

/**
 * @brief 用于获取6轴传感器数据
 * @param none
 * @return 6轴传感器数据
 */
IMU_6AxisData_STR Cdd_Imu_Read6AxisData(void)
{
    return Imu_valDevPtr_Mp->proc_calcdata;
}

/**
 * @brief 用于获取6轴传感器温度信息
 * @param none
 * @return 6轴传感器温度
 */
float Cdd_Imu_ReadSensorTemp(void)
{
    return Imu_valDevPtr_Mp->reg_rawtemp / 256.0;
}

/**
 * @brief 用于开启一次静置状态的标定
 * @param none
 * @return none
 */
void Cdd_Imu_StartCalibOnce(void)
{
    Imu_valDevPtr_Mp->calib = 1;
}


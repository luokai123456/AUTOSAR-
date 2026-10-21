#ifndef __CDD_IMU_MOUNTANGLECALIB_H_
#define __CDD_IMU_MOUNTANGLECALIB_H_

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "typedefs.h"


#define MA_D2R         ( 0.017453292519943 )    /* 角度转弧度系数 */
#define MA_R2D         57.29577951308232         /* 弧度转角度系数 */

typedef struct
{
    float32 roll_offset;  /* roll轴安装偏移角度(°) */
    float32 pitch_offset; /* pitch轴安装偏移角度(°) */
    float32 yaw_offset;   /* yaw轴安装偏移角度(°) */
} IMU_Angel_Calib_TDSTR;

/**
 * @brief 应用安装角度旋转变换
 * @details 使用旋转矩阵将传感器坐标系下的加速度计和陀螺仪数据转换到车身坐标系
 * @param accel_x 输入/输出，X轴加速度(单位g)
 * @param accel_y 输入/输出，Y轴加速度(单位g)
 * @param accel_z 输入/输出，Z轴加速度(单位g)
 * @param gyro_x 输入/输出，X轴角速度(°/s)
 * @param gyro_y 输入/输出，Y轴角速度(°/s)
 * @param gyro_z 输入/输出，Z轴角速度(°/s)
 * @param roll_offset roll轴安装偏移角度(°)
 * @param pitch_offset pitch轴安装偏移角度(°)
 * @param yaw_offset yaw轴安装偏移角度(°)
 */
void Cdd_Imu_ApplyMountAngleRotation(
    float* accel_x, float* accel_y, float* accel_z,
    float* gyro_x, float* gyro_y, float* gyro_z,
    float roll_offset, float pitch_offset, float yaw_offset
);
extern IMU_Angel_Calib_TDSTR IMU_Angel_Calib_Data; /* 安装角度校准结构体 */
#endif

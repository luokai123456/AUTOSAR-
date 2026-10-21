/*** create info ***********************
*@ Author : tianbohan 
*@ date :2025-12-05
*@ Description :IMU attitude calculation using Complementary Filter H file
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : tianbohan 
*@ date :2025-12-05
*@ Modification Description :
初始版本
****************************************/
#ifndef IMU_FILTER_H
#define IMU_FILTER_H

#include "Cdd_Imu_Qmi8a01z.h"

#define RADIAN_CONVERSION_FACTOR 0.0174532922
#define DEGREE_CONVERSION_FACTOR 57.295779513

/**
 * @brief 互补滤波器姿态解算函数
 * @details 融合加速度计和陀螺仪数据，使用四元数进行姿态估计
 * @param input_data 输入的IMU六轴数据（加速度计+陀螺仪）
 * @param roll 输出的roll角度（°）
 * @param pitch 输出的pitch角度（°）
 * @param yaw 输出的yaw角度（°）
 */
extern void Imu_Complementary_Filter(
    QMI8A01Z_6AxisDataType* input_data,
    float* roll,
    float* pitch,
    float* yaw
);

/**
 * @brief 重置互补滤波器内部状态(新增)
 * @details 将四元数状态重置为初始值(1,0,0,0)，积分误差项清零。
 *          用于安装角度标定开始和完成时，避免滤波器状态与新坐标系不匹配。
 */
extern void Imu_Complementary_Filter_Reset(void);

#endif /* IMU_FILTER_H */

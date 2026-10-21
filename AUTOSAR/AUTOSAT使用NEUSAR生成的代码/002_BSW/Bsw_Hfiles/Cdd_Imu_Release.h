
/*** create info ***********************
*@ Author : 
*@ date :2025-12-04
*@ Description :IMU release control functions
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : 
*@ date :2025-12-04
*@ Modification Description :
初始版本
****************************************/
#ifndef __IMU_RELEASE_H_
#define __IMU_RELEASE_H_

#include "typedefs.h"

/**
 * @brief 6轴传感器数据结构体
 * @param accel_x: x轴方向的线性加速度
 * @param accel_y: y轴方向的线性加速度
 * @param accel_z: z轴方向的线性加速度
 * @param roll_angle: 横滚角
 * @param pitch_angle: 俯仰角
 * @param yaw_angle: 偏航角
 * @param time_stamp: 时间戳
 */
typedef struct {
    float	accel_x;
    float	accel_y;
    float	accel_z;
    float	roll_angle;
    float   pitch_angle;
    float   yaw_angle;
    float	time_stamp;
} IMU_6AxisData_STR;

/**
 * @brief 用于获取6轴传感器数据
 * @param none
 * @return 6轴传感器数据
 */
IMU_6AxisData_STR Cdd_Imu_Read6AxisData(void);

/**
 * @brief 用于获取6轴传感器温度信息
 * @param none
 * @return 6轴传感器温度
 */
extern float Cdd_Imu_ReadSensorTemp(void);

/**
 * @brief 用于开启一次静置状态的标定
 * @param none
 * @return none
 */
extern void Cdd_Imu_StartCalibOnce(void);

/**
 * @brief 用于设置IMU安装角度偏移量
 * @param roll_offset roll轴安装偏移角度(°)
 * @param pitch_offset pitch轴安装偏移角度(°)
 * @param yaw_offset yaw轴安装偏移角度(°)
 * @return none
 */
extern void Cdd_Imu_AngelCalib_Set(float32 roll_offset, float32 pitch_offset, float32 yaw_offset);

#endif /* __IMU_RELEASE_H_ */
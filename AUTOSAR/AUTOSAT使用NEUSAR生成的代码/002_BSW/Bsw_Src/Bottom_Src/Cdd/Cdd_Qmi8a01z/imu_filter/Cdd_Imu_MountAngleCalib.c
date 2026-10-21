#include "Cdd_Imu_MountAngleCalib.h"
#include "Imu_Filter.h"
#include "typedefs.h"


IMU_Angel_Calib_TDSTR IMU_Angel_Calib_Data = {0.0f, 0.0f, 0.0f}; /* 初始化安装角度校准结构体 */


void Cdd_Imu_AngelCalib_Set(float32 roll_offset, float32 pitch_offset, float32 yaw_offset)
{
    IMU_Angel_Calib_Data.roll_offset = roll_offset;
    IMU_Angel_Calib_Data.pitch_offset = pitch_offset;
    IMU_Angel_Calib_Data.yaw_offset = yaw_offset;
}

/**
 * @brief 应用安装角度旋转变换
 * @details 使用旋转矩阵将传感器坐标系下的加速度计和陀螺仪数据转换到车身坐标系。
 *          旋转顺序为：先绕X轴旋转roll_offset，再绕Y轴旋转pitch_offset，最后绕Z轴旋转yaw_offset。
 *          旋转矩阵公式：R = R_x(roll) * R_y(pitch) * R_z(yaw)
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
)
{
    static float roll_offset_last = 0.0f, pitch_offset_last = 0.0f, yaw_offset_last = 0.0f;
    static float r11 = 1.0f, r12 = 0.0f, r13 = 0.0f , r21 = 0.0f, r22 = 1.0f, r23 = 0.0f,r31 = 0.0f, r32 = 0.0f, r33 = 1.0f;
    if (roll_offset != roll_offset_last || pitch_offset != pitch_offset_last || yaw_offset != yaw_offset_last)
    {
        /* 将角度转换为弧度 */
        float roll_rad = roll_offset * MA_D2R;
        float pitch_rad = pitch_offset * MA_D2R;
        float yaw_rad = yaw_offset * MA_D2R;

        /* 计算三角函数值 */
        float cos_r = cosf(roll_rad);
        float sin_r = sinf(roll_rad);
        float cos_p = cosf(pitch_rad);
        float sin_p = sinf(pitch_rad);
        float cos_y = cosf(yaw_rad);
        float sin_y = sinf(yaw_rad);

        /* 构建旋转矩阵 R = R_x(roll) * R_y(pitch) * R_z(yaw) */
        /* 旋转矩阵元素定义：
        * R = [cos_p*cos_y,                        -cos_p*sin_y,                       sin_p]
        *     [cos_r*sin_y + sin_r*sin_p*cos_y,    cos_r*cos_y - sin_r*sin_p*sin_y,    -sin_r*cos_p]
        *     [sin_r*sin_y - cos_r*sin_p*cos_y,    sin_r*cos_y + cos_r*sin_p*sin_y,    cos_r*cos_p]
        */
        r11 = cos_p * cos_y;
        r12 = -cos_p * sin_y;
        r13 = sin_p;
        r21 = cos_r * sin_y + sin_r * sin_p * cos_y;
        r22 = cos_r * cos_y - sin_r * sin_p * sin_y;
        r23 = -sin_r * cos_p;
        r31 = sin_r * sin_y - cos_r * sin_p * cos_y;
        r32 = sin_r * cos_y + cos_r * sin_p * sin_y;
        r33 = cos_r * cos_p;

        /* 更新上一次的安装角度 */
        roll_offset_last = roll_offset;
        pitch_offset_last = pitch_offset;
        yaw_offset_last = yaw_offset;
        Imu_Complementary_Filter_Reset(); /* 重置互补滤波器状态 */
    }
    /* 保存原始加速度值 */
    float ax = *accel_x;
    float ay = *accel_y;
    float az = *accel_z;

    /* 应用旋转矩阵转换加速度计数据 */
    *accel_x = r11 * ax + r12 * ay + r13 * az;
    *accel_y = r21 * ax + r22 * ay + r23 * az;
    *accel_z = r31 * ax + r32 * ay + r33 * az;

    /* 保存原始角速度值 */
    float gx = *gyro_x;
    float gy = *gyro_y;
    float gz = *gyro_z;

    /* 应用旋转矩阵转换陀螺仪数据 */
    *gyro_x = r11 * gx + r12 * gy + r13 * gz;
    *gyro_y = r21 * gx + r22 * gy + r23 * gz;
    *gyro_z = r31 * gx + r32 * gy + r33 * gz;
}

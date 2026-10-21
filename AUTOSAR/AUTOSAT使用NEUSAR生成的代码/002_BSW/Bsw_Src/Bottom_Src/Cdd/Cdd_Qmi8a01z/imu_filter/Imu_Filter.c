/*** create info ***********************
*@ Author : tianbohan 
*@ date :2025-12-05
*@ Description :IMU attitude calculation using Complementary Filter
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : tianbohan 
*@ date :2025-12-05
*@ Modification Description :
初始版本
****************************************/
#include <math.h>
#include "imu_filter.h"

/* Complementary filter coefficients */
/* Kp: Proportional gain for accelerometer correction */
/* Ki: Integral gain for gyroscope bias estimation */
float Imu_Kp = 1.0f;
float Imu_Ki = 0.001f;

/* 四元数状态变量，移到文件作用域以便 Reset 函数可以访问 */
/* q1, q2, q3, q4 表示当前姿态的四元数 */
static float q1 = 1, q2 = 0, q3 = 0, q4 = 0;

/* 积分误差项，用于陀螺仪零偏补偿 */
static float exi = 0, eyi = 0, ezi = 0;

/**
 * IMU Complementary Filter for attitude estimation
 * 
 * This function implements a complementary filter that combines accelerometer
 * and gyroscope data to estimate the orientation (roll, pitch, yaw) of the IMU.
 * The filter uses quaternions for orientation representation and provides
 * stable attitude estimation by fusing short-term gyroscope accuracy with
 * long-term accelerometer stability.
 * 
 * @param input_data Pointer to IMU sensor data (accelerometer and gyroscope)
 * @param roll Output roll angle in degrees
 * @param pitch Output pitch angle in degrees  
 * @param yaw Output yaw angle in degrees
 */

void Imu_Complementary_Filter(
    QMI8A01Z_6AxisDataType* input_data,
    float* roll,
    float* pitch,
    float* yaw
)
{   
    /* Time step for integration (10ms = 0.01s) */
    float dt = 0.01;
    
    float ax = input_data->accel_x;
    float ay = input_data->accel_y;
    float az = input_data->accel_z;
    
    /* Extract gyroscope data and convert to radians per second */
    float gx = input_data->gyro_x * RADIAN_CONVERSION_FACTOR; 
    float gy = input_data->gyro_y * RADIAN_CONVERSION_FACTOR; 
    float gz = input_data->gyro_z * RADIAN_CONVERSION_FACTOR; 

 

    /* Normalize accelerometer vector to unit length */
    /* This ensures the gravity vector has magnitude 1g */
    float a_norm = sqrtf(ax * ax + ay * ay + az * az);
    if (a_norm > 0) 
    {
        ax = ax / a_norm;
        ay = ay / a_norm;
        az = az / a_norm;
    } 
    else 
    {
        /* If accelerometer magnitude is zero, assume upright orientation */
        ax = 0; ay = 0; az = 1;  
    }

    /* Calculate the direction of gravity vector predicted by quaternion */
    /* This represents what the gravity vector should be based on current orientation */
    float vx = 2 * (q2 * q4 - q1 * q3);
    float vy = 2 * (q1 * q2 + q3 * q4);
    float vz = q1 * q1 - q2 * q2 - q3 * q3 + q4 * q4;

    /* Calculate error between measured and predicted gravity vectors */
    /* Cross product gives the orientation error */
    float ex = (ay * vz - az * vy);
    float ey = (az * vx - ax * vz);
    float ez = (ax * vy - ay * vx);

    /* Update integral error terms for gyroscope bias estimation */
    /* These accumulate over time to estimate and compensate for gyroscope drift */
    exi += ex * dt;
    eyi += ey * dt;
    ezi += ez * dt;

    /* Apply complementary filter correction to gyroscope data */
    /* Kp term provides immediate correction, Ki term estimates bias over time */
    gx = gx + ex * Imu_Kp + exi * Imu_Ki;
    gy = gy + ey * Imu_Kp + eyi * Imu_Ki;
    gz = gz + ez * Imu_Kp + ezi * Imu_Ki;

    /* Store current quaternion values for integration */
    float q1_temp = q1, q2_temp = q2, q3_temp = q3, q4_temp = q4;
    
    /* Quaternion integration using gyroscope data */
    /* This updates the orientation based on angular velocity */
    q1 += 0.5 * dt * (-q2_temp * gx - q3_temp * gy - q4_temp * gz);
    q2 += 0.5 * dt * (q1_temp * gx + q3_temp * gz - q4_temp * gy);
    q3 += 0.5 * dt * (q1_temp * gy - q2_temp * gz + q4_temp * gx);
    q4 += 0.5 * dt * (q1_temp * gz + q2_temp * gy - q3_temp * gx);

    /* Normalize quaternion to maintain unit length */
    /* This prevents numerical drift in the orientation estimation */
    float q_norm = sqrtf(q1 * q1 + q2 * q2 + q3 * q3 + q4 * q4);
    if (q_norm > 0)
    {
        float inv_norm = 1 / q_norm;
        q1 = inv_norm * q1;
        q2 = inv_norm * q2;
        q3 = inv_norm * q3;
        q4 = inv_norm * q4;
    }

    /* Convert quaternion to Euler angles (roll, pitch, yaw) */
    /* Roll angle calculation using atan2 for full 360-degree range */
    *roll = atan2f(2 * (q1 * q2 + q3 * q4), 1 - 2 * (q2 * q2 + q3 * q3)) * DEGREE_CONVERSION_FACTOR;    
    
    /* Pitch angle calculation with singularity handling */
    /* When pitch approaches ±90 degrees, use special handling */
    float sinp = 2 * (q1 * q3 - q4 * q2);
    if (fabsf(sinp) >= 1)
    {
        /* At singularity (gimbal lock), set pitch to ±90 degrees */
        *pitch = -copysignf(90, sinp);
    } 
    else
    {
        /* Normal pitch calculation using arcsin */
        *pitch = -asinf(sinp) * DEGREE_CONVERSION_FACTOR;
    }
    
    /* Yaw angle calculation using atan2 for full 360-degree range */
    *yaw = atan2f(2 * (q1 * q4 + q2 * q3), 1 - 2 * (q3 * q3 + q4 * q4)) * DEGREE_CONVERSION_FACTOR;
}

/**
 * @brief 重置互补滤波器内部状态(新增)
 * @details 将四元数状态重置为初始值(1,0,0,0)，积分误差项清零。
 *          用于安装角度标定开始和完成时，避免滤波器状态与新坐标系不匹配。
 *          当安装角度变化时，滤波器的旧四元数状态需要重置，否则会导致角度跳变。
 */
void Imu_Complementary_Filter_Reset(void)
{

    
    /* 重置四元数为单位四元数，表示初始姿态(无旋转) */
    q1 = 1.0f;
    q2 = 0.0f;
    q3 = 0.0f;
    q4 = 0.0f;
    
    /* 清零积分误差项 */
    exi = 0.0f;
    eyi = 0.0f;
    ezi = 0.0f;
}

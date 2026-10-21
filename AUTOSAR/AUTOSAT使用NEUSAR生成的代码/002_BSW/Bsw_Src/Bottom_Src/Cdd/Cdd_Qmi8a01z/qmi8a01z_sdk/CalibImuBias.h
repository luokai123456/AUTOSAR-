#pragma once
#ifndef _CALIBIMUBIAS_H
#define _CALIBIMUBIAS_H

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#define real        float
#define D2R         ( 0.017453292519943 )
#define R2D         57.29577951308232
#define GRAVITY     9.7803f


typedef struct
{
    double sysTime;
    real accl[3];  
    real gyro[3];
}ImuBaseData_ST;

typedef struct
{
    float acclBias[3];
    float gyroBias[3];
}CalibImuBiasParam_ST;

void Cdd_Imu_CalibImuBiasStart();
void Cdd_Imu_CalibImuBiasEnd();
bool Cdd_Imu_CalibImuBias(ImuBaseData_ST* imu);
void Cdd_Imu_GetImuBiasParam(CalibImuBiasParam_ST* ImuBias);


#endif

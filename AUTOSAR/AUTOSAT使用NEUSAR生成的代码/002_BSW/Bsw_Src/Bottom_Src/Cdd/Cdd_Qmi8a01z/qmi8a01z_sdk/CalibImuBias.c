#include "CalibImuBias.h"

typedef struct
{
    bool calibBiasInited;
    uint32_t meanCnt;
    real timeCalibStart;
    real acclCalibMean[3], gyroCalibMean[3];
    real acclCalibStd[3], gyroCalibStd[3];
    real acclCalibVar[3], gyroCalibVar[3];
    real calibBiasA[3], calibBiasG[3];
}CalibImuBiasData_ST;

CalibImuBiasData_ST gCalibImuBiasData = { 0 };

void Cdd_Imu_CalibImuBiasInit();
void Cdd_Imu_CalibImuBiasReset();
void Cdd_Imu_CalibImuMeanStd(ImuBaseData_ST* imu);
bool Cdd_Imu_CheckCalibStd();
bool Cdd_Imu_CheckBiasParam();

void Cdd_Imu_CalibImuBiasInit()
{
    gCalibImuBiasData.meanCnt = 1;
    for (uint8_t i = 0; i < 3; i++)
    {
        gCalibImuBiasData.acclCalibMean[i] = 0;
        gCalibImuBiasData.gyroCalibMean[i] = 0;
        gCalibImuBiasData.acclCalibVar[i] = 0;
        gCalibImuBiasData.gyroCalibVar[i] = 0;
        gCalibImuBiasData.acclCalibStd[i] = 0;
        gCalibImuBiasData.gyroCalibStd[i] = 0;
        gCalibImuBiasData.calibBiasA[i] = 0;
        gCalibImuBiasData.calibBiasG[i] = 0;
    }
    gCalibImuBiasData.timeCalibStart = 0;
    gCalibImuBiasData.calibBiasInited = true;
}

void Cdd_Imu_CalibImuBiasReset()
{
    gCalibImuBiasData.meanCnt = 1;
    for (uint8_t i = 0; i < 3; i++)
    {
        gCalibImuBiasData.acclCalibMean[i] = 0;
        gCalibImuBiasData.gyroCalibMean[i] = 0;
        gCalibImuBiasData.acclCalibVar[i] = 0;
        gCalibImuBiasData.gyroCalibVar[i] = 0;
        gCalibImuBiasData.acclCalibStd[i] = 0;
        gCalibImuBiasData.gyroCalibStd[i] = 0;
        gCalibImuBiasData.calibBiasA[i] = 0;
        gCalibImuBiasData.calibBiasG[i] = 0;
    }
    gCalibImuBiasData.timeCalibStart = 0;
    gCalibImuBiasData.calibBiasInited = false;
}

void Cdd_Imu_CalibImuMeanStd(ImuBaseData_ST* imu)
{
    real lastMeanAccl, lastMeanGyro;
    real lastVarAccl, lastVarGyro;
    real varAccl1, varAccl2, varGyro1, varGyro2;
    
    for (uint8_t i = 0; i < 3; i++)
    {
        // mean value
        lastMeanAccl = gCalibImuBiasData.acclCalibMean[i];
        gCalibImuBiasData.acclCalibMean[i] = (lastMeanAccl * (gCalibImuBiasData.meanCnt - 1) + imu->accl[i]) / gCalibImuBiasData.meanCnt;
        lastMeanGyro = gCalibImuBiasData.gyroCalibMean[i];
        gCalibImuBiasData.gyroCalibMean[i] = (lastMeanGyro * (gCalibImuBiasData.meanCnt - 1) + imu->gyro[i]) / gCalibImuBiasData.meanCnt;
        // std value
        if (gCalibImuBiasData.meanCnt > 1)
        {
            lastVarAccl = gCalibImuBiasData.acclCalibVar[i];
            varAccl1 = lastVarAccl * ((real)(gCalibImuBiasData.meanCnt) - 1) / (real)(gCalibImuBiasData.meanCnt);
            varAccl2 = (imu->accl[i] - lastMeanAccl) * (imu->accl[i] - lastMeanAccl) / (real)(gCalibImuBiasData.meanCnt);
            gCalibImuBiasData.acclCalibVar[i] = varAccl1 + varAccl2;
            lastVarGyro = gCalibImuBiasData.gyroCalibVar[i];
            varGyro1 = lastVarGyro * ((real)(gCalibImuBiasData.meanCnt) - 1) / (real)(gCalibImuBiasData.meanCnt);
            varGyro2 = (imu->gyro[i] - lastMeanGyro) * (imu->gyro[i] - lastMeanGyro) / (real)(gCalibImuBiasData.meanCnt);
            gCalibImuBiasData.gyroCalibVar[i] = varGyro1 + varGyro2;

            gCalibImuBiasData.acclCalibStd[i] = sqrtf(gCalibImuBiasData.acclCalibVar[i]);
            gCalibImuBiasData.gyroCalibStd[i] = sqrtf(gCalibImuBiasData.gyroCalibVar[i]);
        }
    }
    gCalibImuBiasData.meanCnt++;
}

bool Cdd_Imu_CheckCalibStd()
{
    bool flag = false;
    bool isAcclNormal = true;
    for (uint8_t i = 0; i < 3; i++)
    {
        if (gCalibImuBiasData.acclCalibStd[i] > 5.0f / 1000 * GRAVITY)// 0.000511
        {
            isAcclNormal = false;
            break;
        }
    }
    bool isGyroNormal = true;
    for (uint8_t i = 0; i < 3; i++)
    {
        if (gCalibImuBiasData.gyroCalibStd[i] > 0.3f * D2R)
        {
            isGyroNormal = false;
            break;
        }
    }

    if (isAcclNormal == true && isGyroNormal == true)
    {
        flag = true;
    }
    return flag;
}

bool Cdd_Imu_CheckBiasParam()
{
    bool flag = false;
    bool isAcclNormal = true;
    for (uint8_t i = 0; i < 3; i++) 
    {
        if (fabs(gCalibImuBiasData.calibBiasA[i]) > (75.0f / 1000 * GRAVITY)) //大于3sigma值
        {
            isAcclNormal = false;
            break;
        }
    }
    bool isGyroNormal = true;
    for (uint8_t i = 0; i < 3; i++) 
    {
        if (fabs(gCalibImuBiasData.calibBiasG[i]) > 15.0f * D2R) //大于3sigma值
        {
            isGyroNormal = false;
            break;
        }
    }
    if (isAcclNormal == true && isGyroNormal == true)
    {
        flag = true;
    }
    return flag;
}


void Cdd_Imu_CalibImuBiasStart()
{
    Cdd_Imu_CalibImuBiasInit();
}

void Cdd_Imu_CalibImuBiasEnd()
{
    Cdd_Imu_CalibImuBiasReset();
}

bool Cdd_Imu_CalibImuBias(ImuBaseData_ST* imu)
{   
    bool sucessFlag = false; //标定成功标志
    if (gCalibImuBiasData.calibBiasInited)
    {
        if (gCalibImuBiasData.meanCnt == 1)
        {
            gCalibImuBiasData.timeCalibStart = imu->sysTime;
        }
        Cdd_Imu_CalibImuMeanStd(imu); // mean and std 

        if (imu->sysTime - gCalibImuBiasData.timeCalibStart > 200.0f)
        {  
            if (Cdd_Imu_CheckCalibStd()) //判断std是否满足阈值要求
            {
                gCalibImuBiasData.calibBiasA[0] = gCalibImuBiasData.acclCalibMean[0]; //m/s2
                gCalibImuBiasData.calibBiasA[1] = gCalibImuBiasData.acclCalibMean[1];
                gCalibImuBiasData.calibBiasA[2] = gCalibImuBiasData.acclCalibMean[2];
                if (gCalibImuBiasData.calibBiasA[2] > 0)
                {
                    gCalibImuBiasData.calibBiasA[2] = gCalibImuBiasData.calibBiasA[2] - GRAVITY;
                }
                else
                {
                    gCalibImuBiasData.calibBiasA[2] = gCalibImuBiasData.calibBiasA[2] + GRAVITY;
                }
                gCalibImuBiasData.calibBiasG[0] = gCalibImuBiasData.gyroCalibMean[0]; //rad/s
                gCalibImuBiasData.calibBiasG[1] = gCalibImuBiasData.gyroCalibMean[1];
                gCalibImuBiasData.calibBiasG[2] = gCalibImuBiasData.gyroCalibMean[2];

                if (Cdd_Imu_CheckBiasParam())
                {
                    sucessFlag = true;
                    gCalibImuBiasData.calibBiasInited = false;
                }
                else
                {
                    Cdd_Imu_CalibImuBiasInit();
                    sucessFlag = false;
                }
               
            }
            else
            {
                Cdd_Imu_CalibImuBiasInit();
                sucessFlag = false;
            }
        }
    }
    
    return sucessFlag;
}

void Cdd_Imu_GetImuBiasParam(CalibImuBiasParam_ST* ImuBias)
{
    ImuBias->acclBias[0] = gCalibImuBiasData.calibBiasA[0]; //mg
    ImuBias->acclBias[1] = gCalibImuBiasData.calibBiasA[1];
    ImuBias->acclBias[2] = gCalibImuBiasData.calibBiasA[2];
    ImuBias->gyroBias[0] = gCalibImuBiasData.calibBiasG[0]; //deg/s
    ImuBias->gyroBias[1] = gCalibImuBiasData.calibBiasG[1];
    ImuBias->gyroBias[2] = gCalibImuBiasData.calibBiasG[2];
}


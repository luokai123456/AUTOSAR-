/*******************************************************************************
File Name:  Motor_HwIf.c
Author:
Date:
Version:    V1.0
File Description:
Copyright:
*******************************************************************************/

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "Motor_HwIf.h"
#include "Pwm3ph.h"
#include "RdcDrv.h"
#include "Motor_Diag.h"
#include "IoHwAbs_ADC.h"
#include "IoHwAbs_DIO.h"
#include "IoHwAbs_ADC_Prv.h"
#include "IoHwAbs_DIO_Prv.h"
#include "Adc3ph.h"

#pragma ghs section data =".foc_data"
#pragma ghs section text =".foc_code"
#pragma ghs section bss =".foc_bss"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
uint8 PwrOffDlyFlg_Mp = 0U;
Motor_InterFace Motor_InterFace_MT;
extern uint32 Motor_Adc3phTime;
extern uint32 Motor_Adc3phTime_Fusa;
extern uint16 Motor_Adc3phRaw_au16[3u];
extern uint16 Motor_Adc3phRaw_au16_Fusa[3u];
extern uint8  Motor_Adc3phRawStu_au8[3u];
extern uint8  Motor_Adc3phRawStu_au8_Fusa[3u];

extern int16 Motor_RdcDrvSinValue_s16_Fusa;
extern int16 Motor_RdcDrvCosValue_s16_Fusa;
extern int16 Motor_RdcDrvSinValue_s16;
extern int16 Motor_RdcDrvCosValue_s16;


#ifdef MOTORCTRL_TEST

void  Hal_SetAllSwitchesOff(void)
{
    Hal_PwmEnableSet(0U);
}


uint8 Hal_GetHwHsIntBSt(void)
{
    return (Motor_Get_U_HsFault() || Motor_Get_V_HsFault() || Motor_Get_W_HsFault());
}


uint8 Hal_GetHwLsIntBSt(void)
{
    return (Motor_Get_U_LsFault() || Motor_Get_V_LsFault() || Motor_Get_W_LsFault());
}

uint8_T Hal_GetBswInit(void)
{
    return 1; 
}

#else

#endif

/* Asw->Bsw */

/**
 * @brief 更新三相PWM占空比（输入为0~1之间）
 * @param dutyU U相占空比
 * @param dutyV V相占空比
 * @param dutyW W相占空比
 * @return 始终返回0
 */
void Hal_UpdatePwmDutyCycle(float dutyU, float dutyV, float dutyW)
{
    Pwm3ph_SetPwmDuty(dutyU * 0.01f, dutyV * 0.01f, dutyW * 0.01f);
}


void Hal_SetDriverCircuit(uint8 state)
{
    if (state == 0U)
    {
        SIUL.GPDO[197].B.PDO = 0;
        SIUL.GPDO[198].B.PDO = 0;	
        Hal_PwmEnableSet(0U);
    }
    else if (state == 1U)
    {
        SIUL.GPDO[197].B.PDO = 1;
        SIUL.GPDO[198].B.PDO = 1;
        Hal_PwmEnableSet(1U);
    }
    else
    {

    }
}

/**
 * @brief 配置主动短路模式
 * @param ascCmd 为1（上管短路），其它值无效
 * @return 0成功，1命令无效
 */
void Hal_ConfigActiveShortCircuit(uint8 ascCmd)
{
    if (ascCmd == 0U)
    {
        Pwm3ph_SetPwmState(&Dev1, Pwm3ph_State_Hasc);
    }
    else if(ascCmd == 1U)
    {
        Pwm3ph_SetPwmState(&Dev1, Pwm3ph_State_Lasc);
    }
    else
    {
        return; 
    }
}



void Hal_PwmEnableSet(uint8 enable)
{
    if (enable == 1U)
    {
        PwmOutEnable(1);
    }
    else
    {
        PwmOutEnable(0);
    }
}



/**
 * @brief 更新PWM频率
 * @param Freq 频率(Hz)，范围2000~100000
 * @return 0成功，1超范围
 */
void Hal_UpdatePwmFreqCycle(float Freq)
{
    uint32 Freq_uint = (uint32)Freq;

    if (Freq_uint < 2000U)
    {
        Freq_uint = 2000U;
    }
    else if (Freq_uint > 100000U)
    {
        Freq_uint = 100000U;
    }

    Pwm3ph_SetPwmFreq(Freq_uint);
}

/**
 * @brief 清除硬件故障
 * @param faultCmd TRUE时清除所有故障
 * @return 0成功，1命令无效
 */
void Hal_ClrHWFaultCycle(boolean faultCmd)
{
  if (faultCmd == TRUE)
    {
        Motor_Diag_ClearAllFaults();
    }
}

void Hal_SetPwrOffDlyFlg(boolean pwrOffDlyFlgCmd)
{
    if (pwrOffDlyFlgCmd == 0)
    {
        PwrOffDlyFlg_Mp = 1U;
    }
    else
    {
        PwrOffDlyFlg_Mp = 0U;
    }
}

/* Bsw->Asw */

uint16 Hal_ReadPhaseCurrentAdc1(void)
{
    return Motor_Adc3phRaw_au16[0];
}

uint16 Hal_ReadPhaseCurrentAdc1BkUp(void)
{
    return Motor_Adc3phRaw_au16_Fusa[0];
}

uint16 Hal_ReadPhaseCurrentAdc2(void)
{
    return Motor_Adc3phRaw_au16[1];
}

uint16 Hal_ReadPhaseCurrentAdc2BkUp(void)
{
    return Motor_Adc3phRaw_au16_Fusa[1];
}

uint16 Hal_ReadPhaseCurrentAdc3(void)
{
    return Motor_Adc3phRaw_au16[2];
}

uint16 Hal_ReadPhaseCurrentAdc3BkUp(void)
{
    return Motor_Adc3phRaw_au16_Fusa[2];
}

uint8 Hal_ReadPwmState(void)
{
	return Dev1.state;
}


uint16 Hal_ReadPhaseACurrentAD(void)
{
    return Motor_Adc3phRaw_au16_Fusa[0];
}


uint16 Hal_ReadPhaseBCurrentAD(void)
{
    return Motor_Adc3phRaw_au16_Fusa[1];
}


uint16 Hal_ReadPhaseCCurrentAD(void)
{
    return Motor_Adc3phRaw_au16_Fusa[2];
}

/**
 * @brief 读取电机温度ADC
 * @return 原始ADC值
 */
uint16 Hal_ReadMotorTempAdc(void)
{
    return Motor_InterFace_MT.Motor_MCU_AN_Motor_TEMP_P;
}

/**
 * @brief 读取电机温度ADC
 * @return 原始ADC值
 */
uint16 Hal_ReadMotorTempAdcBkUp(void)
{
    return Motor_InterFace_MT.Motor_MCU_AN_Motor_TEMP_N;
}

/**
 * @brief 读取直流母线电压ADC
 * @return 原始ADC值
 */
uint16 Hal_ReadDcBusVoltageAdc(void)
{
    uint16 raw_adc = Adc_DMAReadBufferptr_ARRY[HV_DC1_GROUP_INDEX][HV_DC1_CH_INDEX];
    return raw_adc;
}

/**
 * @brief 读取直流母线电压ADC
 * @return 原始ADC值
 */
uint16 Hal_ReadDcLinkVoltMeasAD(void)
{
    uint16 raw_adc = Adc_DMAReadBufferptr_ARRY[HV_DC2_GROUP_INDEX][HV_DC2_CH_INDEX];
    return raw_adc;
}

/**
 * @brief 读取开关管温度ADC1
 * @return 原始ADC值
 */
uint16 Hal_ReadSwitchTempAdc1(void)
{
    return Motor_InterFace_MT.Motor_MCU_AN_TEMP_IGBT_IN1;
}

/**
 * @brief 读取U相温度备份ADC
 * @return 原始ADC值
 */
uint16 Hal_ReadUTempAdcBkUp(void)
{
    return Motor_InterFace_MT.Motor_MCU_AN_TEMP_IGBT_IN1;
}

/**
 * @brief 读取开关管温度ADC2
 * @return 原始ADC值
 */
uint16 Hal_ReadSwitchTempAdc2(void)
{
    return Motor_InterFace_MT.Motor_MCU_AN_TEMP_IGBT_IN2;
}

/**
 * @brief 读取V相温度备份ADC
 * @return 原始ADC值
 */
uint16 Hal_ReadVTempAdcBkUp(void)
{
    return Motor_InterFace_MT.Motor_MCU_AN_TEMP_IGBT_IN2;
}

/**
 * @brief 读取开关管温度ADC3
 * @return 原始ADC值
 */
uint16 Hal_ReadSwitchTempAdc3(void)
{
    return Motor_InterFace_MT.Motor_MCU_AN_TEMP_IGBT_IN3;
}

/**
 * @brief 读取W相温度备份ADC
 * @return 原始ADC值
 */
uint16 Hal_ReadWTempAdcBkUp(void)
{
    return Motor_InterFace_MT.Motor_MCU_AN_TEMP_IGBT_IN3;
}

/**
 * @brief 读取KL15-电压ADC（KEY_Mic）
 * @return 原始ADC值
 */
uint16 Hal_ReadIgnitionVoltageAdc(void)
{
    return Motor_InterFace_MT.Motor_AN_KEY_Mic;
}

/**
 * @brief 读取KL30-电压ADC（UBD_Mic）
 * @return 原始ADC值
 */
uint16 Hal_ReadBatteryVoltageAdc(void)
{
    return Motor_InterFace_MT.Motor_AN_UBD_Mic;
}

/**
 * @brief 获取硬件过压状态（过压1）
 * @return 过压标志
 */
uint8 Hal_GetHwOvervoltSt(void)
{
    return Motor_Get_OverVoltage1();
}

/**
 * @brief 获取硬件过压状态（过压2）
 * @return 过压标志
 */
uint8 Hal_GetHwOvervoltSt1(void)
{
    return Motor_Get_OverVoltage2();
}

/**
 * @brief 获取U相硬件过流状态
 * @return 过流标志
 */
uint8 Hal_GetHwOvercurSt(void)
{
    return Motor_Get_U_OverCurrent();
}

/**
 * @brief 获取V相硬件过流状态
 * @return 过流标志
 */
uint8 Hal_GetHwOvercurSt1(void)
{
    return Motor_Get_V_OverCurrent();
}

/**
 * @brief 获取W相硬件过流状态
 * @return 过流标志
 */
uint8 Hal_GetHwOvercurSt2(void)
{
    return Motor_Get_W_OverCurrent();
}

/**
 * @brief 读取U相上桥驱动故障
 * @return 故障值
 */
uint16 Hal_ReadUHDriFault(void)
{
    return (uint16)Motor_Get_U_HsFault();
}

/**
 * @brief 读取U相下桥驱动故障
 * @return 故障值
 */
uint16 Hal_ReadULDriFault(void)
{
    return (uint16)Motor_Get_U_LsFault();
}

/**
 * @brief 读取V相上桥驱动故障
 * @return 故障值
 */
uint16 Hal_ReadVHDriFault(void)
{
    return (uint16)Motor_Get_V_HsFault();
}

/**
 * @brief 读取V相下桥驱动故障
 * @return 故障值
 */
uint16 Hal_ReadVLDriFault(void)
{
    return (uint16)Motor_Get_V_LsFault();
}

/**
 * @brief 读取W相上桥驱动故障
 * @return 故障值
 */
uint16 Hal_ReadWHDriFault(void)
{
    return (uint16)Motor_Get_W_HsFault();
}

/**
 * @brief 读取W相下桥驱动故障
 * @return 故障值
 */
uint16 Hal_ReadWLDriFault(void)
{
    return (uint16)Motor_Get_W_LsFault();
}

/**
 * @brief 读取上管退饱和故障
 * @return 故障值
 */
uint16_T  Hal_ReadHDriDeSatFault(void)//有故障返回1
{
    return (uint16_T)Motor_Get_TOPDesatFlt(); 
}


/**
 * @brief 读取下管退饱和故障
 * @return 故障值
 */
uint16_T  Hal_ReadLDriDeSatFault(void)
{
    return (uint16_T)Motor_Get_BOTDesatFlt(); 
}

/**
 * @brief 读取上管欠压故障
 * @return 故障值
 */
uint16_T  Hal_ReadHDirUVFault(void)
{
    return (uint16_T)Motor_Get_TOP_UV(); 
}

/**
 * @brief 读取下管欠压故障
 * @return 故障值
 */
uint16_T  Hal_ReadLDriUVFault(void)
{
    return (uint16_T)Motor_Get_BOT_UV(); 
}

uint16 Hal_ReadPowerChipVoltageAdc(void)
{
    uint16 RawResult = 0;
    (void)IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_AN_Driver_5V, &RawResult);
    return RawResult;
}


uint16 Hal_ReadPwrChipVolt(void)
{
    uint16 RawResult = 0;
    (void)IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_AN_Driver_5V, &RawResult);
    return RawResult;
}
////////

int16 Hal_ReadResolverSineRaw(void)
{
    return Motor_RdcDrvSinValue_s16;
}

int16 Hal_ReadResolverCosineRaw(void)
{
    return Motor_RdcDrvCosValue_s16;
}

int16 Hal_ReadResolverSineRawBkUp(void)
{
    return Motor_RdcDrvSinValue_s16_Fusa;
}

int16 Hal_ReadResolverCosineRawBkUp(void)
{
    return Motor_RdcDrvCosValue_s16_Fusa;
}

// int16 Hal_ReadResolverSineRawFB(void)
// {
//     return 0;
// }
// int16 Hal_ReadResolverCosineRawFB(void)
// {
//     return 0;
// }
int16 Hal_ReadSinPosiHigh(void)
{
    return RdcDrv_SampleData.SinpPeak_u16;
}
int16 Hal_ReadSinPosiLow(void)
{
    return RdcDrv_SampleData.SinpValley_u16;
}
int16 Hal_ReadSinNegHigh(void)
{
    return RdcDrv_SampleData.SinnPeak_u16;
}
int16 Hal_ReadSinNegLow(void)
{
    return RdcDrv_SampleData.SinnValley_u16;
}
int16 Hal_ReadCosPosiHigh(void)
{
    return RdcDrv_SampleData.CospPeak_u16;
}
int16 Hal_ReadCosPosiLow(void)
{
    return RdcDrv_SampleData.CospValley_u16;
}
int16 Hal_ReadCosNegHigh(void)
{
    return RdcDrv_SampleData.CosnPeak_u16;
}

int16 Hal_ReadCosNegLow(void)
{
    return RdcDrv_SampleData.CosnValley_u16;
}
int16 Hal_ReadExcPosiHigh(void)
{
    return RdcDrv_SampleData.ExcpPeak_u16;//Ng
}
int16 Hal_ReadExcPosiLow(void)
{
    return RdcDrv_SampleData.ExcpValley_u16;//NF
}
int16 Hal_ReadExcNegHigh(void)
{
    return RdcDrv_SampleData.ExcnPeak_u16;//pg
}
int16 Hal_ReadExcNegLow(void)
{
    return RdcDrv_SampleData.ExcnValley_u16;//PF
}

float Hal_GetSwitchPeriod(void)
{
    if (g_PwmConfig.current_freq == 0) {
        return 0.0f;
    }
    return 1.0f / (float)g_PwmConfig.current_freq;
}


uint32 Hal_ReadCurrentTimestamp(void)
{
    uint32 timestamp = 0; 
    timestamp = Motor_Adc3phTime;
    return timestamp;
}


uint32 Hal_ReadResolverTimestamp(void)
{
    return Motor_ResolverTimestamp_au32;
}


float Hal_GetSwitchFrequency(void)
{
    float current_freq_tmp;
    current_freq_tmp = (float)g_PwmConfig.current_freq;
    return current_freq_tmp;
}

uint16 Hal_ReadUPhaZeroPointAD(void)
{
    return Motor_ZeroDriftOffset_au16[0];
}

uint16 Hal_ReadWPhaZeroPointAD(void)
{
    return Motor_ZeroDriftOffset_au16[2];
}


uint16 Hal_ReadPhaseCurrentAdc1ZeroPointBkUp(void)
{
    return Motor_ZeroDriftOffset_au16_Fusa[0];
}

uint16 Hal_ReadPhaseCurrentAdc3ZeroPointBkUp(void)
{
    return Motor_ZeroDriftOffset_au16_Fusa[2];
}

void Motor_ADC_MainFunction(void)
{
    IoHwAbs_ADC_GetChannelOriginalRegValue(IOHWABS_ADC_CHANNEL_AN_UBD_Mic, &Motor_InterFace_MT.Motor_AN_UBD_Mic);
    IoHwAbs_ADC_GetChannelOriginalRegValue(IOHWABS_ADC_CHANNEL_AN_KEY_Mic, &Motor_InterFace_MT.Motor_AN_KEY_Mic);
    IoHwAbs_ADC_GetChannelOriginalRegValue(IOHWABS_ADC_CHANNEL_MCU_AN_TEMP_IGBT_IN3, &Motor_InterFace_MT.Motor_MCU_AN_TEMP_IGBT_IN3);
    IoHwAbs_ADC_GetChannelOriginalRegValue(IOHWABS_ADC_CHANNEL_MCU_AN_TEMP_IGBT_IN2, &Motor_InterFace_MT.Motor_MCU_AN_TEMP_IGBT_IN2);
    IoHwAbs_ADC_GetChannelOriginalRegValue(IOHWABS_ADC_CHANNEL_MCU_AN_TEMP_IGBT_IN1, &Motor_InterFace_MT.Motor_MCU_AN_TEMP_IGBT_IN1);
    IoHwAbs_ADC_GetChannelOriginalRegValue(IOHWABS_ADC_CHANNEL_MCU_AN_Motor_TEMP_P, &Motor_InterFace_MT.Motor_MCU_AN_Motor_TEMP_P);
    IoHwAbs_ADC_GetChannelOriginalRegValue(IOHWABS_ADC_CHANNEL_MCU_AN_Motor_TEMP_N, &Motor_InterFace_MT.Motor_MCU_AN_Motor_TEMP_N);
}

void Motor_ADC_HV_DC_Read(void)
{
    IoHwAbs_ADC_GetChannelOriginalRegValue(IOHWABS_ADC_CHANNEL_MCU_AN_HV_DC2, &Motor_InterFace_MT.Motor_MCU_AN_HV_DC2);
    IoHwAbs_ADC_GetChannelOriginalRegValue(IOHWABS_ADC_CHANNEL_MCU_AN_HV_DC1, &Motor_InterFace_MT.Motor_MCU_AN_HV_DC1);
}

#pragma ghs section
#pragma ghs section
#pragma ghs section

uint16 Hal_Get_VDD5REF_Ch5_mv(void)
{
    return (uint16)(((uint32)VDD5REF_AN1[0] * ADC_REF_MV) / ADC_MAX_VALUE);
}

uint16 Hal_Get_VDD5REF_Ch1_mv(void)
{
    return (uint16)(((uint32)VDD5REF_AN1[1] * ADC_REF_MV) / ADC_MAX_VALUE);
}

uint16 Hal_Get_VDD5REF_Ch4_mv(void)
{
    return (uint16)(((uint32)VDD5REF_AN1[2] * ADC_REF_MV) / ADC_MAX_VALUE);
}

uint16 Hal_Get_VDD5REF_Ch3_mv(void)
{
    return (uint16)(((uint32)VDD5REF_AN0[0] * ADC_REF_MV) / ADC_MAX_VALUE);
}

uint16 Hal_Get_VDD5REF_Ch6_mv(void)
{
    return (uint16)(((uint32)VDD5REF_AN0[1] * ADC_REF_MV) / ADC_MAX_VALUE);
}

uint16 Hal_Get_VDD5REF_Ch2_mv(void)
{
    return (uint16)(((uint32)VDD5REF_AN0[2] * ADC_REF_MV) / ADC_MAX_VALUE);
}
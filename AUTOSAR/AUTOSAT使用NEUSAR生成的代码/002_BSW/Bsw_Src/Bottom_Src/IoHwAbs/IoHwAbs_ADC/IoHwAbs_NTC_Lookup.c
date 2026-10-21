/*** create info ***********************
 *@ filename : IoHwAbs_NTC_Lookup.c​
*@ Author : wangke 
*@ date :2025-10-30
*@ Description :描述本文件实现功能
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : wangke 
*@ date :2025-10-30
*@ Modification Description :
初始版本
****************************************/
/******************** Include ********************/
#include "IoHwAbs_NTC_Lookup.h"
#include "IoHwAbs_Adc.h"


/****************** Global Variable ****************/


float NTC_valResistance_kohm_Mp[5] = {0.0f};



const float32 NTC_t_map[166] = {
    -40.0f, -39.0f, -38.0f, -37.0f, -36.0f, -35.0f, -34.0f, -33.0f, -32.0f, -31.0f,
    -30.0f, -29.0f, -28.0f, -27.0f, -26.0f, -25.0f, -24.0f, -23.0f, -22.0f, -21.0f,
    -20.0f, -19.0f, -18.0f, -17.0f, -16.0f, -15.0f, -14.0f, -13.0f, -12.0f, -11.0f,
    -10.0f,  -9.0f,  -8.0f,  -7.0f,  -6.0f,  -5.0f,  -4.0f,  -3.0f,  -2.0f,  -1.0f,
      0.0f,   1.0f,   2.0f,   3.0f,   4.0f,   5.0f,   6.0f,   7.0f,   8.0f,   9.0f,
     10.0f,  11.0f,  12.0f,  13.0f,  14.0f,  15.0f,  16.0f,  17.0f,  18.0f,  19.0f,
     20.0f,  21.0f,  22.0f,  23.0f,  24.0f,  25.0f,  26.0f,  27.0f,  28.0f,  29.0f,
     30.0f,  31.0f,  32.0f,  33.0f,  34.0f,  35.0f,  36.0f,  37.0f,  38.0f,  39.0f,
     40.0f,  41.0f,  42.0f,  43.0f,  44.0f,  45.0f,  46.0f,  47.0f,  48.0f,  49.0f,
     50.0f,  51.0f,  52.0f,  53.0f,  54.0f,  55.0f,  56.0f,  57.0f,  58.0f,  59.0f,
     60.0f,  61.0f,  62.0f,  63.0f,  64.0f,  65.0f,  66.0f,  67.0f,  68.0f,  69.0f,
     70.0f,  71.0f,  72.0f,  73.0f,  74.0f,  75.0f,  76.0f,  77.0f,  78.0f,  79.0f,
     80.0f,  81.0f,  82.0f,  83.0f,  84.0f,  85.0f,  86.0f,  87.0f,  88.0f,  89.0f,
     90.0f,  91.0f,  92.0f,  93.0f,  94.0f,  95.0f,  96.0f,  97.0f,  98.0f,  99.0f,
    100.0f, 101.0f, 102.0f, 103.0f, 104.0f, 105.0f, 106.0f, 107.0f, 108.0f, 109.0f,
    110.0f, 111.0f, 112.0f, 113.0f, 114.0f, 115.0f, 116.0f, 117.0f, 118.0f, 119.0f,
    120.0f, 121.0f, 122.0f, 123.0f, 124.0f, 125.0f
};

/* 电阻数组 r_map: 对应温度的中心电阻值 R_Cent (Kohm) */
const float32 NTC_r_map[166] = {
    /* -40℃ 到 -1℃ */
    197.390f, 186.540f, 176.350f, 166.800f, 157.820f, 149.390f, 141.510f, 134.090f, 127.110f, 120.530f,
    114.340f, 108.530f, 103.040f,  97.870f,  92.989f,  88.381f,  84.036f,  79.931f,  76.052f,  72.384f,
     68.915f,  65.634f,  62.529f,  59.589f,  56.804f,  54.166f,  51.665f,  49.294f,  47.046f,  44.913f,
     42.889f,  40.967f,  39.142f,  37.408f,  35.761f,  34.196f,  32.707f,  31.291f,  29.945f,  28.664f,
    
    /* 0℃ 到 39℃ */
     27.445f,  26.283f,  25.177f,  24.124f,  23.121f,  22.165f,  21.253f,  20.384f,  19.555f,  18.764f,
     18.010f,  17.290f,  16.602f,  15.946f,  15.319f,  14.720f,  14.148f,  13.601f,  13.078f,  12.578f,
     12.099f,  11.642f,  11.204f,  10.785f,  10.384f,  10.000f,   9.632f,   9.280f,   8.943f,   8.619f,
      8.309f,   8.012f,   7.727f,   7.453f,   7.191f,   6.939f,   6.698f,   6.466f,   6.243f,   6.029f,
    
    /* 40℃ 到 79℃ */
      5.824f,   5.627f,   5.437f,   5.255f,   5.080f,   4.911f,   4.749f,   4.593f,   4.443f,   4.299f,
      4.160f,   4.027f,   3.898f,   3.774f,   3.654f,   3.539f,   3.429f,   3.322f,   3.219f,   3.119f,
      3.024f,   2.931f,   2.842f,   2.756f,   2.673f,   2.593f,   2.516f,   2.441f,   2.369f,   2.300f,
      2.233f,   2.168f,   2.105f,   2.044f,   1.986f,   1.929f,   1.874f,   1.821f,   1.770f,   1.720f,
    
    /* 80℃ 到 119℃ */
      1.673f,   1.626f,   1.581f,   1.538f,   1.496f,   1.455f,   1.416f,   1.377f,   1.340f,   1.304f,
      1.270f,   1.236f,   1.204f,   1.172f,   1.141f,   1.112f,   1.083f,   1.055f,   1.028f,   1.002f,
      0.976f,   0.951f,   0.927f,   0.904f,   0.882f,   0.860f,   0.838f,   0.818f,   0.798f,   0.778f,
      0.759f,   0.741f,   0.723f,   0.706f,   0.689f,   0.673f,   0.657f,   0.641f,   0.626f,   0.612f,
    
    /* 120℃ 到 125℃ */
      0.598f,   0.584f,   0.570f,   0.557f,   0.545f,   0.532f
};


/* 函数名称: NTC_GetTemperature
 * 参数In: r0: 输入的电阻值 (单位: Kohm)
 *        r_map: 电阻值数组 (使用图片表格中的 R_Cent 列数据，单位: Kohm)
 *        t_map: 温度值数组 (使用图片表格中的 Temp. 列数据，单位: ℃)
 *        n: 数组长度
 * 返回值: 对应的温度值 (单位: ℃)
 * 描述: 使用二分查找的一维查表函数，基于电阻值查找温度，支持线性插值
 *       注意：电阻值数组是单调递减的（温度升高电阻降低）
 */
static float32 NTC_GetTemperature(float32 r0, const float32 *r_map, const float32 *t_map, uint16 n)
{
    uint8 fgGotoEnd_LO = FALSE;
    uint16 low = 0;
    uint16 high = n - 1;
    uint16 j = 0;
    float32 valRecValue_LO = 0.0f;
    
    /* 边界情况检查 */
    if (n == 0)
    {
        fgGotoEnd_LO = TRUE;
        valRecValue_LO = 0.0f;
    }
    
    /* 注意：电阻数组是单调递减的，所以边界判断要反过来 */
    if (r0 >= r_map[0])  // 电阻值大于等于最大值，对应最低温度(-40℃)
    {
        fgGotoEnd_LO = TRUE;
        valRecValue_LO = t_map[0];
    }
    
    if (r0 <= r_map[n-1])  // 电阻值小于等于最小值，对应最高温度(125℃)
    {
        fgGotoEnd_LO = TRUE;
        valRecValue_LO = t_map[n-1];
    }
    
    if (FALSE == fgGotoEnd_LO)
    {
        /* 二分查找定位区间 */
        while (low <= high) {
            j = (low + high) >> 1;
            if (r_map[j] > r0) {  // 注意：因为电阻数组是递减的，所以比较符号要反过来
                low = j + 1;
            } else {
                high = j - 1;
            }
        }
        j = high;

        /* 处理边界情况并计算插值 */
        const float32 dr = r_map[j] - r_map[j+1];  // 电阻差值
        if (dr <= 0.0f) 
        {       
            fgGotoEnd_LO = TRUE;
            valRecValue_LO = t_map[j]; // 防止除以零或无效区间
        }
        if (FALSE == fgGotoEnd_LO)
        {
            const float32 ratio = (r0 - r_map[j+1]) / dr;  // 计算插值比例
            valRecValue_LO = t_map[j+1] + ratio * (t_map[j] - t_map[j+1]);
        }
    }

    return valRecValue_LO;
}

/**
 * 函数名称: IoHwAbs_ADC_GetNTCThermisorValue
 * 参数In: Channel 三个温度通道
 * 参数Out: Resultvalue - 存储的热敏电阻阻值
 * 返回值: Std_ReturnType - 是否成功
 * 描述: 获取热敏电阻阻值
 */
static Std_ReturnType IoHwAbs_ADC_GetNTCThermisorValue(uint8 Channel,float *Resultvalue)
{
	Std_ReturnType Adc_retVal_LO = E_NOT_OK;
	float Adc_CollectVal_LO = 0;
    float Adc_ValConvert_LO = 0;
	uint16 Adc_AdcGetResultTemp_LO = 0;
    Std_ReturnType getResultRet = E_NOT_OK;
    
    switch(Channel)
    {
        case SYS_NTCThermisor_MCU://BLDC2
                getResultRet = IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_Temp_MCU, &Adc_AdcGetResultTemp_LO);
                break;
        case SYS_NTCThermisor_SBC://BLDC1
                getResultRet = IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_Temp_SBC, &Adc_AdcGetResultTemp_LO);
                break;
        default:
            Adc_retVal_LO = E_NOT_OK;
            break;
    }
    
    if (getResultRet == E_OK)
    {

        Adc_ValConvert_LO = (float)Adc_AdcGetResultTemp_LO /1000.0f; //转换为伏特值 
        *Resultvalue = (10.0f * Adc_ValConvert_LO)/(5.0f - Adc_ValConvert_LO);

        Adc_retVal_LO = E_OK;
    }

	return Adc_retVal_LO;
}

Std_ReturnType Sys_GetNTCTempureValue(uint8 Channel,float *Resultvalue)
{
    Std_ReturnType Adc_retVal_LO = E_NOT_OK;
    float resistance;

    Adc_retVal_LO = IoHwAbs_ADC_GetNTCThermisorValue(Channel, &resistance);
    if (Adc_retVal_LO == E_OK)
    {
        switch(Channel)
        {
            case SYS_NTCThermisor_MCU:
                *Resultvalue = NTC_GetTemperature(resistance, (const float32*)NTC_r_map, (const float32*)NTC_t_map, sizeof(NTC_r_map)/sizeof(NTC_r_map[0]));
                break;
            case SYS_NTCThermisor_SBC:
                *Resultvalue = NTC_GetTemperature(resistance, (const float32*)NTC_r_map, (const float32*)NTC_t_map, sizeof(NTC_r_map)/sizeof(NTC_r_map[0]));
                break;
            default:
                Adc_retVal_LO = E_NOT_OK;
                break;
        }
    }

    return Adc_retVal_LO;
}

/******************* Function ********************/



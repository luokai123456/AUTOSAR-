/*** create info *******************************************
*@ filename : IoHwAbs_ADC_Filter.c
*@ Author : pianyongxin 
*@ date :2025-02-12
*@ Description :ADC滤波文件
/*** modify info ******************************************* 
*@ version :0.0
*@ Modifier : pianyongxin 
*@ date :2025-02-12
*@ Modification Description :
初始版本
************************************************************/

/********************************************** Include **********************************************/
#include "typedefs.h"
#include "IoHwAbs_ADC_Filter.h"
#include "StandardTypes.h"
#include "IoHwAbs_ADC.h"
#include "IoHwAbs_ADC_cfg.h"
#include "IoHwAbs_ADC_Filter.h"
#include "common.h"
/******************************************* Global Varibles ******************************************/
uint16 Adc_valFilterResult_ARRY[IOHWABS_ADC_CHANNEL_NUM] = {0};
uint16 Adc_valFilterResultTemp_ARRY[IOHWABS_ADC_CHANNEL_NUM] = {0};
uint16 Adc_valFilterMatirix_ARRY[IOHWABS_ADC_FILTER_MATIRIX_X][IOHWABS_ADC_FILTER_MATIRIX_Y] = {{0}};
uint16 Adc_valCycTaskCnt_mp = 0;
/********************************************* Function *********************************************/
/**
 * 函数名称: IoHwAbs_ADC_ReFileterValue
 * 参数in: args
 * 参数out: args
 * 返回值: return
 * 描述: ADC滤波函数
 */
void IoHwAbs_ADC_ReFileterValue(void)
{
    uint8 Adc_X_num             = ADC_VAL_ZERO;
    uint8 Adc_Y_num             = ADC_VAL_ZERO;
    static uint8 Get_Adcval_num = ADC_VAL_ZERO;
    uint16 Adc_valMaxAdc_LO      = ADC_VAL_ZERO;
    uint16 Adc_valMinAdc_LO      = ADC_VAL_ZERO;
    uint16 Adc_valResultAdc_LO   = ADC_VAL_ZERO;
    uint32 Adc_valTotalAdc_LO    = ADC_VAL_ZERO;
    uint16 Origin_adc_raw_value;

    for (uint8 ChannelID_i = 0; ChannelID_i < IOHWABS_ADC_CHANNEL_NUM; ChannelID_i++)
    {

        if (IS_ORIGINAL_VALUE_CHANNEL(ChannelID_i))
        {
            IoHwAbs_ADC_GetChannelOriginalRegValue(ChannelID_i, &Origin_adc_raw_value);
            Adc_valFilterResultTemp_ARRY[ChannelID_i] = Origin_adc_raw_value;
        }
        else
        {
    	    IoHwAbs_ADC_GetChannelRawValue(ChannelID_i, &Adc_valFilterResultTemp_ARRY[ChannelID_i]);
        }
        
        Adc_valFilterMatirix_ARRY[Get_Adcval_num][ChannelID_i] = Adc_valFilterResultTemp_ARRY[ChannelID_i];
    }

    if (Get_Adcval_num < (IOHWABS_ADC_FILTER_MATIRIX_X - 1))
    {
        Get_Adcval_num++;
    }
    else
    {
        Get_Adcval_num = 0;
    }

    if(Adc_valCycTaskCnt_mp < 5)
    {
        Adc_valCycTaskCnt_mp++;
        cc_memcpy(Adc_valFilterResult_ARRY, Adc_valFilterResultTemp_ARRY, sizeof(Adc_valFilterResult_ARRY));
    }
    else
    {
        for (Adc_Y_num = 0; Adc_Y_num < IOHWABS_ADC_FILTER_MATIRIX_Y; Adc_Y_num++)
        {
            Adc_valTotalAdc_LO  = 0;
            Adc_valMaxAdc_LO    = 0;
            Adc_valMinAdc_LO    = 0xFFFF;

            for (Adc_X_num = 0; Adc_X_num < IOHWABS_ADC_FILTER_MATIRIX_X; Adc_X_num++)
            {
                Adc_valResultAdc_LO = Adc_valFilterMatirix_ARRY[Adc_X_num][Adc_Y_num];
                Adc_valTotalAdc_LO = Adc_valTotalAdc_LO + Adc_valResultAdc_LO;
                if (Adc_valMaxAdc_LO < Adc_valResultAdc_LO)
                {
                    Adc_valMaxAdc_LO = Adc_valResultAdc_LO;
                }
                if (Adc_valMinAdc_LO > Adc_valResultAdc_LO)
                {
                    Adc_valMinAdc_LO = Adc_valResultAdc_LO;
                }
            }
            Adc_valResultAdc_LO = (Adc_valTotalAdc_LO - Adc_valMaxAdc_LO - Adc_valMinAdc_LO) / 3.0;
            Adc_valFilterResult_ARRY[Adc_Y_num] = (uint16)Adc_valResultAdc_LO;
        }
    }



}

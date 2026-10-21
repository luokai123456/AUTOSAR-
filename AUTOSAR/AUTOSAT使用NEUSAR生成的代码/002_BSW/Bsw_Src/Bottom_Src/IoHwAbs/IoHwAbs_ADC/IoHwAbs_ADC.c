/*** Create Info *******************************************
* @file    : IoHwAbs_ADC.c
* @author  : pianyongxin
* @date    : 2025-02-12
* @brief   : ADC Hardware Abstraction Layer Implementation
/*** Modify Info *******************************************
* @version : 0.0
* @modifier: pianyongxin
* @date    : 2025-02-12
* @brief   : Initial version
************************************************************/

/********************************************** Include **********************************************/
#include "typedefs.h"
#include "IoHwAbs_ADC.h"
#include "IoHwAbs_ADC_Prv.h"
#include "IoHwAbs_ADC_Cfg.h"
#include "IoHwAbs_ADC_Filter.h"
#include "eDma_LLDriver.h"
#include "CCFC3012PT.h"
#include "Motor_HwIf.h"
/********************************************** Init **********************************************/
Std_ReturnType IoHwAbs_ADC_GroupConversion(uint8 GroupIdx);
static uint8 Adc_GroupTimeout[ADC_CONFIG_GROUPS] = {0};
P2CONST(Adc_ConfigType, ADC_CONST, ADC_APPL_CONST)
Adc_valConfigptr_STR = &Adc_Config;
/******************************************** Init End ********************************************/
/**
 * 函数名称: IoHwAbs_ADC_HardTrigerInit
 * 参数in: 通道Id
 * 参数out: args
 * 返回值: return
 * 描述: 初始化硬件触发
 */
void IoHwAbs_ADC_HardTrigerInit(uint8_t channel)
{
    eMIOS_LLD_InitGlobalParam(0, &eMIOS_GlobalConfig_STR);
    switch (channel)
    {
        case 16:
            (void)eMIOS_LLD_PWM_Init(0, channel, &eMIOS_PWM_OPWFMB_ChanConfig_STR);
            break;
        case 17:
            (void)eMIOS_LLD_PWM_Init(0, channel, &eMIOS_PWM_OPWFMB_CH17_ChanConfig);
            break;
        case 18:
            (void)eMIOS_LLD_PWM_Init(0, channel, &eMIOS_PWM_OPWFMB_CH18_ChanConfig);
            break;
        case 19:
            (void)eMIOS_LLD_PWM_Init(0, channel, &eMIOS_PWM_OPWFMB_CH19_ChanConfig);
            break;
        case 20:
            (void)eMIOS_LLD_PWM_Init(0, channel, &eMIOS_PWM_OPWFMB_CH20_ChanConfig);
            break;
        case 21:
            (void)eMIOS_LLD_PWM_Init(0, channel, &eMIOS_PWM_OPWFMB_CH21_ChanConfig);
            break;
        default:
            break;
    }
    
    eMIOS_LLD_SetEnDisGlobal(0, TRUE);
}

/********************************************* Function *********************************************/
/**
 * @brief  Initialize ADC hardware abstraction layer
 * @param  None
 * @return None
 * @note   Sets up ADC configuration and enables hardware triggers
 */
volatile uint8_t chan = 16;
void IoHwAbs_ADC_Init(void)
{
    uint8 GroupxIndex_i;
    Adc_Init(&Adc_Config);
    for (chan = 16; chan <= 21; chan++)
    {
	    IoHwAbs_ADC_HardTrigerInit(chan);
    }
    for (GroupxIndex_i = 0; GroupxIndex_i < ADC_CONFIG_GROUPS; GroupxIndex_i++)
    {
        if(GroupxIndex_i == 1|| GroupxIndex_i == 3||GroupxIndex_i == 5||GroupxIndex_i == 6||GroupxIndex_i == 8|| GroupxIndex_i == 13)
        {
        }
        else if(GroupxIndex_i == 21 || GroupxIndex_i == 22 || GroupxIndex_i == 24 || GroupxIndex_i == 25)
        {
            Adc_SetupResultBuffer(GroupxIndex_i, Adc_ResultBufferptr_ARRY[GroupxIndex_i]);
        }
        else
        {
            Adc_SetupResultBuffer(GroupxIndex_i, Adc_ResultBufferptr_ARRY[GroupxIndex_i]);
            Adc_EnableHardwareTrigger(GroupxIndex_i);
        }
        
    }

}

/**
 * @brief  Main processing function for ADC module
 * @param  None
 * @return None
 * @note   Handles group conversions for all configured ADC groups
 */
void IoHwAbs_ADC_MainFunction(void)
{
    uint8 GroupxIndex_i;

    for (GroupxIndex_i = 0; GroupxIndex_i < ADC_CONFIG_GROUPS; GroupxIndex_i++)
    {
        IoHwAbs_ADC_GroupConversion(GroupxIndex_i);
    }
    

}

/**
 * @brief  Execute ADC group conversion
 * @param  GroupIdx - Group index to convert
 * @return E_OK if successful, E_NOT_OK otherwise
 */
Std_ReturnType IoHwAbs_ADC_GroupConversion(uint8 GroupIdx)
{
    Std_ReturnType RetVal_LO = E_NOT_OK;
    uint16 Adc_ChanCntLoop_LO = 0;
#if (SWTRIG_ENABLE_USE == STD_ON)
    uint8 Groupx_SwTrigg_ChanCount = 0;
    if (Adc_valConfigptr_STR->Adc_GroupConfig[GroupIdx].SwOrHw == ADC_TRIGG_SRC_SW)
    {
        Adc_StartGroupConversion(GroupIdx);
        Adc_GroupTimeout[GroupIdx] = 0;
        while (Adc_GetGroupStatus(GroupIdx) != ADC_STREAM_COMPLETED)
        {
            Adc_StartGroupConversion(GroupIdx);

            while (Groupx_SwTrigg_ChanCount <= Adc_valConfigptr_STR->Adc_GroupConfig[GroupIdx].ChannelCount)
            {
                Adc_MainFunction();
                Groupx_SwTrigg_ChanCount++;
            }
        }
        if (((Adc_GetGroupStatus(GroupIdx)) == ADC_COMPLETED) || ((Adc_GetGroupStatus(GroupIdx)) == ADC_STREAM_COMPLETED))
        {
            Adc_ReadGroup(GroupIdx, Adc_DMAReadBufferptr_ARRY[GroupIdx]);
            RetVal_LO = E_OK;
        }
    }
#elif (HWTRIG_ENABLE_USE == STD_ON)
#if (SWTRIG_ENABLE_USE == STD_ON)
    else if ((Adc_valConfigptr_STR->Adc_GroupConfig[GroupIdx].SwOrHw == ADC_TRIGG_SRC_HW))
#endif
    {
        if((GroupIdx == ADC_GROUP_AdcGroup_21) ||
           (GroupIdx == ADC_GROUP_AdcGroup_22) ||
           (GroupIdx == ADC_GROUP_AdcGroup_24) ||
           (GroupIdx == ADC_GROUP_AdcGroup_25))
        {
            if (Adc_GetGroupStatus(GroupIdx) == ADC_IDLE)
            {
                Adc_StartGroupConversion(GroupIdx);
            }
            while (Adc_GetGroupStatus(GroupIdx) != ADC_STREAM_COMPLETED)
            {
                Adc_MainFunction();
                Adc_GroupTimeout[GroupIdx]++;
                if(Adc_GroupTimeout[GroupIdx] > IoHwAbs_ADC_GroupTimeout)
                {
                    Adc_StopGroupConversion(GroupIdx);
                    RetVal_LO = E_NOT_OK;
                    break;
                }
            }

            Adc_ReadGroup(GroupIdx, Adc_DMAReadBufferptr_ARRY[GroupIdx]);
            Adc_GroupTimeout[GroupIdx] = 0;
        }
        else
        {
            Adc_ReadGroup(GroupIdx, Adc_DMAReadBufferptr_ARRY[GroupIdx]);
        }

        RetVal_LO = E_OK;
    }
#endif
    return RetVal_LO;
}

/**
 * @brief  Search and validate ADC input channel
 * @param  ChIdx - Channel index to search
 * @return Valid channel index or IoHwAbs_ADC_Invalid_Value if not found
 */
uint16 IoHwAbs_ADC_Search_Input_Channel_Check(uint16 ChIdx)
{
    uint16 Channel_i;
    uint16 ChIndex_LO;

    ChIndex_LO = IoHwAbs_ADC_Invalid_Value;
    for (Channel_i = 0; Channel_i < IOHWABS_ADC_CHANNEL_NUM; Channel_i++)
    {
        if (ChIdx == Adc_CfgParams_STR[Channel_i].valChannellId)
        {
            ChIndex_LO = Channel_i;
            break;
        }
    }
    return ChIndex_LO;
}

/**
 * @brief  Get raw ADC value for specified channel
 * @param  ChIdx - Channel index
 * @param  RawResult - Pointer to store raw ADC value
 * @return E_OK if successful, E_NOT_OK if channel invalid
 */
Std_ReturnType IoHwAbs_ADC_GetChannelRawValue(uint16 ChIdx, uint16 *RawResult)
{
    Std_ReturnType RetVal_LO = E_OK;
    float Adc_Formula_LO;
    uint16 Adc_Result_LO = 0, Adc_GroupIdx_LO = 0, Adc_ChannleIdx_LO = 0;
    VAR(Adc_StreamNumSampleType, ADC_VAR)
    Adc_StreamNumSamp_LO = 0;
    uint16 Adc_ChIndex_LO = 0;

    switch (ChIdx)
    {
        case IOHWABS_ADC_CHANNEL_VDD5REF5:
            *RawResult = IoHwAbs_ADC_Convert12BitRaw2Mv(VDD5REF_AN1[0]); /* Group 6, VDD5REF5 */
            return E_OK;

        case IOHWABS_ADC_CHANNEL_VDD5REF1:
            *RawResult = IoHwAbs_ADC_Convert12BitRaw2Mv(VDD5REF_AN1[1]); /* Group 13, VDD5REF1 */
            return E_OK;

        case IOHWABS_ADC_CHANNEL_VDD5REF4:
            *RawResult = IoHwAbs_ADC_Convert12BitRaw2Mv(VDD5REF_AN1[2]); /* Group 1, VDD5REF4 */
            return E_OK;

        case IOHWABS_ADC_CHANNEL_VDD5REF6:
            *RawResult = IoHwAbs_ADC_Convert12BitRaw2Mv(VDD5REF_AN0[1]); /* Group 5, VDD5REF6 */
            return E_OK;

        case IOHWABS_ADC_CHANNEL_VDD5REF3:
            *RawResult = IoHwAbs_ADC_Convert12BitRaw2Mv(VDD5REF_AN0[0]); /* Group 3, VDD5REF3 */
            return E_OK;

        case IOHWABS_ADC_CHANNEL_VDD5REF2:
            *RawResult = IoHwAbs_ADC_Convert12BitRaw2Mv(VDD5REF_AN0[2]); /* Group 8, VDD5REF2 */
            return E_OK;

        default:
            break;
    }

    Adc_ChIndex_LO = IoHwAbs_ADC_Search_Input_Channel_Check(ChIdx);

    if((Adc_ChIndex_LO == IoHwAbs_ADC_Invalid_Value)||(ChIdx >= IOHWABS_ADC_CHANNEL_NUM))
    {
        RetVal_LO = E_NOT_OK;
    
    }
    else
    {

        Adc_GroupIdx_LO = Adc_CfgParams_STR[Adc_ChIndex_LO].valGroup;
        Adc_ChannleIdx_LO = Adc_CfgParams_STR[Adc_ChIndex_LO].valChannel;
        Adc_StreamNumSamp_LO = Adc_valConfigptr_STR->Adc_GroupConfig[Adc_GroupIdx_LO].StreamNumSamp;
        Adc_Formula_LO = Adc_CfgParams_STR[Adc_ChIndex_LO].valConvertFormula;
        Adc_Result_LO = Adc_DMAReadBufferptr_ARRY[Adc_GroupIdx_LO][Adc_ChannleIdx_LO * Adc_StreamNumSamp_LO];

        if (Adc_Result_LO != 0)
        {
            *RawResult = (uint16)(IoHwAbs_ADC_Convert12BitRaw2Mv(Adc_Result_LO) * Adc_Formula_LO);
        }
        else
        {
            *RawResult = 0;
        }
        
    }

    return RetVal_LO;
}


/**
 * @brief  Get raw ADC value for specified channel
 * @param  ChIdx - Channel index
 * @param  RawResult - Pointer to store raw ADC value
 * @return E_OK if successful, E_NOT_OK if channel invalid
 */
Std_ReturnType IoHwAbs_ADC_GetChannelOriginalRegValue(uint16 ChIdx, uint16 *RawResult)
{
    Std_ReturnType RetVal_LO = E_OK;
    float Adc_Formula_LO;
    uint16 Adc_Result_LO = 0, Adc_GroupIdx_LO = 0, Adc_ChannleIdx_LO = 0;
    VAR(Adc_StreamNumSampleType, ADC_VAR)
    Adc_StreamNumSamp_LO = 1;
    uint16 Adc_ChIndex_LO = 0;

    if(ChIdx == IOHWABS_ADC_CHANNEL_VDD5REF5)
    {
        *RawResult = VDD5REF_AN1[0];        //Group6  Vdd5Ref5
    }
    else if(IOHWABS_ADC_CHANNEL_VDD5REF1 == ChIdx)      //Group13 Vdd5Ref1
    {
        *RawResult = VDD5REF_AN1[1];
    }
    else if(IOHWABS_ADC_CHANNEL_VDD5REF4 == ChIdx)      //Group1  Vdd5Ref4
    {
        *RawResult = VDD5REF_AN1[2];
    }
    Adc_ChIndex_LO = IoHwAbs_ADC_Search_Input_Channel_Check(ChIdx);

    if((Adc_ChIndex_LO == IoHwAbs_ADC_Invalid_Value)||(ChIdx >= IOHWABS_ADC_CHANNEL_NUM))
    {
        RetVal_LO = E_NOT_OK;
    
    }
    else
    {

        Adc_GroupIdx_LO = Adc_CfgParams_STR[Adc_ChIndex_LO].valGroup;
        Adc_ChannleIdx_LO = Adc_CfgParams_STR[Adc_ChIndex_LO].valChannel;
        Adc_Formula_LO = Adc_CfgParams_STR[Adc_ChIndex_LO].valConvertFormula;
        Adc_Result_LO = Adc_DMAReadBufferptr_ARRY[Adc_GroupIdx_LO][Adc_ChannleIdx_LO * Adc_StreamNumSamp_LO];

        if (Adc_Result_LO != 0)
        {
            *RawResult = (uint16)(IoHwAbs_ADC_Original_REG_VAL(Adc_Result_LO));
        }
        else
        {
            *RawResult = 0;
        }
             
    }

    return RetVal_LO;
}

/**
 * @brief  Get filtered ADC value for specified channel
 * @param  ChIdx - Channel index
 * @param  FileterResult - Pointer to store filtered value
 * @return E_OK if successful, E_NOT_OK if channel invalid
 */
Std_ReturnType IoHwAbs_ADC_GetChannelValue(uint16 ChIdx, uint16 *FileterResult)
{
    Std_ReturnType RetVal_LO = E_OK;

    if (ChIdx <= IOHWABS_ADC_CHANNEL_NUM || IOHWABS_ADC_CHANNEL_NUM >= 0)
    {
        *FileterResult = Adc_valFilterResult_ARRY[ChIdx];
    }
    else
    {
        RetVal_LO = E_NOT_OK;
    }
    return RetVal_LO;
}


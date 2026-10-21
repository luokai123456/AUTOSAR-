/*** create info *******************************************
*@ filename : IoHwAbs_ADC_Cfg.c
*@ Author : pianyongxin 
*@ date :2025-02-12
*@ Description :ADC相关配置
/*** modify info ******************************************* 
*@ version :0.0
*@ Modifier : pianyongxin 
*@ date :2025-02-12
*@ Modification Description :
初始版本
************************************************************/
#ifndef IOHWABS_ADC_CFG_H_
#define IOHWABS_ADC_CFG_H_
/********************************************** Include **********************************************/

#include "IoHwAbs_ADC_PRV.h"
#include "Adc_Cfg.h"
#include "Adc.h"
#include "Adc_Irq.h"
#include "StandardTypes.h"
#include "Platform_Types.h"
#include "eMIOS_LLDriver.h"
#include "Pwm_Emios_LLDriver.h"
/***************************************** Macro Definitions *****************************************/
#define IoHwAbs_ADC_ChannelFormula_5VSensor     2.0
#define IoHwAbs_ADC_ChannelFormula_Ls		    2.0
#define IoHwAbs_ADC_ChannelFormula_BAT          5.55
#define IoHwAbs_ADC_ChannelFormula_IN_ANx       1.0
#define IoHwAbs_ADC_ChannelFormula_Hs		    8.02
#define IoHwAbs_ADC_ChannelFormula_CAN    		10.1
#define IoHwAbs_ADC_ChannelFormula_Imu			1.1



#define IoHwAbs_ADC_Invalid_Value               0xFFFF
#define Group26_BufferSize                            4*4
#define Group27_BufferSize                            2*4

/****************************************** Types Definition ******************************************/
/**
 * 结构体名称: Adc_CfgParams_TDSTR
 * 描述: ADC配置参数结构体
 */
typedef struct 
{   
    uint16		  valChannellId;
	uint16        valGroup;
	uint16        valChannel;
	float 		  valConvertFormula;		   
} Adc_CfgParams_TDSTR;

/****************************************** External Varibles *****************************************/
extern Adc_ValueGroupType*  Adc_ResultBufferptr_ARRY[];
extern Adc_ValueGroupType*  Adc_DMAReadBufferptr_ARRY[];
extern Adc_ValueGroupType*  ADC_FilterResBuffptr_ARRY[];
extern const Adc_CfgParams_TDSTR  Adc_CfgParams_STR[];
extern const eMIOS_GlobalParamType eMIOS_GlobalConfig_STR;
extern const eMIOS_PWM_ParamType eMIOS_PWM_OPWFMB_CH17_ChanConfig;
extern const eMIOS_PWM_ParamType eMIOS_PWM_OPWFMB_CH18_ChanConfig;
extern const eMIOS_PWM_ParamType eMIOS_PWM_OPWFMB_CH19_ChanConfig;
extern const eMIOS_PWM_ParamType eMIOS_PWM_OPWFMB_CH20_ChanConfig;
extern const eMIOS_PWM_ParamType eMIOS_PWM_OPWFMB_CH21_ChanConfig;
extern const eMIOS_PWM_ParamType eMIOS_PWM_OPWFMB_ChanConfig_STR;

#endif /*IOHWABS_ADC_CFG_H_*/

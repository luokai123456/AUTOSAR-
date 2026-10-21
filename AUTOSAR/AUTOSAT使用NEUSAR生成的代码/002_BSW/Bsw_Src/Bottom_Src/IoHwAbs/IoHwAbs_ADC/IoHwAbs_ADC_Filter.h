/*** create info *******************************************
*@ filename : IoHwAbs_ADC_Filter.h
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
#ifndef IOHWABS_ADC_FILTER_H_
#define IOHWABS_ADC_FILTER_H_


/********************************************** Include **********************************************/
#include "Platform_Types.h"
#include "StandardTypes.h"
#include "IoHwAbs_ADC.h"
#include "IoHwAbs_ADC_Prv.h"
/***************************************** Macro Definitions *****************************************/
#define IOHWABS_ADC_FILTER_MATIRIX_X	5
#define IOHWABS_ADC_FILTER_MATIRIX_Y	IOHWABS_ADC_CHANNEL_NUM
#define ADC_VAL_ZERO	                0       

#define IS_ORIGINAL_VALUE_CHANNEL(ch)  ((ch) == IOHWABS_ADC_CHANNEL_AN_Driver_5V)
/****************************************** External Varibles *****************************************/
extern uint16 Adc_valFilterResult_ARRY[IOHWABS_ADC_CHANNEL_NUM];

/********************************************* Function *********************************************/
/**
 * 函数名称: IoHwAbs_ADC_ReFileterValue
 * 参数in: args
 * 参数out: args
 * 返回值: return
 * 描述: ADC滤波函数
 */
extern void IoHwAbs_ADC_ReFileterValue(void);

#endif/*IOHWABS_ADC_FILTER_H_*/



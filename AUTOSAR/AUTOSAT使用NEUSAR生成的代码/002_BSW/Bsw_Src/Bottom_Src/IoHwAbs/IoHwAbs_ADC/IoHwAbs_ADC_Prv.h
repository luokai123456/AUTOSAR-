/*** create info *******************************************
*@ filename : IoHwAbs_ADC_Prv.h 
*@ Author : pianyongxin 
*@ date :2025-02-12
*@ Description :函数接口
/*** modify info ******************************************* 
*@ version :0.0
*@ Modifier : pianyongxin 
*@ date :2025-02-12
*@ Modification Description :
初始版本
************************************************************/
#ifndef IOHWABS_ADC_PRV_H
#define IOHWABS_ADC_PRV_H

/********************************************** Include **********************************************/
#include "IoHwAbs_ADC_Cfg.h"
#include "StandardTypes.h"
/***************************************** Macro Definitions *****************************************/
#define SWTRIG_ENABLE_USE 	0
#define HWTRIG_ENABLE_USE 	1


#define IOHWABS_ADC_CHANNEL_NUM                         (70U)
#define HS_WSTD6080_INFO_SIZE                           6
#define HS_WSTQ6080_INFO_SIZE                           7

//*Functions to convert ADC raw data*/
#define IoHwAbs_ADC_ConvertArrayRaw2Mv(rawResult)       (uint16)( ((uint32)rawResult*5000)/16380)
#define IoHwAbs_ADC_Convert12BitRaw2Mv(rawResult)       (uint16)( ((uint32)rawResult*5000)/4095)
#define IoHwAbs_ADC_Convert12BitRaw2V(rawResult)        (uint16)((uint32)rawResult*5/4096)
#define IoHwAbs_ADC_Original_REG_VAL(rawResult)         (uint16)(((uint32)rawResult))
#define IoHwAbs_ADC_GroupTimeout                        (uint8)20
/********************************************* Function *********************************************/
/**
 * 函数名称: IoHwAbs_ADC_Init
 * 参数in: args
 * 参数out: args
 * 返回值: return
 * 描述: ADC抽象层初始化
 */
extern void IoHwAbs_ADC_Init(void);
/**
 * 函数名称: IoHwAbs_ADC_MainFunction
 * 参数in: args
 * 参数out: args
 * 返回值: return
 * 描述: ADC抽象层主函数
 */
extern void IoHwAbs_ADC_MainFunction(void);
extern void IoHwAbs_ADC_ATOM_IrqHandler(void);

/**
 * 函数名称: IoHwAbs_ADC_GroupConversion
 * 参数in: 组Id
 * 参数out: args
 * 返回值: return
 * 描述: ADC通道组转换
 */
extern Std_ReturnType IoHwAbs_ADC_GroupConversion(uint8 GroupIdx);


extern Std_ReturnType IoHwAbs_ADC_GetChannelOriginalRegValue(uint16 ChIdx, uint16 *RawResult);

#endif /*IOHWABS_ADC_PRV_H*/

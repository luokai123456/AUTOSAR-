/*** create info ***********************
 *@ filename : IoHwAbs_NTC_Lookup.h
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
#ifndef IOHWABS_NTC_LOOKUP_H
#define IOHWABS_NTC_LOOKUP_H
/******************* Include ********************/
#include "Platform_Types.h"
#include "Std_Types.h"


#define SYS_NTCThermisor_MCU 0U
#define SYS_NTCThermisor_SBC 1U


/******************* Global Variable ****************/

extern float NTC_valResistance_kohm_Mp[5];



extern const float32 NTC_t_map[];
extern const float32 NTC_r_map[];

/******************* Function Declaration ********************/

Std_ReturnType IoHwAbs_ADC_GetNTCTempureValue(uint8 Channel, sint16 *Resultvalue);


#endif
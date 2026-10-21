/*** create info ***********************
*@ Author : yanxinlong 
*@ date :2025-12-25
*@ Description :描述本文件实现功能
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : yanxinlong 
*@ date :2025-12-25
*@ Modification Description :
初始版本
****************************************/
#ifndef EVPT_SYSTEM_H
#define EVPT_SYSTEM_H
#include "Mcu.h"

#if(1)
#include "BswM.h"
#include "IoHwAbs_DIO_prv.h"
#include "System_Release.h"
#include "Gpt_Stm_LLDriver.h"
#include "Cdd_Sa47301.h"
extern uint32 Sys_tiWakeTime;
extern boolean Sys_tiWakeTimeEn;
extern uint32 Sys_tiRemainWakeTime;
extern void  Sys_SensorCtrlInit_Function(void);
#endif

#ifndef __SYSTEM_RELEASE_H_
/*Reset*/
#define BSWM_RESET_TYPE_HARD		(0u)
#define BSWM_RESET_TYPE_SOFT		(1u)
#define BSWM_RESET_TYPE_BOOT        (2u)
#endif

#endif
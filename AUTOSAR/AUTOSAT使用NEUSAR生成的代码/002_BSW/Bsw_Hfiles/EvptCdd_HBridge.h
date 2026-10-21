/*** create info ***************************************************************
*@ File name: EvptCdd_HBridge.h
*@ Author : tandehuai
*@ date :2025-01-22
*@ Description : HBridge的相关的接口声明
**** modify info ***************************************************************
*@ version :0.0
*@ Modifier : tandehuai
*@ date :2025-01-22
*@ Modification Description : 打库的初始版本
********************************************************************************/
#ifndef __EVPTCDD_HB_HE99MD_H_
#define __EVPTCDD_HB_HE99MD_H_

#include "Std_Types.h"


#define EXT_D_HB_CHANNEL1			(0U)
#define EXT_D_HB_CHANNEL2			(1U)
#define EXT_D_HB_CHANNEL3			(2U)
#define EXT_D_HB_CHANNEL4			(3U)
#define EXT_D_HB_CHANNEL5			(4U)
#define EXT_D_HB_CHANNEL6			(5U)
#define EXT_D_HB_CHANNEL7			(6U)
#define EXT_D_HB_CHANNEL8			(7U)

/* 描述: 半桥输出函数
 * 参数：
 * 		HB_PwmCtrl: 0: continuous 1: PWM
 * 		HB_Fct: 0:off 1: LS 2: HS
 * 		HB_Freq: 0: 80Hz 1: 100Hz 2: 200Hz 3: 2000Hz
 * 		HB_Duty: 0~100
 */
extern uint8 Cdd_HalfBridegeOut_Function(
		uint8 HB_valChannel, uint8 HB_PwmCtrl, uint8 HB_Fct,
		uint8 HB_Freq, uint8 HB_Duty
	);

#endif /*__EVPTCDD_HB_HE99MD_H_*/

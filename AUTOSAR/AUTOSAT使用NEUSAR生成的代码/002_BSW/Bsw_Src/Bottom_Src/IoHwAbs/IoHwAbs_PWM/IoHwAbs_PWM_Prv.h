/*** create info ***********************
*@ Author : duqian 
*@ date :2025-12-02
*@ Description :PWM The functional interface of the abstraction layer PWM H file
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : duqian 
*@ date :2025-12-02
*@ Modification Description :
初始版本
****************************************/
#ifndef IOHWABS_PWM_PRV_H
#define IOHWABS_PWM_PRV_H

/*******************************************************************************
 * Includes
 *******************************************************************************/
#include "IoHwAbs_PWM.h"
#include "Pwm.h"





/**************************************************/
#define IOHWABS_PWM_PwmOutChannMax		12
#define IoHwAbs_PWM_Invalid_Value     	0xFFFF
#define IOHWABS_PWM_GTM_TIMEBASE		1000000U//1MHz
#define IOHWABS_PWM_MAXDUTY				32768
#define IOHWABS_PWM_EMIOS_TIMEBASE		10000000U
#define EMIOS_DUTY_SCALE_FACTOR    		327.68f

extern uint16 Pwm_CheckInputChannel(uint16 Channel);
extern void IoHwAbs_Pwm_Mainfunction(void);
extern void IoHwAbs_Pwm_Init(void);
#endif/*IOHWABS_PWM_PRV_H*/

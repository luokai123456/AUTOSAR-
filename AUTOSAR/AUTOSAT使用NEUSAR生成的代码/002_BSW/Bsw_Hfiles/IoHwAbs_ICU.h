/*** create info ***********************
*@ Author : liufengyuan
*@ date :2024-12-02
*@ Description :Abstraction Layer ICU H file
**** modify info ***********************
*@ version :0.0
*@ Modifier : liufengyuan
*@ date :2024-12-02
*@ Modification Description :
初始版本
****************************************/
#ifndef IOHWABS_ICU_H
#define IOHWABS_ICU_H

/*******************************************************************************
 * Includes
 *******************************************************************************/

#include "Std_Types.h"

/*******************************************************************************
 * Defines
 *******************************************************************************/

typedef struct
{
	uint8   flgActive;
	uint8   numDuty;
	uint32  numFreq;
}Pwm_ResultIn_TDSTR;


#define IOHWABS_ICU_PwmIn_CH1			    	0
#define IOHWABS_ICU_PwmIn_CH2			    	1
#define IOHWABS_ICU_PwmIn_CH3			    	2
#define IOHWABS_ICU_PwmIn_CH4			    	3
#define IOHWABS_ICU_PwmIn_CH5			    	4
#define IOHWABS_ICU_PwmIn_CH6			    	5
#define IOHWABS_ICU_PwmIn_CH7			    	6
#define IOHWABS_ICU_PwmIn_CH8			    	7
#define IOHWABS_ICU_PwmIn_CH9			    	8
#define IOHWABS_ICU_PWM_OUT_FB1_PVF				9
#define IOHWABS_ICU_PWM_OUT_FB2_PVF				10
#define IOHWABS_ICU_PWM_OUT_FB3_PVF				11
#define IOHWABS_ICU_PWM_OUT_FB4_PVF				12
#define IOHWABS_ICU_PWM_OUT_FB5_PVF				13
#define IOHWABS_ICU_PWM_OUT_FB6_PVF				14
#define IOHWABS_ICU_PWM_OUT_FB10_PVF			15
#define IOHWABS_ICU_PWM_OUT_FB11_PVF			16
#define IOHWABS_ICU_MCU_DI_OCPorOV_TRIGGER		17



extern Std_ReturnType IoHwAbs_ICU_GetChanneValue(uint8 numChannel_LO, Pwm_ResultIn_TDSTR* valresult_STR);

extern Std_ReturnType IoHwAbs_ICU_GetTimeStampValues(uint16 channel,
									uint32 *Pwm_In_TimeStampResult, uint16 *TimeStampresultIdx );

#endif/*IOHWABS_ICU_H*/



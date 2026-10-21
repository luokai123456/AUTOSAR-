/*** create info ***********************
*@ Author : duqian 
*@ date :2025-12-02
*@ Description :PWM The functional interface of the abstraction layer PWM H file
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : duqian 
*@ date :2025-12-02
*@ Modification Description :
********************************************************************************/
#ifndef IOHWABS_PWM_H
#define IOHWABS_PWM_H

#include "Std_Types.h"
		

/*IoHwAbs_PWM_ChannelIdx*/
/**************************************************/
#define IoHwAbs_PWM_MCU_PWMOUT_CON1		       0U
#define IoHwAbs_PWM_MCU_PWMOUT_CON2		       1U
#define IoHwAbs_PWM_MCU_PWMOUT_CON3		       2U
#define IoHwAbs_PWM_MCU_PWMOUT_CON4		       3U
#define IoHwAbs_PWM_MCU_PWMOUT_CON5		       4U
#define IoHwAbs_PWM_MCU_PWMOUT_CON6		       5U
#define IoHwAbs_PWM_MCU_PWMOUT_CON10	       6U
#define IoHwAbs_PWM_MCU_VrefPhase_OCP_N	       7U 
#define IoHwAbs_PWM_MCU_VrefPhase_OCP_P        8U
#define IoHwAbs_PWM_MCU_Vref_VDC               9U
#define IoHwAbs_PWM_MCU_PWMOUT_CON7            10U
#define IoHwAbs_PWM_MCU_PWMOUT_CON11           11U




/**
 * 函数名称: Pwm_SetFreqAndDuty
 * 参数In: numChannel_LO - 通道编号 ：IoHwAbs_PWM_MCU_D_HS_1~IoHwAbs_PWM_MCU_D_LS_14
 * 参数In: numFrequency_LO - 频率 ： 50~5000Hz
 * 参数In: numDutyCycle_LO - 占空比 ： 0~100
 * 参数Out: none
 * 返回值: Std_ReturnType 是否成功
 * 描述: 设置PWM频率和占空比
 */
extern Std_ReturnType Pwm_SetFreqAndDuty(uint16 numChannel_LO,uint32 numFrequency_LO,uint32 numDutyCycle_LO);
/**
 * 函数名称: MotorDiag_PwmSetFreqDutySync
 * 参数In: numChannel_LO - 通道编号 ：IoHwAbs_PWM_MCU_VrefPhase_OCP_N~IoHwAbs_PWM_MCU_Vref_VDC
 * 参数In: numFrequency_LO - 频率 ： 50~5000Hz
 * 参数In: numDutyCycle_LO - 占空比 ： 0~1000
 * 参数Out: none
 * 返回值: Std_ReturnType 是否成功
 * 描述: 设置电机诊断PWM频率和占空比同步 千分制
 */
extern Std_ReturnType MotorDiag_PwmSetFreqDutySync(uint16 numChannel_LO,uint32 numFrequency_LO,uint32 numDutyCycle_LO);






#endif/*IOHWABS_PWM_H*/

#ifndef __PWMOUT_RELEASE_H_
#define __PWMOUT_RELEASE_H_

/* LS PWM index */
#define IoHwAbs_PWM_MCU_PWMOUT1                 (0U)
#define IoHwAbs_PWM_MCU_PWMOUT2                 (1U)
#define IoHwAbs_PWM_MCU_PWMOUT3                 (2U)
#define IoHwAbs_PWM_MCU_PWMOUT4                 (3U)
#define IoHwAbs_PWM_MCU_PWMOUT5                 (4U)
#define IoHwAbs_PWM_MCU_PWMOUT6                 (5U)
#define IoHwAbs_PWM_MCU_PWMOUT10                (6U)
#define IoHwAbs_PWM_MCU_VrefPhase_OCP_N         (7U)
#define IoHwAbs_PWM_MCU_VrefPhase_OCP_P         (8U)
#define IoHwAbs_PWM_MCU_Vref_VDC                (9U)
#define IoHwAbs_PWM_MCU_PWMOUT7                 (10U)
#define IoHwAbs_PWM_MCU_PWMOUT11                (11U)

/**
 * @name Cdd_PwmOut_Function
 * @param uint16 ValChId，通道，参考LS PWM index
 * @param uint32 Frequency，PWM频率，单位：Hz
 * @param uint32 DutyCycle，PWM占空比，单位：%
 * @return 成功(0)/失败(1)
 */
extern Std_ReturnType Cdd_PwmOut_Function(uint16 ValChId, uint32 Frequency, uint32 DutyCycle);

#endif

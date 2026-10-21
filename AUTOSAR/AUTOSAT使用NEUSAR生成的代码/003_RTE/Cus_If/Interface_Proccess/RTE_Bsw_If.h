#ifndef RTE_BSW_IF_H
#define RTE_BSW_IF_H

#include "Std_Types.h"


extern void RTE_Set_M_TM_APhase_Duty(float32 f32_DutyCycle);
extern void RTE_Set_M_TM_BPhase_Duty(float32 f32_DutyCycle);
extern void RTE_Set_M_TM_CPhase_Duty(float32 f32_DutyCycle);
extern void RTE_Set_M_TM_PWM_Period(float32 PwmFreq);

#endif /* RTE_BSW_IF_H */
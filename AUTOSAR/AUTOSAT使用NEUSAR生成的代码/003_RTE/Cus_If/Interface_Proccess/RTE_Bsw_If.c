#include "RTE_Bsw_If.h"
#include "MCU_fc_BIfRx_OUT.h"

void RTE_Set_M_TM_APhase_Duty(float32 f32_DutyCycle)
{
    SGPP_FOC_f32_Uduty_Null = f32_DutyCycle;
}

void RTE_Set_M_TM_BPhase_Duty(float32 f32_DutyCycle)
{
    SGPP_FOC_f32_Vduty_Null = f32_DutyCycle;
}

void RTE_Set_M_TM_CPhase_Duty(float32 f32_DutyCycle)
{
    SGPP_FOC_f32_Wduty_Null = f32_DutyCycle;
}

// void RTE_Set_M_TM_PWM_Period(float32 PwmFreq)
// {
//     SGPP_kFOC_f32_PWMFreq_Hz = PwmFreq;
// }
/*
 * File: PMS_HWO_Serve.c
 *
 * Code generated for Simulink model 'PMS_HWO_Serve'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Apr 15 16:22:37 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PMS_HWO_Serve.h"
#include "PMS_HWO_Serve_private.h"
#include "Hsd_Release.h"
#include "EvptCdd_HBridge.h"
#include "Lsd_Release.h"
#include "PwmOut_Release.h"
#include "LampOut_Release.h"
/* Model step function */
void PMSHWO_DO_KEY_HS_03_PMSHWO_SetDOHS(uint8 Ctr)
{
	Cdd_LampOut_SetLevelFunction(EXT_D_LAMP_CH8,Ctr);
}

/* Model step function */
void PMSHWO_DO_KEY_HS_05_PMSHWO_SetDOHS(uint8 Ctr)
{
	Cdd_LampOut_SetLevelFunction(EXT_D_LAMP_CH9,Ctr);
}

/* Model step function */
void PMSHWO_DO_RELAY_HS_11_PMSHWO_SetDOHS(uint8 Ctr)
{
  Cdd_Hsd_SetLevelFunction(EXT_D_HS_CH_10,Ctr);
}

/* Model step function */
void PMSHWO_DO_RELAY_HS_6_PMSHWO_SetDOHS(uint8 Ctr)
{
  Cdd_Hsd_SetLevelFunction(EXT_D_HS_CH_5,Ctr);
}

/* Model step function */
void PMSHWO_DO_RELAY_HS_8_PMSHWO_SetDOHS(uint8 Ctr)
{
  Cdd_Hsd_SetLevelFunction(EXT_D_HS_CH_6,Ctr);
}

/* Model step function */
void PMSHWO_DO_RELAY_HS_9_PMSHWO_SetDOHS(uint8 Ctr)
{
  Cdd_Hsd_SetLevelFunction(EXT_D_HS_CH_9,Ctr);
}

/* Model step function */
void PMSHWO_DO_RELAY_LS_10_PMSHWO_SetDOLS(uint8 Ctr)
{
  /* The Interface has been deleted*/
  if(Ctr==1U)
  {
    Cdd_HalfBridegeOut_Function(EXT_D_HB_CHANNEL5, 0U, 1U,0U, 0U);
  }
  else
  {
    Cdd_HalfBridegeOut_Function(EXT_D_HB_CHANNEL5, 0U, 0U,0U, 0U);
  }
  
}

/* Model step function */
void PMSHWO_DO_RELAY_LS_12_PMSHWO_SetDOLS(uint8 Ctr)
{
  if(Ctr==1U)
  {
    Cdd_HalfBridegeOut_Function(EXT_D_HB_CHANNEL6, 0U, 1U,0U, 0U);
  }
  else
  {
    Cdd_HalfBridegeOut_Function(EXT_D_HB_CHANNEL6, 0U, 0U,0U, 0U);
  }
}

/* Model step function */
void PMSHWO_DO_RELAY_LS_5_PMSHWO_SetDOLS(uint8 Ctr)
{
	if(Ctr==1U)
	  {
	    Cdd_HalfBridegeOut_Function(EXT_D_HB_CHANNEL3, 0U, 1U,0U, 0U);
	  }
	  else
	  {
	    Cdd_HalfBridegeOut_Function(EXT_D_HB_CHANNEL3, 0U, 0U,0U, 0U);
	  }
}

/* Model step function */
void PMSHWO_DO_RELAY_LS_7_PMSHWO_SetDOLS(uint8 Ctr)
{
	if(Ctr==1U)
	  {
		Cdd_HalfBridegeOut_Function(EXT_D_HB_CHANNEL1, 0U, 1U,0U, 0U);
	  }
	  else
	  {
		Cdd_HalfBridegeOut_Function(EXT_D_HB_CHANNEL1, 0U, 0U,0U, 0U);
	  }
}

/* Model step function */
void PMSHWO_DO_RELAY_LS_9_PMSHWO_SetDOLS(uint8 Ctr)
{
	if(Ctr==1U)
	  {
		Cdd_HalfBridegeOut_Function(EXT_D_HB_CHANNEL2, 0U, 1U,0U, 0U);
	  }
	  else
	  {
		Cdd_HalfBridegeOut_Function(EXT_D_HB_CHANNEL2, 0U, 0U,0U, 0U);
	  }
}

/* Model step function */
void PMSHWO_PO_HVIL_1_PMSHWO_SetPWM(uint32 Frequency, uint32 DutyCycle)
{

	Cdd_PwmOut_Function(IoHwAbs_PWM_MCU_PWMOUT5,Frequency,DutyCycle);

}

/* Model step function */
void PMSHWO_PO_HVIL_2_PMSHWO_SetPWM(uint32 Frequency, uint32 DutyCycle)
{
	Cdd_PwmOut_Function(IoHwAbs_PWM_MCU_PWMOUT10,Frequency,DutyCycle);
}

/* Model step function */
void PMSHWO_PO_PWM_1_PMSHWO_SetPWM(uint32 Frequency, uint32 DutyCycle)
{
	Cdd_PwmOut_Function(IoHwAbs_PWM_MCU_PWMOUT3,Frequency,DutyCycle);
}

/* Model step function */
void PMSHWO_PO_PWM_2_PMSHWO_SetPWM(uint32 Frequency, uint32 DutyCycle)
{
	Cdd_PwmOut_Function(IoHwAbs_PWM_MCU_PWMOUT6,Frequency,DutyCycle);
}

/* Model step function */
void PMSHWO_PO_PWM_4_PMSHWO_SetPWM(uint32 Frequency, uint32 DutyCycle)
{
	Cdd_PwmOut_Function(IoHwAbs_PWM_MCU_PWMOUT1,Frequency,DutyCycle);
}

/* Model initialize function */
void PMS_HWO_Serve_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

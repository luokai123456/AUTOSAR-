/***********************************************************************************************************************
**--------------------------------------------------------------------------------------------------------------------**
** Copyright (c) 2023 by XXX.		All rights reserved.
** This software is copyright protected and proprietary to XXX.
** XXX grants to you only those rights as set out in the license conditions.
** All other rights remain with XXX.
**--------------------------------------------------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: ..\ Adc3ph$
* $Class_____: C$
* $Name______: Adc3ph_Callout.c$
* $ArVeri____: 3$
* $FcVeri____: 0.0$
* $Author____: XXX$
*
* $Configuration or generate Date,Time: 14:19 . 2023/2/15 $
**
**--------------------------------------------------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: Yes
**--------------------------------------------------------------------------------------------------------------------**
** DESCRIPTION:
** Adc3ph driver callout source file
***********************************************************************************************************************/

/***********************************************************************************************************************
**                        				Other Header File Inclusion                    								  **
***********************************************************************************************************************/
#include "Mcu.h"
#include "Gpt_Stm_LLDriver.h"
#include "Adc3ph_Callout.h"
#include "CCFC3012PT.h"



#pragma ghs section data =".foc_data"
#pragma ghs section text =".foc_code"
#pragma ghs section bss =".foc_bss"
/***********************************************************************************************************************
**                        					  Macro Definition                        								  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                        					 Typedef Definition                        								  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                   					Static Local Variables Definition    						          		  **
***********************************************************************************************************************/


/***********************************************************************************************************************
**                						Static Local Function Declaration    					        		      **
***********************************************************************************************************************/
#define ADC3PH_CODE_START
#include "Adc3ph_MemMap.h"

/***********************************************************************************************************************
** Function Name	: Gp_IoMcuAdc_CalloutGetCoreId
** Service ID		: None
** Sync/Async		: Synchronous
** Reentrancy		: Non_Reentrancy
** Parameter[in]	: None
** Parameter[inout]	: None
** Parameter[out]	: None
** Return Value		: uint32 - core ID
** Description		: get core ID callout function
***********************************************************************************************************************/
extern	uint32	Adc3ph_CalloutGetCoreId(void);


/***********************************************************************************************************************
** Function Name	: Adc3ph_CalloutSetDelayNus
** Service ID		: None
** Sync/Async		: Synchronous
** Reentrancy		: Non_Reentrancy
** Parameter[in]	: float32 ArgIn_Nus_f32
** Parameter[inout]	: None
** Parameter[out]	: None
** Return Value		: None
** Description	  	: Adc3ph_STM_DelayNus
***********************************************************************************************************************/
extern	void Adc3ph_CalloutSetDelayNus(float32 ArgIn_Nus_f32);


#define ADC3PH_CODE_STOP
#include "Adc3ph_MemMap.h"



/***********************************************************************************************************************
**                 							  Function Source Code          					  		              **
***********************************************************************************************************************/
#define ADC3PH_CODE_START
#include "Adc3ph_MemMap.h"

/***********************************************************************************************************************
** Function Name	: Gp_IoMcuAdc_CalloutGetCoreId
** Service ID		: None
** Sync/Async		: Synchronous
** Reentrancy		: Non_Reentrancy
** Parameter[in]	: None
** Parameter[inout]	: None
** Parameter[out]	: None
** Return Value		: uint32 - core ID
** Description		: get core ID callout function
***********************************************************************************************************************/
uint32	Adc3ph_CalloutGetCoreId(void)
{
	uint32	CoreId_u32 = 0U;
	uint32	TempId_u32 = 0U;
	TempId_u32 = (uint32)MFSPR(SPR_PIR);
	CoreId_u32 = TempId_u32;
	return (CoreId_u32);
}

/***********************************************************************************************************************
** Function Name	: Adc3ph_CalloutSetDelayNus
** Service ID		: None
** Sync/Async		: Synchronous
** Reentrancy		: Non_Reentrancy
** Parameter[in]	: float32 ArgIn_Nus_f32
** Parameter[inout]	: None
** Parameter[out]	: None
** Return Value		: None
** Description	  	: Adc3ph_STM_DelayNus
***********************************************************************************************************************/
void Adc3ph_CalloutSetDelayNus(float32 ArgIn_Nus_f32)
{
	volatile uint32 StartTick_Temp_u32 = 0U;
	volatile uint32 StopTick_Temp_u32  = 0U;
	volatile uint32 LastTick_Temp_u32 = 0U;
	volatile uint32 ArgIn_Interval = 0U;

	/*Capture the current Tick value*/
	StartTick_Temp_u32 = (uint32)Gpt_Stm_LLD_GetCounter(STM0);

	/*calculate the tick interval*/
	ArgIn_Interval =  ArgIn_Nus_f32;

	while (LastTick_Temp_u32 < ArgIn_Interval)
	{
		StopTick_Temp_u32 = (uint32)Gpt_Stm_LLD_GetCounter(STM0);
		/*calculate the Interval tick*/

		if (StopTick_Temp_u32 > StartTick_Temp_u32)
		{
			LastTick_Temp_u32 = StopTick_Temp_u32 - StartTick_Temp_u32;
		}
		else
		{
			LastTick_Temp_u32 = 0xFFFFFFFFU  + StopTick_Temp_u32 - StartTick_Temp_u32;
		}
	}
}

#define ADC3PH_CODE_STOP
#include "Adc3ph_MemMap.h"

/***********************************************************************************************************************
* $ArchiVer History:$
V1
New 
***********************************************************************************************************************/

/***********************************************************************************************************************
* $FcVer History:$
* 1.0.0		2025.07.10 David
* N: New MultiCore Adc3ph
***********************************************************************************************************************/

#pragma ghs section
#pragma ghs section
#pragma ghs section
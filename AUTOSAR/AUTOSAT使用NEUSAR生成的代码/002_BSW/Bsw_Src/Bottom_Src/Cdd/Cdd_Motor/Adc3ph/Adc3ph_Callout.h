/***********************************************************************************************************************
** Copyright (c)  2023 by XXX.		All rights reserved.
** This software is copyright protected and proprietary to XXX.
** XXX grants to you only those rights as set out in the license conditions.
** All other rights remain with XXX.
**--------------------------------------------------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: ..\ Adc3ph$
* $Class_____: C$
* $Name______: Adc3ph_Callout.h$
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
** Adc3ph driver callout header file
***********************************************************************************************************************/
#ifndef ADC3PH_CALLOUT_H_
#define ADC3PH_CALLOUT_H_

/***********************************************************************************************************************
**                        				Other Header File Inclusion                    								  **
***********************************************************************************************************************/
#include "Adc3ph_Cfg.h"
/***********************************************************************************************************************
**                 						Global Function Prototypes          					  		              **
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
extern uint32	Adc3ph_CalloutGetCoreId(void);

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

#endif /* ADC3PH_CALLOUT_H_ */

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


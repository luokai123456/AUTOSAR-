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
* $Name______: Adc3ph_Cali.c$
* $ArVeri____: 3$
* $FcVeri____: 0.0$
* $Author____: XXX$
*
* $Configuration or generate Date,Time: 17:18 . 2023/3/28 $
**
**--------------------------------------------------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: Yes
**--------------------------------------------------------------------------------------------------------------------**
** DESCRIPTION:
** Adc3ph driver calibration source file
***********************************************************************************************************************/

/***********************************************************************************************************************
**                        				Other Header File Inclusion                    								  **
***********************************************************************************************************************/
#include "Adc3ph_Cfg.h"

/***********************************************************************************************************************
**                  				    Global Variables Definition            						  		          **
***********************************************************************************************************************/
#pragma ghs section data =".foc_data"
#pragma ghs section text =".foc_code"
#pragma ghs section bss =".foc_bss"
#define ADC3PH_CONST_FAR_DATA_ALIGN4_CALI_GLOBAL_START
#include "Adc3ph_MemMap.h"

// const volatile	float32 Adc3ph_DelayTime_kf32 = 1.0f;
// const volatile	uint32	Adc3ph_MaxLoopCnt_ku32 = 1U;
// const volatile	uint32	Adc3ph_EcuVolMax_ku32 = 4800U;
// const volatile	uint32	Adc3ph_EcuVolMin_ku32 = 200U;

#define ADC3PH_CONST_FAR_DATA_ALIGN4_CALI_GLOBAL_STOP
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

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
* $Name______: Adc3ph_Cfg.h$
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
** Adc3ph driver CFG header file
***********************************************************************************************************************/
#ifndef ADC3PH_CFG_H_
#define ADC3PH_CFG_H_

/***********************************************************************************************************************
**                        				Other Header File Inclusion                    								  **
***********************************************************************************************************************/
#include "Adc3ph_Types.h"
/*other FC header file inclusion if necessary*/

/***********************************************************************************************************************
**                        					  Macro Definition                        								  **
***********************************************************************************************************************/
/*signal number is total number of providing from all cores*/
#define	ADC3PH_CFG_SIG_NUM				(4U)
#define ADC3PH_SIG_MOTOR_A				((uint8)0U)/*Motor Signal - A*/

/*AURIX2G core*/
#define	ADC3PH_CORE0_ENABLE               (STD_ON)
// #define ADC3PH_CORE1_ENABLE            (STD_ON)
// #define ADC3PH_CORE2_ENABLE            (STD_ON)
#define ADC3PH_CORE3_ENABLE               (STD_ON)

/*Global Configuration*/
#define ADC3PH_CFG_HWTRG_ENABLE           (TRUE)/*Enable the HW Trigger of Adc Group*/
#define ADC3PH_CFG_VOL_ENABLE             (FALSE)/*Calculate the voltage of adc channel*/
#define	ADC3PH_CFG_VOL_CONV_RATIO			(1.220703125f)  /*Conversion fraction of voltage*/
/***********************************************************************************************************************/
#if (ADC3PH_CORE0_ENABLE == STD_ON)
#define	ADC3PH_CFG_CORE0_GRP_NUM			(3U)/*Group Number*/
#define	ADC3PH_CFG_CORE0_MOT_NUM			(1U)/*Motor Number*/
#define	ADC3PH_CFG_CORE0_CHL_NUM			(3U)/*Channel Number*/

/*Motor Index Configuration*/
#define ADC3PH_CFG_CORE0_MOT_A_INDEX		(0U)/*Motor A Index*/
#endif

#if (ADC3PH_CORE1_ENABLE == STD_ON)
#define	ADC3PH_CFG_CORE1_GRP_NUM			(0U)/*Group Number*/
#define	ADC3PH_CFG_CORE1_MOT_NUM			(1U)/*Motor Number*/
#define	ADC3PH_CFG_CORE1_CHL_NUM			(3U)/*Channel Number*/

/*Motor Index Configuration*/
#define ADC3PH_CFG_CORE1_MOT_A_INDEX		(0U)/*Motor A Index*/
#endif

#if (ADC3PH_CORE2_ENABLE == STD_ON)
#define	ADC3PH_CFG_CORE2_GRP_NUM			(3U)/*Group Number*/
#define	ADC3PH_CFG_CORE2_MOT_NUM			(1U)/*Motor Number*/
#define	ADC3PH_CFG_CORE2_CHL_NUM			(3U)/*Channel Number*/

/*Motor Index Configuration*/
#define ADC3PH_CFG_CORE2_MOT_A_INDEX		(0U)/*Motor A Index*/
#endif

#if (ADC3PH_CORE3_ENABLE == STD_ON)
#define	ADC3PH_CFG_CORE3_GRP_NUM			(3U)/*Group Number*/
#define	ADC3PH_CFG_CORE3_MOT_NUM			(1U)/*Motor Number*/
#define	ADC3PH_CFG_CORE3_CHL_NUM			(3U)/*Channel Number*/

/*Motor Index Configuration*/
#define ADC3PH_CFG_CORE3_MOT_A_INDEX		(0U)/*Motor A Index*/
#endif

/***********************************************************************************************************************
**                        				Global Variables With Declaration											  **
***********************************************************************************************************************/
#define ADC3PH_CONST_FAR_DATA_ALIGN4_GLOBAL_START
#include "Adc3ph_MemMap.h"

extern Adc3ph_CfgType	Adc3ph_CfgCont_vcatst[ADC3PH_CORE_NUM];
extern Adc3ph_AdcSigMappingCfgType	Adc3ph_cfgAdcSigMapping_vcatst[ADC3PH_CFG_SIG_NUM];

#define ADC3PH_CONST_FAR_DATA_ALIGN4_GLOBAL_STOP
#include "Adc3ph_MemMap.h"

/***********************************************************************************************************************
**                  				    Global Cali Variables Definition            						          **
***********************************************************************************************************************/

#define ADC3PH_CONST_FAR_DATA_ALIGN4_CALI_GLOBAL_START
#include "Adc3ph_MemMap.h"

// extern const volatile float32  Adc3ph_DelayTime_kf32;
// extern const volatile uint32   Adc3ph_MaxLoopCnt_ku32;
// extern const volatile uint32   Adc3ph_EcuVolMax_ku32;
// extern const volatile uint32   Adc3ph_EcuVolMin_ku32;

#define ADC3PH_CONST_FAR_DATA_ALIGN4_CALI_GLOBAL_STOP
#include "Adc3ph_MemMap.h"

#endif /* ADC3PH_CFG_H_ */

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


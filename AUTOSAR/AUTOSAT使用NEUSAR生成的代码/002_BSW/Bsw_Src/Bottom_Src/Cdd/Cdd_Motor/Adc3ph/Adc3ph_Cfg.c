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
* $Name______: Adc3ph_Cfg.c$
* $ArVeri____: 3$
* $FcVeri____: 0.0$
* $Author____: XXX$
*
* $Configuration or generate Date,Time: 14:19 2023/2/15 $
**
**--------------------------------------------------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: Yes
**--------------------------------------------------------------------------------------------------------------------**
** DESCRIPTION:
** Adc3ph driver CFG file
***********************************************************************************************************************/

/***********************************************************************************************************************
**                        				Other Header File Inclusion                    								  **
***********************************************************************************************************************/
#include "Adc3ph_Cfg.h"

#include "CCFC3012PT.h"
#include "Adc_Cfg.h"



#pragma ghs section data =".foc_data"
#pragma ghs section text =".foc_code"
#pragma ghs section bss =".foc_bss"

/***********************************************************************************************************************
**                   					Static Local Variables Definition    						          		  **
***********************************************************************************************************************/
//Core0 Cfg
#if (ADC3PH_CORE0_ENABLE == STD_ON)
#define ADC3PH_CONST_FAR_DATA_ALIGN4_CORE0_START
#include "Adc3ph_MemMap.h"

ADC3PH_STATIC_ Adc3ph_HwGrpCfgType Adc3ph_HwGrpCfgCore0_lcatst[ADC3PH_CFG_CORE0_GRP_NUM] =
{
	ADC_GROUP_AdcGroup_3,	/*U Fusa*/
	ADC_GROUP_AdcGroup_5,   /*V Fusa*/
	ADC_GROUP_AdcGroup_8,	/*W Fusa*/
};

ADC3PH_STATIC_  Adc3ph_HwChlCfgType Adc3ph_HwChlCfgCore0_lcatst[ADC3PH_CFG_CORE0_CHL_NUM] =
{
	{
			&EQADC1_ADC23.RFPR[0],    /*U Fusa AN0 ADC2_CH0 PS15*/
			&EQADC1_ADC23.FISR[0],
	},
	{
			&EQADC1_ADC23.RFPR[2],    /*V Fusa AN0 ADC3_CH11 PQ14*/
			&EQADC1_ADC23.FISR[2],
	},
	{
			&EQADC2_ADC45.RFPR[2],    /*W Fusa AN0 ADC5_CH0 PU1*/
			&EQADC2_ADC45.FISR[2],
	}
};

#define ADC3PH_CONST_FAR_DATA_ALIGN4_CORE0_STOP
#include "Adc3ph_MemMap.h"
#endif

//Core1 Cfg
#if (ADC3PH_CORE1_ENABLE == STD_ON)
#define ADC3PH_CONST_FAR_DATA_ALIGN4_CORE1_START
#include "Adc3ph_MemMap.h"

ADC3PH_STATIC_ const Adc3ph_HwChlCfgType Adc3ph_HwChlCfgCore1_lcatst[ADC3PH_CFG_CORE1_CHL_NUM] =
{

};

#define ADC3PH_CONST_FAR_DATA_ALIGN4_CORE1_STOP
#include "Adc3ph_MemMap.h"
#endif

//Core2 Cfg
#if (ADC3PH_CORE2_ENABLE == STD_ON)
#define ADC3PH_CONST_FAR_DATA_ALIGN4_CORE2_START
#include "Adc3ph_MemMap.h"

ADC3PH_STATIC_ const Adc3ph_HwGrpCfgType Adc3ph_HwGrpCfgCore2_lcatst[ADC3PH_CFG_CORE0_GRP_NUM] =
{

};

ADC3PH_STATIC_ const Adc3ph_HwChlCfgType Adc3ph_HwChlCfgCore2_lcatst[ADC3PH_CFG_CORE2_CHL_NUM] =
{

};

#define ADC3PH_CONST_FAR_DATA_ALIGN4_CORE2_STOP
#include "Adc3ph_MemMap.h"
#endif

//Core3 Cfg
#if (ADC3PH_CORE3_ENABLE == STD_ON)
#define ADC3PH_CONST_FAR_DATA_ALIGN4_CORE3_START
#include "Adc3ph_MemMap.h"

ADC3PH_STATIC_ const Adc3ph_HwGrpCfgType Adc3ph_HwGrpCfgCore3_lcatst[ADC3PH_CFG_CORE3_GRP_NUM] =
{
	ADC_GROUP_AdcGroup_6,	/*U AN1 ADC*/
	ADC_GROUP_AdcGroup_13,  /*V AN1 ADC*/
	ADC_GROUP_AdcGroup_1,	/*W AN1 ADC*/
};

ADC3PH_STATIC_ const Adc3ph_HwChlCfgType Adc3ph_HwChlCfgCore3_lcatst[ADC3PH_CFG_CORE3_CHL_NUM] =
{
		{
			&EQADC2_ADC45.RFPR[0],    /*U  AN1 ADC4_CH1 PT4*/
			&EQADC2_ADC45.FISR[0],
		},
		{
			&EQADC5_ADC1011.RFPR[0],  /*V  AN1 ADC10_CH0 PP1*/
			&EQADC5_ADC1011.FISR[0],
		},
		{
			&EQADC0_ADC01.RFPR[0],    /*W  AN1 ADC1_CH0 PS10*/
			&EQADC0_ADC01.FISR[0],
		}
};


#define ADC3PH_CONST_FAR_DATA_ALIGN4_CORE3_STOP
#include "Adc3ph_MemMap.h"
#endif

//Core4 Cfg
#if (ADC3PH_CORE4_ENABLE == STD_ON)
#define ADC3PH_CONST_FAR_DATA_ALIGN4_CORE4_START
#include "Adc3ph_MemMap.h"

#define ADC3PH_CONST_FAR_DATA_ALIGN4_CORE4_STOP
#include "Adc3ph_MemMap.h"
#endif

//Core5 Cfg
#if (ADC3PH_CORE5_ENABLE == STD_ON)
#define ADC3PH_CONST_FAR_DATA_ALIGN4_CORE5_START
#include "Adc3ph_MemMap.h"

#define ADC3PH_CONST_FAR_DATA_ALIGN4_CORE5_STOP
#include "Adc3ph_MemMap.h"
#endif

//Global Cfg
#define ADC3PH_CONST_FAR_DATA_ALIGN4_GLOBAL_START
#include "Adc3ph_MemMap.h"

#define ADC3PH_CONST_FAR_DATA_ALIGN4_GLOBAL_STOP
#include "Adc3ph_MemMap.h"

/***********************************************************************************************************************
**                  					   Global Variables Definition            						  		      **
***********************************************************************************************************************/
#define ADC3PH_CONST_FAR_DATA_ALIGN4_GLOBAL_START
#include "Adc3ph_MemMap.h"

Adc3ph_CfgType	Adc3ph_CfgCont_vcatst[ADC3PH_CORE_NUM] =
{
	/*global constant configuration address of core0*/
	{
#if (ADC3PH_CORE0_ENABLE == STD_ON)
		&Adc3ph_HwChlCfgCore0_lcatst[0U],
		&Adc3ph_HwGrpCfgCore0_lcatst[0U],
		ADC3PH_CFG_CORE0_MOT_NUM,
		ADC3PH_CFG_CORE0_CHL_NUM,
		ADC3PH_CFG_CORE0_GRP_NUM,
#else
		(Adc3ph_HwChlCfgType*)ADC3PH_NULL_PTR,
		(Adc3ph_HwGrpCfgType*)ADC3PH_NULL_PTR,
		0U,
		0U,
		0U,
#endif
	},
	/*global constant configuration address of core1*/
	{
#if (ADC3PH_CORE1_ENABLE == STD_ON)
		&Adc3ph_HwChlCfgCore1_lcatst[0U],
		(Adc3ph_HwGrpCfgType*)ADC3PH_NULL_PTR,
		ADC3PH_CFG_CORE1_MOT_NUM,
		ADC3PH_CFG_CORE1_CHL_NUM,
		ADC3PH_CFG_CORE1_GRP_NUM,
#else
		(Adc3ph_HwChlCfgType*)ADC3PH_NULL_PTR,
		(Adc3ph_HwGrpCfgType*)ADC3PH_NULL_PTR,
		0U,
		0U,
		0U,
#endif
},
	/*global constant configuration address of core2*/
	{
#if (ADC3PH_CORE2_ENABLE == STD_ON)
		&Adc3ph_HwChlCfgCore2_lcatst[0U],
		&Adc3ph_HwGrpCfgCore2_lcatst[0U],
		ADC3PH_CFG_CORE2_MOT_NUM,
		ADC3PH_CFG_CORE2_CHL_NUM,
		ADC3PH_CFG_CORE2_GRP_NUM,
#else
		(Adc3ph_HwChlCfgType*)ADC3PH_NULL_PTR,
		(Adc3ph_HwGrpCfgType*)ADC3PH_NULL_PTR,
		0U,
		0U,
		0U,
#endif
	},

	/*global constant configuration address of core3*/
	{
#if (ADC3PH_CORE3_ENABLE == STD_ON)
		&Adc3ph_HwChlCfgCore3_lcatst[0U],
		&Adc3ph_HwGrpCfgCore3_lcatst[0U],
		ADC3PH_CFG_CORE3_MOT_NUM,
		ADC3PH_CFG_CORE3_CHL_NUM,
		ADC3PH_CFG_CORE3_GRP_NUM,
#else
		(Adc3ph_HwChlCfgType*)ADC3PH_NULL_PTR,
		(Adc3ph_HwGrpCfgType*)ADC3PH_NULL_PTR,
		0U,
		0U,
		0U,
#endif
	},
};

Adc3ph_AdcSigMappingCfgType	Adc3ph_cfgAdcSigMapping_vcatst[ADC3PH_CFG_SIG_NUM] =
{
	{  ADC3PH_CORE0_ID,	ADC3PH_CFG_CORE0_MOT_A_INDEX },
	{  ADC3PH_CORE1_ID,	ADC3PH_CFG_CORE1_MOT_A_INDEX },
	{  ADC3PH_CORE2_ID,	ADC3PH_CFG_CORE2_MOT_A_INDEX },
	{  ADC3PH_CORE3_ID,	ADC3PH_CFG_CORE3_MOT_A_INDEX },
};

#define ADC3PH_CONST_FAR_DATA_ALIGN4_GLOBAL_STOP
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
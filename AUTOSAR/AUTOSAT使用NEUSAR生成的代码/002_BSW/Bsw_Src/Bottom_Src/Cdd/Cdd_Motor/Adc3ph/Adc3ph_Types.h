/***********************************************************************************************************************
**--------------------------------------------------------------------------------------------------------------------**
** Copyright (c)  2023 by XXX.		All rights reserved.
** This software is copyright protected and proprietary to XXX.
** XXX grants to you only those rights as set out in the license conditions.
** All other rights remain with XXX.
**--------------------------------------------------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: ..\ Adc3ph$
* $Class_____: C$
* $Name______: Adc3ph_Types.h$
* $ArVeri____: 3$
* $FcVeri____: 0.0$
* $Author____: XXX$
**
**--------------------------------------------------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**--------------------------------------------------------------------------------------------------------------------**
** DESCRIPTION:
** Adc3ph driver types header file
***********************************************************************************************************************/
#ifndef ADC3PH_TYPES_H_
#define ADC3PH_TYPES_H_

/***********************************************************************************************************************
**                        				Other Header File Inclusion                    								  **
***********************************************************************************************************************/
#include "Platform_Types.h"
/***********************************************************************************************************************
**                        				Macro Definition                        								      **
***********************************************************************************************************************/
#define ADC3PH_UNUSED_PARAMETER(VariableName)	(void)(VariableName)
#define ADC3PH_NULL_PTR						((void *) 0)

#ifndef ADC3PH_INLINE_
#if defined __TASKING__
#define ADC3PH_INLINE_		static inline
#elif defined __HIGHTEC__
#define ADC3PH_INLINE_		static inline __attribute__	((always_inline))
#endif
#endif

#ifndef ADC3PH_STATIC_
#define ADC3PH_STATIC_		static
#endif

#define ADC3PH_REG_RES_MASK 	((uint32)0x0000FFFFU)/*RES Register Mask*/
#define ADC3PH_REG_VF_MASK  	((uint32)0x000000F0U)/*VF Register Mask*/
#define ADC3PH_REG_OVERFLAW	    ((uint32)0x80000U)   /*Overflow Register Mask*/
#define ADC3PH_REG_VF_SHIFT  	((uint32)4)		     /*VF Register Shift*/
#define ADC3PH_REG_FIFODEEP  	((uint32)2)		 	 /*FIFO Deep Register Shift*/
#define ADC3PH_SFE_WFIFODEEP  	((uint32)3)		 	 /*Safety WFIFO Deep Register Shift*/

#define ADC3PH_VADC_VALID		(TRUE)/*ADC VF Flag Valid*/
#define ADC3PH_VADC_INVALID		(FALSE)/*ADC VF Flag Invalid*/
#define	ADC3PH_INVALID_U16		((uint16)0xFFFFU)/*Invalid*/
#define	ADC3PH_INVALID_U32		((uint32)0xFFFFFFFFU)/*Invalid*/

#define ADC3PH_OFFSET_BASE     	(3U)/*Base Channel Index of Motor*/
#define ADC3PH_OFFSET_U        	(0U)/*U Channel Index offset*/
#define ADC3PH_OFFSET_V       	(1U)/*V Channel Index offset*/
#define ADC3PH_OFFSET_W        	(2U)/*W Channel Index offset*/

#define ADC3PH_Fusa_OFFSET_U    (0U)/*U Channel Function safety Index offset*/
#define ADC3PH_Fusa_OFFSET_V    (1U)/*V Channel Function safety Index offset*/
#define ADC3PH_Fusa_OFFSET_W    (2U)/*W Channel Function safety Index offset*/

#define ADC3PH_NONE            	(0U)/*NONE*/

#define ADC3PH_VF_POLL_TIMEOUT_CNT	(3U)

/*Adc3ph core ID should be configured according to MCU core ID*/
#define	ADC3PH_CORE0_ID    		(0U)
#define ADC3PH_CORE1_ID   		(1U)
#define ADC3PH_CORE2_ID    		(2U)
#define ADC3PH_CORE3_ID    		(3U)
#define ADC3PH_CORE_NUM			(4U)
/***********************************************************************************************************************
**										Typedef Definition															  **
***********************************************************************************************************************/
typedef uint16 Adc3ph_HwGrpCfgType;

typedef struct Adc3ph_HwChlCfg
{
	 volatile void *ResReg_cptst;
	 volatile void *FisrReg_cptst;
}Adc3ph_HwChlCfgType;

typedef	struct	Adc3ph_Cfg
{
	const	Adc3ph_HwChlCfgType	*AdcSigChlCfg_cptst;
	const	Adc3ph_HwGrpCfgType	*AdcSigGrpCfg_cpt;
	uint8	MotNum_u8;	/*Motor number*/
	uint8	ChlCnt_u8;	/*ADC Channel number*/
	uint8	GrpNum_u8;	/*ADC group number*/
}Adc3ph_CfgType;

typedef uint16 Adc3ph_GrpDataType;

typedef struct Adc3ph_MotorData
{
	boolean MotorValid_b;/*Motor Data Valid flag*/
}Adc3ph_MotDataType;

typedef struct Adc3ph_ChlData
{
	uint32  AdcVol_u32;/*ADC VOL value*/
	uint16  AdcRaw_u16;/*ADC RAW value*/
	boolean AdcVf_b;  /*ADC VF flag*/
}Adc3ph_ChlDataType;

typedef	struct	Adc3ph_RunTime
{
	Adc3ph_MotDataType	*AdcMot_ptst;
	Adc3ph_ChlDataType    *AdcChl_ptst;
	Adc3ph_GrpDataType    *AdcGrp_pt;
}Adc3ph_RunTimeType;

/****************************************************Mapping***********************************************************/
typedef	struct	Adc3ph_AdcSigMappingCfg
{
	uint32	MappingCoreId_u32;	/*signal mapping core*/
	uint32	MappingMotIdx_u32;	/*signal mapping Motor index*/
}Adc3ph_AdcSigMappingCfgType;	/*specifies the signal mapping configuration*/

#endif /* ADC3PH_TYPES_H_ */

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


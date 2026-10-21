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
* $Name______: Adc3ph.c$
* $ArVeri____: 3$
* $FcVeri____: 0.0$
* $Author____: XXX$
**
**--------------------------------------------------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**--------------------------------------------------------------------------------------------------------------------**
** DESCRIPTION:
** Adc3ph driver source file
***********************************************************************************************************************/

/***********************************************************************************************************************
**                        				Other Header File Inclusion                    								  **
***********************************************************************************************************************/
#include "Adc3ph.h"

#include "Adc.h"

#include "Adc3ph_Callout.h"

#include "Gpt_Stm_LLDriver.h"
#include "Pwm3ph.h"
#pragma ghs section data =".foc_data"
// #pragma ghs section text =".foc_code"
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
#if (ADC3PH_CORE0_ENABLE == STD_ON)
#define ADC3PH_CLEAR_FAR_DATA_ALIGN4_CORE0_START
#include "Adc3ph_MemMap.h"

#if ADC3PH_CFG_CORE0_CHL_NUM > ADC3PH_NONE
ADC3PH_STATIC_	Adc3ph_MotDataType    Adc3ph_MotCore0_latst[ADC3PH_CFG_CORE0_MOT_NUM];
ADC3PH_STATIC_	Adc3ph_ChlDataType	Adc3ph_ChlCore0_latst[ADC3PH_CFG_CORE0_CHL_NUM];
#endif
#if ADC3PH_CFG_CORE0_GRP_NUM > ADC3PH_NONE
ADC3PH_STATIC_	Adc3ph_GrpDataType	Adc3ph_GrpCore0_latst[ADC3PH_CFG_CORE0_GRP_NUM];
#endif

#define ADC3PH_CLEAR_FAR_DATA_ALIGN4_CORE0_STOP
#include "Adc3ph_MemMap.h"
#endif


#if (ADC3PH_CORE1_ENABLE == STD_ON)
#define ADC3PH_CLEAR_FAR_DATA_ALIGN4_CORE1_START
#include "Adc3ph_MemMap.h"

#if ADC3PH_CFG_CORE1_CHL_NUM > ADC3PH_NONE
ADC3PH_STATIC_	Adc3ph_MotDataType	Adc3ph_MotCore1_latst[ADC3PH_CFG_CORE1_MOT_NUM];
ADC3PH_STATIC_	Adc3ph_ChlDataType	Adc3ph_ChlCore1_latst[ADC3PH_CFG_CORE1_CHL_NUM];
#endif
#if ADC3PH_CFG_CORE1_GRP_NUM > ADC3PH_NONE
ADC3PH_STATIC_	Adc3ph_GrpDataType	Adc3ph_GrpCore1_latst[ADC3PH_CFG_CORE1_GRP_NUM];
#endif

#define ADC3PH_CLEAR_FAR_DATA_ALIGN4_CORE1_STOP
#include "Adc3ph_MemMap.h"
#endif


#if (ADC3PH_CORE2_ENABLE == STD_ON)
#define ADC3PH_CLEAR_FAR_DATA_ALIGN4_CORE2_START
#include "Adc3ph_MemMap.h"

#if ADC3PH_CFG_CORE2_CHL_NUM > ADC3PH_NONE
ADC3PH_STATIC_	Adc3ph_MotDataType    Adc3ph_MotCore2_latst[ADC3PH_CFG_CORE2_MOT_NUM];
ADC3PH_STATIC_	Adc3ph_ChlDataType	Adc3ph_ChlCore2_latst[ADC3PH_CFG_CORE2_CHL_NUM];
#endif
#if ADC3PH_CFG_CORE2_GRP_NUM > ADC3PH_NONE
ADC3PH_STATIC_	Adc3ph_GrpDataType	Adc3ph_GrpCore2_latst[ADC3PH_CFG_CORE2_GRP_NUM];
#endif

#define ADC3PH_CLEAR_FAR_DATA_ALIGN4_CORE2_STOP
#include "Adc3ph_MemMap.h"
#endif

#if (ADC3PH_CORE3_ENABLE == STD_ON)
#define ADC3PH_CLEAR_FAR_DATA_ALIGN4_CORE3_START
#include "Adc3ph_MemMap.h"

#if ADC3PH_CFG_CORE3_CHL_NUM > ADC3PH_NONE
ADC3PH_STATIC_	Adc3ph_MotDataType    Adc3ph_MotCore3_latst[ADC3PH_CFG_CORE3_MOT_NUM];
ADC3PH_STATIC_	Adc3ph_ChlDataType	Adc3ph_ChlCore3_latst[ADC3PH_CFG_CORE3_CHL_NUM];
#endif
#if ADC3PH_CFG_CORE3_GRP_NUM > ADC3PH_NONE
ADC3PH_STATIC_	Adc3ph_GrpDataType	Adc3ph_GrpCore3_latst[ADC3PH_CFG_CORE3_GRP_NUM];
#endif

#define ADC3PH_CLEAR_FAR_DATA_ALIGN4_CORE3_STOP
#include "Adc3ph_MemMap.h"
#endif


#define ADC3PH_CONST_FAR_DATA_ALIGN4_GLOBAL_START
#include "Adc3ph_MemMap.h"

/*FC runtime buffer address container for multiple-core*/
ADC3PH_STATIC_	Adc3ph_RunTimeType	Adc3ph_rtCont_lcatst[ADC3PH_CORE_NUM] =
{
	/*global constant runtime buffer address of core0*/
	{
#if (ADC3PH_CORE0_ENABLE == STD_ON)
#if ADC3PH_CFG_CORE0_CHL_NUM > ADC3PH_NONE
		&Adc3ph_MotCore0_latst[0U],
		&Adc3ph_ChlCore0_latst[0U],
#else
		(Adc3ph_MotDataType*)ADC3PH_NULL_PTR,
		(Adc3ph_ChlDataType*)ADC3PH_NULL_PTR,
#endif
#if ADC3PH_CFG_CORE0_GRP_NUM > ADC3PH_NONE
		&Adc3ph_GrpCore0_latst[0U],
#else
		(Adc3ph_GrpDataType*)ADC3PH_NULL_PTR,
#endif
#else
		(Adc3ph_MotDataType*)ADC3PH_NULL_PTR,
		(Adc3ph_ChlDataType*)ADC3PH_NULL_PTR,
		(Adc3ph_GrpDataType*)ADC3PH_NULL_PTR,
#endif
	},
	/*global constant runtime buffer address of core1*/
	{
#if (ADC3PH_CORE1_ENABLE == STD_ON)
#if ADC3PH_CFG_CORE1_CHL_NUM > ADC3PH_NONE
		&Adc3ph_MotCore1_latst[0U],
		&Adc3ph_ChlCore1_latst[0U],
#else
		(Adc3ph_MotDataType*)ADC3PH_NULL_PTR,
		(Adc3ph_ChlDataType*)ADC3PH_NULL_PTR,
#endif
#if ADC3PH_CFG_CORE1_GRP_NUM > ADC3PH_NONE
		&Adc3ph_GrpCore1_latst[0U],
#else
		(Adc3ph_GrpDataType*)ADC3PH_NULL_PTR,
#endif
#else
		(Adc3ph_MotDataType*)ADC3PH_NULL_PTR,
		(Adc3ph_ChlDataType*)ADC3PH_NULL_PTR,
		(Adc3ph_GrpDataType*)ADC3PH_NULL_PTR,
#endif
	},
	/*global constant runtime buffer address of core2*/
	{
#if (ADC3PH_CORE2_ENABLE == STD_ON)
#if ADC3PH_CFG_CORE2_CHL_NUM > ADC3PH_NONE
		&Adc3ph_MotCore2_latst[0U],
		&Adc3ph_ChlCore2_latst[0U],
#else
		(Adc3ph_MotDataType*)ADC3PH_NULL_PTR,
		(Adc3ph_ChlDataType*)ADC3PH_NULL_PTR,
#endif
#if ADC3PH_CFG_CORE2_GRP_NUM > ADC3PH_NONE
		&Adc3ph_GrpCore2_latst[0U],
#else
		(Adc3ph_GrpDataType*)ADC3PH_NULL_PTR,
#endif
#else
		(Adc3ph_MotDataType*)ADC3PH_NULL_PTR,
		(Adc3ph_ChlDataType*)ADC3PH_NULL_PTR,
		(Adc3ph_GrpDataType*)ADC3PH_NULL_PTR,
#endif
	},

	/*global constant runtime buffer address of core3*/
	{
#if (ADC3PH_CORE3_ENABLE == STD_ON)
#if ADC3PH_CFG_CORE3_CHL_NUM > ADC3PH_NONE
		&Adc3ph_MotCore3_latst[0U],
		&Adc3ph_ChlCore3_latst[0U],
#else
		(Adc3ph_MotDataType*)ADC3PH_NULL_PTR,
		(Adc3ph_ChlDataType*)ADC3PH_NULL_PTR,
#endif
#if ADC3PH_CFG_CORE3_GRP_NUM > ADC3PH_NONE
		&Adc3ph_GrpCore3_latst[0U],
#else
		(Adc3ph_GrpDataType*)ADC3PH_NULL_PTR,
#endif
#else
		(Adc3ph_MotDataType*)ADC3PH_NULL_PTR,
		(Adc3ph_ChlDataType*)ADC3PH_NULL_PTR,
		(Adc3ph_GrpDataType*)ADC3PH_NULL_PTR,
#endif
	},
};

#define ADC3PH_CONST_FAR_DATA_ALIGN4_GLOBAL_STOP
#include "Adc3ph_MemMap.h"
/***********************************************************************************************************************
**                						Static Local Function Declaration    					        		      **
***********************************************************************************************************************/
#define ADC3PH_CODE_START
#include "Adc3ph_MemMap.h"

ADC3PH_STATIC_ void	Adc3ph_GetADCRawData
(
	const Adc3ph_CfgType *Cfg_cptst, const Adc3ph_RunTimeType *Rt_cptst, uint32 MotorId_u32
);

ADC3PH_STATIC_ void	Adc3ph_GetSafeADCRawData
(
	const Adc3ph_CfgType *Cfg_cptst, const Adc3ph_RunTimeType *Rt_cptst, uint32 MotorId_u32
);

ADC3PH_STATIC_ void Adc3ph_ClearChannelValidFlg
(
	const Adc3ph_RunTimeType *Rt_cptst, uint32 MotorId_u32
);

#if (ADC3PH_CFG_VOL_ENABLE == TRUE)

ADC3PH_STATIC_ void Adc3ph_DiagEcuVolValue
(
	const Adc3ph_RunTimeType *Rt_cptst, uint32 MotorId_u32
);

ADC3PH_STATIC_ void Adc3ph_CalculateADCVol
(
	const Adc3ph_RunTimeType *Rt_cptst, uint32 MotorId_u32
);

#endif /*#if (ADC3PH_CFG_VOL_ENABLE == TRUE)*/

#define ADC3PH_CODE_STOP
#include "Adc3ph_MemMap.h"

/***********************************************************************************************************************
**                 							  Function Source Code          					  		              **
***********************************************************************************************************************/
#define ADC3PH_CODE_START
#include "Adc3ph_MemMap.h"

/***********************************************************************************************************************
** Function Name	: Adc3ph_Init
** Service ID		: None
** Sync/Async		: Synchronous
** Reentrancy		: Non_Reentrancy
** Parameter[in]	: None
** Parameter[inout]	: None
** Parameter[out]	: None
** Parameter[in]	: uint32 CoreId_u32
** Return Value		: void
** Description		: Initialize the variable of runtime data and enable HW Sample Trigger of ADC Group
***********************************************************************************************************************/
void	Adc3ph_Init(uint32 CoreId_u32)
{
	const	Adc3ph_CfgType	*Cfg_cptst = &Adc3ph_CfgCont_vcatst[0U];
	const	Adc3ph_RunTimeType	*Rt_cptst = &Adc3ph_rtCont_lcatst[0U];

	uint32  ChlCnt_u32 = 0U;
	uint32  GrpCnt_u32 = 0U;
	uint32  MotorIndex_u32 = 0U;

	/*Point to CFG & Runtime data*/
	Cfg_cptst  = &Adc3ph_CfgCont_vcatst[CoreId_u32];
	Rt_cptst   = &Adc3ph_rtCont_lcatst[CoreId_u32];

	/*Initialize Runtime data for Motor*/
	for (MotorIndex_u32 = 0U; MotorIndex_u32 < (uint32)Cfg_cptst->MotNum_u8; MotorIndex_u32++)
	{
		Rt_cptst->AdcMot_ptst[MotorIndex_u32].MotorValid_b = ADC3PH_VADC_INVALID;
	}

	/*Initialize Runtime data for ADC channel*/
	for (ChlCnt_u32 = 0U; ChlCnt_u32 < (uint32)Cfg_cptst->ChlCnt_u8; ChlCnt_u32++)
	{
		Adc3ph_ChlDataType   *Channel_ptst = &Rt_cptst->AdcChl_ptst[ChlCnt_u32];

		/*set initial value*/
		Channel_ptst->AdcVol_u32 = ADC3PH_INVALID_U32;
		Channel_ptst->AdcRaw_u16 = ADC3PH_INVALID_U16;
		Channel_ptst->AdcVf_b   = ADC3PH_VADC_INVALID;
	}

#if (ADC3PH_CFG_HWTRG_ENABLE == TRUE)
	/* Enabled HW Sample Trigger of ADC Group*/
	for (GrpCnt_u32 = 0U; GrpCnt_u32 < (uint32)Cfg_cptst->GrpNum_u8; GrpCnt_u32++)
	{
		(void)Adc_SetupResultBuffer(Cfg_cptst->AdcSigGrpCfg_cpt[GrpCnt_u32], \
				(Adc_ValueGroupType* const)&Rt_cptst->AdcGrp_pt[GrpCnt_u32]);
		Adc_EnableHardwareTrigger(Cfg_cptst->AdcSigGrpCfg_cpt[GrpCnt_u32]);
	}
#endif	/*#if (ADC3PH_CFG_HWTRG_ENABLE == TRUE)*/
}

void Adc3ph_SetFifoMode(void)
{
	//设置RFIFO模式 关DMA
	EQADC2_ADC45.IDCR0.B.RFDS0 = 0; //U相 设置为中断请求 而非DMA请求
	EQADC2_ADC45.IDCR0.B.RFDE0 = 0; //U相 禁用DMA请求
	EQADC2_ADC45.IDCR0.B.EOQIE0 = 0;//U相 禁用队列结束请求

	EQADC5_ADC1011.IDCR0.B.RFDS0 = 0;//V相 设置为中断请求 而非DMA请求
	EQADC5_ADC1011.IDCR0.B.RFDE0 = 0;//V相 禁用DMA请求
	EQADC5_ADC1011.IDCR0.B.EOQIE0 = 0;//V相 禁用队列结束请求

	EQADC0_ADC01.IDCR0.B.RFDS0 = 0;//W相 设置为中断请求 而非DMA请求
	EQADC0_ADC01.IDCR0.B.RFDE0 = 0;//W相 禁用DMA请求
	EQADC0_ADC01.IDCR0.B.EOQIE0 = 0;//W相 禁用队列结束请求

	//功能安全 设置RFIFO模式 关DMA
	EQADC1_ADC23.IDCR0.B.RFDS0 = 0; //U相冗余 设置为中断请求 而非DMA请求 FIFO 0 
	EQADC1_ADC23.IDCR0.B.RFDE0 = 0; //U相冗余 禁用DMA请求
	EQADC1_ADC23.IDCR0.B.EOQIE0 = 0;//U相冗余 禁用队列结束请求

	EQADC1_ADC23.IDCR1.B.RFDS2 = 0;//V相冗余 设置为中断请求 而非DMA请求 FIFO 2
	EQADC1_ADC23.IDCR1.B.RFDE2 = 0;//V相冗余 禁用DMA请求
	EQADC1_ADC23.IDCR1.B.EOQIE2 = 0;//V相冗余 禁用队列结束请求

	EQADC2_ADC45.IDCR1.B.RFDS2 = 0;//W相冗余 设置为中断请求 而非DMA请求 FIFO 2
	EQADC2_ADC45.IDCR1.B.RFDE2 = 0;//W相冗余 禁用DMA请求
	EQADC2_ADC45.IDCR1.B.EOQIE2 = 0;//W相冗余 禁用队列结束请求

	//设置三相抢占
	EQADC2_ADC45.MCR.B.ICEA0=1; //U相启动立即转换 同时转换功能安全W相
	EQADC2_ADC45.MCR.B.ICEA1=1; //U相启动立即转换 同时转换功能安全W相

	EQADC5_ADC1011.MCR.B.ICEA0=1; //V相启动立即转换
	EQADC5_ADC1011.MCR.B.ICEA1=1; //V相启动立即转换

	EQADC0_ADC01.MCR.B.ICEA0=1; //W相启动立即转换
	EQADC0_ADC01.MCR.B.ICEA1=1; //W相启动立即转换

	EQADC1_ADC23.MCR.B.ICEA0=1; //功能安全 UV相启动立即转换
	EQADC1_ADC23.MCR.B.ICEA1=1; //功能安全 UV相启动立即转换

}

#pragma ghs section text =".foc_code"
/***********************************************************************************************************************
** Function Name	: Adc3ph_MainFunction
** Service ID		: None
** Sync/Async		: Synchronous
** Reentrancy		: Non_Reentrancy
** Parameter[in]	: None
** Parameter[inout]	: None
** Parameter[out]	: None
** Parameter[in]	: uint32 CoreId_u32
** Return Value		: void
** Description		: Read the three-phase current Raw values, Calculate the ADC Voltage value
***********************************************************************************************************************/
void	Adc3ph_MainFunction(uint32 CoreId_u32)
{
	const	Adc3ph_CfgType	*Cfg_cptst = &Adc3ph_CfgCont_vcatst[0U];
	const	Adc3ph_RunTimeType	*Rt_cptst = &Adc3ph_rtCont_lcatst[0U];

	uint32  MotorIndex_u32 = 0U;
	uint32  LoopCnt_u32 = 0U;

	/*Point to CFG & Runtime data*/
	Cfg_cptst  = &Adc3ph_CfgCont_vcatst[CoreId_u32];
	Rt_cptst   = &Adc3ph_rtCont_lcatst[CoreId_u32];

	/*Get the ADC Raw and valid flag*/
	Adc3ph_GetADCRawData(&Cfg_cptst[0U], &Rt_cptst[0U], MotorIndex_u32);

	/*Clear the valid flag of ADC channel*/
	Adc3ph_ClearChannelValidFlg(&Rt_cptst[0], MotorIndex_u32);
}

/***********************************************************************************************************************
** Function Name	: Adc3ph_SafetyMainFunction
** Service ID		: None
** Sync/Async		: Synchronous
** Reentrancy		: Non_Reentrancy
** Parameter[in]	: None
** Parameter[inout]	: None
** Parameter[out]	: None
** Parameter[in]	: uint32 CoreId_u32
** Return Value		: void
** Description		: Read the three-phase current Raw values, Calculate the ADC Voltage value
***********************************************************************************************************************/
void	Adc3ph_SafetyMainFunction(uint32 CoreId_u32)
{
	const	Adc3ph_CfgType	*Cfg_cptst = &Adc3ph_CfgCont_vcatst[0U];
	const	Adc3ph_RunTimeType	*Rt_cptst = &Adc3ph_rtCont_lcatst[0U];

	uint32  MotorIndex_u32 = 0U;
	uint32  LoopCnt_u32 = 0U;

	/*Point to CFG & Runtime data*/
	Cfg_cptst  = &Adc3ph_CfgCont_vcatst[CoreId_u32];
	Rt_cptst   = &Adc3ph_rtCont_lcatst[CoreId_u32];

	/*Get the ADC Raw and valid flag*/
	Adc3ph_GetSafeADCRawData(&Cfg_cptst[0U], &Rt_cptst[0U], MotorIndex_u32);

	/*Clear the valid flag of ADC channel*/
	Adc3ph_ClearChannelValidFlg(&Rt_cptst[0], MotorIndex_u32);
}


#if (ADC3PH_CFG_VOL_ENABLE == TRUE)
/***********************************************************************************************************************
** Function Name	: Adc3ph_GetEcuVolSig
** Service ID		: None
** Sync/Async		: Synchronous
** Reentrancy		: Non_Reentrancy
** Parameter[in]	: uint8 MotorId_u8
** Parameter[inout]	: None
** Parameter[out]	: uint32 *EcuVolU_pu32
** Parameter[out]	: uint32 *EcuVolV_pu32
** Parameter[out]	: uint32 *EcuVolW_pu32
** Parameter[out]	: boolean *EcuVolStu_pb
** Return Value		: void
** Description		: Read the VOL values and valid of three-phase current
***********************************************************************************************************************/
void	Adc3ph_GetEcuVolSig
(
	uint8	MotorId_u8,
	uint32 *EcuVolU_pu32,
	uint32 *EcuVolV_pu32,
	uint32 *EcuVolW_pu32,
	boolean *EcuVolStu_pb
)
{
	const	Adc3ph_RunTimeType	*Rt_cptst = &Adc3ph_rtCont_lcatst[0U];
	const	Adc3ph_AdcSigMappingCfgType	*SigMappingCfg_cptst = &Adc3ph_cfgAdcSigMapping_vcatst[0U];

	uint32	CoreId_u32 = 0U;

	/*Get the mapping motor index and calculate the base channel index */
	uint32  MotorIndex_u32  = SigMappingCfg_cptst[MotorId_u8].MappingMotIdx_u32;
	uint32	BaseChlIndex_u32 = MotorIndex_u32 * ADC3PH_OFFSET_BASE;

	/*Calculate the UVW channel index */
	uint32	U_ChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_U;
	uint32	V_ChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_V;
	uint32	W_ChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_W;

	/*get core ID*/
	CoreId_u32 = Adc3ph_CalloutGetCoreId();

	/*Point to Runtime data*/
	Rt_cptst   = &Adc3ph_rtCont_lcatst[CoreId_u32];

	/*Core Check*/
	if (SigMappingCfg_cptst[MotorId_u8].MappingCoreId_u32 == CoreId_u32)
	{
		/*Set the UVW VOL value by mapping motor index*/
		*EcuVolU_pu32  = Rt_cptst->AdcChl_ptst[U_ChlIndex_u32].AdcVol_u32;
		*EcuVolV_pu32  = Rt_cptst->AdcChl_ptst[V_ChlIndex_u32].AdcVol_u32;
		*EcuVolW_pu32  = Rt_cptst->AdcChl_ptst[W_ChlIndex_u32].AdcVol_u32;

		/*Set the valid flag by mapping motor index*/
		if (Rt_cptst->AdcMot_ptst[MotorIndex_u32].MotorValid_b == ADC3PH_VADC_VALID)
		{
			*EcuVolStu_pb = FALSE;
		}
		else
		{
			*EcuVolStu_pb = TRUE;
		}
	}
	else
	{
		/*for MISRA*/
	}
}
#endif /*#if (ADC3PH_CFG_VOL_ENABLE == TRUE)*/
/***********************************************************************************************************************
** Function Name	: Adc3ph_GetEcuRawSig
** Service ID		: None
** Sync/Async		: Synchronous
** Reentrancy		: Non_Reentrancy
** Parameter[in]	: uint8 MotorId_u8
** Parameter[inout]	: None
** Parameter[out]	: uint16 *EcuRawU_pu16
** Parameter[out]	: uint16 *EcuRawV_pu16
** Parameter[out]	: uint16 *EcuRawW_pu16
** Parameter[out]	: boolean *EcuRawStu_pb
** Parameter[in]	: uint32 CoreId_u32
** Parameter[in]	: uint32 Adc_time
** Return Value		: void
** Description		: Read the Raw values and valid of three-phase current
***********************************************************************************************************************/
INLINE void	Adc3ph_GetEcuRawSig
(
	uint8 MotorId_u8,
	uint16 *EcuRawU_pu16,
	uint16 *EcuRawV_pu16,
	uint16 *EcuRawW_pu16,
	uint32 *Adc_time,
	boolean *EcuRawStu_pb,
	uint32 CoreId_u32
)
{
	const	Adc3ph_RunTimeType	*Rt_cptst = &Adc3ph_rtCont_lcatst[0U];
	const	Adc3ph_AdcSigMappingCfgType	*SigMappingCfg_cptst = &Adc3ph_cfgAdcSigMapping_vcatst[0U];

	/*Get the mapping motor index and calculate the base channel index */
	uint32  MotorIndex_u32  = SigMappingCfg_cptst[MotorId_u8].MappingMotIdx_u32;
	uint32	BaseChlIndex_u32 = MotorIndex_u32 * ADC3PH_OFFSET_BASE;

	/*Calculate the UVW channel index */
	uint32	U_ChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_U;
	uint32	V_ChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_V;
	uint32	W_ChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_W;

	/*Point to Runtime data*/
	Rt_cptst   = &Adc3ph_rtCont_lcatst[CoreId_u32];

	/*Core Check*/
	if (SigMappingCfg_cptst[MotorId_u8].MappingCoreId_u32 == CoreId_u32)
	{

		/*Set the valid flag by mapping motor index*/
		if (Rt_cptst->AdcMot_ptst[MotorIndex_u32].MotorValid_b == ADC3PH_VADC_VALID)
		{
		/*Set the UVW VOL value by mapping motor index*/
		*EcuRawU_pu16  = Rt_cptst->AdcChl_ptst[U_ChlIndex_u32].AdcRaw_u16;
		*EcuRawV_pu16  = Rt_cptst->AdcChl_ptst[V_ChlIndex_u32].AdcRaw_u16;
		*EcuRawW_pu16  = Rt_cptst->AdcChl_ptst[W_ChlIndex_u32].AdcRaw_u16;
			*Adc_time      = Pwm3ph_GetTs();
			*EcuRawStu_pb = FALSE;
		}
		else
		{
			*EcuRawStu_pb = TRUE;
		}
	}
	else
	{
		/*for MISRA*/
	}
}




/***********************************************************************************************************************
** Function Name	: Adc3ph_GetADCRawData
** Service ID		: None
** Sync/Async		: Synchronous
** Reentrancy		: Non_Reentrancy
** Parameter[in]	: uint32 MotorId_u32
** Parameter[inout]	: Adc3ph_CfgType *Cfg_cptst
** Parameter[inout]	: Adc3ph_RunTimeType *Rt_cptst
** Parameter[out]	: void
** Return Value		: void
** Description		: Get the RES register of ADC channel, Update the Raw value of Valid channel and Merge the motor
 valid flag by UVW channel valid flag.
***********************************************************************************************************************/
uint16 VDD5REF_AN1[3]={0};
uint16 ADC3PH_OverflowFlag=0;
uint16 ADC3PH_ClearRfifo=0;
uint16 OverFour_Flag=0;
uint16 OverThree_Flag=0;
uint16 Timeover_Flag=0;
ADC3PH_STATIC_ INLINE void	Adc3ph_GetADCRawData
(
	const Adc3ph_CfgType *Cfg_cptst, const Adc3ph_RunTimeType *Rt_cptst, uint32 MotorId_u32
)
{
	Adc3ph_ChlDataType *AdcChl_lptst = Rt_cptst->AdcChl_ptst;

	uint32 ChlCnt_u32 = 0U;
	uint32 Vadc_Reg_u32 = 0U;
	uint32 Vadc_FifoDeep_u32 = 0U;
	uint8  MotorValidCnt = 0U;
	uint32 BaseChlIndex_u32 = MotorId_u32 * ADC3PH_OFFSET_BASE;
	uint32 EndChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_BASE;

	for (ChlCnt_u32 = BaseChlIndex_u32; ChlCnt_u32 < EndChlIndex_u32; ChlCnt_u32++)
	{
		/*Read the RES register*/
		if (AdcChl_lptst[ChlCnt_u32].AdcVf_b == ADC3PH_VADC_INVALID)
		{
			volatile uint32 Tick_Temp_u32 = 0U;
			volatile uint32 StartTick_u32 = (uint32)Gpt_Stm_LLD_GetCounter(STM0);
			while (Tick_Temp_u32 < ADC3PH_VF_POLL_TIMEOUT_CNT)
			{
				/*Read the ADC RES Register*/
				Vadc_Reg_u32 = *((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].FisrReg_cptst);
				Vadc_FifoDeep_u32= ((Vadc_Reg_u32 & ADC3PH_REG_VF_MASK)>>ADC3PH_REG_VF_SHIFT);
				/*Judge the VF Flag of RES register*/
				if (Vadc_FifoDeep_u32 >= ADC3PH_REG_FIFODEEP)
				{
					break;
				}

				volatile uint32 EndTick_u32 = (uint32)Gpt_Stm_LLD_GetCounter(STM0);
                #if 0
				if (EndTick_u32 > StartTick_u32)
				{
					Tick_Temp_u32 = EndTick_u32 - StartTick_u32;
				}
				else
				{
					Tick_Temp_u32 = 0xFFFFFFFFU  - StartTick_u32 + EndTick_u32 + 1;
				}
                #else
				Tick_Temp_u32 = EndTick_u32 - StartTick_u32;
				#endif
			}

			if (Vadc_FifoDeep_u32 >= ADC3PH_REG_FIFODEEP)
			{
			   /*Clear overflow flag if it is set before*/
				if(Vadc_Reg_u32 & ADC3PH_REG_OVERFLAW )
				{
					ADC3PH_OverflowFlag++;
					*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].FisrReg_cptst) |= ADC3PH_REG_OVERFLAW;
				}
				else
				{
					/*Update the valid flag and Raw value of Valid channel */
					MotorValidCnt ++;
				}

				Rt_cptst->AdcChl_ptst[ChlCnt_u32].AdcVf_b = ADC3PH_VADC_VALID;
				Rt_cptst->AdcChl_ptst[ChlCnt_u32].AdcRaw_u16 = (uint16)*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].ResReg_cptst) >> 2;
				VDD5REF_AN1[ChlCnt_u32]=(uint16)*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].ResReg_cptst) >> 2;

				if((Vadc_FifoDeep_u32 -ADC3PH_REG_FIFODEEP) == 2) //Read overflaw rfifo 
				{
					ADC3PH_ClearRfifo=(uint16)*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].ResReg_cptst) >> 2;
					ADC3PH_ClearRfifo=(uint16)*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].ResReg_cptst) >> 2;
					OverFour_Flag++;
				}
				if((Vadc_FifoDeep_u32 -ADC3PH_REG_FIFODEEP) == 1)
				{
					ADC3PH_ClearRfifo=(uint16)*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].ResReg_cptst) >> 2;
					OverThree_Flag++;
				}

			}
			else
			{
				Timeover_Flag++;
				for(uint32 OverCnt=0;OverCnt<Vadc_FifoDeep_u32;OverCnt++)
				{
					ADC3PH_ClearRfifo=(uint16)*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].ResReg_cptst) >> 2;
				}
				AdcChl_lptst[ChlCnt_u32].AdcVf_b = ADC3PH_VADC_INVALID;
			}
		}
		else
		{
			MotorValidCnt ++;
		}
	}

	if (MotorValidCnt == ADC3PH_OFFSET_BASE)
	{
		/*Update the valid flag of motor */
		Rt_cptst->AdcMot_ptst[MotorId_u32].MotorValid_b = ADC3PH_VADC_VALID;
	}
	else
	{
		/*Update the valid flag of motor */
		Rt_cptst->AdcMot_ptst[MotorId_u32].MotorValid_b = ADC3PH_VADC_INVALID;
	}
}

uint16 VDD5REF_AN0[3]={0};
uint16 Mcu_HV_DC1=0;
uint16 ADC3PH_SafeOverflowFlag=0;
uint16 ADC3PH_SafeClearRfifo=0;
uint16 Safe_OverFour_Flag=0;
uint16 Safe_W_OverFour_Flag=0;
uint16 Safe_OverThree_Flag=0;
uint16 Safe_Timeover_Flag=0;
uint16 Safe_Errcnt=0;
uint16 Safe_CNT=0;
ADC3PH_STATIC_ INLINE void	Adc3ph_GetSafeADCRawData
(
	const Adc3ph_CfgType *Cfg_cptst, const Adc3ph_RunTimeType *Rt_cptst, uint32 MotorId_u32
)
{
	Adc3ph_ChlDataType *AdcChl_lptst = Rt_cptst->AdcChl_ptst;

	uint32 ChlCnt_u32 = 0U;
	uint32 Vadc_Reg_u32 = 0U;
	uint32 Vadc_FifoDeep_u32 = 0U;
	uint8  MotorValidCnt = 0U;
	uint32 BaseChlIndex_u32 = MotorId_u32 * ADC3PH_OFFSET_BASE;
	uint32 EndChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_BASE;

	for (ChlCnt_u32 = BaseChlIndex_u32; ChlCnt_u32 < EndChlIndex_u32; ChlCnt_u32++)
	{
		/*Read the RES register*/
		if (AdcChl_lptst[ChlCnt_u32].AdcVf_b == ADC3PH_VADC_INVALID)
		{
			volatile uint32 Tick_Temp_u32 = 0U;
			volatile uint32 StartTick_u32 = (uint32)Gpt_Stm_LLD_GetCounter(STM0);
			while (Tick_Temp_u32 < ADC3PH_VF_POLL_TIMEOUT_CNT)
			{
				/*Read the ADC RES Register*/
				Vadc_Reg_u32 = *((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].FisrReg_cptst);
				Vadc_FifoDeep_u32= ((Vadc_Reg_u32 & ADC3PH_REG_VF_MASK)>>ADC3PH_REG_VF_SHIFT);
				/*Judge the VF Flag of RES register*/
				if (Vadc_FifoDeep_u32 >= ADC3PH_REG_FIFODEEP)
				{
					Safe_CNT++;
					break;
				}

				volatile uint32 EndTick_u32 = (uint32)Gpt_Stm_LLD_GetCounter(STM0);
                #if 0
				if (EndTick_u32 > StartTick_u32)
				{
					Tick_Temp_u32 = EndTick_u32 - StartTick_u32;
				}
				else
				{
					Tick_Temp_u32 = 0xFFFFFFFFU  - StartTick_u32 + EndTick_u32 + 1;
				}
                #else
				Tick_Temp_u32 = EndTick_u32 - StartTick_u32;
				#endif
			}

			if (Vadc_FifoDeep_u32 >= ADC3PH_REG_FIFODEEP)
			{
				/*Clear overflow flag if it is set before*/
				if(Vadc_Reg_u32 & ADC3PH_REG_OVERFLAW )
				{
					ADC3PH_SafeOverflowFlag++;
					*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].FisrReg_cptst) |= ADC3PH_REG_OVERFLAW;
				}
				else
				{
					/*Update the valid flag and Raw value of Valid channel */
					MotorValidCnt ++;
				}

				Rt_cptst->AdcChl_ptst[ChlCnt_u32].AdcVf_b = ADC3PH_VADC_VALID;
				Rt_cptst->AdcChl_ptst[ChlCnt_u32].AdcRaw_u16 = (uint16)*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].ResReg_cptst) >> 2;
				VDD5REF_AN0[ChlCnt_u32]=(uint16)*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].ResReg_cptst) >> 2;

				if((Vadc_FifoDeep_u32 -ADC3PH_REG_FIFODEEP) == 2) //Read overflaw rfifo
				{
					ADC3PH_SafeClearRfifo=(uint16)*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].ResReg_cptst) >> 2;
					ADC3PH_SafeClearRfifo=(uint16)*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].ResReg_cptst) >> 2;
					Safe_OverFour_Flag++;
				}
				if((Vadc_FifoDeep_u32 -ADC3PH_REG_FIFODEEP) == 1)
				{
					ADC3PH_SafeClearRfifo=(uint16)*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].ResReg_cptst) >> 2;
					Safe_OverThree_Flag++;
				}

			}
			else
			{
				Safe_Timeover_Flag++;
				for(uint32 OverCnt=0;OverCnt<Vadc_FifoDeep_u32;OverCnt++)
				{
					ADC3PH_SafeClearRfifo=(uint16)*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].ResReg_cptst) >> 2;
				}
				AdcChl_lptst[ChlCnt_u32].AdcVf_b = ADC3PH_VADC_INVALID;
			}

		}
		else
		{
			MotorValidCnt ++;
		}
	}

	if (MotorValidCnt == ADC3PH_OFFSET_BASE)
	{
		/*Update the valid flag of motor */
		Rt_cptst->AdcMot_ptst[MotorId_u32].MotorValid_b = ADC3PH_VADC_VALID;
	}
	else
	{
		/*Update the valid flag of motor */
		Rt_cptst->AdcMot_ptst[MotorId_u32].MotorValid_b = ADC3PH_VADC_INVALID;
	}
}

/***********************************************************************************************************************
** Function Name	: Adc3ph_CalculateADCVol
** Service ID		: None
** Sync/Async		: Synchronous
** Reentrancy		: Non_Reentrancy
** Parameter[in]	: uint32 MotorId_u32
** Parameter[inout]	: const Adc3ph_RunTimeType *Rt_cptst
** Parameter[out]	: void
** Return Value		: void
** Description		: Clear the valid flag of channel
***********************************************************************************************************************/
ADC3PH_STATIC_ void Adc3ph_ClearChannelValidFlg
(
	const Adc3ph_RunTimeType *Rt_cptst, uint32 MotorId_u32
)
{
	/*Calculate the UVW channel index*/
	uint32 BaseChlIndex_u32 = MotorId_u32 * ADC3PH_OFFSET_BASE;
	uint32 U_ChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_U;
	uint32 V_ChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_V;
	uint32 W_ChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_W;

	/*Get ADC CHL RAW*/
	Rt_cptst->AdcChl_ptst[U_ChlIndex_u32].AdcVf_b = ADC3PH_VADC_INVALID;
	Rt_cptst->AdcChl_ptst[V_ChlIndex_u32].AdcVf_b = ADC3PH_VADC_INVALID;
	Rt_cptst->AdcChl_ptst[W_ChlIndex_u32].AdcVf_b = ADC3PH_VADC_INVALID;
}

#if (ADC3PH_CFG_VOL_ENABLE == TRUE)
/***********************************************************************************************************************
** Function Name	: Adc3ph_DiagEcuVolValue
** Service ID		: None
** Sync/Async		: Synchronous
** Reentrancy		: Non_Reentrancy
** Parameter[in]	: uint32 MotorId_u32
** Parameter[inout]	: Adc3ph_RunTimeType *Rt_cptst
** Parameter[out]	: void
** Return Value		: void
** Description		: To Diagnose the ADC VOL Value  when the motor ADC valid
***********************************************************************************************************************/
ADC3PH_STATIC_ void Adc3ph_DiagEcuVolValue(const Adc3ph_RunTimeType *Rt_cptst, uint32 MotorId_u32)
{
	Adc3ph_ChlDataType *AdcChl_lptst = Rt_cptst->AdcChl_ptst;

	uint32 ChlCnt_u32 = 0U;
	uint32 BaseChlIndex_u32 = MotorId_u32 * ADC3PH_OFFSET_BASE;
	uint32 EndChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_BASE;

	/*To Diagnose the ECU VOL value of AD Valid */
	for (ChlCnt_u32 = BaseChlIndex_u32; ChlCnt_u32 < EndChlIndex_u32; ChlCnt_u32 ++)
	{
		if ((AdcChl_lptst[ChlCnt_u32].AdcVol_u32 > Adc3ph_EcuVolMax_ku32) || \
			(AdcChl_lptst[ChlCnt_u32].AdcVol_u32 < Adc3ph_EcuVolMin_ku32))
		{
			Rt_cptst->AdcMot_ptst[MotorId_u32].MotorValid_b = ADC3PH_VADC_INVALID;
			break;
		}
		else
		{
			/*for MISRA*/
		}
	}
}

/***********************************************************************************************************************
** Function Name	: Adc3ph_CalculateADCVol
** Service ID		: None
** Sync/Async		: Synchronous
** Reentrancy		: Non_Reentrancy
** Parameter[in]	: uint32 MotorId_u32
** Parameter[inout]	: const Adc3ph_RunTimeType *Rt_cptst
** Parameter[out]	: void
** Return Value		: void
** Description		: Get the ADC Voltage by ADC Raw value
***********************************************************************************************************************/
ADC3PH_STATIC_ void Adc3ph_CalculateADCVol(const Adc3ph_RunTimeType *Rt_cptst, uint32 MotorId_u32)
{

	Adc3ph_ChlDataType * AdcChl_lptst = Rt_cptst->AdcChl_ptst;

	uint32 BaseChlIndex_u32 = MotorId_u32 * ADC3PH_OFFSET_BASE;
	uint32 U_ChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_U;
	uint32 V_ChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_V;
	uint32 W_ChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_W;

	/*Get ADC CHL RAW*/
	Rt_cptst->AdcChl_ptst[U_ChlIndex_u32].AdcVol_u32 =  \
			(uint32)((float32)(AdcChl_lptst[U_ChlIndex_u32].AdcRaw_u16) * ADC3PH_CFG_VOL_CONV_RATIO);
	Rt_cptst->AdcChl_ptst[V_ChlIndex_u32].AdcVol_u32 =  \
			(uint32)((float32)(AdcChl_lptst[V_ChlIndex_u32].AdcRaw_u16) * ADC3PH_CFG_VOL_CONV_RATIO);
	Rt_cptst->AdcChl_ptst[W_ChlIndex_u32].AdcVol_u32 =  \
			(uint32)((float32)(AdcChl_lptst[W_ChlIndex_u32].AdcRaw_u16) * ADC3PH_CFG_VOL_CONV_RATIO);
}
#endif /*ADC3PH_CFG_VOL_ENABLE == TRUE*/

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

uint16 Motor_Adc3phRaw_au16[3u]= {0u,0u,0u};
uint16 Motor_Adc3phRaw_au16_Fusa[3u]= {0u,0u,0u};
uint8  Motor_Adc3phRawStu_au8[3u] = {0u,0u,0u};
uint8  Motor_Adc3phRawStu_au8_Fusa[3u] = {0u,0u,0u};
uint32 Motor_Adc3phTime = 0u;
uint32 Motor_Adc3phTime_Fusa = 0u;

void Motor_Adc3phGetRaw_100us(void)
{
    Adc3ph_GetEcuRawSig(3,
		&Motor_Adc3phRaw_au16[0],
        &Motor_Adc3phRaw_au16[1],
		&Motor_Adc3phRaw_au16[2],
		&Motor_Adc3phTime,
        &Motor_Adc3phRawStu_au8[0],3);

	Adc3ph_GetEcuRawSig(0,
		&Motor_Adc3phRaw_au16_Fusa[0],
        &Motor_Adc3phRaw_au16_Fusa[1],
		&Motor_Adc3phRaw_au16_Fusa[2],
		&Motor_Adc3phTime_Fusa,
        &Motor_Adc3phRawStu_au8_Fusa[0],0);
    
}

/* 零漂自学习相关变量 */
uint32 Motor_Adc3phSum_au32[3u] = {0u, 0u, 0u}; /* 累加三相ADC值的和 */
uint16 Motor_ZeroDriftOffset_au16[3u] = {0u, 0u, 0u}; /* 存储计算出的零漂平均值 */
uint16 Motor_ZeroDriftSampleCount_u16 = 0u;

uint16 Motor_ZeroDriftOffset_au16_Fusa[3u] = {0u, 0u, 0u}; /* 功能安全 */

uint8 Motor_DriveState_u8 = 0U;

float SGSA_Current_Zero_A_Buf[32] ;
float SGSA_Current_Zero_B_Buf[32] ;
float SGSA_Current_Zero_C_Buf[32] ;
uint8 SGSA_Current_Zero_A_Buf_Cnt = 0,SGSA_Current_Zero_B_Buf_Cnt = 0,SGSA_Current_Zero_C_Buf_Cnt = 0;
void Motor_Adc3ph_ZeroDrift_Function(void)
{
    if(Motor_ZeroDriftSampleCount_u16 < 64u)
    {	
		if(Motor_ZeroDriftSampleCount_u16 >= 32u)
        {
			Motor_Adc3phSum_au32[0] += Motor_Adc3phRaw_au16[0];
			Motor_Adc3phSum_au32[1] += Motor_Adc3phRaw_au16[1];
			Motor_Adc3phSum_au32[2] += Motor_Adc3phRaw_au16[2];
		}
        Motor_ZeroDriftSampleCount_u16++; 
    }
    else
    {
		Motor_ZeroDriftOffset_au16[0] = (uint16)(Motor_Adc3phSum_au32[0] >> 5);
        Motor_ZeroDriftOffset_au16[1] = (uint16)(Motor_Adc3phSum_au32[1] >> 5);
        Motor_ZeroDriftOffset_au16[2] = (uint16)(Motor_Adc3phSum_au32[2] >> 5);

        Motor_DriveState_u8 = 2;
    }
}


void Adc3ph_ClearRFifoEvent(uint32 CoreId_u32)
{
	const	Adc3ph_CfgType	*Cfg_cptst = &Adc3ph_CfgCont_vcatst[0U];
	const	Adc3ph_RunTimeType	*Rt_cptst = &Adc3ph_rtCont_lcatst[0U];

	uint32  MotorId_u32 = 0U;
	uint32  ChlCnt_u32 = 0U;
	uint32  Vadc_Reg_u32 = 0U;
	uint32  Vadc_FifoDeep_u32 = 0U;

	/*Point to CFG & Runtime data*/ 
	Cfg_cptst  = &Adc3ph_CfgCont_vcatst[CoreId_u32];

	uint32 BaseChlIndex_u32 = MotorId_u32 * ADC3PH_OFFSET_BASE;
	uint32 EndChlIndex_u32 = BaseChlIndex_u32 + ADC3PH_OFFSET_BASE;

	for (ChlCnt_u32 = BaseChlIndex_u32; ChlCnt_u32 < EndChlIndex_u32; ChlCnt_u32++)
	{
		/* 等待至少一轮转换完成（VF >= FIFODEEP），避免清空卡在电流/基准两通道之间 */
		volatile uint32 Tick_Temp_u32 = 0U;
		volatile uint32 StartTick_u32 = (uint32)Gpt_Stm_LLD_GetCounter(STM0);
		volatile uint32 EndTick_u32 = 0U;

		while (Tick_Temp_u32 < ADC3PH_VF_POLL_TIMEOUT_CNT)
		{
			Vadc_Reg_u32 = *((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].FisrReg_cptst);
			Vadc_FifoDeep_u32 = ((Vadc_Reg_u32 & ADC3PH_REG_VF_MASK) >> ADC3PH_REG_VF_SHIFT);
			if (Vadc_FifoDeep_u32 >= ADC3PH_REG_FIFODEEP)
			{
				break;
			}
			EndTick_u32 = (uint32)Gpt_Stm_LLD_GetCounter(STM0);
			Tick_Temp_u32 = EndTick_u32 - StartTick_u32;
		}
		
		if(Vadc_Reg_u32 & ADC3PH_REG_OVERFLAW)
		{
			*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].FisrReg_cptst) |= ADC3PH_REG_OVERFLAW;
		}

		for(uint32 OverCnt=0;OverCnt<Vadc_FifoDeep_u32;OverCnt++)
		{
			ADC3PH_ClearRfifo=(uint16)*((volatile uint32 *)Cfg_cptst->AdcSigChlCfg_cptst[ChlCnt_u32].ResReg_cptst) >> 2;
		}
	}
}


#pragma ghs section
#pragma ghs section
#pragma ghs section
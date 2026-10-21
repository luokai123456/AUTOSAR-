/****************************************************************
 * 模块：Cdd层 - ADC3PH模块
 * 版本：主版本.次版本.修订号
 * ==================== 修改记录 ====================
 * V0.1.0 (初始版本)
 * 1. 支持ADC3PH模块初始化功能
 * 2. 支持ADC3PH模块主函数功能
 * ==================================================
 ****************************************************************/
#ifndef ADC3PH_H_
#define ADC3PH_H_

/***********************************************************************************************************************
**                        				Other Header File Inclusion                    								  **
***********************************************************************************************************************/
#include "Adc3ph_Cfg.h"
#include "Compiler.h"
/***********************************************************************************************************************
**                 						Global Function Prototypes          					  		              **
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
** Return Value		: void
** Description		: Initialize the variable of runtime data and enable HW Sample Trigger of ADC Group
***********************************************************************************************************************/
extern	void	Adc3ph_Init(uint32 CoreId_u32);

/***********************************************************************************************************************
** Function Name	: Adc3ph_MainFunction
** Service ID		: None
** Sync/Async		: Synchronous
** Reentrancy		: Non_Reentrancy
** Parameter[in]	: None
** Parameter[inout]	: None
** Parameter[out]	: None
** Return Value		: void
** Description		: Read the three-phase current Raw values,Calculate the ADC Voltage value
***********************************************************************************************************************/

extern	void	Adc3ph_MainFunction(uint32 CoreId_u32);

/***********************************************************************************************************************
** Function Name	: Adc3ph_SafetyMainFunction
** Service ID		: None
** Sync/Async		: Synchronous
** Reentrancy		: Non_Reentrancy
** Parameter[in]	: None
** Parameter[inout]	: None
** Parameter[out]	: None
** Return Value		: void
** Description		: Read the Safe three-phase current Raw values,Calculate the ADC Voltage value
***********************************************************************************************************************/
extern	void	Adc3ph_SafetyMainFunction(uint32 CoreId_u32);

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
extern	void	Adc3ph_GetEcuVolSig
(
	uint8	MotorId_u8,
	uint32 *EcuVolU_pu32,
	uint32 *EcuVolV_pu32,
	uint32 *EcuVolW_pu32,
	boolean *EcuVolStu_pb
);
#endif/*#if (ADC3PH_CFG_VOL_ENABLE == TRUE)*/

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
** Parameter[out]	: uint32 *Adc_time
** Return Value		: void
** Description		: Read the Raw values and valid of three-phase current
***********************************************************************************************************************/
extern	INLINE void	Adc3ph_GetEcuRawSig
(
	uint8 MotorId_u8,
	uint16 *EcuRawU_pu16,
	uint16 *EcuRawV_pu16,
	uint16 *EcuRawW_pu16,
	uint32 *Adc_time,
	boolean *EcuRawStu_pb,
	uint32 CoreId_u32
);

#define ADC3PH_CODE_STOP
#include "Adc3ph_MemMap.h"


#define ADC3PH_CLEAR_FAR_DATA_ALIGN4_GLOBAL_START
#include "Adc3ph_MemMap.h"

#define ADC3PH_CLEAR_FAR_DATA_ALIGN4_GLOBAL_STOP
#include "Adc3ph_MemMap.h"

extern void Motor_Adc3phGetRaw_100us(void);

/* 零漂自学习相关变量 */
extern uint32 Motor_Adc3phSum_au32[3u]; /* 累加三相ADC值的和 */
extern uint16 Motor_ZeroDriftOffset_au16[3u]; /* 存储计算出的零漂平均值 */
extern uint16 Motor_ZeroDriftSampleCount_u16;/* 样本计数 */
extern uint16 Motor_ZeroDriftOffset_au16_Fusa[3u]; /* 功能安全 */

extern uint8 Motor_DriveState_u8;
extern uint32 Motor_Adc3phTime;

extern void Motor_Adc3ph_ZeroDrift_Function(void);
extern void Adc3ph_SetFifoMode(void);
extern void Adc3ph_ClearRFifoEvent(uint32 CoreId_u32);
#endif /* ADC3PH_H_ */

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


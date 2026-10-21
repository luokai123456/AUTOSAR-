/*
********************************************************************************
*
*  File name: Os_Lcfg.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date : HanCL/2021.11.23
* Change: New create.
* Cause: New
********************************************************************************
*/
#ifndef OS_LCFG_H_
#define OS_LCFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/*
********************************************************************************
*    Global Variable
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
#define OS_START_SEC_CODE 
#include "Os_MemMap.h"
extern void Os_Task_Idle_Task_Core0(void);
extern void Os_Task_Idle_Task_Core1(void);
extern void Os_Task_Idle_Task_Core2(void);
extern void Os_Task_Idle_Task_Core3(void);
extern void Os_Task_Idle_Task_Core4(void);
extern void Os_Task_Idle_Task_Core5(void);
#define OS_STOP_SEC_CODE 
#include "Os_MemMap.h"

extern void Os_Task_Default_Init_Task_Core0(void);
extern void Os_Task_App1_Task_1ms_Core0_QM(void);
extern void Os_Task_App1_Task_5ms_Core0_QM(void);
extern void Os_Task_App1_Task_10ms_Core0_QM(void);
extern void Os_Task_App1_Task_20ms_Core0_QM(void);
extern void Os_Task_App1_Task_50ms_Core0_QM(void);
extern void Os_Task_App1_Task_100ms_Core0_QM(void);
extern void Os_Task_SWC_Init_Task_Core0(void);
extern void Os_Task_Bsw_Task_10ms_Core0_QM(void);
extern void Os_Task_Bsw_Task_5ms_Core0_QM(void);
extern void Os_Task_Default_Init_Task_Core1(void);
extern void Os_Task_App1_Task_10ms_Core1_QM(void);
extern void Os_Task_SWC_Init_Task_Core1(void);
extern void Os_Task_App1_Task_1ms_Core1_QM(void);
extern void Os_Task_App1_Task_5ms_Core1_QM(void);
extern void Os_Task_App1_Task_20ms_Core1_QM(void);
extern void Os_Task_App1_Task_50ms_Core1_QM(void);
extern void Os_Task_App1_Task_100ms_Core1_QM(void);
extern void Os_Task_App1_Task_UDS_Core1_QM(void);
extern void Os_Task_Bsw_Task_10ms_Core1_QM(void);
extern void Os_Task_Default_Init_Task_Core2(void);
extern void Os_Task_App1_Task_50ms_Core2_QM(void);
extern void Os_Task_App1_Task_100ms_Core2_QM(void);
extern void Os_Task_App1_Task_10ms_Core2_QM(void);
extern void Os_Task_App1_Task_1000ms_Core2_QM(void);
extern void Os_Task_SWC_Init_Task_Core2(void);
extern void Os_Task_App1_Task_1ms_Core2_QM(void);
extern void Os_Task_App1_Task_5ms_Core2_QM(void);
extern void Os_Task_App1_Task_20ms_Core2_QM(void);
extern void Os_Task_App1_Task0_UDS_Core2_QM(void);
extern void Os_Task_App1_Task1_UDS_Core2_QM(void);
extern void Os_Task_App1_Task2_UDS_Core2_QM(void);
extern void Os_Task_Bsw_Task_10ms_Core2_QM(void);
extern void Os_Task_Default_Init_Task_Core3(void);
extern void Os_Task_SWC_Init_Task_Core3(void);
extern void Os_Task_App1_Task_UDS_Core3_QM(void);
extern void Os_Task_Task_1ms_Core3_QM(void);
extern void Os_Task_Task_100us_Core3_QM(void);
extern void Os_Task_Task_5ms_Core3_QM(void);
extern void Os_Task_Default_Init_Task_Core4(void);
extern void Os_Task_App1_Task_1ms_Core4_QM(void);
extern void Os_Task_App1_Task_5ms_Core4_QM(void);
extern void Os_Task_App1_Task_10ms_Core4_QM(void);
extern void Os_Task_App1_Task_20ms_Core4_QM(void);
extern void Os_Task_App1_Task_50ms_Core4_QM(void);
extern void Os_Task_App1_Task_100ms_Core4_QM(void);
extern void Os_Task_SWC_Init_Task_Core4(void);
extern void Os_Task_App1_Task_UDS_Core4_QM(void);
extern void Os_Task_Bsw_Task_100ms_Core4_QM(void);
extern void Os_Task_Bsw_Task_50ms_Core4_QM(void);
extern void Os_Task_Bsw_Task_20ms_Core4_QM(void);
extern void Os_Task_Bsw_Task_10ms_Core4_QM(void);
extern void Os_Task_Bsw_Task_5ms_Core4_QM(void);
extern void Os_Task_Bsw_Task_1ms_Core4_QM(void);
extern void Os_Task_Bsw_Task_5ms_Core4_Offest_QM(void);
extern void Os_Task_Bsw_Task_10ms_Core4_Offest_QM(void);
extern void Os_Task_Default_Init_Task_Core5(void);
extern void Os_Task_App1_Task_1ms_Core5_QM(void);
extern void Os_Task_App1_Task_5ms_Core5_QM(void);
extern void Os_Task_App1_Task_10ms_Core5_QM(void);
extern void Os_Task_App1_Task_20ms_Core5_QM(void);
extern void Os_Task_App1_Task_50ms_Core5_QM(void);
extern void Os_Task_App1_Task_100ms_Core5_QM(void);
extern void Os_Task_SWC_Init_Task_Core5(void);
extern void Os_Task_App1_Task_UDS_Core5_QM(void);
extern void Os_Task_App1_Task_200ms_Core5_QM(void);
extern void Os_Task_App1_Task_500ms_Core5_QM(void);
extern void Os_Task_App1_Task_1000ms_Core5_QM(void);
extern void Os_Task_Bsw_Task_10ms_Core5_QM(void);
extern void TIM6_6_W_OCP_IRQHandler(void);
extern void TIM3_4_DC_OverFault2_IRQHandler(void);
extern void TIM3_3_DC_OverFault1_IRQHandler(void);
extern void TIM3_2_U_OCP_IRQHandler(void);
extern void TIM6_5_W_HsFault_IRQHandler(void);
extern void TIM6_4_W_LsFault_IRQHandler(void);
extern void TIM6_3_V_HsFault_IRQHandler(void);
extern void TIM6_2_V_LsFault_IRQHandler(void);
extern void TIM6_1_U_HsFault_IRQHandler(void);
extern void TIM6_0_V_OCP_IRQHandler(void);
extern void TIM4_0_U_LsFault_IRQHandler(void);
extern void ATOM0_6_FOC_IRQHandler(void);
extern void TIM4_7_OCPOV_Trigger_IRQHandler(void);
extern void Os_MultiCoreServer_Handler(void);
extern void ISR_M_CAN11_1(void);
extern void ISR_M_CAN11_0(void);
extern void ISR_M_CAN6_1(void);
extern void ISR_M_CAN6_0(void);
extern void ISR_M_CAN1_1(void);
extern void ISR_M_CAN1_0(void);
extern void ISR_M_CAN9_1(void);
extern void ISR_M_CAN9_0(void);
extern void ISR_M_CAN3_1(void);
extern void ISR_M_CAN3_0(void);
extern void ISR_M_CAN2_1(void);
extern void ISR_M_CAN2_0(void);
extern void ISR_M_CAN7_1(void);
extern void ISR_M_CAN7_0(void);
extern void LINFLEX6_LLD_TXI_IRQ_HANDLER(void);
extern void LINFLEX6_LLD_RXI_IRQ_HANDLER(void);
extern void Os_MultiCoreServer_Handler(void);
extern void SDADC6_DMA_Complete_Handler(void);
#endif /* OS_LCFG_H_ */


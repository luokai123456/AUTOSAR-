/*
 * IoHwAbs_Sdadc.c
 *
 *  Created on: 2025年7月7日
 *      Author:
 */
#include "SDAdc.h"
#include "eDma.h"
#include "Pwm.h"
#include "eDMA_Cfg.h"
#include "StandardTypes.h"
#include "IoHwAbs_Sdadc.h"
#include "IoHwAbs_Sdadc_Cfg.h"
#include "intc_lld.h"
void IoHwAbs_SdAdc_Init(void)
{
    uint8 InstanceIndex = 0;
    
	// EDMA_Init(&EDma_Config);
    // INTC_LLD_Set_IRQ_Handle(DMA0_CH0_IRQn, &EDMA_Ch0_IRQHandler);
	// INTC_LLD_Set_IRQ_Handle(DMA0_CH16_IRQn, &EDMA_Ch16_IRQHandler);
    // INTC_LLD_Set_IRQ_Handle(DMA0_CH32_IRQn, &EDMA_Ch32_IRQHandler);
    // INTC_LLD_Set_IRQ_Handle(DMA0_CH48_IRQn, &EDMA_Ch48_IRQHandler);
    // INTC_LLD_Set_IRQ_Handle(DMA1_CH16_IRQn, &EDMA_Ch80_IRQHandler);
	// INTC_LLD_Set_IRQ_Priority(DMA0_CH16_IRQn, INTR_PRI_20);
    // INTC_LLD_Set_IRQ_Priority(DMA0_CH0_IRQn, INTR_PRI_20);
    // INTC_LLD_Set_IRQ_Priority(DMA0_CH32_IRQn, INTR_PRI_20);
    // INTC_LLD_Set_IRQ_Priority(DMA0_CH48_IRQn, INTR_PRI_20);
    // INTC_LLD_Set_IRQ_Priority(DMA1_CH16_IRQn, INTR_PRI_20);
	// INTC_LLD_Set_IRQ_Enable(DMA0_CH16_IRQn);
    // INTC_LLD_Set_IRQ_Enable(DMA0_CH0_IRQn);
    // INTC_LLD_Set_IRQ_Enable(DMA0_CH32_IRQn);
    // INTC_LLD_Set_IRQ_Enable(DMA0_CH48_IRQn);
    // INTC_LLD_Set_IRQ_Enable(DMA1_CH16_IRQn);

    Sdadc_Init(&SdAdc_TotalConfig);
    
    // for(InstanceIndex = 0; InstanceIndex < SDADC_INSTANCE_CDG_NUM; InstanceIndex++)
    // {
    //     Sdadc_SetupResultBuffer(InstanceIndex, IoHwAbs_SDADC_SetResultBuffer_ptr[InstanceIndex], SDADC_BUFFER_SIZE);
    //     Sdadc_StartModulation(InstanceIndex);
    // }
    
    // Pwm_Init(&Pwm_Config);
}

void IoHwAbs_SdAdc_Mainfunction(void)
{

}

// void DMA_Sdadc1_Callback(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel)
// {
// 	(void) parameter; /* PRQA S 3119 */
// 	(void) status; /* PRQA S 3119 */
// 	(void) mappedChannel;
// }
// void DMA_Sdadc0_Callback(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel)
// {
// 	(void) parameter; /* PRQA S 3119 */
// 	(void) status; /* PRQA S 3119 */
// 	(void) mappedChannel;
// }
// void DMA_Sdadc2_Callback(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel)
// {
// 	(void) parameter; /* PRQA S 3119 */
// 	(void) status; /* PRQA S 3119 */
// 	(void) mappedChannel;
// }
// void DMA_Sdadc3_Callback(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel)
// {
// 	(void) parameter; /* PRQA S 3119 */
// 	(void) status; /* PRQA S 3119 */
// 	(void) mappedChannel;
// }
// void DMA_Sdadc5_Callback(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel)
// {
// 	(void) parameter; /* PRQA S 3119 */
// 	(void) status; /* PRQA S 3119 */
// 	(void) mappedChannel;
// }






















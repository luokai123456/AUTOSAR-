/**
****************************************************************************************
 * @FilePath: SafetyPeriphTst_Cfg.h
 * @Author: CCORE
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety test Periph configuration head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/

#ifndef SAFETYPERIPHTST_CFG_H
#define SAFETYPERIPHTST_CFG_H

#ifdef __cplusplus
extern "C"{
#endif
/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/ 
#include "eqadc_lld.h"
#include "edma_lld.h"
/**
****************************************************************************************
 * @brief: Global Variables 
****************************************************************************************
*/ 

extern boolean SAF_StmstatusCheck_Stm0Chan0(void);/* parasoft-suppress MISRAC2012-RULE_8_6-a "function requirement" */
extern boolean SAF_PitstatusCheck_Pit1Chan0(void);/* parasoft-suppress MISRAC2012-RULE_8_6-a "function requirement" */

/**
****************************************************************************************
* @brief: Macros
****************************************************************************************
*/
                                                                                                            
/* STM module id used for test. */
#define SAF_STM_TEST_INSTANCE                               (0U)
/* STM module channel used for test. */
#define SAF_STM_TEST_USED_CHANNEL                           (2U)
/* STM timer monitor period(us). */
#define SAF_STM_TIMER_MONITOR_PERIOD_US                     (2000U)
/* STM timer monitor accuracy rayio(%). */
#define SAF_STM_MONITOR_ACCURACY_RATIO                      (10U)
                                                                                                                                
/* PIT module id used for test. */
#define SAF_PIT_TEST_INSTANCE                               (1U)
/* PIT module channel used for test. */
#define SAF_PIT_TEST_USED_CHANNEL                           (2U)
/* PIT timer monitor period(us). */
#define SAF_PIT_TIMER_MONITOR_PERIOD_US                     (3000U)
/* PIT timer monitor accuracy rayio(%). */
#define SAF_PIT_MONITOR_ACCURACY_RATIO                      (10U)
                                                                                                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
#ifdef CCFC3012PT

/* List of internal channels that Supervisor ADC (EQADC9) needs to detect. */
#define SAF_ADC_SUPADC_INTERNAL_CHANNEL_LIST                {SAF_EQADC_CH_VDD_LV}
/* The predicted values corresponding to the list of 
internal channels that Supervisor ADC (EQADC9) needs to detect. */
#define SAF_ADC_SUPADC_EXPECTED_VALUE_LIST                  {1200}
/* The maximum allowable error value of EQADC internal channel voltage sampling.*/
#define SAF_SUPADC_AVG_ERROR_VALUE_LIST                     {200}
#else
/* List of internal channels that Supervisor ADC (EQADC9) needs to detect. */
#define SAF_ADC_SUPADC_INTERNAL_CHANNEL_LIST                {SAF_EQADC_CH_VDD_LV}
/* The predicted values corresponding to the list of 
internal channels that Supervisor ADC (EQADC9) needs to detect. */
#define SAF_ADC_SUPADC_EXPECTED_VALUE_LIST                  {1200}
/* The maximum allowable error value of EQADC internal channel voltage sampling.*/
#define SAF_SUPADC_AVG_ERROR_VALUE_LIST                     {100}
#endif

/* List of channels that EQADC needs to detect. */
#define SAF_ADC_EQADC_CHANNEL_LIST                          {255,255,255,255,255,255,255,255,255}
/* The channel list that EQADC needs to detect corresponds to the channel list of Supervisor ADC (EQADC9). */
#define SAF_ADC_SUPADC_EQ_CHANNEL_LIST                      {255,255,255,255,255,255,255,255,255}
/* List of channels that SDADC needs to detect */
#define SAF_ADC_SDADC_CHANNEL_COUNT_LIST                    {255,255,255,255,255,255,255,255}
/* The channel list that SDADC needs to detect corresponds to the channel list of Supervisor ADC (EQADC9). */
#define SAF_ADC_SUPADC_SD_CHANNEL_LIST                      {255,255,255,255,255,255,255,255}
                                                                        
/* Supervisor ADC (EQADC9) sampling internal channel sampling times. */
#define SAF_ADC_SUPADC_SAMPLE_TIMES                         (10U)
/* EQADC channel sampling times. */
#define SAF_ADC_EQADC_SAMPLE_TIMES                          (10U)
/* SDADC channel sampling times. */
#define SAF_ADC_SDADC_SAMPLE_TIMES                          (1U)
/* Maximum allowable error value. */
#define SAF_AVG_ERROR                                       (200U)
            
/* EQADC enable/disable switch. */
#define SAF_ADC_EQADC_SUPPORTED                             (STD_ON)
#if defined(CCFC3007PT) | defined(CCFC3012PT)
/* SDADC enable/disable switch. */
#define SAF_ADC_SDADC_SUPPORTED                             (STD_OFF)
#else
#define SAF_ADC_SDADC_SUPPORTED                             (STD_OFF)
#endif

            
                                                                                                                                                                                                                                                                                                                                    
/* The number of interrupt monitors that need to be detected. */
#define SAF_INTC_MONITOR_COUNT                              (2U)
/* The interrupt number of the interrupt that needs to be detected. */
#define SAF_INTC_IRQID_LIST                                 {STM0_CH0_IRQn,PIT_1_TFLG0_IRQn}
/* The status check function that needs to be registered corresponds to the interrupt that needs to be detected. */
#define SAF_INTC_STATUS_CHECK_API                           {&SAF_StmstatusCheck_Stm0Chan0,&SAF_PitstatusCheck_Pit1Chan0}
                                                                                                                        
/* DMA monitor Channel count. */
#define SAF_DMA_MONITOR_CHAN_COUNT                           (1U)
/* DMA monitor Channel ID. */
#define SAF_DMA_MONITOR_CHAN_LIST                            {SAF_EDMA_CHN63_NUMBER}
/* Initial value of expected number of DMA transfers. */
#define SAF_DMA_EXPECTED_DONE_TIMES                          {0}
                                    
/* DMA transfer timeout. */
#define SAF_DMA_TIMEOUT                                      (100U)

/* TSENS fccu event enable config. */
#define SAF_TSENS_FCCU_EVENT_ENABLE                          (true)
                                
/* Set the high temperature threshold (degree) for TSENS. */
#define SAF_TSENS_HTD_SETTING                                (0x2e)
/* Set the low temperature threshold(degree) for TSENS. */
#define SAF_TSENS_LTD_SETTING                                (0x0a)

/* High temperature warning threshold(degrees). */
#define SAF_TSENS_HTD_WARNING_VALUE                          (105)
/* High temperature fault threshold(degrees). */
#define SAF_TSENS_HTD_FAULT_VALUE                            (120)
/* Low temperature fault threshold(degrees). */
#define SAF_TSENS_LTD_FAULT_VALUE                            (-30)
#ifdef __cplusplus
}
#endif

#endif  

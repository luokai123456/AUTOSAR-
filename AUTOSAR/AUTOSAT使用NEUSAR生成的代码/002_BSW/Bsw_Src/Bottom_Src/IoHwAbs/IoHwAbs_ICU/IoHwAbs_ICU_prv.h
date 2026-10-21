/*** create info ***********************
*@ Author : liufengyuan
*@ date :2024-12-02
*@ Description :Abstraction Layer ICU H file
**** modify info ***********************
*@ version :0.0
*@ Modifier : liufengyuan
*@ date :2024-12-02
*@ Modification Description :
初始版本
****************************************/
#ifndef IOHWABS_ICU_PRV_H
#define IOHWABS_ICU_PRV_H

/*******************************************************************************
 * Includes
 *******************************************************************************/
#include "Icu.h"
#include "IoHwAbs_ICU.h"
#include "IoHwAbs_ICU_Cfg.h"
#include "Std_Types.h"
#include "eDma.h"
#include "eMIOS_LLDriver.h"

/*******************************************************************************
 * Defines
 *******************************************************************************/
#define PWM_INPUT_DMA_MAX_CHANNELS          11U
#define PWM_INPUT_ICU_SIGNAL_MAX_CHANNELS   7U       
#define ICU_DMA_TIMESTAMP_BUFFERSIZE    50

#define PWM_INPUT_GTM_TIMTBASE                  10000000U  /* 10MHz time base for PWM input measurement */ //100MHz



#define IOHWABS_ICU_PwmIn_NUM_MAX		        18


#define ICU_PWM_CH1_DMACHANNEL				    30
#define ICU_PWM_CH3_DMACHANNEL				    106
#define ICU_PWM_CH5_DMACHANNEL				    105
#define ICU_PWM_CH6_DMACHANNEL				    31
#define ICU_PWM_CH7_DMACHANNEL				    102

#define ICU_FB1_PVF_DMACHANNEL				    103
#define ICU_FB2_PVF_DMACHANNEL				    107
#define ICU_FB4_PVF_DMACHANNEL				    104
#define ICU_FB5_PVF_DMACHANNEL				    108
#define ICU_FB6_PVF_DMACHANNEL				    101
#define ICU_FB10_PVF_DMACHANNEL				    127



extern void IoHwAbs_Icu_Init(void);

extern uint32 Icu_valBuffer_TimeStamp_Mp[PWM_INPUT_DMA_MAX_CHANNELS][ICU_DMA_TIMESTAMP_BUFFERSIZE];

extern void IoHwAbs_Icu_MainFunction(void);

extern void Icu_ConfigCmuClk_Func(void);

#endif/*IOHWABS_ICU_PRV_H*/



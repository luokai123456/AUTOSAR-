/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : edma
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*  
*****************************************************************************/

/**
*   @file    eDma_Cfg.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eDma MCAL driver.
*
*   @addtogroup eDma
*   @{
*/
/*PRQA S 0380, 3408, 1533,1509,1593 EOF*/
#ifdef __cplusplus
extern "C"{
#endif

#include "eDma.h"

#define EDMA_CFG_C_VENDOR_ID                     176
#define EDMA_CFG_C_AR_REL_MAJOR_VER              4
#define EDMA_CFG_C_AR_REL_MINOR_VER              4
#define EDMA_CFG_C_AR_REL_REV_VER                0
#define EDMA_CFG_C_SW_MAJOR_VER                  3
#define EDMA_CFG_C_SW_MINOR_VER                  0
#define EDMA_CFG_C_SW_PATCH_VER                  0

#if (MCAL_VENDOR_ID != EDMA_CFG_C_VENDOR_ID)
    #error " NON-MATCHED DATA : EDMA_CFG_C_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != EDMA_CFG_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_C_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != EDMA_CFG_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_C_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != EDMA_CFG_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_C_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != EDMA_CFG_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_C_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != EDMA_CFG_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_C_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != EDMA_CFG_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_C_SW_PATCH_VER "
#endif






#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC01_CFIFO0_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY0,
    .mappedChnConfig = EDMA_CHN0_NUMBER,
    .reqSource = DMAMUX0_EQADC0_ADC01_CFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC01_RFIFO0_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY15,
    .mappedChnConfig = EDMA_CHN1_NUMBER,
    .reqSource = DMAMUX0_EQADC0_ADC01_RFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC01_CFIFO1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY1,
    .mappedChnConfig = EDMA_CHN2_NUMBER,
    .reqSource = DMAMUX0_EQADC0_ADC01_CFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC01_RFIFO1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY14,
    .mappedChnConfig = EDMA_CHN3_NUMBER,
    .reqSource = DMAMUX0_EQADC0_ADC01_RFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC01_CFIFO2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY2,
    .mappedChnConfig = EDMA_CHN4_NUMBER,
    .reqSource = DMAMUX0_EQADC0_ADC01_CFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC01_RFIFO2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY13,
    .mappedChnConfig = EDMA_CHN5_NUMBER,
    .reqSource = DMAMUX0_EQADC0_ADC01_RFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC23_CFIFO0_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY0,
    .mappedChnConfig = EDMA_CHN16_NUMBER,
    .reqSource = DMAMUX2_EQADC1_ADC23_CFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC23_RFIFO0_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY15,
    .mappedChnConfig = EDMA_CHN17_NUMBER,
    .reqSource = DMAMUX2_EQADC1_ADC23_RFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC23_CFIFO1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY6,
    .mappedChnConfig = EDMA_CHN18_NUMBER,
    .reqSource = DMAMUX2_EQADC1_ADC23_CFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC23_RFIFO1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY10,
    .mappedChnConfig = EDMA_CHN19_NUMBER,
    .reqSource = DMAMUX2_EQADC1_ADC23_RFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC23_CFIFO2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY1,
    .mappedChnConfig = EDMA_CHN20_NUMBER,
    .reqSource = DMAMUX2_EQADC1_ADC23_CFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC23_RFIFO2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY14,
    .mappedChnConfig = EDMA_CHN21_NUMBER,
    .reqSource = DMAMUX2_EQADC1_ADC23_RFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC45_CFIFO0_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY2,
    .mappedChnConfig = EDMA_CHN24_NUMBER,
    .reqSource = DMAMUX3_EQADC2_ADC45_CFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC45_RFIFO0_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY13,
    .mappedChnConfig = EDMA_CHN25_NUMBER,
    .reqSource = DMAMUX3_EQADC2_ADC45_RFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC45_CFIFO1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY5,
    .mappedChnConfig = EDMA_CHN26_NUMBER,
    .reqSource = DMAMUX3_EQADC2_ADC45_CFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC45_RFIFO1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY9,
    .mappedChnConfig = EDMA_CHN27_NUMBER,
    .reqSource = DMAMUX3_EQADC2_ADC45_RFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC45_CFIFO2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY3,
    .mappedChnConfig = EDMA_CHN28_NUMBER,
    .reqSource = DMAMUX3_EQADC2_ADC45_CFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC45_RFIFO2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY12,
    .mappedChnConfig = EDMA_CHN29_NUMBER,
    .reqSource = DMAMUX3_EQADC2_ADC45_RFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC67_CFIFO0_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY0,
    .mappedChnConfig = EDMA_CHN32_NUMBER,
    .reqSource = DMAMUX4_EQADC3_ADC67_CFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC67_RFIFO0_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY15,
    .mappedChnConfig = EDMA_CHN33_NUMBER,
    .reqSource = DMAMUX4_EQADC3_ADC67_RFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC67_CFIFO1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY1,
    .mappedChnConfig = EDMA_CHN34_NUMBER,
    .reqSource = DMAMUX4_EQADC3_ADC67_CFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC67_RFIFO1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY14,
    .mappedChnConfig = EDMA_CHN35_NUMBER,
    .reqSource = DMAMUX4_EQADC3_ADC67_RFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC89_CFIFO0_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY0,
    .mappedChnConfig = EDMA_CHN53_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_CFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC89_RFIFO0_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY15,
    .mappedChnConfig = EDMA_CHN54_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_RFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC89_CFIFO1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY1,
    .mappedChnConfig = EDMA_CHN50_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_CFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC89_RFIFO1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY14,
    .mappedChnConfig = EDMA_CHN52_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_RFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC1011_CFIFO0_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY0,
    .mappedChnConfig = EDMA_CHN120_NUMBER,
    .reqSource = DMAMUX10_EQADC5_ADC1011_CFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC1011_RFIFO0_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY15,
    .mappedChnConfig = EDMA_CHN121_NUMBER,
    .reqSource = DMAMUX10_EQADC5_ADC1011_RFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC1011_CFIFO1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY1,
    .mappedChnConfig = EDMA_CHN122_NUMBER,
    .reqSource = DMAMUX10_EQADC5_ADC1011_CFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC1011_RFIFO1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY14,
    .mappedChnConfig = EDMA_CHN123_NUMBER,
    .reqSource = DMAMUX10_EQADC5_ADC1011_RFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC1011_CFIFO2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY2,
    .mappedChnConfig = EDMA_CHN124_NUMBER,
    .reqSource = DMAMUX10_EQADC5_ADC1011_CFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = TRUE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC1011_RFIFO2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY13,
    .mappedChnConfig = EDMA_CHN125_NUMBER,
    .reqSource = DMAMUX10_EQADC5_ADC1011_RFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_TIM7_CH5_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY11,
    .mappedChnConfig = EDMA_CHN127_NUMBER,
    .reqSource = DMAMUX10_GTM_TIM7_IRQ5,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_TIM4_CH2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY14,
    .mappedChnConfig = EDMA_CHN102_NUMBER,
    .reqSource = DMAMUX8_GTM_TIM4_IRQ2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_TIM4_CH0_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY10,
    .mappedChnConfig = EDMA_CHN100_NUMBER,
    .reqSource = DMAMUX8_GTM_TIM4_IRQ0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_TIM4_CH1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY5,
    .mappedChnConfig = EDMA_CHN101_NUMBER,
    .reqSource = DMAMUX8_GTM_TIM4_IRQ1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_TIM4_CH4_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY11,
    .mappedChnConfig = EDMA_CHN103_NUMBER,
    .reqSource = DMAMUX8_GTM_TIM4_IRQ4,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_TIM4_CH5_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY15,
    .mappedChnConfig = EDMA_CHN104_NUMBER,
    .reqSource = DMAMUX8_GTM_TIM4_IRQ5,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_TIM2_CH4_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY11,
    .mappedChnConfig = EDMA_CHN30_NUMBER,
    .reqSource = DMAMUX3_GTM_TIM2_IRQ4,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_TIM2_CH5_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY7,
    .mappedChnConfig = EDMA_CHN31_NUMBER,
    .reqSource = DMAMUX3_GTM_TIM2_IRQ5,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_TIM5_CH1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY9,
    .mappedChnConfig = EDMA_CHN105_NUMBER,
    .reqSource = DMAMUX8_GTM_TIM5_IRQ1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_TIM5_CH2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY8,
    .mappedChnConfig = EDMA_CHN106_NUMBER,
    .reqSource = DMAMUX8_GTM_TIM5_IRQ2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_TIM5_CH4_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY7,
    .mappedChnConfig = EDMA_CHN107_NUMBER,
    .reqSource = DMAMUX8_GTM_TIM5_IRQ4,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_TIM5_CH5_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY6,
    .mappedChnConfig = EDMA_CHN108_NUMBER,
    .reqSource = DMAMUX8_GTM_TIM5_IRQ5,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_SDADC_6_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY14,
    .mappedChnConfig = EDMA_CHN64_NUMBER,
    .reqSource = DMAMUX6_ADC_SD_6_EOC,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_SDADC_7_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY15,
    .mappedChnConfig = EDMA_CHN65_NUMBER,
    .reqSource = DMAMUX6_ADC_SD_7_EOC,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_SDADC_9_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY13,
    .mappedChnConfig = EDMA_CHN66_NUMBER,
    .reqSource = DMAMUX6_ADC_SD_9_EOC,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_SDADC_10_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY7,
    .mappedChnConfig = EDMA_CHN126_NUMBER,
    .reqSource = DMAMUX10_ADC_SD_10_EOC,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_LINFLEXD_1_TX_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY10,
    .mappedChnConfig = EDMA_CHN49_NUMBER,
    .reqSource = DMAMUX5_LINFLEXD_1_TX,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_LINFLEXD_1_RX_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY9,
    .mappedChnConfig = EDMA_CHN48_NUMBER,
    .reqSource = DMAMUX5_LINFLEXD_1_RX,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_LINFLEXD_3_TX_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY13,
    .mappedChnConfig = EDMA_CHN98_NUMBER,
    .reqSource = DMAMUX8_LINFLEXD_3_TX,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_LINFLEXD_3_RX_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY12,
    .mappedChnConfig = EDMA_CHN99_NUMBER,
    .reqSource = DMAMUX8_LINFLEXD_3_RX,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC01_CFIFO3_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY3,
    .mappedChnConfig = EDMA_CHN6_NUMBER,
    .reqSource = DMAMUX0_EQADC0_ADC01_CFIFO3,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC01_RFIFO3_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY12,
    .mappedChnConfig = EDMA_CHN7_NUMBER,
    .reqSource = DMAMUX0_EQADC0_ADC01_RFIFO3,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC67_CFIFO3_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY5,
    .mappedChnConfig = EDMA_CHN37_NUMBER,
    .reqSource = DMAMUX4_EQADC3_ADC67_CFIFO3,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC67_RFIFO3_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY10,
    .mappedChnConfig = EDMA_CHN38_NUMBER,
    .reqSource = DMAMUX4_EQADC3_ADC67_RFIFO3,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC89_CFIFO3_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY2,
    .mappedChnConfig = EDMA_CHN57_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_CFIFO3,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC89_RFIFO3_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY13,
    .mappedChnConfig = EDMA_CHN58_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_RFIFO3,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC89_CFIFO4_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY3,
    .mappedChnConfig = EDMA_CHN59_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_CFIFO4,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC89_RFIFO4_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY12,
    .mappedChnConfig = EDMA_CHN60_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_RFIFO4,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC89_CFIFO5_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY4,
    .mappedChnConfig = EDMA_CHN61_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_CFIFO5,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC89_RFIFO5_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY11,
    .mappedChnConfig = EDMA_CHN62_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_RFIFO5,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC89_CFIFO2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY6,
    .mappedChnConfig = EDMA_CHN55_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_CFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC89_RFIFO2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY8,
    .mappedChnConfig = EDMA_CHN56_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_RFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC23_CFIFO3_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY4,
    .mappedChnConfig = EDMA_CHN22_NUMBER,
    .reqSource = DMAMUX2_EQADC1_ADC23_CFIFO3,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC23_RFIFO3_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY8,
    .mappedChnConfig = EDMA_CHN23_NUMBER,
    .reqSource = DMAMUX2_EQADC1_ADC23_RFIFO3,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC67_CFIFO4_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY6,
    .mappedChnConfig = EDMA_CHN39_NUMBER,
    .reqSource = DMAMUX4_EQADC3_ADC67_CFIFO4,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC67_RFIFO4_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY9,
    .mappedChnConfig = EDMA_CHN40_NUMBER,
    .reqSource = DMAMUX4_EQADC3_ADC67_RFIFO4,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC67_CFIFO2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY7,
    .mappedChnConfig = EDMA_CHN41_NUMBER,
    .reqSource = DMAMUX4_EQADC3_ADC67_CFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_INIT
#include "eDma_MemMap.h"
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_ADC67_RFIFO2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY8,
    .mappedChnConfig = EDMA_CHN42_NUMBER,
    .reqSource = DMAMUX4_EQADC3_ADC67_RFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .errCallback = NULL_PTR,
    .errCallbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
#define EDMA_STOP_SEC_VAR_INIT
#include "eDma_MemMap.h"


#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC01_CFIFO0_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC01_RFIFO0_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC01_CFIFO1_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC01_RFIFO1_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC01_CFIFO2_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC01_RFIFO2_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC23_CFIFO0_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC23_RFIFO0_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC23_CFIFO1_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC23_RFIFO1_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC23_CFIFO2_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC23_RFIFO2_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC45_CFIFO0_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC45_RFIFO0_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC45_CFIFO1_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC45_RFIFO1_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC45_CFIFO2_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC45_RFIFO2_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC67_CFIFO0_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC67_RFIFO0_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC67_CFIFO1_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC67_RFIFO1_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC89_CFIFO0_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC89_RFIFO0_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC89_CFIFO1_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC89_RFIFO1_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC1011_CFIFO0_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC1011_RFIFO0_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC1011_CFIFO1_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC1011_RFIFO1_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC1011_CFIFO2_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC1011_RFIFO2_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_TIM7_CH5_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_TIM4_CH2_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_TIM4_CH0_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_TIM4_CH1_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_TIM4_CH4_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_TIM4_CH5_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_TIM2_CH4_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_TIM2_CH5_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_TIM5_CH1_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_TIM5_CH2_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_TIM5_CH4_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_TIM5_CH5_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_SDADC_6_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_SDADC_7_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_SDADC_9_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_SDADC_10_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_LINFLEXD_1_TX_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_LINFLEXD_1_RX_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_LINFLEXD_3_TX_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_LINFLEXD_3_RX_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC01_CFIFO3_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC01_RFIFO3_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC67_CFIFO3_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC67_RFIFO3_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC89_CFIFO3_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC89_RFIFO3_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC89_CFIFO4_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC89_RFIFO4_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC89_CFIFO5_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC89_RFIFO5_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC89_CFIFO2_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC89_RFIFO2_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC23_CFIFO3_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC23_RFIFO3_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC67_CFIFO4_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC67_RFIFO4_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC67_CFIFO2_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
#define EDMA_START_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_ADC67_RFIFO2_State;
#define EDMA_STOP_SEC_VAR_NO_INIT
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CONFIG_DATA
#include "eDma_MemMap.h"
CONST(eDMAModuleConfigType, EDMA_CONST) dmaconfigure_InitConfig[EDMA_INSTANCE_COUNT] = {
    {
        .setChnArbitMode = EDMA_ARBITRATION_MODE_FIXED_PRIORITY,
        .groupArbitration = EDMA_ARBITRATION_MODE_FIXED_PRIORITY,
        .prioGroup0 = EDMA_GRP_PRIORITY0,
        .prioGroup1 = EDMA_GRP_PRIORITY1,
        .prioGroup2 = EDMA_GRP_PRIORITY2,
        .prioGroup3 = EDMA_GRP_PRIORITY3,
        .haltOnError = FALSE
    },
    {
        .setChnArbitMode = EDMA_ARBITRATION_MODE_FIXED_PRIORITY,
        .groupArbitration = EDMA_ARBITRATION_MODE_FIXED_PRIORITY,
        .prioGroup0 = EDMA_GRP_PRIORITY0,
        .prioGroup1 = EDMA_GRP_PRIORITY1,
        .prioGroup2 = EDMA_GRP_PRIORITY2,
        .prioGroup3 = EDMA_GRP_PRIORITY3,
        .haltOnError = FALSE
    },
};
#define EDMA_STOP_SEC_CONFIG_DATA
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CONFIG_DATA
#include "eDma_MemMap.h"
CONST(eDMAChPriorityCfg, EDMA_CONST) dmaChPriorityCfgs[EDMA_TOTAL_CHANNELS] = {
    {
        .channel = EDMA_CHN0_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN1_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
    {
        .channel = EDMA_CHN2_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN3_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN4_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN5_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN6_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN7_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN8_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN9_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN10_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN11_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN12_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN13_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN14_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN15_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
    {
        .channel = EDMA_CHN16_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN17_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
    {
        .channel = EDMA_CHN18_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN19_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN20_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN21_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN22_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN23_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN24_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN25_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN26_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN27_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN28_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN29_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN30_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
    {
        .channel = EDMA_CHN31_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN32_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN33_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
    {
        .channel = EDMA_CHN34_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN35_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN36_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN37_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN38_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN39_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN40_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN41_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN42_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN43_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN44_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN45_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
    {
        .channel = EDMA_CHN46_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN47_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN48_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN49_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN50_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN51_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN52_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN53_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN54_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
    {
        .channel = EDMA_CHN55_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN56_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN57_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN58_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN59_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN60_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN61_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN62_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
    {
        .channel = EDMA_CHN63_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN64_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN65_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
    {
        .channel = EDMA_CHN66_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN67_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN68_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN69_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN70_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN71_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN72_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN73_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN74_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN75_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN76_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN77_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN78_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
    {
        .channel = EDMA_CHN79_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN80_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN81_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN82_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN83_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN84_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN85_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN86_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN87_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN88_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN89_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN90_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN91_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
    {
        .channel = EDMA_CHN92_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN93_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN94_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN95_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
    {
        .channel = EDMA_CHN96_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN97_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN98_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN99_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN100_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN101_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN102_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN103_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
    {
        .channel = EDMA_CHN104_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
    {
        .channel = EDMA_CHN105_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN106_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN107_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN108_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN109_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN110_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN111_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN112_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN113_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN114_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN115_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN116_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN117_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN118_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN119_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN120_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN121_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
    {
        .channel = EDMA_CHN122_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN123_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN124_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN125_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN126_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN127_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
};
#define EDMA_STOP_SEC_CONFIG_DATA
#include "eDma_MemMap.h"

#define EDMA_START_SEC_CONFIG_DATA
#include "eDma_MemMap.h"
CONST(EDma_ConfigType, EDMA_CONST) EDma_Config =
{
    .pEdma_DeviceConfig = dmaconfigure_InitConfig,
    .pEdma_ChStateArray = {
        &eDmaChannelConfig_ADC01_CFIFO0_State,
        &eDmaChannelConfig_ADC01_RFIFO0_State,
        &eDmaChannelConfig_ADC01_CFIFO1_State,
        &eDmaChannelConfig_ADC01_RFIFO1_State,
        &eDmaChannelConfig_ADC01_CFIFO2_State,
        &eDmaChannelConfig_ADC01_RFIFO2_State,
        &eDmaChannelConfig_ADC23_CFIFO0_State,
        &eDmaChannelConfig_ADC23_RFIFO0_State,
        &eDmaChannelConfig_ADC23_CFIFO1_State,
        &eDmaChannelConfig_ADC23_RFIFO1_State,
        &eDmaChannelConfig_ADC23_CFIFO2_State,
        &eDmaChannelConfig_ADC23_RFIFO2_State,
        &eDmaChannelConfig_ADC45_CFIFO0_State,
        &eDmaChannelConfig_ADC45_RFIFO0_State,
        &eDmaChannelConfig_ADC45_CFIFO1_State,
        &eDmaChannelConfig_ADC45_RFIFO1_State,
        &eDmaChannelConfig_ADC45_CFIFO2_State,
        &eDmaChannelConfig_ADC45_RFIFO2_State,
        &eDmaChannelConfig_ADC67_CFIFO0_State,
        &eDmaChannelConfig_ADC67_RFIFO0_State,
        &eDmaChannelConfig_ADC67_CFIFO1_State,
        &eDmaChannelConfig_ADC67_RFIFO1_State,
        &eDmaChannelConfig_ADC89_CFIFO0_State,
        &eDmaChannelConfig_ADC89_RFIFO0_State,
        &eDmaChannelConfig_ADC89_CFIFO1_State,
        &eDmaChannelConfig_ADC89_RFIFO1_State,
        &eDmaChannelConfig_ADC1011_CFIFO0_State,
        &eDmaChannelConfig_ADC1011_RFIFO0_State,
        &eDmaChannelConfig_ADC1011_CFIFO1_State,
        &eDmaChannelConfig_ADC1011_RFIFO1_State,
        &eDmaChannelConfig_ADC1011_CFIFO2_State,
        &eDmaChannelConfig_ADC1011_RFIFO2_State,
        &eDmaChannelConfig_TIM7_CH5_State,
        &eDmaChannelConfig_TIM4_CH2_State,
        &eDmaChannelConfig_TIM4_CH0_State,
        &eDmaChannelConfig_TIM4_CH1_State,
        &eDmaChannelConfig_TIM4_CH4_State,
        &eDmaChannelConfig_TIM4_CH5_State,
        &eDmaChannelConfig_TIM2_CH4_State,
        &eDmaChannelConfig_TIM2_CH5_State,
        &eDmaChannelConfig_TIM5_CH1_State,
        &eDmaChannelConfig_TIM5_CH2_State,
        &eDmaChannelConfig_TIM5_CH4_State,
        &eDmaChannelConfig_TIM5_CH5_State,
        &eDmaChannelConfig_SDADC_6_State,
        &eDmaChannelConfig_SDADC_7_State,
        &eDmaChannelConfig_SDADC_9_State,
        &eDmaChannelConfig_SDADC_10_State,
        &eDmaChannelConfig_LINFLEXD_1_TX_State,
        &eDmaChannelConfig_LINFLEXD_1_RX_State,
        &eDmaChannelConfig_LINFLEXD_3_TX_State,
        &eDmaChannelConfig_LINFLEXD_3_RX_State,
        &eDmaChannelConfig_ADC01_CFIFO3_State,
        &eDmaChannelConfig_ADC01_RFIFO3_State,
        &eDmaChannelConfig_ADC67_CFIFO3_State,
        &eDmaChannelConfig_ADC67_RFIFO3_State,
        &eDmaChannelConfig_ADC89_CFIFO3_State,
        &eDmaChannelConfig_ADC89_RFIFO3_State,
        &eDmaChannelConfig_ADC89_CFIFO4_State,
        &eDmaChannelConfig_ADC89_RFIFO4_State,
        &eDmaChannelConfig_ADC89_CFIFO5_State,
        &eDmaChannelConfig_ADC89_RFIFO5_State,
        &eDmaChannelConfig_ADC89_CFIFO2_State,
        &eDmaChannelConfig_ADC89_RFIFO2_State,
        &eDmaChannelConfig_ADC23_CFIFO3_State,
        &eDmaChannelConfig_ADC23_RFIFO3_State,
        &eDmaChannelConfig_ADC67_CFIFO4_State,
        &eDmaChannelConfig_ADC67_RFIFO4_State,
        &eDmaChannelConfig_ADC67_CFIFO2_State,
        &eDmaChannelConfig_ADC67_RFIFO2_State,
    },
    .pEdma_ChanelConfig = {
        &eDmaChannelConfig_ADC01_CFIFO0_Config,
        &eDmaChannelConfig_ADC01_RFIFO0_Config,
        &eDmaChannelConfig_ADC01_CFIFO1_Config,
        &eDmaChannelConfig_ADC01_RFIFO1_Config,
        &eDmaChannelConfig_ADC01_CFIFO2_Config,
        &eDmaChannelConfig_ADC01_RFIFO2_Config,
        &eDmaChannelConfig_ADC23_CFIFO0_Config,
        &eDmaChannelConfig_ADC23_RFIFO0_Config,
        &eDmaChannelConfig_ADC23_CFIFO1_Config,
        &eDmaChannelConfig_ADC23_RFIFO1_Config,
        &eDmaChannelConfig_ADC23_CFIFO2_Config,
        &eDmaChannelConfig_ADC23_RFIFO2_Config,
        &eDmaChannelConfig_ADC45_CFIFO0_Config,
        &eDmaChannelConfig_ADC45_RFIFO0_Config,
        &eDmaChannelConfig_ADC45_CFIFO1_Config,
        &eDmaChannelConfig_ADC45_RFIFO1_Config,
        &eDmaChannelConfig_ADC45_CFIFO2_Config,
        &eDmaChannelConfig_ADC45_RFIFO2_Config,
        &eDmaChannelConfig_ADC67_CFIFO0_Config,
        &eDmaChannelConfig_ADC67_RFIFO0_Config,
        &eDmaChannelConfig_ADC67_CFIFO1_Config,
        &eDmaChannelConfig_ADC67_RFIFO1_Config,
        &eDmaChannelConfig_ADC89_CFIFO0_Config,
        &eDmaChannelConfig_ADC89_RFIFO0_Config,
        &eDmaChannelConfig_ADC89_CFIFO1_Config,
        &eDmaChannelConfig_ADC89_RFIFO1_Config,
        &eDmaChannelConfig_ADC1011_CFIFO0_Config,
        &eDmaChannelConfig_ADC1011_RFIFO0_Config,
        &eDmaChannelConfig_ADC1011_CFIFO1_Config,
        &eDmaChannelConfig_ADC1011_RFIFO1_Config,
        &eDmaChannelConfig_ADC1011_CFIFO2_Config,
        &eDmaChannelConfig_ADC1011_RFIFO2_Config,
        &eDmaChannelConfig_TIM7_CH5_Config,
        &eDmaChannelConfig_TIM4_CH2_Config,
        &eDmaChannelConfig_TIM4_CH0_Config,
        &eDmaChannelConfig_TIM4_CH1_Config,
        &eDmaChannelConfig_TIM4_CH4_Config,
        &eDmaChannelConfig_TIM4_CH5_Config,
        &eDmaChannelConfig_TIM2_CH4_Config,
        &eDmaChannelConfig_TIM2_CH5_Config,
        &eDmaChannelConfig_TIM5_CH1_Config,
        &eDmaChannelConfig_TIM5_CH2_Config,
        &eDmaChannelConfig_TIM5_CH4_Config,
        &eDmaChannelConfig_TIM5_CH5_Config,
        &eDmaChannelConfig_SDADC_6_Config,
        &eDmaChannelConfig_SDADC_7_Config,
        &eDmaChannelConfig_SDADC_9_Config,
        &eDmaChannelConfig_SDADC_10_Config,
        &eDmaChannelConfig_LINFLEXD_1_TX_Config,
        &eDmaChannelConfig_LINFLEXD_1_RX_Config,
        &eDmaChannelConfig_LINFLEXD_3_TX_Config,
        &eDmaChannelConfig_LINFLEXD_3_RX_Config,
        &eDmaChannelConfig_ADC01_CFIFO3_Config,
        &eDmaChannelConfig_ADC01_RFIFO3_Config,
        &eDmaChannelConfig_ADC67_CFIFO3_Config,
        &eDmaChannelConfig_ADC67_RFIFO3_Config,
        &eDmaChannelConfig_ADC89_CFIFO3_Config,
        &eDmaChannelConfig_ADC89_RFIFO3_Config,
        &eDmaChannelConfig_ADC89_CFIFO4_Config,
        &eDmaChannelConfig_ADC89_RFIFO4_Config,
        &eDmaChannelConfig_ADC89_CFIFO5_Config,
        &eDmaChannelConfig_ADC89_RFIFO5_Config,
        &eDmaChannelConfig_ADC89_CFIFO2_Config,
        &eDmaChannelConfig_ADC89_RFIFO2_Config,
        &eDmaChannelConfig_ADC23_CFIFO3_Config,
        &eDmaChannelConfig_ADC23_RFIFO3_Config,
        &eDmaChannelConfig_ADC67_CFIFO4_Config,
        &eDmaChannelConfig_ADC67_RFIFO4_Config,
        &eDmaChannelConfig_ADC67_CFIFO2_Config,
        &eDmaChannelConfig_ADC67_RFIFO2_Config,
    },
    .u32Edma_ChanelCnt = 70U,
    .pEdma_ChPriorityCfgs = dmaChPriorityCfgs
};
#define EDMA_STOP_SEC_CONFIG_DATA
#include "eDma_MemMap.h"

#ifdef __cplusplus
}
#endif

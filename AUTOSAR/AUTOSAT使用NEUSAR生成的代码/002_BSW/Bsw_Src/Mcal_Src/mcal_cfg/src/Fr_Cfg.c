/* PRQA S 0380, 3408, 0315, 0704 EOF */
/****************************************************************************
 *
 * Copyright (c) 2023  C*Core -   All Rights Reserved
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *   Project              : AUTOSAR 4.4.0 MCAL
 *   Platform             : PowerPC e200
 *   Peripheral           : Fr
 *   Dependencies         : -
 *
 *   Autosar Version      : 4.4.0
 *   Autosar Revision     : ASR_REL_4_3_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           :
 *   Build Version        :
 *
 *****************************************************************************/

/**
 *   @file    Fr_Cfg.c
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
 *   @details Autosar layer of Fr MCAL driver.
 *
 *   @addtogroup Fr
 *   @{
 */
#ifdef __cplusplus
extern "C" {
#endif
#include "derivative.h"
#ifdef RESOURCE_SUPPORT_FLEXRAY
#include "Fr_Cfg.h"
#include "Fr.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/* Version and Check Begin */
/* Version Info Begin */
#define FR_CFG_VENDOR_ID_C                          176
#define FR_CFG_AR_RELEASE_MAJOR_VERSION_C           4
#define FR_CFG_AR_RELEASE_MINOR_VERSION_C           4
#define FR_CFG_AR_RELEASE_REVISION_VERSION_C        0
#define FR_CFG_SW_MAJOR_VERSION_C                   3
#define FR_CFG_SW_MINOR_VERSION_C                   0
#define FR_CFG_SW_PATCH_VERSION_C                   0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr.h header file are of the same vendor */
#if(FR_CFG_VENDOR_ID_C != FR_H_VENDOR_ID)
    #error "Fr_PBCfg.c and Fr.h have different Vendor IDs"
#endif
/* Check if current file and Fr.h header file are of the same Autosar version */
#if((FR_AR_RELEASE_MAJOR_VERSION    != FR_CFG_AR_RELEASE_MAJOR_VERSION_C) || \
    (FR_AR_RELEASE_MINOR_VERSION    != FR_CFG_AR_RELEASE_MINOR_VERSION_C) || \
    (FR_H_AR_RELEASE_REVISION_VERSION != FR_CFG_AR_RELEASE_REVISION_VERSION_C))
    #error "AutoSar Version Numbers of Fr_PBCfg.c and Fr.h are different"
#endif
/* Check if current file and Fr.h header file are of the same software version */
#if((FR_H_SW_MAJOR_VERSION != FR_CFG_SW_MAJOR_VERSION_C) || \
    (FR_H_SW_MINOR_VERSION != FR_CFG_SW_MINOR_VERSION_C) || \
    (FR_H_SW_PATCH_VERSION != FR_CFG_SW_PATCH_VERSION_C))
    #error "Software Version Numbers of Fr_PBCfg.c and Fr.h are different"
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/






  

#define FR_START_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
const Fr_low_level_config_type Fr_low_level_cfg_set_ecu0 =
{    
    10U,       /* FrIfGColdStartAttempts */
    1U,      /* FrIfGdActionPointOffset */
    81U,       /* FrIfGdCasRxLowMax */         
    0U,       /* FrIfGdDynamicSlotIdlePhase */  
    2U,                    /* FrIfGdMinislot */
    1U,    /* FrIfGdMiniSlotActionPointOffset */
    45U,               /* FrIfGdStaticSlot */    
    0U,           /* FrIfGdSymbolWindow */      
    6U,        /* FrIfGdTSSTransmitter */      
    59U,           /* FrIfGdWakeupRxIdle */    
    55U,                /* FrIfGdWakeupRxLow */ 
    301U,        /* FrIfGdWakeupRxWindow */
    180U,        /* FrIfGdWakeupTxIdle */
    60U,         /* FrIfGdWakeupTxActive */
    4U,          /* FrIfGListenNoise */
    650U,       /* FrIfGMacroPerCycle */
    2U,       /* FrIfGMaxWithoutClockCorrectPassive */         
    2U,         /* FrIfGMaxWithoutClockCorrectFatal */
    98U,         /* FrIfGNumberOfMinislots */
    10U,        /* FrIfGNumberOfStaticSlots */
    647U,               /* FrPOffsetCorrectionStart */     
    16U,       /* FrIfGPayloadLengthStatic */         
    8U,          /* FrIfGSyncFrameIDCountMax */
    2U,         /* FrIfGNetworkManagementVectorLength */
    TRUE,        /* FrPAllowHaltDueToClock */
    0U,           /* FrPAllowPassiveToActive */    
    FR_CHANNEL_AB,                 /* FrPChannels */                  
    69U,       /* FrPdAcceptedStartupRange */       
    8U,             /* FrPClusterDriftDamping */     
    36U,                  /* FrPDecodingCorrection */
    0U,                 /* FrPDelayCompensationA */
    0U,                /* FrPDelayCompensationB */         
    52158U,                /* FrPdListenTimeout */    
    79U,        /* FrPRateCorrectionOut */
    0U,          /* P_EXTERN_OFFSET_CORRECTION */
    0U,          /* P_EXTERN_RATE_CORRECTION */
    1U,              /* FrPKeySlotId */            
    TRUE,       /* FrPKeySlotUsedForStartup */          
    TRUE,              /* FrPKeySlotUsedForSync */     
    242U,       /* P_KEY_SLOT_HEADER_CRC */
    76U,                       /* FrPLatestTx */   
    2U,                /* FrPMacroInitialOffsetA */  
    2U,              /* FrPMacroInitialOffsetB */
    4U,                  /* FrPMicroInitialOffsetA */ 
    4U,                /* FrPMicroInitialOffsetB */
    26000U,                     /* FrPMicroPerCycle */
    34U,                /* FrPOffsetCorrectionOut */
    79U,                    /* FrPRateCorrectionOut */
    FALSE,          /* FrPKeySlotOnlyEnabled */      
    FR_CHANNEL_A,                                 /* FrPWakeupChannel */                               
    63U,                     /* FrPWakeupPattern */
    40U,     /* FrPMicroPerCycle/FrIfGMacroPerCycle */
    0U         /* FrPPayloadLengthDynMax */
};
#define FR_STOP_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
#define FR_START_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
  const Fr_index_selector_type Fr_buffer_cfg_set_ctrl[] =
{
    0U,
    1U,
    2U,
    3U,
    4U,
    5U,
    6U,
    FR_LAST_MB
};
#define FR_STOP_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
#define FR_START_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
const Fr_FIFO_config_type Fr_Ctrl0_FIFO_FR_CHANNEL_A_cfg =
{
  FR_CHANNEL_A,                   /* FrChannels */            
  32,                  /* FrFifoDepth */
  0U,          /* FIFO entry size */                                       
  0,              /* FrMsgIdMatch */
  0,              /* FrMsgIdMask */
  0U,                                            /* FIFO frame ID rejection filter value */
  0x07FFU,                                       /*  FIFO_frame_ID_rejection_filter_mask */
  {
    {TRUE, FR_ACCEPTANCE, 3U, 16U},
    {FALSE, FR_ACCEPTANCE, 0U, 0U}, /* Range filter disabled */
    {FALSE, FR_ACCEPTANCE, 0U, 0U}, /* Range filter disabled */
    {FALSE, FR_ACCEPTANCE, 0U, 0U} /* Range filter disabled */
  },
  TRUE
};
#define FR_STOP_SEC_CONFIG_DATA
#include "Fr_MemMap.h"

#define FR_START_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
const Fr_transmit_buffer_config_type Fr_tx_buffer_slot_1_cfg_ctrl =
{
  1U,                           /* Transmit frame ID */
  242U,                                                                                /* Header CRC */
  16U,                          /* Payload length */
  FR_SINGLE_TRANSMIT_BUFFER,   /* Transmit MB buffering */
  FR_EVENT_TRANSMISSION_MODE,  /* Transmission mode */
  FR_STREAMING_COMMIT_MODE,    /* Transmission commit mode */
  FR_CHANNEL_A,   /* Transmit channels */
  FALSE,  /* Payload preamble disabled */
  FALSE,    /* Cycle counter filtering disabled */
  0U,    /* Cycle counter filter match value */
  0x00U,   /* Cycle counter filter mask (repetition each 1 cycles) */                       
  TRUE,   /*  Transmit MB interrupt enable*/
  FALSE   /*  FALSE - interrupt is enabled at commit side, TRUE - interrupt is enabled at transmit side*/
};
#define FR_STOP_SEC_CONFIG_DATA
#include "Fr_MemMap.h"

#define FR_START_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
const Fr_transmit_buffer_config_type Fr_tx_buffer_slot_3_cfg_ctrl =
{
  3U,                           /* Transmit frame ID */
  1083U,                                                                                /* Header CRC */
  16U,                          /* Payload length */
  FR_SINGLE_TRANSMIT_BUFFER,   /* Transmit MB buffering */
  FR_EVENT_TRANSMISSION_MODE,  /* Transmission mode */
  FR_STREAMING_COMMIT_MODE,    /* Transmission commit mode */
  FR_CHANNEL_A,   /* Transmit channels */
  FALSE,  /* Payload preamble disabled */
  FALSE,    /* Cycle counter filtering disabled */
  0U,    /* Cycle counter filter match value */
  0x00U,   /* Cycle counter filter mask (repetition each 1 cycles) */                       
  TRUE,   /*  Transmit MB interrupt enable*/
  FALSE   /*  FALSE - interrupt is enabled at commit side, TRUE - interrupt is enabled at transmit side*/
};
#define FR_STOP_SEC_CONFIG_DATA
#include "Fr_MemMap.h"

#define FR_START_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
const Fr_receive_buffer_config_type  Fr_rx_buffer_slot_4_cfg_ctrl =
{
  4U,        /* Receive frame ID */
  32U,        /* FrIfLSduLength */
  FR_CHANNEL_A,    /* Reception on channel A enabled */

  FALSE,  /* Cycle counter filtering disabled */
  0U, /* Cycle counter filter match value */
  0x00U, /* Cycle counter filter mask (repetition each 1 cycles) */      
  TRUE  /* Receive MB interrupt enable */
};
#define FR_STOP_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
  
#define FR_START_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
const Fr_transmit_buffer_config_type Fr_tx_buffer_slot_5_cfg_ctrl =
{
  5U,                           /* Transmit frame ID */
  5U,                                                                                /* Header CRC */
  16U,                          /* Payload length */
  FR_SINGLE_TRANSMIT_BUFFER,   /* Transmit MB buffering */
  FR_EVENT_TRANSMISSION_MODE,  /* Transmission mode */
  FR_STREAMING_COMMIT_MODE,    /* Transmission commit mode */
  FR_CHANNEL_A,   /* Transmit channels */
  FALSE,  /* Payload preamble disabled */
  FALSE,    /* Cycle counter filtering disabled */
  0U,    /* Cycle counter filter match value */
  0x00U,   /* Cycle counter filter mask (repetition each 1 cycles) */                       
  TRUE,   /*  Transmit MB interrupt enable*/
  FALSE   /*  FALSE - interrupt is enabled at commit side, TRUE - interrupt is enabled at transmit side*/
};
#define FR_STOP_SEC_CONFIG_DATA
#include "Fr_MemMap.h"

#define FR_START_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
const Fr_receive_buffer_config_type  Fr_rx_buffer_slot_6_cfg_ctrl =
{
  6U,        /* Receive frame ID */
  32U,        /* FrIfLSduLength */
  FR_CHANNEL_A,    /* Reception on channel A enabled */

  FALSE,  /* Cycle counter filtering disabled */
  0U, /* Cycle counter filter match value */
  0x00U, /* Cycle counter filter mask (repetition each 1 cycles) */      
  TRUE  /* Receive MB interrupt enable */
};
#define FR_STOP_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
  
#define FR_START_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
const Fr_receive_shadow_buffers_config_type Fr_rx_shadow_cfg =
{
  TRUE,       /* Rx shadow buffer for channel A, seg 1 - enabled?*/
  FALSE,
  TRUE,       /* Rx shadow buffer for channel B, seg 1 - enabled?*/
  FALSE,
  5U, /* Ch A, seg 1 -  */
  7U, /* Ch A, seg 2 -  */
  6U, /* Ch B, seg 1 -  */
  8U  /* Ch B, seg 2 -  */
};
#define FR_STOP_SEC_CONFIG_DATA
#include "Fr_MemMap.h"


#define FR_START_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
const Fr_buffer_info_type Fr_buffer_cfg[] =
{
  {FR_TRANSMIT_BUFFER, &Fr_tx_buffer_slot_1_cfg_ctrl, 0U, TRUE},
  {FR_TRANSMIT_BUFFER, &Fr_tx_buffer_slot_3_cfg_ctrl, 1U, TRUE},
  {FR_RECEIVE_BUFFER, &Fr_rx_buffer_slot_4_cfg_ctrl, 2U, TRUE},
  {FR_TRANSMIT_BUFFER, &Fr_tx_buffer_slot_5_cfg_ctrl, 3U, TRUE},
  {FR_RECEIVE_BUFFER, &Fr_rx_buffer_slot_6_cfg_ctrl, 4U, TRUE},
  {FR_RECEIVE_SHADOW, &Fr_rx_shadow_cfg, 0U, FALSE},
  {FR_RECEIVE_FIFO, &Fr_Ctrl0_FIFO_FR_CHANNEL_A_cfg, 9U, FALSE},
  {.buffer_config_ptr = NULL}
};
#define FR_STOP_SEC_CONFIG_DATA
#include "Fr_MemMap.h"


#define FR_START_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
const Fr_DemErrorType Fr_DemError =
{
    FALSE,
    0    // ID of DEM message
};
#define FR_STOP_SEC_CONFIG_DATA
#include "Fr_MemMap.h"


#define FR_START_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
const Fr_HW_config_type Fr_HW_cfg_1 =
{
  0xffe50000U, /* Controller base address*/
  0x40080000U,  /* cc memory base address (MB headers start at this address)*/
  FALSE,  /* Synchronization filtering*/
  FR_EXTERNAL_OSCILLATOR, /*ClockSource*/
  0U,   /* Bus speed: 10 Mb/s */
  16U, /* Data size in buffers segment 1 - gPayloadLengthStatic */
  0U, /* Data size in buffers segment 2 - pPayloadLengthDynMax */
  6U, /* Last MB in segment 1 (Number of MB in Segment1 - 1) */
  8U, /* Last individual MB; (All individual MBs belong to Segment1) */
  41U, /* Total number of used MB (Last_individual_MB + 1 + FIFO) */
  TRUE,                   
  10U,                  
  0U                      
};
#define FR_STOP_SEC_CONFIG_DATA
#include "Fr_MemMap.h"


#define FR_START_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
const Fr_CtrlCfgType Fr_Cct_0 = 
{ 
    0,
    &Fr_HW_cfg_1, 
    &Fr_low_level_cfg_set_ecu0, 
    Fr_buffer_cfg, 
    Fr_buffer_cfg_set_ctrl,
    &Fr_DemError 
};
#define FR_STOP_SEC_CONFIG_DATA
#include "Fr_MemMap.h"

#define FR_START_SEC_CONFIG_DATA
#include "Fr_MemMap.h"
const Fr_ConfigType Fr_cfg = 
{
    {
        &Fr_Cct_0
    },
   100 
};
#define FR_STOP_SEC_CONFIG_DATA
#include "Fr_MemMap.h"

#endif /* RESOURCE_SUPPORT_FLEXRAY */

#ifdef __cplusplus
}
#endif

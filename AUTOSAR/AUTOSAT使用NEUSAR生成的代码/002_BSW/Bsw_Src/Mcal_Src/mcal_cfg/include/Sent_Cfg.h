/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : SENT
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
*   @file    Sent_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Sent MCAL driver.
*
*   @addtogroup Sent
*   @{
*/


#ifndef Sent_CFG_H_
#define Sent_CFG_H_

#include "Compiler.h"
#include "StandardTypes.h"
#include "Mcal.h"
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SENT_VENDOR_ID                           176
#define SENT_CFG_AR_MAJOR_VER                    4
#define SENT_CFG_AR_MINOR_VER                    4
#define SENT_CFG_AR_PATCH_VER                    0
#define SENT_CFG_SW_MAJOR_VER                    3
#define SENT_CFG_SW_MINOR_VER                    0
#define SENT_CFG_SW_PATCH_VER                    0

/*============================================FILE VERSION CHECKS===================================*/
#if (MCAL_VENDOR_ID != SENT_VENDOR_ID)
    #error " NON-MATCHED DATA : SENT_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != SENT_CFG_AR_MAJOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_AR_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != SENT_CFG_AR_MINOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_AR_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != SENT_CFG_AR_PATCH_VER)
    #error " NON-MATCHED DATA : SENT_CFG_AR_PATCH_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != SENT_CFG_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != SENT_CFG_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != SENT_CFG_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SENT_CFG_SW_PATCH_VER "
#endif


#define SENT_PRECOMPILE_SUPPORT                  (STD_OFF)
#define SENT_DEV_ERROR_DETECT                    (STD_ON)
#define SENT_VERSION_INFO_API                    (STD_ON)
#define SENT_ENABLE_MULTICORE                    (STD_ON)
#define SENT_INLINE                              LOCAL_INLINE
/* Number of maximum partitions. */
#define SENT_MAX_PARTITIONS                      (6U)
#define SENT_DEFAULT_COREID                      (0U)

#define SENT_0_CH_0                 0x0
#define SENT_0_CH_1                 0x1
#define SENT_0_CH_2                 0x2
#define SENT_0_CH_3                 0x3
#define SENT_0_CH_4                 0x4
#define SENT_0_CH_5                 0x5
#define SENT_0_CH_6                 0x6
#define SENT_0_CH_7                 0x7
#define SENT_0_CH_8                 0x8
#define SENT_0_CH_9                 0x9
#define SENT_0_CH_10                0xa
#define SENT_0_CH_11                0xb
#define SENT_0_CH_12                0xc
#define SENT_1_CH_0                 0x20
#define SENT_1_CH_1                 0x21
#define SENT_1_CH_2                 0x22
#define SENT_1_CH_3                 0x23
#define SENT_1_CH_4                 0x24
#define SENT_1_CH_5                 0x25
#define SENT_1_CH_6                 0x26
#define SENT_1_CH_7                 0x27
#define SENT_1_CH_8                 0x28
#define SENT_1_CH_9                 0x29
#define SENT_1_CH_10                0x2a
#define SENT_1_CH_11                0x2b

#define SentChannelConfiguration_0                             (Sent_SentChannelConfiguration_0)
#define Sent_SentChannelConfiguration_0                        ((Sent_ChannelType)0U) 

#endif /* Sent_CFG_H_ */

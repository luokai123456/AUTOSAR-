/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : CAN
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    Can_176_CanFD_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Can MCAL driver.
*
*   @addtogroup CanFD
*   @{
*/

#ifndef CAN_176_CANFD_CFG_H
#define CAN_176_CANFD_CFG_H

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#include "StandardTypes.h"
#include "Mcal.h"

#ifdef RESOURCE_SUPPORT_CANFD_IP

#define CAN_176_CANFD_CFG_H_VENDOR_ID                     176
#define CAN_176_CANFD_CFG_H_AR_REL_MAJOR_VER              4
#define CAN_176_CANFD_CFG_H_AR_REL_MINOR_VER              4
#define CAN_176_CANFD_CFG_H_AR_REL_REV_VER                0
#define CAN_176_CANFD_CFG_H_SW_MAJOR_VER                  3
#define CAN_176_CANFD_CFG_H_SW_MINOR_VER                  0
#define CAN_176_CANFD_CFG_H_SW_PATCH_VER                  0

#if (MCAL_VENDOR_ID != CAN_176_CANFD_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_H_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != CAN_176_CANFD_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_H_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != CAN_176_CANFD_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_H_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != CAN_176_CANFD_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_H_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != CAN_176_CANFD_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_H_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != CAN_176_CANFD_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_H_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != CAN_176_CANFD_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_H_SW_PATCH_VER "
#endif


#define CAN_176_CANFD_PRECOMPILE_SUPPORT    (STD_OFF)

#define CAN_176_CANFD_MULTICORE_ENABLED    (STD_ON)

#define CAN_176_CANFD_CHECK_WAKEUP_API    (STD_ON)

#define CAN_176_CANFD_FD_MODE_ENABLE    (STD_ON)

#define CAN_176_CANFD_DEV_ERROR_DETECT    (STD_ON)

#define CAN_176_CANFD_VERSION_INFO_API    (STD_ON)

#define CAN_176_CANFD_INSTANCE    (0U)

#define CAN_176_CANFD_MAINFUNCTION_BUSOFF_PERIOD    (0U)

#define CAN_176_CANFD_MAINFUNCTION_MODE_PERIOD    (0U)

#define CAN_176_CANFD_MAINFUNCTION_WAKEUP_PERIOD    (0U)

#define CAN_176_CANFD_MULTIPLEXED_TRANSMISSION    (STD_OFF)

#define CAN_176_CANFD_SET_BAUDRATE_API    (STD_ON)

#define CAN_176_CANFD_MAINFUNCTION_BUSOFF_API    (STD_ON)
#define CAN_176_CANFD_MAINFUNCTION_WAKEUP_API    (STD_ON)
#define CAN_176_CANFD_WAKEUP_SUPPORT    (STD_ON)
/* The unit is us. */
#define CAN_176_CANFD_TIMEOUT_DURATION    1000000U

#define CAN_176_CANFD_MULTIPLE_READ_PERIOD   (STD_ON)
#define CAN_176_CANFD_MULTIPLE_WRITE_PERIOD  (STD_ON)
#define CAN_176_CANFD_MAINFUNCTION_RW_PERIOD_0            (1.0F)
#define CAN_176_CANFD_MAINFUNCTION_PERIOD_READ_0       (1.0F)
#define CAN_176_CANFD_MAINFUNCTION_PERIOD_WRITE_0      (1.0F)
#define CAN_176_CANFD_MAINFUNCTION_RW_PERIOD_1            (0.5F)
#define CAN_176_CANFD_MAINFUNCTION_PERIOD_READ_1       (0.5F)
#define CAN_176_CANFD_MAINFUNCTION_PERIOD_WRITE_1      (0.5F)
#define CAN_176_CANFD_CONTROLLER_COUNT    2U
#define CAN_176_CANFD_MAINFUNCTION_WRITE_API    (STD_ON)
#define CAN_176_CANFD_MAINFUNCTION_READ_API    (STD_ON)
#define CAN_176_CANFD_TRIGGER_TRANSMIT_EN    (STD_OFF)//WJC: (STD_ON)

#define CAN_176_CANFD_INLINE    LOCAL_INLINE

#define CAN_176_CANFD_MB_COUNT       8U
#define CAN_176_CANFD_HOH_CNT_MAX    8U
#define CAN_176_CANFD_DEFAULT_COREID 0U

#define CANFD1_101    0U  /* RECEIVE object of Controller Id 0 */
#define CANFD1_18FF1001    1U  /* RECEIVE object of Controller Id 0 */
#define CANFD9_201    2U  /* RECEIVE object of Controller Id 1 */
#define CANFD9_18FF2001    3U  /* RECEIVE object of Controller Id 1 */
#define CANFD1_TX_PRIMARY    4U  /* TRANSMIT object of Controller Id 0 */
#define CANFD1_TX_SECONDARY    5U  /* TRANSMIT object of Controller Id 0 */
#define CANFD9_TX_PRIMARY    6U  /* TRANSMIT object of Controller Id 1 */
#define CANFD9TX_SECONDARY    7U  /* TRANSMIT object of Controller Id 1 */

#define CanFd_1    0U  /* CANFD_MOD_ID_1 */
#define CanFd_9    1U  /* CANFD_MOD_ID_9 */

//#define Can_176_CanFD_LPduReceiveCalloutFunction     (CanFdLPduReceiveCalloutFunction) //dq

#define CAN_176_CANFD_PB_CONFIG_DECLARATION   extern CONST(Can_176_CanFD_ConfigType, CAN_VAR) Can_176_CanFD_Config;

#endif /* RESOURCE_SUPPORT_CANFD_IP */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CAN_176_CANFD_CFG_H */


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
*   @file    Can_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Can MCAL driver.
*
*   @addtogroup Can
*   @{
*/
#ifndef CAN_TEST_CFG_H_
#ifndef CAN_CFG_H_
#define CAN_CFG_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
#include "Mcal.h"

#define CAN_CFG_H_VENDOR_ID                     176
#define CAN_CFG_H_AR_REL_MAJOR_VER              4
#define CAN_CFG_H_AR_REL_MINOR_VER              4
#define CAN_CFG_H_AR_REL_REV_VER                0
#define CAN_CFG_H_SW_MAJOR_VER                  3
#define CAN_CFG_H_SW_MINOR_VER                  0
#define CAN_CFG_H_SW_PATCH_VER                  0

#if (MCAL_VENDOR_ID != CAN_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_CFG_H_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != CAN_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != CAN_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != CAN_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != CAN_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != CAN_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != CAN_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_SW_PATCH_VER "
#endif


#define CAN_PRECOMPILE_SUPPORT    (STD_OFF)

#define CAN_MULTICORE_ENABLED    (STD_ON)

#define CAN_CHECK_WAKEUP_API    (STD_OFF)

#define CAN_FD_MODE_ENABLE    (STD_ON)

#define CAN_DEV_ERROR_DETECT    (STD_ON)

#define CAN_VERSION_INFO_API    (STD_OFF)

#define CAN_INSTANCE    (0U)

#define CAN_MAINFUNCTION_BUSOFF_PERIOD    (0U)

#define CAN_MAINFUNCTION_MODE_PERIOD    (0U)

#define CAN_MAINFUNCTION_WAKEUP_PERIOD    (0U)

#define CAN_MULTIPLEXED_TRANSMISSION    (STD_ON)

#define CAN_SET_BAUDRATE_API    (STD_ON)

#define CAN_MAINFUNCTION_BUSOFF_API    (STD_OFF)
#define CAN_MAINFUNCTION_WAKEUP_API    (STD_OFF)
#define CAN_WAKEUP_SUPPORT    (STD_OFF)
/* The unit is us. */
#define CAN_TIMEOUT_DURATION    1000000U

#define CAN_MULTIPLE_READ_PERIOD   (STD_ON)
#define CAN_MULTIPLE_WRITE_PERIOD  (STD_ON)
#define CAN_MAINFUNCTION_RW_PERIOD_0            (0.01F)
#define CAN_MAINFUNCTION_PERIOD_READ_0       (0.01F)
#define CAN_MAINFUNCTION_PERIOD_WRITE_0      (0.01F)
#define CAN_MAINFUNCTION_RW_PERIOD_1            (0.01F)
#define CAN_MAINFUNCTION_PERIOD_READ_1       (0.01F)
#define CAN_MAINFUNCTION_PERIOD_WRITE_1      (0.01F)
#define CAN_MAINFUNCTION_RW_PERIOD_2            (0.01F)
#define CAN_MAINFUNCTION_PERIOD_READ_2       (0.01F)
#define CAN_MAINFUNCTION_PERIOD_WRITE_2      (0.01F)
#define CAN_MAINFUNCTION_RW_PERIOD_3            (0.01F)
#define CAN_MAINFUNCTION_PERIOD_READ_3       (0.01F)
#define CAN_MAINFUNCTION_PERIOD_WRITE_3      (0.01F)
#define CAN_MAINFUNCTION_RW_PERIOD_4            (0.01F)
#define CAN_MAINFUNCTION_PERIOD_READ_4       (0.01F)
#define CAN_MAINFUNCTION_PERIOD_WRITE_4      (0.01F)
#define CAN_MAINFUNCTION_RW_PERIOD_5            (0.01F)
#define CAN_MAINFUNCTION_PERIOD_READ_5       (0.01F)
#define CAN_MAINFUNCTION_PERIOD_WRITE_5      (0.01F)
#define CAN_MAINFUNCTION_RW_PERIOD_6            (0.01F)
#define CAN_MAINFUNCTION_PERIOD_READ_6       (0.01F)
#define CAN_MAINFUNCTION_PERIOD_WRITE_6      (0.01F)
#define CAN_CONTROLLER_COUNT    6U
#define CAN_MAINFUNCTION_WRITE_API    (STD_OFF)
#define CAN_MAINFUNCTION_READ_API    (STD_OFF)
#define CAN_TRIGGER_TRANSMIT_EN    (STD_OFF)

#define CAN_INLINE    LOCAL_INLINE
#define CAN_OBJECT_COUNT   93U
#define CAN_MB_COUNT       279U
#define CAN_HOH_CNT_MAX    93U
#define CAN_DEFAULT_COREID 0U


#define DC_CAN_HWObject_RX_00    0U  /* RECEIVE object of Controller Id 0 */
#define DC_CAN_HWObject_RX_01    1U  /* RECEIVE object of Controller Id 0 */
#define DC_CAN_HWObject_RX_02    2U  /* RECEIVE object of Controller Id 0 */
#define DC_CAN_HWObject_RX_03    3U  /* RECEIVE object of Controller Id 0 */
#define DC_CAN_HWObject_RX_04    4U  /* RECEIVE object of Controller Id 0 */
#define DC_CAN_HWObject_RX_05    5U  /* RECEIVE object of Controller Id 0 */
#define DC_CAN_HWObject_RX_06    6U  /* RECEIVE object of Controller Id 0 */
#define DC_CAN_HWObject_RX_07    7U  /* RECEIVE object of Controller Id 0 */
#define DC_CAN_HWObject_RX_08    8U  /* RECEIVE object of Controller Id 0 */
#define DC_CAN_HWObject_RX_09    9U  /* RECEIVE object of Controller Id 0 */
#define EV_CAN_HWObject_RX_00    10U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_01    11U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_02    12U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_03    13U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_04    14U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_05    15U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_06    16U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_07    17U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_08    18U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_09    19U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_10    20U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_11    21U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_12    22U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_13    23U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_14    24U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_15    25U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_16    26U  /* RECEIVE object of Controller Id 1 */
#define EV_CAN_HWObject_RX_17    27U  /* RECEIVE object of Controller Id 1 */
#define XCP_CAN_HWObject_RX_00    28U  /* RECEIVE object of Controller Id 2 */
#define XCP_CAN_HWObject_RX_01    29U  /* RECEIVE object of Controller Id 2 */
#define HCM_CAN_HWObject_RX_00    30U  /* RECEIVE object of Controller Id 3 */
#define HCM_CAN_HWObject_RX_01    31U  /* RECEIVE object of Controller Id 3 */
#define HCM_CAN_HWObject_RX_02    32U  /* RECEIVE object of Controller Id 3 */
#define HCM_CAN_HWObject_RX_03    33U  /* RECEIVE object of Controller Id 3 */
#define HCM_CAN_HWObject_RX_04    34U  /* RECEIVE object of Controller Id 3 */
#define HCM_CAN_HWObject_RX_05    35U  /* RECEIVE object of Controller Id 3 */
#define HCM_CAN_HWObject_RX_06    36U  /* RECEIVE object of Controller Id 3 */
#define CH_CAN_HWObject_RX_00    37U  /* RECEIVE object of Controller Id 4 */
#define CH_CAN_HWObject_RX_01    38U  /* RECEIVE object of Controller Id 4 */
#define CH_CAN_HWObject_RX_02    39U  /* RECEIVE object of Controller Id 4 */
#define CH_CAN_HWObject_RX_03    40U  /* RECEIVE object of Controller Id 4 */
#define CH_CAN_HWObject_RX_04    41U  /* RECEIVE object of Controller Id 4 */
#define CH_CAN_HWObject_RX_05    42U  /* RECEIVE object of Controller Id 4 */
#define CH_CAN_HWObject_RX_06    43U  /* RECEIVE object of Controller Id 4 */
#define CH_CAN_HWObject_RX_07    44U  /* RECEIVE object of Controller Id 4 */
#define CH_CAN_HWObject_RX_08    45U  /* RECEIVE object of Controller Id 4 */
#define CH_CAN_HWObject_RX_09    46U  /* RECEIVE object of Controller Id 4 */
#define CH_CAN_HWObject_RX_10    47U  /* RECEIVE object of Controller Id 4 */
#define CH_CAN_HWObject_RX_11    48U  /* RECEIVE object of Controller Id 4 */
#define CH_CAN_HWObject_RX_12    49U  /* RECEIVE object of Controller Id 4 */
#define CH_CAN_HWObject_RX_13    50U  /* RECEIVE object of Controller Id 4 */
#define CH_CAN_HWObject_RX_14    51U  /* RECEIVE object of Controller Id 4 */
#define CH_CAN_HWObject_RX_15    52U  /* RECEIVE object of Controller Id 4 */
#define PT_CAN_HWObject_RX_00    53U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_01    54U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_02    55U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_03    56U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_04    57U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_05    58U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_06    59U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_07    60U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_08    61U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_09    62U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_10    63U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_11    64U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_12    65U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_13    66U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_14    67U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_15    68U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_16    69U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_17    70U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_18    71U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_19    72U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_20    73U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_21    74U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_22    75U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_23    76U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_24    77U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_25    78U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_26    79U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_27    80U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_28    81U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_29    82U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_30    83U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_31    84U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_32    85U  /* RECEIVE object of Controller Id 5 */
#define PT_CAN_HWObject_RX_33    86U  /* RECEIVE object of Controller Id 5 */
#define DC_CAN_HWObject_TX    87U  /* TRANSMIT object of Controller Id 0 */
#define EV_CAN_HWObject_TX    88U  /* TRANSMIT object of Controller Id 1 */
#define XCP_CAN_HWObject_TX    89U  /* TRANSMIT object of Controller Id 2 */
#define HCM_CAN_HWObject_TX    90U  /* TRANSMIT object of Controller Id 3 */
#define CH_CAN_HWObject_TX    91U  /* TRANSMIT object of Controller Id 4 */
#define PT_CAN_HWObject_TX    92U  /* TRANSMIT object of Controller Id 5 */

#define CanController_E    0U  /* MCAN_1 */
#define CanController_A    1U  /* MCAN_7 */
#define CanController_F    2U  /* MCAN_6 */
#define CanController_G    3U  /* MCAN_11 */
#define CanController_D    4U  /* MCAN_9 */
#define CanController_B    5U  /* MCAN_2 */

#define CAN_PB_CONFIG_DECLARATION   extern CONST(Can_ConfigType, CAN_VAR) Can_Config;

#ifdef __cplusplus
}
#endif

#endif /* CAN_CFG_H_ */




#else
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
*   @file    Can_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Can MCAL driver.
*
*   @addtogroup Can
*   @{
*/

#ifndef CAN_CFG_H_
#define CAN_CFG_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
#include "Mcal.h"

#define CAN_CFG_H_VENDOR_ID                     176
#define CAN_CFG_H_AR_REL_MAJOR_VER              4
#define CAN_CFG_H_AR_REL_MINOR_VER              4
#define CAN_CFG_H_AR_REL_REV_VER                0
#define CAN_CFG_H_SW_MAJOR_VER                  3
#define CAN_CFG_H_SW_MINOR_VER                  0
#define CAN_CFG_H_SW_PATCH_VER                  0

#if (MCAL_VENDOR_ID != CAN_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_CFG_H_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != CAN_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != CAN_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != CAN_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != CAN_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != CAN_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != CAN_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_SW_PATCH_VER "
#endif


#define CAN_PRECOMPILE_SUPPORT    (STD_OFF)

#define CAN_MULTICORE_ENABLED    (STD_ON)

#define CAN_CHECK_WAKEUP_API    (STD_OFF)

#define CAN_FD_MODE_ENABLE    (STD_ON)

#define CAN_DEV_ERROR_DETECT    (STD_ON)

#define CAN_VERSION_INFO_API    (STD_OFF)

#define CAN_INSTANCE    (0U)

#define CAN_MAINFUNCTION_BUSOFF_PERIOD    (0U)

#define CAN_MAINFUNCTION_MODE_PERIOD    (0U)

#define CAN_MAINFUNCTION_WAKEUP_PERIOD    (0U)

#define CAN_MULTIPLEXED_TRANSMISSION    (STD_ON)

#define CAN_SET_BAUDRATE_API    (STD_ON)

#define CAN_MAINFUNCTION_BUSOFF_API    (STD_OFF)
#define CAN_MAINFUNCTION_WAKEUP_API    (STD_OFF)
#define CAN_WAKEUP_SUPPORT    (STD_OFF)
/* The unit is us. */
#define CAN_TIMEOUT_DURATION    1000000U

#define CAN_MULTIPLE_READ_PERIOD   (STD_ON)
#define CAN_MULTIPLE_WRITE_PERIOD  (STD_ON)
#define CAN_MAINFUNCTION_RW_PERIOD_0            (0.01F)
#define CAN_MAINFUNCTION_PERIOD_READ_0       (0.01F)
#define CAN_MAINFUNCTION_PERIOD_WRITE_0      (0.01F)
#define CAN_MAINFUNCTION_RW_PERIOD_1            (0.01F)
#define CAN_MAINFUNCTION_PERIOD_READ_1       (0.01F)
#define CAN_MAINFUNCTION_PERIOD_WRITE_1      (0.01F)
#define CAN_MAINFUNCTION_RW_PERIOD_2            (0.01F)
#define CAN_MAINFUNCTION_PERIOD_READ_2       (0.01F)
#define CAN_MAINFUNCTION_PERIOD_WRITE_2      (0.01F)
#define CAN_MAINFUNCTION_RW_PERIOD_3            (0.01F)
#define CAN_MAINFUNCTION_PERIOD_READ_3       (0.01F)
#define CAN_MAINFUNCTION_PERIOD_WRITE_3      (0.01F)
#define CAN_MAINFUNCTION_RW_PERIOD_4            (0.01F)
#define CAN_MAINFUNCTION_PERIOD_READ_4       (0.01F)
#define CAN_MAINFUNCTION_PERIOD_WRITE_4      (0.01F)
#define CAN_MAINFUNCTION_RW_PERIOD_5            (0.01F)
#define CAN_MAINFUNCTION_PERIOD_READ_5       (0.01F)
#define CAN_MAINFUNCTION_PERIOD_WRITE_5      (0.01F)
#define CAN_MAINFUNCTION_RW_PERIOD_6            (0.01F)
#define CAN_MAINFUNCTION_PERIOD_READ_6       (0.01F)
#define CAN_MAINFUNCTION_PERIOD_WRITE_6      (0.01F)
#define CAN_CONTROLLER_COUNT    7U
#define CAN_MAINFUNCTION_WRITE_API    (STD_OFF)
#define CAN_MAINFUNCTION_READ_API    (STD_OFF)
#define CAN_TRIGGER_TRANSMIT_EN    (STD_OFF)

#define CAN_INLINE    LOCAL_INLINE
#define CAN_OBJECT_COUNT   672U
#define CAN_MB_COUNT       1120U
#define CAN_HOH_CNT_MAX    672U
#define CAN_DEFAULT_COREID 0U


#define CanHardwareObject_0    0U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_1    1U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_2    2U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_3    3U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_4    4U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_5    5U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_6    6U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_7    7U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_8    8U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_9    9U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_10    10U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_11    11U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_12    12U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_13    13U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_14    14U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_15    15U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_16    16U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_17    17U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_18    18U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_19    19U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_20    20U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_21    21U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_22    22U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_23    23U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_24    24U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_25    25U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_26    26U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_27    27U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_28    28U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_29    29U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_30    30U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_31    31U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_32    32U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_33    33U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_34    34U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_35    35U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_36    36U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_37    37U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_38    38U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_39    39U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_40    40U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_41    41U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_42    42U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_43    43U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_44    44U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_45    45U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_46    46U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_47    47U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_48    48U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_49    49U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_50    50U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_51    51U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_52    52U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_53    53U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_54    54U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_55    55U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_56    56U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_57    57U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_58    58U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_59    59U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_60    60U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_61    61U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_62    62U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_63    63U  /* TRANSMIT object of Controller Id 1 */
#define CanHardwareObject_64    64U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_65    65U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_66    66U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_67    67U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_68    68U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_69    69U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_70    70U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_71    71U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_72    72U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_73    73U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_74    74U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_75    75U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_76    76U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_77    77U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_78    78U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_79    79U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_80    80U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_81    81U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_82    82U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_83    83U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_84    84U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_85    85U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_86    86U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_87    87U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_88    88U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_89    89U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_90    90U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_91    91U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_92    92U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_93    93U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_94    94U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_95    95U  /* TRANSMIT object of Controller Id 2 */
#define CanHardwareObject_96    96U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_97    97U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_98    98U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_99    99U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_100    100U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_101    101U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_102    102U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_103    103U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_104    104U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_105    105U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_106    106U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_107    107U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_108    108U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_109    109U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_110    110U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_111    111U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_112    112U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_113    113U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_114    114U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_115    115U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_116    116U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_117    117U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_118    118U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_119    119U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_120    120U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_121    121U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_122    122U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_123    123U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_124    124U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_125    125U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_126    126U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_127    127U  /* TRANSMIT object of Controller Id 3 */
#define CanHardwareObject_128    128U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_129    129U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_130    130U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_131    131U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_132    132U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_133    133U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_134    134U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_135    135U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_136    136U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_137    137U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_138    138U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_139    139U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_140    140U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_141    141U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_142    142U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_143    143U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_144    144U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_145    145U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_146    146U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_147    147U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_148    148U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_149    149U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_150    150U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_151    151U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_152    152U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_153    153U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_154    154U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_155    155U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_156    156U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_157    157U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_158    158U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_159    159U  /* TRANSMIT object of Controller Id 4 */
#define CanHardwareObject_160    160U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_161    161U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_162    162U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_163    163U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_164    164U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_165    165U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_166    166U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_167    167U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_168    168U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_169    169U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_170    170U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_171    171U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_172    172U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_173    173U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_174    174U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_175    175U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_176    176U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_177    177U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_178    178U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_179    179U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_180    180U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_181    181U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_182    182U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_183    183U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_184    184U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_185    185U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_186    186U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_187    187U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_188    188U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_189    189U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_190    190U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_191    191U  /* TRANSMIT object of Controller Id 5 */
#define CanHardwareObject_192    192U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_193    193U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_194    194U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_195    195U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_196    196U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_197    197U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_198    198U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_199    199U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_200    200U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_201    201U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_202    202U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_203    203U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_204    204U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_205    205U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_206    206U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_207    207U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_208    208U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_209    209U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_210    210U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_211    211U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_212    212U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_213    213U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_214    214U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_215    215U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_216    216U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_217    217U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_218    218U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_219    219U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_220    220U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_221    221U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_222    222U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_223    223U  /* TRANSMIT object of Controller Id 6 */
#define CanHardwareObject_224    224U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_225    225U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_226    226U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_227    227U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_228    228U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_229    229U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_230    230U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_231    231U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_232    232U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_233    233U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_234    234U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_235    235U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_236    236U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_237    237U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_238    238U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_239    239U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_240    240U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_241    241U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_242    242U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_243    243U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_244    244U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_245    245U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_246    246U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_247    247U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_248    248U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_249    249U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_250    250U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_251    251U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_252    252U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_253    253U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_254    254U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_255    255U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_256    256U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_257    257U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_258    258U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_259    259U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_260    260U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_261    261U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_262    262U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_263    263U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_264    264U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_265    265U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_266    266U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_267    267U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_268    268U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_269    269U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_270    270U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_271    271U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_272    272U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_273    273U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_274    274U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_275    275U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_276    276U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_277    277U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_278    278U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_279    279U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_280    280U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_281    281U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_282    282U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_283    283U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_284    284U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_285    285U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_286    286U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_287    287U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_288    288U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_289    289U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_290    290U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_291    291U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_292    292U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_293    293U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_294    294U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_295    295U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_296    296U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_297    297U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_298    298U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_299    299U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_300    300U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_301    301U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_302    302U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_303    303U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_304    304U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_305    305U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_306    306U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_307    307U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_308    308U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_309    309U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_310    310U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_311    311U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_312    312U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_313    313U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_314    314U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_315    315U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_316    316U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_317    317U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_318    318U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_319    319U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_320    320U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_321    321U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_322    322U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_323    323U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_324    324U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_325    325U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_326    326U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_327    327U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_328    328U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_329    329U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_330    330U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_331    331U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_332    332U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_333    333U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_334    334U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_335    335U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_336    336U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_337    337U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_338    338U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_339    339U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_340    340U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_341    341U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_342    342U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_343    343U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_344    344U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_345    345U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_346    346U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_347    347U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_348    348U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_349    349U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_350    350U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_351    351U  /* RECEIVE object of Controller Id 1 */
#define CanHardwareObject_352    352U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_353    353U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_354    354U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_355    355U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_356    356U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_357    357U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_358    358U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_359    359U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_360    360U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_361    361U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_362    362U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_363    363U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_364    364U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_365    365U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_366    366U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_367    367U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_368    368U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_369    369U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_370    370U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_371    371U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_372    372U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_373    373U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_374    374U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_375    375U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_376    376U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_377    377U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_378    378U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_379    379U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_380    380U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_381    381U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_382    382U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_383    383U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_384    384U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_385    385U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_386    386U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_387    387U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_388    388U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_389    389U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_390    390U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_391    391U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_392    392U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_393    393U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_394    394U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_395    395U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_396    396U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_397    397U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_398    398U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_399    399U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_400    400U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_401    401U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_402    402U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_403    403U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_404    404U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_405    405U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_406    406U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_407    407U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_408    408U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_409    409U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_410    410U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_411    411U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_412    412U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_413    413U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_414    414U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_415    415U  /* RECEIVE object of Controller Id 2 */
#define CanHardwareObject_416    416U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_417    417U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_418    418U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_419    419U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_420    420U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_421    421U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_422    422U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_423    423U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_424    424U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_425    425U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_426    426U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_427    427U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_428    428U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_429    429U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_430    430U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_431    431U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_432    432U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_433    433U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_434    434U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_435    435U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_436    436U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_437    437U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_438    438U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_439    439U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_440    440U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_441    441U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_442    442U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_443    443U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_444    444U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_445    445U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_446    446U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_447    447U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_448    448U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_449    449U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_450    450U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_451    451U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_452    452U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_453    453U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_454    454U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_455    455U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_456    456U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_457    457U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_458    458U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_459    459U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_460    460U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_461    461U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_462    462U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_463    463U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_464    464U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_465    465U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_466    466U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_467    467U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_468    468U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_469    469U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_470    470U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_471    471U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_472    472U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_473    473U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_474    474U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_475    475U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_476    476U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_477    477U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_478    478U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_479    479U  /* RECEIVE object of Controller Id 3 */
#define CanHardwareObject_480    480U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_481    481U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_482    482U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_483    483U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_484    484U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_485    485U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_486    486U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_487    487U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_488    488U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_489    489U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_490    490U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_491    491U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_492    492U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_493    493U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_494    494U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_495    495U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_496    496U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_497    497U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_498    498U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_499    499U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_500    500U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_501    501U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_502    502U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_503    503U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_504    504U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_505    505U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_506    506U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_507    507U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_508    508U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_509    509U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_510    510U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_511    511U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_512    512U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_513    513U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_514    514U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_515    515U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_516    516U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_517    517U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_518    518U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_519    519U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_520    520U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_521    521U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_522    522U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_523    523U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_524    524U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_525    525U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_526    526U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_527    527U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_528    528U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_529    529U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_530    530U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_531    531U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_532    532U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_533    533U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_534    534U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_535    535U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_536    536U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_537    537U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_538    538U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_539    539U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_540    540U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_541    541U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_542    542U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_543    543U  /* RECEIVE object of Controller Id 4 */
#define CanHardwareObject_544    544U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_545    545U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_546    546U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_547    547U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_548    548U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_549    549U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_550    550U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_551    551U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_552    552U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_553    553U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_554    554U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_555    555U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_556    556U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_557    557U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_558    558U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_559    559U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_560    560U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_561    561U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_562    562U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_563    563U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_564    564U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_565    565U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_566    566U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_567    567U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_568    568U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_569    569U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_570    570U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_571    571U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_572    572U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_573    573U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_574    574U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_575    575U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_576    576U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_577    577U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_578    578U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_579    579U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_580    580U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_581    581U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_582    582U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_583    583U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_584    584U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_585    585U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_586    586U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_587    587U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_588    588U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_589    589U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_590    590U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_591    591U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_592    592U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_593    593U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_594    594U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_595    595U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_596    596U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_597    597U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_598    598U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_599    599U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_600    600U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_601    601U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_602    602U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_603    603U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_604    604U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_605    605U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_606    606U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_607    607U  /* RECEIVE object of Controller Id 5 */
#define CanHardwareObject_608    608U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_609    609U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_610    610U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_611    611U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_612    612U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_613    613U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_614    614U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_615    615U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_616    616U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_617    617U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_618    618U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_619    619U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_620    620U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_621    621U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_622    622U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_623    623U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_624    624U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_625    625U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_626    626U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_627    627U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_628    628U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_629    629U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_630    630U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_631    631U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_632    632U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_633    633U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_634    634U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_635    635U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_636    636U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_637    637U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_638    638U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_639    639U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_640    640U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_641    641U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_642    642U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_643    643U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_644    644U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_645    645U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_646    646U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_647    647U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_648    648U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_649    649U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_650    650U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_651    651U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_652    652U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_653    653U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_654    654U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_655    655U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_656    656U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_657    657U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_658    658U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_659    659U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_660    660U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_661    661U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_662    662U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_663    663U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_664    664U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_665    665U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_666    666U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_667    667U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_668    668U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_669    669U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_670    670U  /* RECEIVE object of Controller Id 6 */
#define CanHardwareObject_671    671U  /* RECEIVE object of Controller Id 6 */

#define CanController_A    0U  /* MCAN_7 */
#define CanController_B    1U  /* MCAN_2 */
#define CanController_C    2U  /* MCAN_3 */
#define CanController_D    3U  /* MCAN_9 */
#define CanController_E    4U  /* MCAN_1 */
#define CanController_F    5U  /* MCAN_6 */
#define CanController_G    6U  /* MCAN_11 */

#define CAN_PB_CONFIG_DECLARATION   extern CONST(Can_ConfigType, CAN_VAR) Can_Config;

#ifdef __cplusplus
}
#endif

#endif /* CAN_CFG_H_ */

#endif
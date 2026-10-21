/**************************************************************************** 
*
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : ETPU
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
*   @file    sPwm.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of sPwm MCAL driver.
*
*   @addtogroup sPwm
*   @{
*/

#ifndef SPWM_H_
#define SPWM_H_

#include "Mcal.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "sPwm_LLDrivers.h"
#include "eTPU_LLDrivers.h"

#define SPWM_H_VENDOR_ID_PLUGIN             176
#define SPWM_H_AR_REL_MAJOR_VER				4
#define SPWM_H_AR_REL_MINOR_VER			    4
#define SPWM_H_AR_REL_REV_VER   		    0
#define SPWM_H_SW_MAJOR_VER                 3
#define SPWM_H_SW_MINOR_VER                 0
#define SPWM_H_SW_PATCH_VER                 0

#if (ETPU_VENDOR_ID_OUTPUT != SPWM_H_VENDOR_ID_PLUGIN)
    #error " NON-MATCHED DATA : SPWM_H_VENDOR_ID_PLUGIN "
#endif
#if (ETPU_AR_REL_MAJOR_VER_OUTPUT != SPWM_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SPWM_H_AR_REL_MAJOR_VER "
#endif
#if (ETPU_AR_REL_MINOR_VER_OUTPUT != SPWM_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SPWM_H_AR_REL_MINOR_VER "
#endif
#if (ETPU_AR_REL_REVISION_VER_OUTPUT != SPWM_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SPWM_H_AR_REL_REV_VER "
#endif
#if (ETPU_SW_MAJOR_VERSION_OUTPUT != SPWM_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SPWM_H_SW_MAJOR_VER "
#endif
#if (ETPU_SW_MINOR_VERSION_OUTPUT != SPWM_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SPWM_H_SW_MINOR_VER "
#endif
#if (ETPU_SW_PATCH_VERSION_OUTPUT != SPWM_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SPWM_H_SW_PATCH_VER "
#endif

#if ((SPWM_MASTER_NUM != 0U)&&(SPWM_MODULE_ENABLE !=STD_OFF))
#define CDD_SPWM_MODULE_ID                       109
#define CDD_SPWM_MAX_SUBORDINATE                 8

#define CDD_SPWM_SID_INIT                      ((uint8)0x00U)
#define CDD_SPWM_SID_RUN_MASTER                ((uint8)0x01U)
#define CDD_SPWM_SID_DUTY                      ((uint8)0x02U)
#define CDD_SPWM_SID_UPDATE_MASTER             ((uint8)0x03U)
#define CDD_SPWM_SID_FREQ_MASTER               ((uint8)0x04U)

#define CDD_SPWM_E_PARAM_POINTER               ((uint8)0x01U)
#define CDD_SPWM_E_PARAM_CHANNLE               ((uint8)0x02U)
#define CDD_SPWM_E_PARAM_PRIORITY              ((uint8)0x03U)

#define Spwm_GetCoreID()       GetCoreID()
#define SPWM_CORE_NUM          MCAL_CORE_NUM

extern CONST(spwm_config_t, SPWM_CONST) sPwm_Config;

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, SPWM_CODE) sPwm_run_master
( \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint8, AUTOMATIC) priority
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, SPWM_CODE) sPwm_duty
( \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint16, AUTOMATIC) duty
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, SPWM_CODE) sPwm_update_master
( \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) freq, \
    VAR(uint16, AUTOMATIC) duty, \
    VAR(uint32, AUTOMATIC) timebase_freq
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, SPWM_CODE) sPwm_get_freq_master
(\
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) timebase_freq
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#endif /* SPWM_H_ */
#endif
#endif

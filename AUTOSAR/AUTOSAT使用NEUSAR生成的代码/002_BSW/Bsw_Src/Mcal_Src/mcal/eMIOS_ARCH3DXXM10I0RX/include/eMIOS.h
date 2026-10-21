/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : EMIOS
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
*   @file    eMIOS.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eMIOS MCAL driver.
*
*   @addtogroup eMIOS
*   @{
*/

#ifndef EMIOS_H
#define EMIOS_H

#include "eMIOS_Cfg.h"
#include "eMIOS_LLDriver.h"

#define EMIOS_H_VENDOR_ID                     176
#define EMIOS_H_AR_REL_MAJOR_VER              4
#define EMIOS_H_AR_REL_MINOR_VER              4
#define EMIOS_H_AR_REL_REV_VER                0
#define EMIOS_H_SW_MAJOR_VER                  3
#define EMIOS_H_SW_MINOR_VER                  0
#define EMIOS_H_SW_PATCH_VER                  0
#define EMIOS_MODULE_ID                       250

#if (EMIOS_VENDOR_ID != EMIOS_H_VENDOR_ID)
    #error " NON-MATCHED DATA : EMIOS_H_VENDOR_ID "
#endif
#if (EMIOS_AR_REL_MAJOR_VER != EMIOS_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EMIOS_H_AR_REL_MAJOR_VER "
#endif
#if (EMIOS_AR_REL_MINOR_VER != EMIOS_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EMIOS_H_AR_REL_MINOR_VER "
#endif
#if (EMIOS_AR_REL_REV_VER != EMIOS_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EMIOS_H_AR_REL_REV_VER "
#endif
#if (EMIOS_SW_MAJOR_VER != EMIOS_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EMIOS_H_SW_MAJOR_VER "
#endif
#if (EMIOS_SW_MINOR_VER != EMIOS_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EMIOS_H_SW_MINOR_VER "
#endif
#if (EMIOS_SW_PATCH_VER != EMIOS_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EMIOS_H_SW_PATCH_VER "
#endif

#define EMIOS_SID_INIT_ID                                   ((uint8)0x00U)
#define EMIOS_SID_INITGLOBALPARAM                           ((uint8)0x01U)
#define EMIOS_SID_MCINIT                                    ((uint8)0x02U)
#define EMIOS_SID_SETENDISGLOBAL                            ((uint8)0x03U)

#define EMIOS_E_PARAM_INSTANCE       ((uint8)0x01U)
#define EMIOS_E_PARAM_POINTER        ((uint8)0x02U)
#define EMIOS_E_PARAM_CHANNEL        ((uint8)0x03U)
#define EMIOS_E_PARAM_CONFIG         ((uint8)0x04U)

#define EMIOS_CORE_NUM                    MCAL_CORE_NUM
typedef struct
{
    VAR(eMIOS_BusDrivenType, EMIOS_VAR) eMIOSChannelId;
    VAR(eMIOS_MC_ParamType, EMIOS_VAR) eMIOS_MC_Param;
} eMIOS_Mc_CntChnConfigType;

typedef struct
{
    VAR(uint8, EMIOS_VAR) eMIOSIntanceId;
    VAR(eMIOS_GlobalParamType, EMIOS_VAR) eMIOS_GlobalParam;
    P2CONST(eMIOS_Mc_CntChnConfigType, EMIOS_VAR, EMIOS_APPL_CONST) eMIOS_Mc_CntChnConfig;
    VAR(uint8, EMIOS_VAR) eMIOSChannelNum;
} eMIOS_InstanceConfigType;

typedef struct
{
    P2CONST(eMIOS_InstanceConfigType, EMIOS_VAR, EMIOS_APPL_CONST) eMIOS_InstanceConfig;
} eMIOS_ConfigType;

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_Init(P2CONST(eMIOS_ConfigType, EMIOS_CONST, EMIOS_APPL_CONST) ConfigPtr);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#if (defined (EMIOS_STARTTIMER_API))
#if (EMIOS_STARTTIMER_API == STD_ON)
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) EMIOS_TimerStart(void);
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"
#endif
#endif

extern CONST(eMIOS_ConfigType, ADC_VAR) eMIOS_Config;


#endif /* EMIOS_H */

/** @} */

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
*   @file    eTPU.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eTPU MCAL driver.
*
*   @addtogroup eTPU
*   @{
*/
/* PRQA S 1594, 1599, 1756 EOF */
#ifndef ETPU_H_
#define ETPU_H_
#include "eTPU_LLDrivers.h"
#if (defined(RESOURCE_SUPPORT_ETPU))

#define ETPU_H_VENDOR_ID_PLUGIN             176
#define ETPU_H_AR_REL_MAJOR_VER             4
#define ETPU_H_AR_REL_MINOR_VER             4
#define ETPU_H_AR_REL_REV_VER               0
#define ETPU_H_SW_MAJOR_VER                 3
#define ETPU_H_SW_MINOR_VER                 0
#define ETPU_H_SW_PATCH_VER                 0

#if (ETPU_VENDOR_ID_OUTPUT != ETPU_H_VENDOR_ID_PLUGIN)
    #error " NON-MATCHED DATA : ETPU_H_VENDOR_ID_PLUGIN "
#endif
#if (ETPU_AR_REL_MAJOR_VER_OUTPUT != ETPU_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETPU_H_AR_REL_MAJOR_VER "
#endif
#if (ETPU_AR_REL_MINOR_VER_OUTPUT != ETPU_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETPU_H_AR_REL_MINOR_VER "
#endif
#if (ETPU_AR_REL_REVISION_VER_OUTPUT != ETPU_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETPU_H_AR_REL_REV_VER "
#endif
#if (ETPU_SW_MAJOR_VERSION_OUTPUT != ETPU_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETPU_H_SW_MAJOR_VER "
#endif
#if (ETPU_SW_MINOR_VERSION_OUTPUT != ETPU_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETPU_H_SW_MINOR_VER "
#endif
#if (ETPU_SW_PATCH_VERSION_OUTPUT != ETPU_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETPU_H_SW_PATCH_VER "
#endif

#define ETPU_INSTANCE                        0
#define ETPU_E_PARAM_DATA                    4

#define ETPU_INIT_ID                         ((uint8)0x63)
#define ETPU_E_PARAM_POINTER                 ((uint8)0x0A)
#define ETPU_E_UNINIT                        ((uint8)0x05U)
#define ETPU_E_TRANSITION                    ((uint8)0x06U)
#define ETPU_CORE_NUM                        MCAL_CORE_NUM

typedef enum
{
    ETPU_UNINIT = 0x00,
    ETPU_INITIALIZING = 0x01,
    ETPU_READY = 0x02
}eTPU_StatusType;

extern CONST(eTPU_ConfigType, ETPU_CONST) etpuConfig[ETPU_INSTANCE_NUM];

extern const uint32_t etpu_code_buff[];  /* PRQA S 3684 */

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) eTPU_Init(P2CONST(eTPU_Total_ConfigType, ETPU_CONST, ETPU_APPL_CONST) ConfigPtr);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#if (ETPU_STARTTIMER_API == STD_ON)
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_TimerStart(void);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
#endif

extern CONST(eTPU_Total_ConfigType, ETPU_CONST) etpu_Config;

#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
#endif /* ETPU_H_ */

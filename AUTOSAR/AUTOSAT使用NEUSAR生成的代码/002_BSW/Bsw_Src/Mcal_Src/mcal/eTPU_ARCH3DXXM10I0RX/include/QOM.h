/**************************************************************************** 
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
*   Autosar Conf.Variant :-
*   SW Version           :-
*   Build Version        :-
*
*****************************************************************************/

/**
*   @file    QOM.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of QOM MCAL driver.
*
*   @addtogroup QOM
*   @{
*/

#ifndef QOM_H_
#define QOM_H_

#include "QOM_LLDrivers.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "eTPU_Cfg.h"
#include "eTPU_LLDrivers.h"

#define QOM_C_VENDOR_ID_PLUGIN             176
#define QOM_C_AR_REL_MAJOR_VER				4
#define QOM_C_AR_REL_MINOR_VER			    4
#define QOM_C_AR_REL_REV_VER   		        0
#define QOM_C_SW_MAJOR_VER                  3
#define QOM_C_SW_MINOR_VER                  0
#define QOM_C_SW_PATCH_VER                  0

#define CDD_QOM_MODULE_ID                       110

#define CDD_QOM_SID_INIT                      ((uint8)0x00U)
#define CDD_QOM_SID_SOFTTRIG                  ((uint8)0x01U)
#define CDD_QOM_SID_GETSTATE                  ((uint8)0x02U)

#define CDD_QOM_E_PARAM_POINTER               ((uint8)0x00U)
#define CDD_QOM_E_PARAM_CHANNEL               ((uint8)0x01U)

#define CDD_QOM_GetState_Sending              ((uint8)0x00U)
#define CDD_QOM_GetState_COMPLETE             ((uint8)0x01U)

#if (ETPU_VENDOR_ID_OUTPUT != QOM_C_VENDOR_ID_PLUGIN)
    #error " NON-MATCHED DATA : QOM_C_VENDOR_ID_PLUGIN "
#endif
#if (ETPU_AR_REL_MAJOR_VER_OUTPUT != QOM_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : QOM_C_AR_REL_MAJOR_VER "
#endif
#if (ETPU_AR_REL_MINOR_VER_OUTPUT != QOM_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : QOM_C_AR_REL_MINOR_VER "
#endif
#if (ETPU_AR_REL_REVISION_VER_OUTPUT != QOM_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : QOM_C_AR_REL_REV_VER "
#endif
#if (ETPU_SW_MAJOR_VERSION_OUTPUT != QOM_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : QOM_C_SW_MAJOR_VER "
#endif
#if (ETPU_SW_MINOR_VERSION_OUTPUT != QOM_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : QOM_C_SW_MINOR_VER "
#endif
#if (ETPU_SW_PATCH_VERSION_OUTPUT != QOM_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : QOM_C_SW_PATCH_VER "
#endif

#if ((ETPU_QOM_INSTANCE_NUM != 0U)&&(QOM_MODULE_ENABLE !=STD_OFF))

extern CONST(etpu_channel_qom_config_t, ETPU_CONST) Etpu_Qom_Config;

extern P2CONST(etpu_channel_qom_config_t, ETPU_CONST, ETPU_APPL_CONST) eTPU_QOM_ConfigPtr;

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) eTPU_QOM_Init
(
	P2CONST(etpu_channel_qom_config_t, ETPU_CONST, ETPU_APPL_CONST) ConfigPtr, \
	VAR(uint8, ETPU_VAR) u8Qom_ChannelIdx, \
	VAR(uint8, ETPU_VAR) u8Qom_EventIdx
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) eTPU_QOM_SetClose(VAR(uint8, ETPU_VAR) u8Qom_ChannelIdx);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) eTPU_QOM_GetState(VAR(uint8, ETPU_VAR) u8Qom_ChannelIdx);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#endif /* QOM_H_ */
#endif
#endif

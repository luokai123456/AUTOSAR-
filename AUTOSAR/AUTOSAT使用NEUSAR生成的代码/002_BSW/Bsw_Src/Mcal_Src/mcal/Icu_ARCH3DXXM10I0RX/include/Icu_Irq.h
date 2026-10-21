/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC 
*   Peripheral           : ICU
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
*   @file    Icu_Irq.h
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
#ifndef ICU_IRQ_H
#define ICU_IRQ_H

#ifdef __cplusplus
extern "C"
{
#endif

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Icu_eMIOS_Types.h"
#include "Icu.h"

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_IRQ_VENDOR_ID_H                   176

#define ICU_IRQ_MAJOR_VER_H                   4
#define ICU_IRQ_MINOR_VER_H                   4
#define ICU_IRQ_REVISION_VER_H                0

#define ICU_IRQ_SW_MAJOR_VER_H                3
#define ICU_IRQ_SW_MINOR_VER_H                0
#define ICU_IRQ_SW_PATCH_VER_H                0

#if (ICU_IRQ_VENDOR_ID_H != ICU_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_IRQ_MAJOR_VER_H != ICU_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_IRQ_MINOR_VER_H != ICU_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_IRQ_REVISION_VER_H != ICU_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_IRQ_SW_MAJOR_VER_H != ICU_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_IRQ_SW_MINOR_VER_H != ICU_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_IRQ_SW_PATCH_VER_H != ICU_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define ICU_ReportWakeupAndOverflow(Channel, bOverflow) \
    Icu_ReportWakeupAndOverflow((Channel), (bOverflow))

#define ICU_AutoSAR_Wapper_ReportEvents(Channel, bOverflow) \
    Icu_ReportEvents((Channel), (bOverflow))

#define ICU_AutoSAR_Wapper_Timestamp(Channel, u8CapturedWords, pBufferPtr, bOverflow) \
    Icu_Timestamp((Channel), (u8CapturedWords), (pBufferPtr), (bOverflow))

#define ICU_SignalMeasurement(Channel, activePulseWidth, period, bOverflow) \
    Icu_SignalMeasurement((Channel), (activePulseWidth), (period), ((bOverflow)))

#define ICU_ATS_Gtm_Wapper_GetInstance(Module, Channel) \
    Icu_Gtm_Wrapper_GetInstance((Module), (Channel))

#define ICU_ATS_eMios_Wapper_GetInstance(Module, Channel) \
    Icu_eMios_Wrapper_GetInstance((Module), (Channel))

#define ICU_ATS_eTpu_Wapper_GetInstance(Module, Channel) \
    Icu_eTpu_Wrapper_GetInstance((Module), (Channel))

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void,ICU_CODE) ICU_GTM_Callback_From_IRQ
(
    VAR(uint8, AUTOMATIC) u8Icu_ModuleId,
    VAR(uint8, AUTOMATIC) u8Icu_ChannelId
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void,ICU_CODE) ICU_eMIOS_Callback_From_IRQ
(
    VAR(uint8, AUTOMATIC) u8Icu_ModuleId,
    VAR(uint8, AUTOMATIC) u8Icu_ChannelId
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (defined(RESOURCE_SUPPORT_ETPU))
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void,ICU_CODE) ICU_eTPU_Callback_From_IRQ
( \
    VAR(uint8, AUTOMATIC) u8Icu_ModuleId, \
    VAR(uint8, AUTOMATIC) u8Icu_ChannelId \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) ICU_TimeStamp_Callback_From_DMA
( \
	P2CONST(void,             AUTOMATIC, ICU_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) ICU_SingalMeasurement_Callback_From_DMA
( \
	P2CONST(void,             AUTOMATIC, ICU_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#ifdef __cplusplus
}
#endif
#endif /* ICU_IRQ_H */


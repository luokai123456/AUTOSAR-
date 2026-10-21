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
*   @file    EBPPA.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of EBPPA MCAL driver.
*
*   @addtogroup EBPPA
*   @{
*/
/* PRQA S 3432 EOF */

#ifndef EBPPA_H_
#define EBPPA_H_

#include "eTPU_LLDrivers.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "EBPPA_LLDrivers.h"
#include "eTPU_Cfg.h"

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define EBPPA_VENDOR_ID_H                   176

#define EBPPA_MAJOR_VER_H                   4
#define EBPPA_MINOR_VER_H                   4
#define EBPPA_REVISION_VER_H                0

#define EBPPA_SW_MAJOR_VER_H                3
#define EBPPA_SW_MINOR_VER_H                0
#define EBPPA_SW_PATCH_VER_H                0

#if (EBPPA_VENDOR_ID_H != ETPU_VENDOR_ID_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_VENDOR_ID_H"
#endif

/* Check if current file and EBPPA header file are of the same Autosar version */
#if (EBPPA_MAJOR_VER_H != ETPU_AR_REL_MAJOR_VER_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_MAJOR_VER_H"
#endif
#if (EBPPA_MINOR_VER_H != ETPU_AR_REL_MINOR_VER_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_MINOR_VER_H"
#endif
#if (EBPPA_REVISION_VER_H != ETPU_AR_REL_REVISION_VER_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_REVISION_VER_H"
#endif

/* Check if current file and EBPPA header file are of the same Software version */
#if (EBPPA_SW_MAJOR_VER_H != ETPU_SW_MAJOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_SW_MAJOR_VER_H"
#endif
#if (EBPPA_SW_MINOR_VER_H != ETPU_SW_MINOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_SW_MINOR_VER_H"
#endif
#if (EBPPA_SW_PATCH_VER_H != ETPU_SW_PATCH_VERSION_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_SW_PATCH_VER_H"
#endif

#if ((EBPPA_INSTANCE_NUM != 0U)&&(EBPPA_MODULE_ENABLE !=STD_OFF))
#define EBPPA_INIT_ID                         ((uint8)0x01)
#define EBPPA_GET_ACCUMULATION_ID             ((uint8)0x02)
#define EBPPA_GET_IMMEDIATE_ID                ((uint8)0x03)
#define EBPPA_GETCOUNT_ID                     ((uint8)0x04)
#define EBPPA_RESETCOUNT_ID                   ((uint8)0x05)

#define EBPPA_E_PARAM_POINTER                 ((uint8)0x0A)
#define EBPPA_E_PARAM_GROUP                   ((uint8)0x0B)
#define EBPPA_E_PARAM_CHANNEL                 ((uint8)0x0C)

#define ETPU_CH_0                      (uint8)0U
#define ETPU_CH_1                      (uint8)1U
#define ETPU_CH_2                      (uint8)2U
#define ETPU_CH_3                      (uint8)3U
#define ETPU_CH_4                      (uint8)4U
#define ETPU_CH_5                      (uint8)5U
#define ETPU_CH_6                      (uint8)6U
#define ETPU_CH_7                      (uint8)7U
#define ETPU_CH_8                      (uint8)8U
#define ETPU_CH_9                      (uint8)9U
#define ETPU_CH_10                     (uint8)10U
#define ETPU_CH_11                     (uint8)11U
#define ETPU_CH_12                     (uint8)12U
#define ETPU_CH_13                     (uint8)13U
#define ETPU_CH_14                     (uint8)14U
#define ETPU_CH_15                     (uint8)15U
#define ETPU_CH_16                     (uint8)16U
#define ETPU_CH_17                     (uint8)17U
#define ETPU_CH_18                     (uint8)18U
#define ETPU_CH_19                     (uint8)19U
#define ETPU_CH_20                     (uint8)20U
#define ETPU_CH_21                     (uint8)21U
#define ETPU_CH_22                     (uint8)22U
#define ETPU_CH_23                     (uint8)23U
#define ETPU_CH_24                     (uint8)24U
#define ETPU_CH_25                     (uint8)25U
#define ETPU_CH_26                     (uint8)26U
#define ETPU_CH_27                     (uint8)27U
#define ETPU_CH_28                     (uint8)28U
#define ETPU_CH_29                     (uint8)29U
#define ETPU_CH_30                     (uint8)30U
#define ETPU_CH_31                     (uint8)31U

#define EBPPA_CORE_NUM                 MCAL_CORE_NUM
#define EBPPA_DEFAULT_COREID           ((uint32)2U)
#if(EBPPA_MULTI_CORE_SUPPORT == STD_ON)
    #define EBPPA_GetCoreID()                 (1U << GetCoreID())
#else
    #define EBPPA_GetCoreID()                 (1U << EBPPA_DEFAULT_COREID)

#endif

/**
* Definition of EBPPA channel input pin level
*/
typedef enum
{
    EBPPA_LEVEL_LOW           = 0x0U,         /**< The input pin level is low */
    EBPPA_LEVEL_HIGH          = 0x1U          /**< The input pin level is high */
} EBPPA_LevelType;

#define EBPPA_CHN_USED                        ((uint8)255U)
#define EBPPA_CHN_UNUSED                      ((uint8)0U)

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) EBPPA_Get_Accumulation(VAR(uint8, EBPPA_VAR) u8Ebppa_ChannelIdx, \
											   P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PeriodData, \
											   P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_DutyData);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) EBPPA_Get_Immediate(VAR(uint8, EBPPA_VAR) u8Ebppa_ChannelIdx, \
											P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PeriodData, \
											P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_DutyData);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) EBPPA_GetCount(VAR(uint8, EBPPA_VAR) u8Ebppa_ChannelIdx, \
                                       P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_CurrentCount);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) EBPPA_ResetCount(VAR(uint8, EBPPA_VAR) u8Ebppa_ChannelIdx, \
                                         P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_CurrentCount);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(EBPPA_LevelType,EBPPA_CODE) EBPPA_GetInputLevel(VAR(uint8, EBPPA_VAR) u16EBPPA_Channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#if (EBPPA_DEV_ERROR_DETECT == STD_ON)
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(Std_ReturnType, EBPPA_CODE) EBPPA_Init_Verify(P2CONST(ebppa_config_t, AUTOMATIC, EBPPA_APPL_CONST) ConfigPtr);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
#endif/*EBPPA_DEV_ERROR_DETECT == STD_ON*/

#endif/*EBPPA_INSTANCE_NUM != 0U*/

#endif

#endif /* EBPPA_H_ */


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
*   @file    EBPPA_LLDriver.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of EBPPA MCAL driver.
*
*   @addtogroup EBPPA
*   @{
*/

#ifndef EBPPA_LLDRIVERS_H_
#define EBPPA_LLDRIVERS_H_

#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "status.h"
#include "eTPU_Cfg.h"


/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define EBPPA_LLDRIVERS_VENDOR_ID_H                   176

#define EBPPA_LLDRIVERS_MAJOR_VER_H                   4
#define EBPPA_LLDRIVERS_MINOR_VER_H                   4
#define EBPPA_LLDRIVERS_REVISION_VER_H                0

#define EBPPA_LLDRIVERS_SW_MAJOR_VER_H                3
#define EBPPA_LLDRIVERS_SW_MINOR_VER_H                0
#define EBPPA_LLDRIVERS_SW_PATCH_VER_H                0

#if (EBPPA_LLDRIVERS_VENDOR_ID_H != ETPU_VENDOR_ID_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_LLDRIVERS_VENDOR_ID_H"
#endif

/* Check if current file and EBPPA header file are of the same Autosar version */
#if (EBPPA_LLDRIVERS_MAJOR_VER_H != ETPU_AR_REL_MAJOR_VER_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_LLDRIVERS_MAJOR_VER_H"
#endif
#if (EBPPA_LLDRIVERS_MINOR_VER_H != ETPU_AR_REL_MINOR_VER_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_LLDRIVERS_MINOR_VER_H"
#endif
#if (EBPPA_LLDRIVERS_REVISION_VER_H != ETPU_AR_REL_REVISION_VER_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_LLDRIVERS_REVISION_VER_H"
#endif

/* Check if current file and EBPPA header file are of the same Software version */
#if (EBPPA_LLDRIVERS_SW_MAJOR_VER_H != ETPU_SW_MAJOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_LLDRIVERS_SW_MAJOR_VER_H"
#endif
#if (EBPPA_LLDRIVERS_SW_MINOR_VER_H != ETPU_SW_MINOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_LLDRIVERS_SW_MINOR_VER_H"
#endif
#if (EBPPA_LLDRIVERS_SW_PATCH_VER_H != ETPU_SW_PATCH_VERSION_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_LLDRIVERS_SW_PATCH_VER_H"
#endif

#if ((EBPPA_INSTANCE_NUM != 0U)&&(EBPPA_MODULE_ENABLE !=STD_OFF))
/**************************************************************************/
/* Function Configuration Information */
#define ETPU_EBPPA_FUNCTION_NUMBER  7UL
#define ETPU_EBPPA_TABLE_SELECT 1UL
#define ETPU_EBPPA_NUM_PARMS 0x0020U

/* Host Service Request Definitions -timer options*/
#define ETPU_EBPPA_INIT_TCR1 7U
#define ETPU_EBPPA_INIT_TCR2 5U

/* Function Mode Bit Definitions - pulse/period measurement options - mode options */
#define ETPU_EBPPA_LOW_PULSE  0U
#define ETPU_EBPPA_HIGH_PULSE 2U

/* Parameter Definitions */
#define ETPU_EBPPA_ACCUM_PULSE_OFFSET  0x0010U
#define ETPU_EBPPA_ACCUM_PERIOD_OFFSET  0x0014U
#define ETPU_EBPPA_SAMPLE_TIME_OFFSET  0x000DU
#define ETPU_EBPPA_PERIOD_COUNT_OFFSET  0x0009U
#define ETPU_EBPPA_MAX_COUNT_OFFSET  0x0005U
#define ETPU_EBPPA_RESULT_PULSE_OFFSET  0x0018U
#define ETPU_EBPPA_RESULT_PERIOD_OFFSET  0x001CU
#define ETPU_EBPPA_STAT_ACC_OFFSET  0x0008U
#define ETPU_EBPPA_STATUS_OFFSET  0x000CU

/* Additional Definitions */
#define ETPU_EBPPA_PERIOD_OVERFLOW 0x80U
#define ETPU_EBPPA_PULSE_OVERFLOW 0x40U

/**************************************************************************/
/*                       Function Prototypes                              */
/**************************************************************************/

/* EBPPA channel initialization */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, EBPPA_CODE) ETPU_LLD_EBPPA_Init \
(
	VAR(uint8, EBPPA_VAR) u8Ebppa_EtpuGroup, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_priority, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_timebase, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_mode, \
	VAR(uint32, EBPPA_VAR) u8Ebppa_MaxCount, \
	VAR(uint32, EBPPA_VAR) u8Ebppa_SampleTime
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
                       
                       
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) ETPU_LLD_EBPPA_Get_Accumulation \
(
	VAR(uint8, EBPPA_VAR) u8Ebppa_EtpuGroup, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel, \
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PeriodResult, \
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PulseResult
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) ETPU_LLD_EBPPA_Get_Immediate \
( \
	VAR(uint8, EBPPA_VAR) u8Ebppa_EtpuGroup, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel, \
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PeriodResult, \
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PulseResult
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) ETPU_LLD_EBPPA_GetCount \
( \
	VAR(uint8, EBPPA_VAR) u8Ebppa_EtpuGroup, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel, \
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_CurrentCount
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) ETPU_LLD_EBPPA_ResetCount \
( \
	VAR(uint8, EBPPA_VAR) u8Ebppa_EtpuGroup, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel, \
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_CurrentCount
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

typedef struct 
{
	VAR(uint8, EBPPA_VAR) EbppaChannelId;
	VAR(uint8, EBPPA_VAR) etpuGroup;
	VAR(uint8, EBPPA_VAR) channel;
	VAR(uint8, EBPPA_VAR) priority;
	VAR(uint8, EBPPA_VAR) timebase;
	VAR(uint8, EBPPA_VAR) mode;
	VAR(uint32, EBPPA_VAR) max_count;
	VAR(uint32, EBPPA_VAR) sample_time;
} ebppa_channel_config_t;


typedef struct
{
    CONST(uint8, EBPPA_CONST) nChannelId;
    CONST(uint8, EBPPA_CONST) nCoreId;
} EBPPA_CoreMapItemType;
typedef struct 
{
	VAR(uint8, EBPPA_VAR) channelTotal;
	P2CONST(ebppa_channel_config_t, ATUPMATIC, EBPPA_APPL_DATA) ebppa_ChannelConfigPtr;
	P2CONST(EBPPA_CoreMapItemType, EBPPA_CONST, EBPPA_APPL_DATA) ebppa_CoreMap;
}ebppa_config_t;

#endif/*EBPPA_INSTANCE_NUM != 0U*/

#endif /* RESOURCE_SUPPORT_ETPU */

#endif /* EBPPA_LLDRIVERS_H_ */

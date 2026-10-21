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
*   @file    eTPU_LLDriver.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eTPU MCAL driver.
*
*   @addtogroup eTPU
*   @{
*/

#ifndef ETPU_LLDRIVERS_H_
#define ETPU_LLDRIVERS_H_

/*******************************************************************************
* Includes
*******************************************************************************/

#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "status.h"
#include "eTPU_Cfg.h"
#include "EBPPA_LLDrivers.h"
#include "QOM_LLDrivers.h"
#include "sPwm_LLDrivers.h"


#define ETPU_LLD_WRA_H_VENDOR_ID                     176
#define ETPU_LLD_WRA_H_AR_REL_MAJOR_VER              4
#define ETPU_LLD_WRA_H_AR_REL_MINOR_VER              4
#define ETPU_LLD_WRA_H_AR_REL_REV_VER                0
#define ETPU_LLD_WRA_H_SW_MAJOR_VER                  3
#define ETPU_LLD_WRA_H_SW_MINOR_VER                  0
#define ETPU_LLD_WRA_H_SW_PATCH_VER                  0

#if (ETPU_VENDOR_ID_OUTPUT != ETPU_LLD_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ETPU_LLD_WRA_H_VENDOR_ID "
#endif
#if (ETPU_AR_REL_MAJOR_VER_OUTPUT != ETPU_LLD_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETPU_LLD_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (ETPU_AR_REL_MINOR_VER_OUTPUT != ETPU_LLD_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETPU_LLD_WRA_H_AR_REL_MINOR_VER "
#endif
#if (ETPU_AR_REL_REVISION_VER_OUTPUT != ETPU_LLD_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETPU_LLD_WRA_H_AR_REL_REV_VER "
#endif
#if (ETPU_SW_MAJOR_VERSION_OUTPUT != ETPU_LLD_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETPU_LLD_WRA_H_SW_MAJOR_VER "
#endif
#if (ETPU_SW_MINOR_VERSION_OUTPUT != ETPU_LLD_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETPU_LLD_WRA_H_SW_MINOR_VER "
#endif
#if (ETPU_SW_PATCH_VERSION_OUTPUT != ETPU_LLD_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETPU_LLD_WRA_H_SW_PATCH_VER "
#endif

#define ETPU_INSTANCE_A_B 0U
#define ETPU_INSTANCE_C   1U
#define FS_ETPU_ENTRY_TABLE  0x0000U
#define FS_ETPU_MISC         0x3A96FE38

#define ETPU_A_CHANNLE(x) (x)
#define ETPU_B_CHANNLE(x) (uint8)((uint32)(x) + 64U)
#define ETPU_C_CHANNLE(x) (x)

/* Instance structure */
typedef struct {
    eTPU_Type *eTPU;
    uint32 code_start;
    uint32 data_ram_start;
    uint32 data_ram_end;
    uint32 data_ram_ext;
    uint32 *free_param;
    uint8 double_engle;
} etpu_instance_t;

/* Configuration structure */
typedef struct {         /*PRQA S 3630*/
    uint32 mcr;
    uint32 misc;
    uint32 ecr_a;
    uint32 tbcr_a;
    uint32 stacr_a;
    uint32 ecr_b;
    uint32 tbcr_b;
    uint32 stacr_b;
    uint32 wdtr_a;
    uint32 wdtr_b;
} etpu_global_param_t;
typedef enum
{
    ETPU_CONFIG_INSTANCE_A_B,
    ETPU_CONFIG_INSTANCE_C,
    ETPU_CONFIG_INSTANCE_MAX
} etpu_instance_type_t;

typedef struct  
{
    VAR(etpu_instance_type_t, ETPU_VAR) etpuInstanceId;
    VAR(etpu_global_param_t, ETPU_VAR) etpuConfigParameter;

} eTPU_ConfigType;


extern CONST(eTPU_ConfigType, ETPU_CONST) etpuConfig[ETPU_INSTANCE_NUM];
#if ((EBPPA_INSTANCE_NUM != 0U)&&(EBPPA_MODULE_ENABLE !=STD_OFF))
extern CONST(ebppa_config_t, ETPU_CONST) ebppa_Config;
#endif

#if ((ETPU_QOM_INSTANCE_NUM != 0U)&&(QOM_MODULE_ENABLE !=STD_OFF))
extern CONST(etpu_channel_qom_config_t, ETPU_CONST) Etpu_Qom_Config;
#endif

#if ((SPWM_MASTER_NUM != 0U)&&(SPWM_MODULE_ENABLE !=STD_OFF))
extern CONST(spwm_config_t, SPWM_CONST) sPwm_Config;
#endif

typedef struct
{
    P2CONST(eTPU_ConfigType, ETPU_CONST, ETPU_APPL_DATA) etpuConfigPtr;

    #if ((EBPPA_INSTANCE_NUM != 0U)&&(EBPPA_MODULE_ENABLE !=STD_OFF))
    P2CONST(ebppa_config_t, ETPU_CONST, ETPU_APPL_DATA) ebppaConfigPtr;
    #endif

    #if ((ETPU_QOM_INSTANCE_NUM != 0U)&&(QOM_MODULE_ENABLE !=STD_OFF))
    P2CONST(etpu_channel_qom_config_t, ETPU_CONST, ETPU_APPL_DATA) qomConfigPtr;
    #endif

    #if ((SPWM_MASTER_NUM != 0U)&&(SPWM_MODULE_ENABLE !=STD_OFF))
    P2CONST(spwm_config_t, ETPU_CONST, ETPU_APPL_DATA) spwmConfigPtr;
    #endif
} eTPU_Total_ConfigType;

/***************************************************************************//*!
* @brief   Channel number expressed by (engine, channel)
* @note    All channel numbers for both eTPUs are absolute.
*          eTPU_A has channels 0-31 and eTPU_B has channels 64-95.
*******************************************************************************/
#define ETPU_ENGINE_CHANNEL(x,y) (((x)-1)*64 + (y))

/***************************************************************************//*!
* @brief   Transformation from absolute channel number to link register encoding
*******************************************************************************/
#define ETPU_CHANNEL_TO_LINK(x)  ((x)+64)

/*******************************************************************************
* Definition of Terms
*******************************************************************************/
/* Channel Priority values used by several function APIs */
#define ETPU_PRIORITY_HIGH         0x3
#define ETPU_PRIORITY_MIDDLE       0x2
#define ETPU_PRIORITY_LOW          0x1
#define ETPU_PRIORITY_DISABLE      0x0

#define ETPU_PIN_HIGH 1
#define ETPU_PIN_LOW  0

/* eTPU timebases */
#define ETPU_TCR1   0u
#define ETPU_TCR2   1
#define ETPU_TCR1_A 0
#define ETPU_TCR2_A 1
#define ETPU_TCR1_B 0
#define ETPU_TCR2_B 1

/* MCR - Module Configuration Register */
#define ETPU_MISC_ENABLE            0x00000200 /* Code RAM MISC Enable */
#define ETPU_MISC_DISABLE           0x00000000

#define ETPU_VIS_ON                 0x00000040 /* Code RAM Visibility */
#define ETPU_VIS_OFF                0x00000000

#define ETPU_GLOBAL_TIMEBASE_ENABLE  0x00000001 /* Global Time Base Enable */
#define ETPU_GLOBAL_TIMEBASE_DISABLE 0x00000000

#define ETPU_SDM_READ_ERROR         0x40000000  /* eTPU2 only */
#define ETPU_WATCHDOG_TIMEOUT_A     0x20000000  /* eTPU2 only */
#define ETPU_WATCHDOG_TIMEOUT_B     0x10000000  /* eTPU2 only */
#define ETPU_MICROCODE_GLOBAL_EX_A  0x08000000
#define ETPU_MICROCODE_GLOBAL_EX_B  0x04000000
#define ETPU_ILLEGAL_INSTRUCTION_A  0x02000000
#define ETPU_ILLEGAL_INSTRUCTION_B  0x01000000
#define ETPU_SHARED_SUBSYS_ACC_ERR  0x00800000  /* eTPU2 only */
#define ETPU_SCM_MISC_FLAG          0x00000400
#define ETPU_SCM_READ_ERROR         0x00000100  /* eTPU2 only */

/* ECR - Engine Configuration Register */
#define ETPU_FILTER_CLOCK_DIV2      0x00000000 /* Filter Prescaler Clock */
#define ETPU_FILTER_CLOCK_DIV4      0x00010000 /* Control                */
#define ETPU_FILTER_CLOCK_DIV8      0x00020000U
#define ETPU_FILTER_CLOCK_DIV16     0x00030000
#define ETPU_FILTER_CLOCK_DIV32     0x00040000
#define ETPU_FILTER_CLOCK_DIV64     0x00050000
#define ETPU_FILTER_CLOCK_DIV128    0x00060000
#define ETPU_FILTER_CLOCK_DIV256    0x00070000

#define ETPU_FCSS_DIV2              0x00000000 /* Filter Clock Source Selection */
#define ETPU_FCSS_DIV1              0x00080000 /* eTPU2 only */

#define ETPU_CHAN_FILTER_2SAMPLE    0x00000000 /* Channel filter mode */
#define ETPU_CHAN_FILTER_3SAMPLE    0x00008000U
#define ETPU_CHAN_FILTER_CONT       0x0000C000
#define ETPU_CHAN_FILTER_BYPASS     0x00004000 /* eTPU2 only */

#define ETPU_ENGINE_ENABLE          0x00000000  /* Low Power Stop Bit */
#define ETPU_ENGINE_DISABLE         0x40000000

#define ETPU_PRIORITY_PASSING_ENABLE   0x00000000 /* Scheduler Priority Passing */
#define ETPU_PRIORITY_PASSING_DISABLE  0x00000080 /* eTPU2 only */

/* TBCR - Time Base Configuration Register */
#define ETPU_TCRCLK_MODE_2SAMPLE     0x00000000 /* TCRCLK Signal Filter Control*/
#define ETPU_TCRCLK_MODE_INTEGRATION 0x10000000
#define ETPU_TCRCLK_INPUT_DIV2CLOCK  0x00000000
#define ETPU_TCRCLK_INPUT_CHANCLOCK  0x08000000

#define ETPU_TCR1CTL_TCRCLK         0x00000000U  /* TCR1 Clock/Gate Control */
#define ETPU_TCR1CTL_DIV2           0x00008000U

#define ETPU_TCR1CS_DIV2            0x00000000  /* TCR1 Clock Source */
#define ETPU_TCR1CS_DIV1            0x00002000  /* eTPU2 only */

#define ETPU_ANGLE_MODE_ENABLE      0x02000000   /* Angle Mode */
#define ETPU_ANGLE_MODE_DISABLE     0x00000000
#define ETPU_ANGLE_MODE_ENABLE_CH1  0x04000000   /* eTPU2 only */
#define ETPU_ANGLE_MODE_ENABLE_CH2  0x06000000   /* eTPU2 only */

#define ETPU_TCR2CTL_GATEDDIV8      0x00000000U   /* TCR2 Clock/Gate Control */
#define ETPU_TCR2CTL_RISE           0x20000000U
#define ETPU_TCR2CTL_FALL           0x40000000U
#define ETPU_TCR2CTL_RISEFALL       0x60000000U
#define ETPU_TCR2CTL_DIV8           0x80000000U

#define ETPU_TCR1_PRESCALER(x)      (((x)-1) & 0xFF) /* TCR1 Prescaler, x = 1 to 256 */
#define ETPU_TCR2_PRESCALER(x)      ((((x)-1) & 0x3F)<<16) /* TCR2 Prescaler, x = 1 to 64 */

/* STACR - Shared Time And Angle Count Register */
#define ETPU_TCR1_STAC_ENABLE       0x80000000   /* TCR1 Resource Enable */
#define ETPU_TCR1_STAC_DISABLE      0x00000000

#define ETPU_TCR1_STAC_CLIENT       0x00000000   /* TCR1 Resource Control */
#define ETPU_TCR1_STAC_SERVER       0x40000000

#define ETPU_TCR1_STAC_SRVSLOT(x)   (((x) & 0xF)<<16) /* TCR1 Server Slot, x = 0 to 3 */

#define ETPU_TCR2_STAC_ENABLE       0x00008000   /* TCR2 Resource Enable */
#define ETPU_TCR2_STAC_DISABLE      0x00000000

#define ETPU_TCR2_STAC_CLIENT       0x00000000   /* TCR2 Resource Control */
#define ETPU_TCR2_STAC_SERVER       0x00004000

#define ETPU_TCR2_STAC_SRVSLOT(x)   ((x) & 0xF)  /* TCR2 Server Slot, x = 0 to 3 */

/* WDTR - Watchdog Timer Register - eTPU2 only */
#define ETPU_WDM_DISABLED           0x00000000 /* Watchdog Mode */
#define ETPU_WDM_THREAD_LEN         0x80000000 /* eTPU2 only */
#define ETPU_WDM_BUSY_LEN           0xC0000000 /* eTPU2 only */

#define ETPU_WDTR_WDCNT(x)      ((x) & 0xFFFF) /* Watchdog Count - eTPU2 only */

/* CxCR - Channel x Configuration Register */
#define ETPU_INTERRUPT_ENABLE       0x80000000  /* Channel Interrupt Enable */
#define ETPU_INTERRUPT_DISABLE      0x00000000

#define ETPU_DMA_ENABLE             0x40000000  /* Data Transfer Request Enable*/
#define ETPU_DMA_DISABLE            0x00000000

#define ETPU_ENTRY_TABLE_STANDARD   0x00000000  /* Entry Table Condition Select*/
#define ETPU_ENTRY_TABLE_ALTERNATE  0x01000000

#define ETPU_ENTRY_TABLE_PIN_INPUT  0x00000000  /* Entry Table Pin Direction*/
#define ETPU_ENTRY_TABLE_PIN_OUTPUT 0x02000000

#define ETPU_OUTPUT_DISABLE_OFF     0x00000000  /* Output Disable */
#define ETPU_OUTPUT_DISABLE_LOW     0x0000C000
#define ETPU_OUTPUT_DISABLE_HIGH    0x00008000

/* eTPU error return codes */
#define ETPU_ERROR_NONE             0
#define ETPU_ERROR_MALLOC           1
#define ETPU_ERROR_FREQ             2
#define ETPU_ERROR_VALUE            3
#define ETPU_ERROR_CODESIZE         4
#define ETPU_ERROR_VIS_BIT_NOT_SET  5
#define ETPU_ERROR_ADDRESS          6
#define ETPU_ERROR_TIMING           7

/*******************************************************************************
* Global variables
*******************************************************************************/

extern etpu_instance_t eTPUInstance[2];

/*-----------------------Channel Configuration Register CR-----------------------------*/

/*
 * @brief   This function enables an eTPU channel to generate interrupts.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelInterruptEnable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*
 * @brief   This function disables an eTPU channel from generating interrupts.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelInterruptDisable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*
 * @brief   This function enables an eTPU channel to request DMA service.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelDMAEnable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*
 * @brief   This function disables an eTPU channel from generating DMA requests.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelDMADisable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*
 * @brief   This function enables or changes the priority of an eTPU channel.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 * @param[in]   priority - The priority to be assigned to the channel.
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelEnable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint8, AUTOMATIC) priority
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*
 * @brief   This function disables an eTPU channel.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelDisable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*
 * @brief   This function disables an eTPU channel.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetChannelParameterBaseAddress \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*
 * @brief   This function enables or disables the channel "output disable"
 *          feature for each engine A channel according to the given mask and
 *          polarity.
 * @param[in]   mask - The "output disable" enable mask.
 * @param[in]   polarity - The "output disable" polarity mask.
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetOutputDisableMask_A \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) mask, \
    VAR(uint32, AUTOMATIC) polarity
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_SetOutputDisableMask_B
****************************************************************************//*!
* @brief   This function enables or disables the channel "output disable"
*          feature for each engine B channel according to the given mask and
*          polarity.
*
* @param   mask - The "output disable" enable mask. A value of:
*          - 0x00000001 enables the "output disable" feature on channel 64 only,
*          - 0x80000000 enables the "output disable" feature on channel 95 only
* @param   polarity - The "output disable" polarity mask. A value of:
*          - 0x00000001 sets the high polarity of disabled output on channel 64
*            and low polarity of disabled output on all other channels
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetOutputDisableMask_B \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) mask, \
    VAR(uint32, AUTOMATIC) polarity
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*-----------------------Channel Status Control Register SCR-----------------------------*/

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetInterruptFlag
****************************************************************************//*!
* @brief   This function returns the current value of the Channel Interrupt
*          Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of CIS bit of the specified channel SCR register.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) ETPU_LLD_GetInterruptFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_GetInterruptOverflowFlag
****************************************************************************//*!
* @brief   This function returns the current value of the Channel Interrupt
*          Overflow Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of CIOS bit of the specified channel SCR register.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) ETPU_LLD_GetInterruptOverflowFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_GetChannelDMAFlag
****************************************************************************//*!
* @brief   This function returns the current value of the Data Transfer Request
*          Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of DTRS bit of the specified channel SCR register.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) ETPU_LLD_GetChannelDMAFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_GetDMAOverflowFlag
****************************************************************************//*!
* @brief   This function returns the current value of the Data Transfer Request
*          Oveflow Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of DTROS bit of the specified channel SCR register.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) ETPU_LLD_GetDMAOverflowFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*-----------------------Channel Host Service Request Register HSR-----------------------------*/

/*
 * @brief   This function sets the Host Service Request (HSR) register of the
 *          specified eTPU channel.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 * @param[in]   hsr - The HSR value to send to the channel
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetHSR \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint8, AUTOMATIC) hsr
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*
 * @brief   This function returns the current value of the Host Service Request
 *          (HSR) register of the specified eTPU channel.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 * @return  The value of HSR register
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) ETPU_LLD_GetHSR \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*-----------------------Interruput Enable Register GCR_CIER-----------------------------*/

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetInterruptMask_A
****************************************************************************//*!
* @brief   This function enables or disables channel interrupt for each engine A
*          channel according to the given mask.
*
* @param   mask - The interrupt enable mask. A value of:
*          - 0x00000001 enables interrupt on channel 0 only,
*          - 0x80000000 enables interrupt on channel 31 only
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetInterruptMask_A \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) mask
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetInterruptMask_B
****************************************************************************//*!
* @brief   This function enables or disables channel interrupt for each engine B
*          channel according to the given mask.
*
* @param   mask - The interrupt enable mask. A value of:
*          - 0x00000001 enables interrupt on channel 64 only,
*          - 0x80000000 enables interrupt on channel 95 only
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetInterruptMask_B \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) mask
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelIntMaskEnable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelIntMaskDisable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
  uint8 ETPU_LLD_GetChannelIntMaskStatus(uint8 etpuGroup,
                                                uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*-----------------------Channel Host Service Request Register HSR-----------------------------*/

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetDMAMask_A
****************************************************************************//*!
* @brief   This function enables or disables channel DMA request for each engine
*          A channel according to the given mask.
*
* @param   mask - The DMA enable mask. A value of:
*          - 0x00000001 enables DMA requests on channel 0 only,
*          - 0x80000000 enables DMA requests on channel 31 only
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetDMAMask_A \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) mask
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_SetDMAMask_B
****************************************************************************//*!
* @brief   This function enables or disables channel DMA request for each engine
*          B channel according to the given mask.
*
* @param   mask - The DMA enable mask. A value of:
*          - 0x00000001 enables DMA requests on channel 64 only,
*          - 0x80000000 enables DMA requests on channel 95 only
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetDMAMask_B \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) mask
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelDMAMaskEnable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelDMAMaskDisable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
  uint8 ETPU_LLD_GetChannelDMAMaskStatus(uint8 etpuGroup,
                                             uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_ClearChannelInterruptFlag
****************************************************************************//*!
* @brief   This function clears the channel interrupt flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ClearChannelInterruptFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_ClearChannelInterruptOverflowFlag
****************************************************************************//*!
* @brief   This function clears the channel interrupt oveflow flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ClearChannelInterruptOverflowFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*----------------------- interrupt flag clear function -----------------------------*/

/*******************************************************************************
* FUNCTION: ETPU_LLD_ClearChannelDMAFlag
****************************************************************************//*!
* @brief   This function clears the channel data transfer request flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ClearChannelDMAFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_ClearChannelDMAOverflowFlag
****************************************************************************//*!
* @brief   This function clears the channel data transfer request oveflow flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ClearChannelDMAOverflowFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
  uint8 ETPU_LLD_GetChannelInputStatus(uint8 etpuGroup,
                                                        uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
  uint8 ETPU_LLD_GetChannelOutputStatus(uint8 etpuGroup,
                                                        uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
  void ETPU_LLD_SetChannelFunctionMode(uint8 etpuGroup,
                                                        uint8 channel,
                                                        uint8 fm);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
  uint8 ETPU_LLD_GetChannelFunctionMode(uint8 etpuGroup,
                                                        uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*----------------------- data ram parameter -----------------------------*/

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetDataRam
****************************************************************************//*!
* @brief   This function returns a pointer to the start of the data RAM for
*            the specified channel.
*
* @param   channel - The eTPU channel number
*
* @return  A pointer to the start of the eTPU DATA RAM allocated for the channel
*
* @warning This function does no error checking. If the channel has not been
*          initialized then an undefined value will be returned (normally 0).
******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
  uint32 *ETPU_LLD_GetDataRam(uint8 etpuGroup,
                                            uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_SetGlobalParameter32
****************************************************************************//*!
* @brief   This function writes to a 32-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 32-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetGlobalParameter32 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint32, AUTOMATIC) value
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_GetGlobalParameter32
****************************************************************************//*!
* @brief   This function reads a 32-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 32-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The 32-bit value of the variable.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetGlobalParameter32 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_SetGlobalParameter24
****************************************************************************//*!
* @brief   This function writes to a 24-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 24-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetGlobalParameter24 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint32, AUTOMATIC) value
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_GetGlobalParameter24
****************************************************************************//*!
* @brief   This function reads an unsigned 24-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 24-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The unsigned 24-bit value of the variable.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetGlobalParameter24 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetGlobalParameter16
****************************************************************************//*!
* @brief   This function writes to a 16-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 16-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetGlobalParameter16 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint16, AUTOMATIC) value
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetGlobalParameter16
****************************************************************************//*!
* @brief   This function reads a 16-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 16-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The 16-bit value of the variable.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint16, ETPU_CODE) ETPU_LLD_GetGlobalParameter16 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetGlobalParameter8
****************************************************************************//*!
* @brief   This function writes to an 8-bit global variable.
*
* @param   offset - The byte offset to the variable. This value is normally
*          provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetGlobalParameter8 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint8, AUTOMATIC) value
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetGlobalParameter8
****************************************************************************//*!
* @brief   This function reads an 8-bit global variable.
*
* @param   offset - The byte offset to the variable. This value is normally
*          provided by the eTPU compiler.
*
* @return  The 8-bit value of the variable.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) ETPU_LLD_GetGlobalParameter8 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetChannelParameter32
****************************************************************************//*!
* @brief   This function sets a 32-bit parameter for an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 32-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetChannelParameter32 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint32, AUTOMATIC) value
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_GetChannelParameter32
****************************************************************************//*!
* @brief   This function reads a 32-bit parameter from an eTPU channel..
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 32-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The 32-bit value of the parameter.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetChannelParameter32 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_SetChannelParameter24
****************************************************************************//*!
* @brief   This function sets a 24-bit parameter for an eTPU channel.
*
* @note    This function uses the sign extended location of the data memory
*          to write only 24 bits to the data memory. This 24 bit write is
*          an atomic operation and does not effect the upper 8 bits of the
*          32 bit value associated with the 24 bits
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 24-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetChannelParameter24 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint32, AUTOMATIC) value
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_GetChannelParameter24
****************************************************************************//*!
* @brief   This function reads a unsigned 24-bit parameter from an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 24-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The unsigned 24-bit value of the parameter.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetChannelParameter24 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetChannelParameter24Address \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"


#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetChannelParameter24S \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetChannelParameter24S \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint32, AUTOMATIC) value
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetChannelParameter24SAddress \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetChannelParameter16
****************************************************************************//*!
* @brief   This function sets a 16-bit parameter for an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 16-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetChannelParameter16 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint16, AUTOMATIC) value
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetChannelParameter16
****************************************************************************//*!
* @brief   This function reads a 16-bit parameter from an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 16-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The 16-bit value of the parameter.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint16, ETPU_CODE) ETPU_LLD_GetChannelParameter16 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_GetChannelParameter8
****************************************************************************//*!
* @brief   This function reads an 8-bit parameter from an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This value is normally
*          provided by the eTPU compiler.
*
* @return  The 8-bit value of the parameter.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) ETPU_LLD_GetChannelParameter8 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_SetChannelParameter8
****************************************************************************//*!
* @brief   This function sets an 8-bit parameter for an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This value is normally
*          provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetChannelParameter8 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint8, AUTOMATIC) value
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* Function prototypes
*******************************************************************************/

/*******************************************************************************
* FUNCTION: ETPU_LLD_Init
****************************************************************************//*!
* @brief   This function initializes the eTPU module.
*
* @note    The following actions are performed in order:
*          -# Load eTPU code into code RAM
*          -# Initialize global registers:
*             - Module Control Register
*             - MISC value
*             - Engine Control Registers
*             - TCR pre-scalers
*          -# Copy initial values of global variables to data RAM
*
* @param   p_etpu_config - This is the structure used to initialize the eTPU
* @param   *code - This is a pointer to an image of the eTPU code.
* @param   code_size - This is the size of the eTPU code in bytes.
* @param   *globals - This is a pointer to the global eTPU data that needs
*          to be initialized.
* @param   globals_size - This is the size of the global data in bytes.
*
* @return  Zero or an error code. Error codes that can be returned are:
*          - @ref FS_ETPU_ERROR_CODESIZE - When the code is too big for the
*            available memory
*          - @ref FS_ETPU_ERROR_VIS_BIT_NOT_SET - When the SCM Visibility cannot
*            be set and SCM cannot be written.
*
* @warning This function does not configure the pins, only the eTPU.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(status_t, ETPU_CODE)ETPU_LLD_Init \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    P2CONST(etpu_global_param_t, AUTOMATIC, ETPU_APPL_CONST) p_etpu_config, \
    P2CONST(uint32, AUTOMATIC, ETPU_APPL_CONST) code, \
    VAR(uint32, AUTOMATIC) code_size, \
    P2CONST(uint32, AUTOMATIC, ETPU_APPL_CONST) globals, \
    VAR(uint32, AUTOMATIC) globals_size
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_TimerStart
****************************************************************************//*!
* @brief   This function starts the timebases.
*
* @note    This functions synchronously starts the timebases of all timer
*          modules on a device.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_TimerStart \
( \
    VAR(uint8, AUTOMATIC) etpuGroup
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_Malloc_32
****************************************************************************//*!
* @brief   This function allocates DATA RAM (parameter RAM) for a channel.
*
* @param   num_bytes - this is the number of bytes that is required to
*          allocate in DATA RAM.
*
* @return  A pointer to allocated DATA RAM. If the requested amount of memory
*          is larger than the available amount of memory then 0 is returned.
*
* @warning This function is non-reentrant and uses the @ref fs_free_param global.
*          The granularity of eTPU DATA RAM allocation for channel parameters
*          is 8 bytes. The requested size is enlarged to a multiple of 8 bytes.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint32 *ETPU_LLD_Malloc_32(uint8 etpuGroup,
                          uint16 num_bytes);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint32 *ETPU_LLD_Malloc2(uint8 etpuGroup,
                           uint8 channel,
                          uint16 num_bytes);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_CoherentRead24
****************************************************************************//*!
* @brief   This function coherently reads two 24-bit variables from the eTPU
*          DATA RAM, using the Coherent Dual-Parameter Controller (CDC).
*
* @param   channel - The eTPU channel number
* @param   offset1 - The offset to the first 24-bit variable to be read
* @param   offset2 - The offset to the second 24-bit variable to be read
* @param   *value1 - A pointer to where the first variable value will be stored
* @param   *value2 - A pointer to where the second variable value will be stored
*
* @return  Zero or an error code. Error codes that can be returned are:
*          - @ref ETPU_ERROR_MALLOC - When there is not enough available
*            memory for the temporally buffer in eTPU DATA RAM
*          - @ref ETPU_ERROR_ADDRESS - When the variable offsets do not allow
*            the CDC operation.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_CoherentRead24 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset1, \
    VAR(uint32, AUTOMATIC) offset2, \
    P2VAR(uint32, AUTOMATIC, ETPU_APPL_DATA) value1, \
    P2VAR(uint32, AUTOMATIC, ETPU_APPL_DATA) value2
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_CoherentRead32
****************************************************************************//*!
* @brief   This function coherently reads two 32-bit variables from the eTPU
*          DATA RAM, using the Coherent Dual-Parameter Controller (CDC).
*
* @param   channel - The eTPU channel number
* @param   offset1 - The offset to the first 32-bit variable to be read
* @param   offset2 - The offset to the second 32-bit variable to be read
* @param   *value1 - A pointer to where the first variable value will be stored
* @param   *value2 - A pointer to where the second variable value will be stored
*
* @return  Zero or an error code. Error codes that can be returned are:
*          - @ref ETPU_ERROR_MALLOC - When there is not enough available
*            memory for the temporally buffer in eTPU DATA RAM
*          - @ref ETPU_ERROR_ADDRESS - When the variable offsets do not allow
*            the CDC operation.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_CoherentRead32 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset1, \
    VAR(uint32, AUTOMATIC) offset2, \
    P2VAR(uint32, AUTOMATIC, ETPU_APPL_DATA) value1, \
    P2VAR(uint32, AUTOMATIC, ETPU_APPL_DATA) value2
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_CoherentWrite24
****************************************************************************//*!
* @brief   This function coherently writes two 24-bit variables into the eTPU
*          DATA RAM, using the Coherent Dual-Parameter Controller (CDC).
*
* @param   channel - The eTPU channel number
* @param   offset1 - The offset to the first 24-bit variable to be written
* @param   offset2 - The offset to the second 24-bit variable to be written
* @param   value1 - The first variable value
* @param   value2 - The second variable value
*
* @return  Zero or an error code. Error codes that can be returned are:
*          - @ref ETPU_ERROR_MALLOC - When there is not enough available
*            memory for the temporally buffer in eTPU DATA RAM
*          - @ref ETPU_ERROR_ADDRESS - When the variable offsets do not allow
*            the CDC operation.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_CoherentWrite24 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset1, \
    VAR(uint32, AUTOMATIC) offset2, \
    VAR(sint32, AUTOMATIC) value1, \
    VAR(sint32, AUTOMATIC) value2
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_CoherentWrite32
****************************************************************************//*!
* @brief   This function coherently writes two 32-bit variables into the eTPU
*          DATA RAM, using the Coherent Dual-Parameter Controller (CDC).
*
* @param   channel - The eTPU channel number
* @param   offset1 - The offset to the first 32-bit variable to be written
* @param   offset2 - The offset to the second 32-bit variable to be written
* @param   value1 - The first variable value
* @param   value2 - The second variable value
*
* @return  Zero or an error code. Error codes that can be returned are:
*          - @ref ETPU_ERROR_MALLOC - When there is not enough available
*            memory for the temporally buffer in eTPU DATA RAM
*          - @ref ETPU_ERROR_ADDRESS - When the variable offsets do not allow
*            the CDC operation.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_CoherentWrite32 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset1, \
    VAR(uint32, AUTOMATIC) offset2, \
    VAR(sint32, AUTOMATIC) value1, \
    VAR(sint32, AUTOMATIC) value2
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void ETPU_LLD_Interrupt_Enable(
		uint8 etpuGroup,
  uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void ETPU_LLD_Interrupt_Disable(
		uint8 etpuGroup,
  uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint8 fs_etpu_get_chan_interrupt_flag(
		uint8 etpuGroup,
  uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void ETPU_LLD_Clear_Chan_Interrupt_Flag(
		uint8 etpuGroup,
  uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint8 fs_etpu_get_chan_interrupt_overflow_flag(
		uint8 etpuGroup,
  uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void fs_etpu_clear_chan_interrupt_overflow_flag(
		uint8 etpuGroup,
  uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void ETPU_LLD_Dma_Enable(
		uint8 etpuGroup,
  uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void ETPU_LLD_Dma_Disable(
		uint8 etpuGroup,
  uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint8 fs_etpu_get_chan_dma_flag(
		uint8 etpuGroup,
  uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void fs_etpu_clear_chan_dma_flag(
		uint8 etpuGroup,
  uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint8 fs_etpu_get_chan_dma_overflow_flag(
		uint8 etpuGroup,
  uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void fs_etpu_clear_chan_dma_overflow_flag(
		uint8 etpuGroup,
  uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
#endif /* _ETPU_UTIL_H_ */

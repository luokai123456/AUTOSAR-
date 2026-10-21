/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx eMIOS low level drivers h file
* HISTORY     : Initial version
* @file     Pwm_Emios_LLDriver.h
* @version  3.0.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/
/*PRQA S 0779 EOF*/
#ifndef EMIOS_PWM_LLD_H_
#define EMIOS_PWM_LLD_H_
#include "eMIOS_LLDriver.h"
#include "Mcal.h"

#define PWM_EMS_LLD_H_VENDOR_ID                      176
#define PWM_EMS_LLD_H_AR_REL_MAJOR_VER               4
#define PWM_EMS_LLD_H_AR_REL_MINOR_VER               4
#define PWM_EMS_LLD_H_AR_REL_REV_VER                 0
#define PWM_EMS_LLD_H_SW_MAJOR_VER                   3
#define PWM_EMS_LLD_H_SW_MINOR_VER                   0
#define PWM_EMS_LLD_H_SW_PATCH_VER                   0

#if (PWM_EMS_LLD_H_VENDOR_ID != MCAL_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_EMS_LLD_H_VENDOR_ID "
#endif
#if (PWM_EMS_LLD_H_AR_REL_MAJOR_VER != MCAL_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : PWM_EMS_LLD_H_AR_REL_MAJOR_VER "
#endif
#if (PWM_EMS_LLD_H_AR_REL_MINOR_VER != MCAL_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : PWM_EMS_LLD_H_AR_REL_MINOR_VER "
#endif
#if (PWM_EMS_LLD_H_AR_REL_REV_VER != MCAL_AR_RELEASE_REVISION_VERSION)
    #error " NON-MATCHED DATA : PWM_EMS_LLD_H_AR_REL_REV_VER "
#endif
#if (PWM_EMS_LLD_H_SW_MAJOR_VER != MCAL_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : PWM_EMS_LLD_H_SW_MAJOR_VER "
#endif
#if (PWM_EMS_LLD_H_SW_MINOR_VER != MCAL_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : PWM_EMS_LLD_H_SW_MINOR_VER "
#endif
#if (PWM_EMS_LLD_H_SW_PATCH_VER != MCAL_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : PWM_EMS_LLD_H_SW_PATCH_VER "
#endif

typedef enum
{
    EMIOS_UC_MODE_PWM_GPIO = 0x01U,

    EMIOS_UC_MODE_PWM_SAOC = 0x03U,

    EMIOS_UC_MODE_PWM_DAOC = 0x07U,
#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
    EMIOS_UC_MODE_PWM_OPWMT = 0x26U,
#endif
    EMIOS_UC_MODE_PWM_OPWFMB = 0x5AU,                  /* Output Pulse Width and Frequency Modulation Buffered, Flags are generated on both A1 & B1 matches */

    EMIOS_UC_MODE_PWM_OPWMCB_TRAIL = 0x5EU,            /* Center Aligned Output Pulse Width Modulation Buffered (with trail edge dead-time), FLAG be generated in the both edges */
    EMIOS_UC_MODE_PWM_OPWMCB_LEAD  = 0x5FU,            /* Center Aligned Output Pulse Width Modulation Buffered (with lead edge dead-time), FLAG be generated in the both edges */

    EMIOS_UC_MODE_PWM_OPWMB = 0x62U                    /* Output Pulse Width Modulation Buffered, Flags are generated on both leading and trailing matches */
} eMIOS_PWM_ModeType;

typedef struct
{
    VAR(eMIOS_PWM_ModeType, PWM_VAR)        mode;              /* Sub-mode selected */
    VAR(uint8, PWM_VAR)                     active;            /* Output active value, 0: active low, 1: active high*/
    VAR(uint8, PWM_VAR)                     divid;             /* Select the clock divider value for the internal channel prescaler in range (1-4) */
} eMIOS_GPIO_ParamType;

typedef struct
{
    VAR(eMIOS_PWM_ModeType, PWM_VAR)         mode;              /* Sub-mode selected */
    VAR(uint8, PWM_VAR)                      active;            /* Output active value, 0: active low, 1: active high*/
    VAR(uint8, PWM_VAR)                      divid;             /* Select the clock divider value for the internal channel prescaler in range (1-4) */
    VAR(uint32, PWM_VAR)                     compare;           /* Compare count */
    VAR(eMIOS_UC_CounterBusSelType, PWM_VAR) timebase;          /* Counter bus selected */
    VAR(boolean, PWM_VAR)                    eMiosDmaSwitch;
} eMIOS_SAOC_ParamType;

typedef struct
{
    VAR(eMIOS_PWM_ModeType, PWM_VAR)         mode;              /* Sub-mode selected */
    VAR(uint8, PWM_VAR)                      divid;             /* Select the clock divider value for the internal channel prescaler in range (1-4) */
    VAR(uint8, PWM_VAR)                      active;            /* Output active value, 0: active low, 1: active high*/
    VAR(eMIOS_UC_CounterBusSelType, PWM_VAR) timebase;          /* Counter bus selected */
    VAR(uint32, PWM_VAR)                     leadingEdge;       /* Leading edge placement */
    VAR(uint32, PWM_VAR)                     trailingEdge;      /* Trailing edge placement */
} eMIOS_DAOC_ParamType;

typedef struct
{
    VAR(eMIOS_PWM_ModeType, PWM_VAR)         mode;              /* Sub-mode selected */
    VAR(uint8, PWM_VAR)                      divid;             /* Select the clock divider value for the internal channel prescaler in range (1-4) */
    VAR(uint8, PWM_VAR)                      active;            /* Output active value, 0: active low, 1: active high*/
    VAR(uint32, PWM_VAR)                     period;            /* Period count */
    VAR(uint32, PWM_VAR)                     dutyCycle;         /* Duty cycle count */
    VAR(boolean, PWM_VAR)                    eMiosDmaSwitch;
} eMIOS_OPWFMB_ParamType;

typedef struct
{
    VAR(eMIOS_PWM_ModeType, PWM_VAR)         mode;              /* Sub-mode selected */
    VAR(uint8, PWM_VAR)                      divid;             /* Select the clock divider value for the internal channel prescaler in range (1-4) */
    VAR(uint8, PWM_VAR)                      active;            /* Output active value, 0: active low, 1: active high*/
    VAR(eMIOS_UC_CounterBusSelType, PWM_VAR) timebase;          /* Counter bus selected */
    VAR(uint32, PWM_VAR)                     leadingEdge;       /* Leading edge placement */
    VAR(uint32, PWM_VAR)                     trailingEdge;      /* Trailing edge placement */
    VAR(boolean, PWM_VAR)                    eMiosDmaSwitch;
} eMIOS_OPWMB_ParamType;

typedef struct
{
    VAR(eMIOS_PWM_ModeType, PWM_VAR)         mode;              /* Sub-mode selected */
    VAR(uint8, PWM_VAR)                      divid;             /* Select the clock divider value for the internal channel prescaler in range (1-4) */
    VAR(uint8, PWM_VAR)                      active;            /* Output active value, 0: active low, 1: active high*/
    VAR(eMIOS_UC_CounterBusSelType, PWM_VAR) timebase;          /* Counter bus selected */
    VAR(uint32, PWM_VAR)                     idealDutyCycle;    /* Ideal duty cycle of the PWM signal using to compare with the selected time base */
    VAR(uint32, PWM_VAR)                     deadTime;          /* The dead time value and is compared against the internal counter */
    VAR(boolean, PWM_VAR)                    eMiosDmaSwitch;
} eMIOS_OPWMCB_ParamType;

#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
typedef struct
{   VAR(eMIOS_PWM_ModeType, PWM_VAR)         mode;              /* Sub-mode selected */
    VAR(uint8, PWM_VAR)                      divid;             /* Select the clock divider value for the internal channel prescaler in range (1-4) */
    VAR(uint8, PWM_VAR)                      active;            /* Output active value, 0: active low, 1: active high*/
    VAR(eMIOS_UC_CounterBusSelType, PWM_VAR) timebase;          /* Counter bus selected */
    VAR(uint32, PWM_VAR)                     leadingEdge;       /* Leading edge placement */
    VAR(uint32, PWM_VAR)                     trailingEdge;      /* Trailing edge placement */
    VAR(uint32, PWM_VAR)                     trigTime;
} eMIOS_OPWMT_ParamType;
#endif

typedef struct
{
    VAR(eMIOS_PWM_ModeType, PWM_VAR)         mode;               /* Sub-mode selected */
    VAR(uint8, PWM_VAR)                      divid;              /* Select the clock divider value for the internal channel prescaler in range (1-4) */
    VAR(uint8, PWM_VAR)                      active;             /* Output active value, 0: active low, 1: active high*/
    VAR(eMIOS_UC_CounterBusSelType, PWM_VAR) timebase;           /* Counter bus selected, ignore with OPWFMB mode */
    VAR(uint32, PWM_VAR)                     period;             /* Period count for OPWFMB mode only */
    VAR(uint32, PWM_VAR)                     dutyCycle;          /* Duty cycle count */
    VAR(uint32, PWM_VAR)                     idealDutyCycle;     /* Ideal duty cycle of the PWM signal using to compare with the selected time base, for OPWMCB only */
    VAR(uint32, PWM_VAR)                     deadTime;           /* The dead time value and is compared against the internal counter, for OPWMCB only */
    VAR(uint32, PWM_VAR)                     offset;
#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
    VAR(uint32, PWM_VAR)                     trigTime;    
#endif
    VAR(boolean, PWM_VAR)                    eMiosDmaSwitch;
} eMIOS_PWM_ParamType;

typedef struct
{
    VAR(uint32, PWM_VAR) active:8;
    VAR(uint32, PWM_VAR) duty:24;
} eMIOS_PWM_DAOC_ISR_ParamType;

/*******************************************************************************
 * API Function declaration.
 *******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t,  PWM_CODE) eMIOS_LLD_PWM_Init \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    CONST(eMIOS_PWM_ParamType, AUTOMATIC)  *pwmParam \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t,  PWM_CODE) eMIOS_LLD_PWM_ForceEdge \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    CONST(uint8, AUTOMATIC) edge \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint32,  PWM_CODE) eMIOS_LLD_PWM_GetPeriod \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t,  PWM_CODE) eMIOS_LLD_PWM_SetPeriodAndDuty \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    CONST(uint32, AUTOMATIC) period, \
    CONST(uint32, AUTOMATIC) duty \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint32,  PWM_CODE) eMIOS_LLD_PWM_GetDutyCycle \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t,  PWM_CODE) eMIOS_LLD_PWM_SetDutyCycle \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    CONST(uint32, AUTOMATIC) newDutyCycle \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t,  PWM_CODE) eMIOS_LLD_PWM_DAOC_SetDutyCycle \
( \
    VAR(uint8, AUTOMATIC) emiosIndex, \
    VAR(uint8, AUTOMATIC) ChanNum, \
    VAR(uint32, AUTOMATIC) DutyCycle, \
    VAR(uint32, AUTOMATIC) Period \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#endif /* EMIOS_PWM_LLD_H_ */


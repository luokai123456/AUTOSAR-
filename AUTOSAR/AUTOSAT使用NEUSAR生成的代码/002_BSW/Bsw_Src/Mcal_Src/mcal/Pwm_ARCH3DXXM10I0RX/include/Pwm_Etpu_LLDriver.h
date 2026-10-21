/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx etpu low level drivers h file
* HISTORY     : Initial version
* @file     Pwm_Etpu_LLDriver.h
* @version  3.0.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/
/*PRQA S 1534 EOF*/
#ifndef ETPU_PWM_LLD_H_
#define ETPU_PWM_LLD_H_
#include "derivative.h"
#ifdef RESOURCE_SUPPORT_ETPU
#include "eTPU_LLDrivers.h"
#include "Pwm_Cfg.h"

#define PWM_ETPU_LLD_H_VENDOR_ID                      176
#define PWM_ETPU_LLD_H_AR_REL_MAJOR_VER               4
#define PWM_ETPU_LLD_H_AR_REL_MINOR_VER               4
#define PWM_ETPU_LLD_H_AR_REL_REV_VER                 0
#define PWM_ETPU_LLD_H_SW_MAJOR_VER                   3
#define PWM_ETPU_LLD_H_SW_MINOR_VER                   0
#define PWM_ETPU_LLD_H_SW_PATCH_VER                   0

#if (PWM_ETPU_LLD_H_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_ETPU_LLD_H_VENDOR_ID "
#endif
#if (PWM_ETPU_LLD_H_AR_REL_MAJOR_VER != PWM_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_ETPU_LLD_H_AR_REL_MAJOR_VER "
#endif
#if (PWM_ETPU_LLD_H_AR_REL_MINOR_VER != PWM_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_ETPU_LLD_H_AR_REL_MINOR_VER "
#endif
#if (PWM_ETPU_LLD_H_AR_REL_REV_VER != PWM_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : PWM_ETPU_LLD_H_AR_REL_REV_VER "
#endif
#if (PWM_ETPU_LLD_H_SW_MAJOR_VER != PWM_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_ETPU_LLD_H_SW_MAJOR_VER "
#endif
#if (PWM_ETPU_LLD_H_SW_MINOR_VER != PWM_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_ETPU_LLD_H_SW_MINOR_VER "
#endif
#if (PWM_ETPU_LLD_H_SW_PATCH_VER != PWM_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : PWM_ETPU_LLD_H_SW_PATCH_VER "
#endif

/**************************************************************************/
/*                       Function Prototypes                              */
/**************************************************************************/

/* Function Configuration Information */
#define ETPU_PWM_FUNCTION_NUMBER  0U
#define ETPU_PWM_TABLE_SELECT 1UL
#define ETPU_PWM_NUM_PARMS 0x0018U
/* Host Service Request Definitions */
#define ETPU_PWM_INIT 7
#define ETPU_PWM_IMM_UPDATE 3
#define ETPU_PWM_CO_UPDATE 5
/* Function Mode Bit Definitions - polarity options */
#define ETPU_PWM_ACTIVEHIGH 1
#define ETPU_PWM_ACTIVELOW 0
/* Parameter Definitions */
#define ETPU_PWM_PERIOD_OFFSET  0x0001UL
#define ETPU_PWM_ACTIVE_OFFSET  0x0005UL
#define ETPU_PWM_CO_PERIOD_OFFSET  0x0009UL
#define ETPU_PWM_CO_ACTIVE_OFFSET  0x000DUL

typedef struct      /*PRQA S 3630 */
{
    VAR(uint8, PWM_VAR)  priority;
    VAR(uint8, PWM_VAR)  polarity;
    VAR(uint32, PWM_VAR) dutyCycle;
    VAR(uint32, PWM_VAR) period;
    VAR(uint8, PWM_VAR)  timebase;
} etpu_pwm_param_t;

/******************************************************************************
FUNCTION     : ETPU_LLD_PWM_Init
PURPOSE      : To initialize an eTPU channel to generate a PWM output.
INPUTS NOTES : This function has 3 parameters:
               etpuGroup - This is the eTPU number.
               channel - This is the channel number.
                          0-31 for ETPU_A and 64-95 for ETPU_B.
               parameter - This is the channel parameter.
RETURNS NOTES: Error code if channel could not be initialized. Error code that
                 can be returned are: ETPU_ERROR_MALLOC ,
                 ETPU_ERROR_FREQ
WARNING      : *This function does not configure the pin only the eTPU. In a
                  system a pin may need to be configured to select the eTPU.
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) ETPU_LLD_PWM_Init \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    P2CONST(etpu_pwm_param_t, AUTOMATIC, PWM_APPL_CONST) parameter \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/******************************************************************************
FUNCTION     : ETPU_LLD_PWM_SetDutyCycle
PURPOSE      : To immedately update a channel dutycycle using a 16 bit integer value.
                This function will update the dutycycle during the current period
                if possible. The ineteger value is the percentage *100, so 20% would
                be 2000.
INPUTS NOTES : This function has 2 parameters:
               etpuGroup - This is the eTPU number.
               channel - This is the channel number.
                           0-31 for ETPU_A and 64-95 for ETPU_B.
               dutyCycle - This is the duty cycle of the PWM. This is a
                        uint16 with a range of 0-10000. To represent 0-100%
                        with 0.01% resolution.
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) ETPU_LLD_PWM_SetDutyCycle \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint16, AUTOMATIC) dutyCycle \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/******************************************************************************
FUNCTION     : ETPU_LLD_PWM_SetDutyCycleAndFrequency
PURPOSE      : To update a PWM output's frequency and dutycycle
INPUTS NOTES : This function has 4 parameters:
               etpuGroup - This is the eTPU number.
               channel - This is the channel number.
                           0-31 for ETPU_A and 64-95 for ETPU_B.
               frequency - This is the frequency of the PWM. This is an unint32_t
                        but the value range is only 24 bits. The range of
                        this parameter is determine by the complete system but
                        normally would be between 1Hz-100kHz.
               timebaseFrequency - This is the frequency of the selected timebase.
                 The range of this is the same as the range of the timebase
                 frequency on the device. This parameter is a uint32_t.
RETURNS NOTES: Error code if frequency is out of range: ETPU_ERROR_FREQ
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) ETPU_LLD_PWM_SetFrequency \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) frequency, \
    VAR(uint32, AUTOMATIC) timebaseFrequency \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/******************************************************************************
FUNCTION     : ETPU_LLD_PWM_GetDutyCycle
PURPOSE      : To determine the actual dutycycle by the PWM channel.
INPUTS NOTES : This function has 3 parameters:
               etpuGroup - This is the eTPU number.
               channel - This is the channel number.
                           0-31 for ETPU_A and 64-95 for ETPU_B.
               timebaseFrequency - This is the frequency of the selected timebase.
                 The range of this is the same as the range of the timebase
                 frequency on the device. This parameter is a uint32_t.
RETURNS NOTES: The actual dutycycle as an integer.
WARNING      :
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint32, PWM_CODE) ETPU_LLD_PWM_GetDutyCycle \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) timebaseFrequency \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/******************************************************************************
FUNCTION     : ETPU_LLD_PWM_GetFrequency
PURPOSE      : To determine the actual frequency by the PWM channel.
INPUTS NOTES : This function has 2 parameters:
               channel - This is the channel number.
                           0-31 for ETPU_A and 64-95 for ETPU_B.
               timebaseFrequency - This is the frequency of the selected timebase.
                 The range of this is the same as the range of the timebase
                 frequency on the device. This parameter is a uint32_t.
RETURNS NOTES: The actual frequency as an integer.
WARNING      :
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8, PWM_CODE) ETPU_LLD_PWM_GetOutputState \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) ETPU_LLD_PWM_SetPeriodAndDuty \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) period, \
    VAR(uint32, AUTOMATIC) duty \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#endif
#endif /* RESOURCE_SUPPORT_ETPU */



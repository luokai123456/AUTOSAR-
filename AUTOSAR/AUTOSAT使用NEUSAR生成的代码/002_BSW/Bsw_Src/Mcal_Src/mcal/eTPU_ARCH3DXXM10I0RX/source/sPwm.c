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
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    sPwm.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of sPwm MCAL driver.
*
*   @addtogroup sPwm
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "sPwm.h" /* PRQA S 0380 */
#if (defined(RESOURCE_SUPPORT_ETPU))
#if (SPWM_DEV_ERROR_DETECT == STD_ON)/* PRQA S 3332 */
#include "Det.h"
#endif

#define SPWM_C_VENDOR_ID_PLUGIN             176
#define SPWM_C_AR_REL_MAJOR_VER				4
#define SPWM_C_AR_REL_MINOR_VER			    4
#define SPWM_C_AR_REL_REV_VER   		    0
#define SPWM_C_SW_MAJOR_VER                 3
#define SPWM_C_SW_MINOR_VER                 0
#define SPWM_C_SW_PATCH_VER                 0

#if (ETPU_VENDOR_ID_OUTPUT != SPWM_C_VENDOR_ID_PLUGIN)
    #error " NON-MATCHED DATA : SPWM_C_VENDOR_ID_PLUGIN "
#endif
#if (ETPU_AR_REL_MAJOR_VER_OUTPUT != SPWM_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SPWM_C_AR_REL_MAJOR_VER "
#endif
#if (ETPU_AR_REL_MINOR_VER_OUTPUT != SPWM_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SPWM_C_AR_REL_MINOR_VER "
#endif
#if (ETPU_AR_REL_REVISION_VER_OUTPUT != SPWM_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SPWM_C_AR_REL_REV_VER "
#endif
#if (ETPU_SW_MAJOR_VERSION_OUTPUT != SPWM_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SPWM_C_SW_MAJOR_VER "
#endif
#if (ETPU_SW_MINOR_VERSION_OUTPUT != SPWM_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SPWM_C_SW_MINOR_VER "
#endif
#if (ETPU_SW_PATCH_VERSION_OUTPUT != SPWM_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SPWM_C_SW_PATCH_VER "
#endif
#if ((SPWM_MASTER_NUM != 0U)&&(SPWM_MODULE_ENABLE !=STD_OFF))
#define ETPU_START_SEC_VAR_INIT
#include "eTPU_MemMap.h"
P2CONST(spwm_config_t, SPWM_CONST, SPWM_APPL_CONST) sPWm_ConfigPtr[SPWM_CORE_NUM] = {NULL_PTR};
#define ETPU_STOP_SEC_VAR_INIT
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_VAR_SHARED_INIT
#include "eTPU_MemMap.h"
volatile VAR(uint8, ETPU_VAR) s_sPwm_ChannelInitState[SPWM_MASTER_NUM] = {0};
#define ETPU_STOP_SEC_VAR_SHARED_INIT
#include "eTPU_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#if SPWM_DEV_ERROR_DETECT
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
    static FUNC(void, CAN_CODE) sPwm_ReportError \
    ( \
        VAR(uint8, AUTOMATIC) u8Dspi_ApiId, \
        VAR(uint8, AUTOMATIC) u8Dspi_ErrorId \
    )
    {
#if (SPWM_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SPWM_MODULE_ID, (uint8)0U, u8Dspi_ApiId, u8Dspi_ErrorId);
#endif
    }
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
#endif

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
#if SPWM_DEV_ERROR_DETECT
static FUNC(Std_ReturnType, SPWM_CODE) spwm_run_master_Verify
(
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint8, AUTOMATIC) priority
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8RetVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32Spwm_CoreId = 0U;
    VAR(uint32, AUTOMATIC) u32Spwm_CoreIdN = 0U;

    u32Spwm_CoreIdN = Spwm_GetCoreID(); /*spwm get coreid*/
    u32Spwm_CoreId = (1U << u32Spwm_CoreIdN);

    channel --;

    if(0 != (sPWm_ConfigPtr[u32Spwm_CoreIdN]->channelcore_map[channel].sPwm_CoreId & u32Spwm_CoreId))
    {
        u8RetVal = (Std_ReturnType)E_OK;
    }else{
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }

    if(u8RetVal == (Std_ReturnType)E_NOT_OK)
    {
        sPwm_ReportError(CDD_SPWM_SID_RUN_MASTER, CDD_SPWM_E_PARAM_CHANNLE);
    }

    if(priority > 3U)
    {
        sPwm_ReportError(CDD_SPWM_SID_RUN_MASTER, CDD_SPWM_E_PARAM_PRIORITY);
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }

    return u8RetVal;
}
#endif
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
#if SPWM_DEV_ERROR_DETECT
static FUNC(Std_ReturnType, SPWM_CODE) sPwm_duty_Verify
( \
    VAR(uint8, AUTOMATIC) channel \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8RetVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32Spwm_CoreId = 0U;
    VAR(uint32, AUTOMATIC) u32Spwm_CoreIdN = 0U;

    u32Spwm_CoreIdN = Spwm_GetCoreID(); /*spwm get coreid*/
    u32Spwm_CoreId = (1U << u32Spwm_CoreIdN);

    channel --;

    if(0 != (sPWm_ConfigPtr[u32Spwm_CoreIdN]->channelcore_map[channel].sPwm_CoreId & u32Spwm_CoreId))
    {
        u8RetVal = (Std_ReturnType)E_OK;
    }else{
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }

    if(u8RetVal == (Std_ReturnType)E_NOT_OK)
    {
        sPwm_ReportError(CDD_SPWM_SID_DUTY, CDD_SPWM_E_PARAM_CHANNLE);
    }
    
    return u8RetVal;
}
#endif
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
#if SPWM_DEV_ERROR_DETECT
static FUNC(Std_ReturnType, SPWM_CODE) sPwm_update_master_Verify
(
    VAR(uint8, AUTOMATIC) channel \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8RetVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32Spwm_CoreId = 0U;
    VAR(uint32, AUTOMATIC) u32Spwm_CoreIdN = 0U;

    u32Spwm_CoreIdN = Spwm_GetCoreID(); /*spwm get coreid*/
    u32Spwm_CoreId = (1U << u32Spwm_CoreIdN);

    channel --;

    if(0 != (sPWm_ConfigPtr[u32Spwm_CoreIdN]->channelcore_map[channel].sPwm_CoreId & u32Spwm_CoreId))
    {
        u8RetVal = (Std_ReturnType)E_OK;
    }else{
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }

    if(u8RetVal == (Std_ReturnType)E_NOT_OK)
    {
        sPwm_ReportError(CDD_SPWM_SID_UPDATE_MASTER, CDD_SPWM_E_PARAM_CHANNLE);
    }

    return u8RetVal;
}
#endif
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
#if SPWM_DEV_ERROR_DETECT
static FUNC(Std_ReturnType, SPWM_CODE) sPwm_get_freq_master_Verify
(
    VAR(uint8, AUTOMATIC) channel \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8RetVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32Spwm_CoreId = 0U;
    VAR(uint32, AUTOMATIC) u32Spwm_CoreIdN = 0U;

    u32Spwm_CoreIdN = Spwm_GetCoreID(); /*spwm get coreid*/
    u32Spwm_CoreId = (1U << u32Spwm_CoreIdN);

    channel --;

    if(0 != (sPWm_ConfigPtr[u32Spwm_CoreIdN]->channelcore_map[channel].sPwm_CoreId & u32Spwm_CoreId))
    {
        u8RetVal = (Std_ReturnType)E_OK;
    }else{
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }

    if(u8RetVal == (Std_ReturnType)E_NOT_OK)
    {
        sPwm_ReportError(CDD_SPWM_SID_FREQ_MASTER, CDD_SPWM_E_PARAM_CHANNLE);
    }

    return u8RetVal;
}
#endif
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, SPWM_CODE) sPwm_run_master
( \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint8, AUTOMATIC) priority
)
{
    VAR(uint8, AUTOMATIC) etpuGroup = 0U;
    VAR(uint32, AUTOMATIC) u32sPwm_Index = 0U;
    VAR(uint8, AUTOMATIC) temp = 1U;
    VAR(uint8, AUTOMATIC) hardware_channel = 0U;    
    VAR(Std_ReturnType, AUTOMATIC) state = E_OK;
    VAR(uint32, AUTOMATIC) u32Spwm_CoreId = 0U;

    u32Spwm_CoreId = Spwm_GetCoreID(); /*spwm get coreid*/

    for(u32sPwm_Index = 0U; u32sPwm_Index < SPWM_MASTER_NUM; u32sPwm_Index++)
    {
        if(temp == channel)
        {
            etpuGroup = sPWm_ConfigPtr[u32Spwm_CoreId]->spwm_master_config[u32sPwm_Index].etpuGroup;
            hardware_channel = sPWm_ConfigPtr[u32Spwm_CoreId]->spwm_master_config[u32sPwm_Index].channel;
            break;
        }else{
            temp += sPWm_ConfigPtr[u32Spwm_CoreId]->slave_num[u32sPwm_Index];
            temp ++;
        }
    }
    
#if SPWM_DEV_ERROR_DETECT
    state = spwm_run_master_Verify(channel, priority);
#endif

    if(temp < channel)
    {
#if SPWM_DEV_ERROR_DETECT
        sPwm_ReportError(CDD_SPWM_SID_RUN_MASTER, CDD_SPWM_E_PARAM_CHANNLE);
#endif
    }
    else if ((Std_ReturnType)E_OK == state)
    {
        SchM_Enter_eTPU_EXCLUSIVE_AREA_05();
        ETPU_LLD_SPWM_Run_Master(etpuGroup, hardware_channel, priority);
        SchM_Exit_eTPU_EXCLUSIVE_AREA_05();
    }
    else{
        ;//nothing
    }

}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, SPWM_CODE) sPwm_duty
( \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint16, AUTOMATIC) duty
)
{
    VAR(uint8, AUTOMATIC) etpuGroup = 0U;
    VAR(uint32, AUTOMATIC) u32sPwm_Index = 0U;
    VAR(uint32, AUTOMATIC) u32slave_Index = 0U;
    VAR(uint8, AUTOMATIC) temp = 1U;
    VAR(uint8, AUTOMATIC) hardware_channel = 0U;   
    VAR(uint8, AUTOMATIC) exit = 1U;
    VAR(Std_ReturnType, AUTOMATIC) state = E_OK;
    VAR(uint32, AUTOMATIC) u32Spwm_CoreId = 0U;

    u32Spwm_CoreId = Spwm_GetCoreID(); /*spwm get coreid*/

    for(u32sPwm_Index = 0U; u32sPwm_Index < SPWM_MASTER_NUM; u32sPwm_Index++)
    {
        if(temp == channel)
        {
            etpuGroup = sPWm_ConfigPtr[u32Spwm_CoreId]->spwm_master_config[u32sPwm_Index].etpuGroup;
            hardware_channel = sPWm_ConfigPtr[u32Spwm_CoreId]->spwm_master_config[u32sPwm_Index].channel;
            break;
        }else{
            for(u32slave_Index = 0U;u32slave_Index < sPWm_ConfigPtr[u32Spwm_CoreId]->slave_num[u32sPwm_Index];u32slave_Index++)
            {
            	temp++;
                if(temp == channel)
                {
                    etpuGroup = sPWm_ConfigPtr[u32Spwm_CoreId]->spwm_master_config[u32sPwm_Index].etpuGroup;
                    hardware_channel = sPWm_ConfigPtr[u32Spwm_CoreId]->spwm_master_config[u32sPwm_Index].spwm_channel_config[u32slave_Index].channel;
                    exit = 0;
                    break;    
                }
            }
            if(exit == 0)
            {
            	break;
            }else{
            	;//nothing
            }
            temp ++;
        }
    }

#if SPWM_DEV_ERROR_DETECT
    state = sPwm_duty_Verify(channel);
#endif

    if(temp < channel)
    {
#if SPWM_DEV_ERROR_DETECT
        sPwm_ReportError(CDD_SPWM_SID_DUTY, CDD_SPWM_E_PARAM_CHANNLE);
#endif
    }else if ((Std_ReturnType)E_OK == state)
    {
        SchM_Enter_eTPU_EXCLUSIVE_AREA_06();
        ETPU_LLD_SPWM_Duty(etpuGroup, hardware_channel, duty);
        SchM_Exit_eTPU_EXCLUSIVE_AREA_06();
    }
}
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
)
{
    VAR(uint8, AUTOMATIC) etpuGroup = 0U;
    VAR(uint32, AUTOMATIC) u32sPwm_Index = 0U;
    VAR(uint8, AUTOMATIC) temp = 1U;
    VAR(uint8, AUTOMATIC) hardware_channel = 0U;    
    VAR(Std_ReturnType, AUTOMATIC) state = E_OK;
    VAR(uint32, AUTOMATIC) u32Spwm_CoreId = 0U;

    u32Spwm_CoreId = Spwm_GetCoreID(); /*spwm get coreid*/

    for(u32sPwm_Index = 0U; u32sPwm_Index < SPWM_MASTER_NUM; u32sPwm_Index++)
    {
        if(temp == channel)
        {
            etpuGroup = sPWm_ConfigPtr[u32Spwm_CoreId]->spwm_master_config[u32sPwm_Index].etpuGroup;
            hardware_channel = sPWm_ConfigPtr[u32Spwm_CoreId]->spwm_master_config[u32sPwm_Index].channel;
            break;
        }else{
            temp += sPWm_ConfigPtr[u32Spwm_CoreId]->slave_num[u32sPwm_Index];
            temp ++;
        }
    }

#if SPWM_DEV_ERROR_DETECT
    state = sPwm_update_master_Verify(channel);
#endif

    if(temp < channel)
    {
#if SPWM_DEV_ERROR_DETECT
        sPwm_ReportError(CDD_SPWM_SID_UPDATE_MASTER, CDD_SPWM_E_PARAM_CHANNLE);
#endif
    }else if ((Std_ReturnType)E_OK == state)
    {
        SchM_Enter_eTPU_EXCLUSIVE_AREA_07();
        (void)ETPU_LLD_SPWM_Update_Master(etpuGroup, hardware_channel, freq, duty, timebase_freq);
        SchM_Exit_eTPU_EXCLUSIVE_AREA_07();
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, SPWM_CODE) sPwm_get_freq_master
(\
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) timebase_freq
)
{
    VAR(uint32, AUTOMATIC) u8sPwm_freq = 0U;
    VAR(uint8, AUTOMATIC) etpuGroup = 0U;
    VAR(uint32, AUTOMATIC) u32sPwm_Index = 0U;
    VAR(uint8, AUTOMATIC) temp = 1U;
    VAR(uint8, AUTOMATIC) hardware_channel = 0U;    
    VAR(Std_ReturnType, AUTOMATIC) state = E_OK;
    VAR(uint32, AUTOMATIC) u32Spwm_CoreId = 0U;

    u32Spwm_CoreId = Spwm_GetCoreID(); /*spwm get coreid*/

    for(u32sPwm_Index = 0U; u32sPwm_Index < SPWM_MASTER_NUM; u32sPwm_Index++)
    {
        if(temp == channel)
        {
            etpuGroup = sPWm_ConfigPtr[u32Spwm_CoreId]->spwm_master_config[u32sPwm_Index].etpuGroup;
            hardware_channel = sPWm_ConfigPtr[u32Spwm_CoreId]->spwm_master_config[u32sPwm_Index].channel;
            break;
        }else{
            temp += sPWm_ConfigPtr[u32Spwm_CoreId]->slave_num[u32sPwm_Index];
            temp ++;
        }
    }

#if SPWM_DEV_ERROR_DETECT
    state = sPwm_get_freq_master_Verify(channel);
#endif

    if(temp < channel)
    {
#if SPWM_DEV_ERROR_DETECT
        sPwm_ReportError(CDD_SPWM_SID_FREQ_MASTER, CDD_SPWM_E_PARAM_CHANNLE);
#endif
    }else if ((Std_ReturnType)E_OK == state)
    {
        SchM_Enter_eTPU_EXCLUSIVE_AREA_08();
        u8sPwm_freq = ETPU_LLD_SPWM_Get_Freq_Master(etpuGroup, hardware_channel, timebase_freq);
        SchM_Exit_eTPU_EXCLUSIVE_AREA_08();
    }

    return u8sPwm_freq;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#ifdef __cplusplus
}
#endif
#endif
#endif

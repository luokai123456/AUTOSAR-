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
*   @file    QOM.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of QOM MCAL driver.
*
*   @addtogroup QOM
*   @{
*/

/* PRQA S 2991,2995,0491,3200,1963,1943 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "QOM.h" /* PRQA S 0380 */
#if (defined(RESOURCE_SUPPORT_ETPU))

#if (QOM_DEV_ERROR_DETECT == STD_ON)/* PRQA S 3332 */
#include "Det.h"
#endif

#define QOM_C_VENDOR_ID_PLUGIN             176
#define QOM_C_AR_REL_MAJOR_VER				4
#define QOM_C_AR_REL_MINOR_VER			    4
#define QOM_C_AR_REL_REV_VER   		        0
#define QOM_C_SW_MAJOR_VER                  3
#define QOM_C_SW_MINOR_VER                  0
#define QOM_C_SW_PATCH_VER                  0

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

#define ETPU_START_SEC_VAR_INIT
#include "eTPU_MemMap.h"
P2CONST(etpu_channel_qom_config_t, ETPU_CONST, ETPU_APPL_CONST) eTPU_QOM_ConfigPtr = NULL_PTR;
#define ETPU_STOP_SEC_VAR_INIT
#include "eTPU_MemMap.h"

#define Qom_ReportError(Qom_ApiId,Qom_ErrorId)(void)Det_ReportError \
                                                    ( \
                                                        (uint16)CDD_QOM_MODULE_ID, \
                                                        (uint8)0U, \
                                                        (uint8)(Qom_ApiId), \
                                                        (uint8)(Qom_ErrorId) \
                                                    );

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
#if (QOM_DEV_ERROR_DETECT == STD_ON)
static FUNC(Std_ReturnType, ETPU_CODE) eTPU_QOM_InitVerify
(
	P2CONST(etpu_channel_qom_config_t, ETPU_CONST, ETPU_APPL_CONST) ConfigPtr, \
	VAR(uint8, ETPU_VAR) u8Qom_ChannelIdx
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Qom_ReturnValue = (Std_ReturnType)E_OK;

    if (u8Qom_ChannelIdx >= ETPU_QOM_INSTANCE_NUM)
    {
        u8Qom_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Qom_ReportError(CDD_QOM_SID_INIT, CDD_QOM_E_PARAM_CHANNEL);
    }else if(ConfigPtr == NULL_PTR )
    {
#if (ETPU_PRECOMPILE_SUPPORT == STD_OFF)
        Qom_ReportError(CDD_QOM_SID_INIT, CDD_QOM_E_PARAM_POINTER);
        u8Qom_ReturnValue = (Std_ReturnType)E_NOT_OK;
#endif
    }else if(ConfigPtr != NULL_PTR ) /* PRQA S 2995, 2991 */
    {
#if (ETPU_PRECOMPILE_SUPPORT == STD_ON)
        Qom_ReportError(CDD_QOM_SID_INIT, CDD_QOM_E_PARAM_POINTER);
        u8Qom_ReturnValue = (Std_ReturnType)E_NOT_OK;
#endif
	}
	else{
        /* nothing */
    }

    return u8Qom_ReturnValue;
}
#endif
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) eTPU_QOM_Init
(
	P2CONST(etpu_channel_qom_config_t, ETPU_CONST, ETPU_APPL_CONST) ConfigPtr, \
	VAR(uint8, ETPU_VAR) u8Qom_ChannelIdx, \
	VAR(uint8, ETPU_VAR) u8Qom_EventIdx
)
{
	VAR(Std_ReturnType, AUTOMATIC)  u8Qom_ReturnValue = E_OK;
#if (QOM_DEV_ERROR_DETECT == STD_ON)
    u8Qom_ReturnValue = eTPU_QOM_InitVerify(ConfigPtr,u8Qom_ChannelIdx);
#endif

    if((Std_ReturnType)E_OK == u8Qom_ReturnValue)
    {
#if (ETPU_PRECOMPILE_SUPPORT == STD_ON)
        eTPU_QOM_ConfigPtr = &Etpu_Qom_Config;
#else
        eTPU_QOM_ConfigPtr = ConfigPtr;
        (void)ConfigPtr; 
#endif
		if(eTPU_QOM_ConfigPtr != NULL_PTR)
        {
            if(eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].interrupt == 1)
            {
            	ETPU_LLD_Interrupt_Disable(eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].etpuGroup,
            			eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].channel);
            }

            ETPU_LLD_QOM_INIT(eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].etpuGroup,
                            eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].channel,
                            eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].priority,
                            eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].mode,
                            eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].timebase,
                            eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].init_pin,
                            eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].first_match_mode,
                            (uint32 *)eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].ref,
                            eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].Loop,
                            eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].EventConfigPtr[u8Qom_EventIdx].event_array_size,
                            eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].EventConfigPtr[u8Qom_EventIdx].event_array);

            if(eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].interrupt == 1)
            {
            	ETPU_LLD_Interrupt_Enable(eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].etpuGroup,
            			eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].channel);
            }

        }
    }

}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
#if (QOM_DEV_ERROR_DETECT == STD_ON)
static FUNC(Std_ReturnType, ETPU_CODE) eTPU_QOM_SetCloseVerify
(
    VAR(uint8, ETPU_VAR) u8Qom_ChannelIdx
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Qom_ReturnValue = (Std_ReturnType)E_OK;

    if (u8Qom_ChannelIdx >= ETPU_QOM_INSTANCE_NUM)
    {
        u8Qom_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Qom_ReportError(CDD_QOM_SID_SOFTTRIG, CDD_QOM_E_PARAM_CHANNEL);
    }else{
        /* nothing */
    }

    return u8Qom_ReturnValue;
}
#endif
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) eTPU_QOM_SetClose
(
	VAR(uint8, ETPU_VAR) u8Qom_ChannelIdx
)
{
    VAR(uint8, ETPU_VAR) u8Qom_Channel = 0U;
    VAR(uint8, ETPU_VAR) u8Qom_Group = 0U;
    VAR(Std_ReturnType, AUTOMATIC) u8Qom_Value = E_OK;

#if (QOM_DEV_ERROR_DETECT == STD_ON)
    u8Qom_Value = eTPU_QOM_SetCloseVerify(u8Qom_ChannelIdx);
#endif
    if((Std_ReturnType)E_OK == u8Qom_Value)
    {
		u8Qom_Channel = eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].channel;
		u8Qom_Group = eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].etpuGroup;

		ETPU_LLD_QOM_SetClose(u8Qom_Group, u8Qom_Channel);
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
#if (QOM_DEV_ERROR_DETECT == STD_ON)
static FUNC(Std_ReturnType, ETPU_CODE) eTPU_QOM_GetStateVerify
(
    VAR(uint8, ETPU_VAR) u8Qom_ChannelIdx
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Qom_ReturnValue = (Std_ReturnType)E_OK;

    if (u8Qom_ChannelIdx >= ETPU_QOM_INSTANCE_NUM)
    {
        u8Qom_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Qom_ReportError(CDD_QOM_SID_SOFTTRIG, CDD_QOM_E_PARAM_CHANNEL);
    }else{
        /* nothing */
    }

    return u8Qom_ReturnValue;
}
#endif
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) eTPU_QOM_GetState(VAR(uint8, ETPU_VAR) u8Qom_ChannelIdx)
{
    VAR(uint8, ETPU_VAR) u8Qom_Channel = 0U;
    VAR(uint8, ETPU_VAR) u8Qom_Group = 0U;
    VAR(uint8, ETPU_VAR) u8Qom_State = 0U;
    VAR(uint32, ETPU_VAR) u8Qom_GetState = 0U;
    VAR(Std_ReturnType, AUTOMATIC) u8Qom_Value = E_OK;


#if (QOM_DEV_ERROR_DETECT == STD_ON)
    u8Qom_Value = eTPU_QOM_GetStateVerify(u8Qom_ChannelIdx);
#endif
    if((Std_ReturnType)E_OK == u8Qom_Value)
    {
		u8Qom_Channel = eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].channel;
		u8Qom_Group = eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_ChannelIdx].etpuGroup;
		u8Qom_GetState = ETPU_LLD_QOM_GetState(u8Qom_Group, u8Qom_Channel);
    }
    if(u8Qom_GetState == 0)
    {
        u8Qom_State = CDD_QOM_GetState_COMPLETE;
    } else {
        u8Qom_State = CDD_QOM_GetState_Sending;
    }
    return u8Qom_State;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#ifdef __cplusplus
}
#endif
#endif
#endif

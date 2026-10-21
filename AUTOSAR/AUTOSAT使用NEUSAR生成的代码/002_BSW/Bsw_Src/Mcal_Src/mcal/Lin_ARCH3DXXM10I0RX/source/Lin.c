/****************************************************************************
*

* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : LIN
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     :
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/
/**
*   @file    Lin.c
*   @implements Lin.c_Artifact
*   @version 3.0.0
*
*   @brief   AUTOSAR Lin - High level part of LIN driver.
*   @details This file contains the functions defined by AutoSAR.
*
*   @addtogroup LIN
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/* Specification of Lin Driver : [SWS_Lin_00005] */
/* Specification of Lin Driver : [SWS_Lin_00055] */

/*======================================INCLUDE FILES===============================================*/
/*PRQA S 686,1006,2842,1514,2053,2991,2995,2992,2996,2984,3408,3432,2844,0491,2982,1758,1594,1599,1756 EOF*/
#include "Lin.h" /* PRQA S 0380 */
#include "Lin_AutoSar_Wrapper.h"
#include "LinIf.h"
#include "Lin_LLDriver.h"
#if (LIN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#if(LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif

/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define LIN_C_VENDOR_ID                            LIN_VENDOR_ID_PLUGIN
#define LIN_C_AR_REL_MAJOR_VER                     LIN_AR_REL_MJR_VERSION_PLUGIN
#define LIN_C_AR_REL_MINOR_VER                     LIN_AR_REL_MNR_VERSION_PLUGIN
#define LIN_C_AR_REL_REV_VER                       LIN_AR_REL_REV_VERSION_PLUGIN
#define LIN_C_SW_MAJOR_VER                         LIN_SW_MAJOR_VERSION_PLUGIN
#define LIN_C_SW_MINOR_VER                         LIN_SW_MINOR_VERSION_PLUGIN
#define LIN_C_SW_PATCH_VER                         LIN_SW_PATCH_VERSION_PLUGIN
/* ============================================FILE VERSION CHECKS=================================== */
#if (LIN_VENDOR_ID_OUTPUT != LIN_C_VENDOR_ID)
    #error " NON-MATCHED DATA : LIN_C_VENDOR_ID "
#endif
#if (LIN_AR_REL_MJR_VERSION_PLUGIN != LIN_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_C_AR_REL_MAJOR_VER "
#endif
#if (LIN_AR_REL_MNR_VERSION_PLUGIN != LIN_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_C_AR_REL_MINOR_VER "
#endif
#if (LIN_AR_REL_REV_VERSION_OUTPUT != LIN_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : LIN_C_AR_REL_REV_VER "
#endif
#if (LIN_SW_MAJOR_VERSION_OUTPUT != LIN_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_C_SW_MAJOR_VER "
#endif
#if (LIN_SW_MINOR_VERSION_OUTPUT != LIN_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_C_SW_MINOR_VER "
#endif
#if (LIN_SW_PATCH_VERSION_OUTPUT != LIN_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : LIN_C_SW_PATCH_VER "
#endif
/*=========================LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)===============================*/

/*======================================LOCAL MACROS================================================*/
#if (LIN_DEV_ERROR_DETECT == STD_ON)
#define Lin_ReportError(Lin_ApiId,Lin_ErrorId)\
        (void)Det_ReportError((uint16)LIN_MODULE_ID, 0, (uint8)(Lin_ApiId), (uint8)(Lin_ErrorId));
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
/*======================================LOCAL CONSTANTS=============================================*/

/*======================================LOCAL VARIABLES=============================================*/

/*======================================GLOBAL CONSTANTS============================================*/

/*======================================GLOBAL VARIABLES============================================*/

/* Specification of Lin Driver : [SWS_Lin_00207] */
/* put all LIN variables into defined section */
#define LIN_START_SEC_VAR_INIT
#include "Lin_MemMap.h"
P2CONST(Lin_ConfigType,LIN_VAR,LIN_APPL_CONST) g_pLin_GenerateConfigPBPtr = NULL_PTR;
#define LIN_STOP_SEC_VAR_INIT
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_SHARED_INIT
#include "Lin_MemMap.h"
VAR(uint8, LIN_VAR) u8Lin_SduBuffAddr[LIN_HW_MAX_AVAILABLE_MODULES][LIN_MAX_DATA_LENGTH] = {{0U,0U}};/* PRQA S 0686 */
#define LIN_STOP_SEC_VAR_SHARED_INIT
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
P2CONST(Lin_ChannelConfigType,LIN_VAR,LIN_APPL_CONST) g_pLin_ChannelConfigPtr[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"

/* Specification of Lin Driver : [SWS_Lin_00145] */
#define LIN_START_SEC_VAR_INIT
#include "Lin_MemMap.h"
VAR(Lin_DriveState_Type,LIN_VAR) eLin_DrvStatus[LIN_CORE_NUM] = {LIN_UNINIT};
#define LIN_STOP_SEC_VAR_INIT
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
volatile VAR(uint8,LIN_VAR)u8Lin_ChStatus[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
volatile VAR(uint8,LIN_VAR)u8Lin_ChFrameStatus[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"

#if (LIN_MASTER_NODE_USED == STD_ON)
#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
static volatile VAR(uint8,LIN_VAR)u8Lin_ChHeaderStatus[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
#endif

#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
volatile VAR(uint8,LIN_VAR)u8Lin_ChFrameErrorStatus[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
VAR(sint8,LIN_VAR)s8Lin_ChannelHardwareMap[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
volatile VAR(uint8, LIN_VAR)u8Lin_TransmitHeaderCmd[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"

/*==================================LOCAL FUNCTION PROTOTYPES=======================================*/

#if (LIN_DEV_ERROR_DETECT == STD_ON)
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_InitVerify(P2CONST(Lin_ConfigType, AUTOMATIC, LIN_APPL_CONST) Config);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_CheckWakeupVerify(VAR(uint8, AUTOMATIC) Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#if (LIN_MASTER_NODE_USED == STD_ON)
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType,LIN_CODE) Lin_GetStatusVerify(VAR(uint8, AUTOMATIC) Channel, P2P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleepVerify(VAR(uint8, AUTOMATIC) Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleepInternalVerify(VAR(uint8, AUTOMATIC) Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#if (LIN_MASTER_NODE_USED == STD_ON)
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_SendFrameVerify(VAR(uint8, AUTOMATIC) Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) PduInfoPtr);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupVerify(VAR(uint8, AUTOMATIC) Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupInternalVerify(VAR(uint8, AUTOMATIC) Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_GetVersionInfoVerify(P2CONST(Std_VersionInfoType, AUTOMATIC,LIN_APPL_DATA) versioninfo);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
/*======================================LOCAL FUNCTIONS=============================================*/
/*****************************************************************************
**  Service Name     : Lin_InitVerify
**
**  Description      : Check the type of error reported by the Lin_Init
**
**  Parameters (in)  : Config: Pointer to driver configuration.
**
**  Parameters (out) : NONE
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#if (LIN_DEV_ERROR_DETECT == STD_ON)
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_InitVerify(P2CONST(Lin_ConfigType, AUTOMATIC, LIN_APPL_CONST) Config)
{
    VAR(Std_ReturnType,AUTOMATIC) u8Lin_ReturnValue = E_OK;
    VAR(uint32, AUTOMATIC) u32Lin_CoreId = 0U;

    u32Lin_CoreId = Lin_GetCoreID(); /*comment get core id*/
    /* Check whether the LIN driver is in LIN_UNINIT state */
    if (LIN_UNINIT != eLin_DrvStatus[u32Lin_CoreId])/* polyspace RTE:OBAI */
    {
        /* LIN driver has been already initialized */
        (void)Lin_ReportError((uint8)LIN_INIT_ID,(uint8)LIN_E_STATE_TRANSITION);
        u8Lin_ReturnValue = E_NOT_OK;
    }
#if (LIN_PRECOMPILE_SUPPORT != STD_ON)
    if( NULL_PTR == Config )
    {
        /* Invalid pointer */
        (void)Lin_ReportError((uint8)LIN_INIT_ID, (uint8)LIN_E_INVALID_POINTER);
        u8Lin_ReturnValue = E_NOT_OK;
    }
#else
    if( NULL_PTR != Config )
    {
        /* Invalid pointer */
        (void)Lin_ReportError((uint8)LIN_INIT_ID, (uint8)LIN_E_INVALID_POINTER);
        u8Lin_ReturnValue = E_NOT_OK;
    }
#endif
    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */

/*****************************************************************************
**  Service Name     : Lin_CheckWakeupVerify
**
**  Description      : Check the type of error reported by the Lin_CheckWakeup
**
**  Parameters (in)  : Channel: Lin channel.
**
**  Parameters (out) : NONE
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#if (LIN_DEV_ERROR_DETECT == STD_ON)
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_CheckWakeupVerify(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType,AUTOMATIC) u8Lin_ReturnValue = E_OK;
    VAR(uint32, AUTOMATIC) u32Lin_CoreId = 0U;
    u32Lin_CoreId = Lin_GetCoreID();/*comment get core id*/

    /* Check whether the LIN driver is in LIN_INIT state */
    if (LIN_INIT != eLin_DrvStatus[u32Lin_CoreId])/* polyspace RTE:OBAI */
    {
        /* LIN driver has not been initialized yet */
        /* Report error to development error tracer */
        (void) Lin_ReportError((uint8 )LIN_CHECKWAKEUP_ID, (uint8)LIN_E_UNINIT);
        u8Lin_ReturnValue = E_NOT_OK;
    }
    /* Check for invalid channel */
    else if (Channel >= g_pLin_GenerateConfigPBPtr->u8Lin_MaxHWChannels) /* polyspace RTE:IDP */
    {
        /* Invalid channel */
        /* Report error to development error tracer */
        (void) Lin_ReportError((uint8 )LIN_CHECKWAKEUP_ID,(uint8)LIN_E_INVALID_CHANNEL);
        u8Lin_ReturnValue = E_NOT_OK;
    }
    else if (g_pLin_ChannelConfigPtr[Channel] ==NULL)/* polyspace RTE:OBAI */
    {
        (void) Lin_ReportError((uint8 )LIN_CHECKWAKEUP_ID, (uint8)LIN_E_PARAM_POINTER);
        u8Lin_ReturnValue = E_NOT_OK;
    }
    
#if (LIN_MULTICORE_SUPPORT == STD_ON)
    else if(u32Lin_CoreId != g_pLin_GenerateConfigPBPtr->coreMap[Channel].u8CoreId)
    {
        (void) Lin_ReportError((uint8 )LIN_CHECKWAKEUP_ID, (uint8)LIN_E_PARAM_POINTER);
        u8Lin_ReturnValue = E_NOT_OK;
    }
#endif
    else
    {
        /* No action */
    }
    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
/*****************************************************************************
**  Service Name     : Lin_CheckWakeupVerify
**
**  Description      : Check the type of error reported by the Lin_CheckWakeup
**
**  Parameters (in)  : Channel: LIN channel to be checked.
**
**  Parameters (out) : Lin_SduPtr:Pointer to pointer to a shadow buffer or
**                     memory mapped LIN Hardware receive buffer where the
**                     current SDU is stored.
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#if (LIN_MASTER_NODE_USED == STD_ON)
#if (LIN_DEV_ERROR_DETECT == STD_ON)
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType,LIN_CODE) Lin_GetStatusVerify(VAR(uint8, AUTOMATIC) Channel, P2P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32Lin_CoreId = 0U;
    u32Lin_CoreId = Lin_GetCoreID();/*comment get core id*/

    /* Check whether the LIN driver is in LIN_INIT state */
    if(LIN_INIT != eLin_DrvStatus[u32Lin_CoreId])/* polyspace RTE:OBAI */
    {
        /* LIN driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_GETSTATUS_ID,(uint8)LIN_E_UNINIT);
        u8Lin_ReturnValue = E_NOT_OK;
    }

    /* Check PduInfoPtr for not being a null pointer */
    else if(NULL_PTR == Lin_SduPtr)
    {
        /* Invalid pointer */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_GETSTATUS_ID, (uint8)LIN_E_PARAM_POINTER );
        u8Lin_ReturnValue = E_NOT_OK;
    }
        /* Check for invalid channel */
    else if (Channel >= g_pLin_GenerateConfigPBPtr->u8Lin_MaxHWChannels) /* polyspace RTE:IDP */
    {
        /* Invalid channel */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_GETSTATUS_ID, (uint8)LIN_E_INVALID_CHANNEL);
        u8Lin_ReturnValue = E_NOT_OK;
    }
    else if(NULL_PTR == g_pLin_ChannelConfigPtr[Channel])/* polyspace RTE:OBAI */
    {
        /* Invalid pointer */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_GETSTATUS_ID, (uint8)LIN_E_PARAM_POINTER );
        u8Lin_ReturnValue = E_NOT_OK;
    }
#if (LIN_MULTICORE_SUPPORT == STD_ON)
    else if (u32Lin_CoreId != g_pLin_GenerateConfigPBPtr->coreMap[Channel].u8CoreId)
    {
        (void)Lin_ReportError((uint8)LIN_GETSTATUS_ID, (uint8)LIN_E_PARAM_POINTER);
        u8Lin_ReturnValue = E_NOT_OK;
    }
#endif
    else
    {
        u8Lin_ReturnValue = E_OK;
    }

    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
/*****************************************************************************
**  Service Name     : Lin_GoToSleepVerify
**
**  Description      : Check the type of error reported by the Lin_GoToSleep
**
**  Parameters (in)  : Channel: LIN channel to be checked.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#if (LIN_DEV_ERROR_DETECT == STD_ON)
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleepVerify(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32Lin_CoreId = 0U;
    u32Lin_CoreId = Lin_GetCoreID();/*comment get core id*/
    /* Check whether the LIN driver is in LIN_INIT state */
    if (LIN_INIT != eLin_DrvStatus[u32Lin_CoreId])/* polyspace RTE:OBAI */
    {
        /* LIN driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_GOTOSLEEP_ID,(uint8)LIN_E_UNINIT);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
    /* Check for invalid channel */
    else if (Channel >= g_pLin_GenerateConfigPBPtr->u8Lin_MaxHWChannels) /* polyspace RTE:IDP */
    {
        /* Invalid channel */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_GOTOSLEEP_ID, (uint8)LIN_E_INVALID_CHANNEL);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
#if (LIN_MULTICORE_SUPPORT == STD_ON)
    else if (u32Lin_CoreId != g_pLin_GenerateConfigPBPtr->coreMap[Channel].u8CoreId)
    {
        (void)Lin_ReportError((uint8)LIN_GOTOSLEEP_ID, (uint8)LIN_E_PARAM_POINTER);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
#endif
    else
    {
        u8Lin_ReturnValue = (uint8)E_OK;
    }

    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
#endif /* (LIN_MASTER_NODE_USED == STD_ON) */
/*****************************************************************************
**  Service Name     : Lin_GoToSleepInternalVerify
**
**  Description      : Check the type of error reported by the Lin_GoToSleepInternal
**
**  Parameters (in)  : Channel: LIN channel to be checked.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#if (LIN_DEV_ERROR_DETECT == STD_ON)
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleepInternalVerify(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = (uint8)E_OK;
    VAR(uint32, AUTOMATIC) u32Lin_CoreId = 0U;
    u32Lin_CoreId = Lin_GetCoreID();/*comment get core id*/
    /* Check whether the LIN driver is in LIN_INIT state */
    if (LIN_INIT != eLin_DrvStatus[u32Lin_CoreId])/* polyspace RTE:OBAI */
    {
        /* LIN driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_GOTOSLEEPINTERNAL_ID, (uint8)LIN_E_UNINIT);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
    /* Check for invalid channel */
    else if (Channel >= g_pLin_GenerateConfigPBPtr->u8Lin_MaxHWChannels) /* polyspace RTE:IDP */
    {
        /* Invalid channel */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_GOTOSLEEPINTERNAL_ID, (uint8)LIN_E_INVALID_CHANNEL);
        u8Lin_ReturnValue =  (uint8)E_NOT_OK;
    }
    
#if (LIN_MULTICORE_SUPPORT == STD_ON)
    else if (u32Lin_CoreId != g_pLin_GenerateConfigPBPtr->coreMap[Channel].u8CoreId)
    {
        (void)Lin_ReportError((uint8)LIN_GOTOSLEEPINTERNAL_ID, (uint8)LIN_E_PARAM_POINTER);
        u8Lin_ReturnValue =  (uint8)E_NOT_OK;
    }
#endif
    else
    {
        u8Lin_ReturnValue =  (uint8)E_OK;
    }

    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */

/*****************************************************************************
**  Service Name     : Lin_SendFrameVerify
**
**  Description      : Check the type of error reported by the Lin_SendFrame
**
**  Parameters (in)  : Channel   : LIN channel to be addressed.
**                     PduInfoPtr: Pointer to PDU containing the PID, checksum model,
**                                 response type, Dl and SDU data pointer.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#if (LIN_MASTER_NODE_USED == STD_ON)
#if (LIN_DEV_ERROR_DETECT == STD_ON)
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_SendFrameVerify(VAR(uint8, AUTOMATIC) Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) PduInfoPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = (uint8)E_OK;
    VAR(uint32, AUTOMATIC) u32Lin_CoreId = 0U;
    u32Lin_CoreId = Lin_GetCoreID();/*comment get core id*/

    if (LIN_INIT != eLin_DrvStatus[u32Lin_CoreId])/* polyspace RTE:OBAI */
    {
        /* LIN driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_SENDFRAME_ID, (uint8)LIN_E_UNINIT);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }

    /* Check for invalid channel */
    else if (Channel >= g_pLin_GenerateConfigPBPtr->u8Lin_MaxHWChannels) /* polyspace RTE:IDP */
    {
        /* Invalid channel */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_SENDFRAME_ID, (uint8)LIN_E_INVALID_CHANNEL);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
    else if(g_pLin_ChannelConfigPtr[Channel] ==NULL) /* polyspace RTE:OBAI */
    {
        (void)Lin_ReportError((uint8)LIN_SENDFRAME_ID,(uint8)LIN_E_PARAM_POINTER);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
    /* Check PduInfoPtr for not being a null pointer */
    else if (NULL_PTR == PduInfoPtr)
    {
        /* Invalid pointer */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_SENDFRAME_ID,(uint8)LIN_E_PARAM_POINTER);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }

    /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
    else if (LIN_CH_SLEEP_STATE == u8Lin_ChStatus[g_pLin_ChannelConfigPtr[Channel]->u8LinHwChannel])/* PRQA S 2844 */ /* polyspace RTE:OBAI */
    {
        /* LIN channel is in sleep mode */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_SENDFRAME_ID, (uint8)LIN_E_STATE_TRANSITION);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }

#if (LIN_MULTICORE_SUPPORT == STD_ON)
    else if(u32Lin_CoreId != g_pLin_GenerateConfigPBPtr->coreMap[Channel].u8CoreId)
    {
        (void)Lin_ReportError((uint8)LIN_SENDFRAME_ID, (uint8)LIN_E_PARAM_POINTER);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
#endif

    else
    {
        u8Lin_ReturnValue = (uint8)E_OK;
    }

    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
#endif /* (LIN_MASTER_NODE_USED == STD_ON) */
/*****************************************************************************
**  Service Name     : Lin_WakeupVerify
**
**  Description      : Check the type of error reported by the Lin_Wakeup
**
**  Parameters (in)  : Channel   : LIN channel to be addressed.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#if (LIN_DEV_ERROR_DETECT == STD_ON)
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupVerify(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = (uint8)E_OK;
    VAR(uint32, AUTOMATIC) u32Lin_CoreId = 0U;
    u32Lin_CoreId = Lin_GetCoreID();/*comment get core id*/

    if (LIN_INIT != eLin_DrvStatus[u32Lin_CoreId])/* polyspace RTE:OBAI */
    {
        /* LIN driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_WAKEUP_ID, (uint8)LIN_E_UNINIT);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
    /* Check for invalid channel */
    else if (Channel >= g_pLin_GenerateConfigPBPtr->u8Lin_MaxHWChannels) /* polyspace RTE:IDP */
    {
        /* Invalid channel */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_WAKEUP_ID,(uint8)LIN_E_INVALID_CHANNEL);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
    else if (g_pLin_ChannelConfigPtr[Channel] == NULL) /* polyspace RTE:OBAI */
    {
        (void)Lin_ReportError((uint8)LIN_WAKEUP_ID, (uint8)LIN_E_PARAM_POINTER);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
    /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
    else if (LIN_CH_SLEEP_STATE != u8Lin_ChStatus[g_pLin_ChannelConfigPtr[Channel]->u8LinHwChannel])/* PRQA S 2844 */ /* polyspace RTE:OBAI */
    {
        /* LIN channel is not in sleep mode */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_WAKEUP_ID, (uint8)LIN_E_STATE_TRANSITION);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
#if (LIN_MULTICORE_SUPPORT == STD_ON)
    else if (u32Lin_CoreId != g_pLin_GenerateConfigPBPtr->coreMap[Channel].u8CoreId)
    {
        (void)Lin_ReportError((uint8)LIN_WAKEUP_ID, (uint8)LIN_E_PARAM_POINTER);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
#endif
    else
    {
        u8Lin_ReturnValue = (uint8)E_OK;
    }
    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
/*****************************************************************************
**  Service Name     : Lin_WakeupInternalVerify
**
**  Description      : Check the type of error reported by the Lin_WakeupInternal
**
**  Parameters (in)  : Channel   : LIN channel to be addressed.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#if (LIN_DEV_ERROR_DETECT == STD_ON)
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupInternalVerify(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = (uint8)E_OK;
    VAR(uint32, AUTOMATIC) u32Lin_CoreId = 0U;
    u32Lin_CoreId = Lin_GetCoreID();/*comment get core id*/
    /* Check whether the LIN driver is in LIN_INIT state */

    if (LIN_INIT != eLin_DrvStatus[u32Lin_CoreId])/* polyspace RTE:OBAI */
    {
        /* LIN driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_WAKEUPINTERNAL_ID, (uint8)LIN_E_UNINIT);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
    /* Check for invalid channel */
    else if (Channel >= g_pLin_GenerateConfigPBPtr->u8Lin_MaxHWChannels) /* polyspace RTE:IDP */
    {
        /* Invalid channel */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_WAKEUPINTERNAL_ID, (uint8)LIN_E_INVALID_CHANNEL);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
    else if (g_pLin_ChannelConfigPtr[Channel] ==NULL) /* polyspace RTE:OBAI */
    {
        (void)Lin_ReportError((uint8)LIN_WAKEUPINTERNAL_ID, (uint8)LIN_E_PARAM_POINTER);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
    /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
    else if (LIN_CH_SLEEP_STATE != u8Lin_ChStatus[g_pLin_ChannelConfigPtr[Channel]->u8LinHwChannel])/* PRQA S 2844 */ /* polyspace RTE:OBAI */
    {
        /* LIN channel is not in sleep mode */
        /* Report error to development error tracer */
        (void)Lin_ReportError((uint8)LIN_WAKEUPINTERNAL_ID, (uint8)LIN_E_STATE_TRANSITION);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
#if (LIN_MULTICORE_SUPPORT == STD_ON)
    else if (u32Lin_CoreId != g_pLin_GenerateConfigPBPtr->coreMap[Channel].u8CoreId)
    {
        (void)Lin_ReportError((uint8)LIN_CHECKWAKEUP_ID, (uint8)LIN_E_PARAM_POINTER);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
#endif
    else
    {
        u8Lin_ReturnValue = (uint8)E_OK;
    }

    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
/*****************************************************************************
**  Service Name     : Lin_GetVersionInfoVerify
**
**  Description      : Check the type of error reported by the Lin_GetVersionInfo
**
**  Parameters (in)  : None
**
**  Parameters (out) : versioninfo : Pointer to where is stored the version
**                                   information of this module.
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#if (LIN_DEV_ERROR_DETECT == STD_ON)
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(Std_ReturnType, LIN_CODE) Lin_GetVersionInfoVerify(P2CONST(Std_VersionInfoType, AUTOMATIC,LIN_APPL_DATA) versioninfo)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = (uint8)E_OK;
    if (NULL_PTR == versioninfo)
    {
        (void)Lin_ReportError((uint8)LIN_GETVERSIONINFO_ID,(uint8)LIN_E_PARAM_POINTER);
        u8Lin_ReturnValue = (uint8)E_NOT_OK;
    }
    else
    {
        u8Lin_ReturnValue = (uint8)E_OK;
    }
    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
/*======================================GLOBAL FUNCTIONS============================================*/


/*****************************************************************************
**  Description      : Initializes the LIN module.
**
**  Service ID       : 0x00
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : Config: Pointer to LIN driver configuration set.
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(void, LIN_CODE) Lin_Init(P2CONST(Lin_ConfigType, AUTOMATIC, LIN_APPL_CONST) Config)
{
	VAR(uint8,AUTOMATIC) u8Lin_HwChLoop = 0U;
    VAR(uint32, AUTOMATIC) u32Lin_CoreId = 0U;
    u32Lin_CoreId = Lin_GetCoreID();/*comment get core id*/
#if (LIN_DEV_ERROR_DETECT == STD_ON)
	if((Std_ReturnType)E_NOT_OK != Lin_InitVerify(Config))
	{
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */

#if (LIN_PRECOMPILE_SUPPORT != STD_ON)
        g_pLin_GenerateConfigPBPtr = Config;
#else
        g_pLin_GenerateConfigPBPtr = &Lin_Config;
        (void)Config;/* Prevent compiler warning */
#endif
        while(u8Lin_HwChLoop < LIN_HW_MAX_AVAILABLE_MODULES)
        {
            s8Lin_ChannelHardwareMap[u8Lin_HwChLoop]= -1;
            u8Lin_HwChLoop++;
        }
        Lin_AutoSar_Wrapper_InitChannel();

        /* Specification of Lin Driver : [SWS_Lin_00146] */
        /* Update LIN driver status to LIN_INIT */
        eLin_DrvStatus[u32Lin_CoreId] = LIN_INIT;/* polyspace RTE:OBAI */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
	}
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/*****************************************************************************
**  Description      : This function checks if a wakeup has occurred on the
**                     addressed LIN channel.
**
**  Service ID       : 0x0a
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : Channel: LIN channel to be addressed.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_CheckWakeup(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = (uint8)E_NOT_OK;
    VAR(uint8,AUTOMATIC) u8LinChannelStatus;

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    if((Std_ReturnType)E_NOT_OK != Lin_CheckWakeupVerify(Channel))
    {
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        u8LinChannelStatus = u8Lin_ChStatus[g_pLin_ChannelConfigPtr[Channel]->u8LinHwChannel];/* PRQA S 2844 */ /* polyspace RTE:OBAI */
        if ((LIN_CH_SLEEP_STATE == u8LinChannelStatus) || (LIN_CH_SLEEP_PENDING == u8LinChannelStatus ))
        {
            /* Check if Lin channel has detected a wake-up */
            if ((uint8)E_TRUE == Lin_AutoSar_Wrapper_CheckWakeup(Channel))
            {
                /* Specification of Lin Driver : [SWS_Lin_00098] */
                /* Indicates a valid timer wakeup event to ECU State Manager */
                EcuM_SetWakeupEvent(g_pLin_ChannelConfigPtr[Channel]->LinChannelEcuMWakeupSource);/* PRQA S 2844 */

            /* report the wakeup source after the successful wakeup to LinInterface */
            LinIf_WakeupConfirmation(g_pLin_ChannelConfigPtr[Channel]->LinChannelEcuMWakeupSource);/* PRQA S 2844 */

                u8Lin_ReturnValue = (uint8)E_OK;
            }
        }
        else
        {
            #if (LIN_DEV_ERROR_DETECT == STD_ON)
                (void)Lin_ReportError((uint8)LIN_CHECKWAKEUP_ID, (uint8)LIN_E_STATE_TRANSITION);
            #endif
            u8Lin_ReturnValue = (uint8)E_NOT_OK;
        }
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#if (LIN_MASTER_NODE_USED == STD_ON)
/*****************************************************************************
**  Description      : Gets the status of the LIN driver.
**
**  Service ID       : 0x08
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : Channel: LIN channel to be checked.
**
**  Parameters (out) : Lin_SduPtr:Pointer to pointer to a shadow buffer or
**                     memory mapped LIN Hardware receive buffer where the
**                     current SDU is stored.
**
**  Return value     : Lin_StatusType
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Lin_StatusType, LIN_CODE) Lin_GetStatus(VAR(uint8, AUTOMATIC) Channel, P2P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr)
{
    VAR(Lin_StatusType, AUTOMATIC) eLin_ReturnValue = LIN_NOT_OK;

    VAR(uint8, LIN_VAR) u8Lin_ChannelState;


#if (LIN_DEV_ERROR_DETECT == STD_ON)
    if((Std_ReturnType)E_NOT_OK != Lin_GetStatusVerify(Channel, Lin_SduPtr))
    {
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        u8Lin_ChannelState = u8Lin_ChStatus[g_pLin_ChannelConfigPtr[Channel]->u8LinHwChannel];/* PRQA S 2844 */ /* polyspace RTE:OBAI */
        /* LIN channel state */
        switch(u8Lin_ChannelState)
        {
            case LIN_CH_SLEEP_STATE:
                eLin_ReturnValue = LIN_CH_SLEEP;
                break;
            case LIN_CH_SLEEP_PENDING:
                u8Lin_ChStatus[g_pLin_ChannelConfigPtr[Channel]->u8LinHwChannel] = LIN_CH_SLEEP_STATE;/* PRQA S 2844 */
                eLin_ReturnValue = LIN_CH_SLEEP;
                break;
            case LIN_CH_OPERATIONAL:
                /* LIN Channel frame state */
                /* Initialize the pointer to return with */
                /* the address of the data receive buffer */
                eLin_ReturnValue = Lin_AutoSar_Wrapper_HardwareGetStatus(Channel, u8Lin_SduBuffAddr[Channel]);/* PRQA S 2844 */
                *Lin_SduPtr = u8Lin_SduBuffAddr[Channel];/* PRQA S 2844 */
                break;
            default :
                eLin_ReturnValue = LIN_NOT_OK;
                break;
        }
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
    return eLin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/*****************************************************************************
**  Description      : Sends a LIN header and a LIN response, if necessary.
**                     The direction of the frame response (master response,
**                     slave response, slave-to-slave communication) is
**                     provided by the PduInfoPtr.
**
**  Service ID       : 0x04
**
**  Sync/Async       : Asynchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : Channel   : LIN channel to be addressed.
**                     PduInfoPtr: Pointer to PDU containing the PID, checksum model,
**                                 response type, Dl and SDU data pointer.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_SendFrame(VAR(uint8, AUTOMATIC) Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) PduInfoPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = (uint8)E_NOT_OK;

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    if(Lin_SendFrameVerify(Channel, PduInfoPtr) != (Std_ReturnType)E_NOT_OK)
    {
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        /* Specification of Lin Driver : [SWS_Lin_00194] */
        if(u8Lin_ChStatus[g_pLin_ChannelConfigPtr[Channel]->u8LinHwChannel] == LIN_CH_OPERATIONAL)/* PRQA S 2844 */ /* polyspace RTE:OBAI */
        {
            /* Lin Master Device will send the header first */
            if ((uint8)E_NOT_OK == Lin_AutoSar_Wrapper_SendHeader(Channel, PduInfoPtr))
            {
                /* Report Production error */
                #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                if ((uint32)STD_ON == g_pLin_GenerateConfigPBPtr->Lin_E_TimeoutCfg.state)
                {
                    Dem_SetEventStatus((Dem_EventIdType)g_pLin_GenerateConfigPBPtr->Lin_E_TimeoutCfg.id,
                                    DEM_EVENT_STATUS_FAILED);
                }
                else
                {
                    #if (LIN_DEV_ERROR_DETECT == STD_ON)
                        (void)Lin_ReportError((uint8)LIN_SENDFRAME_ID,(uint8)LIN_E_TIMEOUT);
                    #endif
                }
                #else
                    #if (LIN_DEV_ERROR_DETECT == STD_ON)
                        (void)Lin_ReportError((uint8)LIN_SENDFRAME_ID,(uint8)LIN_E_TIMEOUT);
                    #endif
                #endif
                u8Lin_ReturnValue = (uint8)E_NOT_OK;
            }
            else
            {
                /* Report Production error */
                #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    if ((uint32)STD_ON == g_pLin_GenerateConfigPBPtr->Lin_E_TimeoutCfg.state)
                    {
                        (void)Dem_SetEventStatus((Dem_EventIdType)g_pLin_GenerateConfigPBPtr->Lin_E_TimeoutCfg.id,
                                                DEM_EVENT_STATUS_PASSED);
                    }
                #endif
                u8Lin_ReturnValue = E_OK;
            }
        }
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
/*****************************************************************************
**  Description      : The service instructs the driver to transmit a
**                     go-to-sleep-command on the addressed LIN channel.
**
**  Service ID       : 0x06
**
**  Sync/Async       : Asynchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : Channel: LIN channel to be addressed.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleep(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = (uint8)E_NOT_OK;

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    if(Lin_GoToSleepVerify(Channel) != (Std_ReturnType)E_NOT_OK)
    {
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        if((uint8)E_NOT_OK == Lin_AutoSar_Wrapper_GoToSleep(Channel))
        {
            /* Report Production error */
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if ((uint32)STD_ON == g_pLin_GenerateConfigPBPtr->Lin_E_TimeoutCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)g_pLin_GenerateConfigPBPtr->Lin_E_TimeoutCfg.id, \
                                        DEM_EVENT_STATUS_FAILED \
                                        );
            }
            else
            {
                #if (LIN_DEV_ERROR_DETECT == STD_ON)
                    (void)Lin_ReportError((uint8)LIN_GOTOSLEEP_ID,(uint8)LIN_E_TIMEOUT);
                #endif
            }
#else
                #if (LIN_DEV_ERROR_DETECT == STD_ON)
                    (void)Lin_ReportError((uint8)LIN_GOTOSLEEP_ID,(uint8)LIN_E_TIMEOUT);
                #endif
#endif  /* (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
            u8Lin_ReturnValue = (uint8)E_NOT_OK;
        }
        else
        {
            /* Report Production error */
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if ((uint32)STD_ON == g_pLin_GenerateConfigPBPtr->Lin_E_TimeoutCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)g_pLin_GenerateConfigPBPtr->Lin_E_TimeoutCfg.id, \
                                        DEM_EVENT_STATUS_PASSED \
                                        );
            }
#endif
            u8Lin_ReturnValue = (uint8)E_OK;
        }
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#endif /* (LIN_MASTER_NODE_USED == STD_ON) */


/*****************************************************************************
**  Description      : Sets the channel state to LIN_CH_SLEEP, enables the
**                     wake-up detection and optionally sets the LIN hardware unit.
**
**  Service ID       : 0x09
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : Channel: LIN channel to be addressed.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleepInternal(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = (uint8)E_NOT_OK;

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    if(Lin_GoToSleepInternalVerify(Channel) != (Std_ReturnType)E_NOT_OK)
    {
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        /* Call LLD function */
        if((uint8)E_NOT_OK == Lin_AutoSar_Wrapper_GoToSleepInternal(Channel))
        {
            /* Report Production error */
            #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if ((uint32)STD_ON == g_pLin_GenerateConfigPBPtr->Lin_E_TimeoutCfg.state)
            {
                Dem_SetEventStatus((Dem_EventIdType)g_pLin_GenerateConfigPBPtr->Lin_E_TimeoutCfg.id, \
                                        DEM_EVENT_STATUS_FAILED \
                                        );
            }
            else
            {
                #if (LIN_DEV_ERROR_DETECT == STD_ON)
                    (void)Lin_ReportError((uint8)LIN_GOTOSLEEP_ID,(uint8)LIN_E_TIMEOUT);
                #endif
            }
            #else
                #if (LIN_DEV_ERROR_DETECT == STD_ON)
                    (void)Lin_ReportError((uint8)LIN_GOTOSLEEP_ID,(uint8)LIN_E_TIMEOUT);
                #endif
            #endif  /* (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

            u8Lin_ReturnValue = (uint8)E_NOT_OK;
        }
        else
        {
            /* Report Production Error */
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if ((uint32)STD_ON == g_pLin_GenerateConfigPBPtr->Lin_E_TimeoutCfg.state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)g_pLin_GenerateConfigPBPtr->Lin_E_TimeoutCfg.id, \
                                        DEM_EVENT_STATUS_PASSED \
                                        );
            }
#endif
            /* Update LIN channel status to LIN_CH_SLEEP_STATE */
            u8Lin_ReturnValue = (uint8)E_OK;
        }
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/*****************************************************************************
**  Description      : Sets the channel state to LIN_CH_OPERATIONAL without
**                     generating a wake up pulse.
**
**  Service ID       : 0x0b
**
**  Sync/Async       : Asynchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : Channel   : LIN channel to be addressed.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupInternal(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = (uint8)E_NOT_OK;

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    if(Lin_WakeupInternalVerify(Channel) != (Std_ReturnType)E_NOT_OK)
    {
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        Lin_AutoSar_Wrapper_WakeUpInternal(Channel);

        u8Lin_ReturnValue = (uint8)E_OK;
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */

    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/*****************************************************************************
**  Description      : Generates a wake up pulse.
**
**  Service ID       : 0x07
**
**  Sync/Async       : Asynchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : Channel   : LIN channel to be addressed.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_Wakeup(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = (uint8)E_NOT_OK;

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    if(Lin_WakeupVerify(Channel)  != (Std_ReturnType)E_NOT_OK)
    {
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        /* Call LLD function */
        Lin_AutoSar_Wrapper_WakeUp(Channel);

        u8Lin_ReturnValue = (uint8)E_OK;
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#if (LIN_VERSION_INFO_API == STD_ON)
/*****************************************************************************
**  Description      : Returns the version information of this module.
**
**  Service ID       : 0x01
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : None
**
**  Parameters (out) : versioninfo : Pointer to where is stored the version
**                                   information of this module.
**
**  Return value     : None
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(void, LIN_CODE) Lin_GetVersionInfo (P2VAR(Std_VersionInfoType, AUTOMATIC,LIN_APPL_DATA) versioninfo)
{
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    if(Lin_GetVersionInfoVerify(versioninfo) != (Std_ReturnType)E_NOT_OK)
    {
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
    	versioninfo->vendorID = (uint16) LIN_VENDOR_ID_PLUGIN;
		versioninfo->moduleID = (uint8) LIN_MODULE_ID;
		versioninfo->sw_major_version = (uint8) LIN_SW_MAJOR_VERSION_PLUGIN;
		versioninfo->sw_minor_version = (uint8) LIN_SW_MINOR_VERSION_PLUGIN;
		versioninfo->sw_patch_version = (uint8) LIN_SW_PATCH_VERSION_PLUGIN;
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* LIN_VERSION_INFO_API == STD_ON */

#ifdef __cplusplus
}
#endif

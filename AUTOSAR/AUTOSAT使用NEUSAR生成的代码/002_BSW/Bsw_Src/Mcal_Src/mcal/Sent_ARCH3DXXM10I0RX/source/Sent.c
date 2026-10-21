/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : SENT
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
*   @file    Sent.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Sent MCAL driver.
*
*   @addtogroup Sent
*   @{
*/
/*PRQA S 2844,1006,0380,0686,3432 EOF*/
/*PRQA S 0491,4397 EOF*/ /*QAC_CWE*/
#ifdef __cplusplus
extern "C"{
#endif

#include "Sent_Hal_Wrapper.h"
#include "Sent.h"

#if (SENT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#ifdef RESOURCE_SUPPORT_SENT

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

#define SENT_VENDOR_ID_C                 176
#define SENT_AR_MAJOR_VER_C              4
#define SENT_AR_MINOR_VER_C              4
#define SENT_AR_PATCH_VER_C              0
#define SENT_SW_MAJOR_VER_C              3
#define SENT_SW_MINOR_VER_C              0
#define SENT_SW_PATCH_VER_C              0

/*============================================FILE VERSION CHECKS===================================*/

/* Check if current file and SENT header file are of the same vendor */
#if (SENT_VENDOR_ID_C != SENT_VENDOR_ID)
#error "NON-MATCHED DATA : SENT_VENDOR_ID"
#endif

/* Check if current file and SENT header file are of the same Autosar version */
#if (SENT_AR_MAJOR_VER_C != SENT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_MAJOR_VER"
#endif
#if (SENT_AR_MINOR_VER_C != SENT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_MINOR_VER"
#endif
#if (SENT_AR_PATCH_VER_C != SENT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_PATCH_VER"
#endif

/* Check if current file and SENT header file are of the same Software version */
#if (SENT_SW_MAJOR_VER_C != SENT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_MAJOR_VER"
#endif
#if (SENT_SW_MINOR_VER_C != SENT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_MINOR_VER"
#endif
#if (SENT_SW_PATCH_VER_C != SENT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_PATCH_VER"
#endif

#define SENT_START_SEC_VAR_INIT
#include "Sent_MemMap.h"
P2CONST(Sent_ConfigType, SENT_CONST, SENT_APPL_CONST) pSent_ConfigPtr = NULL_PTR;
#define SENT_STOP_SEC_VAR_INIT
#include "Sent_MemMap.h"

#if (SENT_DEV_ERROR_DETECT == STD_ON)
#define SENT_START_SEC_VAR_INIT
#include "Sent_MemMap.h"
static VAR(Sent_StatusType, SENT_VAR) eSent_Status[SENT_MAX_PARTITION] = {SENT_UNINIT};
#define SENT_STOP_SEC_VAR_INIT
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
SENT_INLINE FUNC(void, SENT_CODE) Sent_DetReportError
(
    VAR(uint8, AUTOMATIC) ApiId,
    VAR(uint8, AUTOMATIC) ErrorId
);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif

/*===============================================LOCAL FUNCTIONS====================================*/

#if (SENT_DEV_ERROR_DETECT == STD_ON)
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
SENT_INLINE FUNC(void, SENT_CODE) Sent_DetReportError
(
    VAR(uint8, AUTOMATIC) ApiId,
    VAR(uint8, AUTOMATIC) ErrorId
)
{
    (void)Det_ReportError                         \
    (                                             \
        (uint16)SENT_MODULE_ID, SENT_INSTANCE_ID, \
        ApiId, ErrorId                            \
    );
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif

#if (SENT_DEV_ERROR_DETECT == STD_ON)
#if (SENT_ENABLE_MULTICORE == STD_ON)
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
SENT_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_CoreVerify(VAR(Sent_ChannelType, AUTOMATIC) Channel, VAR(uint8, AUTOMATIC) ApiId)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) CurrentCoreId = (uint8)Sent_GetCoreID();

    if(CurrentCoreId != pSent_ConfigPtr->pCoreMap[Channel].u8CoreId)
    {
        Sent_DetReportError(ApiId, SENT_E_CORE);
    }
    else
    {
        returnValue = (Std_ReturnType)E_OK;
    }

    return returnValue;
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif
#endif

#if (SENT_DEV_ERROR_DETECT == STD_ON)
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
SENT_INLINE FUNC(Std_ReturnType,SENT_CODE) Sent_InitVerify       \
(                                                               \
    P2CONST(Sent_ConfigType, AUTOMATIC, SENT_APPL_CONST) pConfig\
)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) ApiId = SENT_SID_INIT;

    VAR(uint8, AUTOMATIC) CurrentCoreId = (uint8)Sent_GetCoreID();

    /* If caller is the initialization function, OK */
    if (SENT_READY == eSent_Status[CurrentCoreId]) /* polyspace RTE:OBAI */
    {
        Sent_DetReportError             \
        (                               \
            ApiId,                      \
            SENT_E_ALREADY_INITIALIZED  \
        );
    }
    else
    {
#if (SENT_PRECOMPILE_SUPPORT == STD_OFF)
        /* check input paramter is valid */
        if (NULL_PTR == pConfig)
#else
        if (NULL_PTR != pConfig)
#endif
        {
            Sent_DetReportError       \
            (                         \
                ApiId,                \
                SENT_E_PARAM_POINTER  \
            );
        }
        else
        {
            returnValue = (Std_ReturnType)E_OK;
        }
    }

    return returnValue;
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif

#if (SENT_DEV_ERROR_DETECT == STD_ON)
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
SENT_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_SetChannelVerify
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId, 
    VAR(Sent_StatType, AUTOMATIC) Operation
)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) ApiId = SENT_SID_SETCHANNEL;
    VAR(uint8, AUTOMATIC) CurrentCoreId = (uint8)Sent_GetCoreID();
    if (SENT_UNINIT == eSent_Status[CurrentCoreId]) /* polyspace RTE:OBAI */
    {
        Sent_DetReportError \
        (                   \
            ApiId,          \
            SENT_E_UNINIT   \
        );
    }
    else
    {
        if(ChannelId >= pSent_ConfigPtr->u8MaxHwChannels)/* polyspace RTE:IDP */
        {
            Sent_DetReportError      \
            (                        \
                ApiId,               \
                SENT_E_PARAM_CHANNEL \
            );
        }
        else if((Operation != SENT_ENABLE) && (Operation != SENT_DISABLE))
        {
            Sent_DetReportError      \
            (                        \
                ApiId,               \
                SENT_E_PARAM_INVALID \
            );
        }
        else
        {
#if (SENT_ENABLE_MULTICORE == STD_ON)
            returnValue = Sent_CoreVerify(ChannelId, ApiId);
#else
            returnValue = (Std_ReturnType)E_OK;
#endif
        }
    }
    return returnValue;
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif

#if (SENT_DEV_ERROR_DETECT == STD_ON)
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
SENT_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_ReadDataVerify
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId
)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) ApiId = SENT_SID_READDATA;
    VAR(uint8, AUTOMATIC) CurrentCoreId = (uint8)Sent_GetCoreID();
    if (SENT_UNINIT == eSent_Status[CurrentCoreId]) /* polyspace RTE:OBAI */
    {
        Sent_DetReportError \
        (                   \
            ApiId,          \
            SENT_E_UNINIT   \
        );
    }
    else
    {
        if(ChannelId >= pSent_ConfigPtr->u8MaxHwChannels)/* polyspace RTE:IDP */
        {
            Sent_DetReportError      \
            (                        \
                ApiId,               \
                SENT_E_PARAM_CHANNEL \
            );
        }
        else
        {
#if (SENT_ENABLE_MULTICORE == STD_ON)
            returnValue = Sent_CoreVerify(ChannelId, ApiId);
#else
            returnValue = (Std_ReturnType)E_OK;
#endif
        }
    }
    return returnValue;
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif

#if (SENT_DEV_ERROR_DETECT == STD_ON)
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
SENT_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_ReadSerialDataVerify
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId,
    P2CONST(Sent_RxSerialDataType, AUTOMATIC, SENT_APPL_CONST)DataPtr
)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) ApiId = SENT_SID_READSERIALDATA;
    VAR(uint8, AUTOMATIC) CurrentCoreId = (uint8)Sent_GetCoreID();
    if (SENT_UNINIT == eSent_Status[CurrentCoreId]) /* polyspace RTE:OBAI */
    {
        Sent_DetReportError \
        (                   \
            ApiId,          \
            SENT_E_UNINIT   \
        );
    }
    else
    {
        if(ChannelId >= pSent_ConfigPtr->u8MaxHwChannels)/* polyspace RTE:IDP */
        {
            Sent_DetReportError      \
            (                        \
                ApiId,               \
                SENT_E_PARAM_CHANNEL \
            );
        }
        else if(DataPtr == NULL_PTR)
        {
            Sent_DetReportError      \
            (                        \
                ApiId,               \
                SENT_E_PARAM_INVALID \
            );
        }
        else
        {
#if (SENT_ENABLE_MULTICORE == STD_ON)
            returnValue = Sent_CoreVerify(ChannelId, ApiId);
#else
            returnValue = (Std_ReturnType)E_OK;
#endif
        }
    }
    return returnValue;
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif

#if (SENT_DEV_ERROR_DETECT == STD_ON)
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
SENT_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_ReadChannelStatusVerify
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId,
    P2CONST(Sent_ChanStatusType, AUTOMATIC, SENT_APPL_CONST)StaPtr
)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) ApiId = SENT_SID_READCHANNELSTATUS;
    VAR(uint8, AUTOMATIC) CurrentCoreId = (uint8)Sent_GetCoreID();
    if (SENT_UNINIT == eSent_Status[CurrentCoreId]) /* polyspace RTE:OBAI */
    {
        Sent_DetReportError \
        (                   \
            ApiId,          \
            SENT_E_UNINIT   \
        );
    }
    else
    {
        if(ChannelId >= pSent_ConfigPtr->u8MaxHwChannels)/* polyspace RTE:IDP */
        {
            Sent_DetReportError      \
            (                        \
                ApiId,               \
                SENT_E_PARAM_CHANNEL \
            );
        }
        else if(StaPtr == NULL_PTR)
        {
            Sent_DetReportError      \
            (                        \
                ApiId,               \
                SENT_E_PARAM_INVALID \
            );
        }
        else
        {
#if (SENT_ENABLE_MULTICORE == STD_ON)
            returnValue = Sent_CoreVerify(ChannelId, ApiId);
#else
            returnValue = (Std_ReturnType)E_OK;
#endif
        }
    }
    return returnValue;
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif

#if 0
#if (SENT_DEV_ERROR_DETECT == STD_ON)
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
SENT_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_SpcGenPulseVerify
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId,
    P2VAR(Sent_SpcType, AUTOMATIC, SENT_APPL_DATA) SpcCfgPtr
)
{

}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif

#if (SENT_DEV_ERROR_DETECT == STD_ON)
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
SENT_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_SetWdgTimerVerify
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId,
    VAR(uint16, AUTOMATIC) WdgTimerReloadVal
)
{

}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif

#if (SENT_DEV_ERROR_DETECT == STD_ON)
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
SENT_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_GetAccessEnableVerify(void)
{

}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif

#if (SENT_DEV_ERROR_DETECT == STD_ON)
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
SENT_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_SetAccessEnableVerify(VAR(uint32, AUTOMATIC) AccenRegVal)
{

}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif
#endif

#if (SENT_DEV_ERROR_DETECT == STD_ON)
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
SENT_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_DeInitVerify(void)
{

    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) ApiId = SENT_SID_DEINIT;
    VAR(uint8, AUTOMATIC) CurrentCoreId = (uint8)Sent_GetCoreID();
    if (SENT_UNINIT == eSent_Status[CurrentCoreId]) /* polyspace RTE:OBAI */
    {
        Sent_DetReportError \
        (                   \
            ApiId,          \
            SENT_E_UNINIT   \
        );
    }
    else
    {
        returnValue = (Std_ReturnType) E_OK;
    }
    return returnValue;
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_Init(P2CONST(Sent_ConfigType, AUTOMATIC, SENT_APPL_CONST) ConfigPtr)
{
#if ((SENT_DEV_ERROR_DETECT == STD_ON)||(SENT_ENABLE_MULTICORE == STD_ON))
    VAR(uint8, AUTOMATIC) CurrentCoreId = (uint8)Sent_GetCoreID();
#endif
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    if(Sent_InitVerify(ConfigPtr) == (Std_ReturnType)(E_OK))
    {
#endif
#if (SENT_PRECOMPILE_SUPPORT == STD_ON)
        pSent_ConfigPtr = &SentChannelConfigSet;
        (void)ConfigPtr;
#else
        pSent_ConfigPtr = ConfigPtr;
#endif
        for(uint8 chn = 0; chn < pSent_ConfigPtr->u8MaxHwChannels; chn++)
        {
#if (SENT_ENABLE_MULTICORE == STD_ON)
            if(pSent_ConfigPtr->pCoreMap[chn].u8CoreId == CurrentCoreId)
#endif
            {
                Sent_Hal_Wrapper_Init(chn);
            }
        }
#if (SENT_DEV_ERROR_DETECT == STD_ON)
        eSent_Status[CurrentCoreId] = SENT_READY; /* polyspace RTE:OBAI */
    }
#endif
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_DeInit(void)
{
    VAR(Sent_ChannelType, AUTOMATIC) Channel;
#if ((SENT_DEV_ERROR_DETECT == STD_ON)||(SENT_ENABLE_MULTICORE == STD_ON))
    VAR(uint8, AUTOMATIC) CurrentCoreId = (uint8)Sent_GetCoreID();
#endif
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    if(Sent_DeInitVerify() == (Std_ReturnType) E_OK)
    {
#endif
        for(Channel = 0; Channel < pSent_ConfigPtr->u8MaxHwChannels; Channel++)/* polyspace RTE:IDP */
        {
#if (SENT_ENABLE_MULTICORE == STD_ON)
            if(pSent_ConfigPtr->pCoreMap[Channel].u8CoreId == CurrentCoreId)
#endif
            {
                Sent_Hal_Wrapper_DeInit(Channel);
            }
        }
#if (SENT_DEV_ERROR_DETECT == STD_ON)
        eSent_Status[CurrentCoreId] = SENT_UNINIT; /* polyspace RTE:OBAI */
    }
#endif
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_SetChannel
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId,
    VAR(Sent_StatType, AUTOMATIC) Operation
)
{
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    if(Sent_SetChannelVerify(ChannelId, Operation) == (Std_ReturnType) E_OK)
    {
#endif
        Sent_Hal_Wrapper_SetChannel(ChannelId, Operation);
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(uint32, SENT_CODE) Sent_ReadData(VAR(Sent_ChannelType, AUTOMATIC) ChannelId)
{
    VAR(uint32, AUTOMATIC) u32Data = 0;
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    if(Sent_ReadDataVerify(ChannelId) == (Std_ReturnType) E_OK)
    {
#endif
        u32Data = Sent_Hal_Wrapper_ReadData(ChannelId);
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return u32Data;
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_ReadSerialData
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId,
    P2VAR(Sent_RxSerialDataType, AUTOMATIC, SENT_APPL_DATA)DataPtr
)
{
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    if(Sent_ReadSerialDataVerify(ChannelId, DataPtr) == (Std_ReturnType) E_OK)
    {
#endif
        Sent_Hal_Wrapper_ReadSerialData(ChannelId, DataPtr);
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_ReadChannelStatus
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId,
    P2VAR(Sent_ChanStatusType, AUTOMATIC, SENT_APPL_DATA)StatPtr
)
{
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    if(Sent_ReadChannelStatusVerify(ChannelId, StatPtr) == (Std_ReturnType) E_OK)
    {
#endif
        StatPtr->ChanStat =  Sent_Hal_Wrapper_ReadChannelStatus(ChannelId);
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, SENT_APPL_DATA) VersionInfoPtr
)
{
    if (NULL_PTR == VersionInfoPtr)
    {
#if (SENT_DEV_ERROR_DETECT == STD_ON)
        Sent_DetReportError          \
        (                            \
            SENT_SID_GETVERSIONINFO, \
            SENT_E_PARAM_INVALID     \
        );
#endif
    }
    else
    {
        VersionInfoPtr->vendorID = (uint16) SENT_VENDOR_ID;
        VersionInfoPtr->moduleID = (uint8) SENT_MODULE_ID;
        VersionInfoPtr->sw_major_version = (uint8) SENT_CFG_SW_MAJOR_VER;
        VersionInfoPtr->sw_minor_version = (uint8) SENT_CFG_SW_MINOR_VER;
        VersionInfoPtr->sw_patch_version = (uint8) SENT_CFG_SW_PATCH_VER;
    }
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_ProcessCommonIrq
(
    VAR(Sent_ChannelType, AUTOMATIC) Channel,
    VAR(srx_callback_type_t, AUTOMATIC) type
)
{
    if(pSent_ConfigPtr != NULL_PTR)
    {
        if(Channel <= pSent_ConfigPtr->u8MaxHwChannels)
        {
            if(pSent_ConfigPtr->pChanCfgPtr[Channel].pfNotification != NULL_PTR)
            {
                pSent_ConfigPtr->pChanCfgPtr[Channel].pfNotification(Channel, type);
            }
        }
    }
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(uint8, SENT_CODE)Sent_GetInstance
(
    VAR(uint8, AUTOMATIC) module,
    VAR(uint8, AUTOMATIC) Channel
)
{
    VAR(uint8, AUTOMATIC) u8Ret = 0xFFu;
    if(pSent_ConfigPtr != NULL_PTR)
    {
        for(uint8 cnt = 0; cnt < pSent_ConfigPtr->u8MaxHwChannels; cnt++)
        {
            VAR(uint8, AUTOMATIC) u8Ins = (uint8)((((uint8)module) << (uint8)5) | (((uint8)Channel) & (uint8)0x1F));
            if(pSent_ConfigPtr->pChanCfgPtr[cnt].u8ChannelId == u8Ins)
            {
                u8Ret = cnt;
                break;
            }
        }
    }
    return u8Ret;
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#if SENT_DMA_EN
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(boolean, SENT_CODE) SENT_EDmaConfig ( VAR(uint8_t, AUTOMATIC) instance, \
    CONST(boolean , AUTOMATIC) fDmaEn,CONST(boolean , AUTOMATIC) sDmaEn, \
    P2CONST(srx_driver_user_config_t, SENT_CONST,SENT_APPL_CONST) DmaconfigPtr)
{
    VAR(boolean, AUTOMATIC) ret = FALSE;
    ret = SRX_LLD_EDmaConfig(instance,fDmaEn,sDmaEn,DmaconfigPtr);
    return ret;
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif

#if 0
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_SpcGenPulse
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId,
    P2VAR(Sent_SpcType, AUTOMATIC, SENT_APPL_DATA) SpcCfgPtr
)
{

}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_SetWdgTimer
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId,
    VAR(uint16, AUTOMATIC) WdgTimerReloadVal
)
{

}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(uint32, SENT_CODE) Sent_GetAccessEnable(void)
{

}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_SetAccessEnable(VAR(uint32, AUTOMATIC) AccenRegVal)
{

}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif

#endif /* RESOURCE_SUPPORT_SENT */

#ifdef __cplusplus
}
#endif

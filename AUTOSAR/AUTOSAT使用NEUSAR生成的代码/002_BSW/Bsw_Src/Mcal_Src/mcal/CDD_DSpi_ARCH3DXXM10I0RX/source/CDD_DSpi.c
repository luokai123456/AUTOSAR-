/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : SPI
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    CDD_DSpi.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of DSPI MCAL driver.
*
*   @addtogroup DSPI
*   @{
*/
/*PRQA S 1006,0380,3432,0686,1258 EOF*/
/*PRQA S 0491,1259,2844 EOF*//*QAC_CWE*/
#ifdef __cplusplus
extern "C"{
#endif

#include "CDD_DSpi.h"
#if CDD_DSPI_DEV_ERROR_DETECT
#include "Det.h"
#endif
#include "SchM_CDD_DSpi.h"

#define CDD_DSPI_C_VENDOR_ID                     176
#define CDD_DSPI_C_AR_REL_MAJOR_VER              4
#define CDD_DSPI_C_AR_REL_MINOR_VER              4
#define CDD_DSPI_C_AR_REL_REV_VER                0
#define CDD_DSPI_C_SW_MAJOR_VER                  3
#define CDD_DSPI_C_SW_MINOR_VER                  0
#define CDD_DSPI_C_SW_PATCH_VER                  0

#if (CDD_DSPI_VENDOR_ID_OUTPUT != CDD_DSPI_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CDD_DSPI_C_VENDOR_ID "
#endif
#if (CDD_DSPI_AR_RELEASE_MAJOR_VERSION_OUTPUT != CDD_DSPI_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_C_AR_REL_MAJOR_VER "
#endif
#if (CDD_DSPI_AR_RELEASE_MINOR_VERSION_OUTPUT != CDD_DSPI_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_C_AR_REL_MINOR_VER "
#endif
#if (CDD_DSPI_AR_RELEASE_REVISION_VERSION_OUTPUT != CDD_DSPI_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_C_AR_REL_REV_VER "
#endif
#if (CDD_DSPI_SW_MAJOR_VERSION_OUTPUT != CDD_DSPI_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_C_SW_MAJOR_VER "
#endif
#if (CDD_DSPI_SW_MINOR_VERSION_OUTPUT != CDD_DSPI_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_C_SW_MINOR_VER "
#endif
#if (CDD_DSPI_SW_PATCH_VERSION_OUTPUT != CDD_DSPI_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_C_SW_PATCH_VER "
#endif

#define CDD_DSPI_START_SEC_VAR_INIT
#include "CDD_DSpi_MemMap.h"
static P2CONST(CDD_DSpi_ConfigType, DSPI_VAR, DSPI_APPL_CONST) g_pDspi_CurConfig = NULL_PTR;
#define CDD_DSPI_STOP_SEC_VAR_INIT
#include "CDD_DSpi_MemMap.h"

#define DATA_LENGTH 0U

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
DSPI_INLINE SPIDriver_t* DSpi_GetSPIDriver(VAR(spi_controller_t, AUTOMATIC) controller);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#if CDD_DSPI_DEV_ERROR_DETECT
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(void, DSPI_CODE) DSpi_ReportError \
( \
    VAR(uint8, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) u8Dspi_ApiId, \
    VAR(uint8, AUTOMATIC) u8Dspi_ErrorId \
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(void, DSPI_CODE) DSpi_ReportError \
( \
    VAR(uint8, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) u8Dspi_ApiId, \
    VAR(uint8, AUTOMATIC) u8Dspi_ErrorId \
)
{
    (void)Det_ReportError((uint16)CDD_DSPI_MODULE_ID, (uint8)instance, u8Dspi_ApiId, u8Dspi_ErrorId);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
DSPI_INLINE SPIDriver_t* DSpi_GetSPIDriver(VAR(spi_controller_t, AUTOMATIC) controller)
{
    static P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) dspidp[CDD_DSPI_CORE_NUM] = {NULL_PTR};

    VAR(uint32,AUTOMATIC)u32Dspi_CoreId = 0U;
    u32Dspi_CoreId = GetCoreID(); /*Get Core Id*/

    switch(controller)
    {
#ifdef RESOURCE_SUPPORT_DSPI_0
        case CDD_DSPI0:
            dspidp[u32Dspi_CoreId] = &SPID1;    /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_1
        case CDD_DSPI1:
            dspidp[u32Dspi_CoreId] = &SPID2;    /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_2
        case CDD_DSPI2:
            dspidp[u32Dspi_CoreId] = &SPID3;    /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_3
        case CDD_DSPI3:
            dspidp[u32Dspi_CoreId] = &SPID4;    /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_4
        case CDD_DSPI4:
            dspidp[u32Dspi_CoreId] = &SPID5;    /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_5
        case CDD_DSPI5:
            dspidp[u32Dspi_CoreId] = &SPID6;    /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_6
        case CDD_DSPI6:
            dspidp[u32Dspi_CoreId] = &SPID7;    /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_7
        case CDD_DSPI7:
            dspidp[u32Dspi_CoreId] = &SPID8;    /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_8
        case CDD_DSPI8:
            dspidp[u32Dspi_CoreId] = &SPID9;    /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_9
        case CDD_DSPI9:
            dspidp[u32Dspi_CoreId] = &SPID10;   /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_10
        case CDD_DSPI10:
            dspidp[u32Dspi_CoreId] = &SPID11;   /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_11
        case CDD_DSPI11:
            dspidp[u32Dspi_CoreId] = &SPID12;   /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_12
         case CDD_DSPI12:
            dspidp[u32Dspi_CoreId] = &SPID13;   /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_13
        case CDD_DSPI13:
            dspidp[u32Dspi_CoreId] = &SPID14;   /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_14
        case CDD_DSPI14:
            dspidp[u32Dspi_CoreId] = &SPID15;   /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_15
        case CDD_DSPI15:
            dspidp[u32Dspi_CoreId] = &SPID16;   /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_16
        case CDD_DSPI16:
            dspidp[u32Dspi_CoreId] = &SPID17;   /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_17
        case CDD_DSPI17:
            dspidp[u32Dspi_CoreId] = &SPID18;   /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_18
        case CDD_DSPI18:
            dspidp[u32Dspi_CoreId] = &SPID19;   /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_19
        case CDD_DSPI19:
            dspidp[u32Dspi_CoreId] = &SPID20;   /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_20
        case CDD_DSPI20:
            dspidp[u32Dspi_CoreId] = &SPID21;   /* polyspace RTE:OBAI */
            break;
#endif
#ifdef RESOURCE_SUPPORT_DSPI_21
        case CDD_DSPI21:
            dspidp[u32Dspi_CoreId] = &SPID22;   /* polyspace RTE:OBAI */
            break;
#endif
        default:
            dspidp[u32Dspi_CoreId] = NULL_PTR;  /* polyspace RTE:OBAI */
            break;
    }
    return dspidp[u32Dspi_CoreId];
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#if CDD_DSPI_DEV_ERROR_DETECT
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
DSPI_INLINE FUNC(Std_ReturnType, DSPI_CODE) CDD_DSpi_DSI_SendVerify \
( \
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint32, AUTOMATIC) n, \
    P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) txbuf, \
    P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) rxbuf
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Dspi_ret = E_NOT_OK;
    VAR(uint32,AUTOMATIC)u32Dspi_CoreId = 0U;
    u32Dspi_CoreId = GetCoreID(); /*Get Core Id*/

    if (CDD_DSPI_CONTROLLER_COUNT <= instance)
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_SEND, CDD_DSPI_E_PARAM_CONTROLLER);
    }
    else if (u32Dspi_CoreId !=g_pDspi_CurConfig->coreMap[instance].Dspi_CoreId)/* polyspace RTE:IDP */
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_SEND, CDD_DSPI_E_PARAM_CONFIG);
    }
    else if ((NULL_PTR == txbuf) || (NULL_PTR == rxbuf))
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_SEND, CDD_DSPI_E_PARAM_POINTER);
    }
    else if(n == (uint32)DATA_LENGTH)
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_SEND, CDD_DSPI_E_PARAM_DATA_LENGTH);
    }
    else
    {
        u8Dspi_ret = E_OK;
    }
    return u8Dspi_ret;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif

#if CDD_DSPI_DEV_ERROR_DETECT
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
DSPI_INLINE FUNC(Std_ReturnType, DSPI_CODE) CDD_DSpi_DSI_ReceiveVerify \
( \
    VAR(uint8, AUTOMATIC) instance,
    P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) rxbuf
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Dspi_ret = E_NOT_OK;
    VAR(uint32,AUTOMATIC)u32Dspi_CoreId = 0U;
    u32Dspi_CoreId = GetCoreID(); /*Get Core Id*/

    if (CDD_DSPI_CONTROLLER_COUNT <= instance)
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_RECEIVE, CDD_DSPI_E_PARAM_CONTROLLER);
    }
    else if (u32Dspi_CoreId !=g_pDspi_CurConfig->coreMap[instance].Dspi_CoreId)/* polyspace RTE:IDP */
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_RECEIVE, CDD_DSPI_E_PARAM_CONFIG);
    }
    else if (NULL_PTR == rxbuf)
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_RECEIVE, CDD_DSPI_E_PARAM_POINTER);
    }
    else
    {
        u8Dspi_ret = E_OK;
    }
    return u8Dspi_ret;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif

#if CDD_DSPI_DEV_ERROR_DETECT
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
DSPI_INLINE FUNC(Std_ReturnType, DSPI_CODE) CDD_DSpi_DSI_TSB_SendVerify \
( \
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint32, AUTOMATIC) n, \
    P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) txbuf, \
    P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) rxbuf
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Dspi_ret = E_NOT_OK;
    VAR(uint32,AUTOMATIC)u32Dspi_CoreId = 0U;
    u32Dspi_CoreId = GetCoreID(); /*Get Core Id*/

    if (CDD_DSPI_CONTROLLER_COUNT <= instance)
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_TSB_SEND, CDD_DSPI_E_PARAM_CONTROLLER);
    }
    else if (u32Dspi_CoreId !=g_pDspi_CurConfig->coreMap[instance].Dspi_CoreId)/* polyspace RTE:IDP */
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_RECEIVE, CDD_DSPI_E_PARAM_CONFIG);
    }
    else if ((NULL_PTR == txbuf) || (NULL_PTR == rxbuf))
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_TSB_SEND, CDD_DSPI_E_PARAM_POINTER);
    }
    else if(n == (uint32)DATA_LENGTH)
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_TSB_SEND, CDD_DSPI_E_PARAM_DATA_LENGTH);
    }
    else
    {
        u8Dspi_ret = E_OK;
    }
    return u8Dspi_ret;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif

#if CDD_DSPI_DEV_ERROR_DETECT
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
DSPI_INLINE FUNC(Std_ReturnType, DSPI_CODE) CDD_DSpi_SetDsiTRGPRDVerify \
( \
    VAR(uint8, AUTOMATIC) instance
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Dspi_ret = E_NOT_OK;
    VAR(uint32,AUTOMATIC)u32Dspi_CoreId = 0U;
    u32Dspi_CoreId = GetCoreID(); /*Get Core Id*/

    if (CDD_DSPI_CONTROLLER_COUNT <= instance)
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_SET_TRGPRD, CDD_DSPI_E_PARAM_CONTROLLER);
    }
    else if (u32Dspi_CoreId !=g_pDspi_CurConfig->coreMap[instance].Dspi_CoreId)/* polyspace RTE:IDP */
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_RECEIVE, CDD_DSPI_E_PARAM_CONFIG);
    }
    else
    {
        u8Dspi_ret = E_OK;
    }
    return u8Dspi_ret;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif

#if CDD_DSPI_DEV_ERROR_DETECT
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
DSPI_INLINE FUNC(Std_ReturnType, DSPI_CODE) CDD_DSpi_CSI_SendVerify \
( \
    VAR(uint8, AUTOMATIC) instance,
    P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) txbuf,
    P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) txbuf1,
    P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) rxbuf,
    P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) rxbuf1,
    VAR(uint32, AUTOMATIC) spi_n,
    VAR(uint32, AUTOMATIC) dsi_n
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Dspi_ret = E_NOT_OK;
    VAR(uint32,AUTOMATIC)u32Dspi_CoreId = 0U;
    u32Dspi_CoreId = GetCoreID(); /*Get Core Id*/

    if (CDD_DSPI_CONTROLLER_COUNT <= instance)
    {
        DSpi_ReportError(instance, CDD_DSPI_CSI_SEND, CDD_DSPI_E_PARAM_CONTROLLER);
    }
    else if (u32Dspi_CoreId !=g_pDspi_CurConfig->coreMap[instance].Dspi_CoreId)/* polyspace RTE:IDP */
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_RECEIVE, CDD_DSPI_E_PARAM_CONFIG);
    }
    else if ((NULL_PTR == txbuf) || (NULL_PTR == rxbuf) || (NULL_PTR == txbuf1) || (NULL_PTR == rxbuf1))
    {
        DSpi_ReportError(instance, CDD_DSPI_CSI_SEND, CDD_DSPI_E_PARAM_POINTER);
    }
    else if((spi_n == (uint32)DATA_LENGTH) || (dsi_n == (uint32)DATA_LENGTH))
    {
        DSpi_ReportError(instance, CDD_DSPI_CSI_SEND, CDD_DSPI_E_PARAM_DATA_LENGTH);
    }
    else
    {
        u8Dspi_ret = E_OK;
    }
    return u8Dspi_ret;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif

#if CDD_DSPI_DEV_ERROR_DETECT
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
DSPI_INLINE FUNC(Std_ReturnType, DSPI_CODE) CDD_DSpi_Cdsi_Prefill_ITBC_TxVerify \
( \
    VAR(uint8, AUTOMATIC) instance,
    P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) txbuf,
    P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) txbuf1,
    P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) rxbuf,
    P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) rxbuf1,
    VAR(uint32, AUTOMATIC) spi_n,
    VAR(uint32, AUTOMATIC) dsi_n
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Dspi_ret = E_NOT_OK;
    VAR(uint32,AUTOMATIC)u32Dspi_CoreId = 0U;
    u32Dspi_CoreId = GetCoreID(); /*Get Core Id*/

    if (CDD_DSPI_CONTROLLER_COUNT <= instance)
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_PREFILL_ITBC_TX, CDD_DSPI_E_PARAM_CONTROLLER);
    }
    else if (u32Dspi_CoreId !=g_pDspi_CurConfig->coreMap[instance].Dspi_CoreId)/* polyspace RTE:IDP */
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_RECEIVE, CDD_DSPI_E_PARAM_CONFIG);
    }
    else if ((NULL_PTR == txbuf) || (NULL_PTR == rxbuf) || (NULL_PTR == txbuf1) || (NULL_PTR == rxbuf1))
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_PREFILL_ITBC_TX, CDD_DSPI_E_PARAM_POINTER);
    }
    else if((spi_n == (uint32)DATA_LENGTH) || (dsi_n == (uint32)DATA_LENGTH))
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_PREFILL_ITBC_TX, CDD_DSPI_E_PARAM_DATA_LENGTH);
    }
    else
    {
        u8Dspi_ret = E_OK;
    }
    return u8Dspi_ret;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif

#if CDD_DSPI_DEV_ERROR_DETECT
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
DSPI_INLINE FUNC(Std_ReturnType, DSPI_CODE) DSPI_LLD_CSI_TSB_TxVerify \
( \
    VAR(uint8, AUTOMATIC) instance,
    P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) tsbcmd,
    P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) tsbdata,
    VAR(uint32, AUTOMATIC) tsbcmd_n,
    VAR(uint32, AUTOMATIC) tsbdata_n
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Dspi_ret = E_NOT_OK;
    VAR(uint32,AUTOMATIC)u32Dspi_CoreId = 0U;
    u32Dspi_CoreId = GetCoreID(); /*Get Core Id*/

    if (CDD_DSPI_CONTROLLER_COUNT <= instance)
    {
        DSpi_ReportError(instance, CDD_DSPI_CSI_TSB_TX, CDD_DSPI_E_PARAM_CONTROLLER);
    }
    else if (u32Dspi_CoreId !=g_pDspi_CurConfig->coreMap[instance].Dspi_CoreId)/* polyspace RTE:IDP */
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_RECEIVE, CDD_DSPI_E_PARAM_CONFIG);
    }
    else if ((NULL_PTR == tsbcmd) || (NULL_PTR == tsbdata))
    {
        DSpi_ReportError(instance, CDD_DSPI_CSI_TSB_TX, CDD_DSPI_E_PARAM_POINTER);
    }
    else if((tsbcmd_n == (uint32)DATA_LENGTH) || (tsbdata_n == (uint32)DATA_LENGTH))
    {
        DSpi_ReportError(instance, CDD_DSPI_DSI_RECEIVE, CDD_DSPI_E_PARAM_DATA_LENGTH);
    }
    else
    {
        u8Dspi_ret = E_OK;
    }
    return u8Dspi_ret;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_Init(P2CONST(CDD_DSpi_ConfigType, AUTOMATIC, DSPI_APPL_CONST) Config)
{
    VAR(uint8, AUTOMATIC) u8Dspi_tempIdx = 0U;
#ifdef RESOURCE_SUPPORT_GTM_TO_MSC
#if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
    VAR(uint8, AUTOMATIC) u8Dspi_Msc_tempIdx = 0U;
#endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
#endif
    VAR(status_t, AUTOMATIC) ret = STATUS_SUCCESS;
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) dspidp_t = NULL_PTR;

    VAR(uint32,AUTOMATIC)u32Dspi_CoreId = 0U;
    u32Dspi_CoreId = GetCoreID(); /*Get Core Id*/

#if (CDD_DSPI_PRECOMPILE_SUPPORT == STD_OFF)
    if (NULL_PTR == Config)
#else
    if (NULL_PTR != Config)
#endif
    {
#if CDD_DSPI_DEV_ERROR_DETECT
        DSpi_ReportError(u8Dspi_tempIdx, CDD_DSPI_SID_INIT, CDD_DSPI_E_PARAM_POINTER);
#endif
    }
    else
    {
#if (CDD_DSPI_PRECOMPILE_SUPPORT == STD_OFF)
        g_pDspi_CurConfig = Config;
#else
        g_pDspi_CurConfig = &CDD_DSpi_Config;
        (void)Config;
#endif
        SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_00();
        for (; u8Dspi_tempIdx < CDD_DSPI_CONTROLLER_COUNT; u8Dspi_tempIdx++)
        {
            if(g_pDspi_CurConfig->coreMap[u8Dspi_tempIdx].Dspi_CoreId == u32Dspi_CoreId)
            {
                dspidp_t = DSpi_GetSPIDriver(g_pDspi_CurConfig->dspiConfig[u8Dspi_tempIdx].WhichSpiController);
                ret = SPI_LLD_Init(dspidp_t, &(CDD_DSpi_Config.dspiConfig[u8Dspi_tempIdx]),CDD_DSpi_Config.dspiConfig[u8Dspi_tempIdx].spi_mode);/* polyspace RTE:IDP */
                if (STATUS_SUCCESS != ret)
                {
#if CDD_DSPI_DEV_ERROR_DETECT
                    DSpi_ReportError(u8Dspi_tempIdx, CDD_DSPI_SID_INIT, CDD_DSPI_E_INIT_FAILED);
#endif
                }
            }
        }
        SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_00();
#ifdef RESOURCE_SUPPORT_GTM_TO_MSC
#if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_09();
        for (u8Dspi_Msc_tempIdx = 0U; u8Dspi_Msc_tempIdx < CDD_DSPI_GTM_MSC_SET_COUNT; u8Dspi_Msc_tempIdx++)
        {
            MSC_SETi_SEL_Set(g_pDspi_CurConfig->gtmMSCSetConfig[u8Dspi_Msc_tempIdx].setIndex, g_pDspi_CurConfig->gtmMSCSetConfig[u8Dspi_Msc_tempIdx].selValue);
        }
        SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_09();
#endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
#endif
    }
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#ifdef RESOURCE_SUPPORT_GTM_TO_MSC
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_Start(VAR(uint8, AUTOMATIC) instance)
{
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) dspidp_t = NULL_PTR;
    dspidp_t = DSpi_GetSPIDriver(g_pDspi_CurConfig->dspiConfig[instance].WhichSpiController); /* polyspace RTE:IDP */   
    Spi_Dspi_Start(dspidp_t);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_DSI_Send
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint32, AUTOMATIC) n,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) txbuf,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf
)
{
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) dspidp_t = NULL_PTR;

#if CDD_DSPI_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == CDD_DSpi_DSI_SendVerify(instance, n, txbuf, rxbuf))
    {
#endif
        dspidp_t = DSpi_GetSPIDriver(g_pDspi_CurConfig->dspiConfig[instance].WhichSpiController);
        DSPI_LLD_DSI_Send(dspidp_t, n, txbuf, rxbuf);
#if CDD_DSPI_DEV_ERROR_DETECT
    }
#endif
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_DSI_Receive
(
    VAR(uint8, AUTOMATIC) instance, 
    VAR(uint32, AUTOMATIC) n, 
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf
)
{
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) dspidp_t = NULL_PTR;
#if CDD_DSPI_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == CDD_DSpi_DSI_ReceiveVerify(instance, rxbuf))
    {
#endif
        dspidp_t = DSpi_GetSPIDriver(g_pDspi_CurConfig->dspiConfig[instance].WhichSpiController);
        DSPI_LLD_DSI_Receive(dspidp_t, n, rxbuf);
#if CDD_DSPI_DEV_ERROR_DETECT
    }
#endif
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_DSI_TSB_Send
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint32, AUTOMATIC) n,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) txbuf,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf
)
{
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) dspidp_t = NULL_PTR;

#if CDD_DSPI_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == CDD_DSpi_DSI_TSB_SendVerify(instance, n, txbuf, rxbuf))
    {
#endif
        dspidp_t = DSpi_GetSPIDriver(g_pDspi_CurConfig->dspiConfig[instance].WhichSpiController);
        DSPI_LLD_DSI_TSB_Send(dspidp_t, n, txbuf, rxbuf);
#if CDD_DSPI_DEV_ERROR_DETECT
    }
#endif
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_CSI_Send
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint32, AUTOMATIC) spi_n,
    VAR(uint32, AUTOMATIC) dsi_n,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) txbuf,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) txbuf1,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf1
)
{
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) dspidp_t = NULL_PTR;

#if CDD_DSPI_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == CDD_DSpi_CSI_SendVerify(instance, txbuf, txbuf1, rxbuf, rxbuf1, spi_n, dsi_n))
    {
#endif
        dspidp_t = DSpi_GetSPIDriver(g_pDspi_CurConfig->dspiConfig[instance].WhichSpiController);
        DSPI_LLD_CSI_Send(dspidp_t, spi_n, dsi_n, txbuf, txbuf1, rxbuf, rxbuf1);
#if CDD_DSPI_DEV_ERROR_DETECT
    }
#endif
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_SetDsiTRGPRD
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint32, AUTOMATIC) trig_period
)
{
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) dspidp_t = NULL_PTR;
#if CDD_DSPI_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == CDD_DSpi_SetDsiTRGPRDVerify(instance))
    {
#endif
        dspidp_t = DSpi_GetSPIDriver(g_pDspi_CurConfig->dspiConfig[instance].WhichSpiController);
        SPI_LLD_SetDsiTRGPRD(dspidp_t, trig_period);
#if CDD_DSPI_DEV_ERROR_DETECT
    }
#endif
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_Cdsi_Prefill_ITBC_Tx
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint32, AUTOMATIC) spi_n,
    VAR(uint32, AUTOMATIC) dsi_n,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) txbuf,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) txbuf1,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf1
)
{
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) dspidp_t = NULL_PTR;

#if CDD_DSPI_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == CDD_DSpi_Cdsi_Prefill_ITBC_TxVerify(instance, txbuf, txbuf1, rxbuf, rxbuf1, spi_n, dsi_n))
    {
#endif
        dspidp_t = DSpi_GetSPIDriver(g_pDspi_CurConfig->dspiConfig[instance].WhichSpiController);
        Cdsi_Prefill_ITBC_Tx(dspidp_t, spi_n, dsi_n, txbuf, txbuf1, rxbuf, rxbuf1);
#if CDD_DSPI_DEV_ERROR_DETECT
    }
#endif
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) CDD_DSpi_LLD_CSI_TSB_Tx
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint32, AUTOMATIC) tsbcmd_n,
    VAR(uint32, AUTOMATIC) tsbdata_n,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) tsbcmd,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) tsbdata
)
{
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) dspidp_t = NULL_PTR;

#if CDD_DSPI_DEV_ERROR_DETECT
    if ((Std_ReturnType)E_OK == DSPI_LLD_CSI_TSB_TxVerify(instance, tsbcmd, tsbdata, tsbcmd_n, tsbdata_n))
    {
#endif
        dspidp_t = DSpi_GetSPIDriver(g_pDspi_CurConfig->dspiConfig[instance].WhichSpiController);
        DSPI_LLD_CSI_TSB_Tx(dspidp_t, tsbcmd_n, tsbdata_n, tsbcmd, tsbdata);
#if CDD_DSPI_DEV_ERROR_DETECT
    }
#endif
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#ifdef __cplusplus
}
#endif

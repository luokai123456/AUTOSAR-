/* PRQA S 0380, 0795, 1006, 3432 EOF */
/* PRQA S 0491, 2844 EOF */   /* CWE */
/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : CAN
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
*   @file    Can_176_CanFD.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CanFD MCAL driver.
*
*   @addtogroup CanFD
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Can_176_CanFD.h"
#include "Can_176_CanFD_LLDriver.h"
#include "Can_176_CanFD_AutoSar_Wrapper.h"

#ifdef RESOURCE_SUPPORT_CANFD_IP
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#define CAN_176_CANFD_C_VENDOR_ID                     176
#define CAN_176_CANFD_C_AR_REL_MAJOR_VER              4
#define CAN_176_CANFD_C_AR_REL_MINOR_VER              4
#define CAN_176_CANFD_C_AR_REL_REV_VER                0
#define CAN_176_CANFD_C_SW_MAJOR_VER                  3
#define CAN_176_CANFD_C_SW_MINOR_VER                  0
#define CAN_176_CANFD_C_SW_PATCH_VER                  0

#if (CAN_176_CANFD_CFG_H_VENDOR_ID != CAN_176_CANFD_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_176_CANFD_C_VENDOR_ID "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MAJOR_VER != CAN_176_CANFD_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_C_AR_REL_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MINOR_VER != CAN_176_CANFD_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_C_AR_REL_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_REV_VER != CAN_176_CANFD_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_C_AR_REL_REV_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MAJOR_VER != CAN_176_CANFD_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_C_SW_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MINOR_VER != CAN_176_CANFD_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_C_SW_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_PATCH_VER != CAN_176_CANFD_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_C_SW_PATCH_VER "
#endif

#define CAN_176_CANFD_START_SEC_VAR_INIT
#include "Can_176_CanFD_MemMap.h"
P2CONST(Can_176_CanFD_ConfigType, CAN_VAR, CAN_APPL_CONST) g_pCanFd_CurConfig = NULL_PTR;
#define CAN_176_CANFD_STOP_SEC_VAR_INIT
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_VAR_INIT
#include "Can_176_CanFD_MemMap.h"
volatile VAR(Can_ControllerStateType, CAN_VAR) g_eCanFd_ControllerState[CAN_176_CANFD_CONTROLLER_COUNT] = {CAN_CS_UNINIT}; /*PRQA S 0686*/ 
#define CAN_176_CANFD_STOP_SEC_VAR_INIT
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_VAR_INIT
#include "Can_176_CanFD_MemMap.h"
VAR(uint16, CAN_VAR) g_u16CanFd_CurBaudRateId[CAN_176_CANFD_CONTROLLER_COUNT];
VAR(uint16, CAN_VAR) g_u16CanFd_CurBaudRateId[CAN_176_CANFD_CONTROLLER_COUNT] = {0U};
#define CAN_176_CANFD_STOP_SEC_VAR_INIT
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_VAR_INIT
#include "Can_176_CanFD_MemMap.h"
VAR(Can_176_CANFD_DriverStateType, CAN_VAR) g_eCanFd_DriverState[CAN_176_CANFD_CORE_NUM];
VAR(Can_176_CANFD_DriverStateType, CAN_VAR) g_eCanFd_DriverState[CAN_176_CANFD_CORE_NUM] = {CAN_176_CANFD_UNINIT}; /*PRQA S 0686*/ 
#define CAN_176_CANFD_STOP_SEC_VAR_INIT
#include "Can_176_CanFD_MemMap.h"

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Can_176_CanFD_ReportError \
( \
    VAR(uint8, AUTOMATIC) u8CanFd_ApiId, \
    VAR(uint8, AUTOMATIC) u8CanFd_ErrorId \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Can_176_CanFD_ReportError \
( \
    VAR(uint8, AUTOMATIC) u8CanFd_ApiId, \
    VAR(uint8, AUTOMATIC) u8CanFd_ErrorId \
)
{
    (void)Det_ReportError((uint16)CAN_176_CANFD_MODULE_ID, \
        (uint8)CAN_176_CANFD_INSTANCE, u8CanFd_ApiId, u8CanFd_ErrorId);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_InitVerify \
( \
    P2CONST(Can_176_CanFD_ConfigType, AUTOMATIC, CAN_APPL_CONST) pCanFd_Config,\
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = E_NOT_OK;
    /*
        [SWS_Can_00174] If development error detection for the Can module is enabled: 
        The function Can_Init shall raise the error CAN_E_TRANSITION if the driver is not in 
        state CAN_UNINIT.
    */
    if (CAN_176_CANFD_READY == g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_INIT, CAN_176_CANFD_E_TRANSITION);
    }
    else
    {
#if (CAN_176_CANFD_PRECOMPILE_SUPPORT == STD_OFF)
        if (NULL_PTR == pCanFd_Config)
#else
        if (NULL_PTR != pCanFd_Config)
#endif
        {
            Can_176_CanFD_ReportError(CAN_176_CANFD_SID_INIT, CAN_176_CANFD_E_PARAM_POINTER);
        }
        else
        {
            u8CanFd_ret = E_OK;
        }
    }
    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_DeInitVerify(VAR(uint32, AUTOMATIC) u32CanFd_CoreId)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = E_NOT_OK;
    VAR(uint8, AUTOMATIC) u8CanFd_tempIdx = 0U;
    /*
        [SWS_Can_91011] If development error detection for the Can module is enabled: 
        The function Can_DeInit shall raise the error CAN_E_TRANSITION if the driver is not 
        in state CAN_READY.
    */
    if (CAN_176_CANFD_READY != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_DEINIT, CAN_176_CANFD_E_TRANSITION);
    }
    else
    {
        for (; u8CanFd_tempIdx < CAN_176_CANFD_CONTROLLER_COUNT; u8CanFd_tempIdx++)
        {
            /*
                [SWS_Can_91012] If development error detection for the Can module is enabled: 
                The function Can_DeInit shall raise the error CAN_E_TRANSITION if any of the CAN 
                controllers is in state STARTED.
            */
            if (CAN_CS_STARTED == g_eCanFd_ControllerState[u8CanFd_tempIdx])
            {
                u8CanFd_ret = E_NOT_OK;
                Can_176_CanFD_ReportError(CAN_176_CANFD_SID_DEINIT, CAN_176_CANFD_E_TRANSITION);
                break;
            }
            else
            {
                u8CanFd_ret = E_OK;
            }
        }
    }
    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
#if (CAN_176_CANFD_SET_BAUDRATE_API == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_SetBaudrateVerify \
( \
    VAR(uint8, AUTOMATIC) u8CanFd_Controller \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = E_NOT_OK;
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
#endif
    /*
        [SWS_Can_00494]  If development error detection for the Can module is enabled
        the function Can_SetBaudrate shall raise the error CAN_E_PARAM_CONTROLLER 
        and return E_NOT_OK if the parameter Controller is out of range.
    */
    if (u8CanFd_Controller >= CAN_176_CANFD_CONTROLLER_COUNT)
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_SET_BAUDRATE, CAN_176_CANFD_E_PARAM_CONTROLLER);
    }
    /*
        [SWS_Can_00492] If development error detection for the Can module is enabled:
        The function Can_SetBaudrate shall raise the error CAN_E_UNINIT and return
        E_NOT_OK if the driver is not yet initialized
    */
    else if (CAN_CS_UNINIT == g_eCanFd_ControllerState[u8CanFd_Controller])
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_SET_BAUDRATE, CAN_176_CANFD_E_UNINIT);
    }
    else if (CAN_CS_STOPPED != g_eCanFd_ControllerState[u8CanFd_Controller])
    {
        /*
            [SWS_Can_00256] If the call of Can_SetBaudrate() would cause a re-initialization 
            of the CAN Controller and the CAN Controller is not in state STOPPED, it shall return E_NOT_OK.
            [SWS_Can_00500] If the requested baud rate change can not performed without a 
            re-initialization of the CAN Controller E_NO_OK shall be returned.
        */
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_SET_BAUDRATE, CAN_176_CANFD_E_TRANSITION);
    }
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    else if (u32CanFd_CoreId != g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_Controller].CoreId)/* polyspace RTE:IDP */
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_SET_BAUDRATE, CAN_176_CANFD_E_PARAM_CONFIG);
    }
#endif
    else
    {
        u8CanFd_ret = E_OK;
    }

    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif
#endif

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_SetControllerModeVerify \
( \
    VAR(uint8, AUTOMATIC) u8CanFd_Controller \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    /*
        [SWS_Can_00198] If development error detection for the Can module is enabled: if 
        the module is not yet initialized, the function Can_SetControllerMode shall raise 
        development error CAN_E_UNINIT and return E_NOT_OK.
    */
    if (CAN_176_CANFD_READY != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_SET_CONTROLLER_MODE, CAN_176_CANFD_E_UNINIT);
    }
    /*
        [SWS_Can_00199] If development error detection for the Can module is enabled: if 
        the parameter Controller is out of range, the function Can_SetControllerMode 
        shall raise development error CAN_E_PARAM_CONTROLLER and return E_NOT_OK.
    */
    else if (u8CanFd_Controller >= CAN_176_CANFD_CONTROLLER_COUNT)
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_SET_CONTROLLER_MODE, CAN_176_CANFD_E_PARAM_CONTROLLER);
    }
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    else if (u32CanFd_CoreId != g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_Controller].CoreId)/* polyspace RTE:IDP */
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_SET_CONTROLLER_MODE, CAN_176_CANFD_E_PARAM_CONFIG);
    }
#endif
    else
    {
        u8CanFd_ret = E_OK;
    }
    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_DisableControllerInterruptsVerify \
( \
    VAR(uint8, AUTOMATIC) u8CanFd_Controller \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    /*
        [SWS_Can_00205] If development error detection for the Can module is enabled: 
        The function Can_DisableControllerInterrupts shall raise the error CAN_E_UNINIT if 
        the driver not yet initialized.
    */
    if (CAN_176_CANFD_READY != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_DISABLE_CONT_INTERRUPTS, CAN_176_CANFD_E_UNINIT);
    }
    else
    {
        /*
            [SWS_Can_00206] If development error detection for the Can module is enabled: 
            The function Can_DisableControllerInterrupts shall raise the error 
            CAN_E_PARAM_CONTROLLER if the parameter Controller is out of range.
        */
        if (u8CanFd_Controller >= CAN_176_CANFD_CONTROLLER_COUNT)
        {
            Can_176_CanFD_ReportError(CAN_176_CANFD_SID_DISABLE_CONT_INTERRUPTS, \
                CAN_176_CANFD_E_PARAM_CONTROLLER);
        }
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
        else if (u32CanFd_CoreId != g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_Controller].CoreId)/* polyspace RTE:IDP */
        {
            Can_176_CanFD_ReportError(CAN_176_CANFD_SID_DISABLE_CONT_INTERRUPTS, CAN_176_CANFD_E_PARAM_CONFIG);
        }
#endif
        else
        {
            u8CanFd_ret = (Std_ReturnType)E_OK;
        }
    }
    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_EnableControllerInterruptsVerify \
( \
    VAR(uint8, AUTOMATIC) u8CanFd_Controller \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    /*
        [SWS_Can_00209] If development error detection for the Can module is enabled: 
        The function Can_EnableControllerInterrupts shall raise the error CAN_E_UNINIT if 
        the driver not yet initialized.
    */
    if (CAN_176_CANFD_READY != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_ENABLE_CONT_INTERRUPTS, CAN_176_CANFD_E_UNINIT);
    }
    else
    {
        /*
            [SWS_Can_00210] If development error detection for the Can module is enabled: 
            The function Can_EnableControllerInterrupts shall raise the error 
            CAN_E_PARAM_CONTROLLER if the parameter Controller is out of range.
        */
        if (u8CanFd_Controller >= CAN_176_CANFD_CONTROLLER_COUNT)
        {
            Can_176_CanFD_ReportError(CAN_176_CANFD_SID_ENABLE_CONT_INTERRUPTS, \
                CAN_176_CANFD_E_PARAM_CONTROLLER);
        }
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
        else if (u32CanFd_CoreId != g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_Controller].CoreId)/* polyspace RTE:IDP */
        {
            Can_176_CanFD_ReportError(CAN_176_CANFD_SID_ENABLE_CONT_INTERRUPTS, CAN_176_CANFD_E_PARAM_CONFIG);
        }
#endif
        else
        {
            u8CanFd_ret = (Std_ReturnType)E_OK;
        }
    }
    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_GetControllerErrorStateVerify \
( \
    VAR(uint8, AUTOMATIC) u8CanFd_Controller, \
    P2CONST(Can_ErrorStateType, AUTOMATIC, CAN_APPL_CONST) ErrorStatePtr \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    /*
        [SWS_Can_91005] If development error detection for the Can module is enabled: if 
        the module is not yet initialized, the function Can_GetControllerErrorState shall raise 
        development error CAN_E_UNINIT and return E_NOT_OK.
    */
    if (CAN_176_CANFD_READY != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_GETCONTROLLERERRORSTATE, \
            CAN_176_CANFD_E_UNINIT);
    }
    /*
        [SWS_Can_91006] If development error detection for the Can module is enabled: if 
        the parameter ControllerId is out of range, the function Can_GetControllerErrorState 
        shall raise development error CAN_E_PARAM_CONTROLLER and return E_NOT_OK.
    */
    else if (u8CanFd_Controller >= CAN_176_CANFD_CONTROLLER_COUNT)
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_GETCONTROLLERERRORSTATE, \
            CAN_176_CANFD_E_PARAM_CONTROLLER);
    }
    /*
        [SWS_Can_91007] If development error detection for the Can module is enabled: if 
        the parameter ErrorStatePtr is a null pointer, the function 
        Can_GetControllerErrorState shall raise development error
        CAN_E_PARAM_POINTER and return E_NOT_OK.
    */
    else if (NULL_PTR == ErrorStatePtr)
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_GETCONTROLLERERRORSTATE, \
            CAN_176_CANFD_E_PARAM_POINTER);
    }
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
        else if (u32CanFd_CoreId != g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_Controller].CoreId)/* polyspace RTE:IDP */
        {
            Can_176_CanFD_ReportError(CAN_176_CANFD_SID_GETCONTROLLERERRORSTATE, CAN_176_CANFD_E_PARAM_CONFIG);
        }
#endif
    else
    {
        u8CanFd_ret = (Std_ReturnType)E_OK;
    }
    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
#if (CAN_176_CANFD_CHECK_WAKEUP_API == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_CheckWakeupVerify \
( \
    VAR(uint8, AUTOMATIC) u8CanFd_Controller \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    /*
        [SWS_Can_00362] If development error detection for the Can module is enabled: 
        The function Can_CheckWakeup shall raise the error CAN_E_UNINIT if the driver is 
        not yet initialized.
    */
    if (CAN_176_CANFD_READY != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_CBK_CHECK_WAKEUP, CAN_176_CANFD_E_UNINIT);
    }
    else
    {
        /*
            [SWS_Can_00363] If development error detection for the Can module is enabled: 
            The function Can_CheckWakeup shall raise the error 
            CAN_E_PARAM_CONTROLLER if the parameter Controller is out of range.
        */
        if (u8CanFd_Controller >= CAN_176_CANFD_CONTROLLER_COUNT)
        {
            Can_176_CanFD_ReportError(CAN_176_CANFD_SID_CBK_CHECK_WAKEUP, \
                CAN_176_CANFD_E_PARAM_CONTROLLER);
        }
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
        else if (u32CanFd_CoreId != g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_Controller].CoreId)/* polyspace RTE:IDP */
        {
            Can_176_CanFD_ReportError(CAN_176_CANFD_SID_CBK_CHECK_WAKEUP, CAN_176_CANFD_E_PARAM_CONFIG);
        }
#endif
        else
        {
            u8CanFd_ret = (Std_ReturnType)E_OK;
        }
    }
    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif
#endif

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_GetControllerModeVerify \
( \
    VAR(uint8, AUTOMATIC) u8CanFd_Controller, \
    P2CONST(Can_ControllerStateType, AUTOMATIC, CAN_APPL_CONST) pCanFd_ControllerMode \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    /*
        [SWS_Can_91016] If development error detection for the Can module is enabled:
        The function Can_GetControllerMode shall raise the error CAN_E_UNINIT and 
        return E_NOT_OK if the driver is not yet initialized.
    */
    if (CAN_176_CANFD_READY != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_GETCONTROLLERMODE, CAN_176_CANFD_E_UNINIT);
    }
    /*
        [SWS_Can_91017] If parameter Controller of Can_GetControllerMode() has an 
        invalid value, the CanDrv shall report development error code 
        CAN_E_PARAM_CONTROLLER to the Det_ReportError service of the DET.
    */
    else if (u8CanFd_Controller > CAN_176_CANFD_CONTROLLER_COUNT)
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_GETCONTROLLERMODE, CAN_176_CANFD_E_PARAM_CONTROLLER);
    }
    /*
        [SWS_Can_91018] If parameter ControllerModePtr of Can_GetControllerMode()
        has an null pointer, the CanDrv shall report development error code
        CAN_E_PARAM_POINTER to the Det_ReportError service of the DET
    */
    else if (NULL_PTR == pCanFd_ControllerMode)
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_GETCONTROLLERMODE, CAN_176_CANFD_E_PARAM_POINTER);
    }
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    else if (u32CanFd_CoreId != g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_Controller].CoreId)/* polyspace RTE:IDP */
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_GETCONTROLLERMODE, CAN_176_CANFD_E_PARAM_CONFIG);
    }
#endif
    else
    {
        u8CanFd_ret = (Std_ReturnType)E_OK;
    }
    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_GetControllerRxErrorCounterVerify \
( \
    VAR(uint8, AUTOMATIC) u8CanFd_Controller, \
    P2CONST(uint8, AUTOMATIC, CAN_APPL_CONST) pCanFd_RxErrorCounter \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    /*
        [SWS_Can_00512] If development error detection for the Can module is enabled: if 
        the module is not yet initialized, the function Can_GetControllerRxErrorCounter shall 
        raise development error CAN_E_UNINIT and return E_NOT_OK.
    */
    if (CAN_176_CANFD_READY != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        Can_176_CanFD_ReportError((uint8)CAN_176_CANFD_SID_GET_RX_ERROR_COUNTER, (uint8)CAN_176_CANFD_E_UNINIT);
    }
    /*
        [SWS_Can_00513] If development error detection for the Can module is enabled: if 
        the parameter ControllerId is out of range, the function 
        Can_GetControllerRxErrorCounter shall raise development error 
        CAN_E_PARAM_CONTROLLER and return E_NOT_OK. 
    */
    else if (u8CanFd_Controller > CAN_176_CANFD_CONTROLLER_COUNT)
    {
        Can_176_CanFD_ReportError((uint8)CAN_176_CANFD_SID_GET_RX_ERROR_COUNTER, (uint8)CAN_176_CANFD_E_PARAM_CONTROLLER);
    }
    /*
        [SWS_Can_00514] If development error detection for the Can module is enabled: if 
        the parameter RxErrorCounterPtr is a null pointer, the function 
        Can_GetControllerRxErrorCounter shall raise development error 
        CAN_E_PARAM_POINTER and return E_NOT_OK.
    */
    else if (NULL_PTR == pCanFd_RxErrorCounter)
    {
        Can_176_CanFD_ReportError((uint8)CAN_176_CANFD_SID_GET_RX_ERROR_COUNTER, (uint8)CAN_176_CANFD_E_PARAM_POINTER);
    }
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    else if (u32CanFd_CoreId != g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_Controller].CoreId)/* polyspace RTE:IDP */
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_GET_RX_ERROR_COUNTER, CAN_176_CANFD_E_PARAM_CONFIG);
    }
#endif
    else
    {
        u8CanFd_ret = (Std_ReturnType)E_OK;
    }

    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_GetControllerTxErrorCounterVerify \
( \
    VAR(uint8, AUTOMATIC) u8CanFd_Controller, \
    P2CONST(uint8, AUTOMATIC, CAN_APPL_CONST) pCan_TxErrorCounter \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    /*
        [SWS_Can_00517] If development error detection for the Can module is enabled: if 
        the module is not yet initialized, the function Can_GetControllerTxErrorCounter shall 
        raise development error CAN_E_UNINIT and return E_NOT_OK
    */
    if (CAN_176_CANFD_READY != g_eCanFd_DriverState[u32CanFd_CoreId] )/* polyspace RTE:OBAI */
    {
        Can_176_CanFD_ReportError((uint8)CAN_176_CANFD_SID_GET_TX_ERROR_COUNTER, \
            (uint8)CAN_176_CANFD_E_UNINIT);
    }
    /*
        [SWS_Can_00518] If development error detection for the Can module is enabled: if 
        the parameter ControllerId is out of range, the function 
        Can_GetControllerTxErrorCounter shall raise development error 
        CAN_E_PARAM_CONTROLLER and return E_NOT_OK.
    */
    else if (u8CanFd_Controller > CAN_176_CANFD_CONTROLLER_COUNT)
    {
        Can_176_CanFD_ReportError((uint8)CAN_176_CANFD_SID_GET_TX_ERROR_COUNTER,  \
            (uint8)CAN_176_CANFD_E_PARAM_CONTROLLER);
    }
    /*
        [SWS_Can_00519] If development error detection for the Can module is enabled: if 
        the parameter TxErrorCounterPtr is a null pointer, the function 
        Can_GetControllerTxErrorCounter shall raise development error 
        CAN_E_PARAM_POINTER and return E_NOT_OK.
    */
    else if (NULL_PTR == pCan_TxErrorCounter)
    {
        Can_176_CanFD_ReportError((uint8)CAN_176_CANFD_SID_GET_TX_ERROR_COUNTER, \
            (uint8)CAN_176_CANFD_E_PARAM_POINTER);
    }
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    else if (u32CanFd_CoreId != g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_Controller].CoreId)/* polyspace RTE:IDP */
    {
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_GET_TX_ERROR_COUNTER, CAN_176_CANFD_E_PARAM_CONFIG);
    }
#endif
    
    else
    {
        u8CanFd_ret = (Std_ReturnType)E_OK;
    }

    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_WriteVerify \
( \
    VAR(Can_HwHandleType, AUTOMATIC) u16CanFd_Hth, \
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) pCanFd_PduInfo, \
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = (Std_ReturnType)E_NOT_OK;
    /*
        [SWS_Can_00216] If development error detection for the Can module is enabled: 
        The function Can_Write shall raise the error CAN_E_UNINIT and shall return 
        E_NOT_OK if the driver is not yet initialized
    */
    if (CAN_176_CANFD_READY != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        Can_176_CanFD_ReportError((uint8)CAN_176_CANFD_SID_WRITE, (uint8)CAN_176_CANFD_E_UNINIT);
    }
    /*
        [SWS_Can_00219] If development error detection for CanDrv is enabled: 
        Can_Write() shall raise CAN_E_PARAM_POINTER and shall return E_NOT_OK if the 
        parameter PduInfo is a null pointer
    */
    else if (NULL_PTR == pCanFd_PduInfo)
    {
        Can_176_CanFD_ReportError((uint8)CAN_176_CANFD_SID_WRITE, (uint8)CAN_176_CANFD_E_PARAM_POINTER);
    }
    /*
        [SWS_Can_00217] If development error detection for the Can module is enabled: 
        The function Can_Write shall raise the error CAN_E_PARAM_HANDLE and shall 
        return E_NOT_OK if the parameter Hth is not a configured Hardware Transmit Handle.
    */
    else if (u16CanFd_Hth >= CAN_176_CANFD_HOH_CNT_MAX)
    {
        Can_176_CanFD_ReportError((uint8)CAN_176_CANFD_SID_WRITE, (uint8)CAN_176_CANFD_E_PARAM_HANDLE);
    }
#if (CAN_176_CANFD_TRIGGER_TRANSMIT_EN == STD_OFF)
    /*
        [SWS_Can_00503] Can_Write() shall accept a null pointer as SDU 
        (Can_PduType.Can_SduPtrType = NULL) if the trigger transmit API is enabled 
        for this hardware object (CanTriggerTransmitEnable = TRUE).
        [SWS_Can_00505]  If development error detection for CanDrv is enabled: 
        Can_Write() shall raise CAN_E_PARAM_POINTER and shall return E_NOT_OK if the 
        trigger transmit API is disabled for this hardware object (CanTriggerTransmitEnable = 
        FALSE) and the SDU pointer inside PduInfo is a null pointer.
    */
    else if (NULL_PTR == pCanFd_PduInfo->sdu)
    {
        Can_176_CanFD_ReportError((uint8)CAN_176_CANFD_SID_WRITE, (uint8)CAN_176_CANFD_E_PARAM_POINTER);
    }
#endif // CAN_TRIGGER_TRANSMIT_EN
    else
    {
        u8CanFd_ret = (Std_ReturnType)E_OK;
    }
    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#if (CAN_176_CANFD_VERSION_INFO_API == STD_ON)
/*****************************************************************************
**  Service Name     : Can_176_CanFD_GetVersionInfo        
**                                            
**  Description      : This function returns the version information of      
**                     this module.                                          
**                                                                            
**  Service ID       : 0x07                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            .
**                                                                            
**  Reentrancy       : Reentrant                                          
**                                                                            
**  Parameters (in)  : None  
**                                                                                     
**  Parameters (out) : versioninfo: Pointer to where to store the version information of this module.
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_GetVersionInfo \
( \
    P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_APPL_DATA) versioninfo \
)
{
    /*
        [SWS_Can_00177] If development error detection for the Can module is enabled: 
        The function Can_GetVersionInfo shall raise the error CAN_E_PARAM_POINTER if 
        the parameter versionInfo is a null pointer.
    */
    if (versioninfo == NULL_PTR)
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_GET_VERSION_INFO, CAN_176_CANFD_E_PARAM_POINTER);
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
    }
    else
    {
        versioninfo->vendorID = CAN_176_CANFD_H_VENDOR_ID;
        versioninfo->moduleID = CAN_176_CANFD_MODULE_ID;
        versioninfo->sw_major_version = CAN_176_CANFD_H_SW_MAJOR_VER;
        versioninfo->sw_minor_version = CAN_176_CANFD_H_SW_MINOR_VER;
        versioninfo->sw_patch_version = CAN_176_CANFD_H_SW_PATCH_VER;
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif // CAN_176_CANFD_VERSION_INFO_API

/*****************************************************************************
**  Service Name     : Can_176_CanFD_Init        
**                                             
**  Description      : This function initializes the module.   
**                                                                            
**  Service ID       : 0x00                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : Config: Pointer to driver configuration.  
**                                                                            
**  Parameters (out) : None                                                 
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_Init \
( \
    P2CONST(Can_176_CanFD_ConfigType, AUTOMATIC, CAN_APPL_CONST) Config \
)
{
    VAR(uint8, AUTOMATIC) u8CanFd_tempIdx = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Can_176_CanFD_InitVerify(Config,u32CanFd_CoreId))
    {
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
        if (NULL_PTR == g_pCanFd_CurConfig)
        {
#if (CAN_176_CANFD_PRECOMPILE_SUPPORT == STD_OFF)
        /*
            [SWS_Can_00056] Post-Build configuration elements that are marked as 'multiple' 
            ('M' or 'x') in chapter 10 can be selected by passing the pointer 'Config' to the init 
            function of the module.
        */
            g_pCanFd_CurConfig = Config;
#else
            g_pCanFd_CurConfig = &Can_176_CanFD_Config;
            (void)Config; /* Prevent compiler warning */
#endif
        }
        /*
            [SWS_Can_00239] The function Can_Init shall initialize all on-chip hardware 
            resources that are used by the CAN controller. The only exception to this is the digital 
            I/O pin configuration (of pins used by CAN), which is done by the port driver.
            [SWS_Can_00053] Can_Init shall not change registers of CAN controller Hardware 
            resources that are not used. 
        */
        for (; u8CanFd_tempIdx < CAN_176_CANFD_CONTROLLER_COUNT; u8CanFd_tempIdx++)
        {
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            if (u32CanFd_CoreId == g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_tempIdx].CoreId)
            {
#endif
                g_u16CanFd_CurBaudRateId[u8CanFd_tempIdx] = g_pCanFd_CurConfig->CanFdControllerConfig[u8CanFd_tempIdx].defaultBaudRateId;
                /*
                    [SWS_Can_00245] The function Can_Init shall initialize all CAN controllers 
                    according to their configuration.
                */
                Can_176_CanFD_AutoSar_Wrapper_InitController(u8CanFd_tempIdx, g_u16CanFd_CurBaudRateId[u8CanFd_tempIdx]);
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            }
#endif
        }
        /*
            [SWS_Can_00246] The function Can_Init shall change the module state to 
            CAN_READY, after initializing all controllers inside the HW Unit.
        */
        g_eCanFd_DriverState[u32CanFd_CoreId] = CAN_176_CANFD_READY;
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    }
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*****************************************************************************
**  Service Name     : Can_176_CanFD_DeInit        
**                                             
**  Description      : This function initializes the module.   
**                                                                                                 
**  Service ID       : 0x10                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : None  
**                                                                                     
**  Parameters (out) : None                                                 
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_DeInit(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_tempIdx = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Can_176_CanFD_DeInitVerify(u32CanFd_CoreId))
    {
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
        for (; u8CanFd_tempIdx < CAN_176_CANFD_CONTROLLER_COUNT; u8CanFd_tempIdx++)
        {
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            if (u32CanFd_CoreId == g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_tempIdx].CoreId)/* polyspace RTE:IDP */
            {
#endif
            Can_176_CanFD_AutoSar_Wrapper_DeInitController(u8CanFd_tempIdx);
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            }
#endif
        }
        /*
            [SWS_Can_91009] The function Can_DeInit shall change the module state to 
            CAN_UNINIT before de-initializing all controllers inside the HW unit
        */
        g_eCanFd_DriverState[u32CanFd_CoreId] = CAN_176_CANFD_UNINIT;
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    }
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#if (CAN_176_CANFD_SET_BAUDRATE_API == STD_ON)
/*****************************************************************************
**  Service Name     : Can_176_CanFD_SetBaudrate        
**                                             
**  Description      : This service shall set the baud rate configuration of 
**                     the CAN controller. Depending on necessary baud rate 
**                     modifications the controller might have to reset.
**                                                                           
**  Service ID       : 0x0F                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant for different Controllers. Non reentrant for 
**                     the same Controller.                                         
**                                                                            
**  Parameters (in)  : Controller: CAN controller, whose baud rate shall be set 
**                     BaudRateConfigID: references a baud rate configuration 
**                                       by ID (see CanControllerBaudRateConfigID)
**                                                                                     
**  Parameters (out) : None                                                 
**                                                                            
**  Return value     : Std_ReturnType: E_OK: Service request accepted, setting 
**                                           of (new) baud rate started
**                                     E_NOT_OK: Service request not accepted   
**                                                                            
******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_SetBaudrate \
( \
    VAR(uint8, AUTOMATIC) Controller, \
    VAR(uint16, AUTOMATIC) BaudRateConfigID \
)
{
    VAR(uint8, AUTOMATIC) u8CanFd_tempIdx = 0U;
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = (Std_ReturnType)E_NOT_OK;

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Can_176_CanFD_SetBaudrateVerify(Controller))
    {
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
        for (; u8CanFd_tempIdx < g_pCanFd_CurConfig->CanFdControllerConfig[Controller].baudRateConfigCount; u8CanFd_tempIdx++)/* polyspace RTE:IDP */
        {
            /*
                [SWS_Can_00493] If development error detection for the Can module is enabled:
                The function Can_SetBaudrate shall raise the error CAN_E_PARAM_BAUDRATE 
                and return E_NOT_OK if the parameter BaudRateConfigID has an invalid value.
            */
            if (BaudRateConfigID == g_pCanFd_CurConfig->CanFdControllerConfig[Controller].phy_para[u8CanFd_tempIdx].baudRateConfigId)
            {
                u8CanFd_ret = (Std_ReturnType)E_OK;
                break;
            }
        }
        if ((Std_ReturnType)E_OK != u8CanFd_ret)
        {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
            Can_176_CanFD_ReportError(CAN_176_CANFD_SID_SET_BAUDRATE, CAN_176_CANFD_E_PARAM_BAUDRATE);
#endif
        }
        else
        {
            /*
                [SWS_Can_00062] If Can_SetBaudrate determines that the aimed configuration 
                change requires a re-initialization and the CAN Controller is in STOPPED, the 
                function Can_SetBaudrate shall re-initialize the CAN controller and the controller 
                specific settings.
                [SWS_Can_00255] The function Can_SetBaudrate shall only affect register areas 
                that contain specific configuration for a single CAN controller.
            */
            g_u16CanFd_CurBaudRateId[Controller] = BaudRateConfigID;
            /*
                [SWS_Can_00260] If re-initialization is necessary the function Can_SetBaudrate 
                shall maintain the CAN controller in the state STOPPED.
            */
        }
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    }
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

/*****************************************************************************
**  Service Name     : Can_176_CanFD_SetControllerMode        
**                                             
**  Description      : This function performs software triggered state    
**                     transitions of the CAN controller State machine.
**                                                                                  
**  Service ID       : 0x03                                                   
**                                                                            
**  Sync/Async       : Asynchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : Controller: CAN controller for which the status shall be changed
**                     Transition: Transition value to request new CAN controller state  
**                                                                                     
**  Parameters (out) : None                                                 
**                                                                            
**  Return value     : Can_ReturnType                                                   
**                                                                            
******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_SetControllerMode \
( \
    VAR(uint8, AUTOMATIC) Controller, \
    VAR(Can_ControllerStateType, AUTOMATIC) Transition \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = E_NOT_OK;
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Can_176_CanFD_SetControllerModeVerify(Controller))
    {
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
        if (Transition > CAN_CS_SLEEP)
        {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
            Can_176_CanFD_ReportError(CAN_176_CANFD_SID_SET_CONTROLLER_MODE, CAN_176_CANFD_E_TRANSITION);
#endif
        }
        else
        {
            /*
                [SWS_Can_00017] The function Can_SetControllerMode shall perform software 
                triggered state transitions of the CAN controller State machine.
            */
            u8CanFd_ret = Can_176_CanFD_AutoSar_Wrapper_SetControllerMode(Controller, Transition);
        }
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    }
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*****************************************************************************
**  Service Name     : Can_176_CanFD_DisableControllerInterrupts  
**
**  Description      : This function disables all interrupts for this CAN     
**                     controller.                                            
**                                                                            
**  Service ID       : 0x04                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                              
**                                                                            
**  Parameters (in)  : Controller: CAN controller for which interrupts shall  
**                     be disabled.                                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
*******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_DisableControllerInterrupts(VAR(uint8, AUTOMATIC) Controller)
{
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Can_176_CanFD_DisableControllerInterruptsVerify(Controller))
    {
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
        Can_176_CanFD_AutoSar_Wrapper_DisableInterrupts(Controller);
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    }
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*****************************************************************************
**  Service Name     : Can_176_CanFD_EnableControllerInterrupts  
**
**  Description      : This function enables all allowed interrupts           
**                                                                            
**  Service ID       : 0x05                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                              
**                                                                            
**  Parameters (in)  : Controller: CAN controller for which interrupts shall  
**                     be re-enabled.                                         
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
*******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_EnableControllerInterrupts(VAR(uint8, AUTOMATIC) Controller)
{
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Can_176_CanFD_EnableControllerInterruptsVerify(Controller))
    {
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
        /*
            [SWS_Can_00050] The function Can_EnableControllerInterrupts shall enable all 
            interrupts that must be enabled according the current software status.
        */
        Can_176_CanFD_AutoSar_Wrapper_EnableInterrupts(Controller);
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    }
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#if (CAN_176_CANFD_CHECK_WAKEUP_API == STD_ON)
/*****************************************************************************
**  Service Name     : Can_176_CanFD_CheckWakeup  
**
**  Description      : This function checks if a wakeup has occurred for the  
**                     given controller.                                      
**                                                                            
**  Service ID       : 0x0b                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                              
**                                                                            
**  Parameters (in)  : controller: Controller to be checked for a wakeup.     
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                         
**                                                                            
*******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_CheckWakeup(VAR(uint8, AUTOMATIC) Controller)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Can_176_CanFD_ret = (Std_ReturnType)E_NOT_OK;
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Can_176_CanFD_CheckWakeupVerify(Controller))
    {
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
        if (g_eCanFd_ControllerState[Controller] != CAN_CS_SLEEP)
        {
            u8Can_176_CanFD_ret = (Std_ReturnType)E_OK;
        }
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    }
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
    return u8Can_176_CanFD_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif
/*****************************************************************************
**  Service Name     : Can_176_CanFD_GetControllerErrorState  
**
**  Description      : This service obtains the error state of the CAN controller.
**                                                                            
**  Service ID       : 0x11                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Non Reentrant for the same ControllerId       
**                                                                            
**  Parameters (in)  : ControllerId: Abstracted CanIf ControllerId which is 
**                     assigned to a CAN controller, which is requested for 
**                     ErrorState.                                                   
**                                                                            
**  Parameters (out) : ErrorStatePtr: Pointer to a memory location, where the 
**                     error state of the CAN controller will be stored.  
**                                                                            
**  Return value     : Std_ReturnType: E_OK: Error state request has been accepted.
**                                     E_NOT_OK: Error state request has not 
**                                               been accepted.           
**                                                                            
*******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_GetControllerErrorState \
( \
    VAR(uint8, AUTOMATIC) ControllerId, \
    P2VAR(Can_ErrorStateType, AUTOMATIC, CAN_APPL_DATA) ErrorStatePtr \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = (Std_ReturnType)E_NOT_OK;

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Can_176_CanFD_GetControllerErrorStateVerify(ControllerId, ErrorStatePtr))
    {
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
        /*
            [SWS_Can_91008] When the API Can_GetControllerErrorState() is called with 
            Controller Id as input parameter then Can driver shall read the error state register of 
            Can Controller and shall return the error status to upper layer.
        */
        *ErrorStatePtr = Can_176_CanFD_AutoSar_Wrapper_GetErrorState(ControllerId);
        u8CanFd_ret = (Std_ReturnType)E_OK;
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    }
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*****************************************************************************
**  Service Name     : Can_176_CanFD_GetControllerMode  
**
**  Description      : This service reports about the current status of the 
**                     requested CAN controller.
**                                                                            
**  Service ID       : 0x12                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Non Reentrant
**                                                                            
**  Parameters (in)  : Controller: CAN controller for which the status shall 
**                                 be requested.
**                                                                            
**  Parameters (out) : ControllerModePtr: Pointer to a memory location, where 
**                     the current mode of the CAN controller will be stored
**                                                                            
**  Return value     : Std_ReturnType: E_OK: Controller mode request has been accepted.
**                                     E_NOT_OK: Controller mode request has not been 
**                                                                            
*******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_GetControllerMode \
( \
    VAR(uint8, AUTOMATIC) Controller, \
    P2VAR(Can_ControllerStateType, AUTOMATIC, CAN_APPL_DATA) ControllerModePtr \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = (Std_ReturnType)E_NOT_OK;
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Can_176_CanFD_GetControllerModeVerify(Controller, ControllerModePtr))
    {
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
        /*
            [SWS_Can_91015] The service Can_GetControllerMode shall return the mode of 
            the requested CAN controller.
        */
        *ControllerModePtr = Can_176_CanFD_AutoSar_Wrapper_GetMode(Controller);
        u8CanFd_ret = (Std_ReturnType)E_OK;
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    }
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*****************************************************************************
**  Service Name     : Can_176_CanFD_GetControllerRxErrorCounter        
**                                             
**  Description      : Return the Rx error counter for a CAN controller. This value might not be
**                   available for all CAN controller, in which case E_NOT_OK would be returned.
**                   Please note that the value of the counter might not be correct at the moment
**                   the API returns it, because the Rx counter is handled asynchronously in hardware.
**                   Applications should not trust this value for any assumption about the current bus state.
**                                                                                                 
**  Service ID       : 0x30                                                
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant for different Controllers. Non reentrant for 
**                     the same Controller.                                         
**                                                                            
**  Parameters (in)  : Controller: CAN controller, whose current Rx error counter shall be acquired.
**                                                                                                          
**  Parameters (out) : RxErrorCounterPtr: Pointer to a memory location, where the current Rx error
**                       counter of the CAN controller will be stored.                                               
**                                                                            
**  Return value     : Std_ReturnType: E_OK: Service request accepted, setting 
**                                           of (new) baud rate started
**                                     E_NOT_OK: Service request not accepted                                                   
**                                                                            
******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_GetControllerRxErrorCounter \
( \
    VAR(uint8, AUTOMATIC) ControllerId, \
    P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) pRxErrorCounterPtr \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = (Std_ReturnType)E_NOT_OK;

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Can_176_CanFD_GetControllerRxErrorCounterVerify(ControllerId, pRxErrorCounterPtr))
    {
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
        /*
            [SWS_Can_00515] When the API Can_GetControllerRxErrorCounter is called with 
            Controller Id as input parameter then Can driver shall read the Rx error counter
            register of Can Controller and shall return the Rx error count to upper layer.
        */
        *pRxErrorCounterPtr = Can_176_CanFD_AutoSar_Wrapper_GetRxErrorCounter(ControllerId);
        u8CanFd_ret = (Std_ReturnType)E_OK;
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    }
#endif // CAN_176_CANFD_DEV_ERROR_DETECT

    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*****************************************************************************
**  Service Name     : Can_176_CanFD_GetControllerTxErrorCounter        
**                                             
**  Description      : Return the Tx error counter for a CAN controller. This value might not be
**                   available for all CAN controller, in which case E_NOT_OK would be returned.
**                   Please note that the value of the counter might not be correct at the moment
**                   the API returns it, because the Tx counter is handled asynchronously in hardware.
**                   Applications should not trust this value for any assumption about the current bus state.
**                                                                                                 
**  Service ID       : 0x31                                               
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant for different Controllers. Non reentrant for 
**                     the same Controller.                                         
**                                                                            
**  Parameters (in)  : Controller: CAN controller, whose current Tx error counter shall be acquired.            
**                                                                                     
**  Parameters (out) : pTxErrorCounterPtr: Pointer to a memory location, where the current Tx error
**                       counter of the CAN controller will be stored.                                               
**                                                                            
**  Return value     : Std_ReturnType: E_OK: Service request accepted, setting 
**                                           of (new) baud rate started
**                                     E_NOT_OK: Service request not accepted                                                   
**                                                                            
******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_GetControllerTxErrorCounter \
( \
    VAR(uint8, AUTOMATIC) ControllerId, \
    P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) pTxErrorCounterPtr \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = (Std_ReturnType)E_NOT_OK;

#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Can_176_CanFD_GetControllerTxErrorCounterVerify(ControllerId, pTxErrorCounterPtr))
    {
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
        /*
            [SWS_Can_00520] When the API Can_GetControllerTxErrorCounter is called with 
            Controller Id as input parameter then Can driver shall read the Tx error counter
            register of Can Controller and shall return the Tx error count to upper layer.
        */
        *pTxErrorCounterPtr = Can_176_CanFD_AutoSar_Wrapper_GetTxErrorCounter(ControllerId);
        u8CanFd_ret = (Std_ReturnType)E_OK;
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    }
#endif // CAN_176_CANFD_DEV_ERROR_DETECT

    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*****************************************************************************
**  Service Name     : Can_176_CanFD_Write  
**
**  Description      : This function is called by CanIf to pass a CAN message 
**                     to CanDrv for transmission.                            
**                                                                            
**  Service ID       : 0x06                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                              
**                                                                            
**  Parameters (in)  : Hth: information which HW-transmit handle shall be     
**                     used for transmit. Implicitly this is also the         
**                     information about the controller to use because the    
**                     Hth numbers are unique inside one hardware unit.       
**                     PduInfo: Pointer to SDU user memory, Data Length and   
**                     Identifier.                                            
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Can_ReturnType                                         
**                                                                            
*******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_Write \
( \
    VAR(Can_HwHandleType, AUTOMATIC) Hth, \
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) PduInfo \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8CanFd_ret = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Can_176_CanFD_WriteVerify(Hth, PduInfo,u32CanFd_CoreId))
    {
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
        u8CanFd_ret = Can_176_CanFD_AutoSar_Wrapper_Write(Hth, PduInfo);
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
    }
#else
    (void)u32CanFd_CoreId;
#endif // CAN_176_CANFD_DEV_ERROR_DETECT
    return u8CanFd_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#if (CAN_176_CANFD_MAINFUNCTION_WRITE_API == STD_ON)
/*****************************************************************************
**  Service Name     : Can_176_CanFD_MainFunction_Write  
**
**  Description      : This function performs the polling of TX confirmation  
**                     when CAN_TX_PROCESSING is set to POLLING.              
**                                                                            
**  Service ID       : 0x01                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                              
**                                                                            
**  Parameters (in)  : None                                                   
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
*******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Write(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_controllerIdx = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    if (CAN_176_CANFD_UNINIT != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        for (u8CanFd_controllerIdx = 0U; u8CanFd_controllerIdx < CAN_176_CANFD_CONTROLLER_COUNT; u8CanFd_controllerIdx++)
        {
            Can_176_CanFD_AutoSar_Wrapper_TxPolling(u8CanFd_controllerIdx);
        }
    }
    else
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE, CAN_176_CANFD_E_UNINIT);
#endif
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#if (CAN_176_CANFD_MAINFUNCTION_READ_API == STD_ON)
/*****************************************************************************
**  Service Name     : Can_176_CanFD_MainFunction_Read  
**
**  Description      : This function performs the polling of RX indications   
**                     when CAN_RX_PROCESSING is set to POLLING.              
**                                                                            
**  Service ID       : 0x08                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                              
**                                                                            
**  Parameters (in)  : None                                                   
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
*******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Read(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_controllerIdx = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    if (CAN_176_CANFD_UNINIT != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        for (u8CanFd_controllerIdx = 0U; u8CanFd_controllerIdx < CAN_176_CANFD_CONTROLLER_COUNT; u8CanFd_controllerIdx++)
        {
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            if (u32CanFd_CoreId == g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_controllerIdx].CoreId)/* polyspace RTE:IDP */
            {
#endif
                Can_176_CanFD_AutoSar_Wrapper_RxPolling(u8CanFd_controllerIdx);
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            }
#endif
        }
    }
    else
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE, CAN_176_CANFD_E_UNINIT);
#endif
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#if (CAN_176_CANFD_MULTIPLE_READ_PERIOD == STD_ON)
#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_READ_0
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Read_0(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_controllerIdx = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    if (CAN_176_CANFD_UNINIT != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        for (u8CanFd_controllerIdx = 0U; u8CanFd_controllerIdx < CAN_176_CANFD_CONTROLLER_COUNT; u8CanFd_controllerIdx++)
        {
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            if (u32CanFd_CoreId == g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_controllerIdx].CoreId)/* polyspace RTE:IDP */
            {
#endif
                Can_176_CanFD_AutoSar_Wrapper_RxPollingMul(u8CanFd_controllerIdx, 0U);
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            }
#endif
        }
    }
    else
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE, CAN_176_CANFD_E_UNINIT);
#endif
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_READ_1
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Read_1(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_controllerIdx = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    if (CAN_176_CANFD_UNINIT != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        for (u8CanFd_controllerIdx = 0U; u8CanFd_controllerIdx < CAN_176_CANFD_CONTROLLER_COUNT; u8CanFd_controllerIdx++)
        {
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            if (u32CanFd_CoreId == g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_controllerIdx].CoreId)/* polyspace RTE:IDP */
            {
#endif
                Can_176_CanFD_AutoSar_Wrapper_RxPollingMul(u8CanFd_controllerIdx, 1U);
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            }
#endif
        }
    }
    else
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE, CAN_176_CANFD_E_UNINIT);
#endif
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_READ_2
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Read_2(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_controllerIdx = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    if (CAN_176_CANFD_UNINIT != g_eCanFd_DriverState[u32CanFd_CoreId])
    {
        for (u8CanFd_controllerIdx = 0U; u8CanFd_controllerIdx < CAN_176_CANFD_CONTROLLER_COUNT; u8CanFd_controllerIdx++)
        {
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            if (u32CanFd_CoreId == g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_controllerIdx].CoreId)
            {
#endif
                Can_176_CanFD_AutoSar_Wrapper_RxPollingMul(u8CanFd_controllerIdx, 2U);
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            }
#endif
        }
    }
    else
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE, CAN_176_CANFD_E_UNINIT);
#endif
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_READ_3
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Read_3(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_controllerIdx = 0U;
VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    if (CAN_176_CANFD_UNINIT != g_eCanFd_DriverState[u32CanFd_CoreId])
    {
        for (u8CanFd_controllerIdx = 0U; u8CanFd_controllerIdx < CAN_176_CANFD_CONTROLLER_COUNT; u8CanFd_controllerIdx++)
        {
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            if (u32CanFd_CoreId == g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_controllerIdx].CoreId)
            {
#endif
                Can_176_CanFD_AutoSar_Wrapper_RxPollingMul(u8CanFd_controllerIdx, 3U);
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            }
#endif
        }
    }
    else
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE, CAN_176_CANFD_E_UNINIT);
#endif
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_READ_4
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Read_4(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_controllerIdx = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    if (CAN_176_CANFD_UNINIT != g_eCanFd_DriverState[u32CanFd_CoreId])
    {
        for (u8CanFd_controllerIdx = 0U; u8CanFd_controllerIdx < CAN_176_CANFD_CONTROLLER_COUNT; u8CanFd_controllerIdx++)
        {
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            if (u32CanFd_CoreId == g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_controllerIdx].CoreId)
            {
#endif
                Can_176_CanFD_AutoSar_Wrapper_RxPollingMul(u8CanFd_controllerIdx, 4U);
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            }
#endif
        }
    }
    else
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE, CAN_176_CANFD_E_UNINIT);
#endif
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#endif // CAN_176_CANFD_MULTIPLE_READ_PERIOD

#if (CAN_176_CANFD_MULTIPLE_WRITE_PERIOD == STD_ON)

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_WRITE_0
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Write_0(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_hwObjectIdex = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    if (CAN_176_CANFD_UNINIT != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        for (u8CanFd_hwObjectIdex = 0U; u8CanFd_hwObjectIdex < g_pCanFd_CurConfig->CanFdHwObjCount; u8CanFd_hwObjectIdex++)/* polyspace RTE:IDP */
        {
            Can_176_CanFD_AutoSar_Wrapper_TxPollingMul(u8CanFd_hwObjectIdex, 0U);
        }
    }
    else
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE, CAN_176_CANFD_E_UNINIT);
#endif
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_WRITE_1
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Write_1(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_hwObjectIdex = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    if (CAN_176_CANFD_UNINIT != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        for (u8CanFd_hwObjectIdex = 0U; u8CanFd_hwObjectIdex < g_pCanFd_CurConfig->CanFdHwObjCount; u8CanFd_hwObjectIdex++)/* polyspace RTE:IDP */
        {
            Can_176_CanFD_AutoSar_Wrapper_TxPollingMul(u8CanFd_hwObjectIdex, 1U);
        }
    }
    else
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE, CAN_176_CANFD_E_UNINIT);
#endif
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_WRITE_2
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Write_2(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_hwObjectIdex = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    if (CAN_176_CANFD_UNINIT != g_eCanFd_DriverState[u32CanFd_CoreId])
    {
        for (u8CanFd_hwObjectIdex = 0U; u8CanFd_hwObjectIdex < g_pCanFd_CurConfig->CanFdHwObjCount; u8CanFd_hwObjectIdex++)
        {
            Can_176_CanFD_AutoSar_Wrapper_TxPollingMul(u8CanFd_hwObjectIdex, 2U);
        }
    }
    else
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE, CAN_176_CANFD_E_UNINIT);
#endif
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_WRITE_3
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Write_3(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_hwObjectIdex = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    if (CAN_176_CANFD_UNINIT != g_eCanFd_DriverState[u32CanFd_CoreId])
    {
        for (u8CanFd_hwObjectIdex = 0U; u8CanFd_hwObjectIdex < g_pCanFd_CurConfig->CanFdHwObjCount; u8CanFd_hwObjectIdex++)
        {
            Can_176_CanFD_AutoSar_Wrapper_TxPollingMul(u8CanFd_hwObjectIdex, 3U);
        }
    }
    else
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE, CAN_176_CANFD_E_UNINIT);
#endif
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_WRITE_4
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Write_4(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_hwObjectIdex = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    if (CAN_176_CANFD_UNINIT != g_eCanFd_DriverState[u32CanFd_CoreId])
    {
        for (u8CanFd_hwObjectIdex = 0U; u8CanFd_hwObjectIdex < g_pCanFd_CurConfig->CanFdHwObjCount; u8CanFd_hwObjectIdex++)
        {
            Can_176_CanFD_AutoSar_Wrapper_TxPollingMul(u8CanFd_hwObjectIdex, 4U);
        }
    }
    else
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE, CAN_176_CANFD_E_UNINIT);
#endif
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#endif // CAN_176_CANFD_MULTIPLE_WRITE_PERIOD

#if (CAN_176_CANFD_MAINFUNCTION_BUSOFF_API == STD_ON)
/*****************************************************************************
**  Service Name     : Can_176_CanFD_MainFunction_BusOff  
**
**  Description      : This function performs the polling of bus-off events   
**                     that are configured statically as 'to be polled'.      
**                                                                            
**  Service ID       : 0x09                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                              
**                                                                            
**  Parameters (in)  : None                                                   
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
*******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_BusOff(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_controllerIdx = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/ 
    if (CAN_176_CANFD_UNINIT != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        for (u8CanFd_controllerIdx = 0U; u8CanFd_controllerIdx < CAN_176_CANFD_CONTROLLER_COUNT; u8CanFd_controllerIdx++)
        {
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            if (u32CanFd_CoreId == g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_controllerIdx].CoreId)/* polyspace RTE:IDP */
            {
#endif
                Can_176_CanFD_AutoSar_Wrapper_BusOffPolling(u8CanFd_controllerIdx);
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            }
#endif
        }
    }
    else
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE, CAN_176_CANFD_E_UNINIT);
#endif
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#if (CAN_176_CANFD_MAINFUNCTION_WAKEUP_API == STD_ON)
/*****************************************************************************
**  Service Name     : Can_176_CanFD_MainFunction_Wakeup  
**
**  Description      : This function performs the polling of wake-up events   
**                     that are configured statically as 'to be polled'.      
**                                                                            
**  Service ID       : 0x0a                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                              
**                                                                            
**  Parameters (in)  : None                                                   
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
*******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Wakeup(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_controllerIdx = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    if (CAN_176_CANFD_UNINIT != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        for (u8CanFd_controllerIdx = 0U; u8CanFd_controllerIdx < CAN_176_CANFD_CONTROLLER_COUNT; u8CanFd_controllerIdx++)
        {
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            if (u32CanFd_CoreId == g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_controllerIdx].CoreId)/* polyspace RTE:IDP */
            {
#endif
                Can_176_CanFD_AutoSar_Wrapper_WakeUpPolling(u8CanFd_controllerIdx);
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            }
#endif
        }
    } 
    else 
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE, CAN_176_CANFD_E_UNINIT);
#endif
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

/*****************************************************************************
**  Service Name     : Can_176_CanFD_MainFunction_Mode  
**
**  Description      : This function performs the polling of CAN controller   
**                     mode transitions.                                      
**                                                                            
**  Service ID       : 0x0c                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                              
**                                                                            
**  Parameters (in)  : None                                                   
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
*******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Mode(void)
{
    VAR(uint8, AUTOMATIC) u8CanFd_controllerIdx = 0U;
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/
    if (CAN_176_CANFD_UNINIT != g_eCanFd_DriverState[u32CanFd_CoreId])/* polyspace RTE:OBAI */
    {
        for (u8CanFd_controllerIdx = 0U; u8CanFd_controllerIdx < CAN_176_CANFD_CONTROLLER_COUNT; u8CanFd_controllerIdx++)
        {
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            if (u32CanFd_CoreId == g_pCanFd_CurConfig->CanFdCoreMap[u8CanFd_controllerIdx].CoreId)/* polyspace RTE:IDP */
            {
#endif
                /*
                    [SWS_Can_00369] The function Can_MainFunction_Mode shall implement the 
                    polling of CAN status register flags to detect transition of CAN Controller state.
                */
                Can_176_CanFD_AutoSar_Wrapper_ControllerModePolling(u8CanFd_controllerIdx);
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
            }
#endif
        }
    }
    else
    {
#if (CAN_176_CANFD_DEV_ERROR_DETECT == STD_ON)
        Can_176_CanFD_ReportError(CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE, CAN_176_CANFD_E_UNINIT);
#endif
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#endif /* RESOURCE_SUPPORT_CANFD_IP */

#ifdef __cplusplus
}
#endif

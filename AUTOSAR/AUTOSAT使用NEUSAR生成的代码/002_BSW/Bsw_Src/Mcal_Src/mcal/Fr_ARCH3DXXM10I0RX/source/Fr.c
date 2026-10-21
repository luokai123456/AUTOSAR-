/* PRQA S 0380, 2844, 2812, 0311, 3432, 1862 EOF */
/* PRQA S 0491, 2877, 0316, 1881, 1840, 2834 EOF */
/* PRQA S 3401, 3400, 3397, 3395, 1853, 1860 EOF */
/****************************************************************************
 *
 * Copyright (c) 2023  C*Core -   All Rights Reserved
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *   Project              : AUTOSAR 4.4.0 MCAL
 *   Platform             : PowerPC e200
 *   Peripheral           :
 *   Dependencies         :
 *
 *   Autosar Version      : 4.4.0
 *   Autosar Revision     : ASR_REL_4_3_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           :
 *   Build Version        :
 *
 *****************************************************************************/

/**
 *   @file    Fr.c
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
 *   @details Autosar layer of Fr MCAL driver.
 *
 *   @addtogroup Fr
 *   @{
 */
#ifdef __cplusplus
extern "C"{
#endif
#include "derivative.h"
#ifdef RESOURCE_SUPPORT_FLEXRAY
#include "Fr.h"
#if(FR_DEM_EVENT_DETECT == STD_ON)
/* Covers FR071 */
#include "Dem.h" /* Include DEM header file */
#endif /* FR_DISABLE_DEM_REPORT_ERROR_STATUS */

/* Covers FR118 */
#include "Det.h"
#include "Fr_HAL_Wrapper.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FR_MODULE_ID_C                        0
#define FR_VENDOR_ID_C                        176
#define FR_AR_RELEASE_MAJOR_VERSION_C         4
#define FR_AR_RELEASE_MINOR_VERSION_C         4
/* @violates @ref FR_FR_H_REF_2 */
#define FR_AR_RELEASE_REVISION_VERSION_C      0
#define FR_SW_MAJOR_VERSION_C                 3
#define FR_SW_MINOR_VERSION_C                 0
#define FR_SW_PATCH_VERSION_C                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr.h header file are of the same vendor */
#if(FR_VENDOR_ID_C != FR_H_VENDOR_ID)
    #error "Fr.c and Fr.h have different Vendor IDs"
#endif
/* Check if current file and Fr.h header file are of the same Autosar version */
#if((FR_AR_RELEASE_MAJOR_VERSION    != FR_AR_RELEASE_MAJOR_VERSION_C) || \
    (FR_AR_RELEASE_MINOR_VERSION    != FR_AR_RELEASE_MINOR_VERSION_C) || \
    (FR_H_AR_RELEASE_REVISION_VERSION != FR_AR_RELEASE_REVISION_VERSION_C))
    #error "AutoSar Version Numbers of Fr.c and Fr.h are different"
#endif
/* Check if current file and Fr.h header file are of the same software version */
#if((FR_H_SW_MAJOR_VERSION != FR_SW_MAJOR_VERSION_C) || \
    (FR_H_SW_MINOR_VERSION != FR_SW_MINOR_VERSION_C) || \
    (FR_H_SW_PATCH_VERSION != FR_SW_PATCH_VERSION_C))
    #error "Software Version Numbers of Fr.c and Fr.h are different"
#endif

/* Check if current file and Fr_HAL_Wrapper header file are of the same vendor */
#if(FR_H_VENDOR_ID != FR_HAL_WAR_H_VENDOR_ID)
    #error "Fr.c and Fr_HAL_Wrapper have different Vendor IDs"
#endif
/* Check if current file and Fr_HAL_Wrapper header file are of the same Autosar version */
#if((FR_AR_RELEASE_MAJOR_VERSION_C    != FR_HAL_WAR_H_AR_RELEASE_MAJOR_VERSION) || \
    (FR_AR_RELEASE_MINOR_VERSION_C    != FR_HAL_WAR_H_AR_RELEASE_MINOR_VERSION) || \
    (FR_AR_RELEASE_REVISION_VERSION_C != FR_HAL_WAR_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr.c and Fr_HAL_Wrapper are different"
#endif
/* Check if current file and Fr_HAL_Wrapper header file are of the same software version */
#if((FR_SW_MAJOR_VERSION_C != FR_HAL_WAR_H_SW_MAJOR_VERSION) || \
    (FR_SW_MINOR_VERSION_C != FR_HAL_WAR_H_SW_MINOR_VERSION) || \
    (FR_SW_PATCH_VERSION_C != FR_HAL_WAR_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr.c and Fr_HAL_Wrapper.h are different"
#endif


#define FR_START_SEC_VAR_INIT
#include "Fr_MemMap.h"
static P2CONST(Fr_ConfigType, AUTOMATIC, FR_APPL_CONST) Fr_pInternalCfg= NULL;
#define FR_STOP_SEC_VAR_INIT
#include "Fr_MemMap.h"

#if (FR_DEV_ERROR_DETECT == STD_ON)
/* Only if FR_DEV_ERROR_DETECT is enabled: */

#define FR_START_SEC_VAR_NO_INIT
#include "Fr_MemMap.h"
/* Arrays used for storage information how many absolute timers have been configured in a certain CC (0 - no timer configured) */
static VAR(uint8, FR_VAR) Fr_au8AbsoluteTimersNum[FR_NUM_CTRL_SUPPORTED];
#define FR_STOP_SEC_VAR_NO_INIT
#include "Fr_MemMap.h"

#define FR_START_SEC_VAR_NO_INIT
#include "Fr_MemMap.h"
static VAR(Fr_SoftwareStatesType, FR_VAR) Fr_eDriverStates;
#define FR_STOP_SEC_VAR_NO_INIT
#include "Fr_MemMap.h"

#define FR_START_SEC_VAR_NO_INIT
#include "Fr_MemMap.h"
static VAR(uint16, FR_VAR) Lpduidx_Max;
#define FR_STOP_SEC_VAR_NO_INIT
#include "Fr_MemMap.h"
#endif /* FR_DEV_ERROR_DETECT */
#if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
    /* Only if FR_BUFFER_RECONFIG is enabled: */
    /* Array is used for storage of information which virtual message buffer is currently configured
    for the physical message buffer each array element represents one physical MB and stored value
    corresponds with configured virtual MB index.
    Example: VirtualResourceAllocation[15] means that MB with index 15 (MBCCSR15,MBIDX15...) is
    configured for virtual MB with index 26 */
#define FR_START_SEC_VAR_SHARED_INIT
#include "Fr_MemMap.h"
VAR(uint16, FR_VAR) Fr_InternalResource[FR_NUM_CTRL_SUPPORTED][FR_NUMBER_MB] = {{0U}};
#define FR_STOP_SEC_VAR_SHARED_INIT
#include "Fr_MemMap.h"
#endif  /* FR_BUFFER_RECONFIG */

#if (FR_RECONFIG_LPDU_SUPPORT == STD_ON)
#if (FR_DEV_ERROR_DETECT == STD_ON)
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
static FUNC(Std_ReturnType, FR_CODE) FR_ValidateReconfigLPDU( VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint16, AUTOMATIC) Fr_LPduIdx,
                                                              VAR(uint16, AUTOMATIC) Fr_FrameId, VAR(Fr_ChannelType, AUTOMATIC) Fr_ChnlIdx,
                                                              VAR(uint8, AUTOMATIC) Fr_CycleRepetition, VAR(uint8, AUTOMATIC) Fr_CycleOffset,
                                                              VAR(uint8, AUTOMATIC) Fr_PayloadLength, VAR(uint16, AUTOMATIC) Fr_HeaderCRC
                                                            );
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif
#endif

#if (FR_DEM_EVENT_DETECT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_Dem_SetEventStatus
*
* @brief            Check and report Det error status.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
*                   u16StatusMask Status macro of DEM report.
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
static FUNC(void, FR_CODE) Fr_Dem_SetEventStatus(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(Dem_EventStatusType, AUTOMATIC) u16StatusMask)
{
    VAR(Dem_EventIdType, AUTOMATIC) eCtrlTestResult;

    if (STD_ON == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]->FrDemCtrlTestResultPtr->state)
    {
        /* The Fr_BuffersInit() function detected error while accessing the CC */
        eCtrlTestResult = (Dem_EventIdType)Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]->FrDemCtrlTestResultPtr->id;
        // (VAR(void, AUTOMATIC))Dem_SetEventStatus(eCtrlTestResult, u16StatusMask); //dq   
    }
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif /* FR_DEM_EVENT_DETECT */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/***************************************************************************************************
* @function_name    Fr_Init
*
* @brief            Controller initialization function
* @param[in]        Fr_ConfigPtr Address to an Fr dependant configuration structure that contains all 
                    information for operating the Fr subsequently
* @return           none
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_Init(
    P2CONST(Fr_ConfigType, AUTOMATIC, FR_APPL_CONST) Fr_ConfigPtr)
{
    #if (FR_DEV_ERROR_DETECT == STD_ON)
    if (FR_UNINIT == Fr_eDriverStates)
    {
    #if (FR_PRECOMPILE_SUPPORT == STD_OFF)
        if(NULL_PTR == Fr_ConfigPtr)
    #else
        if(NULL_PTR != Fr_ConfigPtr)
    #endif
        {
            /* If Fr_ConfigPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_INIT_U8, FR_E_PARAM_POINTER);
        }
        else
        {
        #if (FR_PRECOMPILE_SUPPORT == STD_OFF)
            Fr_pInternalCfg = (P2VAR(Fr_ConfigType, AUTOMATIC, FR_APPL_DATA))Fr_ConfigPtr;
        #else
            Fr_pInternalCfg = &Fr_cfg;
            (void)Fr_ConfigPtr;
        #endif
            /* Successful initialization done store for other API functions to check for proper module initialization */
            Fr_eDriverStates = FR_INIT;
        }
    }
    else
    {
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_INIT_U8, FR_E_INIT_FAILED);
    }
    #else
    if(NULL_PTR != Fr_ConfigPtr)
    {
    #if (FR_PRECOMPILE_SUPPORT == STD_OFF)
        Fr_pInternalCfg = (P2VAR(Fr_ConfigType, AUTOMATIC, FR_APPL_DATA))Fr_ConfigPtr;
    #else
        Fr_pInternalCfg = &Fr_cfg;
        (void)Fr_ConfigPtr;
    #endif
    }
    #endif/* FR_DEV_ERROR_DETECT */
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_ControllerInit
*
* @brief            CC configuration
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @return           :Std_ReturnType
*                       - E_OK      API API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_ControllerInit(
    VAR(uint8, FR_VAR) Fr_CtrlIdx)
{
    /*flexray init*/
    VAR(Fr_LLDriver_StatusType, FR_VAR) ret = StatusErro;
    VAR(Std_ReturnType, FR_VAR) retval = E_NOT_OK;
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, *) pCtrlCfg = NULL_PTR;

    #if (FR_CTRL_TEST_COUNT > 0U)
    VAR(uint8, AUTOMATIC) u8i = 0;
    VAR(boolean, AUTOMATIC) bCtrlTest = FALSE; 
    P2CONST(Fr_low_level_config_type, AUTOMATIC, *) Fr_temp_ptr;
    #endif

#if (FR_DEV_ERROR_DETECT == STD_ON)
    VAR(uint16, FR_VAR) temp_index = 0;
    if (FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_CONTROLLERINIT_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    /* Check the Fr_CtrlIdx value */
    else if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx)  
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_CONTROLLERINIT_U8, FR_E_INV_CTRL_IDX);
    }
    else if ((NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))/* polyspace RTE:IDP */
    {
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CONTROLLERINIT_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
    }
    else
    {
        Fr_au8AbsoluteTimersNum[Fr_CtrlIdx] = 2U;
#endif
    if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
    {
        pCtrlCfg = Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx];
        Fr_CC_reg_ptr = (P2VAR(uint16, AUTOMATIC, FR_APPL_DATA))pCtrlCfg->Fr_HW_config_temp_ptr->CC_base_address;
        if(E_OK == Fr_HAL_InvokeCHICommand(FrPOCR_POCCMD_FREEZE))
        { 
            #if (FR_DEV_ERROR_DETECT == STD_ON)
            while(pCtrlCfg->Fr_buffer_config_set_temp_ptr[temp_index++] != FR_LAST_MB)
            {
                Lpduidx_Max = temp_index;
            }
            #endif
            ret = Fr_HAL_InitConfigMode(pCtrlCfg -> Fr_HW_config_temp_ptr,pCtrlCfg -> Fr_low_level_config_temp_ptr);
            if(ret == StatusErro)
            {
                #if (FR_DEM_EVENT_DETECT == STD_ON)
                    Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                #endif 
            }
            else
            {
                Fr_HAL_ClusterNodeParamCfg(pCtrlCfg->Fr_HW_config_temp_ptr,pCtrlCfg->Fr_low_level_config_temp_ptr);
                if (Fr_HAL_Buffers_Init(Fr_CtrlIdx,pCtrlCfg->Fr_buffers_config_temp_ptr,pCtrlCfg->Fr_buffer_config_set_temp_ptr)==StatusErro)
                {
                    #if (FR_DEM_EVENT_DETECT == STD_ON)
                    Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                }
                else
                {
                    /* Disable all timers - already done by transition to POC:Halt */
                    Fr_HAL_DisableTimers();
                    if(Fr_HAL_Leave_Configuration_Mode() == StatusErro)
                    {
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif                   
                    }
                    else
                    {
                        #if (FR_CTRL_TEST_COUNT > 0U) 
                        /* CC Configuration Test */ 
                        Fr_temp_ptr = pCtrlCfg->Fr_low_level_config_temp_ptr;
                        for (u8i = 0U; u8i < (uint8)FR_CTRL_TEST_COUNT; u8i++) 
                        {
                            if ((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_HAL_ReadCCConfig(Fr_temp_ptr)) 
                            { 
                                bCtrlTest = TRUE; 
                                break;
                            }
                        }
                        if ((boolean)FALSE == bCtrlTest)
                        { 
                            #if (FR_DEM_EVENT_DETECT == STD_ON) 
                            Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED); 
                            #endif 
                        } 
                        else 
                        { 
                        #endif 
                            #if (FR_DEM_EVENT_DETECT == STD_ON)
                            Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_PASSED);
                            #endif
                            retval = E_OK;
                        #if (FR_CTRL_TEST_COUNT > 0U) 
                        }
                        #endif 
                    }   
                }
            }
        }
        
    }
    else
    {
        #if (FR_DEM_EVENT_DETECT == STD_ON)
        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
        #endif  
    }
#if (FR_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_StartCommunication
*
* @brief            Starts the communication
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_StartCommunication(
    VAR(uint8, FR_VAR) Fr_CtrlIdx)
{
    VAR(Fr_LLDriver_StatusType, FR_VAR) ret = StatusErro;
    VAR(Fr_POCStateType, FR_VAR) protocal_state;
    VAR(Std_ReturnType, FR_VAR) retval = E_NOT_OK;
    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_STARTCOMMUNICATION_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        /* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_STARTCOMMUNICATION_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_STARTCOMMUNICATION_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {


                    if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                    {
                    /* CC is not accessible, report error */
                    #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                    }
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
                    if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                    {
                        /* CC is not accessible, report error */
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
    #endif
                    else
                    {
                        protocal_state = Fr_HAL_Get_POC_State();
                        if(protocal_state != FR_POCSTATE_READY)
                        {
                            /* The CC is not in POC:Ready  */
                            (void)Det_ReportRuntimeError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_STARTCOMMUNICATION_U8, FR_E_INV_POCSTATE);
                        }
                        else    /* The CC is in POC:Ready  */
                        {
                            ret = Fr_HAL_Start_Communication();
                            if(ret == StatusErro)
                            {
                                /* API call was failed */
                                #if (FR_DEM_EVENT_DETECT == STD_ON)
                                Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                #endif
                            }
                            else
                            {
                                retval = E_OK;
                            }
                        }
                    }
                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_AllowColdstart
*
* @brief            Invokes the CC CHI command ALLOW_COLDSTART
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call in bad POC state or failure in access to the controller
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_AllowColdstart(
    VAR(uint8, FR_VAR) Fr_CtrlIdx)
{
    VAR(Fr_POCStateType, FR_VAR) protocal_state;
    VAR(Std_ReturnType, FR_VAR) retval = E_NOT_OK;


    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the initialization status */
    if (FR_INIT != Fr_eDriverStates)   
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ALLOWCOLDSTART_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else
    {/* Check the Fr_CtrlIdx value */
        if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
        {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ALLOWCOLDSTART_U8, FR_E_INV_CTRL_IDX);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ALLOWCOLDSTART_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {

                    if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                    {
                    /* CC is not accessible, report error */
                    #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                    }
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
                    if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                    {
                        /* CC is not accessible, report error */
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
    #endif
                    else    
                    {
                        protocal_state = Fr_HAL_Get_POC_State();
                        if((protocal_state == FR_POCSTATE_CONFIG)||(protocal_state == FR_POCSTATE_DEFAULT_CONFIG)||(protocal_state == FR_POCSTATE_HALT))
                        {
                            /* The CC is in POC:default config or POC:config or POC:halt */
                            (void)Det_ReportRuntimeError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ALLOWCOLDSTART_U8, FR_E_INV_POCSTATE);
                        }
                        else   
                        { /* CC is in required state */
                            if((protocal_state ==FR_POCSTATE_READY )||(protocal_state ==FR_POCSTATE_STARTUP ))
                            {
                            /* Yes
                             Immediately activate capability of node to cold start cluster */
                                if(E_OK == Fr_HAL_InvokeCHICommand(FrPOCR_POCCMD_ALLOW_COLDSTART))
                                {
                                    /* API call was successful */
                                    retval = E_OK;
                                }
                                else
                                {
                                    /* Call Dem for FR_DEM_EVENT_DETECT == STD_ON */
                                    #if (FR_DEM_EVENT_DETECT == STD_ON)
                                    Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                    #endif
                                    /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                                }
                            }
                            else
                            {
                                    retval = E_NOT_OK;
                            }
                        }
                    }
                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */

    return retval;

}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_AllSlots
*
* @brief            Invokes the CC CHI command ALL_SLOTS
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call in bad POC state or failure in access to the controller
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_AllSlots(
    VAR(uint8, FR_VAR) Fr_CtrlIdx)
{
    /*FrPOCR_POCCMD_ALL_SLOTS register is not used in FR LLD*/
    VAR(Std_ReturnType, FR_VAR) retval = E_NOT_OK;
    VAR(Fr_POCStateType, FR_VAR) protocal_state;

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the initialization status */
    if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ALLSLOTS_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {/* Check the Fr_CtrlIdx value */
        if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
        {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ALLSLOTS_U8, FR_E_INV_CTRL_IDX);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ALLSLOTS_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
                    if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                    {
                    /* CC is not accessible, report error */
                    #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                    }
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
                    if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                    {
                        /* CC is not accessible, report error */
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
    #endif
                    else    
                    {
                        protocal_state = Fr_HAL_Get_POC_State();
                        if ((FR_POCSTATE_NORMAL_ACTIVE != protocal_state) && (FR_POCSTATE_NORMAL_PASSIVE != protocal_state))
                        {
                            /* The CC is in POC:default config or POC:config or POC:halt */
                            (void)Det_ReportRuntimeError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ALLSLOTS_U8, FR_E_INV_POCSTATE);
                        }
                        else
                        {
                            if(E_OK == Fr_HAL_InvokeCHICommand(FrPOCR_POCCMD_ALL_SLOTS))
                            {
                                /* API call was successful */
                                retval = E_OK;
                            }
                            else
                            {
                                /* Call Dem for FR_DEM_EVENT_DETECT == STD_ON */
                                /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                                #if (FR_DEM_EVENT_DETECT == STD_ON)
                                Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                #endif
                            }
                        }
            
                    }
                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
     /* FR_DEV_ERROR_DETECT == STD_ON */
    #endif 

    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_HaltCommunication
*
* @brief            This API call stops communication.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call in bad POC state or failure in access to the controller
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HaltCommunication(
    VAR(uint8, FR_VAR) Fr_CtrlIdx)
{
    VAR(Fr_LLDriver_StatusType, FR_VAR) ret = StatusSuss;
    VAR(Std_ReturnType, FR_VAR) retval = E_NOT_OK;
    VAR(Fr_POCStateType, FR_VAR) protocal_state;

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the initialization status */
    if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_HALTCOMMUNICATION_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            /* Check the Fr_CtrlIdx value */
        if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
        {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_HALTCOMMUNICATION_U8, FR_E_INV_CTRL_IDX);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_HALTCOMMUNICATION_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {

                    if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                    {
                    /* CC is not accessible, report error */
                    #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                    }
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
                    if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                    {
                        /* CC is not accessible, report error */
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
    #endif
                    else    
                    {
                        protocal_state = Fr_HAL_Get_POC_State();

                        if((protocal_state != FR_POCSTATE_NORMAL_ACTIVE)&&(protocal_state != FR_POCSTATE_NORMAL_PASSIVE))
                        {
                            /* The CC is not synchronized to the FlexRay global time */
                            /* If CC is not synchronized to the FlexRay global time,FR_E_INV_POCSTATE shall be reported */
                            /* to the DET and the API function shall return. */
                            (void)Det_ReportRuntimeError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_HALTCOMMUNICATION_U8, FR_E_INV_POCSTATE);
                        }
                        else
                        {
                            ret = Fr_HAL_Stop_Communication(FR_HALT_COMMUNICATION);
                            if(ret == StatusSuss)
                            {
                                
                                retval = E_OK;
                            }
                            else
                            {
                                /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                                #if (FR_DEM_EVENT_DETECT == STD_ON)
                                Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                #endif
                            }
                        }
                    }
                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
     /* FR_DEV_ERROR_DETECT == STD_ON */
    #endif 
    
    return retval;

}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
/* POC transition FREEZE */

/***************************************************************************************************
* @function_name    Fr_AbortCommunication
*
* @brief            Abort the communication
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_AbortCommunication(
    VAR(uint8, FR_VAR) Fr_CtrlIdx)
{
    VAR(Fr_LLDriver_StatusType, FR_VAR) ret = StatusSuss;
    VAR(Std_ReturnType, FR_VAR) retval = E_NOT_OK;

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the initialization status */
    if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ABORTCOMMUNICATION_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {/* Check the Fr_CtrlIdx value */
        if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
        {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ABORTCOMMUNICATION_U8, FR_E_INV_CTRL_IDX);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ABORTCOMMUNICATION_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {

                    if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                    {
                    /* CC is not accessible, report error */
                    #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                    }
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
                    if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                    {
                        /* CC is not accessible, report error */
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                            Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
    #endif
                    else    
                    {
                        
                        ret = Fr_HAL_Stop_Communication(FR_ABORT_COMMUNICATION);
                        if(ret == StatusSuss)
                        {
                            retval =  E_OK;
                        }
                        else
                        {
                            /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                            #if (FR_DEM_EVENT_DETECT == STD_ON)
                            Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                    }
                }
        #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
     /* FR_DEV_ERROR_DETECT == STD_ON */
    #endif 
    return retval;

}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_SendWUP
*
* @brief            Initiates transition to POC:Wakeup
* @param[in]        Fr_CtrlIdx - Index of FlexRay CC within the context of the FlexRay Driver
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_SendWUP(
    VAR(uint8, FR_VAR) Fr_CtrlIdx)
{
    VAR(Fr_LLDriver_StatusType, FR_VAR) ret = StatusSuss;
    VAR(Fr_POCStateType, FR_VAR) protocal_state;
    VAR(Std_ReturnType, FR_VAR) retval = E_NOT_OK;
    
    #if (FR_DEV_ERROR_DETECT == STD_ON)
     /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx)
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SENDWUP_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
         /* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)  
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SENDWUP_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SENDWUP_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
                
                    if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                    {
                    /* CC is not accessible, report error */
                    #if (FR_DEM_EVENT_DETECT == STD_ON)
                    Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                    }
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
                    if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                    {
                        /* CC is not accessible, report error */
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
    #endif
                    else    
                    {
                        protocal_state = Fr_HAL_Get_POC_State();

                        if((protocal_state != FR_POCSTATE_READY))
                        {
                            /* The CC is not in POC:ready */
                            (void)Det_ReportRuntimeError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SENDWUP_U8, FR_E_INV_POCSTATE);
                        }
                        else
                        {
                            ret = Fr_HAL_Send_Wakeup();
                            if(ret == StatusErro)
                            {
                                /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                                #if (FR_DEM_EVENT_DETECT == STD_ON)
                                Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                #endif
                            }
                            else
                            {
                                retval = E_OK;
                            }
                        }
                    }
                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */

    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_SetWakeupChannel
*
* @brief            Selects which channel sends WUPs
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_ChnlIdx Index of FlexRay channel within the context of the FlexRay CC
*                   Fr_CtrlIdx
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_SetWakeupChannel(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(Fr_ChannelType, FR_VAR) Fr_ChnlIdx)
{
    /* CHI cmd  POCr Config */
    VAR(Std_ReturnType, FR_VAR) retval = E_NOT_OK;
    VAR(Fr_POCStateType, FR_VAR) protocal_state;

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETWAKEUPCHANNEL_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        /* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETWAKEUPCHANNEL_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if ((FR_CHANNEL_A != Fr_ChnlIdx) && (FR_CHANNEL_B != Fr_ChnlIdx))
            {
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETWAKEUPCHANNEL_U8, FR_E_INV_CHNL_IDX);
            }
            else
            {
                if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
                {
                     (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETWAKEUPCHANNEL_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
                }
                else
                {
                    if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                    {
                    /* CC is not accessible, report error */
                    #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                    }
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
                    if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                    {
                        /* CC is not accessible, report error */
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
    #endif
                    else    
                    {
                        protocal_state = Fr_HAL_Get_POC_State();
                        if((protocal_state != FR_POCSTATE_READY))
                        {
                            /* The CC is not in POC:ready */
                            (void)Det_ReportRuntimeError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETWAKEUPCHANNEL_U8, FR_E_INV_POCSTATE);
                        }
                        else
                        {
                            if(E_OK == Fr_HAL_SetWakeupChannel(Fr_ChnlIdx))
                            {
                                retval = E_OK;
                            }
                            else
                            {
                                /* Call Dem for FR_DEM_EVENT_DETECT == STD_ON */
                                #if (FR_DEM_EVENT_DETECT == STD_ON)
                                Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                #endif  
                                /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                            }
                        }
                    }
                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_GetPOCStatus
*
* @brief            Query for the controller status
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[out]       Fr_POCStatusPtr Address the output value is stored to
* @return           :Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_GetPOCStatus(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    P2VAR(Fr_POCStatusType, AUTOMATIC, FR_APPL_DATA) Fr_POCStatusPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETPOCSTATUS_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETPOCSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETPOCSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
    #else
            if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
            {
    #endif 
                if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                {
                    /* CC is not accessible, report error */
                    #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                }
                else    
                {
                    if (NULL_PTR != Fr_POCStatusPtr)
                    {
                        retval = Fr_HAL_GetPOCStatus(Fr_POCStatusPtr);
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        /* HW issue detected, Report error */
                        if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == retval)
                        {
                            Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        }
                        #endif
                    }
                    #if (FR_DEV_ERROR_DETECT == STD_ON)
                    else
                    {
                        /* If Fr_POCStatusPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                        /* to the DET and the API function shall return. */
                         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETPOCSTATUS_U8, FR_E_PARAM_POINTER);
                    }
                    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */
                }
            }
        #if (FR_DEV_ERROR_DETECT == STD_ON)
        }
    }
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_TransmitTxLPdu
*
* @brief            Update selected message buffer with new data
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx The index is used to uniquely identify a FlexRay frame
* @param[in]        Fr_LSduPtr This reference points to a buffer where the assembled LSdu to be 
*                   transmitted within this LPdu is stored at
* @param[in]        Fr_LSduLength Determines the length of the data (in Bytes) to be transmitted
* @param[out]       Fr_SlotAssignmentPtr This reference points to the memory location where the actual 
*                   cycle, slot ID, and channel of the frame identified by Fr_LPduIdx shall be stored. 
*                   A NULL_PTR indicates that the information is not required by the caller
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_TransmitTxLPdu(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_LPduIdx,
    P2CONST(uint8, AUTOMATIC, FR_APPL_CONST) Fr_LSduPtr,
    VAR(uint8, FR_VAR) Fr_LSduLength,
    P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) Fr_SlotAssignmentPtr)
{
    VAR(Fr_tx_MB_status_type, FR_VAR) tx_return_value;
    VAR(Std_ReturnType, FR_VAR) retval = E_NOT_OK;
    P2CONST(Fr_buffer_info_type, AUTOMATIC, *) buffer_info;
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, *) pCtrlCfg = NULL_PTR;
    
    #if (FR_DEV_ERROR_DETECT == STD_ON)
    VAR(boolean, AUTOMATIC) errorOccured = (VAR(boolean, AUTOMATIC))FALSE;
    /* Temporary pointer to transmit configuration data */
    P2CONST(Fr_transmit_buffer_config_type, AUTOMATIC, *) Fr_transmit_buffer_config_ptr; 
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_TRANSMITTXLPDU_U8, FR_E_INV_CTRL_IDX);
    }
    else
    { /* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)  
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_TRANSMITTXLPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_TRANSMITTXLPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
                if (NULL_PTR == Fr_LSduPtr)
                {
                    /* If Fr_LSduPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                    /* to the DET and the API function shall return. */
                   (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_TRANSMITTXLPDU_U8, FR_E_PARAM_POINTER);
                }
                else
                {
                   if(Fr_LPduIdx >Lpduidx_Max)
                    {
                        /* Fr_LPduIdx has an invalid value */
                        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_TRANSMITTXLPDU_U8, FR_E_INV_LPDU_IDX);
                    }
                    else
                    {
                        if (NULL_PTR == Fr_SlotAssignmentPtr)
                        {
                            /* If Fr_SlotAssignmentPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                            /* to the DET and the API function shall return. */
                            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_TRANSMITTXLPDU_U8, FR_E_PARAM_POINTER);
                        }
                        else    /* 1st phase; No error yet -> execute the following code */
                        {
                            
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */
                            if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                            {
                                pCtrlCfg = Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx];
                                buffer_info = pCtrlCfg->Fr_buffers_config_temp_ptr;
                        #if (FR_DEV_ERROR_DETECT == STD_ON)
                                Fr_transmit_buffer_config_ptr = (P2VAR(Fr_transmit_buffer_config_type, AUTOMATIC,FR_APPL_DATA))buffer_info[Fr_LPduIdx].buffer_config_ptr;
                                if(Fr_transmit_buffer_config_ptr->transmit_frame_ID > pCtrlCfg->Fr_low_level_config_temp_ptr->G_NUMBER_OF_STATIC_SLOTS)
                                {
                                    if(Fr_LSduLength > ((pCtrlCfg->Fr_low_level_config_temp_ptr->P_PAYLOAD_LENGTH_DYN_MAX)*2U))
                                    {
                                         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_TRANSMITTXLPDU_U8, FR_E_INV_LENGTH);
                                    errorOccured = (VAR(boolean, AUTOMATIC))TRUE;
                                    }
                                    
                                }
                                else
                                    {
                                        if(Fr_LSduLength > ((pCtrlCfg->Fr_low_level_config_temp_ptr->G_PAYLOAD_LENGTH_STATIC)*2U))
                                        {
                                         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_TRANSMITTXLPDU_U8, FR_E_INV_LENGTH);
                                        errorOccured = (VAR(boolean, AUTOMATIC))TRUE;
                                        }
                                    }   
                                    /* Check if some error occured */
                                if (!((VAR(boolean, FR_VAR))TRUE == errorOccured))    
                                {  
                        #endif
                                    if(FR_TRANSMIT_BUFFER == (buffer_info[Fr_LPduIdx].buffer_type))
                                    {
                                        #if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
                                        if(Fr_InternalResource[Fr_CtrlIdx][buffer_info[Fr_LPduIdx].buffer_index_init] == Fr_LPduIdx) /* polyspace RTE:OBAI */
                                        {      /* Yes, transmit buffer is correctly configured -> execute the following code */
                                         /* FR_BUFFER_RECONFIG */ 
                                        #endif
                                            if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                                            {
                                                /* CC is not accessible, report error */
                                                #if (FR_DEM_EVENT_DETECT == STD_ON)
                                                Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                                #endif 
                                            }
                                            else    
                                            {
                                                tx_return_value = Fr_HAL_Transmit_Data(buffer_info[Fr_LPduIdx].buffer_index_init, Fr_LSduPtr, Fr_LSduLength);
                                                
                                                if(tx_return_value == FR_TXMB_NO_ACCESS)
                                                {
                                                    /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                                                    #if (FR_DEM_EVENT_DETECT == STD_ON)
                                                    Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                                    #endif
                                                }
                                                else
                                                {
                                                    if(E_OK == Fr_HAL_FrExtendedLPduReport(pCtrlCfg,Fr_LPduIdx,Fr_SlotAssignmentPtr))
                                                    {
                                                        retval = E_OK;
                                                    }
                                                    
                                                }
                                            }
                                        #if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
                                        }
                                        #endif
                                    }
                                    else
                                    { /* LPdu is not configured for Tx -> abort the function execution and return E_NOT_OK  */
                                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                        #endif
                                       
                                    }

                            }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
                           }

                        }
                    }
                }
            }
        }
    }
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_CancelTxLPdu
*
* @brief            Reconfigures physical resource
* @details          [FR611]: Figure out the physical resource (e.g., a buffer) mapped to the 
*                   transmission of the FlexRay frame identified by Fr_LPduIdx.
*                   If the physical resource figured out is actively pending for transmission, 
*                   then the transmit request of this particular resource shall be terminated and 
*                   E_OK returned. If no transmission is pending E_NOT_OK shall be returned, 
*                   indicating that no such cancelation took place.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_CancelTxLPdu_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_CancelTxLPdu(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_LPduIdx)
{
    VAR(Std_ReturnType, AUTOMATIC) ret = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    P2CONST(Fr_buffer_info_type, AUTOMATIC, FR_APPL_CONST) buffer_info;
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg = NULL_PTR;
    VAR(boolean, AUTOMATIC) bPendingStatus = (VAR(boolean, AUTOMATIC))(FALSE);

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CANCELTXLPDU_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {/* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CANCELTXLPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CANCELTXLPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
                if(Fr_LPduIdx >Lpduidx_Max)
                {
                    /* Fr_LPduIdx has an invalid value */
                    (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CANCELTXLPDU_U8, FR_E_INV_LPDU_IDX);
                }
                else
                {
    /* FR_DEV_ERROR_DETECT == STD_ON */
    #endif 
                    if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                    {
                        pCtrlCfg = Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx];

                        /* Check whether a Tx MB is configured for given LPdu */
                        buffer_info = pCtrlCfg->Fr_buffers_config_temp_ptr;

                        #if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
                        if(Fr_InternalResource[Fr_CtrlIdx][buffer_info[Fr_LPduIdx].buffer_index_init] == Fr_LPduIdx) /* polyspace RTE:OBAI */
                        {      /* Yes, transmit buffer is correctly configured -> execute the following code */
                        /* FR_BUFFER_RECONFIG */ 
                        #endif 
                            if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                            {   /* CC is not accessible, report error */
                                #if (FR_DEM_EVENT_DETECT == STD_ON)
                                Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                #endif
                            }
                            else
                            {
                                /* @violates @ref Fr_c_REF_7 */
                                if ((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_HAL_CancelTxLPdu( buffer_info[Fr_LPduIdx].buffer_index_init, &bPendingStatus))
                                {
                                    /* Transmit request was terminated*/
                                    if ((VAR(boolean, AUTOMATIC))(TRUE) == bPendingStatus)
                                    {
                                        ret = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                                    }
                                    else
                                    {
                                        /* Transmit request was not terminated -> return E_NOT_OK */
                                    }
                                }
                                else
                                {
                                    /* Do nothing for FR_DEM_EVENT_DETECT == STD_OFF */
                                    #if (FR_DEM_EVENT_DETECT == STD_ON)
                                    Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                    #endif 

                                }
                            } /* Fr_check_CC_access */
                        #if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
                        }
                        /* FR_BUFFER_RECONFIG */ 
                        #endif 
                    }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */

    return ret;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_ReceiveRxLPdu
*
* @brief            Receives data
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame
* @param[out]       Fr_LSduPtr This reference points to the buffer where the LSdu to be received 
*                   shall be stored
* @param[out]       Fr_LPduStatusPtr This reference points to the memory location where the status
*                   of the LPdu shall be stored
* @param[out]       Fr_LSduLengthPtr This reference points to the memory location where the length 
*                   of the LSdu (in bytes) shall be stored. This length represents the number of
*                   bytes copied to Fr_LSduPtr
* @param[out]       Fr_SlotAssignmentPtr  This reference points to the memory location where the
*                   actual cycle, slot ID, and channel of the frame identified byFr_LPduIdx shall be 
*                   stored. A NULL_PTR indicates that the information is not required by the caller
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_ReceiveRxLPdu(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_LPduIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LSduPtr,
    P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_LPduStatusPtr,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LSduLengthPtr,
    P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) Fr_SlotAssignmentPtr)
{
    P2CONST(Fr_buffer_info_type, AUTOMATIC, *) buffer_info;
    VAR(Std_ReturnType, AUTOMATIC) retval = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    /* Temporary pointer to receive FIFO configuration data */
    P2CONST(Fr_FIFO_config_type, AUTOMATIC, *) Fr_FIFO_config_ptr;   
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, *) pCtrlCfg = NULL_PTR;

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECEIVERXLPDU_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {/* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECEIVERXLPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECEIVERXLPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {

                if (NULL_PTR == Fr_LSduPtr)
                {
                    /* If Fr_LSduPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                    /* to the DET and the API function shall return. */
                   (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_RECEIVERXLPDU_U8, FR_E_PARAM_POINTER);
                }
                else
                {
                    if (NULL_PTR == Fr_LSduLengthPtr)
                    {
                        /* If Fr_LSduPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                        /* to the DET and the API function shall return. */
                       (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_RECEIVERXLPDU_U8, FR_E_PARAM_POINTER);
                    }
                    else
                    {
                        if (NULL_PTR == Fr_LPduStatusPtr)
                        {
                            /* If Fr_LSduPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                            /* to the DET and the API function shall return. */
                           (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_RECEIVERXLPDU_U8, FR_E_PARAM_POINTER);
                        }
                        else
                        {
                            if(Fr_LPduIdx >Lpduidx_Max)
                            {
                                /* Fr_LPduIdx has an invalid value */
                                (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECEIVERXLPDU_U8, FR_E_INV_LPDU_IDX);
                            }
                            else
                            {

    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */
                                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                                {
                                    pCtrlCfg = Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx];
                                    buffer_info = pCtrlCfg->Fr_buffers_config_temp_ptr;

                                    if(FR_TRANSMIT_BUFFER != buffer_info[Fr_LPduIdx].buffer_type)
                                    {
                                        #if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
                                        if(Fr_InternalResource[Fr_CtrlIdx][buffer_info[Fr_LPduIdx].buffer_index_init] == Fr_LPduIdx) /* polyspace RTE:OBAI */
                                        {      /* Yes, transmit buffer is correctly configured -> execute the following code */
                                        /* FR_BUFFER_RECONFIG */
                                        #endif 
                                            if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                                            {
                                                /* CC is not accessible, report error */
                                                #if (FR_DEM_EVENT_DETECT == STD_ON)
                                                Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                                #endif
                                            }
                                            else
                                            {
                                                
                                                if(FR_RECEIVE_BUFFER == buffer_info[Fr_LPduIdx].buffer_type )
                                                {
                                                    *Fr_LPduStatusPtr = Fr_HAL_Receive_Data(buffer_info[Fr_LPduIdx].buffer_index_init, Fr_LSduPtr, Fr_LSduLengthPtr,Fr_SlotAssignmentPtr);
                                                    if( FR_RECEIVED == *Fr_LPduStatusPtr)
                                                    {
                                                        retval = E_OK;
                                                    }
                                            
                                                }
                                                else
                                                {
                                                    Fr_FIFO_config_ptr = (Fr_FIFO_config_type*)buffer_info[Fr_LPduIdx].buffer_config_ptr;
                                                    if(Fr_FIFO_config_ptr->FIFO_channel == FR_CHANNEL_A)
                                                    {
                                                        *Fr_LPduStatusPtr = Fr_HAL_Receive_FifoA_Data(Fr_LSduPtr,Fr_LSduLengthPtr,Fr_SlotAssignmentPtr);
                                                        retval = E_OK;
                                                    }
                                                    else if(Fr_FIFO_config_ptr->FIFO_channel == FR_CHANNEL_B)
                                                    {
                                                        *Fr_LPduStatusPtr = Fr_HAL_Receive_FifoB_Data(Fr_LSduPtr,Fr_LSduLengthPtr,Fr_SlotAssignmentPtr);
                                                        retval = E_OK;
                                                    }
                                                    else
                                                    {
                                                        /*Channel not support return E_NOT_OK*/
                                                    }
                                                }
                                                
                                            }
                                        #if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
                                        }
                                        /* FR_BUFFER_RECONFIG */
                                        #endif
                                    }
                                    else
                                    {/* Tx Buffer was detected -> abort function and return E_NOT_OK */
                                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                        #endif
                                        
                                    }
                                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
                            }
                        }
                    }
                }
            }
        }
    }
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */
    
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
 
/***************************************************************************************************
* @function_name    Fr_CheckTxLPduStatus
*
* @brief            Checks if data have been transmitted.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame
* @param[out]       Fr_TxLPduStatusPtr This reference is used to store the transmit status of the LPdu
* @param[out]       Fr_SlotAssignmentPtr This reference points to the memory location where the actual 
*                   cycle, slot ID, and channel of the frame identified by Fr_LPduIdx shall be stored. 
*                   A NULL_PTR indicates that the information is not required by the caller
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_CheckTxLPduStatus(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_LPduIdx,
    P2VAR(Fr_TxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_TxLPduStatusPtr,
    P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) Fr_SlotAssignmentPtr)
{
    P2CONST(Fr_buffer_info_type, AUTOMATIC, *) buffer_info;
    VAR(Std_ReturnType, AUTOMATIC) retval = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, *) pCtrlCfg = NULL_PTR;

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CHECKTXLPDUSTATUS_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {/* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CHECKTXLPDUSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CHECKTXLPDUSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
                if(Fr_LPduIdx >Lpduidx_Max)
                {
                    /* Fr_LPduIdx has an invalid value */
                    (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CHECKTXLPDUSTATUS_U8, FR_E_INV_LPDU_IDX);
                }
                else
                {
                    if(NULL_PTR == Fr_TxLPduStatusPtr)
                    {
                        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CHECKTXLPDUSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
                    }
                    else
                    {
    /* FR_DEV_ERROR_DETECT == STD_ON */          
    #endif  
                    if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                    {
                        pCtrlCfg = Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx];
                        if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                        {
                            /* CC is not accessible, report error */
                            #if (FR_DEM_EVENT_DETECT == STD_ON)
                            Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                        else    
                        {
                            buffer_info = pCtrlCfg->Fr_buffers_config_temp_ptr;
                            
                            #if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
                            if(Fr_InternalResource[Fr_CtrlIdx][buffer_info[Fr_LPduIdx].buffer_index_init] == Fr_LPduIdx) /* polyspace RTE:OBAI */
                            {      /* Yes, transmit buffer is correctly configured -> execute the following code */
                             /* FR_BUFFER_RECONFIG */
                            #endif
                                if(FR_TRANSMIT_BUFFER == buffer_info[Fr_LPduIdx].buffer_type )
                                {
                                    retval =  Fr_HAL_Check_Tx_Status(pCtrlCfg, Fr_LPduIdx, Fr_SlotAssignmentPtr,Fr_TxLPduStatusPtr);
                            
                                    if(retval == E_NOT_OK)
                                    {   /* Data was not transmitted */
                                        /* Do nothing for FR_DEM_EVENT_DETECT == STD_OFF return E_NOT_OK */
                                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                        #endif

                                    }
                                }
                                else
                                {/*buffer idx is not transmit buffer*/
                                    #if (FR_DEM_EVENT_DETECT == STD_ON)
                                    Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                    #endif
                                    
                                }
                            #if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
                            }
                            #endif
                            
                        }
                    }       
    #if (FR_DEV_ERROR_DETECT == STD_ON)
                    }
                }
            }
        }
    }
     /* FR_DEV_ERROR_DETECT == STD_ON */
    #endif 
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_PrepareLPdu
*
* @brief            Reconfigures physical resource
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_PrepareLPdu(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_LPduIdx)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) ret = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg = NULL_PTR;
    P2CONST(Fr_buffer_info_type, AUTOMATIC, FR_APPL_CONST) buffer_info;

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_PREPARELPDU_U8, FR_E_INV_CTRL_IDX);
    }
    else
    { /* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)  
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_PREPARELPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED); /* Report error */
        }
        else
        {

            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_PREPARELPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
                if(Fr_LPduIdx >Lpduidx_Max)
                {
                    /* Fr_LPduIdx has an invalid value */
                    (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_PREPARELPDU_U8, FR_E_INV_LPDU_IDX);
                }
                else
                {
                    pCtrlCfg = Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx];
           
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
                    pCtrlCfg = Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx];
    #endif /* FR_DEV_ERROR_DETECT */
                    if(TRUE == pCtrlCfg->Fr_buffers_config_temp_ptr[Fr_LPduIdx].ReconfigureType)
                    {
                        /* Check  whether LPdu is not dynamically reconfigurable, only LPdus which are not
                        dynamically reconfigurable can use reconfiguration feature */
                        buffer_info = pCtrlCfg->Fr_buffers_config_temp_ptr;
                    
                        if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                        {   /* CC is not accessible, report error */
                            #if (FR_DEM_EVENT_DETECT == STD_ON)
                            Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                        else
                        {
                            if ((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_HAL_PrepareLPdu(pCtrlCfg,Fr_LPduIdx, buffer_info[Fr_LPduIdx].buffer_index_init))
                            {
                                ret = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                            }
                            else
                            {
                                /* Call Dem for FR_DEM_EVENT_DETECT == STD_ON */
                                #if (FR_DEM_EVENT_DETECT == STD_ON)
                                Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                #endif
                            }
                        /* Fr_check_CC_access */  
                        }      
                    }
                    else
                    {
                        ret = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
                    }
                    
                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    /* FR_DEV_ERROR_DETECT */
    #endif 
    return ret;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
/*FR_RECONFIG_LPDU_SUPPORT == STD_ON*/
#endif 
#endif

#if (FR_RECONFIG_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_ReconfigLPdu
*
* @brief            Reconfigures physical resource
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame
* @param[in]        Fr_FrameId FlexRay Frame ID the FrIf_LPdu shall be configured to
* @param[in]        Fr_ChnlIdx FlexRay Channel the FrIf_LPdu shall be configured to
* @param[in]        Fr_CycleRepetition Cycle Repetition part of the cycle filter mechanism FrIf_LPdu
*                   shall be configured to
* @param[in]        Fr_CycleOffset Cycle Offset part of the cycle filter mechanism FrIf_LPdu shall
*                   be configured to
* @param[in]        Fr_PayloadLength Payloadlength in units of bytes the FrIf_LPduIdx shall be
*                   configured to
* @param[in]        Fr_HeaderCRC Header CRC the FrIf_LPdu shall be configured to
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_ReconfigLPdu(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_LPduIdx,
    VAR(uint16, FR_VAR) Fr_FrameId,
    VAR(Fr_ChannelType, FR_VAR) Fr_ChnlIdx,
    VAR(uint8, FR_VAR) Fr_CycleRepetition,
    VAR(uint8, FR_VAR) Fr_CycleOffset,
    VAR(uint8, FR_VAR) Fr_PayloadLength,
    VAR(uint16, FR_VAR) Fr_HeaderCRC)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) ret = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg = NULL_PTR;
    P2CONST(Fr_buffer_info_type, AUTOMATIC, FR_APPL_CONST) buffer_info;

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    if ( (VAR(Std_ReturnType,AUTOMATIC)) E_OK == FR_ValidateReconfigLPDU(Fr_CtrlIdx, Fr_LPduIdx, Fr_FrameId, Fr_ChnlIdx,
                                                Fr_CycleRepetition, Fr_CycleOffset, Fr_PayloadLength, Fr_HeaderCRC))
    {
    #endif /* FR_DEV_ERROR_DETECT */
    if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
    {
        pCtrlCfg = Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx];
        buffer_info = pCtrlCfg->Fr_buffers_config_temp_ptr;
        /* Check  whether LPdu is dynamically reconfigurable, only dynamically reconfigurable
        LPdus can be reconfigured */
        if(TRUE == pCtrlCfg->Fr_buffers_config_temp_ptr[Fr_LPduIdx].ReconfigureType)
        {
            /* Check whether buffer is correctly configured to match the properties of virtual one */
                /* Check whether target Fr_FrameId is inside static segment */
            if(Fr_InternalResource[Fr_CtrlIdx][buffer_info[Fr_LPduIdx].buffer_index_init] == Fr_LPduIdx) /* polyspace RTE:OBAI */
            {      /* Yes, transmit buffer is correctly configured -> execute the following code */
                if (Fr_FrameId <= Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]->Fr_low_level_config_temp_ptr->G_NUMBER_OF_STATIC_SLOTS)
                {
                    if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                    {
                        /* CC is not accessible, report error */
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else
                    {
                        if ((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_HAL_ReconfigLPdu(pCtrlCfg,buffer_info[Fr_LPduIdx].buffer_index_init, Fr_FrameId
                                                                                         , Fr_ChnlIdx, Fr_CycleRepetition,
                                                                                         Fr_CycleOffset, Fr_PayloadLength,
                                                                                         Fr_HeaderCRC))
                        {
                            ret = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                        }
                        else
                        {
                            /* Call Dem for FR_DEM_EVENT_DETECT == STD_ON */
                            #if (FR_DEM_EVENT_DETECT == STD_ON)
                            Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                    } /* Fr_check_CC_access */
                }
            }
        }
    }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
    return ret;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif

#if (FR_RECONFIG_LPDU_SUPPORT == STD_ON)
#if (FR_DISABLE_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_DisableLPdu
*
* @brief            Reconfigures physical resource
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_DisableLPdu
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(uint16, AUTOMATIC) Fr_LPduIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) ret = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg = NULL_PTR;
    P2CONST(Fr_buffer_info_type, AUTOMATIC, FR_APPL_CONST) buffer_info;

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
     /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx)
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_DISABLELPDU_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {/* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_DISABLELPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_DISABLELPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
                if(Fr_LPduIdx >Lpduidx_Max)
                {
                    /* Fr_LPduIdx has an invalid value */
                    (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_DISABLELPDU_U8, FR_E_INV_LPDU_IDX);
                }
                else
                {
                    pCtrlCfg = Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx];
                    buffer_info = pCtrlCfg->Fr_buffers_config_temp_ptr;
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
                    pCtrlCfg = Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx];
                    buffer_info = pCtrlCfg->Fr_buffers_config_temp_ptr;
    #endif /* FR_DEV_ERROR_DETECT */
                    if(TRUE == pCtrlCfg->Fr_buffers_config_temp_ptr[Fr_LPduIdx].ReconfigureType)
                    {
                        /* Check  whether LPdu is dynamically reconfigurable, only dynamically reconfigurable
                        LPdus can be disabled by this service */
                        if(Fr_InternalResource[Fr_CtrlIdx][buffer_info[Fr_LPduIdx].buffer_index_init] == Fr_LPduIdx) /* polyspace RTE:OBAI */
                        {       /* Yes, transmit buffer is correctly configured -> execute the following code */
                            if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                            {   /* CC is not accessible, report error */
                                #if (FR_DEM_EVENT_DETECT == STD_ON)
                                Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                #endif
                            }
                            else
                            {
                                if ((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_HAL_DisableLPdu(buffer_info[Fr_LPduIdx].buffer_index_init))
                                {
                                    ret = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                                }
                                else
                                {
                                    /* Call Dem for FR_DEM_EVENT_DETECT == STD_ON */
                                    #if (FR_DEM_EVENT_DETECT == STD_ON)
                                    Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                    #endif
                                }
                            }
                        }
                    }
                    else
                    {
                        ret = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
                    }
                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    /* FR_DEV_ERROR_DETECT */
    #endif
    return ret;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
 /* FR_DISABLE_LPDU_SUPPORT */
#endif
#endif
/***************************************************************************************************
* @function_name    Fr_GetGlobalTime
*
* @brief            Function gets FlexRay cluster global time
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[out]       Fr_CyclePtr Address where the current FlexRay communication cycle value
*                   shall be stored
* @param[out]       Fr_MacroTickPtr Address where the current macrotick value shall be stored
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_GetGlobalTime(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_CyclePtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_MacroTickPtr)
{
    VAR(Std_ReturnType, FR_VAR) retval = E_NOT_OK;
    VAR(Fr_POCStateType, FR_VAR) protocal_state;
    

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETGLOBALTIME_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        /* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETGLOBALTIME_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_CyclePtr)
            {
                /* If Fr_CyclePtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                /* to the DET and the API function shall return. */
                (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETGLOBALTIME_U8, FR_E_PARAM_POINTER);
            }
            else
            {
                if (NULL_PTR == Fr_MacroTickPtr)
                {
                    /* If Fr_MacroTickPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                    /* to the DET and the API function shall return. */
                    (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETGLOBALTIME_U8, FR_E_PARAM_POINTER);
                }
                else
                {
                    if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
                    {
                        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETGLOBALTIME_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
                    }
                    else
                    {
    #else   
                    if ( (NULL_PTR != Fr_pInternalCfg) &&(NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                    {                                        
    #endif  
                        if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                        {
                            /* CC is not accessible, report error */
                            #if (FR_DEM_EVENT_DETECT == STD_ON)
                            Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                        else    
                        {
                            protocal_state = Fr_HAL_Get_POC_State();
                            if((protocal_state == FR_POCSTATE_NORMAL_ACTIVE)||(protocal_state == FR_POCSTATE_NORMAL_PASSIVE))
                            {
                                Fr_HAL_Get_Global_Time(Fr_CyclePtr, Fr_MacroTickPtr);
                                retval = E_OK;
                            }
                            else
                            {
                                /* The CC is not synchronous to the cluster */
                                #if (FR_DEM_EVENT_DETECT == STD_ON)
                                Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                #endif
                                /* Set error return value */
                                retval = E_NOT_OK;
                            }
                        }
                    }
    #if (FR_DEV_ERROR_DETECT == STD_ON)            
                }
            }
        }                   
    }
    #endif /* FR_DEV_ERROR_DETECT */
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_GetNmVector
*
* @brief            Read network management vector
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[out]       Fr_NmVectorPtr Address where the NmVector of the last communication cycle
*                   shall be stored
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_GetNmVector(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_NmVectorPtr)
{
    VAR(Std_ReturnType, FR_VAR) retval = E_NOT_OK;
    VAR(Fr_POCStateType, FR_VAR) protocal_state;
    

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETNMVECTOR_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        /* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETNMVECTOR_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
           if (NULL_PTR == Fr_NmVectorPtr)
            {
                /* If Fr_NmVectorPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                /* to the DET and the API function shall return. */
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETNMVECTOR_U8, FR_E_PARAM_POINTER);
            }
            else
            {
                if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
                {
                     (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETNMVECTOR_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
                }
                else
                {
     #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {            
    /* FR_DEV_ERROR_DETECT == STD_ON */  
    #endif 
                    if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                    {
                        /* CC is not accessible, report error */
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else    
                    {
                        protocal_state = Fr_HAL_Get_POC_State();
                        if((protocal_state == FR_POCSTATE_NORMAL_ACTIVE)||(protocal_state == FR_POCSTATE_NORMAL_PASSIVE))
                        {
                            retval = Fr_HAL_Get_Network_Management_Vector(Fr_NmVectorPtr);
                        }
                        else
                        {
                            /* The CC is not synchronous to the cluster */
                            /* Set error return value */
                            retval = E_NOT_OK;
                        }
                    }
                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_GetNumOfStartupFrames
*
* @brief            Gets the current number of startup frames seen on the cluster.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_NumOfStartupFramesPtr Address where the number of startup frames seen within
*                   the last even or odd cycle pair shall be stored
* @param[out]       Fr_ConfigParamValuePtr Address the output value is stored to
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_GetNumOfStartupFrames(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_NumOfStartupFramesPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(Fr_POCStateType, AUTOMATIC) protocal_state;
    
    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETNUMOFSTARTUPFRAMES_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        /* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETNUMOFSTARTUPFRAMES_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_NumOfStartupFramesPtr)
            {
                /* Fr_ConfigParamValuePtr has an invalid value */
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETNUMOFSTARTUPFRAMES_U8, FR_E_PARAM_POINTER);
            }
            else
            {
                if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
                {
                     (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETNUMOFSTARTUPFRAMES_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
                }
                else
                {
    #else                
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
    /* FR_DEV_ERROR_DETECT == STD_ON */                
    #endif  
                    if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                    {
                        /* CC is not accessible, report error */
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                            Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else    
                    {
                        protocal_state = Fr_HAL_Get_POC_State();
                        if((protocal_state == FR_POCSTATE_NORMAL_ACTIVE)||(protocal_state == FR_POCSTATE_NORMAL_PASSIVE))
                        {
                            /* FlexRay 2.1 Rev A compliant hardware does not suppport accumulating the number of
                            startupframes. The driver shall always assume 2 startup frames available */
                            *Fr_NumOfStartupFramesPtr = 2U;
                            retval = E_OK;
                        }
                        else
                        {
                            /* The CC is not synchronous to the cluster */
                            /* Set error return value */
                            retval = E_NOT_OK;
                        }
                    }
                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    /* FR_DEV_ERROR_DETECT == STD_ON */
    #endif  
    
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_GetChannelStatus
*
* @brief            Read channel status
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[out]       Fr_ChannelAStatusPtr Address where the bitcoded channel A status information
*                   shall be stored
* @param[out]       Fr_ChannelBStatusPtr Address where the bitcoded channel B status information
*                   shall be stored
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_GetChannelStatus(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAStatusPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBStatusPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) retval =  (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(Fr_POCStateType, AUTOMATIC) protocal_state;

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCHANNELSTATUS_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        /* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCHANNELSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCHANNELSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
                if (NULL_PTR == Fr_ChannelAStatusPtr)
                {
                    /* If Fr_ChannelAStatusPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                    /* to the DET and the API function shall return. */
                     (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCHANNELSTATUS_U8, FR_E_PARAM_POINTER);
                }
                else
                {
                    if (NULL_PTR == Fr_ChannelBStatusPtr)
                    {
                        /* If Fr_ChannelBStatusPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                        /* to the DET and the API function shall return. */
                       (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCHANNELSTATUS_U8, FR_E_PARAM_POINTER);
                    }
                    else /* No error yet -> execute the following code */
                    {
    #else           
                    if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                    { 
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */
                        if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                        {
                            /* CC is not accessible, report error */
                            #if (FR_DEM_EVENT_DETECT == STD_ON)
                            Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                        else    
                        {
                            protocal_state = Fr_HAL_Get_POC_State();
                            if((protocal_state == FR_POCSTATE_NORMAL_ACTIVE)||(protocal_state == FR_POCSTATE_NORMAL_PASSIVE))
                            {
                                Fr_HAL_GetChannelStatus(Fr_ChannelAStatusPtr,Fr_ChannelBStatusPtr);
                                retval = E_OK;
                            }
                            else
                            {
                                /* The CC is not synchronous to the cluster */
                                /* Set error return value */
                                retval = E_NOT_OK;
                            }
                        }
                    }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
    /* FR_DEV_ERROR_DETECT == STD_ON */
    #endif  
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
    
/***************************************************************************************************
* @function_name    Fr_GetClockCorrection
*
* @brief            Gets clock correction values
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[out]       Fr_RateCorrectionPtr Address where the current rate correction value shall
*                   be stored
* @param[out]       Fr_OffsetCorrectionPtr Address where the current offset correction value
*                   shall be stored
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_GetClockCorrection(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    P2VAR(sint16, AUTOMATIC, FR_APPL_DATA) Fr_RateCorrectionPtr,
    P2VAR(sint32, AUTOMATIC, FR_APPL_DATA) Fr_OffsetCorrectionPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) returnValue = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK;

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCLOCKCORRECTION_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        /* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCLOCKCORRECTION_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_RateCorrectionPtr)
            {
                /* If Fr_ChannelAStatusPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                /* to the DET and the API function shall return. */
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCLOCKCORRECTION_U8, FR_E_PARAM_POINTER);
            }
            else
            {
                if (NULL_PTR == Fr_OffsetCorrectionPtr)
                {
                    /* If Fr_ChannelBStatusPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                    /* to the DET and the API function shall return. */
                     (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCLOCKCORRECTION_U8, FR_E_PARAM_POINTER);
                }
                else
                {
                    if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
                    {
                         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCLOCKCORRECTION_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
                    }
                    else
                    {
     #else
                    if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                    {            
    /* FR_DEV_ERROR_DETECT == STD_ON */                    
    #endif  

                        if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                        {
                            /* CC is not accessible, report error */
                            #if (FR_DEM_EVENT_DETECT == STD_ON)
                                Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif

                        }
                        else
                        {
                            /* Read clock correction values */
                            returnValue = Fr_HAL_GetClockCorrection(Fr_RateCorrectionPtr, Fr_OffsetCorrectionPtr);

                        }
                    }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
     /* FR_DEV_ERROR_DETECT == STD_ON */
    #endif 
    return returnValue;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"


/***************************************************************************************************
* @function_name    Fr_GetSyncFrameList
*
* @brief            Gets clock correction values
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver.
* @param[in]        Fr_ListSize Size of the arrays passed via parameters:
*                       -Fr_ChannelAEvenListPtr
*                       -Fr_ChannelBEvenListPtr
*                       -Fr_ChannelAOddListPtr 
*                       -Fr_ChannelBOddListPtr
*                   The service must ensure to not write more entries into those arrays than granted 
*                   by this parameter
* @param[out]       Fr_ChannelAEvenListPtr Address the list of syncframes on channel A within the
*                   even communication cycle is written to
* @param[out]       Fr_ChannelBEvenListPtr Address the list of syncframes on channel B within the
*                   even communication cycle is written to
* @param[out]       Fr_ChannelAOddListPtr Address the list of syncframes on channel A within the
*                   odd communication cycle is written to
* @param[out]       Fr_ChannelBOddListPtr Address the list of syncframes on channel B within the
*                   odd communication cycle is written to
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors or Fr_ListSize=0
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_GetSyncFrameList(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_ListSize,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAEvenListPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBEvenListPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAOddListPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBOddListPtr)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg = NULL_PTR;

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx)   
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETSYNCFRAMELIST_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        /* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)    
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETSYNCFRAMELIST_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (Fr_ListSize > 15U)
            {   /* Fr_ListSize is larger than 15, FR_E_INV_FRAMELIST_SIZE shall be reported */
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETSYNCFRAMELIST_U8, FR_E_INV_FRAMELIST_SIZE);
            }
            else
            {
                if (NULL_PTR == Fr_ChannelAEvenListPtr)
                {
                    /* If Fr_ChannelAEvenListPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                    /* to the DET and the API function shall return. */
                     (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETSYNCFRAMELIST_U8, FR_E_PARAM_POINTER);
                }
                else
                {
                    if (NULL_PTR == Fr_ChannelBEvenListPtr)
                    {
                        /* If Fr_ChannelBEvenListPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                        /* to the DET and the API function shall return. */
                         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETSYNCFRAMELIST_U8, FR_E_PARAM_POINTER);
                    }
                    else
                    {
                        if (NULL_PTR == Fr_ChannelAOddListPtr)
                        {
                            /* If Fr_ChannelAOddListPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                            /* to the DET and the API function shall return. */
                             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETSYNCFRAMELIST_U8, FR_E_PARAM_POINTER);
                        }
                        else
                        {
                            if (NULL_PTR == Fr_ChannelBOddListPtr)
                            {
                                /* If Fr_ChannelBOddListPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                                /* to the DET and the API function shall return. */
                                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETSYNCFRAMELIST_U8, FR_E_PARAM_POINTER);
                            }
                            else
                            {
                                if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
                                {
                                     (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETSYNCFRAMELIST_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
                                }
                                else
                                {
    #else
                                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                                {
    /* FR_DEV_ERROR_DETECT */                                
    #endif 

                                    pCtrlCfg = Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx];

                                    if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                                    {
                                        /* CC is not accessible, report error */
                                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                                            Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                        #endif
                                    }
                                    else
                                    {
                                        /* Check Fr_ListSize parameter is higher than 0 */
                                        if (Fr_ListSize > 0U)
                                        {
                                            /* Get list of Sync frames */
                                            if ((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_HAL_GetSyncFrameList(pCtrlCfg, Fr_ListSize, Fr_ChannelAEvenListPtr
                                                                                                                , Fr_ChannelBEvenListPtr, Fr_ChannelAOddListPtr
                                                                                                                , Fr_ChannelBOddListPtr))
                                            {
                                                returnValue = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                                            }
                                            else
                                            {
                                                /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                                                #if (FR_DEM_EVENT_DETECT == STD_ON)
                                                    Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                                #endif
                                                /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                                            }
                                        }
                                        else
                                        {
                                            /* do nothing */
                                        }
                                    }
                                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
                            }
                        }
                    }
                }
            }
        }
    }
    #endif /* FR_DEV_ERROR_DETECT */
    return returnValue;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_GetWakeupRxStatus
*
* @brief            Gets clock correction values
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver.
* @param[out]       Fr_WakeupRxStatusPtr Address where bitcoded wakeup reception status shall be stored
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_GetWakeupRxStatus(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_WakeupRxStatusPtr)
{
    VAR(Std_ReturnType, FR_VAR) retval = E_NOT_OK;

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETWAKEUPRXSTATUS_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {/* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETWAKEUPRXSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_WakeupRxStatusPtr)
            {
                /* If Fr_ChannelAStatusPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                /* to the DET and the API function shall return. */
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETWAKEUPRXSTATUS_U8, FR_E_PARAM_POINTER);
            }
            else
            {
                if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
                {
                     (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETWAKEUPRXSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {            
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */
                    if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                    {
                        /* CC is not accessible, report error */
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else    
                    {
                        retval= Fr_HAL_GetWakeupRxStatus(Fr_WakeupRxStatusPtr);
                    }
                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    /* FR_DEV_ERROR_DETECT == STD_ON */
    #endif  
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/* WARING */

/***************************************************************************************************
* @function_name    Fr_SetAbsoluteTimer
*
* @brief            Sets the absolute FlexRay timer
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx Index of absolute timer within the context of the FlexRay CC
* @param[in]        Fr_Cycle Absolute cycle the timer shall elapse in
* @param[in]        Fr_Offset Offset within cycle Fr_Cycle in units of macrotick the timer shall
*                   elapse at
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_SetAbsoluteTimer(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_AbsTimerIdx,
    VAR(uint8, FR_VAR) Fr_Cycle,
    VAR(uint16, FR_VAR) Fr_Offset)
{
    VAR(Fr_POCStateType, FR_VAR) protocal_state;
    VAR(Std_ReturnType, FR_VAR) retval = E_NOT_OK;

    #if (FR_DEV_ERROR_DETECT == STD_ON) 
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx)
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETABSTIMER_U8, FR_E_INV_CTRL_IDX);
    }
    else
    { /* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)  
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETABSTIMER_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETABSTIMER_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
                    /*[SWS_Fr_00269] Check the Fr_AbsTimerIdx value */
                    if (!(Fr_AbsTimerIdx < Fr_au8AbsoluteTimersNum[Fr_CtrlIdx])) 
                    {   
                        /* An attempt to configure an invalid timer, Fr_AbsTimerIdx has an invalid value */
                        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETABSTIMERIRQSTATUS_U8, FR_E_INV_TIMER_IDX);
                    }
                    else
                    {
                        /* Check the Fr_Cycle value, max. cycle no. 63 */
                        if (Fr_Cycle > 63U) 
                        {   /* An attempt to configure timer for invalid cycle number, Fr_Cycle has an invalid value */
                            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETABSTIMER_U8, FR_E_INV_CYCLE);
                        }
                        else
                        {
                            if (Fr_Offset >= ((VAR(uint16, AUTOMATIC))(Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]->Fr_low_level_config_temp_ptr->G_MACRO_PER_CYCLE)))
                            {   /* An attempt to configure timer for invalid macrotick offset number,
                                Fr_Offset has an invalid value */
                                (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETABSTIMER_U8, FR_E_INV_OFFSET);
                            }
                            else if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                            {
                                /* CC is not accessible, report error */
                                #if (FR_DEM_EVENT_DETECT == STD_ON)
                                Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                #endif
                            }
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
                    if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                    {
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
    #endif
                    else
                    {
                        protocal_state = Fr_HAL_Get_POC_State();
                        if((protocal_state != FR_POCSTATE_NORMAL_ACTIVE)&&(protocal_state != FR_POCSTATE_NORMAL_PASSIVE))
                        {
                            #if (FR_DEM_EVENT_DETECT == STD_ON)
                            Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                        else
                        {
                        retval = Fr_HAL_SetAbsTimers(Fr_AbsTimerIdx,Fr_Cycle,Fr_Offset);
                        }
                    }
                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
                    }
                }
            }
        }
    }
    /* FR_DEV_ERROR_DETECT */
    #endif
    return retval;

}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_CancelAbsoluteTimer
*
* @brief            Stops an absolute timer
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx Index of absolute timer within the context of the FlexRay CC
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_CancelAbsoluteTimer(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_AbsTimerIdx)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    
    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    /*[SWS_Fr_00284] Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx)
    {   
        /* An attempt to configure unsupported CC,Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CANCELABSTIMER_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        /*[SWS_Fr_00283] Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {  
             /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CANCELABSTIMER_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            /*[SWS_Fr_00285]  Check the Fr_AbsTimerIdx value */
            if (!(Fr_AbsTimerIdx < Fr_au8AbsoluteTimersNum[Fr_CtrlIdx])) 
            {   /* An attempt to configure an invalid timer, Fr_AbsTimerIdx has an invalid value */
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CANCELABSTIMER_U8, FR_E_INV_TIMER_IDX);
            }
            else    /* No error yet -> execute the following code */
            {
                if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]) /* polyspace RTE:IDP */
                {
                    (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CANCELABSTIMER_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
    /* FR_DEV_ERROR_DETECT */                
    #endif 
   
                    if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                    {
                        /*[SWS_Fr_00286] CC is not accessible, report error */
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else    
                    {
                        if((Fr_AbsTimerIdx != (uint8)FR_TIMER_T1)&&(Fr_AbsTimerIdx != (uint8)FR_TIMER_T2))
                        {
                            retval = E_NOT_OK;
                        }
                        else
                        {
                            Fr_HAL_CancelAbsTimer(Fr_AbsTimerIdx);
                            retval = E_OK;
                        }
                    }
                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    /* FR_DEV_ERROR_DETECT */
    #endif 
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_EnableAbsoluteTimerIRQ
*
* @brief            Enables absolute timer interrupts
* @details          [FR298]: Enable the interrupt line related to timer Fr_AbsTimerIdx
* @param[in]        Fr_CtrlIdx      Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx  Index of absolute timer within the context of the FlexRay C
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_EnableAbsoluteTimerIRQ_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_EnableAbsoluteTimerIRQ(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_AbsTimerIdx)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);

     #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    /*[SWS_Fr_00295] Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx)                 
    {   
        /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ENABLEABSTIMERIRQ_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        /*[SWS_Fr_00294] Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)      
        {   
            /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ENABLEABSTIMERIRQ_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (!(Fr_AbsTimerIdx < Fr_au8AbsoluteTimersNum[Fr_CtrlIdx]))/*[SWS_Fr_00296]  Check the Fr_AbsTimerIdx value */
            {   
                /* An attempt to configure an invalid timer, Fr_AbsTimerIdx has an invalid value */
                (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ENABLEABSTIMERIRQ_U8, FR_E_INV_TIMER_IDX);
            }
            else
            {
                if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]) /* polyspace RTE:IDP */
                {
                     (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ENABLEABSTIMERIRQ_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
    /* FR_DEV_ERROR_DETECT */                
    #endif 
                    if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                    {
                        /*[SWS_Fr_00297] CC is not accessible, report error */
                         #if (FR_DEM_EVENT_DETECT == STD_ON)
                             Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else    
                    {
                    
                        if((Fr_AbsTimerIdx != (uint8)FR_TIMER_T1)&&(Fr_AbsTimerIdx != (uint8)FR_TIMER_T2))
                        {
                            retval = E_NOT_OK;
                        }
                        else
                        {
                            if(E_OK == Fr_HAL_EnableAbsoluteTimerIRQ(Fr_AbsTimerIdx))
                            {
                                retval = E_OK;
                            }
                            else
                            {
                                /*return not ok ,no such timer*/
                            }  
                        }
                    }
                }
 #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif /* FR_DEV_ERROR_DETECT */    
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_DisableAbsoluteTimerIRQ
*
* @brief            Disables absolute timer interrupt generation
* @param[in]        Fr_CtrlIdx - Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx - Index of absolute timer within the context of the FlexRay CC
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_DisableAbsoluteTimerIRQ(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_AbsTimerIdx)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = (VAR(Std_ReturnType, AUTOMATIC)) (E_NOT_OK);

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    /* [SWS_Fr_00317] Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_DISABLEABSTIMERIRQ_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {/* [SWS_Fr_00316] Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_DISABLEABSTIMERIRQ_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {/* [SWS_Fr_00318] Check the Fr_AbsTimerIdx value */
            if (!(Fr_AbsTimerIdx < Fr_au8AbsoluteTimersNum[Fr_CtrlIdx])) 
            {   /* An attempt to configure an invalid timer, Fr_AbsTimerIdx has an invalid value */
                (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_DISABLEABSTIMERIRQ_U8, FR_E_INV_TIMER_IDX);
            }
            else
            {
                if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]) /* polyspace RTE:IDP */
                {
                    (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_DISABLEABSTIMERIRQ_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {   
    /* FR_DEV_ERROR_DETECT */    
    #endif 
                    if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                    {
                        /* [SWS_Fr_00319] CC is not accessible, report error */
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else    
                    {
                    
                        if((Fr_AbsTimerIdx != (uint8)FR_TIMER_T1)&&(Fr_AbsTimerIdx != (uint8)FR_TIMER_T2))
                        {
                            retval = E_NOT_OK;
                        }
                        else
                        {
                            if(E_OK == Fr_HAL_DisableAbsoluteTimerIRQ(Fr_AbsTimerIdx))
                            {
                                retval = E_OK;
                            }
                            else
                            {
                                /*return not ok ,no such timer*/
                            }  
                            
                        }
                    }
                }
        #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif /* FR_DEV_ERROR_DETECT */
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_AckAbsoluteTimerIRQ
*
* @brief            Clears absolute timer interrupt flag
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx Index of absolute timer within the context of the FlexRay CC
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_AckAbsoluteTimerIRQ(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_AbsTimerIdx)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);

 #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    /*[SWS_Fr_00306] Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   
        /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ACKABSTIMERIRQ_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        /*[SWS_Fr_00305] Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ACKABSTIMERIRQ_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            /*[SWS_Fr_00307] Check the Fr_AbsTimerIdx value */
            if (!(Fr_AbsTimerIdx < Fr_au8AbsoluteTimersNum[Fr_CtrlIdx])) 
            {   /* An attempt to configure an invalid timer, Fr_AbsTimerIdx has an invalid value */
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ACKABSTIMERIRQ_U8, FR_E_INV_TIMER_IDX);
            }
            else
            {
                if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]) /* polyspace RTE:IDP */
                {
                    (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ACKABSTIMERIRQ_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
    /* FR_DEV_ERROR_DETECT */       
    #endif 

                    if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                    {
                        /* [SWS_Fr_00308] CC is not accessible, report error */
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else    
                    {
                    
                        if((Fr_AbsTimerIdx != (uint8)FR_TIMER_T1)&&(Fr_AbsTimerIdx != (uint8)FR_TIMER_T2))
                        {
                            retval = E_NOT_OK;
                        }
                        else
                        {
                            Fr_HAL_AckAbsTimerIRQ(Fr_AbsTimerIdx);
                            retval = E_OK;  
                        }
                    }
                }
    
        #if (FR_DEV_ERROR_DETECT == STD_ON)
           }
        }
    }
    /* FR_DEV_ERROR_DETECT */
    #endif 
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_GetAbsoluteTimerIRQStatus
*
* @brief            Checks if the absolute timer flag is set
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx Index of absolute timer within the context of the FlexRay CC
* @param[out]       Fr_IRQStatusPtr Address the output value is stored to
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_GetAbsoluteTimerIRQStatus(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_AbsTimerIdx,
    P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) Fr_IRQStatusPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) retval = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
  
    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    /*[SWS_Fr_00328] Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETABSTIMERIRQSTATUS_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        /*[SWS_Fr_00327] Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETABSTIMERIRQSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            /*[SWS_Fr_00329] Check the Fr_AbsTimerIdx value */
            if (!(Fr_AbsTimerIdx < Fr_au8AbsoluteTimersNum[Fr_CtrlIdx])) 
            {   /* An attempt to configure an invalid timer, Fr_AbsTimerIdx has an invalid value */
                (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETABSTIMERIRQSTATUS_U8, FR_E_INV_TIMER_IDX);
            }
            else
            {
                /*[SWS_Fr_00330]*/
                if (NULL_PTR == Fr_IRQStatusPtr)
                {
                    /* If Fr_IRQStatusPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
                    /* to the DET and the API function shall return. */
                    (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETABSTIMERIRQSTATUS_U8, FR_E_PARAM_POINTER);
                }
                /* No error yet -> execute the following code */
                else    
                {
                    if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]) /* polyspace RTE:IDP */
                    {
                         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETABSTIMERIRQSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_POINTER);
                    }
                    else
                    {
    #else
                    if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                    {
    /* FR_DEV_ERROR_DETECT */
    #endif 
                        if(E_NOT_OK == Fr_HAL_CheckCCAccess())
                        {
                            /* CC is not accessible, report error */
                            #if (FR_DEM_EVENT_DETECT == STD_ON)
                            /*[SWS_Fr_00331]*/
                            Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                        else    
                        {
                            if((Fr_AbsTimerIdx != (uint8)FR_TIMER_T1)&&(Fr_AbsTimerIdx != (uint8)FR_TIMER_T2))
                            {
                                retval = E_NOT_OK;
                            }
                            else
                            {
                                *Fr_IRQStatusPtr = Fr_HAL_GetAbsoluteTimerIRQStatus(Fr_AbsTimerIdx);
                                retval = E_OK;
                            }
                        }
                    }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
    /* FR_DEV_ERROR_DETECT */
    #endif 
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_InterruptEnable(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_InterruptSource)
{
    VAR(Std_ReturnType, AUTOMATIC) ret = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_STARTCOMMUNICATION_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        /* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_STARTCOMMUNICATION_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_STARTCOMMUNICATION_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
    /* FR_DEV_ERROR_DETECT == STD_ON */
    #endif 

                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
                    if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
                    {
                        /* CC is not accessible, report error */

                    }

                    else
                    {
                        if(Fr_InterruptSource != ((VAR(uint16, AUTOMATIC))0))
                        {
                            Fr_HAL_InterruptEnable(Fr_InterruptSource);
                            ret = E_OK;
                        }
                    }
                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    /* FR_DEV_ERROR_DETECT */
    #endif 

    return ret;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_InterruptDisable(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_InterruptSource)
{
    VAR(Std_ReturnType, AUTOMATIC) ret = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);

    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_STARTCOMMUNICATION_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        /* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)   
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_STARTCOMMUNICATION_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
            {
                 (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_STARTCOMMUNICATION_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
            }
            else
            {
   /* FR_DEV_ERROR_DETECT == STD_ON */             
    #endif  

    if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
    {
        if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_CheckCCAccess())
        {
            /* CC is not accessible, report error */

        }

        else
        {
            if(Fr_InterruptSource != ((VAR(uint16, AUTOMATIC))0))
            {
                Fr_HAL_InterruptDisable(Fr_InterruptSource);
                ret = E_OK;
            }
        }
    }

    #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    /* FR_DEV_ERROR_DETECT */
    #endif 

    return ret;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#if (FR_VERSION_INFO_API == STD_ON)
/***************************************************************************************************
 * @function_name    Fr_GetVersionInfo
 *
 * @brief            Software module version query
 *                   of this module
 * @param[out]       VersioninfoPtr Pointer to where to store the version information of this module
 * @return           none
 ***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, FR_APPL_DATA) VersioninfoPtr
    )
{
#if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    /*[SWS_Fr_00340]*/
    if (NULL_PTR == VersioninfoPtr)
    {
        /* If VersioninfoPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETVERSIONINFO_U8, FR_E_PARAM_POINTER);
    }
    /* No error yet -> execute the following code */
    else 
    {
         /* FR_DEV_ERROR_DETECT */
#endif
        VersioninfoPtr->moduleID = (VAR(uint16, AUTOMATIC))FR_MODULE_ID_C;
        VersioninfoPtr->vendorID = (VAR(uint16, AUTOMATIC))FR_VENDOR_ID_C;
        VersioninfoPtr->sw_major_version = (VAR(uint8, AUTOMATIC))FR_SW_MAJOR_VERSION_C;
        VersioninfoPtr->sw_minor_version = (VAR(uint8, AUTOMATIC))FR_SW_MINOR_VERSION_C;
        VersioninfoPtr->sw_patch_version = (VAR(uint8, AUTOMATIC))FR_SW_PATCH_VERSION_C;
#if (FR_DEV_ERROR_DETECT == STD_ON)
    }
    /* FR_DEV_ERROR_DETECT */
#endif 
    return;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif /* FR_VERSION_INFO_API == STD_ON */

/***************************************************************************************************
* @function_name    Fr_ReadCCConfig
*
* @brief            Reconfigures physical resource
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_ConfigParamIdx Index that identifies the configuration parameter to read. 
*                   See macros FR_CIDX_<config_parameter_name>.
* @param[out]       Fr_ConfigParamValuePtr Address the output value is stored to.
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_ReadCCConfig(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_ConfigParamIdx,
    P2VAR(uint32, AUTOMATIC, FR_APPL_DATA) Fr_ConfigParamValuePtr)
{
    VAR(Std_ReturnType, FR_VAR) retval = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK;
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg = NULL_PTR;
    P2CONST(Fr_low_level_config_type, AUTOMATIC, FR_APPL_CONST) Fr_temp_ptr;
    #if (FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    /* [SWS_Fr_00654] Check the Fr_CtrlIdx value */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) 
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_READCCCONFIG_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_INIT != Fr_eDriverStates)   /* [SWS_Fr_00653] Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_READCCCONFIG_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        }
        else
        {
            /*[SWS_Fr_00656] */
            if (Fr_ConfigParamValuePtr == NULL_PTR)    
            {
                /* Fr_ConfigParamValuePtr has an invalid value */
                (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_READCCCONFIG_U8, FR_E_PARAM_POINTER);
            }
            else
            {
                if (NULL_PTR == Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx])/* polyspace RTE:IDP */
                {
                    (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_READCCCONFIG_U8, (VAR(uint8, AUTOMATIC))FR_E_PARAM_CONFIG);
                }
                else
                {
    
    #else
                if (( NULL_PTR != Fr_pInternalCfg) && (NULL_PTR != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]))
                {
               
    /* FR_DEV_ERROR_DETECT */     
    #endif 

                    pCtrlCfg = Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx];
                    Fr_temp_ptr = pCtrlCfg->Fr_low_level_config_temp_ptr;
                    if ((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_HAL_ReadCCConfig(Fr_temp_ptr))
                    {   /*[SWS_Fr_00652] CC contains error in the configuration */
                        #if (FR_DEM_EVENT_DETECT == STD_ON)
                        Fr_Dem_SetEventStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else
                    {
                        retval = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                        switch (Fr_ConfigParamIdx)
                        {

                        case FR_CIDX_GDCYCLE:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))((Fr_temp_ptr->P_MICRO_PER_CYCLE) * 25U);
                            break;
                        case FR_CIDX_PMICROPERCYCLE:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_MICRO_PER_CYCLE;
                            break;
                        case FR_CIDX_PDLISTENTIMEOUT:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->PD_LISTEN_TIMEOUT;
                            break;
                        case FR_CIDX_GMACROPERCYCLE:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_MACRO_PER_CYCLE;
                            break;
                        case FR_CIDX_GDMACROTICK:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))(((Fr_temp_ptr->P_MICRO_PER_CYCLE) * 25U) /1000U / /* polyspace RTE:ZDV */
                                                            (Fr_temp_ptr->G_MACRO_PER_CYCLE));
                            break;
                        case FR_CIDX_GNUMBEROFMINISLOTS:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_NUMBER_OF_MINISLOTS;
                            break;
                        case FR_CIDX_GNUMBEROFSTATICSLOTS:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_NUMBER_OF_STATIC_SLOTS;
                            break;
                        /* gMacroPerCycle[MT] = gdStaticSlot[MT] * gNumberOfStaticSlots + adActionPointDifference[MT] +
                            gdMinislot[MT] * gNumberOfMinislots + gdSymbolWindow[MT] + gdNIT[MT] */    
                        case FR_CIDX_GDNIT: 
                            if ((Fr_temp_ptr->GD_ACTION_POINT_OFFSET) <= (Fr_temp_ptr->GD_MINI_SLOT_ACTION_POINT_OFFSET) || (VAR(uint16_t, AUTOMATIC))0x0000 == (Fr_temp_ptr->G_NUMBER_OF_MINISLOTS))
                            {
                                *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))((VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_MACRO_PER_CYCLE - (VAR(uint32, AUTOMATIC))(Fr_temp_ptr->GD_STATIC_SLOT) * (VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_NUMBER_OF_STATIC_SLOTS - (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_SYMBOL_WINDOW - (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_MINISLOT * (VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_NUMBER_OF_MINISLOTS);
                            }
                            else if((Fr_temp_ptr->GD_ACTION_POINT_OFFSET) > (Fr_temp_ptr->GD_MINI_SLOT_ACTION_POINT_OFFSET) )
                            {
                                *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))((VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_MACRO_PER_CYCLE - ((VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_ACTION_POINT_OFFSET - (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_MINI_SLOT_ACTION_POINT_OFFSET) - (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_STATIC_SLOT * (VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_NUMBER_OF_STATIC_SLOTS - (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_SYMBOL_WINDOW - (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_MINISLOT * (VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_NUMBER_OF_MINISLOTS);
                            }
                            else
                            {
                                retval = E_NOT_OK;
                            }
                            break;
                        case FR_CIDX_GDSTATICSLOT:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_STATIC_SLOT;
                            break;
                        case FR_CIDX_GDWAKEUPRXWINDOW:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_WAKEUP_SYMBOL_RX_WINDOW;
                            break;
                        case FR_CIDX_PKEYSLOTID:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_KEY_SLOT_ID;
                            break;
                        case FR_CIDX_PLATESTTX:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_LATEST_TX;
                            break;
                        case FR_CIDX_POFFSETCORRECTIONOUT:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_OFFSET_CORRECTION_OUT;
                            break;
                        case FR_CIDX_POFFSETCORRECTIONSTART:
                            /*Remark: This parameter maps to FlexRay Protocol 2.1 Rev. A parametergOffsetCorrectionStart.*/
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_OFFSET_CORRECTION_START;
                            break;
                        case FR_CIDX_PRATECORRECTIONOUT:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_RATE_CORRECTION_OUT;
                            break;
                        case FR_CIDX_PSECONDKEYSLOTID:
                            /* Remark: Set to 0 for FlexRay Protocol 2.1 Rev. A compliance. */
                            *Fr_ConfigParamValuePtr = 0x00000000U;
                            break;
                        case FR_CIDX_PDACCEPTEDSTARTUPRANGE:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->PD_ACCEPTED_STARTUP_RANGE;
                            break;
                        case FR_CIDX_GCOLDSTARTATTEMPTS:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_COLD_START_ATTEMPTS;
                            break;
                        case FR_CIDX_GCYCLECOUNTMAX:
                            /* Remark: Set to 63 for FlexRay Protocol 2.1 Rev. A compliance. */
                            *Fr_ConfigParamValuePtr = 63U;
                            break;
                        case FR_CIDX_GLISTENNOISE:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_LISTEN_NOISE;
                            break;
                        case FR_CIDX_GMAXWITHOUTCLOCKCORRECTFATAL:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_MAX_WITHOUT_CLOCK_CORRECTION_FATAL;
                            break;
                        case FR_CIDX_GMAXWITHOUTCLOCKCORRECTPASSIVE:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_MAX_WITHOUT_CLOCK_CORRECTION_PASSIVE;
                            break;
                        case FR_CIDX_GNETWORKMANAGEMENTVECTORLENGTH:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_NETWORK_MANAGEMENT_VECTOR_LENGTH;
                            break;
                        case FR_CIDX_GPAYLOADLENGTHSTATIC:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_PAYLOAD_LENGTH_STATIC;
                            break;
                        case FR_CIDX_GSYNCFRAMEIDCOUNTMAX:
                            /*This parameter maps to FlexRay Protocol 2.1 Rev. A parameter gSyncNodeMax.*/
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->G_SYNC_NODE_MAX;
                            break;
                        case FR_CIDX_GDACTIONPOINTOFFSET:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_ACTION_POINT_OFFSET;
                            break;
                        case FR_CIDX_GDBIT:
                            if ((VAR(uint8_t, AUTOMATIC))0U == pCtrlCfg->Fr_HW_config_temp_ptr->prescaler_value)
                            {
                                *Fr_ConfigParamValuePtr = 100U;
                            }
                            /*The bit rate of 8 Mbit/s is not defined by the FlexRay Communications System Protocol Specification, Version 2.1 Rev A.*/

                            else if ((VAR(uint8_t, AUTOMATIC))1U == pCtrlCfg->Fr_HW_config_temp_ptr->prescaler_value)
                            {
                                *Fr_ConfigParamValuePtr = 200U;
                            }
                            else if ((VAR(uint8_t, AUTOMATIC))2U == pCtrlCfg->Fr_HW_config_temp_ptr->prescaler_value)
                            {
                                *Fr_ConfigParamValuePtr = 400U;
                            }
                            else
                            {
                                retval = E_NOT_OK;
                            }
                            break;
                        case FR_CIDX_GDCASRXLOWMAX:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_CAS_RX_LOW_MAX;
                            break;
                        case FR_CIDX_GDDYNAMICSLOTIDLEPHASE:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_DYNAMIC_SLOT_IDLE_PHASE;
                            break;
                        case FR_CIDX_GDMINISLOTACTIONPOINTOFFSET:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_MINI_SLOT_ACTION_POINT_OFFSET;
                            break;
                        case FR_CIDX_GDMINISLOT:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_MINISLOT;
                            break;
                        case FR_CIDX_GDSAMPLECLOCKPERIOD:
                            if ((VAR(uint8, AUTOMATIC))0U == pCtrlCfg->Fr_HW_config_temp_ptr->prescaler_value)
                            {
                                *Fr_ConfigParamValuePtr = 0x00000000U;/*T12_5NS*/
                            }
                            /*The bit rate of 8 Mbit/s is not defined by the FlexRay Communications System Protocol Specification, Version 2.1 Rev A.*/

                            else if ((VAR(uint8, AUTOMATIC))1U == pCtrlCfg->Fr_HW_config_temp_ptr->prescaler_value)
                            {
                                *Fr_ConfigParamValuePtr = 0x00000001U;/*T25NS*/
                            }
                            else if ((VAR(uint8, AUTOMATIC))2U == pCtrlCfg->Fr_HW_config_temp_ptr->prescaler_value)
                            {
                                *Fr_ConfigParamValuePtr = 0x00000002U;/*T50NS*/
                            }
                            else
                            {
                                retval = E_NOT_OK;
                            }
                            break;
                        case FR_CIDX_GDSYMBOLWINDOW:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_SYMBOL_WINDOW;
                            break;
                        case FR_CIDX_GDSYMBOLWINDOWACTIONPOINTOFFSET:
                            /*Set to GdActionPointOffset for FlexRay Protocol 2.1 Rev. A compliance.*/
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_ACTION_POINT_OFFSET;
                            break;
                        case FR_CIDX_GDTSSTRANSMITTER:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_TSS_TRANSMITTER;
                            break;
                        case FR_CIDX_GDWAKEUPRXIDLE:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_WAKEUP_SYMBOL_RX_IDLE;
                            break;
                        case FR_CIDX_GDWAKEUPRXLOW:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_WAKEUP_SYMBOL_RX_LOW;
                            break;
                        case FR_CIDX_GDWAKEUPTXACTIVE:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_WAKEUP_SYMBOL_TX_LOW;
                            break;
                        case FR_CIDX_GDWAKEUPTXIDLE:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->GD_WAKEUP_SYMBOL_TX_IDLE;
                            break;
                        case FR_CIDX_PALLOWPASSIVETOACTIVE:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_ALLOW_PASSIVE_TO_ACTIVE;
                            break;
                        case FR_CIDX_PCHANNELS:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_CHANNELS;
                            break;
                        case FR_CIDX_PCLUSTERDRIFTDAMPING:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_CLUSTER_DRIFT_DAMPING;
                            break;
                        case FR_CIDX_PDECODINGCORRECTION:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_DECODING_CORRECTION;
                            break;
                        case FR_CIDX_PDELAYCOMPENSATIONA:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_DELAY_COMPENSATION_CHA;
                            break;
                        case FR_CIDX_PDELAYCOMPENSATIONB:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_DELAY_COMPENSATION_CHB;
                            break;
                        case FR_CIDX_PMACROINITIALOFFSETA:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_MACRO_INITIAL_OFFSET_A;
                            break;
                        case FR_CIDX_PMACROINITIALOFFSETB:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_MACRO_INITIAL_OFFSET_B;
                            break;
                        case FR_CIDX_PMICROINITIALOFFSETA:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_MICRO_INITIAL_OFFSET_A;
                            break;
                        case FR_CIDX_PMICROINITIALOFFSETB:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_MICRO_INITIAL_OFFSET_B;
                            break;
                        case FR_CIDX_PPAYLOADLENGTHDYNMAX:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_PAYLOAD_LENGTH_DYN_MAX;
                            break;
                        case FR_CIDX_PSAMPLESPERMICROTICK:
                            if ((VAR(uint8_t, AUTOMATIC))0U == pCtrlCfg->Fr_HW_config_temp_ptr->prescaler_value)
                            {/*N2SAMPLES*/
                                *Fr_ConfigParamValuePtr = 0x00000001u;
                            }
                            /*The bit rate of 8 Mbit/s is not defined by the FlexRay Communications System Protocol Specification, Version 2.1 Rev A.*/

                            else if ((VAR(uint8_t, AUTOMATIC))1U == pCtrlCfg->Fr_HW_config_temp_ptr->prescaler_value)
                            {/*N1SAMPLES*/
                                *Fr_ConfigParamValuePtr = 0x00000000u;
                            }
                            else if ((VAR(uint8_t, AUTOMATIC))2U == pCtrlCfg->Fr_HW_config_temp_ptr->prescaler_value)
                            {/*N1SAMPLES*/
                                *Fr_ConfigParamValuePtr = 0x00000000u;
                            }
                            else
                            {
                                retval = E_NOT_OK;
                            }
                            break;
                        case FR_CIDX_PWAKEUPCHANNEL:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_WAKEUP_CHANNEL;
                            break;
                        case FR_CIDX_PWAKEUPPATTERN:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_WAKEUP_PATTERN;
                            break;
                        case FR_CIDX_PDMICROTICK:
                            if ((VAR(uint8_t, AUTOMATIC))0U == pCtrlCfg->Fr_HW_config_temp_ptr->prescaler_value)
                            {/*T25NS*/
                                *Fr_ConfigParamValuePtr = 0x00000001u;
                            }
                            /*The bit rate of 8 Mbit/s is not defined by the FlexRay Communications System Protocol Specification, Version 2.1 Rev A.*/

                            else if ((VAR(uint8_t, AUTOMATIC))1U == pCtrlCfg->Fr_HW_config_temp_ptr->prescaler_value)
                            {/*T25NS*/
                                *Fr_ConfigParamValuePtr = 0x00000001u;
                            }
                            else if ((VAR(uint8_t, AUTOMATIC))2U == pCtrlCfg->Fr_HW_config_temp_ptr->prescaler_value)
                            {/*T50NS*/
                                *Fr_ConfigParamValuePtr = 0x00000002u;
                            }
                            else
                            {
                                retval = E_NOT_OK;
                            }
                            break;
                        case FR_CIDX_GDIGNOREAFTERTX:
                            /* Remark: Set to 0 for FlexRay Protocol 2.1 Rev. A compliance. */
                            *Fr_ConfigParamValuePtr = 0x00000000U;
                            break;
                        case FR_CIDX_PALLOWHALTDUETOCLOCK:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_ALLOW_HALT_DUE_TO_CLOCK;
                            break;
                        case FR_CIDX_PEXTERNALSYNC:
                            /* Remark: Set to false for FlexRay Protocol 2.1 Rev A compliance. */
                            *Fr_ConfigParamValuePtr = FALSE;
                            break;
                        case FR_CIDX_PFALLBACKINTERNAL:
                            /* Remark: Set to false for FlexRay Protocol 2.1 Rev A compliance. */
                            *Fr_ConfigParamValuePtr = FALSE;
                            break;
                        case FR_CIDX_PKEYSLOTONLYENABLED:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_SINGLE_SLOT_ENABLED;
                            break;
                        case FR_CIDX_PKEYSLOTUSEDFORSTARTUP:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_KEY_SLOT_USED_FOR_STARTUP;
                            break;
                        case FR_CIDX_PKEYSLOTUSEDFORSYNC:
                            *Fr_ConfigParamValuePtr = (VAR(uint32, AUTOMATIC))Fr_temp_ptr->P_KEY_SLOT_USED_FOR_SYNC;
                            break;
                        case FR_CIDX_PNMVECTOREARLYUPDATE:
                            /* Remark: Set to false for FlexRay Protocol 2.1 Rev A compliance. */
                            *Fr_ConfigParamValuePtr = FALSE;
                            break;
                        case FR_CIDX_PTWOKEYSLOTMODE:
                            /* Remark: Set to false for FlexRay Protocol 2.1 Rev A compliance. */
                            *Fr_ConfigParamValuePtr = FALSE;
                            break;
                        default:
                        /*[SWS_Fr_00655]*/
                            #if (FR_DEV_ERROR_DETECT == STD_ON)
                            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_READCCCONFIG_U8, (VAR(uint8, AUTOMATIC))FR_E_INV_CONFIG_IDX);
                           /* FR_DEV_ERROR_DETECT */
                            #endif 
                            retval = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
                            break;
                        }
                    }
                }
    #if (FR_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
     /* FR_DEV_ERROR_DETECT */
    #endif
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_Disable_AllInterrupts
* Description:      Thi API call disables an interrupt in the GIFER, PIER0 and PIER1 registers. 
*                   An user may put combinated defined macros into input parametrs. 
*                   If Fr_global_interrupt input parameter is zero, 
*                   this function will not update the GIFER register,
*                   otherwise the GIFER register will be updated.
*                   If Fr_protocol_0_interrupt parameter is zero, this function will not update the PIER0 
*                   register, otherwise the PIER0 register will be updated.
*                   If Fr_protocol_1_interrupt parameter is zero, this function will not update the PIER1 
*                   register, otherwise the PIER1 register will be updated.
*
* Function arguments: 
*                   Fr_global_interrupt          The name of interrupt in the GIFER reg.
*                   Fr_protocol_0_interrupt      The name of interrupt in the PIFR0 reg.
*                   Fr_protocol_1_interrupt         The name of interrupt in the PIFR1 reg.
* Return value:
*                   none     
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_Disable_AllInterrupts(void)
{
    
    Fr_HAL_Disable_AllInterrupts();
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"


#if (FR_RECONFIG_LPDU_SUPPORT == STD_ON)
#if (FR_DEV_ERROR_DETECT == STD_ON)
/***************************************************************************************************
* @function_name    FR_ValidateReconfigLPDU
*
* @brief            This function validates parameter.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame
* @param[in]        Fr_FrameId FlexRay Frame ID the FrIf_LPdu shall be configured to
* @param[in]        Fr_ChnlIdx FlexRay Channel the FrIf_LPdu shall be configured to
* @param[in]        Fr_CycleRepetition Cycle Repetition part of the cycle filter mechanism
*                                      FrIf_LPdu shall be configured to.
* @param[in]        Fr_CycleOffset Cycle Offset part of the cycle filter mechanism FrIf_LPdu shall
*                                  be configured to.
* @param[in]        Fr_PayloadLength Payloadlength in units of bytes the FrIf_LPduIdx shall be
*                                    configured to.
* @param[in]        Fr_HeaderCRC Header CRC the FrIf_LPdu shall be configured to.
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
static FUNC(Std_ReturnType, FR_CODE) FR_ValidateReconfigLPDU( VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint16, AUTOMATIC) Fr_LPduIdx,
                                                              VAR(uint16, AUTOMATIC) Fr_FrameId, VAR(Fr_ChannelType, AUTOMATIC) Fr_ChnlIdx,
                                                              VAR(uint8, AUTOMATIC) Fr_CycleRepetition, VAR(uint8, AUTOMATIC) Fr_CycleOffset,
                                                              VAR(uint8, AUTOMATIC) Fr_PayloadLength, VAR(uint16, AUTOMATIC) Fr_HeaderCRC
                                                            )
{
    VAR(Std_ReturnType, AUTOMATIC) retval = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);

 /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if (FR_NUM_CTRL_SUPPORTED <= Fr_CtrlIdx) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECONFIGLPDU_U8, FR_E_INV_CTRL_IDX);
    }
    else
    {
         /* Check the initialization status */
        if (FR_INIT != Fr_eDriverStates)  
        {   /* The Fr was not initialized successfully prior to this API function call */
             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_RECONFIGLPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED); /* Report error */
        }
        else
        {
            if ((FR_CHANNEL_AB != Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]->Fr_low_level_config_temp_ptr->P_CHANNELS) && (Fr_MB_information_internal[Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]->Fr_buffers_config_temp_ptr[Fr_LPduIdx].buffer_index_init].Mb_channel_type != Fr_ChnlIdx)) /* polyspace RTE:OBAI,IDP */
            {
                (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECONFIGLPDU_U8, FR_E_INV_CHNL_IDX);
            }
            else
            {
                if ((Fr_CycleRepetition != 1U) && (Fr_CycleRepetition != 2U)  && (Fr_CycleRepetition != 4U)\
                                                && (Fr_CycleRepetition != 8U)  && (Fr_CycleRepetition != 16U)\
                                                && (Fr_CycleRepetition != 32U) && (Fr_CycleRepetition != 64U)\
                )
                {
                    /* Fr_CycleRepetition has an invalid value */
                     (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECONFIGLPDU_U8, FR_E_INV_CYCLE);
                }
                else
                {
                    if (Fr_CycleOffset > (Fr_CycleRepetition - 1U))
                    {
                        /* Fr_CycleOffset has an invalid value */
                         (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECONFIGLPDU_U8, FR_E_INV_CYCLE);
                    }
                    else
                    {
                        if (Fr_HeaderCRC > 2047U)
                        {
                            /* Fr_HeaderCRC has an invalid value for static segment */
                             (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECONFIGLPDU_U8, FR_E_INV_HEADERCRC);
                        }
                        else
                        {
                            if(Fr_LPduIdx >Lpduidx_Max)
                            {
                                /* Fr_LPduIdx has an invalid value */
                                (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECONFIGLPDU_U8, FR_E_INV_LPDU_IDX);
                            }
                            else
                            {
                                if((Fr_FrameId <= Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]->Fr_low_level_config_temp_ptr->G_NUMBER_OF_STATIC_SLOTS)
                                && (Fr_PayloadLength != (Fr_pInternalCfg->Fr_pController[Fr_CtrlIdx]->Fr_low_level_config_temp_ptr->G_PAYLOAD_LENGTH_STATIC*2U)))
                                {
                                    /* Fr_PayloadLength has an invalid value for static segment */
                                    (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECONFIGLPDU_U8, FR_E_INV_LENGTH);
                                }
                                else
                                {
                                    retval = E_OK;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif
#endif

#endif /* RESOURCE_SUPPORT_FLEXRAY */

#ifdef __cplusplus
}
#endif
/* End of file */

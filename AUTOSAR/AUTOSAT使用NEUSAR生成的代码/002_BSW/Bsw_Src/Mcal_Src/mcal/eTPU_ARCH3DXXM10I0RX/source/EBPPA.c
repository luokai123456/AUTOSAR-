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
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    EBPPA.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of EBPPA CDD driver.
*
*   @addtogroup EBPPA
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
/* PRQA S 0380,3432,2844,1006,0491,3408,1533,0686,4391,4399,4499 EOF */
#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "eTPU_Cfg.h" 
#if ((EBPPA_INSTANCE_NUM != 0U)&&(EBPPA_MODULE_ENABLE !=STD_OFF))
#include "EBPPA.h"
#include "eDma_LLDriver.h"
#include "Gpt_Stm_LLDriver.h"
#include "sPwm_LLDrivers.h"
#if (EBPPA_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define EBPPA_VENDOR_ID_C                   176

#define EBPPA_MAJOR_VER_C                   4
#define EBPPA_MINOR_VER_C                   4
#define EBPPA_REVISION_VER_C                0

#define EBPPA_SW_MAJOR_VER_C                3
#define EBPPA_SW_MINOR_VER_C                0
#define EBPPA_SW_PATCH_VER_C                0

#if (EBPPA_VENDOR_ID_C != ETPU_VENDOR_ID_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_VENDOR_ID_C"
#endif

/* Check if current file and EBPPA header file are of the same Autosar version */
#if (EBPPA_MAJOR_VER_C != ETPU_AR_REL_MAJOR_VER_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_MAJOR_VER_C"
#endif
#if (EBPPA_MINOR_VER_C != ETPU_AR_REL_MINOR_VER_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_MINOR_VER_C"
#endif
#if (EBPPA_REVISION_VER_C != ETPU_AR_REL_REVISION_VER_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_REVISION_VER_C"
#endif

/* Check if current file and EBPPA header file are of the same Software version */
#if (EBPPA_SW_MAJOR_VER_C != ETPU_SW_MAJOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_SW_MAJOR_VER_C"
#endif
#if (EBPPA_SW_MINOR_VER_C != ETPU_SW_MINOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_SW_MINOR_VER_C"
#endif
#if (EBPPA_SW_PATCH_VER_C != ETPU_SW_PATCH_VERSION_OUTPUT)
#error "NON-MATCHED DATA : EBPPA_SW_PATCH_VER_C"
#endif

/*==================================================================================================
*                                      EXTERN VARIABLES
==================================================================================================*/
#define ETPU_START_SEC_VAR_INIT
#include "eTPU_MemMap.h"
P2CONST(ebppa_config_t, EBPPA_CONST, EBPPA_APPL_CONST) ebppa_gConfigPtr[EBPPA_CORE_NUM] = {0};
#define ETPU_STOP_SEC_VAR_INIT
#include "eTPU_MemMap.h"

#if(EBPPA_MULTI_CORE_SUPPORT == STD_ON)
/**
* Flag to Channel init
*/
#define ETPU_START_SEC_VAR_SHARED_INIT
#include "eTPU_MemMap.h"
volatile VAR(uint8, EBPPA_VAR) sEbppa_u8Hw2LogicChannelMap[EBPPA_CORE_NUM][EBPPA_INSTANCE_NUM] = {{EBPPA_CHN_UNUSED}};
#define ETPU_STOP_SEC_VAR_SHARED_INIT
#include "eTPU_MemMap.h"
#endif
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#if (EBPPA_DEV_ERROR_DETECT == STD_ON)
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
ETPU_INLINE FUNC(Std_ReturnType, EBPPA_CODE) EBPPA_Get_Accumulation_Verify \
( \
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel,\
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PeriodData, \
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_DutyData
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
ETPU_INLINE FUNC(Std_ReturnType, EBPPA_CODE) EBPPA_Get_Immediate_Verify \
( \
	
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel,\
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PeriodData, \
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_DutyData
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
ETPU_INLINE FUNC(Std_ReturnType, EBPPA_CODE) EBPPA_GetCount_Verify \
( \
	
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel,\
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_CurrentCount
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
ETPU_INLINE FUNC(Std_ReturnType, EBPPA_CODE) EBPPA_ResetCount_Verify \
( \
	
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel,\
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_CurrentCount
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
ETPU_INLINE FUNC(void, EBPPA_CODE) EBPPA_ReportError \
( \
    VAR(uint8, AUTOMATIC) EBPPA_ApiId, \
    VAR(uint8, AUTOMATIC) EBPPA_ErrorId \
)
{
    (void)Det_ReportError((uint16)ETPU_MODULE_ID_OUTPUT, 0U, (uint8)EBPPA_ApiId, (uint8)EBPPA_ErrorId);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"


#if(EBPPA_MULTI_CORE_SUPPORT == STD_ON)
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
ETPU_INLINE FUNC(Std_ReturnType, EBPPA_CODE) EBPPA_CoreVerify \
(
    VAR(uint8, EBPPA_VAR) u8Ebppa_Channel, \
    VAR(uint8, AUTOMATIC) EBPPA_ApiId \
)
{
    VAR(uint32, AUTOMATIC) u32EBPPA_CurrentCoreId = (uint32)EBPPA_GetCoreID();/* GetCoreID */
    VAR(Std_ReturnType, AUTOMATIC) u8EBPPA_RetValue = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATCI) Temp = (uint8)(u32EBPPA_CurrentCoreId & (uint32)ebppa_gConfigPtr[GetCoreID()]->ebppa_CoreMap[u8Ebppa_Channel].nCoreId);
    if(Temp == (uint8)0)
    {

        (void)EBPPA_ReportError(EBPPA_ApiId, EBPPA_E_PARAM_CHANNEL);

    }
    else
    {
        u8EBPPA_RetValue = (Std_ReturnType)E_OK;
    }

    return u8EBPPA_RetValue;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
#endif
#endif/*EBPPA_DEV_ERROR_DETECT == STD_ON*/
/*==================================================================================================
*                                    FUNCTION CDD
==================================================================================================*/

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) EBPPA_Get_Accumulation(VAR(uint8, EBPPA_VAR) u8Ebppa_ChannelIdx, \
											   P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PeriodData, \
											   P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_DutyData)
{
    VAR(uint8, EBPPA_VAR) u8Ebppa_Status = 0U;
    VAR(uint8, EBPPA_VAR) u8Ebppa_Channel = 0U;
    VAR(uint8, EBPPA_VAR) u8Ebppa_Group = 0U;
#if (EBPPA_DEV_ERROR_DETECT == STD_ON)
    VAR(Std_ReturnType,  AUTOMATIC) u8EBPPA_VerifyRetVal = E_NOT_OK;
    u8EBPPA_VerifyRetVal = EBPPA_Get_Accumulation_Verify(u8Ebppa_ChannelIdx, pEbppa_PeriodData, pEbppa_DutyData);
    if((Std_ReturnType)E_OK == u8EBPPA_VerifyRetVal)
    {
#endif/*EBPPA_DEV_ERROR_DETECT == STD_ON*/
        u8Ebppa_Channel = ebppa_gConfigPtr[GetCoreID()]->ebppa_ChannelConfigPtr[u8Ebppa_ChannelIdx].channel;
        u8Ebppa_Group = ebppa_gConfigPtr[GetCoreID()]->ebppa_ChannelConfigPtr[u8Ebppa_ChannelIdx].etpuGroup;
    	u8Ebppa_Status = ETPU_LLD_EBPPA_Get_Accumulation(u8Ebppa_Group, u8Ebppa_Channel, pEbppa_PeriodData, pEbppa_DutyData);
#if (EBPPA_DEV_ERROR_DETECT == STD_ON)
    }
#endif/*EBPPA_DEV_ERROR_DETECT == STD_ON*/
    return u8Ebppa_Status;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) EBPPA_Get_Immediate(
											VAR(uint8, EBPPA_VAR) u8Ebppa_ChannelIdx, \
											P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PeriodData, \
											P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_DutyData)
{
    VAR(uint8, EBPPA_VAR) u8Ebppa_Status = 0U;
    VAR(uint8, EBPPA_VAR) u8Ebppa_Channel = 0U;
    VAR(uint8, EBPPA_VAR) u8Ebppa_Group = 0U;
#if (EBPPA_DEV_ERROR_DETECT == STD_ON)
    VAR(Std_ReturnType,  AUTOMATIC) u8EBPPA_VerifyRetVal = E_NOT_OK;
    u8EBPPA_VerifyRetVal = EBPPA_Get_Immediate_Verify(u8Ebppa_ChannelIdx ,pEbppa_PeriodData ,pEbppa_DutyData);
    if((Std_ReturnType)E_OK == u8EBPPA_VerifyRetVal)
    {
#endif/*EBPPA_DEV_ERROR_DETECT == STD_ON*/
        u8Ebppa_Channel = ebppa_gConfigPtr[GetCoreID()]->ebppa_ChannelConfigPtr[u8Ebppa_ChannelIdx].channel;
        u8Ebppa_Group = ebppa_gConfigPtr[GetCoreID()]->ebppa_ChannelConfigPtr[u8Ebppa_ChannelIdx].etpuGroup;
    	u8Ebppa_Status = ETPU_LLD_EBPPA_Get_Immediate(u8Ebppa_Group, u8Ebppa_Channel, pEbppa_PeriodData, pEbppa_DutyData);
#if (EBPPA_DEV_ERROR_DETECT == STD_ON)
    }
#endif/*EBPPA_DEV_ERROR_DETECT == STD_ON*/
    return u8Ebppa_Status;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) EBPPA_GetCount(
											VAR(uint8, EBPPA_VAR) u8Ebppa_ChannelIdx, \
                                            P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_CurrentCount)
{

    VAR(uint8, EBPPA_VAR) u8Ebppa_Status = 0U;
    VAR(uint8, EBPPA_VAR) u8Ebppa_Channel = 0U;
    VAR(uint8, EBPPA_VAR) u8Ebppa_Group = 0U;
#if (EBPPA_DEV_ERROR_DETECT == STD_ON)
    VAR(Std_ReturnType,  AUTOMATIC) u8EBPPA_VerifyRetVal = E_NOT_OK;
    u8EBPPA_VerifyRetVal = EBPPA_GetCount_Verify(u8Ebppa_ChannelIdx ,pEbppa_CurrentCount);
    if((Std_ReturnType)E_OK == u8EBPPA_VerifyRetVal)
    {
#endif/*EBPPA_DEV_ERROR_DETECT == STD_ON*/
        u8Ebppa_Channel = ebppa_gConfigPtr[GetCoreID()]->ebppa_ChannelConfigPtr[u8Ebppa_ChannelIdx].channel;
        u8Ebppa_Group = ebppa_gConfigPtr[GetCoreID()]->ebppa_ChannelConfigPtr[u8Ebppa_ChannelIdx].etpuGroup;
        u8Ebppa_Status = ETPU_LLD_EBPPA_GetCount(u8Ebppa_Group, u8Ebppa_Channel, pEbppa_CurrentCount);
#if (EBPPA_DEV_ERROR_DETECT == STD_ON)
    }
#endif/*EBPPA_DEV_ERROR_DETECT == STD_ON*/
    return u8Ebppa_Status;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) EBPPA_ResetCount(
											VAR(uint8, EBPPA_VAR) u8Ebppa_ChannelIdx, \
                                            P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_CurrentCount)
{
    VAR(uint8, EBPPA_VAR) u8Ebppa_Status = 0U;
    VAR(uint8, EBPPA_VAR) u8Ebppa_Channel = 0U;
    VAR(uint8, EBPPA_VAR) u8Ebppa_Group = 0U;
#if (EBPPA_DEV_ERROR_DETECT == STD_ON)
    VAR(Std_ReturnType,  AUTOMATIC) u8EBPPA_VerifyRetVal = E_NOT_OK;
    u8EBPPA_VerifyRetVal = EBPPA_ResetCount_Verify(u8Ebppa_ChannelIdx ,pEbppa_CurrentCount);

    if((Std_ReturnType)E_OK == u8EBPPA_VerifyRetVal)
    {
#endif/*EBPPA_DEV_ERROR_DETECT == STD_ON*/
        u8Ebppa_Channel = ebppa_gConfigPtr[GetCoreID()]->ebppa_ChannelConfigPtr[u8Ebppa_ChannelIdx].channel;
        u8Ebppa_Group = ebppa_gConfigPtr[GetCoreID()]->ebppa_ChannelConfigPtr[u8Ebppa_ChannelIdx].etpuGroup;
        u8Ebppa_Status = ETPU_LLD_EBPPA_ResetCount(u8Ebppa_Group, u8Ebppa_Channel, pEbppa_CurrentCount);
#if (EBPPA_DEV_ERROR_DETECT == STD_ON)
    }
#endif/*EBPPA_DEV_ERROR_DETECT == STD_ON*/
    return u8Ebppa_Status;

}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*==================================================================================================
*                                    FUNCTION NOT AUTOSAR
==================================================================================================*/
#if (EBPPA_DEV_ERROR_DETECT == STD_ON)
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(Std_ReturnType, EBPPA_CODE) EBPPA_Init_Verify \
( \
    P2CONST(ebppa_config_t, AUTOMATIC, EBPPA_APPL_CONST) ConfigPtr \
)
{

	VAR(Std_ReturnType, AUTOMATIC) u8EBPPA_VerifyRetVal = E_NOT_OK;
#if(ETPU_PRECOMPILE_SUPPORT == STD_OFF)
    if(NULL_PTR == ConfigPtr)//PB
#else 
    // if(NULL_PTR == ConfigPtr)PC  After merging init, it is no longer necessary to check if the PC mode is a null pointer.
    if(NULL_PTR == ConfigPtr)
#endif
    {
        #if (EBPPA_DEV_ERROR_DETECT == STD_ON)
        EBPPA_ReportError(EBPPA_INIT_ID,EBPPA_E_PARAM_POINTER);
        #endif
        u8EBPPA_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        u8EBPPA_VerifyRetVal = (Std_ReturnType)E_OK;
    }
    return u8EBPPA_VerifyRetVal;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
ETPU_INLINE FUNC(Std_ReturnType, EBPPA_CODE) EBPPA_Get_Accumulation_Verify \
( \
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel,\
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PeriodData, \
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_DutyData
)
{
	VAR(Std_ReturnType, AUTOMATIC) u8EBPPA_VerifyRetVal = E_NOT_OK;
    if(ebppa_gConfigPtr[GetCoreID()] == NULL_PTR)
    {
        #if (EBPPA_DEV_ERROR_DETECT == STD_ON)
        EBPPA_ReportError(EBPPA_GET_ACCUMULATION_ID,EBPPA_E_PARAM_POINTER);
        #endif
        u8EBPPA_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if((pEbppa_PeriodData == NULL_PTR) || (pEbppa_DutyData == NULL_PTR))
    {
		#if (EBPPA_DEV_ERROR_DETECT == STD_ON)
		EBPPA_ReportError(EBPPA_GET_ACCUMULATION_ID,EBPPA_E_PARAM_POINTER);
		#endif
		u8EBPPA_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(u8Ebppa_Channel >= EBPPA_INSTANCE_NUM)
    {
        #if (EBPPA_DEV_ERROR_DETECT == STD_ON)
        EBPPA_ReportError(EBPPA_GET_ACCUMULATION_ID,EBPPA_E_PARAM_CHANNEL);
        #endif
        u8EBPPA_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {   
		#if(EBPPA_MULTI_CORE_SUPPORT == STD_ON)
		u8EBPPA_VerifyRetVal = EBPPA_CoreVerify(u8Ebppa_Channel,EBPPA_GET_ACCUMULATION_ID);
        #else
        u8EBPPA_VerifyRetVal = (Std_ReturnType)E_OK;
		#endif
    }
    return u8EBPPA_VerifyRetVal;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
ETPU_INLINE FUNC(Std_ReturnType, EBPPA_CODE) EBPPA_Get_Immediate_Verify \
( \
		
		VAR(uint8, EBPPA_VAR) u8Ebppa_Channel,\
		P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PeriodData, \
		P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_DutyData
)
{
	VAR(Std_ReturnType, AUTOMATIC) u8EBPPA_VerifyRetVal = E_NOT_OK;
	if((pEbppa_PeriodData == NULL_PTR) || (pEbppa_DutyData == NULL_PTR))
	{
		#if (EBPPA_DEV_ERROR_DETECT == STD_ON)
		EBPPA_ReportError(EBPPA_GET_IMMEDIATE_ID,EBPPA_E_PARAM_POINTER);
		#endif
		u8EBPPA_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
	}
    else if(u8Ebppa_Channel >= EBPPA_INSTANCE_NUM)
    {
        #if (EBPPA_DEV_ERROR_DETECT == STD_ON)
        EBPPA_ReportError(EBPPA_GET_IMMEDIATE_ID,EBPPA_E_PARAM_CHANNEL);
        #endif
        u8EBPPA_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
		#if(EBPPA_MULTI_CORE_SUPPORT == STD_ON)
		u8EBPPA_VerifyRetVal = EBPPA_CoreVerify(u8Ebppa_Channel,EBPPA_GET_IMMEDIATE_ID);
        #else
        u8EBPPA_VerifyRetVal = (Std_ReturnType)E_OK;
		#endif
    }
    return u8EBPPA_VerifyRetVal;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
ETPU_INLINE FUNC(Std_ReturnType, EBPPA_CODE) EBPPA_GetCount_Verify \
( \
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel,\
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_CurrentCount
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8EBPPA_VerifyRetVal = E_NOT_OK;
    if(u8Ebppa_Channel >= EBPPA_INSTANCE_NUM)
    {
        #if (EBPPA_DEV_ERROR_DETECT == STD_ON)
        EBPPA_ReportError(EBPPA_GETCOUNT_ID,EBPPA_E_PARAM_CHANNEL);
        #endif
        u8EBPPA_VerifyRetVal = (Std_ReturnType)E_NOT_OK;       
    }
    else if(pEbppa_CurrentCount == NULL_PTR)
    {
        #if (EBPPA_DEV_ERROR_DETECT == STD_ON)
        EBPPA_ReportError(EBPPA_GETCOUNT_ID,EBPPA_E_PARAM_POINTER);
        #endif
        u8EBPPA_VerifyRetVal = (Std_ReturnType)E_NOT_OK;          
    }
    else
    {
		#if(EBPPA_MULTI_CORE_SUPPORT == STD_ON)
		u8EBPPA_VerifyRetVal = EBPPA_CoreVerify(u8Ebppa_Channel,EBPPA_GETCOUNT_ID);
        #else
        u8EBPPA_VerifyRetVal = (Std_ReturnType)E_OK;
		#endif
    }
    return u8EBPPA_VerifyRetVal;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
ETPU_INLINE FUNC(Std_ReturnType, EBPPA_CODE) EBPPA_ResetCount_Verify \
( \
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel,\
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_CurrentCount
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8EBPPA_VerifyRetVal = E_NOT_OK;
    if(u8Ebppa_Channel >= EBPPA_INSTANCE_NUM)
    {
        #if (EBPPA_DEV_ERROR_DETECT == STD_ON)
        EBPPA_ReportError(EBPPA_RESETCOUNT_ID,EBPPA_E_PARAM_CHANNEL);
        #endif
        u8EBPPA_VerifyRetVal = (Std_ReturnType)E_NOT_OK;       
    }
    else if(pEbppa_CurrentCount == NULL_PTR)
    {
        #if (EBPPA_DEV_ERROR_DETECT == STD_ON)
        EBPPA_ReportError(EBPPA_RESETCOUNT_ID,EBPPA_E_PARAM_POINTER);
        #endif
        u8EBPPA_VerifyRetVal = (Std_ReturnType)E_NOT_OK;          
    }
    else
    {
		#if(EBPPA_MULTI_CORE_SUPPORT == STD_ON)
		u8EBPPA_VerifyRetVal = EBPPA_CoreVerify(u8Ebppa_Channel,EBPPA_RESETCOUNT_ID);
        #else
        u8EBPPA_VerifyRetVal = (Std_ReturnType)E_OK;
		#endif
    }
    return u8EBPPA_VerifyRetVal;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
#endif/*EBPPA_DEV_ERROR_DETECT == STD_ON*/



#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(EBPPA_LevelType,EBPPA_CODE) EBPPA_GetInputLevel \
( \
    VAR(uint8, EBPPA_VAR) u16EBPPA_Channel
)
{
    VAR(EBPPA_LevelType, EBPPA_CODE) returnVal = EBPPA_LEVEL_LOW;

    if (ETPU_LLD_GetChannelInputStatus(
        ebppa_gConfigPtr[GetCoreID()]->ebppa_ChannelConfigPtr[u16EBPPA_Channel].etpuGroup,  \
        ebppa_gConfigPtr[GetCoreID()]->ebppa_ChannelConfigPtr[u16EBPPA_Channel].channel     \
        ) == (uint8)1U)
    {
        returnVal = EBPPA_LEVEL_HIGH;
    }
    return returnVal;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"



#ifdef __cplusplus
}
#endif
#endif
#endif

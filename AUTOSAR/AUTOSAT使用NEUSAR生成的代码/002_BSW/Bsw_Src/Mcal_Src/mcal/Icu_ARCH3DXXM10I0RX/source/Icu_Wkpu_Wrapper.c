/* PRQA S 0380, 2844, 1006, 4461 EOF */
/* PRQA S 0491, 4499, 4491, 1863 EOF */
#ifdef __cplusplus
extern "C"{
#endif
#include "Icu.h"
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))

#include "Icu_Wkpu_HAL_Wrapper.h"
#include "Icu_Wkpu_Wrapper.h"
/* PRQA S 2053 EOF */    /* QAC_CWE */

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_WKPU_WRAPPER_VENDOR_ID_C                   176

#define ICU_WKPU_WRAPPER_MAJOR_VER_C                   4
#define ICU_WKPU_WRAPPER_MINOR_VER_C                   4
#define ICU_WKPU_WRAPPER_REVISION_VER_C                0

#define ICU_WKPU_WRAPPER_SW_MAJOR_VER_C                3
#define ICU_WKPU_WRAPPER_SW_MINOR_VER_C                0
#define ICU_WKPU_WRAPPER_SW_PATCH_VER_C                0

#if (ICU_WKPU_WRAPPER_VENDOR_ID_C != ICU_WKPU_WRAPPER_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_WKPU_WRAPPER_MAJOR_VER_C != ICU_WKPU_WRAPPER_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_WKPU_WRAPPER_MINOR_VER_C != ICU_WKPU_WRAPPER_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_WKPU_WRAPPER_REVISION_VER_C != ICU_WKPU_WRAPPER_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_WKPU_WRAPPER_SW_MAJOR_VER_C != ICU_WKPU_WRAPPER_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_WKPU_WRAPPER_SW_MINOR_VER_C != ICU_WKPU_WRAPPER_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_WKPU_WRAPPER_SW_PATCH_VER_C != ICU_WKPU_WRAPPER_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif

extern P2CONST(Icu_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_CfgPtr[ICU_CORE_NUM];


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Wkpu_Wrapper_Init \
( \
    P2CONST(ICU_Wkpu_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CurrentCoreId = Icu_GetCoreID();/* polyspace RTE:SHF,OVFL */
    VAR(uint8, ICU_VAR) Icu_CoreId = GetCoreID();
    VAR(uint8,  AUTOMATIC) u8CoreIdMask;
    VAR(Icu_IndexType, AUTOMATIC) nInstance;
#endif
    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:IDP,NIV */
    
    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
    	psChannelConfig = &sIcu_WrapperConfigPtr->pWkpuChannelConfig[u16ChannelIndex];/* polyspace RTE:NIP */
#if(ICU_MULTI_CORE_SUPPORT == STD_ON)

		nInstance = psChannelConfig->IcuConfig_Instance;/* polyspace RTE:NIV,IDP*/
		u8CoreIdMask= (uint8)(u32CurrentCoreId & sIcu_CfgPtr[Icu_CoreId]->Icu_CoreMap[nInstance].nCoreId);/* polyspace RTE:OBAI,NIV,IDP*/
		if(u8CoreIdMask != 0U)
		{
			sIcu_u8Hw2LogicChannelMap[Icu_CoreId][nInstance] = ICU_CHN_USED;/* polyspace RTE:OBAI */
#endif

			Icu_Wkpu_HAL_Wrapper_Init(psChannelConfig);
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
        }
#endif /* (ICU_MULTI_CORE_SUPPORT == STD_ON) */
    }
#endif/* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */
    if(sIcu_WrapperConfigPtr->pWkpuNMIConfig != NULL_PTR)/* polyspace RTE:NIP */
    {
    	Icu_WkpuNMI_HAL_Wrapper_Init(sIcu_WrapperConfigPtr->pWkpuNMIConfig);
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Wkpu_Wrapper_DeInit \
( \
    P2CONST(ICU_Wkpu_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CurrentCoreId = Icu_GetCoreID();/* polyspace RTE:SHF,OVFL */
    VAR(uint8, ICU_VAR) Icu_CoreId = GetCoreID();
    VAR(uint8,  AUTOMATIC) u8CoreIdMask;
    VAR(Icu_IndexType, AUTOMATIC) nInstance;
#endif
    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    
    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
    	psChannelConfig = &sIcu_WrapperConfigPtr->pWkpuChannelConfig[u16ChannelIndex];/* polyspace RTE:NIP */
#if(ICU_MULTI_CORE_SUPPORT == STD_ON)
		nInstance = psChannelConfig->IcuConfig_Instance;/* polyspace RTE:NIV,IDP*/
		u8CoreIdMask= u32CurrentCoreId & sIcu_CfgPtr[Icu_CoreId]->Icu_CoreMap[nInstance].nCoreId;/* polyspace RTE:OBAI,NIV,IDP*/
		if(u8CoreIdMask != 0)
		{
			sIcu_u8Hw2LogicChannelMap[Icu_CoreId][nInstance] = ICU_CHN_UNUSED;/* polyspace RTE:OBAI */
#endif
        Icu_Wkpu_HAL_Wrapper_DeInit(psChannelConfig);
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
         }
#endif /* ICU_MULTI_CORE_SUPPORT == STD_ON */
    }
#endif/*(defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */
    Icu_WkpuNMI_HAL_Wrapper_DeInit();
    (void)sIcu_WrapperConfigPtr;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Wkpu_Wrapper_EnableEdgeDetection
(
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(ICU_Wkpu_ConfigType,  ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pWkpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            Icu_Wkpu_HAL_Wrap_EnEdgeDetect(u8ModuleId, (uint8)u8IChannelId);
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC (void, ICU_CODE) Icu_Wkpu_Wrapper_DisableEdgeDetection
(
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    P2CONST(ICU_Wkpu_ConfigType,  ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pWkpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            Icu_Wkpu_HAL_Wrap_DisEdgeDetect(u8ModuleId, (uint8)u8IChannelId);
            break;
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Wkpu_Wrapper_SetActivationCondition(
    VAR(Icu_ChannelType,                 AUTOMATIC) nChannel, \
    VAR(Icu_ActivationType,              AUTOMATIC) eActivation, \
    P2CONST(ICU_Wkpu_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
)
{
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;

    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pWkpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            switch(eActivation)
            {
                case ICU_FALLING_EDGE:
                {
                    Icu_Wkpu_HAL_Wrap_SetActCondition(u8ModuleId, (uint8)u8IChannelId, WKPU_FALLING_EDGE);
                    break;
                }
                case ICU_RISING_EDGE:
                {
                    Icu_Wkpu_HAL_Wrap_SetActCondition(u8ModuleId, (uint8)u8IChannelId, WKPU_RISING_EDGE);
                    break;
                }
                case ICU_BOTH_EDGES:
                {
                    Icu_Wkpu_HAL_Wrap_SetActCondition(u8ModuleId, (uint8)u8IChannelId, WKPU_BOTH_EDGES);
                    break;
                }
                default:
                    Icu_Wkpu_HAL_Wrap_SetActCondition(u8ModuleId, (uint8)u8IChannelId, WKPU_NONE_EDGE);
                    break;
            }
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Wkpu_Wrapper_IrqConfig
(
    VAR(Icu_ChannelType,                               AUTOMATIC) nChannel, \
    P2CONST(ICU_Wkpu_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr, \
    VAR(boolean,                                       AUTOMATIC) IsEnable
)
{
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CurrentCoreId = Icu_GetCoreID();/* polyspace RTE:SHF,OVFL */
    VAR(uint8,  AUTOMATIC) u8CoreIdMask;
    VAR(Icu_IndexType, AUTOMATIC) nInstance;
#endif
    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pWkpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
#if(ICU_MULTI_CORE_SUPPORT == STD_ON)
                nInstance = psChannelConfig[u16ChannelIndex].IcuConfig_Instance;/* polyspace RTE:NIV,IDP*/
                u8CoreIdMask= u32CurrentCoreId & sIcu_CfgPtr[GetCoreID()]->Icu_CoreMap[nInstance].nCoreId;/* polyspace RTE:OBAI,NIV,IDP*/
                if(u8CoreIdMask != 0)
                {

                	if (sIcu_u8Hw2LogicChannelMap[GetCoreID()][nInstance] == ICU_CHN_USED)/* polyspace RTE:OBAI */
                	{
#endif
        if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
        {
            u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
            u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
            if (IsEnable == TRUE)
            {
                Icu_Wkpu_HAL_Wrapper_EnIrq(u8ModuleId,(uint8)u8IChannelId);
            }
            else
            {
                Icu_Wkpu_HAL_Wrapper_DisIrq(u8ModuleId,(uint8)u8IChannelId);
            }
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
                	}
                }
#endif /* ICU_MULTI_CORE_SUPPORT == STD_ON */

        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Wkpu_Wrapper_WakeupConfig
(
    VAR(Icu_ChannelType,                               AUTOMATIC) nChannel, \
    P2CONST(ICU_Wkpu_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr, \
    VAR(boolean,                                       AUTOMATIC) IsEnable
)
{
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CODE) psChannelConfig = NULL_PTR;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelNum = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u16ChannelIndex = (Icu_ChannelType)0U;
    VAR(Icu_ChannelType, AUTOMATIC) u8IChannelId = (Icu_ChannelType)0U;
    VAR(Icu_Module_Type ,AUTOMATIC) u8ModuleId = (Icu_Module_Type)0U;
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CurrentCoreId = Icu_GetCoreID();/* polyspace RTE:SHF,OVFL */
    VAR(uint8,  AUTOMATIC) u8CoreIdMask;
    VAR(Icu_IndexType, AUTOMATIC) nInstance;
#endif
    u16ChannelNum = sIcu_WrapperConfigPtr->uChannelCount;/* polyspace RTE:NIV,IDP */
    psChannelConfig = sIcu_WrapperConfigPtr->pWkpuChannelConfig;/* polyspace RTE:NIV,NIP */

    for(u16ChannelIndex = (Icu_ChannelType)0U; u16ChannelIndex < u16ChannelNum; u16ChannelIndex++)
    {
#if(ICU_MULTI_CORE_SUPPORT == STD_ON)
        nInstance = psChannelConfig[u16ChannelIndex].IcuConfig_Instance;/* polyspace RTE:NIV,IDP*/
        u8CoreIdMask= u32CurrentCoreId & sIcu_CfgPtr[GetCoreID()]->Icu_CoreMap[nInstance].nCoreId;/* polyspace RTE:OBAI,NIV,IDP*/
        if(u8CoreIdMask != 0)
        {
            if (sIcu_u8Hw2LogicChannelMap[GetCoreID()][nInstance] == ICU_CHN_USED)/* polyspace RTE:OBAI */
            {
#endif
                if (nChannel == psChannelConfig[u16ChannelIndex].IcuConfig_Instance)/* polyspace RTE:NIV,IDP */
                {
                    u8ModuleId = psChannelConfig[u16ChannelIndex].IcuConfig_ModuleId;/* polyspace RTE:NIV */
                    u8IChannelId = psChannelConfig[u16ChannelIndex].IcuConfig_ChannelId;/* polyspace RTE:NIV */
                    if (IsEnable == TRUE)
                    {
                        Icu_Wkpu_HAL_Wrapper_EnWkp(u8ModuleId,(uint8)u8IChannelId);
                    }
                    else
                    {
                        Icu_Wkpu_HAL_Wrapper_DisWkp(u8ModuleId,(uint8)u8IChannelId);
                    }
                }
#if (ICU_MULTI_CORE_SUPPORT == STD_ON)
            }
        }
#endif /* ICU_MULTI_CORE_SUPPORT == STD_ON */
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif/* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */
#endif /* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */
#ifdef __cplusplus
}
#endif


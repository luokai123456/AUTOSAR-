/* PRQA S 0380, 2053 EOF */
#ifdef __cplusplus
extern "C"{
#endif
#include "Icu.h"
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))

#include "Icu_Wkpu_LLDrivers.h"
#include "Icu_Wkpu_HAL_Wrapper.h"
#include "Icu_Wkpu_Wrapper.h"
#include "Icu_Cfg.h"
/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_WKPU_HAL_WRAPPER_VENDOR_ID_C                   176

#define ICU_WKPU_HAL_WRAPPER_MAJOR_VER_C                   4
#define ICU_WKPU_HAL_WRAPPER_MINOR_VER_C                   4
#define ICU_WKPU_HAL_WRAPPER_REVISION_VER_C                0

#define ICU_WKPU_HAL_WRAPPER_SW_MAJOR_VER_C                3
#define ICU_WKPU_HAL_WRAPPER_SW_MINOR_VER_C                0
#define ICU_WKPU_HAL_WRAPPER_SW_PATCH_VER_C                0

#if (ICU_WKPU_HAL_WRAPPER_VENDOR_ID_C != ICU_WKPU_HAL_WRAPPER_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_WKPU_HAL_WRAPPER_MAJOR_VER_C != ICU_WKPU_HAL_WRAPPER_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_WKPU_HAL_WRAPPER_MINOR_VER_C != ICU_WKPU_HAL_WRAPPER_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_WKPU_HAL_WRAPPER_REVISION_VER_C != ICU_WKPU_HAL_WRAPPER_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_WKPU_HAL_WRAPPER_SW_MAJOR_VER_C != ICU_WKPU_HAL_WRAPPER_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_WKPU_HAL_WRAPPER_SW_MINOR_VER_C != ICU_WKPU_HAL_WRAPPER_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_WKPU_HAL_WRAPPER_SW_PATCH_VER_C != ICU_WKPU_HAL_WRAPPER_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif

#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_HAL_Wrapper_Init
(
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST)Wkpu_ConfigPtr
)
{
    Icu_Wkpu_LLD_Init(Wkpu_ConfigPtr);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_HAL_Wrapper_DeInit
(
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST)Wkpu_ConfigPtr
)
{
    Icu_Wkpu_LLD_DeInit(Wkpu_ConfigPtr->IcuConfig_ModuleId,(uint8)Wkpu_ConfigPtr->IcuConfig_ChannelId);/* polyspace RTE:NIV,IDP */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif/* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */	

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_WkpuNMI_HAL_Wrapper_Init(
    P2CONST(ICU_Wkpu_NMIConfigType, AUTOMATIC, ICU_APPL_CONST) pWkpuNMIConfig
)
{
    Icu_WkpuNMI_LLD_Init(pWkpuNMIConfig);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_WkpuNMI_HAL_Wrapper_DeInit(void)
{
    Icu_WkpuNMI_LLD_DeInit();
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */
#ifdef __cplusplus
}
#endif

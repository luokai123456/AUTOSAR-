#ifndef ICU_WKPU_HAL_WRAPPER_H
#define ICU_WKPU_HAL_WRAPPER_H
/* PRQA S 2053,1599 EOF */
#ifdef __cplusplus
extern "C"
{
#endif


#include "Icu.h"
#include "Icu_Wkpu_LLDrivers.h"
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))
#include "Icu_Cfg.h"
/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_WKPU_HAL_WRAPPER_VENDOR_ID_H                   176

#define ICU_WKPU_HAL_WRAPPER_MAJOR_VER_H                   4
#define ICU_WKPU_HAL_WRAPPER_MINOR_VER_H                   4
#define ICU_WKPU_HAL_WRAPPER_REVISION_VER_H                0

#define ICU_WKPU_HAL_WRAPPER_SW_MAJOR_VER_H                3
#define ICU_WKPU_HAL_WRAPPER_SW_MINOR_VER_H                0
#define ICU_WKPU_HAL_WRAPPER_SW_PATCH_VER_H                0

#if (ICU_WKPU_HAL_WRAPPER_VENDOR_ID_H != ICU_VENDOR_ID_CFG)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_WKPU_HAL_WRAPPER_MAJOR_VER_H != ICU_AR_RELEASE_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_WKPU_HAL_WRAPPER_MINOR_VER_H != ICU_AR_RELEASE_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_WKPU_HAL_WRAPPER_REVISION_VER_H != ICU_AR_RELEASE_REVISION_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_WKPU_HAL_WRAPPER_SW_MAJOR_VER_H != ICU_SW_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_WKPU_HAL_WRAPPER_SW_MINOR_VER_H != ICU_SW_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_WKPU_HAL_WRAPPER_SW_PATCH_VER_H != ICU_SW_PATCH_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif



#define Icu_Wkpu_HAL_Wrap_EnEdgeDetect(module, channel) \
    Icu_Wkpu_LLD_EnableInterrupt((module),(channel))

#define Icu_Wkpu_HAL_Wrap_DisEdgeDetect(module, channel) \
    Icu_Wkpu_LLD_DisableInterrupt((module),(channel))

#define Icu_Wkpu_HAL_Wrap_SetActCondition(module, channel, type) \
    Icu_Wkpu_LLD_SetActivationCondition((module), (channel), (type))

#define Icu_Wkpu_HAL_Wrapper_EnIrq(module, channel) \
    Icu_Wkpu_LLD_EnableInterrupt((module),(channel))

#define Icu_Wkpu_HAL_Wrapper_DisIrq(module, channel) \
    Icu_Wkpu_LLD_DisableInterrupt((module),(channel))

#define Icu_Wkpu_HAL_Wrapper_EnWkp(module, channel) \
    Icu_Wkpu_LLD_EnableWakeup((module),(channel))

#define Icu_Wkpu_HAL_Wrapper_DisWkp(module, channel) \
    Icu_Wkpu_LLD_DisableWakeup((module),(channel))

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_HAL_Wrapper_Init
(
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST)Wkpu_ConfigPtr
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_HAL_Wrapper_DeInit
(
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST)Wkpu_ConfigPtr
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_WkpuNMI_HAL_Wrapper_Init(
    P2CONST(ICU_Wkpu_NMIConfigType, AUTOMATIC, ICU_APPL_CONST) pWkpuNMIConfig
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_WkpuNMI_HAL_Wrapper_DeInit( void );
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */
#ifdef __cplusplus
}
#endif

#endif


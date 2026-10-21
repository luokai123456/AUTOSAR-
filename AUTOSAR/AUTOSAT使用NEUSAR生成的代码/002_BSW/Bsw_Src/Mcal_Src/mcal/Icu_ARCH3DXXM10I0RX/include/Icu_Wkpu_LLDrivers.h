/* PRQA S 3432 EOF */
#ifndef ICU_WKPU_LLDRIVERS_H
#define ICU_WKPU_LLDRIVERS_H

#ifdef __cplusplus
extern "C"{
#endif
#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))
#include "Icu_Cfg.h"
/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_WKPU_LLDRIVERS_VENDOR_ID_H                   176

#define ICU_WKPU_LLDRIVERS_MAJOR_VER_H                   4
#define ICU_WKPU_LLDRIVERS_MINOR_VER_H                   4
#define ICU_WKPU_LLDRIVERS_REVISION_VER_H                0

#define ICU_WKPU_LLDRIVERS_SW_MAJOR_VER_H                3
#define ICU_WKPU_LLDRIVERS_SW_MINOR_VER_H                0
#define ICU_WKPU_LLDRIVERS_SW_PATCH_VER_H                0

#if (ICU_WKPU_LLDRIVERS_VENDOR_ID_H != ICU_VENDOR_ID_CFG)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_WKPU_LLDRIVERS_MAJOR_VER_H != ICU_AR_RELEASE_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_WKPU_LLDRIVERS_MINOR_VER_H != ICU_AR_RELEASE_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_WKPU_LLDRIVERS_REVISION_VER_H != ICU_AR_RELEASE_REVISION_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_WKPU_LLDRIVERS_SW_MAJOR_VER_H != ICU_SW_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_WKPU_LLDRIVERS_SW_MINOR_VER_H != ICU_SW_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_WKPU_LLDRIVERS_SW_PATCH_VER_H != ICU_SW_PATCH_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif

#ifdef RESOURCE_CHIP_CORE_NUM
#define WKPU_NMI_CORE_MAX               (RESOURCE_CHIP_CORE_NUM)
#else
#define WKPU_NMI_CORE_MAX               (uint32)(6U)
#endif

#define WKPU_NMI_CORE_BIT_OFFSET        (uint32)(8U)

typedef  struct WKPU_tag WKPU_Type;

typedef enum
{
    WKPU_NONE_EDGE       = 0U,   /**< @brief None event */
    WKPU_RISING_EDGE     = 1U,   /**< @brief Rising edge event */
    WKPU_FALLING_EDGE    = 2U,   /**< @brief Falling edge event */
    WKPU_BOTH_EDGES      = 3U    /**< @brief Both rising and falling edge event */
} Icu_Wkpu_EdgeType;


typedef enum
{
    WKPU_CORE0       = 0U,    /*!< Core 0 */
    WKPU_CORE1       = 1U,    /*!< Core 1 */
    WKPU_CORE2       = 2U,    /*!< Core 2 */
    WKPU_CORE3       = 3U,     /*!< Core 3 */
    WKPU_CORE4       = 4U,     /*!< Core 4 */
    WKPU_CORE5       = 5U     /*!< Core 5 */
} Wkpu_CoreType;

typedef enum
{
    WKPU_NMI_NONE               = 3U,    /**< @brief No NMI, critical interrupt, or machine check request generated */
    WKPU_NMI_MACHINE_CHK_REQ    = 2U,   /**< @brief Machine check request interrupt */
    WKPU_NMI_CRITICAL_INT       = 1U,   /**< @brief Critical interrupt */
    WKPU_NMI_NON_MASK_INT       = 0U   /**< @brief Non-maskable interrupt */
} Wkpu_NmiDestSrcType;

typedef struct
{
    Wkpu_CoreType               core;               /**< @brief WKPU core source */
    Wkpu_NmiDestSrcType         destination;        /**< @brief NMI destination source */
    boolean                     wkpReqEn;           /**< @brief NMI request enable */
    boolean                     filterEn;           /**< @brief NMI filter enable */
    Icu_Wkpu_EdgeType           edgeEvent;          /**< @brief NMI edge events */
    boolean                     lockEn;             /**< @brief NMI configuration lock register */
} Wkpu_NmiCfgType;

typedef struct
{
    /* ICU channel instance */
    CONST(Icu_IndexType,           ICU_CONST) IcuConfig_Instance;
    CONST(Icu_Module_Type,          ICU_CONST) IcuConfig_ModuleId;
    CONST(Icu_ChannelType,          ICU_CONST) IcuConfig_ChannelId;
    CONST(Icu_ActivationType,       ICU_CONST) IcuChannel_DefaultStartEdge;
    CONST(Icu_NotifyType,           ICU_CONST) IcuChannel_Notification;
    CONST(boolean,                  ICU_CONST) IcuChannel_WakeupCapability;
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
    CONST(EcuM_WakeupSourceType,    ICU_CONST) IcuChannel_WakeupValue;
#endif
    CONST(boolean,                  ICU_CONST) IcuChannel_Filter;
} ICU_Wkpu_ChannelConfigType;

typedef struct
{
	CONST(uint8, ICU_CONST) NMICount;
	P2CONST(Wkpu_NmiCfgType, ICU_CONST, ICU_APPL_CONST)WkpuNMIConfig;
} ICU_Wkpu_NMIConfigType;


typedef struct ICU_Wkpu_Config
{
    /* Number of ICU etpu channels */
    VAR(Icu_ChannelType, ICU_VAR) uChannelCount;
    /* Hardware dependent Channel configuration */
    P2CONST(ICU_Wkpu_ChannelConfigType, ICU_VAR, ICU_APPL_CONST) pWkpuChannelConfig;
    P2CONST(ICU_Wkpu_NMIConfigType, ICU_VAR, ICU_APPL_CONST) pWkpuNMIConfig;
} ICU_Wkpu_ConfigType;

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_Init
(
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST)Wkpu_ConfigPtr
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_DeInit
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_WkpuNMI_LLD_Init(
    P2CONST(ICU_Wkpu_NMIConfigType, AUTOMATIC, ICU_APPL_CONST) pWkpuNMIConfig
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_WkpuNMI_LLD_DeInit( void );
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_EnableInterrupt
(
	VAR(uint8, AUTOMATIC) instance,
	VAR(uint8, AUTOMATIC) hwChannel
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_DisableInterrupt
(
	VAR(uint8, AUTOMATIC) instance,
	VAR(uint8, AUTOMATIC) hwChannel
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_EnableWakeup
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint8, AUTOMATIC) hwChannel
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_DisableWakeup
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint8, AUTOMATIC) hwChannel
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_SetActivationCondition
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel,
    VAR(Icu_Wkpu_EdgeType, ICU_VAR)edge
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(boolean, ICU_CODE)Icu_Wkpu_LLD_GetInputState
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_IrqCallbcak
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


extern CONSTP2VAR(WKPU_Type, ICU_CONST, ICU_APPL_CONST) Wkpu_Base[]; /* PRQA S 3684 */

#endif /* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */
#ifdef __cplusplus
}
#endif

#endif/* ICU_WKPU_LLDRIVERS_H */

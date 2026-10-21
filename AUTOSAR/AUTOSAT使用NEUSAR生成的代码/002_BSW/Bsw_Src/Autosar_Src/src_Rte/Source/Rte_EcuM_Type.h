/*
************************************************************************************************************************
*
* File name: Rte_EcuM_Type.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
************************************************************************************************************************
*
* History
*-----------------------------------------------------------------------------------------------------------------------
************************************************************************************************************************
* Version: 3.0
* Author/Date : WangJP/2021.11.11
* Change: New created.
* Cause: New
************************************************************************************************************************
* Version: 4.0
* Author/Date: LanZG/2024.03.18
* Change: Upgrade template.
* Cause: Update
************************************************************************************************************************
*/
#ifndef RTE_ECUM_TYPE_H_
#define RTE_ECUM_TYPE_H_

/*
************************************************************************************************************************
*    Includes
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Macros
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Types
************************************************************************************************************************
*/
#ifndef Rte_TypeDef_EcuM_UserType
#define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;
#endif

#ifndef Rte_TypeDef_EcuM_ShutdownTargetType
#define Rte_TypeDef_EcuM_ShutdownTargetType
typedef uint8 EcuM_ShutdownTargetType;
#endif

#ifndef Rte_TypeDef_EcuM_ShutdownCauseType
#define Rte_TypeDef_EcuM_ShutdownCauseType
typedef uint8 EcuM_ShutdownCauseType;
#endif

#ifndef Rte_TypeDef_EcuM_ShutdownModeType
#define Rte_TypeDef_EcuM_ShutdownModeType
typedef uint16 EcuM_ShutdownModeType;
#endif

#ifndef Rte_TypeDef_EcuM_BootTargetType
#define Rte_TypeDef_EcuM_BootTargetType
typedef uint8 EcuM_BootTargetType;
#endif

#ifndef Rte_TypeDef_EcuM_TimeType
#define Rte_TypeDef_EcuM_TimeType
typedef uint32 EcuM_TimeType;
#endif

/*SWS_EcuM_04136 EcuM_ShutdownTargetType*/
#define ECUM_SHUTDOWN_TARGET_SLEEP                                   (0x00U)
#define ECUM_SHUTDOWN_TARGET_RESET                                   (0x01U)
#define ECUM_SHUTDOWN_TARGET_OFF                                     (0X02U)

/* EcuM_ShutdownCauseType */
#define ECUM_CAUSE_UNKNOWN                                           (0x00U)
#define ECUM_CAUSE_ECU_STATE                                         (0x01U)
#define ECUM_CAUSE_WDGM                                              (0X02U)
#define ECUM_CAUSE_DCM                                               (0X03U)

/*SWS_EcuM_91008 EcuM_BootTargetType*/
#define ECUM_BOOT_TARGET_APP                                         (0U)
#define ECUM_BOOT_TARGET_OEM_BOOTLOADER                              (1U)
#define ECUM_BOOT_TARGET_SYS_BOOTLOADER                              (2U)

#define ECUM_STATE_SLEEP                            (0U)
#define ECUM_STATE_RESET                            (1U)
#define ECUM_STATE_OFF                              (2U)

/*
************************************************************************************************************************
*    Global Variables
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Constants
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Functions
************************************************************************************************************************
*/

#endif /* RTE_H_ */


/*
********************************************************************************
*
* File name: EcuM_Cfg.h
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 2.0
* Author/Date : yong.zhang/2019.11.26
* Change: New created.
* Cause: New
********************************************************************************
* Version: 2.1
* Author/Date: guoziyang/2020.11.18
* Change: Modify compilation warning.
* Cause: Optimization
********************************************************************************
* Version: 2.2
* Author/Date: GuoZY/2021.10.28
* Change: Increase the header file to include.(Os.h) 
* Cause: Optimization
********************************************************************************
* Version: 2.3
* Author/Date: GuoZY/2021.12.10
* Change: Add conditional compilation for Mcu.h.
* Cause: Optimization
********************************************************************************
* Version: 2.4
* Author/Date: GuoZY/2021.12.17
* Change: Delete type definition.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date: TianL/2024.8.5
* Change: Modify copyright.
* Cause: Update
********************************************************************************
*/
#ifndef ECUM_CFG_H_
#define ECUM_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "EcuM_Types.h"
#include "Os.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* polyspace-begin MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_EcuM_Rule10.3" */
#define ECUM_POSTBUILD_VARIANT_SUPPORT    (STD_OFF)
#define ECUM_CORE_ID_MASTER               (OS_CORE_ID_MASTER)

/* EcuM_WakeupSourceType */
#define ECUM_WKSOURCE_NONE                       (EcuM_WakeupSourceType)(0x00000000UL)
#define ECUM_WKSOURCE_ALL_SOURCES                (EcuM_WakeupSourceType)(~((EcuM_WakeupSourceType)0x00UL))
#define ECUM_WKSOURCE_POWER                      (EcuM_WakeupSourceType)(1UL)
#define ECUM_WKSOURCE_RESET                      (EcuM_WakeupSourceType)(2UL)
#define ECUM_WKSOURCE_INTERNAL_RESET             (EcuM_WakeupSourceType)(4UL)
#define ECUM_WKSOURCE_INTERNAL_WDG               (EcuM_WakeupSourceType)(8UL)
#define ECUM_WKSOURCE_EXTERNAL_WDG               (EcuM_WakeupSourceType)(16UL)   

#define J1939_bms_10nggJ              (EcuM_WakeupSourceType)(32UL)  
#define PMS_EV_CAN_20260126_RMXr12              (EcuM_WakeupSourceType)(64UL)  
#define XCP_And_Test_CAN_GtPS3U              (EcuM_WakeupSourceType)(128UL)  
#define N72_HCM _Matrix_lGfZId              (EcuM_WakeupSourceType)(256UL)  
#define PMS_C_CAN_20260126_fVs55R              (EcuM_WakeupSourceType)(512UL)  
#define N72PMS_PT_CANFD_20260228__XQc0B              (EcuM_WakeupSourceType)(1024UL)  
#define ECUM_DEFAULT_APP_MODE                                               (1U)
#define ECUM_DEFAULT_RESET_MODEREF                                          (0U)
#define ECUM_DEFAULT_SHUTDOWN_TARGET                                        (ECUM_SHUTDOWN_TARGET_OFF)
#define ECUM_DEFAULT_SLEEP_MODEREF                                          (0U)
#define ECUM_GODOWN_ALLOWED_USER                                            (1U)
#define ECUM_MAINFUNCTION_PERIOD                                            (5U)
#define ECUM_NORMAL_MCU_MODEREF                                             (0U)
#define ECUM_NUMBER_OF_CORES                                                (6U)
#define ECUM_RESET_MODE_COUNT                                               (0U)
#define ECUM_SHUTDOWN_CAUSE_COUNT                                           (0U)
#define ECUM_SLAVE_CORE_NOTIFY_SHUTDOWN                                     (4U)
#define ECUM_SLEEP_MODE_COUNT                                               (1U)
#define ECUM_WAKEUP_SOURCE_LIST                                             (11U)
#define ECUM_CHECK_TIMEOUT                                                  (STD_OFF)
#define ECUM_DEV_ERROR_REPORT                                               (STD_OFF)
#define ECUM_INCLUDE_DET                                                    (STD_OFF)
#define ECUM_RESETLOOP_DETECTION                                            (STD_OFF)
#define ECUM_RESET_REASON_REF                                               (STD_OFF)
#define ECUM_SET_PROGRAMABLE_INTERRUPTS                                     (STD_OFF)
#define ECUM_VALIDATION_TIMEOUT                                             (STD_OFF)
#define ECUM_VERSIONINFO_API                                                (STD_OFF)
#define ECUM_RESOURCE_CORE0 CORE0_TASK_OSRESOURCE0
#define ECUM_RESOURCE_CORE1 CORE1_TASK_OSRESOURCE0
#define ECUM_RESOURCE_CORE2 CORE2_TASK_OSRESOURCE0
#define ECUM_RESOURCE_CORE3 CORE3_TASK_OSRESOURCE0
#define ECUM_RESOURCE_CORE4 CORE4_TASK_OSRESOURCE0
#define ECUM_RESOURCE_CORE5 CORE5_TASK_OSRESOURCE0

/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* polyspace-end MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_EcuM_Rule10.3" */
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define ECUM_START_SEC_GLOBAL_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if( ECUM_WAKEUP_SOURCE_LIST > 0U )
extern VAR(uint32, ECUM_VAR_NO_INIT) EcuM_ValidationTimeoutArray[ECUM_WAKEUP_SOURCE_LIST];
#endif

#define ECUM_STOP_SEC_GLOBAL_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define ECUM_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if( ECUM_WAKEUP_SOURCE_LIST > 0U )
extern CONST(EcuM_WakeupSourceListType, ECUM_CONFIG_DATA) EcuM_WakeupSourceList[ECUM_WAKEUP_SOURCE_LIST];
#endif

#if( ECUM_GODOWN_ALLOWED_USER > 0U )
extern CONST(uint8, ECUM_CONFIG_DATA) EcuM_GoDownAllowedUser[ECUM_GODOWN_ALLOWED_USER];
#endif

#if( ECUM_SLEEP_MODE_COUNT > 0U )
extern CONST(EcuM_SleepModeType, ECUM_CONFIG_DATA) Ecum_SleepMode[ECUM_SLEEP_MODE_COUNT];
#endif

extern CONST(EcuM_ConfigParaType, ECUM_CONFIG_DATA) EcuM_ConfigParaData[ECUM_NUMBER_OF_CORES];

#define ECUM_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif  /* ECUM_CFG_H_ */


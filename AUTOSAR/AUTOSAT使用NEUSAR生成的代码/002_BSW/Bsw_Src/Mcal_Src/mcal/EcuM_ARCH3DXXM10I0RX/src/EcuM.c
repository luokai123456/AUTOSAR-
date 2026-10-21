/**
*   @file    EcuM.c
*   @version 3.0.0
*
*   @brief   AUTOSAR EcuM - module implementation.
*   @details This module implements stubs for the AUTOSAR EcuM
*            This file contains sample code only. It is not part of the production code deliverables
*
*   @addtogroup ECUM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : ECUM
*   Dependencies         : -
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : MPC577XM_MCAL_1_0_2_RTM_ASR_REL_4_0_REV_0003_20170922
*
*   (c) Copyright (c) 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017 CCFC.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
/*==============================================INCLUDE FILES=======================================*/
#include "Std_Types.h"
#ifdef TEST_CAN
#include "CanIf.h"
#endif
#include "EcuM.h"
#ifdef TEST_GPT
#include "Gpt.h"
#endif
#ifdef TEST_LIN
#include "LinIf.h"
#endif
#ifdef TEST_ICU
#include "Icu_test_ext_common.h"
#endif
#include "cc_printf.h"

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
#define ECUM_VENDOR_ID_C                         176
#define ECUM_AR_RELEASE_MAJOR_VERSION_C          4
#define ECUM_AR_RELEASE_MINOR_VERSION_C          4
#define ECUM_AR_RELEASE_REVISION_C               0
#define ECUM_SW_MAJOR_VERSION_C                  3
#define ECUM_SW_MINOR_VERSION_C                  0
#define ECUM_SW_PATCH_VERSION_C                  0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ECUM header file are of the same vendor */
#if (ECUM_VENDOR_ID_C != ECUM_VENDOR_ID)
    #error "EcuM.c and EcuM.h have different vendor ids"
#endif

/* Check if source file and ECUM header file are of the same Autosar version */

#if ((ECUM_AR_RELEASE_MAJOR_VERSION_C != ECUM_AR_RELEASE_MAJOR_VERSION) || \
     (ECUM_AR_RELEASE_MINOR_VERSION_C != ECUM_AR_RELEASE_MINOR_VERSION) || \
     (ECUM_AR_RELEASE_REVISION_C != ECUM_AR_RELEASE_REVISION))
  #error "AutoSar Version Numbers of EcuM.c and EcuM.h are different"
#endif

/* Check if source file and ECUM header file are of the same Software version */
#if ((ECUM_SW_MAJOR_VERSION_C != ECUM_SW_MAJOR_VERSION) || \
     (ECUM_SW_MINOR_VERSION_C != ECUM_SW_MINOR_VERSION) || \
     (ECUM_SW_PATCH_VERSION_C != ECUM_SW_PATCH_VERSION))
    #error "Software Version Numbers of EcuM.c and EcuM.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and StandardTypes header file are of the same version */
#if ((ECUM_AR_RELEASE_MAJOR_VERSION_C  != STANDARD_AR_RELEASE_MAJOR_VERSION) || \
     (ECUM_AR_RELEASE_MINOR_VERSION_C != STANDARD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of EcuM.c and Std_Types.h are different"
#endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief   This function sets the last wakeup event of the ECUM.
* @details This is a function stub only.
* 
* @param[in]     events  last wakeup event
* 
*/

ECUM_START_SEC_CODE
FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent(VAR(EcuM_WakeupSourceType, AUTOMATIC) events)
{
    (void)events;

    ECUM_PRINTF("check wake up is ok.\n");
}
ECUM_STOP_SEC_CODE
/*================================================================================================*/
/**
* @brief   This function validates the wakeup event.
* @details This is a function stub only. Functionality is void in this implementation
* 
* @param[in]     events wakeup event to validate
*/
ECUM_START_SEC_CODE
FUNC(void, ECUM_CODE) EcuM_ValidateWakeupEvent(VAR(EcuM_WakeupSourceType, AUTOMATIC) events)
{
    (void)events;
}
ECUM_STOP_SEC_CODE
/*================================================================================================*/
/**
* @brief   This function checks the wakeup source against possible sources of wakeup.
* @details This is a function stub only. It calls the wakeup interfaces of CANIf, GPT and LIN with the wakeupSource parameter.
* 
* @param[in]     wakeupSource  wakeup source ID
* 
*/
ECUM_START_SEC_CODE
FUNC(void, ECUM_CODE) EcuM_CheckWakeup(VAR(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource)
{
    (void)wakeupSource;
#ifdef TEST_CAN
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
    CanIf_CheckWakeup(wakeupSource);
#endif
#endif
#ifdef TEST_GPT
    Gpt_CheckWakeup(wakeupSource);
#endif
#ifdef TEST_LIN
    LinIf_CheckWakeup(wakeupSource);
#endif
#ifdef TEST_ICU
    Icu_CheckWakeup(wakeupSource);
#endif
}
ECUM_STOP_SEC_CODE

#ifdef __cplusplus
}
#endif

/* End of file */

/** @} */

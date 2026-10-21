/*
********************************************************************************
*
* File name: LinSM_Cfg.h
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2020.03.26
* Change: New created
* Cause: New
********************************************************************************
*/
#ifndef LINSM_CFG_H_
#define LINSM_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "LinSM.h"
#include "LinSM_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Total number of network channels. */
#define LINSM_NETWORK_TOTAL_NUMBER                 (1U)
/* LinSM ConfigSet */
/* Specifies the maximal amount of mode request repetitions without a respective
   mode indication from the LinIf module until the LinSM module reports a Default
   Error to the Det and tries to go back to no communication. */
#define LINSM_MODE_REQUEST_REPETITION_MAX          (3U)

/* LinSM General */
/* Switches the Default Error Tracer (Det) detection and notification ON or OFF. */
#define LINSM_DEV_ERROR_DETECT                     (STD_OFF)

/* Fixed period that the MainFunction shall be called.(MS) */
#define LINSM_MAIN_PROCESSING_PERIOD               (10U)

/* Switches the LinSM_GetVersionInfo function ON or OFF. */
#define LINSM_VERSION_INFO_API                     (STD_OFF)

#define LINSM_SCHEDLE_NUMBER                       (2U)
#define LINSM_BSWMENABLED                          (STD_ON)

/* if slave function is supported */
#define LINSM_SLAVE_SUPPORT                        (STD_OFF)

/* if master channel exsists */
#define LINSM_MASTER_SUPPORT                       (STD_ON)

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
#define LINSM_START_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"
extern VAR(LinSM_Managment_st, LINSM_VAR_NO_INIT) LinSM_Management_Tab[LINSM_NETWORK_TOTAL_NUMBER];
#define LINSM_STOP_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define LINSM_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"
extern CONST(LinSM_Channl_Config_st, LINSM_CONFIG_DATA)LinSM_Channl_Cfg_Tab[LINSM_NETWORK_TOTAL_NUMBER];

extern CONST(uint8, LINSM_CONFIG_DATA)LinSM_ScheduleIdx_Info[LINSM_SCHEDLE_NUMBER];
#define LINSM_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinSM_MemMap.h"
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
#endif /* LINSM_CFG_H_ */


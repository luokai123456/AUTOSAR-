/**
*   @file    Det.c
*   @version 3.0.0
*
*   @brief   AUTOSAR Det - module implementation
*   @details This module implements stubs for the AUTOSAR Det
*            This file contains sample code only. It is not part of the production code deliverables
*
*   @addtogroup DET_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : Det
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : MPC577XM_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20170922
*
*   (c) Copyright (c) 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017 CCFC.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
/* PRQA S 1514 EOF */

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/
/**
* @file           Det.c
* @requirements   DET004
*/
#include "Std_Types.h"
#include "Det.h"
#include "cc_printf.h"
/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
#define DET_VENDOR_ID_C                     176
#define DET_AR_RELEASE_MAJOR_VERSION_C      4
#define DET_AR_RELEASE_MINOR_VERSION_C      4
#define DET_AR_RELEASE_REVISION_VERSION_C   0
#define DET_SW_MAJOR_VERSION_C              3
#define DET_SW_MINOR_VERSION_C              0
#define DET_SW_PATCH_VERSION_C              0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and DET header file are of the same vendor */
#if (DET_VENDOR_ID_C != DET_VENDOR_ID)
    #error "Det.c and Det.h have different vendor ids"
#endif

/* Check if source file and DET header file are of the same Autosar version */
#if ((DET_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
     (DET_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) || \
     (DET_AR_RELEASE_REVISION_VERSION_C != DET_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Det.c and Det.h are different"
#endif

/* Check if source file and DET header file are of the same Software version */
#if ((DET_SW_MAJOR_VERSION_C != DET_SW_MAJOR_VERSION) || \
     (DET_SW_MINOR_VERSION_C != DET_SW_MINOR_VERSION) || \
     (DET_SW_PATCH_VERSION_C != DET_SW_PATCH_VERSION))
    #error "Software Version Numbers of Det.c and Det.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/


/* Variables to store last DET error */
DET_START_SEC_VAR_NO_INIT
VAR(uint8, DET_VAR) Det_InstanceId;     /**< @brief DET instance ID*/
DET_STOP_SEC_VAR_NO_INIT

DET_START_SEC_VAR_NO_INIT
VAR(uint8, DET_VAR) Det_ApiId;          /**< @brief DET API ID*/
DET_STOP_SEC_VAR_NO_INIT

DET_START_SEC_VAR_NO_INIT
VAR(uint8, DET_VAR) Det_ErrorId;        /**< @brief DET Error ID*/
DET_STOP_SEC_VAR_NO_INIT

/* Variables to store last DET error */
DET_START_SEC_VAR_NO_INIT
VAR(uint16, DET_VAR) Det_ModuleId;       /**< @brief DET module ID*/
DET_STOP_SEC_VAR_NO_INIT
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/* put all DET code into defined section */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*================================================================================================*/
/**
* @brief          This function initializes the DET module.
* @details        This is a function stub only. Functionality is void in this implementation
*
* @requirements   DET008
*
*/
DET_START_SEC_CODE
FUNC(void, DET_CODE) Det_Init(void)
{
    
}
DET_STOP_SEC_CODE

/*================================================================================================*/
/** 
* @brief   This function provides the service for reporting of development errors. 
* @details This is a function stub only. It only loads the global IDs with the IDs of the latest error that occured
*    
* @param[in]     ModuleId    Module ID of Calling Module
* @param[in]     InstanceId  Index of Module starting at 0
* @param[in]     ApiId       ID of API with Error
* @param[in]     ErrorId     ID of Error
*
* @requirement DET009
*/
DET_START_SEC_CODE
FUNC(Std_ReturnType, DET_CODE) Det_ReportError(VAR(uint16, AUTOMATIC) ModuleId, VAR(uint8, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) ErrorId)
{
    Det_ModuleId = ModuleId; 
    Det_InstanceId = InstanceId;
    Det_ApiId = ApiId; 
    Det_ErrorId = ErrorId;

    DET_PRINTF("Det:ReportError: Module %d, Instance %d, Api %d, Error %d\r\n",
        ModuleId, InstanceId, ApiId, ErrorId);
    return E_OK;
}
DET_STOP_SEC_CODE

DET_START_SEC_CODE
FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError(VAR(uint16, AUTOMATIC) ModuleId, VAR(uint8, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) ErrorId) {
    // do nothing
    (void)ModuleId;
    (void)InstanceId;
    (void)ApiId;
    (void)ErrorId;
	DET_PRINTF("Det:Det_ReportRuntimeError: Module %d, Instance %d, Api %d, Error %d\r\n",
	        ModuleId, InstanceId, ApiId, ErrorId);
	return E_OK;
}
DET_STOP_SEC_CODE

DET_START_SEC_CODE
FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientFault(VAR(uint16, AUTOMATIC) ModuleId, VAR(uint8, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) FaultId) {
    // do nothing
    (void)ModuleId;
    (void)InstanceId;
    (void)ApiId;
    (void)FaultId;
    DET_PRINTF("Det:Det_ReportTransientFault: Module %d, Instance %d, Api %d, Fault %d\r\n",
        ModuleId, InstanceId, ApiId, FaultId);
    return E_OK;
}
DET_STOP_SEC_CODE

/*================================================================================================*/
/** 
* @brief   This function provides the starting after the Det_Init has been called. 
* @details This is a function stub only.  Det_Init and Det_Start shall always be available. 
*          Functionality is void in this implementation
*    
* @requirement DET010   
*/
DET_START_SEC_CODE
FUNC(void, DET_CODE) Det_Start(void)
{
    
}
DET_STOP_SEC_CODE


#ifdef __cplusplus
}
#endif

/** @} */

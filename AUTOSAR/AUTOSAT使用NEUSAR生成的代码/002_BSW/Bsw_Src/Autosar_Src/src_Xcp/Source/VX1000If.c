/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  VX1000If.c
 *        \brief  VX1000 Interface source file
 *
 *      \details  Implementation of an API wrapper between ASAM names and proprietary VX1000 driver names.
 *
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define VX1000IF_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "VX1000If.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of VX1000If header file */
#if (  (VX1000IF_SW_MAJOR_VERSION != (3u)) \
    || (VX1000IF_SW_MINOR_VERSION != (9u)) \
    || (VX1000IF_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of VX1000If.c and VX1000If.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define VX1000IF_START_SEC_VAR_CLEARED_8
#include "VX1000If_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Initialization state of the module */
VAR(uint8, VX1000IF_VAR_CLEARED) VX1000If_State = VX1000IF_UNINIT; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

/*! Counter for errors that are caused by API calls when :
 *     - VX1000 Interface is in incorrect state (e.g. not initialized) 
 *     - or if VX1000If_IsVX1000DriverAccessEnabled returned FALSE 
 */
VAR(uint8, VX1000IF_VAR_CLEARED) VX1000If_ErrorCount = 0; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define VX1000IF_STOP_SEC_VAR_CLEARED_8
#include "VX1000If_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define VX1000IF_START_SEC_CODE
#include "VX1000If_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  VX1000If_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VX1000IF_CODE) VX1000If_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
  VX1000If_State = VX1000IF_UNINIT;

  VX1000If_ErrorCount = 0;
}  /* VX1000If_InitMemory() */

/**********************************************************************************************************************
 *  VX1000If_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VX1000IF_CODE) VX1000If_Init(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #-- Set component to initialized */
  if (VX1000If_State == VX1000IF_UNINIT)
  {
    VX1000If_State = VX1000IF_PRE_INIT;

    VX1000If_ErrorCount = 0;
  }
} /* VX1000If_Init() */

#define VX1000IF_STOP_SEC_CODE
#include "VX1000If_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* COV_JUSTIFICATION_BEGIN

\ID COV_VX1000IF_TESTSUITE_INSTRUMENTATION
  \ACCEPT XF 
  \REASON Not all branches covered because the following preprocessor macros and defines are necessary for proper test execution with TscStandard: VX1000If_IsExtOsTracingEnabled

COV_JUSTIFICATION_END */

/* Justification for module-specific MISRA deviations:
MD_VX1000If_OperationAlwaysTrue:
    Reason:      Optimizations in some configurations lead to a constant operation.
    Risk:        None, even in configurations where the operation is always true.
    Prevention:  N/A
    
MD_VX1000If_OperationAlwaysFalse:
    Reason:      Optimizations in some configurations lead to a constant operation.
    Risk:        None, even in configurations where the operation is always false.
    Prevention:  N/A
*/

/**********************************************************************************************************************
 *  END OF FILE: VX1000If.c
 *********************************************************************************************************************/

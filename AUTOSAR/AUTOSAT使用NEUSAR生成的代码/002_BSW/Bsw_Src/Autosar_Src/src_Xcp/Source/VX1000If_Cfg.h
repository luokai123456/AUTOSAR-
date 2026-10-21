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
 /*!       \file  VX1000If_Cfg.h
 *        \brief  VX1000 Interface configuration header file
 *
 *      \details  Template implementation the configuration specific defines for the VX1000 interface wrapper.
 *                This file can be customized to the users needs.
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

#if !defined(VX1000IF_CFG_H)
#define VX1000IF_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ Include files
 ----------------------------------------------------------------------------- */

#include "Std_Types.h"

#if !defined (VX1000IF_EXT_OS_TRACING) /* COV_VX1000IF_TEMPLATE XF */
# define VX1000IF_EXT_OS_TRACING                     STD_OFF /*!< OS tracing is disabled by default because it leads to significantly higher CPU load. It can be enabled by setting it to STD_ON. */
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

extern volatile boolean VX1000If_DriverActive;

# if (VX1000IF_EXT_OS_TRACING == STD_ON) /* COV_VX1000IF_TEMPLATE TX */
extern volatile boolean VX1000If_ExtOsTracingActive;
# endif

/**********************************************************************************************************************
 * MACROS
 *********************************************************************************************************************/
#define VX1000If_IsVX1000DriverAccessEnabled        TRUE//(VX1000If_DriverActive == TRUE)       /*!< Boolean expression that indicates whether the wrapper should call the actual VX driver. */

# if (VX1000IF_EXT_OS_TRACING == STD_ON) /* COV_VX1000IF_TEMPLATE TX */
#  define VX1000If_IsExtOsTracingEnabled            (VX1000If_ExtOsTracingActive == TRUE) /*!< Boolean expression that indicates whether the wrapper should handle OS VTH hooks for tracing. */
# endif

#endif /* VX1000IF_CFG_H */

/* COV_JUSTIFICATION_BEGIN
 *

\ID COV_VX1000IF_TEMPLATE
  \REASON This template code's variant coverage violation is considered irrelevant because the user is responsible for this file.
  
COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: VX1000If_Cfg.h
 *********************************************************************************************************************/

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
 /*!       \file  VX1000If_MemMap.h
 *        \brief  VX1000 Interface memory mapping header file
 *
 *      \details  Template implementation the memory mapping section defines for the VX1000 interface wrapper.
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

#ifndef MICROSAR_DISABLE_MEMMAP

/**********************************************************************************************************************
 *  MEMMAP SECTIONS
 *********************************************************************************************************************/

#define MEMMAP_ERROR

#if defined VX1000IF_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VX1000IF_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef VX1000IF_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VX1000IF_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VX1000IF_CODE_OPEN
#  error Closing via VX1000IF_STOP_SEC_CODE is not possible as that MemMap section is not opened.
# endif
# undef VX1000IF_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef VX1000IF_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VX1000IF_START_SEC_VAR_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VX1000I_VAR_CLEARED_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef VX1000IF_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VX1000IF_STOP_SEC_VAR_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VX1000I_VAR_CLEARED_8_OPEN
#  error Closing via VX1000IF_STOP_SEC_VAR_CLEARED_8 is not possible as that MemMap section is not opened.
# endif
# undef VX1000I_VAR_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef VX1000IF_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VX1000IF_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VX1000IF_CONST_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef VX1000IF_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VX1000IF_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VX1000IF_CONST_UNSPECIFIED_OPEN
#  error Closing via VX1000IF_STOP_SEC_CONST_UNSPECIFIED is not possible as that MemMap section is not opened.
# endif
# undef VX1000IF_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef VX1000IF_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VX1000IF_START_SEC_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VX1000IF_VAR_NO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef VX1000IF_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VX1000IF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VX1000IF_VAR_NO_INIT_UNSPECIFIED_OPEN
#  error Closing via VX1000IF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as that MemMap section is not opened.
# endif
# undef VX1000IF_VAR_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef VX1000IF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VX1000If_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VX1000If_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef VX1000If_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VX1000If_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VX1000If_CODE_OPEN
#  error Closing via VX1000If_STOP_SEC_CODE is not possible as that MemMap section is not opened.
# endif
# undef VX1000If_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef VX1000If_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef VX1000IF_START_SEC_CODE
# error Each MemMap include may only perform one action. Include MemMap separately for each action.
#endif
#ifdef VX1000IF_STOP_SEC_CODE
# error Each MemMap include may only perform one action. Include MemMap separately for each action.
#endif
#ifdef VX1000IF_START_SEC_VAR_CLEARED_8
# error Each MemMap include may only perform one action. Include MemMap separately for each action.
#endif
#ifdef VX1000IF_STOP_SEC_VAR_CLEARED_8
# error Each MemMap include may only perform one action. Include MemMap separately for each action.
#endif
#ifdef VX1000IF_START_SEC_CONST_UNSPECIFIED
# error Each MemMap include may only perform one action. Include MemMap separately for each action.
#endif
#ifdef VX1000IF_STOP_SEC_CONST_UNSPECIFIED
# error Each MemMap include may only perform one action. Include MemMap separately for each action.
#endif
#ifdef VX1000IF_START_SEC_VAR_NO_INIT_UNSPECIFIED
# error Each MemMap include may only perform one action. Include MemMap separately for each action.
#endif
#ifdef VX1000IF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# error Each MemMap include may only perform one action. Include MemMap separately for each action.
#endif

#ifdef MEMMAP_ERROR
# error No MemMap section found in VX1000If_MemMap.h. Check your section define for validity.
#endif

#endif

/**********************************************************************************************************************
 *  END OF FILE: VX1000If_MemMap.h
 *********************************************************************************************************************/


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
 /*!       \file  VX1000If.h
 *        \brief  VX1000 Interface header file
 *
 *      \details  Implementation of an API wrapper between ASAM names and proprietary VX1000 driver names.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  1.00.00   2015-03-16  visore  ESCAN00082675 FEAT-1488: Implement VX1000 Interface
 *  1.01.00   2017-02-01  visore  ESCAN00093798 Add support for address update of dynamic-address signals.
 *  1.02.00   2017-02-17  visore  ESCAN00094061 Add reference to supplemental VX1000If documentation.
 *  1.03.00   2017-09-20  visore  ESCAN00094493 Update and fix doxygen header of VX1000If_Event()
 *            2017-10-06  visore  ESCAN00097021 Implement new MailboxWriteSplit() support
 *  2.00.00   2018-04-11  visore  STORYC-4965   MISRA-C:2012 Compliance
 *            2018-04-11  visore  ESCAN00097252 Update return codes of mailbox service descriptions
 *  3.00.00   2019-05-06  visore  STORYC-8309   Make Vx1000If Safe (deactivation only)
 *  3.01.00   2019-10-22  visore  ESCAN00104649 Added VX1000If_StimWaitNoCopy and VX1000If_StimWaitNoCopyVoid
 *  3.02.00   2020-06-24  visore  SWAT-1053     Added VX1000If_MemSync_AddrRange
 *  3.03.00   2020-11-04  visore  SWAT-1362     Added VX1000If_EventUserTimestamp
 *  3.04.00   2021-03-05  visore  SWAT-1379     Enhance with sporadic XCP OS Measurement Points
 *            2021-03-18  visore  ESCAN00108901 Missing doxygen description for return value 2 of VX1000If_DeviceDetected()
 *  3.05.00   2021-10-20  visore  SWAT-1757     Add services for A2L Measurment Configuration
 *  3.06.00   2022-01-18  visore  SWAT-2132     M&C: Improve Performance Impact of VX1000 Tracing
 *  3.07.00   2023-07-05  visore  SWAT-2804     Add support for VX1000 Notification and DataTransfer services
 *  3.08.00   2023-08-23  visore  SWAT-3167     Add support for VX1000 Copy Offloader services
 *  3.09.00   2025-02-20  visore  SWAT-3724     Add VX1000If memmap handling according 19-11
 *            2025-02-20  visore  SWAT-3720     Add support for a separate VX1000If_Cfg.h file
 *            2025-02-20  visore  SWAT-3722     Add Overlay and Calibration GetStatus and TA measurement trigger services
 *********************************************************************************************************************/

/**
* \defgroup IF Embedded Interfaces
* \{
*   \defgroup Generic Generic
*   \defgroup STIM STIM and DAQ
*   \defgroup GenHookCtrl Generic Hooking Control
*   \defgroup HookBasedBypassing Hook Based Bypassing
*   \defgroup Mailbox Mailbox
*   \defgroup Overlay Overlay
*   \defgroup ResM Resource Management
*   \defgroup CO Copy Offloader
*   \defgroup DataTransfer Data Transfer
*   \defgroup Notification Notification
*   \defgroup A2L A2L Measurement Configuration
*   \defgroup UsrFunc User functions and macros */
/** \} */

#if !defined(VX1000IF_H)
# define VX1000IF_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "VX1000If_Cfg.h"
# include "VX1000.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define VX1000IF_SW_MAJOR_VERSION                    (3u)
# define VX1000IF_SW_MINOR_VERSION                    (9u)
# define VX1000IF_SW_PATCH_VERSION                    (0u)

# if defined(VX1000IF_CFG_NO_TARGET)
#  error "no target selected that tells the interface which driver files to include"
# else /* !VX1000IF_CFG_NO_TARGET */
#  if !defined(VX1000If_IsVX1000DriverAccessEnabled)
#   error "no boolean expression defined that tells the interface whether to call or to not call the actual driver"
#  else /* VX1000If_IsVX1000DriverAccessEnabled */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ------- Modes ------- */
#   define VX1000IF_UNINIT                              (0x00u)
#   define VX1000IF_PRE_INIT                            (0x01u)
#   define VX1000IF_INITIALIZED                         (0x02u)

/* --- Return Values --- */
#   define VX1000IF_RET_VOID                            (void)0
#   define VX1000IF_RET_E_NOT_OK                        (0xFFu)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 0342 2 */ /* MD_MSR_Rule20.10_0342 */
#   define VX1000IF_IMPL(functionName, retVal)      ((!VX1000If_IsVX1000DriverAccessEnabled) || (VX1000If_State != VX1000IF_INITIALIZED))?(VX1000If_ErrorCount++,retVal):VX1000_##functionName
#   define VX1000IF_IMPL_VOID(functionName)          if ((!VX1000If_IsVX1000DriverAccessEnabled) || (VX1000If_State != VX1000IF_INITIALIZED)) { VX1000If_ErrorCount++; } else VX1000_##functionName

/**********************************************************************************************************************
 *  VX1000If_InitAsyncStart()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_InitAsyncStart(void)
 *  \brief       Macro to perform the VX1000 start-up handshaking
 *  \details     Makes the VX1000 device driver detect an attached VX1000 device and perform a first handshake.
 *  \pre         VX1000If_Init must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-812
 *  \ingroup     Generic
 *********************************************************************************************************************/
#   define   VX1000If_InitAsyncStart()             if ( (VX1000If_IsVX1000DriverAccessEnabled)                     &&       \
                                                        (VX1000If_State == VX1000IF_PRE_INIT))                              \
                                                        { VX1000_INIT_ASYNC_START(); VX1000If_State = VX1000IF_INITIALIZED; } \
                                                   else { VX1000If_ErrorCount++; }

/**********************************************************************************************************************
 *  VX1000If_InitAsyncEnd()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_InitAsyncEnd(void)
 *  \brief       Macro to finish the VX1000 start-up handshake
 *  \details     Makes the VX1000 device driver perform the second part of the handshake with an attached VX1000 device.
 *               Waits for end of handshake and can be used to synchronize the instrumentation on several cores.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-813
 *  \ingroup     Generic
 *********************************************************************************************************************/
#   define   VX1000If_InitAsyncEnd                    VX1000IF_IMPL_VOID(INIT_ASYNC_END)

/**********************************************************************************************************************
 *  VX1000If_CheckFeatureStatus() /   VX1000If_CheckFeatureStatusVoid()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_CheckFeatureStatus(uint32* status_buffer, uint32 finally_checked)
 *  \brief       Macro to exchange status information between an attached VX1000 device and the VX1000 device driver.
 *  \details     The driver can inform the device which XCP features the application is still or no longer interested
 *               in and the device can inform the driver/the application, which XCP features are already ready for use
 *               (note: currently only bit "VX1000_FEATURE_TRACE" is defined).
 *  \param[in]   status_buffer:       A pointer to 32bits in RAM to receive the status information.
 *  \param[in]   finally_checked:     A bitmask to transmit which features need not to be started from now on.
 *  \return      0 - result written to the status buffer
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-278583
 *  \ingroup     Generic
 *********************************************************************************************************************/
#   define   VX1000If_CheckFeatureStatus              VX1000IF_IMPL(CHECK_FEATURESTATUS      , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_CheckFeatureStatusVoid          VX1000IF_IMPL_VOID(CHECK_FEATURESTATUS_VOID)

/**********************************************************************************************************************
 *  VX1000If_DaqGetStatus
 *********************************************************************************************************************/
/*! \fn          void VX1000If_DaqGetStatus(uint32 DgsDaqType, uint8* pDgsDaqStatus)
 *  \brief       Macro to provide the activity status of the selected DAQ type
 *  \details     Checks several conditions and optionally sets the status variable to 1.
 *  \param[in]   DgsDaqType:        Selector for the status type of interest, typically 0x01000000.
 *  \param[in,out]  pDgsDaqStatus:  Pointer to a byte variable that must be initialised to zero and that will
 *                                  receive value one if the DAQ type of interest is started.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-DaqGetStatus
 *  \ingroup     Generic	
 *********************************************************************************************************************/
#   define   VX1000If_DaqGetStatus                    VX1000IF_IMPL_VOID(DAQGETSTATUS)

/**********************************************************************************************************************
 *  VX1000If_PrepareSoftreset() / VX1000If_PrepareSoftresetVoid()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_PrepareSoftreset(void)
 *  \fn          void VX1000If_PrepareSoftresetVoid(void)
 *  \brief       Macros for Pre-restart handshake with the VX1000 device driver
 *  \details     Makes the VX1000 device driver inform an attached VX1000 device about an upcoming software reset.
 *  \return      0 - reset procedure confirmed by tool
 *               1 - handshake failed (measurement won't be resumed after the reset)
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-814
 *  \ingroup     Generic
 *********************************************************************************************************************/
#   define   VX1000If_PrepareSoftreset                VX1000IF_IMPL(PREPARE_SOFTRESET        , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_PrepareSoftresetVoid            VX1000IF_IMPL_VOID(PREPARE_SOFTRESET_VOID)

/********************** STIM API BEGIN *******************************************************************************/

/**********************************************************************************************************************
 *  VX1000If_StimControl() / VX1000If_BypassControl()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_StimControl(void)
 *  \fn          void VX1000If_BypassControl(void)
 *  \brief       Macros for the STIM-Keep-Alive-Handler
 *  \details     DEPRECATED: VX1000If_BypassControl should be used for new projects instead of VX1000If_StimControl!
 *               Must be cyclically called by the application if STIM/Bypassing is used. Makes the VX1000 device driver
 *               perform bypassing management tasks, like globally starting and stopping bypassing operation.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-805
 *  \ingroup     STIM
 *********************************************************************************************************************/
#   define   VX1000If_StimControl                     VX1000IF_IMPL_VOID(STIM_CONTROL)
#   define   VX1000If_BypassControl                   VX1000IF_IMPL_VOID(BYPASS_CONTROL)

/**********************************************************************************************************************
 *  VX1000If_StimRequest()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_StimRequest(uint8 stim_event)
 *  \brief       Macro to a request STIM data set
 *  \details     Makes the VX1000 device driver request a specific STIM data set associated to event channel stim_event.
 *  \param[in]   stim_event:          The range for stim_event is defined in the VX1000 device driver configuration.
 *                                    It is a subset of the available DAQ event channels.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-806
 *  \ingroup     STIM
 *********************************************************************************************************************/
#   define   VX1000If_StimRequest                     VX1000IF_IMPL_VOID(STIM_REQUEST)

/**********************************************************************************************************************
 *  VX1000If_StimGetCurrentState() / VX1000If_BypassGetCurrentState()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_StimGetCurrentState(uint8 stim_event)
 *  \fn          uint8 VX1000If_BypassGetCurrentState(uint8 stim_event)
 *  \brief       Macros to check whether a specific STIM request is not fulfilled, yet.
 *  \details     Returns whether a specific STIM request is not fulfilled, yet.
 *               Depending on the STIM method used, the actual copying to the destination memories may be postponed, though.
 *  \param[in]   stim_event:          The range for stim_event is defined in the VX1000 device driver configuration.
 *                                    It is a subset of the available DAQ event channels.
 *  \return      0 - STIM is not active: the event channel is not involved in the current measurement scenario
 *               1 - corresponding DAQ data - if any - completely transmitted, now waiting for this event's stimulation
 *                   data to completely arrive
 *               2 - all requested data already arrived
 *               3 - still waiting for DAQ data to completely transmit before the stimulation can even begin
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-841
 *  \ingroup     STIM
 *********************************************************************************************************************/
#   define   VX1000If_StimGetCurrentState             VX1000IF_IMPL(STIM_GET_CURRENT_STATE   , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_BypassGetCurrentState           VX1000IF_IMPL(BYPASS_GET_CURRENT_STATE , VX1000IF_RET_E_NOT_OK)

/**********************************************************************************************************************
 *  VX1000If_StimWait() / VX1000If_StimWaitVoid() / VX1000If_BypassStim() / VX1000If_BypassStimVoid()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_StimWait(uint8 stim_event, uint8 copy_enable, uint32 timeout_us)
 *  \fn          void VX1000If_StimWaitVoid(uint8 stim_event, uint8 copy_enable, uint32 timeout_us)
 *  \fn          uint8 VX1000If_BypassStim(uint8 stim_event, uint8 copy_enable, uint32 timeout_us)
 *  \fn          void VX1000If_BypassStimVoid(uint8 stim_event, uint8 copy_enable, uint32 timeout_us)
 *  \brief       Macros to wait until a specific STIM request is fulfilled
 *  \details     Makes the VX1000 device driver wait in a busy polling loop until a specific STIM request is fulfilled.
 *               Depending on the STIM method used, on success all transfer descriptors assigned to stim_event are
 *               processed and the STIM data is transferred to its destination.
 *  \param[in]   stim_event:          The range for stim_event is defined in the VX1000 device driver configuration.
 *                                    It is a subset of the available DAQ event channels.
 *  \param[in]   timeout_us:          timeout in microseconds, starting from related call to VX1000If_StimRequest
 *  \return      0 - data arrived before timeout or timeout but data still copied successfully
 *               1 - timeout, no new data arrived or error during copying and destination data corrupted
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_StimRequest and VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-808
 *  \ingroup     STIM
 *********************************************************************************************************************/
#   define   VX1000If_StimWait                        VX1000IF_IMPL(STIM_WAIT                , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_StimWaitVoid                    VX1000IF_IMPL_VOID(STIM_WAIT_VOID)
#   define   VX1000If_BypassStim                      VX1000IF_IMPL(BYPASS_STIM              , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_BypassStimVoid                  VX1000IF_IMPL_VOID(BYPASS_STIM_VOID)

/**********************************************************************************************************************
 *  VX1000If_StimWaitNoCopy() / VX1000If_StimWaitNoCopyVoid
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_StimWaitNoCopy(uint8 stim_event, uint32 timeout_us)
 *  \fn          void VX1000If_StimWaitNoCopyVoid(uint8 stim_event, uint32 timeout_us)
 *  \brief       Macros to wait until a specific STIM request is fulfilled
 *  \details     Makes the VX1000 device driver wait in a busy polling loop until a specific STIM request is fulfilled.
 *               Depending on the STIM method used, on success all transfer descriptors assigned to stim_event are
 *               processed but the STIM data is not transferred.
 *  \param[in]   stim_event:          The range for stim_event is defined in the VX1000 device driver configuration.
 *                                    It is a subset of the available DAQ event channels.
 *  \param[in]   timeout_us:          timeout in microseconds, starting from related call to VX1000If_StimRequest
 *  \return      0 - data arrived before timeout or timeout but data still copied successfully
 *               1 - timeout, no new data arrived or error during copying and destination data corrupted
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_StimRequest and VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-808
 *  \ingroup     STIM
 *********************************************************************************************************************/
#   define   VX1000If_StimWaitNoCopy                  VX1000IF_IMPL(STIM_WAIT_NO_COPY        , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_StimWaitNoCopyVoid              VX1000IF_IMPL_VOID(STIM_WAIT_NO_COPY_VOID)

/**********************************************************************************************************************
 *  VX1000If_StimActive()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_StimActive(uint8 stim_event)
 *  \brief       Macro to check the STIM status of an event
 *  \details     Makes the VX1000 device driver return whether STIM is active for the specific event channel and globally.
 *  \param[in]   stim_event:          The range for stim_event is defined in the VX1000 device driver configuration.
 *                                    It is a subset of the available DAQ event channels.
 *  \return      1 - active
 *               0 - inactive
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-807
 *  \ingroup     STIM
 *********************************************************************************************************************/
#   define   VX1000If_StimActive                      VX1000IF_IMPL(STIM_ACTIVE              , VX1000IF_RET_E_NOT_OK)

/**********************************************************************************************************************
 *  VX1000If_StimSkip()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_StimSkip(uint8 stim_event)
 *  \brief       Macro to send a STIM skip event
 *  \details     Makes the VX1000 device driver send a STIM skip event to tell the attached VX1000 device not to
 *               stimulate the next cycle. This is in effect a dummy STIM request.
 *  \param[in]   stim_event:          The range for stim_event is defined in the VX1000 device driver configuration.
 *                                    It is a subset of the available DAQ event channels.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-809
 *  \ingroup     STIM
 *********************************************************************************************************************/
#   define   VX1000If_StimSkip                        VX1000IF_IMPL_VOID(STIM_SKIP)

/**********************************************************************************************************************
 *  VX1000If_Stimulate() / VX1000If_StimulateVoid()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_Stimulate(uint8 stim_trigger_event, uint8 stim_event, uint8 cycle_delay, uint32 timeout_us)
 *  \fn          void VX1000If_StimulateVoid(uint8 stim_trigger_event, uint8 stim_event, uint8 cycle_delay, uint32 timeout_us)
 *  \brief       Macros to initiate a bypass without sending DAQ data
 *  \details     Makes the VX1000 device driver perform a complete stimulation. This is done by requesting STIM data
 *               using the stim_trigger_event which is in fact a DAQ event with or without DAQ data. The first cycle_delay
 *               calls are used to fill a STIM data pipeline in the VX1000. During these calls the function will return 0.
 *               After the first cycle_delay calls, this function will busy wait with timeout for the VX1000 to actually
 *               complete the stimulation (stim_event). The pipeline depth / initial delay has to be considered when
 *               generating the STIM data.
 *  \param[in]   stim_trigger_event:  DAQ event range
 *  \param[in]   stim_event:          The range for stim_event is defined in the VX1000 device driver configuration.
 *                                    It is a subset of the available DAQ event channels.
 *  \param[in]   cycle_delay:         Specifies the number of cycles between triggering and the associated
 *                                    stimulation. During the first cycle_delay cycles there is no stimulation in the
 *                                    ECU, instead the VX1000 device fills its STIM buffer FIFO.
 *  \param[in]   timeout_us:          Timeout in microseconds, starting upon calling this function.
 *  \return      0 - code to be bypassed shall be executed as bypassing is not active
 *               1 - STIM successful, code to be bypassed shall be skipped
 *               2 - STIM failed, it is up to the application to handle this error
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-816
 *  \ingroup     STIM
 *********************************************************************************************************************/
#   define   VX1000If_Stimulate                       VX1000IF_IMPL(STIMULATE                , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_StimulateVoid                   VX1000IF_IMPL_VOID(STIMULATE_VOID)

/**********************************************************************************************************************
 *  VX1000If_Bypass() / VX1000If_BypassVoid()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_Bypass(uint8 daq_event, uint8 stim_event, uint32 timeout_us)
 *  \fn          void VX1000If_BypassVoid(uint8 daq_event, uint8 stim_event, uint32 timeout_us)
 *  \brief       Macros to initiate a bypass with sending DAQ data and wait for completion
 *  \details     Makes the VX1000 device driver initiate a bypass by sending DAQ data to the tool and implicitly requesting
 *               a stimulation (daq_event), then busy wait with timeout for the tool to complete the stimulation (stim_event).
 *  \param[in]   daq_event:           DAQ event range
 *  \param[in]   stim_event:          The range for stim_event is defined in the VX1000 device driver configuration.
 *                                    It is a subset of the available DAQ event channels.
 *  \param[in]   timeout_us:          Timeout in microseconds, starting with the function call
 *  \return      0 - code to be bypassed shall be executed as bypassing is not active
 *               1 - Bypass successful, code to be bypassed shall be skipped
 *               2 - Bypass failed, it is up to the application to handle this error
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-815
 *  \ingroup     STIM
 *********************************************************************************************************************/
#   define   VX1000If_Bypass                          VX1000IF_IMPL(BYPASS                   , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_BypassVoid                      VX1000IF_IMPL_VOID(BYPASS_VOID)

/**********************************************************************************************************************
 *  VX1000If_BypassDaq() / VX1000If_BypassDaqVoid()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_BypassDaq(uint8 daq_event, uint8 stim_event)
 *  \fn          void VX1000If_BypassDaqVoid(uint8 daq_event, uint8 stim_event)
 *  \brief       Macros to initiate a bypass by sending a DAQ event
 *  \details     Makes the VX1000 device driver initiate a bypass by sending a DAQ event followed by a STIM request.
 *  \param[in]   daq_event:           DAQ event range
 *  \param[in]   stim_event:          The range for stim_event is defined in the VX1000 device driver configuration.
 *                                    It is a subset of the available DAQ event channels.
 *  \return      0 - bypassing is not active: code to be bypassed shall be executed
 *               1 - bypassing is active: code to be bypassed shall shall be skipped
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-810
 *  \ingroup     STIM
 *********************************************************************************************************************/
#   define   VX1000If_BypassDaq                      VX1000IF_IMPL(BYPASS_DAQ               , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_BypassDaqVoid                  VX1000IF_IMPL_VOID(BYPASS_DAQ_VOID)

/**********************************************************************************************************************
 *  VX1000If_BypassTrigger() / VX1000If_BypassTriggerVoid()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_BypassTrigger(uint8 daq_event, uint8 stim_event)
 *  \fn          void VX1000If_BypassTriggerVoid(uint8 daq_event, uint8 stim_event)
 *  \brief       Macros to initiate a bypass with sending DAQ data
 *  \details     Makes the VX1000 device driver initiate a bypass by sending DAQ data to the tool and implicitly requesting
 *               a stimulation (daq_event).
 *  \param[in]   daq_event:           DAQ event range
 *  \param[in]   stim_event:          The range for stim_event is defined in the VX1000 device driver configuration.
 *                                    It is a subset of the available DAQ event channels.
 *  \return      0 - bypassing is not active: code to be bypassed shall be executed
 *               1 - bypassing is active: code to be bypassed shall shall be skipped
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-839
 *  \ingroup     STIM
 *********************************************************************************************************************/
#   define   VX1000If_BypassTrigger                  VX1000IF_IMPL(BYPASS_TRIGGER           , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_BypassTriggerVoid              VX1000IF_IMPL_VOID(BYPASS_TRIGGER_VOID)

/**********************************************************************************************************************
 *  VX1000If_BypassWait() / VX1000If_BypassWaitVoid()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_BypassWait(uint8 stim_event, uint32 timeout_us)
 *  \fn          void VX1000If_BypassWaitVoid(uint8 stim_event, uint32 timeout_us)
 *  \brief       Macros to wait for the too to complete a stimulation
 *  \details     Makes the VX1000 device driver perform a busy wait with timeout for the tool to complete a stimulation
 *               (stim_event) that has been initiated beforehand by an appropriate call to VX1000If_BypassTrigger.
 *  \param[in]   stim_event:          The range for stim_event is defined in the VX1000 device driver configuration.
 *                                    It is a subset of the available DAQ event channels.
 *  \param[in]   timeout_us:          Timeout in microseconds, starting with the function call
 *  \return      0 - bypassed code shall be activated because bypassing is not active
 *               1 - everything done, bypassed code shall be disabled
 *               2 - bypassing failed; its up to the application design whether executing the bypassed code makes sense here
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_BypassTrigger and VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-817
 *  \ingroup     STIM
 *********************************************************************************************************************/
#   define   VX1000If_BypassWait                     VX1000IF_IMPL(BYPASS_WAIT              , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_BypassWaitVoid                 VX1000IF_IMPL_VOID(BYPASS_WAIT_VOID)

/**********************************************************************************************************************
 *  VX1000If_Event()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_Event(uint8 eventNumber)
 *  \brief       Macro to processes all transfer descriptors assigned to the given event.
 *  \details     Makes the VX1000 device driver trigger an XCP event. For copying-mechanism-based DAQ, makes the
 *               VX1000 device driver process all transfer descriptors assigned to eventNumber and to copy the DAQ data
 *               to an intermediate buffer to be read by the VX1000.
 *  \param[in]   eventNumber:         DAQ event range
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-836
 *  \ingroup     STIM
 *********************************************************************************************************************/
#   define   VX1000If_Event                          VX1000IF_IMPL_VOID(EVENT)

/**********************************************************************************************************************
 *  VX1000If_EventUserTimestamp()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_EventUserTimestamp(uint8 eventNumber, uint32 timeStamp)
 *  \brief       Macro to processes all transfer descriptors assigned to the given event with a user-provided timestamp.
 *  \details     Makes the VX1000 device driver trigger an XCP event. For copying-mechanism-based DAQ, makes the
 *               VX1000 device driver process all transfer descriptors assigned to eventNumber and to copy the DAQ data
 *               to an intermediate buffer to be read by the VX1000. This API allows to attach an old timestamp value
 *               (instead of the automatically fetched current time as done in e.g. VX1000If_Event) to old data as
 *               it may occur with deep message queues between MCU part and CPU/DSP part in complex SOC scenarios.
 *  \param[in]   eventNumber:         DAQ event range
 *  \param[in]   timeStamp:           Timestamp (VX1000_CLOCK() return value from the past)
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-277891
 *  \ingroup     STIM
 *********************************************************************************************************************/
#   define   VX1000If_EventUserTimestamp             VX1000IF_IMPL_VOID(EVENT_USER_TIMESTAMP)

/**********************************************************************************************************************
 *  VX1000If_EventProcessingBarrier()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_EventProcessingBarrier(uint8 eventNumber)
 *  \brief       Macro to set all transfer descriptors assigned to the given event as inconsistent.
 *  \details     Tells the VX1000 device driver that the application starts modifying data for the corresponding event.
 *  \param[in]   eventNumber:         DAQ event range
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-197097
 *  \ingroup     STIM
 *********************************************************************************************************************/
#   define   VX1000If_EventProcessingBarrier         VX1000IF_IMPL_VOID(EVENT_PROCESSING_BARRIER)

/********************** STIM API END *********************************************************************************/

/********************** A2L API BEGIN ********************************************************************************/

/**********************************************************************************************************************
 *  VX1000If_MeasConfigInit()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_MeasConfigInit(void)
 *  \brief       Macro to reset the entire A2L information to empty.
 *  \details     All lists and references are cleared and scope is reset to global.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-278566
 *  \ingroup     A2L
 *********************************************************************************************************************/
#   define   VX1000If_MeasConfigInit                 VX1000IF_IMPL_VOID( MEAS_CONFIG_INIT )

/**********************************************************************************************************************
 *  VX1000If_MeasConfigDone()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_MeasConfigDone(void)
 *  \brief       Macro to signal the VX1000 that the measurement configuration description is complete now.
 *  \details     The tool on the PC will not read the configuration from the ECU unless this API has been called.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-278567
 *  \ingroup     A2L
 *********************************************************************************************************************/
#   define   VX1000If_MeasConfigDone                 VX1000IF_IMPL_VOID(MEAS_CONFIG_DONE)

/**********************************************************************************************************************
 *  VX1000If_MeasSetEventList()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_MeasSetEventList(const uint32* EList, uint32 EListBytes)
 *  \brief       Macro to bind the provided pre-generated list of events to the measurement configuration.
 *  \details     Any previous event list will be replaced by the new one. Data is transmitted by reference only.
 *  \param[in]   EList:               Pointer to a list generated by using compile-time API VX1000_MEAS_INIT_EVENT()/
 *                                    VX1000If_MeasConfigDone().
 *  \param[in]   EListBytes:          Size of that list in bytes. (Despite the zero-termination, the known size allows
 *                                    the VX1000 to exploit efficient block accesses when fetching the list from ECUs
 *                                    memory.)
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-278568
 *  \ingroup     A2L
 *********************************************************************************************************************/
#   define   VX1000If_MeasSetEventList               VX1000IF_IMPL_VOID(MEAS_SET_EVENTLIST)

/**********************************************************************************************************************
 *  VX1000If_MeasSetSignalList()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_MeasSetSignalList(const uint32* SList, uint32 SListBytes)
 *  \brief       Macro to bind the provided pre-generated list of signals to the measurement configuration.
 *  \details     Any previous signal list will be replaced by the new one. Data is transmitted by reference only.
 *  \param[in]   SList:               Pointer to a list generated by using compile-time API VX1000If_MeasAddSigName()/
 *                                    VX1000If_MeasTypedefInst()/VX1000If_MeasAddSigEnumId()/
 *                                    VX1000If_MeasTypedefInstId()/VX1000If_MeasAddSigEnumId()/
 *                                    VX1000If_MeasTypedefAdd()/VX1000If_MeasTypedefAddSt()/
 *                                    VX1000If_MeasTypedefEnd()/VX1000If_MeasConfigDone().
 *  \param[in]   SListBytes:          Size of that list in bytes. (Despite the zero-termination, the known size allows
 *                                    the VX1000 to exploit efficient block accesses when fetching the list from ECUs
 *                                    memory.)
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-278569
 *  \ingroup     A2L
 *********************************************************************************************************************/
#   define   VX1000If_MeasSetSignalList              VX1000IF_IMPL_VOID(MEAS_SET_SIGNALLIST)

/**********************************************************************************************************************
 *  VX1000If_MeasAddEvent()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_MeasAddEvent(uint32 AEv, uint32 APrio, uint32 ADir, uint32 ACycUs, const uint8* ADesc)
 *  \brief       Macro to add a single event description to the measurement configuration.
 *  \details     Data is appended by a copy operation to RAM.
 *  \param[in]   AEv:                 Events channel number E [0,512).
 *  \param[in]   APrio:               Events priority E [0,256).
 *  \param[in]   ADir:                Events data flow direction E {VX1000_MEAS_EVENT_DAQ, VX1000_MEAS_EVENT_STIM,
 *                                    VX1000_MEAS_EVENT_DAQSTIM}.
 *  \param[in]   ACycUs:              Events cycle time in microseconds.
 *  \param[in]   ADesc:               Pointer to an ASCIIZ string to be used as comment for this event.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-278570
 *  \ingroup     A2L
 *********************************************************************************************************************/
#   define   VX1000If_MeasAddEvent                   VX1000IF_IMPL_VOID(MEAS_ADD_EVENT)

/**********************************************************************************************************************
 *  VX1000If_MeasAddSigName()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_MeasAddSigName(const uint8* AName, uint32 ANEvt, uint32 ANAdr, uint32 ANExt, uint32 ANType, uint32 ANArrayCnt)
 *  \brief       Macro to add a single signal description to the measurement configuration.
 *  \details     Data is appended by a copy operation to RAM.
 *  \param[in]   AName:               Pointer to an ASCIIZ string holding the signals name.
 *  \param[in]   ANEvt:               Default event channel that the signal is to be measured by E [0,512).
 *  \param[in]   ANAdr:               Signals address (32 bits).
 *  \param[in]   ANExt:               Signals address extension (8 bits).
 *  \param[in]   ANType:              Signals data type E VX1000_MEAS_DATA_{UBYTE, SBYTE, UWORD, SWORD, ULONG, SLONG,
 *                                    A_UINT64, A_INT64, FLOAT32_IEEE, FLOAT64_IEEE, BLOB}.
 *  \param[in]   ANArrayCnt:          Zero for scalars / the element count if the signal is an array.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-278571
 *  \ingroup     A2L
 *********************************************************************************************************************/
#   define   VX1000If_MeasAddSigName                 VX1000IF_IMPL_VOID(MEAS_ADD_SIGNAL_NAME)

/**********************************************************************************************************************
 *  VX1000If_MeasAddSigEnumId()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_MeasAddSigEnumId(uint32 AID, uint32 AIEvt, uint32 AIAdr, uint32 AIExt, uint32 AIType, uint32 AIArrayCnt)
 *  \brief       Macro to add a single signal description of a standard type to the measurement configuration.
 *  \details     Data is appended by a copy operation to RAM.
 *  \param[in]   AID:                 32bit ID that is used by the tool to look up the signals name on the PC.
 *  \param[in]   AIEvt:               Default event channel that the signal is to be measured by E [0,512).
 *  \param[in]   AIAdr:               Signals address (32 bits).
 *  \param[in]   AIExt:               Signals address extension (8 bits).
 *  \param[in]   AIType:              Signals data type E VX1000_MEAS_DATA_{UBYTE, SBYTE, UWORD, SWORD, ULONG, SLONG,
 *                                    A_UINT64, A_INT64, FLOAT32_IEEE, FLOAT64_IEEE, BLOB}.
 *  \param[in]   AIArrayCnt:          Zero for scalars / the element count if the signal is an array.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-278572
 *  \ingroup     A2L
 *********************************************************************************************************************/
#   define   VX1000If_MeasAddSigEnumId               VX1000IF_IMPL_VOID(MEAS_ADD_SIGNAL_ENUMID)

/**********************************************************************************************************************
 *  VX1000If_MeasTypedefInst()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_MeasTypedefInst(const uint8* TIName, const uint8* TITypeName, uint32 TIEvt, uint32 TIAdr, uint32 TIExt, uint32 TIArrayCnt)
 *  \brief       Macro to add a named instance of a user-defined type to the signal measurement list.
 *  \details     Data is appended by a copy operation to RAM.
 *  \param[in]   TIName:              Pointer to an ASCIIZ string holding the instances name.
 *  \param[in]   TITypeName:          Pointer to an ASCIIZ string holding the instances structure/typedef name.
 *  \param[in]   TIEvt:               Default event channel that the signal is to be measured by E [0,512).
 *  \param[in]   TIAdr:               Signals address (32 bits).
 *  \param[in]   TIExt:               Signals address extension (8 bits).
 *  \param[in]   TIArrayCnt:          Zero for scalars / the element count if the signal is an array.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-278573
 *  \ingroup     A2L
 *********************************************************************************************************************/
#   define   VX1000If_MeasTypedefInst                VX1000IF_IMPL_VOID(MEAS_TYPEDEF_INST)

/**********************************************************************************************************************
 *  VX1000If_MeasTypedefInstId()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_MeasTypedefInstId(uint32 TIID, const uint8* TIITypeName, uint32 TIIEvt, uint32 TIIAdr, uint32 TIIExt, uint32 TIIArrayCnt)
 *  \brief       Macro to add an instance of a user-defined type to the signal measurement list by ID.
 *  \details     Data is appended by a copy operation to RAM.
 *  \param[in]   TIID:                32bit ID that is used by the tool to look up the signals name on the PC.
 *  \param[in]   TIITypeName:         Pointer to an ASCIIZ string holding the instances structure/typedef name.
 *  \param[in]   TIIEvt:              Default event channel that the signal is to be measured by E [0,512).
 *  \param[in]   TIIAdr:              Signals address (32 bits).
 *  \param[in]   TIIExt:              Signals address extension (8 bits).
 *  \param[in]   TIIArrayCnt:         Zero for scalars / the element count if the signal is an array.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-278574
 *  \ingroup     A2L
 *********************************************************************************************************************/
#   define   VX1000If_MeasTypedefInstId              VX1000IF_IMPL_VOID(MEAS_TYPEDEF_INST_ID)

/**********************************************************************************************************************
 *  VX1000If_MeasTypedefBegin()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_MeasTypedefBegin(const uint8* TBName, uint8 TBPad, uint32 TBStructSize)
 *  \brief       Macro to begin the definition of a typedef.
 *  \details     Data is appended by a copy operation to RAM.
 *  \param[in]   TBName:              Pointer to an ASCIIZ string holding the typedefs name.
 *  \param[in]   TBPad:               Alignment of the structure elements: 0 (none/"packed structure"), 1 (WORD), 2 (LONG),
 *                                    3 (INT64), 4 (16 bytes), 5 (32 bytes), 6 (64 bytes), 7 (128 bytes).
 *  \param[in]   TBStructSize:        Total size of the structure in bytes (including substructures and padding).
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-278575
 *  \ingroup     A2L
 *********************************************************************************************************************/
#   define   VX1000If_MeasTypedefBegin               VX1000IF_IMPL_VOID(MEAS_TYPEDEF_BEGIN)

/**********************************************************************************************************************
 *  VX1000If_MeasTypedefAdd()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_MeasTypedefAdd(const uint8* TAName, uint8 TAType, uint32 TAOffset, uint32 TAArrayCnt)
 *  \brief       Macro to add a new element of a built-in data type to the currently open typedef.
 *  \details     Data is appended by a copy operation to RAM.
 *  \param[in]   TAName:              Pointer to an ASCIIZ string holding the elements name.
 *  \param[in]   TAType:              Data type of the added member variable E VX1000_MEAS_DATA_{UBYTE, SBYTE, UWORD,
 *                                    SWORD, ULONG, SLONG, A_UINT64, A_INT64, FLOAT32_IEEE, FLOAT64_IEEE, BLOB}
 *  \param[in]   TAOffset:            The offset of the element from the typedefs base address or VX1000_MEAS_AUTO_OFFSET
 *                                    for automatic calculation.
 *  \param[in]   TAArrayCnt:          Zero for scalars / the element count if the signal is an array.
 *  \pre         VX1000If_MeasTypedefBegin() must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-278576
 *  \ingroup     A2L
 *********************************************************************************************************************/
#   define   VX1000If_MeasTypedefAdd                 VX1000IF_IMPL_VOID(MEAS_TYPEDEF_ADD)

/**********************************************************************************************************************
 *  VX1000If_MeasTypedefAddSt()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_MeasTypedefAddSt(const uint8* TASName, const uint8* TASTypeName, uint32 TASOffset, uint32 TASArrayCnt)
 *  \brief       Macro to add a new element (complete struct of user-defined type) to the currently open typedef.
 *  \details     Data is appended by a copy operation to RAM.
 *  \param[in]   TASName:             Pointer to an ASCIIZ string holding the elements name.
 *  \param[in]   TASTypeName:         Pointer to an ASCIIZ string holding the elements structure/typedef name.
 *  \param[in]   TASOffset:           The offset of the element from the typedefs base address or VX1000_MEAS_AUTO_OFFSET
 *                                    for automatic calculation.
 *  \param[in]   TASArrayCnt:         Zero for scalars / the element count if the signal is an array.
 *  \pre         VX1000If_MeasTypedefBegin() must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-278577
 *  \ingroup     A2L
 *********************************************************************************************************************/
#   define   VX1000If_MeasTypedefAddSt               VX1000IF_IMPL_VOID(MEAS_TYPEDEF_ADD_ST)

/**********************************************************************************************************************
 *  VX1000If_MeasTypedefEnd()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_MeasTypedefEnd(void)
 *  \brief       Macro to end the definition of a typedef
 *  \details     Data is appended by a copy operation to RAM.
 *  \pre         VX1000If_MeasTypedefBegin() must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-278578
 *  \ingroup     A2L
 *********************************************************************************************************************/
#   define   VX1000If_MeasTypedefEnd                 VX1000IF_IMPL_VOID(MEAS_TYPEDEF_END)

/********************** A2L API END **********************************************************************************/

/********************** Generic Hooking Control BEGIN ****************************************************************/

/**********************************************************************************************************************
 *  VX1000If_HookTrigger() / VX1000If_HookTriggerVoid()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_HookTrigger(uint16 HookID)
 *  \fn          void VX1000If_HookTriggerVoid(uint16 HookID)
 *  \brief       Macros to trigger a generic bypass whose event IDs are related to HookID.
 *  \details     Makes the VX1000 device driver trigger a generic bypass whose event IDs are related to HookID.
 *  \param[in]   HookID:              Hook id range
 *  \return      0 - inactive bypass or active bypass and original code enabled
 *               1 - bypass active and original code disabled
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-821
 *  \ingroup     GenHookCtrl
 *********************************************************************************************************************/
#   define   VX1000If_HookTrigger                    VX1000IF_IMPL(HOOK_TRIGGER             , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_HookTriggerVoid                VX1000IF_IMPL_VOID(HOOK_TRIGGER_VOID)

/**********************************************************************************************************************
 *  VX1000If_HookWait() / VX1000If_HookWaitVoid()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_HookWait(uint16 HookID, uint32 timeout_us)
 *  \fn          void VX1000If_HookWaitVoid(uint16 HookID, uint32 timeout_us)
 *  \brief       Macros to trigger with timeout for a generic bypass whose event IDs are related to HookID.
 *  \details     Makes the VX1000 device driver stimulate with timeout for a generic bypass whose event IDs are related to
 *               HookID. Optionally, an additional DAQ event will be triggered.
 *  \param[in]   HookID:              Hook id range
 *  \param[in]   timeout_us:          Timeout in microseconds, starting with the function call
 *  \return      0 - bypass inactive
 *               1 - stimulation done, no timeout, OK
 *               2 - stimulation not done, timeout
 *               3 - stimulation not done, timeout, execute original code
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-822
 *  \ingroup     GenHookCtrl
 *********************************************************************************************************************/
#   define   VX1000If_HookWait                       VX1000IF_IMPL(HOOK_WAIT                , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_HookWaitVoid                   VX1000IF_IMPL_VOID(HOOK_WAIT_VOID)

/**********************************************************************************************************************
 *  VX1000If_GenericEvent()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_GenericEvent(uint16 HookID)
 *  \brief       Macro to trigger a generic event whose event ID is related to HookID.
 *  \details     Makes the VX1000 device driver trigger a generic event whose event ID is related to hook_id.
 *  \param[in]   HookID:              Hook id range
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-823
 *  \ingroup     GenHookCtrl
 *********************************************************************************************************************/
#   define   VX1000If_GenericEvent                   VX1000IF_IMPL_VOID(GENERIC_EVENT)

/**********************************************************************************************************************
 *  VX1000If_Hook()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_Hook(uint16 HookID, uint32 timeout_us, code)
 *  \brief       Macro to trigger a generic event whose event ID is related to HookID.
 *  \details     Makes the VX1000 device driver trigger a generic bypass for STIM events with VX1000 hooks, then wait
 *               until the data set requests of this generic bypass are finished successfully and then trigger a DAQ event or
 *               in case of inactive hook or failed stimulation to execute user code without triggering the DAQ event.
 *  \param[in]   HookID:              Hook id range as configured in the VX1000 device driver
 *  \param[in]   timeout_us:          Timeout in microseconds, starting with the function call
 *  \param[in]   code:                User code to be executed in case of failed stimulation or inactive hook.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-838
 *  \ingroup     GenHookCtrl
 *********************************************************************************************************************/
#   define   VX1000If_Hook                           VX1000IF_IMPL_VOID(HOOK)

/********************** Generic Hooking Control END ******************************************************************/

/********************** Hook based bypassing macros  BEGIN ***********************************************************/

/**********************************************************************************************************************
 *  VX1000If_BypassHbbGetval<8,16,32,64,Float,Double> ()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_BypassHbbGetval8(uint16 HookID, uint8 default)
 *  \fn          void VX1000If_BypassHbbGetval16(uint16 HookID, uint16 default)
 *  \fn          void VX1000If_BypassHbbGetval32(uint16 HookID, uint32 default)
 *  \fn          void VX1000If_BypassHbbGetval64(uint16 HookID, uint64 default)
 *  \fn          void VX1000If_BypassHbbGetvalFloat(uint16 HookID, float32 default)
 *  \fn          void VX1000If_BypassHbbGetvalDouble(uint16 HookID, float64 default)
 *  \brief       Macros to check whether valid data is present in the buffer.
 *  \details     Makes the VX1000 device driver check whether valid data corresponding to the given Hook ID is present in
 *               the buffer.
 *  \param[in]   HookID:              HBB id range as configured in the VX1000 device driver
 *  \param[in]   DefaultValue:        Specifies the default value to be returned if hook is not valid.
 *  \return      Data corresponding to the stimulated value, if hook is valid, data available and
 *               VX1000If_IsVX1000DriverAccessEnabled returned TRUE.
 *               Otherwise DefaultValue is returned.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-824
 *  \ingroup     HookBasedBypassing
 *********************************************************************************************************************/
/* PRQA S 3453 FUNCTIONLIKEMACRO */ /* MD_MSR_FctLikeMacro */
#   define   VX1000If_BypassHbbGetval8(H, D)        VX1000IF_IMPL(BYPASS_HBB_GETVAL_8,       (D))((H), D)
#   define   VX1000If_BypassHbbGetval16(H, D)       VX1000IF_IMPL(BYPASS_HBB_GETVAL_16,      (D))((H), D)
#   define   VX1000If_BypassHbbGetval32(H, D)       VX1000IF_IMPL(BYPASS_HBB_GETVAL_32,      (D))((H), D)
#   define   VX1000If_BypassHbbGetval64(H, D)       VX1000IF_IMPL(BYPASS_HBB_GETVAL_64,      (D))((H), D)
#   define   VX1000If_BypassHbbGetvalFloat(H, D)    VX1000IF_IMPL(BYPASS_HBB_GETVAL_FLOAT,   (D))((H), D)
#   define   VX1000If_BypassHbbGetvalDouble(H, D)   VX1000IF_IMPL(BYPASS_HBB_GETVAL_DOUBLE,  (D))((H), D)
/* PRQA L:FUNCTIONLIKEMACRO */ /* MD_MSR_FctLikeMacro */

/********************** Hook based bypassing macros  END *************************************************************/

/********************** VX1000 Mailbox BEGIN *************************************************************************/

/**********************************************************************************************************************
 *  VX1000If_MailboxControl()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_BypassHbbGetval8(void)
 *  \brief       Macro to check the VX1000 mailbox system for pending requests
 *  \details     Makes the VX1000 device driver check the VX1000 mailbox for pending requests and trigger necessary
 *               actions.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        This function must not be interrupted by any VX1000 mailbox read function.
 *               This function must not interrupt any VX1000 mailbox read function.
 *  \trace       CREQ-825
 *  \ingroup     Mailbox
 *********************************************************************************************************************/
#   define   VX1000If_MailboxControl                 VX1000IF_IMPL_VOID(MAILBOX_CONTROL)

/**********************************************************************************************************************
 *  VX1000If_MailboxWrite() / VX1000If_MailboxWriteVoid()
 *********************************************************************************************************************/
/*! \fn          uint32 VX1000If_MailboxWrite(uint16 len, const uint8* pBuf)
 *  \fn          void VX1000If_MailboxWriteVoid(uint16 len, const uint8* pBuf)
 *  \brief       Macros to write to the Slave->Master mailbox and notify the master.
 *  \details     Makes the VX1000 device driver write len bytes from pBuf to the Slave->Master mailbox and notify the
 *               master.
 *  \param[in]   len:                 Specifies the message size in bytes.
 *  \param[in]   pBuf:                Specifies the pointer to message data input.
 *  \return      VX1000_MAILBOX_OK       - mailbox transfer successful
 *               VX1000_MAILBOX_ERR_FULL - error: no free mailbox slots available
 *               VX1000_MAILBOX_ERR_NULL - error: pBuf is null pointer
 *               VX1000_MAILBOX_ERR_SIZE - error: len exceeds mailbox slot size
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        This function must not be interrupted by any VX1000 mailbox write function.
 *               This function must not interrupt any VX1000 mailbox write function.
 *  \trace       CREQ-826
 *  \ingroup     Mailbox
 *********************************************************************************************************************/
#   define   VX1000If_MailboxWrite                   VX1000IF_IMPL(MAILBOX_WRITE            , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_MailboxWriteVoid               VX1000IF_IMPL_VOID(MAILBOX_WRITE_VOID)

/**********************************************************************************************************************
 *  VX1000If_MailboxWriteSplit() / VX1000If_MailboxWriteSplitVoid()
 *********************************************************************************************************************/
/*! \fn          uint32 VX1000If_MailboxWriteSplit(uint32** ppBuf, uint32 minimum, uint32* idealGot)
 *  \fn          void VX1000If_MailboxWriteSplitVoid(uint32** ppBuf, uint32 minimum, uint32* idealGot)
 *  \brief       Macros to find out the location of the next unused message buffer
 *  \details     Makes the VX1000 device driver obtain a pointer within the ECU -> VX1000 mailbox queue at which the
 *               next (raw) message may be written.
 *               The mailbox state remains unchanged in order to prevent the VX1000 from consuming the message before it
 *               is completely written and submitted via a call to VX1000If_MailboxWriteDone.
 *  \param[in,out] ppBuf:             Pointer within the ECU -> VX1000 mailbox queue at which the next (raw) message
 *                                    may be written.
 *  \param[in]     minimum:           The minimum number of bytes required to be available in the buffer requested.
 *  \param[in,out] idealGot:          Pointer holding the maximum allowed message size.
 *                                    The value is overwritten with number of bytes actually available in the buffer provided.
 *  \return      VX1000_MAILBOX_OK             - mailbox transfer successful
 *               VX1000_MAILBOX_ERR_SPLIT_PEND - repeated call to VX1000If_MailboxWriteSplit / VX1000If_MailboxWriteSplitVoid;
 *                                               call VX1000If_MailboxWriteDone() / VX1000If_MailboxWriteDoneVoid() first!
 *               VX1000_MAILBOX_ERR_NULL       - argument ppBuf is NULL
 *               VX1000_MAILBOX_ERR_ZERO       - argument minimum is < 1
 *               VX1000_MAILBOX_ERR_SIZE       - argument idealGot is < minimum or argument idealGot is bigger than the largest
 *                                               message that possibly fits into the mailbox queue.
 *               VX1000_MAILBOX_ERR_FULL       - mailbox queue is already full
 *               VX1000IF_RET_E_NOT_OK         - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        This function must not be interrupted by any VX1000 mailbox read function.
 *               This function must not interrupt any VX1000 mailbox read function.
 *  \trace       CREQ-827
 *  \ingroup     Mailbox
 *********************************************************************************************************************/
#   define   VX1000If_MailboxWriteSplit              VX1000IF_IMPL(MAILBOX_WRITESPLIT       , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_MailboxWriteSplitVoid          VX1000IF_IMPL_VOID(MAILBOX_WRITESPLIT_VOID)

/**********************************************************************************************************************
 *  VX1000If_MailboxWriteDone() / VX1000If_MailboxWriteDoneVoid()
 *********************************************************************************************************************/
/*! \fn          uint32 VX1000If_MailboxWriteDone(uint32 len)
 *  \fn          void VX1000If_MailboxWriteDoneVoid(uint32 len)
 *  \brief       Macros to Finish a Slave->Master mailbox transfer.
 *  \details     Makes the VX1000 device driver Submit a message to the ECU -> VX1000 mailbox queue after writing to
 *               the buffer obtained from VX1000If_MailboxWriteSplit.
 *  \param[in]   len:                 The actual size in bytes of the message written into the buffer.
 *                                    If len == 0, then the number of bytes is equal to the value contained in idealGot
 *                                    upon return from VX1000If_MailboxWriteSplit.
 *  \return      VX1000_MAILBOX_OK             - mailbox transfer successful
 *               VX1000_MAILBOX_ERR_SPLIT_PEND - call to VX1000If_MailboxWriteDone / VX1000If_MailboxWriteDoneVoid without
 *                                               a prior call to VX1000If_MailboxWriteSplit / VX1000If_MailboxWriteSplitVoid.
 *               VX1000_MAILBOX_ERR_SIZE2      - argument len > *idealGot from prior call to VX1000If_MailboxWriteSplit /
 *                                               VX1000If_MailboxWriteSplitVoid
 *               VX1000IF_RET_E_NOT_OK         - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        This function must not be interrupted by any VX1000 mailbox write function.
 *               This function must not interrupt any VX1000 mailbox write function.
 *  \trace       CREQ-828
 *  \ingroup     Mailbox
 *********************************************************************************************************************/
#   define   VX1000If_MailboxWriteDone               VX1000IF_IMPL(MAILBOX_WRITEDONE        , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_MailboxWriteDoneVoid           VX1000IF_IMPL_VOID(MAILBOX_WRITEDONE_VOID)

/**********************************************************************************************************************
 *  VX1000If_MailboxRead() / VX1000If_MailboxReadVoid()
 *********************************************************************************************************************/
/*! \fn          uint32 VX1000If_MailboxRead(uint32* pLen, uint8* pBuf)
 *  \fn          void VX1000If_MailboxReadVoid(uint32* pLen, uint8* pBuf)
 *  \brief       Macros to read the data from next filled Master->Slave mailbox slot.
 *  \details     Makes the VX1000 device driver read the data from the next filled Master->Slave mailbox slot into pBuf
 *               and return the number of bytes in pLen.
 *  \param[in,out]   pLen:            Pointer holding the maximum allowed message size.
 *                                    The value is overwritten with the actual message size if successful.
 *  \param[in,out]   pBuf:            Pointer to destination for the next message.
 *                                    The caller is responsible that the destination contains at least *pLen writeable bytes.
 *                                    The function aborts with an error if the buffer is too small for the current message
 *                                    (no bytes copied).
 *                                    pBuf holds a copy of the entire message if successful.
 *  \return      VX1000_MAILBOX_OK             - mailbox transfer successful
 *               VX1000_MAILBOX_ERR_EMPTY      - error: mailbox is empty
 *               VX1000_MAILBOX_ERR_NULL       - error: pLen or pBuf are null pointers
 *               VX1000_MAILBOX_ERR_SIZE       - error: mailbox slot content exceeds pLen
 *               VX1000_MAILBOX_ERR_SPLIT_PEND - error: split read transaction pending
 *               VX1000IF_RET_E_NOT_OK         - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        This function must not be interrupted by any VX1000 mailbox read function.
 *               This function must not interrupt any VX1000 mailbox read function.
 *  \trace       CREQ-829
 *  \ingroup     Mailbox
 *********************************************************************************************************************/
#   define   VX1000If_MailboxRead                    VX1000IF_IMPL(MAILBOX_READ             , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_MailboxReadVoid                VX1000IF_IMPL_VOID(MAILBOX_READ_VOID)

/**********************************************************************************************************************
 *  VX1000If_MailboxReadSplit() / VX1000If_MailboxReadSplitVoid()
 *********************************************************************************************************************/
/*! \fn          uint32 VX1000If_MailboxReadSplit(uint32* pLen, uint8** ppBuf)
 *  \fn          void VX1000If_MailboxReadSplitVoid(uint32* pLen, uint8** ppBuf)
 *  \brief       Macros to find out the location and length of the next unread message.
 *  \details     Makes the VX1000 device driver return the location and length of the next unread mailbox message.
 *               Note: the mailbox state is not changed nor is the master notified.
 *               VX1000If_MailboxReadDone must be called to complete the transaction.
 *  \param[out]  pLen:                Pointer to a 32bit variable.
 *                                    The value is overwritten with the byte count of the next message if successful.
 *                                    The caller is responsible that the pointer is valid and that the destination is writeable.
 *  \param[in,out]   pBuf:            Pointer to the data field of the next unread message.
 *                                    The caller is responsible that the pointer is valid and that the destination is writeable.
 *  \return      VX1000_MAILBOX_OK             - mailbox transfer successful
 *               VX1000_MAILBOX_ERR_NULL       - argument pBuf or argument pLen is NULL
 *               VX1000_MAILBOX_ERR_EMPTY      - mailbox queue is empty
 *               VX1000_MAILBOX_ERR_SPLIT_PEND - repeated call to to VX1000If_MailboxReadSplit / VX1000If_MailboxReadSplitVoid;
 *                                               call VX1000If_MailboxReadDone() / VX1000If_MailboxReadDoneVoid() first!
 *               VX1000_MAILBOX_ERR_MAGIC      - message in mailbox queue is corrupted (unmagic start)
 *               VX1000_MAILBOX_ERR_FATAL      - message in mailbox queue is corrupted (unmagic end or impossible length)
 *               VX1000IF_RET_E_NOT_OK         - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        This function must not be interrupted by any VX1000 mailbox read function.
 *               This function must not interrupt any VX1000 mailbox read function.
 *  \trace       CREQ-830
 *  \ingroup     Mailbox
 *********************************************************************************************************************/
#   define   VX1000If_MailboxReadSplit               VX1000IF_IMPL(MAILBOX_READSPLIT        , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_MailboxReadSplitVoid           VX1000IF_IMPL_VOID(MAILBOX_READSPLIT_VOID)

/**********************************************************************************************************************
 *  VX1000If_MailboxReadDone() / VX1000If_MailboxReadDoneVoid()
 *********************************************************************************************************************/
/*! \fn          uint32 VX1000If_MailboxReadDone(void)
 *  \fn          void VX1000If_MailboxReadDoneVoid(void)
 *  \brief       Macros to mark the filled Master->Slave mailbox slot as empty
 *  \details     Makes the VX1000 device driver mark the Master->Slave mailbox slot for the pending read transaction as
 *               empty and notify the master afterwards.
 *  \return      VX1000_MAILBOX_OK             - mailbox transfer successful
 *               VX1000_MAILBOX_ERR_SPLIT_PEND - call to VX1000If_MailboxReadDone / VX1000If_MailboxReadDoneVoid without
 *                                               a prior call to VX1000If_MailboxReadSplit() / VX1000If_MailboxReadSplitVoid() first!
 *               VX1000IF_RET_E_NOT_OK         - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_MailboxReadSplit and VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        This function must not be interrupted by any VX1000 mailbox read function.
 *               This function must not interrupt any VX1000 mailbox read function.
 *  \trace       CREQ-831
 *  \ingroup     Mailbox
 *********************************************************************************************************************/
#   define   VX1000If_MailboxReadDone                VX1000IF_IMPL(MAILBOX_READDONE         , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_MailboxReadDoneVoid            VX1000IF_IMPL_VOID(MAILBOX_READDONE_VOID)

/********************** VX1000 Mailbox END ***************************************************************************/

/********************** VX1000 Overlay BEGIN *************************************************************************/

/**********************************************************************************************************************
 *  VX1000If_OvlSetConfig() / VX1000If_OvlSetConfigVoid()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_OvlSetConfig(uint32 value, uint32 mask, uint8 page, uint32 master, uint32 calMaster)
 *  \fn          void VX1000If_OvlSetConfigVoid(uint32 value, uint32 mask, uint8 page, uint32 master, uint32 calMaster)
 *  \brief       Macros to globally enable/disable overlays
 *  \details     Makes the VX1000 device driver execute a derivative-specific method to globally enable/disable overlays.
 *  \param[in]   value:               Overlay windows to be activated/deactivated
 *  \param[in]   mask:                Resource Mask
 *  \param[in]   page:                Overlay Page
 *  \param[in]   master:              Masters to be activated
 *  \param[in]   calMaster:           Masters resource Mask
 *  \return      0 - Nothing done
 *               1 - Page switch done
 *               2 - Value not written correctly
 *               3 - No single-master page-switch possible
 *               4 - Generic error
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The VX1000 device driver assumes exclusive ownership of the overlay unit.
 *  \trace       CREQ-832
 *  \ingroup     Overlay
 *********************************************************************************************************************/
#   define   VX1000If_OvlSetConfig                  VX1000IF_IMPL(OVL_SET_CONFIG           , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_OvlSetConfigVoid              VX1000IF_IMPL_VOID(OVL_SET_CONFIG_VOID)

/**********************************************************************************************************************
 *  VX1000If_OvlSetConfigDone() / VX1000If_OvlSetConfigDoneVoid()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_OvlSetConfigDone(uint32 value, uint32 mask, uint8 page, uint32 master, uint32 calMaster)
 *  \fn          void VX1000If_OvlSetConfigDoneVoid(uint32 value, uint32 mask, uint8 page, uint32 master, uint32 calMaster)
 *  \brief       Macros to transmit the status of a page switching attempt to the VX1000 driver
 *  \details     Transmits the status of a page switching attempt to the VX1000 driver and optionally also to the XCP tool.
 *  \param[in]   value:               Overlay windows to be activated/deactivated
 *  \param[in]   mask:                Resource Mask
 *  \param[in]   page:                Overlay Page
 *  \param[in]   master:              Masters to be activated
 *  \param[in]   calMaster:           Masters resource Mask
 *  \return      0 - Nothing done
 *               1 - Page switch done
 *               2 - Value not written correctly
 *               3 - No single-master page-switch possible
 *               4 - Generic error
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The VX1000 device driver assumes exclusive ownership of the overlay unit.
 *  \trace       CREQ-864
 *  \ingroup     Overlay
 *********************************************************************************************************************/
#   define   VX1000If_OvlSetConfigDone             VX1000IF_IMPL_VOID(OVL_SET_CONFIG_DONE)
#   define   VX1000If_OvlSetConfigDoneVoid         VX1000IF_IMPL_VOID(OVL_SET_CONFIG_DONE_STUP)

/**********************************************************************************************************************
 *  VX1000If_OvlChkPageSwDone() / VX1000If_OvlChkPageSwDoneVoid()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_OvlChkPageSwDone(void)
 *  \fn          void VX1000If_OvlChkPageSwDoneVoid(void)
 *  \brief       Macros to check page switching status of all bus masters for which a page switch was requested.
 *  \details     Makes the VX1000 driver check and finalize page switching status of all bus masters for which a page
 *               switch was requested.
 *  \return      0 - Nothing done
 *               1 - Page switch done
 *               2 - Value not written correctly
 *               3 - No single-master page-switch possible
 *               4 - Generic error
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The VX1000 device driver assumes exclusive ownership of the overlay unit.
 *  \trace       CREQ-865
 *  \ingroup     Overlay
 *********************************************************************************************************************/
#   define   VX1000If_OvlChkPageSwDone             VX1000IF_IMPL(OVL_CHK_PAGESW_DONE      , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_OvlChkPageSwDoneVoid         VX1000IF_IMPL_VOID(OVL_CHK_PAGESW_DONE_VOID)

/**********************************************************************************************************************
 *  VX1000If_OvlChkPageSwCore() / VX1000If_OvlChkPageSwCoreVoid()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_OvlChkPageSwCore(uint32 master)
 *  \fn          void VX1000If_OvlChkPageSwCoreVoid(uint32 master)
 *  \brief       Macros to check page switching status of a specific bus master
 *  \details     Makes the VX1000 driver check the page switching status of a specific bus master.
 *  \param[in]   master:              bus master to be checked
 *  \return      0 - Nothing done
 *               1 - Page switch done
 *               2 - Value not written correctly
 *               3 - No single-master page-switch possible
 *               4 - Generic error
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The VX1000 device driver assumes exclusive ownership of the overlay unit.
 *  \trace       CREQ-866
 *  \ingroup     Overlay
 *********************************************************************************************************************/
#   define   VX1000If_OvlChkPageSwCore             VX1000IF_IMPL(OVL_CHK_PAGESW_CORE      , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_OvlChkPageSwCoreVoid         VX1000IF_IMPL_VOID(OVL_CHK_PAGESW_CORE_VOID)

/**********************************************************************************************************************
 *  VX1000If_OvlIsPageSwRequested()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_OvlIsPageSwRequested(uint32 master)
 *  \brief       Macros to check whether a page switch request is pending for a bus master
 *  \details     Makes the VX1000 driver check whether a page switch request is pending for a bus master or not.
 *  \param[in]   master:              bus master to be checked
 *  \return      0 - Page switch is not pending
 *               1 - Page switch is pending
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The VX1000 device driver assumes exclusive ownership of the overlay unit.
 *  \trace       CREQ-867
 *  \ingroup     Overlay
 *********************************************************************************************************************/
#   define   VX1000If_OvlIsPageSwRequested         VX1000IF_IMPL(OVL_IS_PAGESW_REQUESTED  , VX1000IF_RET_E_NOT_OK)

/**********************************************************************************************************************
 *  VX1000If_OvlGetStatus()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_OvlGetStatus(uint8* workingPageStatus, uint8* selectedPage);
 *  \brief       Macros to check the current overlay status.
 *  \details     Makes the VX1000 driver check the current overlay status.
 *  \param[out]  workingPageStatus:         0x0: returning working page has some context as flash Page.
 *                                          0x1: working page has same content as flash Page
 *                                          0x2: working page has been modified at least once
 *  \param[out]  selectedPage:              0x0: Flash/Reference Page
 *                                          0x1: RAM/Working Page
 *                                          0xFF: unknown or page switching is deaktivated
 *  \return      0 - Success
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        If the application wants to detect whether some modifications have took place during runtime the API 
 *               has to be called cyclically.
 *               If after multiple modifications the working page is the same as the reference page, working page will 
 *               be reported. If the working page is reset via XCP copy cal page this is reflected in the status 
 *               returning working page has some context as Flash Page.
 *  \trace       CREQ-OvlGetStatus
 *  \ingroup     Overlay
 *********************************************************************************************************************/
#   define   VX1000If_OvlGetStatus                 VX1000IF_IMPL(OVERLAY_GET_STATUS  , VX1000IF_RET_E_NOT_OK)

/**********************************************************************************************************************
 *  VX1000If_InvalidateEmem()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_InvalidateEmem(void)
 *  \brief       Macros to invalidate the signature of the VX1000-allocated persistent ECU-RAM
 *  \details     Invalidate the signature of the VX1000-allocated persistent ECU-RAM.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The VX1000 device driver assumes exclusive ownership of the overlay unit.
 *  \trace       CREQ-868
 *  \ingroup     Overlay
 *********************************************************************************************************************/
#   define   VX1000If_InvalidateEmem               VX1000IF_IMPL_VOID(INVALIDATE_EMEM)

/**********************************************************************************************************************
 *  VX1000If_CalGetStatus()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_CalGetStatus(void);
 *  \brief       Macros to check whether the user has modified the ECU in some manner.
 *  \details     Makes the VX1000 driver check whether the user has modified the ECU in some manner.
 *               Modifications of non-Overlay variables are recorded here.
 *               Typically these modifications are triggered by XCP download commands.
 *  \return      0 - No user modification has took place
 *               1 - User modification has took place
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Modifications by reading system variables with XCP upload commands are not taken into account here.
 *               Modifications done by the VX1000 for the purpose of measurement are not taken into account here.
 *               Use the functions VX1000If_DaqGetStatus and VX1000If_DeviceDetected to get information about the VX1000.
 *  \trace       CREQ-867
 *  \ingroup     Overlay
 *********************************************************************************************************************/
#   define   VX1000If_CalGetStatus                 VX1000IF_IMPL(CAL_GET_STATUS  , VX1000IF_RET_E_NOT_OK)

/**********************************************************************************************************************
 *  VX1000If_CalWakeupRequested()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_CalWakeupRequested(void)
 *  \brief       Macros to check whether the XCP tool requested a wakeup for calibration purposes or not.
 *  \details     Makes the VX1000 driver check whether the XCP tool has requested a wakeup for calibration purposes.
 *  \return      0 - No request pending
 *               1 - Request pending
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The VX1000 device driver assumes exclusive ownership of the overlay unit.
 *  \trace       CREQ-869
 *  \ingroup     Overlay
 *********************************************************************************************************************/
#   define   VX1000If_CalWakeupRequested           VX1000IF_IMPL(CAL_WAKEUP_REQUESTED     , VX1000IF_RET_E_NOT_OK)

/**********************************************************************************************************************
 *  VX1000If_IsCalWakeupActive()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_IsCalWakeupActive(void)
 *  \brief       Macros to check whether the ECU must stay awake for calibration purposes or not.
 *  \details     Makes the VX1000 driver check whether the ECU must stay awake for calibration purposes or not.
 *  \return      0 - ECU must not stay awake
 *               1 - ECU must stay awake
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The VX1000 device driver assumes exclusive ownership of the overlay unit.
 *  \trace       CREQ-870
 *  \ingroup     Overlay
 *********************************************************************************************************************/
#   define   VX1000If_IsCalWakeupActive            VX1000IF_IMPL(IS_CAL_WAKEUP_ACTIVE     , VX1000IF_RET_E_NOT_OK)
/********************** VX1000 Overlay END ***************************************************************************/

/********************** VX1000 Resource Management BEGIN *************************************************************/

/**********************************************************************************************************************
 *  VX1000If_EnableAccess()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_EnableAccess(void)
 *  \brief       Macro to enable the VX1000 tool access.
 *  \details     Makes the VX1000 driver enable the VX1000 tool access.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-833
 *  \ingroup     ResM
 *********************************************************************************************************************/
#   define   VX1000If_EnableAccess                 VX1000IF_IMPL_VOID(ENABLE_ACCESS)

/**********************************************************************************************************************
 *  VX1000If_DisableAccess() / VX1000If_DisableAccessVoid()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_DisableAccess(void)
 *  \fn          void VX1000If_DisableAccessVoid(void)
 *  \brief       Macro to disable the VX1000 tool access.
 *  \details     Disables the VX1000 tool access.
 *  \return      0 - VX1000 tool access successfully disabled
 *               1 - unable to disable VX1000 tool access
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-834
 *  \ingroup     ResM
 *********************************************************************************************************************/
#   define   VX1000If_DisableAccess                VX1000IF_IMPL(DISABLE_ACCESS           , VX1000IF_RET_E_NOT_OK)
#   define   VX1000If_DisableAccessVoid            VX1000IF_IMPL_VOID(DISABLE_ACCESS_VOID)

/**********************************************************************************************************************
 *  VX1000If_IsAccessDisabled()
 *********************************************************************************************************************/
/*! \fn          boolean VX1000If_IsAccessDisabled(void)
 *  \brief       Macro to check the VX1000 tool access state.
 *  \details     Makes the VX1000 driver check whether the VX1000 tool access is disabled or not.
 *  \return      0 - VX1000 tool access disabled
 *               1 - VX1000 tool access enabled
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-835
 *  \ingroup     ResM
 *********************************************************************************************************************/
#   define   VX1000If_IsAccessDisabled             VX1000IF_IMPL(IS_ACCESS_DISABLED       , VX1000IF_RET_E_NOT_OK)

/********************** VX1000 Resource Management END ***************************************************************/

/********************** VX1000 Copy Offloader BEGIN ******************************************************************/

/**********************************************************************************************************************
 *  VX1000If_CoNext
 *********************************************************************************************************************/
/*! \fn          void VX1000If_CoNext(uint32* CopyJobDescriptionList)
 *  \brief       Advances the provided pointer from the current copy job's description to the next copy job's description.
 *  \details     This function is a macro that reads the size allocated by the VX1000 for one copy job description and 
 *               advances the pointer accordingly to point to the next copy job's description in the list.
 *  \param[in]   CopyJobDescriptionList: Pointer to a measurement-dependent list of copy job descriptions.
 *  \pre         VX1000If_InitAsyncStart should have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-CoNext
 *  \ingroup     CO
 *********************************************************************************************************************/
#   define   VX1000If_CoNext                       VX1000IF_IMPL_VOID(CO_NEXT)

/**********************************************************************************************************************
 *  VX1000If_CoGetDoSrcAddrInc
 *********************************************************************************************************************/
/*! \fn          uint32 VX1000If_CoGetDoSrcAddrInc(uint32* CopyJobDescriptionList)
 *  \brief       Extracts the flag indicating whether the source address is to be incremented after each step
 *               in the referred copy job description.
 *  \details     This function, implemented as a macro, extracts the specific bit from the provided copy job description. 
 *               The bit indicates whether the source address should be incremented after each step. 
 *               The extracted value is then adjusted for direct use in the application's code.
 *  \param[in]   CopyJobDescriptionList: Pointer to a measurement-dependent list of copy job descriptions.
 *  \return      Flag value indicating the requested source address increment behavior if VX1000If_IsVX1000DriverAccessEnabled
 *               returns TRUE. If VX1000If_IsVX1000DriverAccessEnabled returns FALSE, the function returns VX1000IF_RET_E_NOT_OK.
 *  \pre         VX1000If_InitAsyncStart should have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-CoGetDoSrcAddrInc
 *  \ingroup     CO
 *********************************************************************************************************************/
#   define   VX1000If_CoGetDoSrcAddrInc            VX1000IF_IMPL(CO_GET_DO_SRCINC         , ((uint32)(VX1000IF_RET_E_NOT_OK)))

/**********************************************************************************************************************
 *  VX1000If_CoGetDoDstAddrInc
 *********************************************************************************************************************/
/*! \fn          uint32 VX1000If_CoGetDoDstAddrInc(uint32* CopyJobDescriptionList)
 *  \brief       Extracts the flag indicating whether the destination address is to be incremented after each step
 *               in the referred copy job description.
 *  \details     This function, implemented as a macro, extracts the specific bit from the provided copy job description. 
 *               The bit indicates whether the destination address should be incremented after each step. 
 *               The extracted value is then adjusted for direct use in the application's code.
 *  \param[in]   CopyJobDescriptionList: Pointer to a measurement-dependent list of copy job descriptions.
 *  \return      Flag value indicating the requested destination address increment behavior if VX1000If_IsVX1000DriverAccessEnabled
 *               returns TRUE. If VX1000If_IsVX1000DriverAccessEnabled returns FALSE, the function returns VX1000IF_RET_E_NOT_OK.
 *  \pre         VX1000If_InitAsyncStart should have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-CoGetDoDstAddrInc
 *  \ingroup     CO
 *********************************************************************************************************************/
#   define   VX1000If_CoGetDoDstAddrInc             VX1000IF_IMPL(CO_GET_DO_DSTINC         , ((uint32)(VX1000IF_RET_E_NOT_OK)))

/**********************************************************************************************************************
 *  VX1000If_CoGetDstDatatype
 *********************************************************************************************************************/
/*! \fn          uint32 VX1000If_CoGetDstDatatype(uint32* CopyJobDescriptionList)
 *  \brief       Extracts the access type for the destination memory from the referred copy job description.
 *  \details     This function, implemented as a macro, extracts a specific bit field from the provided copy job description. 
 *               The bit field contains information about the access type for the destination memory. 
 *               The extracted value is then adjusted for direct use in the application's code.
 *  \param[in]   CopyJobDescriptionList: Pointer to a measurement-dependent list of copy job descriptions.
 *  \return      Data value indicating the requested access type for the destination memory if VX1000If_IsVX1000DriverAccessEnabled
 *               returns TRUE. If VX1000If_IsVX1000DriverAccessEnabled returns FALSE, the function returns VX1000IF_RET_E_NOT_OK.
 *  \pre         VX1000If_InitAsyncStart should have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-CoGetDstDatatype
 *  \ingroup     CO
 *********************************************************************************************************************/
#   define   VX1000If_CoGetDstDatatype             VX1000IF_IMPL(CO_GET_DST_DATATYPE      , ((uint32)(VX1000IF_RET_E_NOT_OK)))

/**********************************************************************************************************************
 *  VX1000If_CoGetSrcDatatype
 *********************************************************************************************************************/
/*! \fn          uint32 VX1000If_CoGetSrcDatatype(uint32* CopyJobDescriptionList)
 *  \brief       Extracts the access type for the source memory from the referred copy job description.
 *  \details     This function, implemented as a macro, extracts a specific bit field from the provided copy job description. 
 *               The bit field contains information about the access type for the source memory. 
 *               The extracted value is then adjusted for direct use in the application's code.
 *  \param[in]   CopyJobDescriptionList: Pointer to a measurement-dependent list of copy job descriptions.
 *  \return      Data value indicating the requested access type for the source memory if VX1000If_IsVX1000DriverAccessEnabled
 *               returns TRUE. If VX1000If_IsVX1000DriverAccessEnabled returns FALSE, the function returns VX1000IF_RET_E_NOT_OK.
 *  \pre         VX1000If_InitAsyncStart should have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-CoGetSrcDatatype
 *  \ingroup     CO
 *********************************************************************************************************************/
#   define   VX1000If_CoGetSrcDatatype             VX1000IF_IMPL(CO_GET_SRC_DATATYPE      , ((uint32)(VX1000IF_RET_E_NOT_OK)))

/**********************************************************************************************************************
 *  VX1000If_CoGetCopysize
 *********************************************************************************************************************/
/*! \fn          uint32 VX1000If_CoGetCopysize(uint32* CopyJobDescriptionList)
 *  \brief       Extracts the copy size value [bytes] from the referred copy job description.
 *  \details     This function, implemented as a macro, extracts a specific bit field from the provided copy job description. 
 *               The bit field contains the copy size value in bytes. 
 *               The extracted value is then adjusted for direct use in the application's code.
 *  \param[in]   CopyJobDescriptionList: Pointer to a measurement-dependent list of copy job descriptions.
 *  \return      Data value indicating the requested copy size value if VX1000If_IsVX1000DriverAccessEnabled returns TRUE.
 *               If VX1000If_IsVX1000DriverAccessEnabled returns FALSE, the function returns VX1000IF_RET_E_NOT_OK.
 *  \pre         VX1000If_InitAsyncStart should have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-CoGetCopysize
 *  \ingroup     CO
 *********************************************************************************************************************/
#   define   VX1000If_CoGetCopysize                VX1000IF_IMPL(CO_GET_COPYSIZE          , ((uint32)(VX1000IF_RET_E_NOT_OK)))

/**********************************************************************************************************************
 *  VX1000If_CoGetDstAddr
 *********************************************************************************************************************/
/*! \fn          uint32 VX1000If_CoGetDstAddr(uint32* CopyJobDescriptionList)
 *  \brief       Extracts the destination address value from the referred copy job description.
 *  \details     This function, implemented as a macro, extracts a specific bit field from the provided copy job description. 
 *               The bit field contains the destination address value. 
 *               The extracted value is then adjusted for direct use in the application's code.
 *  \param[in]   CopyJobDescriptionList: Pointer to a measurement-dependent list of copy job descriptions.
 *  \return      Data value indicating the requested destination address value if VX1000If_IsVX1000DriverAccessEnabled returns TRUE.
 *               If VX1000If_IsVX1000DriverAccessEnabled returns FALSE, the function returns VX1000IF_RET_E_NOT_OK.
 *  \pre         VX1000If_InitAsyncStart should have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-CoGetDstAddr
 *  \ingroup     CO
 *********************************************************************************************************************/
#   define   VX1000If_CoGetDstAddr                 VX1000IF_IMPL(CO_GET_DESTADDR          , ((uint32)(VX1000IF_RET_E_NOT_OK)))

/**********************************************************************************************************************
 *  VX1000If_CoGetSrcAddr
 *********************************************************************************************************************/
/*! \fn          uint32 VX1000If_CoGetSrcAddr(uint32* CopyJobDescriptionList)
 *  \brief       Extracts the source address value from the referred copy job description.
 *  \details     This function, implemented as a macro, extracts a specific bit field from the provided copy job description. 
 *               The bit field contains the source address value. 
 *               The extracted value is then adjusted for direct use in the application's code.
 *  \param[in]   CopyJobDescriptionList: Pointer to a measurement-dependent list of copy job descriptions.
 *  \return      Data value indicating the requested source address value if VX1000If_IsVX1000DriverAccessEnabled returns TRUE.
 *               If VX1000If_IsVX1000DriverAccessEnabled returns FALSE, the function returns VX1000IF_RET_E_NOT_OK.
 *  \pre         VX1000If_InitAsyncStart should have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-CoGetSrcAddr
 *  \ingroup     CO
 *********************************************************************************************************************/
#   define   VX1000If_CoGetSrcAddr                 VX1000IF_IMPL(CO_GET_SRCADDR           , ((uint32)(VX1000IF_RET_E_NOT_OK)))

/********************** VX1000 Copy Offloader END ********************************************************************/

/********************** VX1000 Data Transfer BEGIN *******************************************************************/

/**********************************************************************************************************************
 *  VX1000If_DataTransferStart
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_DataTransferStart(uint32 DtsTransferType, uint64 DtsTime64, uint32 DtsAddr, uint32 DtsBytes)
 *  \brief       Macro to inform the VX1000 that the ECU is going to transmit the payload data of the selected DAQ type.
 *  \details     Assembles a header in the format of the selected transfer type from the data in the provided parameters
 *               and delivers it to the transmission system.
 *  \param[in]   DtsTransferType:      Selector for the status type of interest, typically 0x01000000.
 *  \param[in]   DtsTime64:            A 64bit timestamp whose low 32 bits must match the value of VX1000_CLOCK().
 *  \param[in]   DtsAddr:              The destination address of the transfer.
 *  \param[in]   DtsBytes:             The size of the transfer in bytes.
 *  \return      0 - function completed normally
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-DataTransferStart
 *  \ingroup     DataTransfer
 *********************************************************************************************************************/
#   define   VX1000If_DataTransferStart            VX1000IF_IMPL(DATATRANSFER_START       , VX1000IF_RET_E_NOT_OK)

/**********************************************************************************************************************
 *  VX1000If_DataTransferFinish
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_DataTransferFinish(uint32 DtfTransferType)
 *  \brief       Macro to optionally transfer a footer to the VX1000 that marks the end of data for the event of the selected type.
 *  \details     Assembles a footer in the format of the selected transfer type from the data remembered from the last
 *               call to VX1000If_DataTransferStart with the same transfer type and delivers it to the transmission system.
 *  \param[in]   DtfTransferType:      Selector for the status type of interest, typically 0x01000000.
 *  \return      0 - function completed normally
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         vx1000_DataTransferStart and VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-DataTransferFinish
 *  \ingroup     DataTransfer
 *********************************************************************************************************************/
#   define   VX1000If_DataTransferFinish           VX1000IF_IMPL(DATATRANSFER_FINISH      , VX1000IF_RET_E_NOT_OK)

/**********************************************************************************************************************
 *  VX1000If_DataTransferGetInfo
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_DataTransferGetInfo(uint32 DtgTransferType, uint32* pDtgDstAddress, uint32* pDtgDstMode)
 *  \brief       Macro to provide the transfer destination attributes of the selected DAQ type.
 *  \details     Reads any transfer information provided by the VX1000 and if details for the selected transfer type
 *               are available it delivers them to the caller and returns 0, otherwise 1.
 *  \param[in]   DtgTransferType:      Selector for the status type of interest, typically 0x01000000.
 *  \param[out]  pDtgDstAddress:       Pointer to a 32bit variable that will receive an address where to copy e.g. the radar raw pixel data to.
 *  \param[out]  pDtgDstMode:          Pointer to a 32bit variable that will receive a descriptor with the follwing meaning:
 *                                     bit0=0: auto-increment of destination address expected / bit0=1: all chunks to be copied to same address.
 *  \return      0 - data valid,
 *               else - provided data must not be used.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-DataTransferGetInfo
 *  \ingroup     DataTransfer
 *********************************************************************************************************************/
#   define   VX1000If_DataTransferGetInfo          VX1000IF_IMPL(DATATRANSFER_GET_INFO    , VX1000IF_RET_E_NOT_OK)

/********************** VX1000 Data Transfer END *********************************************************************/

/********************** VX1000 Notification BEGIN ********************************************************************/

/**********************************************************************************************************************
 *  VX1000If_NotificationLinkChange
 *********************************************************************************************************************/
/*! \fn          void VX1000If_NotificationLinkChange(uint8 NlcLinktype, uint8 NlcLinkstatus)
 *  \brief       Macro to inform the VX1000 about opening or closing new communication channels between ECU and VX1000.
 *  \details     Takes and remembers the new state of the specified link type and tries to signal a link change event
 *               to the VX1000 via remaining channel(s) in "up" state.
 *  \param[in]   NlcLinktype:          Selector for the link type that a change is to be notified for, typically 1U.
 *  \param[in]   NlcLinkstatus:        The new link state: 1U for "up" and 2U for "down".
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-NotificationLinkChange
 *  \ingroup     Notification
 *********************************************************************************************************************/
#   define   VX1000If_NotificationLinkChange       VX1000IF_IMPL_VOID(NOTIFICATION_LINKCHANGE)

/**********************************************************************************************************************
 *  VX1000If_NotificationError
 *********************************************************************************************************************/
/*! \fn          void VX1000If_NotificationError(uint8 NeOlInstance, uint32 NeDaqType, uint8 NeErrorType)
 *  \brief       Macro to inform the VX1000 and/or the XCP tool about an error situation in the ECU.
 *  \details     Transmits the user-provided error information to the VX1000.
 *  \param[in]   NeOlInstance:         The index of the affected offloader.
 *  \param[in]   NeDaqType:            A general type specification.
 *  \param[in]   NeErrorType:          Selector for the error type that is to be notified, e.g. 1, 2 or 3.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-NotificationError
 *  \ingroup     Notification
 *********************************************************************************************************************/
#   define   VX1000If_NotificationError            VX1000IF_IMPL_VOID(NOTIFICATION_ERROR)

/********************** VX1000 Notification END **********************************************************************/

/********************** VX1000 User functions and macros *************************************************************/

/**********************************************************************************************************************
 *  VX1000If_DetectFklRequests()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_DetectFklRequests(void)
 *  \brief       Macro to prevents the application from writing to RAM.
 *  \details     Makes the VX1000 driver prevent the application from writing to RAM to allow a flash kernel download
 *               by the VX1000 and to busily wait for trigger command to jump to the flash kernel execution start address
 *               provided by the VX1000.
 *  \pre         VX1000If_InitAsyncStart must have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-837
 *  \ingroup     UsrFunc
 *********************************************************************************************************************/
#   define   VX1000If_DetectFklRequests            VX1000IF_IMPL_VOID(DETECT_FKL_REQUESTS)

/**********************************************************************************************************************
 *  VX1000If_DeviceDetected()
 *********************************************************************************************************************/
/*! \fn          uint8 VX1000If_DeviceDetected(void)
 *  \brief       Macro to check whether a VX1000 was already detected.
 *  \details     Makes the VX1000 driver check whether a VX1000 has been detected.
 *  \return      0 - not detected (no VX1000 responded in time before VX1000If_InitAsyncEnd)
 *               1 - detected (connection to VX1000 system is or at least was established)
 *               2 - still undecided (there is still a chance that a VX1000 might respond in time)
 *               VX1000IF_RET_E_NOT_OK - while VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 *  \pre         VX1000If_InitAsyncStart should have been called.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-820
 *  \note        The final results 0 or 1 are only available after VX1000If_InitAsyncEnd() has returned.
 *               The window for a connection is open in the time from VX1000If_InitAsyncStart to VX1000If_InitAsyncEnd.
 *  \ingroup     UsrFunc
 *********************************************************************************************************************/
#   define   VX1000If_DeviceDetected               VX1000IF_IMPL(DETECTED                 , VX1000IF_RET_E_NOT_OK)

/**********************************************************************************************************************
 *  VX1000If_DynAddrSig_UpdateAddress()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_DynAddrSig_UpdateAddress(uint16 index, uint32 address)
 *  \brief       This API function is not described here. The appropriate VX1000 AppDriver Addons supplement to the
 *               VX1000If Technical Reference can be obtained via VXsupport(at)vector.com.
 * Internal comment removed. *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/ 
#   define   VX1000If_DynAddrSig_UpdateAddress     VX1000IF_IMPL_VOID(DYNADDRSIG_UPDATEADDRESS)

/**********************************************************************************************************************
 *  VX1000If_MemSync_AddrRange()
 *********************************************************************************************************************/
/*! \fn          void VX1000If_MemSync_AddrRange(uint32 address, uint16 size)
 *  \brief       This API function is not described here. The appropriate VX1000 AppDriver Addons supplement to the
 *               VX1000If Technical Reference can be obtained via VXsupport(at)vector.com.
 * Internal comment removed. *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/ 
#   define   VX1000If_MemSync_AddrRange            VX1000IF_IMPL_VOID(MEMSYNC_ADDRESSRANGE)

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#   define   VX1000IF_START_SEC_VAR_CLEARED_8
#   include "VX1000If_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Initialization state of the module */
extern VAR(uint8, VX1000IF_VAR_CLEARED) VX1000If_State;

/*! Counter for errors that are caused by API calls when :
 *     - VX1000 Interface is in incorrect state (e.g. not initialized)
 *     - or if VX1000If_IsVX1000DriverAccessEnabled returned FALSE
 */
extern VAR(uint8, VX1000IF_VAR_CLEARED) VX1000If_ErrorCount;

#   define   VX1000IF_STOP_SEC_VAR_CLEARED_8
#   include "VX1000If_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#   define   VX1000IF_START_SEC_CODE
#   include "VX1000If_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  VX1000If_InitMemory()
 *********************************************************************************************************************/
/*! \brief       Function for *_INIT_*-variable initialization
 *  \details     Service to initialize module global variables at power up. This function initializes the
 *               variables in *_INIT_* sections. Used in case they are not initialized by the startup code.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \ingroup     Generic
 *********************************************************************************************************************/
FUNC(void, VX1000IF_CODE) VX1000If_InitMemory(void);

/**********************************************************************************************************************
 * VX1000If_Init()
 *********************************************************************************************************************/
/*! \brief       Initialization function
 *  \details     This function initializes the module VX1000If. It initializes all variables and sets the module state
 *               to initialized.
 *  \pre         Interrupts are disabled.
 *  \pre         Module is uninitialized.
 *  \pre         VX1000If_InitMemory has been called unless VX1000If_State is initialized by start-up code.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        This service does not initialize the VX1000 device driver by calling VX1000If_InitAsyncStart().
 *               This must be done by the application.
 *  \trace       CREQ-811
 *  \ingroup     Generic
 *********************************************************************************************************************/
FUNC(void, VX1000IF_CODE) VX1000If_Init(void);

#   define   VX1000IF_STOP_SEC_CODE
#   include "VX1000If_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif /* VX1000If_IsVX1000DriverAccessEnabled */
# endif /* !VX1000IF_CFG_NO_TARGET */
#endif /* !VX1000IF_H */

/**********************************************************************************************************************
 *  END OF FILE: VX1000If.h
 *********************************************************************************************************************/

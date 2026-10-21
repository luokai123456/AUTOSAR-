/*
********************************************************************************
*
*  File name: LinIf_Cfg.h
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
*  Version: 3.0
*  Author/Date : WangJP/2021.8.14
*  Change: New created
*  Cause: New
********************************************************************************
*/
#ifndef LINIF_CFG_H_
#define LINIF_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* LinIfGlobalConfig */
/* Defines the interval of calls to main functions in MS. */
/* LinIfGeneral */
/* Global Pre-Compile Switch to enable/disable the APIs LinIf_CancelTransmit/LinTp_CancelReceive. */
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define LINIF_CANCEL_TRANSMIT_SUPPORTED               (STD_OFF)
/* Switches the Default Error Tracer (Det) detection and notification ON or OFF. */
#define LINIF_DEV_ERROR_DETECT                        (STD_OFF)
/* States if multiple drivers are supported by the LIN Interface or not. */
#define LINIF_MULTIPLE_DRIVERS_SUPPORTED              (STD_OFF)
/* States if multiple transceiver drivers are supported by the LIN Interface or not. */
#define LINIF_MULTIPLE_TRCV_DRIVER_SUPPORTED          (STD_OFF)
/* States if the node configuration commands Assign NAD and Conditional Change NAD are supported. */
#define LINIF_NC_OPTIONAL_REQUEST_SUPPORTED           (STD_OFF)
/* States if the TP is included in the LIN Interface or not. */
#define LINIF_TP_SUPPORTED                            (STD_ON)
/* States if transceiver driver support is included in the LIN Interface or not. */
#define LINIF_TRCV_DRIVER_SUPPORTED                   (STD_OFF)
/* Switches the LinIf_GetVersionInfo function ON or OFF. */
#define LINIF_VERSION_INFO_API                        (STD_OFF)
/* linIf channel total number */
#define LINIF_CHANNEL_NUMTOTAL                        (1U)
/* interior configuration */
#define LINIF_CHANNEL_WAKEUP_SUPPORT                  (STD_OFF)
#define LINIF_TRCV_WAKEUP_SUPPORT                     (STD_OFF)
/* Whether sporadic frames are supported */
#define LINIF_SPORADIC_FRM_SUPPORTED                  (STD_OFF)
/* Whether event-triggered frames are supported */
#define LINIF_EVT_FRM_SUPPORTED                       (STD_OFF)
#define LINIF_FIXEDFRAMESDULIST                       (STD_OFF)
#define LINIF_SLAVE_SUPPORT                           (STD_OFF)
#define LINIF_MASTER_SUPPORT                          (STD_ON)
#define LINIF_FIEXDFRAME_NUMBER                       (1U)
/* linIf sporadic frames number */
#define LINIF_SPORADIC_FRM_NUMBER                     (1U)
#define LINIF_EVENT_FRM_NUMBER                        (1U)
/* LinIf farme number. */
#define LINIF_FRAME_NUMBER                            (5U)
/* LinIf entry number. */
#define LINIF_ENTRY_NUMBER                            (5U)

/* LinIf ScheduleTable number. */
#define LINIF_SCHEDULETABLE_NUMBER (2U)
#define LINIF_UNCONDITIONAL_FRM_NUMBER (5U)
#define LINIF_SPORUNFRM_PRO_NUM (0U)
#define LINIF_EVENTUNFRAME_NUM (1U)
#define LINIF_ECUM_SUPPORT (STD_OFF)
#define LINIF_SCEDULE_NULL_SCHEDULE_T34TDkIDX (0U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define LINIF_SCEDULE_Schedule_T34TDkIDX (1U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define LINIF_CHANNEL_VE21_N72_PMS_LIN_LDF_T34TDK_INDEX (0)
#define LINIF_SCHEDULE_VE21_N72_PMS_LIN_LDF_T34TDKNULL_SCHEDULE_T34TDK_INDEX (0)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define LINIF_SCHEDULE_VE21_N72_PMS_LIN_LDF_T34TDKSCHEDULE_T34TDK_INDEX (1)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define LINIF_CONTROLLER_NUM (1U)
#define LINIF_FRAME_NUM_CHANNEL_VE21_N72_PMS_LIN_LDF_T34TDK (5U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */

#define LINIF_TIMEBASE_CHANNEL0                       (10U)
#define LINIF_ADAPTED_AR_VERSION                      (LINIF_AR_VERSION_ABOVE_440)

/* Get sporadic flag. */
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define LinIf_GetSporTransmitFlagsOfPCConfig()       LinIf_SporTransmitFlags
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
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
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* LINIF_CFG_H_ */


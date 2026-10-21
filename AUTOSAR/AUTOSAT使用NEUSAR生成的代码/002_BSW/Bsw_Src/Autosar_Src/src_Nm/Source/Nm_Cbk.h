/*
********************************************************************************
*
* File name: Nm_Cbk.h                                              
*                                                                              
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.           
*
********************************************************************************
*
* History                                                               
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : yong.zhang/2018.12.21
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date : jiafeng/2020.07.02
* Change: Nothing
* Cause: Update to V3.0
********************************************************************************
*/
#ifndef NM_CBK_H_
#define NM_CBK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Nm_Cfg.h"


/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Definition of Callback API-Ids. */
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NM_SID_NETWORKSTARTINDICATION        (0x11U)
#define NM_SID_NETWORKMODE                   (0x12U)
#define NM_SID_PREPAREBUSSLEEPMODE           (0x13U)
#define NM_SID_BUSSLEEPMODE                  (0x14U)
#define NM_SID_PDURXINDICATION               (0x15U)
#define NM_SID_STATECHANGENOTIFICATION       (0x16U)
#define NM_SID_REMOTESLEEPINDICATION         (0x17U)
#define NM_SID_REMOTESLEEPCANCELLATION       (0x18U)
#define NM_SID_SYNCHRONIZATIONPOINT          (0x19U)
#define NM_SID_REPEATMESSAGEINDICATION       (0x1AU)
#define NM_SID_TXTIMEOUTEXCEPTION            (0x1BU)
#define NM_SID_BUSNMSPECIFICPDURXINDICATION  (0x1CU)
#define NM_SID_CARWAKEUPINDICATION           (0x1DU)
#define NM_SID_COORDREADYTOSLEEPINDICATION   (0x1EU)
#define NM_SID_COORDREADYTOSLEEPCANCELLATION (0x1FU)
/* polyspace-begin MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#if( NM_PDU_RX_INDICATION_ENABLED == STD_ON )
#ifdef NM_PDURXIND_CBK
  #define Nm_PduRxIndicationCbk(nmChannelHandle)     NM_PDURXIND_CBK(nmChannelHandle)
#else
  #define Nm_PduRxIndicationCbk(nmChannelHandle)
#endif
#endif

#if( NM_REPEAT_MSG_IND_ENABLED == STD_ON )
#ifdef NM_REPMSGIND_CBK
  #define Nm_RepeatMessageIndicationCbk(nmChannelHandle)     NM_REPMSGIND_CBK(nmChannelHandle)
#else
  #define Nm_RepeatMessageIndicationCbk(nmChannelHandle)
#endif
#endif

#if( NM_CAR_WAKE_UP_RX_ENABLED == STD_ON )
#ifdef NM_CARWURX_CBK
  #define Nm_CarWakeupRxIndicationCbk(nmChannelHandle)     NM_CARWURX_CBK(nmChannelHandle)
#else
  #define Nm_CarWakeupRxIndicationCbk(nmChannelHandle)
#endif
#endif

#ifdef NM_TXTIMEOUT_CBK
  #define Nm_TxTimeoutExceptionCbk(nmChannelHandle)     NM_TXTIMEOUT_CBK(nmChannelHandle)
#else
  #define Nm_TxTimeoutExceptionCbk(nmChannelHandle)
#endif
/* polyspace-end MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
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
#if( NM_PDU_RX_INDICATION_ENABLED == STD_ON )

extern void Nm_PduRxIndcationCallback(const NetworkHandleType nmChannelHandle);
#endif

#if( NM_REPEAT_MSG_IND_ENABLED == STD_ON )

extern void Nm_RepeatMessageIndCallback(const NetworkHandleType nmChannelHandle);
#endif

#if( NM_CAR_WAKE_UP_RX_ENABLED == STD_ON )

extern void Nm_CarWakeUpCallout(const NetworkHandleType nmChannelHandle);
#endif


extern void Nm_TxTimeoutCallback(const NetworkHandleType nmChannelHandle);
#endif  /* NM_CBK_H_ */


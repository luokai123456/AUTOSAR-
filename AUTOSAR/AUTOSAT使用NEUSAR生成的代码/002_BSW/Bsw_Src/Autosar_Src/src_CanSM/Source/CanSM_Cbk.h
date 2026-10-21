/*
********************************************************************************
*
* File name: CanSM_Cbk.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangC/2018.07.21
* Change: New
* Cause: New
********************************************************************************
* Version: 2.0
* Author/Date: WangC/2018.05.29
* Change: Modify format.
* Cause: updata to V2.0.
********************************************************************************
* Version: 2.1
* Author/Date: WangC/2019.10.12
* Change: Modify code format.
* Cause: Unified format.
********************************************************************************
* Version: 3.0
* Author/Date: WangC/2020.01.19
* Change: Synchronizing code with the DF project(Debugging completed).
* Cause: updata to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date : WangC/2020.05.12
* Change: Modify the code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.2
* Author/Date : WangC/2021.10.27
* Change: Modify the file name.
* Cause: Optimize
********************************************************************************
* Version: 3.3
* Author/Date: LiuHJ/2021.10.28
* Change: Modify header file reference.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: TianL/2023.10.27
* Change: Modify header files.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: TianL/2024.5.15
* Change: 1. Add a MemMap paragraph definition to the function declaration.
*         2. Modify coding specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: TianL/2024.8.5
* Change: Modify copyright information.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: TianL/2025.6.8
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: TianL/2025.6.23
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef CANSM_CBK_H_
#define CANSM_CBK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanIf_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
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
#define CANSM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"

extern FUNC(void, CANSM_CODE) CanSM_ControllerBusOff
(
	uint8 ControllerId 
); 
extern FUNC(void, CANSM_CODE) CanSM_ControllerModeIndication
(
	uint8 ControllerId,
	CanIf_ControllerModeType ControllerMode 
);
extern FUNC(void, CANSM_CODE) CanSM_TransceiverModeIndication
(
	uint8 TransceiverId,
	CanTrcv_TrcvModeType TransceiverMode 
);
extern FUNC(void, CANSM_CODE) CanSM_TxTimeoutException
(
	NetworkHandleType Channel 
);
extern FUNC(void, CANSM_CODE) CanSM_ClearTrcvWufFlagIndication
(
	uint8 Transceiver
); 
extern FUNC(void, CANSM_CODE) CanSM_CheckTransceiverWakeFlagIndication
(
	uint8 Transceiver 
); 
extern FUNC(void, CANSM_CODE) CanSM_ConfirmPnAvailability
(
	uint8 TransceiverId 
); 
extern FUNC(void, CANSM_CODE) CanSM_CurrentIcomConfiguration
(
	uint8 ControllerId,
	IcomConfigIdType ConfigurationId,
	/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanSM_Dir4.5" */
 	IcomSwitch_ErrorType Error 
); 

#define CANSM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanSM_MemMap.h"

#endif  /* CANSM_CBK_H_ */


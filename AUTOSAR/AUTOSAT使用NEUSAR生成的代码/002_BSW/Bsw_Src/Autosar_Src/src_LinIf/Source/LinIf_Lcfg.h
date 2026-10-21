/*
********************************************************************************
*
*  File name: LinIf_Lcfg.h
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : li.zhiheng/2020.01.19
* Change: New
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date : Li.ZH/2021.8.16
* Change: Modification code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.1
* Author/Date: LiZH/2022.2.10
* Change: MCAL API name compatible.
* Cause: Optimize.
********************************************************************************
* Version: 3.2
* Author/Date: SunHQ/2022.12.9
* Change: Remove the redundant header files.
* Cause: Optimization.
********************************************************************************
* Version: 3.3
* Author/Date: YuHC/2023.05.10
* Change: 1.CCOREDBUG-2862:Change the type of LinIf_Channel_WakeupSouceInfo.
* Cause: Bugfix.
********************************************************************************
* Version: 3.4
* Author/Date: LiXB/2023.07.01
* Change: Add declaration of LinIfResponseErrorSignalChangedCallout.
* Cause: Update.
********************************************************************************
*/
#ifndef LINIF_LCFG_H_
#define LINIF_LCFG_H_

/*
*******************************************************************************
*    Includes
*******************************************************************************
*/
#include "LinIf_Types.h"
	
/*
*******************************************************************************
*    Global Macros
*******************************************************************************
*/

/*
*******************************************************************************
*    Global Types
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Variables
*******************************************************************************
*/
#define LINIF_START_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
extern VAR(LinIf_ChannelDataType, LINIF_VAR_NO_INIT) LinIf_ChannelData[LINIF_CHANNEL_NUMTOTAL];
#define LINIF_STOP_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define LINIF_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
extern VAR(uint8, LINIF_VAR_INIT) LinIf_SporTransmitFlags[LINIF_SPORADIC_FRM_NUMBER];

#if (LINIF_SPORADIC_FRM_SUPPORTED == STD_ON)
extern VAR(LinIf_SporUnconditionalFrameType, LINIF_VAR_INIT) LinIf_SporUnconditionalFrame[LINIF_SPORUNFRM_PRO_NUM];
#endif

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
extern VAR(uint32, LINIF_VAR_INIT) LinIf_Channel_WakeupSouceInfo[LINIF_CHANNEL_NUMTOTAL];
#endif
	
	
	/* polyspace +1 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
extern P2CONST(LinIf_SlaveChannel_Nc_ConfigType, LINIF_VAR_INIT, LINIF_CONFIG_DATA) LinIf_SlaveChannel_Nc_ConfigData[LINIF_CHANNEL_NUMTOTAL];

#define LINIF_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
*******************************************************************************
*    Global Constants
*******************************************************************************
*/
#define LINIF_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

extern CONST(LinIf_Channel_Config_st, LINIF_CONFIG_DATA) LinIf_Channl_Cfg_Tab[LINIF_CHANNEL_NUMTOTAL];
extern CONST(LINIf_Frame_Table_st, LINIF_CONFIG_DATA) LINIf_Frame_Cfg_Tab[LINIF_FRAME_NUMBER];
extern CONST(LinIf_EntryType, LINIF_CONFIG_DATA) LinIf_Entry[LINIF_ENTRY_NUMBER];
extern CONST(LinIf_ScheduleTableListType, LINIF_CONFIG_DATA) LinIf_ScheduleTableList[LINIF_SCHEDULETABLE_NUMBER];
extern CONST(LinIf_ChannelIndTableType, LINIF_CONFIG_DATA) LinIf_ChannelIndTable[LINIF_CHANNEL_NUMTOTAL];
extern CONST(uint16, LINIF_CONFIG_DATA) LinIf_ScheduleTableListInd[LINIF_SCHEDULETABLE_NUMBER];
extern CONST(uint8, LINIF_CONFIG_DATA) LinIf_FrameLengthDelayList[8];
extern CONST(uint8, LINIF_CONFIG_DATA) LinIf_FixedFrameSduList[LINIF_FIEXDFRAME_NUMBER];

#if (LINIF_EVT_FRM_SUPPORTED == STD_ON)
extern CONST(LinIf_EvtFrameInfoType, LINIF_CONFIG_DATA) LinIf_EvtFrameInfo[LINIF_EVENT_FRM_NUMBER];
extern CONST(LinIf_EvtUnconditionalFrameInfoType, LINIF_CONFIG_DATA) LinIf_EvtUnconditionalFrameInfo[LINIF_EVENTUNFRAME_NUM];
#endif

#if (LINIF_SPORADIC_FRM_SUPPORTED == STD_ON)
extern CONST(uint8, LINIF_CONFIG_DATA) LinIf_SporUncFrameByPriorityList[LINIF_SPORUNFRM_PRO_NUM];
extern CONST(LinIf_SporadicFrameInfoType, LINIF_CONFIG_DATA) LinIf_SporadicFrameInfo[LINIF_CHANNEL_NUMTOTAL];
extern CONST(LinIf_SporadicFrameLookupTableType, LINIF_CONFIG_DATA) LinIf_SporadicFrameLookupTable[LINIF_SPORADIC_FRM_NUMBER];
#endif

#if ( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON )
extern CONST(LinIf_LinMultipeDrvInfoType, LINIF_CONFIG_DATA) LinIf_LinMultipeDrvInfo[LINIF_CONTROLLER_NUM];
#endif

#define LINIF_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define LINIF_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
extern VAR(LinIf_ResponseErrorSignalChangedFuncType , LINIF_VAR_INIT) LinIfResponseErrorSignalChangedCallout;
#define LINIF_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define LINIF_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#define LINIF_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define LINIF_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define LINIF_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
*******************************************************************************
*    Global Functions
*******************************************************************************
*/
#define LINIF_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* polyspace +1 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_Common_IdentifierLength" */
extern FUNC(void, LINIF_CODE) LinIf_MainFunction_VE21_N72_PMS_LIN_ldf_T34TDk(void);

#define LINIF_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif /* LINIF_LCFG_H_ */



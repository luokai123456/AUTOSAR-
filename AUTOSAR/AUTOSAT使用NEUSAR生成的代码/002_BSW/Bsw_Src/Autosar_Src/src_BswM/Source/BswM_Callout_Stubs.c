/*
********************************************************************************
*
*  File name: BswM_Callout_Stubs.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : yong.zhang/2018.12.13
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date : yong.zhang/2020.07.02
* Change: Add release software number.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Include
********************************************************************************
*/
#include "BswM.h"
#include "Evpt_BswM.h"
#include "Dem.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/*
********************************************************************************
*    Local Types
********************************************************************************
*/
/*
********************************************************************************
*    Local Variables
********************************************************************************
*/
/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
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
* Function Name: 
*
* Explanation: 
*
* param: none
*
* retval: none
********************************************************************************
*/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"
FUNC(void, BSWM_CODE) BswM_BootReset_Action(void)
{
	BootReset_Action();
}


FUNC(void, BSWM_CODE) BswM_CANDriver_OFF(void)
{
	BswM_CanIf_SLEEP();
	BswM_TPT1145_SLEEP();
}


FUNC(void, BSWM_CODE) BswM_CANDriver_ON(void)
{
	BswM_TPT1145_NORMAL();
	BswM_CanIf_NORMAL();
}


FUNC(void, BSWM_CODE) BswM_Dem_Shutdown(void)
{
	Dem_Shutdown();
}


FUNC(void, BSWM_CODE) BswM_HardReset_Action(void)
{
	HardReset_Action();
}


FUNC(void, BSWM_CODE) BswM_InitToRun_Action(void)
{
	InitToRun_Action();
}


FUNC(void, BSWM_CODE) BswM_PostRunToRun_Action(void)
{
	PostRunToRun_Action();
}


FUNC(void, BSWM_CODE) BswM_PostRunToShutdown_Action(void)
{
	PostRunToShutdown_Action();
}


FUNC(void, BSWM_CODE) BswM_RunToPostRun_Action(void)
{
	RunToPostRun_Action();
}


FUNC(void, BSWM_CODE) BswUserCallout_SWC_Delay_PowerOffPort(void)
{
	extern uint8 PwrOffDlyFlg_Mp;
	BswM_GenericState[4] = PwrOffDlyFlg_Mp;
}


FUNC(void, BSWM_CODE) BswM_SoftReset_Action(void)
{
	SoftReset_Action();
}



#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"


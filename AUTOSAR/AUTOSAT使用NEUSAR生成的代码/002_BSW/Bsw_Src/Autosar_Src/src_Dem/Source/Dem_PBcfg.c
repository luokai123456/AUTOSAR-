/*
********************************************************************************
*
* File name: Dem_PBcfg.c
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: FanHT/2023.01.01
* Change: New
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: ZengJX/2024.07.18
* Change: 1.Modify copyright information.
*         2.Fix Dem memmap issue.
* Cause: Optimization
********************************************************************************
* Version: 1.2
* Author/Date: ZengJX/2024.08.22
* Change: Modify copyright information.
* Cause: Bugfix
********************************************************************************
* Version: 1.3
* Author/Date: ZengJX/2025.05.06
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Include
********************************************************************************
*/
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
/* polyspace-begin VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */
#define DEM_START_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
CONST(uint32, DEM_CONFIG_DATA) Dem_CfgUdsDtcValue[DEM_CFG_DTC_NUM + 1U] = 
{
	0x0U,
	0x002AD4A2U,
	0x002AD5A3U,
	0x00140149U,
	0x00140249U,
	0x00212C11U,
	0x00212D12U,
	0x00212B16U,
	0x00212B17U,
	0x00213211U,
	0x00213312U,
	0x00213116U,
	0x00213117U,
	0x00212F64U,
	0x00050464U,
	0x00C07388U,
	0x00C07588U,
	0x00C07488U,
	0x00C12187U,
	0x00C29887U,
	0x00C10387U,
	0x00D13487U,
	0x00C45281U,
	0x00C41381U,
	0x00C19A87U,
	0x00C41181U,
	0x0014DB13U,
	0x0014D900U,
	0x0014164BU,
	0x0014174BU,
	0x0014184BU,
	0x0014194BU,
	0x0014204BU,
	0x0014214BU,
	0x0014314BU,
	0x0014324BU,
	0x0014334BU,
	0x0014344BU,
	0x0014354BU,
	0x0014364BU,
	0x00D40981U,
	0x00149D68U,
	0x00149F68U,
	0x00149468U,
	0x00149868U,
	0x00149568U,
	0x0014F100U,
	0x0014F600U,
	0x0014F700U,
	0x0014F800U,
	0x0014F900U,
	0x0014FA00U,
	0x00150016U,
	0x00150119U,
	0x00150219U,
	0x00150317U,
	0x00150417U,
	0x00150616U,
	0x0015094BU,
	0x00150A4BU,
	0x00150B4BU,
	0x00150C4BU,
	0x00150D00U,
	0x00150E22U,
	0x0015101CU,
	0x00151112U,
	0x00151313U,
	0x00151412U,
	0x00151512U,
	0x00151612U,
	0x00151728U,
	0x00151812U,
	0x00151912U,
	0x00151A28U,
	0x00151B13U,
	0x00151C12U,
	0x00151E03U,
	0x00152071U,
	0x00150796U,
	0x000AFB01U,
	0x000AFA01U,
	0x000A7D02U,
	0x000A7D01U,
	0x00313B04U,
	0x00311200U,
	0x000CA600U,
	0x00315D19U,
	0x000CA701U,
	0x00311519U,
	0x00311419U,
	0x00311119U,
	0x000A7E02U,
	0x000A7E01U,
	0x000A7E00U,
	0x000AFD00U,
	0x000DE603U,
	0x000DE602U,
	0x000DE601U,
	0x000DE703U,
	0x000DE702U,
	0x000DE701U,
	0x000DAB01U,
	0x00311602U,
	0x000AA602U,
	0x000AA601U,
	0x00311702U,
	0x00312702U,
	0x00313A1AU,
	0x000AA700U,
	0x00313E13U,
	0x00C1A000U,
	0x00D8A487U,
	0x00F00616U,
	0x00F00617U,
	0x00313900U,
	0x000AA100U,
	0x000AA000U,
	0x000AA400U,
	0x000AA300U,
	0x00313F1FU,
	0x00312298U,
	0x00312398U,
	0x0031074BU,
	0x0031064BU,
	0x000D0900U,
	0x000D0800U,
	0x00314149U,
	0x00314249U,
	0x000AC000U,
	0x00313A49U,
	0x000AC300U,
	0x00060600U,
	0x00313300U,
	0x00313200U,
	0x00313100U,
	0x00313000U,
	0x00312800U,
	0x00314387U,
	0x00314487U,
	0x00314587U,
	0x00314687U,
	0x00314787U,
	0x00314887U,
	0x00314A87U,
	0x00314B87U,
	0x00314C87U,
	0x00314D87U,
	0x00314E87U,
	0x00314F87U,
	0x00315087U,
	0x00310200U,
	0x00310284U,
	0x0031011CU,
	0x0031014BU,
	0x00310184U,
	0x0031021CU,
	0x0031041CU,
	0x00310102U,
	0x0031024BU,
	0x0031034BU,
	0x0031044BU,
	0x0031011BU,
	0x0031011AU,
	0x0031021AU,
	0x0031021BU,
	0x00310115U,
	0x00310104U,
	0x0031031CU,
	0x00311C96U,
	0x00310287U,
	0x0015A001U,
	0x0015A002U,
	0x0015A003U,
	0x0015A004U,
	0x00160001U,
	0x00160002U,
	0x00160003U,
	0x00160004U,
	0x00160005U,
	0x00160006U,
	0x00160007U,
	0x00160008U,
	0x00160009U,
	0x0016000AU,
	0x0016000BU,
	0x0016000CU,
	0x0016000DU,
	0x0016000EU,
	0x0016000FU,
	0x00160010U,
	0x00160011U,
	0x00160012U,
	0x00160013U,
	0x00160014U,
	0x00160015U,
	0x00160016U,
	0x00160017U,
	0x00160018U,
	0x00160019U,
	0x0016001AU,
	0x0016001BU,
	0x0016001CU,
	0x0016001DU,
	0x0016001EU,
	0x0016001FU,
	0x00160020U,
	0x00160021U,
	0x00160022U,
	0x00160023U,
	0x00160024U,
	0x00160025U,
	0x00160026U,
	0x00160027U,
	0x00160028U,
	0x00160029U,
	0x0016002AU,
	0x0016002BU,
	0x0016002CU,
	0x0016002DU,
	0x0016002EU,
	0x0016002FU,
	0x00160030U,
	0x00160031U,
	0x00160032U,
	0x00160033U,
	0x00160034U,
	0x00160035U,
	0x00160036U,
	0x00160037U,
	0x00160038U,
	0x00160039U,
	0x0016003AU,
	0x0016003BU,
	0x0016003CU,
	0x0016003DU,
	0x0016003EU,
	0x0016003FU,
	0x00160040U,
	0x00160041U,
	0x00160042U,
	0x00160043U,
	0x00160044U,
	0x00160045U,
	0x00160046U,
	0x00160047U,
	0x00160048U,
	0x00160049U,
	0x0016004AU,
	0x0016004BU,
};


CONST(boolean, DEM_CONFIG_DATA) Dem_CfgEvtAvail[DEM_CFG_EVENT_NUM + 1U] = 
{
	FALSE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
	TRUE,
};


CONST(uint16, DEM_CONFIG_DATA) Dem_CfgDebCntFailThrs[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U] = 
{
	0U,
	10U,
};


CONST(sint16, DEM_CONFIG_DATA) Dem_CfgDebCntPassThrs[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U] = 
{
	0,
	-128,
};


CONST(uint16, DEM_CONFIG_DATA) Dem_CfgDebCntIncStepSize[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U] = 
{
	0U,
	1U,
};


CONST(uint16, DEM_CONFIG_DATA) Dem_CfgDebCntDecStepSize[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U] = 
{
	0U,
	1U,
};


CONST(boolean, DEM_CONFIG_DATA) Dem_CfgDebCntJuEn[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U] = 
{
	FALSE,
	TRUE,
};


CONST(boolean, DEM_CONFIG_DATA) Dem_CfgDebCntJdEn[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U] =
{
	FALSE,
	FALSE,
};


CONST(sint16, DEM_CONFIG_DATA) Dem_CfgDebCntJuVal[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U] = 
{
	0,
	0,
};


CONST(sint16, DEM_CONFIG_DATA) Dem_CfgDebCntJdVal[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U] = 
{
	0,
	0,
};


CONST(boolean, DEM_CONFIG_DATA) Dem_CfgEnableCond[DEM_CFG_ENCOND_NUM + 1U] = 
{
	FALSE,
	TRUE,
};
#define DEM_STOP_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* polyspace-end VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_GlobalVariables" */


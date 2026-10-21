/*
********************************************************************************
*
* File name: Dcm_Lcfg.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : TanLixiang/2018.11.14
* Change: Neusar
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : TanLixiang/2019.05.13
* Change: Modify
* Cause:
*(1)Modify file structure.
********************************************************************************
* Version: 1.2
* Author/Date : Songqw/2019.09.02
* Change: Revert 10 service about the 82 subfunction
* Cause: bugfix
********************************************************************************
* Version: 1.3
* Author/Date : Songqw/2019.11.11
* Change: Add the address type to the Dcm_DslProtocol structure.
* Cause: update
********************************************************************************
* Version: 1.4
* Author/Date : Liuziyang/2019.11.21
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 1.5
* Author/Date : songqingwei/2020.01.22
* Change: Modify the Dcm_22_2E_ServiceInfo struction.
* Cause: How to association with Nvm about the DID buffer point.
********************************************************************************
* Version: 3.0
* Author/Date: ZhuCY/2021.10.28
* Change: Modify header file.
* Cause: Optimization.
********************************************************************************
* Version: 3.1
* Author/Date: LQiao/2023.02.06
* Change: Add Struct. Add 38 service. 
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Include
********************************************************************************
*/
#include "Dcm.h"
#include "Dem.h"
#include "CanIf.h"
#include "Dcm_Callback.h"

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
#define DCM_START_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(uint8, DCM_VAR_INIT) Dcm_DslBufferRx[DCM_DSL_BUFFERLENRX] = {0U};  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
VAR(uint32, DCM_VAR_INIT) Dcm_ProgrammingLength = DCM_ZERO;

#if( STD_ON == DCM_SERVICE_11_ENABLED )
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
VAR(uint8, DCM_VAR_INIT) Dcm_11_NvMBuf[DCM_FOUR] = {DCM_ZERO};
#endif /* STD_ON == DCM_SERVICE_11_ENABLED */
 
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_ReadBlockId_st, DCM_VAR_INIT) Dcm_ReadBlockId[DCM_READ_BLOCK_NUM + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
    {DCM_INVALID_BLOCKID, DCM_E_NOT_OK, DCM_E_NOT_OK, NULL_PTR, NULL_PTR, 0}
};

 
#if ( (STD_ON == DCM_SERVICE_22_ENABLED) || (STD_ON == DCM_SERVICE_2E_ENABLED) || (STD_ON == DCM_SERVICE_2A_ENABLED) || (STD_ON == DCM_SERVICE_2C_ENABLED) )
/* polyspace-begin DEFECT:DATA_RACE_ALL [Justified:Unset] "NSCA_Polyspace_Dcm_DATA_RACE_ALL"  Polyspace-begin MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace-begin VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0090_Cfg, DCM_VAR_INIT) Dcm_Did_Block0090_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0091_Cfg, DCM_VAR_INIT) Dcm_Did_Block0091_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0092_Cfg, DCM_VAR_INIT) Dcm_Did_Block0092_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0093_Cfg, DCM_VAR_INIT) Dcm_Did_Block0093_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0094_Cfg, DCM_VAR_INIT) Dcm_Did_Block0094_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0095_Cfg, DCM_VAR_INIT) Dcm_Did_Block0095_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0096_Cfg, DCM_VAR_INIT) Dcm_Did_Block0096_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0097_Cfg, DCM_VAR_INIT) Dcm_Did_Block0097_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0098_Cfg, DCM_VAR_INIT) Dcm_Did_Block0098_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0099_Cfg, DCM_VAR_INIT) Dcm_Did_Block0099_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block009A_Cfg, DCM_VAR_INIT) Dcm_Did_Block009A_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block009B_Cfg, DCM_VAR_INIT) Dcm_Did_Block009B_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block009C_Cfg, DCM_VAR_INIT) Dcm_Did_Block009C_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block009D_Cfg, DCM_VAR_INIT) Dcm_Did_Block009D_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block009E_Cfg, DCM_VAR_INIT) Dcm_Did_Block009E_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block009F_Cfg, DCM_VAR_INIT) Dcm_Did_Block009F_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A0_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A0_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A1_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A1_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A2_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A2_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A3_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A3_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A4_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A4_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A5_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A5_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A6_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A6_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A7_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A7_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A8_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A8_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A9_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A9_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00AA_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AA_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00AB_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AB_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00AC_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AC_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00AD_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AD_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00AE_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AE_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00AF_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AF_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B0_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B0_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B1_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B1_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B2_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B2_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B3_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B3_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B4_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B4_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B5_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B5_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B6_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B6_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B7_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B7_Data = {{0x00U}};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B8_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B8_Data = {{0x00U}};
//baoenfei
VAR(Dcm_Did_Block00B9_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B9_Data = {{0x00U}};

/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0090_Cfg, DCM_VAR_INIT) Dcm_Did_Block0090_INIT_Data =
{
	{0x20U ,0x00U ,0x01U ,0x01U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0091_Cfg, DCM_VAR_INIT) Dcm_Did_Block0091_INIT_Data =
{
	{0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0092_Cfg, DCM_VAR_INIT) Dcm_Did_Block0092_INIT_Data =
{
	{0x20U ,0x00U ,0x01U ,0x01U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0093_Cfg, DCM_VAR_INIT) Dcm_Did_Block0093_INIT_Data =
{
	{0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0094_Cfg, DCM_VAR_INIT) Dcm_Did_Block0094_INIT_Data =
{
	{0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0095_Cfg, DCM_VAR_INIT) Dcm_Did_Block0095_INIT_Data =
{
	{0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0096_Cfg, DCM_VAR_INIT) Dcm_Did_Block0096_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0097_Cfg, DCM_VAR_INIT) Dcm_Did_Block0097_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0098_Cfg, DCM_VAR_INIT) Dcm_Did_Block0098_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block0099_Cfg, DCM_VAR_INIT) Dcm_Did_Block0099_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block009A_Cfg, DCM_VAR_INIT) Dcm_Did_Block009A_INIT_Data =
{
	{0xFFU ,0xFFU ,0xFFU ,0xFFU ,0xFFU ,0xFFU ,0xFFU ,0xFFU}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block009B_Cfg, DCM_VAR_INIT) Dcm_Did_Block009B_INIT_Data =
{
	{0xFFU ,0xFFU ,0xFFU ,0xFFU ,0xFFU ,0xFFU ,0xFFU ,0xFFU}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block009C_Cfg, DCM_VAR_INIT) Dcm_Did_Block009C_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block009D_Cfg, DCM_VAR_INIT) Dcm_Did_Block009D_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block009E_Cfg, DCM_VAR_INIT) Dcm_Did_Block009E_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block009F_Cfg, DCM_VAR_INIT) Dcm_Did_Block009F_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A0_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A0_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A1_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A1_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A2_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A2_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A3_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A3_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A4_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A4_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A5_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A5_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A6_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A6_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A7_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A7_INIT_Data =
{
	{0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A8_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A8_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00A9_Cfg, DCM_VAR_INIT) Dcm_Did_Block00A9_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00AA_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AA_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00AB_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AB_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00AC_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AC_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00AD_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AD_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00AE_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AE_INIT_Data =
{
	{0x30U ,0x30U ,0x30U ,0x30U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00AF_Cfg, DCM_VAR_INIT) Dcm_Did_Block00AF_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B0_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B0_INIT_Data =
{
	{0x01U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B1_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B1_INIT_Data =
{
	{0x20U ,0x00U ,0x01U ,0x01U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B2_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B2_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B3_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B3_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B4_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B4_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B5_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B5_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B6_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B6_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B7_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B7_INIT_Data =
{
	{0x00U}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(Dcm_Did_Block00B8_Cfg, DCM_VAR_INIT) Dcm_Did_Block00B8_INIT_Data =
{
	{0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U ,0x30U}
};
/* polyspace-end DEFECT:DATA_RACE_ALL [Justified:Unset] "NSCA_Polyspace_Dcm_DATA_RACE_ALL"  Polyspace-end MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace-end VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
/* polyspace-begin DEFECT:HARD_CODED_BUFFER_SIZE [Justified:Unset] "NSCA_Polyspace_Dcm_HARD_CODED_BUFFER_SIZE"  Polyspace-begin MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace-begin VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
VAR(uint8, DCM_VAR_INIT) Dcm_Did0310Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0311Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0312Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0313Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0314Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0315Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0316Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0317Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0318Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0319Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did031ABuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did031BBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did031CBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did031DBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did031EBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did031FBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0320Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0321Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0322Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0323Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0324Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0325Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0326Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0327Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0328Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0329Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did032ABuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did032BBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did032CBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did032DBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did032EBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did032FBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0330Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0331Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0332Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0333Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0334Buffer[3] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0335Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidDF00Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0501Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0502Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0503Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0504Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0507Buffer[255] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did050ABuffer[54] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidCF00Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidCF05Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidDF09Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0525Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0526Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0527Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0528Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0529Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidCF06Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did052BBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidCF07Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did052DBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0530Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0531Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0532Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0533Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0534Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0535Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0536Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0537Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0538Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0539Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0505Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did053BBuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did053CBuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did053DBuffer[4] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did053EBuffer[4] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0542Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0543Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0544Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0545Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0547Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0552Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did055ABuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did055CBuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did055DBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0585Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0586Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0587Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0588Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0589Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did058ABuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did058BBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did058CBuffer[3] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did058DBuffer[3] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did058EBuffer[3] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did058FBuffer[3] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0590Buffer[3] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0591Buffer[3] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0592Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0593Buffer[48] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0594Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0595Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0596Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0597Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0598Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0599Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did059ABuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did059BBuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did059DBuffer[8] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did059EBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did059FBuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidDD00Buffer[6] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05A1Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05A2Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05A3Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05A4Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05A5Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05A6Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05A7Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05A8Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05A9Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05AABuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05ABBuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05ACBuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05ADBuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05AEBuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05AFBuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05B0Buffer[48] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05B1Buffer[48] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05B2Buffer[288] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05B3Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05B4Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05B5Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05B6Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05B7Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05B8Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05B9Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05BABuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05BBBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05BCBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05BDBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05BEBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05BFBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05C0Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05C1Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05C2Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05C3Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05C4Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05C5Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05C6Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05C7Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05C8Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05C9Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05CABuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05CBBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05CCBuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05CDBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05CEBuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05CFBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05D0Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05D1Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05D2Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05D3Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did05D4Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidDF01Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidDF02Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidDF03Buffer[4] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidDF04Buffer[4] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidDF06Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did059CBuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did052EBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidDF0ABuffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidDF0BBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidDF0CBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidDF0DBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_DidDF0EBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0402Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0403Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0404Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0405Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0406Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0407Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0408Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0409Buffer[2] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did040BBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did040CBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did040DBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did04CFBuffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did0400Buffer[1] = {0x00U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did04DCBuffer[2] = {0x01U, 0x50U};
VAR(uint8, DCM_VAR_INIT) Dcm_Did04DDBuffer[2] = {0x01U, 0x7CU};
VAR(uint8, DCM_VAR_INIT) Dcm_Did04DEBuffer[2] = {0x00U, 0xBEU};
/* polyspace-end DEFECT:HARD_CODED_BUFFER_SIZE [Justified:Unset] "NSCA_Polyspace_Dcm_HARD_CODED_BUFFER_SIZE"  Polyspace-end MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace-end VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
VAR(uint16, DCM_VAR_INIT) Dcm_22_DidList[DCM_22_MAX_DID_LIST_NUM] = {0};
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(uint16, DCM_VAR_INIT) Dcm_22_DidResLen[DCM_22_MAX_DID_LIST_NUM] = {0};
#endif

 
#if (STD_ON == DCM_SERVICE_27_ENABLED)
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
VAR(Dcm_27_Security_cfg, DCM_VAR_INIT) Dcm_27_Security_Data[DCM_27_LEVEL_NUM + 1U] = {{0x00U}};
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
VAR(Dcm_27_Security_cfg, DCM_VAR_INIT) Dcm_27_Security_INIT_Data[DCM_27_LEVEL_NUM + 1U] = {{0x00U}};
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(uint32, DCM_VAR_INIT) Dcm_27_TimerEngine[DCM_27_LEVEL_NUM + 1U] = {0x00U};
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
VAR(uint8, DCM_VAR_INIT) Dcm_security_key[DCM_27_MAX_SEED_LENGTH + 1U] = {0x00U};
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
VAR(uint8, DCM_VAR_INIT) Dcm_security_seed[DCM_27_MAX_SEED_LENGTH + 1U] = {0x00U};
#endif/* STD_ON == DCM_SERVICE_27_ENABLED */

#if( STD_ON == DCM_SERVICE_2C_ENABLED )
/* polyspace-begin DEFECT:HARD_CODED_BUFFER_SIZE [Justified:Unset] "NSCA_Polyspace_Dcm_HARD_CODED_BUFFER_SIZE"  Polyspace-begin MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Dcm_8.7"  Polyspace-begin VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
/* polyspace-end DEFECT:HARD_CODED_BUFFER_SIZE [Justified:Unset] "NSCA_Polyspace_Dcm_HARD_CODED_BUFFER_SIZE"  Polyspace-end MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Dcm_8.7"  Polyspace-end VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
#endif /* STD_ON == DCM_SERVICE_2C_ENABLED */

#if (STD_ON == DCM_SERVICE_86_ENABLED)
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
VAR(Dcm_86_NvMEventInfo_st, DCM_VAR_INIT) Dcm_86_NvMInfo = {DCM_ZERO};
#endif/* STD_ON == DCM_SERVICE_86_ENABLED */

#if (STD_ON == DCM_SERVICE_29_ENABLED)
VAR(uint8, DCM_VAR_INIT) Dcm_AuthenticationState[DCM_29_AUT_ROLE_NUM + 1U][DCM_29_AUT_CONN_NUM + 1U] = {{FALSE}};
#endif /* STD_ON == DCM_SERVICE_29_ENABLED */

#define DCM_STOP_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define DCM_START_SEC_CONFIG_DATA
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

 
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_ServiceTableType_st, DCM_CONFIG_DATA) Dcm_DspServiceInfoTable[DCM_NUM_SERVICES + 1] = /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{0x10U,	DCM_SERVICE_UDS,	2U,	{0x00000005U, 0x7FFFFFFFU},	0x0001U,	DCM_PHY_FUN,	{0x0U, NULL_PTR},	Dcm_10_CheckRule,	Dcm_10_Process,	Dcm_10_Init,	Dcm_10_PostProcess},
	{0x11U,	DCM_SERVICE_UDS,	2U,	{0x00000005U, 0x7FFFFFFFU},	0x0001U,	DCM_PHY_FUN,	{0x0U, NULL_PTR},	Dcm_11_CheckRule,	Dcm_11_Process,	Dcm_11_Init,	Dcm_11_PostProcess},
	{0x14U,	DCM_SERVICE_UDS,	4U,	{0x00000005U, 0x7FFFFFFFU},	0x0001U,	DCM_PHY_FUN,	{0x0U, NULL_PTR},	Dcm_14_CheckRule,	Dcm_14_Process,	Dcm_14_Init,	Dcm_14_PostProcess},
	{0x19U,	DCM_SERVICE_UDS,	2U,	{0x00000005U, 0x7FFFFFFFU},	0x0001U,	DCM_PHY_FUN,	{0x0U, NULL_PTR},	Dcm_19_CheckRule,	Dcm_19_Process,	Dcm_19_Init,	Dcm_19_PostProcess},
	{0x22U,	DCM_SERVICE_UDS,	3U,	{0x00000005U, 0x7FFFFFFFU},	0x0001U,	DCM_PHY_FUN,	{0x0U, NULL_PTR},	Dcm_22_CheckRule,	Dcm_22_Process,	Dcm_22_Init,	Dcm_22_PostProcess},
	{0x27U,	DCM_SERVICE_UDS,	2U,	{0x00000004U, 0x7FFFFFFFU},	0x0001U,	DCM_PHY,	{0x0U, NULL_PTR},	Dcm_27_CheckRule,	Dcm_27_Process,	Dcm_27_Init,	Dcm_27_PostProcess},
	{0x28U,	DCM_SERVICE_UDS,	3U,	{0x00000004U, 0x7FFFFFFFU},	0x0001U,	DCM_PHY_FUN,	{0x0U, NULL_PTR},	Dcm_28_CheckRule,	Dcm_28_Process,	Dcm_28_Init,	Dcm_28_PostProcess},
	{0x2EU,	DCM_SERVICE_UDS,	4U,	{0x00000004U, 0x00000001U},	0x0001U,	DCM_PHY,	{0x0U, NULL_PTR},	Dcm_2E_CheckRule,	Dcm_2E_Process,	Dcm_2E_Init,	Dcm_2E_PostProcess},
	{0x31U,	DCM_SERVICE_UDS,	4U,	{0x00000004U, 0x00000001U},	0x0001U,	DCM_PHY,	{0x0U, NULL_PTR},	Dcm_31_CheckRule,	Dcm_31_Process,	Dcm_31_Init,	Dcm_31_PostProcess},
	{0x3EU,	DCM_SERVICE_UDS,	2U,	{0x00000005U, 0x7FFFFFFFU},	0x0001U,	DCM_PHY_FUN,	{0x0U, NULL_PTR},	Dcm_3E_CheckRule,	Dcm_3E_Process,	Dcm_3E_Init,	Dcm_3E_PostProcess},
	{0x85U,	DCM_SERVICE_UDS,	2U,	{0x00000004U, 0x7FFFFFFFU},	0x0001U,	DCM_PHY_FUN,	{0x0U, NULL_PTR},	Dcm_85_CheckRule,	Dcm_85_Process,	Dcm_85_Init,	Dcm_85_PostProcess},
	// baoenfei for OBD
	{0x01U,	DCM_SERVICE_OBD,	2U,	{0x7FFFFFFFU, 0x7FFFFFFFU},	0x0001U,	DCM_PHY_FUN,	{0x0U, NULL_PTR},	Dcm_01_CheckRule,	Dcm_01_Process,	Dcm_01_Init,	Dcm_01_PostProcess},
	{0x09U,	DCM_SERVICE_OBD,	2U,	{0x7FFFFFFFU, 0x7FFFFFFFU},	0x0001U,	DCM_PHY_FUN,	{0x0U, NULL_PTR},	Dcm_09_CheckRule,	Dcm_09_Process,	Dcm_09_Init,	Dcm_09_PostProcess},
    {0xFFU, 0xFFU,              1U, {0x7FFFFFFFU, 0x7FFFFFFFU}, 0xFFFFU, 0xFFU,          {0x00U, NULL_PTR},	NULL_PTR,   NULL_PTR,       NULL_PTR,       NULL_PTR          }
};
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
CONST(Dcm_DSDInfo_st, DCM_CONFIG_DATA) Dcm_gcaDSDInfo =
{
    Dcm_DspServiceInfoTable
};

/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
CONST(Dcm_DslBufferType, DCM_CONFIG_DATA) Dcm_DslBuffer[DCM_DSL_BUFFERNUM + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
    {
        &Dcm_DslBufferRx[0U],
        DCM_DSL_BUFFERLENRX
    },
    {
        &Dcm_DslBufferRx[0U],
        DCM_DSL_BUFFERLENRX
    },
    {
        NULL_PTR,
        0xFFFFU
    }
};

 
 /*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_DslProtocol_st, DCM_CONFIG_DATA) Dcm_DslProtocol[DCM_DSL_PROTOCOL_NUM + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{0U,	254U,	DCM_PHY,	DCM_UDS_ON_CAN,	0U,	0x1U,	0xFFFFU,	0x7E6U, TRUE, 0x6U},
	{1U,	254U,	DCM_FUN,	DCM_UDS_ON_CAN,	0U,	0x1U,	0xFFFFU,	0x7DFU, TRUE, 0x6U},
	// baoenfei for OBD
	{2U,	255U,	DCM_PHY,	DCM_OBD_ON_CAN,	1U,	0x1U,	0xFFFFU,	0x7E0U, FALSE, 0x6U},
	{3U,	255U,	DCM_FUN,	DCM_OBD_ON_CAN,	1U,	0x1U,	0xFFFFU,	0x7DFU, FALSE, 0x6U},
    {0xFFFFU, 0xFFFFU, 0xFFU, DCM_NO_ACTIVE_PROTOCOL, 0xFFU, 0x0U, 0xFFFFU, 0xFFFFFFFFU, FALSE, 0xFFU}
};

/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */  /* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(uint8, DCM_CONFIG_DATA) Dcm_CfgNetConnComMChannelMap[DCM_DSL_CHANNEL_NUM + 1] =
{
	0x06U,
    0xFFU
};

#if ( STD_ON == DCM_SERVICE_01_ENABLED )	
	/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
CONST(Dcm_01_PidType_st, DCM_CONFIG_DATA) Dcm_01_SupportPID[DCM_01_SUPPRORTPID + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{0xFFU, 0x00U, NULL_PTR, NULL_PTR,},
};
	
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_01_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_01_PIDInfo[DCM_01_SUBID + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	/* Polyspace-begin MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
	{0x00U, DCM_01_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0x20U, DCM_01_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0x40U, DCM_01_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0x60U, DCM_01_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0x80U, DCM_01_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0xA0U, DCM_01_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0xC0U, DCM_01_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0xE0U, DCM_01_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0xFFU, DCM_01_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	/* Polyspace-end MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
};
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_01_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_01_Dispatcher =
{
    Dcm_01_PIDInfo,
    Dcm_01_SupportPID,
};
#endif/* DCM_SERVICE_01_ENABLED */

#if ( STD_ON == DCM_SERVICE_02_ENABLED )
	
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_02_PidType_st, DCM_CONFIG_DATA) Dcm_02_SupportPID[DCM_02_SUPPRORTPID + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{0xFFU, 0x00U, NULL_PTR, NULL_PTR, 0U
	/* Polyspace-end MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */}
};
	
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"   Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_02_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_02_PIDInfo[DCM_02_SUBID + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	/* Polyspace-begin MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
	{0x00U, DCM_02_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0x20U, DCM_02_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0x40U, DCM_02_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0x60U, DCM_02_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0x80U, DCM_02_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0xA0U, DCM_02_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0xFFU, DCM_02_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	/* Polyspace-end MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
};
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_02_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_02_Dispatcher =
{
    Dcm_02_PIDInfo,
    Dcm_02_SupportPID,
    Dcm_02_PidList

};
#endif /* STD_ON == DCM_SERVICE_02_ENABLED */

#if ( STD_ON == DCM_SERVICE_09_ENABLED )
	
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_09_PidType_st, DCM_CONFIG_DATA) Dcm_09_SupportPID[DCM_09_SUPPRORTPID + 1] =   /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	/* Polyspace-begin MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
	{0x02U, 0x11U, NULL_PTR, Dcm_InfotypeServices_Pid02},
	{0xFFU, 0x00U, NULL_PTR, NULL_PTR},
	/* Polyspace-end MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
};
	
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_09_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_09_PIDInfo[DCM_09_SUBID + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	/* Polyspace-begin MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
	{0x00U, DCM_09_MRESQ, NULL_PTR, 0x40000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0x20U, DCM_09_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0x40U, DCM_09_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0x60U, DCM_09_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0x80U, DCM_09_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0xA0U, DCM_09_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0xC0U, DCM_09_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0xE0U, DCM_09_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	{0xFFU, DCM_09_NO_MRESQ, NULL_PTR, 0x00000000U},  /* PRQA S 4424 */ /* NSCA_QAC_Common_AutosarBoolean */
	/* Polyspace-end MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
};
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_09_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_09_Dispatcher =
{
    Dcm_09_PIDInfo,
    Dcm_09_SupportPID,
};
#endif /* STD_ON == DCM_SERVICE_09_ENABLED */

 
#if (STD_ON == DCM_SERVICE_10_ENABLED)
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_10_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_10_ServiceInfo[DCM_10_SUBID + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{0x01U,	DCM_PHY_FUN,	{0x00000005U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	{DCM_P2_TIME_01, DCM_P2EX_TIME_01},	DCM_NO_BOOT,	DCM_SESSION_DEFAULT_LEVEL,	NULL_PTR},
	{0x02U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	{DCM_P2_TIME_02, DCM_P2EX_TIME_02},	DCM_SYS_BOOT,	DCM_SESSION_PROG_LEVEL,	Dcm_Check10SubProgrammingFunc},
	{0x03U,	DCM_PHY_FUN,	{0x00000005U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	{DCM_P2_TIME_03, DCM_P2EX_TIME_03},	DCM_NO_BOOT,	DCM_SESSION_EXTEND_LEVEL,	Dcm_Check10SubextendedFunc},
	{0x81U,	DCM_PHY_FUN,	{0x00000005U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	{DCM_P2_TIME_01, DCM_P2EX_TIME_01},	DCM_NO_BOOT,	DCM_SESSION_DEFAULT_LEVEL,	NULL_PTR},
	{0x82U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	{DCM_P2_TIME_02, DCM_P2EX_TIME_02},	DCM_SYS_BOOT,	DCM_SESSION_PROG_LEVEL,	Dcm_Check10SubProgrammingFunc},
	{0x83U,	DCM_PHY_FUN,	{0x00000005U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	{DCM_P2_TIME_03, DCM_P2EX_TIME_03},	DCM_NO_BOOT,	DCM_SESSION_EXTEND_LEVEL,	Dcm_Check10SubextendedFunc},
	{0xFFU,	DCM_PHY_FUN,	{0x7FFFFFFFU, 0x7FFFFFFFU},	{0x0U, NULL_PTR},   {0xFFU, 0xFFU},	DCM_NO_BOOT,	DCM_SESSION_DEFAULT_LEVEL,	NULL_PTR}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_10_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_10_Dispatcher =
{
	Dcm_10_ServiceInfo
};
#endif /* STD_ON == DCM_SERVICE_10_ENABLED */

 
#if (STD_ON == DCM_SERVICE_11_ENABLED)
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */ /* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_11_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_11_ServiceInfo[DCM_11_SUBID + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{0x01U,	DCM_PHY_FUN,	DCM_BEFORE_RESET,	{0x00000005U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check11SubResetFunc,	Dcm_PrepareResetFunc},
	{0x03U,	DCM_PHY_FUN,	DCM_BEFORE_RESET,	{0x00000005U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check11SubResetFunc,	Dcm_PrepareResetFunc},
	{0x81U,	DCM_PHY_FUN,	DCM_BEFORE_RESET,	{0x00000005U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check11SubResetFunc,	Dcm_PrepareResetFunc},
	{0x83U,	DCM_PHY_FUN,	DCM_BEFORE_RESET,	{0x00000005U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check11SubResetFunc,	Dcm_PrepareResetFunc},
	{0xFFU,	DCM_PHY_FUN,    DCM_BEFORE_RESET,	{0x7FFFFFFFU, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	NULL_PTR,	NULL_PTR}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_11_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_11_Dispatcher =
{
	Dcm_11_ServiceInfo
};
#endif /* STD_ON == DCM_SERVICE_11_ENABLED */

 
#if (STD_ON == DCM_SERVICE_14_ENABLED)
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_14_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_14_ServiceInfo[DCM_14_SUBID_NUM + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{{0x7FFFFFFFU, 0x7FFFFFFFU},	Dcm_14_CheckRuleFunc,	Dcm_ClearCallBackFunc}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_g14DispatherInfo_st, DCM_CONFIG_DATA) Dcm_14_Dispatcher =
{
	Dcm_14_ServiceInfo,
};
#endif /* STD_ON == DCM_SERVICE_14_ENABLED */

 
#if (STD_ON == DCM_SERVICE_19_ENABLED)
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_19_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_19_ServiceInfo[DCM_19_SUBIDNUM + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{0x01U,	DCM_PHY_FUN,	DCM_NO_STOP_DTC,	{0x00000005U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	0x01U,	Dcm_Dsp_1901_Process,	NULL_PTR},
	{0x02U,	DCM_PHY_FUN,	DCM_NO_STOP_DTC,	{0x00000005U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	0x01U,	Dcm_Dsp_1902_Process,	NULL_PTR},
	{0x04U,	DCM_PHY_FUN,	DCM_STOP_DTC,	{0x00000005U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	0x04U,	Dcm_Dsp_1904_Process,	NULL_PTR},
	{0x06U,	DCM_PHY_FUN,	DCM_STOP_DTC,	{0x00000005U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	0x04U,	Dcm_Dsp_1906_Process,	NULL_PTR},
	{0x0AU,	DCM_PHY_FUN,	DCM_NO_STOP_DTC,	{0x00000005U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	0x00U,	Dcm_Dsp_190A_Process,	NULL_PTR},
	{0xFFU,	DCM_PHY_FUN,	DCM_NO_STOP_DTC,		{0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR},   0x00U,	NULL_PTR,	NULL_PTR},
};
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
CONST(Dcm_19_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_19_Dispatcher = 
{
	Dcm_19_ServiceInfo,
};
#endif /* STD_ON == DCM_SERVICE_19_ENABLED */

 
#if ( (STD_ON == DCM_SERVICE_22_ENABLED) || (STD_ON == DCM_SERVICE_2E_ENABLED) || (STD_ON == DCM_SERVICE_2A_ENABLED) || (STD_ON == DCM_SERVICE_2C_ENABLED) )
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
CONST(Dcm_22_2E_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_22_2E_ServiceInfo[DCM_NUM_DIDS + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{0xF199U, TRUE, 0x04U, 144, (uint8*)&Dcm_Did_Block0090_Data,	Dcm_Did_Block0090_Data.Dcm_DidF199Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F199_ReadData, NULL_PTR}, Dcm_DidMgr_F199_ReadDataLength, {Dcm_DidMgr_F199_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF187U, TRUE, 0x15U, 166, (uint8*)&Dcm_Did_Block00A6_Data,	Dcm_Did_Block00A6_Data.Dcm_DidF187Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F187_ReadData, NULL_PTR}, Dcm_DidMgr_F187_ReadDataLength, {Dcm_DidMgr_F187_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF18AU, TRUE, 0x06U, 168, (uint8*)&Dcm_Did_Block00A8_Data,	Dcm_Did_Block00A8_Data.Dcm_DidF18ABuffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F18A_ReadData, NULL_PTR}, Dcm_DidMgr_F18A_ReadDataLength, {Dcm_DidMgr_F18A_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF190U, TRUE, 0x11U, 145, (uint8*)&Dcm_Did_Block0091_Data,	Dcm_Did_Block0091_Data.Dcm_DidF190Buffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F190_ReadData, NULL_PTR}, Dcm_DidMgr_F190_ReadDataLength, {Dcm_DidMgr_F190_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_F190_WriteData, NULL_PTR}, Dcm_DidMgr_F190_ConditionCheckWrite, NULL_PTR},
	{0xF1A2U, TRUE, 0x04U, 146, (uint8*)&Dcm_Did_Block0092_Data,	Dcm_Did_Block0092_Data.Dcm_DidF1A2Buffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F1A2_ReadData, NULL_PTR}, Dcm_DidMgr_F1A2_ReadDataLength, {Dcm_DidMgr_F1A2_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_F1A2_WriteData, NULL_PTR}, Dcm_DidMgr_F1A2_ConditionCheckWrite, NULL_PTR},
	{0xF191U, TRUE, 0x0AU, 169, (uint8*)&Dcm_Did_Block00A9_Data,	Dcm_Did_Block00A9_Data.Dcm_DidF191Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F191_ReadData, NULL_PTR}, Dcm_DidMgr_F191_ReadDataLength, {Dcm_DidMgr_F191_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF189U, TRUE, 0x0AU, 170, (uint8*)&Dcm_Did_Block00AA_Data,	Dcm_Did_Block00AA_Data.Dcm_DidF189Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F189_ReadData, NULL_PTR}, Dcm_DidMgr_F189_ReadDataLength, {Dcm_DidMgr_F189_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF193U, TRUE, 0x10U, 171, (uint8*)&Dcm_Did_Block00AB_Data,	Dcm_Did_Block00AB_Data.Dcm_DidF193Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F193_ReadData, NULL_PTR}, Dcm_DidMgr_F193_ReadDataLength, {Dcm_DidMgr_F193_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF195U, TRUE, 0x10U, 172, (uint8*)&Dcm_Did_Block00AC_Data,	Dcm_Did_Block00AC_Data.Dcm_DidF195Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F195_ReadData, NULL_PTR}, Dcm_DidMgr_F195_ReadDataLength, {Dcm_DidMgr_F195_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF180U, TRUE, 0x10U, 173, (uint8*)&Dcm_Did_Block00AD_Data,	Dcm_Did_Block00AD_Data.Dcm_DidF180Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F180_ReadData, NULL_PTR}, Dcm_DidMgr_F180_ReadDataLength, {Dcm_DidMgr_F180_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF112U, TRUE, 0x08U, 147, (uint8*)&Dcm_Did_Block0093_Data,	Dcm_Did_Block0093_Data.Dcm_DidF112Buffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F112_ReadData, NULL_PTR}, Dcm_DidMgr_F112_ReadDataLength, {Dcm_DidMgr_F112_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_F112_WriteData, NULL_PTR}, Dcm_DidMgr_F112_ConditionCheckWrite, NULL_PTR},
	{0xF198U, TRUE, 0x10U, 148, (uint8*)&Dcm_Did_Block0094_Data,	Dcm_Did_Block0094_Data.Dcm_DidF198Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F198_ReadData, NULL_PTR}, Dcm_DidMgr_F198_ReadDataLength, {Dcm_DidMgr_F198_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF197U, TRUE, 0x08U, 149, (uint8*)&Dcm_Did_Block0095_Data,	Dcm_Did_Block0095_Data.Dcm_DidF197Buffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F197_ReadData, NULL_PTR}, Dcm_DidMgr_F197_ReadDataLength, {Dcm_DidMgr_F197_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_F197_WriteData, NULL_PTR}, Dcm_DidMgr_F197_ConditionCheckWrite, NULL_PTR},
	{0xF113U, TRUE, 0x04U, 174, (uint8*)&Dcm_Did_Block00AE_Data,	Dcm_Did_Block00AE_Data.Dcm_DidF113Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F113_ReadData, NULL_PTR}, Dcm_DidMgr_F113_ReadDataLength, {Dcm_DidMgr_F113_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF182U, TRUE, 0x10U, 175, (uint8*)&Dcm_Did_Block00AF_Data,	Dcm_Did_Block00AF_Data.Dcm_DidF182Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F182_ReadData, NULL_PTR}, Dcm_DidMgr_F182_ReadDataLength, {Dcm_DidMgr_F182_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF186U, TRUE, 0x01U, 176, (uint8*)&Dcm_Did_Block00B0_Data,	Dcm_Did_Block00B0_Data.Dcm_DidF186Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F186_ReadData, NULL_PTR}, Dcm_DidMgr_F186_ReadDataLength, {Dcm_DidMgr_F186_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF18BU, TRUE, 0x04U, 177, (uint8*)&Dcm_Did_Block00B1_Data,	Dcm_Did_Block00B1_Data.Dcm_DidF18BBuffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F18B_ReadData, NULL_PTR}, Dcm_DidMgr_F18B_ReadDataLength, {Dcm_DidMgr_F18B_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF18CU, TRUE, 0x18U, 167, (uint8*)&Dcm_Did_Block00A7_Data,	Dcm_Did_Block00A7_Data.Dcm_DidF18CBuffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F18C_ReadData, NULL_PTR}, Dcm_DidMgr_F18C_ReadDataLength, {Dcm_DidMgr_F18C_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0200U, TRUE, 0x01U, 178, (uint8*)&Dcm_Did_Block00B2_Data,	Dcm_Did_Block00B2_Data.Dcm_Did0200Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_0200_ReadData, NULL_PTR}, Dcm_DidMgr_0200_ReadDataLength, {Dcm_DidMgr_0200_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0201U, TRUE, 0x01U, 179, (uint8*)&Dcm_Did_Block00B3_Data,	Dcm_Did_Block00B3_Data.Dcm_Did0201Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_0201_ReadData, NULL_PTR}, Dcm_DidMgr_0201_ReadDataLength, {Dcm_DidMgr_0201_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xDFECU, TRUE, 0x40U, 150, (uint8*)&Dcm_Did_Block0096_Data,	Dcm_Did_Block0096_Data.Dcm_DidDFECBuffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_DFEC_ReadData, NULL_PTR}, Dcm_DidMgr_DFEC_ReadDataLength, {Dcm_DidMgr_DFEC_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_DFEC_WriteData, NULL_PTR}, Dcm_DidMgr_DFEC_ConditionCheckWrite, NULL_PTR},
	{0xDFEDU, TRUE, 0x40U, 151, (uint8*)&Dcm_Did_Block0097_Data,	Dcm_Did_Block0097_Data.Dcm_DidDFEDBuffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_DFED_ReadData, NULL_PTR}, Dcm_DidMgr_DFED_ReadDataLength, {Dcm_DidMgr_DFED_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_DFED_WriteData, NULL_PTR}, Dcm_DidMgr_DFED_ConditionCheckWrite, NULL_PTR},
	{0xDFEEU, TRUE, 0x40U, 152, (uint8*)&Dcm_Did_Block0098_Data,	Dcm_Did_Block0098_Data.Dcm_DidDFEEBuffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_DFEE_ReadData, NULL_PTR}, Dcm_DidMgr_DFEE_ReadDataLength, {Dcm_DidMgr_DFEE_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_DFEE_WriteData, NULL_PTR}, Dcm_DidMgr_DFEE_ConditionCheckWrite, NULL_PTR},
	{0xDFEFU, TRUE, 0x40U, 153, (uint8*)&Dcm_Did_Block0099_Data,	Dcm_Did_Block0099_Data.Dcm_DidDFEFBuffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_DFEF_ReadData, NULL_PTR}, Dcm_DidMgr_DFEF_ReadDataLength, {Dcm_DidMgr_DFEF_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_DFEF_WriteData, NULL_PTR}, Dcm_DidMgr_DFEF_ConditionCheckWrite, NULL_PTR},
	{0xF101U, TRUE, 0x08U, 154, (uint8*)&Dcm_Did_Block009A_Data,	Dcm_Did_Block009A_Data.Dcm_DidF101Buffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F101_ReadData, NULL_PTR}, Dcm_DidMgr_F101_ReadDataLength, {Dcm_DidMgr_F101_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_F101_WriteData, NULL_PTR}, Dcm_DidMgr_F101_ConditionCheckWrite, NULL_PTR},
	{0xF110U, TRUE, 0x08U, 155, (uint8*)&Dcm_Did_Block009B_Data,	Dcm_Did_Block009B_Data.Dcm_DidF110Buffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F110_ReadData, NULL_PTR}, Dcm_DidMgr_F110_ReadDataLength, {Dcm_DidMgr_F110_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_F110_WriteData, NULL_PTR}, Dcm_DidMgr_F110_ConditionCheckWrite, NULL_PTR},
	{0xF1A3U, TRUE, 0x10U, 180, (uint8*)&Dcm_Did_Block00B4_Data,	Dcm_Did_Block00B4_Data.Dcm_DidF1A3Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F1A3_ReadData, NULL_PTR}, Dcm_DidMgr_F1A3_ReadDataLength, {Dcm_DidMgr_F1A3_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF1A4U, TRUE, 0x10U, 181, (uint8*)&Dcm_Did_Block00B5_Data,	Dcm_Did_Block00B5_Data.Dcm_DidF1A4Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F1A4_ReadData, NULL_PTR}, Dcm_DidMgr_F1A4_ReadDataLength, {Dcm_DidMgr_F1A4_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF1A5U, TRUE, 0x10U, 182, (uint8*)&Dcm_Did_Block00B6_Data,	Dcm_Did_Block00B6_Data.Dcm_DidF1A5Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F1A5_ReadData, NULL_PTR}, Dcm_DidMgr_F1A5_ReadDataLength, {Dcm_DidMgr_F1A5_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xD135U, TRUE, 0x10U, 156, (uint8*)&Dcm_Did_Block009C_Data,	Dcm_Did_Block009C_Data.Dcm_DidD135Buffer, DCM_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {NULL_PTR, NULL_PTR}, Dcm_DidMgr_D135_ReadDataLength, {NULL_PTR, NULL_PTR}, {Dcm_DidMgr_D135_WriteData, NULL_PTR}, Dcm_DidMgr_D135_ConditionCheckWrite, NULL_PTR},
	{0xD136U, TRUE, 0x10U, 157, (uint8*)&Dcm_Did_Block009D_Data,	Dcm_Did_Block009D_Data.Dcm_DidD136Buffer, DCM_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {NULL_PTR, NULL_PTR}, Dcm_DidMgr_D136_ReadDataLength, {NULL_PTR, NULL_PTR}, {Dcm_DidMgr_D136_WriteData, NULL_PTR}, Dcm_DidMgr_D136_ConditionCheckWrite, NULL_PTR},
	{0x0280U, TRUE, 0x10U, 158, (uint8*)&Dcm_Did_Block009E_Data,	Dcm_Did_Block009E_Data.Dcm_Did0280Buffer, DCM_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {NULL_PTR, NULL_PTR}, Dcm_DidMgr_0280_ReadDataLength, {NULL_PTR, NULL_PTR}, {Dcm_DidMgr_0280_WriteData, NULL_PTR}, Dcm_DidMgr_0280_ConditionCheckWrite, NULL_PTR},
	{0x0310U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0310Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0310_ReadData}, Dcm_DidMgr_0310_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0310_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0311U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0311Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0311_ReadData}, Dcm_DidMgr_0311_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0311_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0312U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0312Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0312_ReadData}, Dcm_DidMgr_0312_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0312_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0313U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0313Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0313_ReadData}, Dcm_DidMgr_0313_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0313_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0314U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0314Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0314_ReadData}, Dcm_DidMgr_0314_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0314_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0315U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0315Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0315_ReadData}, Dcm_DidMgr_0315_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0315_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0316U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0316Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0316_ReadData}, Dcm_DidMgr_0316_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0316_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0317U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0317Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0317_ReadData}, Dcm_DidMgr_0317_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0317_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0318U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0318Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0318_ReadData}, Dcm_DidMgr_0318_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0318_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0319U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0319Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0319_ReadData}, Dcm_DidMgr_0319_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0319_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x031AU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did031ABuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_031A_ReadData}, Dcm_DidMgr_031A_ReadDataLength, {NULL_PTR, Dcm_DidMgr_031A_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x031BU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did031BBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_031B_ReadData}, Dcm_DidMgr_031B_ReadDataLength, {NULL_PTR, Dcm_DidMgr_031B_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x031CU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did031CBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_031C_ReadData}, Dcm_DidMgr_031C_ReadDataLength, {NULL_PTR, Dcm_DidMgr_031C_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x031DU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did031DBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_031D_ReadData}, Dcm_DidMgr_031D_ReadDataLength, {NULL_PTR, Dcm_DidMgr_031D_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x031EU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did031EBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_031E_ReadData}, Dcm_DidMgr_031E_ReadDataLength, {NULL_PTR, Dcm_DidMgr_031E_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x031FU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did031FBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_031F_ReadData}, Dcm_DidMgr_031F_ReadDataLength, {NULL_PTR, Dcm_DidMgr_031F_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0320U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0320Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0320_ReadData}, Dcm_DidMgr_0320_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0320_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0321U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0321Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0321_ReadData}, Dcm_DidMgr_0321_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0321_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0322U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0322Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0322_ReadData}, Dcm_DidMgr_0322_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0322_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0323U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0323Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0323_ReadData}, Dcm_DidMgr_0323_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0323_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0324U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0324Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0324_ReadData}, Dcm_DidMgr_0324_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0324_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0325U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0325Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0325_ReadData}, Dcm_DidMgr_0325_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0325_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0326U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0326Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0326_ReadData}, Dcm_DidMgr_0326_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0326_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0327U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0327Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0327_ReadData}, Dcm_DidMgr_0327_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0327_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0328U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0328Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0328_ReadData}, Dcm_DidMgr_0328_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0328_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0329U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0329Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0329_ReadData}, Dcm_DidMgr_0329_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0329_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x032AU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did032ABuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_032A_ReadData}, Dcm_DidMgr_032A_ReadDataLength, {NULL_PTR, Dcm_DidMgr_032A_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x032BU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did032BBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_032B_ReadData}, Dcm_DidMgr_032B_ReadDataLength, {NULL_PTR, Dcm_DidMgr_032B_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x032CU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did032CBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_032C_ReadData}, Dcm_DidMgr_032C_ReadDataLength, {NULL_PTR, Dcm_DidMgr_032C_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x032DU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did032DBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_032D_ReadData}, Dcm_DidMgr_032D_ReadDataLength, {NULL_PTR, Dcm_DidMgr_032D_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x032EU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did032EBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_032E_ReadData}, Dcm_DidMgr_032E_ReadDataLength, {NULL_PTR, Dcm_DidMgr_032E_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x032FU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did032FBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_032F_ReadData}, Dcm_DidMgr_032F_ReadDataLength, {NULL_PTR, Dcm_DidMgr_032F_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0330U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0330Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0330_ReadData}, Dcm_DidMgr_0330_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0330_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0331U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0331Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0331_ReadData}, Dcm_DidMgr_0331_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0331_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0332U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0332Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0332_ReadData}, Dcm_DidMgr_0332_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0332_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0333U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0333Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0333_ReadData}, Dcm_DidMgr_0333_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0333_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0334U, TRUE, 0x03U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0334Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0334_ReadData}, Dcm_DidMgr_0334_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0334_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0335U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0335Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0335_ReadData}, Dcm_DidMgr_0335_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0335_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xDF00U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidDF00Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_DF00_ReadData}, Dcm_DidMgr_DF00_ReadDataLength, {NULL_PTR, Dcm_DidMgr_DF00_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0501U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0501Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0501_ReadData}, Dcm_DidMgr_0501_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0501_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0502U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0502Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0502_ReadData}, Dcm_DidMgr_0502_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0502_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0503U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0503Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0503_ReadData}, Dcm_DidMgr_0503_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0503_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0504U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0504Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0504_ReadData}, Dcm_DidMgr_0504_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0504_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0507U, TRUE, 0xFFU, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0507Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0507_ReadData}, Dcm_DidMgr_0507_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0507_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x050AU, TRUE, 0x36U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did050ABuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_050A_ReadData}, Dcm_DidMgr_050A_ReadDataLength, {NULL_PTR, Dcm_DidMgr_050A_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xCF00U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidCF00Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_CF00_ReadData}, Dcm_DidMgr_CF00_ReadDataLength, {NULL_PTR, Dcm_DidMgr_CF00_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xCF05U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidCF05Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_CF05_ReadData}, Dcm_DidMgr_CF05_ReadDataLength, {NULL_PTR, Dcm_DidMgr_CF05_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xDF09U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidDF09Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_DF09_ReadData}, Dcm_DidMgr_DF09_ReadDataLength, {NULL_PTR, Dcm_DidMgr_DF09_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0525U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0525Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0525_ReadData}, Dcm_DidMgr_0525_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0525_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0526U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0526Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0526_ReadData}, Dcm_DidMgr_0526_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0526_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0527U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0527Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0527_ReadData}, Dcm_DidMgr_0527_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0527_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0528U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0528Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0528_ReadData}, Dcm_DidMgr_0528_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0528_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0529U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0529Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0529_ReadData}, Dcm_DidMgr_0529_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0529_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xCF06U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidCF06Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_CF06_ReadData}, Dcm_DidMgr_CF06_ReadDataLength, {NULL_PTR, Dcm_DidMgr_CF06_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x052BU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did052BBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_052B_ReadData}, Dcm_DidMgr_052B_ReadDataLength, {NULL_PTR, Dcm_DidMgr_052B_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xCF07U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidCF07Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_CF07_ReadData}, Dcm_DidMgr_CF07_ReadDataLength, {NULL_PTR, Dcm_DidMgr_CF07_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x052DU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did052DBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_052D_ReadData}, Dcm_DidMgr_052D_ReadDataLength, {NULL_PTR, Dcm_DidMgr_052D_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0530U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0530Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0530_ReadData}, Dcm_DidMgr_0530_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0530_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0531U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0531Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0531_ReadData}, Dcm_DidMgr_0531_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0531_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0532U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0532Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0532_ReadData}, Dcm_DidMgr_0532_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0532_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0533U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0533Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0533_ReadData}, Dcm_DidMgr_0533_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0533_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0534U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0534Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0534_ReadData}, Dcm_DidMgr_0534_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0534_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0535U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0535Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0535_ReadData}, Dcm_DidMgr_0535_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0535_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0536U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0536Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0536_ReadData}, Dcm_DidMgr_0536_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0536_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0537U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0537Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0537_ReadData}, Dcm_DidMgr_0537_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0537_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0538U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0538Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0538_ReadData}, Dcm_DidMgr_0538_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0538_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0539U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0539Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0539_ReadData}, Dcm_DidMgr_0539_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0539_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0505U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0505Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0505_ReadData}, Dcm_DidMgr_0505_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0505_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x053BU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did053BBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_053B_ReadData}, Dcm_DidMgr_053B_ReadDataLength, {NULL_PTR, Dcm_DidMgr_053B_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x053CU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did053CBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_053C_ReadData}, Dcm_DidMgr_053C_ReadDataLength, {NULL_PTR, Dcm_DidMgr_053C_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x053DU, TRUE, 0x04U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did053DBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_053D_ReadData}, Dcm_DidMgr_053D_ReadDataLength, {NULL_PTR, Dcm_DidMgr_053D_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x053EU, TRUE, 0x04U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did053EBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_053E_ReadData}, Dcm_DidMgr_053E_ReadDataLength, {NULL_PTR, Dcm_DidMgr_053E_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0542U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0542Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0542_ReadData}, Dcm_DidMgr_0542_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0542_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0543U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0543Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0543_ReadData}, Dcm_DidMgr_0543_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0543_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0544U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0544Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0544_ReadData}, Dcm_DidMgr_0544_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0544_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0545U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0545Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0545_ReadData}, Dcm_DidMgr_0545_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0545_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0547U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0547Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0547_ReadData}, Dcm_DidMgr_0547_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0547_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0552U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0552Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0552_ReadData}, Dcm_DidMgr_0552_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0552_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x055AU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did055ABuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_055A_ReadData}, Dcm_DidMgr_055A_ReadDataLength, {NULL_PTR, Dcm_DidMgr_055A_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x055CU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did055CBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_055C_ReadData}, Dcm_DidMgr_055C_ReadDataLength, {NULL_PTR, Dcm_DidMgr_055C_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x055DU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did055DBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_055D_ReadData}, Dcm_DidMgr_055D_ReadDataLength, {NULL_PTR, Dcm_DidMgr_055D_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0585U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0585Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0585_ReadData}, Dcm_DidMgr_0585_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0585_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0586U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0586Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0586_ReadData}, Dcm_DidMgr_0586_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0586_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0587U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0587Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0587_ReadData}, Dcm_DidMgr_0587_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0587_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0588U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0588Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0588_ReadData}, Dcm_DidMgr_0588_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0588_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0589U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0589Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0589_ReadData}, Dcm_DidMgr_0589_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0589_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x058AU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did058ABuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_058A_ReadData}, Dcm_DidMgr_058A_ReadDataLength, {NULL_PTR, Dcm_DidMgr_058A_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x058BU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did058BBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_058B_ReadData}, Dcm_DidMgr_058B_ReadDataLength, {NULL_PTR, Dcm_DidMgr_058B_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x058CU, TRUE, 0x03U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did058CBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_058C_ReadData}, Dcm_DidMgr_058C_ReadDataLength, {NULL_PTR, Dcm_DidMgr_058C_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x058DU, TRUE, 0x03U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did058DBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_058D_ReadData}, Dcm_DidMgr_058D_ReadDataLength, {NULL_PTR, Dcm_DidMgr_058D_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x058EU, TRUE, 0x03U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did058EBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_058E_ReadData}, Dcm_DidMgr_058E_ReadDataLength, {NULL_PTR, Dcm_DidMgr_058E_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x058FU, TRUE, 0x03U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did058FBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_058F_ReadData}, Dcm_DidMgr_058F_ReadDataLength, {NULL_PTR, Dcm_DidMgr_058F_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0590U, TRUE, 0x03U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0590Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0590_ReadData}, Dcm_DidMgr_0590_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0590_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0591U, TRUE, 0x03U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0591Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0591_ReadData}, Dcm_DidMgr_0591_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0591_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0592U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0592Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0592_ReadData}, Dcm_DidMgr_0592_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0592_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0593U, TRUE, 0x30U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0593Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0593_ReadData}, Dcm_DidMgr_0593_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0593_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0594U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0594Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0594_ReadData}, Dcm_DidMgr_0594_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0594_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0595U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0595Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0595_ReadData}, Dcm_DidMgr_0595_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0595_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0596U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0596Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0596_ReadData}, Dcm_DidMgr_0596_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0596_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0597U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0597Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0597_ReadData}, Dcm_DidMgr_0597_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0597_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0598U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0598Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0598_ReadData}, Dcm_DidMgr_0598_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0598_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0599U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0599Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0599_ReadData}, Dcm_DidMgr_0599_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0599_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x059AU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did059ABuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_059A_ReadData}, Dcm_DidMgr_059A_ReadDataLength, {NULL_PTR, Dcm_DidMgr_059A_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x059BU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did059BBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_059B_ReadData}, Dcm_DidMgr_059B_ReadDataLength, {NULL_PTR, Dcm_DidMgr_059B_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x059DU, TRUE, 0x08U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did059DBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_059D_ReadData}, Dcm_DidMgr_059D_ReadDataLength, {NULL_PTR, Dcm_DidMgr_059D_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x059EU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did059EBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_059E_ReadData}, Dcm_DidMgr_059E_ReadDataLength, {NULL_PTR, Dcm_DidMgr_059E_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x059FU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did059FBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_059F_ReadData}, Dcm_DidMgr_059F_ReadDataLength, {NULL_PTR, Dcm_DidMgr_059F_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xDD00U, TRUE, 0x06U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidDD00Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_DD00_ReadData}, Dcm_DidMgr_DD00_ReadDataLength, {NULL_PTR, Dcm_DidMgr_DD00_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05A1U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05A1Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05A1_ReadData}, Dcm_DidMgr_05A1_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05A1_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05A2U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05A2Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05A2_ReadData}, Dcm_DidMgr_05A2_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05A2_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05A3U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05A3Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05A3_ReadData}, Dcm_DidMgr_05A3_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05A3_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05A4U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05A4Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05A4_ReadData}, Dcm_DidMgr_05A4_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05A4_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05A5U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05A5Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05A5_ReadData}, Dcm_DidMgr_05A5_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05A5_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05A6U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05A6Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05A6_ReadData}, Dcm_DidMgr_05A6_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05A6_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05A7U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05A7Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05A7_ReadData}, Dcm_DidMgr_05A7_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05A7_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05A8U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05A8Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05A8_ReadData}, Dcm_DidMgr_05A8_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05A8_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05A9U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05A9Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05A9_ReadData}, Dcm_DidMgr_05A9_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05A9_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05AAU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05AABuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05AA_ReadData}, Dcm_DidMgr_05AA_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05AA_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05ABU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05ABBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05AB_ReadData}, Dcm_DidMgr_05AB_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05AB_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05ACU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05ACBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05AC_ReadData}, Dcm_DidMgr_05AC_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05AC_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05ADU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05ADBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05AD_ReadData}, Dcm_DidMgr_05AD_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05AD_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05AEU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05AEBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05AE_ReadData}, Dcm_DidMgr_05AE_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05AE_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05AFU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05AFBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05AF_ReadData}, Dcm_DidMgr_05AF_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05AF_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05B0U, TRUE, 0x30U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05B0Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05B0_ReadData}, Dcm_DidMgr_05B0_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05B0_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05B1U, TRUE, 0x30U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05B1Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05B1_ReadData}, Dcm_DidMgr_05B1_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05B1_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05B2U, TRUE, 0x120U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05B2Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05B2_ReadData}, Dcm_DidMgr_05B2_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05B2_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05B3U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05B3Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05B3_ReadData}, Dcm_DidMgr_05B3_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05B3_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05B4U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05B4Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05B4_ReadData}, Dcm_DidMgr_05B4_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05B4_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05B5U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05B5Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05B5_ReadData}, Dcm_DidMgr_05B5_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05B5_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05B6U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05B6Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05B6_ReadData}, Dcm_DidMgr_05B6_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05B6_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05B7U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05B7Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05B7_ReadData}, Dcm_DidMgr_05B7_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05B7_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05B8U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05B8Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05B8_ReadData}, Dcm_DidMgr_05B8_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05B8_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05B9U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05B9Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05B9_ReadData}, Dcm_DidMgr_05B9_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05B9_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05BAU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05BABuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05BA_ReadData}, Dcm_DidMgr_05BA_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05BA_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05BBU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05BBBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05BB_ReadData}, Dcm_DidMgr_05BB_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05BB_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05BCU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05BCBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05BC_ReadData}, Dcm_DidMgr_05BC_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05BC_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05BDU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05BDBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05BD_ReadData}, Dcm_DidMgr_05BD_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05BD_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05BEU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05BEBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05BE_ReadData}, Dcm_DidMgr_05BE_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05BE_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05BFU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05BFBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05BF_ReadData}, Dcm_DidMgr_05BF_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05BF_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05C0U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05C0Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05C0_ReadData}, Dcm_DidMgr_05C0_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05C0_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05C1U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05C1Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05C1_ReadData}, Dcm_DidMgr_05C1_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05C1_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05C2U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05C2Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05C2_ReadData}, Dcm_DidMgr_05C2_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05C2_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05C3U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05C3Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05C3_ReadData}, Dcm_DidMgr_05C3_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05C3_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05C4U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05C4Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05C4_ReadData}, Dcm_DidMgr_05C4_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05C4_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05C5U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05C5Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05C5_ReadData}, Dcm_DidMgr_05C5_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05C5_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05C6U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05C6Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05C6_ReadData}, Dcm_DidMgr_05C6_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05C6_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05C7U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05C7Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05C7_ReadData}, Dcm_DidMgr_05C7_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05C7_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05C8U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05C8Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05C8_ReadData}, Dcm_DidMgr_05C8_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05C8_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05C9U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05C9Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05C9_ReadData}, Dcm_DidMgr_05C9_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05C9_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05CAU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05CABuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05CA_ReadData}, Dcm_DidMgr_05CA_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05CA_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05CBU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05CBBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05CB_ReadData}, Dcm_DidMgr_05CB_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05CB_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05CCU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05CCBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05CC_ReadData}, Dcm_DidMgr_05CC_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05CC_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05CDU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05CDBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05CD_ReadData}, Dcm_DidMgr_05CD_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05CD_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05CEU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05CEBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05CE_ReadData}, Dcm_DidMgr_05CE_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05CE_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05CFU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05CFBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05CF_ReadData}, Dcm_DidMgr_05CF_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05CF_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05D0U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05D0Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05D0_ReadData}, Dcm_DidMgr_05D0_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05D0_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05D1U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05D1Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05D1_ReadData}, Dcm_DidMgr_05D1_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05D1_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05D2U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05D2Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05D2_ReadData}, Dcm_DidMgr_05D2_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05D2_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05D3U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05D3Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05D3_ReadData}, Dcm_DidMgr_05D3_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05D3_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05D4U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did05D4Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_05D4_ReadData}, Dcm_DidMgr_05D4_ReadDataLength, {NULL_PTR, Dcm_DidMgr_05D4_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xDF01U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidDF01Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_DF01_ReadData}, Dcm_DidMgr_DF01_ReadDataLength, {NULL_PTR, Dcm_DidMgr_DF01_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xDF02U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidDF02Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_DF02_ReadData}, Dcm_DidMgr_DF02_ReadDataLength, {NULL_PTR, Dcm_DidMgr_DF02_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xDF03U, TRUE, 0x04U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidDF03Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_DF03_ReadData}, Dcm_DidMgr_DF03_ReadDataLength, {NULL_PTR, Dcm_DidMgr_DF03_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xDF04U, TRUE, 0x04U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidDF04Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_DF04_ReadData}, Dcm_DidMgr_DF04_ReadDataLength, {NULL_PTR, Dcm_DidMgr_DF04_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xDF06U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidDF06Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_DF06_ReadData}, Dcm_DidMgr_DF06_ReadDataLength, {NULL_PTR, Dcm_DidMgr_DF06_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x05D5U, TRUE, 0x04U, 159, (uint8*)&Dcm_Did_Block009F_Data,	Dcm_Did_Block009F_Data.Dcm_Did05D5Buffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_05D5_ReadData, NULL_PTR}, Dcm_DidMgr_05D5_ReadDataLength, {Dcm_DidMgr_05D5_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_05D5_WriteData, NULL_PTR}, Dcm_DidMgr_05D5_ConditionCheckWrite, NULL_PTR},
	{0x05D6U, TRUE, 0x04U, 160, (uint8*)&Dcm_Did_Block00A0_Data,	Dcm_Did_Block00A0_Data.Dcm_Did05D6Buffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_05D6_ReadData, NULL_PTR}, Dcm_DidMgr_05D6_ReadDataLength, {Dcm_DidMgr_05D6_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_05D6_WriteData, NULL_PTR}, Dcm_DidMgr_05D6_ConditionCheckWrite, NULL_PTR},
	{0x05D7U, TRUE, 0x03U, 161, (uint8*)&Dcm_Did_Block00A1_Data,	Dcm_Did_Block00A1_Data.Dcm_Did05D7Buffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_05D7_ReadData, NULL_PTR}, Dcm_DidMgr_05D7_ReadDataLength, {Dcm_DidMgr_05D7_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_05D7_WriteData, NULL_PTR}, Dcm_DidMgr_05D7_ConditionCheckWrite, NULL_PTR},
	{0x05D8U, TRUE, 0x02U, 162, (uint8*)&Dcm_Did_Block00A2_Data,	Dcm_Did_Block00A2_Data.Dcm_Did05D8Buffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_05D8_ReadData, NULL_PTR}, Dcm_DidMgr_05D8_ReadDataLength, {Dcm_DidMgr_05D8_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_05D8_WriteData, NULL_PTR}, Dcm_DidMgr_05D8_ConditionCheckWrite, NULL_PTR},
	{0x05D9U, TRUE, 0x01U, 163, (uint8*)&Dcm_Did_Block00A3_Data,	Dcm_Did_Block00A3_Data.Dcm_Did05D9Buffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_05D9_ReadData, NULL_PTR}, Dcm_DidMgr_05D9_ReadDataLength, {Dcm_DidMgr_05D9_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_05D9_WriteData, NULL_PTR}, Dcm_DidMgr_05D9_ConditionCheckWrite, NULL_PTR},
	{0x05DAU, TRUE, 0x01U, 164, (uint8*)&Dcm_Did_Block00A4_Data,	Dcm_Did_Block00A4_Data.Dcm_Did05DABuffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_05DA_ReadData, NULL_PTR}, Dcm_DidMgr_05DA_ReadDataLength, {Dcm_DidMgr_05DA_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_05DA_WriteData, NULL_PTR}, Dcm_DidMgr_05DA_ConditionCheckWrite, NULL_PTR},
	{0x05DBU, TRUE, 0x18U, 165, (uint8*)&Dcm_Did_Block00A5_Data,	Dcm_Did_Block00A5_Data.Dcm_Did05DBBuffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_05DB_ReadData, NULL_PTR}, Dcm_DidMgr_05DB_ReadDataLength, {Dcm_DidMgr_05DB_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_05DB_WriteData, NULL_PTR}, Dcm_DidMgr_05DB_ConditionCheckWrite, NULL_PTR},
	{0x059CU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did059CBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_059C_ReadData}, Dcm_DidMgr_059C_ReadDataLength, {NULL_PTR, Dcm_DidMgr_059C_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x052EU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did052EBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_052E_ReadData}, Dcm_DidMgr_052E_ReadDataLength, {NULL_PTR, Dcm_DidMgr_052E_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xDF0AU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidDF0ABuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_DF0A_ReadData}, Dcm_DidMgr_DF0A_ReadDataLength, {NULL_PTR, Dcm_DidMgr_DF0A_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xDF0BU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidDF0BBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_DF0B_ReadData}, Dcm_DidMgr_DF0B_ReadDataLength, {NULL_PTR, Dcm_DidMgr_DF0B_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xDF0CU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidDF0CBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_DF0C_ReadData}, Dcm_DidMgr_DF0C_ReadDataLength, {NULL_PTR, Dcm_DidMgr_DF0C_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xDF0DU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidDF0DBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_DF0D_ReadData}, Dcm_DidMgr_DF0D_ReadDataLength, {NULL_PTR, Dcm_DidMgr_DF0D_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xDF0EU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_DidDF0EBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_DF0E_ReadData}, Dcm_DidMgr_DF0E_ReadDataLength, {NULL_PTR, Dcm_DidMgr_DF0E_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0402U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0402Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0402_ReadData}, Dcm_DidMgr_0402_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0402_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0403U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0403Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0403_ReadData}, Dcm_DidMgr_0403_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0403_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0404U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0404Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0404_ReadData}, Dcm_DidMgr_0404_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0404_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0405U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0405Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0405_ReadData}, Dcm_DidMgr_0405_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0405_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0406U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0406Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0406_ReadData}, Dcm_DidMgr_0406_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0406_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0407U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0407Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0407_ReadData}, Dcm_DidMgr_0407_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0407_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0408U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0408Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0408_ReadData}, Dcm_DidMgr_0408_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0408_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x0409U, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0409Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0409_ReadData}, Dcm_DidMgr_0409_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0409_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x040BU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did040BBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_040B_ReadData}, Dcm_DidMgr_040B_ReadDataLength, {NULL_PTR, Dcm_DidMgr_040B_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x040CU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did040CBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_040C_ReadData}, Dcm_DidMgr_040C_ReadDataLength, {NULL_PTR, Dcm_DidMgr_040C_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x040DU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did040DBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_040D_ReadData}, Dcm_DidMgr_040D_ReadDataLength, {NULL_PTR, Dcm_DidMgr_040D_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x04CFU, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did04CFBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_04CF_ReadData}, Dcm_DidMgr_04CF_ReadDataLength, {NULL_PTR, Dcm_DidMgr_04CF_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF800U, TRUE, 0x04U, 183, (uint8*)&Dcm_Did_Block00B7_Data,	Dcm_Did_Block00B7_Data.Dcm_DidF800Buffer, DCM_RAED_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F800_ReadData, NULL_PTR}, Dcm_DidMgr_F800_ReadDataLength, {Dcm_DidMgr_F800_ConditionCheckRead, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xF802U, TRUE, 0x11U, 184, (uint8*)&Dcm_Did_Block00B8_Data,	Dcm_Did_Block00B8_Data.Dcm_DidF802Buffer, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x00000004U, 0x00000001U}, {0x0U, NULL_PTR}, {Dcm_DidMgr_F802_ReadData, NULL_PTR}, Dcm_DidMgr_F802_ReadDataLength, {Dcm_DidMgr_F802_ConditionCheckRead, NULL_PTR}, {Dcm_DidMgr_F802_WriteData, NULL_PTR}, Dcm_DidMgr_F802_ConditionCheckWrite, NULL_PTR},
	{0x0400U, TRUE, 0x01U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did0400Buffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_0400_ReadData}, Dcm_DidMgr_0400_ReadDataLength, {NULL_PTR, Dcm_DidMgr_0400_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x04DCU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did04DCBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_04DC_ReadData}, Dcm_DidMgr_04DC_ReadDataLength, {NULL_PTR, Dcm_DidMgr_04DC_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x04DDU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did04DDBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_04DD_ReadData}, Dcm_DidMgr_04DD_ReadDataLength, {NULL_PTR, Dcm_DidMgr_04DD_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0x04DEU, TRUE, 0x02U, DCM_INVALID_BLOCKID, NULL_PTR,	Dcm_Did04DEBuffer, DCM_RAED_ACESS, USE_DATA_ASYNCH_CLIENT_SERVER_ERROR, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, Dcm_DidMgr_04DE_ReadData}, Dcm_DidMgr_04DE_ReadDataLength, {NULL_PTR, Dcm_DidMgr_04DE_ConditionCheckRead}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR},
	{0xFFFFU, FALSE, 0xFFU, DCM_INVALID_BLOCKID, NULL_PTR, NULL_PTR, DCM_RAED_AND_WRITE_ACESS, USE_DATA_SYNCH_FNC, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, {NULL_PTR, NULL_PTR}, {NULL_PTR, NULL_PTR}, NULL_PTR, NULL_PTR}
};
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_22_2E_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_22_2E_Dispatcher =
{
	Dcm_22_DidList,
	Dcm_22_DidResLen,
	Dcm_22_2E_ServiceInfo,
};
#endif

 
#if (STD_ON == DCM_SERVICE_27_ENABLED)
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
CONST(Dcm_27_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_27_ServiceInfo[DCM_27_SUB_NUM + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{0x01U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x7FFFFFFFU,0x7FFFFFFFU},	{0x0U, NULL_PTR},	DCM_2701_ATTCOUNTER,	DCM_2701_MAX_SEED_LENGTH,	DCM_2701_MAX_KEY_LENGTH,	DCM_2701_ATTDELAY,	Dcm_SecurityAccess_Level_01_GetSeed,	Dcm_SecurityAccess_Level_01_CompareKey,	Dcm_SecurityAccess_Level_01_CheckRule,	&Dcm_27_Security_Data[0],	Dcm_SecurityAccess_Level_01_GetAttemptCounter,	Dcm_SecurityAccess_Level_01_SetAttemptCounter},
	{0x81U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x7FFFFFFFU,0x7FFFFFFFU},	{0x0U, NULL_PTR},	DCM_2701_ATTCOUNTER,	DCM_2701_MAX_SEED_LENGTH,	DCM_2701_MAX_KEY_LENGTH,	DCM_2701_ATTDELAY,	Dcm_SecurityAccess_Level_01_GetSeed,	Dcm_SecurityAccess_Level_01_CompareKey,	Dcm_SecurityAccess_Level_01_CheckRule,	&Dcm_27_Security_Data[0],	Dcm_SecurityAccess_Level_01_GetAttemptCounter,	Dcm_SecurityAccess_Level_01_SetAttemptCounter},
	{0xFFU,	DCM_PHY_FUN,	{0x7FFFFFFFU, 0x7FFFFFFFU},	{0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR},	0xFFU,	0xFFU,	0xFFU,	0xFFU,	NULL_PTR,	NULL_PTR,	NULL_PTR,   NULL_PTR,   NULL_PTR,   NULL_PTR}
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
CONST(Dcm_27_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_27_Dispatcher =
{
	Dcm_27_ServiceInfo,
};
#endif/* STD_ON == DCM_SERVICE_27_ENABLED */

 
#if (STD_ON == DCM_SERVICE_28_ENABLED)
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
CONST(uint8, DCM_CONFIG_DATA) Dcm_28_ControlState[DCM_28_CONTROL_STATE_NUM] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	0x01U,
	0x02U,
	0x03U
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(uint8, DCM_CONFIG_DATA) Dcm_28_ChannelId[DCM_28_CHANNLE_NUM + 1U] = 
{
	0x00U,
	0x01U,
	0x02U,
	0x03U,
	0x04U,
	0x05U,
	0x06U,
	0xFFU
};
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_28_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_28_ServiceInfoTable[DCM_28_SUBID_NUM + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{0x00U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check28SubComMFunc},
	{0x01U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check28SubComMFunc},
	{0x02U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check28SubComMFunc},
	{0x03U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check28SubComMFunc},
	{0x80U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check28SubComMFunc},
	{0x81U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check28SubComMFunc},
	{0x82U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check28SubComMFunc},
	{0x83U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check28SubComMFunc},
	{0xFFU,	DCM_PHY_FUN,	{0x7FFFFFFFU, 0x7FFFFFFFU}, {0x0U, NULL_PTR},	NULL_PTR}
};
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_28_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_28_Dispatcher =
{
	Dcm_28_ControlState,
	Dcm_28_ServiceInfoTable,
};
#endif/* STD_ON == DCM_SERVICE_28_ENABLED */

 
#if (STD_ON == DCM_SERVICE_2F_ENABLED)
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_2F_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_2F_ServiceInfo[DCM_2F_MAX_SUB_DID_NUM + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_2F_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_2F_Dispatcher =
{
	Dcm_2F_ServiceInfo,
};
#endif/* STD_ON == DCM_SERVICE_2F_ENABLED */

 
#if (STD_ON == DCM_SERVICE_31_ENABLED)
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
CONST(Dcm_31_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_31_ServiceInfo[DCM_31_SUBID_NUM + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{0x03E0U,	DCM_PHY_FUN,	TRUE,	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{0x00000004U, 0x00000001U},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{0U, 2U},	{0U, 0U},	{0U, 0U},	StartRoutineFunc_0x03E0,	NULL_PTR,	NULL_PTR,	NULL_PTR},
	{0x03E1U,	DCM_PHY_FUN,	TRUE,	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{0x00000004U, 0x00000001U},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{0U, 2U},	{0U, 0U},	{0U, 0U},	StartRoutineFunc_0x03E1,	NULL_PTR,	NULL_PTR,	NULL_PTR},
	{0x03E2U,	DCM_PHY_FUN,	TRUE,	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{0x00000004U, 0x00000001U},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{0U, 1U},	{0U, 1U},	{0U, 0U},	StartRoutineFunc_0x03E2,	StopRoutineFunc_0x03E2,	NULL_PTR,	NULL_PTR},
	{0x03E4U,	DCM_PHY_FUN,	TRUE,	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{0x00000004U, 0x00000001U},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{0U, 2U},	{0U, 0U},	{0U, 0U},	StartRoutineFunc_0x03E4,	NULL_PTR,	NULL_PTR,	NULL_PTR},
	{0x400FU,	DCM_PHY_FUN,	TRUE,	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{0x00000004U, 0x00000001U},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{1U, 1U},	{0U, 0U},	{0U, 0U},	StartRoutineFunc_0x400F,	NULL_PTR,	NULL_PTR,	NULL_PTR},
	{0x4000U,	DCM_PHY_FUN,	TRUE,	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{0x00000004U, 0x00000001U},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{1U, 1U},	{0U, 0U},	{0U, 0U},	StartRoutineFunc_0x4000,	NULL_PTR,	NULL_PTR,	NULL_PTR},
	{0x4F02U,	DCM_PHY_FUN,	TRUE,	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{0x00000004U, 0x00000001U},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{1U, 1U},	{0U, 0U},	{0U, 0U},	StartRoutineFunc_0x4F02,	NULL_PTR,	NULL_PTR,	NULL_PTR},
	{0x4F03U,	DCM_PHY_FUN,	TRUE,	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{0x00000004U, 0x00000001U},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{1U, 1U},	{0U, 0U},	{0U, 0U},	StartRoutineFunc_0x4F03,	NULL_PTR,	NULL_PTR,	NULL_PTR},
	{0x4F04U,	DCM_PHY_FUN,	TRUE,	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED,DCM_31_SIGNAL_TYPE_FIXED},	{0x00000004U, 0x00000001U},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},	{1U, 1U},	{0U, 0U},	{0U, 0U},	StartRoutineFunc_0x4F04,	NULL_PTR,	NULL_PTR,	NULL_PTR},
	{0xFFFFU,	DCM_PHY_FUN,	TRUE,	{DCM_31_SIGNAL_TYPE_FIXED, DCM_31_SIGNAL_TYPE_FIXED, DCM_31_SIGNAL_TYPE_FIXED},	{ DCM_31_SIGNAL_TYPE_FIXED, DCM_31_SIGNAL_TYPE_FIXED, DCM_31_SIGNAL_TYPE_FIXED},	{0x7FFFFFFFU, 0x7FFFFFFFU}, 	{0x0U, NULL_PTR}, 	{0x0U, NULL_PTR},	{0x0U, NULL_PTR},  {0U, 0U},	{0U, 0U},	{0U, 0U},	NULL_PTR,	NULL_PTR,	NULL_PTR,	NULL_PTR}
};
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_31_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_31_Dispatcher =
{
	Dcm_31_ServiceInfo,
};
#endif/* STD_ON == DCM_SERVICE_31_ENABLED */

 
#if (STD_ON == DCM_SERVICE_3E_ENABLED)
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
CONST(Dcm_3E_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_3E_ServiceInfo[DCM_3E_SUBID + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{0x00U,	DCM_PHY_FUN,	1U,	{0x00000005U, 0x7FFFFFFFU},	NULL_PTR},
	{0x80U,	DCM_PHY_FUN,	1U,	{0x00000005U, 0x7FFFFFFFU},	NULL_PTR},
	{0xFFU,	DCM_PHY_FUN,	1U,	{0x7FFFFFFFU, 0x7FFFFFFFU},	NULL_PTR}
};
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_3E_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_3E_Dispatcher =
{
	Dcm_3E_ServiceInfo,
};
#endif/* STD_ON == DCM_SERVICE_3E_ENABLED */

 
#if (STD_ON == DCM_SERVICE_85_ENABLED)
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_85_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_85_ServiceInfo[DCM_85_SUBID_NUM + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{0x01U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check85SubDtcSettingFunc},
	{0x02U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check85SubDtcSettingFunc},
	{0x81U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check85SubDtcSettingFunc},
	{0x82U,	DCM_PHY_FUN,	{0x00000004U, 0x7FFFFFFFU},	{0x0U, NULL_PTR},	Dcm_Check85SubDtcSettingFunc},
	{0xFFU,	DCM_PHY_FUN,	{0x7FFFFFFFU, 0x7FFFFFFFU},	{0x0U, NULL_PTR},   NULL_PTR}
};
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_85_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_85_Dispatcher =
{
	Dcm_85_ServiceInfo
};
#endif/* STD_ON == DCM_SERVICE_85_ENABLED */

 
#if (STD_ON == DCM_SERVICE_87_ENABLED)
CONST(Dcm_87_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_87_ServiceInfo[DCM_87_SUBID_NUM + 1] =
{
};
CONST(Dcm_87_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_87_Dispatcher =
{
	Dcm_87_ServiceInfo
};
#endif/* STD_ON == DCM_SERVICE_87_ENABLED */

/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_DspMemoryInfoType_st, DCM_CONFIG_DATA) Dcm_DspReadMemoryInfo[DCM_DSP_READMEMORY_NUM + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{ 0U, 0U, {0x7FFFFFFFU, 0x7FFFFFFFU}, NULL_PTR }
};

/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_DspMemoryInfoType_st, DCM_CONFIG_DATA) Dcm_DspWriteMemoryInfo[DCM_DSP_WRITEMEMORY_NUM + 1] =  /* PRQA S 1840 */ /* NSCA_QAC_Common_AutosarBoolean */
{
	{ 0U, 0U, {0x7FFFFFFFU, 0x7FFFFFFFU}, NULL_PTR }
};

#if (STD_ON == DCM_SERVICE_2A_ENABLED)
	
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
CONST(Dcm_2A_Channel_st, DCM_CONFIG_DATA) Dcm_2A_Channel[DCM_2A_TX_CHANNEL_NUM + 1U] = 
{
	{
		0xFFFFU,
		0xFFFFU,
	}
};


	
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_2A_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_2A_ServiceInfo[DCM_2A_NUM_DIDS + 1U] = 
{
	{
		0xFFFFU,
		FALSE,
		0xFFU,
		USE_DATA_SYNCH_FNC,
		{0x7FFFFFFFU, 0x7FFFFFFFU},
		{0x0U, NULL_PTR},
		{NULL_PTR, NULL_PTR},
		NULL_PTR,
		{NULL_PTR, NULL_PTR},
		NULL_PTR
	}
};
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(Dcm_2A_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_2A_Dispatcher =
{
     Dcm_2A_ServiceInfo
};
#endif/* STD_ON == DCM_SERVICE_2A_ENABLED */

 
#if (STD_ON == DCM_SERVICE_2C_ENABLED)
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */
CONST(uint8, DCM_CONFIG_DATA) Dcm_2C_SubFunc[DCM_2C_SUB_NUM_DIDS] =
{
	0x01U,
	0x02U,
	0x03U
};
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Usednonsharedvariable" */CONST(Dcm_2C_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_2C_ServiceInfo[DCM_2C_NUM_DIDS + 1U] ={
	{0xFFFFU, 1U, {0x7FFFFFFFU,0x7FFFFFFFU}, {0x0U, NULL_PTR},   NULL_PTR, NULL_PTR}
};
/* Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
CONST(Dcm_2C_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_2C_Dispatcher =
{
	Dcm_2C_SubFunc,
	Dcm_2C_ServiceInfo
};
#endif /* STD_ON == DCM_SERVICE_2C_ENABLED */

#if (STD_ON == DCM_SERVICE_86_ENABLED)
#endif /* STD_ON == DCM_SERVICE_86_ENABLED */

#if (STD_ON == DCM_SERVICE_29_ENABLED)

CONST(Dcm_29_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_29_Dispatcher =
{
     Dcm_29_ServiceInfo
};

CONST(Dcm_29_AutConn_st, DCM_CONFIG_DATA) Dcm_29_AutConn[DCM_29_AUT_CONN_NUM + 1] = 
{
    {
      /*Dcm_CertVerfCallNotifyRef      = */ FALSE,
      /*Dcm_RandSeedCallNotifyRef      = */ FALSE,
      /*Dcm_SignatureGenerateNotifyRef = */ FALSE,
      /*Dcm_SignatureVerifyNotifyRef   = */ FALSE,
      /*Dcm_EcuChallengeLength         = */ 0xFFFFU,
      /*Dcm_ClientCertIdx              = */ 0xFFFFU,
      /*Dcm_ConnectionCertIdx          = */ 0xFFFFU,
      /*Dcm_ConnectionMainConnectionIdx= */ 0xFFFFU,
      /*Dcm_ECUCertificateKeyElmtIdx   = */ 0xFFFFU,
      /*Dcm_ECUCertificateIdx          = */ 0xFFFFU,
      /*Dcm_PublicKeyElmtIdx           = */ 0xFFFFU,
      /*Dcm_RoleElmtIdx                = */ 0xFFFFU,
      /*Dcm_WLDIDElmtIdx               = */ 0xFFFFU,
      /*Dcm_WLMemorySelectionElmtIdx   = */ 0xFFFFU,
      /*Dcm_WLRIDElmntIdx              = */ 0xFFFFU,
      /*Dcm_WLServicesElementIdx       = */ 0xFFFFU,
      /*Dcm_CertPublicKeyStoreJobIdx   = */ 0xFFFFFFFFU,
      /*Dcm_ClientChallengeSignJobIdx  = */ 0xFFFFFFFFU,
      /*Dcm_RandomJobIdx               = */ 0xFFFFFFFFU,
      /*Dcm_VerifyPOWNJobIdx           = */ 0xFFFFFFFFU,
      /*Dcm_CheckRuleRef               = */ NULL_PTR
    }
};

CONST(Dcm_29_AutTransCert_st, DCM_CONFIG_DATA) Dcm_29_AutTransCert[DCM_29_AUT_TRANSCERT_NUM + 1] = 
{
    {
        0xFFFFU,
        0xFFFFU,
        NULL_PTR
    }
};
#endif /* STD_ON == DCM_SERVICE_29_ENABLED */

#if (STD_ON == DCM_SERVICE_38_ENABLED)
/* Polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7"  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
CONST(Dcm_38_ServiceInfoType_st, DCM_CONFIG_DATA) Dcm_38_ServiceInfo[DCM_38_SUBID_NUM + 1U] =
{
};
/*  Polyspace +1 VARIABLE:* [JUstified:Unset] "NSCA_Polyspace_Dcm_Unusedvariable" */
CONST(Dcm_38_DispatherInfo_st, DCM_CONFIG_DATA) Dcm_38_Dispatcher =
{
     Dcm_38_ServiceInfo
};
#endif/* STD_ON == DCM_SERVICE_38_ENABLED */

#if ( STD_ON == DCM_REQUESTMANUFACTURERNOTIFICATION_ENABLED )
CONST(Dcm_ServiceRequestManufacturerNotification_st, DCM_CONFIG_DATA) Dcm_ServiceRequestManufacturerNotification =
{
    {
        Dcm_DcmDsdServiceRequestManufacturerNotification_Ind,
        NULL_PTR
    },
    {
        Dcm_DcmDsdServiceRequestManufacturerNotification_Conf,
        NULL_PTR
    }
};
#endif /* STD_ON == DCM_REQUESTMANUFACTURERNOTIFICATION_ENABLED */

#if ( STD_ON == DCM_REQUESTSUPPLIERNOTIFICATION_ENABLED )
CONST(Dcm_ServiceRequestSupplierNotification_st, DCM_CONFIG_DATA) Dcm_ServiceRequestSupplierNotification = 
{
    {
        Dcm_DcmDsdServiceRequestSupplierNotification_Ind,
        NULL_PTR
    },
    {
        Dcm_DcmDsdServiceRequestSupplierNotification_Conf,
        NULL_PTR
    }
};
#endif /* STD_ON == DCM_REQUESTSUPPLIERNOTIFICATION_ENABLED */

#define DCM_STOP_SEC_CONFIG_DATA
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


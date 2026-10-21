/*
********************************************************************************
*
*  File name: Os_Arch_Mach_MP.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: JiangGL/2025.6.25
* Change: New create.
* Cause: New
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Arch_Mach_MP.h"

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
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

#if( OS_CORE_MPU == STD_ON )
/*
********************************************************************************
* Function Name: Os_Arch_CoreMpInit
*
* Explanation: Initialize the core-level MPU.
*
* Param: regionCnt: The core region number.
*        mpRegionCfgInit: The core region configuration data.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Arch_CoreMpInit
(
    CONST(uint8, OS_CONST) regionCnt,
    P2CONST(Os_Arch_CoreMpRegionCfgType, AUTOMATIC, OS_APPL_CONST) mpRegionCfgInit
)
{
    uint8 region;
    const Os_Arch_CoreMpRegionCfgType* coreMpRegionCfg = mpRegionCfgInit;

    if( NULL_PTR != coreMpRegionCfg )
    {
        /* Disable the core MPU. */
        Os_Arch_CoreMpDisableAll();
        /* Configure Region data. */
        for( region = OS_ARCH_MP_INIT; region < regionCnt; region++ )
        {
            Os_Arch_CoreMpSwitch(coreMpRegionCfg);
            coreMpRegionCfg++;
        }
        /* Enable core MPU. */
        Os_Arch_CoreMpEnable();
    }
}
#endif /*( OS_CORE_MPU == STD_ON )*/

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

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

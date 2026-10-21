/*
********************************************************************************
*
*  File name: Os_MemProtection.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.25
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2022.12.21
* Change: For tricore.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.2.14
* Change: Memory protection code optimization and annotation optimization.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_MemProtection.h"
#include "Os_Cfg.h"
#include "Os_Core.h"

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
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

#if( OS_SYSTEM_MPU == STD_ON )
/*
********************************************************************************
* Function Name: Os_Mp_MpInit
*
* Explanation: Initialize the system-level MPU.
*
* Param: Os_MpCfgType: The mpu configurate data.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Mp_MpInit
(
    P2CONST(Os_MpCfgType, AUTOMATIC, OS_APPL_CONST) Os_MpCfg
)
{
    if( Os_MpCfg != NULL_PTR )
    {
        Os_Arch_MpInit(Os_MpCfg->mpRegionCnt, Os_MpCfg->Os_Arch_MpRegionCfg);
    }
}
#endif /* OS_SYSTEM_MPU == STD_ON */

#if( OS_CORE_MPU == STD_ON )
/*
********************************************************************************
* Function Name: Os_Mp_CoreMpInit
*
* Explanation: Initialize the core-level MPU.
*
* Param: Os_MpCfgType: The mpu configurate data.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Mp_CoreMpInit
(
    P2CONST(Os_MpCfgType, AUTOMATIC, OS_APPL_CONST) Os_MpCfg
)
{
    if( Os_MpCfg != NULL_PTR )
    {
        Os_Arch_CoreMpInit(Os_MpCfg->coreMpRegionCnt, Os_MpCfg->Os_Arch_CoreMpRegionCfg);
    }
}
#endif /* OS_CORE_MPU == STD_ON */

#if( OS_MEMORY_PROTECTION == STD_ON )
/*
********************************************************************************
* Function Name: Os_Mp_Switch
*
* Explanation: Switch to the next mpu configurate data.
*
* Param: isAppMpuCfg: TRUE: The nextMpCfg is application.
*                     FALSE: NextMpCfg is not an application.
*        nextMpCfg: The next mpu configurate data.
*
* Retval: None
********************************************************************************
*/
FUNC(void, OS_CODE) Os_Mp_Switch
(
    boolean isAppMpuCfg,
    P2CONST(Os_MpCfgType, AUTOMATIC, OS_APPL_CONST)nextMpCfg
)
{

    CoreIdType coreId;
    const Os_MpCfgType* currentMpCfg;

    /* Get the current logical core id. */
    coreId = Os_Core_GetLogicId();

    /* Get current application mpu configuration data. */
    if( TRUE == isAppMpuCfg )
    {
        currentMpCfg = OS_CORE_GETCURRAPPMPUCFG(coreId);
    }
    else
    {
        currentMpCfg = OS_CORE_GETCURRMPUCFG(coreId);
    }

    /* If the MPU configurations are different. */
    if( currentMpCfg != nextMpCfg )
    {
        if( NULL_PTR != currentMpCfg )
        {
#if( OS_SYSTEM_MPU == STD_ON )
            /* If mpu region is configured. */
            if( currentMpCfg->mpRegionCnt != OS_MEMPROTECTION_INIT )
            {
                const Os_Arch_MpRegionCfgType* MpRegionCfg = currentMpCfg->Os_Arch_MpRegionCfg;

#if( OS_ARCH == ARCH_TRICORE )
                /* Clear mpu region. */
                Os_Arch_MpClear(MpRegionCfg);
#else
                {
                    uint32 mpuRegion;
                    /* Clear mpu region. */
                    for( mpuRegion = OS_MEMPROTECTION_INIT; mpuRegion < currentMpCfg->mpRegionCnt; mpuRegion++ )
                    {
                        Os_Arch_MpClear(MpRegionCfg);
                        MpRegionCfg++;
                    }
                }
#endif /* OS_ARCH == ARCH_TRICORE */
            }
#endif /* OS_SYSTEM_MPU == STD_ON */
#if( OS_CORE_MPU == STD_ON )
            if( currentMpCfg->coreMpRegionCnt != OS_MEMPROTECTION_INIT )
            {
                const Os_Arch_CoreMpRegionCfgType* coreMpRegionCfg = currentMpCfg->Os_Arch_CoreMpRegionCfg;

#if( OS_ARCH == ARCH_TRICORE )
                /* Clear mpu region. */
                Os_Arch_CoreMpClear(coreMpRegionCfg);
#else
                {
                    uint32 mpuRegion;
                    /* Clear mpu region. */
                    for( mpuRegion = OS_MEMPROTECTION_INIT; mpuRegion < currentMpCfg->coreMpRegionCnt; mpuRegion++ )
                    {
                        Os_Arch_CoreMpClear(coreMpRegionCfg);
                        coreMpRegionCfg++;
                    }
                }
#endif /* OS_ARCH == ARCH_TRICORE */
            }
#endif /* OS_CORE_MPU == STD_ON */
        }

        if( NULL_PTR != nextMpCfg )
        {
 #if( OS_SYSTEM_MPU == STD_ON )
            /* If mpu region is configured. */
            if( nextMpCfg->mpRegionCnt != OS_MEMPROTECTION_INIT )
            {
                const Os_Arch_MpRegionCfgType* MpRegionCfg = nextMpCfg->Os_Arch_MpRegionCfg;

#if( OS_ARCH == ARCH_TRICORE )
                /* Switch mpu region. */
                Os_Arch_MpSwitch(MpRegionCfg);
#else
                {
                    uint32 mpuRegion;
                    /* Switch mpu region. */
                    for( mpuRegion = OS_MEMPROTECTION_INIT; mpuRegion < nextMpCfg->mpRegionCnt; mpuRegion++ )
                    {
                        Os_Arch_MpSwitch(MpRegionCfg);
                        MpRegionCfg++;
                    }
                }
#endif /* OS_ARCH == ARCH_TRICORE */
            }
#endif /* OS_SYSTEM_MPU == STD_ON */

#if( OS_CORE_MPU == STD_ON )
            /* If the core mpu region is configured. */
            if( nextMpCfg->coreMpRegionCnt != OS_MEMPROTECTION_INIT )
            {
                const Os_Arch_CoreMpRegionCfgType* coreMpRegionCfg = nextMpCfg->Os_Arch_CoreMpRegionCfg;

#if( OS_ARCH == ARCH_TRICORE )
                /* Switch mpu region. */
                Os_Arch_CoreMpSwitch(coreMpRegionCfg);
#else
                {
                    uint32 mpuRegion;
                    /* Switch mpu region. */
                    for( mpuRegion = OS_MEMPROTECTION_INIT; mpuRegion < nextMpCfg->coreMpRegionCnt; mpuRegion++ )
                    {
                        Os_Arch_CoreMpSwitch(coreMpRegionCfg);
                        coreMpRegionCfg++;
                    }
                }
#endif /* OS_ARCH == ARCH_TRICORE */
            }
#endif /* OS_CORE_MPU == STD_ON */

        }
            /* Set current application mpu configuration data. */
            if( TRUE == isAppMpuCfg )
            {
                OS_CORE_SETCURRAPPMPUCFG(coreId, nextMpCfg);
            }
            else
            {
                OS_CORE_SETCURRMPUCFG(coreId, nextMpCfg);
            }
        }
    }
#endif /* OS_MEMORY_PROTECTION == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"


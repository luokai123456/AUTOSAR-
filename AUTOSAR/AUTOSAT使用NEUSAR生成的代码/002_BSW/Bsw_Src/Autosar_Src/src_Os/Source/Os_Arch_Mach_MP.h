/*
********************************************************************************
*
*  File name: Os_Arch_Mach_MP.h
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
#ifndef OS_ARCH_MACH_MP_H_
#define OS_ARCH_MACH_MP_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Arch_Mach_MP_Types.h"
#include "Os_Arch_Mach.h"
#include "Os_Core.h"
#include "Os_Stack.h"

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
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

#if( OS_CORE_MPU == STD_ON )
/*
********************************************************************************
* Function Name: Os_Arch_CoreMpClear
*
* Explanation: Disable MPU egion.
*
* Param: mpRegionCfg: The core region configuration data.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_CoreMpClear
(
    P2CONST(Os_Arch_CoreMpRegionCfgType, AUTOMATIC, OS_APPL_CONST) mpRegionCfg
)
{
    /* If the region number is in the range. */
    if( mpRegionCfg->mpuRegion < OS_CORE_CMPU_REGION_CNT )
    {
        /* Disable the protective effect of this CMPU region. */
        Os_Hal_WriteSPR(OS_HAL_SPR_MAS0, OS_ARCH_CMPU_MAS0_VALID_MSK |
                       OS_ARCH_CMPU_MAS0_SEL_MSK | OS_ARCH_CMPU_MAS0_ESEL(mpRegionCfg->mpuRegion));
        /* Set CMPU region TID and PID_MASK. */
        Os_Hal_WriteSPR(OS_HAL_SPR_MAS1, OS_NAUGHT_VALUE);
        /* Set CMPU region upper address. */
        Os_Hal_WriteSPR(OS_HAL_SPR_MAS2, OS_NAUGHT_VALUE);
        /* Set CMPU region lower address. */
        Os_Hal_WriteSPR(OS_HAL_SPR_MAS3, OS_NAUGHT_VALUE);
        /* Perform write operations on CMPU entries. */
        Os_Hal_Asm("mpuwe   " "\n");
        /* MPU instruction synchronization. */
        Os_Hal_Asm("mpusync " "\n");
        /* System instruction synchronization. */
        Os_Hal_Asm("se_isync" "\n");
    }
}

extern FUNC(void, OS_CODE) Os_Arch_CoreMpInit
(
    CONST(uint8, OS_CONST) regionCnt,
    P2CONST(Os_Arch_CoreMpRegionCfgType, AUTOMATIC, OS_APPL_CONST) mpRegionCfgInit
);
#endif /* OS_CORE_MPU == STD_ON */

#if( OS_SYSTEM_MPU == STD_ON )
/*
********************************************************************************
* Function Name: Os_Arch_MpDisableAll
*
* Explanation: Disable the system-level MPU.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_MpDisableAll(void)
{
    /* Do nothing. */
    return;
}

/*
********************************************************************************
* Function Name: Os_Arch_MpClear
*
* Explanation: Clear system-level MPU region.
*
* Param: mpRegionCfg: The system MPU region configuration data.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_MpClear
(
    P2CONST(Os_Arch_MpRegionCfgType, AUTOMATIC, OS_APPL_CONST) mpRegionCfg
)
{
    OS_DUMMY_STATEMENT(mpRegionCfg);
    /* Do nothing. */
    return;
}

/*
********************************************************************************
* Function Name: Os_Arch_MpSwitch
*
* Explanation: Disable the system-level MPU.
*
* Param: mpRegionCfg: The system MPU region configuration data.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_MpSwitch
(
    P2CONST(Os_Arch_MpRegionCfgType, AUTOMATIC, OS_APPL_CONST) mpRegionCfg
)
{
    OS_DUMMY_STATEMENT(mpRegionCfg);
    /* Do nothing. */
    return;
}

/*
********************************************************************************
* Function Name: Os_Arch_MpInit
*
* Explanation: Initialize the system-level MPU.
*
* Param: regionCnt: Mpu region number.
*        mpRegionCfg: The system MPU region configuration data.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_MpInit
(
    uint32 regionCnt,
    P2CONST(Os_Arch_MpRegionCfgType, AUTOMATIC, OS_APPL_CONST) mpRegionCfg
)
{
    uint32 region;
    CoreIdType coreId;
    const Os_Arch_MpRegionCfgType* mpRegionCfgInit = mpRegionCfg;

    /* Disable the system MPU. */
    Os_Arch_MpDisableAll();
    /* Configure region data. */
    for( region = OS_ARCH_MP_INIT; region < regionCnt; region++ )
    {
        Os_Arch_MpSwitch(mpRegionCfgInit);
        mpRegionCfgInit++;
    }
    /* Get core id. */
    coreId = Os_Core_GetLogicId();
    if( OS_CORE_ISMASTER(coreId) )
    {
        /* Master core enable MPU. */
    }
}
#endif /* OS_SYSTEM_MPU == STD_ON */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_ARCH_MACH_MP_H_ */

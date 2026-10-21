/*
********************************************************************************
*
*  File name: Os_Arch_Compiler.h
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
#ifndef OS_ARCH_COMPILER_H_
#define OS_ARCH_COMPILER_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"
#include "Os_Arch_Context_Types.h"
#include "Os_Arch_Mach_MP_Types.h"
#include "Os_SysCall_Types.h"
#include "Os_Cfg.h"
#include "Os_Arch_Mach_CCFC3012.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Function resource. */
/* Interrupt disable. */
#define OS_ARCH_DISABLE()                   __asm("wrteei 0")
/* Interrupt enable. */
#define OS_ARCH_ENABLE()                    __asm("wrteei 1")
/* Execute a null instruction. */
#define OS_ARCH_NOP()                       __asm("nop")
/* Data synchronization instruction. */
#define OS_ARCH_DSBAR()
/* Instruction synchronization. */
#define OS_ARCH_ISYNC()                     __asm("se_isync")
/* Memory synchronization. */
#define OS_ARCH_MSYNC()                     __asm("msync")
/* Set sp value. */
#define OS_ARCH_SETSP(x)                    __SETREG(1U, (x))
/* Declaration of code section for assembler. */
#define OS_ARCH_EXCEPTION_ENTRY(target)     __asm(".align 4");                                 \
                                            __asm("e_b "#target);

#define OS_ARCH_CODE_SECTION(target)        __asm(".section   \"."#target"\", \"axv\"" "\n");  \
                                            __asm(".vle "                              "\n");

#define OS_ARCH_GLOBAL_EXCINTVEC(target)    __asm(".align 4"                           "\n");  \
                                            __asm(".globl    _"#target                 "\n");  \
                                            __asm("_"#target":"                        "\n");

#define OS_ARCH_EIINT_ENTRY(target)         __asm(".long "#target                      "\n");

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
#if( OS_CORE_MPU == STD_ON )
/*
********************************************************************************
* Function Name: Os_Arch_CoreMpEnable
*
* Explanation: Enable the Core MPU.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_CoreMpEnable(void)
{
    /* Enable core mpu function. */
    Os_Hal_WriteSPR(OS_HAL_SPR_MPU0CSR0 , OS_ARCH_CMPU_ENABLE_MASK);
}

/*
********************************************************************************
* Function Name: Os_Arch_CoreMpDisableAll
*
* Explanation: Disable the core-level MPU.
*
* Param: None
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_CoreMpDisableAll(void)
{
    uint32 region;

    /* Disable core mpu function. */
    Os_Hal_WriteSPR (OS_HAL_SPR_MPU0CSR0 , OS_ARCH_CMPU_DISABLE_MASK);
    /* Disable all the regions. */
    for( region = OS_ARCH_MP_INIT; region < OS_CORE_CMPU_REGION_CNT; region++ )
    {
        /* Disable the protective effect of this CMPU region. */
        Os_Hal_WriteSPR(OS_HAL_SPR_MAS0, OS_ARCH_CMPU_MAS0_VALID_MSK | OS_ARCH_CMPU_MAS0_SEL_MSK | OS_ARCH_CMPU_MAS0_ESEL(region));
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


/*
********************************************************************************
* Function Name: Os_Arch_CoreMpSwitch
*
* Explanation: Switch the core-level MPU region.
*
* Param: mpRegionCfg: The core region configuration data.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_CoreMpSwitch
(
    P2CONST(Os_Arch_CoreMpRegionCfgType, AUTOMATIC, OS_APPL_CONST) mpRegionCfg
)
{
    /* Set CMPU region access. */
    Os_Hal_WriteSPR(OS_HAL_SPR_MAS0, OS_ARCH_CMPU_MAS0_VALID_MSK | OS_ARCH_CMPU_MAS0_SEL_MSK
                        | (mpRegionCfg->mpuMpat)
                        | OS_ARCH_CMPU_MAS0_ESEL(mpRegionCfg->mpuRegion));
    /* Set CMPU region TID and PID_MASK. */
    Os_Hal_WriteSPR(OS_HAL_SPR_MAS1, OS_NAUGHT_VALUE);
    /* Set CMPU region upper address. */
    Os_Hal_WriteSPR(OS_HAL_SPR_MAS2, (mpRegionCfg->mpuMpua));
    /* Set CMPU region lower address. */
    Os_Hal_WriteSPR(OS_HAL_SPR_MAS3, (mpRegionCfg->mpuMpla));
    /* Perform write operations on CMPU entries. */
    Os_Hal_Asm("mpuwe   " "\n");
    /* MPU instruction synchronization. */
    Os_Hal_Asm("mpusync " "\n");
    /* System instruction synchronization. */
    Os_Hal_Asm("se_isync" "\n");
}

/*
********************************************************************************
* Function Name: Os_Arch_MpStackSwitch
*
* Explanation: Switch to stack protected address.
*
* Param: startAddr: Stack start address.
*        endAddr: Stack end address.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_MpStackSwitch
(
    P2VAR(Os_Stack_Address, AUTOMATIC, OS_APPL_DATA) startAddr,
    P2VAR(Os_Stack_Address, AUTOMATIC, OS_APPL_DATA) endAddr
)
{
    /* Set CMPU region access. */
    Os_Hal_WriteSPR(OS_HAL_SPR_MAS0, OS_ARCH_CMPU_MAS0_VALID_MSK | OS_ARCH_CMPU_MAS0_SEL_MSK
                         | OS_ARCH_CMPU_MAS0_UW_MSK | OS_ARCH_CMPU_MAS0_URX_MSK
                         | OS_ARCH_CMPU_MAS0_SW_MSK | OS_ARCH_CMPU_MAS0_SRX_MSK
                         | OS_ARCH_CMPU_MAS0_ESEL(OS_CORE_CMPU_STACK_REGION));
    /* Set CMPU region TID and PID_MASK. */
    Os_Hal_WriteSPR(OS_HAL_SPR_MAS1, OS_NAUGHT_VALUE);
    /* Set CMPU region upper address. */
    Os_Hal_WriteSPR(OS_HAL_SPR_MAS2, (uint32)startAddr);
    /* Set CMPU region lower address. */
    Os_Hal_WriteSPR(OS_HAL_SPR_MAS3, (uint32)endAddr);
    /* Perform write operations on CMPU entries. */
    Os_Hal_Asm("mpuwe   " "\n");
    /* Perform write operations on CMPU entries. */
    Os_Hal_Asm("mpusync " "\n");
    /* System instruction synchronization. */
    Os_Hal_Asm("se_isync" "\n");
}

#endif /* OS_CORE_MPU == STD_ON */
extern FUNC(void, OS_CODE) Os_Arch_Stack_Switch
(
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) current,
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) next
);
extern FUNC(void, OS_CODE) Os_Arch_Stack_Restore
(
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) next
);
extern FUNC(void, OS_CODE) Os_Arch_Context_SwitchNext
(
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) next
);
extern FUNC(void, OS_CODE) Os_Arch_Context_SwitchFirst
(
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) next
);
extern FUNC(void, OS_CODE) Os_Arch_Context_Switch
(
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) current,
    P2VAR(Os_Arch_ContextDynType, AUTOMATIC, OS_APPL_DATA) next
);
extern FUNC(void, OS_CODE) Os_Arch_SysCall
(
    P2VAR(volatile Os_SysCallType, AUTOMATIC, OS_APPL_DATA) callData
);

#endif /* OS_ARCH_COMPILER_H_ */

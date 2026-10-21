/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     main.c
* @version  3.0.0
* @date     2023 - 04 - 17
* @brief    Initial version.
*@ version :0.1
*@ Modifier : liufengyuan 
*@ date :2026-05-03
*@ Modification Description: 
                                适配的 start.S  需要 V0.3 及以上
                                适配的 .ld 文件 需要 V0.3 及以上
                                适配的 memory.h 需要 V0.2 及以上
                            1、增加DMA初始化Ram的函数定义
                            2、reset_keep段的初始化 PS:为增加复位段的判断 都做初始化
*@ version :0.2
*@ Modifier : liufengyuan 
*@ date :2026-05-03
*@ Modification Description: 
                                适配的 start.S  需要 V0.5 及以上
                                适配的 .ld 文件 需要 V0.6 及以上
                                适配的 memory.h 需要 V0.4 及以上
                            1、增加 ASW QM data段和bss段的DMA初始化
*@ version :0.3
*@ Modifier : huangbaoxing 
*@ date :2026-06-08
*@ Modification Description: 
                                适配的 start.S  需要 V0.6 及以上
                                适配的 .ld 文件 需要 V0.8 及以上
                                适配的 memory.h 需要 V0.7 及以上
                            1、将6段标定段的DMA初始化合并为一段
                            2、增加MEA_DATA_RAM段的DMA初始化
                            *@ version :0.3
*@ Modifier : huangbaoxing 
*@ date :2026-06-027
*@ Modification Description: 
                                重新整理main.c文件,删除冗余代码
                            1、删除saf_main.c文件及其相关联函数与宏
                            2、删除Os_Arch_TestSpinlock及其相关测试代码
                            3、删除_main、Mcore_Init、ChangeModeFailed等无意义函数实体
                            4、在main函数中删除CMPU_LLD_Init、saf_main及HSM初始化等待代码
                            5、在main函数中删除StartCore等无意义注释代码
*@ Modifier : WangJiaChneg
************ *****************************************************************/
#include "main.h"

#include "Mcu.h" /* PRQA S 0380,1753 EOF */
#include "mpu_lldriver.h"
#ifdef MPU_ENABLE
#include "cmpu_cfg.h"
#endif
#include "intc_lld.h"
#include "console.h"
#include "Port.h"

#include "CCFC3012PT.h"
#include "Os_Arch_Mach.h"
#include "Os.h"
#include "Os_Spinlock.h"
#include "Os_Arch_Core.h"
#include "EcuM.h"
#include "ResetCause.h"
#include "MemoryManage.h"
#ifdef FUNC_SAFETY
#include "saf_sch.h"
#include "saf_testservice_inject.h"
#endif

#if SWITCH_CORE_ENABLE
#define SHELL_DEFAULT_CORE   0 /* If switch core is enable, shell default core ID (range: 0-5)*/
#endif /* SWITCH_CORE_ENABLE */
#define MCU_INIT_CORE        0
#define CORESYNC             0
MCU_PB_CONFIG_DECLARATION;          //DQ add
#if(MCU_CONFIG_TYPE_PB == STD_ON)
#define MCU_CONFIG_HANDLE   &McuModuleConfiguration
#else
#define MCU_CONFIG_HANDLE   NULL_PTR
#endif

#if(PORT_PRECOMPILE_SUPPORT == STD_ON)
#define PORT_CONFIG_HANDLE  NULL_PTR
#else
#define PORT_CONFIG_HANDLE  &PortContainer
#endif

#ifdef DCACHE_ENABLE
extern void CACHE_LLD_InvalidateDcache(void);
extern void CACHE_LLD_InvalidateIcache(void);
#endif

#define Mcal_GetCoreID()                     MFSPR(SPR_PIR)

/* map core_a to 5777M_Z4_2, core_b to 5777M_Z7_0, core_c to 5777M_Z7_1 */
#define SSCM_JTAGID (*(volatile unsigned int*)(0xffff8000 + 0x58))
void Jtag_Swap(uint32_t core_a, uint32_t core_b, uint32_t core_c);
void Jtag_Swap(uint32_t core_a, uint32_t core_b, uint32_t core_c)
{
    static uint32_t core_map[] = {
        [0U] = 0x28, // core_0
        [1U] = 0x29, // core_1
        [2U] = 0x2a, // core_2
        [3U] = 0x2b, // core_3
        [4U] = 0x2c, // core_4
        [5U] = 0x2d, // core_5
        [6U] = 0x27, // hsm
    };

    if (core_a >= (sizeof(core_map) / sizeof(core_map[0])) ||
        core_b >= (sizeof(core_map) / sizeof(core_map[0])) ||
        core_c >= (sizeof(core_map) / sizeof(core_map[0]))) {
        return;
    }

    SSCM_JTAGID = core_map[core_b] | (core_map[core_c] << 6U) | (core_map[core_a] << 12U);
    SSCM_JTAGID |= 1U << 18U; // enable swap
}
#ifdef HSM_ENABLE
#define LINFLEXD_LINCR1_INIT_MASK               0x0001
#define LINFLEXD_LINCR1_SLEEP_MASK              0x0002

#define LINFLEXD_UARTCR_UART_MASK               0x00000001

#define LINFLEXD_UARTSR_SZF_MASK                0x8000
#define LINFLEXD_UARTSR_DRFRFE_MASK             0x0004
#define LINFLEXD_UARTSR_DRFTFF_MASK             0x0002

static void initLINFlexD_0 ( unsigned int MegaHertz, unsigned int BaudRate ) {
    uint32_t Fraction;
    uint32_t Integer;

    LINFlexD_0.LINCR1.R |= LINFLEXD_LINCR1_INIT_MASK;     /* Enter Initialization Mode */
    LINFlexD_0.LINCR1.R &= (~LINFLEXD_LINCR1_SLEEP_MASK);    /* Exit Sleep Mode */
    LINFlexD_0.UARTCR.R |= LINFLEXD_UARTCR_UART_MASK;     /* UART Enable, Req'd before UART configuration */
    LINFlexD_0.UARTCR.R = 0x0033;     /* UART Enable, 1 byte tx, no parity, 8 data*/
    LINFlexD_0.UARTSR.R |= LINFLEXD_UARTSR_SZF_MASK;      /* CHANGE THIS LINE   Clear the Zero status bit */
    LINFlexD_0.UARTSR.R |= LINFLEXD_UARTSR_DRFRFE_MASK;   /* CHANGE THIS LINE  Clear DRFRFE flag - W1C */

    BaudRate  = (MegaHertz * 1000000) / BaudRate;
    Integer   = BaudRate / 16;
    Fraction  = BaudRate - (Integer * 16);

    LINFlexD_0.LINIBRR.R = Integer;
    LINFlexD_0.LINFBRR.R = Fraction;

    LINFlexD_0.LINCR1.R &= ~LINFLEXD_LINCR1_INIT_MASK;     /* Exit Initialization Mode */

    SIUL.PCR[PF10].R = 0x079C;		//PF10 tx
    SIUL.PCR[PF11].R = 0x005C;		//PF11 rx
    SIUL.PSMI[0].B.PADSEL = 0x1;
}
#endif

void Intc_Init(void)
{
    (void) INTC_LLD_Swtich_Mode(INTC_MODE_SOFTWARE_VECTOR);
    INTC_LLD_Set_Vector_Prefix((uint32_t)&VTABLE);/*PRQA S 0305*/
    INTC_LLD_Set_Vector_Table((uint32_t)&IntcIsrVectorTable[0U]);
    if(Mcal_GetCoreID() == 0U)
    {
        INTC_LLD_Reset_IRQ_Status();
    }
    (void) INTC_LLD_Set_Global_Priority(INTR_PRI_0);
    INTC_LLD_Set_Global_Enable();
}

void XBAR_config(void)
{
    uint32_t i = 0;
    XBIC_0.EIR.B.TIMEOUT_EN = 0;
    XBIC_1.EIR.B.TIMEOUT_EN = 0;
    XBIC_2.EIR.B.TIMEOUT_EN = 0;
    XBIC_3.EIR.B.TIMEOUT_EN = 0;

    for(i = 0; i < 8;i ++)
    {
        XBAR_0.PORT[i].CRS.R = 0x0;
        XBAR_1.PORT[i].CRS.R = 0x0;
        XBAR_2.PORT[i].CRS.R = 0x0;
        XBAR_3.PORT[i].CRS.R = 0x0;

        XBAR_0.PORT[i].CRS.B.ARB = 0x1;
        XBAR_1.PORT[i].CRS.B.ARB = 0x1;
        XBAR_2.PORT[i].CRS.B.ARB = 0x1;
        XBAR_3.PORT[i].CRS.B.ARB = 0x1;
    }
}

extern const uint32 RAM_OS_GLOBAL_NOCACHE_VAR_START[];
extern const uint32 RAM_OS_GLOBAL_NOCACHE_VAR_END[];
extern const uint32 RAM_OS_GLOBAL_NOCACHE_INITVAR_START[];
extern const uint32 RAM_OS_GLOBAL_NOCACHE_INITVAR_END[];

void mpu_Init (void)
{
    unsigned int i = 0;
    uint32 address;
    Os_Hal_WriteSPR (OS_HAL_SPR_MPU0CSR0 , 0);

    Os_Hal_WriteSPR (OS_HAL_SPR_MAS0 , 0xA0800000 | OS_ARCH_CMPU_MAS0_IOVR_MSK | OS_ARCH_CMPU_MAS0_I_MSK | OS_ARCH_CMPU_MAS0_ESEL(i));
    Os_Hal_WriteSPR (OS_HAL_SPR_MAS1 , 0);
    address = (uint32)RAM_OS_GLOBAL_NOCACHE_VAR_END - 1;
    Os_Hal_WriteSPR (OS_HAL_SPR_MAS2 , address); /*upper address*/
    address = (uint32)RAM_OS_GLOBAL_NOCACHE_VAR_START;
    Os_Hal_WriteSPR (OS_HAL_SPR_MAS3 , address); /*lower address*/
    __asm ("mpuwe" "\n");
    __asm ("mpusync" "\n");

    i++;
    Os_Hal_WriteSPR (OS_HAL_SPR_MAS0 , 0xA0800000 | OS_ARCH_CMPU_MAS0_IOVR_MSK | OS_ARCH_CMPU_MAS0_I_MSK | OS_ARCH_CMPU_MAS0_ESEL(i));
    Os_Hal_WriteSPR (OS_HAL_SPR_MAS1 , 0);
    address = (uint32)RAM_OS_GLOBAL_NOCACHE_INITVAR_END - 1;
    Os_Hal_WriteSPR (OS_HAL_SPR_MAS2 , address); /*upper address*/
    address = (uint32)RAM_OS_GLOBAL_NOCACHE_INITVAR_START;
    Os_Hal_WriteSPR (OS_HAL_SPR_MAS3 , address); /*lower address*/
    __asm ("mpuwe" "\n");
    __asm ("mpusync" "\n");

   Os_Hal_WriteSPR (OS_HAL_SPR_MPU0CSR0 , 0xFC01);   /* Bypass all permissions. */
}


const uint8 Jtag_SwapDebugCores[3U] = {0U, 1U, 2U};
extern FUNC(void, ECUM_CODE) EcuM_Init(void);
void main (void)
{
    volatile uint32 phyCoreId;
    
    XBAR_config();
    mpu_Init();
    Os_Init();
    phyCoreId = MFSPR(SPR_PIR);
    if( 0U == phyCoreId )
    {
        ResetCause_PreInit();
        #ifdef FUNC_SAFETY
		SAF_SCH_PrestartupTest();
        #endif
        if (ResetCause_IsPorHappened())
		{
            ResetKeepRam_Init();
        }
        /* 核0是主核，由核0设置可以使用调试器调试的内核. */
        Jtag_Swap(Jtag_SwapDebugCores[0U], Jtag_SwapDebugCores[1U], Jtag_SwapDebugCores[2U]);
        /* 由核0调用Mcu_Init. */
        Mcu_Init(MCU_CONFIG_HANDLE);

#if MCU_INIT_CORE == 0
        Mcu_InitClock(0);
        Mcu_SetMode(0);
        while ( MCU_PLL_LOCKED != Mcu_GetPllStatus())
        {
            /* wait until all enabled PLLs are locked. */
        }
        Mcu_DistributePllClock();
#ifdef FUNC_SAFETY
        Intc_Init();
        (void)INTC_LLD_Set_IRQ_Enable(FCCU_0_IRQn);
        (void)INTC_LLD_Set_IRQ_Priority(FCCU_0_IRQn, INTR_PRI_1);
        (void)INTC_LLD_Set_IRQ_Enable(FCCU_1_IRQn);
        (void)INTC_LLD_Set_IRQ_Priority(FCCU_1_IRQn, INTR_PRI_1);
        SAF_SCH_StartupTest();

        CMPU_LLD_DeInit();
        SAF_UserInject_StartupTest();

        mpu_Init();
        Os_Init();
#endif /* FUNC_SAFETY */
#endif /* MCU_INIT_CORE == 0 */
    }
    /* initialize OS again */
    EcuM_Init();//ECU状态管理器初始化 
}

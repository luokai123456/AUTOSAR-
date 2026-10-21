#include "MemoryManage.h"
#include "Os_Arch_Core.h"
#include "CCFC3012PT.h"

void data_ram_copy_dma(uint32 ramStart, uint32 ramSize, uint32 romStart, uint16 srcOffset)
{
	if((ramStart == romStart) || (ramSize == 0)) 
    {
        return;
    }

    eDMA_0.TCD[0].SADDR.R = romStart;
    eDMA_0.TCD[0].ATTR.R = 0x0202;
    eDMA_0.TCD[0].SOFF.R = srcOffset;
    eDMA_0.TCD[0].DOFF.R = 4;
    eDMA_0.TCD[0].NBYTES.MLNO.R = ramSize;
    eDMA_0.TCD[0].SLAST.R = 0;
    eDMA_0.TCD[0].DLASTSGA.R = 0;
    eDMA_0.TCD[0].DADDR.R = ramStart;
    eDMA_0.TCD[0].CITER.ELINKNO.R = 0x01;
    eDMA_0.TCD[0].BITER.ELINKNO.R = 0x01;
    eDMA_0.TCD[0].CSR.R = 0x0;

    eDMA_0.SERQ.R = 0;

    eDMA_0.TCD[0].CSR.R |= 0x1;
    while((eDMA_0.TCD[0].CSR.R & 0x80) != 0x80);
    eDMA_0.CERQ.R = 0;
}
const uint8 dmaClearInitVar = 0;
void dma_clear_ram(uint32 ramStart, uint32 ramSize) {
	data_ram_copy_dma(ramStart, ramSize, (uint32) &dmaClearInitVar, 0);
}

void dma_clear_ram_start_end(uint32 ramStart, uint32 ramEnd) {
	dma_clear_ram(ramStart, ramEnd - ramStart);
}

void dma_copy_ram(uint32 ramStart, uint32 ramSize, uint32 romStart) {
	data_ram_copy_dma(ramStart, ramSize, romStart, 4);
}

void dma_copy_ram_start_end(uint32 ramStart, uint32 ramEnd, uint32 romStart) {
	dma_copy_ram(ramStart, ramEnd - ramStart, romStart);
}
/******************* 链接器脚本定义的符号声明 *******************/
/* 数据复制初始化相关符号 */
extern const uint32 __INTC_VECTOR_TABLE_SIZE[];
extern const uint32 __INTC_VECTOR_TABLE_RAM_ADDR[];
extern const uint32 __INTC_VECTOR_TABLE_ROM_ADDR[];
extern const uint32 __CAL_DATA_SIZE[];
extern const uint32 __CAL_DATA_RAM_ADDR[];
extern const uint32 __CAL_DATA_ROM_ADDR[];
extern const uint32 __SAFCODE_USEVAR_SIZE[];
extern const uint32 __SAFCODE_USEVAR_RAM_ADDR[];
extern const uint32 __SAFCODE_USEVAR_ROM_ADDR[];
extern const uint32 __BSW_DATA_ASILA_SIZE[];
extern const uint32 __BSW_DATA_ASILA_RAM_ADDR[];
extern const uint32 __BSW_DATA_ASILA_ROM_ADDR[];
extern const uint32 __BSW_DATA_ASILB_SIZE[];
extern const uint32 __BSW_DATA_ASILB_RAM_ADDR[];
extern const uint32 __BSW_DATA_ASILB_ROM_ADDR[];
extern const uint32 __BSW_DATA_ASILC_SIZE[];
extern const uint32 __BSW_DATA_ASILC_RAM_ADDR[];
extern const uint32 __BSW_DATA_ASILC_ROM_ADDR[];
extern const uint32 __BSW_DATA_GLOBAL_SIZE[];
extern const uint32 __BSW_DATA_GLOBAL_RAM_ADDR[];
extern const uint32 __BSW_DATA_GLOBAL_ROM_ADDR[];
extern const uint32 __ASW_DATA_ASILA_SIZE[];
extern const uint32 __ASW_DATA_ASILA_RAM_ADDR[];
extern const uint32 __ASW_DATA_ASILA_ROM_ADDR[];
extern const uint32 __ASW_DATA_ASILB_SIZE[];
extern const uint32 __ASW_DATA_ASILB_RAM_ADDR[];
extern const uint32 __ASW_DATA_ASILB_ROM_ADDR[];
extern const uint32 __ASW_DATA_ASILC_SIZE[];
extern const uint32 __ASW_DATA_ASILC_RAM_ADDR[];
extern const uint32 __ASW_DATA_ASILC_ROM_ADDR[];
extern const uint32 __ASW_DATA_GLOBAL_SIZE[];
extern const uint32 __ASW_DATA_GLOBAL_RAM_ADDR[];
extern const uint32 __ASW_DATA_GLOBAL_ROM_ADDR[];
extern const uint32 __ASW_DATA_QM_SIZE[];
extern const uint32 __ASW_DATA_QM_RAM_ADDR[];
extern const uint32 __ASW_DATA_QM_ROM_ADDR[];
extern const uint32 __DATA_SIZE[];
extern const uint32 __DATA_RAM_ADDR[];
extern const uint32 __DATA_ROM_ADDR[];
extern const uint32 __DATA_SHARE_SIZE[];
extern const uint32 __DATA_SHARE_RAM_ADDR[];
extern const uint32 __DATA_SHARE_ROM_ADDR[];
extern const uint32 __SDATA_SIZE[];
extern const uint32 __SDATA_RAM_ADDR[];
extern const uint32 __SDATA_ROM_ADDR[];
extern const uint32 __SDATA2_SIZE[];
extern const uint32 __SDATA2_RAM_ADDR[];
extern const uint32 __SDATA2_ROM_ADDR[];
extern const uint32 __ALGORITH_RAM_SIZE[];
extern const uint32 __ALGORITH_RAM_RAM_ADDR[];
extern const uint32 __ALGORITH_RAM_ROM_ADDR[];
extern const uint32 __FOC_DATA_SIZE[];
extern const uint32 __FOC_DATA_ROM_ADDR[];
extern const uint32 __FOC_DATA_SRAM_ADDR[];

extern const uint32 __RDC_DATA_SIZE[];
extern const uint32 __RDC_DATA_ROM_ADDR[];
extern const uint32 __RDC_DATA_SRAM_ADDR[];

extern const uint32 __RDC_CODE_SIZE[];
extern const uint32 __RDC_CODE_ROM_ADDR[];
extern const uint32 __RDC_CODE_SRAM_ADDR[];

extern const uint32 __MCU_CODE_SIZE[];
extern const uint32 __MCU_CODE_ROM_ADDR[];
extern const uint32 __MCU_CODE_SRAM_ADDR[];
/* 清零初始化相关符号 */
extern const uint32 __MEA_DATA_SIZE[];
extern const uint32 __MEA_DATA_RAM_ADDR[];
extern const uint32 __BSW_BSS_ASILA_SIZE[];
extern const uint32 __BSW_BSS_ASILA_RAM_ADDR[];
extern const uint32 __BSW_BSS_ASILB_SIZE[];
extern const uint32 __BSW_BSS_ASILB_RAM_ADDR[];
extern const uint32 __BSW_BSS_ASILC_SIZE[];
extern const uint32 __BSW_BSS_ASILC_RAM_ADDR[];
extern const uint32 __BSW_BSS_GLOBAL_SIZE[];
extern const uint32 __BSW_BSS_GLOBAL_RAM_ADDR[];
extern const uint32 __ASW_BSS_ASILA_SIZE[];
extern const uint32 __ASW_BSS_ASILA_RAM_ADDR[];
extern const uint32 __ASW_BSS_ASILB_SIZE[];
extern const uint32 __ASW_BSS_ASILB_RAM_ADDR[];
extern const uint32 __ASW_BSS_ASILC_SIZE[];
extern const uint32 __ASW_BSS_ASILC_RAM_ADDR[];
extern const uint32 __ASW_BSS_GLOBAL_SIZE[];
extern const uint32 __ASW_BSS_GLOBAL_RAM_ADDR[];
extern const uint32 __ASW_BSS_QM_SIZE[];
extern const uint32 __ASW_BSS_QM_RAM_ADDR[];
extern const uint32 __BSS_SHARE_SIZE[];
extern const uint32 __BSS_SHARE_RAM_ADDR[];
extern const uint32 __BSS_SIZE[];
extern const uint32 __BSS_RAM_ADDR[];
extern const uint32 __SBSS2_SIZE[];
extern const uint32 __SBSS2_RAM_ADDR[];
extern const uint32 __BSS_OS_SIZE[];
extern const uint32 __BSS_OS_RAM_ADDR[];
extern const uint32 __EE_BLOCK_SIZE[];
extern const uint32 __EE_BLOCK_RAM_ADDR[];
extern const uint32 __RESET_KEEP_SIZE[];
extern const uint32 __RESET_KEEP_RAM_ADDR[];
extern const uint32 __RESET_KEEP_SIZE[];
extern const uint32 __RESET_KEEP_RAM_ADDR[];
extern const uint32 __FOC_BSS_SIZE[];
extern const uint32 __FOC_BSS_SRAM_ADDR[];
extern const uint32 __RDC_BSS_SIZE[];
extern const uint32 __RDC_BSS_SRAM_ADDR[];

/*
* Initialize ECC for reset_keep section
* Disable optimization is necessary,
* otherwise call to this function will be optimized out.
*/
#pragma ghs ZO
void ResetKeepRam_Init(void) {
#pragma asm

e_lis       r5, __RESET_KEEP_SIZE@h
e_or2i      r5, __RESET_KEEP_SIZE@l
e_srwi      r5, r5, 0x7
mtctr       r5

e_lis       r5, __RESET_KEEP_RAM_ADDR@h
e_or2i      r5, __RESET_KEEP_RAM_ADDR@l

reset_keep_init:
	e_stmw      r0,0(r5)
	e_addi      r5,r5,128
	e_bdnz      reset_keep_init
#pragma endasm

#ifdef DATA_COPY_USE_DMA
    dma_clear_ram((uint32)__RESET_KEEP_RAM_ADDR, (uint32)__RESET_KEEP_SIZE);
#else
#pragma asm
RESETKEEPINIT:
    e_lis       r9, __RESET_KEEP_SIZE@h        # Load upper BSW_BSS_ASILA size (# of bytes) into R9
    e_or2i      r9, __RESET_KEEP_SIZE@l       # Load lower BSW_BSS_ASILA size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       RESETKEEPINITEND               # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __RESET_KEEP_RAM_ADDR@h   # Load upper BSW_BSS_ASILA address into R5
    e_or2i      r5, __RESET_KEEP_RAM_ADDR@l   # Load lower BSW_BSS_ASILA address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

RESETKEEPINITLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into BSS at R5 and update address
    e_bdnz      RESETKEEPINITLOOP              # Branch if more bytes to clear
RESETKEEPINITEND:
#pragma endasm

#endif  /* ifdef DATA_COPY_USE_DMA */
	OS_ARCH_ISYNC();
	OS_ARCH_MSYNC();
	OS_ARCH_ISYNC();
	OS_ARCH_MSYNC();
}
#pragma ghs Odefault

void default_copy_sec_init(void)        /* 初始化代码段 */
{
    /* 中断向量表 */
	data_ram_copy_dma((uint32)__INTC_VECTOR_TABLE_RAM_ADDR, (uint32)__INTC_VECTOR_TABLE_SIZE, (uint32)__INTC_VECTOR_TABLE_ROM_ADDR, 4);
    /* CAL 数据区 */
    data_ram_copy_dma((uint32)__CAL_DATA_RAM_ADDR, (uint32)__CAL_DATA_SIZE, (uint32)__CAL_DATA_ROM_ADDR, 4);
    /* 安全代码使用变量 */
    data_ram_copy_dma((uint32)__SAFCODE_USEVAR_RAM_ADDR, (uint32)__SAFCODE_USEVAR_SIZE, (uint32)__SAFCODE_USEVAR_ROM_ADDR, 4);
    /* BSW 安全相关数据 */
    data_ram_copy_dma((uint32)__BSW_DATA_ASILA_RAM_ADDR, (uint32)__BSW_DATA_ASILA_SIZE, (uint32)__BSW_DATA_ASILA_ROM_ADDR, 4);
    data_ram_copy_dma((uint32)__BSW_DATA_ASILB_RAM_ADDR, (uint32)__BSW_DATA_ASILB_SIZE, (uint32)__BSW_DATA_ASILB_ROM_ADDR, 4);
    data_ram_copy_dma((uint32)__BSW_DATA_ASILC_RAM_ADDR, (uint32)__BSW_DATA_ASILC_SIZE, (uint32)__BSW_DATA_ASILC_ROM_ADDR, 4);
    data_ram_copy_dma((uint32)__BSW_DATA_GLOBAL_RAM_ADDR, (uint32)__BSW_DATA_GLOBAL_SIZE, (uint32)__BSW_DATA_GLOBAL_ROM_ADDR, 4);
    /* ASW 安全相关数据 */
    data_ram_copy_dma((uint32)__ASW_DATA_ASILA_RAM_ADDR, (uint32)__ASW_DATA_ASILA_SIZE, (uint32)__ASW_DATA_ASILA_ROM_ADDR, 4);
    data_ram_copy_dma((uint32)__ASW_DATA_ASILB_RAM_ADDR, (uint32)__ASW_DATA_ASILB_SIZE, (uint32)__ASW_DATA_ASILB_ROM_ADDR, 4);
    data_ram_copy_dma((uint32)__ASW_DATA_ASILC_RAM_ADDR, (uint32)__ASW_DATA_ASILC_SIZE, (uint32)__ASW_DATA_ASILC_ROM_ADDR, 4);
    data_ram_copy_dma((uint32)__ASW_DATA_GLOBAL_RAM_ADDR, (uint32)__ASW_DATA_GLOBAL_SIZE, (uint32)__ASW_DATA_GLOBAL_ROM_ADDR, 4);
    data_ram_copy_dma((uint32)__ASW_DATA_QM_RAM_ADDR, (uint32)__ASW_DATA_QM_SIZE, (uint32)__ASW_DATA_QM_ROM_ADDR, 4);
    /* 标准数据段 */
    data_ram_copy_dma((uint32)__DATA_RAM_ADDR, (uint32)__DATA_SIZE, (uint32)__DATA_ROM_ADDR, 4);
    data_ram_copy_dma((uint32)__DATA_SHARE_RAM_ADDR, (uint32)__DATA_SHARE_SIZE, (uint32)__DATA_SHARE_ROM_ADDR, 4);
    data_ram_copy_dma((uint32)__SDATA_RAM_ADDR, (uint32)__SDATA_SIZE, (uint32)__SDATA_ROM_ADDR, 4);
    data_ram_copy_dma((uint32)__SDATA2_RAM_ADDR, (uint32)__SDATA2_SIZE, (uint32)__SDATA2_ROM_ADDR, 4);
    /* 算法 RAM 区 */
    data_ram_copy_dma((uint32)__ALGORITH_RAM_RAM_ADDR, (uint32)__ALGORITH_RAM_SIZE, (uint32)__ALGORITH_RAM_ROM_ADDR, 4);
    data_ram_copy_dma((uint32)__ALGORITH_RAM_RAM_ADDR, (uint32)__ALGORITH_RAM_SIZE, (uint32)__ALGORITH_RAM_ROM_ADDR, 4);
    /* FOC 数据区 */
    data_ram_copy_dma((uint32)__FOC_DATA_SRAM_ADDR, (uint32)__FOC_DATA_SIZE, (uint32)__FOC_DATA_ROM_ADDR, 4);

    data_ram_copy_dma((uint32)__RDC_CODE_SRAM_ADDR, (uint32)__RDC_CODE_SIZE, (uint32)__RDC_CODE_ROM_ADDR, 4);  

    data_ram_copy_dma((uint32)__MCU_CODE_SRAM_ADDR, (uint32)__MCU_CODE_SIZE, (uint32)__MCU_CODE_ROM_ADDR, 4);  

}

void default_clear_sec_init(void)       /* 清零初始化代码段 */
{
    /* MEASUREMENT 未初始化数据 */
	dma_clear_ram((uint32)__MEA_DATA_RAM_ADDR, (uint32)__MEA_DATA_SIZE);
    /* BSW ASIL-A 未初始化数据 */
	dma_clear_ram((uint32)__BSW_BSS_ASILA_RAM_ADDR, (uint32)__BSW_BSS_ASILA_SIZE);
	/* BSW ASIL-B 未初始化数据 */
	dma_clear_ram((uint32)__BSW_BSS_ASILB_RAM_ADDR, (uint32)__BSW_BSS_ASILB_SIZE);
	/* BSW ASIL-C 未初始化数据 */
	dma_clear_ram((uint32)__BSW_BSS_ASILC_RAM_ADDR, (uint32)__BSW_BSS_ASILC_SIZE);
	/* BSW global 未初始化数据 */
	dma_clear_ram((uint32)__BSW_BSS_GLOBAL_RAM_ADDR, (uint32)__BSW_BSS_GLOBAL_SIZE);
	/* ASW ASIL-A 未初始化数据 */
	dma_clear_ram((uint32)__ASW_BSS_ASILA_RAM_ADDR, (uint32)__ASW_BSS_ASILA_SIZE);
	/* ASW ASIL-B 未初始化数据 */
	dma_clear_ram((uint32)__ASW_BSS_ASILB_RAM_ADDR, (uint32)__ASW_BSS_ASILB_SIZE);
	/* ASW ASIL-C 未初始化数据 */
	dma_clear_ram((uint32)__ASW_BSS_ASILC_RAM_ADDR, (uint32)__ASW_BSS_ASILC_SIZE);
	/* ASW global 未初始化数据 */
	dma_clear_ram((uint32)__ASW_BSS_GLOBAL_RAM_ADDR, (uint32)__ASW_BSS_GLOBAL_SIZE);
	/* ASW AM 未初始化数据 */
	dma_clear_ram((uint32)__ASW_BSS_QM_RAM_ADDR, (uint32)__ASW_BSS_QM_SIZE);
	/* BSS Share 未初始化数据 */
	dma_clear_ram((uint32)__BSS_SHARE_RAM_ADDR, (uint32)__BSS_SHARE_SIZE);
	/* 标准未初始化数据 */
	dma_clear_ram((uint32)__BSS_RAM_ADDR, (uint32)__BSS_SIZE);
	/* 小型未初始化数据 */
	dma_clear_ram((uint32)__SBSS2_RAM_ADDR, (uint32)__SBSS2_SIZE);
	/* BSS_OS 未初始化数据 */
	dma_clear_ram((uint32)__BSS_OS_RAM_ADDR, (uint32)__BSS_OS_SIZE);
	/* EEPROM RAM 区 */
	dma_clear_ram((uint32)__EE_BLOCK_RAM_ADDR, (uint32)__EE_BLOCK_SIZE);
    /* FOC 未初始化数据*/
    dma_clear_ram((uint32)__FOC_BSS_SRAM_ADDR, (uint32)__FOC_BSS_SIZE);
    /* RDC 未初始化数据*/
    dma_clear_ram((uint32)__RDC_BSS_SRAM_ADDR, (uint32)__RDC_BSS_SIZE);
}
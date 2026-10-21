#ifdef CCFC3012PT
/**************************************************************************** 
* @FilePath: Startup.s
* @Author: CCORE
* @Date: 2024-11-27, 15:14:12
* @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
* @Descripttion: Startup Assembler File
* @MCAL Version: 3.0.0
* @Safety Version: 1.0.0
*****************************************************************************/
/*** create info ***************************************************************
*@ File name: CCFC3011PT_startup.S
*@ Author : liufengyuan 
*@ date :2025-12-25
*@ Description : 鍚姩鏂囦欢
**** modify info ***************************************************************
*@ version :0.0
*@ Modifier : liufengyuan 
*@ date :2025-12-25
*@ Modification Description : 鍒濆鐗堟湰,涓� 20251225鐨凾CU3.0 褰撳墠鍐呭瓨鍒嗗竷_V0.1.xlsx 涓�鑷�
*@ version :0.1
*@ Modifier : liufengyuan 
*@ date :2026-01-06
*@ Modification Description : 鎸夌収 A016102_TCU3000_闄勪欢_MemoryMap_V2.2.xls 鍒嗛厤
                        1銆佷紭鍖杁tcmECC鍒濆鍖栫殑閫昏緫锛屽垹闄ゆ棤鐢ㄦ眹缂栬鍙ワ紱
                        2銆佷紭鍖朞VC鐨凟CC鍒濆鍖栫▼搴忥紝闃叉鍥燚ATA鐨勫垽鏂笉鎵ц鍒濆鍖�
                        3銆佷紭鍖朣AFDATACOPY鐨勯�昏緫
*@ version :0.2
*@ Modifier : liufengyuan 
*@ date :2026-02-03
*@ Modification Description : 鎸夌収 A016102_TCU3000_闄勪欢_MemoryMap_V2.6.xls 鍒嗛厤
                            鎸夌収ld鏂囦欢鍒嗛厤鐨勫尯鍩� 1銆佸垵濮嬪寲ECC 2銆佸垵濮嬪寲鏈夊垵鍊肩殑娈� 3銆佸垵濮嬪寲鏃犲垵鍊肩殑娈�
*@ version :0.3
*@ Modifier : liufengyuan 
*@ date :2026-02-05
*@ Modification Description :   鎸夌収 A016102_TCU3000_闄勪欢_MemoryMap_V2.6.xls 鍒嗛厤锛�
                                閫傞厤鐨刴ain.c    闇�瑕� V0.1 鍙婁互涓�
                                閫傞厤鐨�.ld 鏂囦欢  闇�瑕� V0.3 鍙婁互涓�
                                閫傞厤鐨刴emory.h  闇�瑕� V0.2 鍙婁互涓�
                            1銆佸鍔犱娇鐢―MA鍒濆鍖栫殑瀹忓畾涔�
                            2銆佸皢sbss2 娈电殑鍒濆鍖� 鐢眂opy鏀规垚clear
                            3銆佸鍔燗LGORITH_RAM 娈电殑鍒濆鍖�(copy)
*@ version :0.4
*@ Modifier : wangjiacheng
*@ date :2026-03-25
*@ Modification Description :   鎸夌収 A016102_TCU3000_闄勪欢_MemoryMap_V2.6.xls 鍒嗛厤锛�
                                閫傞厤鐨刴ain.c    闇�瑕� V0.1 鍙婁互涓�
                                閫傞厤鐨�.ld 鏂囦欢  闇�瑕� V0.3 鍙婁互涓�
                                閫傞厤鐨刴emory.h  闇�瑕� V0.2 鍙婁互涓�
                        1銆佸鎵�鏈夋牳498瀵勫瓨鍣紙DMEMCTL1锛夎繘琛岀疆浣嶏紝璧嬪��0xAAAAAAAA,
                        瑙ｅ喅鍚勪釜Core* CMPU鍦ㄥ搴� Local Ram涓�0x5*800000-0x5*810000涓璏P鏉冮檺閰嶇疆鏃犱綔鐢ㄩ棶棰�
*@ version :0.5
*@ Modifier : liufengyuan
*@ date :2026-04-16
*@ Modification Description :   鎸夌収 A016102_TCU3000_闄勪欢_MemoryMap_V2.8.xls 鍒嗛厤锛�
                                閫傞厤鐨刴ain.c    闇�瑕� V0.2 鍙婁互涓�
                                閫傞厤鐨�.ld 鏂囦欢  闇�瑕� V0.6 鍙婁互涓�
                                閫傞厤鐨刴emory.h  闇�瑕� V0.4 鍙婁互涓�
                        1銆佸鍔燗SW QM data娈靛拰bss娈电殑姹囩紪鍒濆鍖�
*@ version :0.6
*@ Modifier : huangbaoxing
*@ date :2026-06-08
*@ Modification Description :   修改内存分配信息,按照 A020102_JILI_XCU_MemoryMap_V0.3.xls 分配
                                适配的 main.c  需要 V0.3 及以上
                                适配的 .ld 文件 需要 V0.8 及以上
                                适配的 memory.h 需要 V0.7 及以上
                        1、将6段标定区合并为一块，新增观测区ECC初始化
********************************************************************************/
#define  CPU_FIRST_BOOT_CORE 0

#ifdef __ghs__    /* GreenHills */
    .section    .startup, axv
    .vle

    .align 3  ;# 8 bytes

    .extern   main
    .extern   Mcore_Init
    #if SAFETY_ENABLE
    .extern __CACHE_SRAM_SIZE
    .extern __CACHE_SRAM_BASE_ADDR
    .extern __ROM_COPY_SRAM_SIZE
    .extern __ROM_COPY_BASE_ADDR
    .extern SAF_FLASH_CopyCodeRam
    #endif
    .extern __SP_INIT
    .extern __SP_INIT_0
    .extern __SP_INIT_1
    .extern __SP_INIT_2
    .extern __SP_INIT_3
    .extern __SP_ENTRY_0
    .extern __SP_ENTRY_1
    .extern __SP_ENTRY_2
    .extern __SP_ENTRY_3
    
    ;# 娣诲姞鍏朵粬浣跨敤鐨勫閮ㄧ鍙峰０鏄�
    .extern __SYSRAM_USED_SIZE
    .extern __SYSRAM_ADDR
    .extern __I_MEM0_USED_SIZE
    .extern __I_MEM0_ADDR
    .extern __D_MEM0_USED_SIZE
    .extern __D_MEM0_ADDR
    .extern __I_MEM1_USED_SIZE
    .extern __I_MEM1_ADDR
    .extern __D_MEM1_USED_SIZE
    .extern __D_MEM1_ADDR
    .extern __I_MEM2_USED_SIZE
    .extern __I_MEM2_ADDR
    .extern __D_MEM2_USED_SIZE
    .extern __D_MEM2_ADDR
    .extern __I_MEM3_USED_SIZE
    .extern __I_MEM3_ADDR
    .extern __D_MEM3_USED_SIZE
    .extern __D_MEM3_ADDR
    
    .extern __INTC_VECTOR_TABLE_SIZE
    .extern __INTC_VECTOR_TABLE_ROM_ADDR
    .extern __INTC_VECTOR_TABLE_RAM_ADDR
    
    ;# 娣诲姞鏁版嵁娈电浉鍏崇殑澶栭儴绗﹀彿澹版槑
    .extern __DATA_SIZE
    .extern __DATA_ROM_ADDR
    .extern __DATA_RAM_ADDR
    .extern __BSS_SIZE
    .extern __BSS_RAM_ADDR
    
    ;# 娣诲姞SDA鐩稿叧绗﹀彿
    .extern _SDA_BASE_
    .extern _SDA2_BASE_

    ;# FOC-MOTOR
    .extern __FOC_BSS_SIZE 
    .extern __FOC_BSS_SRAM_ADDR   
    .extern __FOC_DATA_SIZE 
    .extern __FOC_DATA_ROM_ADDR
    .extern __FOC_DATA_SRAM_ADDR   

    ;# RDC-MOTOR
    .extern __RDC_BSS_SIZE 
    .extern __RDC_BSS_SRAM_ADDR   
    .extern __RDC_DATA_SIZE 
    .extern __RDC_DATA_ROM_ADDR
    .extern __RDC_DATA_SRAM_ADDR  
    .extern __RDC_CODE_SIZE 
    .extern __RDC_CODE_ROM_ADDR
    .extern __RDC_CODE_SRAM_ADDR 

    ;# MCU
    .extern __MCU_CODE_SIZE 
    .extern __MCU_CODE_ROM_ADDR
    .extern __MCU_CODE_SRAM_ADDR 


#endif
#ifdef __GNUC__   /* GCC */
    .section .startup, "ax"
#endif
#ifdef __DCC__   /* Diab */
   .section ".startup",4,rx
#endif
#ifdef __HIGHTEC__ /* HighTec */
#define e_bdnz bdnz
#define e_beq  beq
#define e_subi subi
#define e_bne  bne
#endif


    .globl    _start
_start:
 
;#****************************** Turn off SWTs ********************************
#if defined(DISABLE_SWT0)
;#SWT0
#ifdef SMP_ONLY_ONE_ELF
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, 0
    e_bne       DISSWT0END
#endif

    e_lis r4, 0xFC05
    e_or2i r4, 0x0000

    e_li r3, 0xC520
    e_stw r3, 0x10(r4)

    e_li r3, 0xD928
    e_stw r3, 0x10(r4)

    e_lis r3, 0xFFFF
    e_or2i r3, 0x010A
    e_stw r3, 0(r4)
DISSWT0END:
#endif

;#********************************* Enable BTB ********************************
;# Flush & Enable BTB - Set BBFI bit in BUCSR
    e_li    r3, 0x201
    mtspr    1013, r3
    se_isync

;#**************************** Init Core Registers ****************************
;# The E200Z4 core needs its registers initialising before they are used
;# otherwise in Lock Step mode the two cores will contain different random data.
;# If this is stored to memory (e.g. stacked) it will cause a Lock Step error.

;# GPRs 0-31
    e_li    r0, 0
    e_li    r1, 0
    e_li    r2, 0
    e_li    r3, 0
    e_li    r4, 0
    e_li    r5, 0
    e_li    r6, 0
    e_li    r7, 0
    e_li    r8, 0
    e_li    r9, 0
    e_li    r10, 0
    e_li    r11, 0
    e_li    r12, 0
    e_li    r13, 0
    e_li    r14, 0
    e_li    r15, 0
    e_li    r16, 0
    e_li    r17, 0
    e_li    r18, 0
    e_li    r19, 0
    e_li    r20, 0
    e_li    r21, 0
    e_li    r22, 0
    e_li    r23, 0
    e_li    r24, 0
    e_li    r25, 0
    e_li    r26, 0
    e_li    r27, 0
    e_li    r28, 0
    e_li    r29, 0
    e_li    r30, 0
    e_li    r31, 0

;# Init any other CPU register which might be stacked (before being used).

    mtspr    1, r1         ;#XER
    mtcrf    0xFF, r1
    mtspr    CTR, r1
    mtspr    272, r1        ;#SPRG0
    mtspr    273, r1        ;#SPRG1
    mtspr    274, r1        ;#SPRG2
    mtspr    275, r1        ;#SPRG3
    mtspr    58, r1         ;#CSRR0
    mtspr    59, r1         ;#CSRR1
    mtspr    570, r1        ;#MCSRR0
    mtspr    571, r1        ;#MCSRR1
    mtspr    61, r1         ;#DEAR
    mtspr    63, r1         ;#IVPR
    mtspr    256, r1        ;#USPRG0
    mtspr    62, r1         ;#ESR
    mtspr    8,r31          ;#LR

;# if SMP, only the BOOT_CORE need to init outer core SRAM
#ifdef SMP_ONLY_ONE_ELF
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, CPU_FIRST_BOOT_CORE
    e_beq       _init_outer_core_sram_start
    e_bne       _init_outer_core_sram_end
#else
    e_b       _init_outer_core_sram_start
#endif

_init_outer_core_sram_start:
;#***************************** Initialise SYS RAM ECC ***************************/
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __SYSRAM_USED_SIZE@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __SYSRAM_USED_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the internal SRAM
    e_lis       r5, __SYSRAM_ADDR@h
    e_or2i      r5, __SYSRAM_ADDR@l

;# Fill SRAM with writes of 32GPRs    
sram_loop:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      sram_loop           # Loop for all of SRAM
_init_outer_core_sram_end:




_init_safetylib_test_sram_start:
;#***************************** Initialise SYS RAM ECC ***************************/
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, 0x2000@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, 0x2000@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the internal SRAM
    e_lis       r5, 0x400be000@h
    e_or2i      r5, 0x400be000@l

;# Fill SRAM with writes of 32GPRs    
sram_safetylib_loop:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      sram_safetylib_loop           # Loop for all of SRAM
_init_safetylib_test_sram_end:








_init_inner_core_sram_start:
;#************************ Initialise Local Data SRAM ECC *********************/
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, 0
    e_beq       _set_itcm_attr_0
    e_bne       _set_dtcm_attr_end_new

_set_itcm_attr_0:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __I_MEM0_USED_SIZE@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __I_MEM0_USED_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __I_MEM0_ADDR@h
    e_or2i      r5, __I_MEM0_ADDR@l

;# Fill Local SRAM with writes of 32GPRs
imem_loop0:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      imem_loop0          # Loop for all of SRAM

_set_dtcm_attr_0:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __D_MEM0_USED_SIZE@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __D_MEM0_USED_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __D_MEM0_ADDR@h
    e_or2i      r5, __D_MEM0_ADDR@l

;# Fill Local SRAM with writes of 32GPRs
dmem_loop0:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      dmem_loop0          # Loop for all of SRAM

_set_itcm_attr_1:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __I_MEM1_USED_SIZE@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __I_MEM1_USED_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __I_MEM1_ADDR@h
    e_or2i      r5, __I_MEM1_ADDR@l

;# Fill Local SRAM with writes of 32GPRs
imem_loop1:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      imem_loop1          # Loop for all of SRAM

_set_dtcm_attr_1:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __D_MEM1_USED_SIZE@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __D_MEM1_USED_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __D_MEM1_ADDR@h
    e_or2i      r5, __D_MEM1_ADDR@l

;# Fill Local SRAM with writes of 32GPRs
dmem_loop1:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      dmem_loop1          # Loop for all of SRAM

_set_itcm_attr_2:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __I_MEM2_USED_SIZE@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __I_MEM2_USED_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __I_MEM2_ADDR@h
    e_or2i      r5, __I_MEM2_ADDR@l

;# Fill Local SRAM with writes of 32GPRs
imem_loop2:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      imem_loop2          # Loop for all of SRAM

_set_dtcm_attr_2:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __D_MEM2_USED_SIZE@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __D_MEM2_USED_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __D_MEM2_ADDR@h
    e_or2i      r5, __D_MEM2_ADDR@l

;# Fill Local SRAM with writes of 32GPRs
dmem_loop2:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      dmem_loop2          # Loop for all of SRAM

_set_itcm_attr_3:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __I_MEM3_USED_SIZE@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __I_MEM3_USED_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __I_MEM3_ADDR@h
    e_or2i      r5, __I_MEM3_ADDR@l

;# Fill Local SRAM with writes of 32GPRs
imem_loop3:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      imem_loop3          # Loop for all of SRAM

_set_dtcm_attr_3:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __D_MEM3_USED_SIZE@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __D_MEM3_USED_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __D_MEM3_ADDR@h
    e_or2i      r5, __D_MEM3_ADDR@l

;# Fill Local SRAM with writes of 32GPRs
dmem_loop3:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      dmem_loop3          # Loop for all of SRAM

_set_itcm_attr_4:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __I_MEM4_USED_SIZE@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __I_MEM4_USED_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __I_MEM4_ADDR@h
    e_or2i      r5, __I_MEM4_ADDR@l

;# Fill Local SRAM with writes of 32GPRs
imem_loop4:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      imem_loop4          # Loop for all of SRAM

_set_dtcm_attr_4:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __D_MEM4_USED_SIZE@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __D_MEM4_USED_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __D_MEM4_ADDR@h
    e_or2i      r5, __D_MEM4_ADDR@l

;# Fill Local SRAM with writes of 32GPRs
dmem_loop4:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      dmem_loop4          # Loop for all of SRAM

_set_itcm_attr_5:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __I_MEM5_USED_SIZE@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __I_MEM5_USED_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __I_MEM5_ADDR@h
    e_or2i      r5, __I_MEM5_ADDR@l

;# Fill Local SRAM with writes of 32GPRs
imem_loop5:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      imem_loop5          # Loop for all of SRAM

_set_dtcm_attr_5:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __D_MEM5_USED_SIZE@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __D_MEM5_USED_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __D_MEM5_ADDR@h
    e_or2i      r5, __D_MEM5_ADDR@l

;# Fill Local SRAM with writes of 32GPRs
dmem_loop5:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      dmem_loop5          # Loop for all of SRAM

_set_dtcm_attr_end_new:


#ifndef DATA_COPY_USE_DMA
;# if SMP, only the BOOT_CORE need to copy data from FALSH to SRAM
#ifdef SMP_ONLY_ONE_ELF
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, CPU_FIRST_BOOT_CORE
    e_beq       _copy_data_from_flash_to_sram_start
    e_bne       _copy_data_from_flash_to_sram_end
#else
    e_b       _copy_data_from_flash_to_sram_start
#endif

_copy_data_from_flash_to_sram_start:
;#*************** Load data from Flash into RAM ************/
;# Initialised Vector - ".intc_vector_table"
VECTORCOPY:
    e_lis       r9, __INTC_VECTOR_TABLE_SIZE@h      # Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __INTC_VECTOR_TABLE_SIZE@l       # Load lower SRAM load size into R9
    e_cmp16i    r9,0                    # Compare to see if equal to 0
    e_beq       VECTORCOPYEND               # Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                      # Store no. of bytes to be moved in counter

    e_lis       r10, __INTC_VECTOR_TABLE_ROM_ADDR@h  # Load address of first SRAM load into R10
    e_or2i      r10, __INTC_VECTOR_TABLE_ROM_ADDR@l  # Load lower address of SRAM load into R10
    e_subi      r10,r10, 1              # Decrement address to prepare for ROMCPYLOOP

    e_lis       r5, __INTC_VECTOR_TABLE_RAM_ADDR@h  # Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __INTC_VECTOR_TABLE_RAM_ADDR@l  # Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1               # Decrement address to prepare for ROMCPYLOOP
    cmp         cr0,r5, r10
    e_beq       VECTORCOPYEND               # Skip to SDATA copy if addresses is equal (no need to copy data)

VECTORCPYLOOP:
    e_lbzu      r4, 1(r10)              # Load data byte at R10 into R4,incrementing (update) ROM address
    e_stbu      r4, 1(r5)               # Store R4 data byte into SRAM at R5 and update SRAM address
    e_bdnz      VECTORCPYLOOP             # Branch if more bytes to load from ROM

VECTORCOPYEND:

;# Initialised Vector - ".XCP_CAL"
CALCOPY:
    e_lis       r9, __CAL_DATA_SIZE@h       # Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __CAL_DATA_SIZE@l       # Load lower SRAM load size into R9
    e_cmp16i    r9,0                    # Compare to see if equal to 0
    e_beq       CALCOPYEND               # Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                      # Store no. of bytes to be moved in counter

    e_lis       r10, __CAL_DATA_ROM_ADDR@h  # Load address of first SRAM load into R10
    e_or2i      r10, __CAL_DATA_ROM_ADDR@l  # Load lower address of SRAM load into R10
    e_subi      r10,r10, 1              # Decrement address to prepare for ROMCPYLOOP

    e_lis       r5, __CAL_DATA_RAM_ADDR@h  # Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __CAL_DATA_RAM_ADDR@l  # Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1               # Decrement address to prepare for ROMCPYLOOP
    cmp         cr0,r5, r10
    e_beq       CALCOPYEND               # Skip to SDATA copy if addresses is equal (no need to copy data)

CALCPYLOOP:
    e_lbzu      r4, 1(r10)              # Load data byte at R10 into R4,incrementing (update) ROM address
    e_stbu      r4, 1(r5)               # Store R4 data byte into SRAM at R5 and update SRAM address
    e_bdnz      CALCPYLOOP             # Branch if more bytes to load from ROM

CALCOPYEND:

;# FOC-MOTOR
FOCBSSCOPY:
    e_lis       r9, __FOC_BSS_SIZE@h        # Load upper BSW_BSS_ASILA size (# of bytes) into R9
    e_or2i      r9, __FOC_BSS_SIZE@l       # Load lower BSW_BSS_ASILA size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       FOCBSSCOPYEND               # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __FOC_BSS_SRAM_ADDR@h   # Load upper BSW_BSS_ASILA address into R5
    e_or2i      r5, __FOC_BSS_SRAM_ADDR@l   # Load lower BSW_BSS_ASILA address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

FOCBSSCPYLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into BSS at R5 and update address
    e_bdnz      FOCBSSCPYLOOP              # Branch if more bytes to clear

FOCBSSCOPYEND:


FOCDATACOPY:
    e_lis       r9, __FOC_DATA_SIZE@h       # Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __FOC_DATA_SIZE@l       # Load lower SRAM load size into R9
    e_cmp16i    r9,0                    # Compare to see if equal to 0
    e_beq       FOCDATACOPYEND               # Exit cfg_ROMCPY if size is zero (no data to initialise)
    mtctr       r9                      # Store no. of bytes to be moved in counter
    e_lis       r10, __FOC_DATA_ROM_ADDR@h  # Load address of first SRAM load into R10
    e_or2i      r10, __FOC_DATA_ROM_ADDR@l  # Load lower address of SRAM load into R10
    e_subi      r10,r10, 1              # Decrement address to prepare for ROMCPYLOOP
    e_lis       r5, __FOC_DATA_SRAM_ADDR@h  # Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __FOC_DATA_SRAM_ADDR@l  # Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1               # Decrement address to prepare for ROMCPYLOOP
    cmp         cr0,r5, r10
    e_beq       FOCDATACOPYEND               # Skip to SDATA copy if addresses is equal (no need to copy data)
FOCDATACPYLOOP:
    e_lbzu      r4, 1(r10)              # Load data byte at R10 into R4,incrementing (update) ROM address
    e_stbu      r4, 1(r5)               # Store R4 data byte into SRAM at R5 and update SRAM address
    e_bdnz      FOCDATACPYLOOP             # Branch if more bytes to load from ROM

FOCDATACOPYEND:


;# RDC-MOTOR
RDCBSSCOPY:
    e_lis       r9, __RDC_BSS_SIZE@h        # Load upper BSW_BSS_ASILA size (# of bytes) into R9
    e_or2i      r9, __RDC_BSS_SIZE@l       # Load lower BSW_BSS_ASILA size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       RDCBSSCOPYEND               # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __RDC_BSS_SRAM_ADDR@h   # Load upper BSW_BSS_ASILA address into R5
    e_or2i      r5, __RDC_BSS_SRAM_ADDR@l   # Load lower BSW_BSS_ASILA address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

RDCBSSCPYLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into BSS at R5 and update address
    e_bdnz      RDCBSSCPYLOOP              # Branch if more bytes to clear

RDCBSSCOPYEND:


RDCDATACOPY:
    e_lis       r9, __RDC_DATA_SIZE@h       # Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __RDC_DATA_SIZE@l       # Load lower SRAM load size into R9
    e_cmp16i    r9,0                    # Compare to see if equal to 0
    e_beq       RDCDATACOPYEND               # Exit cfg_ROMCPY if size is zero (no data to initialise)
    mtctr       r9                      # Store no. of bytes to be moved in counter
    e_lis       r10, __RDC_DATA_ROM_ADDR@h  # Load address of first SRAM load into R10
    e_or2i      r10, __RDC_DATA_ROM_ADDR@l  # Load lower address of SRAM load into R10
    e_subi      r10,r10, 1              # Decrement address to prepare for ROMCPYLOOP
    e_lis       r5, __RDC_DATA_SRAM_ADDR@h  # Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __RDC_DATA_SRAM_ADDR@l  # Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1               # Decrement address to prepare for ROMCPYLOOP
    cmp         cr0,r5, r10
    e_beq       RDCDATACOPYEND               # Skip to SDATA copy if addresses is equal (no need to copy data)
RDCDATACPYLOOP:
    e_lbzu      r4, 1(r10)              # Load data byte at R10 into R4,incrementing (update) ROM address
    e_stbu      r4, 1(r5)               # Store R4 data byte into SRAM at R5 and update SRAM address
    e_bdnz      RDCDATACPYLOOP             # Branch if more bytes to load from ROM

RDCDATACOPYEND:

RDCCODECOPY:
    e_lis       r9, __RDC_CODE_SIZE@h       # Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __RDC_CODE_SIZE@l       # Load lower SRAM load size into R9
    e_cmp16i    r9,0                    # Compare to see if equal to 0
    e_beq       RDCCODECOPYEND               # Exit cfg_ROMCPY if size is zero (no data to initialise)
    mtctr       r9                      # Store no. of bytes to be moved in counter
    e_lis       r10, __RDC_CODE_ROM_ADDR@h  # Load address of first SRAM load into R10
    e_or2i      r10, __RDC_CODE_ROM_ADDR@l  # Load lower address of SRAM load into R10
    e_subi      r10,r10, 1              # Decrement address to prepare for ROMCPYLOOP
    e_lis       r5, __RDC_CODE_SRAM_ADDR@h  # Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __RDC_CODE_SRAM_ADDR@l  # Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1               # Decrement address to prepare for ROMCPYLOOP
    cmp         cr0,r5, r10
    e_beq       RDCCODECOPYEND               # Skip to SDATA copy if addresses is equal (no need to copy data)
RDCCODECPYLOOP:
    e_lbzu      r4, 1(r10)              # Load data byte at R10 into R4,incrementing (update) ROM address
    e_stbu      r4, 1(r5)               # Store R4 data byte into SRAM at R5 and update SRAM address
    e_bdnz      RDCCODECPYLOOP             # Branch if more bytes to load from ROM

RDCCODECOPYEND:


MCUCODECOPY:
    e_lis       r9, __MCU_CODE_SIZE@h       # Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __MCU_CODE_SIZE@l       # Load lower SRAM load size into R9
    e_cmp16i    r9,0                    # Compare to see if equal to 0
    e_beq       MCUCODECOPYEND               # Exit cfg_ROMCPY if size is zero (no data to initialise)
    mtctr       r9                      # Store no. of bytes to be moved in counter
    e_lis       r10, __MCU_CODE_ROM_ADDR@h  # Load address of first SRAM load into R10
    e_or2i      r10, __MCU_CODE_ROM_ADDR@l  # Load lower address of SRAM load into R10
    e_subi      r10,r10, 1              # Decrement address to prepare for ROMCPYLOOP
    e_lis       r5, __MCU_CODE_SRAM_ADDR@h  # Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __MCU_CODE_SRAM_ADDR@l  # Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1               # Decrement address to prepare for ROMCPYLOOP
    cmp         cr0,r5, r10
    e_beq       MCUCOPYEND               # Skip to SDATA copy if addresses is equal (no need to copy data)
MCUCODECPYLOOP:
    e_lbzu      r4, 1(r10)              # Load data byte at R10 into R4,incrementing (update) ROM address
    e_stbu      r4, 1(r5)               # Store R4 data byte into SRAM at R5 and update SRAM address
    e_bdnz      MCUCODECPYLOOP             # Branch if more bytes to load from ROM

MCUCODECOPYEND:



;# Initialised Vector - ".safcode_useVar"
SAFUSEDVARCOPY:
    e_lis       r9, __SAFCODE_USEVAR_SIZE@h       # Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __SAFCODE_USEVAR_SIZE@l       # Load lower SRAM load size into R9
    e_cmp16i    r9,0                    # Compare to see if equal to 0
    e_beq       SAFUSEDVARCOPYEND               # Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                      # Store no. of bytes to be moved in counter

    e_lis       r10, __SAFCODE_USEVAR_ROM_ADDR@h  # Load address of first SRAM load into R10
    e_or2i      r10, __SAFCODE_USEVAR_ROM_ADDR@l  # Load lower address of SRAM load into R10
    e_subi      r10,r10, 1              # Decrement address to prepare for ROMCPYLOOP

    e_lis       r5, __SAFCODE_USEVAR_RAM_ADDR@h  # Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __SAFCODE_USEVAR_RAM_ADDR@l  # Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1               # Decrement address to prepare for ROMCPYLOOP
    cmp         cr0,r5, r10
    e_beq       SAFUSEDVARCOPYEND               # Skip to SDATA copy if addresses is equal (no need to copy data)

SAFUSEDVARCPYLOOP:
    e_lbzu      r4, 1(r10)              # Load data byte at R10 into R4,incrementing (update) ROM address
    e_stbu      r4, 1(r5)               # Store R4 data byte into SRAM at R5 and update SRAM address
    e_bdnz      SAFUSEDVARCPYLOOP             # Branch if more bytes to load from ROM

SAFUSEDVARCOPYEND:

;# Initialised Vector - ".BSW_DATA_ASILA"
BSWDATAASILACOPY:
    e_lis       r9, __BSW_DATA_ASILA_SIZE@h
    e_or2i      r9, __BSW_DATA_ASILA_SIZE@l
    e_cmp16i    r9,0
    e_beq       BSWDATAASILACOPYEND

    mtctr       r9

    e_lis       r10, __BSW_DATA_ASILA_ROM_ADDR@h
    e_or2i      r10, __BSW_DATA_ASILA_ROM_ADDR@l
    e_subi      r10,r10, 1

    e_lis       r5, __BSW_DATA_ASILA_RAM_ADDR@h
    e_or2i      r5, __BSW_DATA_ASILA_RAM_ADDR@l
    e_subi      r5, r5, 1
    cmp         cr0,r5, r10
    e_beq       BSWDATAASILACOPYEND

BSWDATAASILACPYLOOP:
    e_lbzu      r4, 1(r10)
    e_stbu      r4, 1(r5)
    e_bdnz      BSWDATAASILACPYLOOP

BSWDATAASILACOPYEND:
;# Initialised Vector - ".BSW_DATA_ASILB"
BSWDATAASILBCOPY:
    e_lis       r9, __BSW_DATA_ASILB_SIZE@h
    e_or2i      r9, __BSW_DATA_ASILB_SIZE@l
    e_cmp16i    r9,0
    e_beq       BSWDATAASILBCOPYEND

    mtctr       r9

    e_lis       r10, __BSW_DATA_ASILB_ROM_ADDR@h
    e_or2i      r10, __BSW_DATA_ASILB_ROM_ADDR@l
    e_subi      r10,r10, 1

    e_lis       r5, __BSW_DATA_ASILB_RAM_ADDR@h
    e_or2i      r5, __BSW_DATA_ASILB_RAM_ADDR@l
    e_subi      r5, r5, 1
    cmp         cr0,r5, r10
    e_beq       BSWDATAASILBCOPYEND

BSWDATAASILBCPYLOOP:
    e_lbzu      r4, 1(r10)
    e_stbu      r4, 1(r5)
    e_bdnz      BSWDATAASILBCPYLOOP

BSWDATAASILBCOPYEND:
;# Initialised Vector - ".BSW_DATA_ASILC"
BSWDATAASILCCOPY:
    e_lis       r9, __BSW_DATA_ASILC_SIZE@h
    e_or2i      r9, __BSW_DATA_ASILC_SIZE@l
    e_cmp16i    r9,0
    e_beq       BSWDATAASILCCOPYEND

    mtctr       r9

    e_lis       r10, __BSW_DATA_ASILC_ROM_ADDR@h
    e_or2i      r10, __BSW_DATA_ASILC_ROM_ADDR@l
    e_subi      r10,r10, 1

    e_lis       r5, __BSW_DATA_ASILC_RAM_ADDR@h
    e_or2i      r5, __BSW_DATA_ASILC_RAM_ADDR@l
    e_subi      r5, r5, 1
    cmp         cr0,r5, r10
    e_beq       BSWDATAASILCCOPYEND

BSWDATAASILCCPYLOOP:
    e_lbzu      r4, 1(r10)
    e_stbu      r4, 1(r5)
    e_bdnz      BSWDATAASILCCPYLOOP

BSWDATAASILCCOPYEND:
;# Initialised Vector - ".BSW_DATA_GLOBAL"
BSWDATAGLOBALCOPY:
    e_lis       r9, __BSW_DATA_GLOBAL_SIZE@h
    e_or2i      r9, __BSW_DATA_GLOBAL_SIZE@l
    e_cmp16i    r9,0
    e_beq       BSWDATAGLOBALCOPYEND

    mtctr       r9

    e_lis       r10, __BSW_DATA_GLOBAL_ROM_ADDR@h
    e_or2i      r10, __BSW_DATA_GLOBAL_ROM_ADDR@l
    e_subi      r10,r10, 1

    e_lis       r5, __BSW_DATA_GLOBAL_RAM_ADDR@h
    e_or2i      r5, __BSW_DATA_GLOBAL_RAM_ADDR@l
    e_subi      r5, r5, 1
    cmp         cr0,r5, r10
    e_beq       BSWDATAGLOBALCOPYEND

BSWDATAGLOBALCPYLOOP:
    e_lbzu      r4, 1(r10)
    e_stbu      r4, 1(r5)
    e_bdnz      BSWDATAGLOBALCPYLOOP

BSWDATAGLOBALCOPYEND:
;# Initialised Vector - ".ASW_DATA_ASILA"
ASWDATAASILACOPY:
    e_lis       r9, __ASW_DATA_ASILA_SIZE@h
    e_or2i      r9, __ASW_DATA_ASILA_SIZE@l
    e_cmp16i    r9,0
    e_beq       ASWDATAASILACOPYEND

    mtctr       r9

    e_lis       r10, __ASW_DATA_ASILA_ROM_ADDR@h
    e_or2i      r10, __ASW_DATA_ASILA_ROM_ADDR@l
    e_subi      r10,r10, 1

    e_lis       r5, __ASW_DATA_ASILA_RAM_ADDR@h
    e_or2i      r5, __ASW_DATA_ASILA_RAM_ADDR@l
    e_subi      r5, r5, 1
    cmp         cr0,r5, r10
    e_beq       ASWDATAASILACOPYEND

ASWDATAASILACPYLOOP:
    e_lbzu      r4, 1(r10)
    e_stbu      r4, 1(r5)
    e_bdnz      ASWDATAASILACPYLOOP

ASWDATAASILACOPYEND:
;# Initialised Vector - ".ASW_DATA_ASILB"
ASWDATAASILBCOPY:
    e_lis       r9, __ASW_DATA_ASILB_SIZE@h
    e_or2i      r9, __ASW_DATA_ASILB_SIZE@l
    e_cmp16i    r9,0
    e_beq       ASWDATAASILBCOPYEND

    mtctr       r9

    e_lis       r10, __ASW_DATA_ASILB_ROM_ADDR@h
    e_or2i      r10, __ASW_DATA_ASILB_ROM_ADDR@l
    e_subi      r10,r10, 1

    e_lis       r5, __ASW_DATA_ASILB_RAM_ADDR@h
    e_or2i      r5, __ASW_DATA_ASILB_RAM_ADDR@l
    e_subi      r5, r5, 1
    cmp         cr0,r5, r10
    e_beq       ASWDATAASILBCOPYEND

ASWDATAASILBCPYLOOP:
    e_lbzu      r4, 1(r10)
    e_stbu      r4, 1(r5)
    e_bdnz      ASWDATAASILBCPYLOOP

ASWDATAASILBCOPYEND:
;# Initialised Vector - ".ASW_DATA_ASILC"
ASWDATAASILCCOPY:
    e_lis       r9, __ASW_DATA_ASILC_SIZE@h
    e_or2i      r9, __ASW_DATA_ASILC_SIZE@l
    e_cmp16i    r9,0
    e_beq       ASWDATAASILCCOPYEND

    mtctr       r9

    e_lis       r10, __ASW_DATA_ASILC_ROM_ADDR@h
    e_or2i      r10, __ASW_DATA_ASILC_ROM_ADDR@l
    e_subi      r10,r10, 1

    e_lis       r5, __ASW_DATA_ASILC_RAM_ADDR@h
    e_or2i      r5, __ASW_DATA_ASILC_RAM_ADDR@l
    e_subi      r5, r5, 1
    cmp         cr0,r5, r10
    e_beq       ASWDATAASILCCOPYEND

ASWDATAASILCCPYLOOP:
    e_lbzu      r4, 1(r10)
    e_stbu      r4, 1(r5)
    e_bdnz      ASWDATAASILCCPYLOOP

ASWDATAASILCCOPYEND:
;# Initialised Vector - ".ASW_DATA_GLOBAL"
ASWDATAGLOBALCOPY:
    e_lis       r9, __ASW_DATA_GLOBAL_SIZE@h
    e_or2i      r9, __ASW_DATA_GLOBAL_SIZE@l
    e_cmp16i    r9,0
    e_beq       ASWDATAGLOBALCOPYEND

    mtctr       r9

    e_lis       r10, __ASW_DATA_GLOBAL_ROM_ADDR@h
    e_or2i      r10, __ASW_DATA_GLOBAL_ROM_ADDR@l
    e_subi      r10,r10, 1

    e_lis       r5, __ASW_DATA_GLOBAL_RAM_ADDR@h
    e_or2i      r5, __ASW_DATA_GLOBAL_RAM_ADDR@l
    e_subi      r5, r5, 1
    cmp         cr0,r5, r10
    e_beq       ASWDATAGLOBALCOPYEND

ASWDATAGLOBALCPYLOOP:
    e_lbzu      r4, 1(r10)
    e_stbu      r4, 1(r5)
    e_bdnz      ASWDATAGLOBALCPYLOOP

ASWDATAGLOBALCOPYEND:
;# Initialised Vector - ".ASW_DATA_QM"
ASWDATAQMCOPY:
    e_lis       r9, __ASW_DATA_QM_SIZE@h
    e_or2i      r9, __ASW_DATA_QM_SIZE@l
    e_cmp16i    r9,0
    e_beq       ASWDATAQMCOPYEND

    mtctr       r9

    e_lis       r10, __ASW_DATA_QM_ROM_ADDR@h
    e_or2i      r10, __ASW_DATA_QM_ROM_ADDR@l
    e_subi      r10,r10, 1

    e_lis       r5, __ASW_DATA_QM_RAM_ADDR@h
    e_or2i      r5, __ASW_DATA_QM_RAM_ADDR@l
    e_subi      r5, r5, 1
    cmp         cr0,r5, r10
    e_beq       ASWDATAQMCOPYEND

ASWDATAQMCPYLOOP:
    e_lbzu      r4, 1(r10)
    e_stbu      r4, 1(r5)
    e_bdnz      ASWDATAQMCPYLOOP

ASWDATAQMCOPYEND:

;# DATA section
DATACOPY:
    e_lis       r9, __DATA_SIZE@h
    e_or2i      r9, __DATA_SIZE@l
    e_cmp16i    r9,0
    e_beq       DATACOPYEND

    mtctr       r9

    e_lis       r10, __DATA_ROM_ADDR@h
    e_or2i      r10, __DATA_ROM_ADDR@l
    e_subi      r10,r10, 1

    e_lis       r5, __DATA_RAM_ADDR@h
    e_or2i      r5, __DATA_RAM_ADDR@l
    e_subi      r5, r5, 1
    cmp         cr0,r5, r10
    e_beq       DATACOPYEND

DATACPYLOOP:
    e_lbzu      r4, 1(r10)
    e_stbu      r4, 1(r5)
    e_bdnz      DATACPYLOOP

DATACOPYEND:
;# DATA_SHARE section
DATASHARECOPY:
    e_lis       r9, __DATA_SHARE_SIZE@h
    e_or2i      r9, __DATA_SHARE_SIZE@l
    e_cmp16i    r9,0
    e_beq       DATASHARECOPYEND

    mtctr       r9

    e_lis       r10, __DATA_SHARE_ROM_ADDR@h
    e_or2i      r10, __DATA_SHARE_ROM_ADDR@l
    e_subi      r10,r10, 1

    e_lis       r5, __DATA_SHARE_RAM_ADDR@h
    e_or2i      r5, __DATA_SHARE_RAM_ADDR@l
    e_subi      r5, r5, 1
    cmp         cr0,r5, r10
    e_beq       DATASHARECOPYEND

DATASHARECPYLOOP:
    e_lbzu      r4, 1(r10)
    e_stbu      r4, 1(r5)
    e_bdnz      DATASHARECPYLOOP

DATASHARECOPYEND:
;# SDATA section
SDATACOPY:
    e_lis       r9, __SDATA_SIZE@h
    e_or2i      r9, __SDATA_SIZE@l
    e_cmp16i    r9,0
    e_beq       SDATACOPYEND

    mtctr       r9

    e_lis       r10, __SDATA_ROM_ADDR@h
    e_or2i      r10, __SDATA_ROM_ADDR@l
    e_subi      r10,r10, 1

    e_lis       r5, __SDATA_RAM_ADDR@h
    e_or2i      r5, __SDATA_RAM_ADDR@l
    e_subi      r5, r5, 1
    cmp         cr0,r5, r10
    e_beq       SDATACOPYEND

SDATACPYLOOP:
    e_lbzu      r4, 1(r10)
    e_stbu      r4, 1(r5)
    e_bdnz      SDATACPYLOOP

SDATACOPYEND:
;# SDATA2 section
SDATA2COPY:
    e_lis       r9, __SDATA2_SIZE@h
    e_or2i      r9, __SDATA2_SIZE@l
    e_cmp16i    r9,0
    e_beq       SDATA2COPYEND

    mtctr       r9

    e_lis       r10, __SDATA2_ROM_ADDR@h
    e_or2i      r10, __SDATA2_ROM_ADDR@l
    e_subi      r10,r10, 1

    e_lis       r5, __SDATA2_RAM_ADDR@h
    e_or2i      r5, __SDATA2_RAM_ADDR@l
    e_subi      r5, r5, 1
    cmp         cr0,r5, r10
    e_beq       SDATA2COPYEND

SDATA2CPYLOOP:
    e_lbzu      r4, 1(r10)
    e_stbu      r4, 1(r5)
    e_bdnz      SDATA2CPYLOOP

SDATA2COPYEND:
;# ALGORITH_RAM section
ALGORITH_RAMCOPY:
    e_lis       r9, __ALGORITH_RAM_SIZE@h
    e_or2i      r9, __ALGORITH_RAM_SIZE@l
    e_cmp16i    r9,0
    e_beq       ALGORITH_RAMCPYLOOPCOPYEND

    mtctr       r9

    e_lis       r10, __ALGORITH_RAM_ROM_ADDR@h
    e_or2i      r10, __ALGORITH_RAM_ROM_ADDR@l
    e_subi      r10,r10, 1

    e_lis       r5, __ALGORITH_RAM_RAM_ADDR@h
    e_or2i      r5, __ALGORITH_RAM_RAM_ADDR@l
    e_subi      r5, r5, 1
    cmp         cr0,r5, r10
    e_beq       ALGORITH_RAMCPYLOOPCOPYEND

ALGORITH_RAMCPYLOOP:
    e_lbzu      r4, 1(r10)
    e_stbu      r4, 1(r5)
    e_bdnz      ALGORITH_RAMCPYLOOP

ALGORITH_RAMCPYLOOPCOPYEND:
_copy_data_from_flash_to_sram_end:

#endif  /* ifdef DATA_COPY_USE_DMA */


#ifdef ICACHE_ENABLE
;#****************** Invalidate and Enable the Instruction cache **************
__icache_cfg:
    e_lis    r7, 0x0000
    e_or2i    r7, 0x03FF        #create mask for lower 11 bits
    mfspr    r5, 516            #in lower 11 bits we have icache size
    and.    r7, r7, r5        #check if we have icache
    e_beq    __icache_skip    #branch if not
    mfspr    r7, 1011
    e_li    r5, 0x2
    mtspr    1011,r5
    mfspr    r7, 1011
    e_li    r7, 0x4
    e_li    r8, 0x2
    e_lis    r11,0xFFFF
    e_or2i    r11,0xFFFB

__icache_inv:
    mfspr    r9, 1011
    and.    r10, r7, r9
    e_beq    __icache_no_abort
    and.    r10, r11, r9
    mtspr    1011, r10
    e_b        __icache_cfg

__icache_no_abort:
    and.    r10, r8, r9
    e_bne    __icache_inv

    mfspr    r5, 1011
    e_ori    r5, r5, 0x0001
    se_isync
    ;#msync
    mtspr    1011, r5
__icache_skip:
#endif



/*****close specific core dcache*************/

    mfspr       r9, 286             ;# Save coreid to r9
#ifdef CORE0_DCACHE_DISABLE
    e_cmp16i    r9, 0
    e_beq       __dcache_skip
#endif
#ifdef CORE1_DCACHE_DISABLE
    e_cmp16i    r9, 1
    e_beq       __dcache_skip
#endif
#ifdef CORE2_DCACHE_DISABLE
    e_cmp16i    r9, 2
    e_beq       __dcache_skip
#endif
#ifdef CORE3_DCACHE_DISABLE
    e_cmp16i    r9, 3
    e_beq       __dcache_skip
#endif
#ifdef CORE4_DCACHE_DISABLE
    e_cmp16i    r9, 4
    e_beq       __dcache_skip
#endif
#ifdef CORE5_DCACHE_DISABLE
    e_cmp16i    r9, 5
    e_beq       __dcache_skip
#endif



#if defined(CORE0_DCACHE_DISABLE)&&(CORE1_DCACHE_DISABLE)&&(CORE2_DCACHE_DISABLE)&&(CORE3_DCACHE_DISABLE)&&(CORE4_DCACHE_DISABLE)&&(CORE5_DCACHE_DISABLE)

#else
;#****************** Invalidate and Enable the Data cache **************
    #ifdef DCACHE_ENABLE
    #error do not define dache
    #endif

__dcache_cfg:
    e_lis    r7, 0x0000
    e_or2i    r7, 0x03FF        #create mask for lower 11 bits
    mfspr    r5, 515            #in lower 11 bits we have dcache size
    and.    r7, r7, r5        #check if we have dcache
    e_beq    __dcache_skip    #branch if not

    e_li r5, 0x2
    mtspr 1010,r5

    e_li r7, 0x4
    e_li r8, 0x2
    e_lis    r11,0xFFFF
    e_or2i    r11,0xFFFB

__dcache_inv:
    mfspr r9, 1010
    and.  r10, r7, r9
    e_beq   __dcache_no_abort
    and.  r10, r11, r9
    mtspr 1010, r10
    e_b __dcache_cfg

__dcache_no_abort:
    and.  r10, r8, r9
    e_bne __dcache_inv

    mfspr r5, 1010
    e_ori   r5, r5, 0x0001
    se_isync
    msync
    mtspr 1010, r5

__dcache_skip:
#endif

#ifdef DCACHE_ENABLE
;#****************** Invalidate and Enable the Data cache **************
__dcache_cfg:
    e_lis    r7, 0x0000
    e_or2i    r7, 0x03FF        #create mask for lower 11 bits
    mfspr    r5, 515            #in lower 11 bits we have dcache size
    and.    r7, r7, r5        #check if we have dcache
    e_beq    __dcache_skip    #branch if not

    e_li r5, 0x2
    mtspr 1010,r5

    e_li r7, 0x4
    e_li r8, 0x2
    e_lis    r11,0xFFFF
    e_or2i    r11,0xFFFB

__dcache_inv:
    mfspr r9, 1010
    and.  r10, r7, r9
    e_beq   __dcache_no_abort
    and.  r10, r11, r9
    mtspr 1010, r10
    e_b __dcache_cfg

__dcache_no_abort:
    and.  r10, r8, r9
    e_bne __dcache_inv

    mfspr r5, 1010
    e_ori   r5, r5, 0x0001
    se_isync
    msync
    mtspr 1010, r5

__dcache_skip:
#endif


#ifndef DATA_COPY_USE_DMA
;# if SMP, only the BOOT_CORE need to init blank section
#ifdef SMP_ONLY_ONE_ELF
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, CPU_FIRST_BOOT_CORE
    e_beq       _init_blank_section_start
    e_bne       _init_blank_section_end
#else
    e_b       _init_blank_section_start
#endif
_init_blank_section_start:
;# ****************************** Initialize MEASUREMENT_DATA_RAM section ******************************
;# Initialize MEASUREMENT DATA BSS section (zero initialization)
MEASUREMENTINIT:
    e_lis       r9, __MEA_DATA_SIZE@h        # Load upper BSW_BSS_ASILA size (# of bytes) into R9
    e_or2i      r9, __MEA_DATA_SIZE@l       # Load lower BSW_BSS_ASILA size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       MEASUREMENTINITEND               # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __MEA_DATA_RAM_ADDR@h   # Load upper BSW_BSS_ASILA address into R5
    e_or2i      r5, __MEA_DATA_RAM_ADDR@l   # Load lower BSW_BSS_ASILA address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

MEASUREMENTINITLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into BSS at R5 and update address
    e_bdnz      MEASUREMENTINITLOOP              # Branch if more bytes to clear

MEASUREMENTINITEND:
;# ****************************** Initialize BSW_BSS_ASILA section ******************************
;# Initialize BSW ASILA BSS section (zero initialization)
BSWBSSASILAINIT:
    e_lis       r9, __BSW_BSS_ASILA_SIZE@h        # Load upper BSW_BSS_ASILA size (# of bytes) into R9
    e_or2i      r9, __BSW_BSS_ASILA_SIZE@l       # Load lower BSW_BSS_ASILA size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       BSWBSSASILAINITEND               # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __BSW_BSS_ASILA_RAM_ADDR@h   # Load upper BSW_BSS_ASILA address into R5
    e_or2i      r5, __BSW_BSS_ASILA_RAM_ADDR@l   # Load lower BSW_BSS_ASILA address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

BSWBSSASILAINITLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into BSS at R5 and update address
    e_bdnz      BSWBSSASILAINITLOOP              # Branch if more bytes to clear

BSWBSSASILAINITEND:
;# ****************************** Initialize BSW_BSS_ASILB section ******************************
;# Initialize BSW ASILB BSS section (zero initialization)
BSWBSSASILBINIT:
    e_lis       r9, __BSW_BSS_ASILB_SIZE@h        # Load upper BSW_BSS_ASILB size (# of bytes) into R9
    e_or2i      r9, __BSW_BSS_ASILB_SIZE@l       # Load lower BSW_BSS_ASILB size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       BSWBSSASILBINITEND               # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __BSW_BSS_ASILB_RAM_ADDR@h   # Load upper BSW_BSS_ASILB address into R5
    e_or2i      r5, __BSW_BSS_ASILB_RAM_ADDR@l   # Load lower BSW_BSS_ASILB address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

BSWBSSASILBINITLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into BSS at R5 and update address
    e_bdnz      BSWBSSASILBINITLOOP              # Branch if more bytes to clear

BSWBSSASILBINITEND:
;# ****************************** Initialize BSW_BSS_ASILC section ******************************
;# Initialize BSW ASILC BSS section (zero initialization)
BSWBSSASILCINIT:
    e_lis       r9, __BSW_BSS_ASILC_SIZE@h        # Load upper BSW_BSS_ASILC size (# of bytes) into R9
    e_or2i      r9, __BSW_BSS_ASILC_SIZE@l       # Load lower BSW_BSS_ASILC size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       BSWBSSASILCINITEND               # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __BSW_BSS_ASILC_RAM_ADDR@h   # Load upper BSW_BSS_ASILC address into R5
    e_or2i      r5, __BSW_BSS_ASILC_RAM_ADDR@l   # Load lower BSW_BSS_ASILC address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

BSWBSSASILCINITLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into BSS at R5 and update address
    e_bdnz      BSWBSSASILCINITLOOP              # Branch if more bytes to clear

BSWBSSASILCINITEND:
;# ****************************** Initialize BSW_BSS_GLOBAL section ******************************
;# Initialize BSW GLOBAL BSS section (zero initialization)
BSWBSSGLOBALINIT:
    e_lis       r9, __BSW_BSS_GLOBAL_SIZE@h      # Load upper BSW_BSS_GLOBAL size (# of bytes) into R9
    e_or2i      r9, __BSW_BSS_GLOBAL_SIZE@l     # Load lower BSW_BSS_GLOBAL size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       BSWBSSGLOBALINITEND              # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __BSW_BSS_GLOBAL_RAM_ADDR@h  # Load upper BSW_BSS_GLOBAL address into R5
    e_or2i      r5, __BSW_BSS_GLOBAL_RAM_ADDR@l  # Load lower BSW_BSS_GLOBAL address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

BSWBSSGLOBALINITLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into BSS at R5 and update address
    e_bdnz      BSWBSSGLOBALINITLOOP             # Branch if more bytes to clear

BSWBSSGLOBALINITEND:
;# ****************************** Initialize ASW_BSS_ASILA section ******************************
;# Initialize ASW ASILA BSS section (zero initialization)
ASWBSSASILAINIT:
    e_lis       r9, __ASW_BSS_ASILA_SIZE@h       # Load upper ASW_BSS_ASILA size (# of bytes) into R9
    e_or2i      r9, __ASW_BSS_ASILA_SIZE@l      # Load lower ASW_BSS_ASILA size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       ASWBSSASILAINITEND               # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __ASW_BSS_ASILA_RAM_ADDR@h  # Load upper ASW_BSS_ASILA address into R5
    e_or2i      r5, __ASW_BSS_ASILA_RAM_ADDR@l  # Load lower ASW_BSS_ASILA address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

ASWBSSASILAINITLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into BSS at R5 and update address
    e_bdnz      ASWBSSASILAINITLOOP              # Branch if more bytes to clear

ASWBSSASILAINITEND:
;# ****************************** Initialize ASW_BSS_ASILB section ******************************
;# Initialize ASW ASILB BSS section (zero initialization)
ASWBSSASILBINIT:
    e_lis       r9, __ASW_BSS_ASILB_SIZE@h       # Load upper ASW_BSS_ASILB size (# of bytes) into R9
    e_or2i      r9, __ASW_BSS_ASILB_SIZE@l      # Load lower ASW_BSS_ASILB size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       ASWBSSASILBINITEND               # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __ASW_BSS_ASILB_RAM_ADDR@h  # Load upper ASW_BSS_ASILB address into R5
    e_or2i      r5, __ASW_BSS_ASILB_RAM_ADDR@l  # Load lower ASW_BSS_ASILB address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

ASWBSSASILBINITLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into BSS at R5 and update address
    e_bdnz      ASWBSSASILBINITLOOP              # Branch if more bytes to clear

ASWBSSASILBINITEND:
;# ****************************** Initialize ASW_BSS_ASILC section ******************************
;# Initialize ASW ASILC BSS section (zero initialization)
ASWBSSASILCINIT:
    e_lis       r9, __ASW_BSS_ASILC_SIZE@h       # Load upper ASW_BSS_ASILC size (# of bytes) into R9
    e_or2i      r9, __ASW_BSS_ASILC_SIZE@l      # Load lower ASW_BSS_ASILC size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       ASWBSSASILCINITEND               # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __ASW_BSS_ASILC_RAM_ADDR@h  # Load upper ASW_BSS_ASILC address into R5
    e_or2i      r5, __ASW_BSS_ASILC_RAM_ADDR@l  # Load lower ASW_BSS_ASILC address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

ASWBSSASILCINITLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into BSS at R5 and update address
    e_bdnz      ASWBSSASILCINITLOOP              # Branch if more bytes to clear

ASWBSSASILCINITEND:
;# ****************************** Initialize ASW_BSS_GLOBAL section ******************************
;# Initialize ASW GLOBAL BSS section (zero initialization)
ASWBSSGLOBALINIT:
    e_lis       r9, __ASW_BSS_GLOBAL_SIZE@h     # Load upper ASW_BSS_GLOBAL size (# of bytes) into R9
    e_or2i      r9, __ASW_BSS_GLOBAL_SIZE@l    # Load lower ASW_BSS_GLOBAL size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       ASWBSSGLOBALINITEND              # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __ASW_BSS_GLOBAL_RAM_ADDR@h # Load upper ASW_BSS_GLOBAL address into R5
    e_or2i      r5, __ASW_BSS_GLOBAL_RAM_ADDR@l # Load lower ASW_BSS_GLOBAL address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

ASWBSSGLOBALINITLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into BSS at R5 and update address
    e_bdnz      ASWBSSGLOBALINITLOOP             # Branch if more bytes to clear

ASWBSSGLOBALINITEND:
;# ****************************** Initialize ASW_BSS_QM section ******************************
;# Initialize ASW QM BSS section (zero initialization)
ASWBSSQMINIT:
    e_lis       r9, __ASW_BSS_QM_SIZE@h     # Load upper ASW_BSS_QM size (# of bytes) into R9
    e_or2i      r9, __ASW_BSS_QM_SIZE@l    # Load lower ASW_BSS_QM size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       ASWBSSQMINITEND              # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __ASW_BSS_QM_RAM_ADDR@h # Load upper ASW_BSS_QM address into R5
    e_or2i      r5, __ASW_BSS_QM_RAM_ADDR@l # Load lower ASW_BSS_QM address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

ASWBSSQMINITLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into BSS at R5 and update address
    e_bdnz      ASWBSSQMINITLOOP             # Branch if more bytes to clear

ASWBSSQMINITEND:
;# ****************************** Initialize BSS_SHARE section ******************************
;# Initialize BSS_SHARE section (zero initialization)
BSSSHAREINIT:
    e_lis       r9, __BSS_SHARE_SIZE@h          # Load upper BSS_SHARE size (# of bytes) into R9
    e_or2i      r9, __BSS_SHARE_SIZE@l         # Load lower BSS_SHARE size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       BSSSHAREINITEND                  # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __BSS_SHARE_RAM_ADDR@h      # Load upper BSS_SHARE address into R5
    e_or2i      r5, __BSS_SHARE_RAM_ADDR@l     # Load lower BSS_SHARE address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

BSSSHAREINITLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into BSS at R5 and update address
    e_bdnz      BSSSHAREINITLOOP                 # Branch if more bytes to clear

BSSSHAREINITEND:
;# ****************************** Initialize BSS section ******************************
;# Initialize BSS section (zero initialization)
BSSINIT:
    e_lis       r9, __BSS_SIZE@h          # Load upper BSS size (# of bytes) into R9
    e_or2i      r9, __BSS_SIZE@l         # Load lower BSS size into R9
    e_cmp16i    r9,0                     # Compare to see if equal to 0
    e_beq       BSSINITEND               # Exit if size is zero (no data to initialize)

    mtctr       r9                       # Store no. of bytes to be cleared in counter

    e_lis       r5, __BSS_RAM_ADDR@h     # Load upper BSS address into R5
    e_or2i      r5, __BSS_RAM_ADDR@l     # Load lower BSS address into R5
    e_subi      r5, r5, 1                # Decrement address to prepare for loop

    e_lis       r4, 0x0                  # Load zero value into R4

BSSINITLOOP:
    e_stbu      r4, 1(r5)                # Store zero byte into BSS at R5 and update address
    e_bdnz      BSSINITLOOP              # Branch if more bytes to clear

BSSINITEND:
;# ****************************** Initialize BSS_OS section ******************************
;# Initialize BSS_OS section (zero initialization)
BSSOSINIT:
    e_lis       r9, __BSS_OS_SIZE@h              # Load upper BSS_OS size (# of bytes) into R9
    e_or2i      r9, __BSS_OS_SIZE@l             # Load lower BSS_OS size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       BSSOSINITEND                     # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __BSS_OS_RAM_ADDR@h         # Load upper BSS_OS address into R5
    e_or2i      r5, __BSS_OS_RAM_ADDR@l        # Load lower BSS_OS address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

BSSOSINITLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into BSS at R5 and update address
    e_bdnz      BSSOSINITLOOP                    # Branch if more bytes to clear

BSSOSINITEND:
;# ****************************** Initialize SBSS2 section ******************************
;# Initialize SBSS2 section (zero initialization)
SBSS2INIT:
    e_lis       r9, __SBSS2_SIZE@h          # Load upper BSS size (# of bytes) into R9
    e_or2i      r9, __SBSS2_SIZE@l         # Load lower BSS size into R9
    e_cmp16i    r9,0                     # Compare to see if equal to 0
    e_beq       SBSS2INITEND               # Exit if size is zero (no data to initialize)

    mtctr       r9                       # Store no. of bytes to be cleared in counter

    e_lis       r5, __SBSS2_RAM_ADDR@h     # Load upper BSS address into R5
    e_or2i      r5, __SBSS2_RAM_ADDR@l     # Load lower BSS address into R5
    e_subi      r5, r5, 1                # Decrement address to prepare for loop

    e_lis       r4, 0x0                  # Load zero value into R4

SBSS2INITLOOP:
    e_stbu      r4, 1(r5)                # Store zero byte into BSS at R5 and update address
    e_bdnz      SBSS2INITLOOP              # Branch if more bytes to clear

SBSS2INITEND:
;# ****************************** Initialize EE_BLOCK section ******************************
;# Initialize EEPROM emulation block (zero initialization)
EEBLOCKINIT:
    e_lis       r9, __EE_BLOCK_SIZE@h            # Load upper EE_BLOCK size (# of bytes) into R9
    e_or2i      r9, __EE_BLOCK_SIZE@l           # Load lower EE_BLOCK size into R9
    e_cmp16i    r9,0                             # Compare to see if equal to 0
    e_beq       EEBLOCKINITEND                   # Exit if size is zero (no data to initialize)

    mtctr       r9                               # Store no. of bytes to be cleared in counter

    e_lis       r5, __EE_BLOCK_RAM_ADDR@h        # Load upper EE_BLOCK address into R5
    e_or2i      r5, __EE_BLOCK_RAM_ADDR@l       # Load lower EE_BLOCK address into R5
    e_subi      r5, r5, 1                        # Decrement address to prepare for loop

    e_lis       r4, 0x0                          # Load zero value into R4

EEBLOCKINITLOOP:
    e_stbu      r4, 1(r5)                        # Store zero byte into EE_BLOCK at R5 and update address
    e_bdnz      EEBLOCKINITLOOP                  # Branch if more bytes to clear

EEBLOCKINITEND:
_init_blank_section_end:
#endif  /* ifdef DATA_COPY_USE_DMA */


;#****************************** Configure Stack ******************************/
#ifdef SMP_ONLY_ONE_ELF
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, 0
    e_beq       _set_sp_init_0
    e_cmp16i    r9, 1
    e_beq       _set_sp_init_1
    e_cmp16i    r9, 2
    e_beq       _set_sp_init_2
    e_cmp16i    r9, 3
    e_beq       _set_sp_init_3
    e_cmp16i    r9, 4
    e_beq       _set_sp_init_4
    e_cmp16i    r9, 5
    e_beq       _set_sp_init_5
    ;#
_set_sp_init_0:
    e_lis    r1, __SP_ENTRY_0@h    ;# Initialize stack pointer r1 to
    e_or2i    r1, __SP_ENTRY_0@l    ;# value in linker command file.
    e_b     _set_sp_init_end

_set_sp_init_1:
    e_lis    r1, __SP_ENTRY_1@h    ;# Initialize stack pointer r1 to
    e_or2i    r1, __SP_ENTRY_1@l    ;# value in linker command file.
    e_b     _set_sp_init_end

_set_sp_init_2:
    e_lis    r1, __SP_ENTRY_2@h    ;# Initialize stack pointer r1 to
    e_or2i    r1, __SP_ENTRY_2@l    ;# value in linker command file.
    e_b     _set_sp_init_end

_set_sp_init_3:
    e_lis    r1, __SP_ENTRY_3@h    ;# Initialize stack pointer r1 to
    e_or2i    r1, __SP_ENTRY_3@l    ;# value in linker command file.
    e_b     _set_sp_init_end

_set_sp_init_4:
    e_lis    r1, __SP_ENTRY_4@h    ;# Initialize stack pointer r1 to
    e_or2i    r1, __SP_ENTRY_4@l    ;# value in linker command file.
    e_b     _set_sp_init_end

_set_sp_init_5:
    e_lis    r1, __SP_ENTRY_5@h    ;# Initialize stack pointer r1 to
    e_or2i    r1, __SP_ENTRY_5@l    ;# value in linker command file.
    e_b     _set_sp_init_end

_set_sp_init_end:
#else
    e_lis    r1, __SP_INIT@h    ;# Initialize stack pointer r1 to
    e_or2i    r1, __SP_INIT@l    ;# value in linker command file.
#endif
    e_stwu    r0,-64(r1)            ;# Terminate stack.

#ifndef __HIGHTEC__
    e_lis    r13, _SDA_BASE_@h    ;# Initialize r13 to sdata base
    e_or2i    r13, _SDA_BASE_@l    ;# (provided by linker).

    e_lis    r2, _SDA2_BASE_@h    ;# Initialize r2 to sdata2 base
    e_or2i    r2, _SDA2_BASE_@l    ;# (provided by linker).
#endif
#ifdef DATA_COPY_USE_DMA
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, 0
    e_bne		DMA_COPY_END
;# Jump to data_copy function
    e_bl    default_copy_sec_init
;# Jump to data_clear function
    e_bl    default_clear_sec_init
DMA_COPY_END:
#endif /* DATA_COPY_USE_DMA */
;#*************************** Enable ME Bit in MSR *****************************
    mfmsr    r6
    e_or2i   r6,0x1000
    mtmsr    r6

#ifdef __DCC__ /* Diab */
    e_bl    __init_main
#endif

;##ifdef MCORE_INIT     
;#;# launch slave cores
;#    e_bl    Mcore_Init
;##endif

#ifdef SAFETY_ENABLE
;# Jump to SAF_FLASH_CopyCodeRam
e_bl	SAF_FLASH_CopyCodeRam
#endif

e_lis     r4, 0XAAAA
e_or2i    r4, 0xAAAA
mtdcr     498, r4
se_isync

;# Jump to Main
    e_bl    main

#endif  /* CCFC3011PT */

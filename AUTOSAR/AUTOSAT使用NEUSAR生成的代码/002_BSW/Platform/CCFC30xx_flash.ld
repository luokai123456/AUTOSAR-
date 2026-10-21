/*** create info ***************************************************************
*@ File name: CCFC30xx_flash.ld
*@ Author : liufengyuan 
*@ date :2025-12-25
*@ Description : link文件
**** modify info ***************************************************************
*@ version :0.0
*@ Modifier : liufengyuan 
*@ date :2025-12-25
*@ Modification Description : 初始版本,与 20251225的TCU3.0 当前内存分布_V0.1.xlsx 一致
*@ version :0.1
*@ Modifier : liufengyuan 
*@ date :2026-01-06
*@ Modification Description : 删除无用的 m_data section 按照 A016102_TCU3000_附件_MemoryMap_V2.2.xls 分配
*@ version :0.2
*@ Modifier : liufengyuan 
*@ date :2026-02-03
*@ Modification Description : 按照 A016102_TCU3000_附件_MemoryMap_V2.6.xls 分配
                            大改 增加功能安全的块 分配 按照新的EE的块分配
*@ version :0.3
*@ Modifier : liufengyuan 
*@ date :2026-02-05
*@ Modification Description : 按照 A016102_TCU3000_附件_MemoryMap_V2.6.xls 分配
                                适配的main.c    需要 V0.1 及以上
                                适配的start.S   需要 V0.3 及以上
                                适配的memory.h  需要 V0.3 及以上
                              1、增加对齐
                              2、sbss2 段 不在映射到flash
                              3、增加 algorith_ram段
                              4、resetkeep段改名为reset_keep
                              5、修改resetkeep的大小 的值为 CPU_RESET_KEEP_SIZE
*@ version :0.4
*@ Modifier : liufengyuan 
*@ date :2026-02-06
*@ Modification Description : 按照 A016102_TCU3000_附件_MemoryMap_V2.6.xls 分配
                                适配的main.c    需要 V0.1 及以上
                                适配的start.S   需要 V0.3 及以上
                                适配的memory.h  需要 V0.3 及以上
                              1、修改ee_Block8的起始地址，让他4字节对齐，不然开优化后强制让section4字节对齐，导致mem块的地址对不上报错
*@ version :0.5
*@ Modifier : liufengyuan 
*@ date :2026-03-09
*@ Modification Description : 按照 A016102_TCU3000_附件_MemoryMap_V2.6.xls 分配
                                适配的main.c    需要 V0.1 及以上
                                适配的start.S   需要 V0.3 及以上
                                适配的memory.h  需要 V0.3 及以上
                              1、修改 bss_os(160k 左右)放到 asw_bsw0_ram 之前打开 safetylib_enable 后 asw_bsw0_ram 超 1k 左右
*@ version :0.6
*@ Modifier : liufengyuan 
*@ date :2026-04-13
*@ Modification Description : 按照 A016102_TCU3000_附件_MemoryMap_V2.6.xls 分配
                                适配的main.c    需要 V0.2 及以上
                                适配的start.S   需要 V0.5 及以上
                                适配的memory.h  需要 V0.4 及以上
                              1、修改 bsw safety data 放到 asw_bsw1_ram 并在结束段增加align(4)对齐 并增加QM段用于start.S初始化的标识
                              2、在 asw safety data 中添加 qm 段和 blank5 段的定义 并在结束段增加align(4)对齐 并增加QM段用于start.S初始化的标识
                              3、在 asw safety flash 中添加 qm 段和 blank5 段的定义
                              4、按照 Nvm 的需求更新 用于内存保护 的定义
                              5、start.S使用的6个标定段的大小固定为总大小 不在是实际使用的大小 
                                原因是标定段ECC初始化后非全0数据 按照实际使用大小拷贝的话 XCP校验不过 PS：生成的soucehex也要将空白段补充未全FF
*@ version :0.7
*@ Modifier : liufengyuan 
*@ date :2026-05-14
*@ Modification Description : 修改内存分配信息,按照 A020102_JILI_XCU_MemoryMap_V0.2.xls 分配
                            1、增加 cpu4_local_imem cpu4_local_dmem cpu5_local_imem cpu5_local_dmem 块，将stack_4 stack_5 放到cpu4/5_local_dmem 块中
*@ version :0.8
*@ Modifier : huangbaoxing 
*@ date :2026-06-08
*@ Modification Description : 修改内存分配信息,按照 A020102_JILI_XCU_MemoryMap_V0.3.xls 分配
                            1、增加 cal_data_flash，删除cal0、1、2、3、4、5_data_flash，取消asw_bsw0_ram
                            2、新增mea_data_ram
                            3、将VX1000_Fixed固定在asw_bsw3_ram
                            4、将bss_share、data_share分配在asw_bsw1_ram
                            5、将.bss分配在asw_bsw1_ram
                            6、将.bss_os分配在asw_bsw2_ram
********************************************************************************/

CONSTANTS
{
#include "memory_smp.h"
}

DEFAULTS{

/* define stack size */
STACK_SIZE = CPU_CORE_X_STACK_SIZE;



CACHE_SRAM_SIZE          = CACHE_TEST_SRAM_SIZE;
CACHE_SRAM_BASE_ADDR     = CACHE_TEST_SRAM_BASE_ADDR;

ROM_COPY_SRAM_SIZE       = CODE_COPY_SRAM_SIZE;
ROM_COPY_SRAM_BASE_ADDR  = CODE_COPY_SRAM_BASE_ADDR;


/* define safety blank size */
BLANK_SIZE = 128;




EEPROM_BLOCK2_RAM_SIZE = 20;           /* Block 2 - 20 bytes */
EEPROM_BLOCK3_RAM_SIZE = 100;          /* Block 3 - 100 bytes */
EEPROM_BLOCK4_RAM_SIZE = 40;           /* Block 4 - 40 bytes */
EEPROM_BLOCK5_RAM_SIZE = 100;          /* Block 5 - 100 bytes */
EEPROM_BLOCK6_RAM_SIZE = 4;            /* Block 6 - 4 bytes */
EEPROM_BLOCK7_RAM_SIZE = 6;            /* Block 7 - 6 bytes */    /* 不是4字节对齐。开优化要注意 */
EEPROM_BLOCK8_9_RAM_SIZE = 512;        /* Block 8-9 - 512 bytes */
EEPROM_BLOCK10_49_RAM_SIZE = 256;      /* Block 10-49 - 256 bytes */
EEPROM_BLOCK50_89_RAM_SIZE = 20;       /* Block 50-89 - 20 bytes */
EEPROM_BLOCK90_96_RAM_SIZE = 32;       /* Block 90-96 - 32 bytes */
EEPROM_BLOCK97_100_RAM_SIZE = 64;      /* Block 97-100 - 64 bytes */
EEPROM_BLOCK101_RAM_SIZE = 256;        /* Block 101 - 256 bytes */
EEPROM_BLOCK102_105_RAM_SIZE = 64;     /* Block 102-105 - 64 bytes */
EEPROM_BLOCK106_RAM_SIZE = 256;        /* Block 106 - 256 bytes */
EEPROM_BLOCK107_118_RAM_SIZE = 64;     /* Block 107-118 - 64 bytes */
EEPROM_BLOCK119_RAM_SIZE = 256;        /* Block 119 - 256 bytes */
EEPROM_BLOCK120_127_RAM_SIZE = 64;     /* Block 120-127 - 64 bytes */
EEPROM_BLOCK128_131_RAM_SIZE = 256;     /* Block 120-127 - 64 bytes */

/* Block 2 - 20 bytes */
EEPROM_BLOCK2_BASE_ADDR = CPU_DMEM3_EEPROM_RAM_BASE_ADDR;
EEPROM_BLOCK2_END_ADDR = EEPROM_BLOCK2_BASE_ADDR + EEPROM_BLOCK2_RAM_SIZE;
/* Block 3 - 100 bytes */
EEPROM_BLOCK3_BASE_ADDR = EEPROM_BLOCK2_END_ADDR;
EEPROM_BLOCK3_END_ADDR = EEPROM_BLOCK3_BASE_ADDR + EEPROM_BLOCK3_RAM_SIZE;
/* Block 4 - 40 bytes */
EEPROM_BLOCK4_BASE_ADDR = EEPROM_BLOCK3_END_ADDR;
EEPROM_BLOCK4_END_ADDR = EEPROM_BLOCK4_BASE_ADDR + EEPROM_BLOCK4_RAM_SIZE;
/* Block 5 - 100 bytes */
EEPROM_BLOCK5_BASE_ADDR = EEPROM_BLOCK4_END_ADDR;
EEPROM_BLOCK5_END_ADDR = EEPROM_BLOCK5_BASE_ADDR + EEPROM_BLOCK5_RAM_SIZE;
/* Block 6 - 4 bytes */
EEPROM_BLOCK6_BASE_ADDR = EEPROM_BLOCK5_END_ADDR;
EEPROM_BLOCK6_END_ADDR = EEPROM_BLOCK6_BASE_ADDR + EEPROM_BLOCK6_RAM_SIZE;
/* Block 7 - 6 bytes */
EEPROM_BLOCK7_BASE_ADDR = EEPROM_BLOCK6_END_ADDR;
EEPROM_BLOCK7_END_ADDR = EEPROM_BLOCK7_BASE_ADDR + EEPROM_BLOCK7_RAM_SIZE;
/* Block 8-9 - 512 bytes each */
EEPROM_BLOCK8_BASE_ADDR = EEPROM_BLOCK7_END_ADDR + 2;     /* 为了地址4字节对齐 */
EEPROM_BLOCK9_BASE_ADDR = EEPROM_BLOCK8_BASE_ADDR + EEPROM_BLOCK8_9_RAM_SIZE;
EEPROM_BLOCK8_9_END_ADDR = EEPROM_BLOCK9_BASE_ADDR + EEPROM_BLOCK8_9_RAM_SIZE;
/* Block 10-49 - 256 bytes each */
EEPROM_BLOCK10_BASE_ADDR = EEPROM_BLOCK8_9_END_ADDR;
EEPROM_BLOCK11_BASE_ADDR = EEPROM_BLOCK10_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK12_BASE_ADDR = EEPROM_BLOCK11_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK13_BASE_ADDR = EEPROM_BLOCK12_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK14_BASE_ADDR = EEPROM_BLOCK13_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK15_BASE_ADDR = EEPROM_BLOCK14_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK16_BASE_ADDR = EEPROM_BLOCK15_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK17_BASE_ADDR = EEPROM_BLOCK16_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK18_BASE_ADDR = EEPROM_BLOCK17_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK19_BASE_ADDR = EEPROM_BLOCK18_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK20_BASE_ADDR = EEPROM_BLOCK19_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK21_BASE_ADDR = EEPROM_BLOCK20_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK22_BASE_ADDR = EEPROM_BLOCK21_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK23_BASE_ADDR = EEPROM_BLOCK22_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK24_BASE_ADDR = EEPROM_BLOCK23_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK25_BASE_ADDR = EEPROM_BLOCK24_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK26_BASE_ADDR = EEPROM_BLOCK25_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK27_BASE_ADDR = EEPROM_BLOCK26_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK28_BASE_ADDR = EEPROM_BLOCK27_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK29_BASE_ADDR = EEPROM_BLOCK28_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK30_BASE_ADDR = EEPROM_BLOCK29_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK31_BASE_ADDR = EEPROM_BLOCK30_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK32_BASE_ADDR = EEPROM_BLOCK31_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK33_BASE_ADDR = EEPROM_BLOCK32_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK34_BASE_ADDR = EEPROM_BLOCK33_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK35_BASE_ADDR = EEPROM_BLOCK34_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK36_BASE_ADDR = EEPROM_BLOCK35_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK37_BASE_ADDR = EEPROM_BLOCK36_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK38_BASE_ADDR = EEPROM_BLOCK37_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK39_BASE_ADDR = EEPROM_BLOCK38_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK40_BASE_ADDR = EEPROM_BLOCK39_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK41_BASE_ADDR = EEPROM_BLOCK40_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK42_BASE_ADDR = EEPROM_BLOCK41_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK43_BASE_ADDR = EEPROM_BLOCK42_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK44_BASE_ADDR = EEPROM_BLOCK43_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK45_BASE_ADDR = EEPROM_BLOCK44_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK46_BASE_ADDR = EEPROM_BLOCK45_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK47_BASE_ADDR = EEPROM_BLOCK46_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK48_BASE_ADDR = EEPROM_BLOCK47_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK49_BASE_ADDR = EEPROM_BLOCK48_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
EEPROM_BLOCK10_49_END_ADDR = EEPROM_BLOCK49_BASE_ADDR + EEPROM_BLOCK10_49_RAM_SIZE;
/* Block 50-89 - 20 bytes each */
EEPROM_BLOCK50_BASE_ADDR = EEPROM_BLOCK10_49_END_ADDR;
EEPROM_BLOCK51_BASE_ADDR = EEPROM_BLOCK50_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK52_BASE_ADDR = EEPROM_BLOCK51_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK53_BASE_ADDR = EEPROM_BLOCK52_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK54_BASE_ADDR = EEPROM_BLOCK53_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK55_BASE_ADDR = EEPROM_BLOCK54_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK56_BASE_ADDR = EEPROM_BLOCK55_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK57_BASE_ADDR = EEPROM_BLOCK56_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK58_BASE_ADDR = EEPROM_BLOCK57_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK59_BASE_ADDR = EEPROM_BLOCK58_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK60_BASE_ADDR = EEPROM_BLOCK59_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK61_BASE_ADDR = EEPROM_BLOCK60_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK62_BASE_ADDR = EEPROM_BLOCK61_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK63_BASE_ADDR = EEPROM_BLOCK62_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK64_BASE_ADDR = EEPROM_BLOCK63_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK65_BASE_ADDR = EEPROM_BLOCK64_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK66_BASE_ADDR = EEPROM_BLOCK65_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK67_BASE_ADDR = EEPROM_BLOCK66_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK68_BASE_ADDR = EEPROM_BLOCK67_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK69_BASE_ADDR = EEPROM_BLOCK68_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK70_BASE_ADDR = EEPROM_BLOCK69_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK71_BASE_ADDR = EEPROM_BLOCK70_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK72_BASE_ADDR = EEPROM_BLOCK71_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK73_BASE_ADDR = EEPROM_BLOCK72_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK74_BASE_ADDR = EEPROM_BLOCK73_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK75_BASE_ADDR = EEPROM_BLOCK74_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK76_BASE_ADDR = EEPROM_BLOCK75_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK77_BASE_ADDR = EEPROM_BLOCK76_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK78_BASE_ADDR = EEPROM_BLOCK77_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK79_BASE_ADDR = EEPROM_BLOCK78_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK80_BASE_ADDR = EEPROM_BLOCK79_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK81_BASE_ADDR = EEPROM_BLOCK80_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK82_BASE_ADDR = EEPROM_BLOCK81_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK83_BASE_ADDR = EEPROM_BLOCK82_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK84_BASE_ADDR = EEPROM_BLOCK83_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK85_BASE_ADDR = EEPROM_BLOCK84_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK86_BASE_ADDR = EEPROM_BLOCK85_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK87_BASE_ADDR = EEPROM_BLOCK86_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK88_BASE_ADDR = EEPROM_BLOCK87_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK89_BASE_ADDR = EEPROM_BLOCK88_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
EEPROM_BLOCK50_89_END_ADDR = EEPROM_BLOCK89_BASE_ADDR + EEPROM_BLOCK50_89_RAM_SIZE;
/* Block 90-96 - 32 bytes each */
EEPROM_BLOCK90_BASE_ADDR = EEPROM_BLOCK50_89_END_ADDR;
EEPROM_BLOCK91_BASE_ADDR = EEPROM_BLOCK90_BASE_ADDR + EEPROM_BLOCK90_96_RAM_SIZE;
EEPROM_BLOCK92_BASE_ADDR = EEPROM_BLOCK91_BASE_ADDR + EEPROM_BLOCK90_96_RAM_SIZE;
EEPROM_BLOCK93_BASE_ADDR = EEPROM_BLOCK92_BASE_ADDR + EEPROM_BLOCK90_96_RAM_SIZE;
EEPROM_BLOCK94_BASE_ADDR = EEPROM_BLOCK93_BASE_ADDR + EEPROM_BLOCK90_96_RAM_SIZE;
EEPROM_BLOCK95_BASE_ADDR = EEPROM_BLOCK94_BASE_ADDR + EEPROM_BLOCK90_96_RAM_SIZE;
EEPROM_BLOCK96_BASE_ADDR = EEPROM_BLOCK95_BASE_ADDR + EEPROM_BLOCK90_96_RAM_SIZE;
EEPROM_BLOCK90_96_END_ADDR = EEPROM_BLOCK96_BASE_ADDR + EEPROM_BLOCK90_96_RAM_SIZE;
/* Block 97-100 - 64 bytes each */
EEPROM_BLOCK97_BASE_ADDR = EEPROM_BLOCK90_96_END_ADDR;
EEPROM_BLOCK98_BASE_ADDR = EEPROM_BLOCK97_BASE_ADDR + EEPROM_BLOCK97_100_RAM_SIZE;
EEPROM_BLOCK99_BASE_ADDR = EEPROM_BLOCK98_BASE_ADDR + EEPROM_BLOCK97_100_RAM_SIZE;
EEPROM_BLOCK100_BASE_ADDR = EEPROM_BLOCK99_BASE_ADDR + EEPROM_BLOCK97_100_RAM_SIZE;
EEPROM_BLOCK97_100_END_ADDR = EEPROM_BLOCK100_BASE_ADDR + EEPROM_BLOCK97_100_RAM_SIZE;
/* Block 101 - 256 bytes */
EEPROM_BLOCK101_BASE_ADDR = EEPROM_BLOCK97_100_END_ADDR;
EEPROM_BLOCK101_END_ADDR = EEPROM_BLOCK101_BASE_ADDR + EEPROM_BLOCK101_RAM_SIZE;
/* Block 102-105 - 64 bytes each */
EEPROM_BLOCK102_BASE_ADDR = EEPROM_BLOCK101_END_ADDR;
EEPROM_BLOCK103_BASE_ADDR = EEPROM_BLOCK102_BASE_ADDR + EEPROM_BLOCK102_105_RAM_SIZE;
EEPROM_BLOCK104_BASE_ADDR = EEPROM_BLOCK103_BASE_ADDR + EEPROM_BLOCK102_105_RAM_SIZE;
EEPROM_BLOCK105_BASE_ADDR = EEPROM_BLOCK104_BASE_ADDR + EEPROM_BLOCK102_105_RAM_SIZE;
EEPROM_BLOCK102_105_END_ADDR = EEPROM_BLOCK105_BASE_ADDR + EEPROM_BLOCK102_105_RAM_SIZE;
/* Block 106 - 256 bytes */
EEPROM_BLOCK106_BASE_ADDR = EEPROM_BLOCK102_105_END_ADDR;
EEPROM_BLOCK106_END_ADDR = EEPROM_BLOCK106_BASE_ADDR + EEPROM_BLOCK106_RAM_SIZE;
/* Block 107-118 - 64 bytes each */
EEPROM_BLOCK107_BASE_ADDR = EEPROM_BLOCK106_END_ADDR;
EEPROM_BLOCK108_BASE_ADDR = EEPROM_BLOCK107_BASE_ADDR + EEPROM_BLOCK107_118_RAM_SIZE;
EEPROM_BLOCK109_BASE_ADDR = EEPROM_BLOCK108_BASE_ADDR + EEPROM_BLOCK107_118_RAM_SIZE;
EEPROM_BLOCK110_BASE_ADDR = EEPROM_BLOCK109_BASE_ADDR + EEPROM_BLOCK107_118_RAM_SIZE;
EEPROM_BLOCK111_BASE_ADDR = EEPROM_BLOCK110_BASE_ADDR + EEPROM_BLOCK107_118_RAM_SIZE;
EEPROM_BLOCK112_BASE_ADDR = EEPROM_BLOCK111_BASE_ADDR + EEPROM_BLOCK107_118_RAM_SIZE;
EEPROM_BLOCK113_BASE_ADDR = EEPROM_BLOCK112_BASE_ADDR + EEPROM_BLOCK107_118_RAM_SIZE;
EEPROM_BLOCK114_BASE_ADDR = EEPROM_BLOCK113_BASE_ADDR + EEPROM_BLOCK107_118_RAM_SIZE;
EEPROM_BLOCK115_BASE_ADDR = EEPROM_BLOCK114_BASE_ADDR + EEPROM_BLOCK107_118_RAM_SIZE;
EEPROM_BLOCK116_BASE_ADDR = EEPROM_BLOCK115_BASE_ADDR + EEPROM_BLOCK107_118_RAM_SIZE;
EEPROM_BLOCK117_BASE_ADDR = EEPROM_BLOCK116_BASE_ADDR + EEPROM_BLOCK107_118_RAM_SIZE;
EEPROM_BLOCK118_BASE_ADDR = EEPROM_BLOCK117_BASE_ADDR + EEPROM_BLOCK107_118_RAM_SIZE;
EEPROM_BLOCK107_118_END_ADDR = EEPROM_BLOCK118_BASE_ADDR + EEPROM_BLOCK107_118_RAM_SIZE;
/* Block 119 - 256 bytes */
EEPROM_BLOCK119_BASE_ADDR = EEPROM_BLOCK107_118_END_ADDR;
EEPROM_BLOCK119_END_ADDR = EEPROM_BLOCK119_BASE_ADDR + EEPROM_BLOCK119_RAM_SIZE;
/* Block 120-127 - 64 bytes each */
EEPROM_BLOCK120_BASE_ADDR = EEPROM_BLOCK119_END_ADDR;
EEPROM_BLOCK121_BASE_ADDR = EEPROM_BLOCK120_BASE_ADDR + EEPROM_BLOCK120_127_RAM_SIZE;
EEPROM_BLOCK122_BASE_ADDR = EEPROM_BLOCK121_BASE_ADDR + EEPROM_BLOCK120_127_RAM_SIZE;
EEPROM_BLOCK123_BASE_ADDR = EEPROM_BLOCK122_BASE_ADDR + EEPROM_BLOCK120_127_RAM_SIZE;
EEPROM_BLOCK124_BASE_ADDR = EEPROM_BLOCK123_BASE_ADDR + EEPROM_BLOCK120_127_RAM_SIZE;
EEPROM_BLOCK125_BASE_ADDR = EEPROM_BLOCK124_BASE_ADDR + EEPROM_BLOCK120_127_RAM_SIZE;
EEPROM_BLOCK126_BASE_ADDR = EEPROM_BLOCK125_BASE_ADDR + EEPROM_BLOCK120_127_RAM_SIZE;
EEPROM_BLOCK127_BASE_ADDR = EEPROM_BLOCK126_BASE_ADDR + EEPROM_BLOCK120_127_RAM_SIZE;
EEPROM_BLOCK120_127_END_ADDR = EEPROM_BLOCK127_BASE_ADDR + EEPROM_BLOCK120_127_RAM_SIZE;
/* Block 128-131 - 256 bytes each */
EEPROM_BLOCK128_BASE_ADDR = EEPROM_BLOCK120_127_END_ADDR
EEPROM_BLOCK129_BASE_ADDR = EEPROM_BLOCK128_BASE_ADDR + EEPROM_BLOCK128_131_RAM_SIZE;
EEPROM_BLOCK130_BASE_ADDR = EEPROM_BLOCK129_BASE_ADDR + EEPROM_BLOCK128_131_RAM_SIZE;
EEPROM_BLOCK131_BASE_ADDR = EEPROM_BLOCK130_BASE_ADDR + EEPROM_BLOCK128_131_RAM_SIZE;
EEPROM_BLOCK128_131_END_ADDR = EEPROM_BLOCK131_BASE_ADDR + EEPROM_BLOCK128_131_RAM_SIZE;
}

MEMORY
{
/*    boot_header : org = BOOT_RESET_VECTOR_BASE, len = BOOT_RESET_VECTOR_SIZE
    cpu0_reset_vector : org = CPU_CORE_0_RESET_VECTOR, len = BOOT_RESET_VECTOR_SIZE
    cpu0_reset_vector_addr : org = CPU_BSW_FLASH_BASE_ADDR, len = 0
    cpu1_reset_vector : org = CPU_CORE_1_RESET_VECTOR, len = BOOT_RESET_VECTOR_SIZE
    cpu1_reset_vector_addr : org = CPU_BSW_FLASH_BASE_ADDR, len = 0
    cpu2_reset_vector : org = CPU_CORE_2_RESET_VECTOR, len = BOOT_RESET_VECTOR_SIZE
    cpu2_reset_vector_addr : org = CPU_BSW_FLASH_BASE_ADDR, len = 0
    cpu3_reset_vector : org = CPU_CORE_3_RESET_VECTOR, len = BOOT_RESET_VECTOR_SIZE
    cpu3_reset_vector_addr : org = CPU_BSW_FLASH_BASE_ADDR, len = 0
    cpu4_reset_vector : org = CPU_CORE_4_RESET_VECTOR, len = BOOT_RESET_VECTOR_SIZE
    cpu4_reset_vector_addr : org = CPU_BSW_FLASH_BASE_ADDR, len = 0
    cpu5_reset_vector : org = CPU_CORE_5_RESET_VECTOR, len = BOOT_RESET_VECTOR_SIZE
    cpu5_reset_vector_addr : org = CPU_BSW_FLASH_BASE_ADDR, len = 0

    hsm_parsave_addr : org = HSM_SECBOOT_PARSAVE_ADDR, len = 4
    hsm_parstr_addr : org = HSM_SECBOOT_PARSTR_ADDR, len = 48
*/    
    bsw_flash : org = CPU_BSW_FLASH_BASE_ADDR, len = CPU_BSW_FLASH_SIZE
    asw_flash : org = CPU_ASW_FLASH_BASE_ADDR, len = CPU_ASW_FLASH_SIZE
    asw_safetyCode_flash : org = CPU_ASW_SAFETYCODE_FLASH_BASE_ADDR, len = CPU_ASW_SAFETYCODE_FLASH_SIZE
    safcode_useVar_flash : org = CPU_SAF_FLASH_BASE_ADDR, len = CPU_SAF_FLASH_SIZE
    cal_data_flash : org = CPU_CALIBRATION_FLASH_BASE_ADDR, len = CPU_CALIBRATION_FLASH_SIZE
    reserved_flash : org = CPU_RESERVED_FLASH_BASE_ADDR, len = CPU_RESERVED_FLASH_SIZE
    app_sign_flash : org = CPU_APP_SIGN_FLASH_BASE_ADDR, len = CPU_APP_SIGN_FLASH_SIZE
    3012_reserved_flash : org = CPU_3012_RESERVED_FLASH_BASE_ADDR, len = CPU_3012_RESERVED_FLASH_SIZE


    safcode_useVar_ram : org = CPU_SYSRAM_SAFETY_DATA_RESERVE_RAM_BASE_ADDR, len = CPU_SYSRAM_SAFETY_DATA_RESERVE_RAM_SIZE
    reserve0_ram : org = CPU_SYSRAM_RESERVE0_RAM_BASE_ADDR, len = CPU_SYSRAM_RESERVE0_RAM_SIZE
    cal_data_ram : org = CPU_SYSRAM_CALIBRATION_RAM_BASE_ADDR, len = CPU_SYSRAM_CALIBRATION_RAM_SIZE
    mea_data_ram : org = CPU_SYSRAM_MEASUREMENT_RAM_BASE_ADDR, len = CPU_SYSRAM_MEASUREMENT_RAM_SIZE
    reserve1_ram : org = CPU_IMEM0_RESERVE1_RAM_BASE_ADDR, len = CPU_IMEM0_RESERVE1_RAM_SIZE
    asw_bsw1_ram : org = CPU_DMEM0_ASW_BSW1_RAM_BASE_ADDR, len = CPU_DMEM0_ASW_BSW1_RAM_SIZE
    reserve2_ram : org = CPU_IMEM1_RESERVE2_RAM_BASE_ADDR, len = CPU_IMEM1_RESERVE2_RAM_SIZE
    asw_bsw2_ram : org = CPU_DMEM1_ASW_BSW2_RAM_BASE_ADDR, len = CPU_DMEM1_ASW_BSW2_RAM_SIZE
    reserve3_ram : org = CPU_IMEM2_RESERVE3_RAM_BASE_ADDR, len = CPU_IMEM2_RESERVE3_RAM_SIZE
    asw_bsw3_ram : org = CPU_DMEM2_ASW_BSW3_RAM_BASE_ADDR, len = CPU_DMEM2_ASW_BSW3_RAM_SIZE
    algorith_Ram : org = CPU_IMEM3_ALGORITHM_RAM_BASE_ADDR, len = CPU_IMEM3_ALGORITHM_RAM_SIZE   
    /* ee_used_ram : org = CPU_DMEM3_EEPROM_RAM_BASE_ADDR, len = CPU_DMEM3_EEPROM_RAM_SIZE */
    /* ee_reserve_ram : org = CPU_DMEM3_RESERVE_RAM_BASE_ADDR, len = CPU_DMEM3_RESERVE_RAM_SIZE */  /* todo:Ram分配 需要和NvM对应上 */
    asw_bsw4_ram : org = CPU_DMEM3_ASW_BSW4_RAM_BASE_ADDR, len = CPU_DMEM3_ASW_BSW4_RAM_SIZE
    resetkeep_ram : org = CPU_DMEM3_RESETKEEP_RAM_BASE_ADDR, len = CPU_DMEM3_RESETKEEP_RAM_SIZE
    cpu4_local_imem : org = CPU_CORE_4_ITCM_BASE_ADDR, len = CPU_CORE_4_ITCM_SIZE
    cpu4_local_dmem : org = CPU_CORE_4_DTCM_BASE_ADDR, len = CPU_CORE_4_DTCM_SIZE
    cpu5_local_imem : org = CPU_CORE_5_ITCM_BASE_ADDR, len = CPU_CORE_5_ITCM_SIZE
    cpu5_local_dmem : org = CPU_CORE_5_DTCM_BASE_ADDR, len = CPU_CORE_5_DTCM_SIZE

    eeBlock2_ram : org = EEPROM_BLOCK2_BASE_ADDR, len = EEPROM_BLOCK2_RAM_SIZE
    eeBlock3_ram : org = EEPROM_BLOCK3_BASE_ADDR, len = EEPROM_BLOCK3_RAM_SIZE
    eeBlock4_ram : org = EEPROM_BLOCK4_BASE_ADDR, len = EEPROM_BLOCK4_RAM_SIZE
    eeBlock5_ram : org = EEPROM_BLOCK5_BASE_ADDR, len = EEPROM_BLOCK5_RAM_SIZE
    eeBlock6_ram : org = EEPROM_BLOCK6_BASE_ADDR, len = EEPROM_BLOCK6_RAM_SIZE
    eeBlock7_ram : org = EEPROM_BLOCK7_BASE_ADDR, len = EEPROM_BLOCK7_RAM_SIZE
    eeBlock8_ram : org = EEPROM_BLOCK8_BASE_ADDR, len = EEPROM_BLOCK8_9_RAM_SIZE
    eeBlock9_ram : org = EEPROM_BLOCK9_BASE_ADDR, len = EEPROM_BLOCK8_9_RAM_SIZE
    eeBlock10_ram : org = EEPROM_BLOCK10_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock11_ram : org = EEPROM_BLOCK11_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock12_ram : org = EEPROM_BLOCK12_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock13_ram : org = EEPROM_BLOCK13_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock14_ram : org = EEPROM_BLOCK14_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock15_ram : org = EEPROM_BLOCK15_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock16_ram : org = EEPROM_BLOCK16_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock17_ram : org = EEPROM_BLOCK17_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock18_ram : org = EEPROM_BLOCK18_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock19_ram : org = EEPROM_BLOCK19_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock20_ram : org = EEPROM_BLOCK20_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock21_ram : org = EEPROM_BLOCK21_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock22_ram : org = EEPROM_BLOCK22_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock23_ram : org = EEPROM_BLOCK23_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock24_ram : org = EEPROM_BLOCK24_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock25_ram : org = EEPROM_BLOCK25_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock26_ram : org = EEPROM_BLOCK26_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock27_ram : org = EEPROM_BLOCK27_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock28_ram : org = EEPROM_BLOCK28_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock29_ram : org = EEPROM_BLOCK29_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock30_ram : org = EEPROM_BLOCK30_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock31_ram : org = EEPROM_BLOCK31_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock32_ram : org = EEPROM_BLOCK32_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock33_ram : org = EEPROM_BLOCK33_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock34_ram : org = EEPROM_BLOCK34_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock35_ram : org = EEPROM_BLOCK35_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock36_ram : org = EEPROM_BLOCK36_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock37_ram : org = EEPROM_BLOCK37_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock38_ram : org = EEPROM_BLOCK38_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock39_ram : org = EEPROM_BLOCK39_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock40_ram : org = EEPROM_BLOCK40_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock41_ram : org = EEPROM_BLOCK41_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock42_ram : org = EEPROM_BLOCK42_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock43_ram : org = EEPROM_BLOCK43_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock44_ram : org = EEPROM_BLOCK44_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock45_ram : org = EEPROM_BLOCK45_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock46_ram : org = EEPROM_BLOCK46_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock47_ram : org = EEPROM_BLOCK47_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock48_ram : org = EEPROM_BLOCK48_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock49_ram : org = EEPROM_BLOCK49_BASE_ADDR, len = EEPROM_BLOCK10_49_RAM_SIZE
    eeBlock50_ram : org = EEPROM_BLOCK50_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock51_ram : org = EEPROM_BLOCK51_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock52_ram : org = EEPROM_BLOCK52_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock53_ram : org = EEPROM_BLOCK53_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock54_ram : org = EEPROM_BLOCK54_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock55_ram : org = EEPROM_BLOCK55_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock56_ram : org = EEPROM_BLOCK56_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock57_ram : org = EEPROM_BLOCK57_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock58_ram : org = EEPROM_BLOCK58_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock59_ram : org = EEPROM_BLOCK59_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock60_ram : org = EEPROM_BLOCK60_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock61_ram : org = EEPROM_BLOCK61_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock62_ram : org = EEPROM_BLOCK62_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock63_ram : org = EEPROM_BLOCK63_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock64_ram : org = EEPROM_BLOCK64_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock65_ram : org = EEPROM_BLOCK65_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock66_ram : org = EEPROM_BLOCK66_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock67_ram : org = EEPROM_BLOCK67_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock68_ram : org = EEPROM_BLOCK68_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock69_ram : org = EEPROM_BLOCK69_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock70_ram : org = EEPROM_BLOCK70_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock71_ram : org = EEPROM_BLOCK71_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock72_ram : org = EEPROM_BLOCK72_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock73_ram : org = EEPROM_BLOCK73_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock74_ram : org = EEPROM_BLOCK74_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock75_ram : org = EEPROM_BLOCK75_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock76_ram : org = EEPROM_BLOCK76_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock77_ram : org = EEPROM_BLOCK77_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock78_ram : org = EEPROM_BLOCK78_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock79_ram : org = EEPROM_BLOCK79_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock80_ram : org = EEPROM_BLOCK80_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock81_ram : org = EEPROM_BLOCK81_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock82_ram : org = EEPROM_BLOCK82_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock83_ram : org = EEPROM_BLOCK83_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock84_ram : org = EEPROM_BLOCK84_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock85_ram : org = EEPROM_BLOCK85_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock86_ram : org = EEPROM_BLOCK86_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock87_ram : org = EEPROM_BLOCK87_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock88_ram : org = EEPROM_BLOCK88_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock89_ram : org = EEPROM_BLOCK89_BASE_ADDR, len = EEPROM_BLOCK50_89_RAM_SIZE
    eeBlock90_ram : org = EEPROM_BLOCK90_BASE_ADDR, len = EEPROM_BLOCK90_96_RAM_SIZE
    eeBlock91_ram : org = EEPROM_BLOCK91_BASE_ADDR, len = EEPROM_BLOCK90_96_RAM_SIZE
    eeBlock92_ram : org = EEPROM_BLOCK92_BASE_ADDR, len = EEPROM_BLOCK90_96_RAM_SIZE
    eeBlock93_ram : org = EEPROM_BLOCK93_BASE_ADDR, len = EEPROM_BLOCK90_96_RAM_SIZE
    eeBlock94_ram : org = EEPROM_BLOCK94_BASE_ADDR, len = EEPROM_BLOCK90_96_RAM_SIZE
    eeBlock95_ram : org = EEPROM_BLOCK95_BASE_ADDR, len = EEPROM_BLOCK90_96_RAM_SIZE
    eeBlock96_ram : org = EEPROM_BLOCK96_BASE_ADDR, len = EEPROM_BLOCK90_96_RAM_SIZE
    eeBlock97_ram : org = EEPROM_BLOCK97_BASE_ADDR, len = EEPROM_BLOCK97_100_RAM_SIZE
    eeBlock98_ram : org = EEPROM_BLOCK98_BASE_ADDR, len = EEPROM_BLOCK97_100_RAM_SIZE
    eeBlock99_ram : org = EEPROM_BLOCK99_BASE_ADDR, len = EEPROM_BLOCK97_100_RAM_SIZE
    eeBlock100_ram : org = EEPROM_BLOCK100_BASE_ADDR, len = EEPROM_BLOCK97_100_RAM_SIZE
    eeBlock101_ram : org = EEPROM_BLOCK101_BASE_ADDR, len = EEPROM_BLOCK101_RAM_SIZE
    eeBlock102_ram : org = EEPROM_BLOCK102_BASE_ADDR, len = EEPROM_BLOCK102_105_RAM_SIZE
    eeBlock103_ram : org = EEPROM_BLOCK103_BASE_ADDR, len = EEPROM_BLOCK102_105_RAM_SIZE
    eeBlock104_ram : org = EEPROM_BLOCK104_BASE_ADDR, len = EEPROM_BLOCK102_105_RAM_SIZE
    eeBlock105_ram : org = EEPROM_BLOCK105_BASE_ADDR, len = EEPROM_BLOCK102_105_RAM_SIZE
    eeBlock106_ram : org = EEPROM_BLOCK106_BASE_ADDR, len = EEPROM_BLOCK106_RAM_SIZE
    eeBlock107_ram : org = EEPROM_BLOCK107_BASE_ADDR, len = EEPROM_BLOCK107_118_RAM_SIZE
    eeBlock108_ram : org = EEPROM_BLOCK108_BASE_ADDR, len = EEPROM_BLOCK107_118_RAM_SIZE
    eeBlock109_ram : org = EEPROM_BLOCK109_BASE_ADDR, len = EEPROM_BLOCK107_118_RAM_SIZE
    eeBlock110_ram : org = EEPROM_BLOCK110_BASE_ADDR, len = EEPROM_BLOCK107_118_RAM_SIZE
    eeBlock111_ram : org = EEPROM_BLOCK111_BASE_ADDR, len = EEPROM_BLOCK107_118_RAM_SIZE
    eeBlock112_ram : org = EEPROM_BLOCK112_BASE_ADDR, len = EEPROM_BLOCK107_118_RAM_SIZE
    eeBlock113_ram : org = EEPROM_BLOCK113_BASE_ADDR, len = EEPROM_BLOCK107_118_RAM_SIZE
    eeBlock114_ram : org = EEPROM_BLOCK114_BASE_ADDR, len = EEPROM_BLOCK107_118_RAM_SIZE
    eeBlock115_ram : org = EEPROM_BLOCK115_BASE_ADDR, len = EEPROM_BLOCK107_118_RAM_SIZE
    eeBlock116_ram : org = EEPROM_BLOCK116_BASE_ADDR, len = EEPROM_BLOCK107_118_RAM_SIZE
    eeBlock117_ram : org = EEPROM_BLOCK117_BASE_ADDR, len = EEPROM_BLOCK107_118_RAM_SIZE
    eeBlock118_ram : org = EEPROM_BLOCK118_BASE_ADDR, len = EEPROM_BLOCK107_118_RAM_SIZE
    eeBlock119_ram : org = EEPROM_BLOCK119_BASE_ADDR, len = EEPROM_BLOCK119_RAM_SIZE
    eeBlock120_ram : org = EEPROM_BLOCK120_BASE_ADDR, len = EEPROM_BLOCK120_127_RAM_SIZE
    eeBlock121_ram : org = EEPROM_BLOCK121_BASE_ADDR, len = EEPROM_BLOCK120_127_RAM_SIZE
    eeBlock122_ram : org = EEPROM_BLOCK122_BASE_ADDR, len = EEPROM_BLOCK120_127_RAM_SIZE
    eeBlock123_ram : org = EEPROM_BLOCK123_BASE_ADDR, len = EEPROM_BLOCK120_127_RAM_SIZE
    eeBlock124_ram : org = EEPROM_BLOCK124_BASE_ADDR, len = EEPROM_BLOCK120_127_RAM_SIZE
    eeBlock125_ram : org = EEPROM_BLOCK125_BASE_ADDR, len = EEPROM_BLOCK120_127_RAM_SIZE
    eeBlock126_ram : org = EEPROM_BLOCK126_BASE_ADDR, len = EEPROM_BLOCK120_127_RAM_SIZE
    eeBlock127_ram : org = EEPROM_BLOCK127_BASE_ADDR, len = EEPROM_BLOCK120_127_RAM_SIZE
    eeBlock128_ram : org = EEPROM_BLOCK128_BASE_ADDR, len = EEPROM_BLOCK128_131_RAM_SIZE
    eeBlock129_ram : org = EEPROM_BLOCK129_BASE_ADDR, len = EEPROM_BLOCK128_131_RAM_SIZE
    eeBlock130_ram : org = EEPROM_BLOCK130_BASE_ADDR, len = EEPROM_BLOCK128_131_RAM_SIZE
    eeBlock131_ram : org = EEPROM_BLOCK131_BASE_ADDR, len = EEPROM_BLOCK128_131_RAM_SIZE
}


SECTIONS
{
/* 在应用层启动需要的，目前boot启动不需要这个 */
/*   .boot_header   : 
    {
        KEEP(*(.boot_header))
    } > boot_header
    .cpu0_reset_vector  : 
    {
        KEEP(*(.cpu0_reset_vector))
    } > cpu0_reset_vector
    
    .cpu0_reset_vector_addr  : 
    {
        __CPU_CORE_0_RESET_VECTOR_ADDR = . ;
    } > cpu0_reset_vector_addr

    .cpu1_reset_vector  : 
    {
        KEEP(*(.cpu1_reset_vector))
    } > cpu1_reset_vector

    .cpu1_reset_vector_addr  : 
    {
        __CPU_CORE_1_RESET_VECTOR_ADDR = . ;
    } > cpu1_reset_vector_addr

    .cpu2_reset_vector  : 
    {
        KEEP(*(.cpu2_reset_vector))
    } > cpu2_reset_vector

    .cpu2_reset_vector_addr  : 
    {
        __CPU_CORE_2_RESET_VECTOR_ADDR = . ;
    } > cpu2_reset_vector_addr

    .cpu3_reset_vector  : 
    {
        KEEP(*(.cpu3_reset_vector))
    } > cpu3_reset_vector

    .cpu3_reset_vector_addr  : 
    {
        __CPU_CORE_3_RESET_VECTOR_ADDR = . ;
    } > cpu3_reset_vector_addr

    .cpu4_reset_vector  : 
    {
        KEEP(*(.cpu4_reset_vector))
    } > cpu4_reset_vector

    .cpu4_reset_vector_addr  : 
    {
        __CPU_CORE_4_RESET_VECTOR_ADDR = . ;
    } > cpu4_reset_vector_addr

    .cpu5_reset_vector  : 
    {
        KEEP(*(.cpu5_reset_vector))
    } > cpu5_reset_vector

    .cpu5_reset_vector_addr  : 
    {
        __CPU_CORE_5_RESET_VECTOR_ADDR = . ;
    } > cpu5_reset_vector_addr

     .hsm_param_save_addr  : 
    {
        KEEP(*(.hsm_param_save_addr))
    } > hsm_parsave_addr
    
     .hsm_param_store_addr  : 
    {
        __HSM_PARAM_BASE_ADDR = .;
        KEEP(*(.hsm_param_store_addr))
    } > hsm_parstr_addr
*/
    .startup ALIGN(0x40) : 
    {
        *(.startup)
    } > bsw_flash
    
    .core_exceptions_table ALIGN(4096) : 
    {
      __IVPR_VALUE = . ;
      KEEP(*(.core_exceptions_table))
    } > bsw_flash

    .OS_EXCVEC_OSCORE                                         ALIGN(0x1000) : > bsw_flash
    .OS_IRQVEC_OSCORE                                         ALIGN(0x1000) : > bsw_flash

    ROM_OS_EXCVEC_OSCORE_START = ADDR(.OS_EXCVEC_OSCORE);
    ROM_OS_IRQVEC_OSCORE_START = ADDR(.OS_IRQVEC_OSCORE);
    
    /**********************************VX1000_FixedAddress*****************************/
    .VX1000_Fixed :  
    {
      KEEP(*(.VX1000_Fixed))
      "KEEP(*(.VX1000_Fixed))"
    } > asw_bsw3_ram
    /**********************************VX1000_FixedAddress*****************************/

    .intc_vector_table ALIGN(4096) : 
    {
      KEEP(*(.intc_vector_table))
    } > asw_bsw2_ram
    .ROM.intc_vector_table  ROM(.intc_vector_table ) : > bsw_flash 

    .safcode_useVar :
    {
        "KEEP(*(.safcode_useVar))"
        "KEEP(*(.safcode_useVar.*))"
        *(.saf_ram_data)
      . = ALIGN(4);
    } > safcode_useVar_ram
    .ROM.safcode_useVar  ROM(.safcode_useVar ) : > safcode_useVar_flash

    .cal_section :
    {
        "KEEP(*(.cal_section))"
        "KEEP(*(.cal_section.*))"
      . = ALIGN(4);
    } > cal_data_ram
    .ROM.cal_section  ROM(.cal_section ) : > cal_data_flash

    .XCP_CAL :
    {
        "KEEP(*(.XCP_CAL))"
        "KEEP(*(.XCP_CAL.*))"


      "*Diag.o(.rodata)"      
   
      "*PhaCurrDev.o(.rodata)"   
 
      /*"*IdqCtrl.o(.rodata)"*/   
  
      "*VoltModlnGen.o(.rodata)" 

      "*VoltModlnInp.o(.rodata)" 

      "*IdqDes.o(.rodata)"       
    
      /*"*EdrvStMac.o(.rodata)"*/    
  
      "*TempDev.o(.rodata)"      
    
      "*IdqAct.o(.rodata)"       
      
      /*"*HrmcInj.o(.rodata)" */  

      "*HvInvDev.o(.rodata)"    

      /*"*DynFrq.o(.rodata)"*/   

      /*"*BIfRx.o(.rodata)"*/             
          
      "*AngSwDecod.o(.rodata)"       

      "*AngOfstCal.o(.rodata)"          
        
      "*BIfTx.o(.rodata)"    
         
      "*BlfTx.o(.rodata)"

      "*AngEmDev.o(.rodata)"

      "*sort_ByVjd1nn.o(.rodata)"

      "*merge_xRqbf8II.o(.rodata)"

      "*look1_iflf_binlca.o(.rodata)"     

      "*GLOBAL_calibration.o(.rodata)" 
      /*"*TqDemCoorn.o(.rodata)"*/ 

      /*"*ComTx_CAN.o(.rodata)"*/   
 
      /*"*HvIntlck.o(.rodata)"*/     
  
      /*"*ExtTqDes.o(.rodata)"*/     
   
      /*"*EmPwr.o(.rodata)"*/        
     
      /*"*EmTq.o(.rodata)"*/         
       
      /*"*DernSys.o(.rodata)"*/            

      /*"*DernEm.o(.rodata)"*/             
         
      /*"*DernInv.o(.rodata)" */          
             
      /*"*ComRx_CAN.o(.rodata)"*/         
        
      /*"*DernCoorn.o(.rodata)"*/         
       
      /*"*AntiRollBack.o(.rodata)"*/         
         
      /*"*Dchrg.o(.rodata)"*/                         
             
      /*"*ActvDampg.o(.rodata)"*/           
                
      . = ALIGN(4);
    } > cal_data_ram
    .ROM.XCP_CAL  ROM(.XCP_CAL ) : > cal_data_flash

    .XCP_OBS :
    {
        "KEEP(*(.XCP_OBS))"
        "KEEP(*(.XCP_OBS.*))"
      . = ALIGN(4);
    } > mea_data_ram
     .ROM.XCP_OBS  ROM(.XCP_OBS ) : > bsw_flash

    .mea_blank (NOLOAD) ALIGN(4) :
    {
        . += 8;
    } > mea_data_ram

    .text : 
    {
      "*(.text.startup)"
      "*(.*text)"      
      "*(.text.*)"
      KEEP (*(.init))
      KEEP (*(.fini))  
      *(.OS_CODE)        
      . = ALIGN(16);
    } > bsw_flash
     
    .shellCommand :
    {
      _shell_command_start = .;
      *(.shellCommand)
      _shell_command_end = .;
    } > bsw_flash
  
#if 0
    .ctors :
    {
      __CTOR_LIST__ = .;
      /* gcc uses crtbegin.o to find the start of
         the constructors, so we make sure it is
         first.  Because this is a wildcard, it
         doesn't matter if the user does not
         actually link against crtbegin.o; the
         linker won't look for a file to match a
         wildcard.  The wildcard also means that it
         doesn't matter which directory crtbegin.o
         is in.  */
      KEEP (*crtbegin.o(.ctors))
      KEEP (*crtbegin?.o(.ctors))
      /* We don't want to include the .ctor section from
         from the crtend.o file until after the sorted ctors.
         The .ctor section from the crtend file contains the
         end of ctors marker and it must be last */
      KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors))
      KEEP (*(SORT(.ctors.*)))
      KEEP (*(.ctors))
      __CTOR_END__ = .;
    } > bsw_flash

    .dtors :
    {
      __DTOR_LIST__ = .;
      KEEP (*crtbegin.o(.dtors))
      KEEP (*crtbegin?.o(.dtors))
      KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors))
      KEEP (*(SORT(.dtors.*)))
      KEEP (*(.dtors))
      __DTOR_END__ = .;
    } > bsw_flash
    .preinit_array :
    {
      PROVIDE_HIDDEN (__preinit_array_start = .);
      KEEP (*(.preinit_array*))
      PROVIDE_HIDDEN (__preinit_array_end = .);
    } > bsw_flash

    .init_array :
    {
      PROVIDE_HIDDEN (__init_array_start = .);
      KEEP (*(SORT(.init_array.*)))
      KEEP (*(.init_array*))
      PROVIDE_HIDDEN (__init_array_end = .);
    } > bsw_flash

    .fini_array :
    {
      PROVIDE_HIDDEN (__fini_array_start = .);
      KEEP (*(SORT(.fini_array.*)))
      KEEP (*(.fini_array*))
      PROVIDE_HIDDEN (__fini_array_end = .);
    } > bsw_flash
#endif
    .rodata :
    {
      "*(.rodata)"
      "*(.rodata.*)"
      *(.OS_CONST)
    } > bsw_flash

    .eh_frame_hdr : { *(.eh_frame_hdr) } > bsw_flash
    .eh_frame     : { KEEP (*(.eh_frame)) } > bsw_flash    


    /* bsw safety data */
    .bsw_ram_blank0 :
    {
      . += BLANK_SIZE;
    } > asw_bsw1_ram
    /* SRAM ASIL A */
    .bsw_bss_safety_asila (NOLOAD) ALIGN(4) :
    {
      "*(.bsw_bss_safety_asila)"
      "*(.bsw_bss_safety_asila.*)"
      . = ALIGN(4);
    } > asw_bsw1_ram
    .bsw_data_safety_asila ALIGN(4) :
    {
      "*(.bsw_data_safety_asila)"
      "*(.bsw_data_safety_asila.*)"
      . = ALIGN(4);
    } > asw_bsw1_ram
    .ROM.bsw_data_safety_asila  ROM(.bsw_data_safety_asila) ALIGN(4) : > bsw_flash
    .bsw_ram_blank1 :
    {
      . += BLANK_SIZE;
    } > asw_bsw1_ram
    /* SRAM ASIL B */
    .bsw_bss_safety_asilb (NOLOAD) ALIGN(4) : 
    {
      "*(.bsw_bss_safety_asilb)"
      "*(.bsw_bss_safety_asilb.*)"
      . = ALIGN(4);
    } > asw_bsw1_ram
    .bsw_data_safety_asilb ALIGN(4) : 
    {
      "*(.bsw_data_safety_asilb)"
      "*(.bsw_data_safety_asilb.*)"
      . = ALIGN(4);
    } > asw_bsw1_ram
    .ROM.bsw_data_safety_asilb  ROM(.bsw_data_safety_asilb) ALIGN(4) : > bsw_flash
    .bsw_ram_blank2 :
    {
      . += BLANK_SIZE;
    } > asw_bsw1_ram
    /* SRAM ASIL C */
    .bsw_bss_safety_asilc (NOLOAD) ALIGN(4) : 
    {
      "*(.bsw_bss_safety_asilc)"
      "*(.bsw_bss_safety_asilc.*)"

      "*(.saf_bss)"
      "*(.saf_adc_bss)"
      "*(.saf_bist_bss)"
      "*(.saf_cache_bss)"
      "*(.saf_mcu_bss)"
      "*(.saf_cmu_bss)"
      "*(.saf_core_bss)"
      "*(.saf_crc_bss)"
      "*(.saf_cmpu_bss)"
      "*(.saf_dma_bss)"
      "*(.saf_fccu_bss)"
      "*(.saf_flash_bss)"
      "*(.saf_intc_bss)"
      "*(.saf_mem_bss)"
      "*(.saf_memu_bss)"
      "*(.saf_osc_bss)"
      "*(.saf_pit_bss)"
      "*(.saf_pll_bss)"
      "*(.saf_pmc_bss)"
      "*(.saf_ram_bss)"
      "*(.saf_regprot_bss)"
      "*(.saf_sch_bss)"
      "*(.saf_smpu_bss)"
      "*(.saf_stack_bss)"
      "*(.saf_stm_bss)"
      "*(.saf_swt_bss)"
      "*(.saf_tsens_bss)"
      . = ALIGN(4);
    } > cpu4_local_dmem
    .bsw_data_safety_asilc ALIGN(4) : 
    {
      "*(.bsw_data_safety_asilc)"
      "*(.bsw_data_safety_asilc.*)"

      "*(.saf_data)"
      "*(.saf_adc_data)"
      "*(.saf_bist_data)"
      "*(.saf_cache_data)"
      "*(.saf_mcu_data)"
      "*(.saf_cmu_data)"
      "*(.saf_core_data)"
      "*(.saf_crc_data)"
      "*(.saf_cmpu_data)"
      "*(.saf_dma_data)"
      "*(.saf_fccu_data)"
      "*(.saf_flash_data)"
      "*(.saf_intc_data)"
      "*(.saf_mem_data)"
      "*(.saf_memu_data)"
      "*(.saf_osc_data)"
      "*(.saf_pit_data)"
      "*(.saf_pll_data)"
      "*(.saf_pmc_data)"
      
      "*(.saf_regprot_data)"
      "*(.saf_sch_data)"
      "*(.saf_smpu_data)"
      "*(.saf_stack_data)"
      "*(.saf_stm_data)"
      "*(.saf_swt_data)"
      "*(.saf_tsens_data)"
      . = ALIGN(4);
    } > cpu4_local_dmem
    .ROM.bsw_data_safety_asilc  ROM(.bsw_data_safety_asilc) ALIGN(4) : > bsw_flash
    .bsw_ram_blank3 :
    {
      . += BLANK_SIZE;
    } > asw_bsw1_ram
    .bsw_bss_safety_global (NOLOAD) ALIGN(4) : 
    {
      "*(.bsw_bss_safety_global)"
      "*(.bsw_bss_safety_global.*)"
      . = ALIGN(4);
    } > asw_bsw1_ram
    .bsw_data_safety_global ALIGN(4) : 
    {
      "*(.bsw_data_safety_global)"
      "*(.bsw_data_safety_global.*)"
      . = ALIGN(4);
    } > asw_bsw1_ram
    .ROM.bsw_data_safety_global  ROM(.bsw_data_safety_global) ALIGN(4) : > bsw_flash
    .bsw_ram_blank4 :
    {
      . += BLANK_SIZE;
    } > asw_bsw1_ram
    /* bsw safety data end */
    /* asw safety data  */
    .asw_ram_blank0 :
    {
      . += BLANK_SIZE;
    } > asw_bsw2_ram
    .asw_bss_safety_asila (NOLOAD) ALIGN(4) :
    {
      "*(.asw_bss_safety_asila)"
      "*(.asw_bss_safety_asila.*)"
      . = ALIGN(4);
    } > asw_bsw2_ram
    .asw_data_safety_asila ALIGN(4) :
    {
      "*(.asw_data_safety_asila)"
      "*(.asw_data_safety_asila.*)"
      . = ALIGN(4);
    } > asw_bsw2_ram
    .ROM.asw_data_safety_asila  ROM(.asw_data_safety_asila) ALIGN(4) : > asw_flash
    .asw_ram_blank1 :
    {
      . += BLANK_SIZE;
    } > asw_bsw2_ram
    .asw_bss_safety_asilb (NOLOAD) ALIGN(4) : 
    {
      "*(.asw_bss_safety_asilb)"
      "*(.asw_bss_safety_asilb.*)"
      . = ALIGN(4);
    } > asw_bsw2_ram
    .asw_data_safety_asilb ALIGN(4) : 
    {
      "*(.asw_data_safety_asilb)"
      "*(.asw_data_safety_asilb.*)"
      . = ALIGN(4);
    } > asw_bsw2_ram
    .ROM.asw_data_safety_asilb  ROM(.asw_data_safety_asilb) ALIGN(4) : > asw_flash
    .asw_ram_blank2 :
    {
      . += BLANK_SIZE;
    } > asw_bsw2_ram
    .asw_bss_safety_asilc (NOLOAD) ALIGN(4) : 
    {
      "*(.asw_bss_safety_asilc)"
      "*(.asw_bss_safety_asilc.*)"
      . = ALIGN(4);
    } > asw_bsw2_ram
    .asw_data_safety_asilc ALIGN(4) : 
    {
      "*(.asw_data_safety_asilc)"
      "*(.asw_data_safety_asilc.*)"
      . = ALIGN(4);
    } > asw_bsw2_ram
    .ROM.asw_data_safety_asilc  ROM(.asw_data_safety_asilc) ALIGN(4) : > asw_flash
    .asw_ram_blank3 :
    {
      . += BLANK_SIZE;
    } > asw_bsw2_ram
    .asw_bss_safety_global (NOLOAD) ALIGN(4) : 
    {
      "*(.asw_bss_safety_global)"
      "*(.asw_bss_safety_global.*)"
      . = ALIGN(4);
    } > asw_bsw2_ram
    .asw_data_safety_global ALIGN(4) : 
    {
      "*(.asw_data_safety_global)"
      "*(.asw_data_safety_global.*)"
      . = ALIGN(4);
    } > asw_bsw2_ram
    .ROM.asw_data_safety_global  ROM(.asw_data_safety_global) ALIGN(4) : > asw_flash
    .asw_ram_blank4 :
    {
      . += BLANK_SIZE;
    } > asw_bsw2_ram
    .asw_bss_safety_qm (NOLOAD) ALIGN(4) : 
    {
      "*(.asw_bss_safety_qm)"
      "*(.asw_bss_safety_qm.*)"
      . = ALIGN(4);
    } > asw_bsw2_ram
    .asw_data_safety_qm ALIGN(4) : 
    {
      "*(.asw_data_safety_qm)"
      "*(.asw_data_safety_qm.*)"
      . = ALIGN(4);
    } > asw_bsw2_ram
    .ROM.asw_data_safety_qm  ROM(.asw_data_safety_qm) ALIGN(4) : > asw_flash
    .asw_ram_blank5 :
    {
      . += BLANK_SIZE;
    } > asw_bsw2_ram
    /* asw safety data end */


    .data : 
    {
      "*(.data)"
      "*(.data.*)"
      "*(.ramcode)"

      . = ALIGN(4);
      RAM_OS_INITVAR_OSCORE0_START = .;
      *(.OS_INITVAR_OSCORE0)
      RAM_OS_INITVAR_OSCORE0_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_OSCORE1_START = .;
      *(.OS_INITVAR_OSCORE1)
      RAM_OS_INITVAR_OSCORE1_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_OSCORE2_START = .;
      *(.OS_INITVAR_OSCORE2)
      RAM_OS_INITVAR_OSCORE2_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_OSCORE3_START = .;
      *(.OS_INITVAR_OSCORE3)
      RAM_OS_INITVAR_OSCORE3_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_OSCORE4_START = .;
      *(.OS_INITVAR_OSCORE4)
      RAM_OS_INITVAR_OSCORE4_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_OSCORE5_START = .;
      *(.OS_INITVAR_OSCORE5)
      RAM_OS_INITVAR_OSCORE5_END = .;

      . = ALIGN(4);
      RAM_OS_GLOBAL_NOCACHE_INITVAR_START = .;
      *(.OS_GLOBAL_NOCACHE_INITVAR)
      RAM_OS_GLOBAL_NOCACHE_INITVAR_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_APPLICATION_CORE0_QM_START = .;
      *(.OS_INITVAR_APP1_APPLICATION_CORE0_QM)
      RAM_OS_INITVAR_APP1_APPLICATION_CORE0_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_5MS_CORE0_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_5MS_CORE0_QM)
      RAM_OS_INITVAR_APP1_TASK_5MS_CORE0_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_10MS_CORE0_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_10MS_CORE0_QM)
      RAM_OS_INITVAR_APP1_TASK_10MS_CORE0_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_15MS_CORE0_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_15MS_CORE0_QM)
      RAM_OS_INITVAR_APP1_TASK_15MS_CORE0_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_20MS_CORE0_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_20MS_CORE0_QM)
      RAM_OS_INITVAR_APP1_TASK_20MS_CORE0_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_TIMER5MS_ISR_CAT2_CORE0_START = .;
      *(.OS_INITVAR_TIMER5MS_ISR_CAT2_CORE0)
      RAM_OS_INITVAR_TIMER5MS_ISR_CAT2_CORE0_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_APPLICATION_CORE1_QM_START = .;
      *(.OS_INITVAR_APP1_APPLICATION_CORE1_QM)
      RAM_OS_INITVAR_APP1_APPLICATION_CORE1_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_5MS_CORE1_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_5MS_CORE1_QM)
      RAM_OS_INITVAR_APP1_TASK_5MS_CORE1_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_10MS_CORE1_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_10MS_CORE1_QM)
      RAM_OS_INITVAR_APP1_TASK_10MS_CORE1_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_15MS_CORE1_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_15MS_CORE1_QM)
      RAM_OS_INITVAR_APP1_TASK_15MS_CORE1_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_20MS_CORE1_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_20MS_CORE1_QM)
      RAM_OS_INITVAR_APP1_TASK_20MS_CORE1_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_TIMER5MS_ISR_CAT2_CORE1_START = .;
      *(.OS_INITVAR_TIMER5MS_ISR_CAT2_CORE1)
      RAM_OS_INITVAR_TIMER5MS_ISR_CAT2_CORE1_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_APPLICATION_CORE2_QM_START = .;
      *(.OS_INITVAR_APP1_APPLICATION_CORE2_QM)
      RAM_OS_INITVAR_APP1_APPLICATION_CORE2_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_5MS_CORE2_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_5MS_CORE2_QM)
      RAM_OS_INITVAR_APP1_TASK_5MS_CORE2_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_10MS_CORE2_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_10MS_CORE2_QM)
      RAM_OS_INITVAR_APP1_TASK_10MS_CORE2_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_15MS_CORE2_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_15MS_CORE2_QM)
      RAM_OS_INITVAR_APP1_TASK_15MS_CORE2_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_20MS_CORE2_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_20MS_CORE2_QM)
      RAM_OS_INITVAR_APP1_TASK_20MS_CORE2_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_TIMER5MS_ISR_CAT2_CORE2_START = .;
      *(.OS_INITVAR_TIMER5MS_ISR_CAT2_CORE2)
      RAM_OS_INITVAR_TIMER5MS_ISR_CAT2_CORE2_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_APPLICATION_CORE3_QM_START = .;
      *(.OS_INITVAR_APP1_APPLICATION_CORE3_QM)
      RAM_OS_INITVAR_APP1_APPLICATION_CORE3_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_5MS_CORE3_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_5MS_CORE3_QM)
      RAM_OS_INITVAR_APP1_TASK_5MS_CORE3_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_10MS_CORE3_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_10MS_CORE3_QM)
      RAM_OS_INITVAR_APP1_TASK_10MS_CORE3_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_15MS_CORE3_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_15MS_CORE3_QM)
      RAM_OS_INITVAR_APP1_TASK_15MS_CORE3_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_APP1_TASK_20MS_CORE3_QM_START = .;
      *(.OS_INITVAR_APP1_TASK_20MS_CORE3_QM)
      RAM_OS_INITVAR_APP1_TASK_20MS_CORE3_QM_END = .;

      . = ALIGN(4);
      RAM_OS_INITVAR_TIMER5MS_ISR_CAT2_CORE3_START = .;
      *(.OS_INITVAR_TIMER5MS_ISR_CAT2_CORE3)
      RAM_OS_INITVAR_TIMER5MS_ISR_CAT2_CORE3_END = .;
      . = ALIGN(4);
    }  > asw_bsw2_ram
    .ROM.data  ROM(.data ) : > bsw_flash
    
    .bss_share (NOLOAD) ALIGN(0x10) : 
    {
	  __BSS_SHARE_START = .;
      "*(.bss_share)"
      "*(.saf_data_bss_share)"
       . = ALIGN(4);
      RAM_OS_GLOBAL_NOCACHE_VAR_START = .;
      "*(.OS_GLOBAL_NOCACHE_VAR)"
      RAM_OS_GLOBAL_NOCACHE_VAR_END = .;
      . = ALIGN(4);
	  __BSS_SHARE_END = .;
    }  > asw_bsw1_ram
    .data_share ALIGN(0x10) : 
    {
	  __DATA_SHARE_START = .;
      "*(.data_share)"
      "*(.saf_data_share)"
       . = ALIGN(4);
      RAM_OS_GLOBAL_NOCACHE_INITVAR_START = .;
      "*(.OS_GLOBAL_NOCACHE_INITVAR)"
      RAM_OS_GLOBAL_NOCACHE_INITVAR_END = .;
      . = ALIGN(4);
	  __DATA_SHARE_END = .;
    }  > asw_bsw1_ram
    .ROM.data_share  ROM(.data_share ) : > bsw_flash
    
    /* __CODE_ROM =  ROM_COPY_FLASH_BASE_ADDR ;
    .saf_ramcode : AT(__CODE_ROM)
    {
      . = ALIGN(4);
      __CODE_RAM = .;
      __code_start__ = .;
      __code_ram_start__ = .;
      *(.saf_ramcode)
      . = ALIGN(4);
      __code_end__ = .;
      __code_ram_end__ = .;
    } > saf_copy_data_ram
    __CODE_END = __CODE_ROM + (__code_end__ - __code_start__); */

    .sdata2 :
    {  
      "*(.sdata2)"
      "*(.sdata2.*)"
      . = ALIGN(4);
    } > asw_bsw2_ram
    .ROM.sdata2  ROM(.sdata2 ) : > bsw_flash

    .sbss2    (NOLOAD)   :
    {
      /* _SDA2_BASE_ = .; */ 
      "*(.sbss2)"
      "*(.sbss2.*)"
      . = ALIGN(4);
    } > asw_bsw2_ram
    
    .sdata  :
    {
      "*(.sdata)"
      "*(.sdata.*)"
      . = ALIGN(4);
    } > asw_bsw2_ram
    .ROM.sdata  ROM(.sdata ) : > bsw_flash
    


    .stack_0 (NOLOAD) ALIGN(16) :
    {
      SAF_STACK_MONITOR_BOTTOM_LIMIT_ADDR = .;
      SAF_STACK_BOTTOM_ADDR = .;
      . +=  STACK_SIZE ;
      __SP_ENTRY_0 = . ;
      __SP_INIT_0 = .;
      __SP_INIT = .;
      SAF_STACK_TOP_ADDR = .;
    } > asw_bsw1_ram

    .stack_1 (NOLOAD) ALIGN(16) :
    {
      . +=  STACK_SIZE ;
      __SP_ENTRY_1 = . ;
      __SP_INIT_1 = .;
    } > asw_bsw2_ram
    
    .stack_2 (NOLOAD) ALIGN(16) :
    {
      . +=  STACK_SIZE ;
      __SP_ENTRY_2 = . ;
      __SP_INIT_2 = .;
    } > asw_bsw3_ram

    .stack_3 (NOLOAD) ALIGN(16) :
    {
      . +=  STACK_SIZE ;
      __SP_ENTRY_3 = . ;
      __SP_INIT_3 = .;
    } > asw_bsw4_ram

    .stack_4 (NOLOAD) ALIGN(16) :
    {
      . +=  STACK_SIZE ;
      __SP_ENTRY_4 = . ;
      __SP_INIT_4 = .;
    } > cpu4_local_dmem

    .stack_5 (NOLOAD) ALIGN(16) :
    {
      . +=  STACK_SIZE ;
      __SP_ENTRY_5 = . ;
      __SP_INIT_5 = .;
    } > cpu5_local_dmem



    .bss   (NOLOAD)  :
    {
      "*(.sbss)"
      "*(.sbss.*)"    
      "*(.bss)"
      "*(.bss.*)"
      "*(COMMON)"
      . = ALIGN(4);
    } > asw_bsw1_ram

  .bss_os_core4   (NOLOAD)  :
    {
      . = ALIGN(4);
      *(.OS_STACK_OSCORE4)
      . = ALIGN(4);
      RAM_OS_VAR_OSCORE4_START = .;
      *(.OS_VAR_OSCORE4)
      RAM_OS_VAR_OSCORE4_END = .;
      . = ALIGN(4);
      RAM_OS_NOCACHE_VAR_OSCORE4_START = .;
      *(.OS_NOCACHE_VAR_OSCORE4)
      RAM_OS_NOCACHE_VAR_OSCORE4_END = .;

    } > cpu4_local_dmem  
    
    .bss_os   (NOLOAD)  :
    {
      . = ALIGN(4);
      RAM_OS_VAR_APP1_APPLICATION_CORE0_QM_START = .;
      "*(.OS_VAR_APP1_APPLICATION_CORE0_QM)"
      RAM_OS_VAR_APP1_APPLICATION_CORE0_QM_END = .;

      . = ALIGN(4);
      RAM_OS_VAR_APP1_TASK_5MS_CORE0_QM_START = .;
      "*(.OS_VAR_APP1_TASK_5MS_CORE0_QM)"
      RAM_OS_VAR_APP1_TASK_5MS_CORE0_QM_END = .;

      . = ALIGN(4);
      RAM_OS_VAR_APP1_TASK_10MS_CORE0_QM_START = .;
      "*(.OS_VAR_APP1_TASK_10MS_CORE0_QM)"
      RAM_OS_VAR_APP1_TASK_10MS_CORE0_QM_END = .;

      . = ALIGN(4);
      RAM_OS_VAR_APP1_TASK_15MS_CORE0_QM_START = .;
      "*(.OS_VAR_APP1_TASK_15MS_CORE0_QM)"
      RAM_OS_VAR_APP1_TASK_15MS_CORE0_QM_END = .;

      . = ALIGN(4);
      RAM_OS_VAR_APP1_TASK_20MS_CORE0_QM_START = .;
      "*(.OS_VAR_APP1_TASK_20MS_CORE0_QM)"
      "*(.OS_VAR_APP1_TASK_20MS_CORE0_QM_0.*)"
      RAM_OS_VAR_APP1_TASK_20MS_CORE0_QM_END = .;

      . = ALIGN(4);
      RAM_OS_VAR_APP1_APPLICATION_CORE1_QM_START = .;
      "*(.OS_VAR_APP1_APPLICATION_CORE1_QM)"
      RAM_OS_VAR_APP1_APPLICATION_CORE1_QM_END = .;

      . = ALIGN(4);
      RAM_OS_VAR_APP1_TASK_5MS_CORE1_QM_START = .;
      "*(.OS_VAR_APP1_TASK_5MS_CORE1_QM)"
      RAM_OS_VAR_APP1_TASK_5MS_CORE1_QM_END = .;

      . = ALIGN(4);
      RAM_OS_VAR_APP1_TASK_10MS_CORE1_QM_START = .;
      "*(.OS_VAR_APP1_TASK_10MS_CORE1_QM)"
      RAM_OS_VAR_APP1_TASK_10MS_CORE1_QM_END = .;

      . = ALIGN(4);
      RAM_OS_VAR_APP1_TASK_15MS_CORE1_QM_START = .;
      *(.OS_VAR_APP1_TASK_15MS_CORE1_QM)
      RAM_OS_VAR_APP1_TASK_15MS_CORE1_QM_END = .;

      . = ALIGN(4);
      RAM_OS_VAR_APP1_TASK_20MS_CORE1_QM_START = .;
      *(.OS_VAR_APP1_TASK_20MS_CORE1_QM)
      RAM_OS_VAR_APP1_TASK_20MS_CORE1_QM_END = .;

      . = ALIGN(4);
      RAM_OS_VAR_APP1_APPLICATION_CORE2_QM_START = .;
      *(.OS_VAR_APP1_APPLICATION_CORE2_QM)
      RAM_OS_VAR_APP1_APPLICATION_CORE2_QM_END = .;

      . = ALIGN(4);
      RAM_OS_VAR_APP1_TASK_5MS_CORE2_QM_START = .;
      *(.OS_VAR_APP1_TASK_5MS_CORE2_QM)
      RAM_OS_VAR_APP1_TASK_5MS_CORE2_QM_END = .;

      . = ALIGN(4);
      RAM_OS_VAR_APP1_TASK_10MS_CORE2_QM_START = .;
      *(.OS_VAR_APP1_TASK_10MS_CORE2_QM)
      RAM_OS_VAR_APP1_TASK_10MS_CORE2_QM_END = .;

      . = ALIGN(4);
      RAM_OS_VAR_APP1_TASK_15MS_CORE2_QM_START = .;
      *(.OS_VAR_APP1_TASK_15MS_CORE2_QM)
      RAM_OS_VAR_APP1_TASK_15MS_CORE2_QM_END = .;

      . = ALIGN(4);
      RAM_OS_VAR_APP1_TASK_20MS_CORE2_QM_START = .;
      *(.OS_VAR_APP1_TASK_20MS_CORE2_QM)
      RAM_OS_VAR_APP1_TASK_20MS_CORE2_QM_END = .;


      . = ALIGN(4);
      *(.OS_STACK_OSCORE0)
      . = ALIGN(4);
      RAM_OS_VAR_OSCORE0_START = .;
      *(.OS_VAR_OSCORE0)
      RAM_OS_VAR_OSCORE0_END = .;

      . = ALIGN(4);
      *(.OS_STACK_OSCORE1)
      . = ALIGN(4);
      RAM_OS_VAR_OSCORE1_START = .;
      *(.OS_VAR_OSCORE1)
      RAM_OS_VAR_OSCORE1_END = .;
      . = ALIGN(4);
      RAM_OS_NOCACHE_VAR_OSCORE1_START = .;
      *(.OS_NOCACHE_VAR_OSCORE1)
      RAM_OS_NOCACHE_VAR_OSCORE1_END = .;

      . = ALIGN(4);
      *(.OS_STACK_OSCORE2)
      . = ALIGN(4);
      RAM_OS_VAR_OSCORE2_START = .;
      *(.OS_VAR_OSCORE2)
      RAM_OS_VAR_OSCORE2_END = .;
      . = ALIGN(4);
      RAM_OS_NOCACHE_VAR_OSCORE2_START = .;
      *(.OS_NOCACHE_VAR_OSCORE2)
      RAM_OS_NOCACHE_VAR_OSCORE2_END = .;


      . = ALIGN(4);
      *(.OS_STACK_OSCORE5)
      . = ALIGN(4);
      RAM_OS_VAR_OSCORE5_START = .;
      *(.OS_VAR_OSCORE5)
      RAM_OS_VAR_OSCORE5_END = .;
      . = ALIGN(4);
      RAM_OS_NOCACHE_VAR_OSCORE5_START = .;
      *(.OS_NOCACHE_VAR_OSCORE5)
      RAM_OS_NOCACHE_VAR_OSCORE5_END = .;

      . = ALIGN(4);
      RAM_OS_GLOBAL_NOCACHE_VAR_START = .;
      *(.OS_GLOBAL_NOCACHE_VAR)
      RAM_OS_GLOBAL_NOCACHE_VAR_END = .;
      . = ALIGN(4);

    } > asw_bsw2_ram  

    /* bsw safety flash */
    .bsw_flash_blank0 :
    {
      . += BLANK_SIZE;
    } > bsw_flash
    .bsw_flash_safety_asila ALIGN(4) : 
    {
      "*(.bsw_flash_safety_asila)"
      "*(.bsw_flash_safety_asila.*)"
    } > bsw_flash
    .bsw_flash_blank1 :
    {
      . += BLANK_SIZE;
    } > bsw_flash
    .bsw_flash_safety_asilb ALIGN(4) : 
    {
      "*(.bsw_flash_safety_asilb)"
      "*(.bsw_flash_safety_asilb.*)"
    } > bsw_flash
    .bsw_flash_blank2 :
    {
      . += BLANK_SIZE;
    } > bsw_flash
    .bsw_flash_safety_asilc ALIGN(4) : 
    {
      "*(.bsw_flash_safety_asilc)"
      "*(.bsw_flash_safety_asilc.*)"

      "*(.saf_text)"
      "*(.saf_adc_text)"
      "*(.saf_bist_text)"
      "*(.saf_cache_text)"
      "*(.saf_mcu_text)"
      "*(.saf_cmu_text)"
      "*(.saf_core_text)"
      "*(.saf_crc_text)"
      "*(.saf_cmpu_text)"
      "*(.saf_dma_text)"
      "*(.saf_fccu_text)"
      "*(.saf_flash_text)"
      "*(.saf_intc_text)"
      "*(.saf_mem_text)"
      "*(.saf_memu_text)"
      "*(.saf_osc_text)"
      "*(.saf_pit_text)"
      "*(.saf_pll_text)"
      "*(.saf_pmc_text)"
      "*(.saf_ram_text)"
      "*(.saf_regprot_text)"
      "*(.saf_sch_text)"
      "*(.saf_smpu_text)"
      "*(.saf_stack_text)"
      "*(.saf_stm_text)"
      "*(.saf_swt_text)"
      "*(.saf_tsens_text)"

      "*(.saf_rodata)"
      "*(.saf_adc_rodata)"
      "*(.saf_bist_rodata)"
      "*(.saf_cache_rodata)"
      "*(.saf_mcu_rodata)"
      "*(.saf_cmu_rodata)"
      "*(.saf_core_rodata)"
      "*(.saf_crc_rodata)"
      "*(.saf_cmpu_rodata)"
      "*(.saf_dma_rodata)"
      "*(.saf_fccu_rodata)"
      "*(.saf_flash_rodata)"
      "*(.saf_intc_rodata)"
      "*(.saf_mem_rodata)"
      "*(.saf_memu_rodata)"
      "*(.saf_osc_rodata)"
      "*(.saf_pit_rodata)"
      "*(.saf_pll_rodata)"
      "*(.saf_pmc_rodata)"
      "*(.saf_ram_rodata)"
      "*(.saf_regprot_rodata)"
      "*(.saf_sch_rodata)"
      "*(.saf_smpu_rodata)"
      "*(.saf_stack_rodata)"
      "*(.saf_stm_rodata)"
      "*(.saf_swt_rodata)"
      "*(.saf_tsens_rodata)"
    } > bsw_flash
    .bsw_flash_blank3 :
    {
      . += BLANK_SIZE;
    } > bsw_flash
    .bsw_flash_safety_global ALIGN(4) : 
    {
      "*(.bsw_flash_safety_global)"
      "*(.bsw_flash_safety_global.*)"
    } > bsw_flash
    .bsw_flash_blank4 :
    {
      . += BLANK_SIZE;
    } > bsw_flash
    /* bsw safety flash end */
    
    /* asw safety flash */
    .asw_flash_blank0 :
    {
      . += BLANK_SIZE;
    } > asw_flash
    .asw_flash_safety_asila ALIGN(4) : 
    {
      "*(.asw_flash_safety_asila)"
      "*(.asw_flash_safety_asila.*)"
    } > asw_flash
    .asw_flash_blank1 :
    {
      . += BLANK_SIZE;
    } > asw_flash
    .asw_flash_safety_asilb ALIGN(4) : 
    {
      "*(.asw_flash_safety_asilb)"
      "*(.asw_flash_safety_asilb.*)"
    } > asw_flash
    .asw_flash_blank2 :
    {
      . += BLANK_SIZE;
    } > asw_flash
    .asw_flash_safety_asilc ALIGN(4) : 
    {
      "*(.asw_flash_safety_asilc)"
      "*(.asw_flash_safety_asilc.*)"
    } > asw_flash
    .asw_flash_blank3 :
    {
      . += BLANK_SIZE;
    } > asw_flash
    .asw_flash_safety_global ALIGN(4) : 
    {
      "*(.asw_flash_safety_global)"
      "*(.asw_flash_safety_global.*)"
    } > asw_flash
    .asw_flash_blank4 :
    {
      . += BLANK_SIZE;
    } > asw_flash
    .asw_flash_safety_qm ALIGN(4) : 
    {
      "*(.asw_flash_safety_qm)"
      "*(.asw_flash_safety_qm.*)"
    } > asw_flash
    .asw_flash_blank5 :
    {
      . += BLANK_SIZE;
    } > asw_flash
    /* asw safety flash end */


    /* Eeprom_Ram */
    .ee_Block2_data (NOLOAD) :
    {
      "*(.ee_Block2_data)"
      "*(.ee_Block2_data.*)"
    } > eeBlock2_ram
    .ee_Block3_data (NOLOAD) :
    {
      "*(.ee_Block3_data)"
      "*(.ee_Block3_data.*)"
    } > eeBlock3_ram
    .ee_Block4_data (NOLOAD) :
    {
      "*(.ee_Block4_data)"
      "*(.ee_Block4_data.*)"
    } > eeBlock4_ram
    .ee_Block5_data (NOLOAD) :
    {
      "*(.ee_Block5_data)"
      "*(.ee_Block5_data.*)"
    } > eeBlock5_ram
    .ee_Block6_data (NOLOAD) :
    {
      "*(.ee_Block6_data)"
      "*(.ee_Block6_data.*)"
    } > eeBlock6_ram
    .ee_Block7_data (NOLOAD) :
    {
      "*(.ee_Block7_data)"
      "*(.ee_Block7_data.*)"
    } > eeBlock7_ram
    .ee_Block8_data (NOLOAD) :
    {
      "*(.ee_Block8_data)"
      "*(.ee_Block8_data.*)"
    } > eeBlock8_ram
    .ee_Block9_data (NOLOAD) :
    {
      "*(.ee_Block9_data)"
      "*(.ee_Block9_data.*)"
    } > eeBlock9_ram
    .ee_Block10_data (NOLOAD) :
    {
      "*(.ee_Block10_data)"
      "*(.ee_Block10_data.*)"
    } > eeBlock10_ram
    .ee_Block11_data (NOLOAD) :
    {
      "*(.ee_Block11_data)"
      "*(.ee_Block11_data.*)"
    } > eeBlock11_ram
    .ee_Block12_data (NOLOAD) :
    {
      "*(.ee_Block12_data)"
      "*(.ee_Block12_data.*)"
    } > eeBlock12_ram
    .ee_Block13_data (NOLOAD) :
    {
      "*(.ee_Block13_data)"
      "*(.ee_Block13_data.*)"
    } > eeBlock13_ram
    .ee_Block14_data (NOLOAD) :
    {
      "*(.ee_Block14_data)"
      "*(.ee_Block14_data.*)"
    } > eeBlock14_ram
    .ee_Block15_data (NOLOAD) :
    {
      "*(.ee_Block15_data)"
      "*(.ee_Block15_data.*)"
    } > eeBlock15_ram
    .ee_Block16_data (NOLOAD) :
    {
      "*(.ee_Block16_data)"
      "*(.ee_Block16_data.*)"
    } > eeBlock16_ram
    .ee_Block17_data (NOLOAD) :
    {
      "*(.ee_Block17_data)"
      "*(.ee_Block17_data.*)"
    } > eeBlock17_ram
    .ee_Block18_data (NOLOAD) :
    {
      "*(.ee_Block18_data)"
      "*(.ee_Block18_data.*)"
    } > eeBlock18_ram
    .ee_Block19_data (NOLOAD) :
    {
      "*(.ee_Block19_data)"
      "*(.ee_Block19_data.*)"
    } > eeBlock19_ram
    .ee_Block20_data (NOLOAD) :
    {
      "*(.ee_Block20_data)"
      "*(.ee_Block20_data.*)"
    } > eeBlock20_ram
    .ee_Block21_data (NOLOAD) :
    {
      "*(.ee_Block21_data)"
      "*(.ee_Block21_data.*)"
    } > eeBlock21_ram
    .ee_Block22_data (NOLOAD) :
    {
      "*(.ee_Block22_data)"
      "*(.ee_Block22_data.*)"
    } > eeBlock22_ram
    .ee_Block23_data (NOLOAD) :
    {
      "*(.ee_Block23_data)"
      "*(.ee_Block23_data.*)"
    } > eeBlock23_ram
    .ee_Block24_data (NOLOAD) :
    {
      "*(.ee_Block24_data)"
      "*(.ee_Block24_data.*)"
    } > eeBlock24_ram
    .ee_Block25_data (NOLOAD) :
    {
      "*(.ee_Block25_data)"
      "*(.ee_Block25_data.*)"
    } > eeBlock25_ram
    .ee_Block26_data (NOLOAD) :
    {
      "*(.ee_Block26_data)"
      "*(.ee_Block26_data.*)"
    } > eeBlock26_ram
    .ee_Block27_data (NOLOAD) :
    {
      "*(.ee_Block27_data)"
      "*(.ee_Block27_data.*)"
    } > eeBlock27_ram
    .ee_Block28_data (NOLOAD) :
    {
      "*(.ee_Block28_data)"
      "*(.ee_Block28_data.*)"
    } > eeBlock28_ram
    .ee_Block29_data (NOLOAD) :
    {
      "*(.ee_Block29_data)"
      "*(.ee_Block29_data.*)"
    } > eeBlock29_ram
    .ee_Block30_data (NOLOAD) :
    {
      "*(.ee_Block30_data)"
      "*(.ee_Block30_data.*)"
    } > eeBlock30_ram
    .ee_Block31_data (NOLOAD) :
    {
      "*(.ee_Block31_data)"
      "*(.ee_Block31_data.*)"
    } > eeBlock31_ram
    .ee_Block32_data (NOLOAD) :
    {
      "*(.ee_Block32_data)"
      "*(.ee_Block32_data.*)"
    } > eeBlock32_ram
    .ee_Block33_data (NOLOAD) :
    {
      "*(.ee_Block33_data)"
      "*(.ee_Block33_data.*)"
    } > eeBlock33_ram
    .ee_Block34_data (NOLOAD) :
    {
      "*(.ee_Block34_data)"
      "*(.ee_Block34_data.*)"
    } > eeBlock34_ram
    .ee_Block35_data (NOLOAD) :
    {
      "*(.ee_Block35_data)"
      "*(.ee_Block35_data.*)"
    } > eeBlock35_ram
    .ee_Block36_data (NOLOAD) :
    {
      "*(.ee_Block36_data)"
      "*(.ee_Block36_data.*)"
    } > eeBlock36_ram
    .ee_Block37_data (NOLOAD) :
    {
      "*(.ee_Block37_data)"
      "*(.ee_Block37_data.*)"
    } > eeBlock37_ram
    .ee_Block38_data (NOLOAD) :
    {
      "*(.ee_Block38_data)"
      "*(.ee_Block38_data.*)"
    } > eeBlock38_ram
    .ee_Block39_data (NOLOAD) :
    {
      "*(.ee_Block39_data)"
      "*(.ee_Block39_data.*)"
    } > eeBlock39_ram
    .ee_Block40_data (NOLOAD) :
    {
      "*(.ee_Block40_data)"
      "*(.ee_Block40_data.*)"
    } > eeBlock40_ram
    .ee_Block41_data (NOLOAD) :
    {
      "*(.ee_Block41_data)"
      "*(.ee_Block41_data.*)"
    } > eeBlock41_ram
    .ee_Block42_data (NOLOAD) :
    {
      "*(.ee_Block42_data)"
      "*(.ee_Block42_data.*)"
    } > eeBlock42_ram
    .ee_Block43_data (NOLOAD) :
    {
      "*(.ee_Block43_data)"
      "*(.ee_Block43_data.*)"
    } > eeBlock43_ram
    .ee_Block44_data (NOLOAD) :
    {
      "*(.ee_Block44_data)"
      "*(.ee_Block44_data.*)"
    } > eeBlock44_ram
    .ee_Block45_data (NOLOAD) :
    {
      "*(.ee_Block45_data)"
      "*(.ee_Block45_data.*)"
    } > eeBlock45_ram
    .ee_Block46_data (NOLOAD) :
    {
      "*(.ee_Block46_data)"
      "*(.ee_Block46_data.*)"
    } > eeBlock46_ram
    .ee_Block47_data (NOLOAD) :
    {
      "*(.ee_Block47_data)"
      "*(.ee_Block47_data.*)"
    } > eeBlock47_ram
    .ee_Block48_data (NOLOAD) :
    {
      "*(.ee_Block48_data)"
      "*(.ee_Block48_data.*)"
    } > eeBlock48_ram
    .ee_Block49_data (NOLOAD) :
    {
      "*(.ee_Block49_data)"
      "*(.ee_Block49_data.*)"
    } > eeBlock49_ram
    .ee_Block50_data (NOLOAD) :
    {
      "*(.ee_Block50_data)"
      "*(.ee_Block50_data.*)"
    } > eeBlock50_ram
    .ee_Block51_data (NOLOAD) :
    {
      "*(.ee_Block51_data)"
      "*(.ee_Block51_data.*)"
    } > eeBlock51_ram
    .ee_Block52_data (NOLOAD) :
    {
      "*(.ee_Block52_data)"
      "*(.ee_Block52_data.*)"
    } > eeBlock52_ram
    .ee_Block53_data (NOLOAD) :
    {
      "*(.ee_Block53_data)"
      "*(.ee_Block53_data.*)"
    } > eeBlock53_ram
    .ee_Block54_data (NOLOAD) :
    {
      "*(.ee_Block54_data)"
      "*(.ee_Block54_data.*)"
    } > eeBlock54_ram
    .ee_Block55_data (NOLOAD) :
    {
      "*(.ee_Block55_data)"
      "*(.ee_Block55_data.*)"
    } > eeBlock55_ram
    .ee_Block56_data (NOLOAD) :
    {
      "*(.ee_Block56_data)"
      "*(.ee_Block56_data.*)"
    } > eeBlock56_ram
    .ee_Block57_data (NOLOAD) :
    {
      "*(.ee_Block57_data)"
      "*(.ee_Block57_data.*)"
    } > eeBlock57_ram
    .ee_Block58_data (NOLOAD) :
    {
      "*(.ee_Block58_data)"
      "*(.ee_Block58_data.*)"
    } > eeBlock58_ram
    .ee_Block59_data (NOLOAD) :
    {
      "*(.ee_Block59_data)"
      "*(.ee_Block59_data.*)"
    } > eeBlock59_ram
    .ee_Block60_data (NOLOAD) :
    {
      "*(.ee_Block60_data)"
      "*(.ee_Block60_data.*)"
    } > eeBlock60_ram
    .ee_Block61_data (NOLOAD) :
    {
      "*(.ee_Block61_data)"
      "*(.ee_Block61_data.*)"
    } > eeBlock61_ram
    .ee_Block62_data (NOLOAD) :
    {
      "*(.ee_Block62_data)"
      "*(.ee_Block62_data.*)"
    } > eeBlock62_ram
    .ee_Block63_data (NOLOAD) :
    {
      "*(.ee_Block63_data)"
      "*(.ee_Block63_data.*)"
    } > eeBlock63_ram
    .ee_Block64_data (NOLOAD) :
    {
      "*(.ee_Block64_data)"
      "*(.ee_Block64_data.*)"
    } > eeBlock64_ram
    .ee_Block65_data (NOLOAD) :
    {
      "*(.ee_Block65_data)"
      "*(.ee_Block65_data.*)"
    } > eeBlock65_ram
    .ee_Block66_data (NOLOAD) :
    {
      "*(.ee_Block66_data)"
      "*(.ee_Block66_data.*)"
    } > eeBlock66_ram
    .ee_Block67_data (NOLOAD) :
    {
      "*(.ee_Block67_data)"
      "*(.ee_Block67_data.*)"
    } > eeBlock67_ram
    .ee_Block68_data (NOLOAD) :
    {
      "*(.ee_Block68_data)"
      "*(.ee_Block68_data.*)"
    } > eeBlock68_ram
    .ee_Block69_data (NOLOAD) :
    {
      "*(.ee_Block69_data)"
      "*(.ee_Block69_data.*)"
    } > eeBlock69_ram
    .ee_Block70_data (NOLOAD) :
    {
      "*(.ee_Block70_data)"
      "*(.ee_Block70_data.*)"
    } > eeBlock70_ram
    .ee_Block71_data (NOLOAD) :
    {
      "*(.ee_Block71_data)"
      "*(.ee_Block71_data.*)"
    } > eeBlock71_ram
    .ee_Block72_data (NOLOAD) :
    {
      "*(.ee_Block72_data)"
      "*(.ee_Block72_data.*)"
    } > eeBlock72_ram
    .ee_Block73_data (NOLOAD) :
    {
      "*(.ee_Block73_data)"
      "*(.ee_Block73_data.*)"
    } > eeBlock73_ram
    .ee_Block74_data (NOLOAD) :
    {
      "*(.ee_Block74_data)"
      "*(.ee_Block74_data.*)"
    } > eeBlock74_ram
    .ee_Block75_data (NOLOAD) :
    {
      "*(.ee_Block75_data)"
      "*(.ee_Block75_data.*)"
    } > eeBlock75_ram
    .ee_Block76_data (NOLOAD) :
    {
      "*(.ee_Block76_data)"
      "*(.ee_Block76_data.*)"
    } > eeBlock76_ram
    .ee_Block77_data (NOLOAD) :
    {
      "*(.ee_Block77_data)"
      "*(.ee_Block77_data.*)"
    } > eeBlock77_ram
    .ee_Block78_data (NOLOAD) :
    {
      "*(.ee_Block78_data)"
      "*(.ee_Block78_data.*)"
    } > eeBlock78_ram
    .ee_Block79_data (NOLOAD) :
    {
      "*(.ee_Block79_data)"
      "*(.ee_Block79_data.*)"
    } > eeBlock79_ram
    .ee_Block80_data (NOLOAD) :
    {
      "*(.ee_Block80_data)"
      "*(.ee_Block80_data.*)"
    } > eeBlock80_ram
    .ee_Block81_data (NOLOAD) :
    {
      "*(.ee_Block81_data)"
      "*(.ee_Block81_data.*)"
    } > eeBlock81_ram
    .ee_Block82_data (NOLOAD) :
    {
      "*(.ee_Block82_data)"
      "*(.ee_Block82_data.*)"
    } > eeBlock82_ram
    .ee_Block83_data (NOLOAD) :
    {
      "*(.ee_Block83_data)"
      "*(.ee_Block83_data.*)"
    } > eeBlock83_ram
    .ee_Block84_data (NOLOAD) :
    {
      "*(.ee_Block84_data)"
      "*(.ee_Block84_data.*)"
    } > eeBlock84_ram
    .ee_Block85_data (NOLOAD) :
    {
      "*(.ee_Block85_data)"
      "*(.ee_Block85_data.*)"
    } > eeBlock85_ram
    .ee_Block86_data (NOLOAD) :
    {
      "*(.ee_Block86_data)"
      "*(.ee_Block86_data.*)"
    } > eeBlock86_ram
    .ee_Block87_data (NOLOAD) :
    {
      "*(.ee_Block87_data)"
      "*(.ee_Block87_data.*)"
    } > eeBlock87_ram
    .ee_Block88_data (NOLOAD) :
    {
      "*(.ee_Block88_data)"
      "*(.ee_Block88_data.*)"
    } > eeBlock88_ram
    .ee_Block89_data (NOLOAD) :
    {
      "*(.ee_Block89_data)"
      "*(.ee_Block89_data.*)"
    } > eeBlock89_ram
    .ee_Block90_data (NOLOAD) :
    {
      "*(.ee_Block90_data)"
      "*(.ee_Block90_data.*)"
    } > eeBlock90_ram
    .ee_Block91_data (NOLOAD) :
    {
      "*(.ee_Block91_data)"
      "*(.ee_Block91_data.*)"
    } > eeBlock91_ram
    .ee_Block92_data (NOLOAD) :
    {
      "*(.ee_Block92_data)"
      "*(.ee_Block92_data.*)"
    } > eeBlock92_ram
    .ee_Block93_data (NOLOAD) :
    {
      "*(.ee_Block93_data)"
      "*(.ee_Block93_data.*)"
    } > eeBlock93_ram
    .ee_Block94_data (NOLOAD) :
    {
      "*(.ee_Block94_data)"
      "*(.ee_Block94_data.*)"
    } > eeBlock94_ram
    .ee_Block95_data (NOLOAD) :
    {
      "*(.ee_Block95_data)"
      "*(.ee_Block95_data.*)"
    } > eeBlock95_ram
    .ee_Block96_data (NOLOAD) :
    {
      "*(.ee_Block96_data)"
      "*(.ee_Block96_data.*)"
    } > eeBlock96_ram
    .ee_Block97_data (NOLOAD) :
    {
      "*(.ee_Block97_data)"
      "*(.ee_Block97_data.*)"
    } > eeBlock97_ram
    .ee_Block98_data (NOLOAD) :
    {
      "*(.ee_Block98_data)"
      "*(.ee_Block98_data.*)"
    } > eeBlock98_ram
    .ee_Block99_data (NOLOAD) :
    {
      "*(.ee_Block99_data)"
      "*(.ee_Block99_data.*)"
    } > eeBlock99_ram
    .ee_Block100_data (NOLOAD) :
    {
      "*(.ee_Block100_data)"
      "*(.ee_Block100_data.*)"
    } > eeBlock100_ram
    .ee_Block101_data (NOLOAD) :
    {
      "*(.ee_Block101_data)"
      "*(.ee_Block101_data.*)"
    } > eeBlock101_ram
    .ee_Block102_data (NOLOAD) :
    {
      "*(.ee_Block102_data)"
      "*(.ee_Block102_data.*)"
    } > eeBlock102_ram
    .ee_Block103_data (NOLOAD) :
    {
      "*(.ee_Block103_data)"
      "*(.ee_Block103_data.*)"
    } > eeBlock103_ram
    .ee_Block104_data (NOLOAD) :
    {
      "*(.ee_Block104_data)"
      "*(.ee_Block104_data.*)"
    } > eeBlock104_ram
    .ee_Block105_data (NOLOAD) :
    {
      "*(.ee_Block105_data)"
      "*(.ee_Block105_data.*)"
    } > eeBlock105_ram
    .ee_Block106_data (NOLOAD) :
    {
      "*(.ee_Block106_data)"
      "*(.ee_Block106_data.*)"
    } > eeBlock106_ram
    .ee_Block107_data (NOLOAD) :
    {
      "*(.ee_Block107_data)"
      "*(.ee_Block107_data.*)"
    } > eeBlock107_ram
    .ee_Block108_data (NOLOAD) :
    {
      "*(.ee_Block108_data)"
      "*(.ee_Block108_data.*)"
    } > eeBlock108_ram
    .ee_Block109_data (NOLOAD) :
    {
      "*(.ee_Block109_data)"
      "*(.ee_Block109_data.*)"
    } > eeBlock109_ram
    .ee_Block110_data (NOLOAD) :
    {
      "*(.ee_Block110_data)"
      "*(.ee_Block110_data.*)"
    } > eeBlock110_ram
    .ee_Block111_data (NOLOAD) :
    {
      "*(.ee_Block111_data)"
      "*(.ee_Block111_data.*)"
    } > eeBlock111_ram
    .ee_Block112_data (NOLOAD) :
    {
      "*(.ee_Block112_data)"
      "*(.ee_Block112_data.*)"
    } > eeBlock112_ram
    .ee_Block113_data (NOLOAD) :
    {
      "*(.ee_Block113_data)"
      "*(.ee_Block113_data.*)"
    } > eeBlock113_ram
    .ee_Block114_data (NOLOAD) :
    {
      "*(.ee_Block114_data)"
      "*(.ee_Block114_data.*)"
    } > eeBlock114_ram
    .ee_Block115_data (NOLOAD) :
    {
      "*(.ee_Block115_data)"
      "*(.ee_Block115_data.*)"
    } > eeBlock115_ram
    .ee_Block116_data (NOLOAD) :
    {
      "*(.ee_Block116_data)"
      "*(.ee_Block116_data.*)"
    } > eeBlock116_ram
    .ee_Block117_data (NOLOAD) :
    {
      "*(.ee_Block117_data)"
      "*(.ee_Block117_data.*)"
    } > eeBlock117_ram
    .ee_Block118_data (NOLOAD) :
    {
      "*(.ee_Block118_data)"
      "*(.ee_Block118_data.*)"
    } > eeBlock118_ram
    .ee_Block119_data (NOLOAD) :
    {
      "*(.ee_Block119_data)"
      "*(.ee_Block119_data.*)"
    } > eeBlock119_ram
    .ee_Block120_data (NOLOAD) :
    {
      "*(.ee_Block120_data)"
      "*(.ee_Block120_data.*)"
    } > eeBlock120_ram
    .ee_Block121_data (NOLOAD) :
    {
      "*(.ee_Block121_data)"
      "*(.ee_Block121_data.*)"
    } > eeBlock121_ram
    .ee_Block122_data (NOLOAD) :
    {
      "*(.ee_Block122_data)"
      "*(.ee_Block122_data.*)"
    } > eeBlock122_ram
    .ee_Block123_data (NOLOAD) :
    {
      "*(.ee_Block123_data)"
      "*(.ee_Block123_data.*)"
    } > eeBlock123_ram
    .ee_Block124_data (NOLOAD) :
    {
      "*(.ee_Block124_data)"
      "*(.ee_Block124_data.*)"
    } > eeBlock124_ram
    .ee_Block125_data (NOLOAD) :
    {
      "*(.ee_Block125_data)"
      "*(.ee_Block125_data.*)"
    } > eeBlock125_ram
    .ee_Block126_data (NOLOAD) :
    {
      "*(.ee_Block126_data)"
      "*(.ee_Block126_data.*)"
    } > eeBlock126_ram
    .ee_Block127_data (NOLOAD) :
    {
      "*(.ee_Block127_data)"
      "*(.ee_Block127_data.*)"
    } > eeBlock127_ram
    .ee_Block128_data (NOLOAD) :
    {
      "*(.ee_Block128_data)"
      "*(.ee_Block128_data.*)"
    } > eeBlock128_ram
    .ee_Block129_data (NOLOAD) :
    {
      "*(.ee_Block129_data)"
      "*(.ee_Block129_data.*)"
    } > eeBlock129_ram
    .ee_Block130_data (NOLOAD) :
    {
      "*(.ee_Block130_data)"
      "*(.ee_Block130_data.*)"
    } > eeBlock130_ram
    .ee_Block131_data (NOLOAD) :
    {
      "*(.ee_Block131_data)"
      "*(.ee_Block131_data.*)"
    } > eeBlock131_ram

    .algorith_ram :
    {
    
    . = ALIGN(4);
      "*Task_App_Core3.o(.vletext)"
      "*Task_App_Core3.o(.text)"
      "*Task_App_Core3.o(.text.*)"

      "*MCU_fc_BIfRx_IN.o(.vletext)"
      "*MCU_fc_BIfRx_IN.o(.text)"
      "*MCU_fc_BIfRx_IN.o(.text.*)"

      "*MCU_fc_BIfRx_OUT.o(.vletext)"
      "*MCU_fc_BIfRx_OUT.o(.text)"
      "*MCU_fc_BIfRx_OUT.o(.text.*)"

      /*"*Rte_App1_Application_Core3_QM.o(.vletext)"*/
      /*"*Rte_App1_Application_Core3_QM.o(.text)"*/
      /*"*Rte_App1_Application_Core3_QM.o(.text.*)"*/

      "*indfmaxf.o(.vletext)"
      "*indfmaxf.o(.text)"
      "*indfmaxf.o(.text.*)"


      "*indfminf.o(.vletext)"
      "*indfminf.o(.text)"
      "*indfminf.o(.text.*)"


      "*indsqrtf.o(.vletext)"
      "*indsqrtf.o(.text)"
      "*indsqrtf.o(.text.*)"

      "*indpowf.o(.vletext)"
      "*indpowf.o(.text)"
      "*indpowf.o(.text.*)"

      "*indroundf.o(.vletext)"
      "*indroundf.o(.text)"
      "*indroundf.o(.text.*)"

      "*indfloorf.o(.vletext)"
      "*indfloorf.o(.text)"
      "*indfloorf.o(.text.*)"

      "*indexpf.o(.vletext)"
      "*indexpf.o(.text)"
      "*indexpf.o(.text.*)"

      "*indtruncf.o(.vletext)"
      "*indtruncf.o(.text)"
      "*indtruncf.o(.text.*)"

      "*indatn2f.o(.vletext)"
      "*indatn2f.o(.text)"
      "*indatn2f.o(.text.*)"

      "*(.algorith_ram)"
      "*(.algorith_ram.*)"
      "*(.foc_code)"     
      . = ALIGN(4);
    } > algorith_Ram
    .ROM.algorith_ram  ROM(.algorith_ram ) : > bsw_flash

    .reset_keep (NOLOAD):
    {
      "*(.reset_keep)"
      "*(.reset_keep.*)"
      . = ALIGN(4);
    } > resetkeep_ram

    .foc_bss :  
    {
      . = ALIGN(4);
      *(.OS_STACK_OSCORE3)
      . = ALIGN(4);
      RAM_OS_VAR_OSCORE3_START = .;
      *(.OS_VAR_OSCORE3)
      RAM_OS_VAR_OSCORE3_END = .;
      . = ALIGN(4);
      RAM_OS_NOCACHE_VAR_OSCORE3_START = .;
      *(.OS_NOCACHE_VAR_OSCORE3)
      RAM_OS_NOCACHE_VAR_OSCORE3_END = .;    
    
      . = ALIGN(4);
       *(.foc_bss)
      "*Rte_App1_Application_Core3_QM.o(.bss)" 
      "*Rte_App1_Application_Core3_QM.o(.bss.*)"  
      "*Task_App_Core3.o(.bss)" 
      "*Task_App_Core3.o(.bss.*)"  
    
      "*Diag.o(.bss)"      
      "*Diag.o(.bss.*)"      
      "*PhaCurrDev.o(.bss)"   
      "*PhaCurrDev.o(.bss.*)"   
      "*IdqCtrl.o(.bss)"      
      "*IdqCtrl.o(.bss.*)"      
      "*VoltModlnGen.o(.bss)" 
      "*VoltModlnGen.o(.bss.*)" 
      "*VoltModlnInp.o(.bss)" 
      "*VoltModlnInp.o(.bss.*)" 
      "*TqDemCoorn.o(.bss)"   
      "*TqDemCoorn.o(.bss.*)"   
      "*IdqDes.o(.bss)"       
      "*IdqDes.o(.bss.*)"       
      "*EdrvStMac.o(.bss)"    
      "*EdrvStMac.o(.bss.*)"    
      "*TempDev.o(.bss)"      
      "*TempDev.o(.bss.*)"      
      "*IdqAct.o(.bss)"       
      "*IdqAct.o(.bss.*)"       
      "*HrmcInj.o(.bss)"      
      "*HrmcInj.o(.bss.*)"      
      "*ComTx_CAN.o(.bss)"   
      "*ComTx_CAN.o(.bss.*)"   
      "*HvIntlck.o(.bss)"     
      "*HvIntlck.o(.bss.*)"     
      "*ExtTqDes.o(.bss)"     
      "*ExtTqDes.o(.bss.*)"     
      "*HvInvDev.o(.bss)"     
      "*HvInvDev.o(.bss.*)"     
      "*EmPwr.o(.bss)"        
      "*EmPwr.o(.bss.*)"        
      "*EmTq.o(.bss)"         
      "*EmTq.o(.bss.*)"         
      "*DynFrq.o(.bss)"              
      "*DynFrq.o(.bss.*)"              
      "*DernSys.o(.bss)"             
      "*DernSys.o(.bss.*)"             
      "*GLOBAL_calibration.o(.bss)" 
      "*GLOBAL_calibration.o(.bss.*)" 
      "*DernEm.o(.bss)"              
      "*DernEm.o(.bss.*)"              
      "*DernInv.o(.bss)"             
      "*DernInv.o(.bss.*)"             
      /*"*ComRx_CAN.o(.bss)"*/          
      /*"*ComRx_CAN.o(.bss.*)"*/          
      "*DernCoorn.o(.bss)"           
      "*DernCoorn.o(.bss.*)"           
      "*AntiRollBack.o(.bss)"        
      "*AntiRollBack.o(.bss.*)"        
      "*BIfRx.o(.bss)"               
      "*BIfRx.o(.bss.*)"               
      "*AngSwDecod.o(.bss)"          
      "*AngSwDecod.o(.bss.*)"          
      "*Dchrg.o(.bss)"               
      "*Dchrg.o(.bss.*)"               
      "*AngOfstCal.o(.bss)"          
      "*AngOfstCal.o(.bss.*)"          
      "*BIfTx.o(.bss)"               
      "*BIfTx.o(.bss.*)"               
      "*ActvDampg.o(.bss)"           
      "*ActvDampg.o(.bss.*)"           
      "*AngEmDev.o(.bss)"            
      "*AngEmDev.o(.bss.*)"            
      "*BlfTx.o(.bss)"
      "*BlfTx.o(.bss.*)"
      "*ActvDampg.o(.bss)"
      "*ActvDampg.o(.bss.*)"
      "*AngEmDev.o(.bss)"
      "*AngEmDev.o(.bss.*)"
      "*sort_ByVjd1nn.o(.bss)"
      "*sort_ByVjd1nn.o(.bss.*)"
      "*merge_xRqbf8II.o(.bss)"
      "*merge_xRqbf8II.o(.bss.*)"
      "*look1_iflf_binlca.o(.bss)"
      "*look1_iflf_binlca.o(.bss.*)"
      . = ALIGN(4);
    } > asw_bsw4_ram

    .foc_data :  
    {
      . = ALIGN(4);
       *(.foc_data)
      "*Rte_App1_Application_Core3_QM.o(.data)" 
      "*Rte_App1_Application_Core3_QM.o(.data.*)"  
      "*Task_App_Core3.o(.data)" 
      "*Task_App_Core3.o(.data.*)"  
      "*Diag.o(.data)"      
      "*Diag.o(.data.*)"      
      "*PhaCurrDev.o(.data)"   
      "*PhaCurrDev.o(.data.*)"   
      "*IdqCtrl.o(.data)"      
      "*IdqCtrl.o(.data.*)"      
      "*VoltModlnGen.o(.data)" 
      "*VoltModlnGen.o(.data.*)" 
      "*VoltModlnInp.o(.data)" 
      "*VoltModlnInp.o(.data.*)" 
      "*TqDemCoorn.o(.data)"   
      "*TqDemCoorn.o(.data.*)"   
      "*IdqDes.o(.data)"       
      "*IdqDes.o(.data.*)"       
      "*EdrvStMac.o(.data)"    
      "*EdrvStMac.o(.data.*)"    
      "*TempDev.o(.data)"      
      "*TempDev.o(.data.*)"      
      "*IdqAct.o(.data)"       
      "*IdqAct.o(.data.*)"       
      "*HrmcInj.o(.data)"      
      "*HrmcInj.o(.data.*)"      
      "*ComTx_CAN.o(.data)"   
      "*ComTx_CAN.o(.data.*)"   
      "*HvIntlck.o(.data)"     
      "*HvIntlck.o(.data.*)"     
      "*ExtTqDes.o(.data)"     
      "*ExtTqDes.o(.data.*)"     
      "*HvInvDev.o(.data)"     
      "*HvInvDev.o(.data.*)"     
      "*EmPwr.o(.data)"        
      "*EmPwr.o(.data.*)"        
      "*EmTq.o(.data)"         
      "*EmTq.o(.data.*)"         
      "*DynFrq.o(.data)"              
      "*DynFrq.o(.data.*)"              
      "*DernSys.o(.data)"             
      "*DernSys.o(.data.*)"             
      "*GLOBAL_calibration.o(.data)" 
      "*GLOBAL_calibration.o(.data.*)" 
      "*DernEm.o(.data)"              
      "*DernEm.o(.data.*)"              
      "*DernInv.o(.data)"             
      "*DernInv.o(.data.*)"             
      /*"*ComRx_CAN.o(.data)"*/          
      /*"*ComRx_CAN.o(.data.*)"*/          
      "*DernCoorn.o(.data)"           
      "*DernCoorn.o(.data.*)"           
      "*AntiRollBack.o(.data)"        
      "*AntiRollBack.o(.data.*)"        
      "*BIfRx.o(.data)"               
      "*BIfRx.o(.data.*)"               
      "*AngSwDecod.o(.data)"          
      "*AngSwDecod.o(.data.*)"          
      "*Dchrg.o(.data)"               
      "*Dchrg.o(.data.*)"               
      "*AngOfstCal.o(.data)"          
      "*AngOfstCal.o(.data.*)"          
      "*BIfTx.o(.data)"               
      "*BIfTx.o(.data.*)"               
      "*ActvDampg.o(.data)"           
      "*ActvDampg.o(.data.*)"           
      "*AngEmDev.o(.data)"            
      "*AngEmDev.o(.data.*)"            
      "*BlfTx.o(.data)"
      "*BlfTx.o(.data.*)"
      "*ActvDampg.o(.data)"
      "*ActvDampg.o(.data.*)"
      "*AngEmDev.o(.data)"
      "*AngEmDev.o(.data.*)"
      "*sort_ByVjd1nn.o(.data)"
      "*sort_ByVjd1nn.o(.data.*)"
      "*merge_xRqbf8II.o(.data)"
      "*merge_xRqbf8II.o(.data.*)"
      "*look1_iflf_binlca.o(.data)"
      "*look1_iflf_binlca.o(.data.*)"      
      

      "*IdqCtrl.o(.rodata)"  
      "*DynFrq.o(.rodata)"   
      "*HrmcInj.o(.rodata)" 
      "*BIfRx.o(.rodata)"  
      "*EdrvStMac.o(.rodata)"   
      . = ALIGN(4);
    } > asw_bsw4_ram
    .ROM.foc_data  ROM(.foc_data ) : > bsw_flash
    
    .mcu_code :  
    {
      . = ALIGN(4);
     "*EdrvStMac.o(.vletext)"
     "*EdrvStMac.o(.text)"
     "*EdrvStMac.o(.text.*)"
     "*HrmcInj.o(.vletext)"
     "*HrmcInj.o(.text)"
     "*HrmcInj.o(.text.*)"

      
       *(.mcu_code)
      . = ALIGN(4);
    } > cpu4_local_imem
    .ROM.mcu_code  ROM(.mcu_code ) : > bsw_flash

    .rdc_code :  
    {
      . = ALIGN(4);
       *(.rdc_code)
      . = ALIGN(4);
    } > cpu5_local_imem
    .ROM.rdc_code  ROM(.rdc_code ) : > bsw_flash



    .rdc_bss :  
    {
      . = ALIGN(4);
       *(.rdc_bss)
      . = ALIGN(4);
    } > cpu5_local_dmem

    .rdc_data :  
    {
      . = ALIGN(4);
       *(.rdc_data)
      . = ALIGN(4);
    } > cpu5_local_dmem
    .ROM.rdc_data  ROM(.rdc_data ) : > bsw_flash   


/*-------- LABELS USED IN CODE -------------------------------*/

/* Labels Used for Initialising SRAM ECC */
__SYSRAM_USED_SIZE = CPU_SRAM_SIZE;
__SYSRAM_KEEP_SIZE = 0;
__SYSRAM_ADDR = CPU_SRAM_BASE_ADDR;

__I_MEM0_USED_SIZE = CPU_CORE_0_ITCM_SIZE;
__I_MEM0_KEEP_SIZE = 0;
__I_MEM0_ADDR = CPU_CORE_0_ITCM_BASE_ADDR;

__D_MEM0_USED_SIZE = CPU_CORE_0_DTCM_SIZE;
__D_MEM0_KEEP_SIZE = 0;
__D_MEM0_ADDR = CPU_CORE_0_DTCM_BASE_ADDR;

__I_MEM1_USED_SIZE = CPU_CORE_1_ITCM_SIZE;
__I_MEM1_KEEP_SIZE = 0;
__I_MEM1_ADDR = CPU_CORE_1_ITCM_BASE_ADDR;

__D_MEM1_USED_SIZE = CPU_CORE_1_DTCM_SIZE;
__D_MEM1_KEEP_SIZE = 0;
__D_MEM1_ADDR = CPU_CORE_1_DTCM_BASE_ADDR;

__I_MEM2_USED_SIZE = CPU_CORE_2_ITCM_SIZE;
__I_MEM2_KEEP_SIZE = 0;
__I_MEM2_ADDR = CPU_CORE_2_ITCM_BASE_ADDR;

__D_MEM2_USED_SIZE = CPU_CORE_2_DTCM_SIZE;
__D_MEM2_KEEP_SIZE = 0;
__D_MEM2_ADDR = CPU_CORE_2_DTCM_BASE_ADDR;

__I_MEM3_USED_SIZE = CPU_CORE_3_ITCM_SIZE;
__I_MEM3_KEEP_SIZE = 0;
__I_MEM3_ADDR = CPU_CORE_3_ITCM_BASE_ADDR;

__D_MEM3_USED_SIZE = CPU_CORE_3_DTCM_SIZE - CPU_RESET_KEEP_SIZE;
__D_MEM3_KEEP_SIZE = CPU_RESET_KEEP_SIZE;
__D_MEM3_ADDR = CPU_CORE_3_DTCM_BASE_ADDR;

__I_MEM4_USED_SIZE = CPU_CORE_4_ITCM_SIZE;
__I_MEM4_KEEP_SIZE = 0;
__I_MEM4_ADDR = CPU_CORE_4_ITCM_BASE_ADDR;

__D_MEM4_USED_SIZE = CPU_CORE_4_DTCM_SIZE;
__D_MEM4_KEEP_SIZE = 0;
__D_MEM4_ADDR = CPU_CORE_4_DTCM_BASE_ADDR;

__I_MEM5_USED_SIZE = CPU_CORE_5_ITCM_SIZE;
__I_MEM5_KEEP_SIZE = 0;
__I_MEM5_ADDR = CPU_CORE_5_ITCM_BASE_ADDR;

__D_MEM5_USED_SIZE = CPU_CORE_5_DTCM_SIZE;
__D_MEM5_KEEP_SIZE = 0;
__D_MEM5_ADDR = CPU_CORE_5_DTCM_BASE_ADDR;


/* Labels for Copying Initialised Data from Flash to RAM */
__INTC_VECTOR_TABLE_SIZE = SIZEOF(.intc_vector_table);
__INTC_VECTOR_TABLE_RAM_ADDR = ADDR(.intc_vector_table);
__INTC_VECTOR_TABLE_ROM_ADDR = ADDR(.ROM.intc_vector_table);

/* __CAL_DATA_SIZE = SIZEOF(.cal_section); */
__CAL_DATA_SIZE = CPU_CALIBRATION_FLASH_SIZE;
__CAL_DATA_RAM_ADDR = ADDR(.cal_section);
__CAL_DATA_ROM_ADDR = ADDR(.ROM.cal_section);

__SAFCODE_USEVAR_SIZE = SIZEOF(.safcode_useVar);
__SAFCODE_USEVAR_RAM_ADDR = ADDR(.safcode_useVar);
__SAFCODE_USEVAR_ROM_ADDR = ADDR(.ROM.safcode_useVar);

__BSW_DATA_ASILA_SIZE = SIZEOF(.bsw_data_safety_asila);
__BSW_DATA_ASILA_RAM_ADDR = ADDR(.bsw_data_safety_asila);
__BSW_DATA_ASILA_ROM_ADDR = ADDR(.ROM.bsw_data_safety_asila);

__BSW_DATA_ASILB_SIZE = SIZEOF(.bsw_data_safety_asilb);
__BSW_DATA_ASILB_RAM_ADDR = ADDR(.bsw_data_safety_asilb);
__BSW_DATA_ASILB_ROM_ADDR = ADDR(.ROM.bsw_data_safety_asilb);

__BSW_DATA_ASILC_SIZE = SIZEOF(.bsw_data_safety_asilc);
__BSW_DATA_ASILC_RAM_ADDR = ADDR(.bsw_data_safety_asilc);
__BSW_DATA_ASILC_ROM_ADDR = ADDR(.ROM.bsw_data_safety_asilc);

__BSW_DATA_GLOBAL_SIZE = SIZEOF(.bsw_data_safety_global);
__BSW_DATA_GLOBAL_RAM_ADDR = ADDR(.bsw_data_safety_global);
__BSW_DATA_GLOBAL_ROM_ADDR = ADDR(.ROM.bsw_data_safety_global);

__ASW_DATA_ASILA_SIZE = SIZEOF(.asw_data_safety_asila);
__ASW_DATA_ASILA_RAM_ADDR = ADDR(.asw_data_safety_asila);
__ASW_DATA_ASILA_ROM_ADDR = ADDR(.ROM.asw_data_safety_asila);

__ASW_DATA_ASILB_SIZE = SIZEOF(.asw_data_safety_asilb);
__ASW_DATA_ASILB_RAM_ADDR = ADDR(.asw_data_safety_asilb);
__ASW_DATA_ASILB_ROM_ADDR = ADDR(.ROM.asw_data_safety_asilb);

__ASW_DATA_ASILC_SIZE = SIZEOF(.asw_data_safety_asilc);
__ASW_DATA_ASILC_RAM_ADDR = ADDR(.asw_data_safety_asilc);
__ASW_DATA_ASILC_ROM_ADDR = ADDR(.ROM.asw_data_safety_asilc);

__ASW_DATA_GLOBAL_SIZE = SIZEOF(.asw_data_safety_global);
__ASW_DATA_GLOBAL_RAM_ADDR = ADDR(.asw_data_safety_global);
__ASW_DATA_GLOBAL_ROM_ADDR = ADDR(.ROM.asw_data_safety_global);

__ASW_DATA_QM_SIZE = SIZEOF(.asw_data_safety_qm);
__ASW_DATA_QM_RAM_ADDR = ADDR(.asw_data_safety_qm);
__ASW_DATA_QM_ROM_ADDR = ADDR(.ROM.asw_data_safety_qm);

__DATA_SIZE = SIZEOF(.data);
__DATA_RAM_ADDR = ADDR(.data);
__DATA_ROM_ADDR = ADDR(.ROM.data);

__DATA_SHARE_SIZE = SIZEOF(.data_share);
__DATA_SHARE_RAM_ADDR = ADDR(.data_share);
__DATA_SHARE_ROM_ADDR = ADDR(.ROM.data_share);

__SDATA_SIZE = SIZEOF(.sdata);
__SDATA_RAM_ADDR = ADDR(.sdata);
__SDATA_ROM_ADDR = ADDR(.ROM.sdata);

__SDATA2_SIZE = SIZEOF(.sdata2);
__SDATA2_RAM_ADDR = ADDR(.sdata2);
__SDATA2_ROM_ADDR = ADDR(.ROM.sdata2);

__ALGORITH_RAM_SIZE = SIZEOF(.algorith_ram);
__ALGORITH_RAM_RAM_ADDR = ADDR(.algorith_ram);
__ALGORITH_RAM_ROM_ADDR = ADDR(.ROM.algorith_ram);

/*FOC_bss*/
__FOC_BSS_SIZE   = SIZEOF(.foc_bss);
__FOC_BSS_SRAM_ADDR  = ADDR(.foc_bss);


/*FOC_data*/
__FOC_DATA_ROM_ADDR  = ADDR(.ROM.foc_data);
__FOC_DATA_SIZE   = SIZEOF(.foc_data);
__FOC_DATA_SRAM_ADDR  = ADDR(.foc_data);

/*RDC-DATA*/
__RDC_DATA_ROM_ADDR  = ADDR(.ROM.rdc_data);
__RDC_DATA_SIZE   = SIZEOF(.rdc_data);
__RDC_DATA_SRAM_ADDR  = ADDR(.rdc_data);

/*RDC_bss*/
__RDC_BSS_SIZE   = SIZEOF(.rdc_bss);
__RDC_BSS_SRAM_ADDR  = ADDR(.rdc_bss);

/*RDC_code*/
__RDC_CODE_ROM_ADDR  = ADDR(.ROM.rdc_code);
__RDC_CODE_SIZE   = SIZEOF(.rdc_code);
__RDC_CODE_SRAM_ADDR  = ADDR(.rdc_code);

/*MCU_code*/
__MCU_CODE_ROM_ADDR  = ADDR(.ROM.mcu_code);
__MCU_CODE_SIZE   = SIZEOF(.mcu_code);
__MCU_CODE_SRAM_ADDR  = ADDR(.mcu_code);


/* Labels for Init blank section Data */
__MEA_DATA_SIZE = ((SIZEOF(.XCP_OBS) + 3) / 4) * 4;
__MEA_DATA_RAM_ADDR = ADDR(.XCP_OBS);

__BSW_BSS_ASILA_SIZE = SIZEOF(.bsw_bss_safety_asila);
__BSW_BSS_ASILA_RAM_ADDR = ADDR(.bsw_bss_safety_asila);

__BSW_BSS_ASILB_SIZE = SIZEOF(.bsw_bss_safety_asilb);
__BSW_BSS_ASILB_RAM_ADDR = ADDR(.bsw_bss_safety_asilb);

__BSW_BSS_ASILC_SIZE = SIZEOF(.bsw_bss_safety_asilc);
__BSW_BSS_ASILC_RAM_ADDR = ADDR(.bsw_bss_safety_asilc);

__BSW_BSS_GLOBAL_SIZE = SIZEOF(.bsw_bss_safety_global);
__BSW_BSS_GLOBAL_RAM_ADDR = ADDR(.bsw_bss_safety_global);

__ASW_BSS_ASILA_SIZE = SIZEOF(.asw_bss_safety_asila);
__ASW_BSS_ASILA_RAM_ADDR = ADDR(.asw_bss_safety_asila);

__ASW_BSS_ASILB_SIZE = SIZEOF(.asw_bss_safety_asilb);
__ASW_BSS_ASILB_RAM_ADDR = ADDR(.asw_bss_safety_asilb);

__ASW_BSS_ASILC_SIZE = SIZEOF(.asw_bss_safety_asilc);
__ASW_BSS_ASILC_RAM_ADDR = ADDR(.asw_bss_safety_asilc);

__ASW_BSS_GLOBAL_SIZE = SIZEOF(.asw_bss_safety_global);
__ASW_BSS_GLOBAL_RAM_ADDR = ADDR(.asw_bss_safety_global);

__ASW_BSS_QM_SIZE = SIZEOF(.asw_bss_safety_qm);
__ASW_BSS_QM_RAM_ADDR = ADDR(.asw_bss_safety_qm);

__BSS_SHARE_SIZE = SIZEOF(.bss_share);
__BSS_SHARE_RAM_ADDR = ADDR(.bss_share);

__BSS_SIZE = SIZEOF(.bss);
__BSS_RAM_ADDR = ADDR(.bss);

__SBSS2_SIZE = SIZEOF(.sbss2);
__SBSS2_RAM_ADDR = ADDR(.sbss2);

__BSS_OS_SIZE = SIZEOF(.bss_os);
__BSS_OS_RAM_ADDR = ADDR(.bss_os);

__EE_BLOCK_SIZE = CPU_DMEM3_EEPROM_RAM_SIZE;
__EE_BLOCK_RAM_ADDR = CPU_DMEM3_EEPROM_RAM_BASE_ADDR;

__RESET_KEEP_SIZE = CPU_RESET_KEEP_SIZE;
__RESET_KEEP_RAM_ADDR = ADDR(.reset_keep);


/* 用于内存保护 */
BSW_ASILC_DATA_START = ADDR(.bsw_bss_safety_asilc);
BSW_ASILC_DATA_END = ENDADDR(.bsw_data_safety_asilc);
ASILA_DATA_START = ADDR(.asw_bss_safety_asila);
ASILA_DATA_END  = ENDADDR(.asw_data_safety_asila);
ASILC_DATA_START = ADDR(.asw_bss_safety_asilc);
ASILC_DATA_END  = ENDADDR(.asw_data_safety_asilc);
ASILG_DATA_START  = ADDR(.asw_bss_safety_global);
ASILG_DATA_END = ENDADDR(.asw_data_safety_global);
ASILQ_DATA_START = ADDR(.asw_bss_safety_qm);
ASILQ_DATA_END = ENDADDR(.asw_data_safety_qm);

DEFAULTS_DATA_START = ADDR(.bss);
DEFAULTS_DATA_END = ADDR(.bsw_bss_safety_asilc)  - 1;

DEFAULTS1_DATA_START = ENDADDR(.bsw_bss_safety_asilc) + 1;
DEFAULTS1_DATA_END = ADDR(.asw_bss_safety_asilc) - 1;

DEFAULTS2_DATA_START = ENDADDR(.asw_bss_safety_asilc) + 1;
DEFAULTS2_DATA_END = ENDADDR(.ee_Block131_data);

BSW_ASILC_CODE_START = ADDR(.bsw_flash_safety_asilc);
BSW_ASILC_CODE_END = ENDADDR(.bsw_flash_safety_asilc);
ASILA_CODE_START = ADDR(.asw_flash_safety_asila);
ASILA_CODE_END  = ENDADDR(.asw_flash_safety_asila);
ASILC_CODE_START  = ADDR(.asw_flash_safety_asilc);
ASILC_CODE_END  = ENDADDR(.asw_flash_safety_asilc);
ASILG_CODE_START  = ADDR(.asw_flash_safety_global);
ASILG_CODE_END = ENDADDR(.asw_flash_safety_global);
ASILQ_CODE_START = ADDR(.asw_flash_safety_qm);
ASILQ_CODE_END = ENDADDR(.asw_flash_safety_qm);

DEFAULTS_CODE_START = ADDR(.startup);
DEFAULTS_CODE_END = ADDR(.bsw_flash_safety_asilc) - 1;

DEFAULTS1_CODE_START = ENDADDR(.bsw_flash_safety_asilc) + 1;
DEFAULTS1_CODE_END = ADDR(.asw_flash_safety_asilc) - 1;

DEFAULTS2_CODE_START = ENDADDR(.asw_flash_safety_asilc) + 1;
DEFAULTS2_CODE_END = ADDR(.ROM.safcode_useVar) - 1;
}



/**
* @file Saf_MemMap.h
* @version 1.0.1
**@brief   AUTOSAR MCU Rte - module interface.
* @details This file mainly contains reentrant interfaces and multi - core mutually exclusive interface definitions
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
* @addtogroup
* @{
*/
/****************************************************************************
*
* Copyright (c) 2022  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           :
*   Dependencies         :
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     :
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Saf_MemMap.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Rte MCAL driver.
*
*   @addtogroup Rte
*   @{
*/
/*====================================================================================================
                                            INCLUDE FILES
====================================================================================================*/
#ifdef __cplusplus
extern "C" {
#endif
#include "CompilerDefinition.h"

/*====================================================================================================
                                        DISABLE WARNING START
====================================================================================================*/
#ifdef GHS_C_CCFC30XX
#pragma ghs nowarning 1512
#endif
/*====================================================================================================
                                    SOURCE FILE VERSION INFORMATION
====================================================================================================*/
/*====================================================================================================
                                         FILE VERSION CHECKS
====================================================================================================*/
/*====================================================================================================
                                             LOCAL MACROS
====================================================================================================*/
#define SAF_MEMMAP_SECTION_NOTMATCH_ERROR   "Saf_MemMap.h, start - stop section defined not match."
#define MEM_ERROR

#ifdef S32DS_C_CCFC30XX
#define SAF_SEC_CONFIG_DATA           __attribute__ ((section (".saf_rodata")))
#define SAF_SEC_CODE                  __attribute__ ((section (".saf_text")))
#define SAF_SEC_VAR_NO_INIT           __attribute__ ((section (".saf_bss")))
#define SAF_SEC_VAR_INIT              __attribute__ ((section (".saf_data")))
#define SAF_SEC_VAR_SHARED_INIT       __attribute__ ((section (".saf_data_share")))
#define SAF_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".saf_data_share")))
#define SAF_SEC_RAMCODE               __attribute__ ((section (".saf_ramcode")))

/*.rodata*/
#define SAF_ADC_SEC_CONFIG_DATA          __attribute__ ((section (".saf_adc_rodata")))
#define SAF_BIST_SEC_CONFIG_DATA         __attribute__ ((section (".saf_bist_rodata")))
#define SAF_CACHE_SEC_CONFIG_DATA        __attribute__ ((section (".saf_cache_rodata")))
#define SAF_MCU_SEC_CONFIG_DATA          __attribute__ ((section (".saf_mcu_rodata")))
#define SAF_CMU_SEC_CONFIG_DATA          __attribute__ ((section (".saf_cmu_rodata")))
#define SAF_CORE_SEC_CONFIG_DATA         __attribute__ ((section (".saf_core_rodata")))
#define SAF_CRC_SEC_CONFIG_DATA          __attribute__ ((section (".saf_crc_rodata")))
#define SAF_CMPU_SEC_CONFIG_DATA         __attribute__ ((section (".saf_cmpu_rodata")))
#define SAF_DMA_SEC_CONFIG_DATA          __attribute__ ((section (".saf_dma_rodata")))
#define SAF_FCCU_SEC_CONFIG_DATA         __attribute__ ((section (".saf_fccu_rodata")))
#define SAF_FLASH_SEC_CONFIG_DATA        __attribute__ ((section (".saf_flash_rodata")))
#define SAF_INTC_SEC_CONFIG_DATA         __attribute__ ((section (".saf_intc_rodata")))
#define SAF_MEM_SEC_CONFIG_DATA          __attribute__ ((section (".saf_mem_rodata")))
#define SAF_MEMU_SEC_CONFIG_DATA         __attribute__ ((section (".saf_memu_rodata")))
#define SAF_OSC_SEC_CONFIG_DATA          __attribute__ ((section (".saf_osc_rodata")))
#define SAF_PIT_SEC_CONFIG_DATA          __attribute__ ((section (".saf_pit_rodata")))
#define SAF_PLL_SEC_CONFIG_DATA          __attribute__ ((section (".saf_pll_rodata")))
#define SAF_PMC_SEC_CONFIG_DATA          __attribute__ ((section (".saf_pmc_rodata")))
#define SAF_RAM_SEC_CONFIG_DATA          __attribute__ ((section (".saf_ram_rodata")))
#define SAF_REGPROT_SEC_CONFIG_DATA      __attribute__ ((section (".saf_regprot_rodata")))
#define SAF_SCH_SEC_CONFIG_DATA          __attribute__ ((section (".saf_sch_rodata")))
#define SAF_SMPU_SEC_CONFIG_DATA         __attribute__ ((section (".saf_smpu_rodata")))
#define SAF_STACK_SEC_CONFIG_DATA        __attribute__ ((section (".saf_stack_rodata")))
#define SAF_STM_SEC_CONFIG_DATA          __attribute__ ((section (".saf_stm_rodata")))
#define SAF_SWT_SEC_CONFIG_DATA          __attribute__ ((section (".saf_swt_rodata")))
#define SAF_TSENS_SEC_CONFIG_DATA        __attribute__ ((section (".saf_tsens_rodata")))


/*.text*/
#define SAF_ADC_SEC_CODE              __attribute__ ((section (".saf_adc_text")))
#define SAF_BIST_SEC_CODE             __attribute__ ((section (".saf_bist_text")))
#define SAF_CACHE_SEC_CODE            __attribute__ ((section (".saf_cache_text")))
#define SAF_MCU_SEC_CODE              __attribute__ ((section (".saf_mcu_text")))
#define SAF_CMU_SEC_CODE              __attribute__ ((section (".saf_cmu_text")))
#define SAF_CORE_SEC_CODE             __attribute__ ((section (".saf_core_text")))
#define SAF_CRC_SEC_CODE              __attribute__ ((section (".saf_crc_text")))
#define SAF_CMPU_SEC_CODE             __attribute__ ((section (".saf_cmpu_text")))
#define SAF_DMA_SEC_CODE              __attribute__ ((section (".saf_dma_text")))
#define SAF_FCCU_SEC_CODE             __attribute__ ((section (".saf_fccu_text")))
#define SAF_FLASH_SEC_CODE            __attribute__ ((section (".saf_flash_text")))
#define SAF_INTC_SEC_CODE             __attribute__ ((section (".saf_intc_text")))
#define SAF_MEM_SEC_CODE              __attribute__ ((section (".saf_mem_text")))
#define SAF_MEMU_SEC_CODE             __attribute__ ((section (".saf_memu_text")))
#define SAF_OSC_SEC_CODE              __attribute__ ((section (".saf_osc_text")))
#define SAF_PIT_SEC_CODE              __attribute__ ((section (".saf_pit_text")))
#define SAF_PLL_SEC_CODE              __attribute__ ((section (".saf_pll_text")))
#define SAF_PMC_SEC_CODE              __attribute__ ((section (".saf_pmc_text")))
#define SAF_RAM_SEC_CODE              __attribute__ ((section (".saf_ram_text")))
#define SAF_REGPROT_SEC_CODE          __attribute__ ((section (".saf_regprot_text")))
#define SAF_SCH_SEC_CODE              __attribute__ ((section (".saf_sch_text")))
#define SAF_SMPU_SEC_CODE             __attribute__ ((section (".saf_smpu_text")))
#define SAF_STACK_SEC_CODE            __attribute__ ((section (".saf_stack_text")))
#define SAF_STM_SEC_CODE              __attribute__ ((section (".saf_stm_text")))
#define SAF_SWT_SEC_CODE              __attribute__ ((section (".saf_swt_text")))
#define SAF_TSENS_SEC_CODE            __attribute__ ((section (".saf_tsens_text")))

/*.bss*/
#define SAF_ADC_SEC_VAR_NO_INIT          __attribute__ ((section (".saf_adc_bss")))
#define SAF_BIST_SEC_VAR_NO_INIT         __attribute__ ((section (".saf_bist_bss")))
#define SAF_CACHE_SEC_VAR_NO_INIT        __attribute__ ((section (".saf_cache_bss")))
#define SAF_MCU_SEC_VAR_NO_INIT          __attribute__ ((section (".saf_mcu_bss")))
#define SAF_CMU_SEC_VAR_NO_INIT          __attribute__ ((section (".saf_cmu_bss")))
#define SAF_CORE_SEC_VAR_NO_INIT         __attribute__ ((section (".saf_core_bss")))
#define SAF_CRC_SEC_VAR_NO_INIT          __attribute__ ((section (".saf_crc_bss")))
#define SAF_CMPU_SEC_VAR_NO_INIT         __attribute__ ((section (".saf_cmpu_bss")))
#define SAF_DMA_SEC_VAR_NO_INIT          __attribute__ ((section (".saf_dma_bss")))
#define SAF_FCCU_SEC_VAR_NO_INIT         __attribute__ ((section (".saf_fccu_bss")))
#define SAF_FLASH_SEC_VAR_NO_INIT        __attribute__ ((section (".saf_flash_bss")))
#define SAF_INTC_SEC_VAR_NO_INIT         __attribute__ ((section (".saf_intc_bss")))
#define SAF_MEM_SEC_VAR_NO_INIT          __attribute__ ((section (".saf_mem_bss")))
#define SAF_MEMU_SEC_VAR_NO_INIT         __attribute__ ((section (".saf_memu_bss")))
#define SAF_OSC_SEC_VAR_NO_INIT          __attribute__ ((section (".saf_osc_bss")))
#define SAF_PIT_SEC_VAR_NO_INIT          __attribute__ ((section (".saf_pit_bss")))
#define SAF_PLL_SEC_VAR_NO_INIT          __attribute__ ((section (".saf_pll_bss")))
#define SAF_PMC_SEC_VAR_NO_INIT          __attribute__ ((section (".saf_pmc_bss")))
#define SAF_RAM_SEC_VAR_NO_INIT          __attribute__ ((section (".saf_ram_bss")))
#define SAF_REGPROT_SEC_VAR_NO_INIT      __attribute__ ((section (".saf_regprot_bss")))
#define SAF_SCH_SEC_VAR_NO_INIT          __attribute__ ((section (".saf_sch_bss")))
#define SAF_SMPU_SEC_VAR_NO_INIT         __attribute__ ((section (".saf_smpu_bss")))
#define SAF_STACK_SEC_VAR_NO_INIT        __attribute__ ((section (".saf_stack_bss")))
#define SAF_STM_SEC_VAR_NO_INIT          __attribute__ ((section (".saf_stm_bss")))
#define SAF_SWT_SEC_VAR_NO_INIT          __attribute__ ((section (".saf_swt_bss")))
#define SAF_TSENS_SEC_VAR_NO_INIT        __attribute__ ((section (".saf_tsens_bss")))

/*.data*/
#define SAF_ADC_SEC_VAR_INIT             __attribute__ ((section (".saf_adc_data")))
#define SAF_BIST_SEC_VAR_INIT            __attribute__ ((section (".saf_bist_data")))
#define SAF_CACHE_SEC_VAR_INIT           __attribute__ ((section (".saf_cache_data")))
#define SAF_MCU_SEC_VAR_INIT             __attribute__ ((section (".saf_mcu_data")))
#define SAF_CMU_SEC_VAR_INIT             __attribute__ ((section (".saf_cmu_data")))
#define SAF_CORE_SEC_VAR_INIT            __attribute__ ((section (".saf_core_data")))
#define SAF_CRC_SEC_VAR_INIT             __attribute__ ((section (".saf_crc_data")))
#define SAF_CMPU_SEC_VAR_INIT            __attribute__ ((section (".saf_cmpu_data")))
#define SAF_DMA_SEC_VAR_INIT             __attribute__ ((section (".saf_dma_data")))
#define SAF_FCCU_SEC_VAR_INIT            __attribute__ ((section (".saf_fccu_data")))
#define SAF_FLASH_SEC_VAR_INIT           __attribute__ ((section (".saf_flash_data")))
#define SAF_INTC_SEC_VAR_INIT            __attribute__ ((section (".saf_intc_data")))
#define SAF_MEM_SEC_VAR_INIT             __attribute__ ((section (".saf_mem_data")))
#define SAF_MEMU_SEC_VAR_INIT            __attribute__ ((section (".saf_memu_data")))
#define SAF_OSC_SEC_VAR_INIT             __attribute__ ((section (".saf_osc_data")))
#define SAF_PIT_SEC_VAR_INIT             __attribute__ ((section (".saf_pit_data")))
#define SAF_PLL_SEC_VAR_INIT             __attribute__ ((section (".saf_pll_data")))
#define SAF_PMC_SEC_VAR_INIT             __attribute__ ((section (".saf_pmc_data")))
#define SAF_RAM_SEC_VAR_INIT             __attribute__ ((section (".saf_ram_data")))
#define SAF_REGPROT_SEC_VAR_INIT         __attribute__ ((section (".saf_regprot_data")))
#define SAF_SCH_SEC_VAR_INIT             __attribute__ ((section (".saf_sch_data")))
#define SAF_SMPU_SEC_VAR_INIT            __attribute__ ((section (".saf_smpu_data")))
#define SAF_STACK_SEC_VAR_INIT           __attribute__ ((section (".saf_stack_data")))
#define SAF_STM_SEC_VAR_INIT             __attribute__ ((section (".saf_stm_data")))
#define SAF_SWT_SEC_VAR_INIT             __attribute__ ((section (".saf_swt_data")))
#define SAF_TSENS_SEC_VAR_INIT           __attribute__ ((section (".saf_tsens_data")))

#endif

/*************************************************************************************************/
/*                                       GREENHILLS                                              */
/*************************************************************************************************/
#ifdef GHS_C_CCFC30XX
#define SAF_SEC_CONFIG_DATA           _Pragma("ghs section rodata=\".saf_rodata\"")
#define SAF_SEC_CODE                  _Pragma("ghs section text=\".saf_text\"")
#define SAF_SEC_VAR_NO_INIT           _Pragma("ghs section bss=\".saf_bss\"")
#define SAF_SEC_VAR_INIT              _Pragma("ghs section data=\".saf_data\"")
#define SAF_SEC_VAR_SHARED_INIT       _Pragma("ghs section data=\".saf_share_data\"")
#define SAF_SEC_VAR_SHARED_NO_INIT    _Pragma("ghs section data=\".saf_share_data\"")
#define SAF_SEC_RAMCODE               _Pragma("ghs section text=\".saf_ramcode\"")

/*.rodata*/
#define SAF_ADC_SEC_CONFIG_DATA          _Pragma("ghs section rodata=\".saf_adc_rodata\"")
#define SAF_BIST_SEC_CONFIG_DATA         _Pragma("ghs section rodata=\".saf_bist_rodata\"")
#define SAF_CACHE_SEC_CONFIG_DATA        _Pragma("ghs section rodata=\".saf_cache_rodata\"")
#define SAF_MCU_SEC_CONFIG_DATA          _Pragma("ghs section rodata=\".saf_mcu_rodata\"")
#define SAF_CMU_SEC_CONFIG_DATA          _Pragma("ghs section rodata=\".saf_cmu_rodata\"")
#define SAF_CORE_SEC_CONFIG_DATA         _Pragma("ghs section rodata=\".saf_core_rodata\"")
#define SAF_CRC_SEC_CONFIG_DATA          _Pragma("ghs section rodata=\".saf_crc_rodata\"")
#define SAF_CMPU_SEC_CONFIG_DATA         _Pragma("ghs section rodata=\".saf_cmpu_rodata\"")
#define SAF_DMA_SEC_CONFIG_DATA          _Pragma("ghs section rodata=\".saf_dma_rodata\"")
#define SAF_FCCU_SEC_CONFIG_DATA         _Pragma("ghs section rodata=\".saf_fccu_rodata\"")
#define SAF_FLASH_SEC_CONFIG_DATA        _Pragma("ghs section rodata=\".saf_flash_rodata\"")
#define SAF_INTC_SEC_CONFIG_DATA         _Pragma("ghs section rodata=\".saf_intc_rodata\"")
#define SAF_MEM_SEC_CONFIG_DATA          _Pragma("ghs section rodata=\".saf_mem_rodata\"")
#define SAF_MEMU_SEC_CONFIG_DATA         _Pragma("ghs section rodata=\".saf_memu_rodata\"")
#define SAF_OSC_SEC_CONFIG_DATA          _Pragma("ghs section rodata=\".saf_osc_rodata\"")
#define SAF_PIT_SEC_CONFIG_DATA          _Pragma("ghs section rodata=\".saf_pit_rodata\"")
#define SAF_PLL_SEC_CONFIG_DATA          _Pragma("ghs section rodata=\".saf_pll_rodata\"")
#define SAF_PMC_SEC_CONFIG_DATA          _Pragma("ghs section rodata=\".saf_pmc_rodata\"")
#define SAF_RAM_SEC_CONFIG_DATA          _Pragma("ghs section rodata=\".saf_ram_rodata\"")
#define SAF_REGPROT_SEC_CONFIG_DATA      _Pragma("ghs section rodata=\".saf_regprot_rodata\"")
#define SAF_SCH_SEC_CONFIG_DATA          _Pragma("ghs section rodata=\".saf_sch_rodata\"")
#define SAF_SMPU_SEC_CONFIG_DATA         _Pragma("ghs section rodata=\".saf_smpu_rodata\"")
#define SAF_STACK_SEC_CONFIG_DATA        _Pragma("ghs section rodata=\".saf_stack_rodata\"")
#define SAF_STM_SEC_CONFIG_DATA          _Pragma("ghs section rodata=\".saf_stm_rodata\"")
#define SAF_SWT_SEC_CONFIG_DATA          _Pragma("ghs section rodata=\".saf_swt_rodata\"")
#define SAF_TSENS_SEC_CONFIG_DATA        _Pragma("ghs section rodata=\".saf_tsens_rodata\"")

/*.text*/
#define SAF_ADC_SEC_CODE              _Pragma("ghs section text=\".saf_adc_text\"")
#define SAF_BIST_SEC_CODE             _Pragma("ghs section text=\".saf_bist_text\"")
#define SAF_CACHE_SEC_CODE            _Pragma("ghs section text=\".saf_cache_text\"")
#define SAF_MCU_SEC_CODE              _Pragma("ghs section text=\".saf_mcu_text\"")
#define SAF_CMU_SEC_CODE              _Pragma("ghs section text=\".saf_cmu_text\"")
#define SAF_CORE_SEC_CODE             _Pragma("ghs section text=\".saf_core_text\"")
#define SAF_CRC_SEC_CODE              _Pragma("ghs section text=\".saf_crc_text\"")
#define SAF_CMPU_SEC_CODE             _Pragma("ghs section text=\".saf_cmpu_text\"")
#define SAF_DMA_SEC_CODE              _Pragma("ghs section text=\".saf_dma_text\"")
#define SAF_FCCU_SEC_CODE             _Pragma("ghs section text=\".saf_fccu_text\"")
#define SAF_FLASH_SEC_CODE            _Pragma("ghs section text=\".saf_flash_text\"")
#define SAF_INTC_SEC_CODE             _Pragma("ghs section text=\".saf_intc_text\"")
#define SAF_MEM_SEC_CODE              _Pragma("ghs section text=\".saf_mem_text\"")
#define SAF_MEMU_SEC_CODE             _Pragma("ghs section text=\".saf_memu_text\"")
#define SAF_OSC_SEC_CODE              _Pragma("ghs section text=\".saf_osc_text\"")
#define SAF_PIT_SEC_CODE              _Pragma("ghs section text=\".saf_pit_text\"")
#define SAF_PLL_SEC_CODE              _Pragma("ghs section text=\".saf_pll_text\"")
#define SAF_PMC_SEC_CODE              _Pragma("ghs section text=\".saf_pmc_text\"")
#define SAF_RAM_SEC_CODE              _Pragma("ghs section text=\".saf_ram_text\"")
#define SAF_REGPROT_SEC_CODE          _Pragma("ghs section text=\".saf_regprot_text\"")
#define SAF_SCH_SEC_CODE              _Pragma("ghs section text=\".saf_sch_text\"")
#define SAF_SMPU_SEC_CODE             _Pragma("ghs section text=\".saf_smpu_text\"")
#define SAF_STACK_SEC_CODE            _Pragma("ghs section text=\".saf_stack_text\"")
#define SAF_STM_SEC_CODE              _Pragma("ghs section text=\".saf_stm_text\"")
#define SAF_SWT_SEC_CODE              _Pragma("ghs section text=\".saf_swt_text\"")
#define SAF_TSENS_SEC_CODE            _Pragma("ghs section text=\".saf_tsens_text\"")

/*.bss*/
#define SAF_ADC_SEC_VAR_NO_INIT          _Pragma("ghs section bss=\".saf_adc_bss\"")
#define SAF_BIST_SEC_VAR_NO_INIT         _Pragma("ghs section bss=\".saf_bist_bss\"")
#define SAF_CACHE_SEC_VAR_NO_INIT        _Pragma("ghs section bss=\".saf_cache_bss\"")
#define SAF_MCU_SEC_VAR_NO_INIT          _Pragma("ghs section bss=\".saf_mcu_bss\"")
#define SAF_CMU_SEC_VAR_NO_INIT          _Pragma("ghs section bss=\".saf_cmu_bss\"")
#define SAF_CORE_SEC_VAR_NO_INIT         _Pragma("ghs section bss=\".saf_core_bss\"")
#define SAF_CRC_SEC_VAR_NO_INIT          _Pragma("ghs section bss=\".saf_crc_bss\"")
#define SAF_CMPU_SEC_VAR_NO_INIT         _Pragma("ghs section bss=\".saf_cmpu_bss\"")
#define SAF_DMA_SEC_VAR_NO_INIT          _Pragma("ghs section bss=\".saf_dma_bss\"")
#define SAF_FCCU_SEC_VAR_NO_INIT         _Pragma("ghs section bss=\".saf_fccu_bss\"")
#define SAF_FLASH_SEC_VAR_NO_INIT        _Pragma("ghs section bss=\".saf_flash_bss\"")
#define SAF_INTC_SEC_VAR_NO_INIT         _Pragma("ghs section bss=\".saf_intc_bss\"")
#define SAF_MEM_SEC_VAR_NO_INIT          _Pragma("ghs section bss=\".saf_mem_bss\"")
#define SAF_MEMU_SEC_VAR_NO_INIT         _Pragma("ghs section bss=\".saf_memu_bss\"")
#define SAF_OSC_SEC_VAR_NO_INIT          _Pragma("ghs section bss=\".saf_osc_bss\"")
#define SAF_PIT_SEC_VAR_NO_INIT          _Pragma("ghs section bss=\".saf_pit_bss\"")
#define SAF_PLL_SEC_VAR_NO_INIT          _Pragma("ghs section bss=\".saf_pll_bss\"")
#define SAF_PMC_SEC_VAR_NO_INIT          _Pragma("ghs section bss=\".saf_pmc_bss\"")
#define SAF_RAM_SEC_VAR_NO_INIT          _Pragma("ghs section bss=\".saf_ram_bss\"")
#define SAF_REGPROT_SEC_VAR_NO_INIT      _Pragma("ghs section bss=\".saf_regprot_bss\"")
#define SAF_SCH_SEC_VAR_NO_INIT          _Pragma("ghs section bss=\".saf_sch_bss\"")
#define SAF_SMPU_SEC_VAR_NO_INIT         _Pragma("ghs section bss=\".saf_smpu_bss\"")
#define SAF_STACK_SEC_VAR_NO_INIT        _Pragma("ghs section bss=\".saf_stack_bss\"")
#define SAF_STM_SEC_VAR_NO_INIT          _Pragma("ghs section bss=\".saf_stm_bss\"")
#define SAF_SWT_SEC_VAR_NO_INIT          _Pragma("ghs section bss=\".saf_swt_bss\"")
#define SAF_TSENS_SEC_VAR_NO_INIT        _Pragma("ghs section bss=\".saf_tsens_bss\"")

/*.data*/
#define SAF_ADC_SEC_VAR_INIT             _Pragma("ghs section data=\".saf_adc_data\"")
#define SAF_BIST_SEC_VAR_INIT            _Pragma("ghs section data=\".saf_bist_data\"")
#define SAF_CACHE_SEC_VAR_INIT           _Pragma("ghs section data=\".saf_cache_data\"")
#define SAF_MCU_SEC_VAR_INIT             _Pragma("ghs section data=\".saf_mcu_data\"")
#define SAF_CMU_SEC_VAR_INIT             _Pragma("ghs section data=\".saf_cmu_data\"")
#define SAF_CORE_SEC_VAR_INIT            _Pragma("ghs section data=\".saf_core_data\"")
#define SAF_CRC_SEC_VAR_INIT             _Pragma("ghs section data=\".saf_crc_data\"")
#define SAF_CMPU_SEC_VAR_INIT            _Pragma("ghs section data=\".saf_cmpu_data\"")
#define SAF_DMA_SEC_VAR_INIT             _Pragma("ghs section data=\".saf_dma_data\"")
#define SAF_FCCU_SEC_VAR_INIT            _Pragma("ghs section data=\".saf_fccu_data\"")
#define SAF_FLASH_SEC_VAR_INIT           _Pragma("ghs section data=\".saf_flash_data\"")
#define SAF_INTC_SEC_VAR_INIT            _Pragma("ghs section data=\".saf_intc_data\"")
#define SAF_MEM_SEC_VAR_INIT             _Pragma("ghs section data=\".saf_mem_data\"")
#define SAF_MEMU_SEC_VAR_INIT            _Pragma("ghs section data=\".saf_memu_data\"")
#define SAF_OSC_SEC_VAR_INIT             _Pragma("ghs section data=\".saf_osc_data\"")
#define SAF_PIT_SEC_VAR_INIT             _Pragma("ghs section data=\".saf_pit_data\"")
#define SAF_PLL_SEC_VAR_INIT             _Pragma("ghs section data=\".saf_pll_data\"")
#define SAF_PMC_SEC_VAR_INIT             _Pragma("ghs section data=\".saf_pmc_data\"")
#define SAF_RAM_SEC_VAR_INIT             _Pragma("ghs section data=\".saf_ram_data\"")
#define SAF_REGPROT_SEC_VAR_INIT         _Pragma("ghs section data=\".saf_regprot_data\"")
#define SAF_SCH_SEC_VAR_INIT             _Pragma("ghs section data=\".saf_sch_data\"")
#define SAF_SMPU_SEC_VAR_INIT            _Pragma("ghs section data=\".saf_smpu_data\"")
#define SAF_STACK_SEC_VAR_INIT           _Pragma("ghs section data=\".saf_stack_data\"")
#define SAF_STM_SEC_VAR_INIT             _Pragma("ghs section data=\".saf_stm_data\"")
#define SAF_SWT_SEC_VAR_INIT             _Pragma("ghs section data=\".saf_swt_data\"")
#define SAF_TSENS_SEC_VAR_INIT           _Pragma("ghs section data=\".saf_tsens_data\"")

#endif


/*************************************************************************************************/
/*                                         S32DS                                                 */
/*************************************************************************************************/
#ifdef S32DS_C_CCFC30XX
/**
* MCAL MemMap defined, Used for configure data,
* Used START_SEC_CONFIG_DATA must match with STOP_SEC_CONFIG_DATA 
*/
#ifdef SAF_START_SEC_CONFIG_DATA
    #undef SAF_START_SEC_CONFIG_DATA
    #define ENTERED_SAF_START_SEC_CONFIG_DATA
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef SAF_STOP_SEC_CONFIG_DATA
            #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        __attribute__ ((section (".saf_rodata")))
        /* no definition -> default compiler settings are used */
#endif

#ifdef SAF_STOP_SEC_CONFIG_DATA
    #ifdef ENTERED_SAF_START_SEC_CONFIG_DATA
        #undef ENTERED_SAF_START_SEC_CONFIG_DATA
    #else
        #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef SAF_STOP_SEC_CONFIG_DATA
    #undef MEM_ERROR
        /* no definition -> default compiler settings are used */
#endif

/**
* MCAL MemMap defined, Used for code data,
* Used START_SEC_CODE must match with STOP_SEC_CODE 
*/
#ifdef SAF_START_SEC_CODE
    #undef SAF_START_SEC_CODE
    #define ENTERED_SAF_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef SAF_STOP_SEC_CODE
            #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        __attribute__ ((section (".saf_text")))
        /* no definition -> default compiler settings are used */
#endif

#ifdef SAF_STOP_SEC_CODE
    #ifdef ENTERED_SAF_START_SEC_CODE
        #undef ENTERED_SAF_START_SEC_CODE
    #else
        #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef SAF_STOP_SEC_CODE
    #undef MEM_ERROR
        /* no definition -> default compiler settings are used */
#endif

/**
* MCAL MemMap defined, Used for noinit(bss) data,
* Used START_SEC_VAR_NO_INIT must match with STOP_SEC_VAR_NO_INIT 
*/
#ifdef SAF_START_SEC_VAR_NO_INIT
    #undef SAF_START_SEC_VAR_NO_INIT
    #define ENTERED_SAF_START_SEC_VAR_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef SAF_STOP_SEC_VAR_NO_INIT
            #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        __attribute__ ((section (".saf_bss")))
        /* no definition -> default compiler settings are used */
#endif

#ifdef SAF_STOP_SEC_VAR_NO_INIT
    #ifdef ENTERED_SAF_START_SEC_VAR_NO_INIT
        #undef ENTERED_SAF_START_SEC_VAR_NO_INIT
    #else
        #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef SAF_STOP_SEC_VAR_NO_INIT
    #undef MEM_ERROR
        /* no definition -> default compiler settings are used */
#endif

/**
* MCAL MemMap defined, Used for global init data,
* Used START_SEC_VAR_INIT must match with STOP_SEC_VAR_INIT 
*/
#ifdef SAF_START_SEC_VAR_INIT
    #undef SAF_START_SEC_VAR_INIT
    #define ENTERED_SAF_START_SEC_VAR_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef SAF_STOP_SEC_VAR_INIT
            #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        __attribute__ ((section (".saf_data")))
        /* no definition -> default compiler settings are used */
#endif

#ifdef SAF_STOP_SEC_VAR_INIT
    #ifdef ENTERED_SAF_START_SEC_VAR_INIT
        #undef ENTERED_SAF_START_SEC_VAR_INIT
    #else
        #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef SAF_STOP_SEC_VAR_INIT
    #undef MEM_ERROR
        /* no definition -> default compiler settings are used */
#endif

/**
* MCAL MemMap defined, Used for share init data,
* Used START_SEC_VAR_SHARED_INIT must match with STOP_SEC_VAR_SHARED_INIT 
*/
#ifdef SAF_START_SEC_VAR_SHARED_INIT
    #undef SAF_START_SEC_VAR_SHARED_INIT
    #define ENTERED_SAF_START_SEC_VAR_SHARED_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef SAF_STOP_SEC_VAR_SHARED_INIT
            #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        __attribute__ ((section (".saf_data_share")))
#endif

#ifdef SAF_STOP_SEC_VAR_SHARED_INIT
    #ifdef ENTERED_SAF_START_SEC_VAR_SHARED_INIT
        #undef ENTERED_SAF_START_SEC_VAR_SHARED_INIT
    #else
        #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef SAF_STOP_SEC_VAR_SHARED_INIT
    #undef MEM_ERROR
        /* no definition -> default compiler settings are used */
#endif

/**
* MCAL MemMap defined, Used for share zero data,
* Used START_SEC_VAR_SHARED_NO_INIT must match with STOP_SEC_VAR_SHARED_NO_INIT 
*/
#ifdef SAF_START_SEC_VAR_SHARED_NO_INIT
    #undef SAF_START_SEC_VAR_SHARED_NO_INIT
    #define ENTERED_SAF_START_SEC_VAR_SHARED_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef SAF_STOP_SEC_VAR_SHARED_NO_INIT
            #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        __attribute__ ((section (".saf_data_share")))
#endif

#ifdef SAF_STOP_SEC_VAR_SHARED_NO_INIT
    #ifdef ENTERED_SAF_START_SEC_VAR_SHARED_NO_INIT
        #undef ENTERED_SAF_START_SEC_VAR_SHARED_NO_INIT
    #else
        #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef SAF_STOP_SEC_VAR_SHARED_NO_INIT
    #undef MEM_ERROR
        /* no definition -> default compiler settings are used */
#endif

/**
* MCAL MemMap defined, Used for code running in ram,
* Used START_SEC_RAMCODE must match with STOP_SEC_RAMCODE 
*/
#ifdef SAF_START_SEC_RAMCODE
    #undef SAF_START_SEC_RAMCODE
    #define ENTERED_SAF_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef SAF_STOP_SEC_RAMCODE
            #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        __attribute__ ((section (".saf_ramcode")))
#endif

#ifdef SAF_STOP_SEC_RAMCODE
    #ifdef ENTERED_SAF_START_SEC_RAMCODE
        #undef ENTERED_SAF_START_SEC_RAMCODE
    #else
        #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef SAF_STOP_SEC_RAMCODE
    #undef MEM_ERROR
        /* no definition -> default compiler settings are used */
#endif

#endif /* S32DS_C_CCFC30XX */

/*************************************************************************************************/
/*                                       GREENHILLS                                              */
/*************************************************************************************************/
#ifdef GHS_C_CCFC30XX
/**
* MCAL MemMap defined, Used for configure data,
* Used START_SEC_CONFIG_DATA must match with STOP_SEC_CONFIG_DATA 
*/
#ifdef SAF_START_SEC_CONFIG_DATA
    #undef SAF_START_SEC_CONFIG_DATA
    #define ENTERED_SAF_START_SEC_CONFIG_DATA
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef SAF_STOP_SEC_CONFIG_DATA
            #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma ghs section rodata=".saf_rodata"
#endif

#ifdef SAF_STOP_SEC_CONFIG_DATA
    #ifdef ENTERED_SAF_START_SEC_CONFIG_DATA
        #undef ENTERED_SAF_START_SEC_CONFIG_DATA
    #else
        #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef SAF_STOP_SEC_CONFIG_DATA
    #undef MEM_ERROR
        #pragma ghs section
#endif

/**
* MCAL MemMap defined, Used for code data,
* Used START_SEC_CODE must match with STOP_SEC_CODE 
*/
#ifdef SAF_START_SEC_CODE
    #undef SAF_START_SEC_CODE
    #define ENTERED_SAF_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef SAF_STOP_SEC_CODE
            #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma ghs section rodata=".saf_text"
#endif

#ifdef SAF_STOP_SEC_CODE
    #ifdef ENTERED_SAF_START_SEC_CODE
        #undef ENTERED_SAF_START_SEC_CODE
    #else
        #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef SAF_STOP_SEC_CODE
    #undef MEM_ERROR
        #pragma ghs section
#endif

/**
* MCAL MemMap defined, Used for noinit(bss) data,
* Used START_SEC_VAR_NO_INIT must match with STOP_SEC_VAR_NO_INIT 
*/
#ifdef SAF_START_SEC_VAR_NO_INIT
    #undef SAF_START_SEC_VAR_NO_INIT
    #define ENTERED_SAF_START_SEC_VAR_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef SAF_STOP_SEC_VAR_NO_INIT
            #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma ghs section bss=".saf_bss"
#endif

#ifdef SAF_STOP_SEC_VAR_NO_INIT
    #ifdef ENTERED_SAF_START_SEC_VAR_NO_INIT
        #undef ENTERED_SAF_START_SEC_VAR_NO_INIT
    #else
        #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef SAF_STOP_SEC_VAR_NO_INIT
    #undef MEM_ERROR
        #pragma ghs section
#endif

/**
* MCAL MemMap defined, Used for global init data,
* Used START_SEC_VAR_INIT must match with STOP_SEC_VAR_INIT 
*/
#ifdef SAF_START_SEC_VAR_INIT
    #undef SAF_START_SEC_VAR_INIT
    #define ENTERED_SAF_START_SEC_VAR_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef SAF_STOP_SEC_VAR_INIT
            #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma ghs section data = ".saf_data"
#endif

#ifdef SAF_STOP_SEC_VAR_INIT
    #ifdef ENTERED_SAF_START_SEC_VAR_INIT
        #undef ENTERED_SAF_START_SEC_VAR_INIT
    #else
        #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef SAF_STOP_SEC_VAR_INIT
    #undef MEM_ERROR
        #pragma ghs section
#endif

/**
* MCAL MemMap defined, Used for share init data,
* Used START_SEC_VAR_SHARED_INIT must match with STOP_SEC_VAR_SHARED_INIT 
*/
#ifdef SAF_START_SEC_VAR_SHARED_INIT
    #undef SAF_START_SEC_VAR_SHARED_INIT
    #define ENTERED_SAF_START_SEC_VAR_SHARED_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef SAF_STOP_SEC_VAR_SHARED_INIT
            #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma ghs section data = ".saf_data_share"
#endif

#ifdef SAF_STOP_SEC_VAR_SHARED_INIT
    #ifdef ENTERED_SAF_START_SEC_VAR_SHARED_INIT
        #undef ENTERED_SAF_START_SEC_VAR_SHARED_INIT
    #else
        #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef SAF_STOP_SEC_VAR_SHARED_INIT
    #undef MEM_ERROR
        #pragma ghs section
#endif

/**
* MCAL MemMap defined, Used for share zero data,
* Used START_SEC_VAR_SHARED_NO_INIT must match with STOP_SEC_VAR_SHARED_NO_INIT 
*/
#ifdef SAF_START_SEC_VAR_SHARED_NO_INIT
    #undef SAF_START_SEC_VAR_SHARED_NO_INIT
    #define ENTERED_SAF_START_SEC_VAR_SHARED_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef SAF_STOP_SEC_VAR_SHARED_NO_INIT
            #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma ghs section data = ".saf_data_share"
#endif

#ifdef SAF_STOP_SEC_VAR_SHARED_NO_INIT
    #ifdef ENTERED_SAF_START_SEC_VAR_SHARED_NO_INIT
        #undef ENTERED_SAF_START_SEC_VAR_SHARED_NO_INIT
    #else
        #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef SAF_STOP_SEC_VAR_SHARED_NO_INIT
    #undef MEM_ERROR
        #pragma ghs section
#endif

/**
* MCAL MemMap defined, Used for code running in ram,
* Used START_SEC_RAMCODE must match with STOP_SEC_RAMCODE 
*/
#ifdef SAF_START_SEC_RAMCODE
    #undef SAF_START_SEC_RAMCODE
    #define ENTERED_SAF_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef SAF_STOP_SEC_RAMCODE
            #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma ghs section text=".saf_ramcode"
        #pragma ghs inlineprologue
        #pragma ghs callmode=far
#endif

#ifdef SAF_STOP_SEC_RAMCODE
    #ifdef ENTERED_SAF_START_SEC_RAMCODE
        #undef ENTERED_SAF_START_SEC_RAMCODE
    #else
        #error SAF_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef SAF_STOP_SEC_RAMCODE
    #undef MEM_ERROR
        #pragma ghs section
        #pragma ghs noinlineprologue
        #pragma ghs callmode=default
#endif

#endif /* GHS_C_CCFC30XX */

/*************************************************************************************************/
/*                                          DIAB                                                 */
/*************************************************************************************************/
#ifdef DCC_C_CCFC30XX
/**
* MCAL MemMap defined, Used for configure data,
* Used START_SEC_CONFIG_DATA must match with STOP_SEC_CONFIG_DATA 
*/
#ifdef MCU_START_SEC_CONFIG_DATA
    #undef MCU_START_SEC_CONFIG_DATA
    #define ENTERED_MCU_START_SEC_CONFIG_DATA
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_CONFIG_DATA
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=".rodata"
        #else
            #pragma section CONST ".rodata"
        #endif
#endif

#ifdef MCU_STOP_SEC_CONFIG_DATA
    #ifdef ENTERED_MCU_START_SEC_CONFIG_DATA
        #undef ENTERED_MCU_START_SEC_CONFIG_DATA
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_CONFIG_DATA
    #undef MEM_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section CONST
        #endif
#endif

/**
* MCAL MemMap defined, Used for code data,
* Used START_SEC_CODE must match with STOP_SEC_CODE 
*/
#ifdef MCU_START_SEC_CODE
    #undef MCU_START_SEC_CODE
    #define ENTERED_MCU_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_CODE
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata="" text=".text"
        #else
            /* no definition -> default compiler settings are used */
        #endif
#endif

#ifdef MCU_STOP_SEC_CODE
    #ifdef ENTERED_MCU_START_SEC_CODE
        #undef ENTERED_MCU_START_SEC_CODE
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_CODE
    #undef MEM_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata="" text=""
        #else
            /* no definition -> default compiler settings are used */
        #endif
#endif

/**
* MCAL MemMap defined, Used for noinit(bss) data,
* Used START_SEC_VAR_NO_INIT must match with STOP_SEC_VAR_NO_INIT 
*/
#ifdef MCU_START_SEC_VAR_NO_INIT
    #undef MCU_START_SEC_VAR_NO_INIT
    #define ENTERED_MCU_START_SEC_VAR_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_NO_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #ifdef __clang__
                #pragma clang section bss=".bss" data=".data" rodata=""
            #else
                #pragma section DATA ".data" ".bss"
            #endif
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_NO_INIT
        #undef ENTERED_MCU_START_SEC_VAR_NO_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_NO_INIT
    #undef MEM_ERROR
        #ifdef __clang__
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

/**
* MCAL MemMap defined, Used for global init data,
* Used START_SEC_VAR_INIT must match with STOP_SEC_VAR_INIT 
*/
#ifdef MCU_START_SEC_VAR_INIT
    #undef MCU_START_SEC_VAR_INIT
    #define ENTERED_MCU_START_SEC_VAR_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #ifdef __clang__
            #pragma clang section bss=".bss" data=".data" rodata=""
        #else
            #pragma section DATA ".data" ".bss"
        #endif
#endif

#ifdef MCU_STOP_SEC_VAR_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_INIT
        #undef ENTERED_MCU_START_SEC_VAR_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_INIT
    #undef MEM_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
#endif

/**
* MCAL MemMap defined, Used for share init data,
* Used START_SEC_VAR_SHARED_INIT must match with STOP_SEC_VAR_SHARED_INIT 
*/
#ifdef MCU_START_SEC_VAR_SHARED_INIT
    #undef MCU_START_SEC_VAR_SHARED_INIT
    #define ENTERED_MCU_START_SEC_VAR_SHARED_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_SHARED_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #ifdef __clang__
            #pragma clang section bss="data_share" data=".data_share" rodata=""
        #else
            #pragma section DATA ".data_share" ".data_share"
        #endif
#endif

#ifdef MCU_STOP_SEC_VAR_SHARED_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_SHARED_INIT
        #undef ENTERED_MCU_START_SEC_VAR_SHARED_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_SHARED_INIT
    #undef MEM_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
#endif

/**
* MCAL MemMap defined, Used for share zero data,
* Used START_SEC_VAR_SHARED_NO_INIT must match with STOP_SEC_VAR_SHARED_NO_INIT 
*/
#ifdef MCU_START_SEC_VAR_SHARED_NO_INIT
    #undef MCU_START_SEC_VAR_SHARED_NO_INIT
    #define ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef MCU_STOP_SEC_VAR_SHARED_NO_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #ifdef __clang__
            #pragma clang section bss="data_share" data=".data_share" rodata=""
        #else
            #pragma section DATA ".data_share" ".data_share"
        #endif
#endif

#ifdef MCU_STOP_SEC_VAR_SHARED_NO_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
        #undef ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_SHARED_NO_INIT
    #undef MEM_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata=""
        #else
            #pragma section DATA
        #endif
#endif

/**
* MCAL MemMap defined, Used for code running in ram,
* Used START_SEC_RAMCODE must match with STOP_SEC_RAMCODE 
*/
#ifdef MCU_START_SEC_RAMCODE
    #undef MCU_START_SEC_RAMCODE
    #define ENTERED_MCU_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef MCU_STOP_SEC_RAMCODE
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata="" text=".data.code"
        #else
            #pragma section CODE ".data.code" far-absolute
        #endif
#endif

#ifdef MCU_STOP_SEC_RAMCODE
    #ifdef ENTERED_MCU_START_SEC_RAMCODE
        #undef ENTERED_MCU_START_SEC_RAMCODE
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_RAMCODE
    #undef MEM_ERROR
        #ifdef __clang__
            #pragma clang section bss="" data="" rodata="" text=""-n        #else
            #pragma section CODE
        #endif
#endif

#endif /* DCC_C_CCFC30XX */

/*************************************************************************************************/
/*                                       CODEWARRIOR                                             */
/*************************************************************************************************/
#ifdef MWERKS_C_CCFC30XX
/**
* MCAL MemMap defined, Used for configure data,
* Used START_SEC_CONFIG_DATA must match with STOP_SEC_CONFIG_DATA 
*/
#ifdef MCU_START_SEC_CONFIG_DATA
    #undef MCU_START_SEC_CONFIG_DATA
    #define ENTERED_MCU_START_SEC_CONFIG_DATA
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_CONFIG_DATA
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma CONST_SEG rodata
#endif

#ifdef MCU_STOP_SEC_CONFIG_DATA
    #ifdef ENTERED_MCU_START_SEC_CONFIG_DATA
        #undef ENTERED_MCU_START_SEC_CONFIG_DATA
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_CONFIG_DATA
    #undef MEM_ERROR
        #pragma CONST_SEG DEFAULT
#endif

/**
* MCAL MemMap defined, Used for code data,
* Used START_SEC_CODE must match with STOP_SEC_CODE 
*/
#ifdef MCU_START_SEC_CODE
    #undef MCU_START_SEC_CODE
    #define ENTERED_MCU_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_CODE
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma CODE_SEG text
#endif

#ifdef MCU_STOP_SEC_CODE
    #ifdef ENTERED_MCU_START_SEC_CODE
        #undef ENTERED_MCU_START_SEC_CODE
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_CODE
    #undef MEM_ERROR
        #pragma CODE_SEG DEFAULT
#endif

/**
* MCAL MemMap defined, Used for noinit(bss) data,
* Used START_SEC_VAR_NO_INIT must match with STOP_SEC_VAR_NO_INIT 
*/
#ifdef MCU_START_SEC_VAR_NO_INIT
    #undef MCU_START_SEC_VAR_NO_INIT
    #define ENTERED_MCU_START_SEC_VAR_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_NO_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma DATA_SEG bss
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_NO_INIT
        #undef ENTERED_MCU_START_SEC_VAR_NO_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_NO_INIT
    #undef MEM_ERROR
        #pragma DATA_SEG DEFAULT
#endif

/**
* MCAL MemMap defined, Used for global init data,
* Used START_SEC_VAR_INIT must match with STOP_SEC_VAR_INIT 
*/
#ifdef MCU_START_SEC_VAR_INIT
    #undef MCU_START_SEC_VAR_INIT
    #define ENTERED_MCU_START_SEC_VAR_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma DATA_SEG data
#endif

#ifdef MCU_STOP_SEC_VAR_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_INIT
        #undef ENTERED_MCU_START_SEC_VAR_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_INIT
    #undef MEM_ERROR
        #pragma DATA_SEG DEFAULT
#endif

/**
* MCAL MemMap defined, Used for share init data,
* Used START_SEC_VAR_SHARED_INIT must match with STOP_SEC_VAR_SHARED_INIT 
*/
#ifdef MCU_START_SEC_VAR_SHARED_INIT
    #undef MCU_START_SEC_VAR_SHARED_INIT
    #define ENTERED_MCU_START_SEC_VAR_SHARED_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_SHARED_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma DATA_SEG .data_share
#endif

#ifdef MCU_STOP_SEC_VAR_SHARED_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_SHARED_INIT
        #undef ENTERED_MCU_START_SEC_VAR_SHARED_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_SHARED_INIT
    #undef MEM_ERROR
        #pragma DATA_SEG DEFAULT
#endif

/**
* MCAL MemMap defined, Used for share zero data,
* Used START_SEC_VAR_SHARED_NO_INIT must match with STOP_SEC_VAR_SHARED_NO_INIT 
*/
#ifdef MCU_START_SEC_VAR_SHARED_NO_INIT
    #undef MCU_START_SEC_VAR_SHARED_NO_INIT
    #define ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef MCU_STOP_SEC_VAR_SHARED_NO_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma DATA_SEG .data_share
#endif

#ifdef MCU_STOP_SEC_VAR_SHARED_NO_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
        #undef ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_SHARED_NO_INIT
    #undef MEM_ERROR
        #pragma DATA_SEG DEFAULT
#endif

/**
* MCAL MemMap defined, Used for code running in ram,
* Used START_SEC_RAMCODE must match with STOP_SEC_RAMCODE 
*/
#ifdef MCU_START_SEC_RAMCODE
    #undef MCU_START_SEC_RAMCODE
    #define ENTERED_MCU_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef MCU_STOP_SEC_RAMCODE
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma CODE_SEG data.code
#endif

#ifdef MCU_STOP_SEC_RAMCODE
    #ifdef ENTERED_MCU_START_SEC_RAMCODE
        #undef ENTERED_MCU_START_SEC_RAMCODE
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_RAMCODE
    #undef MEM_ERROR
        #pragma CODE_SEG DEFAULT
#endif

#endif /* MWERKS_C_CCFC30XX */

/*************************************************************************************************/
/*                                         COSMIC                                                */
/*************************************************************************************************/
#ifdef CSMC_C_CCFC30XX
/**
* MCAL MemMap defined, Used for configure data,
* Used START_SEC_CONFIG_DATA must match with STOP_SEC_CONFIG_DATA 
*/
#ifdef MCU_START_SEC_CONFIG_DATA
    #undef MCU_START_SEC_CONFIG_DATA
    #define ENTERED_MCU_START_SEC_CONFIG_DATA
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_CONFIG_DATA
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma section const {rodata}
#endif

#ifdef MCU_STOP_SEC_CONFIG_DATA
    #ifdef ENTERED_MCU_START_SEC_CONFIG_DATA
        #undef ENTERED_MCU_START_SEC_CONFIG_DATA
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_CONFIG_DATA
    #undef MEM_ERROR
        #pragma section const {}
#endif

/**
* MCAL MemMap defined, Used for code data,
* Used START_SEC_CODE must match with STOP_SEC_CODE 
*/
#ifdef MCU_START_SEC_CODE
    #undef MCU_START_SEC_CODE
    #define ENTERED_MCU_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_CODE
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma section (text)
#endif

#ifdef MCU_STOP_SEC_CODE
    #ifdef ENTERED_MCU_START_SEC_CODE
        #undef ENTERED_MCU_START_SEC_CODE
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_CODE
    #undef MEM_ERROR
        #pragma section ()
#endif

/**
* MCAL MemMap defined, Used for noinit(bss) data,
* Used START_SEC_VAR_NO_INIT must match with STOP_SEC_VAR_NO_INIT 
*/
#ifdef MCU_START_SEC_VAR_NO_INIT
    #undef MCU_START_SEC_VAR_NO_INIT
    #define ENTERED_MCU_START_SEC_VAR_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_NO_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma section [bss]
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_NO_INIT
        #undef ENTERED_MCU_START_SEC_VAR_NO_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_NO_INIT
    #undef MEM_ERROR
        #pragma section []
#endif

/**
* MCAL MemMap defined, Used for global init data,
* Used START_SEC_VAR_INIT must match with STOP_SEC_VAR_INIT 
*/
#ifdef MCU_START_SEC_VAR_INIT
    #undef MCU_START_SEC_VAR_INIT
    #define ENTERED_MCU_START_SEC_VAR_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma section {data}
#endif

#ifdef MCU_STOP_SEC_VAR_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_INIT
        #undef ENTERED_MCU_START_SEC_VAR_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_INIT
    #undef MEM_ERROR
        #pragma section {}
#endif

/**
* MCAL MemMap defined, Used for share init data,
* Used START_SEC_VAR_SHARED_INIT must match with STOP_SEC_VAR_SHARED_INIT 
*/
#ifdef MCU_START_SEC_VAR_SHARED_INIT
    #undef MCU_START_SEC_VAR_SHARED_INIT
    #define ENTERED_MCU_START_SEC_VAR_SHARED_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_SHARED_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma section {.data_share}
#endif

#ifdef MCU_STOP_SEC_VAR_SHARED_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_SHARED_INIT
        #undef ENTERED_MCU_START_SEC_VAR_SHARED_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_SHARED_INIT
    #undef MEM_ERROR
        #pragma section {}
#endif

/**
* MCAL MemMap defined, Used for share zero data,
* Used START_SEC_VAR_SHARED_NO_INIT must match with STOP_SEC_VAR_SHARED_NO_INIT 
*/
#ifdef MCU_START_SEC_VAR_SHARED_NO_INIT
    #undef MCU_START_SEC_VAR_SHARED_NO_INIT
    #define ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef MCU_STOP_SEC_VAR_SHARED_NO_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma section {.data_share}
#endif

#ifdef MCU_STOP_SEC_VAR_SHARED_NO_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
        #undef ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_SHARED_NO_INIT
    #undef MEM_ERROR
        #pragma section {}
#endif

/**
* MCAL MemMap defined, Used for code running in ram,
* Used START_SEC_RAMCODE must match with STOP_SEC_RAMCODE 
*/
#ifdef MCU_START_SEC_RAMCODE
    #undef MCU_START_SEC_RAMCODE
    #define ENTERED_MCU_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef MCU_STOP_SEC_RAMCODE
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma section (data.code)
#endif

#ifdef MCU_STOP_SEC_RAMCODE
    #ifdef ENTERED_MCU_START_SEC_RAMCODE
        #undef ENTERED_MCU_START_SEC_RAMCODE
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_RAMCODE
    #undef MEM_ERROR
        #pragma section ()
#endif

#endif /* CSMC_C_CCFC30XX */

/*************************************************************************************************/
/*                                        HighTec                                                */
/*************************************************************************************************/
#ifdef HITECH_C_CCFC30XX
/**
* MCAL MemMap defined, Used for configure data,
* Used START_SEC_CONFIG_DATA must match with STOP_SEC_CONFIG_DATA 
*/
#ifdef MCU_START_SEC_CONFIG_DATA
    #undef MCU_START_SEC_CONFIG_DATA
    #define ENTERED_MCU_START_SEC_CONFIG_DATA
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_CONFIG_DATA
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma section ".rodata" a
#endif

#ifdef MCU_STOP_SEC_CONFIG_DATA
    #ifdef ENTERED_MCU_START_SEC_CONFIG_DATA
        #undef ENTERED_MCU_START_SEC_CONFIG_DATA
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_CONFIG_DATA
    #undef MEM_ERROR
        #pragma section
#endif

/**
* MCAL MemMap defined, Used for code data,
* Used START_SEC_CODE must match with STOP_SEC_CODE 
*/
#ifdef MCU_START_SEC_CODE
    #undef MCU_START_SEC_CODE
    #define ENTERED_MCU_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_CODE
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma section ".text" avx
#endif

#ifdef MCU_STOP_SEC_CODE
    #ifdef ENTERED_MCU_START_SEC_CODE
        #undef ENTERED_MCU_START_SEC_CODE
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_CODE
    #undef MEM_ERROR
        #pragma section
#endif

/**
* MCAL MemMap defined, Used for noinit(bss) data,
* Used START_SEC_VAR_NO_INIT must match with STOP_SEC_VAR_NO_INIT 
*/
#ifdef MCU_START_SEC_VAR_NO_INIT
    #undef MCU_START_SEC_VAR_NO_INIT
    #define ENTERED_MCU_START_SEC_VAR_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_NO_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma section ".bss"
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_NO_INIT
        #undef ENTERED_MCU_START_SEC_VAR_NO_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_NO_INIT
    #undef MEM_ERROR
        #pragma section
#endif

/**
* MCAL MemMap defined, Used for global init data,
* Used START_SEC_VAR_INIT must match with STOP_SEC_VAR_INIT 
*/
#ifdef MCU_START_SEC_VAR_INIT
    #undef MCU_START_SEC_VAR_INIT
    #define ENTERED_MCU_START_SEC_VAR_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma section ".data"
#endif

#ifdef MCU_STOP_SEC_VAR_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_INIT
        #undef ENTERED_MCU_START_SEC_VAR_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_INIT
    #undef MEM_ERROR
        #pragma section
#endif

/**
* MCAL MemMap defined, Used for share init data,
* Used START_SEC_VAR_SHARED_INIT must match with STOP_SEC_VAR_SHARED_INIT 
*/
#ifdef MCU_START_SEC_VAR_SHARED_INIT
    #undef MCU_START_SEC_VAR_SHARED_INIT
    #define ENTERED_MCU_START_SEC_VAR_SHARED_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_SHARED_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma section ".data_share"
#endif

#ifdef MCU_STOP_SEC_VAR_SHARED_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_SHARED_INIT
        #undef ENTERED_MCU_START_SEC_VAR_SHARED_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_SHARED_INIT
    #undef MEM_ERROR
        #pragma section
#endif

/**
* MCAL MemMap defined, Used for share zero data,
* Used START_SEC_VAR_SHARED_NO_INIT must match with STOP_SEC_VAR_SHARED_NO_INIT 
*/
#ifdef MCU_START_SEC_VAR_SHARED_NO_INIT
    #undef MCU_START_SEC_VAR_SHARED_NO_INIT
    #define ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef MCU_STOP_SEC_VAR_SHARED_NO_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma section ".data_share"
#endif

#ifdef MCU_STOP_SEC_VAR_SHARED_NO_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
        #undef ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_SHARED_NO_INIT
    #undef MEM_ERROR
        #pragma section
#endif

/**
* MCAL MemMap defined, Used for code running in ram,
* Used START_SEC_RAMCODE must match with STOP_SEC_RAMCODE 
*/
#ifdef MCU_START_SEC_RAMCODE
    #undef MCU_START_SEC_RAMCODE
    #define ENTERED_MCU_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef MCU_STOP_SEC_RAMCODE
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma section ".data.code" avx
#endif

#ifdef MCU_STOP_SEC_RAMCODE
    #ifdef ENTERED_MCU_START_SEC_RAMCODE
        #undef ENTERED_MCU_START_SEC_RAMCODE
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_RAMCODE
    #undef MEM_ERROR
        #pragma  section
#endif

#endif /* HITECH_C_CCFC30XX */

/*************************************************************************************************/
/*                                         Linaro                                                */
/*************************************************************************************************/
#ifdef LINARO_C_CCFC30XX
/**
* MCAL MemMap defined, Used for configure data,
* Used START_SEC_CONFIG_DATA must match with STOP_SEC_CONFIG_DATA 
*/
#ifdef MCU_START_SEC_CONFIG_DATA
    #undef MCU_START_SEC_CONFIG_DATA
    #define ENTERED_MCU_START_SEC_CONFIG_DATA
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_CONFIG_DATA
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma GCC section rodata ".rodata"
#endif

#ifdef MCU_STOP_SEC_CONFIG_DATA
    #ifdef ENTERED_MCU_START_SEC_CONFIG_DATA
        #undef ENTERED_MCU_START_SEC_CONFIG_DATA
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_CONFIG_DATA
    #undef MEM_ERROR
        #pragma GCC section rodata
#endif

/**
* MCAL MemMap defined, Used for code data,
* Used START_SEC_CODE must match with STOP_SEC_CODE 
*/
#ifdef MCU_START_SEC_CODE
    #undef MCU_START_SEC_CODE
    #define ENTERED_MCU_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_CODE
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma GCC section text ".text"
#endif

#ifdef MCU_STOP_SEC_CODE
    #ifdef ENTERED_MCU_START_SEC_CODE
        #undef ENTERED_MCU_START_SEC_CODE
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_CODE
    #undef MEM_ERROR
        #pragma GCC section text
#endif

/**
* MCAL MemMap defined, Used for noinit(bss) data,
* Used START_SEC_VAR_NO_INIT must match with STOP_SEC_VAR_NO_INIT 
*/
#ifdef MCU_START_SEC_VAR_NO_INIT
    #undef MCU_START_SEC_VAR_NO_INIT
    #define ENTERED_MCU_START_SEC_VAR_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_NO_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma GCC section bss ".bss"
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_NO_INIT
        #undef ENTERED_MCU_START_SEC_VAR_NO_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_NO_INIT
    #undef MEM_ERROR
        #pragma GCC section bss
#endif

/**
* MCAL MemMap defined, Used for global init data,
* Used START_SEC_VAR_INIT must match with STOP_SEC_VAR_INIT 
*/
#ifdef MCU_START_SEC_VAR_INIT
    #undef MCU_START_SEC_VAR_INIT
    #define ENTERED_MCU_START_SEC_VAR_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma GCC section data ".data"
#endif

#ifdef MCU_STOP_SEC_VAR_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_INIT
        #undef ENTERED_MCU_START_SEC_VAR_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_INIT
    #undef MEM_ERROR
        #pragma GCC section data
#endif

/**
* MCAL MemMap defined, Used for share init data,
* Used START_SEC_VAR_SHARED_INIT must match with STOP_SEC_VAR_SHARED_INIT 
*/
#ifdef MCU_START_SEC_VAR_SHARED_INIT
    #undef MCU_START_SEC_VAR_SHARED_INIT
    #define ENTERED_MCU_START_SEC_VAR_SHARED_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_SHARED_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma GCC section data ".data_share"
#endif

#ifdef MCU_STOP_SEC_VAR_SHARED_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_SHARED_INIT
        #undef ENTERED_MCU_START_SEC_VAR_SHARED_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_SHARED_INIT
    #undef MEM_ERROR
        #pragma GCC section data
#endif

/**
* MCAL MemMap defined, Used for share zero data,
* Used START_SEC_VAR_SHARED_NO_INIT must match with STOP_SEC_VAR_SHARED_NO_INIT 
*/
#ifdef MCU_START_SEC_VAR_SHARED_NO_INIT
    #undef MCU_START_SEC_VAR_SHARED_NO_INIT
    #define ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef MCU_STOP_SEC_VAR_SHARED_NO_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma GCC section data ".data_share"
#endif

#ifdef MCU_STOP_SEC_VAR_SHARED_NO_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
        #undef ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_SHARED_NO_INIT
    #undef MEM_ERROR
        #pragma GCC section data
#endif

/**
* MCAL MemMap defined, Used for code running in ram,
* Used START_SEC_RAMCODE must match with STOP_SEC_RAMCODE 
*/
#ifdef MCU_START_SEC_RAMCODE
    #undef MCU_START_SEC_RAMCODE
    #define ENTERED_MCU_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef MCU_STOP_SEC_RAMCODE
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma GCC section text ".data.code" 
#endif

#ifdef MCU_STOP_SEC_RAMCODE
    #ifdef ENTERED_MCU_START_SEC_RAMCODE
        #undef ENTERED_MCU_START_SEC_RAMCODE
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_RAMCODE
    #undef MEM_ERROR
        #pragma GCC section text
#endif

#endif /* LINARO_C_CCFC30XX */

/*************************************************************************************************/
/*                                          DS5                                                  */
/*************************************************************************************************/
#ifdef DS5_C_CCFC30XX
/**
* MCAL MemMap defined, Used for configure data,
* Used START_SEC_CONFIG_DATA must match with STOP_SEC_CONFIG_DATA 
*/
#ifdef MCU_START_SEC_CONFIG_DATA
    #undef MCU_START_SEC_CONFIG_DATA
    #define ENTERED_MCU_START_SEC_CONFIG_DATA
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_CONFIG_DATA
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma arm section rodata=".rodata"
#endif

#ifdef MCU_STOP_SEC_CONFIG_DATA
    #ifdef ENTERED_MCU_START_SEC_CONFIG_DATA
        #undef ENTERED_MCU_START_SEC_CONFIG_DATA
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_CONFIG_DATA
    #undef MEM_ERROR
        /* no definition -> default compiler settings are used */
#endif

/**
* MCAL MemMap defined, Used for code data,
* Used START_SEC_CODE must match with STOP_SEC_CODE 
*/
#ifdef MCU_START_SEC_CODE
    #undef MCU_START_SEC_CODE
    #define ENTERED_MCU_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_CODE
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma arm section code=".text"
#endif

#ifdef MCU_STOP_SEC_CODE
    #ifdef ENTERED_MCU_START_SEC_CODE
        #undef ENTERED_MCU_START_SEC_CODE
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_CODE
    #undef MEM_ERROR
        /* no definition -> default compiler settings are used */
#endif

/**
* MCAL MemMap defined, Used for noinit(bss) data,
* Used START_SEC_VAR_NO_INIT must match with STOP_SEC_VAR_NO_INIT 
*/
#ifdef MCU_START_SEC_VAR_NO_INIT
    #undef MCU_START_SEC_VAR_NO_INIT
    #define ENTERED_MCU_START_SEC_VAR_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_NO_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma arm section zidata=".bss"
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_NO_INIT
        #undef ENTERED_MCU_START_SEC_VAR_NO_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_NO_INIT
    #undef MEM_ERROR
        /* no definition -> default compiler settings are used */
#endif

/**
* MCAL MemMap defined, Used for global init data,
* Used START_SEC_VAR_INIT must match with STOP_SEC_VAR_INIT 
*/
#ifdef MCU_START_SEC_VAR_INIT
    #undef MCU_START_SEC_VAR_INIT
    #define ENTERED_MCU_START_SEC_VAR_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma arm section rwdata=".data"
#endif

#ifdef MCU_STOP_SEC_VAR_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_INIT
        #undef ENTERED_MCU_START_SEC_VAR_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_INIT
    #undef MEM_ERROR
        /* no definition -> default compiler settings are used */
#endif

/**
* MCAL MemMap defined, Used for share init data,
* Used START_SEC_VAR_SHARED_INIT must match with STOP_SEC_VAR_SHARED_INIT 
*/
#ifdef MCU_START_SEC_VAR_SHARED_INIT
    #undef MCU_START_SEC_VAR_SHARED_INIT
    #define ENTERED_MCU_START_SEC_VAR_SHARED_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_SHARED_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma arm section rwdata=".data_share"
#endif

#ifdef MCU_STOP_SEC_VAR_SHARED_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_SHARED_INIT
        #undef ENTERED_MCU_START_SEC_VAR_SHARED_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_SHARED_INIT
    #undef MEM_ERROR
        /* no definition -> default compiler settings are used */
#endif

/**
* MCAL MemMap defined, Used for share zero data,
* Used START_SEC_VAR_SHARED_NO_INIT must match with STOP_SEC_VAR_SHARED_NO_INIT 
*/
#ifdef MCU_START_SEC_VAR_SHARED_NO_INIT
    #undef MCU_START_SEC_VAR_SHARED_NO_INIT
    #define ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef MCU_STOP_SEC_VAR_SHARED_NO_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma arm section rwdata=".data_share"
#endif

#ifdef MCU_STOP_SEC_VAR_SHARED_NO_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
        #undef ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_SHARED_NO_INIT
    #undef MEM_ERROR
        /* no definition -> default compiler settings are used */
#endif

/**
* MCAL MemMap defined, Used for code running in ram,
* Used START_SEC_RAMCODE must match with STOP_SEC_RAMCODE 
*/
#ifdef MCU_START_SEC_RAMCODE
    #undef MCU_START_SEC_RAMCODE
    #define ENTERED_MCU_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef MCU_STOP_SEC_RAMCODE
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma arm section code=".data.code"
#endif

#ifdef MCU_STOP_SEC_RAMCODE
    #ifdef ENTERED_MCU_START_SEC_RAMCODE
        #undef ENTERED_MCU_START_SEC_RAMCODE
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_RAMCODE
    #undef MEM_ERROR
        /* no definition -> default compiler settings are used */
#endif

#endif /* DS5_C_CCFC30XX */

/*************************************************************************************************/
/*                                          IAR                                                  */
/*************************************************************************************************/
#ifdef IAR_C_CCFC30XX
/**
* MCAL MemMap defined, Used for configure data,
* Used START_SEC_CONFIG_DATA must match with STOP_SEC_CONFIG_DATA 
*/
#ifdef MCU_START_SEC_CONFIG_DATA
    #undef MCU_START_SEC_CONFIG_DATA
    #define ENTERED_MCU_START_SEC_CONFIG_DATA
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_CONFIG_DATA
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma default_variable_attributes = @ ".rodata"
#endif

#ifdef MCU_STOP_SEC_CONFIG_DATA
    #ifdef ENTERED_MCU_START_SEC_CONFIG_DATA
        #undef ENTERED_MCU_START_SEC_CONFIG_DATA
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_CONFIG_DATA
    #undef MEM_ERROR
        #pragma default_variable_attributes = 
#endif

/**
* MCAL MemMap defined, Used for code data,
* Used START_SEC_CODE must match with STOP_SEC_CODE 
*/
#ifdef MCU_START_SEC_CODE
    #undef MCU_START_SEC_CODE
    #define ENTERED_MCU_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_CODE
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma default_function_attributes = @ ".text"
#endif

#ifdef MCU_STOP_SEC_CODE
    #ifdef ENTERED_MCU_START_SEC_CODE
        #undef ENTERED_MCU_START_SEC_CODE
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_CODE
    #undef MEM_ERROR
        #pragma default_function_attributes =
#endif

/**
* MCAL MemMap defined, Used for noinit(bss) data,
* Used START_SEC_VAR_NO_INIT must match with STOP_SEC_VAR_NO_INIT 
*/
#ifdef MCU_START_SEC_VAR_NO_INIT
    #undef MCU_START_SEC_VAR_NO_INIT
    #define ENTERED_MCU_START_SEC_VAR_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_NO_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma default_variable_attributes = @ ".bss"
#endif

#ifdef MCU_STOP_SEC_VAR_NO_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_NO_INIT
        #undef ENTERED_MCU_START_SEC_VAR_NO_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_NO_INIT
    #undef MEM_ERROR
        #pragma default_variable_attributes =
#endif

/**
* MCAL MemMap defined, Used for global init data,
* Used START_SEC_VAR_INIT must match with STOP_SEC_VAR_INIT 
*/
#ifdef MCU_START_SEC_VAR_INIT
    #undef MCU_START_SEC_VAR_INIT
    #define ENTERED_MCU_START_SEC_VAR_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma default_variable_attributes = @ ".data"
#endif

#ifdef MCU_STOP_SEC_VAR_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_INIT
        #undef ENTERED_MCU_START_SEC_VAR_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_INIT
    #undef MEM_ERROR
        #pragma default_variable_attributes =
#endif

/**
* MCAL MemMap defined, Used for share init data,
* Used START_SEC_VAR_SHARED_INIT must match with STOP_SEC_VAR_SHARED_INIT 
*/
#ifdef MCU_START_SEC_VAR_SHARED_INIT
    #undef MCU_START_SEC_VAR_SHARED_INIT
    #define ENTERED_MCU_START_SEC_VAR_SHARED_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef MCU_STOP_SEC_VAR_SHARED_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma default_variable_attributes = @ ".data_share"
#endif

#ifdef MCU_STOP_SEC_VAR_SHARED_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_SHARED_INIT
        #undef ENTERED_MCU_START_SEC_VAR_SHARED_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_SHARED_INIT
    #undef MEM_ERROR
        #pragma default_variable_attributes =
#endif

/**
* MCAL MemMap defined, Used for share zero data,
* Used START_SEC_VAR_SHARED_NO_INIT must match with STOP_SEC_VAR_SHARED_NO_INIT 
*/
#ifdef MCU_START_SEC_VAR_SHARED_NO_INIT
    #undef MCU_START_SEC_VAR_SHARED_NO_INIT
    #define ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef MCU_STOP_SEC_VAR_SHARED_NO_INIT
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma default_variable_attributes = @ ".data_share"
#endif

#ifdef MCU_STOP_SEC_VAR_SHARED_NO_INIT
    #ifdef ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
        #undef ENTERED_MCU_START_SEC_VAR_SHARED_NO_INIT
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_VAR_SHARED_NO_INIT
    #undef MEM_ERROR
        #pragma default_variable_attributes =
#endif

/**
* MCAL MemMap defined, Used for code running in ram,
* Used START_SEC_RAMCODE must match with STOP_SEC_RAMCODE 
*/
#ifdef MCU_START_SEC_RAMCODE
    #undef MCU_START_SEC_RAMCODE
    #define ENTERED_MCU_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifdef MCU_STOP_SEC_RAMCODE
            #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef MEM_ERROR
        #pragma default_function_attributes = @ ".data.code"
#endif

#ifdef MCU_STOP_SEC_RAMCODE
    #ifdef ENTERED_MCU_START_SEC_RAMCODE
        #undef ENTERED_MCU_START_SEC_RAMCODE
    #else
        #error MCU_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef MCU_STOP_SEC_RAMCODE
    #undef MEM_ERROR
        #pragma default_function_attributes =
#endif

#endif /* IAR_C_CCFC30XX */

#undef MEM_ERROR
#ifdef MEM_ERROR
    #error "Mcu_MemMap.h, no valid memory mapping symbol defined."
#endif
        
/*====================================================================================================
                                         DISABLE WARNING END
====================================================================================================*/
#ifdef GHS_C_CCFC30XX
#pragma ghs  endnowarning 1512
#endif

#ifdef __cplusplus
}
#endif
/*PRQA S 0883*/

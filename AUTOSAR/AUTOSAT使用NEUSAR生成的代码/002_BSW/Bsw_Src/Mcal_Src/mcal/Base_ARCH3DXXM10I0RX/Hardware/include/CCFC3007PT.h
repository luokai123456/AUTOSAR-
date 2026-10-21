/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* @file     CCFC3007PT.h
* @version  1.0
* @date     2023 - 04 - 17
* @brief    Initial version.
*
*****************************************************************************/

#if defined(CCFC3007PT)
#ifndef CCFC3007PT_H_
#define CCFC3007PT_H_

#include "typedefs.h"
/*PRQA S 1536,2052,3108,0784,0636,2053 EOF*/
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __MWERKS__
#pragma push
#pragma ANSI_strict off
#endif
#ifdef __ghs__
#pragma ghs nowarning 618
#endif

#include "module/core_reg.h"
#include "module/c55fmc_reg.h"
#include "module/cmu_reg.h"
#include "module/crc_reg.h"
#include "module/dma_mux_reg.h"
#include "module/dspi_reg.h"
#include "module/etpu_reg.h"
#include "module/dts_reg.h"
#include "module/ebi_reg.h"
#include "module/fccu_reg.h"
#include "module/fec_reg.h"
#include "module/fr_reg.h"
#include "module/i2c_reg.h"
#include "module/ima_reg.h"
#include "module/intc_reg.h"
#include "module/ircosc_reg.h"
#include "module/jdc_reg.h"
#include "module/jtagm_reg.h"
#include "module/lfast_reg.h"
#include "module/lin_reg.h"
#include "module/ssi_reg.h"
#include "module/i2s_reg.h"
#include "module/mc_cgm_reg.h"
#include "module/mc_me_reg.h"
#include "module/mc_pcu_reg.h"
#include "module/mc_rgm_reg.h"
#include "module/memu_reg.h"
#include "module/can_sample_reg.h"
#include "module/canfd_reg.h"
#include "module/mcan_reg.h"
#include "module/mttcan_reg.h"
#include "module/pass_reg.h"
#include "module/pbridge_reg.h"
#include "module/pcm_reg.h"
#include "module/pfalsh_reg.h"
#include "module/pit_reg.h"
#include "module/plldig.h"
#include "module/pmcdig_reg.h"
#include "module/pramc_reg.h"
#include "module/emios_reg.h"
#include "module/psi5_reg.h"
#include "module/psi5s_reg.h"
#include "module/eqadc_reg.h"
#include "module/port_reg.h"
#include "module/sdadc_reg.h"
#include "module/sema42_reg.h"
#include "module/sipi_reg.h"
#include "module/siul2_reg.h"
#include "module/csrx_reg.h"
#include "module/igf_reg.h"
#include "module/smpu_reg.h"
#include "module/srx_reg.h"
#include "module/sscm_reg.h"
#include "module/stcu2_reg.h"
#include "module/stm_reg.h"
#include "module/swt_reg.h"
#include "module/tdm_reg.h"
#include "module/wkpu_reg.h"
#include "module/xbar_reg.h"
#include "module/xbic_reg.h"
#include "module/edma_reg.h"
#include "module/eth0_reg.h"
#include "module/xosc_reg.h"
#include "module/eth1_reg.h"
#include "module/rtc_reg.h"
#include "module/gtm104_reg.h"
#include "module/hsm_reg.h"

/* ============================================================================
   ================================== Address =================================
   ============================================================================ */
#define SRAM0_START     0x40000000UL;
#define C55FMC          (*(volatile struct C55FMC_tag *)   0xFFFE0000UL)
#define CMU_ADCSAR      (*(volatile struct CMU_tag *)      0xFBFB0340UL)
#define CMU_ADCSD       (*(volatile struct CMU_tag *)      0xFBFB0300UL)
#define CMU_CLKOUT      (*(volatile struct CMU_tag *)      0xFBFB04C0UL)
#define CMU_CORE        (*(volatile struct CMU_tag *)      0xFBFB0480UL)
#define CMU_FXBAR       (*(volatile struct CMU_tag *)      0xFBFB0200UL)
#define CMU_PBRIDGE     (*(volatile struct CMU_tag *)      0xFBFB0280UL)
#define CMU_PER         (*(volatile struct CMU_tag *)      0xFBFB02C0UL)
#define CMU_PLL         (*(volatile struct CMU_tag *)      0xFFFB0200UL)
#define CMU_PSI5_1US    (*(volatile struct CMU_tag *)      0xFBFB0440UL)
#define CMU_PSI5_F125   (*(volatile struct CMU_tag *)      0xFBFB0400UL)
#define CMU_PSI5_F189   (*(volatile struct CMU_tag *)      0xFBFB03C0UL)
#define CMU_SENT        (*(volatile struct CMU_tag *)      0xFBFB0380UL)
#define CMU_SXBAR       (*(volatile struct CMU_tag *)      0xFBFB0240UL)
#define CRC_0           (*(volatile struct CRC_tag *)      0xFFF64000UL)
#define CRC_1           (*(volatile struct CRC_tag *)      0xFBF64000UL)
#define DMAMUX_0        (*(volatile struct DMAMUX_tag *)   0xFFF6C000UL)
#define DMAMUX_1        (*(volatile struct DMAMUX_tag *)   0xFFF6C200UL)
#define DMAMUX_2        (*(volatile struct DMAMUX_tag *)   0xFFF6C400UL)
#define DMAMUX_3        (*(volatile struct DMAMUX_tag *)   0xFFF6C600UL)
#define DMAMUX_4        (*(volatile struct DMAMUX_tag *)   0xFFF6C800UL)
#define DMAMUX_5        (*(volatile struct DMAMUX_tag *)   0xFFF6CA00UL)
#define DMAMUX_6        (*(volatile struct DMAMUX_tag *)   0xFFF6CC00UL)
#define DMAMUX_7        (*(volatile struct DMAMUX_tag *)   0xFFF6CE00UL)
#define DMAMUX_8        (*(volatile struct DMAMUX_tag *)   0xFFF6D000UL)
#define DMAMUX_9        (*(volatile struct DMAMUX_tag *)   0xFFF6D200UL)
#define DSPI_0          (*(volatile struct DSPI_tag *)     0xFFE70000UL)
#define DSPI_1          (*(volatile struct DSPI_tag *)     0xFFE74000UL)
#define DSPI_12         (*(volatile struct DSPI_tag *)     0xFFE88000UL)
#define DSPI_2          (*(volatile struct DSPI_tag *)     0xFBE70000UL)
#define DSPI_3          (*(volatile struct DSPI_tag *)     0xFBE74000UL)
#define DSPI_4          (*(volatile struct DSPI_tag *)     0xFFE78000UL)
#define DSPI_5          (*(volatile struct DSPI_tag *)     0xFBE78000UL)
#define DSPI_6          (*(volatile struct DSPI_tag *)     0xFFE7C000UL)
#define DTS             (*(volatile struct DTS_tag *)      0xFFF38000UL)
#define EBI             (*(volatile struct EBI_tag *)      0xFFFF0000UL)
#define FCCU            (*(volatile struct FCCU_tag *)     0xFBF58000UL)
#define FEC             (*(volatile struct FEC_tag *)      0xFC0B0000UL)
#define FR_0            (*(volatile struct FR_tag *)       0xFFE50000UL)
#define FR_1            (*(volatile struct FR_tag *)       0xFBE50000UL)
#define GTM             (*(volatile struct GTM_tag *)      0xFFD00000UL)
#define GTMINT          (*(volatile struct GTMINT_tag *)   0xFFD00000UL)
#define GTM_AFD_0       (*(volatile struct GTM_AFD_tag *)  0xFFD18080UL)
#define GTM_AFD_1       (*(volatile struct GTM_AFD_tag *)  0xFFD1C000UL)
#define GTM_ARU         (*(volatile struct GTM_ARU_tag *)  0xFFD00280UL)
#define GTM_ATOM_0      (*(volatile struct GTM_ATOM_tag *) 0xFFD0D000UL)
#define GTM_ATOM_1      (*(volatile struct GTM_ATOM_tag *) 0xFFD0D800UL)
#define GTM_ATOM_2      (*(volatile struct GTM_ATOM_tag *) 0xFFD0E000UL)
#define GTM_ATOM_3      (*(volatile struct GTM_ATOM_tag *) 0xFFD0E800UL)
#define GTM_ATOM_4      (*(volatile struct GTM_ATOM_tag *) 0xFFD0F000UL)
#define GTM_ATOM_5      (*(volatile struct GTM_ATOM_tag *) 0xFFD0F800UL)
#define GTM_ATOM_6      (*(volatile struct GTM_ATOM_tag *) 0xFFD10000UL)
#define GTM_ATOM_7      (*(volatile struct GTM_ATOM_tag *) 0xFFD10800UL)
#define GTM_ATOM_8      (*(volatile struct GTM_ATOM_tag *) 0xFFD11000UL)
#define GTM_BRC         (*(volatile struct GTM_BRC_tag *)  0xFFD00400UL)
#define GTM_CMP         (*(volatile struct GTM_CMP_tag *)  0xFFD00200UL)
#define GTM_CMU         (*(volatile struct GTM_CMU_tag *)  0xFFD00300UL)
#define GTM_DPLL        (*(volatile struct GTM_DPLL_tag *) 0xFFD28000UL)
#define GTM_F2A_0       (*(volatile struct GTM_F2A_tag *)  0xFFD18000UL)
#define GTM_F2A_1       (*(volatile struct GTM_F2A_tag *)  0xFFD1C080UL)
#define GTM_FIFO_0      (*(volatile struct GTM_FIFO_tag *) 0xFFD18400UL)
#define GTM_FIFO_1      (*(volatile struct GTM_FIFO_tag *) 0xFFD1C400UL)
#define GTM_ICM         (*(volatile struct GTM_ICM_tag *)  0xFFD00600UL)
#define GTM_MAP         (*(volatile struct GTM_MAP_tag *)  0xFFD00F00UL)
#define GTM_MCFG        (*(volatile struct GTM_MCFG_tag *) 0xFFD00F40UL)
#define GTM_MCS_0       (*(volatile struct GTM_MCS_tag *)  0xFFD30000UL)
#define GTM_MCS_1       (*(volatile struct GTM_MCS_tag *)  0xFFD31000UL)
#define GTM_MCS_2       (*(volatile struct GTM_MCS_tag *)  0xFFD32000UL)
#define GTM_MCS_3       (*(volatile struct GTM_MCS_tag *)  0xFFD33000UL)
#define GTM_MCS_4       (*(volatile struct GTM_MCS_tag *)  0xFFD34000UL)
#define GTM_MCS_5       (*(volatile struct GTM_MCS_tag *)  0xFFD35000UL)
#define GTM_MON         (*(volatile struct GTM_MON_tag *)  0xFFD00180UL)
#define GTM_SPE_0       (*(volatile struct GTM_SPE_tag *)  0xFFD00800UL)
#define GTM_SPE_1       (*(volatile struct GTM_SPE_tag *)  0xFFD00880UL)
#define GTM_SPE_2       (*(volatile struct GTM_SPE_tag *)  0xFFD00900UL)
#define GTM_SPE_3       (*(volatile struct GTM_SPE_tag *)  0xFFD00980UL)
#define GTM_TBU         (*(volatile struct GTM_TBU_tag *)  0xFFD00100UL)
#define GTM_TIM_0       (*(volatile struct GTM_TIM_tag *)  0xFFD01000UL)
#define GTM_TIM_1       (*(volatile struct GTM_TIM_tag *)  0xFFD01800UL)
#define GTM_TIM_2       (*(volatile struct GTM_TIM_tag *)  0xFFD02000UL)
#define GTM_TIM_3       (*(volatile struct GTM_TIM_tag *)  0xFFD02800UL)
#define GTM_TIM_4       (*(volatile struct GTM_TIM_tag *)  0xFFD03000UL)
#define GTM_TIM_5       (*(volatile struct GTM_TIM_tag *)  0xFFD03800UL)
#define GTM_TOM_0       (*(volatile struct GTM_TOM_tag *)  0xFFD08000UL)
#define GTM_TOM_1       (*(volatile struct GTM_TOM_tag *)  0xFFD08800UL)
#define GTM_TOM_2       (*(volatile struct GTM_TOM_tag *)  0xFFD09000UL)
#define GTM_TOM_3       (*(volatile struct GTM_TOM_tag *)  0xFFD09800UL)
#define GTM_TOM_4       (*(volatile struct GTM_TOM_tag *)  0xFFD0A000UL)
#define I2C_0           (*(volatile struct I2C_tag *)      0xFFE68000UL)
#define I2C_1           (*(volatile struct I2C_tag *)      0xFBE68000UL)
#define INTC_0          (*(volatile struct INTC_tag *)     0xFC040000UL)
#define IRCOSC          (*(volatile struct IRCOSC_tag *)   0xFFFB0000UL)
#define JDC             (*(volatile struct JDC_tag *)      0xFFF3C000UL)
#define JTAGM           (*(volatile struct JTAGM_tag *)    0xFFF48000UL)
#define LFAST_0         (*(volatile struct LFAST_tag *)    0xFFFD8000UL)
#define LINFlexD_0      (*(volatile struct LINFlexD_tag *) 0xFFE8C000UL)
#define LINFlexD_1      (*(volatile struct LINFlexD_tag *) 0xFFE90000UL)
#define LINFlexD_2      (*(volatile struct LINFlexD_tag *) 0xFBE8C000UL)
#define LINFlexD_3      (*(volatile struct LINFlexD_tag *) 0xFFE94000UL)
#define LINFlexD_4      (*(volatile struct LINFlexD_tag *) 0xFFE98000UL)
#define LINFlexD_5      (*(volatile struct LINFlexD_tag *) 0xFFE9C000UL)
#define LINFlexD_6      (*(volatile struct LINFlexD_tag *) 0xFFEA0000UL)
#define LINFlexD_7      (*(volatile struct LINFlexD_tag *) 0xFBE90000UL)
#define LINFlexD_8      (*(volatile struct LINFlexD_tag *) 0xFBE94000UL)
#define LINFlexD_9      (*(volatile struct LINFlexD_tag *) 0xFBE98000UL)
#define LINFlexD_10     (*(volatile struct LINFlexD_tag *) 0xFBE9C000UL)
#define LINFlexD_11     (*(volatile struct LINFlexD_tag *) 0xFBEA0000UL)
#define LINFlexD_12     (*(volatile struct LINFlexD_tag *) 0xFBEA4000UL)
#define LINFlexD_14     (*(volatile struct LINFlexD_tag *) 0xFFEA8000UL)
#define LINFlexD_15     (*(volatile struct LINFlexD_tag *) 0xFBEA8000UL)
#define LINFlexD_16     (*(volatile struct LINFlexD_tag *) 0xFFEAC000UL)
#define I2S_1      		(*(volatile struct I2SM_tag *)     0xFBEE0000UL)
#define I2S_1_SLV      	(*(volatile struct I2SS_tag *)     0xFBEE0800UL)
#define I2S_2      		(*(volatile struct I2SM_tag *)     0xFBEE4000UL)
#define I2S_2_SLV      	(*(volatile struct I2SS_tag *)     0xFBEE4800UL)
#define MC_CGM          (*(volatile struct MC_CGM_tag *)   0xFFFB0000UL)
#define MC_ME           (*(volatile struct MC_ME_tag *)    0xFFFB8000UL)
#define MC_PCU          (*(volatile struct MC_PCU_tag *)   0xFFFA0000UL)
#define MC_RGM          (*(volatile struct MC_RGM_tag *)   0xFFFA8000UL)
#define MEMU            (*(volatile struct MEMU_tag *)     0xFFF50000UL)
#define IMA             (*(volatile struct IMA_tag *)      0xFFF54000UL)
#define CAN_SAMPLE_1	(*(volatile struct CAN_SAMPLER_tag *) 0xFFEB4000UL)
#define M_CAN_1         (*(volatile struct M_CAN_tag *)    0xFFEE4000UL)
#define M_CAN_2         (*(volatile struct M_CAN_tag *)    0xFFEE8000UL)
#define M_CAN_3         (*(volatile struct M_CAN_tag *)    0xFFEEC000UL)
#define M_CAN_4         (*(volatile struct M_CAN_tag *)    0xFFEF0000UL)
#define M_CAN_5         (*(volatile struct M_CAN_tag *)    0xFFEF4000UL)
#define M_CAN_6         (*(volatile struct M_CAN_tag *)    0xFFEF8000UL)
#define M_CAN_7         (*(volatile struct M_CAN_tag *)    0xFFEFC000UL)
#define M_CAN_8         (*(volatile struct M_CAN_tag *)    0xFFF00000UL)
#define M_CAN_9         (*(volatile struct M_CAN_tag *)    0xFFEBC000UL)
#define M_CAN_10        (*(volatile struct M_CAN_tag *)    0xFFEC0000UL)
#define M_CAN_11        (*(volatile struct M_CAN_tag *)    0xFFEC4000UL)
#define M_CAN_12        (*(volatile struct M_CAN_tag *)    0xFFEC8000UL)
#define CANFD_1         (*(volatile struct CANFD_tag *)    0xFBED8000UL)
#define CANFD_9         (*(volatile struct CANFD_tag *)    0xFBEB8000UL)
#define M_TTCAN         (*(volatile struct M_TTCAN_tag *)  0xFFEDC000UL)
#define PASS            (*(volatile struct PASS_tag *)     0xFFFF4000UL)
#define PBRIDGE_A       (*(volatile struct PBRIDGE_tag *)  0xFC000000UL)
#define PBRIDGE_B       (*(volatile struct PBRIDGE_tag *)  0xF8000000UL)
#define PCM             (*(volatile struct PCM_tag *)      0xFC028000UL)
#define PFLASH          (*(volatile struct PFLASH_tag *)   0xFC030000UL)
#define PIT_0           (*(volatile struct PIT_tag *)      0xFFF84000UL)
#define PIT_1           (*(volatile struct PIT_tag *)      0xFFF80000UL)
#define PLLDIG          (*(volatile struct PLLDIG_tag *)   0xFFFB0100UL)
#define PMCDIG          (*(volatile struct PMCDIG_tag *)   0xFFFA0400UL)
#define PRAMC           (*(volatile struct PRAMC_tag *)    0xFC020000UL)
#define PSI5_0          (*(volatile struct PSI5_tag *)     0xFFE40000UL)
#define PSI5_1          (*(volatile struct PSI5_tag *)     0xFBE40000UL)
#define PSI5S           (*(volatile struct PSI5S_tag *)    0xFBF74000UL)
#define EMIOS_0         (*(volatile struct eMIOS_tag *)    0xFFDEC000UL)
#define EMIOS_1         (*(volatile struct eMIOS_tag *)    0xFBF78000UL)
#define REG_PROT        (*(volatile struct REG_PROT_tag *) 0UL)
#define SDADC_0         (*(volatile struct SDADC_tag *)    0xFFF0C000UL)
#define SDADC_1         (*(volatile struct SDADC_tag *)    0xFBF0C000UL)
#define SDADC_2         (*(volatile struct SDADC_tag *)    0xFFF10000UL)
#define SDADC_3         (*(volatile struct SDADC_tag *)    0xFBF10000UL)
#define SDADC_4         (*(volatile struct SDADC_tag *)    0xFFF14000UL)
#define SDADC_6         (*(volatile struct SDADC_tag *)    0xFFF18000UL)
#define SDADC_7         (*(volatile struct SDADC_tag *)    0xFBF18000UL)
#define SDADC_8         (*(volatile struct SDADC_tag *)    0xFFF1C000UL)
#define EQADC0_ADC01    (*(volatile struct EQADC_tag *)    0xFFE00000UL)
#define EQADC1_ADC23    (*(volatile struct EQADC_tag *)    0xFBE08000UL)
#define EQADC2_ADC45    (*(volatile struct EQADC_tag *)    0xFFE10000UL)
#define EQADC3_ADC67    (*(volatile struct EQADC_tag *)    0xFBE18000UL)
#define EQADC4_ADC89    (*(volatile struct EQADC_tag *)    0xFBE20000UL)
#define SEMA42          (*(volatile struct SEMA42_tag *)   0xFC03C000UL)
#define SIPI_0          (*(volatile struct SIPI_tag *)     0xFFFD0000UL)
#define SIUL2           (*(volatile struct SIUL2_tag *)    0xFFFC0000UL)
#define SIUL2_REG_PROT	(*(volatile struct REG_PROT_tag *) 0xFFFC0000UL)
#define IGF 			(*(volatile struct IGF_tag *) 	   0xFFFC1800UL)
#define SMPU_0          (*(volatile struct SMPU_tag *)     0xFC010000UL)
#define SMPU_1          (*(volatile struct SMPU_tag *)     0xFC014000UL)
#define SRX_0           (*(volatile struct SRX_tag *)      0xFFE5C000UL)
#define SRX_1           (*(volatile struct SRX_tag *)      0xFBE5C000UL)
#define SSCM            (*(volatile struct SSCM_tag *)     0xFFFF8000UL)
#define STCU2           (*(volatile struct STCU2_tag *)    0xFFF44000UL)
#define STM_0           (*(volatile struct STM_tag *)      0xFC068000UL)
#define STM_1           (*(volatile struct STM_tag *)      0xFC06C000UL)
#define STM_2           (*(volatile struct STM_tag *)      0xFC070000UL)
#define SWT_0           (*(volatile struct SWT_tag *)      0xFC050000UL)
#define SWT_1           (*(volatile struct SWT_tag *)      0xFC054000UL)
#define SWT_2           (*(volatile struct SWT_tag *)      0xFC058000UL)
#define SWT_3           (*(volatile struct SWT_tag *)      0xFC05C000UL)
#define TDM             (*(volatile struct TDM_tag *)      0xFFF34000UL)
#define WKPU            (*(volatile struct WKPU_tag *)     0xFFF98000UL)
#define XBAR_0          (*(volatile struct XBAR_tag *)     0xFC004000UL)
#define XBAR_1          (*(volatile struct XBAR_tag *)     0xFC008000UL)
#define XBIC_0          (*(volatile struct XBIC_tag *)     0xFC018000UL)
#define XBIC_1          (*(volatile struct XBIC_tag *)     0xFC01C000UL)
#define XOSC            (*(volatile struct XOSC_tag *)     0xFFFB0080UL)
#define eDMA_0          (*(volatile struct eDMA_tag *)     0xFC0A0000UL)
#define eDMA_1          (*(volatile struct eDMA_tag *)     0xFC0A4000UL)
#define ETHERNET_0      (*(volatile struct ETHERNET_0_tag*)0xFC0B0000UL)
#define RTC_API         (*(volatile struct RTCAPI_tag *)   0xFFEB0000UL)
#define SSI0			(*(volatile struct SSI_tag*)       0xB0000000UL)
#define SSI1			(*(volatile struct SSI_tag*)       0xC0000000UL)
#define CSRX_0_0        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 0U*64U))
#define CSRX_0_1        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 1U*64U))
#define CSRX_0_2        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 2U*64U))
#define CSRX_0_3        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 3U*64U))
#define CSRX_0_4        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 4U*64U))
#define CSRX_0_5        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 5U*64U))
#define CSRX_0_6        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 6U*64U))
#define CSRX_0_7        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 7U*64U))
#define CSRX_1_0        (*(volatile struct CSRX_tag *)    (0xFBE58000UL + 0U*64U))
#define CSRX_1_1        (*(volatile struct CSRX_tag *)    (0xFBE58000UL + 1U*64U))
#define CSRX_1_2        (*(volatile struct CSRX_tag *)    (0xFBE58000UL + 2U*64U))
#define CSRX_1_3        (*(volatile struct CSRX_tag *)    (0xFBE58000UL + 3U*64U))
#define CSRX_1_4        (*(volatile struct CSRX_tag *)    (0xFBE58000UL + 4U*64U))
#define CSRX_1_5        (*(volatile struct CSRX_tag *)    (0xFBE58000UL + 5U*64U))
#define CSRX_1_6        (*(volatile struct CSRX_tag *)    (0xFBE58000UL + 6U*64U))
#define HSM 			   (*(volatile struct HSM_tag *)	    0xFFF30000UL)


#ifdef __MWERKS__
#pragma pop
#endif
#ifdef __ghs__
#pragma ghs endnowarning
#endif
#ifdef  __cplusplus
}
#endif
#endif /* ifdef CCFC3007PT_H_ */
#endif  /* defined(CCFC3007PT) */

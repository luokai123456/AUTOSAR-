/**************************************************************************** 
* 
* Copyright (c) 2025  C*Core -   All Rights Reserved
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* @file     CCFC3008PCSN.h
* @version  1.0
* @date     2025 - 06 - 05
* @brief    Initial version.
*
*****************************************************************************/

#if defined(CCFC3008PCSN)
#ifndef CCFC3008PCSN_H_
#define CCFC3008PCSN_H_

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
#include "module/c55fmc_sm_blk_reg.h"
#include "module/cmu_reg.h"
#include "module/crc_reg.h"
#include "module/dma_mux_reg.h"
#include "module/dspi_reg.h"
#include "module/etpu_reg.h"
#include "module/dts_reg.h"
#include "module/ebi_reg.h"
#include "module/fccu_reg.h"
#include "module/fec_reg.h"
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
#include "module/gtm410_reg.h"
#include "module/ccu7_reg.h"
#include "module/eiomux2_reg.h"
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
#define DSPI_2          (*(volatile struct DSPI_tag *)     0xFBE70000UL)
#define DSPI_3          (*(volatile struct DSPI_tag *)     0xFBE74000UL)
#define DSPI_4          (*(volatile struct DSPI_tag *)     0xFFE78000UL)
#define DSPI_5          (*(volatile struct DSPI_tag *)     0xFBE78000UL)
#define DSPI_6          (*(volatile struct DSPI_tag *)     0xFFE7C000UL)
#define DSPI_12         (*(volatile struct DSPI_tag *)     0xFFE88000UL)
#define DTS             (*(volatile struct DTS_tag *)      0xFFF38000UL)
#define EBI             (*(volatile struct EBI_tag *)      0xFFFF0000UL)
#define FCCU            (*(volatile struct FCCU_tag *)     0xFBF58000UL)
#define FEC             (*(volatile struct FEC_tag *)      0xFC0B0000UL)
#define GTM4            (*(volatile struct GTM4_tag *)     0xFFD00000UL)
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
#define LINFlexD_5      (*(volatile struct LINFlexD_tag *) 0xFFE9C000UL)
#define LINFlexD_6      (*(volatile struct LINFlexD_tag *) 0xFFEA0000UL)
#define LINFlexD_9      (*(volatile struct LINFlexD_tag *) 0xFBE98000UL)
#define LINFlexD_10     (*(volatile struct LINFlexD_tag *) 0xFBE9C000UL)
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
#define EQADC0_ADC01    (*(volatile struct EQADC_tag *)    0xFFE00000UL)
#define EQADC1_ADC23    (*(volatile struct EQADC_tag *)    0xFBE08000UL)
#define SEMA42          (*(volatile struct SEMA42_tag *)   0xFC03C000UL)
#define SIPI_0          (*(volatile struct SIPI_tag *)     0xFFFD0000UL)
#define SIUL2           (*(volatile struct SIUL2_tag *)    0xFFFC0000UL)
#define SIUL2_REG_PROT	(*(volatile struct REG_PROT_tag *) 0xFFFC0000UL)
#define EIOMUX2         (*(volatile struct EIOMUX2_tag *)  0xFFFC4000UL)
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
#define SWT_3           (*(volatile struct SWT_tag *)      0xFC05C000UL)
#define SWT_7_AO        (*(volatile struct SWT_tag *)      0xFC060000UL)
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
#define CSRX_0_0        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 0*64))
#define CSRX_0_1        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 1*64))
#define CSRX_0_2        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 2*64))
#define CSRX_0_3        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 3*64))
#define CSRX_0_4        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 4*64))
#define CSRX_0_5        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 5*64))
#define CSRX_0_6        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 6*64))
#define CSRX_0_7        (*(volatile struct CSRX_tag *)    (0xFFE58000UL + 7*64))
#define CSRX_1_0        (*(volatile struct CSRX_tag *)    (0xFBE58000UL + 0*64))
#define CSRX_1_1        (*(volatile struct CSRX_tag *)    (0xFBE58000UL + 1*64))
#define CSRX_1_2        (*(volatile struct CSRX_tag *)    (0xFBE58000UL + 2*64))
#define CSRX_1_3        (*(volatile struct CSRX_tag *)    (0xFBE58000UL + 3*64))
#define CSRX_1_4        (*(volatile struct CSRX_tag *)    (0xFBE58000UL + 4*64))
#define CSRX_1_5        (*(volatile struct CSRX_tag *)    (0xFBE58000UL + 5*64))
#define CSRX_1_6        (*(volatile struct CSRX_tag *)    (0xFBE58000UL + 6*64))
#define CCU7_0          (*(volatile struct CCU7_Type *)    0xFFDF0000UL)
#define CCU7_1          (*(volatile struct CCU7_Type *)    0xFBF7C000UL)
#define HSM             (*(volatile struct HSM_tag *)      0xFFF30000UL)

#ifdef __MWERKS__
#pragma pop
#endif
#ifdef __ghs__
#pragma ghs endnowarning
#endif
#ifdef  __cplusplus
}
#endif
#endif /* ifdef CCFC3008PCSN_H_ */
#endif  /* defined(CCFC3008PCSN) */

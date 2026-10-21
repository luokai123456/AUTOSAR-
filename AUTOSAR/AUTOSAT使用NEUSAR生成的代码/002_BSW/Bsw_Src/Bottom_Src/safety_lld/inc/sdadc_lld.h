/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     sdadc_lld.h
* @version  1.0
* @date     2023 - 09 - 01
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/
/* PRQA S 0722,1534,0779,2053 EOF*/

#ifndef SAF_SDADC_LLD_H_
#define SAF_SDADC_LLD_H_
#include "derivative.h"
#include "status.h"
#include "edma_lld.h"
#include "intc_lld.h"
#include "console.h"

#define SAF_SDADC_DEV_ERROR             (TRUE)

#define ADC_SAF_SDADC_MAX_INSTANCE      (9u)

/* @brief SDADC instance base address */
#define SAf_SDADC0_BASEADDR             ((uint32_t)0xFFF0C000UL)
#define SAf_SDADC1_BASEADDR             ((uint32_t)0xFBF0C000UL)
#define SAf_SDADC2_BASEADDR             ((uint32_t)0xFFF10000UL)
#define SAf_SDADC3_BASEADDR             ((uint32_t)0xFBF10000UL)
#define SAf_SDADC4_BASEADDR             ((uint32_t)0xFFF14000UL)
#define SAf_SDADC6_BASEADDR             ((uint32_t)0xFFF18000UL)
#define SAf_SDADC7_BASEADDR             ((uint32_t)0xFBF18000UL)
#define SAf_SDADC8_BASEADDR             ((uint32_t)0xFFF1C000UL)

/* @brief EQADC instance base pointer */
#define SAf_SDADC0_PTR                  ((SAF_SDADC_TagType *) SAf_SDADC0_BASEADDR)
#define SAf_SDADC1_PTR                  ((SAF_SDADC_TagType *) SAf_SDADC1_BASEADDR)
#define SAf_SDADC2_PTR                  ((SAF_SDADC_TagType *) SAf_SDADC2_BASEADDR)
#define SAf_SDADC3_PTR                  ((SAF_SDADC_TagType *) SAf_SDADC3_BASEADDR)
#define SAf_SDADC4_PTR                  ((SAF_SDADC_TagType *) SAf_SDADC4_BASEADDR)
#define SAf_SDADC6_PTR                  ((SAF_SDADC_TagType *) SAf_SDADC6_BASEADDR)
#define SAf_SDADC7_PTR                  ((SAF_SDADC_TagType *) SAf_SDADC7_BASEADDR)
#define SAf_SDADC8_PTR                  ((SAF_SDADC_TagType *) SAf_SDADC8_BASEADDR)

/* @brief EQADC instance base address array */
#define SAF_SDADC_BASE_ADDR_ARRAY       {SAf_SDADC0_BASEADDR, SAf_SDADC1_BASEADDR, SAf_SDADC2_BASEADDR, SAf_SDADC3_BASEADDR, SAf_SDADC4_BASEADDR, \
                                                NULL, SAf_SDADC6_BASEADDR, SAf_SDADC7_BASEADDR, SAf_SDADC8_BASEADDR}

/* @brief EQADC instance base pointer array */
#define SAF_SDADC_BASE_PTR_ARRAY        {SAf_SDADC0_PTR, SAf_SDADC1_PTR, SAf_SDADC2_PTR, SAf_SDADC3_PTR, SAf_SDADC4_PTR, \
                                           NULL, SAf_SDADC6_PTR, SAf_SDADC7_PTR, SAf_SDADC8_PTR}
/*******************************************************************************
 * Safety SDADC Register Bit Fields
 *******************************************************************************/
/* CTRL Bit Fields */
#define SAF_SDADC_CTRL_EN_MASK                      0x1u
#define SAF_SDADC_CTRL_EN_SHIFT                     0u
#define SAF_SDADC_CTRL_EN_WIDTH                     1u
#define SAF_SDADC_CTRL_EN(x)                        (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_CTRL_EN_SHIFT))&SAF_SDADC_CTRL_EN_MASK)
/* GAINCORR Bit Fields */
#define SAF_SDADC_GAINCORR_GAINFACTOR_MASK          0x1FFFu
#define SAF_SDADC_GAINCORR_GAINFACTOR_SHIFT         0u
#define SAF_SDADC_GAINCORR_GAINFACTOR_WIDTH         13u
#define SAF_SDADC_GAINCORR_GAINFACTOR(x)            (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_GAINCORR_GAINFACTOR_SHIFT))&SAF_SDADC_GAINCORR_GAINFACTOR_MASK)
#define SAF_SDADC_GAINCORR_CICSHIFT_MASK            0x1F0000u
#define SAF_SDADC_GAINCORR_CICSHIFT_SHIFT           16u
#define SAF_SDADC_GAINCORR_CICSHIFT_WIDTH           5u
#define SAF_SDADC_GAINCORR_CICSHIFT(x)              (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_GAINCORR_CICSHIFT_SHIFT))&SAF_SDADC_GAINCORR_CICSHIFT_MASK)
/* GAINCAL Bit Fields */
#define SAF_SDADC_GAINCAL_CALFACTOR_MASK            0x1FFFu
#define SAF_SDADC_GAINCAL_CALFACTOR_SHIFT           0u
#define SAF_SDADC_GAINCAL_CALFACTOR_WIDTH           13u
#define SAF_SDADC_GAINCAL_CALFACTOR(x)              (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_GAINCAL_CALFACTOR_SHIFT))&SAF_SDADC_GAINCAL_CALFACTOR_MASK)
/* FCFGC Bit Fields */
#define SAF_SDADC_FCFGC_CFMDF_MASK                  0x1FFu
#define SAF_SDADC_FCFGC_CFMDF_SHIFT                 0u
#define SAF_SDADC_FCFGC_CFMDF_WIDTH                 9u
#define SAF_SDADC_FCFGC_CFMDF(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFGC_CFMDF_SHIFT))&SAF_SDADC_FCFGC_CFMDF_MASK)
#define SAF_SDADC_FCFGC_CFMSV_MASK                  0x1FF0000u
#define SAF_SDADC_FCFGC_CFMSV_SHIFT                 16u
#define SAF_SDADC_FCFGC_CFMSV_WIDTH                 9u
#define SAF_SDADC_FCFGC_CFMSV(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFGC_CFMSV_SHIFT))&SAF_SDADC_FCFGC_CFMSV_MASK)
/* FCNTC Bit Fields */
#define SAF_SDADC_FCNTC_CFMDCNT_MASK                0x1FFu
#define SAF_SDADC_FCNTC_CFMDCNT_SHIFT               0u
#define SAF_SDADC_FCNTC_CFMDCNT_WIDTH               9u
#define SAF_SDADC_FCNTC_CFMDCNT(x)                  (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCNTC_CFMDCNT_SHIFT))&SAF_SDADC_FCNTC_CFMDCNT_MASK)
/* FCFGM Bit Fields */
#define SAF_SDADC_FCFGM_FIR0EN_MASK                 0x1u
#define SAF_SDADC_FCFGM_FIR0EN_SHIFT                0u
#define SAF_SDADC_FCFGM_FIR0EN_WIDTH                1u
#define SAF_SDADC_FCFGM_FIR0EN(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFGM_FIR0EN_SHIFT))&SAF_SDADC_FCFGM_FIR0EN_MASK)
#define SAF_SDADC_FCFGM_FIR1EN_MASK                 0x2u
#define SAF_SDADC_FCFGM_FIR1EN_SHIFT                1u
#define SAF_SDADC_FCFGM_FIR1EN_WIDTH                1u
#define SAF_SDADC_FCFGM_FIR1EN(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFGM_FIR1EN_SHIFT))&SAF_SDADC_FCFGM_FIR1EN_MASK)
#define SAF_SDADC_FCFGM_OVCEN_MASK                  0x4u
#define SAF_SDADC_FCFGM_OVCEN_SHIFT                 2u
#define SAF_SDADC_FCFGM_OVCEN_WIDTH                 1u
#define SAF_SDADC_FCFGM_OVCEN(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFGM_OVCEN_SHIFT))&SAF_SDADC_FCFGM_OVCEN_MASK)
#define SAF_SDADC_FCFGM_FIR1DEC_MASK                0x8u
#define SAF_SDADC_FCFGM_FIR1DEC_SHIFT               3u
#define SAF_SDADC_FCFGM_FIR1DEC_WIDTH               1u
#define SAF_SDADC_FCFGM_FIR1DEC(x)                  (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFGM_FIR1DEC_SHIFT))&SAF_SDADC_FCFGM_FIR1DEC_MASK)
#define SAF_SDADC_FCFGM_CICMOD_MASK                 0x10u
#define SAF_SDADC_FCFGM_CICMOD_SHIFT                4u
#define SAF_SDADC_FCFGM_CICMOD_WIDTH                1u
#define SAF_SDADC_FCFGM_CICMOD(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFGM_CICMOD_SHIFT))&SAF_SDADC_FCFGM_CICMOD_MASK)
#define SAF_SDADC_FCFGM_PFEN_MASK                   0x20u
#define SAF_SDADC_FCFGM_PFEN_SHIFT                  5u
#define SAF_SDADC_FCFGM_PFEN_WIDTH                  1u
#define SAF_SDADC_FCFGM_PFEN(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFGM_PFEN_SHIFT))&SAF_SDADC_FCFGM_PFEN_MASK)
#define SAF_SDADC_FCFGM_COMPTR_EN_MASK              0x40u
#define SAF_SDADC_FCFGM_COMPTR_EN_SHIFT             6u
#define SAF_SDADC_FCFGM_COMPTR_EN_WIDTH             1u
#define SAF_SDADC_FCFGM_COMPTR_EN(x)                (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFGM_COMPTR_EN_SHIFT))&SAF_SDADC_FCFGM_COMPTR_EN_MASK)
#define SAF_SDADC_FCFGM_EXT_MESH_EN_MASK            0x80u
#define SAF_SDADC_FCFGM_EXT_MESH_EN_SHIFT           7u
#define SAF_SDADC_FCFGM_EXT_MESH_EN_WIDTH           1u
#define SAF_SDADC_FCFGM_EXT_MESH_EN(x)              (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFGM_EXT_MESH_EN_SHIFT))&SAF_SDADC_FCFGM_EXT_MESH_EN_MASK)
#define SAF_SDADC_FCFGM_OCEN_MASK                   0x700u
#define SAF_SDADC_FCFGM_OCEN_SHIFT                  8u
#define SAF_SDADC_FCFGM_OCEN_WIDTH                  3u
#define SAF_SDADC_FCFGM_OCEN(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFGM_OCEN_SHIFT))&SAF_SDADC_FCFGM_OCEN_MASK)
#define SAF_SDADC_FCFGM_CH_WRAP_EN_MASK             0x800u
#define SAF_SDADC_FCFGM_CH_WRAP_EN_SHIFT            11u
#define SAF_SDADC_FCFGM_CH_WRAP_EN_WIDTH            1u
#define SAF_SDADC_FCFGM_CH_WRAP_EN(x)               (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFGM_CH_WRAP_EN_SHIFT))&SAF_SDADC_FCFGM_CH_WRAP_EN_MASK)
#define SAF_SDADC_FCFGM_DIFF_EN_MASK                0x1000u
#define SAF_SDADC_FCFGM_DIFF_EN_SHIFT               12u
#define SAF_SDADC_FCFGM_DIFF_EN_WIDTH               1u
#define SAF_SDADC_FCFGM_DIFF_EN(x)                  (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFGM_DIFF_EN_SHIFT))&SAF_SDADC_FCFGM_DIFF_EN_MASK)
#define SAF_SDADC_FCFGM_CALIB_EN_MASK               0x10000u
#define SAF_SDADC_FCFGM_CALIB_EN_SHIFT              16u
#define SAF_SDADC_FCFGM_CALIB_EN_WIDTH              1u
#define SAF_SDADC_FCFGM_CALIB_EN(x)                 (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFGM_CALIB_EN_SHIFT))&SAF_SDADC_FCFGM_CALIB_EN_MASK)
/* OFFCOMP Bit Fields */
#define SAF_SDADC_OFFCOMP_OFFSET_MASK               0xFFFFu
#define SAF_SDADC_OFFCOMP_OFFSET_SHIFT              0u
#define SAF_SDADC_OFFCOMP_OFFSET_WIDTH              16u
#define SAF_SDADC_OFFCOMP_OFFSET(x)                 (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_OFFCOMP_OFFSET_SHIFT))&SAF_SDADC_OFFCOMP_OFFSET_MASK)
/* IECFG Bit Fields */
#define SAF_SDADC_IECFG_FWM_INT_EN_MASK             0x1u
#define SAF_SDADC_IECFG_FWM_INT_EN_SHIFT            0u
#define SAF_SDADC_IECFG_FWM_INT_EN_WIDTH            1u
#define SAF_SDADC_IECFG_FWM_INT_EN(x)               (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_IECFG_FWM_INT_EN_SHIFT))&SAF_SDADC_IECFG_FWM_INT_EN_MASK)
#define SAF_SDADC_IECFG_FOV_INT_EN_MASK             0x2u
#define SAF_SDADC_IECFG_FOV_INT_EN_SHIFT            1u
#define SAF_SDADC_IECFG_FOV_INT_EN_WIDTH            1u
#define SAF_SDADC_IECFG_FOV_INT_EN(x)               (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_IECFG_FOV_INT_EN_SHIFT))&SAF_SDADC_IECFG_FOV_INT_EN_MASK)
#define SAF_SDADC_IECFG_DOV_INT_EN_MASK             0x4u
#define SAF_SDADC_IECFG_DOV_INT_EN_SHIFT            2u
#define SAF_SDADC_IECFG_DOV_INT_EN_WIDTH            1u
#define SAF_SDADC_IECFG_DOV_INT_EN(x)               (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_IECFG_DOV_INT_EN_SHIFT))&SAF_SDADC_IECFG_DOV_INT_EN_MASK)
#define SAF_SDADC_IECFG_DMA_REQ_EN_MASK             0x8u
#define SAF_SDADC_IECFG_DMA_REQ_EN_SHIFT            3u
#define SAF_SDADC_IECFG_DMA_REQ_EN_WIDTH            1u
#define SAF_SDADC_IECFG_DMA_REQ_EN(x)               (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_IECFG_DMA_REQ_EN_SHIFT))&SAF_SDADC_IECFG_DMA_REQ_EN_WIDTH)
/* FCFG Bit Fields */
#define SAF_SDADC_FCFG_FIFOSIZE_MASK                0xFFu
#define SAF_SDADC_FCFG_FIFOSIZE_SHIFT               0u
#define SAF_SDADC_FCFG_FIFOSIZE_WIDTH               8u
#define SAF_SDADC_FCFG_FIFOSIZE(x)                  (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFG_FIFOSIZE_SHIFT))&SAF_SDADC_FCFG_FIFOSIZE_MASK)
#define SAF_SDADC_FCFG_FIFOWM_MASK                  0xFF00u
#define SAF_SDADC_FCFG_FIFOWM_SHIFT                 8u
#define SAF_SDADC_FCFG_FIFOWM_WIDTH                 8u
#define SAF_SDADC_FCFG_FIFOWM(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFG_FIFOWM_SHIFT))&SAF_SDADC_FCFG_FIFOWM_MASK)
#define SAF_SDADC_FCFG_INFOEN_MASK                  0x10000u
#define SAF_SDADC_FCFG_INFOEN_SHIFT                 16u
#define SAF_SDADC_FCFG_INFOEN_WIDTH                 1u
#define SAF_SDADC_FCFG_INFOEN(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFG_INFOEN_SHIFT))&SAF_SDADC_FCFG_INFOEN_MASK)
#define SAF_SDADC_FCFG_SIGNEN_MASK                  0x20000u
#define SAF_SDADC_FCFG_SIGNEN_SHIFT                 17u
#define SAF_SDADC_FCFG_SIGNEN_WIDTH                 1u
#define SAF_SDADC_FCFG_SIGNEN(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCFG_SIGNEN_SHIFT))&SAF_SDADC_FCFG_SIGNEN_MASK)
/* FDATA Bit Fields */
#define SAF_SDADC_FDATA_DATA_MASK                   0xFFFFFFFFu
#define SAF_SDADC_FDATA_DATA_SHIFT                  0u
#define SAF_SDADC_FDATA_DATA_WIDTH                  32u
#define SAF_SDADC_FDATA_DATA(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FDATA_DATA_SHIFT))&SAF_SDADC_FDATA_DATA_MASK)
/* ISTAT Bit Fields */
#define SAF_SDADC_ISTAT_NVALCNT_MASK                0x3Fu
#define SAF_SDADC_ISTAT_NVALCNT_SHIFT               0u
#define SAF_SDADC_ISTAT_NVALCNT_WIDTH               6u
#define SAF_SDADC_ISTAT_NVALCNT(x)                  (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_ISTAT_NVALCNT_SHIFT))&SAF_SDADC_ISTAT_NVALCNT_MASK)
#define SAF_SDADC_ISTAT_REPCNT_MASK                 0xF00u
#define SAF_SDADC_ISTAT_REPCNT_SHIFT                8u
#define SAF_SDADC_ISTAT_REPCNT_WIDTH                4u
#define SAF_SDADC_ISTAT_REPCNT(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_ISTAT_REPCNT_SHIFT))&SAF_SDADC_ISTAT_REPCNT_MASK)
#define SAF_SDADC_ISTAT_INTEN_MASK                  0x8000u
#define SAF_SDADC_ISTAT_INTEN_SHIFT                 15u
#define SAF_SDADC_ISTAT_INTEN_WIDTH                 1u
#define SAF_SDADC_ISTAT_INTEN(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_ISTAT_INTEN_SHIFT))&SAF_SDADC_ISTAT_INTEN_MASK)
/* IIVAL Bit Fields */
#define SAF_SDADC_IIVAL_IVAL_MASK                   0x3FFFFFFu
#define SAF_SDADC_IIVAL_IVAL_SHIFT                  0u
#define SAF_SDADC_IIVAL_IVAL_WIDTH                  26u
#define SAF_SDADC_IIVAL_IVAL(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_IIVAL_IVAL_SHIFT))&SAF_SDADC_IIVAL_IVAL_MASK)
/* IWCTR Bit Fields */
#define SAF_SDADC_IWCTR_ISC_MASK                    0x7u
#define SAF_SDADC_IWCTR_ISC_SHIFT                   0u
#define SAF_SDADC_IWCTR_ISC_WIDTH                   3u
#define SAF_SDADC_IWCTR_ISC(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_IWCTR_ISC_SHIFT))&SAF_SDADC_IWCTR_ISC_MASK)
#define SAF_SDADC_IWCTR_IWS_MASK                    0x10u
#define SAF_SDADC_IWCTR_IWS_SHIFT                   4u
#define SAF_SDADC_IWCTR_IWS_WIDTH                   1u
#define SAF_SDADC_IWCTR_IWS(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_IWCTR_IWS_SHIFT))&SAF_SDADC_IWCTR_IWS_MASK)
#define SAF_SDADC_IWCTR_FRC_MASK                    0x20u
#define SAF_SDADC_IWCTR_FRC_SHIFT                   5u
#define SAF_SDADC_IWCTR_FRC_WIDTH                   1u
#define SAF_SDADC_IWCTR_FRC(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_IWCTR_FRC_SHIFT))&SAF_SDADC_IWCTR_FRC_MASK)
#define SAF_SDADC_IWCTR_REPVAL_MASK                 0xF00u
#define SAF_SDADC_IWCTR_REPVAL_SHIFT                8u
#define SAF_SDADC_IWCTR_REPVAL_WIDTH                4u
#define SAF_SDADC_IWCTR_REPVAL(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_IWCTR_REPVAL_SHIFT))&SAF_SDADC_IWCTR_REPVAL_MASK)
#define SAF_SDADC_IWCTR_NVALDIS_MASK                0x3F0000u
#define SAF_SDADC_IWCTR_NVALDIS_SHIFT               16u
#define SAF_SDADC_IWCTR_NVALDIS_WIDTH               6u
#define SAF_SDADC_IWCTR_NVALDIS(x)                  (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_IWCTR_NVALDIS_SHIFT))&SAF_SDADC_IWCTR_NVALDIS_MASK)
#define SAF_SDADC_IWCTR_NVALINT_MASK                0x3F000000u
#define SAF_SDADC_IWCTR_NVALINT_SHIFT               24u
#define SAF_SDADC_IWCTR_NVALINT_WIDTH               6u
#define SAF_SDADC_IWCTR_NVALINT(x)                  (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_IWCTR_NVALINT_SHIFT))&SAF_SDADC_IWCTR_NVALINT_MASK)
/* DICFG Bit Fields */
#define SAF_SDADC_DICFG_ITRMODE_MASK                0x300000u
#define SAF_SDADC_DICFG_ITRMODE_SHIFT               20u
#define SAF_SDADC_DICFG_ITRMODE_WIDTH               2u
#define SAF_SDADC_DICFG_ITRMODE(x)                  (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_DICFG_ITRMODE_SHIFT))&SAF_SDADC_DICFG_ITRMODE_MASK)
/* BOUNDSEL Bit Fields */
#define SAF_SDADC_BOUNDSEL_BOUNDARYL_MASK           0xFFFFu
#define SAF_SDADC_BOUNDSEL_BOUNDARYL_SHIFT          0u
#define SAF_SDADC_BOUNDSEL_BOUNDARYL_WIDTH          16u
#define SAF_SDADC_BOUNDSEL_BOUNDARYL(x)             (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_BOUNDSEL_BOUNDARYL_SHIFT))&SAF_SDADC_BOUNDSEL_BOUNDARYL_MASK)
#define SAF_SDADC_BOUNDSEL_BOUNDARYU_MASK           0xFFFF0000u
#define SAF_SDADC_BOUNDSEL_BOUNDARYU_SHIFT          16u
#define SAF_SDADC_BOUNDSEL_BOUNDARYU_WIDTH          16u
#define SAF_SDADC_BOUNDSEL_BOUNDARYU(x)             (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_BOUNDSEL_BOUNDARYU_SHIFT))&SAF_SDADC_BOUNDSEL_BOUNDARYU_MASK)
/* WMINTSTAT Bit Fields */
#define SAF_SDADC_WMINTSTAT_FWM_INT_MASK            0x1u
#define SAF_SDADC_WMINTSTAT_FWM_INT_SHIFT           0u
#define SAF_SDADC_WMINTSTAT_FWM_INT_WIDTH           1u
#define SAF_SDADC_WMINTSTAT_FWM_INT(x)              (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_WMINTSTAT_FWM_INT_SHIFT))&SAF_SDADC_WMINTSTAT_FWM_INT_MASK)
/* OVINTSTAT Bit Fields */
#define SAF_SDADC_OVINTSTAT_FOV_INT_MASK            0x1u
#define SAF_SDADC_OVINTSTAT_FOV_INT_SHIFT           0u
#define SAF_SDADC_OVINTSTAT_FOV_INT_WIDTH           1u
#define SAF_SDADC_OVINTSTAT_FOV_INT(x)              (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_OVINTSTAT_FOV_INT_SHIFT))&SAF_SDADC_OVINTSTAT_FOV_INT_MASK)
#define SAF_SDADC_OVINTSTAT_DOV_INT_MASK            0x2u
#define SAF_SDADC_OVINTSTAT_DOV_INT_SHIFT           1u
#define SAF_SDADC_OVINTSTAT_DOV_INT_WIDTH           1u
#define SAF_SDADC_OVINTSTAT_DOV_INT(x)              (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_OVINTSTAT_DOV_INT_SHIFT))&SAF_SDADC_OVINTSTAT_DOV_INT_MASK)
/* OVSCFG Bit Fields */
#define SAF_SDADC_OVSCFG_SRFS_MASK                  0x3u
#define SAF_SDADC_OVSCFG_SRFS_SHIFT                 0u
#define SAF_SDADC_OVSCFG_SRFS_WIDTH                 2u
#define SAF_SDADC_OVSCFG_SRFS(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_OVSCFG_SRFS_SHIFT))&SAF_SDADC_OVSCFG_SRFS_MASK)
#define SAF_SDADC_OVSCFG_SRFRT_MASK                 0xCu
#define SAF_SDADC_OVSCFG_SRFRT_SHIFT                2u
#define SAF_SDADC_OVSCFG_SRFRT_WIDTH                2u
#define SAF_SDADC_OVSCFG_SRFRT(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_OVSCFG_SRFRT_SHIFT))&SAF_SDADC_OVSCFG_SRFRT_MASK)
#define SAF_SDADC_OVSCFG_SDM_MASK                   0x10u
#define SAF_SDADC_OVSCFG_SDM_SHIFT                  4u
#define SAF_SDADC_OVSCFG_SDM_WIDTH                  2u
#define SAF_SDADC_OVSCFG_SDM(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_OVSCFG_SDM_SHIFT))&SAF_SDADC_OVSCFG_SDM_MASK)
#define SAF_SDADC_OVSCFG_SDTH_MASK                  0x7FF0000u
#define SAF_SDADC_OVSCFG_SDTH_SHIFT                 16u
#define SAF_SDADC_OVSCFG_SDTH_WIDTH                 11u
#define SAF_SDADC_OVSCFG_SDTH(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_OVSCFG_SDTH_SHIFT))&SAF_SDADC_OVSCFG_SDTH_MASK)
/* HTCFG Bit Fields */
#define SAF_SDADC_HTCFG_HT0_MASK                    0x3u
#define SAF_SDADC_HTCFG_HT0_SHIFT                   0u
#define SAF_SDADC_HTCFG_HT0_WIDTH                   2u
#define SAF_SDADC_HTCFG_HT0(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT0_SHIFT))&SAF_SDADC_HTCFG_HT0_MASK)
#define SAF_SDADC_HTCFG_HT1_MASK                    0xCu
#define SAF_SDADC_HTCFG_HT1_SHIFT                   2u
#define SAF_SDADC_HTCFG_HT1_WIDTH                   2u
#define SAF_SDADC_HTCFG_HT1(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT1_SHIFT))&SAF_SDADC_HTCFG_HT1_MASK)
#define SAF_SDADC_HTCFG_HT2_MASK                    0x30u
#define SAF_SDADC_HTCFG_HT2_SHIFT                   4u
#define SAF_SDADC_HTCFG_HT2_WIDTH                   2u
#define SAF_SDADC_HTCFG_HT2(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT2_SHIFT))&SAF_SDADC_HTCFG_HT2_MASK)
#define SAF_SDADC_HTCFG_HT3_MASK                    0xC0u
#define SAF_SDADC_HTCFG_HT3_SHIFT                   6u
#define SAF_SDADC_HTCFG_HT3_WIDTH                   2u
#define SAF_SDADC_HTCFG_HT3(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT3_SHIFT))&SAF_SDADC_HTCFG_HT3_MASK)
#define SAF_SDADC_HTCFG_HT4_MASK                    0x300u
#define SAF_SDADC_HTCFG_HT4_SHIFT                   8u
#define SAF_SDADC_HTCFG_HT4_WIDTH                   2u
#define SAF_SDADC_HTCFG_HT4(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT4_SHIFT))&SAF_SDADC_HTCFG_HT4_MASK)
#define SAF_SDADC_HTCFG_HT5_MASK                    0xC00u
#define SAF_SDADC_HTCFG_HT5_SHIFT                   10u
#define SAF_SDADC_HTCFG_HT5_WIDTH                   2u
#define SAF_SDADC_HTCFG_HT5(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT5_SHIFT))&SAF_SDADC_HTCFG_HT5_MASK)
#define SAF_SDADC_HTCFG_HT6_MASK                    0x3000u
#define SAF_SDADC_HTCFG_HT6_SHIFT                   12u
#define SAF_SDADC_HTCFG_HT6_WIDTH                   2u
#define SAF_SDADC_HTCFG_HT6(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT6_SHIFT))&SAF_SDADC_HTCFG_HT6_MASK)
#define SAF_SDADC_HTCFG_HT7_MASK                    0xC000u
#define SAF_SDADC_HTCFG_HT7_SHIFT                   14u
#define SAF_SDADC_HTCFG_HT7_WIDTH                   2u
#define SAF_SDADC_HTCFG_HT7(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT7_SHIFT))&SAF_SDADC_HTCFG_HT7_MASK)
#define SAF_SDADC_HTCFG_HT8_MASK                    0x30000u
#define SAF_SDADC_HTCFG_HT8_SHIFT                   16u
#define SAF_SDADC_HTCFG_HT8_WIDTH                   2u
#define SAF_SDADC_HTCFG_HT8(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT8_SHIFT))&SAF_SDADC_HTCFG_HT8_MASK)
#define SAF_SDADC_HTCFG_HT9_MASK                    0xC0000u
#define SAF_SDADC_HTCFG_HT9_SHIFT                   18u
#define SAF_SDADC_HTCFG_HT9_WIDTH                   2u
#define SAF_SDADC_HTCFG_HT9(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT9_SHIFT))&SAF_SDADC_HTCFG_HT9_MASK)
#define SAF_SDADC_HTCFG_HT10_MASK                   0x300000u
#define SAF_SDADC_HTCFG_HT10_SHIFT                  20u
#define SAF_SDADC_HTCFG_HT10_WIDTH                  2u
#define SAF_SDADC_HTCFG_HT10(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT10_SHIFT))&SAF_SDADC_HTCFG_HT10_MASK)
#define SAF_SDADC_HTCFG_HT11_MASK                   0xC00000u
#define SAF_SDADC_HTCFG_HT11_SHIFT                  22u
#define SAF_SDADC_HTCFG_HT11_WIDTH                  2u
#define SAF_SDADC_HTCFG_HT11(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT11_SHIFT))&SAF_SDADC_HTCFG_HT11_MASK)
#define SAF_SDADC_HTCFG_HT12_MASK                   0x3000000u
#define SAF_SDADC_HTCFG_HT12_SHIFT                  24u
#define SAF_SDADC_HTCFG_HT12_WIDTH                  2u
#define SAF_SDADC_HTCFG_HT12(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT12_SHIFT))&SAF_SDADC_HTCFG_HT12_MASK)
#define SAF_SDADC_HTCFG_HT13_MASK                   0xC000000u
#define SAF_SDADC_HTCFG_HT13_SHIFT                  26u
#define SAF_SDADC_HTCFG_HT13_WIDTH                  2u
#define SAF_SDADC_HTCFG_HT13(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT13_SHIFT))&SAF_SDADC_HTCFG_HT13_MASK)
#define SAF_SDADC_HTCFG_HT14_MASK                   0x30000000u
#define SAF_SDADC_HTCFG_HT14_SHIFT                  28u
#define SAF_SDADC_HTCFG_HT14_WIDTH                  2u
#define SAF_SDADC_HTCFG_HT14(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT14_SHIFT))&SAF_SDADC_HTCFG_HT14_MASK)
#define SAF_SDADC_HTCFG_HT15_MASK                   0xC0000000u
#define SAF_SDADC_HTCFG_HT15_SHIFT                  30u
#define SAF_SDADC_HTCFG_HT15_WIDTH                  2u
#define SAF_SDADC_HTCFG_HT15(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_HTCFG_HT15_SHIFT))&SAF_SDADC_HTCFG_HT15_MASK)
/* STCFG Bit Fields */
#define SAF_SDADC_STCFG_SH_EN_MASK                  0x1u
#define SAF_SDADC_STCFG_SH_EN_SHIFT                 0u
#define SAF_SDADC_STCFG_SH_EN_WIDTH                 1u
#define SAF_SDADC_STCFG_SH_EN(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_STCFG_SH_EN_SHIFT))&SAF_SDADC_STCFG_SH_EN_MASK)
#define SAF_SDADC_STCFG_SH_CLR_MASK                 0x2u
#define SAF_SDADC_STCFG_SH_CLR_SHIFT                1u
#define SAF_SDADC_STCFG_SH_CLR_WIDTH                1u
#define SAF_SDADC_STCFG_SH_CLR(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_STCFG_SH_CLR_SHIFT))&SAF_SDADC_STCFG_SH_CLR_MASK)
#define SAF_SDADC_STCFG_FSRSTN_MASK                 0x4u
#define SAF_SDADC_STCFG_FSRSTN_SHIFT                2u
#define SAF_SDADC_STCFG_FSRSTN_WIDTH                1u
#define SAF_SDADC_STCFG_FSRSTN(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_STCFG_FSRSTN_SHIFT))&SAF_SDADC_STCFG_FSRSTN_MASK)
/* FCDIS Bit Fields */
#define SAF_SDADC_FCDIS_FCDIS_EN_MASK               0x1u
#define SAF_SDADC_FCDIS_FCDIS_EN_SHIFT              0u
#define SAF_SDADC_FCDIS_FCDIS_EN_WIDTH              1u
#define SAF_SDADC_FCDIS_FCDIS_EN(x)                 (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCDIS_FCDIS_EN_SHIFT))&SAF_SDADC_FCDIS_FCDIS_EN_MASK)
#define SAF_SDADC_FCDIS_FCDIS_NUM_MASK              0xFF00u
#define SAF_SDADC_FCDIS_FCDIS_NUM_SHIFT             8u
#define SAF_SDADC_FCDIS_FCDIS_NUM_WIDTH             8u
#define SAF_SDADC_FCDIS_FCDIS_NUM(x)                (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_FCDIS_FCDIS_NUM_SHIFT))&SAF_SDADC_FCDIS_FCDIS_NUM_MASK)
/* CH_WRAP Bit Fields */
#define SAF_SDADC_CH_WRAP_CH_DFLT_MASK              0xFu
#define SAF_SDADC_CH_WRAP_CH_DFLT_SHIFT             0u
#define SAF_SDADC_CH_WRAP_CH_DFLT_WIDTH             4u
#define SAF_SDADC_CH_WRAP_CH_DFLT(x)                (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_CH_WRAP_CH_DFLT_SHIFT))&SAF_SDADC_CH_WRAP_CH_DFLT_MASK)
#define SAF_SDADC_CH_WRAP_CH_NUM_MASK               0xF0000u
#define SAF_SDADC_CH_WRAP_CH_NUM_SHIFT              16u
#define SAF_SDADC_CH_WRAP_CH_NUM_WIDTH              4u
#define SAF_SDADC_CH_WRAP_CH_NUM(x)                 (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_CH_WRAP_CH_NUM_SHIFT))&SAF_SDADC_CH_WRAP_CH_NUM_MASK)
/* DOV_INFO Bit Fields */
#define SAF_SDADC_DOV_INFO_DATA_MASK                0xFFFFu
#define SAF_SDADC_DOV_INFO_DATA_SHIFT               0u
#define SAF_SDADC_DOV_INFO_DATA_WIDTH               16u
#define SAF_SDADC_DOV_INFO_DATA(x)                  (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_DOV_INFO_DATA_SHIFT))&SAF_SDADC_DOV_INFO_DATA_MASK)
#define SAF_SDADC_DOV_INFO_COMPTR_UVF_MASK          0x10000u
#define SAF_SDADC_DOV_INFO_COMPTR_UVF_SHIFT         16u
#define SAF_SDADC_DOV_INFO_COMPTR_UVF_WIDTH         1u
#define SAF_SDADC_DOV_INFO_COMPTR_UVF(x)            (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_DOV_INFO_COMPTR_UVF_SHIFT))&SAF_SDADC_DOV_INFO_COMPTR_UVF_MASK)
#define SAF_SDADC_DOV_INFO_COMPTR_OVF_MASK          0x20000u
#define SAF_SDADC_DOV_INFO_COMPTR_OVF_SHIFT         17u
#define SAF_SDADC_DOV_INFO_COMPTR_OVF_WIDTH         1u
#define SAF_SDADC_DOV_INFO_COMPTR_OVF(x)            (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_DOV_INFO_COMPTR_OVF_SHIFT))&SAF_SDADC_DOV_INFO_COMPTR_OVF_MASK)
#define SAF_SDADC_DOV_INFO_CH_INFO_MASK             0xF00000u
#define SAF_SDADC_DOV_INFO_CH_INFO_SHIFT            20u
#define SAF_SDADC_DOV_INFO_CH_INFO_WIDTH            4u
#define SAF_SDADC_DOV_INFO_CH_INFO(x)               (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_DOV_INFO_CH_INFO_SHIFT))&SAF_SDADC_DOV_INFO_CH_INFO_MASK)
/* BIAS Bit Fields */
#define SAF_SDADC_BIAS_BIAS_RES_TRIM_LV_MASK        0x7u
#define SAF_SDADC_BIAS_BIAS_RES_TRIM_LV_SHIFT       0u
#define SAF_SDADC_BIAS_BIAS_RES_TRIM_LV_WIDTH       3u
#define SAF_SDADC_BIAS_BIAS_RES_TRIM_LV(x)          (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_BIAS_BIAS_RES_TRIM_LV_SHIFT))&SAF_SDADC_BIAS_BIAS_RES_TRIM_LV_MASK)
#define SAF_SDADC_BIAS_TEST_BIAS_LV_MASK            0x8u
#define SAF_SDADC_BIAS_TEST_BIAS_LV_SHIFT           3u
#define SAF_SDADC_BIAS_TEST_BIAS_LV_WIDTH           1u
#define SAF_SDADC_BIAS_TEST_BIAS_LV(x)              (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_BIAS_TEST_BIAS_LV_SHIFT))&SAF_SDADC_BIAS_TEST_BIAS_LV_MASK)
/* RES Bit Fields */
#define SAF_SDADC_RES_RES_N_LV_MASK                 0xFFu
#define SAF_SDADC_RES_RES_N_LV_SHIFT                0u
#define SAF_SDADC_RES_RES_N_LV_WIDTH                8u
#define SAF_SDADC_RES_RES_N_LV(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_RES_RES_N_LV_SHIFT))&SAF_SDADC_RES_RES_N_LV_MASK)
#define SAF_SDADC_RES_RES_P_LV_MASK                 0xFF0000u
#define SAF_SDADC_RES_RES_P_LV_SHIFT                16u
#define SAF_SDADC_RES_RES_P_LV_WIDTH                8u
#define SAF_SDADC_RES_RES_P_LV(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_RES_RES_P_LV_SHIFT))&SAF_SDADC_RES_RES_P_LV_MASK)
/* ATT Bit Fields */
#define SAF_SDADC_ATT_GAIN_LV_MASK                  0x1Fu
#define SAF_SDADC_ATT_GAIN_LV_SHIFT                 0u
#define SAF_SDADC_ATT_GAIN_LV_WIDTH                 5u
#define SAF_SDADC_ATT_GAIN_LV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_ATT_GAIN_LV_SHIFT))&SAF_SDADC_ATT_GAIN_LV_MASK)
#define SAF_SDADC_ATT_VCOM_SEL_LV_MASK              0x100u
#define SAF_SDADC_ATT_VCOM_SEL_LV_SHIFT             8u
#define SAF_SDADC_ATT_VCOM_SEL_LV_WIDTH             1u
#define SAF_SDADC_ATT_VCOM_SEL_LV(x)                (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_ATT_VCOM_SEL_LV_SHIFT))&SAF_SDADC_ATT_VCOM_SEL_LV_MASK)
#define SAF_SDADC_ATT_ADC_DIV_LV_MASK               0x70000u
#define SAF_SDADC_ATT_ADC_DIV_LV_SHIFT              16u
#define SAF_SDADC_ATT_ADC_DIV_LV_WIDTH              3u
#define SAF_SDADC_ATT_ADC_DIV_LV(x)                 (((uint32_t)(((uint32_t)(x))<<SAF_SDADC_ATT_ADC_DIV_LV_SHIFT))&SAF_SDADC_ATT_ADC_DIV_LV_MASK)


typedef enum
{
    SAF_SDADC_INSTANCE_0                = 0U,
    SAF_SDADC_INSTANCE_1                = 1U,
    SAF_SDADC_INSTANCE_2                = 2U,
    SAF_SDADC_INSTANCE_3                = 3U,
    SAF_SDADC_INSTANCE_4                = 4U,
    /* SAF_SDADC_5 has no hardware resources */
    SAF_SDADC_INSTANCE_6                = 6U,
    SAF_SDADC_INSTANCE_7                = 7U,
    SAF_SDADC_INSTANCE_8                = 8U
    /* SAF_SDADC_9 has no hardware resources */
} Saf_Sdadc_InstanceType;

/**
 * @brief SDADC external mesh decoder clock selected.
 */
typedef enum
{
    SAF_SDADC_MESH_SEL_ADC_CORE         = 0U,
    SAF_SDADC_MESH_SEL_EXT_SIGNAL       = 1U
} Saf_Sdadc_MeshClkType;

/**
 * @brief SDADC FIR1 filter decimation rate enumeration
 */
typedef enum
{
    SAF_SDADC_FIR1_DECI_2_TO_1          = 0U,   /* Decimation 2:1 for FIR1 */
    SAF_SDADC_FIR1_DECI_NOT             = 1U    /* FIR1 filter does not decimate, 1:1 */
} Saf_Sdadc_Fir1DecimationRateType;

typedef enum
{
    SAF_SDADC_OFFSET_COMPENSATION_FILTER_DISABLED   = 0U,
    SAF_SDADC_OFFSET_COMPENSATION_FILTER_RATE_1     = 1U,
    SAF_SDADC_OFFSET_COMPENSATION_FILTER_RATE_2     = 2U,
    SAF_SDADC_OFFSET_COMPENSATION_FILTER_RATE_3     = 3U,
    SAF_SDADC_OFFSET_COMPENSATION_FILTER_RATE_4     = 4U,
    SAF_SDADC_OFFSET_COMPENSATION_FILTER_RATE_5     = 5U,
    SAF_SDADC_OFFSET_COMPENSATION_FILTER_RATE_6     = 6U,
    SAF_SDADC_OFFSET_COMPENSATION_FILTER_RATE_7     = 7U
} Saf_Sdadc_OffsetCompensationFilterEnType;

/**
 * @brief Selects the valid outputs bits from the CIC filter, depending on the chosen
 *          decimation factor (see data shifter formula).
 */
#define SAF_SDADC_CICSHIFT_USE_BITS_0_16            (0x00U)
#define SAF_SDADC_CICSHIFT_USE_BITS_1_17            (0x01U)
#define SAF_SDADC_CICSHIFT_USE_BITS_2_18            (0x02U)
#define SAF_SDADC_CICSHIFT_USE_BITS_3_19            (0x03U)
#define SAF_SDADC_CICSHIFT_USE_BITS_4_20            (0x04U)
#define SAF_SDADC_CICSHIFT_USE_BITS_5_21            (0x05U)
#define SAF_SDADC_CICSHIFT_USE_BITS_6_22            (0x06U)
#define SAF_SDADC_CICSHIFT_USE_BITS_7_23            (0x07U)
#define SAF_SDADC_CICSHIFT_USE_BITS_8_24            (0x08U)
#define SAF_SDADC_CICSHIFT_USE_BITS_9_25            (0x09U)
#define SAF_SDADC_CICSHIFT_USE_BITS_10_26           (0x0AU)
#define SAF_SDADC_CICSHIFT_USE_BITS_11_27           (0x0BU)
#define SAF_SDADC_CICSHIFT_USE_BITS_12_28           (0x0CU)
#define SAF_SDADC_CICSHIFT_USE_BITS_13_29           (0x0DU)
#define SAF_SDADC_CICSHIFT_USE_BITS_14_30           (0x0EU)
#define SAF_SDADC_CICSHIFT_USE_BITS_15_31           (0x0FU)
#define SAF_SDADC_CICSHIFT_USE_BITS_16_32           (0x10U)
#define SAF_SDADC_CICSHIFT_USE_BITS_17_33           (0x11U)
#define SAF_SDADC_CICSHIFT_USE_BITS_18_34           (0x12U)
#define SAF_SDADC_CICSHIFT_USE_BITS_19_35           (0x13U)
#define SAF_SDADC_CICSHIFT_USE_BITS_20_36           (0x14U)
#define SAF_SDADC_CICSHIFT_USE_BITS_21_37           (0x15U)
#define SAF_SDADC_CICSHIFT_USE_BITS_22_38           (0x16U)
#define SAF_SDADC_CICSHIFT_USE_BITS_23_39           (0x17U)
#define SAF_SDADC_CICSHIFT_USE_BITS_24_40           (0x18U)
#define SAF_SDADC_CICSHIFT_USE_BITS_25_41           (0x19U)
#define SAF_SDADC_CICSHIFT_USE_BITS_26_42           (0x1AU)
#define SAF_SDADC_CICSHIFT_USE_BITS_27_43           (0x1BU)
#define SAF_SDADC_CICSHIFT_USE_BITS_28_44           (0x1CU)

/**
 * @brief The initial value of 4096(0x1000) corresponds to a factor of 1.000.
 *          (Multiplication Factor for Gain Correction)
 *          (Multiplication Factor for Gain Calibration)
 */
#define SAF_SDADC_GAIN_INITIAL_VAL                  (0x1000U)

/**
 * @brief CIC Filter Decimation Factor
 *          Defines the oversampling rate of the CIC filter: OSR = CFMDF + 1.
 *          Valid values are 0x003 to 0x1ff(OSR = 4 to 512).
 */
#define SAF_SDADC_CIC_FILTER_OSR_MIN                (4U)
#define SAF_SDADC_CIC_FILTER_OSR_MAX                (512U)

typedef enum
{
    SAF_SDADC_SLEW_RATE_FILTER_STRENGTH_MIN         = 0U,   /* Minimum filter effect, early attenuation, linear operation */
    SAF_SDADC_SLEW_RATE_FILTER_STRENGTH_WEAK        = 1U,   /* Weak filter effect */
    SAF_SDADC_SLEW_RATE_FILTER_STRENGTH_MED         = 2U,   /* Medium filter effect */
    SAF_SDADC_SLEW_RATE_FILTER_STRENGTH_MAX         = 3U    /* Maximum filter effect, steep beginning, smooth end */
} Saf_Sdadc_SlewRateFilterStrengthType;

typedef enum
{
    SAF_SDADC_SLEW_RATE_FILTER_RUNTIME_2_IN_CYCLES  = 0U,
    SAF_SDADC_SLEW_RATE_FILTER_RUNTIME_4_IN_CYCLES  = 1U,
    SAF_SDADC_SLEW_RATE_FILTER_RUNTIME_8_IN_CYCLES  = 2U,
    SAF_SDADC_SLEW_RATE_FILTER_RUNTIME_16_IN_CYCLES = 3U
} Saf_Sdadc_SlewRateFilterRunTimeType;

typedef enum
{
    SAF_SDADC_STEP_DETECTION_MODE_LAST_INPUT        = 0U,
    SAF_SDADC_STEP_DETECTION_MODE_SECOND_LAST_INPUT = 1U
} Saf_Sdadc_StepDetectionModeType;

typedef enum
{
    SAF_SDADC_HW_TRIG_DISABLE                       = 0U,
    SAF_SDADC_HW_TRIG_POSEDGE                       = 1U,/* posedge: rising edge */
    SAF_SDADC_HW_TRIG_NEGEDGE                       = 2U,/* negedge: falling edge */
    SAF_SDADC_HW_TRIG_EDGE_BOTH                     = 3U
} Saf_Sdadc_HwTrigEdgeType;

typedef enum
{
    SAF_SDADC_INTEGRATOR_TRIG_MODE_BYPASSED         = 0U,
    SAF_SDADC_INTEGRATOR_TRIG_MODE_FALLING_EDGE     = 1U,
    SAF_SDADC_INTEGRATOR_TRIG_MODE_RISING_EDGE      = 2U,
    SAF_SDADC_INTEGRATOR_TRIG_MODE_ALWAYS_ACTIVE    = 3U
} Saf_Sdadc_IntegratorTrigModeType;

typedef enum
{
    SAF_SDADC_INTEGRATION_WINDOW_SIZE_INTERNAL_CTRL = 0U,   /* Internal control: stop integrator after REPVAL+1 integration cycles */
    SAF_SDADC_INTEGRATION_WINDOW_SIZE_EXTERNAL_CTRL = 1U    /* External control: stop integrator up the inverse trigger event */
} Saf_Sdadc_IntegrationWindowSizeType;

typedef enum
{
    SAF_SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_4_20   = 0U,
    SAF_SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_5_21   = 1U,
    SAF_SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_6_22   = 2U,
    SAF_SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_7_23   = 3U,
    SAF_SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_8_24   = 4U,
    SAF_SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_9_25   = 5U
} Saf_Sdadc_IntegratorShiftCtrlType;

typedef enum
{
    SAF_SDADC_FILTER_CHAIN_RESTART_ENABLE           = 0U,   /* Restart the filter chain when an integration window starts */
    SAF_SDADC_FILTER_CHAIN_RESTART_DISABLE          = 1U    /* No influence of filter chain when an integration window starts,
                                                         *  except for the integrator itself. */
} Saf_Sdadc_FilterChainRestartCtrlType;

typedef enum
{
    SAF_SDADC_PRE_GAIN_X1                           = 1U,
    SAF_SDADC_PRE_GAIN_X2                           = 2U,
    SAF_SDADC_PRE_GAIN_X4                           = 4U
} Saf_Sdadc_PreGainType;

typedef enum
{
    SAF_SDADC_INT_WATERMARKER                        = 0U,
    SAF_SDADC_INT_DATAOVERRUN                        = 1U,
    SAF_SDADC_INT_FIFOOVERRUN                        = 2U
} Saf_Sdadc_InterruptType;

/**
 * @brief SDADC Single-ended negative selection
 * @note  usable: Single-ended AC coupled capacitance sampling
 *        unusable: Single-ended DC sampling
 */
typedef enum
{
    SAF_SDADC_VCOM_SEL_HALF_OF_VREF_H               = 0U,   /* Negative: VCOM (VREF_H / 2) */
    SAF_SDADC_VCOM_SEL_VREF_L                       = 1U    /* Negative: ground */
} Saf_Sdadc_VcomSelType;

typedef enum
{
    SAF_SDADC_CLK_DIV_1                             = 0U,
    SAF_SDADC_CLK_DIV_2                             = 1U,
    SAF_SDADC_CLK_DIV_3                             = 2U,
    SAF_SDADC_CLK_DIV_4                             = 3U,
    SAF_SDADC_CLK_DIV_5                             = 4U,
    SAF_SDADC_CLK_DIV_6                             = 5U,
    SAF_SDADC_CLK_DIV_7                             = 6U,
    SAF_SDADC_CLK_DIV_8                             = 7U,
} Saf_Sdadc_ClkDivType;

typedef enum
{
    SAF_SDADC_OSR_12 = 0U,
	SAF_SDADC_OSR_16,
	SAF_SDADC_OSR_24,
	SAF_SDADC_OSR_32,
	SAF_SDADC_OSR_48,
	SAF_SDADC_OSR_64,
	SAF_SDADC_OSR_96,
	SAF_SDADC_OSR_128,
	SAF_SDADC_OSR_160,
	SAF_SDADC_OSR_192,
	SAF_SDADC_OSR_224,
	SAF_SDADC_OSR_256,
} Saf_Sdadc_OSRType;

typedef struct
{
    uint8_t                             ChanDefaultId;
    boolean                             DifferenceEn;
} Saf_Sdadc_ChanSelType;

/**
 * @brief SDADC FIR filters configuration structure
 */
typedef struct
{
    Saf_Sdadc_Fir1DecimationRateType            Fir1DecimationRate;
    boolean                                 CicMode;
    boolean                                 OvershootCompEn;
    Saf_Sdadc_OffsetCompensationFilterEnType    OffsetCompFilterEn;
    boolean                                 CalibrationEn;
} Saf_Sdadc_FirFilterConfigType;

typedef struct
{
    uint16_t                            GainCorrFactor;         /* Multiplication Factor for Gain Correction */
    uint8_t                             GainCorrCicShift;       /* Position of the CIC Filter Output Shifter.
                                                                    Max: [SAF_SDADC_CICSHIFT_USE_BITS_28_44] */
    uint16_t                            GainCalFactor;          /* Multiplication Factor for Gain Calibration */
} Saf_Sdadc_GainConfigType;/*PRQA S 1535*/

#define SAF_SDADC_OVERSHOOT_STEP_DETECTION_THRESHOLD_MAX    (0x7FFu)

typedef struct
{
    Saf_Sdadc_SlewRateFilterStrengthType    SlewRateFilterStrength;
    Saf_Sdadc_SlewRateFilterRunTimeType     SlewRateFilterRunTime;
    Saf_Sdadc_StepDetectionModeType         StepDetectionMode;
    uint16_t                            StepDetectionThreshold;
} Saf_Sdadc_OvershootCompConfigType;

typedef struct
{
    boolean                             FifoWaterMarkerIntEn;
    boolean                             FifoOverFlowIntEn;
    boolean                             DataOverFlowIntEn;
    boolean                             DmaReqEn;
} Saf_Sdadc_IntDmaConfigType;

/**
 * @brief SDADC Integrator configuration structure
 */
typedef struct
{
    Saf_Sdadc_IntegratorTrigModeType        IntegratorTrigMode;     /* Integrator Trigger Mode (DICFG.ITRMODE) */
    Saf_Sdadc_IntegrationWindowSizeType     IntegrationWindowSize;  /* Integration Window Size (IWCTR.IWS) */
    uint16_t                            NumOfDiscardedVal;      /* Start the integration cycle after [NVALDIS] values (IWCTR.NVALDIS) */
    uint16_t                            NumOfAccumulatedVal;    /* Stop the integration cycle after [NVALINT] + 1 values (IWCTR.NVALINT) */
    uint16_t                            NumOfIntegrationCycles; /* Defines the number of integration cycles to
                                                                    be counted by REPCNT if activated(IWS=0).
                                                                    The number of cycles is [REPVAL] + 1. (IWCTR.REPVAL) */
    Saf_Sdadc_IntegratorShiftCtrlType       IntegratorShiftCtrl;    /* Integrator Shift Control
                                                                    Controls the data shifter after the integrator that selects the portion of the integrator data for the result register.
                                                                    Note: [ISC] selects the respective bits in register IIVAL.The lowest selected bit is used for rounding and is then removed.
                                                                    (IWCTR.ISC) */
    Saf_Sdadc_FilterChainRestartCtrlType    FilterChainRestartCtrl; /* Filter Chain Restart Control (IWCTR.FRC) */
} Saf_Sdadc_IntegratorConfigType;

typedef struct
{
    boolean                             FilterChainDiscardEn;
    uint8_t                             FilterChainDiscardNum;
} Saf_Sdadc_FilterChainDiscardConfigType;

typedef struct
{
    boolean                             ChanWraparoundEn;
    uint8_t                             ChanWraparoundNum;
} Saf_Sdadc_ChanWrapConfigType;

typedef struct
{
    boolean                             BoundaryComparatorEn;
    uint16_t                            LowerBoundary;
    uint16_t                            UpperBoundary;
} Saf_Sdadc_ComparatorConfigType;

#define SAF_SDADC_FIFO_SIZE_MAX             (0x40U)

typedef struct
{
    uint8_t                             FifoSize;   /* Max(default) is 0x40 */
    uint8_t                             FifoWaterMarker;
    boolean                             InfoEn;
    boolean                             SignEn;
} Saf_Sdadc_FifoDataConfigType;

/**
 * @brief SDADC Analog Configuration
 *
 * @param PreGain: Analog gain factor
 *        VcomSel: Single-ended negative selection
 *        ClkDiv: Clock frequency division
 *        ResistorChan_P: Resistance Select open channel (positive +)
 *        ResistorChan_N: Resistance Select open channel (negative -)
 *
 * @note  ResistorChan_P & ResistorChan_N:
 *          usable: Single-ended AC coupled capacitance sampling
 *          unusable: Single-ended DC sampling
 */
typedef struct
{
    Saf_Sdadc_PreGainType                   PreGain;
    Saf_Sdadc_VcomSelType                   VcomSel;
    Saf_Sdadc_ClkDivType                    ClkDiv;
} Saf_Sdadc_AnalogCfgType;

typedef struct
{
	uint32_t                            DmaCh;
    uint32_t *                          DmaRxBuf;
    uint32_t                            DmaRxSize;
    boolean                             DreqEn;
} Saf_Sdadc_DmaCfgType;

typedef struct
{
    Saf_Sdadc_ChanSelType                   ChanSel;
    Saf_Sdadc_MeshClkType                   ExtMeshClkSel;  /* External mesh decoder clock selected */
    boolean                             DCTestEn;
    Saf_Sdadc_AnalogCfgType                 AnalogCfg;
    Saf_Sdadc_OSRType                       OsrVal;
    Saf_Sdadc_FirFilterConfigType           FirFilter;
    Saf_Sdadc_OvershootCompConfigType       OvershootComp;
    Saf_Sdadc_IntDmaConfigType              IntDma;
    Saf_Sdadc_DmaCfgType                    DmaCfg;
    boolean                             IntegratorEn;
    Saf_Sdadc_IntegratorConfigType          Integrator;
    Saf_Sdadc_FilterChainDiscardConfigType  FilterChainDiscard;
    Saf_Sdadc_ChanWrapConfigType            ChanWrap;
    Saf_Sdadc_ComparatorConfigType          Comparator;
    Saf_Sdadc_FifoDataConfigType            FifoCfg;
    Saf_Sdadc_HwTrigEdgeType                HwTrigSel[16u];
} Saf_Sdadc_ConfigType;

#define SDADC0_CH0                      (0U)
#define SDADC0_CH1                      (1U)
#define SDADC1_CH0                      (0U)
#define SDADC1_CH1                      (1U)
#define SDADC2_CH0                      (0U)
#define SDADC2_CH1                      (1U)
#define SDADC2_CH2                      (2U)
#define SDADC2_CH3                      (3U)
#define SDADC3_CH0                      (0U)
#define SDADC3_CH1                      (1U)
#define SDADC3_CH2                      (2U)
#define SDADC3_CH3                      (3U)
#define SDADC3_CH4                      (4U)
#define SDADC3_CH5                      (5U)
#define SDADC3_CH6                      (6U)
#define SDADC3_CH7                      (7U)
#define SDADC4_CH0                      (0U)
#define SDADC4_CH1                      (1U)
#define SDADC4_CH2                      (2U)
#define SDADC4_CH3                      (3U)
#define SDADC6_CH0                      (0U)
#define SDADC6_CH1                      (1U)
#define SDADC6_CH2                      (2U)
#define SDADC6_CH3                      (3U)
#define SDADC7_CH0                      (0U)
#define SDADC7_CH1                      (1U)
#define SDADC7_CH2                      (2U)
#define SDADC7_CH3                      (3U)
#define SDADC8_CH0                      (0U)
#define SDADC8_CH1                      (1U)
#define SDADC8_CH2                      (2U)
#define SDADC8_CH3                      (3U)

#define SAF_SDADC_VREFL_MVOLT               (0U)
#define SAF_SDADC_VREFH_MVOLT               (5000U)





/*******************************************************************************
 * Function declaration.
 *******************************************************************************/
void SAF_SDADC_LLD_Init(const Saf_Sdadc_InstanceType instance, const Saf_Sdadc_ConfigType * const ConfigPtr);

void SAF_SDADC_LLD_DeInit(const Saf_Sdadc_InstanceType instance);

void SAF_SDADC_LLD_ModuleEnable(const Saf_Sdadc_InstanceType instance);

void SAF_SDADC_LLD_ModuleDisable(const Saf_Sdadc_InstanceType instance);

uint32_t SAF_SDADC_LLD_CalculateGain(const Saf_Sdadc_InstanceType instance);

uint32_t SAF_SDADC_LLD_CalculateOffset(const Saf_Sdadc_InstanceType instance, uint32_t gainVal);

uint32_t SAF_SDADC_LLD_GetFifoData(const Saf_Sdadc_InstanceType instance);

void SAF_SDADC_LLD_SetSoftTrigger(const Saf_Sdadc_InstanceType instance);

boolean SAF_SDADC_LLD_GetWaterMarkerIntState(const Saf_Sdadc_InstanceType instance);

void SAF_SDADC_LLD_ClearWaterMarkerIntState(const Saf_Sdadc_InstanceType instance);

boolean SAF_SDADC_LLD_GetDataOverFlowIntState(const Saf_Sdadc_InstanceType instance);

void SAF_SDADC_LLD_ClearDataOverFlowIntState(const Saf_Sdadc_InstanceType instance);

boolean SAF_SDADC_LLD_GetFifoOverFlowIntState(const Saf_Sdadc_InstanceType instance);

void SAF_SDADC_LLD_ClearFifoOverFlowIntState(const Saf_Sdadc_InstanceType instance);

void SAF_SDADC_LLD_ConfigDma(const Saf_Sdadc_InstanceType instance, uint8_t waterMarkerValue, Saf_Sdadc_DmaCfgType config);

status_t SAF_SDADC_LLD_PinInit(const Saf_Sdadc_InstanceType instance, uint8_t ch_default, boolean chWrapEn, uint8_t ch_num, boolean diffEn);

uint32_t SAF_SDADC_LLD_GetRecentAccumulation(const Saf_Sdadc_InstanceType instance);

boolean SAF_SDADC_LLD_GetIntegrationEnable(const Saf_Sdadc_InstanceType instance);

void SAF_SDADC_LLD_SetInterruptState(const Saf_Sdadc_InstanceType instance, Saf_Sdadc_InterruptType intType, boolean intState);

void SAF_SDADC_LLD_ResetFifo(const Saf_Sdadc_InstanceType instance);

#endif /* SAF_SDADC_LLD_H_ */

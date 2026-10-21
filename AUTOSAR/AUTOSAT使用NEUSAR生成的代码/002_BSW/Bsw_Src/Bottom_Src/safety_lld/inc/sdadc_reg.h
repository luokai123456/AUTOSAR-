/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     sdadc_reg.h
* @version  1.0
* @date     2023 - 09 - 01
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/
/* PRQA S 3673,4397 EOF*/

#ifndef SAF_SDADC_REG_H_
#define SAF_SDADC_REG_H_
#include "derivative.h"
#include "Saf_MemMap.h"
#ifdef SAF_ADC_SDADC_SUPPORTED
/**
 * @brief SDADC CIC Filter Mode
 */
#define SAF_SDADC_CIC_MODE_CIC3     (0U)

/**
 * @brief SDADC hardware trigger count
 */
#define SAF_SDADC_HW_TRIG_CNT       (16U)
typedef struct SDADC_tag SAF_SDADC_TagType;

/*******************************************************************************
 * @brief SDADC Control Register (SAF_SDADC_CTRL: SAF_SDADC_EN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_CTRL_SetSdadcEnDis(SAF_SDADC_TagType * const BasePtr,
                                            const boolean EnDis)
{
    BasePtr->CTRL.R = ((EnDis == FALSE) ? 0UL : SAF_SDADC_CTRL_EN_MASK); /* polyspace RTE:IDP */
}

SAF_ADC_SEC_CODE
static inline uint8_t SAF_SDADC_CTRL_GetSdadcEnDis(const SAF_SDADC_TagType * const BasePtr)
{
    return (uint8_t)(BasePtr->CTRL.R & SAF_SDADC_CTRL_EN_MASK);
}

/*******************************************************************************
 * @brief SDADC Gain Correction Register (SAF_SDADC_GAINCORR: GAINFACTOR)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_GAINCORR_SetMultiFactor(SAF_SDADC_TagType * const BasePtr,
                                                 const uint16_t CorrMultiFactor)
{
    BasePtr->GAINCORR.R &= ~SAF_SDADC_GAINCORR_GAINFACTOR_MASK;
    BasePtr->GAINCORR.R |= SAF_SDADC_GAINCORR_GAINFACTOR(CorrMultiFactor);
}

/*******************************************************************************
 * @brief SDADC Gain Correction Register (SAF_SDADC_GAINCORR: CICSHIFT)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_GAINCORR_SetCICShift(SAF_SDADC_TagType * const BasePtr,
                                              const uint8_t CICShift)
{
    BasePtr->GAINCORR.R &= ~SAF_SDADC_GAINCORR_CICSHIFT_MASK;
    BasePtr->GAINCORR.R |= SAF_SDADC_GAINCORR_CICSHIFT(CICShift);
}

SAF_ADC_SEC_CODE
static inline void SAF_SDADC_GAINCORR_SetCorrection(SAF_SDADC_TagType * const BasePtr,
                                                const uint16_t CorrMultiFactor,
                                                const uint8_t CICShift)
{
    BasePtr->GAINCORR.R = SAF_SDADC_GAINCORR_GAINFACTOR(CorrMultiFactor) | SAF_SDADC_GAINCORR_CICSHIFT(CICShift);
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_GAINCORR_GetCorrection(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->GAINCORR.R & (SAF_SDADC_GAINCORR_GAINFACTOR_MASK | SAF_SDADC_GAINCORR_CICSHIFT_MASK));
}

/*******************************************************************************
 * @brief SDADC Gain Calibration Register (SAF_SDADC_GAINCAL: CALFACTOR)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_GAINCAL_SetMultiFactor(SAF_SDADC_TagType * const BasePtr,
                                                const uint16_t CalMultiFactor)
{
    BasePtr->GAINCAL.R = SAF_SDADC_GAINCAL_CALFACTOR(CalMultiFactor);
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_GAINCAL_GetCalibration(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->GAINCAL.R & SAF_SDADC_GAINCAL_CALFACTOR_MASK);
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, CIC Filter (SAF_SDADC_FCFGC: CFMDF)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFGC_SetCICFilterDecFactor(SAF_SDADC_TagType * const BasePtr,
                                                     const uint16_t CICFilterDecFactor)
{
    BasePtr->FCFGC.R &= ~SAF_SDADC_FCFGC_CFMDF_MASK;/* polyspace RTE:NIV */
    BasePtr->FCFGC.R |= SAF_SDADC_FCFGC_CFMDF(CICFilterDecFactor);
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, CIC Filter (SAF_SDADC_FCFGC: CFMSV)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFGC_SetCICFilterStartVal(SAF_SDADC_TagType * const BasePtr,
                                                    const uint16_t CICFilterStartVal)
{
    BasePtr->FCFGC.R &= ~SAF_SDADC_FCFGC_CFMSV_MASK;/* polyspace RTE:NIV */
    BasePtr->FCFGC.R |= SAF_SDADC_FCFGC_CFMSV(CICFilterStartVal);
}

SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFGC_SetFilterCfgCIC(SAF_SDADC_TagType * const BasePtr,
                                               const uint16_t CICFilterStartVal,
                                               const uint16_t CICFilterDecFactor)
{
    BasePtr->FCFGC.R = SAF_SDADC_FCFGC_CFMSV(CICFilterStartVal) | SAF_SDADC_FCFGC_CFMDF(CICFilterDecFactor);
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_FCFGC_GetFilterCfgCIC(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->FCFGC.R);
}

/*******************************************************************************
 * @brief SDADC Filter Counter Register, CIC Filter (SAF_SDADC_FCNTC: CFMDCNT)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCNTC_SetCICFilterDecCounter(SAF_SDADC_TagType * const BasePtr,
                                                      const uint16_t CICFilterDecCounter)
{
    BasePtr->FCNTC.R &= ~SAF_SDADC_FCNTC_CFMDCNT_MASK;/* polyspace RTE:NIV */
    BasePtr->FCNTC.R |= SAF_SDADC_FCNTC_CFMDCNT(CICFilterDecCounter);
}
SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_FCNTC_GetCICFilterDecCounter(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->FCNTC.R & SAF_SDADC_FCNTC_CFMDCNT_MASK);
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SAF_SDADC_FCFGM: FIR0EN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFGM_SetFIR0FilterEnDis(SAF_SDADC_TagType * const BasePtr,
                                                  const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SAF_SDADC_FCFGM_FIR0EN_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SAF_SDADC_FCFGM_FIR0EN_MASK;/* polyspace RTE:NIV */
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SAF_SDADC_FCFGM: FIR1EN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFGM_SetFIR1FilterEnDis(SAF_SDADC_TagType * const BasePtr,
                                                  const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SAF_SDADC_FCFGM_FIR1EN_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SAF_SDADC_FCFGM_FIR1EN_MASK;/* polyspace RTE:NIV */
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SAF_SDADC_FCFGM: OVCEN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFGM_SetOvershootCompenEnDis(SAF_SDADC_TagType * const BasePtr,
                                                       const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SAF_SDADC_FCFGM_OVCEN_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SAF_SDADC_FCFGM_OVCEN_MASK;/* polyspace RTE:NIV */
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SAF_SDADC_FCFGM: FIR1DEC)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFGM_SetFIR1FilterDecRate(SAF_SDADC_TagType * const BasePtr,
                                                    const uint8_t FIR1FilterDecRate)
{
    if (FIR1FilterDecRate == FALSE)
    {
        BasePtr->FCFGM.R &= ~SAF_SDADC_FCFGM_FIR1DEC_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SAF_SDADC_FCFGM_FIR1DEC_MASK;/* polyspace RTE:NIV */
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SAF_SDADC_FCFGM: CICMOD)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFGM_SetCICFilterMode(SAF_SDADC_TagType * const BasePtr,
                                                const uint8_t CICFilterMode)
{
    if (CICFilterMode == SAF_SDADC_CIC_MODE_CIC3)
    {
        BasePtr->FCFGM.R &= ~SAF_SDADC_FCFGM_CICMOD_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SAF_SDADC_FCFGM_CICMOD_MASK;/* polyspace RTE:NIV */
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SAF_SDADC_FCFGM: PFEN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFGM_SetPrefilterEnDis(SAF_SDADC_TagType * const BasePtr,
                                                 const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SAF_SDADC_FCFGM_PFEN_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SAF_SDADC_FCFGM_PFEN_MASK;/* polyspace RTE:NIV */
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SAF_SDADC_FCFGM: COMPTR_EN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFGM_SetBoundaryComparatorEnDis(SAF_SDADC_TagType * const BasePtr,
                                                          const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SAF_SDADC_FCFGM_COMPTR_EN_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SAF_SDADC_FCFGM_COMPTR_EN_MASK;/* polyspace RTE:NIV */
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SAF_SDADC_FCFGM: EXT_MESH_EN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFGM_SetExtMeshClkEnDis(SAF_SDADC_TagType * const BasePtr,
                                                  const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SAF_SDADC_FCFGM_EXT_MESH_EN_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SAF_SDADC_FCFGM_EXT_MESH_EN_MASK;/* polyspace RTE:NIV */
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SAF_SDADC_FCFGM: OCEN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFGM_SetOffsetCompenFilterEn(SAF_SDADC_TagType * const BasePtr,
                                                       const uint8_t OffsetCompenFilterEn)
{
    BasePtr->FCFGM.R &= ~SAF_SDADC_FCFGM_OCEN_MASK;/* polyspace RTE:NIV */
    BasePtr->FCFGM.R |= SAF_SDADC_FCFGM_OCEN(OffsetCompenFilterEn);
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SAF_SDADC_FCFGM: CH_WRAP_EN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFGM_SetChannelWraparoundEnDis(SAF_SDADC_TagType * const BasePtr,
                                                         const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SAF_SDADC_FCFGM_CH_WRAP_EN_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SAF_SDADC_FCFGM_CH_WRAP_EN_MASK;/* polyspace RTE:NIV */
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SAF_SDADC_FCFGM: DIFF_EN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFGM_SetDifferenceEnDis(SAF_SDADC_TagType * const BasePtr,
                                                  const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SAF_SDADC_FCFGM_DIFF_EN_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SAF_SDADC_FCFGM_DIFF_EN_MASK;/* polyspace RTE:NIV */
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SAF_SDADC_FCFGM: CALIB_EN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFGM_SetCalibEnDis(SAF_SDADC_TagType * const BasePtr,
                                             const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SAF_SDADC_FCFGM_CALIB_EN_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SAF_SDADC_FCFGM_CALIB_EN_MASK;/* polyspace RTE:NIV */
    }
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_FCFGM_GetFilterCfgMain(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->FCFGM.R);
}

/*******************************************************************************
 * @brief SDADC Offset Compensation Register (SAF_SDADC_OFFCOMP: OFFSET)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_OFFCOMP_SetOffsetVal(SAF_SDADC_TagType * const BasePtr,
                                              const uint16_t OffsetVal)
{
    BasePtr->OFFCOMP.R = SAF_SDADC_OFFCOMP_OFFSET(OffsetVal);
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_OFFCOMP_GetOffsetVal(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->OFFCOMP.R);/* polyspace RTE:NIV */
}

/*******************************************************************************
 * @brief SDADC Interrupt Enable Configuration Register (SAF_SDADC_IECFG: FWM_INT_EN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_IECFG_SetFifoWaterMarkerIntEnDis(SAF_SDADC_TagType * const BasePtr,
                                                          const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->IECFG.R &= ~SAF_SDADC_IECFG_FWM_INT_EN_MASK;/* polyspace RTE:NIV,IDP */
    }
    else
    {
        BasePtr->IECFG.R |= SAF_SDADC_IECFG_FWM_INT_EN_MASK;/* polyspace RTE:NIV,IDP */
    }
}

/*******************************************************************************
 * @brief SDADC Interrupt Enable Configuration Register (SAF_SDADC_IECFG: FOV_INT_EN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_IECFG_SetFifoOverFlowIntEnDis(SAF_SDADC_TagType * const BasePtr,
                                                       const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->IECFG.R &= ~SAF_SDADC_IECFG_FOV_INT_EN_MASK;/* polyspace RTE:NIV,IDP */
    }
    else
    {
        BasePtr->IECFG.R |= SAF_SDADC_IECFG_FOV_INT_EN_MASK;/* polyspace RTE:NIV,IDP */
    }
}

/*******************************************************************************
 * @brief SDADC Interrupt Enable Configuration Register (SAF_SDADC_IECFG: DOV_INT_EN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_IECFG_SetDataOverFlowIntEnDis(SAF_SDADC_TagType * const BasePtr,
                                                       const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->IECFG.R &= ~SAF_SDADC_IECFG_DOV_INT_EN_MASK;/* polyspace RTE:NIV,IDP */
    }
    else
    {
        BasePtr->IECFG.R |= SAF_SDADC_IECFG_DOV_INT_EN_MASK;/* polyspace RTE:NIV,IDP */
    }
}

/*******************************************************************************
 * @brief SDADC Interrupt Enable Configuration Register (SAF_SDADC_IECFG: DMA_REQ_EN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_IECFG_SetDMAReqEnDis(SAF_SDADC_TagType * const BasePtr,
                                              const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->IECFG.R &= ~SAF_SDADC_IECFG_DMA_REQ_EN_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->IECFG.R |= SAF_SDADC_IECFG_DMA_REQ_EN_MASK;/* polyspace RTE:NIV */
    }
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_IECFG_GetIntDMACfg(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->IECFG.R);
}

/*******************************************************************************
 * @brief SDADC FIFO Configuration Register (SAF_SDADC_FCFG: FIFOSIZE)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFG_SetFifoSize(SAF_SDADC_TagType * const BasePtr,
                                          const uint8_t FifoSize)
{
    BasePtr->FCFG.R &= ~SAF_SDADC_FCFG_FIFOSIZE_MASK;/* polyspace RTE:NIV */
    BasePtr->FCFG.R |= SAF_SDADC_FCFG_FIFOSIZE(FifoSize);
}

/*******************************************************************************
 * @brief SDADC FIFO Configuration Register (SAF_SDADC_FCFG: FIFOWM)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFG_SetFifoWaterMarkerVal(SAF_SDADC_TagType * const BasePtr,
                                                    const uint8_t FifoWaterMarkerVal)
{
    BasePtr->FCFG.R &= ~SAF_SDADC_FCFG_FIFOWM_MASK;   /* polyspace RTE:NIV */
    BasePtr->FCFG.R |= SAF_SDADC_FCFG_FIFOWM(FifoWaterMarkerVal);
}

/*******************************************************************************
 * @brief SDADC FIFO Configuration Register (SAF_SDADC_FCFG: INFOEN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFG_SetInfoEnDis(SAF_SDADC_TagType * const BasePtr,
                                           const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFG.R &= ~SAF_SDADC_FCFG_INFOEN_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFG.R |= SAF_SDADC_FCFG_INFOEN_MASK;/* polyspace RTE:NIV */
    }
}

/*******************************************************************************
 * @brief SDADC FIFO Configuration Register (SAF_SDADC_FCFG: SIGNEN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCFG_SetSignEnDis(SAF_SDADC_TagType * const BasePtr,
                                           const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFG.R &= ~SAF_SDADC_FCFG_SIGNEN_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFG.R |= SAF_SDADC_FCFG_SIGNEN_MASK;/* polyspace RTE:NIV */
    }
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_FCFG_GetFifoCfg(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->FCFG.R);
}

/*******************************************************************************
 * @brief SDADC FIFO Data Register (SAF_SDADC_FDATA: DATA)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_FDATA_GetFifoData(const SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->FDATA.R);/* polyspace RTE:NIV,IDP */
}

/*******************************************************************************
 * @brief SDADC Integrator Status Register (SAF_SDADC_ISTAT: NVALCNT)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint8_t SAF_SDADC_ISTAT_GetNumOfValCount(const SAF_SDADC_TagType * const BasePtr)
{
    return (uint8_t)(BasePtr->ISTAT.R & SAF_SDADC_ISTAT_NVALCNT_MASK);
}

/*******************************************************************************
 * @brief SDADC Integrator Status Register (SAF_SDADC_ISTAT: REPCNT)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint8_t SAF_SDADC_ISTAT_GetIntegrationCycleCount(const SAF_SDADC_TagType * const BasePtr)
{
    return (uint8_t)((BasePtr->ISTAT.R & SAF_SDADC_ISTAT_REPCNT_MASK) >> SAF_SDADC_ISTAT_REPCNT_SHIFT);
}

/*******************************************************************************
 * @brief SDADC Integrator Status Register (SAF_SDADC_ISTAT: INTEN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint8_t SAF_SDADC_ISTAT_GetIntegrationEn(const SAF_SDADC_TagType * const BasePtr)
{
    return (uint8_t)((BasePtr->ISTAT.R & SAF_SDADC_ISTAT_INTEN_MASK) >> SAF_SDADC_ISTAT_INTEN_SHIFT);/* polyspace RTE:NIV,IDP */
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_ISTAT_GetIntegrStatus(const SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->ISTAT.R);
}

/*******************************************************************************
 * @brief SDADC Intermediate Integration Value Register (SAF_SDADC_IIVAL: IVAL)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_IIVAL_GetInterIntegrationVal(const SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->IIVAL.R);/* polyspace RTE:NIV,IDP */
}

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SAF_SDADC_IWCTR: ISC)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_IWCTR_SetIntegratorShiftCtrl(SAF_SDADC_TagType * const BasePtr,
                                                      const uint8_t IntegratorShiftCtrl)
{
    BasePtr->IWCTR.R &= ~SAF_SDADC_IWCTR_ISC_MASK;/* polyspace RTE:NIV */
    BasePtr->IWCTR.R |= SAF_SDADC_IWCTR_ISC(IntegratorShiftCtrl);
}

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SAF_SDADC_IWCTR: IWS)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_IWCTR_SetIntegrationWindowSize(SAF_SDADC_TagType * const BasePtr,
                                                        const uint8_t IntegrationWindowSize)
{
    if (IntegrationWindowSize == FALSE)
    {
        BasePtr->IWCTR.R &= ~SAF_SDADC_IWCTR_IWS_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->IWCTR.R |= SAF_SDADC_IWCTR_IWS_MASK;/* polyspace RTE:NIV */
    }
}

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SAF_SDADC_IWCTR: FRC)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_IWCTR_SetFilterRestartCtrl(SAF_SDADC_TagType * const BasePtr,
                                                    const uint8_t FilterRestartCtrl)
{
    if (FilterRestartCtrl == FALSE)
    {
        BasePtr->IWCTR.R &= ~SAF_SDADC_IWCTR_FRC_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->IWCTR.R |= SAF_SDADC_IWCTR_FRC_MASK;/* polyspace RTE:NIV */
    }
}

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SAF_SDADC_IWCTR: REPVAL)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_IWCTR_SetIntegrationCycle(SAF_SDADC_TagType * const BasePtr,
                                                   const uint8_t IntegrationCycle)
{
    BasePtr->IWCTR.R &= ~SAF_SDADC_IWCTR_REPVAL_MASK;/* polyspace RTE:NIV */
    BasePtr->IWCTR.R |= SAF_SDADC_IWCTR_REPVAL(IntegrationCycle);
}

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SAF_SDADC_IWCTR: NVALDIS)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_IWCTR_SetNumberOfValDiscarded(SAF_SDADC_TagType * const BasePtr,
                                                       const uint8_t NumberOfValDiscarded)
{
    BasePtr->IWCTR.R &= ~SAF_SDADC_IWCTR_NVALDIS_MASK;/* polyspace RTE:NIV */
    BasePtr->IWCTR.R |= SAF_SDADC_IWCTR_NVALDIS(NumberOfValDiscarded);
}

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SAF_SDADC_IWCTR: NVALINT)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_IWCTR_SetNumberOfValAccumulated(SAF_SDADC_TagType * const BasePtr,
                                                         const uint8_t NumberOfValAccumulated)
{
    BasePtr->IWCTR.R &= ~SAF_SDADC_IWCTR_NVALINT_MASK;/* polyspace RTE:NIV */
    BasePtr->IWCTR.R |= SAF_SDADC_IWCTR_NVALINT(NumberOfValAccumulated);
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_IWCTR_GetIntegrWindowCtrl(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->IWCTR.R);
}

/*******************************************************************************
 * @brief SDADC Demodulator Input Configuration Register (SAF_SDADC_DICFG: ITRMODE)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_DICFG_SetIntegratorTriggerMode(SAF_SDADC_TagType * const BasePtr,
                                                        const uint8_t IntegratorTriggerMode)
{
    BasePtr->DICFG.R = SAF_SDADC_DICFG_ITRMODE(IntegratorTriggerMode);
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_DICFG_GetDemodulatorInputCfg(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->DICFG.R);
}

/*******************************************************************************
 * @brief SDADC Boundary Select Register (SAF_SDADC_BOUNDSEL: BOUNDARYL / BOUNDARYU)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_BOUNDSEL_SetLowerUpperBoundaryLimit(SAF_SDADC_TagType * const BasePtr,
                                                             const uint8_t LowerBoundaryLimit,
                                                             const uint8_t UpperBoundaryLimit)
{
    BasePtr->BOUNDSEL.R = SAF_SDADC_BOUNDSEL_BOUNDARYL(LowerBoundaryLimit) | SAF_SDADC_BOUNDSEL_BOUNDARYU(UpperBoundaryLimit);
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_BOUNDSEL_GetBoundary(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->BOUNDSEL.R);
}

/*******************************************************************************
 * @brief SDADC WaterMarker Interrupt State Register (SAF_SDADC_WMINTSTAT: FWM_INT)
 *
 * @note  Read / Write 1 clear.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint8_t SAF_SDADC_WMINTSTAT_GetWaterMarkerIntState(const SAF_SDADC_TagType * const BasePtr)
{
    return (uint8_t)(BasePtr->WMINTSTAT.R & SAF_SDADC_WMINTSTAT_FWM_INT_MASK);/* polyspace RTE:NIV,IDP */
}

SAF_ADC_SEC_CODE
static inline void SAF_SDADC_WMINTSTAT_ClearWaterMarkerIntState(SAF_SDADC_TagType * const BasePtr)
{
    BasePtr->WMINTSTAT.R = SAF_SDADC_WMINTSTAT_FWM_INT_MASK;/* polyspace RTE:NIV,IDP */
}

/*******************************************************************************
 * @brief SDADC OverFlow Interrupt State Register
 *          (SAF_SDADC_OVINTSTAT: FOV_INT / DOV_INT)
 *
 * @note  Read / Write 1 clear.
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint8_t SAF_SDADC_OVINTSTAT_GetDataOverFlowIntState(const SAF_SDADC_TagType * const BasePtr)
{
    return (uint8_t)((BasePtr->OVINTSTAT.R & SAF_SDADC_OVINTSTAT_DOV_INT_MASK) >> 1U);/* polyspace RTE:NIV,IDP */
}

SAF_ADC_SEC_CODE
static inline void SAF_SDADC_OVINTSTAT_ClearDataOverFlowIntState(SAF_SDADC_TagType * const BasePtr)
{															/* PRQA S 4391 */						
    BasePtr->OVINTSTAT.R = SAF_SDADC_OVINTSTAT_DOV_INT_MASK;	/* PRQA S 4391 */ /* polyspace RTE:NIV,IDP */
}

SAF_ADC_SEC_CODE
static inline uint8_t SAF_SDADC_OVINTSTAT_GetFifoOverFlowIntState(const SAF_SDADC_TagType * const BasePtr)
{
    return (uint8_t)(BasePtr->OVINTSTAT.R & SAF_SDADC_OVINTSTAT_FOV_INT_MASK);/* polyspace RTE:NIV,IDP */
}

SAF_ADC_SEC_CODE
static inline void SAF_SDADC_OVINTSTAT_ClearFifoOverFlowIntState(SAF_SDADC_TagType * const BasePtr)
{															/* PRQA S 4391 */
    BasePtr->OVINTSTAT.R = SAF_SDADC_OVINTSTAT_FOV_INT_MASK;	/* PRQA S 4391 */ /* polyspace RTE:NIV,IDP */
}

/*******************************************************************************
 * @brief SDADC Overshoot Compensation Configuration Register
 *          (SAF_SDADC_OVSCFG: SRFS)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_OVSCFG_SetSlewRateFilterStrength(SAF_SDADC_TagType * const BasePtr,
                                                          const uint8_t SlewRateFilterStrength)
{
    BasePtr->OVSCFG.R &= ~SAF_SDADC_OVSCFG_SRFS_MASK;/* polyspace RTE:NIV */
    BasePtr->OVSCFG.R |= SAF_SDADC_OVSCFG_SRFS(SlewRateFilterStrength);
}

/*******************************************************************************
 * @brief SDADC Overshoot Compensation Configuration Register
 *          (SAF_SDADC_OVSCFG: SRFRT)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_OVSCFG_SetSlewRateFilterRunTime(SAF_SDADC_TagType * const BasePtr,
                                                         const uint8_t SlewRateFilterRunTime)
{
    BasePtr->OVSCFG.R &= ~SAF_SDADC_OVSCFG_SRFRT_MASK;/* polyspace RTE:NIV */
    BasePtr->OVSCFG.R |= SAF_SDADC_OVSCFG_SRFRT(SlewRateFilterRunTime);
}

/*******************************************************************************
 * @brief SDADC Overshoot Compensation Configuration Register
 *          (SAF_SDADC_OVSCFG: SDM)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_OVSCFG_SetStepDetectionMode(SAF_SDADC_TagType * const BasePtr,
                                                     const uint8_t StepDetectionMode)
{
    if (StepDetectionMode == FALSE)
    {
        BasePtr->OVSCFG.R &= ~SAF_SDADC_OVSCFG_SDM_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->OVSCFG.R |= SAF_SDADC_OVSCFG_SDM_MASK;/* polyspace RTE:NIV */
    }
}

/*******************************************************************************
 * @brief SDADC Overshoot Compensation Configuration Register
 *          (SAF_SDADC_OVSCFG: SDTH)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_OVSCFG_SetStepDetectionThreshold(SAF_SDADC_TagType * const BasePtr,
                                                          const uint16_t StepDetectionThreshold)
{
    BasePtr->OVSCFG.R &= ~SAF_SDADC_OVSCFG_SDTH_MASK;/* polyspace RTE:NIV */
    BasePtr->OVSCFG.R |= SAF_SDADC_OVSCFG_SDTH(StepDetectionThreshold);
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_OVSCFG_GetOvershootCompCfg(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->OVSCFG.R);
}

/*******************************************************************************
 * @brief SDADC Hardware Trigger Configuration Register
 *          (SAF_SDADC_HTCFG: HT0 ~ HT15)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_HTCFG_SetHwTriggerEdge(SAF_SDADC_TagType * const BasePtr,
                                                const uint8_t HwTrigIdx,
                                                const uint8_t HwTrigEdge)
{
    if (HwTrigIdx < SAF_SDADC_HW_TRIG_CNT)
    {														/* PRQA S 1891 */			
        BasePtr->HTCFG.R &= ~(SAF_SDADC_HTCFG_HT0_MASK  << (SAF_SDADC_HTCFG_HT0_WIDTH * HwTrigIdx));			/* PRQA S 1891 */ /* polyspace RTE:NIV */
        BasePtr->HTCFG.R |= ((HwTrigEdge & SAF_SDADC_HTCFG_HT0_MASK) << (SAF_SDADC_HTCFG_HT0_WIDTH * HwTrigIdx));	/* PRQA S 1891 */	
    }
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_HTCFG_GetHwTriggerEdge(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->HTCFG.R);
}

/*******************************************************************************
 * @brief SDADC Software Trigger Configuration Register (SAF_SDADC_STCFG: SH_EN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_STCFG_SetSoftTrigEn(SAF_SDADC_TagType * const BasePtr)
{
    BasePtr->STCFG.R = SAF_SDADC_STCFG_SH_EN_MASK; /* polyspace RTE:IDP */
}

/*******************************************************************************
 * @brief SDADC Software Trigger Configuration Register (SAF_SDADC_STCFG: SH_CLR)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_STCFG_ClearSoftTrig(SAF_SDADC_TagType * const BasePtr)
{
    BasePtr->STCFG.R = SAF_SDADC_STCFG_SH_CLR_MASK;
}

/*******************************************************************************
 * @brief SDADC Software Trigger Configuration Register (SAF_SDADC_STCFG: FSRSTN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_STCFG_SetFifoSoftReset(SAF_SDADC_TagType * const BasePtr)
{
    BasePtr->STCFG.R = SAF_SDADC_STCFG_FSRSTN_MASK; /* polyspace RTE:IDP */
}

/*******************************************************************************
 * @brief SDADC Filter Chain Discard Register (SAF_SDADC_FCDIS: FCDIS_EN)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCDIS_SetFilterChainDiscardEnDis(SAF_SDADC_TagType * const BasePtr,
                                                          const boolean EnDis)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCDIS.R &= ~SAF_SDADC_FCDIS_FCDIS_EN_MASK;/* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCDIS.R |= SAF_SDADC_FCDIS_FCDIS_EN_MASK;/* polyspace RTE:NIV */
    }
}

/*******************************************************************************
 * @brief SDADC Filter Chain Discard Register (SAF_SDADC_FCDIS: FCDIS_NUM)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_FCDIS_SetFilterChainDiscardNum(SAF_SDADC_TagType * const BasePtr,
                                                        const uint8_t FilterChainDiscardNum)
{
    BasePtr->FCDIS.R &= ~SAF_SDADC_FCDIS_FCDIS_NUM_MASK;/* polyspace RTE:NIV */
    BasePtr->FCDIS.R |= SAF_SDADC_FCDIS_FCDIS_NUM(FilterChainDiscardNum);
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_FCDIS_GetFilterChainCfg(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->FCDIS.R);
}

/*******************************************************************************
 * @brief SDADC Channel default & wrap Register (SAF_SDADC_CH_WRAP: CH_DFLT /CH_NUM)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_CH_WRAP_SetChannelDefault(SAF_SDADC_TagType * const BasePtr,
                                                   const uint8_t ChannelDefault,
                                                   const uint8_t ChannelWrap)
{
    BasePtr->CH_WRAP.R = SAF_SDADC_CH_WRAP_CH_DFLT(ChannelDefault) | SAF_SDADC_CH_WRAP_CH_NUM(ChannelWrap);
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_CH_WRAP_GetChannelCfg(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->CH_WRAP.R);
}

/*******************************************************************************
 * @brief SDADC Data OverFlow Information Register (SAF_SDADC_DOV_INFO: DATA)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint16_t SAF_SDADC_DOV_INFO_GetUnderflowOrOverflowData(const SAF_SDADC_TagType * const BasePtr)
{
    return (uint16_t)(BasePtr->DOV_INFO.R & SAF_SDADC_DOV_INFO_DATA_MASK);
}

/*******************************************************************************
 * @brief SDADC Data OverFlow Information Register (SAF_SDADC_DOV_INFO: COMPTR_UVF)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint8_t SAF_SDADC_DOV_INFO_GetDataCompareUnderFlow(const SAF_SDADC_TagType * const BasePtr)
{
    return (uint8_t)((BasePtr->DOV_INFO.R & SAF_SDADC_DOV_INFO_COMPTR_UVF_MASK) >> SAF_SDADC_DOV_INFO_COMPTR_UVF_SHIFT);
}

/*******************************************************************************
 * @brief SDADC Data OverFlow Information Register (SAF_SDADC_DOV_INFO: COMPTR_OVF)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint8_t SAF_SDADC_DOV_INFO_GetDataCompareOverFlow(const SAF_SDADC_TagType * const BasePtr)
{
    return (uint8_t)((BasePtr->DOV_INFO.R & SAF_SDADC_DOV_INFO_COMPTR_OVF_MASK) >> SAF_SDADC_DOV_INFO_COMPTR_OVF_SHIFT);
}

/*******************************************************************************
 * @brief SDADC Data OverFlow Information Register (SAF_SDADC_DOV_INFO: CH_INFO)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline uint8_t SAF_SDADC_DOV_INFO_GetChInfo(const SAF_SDADC_TagType * const BasePtr)
{
    return (uint8_t)((BasePtr->DOV_INFO.R & SAF_SDADC_DOV_INFO_CH_INFO_MASK) >> SAF_SDADC_DOV_INFO_CH_INFO_SHIFT);
}

/*******************************************************************************
 * @brief SDADC BIAS Register (SAF_SDADC_BIAS)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_BIAS_Set(SAF_SDADC_TagType * const BasePtr,
                                  const uint8_t bias_res_trim_lv,
                                  const uint8_t test_bias_lv)
{
    BasePtr->BIAS.R = SAF_SDADC_BIAS_BIAS_RES_TRIM_LV(bias_res_trim_lv) | SAF_SDADC_BIAS_TEST_BIAS_LV(test_bias_lv);
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_BIAS_Get(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->BIAS.R);
}

/*******************************************************************************
 * @brief SDADC Analog Channel Resistor Select Register (SAF_SDADC_RES)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_RES_SetResistorSelChan(SAF_SDADC_TagType * const BasePtr,
                                                const uint8_t res_p_lv,
                                                const uint8_t res_n_lv)
{
    BasePtr->RES.R = SAF_SDADC_RES_RES_N_LV(res_n_lv) | SAF_SDADC_RES_RES_P_LV(res_p_lv);
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_RES_GetResistorSelChan(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->RES.R);
}

/*******************************************************************************
 * @brief SDADC Analog Module Configuration Register (SAF_SDADC_ATT)
 *******************************************************************************/
SAF_ADC_SEC_CODE
static inline void SAF_SDADC_ATT_SetAnalogModuleCfg(SAF_SDADC_TagType * const BasePtr,
                                                const uint8_t gain_lv,
                                                const uint8_t vcom_sel_lv,
                                                const uint8_t adc_div_lv)
{
    BasePtr->ATT.R = (SAF_SDADC_ATT_GAIN_LV(gain_lv) | SAF_SDADC_ATT_VCOM_SEL_LV(vcom_sel_lv) | /* polyspace RTE:IDP */ \
                      SAF_SDADC_ATT_ADC_DIV_LV(adc_div_lv));
}

SAF_ADC_SEC_CODE
static inline uint32_t SAF_SDADC_ATT_GetAnalogModuleCfg(SAF_SDADC_TagType * const BasePtr)
{
    return (uint32_t)(BasePtr->ATT.R);/* polyspace RTE:NIV,IDP */
}
#endif /* SAF_ADC_SDADC_SUPPORTED */
#endif /* SAF_SDADC_REG_H_ */

/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3007PT
* DESCRIPTION : CCFC3007PT edma&mux low level drivers code
* HISTORY     : Initial version
* @file     edma_lld.c
* @version  1.0
* @date     2023 - 04 - 11
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/

#include "edma_lld.h"/* PRQA S 0380 */
#include "edma_configure.h"
#include "intc_lld.h"
#include "Saf_MemMap.h"
/* PRQA S 0491,0492,0751 EOF */
/* PRQA S 1258, 1503, 1505, 2844 EOF */
/* PRQA S 3469 EOF */
/* PRQA S 3119 EOF */
/* PRQA S 4342,4397,4399,4404,4434,4446 EOF */

SAF_DMA_SEC_CONFIG_DATA
static SAF_DMA_Type * const s_edmabaseAddr[SAF_EDMA_INSTANCE_COUNT] = SAF_DMA_BASE_PTRS;

#ifndef SAFETY_ENABLE
SAF_DMA_SEC_CONFIG_DATA
static const IntrId s_edmaErrIrqId[SAF_EDMA_ERROR_INTERRUPT_LINES] = SAF_DMA_ERROR_IRQS;
#endif

SAF_DMA_SEC_CONFIG_DATA
static const IntrId s_edmaIrqId[SAF_EDMA_MAPPED_CHANNELS_INTERRUPT_LINES] = SAF_DMA_CHN_IRQS; /* PRQA S 3218 */

SAF_DMA_SEC_CONFIG_DATA
static SAF_DMAMUX_Type * const s_dmaMuxbaseAddr[SAF_DMAMUX_INSTANCE_COUNT] = SAF_DMAMUX_BASE_PTRS;

SAF_DMA_SEC_VAR_NO_INIT
static safedma_state_t * s_mapEdmaState;

static void SAF_EDMA_HW_ClearStructPtr(uint8_t *sructPtr, volatile uint32_t size);
static void SAF_EDMA_HW_TCDDeInit(SafeDMAIstanceNumType instance, uint8_t channel);
static void SAF_EDMA_HW_Init(SafeDMAIstanceNumType instance);
static void SAF_EDMA_HW_CancelExecChnTransfer(SafeDMAIstanceNumType instance);
static void SAF_EDMA_HW_CancelExecChnTransferWithError(SafeDMAIstanceNumType instance);/* PRQA S 0779 */
static void SAF_EDMA_HW_EnDisHaltOnError(SafeDMAIstanceNumType instance, boolean haltOnError);
static void SAF_EDMA_HW_SetChnPri(SafeDMAIstanceNumType instance, uint8_t channel, SafeDMAChannelPriorityType priority);
static void SAF_EDMA_HW_SetChnArbitrationMode(SafeDMAIstanceNumType instance, SafeDMASelArbitrationModeType channelArbitration);
static SafeDMASelArbitrationModeType SAF_EDMA_HW_GetChnArbitrationMode(SafeDMAIstanceNumType instance);
static void SAF_EDMA_HW_EnDisChnErrorInt(SafeDMAIstanceNumType instance, uint8_t channel, boolean enable);
static inline void SAF_EDMA_HW_GetChnErrorIntFlag(SafeDMAIstanceNumType instance, SafeDMAErrorRegisterType * errReg);
static inline void SAF_EDMA_HW_ClearChnErrorIntFlag(SafeDMAIstanceNumType instance, uint8_t channel);
static inline void SAF_EDMA_HW_EnDisChnDmaReq(SafeDMAIstanceNumType instance, uint8_t channel, boolean enable);
static inline void SAF_EDMA_HW_WaitChnTransferDoneFlag(SafeDMAIstanceNumType instance, uint8_t channel);
static inline void SAF_EDMA_HW_ClearChnTransferDoneFlag(SafeDMAIstanceNumType instance, uint8_t channel);
static inline void SAF_EDMA_HW_SetChnTrigStart(SafeDMAIstanceNumType instance, uint8_t channel);
static inline void SAF_EDMA_HW_ClearChnIntFlag(SafeDMAIstanceNumType instance, uint8_t channel);
void SAF_EDMA_HW_ConfGrpPri(SafeDMAIstanceNumType instance, const SafeDMAModuleConfigType * userConfig);
void SAF_EDMA_HW_SetGrpArbitrationMode(SafeDMAIstanceNumType instance, SafeDMASelArbitrationModeType groupArbitration);
SafeDMASelArbitrationModeType SAF_EDMA_HW_GetGrpArbitrationMode(SafeDMAIstanceNumType instance);
static void SAF_EDMA_HW_EnDisMinorLoopMapping(SafeDMAIstanceNumType instance, boolean enable);
static void SAF_EDMA_HW_TCDDeInit(SafeDMAIstanceNumType instance, uint8_t channel);
void SAF_EDMA_HW_TCDSetBusBindwidth(SafeDMAIstanceNumType instance, uint8_t channel, uint8_t cycles);
static inline void SAF_EDMA_HW_TCDSetSrcAddr(SafeDMAIstanceNumType instance, uint8_t channel, uint32_t address);
static inline void SAF_EDMA_HW_TCDSetSrcAddrOffset(SafeDMAIstanceNumType instance, uint8_t channel, int16_t offset);
static void SAF_EDMA_HW_TCDSetTransferAttribute(
                 SafeDMAIstanceNumType instance, uint8_t channel,
                 SafeDMAModuloType srcModulo, SafeDMAModuloType destModulo,
                 SafeDMATransferSizeType srcTransferSize, SafeDMATransferSizeType destTransferSize);
static void SAF_EDMA_HW_TCDSetSrcDataTransferSize(SafeDMAIstanceNumType instance, uint8_t channel, SafeDMATransferSizeType size);
static void SAF_EDMA_HW_TCDSetDestDataTransferSize(SafeDMAIstanceNumType instance, uint8_t channel, SafeDMATransferSizeType size);
static void SAF_EDMA_HW_TCDSetMinorByteCount(SafeDMAIstanceNumType instance, uint8_t channel, uint32_t nbytes);
static void SAF_EDMA_HW_TCDEnDisSrcMinorLoopOffset(SafeDMAIstanceNumType instance, uint8_t channel, boolean enable);
static void SAF_EDMA_HW_TCDEnDisDestMinorLoopOffset(SafeDMAIstanceNumType instance, uint8_t channel, boolean enable);
static void SAF_EDMA_HW_TCDSetMinorLoopOffset(SafeDMAIstanceNumType instance, uint8_t channel, int32_t offset);
static inline void SAF_EDMA_HW_TCDSetSrcLastAdjust(SafeDMAIstanceNumType instance, uint8_t channel, int32_t size);
static inline void SAF_EDMA_HW_TCDSetDestAddr(SafeDMAIstanceNumType instance, uint8_t channel, uint32_t address);
static inline void SAF_EDMA_HW_TCDSetDestAddrOffset(SafeDMAIstanceNumType instance, uint8_t channel, int16_t offset);
static inline void SAF_EDMA_HW_TCDSetDestLastAdjust(SafeDMAIstanceNumType instance, uint8_t channel, int32_t adjust);
static inline void SAF_EDMA_HW_TCDSetScatterGatherLink(SafeDMAIstanceNumType instance, uint8_t channel, uint32_t nextTCDAddr);
static void SAF_EDMA_HW_TCDSetScatterGatherCmd(SafeDMAIstanceNumType instance, uint8_t channel, boolean enable);/* PRQA S 0779 */
static void SAF_EDMA_HW_TCDSetChannelMajorLink(SafeDMAIstanceNumType instance, uint8_t channel, uint32_t majorLinkChannel, boolean enable);
static void SAF_EDMA_HW_TCDSetDisableDmaRequestAfterTCDDoneCmd(SafeDMAIstanceNumType instance, uint8_t channel, boolean disable);
static void SAF_EDMA_HW_TCDSetMajorHalfCompleteIntCmd(SafeDMAIstanceNumType instance, uint8_t channel, boolean enable);
static void SAF_EDMA_HW_TCDSetMajorCompleteIntCmd(SafeDMAIstanceNumType instance, uint8_t channel, boolean enable);
static void SAF_EDMA_HW_TCDSetChannelMinorLink(SafeDMAIstanceNumType instance, uint8_t channel, uint32_t linkChannel, boolean enable);
static void SAF_EDMA_HW_TCDSetMajorCount(SafeDMAIstanceNumType instance, uint8_t channel, uint32_t count);
static uint32_t SAF_EDMA_HW_TCDGetCurrentMajorCount(SafeDMAIstanceNumType instance, uint8_t channel);
static void SAF_EDMA_HW_PushConfigToReg(uint8_t mappedChannel,
                              const SafeDMATransferConfigType *tcd);
static void SAF_DMAMUX_HW_Init(SAF_DMAMUXInstanceNumType instance);
static void SAF_DMAMUX_HW_SetChannelCmd(SAF_DMAMUXInstanceNumType instance, uint8_t channel, boolean enable);
static void SAF_DMAMUX_HW_SetChannelTrigger(SAF_DMAMUXInstanceNumType instance, uint8_t channel, boolean enable);
static void SAF_DMAMUX_HW_SetChannelSource(SAF_DMAMUXInstanceNumType instance, uint8_t channel, uint8_t source);

void SAF_EDMA_HW_ReleaseChannel(uint8_t mappedChannel);

static void SAF_EDMA_HW_IrqInstall(uint32_t mappedChannel);

static void SAF_EDMA_LLD_IRQHandler(uint8_t mappedChannel);

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_Init(SafeDMAIstanceNumType instance)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    uint8_t idx;
    uint32_t tempValue;
    tempValue = baseAddr->CR.R;/* polyspace RTE:NIV */
    tempValue &= ~(SAF_DMA_CR_CLM_MASK);
    tempValue &= ~(SAF_DMA_CR_CX_MASK);
    tempValue &= ~(SAF_DMA_CR_ECX_MASK);
    tempValue &= ~(SAF_DMA_CR_EDBG_MASK);
    tempValue &= ~(SAF_DMA_CR_EMLM_MASK);
    tempValue &= ~(SAF_DMA_CR_ERCA_MASK);
    baseAddr->CR.R = tempValue;

    baseAddr->ERQH.R = 0U;
    baseAddr->ERQL.R = 0U;
    baseAddr->EEIH.R = 0U;
    baseAddr->EEIL.R = 0U;

    baseAddr->INTH.R = 0U;
    baseAddr->INTL.R = 0U;

    baseAddr->ERRH.R = 0xFFFFFFFFU;
    baseAddr->ERRL.R = 0xFFFFFFFFU;

    for (idx = 0U; idx < MODULES_SAF_EDMA_CHANNELS; idx++)
    {
        SAF_EDMA_HW_TCDDeInit(instance, idx);
    }
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_CancelExecChnTransfer(SafeDMAIstanceNumType instance)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    uint32_t tempValue;
    tempValue = baseAddr->CR.R;/* polyspace RTE:NIV */
    tempValue &= ~(SAF_DMA_CR_CX_MASK);
    tempValue |= SAF_DMA_CR_CX(1U);
    baseAddr->CR.R = tempValue;
    while ((baseAddr->CR.R & SAF_DMA_CR_CX_MASK) != 0UL)
    {}
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_CancelExecChnTransferWithError(SafeDMAIstanceNumType instance)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    uint32_t tempValue;

    tempValue = baseAddr->CR.R;/* polyspace RTE:NIV */
    tempValue &= ~(SAF_DMA_CR_ECX_MASK);
    tempValue |= SAF_DMA_CR_ECX(1U);
    baseAddr->CR.R = tempValue;
    while ((baseAddr->CR.R & SAF_DMA_CR_ECX_MASK) != 0UL)
    {}
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_EnDisHaltOnError(SafeDMAIstanceNumType instance, boolean haltOnError)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    uint32_t tempValue;

    tempValue = baseAddr->CR.R;/* polyspace RTE:NIV */
    tempValue &= ~(SAF_DMA_CR_HOE_MASK);
    tempValue |= SAF_DMA_CR_HOE((haltOnError == TRUE) ? 1UL : 0UL); /* PRQA S 2985 */
    baseAddr->CR.R = tempValue;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_SetChnPri(SafeDMAIstanceNumType instance, uint8_t channel, SafeDMAChannelPriorityType priority)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    uint8_t tempValue;
    uint8_t index = (uint8_t)SAF_EDMA_CHN_TO_DCHPRI_INDEX(channel);
    tempValue = baseAddr->DCHPRI[index].R; /* polyspace RTE:NIV */
    tempValue &= (uint8_t)~(SAF_DMA_DCHPRI_CHPRI_MASK);
    tempValue |= SAF_DMA_DCHPRI_CHPRI(priority); /* PRQA S 2985 */
    baseAddr->DCHPRI[index].R = tempValue;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_SetChnArbitrationMode(SafeDMAIstanceNumType instance, SafeDMASelArbitrationModeType channelArbitration)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    uint32_t tempValue;
    tempValue = baseAddr->CR.R;/* polyspace RTE:NIV */
    tempValue &= ~(SAF_DMA_CR_ERCA_MASK);
    tempValue |= SAF_DMA_CR_ERCA(channelArbitration);
    baseAddr->CR.R = tempValue;
}

SAF_DMA_SEC_CODE
static SafeDMASelArbitrationModeType SAF_EDMA_HW_GetChnArbitrationMode(SafeDMAIstanceNumType instance)
{
    const SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    SafeDMASelArbitrationModeType retVal;

    if ((baseAddr->CR.R & SAF_DMA_CR_ERCA_MASK) != 0U)/* polyspace RTE:NIV */
    {
        retVal = SAF_EDMA_ARBITRATION_MODE_ROUND_ROBIN;
    }
    else
    {
        retVal = SAF_EDMA_ARBITRATION_MODE_FIXED_PRIORITY;
    }
    return retVal;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_EnDisChnErrorInt(SafeDMAIstanceNumType instance, uint8_t channel, boolean enable)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    if (enable == TRUE)
    {
        baseAddr->SEEI.R = channel;
    }
    else
    {
        baseAddr->CEEI.R = channel;
    }
}

SAF_DMA_SEC_CODE
static inline void SAF_EDMA_HW_GetChnErrorIntFlag(SafeDMAIstanceNumType instance, SafeDMAErrorRegisterType * errReg)
{
    const SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    errReg->errh = (uint32_t)baseAddr->ERRH.R;/* polyspace RTE:NIV */
    errReg->errl = (uint32_t)baseAddr->ERRL.R;/* polyspace RTE:NIV */
}

SAF_DMA_SEC_CODE
static inline void SAF_EDMA_HW_ClearChnErrorIntFlag(SafeDMAIstanceNumType instance, uint8_t channel)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    baseAddr->CERR.R = (uint8_t)channel;
}

SAF_DMA_SEC_CODE
static inline void SAF_EDMA_HW_EnDisChnDmaReq(SafeDMAIstanceNumType instance, uint8_t channel, boolean enable)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    if (enable == TRUE)
    {
        baseAddr->SERQ.R = channel;
    }
    else
    {
        baseAddr->CERQ.R = channel;
    }
}

SAF_DMA_SEC_CODE
static inline void SAF_EDMA_HW_WaitChnTransferDoneFlag(SafeDMAIstanceNumType instance, uint8_t channel)
{
    const SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    while (baseAddr->TCD[channel].CSR.B.DONE != 1U)/* polyspace RTE:NIV */
    {}
}

SAF_DMA_SEC_CODE
static inline void SAF_EDMA_HW_ClearChnTransferDoneFlag(SafeDMAIstanceNumType instance, uint8_t channel)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    baseAddr->CDNE.R = (uint8_t)channel;
}

SAF_DMA_SEC_CODE
static inline void SAF_EDMA_HW_SetChnTrigStart(SafeDMAIstanceNumType instance, uint8_t channel)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    baseAddr->SSRT.R = (uint8_t)channel;
}

SAF_DMA_SEC_CODE
static inline void SAF_EDMA_HW_ClearChnIntFlag(SafeDMAIstanceNumType instance, uint8_t channel)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    baseAddr->CINT.R = (uint8_t)channel;
}

SAF_DMA_SEC_CODE
void SAF_EDMA_HW_ConfGrpPri(SafeDMAIstanceNumType instance, const SafeDMAModuleConfigType * userConfig)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    uint32_t tempValue = baseAddr->CR.R;/* polyspace RTE:NIV */
    uint32_t mask = 0UL;

    mask = SAF_DMA_CR_GRP0PRI_MASK | SAF_DMA_CR_GRP1PRI_MASK | SAF_DMA_CR_GRP2PRI_MASK | SAF_DMA_CR_GRP3PRI_MASK;
    tempValue &= ~mask;
    tempValue |= SAF_DMA_CR_GRP0PRI(userConfig->prioGroup0);
    tempValue |= SAF_DMA_CR_GRP1PRI(userConfig->prioGroup1);
    tempValue |= SAF_DMA_CR_GRP2PRI(userConfig->prioGroup2);
    tempValue |= SAF_DMA_CR_GRP3PRI(userConfig->prioGroup3);

    baseAddr->CR.R = tempValue;
}

SAF_DMA_SEC_CODE
void SAF_EDMA_HW_SetGrpArbitrationMode(SafeDMAIstanceNumType instance, SafeDMASelArbitrationModeType groupArbitration)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    uint32_t tempValue;
    tempValue = baseAddr->CR.R;/* polyspace RTE:NIV */
    tempValue &= ~(SAF_DMA_CR_ERGA_MASK);
    tempValue |= SAF_DMA_CR_ERGA(groupArbitration);
    baseAddr->CR.R = tempValue;
}

SAF_DMA_SEC_CODE
SafeDMASelArbitrationModeType SAF_EDMA_HW_GetGrpArbitrationMode(SafeDMAIstanceNumType instance)
{
    const SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    SafeDMASelArbitrationModeType retVal;

    if ((baseAddr->CR.R & SAF_DMA_CR_ERGA_MASK) != 0U)/* polyspace RTE:NIV */
    {
        retVal = SAF_EDMA_ARBITRATION_MODE_ROUND_ROBIN;
    }
    else
    {
        retVal = SAF_EDMA_ARBITRATION_MODE_FIXED_PRIORITY;
    }
    return retVal;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_EnDisMinorLoopMapping(SafeDMAIstanceNumType instance, boolean enable)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    uint32_t tempValue;

    tempValue = baseAddr->CR.R;/* polyspace RTE:NIV */
    tempValue &= ~(SAF_DMA_CR_EMLM_MASK);
    tempValue |= SAF_DMA_CR_EMLM((enable == TRUE) ? 1UL : 0UL); /* PRQA S 2985 */
    baseAddr->CR.R = tempValue;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_TCDDeInit(SafeDMAIstanceNumType instance, uint8_t channel)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    baseAddr->TCD[channel].NBYTES.MLNO.R = 0U;
    baseAddr->TCD[channel].SADDR.R = 0U;
    baseAddr->TCD[channel].SOFF.R = 0;
    baseAddr->TCD[channel].ATTR.R = 0U;
    baseAddr->TCD[channel].SLAST.R = 0;
    baseAddr->TCD[channel].DADDR.R = 0U;
    baseAddr->TCD[channel].DOFF.R = 0;
    baseAddr->TCD[channel].CITER.ELINKNO.R = 0U;
    baseAddr->TCD[channel].DLASTSGA.R = 0;
    baseAddr->TCD[channel].CSR.R = 0U;
    baseAddr->TCD[channel].BITER.ELINKNO.R = 0U;
}

SAF_DMA_SEC_CODE
void SAF_EDMA_HW_TCDSetBusBindwidth(SafeDMAIstanceNumType instance, uint8_t channel, uint8_t cycles)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    uint16_t tempValue;
    tempValue = baseAddr->TCD[channel].CSR.R;/* polyspace RTE:NIV,OBAI */
    tempValue &= ~(SAF_DMA_TCD_CSR_BWC_MASK);
    tempValue |= SAF_DMA_TCD_CSR_BWC(cycles); /* PRQA S 2985 */
    baseAddr->TCD[channel].CSR.R = tempValue;
}

SAF_DMA_SEC_CODE
static inline void SAF_EDMA_HW_TCDSetSrcAddr(SafeDMAIstanceNumType instance, uint8_t channel, uint32_t address)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    baseAddr->TCD[channel].SADDR.R = address;
}

SAF_DMA_SEC_CODE
static inline void SAF_EDMA_HW_TCDSetSrcAddrOffset(SafeDMAIstanceNumType instance, uint8_t channel, int16_t offset)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    baseAddr->TCD[channel].SOFF.R = (uint16_t)offset;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_TCDSetTransferAttribute(
                 SafeDMAIstanceNumType instance, uint8_t channel,
                 SafeDMAModuloType srcModulo, SafeDMAModuloType destModulo,
                 SafeDMATransferSizeType srcTransferSize, SafeDMATransferSizeType destTransferSize)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    uint16_t tempValue;
    tempValue = (uint16_t)(SAF_DMA_TCD_ATTR_SMOD(srcModulo) | SAF_DMA_TCD_ATTR_SSIZE(srcTransferSize)); /* PRQA S 2985 */
    tempValue |= (uint16_t)(SAF_DMA_TCD_ATTR_DMOD(destModulo) | SAF_DMA_TCD_ATTR_DSIZE(destTransferSize)); /* PRQA S 2985 */
    baseAddr->TCD[channel].ATTR.R = tempValue;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_TCDSetSrcDataTransferSize(SafeDMAIstanceNumType instance, uint8_t channel, SafeDMATransferSizeType size)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    uint16_t tempValue;
    tempValue = baseAddr->TCD[channel].ATTR.R;/* polyspace RTE:NIV */
    tempValue &= (uint16_t)(~(SAF_DMA_TCD_ATTR_SSIZE_MASK));
    tempValue |= (uint16_t)(SAF_DMA_TCD_ATTR_SSIZE((uint16_t)size));
    baseAddr->TCD[channel].ATTR.R = tempValue;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_TCDSetDestDataTransferSize(SafeDMAIstanceNumType instance, uint8_t channel, SafeDMATransferSizeType size)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    uint16_t tempValue;
    tempValue = baseAddr->TCD[channel].ATTR.R;/* polyspace RTE:NIV */
    tempValue &= (uint16_t)(~(SAF_DMA_TCD_ATTR_DSIZE_MASK));
    tempValue |= (uint16_t)(SAF_DMA_TCD_ATTR_DSIZE((uint16_t)size)); /* PRQA S 2985 */
    baseAddr->TCD[channel].ATTR.R = tempValue;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_TCDSetMinorByteCount(SafeDMAIstanceNumType instance, uint8_t channel, uint32_t nbytes)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    if ((baseAddr->CR.R & SAF_DMA_CR_EMLM_MASK) != 0UL)/* polyspace RTE:NIV */
    {
        uint32_t sdmloe = baseAddr->TCD[channel].NBYTES.MLOFFNO.R & (SAF_DMA_TCD_NBYTES_MLOFFNO_SMLOE_MASK | SAF_DMA_TCD_NBYTES_MLOFFNO_DMLOE_MASK);/* polyspace RTE:NIV */
        if (sdmloe == 0UL)
        {
            baseAddr->TCD[channel].NBYTES.MLOFFNO.R = (nbytes & SAF_DMA_TCD_NBYTES_MLOFFNO_NBYTES_MASK);
        }
        else
        {
            uint32_t tempValue;
            tempValue = baseAddr->TCD[channel].NBYTES.MLOFFYES.R;/* polyspace RTE:NIV */
            tempValue &= ~(SAF_DMA_TCD_NBYTES_MLOFFYES_NBYTES_MASK);
            tempValue |= SAF_DMA_TCD_NBYTES_MLOFFYES_NBYTES(nbytes); /* PRQA S 2985 */
            baseAddr->TCD[channel].NBYTES.MLOFFYES.R = tempValue;
        }
    }
    else
    {
        baseAddr->TCD[channel].NBYTES.MLNO.R = nbytes;
    }
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_TCDEnDisSrcMinorLoopOffset(SafeDMAIstanceNumType instance, uint8_t channel, boolean enable)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    if ((baseAddr->CR.R & SAF_DMA_CR_EMLM_MASK) != 0UL)/* polyspace RTE:NIV */
    {
        uint32_t tempValue;
        tempValue = baseAddr->TCD[channel].NBYTES.MLOFFYES.R;/* polyspace RTE:NIV */
        tempValue &= ~(SAF_DMA_TCD_NBYTES_MLOFFYES_SMLOE_MASK);
        tempValue |= SAF_DMA_TCD_NBYTES_MLOFFYES_SMLOE((enable == TRUE) ? 1UL : 0UL); /* PRQA S 2985 */
        baseAddr->TCD[channel].NBYTES.MLOFFYES.R = tempValue;
    }
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_TCDEnDisDestMinorLoopOffset(SafeDMAIstanceNumType instance, uint8_t channel, boolean enable)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    if ((baseAddr->CR.R & SAF_DMA_CR_EMLM_MASK) != 0UL)/* polyspace RTE:NIV */
    {
        uint32_t tempValue;
        tempValue = baseAddr->TCD[channel].NBYTES.MLOFFYES.R;/* polyspace RTE:NIV */
        tempValue &= ~(SAF_DMA_TCD_NBYTES_MLOFFYES_DMLOE_MASK);
        tempValue |= SAF_DMA_TCD_NBYTES_MLOFFYES_DMLOE((enable == TRUE) ? 1UL : 0UL); /* PRQA S 2985 */
        baseAddr->TCD[channel].NBYTES.MLOFFYES.R = tempValue;
    }
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_TCDSetMinorLoopOffset(SafeDMAIstanceNumType instance, uint8_t channel, int32_t offset)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    if ((baseAddr->CR.R & SAF_DMA_CR_EMLM_MASK) != 0UL)/* polyspace RTE:NIV */
    {
        uint32_t sdmloe = baseAddr->TCD[channel].NBYTES.MLOFFNO.R & (SAF_DMA_TCD_NBYTES_MLOFFNO_SMLOE_MASK | SAF_DMA_TCD_NBYTES_MLOFFNO_DMLOE_MASK);/* polyspace RTE:NIV */
        if (sdmloe != 0UL)
        {
            uint32_t tempValue;
            tempValue = baseAddr->TCD[channel].NBYTES.MLOFFYES.R;/* polyspace RTE:NIV */
            tempValue &= ~(SAF_DMA_TCD_NBYTES_MLOFFYES_MLOFF_MASK);
            tempValue |= SAF_DMA_TCD_NBYTES_MLOFFYES_MLOFF(offset);
            baseAddr->TCD[channel].NBYTES.MLOFFYES.R = tempValue;
        }
    }
}

SAF_DMA_SEC_CODE
static inline void SAF_EDMA_HW_TCDSetSrcLastAdjust(SafeDMAIstanceNumType instance, uint8_t channel, int32_t size)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    baseAddr->TCD[channel].SLAST.R = (uint32_t)size;
}

SAF_DMA_SEC_CODE
static inline void SAF_EDMA_HW_TCDSetDestAddr(SafeDMAIstanceNumType instance, uint8_t channel, uint32_t address)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    baseAddr->TCD[channel].DADDR.R = address;
}

SAF_DMA_SEC_CODE
static inline void SAF_EDMA_HW_TCDSetDestAddrOffset(SafeDMAIstanceNumType instance, uint8_t channel, int16_t offset)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    baseAddr->TCD[channel].DOFF.R = (uint16_t)offset;
}

SAF_DMA_SEC_CODE
static inline void SAF_EDMA_HW_TCDSetDestLastAdjust(SafeDMAIstanceNumType instance, uint8_t channel, int32_t adjust)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    baseAddr->TCD[channel].DLASTSGA.R = (uint32_t)adjust;
}

SAF_DMA_SEC_CODE
static inline void SAF_EDMA_HW_TCDSetScatterGatherLink(SafeDMAIstanceNumType instance, uint8_t channel, uint32_t nextTCDAddr)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    baseAddr->TCD[channel].DLASTSGA.R = nextTCDAddr;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_TCDSetScatterGatherCmd(SafeDMAIstanceNumType instance, uint8_t channel, boolean enable)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    uint16_t tempValue;
    tempValue = baseAddr->TCD[channel].CSR.R;/* polyspace RTE:NIV */
    tempValue &= (uint16_t)~(SAF_DMA_TCD_CSR_ESG_MASK);
    tempValue |= (uint16_t)SAF_DMA_TCD_CSR_ESG((enable == TRUE) ? 1U : 0U); /* PRQA S 2985 */
    baseAddr->TCD[channel].CSR.R = tempValue;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_TCDSetChannelMajorLink(SafeDMAIstanceNumType instance, uint8_t channel, uint32_t majorLinkChannel, boolean enable)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    uint16_t tempValue;
    tempValue = baseAddr->TCD[channel].CSR.R;/* polyspace RTE:NIV */
    tempValue &= (uint16_t)~(SAF_DMA_TCD_CSR_MAJORLINKCH_MASK);
    tempValue |= (uint16_t)SAF_DMA_TCD_CSR_MAJORLINKCH(majorLinkChannel);
    baseAddr->TCD[channel].CSR.R = tempValue;
    tempValue = baseAddr->TCD[channel].CSR.R;
    tempValue &= (uint16_t)~(SAF_DMA_TCD_CSR_MAJORELINK_MASK);
    tempValue |= (uint16_t)SAF_DMA_TCD_CSR_MAJORELINK((enable == TRUE) ? 1U : 0U); /* PRQA S 2985 */
    baseAddr->TCD[channel].CSR.R = tempValue;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_TCDSetDisableDmaRequestAfterTCDDoneCmd(SafeDMAIstanceNumType instance, uint8_t channel, boolean disable)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    uint16_t tempValue;
    tempValue = baseAddr->TCD[channel].CSR.R;/* polyspace RTE:NIV */
    tempValue &= (uint16_t)~(SAF_DMA_TCD_CSR_DREQ_MASK);
    tempValue |= (uint16_t)SAF_DMA_TCD_CSR_DREQ((disable == TRUE) ? 1U : 0U); /* PRQA S 2985 */
    baseAddr->TCD[channel].CSR.R = tempValue;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_TCDSetMajorHalfCompleteIntCmd(SafeDMAIstanceNumType instance, uint8_t channel, boolean enable)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    uint16_t tempValue;
    tempValue = baseAddr->TCD[channel].CSR.R;/* polyspace RTE:NIV */
    tempValue &= (uint16_t)~(SAF_DMA_TCD_CSR_INTHALF_MASK);
    tempValue |= (uint16_t)SAF_DMA_TCD_CSR_INTHALF((enable == TRUE) ? 1U : 0U); /* PRQA S 2985 */
    baseAddr->TCD[channel].CSR.R = tempValue;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_TCDSetMajorCompleteIntCmd(SafeDMAIstanceNumType instance, uint8_t channel, boolean enable)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    uint16_t tempValue;
    tempValue = baseAddr->TCD[channel].CSR.R;/* polyspace RTE:NIV */
    tempValue &= (uint16_t)~(SAF_DMA_TCD_CSR_INTMAJOR_MASK);
    tempValue |= (uint16_t)SAF_DMA_TCD_CSR_INTMAJOR((enable == TRUE) ? 1U : 0U); /* PRQA S 2985 */
    baseAddr->TCD[channel].CSR.R = tempValue;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_TCDSetChannelMinorLink(SafeDMAIstanceNumType instance, uint8_t channel, uint32_t linkChannel, boolean enable)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance];
    uint16_t tempValue = 0U;
    if (enable == TRUE)
    {
        tempValue = baseAddr->TCD[channel].BITER.ELINKYES.R;/* polyspace RTE:NIV */
        tempValue &= (uint16_t)~(SAF_DMA_TCD_BITER_ELINKYES_ELINK_MASK);
        tempValue |= (uint16_t)SAF_DMA_TCD_BITER_ELINKYES_ELINK(1UL);
        tempValue &= (uint16_t)~(SAF_DMA_TCD_BITER_ELINKYES_LINKCH_MASK);
        tempValue |= (uint16_t)SAF_DMA_TCD_BITER_ELINKYES_LINKCH(linkChannel);
        baseAddr->TCD[channel].BITER.ELINKYES.R = tempValue;
        tempValue = baseAddr->TCD[channel].CITER.ELINKYES.R;/* polyspace RTE:NIV */
        tempValue &= (uint16_t)~(SAF_DMA_TCD_CITER_ELINKYES_ELINK_MASK);
        tempValue |= (uint16_t)SAF_DMA_TCD_CITER_ELINKYES_ELINK(1UL);
        tempValue &= (uint16_t)~(SAF_DMA_TCD_CITER_ELINKYES_LINKCH_MASK);
        tempValue |= (uint16_t)SAF_DMA_TCD_CITER_ELINKYES_LINKCH(linkChannel);
        baseAddr->TCD[channel].CITER.ELINKYES.R = tempValue;
    }
    else
    {
        tempValue = baseAddr->TCD[channel].BITER.ELINKNO.R;/* polyspace RTE:NIV */
        tempValue &= (uint16_t)~(SAF_DMA_TCD_BITER_ELINKYES_ELINK_MASK);
        tempValue |= (uint16_t)SAF_DMA_TCD_BITER_ELINKYES_ELINK(0U); /* PRQA S 2985 */
        tempValue &= (uint16_t)~(SAF_DMA_TCD_BITER_ELINKYES_LINKCH_MASK);
        tempValue |= (uint16_t)SAF_DMA_TCD_BITER_ELINKYES_LINKCH(linkChannel);
        baseAddr->TCD[channel].BITER.ELINKNO.R = tempValue;
        tempValue = baseAddr->TCD[channel].CITER.ELINKNO.R;/* polyspace RTE:NIV */
        tempValue &= (uint16_t)~(SAF_DMA_TCD_CITER_ELINKYES_ELINK_MASK);
        tempValue |= (uint16_t)SAF_DMA_TCD_CITER_ELINKYES_ELINK(0U); /* PRQA S 2985 */
        tempValue &= (uint16_t)~(SAF_DMA_TCD_CITER_ELINKYES_LINKCH_MASK);
        tempValue |= (uint16_t)SAF_DMA_TCD_CITER_ELINKYES_LINKCH(linkChannel);
        baseAddr->TCD[channel].CITER.ELINKNO.R = tempValue;
    }
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_TCDSetMajorCount(SafeDMAIstanceNumType instance, uint8_t channel, uint32_t count)
{
    SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    uint16_t tempValue = 0U;
    if ((baseAddr->TCD[channel].BITER.ELINKNO.R & SAF_DMA_TCD_BITER_ELINKNO_ELINK_MASK) != 0U)/* polyspace RTE:NIV */
    {
        tempValue = baseAddr->TCD[channel].BITER.ELINKYES.R;/* polyspace RTE:NIV */
        tempValue &= (uint16_t)~(SAF_DMA_TCD_BITER_ELINKYES_BITER_MASK);
        tempValue |= (uint16_t)SAF_DMA_TCD_BITER_ELINKYES_BITER(count); /* PRQA S 2985 */
        baseAddr->TCD[channel].BITER.ELINKYES.R = tempValue;
        tempValue = baseAddr->TCD[channel].CITER.ELINKYES.R;/* polyspace RTE:NIV */
        tempValue &= (uint16_t)~(SAF_DMA_TCD_CITER_ELINKYES_CITER_MASK);
        tempValue |= (uint16_t)SAF_DMA_TCD_CITER_ELINKYES_CITER(count); /* PRQA S 2985 */
        baseAddr->TCD[channel].CITER.ELINKYES.R = tempValue;
    }
    else
    {
        tempValue = baseAddr->TCD[channel].BITER.ELINKNO.R;/* polyspace RTE:NIV */
        tempValue &= (uint16_t)~(SAF_DMA_TCD_BITER_ELINKNO_BITER_MASK);
        tempValue |= (uint16_t)SAF_DMA_TCD_BITER_ELINKNO_BITER(count); /* PRQA S 2985 */
        baseAddr->TCD[channel].BITER.ELINKNO.R = tempValue;
        tempValue = baseAddr->TCD[channel].CITER.ELINKNO.R;/* polyspace RTE:NIV */
        tempValue &= (uint16_t)~(SAF_DMA_TCD_CITER_ELINKNO_CITER_MASK);
        tempValue |= (uint16_t)SAF_DMA_TCD_CITER_ELINKNO_CITER(count); /* PRQA S 2985 */
        baseAddr->TCD[channel].CITER.ELINKNO.R = tempValue;
    }
}

SAF_DMA_SEC_CODE
static uint32_t SAF_EDMA_HW_TCDGetCurrentMajorCount(SafeDMAIstanceNumType instance, uint8_t channel)
{
    const SAF_DMA_Type * const baseAddr = s_edmabaseAddr[instance]; /* polyspace RTE:OBAI */
    uint16_t result = 0U;
    if ((baseAddr->TCD[channel].BITER.ELINKNO.R & SAF_DMA_TCD_BITER_ELINKNO_ELINK_MASK) != 0U)/* polyspace RTE:NIV */
    {
        result = (uint16_t)((baseAddr->TCD[channel].CITER.ELINKYES.R & SAF_DMA_TCD_CITER_ELINKYES_CITER_MASK) >>  SAF_DMA_TCD_CITER_ELINKYES_CITER_SHIFT); /* polyspace RTE:NIV */                         
    }
    else
    {
        result = (uint16_t)((baseAddr->TCD[channel].CITER.ELINKNO.R & SAF_DMA_TCD_CITER_ELINKNO_CITER_MASK) >> SAF_DMA_TCD_CITER_ELINKNO_CITER_SHIFT); /* polyspace RTE:NIV */                            
    }
    return (uint32_t) result;
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_PushConfigToReg(uint8_t mappedChannel,
                              const SafeDMATransferConfigType *tcd)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(tcd != NULL);

    SafeDMAIstanceNumType edma_instance = (SafeDMAIstanceNumType)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel); /* PRQA S 4394 */
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);
    uint32_t dmaMinorLoopLink;
    uint32_t dmaMajorLoopLink;

    SAF_EDMA_HW_TCDDeInit(edma_instance, edma_channel);
    SAF_EDMA_HW_TCDSetSrcAddr(edma_instance, edma_channel, tcd->srcAddr);
    SAF_EDMA_HW_TCDSetDestAddr(edma_instance, edma_channel, tcd->destAddr);
    SAF_EDMA_HW_TCDSetTransferAttribute(edma_instance, edma_channel, tcd->srcAddrModulo, tcd->destAddrModulo,
                         tcd->srcTransDataSize, tcd->destTransDataSize);
    SAF_EDMA_HW_TCDSetSrcAddrOffset(edma_instance, edma_channel, tcd->srcAddrOffset);
    SAF_EDMA_HW_TCDSetDestAddrOffset(edma_instance, edma_channel, tcd->destAddrOffset);
    SAF_EDMA_HW_TCDSetSrcLastAdjust(edma_instance, edma_channel, tcd->srcAddrAdjustLast);

    if (tcd->featureScatterGatherEn == TRUE)
    {
        SAF_EDMA_HW_TCDSetScatterGatherCmd(edma_instance, edma_channel, TRUE);
        SAF_EDMA_HW_TCDSetScatterGatherLink(edma_instance, edma_channel, tcd->featureScatterGatherNextDescriptor);
    }
    else
    {
        SAF_EDMA_HW_TCDSetScatterGatherCmd(edma_instance, edma_channel, FALSE);
        SAF_EDMA_HW_TCDSetDestLastAdjust(edma_instance, edma_channel, tcd->destAddrAdjustLast);
    }

    SAF_EDMA_HW_TCDSetMajorCompleteIntCmd(edma_instance, edma_channel, tcd->completeIntEn);

    if (tcd->lpTransConfigPtr != NULL)
    {
        dmaMinorLoopLink = (uint32_t)SAF_EDMA_MCH_TO_CH(tcd->lpTransConfigPtr->minorLpLinkChn);/* polyspace RTE:NIV */
        dmaMajorLoopLink = (uint32_t)SAF_EDMA_MCH_TO_CH(tcd->lpTransConfigPtr->majorLpLinkChn);/* polyspace RTE:NIV */
        SAF_EDMA_HW_TCDEnDisSrcMinorLoopOffset(edma_instance, edma_channel, tcd->lpTransConfigPtr->srcAddrOffsetEn);/* polyspace RTE:NIV */
        SAF_EDMA_HW_TCDEnDisDestMinorLoopOffset(edma_instance, edma_channel, tcd->lpTransConfigPtr->dstAddrOffsetEn);/* polyspace RTE:NIV */
        SAF_EDMA_HW_TCDSetMinorLoopOffset(edma_instance, edma_channel, tcd->lpTransConfigPtr->minorLpOffset);/* polyspace RTE:NIV */
        SAF_EDMA_HW_TCDSetMinorByteCount(edma_instance, edma_channel, tcd->minorTransByte);
        SAF_EDMA_HW_TCDSetChannelMinorLink(edma_instance, edma_channel, dmaMinorLoopLink, tcd->lpTransConfigPtr->minorLpLinkEn);/* polyspace RTE:NIV */
        SAF_EDMA_HW_TCDSetChannelMajorLink(edma_instance, edma_channel, dmaMajorLoopLink, tcd->lpTransConfigPtr->majorLpLinkEn);/* polyspace RTE:NIV */
        SAF_EDMA_HW_TCDSetMajorCount(edma_instance, edma_channel, tcd->lpTransConfigPtr->majorLpIterCnt);
    }
    else
    {
        SAF_EDMA_HW_TCDSetMinorByteCount(edma_instance, edma_channel, tcd->minorTransByte);
    }
    return;
}

SAF_DMA_SEC_CODE
static void SAF_DMAMUX_HW_Init(SAF_DMAMUXInstanceNumType instance)
{
    SAF_DMAMUX_Type * const baseAddr = s_dmaMuxbaseAddr[instance];
    uint8_t idx;
    for (idx = 0U; idx < SAF_DMAMUX_CHANNELS; idx++)
    {
        baseAddr->CHCFG[idx] = 0U;
    }
}

SAF_DMA_SEC_CODE
static void SAF_DMAMUX_HW_SetChannelCmd(SAF_DMAMUXInstanceNumType instance, uint8_t channel, boolean enable)
{
    SAF_DMAMUX_Type * const baseAddr = s_dmaMuxbaseAddr[instance];
    uint32_t regIndex = SAF_DMAMUX_CHN_REG_INDEX(channel);
    uint8_t tempValue = baseAddr->CHCFG[regIndex];/* polyspace RTE:NIV */
    tempValue &= (uint8_t)~(SAF_DMAMUX_CHCFG_ENBL_MASK);
    tempValue |= (uint8_t)SAF_DMAMUX_CHCFG_ENBL((enable == TRUE) ? 1U : 0U);
    baseAddr->CHCFG[regIndex] = tempValue;
}

SAF_DMA_SEC_CODE
static void SAF_DMAMUX_HW_SetChannelTrigger(SAF_DMAMUXInstanceNumType instance, uint8_t channel, boolean enable)
{
    SAF_DMAMUX_Type * const baseAddr = s_dmaMuxbaseAddr[instance];
    uint32_t regIndex = SAF_DMAMUX_CHN_REG_INDEX(channel);
    uint8_t tempValue;
    tempValue = baseAddr->CHCFG[regIndex];/* polyspace RTE:NIV */
    tempValue &= (uint8_t)~(SAF_DMAMUX_CHCFG_TRIG_MASK);
    tempValue |= (uint8_t)SAF_DMAMUX_CHCFG_TRIG((enable == TRUE) ? 1U : 0U);
    baseAddr->CHCFG[regIndex] = tempValue;
}

SAF_DMA_SEC_CODE
static void SAF_DMAMUX_HW_SetChannelSource(SAF_DMAMUXInstanceNumType instance, uint8_t channel, uint8_t source)
{
    SAF_DMAMUX_Type * const baseAddr = s_dmaMuxbaseAddr[instance];
    uint32_t regIndex = SAF_DMAMUX_CHN_REG_INDEX(channel);
    uint8_t tempValue;
    tempValue = baseAddr->CHCFG[regIndex];/* polyspace RTE:NIV */
    tempValue &= (uint8_t)~(SAF_DMAMUX_CHCFG_SOURCE_MASK);
    tempValue |= (uint8_t)SAF_DMAMUX_CHCFG_SOURCE(source); /* PRQA S 2985 */
    baseAddr->CHCFG[regIndex] = tempValue;
}

SAF_DMA_SEC_CODE
status_t SAF_EDMA_LLD_SetUpCallback(uint8_t mappedChannel,
                                SafeDMACallbackType callback,
                                void *parameter)
{
    DEV_ASSERT(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    DEV_ASSERT(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    s_mapEdmaState->mapChnState[mappedChannel]->callback = callback; /* polyspace RTE:IDP */
    s_mapEdmaState->mapChnState[mappedChannel]->parameter = parameter;  /* polyspace RTE:IDP */

    return STATUS_SUCCESS;
}

SAF_DMA_SEC_CODE
void SAF_EDMA_HW_ReleaseChannel(uint8_t mappedChannel)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_TOTAL_CHANNELS);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_EnDisChnDmaReq((SafeDMAIstanceNumType)edma_instance, edma_channel, FALSE);

    return;
}

SAF_DMA_SEC_CODE
void SAF_EDMA_HW_ClearIntStatus(uint8_t mappedChannel)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_TOTAL_CHANNELS);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);
    SAF_EDMA_HW_ClearChnTransferDoneFlag((SafeDMAIstanceNumType)edma_instance, edma_channel);
    SAF_EDMA_HW_ClearChnIntFlag((SafeDMAIstanceNumType)edma_instance, edma_channel);
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_ClearStructPtr(uint8_t *sructPtr, volatile uint32_t size)
{
    uint8_t *s_sructPtr = sructPtr;
    volatile uint32_t s_size = size;

    while (s_size > 0U)
    {
        *s_sructPtr = 0U;  /* polyspace RTE:IDP */
        s_sructPtr++;/*PRQA S 0498*/
        s_size = s_size - 1U;
    }
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_HW_IrqInstall(uint32_t mappedChannel)
{
    IntrId irqNumber = NotAvail_IRQn;

    if (mappedChannel < SAF_EDMA_MAPPED_CHANNELS_INTERRUPT_LINES)
    {
        irqNumber = s_edmaIrqId[mappedChannel];
    }
    else
    {
        SAF_EDMA_DEV_ERR(FALSE);
    }

    switch (mappedChannel)
    {
        case(0U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch0_IRQHandler);
            break;
        case(1U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch1_IRQHandler);
            break;
        case(2U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch2_IRQHandler);
            break;
        case(3U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch3_IRQHandler);
            break;
        case(4U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch4_IRQHandler);
            break;
        case(5U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch5_IRQHandler);
            break;
        case(6U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch6_IRQHandler);
            break;
        case(7U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch7_IRQHandler);
            break;
        case(8U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch8_IRQHandler);
            break;
        case(9U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch9_IRQHandler);
            break;
        case(10U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch10_IRQHandler);
            break;
        case(11U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch11_IRQHandler);
            break;
        case(12U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch12_IRQHandler);
            break;
        case(13U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch13_IRQHandler);
            break;
        case(14U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch14_IRQHandler);
            break;
        case(15U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch15_IRQHandler);
            break;
        case(16U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch16_IRQHandler);
            break;
        case(17U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch17_IRQHandler);
            break;
        case(18U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch18_IRQHandler);
            break;
        case(19U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch19_IRQHandler);
            break;
        case(20U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch20_IRQHandler);
            break;
        case(21U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch21_IRQHandler);
            break;
        case(22U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch22_IRQHandler);
            break;
        case(23U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch23_IRQHandler);
            break;
        case(24U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch24_IRQHandler);
            break;
        case(25U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch25_IRQHandler);
            break;
        case(26U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch26_IRQHandler);
            break;
        case(27U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch27_IRQHandler);
            break;
        case(28U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch28_IRQHandler);
            break;
        case(29U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch29_IRQHandler);
            break;
        case(30U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch30_IRQHandler);
            break;
        case(31U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch31_IRQHandler);
            break;
        case(32U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch32_IRQHandler);
            break;
        case(33U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch33_IRQHandler);
            break;
        case(34U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch34_IRQHandler);
            break;
        case(35U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch35_IRQHandler);
            break;
        case(36U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch36_IRQHandler);
            break;
        case(37U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch37_IRQHandler);
            break;
        case(38U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch38_IRQHandler);
            break;
        case(39U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch39_IRQHandler);
            break;
        case(40U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch40_IRQHandler);
            break;
        case(41U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch41_IRQHandler);
            break;
        case(42U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch42_IRQHandler);
            break;
        case(43U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch43_IRQHandler);
            break;
        case(44U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch44_IRQHandler);
            break;
        case(45U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch45_IRQHandler);
            break;
        case(46U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch46_IRQHandler);
            break;
        case(47U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch47_IRQHandler);
            break;
        case(48U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch48_IRQHandler);
            break;
        case(49U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch49_IRQHandler);
            break;
        case(50U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch50_IRQHandler);
            break;
        case(51U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch51_IRQHandler);
            break;
        case(52U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch52_IRQHandler);
            break;
        case(53U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch53_IRQHandler);
            break;
        case(54U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch54_IRQHandler);
            break;
        case(55U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch55_IRQHandler);
            break;
        case(56U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch56_IRQHandler);
            break;
        case(57U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch57_IRQHandler);
            break;
        case(58U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch58_IRQHandler);
            break;
        case(59U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch59_IRQHandler);
            break;
        case(60U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch60_IRQHandler);
            break;
        case(61U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch61_IRQHandler);
            break;
        case(62U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch62_IRQHandler);
            break;
        case(63U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch63_IRQHandler);
            break;
        case(64U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch64_IRQHandler);
            break;
        case(65U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch65_IRQHandler);
            break;
        case(66U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch66_IRQHandler);
            break;
        case(67U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch67_IRQHandler);
            break;
        case(68U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch68_IRQHandler);
            break;
        case(69U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch69_IRQHandler);
            break;
        case(70U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch70_IRQHandler);
            break;
        case(71U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch71_IRQHandler);
            break;
        case(72U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch72_IRQHandler);
            break;
        case(73U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch73_IRQHandler);
            break;
        case(74U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch74_IRQHandler);
            break;
        case(75U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch75_IRQHandler);
            break;
        case(76U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch76_IRQHandler);
            break;
        case(77U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch77_IRQHandler);
            break;
        case(78U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch78_IRQHandler);
            break;
        case(79U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch79_IRQHandler);
            break;
        case(80U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch80_IRQHandler);
            break;
        case(81U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch81_IRQHandler);
            break;
        case(82U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch82_IRQHandler);
            break;
        case(83U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch83_IRQHandler);
            break;
        case(84U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch84_IRQHandler);
            break;
        case(85U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch85_IRQHandler);
            break;
        case(86U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch86_IRQHandler);
            break;
        case(87U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch87_IRQHandler);
            break;
        case(88U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch88_IRQHandler);
            break;
        case(89U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch89_IRQHandler);
            break;
        case(90U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch90_IRQHandler);
            break;
        case(91U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch91_IRQHandler);
            break;
        case(92U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch92_IRQHandler);
            break;
        case(93U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch93_IRQHandler);
            break;
        case(94U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch94_IRQHandler);
            break;
        case(95U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch95_IRQHandler);
            break;
        case(96U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch96_IRQHandler);
            break;
        case(97U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch97_IRQHandler);
            break;
        case(98U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch98_IRQHandler);
            break;
        case(99U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch99_IRQHandler);
            break;
        case(100U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch100_IRQHandler);
            break;
        case(101U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch101_IRQHandler);
            break;
        case(102U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch102_IRQHandler);
            break;
        case(103U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch103_IRQHandler);
            break;
        case(104U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch104_IRQHandler);
            break;
        case(105U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch105_IRQHandler);
            break;
        case(106U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch106_IRQHandler);
            break;
        case(107U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch107_IRQHandler);
            break;
        case(108U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch108_IRQHandler);
            break;
        case(109U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch109_IRQHandler);
            break;
        case(110U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch110_IRQHandler);
            break;
        case(111U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch111_IRQHandler);
            break;
        case(112U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch112_IRQHandler);
            break;
        case(113U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch113_IRQHandler);
            break;
        case(114U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch114_IRQHandler);
            break;
        case(115U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch115_IRQHandler);
            break;
        case(116U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch116_IRQHandler);
            break;
        case(117U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch117_IRQHandler);
            break;
        case(118U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch118_IRQHandler);
            break;
        case(119U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch119_IRQHandler);
            break;
        case(120U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch120_IRQHandler);
            break;
        case(121U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch121_IRQHandler);
            break;
        case(122U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch122_IRQHandler);
            break;
        case(123U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch123_IRQHandler);
            break;
        case(124U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch124_IRQHandler);
            break;
        case(125U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch125_IRQHandler);
            break;
        case(126U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch126_IRQHandler);
            break;
        case(127U):
            (void) INTC_LLD_Set_IRQ_Priority(irqNumber, INTR_PRI_1);
            (void) INTC_LLD_Set_IRQ_Handle(irqNumber, &SAF_EDMA_Ch127_IRQHandler);
            break;
        default:
            SAF_EDMA_DEV_ERR(FALSE);
            break;
    }
    (void) INTC_LLD_Set_IRQ_Enable(irqNumber);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_SwRequestTriggerEn(uint8_t mappedChannel)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_SetChnTrigStart((SafeDMAIstanceNumType)edma_instance, edma_channel);
}

SAF_DMA_SEC_CODE
status_t SAF_EDMA_LLD_SetChannelSourceConfig(uint8_t mappedChannel,
                                              uint32_t request,
                                              boolean triggerEn)
{
    SAF_EDMA_DEV_ERR(mappedChannel < (uint32_t)SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);

#ifdef SAF_DMAMUX_AVAILABLE
    uint8_t dmamux_instance = (uint8_t)SAF_DMAMUX_REQ_SRC_TO_INSTANCE(request);
    uint8_t dmamux_request = (uint8_t)SAF_DMAMUX_REQ_SRC_TO_CH(request);
    uint8_t dmamux_channel = (uint8_t)SAF_DMAMUX_SAF_DMA_CH_TO_CH(mappedChannel);

    SAF_DMAMUX_HW_SetChannelCmd((SAF_DMAMUXInstanceNumType)dmamux_instance, dmamux_channel, FALSE);
    SAF_DMAMUX_HW_SetChannelSource((SAF_DMAMUXInstanceNumType)dmamux_instance, dmamux_channel, dmamux_request);
#ifdef SAF_DMAMUX_HAS_TRIG
    SAF_DMAMUX_HW_SetChannelTrigger((SAF_DMAMUXInstanceNumType)dmamux_instance, dmamux_channel, triggerEn);
#else
    (void)triggerEn;
#endif
    SAF_DMAMUX_HW_SetChannelCmd((SAF_DMAMUXInstanceNumType)dmamux_instance, dmamux_channel, TRUE);

    return STATUS_SUCCESS;
#else
    (void)mappedChannel;
    (void)request;
    (void)triggerEn;
    return STATUS_UNSUPPORTED;
#endif
}

SAF_DMA_SEC_CODE
status_t SAF_EDMA_LLD_ChannelInit(SafeDMAChnStateType *eedma_channelState, const SafeDMAChanConfigType *eedma_channelConfig)
{
    SAF_EDMA_DEV_ERR(eedma_channelConfig != NULL);
    SAF_EDMA_DEV_ERR(eedma_channelConfig->mappedChnConfig < SAF_EDMA_TOTAL_CHANNELS);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(eedma_channelConfig->mappedChnConfig);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(eedma_channelConfig->mappedChnConfig);
    uint8_t mappedChannel = eedma_channelConfig->mappedChnConfig;

    SAF_EDMA_HW_ClearStructPtr((uint8_t *)eedma_channelState, sizeof(SafeDMAChnStateType));

    status_t retStatus = STATUS_SUCCESS;

    s_mapEdmaState->mapChnState[mappedChannel] = eedma_channelState; /* polyspace RTE:OBAI */
    s_mapEdmaState->mapChnState[mappedChannel]->mappedChn = mappedChannel;
    s_mapEdmaState->mapChnState[mappedChannel]->status = SAF_EDMA_CHN_STATUS_NORMAL; /* polyspace RTE:IDP */
    SAF_EDMA_HW_EnDisChnErrorInt((SafeDMAIstanceNumType)edma_instance, edma_channel, eedma_channelConfig->chnErrIntEn);
    retStatus = SAF_EDMA_LLD_SetChannelSourceConfig(eedma_channelConfig->mappedChnConfig, (uint32_t)eedma_channelConfig->reqSource, \
                                                eedma_channelConfig->triggerEn);
    SAF_EDMA_HW_TCDDeInit((SafeDMAIstanceNumType)edma_instance, edma_channel);

    if ((SAF_EDMA_HW_GetChnArbitrationMode((SafeDMAIstanceNumType)edma_instance) == SAF_EDMA_ARBITRATION_MODE_FIXED_PRIORITY) &&
        (eedma_channelConfig->chnPrioSet != SAF_EDMA_CHN_PRIORITY_DEFALUT))
    {
        SAF_EDMA_HW_SetChnPri((SafeDMAIstanceNumType)edma_instance, edma_channel, eedma_channelConfig->chnPrioSet);
    }
  /* zxy   : config Irq (DMA 63) in the os. */
    // SAF_EDMA_HW_IrqInstall(eedma_channelConfig->mappedChnConfig);
    (void) SAF_EDMA_LLD_SetUpCallback(eedma_channelConfig->mappedChnConfig, eedma_channelConfig->callback, eedma_channelConfig->callbackParam);

    return retStatus;
}

SAF_DMA_SEC_CODE
status_t SAF_EDMA_LLD_ModuleInit(safedma_state_t *edmaState,
                       const SafeDMAModuleConfigType *userConfig,
                       SafeDMAChnStateType * const chnStateArray[],
                       const SafeDMAChanConfigType * const chnConfigArray[],
                       uint32_t chnCount)
{
    uint32_t index = 0U;
    uint8_t edma_instance = 0U;
    status_t edmaStatus = STATUS_SUCCESS;
    status_t chnInitStatus = STATUS_SUCCESS;

    DEV_ASSERT((edmaState != NULL) && (userConfig != NULL));
    DEV_ASSERT(s_mapEdmaState == NULL);

    s_mapEdmaState = edmaState; /* PRQA S 2919 */
    SAF_EDMA_HW_ClearStructPtr((uint8_t *)s_mapEdmaState, sizeof(safedma_state_t));

    for (index = 0U; index < (uint32_t)SAF_EDMA_INSTANCE_COUNT; index++)
    {
        edma_instance = (uint8_t)index;

        SAF_EDMA_HW_Init((SafeDMAIstanceNumType)edma_instance);
        SAF_EDMA_HW_SetChnArbitrationMode((SafeDMAIstanceNumType)edma_instance, userConfig->setChnArbitMode);
        SAF_EDMA_HW_EnDisHaltOnError((SafeDMAIstanceNumType)edma_instance, userConfig->haltOnError);
    }
/* zxy */  
#if 0
     (void) INTC_LLD_Set_IRQ_Priority(DMA0_ERR0_127_IRQn, INTR_PRI_1);
     (void) INTC_LLD_Set_IRQ_Handle(DMA0_ERR0_127_IRQn, &SAF_EDMA_Ch0_Ch127_Error_IRQHandler);
     (void) INTC_LLD_Set_IRQ_Enable(DMA0_ERR0_127_IRQn);
#endif

#ifdef SAF_DMAMUX_AVAILABLE
    for (index = 0U; index < (uint32_t)SAF_DMAMUX_INSTANCE_COUNT; index++)
    {
        SAF_DMAMUX_HW_Init((SAF_DMAMUXInstanceNumType)index);
    }
#endif
    if ((chnStateArray != NULL) && (chnConfigArray != NULL))
    {
        for (index = 0U; index < chnCount; index++)
        {
            chnInitStatus = SAF_EDMA_LLD_ChannelInit(chnStateArray[index], chnConfigArray[index]); /* polyspace RTE:IDP */
            if (chnInitStatus != STATUS_SUCCESS)
            {
                edmaStatus = chnInitStatus;
            }
        }
    }

    return edmaStatus;
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_ClearSwTCDStruct(SafeDMASwTcdType *swtcd)
{
    SAF_EDMA_HW_ClearStructPtr((uint8_t *)swtcd, sizeof(SafeDMASwTcdType));
}

SAF_DMA_SEC_CODE
static void SAF_EDMA_LLD_IRQHandler(uint8_t mappedChannel)
{
    const SafeDMAChnStateType *chnState = s_mapEdmaState->mapChnState[mappedChannel]; /* polyspace RTE:IDP */

    SAF_EDMA_HW_ClearIntStatus(mappedChannel);

    if (chnState != NULL)
    {
        if (chnState->callback != NULL)  /* polyspace RTE:NIP,IDP */
        {
            chnState->callback(chnState->parameter, chnState->status); /* polyspace RTE:NIV,NIP,COR */
        }
    }

}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_ErrorIRQHandler(uint8_t mappedChannel)
{
    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);
    SAF_EDMA_HW_EnDisChnErrorInt((SafeDMAIstanceNumType)edma_instance, edma_channel, FALSE);
    SafeDMAChnStateType *chnState = s_mapEdmaState->mapChnState[mappedChannel]; /* polyspace RTE:IDP */
    if (chnState != NULL)
    {
        SAF_EDMA_HW_ClearIntStatus(mappedChannel);
        SAF_EDMA_HW_ClearChnErrorIntFlag((SafeDMAIstanceNumType)edma_instance, edma_channel);
        chnState->status = SAF_EDMA_CHN_STATUS_ERROR; /* polyspace RTE:IDP */
        if (chnState->callback != NULL) /* polyspace RTE:NIP */
        {
            chnState->callback(chnState->parameter, chnState->status); /* polyspace RTE:NIP,COR */
        }
    }
}

SAF_DMA_SEC_CODE
status_t SAF_EDMA_LLD_SetSingleTransferConfig(uint8_t mappedChannel, /* PRQA S 2755 */
                                          SafeDMATransferType type,
                                          uint32_t srcAddr,
                                          uint32_t destAddr,
                                          SafeDMATransferSizeType transferSize,
                                          uint32_t dataBufferSize)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);
    uint8_t transferOffset;
    status_t retStatus = STATUS_SUCCESS;

    transferOffset = (uint8_t) (1U << ((uint8_t)transferSize));
    SAF_EDMA_DEV_ERR((srcAddr % transferOffset) == 0U);
    SAF_EDMA_DEV_ERR((destAddr % transferOffset) == 0U);

    if ((dataBufferSize % transferOffset) != 0U)/*PRQA S 2834*/
    {
        retStatus = STATUS_ERROR;
    }

    if (retStatus == STATUS_SUCCESS)
    {
        SAF_EDMA_HW_TCDDeInit((SafeDMAIstanceNumType)edma_instance, edma_channel);
        SAF_EDMA_HW_EnDisMinorLoopMapping((SafeDMAIstanceNumType)edma_instance, TRUE);
        SAF_EDMA_HW_TCDSetSrcAddr((SafeDMAIstanceNumType)edma_instance, edma_channel, srcAddr);
        SAF_EDMA_HW_TCDSetDestAddr((SafeDMAIstanceNumType)edma_instance, edma_channel, destAddr);
        SAF_EDMA_HW_TCDSetTransferAttribute((SafeDMAIstanceNumType)edma_instance, edma_channel, SAF_EDMA_ADDRESS_MODULO_OFF, \
                                        SAF_EDMA_ADDRESS_MODULO_OFF, transferSize, transferSize);

        switch (type)
        {
            case SAF_EDMA_TRANSFER_TYPE_PERIPHTOMEM:
                SAF_EDMA_HW_TCDSetSrcAddrOffset((SafeDMAIstanceNumType)edma_instance, edma_channel, 0);
                SAF_EDMA_HW_TCDSetDestAddrOffset((SafeDMAIstanceNumType)edma_instance, edma_channel, (int8_t) transferOffset);
                break;
            case SAF_EDMA_TRANSFER_TYPE_MEMTOPERIPH:
                SAF_EDMA_HW_TCDSetSrcAddrOffset((SafeDMAIstanceNumType)edma_instance, edma_channel, (int8_t) transferOffset);
                SAF_EDMA_HW_TCDSetDestAddrOffset((SafeDMAIstanceNumType)edma_instance, edma_channel, 0);
                break;
            case SAF_EDMA_TRANSFER_TYPE_MEMTOMEM:
                SAF_EDMA_HW_TCDSetSrcAddrOffset((SafeDMAIstanceNumType)edma_instance, edma_channel, (int8_t) transferOffset);
                SAF_EDMA_HW_TCDSetDestAddrOffset((SafeDMAIstanceNumType)edma_instance, edma_channel, (int8_t) transferOffset);
                break;
            case SAF_EDMA_TRANSFER_TYPE_PERIPHTOPERIPH:
                SAF_EDMA_HW_TCDSetSrcAddrOffset((SafeDMAIstanceNumType)edma_instance, edma_channel, 0);
                SAF_EDMA_HW_TCDSetDestAddrOffset((SafeDMAIstanceNumType)edma_instance, edma_channel, 0);
                break;
            default:
                SAF_EDMA_DEV_ERR(FALSE);
                break;
        }

        SAF_EDMA_HW_TCDSetMinorByteCount((SafeDMAIstanceNumType)edma_instance, edma_channel, dataBufferSize);
        SAF_EDMA_HW_TCDSetMajorCount((SafeDMAIstanceNumType)edma_instance, edma_channel, 1U);
        SAF_EDMA_HW_TCDSetMajorCompleteIntCmd((SafeDMAIstanceNumType)edma_instance, edma_channel, TRUE);
        s_mapEdmaState->mapChnState[mappedChannel]->status = SAF_EDMA_CHN_STATUS_NORMAL;  /* polyspace RTE:IDP */
    }

    return retStatus;
}

SAF_DMA_SEC_CODE
status_t SAF_EDMA_LLD_SetMultiTransferConfig(uint8_t mappedChannel,
                                         SafeDMATransferType type,
                                         uint32_t srcAddr,
                                         uint32_t destAddr,
                                         SafeDMATransferSizeType transferSize,
                                         uint32_t blockSize,
                                         uint32_t blockCount,
                                         boolean disableReqOnCompletion)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);
    status_t retStatus = STATUS_SUCCESS;

    retStatus = SAF_EDMA_LLD_SetSingleTransferConfig(mappedChannel, type, srcAddr, destAddr, transferSize, blockSize);

    if (retStatus == STATUS_SUCCESS)
    {
        SAF_EDMA_HW_TCDSetMajorCount((SafeDMAIstanceNumType)edma_instance, edma_channel, blockCount);
        SAF_EDMA_HW_TCDSetDisableDmaRequestAfterTCDDoneCmd((SafeDMAIstanceNumType)edma_instance, edma_channel, disableReqOnCompletion);
    }

    return retStatus;
}

SAF_DMA_SEC_CODE
status_t SAF_EDMA_LLD_SetLoopTransferConfig(uint8_t mappedChannel,
                                     const SafeDMATransferConfigType *transferConfig)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);
    SAF_EDMA_DEV_ERR(transferConfig != NULL);
    SAF_EDMA_DEV_ERR(transferConfig->lpTransConfigPtr != NULL);
    SAF_EDMA_DEV_ERR((transferConfig->srcAddrModulo == SAF_EDMA_ADDRESS_MODULO_OFF) ||
               ((transferConfig->srcAddr % (((uint32_t)1U) << (uint32_t)transferConfig->srcAddrModulo)) == 0U));
    SAF_EDMA_DEV_ERR((transferConfig->destAddrModulo == SAF_EDMA_ADDRESS_MODULO_OFF) ||
               ((transferConfig->destAddr % (((uint32_t)1U) << (uint32_t)transferConfig->destAddrModulo)) == 0U));

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);

    SAF_EDMA_HW_EnDisMinorLoopMapping((SafeDMAIstanceNumType)edma_instance, TRUE);
    SAF_EDMA_HW_PushConfigToReg(mappedChannel, transferConfig);
    s_mapEdmaState->mapChnState[mappedChannel]->status = SAF_EDMA_CHN_STATUS_NORMAL; /* polyspace RTE:IDP */

    return STATUS_SUCCESS;
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_CopyConfigToSwTCD(const SafeDMATransferConfigType *config,
                                SafeDMASwTcdType *stcd)
{
    if ((config != NULL) && (stcd != NULL))
    {
        SAF_EDMA_LLD_ClearSwTCDStruct(stcd);

        stcd->ATTR = (uint16_t)(SAF_DMA_TCD_ATTR_SMOD(config->srcAddrModulo) | SAF_DMA_TCD_ATTR_SSIZE(config->srcTransDataSize) | SAF_DMA_TCD_ATTR_DMOD(config->destAddrModulo) | SAF_DMA_TCD_ATTR_DSIZE(config->destTransDataSize)); /* PRQA S 2985 */ /* polyspace RTE:IDP */
        stcd->SADDR = config->srcAddr;
        stcd->SOFF = config->srcAddrOffset;
        stcd->NBYTES = config->minorTransByte;
        stcd->SLAST = config->srcAddrAdjustLast;
        stcd->DADDR = config->destAddr;
        stcd->DOFF = config->destAddrOffset;
        stcd->CITER = (uint16_t) config->lpTransConfigPtr->majorLpIterCnt;/* polyspace RTE:NIV,IDP */
        if (config->featureScatterGatherEn == TRUE)
        {
            stcd->DLAST_SGA = (int32_t) config->featureScatterGatherNextDescriptor;
        }
        else
        {
            stcd->DLAST_SGA = config->destAddrAdjustLast;
        }

        stcd->CSR = (((uint16_t)((config->completeIntEn == TRUE) ? 1U : 0U) << SAF_DMA_TCD_CSR_INTMAJOR_SHIFT) | \
                     ((uint16_t)((config->featureScatterGatherEn == TRUE) ? 1U : 0U) << SAF_DMA_TCD_CSR_ESG_SHIFT));
        stcd->BITER = (uint16_t) config->lpTransConfigPtr->majorLpIterCnt;
    }
}

SAF_DMA_SEC_CODE
status_t SAF_EDMA_LLD_SetScatterGatherTransferConfig(uint8_t mappedChannel,
                                                 const SafeDMASwTcdType *stcd,
                                                 SafeDMATransferSizeType transferSize,
                                                 uint32_t bytesOnEachRequest,
                                                 const SafeDMAScatterGatherListType *srcList,
                                                 const SafeDMAScatterGatherListType *destList,
                                                 uint8_t tcdCount)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);
    SAF_EDMA_DEV_ERR((stcd != NULL) && (srcList != NULL) && (destList != NULL));

    uint8_t i = 0U;
    uint16_t transferOffset = 0U;
    uint32_t stcdAlignedAddr = SAF_TCD_ADDR_CALC(stcd);
    SafeDMASwTcdType *edmaSwTcdAddr = (SafeDMASwTcdType *)stcdAlignedAddr;
    SafeDMALoopTransferConfigType edmaLoopConfig;
    SafeDMATransferConfigType edmaTransferConfig;
    status_t retStatus = STATUS_SUCCESS;

    s_mapEdmaState->mapChnState[mappedChannel]->status = SAF_EDMA_CHN_STATUS_NORMAL; /* polyspace RTE:IDP,OBAI */

    transferOffset = (uint16_t) (1UL << ((uint16_t)transferSize));

    if ((bytesOnEachRequest % transferOffset) != 0U)/*PRQA S 2834*/
    {
        retStatus = STATUS_ERROR;
    }

    SAF_EDMA_HW_ClearStructPtr((uint8_t *)(&edmaTransferConfig), sizeof(SafeDMATransferConfigType));
    SAF_EDMA_HW_ClearStructPtr((uint8_t *)(&edmaLoopConfig), sizeof(SafeDMALoopTransferConfigType));

    edmaTransferConfig.srcAddrAdjustLast = 0;
    edmaTransferConfig.destAddrAdjustLast = 0;
    edmaTransferConfig.srcAddrModulo = SAF_EDMA_ADDRESS_MODULO_OFF;
    edmaTransferConfig.destAddrModulo = SAF_EDMA_ADDRESS_MODULO_OFF;
    edmaTransferConfig.srcTransDataSize = transferSize;
    edmaTransferConfig.destTransDataSize = transferSize;
    edmaTransferConfig.minorTransByte = bytesOnEachRequest;
    edmaTransferConfig.completeIntEn = TRUE;
    edmaTransferConfig.featureScatterGatherEn = TRUE;
    edmaTransferConfig.lpTransConfigPtr = &edmaLoopConfig;
    edmaTransferConfig.lpTransConfigPtr->srcAddrOffsetEn = FALSE;
    edmaTransferConfig.lpTransConfigPtr->dstAddrOffsetEn = FALSE;
    edmaTransferConfig.lpTransConfigPtr->minorLpLinkEn = FALSE;
    edmaTransferConfig.lpTransConfigPtr->majorLpLinkEn = FALSE;
    edmaTransferConfig.srcAddrOffset = 0;
    edmaTransferConfig.destAddrOffset = 0;

    for (i = 0U; (i < tcdCount) && (retStatus == STATUS_SUCCESS); i++)
    {
        edmaTransferConfig.srcAddr = srcList[i].address;
        edmaTransferConfig.destAddr = destList[i].address;
        if ((srcList[i].length != destList[i].length) || (srcList[i].type != destList[i].type))
        {
            break;
        }
        edmaTransferConfig.lpTransConfigPtr->majorLpIterCnt = srcList[i].length/bytesOnEachRequest;/*PRQA S 2834*/ /* polyspace RTE:ZDV */

        switch (srcList[i].type)
        {
            case SAF_EDMA_TRANSFER_TYPE_PERIPHTOMEM:
                edmaTransferConfig.srcAddrOffset = 0;
                edmaTransferConfig.destAddrOffset = (int16_t) transferOffset;
                break;
            case SAF_EDMA_TRANSFER_TYPE_MEMTOPERIPH:
                edmaTransferConfig.srcAddrOffset = (int16_t) transferOffset;
                edmaTransferConfig.destAddrOffset = 0;
                break;
            case SAF_EDMA_TRANSFER_TYPE_MEMTOMEM:
                edmaTransferConfig.srcAddrOffset = (int16_t) transferOffset;
                edmaTransferConfig.destAddrOffset = (int16_t) transferOffset;
                break;
            case SAF_EDMA_TRANSFER_TYPE_PERIPHTOPERIPH:
                edmaTransferConfig.srcAddrOffset = 0;
                edmaTransferConfig.destAddrOffset = 0;
                break;
            default:
                SAF_EDMA_DEV_ERR(FALSE);
                break;
        }

        if (i == ((uint8_t)(tcdCount - 1U)))
        {
            edmaTransferConfig.featureScatterGatherNextDescriptor = 0U;
        }
        else
        {
            const SafeDMASwTcdType * ptNextAddr = &edmaSwTcdAddr[i];
            edmaTransferConfig.featureScatterGatherNextDescriptor = ((uint32_t) ptNextAddr);
        }

        if (i == 0U)
        {
            SAF_EDMA_HW_PushConfigToReg(mappedChannel, &edmaTransferConfig);
        }
        else
        {
            SAF_EDMA_LLD_CopyConfigToSwTCD(&edmaTransferConfig, &edmaSwTcdAddr[i - 1U]);
        }
    }

    return retStatus;
}

SAF_DMA_SEC_CODE
status_t SAF_EDMA_LLD_SetChannelRequest(uint8_t mappedChannel)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_EnDisChnDmaReq((SafeDMAIstanceNumType)edma_instance, edma_channel, TRUE);

    return STATUS_SUCCESS;
}

SAF_DMA_SEC_CODE
status_t SAF_EDMA_LLD_ClearChannelRequest(uint8_t mappedChannel)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_EnDisChnDmaReq((SafeDMAIstanceNumType)edma_instance, edma_channel, FALSE);

    return STATUS_SUCCESS;
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_ClearHwTCD(uint8_t mappedChannel)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_TCDDeInit((SafeDMAIstanceNumType)edma_instance, edma_channel);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_SetChnSrcAddr(uint8_t mappedChannel,
                            uint32_t address)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_TCDSetSrcAddr((SafeDMAIstanceNumType)edma_instance, edma_channel, address);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_SetChnSrcAddrOffset(uint8_t mappedChannel,
                                  int16_t offset)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_TCDSetSrcAddrOffset((SafeDMAIstanceNumType)edma_instance, edma_channel, offset);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_SetChnSrcAddrReadTransferSize(uint8_t mappedChannel,
                                            SafeDMATransferSizeType size)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_TCDSetSrcDataTransferSize((SafeDMAIstanceNumType)edma_instance, edma_channel, size);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_SetChnSrcAddrLastAdjustment(uint8_t mappedChannel,
                                          int32_t adjust)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_TCDSetSrcLastAdjust((SafeDMAIstanceNumType)edma_instance, edma_channel, adjust);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_SetChnDestAddrLastAdjustment(uint8_t mappedChannel,
                                           int32_t adjust)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_TCDSetDestLastAdjust((SafeDMAIstanceNumType)edma_instance, edma_channel, adjust);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_SetChnDestAddr(uint8_t mappedChannel,
                             uint32_t address)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_TCDSetDestAddr((SafeDMAIstanceNumType)edma_instance, edma_channel, address);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_SetChnDestAddrOffset(uint8_t mappedChannel,
                                   int16_t offset)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_TCDSetDestAddrOffset((SafeDMAIstanceNumType)edma_instance, edma_channel, offset);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_SetChnDestdrWriteTransferSize(uint8_t mappedChannel,
                                            SafeDMATransferSizeType size)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_TCDSetDestDataTransferSize((SafeDMAIstanceNumType)edma_instance, edma_channel, size);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_SetChnMinorLpTransferByte(uint8_t mappedChannel,
                                        uint32_t nbytes)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);
    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_TCDSetMinorByteCount((SafeDMAIstanceNumType)edma_instance, edma_channel, nbytes);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_SetChnMajorLpIterationCount(uint8_t mappedChannel,
                                          uint32_t majorLoopCount)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_TCDSetMajorCount((SafeDMAIstanceNumType)edma_instance, edma_channel, majorLoopCount);
}

SAF_DMA_SEC_CODE
uint32_t SAF_EDMA_LLD_GetChnRemainingIterationsCount(uint8_t mappedChannel)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    uint32_t count = SAF_EDMA_HW_TCDGetCurrentMajorCount((SafeDMAIstanceNumType)edma_instance, edma_channel);

    return count;
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_SetChnScatterGatherLinkMode(uint8_t mappedChannel,
                                          uint32_t nextTCDAddr)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_TCDSetScatterGatherLink((SafeDMAIstanceNumType)edma_instance, edma_channel, nextTCDAddr);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_SetChnDisRequestsOnTransferComplete(uint8_t mappedChannel,
                                                  boolean disable)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_TCDSetDisableDmaRequestAfterTCDDoneCmd((SafeDMAIstanceNumType)edma_instance, edma_channel, disable);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_SetInterruptConfig(uint8_t mappedChannel,
                                 SafeDMAChannelInterruptType intSrc,
                                 boolean enable)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    switch (intSrc)
    {
        case SAF_EDMA_CHN_ENABLE_ERROR_INT:
            SAF_EDMA_HW_EnDisChnErrorInt((SafeDMAIstanceNumType)edma_instance, edma_channel, enable);
            break;
        case SAF_EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT:
            SAF_EDMA_HW_TCDSetMajorHalfCompleteIntCmd((SafeDMAIstanceNumType)edma_instance, edma_channel, enable);
            break;
        case SAF_EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT:
            SAF_EDMA_HW_TCDSetMajorCompleteIntCmd((SafeDMAIstanceNumType)edma_instance, edma_channel, enable);
            break;
        default:
            SAF_EDMA_DEV_ERR(FALSE);
            break;
    }
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_CancelExcutingChnTransfer(boolean error)
{
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);

    uint32_t edma_instance = 0U;

    for (edma_instance = 0U; edma_instance < (uint32_t)SAF_EDMA_INSTANCE_COUNT; edma_instance++)
    {
        if (error == TRUE)
        {
            SAF_EDMA_HW_CancelExecChnTransferWithError((SafeDMAIstanceNumType)edma_instance);
        }
        else
        {
            SAF_EDMA_HW_CancelExecChnTransfer((SafeDMAIstanceNumType)edma_instance);
        }
    }
}

SAF_DMA_SEC_CODE
void SAF_EDMA_LLD_WaitChnTransferDone(uint8_t mappedChannel)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);

    uint8_t edma_instance = (uint8_t)SAF_EDMA_MCH_TO_INSTANCE(mappedChannel);
    uint8_t edma_channel = (uint8_t)SAF_EDMA_MCH_TO_CH(mappedChannel);

    SAF_EDMA_HW_WaitChnTransferDoneFlag((SafeDMAIstanceNumType)edma_instance, edma_channel);
    SAF_EDMA_HW_ClearChnTransferDoneFlag((SafeDMAIstanceNumType)edma_instance, edma_channel);
}

SAF_DMA_SEC_CODE
SafeDMAChnStatusType SAF_EDMA_LLD_GetChnConfigStatus(uint8_t mappedChannel)
{
    SAF_EDMA_DEV_ERR(mappedChannel < SAF_EDMA_MAPPED_CHANNELS);
    SAF_EDMA_DEV_ERR(s_mapEdmaState != NULL);
    SAF_EDMA_DEV_ERR(s_mapEdmaState->mapChnState[mappedChannel] != NULL);

    return s_mapEdmaState->mapChnState[mappedChannel]->status; /* PRQA S 0404 */ /* polyspace RTE:NIV,IDP,OBAI */
}

#if SAF_EDMA_CH0_CH127_ERROR_INT
SAF_DMA_SEC_CODE
void SAF_EDMA_Ch0_Ch127_Error_IRQHandler(void)
{
    uint8_t mappedChannel = 0U;
    SafeDMAErrorRegisterType errStatus;
    SAF_EDMA_HW_GetChnErrorIntFlag(SAF_EDMA_INSTANCE_0, &errStatus);
    if (0U != (errStatus.errl))
    {
        for (mappedChannel  = 0U; mappedChannel <= 31U; mappedChannel++)
        {
            if ((errStatus.errl & 1U) != 0U)
            {
                SAF_EDMA_LLD_ErrorIRQHandler(mappedChannel);
            }
            errStatus.errl = errStatus.errl >> 1U;
        }
    }
    if (0U != (errStatus.errh))
    {
        for (mappedChannel  = 32U; mappedChannel <= 63U; mappedChannel++)
        {
            if ((errStatus.errh & 1U) != 0U)
            {
                SAF_EDMA_LLD_ErrorIRQHandler(mappedChannel);
            }
            errStatus.errh = errStatus.errh >> 1U;
        }
    }
    errStatus.errl = 0U;
    errStatus.errh = 0U;
    SAF_EDMA_HW_GetChnErrorIntFlag(SAF_EDMA_INSTANCE_1, &errStatus);
    if (0U != (errStatus.errl))
    {
        for (mappedChannel  = 64U; mappedChannel <= 95U; mappedChannel++)
        {
            if ((errStatus.errl & 1U) != 0U)
            {
                SAF_EDMA_LLD_ErrorIRQHandler(mappedChannel);
            }
            errStatus.errl = errStatus.errl >> 1U;
        }
    }
    if (0U != (errStatus.errh))
    {
        for (mappedChannel  = 96U; mappedChannel <= 127U; mappedChannel++)
        {
            if ((errStatus.errh & 1U) != 0U)
            {
                SAF_EDMA_LLD_ErrorIRQHandler(mappedChannel);
            }
            errStatus.errh = errStatus.errh >> 1U;
        }
    }
}
#endif

#if SAF_EDMA_CH0_CH127_INT
SAF_DMA_SEC_CODE
void SAF_EDMA_Ch0_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(0U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch1_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(1U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch2_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(2U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch3_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(3U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch4_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(4U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch5_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(5U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch6_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(6U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch7_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(7U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch8_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(8U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch9_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(9U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch10_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(10U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch11_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(11U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch12_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(12U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch13_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(13U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch14_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(14U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch15_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(15U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch16_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(16U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch17_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(17U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch18_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(18U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch19_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(19U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch20_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(20U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch21_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(21U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch22_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(22U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch23_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(23U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch24_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(24U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch25_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(25U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch26_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(26U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch27_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(27U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch28_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(28U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch29_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(29U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch30_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(30U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch31_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(31U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch32_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(32U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch33_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(33U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch34_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(34U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch35_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(35U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch36_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(36U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch37_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(37U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch38_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(38U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch39_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(39U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch40_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(40U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch41_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(41U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch42_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(42U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch43_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(43U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch44_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(44U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch45_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(45U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch46_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(46U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch47_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(47U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch48_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(48U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch49_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(49U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch50_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(50U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch51_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(51U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch52_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(52U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch53_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(53U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch54_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(54U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch55_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(55U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch56_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(56U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch57_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(57U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch58_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(58U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch59_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(59U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch60_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(60U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch61_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(61U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch62_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(62U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch63_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(63U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch64_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(64U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch65_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(65U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch66_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(66U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch67_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(67U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch68_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(68U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch69_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(69U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch70_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(70U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch71_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(71U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch72_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(72U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch73_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(73U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch74_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(74U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch75_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(75U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch76_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(76U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch77_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(77U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch78_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(78U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch79_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(79U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch80_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(80U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch81_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(81U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch82_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(82U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch83_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(83U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch84_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(84U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch85_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(85U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch86_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(86U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch87_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(87U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch88_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(88U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch89_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(89U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch90_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(90U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch91_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(91U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch92_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(92U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch93_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(93U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch94_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(94U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch95_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(95U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch96_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(96U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch97_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(97U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch98_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(98U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch99_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(99U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch100_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(100U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch101_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(101U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch102_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(102U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch103_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(103U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch104_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(104U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch105_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(105U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch106_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(106U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch107_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(107U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch108_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(108U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch109_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(109U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch110_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(110U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch111_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(111U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch112_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(112U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch113_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(113U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch114_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(114U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch115_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(115U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch116_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(116U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch117_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(117U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch118_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(118U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch119_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(119U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch120_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(120U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch121_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(121U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch122_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(122U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch123_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(123U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch124_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(124U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch125_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(125U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch126_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(126U);
}

SAF_DMA_SEC_CODE
void SAF_EDMA_Ch127_IRQHandler(void)
{
    SAF_EDMA_LLD_IRQHandler(127U);
}
#endif


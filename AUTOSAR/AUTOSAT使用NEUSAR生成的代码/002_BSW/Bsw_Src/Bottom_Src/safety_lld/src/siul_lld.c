/****************************************************************************
*
* Copyright (c) 2024  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx SIUL low level drivers code
* HISTORY     : Initial version
* @file     siul_lld.c
* @version  1.0
* @date     2024 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/

#include "siul_lld.h"/* PRQA S 0380 */
#include "Saf_MemMap.h"
#ifdef RESOURCE_SUPPORT_SIUL_IP
/* PRQA S 1503 EOF */
/************************************************************************
 *    MCU ID Register #1 (MIDR1)
 ************************************************************************/
/* @brief SIUL MCU ID Register #1.
 * @return
 * */
SAF_SEC_CODE
uint32_t SIUL_LLD_GetMIDR1(void)
{
    return (uint32_t)(SIUL.MIDR1.R);
}

/* @brief SIUL MCU ID Register #1, MCU Part Number(lower 16 bits) read.
 * @return
 * */
SAF_SEC_CODE
uint16_t SIUL_LLD_GetMIDR1_PartNum_0_15(void)
{
    return (uint16_t)((SIUL.MIDR1.R & SIUL_MIDR1_PARTNUM_MASK) >> SIUL_MIDR1_PARTNUM_SHIFT);
}

/* @brief SIUL  MCU ID Register #1, Package Settings read.
 * @return
 * */
SAF_SEC_CODE
uint8_t SIUL_LLD_GetMIDR1_PackSet(void)
{
    return (uint8_t)((SIUL.MIDR1.R & SIUL_MIDR1_PKG_MASK) >> SIUL_MIDR1_PKG_SHIFT);
}

/* @brief SIUL  MCU ID Register #1, Major Mask Revision read.
 * @return Major Mask Revision
 * */
SAF_SEC_CODE
uint8_t SIUL_LLD_GetMIDR1_MajorMask(void)
{
    return (uint8_t)((SIUL.MIDR1.R & SIUL_MIDR1_MAJOR_MASK) >> SIUL_MIDR1_MAJOR_SHIFT);
}

/* @brief SIUL  MCU ID Register #1, Minor Mask Revision read.
 * @return Minor Mask Revision
 * */
SAF_SEC_CODE
uint8_t SIUL_LLD_GetMIDR1_MinorMask(void)
{
    return (uint8_t)((SIUL.MIDR1.R & SIUL_MIDR1_MINOR_MASK) >> SIUL_MIDR1_MINOR_SHIFT);
}

/************************************************************************
 *    MCU ID Register #2 (MIDR2)
 ************************************************************************/
/* @brief SIUL MCU ID Register #2.
 * @return
 * */
SAF_SEC_CODE
uint32_t SIUL_LLD_GetMIDR2(void)
{
    return (uint32_t)(SIUL.MIDR2.R);
}

/* @brief SIUL MCU ID Register #2, Manufacturer read.
 * @return
 * */
SAF_SEC_CODE
uint8_t SIUL_LLD_GetMIDR2_Manufacturer(void)
{
    return (uint8_t)((SIUL.MIDR2.R & SIUL_MIDR2_SF_MASK) >> SIUL_MIDR2_SF_SHIFT);
}

/* @brief SIUL MCU ID Register #2, Flash memory 1 size read.
 * @return
 * */
SAF_SEC_CODE
uint8_t SIUL_LLD_GetMIDR2_FlashSize1(void)
{
    return (uint8_t)((SIUL.MIDR2.R & SIUL_MIDR2_FLASHSIZE1_MASK) >> SIUL_MIDR2_FLASHSIZE1_SHIFT);
}

/* @brief SIUL MCU ID Register #2, Flash memory 2 size read.
 * @return
 * */
SAF_SEC_CODE
uint8_t SIUL_LLD_GetMIDR2_FlashSize2(void)
{
    return (uint8_t)((SIUL.MIDR2.R & SIUL_MIDR2_FLASHSIZE2_MASK) >> SIUL_MIDR2_FLASHSIZE2_SHIFT);
}

/* @brief SIUL MCU ID Register #2, MCU Part Number(upper 8 bits) read.
 * @return
 * */
SAF_SEC_CODE
uint8_t SIUL_LLD_GetMIDR2_PartNum_16_23(void)
{
    return (uint8_t)((SIUL.MIDR2.R & SIUL_MIDR2_PARTNUM_MASK) >> SIUL_MIDR2_PARTNUM_SHIFT);
}

/* @brief SIUL  MCU ID Register #2, Data Flash present read.
 * @return
 * */
SAF_SEC_CODE
uint8_t SIUL_LLD_GetMIDR2_DataFlash(void)
{
    return (uint8_t)((SIUL.MIDR2.R & SIUL_MIDR2_EE_MASK) >> SIUL_MIDR2_EE_SHIFT);
}

/************************************************************************
 *    Interrupt Status Flag Register (ISR)
 ************************************************************************/
/* @brief ISR, Clear External Interrupt Status Flag x.
 * @param eifNum
 * */
SAF_SEC_CODE
void SIUL_LLD_EXTI_Clear_Flag(const uint32_t eifNum)
{
    SIUL.ISR.R = eifNum;
}

/* @brief ISR, Read External Interrupt Status Flag x.
 * @return
 * */
SAF_SEC_CODE
uint32_t SIUL_LLD_EXTI_Get_Flag(void)
{
    return (uint32_t)(SIUL.ISR.R);
}

/************************************************************************
 *     Interrupt Request Enable Register (IRER)
 ************************************************************************/
/* @brief IRER, External Interrupt Request Enable.
 * @param ireNum
 * */
SAF_SEC_CODE
void SIUL_LLD_SetExtIntReqEn(const uint32_t ireNum)
{
    SIUL.IRER.R = ireNum;
}

SAF_SEC_CODE
uint32_t SIUL_LLD_GetExtIntReqEn(void)
{
    return (uint32_t)(SIUL.IRER.R);
}

/************************************************************************
 *     Interrupt Rising-Edge Event Enable Register (IREER)
 ************************************************************************/
/* @brief IREER, Enable rising-edge events.
 * @param ireeNum
 * */
SAF_SEC_CODE
void SIUL_LLD_SetIntRisingEventEn(const uint32_t ireeNum)
{
    SIUL.IREER.R = ireeNum;
}

SAF_SEC_CODE
uint32_t SIUL_LLD_GetIntRisingEventEn(void)
{
    return (uint32_t)(SIUL.IREER.R);
}

/************************************************************************
 *     Interrupt Falling-Edge Event Enable Register (IFEER)
 ************************************************************************/
/* @brief IFEER, Enable falling-edge events.
 * @param ifeeNum
 * */
SAF_SEC_CODE
void SIUL_LLD_SetIntFallingEventEn(const uint32_t ifeeNum)
{
    SIUL.IFEER.R = ifeeNum;
}

SAF_SEC_CODE
uint32_t SIUL_LLD_GetIntFallingEventEn(void)
{
    return (uint32_t)(SIUL.IFEER.R);
}

/************************************************************************
 *     Interrupt Filter Enable Register (IFER)
 ************************************************************************/
/* @brief IFER, Enable digital glitch filter on the interrupt pad input.
 * @param ifeNum: IFER_IFE_Type
 * */
SAF_SEC_CODE
void SIUL_LLD_SetIntFilterEn(const uint32_t ifeNum)
{
    SIUL.IFER.R = ifeNum;
}

SAF_SEC_CODE
uint32_t SIUL_LLD_GetIntFilterEn(void)
{
    return (uint32_t)(SIUL.IFER.R);
}

/************************************************************************
 *    Pad Configuration Registers (PCR0-PCR335)
 ************************************************************************/
/* @brief SIUL PCR Init.
 * @param pcr_num: PCR_Pin_Type, 0~335 (Spec: Functional port pins)
 *        padType
 * */
SAF_SEC_CODE
void SIUL_LLD_SetPadConfig(const uint16_t pcrNum, const uint16_t padType)
{
    SIUL.PCR[pcrNum].R = padType;/* polyspace RTE:OBAI */
}

SAF_SEC_CODE
uint16_t SIUL_LLD_GetPadConfig(const uint16_t pcrNum)
{
    return (uint16_t)(SIUL.PCR[pcrNum].R);/* polyspace RTE:OBAI */
}

/************************************************************************
 *    Pad Selection for Multiplexed Inputs Registers(PSMI0_3-PSMI136_139)
 ************************************************************************/
/* @brief PSMI, Pad Selection Bits
 *        Each PADSEL field selects the pad currently used for a certain
 *          input function.
 * @param padSelNum:
 *        padSel:
 * */
SAF_SEC_CODE
void SIUL_LLD_SetPadSelMultInput(const uint16_t padSelNum, const uint8_t padSel)
{
    SIUL.PSMI[padSelNum].R = (uint8_t)(padSel & SIUL_PSMI_U8_PADSEL_MASK);/* polyspace RTE:OBAI */
}

SAF_SEC_CODE
uint8_t SIUL_LLD_GetPadSelMultInput(const uint16_t padSelNum)
{
    return (uint8_t)(SIUL.PSMI[padSelNum].R);/* polyspace RTE:OBAI */
}

/************************************************************************
 *     GPIO Pad Data Output Registers (GPDO0_3-GPDO332_335)
 ************************************************************************/
/* @brief SIUL, GPIO Pad Data Output.
 * @param pcrNum: (Spec: Functional port pins).
 *        HighLow:  high = 1, low = 0.
 * */
SAF_SEC_CODE
void SIUL_LLD_SetGPIOPadDataOutput(const uint16_t pcrNum, const uint8_t HighLow)
{
    SIUL.GPDO[pcrNum].R = (uint8_t)(HighLow & SIUL_GPDO_U8_PDO_MASK);/* polyspace RTE:OBAI */
}

SAF_SEC_CODE
uint8_t SIUL_LLD_GetGPIOPadDataOutput(const uint16_t pcrNum)
{
    return (uint8_t)(SIUL.GPDO[pcrNum].R);/* polyspace RTE:OBAI */
}

/************************************************************************
 *     GPIO Pad Data Input Registers (GPDI0_3-GPDI332_335)
 ************************************************************************/
/* @brief SIUL, GPIO Input Status Read.
 * @param pcrNum: (Spec: Functional port pins).
 * @return high = 1, low = 0.
 * */
SAF_SEC_CODE
uint8_t SIUL_LLD_GetGPIOPadDataInput(const uint16_t pcrNum)
{
    return (uint8_t)(SIUL.GPDI[pcrNum].R);/* polyspace RTE:OBAI */
}

/************************************************************************
 *     Parallel GPIO Pad Data Out Registers (PGPDO0-PGPDO10)
 ************************************************************************/
/* @brief SIUL, Parallel port registers for input (PGPDI) and
 *          output (PGPDO) are provided to allow a complete port
 *          to be written or read in one operation, dependent on
 *          the individual pad configuration.
 * @param parallelNum:
 *        pinBit:
 * */
SAF_SEC_CODE
void SIUL_LLD_SetParallelGPIOPadDataOut(const uint8_t parallelNum, const uint32_t pinBit)
{
    SIUL.PGPDO[parallelNum].R = pinBit;/* polyspace RTE:OBAI */
}

SAF_SEC_CODE
uint32_t SIUL_LLD_GetParallelGPIOPadDataOut(const uint8_t parallelNum)
{
    return (uint32_t)(SIUL.PGPDO[parallelNum].R);/* polyspace RTE:OBAI */
}

/************************************************************************
 *     Parallel GPIO Pad Data In Registers (PGPDI0-PGPDI10)
 ************************************************************************/
/* @brief SIUL, Parallel port registers for input (PGPDI) and
 *          output (PGPDO) are provided to allow a complete port
 *          to be written or read in one operation, dependent on
 *          the individual pad configuration.
 * @param parallelNum
 * @return
 * */
SAF_SEC_CODE
uint32_t SIUL_LLD_GetParallelGPIOPadDataIn(const uint8_t parallelNum)
{
    return (uint32_t)(SIUL.PGPDI[parallelNum].R);/* polyspace RTE:OBAI */
}

/************************************************************************
 *     Masked Parallel GPIO Pad Data Out Register (MPGPDO0-MPGPDO20)
 ************************************************************************/
/* @brief SIUL, GPIO Output Status Write.
 * @note  The MPGPDOx registers may only be accessed with 32-bit writes.
 *          8-bit or 16-bit writes will not modify any bits in the register
 *          and will cause a transfer error response by the module.
 *          Read accesses return '0'.
 * @param portNum
 *        maskPinNum: (must 32-bit write)
 * */
SAF_SEC_CODE
void SIUL_LLD_SetMaskedParallelGPIOPadDataOut(const uint8_t portNum, const uint32_t maskPinBit)
{
    SIUL.MPGPDO[portNum].R = maskPinBit;/* polyspace RTE:OBAI */
}

/************************************************************************
 *     Interrupt Filter Maximum Counter Registers (IFMC0-IFMC23)
 ************************************************************************/
/* @brief SIUL, Maximum Interrupt Filter Counter setting.
 *          Filter Period = T(CK)*MAXCNTx + n*T(CK)
 *          Where (n can be -1 to 3)
 *          T(CK): Prescaled Filter Clock Period,
 *                  which is FIRC clock prescaled to IFCP value
 *          T(FIRC): Basic Filter Clock Period: 62.5 ns (fFIRC = 16 MHz)
 * @param regNum: 0~23.
 *        maxcntNum: 0~15
 * */
SAF_SEC_CODE
void SIUL_LLD_SetIntFilterMaxCnt(const uint8_t regNum, const uint8_t maxCnt)
{
    SIUL.IFMC[regNum].R = (uint32_t)((uint32_t)maxCnt & SIUL_IFMC_MAXCNT_MASK);/* polyspace RTE:OBAI */
}

SAF_SEC_CODE
uint8_t SIUL_LLD_GetIntFilterMaxCnt(const uint8_t regNum)
{
    return (uint8_t)(SIUL.IFMC[regNum].R);/* polyspace RTE:OBAI */
}

/************************************************************************
 *     Interrupt Filter Clock Prescaler Register (IFCPR)
 ************************************************************************/
/* @brief SIUL, Interrupt Filter Clock Prescaler setting.
 *          Prescaled Filter Clock Period = T(FIRC) x (IFCP + 1)
 *          T(FIRC) is the fast internal RC oscillator period.
 * @param ifcpNum: 0~15.
 * */
SAF_SEC_CODE
void SIUL_LLD_SetIntFilterClkPres(uint8_t ifcpNum)
{
    SIUL.IFCPR.R = (uint32_t)((uint32_t)ifcpNum & SIUL_IFCPR_IFCP_MASK);
}

SAF_SEC_CODE
uint8_t SIUL_LLD_GetIntFilterClkPres(void)
{
    return (uint8_t)(SIUL.IFCPR.R);
}

/************************************************************************
 *     LVDS Config Register (LCR0-21)
 ************************************************************************/
SAF_SEC_CODE
void SIUL_LLD_SetLVDSConfig(uint8_t CfgNum, uint8_t LVDS_config)
{
    SIUL.LCR[CfgNum].R = LVDS_config;/* polyspace RTE:OBAI */
}

SAF_SEC_CODE
uint8_t SIUL_LLD_GetLVDSConfig(uint8_t CfgNum)
{
    return SIUL.LCR[CfgNum].R;/* polyspace RTE:OBAI */
}


#endif  /* RESOURCE_SUPPORT_SIUL_IP */

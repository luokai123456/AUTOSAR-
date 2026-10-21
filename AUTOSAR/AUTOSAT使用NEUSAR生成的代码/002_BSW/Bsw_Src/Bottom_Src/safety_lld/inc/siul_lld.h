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
* @file     siul_lld.h
* @version  1.0
* @date     2024 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/
#ifndef SIUL_LLD_H_
#define SIUL_LLD_H_
#include "derivative.h"
#ifdef RESOURCE_SUPPORT_SIUL_IP

typedef struct SIUL_tag SAF_SIUL_TagType;

/* @brief SIUL base address */
#define SAF_SIUL_BASEADDR               (0xFFFC0000UL)

/* @brief SIUL base pointer */
#define SAF_SIUL_PTR                    ((SAF_SIUL_TagType *) SAF_SIUL_BASEADDR)

/* @brief SIUL Reg base address offset */
#define SIUL_ISEL0_OFFSET_ADDR      (0x109CU)

/************************************************************************
* @brief    MCU ID Register #1 (MIDR1)
*************************************************************************/

/************************************************************************
* @brief    MCU ID Register #2 (MIDR2)
*************************************************************************/

/************************************************************************
* @brief    Pad Configuration Registers
*************************************************************************/
#define PCR_WEAK_SEL_PULL_DOWN      0U
#define PCR_WEAK_SEL_PULL_UP        1U
#define PCR_WEAK_PULL_DISABLE       0U
#define PCR_WEAK_PULL_ENABLE        1U

extern uint32_t SIUL_LLD_GetMIDR1(void);
extern uint16_t SIUL_LLD_GetMIDR1_PartNum_0_15(void);
extern uint8_t SIUL_LLD_GetMIDR1_PackSet(void);
extern uint8_t SIUL_LLD_GetMIDR1_MajorMask(void);
extern uint8_t SIUL_LLD_GetMIDR1_MinorMask(void);
extern uint32_t SIUL_LLD_GetMIDR2(void);
extern uint8_t SIUL_LLD_GetMIDR2_Manufacturer(void);
extern uint8_t SIUL_LLD_GetMIDR2_FlashSize1(void);
extern uint8_t SIUL_LLD_GetMIDR2_FlashSize2(void);
extern uint8_t SIUL_LLD_GetMIDR2_PartNum_16_23(void);
extern uint8_t SIUL_LLD_GetMIDR2_DataFlash(void);
extern void SIUL_LLD_EXTI_Clear_Flag(const uint32_t eifNum);
extern uint32_t SIUL_LLD_EXTI_Get_Flag(void);
extern void SIUL_LLD_SetExtIntReqEn(const uint32_t ireNum);
extern uint32_t SIUL_LLD_GetExtIntReqEn(void);
extern void SIUL_LLD_SetIntRisingEventEn(const uint32_t ireeNum);
extern uint32_t SIUL_LLD_GetIntRisingEventEn(void);
extern void SIUL_LLD_SetIntFallingEventEn(const uint32_t ifeeNum);
extern uint32_t SIUL_LLD_GetIntFallingEventEn(void);
extern void SIUL_LLD_SetIntFilterEn(const uint32_t ifeNum);
extern uint32_t SIUL_LLD_GetIntFilterEn(void);
extern void SIUL_LLD_SetPadConfig(const uint16_t pcrNum, const uint16_t padType);
extern uint16_t SIUL_LLD_GetPadConfig(const uint16_t pcrNum);
extern void SIUL_LLD_SetPadSelMultInput(const uint16_t padSelNum, const uint8_t padSel);
extern uint8_t SIUL_LLD_GetPadSelMultInput(const uint16_t padSelNum);
extern void SIUL_LLD_SetGPIOPadDataOutput(const uint16_t pcrNum, const uint8_t HighLow);
extern uint8_t SIUL_LLD_GetGPIOPadDataOutput(const uint16_t pcrNum);
extern uint8_t SIUL_LLD_GetGPIOPadDataInput(const uint16_t pcrNum);
extern void SIUL_LLD_SetParallelGPIOPadDataOut(const uint8_t parallelNum, const uint32_t pinBit);
extern uint32_t SIUL_LLD_GetParallelGPIOPadDataOut(const uint8_t parallelNum);
extern uint32_t SIUL_LLD_GetParallelGPIOPadDataIn(const uint8_t parallelNum);
extern void SIUL_LLD_SetMaskedParallelGPIOPadDataOut(const uint8_t portNum, const uint32_t maskPinBit);
extern void SIUL_LLD_SetIntFilterMaxCnt(const uint8_t regNum, const uint8_t maxCnt);
extern uint8_t SIUL_LLD_GetIntFilterMaxCnt(const uint8_t regNum);
extern void SIUL_LLD_SetIntFilterClkPres(uint8_t ifcpNum);
extern uint8_t SIUL_LLD_GetIntFilterClkPres(void);
extern void SIUL_LLD_SetLVDSConfig(uint8_t CfgNum, uint8_t LVDS_config);
extern uint8_t SIUL_LLD_GetLVDSConfig(uint8_t CfgNum);

#endif  /* RESOURCE_SUPPORT_SIUL_IP */
#endif /* SIUL_LLD_H_ */

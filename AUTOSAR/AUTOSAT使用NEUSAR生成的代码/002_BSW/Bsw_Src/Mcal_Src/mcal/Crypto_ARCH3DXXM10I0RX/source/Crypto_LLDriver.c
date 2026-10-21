/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Crypto
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     :
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Crypto_LLDriver.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Crypto MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/
/* PRQA S 0380, 3006, 1006, 2016, 3432, 2052, 2741, 4394, 4342, 1257, 1527, 1525 EOF */
/* PRQA S 3332, 0492, 3344, 1281, 4115, 4558, 1599, 1259, 0751, 1258, 1594 EOF */
/* PRQA S 1503, 3673, 1593, 1750, 1599, 1581, 1508, 1756, 1330 EOF */
#include "Crypto.h"
#include "Mcu_LLDriver.h"
#include "Crypto_LLDriver.h"
#include "cache_lldriver.h"

/*
 * QAC violations
 *
 * @ID:rcma-4.0.0-1503 Rule:M3CM Rule-2.1
 * The function '%1s' is defined but is not used within this project.
 *
 * @ID:qac-11.0.0-3673 Rule:M3CM Rule-7.13
 * The object addressed by the pointer parameter '%1s' is not modified and so
 * the pointer could be of type 'pointer to const'.
 */



/*******************************************************************************
 * Variables
 ******************************************************************************/

/* Pointer to runtime state structure.*/
#define CRYPTO_START_SEC_VAR_NO_INIT
#include "Crypto_MemMap.h"
static hsmSrvDescriptor_t s_hsmSrvDesc;
#define CRYPTO_STOP_SEC_VAR_NO_INIT
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_NO_INIT
#include "Crypto_MemMap.h"
static hsmKeyInfo_t keyInfo;
#define CRYPTO_STOP_SEC_VAR_NO_INIT
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
CRYPTO_INLINE FUNC(boolean, CRYPTO_CODE) HSM_IsResponseReady
(
	VAR(Mcu_CoreType, AUTOMATIC) coreId
)
{
    boolean isBusy;

    if ((1UL << coreId) == (HSM.HOST_FLAG & (1UL << coreId)))/* polyspace RTE:SHF */
    {
        isBusy = FALSE;
    }
    else
    {
        if (HSM_STATUS_MASK == (HSM.HSM_STATUS & HSM_STATUS_MASK))
        {
            isBusy = FALSE;
        }
        else
        {
            isBusy = TRUE;
        }
    }

    if(SUSPEND_REG == SUSPEND_O)
    {
    	isBusy = FALSE;
    }

    return isBusy;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
CRYPTO_INLINE FUNC(status_t, CRYPTO_CODE) HSM_RequestService_Async
(
	VAR(Mcu_CoreType, AUTOMATIC) coreId,
	P2VAR(hsmSrvDescriptor_t, AUTOMATIC, CRYPTO_APPL_DATA) pHsmSrvDescriptor
)
{
/*    uint32_t timeout = HSE_OPERATION_TIMEOUT;*/
    status_t status = STATUS_SUCCESS;

    if (TRUE != HSM_IsResponseReady(coreId))
    {
        status = STATUS_BUSY;
    }
    if (STATUS_SUCCESS == status)
    {
        HSM.ALG_PARAM[0] = coreId;
        HSM.ALG_PARAM[1] = (uint32_t)pHsmSrvDescriptor;

        HSM.HOST_FLAG = 1UL << coreId; /* Call hsm to raise interrupt */
    }

    return status;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
CRYPTO_INLINE FUNC(status_t, CRYPTO_CODE) HSM_RequestService
(
	VAR(Mcu_CoreType, AUTOMATIC) coreId,
	P2VAR(hsmSrvDescriptor_t, AUTOMATIC, CRYPTO_APPL_DATA) pHsmSrvDescriptor
)
{
    uint32_t timeout = HSE_OPERATION_TIMEOUT;
    status_t status = STATUS_SUCCESS;

    if (TRUE != HSM_IsResponseReady(coreId))
    {
        status = STATUS_BUSY;
    }
    if (STATUS_SUCCESS == status)
    {
        HSM.ALG_PARAM[0] = coreId;
        HSM.ALG_PARAM[1] = (uint32_t)pHsmSrvDescriptor;

        HSM.HOST_FLAG = 1UL << coreId; /* Call hsm to raise interrupt */

        if (1) /* SYNC */
        {
            while ((FALSE == HSM_IsResponseReady(coreId)) && (timeout > 0U))
            {
                timeout -- ;
            }

            if (0UL == timeout)
            {
                status = STATUS_TIMEOUT;
            }
        }
        else /* ASYNC */
        {

        }
    }
    if (STATUS_SUCCESS == status)
    {
        if (0U != HSM.HSM_STATUS)
        {
            status = (status_t)(((HSM.HSM_STATUS & 0xFFFF0000U) >> 16) | HSM_ERC_OFFSET);
        }
#ifdef DCACHE_ENABLE /* cyh */
        /* NOTE: up to MCAL V3.0.8(or later), cache operation will use new API */
		#if (1 == SUPPORT_NEW_CACHE_API)
			Mcu_Cache_InitUncacheRegion();
		#else
			CACHE_LLD_InvalidateDcache();
		#endif
#endif
    }

    return status;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Init(void)
{
	uint8 i = 0;
	status_t status = STATUS_SUCCESS;

	if ((0U == SSCM.UOPS.B.HSE) || (0U == SSCM.HSA.B.HADR))
	{
		status = STATUS_ERROR;
	}
	else
	{
		for (i = 0U; i < 32U; i++)
		{
			PBRIDGE_A.OPACR[i].B.OPACRa = 0;
			PBRIDGE_A.OPACR[i].B.OPACRb = 0;
			PBRIDGE_A.OPACR[i].B.OPACRc = 0;
			PBRIDGE_A.OPACR[i].B.OPACRd = 0;
			PBRIDGE_A.OPACR[i].B.OPACRe = 0;
			PBRIDGE_A.OPACR[i].B.OPACRf = 0;
			PBRIDGE_A.OPACR[i].B.OPACRg = 0;
			PBRIDGE_A.OPACR[i].B.OPACRh = 0;

			PBRIDGE_B.OPACR[i].B.OPACRa = 0;
			PBRIDGE_B.OPACR[i].B.OPACRb = 0;
			PBRIDGE_B.OPACR[i].B.OPACRc = 0;
			PBRIDGE_B.OPACR[i].B.OPACRd = 0;
			PBRIDGE_B.OPACR[i].B.OPACRe = 0;
			PBRIDGE_B.OPACR[i].B.OPACRf = 0;
			PBRIDGE_B.OPACR[i].B.OPACRg = 0;
			PBRIDGE_B.OPACR[i].B.OPACRh = 0;

		}
		/* SKIP B OPACR92 LIN Controller 2 (LINFlexD_2) */
		PBRIDGE_B.OPACR[11].B.OPACRe = 0x0;
		/* Write protect, S */
		PBRIDGE_A.PACR[7].B.PACRb = 0; /* 16 KB A PACR57 Tamper Detect (Tamper_DETECT) */
		PBRIDGE_A.PACR[5].B.PACRe = 0; /* 16 KB A PACR44 Fast Ethernet Controller 0 (FEC_0) */
		PBRIDGE_A.PACR[5].B.PACRb = 0; /* 16 KB A PACR41 Direct Memory Access Controller 1 (DMA_1) */
		PBRIDGE_A.PACR[5].B.PACRa = 0; /* 16 KB A PACR40 Direct Memory Access Controller 0 (DMA_0) */
		PBRIDGE_A.PACR[3].B.PACRe = 0; /* 16 KB A PACR28 System Timer Module 2 (STM_2) */
		PBRIDGE_A.PACR[3].B.PACRd = 0; /* 16 KB A PACR27 System Timer Module 1 (STM_1) */
		PBRIDGE_A.PACR[3].B.PACRc = 0; /* 16 KB A PACR26 System Timer Module 0 (STM_0) */
		PBRIDGE_A.PACR[2].B.PACRh = 0; /* 16 KB A PACR23 Software Watchdog Timer 3 (SWT_3) */
		PBRIDGE_A.PACR[2].B.PACRg = 0; /* 16 KB A PACR22 Software Watchdog Timer 2 (SWT_2) */
		PBRIDGE_A.PACR[2].B.PACRf = 0; /* 16 KB A PACR21 Software Watchdog Timer 1 (SWT_1) */
		PBRIDGE_A.PACR[2].B.PACRe = 0; /* 16 KB A PACR20 Software Watchdog Timer 0 (SWT_0) */
		PBRIDGE_A.PACR[2].B.PACRa = 0; /* 16 KB A PACR16 Interrupt Controller (INTC_0) */
		PBRIDGE_A.PACR[1].B.PACRh = 0; /* 16 KB A PACR15 Semaphore (SEMA4) */
		PBRIDGE_A.PACR[1].B.PACRe = 0; /* 16 KB A PACR12 PFLASH (Platform Flash controller) */
		PBRIDGE_A.PACR[1].B.PACRc = 0; /* 16 KB A PACR10 Platform Configuration Module (PCM) */
		PBRIDGE_A.PACR[1].B.PACRa = 0; /* 16 KB A PACR8 Platform RAM controller (PRAM_0) */
		PBRIDGE_A.PACR[0].B.PACRh = 0; /* 16 KB A PACR7 Cross Bar Integrity Checker 1 (XBIC_1) */
		PBRIDGE_A.PACR[0].B.PACRg = 0; /* 16 KB A PACR6 Cross Bar Integrity Checker 0 (XBIC_0) */
		PBRIDGE_A.PACR[0].B.PACRf = 0; /* 16 KB A PACR5 System Memory Protection Unit 1 (SMPU_1) */
		PBRIDGE_A.PACR[0].B.PACRe = 0; /* 16 KB A PACR4 System Memory Protection Unit 0 (SMPU_0) */
		PBRIDGE_A.PACR[0].B.PACRc = 0; /* 16 KB A PACR2 Peripheral Shell Crossbar (XBAR_1) */
		PBRIDGE_A.PACR[0].B.PACRb = 0; /* 16 KB A PACR1 Computational Shell Crossbar (XBAR_0) */
		PBRIDGE_A.PACR[0].B.PACRa = 0; /* 16 KB A PACR0 Peripheral Bridge A (PBRIDGE_A) */
		PBRIDGE_B.PACR[0].B.PACRa = 0; /* 16 KB B PACR0 Peripheral Bridge B (PBRIDGE_B) */
	}

	return status;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) HSM_LLD_ConfigInterrupt
(
	VAR(boolean, AUTOMATIC) enable
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();

    /* enable irq */
    if (0U == coreId)
    {
        if (TRUE == enable)
        {
            HSM.HSM_FLAG = 0xFFFFFFFFUL;
            HSM.HOST_IE_ENABLE |= 1UL << coreId;
        }
        else
        {
            HSM.HOST_IE_ENABLE &= ~(1UL << coreId);
        }
    }
    else if (1U == coreId)
    {
        if (TRUE == enable)
        {
            HSM.HSM_FLAG = 0xFFFFFFFFUL;
            HSM.HOST_IE_ENABLE |= 1UL << coreId;
        }
        else
        {
            HSM.HOST_IE_ENABLE &= ~(1UL << coreId);
        }
    }
    else
    {
        if (TRUE == enable)
        {
            HSM.HSM_FLAG = 0xFFFFFFFFUL;
            HSM.HOST_IE_ENABLE |= 1UL << coreId;/* polyspace RTE:SHF */
        }
        else
        {
            HSM.HOST_IE_ENABLE &= ~(1UL << coreId);/* polyspace RTE:SHF */
        }
    }
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_SetClkDiv
(
	VAR(uint32, AUTOMATIC) divider
)
{
    status_t status = STATUS_SUCCESS;
    uint32 timeout = HSE_OPERATION_TIMEOUT;

    HSM.ALG_PARAM[1] = divider;
    HSM.HOST_FLAG = HSM_SRV_CMD_SET_CLK_DIV;

    /* Wait for the service to complete */
    while ((HSM.HOST_FLAG == HSM_SRV_CMD_SET_CLK_DIV) && (timeout > 0U))
    {
        timeout -- ;
    }

    if (0UL == timeout)
    {
        status = STATUS_TIMEOUT;
    }
    return status;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_SetAttr
(
		VAR(uint16, AUTOMATIC) attrid,
		VAR(uint8, AUTOMATIC) attrval,
		VAR(uint32, AUTOMATIC) attrlen
)
{
    status_t status = STATUS_SUCCESS;
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t)); /* PRQA S 0751 */

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SET_ATTR; /* PRQA S 1259 */
    pHsmSrvDesc->srvReq.setAttr.attrId = attrid;
    pHsmSrvDesc->srvReq.setAttr.pAttr = (HOST_ADDR)&attrval;
    pHsmSrvDesc->srvReq.setAttr.attrLen = attrlen;

    /* Request the service to HSM */
    status = HSM_RequestService(coreId, pHsmSrvDesc);

    return status;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_SetAttr_Async
(
		VAR(uint16, AUTOMATIC) attrid,
		VAR(uint8, AUTOMATIC) attrval,
		VAR(uint32, AUTOMATIC) attrlen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t)); /* PRQA S 0751 */

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SET_ATTR; /* PRQA S 1259 */
    pHsmSrvDesc->srvReq.setAttr.attrId = attrid;
    pHsmSrvDesc->srvReq.setAttr.pAttr = (HOST_ADDR)&attrval;
    pHsmSrvDesc->srvReq.setAttr.attrLen = attrlen;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetVersion
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pVer,
	VAR(uint32, AUTOMATIC) verLen
)
{
    status_t status;
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_GET_ATTR;
    pHsmSrvDesc->srvReq.getAttr.attrId = HSM_ATTR_ID_FW_VERSION;
    pHsmSrvDesc->srvReq.getAttr.pAttr = (HOST_ADDR)pVer;
    pHsmSrvDesc->srvReq.getAttr.attrLen = verLen;

    /* Request the service to HSM */
    status = HSM_RequestService(coreId, pHsmSrvDesc);

    return status;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_SetParam
(
    P2VAR(volatile uint8, AUTOMATIC, CRYPTO_APPL_DATA) pParam,
    VAR(uint32, AUTOMATIC) ParamOffset
)
{
    status_t status;
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SET_ATTR;
    pHsmSrvDesc->srvReq.setAttr.attrId = HSM_ATTR_ID_SET_PARAM;
    pHsmSrvDesc->srvReq.setAttr.pAttr = (HOST_ADDR)pParam;
    pHsmSrvDesc->srvReq.setAttr.attrOffset = ParamOffset;

    /* Request the service to HSM */
    status = HSM_RequestService(coreId, pHsmSrvDesc);

    return status;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetCounter
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pCounter,
	VAR(uint32, AUTOMATIC) counterLen
)
{
    status_t status;
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_GET_ATTR;
    pHsmSrvDesc->srvReq.getAttr.attrId = HSM_ATTR_ID_GET_COUNTER;
    pHsmSrvDesc->srvReq.getAttr.pAttr = (HOST_ADDR)pCounter;
    pHsmSrvDesc->srvReq.getAttr.attrLen = counterLen;

    /* Request the service to HSM */
    status = HSM_RequestService(coreId, pHsmSrvDesc);

    return status;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetStack
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pVal,
	VAR(uint32, AUTOMATIC) Len
)
{
    status_t status;
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_GET_ATTR;
    pHsmSrvDesc->srvReq.getAttr.attrId = HSM_ATTR_ID_STACK_REMAIN;
    pHsmSrvDesc->srvReq.getAttr.pAttr = (HOST_ADDR)pVal;
    pHsmSrvDesc->srvReq.getAttr.attrLen = Len;

    /* Request the service to HSM */
    status = HSM_RequestService(coreId, pHsmSrvDesc);

    return status;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetAttr
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pVal,
	VAR(uint32, AUTOMATIC) Len,
	VAR(hsmAttrId_t, AUTOMATIC) AttrID
)
{
    status_t status;
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_GET_ATTR;
    pHsmSrvDesc->srvReq.getAttr.attrId = AttrID;
    pHsmSrvDesc->srvReq.getAttr.pAttr = (HOST_ADDR)pVal;
    pHsmSrvDesc->srvReq.getAttr.attrLen = Len;

    /* Request the service to HSM */
    status = HSM_RequestService(coreId, pHsmSrvDesc);

    return status;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetDataVersion
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pVer,
	VAR(uint32, AUTOMATIC) verLen
)
{
    status_t status;
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_GET_ATTR;
    pHsmSrvDesc->srvReq.getAttr.attrId = HSM_ATTR_ID_DATA_VERSION;
    pHsmSrvDesc->srvReq.getAttr.pAttr = (HOST_ADDR)pVer;
    pHsmSrvDesc->srvReq.getAttr.attrLen = verLen;

    /* Request the service to HSM */
    status = HSM_RequestService(coreId, pHsmSrvDesc);

    return status;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetBootType
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pType,
	VAR(uint32, AUTOMATIC) typeLen
)
{
    status_t status;
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_GET_ATTR;
    pHsmSrvDesc->srvReq.getAttr.attrId = HSM_ATTR_ID_BOOT_TYPE;
    pHsmSrvDesc->srvReq.getAttr.pAttr = (HOST_ADDR)pType;
    pHsmSrvDesc->srvReq.getAttr.attrLen = typeLen;

    /* Request the service to HSM */
    status = HSM_RequestService(coreId, pHsmSrvDesc);

    return status;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetSmrEntry
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSmrEntry,
	VAR(uint32, AUTOMATIC) SmrEntryLen
)
{
    status_t status;
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_GET_ATTR;
    pHsmSrvDesc->srvReq.getAttr.attrId = HSM_ATTR_ID_SMR_ENTRY;
    pHsmSrvDesc->srvReq.getAttr.pAttr = (HOST_ADDR)pSmrEntry;
    pHsmSrvDesc->srvReq.getAttr.attrLen = SmrEntryLen;

    /* Request the service to HSM */
    status = HSM_RequestService(coreId, pHsmSrvDesc);

    return status;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_DevAuthReq
(
	VAR(hsmDevAuthOption_t, AUTOMATIC) devAuthOption,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(hsmAuthScheme_t, AUTOMATIC, CRYPTO_APPL_DATA) pAuthScheme,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pChallenge
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_DEV_AUTH_REQ;
    pHsmSrvDesc->srvReq.devAuthReq.devAuthOption = devAuthOption;
    pHsmSrvDesc->srvReq.devAuthReq.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.devAuthReq.pChallenge = (HOST_ADDR)pChallenge;
    if (NULL != pAuthScheme)
    {
        cc_memcpy((uint8 *)&pHsmSrvDesc->srvReq.devAuthReq.authScheme, (uint8_t *)pAuthScheme, sizeof(hsmAuthScheme_t));
    }
    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_DevAuthResp
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAuth0,
	VAR(uint32, AUTOMATIC) auth0Len,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAuth1,
	VAR(uint32, AUTOMATIC) auth1Len
)
{
    uint32 calcBuf[8];
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_DEV_AUTH_RESP;
    pHsmSrvDesc->srvReq.devAuthResp.pAuth[0] = (HOST_ADDR)pAuth0;
    pHsmSrvDesc->srvReq.devAuthResp.authLen[0] = (uint16)auth0Len;
    pHsmSrvDesc->srvReq.devAuthResp.pAuth[1] = (HOST_ADDR)pAuth1;
    pHsmSrvDesc->srvReq.devAuthResp.authLen[1] = (uint16)auth1Len;
    pHsmSrvDesc->srvReq.devAuthResp.pCalcBuf = (HOST_ADDR)calcBuf;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_DevAuthRst
(
	VAR(hsmDevAuthOption_t, AUTOMATIC) devAuthOption
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_DEV_AUTH_RST;
    pHsmSrvDesc->srvReq.devAuthRst.devAuthOption = devAuthOption;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ConfigSecureBoot
(
	VAR(hsmSecureBootType_t, AUTOMATIC) bootType,
	VAR(hsmKeyHandle_t, AUTOMATIC) authKeyHandle,
	VAR(hsmSecureBootFailOp_t, AUTOMATIC) op,
	P2VAR(xoscClkCofigData_t, AUTOMATIC, CRYPTO_APPL_DATA) xoscConfigData,
	P2VAR(verifyCodeSegments, AUTOMATIC, CRYPTO_APPL_DATA) pCodeSegs,
	P2VAR(codeSigns0, AUTOMATIC, CRYPTO_APPL_DATA) pSign,
	VAR(uint32, AUTOMATIC) segcnt,
	VAR(boolean, AUTOMATIC) bootZ4_2,
	VAR(boolean, AUTOMATIC) bootZ7_0,
	VAR(boolean, AUTOMATIC) bootZ7_1
)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;


    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

	pHsmSrvDesc->srvCmd = HSM_SRV_CMD_CONFIG_SECURE_BOOT;
	pHsmSrvDesc->srvReq.configSecureBoot.bootType = bootType;
	pHsmSrvDesc->srvReq.configSecureBoot.authkeyHandle = authKeyHandle;
	pHsmSrvDesc->srvReq.configSecureBoot.operationOnFail = op;
	pHsmSrvDesc->srvReq.configSecureBoot.xoscConfig = (HOST_ADDR)xoscConfigData;
	pHsmSrvDesc->srvReq.configSecureBoot.pVerifySegs = (uint32_t)pCodeSegs;
	pHsmSrvDesc->srvReq.configSecureBoot.bootZ4_2 = bootZ4_2;
	pHsmSrvDesc->srvReq.configSecureBoot.bootZ7_0 = bootZ7_0;
	pHsmSrvDesc->srvReq.configSecureBoot.bootZ7_1 = bootZ7_1;
	pHsmSrvDesc->srvReq.configSecureBoot.pSign = (HOST_ADDR)pSign;
	pHsmSrvDesc->srvReq.configSecureBoot.signlen = segcnt;

	return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ConfigSecureBoot_SWP
(
	VAR(hsmSecureBootType_t, AUTOMATIC) bootType,
	VAR(hsmKeyHandle_t, AUTOMATIC) authKeyHandle,
	VAR(hsmSecureBootFailOp_t, AUTOMATIC) op,
	P2VAR(xoscClkCofigData_t, AUTOMATIC, CRYPTO_APPL_DATA) xoscConfigData,
	P2VAR(verifyCodeSegments, AUTOMATIC, CRYPTO_APPL_DATA) pCodeSegs,
	P2VAR(verifyCodeSegments, AUTOMATIC, CRYPTO_APPL_DATA) pSwpCodeSegs,
	P2VAR(codeSigns0, AUTOMATIC, CRYPTO_APPL_DATA) pSign,
	P2VAR(codeSigns0, AUTOMATIC, CRYPTO_APPL_DATA) pSwpSign,
	VAR(uint32, AUTOMATIC) segcnt,
	VAR(boolean, AUTOMATIC) bootZ4_2,
	VAR(boolean, AUTOMATIC) bootZ7_0,
	VAR(boolean, AUTOMATIC) bootZ7_1
)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

	pHsmSrvDesc->srvCmd = HSM_SRV_CMD_CONFIG_SECURE_BOOT_SWP;
	pHsmSrvDesc->srvReq.configSecureBootSWP.bootType = bootType;
	pHsmSrvDesc->srvReq.configSecureBootSWP.authkeyHandle = authKeyHandle;
	pHsmSrvDesc->srvReq.configSecureBootSWP.operationOnFail = op;
	pHsmSrvDesc->srvReq.configSecureBootSWP.xoscConfig = (HOST_ADDR)xoscConfigData;
	pHsmSrvDesc->srvReq.configSecureBootSWP.verifySegs = (uint32_t)pCodeSegs;
	pHsmSrvDesc->srvReq.configSecureBootSWP.SwpverifySegs = (uint32_t)pSwpCodeSegs;
	pHsmSrvDesc->srvReq.configSecureBootSWP.bootZ4_2 = bootZ4_2;
	pHsmSrvDesc->srvReq.configSecureBootSWP.bootZ7_0 = bootZ7_0;
	pHsmSrvDesc->srvReq.configSecureBootSWP.bootZ7_1 = bootZ7_1;
	pHsmSrvDesc->srvReq.configSecureBootSWP.pSign = (HOST_ADDR)pSign;
	pHsmSrvDesc->srvReq.configSecureBootSWP.Swpsigns = (HOST_ADDR)pSwpSign;
	pHsmSrvDesc->srvReq.configSecureBootSWP.signlen = segcnt;
	return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*
 * @Notice: This function is only applicable to HSM firmware version V1.90 or later
 * 			(HSM_FW_VER >= V1.90)
 */
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_InstallSmrEntry
(

	VAR(uint8, AUTOMATIC) bootCore,
	VAR(hsmSecureBootType_t, AUTOMATIC) bootType,
	VAR(hsmSecureBootFailOp_t, AUTOMATIC) op,
	P2VAR(xoscClkCofigData_t, AUTOMATIC, CRYPTO_APPL_DATA) xoscConfigData,
	VAR(uint32, AUTOMATIC) smrCnt,
	P2VAR(hsmSmrEntry_t, AUTOMATIC, CRYPTO_APPL_DATA) pSmrEntry
)
{

	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

	pHsmSrvDesc->srvCmd = HSM_SRV_CMD_INSTALL_SMR_ENTRY;

	pHsmSrvDesc->srvReq.installlSmrEntry.bootCore 	 = bootCore;
	pHsmSrvDesc->srvReq.installlSmrEntry.bootType 	 = bootType;
	pHsmSrvDesc->srvReq.installlSmrEntry.bootFailOp  = op;
	pHsmSrvDesc->srvReq.installlSmrEntry.pXoscConfig = (HOST_ADDR)xoscConfigData;
	pHsmSrvDesc->srvReq.installlSmrEntry.smrCnt      = smrCnt;
	pHsmSrvDesc->srvReq.installlSmrEntry.pSmrEntry   = (HOST_ADDR)pSmrEntry;

	return HSM_RequestService(coreId, pHsmSrvDesc);

}


#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"



#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetSecureBootStatus
(
	P2VAR(hsmSecureBootStatus_t, AUTOMATIC, CRYPTO_APPL_DATA) secureBootStatus
)
{
    uint8_t i;
    uint32_t status_value;
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_GET_ATTR;
    pHsmSrvDesc->srvReq.getAttr.attrId = HSM_ATTR_ID_SECURE_BOOT_STATUS;
    pHsmSrvDesc->srvReq.getAttr.pAttr = (HOST_ADDR)secureBootStatus;
    pHsmSrvDesc->srvReq.getAttr.attrLen = 8;/* sizeof(hsmSecureBootStatus_t);*/

    if ((HSM.HSM_STATUS & 0xFF000000u)== 0xCC000000u)
    {
    	status_value = (HSM.HSM_STATUS & 0x00FFFF00u) >> 8;
    	for (i = 0u; i < 8u; i++)
    	{
    		secureBootStatus[i] = (uint8)(((status_value&0x03u) << 4) | (status_value&0x03u));
    		status_value = status_value >> 2;
    	}

    	return STATUS_SUCCESS;
    }

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_SetIgnoreSecureBootOnce(void)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
	hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;
    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IGNORE_SECURE_BOOT;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);

}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GenerateTrngNum
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pRandom,
	VAR(uint32, AUTOMATIC) randomLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_GET_TRNG_NUMBER;
    pHsmSrvDesc->srvReq.getRandom.pRandomNum = (HOST_ADDR)pRandom;
    pHsmSrvDesc->srvReq.getRandom.randomNumLength = randomLen;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GeneratePrngNum
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pRandom,
	VAR(uint32, AUTOMATIC) randomLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_GET_PRNG_NUMBER;
    pHsmSrvDesc->srvReq.getRandom.pRandomNum = (HOST_ADDR)pRandom;
    pHsmSrvDesc->srvReq.getRandom.randomNumLength = randomLen;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_EraseKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmEraseKeyOptions_t, AUTOMATIC) eraseKeyOptions
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_ERASE_KEY;
    pHsmSrvDesc->srvReq.eraseKey.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.eraseKey.eraseKeyOptions = eraseKeyOptions;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetKeyInfo
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_GET_KEY_INFO;
    pHsmSrvDesc->srvReq.getKeyInfo.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.getKeyInfo.pKeyInfo = (HOST_ADDR)pKeyInfo;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetKeyHash
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pKeyHash
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_GET_KEY_HASH;
    pHsmSrvDesc->srvReq.getKeyHash.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.getKeyHash.pHash = (HOST_ADDR)pKeyHash;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GenerateSymKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyByteLen
)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_KEY_GENERATE;
    pHsmSrvDesc->srvReq.keyGen.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.keyGen.keyInfo.keyType = keyType;
    pHsmSrvDesc->srvReq.keyGen.keyInfo.keyFlags = keyFlags;
    pHsmSrvDesc->srvReq.keyGen.keyInfo.keyBitLen = keyByteLen << 3;
    pHsmSrvDesc->srvReq.keyGen.keyGenScheme = HSM_KEY_GEN_SYM_RANDOM_KEY;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GenerateJtagPasswd
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pDerivative,
	VAR(uint32, AUTOMATIC) derivativeLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pJtagPasswd
)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_KEY_GENERATE;
    pHsmSrvDesc->srvReq.keyGen.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.keyGen.keyInfo.keyBitLen = HSM_KEY_BITS_256;
    pHsmSrvDesc->srvReq.keyGen.keyInfo.keyFlags = HSM_KEY_FLAG_USAGE_UNLOCK_JTAG | HSM_KEY_FLAG_ACCESS_WRITE_PROT | HSM_KEY_FLAG_ACCESS_EXPORTABLE;/* PRQA S 0499 *//* PRQA S 4399 */
    pHsmSrvDesc->srvReq.keyGen.keyInfo.keyType =  HSM_KEY_TYPE_PASSWD;
    pHsmSrvDesc->srvReq.keyGen.keyGenScheme = HSM_KEY_GEN_JTAG_PASSWD;
    pHsmSrvDesc->srvReq.keyGen.sch.jtagKey.derivative = (HOST_ADDR)pDerivative;
    pHsmSrvDesc->srvReq.keyGen.sch.jtagKey.derivativeLen = derivativeLen;
    pHsmSrvDesc->srvReq.keyGen.sch.jtagKey.pPasswd = (HOST_ADDR)pJtagPasswd;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetJtagPasswd
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pJtagPasswd,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pJtagPasswdLen
)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_EXPORT_KEY;
    pHsmSrvDesc->srvReq.exportKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.exportKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.exportKey.pKey[2] = (HOST_ADDR)pJtagPasswd;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[2] = (HOST_ADDR)pJtagPasswdLen;
    pHsmSrvDesc->srvReq.exportKey.cipher.cipherKeyHandle = HSM_INVALID_KEY_HANDLE;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainSymKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyByteLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pKey
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyByteLen << 3;
    keyInfo.keyFlags = keyFlags;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = keyByteLen;
    pHsmSrvDesc->srvReq.importKey.cipher.cipherKeyHandle = HSM_INVALID_KEY_HANDLE;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainSymKey_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyByteLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pKey
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyByteLen << 3;
    keyInfo.keyFlags = keyFlags;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = keyByteLen;
    pHsmSrvDesc->srvReq.importKey.cipher.cipherKeyHandle = HSM_INVALID_KEY_HANDLE;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainRsaKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pModulus,
	VAR(uint16, AUTOMATIC) publicExponentLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponent,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateExponent
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyBitLen;
    keyInfo.keyFlags = keyFlags;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[0] = (HOST_ADDR)pModulus;
    pHsmSrvDesc->srvReq.importKey.keyLen[0] = keyBitLen >> 3;
    pHsmSrvDesc->srvReq.importKey.pKey[1] = (HOST_ADDR)pPublicExponent;
    pHsmSrvDesc->srvReq.importKey.keyLen[1] = publicExponentLen;
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pPrivateExponent;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = keyBitLen >> 3;
    pHsmSrvDesc->srvReq.importKey.cipher.cipherKeyHandle = HSM_INVALID_KEY_HANDLE;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainRsaKey_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pModulus,
	VAR(uint16, AUTOMATIC) publicExponentLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponent,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateExponent
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyBitLen;
    keyInfo.keyFlags = keyFlags;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[0] = (HOST_ADDR)pModulus;
    pHsmSrvDesc->srvReq.importKey.keyLen[0] = keyBitLen >> 3;
    pHsmSrvDesc->srvReq.importKey.pKey[1] = (HOST_ADDR)pPublicExponent;
    pHsmSrvDesc->srvReq.importKey.keyLen[1] = publicExponentLen;
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pPrivateExponent;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = keyBitLen >> 3;
    pHsmSrvDesc->srvReq.importKey.cipher.cipherKeyHandle = HSM_INVALID_KEY_HANDLE;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainEccKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(hsmEccCurveId_t, AUTOMATIC) eccCurveId,
	VAR(uint16, AUTOMATIC)  keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyBitLen;
    keyInfo.keyFlags = keyFlags;
    keyInfo.special.eccCurveId = eccCurveId;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[0] = (HOST_ADDR)pPublicKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[0] = 2U * (keyBitLen >> 3);
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pPrivateKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = keyBitLen >> 3;

    s_hsmSrvDesc.srvReq.importKey.cipher.cipherKeyHandle = HSM_INVALID_KEY_HANDLE;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainEccKey_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(hsmEccCurveId_t, AUTOMATIC) eccCurveId,
	VAR(uint16, AUTOMATIC)  keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyBitLen;
    keyInfo.keyFlags = keyFlags;
    keyInfo.special.eccCurveId = eccCurveId;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[0] = (HOST_ADDR)pPublicKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[0] = 2U * (keyBitLen >> 3);
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pPrivateKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = keyBitLen >> 3;

    s_hsmSrvDesc.srvReq.importKey.cipher.cipherKeyHandle = HSM_INVALID_KEY_HANDLE;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainED25519Key
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC)  keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyBitLen;
    keyInfo.keyFlags = keyFlags;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[0] = (HOST_ADDR)pPublicKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[0] = keyBitLen >> 3;
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pPrivateKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = keyBitLen >> 3;

    s_hsmSrvDesc.srvReq.importKey.cipher.cipherKeyHandle = HSM_INVALID_KEY_HANDLE;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainED25519Key_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC)  keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyBitLen;
    keyInfo.keyFlags = keyFlags;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[0] = (HOST_ADDR)pPublicKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[0] = keyBitLen >> 3;
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pPrivateKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = keyBitLen >> 3;

    s_hsmSrvDesc.srvReq.importKey.cipher.cipherKeyHandle = HSM_INVALID_KEY_HANDLE;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif


#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainSm2Key
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC)  keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyBitLen;
    keyInfo.keyFlags = keyFlags;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[0] = (HOST_ADDR)pPublicKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[0] = 2U * (keyBitLen >> 3);
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pPrivateKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = keyBitLen >> 3;

    s_hsmSrvDesc.srvReq.importKey.cipher.cipherKeyHandle = HSM_INVALID_KEY_HANDLE;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainSm2Key_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC)  keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyBitLen;
    keyInfo.keyFlags = keyFlags;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[0] = (HOST_ADDR)pPublicKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[0] = 2U * (keyBitLen >> 3);
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pPrivateKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = keyBitLen >> 3;

    s_hsmSrvDesc.srvReq.importKey.cipher.cipherKeyHandle = HSM_INVALID_KEY_HANDLE;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedSymKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyByteLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pKey,
	VAR(uint16, AUTOMATIC) encryptedKeyLen)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyByteLen << 3;
    keyInfo.keyFlags = keyFlags;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = encryptedKeyLen;
    pHsmSrvDesc->srvReq.importKey.cipher.cipherKeyHandle = cipherKeyHandle;
    pHsmSrvDesc->srvReq.importKey.cipher.cipherScheme = cipherScheme;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedSymKey_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyByteLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pKey,
	VAR(uint16, AUTOMATIC) encryptedKeyLen)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyByteLen << 3;
    keyInfo.keyFlags = keyFlags;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = encryptedKeyLen;
    pHsmSrvDesc->srvReq.importKey.cipher.cipherKeyHandle = cipherKeyHandle;
    pHsmSrvDesc->srvReq.importKey.cipher.cipherScheme = cipherScheme;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedRsaKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pModulus,
	VAR(uint16, AUTOMATIC) publicExponentLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponent,
	VAR(uint16, AUTOMATIC) encryptedPrivateExponentLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptedPrivateExponent
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyBitLen;
    keyInfo.keyFlags = keyFlags;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[0] = (HOST_ADDR)pModulus;
    pHsmSrvDesc->srvReq.importKey.keyLen[0] = keyBitLen >> 3;
    pHsmSrvDesc->srvReq.importKey.pKey[1] = (HOST_ADDR)pPublicExponent;
    pHsmSrvDesc->srvReq.importKey.keyLen[1] = publicExponentLen;
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pEncryptedPrivateExponent;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = encryptedPrivateExponentLen;

    pHsmSrvDesc->srvReq.importKey.cipher.cipherKeyHandle = cipherKeyHandle;
    pHsmSrvDesc->srvReq.importKey.cipher.cipherScheme = cipherScheme;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedRsaKey_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pModulus,
	VAR(uint16, AUTOMATIC) publicExponentLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponent,
	VAR(uint16, AUTOMATIC) encryptedPrivateExponentLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptedPrivateExponent
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyBitLen;
    keyInfo.keyFlags = keyFlags;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[0] = (HOST_ADDR)pModulus;
    pHsmSrvDesc->srvReq.importKey.keyLen[0] = keyBitLen >> 3;
    pHsmSrvDesc->srvReq.importKey.pKey[1] = (HOST_ADDR)pPublicExponent;
    pHsmSrvDesc->srvReq.importKey.keyLen[1] = publicExponentLen;
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pEncryptedPrivateExponent;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = encryptedPrivateExponentLen;

    pHsmSrvDesc->srvReq.importKey.cipher.cipherKeyHandle = cipherKeyHandle;
    pHsmSrvDesc->srvReq.importKey.cipher.cipherScheme = cipherScheme;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedEccKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(hsmEccCurveId_t, AUTOMATIC) eccCurveId,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptedPrivateKey,
	VAR(uint16, AUTOMATIC) encryptedPrivateKeyLen)

{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyBitLen;
    keyInfo.keyFlags = keyFlags;
    keyInfo.special.eccCurveId = eccCurveId;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[0] = (HOST_ADDR)pPublicKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[0] = 2U * (keyBitLen >> 3);
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pEncryptedPrivateKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = encryptedPrivateKeyLen;

    pHsmSrvDesc->srvReq.importKey.cipher.cipherKeyHandle = cipherKeyHandle;
    pHsmSrvDesc->srvReq.importKey.cipher.cipherScheme = cipherScheme;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedEccKey_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(hsmEccCurveId_t, AUTOMATIC) eccCurveId,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptedPrivateKey,
	VAR(uint16, AUTOMATIC) encryptedPrivateKeyLen)

{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyBitLen;
    keyInfo.keyFlags = keyFlags;
    keyInfo.special.eccCurveId = eccCurveId;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[0] = (HOST_ADDR)pPublicKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[0] = 2U * (keyBitLen >> 3);
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pEncryptedPrivateKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = encryptedPrivateKeyLen;

    pHsmSrvDesc->srvReq.importKey.cipher.cipherKeyHandle = cipherKeyHandle;
    pHsmSrvDesc->srvReq.importKey.cipher.cipherScheme = cipherScheme;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedSm2Key
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pEncryptedPrivateKey,
	VAR(uint16, AUTOMATIC)  encryptedPrivateKeyLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyBitLen;
    keyInfo.keyFlags = keyFlags;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[0] = (HOST_ADDR)pPublicKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[0] = 2U * (keyBitLen >> 3);
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pEncryptedPrivateKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = encryptedPrivateKeyLen;

    pHsmSrvDesc->srvReq.importKey.cipher.cipherKeyHandle = cipherKeyHandle;
    pHsmSrvDesc->srvReq.importKey.cipher.cipherScheme = cipherScheme;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedSm2Key_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pEncryptedPrivateKey,
	VAR(uint16, AUTOMATIC)  encryptedPrivateKeyLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    cc_memset((uint8 *)&keyInfo, 0, sizeof(hsmKeyInfo_t));

    keyInfo.keyType = keyType;
    keyInfo.keyBitLen = keyBitLen;
    keyInfo.keyFlags = keyFlags;
    keyInfo.keyCounter = 0UL;

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_IMPORT_KEY;
    pHsmSrvDesc->srvReq.importKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.importKey.pKeyInfo = (HOST_ADDR)&keyInfo;
    pHsmSrvDesc->srvReq.importKey.pKey[0] = (HOST_ADDR)pPublicKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[0] = 2U * (keyBitLen >> 3);
    pHsmSrvDesc->srvReq.importKey.pKey[2] = (HOST_ADDR)pEncryptedPrivateKey;
    pHsmSrvDesc->srvReq.importKey.keyLen[2] = encryptedPrivateKeyLen;

    pHsmSrvDesc->srvReq.importKey.cipher.cipherKeyHandle = cipherKeyHandle;
    pHsmSrvDesc->srvReq.importKey.cipher.cipherScheme = cipherScheme;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportPlainSymKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pKeyByteLen)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_EXPORT_KEY;
    pHsmSrvDesc->srvReq.exportKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.exportKey.pKeyInfo = (HOST_ADDR)pKeyInfo;
    pHsmSrvDesc->srvReq.exportKey.pKey[2] = (HOST_ADDR)pKey;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[2] = (HOST_ADDR)pKeyByteLen;
    pHsmSrvDesc->srvReq.exportKey.cipher.cipherKeyHandle = HSM_INVALID_KEY_HANDLE;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportPlainRsaKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pModulus,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pModulusLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponent,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponentLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) *pPrivateExponent,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateExponentLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_EXPORT_KEY;
    pHsmSrvDesc->srvReq.exportKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.exportKey.pKeyInfo = (HOST_ADDR)pKeyInfo;
    pHsmSrvDesc->srvReq.exportKey.pKey[0] = (HOST_ADDR)pModulus;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[0] = (HOST_ADDR)pModulusLen;
    pHsmSrvDesc->srvReq.exportKey.pKey[1] = (HOST_ADDR)pPublicExponent;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[1] = (HOST_ADDR)pPublicExponentLen;
    pHsmSrvDesc->srvReq.exportKey.pKey[2] = (HOST_ADDR)pPrivateExponent;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[2] = (HOST_ADDR)pPrivateExponentLen;
    pHsmSrvDesc->srvReq.exportKey.cipher.cipherKeyHandle = HSM_INVALID_KEY_HANDLE;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportPlainEccKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKeyLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA)pPrivateKeyLen)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_EXPORT_KEY;
    pHsmSrvDesc->srvReq.exportKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.exportKey.pKeyInfo = (HOST_ADDR)pKeyInfo;
    pHsmSrvDesc->srvReq.exportKey.pKey[0] = (HOST_ADDR)pPublicKey;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[0] = (HOST_ADDR)pPublicKeyLen;
    pHsmSrvDesc->srvReq.exportKey.pKey[2] = (HOST_ADDR)pPrivateKey;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[2] = (HOST_ADDR)pPrivateKeyLen;
    pHsmSrvDesc->srvReq.exportKey.cipher.cipherKeyHandle = HSM_INVALID_KEY_HANDLE;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportPlainSm2Key
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKeyLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKeyLen)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_EXPORT_KEY;
    pHsmSrvDesc->srvReq.exportKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.exportKey.pKeyInfo = (HOST_ADDR)pKeyInfo;
    pHsmSrvDesc->srvReq.exportKey.pKey[0] = (HOST_ADDR)pPublicKey;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[0] = (HOST_ADDR)pPublicKeyLen;
    pHsmSrvDesc->srvReq.exportKey.pKey[2] = (HOST_ADDR)pPrivateKey;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[2] = (HOST_ADDR)pPrivateKeyLen;
    pHsmSrvDesc->srvReq.exportKey.cipher.cipherKeyHandle = HSM_INVALID_KEY_HANDLE;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportEncryptedSymKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptedKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptedKeyLen,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_EXPORT_KEY;
    pHsmSrvDesc->srvReq.exportKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.exportKey.pKeyInfo = (HOST_ADDR)pKeyInfo;
    pHsmSrvDesc->srvReq.exportKey.pKey[2] = (HOST_ADDR)pEncryptedKey;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[2] = (HOST_ADDR)pEncryptedKeyLen;

    pHsmSrvDesc->srvReq.exportKey.cipher.cipherKeyHandle = cipherKeyHandle;
    pHsmSrvDesc->srvReq.exportKey.cipher.cipherScheme = cipherScheme;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportEncryptedRsaKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pModulus,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pModulusLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponent,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponentLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptPrivateExponent,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptPrivateExponentLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_EXPORT_KEY;
    pHsmSrvDesc->srvReq.exportKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.exportKey.pKeyInfo = (HOST_ADDR)pKeyInfo;
    pHsmSrvDesc->srvReq.exportKey.pKey[0] = (HOST_ADDR)pModulus;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[0] = (HOST_ADDR)pModulusLen;
    pHsmSrvDesc->srvReq.exportKey.pKey[1] = (HOST_ADDR)pPublicExponent;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[1] = (HOST_ADDR)pPublicExponentLen;
    pHsmSrvDesc->srvReq.exportKey.pKey[2] = (HOST_ADDR)pEncryptPrivateExponent;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[2] = (HOST_ADDR)pEncryptPrivateExponentLen;

    pHsmSrvDesc->srvReq.exportKey.cipher.cipherKeyHandle = cipherKeyHandle;
    pHsmSrvDesc->srvReq.exportKey.cipher.cipherScheme = cipherScheme;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportEncryptedEccKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKeyLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptPrivateKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptPrivateKeyLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_EXPORT_KEY;
    pHsmSrvDesc->srvReq.exportKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.exportKey.pKeyInfo = (HOST_ADDR)pKeyInfo;
    pHsmSrvDesc->srvReq.exportKey.pKey[0] = (HOST_ADDR)pPublicKey;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[0] = (HOST_ADDR)pPublicKeyLen;
    pHsmSrvDesc->srvReq.exportKey.pKey[2] = (HOST_ADDR)pEncryptPrivateKey;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[2] = (HOST_ADDR)pEncryptPrivateKeyLen;

    pHsmSrvDesc->srvReq.exportKey.cipher.cipherKeyHandle = cipherKeyHandle;
    pHsmSrvDesc->srvReq.exportKey.cipher.cipherScheme = cipherScheme;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportEncryptedSm2Key
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKeyLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptPrivateKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptPrivateKeyLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_EXPORT_KEY;
    pHsmSrvDesc->srvReq.exportKey.targetKeyHandle = keyHandle;
    pHsmSrvDesc->srvReq.exportKey.pKeyInfo = (HOST_ADDR)pKeyInfo;
    pHsmSrvDesc->srvReq.exportKey.pKey[0] = (HOST_ADDR)pPublicKey;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[0] = (HOST_ADDR)pPublicKeyLen;
    pHsmSrvDesc->srvReq.exportKey.pKey[2] = (HOST_ADDR)pEncryptPrivateKey;
    pHsmSrvDesc->srvReq.exportKey.pKeyLen[2] = (HOST_ADDR)pEncryptPrivateKeyLen;

    pHsmSrvDesc->srvReq.exportKey.cipher.cipherKeyHandle = cipherKeyHandle;
    pHsmSrvDesc->srvReq.exportKey.cipher.cipherScheme = cipherScheme;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Hash
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_HASH;
    pHsmSrvDesc->srvReq.hash.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.hash.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.hash.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.hash.inputLength = inputLen;
    pHsmSrvDesc->srvReq.hash.pHash = (HOST_ADDR)pOutput;
    pHsmSrvDesc->srvReq.hash.pHashLength = (HOST_ADDR)pOutputLen;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Hash_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_HASH;
    pHsmSrvDesc->srvReq.hash.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.hash.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.hash.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.hash.inputLength = inputLen;
    pHsmSrvDesc->srvReq.hash.pHash = (HOST_ADDR)pOutput;
    pHsmSrvDesc->srvReq.hash.pHashLength = (HOST_ADDR)pOutputLen;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_HmacGenerate
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_MAC;
    pHsmSrvDesc->srvReq.mac.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.mac.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.mac.macScheme.macAlgo = HSM_MAC_ALGO_HMAC;
    pHsmSrvDesc->srvReq.mac.macScheme.sch.hmac.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.mac.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.mac.inputLength = inputLen;
    pHsmSrvDesc->srvReq.mac.pTag = (HOST_ADDR)pOutput;
    pHsmSrvDesc->srvReq.mac.pTagLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.mac.authDir = HSM_AUTH_DIR_GENERATE;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_HmacGenerate_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_MAC;
    pHsmSrvDesc->srvReq.mac.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.mac.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.mac.macScheme.macAlgo = HSM_MAC_ALGO_HMAC;
    pHsmSrvDesc->srvReq.mac.macScheme.sch.hmac.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.mac.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.mac.inputLength = inputLen;
    pHsmSrvDesc->srvReq.mac.pTag = (HOST_ADDR)pOutput;
    pHsmSrvDesc->srvReq.mac.pTagLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.mac.authDir = HSM_AUTH_DIR_GENERATE;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_HmacVerify
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pHmac,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pHmaLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_MAC;
    pHsmSrvDesc->srvReq.mac.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.mac.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.mac.macScheme.macAlgo = HSM_MAC_ALGO_HMAC;
    pHsmSrvDesc->srvReq.mac.macScheme.sch.hmac.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.mac.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.mac.inputLength = inputLen;
    pHsmSrvDesc->srvReq.mac.pTag = (HOST_ADDR)pHmac;
    pHsmSrvDesc->srvReq.mac.pTagLength = (HOST_ADDR)pHmaLen;
    pHsmSrvDesc->srvReq.mac.authDir = HSM_AUTH_DIR_VERIFY;
    pHsmSrvDesc->srvReq.mac.pVerifyResult = (HOST_ADDR)pVerifyStatus;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);

#if 0
    /* Request the service to HSM */
    status = HSM_RequestService(coreId, pHsmSrvDesc);
    if (STATUS_SUCCESS == status)
    {
    	*pVerifyStatus = TRUE;
    }
    else if (STATUS_HSM_VERIFY_FAILED == status)
    {
    	*pVerifyStatus = FALSE;
    	status = STATUS_SUCCESS;
    }
    else
    {
    	*pVerifyStatus = FALSE;
    }

    return status;
#endif
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_HmacVerify_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pHmac,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pHmaLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_MAC;
    pHsmSrvDesc->srvReq.mac.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.mac.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.mac.macScheme.macAlgo = HSM_MAC_ALGO_HMAC;
    pHsmSrvDesc->srvReq.mac.macScheme.sch.hmac.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.mac.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.mac.inputLength = inputLen;
    pHsmSrvDesc->srvReq.mac.pTag = (HOST_ADDR)pHmac;
    pHsmSrvDesc->srvReq.mac.pTagLength = (HOST_ADDR)pHmaLen;
    pHsmSrvDesc->srvReq.mac.authDir = HSM_AUTH_DIR_VERIFY;
    pHsmSrvDesc->srvReq.mac.pVerifyResult = (HOST_ADDR)pVerifyStatus;
    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);

}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesCmacGenerate
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_MAC;
    pHsmSrvDesc->srvReq.mac.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.mac.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.mac.macScheme.macAlgo = HSM_MAC_ALGO_CMAC;
    pHsmSrvDesc->srvReq.mac.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.mac.inputLength = inputLen;
    pHsmSrvDesc->srvReq.mac.pTag = (HOST_ADDR)pOutput;
    pHsmSrvDesc->srvReq.mac.pTagLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.mac.authDir = HSM_AUTH_DIR_GENERATE;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesCmacGenerate_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_MAC;
    pHsmSrvDesc->srvReq.mac.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.mac.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.mac.macScheme.macAlgo = HSM_MAC_ALGO_CMAC;
    pHsmSrvDesc->srvReq.mac.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.mac.inputLength = inputLen;
    pHsmSrvDesc->srvReq.mac.pTag = (HOST_ADDR)pOutput;
    pHsmSrvDesc->srvReq.mac.pTagLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.mac.authDir = HSM_AUTH_DIR_GENERATE;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesCmacVerify
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pCmac,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pCmaLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_MAC;
    pHsmSrvDesc->srvReq.mac.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.mac.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.mac.macScheme.macAlgo = HSM_MAC_ALGO_CMAC;
    pHsmSrvDesc->srvReq.mac.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.mac.inputLength = inputLen;
    pHsmSrvDesc->srvReq.mac.pTag = (HOST_ADDR)pCmac;
    pHsmSrvDesc->srvReq.mac.pTagLength = (HOST_ADDR)pCmaLen;
    pHsmSrvDesc->srvReq.mac.authDir = HSM_AUTH_DIR_VERIFY;
    pHsmSrvDesc->srvReq.mac.pVerifyResult = (HOST_ADDR)pVerifyStatus;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);

#if 0
    /* Request the service to HSM */
    status = HSM_RequestService(coreId, pHsmSrvDesc);
    if (STATUS_SUCCESS == status)
    {
    	*pVerifyStatus = TRUE;
    }
    else if (STATUS_HSM_VERIFY_FAILED == status)
    {
    	*pVerifyStatus = FALSE;
    	status = STATUS_SUCCESS;
    }
    else
    {
    	*pVerifyStatus = FALSE;
    }

    return status;
#endif
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesCmacVerify_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pCmac,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pCmaLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_MAC;
    pHsmSrvDesc->srvReq.mac.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.mac.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.mac.macScheme.macAlgo = HSM_MAC_ALGO_CMAC;
    pHsmSrvDesc->srvReq.mac.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.mac.inputLength = inputLen;
    pHsmSrvDesc->srvReq.mac.pTag = (HOST_ADDR)pCmac;
    pHsmSrvDesc->srvReq.mac.pTagLength = (HOST_ADDR)pCmaLen;
    pHsmSrvDesc->srvReq.mac.authDir = HSM_AUTH_DIR_VERIFY;
    pHsmSrvDesc->srvReq.mac.pVerifyResult = (HOST_ADDR)pVerifyStatus;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesEncrypt
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SYM_CIPHER;
    pHsmSrvDesc->srvReq.symCipher.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.symCipher.cipherAlgo = HSM_CIPHER_ALGO_AES;
    pHsmSrvDesc->srvReq.symCipher.cipherBlockMode = cipherBlockMode;
    pHsmSrvDesc->srvReq.symCipher.cipherStramBits = cipherStreamBits;
    pHsmSrvDesc->srvReq.symCipher.cipherDir = HSM_CIPHER_DIR_ENCRYPT;
    pHsmSrvDesc->srvReq.symCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.symCipher.pIV = (HOST_ADDR)pIV;
    pHsmSrvDesc->srvReq.symCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.symCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.symCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesEncrypt_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SYM_CIPHER;
    pHsmSrvDesc->srvReq.symCipher.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.symCipher.cipherAlgo = HSM_CIPHER_ALGO_AES;
    pHsmSrvDesc->srvReq.symCipher.cipherBlockMode = cipherBlockMode;
    pHsmSrvDesc->srvReq.symCipher.cipherStramBits = cipherStreamBits;
    pHsmSrvDesc->srvReq.symCipher.cipherDir = HSM_CIPHER_DIR_ENCRYPT;
    pHsmSrvDesc->srvReq.symCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.symCipher.pIV = (HOST_ADDR)pIV;
    pHsmSrvDesc->srvReq.symCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.symCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.symCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesDecrypt
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SYM_CIPHER;
    pHsmSrvDesc->srvReq.symCipher.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.symCipher.cipherAlgo = HSM_CIPHER_ALGO_AES;
    pHsmSrvDesc->srvReq.symCipher.cipherBlockMode = cipherBlockMode;
    pHsmSrvDesc->srvReq.symCipher.cipherStramBits = cipherStreamBits;
    pHsmSrvDesc->srvReq.symCipher.cipherDir = HSM_CIPHER_DIR_DECRYPT;
    pHsmSrvDesc->srvReq.symCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.symCipher.pIV = (HOST_ADDR)pIV;
    pHsmSrvDesc->srvReq.symCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.symCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.symCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesDecrypt_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SYM_CIPHER;
    pHsmSrvDesc->srvReq.symCipher.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.symCipher.cipherAlgo = HSM_CIPHER_ALGO_AES;
    pHsmSrvDesc->srvReq.symCipher.cipherBlockMode = cipherBlockMode;
    pHsmSrvDesc->srvReq.symCipher.cipherStramBits = cipherStreamBits;
    pHsmSrvDesc->srvReq.symCipher.cipherDir = HSM_CIPHER_DIR_DECRYPT;
    pHsmSrvDesc->srvReq.symCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.symCipher.pIV = (HOST_ADDR)pIV;
    pHsmSrvDesc->srvReq.symCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.symCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.symCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesAeadEncrypt
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmAuthCipherMode_t, AUTOMATIC) authCipherMode,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIv,
	VAR(uint32, AUTOMATIC) ivLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAad,
	VAR(uint32, AUTOMATIC) aadLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(hsmKeyHandle_t, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pTag,
	VAR(uint32, AUTOMATIC) tagLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_AEAD;
    pHsmSrvDesc->srvReq.aead.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.aead.cipherDir = HSM_CIPHER_DIR_ENCRYPT;
    pHsmSrvDesc->srvReq.aead.authCipherMode = authCipherMode;
    pHsmSrvDesc->srvReq.aead.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.aead.pIV = (HOST_ADDR)pIv;
    pHsmSrvDesc->srvReq.aead.ivLength = ivLen;
    pHsmSrvDesc->srvReq.aead.pAad = (HOST_ADDR)pAad;
    pHsmSrvDesc->srvReq.aead.aadLength = aadLen;
    pHsmSrvDesc->srvReq.aead.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.aead.inputLength = inputLen;
    pHsmSrvDesc->srvReq.aead.pTag = (HOST_ADDR)pTag;
    pHsmSrvDesc->srvReq.aead.tagLength = tagLen;
    pHsmSrvDesc->srvReq.aead.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesAeadEncrypt_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmAuthCipherMode_t, AUTOMATIC) authCipherMode,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIv,
	VAR(uint32, AUTOMATIC) ivLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAad,
	VAR(uint32, AUTOMATIC) aadLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(hsmKeyHandle_t, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pTag,
	VAR(uint32, AUTOMATIC) tagLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_AEAD;
    pHsmSrvDesc->srvReq.aead.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.aead.cipherDir = HSM_CIPHER_DIR_ENCRYPT;
    pHsmSrvDesc->srvReq.aead.authCipherMode = authCipherMode;
    pHsmSrvDesc->srvReq.aead.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.aead.pIV = (HOST_ADDR)pIv;
    pHsmSrvDesc->srvReq.aead.ivLength = ivLen;
    pHsmSrvDesc->srvReq.aead.pAad = (HOST_ADDR)pAad;
    pHsmSrvDesc->srvReq.aead.aadLength = aadLen;
    pHsmSrvDesc->srvReq.aead.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.aead.inputLength = inputLen;
    pHsmSrvDesc->srvReq.aead.pTag = (HOST_ADDR)pTag;
    pHsmSrvDesc->srvReq.aead.tagLength = tagLen;
    pHsmSrvDesc->srvReq.aead.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesAeadDecrypt
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmAuthCipherMode_t, AUTOMATIC) authCipherMode,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIv,
	VAR(uint32, AUTOMATIC) ivLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAad,
	VAR(uint32, AUTOMATIC) aadLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(hsmKeyHandle_t, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pTag,
	VAR(uint32, AUTOMATIC) tagLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_AEAD;
    pHsmSrvDesc->srvReq.aead.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.aead.cipherDir = HSM_CIPHER_DIR_DECRYPT;
    pHsmSrvDesc->srvReq.aead.authCipherMode = authCipherMode;
    pHsmSrvDesc->srvReq.aead.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.aead.pIV = (HOST_ADDR)pIv;
    pHsmSrvDesc->srvReq.aead.ivLength = ivLen;
    pHsmSrvDesc->srvReq.aead.pAad = (HOST_ADDR)pAad;
    pHsmSrvDesc->srvReq.aead.aadLength = aadLen;
    pHsmSrvDesc->srvReq.aead.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.aead.inputLength = inputLen;
    pHsmSrvDesc->srvReq.aead.pTag = (HOST_ADDR)pTag;
    pHsmSrvDesc->srvReq.aead.tagLength = tagLen;
    pHsmSrvDesc->srvReq.aead.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesAeadDecrypt_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmAuthCipherMode_t, AUTOMATIC) authCipherMode,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIv,
	VAR(uint32, AUTOMATIC) ivLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAad,
	VAR(uint32, AUTOMATIC) aadLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(hsmKeyHandle_t, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pTag,
	VAR(uint32, AUTOMATIC) tagLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_AEAD;
    pHsmSrvDesc->srvReq.aead.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.aead.cipherDir = HSM_CIPHER_DIR_DECRYPT;
    pHsmSrvDesc->srvReq.aead.authCipherMode = authCipherMode;
    pHsmSrvDesc->srvReq.aead.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.aead.pIV = (HOST_ADDR)pIv;
    pHsmSrvDesc->srvReq.aead.ivLength = ivLen;
    pHsmSrvDesc->srvReq.aead.pAad = (HOST_ADDR)pAad;
    pHsmSrvDesc->srvReq.aead.aadLength = aadLen;
    pHsmSrvDesc->srvReq.aead.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.aead.inputLength = inputLen;
    pHsmSrvDesc->srvReq.aead.pTag = (HOST_ADDR)pTag;
    pHsmSrvDesc->srvReq.aead.tagLength = tagLen;
    pHsmSrvDesc->srvReq.aead.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm4Encrypt
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SYM_CIPHER;
    pHsmSrvDesc->srvReq.symCipher.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.symCipher.cipherAlgo = HSM_CIPHER_ALGO_SM4;
    pHsmSrvDesc->srvReq.symCipher.cipherBlockMode = cipherBlockMode;
    pHsmSrvDesc->srvReq.symCipher.cipherStramBits = cipherStreamBits;
    pHsmSrvDesc->srvReq.symCipher.cipherDir = HSM_CIPHER_DIR_ENCRYPT;
    pHsmSrvDesc->srvReq.symCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.symCipher.pIV = (HOST_ADDR)pIV;
    pHsmSrvDesc->srvReq.symCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.symCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.symCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm4Encrypt_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SYM_CIPHER;
    pHsmSrvDesc->srvReq.symCipher.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.symCipher.cipherAlgo = HSM_CIPHER_ALGO_SM4;
    pHsmSrvDesc->srvReq.symCipher.cipherBlockMode = cipherBlockMode;
    pHsmSrvDesc->srvReq.symCipher.cipherStramBits = cipherStreamBits;
    pHsmSrvDesc->srvReq.symCipher.cipherDir = HSM_CIPHER_DIR_ENCRYPT;
    pHsmSrvDesc->srvReq.symCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.symCipher.pIV = (HOST_ADDR)pIV;
    pHsmSrvDesc->srvReq.symCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.symCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.symCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm4Decrypt
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SYM_CIPHER;
    pHsmSrvDesc->srvReq.symCipher.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.symCipher.cipherAlgo = HSM_CIPHER_ALGO_SM4;
    pHsmSrvDesc->srvReq.symCipher.cipherBlockMode = cipherBlockMode;
    pHsmSrvDesc->srvReq.symCipher.cipherStramBits = cipherStreamBits;
    pHsmSrvDesc->srvReq.symCipher.cipherDir = HSM_CIPHER_DIR_DECRYPT;
    pHsmSrvDesc->srvReq.symCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.symCipher.pIV = (HOST_ADDR)pIV;
    pHsmSrvDesc->srvReq.symCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.symCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.symCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm4Decrypt_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SYM_CIPHER;
    pHsmSrvDesc->srvReq.symCipher.optMode = (hsmOperationMode_t)eOptMode;
    pHsmSrvDesc->srvReq.symCipher.cipherAlgo = HSM_CIPHER_ALGO_SM4;
    pHsmSrvDesc->srvReq.symCipher.cipherBlockMode = cipherBlockMode;
    pHsmSrvDesc->srvReq.symCipher.cipherStramBits = cipherStreamBits;
    pHsmSrvDesc->srvReq.symCipher.cipherDir = HSM_CIPHER_DIR_DECRYPT;
    pHsmSrvDesc->srvReq.symCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.symCipher.pIV = (HOST_ADDR)pIV;
    pHsmSrvDesc->srvReq.symCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.symCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.symCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15Encrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_RSA_CIPHER;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.rsaAlgo = HSM_RSA_ALGO_RSAES_PKCS1_V15;
    pHsmSrvDesc->srvReq.rsaCipher.cipherDir = HSM_CIPHER_DIR_ENCRYPT;
    pHsmSrvDesc->srvReq.rsaCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.rsaCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.rsaCipher.pOutputLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15Encrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_RSA_CIPHER;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.rsaAlgo = HSM_RSA_ALGO_RSAES_PKCS1_V15;
    pHsmSrvDesc->srvReq.rsaCipher.cipherDir = HSM_CIPHER_DIR_ENCRYPT;
    pHsmSrvDesc->srvReq.rsaCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.rsaCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.rsaCipher.pOutputLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15Decrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_RSA_CIPHER;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.rsaAlgo = HSM_RSA_ALGO_RSAES_PKCS1_V15;
    pHsmSrvDesc->srvReq.rsaCipher.cipherDir = HSM_CIPHER_DIR_DECRYPT;
    pHsmSrvDesc->srvReq.rsaCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.rsaCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.rsaCipher.pOutputLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15Decrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_RSA_CIPHER;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.rsaAlgo = HSM_RSA_ALGO_RSAES_PKCS1_V15;
    pHsmSrvDesc->srvReq.rsaCipher.cipherDir = HSM_CIPHER_DIR_DECRYPT;
    pHsmSrvDesc->srvReq.rsaCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.rsaCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.rsaCipher.pOutputLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaNoPaddEncrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_RSA_CIPHER;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.rsaAlgo = HSM_RSA_ALGO_NO_PADDING;
    pHsmSrvDesc->srvReq.rsaCipher.cipherDir = HSM_CIPHER_DIR_ENCRYPT;
    pHsmSrvDesc->srvReq.rsaCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.rsaCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.rsaCipher.pOutputLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaNoPaddDecrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_RSA_CIPHER;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.rsaAlgo = HSM_RSA_ALGO_NO_PADDING;
    pHsmSrvDesc->srvReq.rsaCipher.cipherDir = HSM_CIPHER_DIR_DECRYPT;
    pHsmSrvDesc->srvReq.rsaCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.rsaCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.rsaCipher.pOutputLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);

}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaNoPaddEncrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_RSA_CIPHER;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.rsaAlgo = HSM_RSA_ALGO_NO_PADDING;
    pHsmSrvDesc->srvReq.rsaCipher.cipherDir = HSM_CIPHER_DIR_ENCRYPT;
    pHsmSrvDesc->srvReq.rsaCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.rsaCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.rsaCipher.pOutputLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaNoPaddDecrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_RSA_CIPHER;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.rsaAlgo = HSM_RSA_ALGO_NO_PADDING;
    pHsmSrvDesc->srvReq.rsaCipher.cipherDir = HSM_CIPHER_DIR_DECRYPT;
    pHsmSrvDesc->srvReq.rsaCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.rsaCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.rsaCipher.pOutputLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);

}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaOAEPEncrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_RSA_CIPHER;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.rsaAlgo = HSM_RSA_ALGO_RSAES_OAEP;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.sch.rsaOeap.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.sch.rsaOeap.labelLength = 0;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.sch.rsaOeap.pLabel = NULL;
    pHsmSrvDesc->srvReq.rsaCipher.cipherDir = HSM_CIPHER_DIR_ENCRYPT;
    pHsmSrvDesc->srvReq.rsaCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.rsaCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.rsaCipher.pOutputLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaOAEPDecrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_RSA_CIPHER;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.rsaAlgo = HSM_RSA_ALGO_RSAES_OAEP;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.sch.rsaOeap.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.sch.rsaOeap.labelLength = 0;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.sch.rsaOeap.pLabel = NULL;
    pHsmSrvDesc->srvReq.rsaCipher.cipherDir = HSM_CIPHER_DIR_DECRYPT;
    pHsmSrvDesc->srvReq.rsaCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.rsaCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.rsaCipher.pOutputLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaOAEPEncrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_RSA_CIPHER;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.rsaAlgo = HSM_RSA_ALGO_RSAES_OAEP;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.sch.rsaOeap.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.sch.rsaOeap.labelLength = 0;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.sch.rsaOeap.pLabel = NULL;
    pHsmSrvDesc->srvReq.rsaCipher.cipherDir = HSM_CIPHER_DIR_ENCRYPT;
    pHsmSrvDesc->srvReq.rsaCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.rsaCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.rsaCipher.pOutputLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaOAEPDecrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_RSA_CIPHER;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.rsaAlgo = HSM_RSA_ALGO_RSAES_OAEP;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.sch.rsaOeap.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.sch.rsaOeap.labelLength = 0;
    pHsmSrvDesc->srvReq.rsaCipher.rsaScheme.sch.rsaOeap.pLabel = NULL;
    pHsmSrvDesc->srvReq.rsaCipher.cipherDir = HSM_CIPHER_DIR_DECRYPT;
    pHsmSrvDesc->srvReq.rsaCipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.rsaCipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.rsaCipher.pOutputLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.rsaCipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15GenerateSignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_GENERATE;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_RSASSA_PKCS1_V15;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.rsaPkcs1v15.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignature;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureLen;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPssGenerateSignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	VAR(uint32, AUTOMATIC) saltLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_GENERATE;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_RSASSA_PSS;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.rsaPkcs1v15.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.rsaPss.saltLength = saltLen;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignature;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureLen;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPssVerifySignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	VAR(uint32, AUTOMATIC) saltLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_VERIFY;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_RSASSA_PSS;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.rsaPkcs1v15.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.rsaPss.saltLength = saltLen;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignature;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureLen;
    pHsmSrvDesc->srvReq.sign.pVerifyResault = (HOST_ADDR)pVerifyStatus;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPssGenerateSignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	VAR(uint32, AUTOMATIC) saltLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_GENERATE;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_RSASSA_PSS;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.rsaPkcs1v15.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.rsaPss.saltLength = saltLen;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignature;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureLen;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPssVerifySignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	VAR(uint32, AUTOMATIC) saltLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_VERIFY;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_RSASSA_PSS;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.rsaPkcs1v15.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.rsaPss.saltLength = saltLen;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignature;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureLen;
    pHsmSrvDesc->srvReq.sign.pVerifyResault = (HOST_ADDR)pVerifyStatus;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15GenerateSignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_GENERATE;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_RSASSA_PKCS1_V15;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.rsaPkcs1v15.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignature;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureLen;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15VerifySignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA)pVerifyStatus
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_VERIFY;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_RSASSA_PKCS1_V15;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.rsaPkcs1v15.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignature;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureLen;
    pHsmSrvDesc->srvReq.sign.pVerifyResault = (HOST_ADDR)pVerifyStatus;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
#if 0
    /* Request the service to HSM */
    status = HSM_RequestService(coreId, pHsmSrvDesc);
    if (STATUS_SUCCESS == status)
    {
    	*pVerifyStatus = TRUE;
    }
    else if (STATUS_HSM_VERIFY_FAILED == status)
    {
    	*pVerifyStatus = FALSE;
    	status = STATUS_SUCCESS;
    }
    else
    {
    	*pVerifyStatus = FALSE;
    }

    return status;
#endif
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15VerifySignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA)pVerifyStatus
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_VERIFY;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_RSASSA_PKCS1_V15;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.rsaPkcs1v15.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignature;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureLen;
    pHsmSrvDesc->srvReq.sign.pVerifyResault = (HOST_ADDR)pVerifyStatus;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2Encrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    s_hsmSrvDesc.srvCmd = HSM_SRV_CMD_SM2_CIPHER;
    s_hsmSrvDesc.srvReq.sm2Cipher.cipherDir = HSM_CIPHER_DIR_ENCRYPT;
    s_hsmSrvDesc.srvReq.sm2Cipher.keyHandle = keyHandle;
    s_hsmSrvDesc.srvReq.sm2Cipher.inputLength = inputLen;
    s_hsmSrvDesc.srvReq.sm2Cipher.pInput = (HOST_ADDR)pInput;
    s_hsmSrvDesc.srvReq.sm2Cipher.pOutputLength = (HOST_ADDR)pOutputLen;
    s_hsmSrvDesc.srvReq.sm2Cipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2Encrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    s_hsmSrvDesc.srvCmd = HSM_SRV_CMD_SM2_CIPHER;
    s_hsmSrvDesc.srvReq.sm2Cipher.cipherDir = HSM_CIPHER_DIR_ENCRYPT;
    s_hsmSrvDesc.srvReq.sm2Cipher.keyHandle = keyHandle;
    s_hsmSrvDesc.srvReq.sm2Cipher.inputLength = inputLen;
    s_hsmSrvDesc.srvReq.sm2Cipher.pInput = (HOST_ADDR)pInput;
    s_hsmSrvDesc.srvReq.sm2Cipher.pOutputLength = (HOST_ADDR)pOutputLen;
    s_hsmSrvDesc.srvReq.sm2Cipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2Decrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SM2_CIPHER;
    pHsmSrvDesc->srvReq.sm2Cipher.cipherDir = HSM_CIPHER_DIR_DECRYPT;
    pHsmSrvDesc->srvReq.sm2Cipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sm2Cipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sm2Cipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sm2Cipher.pOutputLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.sm2Cipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2Decrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SM2_CIPHER;
    pHsmSrvDesc->srvReq.sm2Cipher.cipherDir = HSM_CIPHER_DIR_DECRYPT;
    pHsmSrvDesc->srvReq.sm2Cipher.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sm2Cipher.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sm2Cipher.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sm2Cipher.pOutputLength = (HOST_ADDR)pOutputLen;
    pHsmSrvDesc->srvReq.sm2Cipher.pOutput = (HOST_ADDR)pOutput;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2GenerateSignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_GENERATE;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_SM2;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignatureR;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureRLen;
    pHsmSrvDesc->srvReq.sign.pSignature[1] = (HOST_ADDR)pSignatureS;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[1] = (HOST_ADDR)pSignatureSLen;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2GenerateSignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_GENERATE;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_SM2;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignatureR;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureRLen;
    pHsmSrvDesc->srvReq.sign.pSignature[1] = (HOST_ADDR)pSignatureS;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[1] = (HOST_ADDR)pSignatureSLen;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2VerifySignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_VERIFY;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_SM2;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignatureR;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureRLen;
    pHsmSrvDesc->srvReq.sign.pSignature[1] = (HOST_ADDR)pSignatureS;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[1] = (HOST_ADDR)pSignatureSLen;
    pHsmSrvDesc->srvReq.sign.pVerifyResault = (HOST_ADDR)pVerifyStatus;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
#if 0
    /* Request the service to HSM */
    status = HSM_RequestService(coreId, pHsmSrvDesc);
    if (STATUS_SUCCESS == status)
    {
    	*pVerifyStatus = TRUE;
    }
    else if (STATUS_HSM_VERIFY_FAILED == status)
    {
    	*pVerifyStatus = FALSE;
    	status = STATUS_SUCCESS;
    }
    else
    {
    	*pVerifyStatus = FALSE;
    }

    return status;
#endif
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2VerifySignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_VERIFY;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_SM2;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignatureR;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureRLen;
    pHsmSrvDesc->srvReq.sign.pSignature[1] = (HOST_ADDR)pSignatureS;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[1] = (HOST_ADDR)pSignatureSLen;
    pHsmSrvDesc->srvReq.sign.pVerifyResault = (HOST_ADDR)pVerifyStatus;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ED25519GenerateSignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRs,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRsLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen
)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
	hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

	/* Prepare the service */
	cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

	pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
	pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
	pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_GENERATE;
	pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
	pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_ED_25519;
	pHsmSrvDesc->srvReq.sign.signScheme.sch.ed25519.hashAlgo = hashAlgo;
	pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
	pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
	pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
	pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignatureRs;
	pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureRsLen;
	pHsmSrvDesc->srvReq.sign.pSignature[1] = (HOST_ADDR)pSignatureS;
	pHsmSrvDesc->srvReq.sign.pSignatureLength[1] = (HOST_ADDR)pSignatureSLen;

	/* Request the service to HSM */
	return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_EcdsaGenerateSignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_GENERATE;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_ECDSA;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.ecdsa.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignatureR;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureRLen;
    pHsmSrvDesc->srvReq.sign.pSignature[1] = (HOST_ADDR)pSignatureS;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[1] = (HOST_ADDR)pSignatureSLen;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_EcdsaGenerateSignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_GENERATE;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_ECDSA;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.ecdsa.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignatureR;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureRLen;
    pHsmSrvDesc->srvReq.sign.pSignature[1] = (HOST_ADDR)pSignatureS;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[1] = (HOST_ADDR)pSignatureSLen;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ED25519VerifySignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRs,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRsLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
	hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

	/* Prepare the service */
	cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_VERIFY;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_ED_25519;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.ed25519.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignatureRs;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureRsLen;
    pHsmSrvDesc->srvReq.sign.pSignature[1] = (HOST_ADDR)pSignatureS;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[1] = (HOST_ADDR)pSignatureSLen;
    pHsmSrvDesc->srvReq.sign.pVerifyResault = (HOST_ADDR)pVerifyStatus;


	/* Request the service to HSM */
	return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_EcdsaVerifySignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_VERIFY;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_ECDSA;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.ecdsa.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignatureR;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureRLen;
    pHsmSrvDesc->srvReq.sign.pSignature[1] = (HOST_ADDR)pSignatureS;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[1] = (HOST_ADDR)pSignatureSLen;
    pHsmSrvDesc->srvReq.sign.pVerifyResault = (HOST_ADDR)pVerifyStatus;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
#if 0
    /* Request the service to HSM */
    status = HSM_RequestService(coreId, pHsmSrvDesc);
    if (STATUS_SUCCESS == status)
    {
    	*pVerifyStatus = TRUE;
    }
    else if (STATUS_HSM_VERIFY_FAILED == status)
    {
    	*pVerifyStatus = FALSE;
    	status = STATUS_SUCCESS;
    }
    else
    {
    	*pVerifyStatus = FALSE;
    }

    return status;
#endif
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_EcdsaVerifySignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_SIGN;
    pHsmSrvDesc->srvReq.sign.optMode = HSM_OPERATION_MODE_SINGLE_CALL;
    pHsmSrvDesc->srvReq.sign.authDir = HSM_AUTH_DIR_VERIFY;
    pHsmSrvDesc->srvReq.sign.keyHandle = keyHandle;
    pHsmSrvDesc->srvReq.sign.signScheme.signSch = HSM_SIGN_ECDSA;
    pHsmSrvDesc->srvReq.sign.signScheme.sch.ecdsa.hashAlgo = hashAlgo;
    pHsmSrvDesc->srvReq.sign.pInput = (HOST_ADDR)pInput;
    pHsmSrvDesc->srvReq.sign.inputLength = inputLen;
    pHsmSrvDesc->srvReq.sign.bInputIsHashed = isInputHashed;
    pHsmSrvDesc->srvReq.sign.pSignature[0] = (HOST_ADDR)pSignatureR;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[0] = (HOST_ADDR)pSignatureRLen;
    pHsmSrvDesc->srvReq.sign.pSignature[1] = (HOST_ADDR)pSignatureS;
    pHsmSrvDesc->srvReq.sign.pSignatureLength[1] = (HOST_ADDR)pSignatureSLen;
    pHsmSrvDesc->srvReq.sign.pVerifyResault = (HOST_ADDR)pVerifyStatus;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_WriteUseData
(
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pData,
	VAR(uint32, AUTOMATIC) length,
	VAR(uint32, AUTOMATIC) offset,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    s_hsmSrvDesc.srvCmd = HSM_SRV_CMD_WRITE_USER_DATA;
    s_hsmSrvDesc.srvReq.userDataRW.keyHandle = keyHandle;
    s_hsmSrvDesc.srvReq.userDataRW.pData = (HOST_ADDR)pData;
    s_hsmSrvDesc.srvReq.userDataRW.offset = offset;
    s_hsmSrvDesc.srvReq.userDataRW.length = length;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ReadUseData
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pData,
	VAR(uint32, AUTOMATIC) length,
	VAR(uint32, AUTOMATIC) offset,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle
)
{
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8 *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    s_hsmSrvDesc.srvCmd = HSM_SRV_CMD_READ_USER_DATA;
    s_hsmSrvDesc.srvReq.userDataRW.keyHandle = keyHandle;
    s_hsmSrvDesc.srvReq.userDataRW.pData = (HOST_ADDR)pData;
    s_hsmSrvDesc.srvReq.userDataRW.offset = offset;
    s_hsmSrvDesc.srvReq.userDataRW.length = length;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) HSM_LLD_IRQHandler
(
	VAR(uint32, AUTOMATIC) coreId
)
{
	HSM.HSM_FLAG = 1UL << coreId;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateInit(void)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    s_hsmSrvDesc.srvCmd = HSM_SRV_CMD_FW_UPDATA_INIT;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateInit_Async(void)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    s_hsmSrvDesc.srvCmd = HSM_SRV_CMD_FW_UPDATA_INIT;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


/*
 * @brief Prepare some init job before firmware update.
 * @param[in] fwImage: Pointer to the firmware image.
 * @param[in] fwLength: The length of firmware image.
 * @param[in] fwOffset: The offset of .
 * @return Error Code after command execution.
 */

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateProcess
(
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pFwImage,
	VAR(uint32, AUTOMATIC) fwLength,
	VAR(uint32, AUTOMATIC) fwOffset
)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    s_hsmSrvDesc.srvCmd = HSM_SRV_CMD_FW_UPDATE_PROCESS;
    s_hsmSrvDesc.srvReq.fwUpdate.pInFwData = (HOST_ADDR)pFwImage;
    s_hsmSrvDesc.srvReq.fwUpdate.fwOffset = fwOffset;
    s_hsmSrvDesc.srvReq.fwUpdate.fwLength = fwLength;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateProcess_Async
(
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pFwImage,
	VAR(uint32, AUTOMATIC) fwLength,
	VAR(uint32, AUTOMATIC) fwOffset
)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    s_hsmSrvDesc.srvCmd = HSM_SRV_CMD_FW_UPDATE_PROCESS;
    s_hsmSrvDesc.srvReq.fwUpdate.pInFwData = (HOST_ADDR)pFwImage;
    s_hsmSrvDesc.srvReq.fwUpdate.fwOffset = fwOffset;
    s_hsmSrvDesc.srvReq.fwUpdate.fwLength = fwLength;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


/*!
 * @brief Prepare some init job before firmware update.
 * @param[in] fwLength: The length of data to be readed.
 * @param[in] key: The key used to calc mac.
 * @param[in] mac: The calculed mac.
 * @return Error Code after command execution.
 */

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateFinal_New
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(uint32_t, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac
)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    s_hsmSrvDesc.srvCmd = HSM_SRV_CMD_FW_UPDATE_FINAL;
    s_hsmSrvDesc.srvReq.fwFinalNew.pVerifyKeyHandle = keyHandle;
    s_hsmSrvDesc.srvReq.fwFinalNew.fwLength = fwLength;
    s_hsmSrvDesc.srvReq.fwFinalNew.pVerifyMac = (HOST_ADDR)mac;

    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateFinal2
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(uint32_t, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) dVer,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) stDycode,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) runDycode,
	VAR(uint32, AUTOMATIC) codeLength
)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    s_hsmSrvDesc.srvCmd = HSM_SRV_CMD_FW_UPDATE_FINAL;
    s_hsmSrvDesc.srvReq.fwFinalNew.pVerifyKeyHandle = keyHandle;
    s_hsmSrvDesc.srvReq.fwFinalNew.fwLength = fwLength;
    s_hsmSrvDesc.srvReq.fwFinalNew.pVerifyMac = (HOST_ADDR)mac;

    if(dVer)
    {
    	s_hsmSrvDesc.srvReq.fwFinalNew.dverValid = 0xA1B2C311;		/*DVER_VALID_FLAG*/
    	s_hsmSrvDesc.srvReq.fwFinalNew.dverAddr = (HOST_ADDR)dVer;
    }
    if(stDycode && runDycode && codeLength)
    {
    	s_hsmSrvDesc.srvReq.fwFinalNew.codeValid = 0xA1B2C310;		/*DYCODE_VALID_FLAG*/
    	s_hsmSrvDesc.srvReq.fwFinalNew.stCodeAddr = (HOST_ADDR)stDycode;
    	s_hsmSrvDesc.srvReq.fwFinalNew.dyCodeAddr = (HOST_ADDR)runDycode;
    	s_hsmSrvDesc.srvReq.fwFinalNew.codeLength = codeLength;
    }
    /* Request the service to HSM */
    return HSM_RequestService(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateFinal_Async
(
	VAR(uint32, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) key,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac
)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    s_hsmSrvDesc.srvCmd = HSM_SRV_CMD_FW_UPDATE_FINAL;
    s_hsmSrvDesc.srvReq.fwFinal.fwLength = fwLength;
    s_hsmSrvDesc.srvReq.fwFinal.pVerifyKey = (HOST_ADDR)key;
    s_hsmSrvDesc.srvReq.fwFinal.pVerifyMac = (HOST_ADDR)mac;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateFinal_Async_New
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(uint32_t, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac
)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));

    s_hsmSrvDesc.srvCmd = HSM_SRV_CMD_FW_UPDATE_FINAL;
    s_hsmSrvDesc.srvReq.fwFinalNew.pVerifyKeyHandle = keyHandle;
    s_hsmSrvDesc.srvReq.fwFinalNew.fwLength = fwLength;
    s_hsmSrvDesc.srvReq.fwFinalNew.pVerifyMac = (HOST_ADDR)mac;

    /* Request the service to HSM */
    return HSM_RequestService_Async(coreId, pHsmSrvDesc);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_CheckServiceResponce(void)
{
	Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    status_t status = STATUS_SUCCESS;

    if (TRUE != HSM_IsResponseReady(coreId))
    {
        status = STATUS_BUSY;
    }

    if (STATUS_SUCCESS == status)
    {
        if (0U != HSM.HSM_STATUS)
        {
            status = (status_t)(((HSM.HSM_STATUS & 0xFFFF0000U) >> 16U) | HSM_ERC_OFFSET); /* PRQA S 4342, 4394 */
        }
#ifdef DCACHE_ENABLE /* cyh */
        /* NOTE: up to MCAL V3.0.8(or later), cache operation will use new API */
		#if (1 == SUPPORT_NEW_CACHE_API)
			Mcu_Cache_InitUncacheRegion();
		#else
			CACHE_LLD_InvalidateDcache();
		#endif
#endif
    }

    return status;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_CheckServiceResponce(void)
{
	return HSM_CheckServiceResponce();
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RamWait_S0
(
	P2VAR(volatile uint32_t, AUTOMATIC, CRYPTO_APPL_DATA) checkaddr,
	VAR(uint32_t, AUTOMATIC) ram_timeout
)
{
    status_t status = STATUS_SUCCESS;
    uint32_t timeout = HSE_OPERATION_TIMEOUT;
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    hsmSrvDescriptor_t *pHsmSrvDesc = &s_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(hsmSrvDescriptor_t));
    *checkaddr = 0xa100b200U;
    /* Prepare the service */
    pHsmSrvDesc->srvCmd = HSM_SRV_CMD_RAMWAIT;
    pHsmSrvDesc->srvReq.ramWait.checkaddr = checkaddr;
    pHsmSrvDesc->srvReq.ramWait.timeout = ram_timeout;

    /* Request the service to HSM */
    status = HSM_RequestService_Async(coreId, pHsmSrvDesc);

    while(( *checkaddr != 0xa101b201U )&&( timeout > 0U ))
    {
    	timeout--;
    }

    if (0UL == timeout)
    {
           status = STATUS_TIMEOUT;
    }

    return status;

}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RamWait_S1
(
		P2VAR(volatile uint32_t, AUTOMATIC, CRYPTO_APPL_DATA) checkaddr
)
{
    status_t status = STATUS_SUCCESS;

    *checkaddr = 0xa102b202U;
    /* Request the service to HSM */
    do{
    	status = HSM_CheckServiceResponce();
    }while(status == STATUS_BUSY);
    return status;

}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RamWait_S1_Err(void)
{
    status_t status = STATUS_SUCCESS;

    /* Request the service to HSM */
    do{
    	status = HSM_CheckServiceResponce();
    }while(status == STATUS_BUSY);
    return status;

}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

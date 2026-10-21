/****************************************************************************
*
* Copyright (c) 2024  C*Core -   All Rights Reserved
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
*   @file    Crypto_AutoSar_Extension.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Crypto MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/
/*PRQA S 0380, 0389, 1842, 1840, 1281, 4543, 4393 EOF*/
/*PRQA S 1863, 3432, 1330, 2016, 4391, 4397, 4399, 2214, 0580 EOF*/
#ifdef __cplusplus
extern "C"{
#endif

#include "Crypto.h"
#include "Crypto_common.h"
#include "Crypto_AutoSar_Externsion.h"
#include "derivative.h"
#include "Mcal.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
static void HostFlash_ProgramUnlock(uint32_t flashAddr)
{
    uint32_t i, lockReg = 0, lockbit = 0;

    for (i = 0; i < FLS_BLOCK_ALL; i++)
    {
        if ((flashAddr >= flashInfo[i].addrStart) && (flashAddr < flashInfo[i].addrEnd))
        {
            lockReg = flashInfo[i].lockSelReg;
            lockbit = flashInfo[i].lockSelBit;
            break;
        }
    }

    if (0U == lockbit)
    {
        return;
    }

    if((flashAddr >= 0x700000U) && (flashAddr <= 0x73BFFFU)) {
        *(uint8_t*)(0xFFFE0000U + 0x1FCU) = 0x20U;
        *(uint8_t*)(0xFFFE0000U + 0x1FDU) = 0x22U;
        *(uint8_t*)(0xFFFE0000U + 0x1FEU) = 0x08U;
        *(uint8_t*)(0xFFFE0000U + 0x1FFU) = 0x01U;

        switch(lockReg) {
        case 0:
            C55FMC.LOCK0.R |= (uint32_t)(0x1U << lockbit);
            break;
        case 1:
            C55FMC.LOCK1.R |= (uint32_t)(0x1U << lockbit);
            break;
        case 2:
            C55FMC.LOCK2.R |= (uint32_t)(0x1U << lockbit);
            break;
        case 3:
            C55FMC.LOCK3.R |= (uint32_t)(0x1U << lockbit);
            break;
        default:
			/*Nothing todo*/
            break;
        }
    } else {
        switch(lockReg) {
        case 0:
            C55FMC.LOCK0.R &= (uint32_t)(~(uint32_t)(0x1U << lockbit));
            break;
        case 1:
            C55FMC.LOCK1.R &= (uint32_t)(~(uint32_t)(0x1U << lockbit));
            break;
        case 2:
            C55FMC.LOCK2.R &= (uint32_t)(~(uint32_t)(0x1U << lockbit));
            break;
        case 3:
            C55FMC.LOCK3.R &= (uint32_t)(~(uint32_t)(0x1U << lockbit));
            break;
        default:
		 	/*Nothing todo*/
            break;
        }
    }
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
static void HostFlash_Programlock(uint32_t flashAddr)
{
    uint32_t i, lockReg = 0U, lockbit = 0U;

    for (i = 0U; i < FLS_BLOCK_ALL; i++)
    {
        if ((flashAddr >= flashInfo[i].addrStart) && (flashAddr < flashInfo[i].addrEnd))
        {
            lockReg = flashInfo[i].lockSelReg;
            lockbit = flashInfo[i].lockSelBit;
            break;
        }
    }

    if (0u == lockbit)
    {
        return;
    }

    if ((flashAddr >= 0x700000U) && (flashAddr <= 0x73BFFFU)) {
        *(uint8_t*)(0xFFFE0000U + 0x1FCU) = 0x20U;
        *(uint8_t*)(0xFFFE0000U + 0x1FDU) = 0x22U;
        *(uint8_t*)(0xFFFE0000U + 0x1FEU) = 0x08U;
        *(uint8_t*)(0xFFFE0000U + 0x1FFU) = 0x01U;

        switch(lockReg) {
        case 0:
            C55FMC.LOCK0.R &= (uint32_t)(~(0x1U << lockbit));
            break;
        case 1:
            C55FMC.LOCK1.R &= (uint32_t)(~(0x1U << lockbit));
            break;
        case 2:
            C55FMC.LOCK2.R &= (uint32_t)(~(0x1U << lockbit));
            break;
        case 3:
            C55FMC.LOCK3.R &= (uint32_t)(~(0x1U << lockbit));
            break;
        default:
			/*Nothing todo*/
            break;
        }
    } else {
        switch(lockReg) {
        case 0:
            C55FMC.LOCK0.R |= (uint32_t)(0x1U  << lockbit);
            break;
        case 1:
            C55FMC.LOCK1.R |= (uint32_t)(0x1U  << lockbit);
            break;
        case 2:
            C55FMC.LOCK2.R |= (uint32_t)(0x1U  << lockbit);
            break;
        case 3:
            C55FMC.LOCK3.R |= (uint32_t)(0x1U  << lockbit);
            break;
        default:
			/*Nothing todo*/
            break;
        }
    }
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
static void HostFlash_DoubleWordWrite(uint32_t flashAddr, uint64_t writeData)
{
	VAR(uint32, AUTOMATIC) Crypto_Timeout = 0U;
    if ((flashAddr & 0x7u) != 0u)
    {
        return;
    }
    HostFlash_ProgramUnlock(flashAddr);
    C55FMC.MCR.B.PGM = 1;
    *(uint64_t*)flashAddr = writeData;/* polyspace RTE:IDP */
    C55FMC.MCR.B.EHV = 1;
    while((C55FMC.MCR.B.DONE == 0) && (Crypto_Timeout < DEFAULT_TIMEOUT))
	{
		Crypto_Timeout++;
	}
    C55FMC.MCR.B.EHV = 0;
    C55FMC.MCR.B.PGM = 0;

    HostFlash_Programlock(flashAddr);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ReadHsmVersion
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pVersion,
	VAR(uint32, AUTOMATIC) versionLen
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status = HSM_LLD_GetVersion(pVersion, versionLen);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_GetCounter
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pCounter,
	VAR(uint32, AUTOMATIC) counterLen
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status = HSM_LLD_GetCounter(pCounter, counterLen);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ReadHsmStack
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) Stack,
	VAR(uint32, AUTOMATIC) Len
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status = HSM_LLD_GetStack(Stack, Len);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ReadHsmDataVersion
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pVersion,
	VAR(uint32, AUTOMATIC) versionLen
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status = HSM_LLD_GetDataVersion(pVersion, versionLen);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ReadBootType
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pType,
	VAR(uint32, AUTOMATIC) typeLen
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status = HSM_LLD_GetBootType(pType, typeLen);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ReadSmrEntry
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSmrEntry,
	VAR(uint32, AUTOMATIC) SmrEntryLen
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status = HSM_LLD_GetSmrEntry(pSmrEntry, SmrEntryLen);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_DevAuthReq
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
    VAR(hsmDevAuthOption_t, AUTOMATIC) devAuthOption,
	P2VAR(hsmAuthScheme_t, AUTOMATIC, CRYPTO_APPL_DATA) pAuthScheme,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pChallenge
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status = HSM_LLD_DevAuthReq(devAuthOption, keyHandle, pAuthScheme, pChallenge);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_DevAuthResp
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAuth0,
	VAR(uint32, AUTOMATIC) auth0Len,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAuth1,
	VAR(uint32, AUTOMATIC) auth1Len
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status = HSM_LLD_DevAuthResp(pAuth0, auth0Len, pAuth1, auth1Len);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_DevAuthRst
(
	VAR(hsmDevAuthOption_t, AUTOMATIC) devAuthOption
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status = HSM_LLD_DevAuthRst(devAuthOption);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_WriteUserData
(
	P2CONST(uint8, AUTOMATIC, CRYPTO_CONST) pData,
	VAR(uint32, AUTOMATIC) len,
	VAR(uint32, AUTOMATIC) offset,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status = HSM_LLD_WriteUseData(pData, len, offset, keyHandle);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ReadUserData
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pData,
	VAR(uint32, AUTOMATIC) len,
	VAR(uint32, AUTOMATIC) offset,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status = HSM_LLD_ReadUseData(pData, len, offset, keyHandle);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ConfigSecureBoot
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
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status = HSM_LLD_ConfigSecureBoot(bootType, authKeyHandle, op,xoscConfigData,
									  pCodeSegs, pSign, segcnt,
									  bootZ4_2, bootZ7_0, bootZ7_1);

	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_ConfigSecureBoot_SWP
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
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status = HSM_LLD_ConfigSecureBoot_SWP(bootType, authKeyHandle, op,xoscConfigData,
									  pCodeSegs, pSwpCodeSegs, pSign,pSwpSign,segcnt,
									  bootZ4_2, bootZ7_0, bootZ7_1);

	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_InstallSmrEntry
(
	VAR(uint8, AUTOMATIC) bootCore,
	VAR(hsmSecureBootType_t, AUTOMATIC) bootType,
	VAR(hsmSecureBootFailOp_t, AUTOMATIC) op,
	P2VAR(xoscClkCofigData_t, AUTOMATIC, CRYPTO_APPL_DATA) xoscConfigData,
	VAR(uint32, AUTOMATIC) smrCnt,
	P2VAR(hsmSmrEntry_t, AUTOMATIC, CRYPTO_APPL_DATA) pSmrEntry
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status = HSM_LLD_InstallSmrEntry(bootCore, bootType, op,xoscConfigData,
										smrCnt, pSmrEntry);

	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"



#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_GetSecureBootStatus
(
	P2VAR(hsmSecureBootStatus_t, AUTOMATIC, CRYPTO_APPL_DATA) pSecureBootStatus
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status =  HSM_LLD_GetSecureBootStatus(pSecureBootStatus);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_EnableHsmFeature(void)
{
	VAR(uint32, AUTOMATIC) utest_addr = 0;
	VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;

	if (0u == SSCM.UOPS.B.HSE)
	{
        /* check DCF Start Record */
        utest_addr = 0x400300u;
        if (*(uint64_t *)utest_addr != 0x05AA55AF00000000u)/* polyspace RTE:IDP,NIV */
        {
            HostFlash_DoubleWordWrite(utest_addr, 0x05AA55AF00000000u);
        }

        /* check DCF HSM 'ROM' key Records */
        for (utest_addr = 0x400308u; utest_addr < 0x400348u; utest_addr += 0x8u)
        {
            if (*(uint64_t *)utest_addr == 0xFFFFFFFFFFFFFFFFu)/* polyspace RTE:IDP,NIV */
            {
                HostFlash_DoubleWordWrite(utest_addr, 0x0000000000000000u);
            }
        }

        /* check DCF Records */
        for (utest_addr = 0x400348UL; utest_addr < 0x00401000UL; utest_addr += 0x8UL)
        {
            if (*(uint64_t *)utest_addr == 0xFFFFFFFFFFFFFFFF)/* polyspace RTE:IDP,NIV */
            {
                HostFlash_DoubleWordWrite(utest_addr, 0x0000000300400040u);
                break;
            }
        }

        /* check write data */
        if (*(uint64_t *)utest_addr != 0x0000000300400040u)/* polyspace RTE:IDP,NIV */
        {
        	retVal = (Std_ReturnType)E_NOT_OK;
        }
	}

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_SetIgnoreSecureBootOnce(void)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status =  HSM_LLD_SetIgnoreSecureBootOnce();
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateInit(void)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status =  HSM_LLD_FWUpdateInit();
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateInit_Async(void)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status =  HSM_LLD_FWUpdateInit_Async();
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateProcess
(
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pFwImage,
	VAR(uint32, AUTOMATIC) fwLength,
	VAR(uint32, AUTOMATIC) fwOffset
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status =  HSM_LLD_FWUpdateProcess(pFwImage,fwLength,fwOffset);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateProcess_Async
(
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pFwImage,
	VAR(uint32, AUTOMATIC) fwLength,
	VAR(uint32, AUTOMATIC) fwOffset
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status =  HSM_LLD_FWUpdateProcess_Async(pFwImage,fwLength,fwOffset);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateFinal
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(uint32_t, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status =  HSM_LLD_FWUpdateFinal_New(keyHandle,fwLength,mac);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateFinal2
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
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status =  HSM_LLD_FWUpdateFinal2(keyHandle,fwLength,mac,dVer,stDycode,runDycode,codeLength);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateFinal_Async
(
	VAR(uint32, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) key,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status =  HSM_LLD_FWUpdateFinal_Async(fwLength,key,mac);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_FWUpdateFinal_Async_New
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(uint32_t, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status =  HSM_LLD_FWUpdateFinal_Async_New(keyHandle,fwLength,mac);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_CheckServiceResponce
(
	P2VAR(status_t, AUTOMATIC, CRYPTO_APPL_DATA) pStatus
)
{
	VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;

	*pStatus =  HSM_LLD_CheckServiceResponce();

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_RamWait_S0
(
	P2VAR(volatile uint32_t, AUTOMATIC, CRYPTO_APPL_DATA) checkaddr,
	VAR(uint32_t, AUTOMATIC) ram_timeout
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status =  HSM_LLD_RamWait_S0(checkaddr,ram_timeout);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_RamWait_S1
(
	P2VAR(volatile uint32_t, AUTOMATIC, CRYPTO_APPL_DATA) checkaddr
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status =  HSM_LLD_RamWait_S1(checkaddr);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_RamWait_S1_Err(void)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status =  HSM_LLD_RamWait_S1_Err();
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_PRIVATE_CODE) Crypto_AutoSar_Ext_GetKeyHash
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pkeyHash
)
{
	VAR(status_t, AUTOMATIC) status;
	VAR(Std_ReturnType, AUTOMATIC) retVal;

	status = HSM_LLD_GetKeyHash(keyHandle,pkeyHash);
	retVal = Crypto_VerifyHsmResp(status);

	return retVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

/*
********************************************************************************
*
*  File name: CryIf_Cfg.c
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
*  Version: 3.0
*  Author/Date : JiaF/2020.07.02
*  Change: New created.
*  Cause: New
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CryIf.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/*
********************************************************************************
*    Local Types
********************************************************************************
*/
/*
********************************************************************************
*    Local Variables
********************************************************************************
*/
/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
/*
********************************************************************************
*    Global Variable
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define CRYIF_START_SEC_CONFIG_DATA
//wjc:CryIf_MemMap.h
/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_CryIf_Unreasonablevariable" */
CONST(CryIf_ChannelConfigType, CRYIF_CONFIG_DATA) CryIf_ChannelConfig[CRYIF_NUMBER_OF_CHANNEL + CRYIF_VALUE_ONE] =
{
	{
		0U,
		CRYIF_INVALID_ID,
		0U
	},
	{
		0U,
		CRYIF_INVALID_ID,
		0U
	}
};
/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_CryIf_Unreasonablevariable" */
CONST(CryIf_KeyConfigType, CRYIF_CONFIG_DATA) CryIf_KeyConfig[CRYIF_NUMBER_OF_KEY + CRYIF_VALUE_ONE] =
{
	{
		0U,
		CRYIF_INVALID_ID,
		0U
	},
	{
		0U,
		CRYIF_INVALID_ID,
		0U
	}
};
/* Polyspace +1 VARIABLE:ALL [Justified:Unset] "NSCA_Polyspace_CryIf_Unreasonablevariable" */
CONST(CryIf_ObjectDriverFunctionTableType, CRYIF_CONFIG_DATA) CryIf_ObejectDriverFunctionTable[CRYIF_NUMBER_OF_DRIVER + CRYIF_VALUE_ONE] =
{
	{
		Crypto_ProcessJob,
		Crypto_CancelJob,
		Crypto_KeyElementSet,
		Crypto_KeySetValid,
		Crypto_KeyElementGet,
		Crypto_KeyElementCopy,
#if( CRYIF_KEY_ELEMENT_COPY_PARTIAL == STD_ON )
		Crypto_KeyElementCopyPartial,
#else
		NULL_PTR,
#endif
		Crypto_KeyCopy,
		Crypto_RandomSeed,
		Crypto_KeyGenerate,
		Crypto_KeyDerive,
		Crypto_KeyExchangeCalcPubVal,
		Crypto_KeyExchangeCalcSecret,
		Crypto_CertificateParse,
		Crypto_CertificateVerify,
		Crypto_KeyElementIdsGet,
	},
	{
		NULL_PTR,
	}
};


#define CRYIF_STOP_SEC_CONFIG_DATA
//wjc:CryIf_MemMap.h


/*
********************************************************************************
*
* File name: SecOC_Lcfg.c
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date : ZhangY/2021.11.12
* Change: New created
* Cause: New
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "SecOC.h"

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
*    Global Variables
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define SECOC_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* polyspace-begin VARIABLE:* [Justified:Unset] "NSCA_Polyspace_SecOC_GlobalVariables" */
/* polyspace-begin MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.7" */
	
VAR(SecOC_RxPdu_OverrideStatusType, SECOC_VAR_INIT) SecOC_RxPdu_OverrideStatus[SECOC_NUM_RXPDUPRO] =
{
	{
		12U,
		0U,
		SECOC_OVERRIDE_CANCEL,
	},
};

/* polyspace-end MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule8.7" */
#define SECOC_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define SECOC_START_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if( SECOC_NUM_SECUREDAREA>0U )
	
CONST(SecOCTxPduSecuredAreaType, SECOC_CONFIG_DATA) SecOCTxPduSecuredAreaIns[SECOC_NUM_SECUREDAREA] =
{
	{
		16U,
		0U,
	},
};
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCTxPduProcessing/SecOCTxSecuredPduLayer/SecOCTxSecuredPdu */
#if( SECOC_NUM_SECUREDPDU>0U )
	
static CONST(SecOCTxSecuredPduType, SECOC_CONFIG_DATA) SecOCTxSecuredPduTypeIns[SECOC_NUM_SECUREDPDU] =
{
	{
		0U,
		0U,
		51U,
	},
};
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCTxPduProcessing/SecOCTxSecuredPduLayer/SecOCTxSecuredPduCollection/SecOCTxAuthenticPdu */
#if( SECOC_NUM_TXAUTHENTICPDU>0 )
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCTxPduProcessing/SecOCTxSecuredPduLayer/SecOCTxSecuredPduCollection/SecOCTxCryptographicPdu */
#if( SECOC_NUM_TXCRYPTOGRAPHICPDU>0U )
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCTxPduProcessing/SecOCTxSecuredPduLayer/SecOCTxSecuredPduCollection/SecOCUseMessageLink */
#if( SECOC_NUM_USEMESSAGELINK_TX>0U )
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCTxPduProcessing/SecOCTxSecuredPduLayer/SecOCTxSecuredPduCollection */
#if( SECOC_NUM_SECUREDPDUCOLL>0U )
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCTxPduProcessing/SecOCTxSecuredPduLayer */
#if( SECOC_NUM_SECUREDLAYERINS>0U )
	
static CONST(SecOCTxSecuredPduLayerType, SECOC_CONFIG_DATA) SecOCTxSecuredPduLayerIns[SECOC_NUM_SECUREDLAYERINS] =
{
	{
		&SecOCTxSecuredPduTypeIns[0],
		NULL_PTR,
	},
};
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCTxPduProcessing/SecOCTxAuthenticPduLayer */
#if( SECOC_NUM_AUTHENTICPDULAYER>0U )
	
static CONST( SecOCTxAuthenticPduLayerType, SECOC_CONFIG_DATA) SecOCTxAuthenticPduLayerIns[SECOC_NUM_AUTHENTICPDULAYER] =
{
	{
		SECOC_IFPDU,
		0U,
		83U,
	},
};
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCTxPduProcessing */
#if( SECOC_NUM_TXPDUPRO>0U )
	
CONST( SecOCTxPduProcessingType, SECOC_CONFIG_DATA) SecOCTxPduProcessingIns[SECOC_NUM_TXPDUPRO] =
{
	{
		1U,
		8U,
		17U,
		1U,
		0U,
		0U,
		FALSE,
		FALSE,
		TRUE,
		0U,
		CRYPTO_PROCESSING_SYNC,
		&SecOCTxAuthenticPduLayerIns[0],
		&SecOCTxSecuredPduLayerIns[0],
		&SecOCTxPduSecuredAreaIns[0],
	},
};
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCRxPduProcessing/SecOCRxAuthenticPduLayer */
#if( SECOC_NUM_RXAUTHENTICPDULAYER>0U )
	
static CONST( SecOCRxAuthenticPduLayerType, SECOC_CONFIG_DATA) SecOCRxAuthenticPduLayerIns[SECOC_NUM_RXAUTHENTICPDULAYER] =
{
	{
		SECOC_IFPDU,
		53U,
	},
};
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCRxPduProcessing/SecOCRxSecuredPduLayer/SecOCRxSecuredPdu */
#if( SECOC_NUM_RXSECUREDPDU>0U )
	
static CONST( SecOCRxSecuredPduType, SECOC_CONFIG_DATA) SecOCRxSecuredPduIns[SECOC_NUM_RXSECUREDPDU] =
{
	{
		0U,
		0U,
		FALSE,
		85U,
	},
};
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCRxPduProcessing/SecOCRxSecuredPduLayer/SecOCRxSecuredPduCollection/SecOCRxAuthenticPdu */
#if( SECOC_NUM_RXAUTHENTICPDU>0 )
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCRxPduProcessing/SecOCRxSecuredPduLayer/SecOCRxSecuredPduCollection/SecOCRxCryptographicPdu */
#if( SECOC_NUM_RXCRYPTOGRAPHICPDU>0 )
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCRxPduProcessing/SecOCRxSecuredPduLayer/SecOCRxSecuredPduCollection/SecOCUseMessageLink */
#if( SECOC_NUM_USEMESSAGELINK_RX>0 )
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCRxPduProcessing/SecOCRxSecuredPduLayer/SecOCRxSecuredPduCollection */
#if( SECOC_NUM_RXSECUREDPDUCOLL>0U )
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCRxPduProcessing/SecOCRxSecuredPduLayer */
#if( SECOC_NUM_RXSECUREDPDULAYER>0U )
	
static CONST( SecOCRxSecuredPduLayerType, SECOC_CONFIG_DATA) SecOCRxSecuredPduLayerIns[SECOC_NUM_RXSECUREDPDULAYER] =
{
	{
		&SecOCRxSecuredPduIns[0],
		NULL_PTR,
	},
};
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCRxPduProcessing/SecOCRxPduSecuredArea */
#if( SECOC_NUM_RXSECUREDAREA>0U )
	
CONST(SecOCRxPduSecuredAreaType, SECOC_CONFIG_DATA) SecOCRxPduSecuredAreaIns[SECOC_NUM_RXSECUREDAREA] =
{
	{
		16U,
		0U,
	},
};
#endif

/* /AUTOSAR/EcucDefs/SecOC/SecOCRxPduProcessing */
#if( SECOC_NUM_RXPDUPRO>0U )

	
CONST(SecOCRxPduProcessingType, SECOC_CONFIG_DATA) SecOCRxPduProcessingIns[SECOC_NUM_RXPDUPRO] =
{
	{
		0U,
		0U,
		1U,
		1U,
		0U,
		12U,
		1U,
		0U,
		0U,
		SECOC_REPLACE,
		0U,
		FALSE,
		FALSE,
		SECOC_NONE,
		0U,
		CRYPTO_PROCESSING_SYNC,
		&SecOCRxAuthenticPduLayerIns[0],
		&SecOCRxSecuredPduLayerIns[0],
		NULL_PTR,
		0U,
		&SecOC_RxPdu_OverrideStatus[0],
	},
};
#endif

/* /AUTOSAR/EcucDefs/SecOC */
	
CONST(SecOC_ConfigType, SECOC_CONFIG_DATA) SecOC_Config =
{
	&SecOCTxPduProcessingIns[0],
	&SecOCRxPduProcessingIns[0],
};

static CONST(uint16, SECOC_CONFIG_DATA) SecOC_RxPduInfo[SECOC_RXPDU_NUM + 1U] =
{
    0U,
    65535U
};

CONST(SecOC_RxPduInfoTableType, SECOC_CONFIG_DATA) SecOC_RxPduInfoTable[SECOC_RXPDU_TOTAL_TABLES] =
{
    {
        SecOC_RxPduInfo,
        SECOC_RXPDU_NUM
    }
};

static CONST(uint16, SECOC_CONFIG_DATA) SecOC_TxPduInfo[SECOC_TXPDU_NUM + 1U] =
{
    0U,
    65535U
};

CONST(SecOC_TxPduInfoTableType, SECOC_CONFIG_DATA) SecOC_TxPduInfoTable[SECOC_TXPDU_TOTAL_TABLES] =
{
    {
        SecOC_TxPduInfo,
        SECOC_TXPDU_NUM
    }
};
/* polyspace-end VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanNm_GlobalVariables" */
#define SECOC_STOP_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


/*
********************************************************************************
*
* File name: ComStack_Types.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : WangJipeng/2020.01.06
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date : WangCong/2020.03.25
* Change: #include "ComStack_Types.h" change to #include "ComStack_Cfg.h"
* Cause: bugfix
********************************************************************************
* Version: 3.1
* Author/Date : WangJipeng/2020.07.02
* Change: Add ComStack module and autosar release version.
* Cause: Update
********************************************************************************
*/
#ifndef COMSTACK_TYPES_H_
#define COMSTACK_TYPES_H_

//merge MCAL ComStack_Types.h to this file
#ifdef __cplusplus
extern "C"{
#endif


/*==============================================INCLUDE FILES=======================================*/
#include "Std_Types.h"

/**
* @brief  Action has been successfully finished
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_OK           0x00

/**
* @brief  Message not successfully received or sent out
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_NOT_OK     0x01

/**
* @brief  Timer N_Ar/N_As has passed its time-out value N_Asmax/N_Armax
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_TIMEOUT_A  0x02

/**
* @brief  Timer N_Bs has passed its time-out value N_Bsmax
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_TIMEOUT_BS 0x03

/**
* @brief  Timer N_Cr has passed its time-out value N_Crmax
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_TIMEOUT_CR 0x04

/**
* @brief  Unexpected sequence number (PCI.SN) value received
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_WRONG_SN   0x05

/**
* @brief  Invalid or unknown FlowStatus value has been received
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_INVALID_FS 0x06

/**
* @brief  Unexpected protocol data unit received
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_UNEXP_PDU  0x07

/**
* @brief  Flow control WAIT frame that exceeds the maximum counter N_WFTmax received
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_WFT_OVRN   0x08

/**
* @brief  Flow control (FC) N_PDU with FlowStatus = OVFLW received
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_ABORT  0x09

/**
* @brief  Indicates an abort of a transmission.
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_NO_BUFFER  0x0A

/**
* @brief  Requested cancellation has been executed
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_CANCELATION_OK 0x0B

/**
* @brief  Request cancellation has not been executed
*         Due to an internal error the requested cancelation has not been executed.
*         This will happen e.g. if the to be canceled transmission has been executed already.
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_CANCELATION_NOT_OK 0x0C

/**
* @brief  The parameter change request has been successfully executed
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_PARAMETER_OK  0x0D

/**
* @brief  The request for the change of the parameter did not complete successfully
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_PARAMETER_NOT_OK  0x0E

/**
* @brief  The parameter change request not executed successfully due to an ongoing reception
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_RX_ON 0x0F

/**
* @brief  The parameter change request not executed successfully due to a wrong value
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_VALUE_NOT_OK 0x10


typedef uint16       PduIdType;
typedef uint32       PduLengthType;


#ifdef __cplusplus 
}
#endif

//NeuSAR
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "StandardTypes.h" //DQ add
#include "Std_Types.h"
#include "ComStack_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Module identification and version. */
#define COMSTACK_VENDOR_ID                            (119U)
#define COMSTACK_MODULE_ID                            (196U)
#define COMSTACK_SW_MAJOR_VERSION                     (3U)
#define COMSTACK_SW_MINOR_VERSION                     (0U)
#define COMSTACK_SW_PATCH_VERSION                     (0U)

/* AUTOSAR Version. */
#define COMSTACK_AR_RELEASE_MAJOR_VERSION             (4U)
#define COMSTACK_AR_RELEASE_MINOR_VERSION             (2U)
#define COMSTACK_AR_RELEASE_REVISION_VERSION          (2U)

/* SWS_COMTYPE_00021 */
#define BUSTRCV_OK 		(0x00u)	/* There is no bus transceiver error seen by the 
                                   driver or transceiver does not support the detection of bus errors. */
#define BUSTRCV_E_ERROR	(0x01u)	/* Bus transceiver detected an unclassified error. */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef uint8 PNCHandleType;		/* SWS_COMTYPE_00036 */
typedef uint8 BusTrcvErrorType;		/* SWS_COMTYPE_00020 */
typedef uint8 NetworkHandleType;	/* SWS_COMTYPE_00038 */
typedef uint8 IcomConfigIdType;		/* SWS_COMTYPE_00039 */

typedef enum
{
	TP_STMIN,	/* 0x00: Separation Time */
	TP_BS,		/* 0x01: Block Size */
	TP_BC		/* 0x02: The Band width control parameter used in FlexRay transport protocol module. */
} TPParameterType;	/* SWS_COMTYPE_00031 */

typedef enum	/* Variables of this type shall be used to store the result of a buffer request. */	
{
	BUFREQ_OK,			/* 0: Buffer request accomplished successful. */
	BUFREQ_E_NOT_OK,	/* 1: Buffer request not successful. Buffer cannot be accessed. */
	BUFREQ_E_BUSY,		/* 2: Temporarily no buffer available. It's up the requester to retry request for a certain time. */
	BUFREQ_E_OVFL		/* 3: No Buffer of the required length can be provided. */
} BufReq_ReturnType;		/* SWS_COMTYPE_00012 */

typedef enum	/* Variables of this type shall be used to store the state of TP buffer. */
{
	TP_DATACONF,	/* 0x00: TP_DATACONF indicates that all data, that have been 
	                   copied so far, are confirmed and can be removed from the TP buffer. */
	TP_DATARETRY,	/* 0x01: TP_DATARETRY indicates that this API call shall copy
                       already copied data in order to recover from an error. */
	TP_CONFPENDING	/* 0x02: TP_CONFPENDING indicates that the previously copied data must remain in the TP. */
} TpDataStateType;	/* SWS_COMTYPE_00027 */

typedef enum	/* IcomSwitch_ErrorType defines the errors which can occur when activating or deactivating Pretended Networking. */
{
	ICOM_SWITCH_E_OK,	/* The activation of Pretended Networking was successful. */
	ICOM_SWITCH_E_FAILED	/* ICOM_SWITCH_E_FAILED The activation of Pretended Networking was not successful. */
} IcomSwitch_ErrorType;		/* SWS_COMTYPE_00040 */

typedef struct	/* Used to store the identifier of a partial network cluster. */ 
{
  uint8* SduDataPtr;		/* Pointer to the SDU of the PDU. */
  PduLengthType SduLength;	/* Length of the SDU in bytes, including MetaData. */
} PduInfoType;				/* SWS_COMTYPE_00011 */

typedef struct	/* Variables of this type shall be used to store the information about Tp buffer handling. */
{
	TpDataStateType TpDataState;	/* The enum type to be used to store the state of Tp buffer. */
	PduLengthType TxTpDataCnt;		/* Offset from the current position which identifies the number of bytes to be retransmitted. */
} RetryInfoType;	/* SWS_COMTYPE_00037 */

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
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* COMSTACK_TYPES_H_ */	/* SWS_COMPILER_00047 */

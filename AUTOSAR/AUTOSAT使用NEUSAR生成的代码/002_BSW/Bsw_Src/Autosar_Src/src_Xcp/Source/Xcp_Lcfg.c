/*
********************************************************************************
*
*  File name:   Xcp_Lcfg.c
*
*  Copyright    Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : yong.zhang/2019.12.28
* Change: New created
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : fangtao/2020.8.11
* Change: Added channel name and length.
* Cause: Bugfix.
********************************************************************************
* Version: 3.0
* Author/Date: FangT/2021.03.03
* Change: Add checksum and Multi pudid functions.
* Cause: Optimization
********************************************************************************
* Version: 3.1
* Author/Date: lqiao/2022.09.16
* Change: Add XCP_gcaCAN_Msg_CRO and XCP_gcaCAN_Msg_DTO
* Cause: new.
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Xcp.h"
#include "Xcp_Swc.h"
/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
#define DAQ      (0U) 
#define DAQ_STIM (1U) 
#define STIM     (2U)

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
static FUNC(uint8, XCP_CODE) XcpGetRand
(
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)xcpBufferRand,
    const uint8 avcLength
);

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
VAR(uint8, XCP_VAR_NO_INIT) XCP_gcaCAN_Msg_CRO[64];
VAR(uint8, XCP_VAR_NO_INIT) XCP_gcaCAN_Msg_DTO[64];
VAR(uint8, XCP_VAR_INIT) Xcp_Resource_Array[XCP_SAFELEN] = {0};

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define XCP_START_SEC_CONFIG_DATA
#include "Xcp_MemMap.h"

#if( XCP_EVENT_CHANNEL_NUM > 0 )
CONST(Xcp_EventChannelType, XCP_CONFIG_DATA) Xcp_EventChannel[XCP_EVENT_CHANNEL_NUM] =
{
	{0, 1, 0, 0, 1, DAQ_TIMESTAMP_UNIT_1MS, 4, 0},
	{0, 1, 1, 0, 2, DAQ_TIMESTAMP_UNIT_1MS, 4, 0},
	{0, 1, 2, 0, 10, DAQ_TIMESTAMP_UNIT_1MS, 4, 0},
	{0, 1, 3, 0, 20, DAQ_TIMESTAMP_UNIT_1MS, 4, 0},
	{0, 1, 4, 0, 100, DAQ_TIMESTAMP_UNIT_1MS, 4, 0},
};
#endif
CONST(uint8, XCP_CONFIG_DATA) XcpEventName_0[10] = "XcpEvent1";
CONST(uint8, XCP_CONFIG_DATA) XcpEventName_1[10] = "XcpEvent2";
CONST(uint8, XCP_CONFIG_DATA) XcpEventName_2[10] = "XcpEvent3";
CONST(uint8, XCP_CONFIG_DATA) XcpEventName_3[10] = "XcpEvent4";
CONST(uint8, XCP_CONFIG_DATA) XcpEventName_4[10] = "XcpEvent5";

P2CONST(uint8, XCP_CONFIG_DATA, XCP_APPL_CONST) XcpEventName[XCP_EVENT_CHANNEL_NUM] =
{
	&XcpEventName_0[0],
	&XcpEventName_1[0],
	&XcpEventName_2[0],
	&XcpEventName_3[0],
	&XcpEventName_4[0],
};
CONST(uint8, XCP_CONFIG_DATA) XcpEventNameLength[XCP_EVENT_CHANNEL_NUM] = 
{
	9U,
	9U,
	9U,
	9U,
	9U,
};

#if( XCP_DTO_NUM > XCP_ZERO )
CONST(Xcp_DtoType, XCP_CONFIG_DATA) Xcp_Dto[XCP_DTO_NUM] =
{
};
#endif

#if( XCP_ODTENTRY_NUM > XCP_ZERO )
CONST(Xcp_OdtEntryType, XCP_CONFIG_DATA) Xcp_OdtEntry[XCP_ODTENTRY_NUM] = 
{
};
#endif

#if( XCP_ODT_NUM > XCP_ZERO )
CONST(Xcp_OdtType, XCP_CONFIG_DATA) Xcp_Odt[XCP_ODT_NUM] =
{
};
#endif

#if( XCP_DAQ_LIST_NUM > 0 )
CONST(Xcp_DaqListType, XCP_CONFIG_DATA) Xcp_DaqList[XCP_DAQ_LIST_NUM] =
{
};
#endif

CONST(Xcp_RxPduType, XCP_CONFIG_DATA) Xcp_RxPdu[XCP_RXPDU_LIST] =
{
	{0, 0},
};

CONST(Xcp_TxPduType, XCP_CONFIG_DATA) Xcp_TxPdu[XCP_TXPDU_LIST] =
{
	{0, 0},
};

CONST(Xcp_PduType, XCP_CONFIG_DATA) Xcp_Pdu[XCP_PDU_LIST] =
{
    {&Xcp_RxPdu[0U],&Xcp_TxPdu[0U]}
};

VAR(Xcp_NvmBlockId_st, XCP_CONFIG_DATA) Xcp_NvmBlockId[XCP_BLOCK_NUM + 1] = 
{
    { 0xFFFFU, XCP_E_NOT_OK, XCP_E_NOT_OK, NULL_PTR, 0U }
};


#if( (RTECALIBRATIONSUPPORT == OVERLAY_METHOD) )
VAR(Xcp_Addr_st, XCP_CONFIG_DATA) Xcp_Addr_Temp[XCP_OVERLAY_CNT];
#endif


#define XCP_STOP_SEC_CONFIG_DATA
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CODE
#include "Xcp_MemMap.h"

static FUNC(uint8, XCP_CODE) XcpGetRand
(
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)xcpBufferRand,
    const uint8 avcLength
)
{
	uint8 retVal = E_NOT_OK;
	(void)xcpBufferRand;
	(void)avcLength;
	/* Provide customers with code to write random data */
	return retVal; 
}



FUNC(void, XCP_CODE) XcpGetSeed(void)
{
	uint8 retVal = E_NOT_OK; 
	if( XCP_SAFELEN > 0 )
	{
		retVal = XcpGetRand((uint8*)&Xcp_Resource_Array, XCP_SAFELEN);

		if( E_OK == retVal )
		{
			/* Write decryption code for clients */
		}
		else
		{

		}

	}
	else
	{

	}
	
    /* Provide customers with the key to write and obtain security algorithms */

}


FUNC(uint8, XCP_CODE) XcpUnlock
(
    P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST)avcpKey,
    const uint8 avcLength
)
{
    uint8 reValue = E_NOT_OK;
    (void)avcpKey;
    (void)avcLength;
    /* Provide decryption to customers */


    return reValue;
}

/*
********************************************************************************
* Function Name: XcpAppl_FlashClear
*
* Explanation: Execute clear data instruction interface.
*
* param: setMta: Starting address for clearing data.
* param: clearSize: Clear the size of data.
*
* retval: XCP_E_OK: Successfully cleared
		  XCP_E_NOT_OK: Clearing unsuccessful.
********************************************************************************
*/
FUNC(uint8, XCP_CODE) XcpAppl_FlashClear
(
    uint32 setMta,
    uint32 clearSize
)
{
    uint8 ret = XCP_E_NOT_OK;
    /* Provide decryption to customers */


    return ret;
}

/*
********************************************************************************
* Function Name: XcpAppl_FlashProgram
*
* Explanation: Execute program flushing interface.
*
* param: setMta: Brush Start Address.
* param: dataPtr:Data to be written.
* param: Size of data to be flushed.
*
* retval: XCP_E_OK: Brush successfully
		  XCP_E_NOT_OK: Brushing unsuccessful.
********************************************************************************
*/
FUNC(uint8, XCP_CODE) XcpAppl_FlashProgram
(
    uint32 setMta,
    P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST)dataPtr,
    uint32 writeSize
)
{
    uint8 ret = XCP_E_NOT_OK;
    XCP_DUMMY_STATEMENT(setMta);
    (void)dataPtr;
    XCP_DUMMY_STATEMENT(writeSize);
    /* Provide decryption to customers */
    return ret;
}

/*
********************************************************************************
* Function Name: XcpAppl_Reset
*
* Explanation: Execute flush reset command interface.
*
* param: None.
*
* retval: XCP_E_OK: Reset successful
		  XCP_E_NOT_OK: Reset failed.
********************************************************************************
*/
FUNC(uint8, XCP_CODE) XcpAppl_Reset(void)
{
    uint8 ret = XCP_E_NOT_OK;

    /* Provide decryption to customers */
    return ret;
}

#if( (RTECALIBRATIONSUPPORT == OVERLAY_METHOD) )
/*
********************************************************************************
* Function Name: XcpOverlayMapping
*
* Explanation: Enable and disable the overlay function interface.
*
* param: None.
*
* retval: XCP_E_OK: Successfully configured
		  XCP_E_NOT_OK: Configure failed.
********************************************************************************
*/
FUNC(uint8, XCP_CODE) XcpOverlayMapping
(
	uint8 segment,
	uint8 page,
	uint8 mode
)
{
	uint8 ret = XCP_E_NOT_OK;
	XCP_DUMMY_STATEMENT(segment);
	XCP_DUMMY_STATEMENT(page);
	XCP_DUMMY_STATEMENT(mode);
	return ret;
}
#endif

FUNC(void, XCP_CODE) Xcp_Daq_Eventchannel0(void)
{
	Xcp_Event(XcpConf_XcpEventChannel_0);
}
FUNC(void, XCP_CODE) Xcp_Daq_Eventchannel1(void)
{
	Xcp_Event(XcpConf_XcpEventChannel_1);
}
FUNC(void, XCP_CODE) Xcp_Daq_Eventchannel2(void)
{
	Xcp_Event(XcpConf_XcpEventChannel_2);
}
FUNC(void, XCP_CODE) Xcp_Daq_Eventchannel3(void)
{
	Xcp_Event(XcpConf_XcpEventChannel_3);
}
FUNC(void, XCP_CODE) Xcp_Daq_Eventchannel4(void)
{
	Xcp_Event(XcpConf_XcpEventChannel_4);
}

#define XCP_STOP_SEC_CODE
#include "Xcp_MemMap.h"


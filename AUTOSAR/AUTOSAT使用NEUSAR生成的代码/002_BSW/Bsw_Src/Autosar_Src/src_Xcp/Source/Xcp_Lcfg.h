/*
********************************************************************************
*
*  File name:   Xcp_Lcfg.h
*
*  Copyright    Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : yong.zhang/2019.12.27
* Change: New created
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : fangtao/2020.08.11
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
#ifndef XCP_LCFG_H_
#define XCP_LCFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define XcpConf_XcpEventChannel_0          (0U)
#define XcpConf_XcpEventChannel_1          (1U)
#define XcpConf_XcpEventChannel_2          (2U)
#define XcpConf_XcpEventChannel_3          (3U)
#define XcpConf_XcpEventChannel_4          (4U)

#define XCP_EVENT_CHANNEL_NUM              (5U)
#define XCP_DAQ_LIST_NUM                   (0U)
#define XCP_DTO_NUM                        (0U)
#define XCP_ODT_NUM                        (0U)
#define XCP_ODTENTRY_NUM                   (0U)
#define XCP_PDU_LIST           (1U)         /* Xcp/XcpConfig/XcpPdus/ */
#define XCP_TXPDU_LIST                     (1U)
#define XCP_RXPDU_LIST                     (1U)
#define XCP_RAM_CNT                        (1U)
#define XCP_SAFELEN                        (1U)
#define XCP_BLOCK_NUM                      (0U)
#define XCP_OVERLAY_CNT                    (1U)
/* DAQ Timestamp Unit */
#define DAQ_TIMESTAMP_UNIT_1NS              (0u << 4u)
#define DAQ_TIMESTAMP_UNIT_10NS             (1u << 4u)
#define DAQ_TIMESTAMP_UNIT_100NS            (2u << 4u)
#define DAQ_TIMESTAMP_UNIT_1US              (3u << 4u)
#define DAQ_TIMESTAMP_UNIT_10US             (4u << 4u)
#define DAQ_TIMESTAMP_UNIT_100US            (5u << 4u)
#define DAQ_TIMESTAMP_UNIT_1MS              (6u << 4u)
#define DAQ_TIMESTAMP_UNIT_10MS             (7u << 4u)
#define DAQ_TIMESTAMP_UNIT_100MS            (8u << 4u)
#define DAQ_TIMESTAMP_UNIT_1S               (9u << 4u)
#define DAQ_TIMESTAMP_UNIT_1PS              (10 << 4u)
#define DAQ_TIMESTAMP_UNIT_10PS             (11 << 4u)
#define DAQ_TIMESTAMP_UNIT_100PS            (12 << 4u)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef struct
{
    uint8 XcpEventChannelConsistency;
    uint8 XcpEventChannelMaxDaqList;
    uint8 XcpEventChannelNumber;
    uint8 XcpEventChannelPriority;
    uint8 XcpEventChannelTimeCycle;
    uint8 XcpEventChannelTimeUnit;
    uint8 XcpEventChannelType;
    uint8 XcpEventChannelTriggeredDaqListRef;
} Xcp_EventChannelType;

typedef struct
{
    uint8 XcpDtoPid;
    uint8 XcpDto2PduMapping;
} Xcp_DtoType;

typedef struct
{
	uint32 XcpOdtEntryAddress;
	uint8  XcpOdtEntryBitOffset;
	uint8  XcpOdtEntryLength;
	uint8  XcpOdtEntryNumber;
} Xcp_OdtEntryType;

typedef struct
{
    uint8 XcpOdtEntryMaxSize;
    uint8 XcpOdtNumber;
    uint8 XcpOdt2DtoMapping;
	const Xcp_OdtEntryType *XcpOdtEntry;
} Xcp_OdtType;

typedef struct
{
    uint8 XcpDaqListNumber;
    uint8 XcpDaqListType;
    uint8 XcpMaxOdt;
    uint8 XcpMaxOdtEntries;
    const Xcp_DtoType *XcpDto;
    const Xcp_OdtType *XcpOdt;
} Xcp_DaqListType;

typedef struct
{
    uint16 XcpRxPduId;
    uint16 XcpRxPduRef;
} Xcp_RxPduType;

typedef struct
{
    uint16 XcpTxPduId;
    uint16 XcpTxPduRef;
} Xcp_TxPduType;

typedef struct
{
    const Xcp_RxPduType *Xcp_RxPdu;
    const Xcp_TxPduType *Xcp_TxPdu;
} Xcp_PduType;

typedef struct{
    uint32 addr_wp;     /* Starting address of Working Page */
    uint32 addr_rp;      /* Starting address of Reference Page */
    uint32 len;         /* Ram partition length */
} Xcp_Addr_st;

typedef struct{
    uint16 BlockId;
    uint8 RequestResp;
    uint8 ReadResp;
    uint8 *DataPtr;
    uint16 DataSize;
}Xcp_NvmBlockId_st;
/*
*******************************************************************************
*    Global Variables
*******************************************************************************
*/
extern CONST(Xcp_EventChannelType, XCP_CONFIG_DATA) Xcp_EventChannel[XCP_EVENT_CHANNEL_NUM];
extern CONST(uint8, XCP_CONFIG_DATA) XcpEventName_0[10];
extern CONST(uint8, XCP_CONFIG_DATA) XcpEventName_1[10];
extern CONST(uint8, XCP_CONFIG_DATA) XcpEventName_2[10];
extern CONST(uint8, XCP_CONFIG_DATA) XcpEventName_3[10];
extern CONST(uint8, XCP_CONFIG_DATA) XcpEventName_4[10];
extern P2CONST(uint8, XCP_CONFIG_DATA, XCP_APPL_DATA) XcpEventName[XCP_EVENT_CHANNEL_NUM];
extern CONST(uint8, XCP_CONFIG_DATA) XcpEventNameLength[XCP_EVENT_CHANNEL_NUM];
extern CONST(Xcp_RxPduType, XCP_CONFIG_DATA) Xcp_RxPdu[XCP_RXPDU_LIST];
extern CONST(Xcp_TxPduType, XCP_CONFIG_DATA) Xcp_TxPdu[XCP_TXPDU_LIST];
extern VAR(uint8, XCP_VAR_NO_INIT) XCP_gcaCAN_Msg_CRO[64U];
extern VAR(uint8, XCP_VAR_NO_INIT) XCP_gcaCAN_Msg_DTO[64U];
extern VAR(uint8, XCP_VAR_INIT) Xcp_Resource_Array[XCP_SAFELEN];
extern VAR(Xcp_NvmBlockId_st, XCP_CONFIG_DATA)Xcp_NvmBlockId[XCP_BLOCK_NUM + 1];
#if( (RTECALIBRATIONSUPPORT == OVERLAY_METHOD) )
extern VAR(Xcp_Addr_st, XCP_CONFIG_DATA) Xcp_Addr_Temp[XCP_OVERLAY_CNT];
#endif

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
extern FUNC(void, XCP_CODE) Xcp_Daq_Eventchannel0(void);
extern FUNC(void, XCP_CODE) Xcp_Daq_Eventchannel1(void);
extern FUNC(void, XCP_CODE) Xcp_Daq_Eventchannel2(void);
extern FUNC(void, XCP_CODE) Xcp_Daq_Eventchannel3(void);
extern FUNC(void, XCP_CODE) Xcp_Daq_Eventchannel4(void);

extern FUNC(void, XCP_CODE) XcpGetSeed(void);
extern FUNC(uint8, XCP_CODE) XcpUnlock
(
    P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST)avcpKey,
    const uint8 avcLength
);

extern FUNC(uint8, XCP_CODE) XcpAppl_FlashClear
(
    uint32 setMta,
    uint32 clearSize
);
extern FUNC(uint8, XCP_CODE) XcpAppl_FlashProgram
(
    uint32 setMta,
    P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST)dataPtr,
    uint32 clearSize
);
extern FUNC(uint8, XCP_CODE) XcpAppl_Reset(void);

#if( (RTECALIBRATIONSUPPORT == OVERLAY_METHOD) )
extern FUNC(uint8, XCP_CODE) XcpOverlayMapping
(
	uint8 segment,
	uint8 page,
	uint8 mode
);
#endif

#endif  /* XCP_LCFG_H_ */


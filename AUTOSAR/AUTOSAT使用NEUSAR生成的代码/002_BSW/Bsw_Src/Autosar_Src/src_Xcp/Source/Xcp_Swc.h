/*** create info *******************************************
*@ filename : Xcp_Swc.h 
*@ Author : liufengyuan 
*@ date :2025-02-12
*@ Description :XCP相关的接口声明
/*** modify info ******************************************* 
*@ version :0.0
*@ Modifier : liufengyuan 
*@ date :2025-02-12
*@ Modification Description :
初始版本
************************************************************/
#ifndef BOTTOM_LIB_HFILES_XCP_SWC_H_
#define BOTTOM_LIB_HFILES_XCP_SWC_H_

/********************************************** Include **********************************************/
/* 头文件 */
#include "Std_Types.h"
#include "ComStack_Types.h"
#include "status.h"
#include "typedefs.h"
#include "Gpt_Stm_LLDriver.h"

extern const uint32 XCP_valCalRAM_ADDR_MP;
extern const uint32 XCP_valCalFLASH_ADDR_MP;
extern const uint32 XCP_valCALRAM_SIZE_MP;
extern const uint32 XCP_valCALRAM_REMAPSIZE_MP;
/********************************************* Function *********************************************/
/**
 * 函数名称: CanXcp_Init
 * 参数in: args
 * 参数out: args
 * 返回值: return
 * 描述: CAN  xcp初始化函数
 */
extern void CanXcp_Init(void);

/**
 * 函数名称: Xcp_CanIfRxIndication
 * 参数in: args
 * 参数out: args
 * 返回值: return
 * 描述: description
 */
extern void Xcp_CanIfRxIndication(uint16 CanCanXcpRxPduId,const PduInfoType* PduInfoPtr);

/**
 * 函数名称: Xcp_Daq_Eventchannel0
 * 参数in: args
 * 参数out: args
 * 返回值: return
 * 描述: description
 */
extern void Xcp_Daq_Eventchannel0(void);

/**
 * 函数名称: Xcp_Daq_Eventchannel1
 * 参数in: args
 * 参数out: args
 * 返回值: return
 * 描述: description
 */
extern void Xcp_Daq_Eventchannel1(void);

/**
 * 函数名称: Xcp_Daq_Eventchannel2
 * 参数in: args
 * 参数out: args
 * 返回值: return
 * 描述: description
 */
extern void Xcp_Daq_Eventchannel2(void);

/**
 * 函数名称: Xcp_Daq_Eventchannel3
 * 参数in: args
 * 参数out: args
 * 返回值: return
 * 描述: description
 */
extern void Xcp_Daq_Eventchannel3(void);

/**
 * 函数名称: Xcp_Daq_Eventchannel4
 * 参数in: args
 * 参数out: args
 * 返回值: return
 * 描述: description
 */
extern void Xcp_Daq_Eventchannel4(void);

/**
 * 函数名称: Xcp_Init
 * 参数in: args
 * 参数out: args
 * 返回值: return
 * 描述: Xcp初始化函数
 */
extern void Xcp_Init(void);

/**
 * 函数名称: Xcp_MainFunction
 * 参数in: args
 * 参数out: args
 * 返回值: return
 * 描述: Xcp主函数
 */
extern void Xcp_MainFunction(void);

extern void XcpCAN_TxMessage(const uint8 *DataPtr, uint8 DataLen);
extern void XcpCAN_RxMessage(uint8 *receive_data,uint8 receive_length);

extern PduLengthType DataSduLength;
extern VAR(uint8, XCP_VAR_INIT) CanXcpGetStatus;

/************************************CAN or CANFD**************************/
extern const uint8 Const_CRM_CONNECT_LEN;
extern const uint8 Const_CRO_BUILD_CHECKSUM_LEN;
extern const uint8 Const_CRM_BUILD_CHECKSUM_LEN;
extern const uint8 Const_CRO_START_STOP_SYNC_LEN;
extern const uint8 Const_XCP_ODT_COUNT;
extern const uint8 Const_XCP_ODT_ENTRYYS_COUNT;
/************************************CAN or CANFD**************************/

extern void XCPSend_Test(void);
extern void XCP_Step(void);
extern FUNC(uint32, GPT_CODE) Gpt_Stm_LLD_GetCounter(VAR(STM_ModuleID_Type, AUTOMATIC) STM_ModuleID);
extern void VX1000Send_Test(void);
extern void VX1000_Step(void);
extern const uint32 XCP_OBS_LIMIT_MINADDR_MP;
extern const uint32 XCP_OBS_LIMIT_MAXADDR_MP;

#endif /* BOTTOM_LIB_HFILES_XCP_SWC_H_ */

#ifndef __CAN_NM_USERDATA_FILL_H_
#define __CAN_NM_USERDATA_FILL_H_

#include "Platform_Types.h"
#include "ComM_Lcfg.h"

/***********************************UserDataEnable_Define***********************************/

/**
 *  0x0: Repeat Message State
    0x1: Normal Operation State
    状态PMS_NMSts
*/
#define CANNM_NM_USER_ENABLE_NMSts                  (STD_ON)    //网络管理状态
#define CANNM_NM_USER_ENABLE_flgKeyOn               (STD_ON)    //钥匙唤醒  
#define CANNM_NM_USER_ENABLE_flgChargeOn            (STD_ON)    //充电唤醒
#define CANNM_NM_USER_ENABLE_flgNMWakeUp            (STD_ON)    //网络唤醒
#define CANNM_NM_USER_ENABLE_fgDiag_WakeUpDiag      (STD_ON)    //诊断报文维持

/***********************************UserDataEnable_Define***********************************/

//-16原因是因为UserData的起始位是从byte2开始的，所以bitIndex需要减去16
//主动唤醒标志位
#define UserData_WakeUp_flag                        (16-16)        //网络管理状态
#define UserData_NMSts                              (24-16)        //网络管理状态
#define UserData_flgKeyOn                           (37-16)        //钥匙唤醒  
#define UserData_flgChargeOn                        (50-16)        //充电唤醒
#define UserData_flgOBC_ON                          (51-16)        //OBC唤醒
#define UserData_Smart_Charging                     (52-16)        //网络唤醒
#define UserData_fgDiag_WakeUpDiag                  (44-16)        //诊断报文维持







extern uint8 ComM_DcmRequestActive[COMM_ACTIVE_CHANNEL];
/* 缓冲区固定长度 */
#define CANNM_UD_BUFFER_LENGTH  6u


extern void Can_NM_UserData_Fill(void);
extern uint8 CanNm_GetTxUserNMEnable(void);
extern void can_NM_USERDATA_FILL_CALLBACK(uint8 Can_valNodeId, uint32 Can_valMsgId);
extern void can_NM_WakeUpFlg_Clear(void);


/**
 * @brief 位填充: 向 buffer 的指定 bitIndex 位置写入 value。
 *
 * @param buffer    目标缓冲区
 * @param bitIndex  位索引，从 0 开始。
 *                  例如 37 -> byte4 bit5，50 -> byte6 bit2
 * @param bitWidth  位宽 (1..8)，要求 bitOffset + bitWidth <= 8
 * @param value     待写入的值（超出位宽的高位会被截断）
 */
void CanNm_UserData_WriteBits(uint8*     buffer,
                              uint16   bitIndex,
                              uint8    bitWidth,
                              uint64     value);

/**
 * @brief 位消除: 清零 buffer 的指定 bitIndex 位置。
 *
 * @param buffer    目标缓冲区
 * @param bitIndex  位索引，从 0 开始。
 *                  例如 37 -> byte4 bit5，50 -> byte6 bit2
 * @param bitWidth  位宽 (1..8)，要求 bitOffset + bitWidth <= 8
 */
void CanNm_UserData_ClearBits(uint8*     buffer,
                              uint16   bitIndex,
                              uint8   bitWidth);
#endif /* __TASK_APP_CORE3_H_ */


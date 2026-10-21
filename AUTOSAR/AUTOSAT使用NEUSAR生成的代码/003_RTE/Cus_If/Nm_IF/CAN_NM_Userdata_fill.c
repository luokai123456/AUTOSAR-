
#include "CAN_NM_Userdata_fill.h"
#include "Com_Lcfg.h"
#include "Rte_Type.h"
#include "Platform_Types.h"
#include "CanIf_Lcfg.h"
#include "IoHwAbs_ADC.h"
#include "Com.h"
#include "CanNm.h"
#include "CanNm_Cfg.h"
#include "NmStack_Types.h"
#include "Dcm.h"
#include "ComM.h"
#include "Rte_BSW_NM.h"

uint8  NmIF_fgNMWakeUpID_0X40D_C = 0;
uint8  NmIF_fgNMWakeUpID_0X426_C = 0;
uint8  NmIF_fgNMWakeUpID_0X40A_C = 0;
uint16 NmIF_numNMWakeUpCounter_0X40D_MP = 0;
uint16 NmIF_numNMWakeUpCounter_0X426_MP = 0;
uint16 NmIF_numNMWakeUpCounter_0X40A_MP = 0;
uint8  NmIF_fgNMWakeUpID_Diag_C=0;
boolean NmIF_fgBCM_IntelligentChargeCommand=0;
uint16 NmIF_uChargeOn_C=0;
uint16 NmIF_uOBC_ON_C=0;
uint16 NmIF_uKeyOn_C=0;
boolean NmIF_flgCANNM_STASE_C=0;
boolean NmIF_flgChargeOn_C=0;
boolean NmIF_flgOBC_ON_C=0;
boolean NmIF_flgKeyOn_C=0;
uint8 NmIF_valOBC_OnBdCPline=0;
uint8 NmIF_numCanNmChannel_C=0;
uint8 NmIF_stCANNM_C[2]={0}; 

boolean evpt_hvbd_b_tboxIntelChgCmdRaw;//智能补电命令原始值   
uint8 ASW_BMS_DelayControl_MP = 0U;

extern uint8 KL15_Status_MP;	//KL15 IO状态
extern uint8 CHG_Status_MP;		//A+ 1 IO状态
extern uint8 OBC_Status_MP;		//OBC IO状态

extern uint8 CanNm_TxMessageData[CANNM_NUMBER_OF_CANNM_CHANNELS][8U]; //NM报文发送buffer

/**
 * 
 * 以5ms周期运行获取值，并作出判断
*/
void Can_NM_UserData_Fill(void)
{
    uint16 Com_PduID_LO = 0;
/***********************************************值获取******************************************/
    //获取BCM_IntelligentChargeCommand值
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_BCM_ACCINFOR__XQC0B_BCM_INTELLIGENTCHARGECOMMAND_BCM_ACCINFOR_N72__PMS_PT_CANFD_20260425_DBC_RX, &NmIF_fgBCM_IntelligentChargeCommand);
    //智能补电判断依据为应用层数据来源
    Rte_Read_vcib_VCIP_hvbd_b_tboxIntelChgCmd(&evpt_hvbd_b_tboxIntelChgCmdRaw);
    //获取OBC_OnBdCPline值
    (void)Com_ReceiveSignal(COMCONF_COMSIGNAL_OBC_STS__XQC0B_OBC_ONBDCPLINE_OBC_STS_N72__PMS_PT_CANFD_20260425_DBC_TX, &NmIF_valOBC_OnBdCPline);
    //获取充电信号 
    NmIF_flgChargeOn_C = CHG_Status_MP;
    //获取OBC_ON信号
    NmIF_flgOBC_ON_C = OBC_Status_MP;
    //获取开钥匙信号
    NmIF_flgKeyOn_C = KL15_Status_MP;

/***********************************************值获取******************************************/

/**********************************************逻辑实现*****************************************/

    //清除唤醒源
    for( NmIF_numCanNmChannel_C = CANNM_ZERO; NmIF_numCanNmChannel_C < (NetworkHandleType)CanNm_GetSizeOfChannelConfig(); NmIF_numCanNmChannel_C++ )
    {
        //获取CANNM状态
        NmIF_stCANNM_C[NmIF_numCanNmChannel_C] = CanNm_GetNmState(NmIF_numCanNmChannel_C);
        //获取发送PDUID 
        Com_PduID_LO = CanNm_GetTxPduRef(NmIF_numCanNmChannel_C);
#if( CANNM_NM_USER_ENABLE_NMSts == STD_ON )
        //NMSts状态更新
        switch (NmIF_stCANNM_C[NmIF_numCanNmChannel_C])
        {
            case NM_STATE_NORMAL_OPERATION:/* Normal Operation State. */
                //COM发送数据更新
                CanNm_UserData_WriteBits(Com_TxPduInfo[Com_PduID_LO].dataRaw,UserData_NMSts, 1, 1);
                //CANNM发送数据更新
                CanNm_UserData_WriteBits(&CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_NMSts, 1, 1);
                // CanNm_TxMessageData[NmIF_numCanNmChannel_C][3] = 0x01;
                break;
            case NM_STATE_REPEAT_MESSAGE:/* Repeat Message State. */
                //COM发送数据更新
                CanNm_UserData_ClearBits(Com_TxPduInfo[Com_PduID_LO].dataRaw, UserData_NMSts, 1);
                //CANNM发送数据更新
                CanNm_UserData_ClearBits(&CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_NMSts, 1);
                break;
            case NM_STATE_BUS_SLEEP:/* Bus Sleep State. */
            case NM_STATE_PREPARE_BUS_SLEEP:/* Prepare Bus Sleep State. */
            case NM_STATE_READY_SLEEP:/* Ready Sleep State. */
                for(uint8 i=0;i<6U;i++)
                {
                    //COM发送数据更新
                    Com_TxPduInfo[Com_PduID_LO].dataRaw[i]  = 0x00;
                    //CANNM发送数据更新
                    CanNm_TxMessageData[NmIF_numCanNmChannel_C][i+2] = 0x00;
                }
                break;
            default:
                break;
        }
#endif
#if( CANNM_NM_USER_ENABLE_flgKeyOn == STD_ON )
        //钥匙唤醒
        if(NmIF_flgKeyOn_C)
        {
            if(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw[0]==0x00U)
            {
                //COM发送数据更新
                CanNm_UserData_WriteBits(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw, UserData_WakeUp_flag, 8, 1);
                //CANNM发送数据更新
                CanNm_UserData_WriteBits(&CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_WakeUp_flag, 8, 1);
            }
            //维持源 
            //COM发送数据更新
            CanNm_UserData_WriteBits(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw, UserData_flgKeyOn, 1, 1);
            //CANNM发送数据更新
            CanNm_UserData_WriteBits(&CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_flgKeyOn, 1, 1);

        }else
        {
            //COM发送数据更新
            CanNm_UserData_ClearBits(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw, UserData_flgKeyOn, 1);
            //CANNM发送数据更新
            CanNm_UserData_ClearBits(&CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_flgKeyOn, 1);
        }
#endif
#if( CANNM_NM_USER_ENABLE_flgChargeOn == STD_ON )
        //充电唤醒
        if(NmIF_flgChargeOn_C)
        {
            //唤醒
            if(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw[0] == 0x00U)
            {
                //COM发送数据更新
                CanNm_UserData_WriteBits(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw, UserData_WakeUp_flag, 8, 2);
                //CANNM发送数据更新
                CanNm_UserData_WriteBits(&CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_WakeUp_flag, 8, 2);
            }
            //维持原更新
            //COM发送数据更新
            CanNm_UserData_WriteBits(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw, UserData_flgChargeOn, 1, 1);
            //CANNM发送数据更新
            CanNm_UserData_WriteBits(&CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_flgChargeOn, 1, 1);
        }
        //维持清零
        else
        {
            //COM发送数据更新
            CanNm_UserData_ClearBits(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw, UserData_flgChargeOn, 1);  
            //CANNM发送数据更新
            CanNm_UserData_ClearBits(&CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_flgChargeOn, 1);
        }
        //OBC充电唤醒
        if(NmIF_flgOBC_ON_C)
        {
            //唤醒
            if(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw[0] == 0x00U)
            {
                //COM发送数据更新
                CanNm_UserData_WriteBits(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw, UserData_WakeUp_flag, 8, 2);
                //CANNM发送数据更新
                CanNm_UserData_WriteBits(&CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_WakeUp_flag, 8, 2);
            }
            //维持原更新
            //COM发送数据更新
            CanNm_UserData_WriteBits(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw, UserData_flgOBC_ON, 1, 1);
            //CANNM发送数据更新
            CanNm_UserData_WriteBits(&CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_flgOBC_ON, 1, 1);
        }
        //维持清零
        else
        {
            //COM发送数据更新
            CanNm_UserData_ClearBits(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw, UserData_flgOBC_ON, 1);  
            //CANNM发送数据更新
            CanNm_UserData_ClearBits(&CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_flgOBC_ON, 1);
        }
#endif
#if( CANNM_NM_USER_ENABLE_flgNMWakeUp == STD_ON )   
        //网络唤醒
        if(NmIF_fgNMWakeUpID_0X426_C || NmIF_fgNMWakeUpID_0X40A_C || NmIF_fgNMWakeUpID_0X40D_C)
        {
            if(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw[0]==0x00U)
            {
                //COM发送数据更新
                CanNm_UserData_WriteBits(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw, UserData_WakeUp_flag, 8, 2);
                //CANNM发送数据更新
                CanNm_UserData_WriteBits(&CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_WakeUp_flag, 8, 2);
            }
        }
#endif
        //智能补电,改进通过应用层数据获取智能补电命令原始值，由于唤醒源是NM报文
        if(evpt_hvbd_b_tboxIntelChgCmdRaw)
        {
            //COM发送数据更新
            CanNm_UserData_WriteBits( Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw,UserData_Smart_Charging, 1, 1);
            //NmIF_numCanNmChannel_C
            CanNm_UserData_WriteBits( &CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_Smart_Charging, 1, 1);
        }else
        {
            //清除维持源
            //COM发送数据更新
            CanNm_UserData_ClearBits(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw, UserData_Smart_Charging, 1);   
            //CANNM发送数据更新
            CanNm_UserData_ClearBits(&CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_Smart_Charging, 1);
        }
#if( CANNM_NM_USER_ENABLE_fgDiag_WakeUpDiag == STD_ON )
        //诊断报文维持源
        if (ComM_DcmRequestActive[6]==0x01U)
        {
            // NM 正在被诊断维持!
            //COM发送数据更新
            CanNm_UserData_WriteBits(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw, UserData_fgDiag_WakeUpDiag, 1, 1);
            //CANNM发送数据更新
            CanNm_UserData_WriteBits(&CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_fgDiag_WakeUpDiag, 1, 1);

        }else
        {
            //COM发送数据更新
            CanNm_UserData_ClearBits(Com_TxPduInfo[CanNm_GetTxPduRef(NmIF_numCanNmChannel_C)].dataRaw, UserData_fgDiag_WakeUpDiag, 1);  
            //CANNM发送数据更新
            CanNm_UserData_ClearBits(&CanNm_TxMessageData[NmIF_numCanNmChannel_C][2], UserData_fgDiag_WakeUpDiag, 1);
        }
#endif
    }
    
/**********************************************逻辑实现*****************************************/
}


#if( CANNM_NM_USER_ENABLE_SUPPORTED == STD_ON )
/**
 * CanNM获取用户自定义 NM报文使能情况 
 * 
 * retVal: 0: NM报文发送使能，1: NM报文发送禁止
*/
uint8 CanNm_GetTxUserNMEnable(void)
{
    uint8 retVal = E_NOT_OK;

    /*******************应用层控制标志位获取**************************/
    Rte_Read_BMS_DelayControl_BMS_DelayControl(&ASW_BMS_DelayControl_MP);
    /*******************应用层控制标志位获取**************************/

    //NM报文发送禁止/使能判断    
    if( 1 == ASW_BMS_DelayControl_MP)   //NM报文发送禁止
    {
        retVal = E_NOT_OK;
    }
    else                                //NM报文发送使能
    {
        retVal = E_OK;
    }
    
    return retVal;
}

#endif

/**
 * 从中断中获取收到的ID和通道并置相应标志位
 * 
 * 
*/
void can_NM_USERDATA_FILL_CALLBACK(uint8 Can_valNodeId, uint32 Can_valMsgId)
{
    //CANB NM唤醒报文
    if(Can_valMsgId==0x40D)
    {
        if(Can_valNodeId==CANIF_CHANNEL_N72__PMS_PT_CANFD_20260425__XQC0B_INDEX)
        {
            NmIF_fgNMWakeUpID_0X40D_C        = 1;
            NmIF_numNMWakeUpCounter_0X40D_MP = 0;
        }
    } 
    //CANA NM唤醒报文
    if(Can_valMsgId==0x426)
    {
        if(Can_valNodeId==CANIF_CHANNEL_PMS_EV_CAN_20260427_RMXR12_INDEX)
        {
            NmIF_fgNMWakeUpID_0X426_C        = 1;
            NmIF_numNMWakeUpCounter_0X426_MP = 0;
        }
    }
    //CANA NM唤醒报文
    if(Can_valMsgId==0x40A)
    {
        if(Can_valNodeId==CANIF_CHANNEL_PMS_EV_CAN_20260427_RMXR12_INDEX)
        {
            NmIF_fgNMWakeUpID_0X40A_C        = 1;
            NmIF_numNMWakeUpCounter_0X40A_MP = 0;
        }
    }
    //这里因该还会有一个诊断报文ID判断
    if((Can_valMsgId & 0x700)==0x700)
    {
        NmIF_fgNMWakeUpID_Diag_C=1;
    }
}

/**
 * NM接收标志位清除判断函数
 * 
 * 
*/
void can_NM_WakeUpFlg_Clear(void)
{
    //40D
    if(NmIF_fgNMWakeUpID_0X40D_C == 1)//持续550ms 清除NM唤醒标志位
    {
        if(NmIF_numNMWakeUpCounter_0X40D_MP < 110)
        {
            NmIF_numNMWakeUpCounter_0X40D_MP++;
        }
        else
        {
            NmIF_fgNMWakeUpID_0X40D_C = 0;
        }
    }

    //426
    if(NmIF_fgNMWakeUpID_0X426_C == 1)//持续550ms 清除NM唤醒标志位
    {
        if(NmIF_numNMWakeUpCounter_0X426_MP < 110)
        {
            NmIF_numNMWakeUpCounter_0X426_MP++;
        }
        else
        {
            NmIF_fgNMWakeUpID_0X426_C = 0;
        }
    }

    //40A
    if(NmIF_fgNMWakeUpID_0X40A_C == 1)//持续550ms 清除NM唤醒标志位
    {
        if(NmIF_numNMWakeUpCounter_0X40A_MP < 110)
        {
            NmIF_numNMWakeUpCounter_0X40A_MP++;
        }
        else
        {
            NmIF_fgNMWakeUpID_0X40A_C = 0;
        }
    }
}


/**
 * @brief 位填充: 向 buffer 的指定 bitIndex 位置写入 value。
 *
 * @param buffer    目标缓冲区
 * @param bitIndex  位索引，从 0 开始。
 *                  例如 37 -> byte4 bit5，50 -> byte6 bit2
 * @param bitWidth  位宽 (1..8)，要求 bitOffset + bitWidth <= 8
 * @param value     待写入的值（超出位宽的高位会被截断）
 */
void CanNm_UserData_WriteBits(uint8* buffer,
                              uint16 bitIndex,
                              uint8  bitWidth,
                              uint64 value)
{
    uint8  byteIndex;
    uint8  bitOffset;
    uint8  mask;
    uint8  shiftedValue;
    uint64 valueMask;

    /* 参数校验 */
    if (((void*)0) == buffer)
    {
        return;
    }

    if ((bitWidth == 0u) || (bitWidth > 8u))
    {
        return;
    }

    /* 位索引换算成 byteIndex 和 bitOffset */
    if ((uint32)bitIndex >= ((uint32)CANNM_UD_BUFFER_LENGTH * 8u))
    {
        return;
    }

    byteIndex = (uint8)(bitIndex / 8u);
    bitOffset = (uint8)(bitIndex % 8u);

    if (((uint16)bitOffset + (uint16)bitWidth) > 8u)
    {
        return;
    }

    /* 构造掩码: e.g. bitOffset=2, bitWidth=3 => mask=0b00011100 */
    mask = (uint8)(((1u << bitWidth) - 1u) << bitOffset);

    /* 截断 value 到位宽，并移位到目标位置 */
    valueMask = ((uint64)1u << bitWidth) - 1u;
    shiftedValue = (uint8)((value & valueMask) << bitOffset);

    /* 先清零目标位域，再写入新值 */
    buffer[byteIndex] &= (uint8)(~mask);
    buffer[byteIndex] |= shiftedValue;
}


/**
 * @brief 位消除: 清零 buffer 的指定 bitIndex 位置。
 *
 * @param buffer    目标缓冲区
 * @param bitIndex  位索引，从 0 开始。
 *                  例如 37 -> byte4 bit5，50 -> byte6 bit2
 * @param bitWidth  位宽 (1..8)，要求 bitOffset + bitWidth <= 8
 */
void CanNm_UserData_ClearBits(uint8* buffer,
                              uint16 bitIndex,
                              uint8  bitWidth)
{
    uint8 byteIndex;
    uint8 bitOffset;
    uint8 mask;

    /* 参数校验 */
    if (((void*)0) == buffer)
    {
        return;
    }

    if ((bitWidth == 0u) || (bitWidth > 8u))
    {
        return;
    }

    /* 位索引换算成 byteIndex 和 bitOffset */
    if ((uint32)bitIndex >= ((uint32)CANNM_UD_BUFFER_LENGTH * 8u))
    {
        return;
    }

    byteIndex = (uint8)(bitIndex / 8u);
    bitOffset = (uint8)(bitIndex % 8u);

    if (((uint16)bitOffset + (uint16)bitWidth) > 8u)
    {
        return;
    }

    /* 构造掩码并清零目标位域 */
    mask = (uint8)(((1u << bitWidth) - 1u) << bitOffset);
    buffer[byteIndex] &= (uint8)(~mask);
}


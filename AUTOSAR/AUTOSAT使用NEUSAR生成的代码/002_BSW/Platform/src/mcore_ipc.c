/*PRQA S 2052,3108 EOF*/
///****************************************************************************
//*
//* Copyright (c) 2023  C*Core -   All Rights Reserved
//*
//* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
//* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//*
//* @file     mocre_ipc.c
//* @version  3.0.0
//* @date     2023 - 07 - 31
//* @brief    Initial version.
//*****************************************************************************/
//
//#include "mcore_ipc.h"/*PRQA S 0380*/
///*PRQA S 1504,1503,3387 EOF*/
//volatile static HeartBeat g_heart_beat[CORE_ID_BUTT]; /*PRQA S 3228*/
//static ShareBuf g_share_buf[CORE_ID_BUTT];
//static uint32_t common_value = 0U;
//static uint32_t common_mask = 0U;
//
//void IPC_Update_Heart_Beat(void)
//{
//    CoreId core_id = Mcu_LLD_Get_Core_Id();
//    g_heart_beat[core_id].heart_beat++;
//}
//
//uint32_t IPC_Get_Heart_Beat(CoreId core_id)
//{
//    return g_heart_beat[core_id].heart_beat;
//}
//
//void IPC_Update_Share_Buf(const uint8_t *buf, uint32_t len)
//{
//    CoreId core_id = Mcu_LLD_Get_Core_Id();
//    cc_memcpy((uint8_t *)&g_share_buf[core_id].share_buf[0], buf, len);
//}
//
//ShareBuf *IPC_Get_Share_Buf(CoreId core_id)
//{
//    return &g_share_buf[core_id];
//}
//
//void Set_Common_Mask(void)
//{
//    common_mask = 0x5A5A;
//}
//
//uint32_t Get_Common_Mask(void)
//{
//    return common_mask;
//}
//
//void Sema42_Test_Value_Update(void)
//{
//    common_value++;
//}
//
//uint32_t Sema42_Get_Test_Value(void)
//{
//    return common_value;
//}

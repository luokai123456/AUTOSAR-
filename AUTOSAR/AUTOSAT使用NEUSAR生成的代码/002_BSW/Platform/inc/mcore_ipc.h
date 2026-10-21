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
//#ifndef _MCORE_IPC_H_
//#define _MCORE_IPC_H_/*PRQA S 0603,0602*/
///*PRQA S 3630 EOF*/
//#include "Mcu_LLDriver.h"
//
//#define MCORE_SHARE_BUF_SIZE 0x100
//
//#define MCORE_SHARE_MEM_DESC __attribute__ ((section (".data_share")))
//
//typedef struct {
//    uint32_t heart_beat;
//} HeartBeat;
//
//typedef struct {
//    uint32_t share_len;
//    uint32_t share_buf[MCORE_SHARE_BUF_SIZE];
//} ShareBuf;
//
//
//void IPC_Update_Heart_Beat(void);
//uint32_t IPC_Get_Heart_Beat(CoreId core_id);
//void IPC_Update_Share_Buf(const uint8_t *buf, uint32_t len);
//ShareBuf *IPC_Get_Share_Buf(CoreId core_id);
//void Set_Common_Mask(void);
//uint32_t Get_Common_Mask(void);
//void Sema42_Test_Value_Update(void);
//uint32_t Sema42_Get_Test_Value(void);
//#endif

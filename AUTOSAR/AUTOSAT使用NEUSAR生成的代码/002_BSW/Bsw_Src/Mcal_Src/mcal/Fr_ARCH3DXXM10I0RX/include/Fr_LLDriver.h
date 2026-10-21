/* PRQA S 0722, 1536 EOF */
/****************************************************************************
 *
 * Copyright (c) 2023  C*Core -   All Rights Reserved
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *   Project              : AUTOSAR 4.4.0 MCAL
 *   Platform             : PowerPC e200
 *   Peripheral           :
 *   Dependencies         :
 *
 *   Autosar Version      : 4.4.0
 *   Autosar Revision     : ASR_REL_4_3_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           :
 *   Build Version        :
 *
 *****************************************************************************/

/**
 *   @file    Fr_LLDriver.h
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR 4.4.0 - Common Level Driver header file.
 *   @details Autosar layer of Fr MCAL driver.
 *
 *   @addtogroup Fr
 *   @{
 */
#ifndef FLEXRAY_LLD_H_
#define FLEXRAY_LLD_H_

#ifdef __cplusplus
extern "C"{
#endif
/******************************************************************************
* Includes
******************************************************************************/
#include "derivative.h"
#ifdef RESOURCE_SUPPORT_FLEXRAY
#include "Fr.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FR_LLD_H_VENDOR_ID                        176
#define FR_LLD_H_AR_RELEASE_MAJOR_VERSION         4
#define FR_LLD_H_AR_RELEASE_MINOR_VERSION         4
/* @violates @ref FR_FR_H_REF_2 */
#define FR_LLD_H_AR_RELEASE_REVISION_VERSION      0
#define FR_LLD_H_SW_MAJOR_VERSION                 3
#define FR_LLD_H_SW_MINOR_VERSION                 0
#define FR_LLD_H_SW_PATCH_VERSION                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr_Cfg.h header file are of the same vendor */
#if(FR_CFG_H_VENDOR_ID != FR_LLD_H_VENDOR_ID)
    #error "Fr_LLDriver.h and Fr_Cfg.h have different Vendor IDs"
#endif
/* Check if current file and Fr_Cfg.h header file are of the same Autosar version */
#if((FR_LLD_H_AR_RELEASE_MAJOR_VERSION    != FR_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
    (FR_LLD_H_AR_RELEASE_MINOR_VERSION    != FR_CFG_H_AR_RELEASE_MINOR_VERSION) || \
    (FR_LLD_H_AR_RELEASE_REVISION_VERSION != FR_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_LLDriver.h and Fr_Cfg.h are different"
#endif
/* Check if current file and Fr_Cfg.h header file are of the same software version */
#if((FR_LLD_H_SW_MAJOR_VERSION != FR_CFG_H_SW_MAJOR_VERSION) || \
    (FR_LLD_H_SW_MINOR_VERSION != FR_CFG_H_SW_MINOR_VERSION) || \
    (FR_LLD_H_SW_PATCH_VERSION != FR_CFG_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_LLDriver.h and Fr_Cfg.h are different"
#endif

/******************************************************************************
* Constants
******************************************************************************/

/* This constant is used to correctly handle the situation when the driver
waits till the PE accepts a command (e.g. the protocol control command).
In such a case, the driver will be waiting in the loop (maximum FR_MAX_WAIT_CYCLES
iterations) until a proper value appears in the required register. */

#define FR_MAX_WAIT_CYCLES      100U

#define F_MAX_NMVREAD_CNT       5U

/* Maximal number of used MB except FIFO storage and shadow message buffers */
#define FR_MAX_NUMBER_TXRX_MB    128U   

typedef enum Fr_LLDriver_Status
{
    StatusErro = 0,
    StatusSuss/* data */
}Fr_LLDriver_StatusType;

/* Structure of this type contains names of service callback functions which are stored by driver for internal use and 
    will be called by the Fr_interrupt_handler() function when an interrupt occurs. */
typedef struct
{
     /* Callback function for Module Interrupt Flag in the GIFER reg. */
    void (* Fr_module_ptr) (void);     
    /* Callback function for Protocol Interrupt Flag in the GIFER reg. */
    void (* Fr_protocol_ptr) (void);    
    /* Callback function for CHI Interrupt Flag in the GIFER reg. */
    void (* Fr_chi_ptr) (uint16 chi_error); 
 /* Callback function for Wakeup Interrupt Flag in the GIFER reg. */
    void (* Fr_wakeup_ptr) (Fr_ChannelType wakeup_channel);
/* Callback function for FIFO B Interrupt Flag in the GIFER reg. */
    void (* Fr_fifo_B_ptr) (uint16 header_index);   
/* Callback function for FIFO A Interrupt Flag in the GIFER reg. */
    void (* Fr_fifo_A_ptr) (uint16 header_index);   
/* Callback function for FATL_IF Interrupt Flag in the PIFR0 reg. */
    void (* Fr_fatal_protocol_error_ptr) (void);    
/* Callback function for INTL_IF Interrupt Flag in the PIFR0 reg. */
    void (* Fr_internal_protocol_error_ptr) (void); 
/* Callback function for ILCF_IF Interrupt Flag in the PIFR0 reg. */
    void (* Fr_illegal_protocol_conf_ptr) (void);   
/* Callback function for CSA_IF Interrupt Flag in the PIFR0 reg. */
    void (* Fr_coldstart_abort_ptr) (void);         
/* Callback function for MRC_IF Interrupt Flag in the PIFR0 reg. */
    void (* Fr_missing_rate_corr_ptr) (void);       
/* Callback function for MOC_IF Interrupt Flag in the PIFR0 reg. */
    void (* Fr_missing_offset_corr_ptr) (void);     
/* Callback function for CCL_IF Interrupt Flag in the PIFR0 reg. */
    void (* Fr_clock_corr_limit_ptr) (void);        
/* Callback function for MXS_IF Interrupt Flag in the PIFR0 reg. */
    void (* Fr_max_sync_frames_ptr) (void);         
 /* Callback function for MTX_IF Interrupt Flag in the PIFR0 reg. */
    void (* Fr_mts_received_ptr) (void);           
/* Callback function for LTXB_IF Interrupt Flag in the PIFR0 reg. */
    void (* Fr_violation_B_ptr) (void);             
 /* Callback function for LTXA_IF Interrupt Flag in the PIFR0 reg. */
    void (* Fr_violation_A_ptr) (void);            
/* Callback function for TBVB_IF Interrupt Flag in the PIFR0 reg. */
    void (* Fr_trans_across_boundary_B_ptr) (void); 
/* Callback function for TBVA_IF Interrupt Flag in the PIFR0 reg. */ 
    void (* Fr_trans_across_boundary_A_ptr) (void); 
/* Callback function for TI2_IF Interrupt Flag in the PIFR0 reg.  */ 
    void (* Fr_timer_2_expired_ptr) (void);         
     /* Callback function for TI1_IF Interrupt Flag in the PIFR0 reg.  */
    void (* Fr_timer_1_expired_ptr) (void);        
/* Callback function for CYS_IF Interrupt Flag in the PIFR0 reg.  */  
    void (* Fr_cycle_start_ptr) (void);             
/* Callback function for EMC_IF Interrupt Flag in the PIFR1 reg.   */  
    void (* Fr_error_mode_changed_ptr) (void);      
/* Callback function for IPC_IF Interrupt Flag in the PIFR1 reg. */
    void (* Fr_illegal_protocol_command_ptr) (void);    
/* Callback function for PECF_IF Interrupt Flag in the PIFR1 reg. */
    void (* Fr_protocol_engine_comm_failure_ptr) (void); 
/* Callback function for PSC_IF Interrupt Flag in the PIFR1 reg.  */
    void (* Fr_protocol_state_changed_ptr) (void);  
/* Callback function for SSI3_IF Interrupt Flag in the PIFR1 reg. */
    void (* Fr_slot_status_counter_3_inc_ptr) (void);   
/* Callback function for SSI2_IF Interrupt Flag in the PIFR1 reg. */
    void (* Fr_slot_status_counter_2_inc_ptr) (void);   
/* Callback function for SSI1_IF Interrupt Flag in the PIFR1 reg. */
    void (* Fr_slot_status_counter_1_inc_ptr) (void);   
    /* Callback function for SSI0_IF Interrupt Flag in the PIFR1 reg. */
    void (* Fr_slot_status_counter_0_inc_ptr) (void);   
     /* Callback function for EVT_IF Interrupt Flag in the PIFR1 reg. */
    void (* Fr_even_cycle_table_written_ptr) (void);   
    /* Callback function for ODT_IF Interrupt Flag in the PIFR1 reg. */
    void (* Fr_odd_cycle_table_written_ptr) (void);     
} Fr_callback_functions_type;

/******************************************************************************
* Global variables
******************************************************************************/
/* This internal array contains message buffer configuration information (except shadow message buffers and FIFO storage).*/
#ifdef FR_NUMBER_TXRX_MB
/* The FR_NUMBER_TXRX_MB parameter is defined in the flexray_cfg.h file 
   - memory consumption optimization is applied */
    /* The LLD Driver allocates following array with limited number of elements */
    /* - the number is given by host in the flexray_cfg.h file */
extern VAR(Fr_MB_information_internal_type, FR_VAR) Fr_MB_information_internal[FR_NUMBER_TXRX_MB + 1U];
#else
extern VAR(Fr_MB_information_internal_type, FR_VAR) Fr_MB_information_internal[FR_MAX_NUMBER_TXRX_MB];
#endif

extern volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_CC_reg_ptr;
/******************************************************************************
* Global functions
******************************************************************************/

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Init(P2CONST(Fr_HW_config_type, AUTOMATIC, FR_APPL_CONST) Fr_HW_config_temp_ptr, P2CONST(Fr_low_level_config_type, AUTOMATIC, FR_APPL_CONST) Fr_low_level_config_temp_ptr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
                            
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_LLD_Set_Configuration(P2CONST(Fr_HW_config_type, AUTOMATIC, FR_APPL_CONST) Fr_HW_config_temp_ptr, P2CONST(Fr_low_level_config_type, AUTOMATIC, FR_APPL_CONST) Fr_low_level_config_temp_ptr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
                           
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Buffers_Init(VAR(uint8, FR_VAR) Fr_CtrlIdx,P2CONST(Fr_buffer_info_type, AUTOMATIC, FR_APPL_CONST) Fr_buffers_config_temp_ptr, P2CONST(Fr_index_selector_type, AUTOMATIC, FR_APPL_CONST) Fr_buffer_config_set_temp_ptr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Leave_Configuration_Mode(VAR(void, FR_VAR));
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Start_Communication(VAR(void, FR_VAR));
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Stop_Communication(VAR(Fr_stop_communication_type, FR_VAR) Fr_stop_option);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Send_Wakeup(VAR(void, FR_VAR));
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_WakeupStatusType, FR_CODE) Fr_LLD_Get_Wakeup_State(VAR(void, FR_VAR));
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_POCStateType, FR_CODE) Fr_LLD_Get_POC_State(VAR(void, FR_VAR));
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Enter_Configuration_Mode(VAR(void, FR_VAR));
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_LLD_Get_Global_Time(P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_cycle_ptr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_macrotick_ptr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_LLD_Get_Network_Management_Vector(P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_vector_ptr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_tx_MB_status_type, FR_CODE) Fr_LLD_Transmit_Data(VAR(uint16, FR_VAR) Fr_buffer_idx, P2CONST(uint8, AUTOMATIC, FR_APPL_CONST) Fr_data_ptr, VAR(uint8, FR_VAR) Fr_data_length);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_RxLPduStatusType, FR_CODE) Fr_LLD_Receive_Data(VAR(uint16, FR_VAR) Fr_buffer_idx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_ptr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_length_ptr,P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) Fr_SlotAssignmentPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
                    
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_FIFO_status_type, FR_CODE) Fr_LLD_Receive_FifoA_Data(P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_ptr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_length_ptr, P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) Fr_SlotAssignmentPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_FIFO_status_type, FR_CODE) Fr_LLD_Receive_FifoB_Data(P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_ptr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_length_ptr, P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) Fr_SlotAssignmentPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_LLD_Enable_Interrupts(VAR(uint16, FR_VAR) Fr_global_interrupt, VAR(uint16, FR_VAR) Fr_protocol_0_interrupt, VAR(uint16, FR_VAR) Fr_protocol_1_interrupt);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_LLD_Disable_Interrupts(VAR(uint16, FR_VAR) Fr_global_interrupt, VAR(uint16, FR_VAR) Fr_protocol_0_interrupt, VAR(uint16, FR_VAR) Fr_protocol_1_interrupt);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_LLD_Interrupt_Handler(VAR(void, FR_VAR));
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_LLD_Set_MB_Callback(P2FUNC(void,FR_APPL_CODE,MB_callback_ptr)(VAR(uint8, FR_VAR) Fr_int_buffer_idx), VAR(uint8, FR_VAR) Fr_buffer_idx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Set_Global_IRQ_Callback(P2FUNC(void,FR_APPL_CODE,callback_ptr)(void), VAR(uint16, FR_VAR) Fr_global_interrupt);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Set_Protocol_0_IRQ_Callback(P2FUNC(void,FR_APPL_CODE,callback_ptr)(void), VAR(uint16, FR_VAR) Fr_protocol_interrupt);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Set_Protocol_1_IRQ_Callback(P2FUNC(void,FR_APPL_CODE,callback_ptr)(void), VAR(uint16, FR_VAR) Fr_protocol_interrupt);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_LLD_Set_Wakeup_IRQ_Callback(P2FUNC(void,FR_APPL_CODE,callback_ptr)(VAR(Fr_ChannelType, FR_VAR) wakeup_channel));
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_LLD_Set_Chi_IRQ_Callback(P2FUNC(void,FR_APPL_CODE,callback_ptr)(VAR(uint16, FR_VAR) chi_error));
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Set_Fifo_IRQ_Callback(P2FUNC(void,FR_APPL_CODE,callback_ptr)(VAR(uint16, FR_VAR) header_index), VAR(uint16, FR_VAR) Fr_global_interrupt);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_LLD_Start_Timer(VAR(Fr_timer_ID_type, FR_VAR) timer_ID);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_Stop_Timer(VAR(Fr_timer_ID_type, FR_VAR) timer_ID);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_LLD_Check_Tx_Status(P2CONST(Fr_CtrlCfgType, AUTOMATIC, *)pCtrlCfg, VAR(uint16, FR_VAR) Fr_LPduIdx,P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) pSlotAssignment,P2VAR(Fr_TxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_TxLPduStatusPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(uint16, FR_CODE) Fr_LLD_Low_Level_Access_Read_Reg(VAR(uint16, FR_VAR) Fr_required_register);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_LLD_Low_Level_Access_Write_Reg(VAR(uint16, FR_VAR) Fr_required_register, VAR(uint16, FR_VAR) Fr_value);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(uint16, FR_CODE) Fr_LLD_Low_Level_Access_Read_Memory(VAR(uint16, FR_VAR) Fr_memory_address);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_LLD_Low_Level_Access_Write_Memory(VAR(uint16, FR_VAR) Fr_memory_address, VAR(uint16, FR_VAR) Fr_value);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_CheckCCAccess(VAR(void, FR_VAR));
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_SetAbsTimers(VAR(uint8, AUTOMATIC) timerIdx,VAR(uint8, AUTOMATIC) cycle,VAR(uint16, AUTOMATIC) offset);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_Driver_DisableTimers(VAR(void, FR_VAR));
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_Driver_GetChannelStatus( P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelAStatusPtr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelBStatusPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_InvokeCHICommand(VAR(uint16, AUTOMATIC) CHICommand);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_SetWakeupChannel(VAR(Fr_ChannelType, FR_VAR) Fr_ChnlIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_FrExtendedLPduReport(P2CONST(Fr_CtrlCfgType, AUTOMATIC, *) pCtrlCfg,
                                                        VAR(uint16, AUTOMATIC) mb_index, P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) pSlotAssignment);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_Driver_AckAbsTimerIRQ(VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(boolean, FR_CODE) Fr_Driver_GetAbsoluteTimerIRQStatus(VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_ReadCCConfig(P2CONST(Fr_low_level_config_type, AUTOMATIC, *) Fr_low_level_config_ptr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_GetPOCStatus(P2VAR(Fr_POCStatusType, AUTOMATIC, FR_APPL_DATA) pPocState);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_GetStartupState(VAR(uint16, AUTOMATIC) PSR0,P2VAR(Fr_StartupStateType, AUTOMATIC, FR_APPL_DATA) pStartupState);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_GetErrorMode
(
    VAR(uint16, AUTOMATIC) u16RegValuePSR0,
    P2VAR(Fr_ErrorModeType, AUTOMATIC, FR_APPL_DATA) pErrorMode
);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_GetSlotMode
(
    VAR(uint16, AUTOMATIC) PSR0,
    P2VAR(Fr_SlotModeType, AUTOMATIC, FR_APPL_DATA) pSlotMode
);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_GetWakeupRxStatus
(
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) pu8WakeupRxStatus);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_GetClockCorrection
(
    P2VAR(sint16, AUTOMATIC, FR_APPL_DATA) ps16RateCorrection,
    P2VAR(sint32, AUTOMATIC, FR_APPL_DATA) ps32OffsetCorrection
);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#if (FR_RECONFIG_LPDU_SUPPORT == STD_ON)
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_ReconfigLPdu
(
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg,
    VAR(uint16, AUTOMATIC) Mbindex,
    VAR(uint16, AUTOMATIC) FrameId,
    VAR(Fr_ChannelType, AUTOMATIC) chnlIdx,
    VAR(uint8, AUTOMATIC) CycleRepetition,
    VAR(uint8, AUTOMATIC) CycleOffset,
    VAR(uint8, AUTOMATIC) PayloadLength,
    VAR(uint16, AUTOMATIC) HeaderCRC
);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_PrepareLPdu
(
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg,
    uint16 Mbindex,
    VAR(uint16, AUTOMATIC) LPduIdx
);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif

#if (FR_DISABLE_LPDU_SUPPORT == STD_ON)
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_DisableLPdu
(
    VAR(uint16, AUTOMATIC) MbIdx
);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_GetSyncFrameList
(
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg,
    VAR(uint8, AUTOMATIC) u8ListSize,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) pu16ChannelAEvenList,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) pu16ChannelBEvenList,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) pu16ChannelAOddList,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) pu16ChannelBOddList
);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_Driver_CancelTxLPdu
(
    VAR(uint16, AUTOMATIC) Mbidx,
    P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) pbPendingStatus
);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/******************************************************************************
* End of file
******************************************************************************/
#endif /* RESOURCE_SUPPORT_FLEXRAY */

#ifdef __cplusplus
}
#endif

#endif /* FR_H */

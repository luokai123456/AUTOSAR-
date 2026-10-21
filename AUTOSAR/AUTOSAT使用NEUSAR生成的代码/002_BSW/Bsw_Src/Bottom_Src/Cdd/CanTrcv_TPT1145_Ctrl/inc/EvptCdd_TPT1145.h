/**********************************************************************************************************************
*
* COPYRIGHT RESERVED, Tianjin Yidingfeng Power Technology, 2012. All rights reserved.
* The reproduction, distribution and utilization of this document as well as the communication of its contents to
* others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
* All rights reserved in the event of the grant of a patent, utility model or design.
*
**********************************************************************************************************************
* Administrative Information
* Namespace_:
* Class_____:H
* Name______:EvptCdd_TPT1145
* Variant___:75.16.01
* Revision__:0
**********************************************************************************************************************
 * History___:
 *
 * 75.16.01; 0     28.06.2023 SH-RD  Kaili.Shentu
 *   N: new created
 *
 * 
 * 
 * 
***********************************************************************************************************************/
#ifndef EVPTCDD_TPT1145_H
#define EVPTCDD_TPT1145_H
/*
***************************************************************************************************
* Includes
***************************************************************************************************
*/
#include "EvptCdd_CanTrcv_Cfg.h"
#include "Spi.h"
#include "Dem.h"
#include "EcuM.h"
#include "Std_Types.h"
#include "Can_GeneralTypes.h"
/**
 ***************************************************************************************************
*
*
*               DEFINES
*
*
****************************************************************************************************
*/
#define Spi_DataType uint16

typedef enum
{
    CANTRCV_PN_ENABLED  = 0,
    CANTRCV_PN_DISABLED = 1
}CanTrcv_PNActivationType;

typedef enum
{
    CANTRCV_FLAG_SET        = 0,
    CANTRCV_FLAG_CLEARED    = 1
}CanTrcv_TrcvFlagStateType;

/**
 * @ingroup CAN_GENERALTYPES_H
 *
 * Wake up reason detected by the CAN transceiver.
 * typedef enum
 * {
 *  CANTRCV_WU_ERROR=0,         Wake up reason not detected due to some error. This may only be reported when error was reported to DEM before \n
 *  CANTRCV_WU_NOT_SUPPORTED,   The transceiver does not support any information for the wake up reason.\n
 *  CANTRCV_WU_BY_BUS,          The transceiver has detected, that the network has caused the wake up of the ECU.\n
 *  CANTRCV_WU_INTERNALLY,      The transceiver has detected, that the network has woken up by the ECU via a request to NORMAL mode. \n
 *  CANTRCV_WU_RESET,           The transceiver has detected, that the "wake up" is due to an ECU reset. \n
 *  CANTRCV_WU_POWER_ON,        The transceiver has detected, that the "wake up" is due to an ECU reset after power on.\n
 *  CANTRCV_WU_BY_PIN           The transceiver has detected a wake-up event at one of the transceiver's pins (not at the CAN bus). \n
 * }CanTrcv_TrcvWakeupReasonType;
 */
//typedef enum
//{
//    CANTRCV_WU_ERROR=0,
//    CANTRCV_WU_NOT_SUPPORTED,
//    CANTRCV_WU_BY_BUS,
//    CANTRCV_WU_INTERNALLY,
//    CANTRCV_WU_RESET,
//    CANTRCV_WU_POWER_ON,
//    CANTRCV_WU_BY_PIN
//}CanTrcv_TrcvWakeupReasonType;

/**
 * @ingroup CAN_GENERALTYPES_H
 *
 * CAN transceiver concerned wake up events and wake up notifications.                                  \n
 * typedef enum                                                                                         \n
 * {                                                                                                    \n
 *  CANTRCV_WUMODE_ENABLE=0,    The notification for wakeup events is enabled on the addressed network. \n
 *  CANTRCV_WUMODE_DISABLE,     The notification for wakeup events is disabled on the addressed network.\n
 *  CANTRCV_WUMODE_CLEAR        A stored wakeup event is cleared on the addressed network.              \n
 * }CanTrcv_TrcvWakeupModeType;
 */
//typedef enum
//{
//    CANTRCV_WUMODE_ENABLE=0,
//    CANTRCV_WUMODE_DISABLE,
//    CANTRCV_WUMODE_CLEAR
//}CanTrcv_TrcvWakeupModeType;

extern Std_ReturnType CanTrcv_SetOpMode_TPT1145(uint8 Transceiver, CanTrcv_TrcvModeType OpMode);
#if (CANTRCV_CFG_WAKEUP_BY_NODE_USED == STD_ON) || ( CANTRCV_CFG_SPI_TPT1145_USED == STD_ON )
extern boolean CanTrcv_WakeupModeState_ab[];
#endif

#if ( CANTRCV_CFG_SPI_TPT1145_USED == STD_ON )
extern uint16                 CanTrcv_Prv_TPT1145_SpiState[];
extern CanTrcv_TrcvModeType   CanTrcv_Prv_TPT1145_State[];
extern CanTrcv_TrcvModeType   CanTrcv_Prv_TPT1145_ReqState[];
extern Spi_DataType           CanTrcv_Prv_TPT1145_SpiInitRxBuf_ao[CANTRCV_CFG_TPT1145_MAX][CANTRCV_CFG_TPT1145_SPI_INIT_MAX];
extern Spi_DataType           CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[CANTRCV_CFG_TPT1145_MAX][CANTRCV_CFG_TPT1145_SPI_CTRL_MAX];
extern Spi_DataType           CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[CANTRCV_CFG_TPT1145_MAX][CANTRCV_CFG_TPT1145_SPI_CTRL_MAX];
extern uint8                  CanTrcv_Prv_TPT1145_Wakeup_au8[];   /* 0=no wakeup; 1=wakeup detected */
#endif

/*  Extern Function Definations */
/***************************************************************************************************
*
*               CAN TRANSCEIVER DRIVER SPECIFIC FUNCTIONS
*
****************************************************************************************************
*/

extern  void            CanTrcv_Init( void);
Std_ReturnType  CanTrcv_SetOpMode( uint8 Transceiver,CanTrcv_TrcvModeType OpMode);
Std_ReturnType  CanTrcv_GetOpMode( uint8 Transceiver,CanTrcv_TrcvModeType* OpMode );
Std_ReturnType  CanTrcv_GetBusWuReason( uint8 Transceiver,CanTrcv_TrcvWakeupReasonType* reason);
Std_ReturnType  CanTrcv_SetWakeupMode( uint8 Transceiver,CanTrcv_TrcvWakeupModeType TrcvWakeupMode);
Std_ReturnType  CanTrcv_CheckWakeup( uint8 Transceiver);
Std_ReturnType  CanTrcv_CheckWakeFlag(uint8 Transceiver);
Std_ReturnType  CanTrcv_SetPNActivationState(CanTrcv_PNActivationType ActivationState);
Std_ReturnType  CanTrcv_ClearTrcvWufFlag(uint8 Transceiver);

# if (CANTRCV_HW_PN_SUPPORT == STD_ON)
Std_ReturnType  CanTrcv_ReadTrcvTimeoutFlag( uint8 Transceiver, CanTrcv_TrcvFlagStateType* FlagState );
Std_ReturnType  CanTrcv_ClearTrcvTimeoutFlag( uint8 Transceiver );
Std_ReturnType  CanTrcv_ReadTrcvSilenceFlag( uint8 Transceiver, CanTrcv_TrcvFlagStateType* FlagState );
void            CanTrcv_MainFunctionDiagnostics( void );
# endif

# if ((CANTRCV_CFG_WAKEUP_BY_NODE_USED == STD_ON) || ( CANTRCV_CFG_SPI_TPT1145_USED == STD_ON ))
extern void            CanTrcv_TPT1145_MainFunction_10ms( void );
# endif

typedef void (*CanTrcv_PowerOffProcess)(void);
Std_ReturnType CanTrcv_ProcessKL30WakeupPowerDown(CanTrcv_PowerOffProcess func);

#endif  /* CAN_TRCV_H_ */


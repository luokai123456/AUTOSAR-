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
* Name______:CanTrcv_prv
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
#ifndef CANTRCV_PRV_H
#define CANTRCV_PRV_H

#include "EvptCdd_TPT1145.h"
/**
 ***************************************************************************************************
*
*
*               DEFINES
*
*
****************************************************************************************************
*/

# define CANTRCV_TRUE_B             (1==1)
# define CANTRCV_FALSE_B            (1==2)
/* The following identifiers should not be use by the user of this component, it is listed here for information only and for reference on error*/
enum
{
    CANTRCV_E_INVALID_TRANSCEIVER        =0x01,
    CANTRCV_E_PARAM_POINTER              =0x02,
    CANTRCV_E_UNINIT                     =0x11,
    CANTRCV_E_TRCV_NOT_STANDBY           =0x21,
    CANTRCV_E_TRCV_NOT_NORMAL            =0x22,
    CANTRCV_E_PARAM_TRCV_WAKEUP_MODE     =0x23,
    CANTRCV_E_PARAM_TRCV_OPMODE          =0x24,
    CANTRCV_E_PARAM_TRCV_WRONG_CONF      =0x30,
    CANTRCV_E_SPI                        =0x31
};

/* The following identifiers should not be use by the user of this component, it is listed here for information only and for reference on error*/
enum
{
    CANTRCV_SID_INIT                     = 0x00,
    CANTRCV_SID_SETOPMODE                = 0x01,
    CANTRCV_SID_GETOPMODE                = 0x02,
    CANTRCV_SID_GETBUSWUREASON           = 0x03,
    CANTRCV_SID_GETVERSIONINFO           = 0x04,
    CANTRCV_SID_SETWAKEUPMODE            = 0x05,
    CANTRCV_SID_MAINFUNCTION             = 0x06,
    CANTRCV_SID_CHECKWAKEUP              = 0x07,
    CANTRCV_SID_MAINFUNCTIONDIAGNOSTICS  = 0x08,
    CANTRCV_SID_GETTRCVSYSTEMDATA        = 0x09,
    CANTRCV_SID_CLEARTRCVWUFFLAG         = 0x0a,
    CANTRCV_SID_READTRCVTIMEOUTFLAG      = 0x0b,
    CANTRCV_SID_CLEARTRCVTIMEOUTFLAG     = 0x0c,
    CANTRCV_SID_READTRCVSILENCEFLAG      = 0x0d,
    CANTRCV_SID_CHECKWAKEFLAG            = 0x0e,
    CANTRCV_SID_SETPNACTIVATIONSTATE     = 0x0f,
    CANTRCV_SID_RB_GETERROR              = 0x20
};

#if (CANTRCV_DEV_ERROR_DETECT == STD_ON)

# ifndef CANTRCV_DET_REPORTERROR
# define CANTRCV_DET_REPORTERROR ((void)Det_ReportError)
# endif

# define CANTRCV_CHECKDET_RETURN(Idx, FuncId, ErrId) \
           do{(void)Det_ReportError(CANTRCV_MODULE_ID,Idx,FuncId, ErrId); return E_NOT_OK;}while(0)
# define CANTRCV_CHECKDET_NORETURN(Idx, FuncId, ErrId) \
           do{(void)Det_ReportError(CANTRCV_MODULE_ID, Idx, FuncId, ErrId); }while(0)
# define CANTRCV_CHECKDETINIT_RETURN(state, Idx, FuncId)   do{if((state) == CANTRCV_FALSE_B) \
           {(void)Det_ReportError(CANTRCV_MODULE_ID, Idx, FuncId, CANTRCV_E_UNINIT); return E_NOT_OK;}}while(0)
# define CANTRCV_CHECKDETINIT_NORETURN(state, Idx, FuncId)  do{if((state) == CANTRCV_FALSE_B) \
           {(void)Det_ReportError(CANTRCV_MODULE_ID, Idx, FuncId, CANTRCV_E_UNINIT);}}while(0)
# define CANTRCV_CHECKDETTRCVIDX_RETURN(Idx,FuncId)  do{if((Idx) >= CANTRCV_CFG_NUMBER_OF_CANTRCV) \
           {(void)Det_ReportError(CANTRCV_MODULE_ID, Idx, FuncId, CANTRCV_E_INVALID_TRANSCEIVER);return E_NOT_OK;}}while(0)
# define CANTRCV_CHECKDETNULLPTR_RETURN(Idx, Ptr, FuncId)  do{if((Ptr) == NULL_PTR) \
           {(void)Det_ReportError(CANTRCV_MODULE_ID, Idx, FuncId,   CANTRCV_E_PARAM_POINTER);return E_NOT_OK;}}while(0)
# define CANTRCV_CHECKDET_TRCVSTATE_RETURN(Idx, CurrentMode, AllowedMode1, AllowedMode2, FuncId, ErrId) do \
           {if(((CurrentMode) != (AllowedMode1)) || ((CurrentMode) != (AllowedMode2))) \
           {(void)Det_ReportError(CANTRCV_MODULE_ID, Idx, FuncId, ErrId);}}while(0)
# define CANTRCV_CHECKDETTRUE_RETURN(Cond, Idx, FuncId, ErrId)  do{if((Cond) == CANTRCV_FALSE_B) \
           {(void)Det_ReportError(CANTRCV_MODULE_ID, Idx, FuncId, ErrId); return E_NOT_OK;}}while(0)
# define CANTRCV_CHECKDETTRUE_RETURN_NOVAL(Cond, Idx, FuncId, ErrId)  do{if((Cond) == CANTRCV_FALSE_B) \
           {(void)Det_ReportError(CANTRCV_MODULE_ID, Idx, FuncId, ErrId); return;}}while(0)
# define CANTRCV_CHECKDETTRUE_NORETURN(Cond, Idx, FuncId, ErrId)  do{if((Cond) == CANTRCV_FALSE_B) \
           {(void)Det_ReportError(CANTRCV_MODULE_ID, Idx, FuncId, ErrId);}}while(0)

#else
# define CANTRCV_CHECKDET_RETURN(Idx,FuncId,ErrId)              do{}while(0)
# define CANTRCV_CHECKDET_NORETURN(Idx,FuncId,ErrId)            do{}while(0)
# define CANTRCV_CHECKDETINIT_RETURN(state,Idx,FuncId)          do{}while(0)
# define CANTRCV_CHECKDETINIT_NORETURN(state,Idx,FuncId)        do{}while(0)
# define CANTRCV_CHECKDETTRCVIDX_RETURN(Idx,FuncId)             do{}while(0)
# define CANTRCV_CHECKDETTRCVIDX_NORETURN(Idx,FuncId)           do{}while(0)
# define CANTRCV_CHECKDETNULLPTR_RETURN(Idx,Ptr,FuncId)         do{}while(0)
# define CANTRCV_CHECKDETNULLPTR_NORETURN(Idx,Ptr,FuncId)       do{}while(0)
# define CANTRCV_CHECKDET_TRCVSTATE_RETURN(Idx,CurrentMode,AllowedMode1,AllowedMode2,FuncId,ErrId) do {}while(0)
# define CANTRCV_CHECKDETTRUE_RETURN(Cond, Idx, FuncId, ErrId)         do{}while(0)
# define CANTRCV_CHECKDETTRUE_RETURN_NOVAL(Cond, Idx, FuncId, ErrId)   do{}while(0)
# define CANTRCV_CHECKDETTRUE_NORETURN(Cond, Idx, FuncId, ErrId)       do{}while(0)
#endif

typedef enum 
{
    CANTrcv_Not_Used,
    CANTrcv_Used_HE9788,
    CANTrcv_Used_TPT1042,
    CANTrcv_Used_TPT1145
}CanTrcv_TrcvTyp;

#if CANTRCV_CFG_SPI_USED == STD_ON
# if CANTRCV_ECUM_USED == STD_OFF
// It is not possible to filter out WakeupSourceRef in CanTrcv_Spi_tst because struct is generated and generator
// does not know if integrator reconfigured ECUM availability. So EcuM_WakeupSourceType is defined in CanTrcv
typedef uint32      EcuM_WakeupSourceType;
# endif
typedef struct
{
    uint8                 No;         // 0-based Number specific for each Spi-Trcv-Type
    Spi_ChannelType       Channel;
    Spi_SequenceType      Sequence;
    EcuM_WakeupSourceType WakeupSourceRef;
    uint16                InitStartPos;
    uint16                ControlStartPos;
    uint16                ControlEndPos;
    uint8                 SpecReg1;     // Transceiver specific register value. For TPT1145 Bit CMC in normal mode
}CanTrcv_Spi_tst;
#endif

/* Data Structure for PN information */
typedef struct
{
    boolean BusErrFlag;         // CANTRCV_CFG_BUS_ERR_FLAG
    boolean PnEnabled;          // CanTrcvPnEnabled
    boolean PowerOnFlag;        // CanTrcvPowerOnFlag
}CanTrcv_PnTrcv_tst;

/* Data Structure for DEM information (only used for no-rba_Trcv) Same index as CanTrcv_PnTrcv_tst*/
#if (CANTRCV_CFG_DEM_ENABLE == STD_ON)
typedef struct
{
    Dem_EventIdType     EventId;    // DemEventId
}CanTrcv_Dem_tst;
#endif

typedef void (*CanTrcv_Init_t)(uint8 Transceiver);
typedef Std_ReturnType (*CanTrcv_SetOpMode_t)(uint8 Transceiver, CanTrcv_TrcvModeType OpMode);
typedef Std_ReturnType (*CanTrcv_GetOpMode_t)(uint8 Transceiver, CanTrcv_TrcvModeType* OpMode);
typedef Std_ReturnType (*CanTrcv_GetBusWuReason_t)(uint8 Transceiver, CanTrcv_TrcvWakeupReasonType* reason);
typedef Std_ReturnType (*CanTrcv_SetWakeupMode_t)(uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);
typedef Std_ReturnType (*CanTrcv_CheckWakeup_t)(uint8 Transceiver);

/* Structure to pointer of functions */
typedef struct
{
    CanTrcv_Init_t              Init;
    CanTrcv_SetOpMode_t         SetOpMode;
    CanTrcv_GetOpMode_t         GetOpMode;
    CanTrcv_GetBusWuReason_t    GetBusWuReason;
    CanTrcv_SetWakeupMode_t     SetWakeupMode;
    CanTrcv_CheckWakeup_t       CheckWakeup;
}CanTrcv_FctP_tst;


extern uint8                    CanTrcv_TrcvType[];
extern CanTrcv_FctP_tst         CanTrcv_FctP_st[];
#if CANTRCV_CFG_SPI_USED == STD_ON
extern const uint8              CanTrcv_Cfg_SpiPos_au8[];
extern const CanTrcv_Spi_tst    CanTrcv_SpiArray_ast[];
extern Spi_DataType       CanTrcv_CfgSpiChannel_ao[];
extern const CanTrcv_PnTrcv_tst CanTrcv_PnTrcv_st[];
#if (CANTRCV_CFG_DEM_ENABLE == STD_ON)
extern const CanTrcv_Dem_tst    CanTrcv_Dem_st[];
#endif
#endif

# define CANTRCV_TRCVTYPE           CanTrcv_TrcvType
# define CANTRCV_FCTP_ST            CanTrcv_FctP_st
# if CANTRCV_CFG_SPI_USED == STD_ON
# define CANTRCV_CFG_SPIPOS_AU8     CanTrcv_Cfg_SpiPos_au8
# define CANTRCV_SPIARRAY_AST       CanTrcv_SpiArray_ast
# define CANTRCV_CFGSPICHANNEL_AO   CanTrcv_CfgSpiChannel_ao
# define CANTRCV_PNTRCV_ST          CanTrcv_PnTrcv_st
# endif

extern uint8 Get_Tsk_CpuSleepOrOff(void);
extern uint8 CanTrcv_IsPoweredOff(void);
extern void CanTrcv_Init_TPT1145( uint8 Transceiver);
extern Std_ReturnType CanTrcv_SetOpMode_TPT1145(uint8 Transceiver, CanTrcv_TrcvModeType OpMode);
extern Std_ReturnType CanTrcv_GetOpMode_TPT1145(uint8 Transceiver,CanTrcv_TrcvModeType* OpMode );
extern Std_ReturnType CanTrcv_GetBusWuReason_TPT1145(uint8 Transceiver,CanTrcv_TrcvWakeupReasonType* reason);
extern Std_ReturnType CanTrcv_SetWakeupMode_TPT1145( uint8 Transceiver,CanTrcv_TrcvWakeupModeType TrcvWakeupMode);
extern Std_ReturnType CanTrcv_CheckWakeup_TPT1145(uint8 Transceiver);

#endif //CANTRCV_PRV_H

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
* Class_____:C
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

//TODO: relationship between cantrcv and canif notification
//#include "CanIf.h"
//#include "CanIf_Cbk.h"
#include "EvptCdd_CanTrcv_cfg.h"
#include "EvptCdd_TPT1145.h"
#include "EvptCdd_CanTrcv_prv.h"
#include "IoHwAbs_SPI.h"
#include "Cdd_Sa47301.h"
#include "Evpt_InterDataWatch_Prv.h"
/**
 ***************************************************************************************************
*
*
*               Global variables
*
*
****************************************************************************************************
*/
#define CANTRCV_TPT1145_SPI_STATE_INIT_MASK             0x0001u   // Bit-Mask in CanTrcv_Prv_TPT1145_SpiState
#define CANTRCV_TPT1145_SPI_STATE_INITDATA_MASK         0x0002u   // Bit-Maks in CanTrcv_Prv_TPT1145_SpiState shown possibly init data
#define CANTRCV_TPT1145_SPI_STATE_CLEAR_WUP_MASK        0x0004u   // Bit-Mask in CanTrcv_Prv_TPT1145_SpiState to clear wakeup reasons
#define CANTRCV_TPT1145_SPI_STATE_CLEAR_TIMEOUT_MASK    0x0008u   // Bit-Mask in CanTrcv_Prv_TPT1145_SpiState to clear timeout flag
#define CANTRCV_TPT1145_SPI_STATE_CLEAR_PNACTIVATE_MASK 0x0010u  // Bit-Mask in CanTrcv_Prv_TPT1145_SpiState to clear ActivationState
#define CANTRCV_TPT1145_SPI_STATE_SET_PNACTIVATE_MASK   0x0020u  // Bit-Mask in CanTrcv_Prv_TPT1145_SpiState to set  ActivationState
#define CANTRCV_TPT1145_SPI_STATE_MODE_INDICATION_MASK  0x0040u  // Bit-Mask in CanTrcv_Prv_TPT1145_SpiState to set  CanTrcvSetOpMode called
#define CANTRCV_TPT1145_SPI_STATE_CLEAR_TRCV_WUF_FLAG_INDICATION_MASK  0x0080u // Bit-Mask in CanTrcv_Prv_TPT1145_SpiState to set  CanIf_ClearTrcvWufFlagIndication called
#define CANTRCV_TPT1145_SPI_STATE_SETOPMODE             0x0100u  // function SetOpMode was called

/*tdh*/
uint16  CanTrcv_Prv_TPT1145_SpiTempStorageBuf_ao[CANTRCV_CFG_TPT1145_MAX][CANTRCV_CFG_TPT1145_SPI_CTRL_MAX];

uint8 CanTrcv_Prv_TPT1145_PowerDownCnter;
uint16  CanTrcv_Prv_TPT1145_SpiState[CANTRCV_CFG_TPT1145_MAX];
CanTrcv_TrcvModeType   CanTrcv_Prv_TPT1145_State[CANTRCV_CFG_TPT1145_MAX];
CanTrcv_TrcvModeType   CanTrcv_Prv_TPT1145_ReqState[CANTRCV_CFG_TPT1145_MAX];
// Buffer for SPI to receive init data from trcv. Possibility to check initialization
uint16  CanTrcv_Prv_TPT1145_SpiInitRxBuf_ao[CANTRCV_CFG_TPT1145_MAX][CANTRCV_CFG_TPT1145_SPI_INIT_MAX];
// Buffer for SPI to receive data from trcv
uint16  CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[CANTRCV_CFG_TPT1145_MAX][CANTRCV_CFG_TPT1145_SPI_CTRL_MAX];
// Buffer for SPI to transmit changed data to trcv
uint16  CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[CANTRCV_CFG_TPT1145_MAX][CANTRCV_CFG_TPT1145_SPI_CTRL_MAX];
uint8   CanTrcv_Prv_TPT1145_Wakeup_au8[CANTRCV_CFG_TPT1145_MAX];   /* 0=no wakeup; 1=wakeup detected */
boolean CanTrcv_WakeupModeState_ab[CANTRCV_CFG_NUMBER_OF_CANTRCV];

//TODO: CanTrcv_Prv_InitState_b shouldn't be part of the 1145 drvier, delete it later after integrate with AUTOSAR
#if (CANTRCV_DEV_ERROR_DETECT == STD_ON)
boolean CanTrcv_Prv_InitState_b;    /* 0:=FALSE not init, TRUE: init */
#endif

extern const uint8		Can_ActiveMode[CANTRCV_CFG_NUMBER_OF_CANTRCV];
extern const uint32		Can_ActiveId[CANTRCV_CFG_NUMBER_OF_CANTRCV];
extern const uint32		Can_ActiveId_Mask[CANTRCV_CFG_NUMBER_OF_CANTRCV];
/**
****************************************************************************************************
*
*
*              AUTOSAR CAN TRANSCEIVER DRIVER SPECIFIC FUNCTIONS
*              Function declarations
*
*
****************************************************************************************************
*/

/**
 ***************************************************************************************************
 * \moduledescription
 * Init Function for Can Transceiver function. One function for all transceivers.
 *
 * \param   -
 * \arg     -
 * \return  void
 * \see
 * \note    Initialization of global variables
 ***************************************************************************************************
 */
void CanTrcv_Init(void)
{
    uint8 TrcvIdx_qu8;

    #if (CANTRCV_DEV_ERROR_DETECT == STD_ON)
    /* MR12 RULE 10.3 VIOLATION: type boolean assigned to TRUE. This should always be ok */
    CanTrcv_Prv_InitState_b = TRUE;    /* TRUE: init */
    #endif

    // Loop over all CanTrcv
    for(TrcvIdx_qu8 = 0; TrcvIdx_qu8 < CANTRCV_CFG_NUMBER_OF_CANTRCV; TrcvIdx_qu8++ )
    {
        if(CANTRCV_FCTP_ST[TrcvIdx_qu8].Init != NULL_PTR)
        {
            CANTRCV_FCTP_ST[TrcvIdx_qu8].Init((uint8)TrcvIdx_qu8 );
        }
        #if (CANTRCV_CFG_WAKEUP_BY_NODE_USED == STD_ON)
        /* MR12 RULE 10.3 VIOLATION: type boolean assigned to FALSE. This should always be ok */
        CanTrcv_WakeupModeState_ab[TrcvIdx_qu8] = TRUE;
        #endif
    }
}

/**
 ***************************************************************************************************
 * \moduledescription
 * Init Function for Can Transceiver function. One function for all transceivers
 *
 * \param   uint8                       Transceiver
 * \arg     Transceiver                 identifies Transceiver to which the API has to be applied
 * \return  void
 * \see
 * \note    Initialization of global variables
 ***************************************************************************************************
 */
void CanTrcv_Init_TPT1145( uint8 Transceiver)
{
    uint8  TrcvNo_u8;
    uint8 Can_ActiveMode_Lo = 0; 
    uint16 SpiPos_u16;
    uint16 start_u16;
    uint16 size_u16;
    uint16 n;
    uint32 Can_ActiveId_LO = 0;
    uint32 Can_ActiveId_Mask_LO = 0;

    Spi_SequenceType sequence;
    const Spi_DataType     *src_o;

    // Check configured trcv type
    CANTRCV_CHECKDETTRUE_RETURN_NOVAL((CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145),
            Transceiver, CANTRCV_SID_INIT, CANTRCV_E_INVALID_TRANSCEIVER);
            
    // Get relevant configuration parameter
    SpiPos_u16  = CANTRCV_CFG_SPIPOS_AU8[Transceiver];
    TrcvNo_u8    = CANTRCV_SPIARRAY_AST[SpiPos_u16].No;

    CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] = CANTRCV_TPT1145_SPI_STATE_INIT_MASK + CANTRCV_TPT1145_SPI_STATE_INITDATA_MASK;
    start_u16   = CANTRCV_SPIARRAY_AST[SpiPos_u16].InitStartPos;
    size_u16    = CANTRCV_SPIARRAY_AST[SpiPos_u16].ControlStartPos - start_u16;
    sequence    = CANTRCV_SPIARRAY_AST[SpiPos_u16].Sequence;
    src_o       = &(CANTRCV_CFGSPICHANNEL_AO[start_u16]);

    Can_ActiveMode_Lo = Can_ActiveMode[Transceiver];
    Can_ActiveId_LO = Can_ActiveId[Transceiver];
    if(0 == Can_ActiveMode_Lo)
    {
        Can_ActiveId_Mask_LO = Can_ActiveId_Mask[Transceiver] & 0x7ff;
    }
    else if(1 == Can_ActiveMode_Lo)
    {
        Can_ActiveId_Mask_LO = Can_ActiveId_Mask[Transceiver] & 0x1fffffff;
    }else{/* NA */}

    // Write Initdata in SPI-Buffer
    if(0 == Transceiver)
    {
        /* write ActiveID,ActiveIDMask in Init_Spi_buff */
        if(0 == Can_ActiveMode_Lo)
        {
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG29] |= (uint8)((Can_ActiveId_LO & 0x3f) << 2);	//B7:B2 -> bits ID5 to ID0 of the standard frame format
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2A] |= (uint8)((Can_ActiveId_LO >> 6) & 0x1f);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2D] |= (uint8)((Can_ActiveId_Mask_LO & 0x3f) << 2);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2E] |= (uint8)((Can_ActiveId_Mask_LO >> 6) & 0x1f);
        }
        else if(1 == Can_ActiveMode_Lo)
        {
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG27] |= (uint8)(Can_ActiveId_LO & 0xff);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG28] |= (uint8)((Can_ActiveId_LO & 0xff00) >> 8);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG29] |= (uint8)((Can_ActiveId_LO & 0xff0000) >> 16);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2A] |= (uint8)((Can_ActiveId_LO & 0x1f000000) >> 24);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2B] |= (uint8)(Can_ActiveId_Mask_LO & 0xff);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2C] |= (uint8)((Can_ActiveId_Mask_LO & 0xff00) >> 8);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2D] |= (uint8)((Can_ActiveId_Mask_LO & 0xff0000) >> 16);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2E] |= (uint8)((Can_ActiveId_Mask_LO & 0x1f000000) >> 24);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2F] |= (0x0080);
        }
        else{/* NA */}
    }else if(1 == Transceiver)
    {
        /* write ActiveID,ActiveIDMask in Init_Spi_buff */
        if(0 == Can_ActiveMode_Lo)
        {
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG29 +start_u16] |= (uint8)((Can_ActiveId_LO & 0x3f) << 2);	//B7:B2 -> bits ID5 to ID0 of the standard frame format
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2A +start_u16] |= (uint8)((Can_ActiveId_LO >> 6) & 0x1f);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2D +start_u16] |= (uint8)((Can_ActiveId_Mask_LO & 0x3f) << 2);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2E +start_u16] |= (uint8)((Can_ActiveId_Mask_LO >> 6) & 0x1f);
        }
        else if(1 == Can_ActiveMode_Lo)
        {
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG27 +start_u16] |= (uint8)(Can_ActiveId_LO & 0xff);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG28 +start_u16] |= (uint8)((Can_ActiveId_LO & 0xff00) >> 8);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG29 +start_u16] |= (uint8)((Can_ActiveId_LO & 0xff0000) >> 16);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2A +start_u16] |= (uint8)((Can_ActiveId_LO & 0x1f000000) >> 24);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2B +start_u16] |= (uint8)(Can_ActiveId_Mask_LO & 0xff);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2C +start_u16] |= (uint8)((Can_ActiveId_Mask_LO & 0xff00) >> 8);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2D +start_u16] |= (uint8)((Can_ActiveId_Mask_LO & 0xff0000) >> 16);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2E +start_u16] |= (uint8)((Can_ActiveId_Mask_LO & 0x1f000000) >> 24);
            CANTRCV_CFGSPICHANNEL_AO[CANTRCV_CFG_TPT1145_INIT_SPI_REG2F +start_u16] |= (0x0080);
        }
        else{/* NA */}
    }else{/* NA */}

    IoHwAbs_Spi_SetupEB(CANTRCV_SPIARRAY_AST[SpiPos_u16].Channel,// Channel: get out of SPI config
                		&CANTRCV_CFGSPICHANNEL_AO[start_u16],               // points to Trcv generated data in ROM for initdata
						&CanTrcv_Prv_TPT1145_SpiInitRxBuf_ao[TrcvNo_u8][0], // points to Trcv reserved array to read result of initdata. Not used in curr impl
						size_u16);

   IoHwAbs_Spi_SyncTransmit(sequence);

    // Prepare Control Table
    // Copy Rom-Table into Ram (values are modified and read out in main trcv-function)
    // Initmode is set by generated Register values. No extra setmode is required.
    start_u16   = CANTRCV_SPIARRAY_AST[SpiPos_u16].ControlStartPos;
    size_u16    = CANTRCV_SPIARRAY_AST[SpiPos_u16].ControlEndPos - start_u16;
    src_o       = &(CANTRCV_CFGSPICHANNEL_AO[start_u16]);
    for(n = 0; n < size_u16; n++)
    {
        CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][n] = src_o[n];
    }
}

/**
 ***************************************************************************************************
 * \moduledescription
 * This function sets the transceiver mode
 *
 * \param   uint8                       Transceiver
 * \arg     Transceiver                 identifies Transceiver to which the API has to be applied
 * \param   CanTrcv_TrcvModeType        CanTrcv_TrcvModeType
 * \arg     OpMode                      Selects the state the transceiver will transit to
 * \return     E_OK:                    The state request was successful
 *             E_NOT_OK:                The state request could not be executed, because of transceiver error
 *                                      or wrong parameters
 * \see
 * \note
 ***************************************************************************************************
 */
Std_ReturnType CanTrcv_SetOpMode(uint8 Transceiver, CanTrcv_TrcvModeType OpMode)
{
    Std_ReturnType RetVal_o = E_NOT_OK;

    // Check all input parameters
    /* MR12 RULE 10.3 VIOLATION: type boolean compared with FALSE. This should always be ok */
    CANTRCV_CHECKDETINIT_RETURN((CanTrcv_Prv_InitState_b != FALSE), Transceiver, CANTRCV_SID_SETOPMODE);
    CANTRCV_CHECKDETTRCVIDX_RETURN(Transceiver, CANTRCV_SID_SETOPMODE);
    CANTRCV_CHECKDETTRUE_RETURN((OpMode <= CANTRCV_TRCVMODE_STANDBY),
                                  Transceiver, CANTRCV_SID_SETOPMODE, CANTRCV_E_PARAM_TRCV_OPMODE);

    // Call trcv-specific SetOp fuction according config
    if(CANTRCV_FCTP_ST[Transceiver].SetOpMode != NULL_PTR)
    {
        RetVal_o = CANTRCV_FCTP_ST[Transceiver].SetOpMode(Transceiver, OpMode );
    }

    return RetVal_o;
}

/**
 ***************************************************************************************************
 * \moduledescription
 * This function sets the transceiver mode
 *
 * \param   uint8                       Transceiver
 * \arg     Transceiver                 identifies Transceiver to which the API has to be applied
 * \param   CanTrcv_TrcvModeType        CanTrcv_TrcvModeType
 * \arg     OpMode                      Selects the state the transceiver will transit to
 * \return     E_OK:                    The state request was successful
 *             E_NOT_OK:                The state request could not be executed, because of transceiver error
 *                                      or wrong parameters
 * \see
 * \note
 ***************************************************************************************************
 */
Std_ReturnType CanTrcv_SetOpMode_TPT1145(uint8 Transceiver, CanTrcv_TrcvModeType OpMode)
{
    Std_ReturnType RetVal_o = E_OK;
    uint16 SpiPos_u16;
    uint8  TrcvNo_u8;

    // Check transceiver type
    CANTRCV_CHECKDETTRUE_RETURN((CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145),
            Transceiver, CANTRCV_SID_SETOPMODE, CANTRCV_E_INVALID_TRANSCEIVER);

    // Get relevant configuration parameter
    SpiPos_u16  = CANTRCV_CFG_SPIPOS_AU8[Transceiver];
    TrcvNo_u8   = CANTRCV_SPIARRAY_AST[SpiPos_u16].No;
    CanTrcv_Prv_TPT1145_ReqState[TrcvNo_u8] = OpMode;

    // Set global flag to write mode in main function
    CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] |= CANTRCV_TPT1145_SPI_STATE_SETOPMODE;

    #  if (CANTRCV_CFG_RB_INDICATION_BEHAVIOUR == CANTRCV_INDICATION_IMMEDIATELY)
        CanIf_TrcvModeIndication(Transceiver, OpMode);
    #  else
        // Set global flag. Processed in main function
        CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] |= CANTRCV_TPT1145_SPI_STATE_MODE_INDICATION_MASK;
    #  endif

    return RetVal_o;
}

/**
 ***************************************************************************************************
 * \moduledescription
 * This function returns the actual state of the transceiver.
 *
 * \param   uint8                   Transceiver
 * \arg     Transceiver             identifies Transceiver to which the API has to be applied
 * \param   CanTrcv_TrcvModeType*   CanTrcv_TrcvModeType
 * \arg     OpMode                  Current state of the transceiver
 * \return     E_OK:        The state can be evaluated
 *             E_NOT_OK:    The state could not be evaluated, either because of transceiver error
 *                          or wrong parameters
 * \see
 * \note
 ***************************************************************************************************
 */
Std_ReturnType CanTrcv_GetOpMode(uint8 Transceiver,CanTrcv_TrcvModeType* OpMode )
{
    Std_ReturnType RetVal_o = E_NOT_OK;

    // Check all input parameters
    /* MR12 RULE 10.3 VIOLATION: type boolean compared with FALSE. This should always be ok */
    CANTRCV_CHECKDETINIT_RETURN((CanTrcv_Prv_InitState_b  != FALSE), Transceiver, CANTRCV_SID_GETOPMODE);
    CANTRCV_CHECKDETTRCVIDX_RETURN(Transceiver,CANTRCV_SID_GETOPMODE);
    CANTRCV_CHECKDETNULLPTR_RETURN(Transceiver,OpMode,CANTRCV_SID_GETOPMODE);

    // Check if configparameter configured
    if(CANTRCV_FCTP_ST[Transceiver].GetOpMode != NULL_PTR)
    {
        // Call trcv-specific GetOpMode fuction according config
        RetVal_o = CANTRCV_FCTP_ST[Transceiver].GetOpMode(Transceiver, OpMode );
    }
    return RetVal_o;
}

/**
 ***************************************************************************************************
 * \moduledescription
 * This function returns the actual state of the transceiver.
 *
 * \param   uint8                   Transceiver
 * \arg     Transceiver             identifies Transceiver to which the API has to be applied
 * \param   CanTrcv_TrcvModeType*   CanTrcv_TrcvModeType
 * \arg     OpMode                  Current state of the transceiver
 * \return     E_OK:        The state can be evaluated
 *             E_NOT_OK:    The state could not be evaluated, either because of transceiver error
 *                          or wrong parameters
 * \see
 * \note
 ***************************************************************************************************
 */
Std_ReturnType CanTrcv_GetOpMode_TPT1145(uint8 Transceiver,CanTrcv_TrcvModeType* OpMode )
{
    Std_ReturnType RetVal_o = E_OK;

    uint8  TrcvNo_u8;
    uint16 SpiPos_u16;
    Spi_DataType RegVal01_o;

    // Check configured trcv type
    CANTRCV_CHECKDETTRUE_RETURN((CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145),
            Transceiver, CANTRCV_SID_GETOPMODE, CANTRCV_E_INVALID_TRANSCEIVER);

    // Get relevant configuration parameter
    SpiPos_u16  = CANTRCV_CFG_SPIPOS_AU8[Transceiver];
    TrcvNo_u8   = CANTRCV_SPIARRAY_AST[SpiPos_u16].No;

    // Check if data are valid
    if((CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] & CANTRCV_TPT1145_SPI_STATE_INITDATA_MASK) == 0u)
    {
        // Calculated state out of register values
        RegVal01_o  = CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG01] & CANTRCV_CFG_TPT1145_SPI_MC_AND_MASK;
        if( RegVal01_o ==  CANTRCV_CFG_TPT1145_SPI_MC_NM_OR_MASK)
        {
            *OpMode = CANTRCV_TRCVMODE_NORMAL;
        }
        else if ( RegVal01_o ==  CANTRCV_CFG_TPT1145_SPI_MC_SBM_OR_MASK)
        {
            *OpMode = CANTRCV_TRCVMODE_STANDBY;
        }
        else if ( RegVal01_o ==  CANTRCV_CFG_TPT1145_SPI_MC_SM_OR_MASK)
        {
            *OpMode = CANTRCV_TRCVMODE_SLEEP;
        }
        else
        {
            /* MR12 RULE 10.3 VIOLATION: type boolean compared with FALSE. This should always be ok */
            CANTRCV_CHECKDETINIT_RETURN((CanTrcv_Prv_InitState_b  != FALSE), Transceiver, CANTRCV_E_PARAM_TRCV_OPMODE);
        }
    }
    else
    {
        RetVal_o = E_NOT_OK;
    }
    return RetVal_o;
}

Std_ReturnType EvptCdd_TPT1145_GetPowerUpReason(uint8 Transceiver,CanTrcv_TrcvWakeupReasonType* reason)
{
    Std_ReturnType RetVal_o = E_NOT_OK;
    //TODO: implement 1145 wake up reason analyze, based on CanTrcv_Prv_TCAN1145_SpiInitRxBuf_ao[Transceiver][1] and CanTrcv_Prv_TCAN1145_SpiInitRxBuf_ao[Transceiver][24]
    return RetVal_o;
}
/**
 ***************************************************************************************************
 * \moduledescription
 * This function returns the wakeup reason.
 *
 * \param   uint8                       Transceiver
 * \arg     Transceiver                 identifies Transceiver to which the API has to be applied
 * \param   CanTrcv_TrcvWakeupReasonType*  reason
 * \arg     reason                      Evaluated wakeup reason
 * \return     E_OK:                    The wakeup reason can be evaluated
 *             E_NOT_OK:                The wakeup reason could not be evaluated, either because of transceiver error
 *                                      or wrong parameters
 * \see
 * \note
 ***************************************************************************************************
 */
Std_ReturnType CanTrcv_GetBusWuReason(uint8 Transceiver,CanTrcv_TrcvWakeupReasonType* reason )
{
    Std_ReturnType RetVal_o = E_NOT_OK;

    // Check all input parameters
    /* MR12 RULE 10.3 VIOLATION: type boolean compared with FALSE. This should always be ok */
    CANTRCV_CHECKDETINIT_RETURN((CanTrcv_Prv_InitState_b != FALSE), Transceiver, CANTRCV_SID_GETBUSWUREASON);
    CANTRCV_CHECKDETTRCVIDX_RETURN(Transceiver,CANTRCV_SID_GETBUSWUREASON);
    CANTRCV_CHECKDETNULLPTR_RETURN(Transceiver,reason,CANTRCV_SID_GETBUSWUREASON);

    // Check if configparameter configured
    if(CANTRCV_FCTP_ST[Transceiver].GetBusWuReason != NULL_PTR)
    {
        //Call trcv-specific GetOpMode fuction according config
        RetVal_o = CANTRCV_FCTP_ST[Transceiver].GetBusWuReason(Transceiver, reason);
    }
    return RetVal_o;
}

/**
 ***************************************************************************************************
 * \moduledescription
 * This function returns the wakeup reason.
 *
 * \param   uint8                       Transceiver
 * \arg     Transceiver                 identifies Transceiver to which the API has to be applied
 * \param   CanTrcv_TrcvWakeupReasonType*  reason
 * \arg     reason                      Evaluated wakeup reason
 * \return     E_OK:                    The wakeup reason can be evaluated
 *             E_NOT_OK:                The wakeup reason could not be evaluated, either because of transceiver error
 *                                      or wrong parameters
 * \see
 * \note
 ***************************************************************************************************
 */
Std_ReturnType CanTrcv_GetBusWuReason_TPT1145(uint8 Transceiver,CanTrcv_TrcvWakeupReasonType* reason)
{
    Std_ReturnType RetVal_o = E_OK;

    uint16 SpiPos_u16;
    uint8  TrcvNo_u8;
    uint16 mask_u16 = 0;

    // Check configured trcv type
    CANTRCV_CHECKDETTRUE_RETURN((CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145),
            Transceiver, CANTRCV_SID_GETBUSWUREASON, CANTRCV_E_INVALID_TRANSCEIVER);

    // Get relevant configuration data
    SpiPos_u16  = CANTRCV_CFG_SPIPOS_AU8[Transceiver];
    TrcvNo_u8   = CANTRCV_SPIARRAY_AST[SpiPos_u16].No;

    if((CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] & CANTRCV_TPT1145_SPI_STATE_INITDATA_MASK) == 0u)
    {
        // Calculate Wakeupreason out of register values (RAM mirror)
        *reason = CANTRCV_WU_NOT_SUPPORTED;
        if ((CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG63] & CANTRCV_CFG_TPT1145_SPI_CW_MASK) != 0u)  // Reg 0x63: CW in Transceiver event status
        {
            mask_u16 |= 1u;
        }
        if ((CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG4B] & CANTRCV_CFG_TPT1145_SPI_WPVS_MASK) != 0u)  // Reg 0x4B: WAKE pin status
        {
            mask_u16 |= 2u;
        }
        if ((CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG61] & CANTRCV_CFG_TPT1145_SPI_PO_MASK) != 0u)  // Reg 0x61: Power on status
        {
            if((CANTRCV_PNTRCV_ST[TrcvNo_u8].PnEnabled == FALSE) || (CANTRCV_PNTRCV_ST[TrcvNo_u8].PowerOnFlag == TRUE))
            {
                mask_u16 |= 4u;
            }
        }
        switch (mask_u16)
        {
            case 1u:
                *reason = CANTRCV_WU_BY_BUS;
            break;
            case 2u:
                *reason = CANTRCV_WU_BY_PIN;
            break;
            case 3u:
                *reason = CANTRCV_CFG_WU_BY_BUS_AND_PIN;
            break;
            case 4u:
                *reason = CANTRCV_WU_POWER_ON;
            break;
            case 5u:
                *reason = CANTRCV_CFG_WU_BY_BUS_AND_POWER_ON;
            break;
            case 6u:
                *reason = CANTRCV_CFG_WU_BY_PIN_AND_POWER_ON;
            break;
            case 7u:
                *reason = CANTRCV_CFG_WU_BY_BUS_AND_PIN_AND_POWER_ON;
            break;
            default:    // 0 = CANTRCV_WU_NOT_SUPPORTED
                *reason = CANTRCV_WU_NOT_SUPPORTED;
            break;
        }
    }
    else
    {
        RetVal_o = E_NOT_OK;
    }
    return RetVal_o;
}

/**
 ***************************************************************************************************
 * \moduledescription
 * Enables, disables or clears wake-up events of the Transceiver according to TrcvWakeupMode..
 *
 * \param   uint8           Transceiver
 * \arg     Transceiver     identifies Transceiver to which the API has to be applied
 * \param   CanTrcv_TrcvWakeupModeType  WakeupMode
 * \arg     TrcvWakeupMode            requested wakeup mode
 * \return  E_OK:           The wakeup reason can be changed
 *          E_NOT_OK:       Error orrcured
 * \see
 * \note
 ***************************************************************************************************
 */
Std_ReturnType CanTrcv_SetWakeupMode( uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode)
{
    Std_ReturnType RetVal_o = E_NOT_OK;

    // Check all input parameters
    /* MR12 RULE 10.3 VIOLATION: type boolean compared with FALSE. This should always be ok */
    CANTRCV_CHECKDETINIT_RETURN((CanTrcv_Prv_InitState_b != FALSE), Transceiver, CANTRCV_SID_SETWAKEUPMODE);
    CANTRCV_CHECKDETTRCVIDX_RETURN(Transceiver,CANTRCV_SID_SETWAKEUPMODE);
    CANTRCV_CHECKDETTRUE_RETURN((TrcvWakeupMode <= CANTRCV_WUMODE_CLEAR),
                                  Transceiver, CANTRCV_SID_SETWAKEUPMODE, CANTRCV_E_PARAM_TRCV_WAKEUP_MODE);

    // Check if configparameter configured
#if (CANTRCV_CFG_WAKEUP_BY_NODE_USED == STD_ON)
    if(CANTRCV_FCTP_ST[Transceiver].SetWakeupMode != NULL_PTR)
    {
        // Call trcv-specific SetWakeupMode fuction according config
        RetVal_o = CANTRCV_FCTP_ST[Transceiver].SetWakeupMode(Transceiver, TrcvWakeupMode);
    }
#else
    (void)Transceiver;      // CANTRCV_PRV_PARAM_UNUSED
    (void)TrcvWakeupMode;   // CANTRCV_PRV_PARAM_UNUSED
#endif
    return RetVal_o;
}

/**
 ***************************************************************************************************
 * \moduledescription
 * Enables, disables or clears wake-up events of the Transceiver according to TrcvWakeupMode..
 *
 * \param   uint8           Transceiver
 * \arg     Transceiver     identifies Transceiver to which the API has to be applied
 * \param   CanTrcv_TrcvWakeupModeType  WakeupMode
 * \arg     TrcvWakeupMode            requested wakeup mode
 * \return  E_OK:           The wakeup reason can be changed
 *          E_NOT_OK:       Error orrcured
 * \see
 * \note
 ***************************************************************************************************
 */
Std_ReturnType CanTrcv_SetWakeupMode_TPT1145( uint8 Transceiver,CanTrcv_TrcvWakeupModeType TrcvWakeupMode)
{
    // Check configured trcv type
    CANTRCV_CHECKDETTRUE_RETURN((CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145),
            Transceiver, CANTRCV_SID_SETWAKEUPMODE, CANTRCV_E_INVALID_TRANSCEIVER);

    switch(TrcvWakeupMode)
    {
        case CANTRCV_WUMODE_CLEAR:
        {   /* in case of clear wakeup the mode is not changed */
            // get relevant config data
            uint16 SpiPos_u16;
            uint8  TrcvNo_u8;

            SpiPos_u16  = CANTRCV_CFG_SPIPOS_AU8[Transceiver];
            TrcvNo_u8   = CANTRCV_SPIARRAY_AST[SpiPos_u16].No;

            // Set relevant global variables
            CanTrcv_Prv_TPT1145_Wakeup_au8[TrcvNo_u8] = 0; /* 0: no wakeup; 1=wakeup detected */
            // CANTRCV_CFG_CLEAR_WUPREASON_IN_SETWAKEUPMODE is not used for TPT1145 as the reason is always
            // directly read out of registers
            CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] |= CANTRCV_TPT1145_SPI_STATE_CLEAR_WUP_MASK;
        }
        break;
        case CANTRCV_WUMODE_DISABLE:
        {
            // Set relevant global variables
            /* MR12 RULE 10.3 VIOLATION: type boolean assigned with FALSE. This should always be ok */
            CanTrcv_WakeupModeState_ab[Transceiver] = FALSE;
        }
        break;
        default:   // CANTRCV_WUMODE_ENABLE:
        {
            // Set relevant global variables
            /* Mode is change as requested (TRCV_WU_ENABLE)  */
            /* MR12 RULE 10.3 VIOLATION: type boolean assigned with TRUE. This should always be ok */
            CanTrcv_WakeupModeState_ab[Transceiver] = TRUE;
        }
        break;
    }
    return E_OK;
}

/**
 ***************************************************************************************************
 * \moduledescription
 * Checks HW for current or previous wakeup and returns value
 * This function notifies the calling function if a wakeup is detected in the Transceiver by returning E_OK else returns E_NOT_OK
 *
 * \param   uint8                       Transceiver
 * \arg     Transceiver                 identifies Transceiver to which the API has to be applied
 * \return     E_OK:                    The wakeup occured
 *             E_NOT_OK:                The wakeup not occured
 * \see
 * \note       Service is called by underlying CANIF in case a wake up interrupt is detected.
 ***************************************************************************************************
 */
Std_ReturnType CanTrcv_CheckWakeup(uint8 Transceiver)
{
    #if (CANTRCV_CFG_WAKEUP_BY_NODE_USED == STD_ON)
    Std_ReturnType RetVal_o = E_NOT_OK;

    // Check all input parameters
    /* MR12 RULE 10.3 VIOLATION: type boolean compared with FALSE. This should always be ok */
    CANTRCV_CHECKDETINIT_RETURN((CanTrcv_Prv_InitState_b != FALSE), Transceiver, CANTRCV_SID_CHECKWAKEUP);
    CANTRCV_CHECKDETTRCVIDX_RETURN(Transceiver,CANTRCV_SID_CHECKWAKEUP);

    // Check if configparameter configured
    if(CANTRCV_FCTP_ST[Transceiver].CheckWakeup != NULL_PTR)
    {
        // Call trcv-specific CheckWakeup fuction according config
        RetVal_o = CANTRCV_FCTP_ST[Transceiver].CheckWakeup(Transceiver );
    }
    return RetVal_o;
    #else
    (void) (Transceiver);   // CANTRCV_PRV_PARAM_UNUSED
    return E_NOT_OK;        // if not configured, then "no wakeup" should be returned
    #endif
}

/**
 ***************************************************************************************************
 * \moduledescription
 * Checks HW for current or previous wakeup and returns value
 * This function notifies the calling function if a wakeup is detected in the Transceiver by returning E_OK else returns E_NOT_OK
 *
 * \param   uint8                       Transceiver
 * \arg     Transceiver                 identifies Transceiver to which the API has to be applied
 * \return     E_OK:                    The wakeup occured
 *             E_NOT_OK:                The wakeup not occured
 * \see
 * \note       Service is called by underlying CANIF in case a wake up interrupt is detected.
 *              This function reads out SPI-status bits. Rx-Pin is only low as long event is pending
 ***************************************************************************************************
 */
Std_ReturnType CanTrcv_CheckWakeup_TPT1145(uint8 Transceiver)
{
    Std_ReturnType RetVal_o = E_NOT_OK;
    uint16 SpiPos_u16;
    uint8  TrcvNo_u8;

    // Check configured trcv type
    CANTRCV_CHECKDETTRUE_RETURN((CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145),
            Transceiver, CANTRCV_SID_CHECKWAKEUP, CANTRCV_E_INVALID_TRANSCEIVER);

    // Check if mode allowes wakeup-check
    /* MR12 RULE 10.3 VIOLATION: type boolean compared with FALSE. This should always be ok */
    if ( FALSE != CanTrcv_WakeupModeState_ab[Transceiver])
    {

        // Get relevant configuration parameter
        SpiPos_u16  = CANTRCV_CFG_SPIPOS_AU8[Transceiver];
        TrcvNo_u8   = CANTRCV_SPIARRAY_AST[SpiPos_u16].No;

        // Get wakeupinfo out of global variable
        if( CanTrcv_Prv_TPT1145_Wakeup_au8[TrcvNo_u8] == 1)   /* 0=no wakeup; 1=wakeup detected */
        {
            // set return value out of result
            RetVal_o = E_OK;
        }
    }
    return RetVal_o;
}

/**
 ***************************************************************************************************
 * \moduledescription
 * Requests to check the status of the wakeup flag from the transceiver hardware.
 *
 * \param   uint8                       Transceiver
 * \arg     Transceiver                 identifies Transceiver to which the API has to be applied
 * \return     E_OK:                    Check was allowed
 *             E_NOT_OK:                Error in function
 * \see
 * \note    This function is not used as the wakeupflag is read cyclicly in main function
 ***************************************************************************************************
 */
Std_ReturnType CanTrcv_CheckWakeFlag(uint8 Transceiver)
{
    Std_ReturnType RetVal_o = E_NOT_OK;
#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
    uint16 SpiPos_u16;
    uint8  TrcvNo_u8;

    // Check all input parameters
    CANTRCV_CHECKDETTRCVIDX_RETURN(Transceiver, CANTRCV_SID_CHECKWAKEFLAG);
    CANTRCV_CHECKDETTRUE_RETURN(((CANTRCV_TRCVTYPE[Transceiver] == CANTRCV_TRCVTYPE_TPT1145)),
                                  Transceiver, CANTRCV_SID_CHECKWAKEFLAG, CANTRCV_E_INVALID_TRANSCEIVER);

    /* MR12 RULE 10.3 VIOLATION: type boolean compared with FALSE. This should always be ok */
# if (CANTRCV_ECUM_USED == STD_ON)
    // Check if mode allowes wakeup-check
    if (FALSE != CanTrcv_WakeupModeState_ab[Transceiver])
    {
        // Get relevant configuration parameter
        SpiPos_u16  = CANTRCV_CFG_SPIPOS_AU8[Transceiver];
        TrcvNo_u8   = CANTRCV_SPIARRAY_AST[SpiPos_u16].No;

        // Check if wakeup was stored in global variable
        if(CANTRCV_TRCVTYPE[Transceiver] == CANTRCV_TRCVTYPE_TPT1145)
        {
            if(0 != CanTrcv_Prv_TPT1145_Wakeup_au8[TrcvNo_u8])
            {
                // Check if Wakeupsource is configured
                if(CANTRCV_SPIARRAY_AST[SpiPos_u16].WakeupSourceRef != 0u)
                {
                    //TODO: implement EcuM_SetWakeupEvent
                    //EcuM_SetWakeupEvent(CANTRCV_SPIARRAY_AST[SpiPos_u16].WakeupSourceRef );
                }
            }
        }
    }
# else
    (void)SpiPos_u16;   // CANTRCV_PRV_PARAM_UNUSED
    (void)TrcvNo_u8;    // CANTRCV_PRV_PARAM_UNUSED
# endif
    // Always give indication as AR4.x Req is wrong. See sequence diagramm in AR4.0 spec
    // As the bits are cyclic read out in main function, this callback can be given sync.
    //TODO:implement CanIf_CheckTrcvWakeFlagIndication
    //CanIf_CheckTrcvWakeFlagIndication(Transceiver);
    // Set return value to E_OK
    RetVal_o = E_OK;
#else
    (void) (Transceiver);   // CANTRCV_PRV_PARAM_UNUSED
#endif
    //return return value
    return RetVal_o;
}

/**
 ***************************************************************************************************
 * \moduledescription
 * Requests to check the status of the wakeup flag from the transceiver hardware.
 *
 * \param   uint8                       Transceiver
 * \arg     Transceiver                 identifies Transceiver to which the API has to be applied
 * \return     E_OK:                    Check was allowed
 *             E_NOT_OK:                Error in function
 * \see
 * \note    This function is not used as the wakeupflag is read cyclicly in main function
 ***************************************************************************************************
 */
Std_ReturnType CanTrcv_CheckWakeFlag_TPT1145(uint8 Transceiver)
{
    Std_ReturnType RetVal_o = E_NOT_OK;
    #if (CANTRCV_HW_PN_SUPPORT == STD_ON)
    uint16 SpiPos_u16;
    uint8  TrcvNo_u8;

    // Check all input parameters
    CANTRCV_CHECKDETTRCVIDX_RETURN(Transceiver, CANTRCV_SID_CHECKWAKEFLAG);
    CANTRCV_CHECKDETTRUE_RETURN(((CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145)),
                                  Transceiver, CANTRCV_SID_CHECKWAKEFLAG, CANTRCV_E_INVALID_TRANSCEIVER);

        /* MR12 RULE 10.3 VIOLATION: type boolean compared with FALSE. This should always be ok */
        # if (CANTRCV_ECUM_USED == STD_ON)
        // Check if mode allowes wakeup-check
        if (FALSE != CanTrcv_WakeupModeState_ab[Transceiver])
        {
            // Get relevant configuration parameter
            SpiPos_u16  = CANTRCV_CFG_SPIPOS_AU8[Transceiver];
            TrcvNo_u8   = CANTRCV_SPIARRAY_AST[SpiPos_u16].No;

            // Check if wakeup was stored in global variable
            if(CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145)
            {
                if(0 != CanTrcv_Prv_TPT1145_Wakeup_au8[TrcvNo_u8])
                {
                    // Check if Wakeupsource is configured
                    if(CANTRCV_SPIARRAY_AST[SpiPos_u16].WakeupSourceRef != 0u)
                    {
                        EcuM_SetWakeupEvent(CANTRCV_SPIARRAY_AST[SpiPos_u16].WakeupSourceRef );
                    }
                }
            }
        }
        # else
        (void)SpiPos_u16;   // CANTRCV_PRV_PARAM_UNUSED
        (void)TrcvNo_u8;    // CANTRCV_PRV_PARAM_UNUSED
        # endif
    // Always give indication as AR4.x Req is wrong. See sequence diagramm in AR4.0 spec
    // As the bits are cyclic read out in main function, this callback can be given sync.
    //TODO: implement CanIf_CheckTrcvWakeFlagIndication when in AUTOSAR 
    //CanIf_CheckTrcvWakeFlagIndication(Transceiver);
    // Set return value to E_OK
    RetVal_o = E_OK;
    #else
    (void) (Transceiver);   // CANTRCV_PRV_PARAM_UNUSED
    #endif
    //return return value
    return RetVal_o;
}
/**
 ***************************************************************************************************
 * \moduledescription
 * Reads the status of the timeout flag from the transceiver hardware.
 *
 * \param   uint8                       Transceiver
 * \arg     Transceiver                 identifies Transceiver to which the API has to be applied
 * \return  E_OK: Will be returned, if status of the timeout flag is success-fully read.
 *          E_NOT_OK: Will be returned, if status of the timeout flag could not be read.
 * \see
 * \note  This API shall exist only if CanTrcvHwPnSupport = TRUE..
 ***************************************************************************************************
 */
#if CANTRCV_HW_PN_SUPPORT == STD_ON
Std_ReturnType CanTrcv_ReadTrcvTimeoutFlag( uint8 Transceiver, CanTrcv_TrcvFlagStateType* FlagState )
{
    Std_ReturnType RetVal_o = E_NOT_OK;
    uint16 SpiPos_u16;
    uint8  TrcvNo_u8;

    // Check all input parameters
    CANTRCV_CHECKDETTRUE_RETURN((Transceiver < CANTRCV_CFG_NUMBER_OF_CANTRCV),
                                  Transceiver, CANTRCV_SID_READTRCVTIMEOUTFLAG, CANTRCV_E_INVALID_TRANSCEIVER);
    CANTRCV_CHECKDETTRUE_RETURN((CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145),
                                  Transceiver, CANTRCV_SID_READTRCVTIMEOUTFLAG, CANTRCV_E_INVALID_TRANSCEIVER);
    CANTRCV_CHECKDETTRUE_RETURN((FlagState != NULL_PTR),
                                  Transceiver, CANTRCV_SID_READTRCVTIMEOUTFLAG, CANTRCV_E_PARAM_POINTER);

    // Check for correct Trcv-type
    if (CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145)
    {
        // Get relevant configuration parameter
        // Bit CFS in Reg 22h  Transceiver status register
        SpiPos_u16  = CANTRCV_CFG_SPIPOS_AU8[Transceiver];
        TrcvNo_u8   = CANTRCV_SPIARRAY_AST[SpiPos_u16].No;

        // Check for valid register data
        if((CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] & CANTRCV_TPT1145_SPI_STATE_INITDATA_MASK) == 0u)
        {
            // Calculate  parameter FlagState
            *FlagState = CANTRCV_FLAG_CLEARED;
            if((CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG63] & CANTRCV_CFG_TPT1145_SPI_CBS_MASK) != 0u)
            {
                *FlagState = CANTRCV_FLAG_SET;
            }

            RetVal_o = E_OK;
        }
    }
    return RetVal_o;
}
#endif
/**
 ***************************************************************************************************
 * \moduledescription
 * Clears the status of the timeout flag in the transceiver hardware.
 *
 * \param   uint8                       Transceiver
 * \arg     Transceiver                 identifies Transceiver to which the API has to be applied
 * \return     E_OK:                    Check was allowed
 *             E_NOT_OK:                Error in function
 * \see
 * \note  This API shall exist only if CanTrcvHwPnSupport = TRUE..
 *!Reg 63  CBS R/W 0 CAN bus is active
 *                 1 no activity on CAN bus for tto(silence)
 *
 * Reg 22 CBSS R   0 CAN bus active (communication detected on bus)
 *                 1 CAN bus inactive (for longer than tto(silence))
 * Reg 23 CBSE R/W 0 CAN bus silence detection disabled
 * Reg 22  CFS R   0 no TXD dominant timeout event detected
 ***************************************************************************************************
 */
#if CANTRCV_HW_PN_SUPPORT == STD_ON
Std_ReturnType CanTrcv_ClearTrcvTimeoutFlag( uint8 Transceiver )
{
    Std_ReturnType RetVal_o = E_NOT_OK;
    uint16 SpiPos_u16;
    uint8  TrcvNo_u8;

    // Check all input parameters
    CANTRCV_CHECKDETTRUE_RETURN((Transceiver < CANTRCV_CFG_NUMBER_OF_CANTRCV),
                                  Transceiver, CANTRCV_SID_CLEARTRCVTIMEOUTFLAG, CANTRCV_E_INVALID_TRANSCEIVER);
    CANTRCV_CHECKDETTRUE_RETURN((CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145),
                                  Transceiver, CANTRCV_SID_CLEARTRCVTIMEOUTFLAG, CANTRCV_E_INVALID_TRANSCEIVER);

    // Check for correct Trcv-type
    if (CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145)
    {
        // Get relevant configuration parameter
        // Bit CFS in Reg 22h  Transceiver status register
        SpiPos_u16  = CANTRCV_CFG_SPIPOS_AU8[Transceiver];
        TrcvNo_u8   = CANTRCV_SPIARRAY_AST[SpiPos_u16].No;

        // Set global Flag to start activity in main function
        CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] |= CANTRCV_TPT1145_SPI_STATE_CLEAR_TIMEOUT_MASK;
        RetVal_o = E_OK;
    }
    return RetVal_o;
}
#endif
/**
 ***************************************************************************************************
 * \moduledescription
 * Reads the status of the silence flag from the transceiver hardware
 *
 * \param   uint8                       Transceiver
 * \arg     Transceiver                 identifies Transceiver to which the API has to be applied
 * \return     E_OK:                    Check was allowed
 *             E_NOT_OK:                Error in function
 * \see
 * \note  This API shall exist only if CanTrcvHwPnSupport = TRUE..
 ***************************************************************************************************
 */
#if CANTRCV_HW_PN_SUPPORT == STD_ON
Std_ReturnType CanTrcv_ReadTrcvSilenceFlag( uint8 Transceiver, CanTrcv_TrcvFlagStateType* FlagState )
{
    Std_ReturnType RetVal_o = E_NOT_OK;

    uint16 SpiPos_u16;
    uint8  TrcvNo_u8;

    // Check all input parameters
    CANTRCV_CHECKDETTRUE_RETURN((Transceiver < CANTRCV_CFG_NUMBER_OF_CANTRCV),
                                  Transceiver, CANTRCV_SID_READTRCVSILENCEFLAG, CANTRCV_E_INVALID_TRANSCEIVER);
    CANTRCV_CHECKDETTRUE_RETURN((CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145),
                                  Transceiver, CANTRCV_SID_READTRCVSILENCEFLAG, CANTRCV_E_INVALID_TRANSCEIVER);
    CANTRCV_CHECKDETTRUE_RETURN((FlagState != NULL_PTR),
                                  Transceiver, CANTRCV_SID_READTRCVSILENCEFLAG, CANTRCV_E_PARAM_POINTER);

    // Check for correct Trcv-type
    if (CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145)
    {
        // Get relevant configuration parameter
        // Bit CFS in Reg 22h  Transceiver status register
        SpiPos_u16  = CANTRCV_CFG_SPIPOS_AU8[Transceiver];
        TrcvNo_u8   = CANTRCV_SPIARRAY_AST[SpiPos_u16].No;

        // Check for valid register data
        if((CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] & CANTRCV_TPT1145_SPI_STATE_INITDATA_MASK) == 0u)
        {
            // Calculate  parameter FlagState
            *FlagState = CANTRCV_FLAG_SET;  // Value=0
            if((CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG22] & CANTRCV_CFG_TPT1145_SPI_CBSS_MASK) != 0u)
            {
                *FlagState = CANTRCV_FLAG_CLEARED;  // Value 1
            }

            RetVal_o = E_OK;
        }
    }
    // return retval
    return RetVal_o;
}
#endif
/**
 ***************************************************************************************************
 * \moduledescription
 * The API configures the wake-up of the transceiver for Standby and Sleep Mode: Either the CAN
 * transceiver is woken up by a remote wake-up pattern (standard CAN wake-up) or by the
 * configured remote wake-up frame.
 *
 * \param   CanTrcv_PNActivationType    CANTRCV_PN_ENABLED  = 0,    CANTRCV_PN_DISABLED = 1
 * \arg     ActivationState             identifies Transceiver to which the API has to be applied
 * \return      E_OK: Will be returned, if the PN has been changed to the requested configuration.
 *              E_NOT_OK: Will be returned, if the PN configuration change has failed. The previous
 *                        configuration has not been changed.
 * \see
 * \note
 ***************************************************************************************************
 */
#if CANTRCV_HW_PN_SUPPORT == STD_ON
Std_ReturnType CanTrcv_SetPNActivationState(CanTrcv_PNActivationType ActivationState)
{
    Std_ReturnType RetVal_o = E_NOT_OK;
    uint8  TrcvNo_u8;

    // Check state of Trcv
    /* MR12 RULE 10.3 VIOLATION: type boolean compared with FALSE. This should always be ok */
    CANTRCV_CHECKDETINIT_RETURN((CanTrcv_Prv_InitState_b != FALSE), 0, CANTRCV_SID_SETPNACTIVATIONSTATE);


    for(TrcvNo_u8 = 0; TrcvNo_u8 < CANTRCV_CFG_TPT1145_MAX; TrcvNo_u8++)
    {
        if( ActivationState == CANTRCV_PN_ENABLED)
        {
            CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] |= CANTRCV_TPT1145_SPI_STATE_SET_PNACTIVATE_MASK;
        }
        else    // CANTRCV_PN_DISABLED = 1
        {
            CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] |= CANTRCV_TPT1145_SPI_STATE_CLEAR_PNACTIVATE_MASK;
        }
        RetVal_o = E_OK;
    }
    return RetVal_o;
}
#endif

/**
 ***************************************************************************************************
 * \moduledescription
 * Clears the WUF flag in the transceiver hardware.
 *
 *
 *
 * \param   uint8                       Transceiver
 * \arg     Transceiver                 identifies Transceiver to which the API has to be applied
 * \return     E_OK:                    Check was allowed
 *             E_NOT_OK:                Error in function
 * \see
 * \note
 ***************************************************************************************************
 */
Std_ReturnType CanTrcv_ClearTrcvWufFlag(uint8 Transceiver)
{
    Std_ReturnType RetVal_o = E_OK;
    uint16 SpiPos_u16;
    uint8  TrcvNo_u8;

    // Check all input parameters
    /* MR12 RULE 10.3 VIOLATION: type boolean compared with FALSE. This should always be ok */
    CANTRCV_CHECKDETINIT_RETURN((CanTrcv_Prv_InitState_b != FALSE), Transceiver, CANTRCV_SID_CLEARTRCVWUFFLAG);
    CANTRCV_CHECKDETTRUE_RETURN((Transceiver < CANTRCV_CFG_NUMBER_OF_CANTRCV),
                                  Transceiver, CANTRCV_SID_CLEARTRCVWUFFLAG, CANTRCV_E_INVALID_TRANSCEIVER);
    CANTRCV_CHECKDETTRUE_RETURN(((CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145)),
                                  Transceiver, CANTRCV_SID_CLEARTRCVWUFFLAG, CANTRCV_E_INVALID_TRANSCEIVER);

    // Check for correct Trcv-type
    if (CANTRCV_TRCVTYPE[Transceiver] == CANTrcv_Used_TPT1145)
    {
        // Get relevant configuration parameter
        // Bit CFS in Reg 22h  Transceiver status register
        SpiPos_u16  = CANTRCV_CFG_SPIPOS_AU8[Transceiver];
        TrcvNo_u8   = CANTRCV_SPIARRAY_AST[SpiPos_u16].No;

        // clear global wakeup information
        CanTrcv_Prv_TPT1145_Wakeup_au8[TrcvNo_u8] = 0;

        // Set global Flag to start activity in main function
        CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] |= CANTRCV_TPT1145_SPI_STATE_CLEAR_WUP_MASK;

        # if (CANTRCV_CFG_RB_INDICATION_BEHAVIOUR == CANTRCV_INDICATION_IMMEDIATELY)
        CanIf_ClearTrcvWufFlagIndication(Transceiver);
        # else
        CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] |= CANTRCV_TPT1145_SPI_STATE_CLEAR_TRCV_WUF_FLAG_INDICATION_MASK;
        # endif
    }
    else
    {
        RetVal_o = E_NOT_OK;
    }
    return RetVal_o;
}
/**
 ***************************************************************************************************
 * \moduledescription
 * cyclic function of transceiver driver
 *
 *
 *
 * \param   -
 * \arg     -
 * \return  -
 * \see
 * \note   This function can also directly called from startup HW-tests where Can-Stack is initialized but Os is not running.
 *         At this time SPI often runs in sync-Mode.  On any changes to this function this usecase shall be condsidered
 ***************************************************************************************************
 */
//static uint8 TPT1145_numIndex_MP = 2;
void CanTrcv_TPT1145_MainFunction_10ms(void)
{
    uint8 index_qu8;
    CanTrcv_TrcvModeType TrcvMode;

    uint8 CanTrcv_DiagWorkMode_Lo[CANTRCV_CFG_NUMBER_OF_CANTRCV] = {0};
    uint8 CanTrcv_DiagFaultMode_Lo[CANTRCV_CFG_NUMBER_OF_CANTRCV] = {0};
    // Check init-state of Trcv-HW
    /* MR12 RULE 10.3 VIOLATION: type boolean compared with FALSE. This should always be ok */
    CANTRCV_CHECKDETTRUE_RETURN_NOVAL((CanTrcv_Prv_InitState_b != FALSE), 0, CANTRCV_SID_MAINFUNCTION, CANTRCV_E_UNINIT);

    for(index_qu8 = 0; index_qu8 < CANTRCV_CFG_NUMBER_OF_CANTRCV; index_qu8++)
    {
		// if(Get_Tsk_CpuSleepOrOff())
		// {
		// 	if(!CanTrcv_Prv_TPT1145_PowerDownCnter)
		// 	{
		// 		CanTrcv_SetOpMode(index_qu8, CANTRCV_TRCVMODE_SLEEP);
		// 		CanTrcv_GetOpMode(index_qu8, &TrcvMode);
		// 		if(CANTRCV_TRCVMODE_SLEEP == TrcvMode){
		// 			CanTrcv_Prv_TPT1145_PowerDownCnter++;
		// 		}
		// 	}
		// }
		// else
		// {
		// 	CanTrcv_Prv_TPT1145_PowerDownCnter = 0;
		// }

        # if CANTRCV_CFG_WAKEUP_BY_NODE_USED == STD_ON
        //TODO: The wakeup is checked but now nothing will be done with result, the wakeup strategy should be implemented somewhere else
        (void)CanTrcv_CheckWakeup((uint8)index_qu8);
        # endif

        # if CANTRCV_CFG_SPI_TPT1145_USED == STD_ON
        if(CANTRCV_TRCVTYPE[index_qu8] == CANTrcv_Used_TPT1145)
        {
            //  SPI_SEQ_OK,               //!< Sequence transfer complete.
            //  SPI_SEQ_PENDING,          //!< Sequence transfer pending.
            //  SPI_SEQ_FAILED,           //!< Sequence transfer has failed.
            //  SPI_SEQ_CANCELED,         //!< Sequence was canceled.
            //  SPI_SEQ_CANCEL_PENDING    //!< Cancel was requested but not yet executed.

            uint16  start_u16;
            uint16  size_u16;
            uint16  SpiPos_u16;
            uint16  n_u16;
            uint8   TrcvNo_u8;
            boolean ChangeFlag_b = FALSE;
            Spi_SequenceType        sequence;
            Spi_SeqResultType       Spi_SeqResult;
            
            Spi_DataType            RegVal01_o;
            Spi_DataType            RegVal22_o;
            CanTrcv_TrcvModeType    StateReadBack;

            // Get relevant configuration parameter
            SpiPos_u16  = CANTRCV_CFG_SPIPOS_AU8[index_qu8];
            sequence    = CANTRCV_SPIARRAY_AST[SpiPos_u16].Sequence;
            TrcvNo_u8   = CANTRCV_SPIARRAY_AST[SpiPos_u16].No;

            //if this software component is used in SDK, the mcal spi result should not be used.
            #ifndef CCFC3007BC
            Spi_SeqResult = Spi_GetSequenceResult(sequence);

            // Check for Correct SPI
            if ( Spi_SeqResult == SPI_SEQ_OK)
            #else
            //TODO:ILLD SPI
//            for(m = 0;m < 12;m++)
//            {
//            	CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8-1][m] = CanTrcv_Prv_TPT1145_SpiTempStorageBuf_ao[TrcvNo_u8-1][m];
//            }

            if(1)
			#endif
            {
                // Check if initdata are written/read in last spi-transfer
                if((CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] & CANTRCV_TPT1145_SPI_STATE_INIT_MASK) != 0u)
                {
                    // Set global flag that next SPI data are not initdata any more
                    // Only for first call of main function. In that function Spi was directly filled in CanTrcv_Init_TPT1145 with Rom-Config data
                    // in CanTrcv_Init_TPT1145 CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao is also filled with control registers
                    // Change state and clear INIT-Flag
                    CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] &=(uint16)~((uint16)CANTRCV_TPT1145_SPI_STATE_INIT_MASK);
                    // Possible extension here (not requested yet): Check Init Configuration if required.
                }
                else // if read-registers are valid with control registers:
                {    //   Check for wakeup and store in global variables
                    CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] &= (uint16)~((uint16)CANTRCV_TPT1145_SPI_STATE_INITDATA_MASK); // Rx-Data are valid now

                    if(((CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG63] & CANTRCV_CFG_TPT1145_SPI_CW_MASK)   != 0u) || // Reg 0x63: CW in Transceiver event status
                       ((CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG4B] & CANTRCV_CFG_TPT1145_SPI_WPVS_MASK) != 0u))   // Reg 0x4B: WAKE pin status
                    {
                        CanTrcv_Prv_TPT1145_Wakeup_au8[TrcvNo_u8] = 1;   /* 0 = no wakeup; 1 = wakeup detected */
                    }
                    // Only check PON-Wakeup if configured at PN
                    if( ((CANTRCV_PNTRCV_ST[TrcvNo_u8].PnEnabled == FALSE) || (CANTRCV_PNTRCV_ST[TrcvNo_u8].PowerOnFlag == TRUE)) &&
                       ((CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG61] & CANTRCV_CFG_TPT1145_SPI_PO_MASK)   != 0u))   // Reg 0x4B: Power on status
                    {
                        CanTrcv_Prv_TPT1145_Wakeup_au8[TrcvNo_u8] = 1;   /* 0 = no wakeup; 1 = wakeup detected */
                    }

                #  if (CANTRCV_CFG_DEM_ENABLE == STD_ON)
                    // Check for correct communication with Trcv:
                    // in normal  : Reg  61 and 01 should not all FF or Command RegAdr should not read back as 0
                    if(((CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][2] &
                         CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][4] & 0x0Fu) == 0x0Fu) ||
                       (CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][0] == 0x00 ) )
                    {
                        Dem_ReportErrorStatus( CanTrcv_Dem_st[TrcvNo_u8].EventId, DEM_EVENT_STATUS_FAILED);
                    }
                    else
                    {
                        Dem_ReportErrorStatus( CanTrcv_Dem_st[TrcvNo_u8].EventId, DEM_EVENT_STATUS_PASSED);
                    }
                #  endif
                    // Check if CanIf_ClearTrcvWufFlagIndication should be called
                    //  This is done if the request CANTRCV_TPT1145_SPI_STATE_CLEAR_WUP_MASK is already done and correct sent
                    //  (see note1 in AR SWS4.0.3 chapter 9.4)
                #  if (CANTRCV_HW_PN_SUPPORT == STD_ON)
                    if(((CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] & CANTRCV_TPT1145_SPI_STATE_CLEAR_TRCV_WUF_FLAG_INDICATION_MASK) != 0u) &&
                       ((CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] & CANTRCV_TPT1145_SPI_STATE_CLEAR_WUP_MASK) == 0u))
                    {
                        // Clear global request-flag
                        CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] &=  (uint16)~((uint16)CANTRCV_TPT1145_SPI_STATE_CLEAR_TRCV_WUF_FLAG_INDICATION_MASK);
                        // call indication function
                        //if this software component is used in SDK, the autosar canif should not be used.
                        #ifndef CCFC3008PT
                        //TODO
                        //CanIf_ClearTrcvWufFlagIndication(TrcvNo_u8);
                        #endif
                    }
                #  endif
                    // Read out state out of registers and store it in local variable
                    RegVal01_o  = CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG01] & CANTRCV_CFG_TPT1145_SPI_MC_AND_MASK;
                    RegVal22_o  = CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG22] & CANTRCV_CFG_TPT1145_SPI_CTS_MASK;
                    if( RegVal01_o ==  CANTRCV_CFG_TPT1145_SPI_MC_NM_OR_MASK)
                    {   // If in mode is on, check if there is a failure to disable the CAN-communication by checking bit CTS in Reg22
                        if ( RegVal22_o != 0 )  // if transmitter is also on, than TPT1145 is really in normal mode
                        {
                            StateReadBack = CANTRCV_TRCVMODE_NORMAL;
                        }
                        else    // There was a failure somewhere which disables transmitting. It is assumed that TRCV is is standby mode
                        {
                            StateReadBack = CANTRCV_TRCVMODE_STANDBY;
                        }
                    }
                    else if ( RegVal01_o ==  CANTRCV_CFG_TPT1145_SPI_MC_SBM_OR_MASK)
                    {
                        StateReadBack = CANTRCV_TRCVMODE_STANDBY;
                    }
                    else if ( RegVal01_o ==  CANTRCV_CFG_TPT1145_SPI_MC_SM_OR_MASK)
                    {
                        StateReadBack = CANTRCV_TRCVMODE_SLEEP;
                    }
                    else
                    {   // in error case, set StateReadBack same as CanTrcv_Prv_TPT1145_State
                        StateReadBack = CanTrcv_Prv_TPT1145_State[TrcvNo_u8];
                        CANTRCV_CHECKDETTRUE_NORETURN((FALSE), TrcvNo_u8, CANTRCV_SID_MAINFUNCTION, CANTRCV_E_SPI);
                    }

                #  if (CANTRCV_CFG_RB_INDICATION_BEHAVIOUR != CANTRCV_INDICATION_IMMEDIATELY)
                    // Check if Mode-indication function should be called
                    // Send async mode indication if read back state is same as requested state
                    // Com-Stack does not request sleep state, so it is no problem if this indication is never sent
                    if(((CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] & CANTRCV_TPT1145_SPI_STATE_MODE_INDICATION_MASK) != 0u) &&
                        (StateReadBack == CanTrcv_Prv_TPT1145_ReqState[TrcvNo_u8]))
                    {
                        CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] &=  (uint16)~((uint16)CANTRCV_TPT1145_SPI_STATE_MODE_INDICATION_MASK);
                        //TODO: implemente the CanIf_TrcvModeIndication
                        //CanIf_TrcvModeIndication((uint8)index_qu8, StateReadBack);
                    }
                #  endif
                    // The read state if different than expected state.
                    if(StateReadBack != CanTrcv_Prv_TPT1145_State[TrcvNo_u8])
                    {
                        //adapt internal trcv-mode to read back mode
                        CanTrcv_Prv_TPT1145_State[TrcvNo_u8] = StateReadBack;
                    }
                }

                // Check if wakeup should be cleared
                if((CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] & CANTRCV_TPT1145_SPI_STATE_CLEAR_WUP_MASK) != 0u)  // Check if request is set in CanTrcv_SetWakeupMode_TPT1145
                {
                    // Write register values in mirror RAM to clear wakeup
                    CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] &=  (uint16)~((uint16)CANTRCV_TPT1145_SPI_STATE_CLEAR_WUP_MASK);
                    // Clear WakePinEvent
                    CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG60] |= CANTRCV_CFG_TPT1145_SPI_WPE_MASK;
                    CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG60] &= (Spi_DataType)~CANTRCV_CFG_TPT1145_READ_ONLY_MASK;
                    // Clear PowerOn event
                    CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG61] |= CANTRCV_CFG_TPT1145_SPI_PO_MASK;
                    CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG61] &= (Spi_DataType)~CANTRCV_CFG_TPT1145_READ_ONLY_MASK;
                    // Clear CAN wake-up event detected   CW
                    CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG63] |= CANTRCV_CFG_TPT1145_SPI_CW_MASK;
                    CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG63] &= (Spi_DataType)~CANTRCV_CFG_TPT1145_READ_ONLY_MASK;
                    // Clear WAKE pin event status register WPF + WPR
                    CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG64] |= CANTRCV_CFG_TPT1145_SPI_WPR_MASK + CANTRCV_CFG_TPT1145_SPI_WPF_MASK;
                    CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG64] &= (Spi_DataType)~CANTRCV_CFG_TPT1145_READ_ONLY_MASK;
                    // Clear stored wakeup
                    CanTrcv_Prv_TPT1145_Wakeup_au8[TrcvNo_u8] = 0; /* 0: no wakeup; 1=wakeup detected */
                    ChangeFlag_b = TRUE;
                }

                // Check if timoutflag should be cleard
                if((CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] & CANTRCV_TPT1145_SPI_STATE_CLEAR_TIMEOUT_MASK) != 0u) // Check if request is set in CanTrcv_ClearTrcvTimeoutFlag
                {
                    // Write register values in mirror RAM to clear timout flag
                    CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] &=  (uint16)~((uint16)CANTRCV_TPT1145_SPI_STATE_CLEAR_TIMEOUT_MASK);
                    CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG63] |= CANTRCV_CFG_TPT1145_SPI_CBS_MASK;
                    CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG63] &= (Spi_DataType)~CANTRCV_CFG_TPT1145_READ_ONLY_MASK;
                    ChangeFlag_b = TRUE;
                }

                // check if PNActivationState should be cleared
                if((CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] & CANTRCV_TPT1145_SPI_STATE_CLEAR_PNACTIVATE_MASK) != 0u)   // Check if request is set to clear CanTrcv_SetPNActivationState
                {   // Write register values in mirror RAM to clear PNActivationState
                    // CPNC =0 = disable CAN selective wake-up
                    CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] &= (uint16)~((uint16)CANTRCV_TPT1145_SPI_STATE_CLEAR_PNACTIVATE_MASK);
                    CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG20]   &=  (Spi_DataType)~(CANTRCV_CFG_TPT1145_READ_ONLY_MASK + CANTRCV_CFG_TPT1145_SPI_CPNC_MASK);
                    ChangeFlag_b = TRUE;
                }

                if((CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] & CANTRCV_TPT1145_SPI_STATE_SET_PNACTIVATE_MASK) != 0u) // Check if request is set in CanTrcv_SetPNActivationState
                {
                    // Write register values in mirror RAM to set PNActivationState
                    CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] &=  (uint16)~((uint16)CANTRCV_TPT1145_SPI_STATE_SET_PNACTIVATE_MASK);
                    CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG20]   |=  CANTRCV_CFG_TPT1145_SPI_CPNC_MASK;
                    CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG20]   &=  (Spi_DataType)~CANTRCV_CFG_TPT1145_READ_ONLY_MASK;
                    ChangeFlag_b = TRUE;
                }

                // Check if requested state should be written to trcv
                if((CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] & CANTRCV_TPT1145_SPI_STATE_SETOPMODE) != 0u)
                {
                    // Clear request and set registers for requested state
                    CanTrcv_Prv_TPT1145_SpiState[TrcvNo_u8] &= (uint16)~((uint16)CANTRCV_TPT1145_SPI_STATE_SETOPMODE);

                    switch (CanTrcv_Prv_TPT1145_ReqState[TrcvNo_u8])
                    {
                        case CANTRCV_TRCVMODE_NORMAL:
                        {
                            // Entering CAN Active is possible only while the TXD pin is HIGH (ApplHint P26)
                            // During CAN Active, a LOW level on pin TXD that persists longer than tto(dom)TXD will disable the transmitter, releasing the bus lines to recessive state
                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG01] &= (Spi_DataType)CANTRCV_CFG_TPT1145_SPI_MC_NM_AND_MASK;
                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG01] |= (Spi_DataType)CANTRCV_CFG_TPT1145_SPI_MC_NM_OR_MASK;
                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG20] &= (Spi_DataType)CANTRCV_CFG_TPT1145_SPI_CMC_NM_AND_MASK;
                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG20] |= (Spi_DataType)CANTRCV_SPIARRAY_AST[SpiPos_u16].SpecReg1;
                        }
                        break;
                        case CANTRCV_TRCVMODE_SLEEP:
                        {
                            // clear outstanding error and statusbits
                            // if no wakeup is configured (CAN or PIN, Reg 23,4C) Trcv goes into Standby Mode (AppHint P20)
                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG60] = (Spi_DataType)0xC00D;   // write 1 = clear bits for Reg60
                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG61] = (Spi_DataType)0xC216;   // write 1 = clear bits for Reg61
                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG63] = (Spi_DataType)0xC633;   // write 1 = clear bits for Reg63
                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG64] = (Spi_DataType)0xC803;   // write 1 = clear bits for Reg64

                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG01] &= (Spi_DataType)CANTRCV_CFG_TPT1145_SPI_MC_SM_AND_MASK;
                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG01] |= (Spi_DataType)CANTRCV_CFG_TPT1145_SPI_MC_SM_OR_MASK;
                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG20] &= (Spi_DataType)CANTRCV_CFG_TPT1145_SPI_CMC_SM_AND_MASK;
                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG20] |= (Spi_DataType)CANTRCV_CFG_TPT1145_SPI_CMC_SM_OR_MASK;
                        }
                        break;
                        case CANTRCV_TRCVMODE_STANDBY:
                        {
                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG01] &= (Spi_DataType)CANTRCV_CFG_TPT1145_SPI_MC_SBM_AND_MASK;
                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG01] |= (Spi_DataType)CANTRCV_CFG_TPT1145_SPI_MC_SBM_OR_MASK;
                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG20] &= (Spi_DataType)CANTRCV_CFG_TPT1145_SPI_CMC_SBM_AND_MASK;
                            CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG20] |= (Spi_DataType)CANTRCV_CFG_TPT1145_SPI_CMC_SBM_OR_MASK;
                        }
                        break;
                        default:
                        {
                            CANTRCV_CHECKDET_NORETURN(TrcvNo_u8, CANTRCV_SID_MAINFUNCTION, 0);
                        }
                        break;
                    }
                    ChangeFlag_b = TRUE;
                }

                // Check if any above line needs an update of registers in trcv
                if (ChangeFlag_b == FALSE)
                {
                    // Nothing changed -> nothing to write
                    // Set all "ReadOnlybits"
                    for(n_u16 = 0; n_u16 < CANTRCV_CFG_TPT1145_SPI_CTRL_MAX; n_u16++)
                    {
                        CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][n_u16] |= (Spi_DataType)CANTRCV_CFG_TPT1145_READ_ONLY_MASK;
                    }
                }
                else
                {
                    // open lock bits of trcv
                    CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG0A_A] &= (Spi_DataType)~CANTRCV_CFG_TPT1145_READ_ONLY_MASK;
                    CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG0A_E] &= (Spi_DataType)~CANTRCV_CFG_TPT1145_READ_ONLY_MASK;
                }

                // Get relevant SPI-configuration data
                SpiPos_u16 = CANTRCV_CFG_SPIPOS_AU8[index_qu8];
                start_u16 =  CANTRCV_SPIARRAY_AST[SpiPos_u16].ControlStartPos;
                size_u16  =  CANTRCV_SPIARRAY_AST[SpiPos_u16].ControlEndPos - start_u16;
                //if this software component is used in SDK, the lld driver should be included.
                // Prepare to read Registers
                IoHwAbs_Spi_SetupEB(CANTRCV_SPIARRAY_AST[SpiPos_u16].Channel,    // generated by SPI
                					&CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[TrcvNo_u8][0],     // points to RAM-Tx buffer
									&CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][0],     // points to RAM-Rx buffer
									size_u16);
                Spi_SyncTransmit(sequence);
                #endif
                
            }
            else   // Spi_SeqResult == SPI_SEQ_OK
            {
                // SPI Communication fails
                CANTRCV_CHECKDET_NORETURN((uint8)index_qu8 , CANTRCV_SID_MAINFUNCTION, CANTRCV_E_PARAM_TRCV_WRONG_CONF);
            }

            CanTrcv_DiagWorkMode_Lo[index_qu8] = CanTrcv_Prv_TPT1145_State[TrcvNo_u8];
            CanTrcv_DiagFaultMode_Lo[index_qu8] = (CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[TrcvNo_u8][CANTRCV_CFG_TPT1145_SPI_REG22] & CANTRCV_CFG_TPT1145_SPI_CPNERR_MASK) >> 6;                              ;
   
        }

 }

    Evpt_DiagDb_SetValue(DIAG_VAR_CAN_TRCV_WORK_STATE, CanTrcv_DiagWorkMode_Lo, sizeof(uint8) * CANTRCV_CFG_NUMBER_OF_CANTRCV);
    Evpt_DiagDb_SetValue(DIAG_VAR_CAN_TRCV_FAULT_STATE, CanTrcv_DiagFaultMode_Lo, sizeof(uint8) * CANTRCV_CFG_NUMBER_OF_CANTRCV);

}

Std_ReturnType CanTrcv_ProcessKL30WakeupPowerDown(CanTrcv_PowerOffProcess func)
{
    uint8 i;
    uint8 CanTrcv_valAllBitSet_Lo = 1;
    uint8 CanTrcv_valResBuf_Lo[CANTRCV_CFG_NUMBER_OF_CANTRCV] = {0};
    Std_ReturnType CanTrcv_valRet_Lo = E_NOT_OK;

    for(i= 0;i < CANTRCV_CFG_NUMBER_OF_CANTRCV;i++) {
        CanTrcv_valRet_Lo = Spi_SetupEB(CANTRCV_SPIARRAY_AST[i].Channel, // generated by SPI
            &CanTrcv_Prv_TPT1145_SpiCtrlTxBuf_ao[i][CANTRCV_CFG_TPT1145_SPI_REG61], // points to RAM-Tx buffer
            &CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[i][CANTRCV_CFG_TPT1145_SPI_REG61], // points to RAM-Rx buffer
            1);
        if(E_OK != CanTrcv_valRet_Lo) {
            return CanTrcv_valRet_Lo;
        }

        CanTrcv_valRet_Lo = Spi_SyncTransmit(CANTRCV_SPIARRAY_AST[i].Sequence);
        if(E_OK != CanTrcv_valRet_Lo) {
            return CanTrcv_valRet_Lo;
        }

        CanTrcv_valResBuf_Lo[i] = (CanTrcv_Prv_TPT1145_SpiCtrlRxBuf_ao[i][CANTRCV_CFG_TPT1145_SPI_REG61] & CANTRCV_CFG_TPT1145_SPI_PO_MASK) ? 1 : 0;
        if(0 == CanTrcv_valResBuf_Lo[i]) {
            CanTrcv_valAllBitSet_Lo = 0;
        }
    }

    if(CanTrcv_valAllBitSet_Lo && (NULL != func)) {
        func();
    }

    return CanTrcv_valRet_Lo;
}

/**
 ***************************************************************************************************
 * \moduledescription
 * Reads the transceiver diagnostic status periodically and sets product/development accordingly
 *
 *
 *
 * \param   -
 * \arg     -
 * \return  -
 * \see
 * \note     not used in current impl.
 ***************************************************************************************************
 */
#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
# if (CANTRCV_CFG_BUS_ERR_FLAG_GENERAL == STD_ON)
void CanTrcv_MainFunctionDiagnostics( void )
{
    uint8_least index_qu8;
    uint16      SpiPos_u16;

    // Check all input parameters
    CANTRCV_CHECKDETTRUE_RETURN_NOVAL((CanTrcv_Prv_InitState_b == TRUE), 0, CANTRCV_SID_MAINFUNCTIONDIAGNOSTICS, CANTRCV_E_UNINIT);

    // For all TPT1145
    for(index_qu8 = 0; index_qu8 < CANTRCV_CFG_NUMBER_OF_CANTRCV; index_qu8++)
    {
        if(CANTRCV_TRCVTYPE[index_qu8] == CANTrcv_Used_TPT1145)
        {
            uint8   TrcvNo_u8;

            SpiPos_u16  = CANTRCV_CFG_SPIPOS_AU8[index_qu8];
            TrcvNo_u8   = CANTRCV_SPIARRAY_AST[SpiPos_u16].No;

            if( CANTRCV_PNTRCV_ST[TrcvNo_u8].BusErrFlag == TRUE)
            {
                // Do something. To be specified!
            }
        }
    }
    return;
}
# endif
#endif

uint8 CanTrcv_IsPoweredOff(void)
{
	return CanTrcv_Prv_TPT1145_PowerDownCnter;
}

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
* Name______:CanTrcv_cfg
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
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: B_BSW_AR40.21.0.00                Module Package Version
 * $Editor_____: ECU.WorX_2016.1.2                Tool Version
 * $Model______: 2.3.0.4                 ECU Parameter Definition Version
 *

 </VersionHead>*/


#include "EvptCdd_CanTrcv_Prv.h"

uint8 CanTrcv_TrcvType[]=
{
	CANTrcv_Used_TPT1145,
    CANTrcv_Used_TPT1145
};


CanTrcv_FctP_tst CanTrcv_FctP_st[]=
{
    {    
        &CanTrcv_Init_TPT1145,
        &CanTrcv_SetOpMode_TPT1145,
        &CanTrcv_GetOpMode_TPT1145,
        &CanTrcv_GetBusWuReason_TPT1145,
        &CanTrcv_SetWakeupMode_TPT1145,
        &CanTrcv_CheckWakeup_TPT1145
    },
    {   
        &CanTrcv_Init_TPT1145,
        &CanTrcv_SetOpMode_TPT1145,
        &CanTrcv_GetOpMode_TPT1145,
        &CanTrcv_GetBusWuReason_TPT1145,
        &CanTrcv_SetWakeupMode_TPT1145,
        &CanTrcv_CheckWakeup_TPT1145
    }

};

/* Links to canTrcv_Generate_CanTrcv_SpiArray_ast and canTrcv_Generate_CanTrcv_FctP_st */
const uint8 CanTrcv_Cfg_SpiPos_au8[]=
{
    0,
    1
};

const CanTrcv_Spi_tst CanTrcv_SpiArray_ast[]=
{
    {       					// TPT1145_01
        0,
		SpiChannel_CAN1_TPT1445, // SpiChannel   Spi_ChannelType     Channel
		SpiSequence_CAN1_TPT1445,//  Sequence     Spi_SequenceType    Sequence
        NULL, 					// Wakeupsource
        0,  					// Starpos for init
        29,  					// Startpos for Control Reg
        41,  					// Endpos for Control Reg
        0x02u       			// CMC or-Mask in normal-mode
    },
        {       					// TPT1145_01
        1,
		SpiChannel_CAN2_TPT1445, // SpiChannel   Spi_ChannelType     Channel
		SpiSequence_CAN2_TPT1445,//  Sequence     Spi_SequenceType    Sequence
        NULL, 					// Wakeupsource
        41,  					// Starpos for init
        70,  					// Startpos for Control Reg
        82,  					// Endpos for Control Reg
        0x02u       			// CMC or-Mask in normal-mode
    },
};

/*
 * If it is added or deleted, remember to modify the functions
 * related to CAN activation in the CanTrcv_Init_TPT1145 function.
 * */
Spi_DataType CanTrcv_CfgSpiChannel_ao[]=
{
    // TPT1145_01 InitStarPos
    0x1400,   //0  Reg:0x0A Lock control. Spi write access enable
    0x0207,   //1  Reg 1 Mode control      			(((0x01<<1)+0) | 0x07)
    0x0800,   //2  Reg 4 System event enable			(((0x04<<1)+0) | 0x00)
    0x4603,   //3  Reg 23 Transceiver event enable	(((0x23<<1)+0) | 0x03)
    0x4c05,   //4  Reg 26 Data rate					(((0x26<<1)+0) | 0x03)
    0x4e00,   //5  Reg 27 Identifier 0
    0x5000,   //6  Reg 28 Identifier 1
    0x5200,   //7  Reg 29 Identifier 2
    0x5400,   //8  Reg 2A Identifier 3
    0x5600,   //9  Reg 2B Mask0
    0x5800,   //10 Reg 2C Mask1
    0x5a00,   //11 Reg 2D Mask2						for standard frame
    0x5c00,   //12 Reg 2E Mask3						for standard frame
    0x5e08,   //13 Reg 2F Frame control				(((0x2F<<1)+0) | 0x00001000)
    0xd000,   //14 Reg 68 Data Mask0
    0xd200,   //15 Reg 69 Data Mask1
    0xd400,   //16 Reg 6A Data Mask2
    0xd600,   //17 Reg 6B Data Mask3
    0xd800,   //18 Reg 6C Data Mask4
    0xda00,   //19 Reg 6D Data Mask5
    0xdc00,   //20 Reg 6E Data Mask6
    0xde00,   //21 Reg 6F Data Mask7
    0x9803,   //22 Reg 4C WAKE pin enable
    0xc300,   //23 Reg 61 Not clear register and old errors
    0xc700,   //24 Reg 63 Not clear register and old errors
    0xc100,   //25 Reg 60 Not clear register and old errors
    0x4072,   //26 Reg 20 CAN control
    0x147F,   //27 Reg:0x0A Lock control. Spi write access disable
    0x1400,   //28 Reg:0x0A Lock control
    // Startpos for Control Reg
    0x1400,   // 0 Reg:0x0A Lock control. Spi write access enable
    0xc100,   // 1 Reg 60 Event capture status
    0xc300,   // 2 Reg 61 System event status
    0xc700,   // 3 Reg 63 Transceiver event status
    0x4072,   // 4 Reg 20 CAN control
    0x0207,   // 5 Reg 1 Mode control
    0x9803,   // 6 Reg 4C WAKE pin disable
    0x0700,   // 7 Reg 03 Main status
    0x4500,   // 8 Reg 22 Transceiver status
    0x9700,   // 9 Reg 4b WAKE pin status
    0xc900,   // 10 Reg 64 WAKE pin event status
	0x147F,   // 11 Reg:0x0A Lock control. Spi write access disable
    // Endpos for Diag Reg
    // TPT1145_02 InitStarPos
    0x1400,   //0  Reg:0x0A Lock control. Spi write access enable
    0x0207,   //1  Reg 1 Mode control      			(((0x01<<1)+0) | 0x07)
    0x0800,   //2  Reg 4 System event enable			(((0x04<<1)+0) | 0x00)
    0x4603,   //3  Reg 23 Transceiver event enable	(((0x23<<1)+0) | 0x03)
    0x4c05,   //4  Reg 26 Data rate					(((0x26<<1)+0) | 0x03)
    0x4e00,   //5  Reg 27 Identifier 0
    0x5000,   //6  Reg 28 Identifier 1
    0x5200,   //7  Reg 29 Identifier 2
    0x5400,   //8  Reg 2A Identifier 3
    0x5600,   //9  Reg 2B Mask0
    0x5800,   //10 Reg 2C Mask1
    0x5a00,   //11 Reg 2D Mask2						for standard frame
    0x5c00,   //12 Reg 2E Mask3						for standard frame
    0x5e08,   //13 Reg 2F Frame control				(((0x2F<<1)+0) | 0x00001000)
    0xd000,   //14 Reg 68 Data Mask0
    0xd200,   //15 Reg 69 Data Mask1
    0xd400,   //16 Reg 6A Data Mask2
    0xd600,   //17 Reg 6B Data Mask3
    0xd800,   //18 Reg 6C Data Mask4
    0xda00,   //19 Reg 6D Data Mask5
    0xdc00,   //20 Reg 6E Data Mask6
    0xde00,   //21 Reg 6F Data Mask7
    0x9803,   //22 Reg 4C WAKE pin enable
    0xc300,   //23 Reg 61 Not clear register and old errors
    0xc700,   //24 Reg 63 Not clear register and old errors
    0xc100,   //25 Reg 60 Not clear register and old errors
    0x4072,   //26 Reg 20 CAN control
    0x147F,   //27 Reg:0x0A Lock control. Spi write access disable
    0x1400,   //28 Reg:0x0A Lock control
    // Startpos for Control Reg
    0x1400,   // 0 Reg:0x0A Lock control. Spi write access enable
    0xc100,   // 1 Reg 60 Event capture status
    0xc300,   // 2 Reg 61 System event status
    0xc700,   // 3 Reg 63 Transceiver event status
    0x4072,   // 4 Reg 20 CAN control
    0x0207,   // 5 Reg 1 Mode control
    0x9803,   // 6 Reg 4C WAKE pin disable
    0x0700,   // 7 Reg 03 Main status
    0x4500,   // 8 Reg 22 Transceiver status
    0x9700,   // 9 Reg 4b WAKE pin status
    0xc900,   // 10 Reg 64 WAKE pin event status
	0x147F,   // 11 Reg:0x0A Lock control. Spi write access disable
    // Endpos for Diag Reg
};

const CanTrcv_PnTrcv_tst CanTrcv_PnTrcv_st[]=
{
    {       // TPT1145_01
        FALSE,  // CanTrcvBusErrFlag
        TRUE,  // CanTrcvPnEnabled
        FALSE  // CanTrcvPowerOnFlag
    },
    {       // TPT1145_01
        FALSE,  // CanTrcvBusErrFlag
        TRUE,  // CanTrcvPnEnabled
        FALSE  // CanTrcvPowerOnFlag
    }
};


#if (CANTRCV_CFG_DEM_ENABLE == STD_ON)
const CanTrcv_Dem_tst CanTrcv_Dem_st[]=
{
    {       // TPT1145_01
        0
    },
    {       // TPT1145_02
        0
    }
};
#endif



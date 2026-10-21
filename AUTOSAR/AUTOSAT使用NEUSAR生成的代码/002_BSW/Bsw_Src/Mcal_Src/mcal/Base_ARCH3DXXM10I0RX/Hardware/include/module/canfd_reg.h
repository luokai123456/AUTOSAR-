#ifndef CANFD_REG_H_
#define CANFD_REG_H_

/* ============================================================================
   =============================== Module: CANFD ==============================
   ============================================================================ */

typedef union
{
	vuint8_t	R;			//CAN Node Configuration Register NODECFG
	struct
	{
		vuint8_t Reserved: 	5;
		vuint8_t TMSE: 			1;		//CAN XL transceiver mode switch enable
		vuint8_t ROP: 			1;		//Restricted Operation
		vuint8_t CES: 			1;		//CAN Error Signaling
	}B;
}CAN_FD_NODECFG_tag;

typedef union
{
	vuint8_t	R;			//CiA 603 Time-Stamping Configuration TSCFG
	struct
	{
		vuint8_t Reserved: 	6;
		vuint8_t TSPOS: 		1;		//TIME-stamping POSition
		vuint8_t TSEN: 			1;		//TIME-stamping ENable
	}B;
}CAN_FD_TSCFG_tag;

typedef union
{
	vuint32_t	R;			//CAN FD Bit Timing
	struct
	{
		vuint32_t FD_SEG_1: 		8;		//Bit time segment 1
		vuint32_t Reserved_0: 	9;
		vuint32_t FD_SEG_2: 		7;		//Bit time segment 2
		vuint32_t Reserved_1: 	1;
		vuint32_t FD_SJW: 			7;		//Synchronization jump width
	}B;
}CAN_FD_FD_TIME_tag;

typedef union
{
	vuint32_t	R;			//CAN XL Bit Timing
	struct
	{

		vuint32_t XL_SEG_1: 		8;		//Bit time segment 1
		vuint32_t Reserved_0: 	9;
		vuint32_t XL_SEG_2: 		7;		//Bit time segment 2
		vuint32_t Reserved_1: 	1;
		vuint32_t XL_SJW: 			7;		//Synchronization jump width
	}B;
}CAN_FD_XL_TIME_tag;

typedef union
{
	vuint8_t	R;			//Retransmission and Re-Arbitration limit
	struct
	{
		vuint8_t Reserved_0: 	1;
		vuint8_t RETLIM:			3;		//Retransmission limit
		vuint8_t Reserved_1: 	1;
		vuint8_t REALIM:			3;		//Re-Arbitration limit
	}B;
}CAN_FD_RELIM_tag;

typedef union
{
	vuint32_t	R;			//Interrupt flag reg
	struct
	{
		vuint32_t RIF:				1;		//Receive Interrupt Flag
		vuint32_t ROIF:				1;		//RB Overflow Interrupt Flag
		vuint32_t RFIF:				1;		//RB Full Interrupt Flag
		vuint32_t RAFIF:			1;		//RB Almost Full Interrupt Flag
		vuint32_t TPIF:				1;		//Transmission Primary Interrupt Flag
		vuint32_t TSIF:				1;		//Transmission Secondary Interrupt Flag
		vuint32_t EIF:				1;		//Error Interrupt Flag
		vuint32_t AIF:				1;		//Abort Interrupt Flag
		vuint32_t MDEIF:			1;		//Memory Protection (ECC): Data Error Interrupt Flag
		vuint32_t MDWIF:			1;		//Memory Protection (ECC): Data Warning Interrupt Flag
		vuint32_t WTIF:				1;		//TTCAN: Watch Trigger Interrupt Flag
		vuint32_t TEIF:				1;		//TTCAN: Trigger Error Interrupt Flag
		vuint32_t TTIF:				1;		//TTCAN: Time Trigger Interrupt Flag
		vuint32_t EPIF:				1;		//Error Passive Interrupt Flag. EPIF will be activated if EPASS changes and if EPIE=1.
		vuint32_t ALIF:				1;		//Arbitration Lost Interrupt Flag
		vuint32_t BEIF:				1;		//Bus Error Interrupt Flag
		vuint32_t Reserved_0: 	5;
		vuint32_t SWIF:				1;		//DMR / TMR: Safety warning interrupt flag
		vuint32_t SEIF:				1;		//DMR / TMR: Safety Error Interrupt Flag
		vuint32_t MAEIF:			1;		//Memory Protection (ECC): Address Error Interrupt Flag
		vuint32_t EWARN:		1;		//Error warning limit reach
		vuint32_t EPASS:		1;		//Error passive state
		vuint32_t Reserved_1: 	6;
	}B;
}CAN_FD_INTF_tag;

typedef union
{
	vuint32_t	R;			// Interrupt Enable Register
	struct
	{
		vuint32_t RIE:				1;		//Receive Interrupt Enable
		vuint32_t ROIE:				1;		//RB Overflow Interrupt Enable
		vuint32_t RFIE:				1;		//RB Full Interrupt Enable
		vuint32_t RAFIE:			1;		//RB Almost Full Interrupt Enable
		vuint32_t TPIE:				1;		//Transmission Primary Interrupt Enable
		vuint32_t TSIE:				1;		//Transmission Secondary Interrupt Enable
		vuint32_t EIE:				1;		//Error Interrupt Enable
		vuint32_t Reserved_0: 	2;
		vuint32_t MDWIE:			1;		//Memory Protection (ECC): Data Warning Interrupt Enable
		vuint32_t WTIE:				1;		//TTCAN: Watch Trigger Interrupt Enable
		vuint32_t Reserved_1: 	1;
		vuint32_t TTIE:				1;		//TTCAN: Time Trigger Interrupt Enable
		vuint32_t EPIE:				1;		//Error Passive Interrupt Enable. EPIF will be activated if EPASS changes and if EPIE=1.
		vuint32_t ALIE:				1;		//Arbitration Lost Interrupt Enable
		vuint32_t BEIE:				1;		//Bus Error Interrupt Enable
		vuint32_t Reserved_2: 	5;
		vuint32_t SWIE:				1;		//DMR / TMR: Safety Warning Interrupt Enable
		vuint32_t Reserved_3: 	10;
	}B;
}CAN_FD_INTE_tag;

typedef union
{
	vuint16_t	R;			// Transmit Status Registers TSTAT_1
	struct
	{
		vuint16_t HANDLE:		8;		//Handle for frame identification
		vuint16_t Reserved_0: 	5;
		vuint16_t TSTAT:		3;		//Transmission Status Code
	}B;

}CAN_FD_TSTAT_1_tag;

typedef union
{
	vuint16_t	R;			// Transmit Status Registers TSTAT_2
	struct
	{
		vuint16_t HANDLE:		8;		//Handle for frame identification
		vuint16_t Reserved_0: 	5;
		vuint16_t TSTAT:		3;		//Transmission Status Code
	}B;

}CAN_FD_TSTAT_2_tag;

typedef union
{
	vuint8_t	R;			// Configuration and Status Register
	struct
	{
		vuint8_t RESET: 			1;		//RESET request bit
		vuint8_t LBME: 				1;		//Loop Back Mode, External
		vuint8_t LBMI: 				1;		//Loop Back Mode, Internal
		vuint8_t Reserved_0: 	4;
		vuint8_t BUSOFF: 			1;		//Bus Off
	}B;

}CAN_FD_CFG_STAT_tag;

typedef union
{
	vuint8_t	R;			// Transmission Command Register
	struct
	{
		vuint8_t TBSEL: 			1;		//Transmit Buffer Select
		vuint8_t LOM: 				1;		//Listen Only Mode
		vuint8_t STBY: 				1;		//Transceiver Standby Mode
		vuint8_t TPE: 				1;		//Transmit Primary Enable
		vuint8_t TPA: 				1;		//Transmit Primary Abort
		vuint8_t TSONE: 			1;		//Transmit Secondary ONE frame
		vuint8_t TSALL: 			1;		//Transmit Secondary ALL frames
		vuint8_t TSA: 				1;		//Transmit Secondary Abort
	}B;

}CAN_FD_TCMD_tag;

typedef union
{
	vuint8_t	R;			// Transmission Control Register
	struct
	{
		vuint8_t FD_ISO: 			1;		//CAN FD ISO mode
		vuint8_t TSNEXT: 			1;		//Transmit buffer Secondary NEXT
		vuint8_t TSMODE: 			1;		//Transmit buffer Secondary operation MODE
		vuint8_t TTTBM: 			1;		//TTCAN Transmit Buffer Mode
		vuint8_t Reserved_0: 	1;
		vuint8_t TSFF: 				1;		//
		vuint8_t TSSTAT: 			2;		//Transmission Secondary STATus bits
	}B;

}CAN_FD_TCRL_tag;


typedef enum
{
    RB_Empty                        = 0,
    RB_NotEmptyLessThanAFWL         = 1,
    RB_NotFullMoreThanOrEqualToAFWL = 2,
    RB_Full                         = 3
}CAN_FD_RSTAT_tag;

typedef union
{
	vuint8_t	R;			// Receive Control Register
	struct
	{
		vuint8_t SACK: 				1;		//Self-ACKnowledge
		vuint8_t ROM: 				1;		//Receive buffer Overflow Mode
		vuint8_t ROV: 			1;		//Receive buffer OVerflow
		vuint8_t RREL: 				1;		//Receive buffer RELease
		vuint8_t RBALL: 			1;		//Receive Buffer stores ALL data frames
		vuint8_t Reserved_0: 	1;
		vuint8_t RSTAT: 	2;		//Receive buffer STATus
	}B;

}CAN_FD_RCRL_tag;

typedef union
{
	vuint8_t	R;			// Warning Limits Registe
	struct
	{
		vuint8_t AFWL: 				4;		//receive buffer Almost Full Warning Limit
		vuint8_t EWL: 				4;		//Programmable Error Warning Limit = (EWL+1)*8.
	}B;

}CAN_FD_LIMIT_tag;

typedef union
{
	vuint8_t	R;			//Error and Arbitration Lost Capture Register
	struct
	{
		vuint8_t KOER: 			3;		//Kind Of ERror (Error code)
		vuint8_t ALC: 			5;		//Arbitration Lost Capture (bit position in the frame where the arbitration has been lost)
	}B;

}CAN_FD_EALCAP_tag;

typedef union
{
	vuint8_t	R;			// TTCAN: Trigger Configuration TRIG_CFG_0
	struct
	{
		vuint8_t : 			2;
		vuint8_t TTPRP: 		6;		//Transmit Trigger TB slot Pointer
	}B;

}CAN_FD_TRIG_CFG_0_tag;

typedef union
{
	vuint8_t	R;			// TTCAN: Trigger Configuration TRIG_CFG_1
	struct
	{
		vuint8_t TEW:			4;		//Transmit Enable Window
		vuint8_t : 			1;
		vuint8_t TTYPE: 		3;		//Trigger Type
	}B;

}CAN_FD_TRIG_CFG_1_tag;

typedef union
{
	vuint8_t	R;			// TTCAN: TB Slot Pointer TBSLOT
	struct
	{
		vuint8_t TBE:			1;		//set TB slot to ?¡ㅭpty?¡À
		vuint8_t TBF:			1;		//set TB slot to ?¡ㆩlled?¡À
		vuint8_t TBPTR: 		6;		//Pointer to a TB frame slot.
	}B;

}CAN_FD_TBSLOT_tag;

typedef union
{
	vuint8_t	R;			// TTCAN: Time Trigger Configuration
	struct
	{
		vuint8_t :				5;
		vuint8_t T_PRESC:		2;		//TTCAN Timer PRESCaler
		vuint8_t TTEN: 		1;			//Time Trigger Enable
	}B;

}CAN_FD_TTCFG_tag;

typedef union
{
	vuint8_t	R;			//  SCFG: Safety Configuration
	struct
	{
		vuint8_t :				4;
		vuint8_t FSTIM:			3;		//Fault Stimulation
		vuint8_t XMREN: 		1;		//DMR / TMR enable
	}B;

}CAN_FD_SCFG_tag;

typedef union
{
	vuint8_t	R;			//  Memory Status
	struct
	{
		vuint8_t MPEN:			1;		//Memory Protection Enable
		vuint8_t :				2;
		vuint8_t HELOC: 		2;		//Host side memory error location
		vuint8_t TXB:			1;		//Transmission Block
		vuint8_t TXS:			1;		//Transmission Stop
		vuint8_t ACFA:			1;		//Acceptance Filter Accept
	}B;

}CAN_FD_MEM_STA_tag;

typedef union
{
	vuint8_t	R;			//  Memory Error Stimulation 0
	struct
	{
		vuint8_t MEAEE:			1;		//Memory Error: Address Error Enable
		vuint8_t ME1EE:			1;		//Memory Error: 1st Error Enable
		vuint8_t MEBP1: 		6;		//Memory Error: Bit Position 1
	}B;

}CAN_FD_MEM_ES_0_tag;

typedef union
{
	vuint8_t	R;			//  Memory Error Stimulation 1
	struct
	{
		vuint8_t :				1;
		vuint8_t ME2EE:			1;		//Memory Error: 2nd Error Enable
		vuint8_t MEBP2: 		6;		//Memory Error: Bit Position 2
	}B;

}CAN_FD_MEM_ES_1_tag;

typedef union
{
	vuint8_t	R;			//  Memory Error Stimulation 2
	struct
	{
		vuint8_t MENEC:			4;		//Memory Error: No Error Counter
		vuint8_t MEEEC:			4;		//Memory Error: Error Enable Counter
	}B;

}CAN_FD_MEM_ES_2_tag;

typedef union
{
	vuint8_t	R;			//  Memory Error Stimulation 3
	struct
	{
		vuint8_t :				5;
		vuint8_t MES:			1;		//Memory Error Side
		vuint8_t MEL:			2;		//Memory Error Location
	}B;

}CAN_FD_MEM_ES_3_tag;

typedef union
{
	vuint8_t	R;			//  Acceptance Filter Control Register
	struct
	{
		vuint8_t :				4;
		vuint8_t ACFADR:		4;		//acceptance filter address
	}B;

}CAN_FD_ACFCTRL_tag;

typedef union
{
	vuint32_t	R;			//  Logical Link Control Frame : Format
	struct
	{
		vuint32_t DLC_0:		8;		//
		vuint32_t :				5;		//
		vuint32_t DLC_1:		3;
		vuint32_t :				2;		//
		vuint32_t SEC:			1;		//
		vuint32_t RMF:			1;		//
		vuint32_t XLF:			1;		//
		vuint32_t BRS:			1;		//
		vuint32_t FDF:			1;		//
		vuint32_t IDE:			1;		//
		vuint32_t :				3;		//
		vuint32_t LBF:			1;		//
		vuint32_t ESI:			1;		//
		vuint32_t KOER:			3;		//
	}B;

}CAN_FD_LLC_FRAME_FMT_tag;

typedef union
{
	vuint32_t	R;			//  Logical Link Control Frame : TYPE
	struct
	{
		vuint32_t SDT:			8;		//
		vuint32_t VCID:			8;		//
		vuint32_t Reserved:		8;		//
		vuint32_t HANDLE:		8;		//
	}B;

}CAN_FD_LLC_FRAME_TYPE_tag;

typedef union
{
	vuint8_t	R;			//  Stream Configuration
	struct
	{
		vuint8_t :				3;		//
		vuint8_t TSTRCFG:		2;		//Transmit stream configuration
		vuint8_t TSTREN:		1;		//Transmission stream enable
		vuint8_t RSTREN:		1;		//Reception stream enable
		vuint8_t RBUFEN:		1;		//Reception buffer enable
	}B;

}CAN_FD_STR_CFG_tag;

typedef union
{
	vuint32_t	R;			//  tx buffer
	struct
	{
		vuint32_t TxByte_0:		8;
		vuint32_t TxByte_1:		8;
		vuint32_t TxByte_2:		8;
		vuint32_t TxByte_3:		8;
	}B;
}CAN_FD_TBUF_tag;

typedef union
{
	vuint32_t	R;			//  rx buffer
	struct
	{
		vuint32_t RxByte_0:		8;
		vuint32_t RxByte_1:		8;
		vuint32_t RxByte_2:		8;
		vuint32_t RxByte_3:		8;
	}B;
}CAN_FD_RBUF_tag;

typedef union
{
	vuint32_t	R;			//  tx buffer
	struct
	{
		vuint32_t ID_Byte_0:		8;
		vuint32_t ID_Byte_1:		8;
		vuint32_t ID_Byte_2:		8;
		vuint32_t ID_Byte_3:		8;
	}B;
}CAN_FD_ACF_ID_tag;

typedef struct CANFD_tag
{
	vuint8_t VER_0;				//(0x00)Read Only; Version of CAN-CTRL. VER_0 the minor version.
	vuint8_t VER_1;				//(0x01)Read Only; Version of CAN-CTRL. VER_1 holds the major version
	CAN_FD_NODECFG_tag NODECFG;		//(0x02)CAN Node Configuration Register NODECFG
	CAN_FD_TSCFG_tag TSCFG;			//(0x03)CiA 603 Time-Stamping Configuration TSCFG
	vuint8_t AC_SEG_1_L;			//(0x04)Synchronization jump width (BIT7-0)
	vuint8_t AC_SEG_1_H;			//(0x05)Synchronization jump width (BIT8)
	vuint8_t AC_SEG_2;				//(0x06)Bit time segment 2 (BIT6:0)
	vuint8_t AC_SJW;				//(0x07)Synchronization jump width (BIT6:0)
	CAN_FD_FD_TIME_tag FD_TIME;		//(0x08)CAN FD Bit Timing
	CAN_FD_XL_TIME_tag XL_TIME;		//(0x0C)CAN XL Bit Timing
	vuint8_t PRESC;					//(0x10)The prescaler divides the system clock to synthesize the time quanta TQ (BIT4:0)
	vuint8_t FD_SSPOFF;				//(0x11)Secondary sample point offset for CAN FD frame
	vuint8_t XL_SSPOFF;				//(0x12)Secondary sample point offset for CAN XL frame
	CAN_FD_RELIM_tag RELIM;			//(0x13)Retransmission and Re-Arbitration limit
	CAN_FD_INTF_tag INTF;			//(0x14)Interrupt flag regISTER
	CAN_FD_INTE_tag INTE;			//(0x18)Interrupt Enable regISTER
	CAN_FD_TSTAT_1_tag TSTAT_1;		//(0x1C)Transmit Status Registers TSTAT_1
	CAN_FD_TSTAT_2_tag TSTAT_2;		//(0x1E)Transmit Status Registers TSTAT_2
	vuint32_t TTS_L;			//(0x20)Transmission Time Stamp Lower part(Bit 31:0)
	vuint32_t TTS_H;			//(0x24)Transmission Time Stamp Higher part(Bit 63:32)
	CAN_FD_CFG_STAT_tag CFG_STAT;	//(0x28)Configuration and Status Register
	CAN_FD_TCMD_tag TCMD;			//(0x29)Transmission Command Register
	CAN_FD_TCRL_tag TCRL;			//(0x2A)Transmission Control Register
	CAN_FD_RCRL_tag RCRL;			//(0x2B)Receive Control Register
	CAN_FD_LIMIT_tag LIMIT;			//(0x2C)Warning Limits Register
	CAN_FD_EALCAP_tag EALCAP;		//(0x2D)Error and Arbitration Lost Capture Register
	vuint8_t RECNT;				//(0x2E)Receive Error CouNT
	vuint8_t TECNT;				//(0x2F)Transmission Error CouNT
	vuint8_t REF_MSG_0;				//(0x30)REFerence message 0
	vuint8_t REF_MSG_1;				//(0x31)REFerence message 1
	vuint8_t REF_MSG_2;				//(0x32)REFerence message 2
	vuint8_t REF_MSG_3;				//(0x30)REFerence message 3
	CAN_FD_TRIG_CFG_0_tag TRIG_CFG_0;//(0x34)TTCAN: Trigger Configuration TRIG_CFG_0
	CAN_FD_TRIG_CFG_1_tag TRIG_CFG_1;//(0x35)TTCAN: Trigger Configuration TRIG_CFG_1
	CAN_FD_TBSLOT_tag TBSLOT;		//(0x36)TTCAN: TB Slot Pointer TBSLOT
	CAN_FD_TTCFG_tag TTCFG;			//(0x37)TTCAN: Time Trigger Configuration
	vuint8_t TT_TRIG_0;				//(0x38)TTCAN: Trigger Time(BIT 7:0)
	vuint8_t TT_TRIG_1;				//(0x39)TTCAN: Trigger Time(BIT 15:8)
	vuint8_t TT_WTRIG_0;			//(0x3A)TTCAN: Watch Trigger Time(BIT 7:0)
	vuint8_t TT_WTRIG_1;			//(0x3A)TTCAN: Watch Trigger Time(BIT 15:8)
	CAN_FD_SCFG_tag SCFG;			//(0x3C)SCFG: Safety Configuration
	vuint8_t Reserved_0[2];
	CAN_FD_MEM_STA_tag MEM_STA;		//(0x3F)Memory Status
	CAN_FD_MEM_ES_0_tag MEM_ES_0;	//(0x40)Memory Error Stimulation 0
	CAN_FD_MEM_ES_1_tag MEM_ES_1;	//(0x41)Memory Error Stimulation 1
	CAN_FD_MEM_ES_2_tag MEM_ES_2;	//(0x42)Memory Error Stimulation 2
	CAN_FD_MEM_ES_3_tag MEM_ES_3;	//(0x43)Memory Error Stimulation 3
	CAN_FD_ACFCTRL_tag ACFCTRL;		//(0x44)Acceptance Filter Control Register
	vuint8_t Reserved_1;
	vuint8_t ACFEN_0;				//(0x46)Acceptance Filter Enable (AE_7:AE_0)
	vuint8_t ACFEN_1;				//(0x47)Acceptance Filter Enable (AE_15:AE_8)
	vuint32_t ACFC_ID;			//(0x48)acceptance code:Logical Link Control Frame : Identifier
	CAN_FD_LLC_FRAME_FMT_tag ACFC_FMT;//(0x4C)acceptance code:Logical Link Control Frame : Format
	CAN_FD_LLC_FRAME_TYPE_tag ACFC_TYPE;//(0x50)acceptance code:Logical Link Control Frame : Type
	vuint32_t ACFC_AF;				//(0x54)acceptance code:Logical Link Control Frame : Acceptance field
	vuint32_t ACFM_ID;			//(0x58)acceptance mask:Logical Link Control Frame : Identifier
	CAN_FD_LLC_FRAME_FMT_tag ACFM_FMT;//(0x5C)acceptance mask:Logical Link Control Frame : Format
	CAN_FD_LLC_FRAME_TYPE_tag ACFM_TYPE;//(0x60)acceptance mask:Logical Link Control Frame : Type
	vuint32_t ACFM_AF;				//(0x64)acceptance mask:Logical Link Control Frame : Acceptance field
	vuint8_t Reserved_2[8];
	CAN_FD_RBUF_tag RBUF[519];			//(0x70 - 0x88B)Receive Buffer Registers
	vuint32_t Reserved_3;
	CAN_FD_TBUF_tag TBUF[515];			//(0x890 - 0x109F)Transmit Buffer Registers
	vuint32_t Reserved_4[3];
	vuint8_t PWMO;					//(0x10AC)
	vuint8_t PWMS;					//(0x10AD)
	vuint8_t PWML;					//(0x10AE)
	vuint8_t Reserved_5;
	CAN_FD_STR_CFG_tag STR_CFG;		//(0x10B0)
	vuint8_t Reserved_6[3];
	vuint32_t LLCFORMAT;			//(0x10B4)
	vuint8_t LLCPBYTES_0;			//(0x10B8)
	vuint8_t LLCPBYTES_1;			//(0x10B9)
	vuint8_t LLCAOT_0;				//(0x10BA)
	vuint8_t LLCAOT_1;				//(0x10BB)
} CAN_FD_TypeDef;

#define CANFD_INTE_SWIE_MASK                      0x2000u
#define CANFD_INTE_SWIE_SHIFT                     13u
#define CANFD_INTE_SWIE_WIDTH                     1u
#define CANFD_INTE_SWIE(x)                        (((uint32)(((uint32)(x)) \
													<<CANFD_INTE_SWIE_SHIFT)) \
													&CANFD_INTE_SWIE_MASK)

#define CANFD_INTE_MDWIE_MASK                      0x20000u
#define CANFD_INTE_MDWIE_SHIFT                     17u
#define CANFD_INTE_MDWIE_WIDTH                     1u
#define CANFD_INTE_MDWIE(x)                        (((uint32)(((uint32)(x)) \
													<<CANFD_INTE_MDWIE_SHIFT)) \
													&CANFD_INTE_MDWIE_MASK)

#define CANFD_INTE_EPIE_MASK                      0x200000u
#define CANFD_INTE_EPIE_SHIFT                     21u
#define CANFD_INTE_EPIE_WIDTH                     1u
#define CANFD_INTE_EPIE(x)                        (((uint32)(((uint32)(x)) \
													<<CANFD_INTE_EPIE_SHIFT)) \
													&CANFD_INTE_EPIE_MASK)

#define CANFD_INTE_ALIE_MASK                      0x400000u
#define CANFD_INTE_ALIE_SHIFT                     22u
#define CANFD_INTE_ALIE_WIDTH                     1u
#define CANFD_INTE_ALIE(x)                        (((uint32)(((uint32)(x)) \
													<<CANFD_INTE_ALIE_SHIFT)) \
													&CANFD_INTE_ALIE_MASK)

#define CANFD_INTE_BEIE_MASK                      0x800000u
#define CANFD_INTE_BEIE_SHIFT                     23u
#define CANFD_INTE_BEIE_WIDTH                     1u
#define CANFD_INTE_BEIE(x)                        (((uint32)(((uint32)(x)) \
													<<CANFD_INTE_BEIE_SHIFT)) \
													&CANFD_INTE_BEIE_MASK)

#define CANFD_INTE_RIE_MASK                       0x1000000u
#define CANFD_INTE_RIE_SHIFT                      24u
#define CANFD_INTE_RIE_WIDTH                      1u
#define CANFD_INTE_RIE(x)                         (((uint32)(((uint32)(x)) \
													<<CANFD_INTE_RIE_SHIFT)) \
													&CANFD_INTE_RIE_MASK)

#define CANFD_INTE_ROIE_MASK                      0x2000000u
#define CANFD_INTE_ROIE_SHIFT                     25u
#define CANFD_INTE_ROIE_WIDTH                     1u
#define CANFD_INTE_ROIE(x)                        (((uint32)(((uint32)(x)) \
													<<CANFD_INTE_ROIE_SHIFT)) \
													&CANFD_INTE_ROIE_MASK)

#define CANFD_INTE_RFIE_MASK                      0x4000000u
#define CANFD_INTE_RFIE_SHIFT                     26u
#define CANFD_INTE_RFIE_WIDTH                     1u
#define CANFD_INTE_RFIE(x)                        (((uint32)(((uint32)(x)) \
													<<CANFD_INTE_RFIE_SHIFT)) \
													&CANFD_INTE_RFIE_MASK)

#define CANFD_INTE_RAFIE_MASK                     0x8000000u
#define CANFD_INTE_RAFIE_SHIFT                    27u
#define CANFD_INTE_RAFIE_WIDTH                    1u
#define CANFD_INTE_RAFIE(x)                       (((uint32)(((uint32)(x)) \
													<<CANFD_INTE_RAFIE_SHIFT)) \
													&CANFD_INTE_RAFIE_MASK)

#define CANFD_INTE_TPIE_MASK                      0x10000000u
#define CANFD_INTE_TPIE_SHIFT                     28u
#define CANFD_INTE_TPIE_WIDTH                     1u
#define CANFD_INTE_TPIE(x)                        (((uint32)(((uint32)(x)) \
													<<CANFD_INTE_TPIE_SHIFT)) \
													&CANFD_INTE_TPIE_MASK)

#define CANFD_INTE_TSIE_MASK                      0x20000000u
#define CANFD_INTE_TSIE_SHIFT                     29u
#define CANFD_INTE_TSIE_WIDTH                     1u
#define CANFD_INTE_TSIE(x)                        (((uint32)(((uint32)(x)) \
													<<CANFD_INTE_TSIE_SHIFT)) \
													&CANFD_INTE_TSIE_MASK)

#define CANFD_INTE_EIE_MASK                       0x40000000u
#define CANFD_INTE_EIE_SHIFT                      30u
#define CANFD_INTE_EIE_WIDTH                      1u
#define CANFD_INTE_EIE(x)                         (((uint32)(((uint32)(x)) \
													<<CANFD_INTE_EIE_SHIFT)) \
													&CANFD_INTE_EIE_MASK)

#define CANFD_FD_ID_DESCRIPTOR               (0x40000000U)
#define CANFD_MSG_ID_EXT_MASK                (0x80000000U)
#define CANFD_TX_BUFFER_EXT_ID_MASK          0x1FFFFFFFU
#define CANFD_TX_BUFFER_STD_ID_SHIFT         18U
#define CANFD_TX_BUFFER_STD_ID_MASK          0x1FFC0000U

#endif  /* CANFD_REG_H_ */

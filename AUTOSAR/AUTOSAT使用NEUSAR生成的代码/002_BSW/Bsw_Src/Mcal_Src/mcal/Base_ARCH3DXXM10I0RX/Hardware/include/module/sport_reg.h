/* PRQA S 0602 EOF */
#ifndef __SPORT_REG_H__
#define __SPORT_REG_H__

//#include "chip_reg.h"
#include "typedefs.h"

typedef volatile struct
{
    union
    {
        vuint32_t R;
        struct
        {
        	vuint32_t DXSPRI :2; /*31:30  Data Transfer Buffer Status(Primary)*/
        	vuint32_t DERRPRI :1; /*29 Data Error Status (Primary)*/
        	vuint32_t DXSSEC :2; /*28:27 Data Transfer Buffer Status(Secondary)*/
        	vuint32_t DERRSEC :1; /*26 Data Error Status (Secondary)*/
        	vuint32_t SPTRAN :1; /*25 Serial Port Transfer Direction*/
        	vuint32_t SPENSEC :1; /*24 Serial Port Enable (Secondary)*/
        	vuint32_t :2; /*23:22 reversed*/
        	vuint32_t GCLKEN :1; /*21 Gated Clock Enable.*/
        	vuint32_t TFIEN :1; /*20 Transmit Finish Interrupt Enable*/
        	vuint32_t FSED :1; /*19 Frame Sync Edge Detect*/
        	vuint32_t RJUST :1; /*18 Right-Justified Operation Mode*/
        	vuint32_t LAFS :1; /*17 Late Frame Sync*/
        	vuint32_t LFS :1; /*16 Active-Low Frame Sync*/
        	vuint32_t DIFS :1; /*15 Data-Independent Frame Sync*/
        	vuint32_t IFS :1; /*14 Internal Frame Sync*/
        	vuint32_t FSR :1; /*13 Frame Sync Required*/
        	vuint32_t CKRE :1; /*12 Clock Rising Edge*/
        	vuint32_t OPMODE :1; /*11 Operation mode*/
        	vuint32_t ICLK :1; /*10 Internal Clock*/
        	vuint32_t PACK :1; /*9  Packing Enable*/
        	vuint32_t SLEN :5; /*8:4 Serial Word Length*/
        	vuint32_t LSBF :1; /*3 Least-Significant Bit First.*/
        	vuint32_t DTYPE :2; /*2:1 Data Type*/
            vuint32_t SPENPRI :1; /*0 Serial Port Enable (Primary)*/
        } B;
    } CTL;

    union
    {
        vuint32_t R;
        struct
        {
        	vuint32_t FSDIV :16; /*31:16  Frame Sync Divisor*/
            vuint32_t CLKDIV :16; /*15:0   Clock Divisor*/
        } B;
    } DIV;

    union
    {
        vuint32_t R;
        struct
        {
        	vuint32_t :6;
        	vuint32_t WOFFSET :10; /*25:16  Window Offset.*/
        	vuint32_t :1;
        	vuint32_t WSIZE :7; /*14:8  Window Size.*/
        	vuint32_t MFD :4; /*7:4   Multichannel Frame Delay.*/
        	vuint32_t :1;
        	vuint32_t WCPDE :1; /*2  Multichannel Packing DMA Enable*/
        	vuint32_t :1;
            vuint32_t MCE :1; /*0  Multichannel enable*/
        } B;
    } MCTL;

    union
    {
        vuint32_t R;
        struct
        {
            vuint32_t VALUE :32; /*31:0 Channel Enable 0-31.*/
        } B;
    } CS0;

    union
    {
        vuint32_t R;
        struct
        {
            vuint32_t VALUE :32; /*31:0 Channel Enable 32-63.*/
        } B;
    } CS1;

    union
    {
        vuint32_t R;
        struct
        {
            vuint32_t VALUE :32; /*31:0 Channel Enable 64-95.*/
        } B;
    } CS2;

    union
    {
        vuint32_t R;
        struct
        {
            vuint32_t VALUE :32; /*31:0 Channel Enable 96-127.*/
        } B;
    } CS3;
    
    vuint8_t reversed1[0x4];

    union
    {
        vuint32_t R;
        struct
        {
        	vuint32_t :25;
        	vuint32_t FSERRSTAT :1; /*6 Frame Sync Error Status*/
        	vuint32_t DERRSSTAT :1; /*5 Data Error Secondary Status*/
        	vuint32_t DERRPSTAT :1; /*4 Data Error Primary Status*/
        	vuint32_t :1;
        	vuint32_t FSERRMSK :1; /*2 Frame Sync Error (Interrupt) Mask*/
        	vuint32_t DERRSMSK :1; /*1 Data Error Secondary (Interrupt) Mask*/
            vuint32_t DERRPMSK :1; /*0 Data Error Primary (Interrupt) Mask*/
        } B;
    } ERR;

    union
    {
        vuint32_t R;
        struct
        {
            vuint32_t :22;
            vuint32_t CURCHAN :10; /*9:0 Current Channel*/
        } B;
    } MSTAT;

    union
    {
       vuint32_t R;
       struct
       {
    	   vuint32_t :30;
    	   vuint32_t CKMUXSEL :1; /*1 Clock Multiplexer Select*/
           vuint32_t FSMUXSEL :1; /*0 Frame Sync Multiplexer Select*/
       } B;
    } CTL2;

    vuint8_t reversed2[0x14];

    union
    {
        vuint32_t R;
        struct
        {
            vuint32_t VALUE :32; /*31:0 Transmit Buffer (Primary)*/
        } B;
    } TXPRI;

    union
    {
        vuint32_t R;
        struct
        {
            vuint32_t VALUE :32; /*31:0 Receive  Buffer (Primary)*/
        } B;
    } RXPRI;

    union
    {
        vuint32_t R;
        struct
        {
            vuint32_t VALUE :32; /*31:0 Transmit Buffer (Secondary)*/
        } B;
    } TXSEC;

    union
    {
        vuint32_t R;
        struct
        {
            vuint32_t VALUE :32; /*31:0 Receive  Buffer (Secondary)*/
        } B;
    } RXSEC;

    union
	{
		vuint32_t R;
		struct
		{
			vuint32_t :29;
			vuint32_t TXDMAIE :1; /*2 Tx DMA TransferDone Interrupt Enable*/
			vuint32_t RXFSIE :1;  /*1 Rx FS Interrupt Enable*/
		    vuint32_t AB_LOOP :1; /*0 half A/B loop*/
		} B;
	}CTL3;

    union
	{
		vuint32_t R;
		struct
		{
			vuint32_t :30;			  /* bit 2:31, Reserved */
			vuint32_t RXFSST :1; /*31:0 Receive  Buffer (Secondary)*/
			vuint32_t TXDMAST :1; /*31:0 Receive  Buffer (Secondary)*/
		} B;
	}INT_ST;
}SPORT_REG;

#define BITM_SPORT_CTL_A_SPENPRI      ((uint32_t)0x00000001UL)
#define BITM_SPORT_CTL_A_SPENSEC      ((uint32_t)0x01000000UL)

#define SPORT0_BASE_ADDR                               (uint32_t)(0xFBEE0000u)
#define SPORT1_BASE_ADDR                               (uint32_t)(0xFBEE4000u)

#define SPORT_0A_BASE_ADDR           (SPORT0_BASE_ADDR)
#define SPORT_0B_BASE_ADDR           (SPORT0_BASE_ADDR + 0x80UL)

#define SPORT_1A_BASE_ADDR           (SPORT1_BASE_ADDR)
#define SPORT_1B_BASE_ADDR           (SPORT1_BASE_ADDR + 0x80UL)

#endif

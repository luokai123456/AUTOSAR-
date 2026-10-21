/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : ETPU
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    sPwm_LLDrivers.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of sPwm MCAL driver.
*
*   @addtogroup sPwm
*   @{
*/
/* PRQA S 0380 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "sPwm_LLDrivers.h"		  	/* eTPU SPWM API defines */
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "eTPU_LLDrivers.h"

#define SPWM_LLD_WRA_C_VENDOR_ID                     176
#define SPWM_LLD_WRA_C_AR_REL_MAJOR_VER              4
#define SPWM_LLD_WRA_C_AR_REL_MINOR_VER              4
#define SPWM_LLD_WRA_C_AR_REL_REV_VER                0
#define SPWM_LLD_WRA_C_SW_MAJOR_VER                  3
#define SPWM_LLD_WRA_C_SW_MINOR_VER                  0
#define SPWM_LLD_WRA_C_SW_PATCH_VER                  0

#if (ETPU_VENDOR_ID_OUTPUT != SPWM_LLD_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : SPWM_LLD_WRA_C_VENDOR_ID "
#endif
#if (ETPU_AR_REL_MAJOR_VER_OUTPUT != SPWM_LLD_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SPWM_LLD_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (ETPU_AR_REL_MINOR_VER_OUTPUT != SPWM_LLD_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SPWM_LLD_WRA_C_AR_REL_MINOR_VER "
#endif
#if (ETPU_AR_REL_REVISION_VER_OUTPUT != SPWM_LLD_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SPWM_LLD_WRA_C_AR_REL_REV_VER "
#endif
#if (ETPU_SW_MAJOR_VERSION_OUTPUT != SPWM_LLD_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SPWM_LLD_WRA_C_SW_MAJOR_VER "
#endif
#if (ETPU_SW_MINOR_VERSION_OUTPUT != SPWM_LLD_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SPWM_LLD_WRA_C_SW_MINOR_VER "
#endif
#if (ETPU_SW_PATCH_VERSION_OUTPUT != SPWM_LLD_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SPWM_LLD_WRA_C_SW_PATCH_VER "
#endif

#if ((SPWM_MASTER_NUM != 0U)&&(SPWM_MODULE_ENABLE !=STD_OFF))

/******************************************************************************
    FUNCTION     : ETPU_LLD_SPWM_Init_Master
    PURPOSE      : To initialize an eTPU channel to generate a master SPWM output.
    INPUTS NOTES : This function has the following parameters:
                channel - This is the channel number.
                            0-31 for ETPU_A and 64-95 for ETPU_B.
                    freq - This is the frequency of the SPWM.  The 
                            range of this parameter is determined by the complete
                            system but normally would be between 1Hz-100kHz.
                    duty - This is the initial duty cycle of the PWM. This is a
                            uint16_t with a range of 0-10000. To represent 0-100%
                            with 0.01% resolution.
                timebase - This is the timer to use as a reference for the SPWM
                            signal. This parameter should be assigned to a value
                            of: ETPU_TCR1 or ETPU_TCR2.
            timebase_freq - This is the frequency of the selected timebase.
                            The range of this is the same as the range of the 
                            timebase frequency on the device. This parameter is a 
                            uint32_t.
            reference_mode - This determines whether the function will run in 
                            immediate mode or relative to a timing reference 
                            stored in PRAM.
                            This parameter should be assigned a value of:
                            ETPU_SPWM_REF_IN_PRAM,
                            ETPU_SPWM_IMMEDIATE
            *reference_ptr - This is the address of the reference when 
                            reference_mode is ETPU_SPWM_REF_IN_PRAM.
    INT_DMA_on_falling_edge - Determines if an inteerupt/DMA request is generated 
                            on active edge or not. This parameter should be 
                            assigned a value of:
                            ETPU_SPWM_NO_FALL_EDGE_INT_DMA,
                            ETPU_SPWM_FALLING_EDGE_INT_DMA
                    link1 - This is a packed 32 bit parameter with 4 8 bit 
                            channel numbers in it.
                    link2 - This is a packed 32 bit parameter with 4 8 bit 
                            channel numbers in it.
    RETURNS NOTES: Error code if channel could not be initialized. Error code that
                can be returned are: ETPU_ERROR_MALLOC ,ETPU_ERROR_FREQ.
    WARNING      : *This function does not configure the pin only the eTPU. In a
                system a pin may need to be configured to select the eTPU.
******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(sint32, SPWM_CODE) ETPU_LLD_SPWM_Init_Master \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) freq, \
    VAR(uint16, AUTOMATIC) duty, \
    VAR(uint8, AUTOMATIC) timebase, \
    VAR(uint32, AUTOMATIC) timebase_freq, \
    VAR(uint8, AUTOMATIC) reference_mode, \
    P2VAR(uint32, AUTOMATIC, SPWM_APPL_DATA) reference_ptr, \
    VAR(uint8, AUTOMATIC) INT_DMA_on_falling_edge, \
    VAR(uint32, AUTOMATIC) link1, \
    VAR(uint32, AUTOMATIC) link2 \
)
{
    P2VAR(uint32, AUTOMATIC, SPWM_APPL_DATA) pba; /* parameter base address for channel */
    VAR(uint32, AUTOMATIC) chan_period;
    P2VAR(uint8, AUTOMATIC, SPWM_APPL_DATA) pba8;
    P2VAR(uint8, AUTOMATIC, SPWM_APPL_DATA) reference_ptr8;

	/* Disable channel to assign function safely */
    eTPUInstance[etpuGroup]. eTPU->CHAN[channel].CR.B.CPR = 0U;

    if (eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA == 0U )
    {
    	/* get parameter RAM for
    	number of parameters passed from eTPU C code */
    	pba = ETPU_LLD_Malloc_32(etpuGroup, 0x30);
			
        if (pba == NULL_PTR)
    	{
    		return (ETPU_ERROR_MALLOC);
    	}
    }
    else /*set pba to what is in the CR register*/
    {
    	pba = ((uint32*)(eTPUInstance[etpuGroup].data_ram_start + \
            ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3)));
    }
    pba8 = (uint8 *) pba;
    


    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA = \
        (((uint32)pba - (uint8)eTPUInstance[etpuGroup].data_ram_start)>>3);

    /* Determine frequency of output waveform */
	chan_period = timebase_freq / freq;

	if ((chan_period == 0U) || (chan_period > 0x007FFFFFU ))
    {
        return( ETPU_ERROR_FREQ);
    }
		
	/* write parameters to data memory */
    *(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_ext + \
    	((uint32)(eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3)) + \
        ((uint32)ETPU_SPWM_PERIOD_OFFSET - (uint8)1)) = chan_period;


	if (duty < 10000U)
	{
		*(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_ext + \
		((uint32)(eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3)) + \
        ((uint32)ETPU_SPWM_ACTIVE_OFFSET - (uint8)1)) = (chan_period * duty) / (uint32)10000;
	}
	else /*if duty > 100% make duty 100% */
	{
        *(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_ext + \
        ((uint32)(eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3)) + \
        ((uint32)ETPU_SPWM_ACTIVE_OFFSET - (uint8)1)) = chan_period;
	}
	
	*(pba + ((uint32)(ETPU_SPWM_LINK1_OFFSET)>>2)) = link1;
	*(pba + ((uint32)(ETPU_SPWM_LINK2_OFFSET)>>2)) = link2;
	
	/* populate the reference */
	/* write REF_MODE to master channel */
	/* this is used by the rum_master API to determine how to calculate the */
	/* first edge time */
	if ( reference_mode == (uint8)ETPU_SPWM_IMMEDIATE)
	{
	    *(pba8 + ETPU_SPWM_REF_MODE) = 0;
			/* generate pointer to the reference for immediate mode*/
			/* The reference is populated by the fs_etpu_rum_spwm API with the */
			/* then current value of the selected TCR */
	    reference_ptr8 = pba8 + ETPU_SPWM_REFERENCE;
	    reference_ptr =  (uint32 *)reference_ptr8 - \
        (uint32) ((uint32 *) ((eTPUInstance[etpuGroup].data_ram_start) / (uint32)4));;
    }
    else /* reference mode; ptr is in PRAM */
    {
        *(pba8 + ETPU_SPWM_REF_MODE) = 1;
        /* reference_ptr has been passed in ; no need to calculate */
    }

    /* populate the pointer on the eTPU */
    *(pba + ((uint32)(ETPU_SPWM_REF_PTR_OFFSET)>>2)) = (uint32) reference_ptr;
		
	/* write FM (function mode) bits */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.R = ((uint32)timebase << 1) + (uint32)INT_DMA_on_falling_edge;

    /* write channel configuration register */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.R = \
        (uint32)((uint32)ETPU_SPWM_TABLE_SELECT << 24) + \
        (uint32)((uint32)ETPU_SPWM_FUNCTION_NUMBER << 16) + \
        (((uint32)pba - eTPUInstance[etpuGroup].data_ram_start)>>3);



	return(0);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/******************************************************************************
    FUNCTION     : ETPU_LLD_SPWM_Run_Master
    PURPOSE      : To set the SPWM master channel running.
    INPUTS NOTES : This function has the following parameters:
                channel - This is the channel number.
                            0-31 for ETPU_A and 64-95 for ETPU_B.
                priority - This is the priority to assign to the channel.
                            This parameter should be assigned a value of:
                            ETPU_PRIORITY_HIGH, ETPU_PRIORITY_MIDDLE or
                            ETPU_PRIORITY_LOW.
    RETURNS NOTES: none
******************************************************************************/   
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"                   
FUNC(void, SPWM_CODE) ETPU_LLD_SPWM_Run_Master \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint8, AUTOMATIC) priority
)
{
    P2VAR(uint32, AUTOMATIC, SPWM_APPL_DATA) pba; 
    P2VAR(uint8, AUTOMATIC, SPWM_APPL_DATA) pba8;
    P2VAR(uint32, AUTOMATIC, SPWM_APPL_DATA) host_ref_ptr;
    VAR(uint32, AUTOMATIC) time_now;

	pba = ((uint32*)(eTPUInstance[etpuGroup].data_ram_start + ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3)));
    pba8 = (uint8 *) pba;

	if ( *(pba8 + ETPU_SPWM_REF_MODE) == (uint8)0 ) /* immediate mode */
	{
        host_ref_ptr =  (pba + ((uint32)(ETPU_SPWM_REFERENCE ) / (uint32)4)) ; 
		if ( eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.B.FM1 == (uint32)ETPU_TCR1)
		{
			if (channel < 32U) /*engine A channel */
			{
				time_now = eTPUInstance[etpuGroup].eTPU->TB1R_A.R;
			}
			else /*engine B channel */
			{
				time_now = eTPUInstance[etpuGroup].eTPU->TB1R_B.R;
			}
		
		}
		else /*tcr2 timebase */
		{
			if (channel < 32U) /*engine A channel */
			{
				time_now = eTPUInstance[etpuGroup].eTPU->TB2R_A.R;
			}
			else /*engine B channel */
			{
				time_now = eTPUInstance[etpuGroup].eTPU->TB2R_B.R;
			}
		}
	    *host_ref_ptr = time_now;
	}
	else /* reference is in PRAM */
	{
		/* do nothing; ref address already populated */
	}	
    

	/* write hsr to start channel running */
	eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = ETPU_SPWM_INIT_MASTER;

    /* write channel configuration register ; priority bit */

	eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPR = (priority);


}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/******************************************************************************
    FUNCTION     : ETPU_LLD_SPWM_Init_Slave
    PURPOSE      : To initialize an eTPU channel to generate a slave SPWM output.
    INPUTS NOTES : This function has the following parameters:
                    channel - This is the channel number.
                            0-31 for ETPU_A and 64-95 for ETPU_B.
                    priority - This is the priority to assign to the channel.
                            This parameter should be assigned a value of:
                            ETPU_PRIORITY_HIGH, ETPU_PRIORITY_MIDDLE or
                            ETPU_PRIORITY_LOW.
                        freq - This is the frequency of the SPWM.  The 
                            range of this parameter is determined by the 
                            complete system but normally would be between 
                            1Hz-100kHz.
                        duty - This is the initial duty cycle of the PWM. This is a
                            uint16_t with a range of 0-10000. To represent 
                            0-100% with 0.01% resolution.                  
                    slave_delay - This is the delay in micro-seconds of the rising 
                            edge of the slave relative to the rising edge of the 
                            master or reference.
                    timebase - This is the timer to use as a reference for the SPWM
                            signal. This parameter should be assigned to a value
                            of: ETPU_TCR1 or ETPU_TCR2.
            timebase_freq - This is the frequency of the selected timebase.
                            The range of this is the same as the range of the 
                            timebase frequency on the device. This parameter is
                            a uint32_t.
        *MasterFrameEdgePtr - The address of the variable on the eTPU which stores 
                            the time of the next rising edge.
                            
            NOTES: In this case the freq varialble is used only to gerarate the
                TCR counts pertaining to duty and delay. Freq is not used to 
                generate a chan_period variabke as in the init_master function.
    RETURNS NOTES: Error code if channel could not be initialized. Error code that
                can be returned are: ETPU_ERROR_MALLOC ,ETPU_ERROR_FREQ.
    WARNING      : This function does not configure the pin only the eTPU. In a
                system a pin may need to be configured to select the eTPU.
******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(sint32, SPWM_CODE) ETPU_LLD_SPWM_Init_Slave \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint8, AUTOMATIC) priority, \
    VAR(uint32, AUTOMATIC) freq, \
    VAR(uint16, AUTOMATIC) duty, \
    VAR(uint32, AUTOMATIC) slave_delay, \
    VAR(uint8, AUTOMATIC) timebase, \
    VAR(uint32, AUTOMATIC) timebase_freq, \
    P2CONST(uint32, AUTOMATIC, SPWM_APPL_DATA) MasterFrameEdgePtr
)
{
    P2VAR(uint32, AUTOMATIC, SPWM_APPL_DATA) pba; /* parameter base address for channel */
    VAR(uint32, AUTOMATIC) chan_period;
    VAR(uint32, AUTOMATIC) delay_in_ticks;
    VAR(uint64, AUTOMATIC) x;

    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPR = 0U;

    if (eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA == 0U)
    {
        /* get parameter RAM
        number of parameters passed from eTPU C code */
        pba = ETPU_LLD_Malloc_32(etpuGroup, ETPU_SPWM_NUM_PARMS);

    	if (pba == NULL_PTR)
    	{
    		return (ETPU_ERROR_MALLOC);
    	}
    }
    else /*set pba to what is in the CR register*/
    {
    	pba=((uint32*)(eTPUInstance[etpuGroup].data_ram_start + \
            ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3)));
    }

    /* Determine frequency of output waveform */
	chan_period = timebase_freq / freq;

	if ((chan_period == 0U) || (chan_period > 0x007FFFFFU))
	{
		return( ETPU_ERROR_FREQ);
	}
		


	eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA = \
		(((uint32)pba - (uint8)eTPUInstance[etpuGroup].data_ram_start)>>3);

	/* write parameters to data memory */
    *(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_ext + \
        ((uint32)(eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3U)) + \
        ((uint32)ETPU_SPWM_PERIOD_OFFSET - (uint8)1)) = chan_period;

	/* write parameters to data memory */
	if (duty < 10000U)
	{
		*(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_ext + \
			((uint32)(eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3U)) + \
            ((uint32)ETPU_SPWM_ACTIVE_OFFSET - (uint8)1)) = (chan_period * duty) / (uint32)10000;
	}
	else /*if duty > 100% make duty 100% */
	{
		*(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_ext + \
			((uint32)(eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3U)) + \
            ((uint32)ETPU_SPWM_ACTIVE_OFFSET - (uint8)1)) = chan_period;
	}

	x = (uint64)slave_delay * timebase_freq;
	
	delay_in_ticks = (uint32)(x / (uint32)1000000);
    /*need to very this can't overflow */
	
	*(pba + ((uint32)(ETPU_SPWM_DELAY_OFFSET )>>2))  = 
			delay_in_ticks  ;

    *(pba + ((uint32)(ETPU_SPWM_MASTERRISINGEDGEPTR )>>2)) =
    (uint32 )MasterFrameEdgePtr;	
  
    /* write hsr to start channel running */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = ETPU_SPWM_INIT_SLAVE;
 
			
	/* write FM (function mode) bits */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.R = ((uint32)timebase << 1U) + (uint32)0;
	/* slave cannot generate interrupts */
	
	 /* write channel configuration register */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.R = ((uint32)priority << 28U) + \
        (uint32)((uint32)ETPU_SPWM_TABLE_SELECT << 24) + (uint32)((uint32)ETPU_SPWM_FUNCTION_NUMBER << 16) + \
        (((uint32)pba - eTPUInstance[etpuGroup].data_ram_start)>>3U);



	return(0);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/******************************************************************************
    FUNCTION     : ETPU_LLD_SPWM_Duty
    PURPOSE      : To update a channel duty cycle using a 16 bit integer value. The
                integer value is the percentage *100, so 20% would be 2000.
                Supports both master and slave channels.
    INPUTS NOTES : This function has 2 parameters:
                channel - This is the channel number.
                            0-31 for ETPU_A and 64-95 for ETPU_B.
                    duty - This is the duty cycle of the PWM. This is a
                            uint16 with a range of 0-10000. To represent 0-100%
                            with 0.01% resolution.
    RETURNS NOTES: none
    WARNING      :
******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void ETPU_LLD_SPWM_Duty( uint8_t etpuGroup,uint8_t channel,
                        uint16_t duty)
{
    P2VAR(uint32, AUTOMATIC, SPWM_APPL_DATA) pba;
    VAR(uint32, AUTOMATIC) chan_period;

	pba = ((uint32*)((uint8*)eTPUInstance[etpuGroup].data_ram_start + \
        (eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3)));

	chan_period = *(pba + (ETPU_SPWM_PERIOD_OFFSET - 1));
	chan_period = (uint32)(chan_period & (uint32)0xFFFFFF);

	if (duty < 10000U)
	{
		*(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_ext + \
            (uint32)(eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3) + \
            (uint32)(ETPU_SPWM_ACTIVE_OFFSET - 1)) = (chan_period* duty) / 10000U;
	}
	else /*if duty > 100% make duty 100% */
	{
	    *(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_ext + \
            (uint32)(eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3) + \
            (uint32)(ETPU_SPWM_ACTIVE_OFFSET - 1)) = chan_period;
	}
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/******************************************************************************
    FUNCTION     : ETPU_LLD_SPWM_Update_Master
    PURPOSE      : To update a PWM output's frequency and dutycycle
    INPUTS NOTES : This function has the following parameters:
                channel - This is the channel number.
                            0-31 for ETPU_A and 64-95 for ETPU_B.
                    freq - This is the frequency of the SPWM. The range of
                            this parameter is determine by the complete system but
                            normally would be between 1Hz-100kHz.
                    duty - This is the initial duty cycle of the PWM. This is a
                            uint16_t with a range of 0-10000. To represent 0-100%
                            with 0.01% resolution.
            timebase_freq - This is the frequency of the selected timebase.
                            The range of this is the same as the range of the 
                            timebase frequency on the device. This parameter is a 
                            uint32_t.
    RETURNS NOTES: Error code if frequency is out of range: ETPU_ERROR_FREQ
******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(sint32, SPWM_CODE) ETPU_LLD_SPWM_Update_Master \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) freq, \
    VAR(uint16, AUTOMATIC) duty, \
    VAR(uint32, AUTOMATIC) timebase_freq \
)
{
    P2VAR(uint32, AUTOMATIC, SPWM_APPL_DATA) pba;
    VAR(uint32, AUTOMATIC) chan_period;

	pba = ((uint32*)(eTPUInstance[etpuGroup].data_ram_start + \
        ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3)));

    /* Determine frequency of output waveform */
	chan_period = timebase_freq / freq;

	if ((chan_period == 0U) || (chan_period > 0x007FFFFFU ))
	{
    	return( ETPU_ERROR_FREQ);
	}
  
	/* write parameters to data memory */
	*(pba + ((uint32)(ETPU_SPWM_PERIOD_OFFSET )>>2)) = chan_period;
	*(pba + ((uint32)(ETPU_SPWM_ACTIVE_OFFSET )>>2))  = (chan_period * duty) / (uint32)10000;

    return 0;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/******************************************************************************
    FUNCTION     : ETPU_LLD_SPWM_Get_Freq_Master
    PURPOSE      : To determine the actual frequency by the SPWM channel.
    INPUTS NOTES : This function has 2 parameters:
                channel - This is the channel number.
                            0-31 for ETPU_A and 64-95 for ETPU_B.
        timebase_freq -   This is the frequency of the selected timebase.
                            The range of this is the same as the range of the 
                            timebase frequency on the device. This parameter 
                            is a uint32_t.
    RETURNS NOTES: The actual frequency as an integer.
    WARNING      :
******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, SPWM_CODE) ETPU_LLD_SPWM_Get_Freq_Master \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) timebase_freq \
)
{
    P2VAR(uint32, AUTOMATIC, SPWM_APPL_DATA) pba;
    VAR(uint32, AUTOMATIC) chan_period;

	pba = ((uint32*)(eTPUInstance[etpuGroup].data_ram_start + \
        ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3)));

	chan_period = *(pba + ((uint32)(ETPU_SPWM_PERIOD_OFFSET )>>2));
	chan_period = chan_period & (uint32)0xFFFFFF;

	return( timebase_freq / chan_period );
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#ifdef __cplusplus
}
#endif
#endif
#endif

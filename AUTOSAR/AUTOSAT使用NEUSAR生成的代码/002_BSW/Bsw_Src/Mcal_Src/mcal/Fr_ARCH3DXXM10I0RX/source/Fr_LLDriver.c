/* PRQA S 4397, 0491, 2897, 1860, 3432, 4393 EOF */
/* PRQA S 4391, 1891, 2907, 4532, 3393, 1851 EOF */
/* PRQA S 2844, 1861, 4542, 4434, 0488, 2985 EOF */
/* PRQA S 0311, 0316, 2982, 0316, 0311, 3398 EOF */
/* PRQA S 0492, 1853, 2986, 4342, 4558, 3401 EOF */
/* PRQA S 1850, 2016, 3395, 1852, 3397, 2812 EOF */
/* PRQA S 1881, 2053, 4533, 1840, 1841, 1291 EOF */
/* PRQA S 4115, 4522, 4461, 1330, 2013, 2755 EOF */
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
 *   @file    Fr_LLDriver.c
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
 *   @details Autosar layer of Fr MCAL driver.
 *
 *   @addtogroup Fr
 *   @{
 */

/* PRQA S 0380 EOF*/
#ifdef __cplusplus
extern "C"{
#endif
#include "derivative.h"
#ifdef RESOURCE_SUPPORT_FLEXRAY
#include "Fr_LLDriver.h"
#include "Fr_HAL_Wrapper.h"
#include "SchM_Fr.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FR_LLD_VENDOR_ID_C                        176
#define FR_LLD_AR_RELEASE_MAJOR_VERSION_C         4
#define FR_LLD_AR_RELEASE_MINOR_VERSION_C         4
/* @violates @ref FR_FR_H_REF_2 */
#define FR_LLD_AR_RELEASE_REVISION_VERSION_C      0
#define FR_LLD_SW_MAJOR_VERSION_C                 3
#define FR_LLD_SW_MINOR_VERSION_C                 0
#define FR_LLD_SW_PATCH_VERSION_C                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr_LLDriver.h header file are of the same vendor */
#if(FR_LLD_VENDOR_ID_C != FR_LLD_H_VENDOR_ID)
    #error "Fr_LLDriver.c and Fr_LLDriver.h have different Vendor IDs"
#endif
/* Check if current file and Fr_LLDriver.h header file are of the same Autosar version */
#if((FR_LLD_AR_RELEASE_MAJOR_VERSION_C    != FR_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
    (FR_LLD_AR_RELEASE_MINOR_VERSION_C    != FR_LLD_H_AR_RELEASE_MINOR_VERSION) || \
    (FR_LLD_AR_RELEASE_REVISION_VERSION_C != FR_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_LLDriver.c and Fr_LLDriver.h are different"
#endif
/* Check if current file and Fr_LLDriver.h header file are of the same software version */
#if((FR_LLD_SW_MAJOR_VERSION_C != FR_LLD_H_SW_MAJOR_VERSION) || \
    (FR_LLD_SW_MINOR_VERSION_C != FR_LLD_H_SW_MINOR_VERSION) || \
    (FR_LLD_SW_PATCH_VERSION_C != FR_LLD_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_LLDriver.c and Fr_LLDriver.h are different"
#endif

/* Check if current file and Fr_HAL_Wrapper header file are of the same vendor */
#if(FR_LLD_VENDOR_ID_C != FR_HAL_WAR_H_VENDOR_ID)
    #error "Fr_LLDriver.c and Fr_HAL_Wrapper.h have different Vendor IDs"
#endif
/* Check if current file and Fr_HAL_Wrapper header file are of the same Autosar version */
#if((FR_LLD_AR_RELEASE_MAJOR_VERSION_C    != FR_HAL_WAR_H_AR_RELEASE_MAJOR_VERSION) || \
    (FR_LLD_AR_RELEASE_MINOR_VERSION_C    != FR_HAL_WAR_H_AR_RELEASE_MINOR_VERSION) || \
    (FR_LLD_AR_RELEASE_REVISION_VERSION_C != FR_HAL_WAR_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_LLDriver.c and Fr_HAL_Wrapper.h are different"
#endif
/* Check if current file and Fr_HAL_Wrapper header file are of the same software version */
#if((FR_LLD_SW_MAJOR_VERSION_C != FR_HAL_WAR_H_SW_MAJOR_VERSION) || \
    (FR_LLD_SW_MINOR_VERSION_C != FR_HAL_WAR_H_SW_MINOR_VERSION) || \
    (FR_LLD_SW_PATCH_VERSION_C != FR_HAL_WAR_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_LLDriver.c and Fr_HAL_Wrapper.h are different"
#endif


#if (FR_RXSTRINGENTCHECK == STD_OFF)
    #define FLEXRAY_STRINGENT_MASK_A  0x0080U
    #define FLEXRAY_STRINGENT_MASK_B  0x8000U
#else
    #define FLEXRAY_STRINGENT_MASK_A  0x008EU   /*Check SEA, CEA and BVA for Error*/
    #define FLEXRAY_STRINGENT_MASK_B  0x8E00U   /*Check SEA, CEA and BVA for Error*/
#endif
/******************************************************************************
* Global variables
******************************************************************************/
/* This internal array contains message buffer configuration information (except shadow message buffers and FIFO storage).*/
#ifdef FR_NUMBER_TXRX_MB
/* The FR_NUMBER_TXRX_MB parameter is defined in the flexray_cfg.h file 
   - memory consumption optimization is applied */
    /* The LLD Driver allocates following array with limited number of elements */
    /* - the number is given by host in the flexray_cfg.h file */
#define FR_START_SEC_VAR_SHARED_NO_INIT
#include "Fr_MemMap.h"
    VAR(Fr_MB_information_internal_type, FR_VAR) Fr_MB_information_internal[FR_NUMBER_TXRX_MB + 1U];
#define FR_STOP_SEC_VAR_SHARED_NO_INIT
#include "Fr_MemMap.h"
#else
/* The FR_NUMBER_TXRX_MB parameter is not defined in the flexray_cfg.h file 
   - no memory consumption optimization is applied */
    /* The UNIFIED Driver allocates following array with the maximal number of elements (for maximum number of possible MB) */
#define FR_START_SEC_VAR_SHARED_NO_INIT
#include "Fr_MemMap.h"
    VAR(Fr_MB_information_internal_type, FR_VAR) Fr_MB_information_internal[FR_MAX_NUMBER_TXRX_MB];
#define FR_STOP_SEC_VAR_SHARED_NO_INIT
#include "Fr_MemMap.h"
#endif

/******************************************************************************
* Constants
******************************************************************************/
/* Internal pointers to configuration data, they are initialized in the Fr_set_configuration function */
#define FR_START_SEC_VAR_NO_INIT
#include "Fr_MemMap.h"
static P2CONST(Fr_HW_config_type, AUTOMATIC, *) Fr_HW_config_ptr;
#define FR_STOP_SEC_VAR_NO_INIT
#include "Fr_MemMap.h"
/******************************************************************************
* Local variables
******************************************************************************/

/* This variable is used for base address of the FlexRay module */
#define FR_START_SEC_VAR_NO_INIT
#include "Fr_MemMap.h"
volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_CC_reg_ptr;
#define FR_STOP_SEC_VAR_NO_INIT
#include "Fr_MemMap.h"

#define FR_START_SEC_VAR_NO_INIT
#include "Fr_MemMap.h"
static VAR(Fr_FIFO_info_type, FR_VAR) Fr_FIFO_info;
#define FR_STOP_SEC_VAR_NO_INIT
#include "Fr_MemMap.h"

/* This internal structure contains names of callback functions */
#define FR_START_SEC_VAR_NO_INIT
#include "Fr_MemMap.h"
static VAR(Fr_callback_functions_type, FR_VAR) Fr_callback_functions;
#define FR_STOP_SEC_VAR_NO_INIT
#include "Fr_MemMap.h"


#if (FR_RECONFIG_LPDU_SUPPORT == STD_ON)
#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
static FUNC(Std_ReturnType, FR_CODE) Fr_Driver_PrepareTxBuffer
(
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg,
    VAR(uint16, AUTOMATIC) Mbindex,
    VAR(uint16, AUTOMATIC) TempMBNum
);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
static FUNC(Std_ReturnType, FR_CODE) Fr_Driver_PrepareRxBuffer
(
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg,
    VAR(uint16, AUTOMATIC) Mbindex,
    VAR(uint16, AUTOMATIC) TempMBNum
);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif
#endif


/******************************************************************************
* Global functions
******************************************************************************/

/************************************************************************************
* Function name:    Fr_LLD_Init
* Description:      This API call stores the base address of the FlexRay 
*                   module and available memory, configures the channels,
*                   resets FlexRay CC and forces the CC into FR_POCSTATE_CONFIG state
*
* Function arguments:
*                   Fr_HW_config_temp_ptr Reference to the hardware configuration 
*                                       parameters for the FlexRay driver
*                   Fr_low_level_config_temp_ptr Reference to the low level 
*                                       configuration parameters
*
* Return value:
*                   StatusSuss         API call has been successful
*                   StatusErro    Error occured during transition 
*                                       into FR_POCSTATE_CONFIG
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Init(P2CONST(Fr_HW_config_type, AUTOMATIC, FR_APPL_CONST) Fr_HW_config_temp_ptr, P2CONST(Fr_low_level_config_type, AUTOMATIC, FR_APPL_CONST) Fr_low_level_config_temp_ptr)
{
    /* Temporary variable for bit operations */
    volatile VAR(uint16, AUTOMATIC) temp_value; 
    VAR(Fr_LLDriver_StatusType, AUTOMATIC) retVal = StatusErro;
    /* Initialize the base address */
    Fr_CC_reg_ptr = (volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA)) Fr_HW_config_temp_ptr->CC_base_address;

    /* Initialize the FlexRay Memory Start address */

    Fr_CC_reg_ptr[FrSYMBADHR] = (VAR(uint16, AUTOMATIC))(Fr_HW_config_temp_ptr->CC_FlexRay_memory_base_address >> 16U); /* polyspace RTE:IDP */
    Fr_CC_reg_ptr[FrSYMBADLR] = (VAR(uint16, AUTOMATIC))(Fr_HW_config_temp_ptr->CC_FlexRay_memory_base_address & 0xFFFFU); /* polyspace RTE:IDP */

    
    /* Configuration of the SYMATOR register */
     /* Stored only if the value is not equal to 0 */
    if(Fr_HW_config_temp_ptr->timeout != 0U)    
    {
        /* Store the value of the TIMEOUT bit field in the SYMATOR register */
        Fr_CC_reg_ptr[FrSYMATOR] = ((VAR(uint16, AUTOMATIC))Fr_HW_config_temp_ptr->timeout & 0x1FU); /* polyspace RTE:IDP */
    }

    
    /* Configuration of the MCR register */
    /* Clear temporary variable */
    temp_value = 0x0000U;        
    if(Fr_low_level_config_temp_ptr->P_CHANNELS == FR_CHANNEL_AB)
    {
       temp_value = FrMCR_CHA | FrMCR_CHB;
    } 
    else if(Fr_low_level_config_temp_ptr->P_CHANNELS == FR_CHANNEL_B)
    {
        /* Single chip mode */
        temp_value = FrMCR_SCM;    
        /* Connected to FR channel B */
        temp_value |= FrMCR_CHB;   
    }
    else if(Fr_low_level_config_temp_ptr->P_CHANNELS == FR_CHANNEL_A)
    {
        /* Single chip mode */
        temp_value = FrMCR_SCM;   
        /* Connected to FR channel A */  
        temp_value |= FrMCR_CHA;    
    }
    else
    {
        temp_value = 0x0000U;
    }
    
    if(Fr_HW_config_temp_ptr->synchronization_filtering_enable == TRUE)
    {
        /* Synchronization frame filter enabled */
        temp_value |= FrMCR_SFFE;   
    }
    
    /* Not used for the MFR4300 and MFR4310 */
    if(Fr_HW_config_temp_ptr->clock_source == FR_INTERNAL_SYSTEM_BUS_CLOCK)
    {
        /* Use internal system bus clock as PE clock source */
        temp_value |= FrMCR_CLKSEL;     
    }
    
    /* PRESCALE or BITRATE bit field settings in the MCR register - a little different meaning of these bits */

    temp_value |=  (VAR(uint16, AUTOMATIC))((((VAR(uint16, AUTOMATIC))Fr_HW_config_temp_ptr->prescaler_value & 0x07U) << 1U));

    /* Write to MCR reg. before enabling the FR module */
    Fr_CC_reg_ptr[FrMCR] = temp_value; /* polyspace RTE:IDP */
    
    temp_value |= FrMCR_MEN;
    /* Enable FlexRay module */
    Fr_CC_reg_ptr[FrMCR] = temp_value;  


    if(Fr_LLD_Enter_Configuration_Mode() == StatusErro)
    {
        retVal = StatusErro;
    }
    else
    {
        retVal = StatusSuss;
    }
    /* API call has been successful */
    return retVal;                                      
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Set_Configuration
* Description:      This API call initializes the FlexRay CC. The following action 
*                   are performed by this function:
*                   - initialization of the data structures of the FlexRay driver
*                   - configuration of FlexRay configuration parameters (e.g. cluster configuration)
*                   - disabling all FlexRay CC interrupts
*
* Function arguments:
*                   Fr_HW_config_temp_ptr   Reference to the hardware configuration 
*                                       parameters for the FlexRay driver
*                   Fr_low_level_config_temp_ptr Reference to the low level 
*                                       configuration parameters
*
* Return value:
*                   None
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_LLD_Set_Configuration(P2CONST(Fr_HW_config_type, AUTOMATIC, FR_APPL_CONST) Fr_HW_config_temp_ptr, P2CONST(Fr_low_level_config_type, AUTOMATIC, FR_APPL_CONST) Fr_low_level_config_temp_ptr)
{
    /* Temporary variables intended for bit operations */
    volatile VAR(uint16, AUTOMATIC) temp_value_1, temp_value_3;   
    /* Temporary variable intended for bit operations */  
    volatile VAR(uint32, AUTOMATIC) temp_value_2;                   
    static P2CONST(Fr_low_level_config_type, AUTOMATIC, FR_APPL_CONST) Fr_low_level_config_ptr;
    /* Temporary counter */
    VAR(uint8, AUTOMATIC) Fr_p;                                     
    
    /* Initialize the base address for the second time - in case that this function is called more than once  */
    /* with different configuration */
    Fr_CC_reg_ptr = (volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA)) Fr_HW_config_temp_ptr->CC_base_address;

    /* Initialization of the internal pointers, which will be used by driver later on */
    Fr_HW_config_ptr = Fr_HW_config_temp_ptr;  /* PRQA S 2919 */
    Fr_low_level_config_ptr = Fr_low_level_config_temp_ptr;
    
    /* Initialization of the internal MB information structure */
    #ifdef FR_NUMBER_TXRX_MB
    /* The FR_NUMBER_TXRX_MB parameter is defined in the Fr_UNIFIED_cfg.h file 
    - memory consumption optimization is applied */
    /* Configure limited number of items */
        for(Fr_p = 0U; Fr_p < (FR_NUMBER_TXRX_MB + 1U); Fr_p++) 
        {
            /* Set callback function to NULL */
            Fr_MB_information_internal[Fr_p].Fr_MB_function_ptr = NULL_PTR; 
            /* Clear slot number item */
            Fr_MB_information_internal[Fr_p].slot_number = 0U;          
            /* Clear transmission mode item */
            Fr_MB_information_internal[Fr_p].transmission_mode = FR_SINGLE_TRANSMIT_BUFFER;     
            /* Clear transmission type item */
            Fr_MB_information_internal[Fr_p].transmission_type = FR_EVENT_TRANSMISSION_MODE;   
            Fr_MB_information_internal[Fr_p].Mb_channel_type = FR_CHANNEL_A;  
        }
    #else
    /* The FR_NUMBER_TXRX_MB parameter is not defined in the Fr_UNIFIED_cfg.h file 
       - no memory consumption optimization is applied */
       /* Configure maximum number of items */
        for(Fr_p = 0U; Fr_p < FR_MAX_NUMBER_TXRX_MB; Fr_p++) 
        {
            /* Set callback function to NULL */
            Fr_MB_information_internal[Fr_p].Fr_MB_function_ptr = NULL_PTR; 
            Fr_MB_information_internal[Fr_p].slot_number = 0U;           /* Clear slot number item */
            /* Clear transmission mode item */
            Fr_MB_information_internal[Fr_p].transmission_mode = FR_SINGLE_TRANSMIT_BUFFER;     
            /* Clear transmission type item */
            Fr_MB_information_internal[Fr_p].transmission_type = FR_EVENT_TRANSMISSION_MODE;    
            Fr_MB_information_internal[Fr_p].Mb_channel_type = FR_CHANNEL_A;
        }
    #endif

    
    /* PCR0 */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_low_level_config_ptr->GD_ACTION_POINT_OFFSET - 1U);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 10U) | Fr_low_level_config_ptr->GD_STATIC_SLOT);
    Fr_CC_reg_ptr[FrPCR0] = temp_value_1; /* polyspace RTE:IDP */

    /* PCR1  */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 14U) | (Fr_low_level_config_ptr->G_MACRO_PER_CYCLE - Fr_low_level_config_ptr->GD_STATIC_SLOT));
    Fr_CC_reg_ptr[FrPCR1] = temp_value_1; /* polyspace RTE:IDP */
    
    /* PCR2  */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_MINISLOT - (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_MINI_SLOT_ACTION_POINT_OFFSET - 1U);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 10U) | Fr_low_level_config_ptr->G_NUMBER_OF_STATIC_SLOTS);
    Fr_CC_reg_ptr[FrPCR2] = temp_value_1; /* polyspace RTE:IDP */

    /* PCR3  */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_WAKEUP_SYMBOL_RX_LOW;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 5U) | (VAR(uint16, AUTOMATIC))(Fr_low_level_config_ptr->GD_MINI_SLOT_ACTION_POINT_OFFSET - 1U));
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 5U) | Fr_low_level_config_ptr->G_COLD_START_ATTEMPTS);
    Fr_CC_reg_ptr[FrPCR3] = temp_value_1; /* polyspace RTE:IDP */

    /* PCR4  */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_low_level_config_ptr->GD_CAS_RX_LOW_MAX - 1U);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 9U) | Fr_low_level_config_ptr->GD_WAKEUP_SYMBOL_RX_WINDOW);
    Fr_CC_reg_ptr[FrPCR4] = temp_value_1; /* polyspace RTE:IDP */

    /* PCR5  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->GD_TSS_TRANSMITTER;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 6U) | (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_WAKEUP_SYMBOL_TX_LOW);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 6U) | (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_WAKEUP_SYMBOL_RX_IDLE);
    Fr_CC_reg_ptr[FrPCR5] = temp_value_1; /* polyspace RTE:IDP */

    /* PCR6  */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_SYMBOL_WINDOW - (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_ACTION_POINT_OFFSET - 1U);  /* PRQA S 2892,2902 */
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 7U) | (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->P_MACRO_INITIAL_OFFSET_A);
    Fr_CC_reg_ptr[FrPCR6] = temp_value_1; /* polyspace RTE:IDP */

    /* PCR7  */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->P_DECODING_CORRECTION + (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->P_DELAY_COMPENSATION_CHB + 2U);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 7U) | (VAR(uint16, AUTOMATIC))(Fr_low_level_config_ptr->P_MICRO_PER_MACRO_NOM / 2U));
    Fr_CC_reg_ptr[FrPCR7] = temp_value_1; /* polyspace RTE:IDP */

    /* PCR8  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->G_MAX_WITHOUT_CLOCK_CORRECTION_FATAL;
    temp_value_1 = (VAR(uint16, AUTOMATIC))(((temp_value_1 << 4U) | (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->G_MAX_WITHOUT_CLOCK_CORRECTION_PASSIVE));
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 8U) | (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_WAKEUP_SYMBOL_TX_IDLE);
    Fr_CC_reg_ptr[FrPCR8] = temp_value_1; /* polyspace RTE:IDP */
    
    /* PCR9  */
    temp_value_1 = 0x0000U;
    if(Fr_low_level_config_ptr->G_NUMBER_OF_MINISLOTS != 0U)
    {
      temp_value_1 = TRUE;
    }
    else                                                  
    {
      temp_value_1 = FALSE;
    }

    if(Fr_low_level_config_ptr->GD_SYMBOL_WINDOW != 0U)
    {
      temp_value_3 = TRUE;
    } 
    else
    {
      temp_value_3 = FALSE; 
    }
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 1U) | temp_value_3);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 14U) | Fr_low_level_config_ptr->P_OFFSET_CORRECTION_OUT);
    Fr_CC_reg_ptr[FrPCR9] = temp_value_1; /* polyspace RTE:IDP */

    /* PCR10  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->P_SINGLE_SLOT_ENABLED;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 1U) | (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->P_WAKEUP_CHANNEL);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 14U) | Fr_low_level_config_ptr->G_MACRO_PER_CYCLE);
    Fr_CC_reg_ptr[FrPCR10] = temp_value_1; /* polyspace RTE:IDP */
      
    /* PCR11  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->P_KEY_SLOT_USED_FOR_STARTUP;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 1U) | Fr_low_level_config_ptr->P_KEY_SLOT_USED_FOR_SYNC);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 14U) | Fr_low_level_config_ptr->G_OFFSET_CORRECTION_START);
    Fr_CC_reg_ptr[FrPCR11] = temp_value_1; /* polyspace RTE:IDP */

    /* PCR12  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->P_ALLOW_PASSIVE_TO_ACTIVE;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 11U) | Fr_low_level_config_ptr->P_KEY_SLOT_HEADER_CRC);
    Fr_CC_reg_ptr[FrPCR12] = temp_value_1; /* polyspace RTE:IDP */
    
    /* PCR13  */
    temp_value_1 = 0x0000U;
    if(Fr_low_level_config_ptr->GD_ACTION_POINT_OFFSET >= Fr_low_level_config_ptr->GD_MINI_SLOT_ACTION_POINT_OFFSET)
    {
      temp_value_1 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_ACTION_POINT_OFFSET - 1U);
    }
    else
    {
      temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_low_level_config_ptr->GD_MINI_SLOT_ACTION_POINT_OFFSET - 1U);
    }  
    temp_value_1 = (VAR(uint16, AUTOMATIC))(temp_value_1 << 10U);
    temp_value_1 |= (VAR(uint16, AUTOMATIC))(Fr_low_level_config_ptr->GD_STATIC_SLOT -  Fr_low_level_config_ptr->GD_ACTION_POINT_OFFSET - 1U);
    Fr_CC_reg_ptr[FrPCR13] = temp_value_1; /* polyspace RTE:IDP */
    
    /* PCR14  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_2 = (Fr_low_level_config_ptr->PD_LISTEN_TIMEOUT - 1U) & 0x001F0000U;
    temp_value_1 = Fr_low_level_config_ptr->P_RATE_CORRECTION_OUT;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 5U) | ((VAR(uint16, AUTOMATIC))(temp_value_2 >> 16U)));
    Fr_CC_reg_ptr[FrPCR14] = temp_value_1; /* polyspace RTE:IDP */
    
    /* PCR15  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_2 = (Fr_low_level_config_ptr->PD_LISTEN_TIMEOUT - 1U) & 0x0000FFFFU;
    temp_value_1 = (VAR(uint16, AUTOMATIC))temp_value_2;
    Fr_CC_reg_ptr[FrPCR15] = temp_value_1; /* polyspace RTE:IDP */
    
    /* PCR16  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_1 = Fr_low_level_config_ptr->P_MACRO_INITIAL_OFFSET_B;
    temp_value_2 = ((Fr_low_level_config_ptr->G_LISTEN_NOISE * Fr_low_level_config_ptr->PD_LISTEN_TIMEOUT) - 1U) & 0x01FF0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 9U ) | ((VAR(uint16, AUTOMATIC))(temp_value_2 >> 16U)));
    Fr_CC_reg_ptr[FrPCR16] = temp_value_1; /* polyspace RTE:IDP */
    
    /* PCR17  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_2 = ((Fr_low_level_config_ptr->G_LISTEN_NOISE * Fr_low_level_config_ptr->PD_LISTEN_TIMEOUT) - 1U) & 0x0000FFFFU;
    temp_value_1 = (VAR(uint16, AUTOMATIC))temp_value_2;
    Fr_CC_reg_ptr[FrPCR17] = temp_value_1; /* polyspace RTE:IDP */
    
    /* PCR18  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->P_WAKEUP_PATTERN;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 10U) | Fr_low_level_config_ptr->P_KEY_SLOT_ID);
    Fr_CC_reg_ptr[FrPCR18] = temp_value_1; /* polyspace RTE:IDP */
    
    /* PCR19  */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->P_DECODING_CORRECTION + (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->P_DELAY_COMPENSATION_CHA + 2U);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 7U) | Fr_low_level_config_ptr->G_PAYLOAD_LENGTH_STATIC);
    Fr_CC_reg_ptr[FrPCR19] = temp_value_1; /* polyspace RTE:IDP */

    /* PCR20  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->P_MICRO_INITIAL_OFFSET_B;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 8U) | Fr_low_level_config_ptr->P_MICRO_INITIAL_OFFSET_A);
    Fr_CC_reg_ptr[FrPCR20] = temp_value_1; /* polyspace RTE:IDP */
        
    /* PCR21  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->P_EXTERN_RATE_CORRECTION;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 13U) | (Fr_low_level_config_ptr->G_NUMBER_OF_MINISLOTS - Fr_low_level_config_ptr->P_LATEST_TX));
    Fr_CC_reg_ptr[FrPCR21] = temp_value_1; /* polyspace RTE:IDP */
    
    /* PCR22  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_1 =(VAR(uint16, AUTOMATIC))( Fr_low_level_config_ptr->PD_ACCEPTED_STARTUP_RANGE - Fr_low_level_config_ptr->P_DELAY_COMPENSATION_CHA);
    temp_value_2 = (Fr_low_level_config_ptr->P_MICRO_PER_CYCLE) & 0x000F0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 4U) | ((VAR(uint16, AUTOMATIC))(temp_value_2 >> 16U)));
    Fr_CC_reg_ptr[FrPCR22] = temp_value_1; /* polyspace RTE:IDP */
    
    /* PCR23  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_2 = Fr_low_level_config_ptr->P_MICRO_PER_CYCLE & 0x0000FFFFU;
    temp_value_1 = (VAR(uint16, AUTOMATIC))temp_value_2;
    Fr_CC_reg_ptr[FrPCR23] = temp_value_1; /* polyspace RTE:IDP */
    
    /* PCR24  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_1 = Fr_low_level_config_ptr->P_CLUSTER_DRIFT_DAMPING;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 7U) | Fr_low_level_config_ptr->P_PAYLOAD_LENGTH_DYN_MAX);
    temp_value_2 = (Fr_low_level_config_ptr->P_MICRO_PER_CYCLE - Fr_low_level_config_ptr->PD_MAX_DRIFT) & 0x000F0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 4U) | ((VAR(uint16, AUTOMATIC))(temp_value_2 >> 16U)));
    Fr_CC_reg_ptr[FrPCR24] = temp_value_1; /* polyspace RTE:IDP */

    /* PCR25  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_2 = (Fr_low_level_config_ptr->P_MICRO_PER_CYCLE - Fr_low_level_config_ptr->PD_MAX_DRIFT) & 0x0000FFFFU;
    temp_value_1 = (VAR(uint16, AUTOMATIC))temp_value_2;
    Fr_CC_reg_ptr[FrPCR25] = temp_value_1; /* polyspace RTE:IDP */

    /* PCR26  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_1 = Fr_low_level_config_ptr->P_ALLOW_HALT_DUE_TO_CLOCK;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 11U));
    temp_value_1 |= (VAR(uint16, AUTOMATIC))((Fr_low_level_config_ptr->PD_ACCEPTED_STARTUP_RANGE - Fr_low_level_config_ptr->P_DELAY_COMPENSATION_CHB));
    temp_value_2 = (Fr_low_level_config_ptr->P_MICRO_PER_CYCLE + Fr_low_level_config_ptr->PD_MAX_DRIFT) & 0x000F0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 4U) | ((VAR(uint16, AUTOMATIC))(temp_value_2 >> 16U)));
    Fr_CC_reg_ptr[FrPCR26] = temp_value_1; /* polyspace RTE:IDP */
    
    /* PCR27  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_2 = (Fr_low_level_config_ptr->P_MICRO_PER_CYCLE + Fr_low_level_config_ptr->PD_MAX_DRIFT) & 0x0000FFFFU;
    temp_value_1 = (VAR(uint16, AUTOMATIC))temp_value_2;
    Fr_CC_reg_ptr[FrPCR27] = temp_value_1; /* polyspace RTE:IDP */
    
    /* PCR28  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->GD_DYNAMIC_SLOT_IDLE_PHASE;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 14U));
    temp_value_1 |= (VAR(uint16, AUTOMATIC))((Fr_low_level_config_ptr->G_MACRO_PER_CYCLE - Fr_low_level_config_ptr->G_OFFSET_CORRECTION_START));
    Fr_CC_reg_ptr[FrPCR28] = temp_value_1; /* polyspace RTE:IDP */
    
    /* PCR29  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->P_EXTERN_OFFSET_CORRECTION;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 13U) | (VAR(uint16, AUTOMATIC))(Fr_low_level_config_ptr->G_NUMBER_OF_MINISLOTS - 1U)); /* PRQA S 2912 */
    Fr_CC_reg_ptr[FrPCR29] = temp_value_1; /* polyspace RTE:IDP */

    /* PCR30  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->G_SYNC_NODE_MAX;
    Fr_CC_reg_ptr[FrPCR30] = temp_value_1; /* polyspace RTE:IDP */


    /* NMVLR */
    Fr_CC_reg_ptr[FrNMVLR] = Fr_low_level_config_ptr->G_NETWORK_MANAGEMENT_VECTOR_LENGTH; /* polyspace RTE:IDP */
    
    /* Message Buffer Data Size Register initialization */
    temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_HW_config_ptr->MB_segment_2_data_size);
    temp_value_1 = (VAR(uint16, AUTOMATIC))(temp_value_1 << 8U);
    temp_value_1 = (VAR(uint16, AUTOMATIC))(temp_value_1 | ((VAR(uint16, AUTOMATIC))(Fr_HW_config_ptr->MB_segment_1_data_size)));

    /* Message Buffer Segment Size and Utilization Register initialization */
    temp_value_3 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 - 1U);
    temp_value_3 = (VAR(uint16, AUTOMATIC))(temp_value_3 << 8U);
    temp_value_3 = (VAR(uint16, AUTOMATIC))(temp_value_3 | (((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 + (VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_util - 1U)));


    /* Message Buffer Data Size Register initialization */
    Fr_CC_reg_ptr[FrMBDSR] = temp_value_1; /* polyspace RTE:IDP */    /* MBSEG2DS, MBSEG1DS */
    
    /* Message Buffer Segment Size and Utilization Register initialization */
    Fr_CC_reg_ptr[FrMBSSUTR] = temp_value_3;  /* LAST_MB_SEG1, LAST_MB_UTIL */

    /* SFTOR */
    if(Fr_HW_config_temp_ptr->sync_frame_table_offset != 0U)     /* Stored only if the value is not equal to 0 */
    {
        /* Store the value of the SFT_OFFSET bit field in the SFTOR register */
        Fr_CC_reg_ptr[FrSFTOR] = Fr_HW_config_temp_ptr->sync_frame_table_offset; 
    }
    Fr_CC_reg_ptr[FrSFTCCSR] = (0x01);
    /* Disable all FlexRay interrupts */
    SchM_Enter_Fr_EXCLUSIVE_AREA_00();
    Fr_CC_reg_ptr[FrGIFER] = 0x0000U;
    Fr_CC_reg_ptr[FrPIER0] = 0x0000U;
    Fr_CC_reg_ptr[FrPIER1] = 0x0000U;
    SchM_Exit_Fr_EXCLUSIVE_AREA_00();
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Buffers_Init
* Description:      This API call initializes the FlexRay CC message buffers, 
*                   the receive shadow buffers and receive FIFO storages
*
* Function arguments:
*                   Fr_buffers_config_temp_ptr - Pointer to structure with message 
*                               buffers configuration data
*                   Fr_buffer_config_set_temp_ptr - Reference to the array with 
*                               information which message buffers will be used 
*                               from MB configuration structure (referenced by 
*                               Fr_buffers_config_temp_ptr pointer) 
*
* Return value:
*                   StatusSuss        API call has been successful
*                   StatusErro    The FR_NUMBER_TXRX_MB parameter is not correctly set 
*                                       in the flexray_cfg.h file
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Buffers_Init(VAR(uint8, FR_VAR) Fr_CtrlIdx,P2CONST(Fr_buffer_info_type, AUTOMATIC, FR_APPL_CONST) Fr_buffers_config_temp_ptr, P2CONST(Fr_index_selector_type, AUTOMATIC, FR_APPL_CONST) Fr_buffer_config_set_temp_ptr)
{
    /* Temporary index used for indexing of the buffer config set structure */
    volatile VAR(uint8, FR_VAR) temp_index;                
    /* The highest number of configured transmit or receive MB index -for verification */  
    volatile VAR(uint8, FR_VAR) highest_txrx_mb_number = 0U;  
    VAR(Fr_LLDriver_StatusType, FR_VAR) retVal = StatusSuss;
    /* Temporary variable used for bit operation */
    volatile VAR(uint16, FR_VAR) temp_value_1;          
    /* Temporary variable used for bit operation */     
    volatile VAR(uint16, FR_VAR) temp_value_2;        
    /* Temporary variable used for bit operation - for double buffered MB */       
    volatile VAR(uint16, FR_VAR) temp_value_3;               
    /* Item index in array referenced by Fr_buffer_config_set_temp_ptr pointer */
    volatile VAR(uint16, FR_VAR) Fr_buffer_info_set_index;   
    /* Temporary offset adress of message buffer registers */
    volatile VAR(uint16, FR_VAR) Fr_MB_registers_offset_add_temp; 
    static P2CONST(Fr_buffer_info_type, AUTOMATIC, FR_APPL_CONST) Fr_buffers_config_ptr;
    static P2CONST(uint16, AUTOMATIC, FR_APPL_CONST) Fr_buffer_config_set_ptr;
    /* Temporary pointer to receive configuration data */
    P2CONST(Fr_receive_buffer_config_type, AUTOMATIC, FR_APPL_CONST) Fr_receive_buffer_config_ptr;   
    /* Temporary pointer to transmit configuration data */
    P2CONST(Fr_transmit_buffer_config_type, AUTOMATIC, FR_APPL_CONST) Fr_transmit_buffer_config_ptr; 
    /* Temporary pointer to receive shadow  */
    P2CONST(Fr_receive_shadow_buffers_config_type, AUTOMATIC, FR_APPL_CONST) Fr_shadow_buffer_config_ptr; 
    /* Temporary pointer to receive FIFO configuration data */
    P2CONST(Fr_FIFO_config_type, AUTOMATIC, FR_APPL_CONST) Fr_FIFO_config_ptr;   
    /* Message buffer header pointer */
    volatile P2VAR(uint16, AUTOMATIC, FR_APPL_CONST) header_MB_ptr; 
    
    /* Initialization of the internal pointers, which will be used by driver later on */
    Fr_buffers_config_ptr = Fr_buffers_config_temp_ptr;
    Fr_buffer_config_set_ptr = Fr_buffer_config_set_temp_ptr;
    
    /* Initialization of the internal FIFO information structure */
    Fr_FIFO_info.FIFO_1_used = FALSE;
    Fr_FIFO_info.FIFO_1_channel = FR_CHANNEL_A;
    Fr_FIFO_info.FIFO_1_depth = 0U;
    Fr_FIFO_info.FIFO_1_entry_size = 0U;
    Fr_FIFO_info.FIFO_2_used = FALSE;
    Fr_FIFO_info.FIFO_2_channel = FR_CHANNEL_A;
    Fr_FIFO_info.FIFO_2_depth = 0U;
    Fr_FIFO_info.FIFO_2_entry_size = 0U;

    /* Initialization of the internal calback function structure - mainly used in Fr_interrupt_handler() function */
    Fr_callback_functions.Fr_module_ptr = NULL_PTR;
    Fr_callback_functions.Fr_protocol_ptr = NULL_PTR;
    Fr_callback_functions.Fr_chi_ptr = NULL_PTR;
    Fr_callback_functions.Fr_wakeup_ptr = NULL_PTR;
    Fr_callback_functions.Fr_fifo_B_ptr = NULL_PTR;
    Fr_callback_functions.Fr_fifo_A_ptr = NULL_PTR;
    Fr_callback_functions.Fr_fatal_protocol_error_ptr = NULL_PTR;
    Fr_callback_functions.Fr_internal_protocol_error_ptr = NULL_PTR;
    Fr_callback_functions.Fr_illegal_protocol_conf_ptr = NULL_PTR; 
    Fr_callback_functions.Fr_coldstart_abort_ptr = NULL_PTR;
    Fr_callback_functions.Fr_missing_rate_corr_ptr = NULL_PTR;
    Fr_callback_functions.Fr_missing_offset_corr_ptr = NULL_PTR;
    Fr_callback_functions.Fr_clock_corr_limit_ptr = NULL_PTR;
    Fr_callback_functions.Fr_max_sync_frames_ptr = NULL_PTR;
    Fr_callback_functions.Fr_mts_received_ptr = NULL_PTR;  
    Fr_callback_functions.Fr_violation_B_ptr = NULL_PTR;   
    Fr_callback_functions.Fr_violation_A_ptr = NULL_PTR;  
    Fr_callback_functions.Fr_trans_across_boundary_B_ptr = NULL_PTR;
    Fr_callback_functions.Fr_trans_across_boundary_A_ptr = NULL_PTR;
    Fr_callback_functions.Fr_timer_2_expired_ptr = NULL_PTR;
    Fr_callback_functions.Fr_timer_1_expired_ptr = NULL_PTR;
    Fr_callback_functions.Fr_cycle_start_ptr = NULL_PTR;  
    Fr_callback_functions.Fr_error_mode_changed_ptr = NULL_PTR;  
    Fr_callback_functions.Fr_illegal_protocol_command_ptr = NULL_PTR;   
    Fr_callback_functions.Fr_protocol_engine_comm_failure_ptr = NULL_PTR;  
    Fr_callback_functions.Fr_protocol_state_changed_ptr = NULL_PTR;
    Fr_callback_functions.Fr_slot_status_counter_3_inc_ptr = NULL_PTR;
    Fr_callback_functions.Fr_slot_status_counter_2_inc_ptr = NULL_PTR;
    Fr_callback_functions.Fr_slot_status_counter_1_inc_ptr = NULL_PTR;
    Fr_callback_functions.Fr_slot_status_counter_0_inc_ptr = NULL_PTR;  
    Fr_callback_functions.Fr_even_cycle_table_written_ptr = NULL_PTR;
    Fr_callback_functions.Fr_odd_cycle_table_written_ptr = NULL_PTR;
    /* Clear index */
    temp_index = 0U;     
    /* Configure all required MBs */
    while(Fr_buffer_config_set_ptr[temp_index] != FR_LAST_MB)   
    {
        /* Store configuration index */
        Fr_buffer_info_set_index = Fr_buffer_config_set_ptr[temp_index];    
        /* Temporary offset address of MB registers */
        Fr_MB_registers_offset_add_temp = (VAR(uint16, AUTOMATIC))(Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init * 4U);

        

        switch(Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_type)
        {
        /* Configure receive MB */
        case FR_RECEIVE_BUFFER:         
            #if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
            Fr_InternalResource[Fr_CtrlIdx][Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init] = temp_index; /* polyspace RTE:OBAI */
            /* FR_BUFFER_RECONFIG */
            #else
            (void)Fr_CtrlIdx;
            #endif  
            Fr_receive_buffer_config_ptr = ((P2VAR(Fr_receive_buffer_config_type, AUTOMATIC, FR_APPL_DATA))(Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_config_ptr));
            
            /* Disable appropriate MB */
            if((Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] & FrMBCCSR_EDS) != 0U) /* polyspace RTE:NIV,IDP */
            {
                temp_value_1 = FrMBCCSR_EDT;
                Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] = temp_value_1; /* polyspace RTE:IDP */
            }
            
            /* Configure MBCCSRn register */
            /* Clear variable */
            temp_value_2 = 0x0000U;      
            if(Fr_receive_buffer_config_ptr->rx_MB_interrupt_enable != 0U)
            {
                /* Interrupt generation enabled */
                temp_value_2 = FrMBCCSR_MBIE;            
            }
            /* Configure MB as Receive MB and enable interrupt if required */
            Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] = temp_value_2; /* polyspace RTE:IDP */
            
            /* Configure MBCCFRn register */
            /* Clear variable */
            temp_value_1 = 0x0000U;     
            if(Fr_receive_buffer_config_ptr->receive_channel_enable == FR_CHANNEL_A)
            {
                /* Channel assigment - ch. A */
                temp_value_1 = FrMBCCFR_CHA;    
            }
            else if(Fr_receive_buffer_config_ptr->receive_channel_enable == FR_CHANNEL_B)
            {
                /* Channel assigment - ch. B */
                temp_value_1 = FrMBCCFR_CHB;    
            }
            else if(Fr_receive_buffer_config_ptr->receive_channel_enable == FR_CHANNEL_AB)
            {
                /* Channel assigment - ch. A */
                temp_value_1 = (FrMBCCFR_CHA | FrMBCCFR_CHB);    
            }
            else
            {
                retVal = StatusErro;
            }
            Fr_MB_information_internal[Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init].Mb_channel_type = Fr_receive_buffer_config_ptr->receive_channel_enable; /* polyspace RTE:OBAI */
            Fr_MB_information_internal[Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init].FrifLsduLength = Fr_receive_buffer_config_ptr->RxSduLength; /* polyspace RTE:OBAI */
            /* Cycle counter filter settings */
            /* Should be the cycle counter filter enabled? */
            if(Fr_receive_buffer_config_ptr->rx_cycle_counter_filter_enable  != 0U)    
            {
                temp_value_2 = 0x0000U;
                /* Cycle counter filter value */
                temp_value_2= (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_receive_buffer_config_ptr->rx_cycle_counter_filter_value & 0x3FU);
                temp_value_1 |= temp_value_2;
                /* Cycle counter filter mask */
                temp_value_2 =  ((VAR(uint16, AUTOMATIC))Fr_receive_buffer_config_ptr->rx_cycle_counter_filter_mask & 0x3FU);
                temp_value_1 |= (VAR(uint16, AUTOMATIC))(temp_value_2 << 6U);
                /* Cycle counter filter enabled */
                temp_value_1 |= FrMBCCFR_CCFE;  
            }
            /* Store configuration into MBCCFRn register */
            Fr_CC_reg_ptr[FrMBCCFR0 + Fr_MB_registers_offset_add_temp] = temp_value_1; /* polyspace RTE:IDP */
            
            /* Configure MBFIDRn register */
            Fr_CC_reg_ptr[FrMBFIDR0 + Fr_MB_registers_offset_add_temp] = Fr_receive_buffer_config_ptr->receive_frame_ID; /* polyspace RTE:IDP */
            
            /* Store receive MB frame ID into internal MB information structure */
            Fr_MB_information_internal[Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init].slot_number = Fr_receive_buffer_config_ptr->receive_frame_ID; /* polyspace RTE:OBAI */

            
            /* Calculate and configure data field offset  */
            /* According to a FlexRay Memory Layout descibed in FlexRay module documentation */
            
            /* Calculate the message buffer header  */
            header_MB_ptr = ((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA))(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + (Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init * 4U));
            /* Check if the message buffer is in segment 1 or segment 2 */
            if(Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init < ((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 + 1U))
            {   /* Payload data of MB are in segment 1 */
                /* Calculate valid Data Field Offset */
                /* (total_MB_number * 10) + (buffer_index_init * MB_segment_1_data_size * 2) */
                temp_value_2 = (VAR(uint16, AUTOMATIC))((Fr_HW_config_ptr->total_MB_number * 8U) + \
                                (Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init * \
                                Fr_HW_config_ptr->MB_segment_1_data_size * 2U));
            }
            else /* Payload data of MB are in segment 2 */
            {
                /* Calculate valid Data Field Offset */
                /*(total_MB_number * 10) + ((last_MB_seg_1 + 1) * MB_segment_1_data_size * 2) + ((buffer_index_init - (last_MB_seg_1 + 1)) * MB_segment_2_data_size * 2)*/
                temp_value_2 = (VAR(uint16, AUTOMATIC))((Fr_HW_config_ptr->total_MB_number * 8U) + \
                                (((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 + 1U) * Fr_HW_config_ptr->MB_segment_1_data_size * 2U) + \
                                ((Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init - \
                                ((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 + 1U)) * Fr_HW_config_ptr->MB_segment_2_data_size * 2U));
            }
            temp_value_1 = Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init;
            Fr_CC_reg_ptr[FrMBDOR0 + temp_value_1] = temp_value_2; /* polyspace RTE:IDP */

            /* Message Buffer Index Registers initialization */
            temp_value_1 = Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init;
            Fr_CC_reg_ptr[FrMBIDXR0 + Fr_MB_registers_offset_add_temp] = temp_value_1; /* polyspace RTE:IDP */
            
            /* Store the highest number of message buffer index into variable for optimization verification */
            if(highest_txrx_mb_number < temp_value_1)
            {
                /* Update variable with the highest index number */
                highest_txrx_mb_number = (VAR(uint8, AUTOMATIC))temp_value_1;      
            }
            
            /* Store MB type into internal MB information structure */
            /* Not necessary for the current version of the UNIFIED Driver */
            
            /* Enable message buffer */
            SchM_Enter_Fr_EXCLUSIVE_AREA_10();
            temp_value_1 = Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] | FrMBCCSR_EDT; /* polyspace RTE:NIV,IDP */
            Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] = temp_value_1; /* polyspace RTE:IDP */
            SchM_Exit_Fr_EXCLUSIVE_AREA_10();
            
            break;
            /* Configure transmit MB */
        case FR_TRANSMIT_BUFFER:        
            #if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)

            Fr_InternalResource[Fr_CtrlIdx][Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init] = temp_index; /* polyspace RTE:OBAI */
            /* FR_BUFFER_RECONFIG */
            #endif  
            Fr_transmit_buffer_config_ptr = ((P2VAR(Fr_transmit_buffer_config_type, AUTOMATIC,FR_APPL_DATA))(Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_config_ptr));
            /* Store trigger enable/disbale bit into variable */
            temp_value_1 = FrMBCCSR_EDT;    
           
            /* Disable appropriate MB */
            if((Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] & FrMBCCSR_EDS)  != 0U) /* polyspace RTE:NIV,IDP */
            {
                Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] = temp_value_1; /* polyspace RTE:IDP */
            }
            /* Disable transmit side of the double buffered MB */
            if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
            {
                /* Disable appropriate MB */
                if((Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp + 4U] & FrMBCCSR_EDS)  != 0U) /* polyspace RTE:NIV,IDP */
                {
                    Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp + 4U] = temp_value_1; /* polyspace RTE:IDP */
                }
            }
            
            /* Configure MBCCSRn register */
            /* Configure MB as Transmit */
            temp_value_2 = FrMBCCSR_MTD;    
            /* Clear temporary variable */
            temp_value_3 = 0x0000U;          

            /* Double buffered TX MB configured? */
            if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
            {
                /* Double buffered transmit MB */
                temp_value_2 |= FrMBCCSR_MBT;           

                /* Immediate commit mode configured? (only for double buffered TX MB */
                if(Fr_transmit_buffer_config_ptr->transmission_commit_mode == FR_IMMEDIATE_COMMIT_MODE)
                {
                    /* Immediate commit mode */
                    temp_value_2 |= FrMBCCSR_MCM;           
                }
                /* Store transmit MB type into internal MB information structure */
                Fr_MB_information_internal[Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init].transmission_mode =  FR_DOUBLE_TRANSMIT_BUFFER; /* polyspace RTE:OBAI */
                Fr_MB_information_internal[Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init + 1U].transmission_mode =  FR_DOUBLE_TRANSMIT_BUFFER; /* polyspace RTE:OBAI */
            }
            else
            {
                /* Store transmit MB type into internal MB information structure */
                Fr_MB_information_internal[Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init].transmission_mode =  FR_SINGLE_TRANSMIT_BUFFER; /* polyspace RTE:OBAI */
            }
            /* Copy configuration into temp_value_3 variable */     
            /* Interrupt flag can be set for the commit or transmit side of the double buf.MB */
            temp_value_3 = temp_value_2;    
            
            /* Interrupt generation configured? */
            if(Fr_transmit_buffer_config_ptr->tx_MB_interrupt_enable  != 0U)   
            {
                if((Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER) && Fr_transmit_buffer_config_ptr->tx_MB_interrupt_transmit_side_enable) /* PRQA S 4115 */
                {
                    /* Interrupt flag is set for the transmit side of the double buf.MB, not for commit side */
                    /* Interrupt generation enabled */
                    temp_value_2 |= FrMBCCSR_MBIE;           
                }
                else
                {
                    /* Interrupt flag is not set for the transmit side of the double buf.MB */
                    /* Interrupt generation enabled */
                    temp_value_3 |= FrMBCCSR_MBIE;           
                }
            }

            /* Store configuration into the MBCCSRn register */
            Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] = temp_value_3; /* polyspace RTE:IDP */
            /* Store configuration into transmit side of the double buffered MB */
            if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
            {
                /* Store configuration into the MBCCSR[2n+1] register */
                Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp + 4U] = temp_value_2; /* polyspace RTE:IDP */
            }
            
            /* Configure MBCCFRn register */
            /* Clear variable */
            temp_value_1 = 0x0000U;      
            if(Fr_transmit_buffer_config_ptr->transmit_channel_enable == FR_CHANNEL_A)
            {
                /* Channel assigment - ch. A */
                temp_value_1 = FrMBCCFR_CHA;    
            }
            else if(Fr_transmit_buffer_config_ptr->transmit_channel_enable == FR_CHANNEL_B)
            {
                /* Channel assigment - ch. B */
                temp_value_1 = FrMBCCFR_CHB;     
            }
            else if(Fr_transmit_buffer_config_ptr->transmit_channel_enable == FR_CHANNEL_AB)
            {
                /* Channel assigment - ch. A */
                temp_value_1 = (FrMBCCFR_CHA | FrMBCCFR_CHB);    
            }
            else
            {
                retVal = StatusErro;
            }
            Fr_MB_information_internal[Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init].Mb_channel_type = Fr_transmit_buffer_config_ptr->transmit_channel_enable; /* polyspace RTE:OBAI */
            /* Cycle counter filter settings */
            /* Should be the cycle counter filter enabled? */
            if(Fr_transmit_buffer_config_ptr->tx_cycle_counter_filter_enable  != 0U)   
            {
                temp_value_2 = 0x0000U;
                /* Cycle counter filter value */
                temp_value_2 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_transmit_buffer_config_ptr->tx_cycle_counter_filter_value & 0x003FU);
                temp_value_1 |= temp_value_2;
                /* Cycle counter filter mask */
                temp_value_2 =  ((VAR(uint16, AUTOMATIC))Fr_transmit_buffer_config_ptr->tx_cycle_counter_filter_mask & 0x3FU);
                temp_value_1 |= (VAR(uint16, AUTOMATIC))(temp_value_2 << 6U);
                /* Cycle counter filter enabled */ 
                temp_value_1 |= FrMBCCFR_CCFE;  
            }
             /* Which transmission mode? */
            if(Fr_transmit_buffer_config_ptr->transmission_mode == FR_STATE_TRANSMISSION_MODE)
            {
                /* State transmission mode is enabled */
                temp_value_1 |= FrMBCCFR_MTM;   
                /* Store information into internal structure */
                Fr_MB_information_internal[Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init].transmission_type = FR_STATE_TRANSMISSION_MODE; /* polyspace RTE:OBAI */
                if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
                {
                    /* Store information also for transmit side of the double buffered MB */
                    Fr_MB_information_internal[Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init + 1U].transmission_type =  FR_STATE_TRANSMISSION_MODE; /* polyspace RTE:OBAI */
                }                            
            }
            else
            {
               /* Store information into internal structure */
               Fr_MB_information_internal[Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init].transmission_type =  FR_EVENT_TRANSMISSION_MODE; /* polyspace RTE:OBAI */
            }
            /* Store configuration into MBCCFRn register */
            Fr_CC_reg_ptr[FrMBCCFR0 + Fr_MB_registers_offset_add_temp] = temp_value_1; /* polyspace RTE:IDP */
            /* Store configuration into transmit side of the double buffered MB */
            if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
            {
                /* Store configuration into the MBCCFR[2n+1] register */
                Fr_CC_reg_ptr[FrMBCCFR0 + Fr_MB_registers_offset_add_temp + 4U] = temp_value_1; /* polyspace RTE:IDP */
            }

            
            /* Configure MBFIDRn register */
            Fr_CC_reg_ptr[FrMBFIDR0 + Fr_MB_registers_offset_add_temp] = Fr_transmit_buffer_config_ptr->transmit_frame_ID; /* polyspace RTE:IDP */
            /* Store configuration into transmit side of the double buffered MB */
            if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
            {
                /* Store configuration into the MBFIDR[2n+1] register */
                Fr_CC_reg_ptr[FrMBFIDR0 + Fr_MB_registers_offset_add_temp + 4U] = Fr_transmit_buffer_config_ptr->transmit_frame_ID; /* polyspace RTE:IDP */
            }

            
            /* Store transmit MB frame ID into internal MB information structure */
            Fr_MB_information_internal[Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init].slot_number = Fr_transmit_buffer_config_ptr->transmit_frame_ID; /* polyspace RTE:OBAI */

            /* Initialize the second part of double buffer if double buffered TX MB configured */
            if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
            {
                Fr_MB_information_internal[Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init + 1U].slot_number = Fr_transmit_buffer_config_ptr->transmit_frame_ID; /* polyspace RTE:OBAI */
            }
          
            /* Calculate and configure data field offset  */
            /* According to a FlexRay Memory Layout descibed in FlexRay module documentation */
            
            /* Calculate the message buffer header  */

            header_MB_ptr = ((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA))(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + (Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init * 4U));

            /* Configure Frame Header registers */
            temp_value_1 = 0x0000U;          /* Clear */
            /* Frame ID */
            temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_transmit_buffer_config_ptr->transmit_frame_ID & 0x07FFU);   
            /* Payload preamble indicator configured? */
            if(Fr_transmit_buffer_config_ptr->payload_preamble == TRUE)        
            {
                /* Configure Payload preamble indicator */
                temp_value_1 = FrF_HEADER_PPI;                                  
            }
            /* Store the first word of Frame Header Section */
            header_MB_ptr[0U] = temp_value_1; /* polyspace RTE:IDP */
            /* Store configuration into transmit side of the double buffered MB */
            if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
            {
                /* Store configuration into the first word of Frame Header Section */
                /* Store the first word of Frame Header Section */
                header_MB_ptr[0+5] = temp_value_1; /* polyspace RTE:IDP */
            }
            /* Clear */
            temp_value_2 = 0x0000U;          
            /* Payload length */
            temp_value_2 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_transmit_buffer_config_ptr->payload_length & 0x007FU);   
            /* Store the second word of Frame Header Section */
            header_MB_ptr[1U] = temp_value_2; /* polyspace RTE:IDP */
            /* Store configuration into transmit side of the double buffered MB */
            if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
            {
                /* Store configuration into the second word of Frame Header Section */
                 /* Store the second word of Frame Header Section */
                header_MB_ptr[1U+5U] = temp_value_2; /* polyspace RTE:IDP */
            }

            /* Clear */ 
            temp_value_1 = 0x0000U;         
            /* Header CRC */
            temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_transmit_buffer_config_ptr->header_CRC & 0x07FFU);   
            /* Store the third word of Frame Header Section */
            header_MB_ptr[2U] = temp_value_1; /* polyspace RTE:IDP */
            /* Store configuration into transmit side of the double buffered MB */
            if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
            {
                /* Store configuration into the third word of Frame Header Section */
                /* Store the third word of Frame Header Section */
                header_MB_ptr[2U+5U] = temp_value_1; /* polyspace RTE:IDP */
            }

          
            /* Check if the message buffer is in segment 1 or segment 2 */
            if(Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init < ((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 + 1U))
            {   /* Payload data of MB are in segment 1 */
                /* Calculate valid Data Field Offset */
                    /* (total_MB_number * 8) + (buffer_index_init * MB_segment_1_data_size * 2) */
                    temp_value_2 =(VAR(uint16, AUTOMATIC))((Fr_HW_config_ptr->total_MB_number * 8U) + \
                               (Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init * \
                               Fr_HW_config_ptr->MB_segment_1_data_size * 2U));

                /* Calculate the Data Field Offset for the transmit side of the double MB */
                if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
                {
                    /* Calculate valid Data Field Offset */
                    /* (total_MB_number * 10) + (buffer_index_init * MB_segment_1_data_size * 2) + 1 * MB_segment_1_data_size * 2 */
                    temp_value_1 = (VAR(uint16, AUTOMATIC))(temp_value_2 + ((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->MB_segment_1_data_size * 2U));
                }
            }
            else /* Payload data of MB are in segment 2 */
            {
                    /* Calculate valid Data Field Offset */
                    /*(total_MB_number * 8) + ((last_MB_seg_1 + 1) * MB_segment_1_data_size * 2) + ((buffer_index_init - (last_MB_seg_1 + 1)) * MB_segment_2_data_size * 2)*/
                    temp_value_2 = (VAR(uint16, AUTOMATIC))((Fr_HW_config_ptr->total_MB_number * 8U) + \
                                   (((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 + 1U) * Fr_HW_config_ptr->MB_segment_1_data_size * 2U) + \
                                   ((Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init - \
                                   ((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 + 1U)) * Fr_HW_config_ptr->MB_segment_2_data_size * 2U));

                /* Calculate the Data Field Offset for the transmit side of the double MB */
                if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
                {
                    /* Calculate valid Data Field Offset */
                    /*(total_MB_number * 10) + ((last_MB_seg_1 + 1) * MB_segment_1_data_size * 2) + ((buffer_index_init - (last_MB_seg_1 + 1)) * MB_segment_2_data_size * 2) + 1 * MB_segment_2_data_size * 2 */
                    temp_value_1 = (VAR(uint16, AUTOMATIC))(temp_value_2 + ((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->MB_segment_2_data_size * 2U));
                }
            }
            
            Fr_CC_reg_ptr[FrMBDOR0 + Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init] = temp_value_2; /* polyspace RTE:IDP */

            /* Store configuration into transmit side of the double buffered MB */
            if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
            {
                /* Store the Data Field Offset to Frame Header Section */
                /* Store Data Field Offset to Frame header register */
                header_MB_ptr[3U+5U] = temp_value_1; /* polyspace RTE:IDP */
            }

 
            /* Message Buffer Index Registers initialization */
            temp_value_1 = Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init;
            Fr_CC_reg_ptr[FrMBIDXR0 + Fr_MB_registers_offset_add_temp] = temp_value_1; /* polyspace RTE:IDP */
            /* Store configuration into transmit side of the double buffered MB */

            /* Store the highest number of message buffer index into variable for optimization verification */
            if(highest_txrx_mb_number < temp_value_1)
            {
                /* Update variable with the highest index number */
                highest_txrx_mb_number = (VAR(uint8, AUTOMATIC))temp_value_1;      
            }

            if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
            {
                /* Store configuration into the MBIDXR[2n+1] register */
                Fr_CC_reg_ptr[FrMBIDXR0 + Fr_MB_registers_offset_add_temp + 4U] = (VAR(uint16, AUTOMATIC))(temp_value_1 + 1U); /* polyspace RTE:IDP */
                
                /* Store the highest number of message buffer index into variable for optimization verification */
                if(highest_txrx_mb_number < (temp_value_1 + 1U))
                {
                    /* Update variable with the highest index number */
                    highest_txrx_mb_number = (VAR(uint8, AUTOMATIC))(temp_value_1 + 1U);      
                }
            }
            
            /* Store MB type into internal MB information structure */
            /* Not necessary for the current version of the UNIFIED Driver */

            /* Enable message buffer */
            temp_value_1 = Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] | FrMBCCSR_EDT; /* polyspace RTE:NIV,IDP */
            SchM_Enter_Fr_EXCLUSIVE_AREA_11();
            /* Initialize the second part of double buffer if double buffered TX MB configured */
            if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
            {
                /* Enable the MB - only in the transmit side of the double buffered - the MBCCSR[2n+1] register */
                Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp + 4U] = temp_value_1; /* polyspace RTE:IDP */
            }
            else
            {
                /* Enable the MB in the MBCCSRn register */
                Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] = temp_value_1; /* polyspace RTE:IDP */
            }
        SchM_Exit_Fr_EXCLUSIVE_AREA_11();
            break;
            

        case FR_RECEIVE_FIFO:           /* Configure receive FIFO storage */
            Fr_FIFO_config_ptr = ((P2VAR(Fr_FIFO_config_type, AUTOMATIC,FR_APPL_DATA))(Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_config_ptr));
            #if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
            Fr_InternalResource[Fr_CtrlIdx][Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init] = temp_index; /* polyspace RTE:OBAI */
            #endif  /* FR_BUFFER_RECONFIG */
            /* FIFO A or FIFO B? */
            if(Fr_FIFO_config_ptr->FIFO_channel == FR_CHANNEL_A)    
            {   /* FIFO A */
            /* Set channel A in Receive FIFO Selection reg. */
                Fr_CC_reg_ptr[FrRFSR] = 0x0000U;                     

                /* Calculate data field offset and configure MB Header Field reg. */
                /* Clear */
                temp_value_1 = 0x0000U;      
                /* Calculate data field offset - for the first FIFO item */
                /* Has a FIFO storage already been configured? */
                if(Fr_FIFO_info.FIFO_1_used == FALSE)   
                {                                       /* No FIFO storage has been configured yet */
                    /*(total_MB_number * 10) + ((last_MB_seg_1 + 1) * MB_segment_1_data_size * 2) + ((last_MB_util -last_MB_seg_1) * MB_segment_2_data_size * 2) */
                    temp_value_2 = (VAR(uint16, AUTOMATIC))((Fr_HW_config_ptr->total_MB_number * 8U) + \
                                    (((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 + 1U) * Fr_HW_config_ptr->MB_segment_1_data_size * 2U) + \
                                    ((Fr_HW_config_ptr->last_MB_util - (VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1) * \
                                    Fr_HW_config_ptr->MB_segment_2_data_size * 2U));
                                    Fr_CC_reg_ptr[FrRFSDOR] = temp_value_2; /* polyspace RTE:IDP */

                    /* Update FIFO info structure */
                    Fr_FIFO_info.FIFO_1_used = TRUE;
                    Fr_FIFO_info.FIFO_1_channel = FR_CHANNEL_A;
                    Fr_FIFO_info.FIFO_1_depth = Fr_FIFO_config_ptr->FIFO_depth;
                    Fr_FIFO_info.FIFO_1_entry_size = Fr_FIFO_config_ptr->FIFO_entry_size;

                }
                /* One FIFO storage has already been configured */
                else  
                {
                    /* (total_MB_number * 10) + ((last_MB_seg_1 + 1) * MB_segment_1_data_size * 2) + ((last_MB_util -last_MB_seg_1) * MB_segment_2_data_size * 2) + (FIFO_1_depth * FIFO_1_entry_size * 2)*/

                    temp_value_2 = (VAR(uint16, AUTOMATIC))((Fr_HW_config_ptr->total_MB_number * 8U) + \
                                    (((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 + 1U) * Fr_HW_config_ptr->MB_segment_1_data_size * 2U) + \
                                    ((Fr_HW_config_ptr->last_MB_util - (VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1) * \
                                    (VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->MB_segment_2_data_size * 2U) + ((VAR(uint16, AUTOMATIC))Fr_FIFO_info.FIFO_1_depth * \
                                    Fr_FIFO_info.FIFO_1_entry_size * 2U));

                    /* Update FIFO info structure */
                    Fr_FIFO_info.FIFO_2_used = TRUE;
                    Fr_FIFO_info.FIFO_2_channel = FR_CHANNEL_A;
                    Fr_FIFO_info.FIFO_2_depth = Fr_FIFO_config_ptr->FIFO_depth;
                    Fr_FIFO_info.FIFO_2_entry_size = Fr_FIFO_config_ptr->FIFO_entry_size;

                }
            }
            else
            {   /* FIFO B */
            /* Set channel B in Receive FIFO Selection reg. */
                Fr_CC_reg_ptr[FrRFSR] = 0x0001U;                     

                /* Calculate data field offset and configure MB Header Field reg. */
                temp_value_1 = 0x0000U;      /* Clear */

                /* Calculate data field offset - for the first FIFO item */
                /* Has a FIFO storage already been configured? */
                if(Fr_FIFO_info.FIFO_1_used == FALSE)   
                {                                 /* No FIFO storage has been configured yet */
                    /*(total_MB_number * 10) + ((last_MB_seg_1 + 1) * MB_segment_1_data_size * 2) + ((last_MB_util -last_MB_seg_1) * MB_segment_2_data_size * 2) */
                    temp_value_2 = (VAR(uint16, AUTOMATIC))((Fr_HW_config_ptr->total_MB_number * 8U) + \
                                    (((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 + 1U) * (VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->MB_segment_1_data_size * 2U) + \
                                    (((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_util - (VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1) * \
                                    Fr_HW_config_ptr->MB_segment_2_data_size * 2U));
                    Fr_CC_reg_ptr[FrRFSDOR] = temp_value_2; /* polyspace RTE:IDP */

                    /* Update FIFO info structure */
                    Fr_FIFO_info.FIFO_1_used = TRUE;
                    Fr_FIFO_info.FIFO_1_channel = FR_CHANNEL_B;
                    Fr_FIFO_info.FIFO_1_depth = Fr_FIFO_config_ptr->FIFO_depth;
                    Fr_FIFO_info.FIFO_1_entry_size = Fr_FIFO_config_ptr->FIFO_entry_size;
                }
                /* One FIFO storage has already been configured */
                else                                    
                {
                    /*(total_MB_number * 10) + ((last_MB_seg_1 + 1) * MB_segment_1_data_size * 2) + ((last_MB_util -last_MB_seg_1) * MB_segment_2_data_size * 2) + (FIFO_1_depth * FIFO_1_entry_size * 2) */
                    temp_value_2 = (VAR(uint16, AUTOMATIC))((Fr_HW_config_ptr->total_MB_number * 8U) + \
                                    (((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 + 1U) * Fr_HW_config_ptr->MB_segment_1_data_size * 2U) + \
                                    ((Fr_HW_config_ptr->last_MB_util - (VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1) * \
                                    (VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->MB_segment_2_data_size * 2U) + ((VAR(uint16, AUTOMATIC))Fr_FIFO_info.FIFO_1_depth * \
                                    Fr_FIFO_info.FIFO_1_entry_size * 2U));
            
                    /* Update FIFO info structure */
                    Fr_FIFO_info.FIFO_2_used = TRUE;
                    Fr_FIFO_info.FIFO_2_channel = FR_CHANNEL_B;
                    Fr_FIFO_info.FIFO_2_depth = Fr_FIFO_config_ptr->FIFO_depth;
                    Fr_FIFO_info.FIFO_2_entry_size = Fr_FIFO_config_ptr->FIFO_entry_size;
                }
            }
            
            /* Configure Receive FIFO start index reg. */
            /* Clear */
            temp_value_2 = 0x0000U;
            /* Load start index */     
            temp_value_2 = (VAR(uint16, AUTOMATIC))(Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_index_init & 0x03FFU); 
            /* Store start index */
            Fr_CC_reg_ptr[FrRFSIR] = temp_value_2;  
            
            /* Configure FIFO Depth and Size reg. */
            /* Clear variable */
            temp_value_1 = 0x0000U;      
            /* Entry size [Words] */
            temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_FIFO_config_ptr->FIFO_entry_size & 0x7FU);   
            temp_value_2 = (VAR(uint16, AUTOMATIC))(Fr_FIFO_config_ptr->FIFO_depth << 8U);
            /* FIFO Depth */
            temp_value_1 |= temp_value_2;          
            /* Store FIFO entry size and depth */
            Fr_CC_reg_ptr[FrRFDSR] = temp_value_1;                          
            
            /* Configure FIFO Message ID Acceptance Filter Value */
            /* Store filter value */
            Fr_CC_reg_ptr[FrRFMIDAFVR] = Fr_FIFO_config_ptr->FIFO_message_ID_acceptance_filter_value;   
            
            /* Configure FIFO Message ID Acceptance Filter Mask */
            /* Store filter mask */
            Fr_CC_reg_ptr[FrRFMIAFMR] = Fr_FIFO_config_ptr->FIFO_message_ID_acceptance_filter_mask;     
            
            /* Configure FIFO Frame ID Rejection Filter Value */
            /* Clear */
            temp_value_2 = 0x0000U;      
            /* Rejection filter value */
            temp_value_2 = (VAR(uint16, AUTOMATIC))(Fr_FIFO_config_ptr->FIFO_frame_ID_rejection_filter_value & 0x07FFU); 
            /* Store filter value */
            Fr_CC_reg_ptr[FrRFFIDRFVR] = temp_value_2;                      
            
            /* Configure FIFO Frame ID Rejection Filter Mask */
            /* Clear */
            temp_value_1 = 0x0000U;      
            /* Rejection filter mask */
            temp_value_1 = (Fr_FIFO_config_ptr->FIFO_frame_ID_rejection_filter_mask & 0x07FFU);   
            /* Store filter mask */
            Fr_CC_reg_ptr[FrRFFIDRFMR] = temp_value_1;                      
            
            /* Configure FIFO Interrupt */
            /* FIFO interrupt should be configured? */
            if(Fr_FIFO_config_ptr->FIFO_interrupt_enable  != 0U)                   
            {
                /* Which FIFO channel */
                if(Fr_FIFO_config_ptr->FIFO_channel == FR_CHANNEL_A)        
                {
                    /* Enable interrupt for FIFO channel A in the GIFER reg. */
                    /* Clear */
                    temp_value_2 = 0x0000U;            
                    /* Load content of the GIFER reg. */      
                    temp_value_2 |= Fr_CC_reg_ptr[FrGIFER]; /* polyspace RTE:NIV */
                    /* FNEAIE bit - enable interrupt line */
                    temp_value_2 |= FrGIFER_FNEAIE;       
                    /* Store settings */
                    Fr_CC_reg_ptr[FrGIFER] = temp_value_2;  
                }
                else
                {
                    /* Enable interrupt for FIFO channel B in the GIFER reg. */
                    /* Clear */
                    temp_value_2 = 0x0000U;            
                    /* Load content of the GIFER reg. */      
                    temp_value_2 |= Fr_CC_reg_ptr[FrGIFER]; /* polyspace RTE:NIV */
                    /* FNEBIE bit - enable interrupt line */
                    temp_value_2 |= FrGIFER_FNEBIE;         
                    /* Store settings */
                    Fr_CC_reg_ptr[FrGIFER] = temp_value_2;  
                }
            }

            /* Configure Range Filters */
            /* Range filter 0 */
            /* Range filter 0 enabled? */
            if(Fr_FIFO_config_ptr->FIFO_range_filters_config[0U].range_filter_enable  != 0U)  
            {
                /* Clear + set filter Selector - filter 0 */
                temp_value_1 = 0x0000U;                      
                /* Set Lower Interval Boundary Slot ID */
                temp_value_1 = (Fr_FIFO_config_ptr->FIFO_range_filters_config[0U].range_filter_lower_interval & 0x07FFU);
                /* Store Range filter 0 settings */
                Fr_CC_reg_ptr[FrRFRFCFR] = temp_value_1;    
                /* Clear + set filter Selector - filter 0 */
                temp_value_2 = 0x0000U;             
                /* Program upper interval boundary */         
                temp_value_2 |= FrRFRFCFR_IBD;              
                /* Set Upper Interval Boundary Slot ID */
                temp_value_1 = (Fr_FIFO_config_ptr->FIFO_range_filters_config[0U].range_filter_upper_interval & 0x07FFU);
                temp_value_2 |= temp_value_1;
                /* Store Range filter 0 settings */
                Fr_CC_reg_ptr[FrRFRFCFR] = temp_value_2;    
            }
        
            /* Range filter 1 */
            /* Range filter 1 enabled? */
            if(Fr_FIFO_config_ptr->FIFO_range_filters_config[1U].range_filter_enable  != 0U)  
            {
                /* Clear */
                temp_value_1 = 0x0000U;                      
                /* Set Filter SELector - filter 1 */
                temp_value_1 |= 0x1000U;                     
                /* Set Lower Interval Boundary Slot ID */
                temp_value_2 = (Fr_FIFO_config_ptr->FIFO_range_filters_config[1U].range_filter_lower_interval & 0x07FFU);
                temp_value_1 |= temp_value_2;
                /* Store Range filter 1 settings */
                Fr_CC_reg_ptr[FrRFRFCFR] = temp_value_1;    
                /* Clear */
                temp_value_2 = 0x0000U;                
                /* Set Filter SELector - filter 1 */      
                temp_value_2 |= 0x1000U;          
                /* Program upper interval boundary */           
                temp_value_2 |= FrRFRFCFR_IBD;              
                /* Set Upper Interval Boundary Slot ID */
                temp_value_1 = (Fr_FIFO_config_ptr->FIFO_range_filters_config[1].range_filter_upper_interval & 0x07FFU);
                temp_value_2 |= temp_value_1;
                /* Store Range filter 1 settings */
                Fr_CC_reg_ptr[FrRFRFCFR] = temp_value_2;    
            }
            
            /* Range filter 2 */
            /* Range filter 2 enabled? */
            if(Fr_FIFO_config_ptr->FIFO_range_filters_config[2].range_filter_enable  != 0U)  
            {
                /* Clear */
                temp_value_1 = 0x0000U;                   
                /* Set Filter SELector - filter 2 */   
                temp_value_1 |= 0x2000U;                     
                /* Set Lower Interval Boundary Slot ID */
                temp_value_2 = (Fr_FIFO_config_ptr->FIFO_range_filters_config[2U].range_filter_lower_interval & 0x07FFU);
                temp_value_1 |= temp_value_2;
                /* Store Range filter 2 settings */
                Fr_CC_reg_ptr[FrRFRFCFR] = temp_value_1;    
                /* Clear */
                temp_value_2 = 0x0000U;                      
                /* Set Filter SELector - filter 2 */
                temp_value_2 |= 0x2000U;               
                /* Program upper interval boundary */      
                temp_value_2 |= FrRFRFCFR_IBD;             
                /* Set Upper Interval Boundary Slot ID */
                temp_value_1 = (Fr_FIFO_config_ptr->FIFO_range_filters_config[2U].range_filter_upper_interval & 0x07FFU);
                temp_value_2 |= temp_value_1;
                /* Store Range filter 2 settings */
                Fr_CC_reg_ptr[FrRFRFCFR] = temp_value_2;    
            }

            /* Range filter 3 */
            /* Range filter 3 enabled? */
            if(Fr_FIFO_config_ptr->FIFO_range_filters_config[3U].range_filter_enable  != 0U)  
            {
                /* Clear */
                temp_value_1 = 0x0000U;                      
                /* Set Filter SELector - filter 3 */
                temp_value_1 |= 0x3000U;                     
                /* Set Lower Interval Boundary Slot ID */
                temp_value_2 = (Fr_FIFO_config_ptr->FIFO_range_filters_config[3U].range_filter_lower_interval & 0x07FFU);
                temp_value_1 |= temp_value_2;
                /* Store Range filter 3 settings */
                Fr_CC_reg_ptr[FrRFRFCFR] = temp_value_1;    
                /* Clear */
                temp_value_2 = 0x0000U;    
                /* Set Filter SELector - filter 3 */                  
                temp_value_2 |= 0x3000U;         
                /* Program upper interval boundary */            
                temp_value_2 |= FrRFRFCFR_IBD;              
                /* Set Upper Interval Boundary Slot ID */
                temp_value_1 = (Fr_FIFO_config_ptr->FIFO_range_filters_config[3U].range_filter_upper_interval & 0x07FFU);
                temp_value_2 |= temp_value_1;
                /* Store Range filter 3 settings */
                Fr_CC_reg_ptr[FrRFRFCFR] = temp_value_2;    
            }

            /* Configure the FIFO Range Filter Control reg. */
            /* Clear */
            temp_value_1 = 0x0000U;                          
            /* Range filter 0 enabled? */
            if(Fr_FIFO_config_ptr->FIFO_range_filters_config[0U].range_filter_enable  != 0U)  
            {
                /* Enable Range Filter 0 */
                temp_value_1 |= FrRFRFCTR_F0EN;             
            }
            /* Range filter 1 enabled? */
            if(Fr_FIFO_config_ptr->FIFO_range_filters_config[1U].range_filter_enable  != 0U)  
            {
                /* Enable Range Filter 1 */
                temp_value_1 |= FrRFRFCTR_F1EN;             
            }
            /* Range filter 2 enabled? */
            if(Fr_FIFO_config_ptr->FIFO_range_filters_config[2U].range_filter_enable  != 0U)  
            {
                /* Enable Range Filter 2 */
                temp_value_1 |= FrRFRFCTR_F2EN;             
            }
            /* Range filter 3 enabled? */
            if(Fr_FIFO_config_ptr->FIFO_range_filters_config[3U].range_filter_enable  != 0U)  
            {
                /* Enable Range Filter 3 */
                temp_value_1 |= FrRFRFCTR_F3EN;             
            }
            /* Filter 0 as rejection? */
            if(Fr_FIFO_config_ptr->FIFO_range_filters_config[0U].range_filter_mode == FR_REJECTION)  
            {
                /* Range filter 0 as rejection filter */
                temp_value_1 |= FrRFRFCTR_F0MD;             
            }
            /* Filter 1 as rejection? */
            if(Fr_FIFO_config_ptr->FIFO_range_filters_config[1U].range_filter_mode == FR_REJECTION)  
            {
                /* Range filter 1 as rejection filter */
                temp_value_1 |= FrRFRFCTR_F1MD;            
            }
            /* Filter 2 as rejection? */
            if(Fr_FIFO_config_ptr->FIFO_range_filters_config[2U].range_filter_mode == FR_REJECTION)  
            {
                /* Range filter 2 as rejection filter */
                temp_value_1 |= FrRFRFCTR_F2MD;            
            }
            /* Filter 3 as rejection? */
            if(Fr_FIFO_config_ptr->FIFO_range_filters_config[3U].range_filter_mode == FR_REJECTION)  
            {
                /* Range filter 3 as rejection filter */
                temp_value_1 |= FrRFRFCTR_F3MD;             
            }
            /* Write configuration settings to the FIFO Range Filter Control reg. */
            Fr_CC_reg_ptr[FrRFRFCTR] = temp_value_1;

            break;
           /* Configure receive shadow buffers */
        case FR_RECEIVE_SHADOW:         
            Fr_shadow_buffer_config_ptr = ((P2VAR(Fr_receive_shadow_buffers_config_type, AUTOMATIC,FR_APPL_DATA))(Fr_buffers_config_ptr[Fr_buffer_info_set_index].buffer_config_ptr));

            /* Configuration of receive shadow buffer for channel A and segment 1 */
            /* Clear */
            temp_value_1 = 0x0000U;      
            /* Shadow buffer for cha A and seg 1 enabled? */
            if(Fr_shadow_buffer_config_ptr->RSBIR_A1_enable  != 0U)    
            {   /* Enabled */
                /* Configure RSBIR reg. */
                /* Store buffer index */
                temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_shadow_buffer_config_ptr->RSBIR_A1_buffer_number_init);    
                /* Store settings for shadow buffer, ch A, seg 1 */
                Fr_CC_reg_ptr[FrRSBIR] = temp_value_1;      
                
                /* Calculate the message buffer header  */

                header_MB_ptr = ((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) )(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + \
                                ((VAR(uint16, AUTOMATIC))(Fr_shadow_buffer_config_ptr->RSBIR_A1_buffer_number_init) * 4U));

                /* Configure MB header field reg. */
                /* Calculate valid Data Field Offset */
                /* (total_MB_number * 10) + (x_buffer_number_init * MB_segment_1_data_size * 2) */

                temp_value_2 = (VAR(uint16, AUTOMATIC))((Fr_HW_config_ptr->total_MB_number * 8U) + \
                                ((VAR(uint16, AUTOMATIC))(Fr_shadow_buffer_config_ptr->RSBIR_A1_buffer_number_init) * \
                                Fr_HW_config_ptr->MB_segment_1_data_size * 2U));
                Fr_CC_reg_ptr[FrMBDOR0 + Fr_shadow_buffer_config_ptr->RSBIR_A1_buffer_number_init] = temp_value_2; /* polyspace RTE:IDP */

            }
            
            /* Configuration of receive shadow buffer for channel A and segment 2 */
            temp_value_1 = 0x0000U;      /* Clear */
            /* Shadow buffer for cha A and seg 2 enabled? */
            if(Fr_shadow_buffer_config_ptr->RSBIR_A2_enable  != 0U)    
            {   /* Enabled */
                /* Configure RSBIR reg. */
                /* Store buffer index */
                temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_shadow_buffer_config_ptr->RSBIR_A2_buffer_number_init);    
                /* Selector field - ch A, seg 2 */
                temp_value_1 |= 0x1000U;                     
                /* Store settings for shadow buffer, ch A, seg 2 */
                Fr_CC_reg_ptr[FrRSBIR] = temp_value_1;      
                
                /* Calculate the message buffer header  */

                header_MB_ptr = ((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA))(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + \
                                ((VAR(uint16, AUTOMATIC))(Fr_shadow_buffer_config_ptr->RSBIR_A2_buffer_number_init) * 4U));

                /* Configure MB header field reg. */
                /* Calculate valid Data Field Offset */
                /* (total_MB_number * 10) + ((last_MB_seg_1 + 1) * MB_segment_1_data_size * 2) + ((x_buffer_number_init - (last_MB_seg_1 + 1)) * MB_segment_2_data_size * 2) */
                temp_value_2 = (VAR(uint16, AUTOMATIC))((Fr_HW_config_ptr->total_MB_number * 8U) + \
                                (((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 + 1U) * Fr_HW_config_ptr->MB_segment_1_data_size * 2U) + \
                                ((((VAR(uint16, AUTOMATIC))Fr_shadow_buffer_config_ptr->RSBIR_A2_buffer_number_init) - \
                                ((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 + 1U)) * Fr_HW_config_ptr->MB_segment_2_data_size * 2U));
                Fr_CC_reg_ptr[FrMBDOR0 + Fr_shadow_buffer_config_ptr->RSBIR_A2_buffer_number_init] = temp_value_2; /* polyspace RTE:IDP */
            }
            
            /* Configuration of receive shadow buffer for channel B and segment 1 */
            /* Clear */
            temp_value_1 = 0x0000U;      
            /* Shadow buffer for cha B and seg 1 enabled? */
            if(Fr_shadow_buffer_config_ptr->RSBIR_B1_enable  != 0U)    
            {   /* Enabled */
                /* Configure RSBIR reg. */
                /* Store buffer index */
                temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_shadow_buffer_config_ptr->RSBIR_B1_buffer_number_init);    
                /* Selector field - ch B, seg 1 */
                temp_value_1 |= 0x2000U;                    
                /* Store settings for shadow buffer, ch B, seg 1 */
                Fr_CC_reg_ptr[FrRSBIR] = temp_value_1;      
                
                /* Calculate the message buffer header  */
                header_MB_ptr = ((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) )(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + \
                                ((VAR(uint16, AUTOMATIC))(Fr_shadow_buffer_config_ptr->RSBIR_B1_buffer_number_init) * 4U));

                /* Configure MB header field reg. */
                /* Calculate valid Data Field Offset */
                /* (total_MB_number * 10) + (x_buffer_number_init * MB_segment_1_data_size * 2) */
                temp_value_2 = (VAR(uint16, AUTOMATIC))((Fr_HW_config_ptr->total_MB_number * 8U) + \
                        ((VAR(uint16, AUTOMATIC))(Fr_shadow_buffer_config_ptr->RSBIR_B1_buffer_number_init) * \
                        Fr_HW_config_ptr->MB_segment_1_data_size * 2U));
                Fr_CC_reg_ptr[FrMBDOR0 + Fr_shadow_buffer_config_ptr->RSBIR_B1_buffer_number_init] = temp_value_2; /* polyspace RTE:IDP */
            }
            
            /* Configuration of receive shadow buffer for channel B and segment 2 */
            /* Clear */
            temp_value_1 = 0x0000U;      
            /* Shadow buffer for cha B and seg 2 enabled? */
            if(Fr_shadow_buffer_config_ptr->RSBIR_B2_enable != 0U)    
            {   /* Enabled */
                /* Configure RSBIR reg. */
                /* Store buffer index */
                temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_shadow_buffer_config_ptr->RSBIR_B2_buffer_number_init);    
                /* Selector field - ch B, seg 2 */
                temp_value_1 |= 0x3000U;                   
                /* Store settings for shadow buffer, ch B, seg 2 */
                Fr_CC_reg_ptr[FrRSBIR] = temp_value_1;      
                
                /* Calculate the message buffer header  */

                header_MB_ptr = ((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA))(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + \
                                ((VAR(uint16, AUTOMATIC))(Fr_shadow_buffer_config_ptr->RSBIR_B2_buffer_number_init) * 4U));

                /* Configure MB header field reg. */
                /* Calculate valid Data Field Offset */
                /*(total_MB_number * 10) + ((last_MB_seg_1 + 1) * MB_segment_1_data_size * 2) + ((x_buffer_number_init - (last_MB_seg_1 + 1)) * MB_segment_2_data_size * 2) */

                temp_value_2 = (VAR(uint16, AUTOMATIC))(((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->total_MB_number * 8U) + \
                                (((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 + 1U) * Fr_HW_config_ptr->MB_segment_1_data_size * 2U) + \
                                ((((VAR(uint16, AUTOMATIC))Fr_shadow_buffer_config_ptr->RSBIR_B2_buffer_number_init) - \
                                ((VAR(uint16, AUTOMATIC))Fr_HW_config_ptr->last_MB_seg_1 + 1U)) * Fr_HW_config_ptr->MB_segment_2_data_size * 2U));
                Fr_CC_reg_ptr[FrMBDOR0 + Fr_shadow_buffer_config_ptr->RSBIR_B2_buffer_number_init] = temp_value_2; /* polyspace RTE:IDP */
            }           
            break;
        default:
            break;
        }
        /* Increment */
        temp_index = (VAR(uint8, AUTOMATIC))(1U + temp_index);   
    }
    
    /* Optimization verification */
    /* Verification whether the highest defined transmit or receive message buffer index  */
    /* (by FR_NUMBER_TXRX_MB parameter in the flexray_cfg.h file) */
    /* does not exceed actually configured message buffer index for some message buffer (without shadow and FIFO) */
    #ifdef FR_NUMBER_TXRX_MB
    /* The FR_NUMBER_TXRX_MB parameter is defined in the flexray_cfg.h file 
    - memory consumption optimization is applied */
        if(highest_txrx_mb_number > FR_NUMBER_TXRX_MB)
        {   /* The configured transmit or receive MB index is greater than it is set in the FR_NUMBER_TXRX_MB parameter */
        /* Error - the value of the FR_NUMBER_TXRX_MB parameter is too low */
            retVal = StatusErro;                  
        }
        else
        {
            retVal = StatusSuss;
        }
         /* API call has been successful */
    #endif
    return retVal;                                     
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Leave_Configuration_Mode
* Description:      This API call initiates a transition from FR_POCSTATE_CONFIG 
*                   state into FR_POCSTATE_READY state.
*
* Function arguments: 
*                   None
*
* Return value:
*                   StatusSuss        API call has been successful
*                   StatusErro    Error occured during transition 
*                                       into FR_POCSTATE_READY
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Leave_Configuration_Mode(VAR(void, FR_VAR))
{
    /* Temporary counter */
    VAR(uint8, FR_VAR) i;                                            
    VAR(Fr_LLDriver_StatusType, FR_VAR) retVal = StatusSuss;
    
    /* Force the FlexRay CC into FR_POCSTATE_READY */
      /* Clear temporary counter */
    i = 0U;    
    /* Wait till Protocol Command Write is not busy */
    while((i < FR_MAX_WAIT_CYCLES) && (Fr_CC_reg_ptr[FrPOCR] & FrPOCR_BSY)) /* polyspace RTE:NIV */
    {
         /* Increment temporary counter */
        i++;       
    }
    if(i == FR_MAX_WAIT_CYCLES) 
    {
        /* Return FR_NOT_SUCCESS in case any error */
        retVal = StatusErro;      

    }
    else
    {
        /* Transition to FR_POCSTATE_READY */
        Fr_CC_reg_ptr[FrPOCR] = (FrPOCR_POCCMD_CONFIG_COMPLETE | FrPOCR_WME);  
        /* Clear temporary counter */
        i = 0U;      
        /* Wait till Protocol Command Write is not busy */
        while((i < FR_MAX_WAIT_CYCLES) && (Fr_CC_reg_ptr[FrPOCR] & FrPOCR_BSY)) 
        {
            /* Increment temporary counter */
            i++;        
        }
        if(i == FR_MAX_WAIT_CYCLES) 
        {
            /* Return FR_NOT_SUCCESS in case any error */
            retVal = StatusErro;      
            
        }
        else
        {
            /* Wait till FlexRay CC is not in FR_POCSTATE_READY */
            /* Clear temporary counter */
            i = 0U;      
            while((i < FR_MAX_WAIT_CYCLES) && ( (Fr_CC_reg_ptr[FrPSR0] & 0x0700U) != FrPSR0_PROTSTATE_READY)) /* polyspace RTE:NIV */
            {
                /* Increment temporary counter */
                i++;        
            }
            if(i == FR_MAX_WAIT_CYCLES) 
            {
                /* Return FR_NOT_SUCCESS in case any error */
                retVal = StatusErro;      
            }
            else
            {
                retVal = StatusSuss;
            }    
        }
    }
/* API call has been successful */
    return retVal;                                      
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_start_communication
* Description:      This API call initiates the start of the communication of the 
*                   FlexRay CC - initiates a transition from FR_POCSTATE_READY state 
*                   into FR_POCSTATE_STARTUP state. If the start up of the FlexRay CC 
*                   is successful, the state FR_POCSTATE_NORMAL_ACTIVE is 
*                   automatically reached. If the FlexRay CC is not in 
*                   FR_POCSTATE_READY state, but e.g. in FR_POCSTATE_HALT state, this 
*                   API call returns StatusErro and remains in the state it is in
*
* Function arguments: 
*                   None
*
* Return value:
*                   StatusSuss        API call has been successful
*                   StatusErro    Error occured during transition 
*                                       into FR_POCSTATE_STARTUP
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Start_Communication(VAR(void, FR_VAR))
{
    /* Temporary counter */
    VAR(uint8, FR_VAR) i;                                    
    VAR(Fr_LLDriver_StatusType, FR_VAR) retVal = StatusSuss;
    /* Temporary variable used for bit operation */
    volatile VAR(uint16, FR_VAR) temp_value_1;               
    /* Load Protocol State field of the PSR0 reg. */
    temp_value_1 = (Fr_CC_reg_ptr[FrPSR0] & 0x0700U); /* polyspace RTE:NIV */
   /* Is the FlexRay CC in the FR_POCSTATE_READY state? */
    if(temp_value_1 == FrPSR0_PROTSTATE_READY)  
    {   /* Yes */
        
        /* Force the FlexRay CC into FR_POCSTATE_STARTUP */
         /* Clear temporary counter */
        i = 0U;     
         /* Wait till Protocol Command Write is not busy */
        while((i < FR_MAX_WAIT_CYCLES) && (Fr_CC_reg_ptr[FrPOCR] & FrPOCR_BSY)) /* polyspace RTE:NIV */
        {
            /* Increment temporary counter */
            i++;        
        }
        if(i == FR_MAX_WAIT_CYCLES) 
        {
            retVal = StatusErro;      /* Return FR_NOT_SUCCESS in case any error */
        }
        else
        {
            if(Fr_HW_config_ptr->allow_cold_start_enable  != 0U) /* polyspace RTE:IDP */           /* Node is ColdStart node? */
            {   /* Yes */
                /* Immediately activate capability of node to cold start cluster */
                Fr_CC_reg_ptr[FrPOCR] = (FrPOCR_POCCMD_ALLOW_COLDSTART  | FrPOCR_WME);
                
                i = 0U;      /* Clear temporary counter */
                /* Wait till Protocol Command Write is not busy */
                while((i < FR_MAX_WAIT_CYCLES) && (Fr_CC_reg_ptr[FrPOCR] & FrPOCR_BSY))
                {
                    /* Increment temporary counter */
                    i++;        
                }
                if(i == FR_MAX_WAIT_CYCLES) 
                {
                    /* Return FR_NOT_SUCCESS in case any error */
                    retVal = StatusErro;      
                }
                else
                {
                    /* Immediately transition to the FR_POCSTATE_STARTUP */
                    Fr_CC_reg_ptr[FrPOCR] = (FrPOCR_POCCMD_RUN  | FrPOCR_WME);  
                    /* Clear temporary counter */
                    i = 0U;      
                    /* Wait till Protocol Command Write is not busy */
                    while((i < FR_MAX_WAIT_CYCLES) && (Fr_CC_reg_ptr[FrPOCR] & FrPOCR_BSY)) 
                    {
                        /* Increment temporary counter */
                        i++;        
                    }
                    if(i == FR_MAX_WAIT_CYCLES) 
                    {
                        /* Return FR_NOT_SUCCESS in case any error */
                        retVal =  StatusErro;      
                    }
                    else
                    {
                        retVal = StatusSuss;
                    }   
                }
            }
            else
            {
                /* Immediately transition to the FR_POCSTATE_STARTUP */
                Fr_CC_reg_ptr[FrPOCR] = (FrPOCR_POCCMD_RUN  | FrPOCR_WME);  
                /* Clear temporary counter */
                i = 0U;      
                /* Wait till Protocol Command Write is not busy */
                while((i < FR_MAX_WAIT_CYCLES) && (Fr_CC_reg_ptr[FrPOCR] & FrPOCR_BSY)) 
                {
                    /* Increment temporary counter */
                    i++;        
                }
                if(i == FR_MAX_WAIT_CYCLES) 
                {
                    /* Return FR_NOT_SUCCESS in case any error */
                    retVal = StatusErro;     
                }
                else
                {
                    /* API call has been successful */
                    retVal = StatusSuss;    
                }  
            }
        }
    }
    else
    {
        /* Return FR_NOT_SUCCESS in case any error */
        retVal = StatusErro;                                  
    }
    return retVal;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Stop_Communication
* Description:      This API call halts the communication of the FlexRay CC at the end
*                   of current FlexRay cycle in case that the FR_HALT_COMMUNICATION parameter is placed.
*                   The API call immediately aborts the communication of the FlexRay CC 
*                   in case that the FR_ABORT_COMMUNICATION parameter is placed
*
* Function arguments: 
*                   Fr_stop_option  FR_HALT_COMMUNICATION   - the API call halts the communication 
*                                               of the FlexRay CC at the end of current FlexRay cycle
*                                   FR_ABORT_COMMUNICATION  - the API call immediately aborts the 
*                                                             communication of the FlexRay CC
*
* Return value:
*                   StatusSuss        API call has been successful
*                   StatusErro    Error occured during transition 
*                                       into FR_POCSTATE_STARTUP
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Stop_Communication(VAR(Fr_stop_communication_type, FR_VAR) Fr_stop_option)
{
    /* Temporary counter */
    VAR(uint8, FR_VAR) i;                                    
    VAR(Fr_LLDriver_StatusType, FR_VAR) retVal = StatusSuss;
    /* Clear temporary counter */
    i = 0U;      
    /* Wait till Protocol Command Write is not busy */
    while((i < FR_MAX_WAIT_CYCLES) && (Fr_CC_reg_ptr[FrPOCR] & FrPOCR_BSY)) /* polyspace RTE:NIV */
    {
        /* Increment temporary counter */
        i++;        
    }
    if(i == FR_MAX_WAIT_CYCLES) 
    {
        /* Return FR_NOT_SUCCESS in case any error */
        retVal = StatusErro;      
    }
    else
    {
        switch(Fr_stop_option)
        {
        case FR_HALT_COMMUNICATION:
            /* Transition to halt state on completion of current comm. cycle */
            Fr_CC_reg_ptr[FrPOCR] = (FrPOCR_POCCMD_HALT  | FrPOCR_WME); 
            break;
        case FR_ABORT_COMMUNICATION:
        /* Immediately transition to halt state */
            Fr_CC_reg_ptr[FrPOCR] = (FrPOCR_POCCMD_FREEZE  | FrPOCR_WME);   
            break;
        default:
        /* Return FR_NOT_SUCCESS - wrong input parameter */
            retVal = StatusErro;                              
            break;
        }
        if(StatusErro != retVal)
        {
            /* Clear temporary counter */
            i = 0U;      
            /* Wait till Protocol Command Write is not busy */
            while((i < FR_MAX_WAIT_CYCLES) && (Fr_CC_reg_ptr[FrPOCR] & FrPOCR_BSY)) /* polyspace RTE:NIV */
            {
                /* Increment temporary counter */
                i++;        
            }
            if(i == FR_MAX_WAIT_CYCLES) 
            {
                /* Return FR_NOT_SUCCESS in case of any error */
                retVal = StatusErro;      
            }
        }
        
    }
/* API call has been successful */
    return retVal;                                      
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"


/************************************************************************************
* Function name:    Fr_send_wakeup
* Description:      This API call sends a Wakeup Pattern over configured channel
*
* Function arguments: 
*                   None
*
* Return value:
*                   StatusSuss        API call has been successful
*                   StatusErro    Error occured
*
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Send_Wakeup(VAR(void, FR_VAR))
{
    /* Temporary counter */
    VAR(uint8, FR_VAR) i;                                  
    /* Temporary variable used for bit operation */
    volatile VAR(uint16, FR_VAR) temp_value_1;              
    VAR(Fr_LLDriver_StatusType, FR_VAR) retVal = StatusSuss;
    
    temp_value_1 = (Fr_CC_reg_ptr[FrPSR0] & 0x0700U); /* polyspace RTE:NIV */    /* Load Protocol State field of the PSR0 reg. */
    
    if(temp_value_1 == FrPSR0_PROTSTATE_READY)  /* Is the FlexRay CC in the FR_POCSTATE_READY state? */
    {   /* Yes */
        /* Initiate wakeup procedure */
        i = 0U;      /* Clear temporary counter */
        while((i < FR_MAX_WAIT_CYCLES) && (Fr_CC_reg_ptr[FrPOCR] & FrPOCR_BSY)) /* polyspace RTE:NIV */ /* Wait till Protocol Command Write is not busy */
        {
            i++;        /* Increment temporary counter */
        }
        if(i == FR_MAX_WAIT_CYCLES) 
        {
            retVal = StatusErro;  /* Return FR_NOT_SUCCESS in case of any error */
        }
        else
        {
            Fr_CC_reg_ptr[FrPOCR] = (FrPOCR_POCCMD_WAKEUP  | FrPOCR_WME);       /* Immediately transition to the FR_POCSTATE_WAKEUP */
        
            i = 0U;      /* Clear temporary counter */
            while((i < FR_MAX_WAIT_CYCLES) && (Fr_CC_reg_ptr[FrPOCR] & FrPOCR_BSY)) /* Wait till Protocol Command Write is not busy */
            {
                i++;        /* Increment temporary counter */
            }
            if(i == FR_MAX_WAIT_CYCLES) 
            {
                retVal = StatusErro;  /* Return FR_NOT_SUCCESS in case of any error */
            }
            else
            {
                retVal = StatusSuss;  /* API call has been successful */
            }
        }
    }
    else
    {
        retVal = StatusErro;                              /* Return FR_NOT_SUCCESS in case of any error */
    }
    return retVal;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Get_Wakeup_State
* Description:      Retrieve the wakeup state of the FlexRay CC, 
*                   which is part of the startup of a FlexRay CC
*
* Function arguments: 
*                   None
*
* Return value:
*            FR_WAKEUP_UNDEFINED           Undefined
*            FR_WAKEUP_RECEIVED_HEADER     Received_Header
*            FR_WAKEUP_RECEIVED_WUP        Receiver_WUP
*            FR_WAKEUPSTATE_COLLOSION_HEADER    Collision_Header
*            FR_WAKEUP_COLLISION_WUP       Collision_WUP
*            FR_WAKEUP_COLLISION_UNKNOWN   Collision_Unknow
*            FR_WAKEUP_TRANSMITTED         Transmitted
*                   
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_WakeupStatusType, FR_CODE) Fr_LLD_Get_Wakeup_State(VAR(void, FR_VAR))
{
    volatile VAR(uint16, FR_VAR) temp_value_1 = 0U;           /* Temporary variable used for bit operation */
    VAR(Fr_WakeupStatusType, FR_VAR) retVal = FR_WAKEUP_UNDEFINED;
    /* Read current WAKEUPSTATUS */
    temp_value_1 = Fr_CC_reg_ptr[FrPSR0]; /* polyspace RTE:NIV */
    temp_value_1 &= 0x0007U;                     /* Select only WAKEUPSTATUS field */
    
    switch(temp_value_1)                        /* Test Protocol State */
    {
    case 0x0000U:                                /* FR_WAKEUP_UNDEFINED */
        retVal = FR_WAKEUP_UNDEFINED;        /* Return current Wakeup State */
        break;
    case FrPSR0_WAKEUPSTATUS_RECEIVED_HEADER:   /* FR_WAKEUP_RECEIVED_HEADER */
        retVal = FR_WAKEUP_RECEIVED_HEADER;  /* Return current Wakeup State */
        break;
    case FrPSR0_WAKEUPSTATUS_RECEIVED_WUP:      /* FR_WAKEUP_RECEIVED_WUP */
        retVal = FR_WAKEUP_RECEIVED_WUP;     /* Return current Wakeup State */
        break;
    case FrPSR0_WAKEUPSTATUS_COLLISION_HEADER:  /* FR_WAKEUP_COLLISION_HEADER */
        retVal = FR_WAKEUP_COLLISION_HEADER; /* Return current Wakeup State */
        break;
    case FrPSR0_WAKEUPSTATUS_COLLISION_WUP:     /* FR_WAKEUP_COLLISION_WUP */
        retVal = FR_WAKEUP_COLLISION_WUP;    /* Return current Wakeup State */
        break;
    case FrPSR0_WAKEUPSTATUS_COLLISION_UNKNOWN: /* FR_WAKEUP_COLLISION_UNKNOWN */
        retVal = FR_WAKEUP_COLLISION_UNKNOWN; /* Return current Wakeup State */
        break;
    case FrPSR0_WAKEUPSTATUS_TRANSMITTED:       /* FR_WAKEUP_TRANSMITTED */
        retVal = FR_WAKEUP_TRANSMITTED;      /* Return current Wakeup State */
        break;    
    default:
        retVal = FR_WAKEUP_UNDEFINED;
        break;
    }
    return retVal; /* FR_WAKEUP_UNDEFINED in case of any error */
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Get_POC_State
* Description:      Query the current value of the POC state of FlexRay CC
*
* Function arguments: 
*                   None
*
* Return value:
*                   FR_POCSTATE_CONFIG  Configuration state
*                   FR_POCSTATE_DEFAULT_CONFIG  State prior to config, only left with 
*                                   an explicit configuration request
*                   FR_POCSTATE_HALT    Error state, can only be left by a reinitialization
*                   FR_POCSTATE_NORMAL_ACTIVE  Normal operation
*                   FR_POCSTATE_NORMAL_PASSIVE  Errors detected, no transmission of data,
*                                   but attempting to return to normal operation
*                   FR_POCSTATE_READY   State reached from FR_POCSTATE_CONFIG after 
*                                   concluding the configuration
*                   FR_POCSTATE_STARTUP CC transmits only startup frames
*                   FR_POCSTATE_WAKEUP  CC sends a wakeup pattern if it couldnot find 
*                                   anything on the bus
*                   
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_POCStateType, FR_CODE) Fr_LLD_Get_POC_State(VAR(void, FR_VAR))
{
    volatile VAR(uint16, FR_VAR) temp_value_1 = 0U;           /* Temporary variable used for bit operation */
    VAR(Fr_POCStateType, FR_VAR) ret = FR_POCSTATE_CONFIG;
    /* The state of the PSR0 register (the PROSTATE field) is not updated if FREEZE occured */
    temp_value_1 = Fr_CC_reg_ptr[FrPSR1]; /* polyspace RTE:NIV,IDP */       /* Check if immediate halt due to FREEZE or internal error condition occured */
    if((temp_value_1 & FrPSR1_FRZ)   != 0U) 
    {
        ret = FR_POCSTATE_HALT;  /* The FlexRay module is in FR_POCSTATE_HALT state  */
    }
    else
    {
        /* Read current FR_POCSTATE */
        temp_value_1 = Fr_CC_reg_ptr[FrPSR0]; /* polyspace RTE:NIV */
        temp_value_1 &= 0x0700U;                     /* Select only PROSTATE field */
        
        switch(temp_value_1)                        /* Test Protocol State */
        {
        case FrPSR0_PROTSTATE_DEFAULT_CONFIG:       /* FR_POCSTATE_DEFAULT_CONFIG */
            ret = FR_POCSTATE_DEFAULT_CONFIG;      /* Return current Protocol State */
            break;
        case FrPSR0_PROTSTATE_CONFIG:               /* FR_POCSTATE_CONFIG */
            ret = FR_POCSTATE_CONFIG;              /* Return current Protocol State */
            break;
        case FrPSR0_PROTSTATE_WAKEUP:               /* FR_POCSTATE_WAKEUP */
            ret = FR_POCSTATE_WAKEUP;              /* Return current Protocol State */
            break;
        case FrPSR0_PROTSTATE_READY:                /* FR_POCSTATE_READY */
            ret = FR_POCSTATE_READY;               /* Return current Protocol State */
            break;
        case FrPSR0_PROTSTATE_NORMAL_PASSIVE:       /* FR_POCSTATE_READY */
            ret = FR_POCSTATE_NORMAL_PASSIVE;      /* Return current Protocol State */
            break;
        case FrPSR0_PROTSTATE_NORMAL_ACTIVE:        /* FR_POCSTATE_NORMAL_ACTIVE */
            ret = FR_POCSTATE_NORMAL_ACTIVE;       /* Return current Protocol State */
            break;
        case FrPSR0_PROTSTATE_HALT:                 /* FR_POCSTATE_HALT */
            ret = FR_POCSTATE_HALT;                /* Return current Protocol State */
            break;    
        case FrPSR0_PROTSTATE_STARTUP:              /* FR_POCSTATE_STARTUP */
            ret = FR_POCSTATE_STARTUP;             /* Return current Protocol State */
            break;
        default:
            break;
        }
    }
    
    return ret;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Enter_Configuration_Mode
* Description:      This API call determines in which POC state of the FlexRay protocol 
*                   and performs following sequences:
*                   - if the state of the protocol is FR_POCSTATE_HALT, the function sends 
*                     the DEFAULT_CONFIG command and later on the CONFIG command
*                   - if the state of the protocol is FR_POCSTATE_DEFAULT_CONFIG or FR_POCSTATE_READY,
*                     the function sends the the CONFIG command
*
*                   If the transition is not successful this API call returns StatusErro.
*
* Function arguments: 
*                   None
*
* Return value:
*                   StatusSuss        API call has been successful
*                   StatusErro    Error occured during transition 
*                                       into FR_POCSTATE_CONFIG
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Enter_Configuration_Mode(VAR(void, FR_VAR))
{
    VAR(uint8, FR_VAR) i;                                    /* Temporary counter */
    volatile VAR(uint16, FR_VAR) temp_value_1;               /* Temporary variable used for bit operation */
    volatile VAR(uint16, FR_VAR) temp_value_2;               /* Temporary variable used for bit operation */
    VAR(Fr_LLDriver_StatusType, FR_VAR) retVal = StatusSuss;
    
    temp_value_1 = (Fr_CC_reg_ptr[FrPSR0] & 0x0700U); /* polyspace RTE:NIV,IDP */    /* Load Protocol State field of the PSR0 reg. */
    temp_value_2 = Fr_CC_reg_ptr[FrPSR1]; /* polyspace RTE:NIV,IDP */               /* Load the PSR1 register - to check if freeze occured */
   
    /* Is the FlexRay CC in the FR_POCSTATE_HALT state? */
    /* Also check if immediate halt due to FREEZE or internal error condition occured */
    if((temp_value_1 == FrPSR0_PROTSTATE_HALT) || (temp_value_2 & FrPSR1_FRZ))
    {   /* Yes */
        
        /* Force the FlexRay CC into FR_POCSTATE_DEFAULT_CONFIG */
        i = 0U;      /* Clear temporary counter */
        while((i < FR_MAX_WAIT_CYCLES) && (Fr_CC_reg_ptr[FrPOCR] & FrPOCR_BSY)) /* polyspace RTE:NIV */ /* Wait till Protocol Command Write is not busy */
        {
            i++;        /* Increment temporary counter */
        }
        if(i == FR_MAX_WAIT_CYCLES) 
        {
            retVal = StatusErro;      /* Return StatusErro in case any error */
        }
        else
        {
            /* Immediately transition to the FR_POCSTATE_DEFAULT_CONFIG */
            Fr_CC_reg_ptr[FrPOCR] = (FrPOCR_POCCMD_DEFAULT_CONFIG  | FrPOCR_WME);   

            i = 0U;      /* Clear temporary counter */
            while((i < FR_MAX_WAIT_CYCLES) && (Fr_CC_reg_ptr[FrPOCR] & FrPOCR_BSY)) /* Wait till Protocol Command Write is not busy */
            {
                i++;        /* Increment temporary counter */
            }
            if(i == FR_MAX_WAIT_CYCLES)
            {
                retVal = StatusErro;      /* Return FR_NOT_SUCCESS in case any error */
            }
            else
            {
                i = 0U;      /* Clear temporary counter */
                /* Wait till the FlexRay CC is not in the FR_POCSTATE_DEFAULT_CONFIG */
                while((i < FR_MAX_WAIT_CYCLES) && ((Fr_CC_reg_ptr[FrPSR0] & 0x0700U) != FrPSR0_PROTSTATE_DEFAULT_CONFIG)) /* polyspace RTE:NIV */
                {
                    i++;        /* Increment temporary counter */
                }
                if(i == FR_MAX_WAIT_CYCLES) 
                {
                    retVal = StatusErro;      /* Return FR_NOT_SUCCESS in case any error */
                }
                else
                {
                    retVal = StatusSuss;
                    temp_value_1 = (Fr_CC_reg_ptr[FrPSR0] & 0x0700U); /* polyspace RTE:NIV */        /* Load Protocol State field of the PSR0 reg. */
                }
            }
        }
        
    }
    if( StatusErro != retVal)
    {
        /* Is the FlexRay CC in the FR_POCSTATE_DEFAULT_CONFIG or FR_POCSTATE_READY state? */
        if((temp_value_1 == FrPSR0_PROTSTATE_DEFAULT_CONFIG) || (temp_value_1 == FrPSR0_PROTSTATE_READY))
        {   /* Yes */
            
            /* Force the FlexRay CC into FR_POCSTATE_CONFIG */
            i = 0U;      /* Clear temporary counter */
            while((i < FR_MAX_WAIT_CYCLES) && (Fr_CC_reg_ptr[FrPOCR] & FrPOCR_BSY)) /* polyspace RTE:NIV */ /* Wait till Protocol Command Write is not busy */
            {
                i++;        /* Increment temporary counter */
            }
            if(i == FR_MAX_WAIT_CYCLES) 
            {   
                retVal = StatusErro;      /* Return FR_NOT_SUCCESS in case any error */
            }
            else
            {
                Fr_CC_reg_ptr[FrPOCR] = (FrPOCR_POCCMD_CONFIG  | FrPOCR_WME);   /* Immediately transition to the FR_POCSTATE_CONFIG */
                
                i = 0U;      /* Clear temporary counter */
                while((i < FR_MAX_WAIT_CYCLES) && (Fr_CC_reg_ptr[FrPOCR] & FrPOCR_BSY)) /* Wait till Protocol Command Write is not busy */
                {
                    i++;        /* Increment temporary counter */
                }
                if(i == FR_MAX_WAIT_CYCLES) 
                {
                    retVal = StatusErro;      /* Return FR_NOT_SUCCESS in case any error */
                }
                else
                {
                    /* Wait till FlexRay CC is in FR_POCSTATE_CONFIG */
                    i = 0U;      /* Clear temporary counter */
                    while((i < FR_MAX_WAIT_CYCLES) && ( (Fr_CC_reg_ptr[FrPSR0] & 0x0700U) != FrPSR0_PROTSTATE_CONFIG)) /* polyspace RTE:NIV */
                    {
                        i++;        /* Increment temporary counter */
                    }
                    if(i == FR_MAX_WAIT_CYCLES) 
                    {
                        retVal = StatusErro;      /* Return FR_NOT_SUCCESS in case any error */
                    }
                    else
                    {
                        retVal = StatusSuss;
                    }
                }
            }
        } 
        else    /* The protocol status is not in FR_POCSTATE_DEFAULT_CONFIG or FR_POCSTATE_READY      */
        {
            retVal = StatusErro;      /* Return FR_NOT_SUCCESS - inappropriate state of protocol */
        }
    }
    
        
    return retVal;                                      /* API call has been successful */
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Get_Global_Time
* Description:      Query the global time (current cycle and macrotick values) of the FlexRay cluster
*
* Function arguments: 
*                   Fr_cycle_ptr    Reference to a memory location where the current 
*                                   FlexRay communication cycle value will be stored
*                   Fr_macrotick_ptr    Reference to a memory location where the current 
*                                   FlexRay communication macrotick value will be stored
*
* Return value:
*                   none
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_LLD_Get_Global_Time(P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_cycle_ptr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_macrotick_ptr)
{
    *Fr_macrotick_ptr = Fr_CC_reg_ptr[FrMTCTR]; /* polyspace RTE:NIV,IDP */     /* Store the current macrotick value */
    *Fr_cycle_ptr = (VAR(uint8, AUTOMATIC))(Fr_CC_reg_ptr[FrCYCTR]); /* polyspace RTE:NIV,IDP */    /* Store the current cycle value */
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Get_Network_Management_Vector
* Description:      Get the vector managment vectors and copy to memory location given by reference
*
* Function arguments: 
*                   Fr_vector_ptr   This reference points to a array where the network 
*                                   management vectors shall be stored
*
* Return value:
*                   none
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_LLD_Get_Network_Management_Vector(P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_vector_ptr)
{
    volatile VAR(uint16, FR_VAR) temp_value_1;               /* Temporary variable used for bit operation */
    volatile VAR(uint16, FR_VAR) temp_value_2;               /* Temporary variable used for bit operation */
    VAR(boolean, AUTOMATIC) bDataCons = FALSE;
    VAR(uint8, AUTOMATIC) ReadCnt = F_MAX_NMVREAD_CNT;
    VAR(uint8, FR_VAR) Fr_p;                                 /* Temporary counter used for copying     */
    VAR(Std_ReturnType, FR_VAR) retVal = E_NOT_OK;  
    
    temp_value_1 = Fr_CC_reg_ptr[FrNMVLR]; /* polyspace RTE:NIV,IDP */      /* Load network management vector length (in Bytes) */
    temp_value_2 = temp_value_1 / 2U;            /* Divide the length by 2 - conversion Bytes -> Words */
    
    if((temp_value_1 & 0x0001U)   != 0U)                  /* Is the length the odd number? */
    {   /* The length is odd number -> it is necessary to read another vector */
        temp_value_2 = (uint16)(1U + temp_value_2);                         /* Increment the number of loaded vectors by 1 (in Words) */
    }
    

    while((VAR(boolean, AUTOMATIC))(ReadCnt) > 0U)
    {
        /* assume that data are consistent. If not so, this value will be updated */
        bDataCons = (VAR(boolean, AUTOMATIC))TRUE;
        /* Copy all network management vector items */
        for (Fr_p = 0; Fr_p < temp_value_2; ++Fr_p)
        {
            /* Check if data are consistent or need to be updated */ 
            if((Fr_vector_ptr[Fr_p*2U] != (VAR(uint8, AUTOMATIC))(Fr_CC_reg_ptr[FrNMVR0+ Fr_p] >> 8))||(Fr_vector_ptr[Fr_p*2U + 1U] != (VAR(uint8, AUTOMATIC))(Fr_CC_reg_ptr[FrNMVR0 + Fr_p] & 0xFFU))) /* polyspace RTE:NIV,IDP */
            {
                Fr_vector_ptr[Fr_p*2U] = (VAR(uint8, AUTOMATIC))(Fr_CC_reg_ptr[FrNMVR0+ Fr_p] >> 8); /* polyspace RTE:NIV */ /* Store the high byte */
                Fr_vector_ptr[Fr_p*2U + 1U] = (VAR(uint8, AUTOMATIC))(Fr_CC_reg_ptr[FrNMVR0 + Fr_p] & 0xFFU); /* polyspace RTE:NIV */ /* Store the low byte */
                /* Indicate data inconsitency => another check is required */
                bDataCons = (VAR(boolean, AUTOMATIC))FALSE;
            }
            
        }
        ReadCnt--;
        if ((VAR(boolean, AUTOMATIC))TRUE == bDataCons)
        {/* Data is consistent */
            retVal = (VAR(Std_ReturnType, AUTOMATIC))E_OK; /* API call was successful */
            break;
        }
    }

    return retVal;
    
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Transmit_Data
* Description:      This function is used to transmit a data from given memory array. 
*                   If Fr_data_length is zero, the function determines (reads) the length 
*                   of the data directly from the FlexRay CC. If the FlexRay driver detects 
*                   that it cannot lock the message buffer, the FR_TXMB_NO_ACCESS parameter 
*                   shall be returned. The function clears the message buffer interrupt 
*                   flag even if the buffer has not been updated or locked
*
* Function arguments: 
*                   Fr_buffer_idx   This index is used to select a transmit/receive message 
*                                   buffer of FlexRay CC
*                   Fr_data_ptr     This reference points to a array where the data to be transmitted 
*                                   is stored
*                   Fr_data_length  Determines the length of the data to be transmitted. 
*                                   If Fr_data_length is zero, the function determines (reads)
*                                   the length of the data directly from the FlexRay CC
* Return value:
*                   FR_TXMB_UPDATED The transmit message buffer has been successfully updated 
*                                   with new data
*                   FR_TXMB_NO_ACCESS   The transmit message buffer has not been 
*                                   successfully locked
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_tx_MB_status_type, FR_CODE) Fr_LLD_Transmit_Data(VAR(uint16, FR_VAR) Fr_buffer_idx, P2CONST(uint8, AUTOMATIC, FR_APPL_CONST) Fr_data_ptr, VAR(uint8, FR_VAR) Fr_data_length)
{
    volatile P2CONST(uint16, AUTOMATIC, FR_APPL_CONST) header_MB_ptr;        /* Message buffer header pointer */
    volatile P2VAR(uint16, AUTOMATIC, FR_APPL_CONST)  Fr_CC_data_ptr;       /* Reference to data array */
    volatile VAR(uint16, FR_VAR) temp_value_1 = 0U;
    volatile VAR(uint16, FR_VAR) temp_value_2 = 0U; /* Temporary variables used for bit operation */
    volatile VAR(uint16, FR_VAR) temp_value_3 = 0U; /* Temporary variables used for bit operation */
    volatile VAR(uint16, FR_VAR) Fr_MB_registers_offset_add_temp; /* Temporary offset adress of message buffer registers */
    VAR(uint16, FR_VAR) Fr_p;                                        /* Temporary counter used for copying */
    VAR(Fr_tx_MB_status_type, FR_VAR) retval = FR_TXMB_UPDATED;

    /* Temporary offset address of MB registers */
    Fr_MB_registers_offset_add_temp = (VAR(uint16, AUTOMATIC))(Fr_buffer_idx * 4U);

    /* Read the MB Configuration, Control and Status reg. */
    /* Load MBCCSRn register and select only necessary bits */
    temp_value_1 = (Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] & 0xF900U); /* polyspace RTE:NIV,IDP */
    temp_value_1 |= FrMBCCSR_LCKT;              /* Set Lock Trigger bit */
    Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] = temp_value_1; /* polyspace RTE:IDP */  /* Lock MB */
    
    /* Read the MB again for checking if the MB is locked */
    temp_value_2 = Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp]; /* polyspace RTE:NIV,IDP */
    if((temp_value_2 & FrMBCCSR_LCKS)  != 0U)            /* Is the MB locked? */
    {                                           /* Yes */
        /* Load current MB index */
        temp_value_3 = Fr_CC_reg_ptr[FrMBIDXR0 + Fr_MB_registers_offset_add_temp]; /* polyspace RTE:NIV,IDP */

        /* Calculate the message buffer header */
        header_MB_ptr = ((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) )(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + (temp_value_3 * 4U)); /* polyspace RTE:IDP */
        /* Calculate MB Data pointer */
        Fr_CC_data_ptr = ((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA))(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + (Fr_CC_reg_ptr[FrMBDOR0 + (Fr_MB_registers_offset_add_temp/4U)]/2U)); /* polyspace RTE:NIV,IDP */

        /* Test if given data length is not zero, then read length from  */
        if(Fr_data_length == 0U)
        {
            Fr_data_length = (VAR(uint8, AUTOMATIC))((header_MB_ptr[1U] & 0x007FU)<<1U); /* polyspace RTE:NIV,IDP */   /* Load the data payload length value from Frame header register */
        }
        
        /* Copy data */
        for (Fr_p = 0; Fr_p < Fr_data_length; Fr_p = (VAR(uint16, AUTOMATIC))(2U + Fr_p))
        { 
            Fr_CC_data_ptr[Fr_p / 2U] = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_data_ptr[Fr_p] << 8); /* polyspace RTE:IDP */
            if (Fr_p + 1U < Fr_data_length)
            { 
                Fr_CC_data_ptr[Fr_p / 2U] = (VAR(uint16, AUTOMATIC))(Fr_data_ptr[Fr_p + 1U] | Fr_CC_data_ptr[Fr_p / 2U]);
            } 
            else 
            { 
                Fr_CC_data_ptr[Fr_p / 2U] |= 0x00U; 
                /* Padding with 0 if Fr_LSduLength is odd  */
            } 
        } 
        
        /* Set MB to commit */
        /* Load MBCCSRn register and select only necessary bits */
        SchM_Enter_Fr_EXCLUSIVE_AREA_05();
        temp_value_1 = (Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] & 0xF900U); /* polyspace RTE:NIV,IDP */
        temp_value_1 |= (FrMBCCSR_CMT | FrMBCCSR_MBIF);
        Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] = temp_value_1; /* polyspace RTE:IDP */
        SchM_Exit_Fr_EXCLUSIVE_AREA_05();
        
        /* Attempt to unlock MB */
        /* Load MBCCSRn register and select only necessary bits */
        temp_value_1 = (Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] & 0xF900U); /* polyspace RTE:NIV,IDP */
        temp_value_1 |= FrMBCCSR_LCKT;      /* Trigger lock/unlock */
        Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] = temp_value_1; /* polyspace RTE:IDP */
    }
    else
    {
        /* Clear Transmit Buffer Interrupt Flag     */
        /* Read MBCCSRn and select only necessary bits */
        SchM_Enter_Fr_EXCLUSIVE_AREA_05();
        temp_value_2 = (Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] & 0xF900U); /* polyspace RTE:NIV,IDP */
        temp_value_2 |= FrMBCCSR_MBIF;          /* Set MBIF flag - clear TX MB interrupt flag  */
        Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] = temp_value_2; /* polyspace RTE:IDP */  /* Clear Transmit Buffer Interrupt Flag */
        SchM_Exit_Fr_EXCLUSIVE_AREA_05();
        retval =  FR_TXMB_NO_ACCESS;       /* The transmit MB has not been successfully locked */
    }
    return retval;                 /* The transmit MB has been updated with new data */
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Receive_Data
* Description:      This function is used to receive a data and copy to given memory array. 
*                   If a data has been successfully received, tha data will be copied 
*                   to the buffer referenced by Fr_data_ptr and FR_RECEIVED parameter 
*                   will be returned.
*                   If a data has not been received, no copying will take place to the 
*                   message aray referenced by Fr_data_ptr and FR_NOT_RECEIVED parameter 
*                   will be returned.
*                   If a Nullframe has been received, no copying will take place to the 
*                   message aray referenced by Fr_data_ptr, FR_RXMB_NULL_FRAME_RECEIVED parameter 
*                   will be returned and the length will be stored in Fr_data_length.
*                   If the FlexRay driver detects that it cannot lock the message buffer, 
*                   the FR_NOT_RECEIVED parameter shall be returned.
*                   The function clears the message buffer interrupt flag
*
* Function arguments: 
*                   Fr_buffer_idx   This index is used to select a transmit/receive message 
*                                   buffer of FlexRay CC
*                   Fr_data_ptr     This reference points to a array where the data to be 
*                                   received shall be stored
*                   Fr_data_length_ptr  This reference points to the memory location where 
*                                   the length of received data shall be stored
*                   Fr_slot_status_ptr  This reference points to the memory location where 
*                                   the slot status of received data shall be stored
* Return value:
*                   FR_RECEIVED Data has been received
*                   FR_NOT_RECEIVED Data has not been received
*                   FR_RXMB_NULL_FRAME_RECEIVED Received frame is a NULL frame
*                   FR_NOT_RECEIVED The receive message buffer has not been successfully locked
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_RxLPduStatusType, FR_CODE) Fr_LLD_Receive_Data(VAR(uint16, FR_VAR) Fr_buffer_idx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_ptr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_length_ptr,P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) Fr_SlotAssignmentPtr)
{
    volatile P2CONST(uint16, AUTOMATIC, FR_APPL_CONST)  header_MB_ptr;    /* Message buffer header pointer */
    volatile P2CONST(uint16, AUTOMATIC, FR_APPL_CONST)  Fr_CC_data_ptr;   /* Reference to data array */
    volatile VAR(uint16, FR_VAR) temp_value_1 = 0U;           /* Temporary variable used for bit operation */
    volatile VAR(uint16, FR_VAR) temp_value_2 = 0U;           /* Temporary variable used for bit operation */
    volatile VAR(uint16, FR_VAR) temp_value_3 = 0U;           /* Temporary variable used for bit operation */
    volatile VAR(uint16, FR_VAR) temp_value_4 = 0U;           /* Temporary variable used for bit operation */
    volatile VAR(uint16, FR_VAR) Fr_MB_registers_offset_add_temp; /* Temporary offset adress of message buffer registers */
    volatile VAR(uint8, FR_VAR) Fr_data_length;              /* Data payload length */
    VAR(Fr_RxLPduStatusType, FR_VAR) retRxStus = FR_NOT_RECEIVED;
    VAR(uint16, FR_VAR) Fr_p;                                /* Temporary counter used for copying */
    #if(FR_RX_STRINGENT_LENGTH_CHECK == STD_ON)
    VAR(boolean, AUTOMATIC) bStatusVal = (VAR(boolean, AUTOMATIC))TRUE;
    #endif /* FR_RX_STRINGENT_LENGTH_CHECK == STD_ON */

    /* Temporary offset address of MB registers */
    Fr_MB_registers_offset_add_temp = (VAR(uint16, AUTOMATIC))(Fr_buffer_idx * 4U);
    /* Read the MB again for checking if the MB is locked */
    temp_value_2 = Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp]; /* polyspace RTE:NIV,IDP */
    
    
    /* If DUP == 1 : Frame header and MB data field updated */
    if(((VAR(uint8, AUTOMATIC))(FrMBCCSR_DUP | FrMBCCSR_MBIF))
            == (temp_value_2 & ((VAR(uint16, AUTOMATIC)) (FrMBCCSR_DUP | FrMBCCSR_MBIF)))
        )
    {   /* Yes, Valid non-null frame received */
        /* Calculate MB Data pointer */
        /* Read the MB Configuration, Control and Status reg. */
        temp_value_1 = Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp]; /* polyspace RTE:NIV,IDP */
        temp_value_1 |= FrMBCCSR_LCKT;      /* Set Lock Trigger bit */
        Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] = temp_value_1; /* polyspace RTE:IDP */  /* Lock MB */
        temp_value_1 = Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp]; /* polyspace RTE:NIV,IDP */
        if((temp_value_1 & FrMBCCSR_LCKS)  != 0U)            /* Is the MB locked? */
        {

            /* Load current MB index */
            temp_value_4 = Fr_CC_reg_ptr[FrMBIDXR0 + Fr_MB_registers_offset_add_temp]; /* polyspace RTE:NIV,IDP */

            /* Calculate the message buffer header */
            header_MB_ptr = ((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA))(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + (temp_value_4 * 4U)); /* polyspace RTE:IDP */

            /* Read Slot Status */
            temp_value_2 = header_MB_ptr[3U]; /* polyspace RTE:NIV,IDP */        /* Load Slot Status Information */

            if (NULL_PTR != Fr_SlotAssignmentPtr)
            {
       
                /* copy cycle of the frame to Fr_SlotAssignment*/
                Fr_SlotAssignmentPtr->Cycle = (VAR(uint8, AUTOMATIC))((header_MB_ptr[1U] & 0x3F00U) >> 8U); /* polyspace RTE:NIV,IDP */
                /* copy slot ID of the frame to Fr_SlotAssignment*/
                Fr_SlotAssignmentPtr->SlotId = (VAR(uint16, AUTOMATIC))(header_MB_ptr[0U] & 0x07FFU); /* polyspace RTE:NIV,IDP */
            }
            Fr_CC_data_ptr = ((volatile uint16 * )(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + (Fr_CC_reg_ptr[FrMBDOR0 + (Fr_MB_registers_offset_add_temp/4U)] / 2U)); /* polyspace RTE:NIV,IDP */

            /* Load data length from Frame header reg. */
            Fr_data_length = (VAR(uint8, AUTOMATIC))(header_MB_ptr[1U] & 0x007FU); /* polyspace RTE:NIV */   /* Load the data payload length value from Frame header register */
            
            
            if( Fr_data_length > (VAR(uint8, AUTOMATIC))Fr_MB_information_internal[Fr_buffer_idx].FrifLsduLength)
            {
                #if(FR_RX_STRINGENT_LENGTH_CHECK == STD_OFF)
                Fr_data_length = (VAR(uint8, AUTOMATIC))Fr_MB_information_internal[Fr_buffer_idx].FrifLsduLength;
                #else
                *Fr_data_length_ptr = 0;
                retRxStus = FR_NOT_RECEIVED;
                bStatusVal = FALSE;
                #endif
            }
            #if(FR_RX_STRINGENT_LENGTH_CHECK == STD_ON)
            if ((VAR(boolean, AUTOMATIC))TRUE == bStatusVal)
            {
            #endif
                /* Copy data */
                for (Fr_p = 0; Fr_p < Fr_data_length; ++Fr_p)
                {
                    Fr_data_ptr[Fr_p * 2U] = (VAR(uint8, AUTOMATIC))(Fr_CC_data_ptr[Fr_p] >> 8); /* polyspace RTE:NIV,IDP */ /* Store the high byte */
                    Fr_data_ptr[Fr_p * 2U + 1U] = (VAR(uint8, AUTOMATIC))(Fr_CC_data_ptr[Fr_p] & 0xFFU); /* polyspace RTE:NIV */ /* Store the low byte */
                }

                temp_value_3 = Fr_CC_reg_ptr[FrMBCCFR0 + Fr_MB_registers_offset_add_temp]; /* polyspace RTE:NIV,IDP */

                if ((FrMBCCFR_CHA == (temp_value_3 & FrMBCCFR_CHA)) && (FrMBCCFR_CHB == (temp_value_3 & FrMBCCFR_CHB)))
                {
                    /* MB is assigned to channels AB */
                    Fr_SlotAssignmentPtr->channelId = FR_CHANNEL_AB;                
                    /* Check Slot Status information */
                    if ((0x0080U == (temp_value_2 & FLEXRAY_STRINGENT_MASK_A)) || (0x8000U ==(temp_value_2 & FLEXRAY_STRINGENT_MASK_B)))
                    {
                        /* channel receive data */
                        retRxStus = FR_RECEIVED;
                    }
                }
                else if (FrMBCCFR_CHA == (temp_value_3 & FrMBCCFR_CHA))
                {
                    /* MB is assigned to channel A */
                    Fr_SlotAssignmentPtr->channelId = FR_CHANNEL_A;
                    /* Check Slot Status information */
                    if (0x0080U == (temp_value_2 & FLEXRAY_STRINGENT_MASK_A))
                    {
                        /* channel receive data */
                        retRxStus = FR_RECEIVED;
                    }
                }
                else
                {
                    /* MB is assigned to channel B */
                    Fr_SlotAssignmentPtr->channelId = FR_CHANNEL_B;
                    /* Check Slot Status information */
                    if (0x8000U == (temp_value_2 & FLEXRAY_STRINGENT_MASK_B))
                    {
                        /* channel receive data */
                        retRxStus = FR_RECEIVED;
                    }
                }
            #if(FR_RX_STRINGENT_LENGTH_CHECK == STD_ON)
            }
            #endif
            /* Clear Receive Buffer Interrupt Flag     */
            SchM_Enter_Fr_EXCLUSIVE_AREA_06();
            temp_value_1 = Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp]; /* polyspace RTE:NIV,IDP */                 /* Select only necessary bits     */
            temp_value_1 |= FrMBCCSR_MBIF;          /* Set MBIF flag - clear RX MB interrupt flag  */
            Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] = temp_value_1; /* polyspace RTE:IDP */  /* Clear Transmit Buffer Interrupt Flag */
            SchM_Exit_Fr_EXCLUSIVE_AREA_06();
            /* Attempt to unlock MB */
            /* Read the MBCCSRn register and select only necessary bits */
            temp_value_1 = (Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] & 0xF900U); /* polyspace RTE:NIV,IDP */
            temp_value_1 |= FrMBCCSR_LCKT;
            Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] = temp_value_1; /* polyspace RTE:IDP */
            
            *Fr_data_length_ptr = (VAR(uint8, AUTOMATIC))(Fr_data_length<<1);   /* Store length into Fr_data_length_ptr */
        }
    }
    else
    {
        /* Clear Receive Buffer Interrupt Flag     */
        *Fr_data_length_ptr = 0;
        retRxStus = FR_NOT_RECEIVED;
        SchM_Enter_Fr_EXCLUSIVE_AREA_06();
        temp_value_1 = Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp]; /* polyspace RTE:NIV,IDP */                 /* Select only necessary bits     */
        temp_value_1 |= FrMBCCSR_MBIF;          /* Set MBIF flag - clear RX MB interrupt flag  */
        Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp] = temp_value_1; /* polyspace RTE:IDP */  /* Clear Transmit Buffer Interrupt Flag */
        SchM_Exit_Fr_EXCLUSIVE_AREA_06();
        
    }
    
    return retRxStus;                /* The receive MB has been updated with new data */
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Receive_Fifo_Data
* Description:      This function is used to receive a data and copy to given memory array. 
*                   If a data has been successfully received, tha data will be copied to the buffer 
*                   referenced by Fr_data_ptr and FR_FIFO_RECEIVED parameter will be returned.
*                   If a data has not been received, no copying will take place to the message 
*                   aray referenced by Fr_data_ptr and FR_FIFO_NOT_RECEIVED parameter will be returned.
*                   
* Function arguments: 
*                   Fr_buffer_read_idx      This index is used to select next available receive 
*                                           FIFO message buffer that the application can read
*                   Fr_data_ptr             This reference points to a array where the data to be 
*                                           received shall be stored
*                   Fr_data_length          This reference points to the memory location where 
*                                           the length of received data shall be stored
*                   Fr_slot_idx_ptr         This reference points to the memory location where 
*                                           the received frame ID will be stored
*                   Fr_slot_status          This reference points to the memory location where 
*                                           the slot status of received data shall be stored
* Return value:
*                   FR_FIFO_RECEIVED        Data has been received
*                   FR_FIFO_NOT_RECEIVED    Data has not been received
*                   
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_FIFO_status_type, FR_CODE) Fr_LLD_Receive_FifoA_Data(P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_ptr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_length_ptr, P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) Fr_SlotAssignmentPtr)
{
    volatile P2CONST(uint16, AUTOMATIC, FR_APPL_CONST)  header_MB_ptr;    /* Message buffer header pointer */
    volatile P2CONST(uint16, AUTOMATIC, FR_APPL_CONST)  Fr_CC_data_ptr;   /* Reference to data array */
    volatile VAR(uint16, FR_VAR) temp_value_1 = 0U;           /* Temporary variable used for bit operation */
    volatile VAR(uint16, FR_VAR) temp_value_2 = 0U;           /* Temporary variable used for bit operation */
    volatile VAR(uint8, FR_VAR) Fr_data_length = 0U;              /* Data payload length */
    volatile VAR(uint16, FR_VAR) Fr_buffer_read_idx = 0U;
    VAR(boolean, FR_VAR) bReceive = FALSE;
    VAR(Fr_FIFO_status_type, FR_VAR) retval = FR_FIFO_NOT_RECEIVED;
    #if(FR_RX_STRINGENT_LENGTH_CHECK == STD_ON)
    VAR(boolean, AUTOMATIC) bStatusVal = (VAR(boolean, AUTOMATIC))TRUE;
    #endif /* FR_RX_STRINGENT_LENGTH_CHECK == STD_ON */

    VAR(uint16, FR_VAR) Fr_p;                                /* Temporary counter used for copying */
    Fr_buffer_read_idx = (Fr_CC_reg_ptr[FrRFARIR] & 0x03FFU); /* polyspace RTE:NIV,IDP */
    /* Calculate the message buffer header */
    header_MB_ptr = ((volatile uint16 * )(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + (Fr_buffer_read_idx * 4U)); /* polyspace RTE:IDP */

    /* Read Slot Status */
    temp_value_1 = header_MB_ptr[0U]; /* polyspace RTE:NIV,IDP */                /* Load MB header field */
    temp_value_2 = header_MB_ptr[3U]; /* polyspace RTE:NIV,IDP */                /* Load Slot Status Information */

    if (NULL_PTR != Fr_SlotAssignmentPtr)
    {

        Fr_SlotAssignmentPtr->channelId = FR_CHANNEL_A;
        /* copy cycle of the frame to Fr_SlotAssignment*/
        Fr_SlotAssignmentPtr->Cycle = (VAR(uint8, AUTOMATIC))((header_MB_ptr[1U] & 0x3F00U) >> 8U); /* polyspace RTE:NIV */
        /* copy slot ID of the frame to Fr_SlotAssignment*/
        Fr_SlotAssignmentPtr->SlotId = (VAR(uint16, AUTOMATIC))(header_MB_ptr[0U] & 0x07FFU); /* polyspace RTE:NIV */
    }
    if(FrGIFER_FNEAIF == (Fr_CC_reg_ptr[FrGIFER] & FrGIFER_FNEAIF)) /* polyspace RTE:NIV */
    {  
        /* If NUF == 1 : Null frame received */
        if((temp_value_1 & FrF_HEADER_NUF)  != 0U)               /* Valid non-null frame received? */
        {   /* Yes, Valid non-null frame received */
            /* Calculate MB Data pointer */

            temp_value_2 = (VAR(uint16, AUTOMATIC))((Fr_CC_reg_ptr[FrRFDSR] & 0x007FU) * 2U); /* polyspace RTE:NIV */
            Fr_CC_data_ptr = ((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) )(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + ((Fr_CC_reg_ptr[FrRFSDOR]+(temp_value_2 * (Fr_CC_reg_ptr[FrRFARIR] - Fr_CC_reg_ptr[FrRFSIR]))) / 2U)); /* polyspace RTE:NIV,OVFL,IDP */

            /* Load data length from Frame header reg. */
            Fr_data_length = (VAR(uint8, AUTOMATIC))(header_MB_ptr[1U] & 0x007FU); /* polyspace RTE:NIV */   /* Load the data payload length value from Frame header register */
            
            if( Fr_data_length > Fr_FIFO_info.FIFO_1_entry_size)
            {
                #if(FR_RX_STRINGENT_LENGTH_CHECK == OFF)
                Fr_data_length = Fr_FIFO_info.FIFO_1_entry_size;
                #else
                *Fr_data_length_ptr = 0;
                retval = FR_FIFO_NOT_RECEIVED;
                bStatusVal = FALSE;
                #endif
            }
            
            #if(FR_RX_STRINGENT_LENGTH_CHECK == STD_ON)
            if ((VAR(boolean, AUTOMATIC))TRUE == bStatusVal)
            {
            #endif
                /* Copy data */
                for (Fr_p = 0; Fr_p < Fr_data_length; ++Fr_p)
                {
                    Fr_data_ptr[Fr_p * 2U] = (VAR(uint8, AUTOMATIC))(Fr_CC_data_ptr[Fr_p] >> 8); /* polyspace RTE:NIV,IDP */ /* Store the high byte */
                    Fr_data_ptr[Fr_p * 2U + 1U] = (VAR(uint8, AUTOMATIC))(Fr_CC_data_ptr[Fr_p] & 0xFFU); /* polyspace RTE:NIV */ /* Store the low byte */
                }
                /* Stringent check for FIFO A */
                if (0x0080U == ((header_MB_ptr[3]) & FLEXRAY_STRINGENT_MASK_A)) /* polyspace RTE:NIV */
                {
                    bReceive = TRUE;
                }
            #if(FR_RX_STRINGENT_LENGTH_CHECK == STD_ON)
            }
            #endif
        }
        if(bReceive == TRUE)
        {
            *Fr_data_length_ptr = (VAR(uint8, AUTOMATIC))(Fr_data_length<<1);           /* Store length into Fr_data_length_ptr */
            SchM_Enter_Fr_EXCLUSIVE_AREA_13();
            temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_CC_reg_ptr[FrGIFER] ); /* polyspace RTE:NIV */
            temp_value_1 |= FrGIFER_FNEAIF;
            Fr_CC_reg_ptr[FrGIFER] = temp_value_1;
            SchM_Exit_Fr_EXCLUSIVE_AREA_13();
            retval = FR_FIFO_RECEIVED;                        /* The receive FIFO MB has been updated with new data */
        }
        else
        {
            *Fr_data_length_ptr = 0U;  
            SchM_Enter_Fr_EXCLUSIVE_AREA_13();
            temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_CC_reg_ptr[FrGIFER] ); /* polyspace RTE:NIV */
            temp_value_1 |= FrGIFER_FNEAIF;
            Fr_CC_reg_ptr[FrGIFER] = temp_value_1;
            SchM_Exit_Fr_EXCLUSIVE_AREA_13();
            retval = FR_FIFO_NOT_RECEIVED;
        }
    }
    else
    {
        *Fr_data_length_ptr = 0U;  
        retval = FR_FIFO_NOT_RECEIVED;
    }
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_FIFO_status_type, FR_CODE) Fr_LLD_Receive_FifoB_Data(P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_ptr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_length_ptr, P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) Fr_SlotAssignmentPtr)
{
    volatile P2CONST(uint16, AUTOMATIC, FR_APPL_CONST)  header_MB_ptr;    /* Message buffer header pointer */
    volatile P2CONST(uint16, AUTOMATIC, FR_APPL_CONST)  Fr_CC_data_ptr;   /* Reference to data array */
    volatile VAR(uint16, FR_VAR) temp_value_1 = 0U;           /* Temporary variable used for bit operation */
    volatile VAR(uint16, FR_VAR) temp_value_2 = 0U;           /* Temporary variable used for bit operation */
    volatile VAR(uint8, FR_VAR) Fr_data_length;              /* Data payload length */
    volatile VAR(uint16, FR_VAR) Fr_buffer_read_idx = 0U;
    VAR(boolean, FR_VAR) bReceive = FALSE;
    VAR(Fr_FIFO_status_type, FR_VAR) retval = FR_FIFO_NOT_RECEIVED;
    #if(FR_RX_STRINGENT_LENGTH_CHECK == STD_ON)
    VAR(boolean, AUTOMATIC) bStatusVal = (VAR(boolean, AUTOMATIC))TRUE;
    #endif /* FR_RX_STRINGENT_LENGTH_CHECK == STD_ON */

    VAR(uint16, FR_VAR) Fr_p;                                /* Temporary counter used for copying */
    Fr_buffer_read_idx = (Fr_CC_reg_ptr[FrRFBRIR] & 0x03FFU); /* polyspace RTE:NIV,IDP */
    /* Calculate the message buffer header */
    header_MB_ptr = ((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) )(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + (Fr_buffer_read_idx * 4U)); /* polyspace RTE:IDP */

    /* Read Slot Status */
    temp_value_1 = header_MB_ptr[0U]; /* polyspace RTE:NIV,IDP */                /* Load MB header field */
    temp_value_2 = header_MB_ptr[3U]; /* polyspace RTE:NIV,IDP */                /* Load Slot Status Information */

    if (NULL_PTR != Fr_SlotAssignmentPtr)
    {

        Fr_SlotAssignmentPtr->channelId = FR_CHANNEL_A;
        /* copy cycle of the frame to Fr_SlotAssignment*/
        Fr_SlotAssignmentPtr->Cycle = (VAR(uint8, AUTOMATIC))((header_MB_ptr[1U] & 0x3F00U) >> 8U); /* polyspace RTE:NIV */
        /* copy slot ID of the frame to Fr_SlotAssignment*/
        Fr_SlotAssignmentPtr->SlotId = (VAR(uint16, AUTOMATIC))(header_MB_ptr[0U] & 0x07FFU); /* polyspace RTE:NIV */
    }

    if(FrGIFER_FNEBIF == (Fr_CC_reg_ptr[FrGIFER] & FrGIFER_FNEBIF)) /* polyspace RTE:NIV */
    {  
        /* If NUF == 1 : Null frame received */
        if((temp_value_1 & FrF_HEADER_NUF)  != 0U)               /* Valid non-null frame received? */
        {   /* Yes, Valid non-null frame received */
            /* Calculate MB Data pointer */

            temp_value_2 = (VAR(uint16, AUTOMATIC))((Fr_CC_reg_ptr[FrRFDSR] & 0x007FU) * 2U); /* polyspace RTE:NIV */
            Fr_CC_data_ptr = ((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) )(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + ((Fr_CC_reg_ptr[FrRFSDOR]+(temp_value_2 * (Fr_CC_reg_ptr[FrRFBRIR] - Fr_CC_reg_ptr[FrRFSIR]))) / 2U)); /* polyspace RTE:NIV,OVFL,IDP */

            /* Load data length from Frame header reg. */
            Fr_data_length = (VAR(uint8, AUTOMATIC))(header_MB_ptr[1U] & 0x007FU); /* polyspace RTE:NIV */   /* Load the data payload length value from Frame header register */

            if( Fr_data_length > Fr_FIFO_info.FIFO_2_entry_size)
            {
                #if(FR_RX_STRINGENT_LENGTH_CHECK == OFF)
                Fr_data_length = Fr_FIFO_info.FIFO_2_entry_size;
                #else
                *Fr_data_length_ptr = 0;
                retval = FR_FIFO_NOT_RECEIVED;
                bStatusVal = FALSE;
                #endif
            }
            #if(FR_RX_STRINGENT_LENGTH_CHECK == STD_ON)
            if ((VAR(boolean, AUTOMATIC))TRUE == bStatusVal)
            {
            #endif
                /* Copy data */
                for (Fr_p = 0; Fr_p < Fr_data_length; ++Fr_p)
                {
                    Fr_data_ptr[Fr_p * 2U] = (VAR(uint8, AUTOMATIC))(Fr_CC_data_ptr[Fr_p] >> 8); /* polyspace RTE:NIV,IDP */ /* Store the high byte */
                    Fr_data_ptr[Fr_p * 2U + 1U] = (VAR(uint8, AUTOMATIC))(Fr_CC_data_ptr[Fr_p] & 0xFFU); /* polyspace RTE:NIV */ /* Store the low byte */
                }
                /* Stringent check for FIFO B */
                if (0x0080U == ((header_MB_ptr[3]) & FLEXRAY_STRINGENT_MASK_B)) /* polyspace RTE:NIV */
                {
                    bReceive = TRUE;
                }
            #if(FR_RX_STRINGENT_LENGTH_CHECK == STD_ON)
            }
            #endif
        }
        if(bReceive == TRUE)
        {
            *Fr_data_length_ptr = (VAR(uint8, AUTOMATIC))(Fr_data_length<<1);           /* Store length into Fr_data_length_ptr */
            SchM_Enter_Fr_EXCLUSIVE_AREA_12();
            temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_CC_reg_ptr[FrGIFER] ); /* polyspace RTE:NIV */
            temp_value_1 |= FrGIFER_FNEBIF;
            Fr_CC_reg_ptr[FrGIFER] = temp_value_1;
            SchM_Exit_Fr_EXCLUSIVE_AREA_12();
            retval = FR_FIFO_RECEIVED;                        /* The receive FIFO MB has been updated with new data */
        }
        else
        {
            *Fr_data_length_ptr = 0U;  
            SchM_Enter_Fr_EXCLUSIVE_AREA_12();
            temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_CC_reg_ptr[FrGIFER] ); /* polyspace RTE:NIV */
            temp_value_1 |= FrGIFER_FNEBIF;
            Fr_CC_reg_ptr[FrGIFER] = temp_value_1;
            SchM_Exit_Fr_EXCLUSIVE_AREA_12();
            retval = FR_FIFO_NOT_RECEIVED;
        }

    }
    else
    {
        *Fr_data_length_ptr = 0U;  
        retval = FR_FIFO_NOT_RECEIVED;
    }
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"


/************************************************************************************
* Function name:    Fr_LLD_Enable_Interrupts
* Description:      Thi API call enables an interrupt in the GIFER, PIER0 and PIER1 registers. 
*                   An user may put combinated defined macros into input parametrs. 
*                   If Fr_global_interrupt input parameter is zero, 
*                   this function will not update the GIFER register,
*                   otherwise the GIFER register will be updated.
*                   If Fr_protocol_0_interrupt parameter is zero, this function will not update the PIER0 
*                   register, otherwise the PIER0 register will be updated.
*                   If Fr_protocol_1_interrupt parameter is zero, this function will not update the PIER1 
*                   register, otherwise the PIER1 register will be updated.
*
* Function arguments: 
*                   Fr_global_interrupt          The name of interrupt in the GIFER reg.
*                   Fr_protocol_0_interrupt      The name of interrupt in the PIFR0 reg.
*                   Fr_protocol_1_interrupt      The name of interrupt in the PIFR1 reg.
* Return value:
*                   none     
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_LLD_Enable_Interrupts(VAR(uint16, FR_VAR) Fr_global_interrupt, VAR(uint16, FR_VAR) Fr_protocol_0_interrupt, VAR(uint16, FR_VAR) Fr_protocol_1_interrupt)
{
    volatile VAR(uint16, FR_VAR) temp_value_1;       /* Temporary varibale used for bit operations */
    
    if(Fr_global_interrupt  != 0U)             /* Fr_global_interrupt parameter is not equal to zero */
    {
        /* Enable Interrupts in the GIFER register */
        temp_value_1 = Fr_CC_reg_ptr[FrGIFER]; /* polyspace RTE:NIV,IDP */  /* Load content of GIFER reg. */
        temp_value_1 |= Fr_global_interrupt;    /* Set bit(s) */
        Fr_CC_reg_ptr[FrGIFER] = temp_value_1;  /* Store new settings */
    }
    temp_value_1 = 0x0000U;              /* Clear variable */
    if(Fr_protocol_0_interrupt  != 0U)         /* Fr_protocol_0_interrupt parameter is not equal to zero */
    {
        /* Enable Interrupts in the PIER0 register */
        temp_value_1 = Fr_CC_reg_ptr[FrPIER0]; /* polyspace RTE:NIV,IDP */      /* Load content of PIER0 reg. */
        temp_value_1 |= Fr_protocol_0_interrupt;    /* Set bit(s) */
        Fr_CC_reg_ptr[FrPIER0] = temp_value_1;      /* Store new settings */
    }
    temp_value_1 = 0x0000U;              /* Clear variable */
    if(Fr_protocol_1_interrupt  != 0U)         /* Fr_protocol_1_interrupt parameter is not equal to zero */
    {
        /* Enable Interrupts in the PIER1 register */
        temp_value_1 = Fr_CC_reg_ptr[FrPIER1];      /* Load content of PIER0 reg. */
        temp_value_1 |= Fr_protocol_1_interrupt;    /* Set bit(s) */
        Fr_CC_reg_ptr[FrPIER1] = temp_value_1;      /* Store new settings */
    }
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Disable_Interrupts
* Description:      Thi API call disables an interrupt in the GIFER, PIER0 and PIER1 registers. 
*                   An user may put combinated defined macros into input parametrs. 
*                   If Fr_global_interrupt input parameter is zero, 
*                   this function will not update the GIFER register,
*                   otherwise the GIFER register will be updated.
*                   If Fr_protocol_0_interrupt parameter is zero, this function will not update the PIER0 
*                   register, otherwise the PIER0 register will be updated.
*                   If Fr_protocol_1_interrupt parameter is zero, this function will not update the PIER1 
*                   register, otherwise the PIER1 register will be updated.
*
* Function arguments: 
*                   Fr_global_interrupt          The name of interrupt in the GIFER reg.
*                   Fr_protocol_0_interrupt      The name of interrupt in the PIFR0 reg.
*                   Fr_protocol_1_interrupt      The name of interrupt in the PIFR1 reg.
* Return value:
*                   none     
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_LLD_Disable_Interrupts(VAR(uint16, FR_VAR) Fr_global_interrupt, VAR(uint16, FR_VAR) Fr_protocol_0_interrupt, VAR(uint16, FR_VAR) Fr_protocol_1_interrupt)
{
    volatile VAR(uint16, FR_VAR) temp_value_1;       /* Temporary varibale used for bit operations */
    SchM_Enter_Fr_EXCLUSIVE_AREA_02();
    if(Fr_global_interrupt  != 0U)             /* Fr_global_interrupt parameter is not equal to zero */
    {
        /* Disable Interrupts in the GIFER register */
        temp_value_1 = Fr_CC_reg_ptr[FrGIFER]; /* polyspace RTE:NIV,IDP */  /* Load content of GIFER reg. */
        temp_value_1 &= (VAR(uint16, AUTOMATIC))(~Fr_global_interrupt); /* Clear bit(s) */
        Fr_CC_reg_ptr[FrGIFER] = temp_value_1;  /* Store new settings */
    }
    temp_value_1 = 0x0000U;              /* Clear variable */
    if(Fr_protocol_0_interrupt  != 0U)         /* Fr_protocol_0_interrupt parameter is not equal to zero */
    {
        /* Disable Interrupts in the PIER0 register */
        temp_value_1 = Fr_CC_reg_ptr[FrPIER0]; /* polyspace RTE:NIV,IDP */      /* Load content of PIER0 reg. */
        temp_value_1 &= (VAR(uint16, AUTOMATIC))(~Fr_protocol_0_interrupt); /* Clears bit(s) */
        Fr_CC_reg_ptr[FrPIER0] = temp_value_1;      /* Store new settings */
    }
    temp_value_1 = 0x0000U;              /* Clear variable */
    if(Fr_protocol_1_interrupt  != 0U)         /* Fr_protocol_1_interrupt parameter is not equal to zero */
    {
        /* Disbale Interrupts in the PIER1 register */
        temp_value_1 = Fr_CC_reg_ptr[FrPIER1];      /* Load content of PIER0 reg. */
        temp_value_1 &= (VAR(uint16, AUTOMATIC))(~Fr_protocol_1_interrupt); /* Clear bit(s) */
        Fr_CC_reg_ptr[FrPIER1] = temp_value_1;      /* Store new settings */
    }
    SchM_Exit_Fr_EXCLUSIVE_AREA_02();
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"


/************************************************************************************
* Function name:    Fr_LLD_Interrupt_Handler
* Description:      This function shoudl be called in interrupt service routine when 
*                   an interrupt occured. The API call check which interrupt source 
*                   generates the interrupt and if an appropriate callback function is called 
*                   if configured. The interrupt flags are cleared except the transmit or 
*                   receive message buffer interrupts (these are cleared by 
*                   Fr_transmit_data or Fr_receive_data)
*
* Function arguments: 
*                   none
*
* Return value:
*                   none     
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_LLD_Interrupt_Handler(VAR(void, FR_VAR))
{
    volatile VAR(uint16, FR_VAR) isr_event;              /* Content of the GIFER register is stored into this varibale */
    volatile VAR(uint16, FR_VAR) temp_isr_event;         /* Temporary variable intended for bit operation with isr_event variable */
    VAR(uint8, FR_VAR) buffer_idx;                       /* Which MB generated the interrupt */
    VAR(uint16, FR_VAR) buffer_fifo_idx;                 /* Which FIFO MB generated the interrupt */
    volatile VAR(uint16, FR_VAR) chierfr_event;          /* Content of the CHIERFR register is stored into this variable */
    volatile VAR(uint16, FR_VAR) isr_prif_0_event;       /* Content of the PIFR0 register is stored into this varibale */
    volatile VAR(uint16, FR_VAR) isr_prif_1_event;       /* Content of the PIFR1 register is stored into this varibale */
    volatile VAR(uint16, FR_VAR) temp_value_1, temp_value_2;     /* Temporary variables intended for bit operations */
    
    if (Fr_CC_reg_ptr == NULL_PTR)
    {
        return;
    }
    isr_event = Fr_CC_reg_ptr[FrGIFER]; /* polyspace RTE:NIV,IDP */     /* Read the GIFER register */
    temp_isr_event = (isr_event & 0x00FFU);  /* Select only lower eight bit */
    isr_event &= (VAR(uint16, AUTOMATIC))(temp_isr_event << 8);     /* Move selected bits and separate only enabled interrupt flags */
        
    if((isr_event & FrGIFER_TBIF) != 0U)     /* Transmit buffer interrupt flag set? */
    {   /* Yes, tx interrupt occured */
        buffer_idx = (VAR(uint8, AUTOMATIC))((Fr_CC_reg_ptr[FrMBIVEC] & 0x7F00U) >> 8U); /* polyspace RTE:NIV,IDP */ /* Read Transmit Buffer Interrupt Vector */
        if(Fr_MB_information_internal[buffer_idx].Fr_MB_function_ptr != NULL_PTR)       /* Service callback function was configured? */
        {
            Fr_MB_information_internal[buffer_idx].Fr_MB_function_ptr(buffer_idx);  /* Call service callback function */
        }
    }
    if((isr_event & FrGIFER_RBIF) != 0U)     /* Receive buffer interrupt flag set? */
    {   /* Yes, rx interrupt occured */
        buffer_idx = (VAR(uint8, AUTOMATIC))(Fr_CC_reg_ptr[FrMBIVEC] & 0x007FU); /* polyspace RTE:NIV,IDP */    /* Read Receive Buffer Interrupt Vector */
        if(Fr_MB_information_internal[buffer_idx].Fr_MB_function_ptr != NULL_PTR)       /* Service callback function was configured? */
        {
            Fr_MB_information_internal[buffer_idx].Fr_MB_function_ptr(buffer_idx);  /* Call service callback function */
        }
    }
    if((isr_event & FrGIFER_FNEAIF) != 0U)     /* FIFO A interrupt flag set? */
    {   /* Yes, FIFO A Not empty interrupt occured */
        buffer_fifo_idx = (Fr_CC_reg_ptr[FrRFARIR] & 0x03FFU); /* polyspace RTE:NIV,IDP */   /* Read Receive FIFO A Read Index */
        if(Fr_callback_functions.Fr_fifo_A_ptr != NULL_PTR)     /* Service callback function was configured? */
        {
            Fr_callback_functions.Fr_fifo_A_ptr(buffer_fifo_idx);   /* Call service callback function */
        }
        /* Read the GIFER reg. and clear the WUPIF, FNEBIF and FNEAIF bits */
    }
    if((isr_event & FrGIFER_FNEBIF) != 0U)     /* FIFO B interrupt flag set? */
    {   /* Yes, FIFO B Not empty interrupt occured */
        buffer_fifo_idx = (VAR(uint8, AUTOMATIC))(Fr_CC_reg_ptr[FrRFBRIR] & 0x03FFU); /* polyspace RTE:NIV,IDP */    /* Read Receive FIFO B Read Index */
        if(Fr_callback_functions.Fr_fifo_B_ptr != NULL_PTR)     /* Service callback function was configured? */
        {
            Fr_callback_functions.Fr_fifo_B_ptr(buffer_fifo_idx);   /* Call service callback function */
        }
    }
    if((isr_event & FrGIFER_WUPIF) != 0U)     /* Wakeup interrupt flag set? */
    {   /* Yes, Wakeup interrupt occured */
        if(Fr_callback_functions.Fr_wakeup_ptr != NULL)     /* Service callback function was configured? */
        {
            if((Fr_CC_reg_ptr[FrPSR3] & FrPSR3_WUA)   != 0U) /* polyspace RTE:NIV,IDP */         /* Determine on which channel has been wakeup received */
            {                                               /* On channel A */
                Fr_callback_functions.Fr_wakeup_ptr(FR_CHANNEL_A);  /* Call service callback function */
                Fr_CC_reg_ptr[FrPSR3] = FrPSR3_WUA;         /* Clear flag */
            }
            else if((Fr_CC_reg_ptr[FrPSR3] & FrPSR3_WUB)  != 0U) /* polyspace RTE:NIV */     /* Determine on which channel has been wakeup received */
            {                                               /* On channel B */
                Fr_callback_functions.Fr_wakeup_ptr(FR_CHANNEL_B);  /* Call service callback function */
                Fr_CC_reg_ptr[FrPSR3] = FrPSR3_WUB;         /* Clear flag */
            }
            else
            {

            }
        }
        /* Read the GIFER reg. and clear the WUPIF, FNEBIF and FNEAIF bits */
        temp_value_2 = (Fr_CC_reg_ptr[FrGIFER] & 0xE3FFU); /* polyspace RTE:NIV */
        Fr_CC_reg_ptr[FrGIFER] = (FrGIFER_WUPIF | temp_value_2);    /* Clear interrupt flag */
    }

    if((isr_event & FrGIFER_CHIF) != 0U)         /* CHI interrupt flag set? */
    {   /* Yes, at least one CHI error flag is asserted */
        chierfr_event = Fr_CC_reg_ptr[FrCHIERFR]; /* polyspace RTE:NIV,IDP */       /* Read CHI Error Flag register */
        if(Fr_callback_functions.Fr_chi_ptr != NULL_PTR)    /* Service callback function was configured? */
        {
            Fr_callback_functions.Fr_chi_ptr(chierfr_event);    /* Call service callback function */
        }
        Fr_CC_reg_ptr[FrCHIERFR] = chierfr_event;        /* Clear interrupt flag */
    }

    if((isr_event & FrGIFER_PRIF) != 0U)     /* Protocol interrupt flag set? */
    {   /* Yes, protocol interrupt occured */
        /* It is possible to use either one callback function for all Protocol Interrupt flags or  */
        /* more separate functions for individual flags */
        isr_prif_0_event = Fr_CC_reg_ptr[FrPIFR0]; /* polyspace RTE:NIV,IDP */      /* Read the PIFR0 register */
        isr_prif_1_event = Fr_CC_reg_ptr[FrPIFR1]; /* polyspace RTE:NIV,IDP */      /* Read the PIFR1 register */
        temp_value_1 = Fr_CC_reg_ptr[FrPIER0]; /* polyspace RTE:NIV,IDP */          /* Read the PIER0 register */
        isr_prif_0_event &= temp_value_1;               /* Select only enabled interrupt */
        temp_value_2 = Fr_CC_reg_ptr[FrPIER1]; /* polyspace RTE:NIV,IDP */          /* Read the PIER1 register */
        isr_prif_1_event &= temp_value_2;               /* Select only enabled interrupt */

        /* More separate callback functions for individual Protocol Interrupt flags */
        /* PIFR0 register */
        if((isr_prif_0_event & FR_CYCLE_START_IRQ) != 0U)                /* Cycle Start interrupt flag set? */
        {   /* Yes, cycle start occured */
            if(Fr_callback_functions.Fr_cycle_start_ptr != NULL_PTR)        /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_cycle_start_ptr();             /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_CYCLE_START_IRQ;                /* Clear interrupt flag */
        }

        if((isr_prif_0_event & FR_TIMER_1_EXPIRED_IRQ) != 0U)            /* Timer 1 expired interrupt flag set? */
        {   /* Yes, timer 1 expired */
            if(Fr_callback_functions.Fr_timer_1_expired_ptr != NULL_PTR)    /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_timer_1_expired_ptr();         /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_TIMER_1_EXPIRED_IRQ;            /* Clear interrupt flag */
        }

        if((isr_prif_0_event & FR_TIMER_2_EXPIRED_IRQ) != 0U)            /* Timer 2 expired interrupt flag set? */
        {   /* Yes, timer 2 expired */
            if(Fr_callback_functions.Fr_timer_2_expired_ptr != NULL)    /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_timer_2_expired_ptr();         /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_TIMER_2_EXPIRED_IRQ;            /* Clear interrupt flag */
        }

        if((isr_prif_0_event & FR_TRANSMISSION_ACROSS_BOUNDARY_CHA_IRQ) != 0U) /* Transmission across boundary occured on channel A? */
        {   /* Yes, transmission across boundary occured */
            if(Fr_callback_functions.Fr_trans_across_boundary_A_ptr != NULL_PTR)    /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_trans_across_boundary_A_ptr();         /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_TRANSMISSION_ACROSS_BOUNDARY_CHA_IRQ;   /* Clear interrupt flag */
        }

        if((isr_prif_0_event & FR_TRANSMISSION_ACROSS_BOUNDARY_CHB_IRQ) != 0U) /* Transmission across boundary occured on channel B? */
        {   /* Yes, transmission across boundary occured */
            if(Fr_callback_functions.Fr_trans_across_boundary_B_ptr != NULL_PTR)    /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_trans_across_boundary_B_ptr();         /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_TRANSMISSION_ACROSS_BOUNDARY_CHB_IRQ;   /* Clear interrupt flag */
        }
       
        if((isr_prif_0_event & FR_VIOLATION_CHA_IRQ) != 0U)              /* pLatestTx violation occured on channel A? */
        {   /* Yes, pLatestTx violation occured */
            if(Fr_callback_functions.Fr_violation_A_ptr != NULL_PTR)        /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_violation_A_ptr();             /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_VIOLATION_CHA_IRQ;              /* Clear interrupt flag */
        }

        if((isr_prif_0_event & FR_VIOLATION_CHB_IRQ) != 0U)              /* pLatestTx violation occured on channel B? */
        {   /* Yes, pLatestTx violation occured */
            if(Fr_callback_functions.Fr_violation_B_ptr != NULL_PTR)        /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_violation_B_ptr();             /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_VIOLATION_CHB_IRQ;              /* Clear interrupt flag */
        }

        if((isr_prif_0_event & FR_MEDIA_ACCESS_TEST_SYMBOL_RECEIVED_IRQ) != 0U)  /* MTS symbol received? */
        {   /* Yes, MTS symbol received */
            if(Fr_callback_functions.Fr_mts_received_ptr != NULL_PTR)       /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_mts_received_ptr();            /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_MEDIA_ACCESS_TEST_SYMBOL_RECEIVED_IRQ;  /* Clear interrupt flag */
        }

        if((isr_prif_0_event & FR_MAX_SYNC_FRAMES_DETECTED_IRQ) != 0U)   /* Max Sync Frames Detected? */
        {   /* Yes, More than node_sync_max sync frames detected */
            if(Fr_callback_functions.Fr_max_sync_frames_ptr != NULL_PTR)    /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_max_sync_frames_ptr();         /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_MAX_SYNC_FRAMES_DETECTED_IRQ;   /* Clear interrupt flag */
        }

        if((isr_prif_0_event & FR_CLOCK_CORRECTION_LIMIT_IRQ) != 0U)     /* Clock correction limit reached? */
        {   /* Yes, Offset or rate correction limit reached */
            if(Fr_callback_functions.Fr_clock_corr_limit_ptr != NULL_PTR)   /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_clock_corr_limit_ptr();        /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_CLOCK_CORRECTION_LIMIT_IRQ;     /* Clear interrupt flag */
        }

        if((isr_prif_0_event & FR_MISSING_OFFSET_CORRECTION_IRQ) != 0U)  /* Missing Offset Correction Interrupt? */
        {   /* Yes, Insufficient number of measurements for offset correction detected */
            if(Fr_callback_functions.Fr_missing_offset_corr_ptr != NULL_PTR) /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_missing_offset_corr_ptr();     /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_MISSING_OFFSET_CORRECTION_IRQ;  /* Clear interrupt flag */
        }

        if((isr_prif_0_event & FR_MISSING_RATE_CORRECTION_IRQ) != 0U)    /* Missing Rate Correction Interrupt? */
        {   /* Yes, Insufficient number of measurements for rate correction detected */
            if(Fr_callback_functions.Fr_missing_rate_corr_ptr != NULL_PTR)  /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_missing_rate_corr_ptr();       /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_MISSING_RATE_CORRECTION_IRQ;    /* Clear interrupt flag */
        }

        if((isr_prif_0_event & FR_COLDSTART_ABORT_IRQ) != 0U)            /* Coldstart Abort Interrupt? */
        {   /* Yes, Coldstart aborted and no more coldstart attempts allowed */
            if(Fr_callback_functions.Fr_coldstart_abort_ptr != NULL_PTR)    /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_coldstart_abort_ptr();         /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_COLDSTART_ABORT_IRQ;            /* Clear interrupt flag */
        }

        if((isr_prif_0_event & FR_ILLEGAL_PROTOCOL_CONFIGURATION_IRQ) != 0U) /* Illegal protocol congiguration detected? */
        {   /* Yes, illegal protocol configuration detected */
            if(Fr_callback_functions.Fr_illegal_protocol_conf_ptr != NULL_PTR)  /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_illegal_protocol_conf_ptr();       /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_ILLEGAL_PROTOCOL_CONFIGURATION_IRQ; /* Clear interrupt flag */
        }

        if((isr_prif_0_event & FR_INTERNAL_PROTOCOL_ERROR_IRQ) != 0U)    /* Internal protocol error detected? */
        {   /* Yes, internal protocol error detected */
            if(Fr_callback_functions.Fr_internal_protocol_error_ptr != NULL_PTR)    /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_internal_protocol_error_ptr(); /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_INTERNAL_PROTOCOL_ERROR_IRQ;    /* Clear interrupt flag */
        }

        if((isr_prif_0_event & FR_FATAL_PROTOCOL_ERROR_IRQ) != 0U)       /* Fatal protocol error detected? */
        {   /* Yes, fatal protocol error detected */
            if(Fr_callback_functions.Fr_fatal_protocol_error_ptr != NULL_PTR)   /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_fatal_protocol_error_ptr(); /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR0] = FR_FATAL_PROTOCOL_ERROR_IRQ;    /* Clear interrupt flag */
        }

        /* PIFR1 register */
        if((isr_prif_1_event & FR_ERROR_MODE_CHANGED_IRQ) != 0U)         /* Error mode Changed Interrupt? */
        {   /* Yes, ERRMODE field changed */
            if(Fr_callback_functions.Fr_error_mode_changed_ptr != NULL_PTR) /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_error_mode_changed_ptr();      /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR1] = FR_ERROR_MODE_CHANGED_IRQ;         /* Clear interrupt flag */
        }

        if((isr_prif_1_event & FR_ILLEGAL_PROTOCOL_COMMAND_IRQ) != 0U)   /* Illegal protocol command detected? */
        {   /* Yes, illegal protocol state change command detected */
            if(Fr_callback_functions.Fr_illegal_protocol_command_ptr != NULL_PTR) /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_illegal_protocol_command_ptr();      /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR1] = FR_ILLEGAL_PROTOCOL_COMMAND_IRQ;         /* Clear interrupt flag */
        }
        
        if((isr_prif_1_event & FR_PROTOCOL_ENGINE_COM_FAILURE) != 0U)    /* Protocol engine communication failure detected? */
        {   /* Yes, protocol engine communication failure detected */
            if(Fr_callback_functions.Fr_protocol_engine_comm_failure_ptr != NULL_PTR) /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_protocol_engine_comm_failure_ptr();    /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR1] = FR_PROTOCOL_ENGINE_COM_FAILURE;            /* Clear interrupt flag */
        }

        if((isr_prif_1_event & FR_PROTOCOL_STATE_CHANGED_IRQ) != 0U)     /* Protocol state changed? */
        {   /* Yes, protocol state changed */
            if(Fr_callback_functions.Fr_protocol_state_changed_ptr != NULL_PTR) /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_protocol_state_changed_ptr();  /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR1] = FR_PROTOCOL_STATE_CHANGED_IRQ;     /* Clear interrupt flag */
        }

        if((isr_prif_1_event & FR_SLOT_STATUS_COUNTER_3_INCREMENTED_IRQ) != 0U)  /* Slot status counter 3 incremented? */
        {   /* Yes, slot status counter 3 has incremented */
            if(Fr_callback_functions.Fr_slot_status_counter_3_inc_ptr != NULL_PTR)  /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_slot_status_counter_3_inc_ptr();       /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR1] = FR_SLOT_STATUS_COUNTER_3_INCREMENTED_IRQ;  /* Clear interrupt flag */
        }
        
        if((isr_prif_1_event & FR_SLOT_STATUS_COUNTER_2_INCREMENTED_IRQ) != 0U)  /* Slot status counter 2 incremented? */
        {   /* Yes, slot status counter 2 has incremented */
            if(Fr_callback_functions.Fr_slot_status_counter_2_inc_ptr != NULL_PTR)  /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_slot_status_counter_2_inc_ptr();       /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR1] = FR_SLOT_STATUS_COUNTER_2_INCREMENTED_IRQ;  /* Clear interrupt flag */
        }
        
        if((isr_prif_1_event & FR_SLOT_STATUS_COUNTER_1_INCREMENTED_IRQ) != 0U)  /* Slot status counter 1 incremented? */
        {   /* Yes, slot status counter 1 has incremented */
            if(Fr_callback_functions.Fr_slot_status_counter_1_inc_ptr != NULL_PTR)  /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_slot_status_counter_1_inc_ptr();       /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR1] = FR_SLOT_STATUS_COUNTER_1_INCREMENTED_IRQ;  /* Clear interrupt flag */
        }
        
        if((isr_prif_1_event & FR_SLOT_STATUS_COUNTER_0_INCREMENTED_IRQ) != 0U)  /* Slot status counter 0 incremented? */
        {   /* Yes, slot status counter 0 has incremented */
            if(Fr_callback_functions.Fr_slot_status_counter_0_inc_ptr != NULL_PTR)  /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_slot_status_counter_0_inc_ptr();       /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR1] = FR_SLOT_STATUS_COUNTER_0_INCREMENTED_IRQ;  /* Clear interrupt flag */
        }

        if((isr_prif_1_event & FR_EVEN_CYCLE_TABLE_WRITTEN_IRQ) != 0U)           /* Even cycle table written? */
        {   /* Yes, sync frame measurement table written */
            if(Fr_callback_functions.Fr_even_cycle_table_written_ptr != NULL_PTR)  /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_even_cycle_table_written_ptr();       /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR1] = FR_EVEN_CYCLE_TABLE_WRITTEN_IRQ;           /* Clear interrupt flag */
        }

        if((isr_prif_1_event & FR_ODD_CYCLE_TABLE_WRITTEN_IRQ) != 0U)           /* Odd cycle table written? */
        {   /* Yes, sync frame measurement table written */
            if(Fr_callback_functions.Fr_odd_cycle_table_written_ptr != NULL_PTR)  /* Service callback function was configured? */
            {
                Fr_callback_functions.Fr_odd_cycle_table_written_ptr();       /* Call service callback function */
            }
            Fr_CC_reg_ptr[FrPIFR1] = FR_ODD_CYCLE_TABLE_WRITTEN_IRQ;           /* Clear interrupt flag */
        }
        
        /* One callback function for all Protocol interrupt flags */
        if(Fr_callback_functions.Fr_protocol_ptr != NULL_PTR)   /* Service callback function was configured? */
        {
            Fr_callback_functions.Fr_protocol_ptr();        /* Call service callback function */
            /* Be careful - all enabled flags in the PIFR0 and PIFR1 are cleared */
            Fr_CC_reg_ptr[FrPIFR0] = isr_prif_0_event;      /* Clear interrupt flag */
            Fr_CC_reg_ptr[FrPIFR1] = isr_prif_1_event;      /* Clear interrupt flag */
        }
    }

    /* One callback function for all interrupt flags - no interrupt flas are cleared */
    if((isr_event & FrGIFER_MIF) != 0U)         /* Module interrupt flag set? */
    {   /* Yes, at least one of the other interrupt flags in the GIFER reg. is asserted */
        if(Fr_callback_functions.Fr_module_ptr != NULL_PTR) /* Service callback function was configured? */
        {
            Fr_callback_functions.Fr_module_ptr();      /* Call service callback function */
            /* Be careful - no interrupt flags are cleared by this function call */
            /* For interrupt flag clearing, it is neccessary to set a service routine for appropriate individual interrupt */
        }
    }
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Set_MB_Callback
* Description:      This function stores the reference to the callback function into internal 
*                   structure. When an transmit/receive interrupt arrises and Fr_interrupt_handler 
*                   function is called, the function referenced by MB_callback_ptr pointer 
*                   is called with the number of MB (in Fr_int_buffer_idx) which generated 
*                   the interrupt.
*                   This API call does not set the MBIE bit in the MBCCSRn register or 
*                   the TBIE/RBIE bit in the GIFER register, i.e. it does not enable 
*                   the transmit/receive interrupt
*
* Function arguments: 
*                   MB_callback_ptr  The reference to the function which should be 
*                                   called by Fr_interrupt_handler function when 
*                                   an interrupt occured
*                   Fr_buffer_idx   This index is used to select a transmit message 
*                                   buffer of FlexRay CC.
*
* Return value:
*                   none     
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_LLD_Set_MB_Callback(P2FUNC(void,FR_APPL_CODE,MB_callback_ptr)(VAR(uint8, FR_VAR) Fr_int_buffer_idx), VAR(uint8, FR_VAR) Fr_buffer_idx)
{
    /* Store the reference to the function into internal structure */
    Fr_MB_information_internal[Fr_buffer_idx].Fr_MB_function_ptr = MB_callback_ptr; /* polyspace RTE:OBAI */
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Set_Global_IRQ_Callback
* Description:      This function stores the reference to the callback function into internal 
*                   structure. When an interrupt arrises and Fr_interrupt_handler 
*                   function is called, the function referenced by callback_ptr pointer 
*                   is called.
*
* Function arguments: 
*                   callback_ptr    The reference to the function which should be 
*                                   called by Fr_interrupt_handler function when 
*                                   an interrupt occured
*                   Fr_global_interrupt     The name of interrupt which should be selected
* Return value:
*                   StatusSuss        API call has been successful
*                   StatusErro    Wrong input parameter
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Set_Global_IRQ_Callback(P2FUNC(void,FR_APPL_CODE,callback_ptr)(void), VAR(uint16, FR_VAR) Fr_global_interrupt)
{
    VAR(Fr_LLDriver_StatusType, FR_VAR) retval = StatusSuss;
    /* Store the reference to the function into internal structure */
    switch(Fr_global_interrupt)
    {
    case FR_MODULE_IRQ:
        Fr_callback_functions.Fr_module_ptr = callback_ptr;
        break;
    case FR_PROTOCOL_IRQ:
        Fr_callback_functions.Fr_protocol_ptr = callback_ptr;
        break;
    default:
        retval = StatusErro;      /* API call has not been successful - wrong parameter */
        break;
    }
    return retval;              /* API call has been successful */
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Set_Protocol_0_IRQ_Callback
* Description:      This function stores the reference to the callback function 
*                   into internal structure. When an Protocol interrupt 
*                   (asserted with PIFR0 register) arrises and Fr_interrupt_handler function 
*                   is called, the function referenced by callback_ptr pointer is called. 
*                   This API call does not enable any interrupt
*
* Function arguments: 
*                   callback_ptr    The reference to the function which should be 
*                                   called by Fr_interrupt_handler function when 
*                                   an protocol interrupt occured
*                   Fr_protocol_interrupt     The name of interrupt which should be selected
* Return value:
*                   StatusSuss        API call has been successful
*                   StatusErro    Wrong input parameter
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Set_Protocol_0_IRQ_Callback(P2FUNC(void,FR_APPL_CODE,callback_ptr)(void), VAR(uint16, FR_VAR) Fr_protocol_interrupt)
{
    VAR(Fr_LLDriver_StatusType, FR_VAR) retval = StatusSuss;
    /* Store the reference to the function into internal structure */
    switch(Fr_protocol_interrupt)
    {
    case FR_FATAL_PROTOCOL_ERROR_IRQ:
        Fr_callback_functions.Fr_fatal_protocol_error_ptr = callback_ptr;
        break;
    case FR_INTERNAL_PROTOCOL_ERROR_IRQ:
        Fr_callback_functions.Fr_internal_protocol_error_ptr = callback_ptr;
        break;
    case FR_ILLEGAL_PROTOCOL_CONFIGURATION_IRQ:
        Fr_callback_functions.Fr_illegal_protocol_conf_ptr = callback_ptr;
        break;
    case FR_COLDSTART_ABORT_IRQ:
        Fr_callback_functions.Fr_coldstart_abort_ptr = callback_ptr;
        break;
    case FR_MISSING_RATE_CORRECTION_IRQ:
        Fr_callback_functions.Fr_missing_rate_corr_ptr = callback_ptr;
        break;
    case FR_MISSING_OFFSET_CORRECTION_IRQ:
        Fr_callback_functions.Fr_missing_offset_corr_ptr = callback_ptr;
        break;
    case FR_CLOCK_CORRECTION_LIMIT_IRQ:
        Fr_callback_functions.Fr_clock_corr_limit_ptr = callback_ptr;
        break;
    case FR_MAX_SYNC_FRAMES_DETECTED_IRQ:
        Fr_callback_functions.Fr_max_sync_frames_ptr = callback_ptr;
        break;
    case FR_MEDIA_ACCESS_TEST_SYMBOL_RECEIVED_IRQ:
        Fr_callback_functions.Fr_mts_received_ptr = callback_ptr;
        break;
    case FR_VIOLATION_CHB_IRQ:
        Fr_callback_functions.Fr_violation_B_ptr = callback_ptr;
        break;
    case FR_VIOLATION_CHA_IRQ:
        Fr_callback_functions.Fr_violation_A_ptr = callback_ptr;
        break;
    case FR_TRANSMISSION_ACROSS_BOUNDARY_CHB_IRQ:
        Fr_callback_functions.Fr_trans_across_boundary_B_ptr = callback_ptr;
        break;
    case FR_TRANSMISSION_ACROSS_BOUNDARY_CHA_IRQ:
        Fr_callback_functions.Fr_trans_across_boundary_A_ptr = callback_ptr;
        break;
    case FR_TIMER_2_EXPIRED_IRQ:
        Fr_callback_functions.Fr_timer_2_expired_ptr = callback_ptr;
        break;
    case FR_TIMER_1_EXPIRED_IRQ:
        Fr_callback_functions.Fr_timer_1_expired_ptr = callback_ptr;
        break;
    case FR_CYCLE_START_IRQ:
        Fr_callback_functions.Fr_cycle_start_ptr = callback_ptr;
        break;
    default:
        retval = StatusErro;      /* API call has not been successful - wrong parameter */
        break;
    }
    return retval;              /* API call has been successful */
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Set_Protocol_1_IRQ_Callback
* Description:      This function stores the reference to the callback function 
*                   into internal structure. When an Protocol interrupt 
*                   (asserted with PIFR1 register) arrises and Fr_interrupt_handler function 
*                   is called, the function referenced by callback_ptr pointer is called. 
*                   This API call does not enable any interrupt
*
* Function arguments: 
*                   callback_ptr    The reference to the function which should be 
*                                   called by Fr_interrupt_handler function when 
*                                   an protocol interrupt occured
*                   Fr_protocol_interrupt     The name of interrupt which should be selected
* Return value:
*                   StatusSuss        API call has been successful
*                   StatusErro    Wrong input parameter
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Set_Protocol_1_IRQ_Callback(P2FUNC(void,FR_APPL_CODE,callback_ptr)(void), VAR(uint16, FR_VAR) Fr_protocol_interrupt)
{
    VAR(Fr_LLDriver_StatusType, FR_VAR) retval = StatusSuss;

    /* Store the reference to the function into internal structure */
    switch(Fr_protocol_interrupt)
    {
    case FR_ERROR_MODE_CHANGED_IRQ:
        Fr_callback_functions.Fr_error_mode_changed_ptr = callback_ptr;
        break;
    case FR_ILLEGAL_PROTOCOL_COMMAND_IRQ:
        Fr_callback_functions.Fr_illegal_protocol_command_ptr = callback_ptr;
        break;
    case FR_PROTOCOL_ENGINE_COM_FAILURE:
        Fr_callback_functions.Fr_protocol_engine_comm_failure_ptr = callback_ptr;
        break;
    case FR_PROTOCOL_STATE_CHANGED_IRQ:
        Fr_callback_functions.Fr_protocol_state_changed_ptr = callback_ptr;
        break;
    case FR_SLOT_STATUS_COUNTER_3_INCREMENTED_IRQ:
        Fr_callback_functions.Fr_slot_status_counter_3_inc_ptr = callback_ptr;
        break;
    case FR_SLOT_STATUS_COUNTER_2_INCREMENTED_IRQ:
        Fr_callback_functions.Fr_slot_status_counter_2_inc_ptr = callback_ptr;
        break;
    case FR_SLOT_STATUS_COUNTER_1_INCREMENTED_IRQ:
        Fr_callback_functions.Fr_slot_status_counter_1_inc_ptr = callback_ptr;
        break;
    case FR_SLOT_STATUS_COUNTER_0_INCREMENTED_IRQ:
        Fr_callback_functions.Fr_slot_status_counter_0_inc_ptr = callback_ptr;
        break;
    case FR_EVEN_CYCLE_TABLE_WRITTEN_IRQ:
        Fr_callback_functions.Fr_even_cycle_table_written_ptr = callback_ptr;
        break;
    case FR_ODD_CYCLE_TABLE_WRITTEN_IRQ:
        Fr_callback_functions.Fr_odd_cycle_table_written_ptr = callback_ptr;
        break;
    default:
        retval = StatusErro;      /* API call has not been successful - wrong parameter */
        break;
    }
    return retval;              /* API call has been successful */
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"


/************************************************************************************
* Function name:    Fr_LLD_Set_Wakeup_IRQ_Callback
* Description:      This function stores the reference to the callback function into 
*                   internal structure. When Wakeup interrupt arrises and Fr_interrupt_handler 
*                   function is called, the function referenced by callback_ptr pointer is 
*                   called with information on which channle the wakeup symbol was received
*                   (in wakeup_channel). This API call does not enable the Wakeup interrupt
*
* Function arguments: 
*                   callback_ptr    The reference to the function which should be 
*                                   called by Fr_interrupt_handler function when 
*                                   Wakeup interrupt occured
* Return value:
*                   none
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_LLD_Set_Wakeup_IRQ_Callback(P2FUNC(void,FR_APPL_CODE,callback_ptr)(VAR(Fr_ChannelType, FR_VAR) wakeup_channel))
{
    /* Store the reference to the function into internal structure */
    Fr_callback_functions.Fr_wakeup_ptr = callback_ptr;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
    
/************************************************************************************
* Function name:    Fr_LLD_Set_Chi_IRQ_Callback
* Description:      This function stores the reference to the callback function into 
*                   internal structure. When CHI interrupt arrises and Fr_interrupt_handler 
*                   function is called, the function referenced by callback_ptr pointer is 
*                   called with content of CHIERFR register (in chi_error). This API call 
*                   does not enable the CHI interrupt
*
* Function arguments: 
*                   callback_ptr    The reference to the function which should be 
*                                   called by Fr_interrupt_handler function when 
*                                   CHI interrupt occured
* Return value:
*                   none
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_LLD_Set_Chi_IRQ_Callback(P2FUNC(void,FR_APPL_CODE,callback_ptr)(VAR(uint16, FR_VAR) chi_error))
{
    /* Store the reference to the function into internal structure */
    Fr_callback_functions.Fr_chi_ptr = callback_ptr;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"


/************************************************************************************
* Function name:    Fr_LLD_Set_Fifo_IRQ_Callback
* Description:      This function stores the reference to the callback function into 
*                   internal structure. When an FIFO interrupt arrises and Fr_interrupt_handler 
*                   function is called, the function referenced by callback_ptr pointer is 
*                   called with content of the RFARIR or RFBRIR register (in header_index). This API call 
*                   does not enable the FIFO interrupts
*
* Function arguments: 
*                   callback_ptr    The reference to the function which should be 
*                                   called by Fr_interrupt_handler function when 
*                                   an FIFO interrupt occured
*                   Fr_global_interrupt     The name of interrupt which should be selected
*
* Return value:
*                   StatusSuss        API call has been successful
*                   StatusErro    Wrong input parameter
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_LLD_Set_Fifo_IRQ_Callback(P2FUNC(void,FR_APPL_CODE,callback_ptr)(VAR(uint16, FR_VAR) header_index), VAR(uint16, FR_VAR) Fr_global_interrupt)
{
    VAR(Fr_LLDriver_StatusType, FR_VAR) retval = StatusSuss;

    /* Store the reference to the function into internal structure */
    switch(Fr_global_interrupt)
    {
    case FR_FIFO_B_IRQ:
        Fr_callback_functions.Fr_fifo_B_ptr = callback_ptr;
        break;
    case FR_FIFO_A_IRQ:
        Fr_callback_functions.Fr_fifo_A_ptr = callback_ptr;
        break;
    default:
        retval = StatusErro;      /* API call has not been successful - wrong parameter */
        break;
    }
    return retval;              /* API call has been successful */
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Start_Timer
* Description:      This function starts timer T1 or T2
*
* Function arguments: 
*                   timer_ID    This parameter determines which timer (T1 or T2) 
*                               will start
* Return value:
*                   none
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_LLD_Start_Timer(VAR(Fr_timer_ID_type, FR_VAR) timer_ID)
{
    volatile VAR(uint16, FR_VAR) temp_value_1;               /* Temporary variable used for bit operation */
    SchM_Enter_Fr_EXCLUSIVE_AREA_04();
    temp_value_1 = Fr_CC_reg_ptr[FrTICCR]; /* polyspace RTE:NIV */      /* Load content of the Timer Configuration and Control reg. */
    if(timer_ID == FR_TIMER_T1)                 /* Which timer should start */
    {                                           /* Timer T1 */
        temp_value_1 |= FrTICCR_T1TR;           /* Start bit for T1 */
    }
    else if(timer_ID == FR_TIMER_T2)            /* Which timer should start */
    {                                           /* Timer T2 */
        temp_value_1 |= FrTICCR_T2TR;           /* Start bit for T2 */
    }
    else
    {

    }
    Fr_CC_reg_ptr[FrTICCR] = temp_value_1;  /* Store new value to the Timer Configuration and Control reg. */
    SchM_Exit_Fr_EXCLUSIVE_AREA_04();
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_Stop_Timer
* Description:      This function stops timer T1 or T2
*
* Function arguments: 
*                   timer_ID    This parameter determines which timer (T1 or T2) 
*                               will stop
* Return value:
*                   none
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_Stop_Timer(VAR(Fr_timer_ID_type, FR_VAR) timer_ID)
{
    volatile VAR(uint16, FR_VAR) temp_value_1;               /* Temporary variable used for bit operation */
    SchM_Enter_Fr_EXCLUSIVE_AREA_01();
    temp_value_1 = Fr_CC_reg_ptr[FrTICCR]; /* polyspace RTE:NIV,IDP */      /* Load content of the Timer Configuration and Control reg. */
    if(timer_ID == FR_TIMER_T1)                 /* Which timer should stop */
    {                                           /* Timer T1 */
        temp_value_1 |= FrTICCR_T1SP;           /* Stop bit for T1 */
    }
    else if(timer_ID == FR_TIMER_T2)            /* Which timer should stop */
    {                                           /* Timer T2 */
        temp_value_1 |= FrTICCR_T2SP;           /* Stop bit for T2 */
    }
    else
    {

    }
    Fr_CC_reg_ptr[FrTICCR] = temp_value_1;  /* Store new value to the Timer Configuration and Control reg. */
    SchM_Exit_Fr_EXCLUSIVE_AREA_01();
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"


/************************************************************************************
* Function name:    Fr_LLD_Check_Tx_Status
* Description:      Check whether or not the transmission of the data referenced 
*                   by Fr_buffer_idx has been performed
*
* Function arguments: 
*                   Fr_buffer_idx   This index is used to select a transmit message 
*                                   buffer of FlexRay CC.
* Return value:
*                   FR_TRANSMITTED  Data has been transmitted
*                                   commit side - transferred
*                                   transmit side - transmitted
*                   FR_NOT_TRANSMITTED  Data has not been transmitted
*                                   commit side - not transferred
*                                   transmit side - not transmitted
*                   FR_INTERNAL_MESSAGE_TRANSFER_DONE - only for double MB
*                                   commit side - transferred
*                                   transmit side - not transmitted
*                   FR_TRANSMIT_SIDE_TRANSMITTED - only for double MB
*                                   commit side - not transferred
*                                   transmit side - transmitted
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_LLD_Check_Tx_Status(P2CONST(Fr_CtrlCfgType, AUTOMATIC, *)pCtrlCfg, VAR(uint16, FR_VAR) Fr_LPduIdx,P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) pSlotAssignment,P2VAR(Fr_TxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_TxLPduStatusPtr)
{
    volatile VAR(uint16, FR_VAR) temp_value_1 = 0U;
    volatile VAR(uint16, FR_VAR) temp_value_2 = 0U; /* Temporary variable used for bit operation */
    volatile VAR(uint16, FR_VAR) Fr_MB_registers_offset_add_temp; /* Temporary offset adress of message buffer registers */
    VAR(uint16, FR_VAR) Fr_buffer_idx = (VAR(uint16, AUTOMATIC))pCtrlCfg->Fr_buffers_config_temp_ptr[Fr_LPduIdx].buffer_index_init;
    P2CONST(Fr_transmit_buffer_config_type, AUTOMATIC, *) Fr_transmit_buffer_config_ptr= ((P2VAR(Fr_transmit_buffer_config_type, AUTOMATIC,FR_APPL_DATA))(pCtrlCfg->Fr_buffers_config_temp_ptr[Fr_LPduIdx].buffer_config_ptr));
    VAR(Std_ReturnType, FR_VAR) ret = E_NOT_OK;

    /* Temporary offset address of MB registers */
    Fr_MB_registers_offset_add_temp = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_buffer_idx * 4U);
    if(pCtrlCfg->Fr_buffers_config_temp_ptr[Fr_LPduIdx].buffer_type == FR_TRANSMIT_BUFFER)
    {
        if (NULL_PTR != pSlotAssignment)
        {
            pSlotAssignment->channelId = Fr_transmit_buffer_config_ptr->transmit_channel_enable;
            pSlotAssignment->SlotId = Fr_transmit_buffer_config_ptr->transmit_frame_ID;
            pSlotAssignment->Cycle = (VAR(uint8, AUTOMATIC))(Fr_CC_reg_ptr[FrCYCTR]); /* polyspace RTE:NIV,IDP */
        }
        
        /* Read the MB Configuration, Control and Status reg. */
        temp_value_1 = Fr_CC_reg_ptr[FrMBCCSR0 + Fr_MB_registers_offset_add_temp]; /* polyspace RTE:NIV,IDP */

        if(FrMBCCSR_CMT == (temp_value_1 & FrMBCCSR_CMT))    /* Check if CMT bit is set */
        {                                   /* Yes -> data has not been transmitted yet */
            *Fr_TxLPduStatusPtr =  FR_NOT_TRANSMITTED;
        }
        else                                /* No -> data has been transmitted */
        {
            temp_value_2 = Fr_CC_reg_ptr[FrPSR2]; /* polyspace RTE:NIV */
            /* Check for transmission conflicts */
            if ((((VAR(boolean, AUTOMATIC))((FR_CHANNEL_A | FR_CHANNEL_AB) & Fr_transmit_buffer_config_ptr->transmit_channel_enable)) 
                && (FrPSR2_STCA == (temp_value_2 & FrPSR2_STCA))) 
                || (((VAR(boolean, AUTOMATIC))((FR_CHANNEL_B | FR_CHANNEL_AB) & Fr_transmit_buffer_config_ptr->transmit_channel_enable)) 
                && (FrPSR2_STCB == (temp_value_2 & FrPSR2_STCB)))
            )
            {
                *Fr_TxLPduStatusPtr = FR_TRANSMITTED_CONFLICT;
            }
            else
            {
                *Fr_TxLPduStatusPtr =  FR_TRANSMITTED;
            }
        }
        ret = E_OK;
    }
    else
    {
        /* HW error MB is not configured for Tx -> return E_NOT_OK */
        ret = E_NOT_OK;
    }
    return ret;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Low_Level_Access_Read_Reg
* Description:      Read value of the given register
*
* Function arguments: 
*                   Fr_required_register    This parameter determines which 
*                                           FlexRay register shall be read
* Return value:
*                   The content of required register
*
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(uint16, FR_CODE) Fr_LLD_Low_Level_Access_Read_Reg(VAR(uint16, FR_VAR) Fr_required_register)
{
    if (Fr_CC_reg_ptr == NULL_PTR)
    {
        return (uint16)0;
    }
    return Fr_CC_reg_ptr[Fr_required_register]; /* polyspace RTE:NIV,IDP */ /* Read the content of the required FlexRay register */
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Low_Level_Access_Write_Reg
* Description:      Write given value to the register
*
* Function arguments: 
*                   Fr_required_register    This parameter determines to which FlexRay 
*                                           register shall be written the value put in Fr_value parameter
*                   Fr_value                Value which should be written into required register
* Return value:
*                   none
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_LLD_Low_Level_Access_Write_Reg(VAR(uint16, FR_VAR) Fr_required_register, VAR(uint16, FR_VAR) Fr_value)
{
    if (Fr_CC_reg_ptr == NULL_PTR)
    {
        return;
    }
    Fr_CC_reg_ptr[Fr_required_register] = Fr_value; /* polyspace RTE:IDP */     /* Write given value to the FlexRay register */
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Low_Level_Access_Read_Memory
* Description:      Read value of the FlexRay memory field. 
*                   The value of the Fr_memory_address parameter is any offset of the corresponding 
*                   FlexRay memory field with respect to the FlexRay memory base address 
*                   as provided by the CC_FlexRay_memory_base_address parameter 
*                   in the Fr_HW_config_type structure
*
* Function arguments: 
*                   Fr_memory_address   This parameter determines which FlexRay memory 
*                                       field to be read. The host has to put the value
*                                       in bytes and needs to be even number
* Return value:
*                   The content of required FlexRay memory field
*
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(uint16, FR_CODE) Fr_LLD_Low_Level_Access_Read_Memory(VAR(uint16, FR_VAR) Fr_memory_address)
{
    /* Read the content of the required FlexRay memory field */
    if (Fr_HW_config_ptr == NULL_PTR)
    {
        return (uint16)0;
    }
    return *((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) )(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + (Fr_memory_address / 2U)); /* polyspace RTE:NIV,IDP */
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/************************************************************************************
* Function name:    Fr_LLD_Low_Level_Access_Write_Memory
* Description:      Write given value to the FlexRay memory field
*
* Function arguments: 
*                   Fr_memory_address       This parameter determines to which 
*                                           FlexRay memory field shall be written the value put in Fr_value parameter
*                   Fr_value                Value which should be written into required register
* Return value:
*                   none
*************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_LLD_Low_Level_Access_Write_Memory(VAR(uint16, FR_VAR) Fr_memory_address, VAR(uint16, FR_VAR) Fr_value)
{
     /* Write given value to the FlexRay register */
    if (Fr_HW_config_ptr == NULL_PTR)
    {
        return;
    }
    *((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) )(Fr_HW_config_ptr->CC_FlexRay_memory_base_address) + (Fr_memory_address / 2U)) = Fr_value; /* polyspace RTE:IDP */
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_CheckCCAccess(VAR(void, FR_VAR))
{
    VAR(uint16, AUTOMATIC) RegVal = 0U;   /* Temporary variable for register access */
    VAR(Std_ReturnType, AUTOMATIC) ret = E_OK;
    if (Fr_CC_reg_ptr == NULL_PTR)
    {
        return E_NOT_OK;
    }
    RegVal = Fr_CC_reg_ptr[FrMCR]; /* polyspace RTE:NIV,IDP */  /* Enable FlexRay module */
    if ((RegVal & FrMCR_MEN) != FrMCR_MEN)
    {
        /* FlexRay module is not enabled, report error */
        ret = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }

    return ret;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
/***************************************************************************************************
* @function_name    Fr_Driver_SetAbsTimers
*
* @brief            FrIP function for the Fr_SetAbsTimers API
* @description      

* @param[in]        ctrlIdx - Index of FlexRay CC
* @return           Std_ReturnType
*
* @implements       Fr_Driver_SetAbsTimers
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_SetAbsTimers(VAR(uint8, AUTOMATIC) timerIdx,VAR(uint8, AUTOMATIC) cycle,VAR(uint16, AUTOMATIC) offset)
{
    /*only for absolute timer*/
    volatile VAR(uint16, AUTOMATIC) temp_value_1;               /* Temporary variable used for bit operation */
    volatile VAR(uint32, AUTOMATIC) temp_value_2;               /* Temporary variable used for bit operation */
    volatile VAR(uint16, AUTOMATIC) temp_timer_config_reg = 0U;  /* Timer configuration and control register */
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_OK;

    
    if((Fr_timer_ID_type)timerIdx == FR_TIMER_T1)    /* Configure FR module registers for timer T1 */
    {
        Fr_Stop_Timer((Fr_timer_ID_type)timerIdx);
        /* Configure TI1CYSR register */
        SchM_Enter_Fr_EXCLUSIVE_AREA_03();
        temp_value_1 = 0x0000U;                      /* Clear */
        temp_value_1 |= (VAR(uint16, AUTOMATIC))(((VAR(uint16, AUTOMATIC))cycle & 0x3FU) << 8U); /* Set cycle filter value */
        temp_value_1 |= (0x3FU);         /* Set cycle filter mask */
        Fr_CC_reg_ptr[FrTI1CYSR] = temp_value_1; /* polyspace RTE:IDP */                                        /* Store Timer 1 Cycle Set reg. */

        /* Configure TI1MTOR register */
        temp_value_2 = 0x0000U;                      /* Clear */
        temp_value_2 |= (VAR(uint16, AUTOMATIC))(offset & 0x3FFFU); /* Set macrotick value */
        Fr_CC_reg_ptr[FrTI1MTOR] = (VAR(uint16, AUTOMATIC))temp_value_2; /* polyspace RTE:IDP */                                        /* Store Timer 1 Macrotick Offset */
        temp_timer_config_reg |= FrTICCR_T1_REP; 
        Fr_CC_reg_ptr[FrTICCR] |= temp_timer_config_reg; /* polyspace RTE:NIV */
        SchM_Exit_Fr_EXCLUSIVE_AREA_03();
        Fr_LLD_Start_Timer((Fr_timer_ID_type)timerIdx);
        retVal = E_OK;
    }
    else if((Fr_timer_ID_type)timerIdx == FR_TIMER_T2)  /* Configure FR module registers for timer T2 */
    {
        Fr_Stop_Timer((Fr_timer_ID_type)timerIdx);
        /* Configure TI2CR0 register */
        SchM_Enter_Fr_EXCLUSIVE_AREA_03();
        temp_value_1 = 0x0000U;                      /* Clear */
        temp_value_1 |= (VAR(uint16, AUTOMATIC))(((VAR(uint16, AUTOMATIC))cycle & 0x3FU) << 8U); /* Set cycle filter value */
        temp_value_1 |= (0x3FU);         /* Set cycle filter mask */
        Fr_CC_reg_ptr[FrTI2CR0] = temp_value_1; /* polyspace RTE:IDP */                                         /* Store Timer 2 Configuration 0 */

        /* Configure TI2CR1 register */
        temp_value_2 = 0x0000U;                      /* Clear */
        temp_value_2 |= (VAR(uint16, AUTOMATIC))(offset & 0x3FFFU); /* Set macrotick value */
        Fr_CC_reg_ptr[FrTI2CR1] = (VAR(uint16, AUTOMATIC))temp_value_2; /* polyspace RTE:IDP */                                          /* Store Timer 2 Configuration 1 */
        temp_timer_config_reg |= FrTICCR_T2_REP; 
        Fr_CC_reg_ptr[FrTICCR] |= temp_timer_config_reg; /* polyspace RTE:NIV */
        SchM_Exit_Fr_EXCLUSIVE_AREA_03();
        Fr_LLD_Start_Timer((Fr_timer_ID_type)timerIdx);
        retVal = E_OK;
    }
    else
    {
        retVal = E_NOT_OK;
    }
    return retVal;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_Driver_DisableTimers(VAR(void, FR_VAR))
{
    Fr_Stop_Timer(FR_TIMER_T1);
    Fr_Stop_Timer(FR_TIMER_T2);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_Driver_GetChannelStatus
*
* @brief            FrIP function for the Fr_GetChannelStatus API
* @description      Reads the aggregated channel status, NIT status and symbol window status from 
*                   FLEXRAY_PSR2_ADDR16, and FLEXRAY_PSR3_ADDR16 registers
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[out]       channelAStatusPtr - Address of the variable the channel A status is stored to
* @param[out]       channelAStatusPtr - Address of the variable the channel A status is stored to
* @return           none
*
* @implements       Fr_Driver_GetChannelStatus
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_Driver_GetChannelStatus
( 
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelAStatusPtr, 
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelBStatusPtr
)
{
    VAR(uint16, AUTOMATIC) Temp_val; /* Temporary variable for register access */
    
    /* Read PSR2 register */
    Temp_val = Fr_CC_reg_ptr[FrPSR2]; /* polyspace RTE:NIV,IDP */ /*Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_PSR2_ADDR16); */
    
    *channelBStatusPtr = (VAR(uint16, AUTOMATIC))((Temp_val & 0xFC00U) >> 2U);
    *channelAStatusPtr = (VAR(uint16, AUTOMATIC))((Temp_val & 0x03F0U) << 4U);
    
    /* Read PSR3 register */
    Temp_val = Fr_CC_reg_ptr[FrPSR3]; /* polyspace RTE:NIV,IDP */
    
    *channelBStatusPtr |= (VAR(uint16, AUTOMATIC))((Temp_val & 0xFC00U) >> 8);
    *channelAStatusPtr = (VAR(uint16, AUTOMATIC))((Temp_val & 0x03F0U) | (*channelAStatusPtr));
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_InvokeCHICommand(VAR(uint16, AUTOMATIC) CHICommand)
{
    VAR(uint16, AUTOMATIC) i;
    VAR(Std_ReturnType, AUTOMATIC) retval = E_OK;
    i = 0U;      /* Clear temporary counter */
   /* Wait till Protocol Command Write is not busy */
    if (Fr_CC_reg_ptr == NULL_PTR)
    {
        return E_NOT_OK;
    }
    while((i < FR_MAX_WAIT_CYCLES) && (Fr_CC_reg_ptr[FrPOCR] & FrPOCR_BSY)) /* polyspace RTE:NIV,IDP */
    {
        i++;        /* Increment temporary counter */
    }
    if(i == FR_MAX_WAIT_CYCLES)
    {
        retval = E_NOT_OK;     /* Return FR_NOT_SUCCESS in case any error */
    }
    Fr_CC_reg_ptr[FrPOCR] = (CHICommand  | FrPOCR_WME);

    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_SetWakeupChannel(VAR(Fr_ChannelType, FR_VAR) Fr_ChnlIdx)
{
    VAR(Fr_LLDriver_StatusType, FR_VAR) ret = StatusSuss;
    VAR(uint16, FR_VAR) temp_value = 0U;
    VAR(Std_ReturnType, FR_VAR) retval = E_NOT_OK;

    ret  =   Fr_LLD_Enter_Configuration_Mode();

    if (ret == StatusErro)
    {
        retval = E_NOT_OK;
    }
    else
    {
        if(Fr_ChnlIdx == FR_CHANNEL_A)
        {
            temp_value = (VAR(uint16, AUTOMATIC))FR_CHANNEL_A;
        }
        else
        {
            temp_value = (VAR(uint16, AUTOMATIC))FR_CHANNEL_B;
        }
        temp_value = (VAR(uint16, AUTOMATIC))(temp_value << 14);

        Fr_CC_reg_ptr[FrPCR10] |= temp_value; /* polyspace RTE:NIV,IDP */
        /* CHI cmd  POCr leave Config */
        ret = Fr_LLD_Leave_Configuration_Mode();
        if(ret == StatusErro)
        {
            retval = E_NOT_OK;

        }
        else
        {
            retval = E_OK;
        }

    }
    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_FrExtendedLPduReport(P2CONST(Fr_CtrlCfgType, AUTOMATIC, *) pCtrlCfg,
                                                                    VAR(uint16, AUTOMATIC) mb_index, P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) pSlotAssignment)
{
    
    VAR(Std_ReturnType, AUTOMATIC) ret = E_OK;
    P2CONST(Fr_buffer_info_type, AUTOMATIC, *) Fr_buffers_config_ptr;
    P2CONST(Fr_receive_buffer_config_type, AUTOMATIC, *) Fr_receive_buffer_config_ptr;   /* Temporary pointer to receive configuration data */
    P2CONST(Fr_transmit_buffer_config_type, AUTOMATIC, *) Fr_transmit_buffer_config_ptr; 
    P2CONST(Fr_FIFO_config_type, AUTOMATIC, *) Fr_FIFO_config_ptr;   /* Temporary pointer to receive FIFO configuration data */

    Fr_buffers_config_ptr = pCtrlCfg->Fr_buffers_config_temp_ptr;
   
    switch(Fr_buffers_config_ptr[mb_index].buffer_type)
    {
        case FR_RECEIVE_BUFFER:
            Fr_receive_buffer_config_ptr = ((P2VAR(Fr_receive_buffer_config_type, AUTOMATIC,FR_APPL_DATA))(Fr_buffers_config_ptr[mb_index].buffer_config_ptr));
            pSlotAssignment->channelId = Fr_receive_buffer_config_ptr->receive_channel_enable;
            pSlotAssignment->SlotId = Fr_receive_buffer_config_ptr->receive_frame_ID;
            ret = E_OK;
            break;
        case FR_TRANSMIT_BUFFER:
            Fr_transmit_buffer_config_ptr = ((P2VAR(Fr_transmit_buffer_config_type, AUTOMATIC,FR_APPL_DATA))(Fr_buffers_config_ptr[mb_index].buffer_config_ptr));
            pSlotAssignment->channelId = Fr_transmit_buffer_config_ptr->transmit_channel_enable;
            pSlotAssignment->SlotId = Fr_transmit_buffer_config_ptr->transmit_frame_ID;
            ret = E_OK;
            break;
        case FR_RECEIVE_FIFO:
            Fr_FIFO_config_ptr = ((P2VAR(Fr_FIFO_config_type, AUTOMATIC,FR_APPL_DATA))(Fr_buffers_config_ptr[mb_index].buffer_config_ptr));
            pSlotAssignment->channelId = Fr_FIFO_config_ptr->FIFO_channel;
            ret = E_OK;
            break;
        case FR_RECEIVE_SHADOW:
            ret = E_NOT_OK;
            break;
        default:
            break;

    }

    pSlotAssignment->Cycle = (VAR(uint8, AUTOMATIC))(Fr_CC_reg_ptr[FrCYCTR]); /* polyspace RTE:NIV */

    return ret;
    
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_Driver_AckAbsTimerIRQ(VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx)
{

    if((Fr_timer_ID_type)Fr_AbsTimerIdx == FR_TIMER_T1)
    {
        Fr_CC_reg_ptr[FrPIFR0] = FrPIFR0_TI1_IF; /* polyspace RTE:IDP */
    }
    else
    {
        Fr_CC_reg_ptr[FrPIFR0] = FrPIFR0_TI2_IF; /* polyspace RTE:IDP */
    }

}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(boolean, FR_CODE) Fr_Driver_GetAbsoluteTimerIRQStatus(VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx)
{
    volatile VAR(uint16, AUTOMATIC) temp_value;
    VAR(boolean, AUTOMATIC) retval = FALSE;

    temp_value = Fr_CC_reg_ptr[FrPIFR0]; /* polyspace RTE:NIV,IDP */

    if (0U == Fr_AbsTimerIdx)
    {
        /* Timer 1 */
        if (0U != (temp_value & FrPIFR0_TI1_IF))
        {
            /* Interrupt flag has been set */
            retval = TRUE;
        }
    } 
    else
    {
        /* Timer 2 */
        if (0U != (temp_value & FrPIFR0_TI2_IF))
        {
            /* Interrupt flag has been set */
            retval = TRUE;
        }
    }

    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_ReadCCConfig(P2CONST(Fr_low_level_config_type, AUTOMATIC, *) Fr_low_level_config_ptr)
{
    VAR(uint16, AUTOMATIC) temp_value_1;
    VAR(uint32, AUTOMATIC) temp_value_2;
    VAR(uint16, AUTOMATIC) temp_value_3;
    VAR(Std_ReturnType, AUTOMATIC) retval = E_OK;
    /* PCR0 */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_low_level_config_ptr->GD_ACTION_POINT_OFFSET - 1U);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 10U) | Fr_low_level_config_ptr->GD_STATIC_SLOT);
    if (Fr_CC_reg_ptr == NULL_PTR)
    {
        return E_NOT_OK;
    }
    if(Fr_CC_reg_ptr[FrPCR0] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }

    /* PCR1  */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 14U) | (Fr_low_level_config_ptr->G_MACRO_PER_CYCLE - Fr_low_level_config_ptr->GD_STATIC_SLOT));
    if(Fr_CC_reg_ptr[FrPCR1] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    
    /* PCR2  */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_MINISLOT - (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_MINI_SLOT_ACTION_POINT_OFFSET - 1U);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 10U) | Fr_low_level_config_ptr->G_NUMBER_OF_STATIC_SLOTS);
    if(Fr_CC_reg_ptr[FrPCR2] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }

    /* PCR3  */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_WAKEUP_SYMBOL_RX_LOW;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 5U) | (VAR(uint16, AUTOMATIC))(Fr_low_level_config_ptr->GD_MINI_SLOT_ACTION_POINT_OFFSET - 1U));
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 5U) | Fr_low_level_config_ptr->G_COLD_START_ATTEMPTS);
    if(Fr_CC_reg_ptr[FrPCR3] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }

    /* PCR4  */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_low_level_config_ptr->GD_CAS_RX_LOW_MAX - 1U);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 9U) | Fr_low_level_config_ptr->GD_WAKEUP_SYMBOL_RX_WINDOW);
    if(Fr_CC_reg_ptr[FrPCR4] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }

    /* PCR5  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->GD_TSS_TRANSMITTER;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 6U) | (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_WAKEUP_SYMBOL_TX_LOW);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 6U) | (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_WAKEUP_SYMBOL_RX_IDLE);
    if(Fr_CC_reg_ptr[FrPCR5] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }

    /* PCR6  */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_SYMBOL_WINDOW - (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_ACTION_POINT_OFFSET - 1U);  /* PRQA S 2892,2902 */
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 7U) | (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->P_MACRO_INITIAL_OFFSET_A);
    temp_value_1 &= 0x7fffU;
    if(Fr_CC_reg_ptr[FrPCR6] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }

    /* PCR7  */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->P_DECODING_CORRECTION + (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->P_DELAY_COMPENSATION_CHB + 2U);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 7U) | (VAR(uint16, AUTOMATIC))(Fr_low_level_config_ptr->P_MICRO_PER_MACRO_NOM / 2U));
    if(Fr_CC_reg_ptr[FrPCR7] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }

    /* PCR8  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->G_MAX_WITHOUT_CLOCK_CORRECTION_FATAL;
    temp_value_1 = (VAR(uint16, AUTOMATIC))(((temp_value_1 << 4U) | (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->G_MAX_WITHOUT_CLOCK_CORRECTION_PASSIVE));
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 8U) | (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_WAKEUP_SYMBOL_TX_IDLE);
    if(Fr_CC_reg_ptr[FrPCR8] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    
    /* PCR9  */
    temp_value_1 = 0x0000U;
    if(Fr_low_level_config_ptr->G_NUMBER_OF_MINISLOTS != 0U)
    {
      temp_value_1 = TRUE;
    }
    else                                                  
    {
      temp_value_1 = FALSE;
    }

    if(Fr_low_level_config_ptr->GD_SYMBOL_WINDOW != 0U)
    {
      temp_value_3 = TRUE;
    } 
    else
    {
      temp_value_3 = FALSE; 
    }
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 1U) | temp_value_3);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 14U) | Fr_low_level_config_ptr->P_OFFSET_CORRECTION_OUT);
    if(Fr_CC_reg_ptr[FrPCR9] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }

    /* PCR10  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->P_SINGLE_SLOT_ENABLED;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 1U) | (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->P_WAKEUP_CHANNEL);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 14U) | Fr_low_level_config_ptr->G_MACRO_PER_CYCLE);
    if(Fr_CC_reg_ptr[FrPCR10] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
      
    /* PCR11  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->P_KEY_SLOT_USED_FOR_STARTUP;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 1U) | Fr_low_level_config_ptr->P_KEY_SLOT_USED_FOR_SYNC);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 14U) | Fr_low_level_config_ptr->G_OFFSET_CORRECTION_START);
    if(Fr_CC_reg_ptr[FrPCR11] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }

    /* PCR12  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->P_ALLOW_PASSIVE_TO_ACTIVE;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 11U) | Fr_low_level_config_ptr->P_KEY_SLOT_HEADER_CRC);
    if(Fr_CC_reg_ptr[FrPCR12] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    
    /* PCR13  */
    temp_value_1 = 0x0000U;
    if(Fr_low_level_config_ptr->GD_ACTION_POINT_OFFSET >= Fr_low_level_config_ptr->GD_MINI_SLOT_ACTION_POINT_OFFSET)
    {
      temp_value_1 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->GD_ACTION_POINT_OFFSET - 1U);
    }
    else
    {
      temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_low_level_config_ptr->GD_MINI_SLOT_ACTION_POINT_OFFSET - 1U);
    }  
    temp_value_1 = (VAR(uint16, AUTOMATIC))(temp_value_1 << 10U);
    temp_value_1 |= (VAR(uint16, AUTOMATIC))(Fr_low_level_config_ptr->GD_STATIC_SLOT -  Fr_low_level_config_ptr->GD_ACTION_POINT_OFFSET - 1U);
    if(Fr_CC_reg_ptr[FrPCR13] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    
    /* PCR14  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_2 = (VAR(uint32, AUTOMATIC))((Fr_low_level_config_ptr->PD_LISTEN_TIMEOUT - 1U) & 0x001F0000U);
    temp_value_1 = Fr_low_level_config_ptr->P_RATE_CORRECTION_OUT;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 5U) | ((VAR(uint16, AUTOMATIC))(temp_value_2 >> 16U)));
    temp_value_1 &= 0xFFF0U;
    if((Fr_CC_reg_ptr[FrPCR14] & 0xFFF0U) != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    
    /* PCR15  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_2 = (Fr_low_level_config_ptr->PD_LISTEN_TIMEOUT - 1U) & 0x0000FFFFU;
    temp_value_1 = (VAR(uint16, AUTOMATIC))temp_value_2;
    /* Fr_CC_reg_ptr[FrPCR15] = temp_value_1; */
    if(Fr_CC_reg_ptr[FrPCR15] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    
    /* PCR16  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_1 = Fr_low_level_config_ptr->P_MACRO_INITIAL_OFFSET_B;
    temp_value_2 = (VAR(uint16, AUTOMATIC))(((Fr_low_level_config_ptr->G_LISTEN_NOISE * Fr_low_level_config_ptr->PD_LISTEN_TIMEOUT) - 1U) & 0x01FF0000U);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 9U ) | ((VAR(uint16, AUTOMATIC))(temp_value_2 >> 16U)));
    temp_value_1 &= 0xFFF0U;
    if((Fr_CC_reg_ptr[FrPCR16] & 0xFFF0U) != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    
    /* PCR17  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_2 = ((Fr_low_level_config_ptr->G_LISTEN_NOISE * Fr_low_level_config_ptr->PD_LISTEN_TIMEOUT) - 1U) & 0x0000FFFFU;
    temp_value_1 = (VAR(uint16, AUTOMATIC))temp_value_2;
    if(Fr_CC_reg_ptr[FrPCR17] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    /* PCR18  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->P_WAKEUP_PATTERN;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 10U) | Fr_low_level_config_ptr->P_KEY_SLOT_ID);
    if(Fr_CC_reg_ptr[FrPCR18] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    /* PCR19  */
    temp_value_1 = 0x0000U;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->P_DECODING_CORRECTION + (VAR(uint16, AUTOMATIC))Fr_low_level_config_ptr->P_DELAY_COMPENSATION_CHA + 2U);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 7U) | Fr_low_level_config_ptr->G_PAYLOAD_LENGTH_STATIC);
    if(Fr_CC_reg_ptr[FrPCR19] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    /* PCR20  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->P_MICRO_INITIAL_OFFSET_B;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 8U) | Fr_low_level_config_ptr->P_MICRO_INITIAL_OFFSET_A);
    if(Fr_CC_reg_ptr[FrPCR20] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
        
    /* PCR21  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->P_EXTERN_RATE_CORRECTION;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 13U) | (Fr_low_level_config_ptr->G_NUMBER_OF_MINISLOTS - Fr_low_level_config_ptr->P_LATEST_TX));
    if(Fr_CC_reg_ptr[FrPCR21] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    /* PCR22  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_1 =(VAR(uint16, AUTOMATIC))( Fr_low_level_config_ptr->PD_ACCEPTED_STARTUP_RANGE - Fr_low_level_config_ptr->P_DELAY_COMPENSATION_CHA);
    temp_value_2 = (VAR(uint16, AUTOMATIC))((Fr_low_level_config_ptr->P_MICRO_PER_CYCLE) & 0x000F0000U);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 4U) | ((VAR(uint16, AUTOMATIC))(temp_value_2 >> 16U)));
    temp_value_1 &= 0xFFF0U;
    if((Fr_CC_reg_ptr[FrPCR22] & 0xFFF0U) != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    /* PCR23  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_2 = Fr_low_level_config_ptr->P_MICRO_PER_CYCLE & 0x0000FFFFU;
    temp_value_1 = (VAR(uint16, AUTOMATIC))temp_value_2;
    if(Fr_CC_reg_ptr[FrPCR23] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    /* PCR24  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_1 = Fr_low_level_config_ptr->P_CLUSTER_DRIFT_DAMPING;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 7U) | Fr_low_level_config_ptr->P_PAYLOAD_LENGTH_DYN_MAX);
    temp_value_2 = (VAR(uint16, AUTOMATIC))((Fr_low_level_config_ptr->P_MICRO_PER_CYCLE - Fr_low_level_config_ptr->PD_MAX_DRIFT) & 0x000F0000U);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 4U) | ((VAR(uint16, AUTOMATIC))(temp_value_2 >> 16U)));
    temp_value_1 &= 0xFFF0U;
    if((Fr_CC_reg_ptr[FrPCR24] & 0xFFF0U) != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    /* PCR25  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_2 = (Fr_low_level_config_ptr->P_MICRO_PER_CYCLE - Fr_low_level_config_ptr->PD_MAX_DRIFT) & 0x0000FFFFU;
    temp_value_1 = (VAR(uint16, AUTOMATIC))temp_value_2;
    /* Fr_CC_reg_ptr[FrPCR25] = temp_value_1; */
    if(Fr_CC_reg_ptr[FrPCR25] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    /* PCR26  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_1 = Fr_low_level_config_ptr->P_ALLOW_HALT_DUE_TO_CLOCK;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 11U));
    temp_value_1 |= (VAR(uint16, AUTOMATIC))((Fr_low_level_config_ptr->PD_ACCEPTED_STARTUP_RANGE - Fr_low_level_config_ptr->P_DELAY_COMPENSATION_CHB));
    temp_value_2 = (VAR(uint16, AUTOMATIC))((Fr_low_level_config_ptr->P_MICRO_PER_CYCLE + Fr_low_level_config_ptr->PD_MAX_DRIFT) & 0x000F0000U);
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 4U) | ((VAR(uint16, AUTOMATIC))(temp_value_2 >> 16U)));
    temp_value_1 &= 0xFFF0U;
    if((Fr_CC_reg_ptr[FrPCR26] & 0xFFF0U) != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    /* PCR27  */
    temp_value_1 = 0x0000U;
    temp_value_2 = 0x00000000U;
    temp_value_2 = (Fr_low_level_config_ptr->P_MICRO_PER_CYCLE + Fr_low_level_config_ptr->PD_MAX_DRIFT) & 0x0000FFFFU;
    temp_value_1 = (VAR(uint16, AUTOMATIC))temp_value_2;
    if(Fr_CC_reg_ptr[FrPCR27] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    /* PCR28  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->GD_DYNAMIC_SLOT_IDLE_PHASE;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 14U));
    temp_value_1 |= (VAR(uint16, AUTOMATIC))((Fr_low_level_config_ptr->G_MACRO_PER_CYCLE - Fr_low_level_config_ptr->G_OFFSET_CORRECTION_START));
    if(Fr_CC_reg_ptr[FrPCR28] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    /* PCR29  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->P_EXTERN_OFFSET_CORRECTION;
    temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_1 << 13U) | (VAR(uint16, AUTOMATIC))(Fr_low_level_config_ptr->G_NUMBER_OF_MINISLOTS - 1U)); /* PRQA S 2912 */
    if(Fr_CC_reg_ptr[FrPCR29] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }
    /* PCR30  */
    temp_value_1 = 0x0000U;
    temp_value_1 = Fr_low_level_config_ptr->G_SYNC_NODE_MAX;
    if(Fr_CC_reg_ptr[FrPCR30] != temp_value_1) /* polyspace RTE:NIV,IDP */
    {
        retval = E_NOT_OK;
    }

    return retval;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_GetPOCStatus(P2VAR(Fr_POCStatusType, AUTOMATIC, FR_APPL_DATA) pPocState)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (VAR(Std_ReturnType, AUTOMATIC))E_OK;

    VAR(uint16, AUTOMATIC) PSR0 = Fr_CC_reg_ptr[FrPSR0]; /* polyspace RTE:NIV,IDP */
    VAR(uint16, AUTOMATIC) PSR1 = Fr_CC_reg_ptr[FrPSR1]; /* polyspace RTE:NIV,IDP */

    if((PSR1 & FrPSR1_FRZ) == FrPSR1_FRZ)
    {
        pPocState->State = FR_POCSTATE_HALT;
        pPocState->Freeze = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else
    {
        pPocState->State = Fr_LLD_Get_POC_State();
        pPocState->Freeze = (VAR(boolean, AUTOMATIC))FALSE;
    }

    if(pPocState->State == FR_POCSTATE_STARTUP)
    {
        if(Fr_Driver_GetStartupState(PSR0, &pPocState->StartupState) == (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK)
        {
            retVal = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK;
        }
    }
    else
    {
        pPocState->StartupState = FR_STARTUP_UNDEFINED;
    }

    pPocState->WakeupStatus = Fr_LLD_Get_Wakeup_State();

    if(Fr_Driver_GetSlotMode(PSR0, &pPocState->SlotMode) == (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK)
    {
        retVal = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK;
    }

    if(Fr_Driver_GetErrorMode(PSR0, &pPocState->ErrorMode) == (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK)
    {
        retVal = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK;
    }

    if((PSR1 & FrPSR1_HHR) == FrPSR1_HHR)
    {
        pPocState->CHIHaltRequest = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else
    {
        pPocState->CHIHaltRequest = (VAR(boolean, AUTOMATIC))FALSE;
    }

    if((PSR1 & FrPSR1_CPN) == FrPSR1_CPN)
    {
        pPocState->ColdstartNoise = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else
    {
        pPocState->ColdstartNoise = (VAR(boolean, AUTOMATIC))FALSE;
    }

    return retVal;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_GetStartupState(
    VAR(uint16, AUTOMATIC) PSR0,
    P2VAR(Fr_StartupStateType, AUTOMATIC, FR_APPL_DATA) pStartupState
)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (VAR(Std_ReturnType, AUTOMATIC))E_OK;
    switch(PSR0 & ((VAR(uint16, AUTOMATIC))0x00F0U))
    {
        case FrPSR0_STARTUPSTATE_COLDSTART_COLLISION_RESOLUTION:{
            *pStartupState = FR_STARTUP_COLDSTART_COLLISION_RESOLUTION;
            break;
            }
        case FrPSR0_STARTUPSTATE_COLDSTART_LISTEN:{
            *pStartupState = FR_STARTUP_COLDSTART_LISTEN;
            break;
            }
        case FrPSR0_STARTUPSTATE_INTEGRATION_CONSISTENCY_CHECK:{
            *pStartupState = FR_STARTUP_INTEGRATION_CONSISTENCY_CHECK;
            break;
            }
        case FrPSR0_STARTUPSTATE_INTEGRATION_LISTEN:{
            *pStartupState = FR_STARTUP_INTEGRATION_LISTEN;
            break;
            }
        case FrPSR0_STARTUPSTATE_INITIALIZE_SCHEDULE:{
            *pStartupState = FR_STARTUP_INITIALIZE_SCHEDULE;
            break;
            }
        case FrPSR0_STARTUPSTATE_COLDSTART_CONSISTENCY_CHECK:{
            *pStartupState = FR_STARTUP_COLDSTART_CONSISTENCY_CHECK;
            break;
            }
        case FrPSR0_STARTUPSTATE_INTEGRATION_COLDSTART_CHECK:{
            *pStartupState = FR_STARTUP_INTEGRATION_COLDSTART_CHECK;
            break;
            }
        case FrPSR0_STARTUPSTATE_COLDSTART_GAP:{
            *pStartupState = FR_STARTUP_COLDSTART_GAP;
            break;
            }
        case FrPSR0_STARTUPSTATE_COLDSTART_JOIN:{
            *pStartupState = FR_STARTUP_COLDSTART_JOIN;
            break;
            }
        default :{
            *pStartupState = FR_STARTUP_UNDEFINED;
            retVal = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK;
            break;
            }
    }
    return retVal;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_GetSlotMode(
    VAR(uint16, AUTOMATIC) PSR0,
    P2VAR(Fr_SlotModeType, AUTOMATIC, FR_APPL_DATA) pSlotMode
)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (VAR(Std_ReturnType, AUTOMATIC))E_OK;
    switch (PSR0 & ((VAR(uint16, AUTOMATIC))0x3000U))
    {
        case FrPSR0_SLOTMODE_SINGLE:{
            *pSlotMode = FR_SLOTMODE_KEYSLOT;
            break;
            }
        case FrPSR0_SLOTMODE_ALL_PENDING:{
            *pSlotMode = FR_SLOTMODE_ALL_PENDING;
            break;
            }
        case FrPSR0_SLOTMODE_ALL:{
            *pSlotMode = FR_SLOTMODE_ALL;
            break;
            }
        default:{
            *pSlotMode = FR_SLOTMODE_SINGLE;
            retVal = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK;
            break;
            }
    }
    return retVal;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_GetErrorMode
(
    VAR(uint16, AUTOMATIC) u16RegValuePSR0,
    P2VAR(Fr_ErrorModeType, AUTOMATIC, FR_APPL_DATA) pErrorMode
)
{
    /* Initialize variable */
    VAR(Std_ReturnType, AUTOMATIC) retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);

    /* Determine the error mode */
    switch (u16RegValuePSR0 & ((VAR(uint16, AUTOMATIC))0xC000U))
    {
        case FrPSR0_ERRMODE_ACTIVE:
            /* Store the Error mode to location referenced by given pointer */
            *pErrorMode = FR_ERRORMODE_ACTIVE;
            break;

        case FrPSR0_ERRMODE_PASSIVE:
            /* Store the Error mode to location referenced by given pointer */
            *pErrorMode = FR_ERRORMODE_PASSIVE;
            break;

        case FrPSR0_ERRMODE_COMM_HALT:
            /* Store the Error mode to location referenced by given pointer */
            *pErrorMode = FR_ERRORMODE_COMM_HALT;
            break;

        default:
            /* Reserved value cannot occur */
            *pErrorMode = FR_ERRORMODE_ACTIVE;
            retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
            break;
    }
    return retVal;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_GetWakeupRxStatus
(
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) pu8WakeupRxStatus
)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint16, AUTOMATIC) u16TmpRegVal = 0U; /* Temporary variable for register access */

    /* Read PSR3 register */
    u16TmpRegVal = Fr_CC_reg_ptr[FrPSR3]; /* polyspace RTE:NIV,IDP */

    /* Store wakeup symbol received on channel A */
    *pu8WakeupRxStatus = (VAR(uint8, AUTOMATIC))((u16TmpRegVal & FrPSR3_WUA) >> 5U);

    /* Store wakeup symbol recieved on channel B */
    *pu8WakeupRxStatus |= (VAR(uint8, AUTOMATIC))((u16TmpRegVal & FrPSR3_WUB) >> 12U);

    /* Clear both WUA and WUB flags */
    if (0U != (u16TmpRegVal & (VAR(uint16, AUTOMATIC))(FrPSR3_WUB | FrPSR3_WUA)))
    {
        Fr_CC_reg_ptr[FrPSR3] = (FrPSR3_WUA|FrPSR3_WUB);         /* Clear flag */
    }

    if (0U == (Fr_CC_reg_ptr[FrPSR3] & (VAR(uint16, AUTOMATIC))(FrPSR3_WUA | FrPSR3_WUB))) /* polyspace RTE:NIV */
    {
        retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_OK); /* Flags were cleared */
    }

    return retVal;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_GetClockCorrection
(
    P2VAR(sint16, AUTOMATIC, FR_APPL_DATA) ps16RateCorrection,
    P2VAR(sint32, AUTOMATIC, FR_APPL_DATA) ps32OffsetCorrection
)
{
    VAR(uint32, AUTOMATIC) u32RateOffsetCorrMax = 0U;
    VAR(sint16, AUTOMATIC) s16TmpVal = (sint16)0;
    VAR(Std_ReturnType, AUTOMATIC) retVal = (VAR(Std_ReturnType, AUTOMATIC))E_OK;

    /* Get pRateCorrectionOut maximum magnitude from configuration */
    u32RateOffsetCorrMax = (VAR(uint32,AUTOMATIC))(Fr_CC_reg_ptr[FrPCR14] & FrPcr14_bit); /* polyspace RTE:NIV,IDP */
    /* Read signed extended rate correction value */
    *ps16RateCorrection = (VAR(sint16, AUTOMATIC))Fr_CC_reg_ptr[FrRTCORVR]; /* polyspace RTE:NIV */
    /* Prepare absolute value */
    s16TmpVal = *ps16RateCorrection;

    if (s16TmpVal < 0)
    {
        s16TmpVal = (VAR(sint16, AUTOMATIC))(-(s16TmpVal)); /* polyspace RTE:OVFL */
    }
    /* Check range */
    if (s16TmpVal > (VAR(sint16, AUTOMATIC))u32RateOffsetCorrMax)
    {
        /* Not-In-Range, use saturated value */
        *ps16RateCorrection = (VAR(sint16, AUTOMATIC))u32RateOffsetCorrMax;
        /* Indicate error */
        retVal = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK;
    }

    /* Get pOffsetCorrectionOut maximum magnitude from configuration */
    u32RateOffsetCorrMax = (VAR(uint32,AUTOMATIC))(Fr_CC_reg_ptr[FrPCR9] & FrPcr9_bit); /* polyspace RTE:NIV */
    /* Read offset correction value */
    s16TmpVal = (VAR(sint16, AUTOMATIC))Fr_CC_reg_ptr[FrOFCORVR]; /* polyspace RTE:NIV */

    if (s16TmpVal < 0)
    {
        s16TmpVal = (VAR(sint16, AUTOMATIC))(-(s16TmpVal)); /* polyspace RTE:OVFL */
    }
    /* Check range */
    if (s16TmpVal > (VAR(sint16, AUTOMATIC))(u32RateOffsetCorrMax))
    {
        /* Not-In-Range, use saturated value */
        *ps32OffsetCorrection = (VAR(sint16, AUTOMATIC))u32RateOffsetCorrMax;
        /* Indicate error */
        retVal = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK;
    }
    else
    {
        /* Store the output value */
        *ps32OffsetCorrection = (VAR(sint32, AUTOMATIC))s16TmpVal;
    }

    return retVal;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_CancelTxLPdu
(
    VAR(uint16, AUTOMATIC) Mbidx,
    P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) pbPendingStatus
)
{
     /* Set initial return value */
     VAR(Std_ReturnType, AUTOMATIC) ret = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
     VAR(uint16, AUTOMATIC) MbRegOffset = 0U;
     VAR(uint16, AUTOMATIC) TempRegVal = 0U;

    /* Temporary offset address of MB configuration registers */
    MbRegOffset = (VAR(uint16, AUTOMATIC))(Mbidx * 4U);

    /* Read FR_MBCCSR register value */
    SchM_Enter_Fr_EXCLUSIVE_AREA_09();
    TempRegVal = Fr_CC_reg_ptr[FrMBCCSR0+MbRegOffset]; /* polyspace RTE:NIV,IDP */

    /* Message buffer configured for Tx ? */
    if (FrMBCCSR_MTD == (TempRegVal & FrMBCCSR_MTD))
    {
        /* Message buffer data ready for transmission ? */
        if (FrMBCCSR_CMT == (TempRegVal & FrMBCCSR_CMT))
        {   /* Yes - Data are ready for transmission */
            *pbPendingStatus = (VAR(boolean, AUTOMATIC))(TRUE);
            /* Lock MB -> write 1 to LCKT bit and 0 to the EDT bit in FR_MBCCSR register for current MB
              (write access to all other bits is ignored) */
            Fr_CC_reg_ptr[FrMBCCSR0+MbRegOffset] |= FrMBCCSR_LCKT; /* polyspace RTE:NIV */
            /* Fr_CC_reg_ptr[FrMBCCSR0+MbRegOffset] &= (~FrMBCCSR_EDT); */
            /* Select only necessary bits from MBCCSRx register */
            TempRegVal &= 0x7900U;
            /* Clear CMT bit */
            TempRegVal = (VAR(uint16, AUTOMATIC))(~FrMBCCSR_CMT)& (TempRegVal);
            Fr_CC_reg_ptr[FrMBCCSR0+MbRegOffset] = TempRegVal;
            /* Unlock MB -> write 1 to LCKT bit and 0 to the EDT bit in FR_MBCCSR register for current MB
              (write access to all other bits is ignored) */
            Fr_CC_reg_ptr[FrMBCCSR0+MbRegOffset] |= FrMBCCSR_LCKT;
            /*            Fr_CC_reg_ptr[FrMBCCSR0+MbRegOffset] &= (~FrMBCCSR_EDT); */
            /* Is the MB Unlocked and CMT cleared? */
            TempRegVal = Fr_CC_reg_ptr[FrMBCCSR0+MbRegOffset];
            if ((FrMBCCSR_LCKT != (TempRegVal & FrMBCCSR_LCKT)) && (FrMBCCSR_CMT != (TempRegVal & FrMBCCSR_CMT)))
            { /* Yes */
                ret = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            }
            else
            {
               /* This is HW error return E_NOT_OK and pbPendingStatus TRUE */
            }
        }
        else
        {
             /* Data is not ready for transmission return E_OK pbPendingStatus FALSE */
             ret = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
        }
    }
    else
    {
        /* MB is not configured for Tx -> return E_NOT_OK */
    }
    SchM_Exit_Fr_EXCLUSIVE_AREA_09();
    return ret;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_GetSyncFrameList
(
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg,
    VAR(uint8, AUTOMATIC) u8ListSize,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) pu16ChannelAEvenList,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) pu16ChannelBEvenList,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) pu16ChannelAOddList,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) pu16ChannelBOddList
)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) i = 0U;         /* Temporary variable for copying process access */
    VAR(uint16, AUTOMATIC) u16tmpSyncFrameCnt = 0U;   /* Temporary variable for Sync Frame Counter */
    VAR(uint8, AUTOMATIC) u8tmpListSizeChAEven = 0U; /* Temporary variable for u8ListSize chA even */
    VAR(uint8, AUTOMATIC) u8tmpListSizeChBEven = 0U; /* Temporary variable for u8ListSize chB even */
    VAR(uint8, AUTOMATIC) u8tmpListSizeChAOdd = 0U;  /* Temporary variable for u8ListSize chA odd */
    VAR(uint8, AUTOMATIC) u8tmpListSizeChBOdd = 0U;  /* Temporary variable for u8ListSize chB odd */
    VAR(uint8, AUTOMATIC) u8tmpListSizeMax = 0U;    /* Temporary variable for max u8ListSize */

    if (15U >= u8ListSize)
    {
        u8tmpListSizeMax = u8ListSize;
    }
    else
    {/* Maximum 15 syncframes shall be supported */
        u8tmpListSizeMax = 15U;
    }

    /* Check if both EVAL OVAL bits are set */
    if ((VAR(uint16, AUTOMATIC))((0x20) | (0x10)) == ((Fr_CC_reg_ptr[FrSFTCCSR]) & (VAR(uint16, AUTOMATIC))(0x20 | 0x10))) /* polyspace RTE:NIV,IDP */
    {
        /* Lock even/odd cycle tables */
        Fr_CC_reg_ptr[FrSFTCCSR] |= (0x4000U | 0x8000U); /* polyspace RTE:NIV */
        
        /* Check Even/Odd Cycle Table Lock Status */
        if ((VAR(uint16, AUTOMATIC))(0x80 | 0x40| 0x01) ==
            (Fr_CC_reg_ptr[FrSFTCCSR] & (VAR(uint16, AUTOMATIC))(0x80U | (VAR(uint16, AUTOMATIC))(0x40U | 0x01U))))
        {
            /* Read Sync Frame Counter for all subset of sync table */
            u16tmpSyncFrameCnt = Fr_CC_reg_ptr[FrSFCNTR]; /* polyspace RTE:NIV */
            /* Prepare list size for channel A Even Sync Frames */
            u8tmpListSizeChAEven = (VAR(uint8, AUTOMATIC))((u16tmpSyncFrameCnt & 0x0F00U) >> 8U);
            /* Prepare list size for channel B Even Sync Frames */
            u8tmpListSizeChBEven = (VAR(uint8, AUTOMATIC))((u16tmpSyncFrameCnt & 0xF000U) >> 12U);
            /* Prepare list size for channel A Odd Sync Frames */
            u8tmpListSizeChAOdd = (VAR(uint8, AUTOMATIC))(u16tmpSyncFrameCnt & 0x000FU);
            /* Prepare list size for channel B Odd Sync Frames */
            u8tmpListSizeChBOdd = (VAR(uint8, AUTOMATIC))((u16tmpSyncFrameCnt & 0x00F0U) >> 4U);

            for (i = 0U; i < u8tmpListSizeMax; i++)
            {
                pu16ChannelAEvenList[i] = 0U;
                pu16ChannelBEvenList[i] = 0U;
                pu16ChannelAOddList[i] = 0U;
                pu16ChannelBOddList[i] = 0U;
                if (i < u8tmpListSizeChAEven)
                {/* Copy channel A Even Sync Frame ID Table */    
                    pu16ChannelAEvenList[i] = *((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA))pCtrlCfg->Fr_HW_config_temp_ptr->CC_FlexRay_memory_base_address /* polyspace RTE:NIV,IDP */
                                            + (pCtrlCfg->Fr_HW_config_temp_ptr->sync_frame_table_offset) + i);
                }
                if (i < u8tmpListSizeChBEven)
                {/* Copy channel B Even Sync Frame ID Table */                  
                    pu16ChannelBEvenList[i] = *((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA))pCtrlCfg->Fr_HW_config_temp_ptr->CC_FlexRay_memory_base_address /* polyspace RTE:NIV,IDP */
                                            + (pCtrlCfg->Fr_HW_config_temp_ptr->sync_frame_table_offset + 0x001EU) + i);
                }
                if (i < u8tmpListSizeChAOdd)
                {/* Copy channel A Odd Sync Frame ID Table */
                    pu16ChannelAOddList[i] = *((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA))pCtrlCfg->Fr_HW_config_temp_ptr->CC_FlexRay_memory_base_address /* polyspace RTE:NIV,IDP */
                                            + (pCtrlCfg->Fr_HW_config_temp_ptr->sync_frame_table_offset + 0x003CU) + i);
                }
                if (i < u8tmpListSizeChBOdd)
                {/* Copy channel B Odd Sync Frame ID Table */                    
                    pu16ChannelBOddList[i] = *((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA))pCtrlCfg->Fr_HW_config_temp_ptr->CC_FlexRay_memory_base_address /* polyspace RTE:NIV,IDP */
                                            + (pCtrlCfg->Fr_HW_config_temp_ptr->sync_frame_table_offset + 0x005AU) + i);
                }
            }

            /* Unlock even/odd cycle table and enable generation*/
            Fr_CC_reg_ptr[FrSFTCCSR] |= (0x4000U | 0x8000U | 0x0001U);

            /* Check Even Cycle Table Lock Status */
            if (0x80U == (Fr_CC_reg_ptr[FrSFTCCSR] & 0x80U))
            {
                /* Tables were not unlocked */
            }
            /* Check Odd Cycle Table Lock Status */
            else if (0x40U == (Fr_CC_reg_ptr[FrSFTCCSR] & 0x40U))
            {
                /* Tables were not unlocked */
            }
            else
            {
                /* Tables were unlocked successfully*/
                retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            }
        }
        else
        {
            /* Tables were not locked return E_NOT_OK */
        }
    }
    else
    {
        /* EVAL OVAL bits are not set, table is not valid return E_NOT_OK  */
    }

    return retVal;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#if (FR_DISABLE_LPDU_SUPPORT == STD_ON)
#if (FR_RECONFIG_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_Driver_DisableLPdu
*
* @brief            FrIP function for the Fr_Flexray_DisableLPdu
* @param[in]        pCtrlCfg - Index of FlexRay CC
* @param[in]        LPduIdx - Index of LPdu to be reconfigured
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_DisableLPdu
(
    VAR(uint16, AUTOMATIC) Mbidx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) ret = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint16, AUTOMATIC) MbRegOffset = 0U;
    VAR(uint16, AUTOMATIC) PocStatus = 0U;

    /* Workaround for Errata e50119: Do not disable Message Buffer, while FlexRay is in STARTUP protocol State */
    PocStatus = Fr_CC_reg_ptr[FrPSR0]; /* polyspace RTE:NIV,IDP */

    if ((PocStatus & FrPSR0_PROTSTATE_STARTUP) != FrPSR0_PROTSTATE_STARTUP)
    {
        /* Get current MB Idx */
        /* TempMBIdx = pCtrlCfg->BufferConfigSetPtr->LPduInfoPtr[LPduIdx].MessageBufferNumber; */
        /* Offset from FR base address to the MB registers */
        MbRegOffset = (VAR(uint16, AUTOMATIC))(Mbidx * 4U);

        if (FrMBCCSR_EDS == (Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] & FrMBCCSR_EDS)) /* polyspace RTE:NIV,IDP */
        {
            Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] = FrMBCCSR_EDT;
        }
        /* Check if buffer has been successfully disabled */
        if (FrMBCCSR_EDS != (Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] & FrMBCCSR_EDS)) /* polyspace RTE:NIV,IDP */
        {
            ret = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
        }
        else
        {
            /* Buffer was not disabled return E_NOT_OK */
        }
    }
    return ret;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif /* FR_DISABLE_LPDU_SUPPORT */
#endif /* FR_RECONFIG_LPDU_SUPPORT == STD_ON */

#if (FR_RECONFIG_LPDU_SUPPORT == STD_ON)
#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_Driver_PrepareLPdu
*
* @brief            FrIP function for the Fr_PrepareLPdu API
* @param[in]        pCtrlCfg - Index of FlexRay CC
* @param[in]        LPduIdx - Index of LPdu to be prepared
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_PrepareLPdu
(
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg,
    VAR(uint16, AUTOMATIC) Mbindex,
    VAR(uint16, AUTOMATIC) LPduIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) ret = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint16, AUTOMATIC) TempMBNum = 0U;  /* Temporary variable for the MB index */
    P2CONST(Fr_buffer_info_type, AUTOMATIC, FR_APPL_CONST) buffer_info;


    buffer_info = pCtrlCfg->Fr_buffers_config_temp_ptr;
    /* Store the initial MB index */
    TempMBNum = LPduIdx;

    /* Determine the type of buffer */
    switch (buffer_info[Mbindex].buffer_type)
    {
        /* Transmit MB configuration */
        case FR_TRANSMIT_BUFFER:
            ret = Fr_Driver_PrepareTxBuffer(pCtrlCfg, Mbindex, TempMBNum);
            break;
        /* Receive MB configuration */
        case FR_RECEIVE_BUFFER:
            ret = Fr_Driver_PrepareRxBuffer(pCtrlCfg, Mbindex, TempMBNum);
            break;

        case FR_RECEIVE_FIFO: /* Intentional fall-through */

        case FR_RECEIVE_SHADOW: /* Intentional fall-through */

        default:
        {
            break;
        }
    }
    if ((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == ret) /* Continue only on success */
    {

        /* [SWS_Fr_00440],[SWS_Fr_00441]: Only if FR_RECONFIG_LPDU_SUPPORT is enabled: */
        /* Store information which LPdu is currently configured for given physical
           resource (individual MB) */
        Fr_InternalResource[pCtrlCfg->CtrlIdx][Mbindex] = LPduIdx; /* polyspace RTE:OBAI */
    }   /* E_OK == ret */

    return ret;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"


/***************************************************************************************************
* @function_name    Fr_Driver_PrepareTxBuffer
*
* @brief            Fr function for the Fr_Flexray_PrepareLPdu function.
* @description      Prepare transmission buffer.
* @param[in]        pCtrlCfg - Index of FlexRay CC
* @param[in]        LPduIdx - Index of LPdu to be prepared.
* @param[in]        TempMBNum - Temporary variable for the MB index.
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
static Std_ReturnType Fr_Driver_PrepareTxBuffer
(
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg,
    VAR(uint16, AUTOMATIC) Mbindex,
    VAR(uint16, AUTOMATIC) TempMBNum
)
{
    Std_ReturnType retVal = E_NOT_OK;
    VAR(uint16, AUTOMATIC) MbRegOffset = 0U;
    volatile VAR(uint8, AUTOMATIC) highest_txrx_mb_number = 0U;  /* The highest number of configured transmit or receive MB index -for verification */
    volatile VAR(uint16, AUTOMATIC) temp_value_1;               /* Temporary variable used for bit operation */
    volatile VAR(uint16, AUTOMATIC) temp_value_2;               /* Temporary variable used for bit operation */
    volatile VAR(uint16, AUTOMATIC) temp_value_3;               /* Temporary variable used for bit operation - for double buffered MB */
    volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) header_MB_ptr; /* Message buffer header pointer */
    static const Fr_buffer_info_type *Fr_buffers_config_ptr;
    Fr_transmit_buffer_config_type const * Fr_transmit_buffer_config_ptr; 
    /* P2CONST(Fr_CCTxBufferConfigType, AUTOMATIC, FR_APPL_CONST) pTxCfg = NULL_PTR; */

    /* Temporary offset address of MB configuration registers */
    MbRegOffset = (VAR(uint16, AUTOMATIC))(TempMBNum * 4U);
    /* Get the index from MBIDXn */
    /* Store the reference to transmit buffer configuration */
    Fr_buffers_config_ptr = pCtrlCfg->Fr_buffers_config_temp_ptr;
    Fr_transmit_buffer_config_ptr = ((Fr_transmit_buffer_config_type*)(pCtrlCfg->Fr_buffers_config_temp_ptr[Mbindex].buffer_config_ptr));

    /* MBIDXn must not be written because it could be changed by
    Rx shadow buffer index swap */

    /* Check whether the index value is in expected range */

    temp_value_1 = FrMBCCSR_EDT;    /* Store trigger enable/disbale bit into variable */
           
    /* Disable appropriate MB */
    if((Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] & FrMBCCSR_EDS)  != 0U) /* polyspace RTE:NIV,IDP */
    {
        Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] = temp_value_1;
    }
    /* Disable transmit side of the double buffered MB */
    if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
    {
        /* Disable appropriate MB */
        if((Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset + 4U] & FrMBCCSR_EDS)  != 0U) /* polyspace RTE:NIV,IDP */
        {
            Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset + 4U] = temp_value_1;
        }
    }
    
    /* Configure MBCCSRn register */
    temp_value_2 = FrMBCCSR_MTD;    /* Configure MB as Transmit */
    temp_value_2 |= FrMBCCSR_MBIF;    /* Configure MB as Transmit */
    temp_value_3 = 0x0000U;          /* Clear temporary variable */

    /* Double buffered TX MB configured? */
    if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
    {
        temp_value_2 |= FrMBCCSR_MBT;           /* Double buffered transmit MB */
        /* Immediate commit mode configured? (only for double buffered TX MB */
        if(Fr_transmit_buffer_config_ptr->transmission_commit_mode == FR_IMMEDIATE_COMMIT_MODE)
        {
            temp_value_2 |= FrMBCCSR_MCM;           /* Immediate commit mode */
        }
        /* Store transmit MB type into internal MB information structure */
        Fr_MB_information_internal[Fr_buffers_config_ptr[Mbindex].buffer_index_init].transmission_mode =  FR_DOUBLE_TRANSMIT_BUFFER; /* polyspace RTE:OBAI */
        Fr_MB_information_internal[Fr_buffers_config_ptr[Mbindex].buffer_index_init + 1U].transmission_mode =  FR_DOUBLE_TRANSMIT_BUFFER; /* polyspace RTE:OBAI */
    }
    else
    {
        /* Store transmit MB type into internal MB information structure */
        Fr_MB_information_internal[Fr_buffers_config_ptr[Mbindex].buffer_index_init].transmission_mode =  FR_SINGLE_TRANSMIT_BUFFER; /* polyspace RTE:OBAI */
    }
    /* Copy configuration into temp_value_3 variable  */ 
    temp_value_3 = temp_value_2;    /* Interrupt flag can be set for the commit or transmit side of the double buf.MB */
    
    if(Fr_transmit_buffer_config_ptr->tx_MB_interrupt_enable  != 0U)   /* Interrupt generation configured? */
    {
        if((Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER) && Fr_transmit_buffer_config_ptr->tx_MB_interrupt_transmit_side_enable) /* PRQA S 4115 */
        {
            /* Interrupt flag is set for the transmit side of the double buf.MB, not for commit side */
            temp_value_2 |= FrMBCCSR_MBIE;           /* Interrupt generation enabled */
        }
        else
        {
            /* Interrupt flag is not set for the transmit side of the double buf.MB */
            temp_value_3 |= FrMBCCSR_MBIE;           /* Interrupt generation enabled */
        }
    }

    /* Store configuration into the MBCCSRn register */
    Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] = temp_value_3;
    /* Store configuration into transmit side of the double buffered MB */
    if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
    {
        /* Store configuration into the MBCCSR[2n+1] register */
        Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset + 4U] = temp_value_2; /* polyspace RTE:IDP */
    }
    
    /* Configure MBCCFRn register */
    temp_value_1 = 0x0000U;      /* Clear variable */
    if(Fr_transmit_buffer_config_ptr->transmit_channel_enable == FR_CHANNEL_A)
    {
        temp_value_1 = FrMBCCFR_CHA;    /* Channel assigment - ch. A */
    }
    else if(Fr_transmit_buffer_config_ptr->transmit_channel_enable == FR_CHANNEL_B)
    {
        temp_value_1 = FrMBCCFR_CHB;    /* Channel assigment - ch. B */
    }
    else if(Fr_transmit_buffer_config_ptr->transmit_channel_enable == FR_CHANNEL_AB)
    {
        temp_value_1 = (FrMBCCFR_CHA | FrMBCCFR_CHB);    /* Channel assigment - ch. A */
    }
    else
    {
        
    }
    /* Cycle counter filter settings */
    if(Fr_transmit_buffer_config_ptr->tx_cycle_counter_filter_enable  != 0U)    /* Should be the cycle counter filter enabled? */
    {
        temp_value_2 = 0x0000U;
        /* Cycle counter filter value */
        temp_value_2 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_transmit_buffer_config_ptr->tx_cycle_counter_filter_value & 0x003FU);
        temp_value_1 |= temp_value_2;
        /* Cycle counter filter mask */
        temp_value_2 =  ((VAR(uint16, AUTOMATIC))Fr_transmit_buffer_config_ptr->tx_cycle_counter_filter_mask & 0x3FU);
        temp_value_1 |= (VAR(uint16, AUTOMATIC))((temp_value_2 << 6U));
        temp_value_1 |= FrMBCCFR_CCFE;  /* Cycle counter filter enabled */
    }
    if(Fr_transmit_buffer_config_ptr->transmission_mode == FR_STATE_TRANSMISSION_MODE) /* Which transmission mode? */
    {
        temp_value_1 |= FrMBCCFR_MTM;   /* State transmission mode is enabled */
        /* Store information into internal structure */
        Fr_MB_information_internal[Fr_buffers_config_ptr[Mbindex].buffer_index_init].transmission_type = FR_STATE_TRANSMISSION_MODE; /* polyspace RTE:OBAI */
        if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
        {
            /* Store information also for transmit side of the double buffered MB */
            Fr_MB_information_internal[Fr_buffers_config_ptr[Mbindex].buffer_index_init + 1U].transmission_type =  FR_STATE_TRANSMISSION_MODE; /* polyspace RTE:OBAI */
        }                            
    }
    else
    {
        /* Store information into internal structure */
        Fr_MB_information_internal[Fr_buffers_config_ptr[Mbindex].buffer_index_init].transmission_type =  FR_EVENT_TRANSMISSION_MODE; /* polyspace RTE:OBAI */
    }
    Fr_CC_reg_ptr[FrMBCCFR0 + MbRegOffset] = temp_value_1; /* polyspace RTE:IDP */ /* Store configuration into MBCCFRn register */
    /* Store configuration into transmit side of the double buffered MB */
    if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
    {
        /* Store configuration into the MBCCFR[2n+1] register */
        Fr_CC_reg_ptr[FrMBCCFR0 + MbRegOffset + 4U] = temp_value_1; /* polyspace RTE:IDP */
    }

    
    /* Configure MBFIDRn register */
    Fr_CC_reg_ptr[FrMBFIDR0 + MbRegOffset] = Fr_transmit_buffer_config_ptr->transmit_frame_ID; /* polyspace RTE:IDP */
    /* Store configuration into transmit side of the double buffered MB */
    if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
    {
        /* Store configuration into the MBFIDR[2n+1] register */
        Fr_CC_reg_ptr[FrMBFIDR0 + MbRegOffset + 4U] = Fr_transmit_buffer_config_ptr->transmit_frame_ID; /* polyspace RTE:IDP */
    }

    
    /* Store transmit MB frame ID into internal MB information structure */
    Fr_MB_information_internal[Fr_buffers_config_ptr[Mbindex].buffer_index_init].slot_number = Fr_transmit_buffer_config_ptr->transmit_frame_ID; /* polyspace RTE:OBAI */

    /* Initialize the second part of double buffer if double buffered TX MB configured */
    if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
    {
        Fr_MB_information_internal[Fr_buffers_config_ptr[Mbindex].buffer_index_init + 1U].slot_number = Fr_transmit_buffer_config_ptr->transmit_frame_ID; /* polyspace RTE:OBAI */
    }
    
    /* Calculate and configure data field offset  */
    /* According to a FlexRay Memory Layout descibed in FlexRay module documentation */
    
    /* Calculate the message buffer header  */

    header_MB_ptr = ((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA))(pCtrlCfg->Fr_HW_config_temp_ptr->CC_FlexRay_memory_base_address) + (Fr_buffers_config_ptr[Mbindex].buffer_index_init * 4U));

    /* Configure Frame Header registers */
    temp_value_1 = 0x0000U;          /* Clear */
    temp_value_1 = (Fr_transmit_buffer_config_ptr->transmit_frame_ID & 0x07FFU);    /* Frame ID */
    if(Fr_transmit_buffer_config_ptr->payload_preamble == TRUE)         /* Payload preamble indicator configured? */
    {
        temp_value_1 = FrF_HEADER_PPI;                                  /* Configure Payload preamble indicator */
    }
    header_MB_ptr[0U] = temp_value_1; /* polyspace RTE:IDP */        /* Store the first word of Frame Header Section */
    /* Store configuration into transmit side of the double buffered MB */
    if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
    {
        /* Store configuration into the first word of Frame Header Section */
        header_MB_ptr[0+5] = temp_value_1; /* polyspace RTE:IDP */        /* Store the first word of Frame Header Section */
    }

    temp_value_2 = 0x0000U;          /* Clear */
    temp_value_2 = ((VAR(uint16, AUTOMATIC))Fr_transmit_buffer_config_ptr->payload_length & 0x007FU);    /* Payload length */
    header_MB_ptr[1U] = temp_value_2; /* polyspace RTE:IDP */        /* Store the second word of Frame Header Section */
    /* Store configuration into transmit side of the double buffered MB */
    if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
    {
        /* Store configuration into the second word of Frame Header Section */
        header_MB_ptr[1U+5U] = temp_value_2; /* polyspace RTE:IDP */        /* Store the second word of Frame Header Section */
    }


    temp_value_1 = 0x0000U;          /* Clear */
    temp_value_1 = (VAR(uint16, AUTOMATIC))(Fr_transmit_buffer_config_ptr->header_CRC & 0x07FFU);       /* Header CRC */
    header_MB_ptr[2U] = temp_value_1; /* polyspace RTE:IDP */        /* Store the third word of Frame Header Section */
    /* Store configuration into transmit side of the double buffered MB */
    if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
    {
        /* Store configuration into the third word of Frame Header Section */
        header_MB_ptr[2U+5U] = temp_value_1; /* polyspace RTE:IDP */        /* Store the third word of Frame Header Section */
    }

    
    /* Check if the message buffer is in segment 1 or segment 2 */
    if(Fr_buffers_config_ptr[Mbindex].buffer_index_init < ((VAR(uint16, AUTOMATIC))pCtrlCfg->Fr_HW_config_temp_ptr->last_MB_seg_1 + 1U))
    {   /* Payload data of MB are in segment 1 */
        /* Calculate valid Data Field Offset */
            /* (total_MB_number * 8) + (buffer_index_init * MB_segment_1_data_size * 2) */
            temp_value_2 =(VAR(uint16, AUTOMATIC))((pCtrlCfg->Fr_HW_config_temp_ptr->total_MB_number * 8U) + \
                        (Fr_buffers_config_ptr[Mbindex].buffer_index_init * \
                        pCtrlCfg->Fr_HW_config_temp_ptr->MB_segment_1_data_size * 2U));

        /* Calculate the Data Field Offset for the transmit side of the double MB */
        if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
        {
            /* Calculate valid Data Field Offset */
            /* (total_MB_number * 10) + (buffer_index_init * MB_segment_1_data_size * 2) + 1 * MB_segment_1_data_size * 2 */
            temp_value_1 = (VAR(uint16, AUTOMATIC))(temp_value_2 + ((VAR(uint16, AUTOMATIC))pCtrlCfg->Fr_HW_config_temp_ptr->MB_segment_1_data_size * 2U));
        }
    }
    else /* Payload data of MB are in segment 2 */
    {
            /* Calculate valid Data Field Offset */
            /*(total_MB_number * 8) + ((last_MB_seg_1 + 1) * MB_segment_1_data_size * 2) + ((buffer_index_init - (last_MB_seg_1 + 1)) * MB_segment_2_data_size * 2)*/
            temp_value_2 = (VAR(uint16, AUTOMATIC))((pCtrlCfg->Fr_HW_config_temp_ptr->total_MB_number * 8U) + \
                            (((VAR(uint16, AUTOMATIC))pCtrlCfg->Fr_HW_config_temp_ptr->last_MB_seg_1 + 1U) * pCtrlCfg->Fr_HW_config_temp_ptr->MB_segment_1_data_size * 2U) + \
                            ((Fr_buffers_config_ptr[Mbindex].buffer_index_init - \
                            ((VAR(uint16, AUTOMATIC))pCtrlCfg->Fr_HW_config_temp_ptr->last_MB_seg_1 + 1U)) * pCtrlCfg->Fr_HW_config_temp_ptr->MB_segment_2_data_size * 2U));

        /* Calculate the Data Field Offset for the transmit side of the double MBf-> */
        if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
        {
            /* Calculate valid Data Field Offset */
            /*(total_MB_number * 10) + ((last_MB_seg_1 + 1) * MB_segment_1_data_size * 2) + ((buffer_index_init - (last_MB_seg_1 + 1)) * MB_segment_2_data_size * 2) + 1 * MB_segment_2_data_size * 2 */
            temp_value_1 = (VAR(uint16, AUTOMATIC))(temp_value_2 + ((VAR(uint16, AUTOMATIC))pCtrlCfg->Fr_HW_config_temp_ptr->MB_segment_2_data_size * 2U));
        }
    }
    
    Fr_CC_reg_ptr[FrMBDOR0 + Fr_buffers_config_ptr[Mbindex].buffer_index_init] = temp_value_2; /* polyspace RTE:IDP */

    /* Store configuration into transmit side of the double buffered MB */
    if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
    {
        /* Store the Data Field Offset to Frame Header Section */
        header_MB_ptr[3U+5U] = temp_value_1; /* polyspace RTE:IDP */        /* Store Data Field Offset to Frame header register */
    }


    /* Message Buffer Index Registers initialization */
    temp_value_1 = Fr_buffers_config_ptr[Mbindex].buffer_index_init;
    Fr_CC_reg_ptr[FrMBIDXR0 + MbRegOffset] = temp_value_1;
    /* Store configuration into transmit side of the double buffered MB */

    /* Store the highest number of message buffer index into variable for optimization verification */
    if(highest_txrx_mb_number < temp_value_1)
    {
        highest_txrx_mb_number = (VAR(uint8, AUTOMATIC))temp_value_1;      /* Update variable with the highest index number */
    }

    if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
    {
        /* Store configuration into the MBIDXR[2n+1] register */
        Fr_CC_reg_ptr[FrMBIDXR0 + MbRegOffset + 4U] = (VAR(uint16, AUTOMATIC))(temp_value_1 + 1U); /* polyspace RTE:IDP */
        
        /* Store the highest number of message buffer index into variable for optimization verification */
        if(highest_txrx_mb_number < (temp_value_1 + 1U))
        {
            highest_txrx_mb_number = (VAR(uint8, AUTOMATIC))(temp_value_1 + 1U);      /* Update variable with the highest index number */
        }
    }
    
    /* Store MB type into internal MB information structure */
    /* Not necessary for the current version of the UNIFIED Driver */

    /* Enable message buffer */
    temp_value_1 = Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] | FrMBCCSR_EDT; /* polyspace RTE:NIV */
    
    /* Initialize the second part of double buffer if double buffered TX MB configured */
    if(Fr_transmit_buffer_config_ptr->transmit_MB_buffering == FR_DOUBLE_TRANSMIT_BUFFER)
    {
        /* Enable the MB - only in the transmit side of the double buffered - the MBCCSR[2n+1] register */
        Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset + 4U] = temp_value_1;
    }
    else
    {
        /* Enable the MB in the MBCCSRn register */
        Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] = temp_value_1;
    }
    if (FrMBCCSR_EDS == (Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] & FrMBCCSR_EDS)) /* polyspace RTE:NIV */
    {
        retVal =  E_OK;
    }

    return retVal;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/***************************************************************************************************
* @function_name    Fr_Driver_PrepareRxBuffer
*
* @brief            Fr function for the Fr_Flexray_PrepareLPdu function.
* @description      Prepare transmission buffer.
* @param[in]        pCtrlCfg - Index of FlexRay CC
* @param[in]        LPduIdx - Index of LPdu to be prepared.
* @param[in]        TempMBNum - Temporary variable for the MB index.
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
static Std_ReturnType Fr_Driver_PrepareRxBuffer
(
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg,
    VAR(uint16, AUTOMATIC) Mbindex,
    VAR(uint16, AUTOMATIC) TempMBNum
)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_NOT_OK;
    VAR(uint16, AUTOMATIC) MbRegOffset = 0U;
    volatile VAR(uint8, AUTOMATIC) highest_txrx_mb_number = 0U;  /* The highest number of configured transmit or receive MB index -for verification */
    volatile VAR(uint16, AUTOMATIC) temp_value_1;               /* Temporary variable used for bit operation */
    volatile VAR(uint16, AUTOMATIC) temp_value_2;               /* Temporary variable used for bit operation */
    static P2CONST(Fr_buffer_info_type, AUTOMATIC, FR_APPL_CONST) Fr_buffers_config_ptr;
    P2CONST(Fr_receive_buffer_config_type, AUTOMATIC, FR_APPL_CONST) Fr_receive_buffer_config_ptr; 

    /* Temporary offset address of MB configuration registers */
    MbRegOffset = (VAR(uint16, AUTOMATIC))(TempMBNum * 4U);
    /* Get the index from MBIDXn */
    /* Store the reference to transmit buffer configuration */
    Fr_buffers_config_ptr = pCtrlCfg->Fr_buffers_config_temp_ptr;
    Fr_receive_buffer_config_ptr = ((Fr_receive_buffer_config_type*)(pCtrlCfg->Fr_buffers_config_temp_ptr[Mbindex].buffer_config_ptr));

    
    /* Disable appropriate MB */
    if((Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] & FrMBCCSR_EDS) != 0U) /* polyspace RTE:NIV,IDP */
    {
        temp_value_1 = FrMBCCSR_EDT;
        Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] = temp_value_1;
    }
    
    /* Configure MBCCSRn register */
    temp_value_2 = 0x0000U;      /* Clear variable */
    if(Fr_receive_buffer_config_ptr->rx_MB_interrupt_enable != 0U)
    {
        temp_value_2 = FrMBCCSR_MBIE;            /* Interrupt generation enabled */
    }
    /* Configure MB as Receive MB and enable interrupt if required */
    Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] = temp_value_2;
    
    /* Configure MBCCFRn register */
    temp_value_1 = 0x0000U;      /* Clear variable */
    if(Fr_receive_buffer_config_ptr->receive_channel_enable == FR_CHANNEL_A)
    {
        temp_value_1 = FrMBCCFR_CHA;    /* Channel assigment - ch. A */
    }
    else if(Fr_receive_buffer_config_ptr->receive_channel_enable == FR_CHANNEL_B)
    {
        temp_value_1 = FrMBCCFR_CHB;    /* Channel assigment - ch. B */
    }
    else if(Fr_receive_buffer_config_ptr->receive_channel_enable == FR_CHANNEL_AB)
    {
        temp_value_1 = (FrMBCCFR_CHA | FrMBCCFR_CHB);    /* Channel assigment - ch. A */
    }
    else
    {

    }
    /* Cycle counter filter settings */
    if(Fr_receive_buffer_config_ptr->rx_cycle_counter_filter_enable  != 0U)    /* Should be the cycle counter filter enabled? */
    {
        temp_value_2 = 0x0000U;
        /* Cycle counter filter value */
        temp_value_2= (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))Fr_receive_buffer_config_ptr->rx_cycle_counter_filter_value & 0x3FU);
        temp_value_1 |= temp_value_2;
        /* Cycle counter filter mask */
        temp_value_2 =  ((VAR(uint16, AUTOMATIC))Fr_receive_buffer_config_ptr->rx_cycle_counter_filter_mask & 0x3FU);
        temp_value_1 |= (VAR(uint16, AUTOMATIC))(temp_value_2 << 6U);
        temp_value_1 |= FrMBCCFR_CCFE;  /* Cycle counter filter enabled */
    }
    Fr_CC_reg_ptr[FrMBCCFR0 + MbRegOffset] = temp_value_1; /* polyspace RTE:IDP */ /* Store configuration into MBCCFRn register */
    
    /* Configure MBFIDRn register */
    Fr_CC_reg_ptr[FrMBFIDR0 + MbRegOffset] = Fr_receive_buffer_config_ptr->receive_frame_ID; /* polyspace RTE:IDP */
    
    /* Store receive MB frame ID into internal MB information structure */
    Fr_MB_information_internal[Fr_buffers_config_ptr[Mbindex].buffer_index_init].slot_number = Fr_receive_buffer_config_ptr->receive_frame_ID; /* polyspace RTE:OBAI */

    
    /* Calculate and configure data field offset  */
    /* According to a FlexRay Memory Layout descibed in FlexRay module documentation */
    
    /* Calculate the message buffer header  */
    /* header_MB_ptr = ((volatile uint16 *)(pCtrlCfg->Fr_HW_config_temp_ptr->CC_FlexRay_memory_base_address) + (Fr_buffers_config_ptr[Mbindex].buffer_index_init * 4U)); */
    /* Check if the message buffer is in segment 1 or segment 2 */
    if(Fr_buffers_config_ptr[Mbindex].buffer_index_init < ((VAR(uint16, AUTOMATIC))pCtrlCfg->Fr_HW_config_temp_ptr->last_MB_seg_1 + 1U))
    {   /* Payload data of MB are in segment 1 */
        /* Calculate valid Data Field Offset */
        /* (total_MB_number * 10) + (buffer_index_init * MB_segment_1_data_size * 2) */
        temp_value_2 = (VAR(uint16, AUTOMATIC))((pCtrlCfg->Fr_HW_config_temp_ptr->total_MB_number * 8U) + \
                        (Fr_buffers_config_ptr[Mbindex].buffer_index_init * \
                        pCtrlCfg->Fr_HW_config_temp_ptr->MB_segment_1_data_size * 2U));
    }
    else /* Payload data of MB are in segment 2 */
    {
        /* Calculate valid Data Field Offset */
        /*(total_MB_number * 10) + ((last_MB_seg_1 + 1) * MB_segment_1_data_size * 2) + ((buffer_index_init - (last_MB_seg_1 + 1)) * MB_segment_2_data_size * 2)*/
        temp_value_2 = (VAR(uint16, AUTOMATIC))((pCtrlCfg->Fr_HW_config_temp_ptr->total_MB_number * 8U) + \
                        (((VAR(uint16, AUTOMATIC))pCtrlCfg->Fr_HW_config_temp_ptr->last_MB_seg_1 + 1U) * pCtrlCfg->Fr_HW_config_temp_ptr->MB_segment_1_data_size * 2U) + \
                        ((Fr_buffers_config_ptr[Mbindex].buffer_index_init - \
                        ((VAR(uint16, AUTOMATIC))pCtrlCfg->Fr_HW_config_temp_ptr->last_MB_seg_1 + 1U)) * pCtrlCfg->Fr_HW_config_temp_ptr->MB_segment_2_data_size * 2U));
    }
    temp_value_1 = Fr_buffers_config_ptr[Mbindex].buffer_index_init;
    Fr_CC_reg_ptr[FrMBDOR0 + temp_value_1] = temp_value_2; /* polyspace RTE:IDP */

    /* Message Buffer Index Registers initialization */
    temp_value_1 = Fr_buffers_config_ptr[Mbindex].buffer_index_init;
    Fr_CC_reg_ptr[FrMBIDXR0 + MbRegOffset] = temp_value_1;
    
    /* Store the highest number of message buffer index into variable for optimization verification */
    if(highest_txrx_mb_number < temp_value_1)
    {
        highest_txrx_mb_number = (VAR(uint8, AUTOMATIC))temp_value_1;      /* Update variable with the highest index number */
    }
    
    /* Store MB type into internal MB information structure */
    /* Not necessary for the current version of the UNIFIED Driver */
    
    /* Enable message buffer */
    temp_value_1 = Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] | FrMBCCSR_EDT; /* polyspace RTE:NIV */
    Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] = temp_value_1;

    if (FrMBCCSR_EDS == (Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] & FrMBCCSR_EDS))
    {
        /* Clear Buffer Interrupt Flag which is set after MB enabling */
        /* Select only necessary bits */
        SchM_Enter_Fr_EXCLUSIVE_AREA_07();
        temp_value_1 = Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] & 0x7900U;
        temp_value_1 |= FrMBCCSR_MBIF;      /* Set MBIF flag - clear Rx MB interrupt flag */
        /* Fr_CtrlIdx: FR_MBCCSR */
        /* Clear Transmit Buffer Interrupt Flag */
        Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] = temp_value_1;;
        SchM_Exit_Fr_EXCLUSIVE_AREA_07();
        retVal =  E_OK;
    }
    return retVal;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif /* FR_RECONFIG_LPDU_SUPPORT == STD_ON */
#endif
#if (FR_RECONFIG_LPDU_SUPPORT == STD_ON)

/***************************************************************************************************
* @function_name    Fr_Driver_ReconfigLPdu
*
* @brief            FrIP function for the Fr_ReconfigLPdu API
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        u16LPduIdx - Index of LPdu to be reconfigured
* @param[in]        u16FrameId - Frame ID for reconfiguration
* @param[in]        u8CycleRepetition - Repetition value for cycle filter mechanism
* @param[in]        cycleOffste - Offste value for cycle filter mechanism
* @param[in]        u8PayloadLength - payload for data to be reconfigured
* @param[in]        u16HeaderCRC - hedaer CRC value
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_Driver_ReconfigLPdu
(
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg,
    VAR(uint16, AUTOMATIC) Mbindex,
    VAR(uint16, AUTOMATIC) FrameId,
    VAR(Fr_ChannelType, AUTOMATIC) chnlIdx,
    VAR(uint8, AUTOMATIC) CycleRepetition,
    VAR(uint8, AUTOMATIC) CycleOffset,
    VAR(uint8, AUTOMATIC) PayloadLength,
    VAR(uint16, AUTOMATIC) HeaderCRC
)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = E_NOT_OK;
    VAR(uint16, AUTOMATIC) MbRegOffset;
    VAR(uint16, AUTOMATIC) temp_value_1;
    VAR(uint16, AUTOMATIC) temp_value_2;
    P2VAR(volatile VAR(uint16, AUTOMATIC), AUTOMATIC, FR_APPL_DATA) header_MB_ptr;
    
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    /* Offset from FR base address to the MB registers */
    MbRegOffset = (VAR(uint16, AUTOMATIC))(Mbindex * 4U);
        
    /*disable the MB*/
    temp_value_1 = (Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] | FrMBCCSR_EDT); /* polyspace RTE:NIV,IDP */
    if (FrMBCCSR_EDS == (Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] & FrMBCCSR_EDS)) /* polyspace RTE:NIV */
    {
        Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] = temp_value_1;
    }
    /* Check if buffer has been successfully disabled */
    if(FrMBCCSR_EDS != (Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] & FrMBCCSR_EDS)) /* polyspace RTE:NIV */
    { /* Yes */ 

        /* Store configuration into transmit side of the double buffered MB */
        
        /* Configure MBCCFRn register */
        temp_value_1 = 0x0000U;      /* Clear variable */
        if(chnlIdx == FR_CHANNEL_A)
        {
            temp_value_1 = FrMBCCFR_CHA;    /* Channel assigment - ch. A */
        }
        else if(chnlIdx == FR_CHANNEL_B)
        {
            temp_value_1 = FrMBCCFR_CHB;    /* Channel assigment - ch. B */
        }
        else if(chnlIdx == FR_CHANNEL_AB)
        {
            temp_value_1 = (FrMBCCFR_CHA | FrMBCCFR_CHB);    /* Channel assigment - ch. A */
        }
        else
        {

        }
        /* Cycle counter filter settings */
        SchM_Enter_Fr_EXCLUSIVE_AREA_08();
        temp_value_2 = 0x0000U;
        /* Cycle counter filter value */
        temp_value_1 = (VAR(uint16, AUTOMATIC))(((VAR(uint16, AUTOMATIC))CycleOffset & 0x3FU) | temp_value_1);
        /* Cycle counter filter mask */
        temp_value_2 =  (VAR(uint16, AUTOMATIC))(((VAR(uint16, AUTOMATIC))CycleRepetition & 0x3FU) - 1U);
        temp_value_1 = (VAR(uint16, AUTOMATIC))((temp_value_2 << 6U) | temp_value_1);
        temp_value_1 |= FrMBCCFR_CCFE;  /* Cycle counter filter enabled */
    
        Fr_CC_reg_ptr[FrMBCCFR0 + MbRegOffset] = temp_value_1; /* polyspace RTE:IDP */ /* Store configuration into MBCCFRn register */
        SchM_Exit_Fr_EXCLUSIVE_AREA_08();
        Fr_CC_reg_ptr[FrMBFIDR0 + MbRegOffset] = FrameId; /* polyspace RTE:IDP */
        /* Store configuration into transmit side of the double buffered MB */

        /* Store transmit MB frame ID into internal MB information structure */
        Fr_MB_information_internal[Mbindex].slot_number = (VAR(uint8, AUTOMATIC))(FrameId & 0xffU);


        /* Calculate the message buffer header  */

        header_MB_ptr = ((volatile P2VAR(uint16, AUTOMATIC, FR_APPL_DATA))(pCtrlCfg->Fr_HW_config_temp_ptr->CC_FlexRay_memory_base_address) + (Mbindex * 4U));

        /* Configure Frame Header registers */
        temp_value_1 = 0x0000U;          /* Clear */
        temp_value_1 = (VAR(uint16, AUTOMATIC))(FrameId & 0x07FFU);    /* Frame ID */
    
        header_MB_ptr[0U] = temp_value_1; /* polyspace RTE:IDP */        /* Store the first word of Frame Header Section */
        /* Store configuration into transmit side of the double buffered MB */
        /* Clear */
        temp_value_2 = 0x0000U;          
        temp_value_1 = (VAR(uint16, AUTOMATIC))(((((VAR(uint16, AUTOMATIC))PayloadLength + 1U) & 0xFEU) >> 1) & (0x7FU));
        temp_value_2 |= temp_value_1;
        /* Store the second word of Frame Header Section */
        header_MB_ptr[1U] = temp_value_2; /* polyspace RTE:IDP */
        /* Store configuration into transmit side of the double buffered MB */
        /* Clear */
        temp_value_1 = 0x0000U;         
        /* Header CRC */
        temp_value_1 = (VAR(uint16, AUTOMATIC))((HeaderCRC & 0x07FFU) | temp_value_1);       
         /* Store the third word of Frame Header Section */
        header_MB_ptr[2U] = temp_value_1; /* polyspace RTE:IDP */

        /* Message Buffer Index Registers initialization */
        Fr_CC_reg_ptr[FrMBIDXR0 + MbRegOffset] = Mbindex; /* polyspace RTE:IDP */

        /* Enable message buffer */
        temp_value_1 = Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] | FrMBCCSR_EDT; /* polyspace RTE:NIV */
        /* Enable the MB in the MBCCSRn register */
        Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] = temp_value_1;
        if (FrMBCCSR_EDS == (Fr_CC_reg_ptr[FrMBCCSR0 + MbRegOffset] & FrMBCCSR_EDS))
        {
            retVal = E_OK;
        }
    }

    return retVal;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif /* FR_RECONFIG_LPDU_SUPPORT */

#endif /* RESOURCE_SUPPORT_FLEXRAY */

#ifdef __cplusplus
}
#endif

/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : DIO
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*****************************************************************************/
/**
*   @file    Dio.c
*   @version 3.0.0
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Dio MCAL driver.
*   @addtogroup Dio
*   @{
*/
/*PRQA S 0380,1006,3432 EOF*/
/*PRQA S 0488,0491,1891,2844,4397,1259,2991,2985,2995,1258 EOF*/ /*QAC_CWE*/
#ifdef __cplusplus
extern "C"{
#endif

/* ==============================================INCLUDE FILES======================================= */
#include "Dio.h"
#if (STD_ON == DIO_ERROR_CHECK)
    #include "Det.h"
#endif

/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define DIO_C_VENDOR_ID                     176
#define DIO_C_MAJOR_VERSION                 4
#define DIO_C_MINOR_VERSION                 4
#define DIO_C_patch_VERSION                 0
#define DIO_C_SW_MAJOR_VERSION              3
#define DIO_C_SW_MINOR_VERSION              0
#define DIO_C_SW_PATCH_VERSION              0

/* ============================================FILE VERSION CHECKS=================================== */
#if (DIO_C_VENDOR_ID != DIO_H_VENDOR_ID)
    #error " NON-MATCHED DATA : DIO_C_VENDOR_ID "
#endif
#if (DIO_C_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_C_MAJOR_VERSION "
#endif
#if (DIO_C_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_C_MINOR_VERSION "
#endif
#if (DIO_C_patch_VERSION != DIO_AR_RELEASE_REVISION_VERSION)
    #error " NON-MATCHED DATA : DIO_C_patch_VERSION "
#endif
#if (DIO_C_SW_MAJOR_VERSION != DIO_H_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_C_SW_MAJOR_VERSION "
#endif
#if (DIO_C_SW_MINOR_VERSION != DIO_H_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_C_SW_MINOR_VERSION "
#endif
#if (DIO_C_SW_PATCH_VERSION != DIO_H_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : DIO_C_SW_PATCH_VERSION "
#endif
/* =================================================Constants======================================== */

/* ============================================DEFINES AND MACROS==================================== */

/* ===================================================Enums========================================== */

/* =======================================STRUCTURES AND OTHER TYPEDEFS============================== */

/* ===========================================VARIABLE DECLARATIONS================================== */

/* ============================================FUNCTION PROTOTYPES=================================== */


#if (STD_ON == DIO_MULTICORE_SUPPORT)
    #define Dio_GetCoreID()            GetCoreID()
#else
    #define Dio_GetCoreID()            ((uint8)ncoreid)
#endif

#if (STD_ON == DIO_ERROR_CHECK)

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
static FUNC(void, DIO_CODE) Dio_120ReportError \
( \
    VAR(uint8, AUTOMATIC) Dio_120ApiId, \
    VAR(uint8, AUTOMATIC) Dio_120ErrorId \
)
{
    (void)Det_ReportError((uint16)DIO_H_MODULE_ID, DIO_INSTANCE_ID, \
                          (uint8)Dio_120ApiId, \
                          (uint8)Dio_120ErrorId \
                         );
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
#if (DIO_ERROR_CHECK == STD_ON)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ReadChannelVerify \
( \
    VAR(Dio_ChannelType, AUTOMATIC) u16Dio_ChannelId, \
    VAR(uint8, AUTOMATIC) u8ApiNumId \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Dio_LevelType, DIO_CODE)Dio_ChannelLevelVerify(VAR(Dio_LevelType, AUTOMATIC) Level);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Dio_LevelType, DIO_CODE)Dio_WriteChannelVerify \
( \
    VAR(Dio_ChannelType, AUTOMATIC) u16Dio_ChannelId, \
    VAR(uint8, AUTOMATIC) FuncId \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ReadPortVerify \
( \
   VAR(Dio_PortType, AUTOMATIC) PortId, \
   VAR(uint8, AUTOMATIC) FuncId \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_WritePortVerify \
( \
   VAR(Dio_PortType, AUTOMATIC) PortId, \
   VAR(uint8, AUTOMATIC) FuncId \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ReadChannelGroupVerify \
( \
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) Dio_ChannelGroupIdPtr \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_WriteChannelGroupVerify \
( \
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) Dio_ChannelGroupIdPtr \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#if(DIO_VERSION_INFO_API == STD_ON)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_GetVersionInfoVerify \
( \
		P2CONST(Std_VersionInfoType, AUTOMATIC, DIO_APPL_DATA) VersionInfo \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType,AUTOMATIC)Dio_FlipChannelVerify \
( \
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId, \
    VAR(uint8, AUTOMATIC) FuncId \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#if (STD_ON == DIO_MASKEDWRITEPORT_API)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_MaskedWritePortVerify \
( \
    VAR(Dio_PortType, AUTOMATIC) PortId, \
	VAR(Dio_PortLevelType, AUTOMATIC) Mask, \
    VAR(uint8, AUTOMATIC) FuncId \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
#endif
/*****************************************************************************
** Service Name       : Dio_ReadChannelVerify                                              
** 
** 
**  Description      : This function checks whether the parameters 
**  of Dio_ReadChannel are normal.                        
**                                                                            
**  Parameters (in)  : ChannelId: Channel ID number
**                     serviceId: Id for DET Function                                
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : u8dio_176VerifyRetval : Boolean variables 
**  used by functions                                                    
**                                                                            
******************************************************************************/
#if (DIO_ERROR_CHECK == STD_ON)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ReadChannelVerify \
( \
    VAR(Dio_ChannelType, AUTOMATIC) u16Dio_ChannelId, \
    VAR(uint8, AUTOMATIC) u8ApiNumId \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8dio_JudgeState = (Std_ReturnType)E_NOT_OK;
    VAR(uint8,          AUTOMATIC) CoreId = (uint8)Dio_GetCoreID();
    VAR(uint32,          AUTOMATIC) channle_flag = 0U;
    if (((u16Dio_ChannelId < DIO_NUM_CHANNELS_U16) \
    		&& (((DIO_BIT1_LEFTMOST_MASK_U16 >> ((u16Dio_ChannelId) & DIO_PIN_MASK_U16)) & Dio_ReadAvailablePins[u16Dio_ChannelId>>DIO_PORTID_SHIFT_U8])!=0U)))
    {
        channle_flag = channel_index[u16Dio_ChannelId];
        if((CoreId < DIO_CORE_NUM) && (Dio_ConfigPC.Dio_u32ChannelToPartitionMap!=NULL_PTR) && (channle_flag <DIO_NUM_CHANNELS_U16))
        {
        	if (1U == ((Dio_ConfigPC.Dio_u32ChannelToPartitionMap[channle_flag].coreid & (1U << CoreId)) >> CoreId))
        	{
        		u8dio_JudgeState = (Std_ReturnType)E_OK;
        	}
        	else
        	{
        		(void)Dio_120ReportError( u8ApiNumId, DIO_E_PARAM_CONFIG);
        	}
        }
        else{
           (void)Dio_120ReportError( u8ApiNumId, DIO_E_PARAM_CONFIG);
        }
    }
    else
    {
        (void)Dio_120ReportError(u8ApiNumId, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }

    return u8dio_JudgeState;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
/*****************************************************************************
**  Description      : Returns the value of the specified Dio channel                        
**                                                                            
**  Service ID       : 0x00                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                          
**                                                                            
**  Parameters (in)  : ChannelId: ID of Dio channel                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Dio_LevelType                                                   
**                                                                            
******************************************************************************/
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC(Dio_LevelType, DIO_CODE) Dio_ReadChannel \
( \
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId \
)
{
    VAR(Dio_LevelType, AUTOMATIC) u8ChannelIdLecel = (Dio_LevelType)STD_LOW;

#if (STD_ON == DIO_ERROR_CHECK)
    VAR(Std_ReturnType, AUTOMATIC) u8ChannelIdVerify = Dio_ReadChannelVerify(ChannelId, DIO_READCHANNEL_ID);
    if ((Std_ReturnType)E_OK == u8ChannelIdVerify)
    {
#endif
        u8ChannelIdLecel = Dio_Auto_Wrap_ReadChannel(ChannelId);
#if (STD_ON == DIO_ERROR_CHECK)
    }
#endif

    return u8ChannelIdLecel;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
/*****************************************************************************
** Service Name       : Dio_ChannelLevelVerify                                              
** 
** 
**  Description      : This function checks whether Level is normal.                        
**                                                                            
**  Parameters (in)  : level: Level to be set                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : u8dio_176VerifyRetval : Boolean variables 
**  used by functions                                                    
**                                                                            
******************************************************************************/
#if (DIO_ERROR_CHECK == STD_ON)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Dio_LevelType, DIO_CODE)Dio_ChannelLevelVerify(VAR(Dio_LevelType, AUTOMATIC) Level)
{
    VAR(Std_ReturnType, AUTOMATIC) u8dio_levelRetval = (Std_ReturnType)E_NOT_OK;
    if (((Dio_LevelType)STD_HIGH == Level) || ((Dio_LevelType)STD_LOW == Level))
    {
    	u8dio_levelRetval = (Std_ReturnType)E_OK;
    }
    else
    {
        (void)Dio_120ReportError(DIO_WRITECHANNEL_ID, DIO_E_PARAM_LEVEL);
    }

    return u8dio_levelRetval;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
/*****************************************************************************
** Service Name       : Dio_WriteChannelVerify                                              
** 
** 
**  Description      : This function checks whether the parameters 
**  of Dio_WriteChannel are normal.                        
**                                                                            
**  Parameters (in)  : ChannelId: Channel ID number
**                     serviceId: Id for DET Function                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : u8dio_176VerifyRetval : Boolean variables 
**  used by functions                                                    
**                                                                            
******************************************************************************/
#if (DIO_ERROR_CHECK == STD_ON)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Dio_LevelType, DIO_CODE)Dio_WriteChannelVerify \
( \
    VAR(Dio_ChannelType, AUTOMATIC) u16Dio_ChannelId, \
    VAR(uint8, AUTOMATIC) FuncId \
)
{
	VAR(Std_ReturnType, AUTOMATIC) u8dio_ChannelRetval = (Std_ReturnType)E_NOT_OK;
    VAR(uint8,          AUTOMATIC) CoreId = (uint8)Dio_GetCoreID();
    VAR(uint32,          AUTOMATIC) channle_flag = 0U;

	if (((Dio_ChannelType)(u16Dio_ChannelId) < DIO_NUM_CHANNELS_U16)\
        && (((DIO_BIT1_LEFTMOST_MASK_U16 >> ((u16Dio_ChannelId) & DIO_PIN_MASK_U16)) & Dio_WriteAvailablePins[u16Dio_ChannelId>>DIO_PORTID_SHIFT_U8])!=0U))
	{
        channle_flag = channel_index[u16Dio_ChannelId];
        if((CoreId < DIO_CORE_NUM) && (Dio_ConfigPC.Dio_u32ChannelToPartitionMap!=NULL_PTR) && (channle_flag<DIO_NUM_CHANNELS_U16))
        {
        	if (1U == ((Dio_ConfigPC.Dio_u32ChannelToPartitionMap[channle_flag].coreid & (1U << CoreId)) >> CoreId))
        	{
        		u8dio_ChannelRetval = (Std_ReturnType)E_OK;
        	}
        	else
        	{
        		(void)Dio_120ReportError( FuncId, DIO_E_PARAM_CONFIG);
        		u8dio_ChannelRetval = (Std_ReturnType)E_NOT_OK;
        	}
        }
        else{
    		(void)Dio_120ReportError( FuncId, DIO_E_PARAM_CONFIG);
        }
	}
	else
	{
	    (void)Dio_120ReportError(FuncId, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}

	return u8dio_ChannelRetval;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
/*****************************************************************************
**  Description      : Service to set a level of a channel                        
**                                                                            
**  Service ID       : 0x01                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                          
**                                                                            
**  Parameters (in)  : ChannelId: ID of Dio channel
**                     Level: Value to be written                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                 
**                                                                            
******************************************************************************/
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC(void, DIO_CODE) Dio_WriteChannel \
( \
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId, \
	CONST(Dio_LevelType, AUTOMATIC) Level \
)
{
#if (STD_ON == DIO_ERROR_CHECK)
    VAR(Std_ReturnType, AUTOMATIC) u8dio_ChannelRetval \
        = Dio_WriteChannelVerify(ChannelId, DIO_WRITECHANNEL_ID);
    if ((Std_ReturnType) E_OK == u8dio_ChannelRetval)
    {
    	u8dio_ChannelRetval = Dio_ChannelLevelVerify(Level);

        if ((Std_ReturnType) E_OK == u8dio_ChannelRetval)
        {
#endif
            Dio_Auto_Wrap_WriteChanne(ChannelId, Level);
#if (STD_ON == DIO_ERROR_CHECK)
        }
    }
#endif
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
/*****************************************************************************
** Service Name       : Dio_ReadPortVerify                                              
** 
** 
**  Description      : This function checks whether the parameters 
**  of Dio_ReadPort are normal.                        
**                                                                            
**  Parameters (in)  : PortId: Port ID number
**                     serviceId: Id for DET Function                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : u8dio_176VerifyRetval : Boolean variables 
**  used by functions                                                    
**                                                                            
******************************************************************************/
#if (DIO_ERROR_CHECK == STD_ON)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ReadPortVerify \
( \
    VAR(Dio_PortType, AUTOMATIC) PortId, \
    VAR(uint8, AUTOMATIC) FuncId \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8dio_VerifyRetval = (Std_ReturnType)E_NOT_OK;
    VAR(uint8,          AUTOMATIC) CoreId = (uint8)Dio_GetCoreID();
    VAR(uint32,          AUTOMATIC) port_flag = 0U;

    if (((uint8)(PortId) < DIO_NUM_PORTS_U16)&&(Dio_ReadAvailablePins[(uint8)(PortId)] != DIO_ZERO_U16))
    {
        port_flag = port_index[PortId];
        if((CoreId < DIO_CORE_NUM) && (Dio_ConfigPC.Dio_u32PortToPartitionMap!=NULL_PTR) && (port_flag <DIO_NUM_PORTS_U16))
        {
        	if (1U == ((Dio_ConfigPC.Dio_u32PortToPartitionMap[port_flag].coreid & (1U << CoreId)) >> CoreId))
        	{
        		u8dio_VerifyRetval = ( Std_ReturnType)E_OK;
        	}
        	else
        	{
            	(void)Dio_120ReportError(FuncId, DIO_E_PARAM_CONFIG);
        	}
        }
        else{
            (void)Dio_120ReportError(FuncId, DIO_E_PARAM_CONFIG);
        }
        
    }
    else
    {
        (void)Dio_120ReportError(FuncId, DIO_E_PARAM_INVALID_PORT_ID);    
    }

    return u8dio_VerifyRetval;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
/*****************************************************************************
**  Description      : Returns the Level of all channels of that port                        
**                                                                            
**  Service ID       : 0x02                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                          
**                                                                            
**  Parameters (in)  : portlId: ID of Dio port                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Dio_LevelType                                                   
**                                                                            
******************************************************************************/
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadPort \
( \
    CONST(Dio_PortType, AUTOMATIC) PortlId \
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) u8PortIdLecel = (Dio_PortLevelType)STD_LOW;

#if (STD_ON == DIO_ERROR_CHECK)
    VAR(Std_ReturnType, AUTOMATIC) u8PortIdVerify = Dio_ReadPortVerify(PortlId, DIO_READPORT_ID);
    if ((Std_ReturnType)E_OK == u8PortIdVerify)
    {
#endif
        u8PortIdLecel = Dio_Auto_Wrap_ReadPort(PortlId);
#if (STD_ON == DIO_ERROR_CHECK)
    }
#endif

    return u8PortIdLecel;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

/*****************************************************************************
** Service Name       : Dio_WritePortVerify                                              
** 
** 
**  Description      : This function checks whether the parameters 
**  of Dio_WritePort are normal.                        
**                                                                            
**  Parameters (in)  : PortId: Port ID number
**                     serviceId: Id for DET Function                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : u8dio_176VerifyRetval : Boolean variables 
**  used by functions                                                    
**                                                                            
******************************************************************************/
#if (DIO_ERROR_CHECK == STD_ON)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_WritePortVerify \
( \
    VAR(Dio_PortType, AUTOMATIC) PortId, \
    VAR(uint8, AUTOMATIC) FuncId \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8dio_VerifyRetval = (Std_ReturnType)E_NOT_OK;    
    VAR(uint8,          AUTOMATIC) CoreId = (uint8)Dio_GetCoreID();
    VAR(uint32,          AUTOMATIC) port_flag = 0U;

    if (((uint8)(PortId) < DIO_NUM_PORTS_U16) \
                            && (Dio_WriteAvailablePins[(uint8)(PortId)] != DIO_ZERO_U16))
    {
        port_flag = port_index[PortId];
        if((CoreId < DIO_CORE_NUM) && (Dio_ConfigPC.Dio_u32PortToPartitionMap!=NULL_PTR) &&(port_flag<DIO_NUM_PORTS_U16))
        {
        	if (1U == ((Dio_ConfigPC.Dio_u32PortToPartitionMap[port_flag].coreid & (1U << CoreId)) >> CoreId))
        	{
        		u8dio_VerifyRetval = (Std_ReturnType)E_OK;
        	}
        	else
        	{
        		(void)Dio_120ReportError(FuncId, DIO_E_PARAM_CONFIG);
        	}
        }
        else{
           (void)Dio_120ReportError(FuncId, DIO_E_PARAM_CONFIG);
        }
        
    }
    else
    {
        (void)Dio_120ReportError(FuncId, DIO_E_PARAM_INVALID_PORT_ID);
   }

   return u8dio_VerifyRetval;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
/*****************************************************************************
**  Description      : Service to set a value of the port                         
**                                                                            
**  Service ID       : 0x03                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                          
**                                                                            
**  Parameters (in)  : PortId: ID of Dio port
**                      Level: Value to be written                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                 
**                                                                            
******************************************************************************/
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC(void, DIO_CODE) Dio_WritePort \
( \
    CONST(Dio_PortType, AUTOMATIC) PortId, \
    CONST(Dio_PortLevelType, AUTOMATIC) Level \
)
{
#if (STD_ON == DIO_ERROR_CHECK)
    if ((Std_ReturnType)E_OK == Dio_WritePortVerify(PortId, DIO_WRITEPORT_ID))
    {
#endif
    	Dio_Auto_Wrap_WritePort(PortId, Level);
#if (STD_ON == DIO_ERROR_CHECK)
    }
#endif
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

/*****************************************************************************
** Service Name       : Dio_ReadChannelGroupVerify                                              
** 
** 
**  Description      : This function checks whether the parameters 
**  of Dio_ReadChannelGroup are normal.                        
**                                                                            
**  Parameters (in)  : ConfigPtr: Pointer to configuration set                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : u8dio_176VerifyRetval : Boolean variables 
**  used by functions                                                    
**                                                                            
******************************************************************************/
#if (DIO_ERROR_CHECK == STD_ON)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ReadChannelGroupVerify \
( \
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) Dio_ChannelGroupIdPtr \
)
{
    VAR(Std_ReturnType,AUTOMATIC)u8dio_VerifyRetval = (Std_ReturnType)E_NOT_OK;

    if (NULL_PTR == Dio_ChannelGroupIdPtr)
    {/* polyspace RTE:UNR */
        (void)Dio_120ReportError((DIO_READCHANNELGROUP_ID),(DIO_E_PARAM_POINTER));
    }
    else if((((uint32)(Dio_ChannelGroupIdPtr)) >= ((uint32)Dio_ConfigPC.pChannelGroupList))  &&  \
    (((uint32)(Dio_ChannelGroupIdPtr)) < (uint32)(Dio_ConfigPC.pChannelGroupList + Dio_ConfigPC.u8NumChannelGroups)) &&  \
           ((uint8)Dio_ChannelGroupIdPtr->port < DIO_NUM_PORTS_U16) && \
           ((uint8)Dio_ChannelGroupIdPtr->offset <= DIO_OFFSET_MAX_VALID_U8) && \
           (Dio_ReadAvailablePins[(uint8)(Dio_ChannelGroupIdPtr->port)] !=DIO_ZERO_U16))
	{
    	u8dio_VerifyRetval = (Std_ReturnType)E_OK;
	}
    else
    {
        (void)Dio_120ReportError((DIO_READCHANNELGROUP_ID),(DIO_E_PARAM_INVALID_GROUP_ID));
    }

    return u8dio_VerifyRetval;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
/*****************************************************************************
**  Description      : This seevice reads a subset of the adjoining bits of 
**      a port                          
**                                                                            
**  Service ID       : 0x04                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                          
**                                                                            
**  Parameters (in)  : ChannelGroupIdPtr: Pointer to channelgroup                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Dio_PortLevelType                                                   
**                                                                            
******************************************************************************/
#include "Dio_Cfg.h"
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadChannelGroup \
( \
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr \
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_Level = (Dio_PortLevelType) STD_LOW;
#ifdef DIO_CHANNEL_GROUPS_AVAILABLE
    VAR(uint8,          AUTOMATIC) CoreId = (uint8)Dio_GetCoreID();
    VAR(uint8,          AUTOMATIC) GroupAlocated = 0;
    VAR(uint8,          AUTOMATIC) GroupIndex    = 0;
#endif
#if (DIO_ERROR_CHECK == STD_ON)
    if ((Std_ReturnType)E_OK == Dio_ReadChannelGroupVerify(ChannelGroupIdPtr))
    {
#endif
#ifdef DIO_CHANNEL_GROUPS_AVAILABLE
        for(GroupIndex = 0U; GroupIndex < Dio_ConfigPC.u8NumChannelGroups; GroupIndex++)
        {
            if(u32ChannelGroupsListForEachPartition[CoreId][GroupIndex] == ChannelGroupIdPtr)/* polyspace RTE:NIV,IDP,OBAI */
            {
                GroupAlocated = 1U;
            }
        }
        if(GroupAlocated == 1U)
        {
#endif
            u16Dio_Level = Dio_Auto_Wrap_ReadChannelGroup(ChannelGroupIdPtr);

#ifdef DIO_CHANNEL_GROUPS_AVAILABLE
        }

        else
        {
            #if (DIO_ERROR_CHECK == STD_ON)
             (void)Dio_120ReportError(DIO_READCHANNELGROUP_ID, DIO_E_PARAM_CONFIG);
             #endif
        }
#endif
#if (DIO_ERROR_CHECK == STD_ON)
    }
#endif
    return u16Dio_Level;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

/*****************************************************************************
** Service Name       : Dio_WriteChannelGroupVerify                                              
** 
** 
**  Description      : This function checks whether the parameters 
**  of Dio_WriteChannelGroup are normal.                        
**                                                                            
**  Parameters (in)  : ConfigPtr: Pointer to configuration set                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : u8dio_176VerifyRetval : Boolean variables 
**  used by functions                                                    
**                                                                            
******************************************************************************/
#if (DIO_ERROR_CHECK == STD_ON)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_WriteChannelGroupVerify \
( \
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) Dio_ChannelGroupIdPtr \
)
{
    VAR(Std_ReturnType,AUTOMATIC) u8dio_VerifyRetval = (Std_ReturnType)E_NOT_OK;

    if (NULL_PTR == Dio_ChannelGroupIdPtr)
    {/* polyspace RTE:UNR */
        u8dio_VerifyRetval = (Std_ReturnType)E_NOT_OK;
        (void)Dio_120ReportError((DIO_WRITECHANNELGROUP_ID),(DIO_E_PARAM_POINTER));
    }
    else if((((uint32)(Dio_ChannelGroupIdPtr)) >= ((uint32)Dio_ConfigPC.pChannelGroupList))  &&  \
    (((uint32)(Dio_ChannelGroupIdPtr)) < (uint32)(Dio_ConfigPC.pChannelGroupList + Dio_ConfigPC.u8NumChannelGroups)) &&  \
        ((uint8)Dio_ChannelGroupIdPtr->port < DIO_NUM_PORTS_U16) && \
            ((uint8)Dio_ChannelGroupIdPtr->offset <= DIO_OFFSET_MAX_VALID_U8) && \
            (Dio_WriteAvailablePins[(uint8)(Dio_ChannelGroupIdPtr->port)] != DIO_ZERO_U16))
    {
        u8dio_VerifyRetval = (Std_ReturnType)E_OK;
    }
    else
    {
    	(void)Dio_120ReportError((DIO_WRITECHANNELGROUP_ID), (DIO_E_PARAM_INVALID_GROUP_ID));
    }

    return u8dio_VerifyRetval;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
/*****************************************************************************
**  Description      : Service to set a subset of the adjoining bits of a port
**      to a specified level                          
**                                                                            
**  Service ID       : 0x05                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                          
**                                                                            
**  Parameters (in)  : ChannelGroupIdPtr: Pointer to channelgroup                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC(void, DIO_CODE) Dio_WriteChannelGroup \
( \
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr, \
    CONST(Dio_PortLevelType,AUTOMATIC) Level \
)
{
#ifdef DIO_CHANNEL_GROUPS_AVAILABLE
    VAR(uint8,          AUTOMATIC) GroupAlocated = 0;
    VAR(uint8,          AUTOMATIC) GroupIndex    = 0;
    VAR(uint8,          AUTOMATIC) CoreId = (uint8)Dio_GetCoreID();
#endif
#if (DIO_ERROR_CHECK == STD_ON)
    if ((Std_ReturnType)E_OK == Dio_WriteChannelGroupVerify(ChannelGroupIdPtr))
    {
#endif
#ifdef DIO_CHANNEL_GROUPS_AVAILABLE
        for(GroupIndex = 0U; GroupIndex < Dio_ConfigPC.u8NumChannelGroups; GroupIndex++)
        {
            if(u32ChannelGroupsListForEachPartition[CoreId][GroupIndex] == ChannelGroupIdPtr)/* polyspace RTE:OBAI */
            {
                GroupAlocated = 1U;
            }
        }
        if(GroupAlocated==1U)
        {
#endif
            Dio_Auto_Wrap_WriteChanneGroup(ChannelGroupIdPtr, Level);
#ifdef DIO_CHANNEL_GROUPS_AVAILABLE
        }
        else
        {
            #if (DIO_ERROR_CHECK == STD_ON)
            (void)Dio_120ReportError( DIO_WRITECHANNELGROUP_ID, DIO_E_PARAM_CONFIG);
            #endif
        }
#endif
#if (DIO_ERROR_CHECK == STD_ON)
    }
#endif
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

/*****************************************************************************
** Service Name       : Dio_GetVersionInfoVerify                                              
** 
** 
**  Description      : This function checks whether the parameters 
**  of Dio_GetVersionInfo are normal.                        
**                                                                            
**  Parameters (in)  : VersionInfo: Module Version                          
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : u8dio_176VerifyRetval : Boolean variables 
**  used by functions                                                    
**                                                                            
******************************************************************************/
#if ((DIO_ERROR_CHECK == STD_ON) && (DIO_VERSION_INFO_API == STD_ON))
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_GetVersionInfoVerify \
( \
    P2CONST(Std_VersionInfoType, AUTOMATIC, DIO_APPL_DATA) VersionInfo \
)
{
    VAR(Std_ReturnType,AUTOMATIC) u8dio_VerifyRetval = (Std_ReturnType)E_NOT_OK;

    if (NULL_PTR != VersionInfo)
    {
        u8dio_VerifyRetval = (Std_ReturnType)E_OK;
    }
    else
    {/* polyspace RTE:UNR */
        (void)Dio_120ReportError((DIO_GETVERSIONINFO_ID), (DIO_E_PARAM_POINTER));
    }

    return u8dio_VerifyRetval;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
#if(DIO_VERSION_INFO_API == STD_ON)
/*****************************************************************************
**  Description      : Service to get the version information of this module                          
**                                                                            
**  Service ID       : 0x12                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                          
**                                                                            
**  Parameters (in)  : None
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                  
**                                                                            
******************************************************************************/
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC(void, DIO_CODE) Dio_GetVersionInfo \
( \
    P2VAR(Std_VersionInfoType, AUTOMATIC, DIO_APPL_DATA) VersionInfo \
)
{
#if ((DIO_ERROR_CHECK == STD_ON) && (DIO_VERSION_INFO_API == STD_ON))
    if ((Std_ReturnType)E_OK == Dio_GetVersionInfoVerify(VersionInfo))/* polyspace RTE:UNR */
    {
#endif 
        VersionInfo->vendorID         = (uint16)DIO_TYPES_VENDOR_ID;
        VersionInfo->moduleID         = (uint16)DIO_MODULE_ID;
        VersionInfo->sw_major_version = (uint8)DIO_TYPES_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)DIO_TYPES_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)DIO_TYPES_SW_PATCH_VERSION;
#if (STD_ON == DIO_ERROR_CHECK)        
    }
#endif    
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif

/*****************************************************************************
** Service Name       : Dio_FlipChannelVerify                                              
** 
** 
**  Description      : This function checks whether the parameters 
**  of Dio_FlipChannel are normal.                        
**                                                                            
**  Parameters (in)  : ChannelId: Channel ID number
**                     serviceId: Id for DET Function                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : u8dio_176VerifyRetval : Boolean variables 
**  used by functions                                                    
**                                                                            
******************************************************************************/
#if (DIO_ERROR_CHECK == STD_ON)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType,AUTOMATIC)Dio_FlipChannelVerify \
( \
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId, \
    VAR(uint8, AUTOMATIC) FuncId \
)
{       
    VAR(Std_ReturnType,AUTOMATIC) u8dio_VerifyRetval = (Std_ReturnType)E_NOT_OK; 
    VAR(uint8,          AUTOMATIC) CoreId = (uint8)Dio_GetCoreID();
    VAR(uint32,          AUTOMATIC) channel_flag = 0U;

    if (((Dio_ChannelType)(ChannelId) < DIO_NUM_CHANNELS_U16) && \
    		((Dio_PortLevelType)0U != (Dio_WriteAvailablePins[(ChannelId >> DIO_PORTID_SHIFT_U8 )] \
                        & (DIO_BIT1_LEFTMOST_MASK_U16 \
                        >> (((uint16)ChannelId) & DIO_PIN_MASK_U16)))))   		
    {
    	channel_flag = channel_index[ChannelId];
        if((CoreId < DIO_CORE_NUM) &&(Dio_ConfigPC.Dio_u32ChannelToPartitionMap != NULL_PTR) &&(channel_flag<DIO_NUM_CHANNELS_U16))
        {
        	if (1U == ((Dio_ConfigPC.Dio_u32ChannelToPartitionMap[channel_flag].coreid & (1U << CoreId)) >> CoreId))
        	{
        		u8dio_VerifyRetval = (Std_ReturnType)E_OK;
        	}
        	else
        	{
        		(void)Dio_120ReportError(FuncId, DIO_E_PARAM_CONFIG);
        	}
        }
        else{
            (void)Dio_120ReportError(FuncId, DIO_E_PARAM_CONFIG);
        }  
    }
    else
    {       
        (void)Dio_120ReportError(FuncId,DIO_E_PARAM_INVALID_CHANNEL_ID);    
    }

    return u8dio_VerifyRetval;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
/*****************************************************************************
**  Description      : Service to flip(change from 1 to 0 or from 0 to 1)the 
**  level of a channel and return the lebel of the channel after flip.                       
**                                                                            
**  Service ID       : 0x11                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                          
**                                                                            
**  Parameters (in)  : ChannelId: ID of Dio channel                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                 
**                                                                            
******************************************************************************/
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC(Dio_LevelType, DIO_CODE) Dio_FlipChannel \
( \
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId \
)
{
    VAR(Dio_LevelType, AUTOMATIC) u8Dio_ChannelLevel = (Dio_LevelType)STD_LOW;

#if (STD_ON == DIO_ERROR_CHECK)
    if ((Std_ReturnType)E_OK == Dio_FlipChannelVerify(ChannelId,DIO_FLIPCHANNEL_ID))
    {
#endif
        u8Dio_ChannelLevel = Dio_Auto_Wrap_FlipChannel(ChannelId);
#if (STD_ON == DIO_ERROR_CHECK)
    }
#endif

    return u8Dio_ChannelLevel;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

/*****************************************************************************
** Service Name       : Dio_MaskedWritePortVerify                                              
** 
** 
**  Description      : This function checks whether the parameters 
**  of Dio_MaskedWritePort are normal.                        
**                                                                            
**  Parameters (in)  : PortId: Port ID number
**                     serviceId: Id for DET Function                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : u8dio_176VerifyRetval : Boolean variables 
**  used by functions                                                    
**                                                                            
******************************************************************************/
#if ((DIO_ERROR_CHECK == STD_ON) && (STD_ON == DIO_MASKEDWRITEPORT_API))
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_MaskedWritePortVerify \
( \
    VAR(Dio_PortType, AUTOMATIC) PortId, \
    VAR(Dio_PortLevelType, AUTOMATIC) Mask, \
    VAR(uint8, AUTOMATIC) FuncId \
)
{
    VAR(Std_ReturnType,AUTOMATIC) u8dio_VerifyRetval = (Std_ReturnType)E_NOT_OK;
    VAR(uint8,          AUTOMATIC) CoreId = (uint8)Dio_GetCoreID();
    VAR(uint32,          AUTOMATIC) port_flag = 0U;

    if (((uint8)(PortId) < DIO_NUM_PORTS_U16) && ((Mask & Dio_WriteAvailablePins[(uint8)PortId])!=0U))
    {
        port_flag = port_index[PortId];
        if((CoreId < DIO_CORE_NUM)&&(Dio_ConfigPC.Dio_u32PortToPartitionMap!=NULL_PTR) && (port_flag<DIO_NUM_PORTS_U16))
        {
        	if (1U == ((Dio_ConfigPC.Dio_u32PortToPartitionMap[port_flag].coreid & (1U << CoreId)) >> CoreId))
        	{
        			u8dio_VerifyRetval = (Std_ReturnType)E_OK;
        	}
        	else
        	{
				#if (DIO_ERROR_CHECK == STD_ON)
        		(void)Dio_120ReportError(FuncId, DIO_E_PARAM_CONFIG);
				#endif
        	}
        }
        else{
				#if (DIO_ERROR_CHECK == STD_ON)
        		(void)Dio_120ReportError(FuncId, DIO_E_PARAM_CONFIG);
				#endif
        }
    }
    else
    {        
#if (DIO_ERROR_CHECK == STD_ON)
    	(void)Dio_120ReportError(FuncId,DIO_E_PARAM_INVALID_PORT_ID);
#endif
    }

    return u8dio_VerifyRetval;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
#if (STD_ON == DIO_MASKEDWRITEPORT_API)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC(void, DIO_CODE) Dio_MaskedWritePort \
( \
    CONST(Dio_PortType, AUTOMATIC) PortId, \
    CONST(Dio_PortLevelType, AUTOMATIC) Level, \
    CONST(Dio_PortLevelType, AUTOMATIC) Mask \
)
{
#if ((DIO_ERROR_CHECK == STD_ON) && (STD_ON == DIO_MASKEDWRITEPORT_API))
    if ((Std_ReturnType)E_OK == Dio_MaskedWritePortVerify(PortId, Mask, DIO_MASKEDWRITEPORT_ID))
    {
#endif
    	Dio_Auto_Wrap_MaskedWritePort(PortId, Level, Mask);
#if (STD_ON == DIO_ERROR_CHECK)
    }
#endif
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif



#ifdef __cplusplus
}
#endif

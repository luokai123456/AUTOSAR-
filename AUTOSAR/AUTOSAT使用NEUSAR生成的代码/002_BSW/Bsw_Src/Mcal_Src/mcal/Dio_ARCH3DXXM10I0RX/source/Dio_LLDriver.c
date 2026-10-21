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
*   @file    Dio_LLDriver.c
*   @version 3.0.0
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Dio MCAL driver.
*   @addtogroup Dio
*   @{
*/
/*PRQA S 0380,2980,2985 EOF*/
/*PRQA S 2844 EOF*/ /*QAC_CWE*/
#ifdef __cplusplus
extern "C"{
#endif

/* ==============================================INCLUDE FILES======================================= */
#include "Dio_LLDriver.h"
#include "SchM_Dio.h"
/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define DIO_LLD_VENDOR_ID                     176
#define DIO_LLD_MAJOR_VERSION                 4
#define DIO_LLD_MINOR_VERSION                 4
#define DIO_LLD_patch_VERSION                 0
#define DIO_LLD_SW_MAJOR_VERSION              3
#define DIO_LLD_SW_MINOR_VERSION              0
#define DIO_LLD_SW_PATCH_VERSION              0

/* ============================================FILE VERSION CHECKS=================================== */
#if (DIO_LLD_VENDOR_ID != DIO_LLD_H_VENDOR_ID)
    #error " NON-MATCHED DATA : DIO_LLD_VENDOR_ID "
#endif
#if (DIO_LLD_MAJOR_VERSION != DIO_LLD_H_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_LLD_MAJOR_VERSION "
#endif
#if (DIO_LLD_MINOR_VERSION != DIO_LLD_H_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_LLD_MINOR_VERSION "
#endif
#if (DIO_LLD_patch_VERSION != DIO_LLD_H_patch_VERSION)
    #error " NON-MATCHED DATA : DIO_LLD_patch_VERSION "
#endif
#if (DIO_LLD_SW_MAJOR_VERSION != DIO_LLD_H_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_LLD_SW_MAJOR_VERSION "
#endif
#if (DIO_LLD_SW_MINOR_VERSION != DIO_LLD_H_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_LLD_SW_MINOR_VERSION "
#endif
#if (DIO_LLD_SW_PATCH_VERSION != DIO_LLD_H_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : DIO_LLD_SW_PATCH_VERSION "
#endif

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC (uint32, DIO_CODE) Dio_LLDrivers_ChannelGroupLevel \
( \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_port, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_Level, \
    VAR(uint8, AUTOMATIC) u8Dio_offset, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_mask \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#if defined (RESOURCE_SUPPORT_SIUL2_IP)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC (Dio_PortLevelType, DIO_CODE)SIUL_Dio_ReadChannelGroup \
( \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_ChannelGroupport, \
    VAR(uint8, AUTOMATIC) u8Dio_ChannelGroupoffset, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_ChannelGroupmask, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_PortLevel \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#elif defined (RESOURCE_SUPPORT_SIUL_IP)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC (Dio_PortLevelType, DIO_CODE)SIUL_Dio_ReadChannelGroup \
( \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_ChannelGroupport, \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_ChannelGroup, \
    VAR(uint8, AUTOMATIC) u8Dio_ChannelGroupoffset, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_ChannelGroupmask, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_PortLevel \
);
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
/*****************************************************************************
** Service Name       : Dio_LLDrivers_ReadChannel                                              
** 
** 
**  Description      : Service to read a level of a channel                         
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
FUNC (Dio_LevelType, DIO_CODE) Dio_LLDrivers_ReadChannel \
( \
    CONST(Dio_ChannelType, AUTOMATIC) u16Dio_ChannelId \
)
{
    VAR(Dio_LevelType, AUTOMATIC) u8Dio_ChannelLevel = (Dio_LevelType) STD_LOW;

#if defined (RESOURCE_SUPPORT_SIUL2_IP)
    u8Dio_ChannelLevel = SIUL2.GPDI[u16Dio_ChannelId].B.PDI;/* polyspace RTE:NIV,OBAI */ 
#elif defined (RESOURCE_SUPPORT_SIUL_IP)
    u8Dio_ChannelLevel = SIUL.GPDI[u16Dio_ChannelId].B.PDI;/* polyspace RTE:NIV,OBAI */
#endif 
    return u8Dio_ChannelLevel;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

/*****************************************************************************
** Service Name       : Dio_LLDrivers_WriteChannel                                              
** 
** 
**  Description      : Service to write a level of a channel                         
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
FUNC (void, DIO_CODE) Dio_LLDrivers_WriteChannel \
( \
    CONST(Dio_ChannelType, AUTOMATIC) u16Dio_ChannelId, \
    CONST(Dio_LevelType, AUTOMATIC) u8Dio_Level \
)
{ 
    SchM_Enter_Dio_EXCLUSIVE_AREA_02();

#if defined (RESOURCE_SUPPORT_SIUL2_IP)
	SIUL2.GPDO[u16Dio_ChannelId].B.PDO = u8Dio_Level;/* polyspace RTE:OBAI */
#elif defined (RESOURCE_SUPPORT_SIUL_IP)
    SIUL.GPDO[u16Dio_ChannelId].B.PDO = u8Dio_Level;/* polyspace RTE:OBAI */
#endif

    SchM_Exit_Dio_EXCLUSIVE_AREA_02();
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#ifdef __HIGHTEC__
#pragma GCC diagnostic push
#pragma GCC optimize("O0")
#endif
#ifdef __S32DS__
#pragma GCC diagnostic push
#pragma GCC optimize("O0")
#endif
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC(Dio_LevelType, DIO_CODE) Dio_LLDrivers_FlipChannel \
( \
    CONST(Dio_ChannelType, AUTOMATIC) u16Dio_ChannelId, \
    VAR(Dio_LevelType, DIO_VAR) u8Dio_ChannelLevel \
)
{
    VAR(Dio_LevelType, DIO_VAR) u8ChannelLevel = 0;

    SchM_Enter_Dio_EXCLUSIVE_AREA_01();

#if defined (RESOURCE_SUPPORT_SIUL2_IP)
    SIUL2.GPDO[u16Dio_ChannelId].B.PDO = (Dio_LevelType)u8Dio_ChannelLevel;
    u8ChannelLevel =  SIUL2.GPDI[u16Dio_ChannelId].B.PDI;/* polyspace RTE:NIV */ 
#elif defined (RESOURCE_SUPPORT_SIUL_IP)
    SIUL.GPDO[u16Dio_ChannelId].B.PDO = (Dio_LevelType)u8Dio_ChannelLevel;
    u8ChannelLevel =  SIUL.GPDI[u16Dio_ChannelId].B.PDI;/* polyspace RTE:NIV */
#endif
    SchM_Exit_Dio_EXCLUSIVE_AREA_01();
    
    return u8ChannelLevel;
}
#ifdef __S32DS__
#pragma GCC diagnostic pop
#endif
#ifdef __HIGHTEC__
#pragma GCC diagnostic pop
#endif
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

/*****************************************************************************
** Service Name       : Dio_LLDrivers_ReadPorts                                              
** 
** 
**  Description      : Returns the Level of all channels of that port                          
**                                                                            
**  Parameters (in)  : PortlId: ID of Dio port    
**                      PortLevel: level of port                         
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Dio_PortLevelType                                                   
**                                                                            
******************************************************************************/
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC (Dio_PortLevelType, DIO_CODE) Dio_LLDrivers_ReadPort \
( \
    CONST(Dio_PortType, DIO_CONST) u8Dio_PortId \
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) uDio_PortLevelType =  STD_LOW;

#if defined (RESOURCE_SUPPORT_SIUL2_IP)
    uDio_PortLevelType = SIUL2.PGPDI[u8Dio_PortId].B.PPDI;/* polyspace RTE:NIV */
#elif defined (RESOURCE_SUPPORT_SIUL_IP)
    uint32_t u32PgpdoIndex = (uint32_t)u8Dio_PortId/2U;
    uDio_PortLevelType = SIUL.PGPDI[u32PgpdoIndex].R;/* polyspace RTE:OBAI */
#endif

#if (DIO_READZERO_UNDEFINEDPORTS == STD_ON)
    {
#if defined (RESOURCE_SUPPORT_SIUL2_IP)
        uDio_PortLevelType = (uDio_PortLevelType & Dio_ReadAvailablePins[u8Dio_PortId]);
#elif defined (RESOURCE_SUPPORT_SIUL_IP)
        if((u8Dio_PortId % 2U) == 0U)
        {
            /* PB, PD, PF... use High 16bit of PGPDI[x] */
            uDio_PortLevelType &= 0xffff0000U;
            uDio_PortLevelType >>= 16U;
        }
        else
        {
            /* PA, PC, PE... use Low 16bit of PGPDI[x] */
            uDio_PortLevelType &= 0xffffU;
        }
        uDio_PortLevelType &= (Dio_ReadAvailablePins[u8Dio_PortId] & 0xffffUL);
#endif
    }
#endif

    return uDio_PortLevelType;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

/*****************************************************************************
** Service Name       : Dio_LLDrivers_WritePort                                              
** 
** 
**  Description      : Service to set a value of the port                           
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
FUNC (void, DIO_CODE) Dio_LLDrivers_WritePort \
( \
    CONST(Dio_PortType, DIO_CONST) u8Dio_PortId, \
    CONST(Dio_PortLevelType, DIO_CONST) uDio_Level \
)
{
#if defined (RESOURCE_SUPPORT_SIUL2_IP)
    SIUL2.PGPDO[u8Dio_PortId].B.PPDO = uDio_Level;
#elif defined (RESOURCE_SUPPORT_SIUL_IP)
    uint32_t u32PgpdoIndex = (uint32_t)u8Dio_PortId/2U;
    uint32_t u32Temp = SIUL.PGPDO[u32PgpdoIndex].R;
    if((u8Dio_PortId % 2U) == 0U)
    {
        /* PB, PD, PF... use High 16bit of PGPDI[x] */
        u32Temp &= 0xffffU;
        u32Temp |= ((uDio_Level & 0xffffU) << 16U);
    }
    else
    {
        /* PA, PC, PE... use Low 16bit of PGPDI[x] */
        u32Temp &= 0xffff0000U;
        u32Temp |= (uDio_Level & 0xffffU);
    }

    SIUL.PGPDO[u32PgpdoIndex].R = u32Temp;/* polyspace RTE:OBAI */
#endif
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#if defined (RESOURCE_SUPPORT_SIUL2_IP)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC (Dio_PortLevelType, DIO_CODE)SIUL_Dio_ReadChannelGroup \
( \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_ChannelGroupport, \
    VAR(uint8, AUTOMATIC) u8Dio_ChannelGroupoffset, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_ChannelGroupmask, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_PortLevel \
)
{

    u16Dio_PortLevel = SIUL2.PGPDI[u8Dio_ChannelGroupport].R;/* polyspace RTE:NIV,OBAI */ 
    if(u8Dio_ChannelGroupoffset<=16U)
    {
        u16Dio_PortLevel = (Dio_PortLevelType)((u16Dio_PortLevel & u16Dio_ChannelGroupmask) >> u8Dio_ChannelGroupoffset);
    }

    return u16Dio_PortLevel;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#elif defined (RESOURCE_SUPPORT_SIUL_IP)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC (Dio_PortLevelType, DIO_CODE)SIUL_Dio_ReadChannelGroup \
( \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_ChannelGroupport, \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_ChannelGroup, \
    VAR(uint8, AUTOMATIC) u8Dio_ChannelGroupoffset, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_ChannelGroupmask, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_PortLevel \
)
{

	u16Dio_PortLevel = SIUL.PGPDI[u8Dio_ChannelGroupport].R;/* polyspace RTE:NIV,OBAI */
    if(u8Dio_ChannelGroupoffset<=16U)
    {
    	u16Dio_PortLevel = (Dio_PortLevelType)((u16Dio_PortLevel & (u16Dio_ChannelGroupmask << (((u8Dio_ChannelGroup + 1U) % 2U) * 16U))) >> (u8Dio_ChannelGroupoffset + (((u8Dio_ChannelGroup + 1U) % 2U) * 16U)));/* polyspace RTE:SHF */
    }

    return u16Dio_PortLevel;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
/*****************************************************************************
** Service Name       : Dio_LLDrivers_ReadChannelGroup                                              
** 
** 
**  Description      : This seevice reads a subset of the adjoining bits of 
**      a port                     
**                                                                            
**  Parameters (in)  : ChannelGroupport: Port Id number
**                      PortLevel: Level to be set
**                       ChannelGroupmask: mask to be use 
**                      ChannelGroupoffset: offset to be use                                                                             
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Dio_PortLevelType                                                   
**                                                                            
******************************************************************************/
#if defined (RESOURCE_SUPPORT_SIUL2_IP)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC (Dio_PortLevelType, DIO_CODE) Dio_LLDrivers_ReadChannelGroup \
( \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_ChannelGroupport, \
    VAR(uint8, AUTOMATIC) u8Dio_ChannelGroupoffset, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_ChannelGroupmask, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_PortLevel \
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) u16DioPortLevel = 0x0;

    u16DioPortLevel = SIUL_Dio_ReadChannelGroup \
                        ( \
                            u8Dio_ChannelGroupport, \
                            u8Dio_ChannelGroupoffset, \
                            u16Dio_ChannelGroupmask, \
                            u16Dio_PortLevel \
                        );

    return u16DioPortLevel; 
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#elif defined (RESOURCE_SUPPORT_SIUL_IP)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC (Dio_PortLevelType, DIO_CODE) Dio_LLDrivers_ReadChannelGroup \
( \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_ChannelGroupport, \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_ChannelGroup, \
    VAR(uint8, AUTOMATIC) u8Dio_ChannelGroupoffset, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_ChannelGroupmask, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_PortLevel \
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) u16DioPortLevel = 0x0;

    u16DioPortLevel = SIUL_Dio_ReadChannelGroup \
                        ( \
                            u8Dio_ChannelGroupport, \
                            u8Dio_ChannelGroup, \
                            u8Dio_ChannelGroupoffset, \
                            u16Dio_ChannelGroupmask, \
                            u16Dio_PortLevel \
                        );

    return u16DioPortLevel; 
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
/*****************************************************************************
** Service Name       : Dio_LLDrivers_WriteChannelGroup                                              
** 
** 
**  Description      : Service to set a subset of the adjoining bits of a port
**      to a specified level                     
**                                                                            
**  Parameters (in)  : PortId: Port Id number
**                      Level: Level to be set
**                       Mask: mask to be use 
**                      level: Level to be set                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC (void, DIO_CODE) Dio_LLDrivers_WriteChannelGroup \
( \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_port, \
    VAR(uint8, AUTOMATIC) u8Dio_offset, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_mask, \
    CONST(Dio_PortLevelType, DIO_CONST) u16Dio_Level \
)
{
    VAR(uint32, DIO_CONST) u32Dio_PortLevel = Dio_LLDrivers_ChannelGroupLevel \
                                                ( \
                                                    u8Dio_port, \
                                                    u16Dio_Level, \
                                                    u8Dio_offset, \
                                                    u16Dio_mask \
                                                );
												
#if defined (RESOURCE_SUPPORT_SIUL2_IP)
    SIUL2.MPGPDO[u8Dio_port].R = u32Dio_PortLevel;/* polyspace RTE:IDP */
#elif defined (RESOURCE_SUPPORT_SIUL_IP)
    SIUL.MPGPDO[u8Dio_port].R = u32Dio_PortLevel;/* polyspace RTE:IDP */
#endif
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#if defined (RESOURCE_SUPPORT_SIUL2_IP)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC (uint32, DIO_CODE) Dio_LLDrivers_ChannelGroupLevel \
( \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_port, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_Level, \
    VAR(uint8, AUTOMATIC) u8Dio_offset, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_mask \
)
{
    VAR(uint32, AUTOMATIC) u32Dio_MPGPDOmask = 0;

    VAR(uint32, DIO_CONST) u32Dio_PortLevel = SIUL2.MPGPDO[u8Dio_port].B.MPPDO;/* polyspace RTE:NIV,IDP,OBAI */

    VAR(Dio_PortLevelType, AUTOMATIC) u16DioLevel = 0;

    u32Dio_MPGPDOmask = ((uint32)u16Dio_mask << 0x10);
    if(u8Dio_offset<=16U)
    {
    	u16DioLevel = (uint16)( ((uint32)(u16Dio_Level) << (u8Dio_offset)) & (((uint16)0xffff)));
    }
    u32Dio_PortLevel |= (u32Dio_MPGPDOmask | u16DioLevel);

    return u32Dio_PortLevel;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#elif defined (RESOURCE_SUPPORT_SIUL_IP)
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_INLINE FUNC (uint32, DIO_CODE) Dio_LLDrivers_ChannelGroupLevel \
( \
    VAR(Dio_PortType, AUTOMATIC) u8Dio_port, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_Level, \
    VAR(uint8, AUTOMATIC) u8Dio_offset, \
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_mask \
)
{
    VAR(uint32, AUTOMATIC) u32Dio_MPGPDOmask = 0;

    VAR(uint32, DIO_CONST) u32Dio_PortLevel = SIUL.MPGPDO[u8Dio_port].B.MPPDO;/* polyspace RTE:NIV,IDP,OBAI */

    VAR(Dio_PortLevelType, AUTOMATIC) u32DioLevel = 0;

    u32Dio_MPGPDOmask = (((uint32)u16Dio_mask) << 0x10);
    if(u8Dio_offset<=16U)
    {
    	u32DioLevel = (uint32)( (((uint32)(u16Dio_Level)) << (u8Dio_offset)) & (((uint32)0xffffffffUL)));
    }
    u32Dio_PortLevel |= (u32Dio_MPGPDOmask | u32DioLevel);

    return u32Dio_PortLevel;
}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif

#if (STD_ON == DIO_MASKEDWRITEPORT_API)

/*****************************************************************************
** Service Name       : Dio_LLDrivers_MaskedWritePort                                              
** 
** 
**  Description      : Service to set a subset of the adjoining bits of a port
**      to a specified level                     
**                                                                            
**  Parameters (in)  : PortId: Port Id number
**                      Level: Level to be set
**                       Mask: mask to be use                             
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
FUNC (void, DIO_CODE) Dio_LLDrivers_MaskedWritePort \
( \
    CONST(Dio_PortType, DIO_CONST) u8Dio_176PortId, \
    CONST(Dio_PortLevelType, DIO_CONST) u16Dio_176Level, \
    CONST(Dio_PortLevelType, DIO_CONST) u16Dio_176Mask \
)
{
    VAR(uint32, DIO_CONST) u32Dio_MPGPDOMask = 0;
    VAR(uint32, DIO_CONST) u32Dio_MPGPDOLevel = 0;
    u32Dio_MPGPDOMask  = ((uint32)u16Dio_176Mask << 0x10);
    u32Dio_MPGPDOLevel = (u32Dio_MPGPDOMask | u16Dio_176Level);

#if defined (RESOURCE_SUPPORT_SIUL2_IP)
    SIUL2.MPGPDO[u8Dio_176PortId].R = u32Dio_MPGPDOLevel;/* polyspace RTE:OBAI */
#elif defined (RESOURCE_SUPPORT_SIUL_IP)
    SIUL.MPGPDO[u8Dio_176PortId].R = u32Dio_MPGPDOLevel;/* polyspace RTE:OBAI */
#endif

}
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#endif
#ifdef __cplusplus
}
#endif

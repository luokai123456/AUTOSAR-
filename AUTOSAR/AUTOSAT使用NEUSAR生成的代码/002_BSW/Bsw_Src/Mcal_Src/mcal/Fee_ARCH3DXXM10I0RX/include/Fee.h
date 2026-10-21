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
*   Autosar Revision     : 
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Fee.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FEE MCAL driver.
*
*   @addtogroup FEE
*   @{
*/

#ifndef FEE_H
#define FEE_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Fee_Cfg.h"
#include "Fee_Cbk.h"
#include "MemIf_Types.h"
#include "Det.h"

#define FEE_H_VENDOR_ID_PLUGIN              176
#define FEE_AR_RELEASE_MAJOR_VERSION        4
#define FEE_AR_RELEASE_MINOR_VERSION        4
#define FEE_H_AR_REL_REV_VER                0
#define FEE_H_SW_MAJOR_VER                  3
#define FEE_H_SW_MINOR_VER                  0
#define FEE_H_SW_PATCH_VER                  0
#define FEE_INSTANCE_ID                0U
  
#if (FEE_VENDOR_ID_OUTPUT != FEE_H_VENDOR_ID_PLUGIN)
    #error " NON-MATCHED DATA : FEE_H_VENDOR_ID_PLUGIN "
#endif
#if (FEE_AR_REL_MAJOR_VER_OUTPUT != FEE_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : FEE_AR_RELEASE_MAJOR_VERSION "
#endif
#if (FEE_AR_REL_MINOR_VER_OUTPUT != FEE_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : FEE_AR_RELEASE_MINOR_VERSION "
#endif
#if (FEE_AR_REL_REVISION_VER_OUTPUT != FEE_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : FEE_H_AR_REL_REV_VER "
#endif
#if (FEE_SW_MAJOR_VERSION_OUTPUT != FEE_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : FEE_H_SW_MAJOR_VER "
#endif
#if (FEE_SW_MINOR_VERSION_OUTPUT != FEE_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : FEE_H_SW_MINOR_VER "
#endif
#if (FEE_SW_PATCH_VERSION_OUTPUT != FEE_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : FEE_H_SW_PATCH_VER "
#endif


#define FEE_CORE_NUM                   MCAL_CORE_NUM

#define FEE_INIT_ID                    0x00U
#define FEE_SETMODE_ID                 0x01U
#define FEE_READ_ID                    0x02U
#define FEE_WRITE_ID                   0x03U
#define FEE_CANCEL_ID                  0x04U
#define FEE_GETSTATUS_ID               0x05U
#define FEE_GETJOBRESULT_ID            0x06U
#define FEE_INVALIDATEBLOCK_ID         0x07U
#define FEE_GETVERSIONINFO_ID          0x08U
#define FEE_ERASEIMMEDIATEBLOCK_ID     0x09U
#define FEE_JOBENDNOTIFICATION_ID      0x10U
#define FEE_JOBERRORNOTIFICATION_ID    0x11U
#define FEE_MAINFUNCTION_ID            0x12U

#define FEE_GETRUNTIMEINFO_ID          0x13U
#define FEE_FORCESWAPONNEXTWRITE_ID    0x14U

#define FEE_E_UNINIT                  0x01U
#define FEE_E_INVALID_BLOCK_NO        0x02U
#define FEE_E_INVALID_BLOCK_OFS       0x03U
#define FEE_E_PARAM_POINTER           0x04U
#define FEE_E_INVALID_BLOCK_LEN       0x05U
#define FEE_E_INIT_FAILED             0x09U

#define FEE_E_BUSY                    0x06U
#define FEE_E_INVALID_CANCEL          0x08U

#define FEE_E_CANCEL_API              0x0AU
#define FEE_E_CLUSTER_GROUP_IDX       0x0BU 
#define FEE_E_FOREIGN_BLOCKS_OVF      0x0CU

typedef enum
{
    FEE_BLOCK_VALID ,
    FEE_BLOCK_INVALID,   
    FEE_BLOCK_INCONSISTENT,
    FEE_BLOCK_HEADER_INVALID,  
    FEE_BLOCK_INVALIDATED,
    FEE_BLOCK_HEADER_BLANK,
#if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_ON)   
    FEE_BLOCK_INCONSISTENT_COPY       
#else
    FEE_BLOCK_INCONSISTENT_COPY,        
    FEE_BLOCK_NEVER_WRITTEN
#endif
} Fee_BlockStatus_Type;

typedef struct
{
    VAR(Fls_AddressType, AUTOMATIC) Fee_DataAddr;
    VAR(Fls_AddressType, AUTOMATIC) Fee_InvalidAddr;
    VAR(Fee_BlockStatus_Type, AUTOMATIC) Fee_BlockStatus;
} Fee_BlockInfo_Type;

extern VAR(Fee_JobResult_Type, FEE_VAR) Fee_JobConfig;


#if (FEE_DEV_ERROR_DETECT == STD_ON)
#define Fee_ReportError(Fee_ApiId, Fee_ErrorId) \
        (void)Det_ReportError( (uint16)FEE_MODULE_ID_PLUGIN, FEE_INSTANCE_ID, (Fee_ApiId), (Fee_ErrorId) );
#endif 

#define Fee_ReportRuntimeError(Fee_ApiId, Fee_ErrorId) \
        (void)Det_ReportRuntimeError( (uint16)FEE_MODULE_ID_PLUGIN, FEE_INSTANCE_ID, (Fee_ApiId), (Fee_ErrorId) );

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( void, FEE_CODE ) Fee_Init \
( \
    P2CONST(Fee_ConfigType, FEE_VAR, FEE_APPL_CONST) ConfigPtr \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"


#if( FEE_SETMODE_API_SUPPORTED == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( void, FEE_CODE ) Fee_SetMode \
( \
    VAR( MemIf_ModeType, AUTOMATIC ) Mode \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( Std_ReturnType, FEE_CODE ) Fee_Read \
( \
    VAR( uint16, AUTOMATIC ) BlockNumber, \
    VAR( uint16, AUTOMATIC ) BlockOffset, \
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) DataBufferPtr, \
    VAR( uint16, AUTOMATIC ) Length \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( Std_ReturnType, FEE_CODE ) Fee_Write \
( \
   VAR( uint16, AUTOMATIC ) BlockNumber, \
   P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) DataBufferPtr \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#if( FEE_CANCEL_API == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( void, FEE_CODE ) Fee_Cancel( void );
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( MemIf_StatusType, FEE_CODE ) Fee_GetStatus( void );
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( MemIf_JobResultType, FEE_CODE ) Fee_GetJobResult( void );
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"


#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( Std_ReturnType, FEE_CODE ) Fee_InvalidateBlock \
( \
    VAR( uint16, AUTOMATIC ) BlockNumber \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#if( FEE_VERSION_INFO_API == STD_ON )

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( void, FEE_CODE ) Fee_GetVersionInfo \
( \
    P2VAR( Std_VersionInfoType, AUTOMATIC, FEE_APPL_DATA ) VersionInfoPtr \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#endif

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( Std_ReturnType, FEE_CODE ) Fee_EraseImmediateBlock \
( \
    VAR( uint16, AUTOMATIC ) BlockNumber \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"


#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( void, FEE_CODE ) Fee_MainFunction( void );
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( Fee_ClusterGroupRuntimeInfo_Type, FEE_CODE ) Fee_GetRunTimeInfo \
( \
    VAR( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( Std_ReturnType, FEE_CODE ) Fee_ForceSwapOnNextWrite \
( \
    VAR( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex \
); 
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FEE_H */
/** @} */

/* PRQA S 2053, 3432, 0311 EOF */
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
/* PRQA S 0498,2461,4115,4558,4116,2003,3604,1259 EOF */   
/**
*   @file    Fee.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FEE MCAL driver.
*
*   @addtogroup FEE
*   @{
*/

/* PRQA S 0488, 0310, 3305, 0491, 2844 EOF */

#ifdef __cplusplus
extern "C"{
#endif

#include "Fee.h" /* PRQA S 0380 */
#include "SchM_Fee.h"

#define FEE_C_VENDOR_ID_PLUGIN              176
#define FEE_C_AR_REL_MAJOR_VER				4
#define FEE_C_AR_REL_MINOR_VER			    4
#define FEE_C_AR_REL_REV_VER   		        0
#define FEE_C_SW_MAJOR_VER                  3
#define FEE_C_SW_MINOR_VER                  0
#define FEE_C_SW_PATCH_VER                  0
  
#if (FEE_VENDOR_ID_OUTPUT != FEE_C_VENDOR_ID_PLUGIN)
    #error " NON-MATCHED DATA : FEE_C_VENDOR_ID_PLUGIN "
#endif
#if (FEE_AR_REL_MAJOR_VER_OUTPUT != FEE_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : FEE_C_AR_REL_MAJOR_VER "
#endif
#if (FEE_AR_REL_MINOR_VER_OUTPUT != FEE_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : FEE_C_AR_REL_MINOR_VER "
#endif
#if (FEE_AR_REL_REVISION_VER_OUTPUT != FEE_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : FEE_C_AR_REL_REV_VER "
#endif
#if (FEE_SW_MAJOR_VERSION_OUTPUT != FEE_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : FEE_C_SW_MAJOR_VER "
#endif
#if (FEE_SW_MINOR_VERSION_OUTPUT != FEE_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : FEE_C_SW_MINOR_VER "
#endif
#if (FEE_SW_PATCH_VERSION_OUTPUT != FEE_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : FEE_C_SW_PATCH_VER "
#endif

#define FEE_SERIALIZE( paramVal, paramType, serialPtr ) \
{ \
    *((paramType*)(serialPtr)) = (paramVal); \
    (serialPtr) += sizeof(paramType); \
}
    
#define FEE_DESERIALIZE( deserialPtr, paramVal, paramType ) \
{ \
    (paramVal) = *((paramType*)(deserialPtr)); \
    (deserialPtr) += sizeof(paramType); \
}

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) && (FEE_LEGACY_MODE == STD_OFF)
#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
static VAR( uint32, FEE_VAR )
    Fee_aReservedAreaTouched[
                              (FEE_MAX_NR_OF_BLOCKS+((sizeof( uint32 )*8U) - 1U)) /
                              (sizeof( uint32 ) * 8U)
                            ] = { 0UL };
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"
#endif

#define FEE_JOB_MAX_COUNT 20U
#if !defined(__DOXYGEN__)
FEE_NVM_JOB_END_NOTIFICATION_DECL

FEE_NVM_JOB_ERROR_NOTIFICATION_DECL

FEE_NVM_CLUSTER_FORMAT_NOTIFICATION_DECL
#endif

#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
static VAR(uint16, FEE_VAR) u16Fee_JobBlockIndex = 0U;
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"


#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
static VAR(uint16, FEE_VAR) u16Fee_JobIntBlockIt = 0U;
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
static VAR(Fls_LengthType, FEE_VAR) u16Fee_JobBlockOffset = 0U;  
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
static VAR(Fls_LengthType, FEE_VAR) u16Fee_JobBlockLength = 0U; 
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
static P2VAR( uint8, FEE_VAR, FEE_APPL_DATA ) gFee_JobDataDestPtr = NULL_PTR;
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
static VAR(uint8, FEE_VAR) gFee_DataBuffer[FEE_DATA_BUFFER_SIZE] = {(uint8)0}; /* PRQA S 0686 */
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
static P2CONST(Fee_ConfigType, FEE_VAR, FEE_APPL_CONST) gFee_ConfigPtr = NULL_PTR;
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
static VAR(uint8, FEE_VAR) gFee_JobIntClrGrpIt = 0U;
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
static VAR(uint8, FEE_VAR) gFee_JobIntClrIt = 0U;
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
static VAR(Fls_AddressType, FEE_VAR) u32Fee_JobIntAddrIt = 0U;
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
static VAR(Fls_AddressType, FEE_VAR) u32Fee_JobIntHdrAddr = 0U;
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
static VAR(Fls_AddressType, FEE_VAR) u32Fee_JobIntDataAddr = 0U;
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_NO_INIT
#include "Fee_MemMap.h"
static VAR(Fee_ClusterGroupInfo_Type, FEE_VAR) gFee_ClrGrpInfo[FEE_NUMBER_OF_CLUSTER_GROUPS];
#define FEE_STOP_SEC_VAR_NO_INIT
#include "Fee_MemMap.h"


#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
static VAR(Fee_BlockConfig_Type, FEE_VAR) Fee_ForeignBlockConfig[FEE_MAX_NR_OF_BLOCKS - FEE_NUMBER_OF_BLOCKS]={{0U}};
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"
#endif

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
static VAR(uint16, FEE_VAR) u16Fee_ForeignBlocksNumber = 0U;
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"

#endif
#define FEE_START_SEC_VAR_INIT
#include "Fee_MemMap.h"
 

VAR(Fee_JobResult_Type, FEE_VAR) Fee_JobConfig = 
{
    FEE_JOB_DONE,
    FEE_JOB_DONE,
    MEMIF_JOB_OK,
    MEMIF_UNINIT
};
#define FEE_STOP_SEC_VAR_INIT
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_NO_INIT
#include "Fee_MemMap.h"
static VAR(Fee_BlockInfo_Type, FEE_VAR) gFee_BlockInfo[FEE_MAX_NR_OF_BLOCKS];
#define FEE_STOP_SEC_VAR_NO_INIT
#include "Fee_MemMap.h"


#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( void, FEE_CODE ) Fee_SerializeBlockHdr \
( \
    CONST( uint16, AUTOMATIC ) u16Fee_BlockNumber, \
    CONST( uint16, AUTOMATIC ) u16Fee_Length, \
    CONST( Fls_AddressType, AUTOMATIC) u32Fee_TargetAddress, \
    CONST( boolean, AUTOMATIC ) bFee_ImmediateBlock, 
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    CONST( Fee_BlockAssignmentType, AUTOMATIC ) uBlockAssignment,
#endif
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_BlockHdrPtr \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_BlankCheck \
( \
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) u8Fee_TargetPtr, \
    CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) u8Fee_TargetEndPtr
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
    
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_DeserializeFlag \
( \
    CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) u8Fee_TargetPtr, \
    VAR( uint8, AUTOMATIC ) u8Fee_FlagPattern, \
    P2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) bFee_FlagValue \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Fee_BlockStatus_Type, FEE_CODE ) Fee_DeserializeBlockHdr \
( \
    CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) u16Fee_BlockNumber, \
    CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) u16Fee_Length, \
    CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) u32Fee_TargetAddress, \
    P2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) bFee_ImmediateBlock,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    CONSTP2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_BlockAssignment,
#endif
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) u8Fee_BlockHdrPtr \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
    
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Fee_ClusterStatus_Type, FEE_CODE ) Fee_DeserializeClusterHdr \
( \
    CONSTP2VAR( uint32, AUTOMATIC, FEE_APPL_DATA ) u32Fee_ClrID, \
    CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) u32Fee_StartAddress, \
    CONSTP2VAR( Fls_LengthType, AUTOMATIC, FEE_APPL_DATA ) u32Fee_ClusteSize, \
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) u8Fee_ClrHdrPtr \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"    
FEE_INLINE FUNC( void, FEE_CODE ) Fee_SerializeClusterHdr \
( \
    CONST( uint32, AUTOMATIC ) u32Fee_ClrID, \
    CONST( Fls_AddressType, AUTOMATIC) u32Fee_StartAddress, \
    CONST( Fls_LengthType, AUTOMATIC) u32Fee_ClusteSize, \
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_ClrHdrPtr \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"    
FEE_INLINE FUNC( uint16, FEE_CODE ) Fee_GetBlockIndex \
( \
    CONST( uint16, AUTOMATIC ) u16Fee_BlockNumber \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"


#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( uint16, FEE_CODE ) Fee_GetForeignBlockIndex \
( \
    CONST( uint16, AUTOMATIC ) u16Fee_BlockNumber \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"    
FEE_INLINE FUNC( uint16, FEE_CODE ) Fee_AlignToVirtualPageSize \
( \
    VAR( uint16, AUTOMATIC ) u16Fee_BlockSize \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"   
FEE_INLINE FUNC( void, FEE_CODE ) Fee_CopyDataToPageBuffer \
( \
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) u8Fee_SourcePtr, \
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_TargetPtr, \
    CONST( uint16, AUTOMATIC ) u16Fee_Length \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"  
FEE_INLINE FUNC( void, FEE_CODE ) Fee_SerializeFlag \
( 
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_TargetPtr, \
    CONST( uint8, AUTOMATIC ) u8Fee_FlagPattern \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"   
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVld( void );
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlock \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrFmt \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrErase( void );
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwap( void );
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrRead( void );
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrErase( void );
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClr( void );
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmt \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmtDone \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrParse \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrRead( void );
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScan \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrParse \
( \
    CONST( boolean, AUTOMATIC) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"   
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobRead \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlockVld( void );
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataRead \
( \
    CONST( boolean, AUTOMATIC) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"   
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataWrite \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"   
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVldDone \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteHdr( void );
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteData \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWrite \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteUnalignedData \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteValidate \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteDone \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlock \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlockDone \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediate \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediateDone \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobSchedule( void );
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#if( FEE_DEV_ERROR_DETECT == STD_ON )
#if(( FEE_SETMODE_API_SUPPORTED == STD_ON ) || defined(__DOXYGEN__))
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_SetModeVerify(void);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif
#endif

#if( FEE_DEV_ERROR_DETECT == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_InitVerify \
( \
    P2CONST( Fee_ConfigType, AUTOMATIC, FEE_APPL_CONST ) stFee_ConfigPtr \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

#if( FEE_DEV_ERROR_DETECT == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_ReadVerify \
( \
    VAR( uint16, AUTOMATIC ) u16Fee_BlockNumber, \
    VAR( uint16, AUTOMATIC ) u16Fee_BlockOffset, \
    P2CONST( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_DataBufferPtr, \
    VAR( uint16, AUTOMATIC ) u16Fee_Length \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

#if( FEE_DEV_ERROR_DETECT == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_WriteVerify \
( \
    VAR( uint16, AUTOMATIC ) u16Fee_BlockNumber, \
    P2CONST( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_DataBufferPtr \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

#if( FEE_DEV_ERROR_DETECT == STD_ON )
#if( FEE_CANCEL_API == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_CancelVerify( void );
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif
#endif

#if( FEE_DEV_ERROR_DETECT == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_InvalidateBlockVerify \
( \
    VAR( uint16, AUTOMATIC ) u16Fee_BlockNumber \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

#if( FEE_DEV_ERROR_DETECT == STD_ON )
#if(( FEE_VERSION_INFO_API == STD_ON ) || defined(__DOXYGEN__))
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_GetVersionInfoVerify \
( \
    P2CONST( Std_VersionInfoType, AUTOMATIC, FEE_APPL_DATA ) stFee_VersionInfoPtr \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif
#endif

#if( FEE_DEV_ERROR_DETECT == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_EraseImmediateBlockVerify \
( \
    VAR( uint16, AUTOMATIC ) u16Fee_BlockNumber \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

#if( FEE_DEV_ERROR_DETECT == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_GetRunTimeInfoVerify \
( \
    VAR( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

#if( FEE_DEV_ERROR_DETECT == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_ForceSwapOnNextWriteVerify \
( \
    VAR( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex \
);
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

#if (FEE_LEGACY_MODE == STD_OFF)
        #define FEE_START_SEC_CODE
        #include "Fee_MemMap.h"
		FEE_INLINE FUNC( boolean, FEE_CODE ) Fee_ReservedAreaWritable( void );
        #define FEE_STOP_SEC_CODE
        #include "Fee_MemMap.h"

    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        #define FEE_START_SEC_CODE
        #include "Fee_MemMap.h"
		FEE_INLINE FUNC( sint8, FEE_CODE )  Fee_ReservedAreaTargetedInClrGrp \
		( \
		    CONST( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex \
		);
        #define FEE_STOP_SEC_CODE
        #include "Fee_MemMap.h"

        #define FEE_START_SEC_CODE
        #include "Fee_MemMap.h"
        FEE_INLINE FUNC( sint8, FEE_CODE ) Fee_ReservedAreaTouchedByBlock \
        ( \
            CONST( uint16, AUTOMATIC ) u16Fee_BlockNumber \
        );
        #define FEE_STOP_SEC_CODE
        #include "Fee_MemMap.h"

        #define FEE_START_SEC_CODE
        #include "Fee_MemMap.h"
        FEE_INLINE FUNC( void, FEE_CODE ) Fee_TouchReservedAreaByBlock \
        ( \
            CONST( uint16, AUTOMATIC ) u16Fee_BlockNumber \
        );
        #define FEE_STOP_SEC_CODE
        #include "Fee_MemMap.h"

        #define FEE_START_SEC_CODE
        #include "Fee_MemMap.h"
        FEE_INLINE FUNC( void, FEE_CODE ) Fee_UntouchReservedAreaByClrGrp \
        ( \
            CONST( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex \
        );
        #define FEE_STOP_SEC_CODE
        #include "Fee_MemMap.h"
    #endif   /* FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON */
#endif  /* FEE_LEGACY_MODE == STD_OFF */

/*****************************************************************************
** Service Name      : Fee_SerializeBlockHdr                                              
** 
** 
**  Description      : Write Fee blocks into the buffer continuously.                         
**                                                                            
**  Parameters (in)  : u16Fee_BlockNumber: Fee block number      
**                     u16Fee_Length: Fee block size (in bytes)
**                     u32Fee_TargetAddress: The logical address of Fee block in Fls address space
**                     bFee_ImmediateBlock: Type of Fee block. Set to TRUE for immediate block                               
**                                                                            
**  Parameters (out) : u8Fee_BlockHdrPtr: Pointer to serialization buffer                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( void, FEE_CODE ) Fee_SerializeBlockHdr \
( \
    CONST( uint16, AUTOMATIC ) u16Fee_BlockNumber, \
    CONST( uint16, AUTOMATIC ) u16Fee_Length, \
    CONST( Fls_AddressType, AUTOMATIC) u32Fee_TargetAddress, \
    CONST( boolean, AUTOMATIC ) bFee_ImmediateBlock,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    CONST( Fee_BlockAssignmentType, AUTOMATIC ) uBlockAssignment,
#endif
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_BlockHdrPtr \
)
{
    VAR( uint32, AUTOMATIC ) u32Fee_CheckSum = 0UL;

    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u32Fee_TargetEndPtr = NULL_PTR;

    u32Fee_TargetEndPtr = u8Fee_BlockHdrPtr + FEE_BLOCK_OVERHEAD;  
    u32Fee_CheckSum = (uint32) u16Fee_BlockNumber + (uint32) u16Fee_Length + u32Fee_TargetAddress;
   
    if( bFee_ImmediateBlock == 0U)
    {
        u32Fee_CheckSum &= 0x7fffffffU;
    }
    else
    {
        u32Fee_CheckSum += 1U;
        u32Fee_CheckSum |= 0x80000000U;
    }
    FEE_SERIALIZE( u16Fee_BlockNumber, uint16, u8Fee_BlockHdrPtr )
    FEE_SERIALIZE( u16Fee_Length, uint16, u8Fee_BlockHdrPtr )
    FEE_SERIALIZE( u32Fee_TargetAddress, Fls_AddressType, u8Fee_BlockHdrPtr )
    FEE_SERIALIZE( u32Fee_CheckSum, uint32, u8Fee_BlockHdrPtr )
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    FEE_SERIALIZE( (uint8)uBlockAssignment, uint8, u8Fee_BlockHdrPtr  )
#endif

    for( ; (uint32)u8Fee_BlockHdrPtr < (uint32)u32Fee_TargetEndPtr; u8Fee_BlockHdrPtr++ ) /* PRQA S 0498 */
    {
        *u8Fee_BlockHdrPtr = FEE_ERASED_VALUE;/* polyspace RTE:IDP */
    }
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_BlankCheck                                              
** 
** 
**  Description      : Used to check whether all the specified data buffers 
**                     are FEE_ERASED_VALUE.                         
**                                                                            
**  Parameters (in)  : u8Fee_TargetPtr: Pointer to the start area of the checked buffer.      
**                     u8Fee_TargetEndPtr: Pointer to one bit after the end of 
**                                            the checked buffer.                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK: The buffer contains only FEE_ERASED_VALUE
**                                     E_NOT_OK:The buffer doesn't contain
**                                              only FEE_ERASED_VALUE                                                   
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_BlankCheck \
( \
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) u8Fee_TargetPtr, \
    CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) u8Fee_TargetEndPtr
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;
    
    for( ; (uint32)u8Fee_TargetPtr < (uint32)u8Fee_TargetEndPtr; u8Fee_TargetPtr++ )
    {
        if( FEE_ERASED_VALUE != *u8Fee_TargetPtr ) /*polyspace RTE:IDP*/
        {
            u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return( u8Fee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_DeserializeBlockHdr                                              
** 
** 
**  Description      : Parameter used to deserialize Fee block header from read buffer.                        
**                                                                            
**  Parameters (in)  : u8Fee_BlockHdrPtr: Pointer to read buffer                               
**                                                                            
**  Parameters (out) : u16Fee_BlockNumber: Fee block number      
**                     u16Fee_Length: Fee block size (in bytes)
**                     u32Fee_TargetAddress logical address of Fee block in Fls address space
**                     bFee_ImmediateBlock: Type of Fee block. Set to TRUE for immediate block                                                    
**                                                                            
**  Return value     : Fee_BlockStatus_Type: 
**                     FEE_BLOCK_VALID: Fee block is valid.
**                     FEE_BLOCK_INVALID: Fee block is invalid.
**                     FEE_BLOCK_INCONSISTENT: Fee block is inconsistent. 
**                     FEE_BLOCK_HEADER_INVALID: Fee block header is invalid.
**                     FEE_BLOCK_INVALIDATED: The Fee_InvaliDateBlock (blocknumber) 
**                                            invalidates the fee block header. 
**                     FEE_BLOCK_HEADER_BLANK: The Fee block header is FEE_ERASED_VALUE.                                                 
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Fee_BlockStatus_Type, FEE_CODE ) Fee_DeserializeBlockHdr \
( \
    CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) u16Fee_BlockNumber, \
    CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) u16Fee_Length, \
    CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) u32Fee_TargetAddress, \
    P2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) bFee_ImmediateBlock,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    CONSTP2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_BlockAssignment,
#endif
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) u8Fee_BlockHdrPtr
)
{
    VAR( Fee_BlockStatus_Type, AUTOMATIC ) eFee_RetVal = FEE_BLOCK_HEADER_INVALID;
    
    if( Fee_BlankCheck( u8Fee_BlockHdrPtr, u8Fee_BlockHdrPtr + FEE_BLOCK_OVERHEAD ) \
        != (Std_ReturnType)E_OK )
    {
        VAR( uint32, AUTOMATIC ) u32Fee_ReadCheckSum = 0UL;
        VAR( uint32, AUTOMATIC ) u32Fee_CalcCheckSum = 0UL;
        P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) u8Fee_TargetEndPtr = NULL_PTR; 
        VAR( boolean, AUTOMATIC ) bFee_FlagValid = (boolean)FALSE;
        VAR( boolean, AUTOMATIC ) bFee_FlagInvalid = (boolean)FALSE;  
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_OFF)
        VAR( uint8, AUTOMATIC ) u8Fee_ReservedSpace = 0U;
#endif

        u8Fee_TargetEndPtr = ( u8Fee_BlockHdrPtr + FEE_BLOCK_OVERHEAD ) - \
                                ( 2U * FEE_VIRTUAL_PAGE_SIZE );
        FEE_DESERIALIZE( u8Fee_BlockHdrPtr, *u16Fee_BlockNumber, uint16 )
        FEE_DESERIALIZE( u8Fee_BlockHdrPtr, *u16Fee_Length, uint16 )
        FEE_DESERIALIZE( u8Fee_BlockHdrPtr, *u32Fee_TargetAddress, Fls_AddressType )
        FEE_DESERIALIZE( u8Fee_BlockHdrPtr, u32Fee_ReadCheckSum, uint32 )
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        FEE_DESERIALIZE( u8Fee_BlockHdrPtr, *u8Fee_BlockAssignment, uint8 )
#else
        FEE_DESERIALIZE( u8Fee_BlockHdrPtr, u8Fee_ReservedSpace, uint8) /* PRQA S 0489 */
        (void)u8Fee_ReservedSpace;
#endif
          
        u32Fee_CalcCheckSum = *u16Fee_Length + *u32Fee_TargetAddress + *u16Fee_BlockNumber;

        if( 0U != (u32Fee_ReadCheckSum & 0x80000000U)  )
        {
            *bFee_ImmediateBlock = (boolean) TRUE;
            u32Fee_CalcCheckSum += 1U;
        }
        else
        {
            *bFee_ImmediateBlock = (boolean) FALSE;
        }

        if( (u32Fee_ReadCheckSum & 0x7fffffffU) != (u32Fee_CalcCheckSum & 0x7fffffffU) )
        {

        }
        else if( Fee_BlankCheck( u8Fee_BlockHdrPtr, u8Fee_TargetEndPtr ) != \
            (Std_ReturnType)E_OK )
        {
            
        }
        else if( Fee_DeserializeFlag( u8Fee_TargetEndPtr, FEE_VALIDATED_VALUE, &bFee_FlagValid ) \
            != (Std_ReturnType)E_OK )
        {
            
        }
        else if( Fee_DeserializeFlag( u8Fee_TargetEndPtr + FEE_VIRTUAL_PAGE_SIZE, FEE_INVALIDATED_VALUE, \
            &bFee_FlagInvalid ) != (Std_ReturnType)E_OK )
        {
            
        }
        else 
        {
            if( bFee_FlagValid == (boolean)FALSE )
            {
                if( bFee_FlagInvalid == (boolean)FALSE )
                {
                    eFee_RetVal = FEE_BLOCK_INCONSISTENT;
                }
                else
                {
                    eFee_RetVal = FEE_BLOCK_INVALID;
                }
            }
            else
            {
                if( bFee_FlagInvalid == (boolean)FALSE )
                {
                    eFee_RetVal = FEE_BLOCK_VALID;
                }
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)  
                else
                {
                    eFee_RetVal = FEE_BLOCK_INVALIDATED;
                }
#endif
            }
        }
    }
    else
    {
        eFee_RetVal = FEE_BLOCK_HEADER_BLANK;
    }

    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_DeserializeFlag                                              
** 
** 
**  Description      : Used to deserialize valid or invalid flags from the read buffer.                        
**                                                                            
**  Parameters (in)  : u8Fee_TargetPtr: Pointer to the read buffer.      
**                     u8Fee_FlagPattern: FEE_VALIDATED_VALUE or FEE_INVALIDATED_VALUE
**                                                                            
**  Parameters (out) : bFee_FlagValue: The value is True if the above flag is set.                                                    
**                                                                            
**  Return value     : Std_ReturnType: E_OK: The flag is set or cleared, and the rest
**                                     of the read buffers are all FEE_ERASED_VALUE.
**                                     E_NOT_OK: The buffer does not contain valid flag data.                                                  
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_DeserializeFlag \
( \
    CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) u8Fee_TargetPtr, \
    VAR( uint8, AUTOMATIC ) u8Fee_FlagPattern, \
    P2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) bFee_FlagValue \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;

    if(( *u8Fee_TargetPtr == u8Fee_FlagPattern ) || ( FEE_ERASED_VALUE == *u8Fee_TargetPtr ))
    {
        if( *u8Fee_TargetPtr != u8Fee_FlagPattern )
        {
            *bFee_FlagValue = (boolean) FALSE;
        }
        else
        {
            *bFee_FlagValue = (boolean) TRUE;
        }
        
        u8Fee_RetVal = Fee_BlankCheck(u8Fee_TargetPtr + 1, u8Fee_TargetPtr + FEE_VIRTUAL_PAGE_SIZE ); /* PRQA S 0489 */
    }
    else
    {
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    
    return( u8Fee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_DeserializeClusterHdr                                              
** 
** 
**  Description      : Used to deserialize Fee cluster header parameter from read buffer.                        
**                                                                            
**  Parameters (in)  : u8Fee_ClrHdrPtr: Pointer to the read buffer.                                
**                                                                            
**  Parameters (out) : u32Fee_ClrID: Cluster ID     
**                     u32Fee_StartAddress: The logical address of Fee cluster in Fls address space
**                     u32Fee_ClusteSize: The size of the Fee cluster (in bytes)                                                    
**                                                                            
**  Return value     : Fee_ClusterStatus_Type: 
**                     FEE_CLUSTER_VALID: The Fee cluster is valid.
**                     FEE_CLUSTER_INVALID: The Fee cluster is invalid.
**                     FEE_CLUSTER_INCONSISTENT: The Fee cluster is inconsistent. 
**                     FEE_CLUSTER_HEADER_INVALID: The Fee cluster header is invalid.                                                 
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Fee_ClusterStatus_Type, FEE_CODE ) Fee_DeserializeClusterHdr \
( \
    CONSTP2VAR( uint32, AUTOMATIC, FEE_APPL_DATA ) u32Fee_ClrID, \
    CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) u32Fee_StartAddress, \
    CONSTP2VAR( Fls_LengthType, AUTOMATIC, FEE_APPL_DATA ) u32Fee_ClusteSize, \
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) u8Fee_ClrHdrPtr \
)
{
    VAR( Fee_ClusterStatus_Type, AUTOMATIC ) eFee_RetVal = FEE_CLUSTER_HEADER_INVALID;
    VAR( uint32, AUTOMATIC ) u32Fee_CheckSum = 0UL;
    VAR( boolean, AUTOMATIC ) bFee_FlagValid = (boolean)FALSE;
    VAR( boolean, AUTOMATIC ) bFee_FlagInvalid = (boolean)FALSE;
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) u8Fee_TargetEndPtr = NULL_PTR; 

    u8Fee_TargetEndPtr = ( u8Fee_ClrHdrPtr + FEE_CLUSTER_OVERHEAD ) - \
        ( 2U * FEE_VIRTUAL_PAGE_SIZE );
    
    FEE_DESERIALIZE( u8Fee_ClrHdrPtr, *u32Fee_ClrID, uint32 )
    FEE_DESERIALIZE( u8Fee_ClrHdrPtr, *u32Fee_StartAddress, Fls_AddressType )
    FEE_DESERIALIZE( u8Fee_ClrHdrPtr, *u32Fee_ClusteSize, Fls_LengthType )
    FEE_DESERIALIZE( u8Fee_ClrHdrPtr, u32Fee_CheckSum, uint32 )

    if( (*u32Fee_ClrID + *u32Fee_StartAddress + *u32Fee_ClusteSize) != u32Fee_CheckSum )
    {

    }
    else if( Fee_BlankCheck( u8Fee_ClrHdrPtr, u8Fee_TargetEndPtr ) != \
        (Std_ReturnType)E_OK )
    {
        
    }
    else if( Fee_DeserializeFlag( u8Fee_TargetEndPtr, FEE_VALIDATED_VALUE, &bFee_FlagValid ) \
        != (Std_ReturnType)E_OK )
    {
        
    }
    else if( Fee_DeserializeFlag( u8Fee_TargetEndPtr + FEE_VIRTUAL_PAGE_SIZE, FEE_INVALIDATED_VALUE, \
        &bFee_FlagInvalid ) != (Std_ReturnType)E_OK )
    {
        
    }
    else 
    {
        if( bFee_FlagInvalid == (boolean)FALSE )
        {
            if( bFee_FlagValid == (boolean)FALSE)
            {
                eFee_RetVal = FEE_CLUSTER_INCONSISTENT;
            }
            else
            {
                eFee_RetVal = FEE_CLUSTER_VALID;
            }
        }
        else
        {
            eFee_RetVal = FEE_CLUSTER_INVALID;
        }
    }

    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_SerializeClusterHdr                                              
** 
** 
**  Description      : Used to serialize the Fee cluster header parameters
**                     to write to the buffer.                        
**                                                                            
**  Parameters (in)  : u32Fee_ClrID: Cluster ID     
**                     u32Fee_StartAddress: The logical address of Fee cluster in Fls address space
**                     ClusteSize: The size of the Fee cluster (in bytes) 
**                                                                            
**  Parameters (out) : u8Fee_ClrHdrPtr: Pointer to the write buffer.                                                                                   
**                                                                            
**  Return value     : None                                              
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( void, FEE_CODE ) Fee_SerializeClusterHdr \
( \
    CONST( uint32, AUTOMATIC ) u32Fee_ClrID, \
    CONST( Fls_AddressType, AUTOMATIC) u32Fee_StartAddress, \
    CONST( Fls_LengthType, AUTOMATIC) u32Fee_ClusteSize, \
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_ClrHdrPtr \
)
{
    VAR( uint32, AUTOMATIC ) U32Fee_CheckSum = 0UL;

    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_TargetEndPtr = NULL_PTR; 

    u8Fee_TargetEndPtr = u8Fee_ClrHdrPtr + FEE_CLUSTER_OVERHEAD;

    U32Fee_CheckSum = u32Fee_ClrID + u32Fee_StartAddress + u32Fee_ClusteSize;
    FEE_SERIALIZE( u32Fee_ClrID, uint32, u8Fee_ClrHdrPtr )
    FEE_SERIALIZE( u32Fee_StartAddress, Fls_AddressType, u8Fee_ClrHdrPtr )
    FEE_SERIALIZE( u32Fee_ClusteSize, Fls_LengthType, u8Fee_ClrHdrPtr )
    FEE_SERIALIZE( U32Fee_CheckSum, uint32, u8Fee_ClrHdrPtr )

   

    while ( (uint32_t)u8Fee_ClrHdrPtr < (uint32_t)u8Fee_TargetEndPtr)
    {
        *u8Fee_ClrHdrPtr = FEE_ERASED_VALUE;/* polyspace RTE:IDP */
        u8Fee_ClrHdrPtr++; /* PRQA S 0498 */
    }    
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_GetBlockIndex                                              
** 
** 
**  Description      : Used to search the ordered list of Fee blocks and return 
**                     the index of blocks with matching block numbers.                        
**                                                                            
**  Parameters (in)  : u16Fee_BlockNumber: Fee block number      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : uint16: Fee block index                                              
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( uint16, FEE_CODE ) Fee_GetBlockIndex \
( \
    CONST( uint16, AUTOMATIC ) u16Fee_BlockNumber \
)
{
    VAR( sint32, AUTOMATIC ) s32Fee_Low = 0L;
    VAR( sint32, AUTOMATIC ) s32Fee_High = (sint32)(FEE_NUMBER_OF_BLOCKS - 1U);
    VAR( sint32, AUTOMATIC ) s32Fee_Middle = 0L;
    VAR( uint16, AUTOMATIC ) u16Fee_RetVal = 0xFFFFU;


    while( s32Fee_Low <= s32Fee_High )
    { 
        s32Fee_Middle = s32Fee_Low + (( s32Fee_High - s32Fee_Low ) / 2);
			
        if( u16Fee_BlockNumber > \
            gFee_ConfigPtr->Fee_BlockConfig[s32Fee_Middle].u16Fee_BlockNumber ) /*polyspace RTE:IDP*/
        {
        	s32Fee_Low = s32Fee_Middle + 1;
        }
        else if( u16Fee_BlockNumber < \
            gFee_ConfigPtr->Fee_BlockConfig[s32Fee_Middle].u16Fee_BlockNumber ) /*polyspace RTE:IDP*/ 
        {
            s32Fee_High = s32Fee_Middle - 1;
        }
        else
        {
            u16Fee_RetVal = (uint16)s32Fee_Middle;
            break;
        }
    }
    
    return( u16Fee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_GetBlockClusterGrp                                              
** 
** 
**  Description      : Returns the cluster group for a block specified by its index 
                       in the gFee_BlockInfo array                      
**                                                                            
**  Parameters (in)  : uBlockIndex: index in the gFee_BlockInfo array
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : uint8:  cluster group number                                                 
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( uint8, FEE_CODE ) Fee_GetBlockClusterGrp \
( \
    CONST( uint16, AUTOMATIC ) u16Fee_BlockIndex \
)
{
    VAR( uint8, AUTOMATIC ) u8Fee_ClrGrp = 0U;

    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (u16Fee_BlockIndex < FEE_NUMBER_OF_BLOCKS)
    {
        u8Fee_ClrGrp = \
            gFee_ConfigPtr->Fee_BlockConfig[u16Fee_BlockIndex].u8Fee_ClrGrp;
    }
    else
    {
        u8Fee_ClrGrp = \
            Fee_ForeignBlockConfig[u16Fee_BlockIndex - FEE_NUMBER_OF_BLOCKS].u8Fee_ClrGrp;
    }
    #else
        u8Fee_ClrGrp = \
            gFee_ConfigPtr->Fee_BlockConfig[u16Fee_BlockIndex].u8Fee_ClrGrp; /*polyspace RTE:IDP*/
    #endif

    return u8Fee_ClrGrp;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_GetBlockSize                                              
** 
** 
**  Description      : Returns the block size for a block specified by its index in the gFee_BlockInfo array                      
**                                                                            
**  Parameters (in)  : u16Fee_BlockRuntimeInfoIndex: index in the gFee_BlockInfo array
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : uint8:  block size                                                 
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( uint16, FEE_CODE ) Fee_GetBlockSize \
( \
    CONST( uint16, AUTOMATIC ) u16Fee_BlockRuntimeInfoIndex \
)
{
    VAR( uint16, AUTOMATIC ) u16Fee_BlockSize = 0U;

    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (u16Fee_BlockRuntimeInfoIndex < FEE_NUMBER_OF_BLOCKS)
    {
        u16Fee_BlockSize = \
            gFee_ConfigPtr->Fee_BlockConfig[u16Fee_BlockRuntimeInfoIndex].u16Fee_BlockSize;
    }
    else
    {
        u16Fee_BlockSize = \
            Fee_ForeignBlockConfig[u16Fee_BlockRuntimeInfoIndex - FEE_NUMBER_OF_BLOCKS].u16Fee_BlockSize;
    }
    #else
        u16Fee_BlockSize = \
            gFee_ConfigPtr->Fee_BlockConfig[u16Fee_BlockRuntimeInfoIndex].u16Fee_BlockSize; /*polyspace RTE:IDP*/
    #endif

    return u16Fee_BlockSize;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
/*****************************************************************************
** Service Name      : Fee_GetForeignBlockIndex                                              
** 
** 
**  Description      : Searches ordered list of Fee blocks and returns index of block with matching BlockNumber                
**                                                                            
**  Parameters (in)  : u16Fee_BlockNumber: Fee block number
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : uint8:  Fee block index                                                 
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( uint16, FEE_CODE ) Fee_GetForeignBlockIndex \
( \
    CONST( uint16, AUTOMATIC ) u16Fee_BlockNumber \
)
{
    VAR( uint16, AUTOMATIC ) u16Fee_ForeignBlockIt = 0U;
    VAR( uint16, AUTOMATIC ) u16Fee_RetVal = 0xFFFFU;
    
    if (u16Fee_ForeignBlocksNumber >= 1UL)
    {
        for(u16Fee_ForeignBlockIt = 0U; u16Fee_ForeignBlockIt < u16Fee_ForeignBlocksNumber; u16Fee_ForeignBlockIt++)
        {
            if(u16Fee_BlockNumber == Fee_ForeignBlockConfig[u16Fee_ForeignBlockIt].u16Fee_BlockNumber)
            {
                u16Fee_RetVal = u16Fee_ForeignBlockIt;
                break;
            }
        }
    }
    
    return( u16Fee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) && (FEE_LEGACY_MODE == STD_OFF)
/*****************************************************************************
** Service Name      : Fee_ReservedAreaTouchedByBlock                                              
** 
** 
**  Description      : eturns the information about touching the Reserved Area by the block
*                      specified by u16Fee_BlockNumber.                
**                                                                            
**  Parameters (in)  : u16Fee_BlockNumber: index in the gFee_BlockInfo array
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : sint8:  TRUE   the Reserved Area is touched by the block
*                              FALSE  the Reserved Area is not touched by the block                                               
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( sint8, FEE_CODE ) Fee_ReservedAreaTouchedByBlock \
( \
    CONST( uint16, AUTOMATIC ) u16Fee_BlockNumber \
)
{
    VAR( uint32, AUTOMATIC ) u32Fee_Idx = 0UL;
    VAR( sint8, AUTOMATIC ) s8Fee_RetVal;

    u32Fee_Idx = ((uint32)u16Fee_BlockNumber) >> 5U;

    if( 0U != (Fee_aReservedAreaTouched[ u32Fee_Idx ] & \
    ((0x00000001UL << (u16Fee_BlockNumber & 0x1FUL)))))
    {
        s8Fee_RetVal = (sint8)TRUE;
    }
    else
    {
        s8Fee_RetVal = (sint8)FALSE;
    }

    return s8Fee_RetVal;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif /* (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) && (FEE_LEGACY_MODE == STD_OFF) */

/*****************************************************************************
** Service Name      : Fee_GetBlockImmediate                                              
** 
** 
**  Description      : Returns the immediate attribute for a block specified by its index in the gFee_BlockInfo array                      
**                                                                            
**  Parameters (in)  : u16Fee_BlockRuntimeInfoIndex: index in the gFee_BlockInfo array
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : sint8:  TRUE   the Reserved Area is touched by the block
*                              FALSE  the Reserved Area is not touched by the block                                               
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( boolean, FEE_CODE ) Fee_GetBlockImmediate \
( \
    CONST( uint16, AUTOMATIC ) u16Fee_BlockRuntimeInfoIndex \
)
{
    VAR( boolean, AUTOMATIC ) bFee_Immediate = (boolean)FALSE;

    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (u16Fee_BlockRuntimeInfoIndex < FEE_NUMBER_OF_BLOCKS)
    {
        bFee_Immediate = \
            gFee_ConfigPtr->Fee_BlockConfig[u16Fee_BlockRuntimeInfoIndex].bFee_ImmediateData;
    }
    else
    {
        bFee_Immediate = \
            Fee_ForeignBlockConfig[u16Fee_BlockRuntimeInfoIndex - FEE_NUMBER_OF_BLOCKS].bFee_ImmediateData;
    }
    #else
        bFee_Immediate = \
            gFee_ConfigPtr->Fee_BlockConfig[u16Fee_BlockRuntimeInfoIndex].bFee_ImmediateData;
    #endif

    return bFee_Immediate;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) && (FEE_LEGACY_MODE == STD_OFF)
/*****************************************************************************
** Service Name      : Fee_UntouchReservedAreaByClrGrp                                              
** 
** 
**  Description      : Removes the information about touching the Reserved Area for all blocks
*                      within a cluster group specified by u8Fee_ClrGrpIndex.              
**                                                                            
**  Parameters (in)  : u8Fee_ClrGrpIndex - see above
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : void                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( void, FEE_CODE ) Fee_UntouchReservedAreaByClrGrp \
( \
    CONST( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex \
)
{
    VAR( uint32, AUTOMATIC ) u32Fee_BlockIt = 0UL;
    VAR( uint32, AUTOMATIC ) u32Fee_Idx = 0UL;
    VAR( uint32, AUTOMATIC ) u32Fee_Mask = 0x00000001UL;
    VAR( uint8, AUTOMATIC ) u8Fee_BlockClusterGrp = 0U;
    
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
   for( u32Fee_BlockIt = 0U; u32Fee_BlockIt < \
    ((uint32)FEE_NUMBER_OF_BLOCKS + (uint32)u16Fee_ForeignBlocksNumber); u32Fee_BlockIt++ )
#else
   for( u32Fee_BlockIt = 0U; u32Fee_BlockIt < FEE_NUMBER_OF_BLOCKS; u32Fee_BlockIt++ )
#endif
    {
        u8Fee_BlockClusterGrp = Fee_GetBlockClusterGrp((uint16)u32Fee_BlockIt);
        
       if(u8Fee_ClrGrpIndex == u8Fee_BlockClusterGrp)
       {
           Fee_aReservedAreaTouched[u32Fee_Idx] &= (~u32Fee_Mask);
       }
       if (0x80000000UL == u32Fee_Mask)
       {
           u32Fee_Mask = 0x00000001UL;
           u32Fee_Idx++;
       }
       else
       {
           u32Fee_Mask = u32Fee_Mask << 1U;
       }
    }
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_ReservedAreaTargetedInClrGrp                                              
** 
** 
**  Description      : Checks whether the area specified by gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_DataAddrIt
*                      and gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_HdrAddrIt touches the Reserved Area.              
**                                                                            
**  Parameters (in)  : u8Fee_ClrGrpIndex - Cluster Group Index
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : sint8                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( sint8, FEE_CODE )  Fee_ReservedAreaTargetedInClrGrp \
( \
    CONST( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex \
)
{
    VAR( sint8, AUTOMATIC ) s8Fee_RetVal = FALSE;
    VAR( Fls_LengthType, AUTOMATIC ) u32Fee_AvailClrSpace = 0UL;
    VAR( uint32, AUTOMATIC ) u32Fee_ReservedSpace = 0UL;

    u32Fee_ReservedSpace = \
        gFee_ConfigPtr->Fee_ClusterGroup[ u8Fee_ClrGrpIndex ].Fee_reservedSize;

    u32Fee_AvailClrSpace = gFee_ClrGrpInfo[ u8Fee_ClrGrpIndex ].Fee_DataAddrIt - \
        gFee_ClrGrpInfo[ u8Fee_ClrGrpIndex ].Fee_HdrAddrIt;

    if( (FEE_BLOCK_OVERHEAD  + u32Fee_ReservedSpace) > u32Fee_AvailClrSpace )
    {
        s8Fee_RetVal = (sint8)TRUE;
    }

    return s8Fee_RetVal;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_TouchReservedAreaByBlock                                              
** 
** 
**  Description      : Stores the information about touching the Reserved Area for the block
*                      specified by u16Fee_BlockNumber.            
**                                                                            
**  Parameters (in)  : u16Fee_BlockNumber - number of the block touching the Reserved Area
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : void                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( void, FEE_CODE ) Fee_TouchReservedAreaByBlock \
( \
    CONST( uint16, AUTOMATIC ) u16Fee_BlockNumber \
)
{
     VAR( uint32, AUTOMATIC ) u32Fee_Idx = 0UL;

     u32Fee_Idx = ((uint32)u16Fee_BlockNumber) >> 5U;

     Fee_aReservedAreaTouched[ u32Fee_Idx ] |= \
        ((0x00000001UL << (u16Fee_BlockNumber & 0x1FUL)));
}  
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"     
#endif /* (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) && (FEE_LEGACY_MODE == STD_OFF) */

/*****************************************************************************
** Service Name      : Fee_AlignToVirtualPageSize                                              
** 
** 
**  Description      : Used to adjust the size of delivery to be an integer 
**                     multiple of preconfigured+FEE_VIRTUAL_PAGE_SIZE.                        
**                                                                            
**  Parameters (in)  : u16Fee_BlockSize: Fee block size      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : uint16: Fee block size (integer multiple of FEE_VIRTUAL_PAGE_SIZE)                                              
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( uint16, FEE_CODE ) Fee_AlignToVirtualPageSize \
( \
    VAR( uint16, AUTOMATIC ) u16Fee_BlockSize \
)
{
    if( 0U != ( u16Fee_BlockSize % FEE_VIRTUAL_PAGE_SIZE ) )
    {
        u16Fee_BlockSize = (uint16)((( u16Fee_BlockSize / FEE_VIRTUAL_PAGE_SIZE ) + 1U ) \
            * FEE_VIRTUAL_PAGE_SIZE);
    }

    return( (uint16)u16Fee_BlockSize );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_CopyDataToPageBuffer                                              
** 
** 
**  Description      : Used to copy data from the user to the internal write buffer
**                     and fill the rest of the write buffer with FEE_ERASED_VALUE.                        
**                                                                            
**  Parameters (in)  : u8Fee_SourcePtr: Pointer to the user data buffer. 
**                     u16Fee_Length: Number of bytes required for replication.     
**                                                                            
**  Parameters (out) : u8Fee_TargetPtr: Pointer to internal write buffer.                                                                                   
**                                                                            
**  Return value     : None                                              
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( void, FEE_CODE ) Fee_CopyDataToPageBuffer \
( \
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) u8Fee_SourcePtr, \
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_TargetPtr, \
    CONST( uint16, AUTOMATIC ) u16Fee_Length \
)
{

    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_TargetEndPtr = NULL_PTR;
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_PageEndPtr = NULL_PTR;

    u8Fee_TargetEndPtr = u8Fee_TargetPtr + u16Fee_Length;
    u8Fee_PageEndPtr = u8Fee_TargetPtr + FEE_VIRTUAL_PAGE_SIZE;

    while ((uint32_t)u8Fee_TargetPtr < (uint32_t)u8Fee_TargetEndPtr)
    {
        *u8Fee_TargetPtr = *u8Fee_SourcePtr; /*polyspace RTE:IDP*/
        u8Fee_SourcePtr++;
        u8Fee_TargetPtr++;
    }
   
    while ( (uint32_t)u8Fee_TargetPtr < (uint32_t)u8Fee_PageEndPtr)
    {
        *u8Fee_TargetPtr = FEE_ERASED_VALUE;/* polyspace RTE:IDP */
        u8Fee_TargetPtr++;
    }   
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_SerializeFlag                                              
** 
** 
**  Description      : Used to serialize validation or invalidation flags 
**                     into the write buffer.                        
**                                                                            
**  Parameters (in)  : u8Fee_FlagPattern: FEE_VALIDATED_VALUE or FEE_INVALIDATED_VALUE     
**                                                                            
**  Parameters (out) : u8Fee_TargetPtr: Pointer to write buffer.                                                                                   
**                                                                            
**  Return value     : None                                              
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( void, FEE_CODE ) Fee_SerializeFlag \
( \
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_TargetPtr, \
    CONST( uint8, AUTOMATIC ) u8Fee_FlagPattern \
)
{
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_TargetEndPtr = NULL_PTR;

    u8Fee_TargetEndPtr = u8Fee_TargetPtr + FEE_VIRTUAL_PAGE_SIZE;

    *u8Fee_TargetPtr = u8Fee_FlagPattern;
    u8Fee_TargetPtr++; /* PRQA S 0498 */
 

    while ((uint32_t)u8Fee_TargetPtr < (uint32_t)u8Fee_TargetEndPtr )
    {
        *u8Fee_TargetPtr = FEE_ERASED_VALUE;/* polyspace RTE:IDP */
        u8Fee_TargetPtr++; /* PRQA S 0498 */

    }
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntSwapClrVld                                              
** 
** 
**  Description      : Used to verify the current expense group in the current 
**                     expense group (by writing FEE_VALIDATED_VALUE into 
**                     flash memory).                        
**                                                                            
**  Parameters (in)  : None     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the write job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the write job.                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVld( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_StartAddr = 0UL;
    P2CONST( Fee_ClusterGroup_Type, FEE_CONST, FEE_APPL_CONST ) pFee_Group = \
    gFee_ConfigPtr->Fee_ClusterGroup;  /*polyspace RTE:IDP*/

    u32Fee_StartAddr = \
        pFee_Group[gFee_JobIntClrGrpIt].Fee_ClrPtr[gFee_JobIntClrIt].Fee_StartAddr;
    
    Fee_SerializeFlag( gFee_DataBuffer, FEE_VALIDATED_VALUE );
    if( Fls_Write(( u32Fee_StartAddr + FEE_CLUSTER_OVERHEAD ) - \
        ( 2U * FEE_VIRTUAL_PAGE_SIZE ), gFee_DataBuffer, FEE_VIRTUAL_PAGE_SIZE ) != \
        (Std_ReturnType)E_OK )
    {
        eFee_RetVal = MEMIF_JOB_FAILED;    
    }
    else
    {
        eFee_RetVal = MEMIF_JOB_PENDING;
    }

    Fee_JobConfig.Fee_Job = FEE_JOB_INT_SWAP_CLR_VLD_DONE;
    
    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntSwapBlock                                              
** 
** 
**  Description      : Used to copy the next data block from the source 
**                     cluster to the target cluster.                       
**                                                                            
**  Parameters (in)  : None     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the write job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the write job.                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlock \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    (void)bFee_Valid;
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    VAR( Fee_BlockAssignmentType, AUTOMATIC ) uFee_BlockAssignment = FEE_PROJECT_RESERVED;
#endif

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    for( ; u16Fee_JobIntBlockIt < (FEE_NUMBER_OF_BLOCKS + u16Fee_ForeignBlocksNumber); u16Fee_JobIntBlockIt++ )
#else
    for( ; u16Fee_JobIntBlockIt < FEE_NUMBER_OF_BLOCKS; u16Fee_JobIntBlockIt++ )
#endif
    {
        if(( gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobIntBlockIt].u8Fee_ClrGrp == /*polyspace RTE:IDP*/
            gFee_JobIntClrGrpIt ) && ( ( FEE_BLOCK_VALID ==  \
            gFee_BlockInfo[u16Fee_JobIntBlockIt].Fee_BlockStatus ) || \
           ( FEE_BLOCK_INCONSISTENT == gFee_BlockInfo[u16Fee_JobIntBlockIt].Fee_BlockStatus )))
        {
            break;
        }
        else
        {
            
        }
    }

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if((FEE_NUMBER_OF_BLOCKS + u16Fee_ForeignBlocksNumber) != u16Fee_JobIntBlockIt)
#else
    if( FEE_NUMBER_OF_BLOCKS != u16Fee_JobIntBlockIt )
#endif
    {
        VAR( Fls_AddressType, AUTOMATIC ) u32Fee_DataAddr = 0UL;
        VAR( uint16, AUTOMATIC ) u16Fee_BlockSize = 0U;
        VAR( uint16, AUTOMATIC ) u16Fee_AlignedBlockSize = 0U;

        if (u16Fee_JobIntBlockIt >= FEE_NUMBER_OF_BLOCKS )
        {
            #if (FEE_DEV_ERROR_DETECT == STD_ON)
                Fee_ReportError( FEE_INVALIDATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
            #endif
            eFee_RetVal = MEMIF_JOB_FAILED; 
            FEE_NVM_JOB_ERROR_NOTIFICATION
            return( eFee_RetVal );
        }
        else
        {

        }	
        u16Fee_BlockSize = Fee_GetBlockSize(u16Fee_JobIntBlockIt);
    #if (FEE_LEGACY_MODE == STD_OFF)
        if( FEE_BLOCK_VALID == gFee_BlockInfo[u16Fee_JobIntBlockIt].Fee_BlockStatus )
    #else
        if( (FEE_BLOCK_VALID == gFee_BlockInfo[u16Fee_JobIntBlockIt].Fee_BlockStatus) ||
            ((boolean)TRUE == \
                gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobIntBlockIt].bFee_ImmediateData) \
          )
    #endif
        {
            u16Fee_AlignedBlockSize = Fee_AlignToVirtualPageSize( u16Fee_BlockSize );
            u32Fee_DataAddr = u32Fee_JobIntDataAddr - u16Fee_AlignedBlockSize;
            u32Fee_JobIntDataAddr = u32Fee_DataAddr;
            u32Fee_JobIntAddrIt = u32Fee_DataAddr;
        }
        else
        {
            u32Fee_DataAddr = 0U;
        }

        Fee_SerializeBlockHdr( gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobIntBlockIt].u16Fee_BlockNumber, \
                               u16Fee_BlockSize, u32Fee_DataAddr, \
                               gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobIntBlockIt].bFee_ImmediateData,
                               #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
                               uFee_BlockAssignment,
                               #endif
                               gFee_DataBuffer );
        
        if( FEE_BLOCK_VALID != gFee_BlockInfo[u16Fee_JobIntBlockIt].Fee_BlockStatus ) /* PRQA S 2843 */
        {
            u16Fee_JobIntBlockIt++;
            Fee_JobConfig.Fee_Job = FEE_JOB_INT_SWAP_BLOCK;
        }
        else
        {
            Fee_JobConfig.Fee_Job = FEE_JOB_INT_SWAP_DATA_READ;
        }
        
        if( Fls_Write( u32Fee_JobIntHdrAddr, gFee_DataBuffer, FEE_BLOCK_OVERHEAD - \
        ( 2U * FEE_VIRTUAL_PAGE_SIZE )) == (Std_ReturnType)E_OK )
        {
            eFee_RetVal = MEMIF_JOB_PENDING;
        }
        else
        {
            eFee_RetVal = MEMIF_JOB_FAILED;
        }
        
        u32Fee_JobIntHdrAddr += FEE_BLOCK_OVERHEAD;
    }
    else
    {
        eFee_RetVal = Fee_JobIntSwapClrVld();
    }
    
    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntSwapClrFmt                                              
** 
** 
**  Description      : Used to format the current Fee cluster in the current 
**                     Fee cluster group (by writing the Fee cluster header 
**                     into flash memory).                       
**                                                                            
**  Parameters (in)  : None     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the write job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the write job.                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrFmt \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    (void)bFee_Valid;
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_StartAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) u32Fee_Length = 0UL;
    VAR( uint32, AUTOMATIC ) u32Fee_ActClrID = 0UL;
    VAR( uint32, AUTOMATIC ) u32Fee_GrpIt = gFee_JobIntClrGrpIt;
    VAR( uint32, AUTOMATIC ) u32Fee_ClrIt = gFee_JobIntClrIt;
    P2CONST( Fee_ClusterGroup_Type, FEE_CONST, FEE_APPL_CONST ) pFee_Group = \
    gFee_ConfigPtr->Fee_ClusterGroup;  /*polyspace RTE:IDP*/
    
    if( u32Fee_GrpIt >= FEE_NUMBER_OF_CLUSTER_GROUPS)
    {
        eFee_RetVal = MEMIF_JOB_FAILED;
        return( eFee_RetVal );
    }
    else
    {
        
    }
    u32Fee_StartAddr = pFee_Group[u32Fee_GrpIt].Fee_ClrPtr[u32Fee_ClrIt].Fee_StartAddr;
    u32Fee_Length = pFee_Group[u32Fee_GrpIt].Fee_ClrPtr[u32Fee_ClrIt].Fee_Length;
    u32Fee_ActClrID = gFee_ClrGrpInfo[u32Fee_GrpIt].Fee_ActClrID;
    
    Fee_SerializeClusterHdr( u32Fee_ActClrID + 1U, u32Fee_StartAddr, u32Fee_Length, 
        gFee_DataBuffer );
    if( Fls_Write( u32Fee_StartAddr, gFee_DataBuffer, FEE_CLUSTER_OVERHEAD - \
        ( 2U * FEE_VIRTUAL_PAGE_SIZE )) != (Std_ReturnType)E_OK )
    {
        eFee_RetVal = MEMIF_JOB_FAILED;
    }
    else
    {
        eFee_RetVal = MEMIF_JOB_PENDING;
    }    

    Fee_JobConfig.Fee_Job = FEE_JOB_INT_SWAP_BLOCK;

    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntSwapClrErase                                              
** 
** 
**  Description      : Erase current Fee cluster in current Fee cluster group by erasing flash                       
**                                                                            
**  Parameters (in)  : None     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the write job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the write job.                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrErase( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_StartAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) u32Fee_Length = 0UL;
    VAR( uint32, AUTOMATIC ) u32Fee_GrpIt = gFee_JobIntClrGrpIt;
    VAR( uint32, AUTOMATIC ) u32Fee_ClrIt = gFee_JobIntClrIt;
    P2CONST( Fee_ClusterGroup_Type, FEE_CONST, FEE_APPL_CONST ) pFee_Group = \
    gFee_ConfigPtr->Fee_ClusterGroup;

    u32Fee_StartAddr = pFee_Group[u32Fee_GrpIt].Fee_ClrPtr[u32Fee_ClrIt].Fee_StartAddr;
    u32Fee_Length = pFee_Group[u32Fee_GrpIt].Fee_ClrPtr[u32Fee_ClrIt].Fee_Length;
    
    if( Fls_Erase( u32Fee_StartAddr, u32Fee_Length ) != (Std_ReturnType)E_OK )
    {
        eFee_RetVal = MEMIF_JOB_FAILED;   
    } 
    else
    {        
        eFee_RetVal = MEMIF_JOB_PENDING; 
    }

    Fee_JobConfig.Fee_Job = FEE_JOB_INT_SWAP_CLR_FMT;

    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntSwap                                              
** 
** 
**  Description      : Used to initialize the cluster exchange internal 
**                     operation (on the current cluster group).                      
**                                                                            
**  Parameters (in)  : None     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the erase job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the erase job.                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwap( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
    P2CONST( Fee_ClusterGroup_Type, FEE_CONST, FEE_APPL_CONST ) pFee_Group = \
    gFee_ConfigPtr->Fee_ClusterGroup;

    Fee_JobConfig.Fee_OriginalJob = Fee_JobConfig.Fee_Job;

    u16Fee_JobIntBlockIt = 0U;

    if(gFee_JobIntClrGrpIt >=FEE_NUMBER_OF_CLUSTER_GROUPS)
    {
        eFee_RetVal = MEMIF_JOB_FAILED; 
        return( eFee_RetVal );
    }
    else
    {

    }
    gFee_JobIntClrIt = gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_ActClr;

    gFee_JobIntClrIt++;
		
    if( gFee_JobIntClrIt == pFee_Group[gFee_JobIntClrGrpIt].Fee_ClrCount )
    {
        gFee_JobIntClrIt = 0U;
    }
		
    u32Fee_JobIntHdrAddr = \
        pFee_Group[gFee_JobIntClrGrpIt].Fee_ClrPtr[gFee_JobIntClrIt].Fee_StartAddr;
    
    u32Fee_JobIntDataAddr = u32Fee_JobIntHdrAddr + \
        pFee_Group[gFee_JobIntClrGrpIt].Fee_ClrPtr[gFee_JobIntClrIt].Fee_Length;
    u32Fee_JobIntHdrAddr += FEE_CLUSTER_OVERHEAD;

    eFee_RetVal = Fee_JobIntSwapClrErase();

    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntScanBlockHdrRead                                              
** 
** 
**  Description      : Used to read Fee block header into internal buffer.                     
**                                                                            
**  Parameters (in)  : None     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the read job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the read job.                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrRead( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;

    if( Fls_Read( u32Fee_JobIntAddrIt, gFee_DataBuffer, FEE_BLOCK_OVERHEAD ) == \
        (Std_ReturnType)E_OK )
    {
        eFee_RetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        eFee_RetVal = MEMIF_JOB_FAILED;
    }
    Fee_JobConfig.Fee_Job    = FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE;
    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntScanClrErase                                              
** 
** 
**  Description      : Used to erase the first Fee cluster in the current cluster group.                     
**                                                                            
**  Parameters (in)  : None     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the erase job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the erase job.                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrErase( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_StartAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) u32Fee_Length = 0UL;    
    VAR( uint32, AUTOMATIC ) u32Fee_GrpIt = gFee_JobIntClrGrpIt;
    P2CONST( Fee_ClusterGroup_Type, FEE_CONST, FEE_APPL_CONST ) pFee_Group = \
    gFee_ConfigPtr->Fee_ClusterGroup;
    
    u32Fee_StartAddr = pFee_Group[u32Fee_GrpIt].Fee_ClrPtr[0].Fee_StartAddr;
    u32Fee_Length = pFee_Group[u32Fee_GrpIt].Fee_ClrPtr[0].Fee_Length;
    
    if( Fls_Erase( u32Fee_StartAddr, u32Fee_Length ) != \
        (Std_ReturnType)E_OK )
    {
        eFee_RetVal = MEMIF_JOB_FAILED;     
    } 
    else
    {     
        eFee_RetVal = MEMIF_JOB_PENDING;  
    }

    Fee_JobConfig.Fee_Job = FEE_JOB_INT_SCAN_CLR_FMT;

    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntScanClr                                              
** 
** 
**  Description      : Used to scan the active cluster of the current cluster 
**                     group (if no active cluster can be found, erase and 
**                     format the first cluster).                     
**                                                                            
**  Parameters (in)  : None     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the erase or read job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the erase or read job.                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClr( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
    VAR( uint32, AUTOMATIC ) u32Fee_GrpIt = gFee_JobIntClrGrpIt;
    VAR( uint8, AUTOMATIC ) u8Fee_ClrIndex = 0U;
    VAR( Fls_AddressType , AUTOMATIC ) u32Fee_ClrStartAddr = 0UL;
    VAR( Fls_LengthType , AUTOMATIC ) u32Fee_ClrLength = 0UL;
    P2CONST( Fee_ClusterGroup_Type, FEE_CONST, FEE_APPL_CONST ) pFee_Group = \
    gFee_ConfigPtr->Fee_ClusterGroup;  /*polyspace RTE:IDP*/

    if(u32Fee_GrpIt > FEE_NUMBER_OF_CLUSTER_GROUPS )
    {
        eFee_RetVal = MEMIF_JOB_FAILED;
        return( eFee_RetVal );
    }
    else 
    {

    }
    if( u32Fee_GrpIt != FEE_NUMBER_OF_CLUSTER_GROUPS )
    {
        if( gFee_ClrGrpInfo[u32Fee_GrpIt].Fee_ActClrID == 0U )
        {
            FEE_NVM_CLUSTER_FORMAT_NOTIFICATION

            eFee_RetVal = Fee_JobIntScanClrErase();
        }
        else
        {
            u8Fee_ClrIndex = gFee_ClrGrpInfo[u32Fee_GrpIt].Fee_ActClr;

            u32Fee_ClrStartAddr = \
                pFee_Group[u32Fee_GrpIt].Fee_ClrPtr[u8Fee_ClrIndex].Fee_StartAddr;

            u32Fee_JobIntAddrIt = FEE_CLUSTER_OVERHEAD + u32Fee_ClrStartAddr;

            gFee_ClrGrpInfo[u32Fee_GrpIt].Fee_HdrAddrIt = u32Fee_JobIntAddrIt;

            u32Fee_ClrLength = \
                pFee_Group[u32Fee_GrpIt].Fee_ClrPtr[u8Fee_ClrIndex].Fee_Length;

            gFee_ClrGrpInfo[u32Fee_GrpIt].Fee_DataAddrIt = \
                u32Fee_ClrStartAddr + u32Fee_ClrLength;

            eFee_RetVal = Fee_JobIntScanBlockHdrRead();
        }
    }
    else
    {
        Fee_JobConfig.Fee_Job = FEE_JOB_DONE;
    }   

    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntScanClrFmt                                              
** 
** 
**  Description      : Used to format the first Fee cluster in the current Fee 
**                     cluster group (by writing the Fee cluster header into 
**                     flash memory).                     
**                                                                            
**  Parameters (in)  : None     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the erase job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the erase job.                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmt \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
) 
{
    (void)bFee_Valid;
    VAR( uint32, AUTOMATIC ) u32Fee_GrpIt = gFee_JobIntClrGrpIt;
    P2CONST( Fee_ClusterGroup_Type, FEE_CONST, FEE_APPL_CONST ) pFee_Group = \
    gFee_ConfigPtr->Fee_ClusterGroup;  /*polyspace RTE:IDP*/
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_StartAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) u32Fee_Length = 0UL;
    
    u32Fee_StartAddr = pFee_Group[u32Fee_GrpIt].Fee_ClrPtr[0].Fee_StartAddr;

    u32Fee_Length = pFee_Group[u32Fee_GrpIt].Fee_ClrPtr[0].Fee_Length;

    Fee_SerializeClusterHdr( 1U, u32Fee_StartAddr, u32Fee_Length, gFee_DataBuffer );

    Fee_SerializeFlag(( gFee_DataBuffer + FEE_CLUSTER_OVERHEAD ) - \
        (2U * FEE_VIRTUAL_PAGE_SIZE), FEE_VALIDATED_VALUE );

    if( Fls_Write( u32Fee_StartAddr, gFee_DataBuffer, \
        FEE_CLUSTER_OVERHEAD - FEE_VIRTUAL_PAGE_SIZE ) != (Std_ReturnType)E_OK )
    {
        eFee_RetVal = MEMIF_JOB_FAILED;   
    }
    else
    {
        eFee_RetVal = MEMIF_JOB_PENDING; 
    }    
    Fee_JobConfig.Fee_Job = FEE_JOB_INT_SCAN_CLR_FMT_DONE;
    
    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntScanClrFmtDone                                              
** 
** 
**  Description      : Determine the format of the first Fee group in the 
**                     current Fee group.                     
**                                                                            
**  Parameters (in)  : None     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the erase or read job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the erase or read job.
**                     MEMIF_JOB_OK: There are no cluster groups to scan.                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmtDone \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
) 
{
    (void)bFee_Valid;
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType , AUTOMATIC ) u32Fee_ClrStartAddr = 0UL;
    VAR( Fls_LengthType , AUTOMATIC ) u32Fee_ClrLength = 0UL;
    VAR( uint32 , AUTOMATIC ) u32Fee_GrpIt = gFee_JobIntClrGrpIt;
    P2CONST( Fee_ClusterGroup_Type, FEE_CONST, FEE_APPL_CONST ) pFee_Group = \
    gFee_ConfigPtr->Fee_ClusterGroup; /*polyspace RTE:IDP*/
    
    if(u32Fee_GrpIt >= FEE_NUMBER_OF_CLUSTER_GROUPS)
    {
        eFee_RetVal = MEMIF_JOB_FAILED;
        return( eFee_RetVal );

    }
    else
    {
        
    }
    gFee_ClrGrpInfo[u32Fee_GrpIt].Fee_ActClr = 0U;
    gFee_ClrGrpInfo[u32Fee_GrpIt].Fee_ActClrID = 1U;

    u32Fee_ClrStartAddr = pFee_Group[u32Fee_GrpIt].Fee_ClrPtr[0].Fee_StartAddr;
    u32Fee_ClrLength = pFee_Group[u32Fee_GrpIt].Fee_ClrPtr[0].Fee_Length;
    
    gFee_ClrGrpInfo[u32Fee_GrpIt].Fee_HdrAddrIt = 
        u32Fee_ClrStartAddr + FEE_CLUSTER_OVERHEAD;
    
    gFee_ClrGrpInfo[u32Fee_GrpIt].Fee_DataAddrIt = u32Fee_ClrStartAddr + u32Fee_ClrLength;
    
    gFee_JobIntClrGrpIt++;
    
    eFee_RetVal = Fee_JobIntScanClr();
    
    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntScanBlockHdrParse                                              
** 
** 
**  Description      : Parse Fee block header.                    
**                                                                            
**  Parameters (in)  : bFee_BufferValid: FALSE if the previous Fls read operation failed.     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the erase or read job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the erase or read job.
**                     MEMIF_JOB_OK: There are no cluster groups to scan.                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrParse \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_FAILED;
    VAR( Fee_BlockStatus_Type, AUTOMATIC ) eFee_BlockStatus;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockNumber = 0U;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockSize = 0U;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_DataAddr = 0UL;
    VAR( boolean, AUTOMATIC ) bFee_ImmediateData = (boolean)FALSE;
    static VAR( boolean, AUTOMATIC) bFee_SwapToBePerformed = (boolean)FALSE;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockRuntimeInfoIndex = 0U;
    VAR( boolean, AUTOMATIC) bFee_SwapNeeded = (boolean)FALSE;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    VAR( uint8, AUTOMATIC ) u8Fee_BlockAssignment = (uint8)FEE_PROJECT_RESERVED;
    VAR( uint16, AUTOMATIC ) u16Fee_ForeignBlockIndex = 0U;
    VAR( boolean, AUTOMATIC ) bFee_Foreign = (boolean)FALSE;
    VAR( boolean, AUTOMATIC ) bFee_ForeignBlockOverflow = (boolean)FALSE;
#endif

    eFee_BlockStatus = Fee_DeserializeBlockHdr( \
        &u16Fee_BlockNumber, &u16Fee_BlockSize, &u32Fee_DataAddr, &bFee_ImmediateData,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        &u8Fee_BlockAssignment,
#endif
		gFee_DataBuffer);

#if (FEE_LEGACY_MODE == STD_ON)
    if( FEE_BLOCK_HEADER_BLANK != eFee_BlockStatus )
    {
        bFee_SwapToBePerformed = (boolean)FALSE;
    } 
#endif

    if(gFee_JobIntClrGrpIt >=FEE_NUMBER_OF_CLUSTER_GROUPS)
    {
        eFee_RetVal = MEMIF_JOB_FAILED; 
        return( eFee_RetVal );
    }
    else
    {

    }
    if (( FEE_BLOCK_HEADER_INVALID != eFee_BlockStatus ) &&( bFee_Valid != 0U))
    {
        if ( eFee_BlockStatus == FEE_BLOCK_HEADER_BLANK)
        {

            if(bFee_SwapToBePerformed == (boolean)TRUE)
            {
               bFee_SwapToBePerformed = (boolean)FALSE;
               gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_DataAddrIt = \
                    u32Fee_JobIntAddrIt + (2U * FEE_BLOCK_OVERHEAD );
            }
            gFee_JobIntClrGrpIt++;
            eFee_RetVal = Fee_JobIntScanClr();
        }
        else
        {
            VAR( uint32, AUTOMATIC ) u32Fee_BlockIndex = 0UL;

            u32Fee_BlockIndex = Fee_GetBlockIndex( u16Fee_BlockNumber );

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 

            bFee_Foreign = (boolean)FALSE;

            if( 0xFFFFU == u32Fee_BlockIndex )
            {
                #if (FEE_BOOTLOADER_CONFIG == STD_ON)
                    if (FEE_PROJECT_APPLICATION == (Fee_BlockAssignmentType)u8Fee_BlockAssignment)
                #else
                    if (FEE_PROJECT_BOOTLOADER == (Fee_BlockAssignmentType)u8Fee_BlockAssignment)
                #endif
                    {       
                        bFee_Foreign = (boolean)TRUE;
                        u16Fee_ForeignBlockIndex =  Fee_GetForeignBlockIndex( u16Fee_BlockNumber );

                        if( 0xFFFFU == u16Fee_ForeignBlockIndex )
                        {
                            bFee_ForeignBlockOverflow = (boolean)FALSE;

                            if(u16Fee_ForeignBlocksNumber < (FEE_MAX_NR_OF_BLOCKS - FEE_NUMBER_OF_BLOCKS))
                            {
                                u16Fee_ForeignBlockIndex = u16Fee_ForeignBlocksNumber;
                                Fee_ForeignBlockConfig[u16Fee_ForeignBlockIndex].u16Fee_BlockNumber = u16Fee_BlockNumber;
                                Fee_ForeignBlockConfig[u16Fee_ForeignBlockIndex].u16Fee_BlockSize = u16Fee_BlockSize;
                                Fee_ForeignBlockConfig[u16Fee_ForeignBlockIndex].u8Fee_ClrGrp = gFee_JobIntClrGrpIt;
                                Fee_ForeignBlockConfig[u16Fee_ForeignBlockIndex].bFee_ImmediateData = bFee_ImmediateData;
                                Fee_ForeignBlockConfig[u16Fee_ForeignBlockIndex].eFee_blockAssignment = \
                                    (Fee_BlockAssignmentType)u8Fee_BlockAssignment; 
                                u16Fee_ForeignBlocksNumber = u16Fee_ForeignBlocksNumber + 1U;
                            }
                            else
                            {
                                #if (FEE_DEV_ERROR_DETECT == STD_ON)
                                    Fee_ReportError( FEE_WRITE_ID, FEE_E_FOREIGN_BLOCKS_OVF);
                                #endif
                                FEE_NVM_JOB_ERROR_NOTIFICATION 
                                bFee_ForeignBlockOverflow = (boolean)TRUE;
                            }
                        }
                    }
            }

            if( bFee_ForeignBlockOverflow == (boolean)FALSE ) 
            {
#endif
                #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)        
                if( (0xffffU == u32Fee_BlockIndex) && ( bFee_Foreign == (boolean)FALSE) )
                #else
                if( 0xffffU == u32Fee_BlockIndex )
                #endif
                {
                    bFee_SwapToBePerformed = (boolean)TRUE;
                }
                else
                {   
                    VAR( uint16, AUTOMATIC ) u16Fee_AlignedBlockSize = 0U;

                    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
                    if((boolean)TRUE == bFee_Foreign)
                    {
                        u16Fee_BlockRuntimeInfoIndex = FEE_NUMBER_OF_BLOCKS + u16Fee_ForeignBlockIndex;
                    }
                    else
                    {
                        u16Fee_BlockRuntimeInfoIndex = u32Fee_BlockIndex;
                    }
                    #else
                    u16Fee_BlockRuntimeInfoIndex = u32Fee_BlockIndex; /* PRQA S 4461 */
                    #endif

                    u16Fee_AlignedBlockSize = Fee_AlignToVirtualPageSize( u16Fee_BlockSize );

                    bFee_SwapNeeded = (boolean)FALSE;

                    if(( u32Fee_DataAddr > \
                        (gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_DataAddrIt - u16Fee_AlignedBlockSize) ) || \
                        ( u32Fee_DataAddr < \
                        (gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_HdrAddrIt + (2U * FEE_BLOCK_OVERHEAD)) )
                    )
                    {
                        bFee_SwapToBePerformed = (boolean)TRUE;
                    }
                    else
                    {
                    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)                
                        if((boolean)FALSE == bFee_Foreign)
                    #endif 
                        {
                            if((gFee_ConfigPtr->Fee_BlockConfig[u32Fee_BlockIndex].u8Fee_ClrGrp \
                                == gFee_JobIntClrGrpIt) && \
                                (gFee_ConfigPtr->Fee_BlockConfig[u32Fee_BlockIndex].u16Fee_BlockSize \
                                    == u16Fee_BlockSize) && \
                                (gFee_ConfigPtr->Fee_BlockConfig[u32Fee_BlockIndex].bFee_ImmediateData \
                                    == bFee_ImmediateData))
                            {
                                bFee_SwapNeeded = (boolean)FALSE;
                            }
                            else
                            {
                                bFee_SwapNeeded = (boolean)TRUE;   
                            }
                        }
                    }  

                    if( (boolean)FALSE == bFee_SwapNeeded )
                    {
    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)

            #if (FEE_LEGACY_MODE == STD_OFF)
                    if( FEE_BLOCK_INCONSISTENT == eFee_BlockStatus )
            #else
                    if ((FEE_BLOCK_INCONSISTENT == eFee_BlockStatus) && \
                        (bFee_ImmediateData == (boolean)FALSE))
            #endif
                    {
                        gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_DataAddrIt = u32Fee_DataAddr;
                    }
                    else
                    {
                        if (FEE_BLOCK_INVALIDATED == eFee_BlockStatus)
                        {
                            eFee_BlockStatus = FEE_BLOCK_INVALID;
                        }
    #endif
                        gFee_BlockInfo[u16Fee_BlockRuntimeInfoIndex].Fee_BlockStatus = eFee_BlockStatus;
                        gFee_BlockInfo[u16Fee_BlockRuntimeInfoIndex].Fee_DataAddr = u32Fee_DataAddr;
                        gFee_BlockInfo[u16Fee_BlockRuntimeInfoIndex].Fee_InvalidAddr = \
                            ( u32Fee_JobIntAddrIt + FEE_BLOCK_OVERHEAD ) - FEE_VIRTUAL_PAGE_SIZE;
                    
                        gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_DataAddrIt = u32Fee_DataAddr;
                    
    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
                    }
    #endif              
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) && (FEE_LEGACY_MODE == STD_OFF)
                    gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_HdrAddrIt = \
                        u32Fee_JobIntAddrIt + FEE_BLOCK_OVERHEAD;
                    if( Fee_ReservedAreaTargetedInClrGrp( gFee_JobIntClrGrpIt ) != (boolean)FALSE )
                    {
                        if( bFee_ImmediateData == (boolean)TRUE )
                        {
                            Fee_TouchReservedAreaByBlock( u16Fee_BlockRuntimeInfoIndex );

                        }
                        else
                        {
                            bFee_SwapToBePerformed = (boolean)TRUE;
                        }
                    }
        #endif
                    }
                    else
                    {
                        bFee_SwapToBePerformed = (boolean)TRUE;
                    }
                }

                u32Fee_JobIntAddrIt += FEE_BLOCK_OVERHEAD;
                gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_HdrAddrIt = \
                u32Fee_JobIntAddrIt;  
                eFee_RetVal = Fee_JobIntScanBlockHdrRead();
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
            }
            else
            {
                eFee_RetVal = MEMIF_JOB_FAILED;
            }
#endif 
        }
    }
    else
    {
        u16Fee_JobBlockIndex = 0xffffU;
        u32Fee_JobIntAddrIt += FEE_BLOCK_OVERHEAD;
        gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_HdrAddrIt = \
        u32Fee_JobIntAddrIt;
        bFee_SwapToBePerformed = (boolean)TRUE; 
        eFee_RetVal = Fee_JobIntScanBlockHdrRead();
    }

    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntScanClrHdrRead                                              
** 
** 
**  Description      : Read Fee block header.                    
**                                                                            
**  Parameters (in)  : None     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the read job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the read job.                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrRead( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_ReadAddress = 0UL;
    P2CONST( Fee_ClusterGroup_Type, FEE_CONST, FEE_APPL_CONST ) pFee_Group = \
    gFee_ConfigPtr->Fee_ClusterGroup;  /*polyspace RTE:IDP*/
   
    u32Fee_ReadAddress = \
        pFee_Group[gFee_JobIntClrGrpIt].Fee_ClrPtr[gFee_JobIntClrIt].Fee_StartAddr;
    
    if( Fls_Read( u32Fee_ReadAddress, gFee_DataBuffer, FEE_CLUSTER_OVERHEAD ) != (Std_ReturnType)E_OK )
    {
        eFee_RetVal = MEMIF_JOB_FAILED;
    }
    else
    {
        eFee_RetVal = MEMIF_JOB_PENDING;
    }
        
    Fee_JobConfig.Fee_Job = FEE_JOB_INT_SCAN_CLR_HDR_PARSE;
    
    return( eFee_RetVal );        
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntScan                                              
** 
** 
**  Description      : Initialize cluster scan job.                    
**                                                                            
**  Parameters (in)  : None     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the read job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the read job.                                             
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScan \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    (void)bFee_Valid;
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;

    gFee_JobIntClrGrpIt = 0U;
    gFee_JobIntClrIt = 0U;

    eFee_RetVal = Fee_JobIntScanClrHdrRead();
    
    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntScanClrHdrParse                                              
** 
** 
**  Description      : Parse Fee cluster header.                    
**                                                                            
**  Parameters (in)  : bFee_BufferValid: FALSE if the previous Fls read operation failed.     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the erase or read job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the erase or read job.                                            
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrParse \
( \
    CONST( boolean, AUTOMATIC) bFee_Valid \
) 
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
    VAR( Fee_ClusterStatus_Type, AUTOMATIC ) eFee_ClrStatus = FEE_CLUSTER_VALID;
    VAR( uint32, AUTOMATIC ) u32Fee_ClrID = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_ClrStartAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) u32Fee_ClrSize = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_CfgStartAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) u32Fee_CfgClrSize = 0UL;
    P2CONST( Fee_ClusterGroup_Type, FEE_CONST, FEE_APPL_CONST ) pFee_Group = \
    gFee_ConfigPtr->Fee_ClusterGroup;    /*polyspace RTE:IDP*/
    
    u32Fee_CfgStartAddr = \
        pFee_Group[gFee_JobIntClrGrpIt].Fee_ClrPtr[gFee_JobIntClrIt].Fee_StartAddr;
    u32Fee_CfgClrSize = \
        pFee_Group[gFee_JobIntClrGrpIt].Fee_ClrPtr[gFee_JobIntClrIt].Fee_Length;
    eFee_ClrStatus = \
        Fee_DeserializeClusterHdr( &u32Fee_ClrID, &u32Fee_ClrStartAddr, &u32Fee_ClrSize, \
            gFee_DataBuffer );

    if(gFee_JobIntClrGrpIt >= FEE_NUMBER_OF_CLUSTER_GROUPS)
    {
        eFee_RetVal = MEMIF_JOB_FAILED;
        return( eFee_RetVal );  

    }
    else 
    {

    }
    if(( bFee_Valid != 0U) && ( FEE_CLUSTER_VALID == eFee_ClrStatus ) && \
        ( u32Fee_ClrStartAddr == u32Fee_CfgStartAddr ) && ( u32Fee_ClrSize == \
        u32Fee_CfgClrSize ) && ( u32Fee_ClrID > \
        gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_ActClrID ))
    {
        gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_ActClr = gFee_JobIntClrIt;
        gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_ActClrID = u32Fee_ClrID;
    }
    
    gFee_JobIntClrIt++;
    
    if( gFee_JobIntClrIt == pFee_Group[gFee_JobIntClrGrpIt].Fee_ClrCount )
    {
        gFee_JobIntClrGrpIt++;
        gFee_JobIntClrIt = 0U;
    }

    if ( gFee_JobIntClrGrpIt != FEE_NUMBER_OF_CLUSTER_GROUPS )
    {
        eFee_RetVal = Fee_JobIntScanClrHdrRead();
    }
    else
    {
        gFee_JobIntClrGrpIt = 0U;
        eFee_RetVal = Fee_JobIntScanClr();
    }
    
    return( eFee_RetVal );        
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobRead                                              
** 
** 
**  Description      : Read Fee block.                    
**                                                                            
**  Parameters (in)  : None     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the read job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the read job. 
**                     MEMIF_BLOCK_INVALID: The requested Fee block is invalid.
**                     MEMIF_BLOCK_INCONSISTENT: The requested Fee block is inconsistent.                     
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobRead \
( \
	CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    (void)bFee_Valid;
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_FAILED;
    VAR( Fee_BlockStatus_Type, AUTOMATIC ) eFee_BlockStatus = FEE_BLOCK_VALID;
    VAR( Fls_AddressType, AUTOMATIC ) eFee_BlockAddress = 0UL;

    if (u16Fee_JobBlockIndex >= FEE_NUMBER_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_ReportError( FEE_READ_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        eFee_RetVal = MEMIF_JOB_FAILED;
        FEE_NVM_JOB_ERROR_NOTIFICATION
        return( eFee_RetVal );
    }
    else
    {

    }
    eFee_BlockStatus = gFee_BlockInfo[ u16Fee_JobBlockIndex].Fee_BlockStatus;
    eFee_BlockAddress = gFee_BlockInfo[ u16Fee_JobBlockIndex].Fee_DataAddr;
    
    switch (eFee_BlockStatus)
    {
        case FEE_BLOCK_VALID:
		{
            if( Fls_Read( eFee_BlockAddress + u16Fee_JobBlockOffset, \
                gFee_JobDataDestPtr, u16Fee_JobBlockLength) == (Std_ReturnType)E_OK )
            {
                eFee_RetVal = MEMIF_JOB_PENDING;
            }
            else
            {
                eFee_RetVal = MEMIF_JOB_FAILED;
            }
            break;
        }
#if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_OFF)
        case FEE_BLOCK_NEVER_WRITTEN:
        {
            eFee_RetVal = MEMIF_BLOCK_INCONSISTENT;
            break;
        }
#endif
        case FEE_BLOCK_INVALID:
        {
            eFee_RetVal = MEMIF_BLOCK_INVALID;
            break;
        }
        case FEE_BLOCK_INCONSISTENT:
        {
            if ( (gFee_ConfigPtr->Fee_BlockConfig[ u16Fee_JobBlockIndex].bFee_ImmediateData ) == 0U) /*polyspace RTE:IDP*/
            {
                eFee_RetVal = MEMIF_BLOCK_INCONSISTENT;
            }
            else
            {
                eFee_RetVal = MEMIF_BLOCK_INVALID;
            }
            break;
        }
        default:
        {
            /* do nothing */
            break;
        }
    }

    Fee_JobConfig.Fee_Job = FEE_JOB_DONE;
    
    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntSwapBlockVld                                              
** 
** 
**  Description      : Used to verify Fee block                   
**                                                                            
**  Parameters (in)  : None     
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the write job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the write job.                     
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlockVld( void ) 
{ 
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
     
    Fee_SerializeFlag( gFee_DataBuffer, FEE_VALIDATED_VALUE );
    if( Fls_Write( u32Fee_JobIntHdrAddr - ( 2U * FEE_VIRTUAL_PAGE_SIZE ), \
        gFee_DataBuffer, FEE_VIRTUAL_PAGE_SIZE ) == (Std_ReturnType)E_OK )
    {
        eFee_RetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        eFee_RetVal = MEMIF_JOB_FAILED;
    }

    Fee_JobConfig.Fee_Job = FEE_JOB_INT_SWAP_BLOCK;
    
    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntSwapDataRead                                              
** 
** 
**  Description      : Used to read data from the source cluster to the 
**                     internal Fee buffer                   
**                                                                            
**  Parameters (in)  : bufferValid: FALSE if the previous Fls read operation failed.      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the read job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the read job.                     
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataRead \
( \
    CONST( boolean, AUTOMATIC) bFee_Valid \
)
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_FAILED;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_ReadAddr = 0UL;
    VAR( uint16, AUTOMATIC ) u16Fee_AlignedBlockSize = 0U;    
    VAR( uint16, AUTOMATIC ) u16Fee_BlockSize = 0U;

    if (u16Fee_JobIntBlockIt >= FEE_NUMBER_OF_BLOCKS )
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_ReportError( FEE_INVALIDATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        eFee_RetVal = MEMIF_JOB_FAILED; 
        FEE_NVM_JOB_ERROR_NOTIFICATION
        return( eFee_RetVal );
    }
    else
    {

    }
    u16Fee_BlockSize = gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobIntBlockIt].u16Fee_BlockSize;  /*polyspace RTE:IDP*/
    
    u16Fee_AlignedBlockSize = Fee_AlignToVirtualPageSize( u16Fee_BlockSize );
    
    u16Fee_JobBlockLength = ( u32Fee_JobIntDataAddr + \
        u16Fee_AlignedBlockSize ) - u32Fee_JobIntAddrIt;
    if (bFee_Valid != 0U)
    {
        if( 0U == u16Fee_JobBlockLength )
        {
            u16Fee_JobIntBlockIt++;
            eFee_RetVal = Fee_JobIntSwapBlockVld();
        }
        else
        {
            if( u16Fee_JobBlockLength > FEE_DATA_BUFFER_SIZE )
            {
                u16Fee_JobBlockLength = FEE_DATA_BUFFER_SIZE;
            }
    
            u32Fee_ReadAddr = ( gFee_BlockInfo[u16Fee_JobIntBlockIt].Fee_DataAddr + \
                u32Fee_JobIntAddrIt ) - u32Fee_JobIntDataAddr;
        
            if( (Std_ReturnType)E_OK == Fls_Read( u32Fee_ReadAddr, gFee_DataBuffer, \
                                                u16Fee_JobBlockLength ) )
            {
                eFee_RetVal = MEMIF_JOB_PENDING;
            }
            else
            {
                eFee_RetVal = MEMIF_JOB_FAILED;
            }    
            Fee_JobConfig.Fee_Job = FEE_JOB_INT_SWAP_DATA_WRITE;
        }
    }
    else
    {
        gFee_BlockInfo[u16Fee_JobIntBlockIt].Fee_BlockStatus = FEE_BLOCK_INCONSISTENT_COPY;
        u16Fee_JobIntBlockIt++;
        eFee_RetVal = Fee_JobIntSwapBlock(TRUE);
    }

    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntSwapDataWrite                                              
** 
** 
**  Description      : Used to write data from the internal Fee buffer to 
**                     the target cluster.                   
**                                                                            
**  Parameters (in)  : bufferValid: FALSE if the previous Fls read operation failed.      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the write job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the write job.                     
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataWrite \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;

    if( bFee_Valid == 0U )
    {    
        eFee_RetVal = Fee_JobIntSwapDataRead( (boolean) FALSE );
    }
    else
    {
        if( (Std_ReturnType)E_OK != Fls_Write( u32Fee_JobIntAddrIt, gFee_DataBuffer, \
                                                           u16Fee_JobBlockLength ))
        {
            eFee_RetVal = MEMIF_JOB_FAILED;   
        }
        else
        {
            eFee_RetVal = MEMIF_JOB_PENDING; 
        }
        u32Fee_JobIntAddrIt += u16Fee_JobBlockLength;
        Fee_JobConfig.Fee_Job = FEE_JOB_INT_SWAP_DATA_READ;
    }

    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobIntSwapClrVldDone                                              
** 
** 
**  Description      : Used to complete cluster verification.                   
**                                                                            
**  Parameters (in)  : None      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the write job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the write job.                     
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVldDone \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    (void)bFee_Valid;
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockIt = 0U;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_HdrAddrIt = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_DataAddrIt = 0UL;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockSize = 0U;        
    VAR( uint16, AUTOMATIC ) u16Fee_AlignedBlockSize = 0U;  
    P2CONST( Fee_ClusterGroup_Type, FEE_CONST, FEE_APPL_CONST ) pFee_Group = \
    gFee_ConfigPtr->Fee_ClusterGroup;  /*polyspace RTE:IDP*/
#if (FEE_LEGACY_MODE == STD_ON)     
    VAR( boolean, AUTOMATIC ) bFee_ImmediateBlock = (boolean)FALSE;
#endif

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) && (FEE_LEGACY_MODE == STD_OFF)
    Fee_UntouchReservedAreaByClrGrp( gFee_JobIntClrGrpIt );
#endif

    u32Fee_HdrAddrIt = pFee_Group[gFee_JobIntClrGrpIt].Fee_ClrPtr[gFee_JobIntClrIt].Fee_StartAddr;
    u32Fee_DataAddrIt = u32Fee_HdrAddrIt + \
        pFee_Group[gFee_JobIntClrGrpIt].Fee_ClrPtr[gFee_JobIntClrIt].Fee_Length;
    u32Fee_HdrAddrIt += FEE_CLUSTER_OVERHEAD;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
   for( u16Fee_BlockIt = 0U; u16Fee_BlockIt < \
    (FEE_NUMBER_OF_BLOCKS + u16Fee_ForeignBlocksNumber); u16Fee_BlockIt++ )
#else
    for( u16Fee_BlockIt = 0U; u16Fee_BlockIt < FEE_NUMBER_OF_BLOCKS; u16Fee_BlockIt++ )
#endif
    {   
        if(gFee_ConfigPtr->Fee_BlockConfig[u16Fee_BlockIt].u8Fee_ClrGrp == gFee_JobIntClrGrpIt)
        {
            if (( FEE_BLOCK_VALID == gFee_BlockInfo[u16Fee_BlockIt].Fee_BlockStatus ) || \
                ( FEE_BLOCK_INCONSISTENT == gFee_BlockInfo[u16Fee_BlockIt].Fee_BlockStatus ) || \
                (FEE_BLOCK_INCONSISTENT_COPY == gFee_BlockInfo[u16Fee_BlockIt].Fee_BlockStatus)
          		)
            {    
                gFee_BlockInfo[u16Fee_BlockIt].Fee_InvalidAddr = ( u32Fee_HdrAddrIt + \
                    FEE_BLOCK_OVERHEAD ) - FEE_VIRTUAL_PAGE_SIZE;

                #if (FEE_LEGACY_MODE == STD_ON)                
                    bFee_ImmediateBlock = Fee_GetBlockImmediate(u16Fee_BlockIt);
                #endif

                if (( FEE_BLOCK_VALID == gFee_BlockInfo[u16Fee_BlockIt].Fee_BlockStatus ) || \
                ( FEE_BLOCK_INCONSISTENT_COPY == gFee_BlockInfo[u16Fee_BlockIt].Fee_BlockStatus )
                #if (FEE_LEGACY_MODE == STD_ON)
                     || ( ((boolean)TRUE == bFee_ImmediateBlock) &&
                          (FEE_BLOCK_INCONSISTENT == gFee_BlockInfo[u16Fee_BlockIt].Fee_BlockStatus) 
                        )
                #endif
                    )
                {
                    u16Fee_BlockSize = gFee_ConfigPtr->Fee_BlockConfig[u16Fee_BlockIt].u16Fee_BlockSize;
                    u16Fee_AlignedBlockSize = Fee_AlignToVirtualPageSize( u16Fee_BlockSize );
                    u32Fee_DataAddrIt -= u16Fee_AlignedBlockSize;

                    if( FEE_BLOCK_INCONSISTENT_COPY == gFee_BlockInfo[u16Fee_BlockIt].Fee_BlockStatus )
                    {
                        gFee_BlockInfo[u16Fee_BlockIt].Fee_BlockStatus = FEE_BLOCK_INCONSISTENT;
                        gFee_BlockInfo[u16Fee_BlockIt].Fee_DataAddr = 0U;
                    }
                    else
                    {
                        gFee_BlockInfo[u16Fee_BlockIt].Fee_DataAddr = u32Fee_DataAddrIt;
                    }
                }
                else
                {
                    gFee_BlockInfo[u16Fee_BlockIt].Fee_DataAddr = 0U;
                }

                u32Fee_HdrAddrIt += FEE_BLOCK_OVERHEAD;
			}
            else
            {
                gFee_BlockInfo[u16Fee_BlockIt].Fee_DataAddr = 0U;
                gFee_BlockInfo[u16Fee_BlockIt].Fee_InvalidAddr = 0U;
            }
        }
    }


    if(gFee_JobIntClrGrpIt >= FEE_NUMBER_OF_CLUSTER_GROUPS)
    {
        Fee_ReportRuntimeError(FEE_JOBENDNOTIFICATION_ID, FEE_E_CLUSTER_GROUP_IDX);
        eFee_RetVal = MEMIF_JOB_FAILED; 
        return( eFee_RetVal );
    }
    else
    {
        
    }
    gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_ActClr = \
    gFee_JobIntClrIt;
    gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_ActClrID++;
    gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_HdrAddrIt = u32Fee_HdrAddrIt;
    gFee_ClrGrpInfo[gFee_JobIntClrGrpIt].Fee_DataAddrIt = u32Fee_DataAddrIt;


    if( FEE_JOB_INT_SCAN_CLR == Fee_JobConfig.Fee_OriginalJob )
    {
        gFee_JobIntClrGrpIt++;
    }
    else
    {
        /* Do nothing */
    }

    Fee_JobConfig.Fee_ModuleStatus = MEMIF_BUSY;

    Fee_JobConfig.Fee_Job = Fee_JobConfig.Fee_OriginalJob;

    eFee_RetVal = Fee_JobSchedule();
    
    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobWriteHdr                                              
** 
** 
**  Description      : Used to write Fee block header to flash memory.                  
**                                                                            
**  Parameters (in)  : None      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the write job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the write job.                     
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteHdr( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_FAILED;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockSize = 0U;
    VAR( uint16, AUTOMATIC ) u16Fee_AlignedBlockSize =0U;
#if (FEE_LEGACY_MODE == STD_ON)
    VAR( Fls_LengthType, AUTOMATIC ) u32Fee_AvailClrSpace = 0UL;
#endif
    VAR( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex = 0U;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_DataAddr = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_HdrAddr = 0UL;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (u16Fee_JobBlockIndex >= FEE_NUMBER_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_ReportError( FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        eFee_RetVal = MEMIF_JOB_FAILED;
        FEE_NVM_JOB_ERROR_NOTIFICATION
    }
    else
    {
#endif
        u8Fee_ClrGrpIndex = gFee_ConfigPtr->Fee_BlockConfig[ u16Fee_JobBlockIndex].u8Fee_ClrGrp;  /*polyspace RTE:IDP*/
        if(u8Fee_ClrGrpIndex >= FEE_NUMBER_OF_CLUSTER_GROUPS)
        {
            eFee_RetVal = MEMIF_JOB_FAILED;
            return eFee_RetVal;
        }
        else
        {
            
        }

        #if (FEE_LEGACY_MODE == STD_ON)
        u32Fee_AvailClrSpace = gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_DataAddrIt - \
            gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_HdrAddrIt;
        #endif

        u16Fee_BlockSize = gFee_ConfigPtr->Fee_BlockConfig[ u16Fee_JobBlockIndex].u16Fee_BlockSize;
        u16Fee_AlignedBlockSize = Fee_AlignToVirtualPageSize( u16Fee_BlockSize );

        #if (FEE_LEGACY_MODE == STD_ON)
        if(((uint32) u16Fee_AlignedBlockSize + (2U * FEE_BLOCK_OVERHEAD )) <= u32Fee_AvailClrSpace )
        #else
        if( TRUE == Fee_ReservedAreaWritable() )
        #endif
        {
            u32Fee_DataAddr = gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_DataAddrIt - \
                u16Fee_AlignedBlockSize;
            u32Fee_HdrAddr = gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_HdrAddrIt;
            Fee_SerializeBlockHdr(  gFee_ConfigPtr->Fee_BlockConfig[ u16Fee_JobBlockIndex].u16Fee_BlockNumber,
                                    u16Fee_BlockSize, u32Fee_DataAddr, 
                                    gFee_ConfigPtr->Fee_BlockConfig[ u16Fee_JobBlockIndex].bFee_ImmediateData, 
                                    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
                                    gFee_ConfigPtr->Fee_BlockConfig[ u16Fee_JobBlockIndex].eFee_blockAssignment,
                                    #endif
                                    gFee_DataBuffer );

            if( (Std_ReturnType)E_OK == Fls_Write( u32Fee_HdrAddr, gFee_DataBuffer, FEE_BLOCK_OVERHEAD - \
                                        ( 2U * FEE_VIRTUAL_PAGE_SIZE )) )
            {
                eFee_RetVal = MEMIF_JOB_PENDING;
            }
            else
            {    
                eFee_RetVal = MEMIF_JOB_FAILED;
            }
        } 
        else
        {
            gFee_JobIntClrGrpIt = u8Fee_ClrGrpIndex;
            eFee_RetVal = Fee_JobIntSwap();
        }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif
    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobWriteData                                              
** 
** 
**  Description      : Used to write Fee block data to flash memory.                  
**                                                                            
**  Parameters (in)  : None      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the write job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the write job.                     
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteData \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    (void)bFee_Valid;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_DataAddr = 0UL;
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockSize = 0U;
    VAR( uint16, AUTOMATIC ) u16Fee_AlignedBlockSize = 0U;    
    VAR( Fls_LengthType, AUTOMATIC ) u32Fee_WriteLength = 0UL;    
    VAR( uint16, AUTOMATIC ) u16Fee_ClrGrp = 0U;
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF)
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_HdrAddr = 0UL;
    VAR( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex = 0U;
#endif
#if (FEE_LEGACY_MODE == STD_OFF)
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)    
    VAR(sint8, AUTOMATIC) sFee_IsReservedAreaTouched = TRUE; 
#endif
#endif
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_WriteDataPtr = NULL_PTR;  

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (u16Fee_JobBlockIndex >= FEE_NUMBER_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_ReportError( FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        eFee_RetVal = MEMIF_JOB_FAILED;
        FEE_NVM_JOB_ERROR_NOTIFICATION
    }
    else
    {
#endif
    if (u16Fee_JobBlockIndex >= FEE_NUMBER_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_ReportError( FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        eFee_RetVal = MEMIF_JOB_FAILED;
        FEE_NVM_JOB_ERROR_NOTIFICATION
        return eFee_RetVal;
    }
    else
    {

    }
    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF)

        #if (FEE_LEGACY_MODE == STD_OFF)
        #else
        if( !gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].bFee_ImmediateData )
        #endif
        {
            u8Fee_ClrGrpIndex = gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].u8Fee_ClrGrp; /*polyspace RTE:IDP*/
            if(u8Fee_ClrGrpIndex >= FEE_NUMBER_OF_CLUSTER_GROUPS)
            {
                eFee_RetVal = MEMIF_JOB_FAILED;
                return eFee_RetVal;
            }
            else
            {
                
            }
            u16Fee_BlockSize = gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].u16Fee_BlockSize;
            u16Fee_AlignedBlockSize = Fee_AlignToVirtualPageSize( u16Fee_BlockSize );
            u32Fee_DataAddr = gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_DataAddrIt - \
                                u16Fee_AlignedBlockSize;
            u32Fee_HdrAddr = gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_HdrAddrIt;
            gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_DataAddr = u32Fee_DataAddr;
            gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_InvalidAddr = \
                ( u32Fee_HdrAddr + FEE_BLOCK_OVERHEAD ) - FEE_VIRTUAL_PAGE_SIZE;
        }
        gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_BlockStatus = FEE_BLOCK_INCONSISTENT;
    #endif
        
        u16Fee_BlockSize = gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].u16Fee_BlockSize;

        u16Fee_AlignedBlockSize = Fee_AlignToVirtualPageSize( u16Fee_BlockSize );

        u16Fee_ClrGrp = gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].u8Fee_ClrGrp;

    #if (FEE_LEGACY_MODE == STD_OFF)
            gFee_ClrGrpInfo[u16Fee_ClrGrp].Fee_HdrAddrIt += FEE_BLOCK_OVERHEAD;
            gFee_ClrGrpInfo[u16Fee_ClrGrp].Fee_DataAddrIt -= u16Fee_AlignedBlockSize;
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        sFee_IsReservedAreaTouched = Fee_ReservedAreaTargetedInClrGrp(u16Fee_ClrGrp);
        if( (0UL != gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].bFee_ImmediateData) && \
            (FALSE != sFee_IsReservedAreaTouched))
        {
            /* Store the information about immediate blook touching the Reserved Area. */
            Fee_TouchReservedAreaByBlock( u16Fee_JobBlockIndex );
        }
        #endif
    #else
        if( !gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].bFee_ImmediateData )
        {
            gFee_ClrGrpInfo[u16Fee_ClrGrp].Fee_HdrAddrIt += FEE_BLOCK_OVERHEAD;
            gFee_ClrGrpInfo[u16Fee_ClrGrp].Fee_DataAddrIt -= u16Fee_AlignedBlockSize;
        }
    #endif
        
        if( u16Fee_BlockSize >= FEE_VIRTUAL_PAGE_SIZE )
        {
            u8Fee_WriteDataPtr = gFee_JobDataDestPtr;
            if( u16Fee_AlignedBlockSize != u16Fee_BlockSize )
            {
                u32Fee_WriteLength = (uint32) u16Fee_AlignedBlockSize - FEE_VIRTUAL_PAGE_SIZE;
                Fee_JobConfig.Fee_Job = FEE_JOB_WRITE_UNALIGNED_DATA;
            }
            else
            {
                u32Fee_WriteLength = u16Fee_BlockSize;
                Fee_JobConfig.Fee_Job = FEE_JOB_WRITE_VALIDATE;
            }
        }
        else
        {
            Fee_CopyDataToPageBuffer( gFee_JobDataDestPtr, gFee_DataBuffer, u16Fee_BlockSize );
            u8Fee_WriteDataPtr = gFee_DataBuffer;
            u32Fee_WriteLength = FEE_VIRTUAL_PAGE_SIZE;
            Fee_JobConfig.Fee_Job = FEE_JOB_WRITE_VALIDATE;
        }

    #if (FEE_LEGACY_MODE == STD_OFF)
       u32Fee_DataAddr = gFee_ClrGrpInfo[u16Fee_ClrGrp].Fee_DataAddrIt;
    #else
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
            if (!gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].bFee_ImmediateData)
            {
                u32Fee_DataAddr = gFee_ClrGrpInfo[u16Fee_ClrGrp].Fee_DataAddrIt;
            }
            else
            {
        #endif
                u32Fee_DataAddr = gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_DataAddr;
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
            }
        #endif
    #endif

        if( Fls_Write( u32Fee_DataAddr, u8Fee_WriteDataPtr, u32Fee_WriteLength ) != \
            (Std_ReturnType)E_OK )
        {
            eFee_RetVal = MEMIF_JOB_FAILED;  
        }
        else
        {
            eFee_RetVal = MEMIF_JOB_PENDING;  
        }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif
    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobWrite                                              
** 
** 
**  Description      : Used to write Fee block to flash memory.                  
**                                                                            
**  Parameters (in)  : None      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the write job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the write job.                     
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWrite \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    (void)bFee_Valid;
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_FAILED;
    
    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    if (u16Fee_JobBlockIndex >= FEE_NUMBER_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_ReportError( FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO );
        #endif
        eFee_RetVal = MEMIF_JOB_FAILED;
        FEE_NVM_JOB_ERROR_NOTIFICATION 
    }
    else
    {
#endif
        #if (FEE_LEGACY_MODE == STD_ON)
        if( gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].bFee_ImmediateData )
        {
            if( gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_BlockStatus != \
                FEE_BLOCK_INCONSISTENT )
            {
                eFee_RetVal = MEMIF_JOB_FAILED;
            }
            else
            {
                eFee_RetVal = Fee_JobWriteData(TRUE);
            }
        }
        else
        #else
        #endif
        {
            eFee_RetVal = Fee_JobWriteHdr();
            if( Fee_JobConfig.Fee_Job != FEE_JOB_INT_SWAP_CLR_FMT )
            {        
                Fee_JobConfig.Fee_Job = FEE_JOB_WRITE_DATA; 
            }
        }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    }
#endif 

    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobWriteUnalignedData                                              
** 
** 
**  Description      : Used to write the remaining data of Fee block 
**                     misalignment into flash memory.                 
**                                                                            
**  Parameters (in)  : None      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the write job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the write job.                     
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteUnalignedData \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    (void)bFee_Valid;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_DataAddr = 0UL;
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
    VAR( uint16, AUTOMATIC ) u16Fee_WriteOffset = 0U;
    VAR( uint16, AUTOMATIC ) u16Fee_WriteLength = 0U;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockSize = 0U;

    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (u16Fee_JobBlockIndex >= FEE_NUMBER_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void) Fee_ReportError( FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO );
        #endif
        eFee_RetVal = MEMIF_JOB_FAILED;
        FEE_NVM_JOB_ERROR_NOTIFICATION
    }
    else
    {
#endif
    if (u16Fee_JobBlockIndex >= FEE_NUMBER_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void) Fee_ReportError( FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO );
        #endif
        eFee_RetVal = MEMIF_JOB_FAILED;
        FEE_NVM_JOB_ERROR_NOTIFICATION
        return( eFee_RetVal );
    }
    else
    {

    }
    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        VAR( uint16, AUTOMATIC ) u16Fee_ClrGrp =0U;

        u16Fee_ClrGrp = gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].u8Fee_ClrGrp;
    #endif
        u16Fee_BlockSize = gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].u16Fee_BlockSize;  /*polyspace RTE:IDP*/
        u16Fee_WriteOffset = (uint16)((u16Fee_BlockSize / FEE_VIRTUAL_PAGE_SIZE) * FEE_VIRTUAL_PAGE_SIZE);
        u16Fee_WriteLength = u16Fee_BlockSize % FEE_VIRTUAL_PAGE_SIZE;
        Fee_CopyDataToPageBuffer( gFee_JobDataDestPtr + u16Fee_WriteOffset, \
                                gFee_DataBuffer,u16Fee_WriteLength );

    #if (FEE_LEGACY_MODE == STD_OFF)
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
            u32Fee_DataAddr = gFee_ClrGrpInfo[u16Fee_ClrGrp].Fee_DataAddrIt;
        #else
            u32Fee_DataAddr = gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_DataAddr;
        #endif
    #else
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
            if( !gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].bFee_ImmediateData )
            {
                u32Fee_DataAddr = gFee_ClrGrpInfo[u16Fee_ClrGrp].Fee_DataAddrIt;
            }
            else
            {
        #endif        
                u32Fee_DataAddr = gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_DataAddr;
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
            }
        #endif
    #endif

        if( Fls_Write( u32Fee_DataAddr + u16Fee_WriteOffset, gFee_DataBuffer, \
            FEE_VIRTUAL_PAGE_SIZE ) != (Std_ReturnType)E_OK )
        {
            eFee_RetVal = MEMIF_JOB_FAILED;  
        }
        else
        {
            eFee_RetVal = MEMIF_JOB_PENDING;  
        }

        Fee_JobConfig.Fee_Job = FEE_JOB_WRITE_VALIDATE;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif

    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobWriteValidate                                              
** 
** 
**  Description      : Used to verify Fee block (write verification flag 
**                     to flash memory)                 
**                                                                            
**  Parameters (in)  : None      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the write job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the write job.                     
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteValidate \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    (void)bFee_Valid;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_HdrAddr = 0UL;
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (u16Fee_JobBlockIndex >= FEE_NUMBER_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_ReportError( FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO );
        #endif
        eFee_RetVal = MEMIF_JOB_FAILED;
        FEE_NVM_JOB_ERROR_NOTIFICATION
    }
    else
    {
#endif
    if (u16Fee_JobBlockIndex >= FEE_NUMBER_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_ReportError( FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO );
        #endif
        eFee_RetVal = MEMIF_JOB_FAILED;
        FEE_NVM_JOB_ERROR_NOTIFICATION
        return( eFee_RetVal );
    }
    else
    {

    }
    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        VAR( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex = 0U;
        
        u8Fee_ClrGrpIndex = gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].u8Fee_ClrGrp;
    #endif       
        Fee_SerializeFlag( gFee_DataBuffer, FEE_VALIDATED_VALUE );

#if (FEE_LEGACY_MODE == STD_OFF)
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        u32Fee_HdrAddr = gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_HdrAddrIt - \
                (2U *  FEE_VIRTUAL_PAGE_SIZE);
        #else
        u32Fee_HdrAddr = (gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_InvalidAddr - \
                FEE_VIRTUAL_PAGE_SIZE);
        #endif
#else
    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        if(!gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].bFee_ImmediateData)
        {
            u32Fee_HdrAddr = gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_HdrAddrIt - \
                (2U *  FEE_VIRTUAL_PAGE_SIZE);
        }
        else
        {
    #endif
            u32Fee_HdrAddr = (gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_InvalidAddr - \
                FEE_VIRTUAL_PAGE_SIZE);
    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        }
    #endif
#endif

        if( Fls_Write( u32Fee_HdrAddr, gFee_DataBuffer, FEE_VIRTUAL_PAGE_SIZE)  != \
            (Std_ReturnType)E_OK )
        {
            eFee_RetVal = MEMIF_JOB_FAILED;  
        }
        else
        {
            eFee_RetVal = MEMIF_JOB_PENDING;  
        }
        
        Fee_JobConfig.Fee_Job = FEE_JOB_WRITE_DONE;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif

    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobWriteDone                                              
** 
** 
**  Description      : Used to complete the verification of Fee block.                 
**                                                                            
**  Parameters (in)  : None      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType: MEMIF_JOB_OK                    
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteDone \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    (void)bFee_Valid;
    if (u16Fee_JobBlockIndex >= FEE_NUMBER_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_ReportError( FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        return ( MEMIF_JOB_FAILED);
        FEE_NVM_JOB_ERROR_NOTIFICATION
    }
    else
    {

    }
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_DataAddr = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fee_HdrAddr = 0UL;
    VAR( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex = 0U;

    u8Fee_ClrGrpIndex = gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].u8Fee_ClrGrp;
    
    u32Fee_DataAddr = gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_DataAddrIt;
    u32Fee_HdrAddr = gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_HdrAddrIt;

    #if (FEE_LEGACY_MODE == STD_ON)
    if( (boolean)FALSE == gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].bFee_ImmediateData )
    #endif
    {
        gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_DataAddr = u32Fee_DataAddr;
        gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_InvalidAddr = \
            ( u32Fee_HdrAddr - FEE_VIRTUAL_PAGE_SIZE);
    }
#endif
    gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_BlockStatus = FEE_BLOCK_VALID;

    Fee_JobConfig.Fee_Job = FEE_JOB_DONE;

    return( MEMIF_JOB_OK );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobInvalBlock                                              
** 
** 
**  Description      : Writing the invalid flag to the flash memory 
**                     invalidates the Fee block.                
**                                                                            
**  Parameters (in)  : None      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the write job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the write job.                     
**                     MEMIF_JOB_OK: Fee block is invalid.
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlock \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    (void)bFee_Valid;
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;

    if (u16Fee_JobBlockIndex >= FEE_NUMBER_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_ReportError( FEE_INVALIDATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        eFee_RetVal = MEMIF_JOB_FAILED; 
        FEE_NVM_JOB_ERROR_NOTIFICATION
        return( eFee_RetVal );
    }
    else
    {

    }
    if( FEE_BLOCK_INVALID == gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_BlockStatus )
    {
        Fee_JobConfig.Fee_Job = FEE_JOB_DONE;
        eFee_RetVal = MEMIF_JOB_OK; 
    }
    else 
    {
        #if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_OFF)
        if( FEE_BLOCK_NEVER_WRITTEN != gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_BlockStatus ) 
        {
            Fee_SerializeFlag( gFee_DataBuffer, FEE_INVALIDATED_VALUE );

            if( Fls_Write( gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_InvalidAddr, \
                gFee_DataBuffer, FEE_VIRTUAL_PAGE_SIZE ) != (Std_ReturnType)E_OK )
            {
                eFee_RetVal = MEMIF_JOB_FAILED;   
            }
            else
            {
                eFee_RetVal = MEMIF_JOB_PENDING; 
            }

            Fee_JobConfig.Fee_Job = FEE_JOB_INVAL_BLOCK_DONE;       
        }
        else
		#endif
        {
            gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_BlockStatus = FEE_BLOCK_INVALID;
            Fee_JobConfig.Fee_Job = FEE_JOB_DONE;
            eFee_RetVal = MEMIF_JOB_OK; 
        }
    }
        
    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobInvalBlockDone                                              
** 
** 
**  Description      : The final Fee block is determined to be invalid.                
**                                                                            
**  Parameters (in)  : None      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType: MEMIF_JOB_OK
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlockDone \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    (void)bFee_Valid;
    if (u16Fee_JobBlockIndex >= FEE_NUMBER_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_ReportError( FEE_INVALIDATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        FEE_NVM_JOB_ERROR_NOTIFICATION
        return( MEMIF_JOB_FAILED );
    }
    else
    {

    }
    gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_BlockStatus = FEE_BLOCK_INVALID;

    Fee_JobConfig.Fee_Job = FEE_JOB_DONE;

    return( MEMIF_JOB_OK );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#if (FEE_LEGACY_MODE == STD_OFF)
/*****************************************************************************
** Service Name      : Fee_ReservedAreaWritable                                              
** 
** 
**  Description      : Checks whether the block specified by Fee_JobBlockIndex is writable into the reserved area.
**                                                                            
**  Parameters (in)  : None      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : boolean : TRUE: The block is writable into the reserved area.
**                                FALSE: The block is not writable into the reserved area.
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( boolean, FEE_CODE ) Fee_ReservedAreaWritable( void )
{
    VAR( boolean, AUTOMATIC ) sFee_RetVal = TRUE;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockSize = 0U;
    VAR( uint16, AUTOMATIC ) u16Fee_AlignedBlockSize = 0U;
    VAR( Fls_LengthType, AUTOMATIC ) u32Fee_AvailClrSpace = 0UL;
    VAR( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex = (uint8)0;
    VAR( uint32, AUTOMATIC ) u32Fee_ReservedSpace = 0UL;
    VAR( boolean, AUTOMATIC ) bFee_ImmediateData = (boolean)FALSE;
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    VAR( sint8, AUTOMATIC ) sIsReservedAreaTouched = TRUE;
#endif

    u8Fee_ClrGrpIndex = Fee_GetBlockClusterGrp(u16Fee_JobBlockIndex);
    if(u8Fee_ClrGrpIndex >= FEE_NUMBER_OF_CLUSTER_GROUPS)
    {
        sFee_RetVal = FALSE;
        return sFee_RetVal;
    }
    else
    {
        
    }
    u32Fee_ReservedSpace = gFee_ConfigPtr->Fee_ClusterGroup[u8Fee_ClrGrpIndex].Fee_reservedSize;
    u32Fee_AvailClrSpace = gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_DataAddrIt - \
                     gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_HdrAddrIt;

    u16Fee_BlockSize = Fee_GetBlockSize(u16Fee_JobBlockIndex);

    u16Fee_AlignedBlockSize = Fee_AlignToVirtualPageSize( u16Fee_BlockSize );

    if( (((uint32)u16Fee_AlignedBlockSize) + ( FEE_BLOCK_OVERHEAD * 2U )) > \
        u32Fee_AvailClrSpace )
    {
        sFee_RetVal = FALSE;
    }
    else if( (((uint32)u16Fee_AlignedBlockSize) + (2U * FEE_BLOCK_OVERHEAD) + \
        u32Fee_ReservedSpace) > u32Fee_AvailClrSpace)
    {
        bFee_ImmediateData = Fee_GetBlockImmediate(u16Fee_JobBlockIndex);

    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        sIsReservedAreaTouched = Fee_ReservedAreaTouchedByBlock( u16Fee_JobBlockIndex );
        if( ((boolean)TRUE == bFee_ImmediateData) && (FALSE == sIsReservedAreaTouched ))
    #else
        if( (boolean)TRUE == bFee_ImmediateData )
    #endif
        {
            if(u16Fee_JobBlockIndex >= FEE_MAX_NR_OF_BLOCKS)
            {
                sFee_RetVal = FALSE;
                return sFee_RetVal;
            }
            else
            {
                
            }
            if( (0UL == gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_DataAddr) &&
                (0UL == gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_InvalidAddr)
              )
            {
                sFee_RetVal = TRUE;
            }
            else
            {
                if( (FEE_BLOCK_OVERHEAD + u32Fee_ReservedSpace) >
                    (gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_DataAddr - \
                        (gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_InvalidAddr + FEE_VIRTUAL_PAGE_SIZE)
                    )
                  )
                {
                    sFee_RetVal = FALSE;
                }
                else
                {
                   sFee_RetVal = TRUE;
                }
            }
        }
        else
        {
            sFee_RetVal = FALSE;
        }
    }
    else
    {
        sFee_RetVal = TRUE;
    }

    return sFee_RetVal;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif /* FEE_LEGACY_MODE == STD_OFF */

/*****************************************************************************
** Service Name      : Fee_JobEraseImmediate                                              
** 
** 
**  Description      : Used to erase (pre-allocate) immediate Fee blocks.                
**                                                                            
**  Parameters (in)  : None      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType:
**                     MEMIF_JOB_FAILED: The underlying Fls did not accept the write job.
**                     MEMIF_JOB_PENDING: The underlying Fls accepted the write job. 
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediate \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    (void)bFee_Valid;
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (u16Fee_JobBlockIndex >= FEE_NUMBER_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_ReportError( FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO );
        #endif
        eFee_RetVal = MEMIF_JOB_FAILED;
        FEE_NVM_JOB_ERROR_NOTIFICATION
    }
    else
    {
#endif
    #if (FEE_LEGACY_MODE == STD_OFF)
        #if (FEE_LEGACY_IMM_ERASE_MODE == STD_ON)

        if( FALSE == Fee_ReservedAreaWritable() )
        {
            gFee_BlockInfo[ u16Fee_JobBlockIndex ].Fee_BlockStatus = FEE_BLOCK_INVALID;
            gFee_JobIntClrGrpIt = gFee_ConfigPtr->Fee_BlockConfig[ u16Fee_JobBlockIndex ].u8Fee_ClrGrp; 
            eFee_RetVal = Fee_JobIntSwap();
        }
        else
        {
            eFee_RetVal = Fee_JobInvalBlock(TRUE);
        }
        #else
        if( FALSE == Fee_ReservedAreaWritable() )
        {
            gFee_JobIntClrGrpIt = gFee_ConfigPtr->Fee_BlockConfig[ u16Fee_JobBlockIndex ].u8Fee_ClrGrp;          
            eFee_RetVal = Fee_JobIntSwap();
        }
        else
        {
            Fee_JobConfig.Fee_Job = FEE_JOB_DONE;
        }
        #endif
    #else           
        eFee_RetVal = Fee_JobWriteHdr();
            
        if( Fee_JobConfig.Fee_Job != FEE_JOB_INT_SWAP_CLR_FMT )
        {
            Fee_JobConfig.Fee_Job = FEE_JOB_ERASE_IMMEDIATE_DONE;
        }
    #endif
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    }
#endif

    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"


/*****************************************************************************
** Service Name      : Fee_JobEraseImmediateDone                                              
** 
** 
**  Description      : Complete erasure (pre-allocation) of Fee block.               
**                                                                            
**  Parameters (in)  : None      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType: MEMIF_JOB_OK
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediateDone \
( \
    CONST( boolean, AUTOMATIC ) bFee_Valid \
)
{
    (void)bFee_Valid;
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_OK;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockSize = 0U;
    VAR( uint16, AUTOMATIC ) u16Fee_AlignedBlockSize = 0U;
    VAR( uint16, AUTOMATIC ) u16Fee_ClrGrp = 0U;

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF)
    VAR( Fls_AddressType, AUTOMATIC ) uDataAddr = 0U;
    VAR( Fls_AddressType, AUTOMATIC ) uHdrAddr = 0U;
    VAR( uint8, AUTOMATIC ) uClrGrpIndex = (uint8)0;
#endif

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (u16Fee_JobBlockIndex >= FEE_NUMBER_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_ReportError( FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO );
        #endif
        eFee_RetVal = MEMIF_JOB_FAILED;
        FEE_NVM_JOB_ERROR_NOTIFICATION
    }
    else
    {
#endif
    if (u16Fee_JobBlockIndex >= FEE_NUMBER_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_ReportError( FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO );
        #endif
        eFee_RetVal = MEMIF_JOB_FAILED;
        FEE_NVM_JOB_ERROR_NOTIFICATION
        return ( eFee_RetVal );
    }
    else
    {

    }
    gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_BlockStatus = FEE_BLOCK_INCONSISTENT;
    u16Fee_BlockSize = gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].u16Fee_BlockSize; /*polyspace RTE:IDP*/
    u16Fee_AlignedBlockSize = Fee_AlignToVirtualPageSize( u16Fee_BlockSize );
    u16Fee_ClrGrp = gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].u8Fee_ClrGrp;
    
    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF)
       
        uClrGrpIndex = gFee_ConfigPtr->Fee_BlockConfig[u16Fee_JobBlockIndex].u8Fee_ClrGrp;
        if(uClrGrpIndex >= FEE_NUMBER_OF_CLUSTER_GROUPS)
        {
            #if (FEE_DEV_ERROR_DETECT == STD_ON)
            Fee_ReportError( FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO );
            #endif
            eFee_RetVal = MEMIF_JOB_FAILED;
            FEE_NVM_JOB_ERROR_NOTIFICATION
            return ( eFee_RetVal );
        }
        else
        {
            
        }
        uDataAddr = gFee_ClrGrpInfo[uClrGrpIndex].Fee_DataAddrIt - u16Fee_AlignedBlockSize;
        uHdrAddr = gFee_ClrGrpInfo[uClrGrpIndex].Fee_HdrAddrIt;

        gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_DataAddr = uDataAddr;
        gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_InvalidAddr = (uHdrAddr + FEE_BLOCK_OVERHEAD) - \
                                                              FEE_VIRTUAL_PAGE_SIZE;
    #endif
    gFee_ClrGrpInfo[u16Fee_ClrGrp].Fee_HdrAddrIt += FEE_BLOCK_OVERHEAD;
    gFee_ClrGrpInfo[u16Fee_ClrGrp].Fee_DataAddrIt -= u16Fee_AlignedBlockSize;

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_InvalidAddr = \
        (gFee_ClrGrpInfo[u16Fee_ClrGrp].Fee_HdrAddrIt - FEE_VIRTUAL_PAGE_SIZE);
    gFee_BlockInfo[u16Fee_JobBlockIndex].Fee_DataAddr = \
        gFee_ClrGrpInfo[u16Fee_ClrGrp].Fee_DataAddrIt;
#endif

    Fee_JobConfig.Fee_Job = FEE_JOB_DONE;
    eFee_RetVal = MEMIF_JOB_OK;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    }
#endif

    return ( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobSchedule                                              
** 
** 
**  Description      : Subsequent work.               
**                                                                            
**  Parameters (in)  : None      
**                                                                            
**  Parameters (out) : None                                                                                   
**                                                                            
**  Return value     : MemIf_JobResultType
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobSchedule( void )
{
    VAR( uint8, AUTOMATIC ) u8Fee_Index = 0U;
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = MEMIF_JOB_FAILED;
    static VAR(Fee_Job_info_t, FEE_VAR) gFee_JobTable[] = 
    {
        { FEE_JOB_READ,                        &Fee_JobRead },
        { FEE_JOB_WRITE,                       &Fee_JobWrite },
        { FEE_JOB_WRITE_DATA,                  &Fee_JobWriteData },
        { FEE_JOB_WRITE_UNALIGNED_DATA,        &Fee_JobWriteUnalignedData },
        { FEE_JOB_WRITE_VALIDATE,              &Fee_JobWriteValidate },
        { FEE_JOB_WRITE_DONE,                  &Fee_JobWriteDone },
        { FEE_JOB_INVAL_BLOCK,                 &Fee_JobInvalBlock },
        { FEE_JOB_INVAL_BLOCK_DONE,            &Fee_JobInvalBlockDone },
        { FEE_JOB_ERASE_IMMEDIATE,             &Fee_JobEraseImmediate },
        { FEE_JOB_ERASE_IMMEDIATE_DONE,        &Fee_JobEraseImmediateDone },
        { FEE_JOB_INT_SCAN,                    &Fee_JobIntScan },
        { FEE_JOB_INT_SCAN_CLR_HDR_PARSE,      &Fee_JobIntScanClrHdrParse },
        { FEE_JOB_INT_SCAN_CLR_FMT,            &Fee_JobIntScanClrFmt },
        { FEE_JOB_INT_SCAN_CLR_FMT_DONE,       &Fee_JobIntScanClrFmtDone },
        { FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE,    &Fee_JobIntScanBlockHdrParse },
        { FEE_JOB_INT_SWAP_CLR_FMT,            &Fee_JobIntSwapClrFmt },
        { FEE_JOB_INT_SWAP_BLOCK,              &Fee_JobIntSwapBlock },
        { FEE_JOB_INT_SWAP_DATA_READ,          &Fee_JobIntSwapDataRead },
        { FEE_JOB_INT_SWAP_DATA_WRITE,         &Fee_JobIntSwapDataWrite },
        { FEE_JOB_INT_SWAP_CLR_VLD_DONE,       &Fee_JobIntSwapClrVldDone},
    };

    for (u8Fee_Index = 0;u8Fee_Index < FEE_JOB_MAX_COUNT;u8Fee_Index ++)
    {
        if( Fee_JobConfig.Fee_Job == gFee_JobTable[u8Fee_Index].eFee_Job )
        {
            if( gFee_JobTable[u8Fee_Index].fun != NULL_PTR )
            {
                eFee_RetVal = gFee_JobTable[u8Fee_Index].fun((boolean)TRUE);
                break;
            }
        }
    }
    
    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_SetModeVerify                                              
** 
** 
**  Description      : Development error verification of Fee_SetMode interface.                       
**                                                                            
**  Parameters (in)  : None                             
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FEE_DEV_ERROR_DETECT == STD_ON )
#if(( FEE_SETMODE_API_SUPPORTED == STD_ON ) || defined(__DOXYGEN__))
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_SetModeVerify(void)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;

    /* Specification of Fee Driver : [SWS_Fee_00170] */
    if( MEMIF_BUSY == Fee_JobConfig.Fee_ModuleStatus )
    {
        Fee_ReportRuntimeError(FEE_SETMODE_ID, FEE_E_BUSY)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }

    /* Specification of Fee Driver : [SWS_Fee_00121] */
    if( MEMIF_UNINIT == Fee_JobConfig.Fee_ModuleStatus )
    {
        Fee_ReportError(FEE_SETMODE_ID, FEE_E_UNINIT)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    { 
        /* do nothing */
    }

    return u8Fee_RetVal;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif
#endif
/*****************************************************************************
** Service Name      : Fee_InitVerify                                              
** 
** 
**  Description      : Development error verification of Fee_Init interface.                       
**                                                                            
**  Parameters (in)  : stFee_ConfigPtr: Pointer to flash driver configuration set.                             
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FEE_DEV_ERROR_DETECT == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_InitVerify \
( \
    P2CONST( Fee_ConfigType, AUTOMATIC, FEE_APPL_CONST ) stFee_ConfigPtr \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_VerifyRetVal = E_NOT_OK;

#if(STD_OFF == FEE_PRECOMPILE_SUPPORT)
    if(NULL_PTR == stFee_ConfigPtr)
#else
    if(NULL_PTR != stFee_ConfigPtr)
#endif
    {

    Fee_ReportError(FEE_INIT_ID,FEE_E_PARAM_POINTER)
    u8Fee_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( MEMIF_BUSY == Fee_JobConfig.Fee_ModuleStatus )
    {
        Fee_ReportError(FEE_INIT_ID, FEE_E_BUSY);
        u8Fee_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    } 
    else
    {
        u8Fee_VerifyRetVal = E_OK;
    }

    return u8Fee_VerifyRetVal;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fee_ReadVerify                                              
** 
** 
**  Description      : Development error verification of Fee_Read interface.                       
**                                                                            
**  Parameters (in)  : u16Fee_BlockNumber: Number of logical block, also denoting start
**                                            address of that block in flash memory.
**                     u16Fee_BlockOffset: Read address offset inside the block 
**                     u16Fee_Length: Number of bytes to read                            
**                                                                            
**  Parameters (out) : u8Fee_DataBufferPtr: Pointer to data buffer                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FEE_DEV_ERROR_DETECT == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_ReadVerify \
( \
    VAR( uint16, AUTOMATIC ) u16Fee_BlockNumber,\
    VAR( uint16, AUTOMATIC ) u16Fee_BlockOffset, \
    P2CONST( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_DataBufferPtr, \
    VAR( uint16, AUTOMATIC ) u16Fee_Length \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockIndex = 0xffffU;
	if(gFee_ConfigPtr != NULL)
	{
		u16Fee_BlockIndex = Fee_GetBlockIndex( u16Fee_BlockNumber );
	}
    /* Specification of Fee Driver : [SWS_Fee_00133] */
    if( MEMIF_BUSY == Fee_JobConfig.Fee_ModuleStatus )
    {
        Fee_ReportRuntimeError(FEE_READ_ID, FEE_E_BUSY)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }

    /* Specification of Fee Driver : [SWS_Fee_00122] */
    if( MEMIF_UNINIT == Fee_JobConfig.Fee_ModuleStatus )
    {
        Fee_ReportError(FEE_READ_ID, FEE_E_UNINIT)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Fee Driver : [SWS_Fee_00134] */
    else if( 0xffffU == u16Fee_BlockIndex )
    {
        Fee_ReportError(FEE_READ_ID, FEE_E_INVALID_BLOCK_NO)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Fee Driver : [SWS_Fee_00135] */
    else if( u16Fee_BlockOffset >= gFee_ConfigPtr->Fee_BlockConfig[u16Fee_BlockIndex].u16Fee_BlockSize )
    {
        Fee_ReportError(FEE_READ_ID, FEE_E_INVALID_BLOCK_OFS)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Fee Driver : [SWS_Fee_00136] */
    else if( NULL_PTR == u8Fee_DataBufferPtr )
    {
        Fee_ReportError(FEE_READ_ID, FEE_E_PARAM_POINTER)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Fee Driver : [SWS_Fee_00137] */
    else if(( 0U == u16Fee_Length ) || \
           ((u16Fee_BlockOffset + u16Fee_Length) > gFee_ConfigPtr->Fee_BlockConfig[u16Fee_BlockIndex].u16Fee_BlockSize ))
    {
        Fee_ReportError(FEE_READ_ID, FEE_E_INVALID_BLOCK_LEN)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* do nothing */
    }

    return u8Fee_RetVal;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fee_WriteVerify                                              
** 
** 
**  Description      : Development error verification of Fee_Write interface.                       
**                                                                            
**  Parameters (in)  : u16Fee_BlockNumber: Number of logical block, also denoting start
**                                            ddress of that block in EEPROM.
**                     u8Fee_DataBufferPtr: Pointer to data buffer                             
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FEE_DEV_ERROR_DETECT == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_WriteVerify \
( \
    VAR( uint16, AUTOMATIC ) u16Fee_BlockNumber, \
    P2CONST( uint8, AUTOMATIC, FEE_APPL_DATA ) u8Fee_DataBufferPtr \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockIndex = 0xffffU;
    if(gFee_ConfigPtr != NULL)
    {
    	u16Fee_BlockIndex = Fee_GetBlockIndex( u16Fee_BlockNumber );
    }

    /* Specification of Fee Driver : [SWS_Fee_00144] */
    if( MEMIF_BUSY == Fee_JobConfig.Fee_ModuleStatus )
    {
        Fee_ReportRuntimeError(FEE_WRITE_ID, FEE_E_BUSY)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }

    /* Specification of Fee Driver : [SWS_Fee_00123] */
    if( MEMIF_UNINIT == Fee_JobConfig.Fee_ModuleStatus )
    {
        Fee_ReportError(FEE_WRITE_ID, FEE_E_UNINIT)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Fee Driver : [SWS_Fee_00138] */
    else if( 0xffffU == u16Fee_BlockIndex )
    {

        Fee_ReportError(FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Fee Driver : [SWS_Fee_00139] */
    else if( NULL_PTR == u8Fee_DataBufferPtr )
    {

        Fee_ReportError(FEE_WRITE_ID, FEE_E_PARAM_POINTER)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* do nothing */
    }

    return u8Fee_RetVal;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fee_CancelVerify                                              
** 
** 
**  Description      : Development error verification of Fee_Cancel interface.                       
**                                                                            
**  Parameters (in)  : None                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FEE_DEV_ERROR_DETECT == STD_ON )
#if( FEE_CANCEL_API == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_CancelVerify( void )
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;

    /* Specification of Fee Driver : [SWS_Fee_00184] */
    if((MEMIF_JOB_PENDING == Fee_JobConfig.Fee_JobResult) && (MEMIF_BUSY != Fee_JobConfig.Fee_ModuleStatus))
    {
        Fee_ReportRuntimeError(FEE_CANCEL_ID, FEE_E_INVALID_CANCEL)
        FEE_NVM_JOB_ERROR_NOTIFICATION
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    
    /* Specification of Fee Driver : [SWS_Fee_00124] */
    if( MEMIF_UNINIT == Fee_JobConfig.Fee_ModuleStatus )
    {
        Fee_ReportError(FEE_CANCEL_ID, FEE_E_UNINIT)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* do nothing */
    }

    return u8Fee_RetVal;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif
#endif

/*****************************************************************************
** Service Name      : Fee_InvalidateBlockVerify                                              
** 
** 
**  Description      : Development error verification of Fee_InvalidateBlock interface.                       
**                                                                            
**  Parameters (in)  : u16Fee_BlockNumber: Number of logical block, also denoting start
**                                            address of that block in EEPROM.                          
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FEE_DEV_ERROR_DETECT == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_InvalidateBlockVerify \
( \
    VAR( uint16, AUTOMATIC ) u16Fee_BlockNumber \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockIndex = 0xffffU;
	if(gFee_ConfigPtr != NULL)
	{
		u16Fee_BlockIndex = Fee_GetBlockIndex( u16Fee_BlockNumber );
	}

    /* Specification of Fee Driver : [[SWS_Fee_00145] */
    if( MEMIF_BUSY == Fee_JobConfig.Fee_ModuleStatus )
    {
        Fee_ReportRuntimeError(FEE_INVALIDATEBLOCK_ID, FEE_E_BUSY)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }  

    /* Specification of Fee Driver : [[SWS_Fee_00126] */
    if( MEMIF_UNINIT == Fee_JobConfig.Fee_ModuleStatus )
    {

        Fee_ReportError(FEE_INVALIDATEBLOCK_ID, FEE_E_UNINIT)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Fee Driver : [[SWS_Fee_00140] */
    else if( 0xffffU == u16Fee_BlockIndex )
    {
        Fee_ReportError(FEE_INVALIDATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    } 
    else
    {
        /* do nothing */
    }

    return u8Fee_RetVal;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fee_GetVersionInfoVerify                                              
** 
** 
**  Description      : Development error verification of Fee_GetVersionInfo interface.                       
**                                                                            
**  Parameters (in)  : None                          
**                                                                            
**  Parameters (out) : stFee_VersionInfoPtr: Pointer to standard version information structure.                                                   
**                                                                           
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FEE_DEV_ERROR_DETECT == STD_ON )
#if(( FEE_VERSION_INFO_API == STD_ON ) || defined(__DOXYGEN__))
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_GetVersionInfoVerify \
( \
    P2CONST( Std_VersionInfoType, AUTOMATIC, FEE_APPL_DATA ) stFee_VersionInfoPtr \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;

    /* Specification of Fee Driver : [[SWS_Fee_00147] */
    if( NULL_PTR == stFee_VersionInfoPtr )
    {

        Fee_ReportError(FEE_GETVERSIONINFO_ID, FEE_E_PARAM_POINTER)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* do nothing */
    }

    return u8Fee_RetVal;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif
#endif

/*****************************************************************************
** Service Name      : Fee_EraseImmediateBlockVerify                                              
** 
** 
**  Description      : Development error verification of Fee_EraseImmediateBlock interface.                       
**                                                                            
**  Parameters (in)  : u16Fee_BlockNumber: Number of logical block, also denoting start
**                                            address of that block in EEPROM.                             
**                                                                            
**  Parameters (out) : None                                                      
**                                                                           
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FEE_DEV_ERROR_DETECT == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_EraseImmediateBlockVerify \
( \
    VAR( uint16, AUTOMATIC ) u16Fee_BlockNumber \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockIndex = 0xffffU;
	if(gFee_ConfigPtr != NULL)
	{
		u16Fee_BlockIndex = Fee_GetBlockIndex( u16Fee_BlockNumber );
	}

    /* Specification of Fee Driver : [[SWS_Fee_00146] */
    if( MEMIF_BUSY == Fee_JobConfig.Fee_ModuleStatus )
    {
        Fee_ReportRuntimeError(FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_BUSY)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }

    /* Specification of Fee Driver : [[SWS_Fee_00127] */
    if( MEMIF_UNINIT == Fee_JobConfig.Fee_ModuleStatus )
    {

        Fee_ReportError(FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_UNINIT)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Fee Driver : [[SWS_Fee_00068] */
    else if( 0xffffU == u16Fee_BlockIndex )
    {

        Fee_ReportError(FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Fee Driver : [[SWS_Fee_00068] */
    else if( gFee_ConfigPtr->Fee_BlockConfig[u16Fee_BlockIndex].bFee_ImmediateData == \
        (boolean)FALSE)
    {

        Fee_ReportError(FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO)
        u8Fee_RetVal = (Std_ReturnType)E_NOT_OK;
    }    
    else
    {
        /* do nothing */
    }

    return u8Fee_RetVal;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fee_GetRunTimeInfoVerify                                              
** 
** 
**  Description      : Development error verification of Fee_GetRunTimeInfo interface.                       
**                                                                            
**  Parameters (in)  : u8Fee_ClrGrpIndex: The index of the selected selection group.                               
**                                                                            
**  Parameters (out) : None                                                      
**                                                                           
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FEE_DEV_ERROR_DETECT == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_GetRunTimeInfoVerify \
( \
    VAR( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_VerifyRetVal = (Std_ReturnType)E_OK;

    if( MEMIF_UNINIT == Fee_JobConfig.Fee_ModuleStatus )
    {

        Fee_ReportError(FEE_GETRUNTIMEINFO_ID, FEE_E_UNINIT)
        u8Fee_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( MEMIF_BUSY == Fee_JobConfig.Fee_ModuleStatus )
    {

        Fee_ReportRuntimeError(FEE_GETRUNTIMEINFO_ID, FEE_E_BUSY)
        u8Fee_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( FEE_NUMBER_OF_CLUSTER_GROUPS <= u8Fee_ClrGrpIndex )
    {

        Fee_ReportError(FEE_GETRUNTIMEINFO_ID, FEE_E_CLUSTER_GROUP_IDX)
        u8Fee_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* do nothing */
    }

    return u8Fee_VerifyRetVal;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fee_ForceSwapOnNextWriteVerify                                              
** 
** 
**  Description      : Development error verification of Fee_ForceSwapOnNextWrite interface.                       
**                                                                            
**  Parameters (in)  : clrGrpIndex: The index of the selected selection group.                               
**                                                                            
**  Parameters (out) : None                                                       
**                                                                           
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FEE_DEV_ERROR_DETECT == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( Std_ReturnType, FEE_CODE ) Fee_ForceSwapOnNextWriteVerify \
( \
    VAR( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex \
) 
{ 
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_VerifyRetVal = (Std_ReturnType)E_OK; 

    if( MEMIF_UNINIT == Fee_JobConfig.Fee_ModuleStatus )
    {
        
        Fee_ReportError(FEE_FORCESWAPONNEXTWRITE_ID, FEE_E_UNINIT)
        u8Fee_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( MEMIF_BUSY == Fee_JobConfig.Fee_ModuleStatus )
    {
        
        Fee_ReportRuntimeError(FEE_FORCESWAPONNEXTWRITE_ID, FEE_E_BUSY)
        u8Fee_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( FEE_NUMBER_OF_CLUSTER_GROUPS <= u8Fee_ClrGrpIndex )
    {
        Fee_ReportError(FEE_FORCESWAPONNEXTWRITE_ID, FEE_E_CLUSTER_GROUP_IDX)
        u8Fee_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* do nothing */
    }

    return u8Fee_VerifyRetVal;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
 #endif


/*****************************************************************************
** Service Name      : Fee_JobStateProc                                              
** 
** 
**  Description      : Handling the internal status of the feed                       
**                                                                            
**  Parameters (in)  : Job: The job of the fee selection group.                               
**                                                                            
**  Parameters (out) : None                                                       
**                                                                           
**  Return value     : void
**
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FEE_INLINE FUNC( void, FEE_CODE ) Fee_JobStateProc \
( \
    VAR( Fee_Job_Type, AUTOMATIC ) Job \
)
{
    if( FEE_JOB_INT_SCAN == Job )
    {
        Fee_JobConfig.Fee_ModuleStatus = MEMIF_BUSY_INTERNAL;
    }
    else
    {
        Fee_JobConfig.Fee_ModuleStatus = MEMIF_BUSY;
    }

    Fee_JobConfig.Fee_Job = Job;

    Fee_JobConfig.Fee_JobResult = MEMIF_JOB_PENDING;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_Init                                              
** 
** 
**  Description      : Service to initialize the FEE module.                         
**                                                                            
**  Service ID       : 0x00                                                   
**                                                                            
**  Sync/Async       : Asynchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : ConfigPtr: Pointer to the selected configuration set.                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
/* Specification of Fee Driver : [SWS_Fee_00085] */
/* Specification of Fee Driver : [SWS_Fee_00168] */
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( void, FEE_CODE ) Fee_Init \
( \
    P2CONST(Fee_ConfigType, FEE_VAR, FEE_APPL_CONST) ConfigPtr \
)
{ 
    VAR( uint32, AUTOMATIC ) u32Fee_InvalIndex = 0U;
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = E_OK;
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    u8Fee_RetVal = Fee_InitVerify(ConfigPtr);
#endif

    if(u8Fee_RetVal == (Std_ReturnType)E_OK)
    {
        for (u32Fee_InvalIndex = 0;u32Fee_InvalIndex < 
            FEE_NUMBER_OF_CLUSTER_GROUPS; u32Fee_InvalIndex++)
        {
            gFee_ClrGrpInfo[u32Fee_InvalIndex].Fee_ActClrID = 0U;
        }

        for (u32Fee_InvalIndex = 0;u32Fee_InvalIndex < \
            FEE_NUMBER_OF_BLOCKS; u32Fee_InvalIndex++)
        {
    #if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_ON)
            gFee_BlockInfo[u32Fee_InvalIndex].Fee_BlockStatus = FEE_BLOCK_INVALID;
    #else
            gFee_BlockInfo[u32Fee_InvalIndex].Fee_BlockStatus = FEE_BLOCK_NEVER_WRITTEN;
    #endif

    #if (FEE_LEGACY_MODE == STD_OFF)
            gFee_BlockInfo[u32Fee_InvalIndex].Fee_DataAddr = 0U;
            gFee_BlockInfo[u32Fee_InvalIndex].Fee_InvalidAddr = 0U;
    #endif
        }

    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        for( u32Fee_InvalIndex = 0U; u32Fee_InvalIndex < \
            (FEE_MAX_NR_OF_BLOCKS - FEE_NUMBER_OF_BLOCKS); u32Fee_InvalIndex++ )
        {
            Fee_ForeignBlockConfig[u32Fee_InvalIndex].u16Fee_BlockNumber = 0U;
            Fee_ForeignBlockConfig[u32Fee_InvalIndex].u16Fee_BlockSize = 0U;
            Fee_ForeignBlockConfig[u32Fee_InvalIndex].u8Fee_ClrGrp = 0U;
            Fee_ForeignBlockConfig[u32Fee_InvalIndex].bFee_ImmediateData = (boolean)FALSE;
            Fee_ForeignBlockConfig[u32Fee_InvalIndex].eFee_blockAssignment = FEE_PROJECT_RESERVED;
        }
    #endif

    #if (FEE_PRECOMPILE_SUPPORT == STD_ON)
        gFee_ConfigPtr = &Fee_Config;
        (void) ConfigPtr;
    #else 
        gFee_ConfigPtr = ConfigPtr;
    #endif

    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) && (FEE_LEGACY_MODE == STD_OFF)
        for( u32Fee_InvalIndex = 0UL; u32Fee_InvalIndex < \
            (sizeof( Fee_aReservedAreaTouched ) / sizeof( *Fee_aReservedAreaTouched )); \
            u32Fee_InvalIndex++ )
        {
            Fee_aReservedAreaTouched[ u32Fee_InvalIndex ] = 0x00000000UL;
        }
    #endif

        Fee_JobStateProc(FEE_JOB_INT_SCAN);

    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)   
            u16Fee_ForeignBlocksNumber = 0U;
    #endif
    }
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_SetMode                                              
** 
** 
**  Description      : Service to call the Fls_SetMode function of 
**                     the underlying flash driver.                         
**                                                                            
**  Service ID       : 0x01                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : Mode: Desired mode for the underlying flash driver                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
/* Specification of Fee Driver : [SWS_Fee_00086] */
/* Specification of Fee Driver : [SWS_Fee_00087] */
/* Specification of Fee Driver : [SWS_Fee_00190] */
/* Specification of Fee Driver : [SWS_Fee_00191] */
#if(( FEE_SETMODE_API_SUPPORTED == STD_ON ) || defined(__DOXYGEN__))
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( void, FEE_CODE ) Fee_SetMode \
( \
    VAR( MemIf_ModeType, AUTOMATIC) Mode \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    u8Fee_RetVal = Fee_SetModeVerify();
#endif

    if( u8Fee_RetVal == (Std_ReturnType)E_OK)
    {
        if( (Fee_JobConfig.Fee_ModuleStatus == MEMIF_IDLE) || 
        (Fee_JobConfig.Fee_ModuleStatus == MEMIF_BUSY_INTERNAL) )
        {
            Fls_SetMode( Mode );
        }
    }
} 
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fee_Read                                              
** 
** 
**  Description      : Service to initiate a read job.                       
**                                                                            
**  Service ID       : 0x02                                                   
**                                                                            
**  Sync/Async       : Asynchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : BlockNumber: Number of logical block, also denoting start
**                                  address of that block in flash memory.
**                     BlockOffset: Read address offset inside the block 
**                     Length: Number of bytes to read                               
**                                                                            
**  Parameters (out) : DataBufferPtr: Pointer to data buffer                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK: The requested job has been 
**                                           accepted by the module.
**                                     E_NOT_OK: The requested job has not 
**                                               been accepted by the module.                                                  
**                                                                            
******************************************************************************/
/* Specification of Fee Driver : [SWS_Fee_00087] */
/* Specification of Fee Driver : [SWS_Fee_00021] */
/* Specification of Fee Driver : [SWS_Fee_00022] */
/* Specification of Fee Driver : [SWS_Fee_00172] */
/* Specification of Fee Driver : [SWS_Fee_00073] */
/* Specification of Fee Driver : [SWS_Fee_00162] */
/* Specification of Fee Driver : [SWS_Fee_00187] */
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( Std_ReturnType, FEE_CODE ) Fee_Read \
( \
    VAR( uint16, AUTOMATIC ) BlockNumber, \
    VAR( uint16, AUTOMATIC ) BlockOffset, \
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) DataBufferPtr, \
    VAR( uint16, AUTOMATIC ) Length \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockIndex = 0U;

    SchM_Enter_Fee_EXCLUSIVE_AREA_00();
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    u8Fee_RetVal = Fee_ReadVerify( BlockNumber, BlockOffset, DataBufferPtr, Length );
#endif

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    if ( u8Fee_RetVal == (Std_ReturnType)E_OK )
#else
    if( Fee_JobConfig.Fee_ModuleStatus == MEMIF_IDLE || 
    Fee_JobConfig.Fee_ModuleStatus == MEMIF_BUSY_INTERNAL)
#endif 
    {
    	u16Fee_BlockIndex = Fee_GetBlockIndex( BlockNumber );

        u16Fee_JobBlockIndex = u16Fee_BlockIndex;       

        u16Fee_JobBlockOffset = BlockOffset;

        u16Fee_JobBlockLength = Length;

        gFee_JobDataDestPtr = DataBufferPtr;

        Fee_JobStateProc( FEE_JOB_READ );
    }

    SchM_Exit_Fee_EXCLUSIVE_AREA_00();

    return( u8Fee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_Write                                              
** 
** 
**  Description      : Service to initiate a write job.                       
**                                                                            
**  Service ID       : 0x03                                                   
**                                                                            
**  Sync/Async       : Asynchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : BlockNumber: Number of logical block, also denoting start
**                                  address of that block in EEPROM.
**                     DataBufferPtr: Pointer to data buffer                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK: The requested job has been 
**                                           accepted by the module.
**                                     E_NOT_OK: The requested job has not 
**                                               been accepted by the module.                                                  
**                                                                            
******************************************************************************/
/* Specification of Fee Driver : [SWS_Fee_00088] */
/* Specification of Fee Driver : [SWS_Fee_00024] */
/* Specification of Fee Driver : [SWS_Fee_00025] */
/* Specification of Fee Driver : [SWS_Fee_00174] */
/* Specification of Fee Driver : [SWS_Fee_00026] */
/* Specification of Fee Driver : [SWS_Fee_00163] */
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( Std_ReturnType, FEE_CODE ) Fee_Write \
( \
    VAR( uint16, AUTOMATIC ) BlockNumber, \
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) DataBufferPtr \
) 
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockIndex = 0U;

    SchM_Enter_Fee_EXCLUSIVE_AREA_01();
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    u8Fee_RetVal = Fee_WriteVerify( BlockNumber, DataBufferPtr );
#endif

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    if ( u8Fee_RetVal == (Std_ReturnType)E_OK )
#else
    if( Fee_JobConfig.Fee_ModuleStatus == MEMIF_IDLE || 
    Fee_JobConfig.Fee_ModuleStatus == MEMIF_BUSY_INTERNAL)
#endif
    {
    	u16Fee_BlockIndex = Fee_GetBlockIndex( BlockNumber );

        u16Fee_JobBlockIndex = u16Fee_BlockIndex;

        gFee_JobDataDestPtr = DataBufferPtr;

        Fee_JobStateProc(FEE_JOB_WRITE);
    }

    SchM_Exit_Fee_EXCLUSIVE_AREA_01();

    return( u8Fee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_Cancel                                              
** 
** 
**  Description      : Service to call the cancel function of the underlying flash driver.                       
**                                                                            
**  Service ID       : 0x04                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : None                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                  
**                                                                            
******************************************************************************/
/* Specification of Fee Driver : [SWS_Fee_00089] */
/* Specification of Fee Driver : [SWS_Fee_00080] */
/* Specification of Fee Driver : [SWS_Fee_00081] */
/* Specification of Fee Driver : [SWS_Fee_00164] */
/* Specification of Fee Driver : [SWS_Fee_00184] */
#if( FEE_CANCEL_API == STD_ON )
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( void, FEE_CODE ) Fee_Cancel( void )
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    u8Fee_RetVal = Fee_CancelVerify();
#endif

    if( u8Fee_RetVal == (Std_ReturnType)E_OK )
    {
        Fee_JobConfig.Fee_JobResult = MEMIF_JOB_CANCELED;
        Fee_JobConfig.Fee_Job = FEE_JOB_DONE;
        Fls_Cancel();
        Fee_JobConfig.Fee_ModuleStatus = MEMIF_IDLE;
    }
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fee_GetStatus                                              
** 
** 
**  Description      : Service to return the status.                       
**                                                                            
**  Service ID       : 0x05                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : None                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : MemIf_StatusType: MEMIF_UNINIT: The FEE module has not been initialized.
**                                       MEMIF_IDLE: The FEE module is currently idle.
**                                       MEMIF_BUSY: The FEE module is currently busy.
**                                       MEMIF_BUSY_INTERNAL: The FEE module is busy with 
**                                                            internal management operations.                                                   
**                                                                            
******************************************************************************/
/* Specification of Fee Driver : [SWS_Fee_00090] */
/* Specification of Fee Driver : [SWS_Fee_00034] */
/* Specification of Fee Driver : [SWS_Fee_00128] */
/* Specification of Fee Driver : [SWS_Fee_00129] */
/* Specification of Fee Driver : [SWS_Fee_00074] */
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( MemIf_StatusType, FEE_CODE ) Fee_GetStatus( void ) 
{
    return( Fee_JobConfig.Fee_ModuleStatus );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_GetJobResult                                              
** 
** 
**  Description      : Service to query the result of the last accepted job 
**                     issued by the upper layer software.                       
**                                                                            
**  Service ID       : 0x06                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : None                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : MemIf_StatusType: MEMIF_JOB_OK: The last job has been finished successfully.
**                                       MEMIF_JOB_PENDING: The last job is waiting for execution 
**                                                          or currently being executed.
**                                       MEMIF_JOB_CANCELED: The last job has been canceled 
**                                                           (which means it failed).
**                                       MEMIF_JOB_FAILED: The last job has not been finished 
**                                                         successfully (it failed). 
**                                       MEMIF_BLOCK_INCONSISTENT: The requested block is inconsistent, 
**                                                                 it may contain corrupted data. 
**                                       MEMIF_BLOCK_INVALID: The requested block has been invalidated, 
**                                                            the requested read operation can not be 
**                                                            performed.                                                  
**                                                                            
******************************************************************************/
/* Specification of Fee Driver : [SWS_Fee_00091] */
/* Specification of Fee Driver : [SWS_Fee_00035] */
/* Specification of Fee Driver : [SWS_Fee_00156] */
/* Specification of Fee Driver : [SWS_Fee_00157] */
/* Specification of Fee Driver : [SWS_Fee_00158] */
/* Specification of Fee Driver : [SWS_Fee_00159] */
/* Specification of Fee Driver : [SWS_Fee_00160] */
/* Specification of Fee Driver : [SWS_Fee_00155] */
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( MemIf_JobResultType, FEE_CODE ) Fee_GetJobResult( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eFee_RetVal = Fee_JobConfig.Fee_JobResult;

    /* Specification of Fee Driver : [SWS_Fee_00125] */
    if( Fee_JobConfig.Fee_ModuleStatus == MEMIF_UNINIT )
    {
        #if( FEE_DEV_ERROR_DETECT == STD_ON )
        Fee_ReportError(FEE_GETJOBRESULT_ID, FEE_E_UNINIT)
        #endif
        eFee_RetVal = MEMIF_JOB_FAILED;
    }    

    return( eFee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_InvalidateBlock                                              
** 
** 
**  Description      : Service to invalidate a logical block.                       
**                                                                            
**  Service ID       : 0x07                                                   
**                                                                            
**  Sync/Async       : Asynchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : BlockNumber: Number of logical block, also denoting start
**                                  address of that block in EEPROM.                             
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK: The requested job has been 
**                                           accepted by the module.
**                                     E_NOT_OK - only if DET is enabled: 
**                                               The requested job has not 
**                                               been accepted by the module.                                                  
**                                                                            
******************************************************************************/
/* Specification of Fee Driver : [SWS_Fee_00092] */
/* Specification of Fee Driver : [SWS_Fee_00036] */
/* Specification of Fee Driver : [SWS_Fee_00037] */
/* Specification of Fee Driver : [SWS_Fee_00192] */
/* Specification of Fee Driver : [SWS_Fee_00193] */
/* Specification of Fee Driver : [SWS_Fee_00165] */
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( Std_ReturnType, FEE_CODE ) Fee_InvalidateBlock \
( \
    VAR( uint16, AUTOMATIC ) BlockNumber \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockIndex = 0U;

    SchM_Enter_Fee_EXCLUSIVE_AREA_02();
#if( FEE_DEV_ERROR_DETECT == STD_ON )
    u8Fee_RetVal = Fee_InvalidateBlockVerify(BlockNumber );
#endif

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    if ( u8Fee_RetVal == (Std_ReturnType)E_OK )
#else
    if( Fee_JobConfig.Fee_ModuleStatus == MEMIF_IDLE || 
    Fee_JobConfig.Fee_ModuleStatus == MEMIF_BUSY_INTERNAL)
#endif  
    {
    	u16Fee_BlockIndex = Fee_GetBlockIndex( BlockNumber );

        u16Fee_JobBlockIndex = u16Fee_BlockIndex;

        Fee_JobStateProc(FEE_JOB_INVAL_BLOCK);
    }

    SchM_Exit_Fee_EXCLUSIVE_AREA_02();

    return( u8Fee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_GetVersionInfo                                              
** 
** 
**  Description      : Service to return the version information of the FEE module.                       
**                                                                            
**  Service ID       : 0x08                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                          
**                                                                            
**  Parameters (in)  : None                               
**                                                                            
**  Parameters (out) : VersioninfoPtr: Pointer to standard version information structure.                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
/* Specification of Fee Driver : [SWS_Fee_00093] */
#if(( FEE_VERSION_INFO_API == STD_ON ) || defined(__DOXYGEN__))
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( void, FEE_CODE ) Fee_GetVersionInfo \
( \
    P2VAR( Std_VersionInfoType, AUTOMATIC, FEE_APPL_DATA ) VersionInfoPtr \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    u8Fee_RetVal = Fee_GetVersionInfoVerify(VersionInfoPtr);
#endif

    if( u8Fee_RetVal == (Std_ReturnType)E_OK )
    {
    	VersionInfoPtr->moduleID = (uint16)FEE_MODULE_ID_PLUGIN;
    	VersionInfoPtr->vendorID = (uint16)FEE_C_VENDOR_ID_PLUGIN;
    	VersionInfoPtr->sw_major_version = (uint8)FEE_C_SW_MAJOR_VER;
    	VersionInfoPtr->sw_minor_version = (uint8)FEE_C_SW_MINOR_VER;
    	VersionInfoPtr->sw_patch_version = (uint8)FEE_C_SW_PATCH_VER;
    }
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fee_EraseImmediateBlock                                              
** 
** 
**  Description      : Service to erase a logical block.                       
**                                                                            
**  Service ID       : 0x09                                                   
**                                                                            
**  Sync/Async       : Asynchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : BlockNumber: Number of logical block, also denoting start
**                                  address of that block in EEPROM.                             
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK: The requested job has been 
**                                           accepted by the module.
**                                     E_NOT_OK - only if DET is enabled: 
**                                               The requested job has not 
**                                               been accepted by the module.                                                  
**                                                                            
******************************************************************************/
/* Specification of Fee Driver : [SWS_Fee_00094] */
/* Specification of Fee Driver : [SWS_Fee_00066] */
/* Specification of Fee Driver : [SWS_Fee_00067] */
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( Std_ReturnType, FEE_CODE ) Fee_EraseImmediateBlock \
( \
    VAR( uint16, AUTOMATIC ) BlockNumber \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;
    VAR( uint16, AUTOMATIC ) u16Fee_BlockIndex = 0U;

    SchM_Enter_Fee_EXCLUSIVE_AREA_03();

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    u8Fee_RetVal = Fee_EraseImmediateBlockVerify(BlockNumber);
#endif

    if( u8Fee_RetVal == (Std_ReturnType)E_OK )
    {
    	u16Fee_BlockIndex = Fee_GetBlockIndex( BlockNumber );

        u16Fee_JobBlockIndex = u16Fee_BlockIndex;

        Fee_JobStateProc(FEE_JOB_ERASE_IMMEDIATE);
    }

    SchM_Exit_Fee_EXCLUSIVE_AREA_03();

    return( u8Fee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobEndNotification                                              
** 
** 
**  Description      : Service to report to this module the successful end of
**                     an asynchronous operation.                      
**                                                                            
**  Service ID       : 0x10                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : None                             
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                  
**                                                                            
******************************************************************************/
/* Specification of Fee Driver : [SWS_Fee_00052] */
/* Specification of Fee Driver : [[SWS_Fee_00142] */
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( void, FEE_CODE ) Fee_JobEndNotification( void )
{
    if( FEE_JOB_DONE != Fee_JobConfig.Fee_Job )
    {        
        Fee_JobConfig.Fee_JobResult = Fee_JobSchedule();

        if( MEMIF_JOB_OK == Fee_JobConfig.Fee_JobResult )
        {
            if( MEMIF_BUSY_INTERNAL != Fee_JobConfig.Fee_ModuleStatus )
            {
                Fee_JobConfig.Fee_ModuleStatus = MEMIF_IDLE;
                FEE_NVM_JOB_END_NOTIFICATION
            }
            else
            {
                Fee_JobConfig.Fee_ModuleStatus = MEMIF_IDLE;
            }
        }
        else if( MEMIF_JOB_PENDING == Fee_JobConfig.Fee_JobResult )
        {
            /* Nothing to do (ongoing Fls job) */
        }
        else
        {
            if( MEMIF_BUSY_INTERNAL != Fee_JobConfig.Fee_ModuleStatus )
            {
                Fee_JobConfig.Fee_ModuleStatus = MEMIF_IDLE;
                FEE_NVM_JOB_ERROR_NOTIFICATION
            }
            else
            {
                Fee_JobConfig.Fee_ModuleStatus = MEMIF_IDLE;
            }
        }
    }
    else
    {
        Fee_JobConfig.Fee_JobResult = Fls_GetJobResult();
        
        if( MEMIF_BUSY_INTERNAL != Fee_JobConfig.Fee_ModuleStatus )
        {
            Fee_JobConfig.Fee_ModuleStatus = MEMIF_IDLE;
            FEE_NVM_JOB_END_NOTIFICATION
        }
        else
        {
            Fee_JobConfig.Fee_ModuleStatus = MEMIF_IDLE;
        }
    }
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_JobErrorNotification                                              
** 
** 
**  Description      : Service to report to this module the failure of an 
**                     asynchronous operation.                      
**                                                                            
**  Service ID       : 0x11                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : None                             
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                  
**                                                                            
******************************************************************************/
/* Specification of Fee Driver : [SWS_Fee_00096] */
/* Specification of Fee Driver : [SWS_Fee_00054] */
/* Specification of Fee Driver : [SWS_Fee_00143] */
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( void, FEE_CODE ) Fee_JobErrorNotification( void )
{
	VAR( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex = 0U;
    VAR( boolean, AUTOMATIC ) bFee_NotifiFlag = (boolean)FALSE; 

    if( MEMIF_JOB_CANCELED != Fee_JobConfig.Fee_JobResult )
    {

        switch ( Fee_JobConfig.Fee_Job )
        {
            case FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE:
            {
                Fee_JobConfig.Fee_JobResult = Fee_JobIntScanBlockHdrParse((boolean) FALSE );
                break;
            }
            case FEE_JOB_INT_SCAN_CLR_HDR_PARSE:
            {
                Fee_JobConfig.Fee_JobResult = Fee_JobIntScanClrHdrParse((boolean) FALSE );
                break;
            }
            case FEE_JOB_INT_SWAP_DATA_WRITE:
            {
                Fee_JobConfig.Fee_JobResult = Fee_JobIntSwapDataWrite((boolean) FALSE );
                break;
            }
            case FEE_JOB_WRITE:
            case FEE_JOB_WRITE_DATA:
            case FEE_JOB_WRITE_UNALIGNED_DATA:
            case FEE_JOB_ERASE_IMMEDIATE:
            case FEE_JOB_ERASE_IMMEDIATE_DONE:
            case FEE_JOB_WRITE_VALIDATE:
            case FEE_JOB_WRITE_DONE:
            {
				u8Fee_ClrGrpIndex = Fee_GetBlockClusterGrp(u16Fee_JobBlockIndex);
                gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_DataAddrIt = \
                    gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_HdrAddrIt + (2U * FEE_BLOCK_OVERHEAD );/* polyspace RTE:OBAI */
                bFee_NotifiFlag = (boolean)TRUE;
                break; 
                
            }
            case FEE_JOB_READ:
            case FEE_JOB_INVAL_BLOCK:
            case FEE_JOB_INVAL_BLOCK_DONE:
            case FEE_JOB_INT_SCAN:
            case FEE_JOB_INT_SCAN_CLR:
            case FEE_JOB_INT_SCAN_CLR_FMT:
            case FEE_JOB_INT_SCAN_CLR_FMT_DONE:
            case FEE_JOB_INT_SWAP_BLOCK:
            case FEE_JOB_INT_SWAP_CLR_FMT:
            case FEE_JOB_INT_SWAP_DATA_READ:
            case FEE_JOB_INT_SWAP_CLR_VLD_DONE:
            case FEE_JOB_DONE:
            {
                bFee_NotifiFlag = (boolean)TRUE; 
                break;
            }
            default:
            {
                /* do nothing */
                break;
            }
        }

        if ( bFee_NotifiFlag == (boolean)TRUE)
        {
            Fee_JobConfig.Fee_JobResult = Fls_GetJobResult();

            if( MEMIF_BUSY_INTERNAL != Fee_JobConfig.Fee_ModuleStatus )
            {
                Fee_JobConfig.Fee_ModuleStatus = MEMIF_IDLE;
                FEE_NVM_JOB_ERROR_NOTIFICATION
            }
            else
            {
                Fee_JobConfig.Fee_ModuleStatus = MEMIF_IDLE;
            }
        }  
    }
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_MainFunction                                              
** 
** 
**  Description      : Service to handle the requested read / write / erase 
**                     jobs and the internal management operations.                       
**                                                                            
**  Service ID       : 0x12                                                   
**                                                                            
**  Timing           : ON_PRE_CONDITION                                            
**                                                                            
**  Parameters (in)  : None                               
**                                                                            
**  Parameters (out) : None                                                  
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
/* Specification of Fee Driver : [SWS_Fee_00097] */
/* Specification of Fee Driver : [SWS_Fee_00169] */
/* Specification of Fee Driver : [SWS_Fee_00057] */
/* Specification of Fee Driver : [SWS_Fee_00075] */
/* Specification of Fee Driver : [SWS_Fee_00023] */
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( void, FEE_CODE ) Fee_MainFunction( void )
{
    if( Fee_JobConfig.Fee_JobResult == MEMIF_JOB_PENDING )
    {
        switch ( Fee_JobConfig.Fee_Job )
        {
            case FEE_JOB_INT_SCAN:
            case FEE_JOB_READ:
            case FEE_JOB_WRITE:
            case FEE_JOB_INVAL_BLOCK:
            case FEE_JOB_ERASE_IMMEDIATE:
            {
                Fee_JobConfig.Fee_JobResult = Fee_JobSchedule();
                break;
            }
            default:
            {
                /* do nothing */
                break;
            }
        }
                
        if( Fee_JobConfig.Fee_JobResult == MEMIF_JOB_PENDING )
        {
            /* do nothing */
        }
        else if( MEMIF_JOB_OK == Fee_JobConfig.Fee_JobResult )
        {
            if( MEMIF_BUSY_INTERNAL != Fee_JobConfig.Fee_ModuleStatus )
            {
                Fee_JobConfig.Fee_ModuleStatus = MEMIF_IDLE;
                FEE_NVM_JOB_END_NOTIFICATION
            }
            else
            {
                Fee_JobConfig.Fee_ModuleStatus = MEMIF_IDLE;
            }
        }
        else
        {
            if( MEMIF_BUSY_INTERNAL != Fee_JobConfig.Fee_ModuleStatus )
            {
                Fee_JobConfig.Fee_ModuleStatus = MEMIF_IDLE;
                FEE_NVM_JOB_ERROR_NOTIFICATION
            }
            else
            {
                Fee_JobConfig.Fee_ModuleStatus = MEMIF_IDLE;
            }
        }
    }
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*****************************************************************************
** Service Name      : Fee_GetRunTimeInfo                                              
** 
** 
**  Description      : Used to read runtime information in the selected cluster.                         
**                                                                            
**  Parameters (in)  : u8Fee_ClrGrpIndex: The index of the selected selection group.                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Fee_ClusterGroupRuntimeInfo_Type:
**                     clusterTotalSpace: Total current cluster size
**                     clusterFreeSpace: The available space of the current cluster.
**                     blockHeaderOverhead: Header overhead (header, valid flag and invalid flag)
**                     virtualPageSize: Virtual page size
**                     numberOfSwap: Number of times the cluster exchange has been performed.                                                   
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( Fee_ClusterGroupRuntimeInfo_Type, FEE_CODE ) Fee_GetRunTimeInfo \
( \
    VAR( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex \
) 
{ 
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK;
    VAR( uint32, AUTOMATIC ) u32Fee_ActiveClrIndex = 0UL;
    VAR( Fee_ClusterGroupRuntimeInfo_Type, AUTOMATIC ) sFee_ClrGrpRTInfo= \
        { (Fls_AddressType)0,(Fls_AddressType)0,(uint8)0,(uint8)0,(uint32)0 };
    P2CONST( Fee_ClusterGroup_Type, FEE_CONST, FEE_APPL_CONST ) pFee_Group = \
    gFee_ConfigPtr->Fee_ClusterGroup;   /*polyspace RTE:IDP*/

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    u8Fee_RetVal = Fee_GetRunTimeInfoVerify(u8Fee_ClrGrpIndex);
#endif

    if( u8Fee_RetVal == (Std_ReturnType)E_OK )
    {
        u32Fee_ActiveClrIndex = gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_ActClr;

        sFee_ClrGrpRTInfo.u32Fee_ClusterTotalSpace = \
            pFee_Group[u8Fee_ClrGrpIndex].Fee_ClrPtr[u32Fee_ActiveClrIndex].Fee_Length;

        sFee_ClrGrpRTInfo.u32Fee_ClusterFreeSpace = \
            (gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_DataAddrIt - \
            (gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_HdrAddrIt + FEE_BLOCK_OVERHEAD));

        sFee_ClrGrpRTInfo.u8Fee_BlockHeaderOverhead  = FEE_CLUSTER_OVERHEAD; 

        sFee_ClrGrpRTInfo.u8Fee_VirtualPageSize = FEE_VIRTUAL_PAGE_SIZE; 

        sFee_ClrGrpRTInfo.u32Fee_NumberOfSwap = \
            gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_ActClrID - 1U;
    }

    return (sFee_ClrGrpRTInfo); 
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"


/*****************************************************************************
** Service Name      : Fee_ForceSwapOnNextWrite                                              
** 
** 
**  Description      : Used to prepare drivers for cluster exchange in the 
**                     selected cluster group.                         
**                                                                            
**  Parameters (in)  : u8Fee_ClrGrpIndex: The index of the selected selection group.                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK: There is no more space available 
**                                     in the selected cluster.
**                                     E_NOT_OK: The module is uninitialized, busy, 
**                                     or u8Fee_ClrGrpIndex is not in the valid range.
**                                                                            
******************************************************************************/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
FUNC( Std_ReturnType, FEE_CODE ) Fee_ForceSwapOnNextWrite \
( \
    VAR( uint8, AUTOMATIC ) u8Fee_ClrGrpIndex \
) 
{ 
    VAR( Std_ReturnType, AUTOMATIC ) u8Fee_RetVal = (Std_ReturnType)E_OK; 

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    u8Fee_RetVal = Fee_ForceSwapOnNextWriteVerify(u8Fee_ClrGrpIndex);
#endif

    if( u8Fee_RetVal == (Std_ReturnType)E_OK )
    {
        gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_DataAddrIt = \
            gFee_ClrGrpInfo[u8Fee_ClrGrpIndex].Fee_HdrAddrIt + (2U * FEE_BLOCK_OVERHEAD ); 
    }

    return( u8Fee_RetVal );
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif

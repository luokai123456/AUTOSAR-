/* PRQA S 3332, 0722 EOF */
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
*   @file    Fee_Types.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FEE MCAL driver.
*
*   @addtogroup FEE
*   @{
*/

#ifndef FEE_TYPES_H
#define FEE_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
#include "Fls.h"

#define FEE_TYP_WRA_H_VENDOR_ID                     176
#define FEE_MODULE_ID_PLUGIN                        21
#define FEE_TYP_WRA_H_AR_REL_MAJOR_VER              4
#define FEE_TYP_WRA_H_AR_REL_MINOR_VER              4
#define FEE_TYP_WRA_H_AR_REL_REV_VER                0
#define FEE_TYP_WRA_H_SW_MAJOR_VER                  3
#define FEE_TYP_WRA_H_SW_MINOR_VER                  0
#define FEE_TYP_WRA_H_SW_PATCH_VER                  0

#if (MCAL_VENDOR_ID != FEE_TYP_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : FEE_TYP_WRA_H_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != FEE_TYP_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : FEE_TYP_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != FEE_TYP_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : FEE_TYP_WRA_H_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != FEE_TYP_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : FEE_TYP_WRA_H_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != FEE_TYP_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : FEE_TYP_WRA_H_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != FEE_TYP_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : FEE_TYP_WRA_H_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != FEE_TYP_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : FEE_TYP_WRA_H_SW_PATCH_VER "
#endif

typedef struct 
{ 
    VAR(Fls_AddressType, AUTOMATIC)  u32Fee_ClusterTotalSpace;
    VAR(Fls_AddressType, AUTOMATIC)  u32Fee_ClusterFreeSpace;
    VAR(uint32, AUTOMATIC)            u8Fee_BlockHeaderOverhead;
    VAR(uint32, AUTOMATIC)            u8Fee_VirtualPageSize;
    VAR(uint32, AUTOMATIC)           u32Fee_NumberOfSwap;
} Fee_ClusterGroupRuntimeInfo_Type; 

typedef enum 
{
    FEE_PROJECT_SHARED          = 0x01,
    FEE_PROJECT_APPLICATION     = 0x02,
    FEE_PROJECT_BOOTLOADER      = 0x03,
    FEE_PROJECT_RESERVED        = 0xFF 
} Fee_BlockAssignmentType;

typedef struct 
{
    VAR(uint16, AUTOMATIC) u16Fee_BlockNumber;
    VAR(uint16, AUTOMATIC) u16Fee_BlockSize;
    VAR(uint8, AUTOMATIC)  u8Fee_ClrGrp;
    VAR(boolean, AUTOMATIC) bFee_ImmediateData;
    VAR(Fee_BlockAssignmentType, AUTOMATIC) eFee_blockAssignment;  
} Fee_BlockConfig_Type;

typedef struct 
{
    VAR(Fls_AddressType, AUTOMATIC) Fee_StartAddr;
    VAR(Fls_LengthType, AUTOMATIC) Fee_Length;
} Fee_Cluster_Type;

typedef struct 
{
    CONSTP2CONST( Fee_Cluster_Type, FEE_CONST, FEE_APPL_CONST ) Fee_ClrPtr; 
    VAR(uint32, AUTOMATIC) Fee_ClrCount;
    VAR(uint32, AUTOMATIC) Fee_reservedSize;
} Fee_ClusterGroup_Type;


typedef enum
{    
    FEE_CLUSTER_VALID ,      
    FEE_CLUSTER_INVALID,
    FEE_CLUSTER_INCONSISTENT,
    FEE_CLUSTER_HEADER_INVALID 
} Fee_ClusterStatus_Type;

typedef enum
{
    FEE_JOB_READ ,
    FEE_JOB_WRITE,    
    FEE_JOB_WRITE_DATA,
    FEE_JOB_WRITE_UNALIGNED_DATA,
    FEE_JOB_WRITE_VALIDATE,      
    FEE_JOB_WRITE_DONE,     
    FEE_JOB_INVAL_BLOCK, 
    FEE_JOB_INVAL_BLOCK_DONE,
    FEE_JOB_ERASE_IMMEDIATE,   
    FEE_JOB_ERASE_IMMEDIATE_DONE,  
    FEE_JOB_INT_SCAN,         
    FEE_JOB_INT_SCAN_CLR_HDR_PARSE,   
    FEE_JOB_INT_SCAN_CLR,  
    FEE_JOB_INT_SCAN_CLR_FMT,      
    FEE_JOB_INT_SCAN_CLR_FMT_DONE, 
    FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE,
    FEE_JOB_INT_SWAP_BLOCK,  
    FEE_JOB_INT_SWAP_CLR_FMT,
    FEE_JOB_INT_SWAP_DATA_READ, 
    FEE_JOB_INT_SWAP_DATA_WRITE,
    FEE_JOB_INT_SWAP_CLR_VLD_DONE,
    FEE_JOB_DONE
} Fee_Job_Type;

typedef struct 
{
    VAR(Fls_AddressType, AUTOMATIC) Fee_DataAddrIt;
    VAR(Fls_AddressType, AUTOMATIC) Fee_HdrAddrIt;
    VAR(uint32, AUTOMATIC) Fee_ActClrID;
    VAR(uint8, AUTOMATIC) Fee_ActClr;
} Fee_ClusterGroupInfo_Type;

typedef struct 
{
    VAR(Fee_Job_Type, AUTOMATIC) Fee_Job;
    VAR(Fee_Job_Type, AUTOMATIC) Fee_OriginalJob;
    VAR(MemIf_JobResultType, AUTOMATIC) Fee_JobResult;
    VAR(MemIf_StatusType, AUTOMATIC) Fee_ModuleStatus;
} Fee_JobResult_Type;

typedef struct {
    VAR(Fee_Job_Type, AUTOMATIC) eFee_Job;
    MemIf_JobResultType (*fun)(const boolean bFee_Valid);
} Fee_Job_info_t;



#ifdef __cplusplus
}
#endif

#endif /* FEE_TYPES_H */

/** @}*/

/*
********************************************************************************
*
*  File name: Os_Arch_Mach_MP_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: JiangGL/2025.6.25
* Change: New create.
* Cause: New
********************************************************************************
*/
#ifndef OS_ARCH_MACH_MP_TYPES_H_
#define OS_ARCH_MACH_MP_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Init value. */
#define OS_ARCH_MP_INIT                     (0U)
/* Enables the the MPU. */
#define OS_ARCH_CMPU_ENABLE_MASK            (0x2401U)
/* DMEMCTL1 MASK. */
#define OS_ARCH_CMPU_DMEMCTL1_MASK          (0xAAAAAAAAU)
/* Disables the the MPU. */
#define OS_ARCH_CMPU_DISABLE_MASK           (0)
/* Bit mask - MPU Entry valid. */
#define OS_ARCH_CMPU_MAS0_VALID_MSK         (0x80000000U)
/* Bit mask -  Invalidation Protect. */
#define OS_ARCH_CMPU_MAS0_IPROT_MSK         (0x40000000U)
/* Bit mask - Selects MPU for access (2 Bits --> 10). */
#define OS_ARCH_CMPU_MAS0_SEL_MSK           (0x20000000U)
/* Bit mask - Read only - entry is write protected until reset. */
#define OS_ARCH_CMPU_MAS0_RO_MSK            (0x04000000U)
/* Bit mask - Debug Control (Use of debug ). */
#define OS_ARCH_CMPU_MAS0_DBG_MSK           (0x02000000U)
/* Bit mask - Instruction Region Entry. */
#define OS_ARCH_CMPU_MAS0_INST_MSK          (0x01000000U)
/* Bit mask - Shared Entry Select. */
#define OS_ARCH_CMPU_MAS0_SHD_MSK           (0x00800000U)
/* Bit mask - User Mode Write. */
#define OS_ARCH_CMPU_MAS0_UW_MSK            (0x00000800U)
/* Bit mask - Supervisor Mode Write. */
#define OS_ARCH_CMPU_MAS0_SW_MSK            (0x00000400U)
/* Bit mask - User Mode Read and Execute. */
#define OS_ARCH_CMPU_MAS0_URX_MSK           (0x00000200U)
/* Bit mask - Supervisor Mode Read and Execute. */
#define OS_ARCH_CMPU_MAS0_SRX_MSK           (0x00000100U)
/* Bit mask - Cache inhibit override. */
#define OS_ARCH_CMPU_MAS0_IOVR_MSK          (0x00000080U)
/* Bit mask - G Attribute overwrite. */
#define OS_ARCH_CMPU_MAS0_GOVR_MSK          (0x00000040U)
/* Bit mask - Cache inhibit flag. */
#define OS_ARCH_CMPU_MAS0_I_MSK             (0x00000008U)
/* Bit mask - Guarded flag. */
#define OS_ARCH_CMPU_MAS0_G_MSK             (0x00000002U)
/* Bit mask - MPU Disable. */
#define OS_ARCH_CMPU_CSR0_DIS_MASK          (0x00000000U)
/* Bit mask for Entry Select. */
#define OS_ARCH_CMPU_MAS0_ESEL(x)           (((x)&0xFUL) << 16U)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
struct Os_Arch_MpRegionCfg
{
    uint8 Reserved;
};

struct Os_Arch_CoreMpRegionCfg
{
    uint32 mpuRegion;   /* Mpu region number. */
    uint32 mpuMpla;     /* Mpu low address. */
    uint32 mpuMpua;     /* Mpu up address. */
    uint32 mpuMpat;     /* Mpu attribute register. */
};

typedef struct Os_Arch_MpRegionCfg Os_Arch_MpRegionCfgType;
typedef struct Os_Arch_CoreMpRegionCfg Os_Arch_CoreMpRegionCfgType;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* OS_ARCH_MACH_MP_TYPES_H_ */

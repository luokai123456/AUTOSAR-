/*PRQA S 2053 EOF*/
/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Crc_Hw.h
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Crc MCAL driver.
*
*   @addtogroup Crc
*   @{
*/

#ifndef CRC_HW_H
#define CRC_HW_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================
INCLUDE FILES
====================================================================================================*/
#include "Crc.h"
#include "derivative.h"
/*====================================================================================================
HEAD FILE VERSION INFORMATION
====================================================================================================*/
#define CRC_MODULE_ID                        201
#define CRC_HW_VENDOR_ID                     176
#define CRC_HW_AR_MAJOR_VER                  4
#define CRC_HW_AR_MINOR_VER                  4
#define CRC_HW_AR_PATCH_VER                  0
#define CRC_HW_SW_MAJOR_VER                  3
#define CRC_HW_SW_MINOR_VER                  0
#define CRC_HW_SW_PATCH_VER                  0
/*====================================================================================================
FILE VERSION CHECKS
====================================================================================================*/
/* Check if current file and CRC header file are of the same vendor */
#if (CRC_HW_VENDOR_ID != CRC_VENDOR_ID)
#error "NON-MATCHED DATA : CRC_VENDOR_ID"
#endif

/* Check if current file and CRC header file are of the same Autosar version */
#if (CRC_HW_AR_MAJOR_VER != CRC_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : CRC_AR_RELEASE_MAJOR_VERSION"
#endif
#if (CRC_HW_AR_MINOR_VER != CRC_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : CRC_AR_RELEASE_MINOR_VERSION"
#endif
#if (CRC_HW_AR_PATCH_VER != CRC_AR_PATCH_VER)
#error "NON-MATCHED DATA : CRC_AR_PATCH_VER"
#endif

/* Check if current file and CRC header file are of the same Software version */
#if (CRC_HW_SW_MAJOR_VER != CRC_SW_MAJOR_VER)
#error "NON-MATCHED DATA : CRC_SW_MAJOR_VER"
#endif
#if (CRC_HW_SW_MINOR_VER != CRC_SW_MINOR_VER)
#error "NON-MATCHED DATA : CRC_SW_MINOR_VER"
#endif
#if (CRC_HW_SW_PATCH_VER != CRC_SW_PATCH_VER)
#error "NON-MATCHED DATA : CRC_SW_PATCH_VER"
#endif

/*====================================================================================================
DEFINES
====================================================================================================*/

/*====================================================================================================
ENUMS
====================================================================================================*/

typedef  struct CRC_tag                          volatile CRC_tag_Type;
/* CRC - Peripheral instance base addresses */
/** Peripheral CRC_0 base address */
#define CRC_0_BASE                               (0xFFF64000UL)
/** Peripheral CRC_0 base pointer */
#define SAF_CRC_0                                 ((volatile struct CRC_tag *)CRC_0_BASE)
/** Peripheral CRC_1 base address */
#define CRC_1_BASE                               (0xFBF64000UL)
/** Peripheral CRC_1 base pointer */
#define SAF_CRC_1                                 ((volatile struct CRC_tag *)CRC_1_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC_0_BASE, CRC_1_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { SAF_CRC_0, SAF_CRC_1 }

#define CRC_CFG_POLYG_8                          0x00000018U
#define CRC_CFG_POLYG_16                         0x00000010U
#define CRC_CFG_POLYG_32                         0x00000027U

#define CRC_INDEX                                   2



/*====================================================================================================
TYPEDEFS
====================================================================================================*/

/*====================================================================================================
STRUCT
====================================================================================================*/

/*====================================================================================================
FUNCTION DECLARATION
====================================================================================================*/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint8, CRC_CODE) Crc_Hw_CalculateCRC8(VAR(uint8, AUTOMATIC) CrcID,
							     P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                                 VAR(uint32, AUTOMATIC) Crc_Length, 
                                 VAR(uint8, AUTOMATIC) Crc_StartValue );
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_Hw_CalculateCRC16(VAR(uint8, AUTOMATIC) CrcID,
							   P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
								VAR(uint32, AUTOMATIC) Crc_Length,
								VAR(uint16, AUTOMATIC) Crc_StartValue );
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint32, CRC_CODE) Crc_Hw_CalculateCRC32(VAR(uint8, AUTOMATIC) CrcID,
							P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
							VAR(uint32, AUTOMATIC) Crc_Length,
							VAR(uint32, AUTOMATIC) Crc_StartValue );
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE) Crc_Hw_CalculateAsyncCRC8(VAR(uint8, AUTOMATIC) CrcIndex,
							     P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                                 VAR(uint32, AUTOMATIC) Crc_Length,
                                 VAR(uint8, AUTOMATIC) Crc_StartValue );
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE) Crc_Hw_CalculateAsyncCRC16(VAR(uint8, AUTOMATIC) CrcIndex,
								   P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                                   VAR(uint32, AUTOMATIC) Crc_Length,
                                   VAR(uint16, AUTOMATIC) Crc_StartValue );
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE) Crc_Hw_CalculateAsyncCRC32(VAR(uint8, AUTOMATIC) CrcIndex,
								   P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                                   VAR(uint32, AUTOMATIC) Crc_Length,
                                   VAR(uint32, AUTOMATIC) Crc_StartValue );
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE) Crc_AsyncHandle(P2VAR(Crc_ConfigGroupType, AUTOMATIC, CRC_APPL_DATA) CRC_HandlePtr);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE) Crc_TransmitReceive_dma_8(VAR(uint8, AUTOMATIC) CrcIndex ,
                            P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                            VAR(uint32, AUTOMATIC) Crc_Length);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE) Crc_TransmitReceive_dma_16(VAR(uint8, AUTOMATIC) CrcIndex ,
							P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
							VAR(uint32, AUTOMATIC) Crc_Length);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE) Crc_TransmitReceive_dma_32(VAR(uint8, AUTOMATIC) CrcIndex ,
							P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
							VAR(uint32, AUTOMATIC) Crc_Length);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE)Crc_TransmitEndDma(P2VAR(Crc_ConfigGroupType, AUTOMATIC, CRC_APPL_DATA) CRC_HandlePtr);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* CRC_HW_H */

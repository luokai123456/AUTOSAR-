/*
********************************************************************************
*
*  File name: PduR_Buffer.h
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: SunHQ/2022.09.20
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: SunHQ/2023.02.28
* Change: Add the declaration of function PduR_Buffer_GetSpace.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: LuQ/2023.10.17
* Change: Modify the declaration of function PduR_Buffer_Alloc and
*         PduR_Buffer_Get.
* Cause: Buxfix
********************************************************************************
* Version: 3.3
* Author/Date: LuQ/2024.03.18
* Change: Modify P2CONST member labels.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: LuQ/2024.04.02
* Change: 1. Modify the comments format.
*         2. Modify P2CONST member labels.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LuQ/2024.05.13
* Change: Add Memmap segment definition.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LuQ/2024.09.20
* Change: Modify copyright information.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: LuQ/2025.06.23
* Change: Modify the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef PDUR_BUFFER_H_
#define PDUR_BUFFER_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "PduR_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
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
/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"
extern FUNC(void, PDUR_CODE) PduR_Buffer_Init
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_DATA) buffer
);
extern FUNC_P2VAR(uint8, PDUR_APPL_DATA, PDUR_CODE) PduR_Buffer_Alloc
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_DATA) buffer,
    uint32 size
);
extern FUNC(void, PDUR_CODE) PduR_Buffer_Write
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_DATA) buffer,
    uint32 size
);
extern FUNC_P2VAR(uint8, PDUR_APPL_DATA, PDUR_CODE) PduR_Buffer_Get
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_DATA) buffer
);
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
extern FUNC(void, PDUR_CODE) PduR_Buffer_Free
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_DATA) buffer,
    uint32 size
);
extern FUNC(boolean, PDUR_CODE) PduR_Buffer_Empty
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_DATA) buffer
);
extern FUNC(uint32, PDUR_CODE) PduR_Buffer_GetSpace
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_DATA) buffer
);
/* PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */
#define PDUR_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"

#endif /* #define PDUR_BUFFER_H_ */

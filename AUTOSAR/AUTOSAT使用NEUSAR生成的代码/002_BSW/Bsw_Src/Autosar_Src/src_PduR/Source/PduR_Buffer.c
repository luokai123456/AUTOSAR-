/*
********************************************************************************
*
*  File name: PduR_Buffer.c
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
* Change: Add the implementation of function PduR_Buffer_GetSpace.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: LuQ/2023.10.17
* Change: Modify the definition of function PduR_Buffer_Alloc and
*         PduR_Buffer_Get.
* Cause: Buxfix
********************************************************************************
* Version: 3.3
* Author/Date: LuQ/2024.03.13
* Change: Memmap modify.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: LuQ/2024.03.18
* Change: Modify P2CONST member labels.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LuQ/2024.04.02
* Change: 1. Modify P2CONST member labels.
*         2. Modify the comments format.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LuQ/2024.09.20
* Change: Modify copyright information.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LuQ/2024.09.23
* Change: Modify the comments format.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: LuQ/2025.06.23
* Change: Modify the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "PduR_Buffer.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
#define PDUR_BUFFER_NO_SPACE        (0x00U)
#define PDUR_BUFFER_POS_0           (0x00U)

/*
********************************************************************************
*    Local Types
********************************************************************************
*/
/*
********************************************************************************
*    Local Variables
********************************************************************************
*/
/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
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
#define PDUR_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"

/*
********************************************************************************
* Function Name: PduR_Buffer_Init
*
* Explanation: Initialize the buffer.
* (Synchronous)
*
* param: buffer-> Pointer to the buffer.
*
* retval: None.
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_Buffer_Init
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_DATA) buffer
)
{
    if( NULL_PTR != buffer )
    {
        /* Set valid buffer size to total buffer size */
        /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_PduR_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
        buffer->header->validSize = buffer->dataSize;
        /* Set read position to begin */
        buffer->header->readPos = PDUR_BUFFER_POS_0;
        /* Set write position to begin */
        buffer->header->writePos = PDUR_BUFFER_POS_0;
    }
}

/*
********************************************************************************
* Function Name: PduR_Buffer_Alloc
*
* Explanation: Allocate a memory space from the buffer.
* (Synchronous)
*
* param: buffer-> Pointer to the buffer.
*        size -> The amount of space requested to be allocated
*
* retval: NULL_PTR: Failed to allocate buffer.
*         other: Address of allocated memory space.
********************************************************************************
*/
FUNC_P2VAR(uint8, PDUR_APPL_DATA, PDUR_CODE) PduR_Buffer_Alloc
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_DATA) buffer,
    uint32 size
)
{
    uint8* data = NULL_PTR;

    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    if( buffer->header->readPos < buffer->header->writePos )
    {
        /* Is there enough free space behind the write position */
        if( (buffer->dataSize - buffer->header->writePos) >= size )
        {
            /* Use the free space in the back */
            data = &buffer->dataPtr[buffer->header->writePos];
        }
        else if( buffer->header->readPos >= size )
        {
            /* Use the free space in the front */
            buffer->header->validSize = buffer->header->writePos;
            data = &buffer->dataPtr[PDUR_BUFFER_POS_0];
        }
        else
        {
            /* Do nothing */
        }
    }
    else if( buffer->header->readPos > buffer->header->writePos )
    {
        /* Is there enough free space between the read position and write position */
        if( (buffer->header->readPos - buffer->header->writePos) >= size )
        {
            data = &buffer->dataPtr[buffer->header->writePos];
        }
    }
    else
    {
        /* Is the buffer empty?*/
        if( buffer->header->writePos == PDUR_BUFFER_POS_0 )
        {
            data = &buffer->dataPtr[PDUR_BUFFER_POS_0];
        }
    }

    return data;
}

/*
********************************************************************************
* Function Name: PduR_Buffer_Write
*
* Explanation: Write data to the buffer.
* (Synchronous)
*
* param: buffer-> Pointer to the buffer.
*        size -> The amount of space used.
*
* retval: None.
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_Buffer_Write
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_DATA) buffer,
    uint32 size
)
{
    /* There is no space behind write position */
    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    if( buffer->header->writePos == buffer->header->validSize )
    {
        /* Reset the write position to begin */
        buffer->header->writePos = PDUR_BUFFER_POS_0;
    }

    /* Increase the write position */
    buffer->header->writePos += size;
}

/*
********************************************************************************
* Function Name: PduR_Buffer_Get
*
* Explanation: Get available data from the buffer.
* (Synchronous)
*
* param: buffer-> Pointer to the buffer.
*
* retval: Pointer to the data.
********************************************************************************
*/
FUNC_P2VAR(uint8, PDUR_APPL_DATA, PDUR_CODE) PduR_Buffer_Get
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_DATA) buffer
)
{
    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    uint32 pos = buffer->header->readPos;

    /* There is no space to read */
    if( pos == buffer->header->validSize )
    {
        /* Reset the position to starting point */
        pos = PDUR_BUFFER_POS_0;
    }

    return &buffer->dataPtr[pos];
}

/*
********************************************************************************
* Function Name: PduR_Buffer_Free
*
* Explanation: Deallocate memory space.
* (Synchronous)
*
* param: buffer-> Pointer to the buffer.
*        size -> The amount of space requested to be deallocate.
*
* retval: None.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
FUNC(void, PDUR_CODE) PduR_Buffer_Free
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_DATA) buffer,
    uint32 size
)
{
    /* There is no space to read */
    /* Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    if( buffer->header->readPos == buffer->header->validSize )
    {
        /* Reset the position to begin */
        buffer->header->readPos = PDUR_BUFFER_POS_0;
    }

    buffer->header->readPos += size;

    /* The buffer is empty */
    if( buffer->header->readPos == buffer->header->writePos )
    {
        /* Reset the buffer */
        buffer->header->readPos = PDUR_BUFFER_POS_0;
        buffer->header->writePos = PDUR_BUFFER_POS_0;
        buffer->header->validSize = buffer->dataSize;
    }
    else if( (buffer->header->readPos == buffer->header->validSize)
             && (buffer->header->validSize != buffer->dataSize) )
    {
        /* Reset the valid buffer size */
        buffer->header->validSize = buffer->dataSize;
        /* Set read position to the end */
        buffer->header->readPos = buffer->dataSize;
    }
    else
    {
        /* Do nothing */
    }
}

/*
********************************************************************************
* Function Name: PduR_Buffer_Empty
*
* Explanation: Check if there is data in the buffer.
* (Synchronous)
*
* param: buffer-> Pointer to the buffer.
*
* retval: TRUE: buffer is empty.
*         FALSE: buffer is not empty.
********************************************************************************
*/
FUNC(boolean, PDUR_CODE) PduR_Buffer_Empty
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_DATA) buffer
)
{
    boolean retVal = FALSE;

    /* Is the buffer empty */
    /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_PduR_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    if( (buffer->header->readPos == PDUR_BUFFER_POS_0) && (buffer->header->writePos == PDUR_BUFFER_POS_0) )
    {
        retVal = TRUE;
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: PduR_Buffer_GetSpace
*
* Explanation: Gets the free space of the buffer.
* (Synchronous)
*
* param: buffer-> Pointer to the buffer.
*
* retval: free space.
********************************************************************************
*/
FUNC(uint32, PDUR_CODE) PduR_Buffer_GetSpace
(
    P2CONST(PduR_BufferType, AUTOMATIC, PDUR_APPL_DATA) buffer
)
{
    uint32 space = PDUR_BUFFER_NO_SPACE;

    /* PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.14" PolySpace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_PduR_TAINTED_PTR" Polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_PduR_IDP" */
    if( buffer->header->readPos < buffer->header->writePos )
    {
        /* use the space after the write position */
        space = buffer->dataSize - buffer->header->writePos;

        if( space < buffer->header->readPos )
        {
            /* use the space before the read position */
            space = buffer->header->readPos;
        }
    }
    else if( buffer->header->readPos > buffer->header->writePos )
    {
        /* use the space between the read position and write position */
        space = buffer->header->readPos - buffer->header->writePos;
    }
    else
    {
        /* Is the buffer empty?*/
        if( buffer->header->writePos == PDUR_BUFFER_POS_0 )
        {
            /* use all the space */
            space = buffer->dataSize;
        }
    }

    return space;
}

#define PDUR_STOP_SEC_CODE
/* MISRA C:2012 Rule-20.1 */
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"

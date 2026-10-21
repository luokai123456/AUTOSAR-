/*
********************************************************************************
*
*  File name: Os_BitMap.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.23
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: WangJP/2022.12.10
* Change: Modification of coding standard.
* Cause: Optimize
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2024.2.29
* Change: Remove numeric macros.
* Cause: Optimization
********************************************************************************
*/
#ifndef OS_BITMAP_H_
#define OS_BITMAP_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"
#include "Os_Error.h"
#include "Os_Cfg.h"
#include "Os_Arch_Core.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Calculation of leading zero width. */
#if( OS_CFG_COUNT_LEAD_ZEROS_HARDWARE == STD_ON )
#define OS_BIT_WIDTH          (32U)  /* Hardware width. */
#else
#define OS_BIT_WIDTH          (8U)   /* Software width. */
#endif

/* The bitmap highest bit mask. */
#if( OS_CFG_COUNT_LEAD_ZEROS_HARDWARE == STD_ON )
#define OS_BITMAP_MASK_MSB    ((uint32)(((uint32)1U) << (uint32)(OS_BIT_WIDTH - 1U )))
#else
#define OS_BITMAP_MASK_MSB    ((uint8)(((uint8)1U) << (uint8)(OS_BIT_WIDTH - 1U )))
#endif

/* The bitmap support the maximum number of columns. */
#if( (OS_CFG_COUNT_LEAD_ZEROS_HARDWARE == STD_OFF) && (OS_CFG_TASK_PROC_NUM_GR64 == STD_ON) )
#define OS_BITMAP_MAXLENGTH   (OS_BIT_WIDTH)
#else
#define OS_BITMAP_MAXLENGTH   (64U)
#endif

/* The bitmap supports the maximum number of bit fields. */
#define OS_BITMAP_MAXNUM      (OS_BITMAP_MAXLENGTH * OS_BIT_WIDTH)

#if( OS_CFG_COUNT_LEAD_ZEROS_HARDWARE == STD_ON )
/* The 32 bit width offset. */
#define OS_BIT_WIDTH_OFFSET   (5U)
#else
/* The 8 bit width offset. */
#define OS_BIT_WIDTH_OFFSET   (3U)
#endif

/* Calculates the number of required bits. */
#define OS_BITMAP_NUM(BitNum) ((BitNum) + 1U)

/* Calculates the number of required bit fields. */
#define OS_BITMAP_LENGTH(BitNum) ((OS_BITMAP_NUM(BitNum) / OS_BIT_WIDTH) + 1U)

/* Bitmap data shift bit. */
#define OS_BIT_SHIFTBIT       (1U)
/* Operand after bit shift. */
#define OS_BIT_SHIFTOPERAND   (1U)
/* The minimum value of bitnum. */
#define OS_BIT_BITNUMMINVALUE (1U)
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef uint8 Os_BitMapCntSizeType;
typedef uint16 Os_BitMapIdType;

#if( OS_CFG_COUNT_LEAD_ZEROS_HARDWARE == STD_ON )
typedef uint32 Os_BitMapDataType;
#else
typedef uint8 Os_BitMapDataType;
#endif

typedef struct
{
    Os_BitMapDataType l1OrdinateMask;
} Os_BitMapDynType;

/* Basic data structure of the bit array. */
typedef struct
{
    /* Confirm whether to use ordinate elements. */
    Os_BitMapDynType* bitMapDyn;
    /* Bit map fields. */
    Os_BitMapDataType* l1Data;
#if( (OS_CFG_COUNT_LEAD_ZEROS_HARDWARE == STD_OFF) && (OS_CFG_TASK_PROC_NUM_GR64 == STD_ON) )
    Os_BitMapDataType* l2Data;
#endif
    /* Bit map length. */
    Os_BitMapIdType length;
    /* The number of configured bits in the bit map. */
    Os_BitMapIdType bitNum;
} Os_BitMapCfgType;

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
#define OS_START_SEC_CONST
#include "Os_MemMap.h"

extern CONST(uint8, OS_CONST) Os_CntLeadZerosTbl[256U];

#define OS_STOP_SEC_CONST
#include "Os_MemMap.h"

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*
********************************************************************************
* Function Name: Os_CntLeadZeros
*
* Explanation: Calculate leading zeros of the value.
*
* Param: val: value to calculate.
*
* Retval: Number of leading zeros.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_BitMapCntSizeType, OS_CODE) Os_CntLeadZeros(Os_BitMapDataType val)
{
#if( OS_CFG_COUNT_LEAD_ZEROS_HARDWARE == STD_ON )
    /* Use hardware CLZ instruction. */
    return (Os_BitMapCntSizeType)Os_Arch_CntLeadZeros(val);
#else
    /* Use software CLZ instruction. */
    return (Os_BitMapCntSizeType)Os_CntLeadZerosTbl[val];
#endif
}

/*
********************************************************************************
* Function Name: Os_BitMapCountLeadingZeros
*
* Explanation: Calculate leading zeros based on the given bitmap.
*
* Param: BitMap: The bit map element.
*
* Retval: Number of leading zeros.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_BitMapIdType, OS_CODE) Os_BitMap_CountLeadZeros
(
    P2CONST(Os_BitMapCfgType, AUTOMATIC, OS_APPL_CONST) bitMap
)
{
#if( (OS_CFG_COUNT_LEAD_ZEROS_HARDWARE == STD_OFF) && (OS_CFG_TASK_PROC_NUM_GR64 == STD_ON) )
    Os_BitMapIdType resultIdx;
    Os_BitMapIdType l1OrdinateIdx;
    Os_BitMapIdType l2OrdinateIdx;
    Os_BitMapIdType l1AbscissaIdx;
    Os_BitMapIdType l2AbscissaIdx;

    /* Get horizontal of the bitmap. */
    l1OrdinateIdx = (Os_BitMapIdType)Os_CntLeadZeros(bitMap->bitMapDyn->l1OrdinateMask);
    /* Calculate leading zeros of bit fields. */
    l1AbscissaIdx = (Os_BitMapIdType)Os_CntLeadZeros(bitMap->l1Data[l1OrdinateIdx]);

    /* Get horizontal of the bitmap. */
    l2OrdinateIdx = ((Os_BitMapIdType)(l1OrdinateIdx << OS_BIT_WIDTH_OFFSET) + l1AbscissaIdx);
    /* Calculate leading zeros of bit fields. */
    l2AbscissaIdx = (Os_BitMapIdType)Os_CntLeadZeros(bitMap->l2Data[l1AbscissaIdx]);

    resultIdx = ((Os_BitMapIdType)(l2OrdinateIdx << OS_BIT_WIDTH_OFFSET) + l2AbscissaIdx);

    return resultIdx;
#else
    Os_BitMapIdType resultIdx;
    Os_BitMapIdType l1OrdinateIdx;
    Os_BitMapIdType l1AbscissaIdx;

    /* Get horizontal of the bitmap. */
    l1OrdinateIdx = (Os_BitMapIdType)Os_CntLeadZeros(bitMap->bitMapDyn->l1OrdinateMask);

    /* Calculate leading zeros of bit fields. */
    l1AbscissaIdx = (Os_BitMapIdType)Os_CntLeadZeros(bitMap->l1Data[l1OrdinateIdx]);

    /* Calculate bit index. */
    resultIdx = ((Os_BitMapIdType)(l1OrdinateIdx << OS_BIT_WIDTH_OFFSET) + l1AbscissaIdx);

    return resultIdx;
#endif
}

/*
********************************************************************************
* Function Name: Os_BitMap_Set
*
* Explanation: The bit map set bit.
*
* Param: BitMap: Reference to the bit map element.
*        BitIdx: Bit index.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_BitMap_Set
(
    P2CONST(Os_BitMapCfgType, AUTOMATIC, OS_APPL_CONST) bitMap,
    Os_BitMapIdType bitIdx
)
{
#if( (OS_CFG_COUNT_LEAD_ZEROS_HARDWARE == STD_OFF) && (OS_CFG_TASK_PROC_NUM_GR64 == STD_ON) )
    Os_BitMapIdType l1OrdinateIdx;
    Os_BitMapIdType l2OrdinateIdx;
    Os_BitMapIdType l1AbscissaIdx;
    Os_BitMapIdType l2AbscissaIdx;

    /* Check bit index is valid. */
    Os_ParamCheck(bitIdx < bitMap->bitNum);

    /* Get horizontal of the bitmap. */
    l2OrdinateIdx = (bitIdx >> OS_BIT_WIDTH_OFFSET);
    l1OrdinateIdx = (l2OrdinateIdx >> OS_BIT_WIDTH_OFFSET);

    l2AbscissaIdx = (bitIdx & ((((Os_BitMapIdType)OS_BIT_SHIFTBIT << OS_BIT_WIDTH_OFFSET) - OS_BIT_SHIFTOPERAND)));
    l1AbscissaIdx = (l2OrdinateIdx & ((((Os_BitMapIdType)OS_BIT_SHIFTBIT << OS_BIT_WIDTH_OFFSET) - OS_BIT_SHIFTOPERAND)));

    /* Set the bit field bit and the allocation bit. */
    bitMap->l1Data[l1OrdinateIdx]     |= (Os_BitMapDataType)((Os_BitMapDataType)OS_BITMAP_MASK_MSB >> l1AbscissaIdx);
    bitMap->l2Data[l2OrdinateIdx]     |= (Os_BitMapDataType)((Os_BitMapDataType)OS_BITMAP_MASK_MSB >> l2AbscissaIdx);
    bitMap->bitMapDyn->l1OrdinateMask |= (Os_BitMapDataType)((Os_BitMapDataType)OS_BITMAP_MASK_MSB >> l1OrdinateIdx);
#else
    Os_BitMapIdType l1OrdinateIdx;
    Os_BitMapIdType l1AbscissaIdx;

    /* Check bit index is valid. */
    Os_ParamCheck(bitIdx < bitMap->bitNum);

    /* Get horizontal of the bitmap. */
    l1OrdinateIdx = (bitIdx >> OS_BIT_WIDTH_OFFSET);
    l1AbscissaIdx = (bitIdx & (((Os_BitMapIdType)((Os_BitMapIdType)OS_BIT_SHIFTBIT << OS_BIT_WIDTH_OFFSET) - OS_BIT_SHIFTOPERAND)));

    /* Set the bit field bit and the allocation bit. */
    bitMap->l1Data[l1OrdinateIdx]     |= (OS_BITMAP_MASK_MSB >> l1AbscissaIdx);
    bitMap->bitMapDyn->l1OrdinateMask |= (OS_BITMAP_MASK_MSB >> l1OrdinateIdx);
#endif
}

/*
********************************************************************************
* Function Name: Os_BitMap_Init
*
* Explanation: Initialize the bitmap.
*
* Param: BitMap: Reference to the bit map element.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_BitMap_Init
(
    P2CONST(Os_BitMapCfgType, AUTOMATIC, OS_APPL_CONST) bitMap
)
{
#if( (OS_CFG_COUNT_LEAD_ZEROS_HARDWARE == STD_OFF) && (OS_CFG_TASK_PROC_NUM_GR64 == STD_ON) )
    Os_BitMapIdType idx;
    Os_BitMapIdType l1Length;
    Os_BitMapIdType l2Length;

    /* Parameter verification. */
    Os_ParamCheck((bitMap->length > 0U) && (bitMap->length <= OS_BITMAP_MAXLENGTH));
    Os_ParamCheck((bitMap->bitNum > OS_BIT_BITNUMMINVALUE) && (bitMap->bitNum <= OS_BITMAP_MAXNUM));

    /* Clean bit map. */
    bitMap->bitMapDyn->l1OrdinateMask = 0U;

    l2Length = bitMap->length;
    for( idx = 0U; idx < l2Length; idx++ )
    {
        bitMap->l2Data[idx] = 0U;
    }

    l1Length = (l2Length >> OS_BIT_WIDTH_OFFSET) + OS_BIT_SHIFTOPERAND;
    for( idx = 0U; idx < l1Length; idx++ )
    {
        bitMap->l1Data[idx] = 0U;
    }
#else
    Os_BitMapIdType idx;
    /* Parameter verification. */
    Os_ParamCheck((bitMap->length > 0U) && (bitMap->length <= OS_BITMAP_MAXLENGTH));
    Os_ParamCheck((bitMap->bitNum > OS_BIT_BITNUMMINVALUE) && (bitMap->bitNum <= OS_BITMAP_MAXNUM));

    /* Clean bit map. */
    bitMap->bitMapDyn->l1OrdinateMask = 0U;

    for( idx = 0U; idx < bitMap->length; idx++ )
    {
        bitMap->l1Data[idx] = 0U;
    }
#endif

    Os_BitMap_Set(bitMap, bitMap->bitNum - OS_BIT_SHIFTOPERAND);
}

/*
********************************************************************************
* Function Name: Os_BitMap_Clear
*
* Explanation: The bit map clear bit.
*
* Param: BitMap: Reference to the bit map element.
*        BitIdx: Bit index.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_BitMap_Clear
(
    P2CONST(Os_BitMapCfgType, AUTOMATIC, OS_APPL_CONST) bitMap,
    Os_BitMapIdType bitIdx
)
{
#if( (OS_CFG_COUNT_LEAD_ZEROS_HARDWARE == STD_OFF) && (OS_CFG_TASK_PROC_NUM_GR64 == STD_ON) )
    Os_BitMapIdType l1OrdinateIdx;
    Os_BitMapIdType l2OrdinateIdx;
    Os_BitMapIdType l1AbscissaIdx;
    Os_BitMapIdType l2AbscissaIdx;

    /* Check bit index is valid. */
    Os_ParamCheck(bitIdx < bitMap->bitNum);

    /* Get horizontal of the bitmap. */
    l2OrdinateIdx = (bitIdx >> OS_BIT_WIDTH_OFFSET);
    l1OrdinateIdx = (l2OrdinateIdx >> OS_BIT_WIDTH_OFFSET);

    l2AbscissaIdx = (bitIdx & (((Os_BitMapIdType)((Os_BitMapIdType)OS_BIT_SHIFTBIT << OS_BIT_WIDTH_OFFSET) - OS_BIT_SHIFTOPERAND)));
    l1AbscissaIdx = (l2OrdinateIdx & (((Os_BitMapIdType)((Os_BitMapIdType)OS_BIT_SHIFTBIT << OS_BIT_WIDTH_OFFSET) - OS_BIT_SHIFTOPERAND)));

    /* Clear the bit field bit and the allocation bit. */
    bitMap->l2Data[l2OrdinateIdx] &= (Os_BitMapDataType)(~(OS_BITMAP_MASK_MSB >> l2AbscissaIdx));

    if( 0U == bitMap->l2Data[l2OrdinateIdx] )
    {
        bitMap->l1Data[l1OrdinateIdx] &= (Os_BitMapDataType)(~((Os_BitMapDataType)OS_BITMAP_MASK_MSB >> l1AbscissaIdx));

        if( 0U == bitMap->l1Data[l1OrdinateIdx] )
        {
             bitMap->bitMapDyn->l1OrdinateMask &= (Os_BitMapDataType)(~((Os_BitMapDataType)OS_BITMAP_MASK_MSB >> l1OrdinateIdx));
        }
    }

#else
    Os_BitMapIdType l1OrdinateIdx;
    Os_BitMapIdType l1AbscissaIdx;

    /* Check bit index is valid. */
    Os_ParamCheck(bitIdx < bitMap->bitNum);

    /* Get horizontal of the bitmap. */
    l1OrdinateIdx = (bitIdx >> OS_BIT_WIDTH_OFFSET);
    l1AbscissaIdx = (bitIdx & (((Os_BitMapIdType)((Os_BitMapIdType)OS_BIT_SHIFTBIT << OS_BIT_WIDTH_OFFSET) - OS_BIT_SHIFTOPERAND)));

    /* Clear the bit field bit and the allocation bit. */
    bitMap->l1Data[l1OrdinateIdx] &= (~(Os_BitMapDataType)((Os_BitMapDataType)OS_BITMAP_MASK_MSB >> l1AbscissaIdx));
    if( 0U == bitMap->l1Data[l1OrdinateIdx] )
    {
        bitMap->bitMapDyn->l1OrdinateMask &= (~(Os_BitMapDataType)((Os_BitMapDataType)OS_BITMAP_MASK_MSB >> l1OrdinateIdx));
    }
#endif
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_BITMAP_H_ */

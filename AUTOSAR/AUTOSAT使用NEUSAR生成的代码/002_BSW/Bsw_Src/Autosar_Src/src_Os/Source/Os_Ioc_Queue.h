/*
********************************************************************************
*
*  File name: Os_Ioc_Queue.h
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
* Author/Date: LiG/2023.1.13
* Change: Solves the problem of multiple cores accessing the same variable at
*         the same time.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2023.1.20
* Change: New IOC data type.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: ZhangY/2023.10.07
* Change: Modification for coding standard.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: LiG/2024.4.10
* Change: Modifying static code check issues.
* Cause: Optimization
********************************************************************************
*/
#ifndef OS_IOC_QUEUE_H_
#define OS_IOC_QUEUE_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Ioc queue periodic flipping deviation. */
#define OS_QUEUE_FLIPDEV                (1U)
/* Ioc queue initial zero value. */
#define OS_QUEUE_INIT                   (0U)
/* Ioc queue initial one value. */
#define OS_QUEUEVALUE_1                 (1U)

/* Create data is boolean type ioc queue. */
#define OS_QUEUE_CREATE_BL(name,  size)                   \
            boolean name##_Buffer[size];                  \
            Os_QueueType_BL (name);

/* Create data is uint8 type ioc queue. */
#define OS_QUEUE_CREATE_U8(name,  size)                   \
            uint8 name##_Buffer[size];                    \
            Os_QueueType_U8 (name);

/* Create data is uint16 type ioc queue. */
#define OS_QUEUE_CREATE_U16(name, size)                   \
            uint16 name##_Buffer[size];                   \
            Os_QueueType_U16 (name);

/* Create data is uint32 type ioc queue. */
#define OS_QUEUE_CREATE_U32(name, size)                   \
            uint32 name##_Buffer[size];                   \
            Os_QueueType_U32 (name);

/* Create data is uint64 type ioc queue. */
#define OS_QUEUE_CREATE_U64(name, size)                   \
            uint64 name##_Buffer[size];                   \
            Os_QueueType_U64 (name);

/* Create data is sint8 type ioc queue. */
#define OS_QUEUE_CREATE_S8(name,  size)                   \
            sint8 name##_Buffer[size];                    \
            Os_QueueType_S8 (name);

/* Create data is sint16 type ioc queue. */
#define OS_QUEUE_CREATE_S16(name, size)                   \
            sint16 name##_Buffer[size];                   \
            Os_QueueType_S16 (name);

/* Create data is sint32 type ioc queue. */
#define OS_QUEUE_CREATE_S32(name, size)                   \
            sint32 name##_Buffer[size];                   \
            Os_QueueType_S32 (name);

/* Create data is sint64 type ioc queue. */
#define OS_QUEUE_CREATE_S64(name, size)                   \
            sint64 name##_Buffer[size];                   \
            Os_QueueType_S64 (name);

/* Create data is float type ioc queue. */
#define OS_QUEUE_CREATE_FL(name, size)                    \
            float32 name##_Buffer[size];                  \
            Os_QueueType_FL (name);

/* Create data is double type ioc queue. */
#define OS_QUEUE_CREATE_DB(name, size)                    \
            float64 name##_Buffer[size];                  \
            Os_QueueType_DB (name);

/* Create data is point type ioc queue. */
#define OS_QUEUE_CREATE_P(name, size, type)               \
            type name##_Buffer[size];                     \
            Os_QueueType_Point (name);

/* Set the initial value of the ioc queue. */
#define OS_QUEUE_SETINITVALUE(name, queueLen)             \
        do                                                \
        {                                                 \
            (name).writeId = OS_QUEUE_INIT;               \
            (name).readId = OS_QUEUE_INIT;                \
            (name).size = queueLen;                       \
            (name).data = &name##_Buffer[OS_QUEUE_INIT];  \
        }while(OS_QUEUE_INIT)

/* Set the empty value of the ioc queue. */
#define OS_QUEUE_SETEMPTY(name)                           \
        do                                                \
        {                                                 \
            (name)->writeId = OS_QUEUE_INIT;              \
            (name)->readId = OS_QUEUE_INIT;               \
        }while(OS_QUEUE_INIT)

/* The ioc queue pop. */
#define OS_QUEUE_POP(name, value)                         \
do                                                        \
{                                                         \
    *(value) = (name->data[name->readId]);                \
    name->readId++;                                       \
    if( name->readId == name->size )                      \
    {                                                     \
        name->readId = OS_QUEUE_INIT;                     \
    }                                                     \
}while(OS_QUEUE_INIT)

/* The ioc queue push. */
#define OS_QUEUE_PUSH(name, value)                        \
do                                                        \
{                                                         \
    *(name->data + name->writeId) = value;                \
    name->writeId++;                                      \
    if( name->writeId == name->size )                     \
    {                                                     \
        name->writeId = OS_QUEUE_INIT;                    \
    }                                                     \
}while(OS_QUEUE_INIT)

/* The ioc queue write id add one. */
#define OS_QUEUE_INCREASEINDEX(name)                      \
do                                                        \
{                                                         \
    name->writeId++;                                      \
    if( name->writeId == name->size )                     \
    {                                                     \
        name->writeId = OS_QUEUE_INIT;                    \
    }                                                     \
}while(OS_QUEUE_INIT)

/* The ioc queue read id add one. */
#define OS_QUEUE_DECREASEINDEX(name)                      \
do                                                        \
{                                                         \
    name->readId++;                                       \
    if( name->readId == name->size )                      \
    {                                                     \
        name->readId = OS_QUEUE_INIT;                     \
    }                                                     \
}while(OS_QUEUE_INIT)

/* Ioc queue get the given position value. */
#define OS_QUEUE_GET(name, offset, type)                  \
do                                                        \
{                                                         \
    type ret;                                             \
    uint16 rawoffset;                                     \
    if( (offset + name->readId) >= name->size )           \
    {                                                     \
        rawoffset = (offset + name->readId) - name->size; \
    }                                                     \
    else                                                  \
    {                                                     \
        rawoffset = (uint16)(offset + name->readId);      \
    }                                                     \
    ret = (type)name->data[rawoffset];                    \
    return ret;                                           \
}while(OS_QUEUE_INIT)

/* Ioc queue delete the given position value. */
#define OS_QUEUE_DEL(name, offset)                        \
do                                                        \
{                                                         \
    uint16 des, src;                                      \
    if( offset < name->usrSize )                          \
    {                                                     \
        des = offset;                                     \
        for( i = OS_QUEUE_INIT; i < offset; i++ )         \
        {                                                 \
            src = (uint16)(des - OS_QUEUEVALUE_1);        \
            if( OS_QUEUE_INIT == des )                    \
            {                                             \
                src = name->size;                         \
            }                                             \
            name->data[des] = name->data[src];            \
            des = src;                                    \
        }                                                 \
        name->readId++;                                   \
        if( name->readId == name->size )                  \
        {                                                 \
            name->readId = OS_QUEUE_INIT;                 \
        }                                                 \
        name->usrSize--;                                  \
    }                                                     \
}while(OS_QUEUE_INIT)

/* Determine if the ioc queue is empty. */
#define OS_QUEUE_ISEMPTY(name)    (name->readId ==  name->writeId)

/* Determine if the ioc queue is full. */
#define OS_QUEUE_ISFULL(name)     (((0U == (name)->readId) && \
    ((name)->writeId == ((name)->size - OS_QUEUE_FLIPDEV))) || \
    (OS_QUEUE_FLIPDEV == ((name)->readId - (name)->writeId)))

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* The data is boolean type ioc queue node type. */
typedef struct
{
    uint16 writeId;
    uint16 readId;
    uint16 size;
    boolean* data;
} Os_QueueType_BL;

/* The data is uint8 type ioc queue node type. */
typedef struct
{
    uint16 writeId;
    uint16 readId;
    uint16 size;
    uint8* data;
} Os_QueueType_U8;

/* The data is uint16 type ioc queue node type. */
typedef struct
{
    uint16 writeId;
    uint16 readId;
    uint16 size;
    uint16* data;
} Os_QueueType_U16;

/* The data is uint32 type ioc queue node type. */
typedef struct
{
    uint16 writeId;
    uint16 readId;
    uint16 size;
    uint32* data;
} Os_QueueType_U32;

/* The data is uint64 type ioc queue node type. */
typedef struct
{
    uint16 writeId;
    uint16 readId;
    uint16 size;
    uint64* data;
} Os_QueueType_U64;

/* The data is sint8 type ioc queue node type. */
typedef struct
{
    uint16 writeId;
    uint16 readId;
    uint16 size;
    sint8* data;
} Os_QueueType_S8;

/* The data is sint16 type ioc queue node type. */
typedef struct
{
    uint16 writeId;
    uint16 readId;
    uint16 size;
    sint16* data;
} Os_QueueType_S16;

/* The data is sint32 type ioc queue node type. */
typedef struct
{
    uint16 writeId;
    uint16 readId;
    uint16 size;
    sint32* data;
} Os_QueueType_S32;

/* The data is sint64 type ioc queue node type. */
typedef struct
{
    uint16 writeId;
    uint16 readId;
    uint16 size;
    sint64* data;
} Os_QueueType_S64;

/* The data is float type ioc queue node type. */
typedef struct
{
    uint16 writeId;
    uint16 readId;
    uint16 size;
    float32* data;
} Os_QueueType_FL;

/* The data is double type ioc queue node type. */
typedef struct
{
    uint16 writeId;
    uint16 readId;
    uint16 size;
    float64* data;
} Os_QueueType_DB;

/* The data is point type ioc queue node type. */
typedef struct
{
    uint16 writeId;
    uint16 readId;
    uint16 size;
    void* data;
} Os_QueueType_Point;

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

#endif /* OS_IOC_QUEUE_H_ */

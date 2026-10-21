/*
********************************************************************************
*                                                                                                                                         
* File name: ComM_Lcfg.c                                                                                                     
*                                                                                                                                         
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.                                             
*                                                                                                                                         
********************************************************************************
*                                                                                                                                        
* History                                                                                                                             
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : TanLixiang/2018.11.14
* Change: Neusar
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : TanLixiang/2019.04.29
* Change: Modify
* Cause: 
*(1)Modify file structure.
********************************************************************************
* Version: 2.0
* Author/Date : zhangyong/2020.01.17
* Change: Modify
* Cause:
*(1)optimize all configuration item.
********************************************************************************
* Version: 3.0
* Author/Date : jiafeng/2020.07.02
* Change: Nothing
* Cause: Update to V3.0
********************************************************************************
* Version: 3.1
* Author/Date: TianL/2024.8.5
* Change: Modify copyright.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComStack_Types.h"
#include "ComM_Lcfg.h"
#include "ComM_Types.h"
#include "Com.h"
#include "ComM.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
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
*    Global Variable
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
/* polyspace-bagin MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
/* polyspace-bagin VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
#define COMM_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


CONST(ComM_ChannelType, COMM_CONFIG_DATA) ComM_Channel[COMM_ACTIVE_CHANNEL] = {
	{ COMM_BUS_TYPE_LIN,	0U,	0U,	(FALSE),	5U,	(FALSE),	(FALSE),	COMM_GATEWAY_TYPE_NONE,	2000U,	COMM_FULL_NMTYPEOFCHANNEL,	(FALSE),COMM_FULL_COM_READY_SLEEP },
	{ COMM_BUS_TYPE_CAN,	0U,	1U,	(FALSE),	5U,	(FALSE),	(FALSE),	COMM_GATEWAY_TYPE_NONE,	2000U,	COMM_FULL_NMTYPEOFCHANNEL,	(FALSE),COMM_FULL_COM_READY_SLEEP },
	{ COMM_BUS_TYPE_CAN,	0U,	2U,	(FALSE),	5U,	(FALSE),	(FALSE),	COMM_GATEWAY_TYPE_NONE,	2000U,	COMM_FULL_NMTYPEOFCHANNEL,	(FALSE),COMM_FULL_COM_READY_SLEEP },
	{ COMM_BUS_TYPE_CAN,	0U,	3U,	(FALSE),	5U,	(FALSE),	(FALSE),	COMM_GATEWAY_TYPE_NONE,	2000U,	COMM_FULL_NMTYPEOFCHANNEL,	(FALSE),COMM_FULL_COM_READY_SLEEP },
	{ COMM_BUS_TYPE_CAN,	0U,	4U,	(FALSE),	5U,	(FALSE),	(FALSE),	COMM_GATEWAY_TYPE_NONE,	2000U,	COMM_FULL_NMTYPEOFCHANNEL,	(FALSE),COMM_FULL_COM_READY_SLEEP },
	{ COMM_BUS_TYPE_CAN,	0U,	5U,	(FALSE),	5U,	(FALSE),	(FALSE),	COMM_GATEWAY_TYPE_NONE,	2000U,	COMM_FULL_NMTYPEOFCHANNEL,	(FALSE),COMM_FULL_COM_READY_SLEEP },
	{ COMM_BUS_TYPE_CAN,	0U,	6U,	(FALSE),	5U,	(FALSE),	(FALSE),	COMM_GATEWAY_TYPE_NONE,	2000U,	COMM_FULL_NMTYPEOFCHANNEL,	(FALSE),COMM_FULL_COM_READY_SLEEP }
};

CONST(ComM_ChannelPbType, COMM_CONFIG_DATA) ComM_ChannelPb[COMM_ACTIVE_CHANNEL] =
{
	{ COMM_NO_PNCPBINDENDIDXOFCHANNELPB,	COMM_NO_PNCPBINDSTARTIDXOFCHANNELPB,	1U,	0U },
	{ COMM_NO_PNCPBINDENDIDXOFCHANNELPB,	COMM_NO_PNCPBINDSTARTIDXOFCHANNELPB,	2U,	1U },
	{ COMM_NO_PNCPBINDENDIDXOFCHANNELPB,	COMM_NO_PNCPBINDSTARTIDXOFCHANNELPB,	3U,	2U },
	{ COMM_NO_PNCPBINDENDIDXOFCHANNELPB,	COMM_NO_PNCPBINDSTARTIDXOFCHANNELPB,	4U,	3U },
	{ COMM_NO_PNCPBINDENDIDXOFCHANNELPB,	COMM_NO_PNCPBINDSTARTIDXOFCHANNELPB,	5U,	4U },
	{ COMM_NO_PNCPBINDENDIDXOFCHANNELPB,	COMM_NO_PNCPBINDSTARTIDXOFCHANNELPB,	6U,	5U },
	{ COMM_NO_PNCPBINDENDIDXOFCHANNELPB,	COMM_NO_PNCPBINDSTARTIDXOFCHANNELPB,	7U,	6U }
};
	
CONST(ComM_UserByteMaskType, COMM_CONFIG_DATA) ComM_UserByteMask[COMM_NUM_USER_BYTE_MASK] =
{
	{0U,    0xFEU,    0x1U,    0U},
	{1U,    0xFEU,    0x1U,    1U},
	{2U,    0xFEU,    0x1U,    2U},
	{3U,    0xFEU,    0x1U,    3U},
	{4U,    0xFEU,    0x1U,    4U},
	{5U,    0xFEU,    0x1U,    5U},
	{6U,    0xFEU,    0x1U,    6U},
};
	
CONST(ComM_UserType, COMM_CONFIG_DATA) ComM_User[COMM_USER_SIZE] =
{
	{FALSE,    1U,    0U,    COMM_NO_USERPNCBYTEMASKENDIDXOFUSER,    COMM_NO_USERPNCBYTEMASKSTARTIDXOFUSER},
	{FALSE,    2U,    1U,    COMM_NO_USERPNCBYTEMASKENDIDXOFUSER,    COMM_NO_USERPNCBYTEMASKSTARTIDXOFUSER},
	{FALSE,    3U,    2U,    COMM_NO_USERPNCBYTEMASKENDIDXOFUSER,    COMM_NO_USERPNCBYTEMASKSTARTIDXOFUSER},
	{FALSE,    4U,    3U,    COMM_NO_USERPNCBYTEMASKENDIDXOFUSER,    COMM_NO_USERPNCBYTEMASKSTARTIDXOFUSER},
	{FALSE,    5U,    4U,    COMM_NO_USERPNCBYTEMASKENDIDXOFUSER,    COMM_NO_USERPNCBYTEMASKSTARTIDXOFUSER},
	{FALSE,    6U,    5U,    COMM_NO_USERPNCBYTEMASKENDIDXOFUSER,    COMM_NO_USERPNCBYTEMASKSTARTIDXOFUSER},
	{FALSE,    7U,    6U,    COMM_NO_USERPNCBYTEMASKENDIDXOFUSER,    COMM_NO_USERPNCBYTEMASKSTARTIDXOFUSER},
};
#if (COMM_PNCSUPPORT == STD_ON)	
	
CONST(ComM_UserPncByteMaskType, COMM_CONFIG_DATA) ComM_UserPncByteMask[COMM_NUM_USER_PNC_BYTE_MASK] =
{
};
	
CONST(uint8, COMM_CONFIG_DATA) ComM_PncChannelMapping[COMM_NUM_PNC_CHANNEL_MAPPING] =
{
};
	
CONST(ComM_PncPbType, COMM_CONFIG_DATA) ComM_PncPb[COMM_PNC_SIZE] =
{
};
	
CONST(uint8, COMM_CONFIG_DATA) ComM_PncSignalInd[COMM_NUM_PNC_SIGNALIND] =
{
};
	
CONST(uint8, COMM_CONFIG_DATA) ComM_PncPbInd[COMM_NUM_PNC_PBIND] =
{
};
	
CONST(ComM_PncType, COMM_CONFIG_DATA) ComM_Pnc[COMM_PNC_SIZE] =
{
};
	
/* polyspace +2 MISRA-C3:8.4 [Justified:Unset] "NSCA_Polyspace_ComM_Rule8.4" */
/* polyspace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_ComM_Rule8.7" */
CONST(ComM_PncSignalInfoType, COMM_CONFIG_DATA) ComM_PncSignalGroup[COMM_SIGNAL_GROUP_NUM] =  /* PRQA S 3408 */ /* NSCA_QAC_ComM_Rule8.4 */
{
{0, 0, 0, 0}  /* PRQA S 4424 */ /* NSCA_QAC_ComM_Rule10.3 */};
	
CONST(ComM_PncSignalType, COMM_CONFIG_DATA) ComM_PncSignal[COMM_SIGNAL_NUM] =
{
};
#endif

#define COMM_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define COMM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#if (COMM_PNCSUPPORT == STD_ON)
static FUNC(void, COMM_CODE) ComM_SendOneSignalInSignalGroup
(
    uint8 IndexOfSignalGroup,
    uint8 SignalByteSize,
    const uint8 * SignalDataTx
);
#endif

#if (COMM_PNCSUPPORT == STD_ON)
static FUNC(void, COMM_CODE) ComM_SendOneSignalInSignalGroup
(
    uint8 IndexOfSignalGroup,
    uint8 SignalByteSize,
    const uint8 * SignalDataTx
)
{
    uint8 byteCount = COMM_ZERO;
    uint8 shift = COMM_ZERO;
    uint8 byteIndex = COMM_ZERO;
    uint8 loopLimit = COMM_ZERO;

    uint8  signalData8 = COMM_ZERO;
    uint8  signalData8N[COMM_PNC_SIGNAL_LENGTH] = {COMM_ZERO};
    uint16 signalData16 = COMM_ZERO;
    uint32 signalData32 = COMM_ZERO;
    uint64 signalData64 = COMM_ZERO;

    uint16 tempValue16 = COMM_ZERO;
    uint32 tempValue32 = COMM_ZERO;
    uint64 tempValue64 = COMM_ZERO;

    switch( ComM_PncSignalGroup[IndexOfSignalGroup].SignalDataType )
    {
        case COMM_PNC_SIGNALTYPE_UINT8:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3 */
        {
            /* Directly assign the tx data to the signal(uint8). */
            /* polyspace +3 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_ComM_Rule18.1" */
            /* polyspace +2 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.1" */
            /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_ComM_PointerOutBounds" */
            signalData8 = SignalDataTx[COMM_ZERO]; /*0x01*/
            (void)Com_SendSignal(ComM_PncSignalGroup[IndexOfSignalGroup].SignalId, &signalData8);
        }
        break;
        case COMM_PNC_SIGNALTYPE_UINT8_N:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3 */
        {
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable */
            if( SignalByteSize <= COMM_PNC_SIGNAL_LENGTH )
            {
                loopLimit = SignalByteSize;
                for( byteCount = COMM_ZERO; byteCount < loopLimit; byteCount++ )
                {
                    byteIndex = loopLimit - byteCount - COMM_ONE;
                    /* polyspace +3 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_ComM_Rule18.1" */
                    /* polyspace +2 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.1" */
                    /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_ComM_PointerOutBounds" */
                    signalData8N[byteIndex] = SignalDataTx[byteIndex];
                }
                (void)Com_SendSignal(ComM_PncSignalGroup[IndexOfSignalGroup].SignalId, signalData8N);
            }
        }
        break;
        case COMM_PNC_SIGNALTYPE_UINT16:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3 */
        {
            /* map the tx data to the signal(uint16). */
            loopLimit = sizeof(uint16);
            for( byteCount = COMM_ZERO ; byteCount < loopLimit; byteCount++ )
            {
                shift = byteCount * 8;  /* PRQA S 1860 */ /* NSCA_QAC_ComM_Rule10.4 */
                byteIndex = loopLimit - byteCount - COMM_ONE;
                /* polyspace +3 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_ComM_Rule18.1" */
                /* polyspace +2 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.1" */
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_ComM_PointerOutBounds" */
                tempValue16 = (uint16)SignalDataTx[byteIndex];
                signalData16 = signalData16 | (tempValue16 << shift);  /* PRQA S 4397 */ /* NSCA_QAC_ComM_Rule10.7 */
            }
            (void)Com_SendSignal(ComM_PncSignalGroup[IndexOfSignalGroup].SignalId, &signalData16);
        }
        break;
        case COMM_PNC_SIGNALTYPE_UINT32:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3 */
        {
            /* map the tx data to the signal(uint32). */
            loopLimit = sizeof(uint32);
            for( byteCount = COMM_ZERO; byteCount < loopLimit; byteCount++ )
            {
                shift = byteCount * 8;  /* PRQA S 1860 */ /* NSCA_QAC_ComM_Rule10.4 */
                byteIndex = loopLimit - byteCount - COMM_ONE;
                /* polyspace +3 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_ComM_Rule18.1" */
                /* polyspace +2 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.1" */
                /* polyspace +1 RTE:IDP [Justified:Unset] "NSCA_Polyspace_ComM_PointerOutBounds" */
                tempValue32 = (uint32)SignalDataTx[byteIndex];
                signalData32 = signalData32 | (tempValue32 << shift);
            }
            (void)Com_SendSignal(ComM_PncSignalGroup[IndexOfSignalGroup].SignalId, &signalData32);
        }break;
        /* polyspace +2 DEFECT:DEAD_CODE [Justified:Unset] "NSCA_Polyspace_Common_Deadcode" */
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable */
        case COMM_PNC_SIGNALTYPE_UINT64:  /* PRQA S 570 */ /* NSCA_QAC_ComM_Rule10.3 */
        {
            /* map the tx data to the signal(uint64). */
            loopLimit = SignalByteSize;
            if( loopLimit >= COMM_ONE )
            {
                for( byteCount = COMM_ZERO; byteCount < loopLimit; byteCount++ )
                {
                    shift = byteCount * 8;  /* PRQA S 1860 */ /* NSCA_QAC_ComM_Rule10.4 */
                    byteIndex = loopLimit - byteCount - COMM_ONE;
                    tempValue64 = (uint64)SignalDataTx[byteIndex];
                    signalData64 = signalData64 | (tempValue64 << shift);
                }
                (void)Com_SendSignal(ComM_PncSignalGroup[IndexOfSignalGroup].SignalId, &signalData64);
            }
        }break;
        default:
            /* Nothing to do */
            break;
    }

    return;
}
#endif

FUNC(void, COMM_CODE) ComM_MainFunction_0(void)
{
    (void)ComM_MainFunction((NetworkHandleType)0 );
}

FUNC(void, COMM_CODE) ComM_MainFunction_1(void)
{
    (void)ComM_MainFunction((NetworkHandleType)1 );
}

FUNC(void, COMM_CODE) ComM_MainFunction_2(void)
{
    (void)ComM_MainFunction((NetworkHandleType)2 );
}

FUNC(void, COMM_CODE) ComM_MainFunction_3(void)
{
    (void)ComM_MainFunction((NetworkHandleType)3 );
}

FUNC(void, COMM_CODE) ComM_MainFunction_4(void)
{
    (void)ComM_MainFunction((NetworkHandleType)4 );
}

FUNC(void, COMM_CODE) ComM_MainFunction_5(void)
{
    (void)ComM_MainFunction((NetworkHandleType)5 );
}

FUNC(void, COMM_CODE) ComM_MainFunction_6(void)
{
    (void)ComM_MainFunction((NetworkHandleType)6 );
}


#if (COMM_PNCSUPPORT == STD_ON)

#endif

#if (COMM_PNCSUPPORT == STD_ON)
FUNC(void, COMM_CODE) ComM_ExecuteComSendSignal(ComM_SizeOfPncSignalType InternalSignalId, P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) SignalDataTx)
{
    uint8 numberOfSignalsInSignalGroup = COMM_ZERO;
    uint8 startIdxOfSignalGroup = COMM_ZERO;
    uint8 cntOfSignal = COMM_ZERO;
    uint8 currentIdxOfSignalGroup = COMM_ZERO;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_ComM_Dir4.5" */
    uint8 signalByteSize = COMM_ZERO;
    uint8 currentByteIdxOfSignalData = COMM_ZERO;
    uint8 isSendSignal = COMM_ZERO;

    startIdxOfSignalGroup = ComM_PncSignal[InternalSignalId].StartIdxOfSignalGroup;
    numberOfSignalsInSignalGroup = ComM_PncSignal[InternalSignalId].NumberOfSignalsInSignalGroup;
    for( cntOfSignal = COMM_ZERO; cntOfSignal < numberOfSignalsInSignalGroup; cntOfSignal++ )
    {
        currentIdxOfSignalGroup = startIdxOfSignalGroup + cntOfSignal;
        signalByteSize = ComM_PncSignalGroup[currentIdxOfSignalGroup].SignalByteSize;

        if( COMM_ONE == numberOfSignalsInSignalGroup )
        {
            ComM_SendOneSignalInSignalGroup(currentIdxOfSignalGroup, signalByteSize, &SignalDataTx[currentByteIdxOfSignalData]);
        }
        else
        {
            isSendSignal = ComM_PncSignal[InternalSignalId].SignalMask & (COMM_ONE<<cntOfSignal);  /* PRQA S 4397 */ /* NSCA_QAC_ComM_Rule10.7 */
            if( COMM_ZERO != isSendSignal )
            {
                ComM_SendOneSignalInSignalGroup(currentIdxOfSignalGroup, signalByteSize, &SignalDataTx[currentByteIdxOfSignalData]);
            }
        }
        /* move the Signal Byte index of current signal. */
        currentByteIdxOfSignalData = currentByteIdxOfSignalData + signalByteSize;
    }

    return;
}
#endif
/* polyspace-end MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_ComM_Rule10.3" */
/* polyspace-end VARIABLE:* [Justified:Unset] "NSCA_Polyspace_ComM_UsedNonSharedVariable" */
#define COMM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "ComM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


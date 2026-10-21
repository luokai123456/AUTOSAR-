#include "PMS_RteComCbk.h"
#include "Rte_Cbk.h"
#include "ErrorDiag_CAN.h"

FUNC(void, RTE_CODE) Rte_COMCbk_CSM_DriveModeReq_CSM_SwitchSts_TimeoutNotification(void)
{
  
}

FUNC(void, RTE_CODE) Rte_COMCbk_CSM_DriveModeReq_CSM_SwitchSts_ComNotification(void)
{
  Rte_COMCbk_CSM_DriveModeReq_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx();
}

FUNC(void, RTE_CODE) Rte_COMCbk_PEPS_PowerModeValidity_PEPS_Message_Sts_TimeoutNotification(void)
{

}

FUNC(void, RTE_CODE) Rte_COMCbk_PEPS_PowerModeValidity_PEPS_Message_Sts_ComNotification(void)
{
  Rte_COMCbk_PEPS_PowerModeValidity_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx();
}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_OutOverCurr_DCDC_FaultInfo_TimeoutNotification(void)
{

}

FUNC(void, RTE_CODE) Rte_COMCbk_DCDC_OutOverCurr_DCDC_FaultInfo_ComNotification(void)
{
  Rte_COMCbk_DCDC_OutOverCurr_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx();
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_MbRegenTargetWheel_EHB_Regen_TimeoutNotification(void)
{

}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_MbRegenTargetWheel_EHB_Regen_ComNotification(void)
{
  Rte_COMCbk_EHB_MbRegenTargetWheel_EHB_Regen_N72__PMS_C_CAN_20260425_dbc_Rx();
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_PTTrqDecReq_EHB_PTTorqueRequest_TimeoutNotification(void)
{

}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_PTTrqDecReq_EHB_PTTorqueRequest_ComNotification(void)
{
  Rte_COMCbk_EHB_PTTrqDecReq_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx();
}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_ABSActive_EHB_Status_TimeoutNotification(void)
{

}

FUNC(void, RTE_CODE) Rte_COMCbk_EHB_ABSActive_EHB_Status_ComNotification(void)
{
  Rte_COMCbk_EHB_ABSActive_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx();
}

FUNC(void, RTE_CODE) Rte_COMCbk_ACU_CrashOutputSts_ACU_ChimeTelltaleReq_TimeoutNotification(void)
{

}

FUNC(void, RTE_CODE) Rte_COMCbk_ACU_CrashOutputSts_ACU_ChimeTelltaleReq_ComNotification(void)
{
  Rte_COMCbk_ACU_CrashOutputSts_ACU_ChimeTelltaleReq_N72__PMS_C_CAN_20260425_dbc_Rx();
}

FUNC(void, RTE_CODE) Rte_COMCbk_EGSM_ParkReq_EGSM_Status_TimeoutNotification(void)
{

}

FUNC(void, RTE_CODE) Rte_COMCbk_EGSM_ParkReq_EGSM_Status_ComNotification(void)
{
  Rte_COMCbk_EGSM_ParkReq_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx();
}

FUNC(boolean, RTE_CODE) ACU_ChimeTelltaleReq_CAND_0x380_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CAND_0x380_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CAND_0x380_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}

FUNC(boolean, RTE_CODE) CSM_SwitchSts_CANB_0x3CA_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CANB_0x3CA_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CANB_0x3CA_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}

FUNC(boolean, RTE_CODE) PEPS_Message_Sts_CANB_0x1E2_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CANB_0x1E2_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CANB_0x1E2_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}

FUNC(boolean, RTE_CODE) EGSM_Status_CANA_0x145_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CANA_0x145_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CANA_0x145_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}

FUNC(boolean, RTE_CODE) EHB_Status_CAND_0x125_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CAND_0x125_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CAND_0x125_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}

FUNC(boolean, RTE_CODE) PDC_Status_Info_CAND_0x2CF_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CAND_0x2CF_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CAND_0x2CF_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}


FUNC(boolean, RTE_CODE) OBC_Sts_CANA_0x220_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CANA_0x220_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CANA_0x220_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}
FUNC(boolean, RTE_CODE) Station_Status_CANA_0x157_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CANA_0x157_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CANA_0x157_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}
FUNC(boolean, RTE_CODE) EHB_DA_MESSAGE_CAND_0x126_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CAND_0x126_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CAND_0x126_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}
FUNC(boolean, RTE_CODE) EHB_FrontWheelSpeedsKPH_CAND_0x122_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CAND_0x122_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CAND_0x122_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}
FUNC(boolean, RTE_CODE) EHB_ISARequest_CAND_0x1F9_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CAND_0x1F9_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CAND_0x1F9_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}
FUNC(boolean, RTE_CODE) EHB_PTTorqueRequest_CAND_0x129_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CAND_0x129_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CAND_0x129_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}
FUNC(boolean, RTE_CODE) EHB_RearWheelSpeedsKPH_CAND_0x123_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CAND_0x123_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CAND_0x123_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}
FUNC(boolean, RTE_CODE) EHB_Regen_CAND_0x128_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CAND_0x128_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CAND_0x128_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}
FUNC(boolean, RTE_CODE) EHB_VLC_TorqueRequest_CAND_0x121_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CAND_0x121_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CAND_0x121_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}
FUNC(boolean, RTE_CODE) EHB_WheelSpeedsRC_CAND_0x124_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CAND_0x124_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CAND_0x124_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}


FUNC(boolean, RTE_CODE) SAS_Status_CAND_0x0E0_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;


    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;

        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CAND_0x0E0_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CAND_0x0E0_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}
FUNC(boolean, RTE_CODE) YRS1_CAND_0x130_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CAND_0x130_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CAND_0x130_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}
FUNC(boolean, RTE_CODE) YRS2_CAND_0x131_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CAND_0x131_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CAND_0x131_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}
FUNC(boolean, RTE_CODE) HCM_MainRelayValue_CANG_0x122_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CANG_0x122_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CANG_0x122_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}
FUNC(boolean, RTE_CODE) HCM_Other2RelayValue_CANG_0x128_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CANG_0x128_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CANG_0x128_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}
FUNC(boolean, RTE_CODE) HCM_OtherRelayValue_CANG_0x124_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CANG_0x124_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CANG_0x124_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}
FUNC(boolean, RTE_CODE) HCM_Status_CANG_0x120_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    PduLengthType byteIndex;
    PduLengthType copyLength = 0U;

    (void)PduId;

    if((NULL_PTR != PduInfoPtr) && (NULL_PTR != PduInfoPtr->SduDataPtr))
    {
        copyLength = PduInfoPtr->SduLength;
        if(copyLength > 8U)
        {
            copyLength = 8U;
        }

        for(byteIndex = 0U; byteIndex < copyLength; byteIndex++)
        {
        	CANG_0x120_CheckSumArray[byteIndex] = PduInfoPtr->SduDataPtr[byteIndex];
        }
    }
    for(byteIndex = copyLength; byteIndex < 8U; byteIndex++)
    {
    	CANG_0x120_CheckSumArray[byteIndex] = 0U;
    }

    return TRUE;
}

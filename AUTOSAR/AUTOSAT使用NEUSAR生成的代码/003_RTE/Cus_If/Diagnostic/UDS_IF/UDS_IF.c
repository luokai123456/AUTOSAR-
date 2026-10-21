#include "UDS_IF.h"

#include "ErrorDiag_CAN.h"
#include "Dem_PBcfg.h"


/**
 * 函数含义：UDS报文，是否允许通讯，自定义规则回调函数
 * 
 * return：是否允许通讯  E_OK：允许UDS通讯  E_NOT_OK：不允许UDS通讯
 * 
*/
uint8 UDS_Communication_User_Rule(void)
{
    uint8 RetVal = E_NOT_OK;

    if( TRUE == Can_DiagVltgCondFlg ) 
    {
        RetVal = E_OK;
    }
    else
    {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}




#define DEM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#if(DEM_CFG_DTCSTATUSCHANGES_SUPPORT == STD_ON)
VAR(Dem_DTCStatusChanges_st, DEM_VAR_INIT) Dem_DTCStatusChanges[DEM_CFG_DTC_NUM + 1U] = {{0U, 0U, 0U}};
#endif
#define DEM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define DEM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

void Dem_CallbackDTCStatusChanged(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew)
{
#if(DEM_CFG_DTCSTATUSCHANGES_SUPPORT == STD_ON)
	uint16 dtcIdx;

	for(dtcIdx = 1U; dtcIdx <= DEM_CFG_DTC_NUM; dtcIdx++)
	{
		if(Dem_CfgUdsDtcValue[dtcIdx] == DTC)
		{
			Dem_DTCStatusChanges[dtcIdx].DTC = DTC;
			if(((DTCStatusOld & 0x01U) == 0U) && ((DTCStatusNew & 0x01U) != 0U))
			{
				if(Dem_DTCStatusChanges[dtcIdx].Dem_DTCFailedCount < 0xFFFFU)
				{
					Dem_DTCStatusChanges[dtcIdx].Dem_DTCFailedCount++;
				}
			}
			else if(((DTCStatusOld & 0x01U) != 0U) && ((DTCStatusNew & 0x01U) == 0U))
			{
				if(Dem_DTCStatusChanges[dtcIdx].Dem_DTCPassedCount < 0xFFFFU)
				{
					Dem_DTCStatusChanges[dtcIdx].Dem_DTCPassedCount++;
				}
			}
			else
			{
				/* No bit 0 transition. */
			}
			break;
		}
	}
#endif
}

#define DEM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */




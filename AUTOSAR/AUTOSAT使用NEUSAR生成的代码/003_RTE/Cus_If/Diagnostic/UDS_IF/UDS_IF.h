#ifndef _UDS_IF_H_
#define _UDS_IF_H_

#include "Platform_Types.h"
#include "StandardTypes.h"

#include "Dem_Lcfg.h"


extern uint8 UDS_Communication_User_Rule(void);


//DEM
#define DEM_CFG_DTCSTATUSCHANGES_SUPPORT STD_ON

#if(DEM_CFG_DTCSTATUSCHANGES_SUPPORT == STD_ON)
typedef struct
{
	uint32 DTC;
	uint16 Dem_DTCFailedCount;
	uint16 Dem_DTCPassedCount;
} Dem_DTCStatusChanges_st;
#endif
#define DEM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
#if(DEM_CFG_DTCSTATUSCHANGES_SUPPORT == STD_ON)
extern VAR(Dem_DTCStatusChanges_st, DEM_VAR_INIT) Dem_DTCStatusChanges[DEM_CFG_DTC_NUM + 1U];
#endif
void Dem_CallbackDTCStatusChanged(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew);
#define DEM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */


#endif /* _UDS_IF_H_ */
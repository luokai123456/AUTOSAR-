#ifndef __CANBUS_CONFIGURATION_H_
#define __CANBUS_CONFIGURATION_H_

#include "StandardTypes.h"

/***************************** Version Start *****************************/
#define BSW_RELEASE_MANUFACTORY_VERSION     201 
#define BSW_RELEASE_CARMODEL_VERSION        2   

#define BSW_RELEASE_MAJOR_VERSION           0   
#define BSW_RELEASE_MINOR_VERSION           6   
#define BSW_RELEASE_TEST_VERSION            57

#define BSW_RELEASE_YEAR                    26   
#define BSW_RELEASE_MONTH                   10   
#define BSW_RELEASE_DAY                     20     

/****************************** Version End ******************************/

extern boolean CAND_0x125_ActiveRaw;
extern boolean CAND_0x125_Active;
extern boolean CAND_0x128_ActiveRaw;
extern boolean CAND_0x128_Active;
extern boolean CAND_0x129_ActiveRaw;
extern boolean CAND_0x129_Active;
extern boolean CANA_0x398_ActiveRaw;
extern boolean CANA_0x398_Active;
extern boolean CANA_0x145_ActiveRaw;
extern boolean CANA_0x145_Active;
extern boolean CAND_0x380_ActiveRaw;
extern boolean CAND_0x380_Active;
extern boolean CANB_0x3C3_ActiveRaw;
extern boolean CANB_0x3C3_Active;
extern boolean CANB_0x3CA_ActiveRaw;
extern boolean CANB_0x3CA_Active;

extern boolean CANG_0x122_ActiveRaw;
extern boolean CANG_0x122_Active;
extern boolean CANG_0x128_ActiveRaw;
extern boolean CANG_0x128_Active;
extern boolean CANE_0x1826F456_ActiveRaw;
extern boolean CANE_0x1826F456_Active;
extern boolean CANE_0x1801F456_ActiveRaw;
extern boolean CANE_0x1801F456_Active;
extern boolean CANE_0x100AF456_ActiveRaw;
extern boolean CANE_0x100AF456_Active;
extern boolean CANE_0x1812F456_ActiveRaw;
extern boolean CANE_0x1812F456_Active;
extern boolean CANE_0x1808F456_ActiveRaw;
extern boolean CANE_0x1808F456_Active;
extern boolean CANE_0x181DF456_ActiveRaw;
extern boolean CANE_0x181DF456_Active;
extern boolean CANE_0x101AF456_ActiveRaw;
extern boolean CANE_0x101AF456_Active;
extern boolean CANE_0x81FF456_ActiveRaw;
extern boolean CANE_0x81FF456_Active;

extern boolean CANA_0x220_ActiveRaw;
extern boolean CANA_0x220_Active;

extern boolean CANB_0x247_ActiveRaw;
extern boolean CANB_0x247_Active;

extern boolean CANB_0x1E2_ActiveRaw;
extern boolean CANB_0x1E2_Active;

extern boolean CAND_0x2CF_ActiveRaw;
extern boolean CAND_0x2CF_Active;

extern boolean CANA_0x157_ActiveRaw;
extern boolean CAND_0x126_ActiveRaw;
extern boolean CAND_0x122_ActiveRaw;
extern boolean CAND_0x1F9_ActiveRaw;
extern boolean CAND_0x123_ActiveRaw;
extern boolean CAND_0x121_ActiveRaw;
extern boolean CAND_0x124_ActiveRaw;
extern boolean CAND_0x0E0_ActiveRaw;
extern boolean CAND_0x130_ActiveRaw;
extern boolean CAND_0x131_ActiveRaw;
extern boolean CANG_0x124_ActiveRaw;
extern boolean CANG_0x120_ActiveRaw;

extern boolean CANA_0x157_Active;
extern boolean CAND_0x126_Active;
extern boolean CAND_0x122_Active;
extern boolean CAND_0x1F9_Active;
extern boolean CAND_0x123_Active;
extern boolean CAND_0x121_Active;
extern boolean CAND_0x124_Active;
extern boolean CAND_0x0E0_Active;
extern boolean CAND_0x130_Active;
extern boolean CAND_0x131_Active;
extern boolean CANG_0x124_Active;
extern boolean CANG_0x120_Active;

extern void Com_CanSm_CANReceiveInf_callBack(uint8 Can_valNodeId, uint32 Can_valMsgId);
extern void CAN_MsgActive_Update(void);


#endif /*__CANBUS_CONFIGURATION_H_*/

#ifndef __CDD_AFE_RELEASE_H_
#define __CDD_AFE_RELEASE_H_

#include "Std_Types.h"

extern uint8 Cdd_AFE_GetCellVoltages(uint16* CellVoltages, uint8 ChLength);
extern uint8 Cdd_AFE_GetCellTempResistance(uint16* CalTempResistors, uint8 ChLength);
extern void Cdd_AFE_GetBalTempResistance(uint16* BalTempResistors,uint8 ChLength);
extern void Cdd_AFE_GetChipTemp(float* AFEInterTemp,uint8 ChLength);
extern void Cdd_AFE_GetCellOpenWireStatus(uint32* OpenWireMask,uint8 ChLength);
extern void Cdd_AFE_GetTempOpenWireStatus(uint32* OpenWireMask,uint8 ChLength);
extern void Cdd_AFE_SetBalancingChannels(uint32* BalancingMask,uint8 ChLength);
extern uint8 Cdd_AFE_GetBalancingStatus(uint32* FeedbackMask, uint16 Length);
extern void Cdd_AFE_GetTempDiagStatus(uint16 *DiagMask,uint8 ChLength);
extern uint8 Cdd_AFE_GetUARTCommTimeout(void);
extern uint32 Cdd_AFE_GetSubMissingStatus(void);
extern uint32 Cdd_AFE_GetBalanceErrorStatus(uint8 AFEChannel);
extern uint32 Cdd_AFE_GetAFEChipErrorStatus(void);

#endif/* __CDD_AFE_RELEASE_H_ */

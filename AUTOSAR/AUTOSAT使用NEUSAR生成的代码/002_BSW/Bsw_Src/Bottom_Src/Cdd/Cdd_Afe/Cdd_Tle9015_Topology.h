#ifndef __CDD_TLE9015_TOPOLOGY_H_
#define __CDD_TLE9015_TOPOLOGY_H_

#include "Cdd_Tle9018_Driver.h"

extern uint8 Tle9015_Topology_AutoInit(Tle9018_DevType* dev);
extern uint8 Tle9015_GetPhyId(Tle9018_DevType* dev, uint8 logic_addr);
extern uint8 Tle9015_GetPort(Tle9018_DevType* dev, uint8 logic_addr);
extern uint8 Tle9015_GetTotalDevNum(Tle9018_DevType* dev);
extern uint8 Tle9015_LineOffTopologyInit(Tle9018_DevType* dev);
extern void Tle9015_RestErrAndnSleep(void);
extern uint8 Cdd_Afe_Tle9015_AbistChack(Tle9018_DevType* dev);

#endif

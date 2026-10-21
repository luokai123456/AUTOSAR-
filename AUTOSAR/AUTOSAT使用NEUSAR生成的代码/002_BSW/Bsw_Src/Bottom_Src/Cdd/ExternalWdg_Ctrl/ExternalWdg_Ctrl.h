#include "Platform_Types.h"
#include "Cdd_Sa47301.h"


typedef struct
{
  uint8 RESP3; /*Response byte 3 */
  uint8 RESP2; /*Response byte 2 */
  uint8 RESP1; /*Response byte 1 */
  uint8 RESP0; /*Response byte 0 */
} SA_47301_FwdResponse_Type;

#define   SUCCESSFUL   0
#define   FAILED       1

#define SPI_READ                               0
#define SPI_WTITE                              1

extern uint8 Wdg_30_Sbc_Timer_permissionCounter;
extern void ExternalWdg_FeedFWD_Function(void);
extern uint16 ExternalWdg_Ctrl_Init(void);
extern void SA47031_CONDITION_Function(void);
extern void SA_SpiTransmit_Function(boolean valRW_Lo,uint8 valRegAddr_Lo,uint8 Txdata,uint16 *Rxdata);
extern void Wdg30_Sbc_Timer_SetTimeout(void);
extern void Wdg30_Sbc_ExtWdgReset(void);


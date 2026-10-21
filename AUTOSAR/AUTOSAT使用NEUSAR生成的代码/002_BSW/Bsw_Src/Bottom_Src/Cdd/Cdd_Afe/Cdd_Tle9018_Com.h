#ifndef __CDD_TLE9018_COM_
#define __CDD_TLE9018_COM_

#include "Std_Types.h"

#define TLE9018_UART_INST_0                         0
#define TLE9018_UART_INST_1                         1
#define TLE9018_UART_CRC_TABLE_ARRAY_SIZE           256
#define TLE9018_UART_RX_BUF_NUM                     94
#define TLE9018_UART_TX_BUF_NUM                     6

#define TLE9018_REG_ADDR_MASK                       0x3F
#define TLE9018_WRITE_CMD_MASK                      0x80
#define TLE9018_READ_CMD_MASK                       0x00

extern uint8* Tle9018_GetSpiRxData(uint8 index);
extern uint8 Tle9018_WriteRegister(uint32 instance, uint8 dev_id, uint8 reg_addr, uint16 data);
extern uint8 Tle9018_ReadRegister(uint32 instance, uint8 dev_id, uint8 reg_addr, uint8 res_len);
extern uint8 Tle9018_ReadRegister_Dual(uint32 instance, uint8 dev_id, uint8 reg_addr, uint8 res_len);

#endif /*__EVPTCDD_TLE9018_CFG_*/

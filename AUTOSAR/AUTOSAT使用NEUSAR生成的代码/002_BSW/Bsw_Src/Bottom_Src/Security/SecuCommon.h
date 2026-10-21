#ifndef CDD_SRC_SECULIB_SECUCOMMON_H
#define CDD_SRC_SECULIB_SECUCOMMON_H


#include "Std_Types.h"
#include "common.h"




void Secu_Memset(uint8 *dst, uint8 value, uint32 count);
boolean Secu_Memcmp(uint8 *dst, uint8 *src, uint32 count);


#endif  /* CDD_SRC_SECULIB_SECUCOMMON_H */

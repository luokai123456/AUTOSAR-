#ifndef CACHE_H_H
#define CACHE_H_H

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Switch_ICache(VAR(uint32, AUTOMATIC) u32Mcu_Switch_val);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Enable_ICache(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Disable_ICache(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Invalid_ICache_Set_Way \
( \
    VAR(uint32, AUTOMATIC) u32Mcu_Set, \
    VAR(uint32, AUTOMATIC) u32Mcu_way \
);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Invalid_ICache \
( \
    VAR(uint32, AUTOMATIC) u32Mcu_Base, \
    VAR(uint32, AUTOMATIC) u32Mcu_Len \
);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Switch_DCache \
( \
    VAR(uint32, AUTOMATIC) u32Mcu_Switch_val \
);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Enable_DCache(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Disable_DCache(void);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Invalid_DCache_Set_Way \
( \
    VAR(uint32, AUTOMATIC) u32Mcu_Set, \
    VAR(uint32, AUTOMATIC) u32Mcu_way \
);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Invalid_DCache \
( \
    VAR(uint32, AUTOMATIC) u32Mcu_Base, \
    VAR(uint32, AUTOMATIC) u32Mcu_Len \
);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#endif

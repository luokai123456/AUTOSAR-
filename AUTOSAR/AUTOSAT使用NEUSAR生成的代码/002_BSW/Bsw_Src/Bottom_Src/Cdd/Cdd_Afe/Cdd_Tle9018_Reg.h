#ifndef __CDD_TLE9018_REG_H_
#define __CDD_TLE9018_REG_H_

#include "Std_Types.h"

#define TLE9018_REG_PART_CFG_0              (uint8)0x01
#define TLE9018_REG_PART_CFG_1              (uint8)0x02
#define TLE9018_REG_GEN_CFG                 (uint8)0x03
#define TLE9018_REG_OL_OV_CFG               (uint8)0x04
#define TLE9018_REG_OL_UV_CFG               (uint8)0x05
#define TLE9018_REG_EXT_TEMP_CFG_0          (uint8)0x06
#define TLE9018_REG_EXT_TEMP_CFG_2          (uint8)0x08
#define TLE9018_REG_UC_OC_CFG               (uint8)0x0A
#define TLE9018_REG_RR_CFG_0                (uint8)0x0C
#define TLE9018_REG_RR_CFG_1                (uint8)0x0D
#define TLE9018_REG_FAULT_MASK_CONFIG       (uint8)0x0E
#define TLE9018_REG_GEN_DIAG                (uint8)0x0F
#define TLE9018_REG_CH_DIAG                 (uint8)0x10
#define TLE9018_REG_DIAG_1_0                (uint8)0x11
#define TLE9018_REG_DIAG_3_2                (uint8)0x12
#define TLE9018_REG_DIAG_5_4                (uint8)0x13
#define TLE9018_REG_DIAG_7_6                (uint8)0x14
#define TLE9018_REG_DIAG_9_8                (uint8)0x15
#define TLE9018_REG_DIAG_11_10              (uint8)0x16
#define TLE9018_REG_DIAG_13_12              (uint8)0x17
#define TLE9018_REG_DIAG_15_14              (uint8)0x18
#define TLE9018_REG_DIAG_17_16              (uint8)0x19
#define TLE9018_REG_EXT_TEMP_DIAG_0         (uint8)0x1A
#define TLE9018_REG_EXT_TEMP_DIAG_1         (uint8)0x1B
#define TLE9018_REG_TMP_REF_DIAG            (uint8)0x1C
#define TLE9018_REG_RR_SLEEP_STAT           (uint8)0x1E
#define TLE9018_REG_MULTI_READ              (uint8)0x31
#define TLE9018_REG_MULTI_READ_CFG          (uint8)0x32
#define TLE9018_REG_MULTI_READ_CFG_SEL      (uint8)0x33
#define TLE9018_REG_MULTI_READ_CFG_0        (uint8)0x34
#define TLE9018_REG_MULTI_READ_CFG_2        (uint8)0x36
#define TLE9018_REG_GEN_STAT                (uint8)0x38
#define TLE9018_REG_MEAS_CTRL               (uint8)0x3A
#define TLE9018_REG_MISC_CTRL               (uint8)0x3B
#define TLE9018_REG_EXT_TEMP_CTRL_0         (uint8)0x3C
#define TLE9018_REG_EXT_TEMP_CTRL_1         (uint8)0x3D
#define TLE9018_REG_PCVM_1                  (uint8)0x3E
#define TLE9018_REG_INT_TEMP_0              (uint8)0x5C
#define TLE9018_REG_INT_TEMP_1              (uint8)0x5D
#define EXT_TEMP_1                          (uint8)0x5E
#define TLE9018_REG_WDOG_CNT                (uint8)0xB0
#define TLE9018_REG_IF_CFG                  (uint8)0xC0
#define TLE9018_REG_ICVID                   (uint8)0xC2
#define TLE9018_REG_BAL_CNT_CFG_0           (uint8)0xE0
#define TLE9018_REG_BAL_CTRL_0              (uint8)0xE6
#define TLE9018_REG_BAL_CTRL_1              (uint8)0xE7
#define TLE9018_REG_OP_MODE                 (uint8)0x90
#define TLE9018_REG_AVM_CFG_0              (uint8)0x93
#define TLE9018_REG_AVM_CFG_1              (uint8)0x94

#define TLE9018_REG_EXT_TEMP_INTC_MASK      (0x1C00)
#define TLE9018_REG_EXT_TEMP_INTC_POS       (10)

#endif /*__CDD_TLE9018_REG_H_ */

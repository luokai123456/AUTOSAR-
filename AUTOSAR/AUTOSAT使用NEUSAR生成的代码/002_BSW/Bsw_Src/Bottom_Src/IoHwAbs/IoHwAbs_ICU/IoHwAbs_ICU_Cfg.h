/*** create info ***********************
*@ Author : liufengyuan
*@ date :2024-12-02
*@ Description :Abstraction Layer ICU configuration H file
**** modify info ***********************
*@ version :0.0
*@ Modifier : liufengyuan
*@ date :2024-12-02
*@ Modification Description :
初始版本
****************************************/
#ifndef IOHWABS_ICU_CFG_H
#define IOHWABS_ICU_CFG_H

/*******************************************************************************
 * Includes
 *******************************************************************************/
#include "Icu.h"

#define PWM_INPUT_DMA_MAX_CHANNELS          11

typedef struct {
    uint16         numIcuAbsIdx;
    uint16         numIcuInitIdx;
    uint8          numDmaBufSize;
    uint32*        IcuTimeStampBuf;
} IoHwAbs_IcuConfig_TDSTR;

typedef struct {
    uint16         numIcuAbsIdx;
    uint16         numIcuInitIdx;
} Icu_GetDutyChnCfg_TDSTR;

extern const IoHwAbs_IcuConfig_TDSTR IoHwAbs_valIcuConfig_STR[PWM_INPUT_DMA_MAX_CHANNELS];

#endif/*IOHWABS_ICU_CFG_H*/

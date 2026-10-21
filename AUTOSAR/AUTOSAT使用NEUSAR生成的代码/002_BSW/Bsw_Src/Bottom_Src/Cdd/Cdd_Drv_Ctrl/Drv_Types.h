#ifndef __DRV_TYPES_H_
#define __DRV_TYPES_H_

#include "typedefs.h"

#define DD_CTRL_IO_OFF  0
#define DD_CTRL_IO_ON   1
#define DD_CTRL_PWM     2
#define DD_CTRL_CHECK_DUTY(x)           ((x > 100) ? 1 : 0)

struct dd_ctrl {
    uint8	ch_id;
    uint16	ch_Level;
    uint16  ch_Level_Last;
    uint8   ch_DiagOutputDisCh;
};

struct dd_PwmCtrl {
	uint8	ch_Pwmstat;
    uint8	ch_Pwmid;
    uint32	ch_Frequency;
    uint32	ch_DutyCycle;
};

struct dd_parameter {
    uint16 r;
    uint16 k;
    uint32 IoutThres;
};

typedef struct{
    uint8   drv_ch;
    uint8   dio_dsel;
    uint8   adc_chcfb;
    uint8   adc_chdiag;
    boolean    dio_chsel;
    uint16  stg_errid;
    uint16  stb_errid;
    uint16  opl_errid;
    void*   parameter;
}dd_diaginfo;

#endif /* __DRV_TYPES_H_ */

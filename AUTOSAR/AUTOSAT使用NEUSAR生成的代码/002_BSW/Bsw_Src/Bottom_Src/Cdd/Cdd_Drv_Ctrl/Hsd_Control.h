#ifndef _HSD_CONTROL_H_
#define _HSD_CONTROL_H_

#include "IoHwAbs_DIO.h"
#include "IoHwAbs_ADC.h"
// #include "IoHwAbs_PWM.h"
#include "Drv_Types.h"

#define DD_HSD_DIO_CHANNEL_MAX                  10
#define DD_HSD_OPL_THRESH_Min                   2000
#define DD_HSD_OPL_THRESH_Max                   5000
#define DD_HSD_STB_THRESH                       9000
#define DD_HSD_STG_GET_IOUT(x, y, z)            ((x) / (y) * (z))

extern struct dd_ctrl Hsd_valDioCtrl_Mp[DD_HSD_DIO_CHANNEL_MAX];
extern void Cdd_Hsd_InitFunction(void);
extern void Cdd_Hsd_DiagFunction(void);
extern void Cdd_Hsd_ErrorDiag(dd_diaginfo* Dd_valInfo);
extern void Cdd_Hsd_10msMainFunction(void);

#endif /* __HSD_CONTROL_H_ */

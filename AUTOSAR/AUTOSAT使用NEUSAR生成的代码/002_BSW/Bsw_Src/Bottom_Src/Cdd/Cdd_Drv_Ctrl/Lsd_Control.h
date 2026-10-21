#ifndef _LSD_CONTROL_H_
#define _LSD_CONTROL_H_

#include "IoHwAbs_DIO.h"
#include "IoHwAbs_DIO_prv.h"
#include "IoHwAbs_ADC.h"
// #include "IoHwAbs_PWM.h"
#include "Drv_Types.h"

#define DD_LSD_LAMP_CHANNEL_MAX                 3
#define DD_LSD_DIO_CHANNEL_MAX                  4
#define DD_LSD_PWM_CHANNEL_MAX                  12
#define DD_LSD_OPL_THRESH_Min                   2000
#define DD_LSD_OPL_THRESH_Max                   5000
#define DD_LSD_STB_THRESH                       9000
#define DD_LSD_STG_GET_IOUT(x, y, z)            ((x) / (y) * (z))

extern struct dd_ctrl Lamp_valDioCtrl_Mp[DD_LSD_LAMP_CHANNEL_MAX];
extern struct dd_ctrl Lsd_valDioCtrl_Mp[DD_LSD_DIO_CHANNEL_MAX];
extern struct dd_PwmCtrl Lsd_valPwmCtrl_Mp[DD_LSD_PWM_CHANNEL_MAX];
extern void Cdd_Lsd_InitFunction(void);
extern void Cdd_Lsd_DiagFunction(void);
extern void Cdd_Lsd_ErrorDiag(dd_diaginfo* Dd_valInfo);
extern void Cdd_Lsd_10msMainFunction(void);

#endif /* __HSD_CONTROL_H_ */

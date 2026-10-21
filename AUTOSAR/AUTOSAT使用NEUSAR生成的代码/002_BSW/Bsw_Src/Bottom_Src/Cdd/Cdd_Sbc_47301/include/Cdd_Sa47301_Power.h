#ifndef _CDD_SA47301_POWER_H_
#define _CDD_SA47301_POWER_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "Cdd_Sa47301_Type.h"
#include "Cdd_Sa47301_Cfg.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SA47301_AR_REL_MAJOR_VER_POWER             4
#define SA47301_AR_REL_MINOR_VER_POWER             4
#define SA47301_AR_REL_REV_VER_POWER               0
#define SA47301_SW_MAJOR_VER_POWER                 1
#define SA47301_SW_MINOR_VER_POWER                 0
#define SA47301_SW_PATCH_VER_POWER                 0

/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same Autosar version */
#if (SA47301_AR_REL_MAJOR_VER_POWER != EB_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MAJOR_VER_POWER"
#endif
#if (SA47301_AR_REL_MINOR_VER_POWER != EB_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MINOR_VER_POWER"
#endif
#if (SA47301_AR_REL_REV_VER_POWER != EB_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_REV_VER_POWER"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (SA47301_SW_MAJOR_VER_POWER != EB_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MAJOR_VER_POWER"
#endif
#if (SA47301_SW_MINOR_VER_POWER != EB_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MINOR_VER_POWER"
#endif
#if (SA47301_SW_PATCH_VER_POWER != EB_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_PATCH_VER_POWER"
#endif
#ifdef __cplusplus
}
#endif

Std_ReturnType Cdd_Sbc_Sa47301_PowerOff(void);
void Cdd_Sbc_Sa47301_SetLdoEn(Cdd_Sa47301LdoCtrl_TDSTR *LdoCtrlstr);
Std_ReturnType Cdd_Sbc_Sa47301_SetWakeStatus(uint8 WakeStatus); 
Std_ReturnType Cdd_Sbc_Sa47301_SetWakeTime(uint32 wakeTime);


#endif /* _CDD_SA47301_POWER_H_ */
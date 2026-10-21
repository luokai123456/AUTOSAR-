#ifndef _CDD_SA47301_DIAG_H_
#define _CDD_SA47301_DIAG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Cdd_Sa47301_Type.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SA47301_AR_REL_MAJOR_VER_DIAG             4
#define SA47301_AR_REL_MINOR_VER_DIAG             4
#define SA47301_AR_REL_REV_VER_DIAG               0
#define SA47301_SW_MAJOR_VER_DIAG                 1
#define SA47301_SW_MINOR_VER_DIAG                 0
#define SA47301_SW_PATCH_VER_DIAG                 0

/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same Autosar version */
#if (SA47301_AR_REL_MAJOR_VER_DIAG != EB_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MAJOR_VER_DIAG"
#endif
#if (SA47301_AR_REL_MINOR_VER_DIAG != EB_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MINOR_VER_DIAG"
#endif
#if (SA47301_AR_REL_REV_VER_DIAG != EB_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_REV_VER_DIAG"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (SA47301_SW_MAJOR_VER_DIAG != EB_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MAJOR_VER_DIAG"
#endif
#if (SA47301_SW_MINOR_VER_DIAG != EB_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MINOR_VER_DIAG"
#endif
#if (SA47301_SW_PATCH_VER_DIAG != EB_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_PATCH_VER_DIAG"
#endif


Std_ReturnType Cdd_Sbc_Sa47301_ClearDiag(void);
boolean Cdd_Sbc_Sa47301_GetDiagStatus(Cdd_Sa47301Diag_TDEM DiagID);
Std_ReturnType Cdd_Sbc_Sa47301_SaveDiagStatus(void);
Std_ReturnType Cdd_Sbc_Sa47301_AbistEnFunction(Cdd_Sa47301AbistCfgType_TDSTR *AbistCfg);
Std_ReturnType Cdd_Sbc_Sa47301_GetAbistResrult(Cdd_Sa47301AbistResult_TDSTR *AbistResult, \
                                                uint32 *FailChMask);
#ifdef __cplusplus
}
#endif


#endif /* _CDD_SA47301_DIAG_H_ */
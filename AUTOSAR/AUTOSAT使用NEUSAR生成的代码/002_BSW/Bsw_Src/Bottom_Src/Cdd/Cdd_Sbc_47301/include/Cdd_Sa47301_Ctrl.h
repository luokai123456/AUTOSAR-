#ifndef _CDD_SA47301_CTRL_H_
#define _CDD_SA47301_CTRL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Cdd_Sa47301_Type.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SA47301_AR_REL_MAJOR_VER_Ctrl             4
#define SA47301_AR_REL_MINOR_VER_Ctrl             4
#define SA47301_AR_REL_REV_VER_Ctrl               0
#define SA47301_SW_MAJOR_VER_Ctrl                 1
#define SA47301_SW_MINOR_VER_Ctrl                 0
#define SA47301_SW_PATCH_VER_Ctrl                 0

/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same Autosar version */
#if (SA47301_AR_REL_MAJOR_VER_Ctrl != EB_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MAJOR_VER_Ctrl"
#endif
#if (SA47301_AR_REL_MINOR_VER_Ctrl != EB_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MINOR_VER_Ctrl"
#endif
#if (SA47301_AR_REL_REV_VER_Ctrl != EB_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_REV_VER_Ctrl"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (SA47301_SW_MAJOR_VER_Ctrl != EB_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MAJOR_VER_Ctrl"
#endif
#if (SA47301_SW_MINOR_VER_Ctrl != EB_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MINOR_VER_Ctrl"
#endif
#if (SA47301_SW_PATCH_VER_Ctrl != EB_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_PATCH_VER_Ctrl"
#endif


typedef struct
{
    uint8 question;
    uint8 response[4];
}Cdd_Sa47301FWdgResponse_TDSTR;


void Cdd_Sbc_Sa47301_FeedWWdg(void);
void Cdd_Sbc_Sa47301_FeedFWdg(void);
Std_ReturnType Cdd_Sbc_Sa47301_SetWdgEnStatus(Cdd_Sa47301WdgType_TDEN WdgType,uint8 wdgEnStatus);
Std_ReturnType SA47301_ProtectedRegMode_Function(boolean valLock_Lo);
Std_ReturnType Cdd_Sbc_Sa47301_CtrlErrMonStatusFunction(Cdd_Sa47301ErrMonType_STDR ErrMonCtrl);

#ifdef __cplusplus
}
#endif


#endif /* _CDD_SA47301_CTRL_H_ */
#ifndef _CDD_SA47301_COM_H_
#define _CDD_SA47301_COM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Cdd_Sa47301_Type.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SA47301_AR_REL_MAJOR_VER_COM             4
#define SA47301_AR_REL_MINOR_VER_COM             4
#define SA47301_AR_REL_REV_VER_COM               0
#define SA47301_SW_MAJOR_VER_COM                 1
#define SA47301_SW_MINOR_VER_COM                 0
#define SA47301_SW_PATCH_VER_COM                 0

/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same Autosar version */
#if (SA47301_AR_REL_MAJOR_VER_COM != EB_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MAJOR_VER_COM"
#endif
#if (SA47301_AR_REL_MINOR_VER_COM != EB_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MINOR_VER_COM"
#endif
#if (SA47301_AR_REL_REV_VER_COM != EB_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_REV_VER_COM"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (SA47301_SW_MAJOR_VER_COM != EB_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MAJOR_VER_COM"
#endif
#if (SA47301_SW_MINOR_VER_COM != EB_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MINOR_VER_COM"
#endif
#if (SA47301_SW_PATCH_VER_COM != EB_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_PATCH_VER_COM"
#endif

#define SPI_COM_ERR_FLAG          0x01
#define SPI_COM_NO_ERR_FLAG       0x00

typedef struct 
{ 
    uint8 valLockOrUnlockerr;
    uint8 valSpiFrameDurationErr;
    uint8 valSpiAdderssInvalidErr;
    uint8 valSpiLengthInvalidErr;
    uint8 valSpiFrameParityErr;
}Cdd_Sa47301SpiComErrType_TDSTR;

typedef struct 
{ 
    uint8 valErrFlag;
    Cdd_Sa47301SpiComErrType_TDSTR valErrTypeInfo;
}Cdd_Sa47301SpiComErrInfo_TDSTR;



Std_ReturnType Cdd_Sbc_Sa47301_SpiTransmit(Cdd_Sa47301SpiInfo_TDSTR *Sa47301SpiDataInfo, uint8 valRW_Lo, uint8 valRegAddr_Lo, uint8 RegDate);
Std_ReturnType Cdd_Sbc_Sa47301_SpiComErrCheck(Cdd_Sa47301SpiInfo_TDSTR *Sa47301SpiDataInfo, Cdd_Sa47301SpiComErrInfo_TDSTR *Sa47301SpiComErrInfo);


#ifdef __cplusplus
}
#endif


#endif /* _CDD_SA47301_COM_H_*/
#ifdef __cplusplus
extern "C" {
#endif
#include "Cdd_Sa47301_Com.h"
#include "Cdd_Sa47301_Reg.h"
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SA47301_AR_REL_MAJOR_VER_COM_C             4
#define SA47301_AR_REL_MINOR_VER_COM_C             4
#define SA47301_AR_REL_REV_VER_COM_C               0
#define SA47301_SW_MAJOR_VER_COM_C                 1
#define SA47301_SW_MINOR_VER_COM_C                 0
#define SA47301_SW_PATCH_VER_COM_C                 0

/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same Autosar version */
#if (SA47301_AR_REL_MAJOR_VER_COM_C != EB_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MAJOR_VER_COM_C"
#endif
#if (SA47301_AR_REL_MINOR_VER_COM_C != EB_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MINOR_VER_COM_C"
#endif
#if (SA47301_AR_REL_REV_VER_COM_C != EB_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_REV_VER_COM_C"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (SA47301_SW_MAJOR_VER_COM_C != EB_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MAJOR_VER_COM_C"
#endif
#if (SA47301_SW_MINOR_VER_COM_C != EB_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MINOR_VER_COM_C"
#endif
#if (SA47301_SW_PATCH_VER_COM_C != EB_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_PATCH_VER_COM_C"
#endif


static uint16 Sa47301_ParityCalculate_Function(uint16 Sa47301_data_Lo) 
{
    uint16 valParity_Lo = 0;

    while(Sa47301_data_Lo != 0U)
    {
        valParity_Lo++;  
        Sa47301_data_Lo &= (Sa47301_data_Lo - 1U);   
    }

    return (valParity_Lo%2)?1:0;

}

static Std_ReturnType Sa47301_ParityCheck_Function(uint16 Sa47301_data_Lo) 
{
    uint8 valParity_Lo = 0;
    uint16 DataParity = (Sa47301_data_Lo & 0x0001);
    Std_ReturnType ret = E_NOT_OK;

    for(uint8 numBitCnt_Lo = 1; numBitCnt_Lo < 16;numBitCnt_Lo++)
    {
        if ((Sa47301_data_Lo >> numBitCnt_Lo) & 0x01)
        {
        	valParity_Lo++;
        }
    }

    if (((valParity_Lo%2)?1:0) == DataParity) {
        ret =  E_OK;
    }
    else {
        ret =  E_NOT_OK;
    }
    return ret;

}

Std_ReturnType Cdd_Sbc_Sa47301_SpiTransmit(Cdd_Sa47301SpiInfo_TDSTR *Sa47301SpiDataInfo, uint8 valRW_Lo, uint8 valRegAddr_Lo, uint8 RegDate)
{
    Std_ReturnType ret = E_OK;
    uint16 ReadDate = 0;

    CHECK_PTR_NULL_RET(Sa47301SpiDataInfo->SpiReceiveCallBack, 0xFF);
    CHECK_PTR_NULL_RET(Sa47301SpiDataInfo->SpiSendCallBack, 0xFF);

    Sa47301SpiDataInfo->TxFrame.FrameData = 0;
    Sa47301SpiDataInfo->RxFrame.FrameData = 0;
    Sa47301SpiDataInfo->TxFrame.BITS.ADDRESS = valRegAddr_Lo;
    Sa47301SpiDataInfo->TxFrame.BITS.RW = valRW_Lo;
    Sa47301SpiDataInfo->TxFrame.BITS.DATA = RegDate;
    Sa47301SpiDataInfo->TxFrame.BITS.PARITY = Sa47301_ParityCalculate_Function(Sa47301SpiDataInfo->TxFrame.FrameData);

    Sa47301SpiDataInfo->SpiSendCallBack(Sa47301SpiDataInfo->TxFrame.FrameData);

    Sa47301SpiDataInfo->RxFrame.FrameData = Sa47301SpiDataInfo->SpiReceiveCallBack();
    ret = Sa47301_ParityCheck_Function(Sa47301SpiDataInfo->RxFrame.FrameData); 


    return ret;
}

Std_ReturnType Cdd_Sbc_Sa47301_SpiComErrCheck(Cdd_Sa47301SpiInfo_TDSTR *Sa47301SpiDataInfo, Cdd_Sa47301SpiComErrInfo_TDSTR *Sa47301SpiComErrInfo)
{
    Std_ReturnType ret = E_OK;

    CHECK_PTR_NULL_RET(Sa47301SpiDataInfo->SpiReceiveCallBack, 0xFF);
    CHECK_PTR_NULL_RET(Sa47301SpiDataInfo->SpiSendCallBack, 0xFF);

    Sa47301SpiDataInfo->TxFrame.FrameData = 0;
    Sa47301SpiDataInfo->RxFrame.FrameData = 0;
    Sa47301SpiDataInfo->TxFrame.BITS.ADDRESS = SA_REG_SPISTATUS_TAG;
    Sa47301SpiDataInfo->TxFrame.BITS.RW = SA47301_SPI_READ;
    Sa47301SpiDataInfo->TxFrame.BITS.DATA = 0;
    Sa47301SpiDataInfo->TxFrame.BITS.PARITY = Sa47301_ParityCalculate_Function(Sa47301SpiDataInfo->TxFrame.FrameData);

    Sa47301SpiDataInfo->SpiSendCallBack(Sa47301SpiDataInfo->TxFrame.FrameData);

    Sa47301SpiDataInfo->RxFrame.FrameData = Sa47301SpiDataInfo->SpiReceiveCallBack();

    ret = Sa47301_ParityCheck_Function(Sa47301SpiDataInfo->RxFrame.FrameData);

    if (ret == E_OK) 
    {
        if(Sa47301SpiDataInfo->RxFrame.BITS.DATA != 0)
        {
            Sa47301SpiComErrInfo->valErrFlag = SPI_COM_ERR_FLAG;
            Sa47301SpiComErrInfo->valErrTypeInfo.valLockOrUnlockerr = ((Sa47301SpiDataInfo->RxFrame.BITS.DATA >> 4) & 0x01);
            Sa47301SpiComErrInfo->valErrTypeInfo.valSpiFrameDurationErr = ((Sa47301SpiDataInfo->RxFrame.BITS.DATA >> 3) & 0x01);
            Sa47301SpiComErrInfo->valErrTypeInfo.valSpiAdderssInvalidErr = ((Sa47301SpiDataInfo->RxFrame.BITS.DATA >> 2) & 0x01);
            Sa47301SpiComErrInfo->valErrTypeInfo.valSpiLengthInvalidErr = ((Sa47301SpiDataInfo->RxFrame.BITS.DATA >> 1) & 0x01);
            Sa47301SpiComErrInfo->valErrTypeInfo.valSpiFrameParityErr = ((Sa47301SpiDataInfo->RxFrame.BITS.DATA >> 0) & 0x01);
        }
    }
    
    return ret;
}


#ifdef __cplusplus
}
#endif

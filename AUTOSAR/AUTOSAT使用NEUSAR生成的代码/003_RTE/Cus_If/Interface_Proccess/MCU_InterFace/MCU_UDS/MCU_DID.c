/*
 * File: MCU_DID.c
 *
 * Code generated for Simulink model 'MCU_DID'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Aug 10 14:06:22 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
// #define FXS_DIDTestSwitch 1

#include "MCU_DID.h"
#include "MCU_DID_private.h"

/* Model step function */
uint8 DID_0x0402_OverVal = 0U;
Std_ReturnType IPU_DTC_0x0402_CS_ReadData(UInt8_T OpStatus, uint8 *Data, UInt8_T
  *ErrorCode)
{
#ifdef FXS_DIDTestSwitch
    *Data = DID_0x0402_OverVal;
#else
    uint16 tmpRead;
    UNUSED_PARAMETER(OpStatus);

    /* Inport: '<Root>/IPU_DTC_IPU_DTC' */
    (void)Rte_Read_IPU_DTC_IPU_DTC(&tmpRead);

    /* Outputs for Function Call SubSystem: '<Root>/IPU_DTC_0x0402_CS_ReadData_sys' */
    /* DataTypeConversion: '<S1>/Data Type Conversion6' incorporates:
     *  SignalConversion generated from: '<S1>/IPU_DTC_IPU_DTC_read'
     */
    if (tmpRead > 255) {
        tmpRead = 255U;
    }

    /* SignalConversion generated from: '<S1>/Data' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion6'
     */
    *Data = (uint8)tmpRead;

    /* SignalConversion generated from: '<S1>/ErrorCode' */
    *ErrorCode = 0U;

    /* SignalConversion generated from: '<S1>/ERR' */
    return 0U;

    /* End of Outputs for SubSystem: '<Root>/IPU_DTC_0x0402_CS_ReadData_sys' */
#endif
}

uint8 DID_0x04CF_OverVal = 0U;
/* Model step function */
Std_ReturnType IPU_DischgState_0X04CF_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
#ifdef FXS_DIDTestSwitch
    *Data = DID_0x04CF_OverVal;
#else
    UNUSED_PARAMETER(OpStatus);

    /* Outputs for Function Call SubSystem: '<Root>/IPU_DischgState_0X04CF_CS_ReadData_sys' */
    /* SignalConversion generated from: '<S2>/Data' incorporates:
     *  Inport: '<Root>/IPU_DischgState_IPU_DischgState'
     */
    (void)Rte_Read_IPU_DischgState_IPU_DischgState(Data);

    /* SignalConversion generated from: '<S2>/ErrorCode' */
    *ErrorCode = 0U;

    /* SignalConversion generated from: '<S2>/ERR' */
    return 0U;

    /* End of Outputs for SubSystem: '<Root>/IPU_DischgState_0X04CF_CS_ReadData_sys' */
#endif
}

uint8 DID_0x0409_OverVal = 0U;
/* Model step function */
Std_ReturnType IPU_HVBusCur_0x0409_CS_ReadData(UInt8_T OpStatus, uint8 Data[2],
  UInt8_T *ErrorCode)
{
#ifdef FXS_DIDTestSwitch
    Data[0] = DID_0x0409_OverVal;
#else
    uint16 tmpRead;
    UNUSED_PARAMETER(OpStatus);

    /* Inport: '<Root>/IPU_HVBusCur_IPU_HVBusCur' */
    (void)Rte_Read_IPU_HVBusCur_IPU_HVBusCur(&tmpRead);

    /* Outputs for Function Call SubSystem: '<Root>/IPU_HVBusCur_0x0409_CS_ReadData_sys' */
    /* SignalConversion generated from: '<S3>/Data' incorporates:
     *  ArithShift: '<S14>/Shift Arithmetic'
     *  ArithShift: '<S14>/Shift Arithmetic1'
     *  ArithShift: '<S14>/Shift Arithmetic2'
     *  DataTypeConversion: '<S14>/Data Type Conversion5'
     *  DataTypeConversion: '<S14>/Data Type Conversion6'
     *  SignalConversion generated from: '<S3>/IPU_HVBusCur_IPU_HVBusCur_read'
     */
    Data[0] = (uint8)((uint32)tmpRead >> 8);
    Data[1] = (uint8)((uint32)(uint16)(tmpRead << 8) >> 8);

    /* SignalConversion generated from: '<S3>/ErrorCode' */
    *ErrorCode = 0U;

    /* SignalConversion generated from: '<S3>/ERR' */
    return 0U;

    /* End of Outputs for SubSystem: '<Root>/IPU_HVBusCur_0x0409_CS_ReadData_sys' */
#endif
}

uint8 DID_0x0408_OverVal = 0U;
/* Model step function */
Std_ReturnType IPU_HVBusVolt_500_0x0408_CS_ReadData(UInt8_T OpStatus, uint8
  Data[2], UInt8_T *ErrorCode)
{
#ifdef FXS_DIDTestSwitch
    Data[0] = DID_0x0408_OverVal;
#else
    uint16 tmpRead;
    UNUSED_PARAMETER(OpStatus);

    /* Inport: '<Root>/IPU_HVBusVolt_500_IPU_HVBusVolt_500' */
    (void)Rte_Read_IPU_HVBusVolt_500_IPU_HVBusVolt_500(&tmpRead);

    /* Outputs for Function Call SubSystem: '<Root>/IPU_HVBusVolt_500_0x0408_CS_ReadData_sys' */
    /* SignalConversion generated from: '<S4>/Data' incorporates:
     *  ArithShift: '<S15>/Shift Arithmetic'
     *  ArithShift: '<S15>/Shift Arithmetic1'
     *  ArithShift: '<S15>/Shift Arithmetic2'
     *  DataTypeConversion: '<S15>/Data Type Conversion5'
     *  DataTypeConversion: '<S15>/Data Type Conversion6'
     *  SignalConversion generated from: '<S4>/IPU_HVBusVolt_500_IPU_HVBusVolt_500_read'
     */
    Data[0] = (uint8)((uint32)tmpRead >> 8);
    Data[1] = (uint8)((uint32)(uint16)(tmpRead << 8) >> 8);

    /* SignalConversion generated from: '<S4>/ErrorCode' */
    *ErrorCode = 0U;

    /* SignalConversion generated from: '<S4>/ERR' */
    return 0U;

    /* End of Outputs for SubSystem: '<Root>/IPU_HVBusVolt_500_0x0408_CS_ReadData_sys' */
#endif
}

uint8 DID_0x040C_OverVal = 0U;
/* Model step function */
Std_ReturnType IPU_IsgInvrT_0x040C_CS_ReadData(UInt8_T OpStatus, UInt8_T *Data,
  UInt8_T *ErrorCode)
{
#ifdef FXS_DIDTestSwitch
    *Data = DID_0x040C_OverVal;
#else
    UNUSED_PARAMETER(OpStatus);

    /* Outputs for Function Call SubSystem: '<S5>/IPU_IsgInvrT_0x040C_CS_ReadData_sys' */
    /* SignalConversion generated from: '<S16>/Data' */
    *Data = 0U;

    /* SignalConversion generated from: '<S16>/ErrorCode' */
    *ErrorCode = 0U;

    /* SignalConversion generated from: '<S16>/ERR' */
    return 0U;

    /* End of Outputs for SubSystem: '<S5>/IPU_IsgInvrT_0x040C_CS_ReadData_sys' */
#endif
}

uint8 DID_0x040B_OverVal = 0U;
/* Model step function */
Std_ReturnType IPU_IsgMotT_0x040B_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
#ifdef FXS_DIDTestSwitch
    *Data = DID_0x040B_OverVal;
#else
    uint8 tmpRead;
    UNUSED_PARAMETER(OpStatus);

    /* Inport: '<Root>/IPU_IsgMotT_IPU_IsgMotT' */
    (void)Rte_Read_IPU_IsgMotT_IPU_IsgMotT(&tmpRead);

    /* Outputs for Function Call SubSystem: '<Root>/IPU_IsgMotT_0x040B_CS_ReadData_sys' */
    /* SignalConversion generated from: '<S6>/Data' incorporates:
     *  ArithShift: '<S6>/Shift Arithmetic1'
     */
    *Data = 0U;

    /* SignalConversion generated from: '<S6>/ErrorCode' */
    *ErrorCode = 0U;

    /* SignalConversion generated from: '<S6>/ERR' */
    return 0U;

    /* End of Outputs for SubSystem: '<Root>/IPU_IsgMotT_0x040B_CS_ReadData_sys' */
#endif
}

uint8 DID_0x0403_OverVal = 0U;
/* Model step function */
Std_ReturnType IPU_IsgSpdActSgn_0x0403_CS_ReadData(UInt8_T OpStatus, uint8 Data
  [2], UInt8_T *ErrorCode)
{
#ifdef FXS_DIDTestSwitch
    Data[0] = DID_0x0403_OverVal;
#else
    uint16 tmpRead;
    UNUSED_PARAMETER(OpStatus);

    /* Inport: '<Root>/IPU_IsgSpdActSgn_IPU_IsgSpdActSgn' */
    (void)Rte_Read_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn(&tmpRead);

    /* Outputs for Function Call SubSystem: '<Root>/IPU_IsgSpdActSgn_0x0403_CS_ReadData_sys' */
    /* SignalConversion generated from: '<S7>/Data' incorporates:
     *  ArithShift: '<S17>/Shift Arithmetic'
     *  ArithShift: '<S17>/Shift Arithmetic1'
     *  ArithShift: '<S17>/Shift Arithmetic2'
     *  DataTypeConversion: '<S17>/Data Type Conversion5'
     *  DataTypeConversion: '<S17>/Data Type Conversion6'
     *  SignalConversion generated from: '<S7>/IPU_IsgSpdActSgn_IPU_IsgSpdActSgn_read'
     */
    Data[0] = (uint8)((uint32)tmpRead >> 8);
    Data[1] = (uint8)((uint32)(uint16)(tmpRead << 8) >> 8);

    /* SignalConversion generated from: '<S7>/ErrorCode' */
    *ErrorCode = 0U;

    /* SignalConversion generated from: '<S7>/ERR' */
    return 0U;

    /* End of Outputs for SubSystem: '<Root>/IPU_IsgSpdActSgn_0x0403_CS_ReadData_sys' */
#endif
}

uint8 DID_0x0404_OverVal = 0U;
/* Model step function */
Std_ReturnType IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData(UInt8_T OpStatus, uint8
  Data[2], UInt8_T *ErrorCode)
{
#ifdef FXS_DIDTestSwitch
    Data[0] = DID_0x0404_OverVal;
#else
    uint16 tmpRead;
    UNUSED_PARAMETER(OpStatus);

    /* Inport: '<Root>/IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct' */
    (void)Rte_Read_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct(&tmpRead);

    /* Outputs for Function Call SubSystem: '<Root>/IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_sys' */
    /* SignalConversion generated from: '<S8>/Data' incorporates:
     *  ArithShift: '<S18>/Shift Arithmetic'
     *  ArithShift: '<S18>/Shift Arithmetic1'
     *  ArithShift: '<S18>/Shift Arithmetic2'
     *  DataTypeConversion: '<S18>/Data Type Conversion5'
     *  DataTypeConversion: '<S18>/Data Type Conversion6'
     *  SignalConversion generated from: '<S8>/IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct_read'
     */
    Data[0] = (uint8)((uint32)tmpRead >> 8);
    Data[1] = (uint8)((uint32)(uint16)(tmpRead << 8) >> 8);

    /* SignalConversion generated from: '<S8>/ErrorCode' */
    *ErrorCode = 0U;

    /* SignalConversion generated from: '<S8>/ERR' */
    return 0U;

    /* End of Outputs for SubSystem: '<Root>/IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_sys' */
#endif
}

uint8 DID_0x040D_OverVal = 0U;
/* Model step function */
Std_ReturnType IPU_MotorTemp_0x040D_CS_ReadData(UInt8_T OpStatus, uint8 *Data,
  UInt8_T *ErrorCode)
{
#ifdef FXS_DIDTestSwitch
    *Data = DID_0x040D_OverVal;
#else
    UNUSED_PARAMETER(OpStatus);

    /* Outputs for Function Call SubSystem: '<Root>/IPU_MotorTemp_0x040D_CS_ReadData_sys' */
    /* SignalConversion generated from: '<S9>/Data' incorporates:
     *  Inport: '<Root>/IPU_IsgInvrT_IPU_IsgInvrT'
     */
    (void)Rte_Read_IPU_IsgInvrT_IPU_IsgInvrT(Data);

    /* SignalConversion generated from: '<S9>/ErrorCode' */
    *ErrorCode = 0U;

    /* SignalConversion generated from: '<S9>/ERR' */
    return 0U;

    /* End of Outputs for SubSystem: '<Root>/IPU_MotorTemp_0x040D_CS_ReadData_sys' */
#endif
}

uint8 DID_0x0406_OverVal = 0U;
/* Model step function */
Std_ReturnType IPU_TqAvlIsgMax_0x0406_CS_ReadData(UInt8_T OpStatus, uint8 Data[2],
  UInt8_T *ErrorCode)
{
#ifdef FXS_DIDTestSwitch
    Data[0] = DID_0x0406_OverVal;
#else
    uint16 tmpRead;
    UNUSED_PARAMETER(OpStatus);

    /* Inport: '<Root>/IPU_TqAvlIsgMax_IPU_TqAvlIsgMax' */
    (void)Rte_Read_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax(&tmpRead);

    /* Outputs for Function Call SubSystem: '<Root>/IPU_TqAvlIsgMax_0x0406_CS_ReadData_sys' */
    /* SignalConversion generated from: '<S10>/Data' incorporates:
     *  ArithShift: '<S19>/Shift Arithmetic'
     *  ArithShift: '<S19>/Shift Arithmetic1'
     *  ArithShift: '<S19>/Shift Arithmetic2'
     *  DataTypeConversion: '<S19>/Data Type Conversion5'
     *  DataTypeConversion: '<S19>/Data Type Conversion6'
     *  SignalConversion generated from: '<S10>/IPU_TqAvlIsgMax_IPU_TqAvlIsgMax_read'
     */
    Data[0] = (uint8)((uint32)tmpRead >> 8);
    Data[1] = (uint8)((uint32)(uint16)(tmpRead << 8) >> 8);

    /* SignalConversion generated from: '<S10>/ErrorCode' */
    *ErrorCode = 0U;

    /* SignalConversion generated from: '<S10>/ERR' */
    return 0U;

    /* End of Outputs for SubSystem: '<Root>/IPU_TqAvlIsgMax_0x0406_CS_ReadData_sys' */
#endif
}

uint8 DID_0x0407_OverVal = 0U;
/* Model step function */
Std_ReturnType IPU_TqAvlIsgMin_0x0407_CS_ReadData(UInt8_T OpStatus, uint8 Data[2],
  UInt8_T *ErrorCode)
{
#ifdef FXS_DIDTestSwitch
    Data[0] = DID_0x0407_OverVal;
#else
    uint16 tmpRead;
    UNUSED_PARAMETER(OpStatus);

    /* Inport: '<Root>/IPU_TqAvlIsgMin_IPU_TqAvlIsgMin' */
    (void)Rte_Read_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin(&tmpRead);

    /* Outputs for Function Call SubSystem: '<Root>/IPU_TqAvlIsgMin_0x0407_CS_ReadData_sys' */
    /* SignalConversion generated from: '<S11>/Data' incorporates:
     *  ArithShift: '<S20>/Shift Arithmetic'
     *  ArithShift: '<S20>/Shift Arithmetic1'
     *  ArithShift: '<S20>/Shift Arithmetic2'
     *  DataTypeConversion: '<S20>/Data Type Conversion5'
     *  DataTypeConversion: '<S20>/Data Type Conversion6'
     *  SignalConversion generated from: '<S11>/IPU_TqAvlIsgMin_IPU_TqAvlIsgMin_read'
     */
    Data[0] = (uint8)((uint32)tmpRead >> 8);
    Data[1] = (uint8)((uint32)(uint16)(tmpRead << 8) >> 8);

    /* SignalConversion generated from: '<S11>/ErrorCode' */
    *ErrorCode = 0U;

    /* SignalConversion generated from: '<S11>/ERR' */
    return 0U;

    /* End of Outputs for SubSystem: '<Root>/IPU_TqAvlIsgMin_0x0407_CS_ReadData_sys' */
#endif
}

uint8 DID_0x0405_OverVal = 0U;
/* Model step function */
Std_ReturnType PMS_DriverDemandTorque_0x0405_CS_ReadData(UInt8_T OpStatus, uint8
  Data[2], UInt8_T *ErrorCode)
{
#ifdef FXS_DIDTestSwitch
    Data[0] = DID_0x0405_OverVal;
#else
    uint16 tmpRead;
    UNUSED_PARAMETER(OpStatus);

    /* Inport: '<Root>/PMS_DriverDemandTorque_PMS_DriverDemandTorque' */
    (void)Rte_Read_PMS_DriverDemandTorque_PMS_DriverDemandTorque(&tmpRead);

    /* Outputs for Function Call SubSystem: '<Root>/PMS_DriverDemandTorque_0x0405_CS_ReadData_sys' */
    /* SignalConversion generated from: '<S13>/Data' incorporates:
     *  ArithShift: '<S21>/Shift Arithmetic'
     *  ArithShift: '<S21>/Shift Arithmetic1'
     *  ArithShift: '<S21>/Shift Arithmetic2'
     *  DataTypeConversion: '<S21>/Data Type Conversion5'
     *  DataTypeConversion: '<S21>/Data Type Conversion6'
     *  SignalConversion generated from: '<S13>/PMS_DriverDemandTorque_PMS_DriverDemandTorque_read'
     */
    Data[0] = (uint8)((uint32)tmpRead >> 8);
    Data[1] = (uint8)((uint32)(uint16)(tmpRead << 8) >> 8);

    /* SignalConversion generated from: '<S13>/ErrorCode' */
    *ErrorCode = 0U;

    /* SignalConversion generated from: '<S13>/ERR' */
    return 0U;

    /* End of Outputs for SubSystem: '<Root>/PMS_DriverDemandTorque_0x0405_CS_ReadData_sys' */
#endif
}


/* Model initialize function */
void MCU_DID_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

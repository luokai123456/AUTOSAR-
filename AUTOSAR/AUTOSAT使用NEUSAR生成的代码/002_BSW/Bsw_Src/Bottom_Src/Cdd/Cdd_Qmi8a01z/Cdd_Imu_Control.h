#ifndef __CDD_IMU_CONTROL_H_
#define __CDD_IMU_CONTROL_H_

#include "Cdd_Imu_Qmi8a01z.h"

extern QMI8A01Z_DevType* Imu_valDevPtr_Mp;
extern void Cdd_Imu_Init(void);
extern void Cdd_Imu_MainFunction_10ms(void);

#endif /* __CDD_IMU_CONTROL_H_ */

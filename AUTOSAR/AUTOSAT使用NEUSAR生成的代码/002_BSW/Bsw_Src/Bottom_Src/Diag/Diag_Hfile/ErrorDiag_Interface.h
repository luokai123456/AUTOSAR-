#ifndef ERRORDIAG_INTERFACE_H
#define ERRORDIAG_INTERFACE_H


#include "Std_Types.h"


/**
 * @brief 获取故障状态
 * 
 * @param ErrorId 故障ID，来自ErrorDiag_Errorid.h或ErrorDiag_Errorid_ASW.h
 * @return boolean 0: 无故障，1: 有故障
 */
extern boolean ErrorDiag_Receive_ErrorStatus(uint16 ErrorId);

/**
 * @brief 清除故障状态
 * 
 * @param ErrorId 故障ID，来自ErrorDiag_Errorid.h或ErrorDiag_Errorid_ASW.h
 * @return Std_ReturnType E_OK: 成功，E_NOT_OK：故障ID超出范围，失败
 */
extern Std_ReturnType ErrorDiag_ClearErrorStatus(uint16 ErrorId);

/**
 * @brief 请求软件复位，异步
 * 
 */
extern void ErrorHandler_RequestReset(void);

/**
 * @brief 请求拉ErrorPin，异步
 * 
 */
extern void ErrorHandler_RequestSetErrorPin(void);


#endif  /* ERRORDIAG_INTERFACE_H */

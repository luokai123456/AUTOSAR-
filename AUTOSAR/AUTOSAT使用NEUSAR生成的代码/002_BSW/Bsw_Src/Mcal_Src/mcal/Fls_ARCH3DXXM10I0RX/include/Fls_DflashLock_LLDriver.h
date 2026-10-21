/*
 * Fls_DfashLock_LLDriver.h
 *
 *  Created on: 2025��11��17��
 *      Author: zjjin
 */
/* PRQA S 1535,1752 EOF */
#ifndef FLS_DFLASHLOCK_LLDRIVER_H_
#define FLS_DFLASHLOCK_LLDRIVER_H_

#include "status.h"

#define Flash_Ack	0x20000
#define Host_Ack	0x20000

#define RTE_HSM_SEMA42_GATE_ID             11UL

typedef enum
{
	S_OK = STATUS_SUCCESS,
	S_BUSY = STATUS_BUSY,
	S_TIMEOUT = STATUS_TIMEOUT,
	S_ERROR = STATUS_ERROR,
} LOCK_STATUS;

typedef enum
{
	UNLOCK,
	LOCK_HSM,
	LOCK_HOST_FLS,
	LOCK_HOST_BIN,
} LOCK_TYPE;

typedef enum
{
	INIT,
	QUICK,
	ISRTRIG,
} LOCK_PATH;

#define TIMEMAX (10000U)

typedef uint16_t lock_status_t;

extern volatile uint8_t Flash_Lock;

extern lock_status_t Host_Flash_TryLock(LOCK_TYPE master);

extern lock_status_t Host_Flash_UnLock(LOCK_TYPE master);

extern void Host_Flash_LockInit(void);

extern lock_status_t Host_Flash_Request_Done(void);

extern lock_status_t Host_Flash_Request(void);

extern uint8_t Host_Flash_ReadLock(void);

#endif /* FLS_DFLASHLOCK_LLDRIVER_H_ */

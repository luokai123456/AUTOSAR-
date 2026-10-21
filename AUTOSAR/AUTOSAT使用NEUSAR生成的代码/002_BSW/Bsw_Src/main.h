#ifndef MAIN_H__
#define MAIN_H__

//#define TEST_CODE //wjc:delete Neusar TEST_CODE

#include "derivative.h"

#ifdef TEST_CODE
#include "test_main.h"
#endif

typedef void (*BootFunc) (void);

extern const uint32_t IntcIsrVectorTable[];/*PRQA S 3684*/
extern void Intc_Init(void);

extern void VTABLE(void);/*PRQA S 1753*/

#if defined(MCORE_INIT)
extern void Mcore_Init(void);
#endif
void XBAR_config(void);
// void Core0Main(void);
// void Core1Main(void);
// void Core2Main(void);
// void Core3Main(void);
// void Core4Main(void);
// void Core5Main(void);


#endif

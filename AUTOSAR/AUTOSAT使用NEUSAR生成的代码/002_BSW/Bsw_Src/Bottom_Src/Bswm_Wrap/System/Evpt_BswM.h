
#ifndef EVPT_BSWM_H
#define EVPT_BSWM_H

FUNC(void, BSWM_CODE) InitToRun_Action(void);
FUNC(void, BSWM_CODE) PostRunToRun_Action(void);
FUNC(void, BSWM_CODE) PostRunToShutdown_Action(void);
FUNC(void, BSWM_CODE) RunToPostRun_Action(void);
FUNC(void, BSWM_CODE) SoftReset_Action(void);
FUNC(void, BSWM_CODE) BootReset_Action(void);
FUNC(void, BSWM_CODE) HardReset_Action(void);


extern FUNC(void, BSWM_CODE)BswM_CanIf_NORMAL(void);
extern FUNC(void, BSWM_CODE)BswM_CanIf_SLEEP(void);
extern FUNC(void, BSWM_CODE)BswM_Nvm_WriteAll(void);
extern FUNC(void, BSWM_CODE)BswM_Nvm_ReadAll(void);
extern FUNC(void, BSWM_CODE)BswM_TPT1145_NORMAL(void);
extern FUNC(void, BSWM_CODE)BswM_TPT1145_SLEEP(void);

#endif

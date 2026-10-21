/****************************************************************
 * 模块：Cdd层 - LSD_HELS121D驱动
 * 版本：主版本.次版本.修订号
 * ==================== 修改记录 ====================
 * V0.1.0 (初始版本)
 * 1. 支持LSD_HELS121D控制功能
 * 2. 支持LSD_HELS121D诊断功能
 * ==================================================
 ****************************************************************/
#ifndef EVPTCDD_HELS121D_PRV_H_
#define EVPTCDD_HELS121D_PRV_H_
/*******************************************************************************
 * Includes
 *******************************************************************************/
#include "Std_Types.h"

typedef struct
{
	uint16 valSG_Threshold;
	uint16 valOL_LowThreshold;
	uint16 valOL_HighThreshold;
	uint16 valSB_Threshold;
}HELS121D_DiagThrCfg_STR;


typedef struct
{
    uint8 OPL_Errorid;
    uint8 STB_Errorid;
	uint8 STG_Errorid;
} Lsd_ErrorIdMap_Str;

#define HELS121D_Io_LsOutCh0_Ctrl 	0
#define HELS121D_Io_LsOutCh1_Ctrl 	1
#define HELS121D_Io_LsOutCh2_Ctrl 	2
#define HELS121D_Io_LsOutCh3_Ctrl 	3
#define HELS121D_Io_numOutPutMax	4
#define HELS121D_DIAG_ErrNumMax	3

extern uint8 HELS121D_stDriveOut_Mp[HELS121D_Io_numOutPutMax];
extern Std_ReturnType HELS121D_DiagThresholdCfg(uint8 HELS121D_valChannl_Lo ,HELS121D_DiagThrCfg_STR *valThresholdCfg_Lo);
extern void ErrHdlr_HELS121D_ErrDetect(void);
extern void ErrHdlr_HELS121D_ErrRecover(void);
extern void EH_HELS121D_Diag(void);
extern void Cdd_Lsd_DiagFunction(void);


#endif /* EVPTCDD_HELS121D_PRV_H_ */

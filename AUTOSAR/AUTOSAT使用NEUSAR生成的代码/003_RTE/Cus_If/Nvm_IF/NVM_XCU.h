
#include "StandardTypes.h"
#include "Rte_Type.h"
typedef struct
{
	uint8 	 BlockID;					//块ID
	uint8* 	 BlockDataAdrr;				//块数据地址
	boolean* RequestFlg;				//处理请求标志位        0:不请求    1:请求
	uint8    BlockSts;				    //Block状态            0:操作成功  1:操作失败   2:正在操作
    uint8    RequestFinishFlg;          //下电请求标志位        0:未请求    1:已请求
    uint8*   NvMFunRetValAdrr;          //NvM函数返回值存放地址
}XCU_NVMBlockArrayType;


#define XCU_NVMBLOCKARRAY_SIZE          (sizeof(XCU_NVMBlockImmeArray)/sizeof(XCU_NVMBlockArrayType))
#define XCU_NVMBLOCKPOWEROFFARRAY_SIZE  (sizeof(XCU_NVMBlockPowerOffArray)/sizeof(XCU_NVMBlockArrayType))



#define ASW_NvRam_App1_MP Rte_swc_DiagcEveHndlg_NvRam_App1
#define ASW_NvRam_App2_MP Rte_swc_DiagcEveHndlg_NvRam_App2
#define ASW_NvRam_App3_MP Rte_swc_DiagcEveHndlg_NvRam_App3
#define ASW_NvRam_App4_MP Rte_swc_DiagcEveHndlg_NvRam_App4
#define ASW_NvRam_App5_MP Rte_swc_DiagcEveHndlg_NvRam_App5
extern VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App1;
extern VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App2;
extern VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App3;
extern VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App4;
extern VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App5;

extern boolean NVM_XCU_EEWriteFlgBlock54;
extern boolean NVM_XCU_EEWriteFinish;

extern void NVM_XCU_EEWriteImm(void);
extern uint8 NVM_XCU_EEWrite(uint8* OpStatus);
extern void NVM_XCU_EERead(void);
extern void NVM_XCU_EEDataPack(void);
extern void NVM_XCU_EEDataUnPack(void);
extern uint8 NVMBlock119Array[256];
extern uint8 NVMBlock128Array[256];
extern uint8 NVMBlock129Array[256];
extern uint8 NVMBlock130Array[256];
extern uint8 NVMBlock131Array[256];
extern boolean NVM_XCU_EEWriteFlgBlock119;
extern boolean NVM_XCU_EEWriteFlgBlock128;
extern boolean NVM_XCU_EEWriteFlgBlock129;
extern boolean NVM_XCU_EEWriteFlgBlock130;
extern boolean NVM_XCU_EEWriteFlgBlock131;
extern uint8 Nvm_WriteBlock119Sts;
extern uint8 Nvm_WriteBlock128Sts;
extern uint8 Nvm_WriteBlock129Sts;
extern uint8 Nvm_WriteBlock130Sts;
extern uint8 Nvm_WriteBlock131Sts;

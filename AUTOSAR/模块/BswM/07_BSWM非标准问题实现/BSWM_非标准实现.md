---
tags: [AUTOSAR, BswM, 非标准实现, 供应商扩展]
---
# BSWM 非标准问题实现（vendor / 项目扩展清单）

> [!info] 导航
> 上级：[[BswM]]

> 适用实现：NeuSAR BswM 3.14.0 / AUTOSAR 4.2.2，单分区
> 代码：`AUTOSAR/AUTOSAT使用NEUSAR生成的代码/002_BSW/Bsw_Src/Autosar_Src/src_BswM/Source/`
> 最后更新：2026-10-22

> 本页只记录**与 AUTOSAR SWS 不一致、或 SWS 没有的 vendor/项目实现**，用于评审、移植和排查。
> 历史问题见 `BswM_问题排查记录.md`；时间类问题见 `06_问题排查/BSWM_时间类问题排查.md`。

## 1. 判定口径

| 类型 | 含义 | 本页处理 |
|---|---|---|
| SWS 标准行为 | 标准有明确章节/需求号 | 不收录 |
| Vendor 扩展 | SWS 无此机制，供应商用宏/函数扩展 | 收录（NS-001 起） |
| 项目 Hook | 项目代码插入到标准流程 | 收录 |
| 实现差异 | 标准允许，但实现方式与文档不同 | 收录为“差异”类 |
| 配置裁剪 | 特性宏关闭导致代码不生效 | 收录为“配置快照”提醒 |

## 2. 非标准实现总表

| 编号 | 名称 | 入口/开关 | 代码位置 | 影响级别 | 标准对应 |
|---|---|---|---|---|---|
| NS-001 | 项目 Callout 动作（复位/上下电/CAN 驱动/Dem） | `BswM_Callout_Stubs.c` | L81~149 | 高（上下电/复位） | SWS 无具体 Hook |
| NS-002 | 直接写 `BswM_GenericState[4]` | `BswUserCallout_SWC_Delay_PowerOffPort` | L137~141 | 中（绕过端口 API） | SWS 无直接写数组 |
| NS-003 | `BswM_ImmediateModeRequest` 内部 API + 同步队列处理 | `BswM_ImmediateModeRequest` | L644~709 | 高（响应时序） | SWS 公开 API 是 `BswM_RequestMode` |
| NS-004 | 规则/动作列表为生成函数，不是通用解释器 | `BswM_Rules[]` / `BswM_ActionLists[]` | `BswM_Lcfg.c` | 中（移植/扩展） | SWS 允许实现方式，但与文档描述不同 |
| NS-005 | `BswM_ConfigType` 空/ConfigPtr 未用 | `BswM_Init` | L1051、结尾 dummy | 中（多配置/移植） | SWS 允许 link-time，但参数未用 |
| NS-006 | 主函数每周期执行 IPDU 组控制 | `BSWM_IPDU_GROUP_CONTROL` | `BswM_Lcfg.c` L838、`BswM.c` L3425 | 中（通信时序） | SWS 的 IPDU 组动作语义 |
| NS-007 | `BSWM_MAINFUNCTIONPERIOD=5U` 生成宏未引用 | `BswM_Cfg.h` L50 | — | 中（时间单位） | SWS 参数单位是秒 |
| NS-008 | 项目动作列表/规则命名与顺序 | `AL_CANSM_*`、`AL_COMM_*`、`AL_VOL_COM_*` | `BswM_Cfg.h` L99~130 | 中（上下电/通信） | 项目配置，不是 SWS 行为 |
| NS-009 | SWC 模式更新/Mode 通知 Hook | `BSWM_SWCMODEREQUESTUPDATE_FUNC`、`BSWM_MODENOTIFICATION_FUNC` | `BswM.c` L3417/L3421 | 中（模式通知） | SWS 无此函数名 |
| NS-010 | 多分区代码存在但关闭 | `BSWM_MULTIPARTITION=STD_OFF` | `BswM_ProcessingState` L480 | 低（排查误导） | SWS 多分区 |
| NS-011 | 供应商内存工具函数 | `BswM_MemCmp/MemCpy/MemSet` | `BswM.c` L965/1001/1026 | 低（工具） | SWS 无此 API |
| NS-012 | 队列/信号量实现（SWS 未规定细节） | `BswM_QueueSemaphore/QueueWritten` | `BswM.c` L474/476、L555 | 中（重入/时序） | SWS 只规定语义 |

## 3. 逐项说明

### NS-001 项目 Callout 动作（`BswM_Callout_Stubs.c`）

**代码行为**：该文件把 BswM 动作列表中的“项目动作”转发到外部函数：

```c
FUNC(void, BSWM_CODE) BswM_InitToRun_Action(void)      { InitToRun_Action(); }
FUNC(void, BSWM_CODE) BswM_RunToPostRun_Action(void)   { RunToPostRun_Action(); }
FUNC(void, BSWM_CODE) BswM_PostRunToRun_Action(void)   { PostRunToRun_Action(); }
FUNC(void, BSWM_CODE) BswM_PostRunToShutdown_Action(void){ PostRunToShutdown_Action(); }
FUNC(void, BSWM_CODE) BswM_BootReset_Action(void)      { BootReset_Action(); }
FUNC(void, BSWM_CODE) BswM_HardReset_Action(void)      { HardReset_Action(); }
FUNC(void, BSWM_CODE) BswM_SoftReset_Action(void)      { SoftReset_Action(); }
FUNC(void, BSWM_CODE) BswM_CANDriver_ON(void)          { BswM_TPT1145_NORMAL(); BswM_CanIf_NORMAL(); }
FUNC(void, BSWM_CODE) BswM_CANDriver_OFF(void)         { BswM_CanIf_SLEEP(); BswM_TPT1145_SLEEP(); }
FUNC(void, BSWM_CODE) BswM_Dem_Shutdown(void)          { Dem_Shutdown(); }
```

**与标准差异**：SWS 只定义动作类型/参数（如 ComM、Com、EcuM、RTE 动作），不定义这些项目函数名和外部 Hook。

**风险**：

- 上下电/复位是否成功取决于这些外部函数（`InitToRun_Action`、`RunToPostRun_Action`、`Dem_Shutdown`、`BswM_CanIf_*`、`BswM_TPT1145_*`）；
- Hook 内部阻塞会占住 BswM 队列信号量，导致后续模式请求“无响应”；
- 顺序错误（先关 CAN 再发通知）可能导致报文丢失。

**测试**：冷启动、正常关机、复位（Boot/Hard/Soft）、CAN 驱动 ON/OFF 各走一遍，确认动作顺序与下游状态。

### NS-002 直接写 `BswM_GenericState[4]`

**代码行为**：

```c
FUNC(void, BSWM_CODE) BswUserCallout_SWC_Delay_PowerOffPort(void)
{
    extern uint8 PwrOffDlyFlg_Mp;
    BswM_GenericState[4] = PwrOffDlyFlg_Mp;   /* 绕过 BswM_RequestMode/端口 API */
}
```

**与标准差异**：SWS 的模式请求应通过端口/`BswM_RequestMode` 进入；这里直接写通用端口数组，且硬编码索引 4。

**风险**：索引 4 依赖 `BSWM_SIZE_GENERIC=5` 的配置；若规模/顺序变化会越界或写错端口；规则可能在未触发队列处理时看到新值，造成“值变了但没动作”。

**建议**：确认该 Hook 的调用时机；规模变化时同步修改索引或改为 `BswM_RequestMode`。

### NS-003 `BswM_ImmediateModeRequest` + 同步队列处理

**代码行为**：`BswM_RequestMode` 更新 `BswM_GenericState[userHandle]` 后调用 `BswM_ImmediateModeRequest`；`ImmediateModeRequest` 若发现信号量 UNLOCKED，会**同步**调用 `BswM_ProcessQueuedRequests` 并执行规则/动作。

**与标准差异**：SWS 公开 API 只有 `BswM_RequestMode`；`BswM_ImmediateModeRequest` 是生成代码内部接口，且“请求即执行”的同步行为依赖本实现。

**风险**：

- 请求可能在调用者上下文执行动作（含长 Hook），导致调用者阻塞；
- 若信号量已锁，请求排队，响应延迟到一个主函数周期或当前动作结束；
- 排查“请求慢”时不能只看主函数周期，还要看信号量/当前动作。

### NS-004 规则/动作列表是生成函数

**代码行为**：`BswM_Rules[i].FctPtrOfRules()`、`BswM_ActionLists[i].FctPtrOfActionLists()` 在 `BswM_Lcfg.c` 中生成具体函数；主函数没有遍历条件/表达式的通用解释器。

**与标准差异**：SWS 描述的是条件/表达式/规则的配置语义；本实现将规则/动作编译成函数指针，行为等价但不可在运行期修改。

**风险**：改规则/动作必须改配置并重新生成；排查时不能期望在 BswM.c 里看到“条件表达式”代码，应进对应生成函数。

### NS-005 `BswM_ConfigType` 为空 / ConfigPtr 未用

**代码行为**：`BswM_ConfigType` 是空结构（`BswM_PCConfigType`，`BswM_Cfg.h` L287）；`BswM_Init` 使用 `BSWM_DUMMY_STATEMENT(ConfigPtr)`，配置直接引用 `BswM_Lcfg.c` 常量。

**与标准差异**：SWS 允许 link-time 配置，但接口保留 ConfigPtr；本实现实际不使用，也不支持 post-build 切换。

**风险**：多配置集/移植项目会误以为可切换；`BswM_Init` 传入的指针无效。

### NS-006 主函数每周期执行 IPDU 组控制

**代码行为**：`BSWM_IPDU_GROUP_CONTROL=STD_ON` 时，`BswM_MainFunction` 末尾调用 `BswM_ExecuteIpduGroupControl()`（`BswM_Lcfg.c` L838），把配置的 IPDU 组状态落到 Com/PduR。

**与标准差异**：SWS 的 IPDU 组控制是动作/规则结果；本实现额外提供每周期执行的集中控制。

**风险**：每周期调用可能覆盖其他模块的 IPDU 组设置；排查通信异常时要确认该函数的组配置与 Com/PduR 一致。

### NS-007 `BSWM_MAINFUNCTIONPERIOD=5U`

**代码行为**：`BswM_Cfg.h` 定义 `BSWM_MAINFUNCTIONPERIOD=5U`，但 BswM.c/Lcfg 中未直接引用；`BswM_DecreaseTimer` 每主函数调用减 1。

**与标准差异**：SWS 的 `BswMMainFunctionPeriod` 单位是秒；生成宏是工具换算后的参数，代码里不再按秒计算。

**风险**：把 `5U` 当 ms 或秒都会算错；实际时间 = 定时器值 × 实际任务周期（需在 SchM/OS 配置确认）。

### NS-008 项目动作列表/规则命名与顺序

**代码行为**：`BswM_Cfg.h` 的动作列表 ID 包含 `AL_InitToRun`、`AL_RunToPostRun`、`AL_CANSM_IpduStart_*`、`AL_COMM_NM_FullCOMM/NoCOMM`、`AL_VOL_COM_ON/OFF` 等项目命名。

**与标准差异**：这些是项目配置选择，不是 SWS 强制命名；顺序/优先级由配置决定。

**风险**：上下电/通信动作顺序错会表现为“模式切换了但通信没起来/没关掉”；排查时先看动作列表顺序，不要只看规则。

### NS-009 SWC 模式更新 / Mode 通知 Hook

**代码行为**：`BSWM_SWCMODEREQUESTUPDATE_FUNC`（OFF）与 `BSWM_MODENOTIFICATION_FUNC`（OFF）在主函数中条件调用；本项不编译。

**与标准差异**：SWS 无这两个函数名，属于供应商/项目 Hook。

**风险**：若项目打开，需确认函数实现与调用时序；本项关闭，排查时不要按这两个函数找问题。

### NS-010 多分区代码存在但关闭

**代码行为**：`BswM_ProcessingState` 仅在 `BSWM_MULTIPARTITION=STD_ON` 时编译；本项 OFF，`BswM_ProcessingState` 不存在。

**风险**：按多分区文档找 `ProcessingState` 会找不到；所有索引固定 0。

### NS-011 供应商内存工具函数

`BswM_MemCmp/MemCpy/MemSet`（L965/1001/1026）是供应商提供的工具函数，SWS 没有这些 API；排查时应看调用处而不是标准文档。

### NS-012 队列/信号量实现

`BswM_QueueSemaphore`/`BswM_QueueWritten` 与 `BswM_ProcessQueuedRequests` 构成“请求队列 + 重入保护”，SWS 只规定请求/仲裁/动作的语义，不规定该实现。风险是长动作占用信号量导致后续请求延迟。

## 4. 风险与回归建议

| 编号 | 影响面 | 必测场景 |
|---|---|---|
| NS-001 | 上下电/复位/CAN | 冷启动、正常关机、三种复位、CAN ON/OFF |
| NS-002 | 通用端口/电源标志 | 电源延时标志变化、尺寸变化 |
| NS-003 | 请求响应时序/重入 | 单请求、并发请求、动作执行中再请求 |
| NS-004 | 规则/动作修改 | 重新生成后规则/动作一致性 |
| NS-005 | 配置选择/移植 | 单配置、多配置（如使用） |
| NS-006 | 通信组控制 | 上下电、模式切换时 IPDU 组状态 |
| NS-007 | 定时器/时间 | 定时器到期、模式切换时间 |
| NS-008 | 上下电/通信顺序 | InitToRun、RunToPostRun、PostRunToShutdown |
| NS-009 | 模式通知 | 宏打开/关闭对比 |
| NS-010 | 多分区排查 | 单分区配置确认 |
| NS-011 | 工具函数 | 内存比较/拷贝调用点 |
| NS-012 | 并发/时序 | 多请求、长动作、信号量锁 |

## 5. 使用建议

1. **评审时**：把本页作为“标准之外”的检查单，确认每个 Hook 是否必要；
2. **移植时**：先确认 `BswM_Callout_Stubs.c` 的外部函数（`InitToRun_Action`、`RunToPostRun_Action`、`BswM_CanIf_*`、`BswM_TPT1145_*`、`Dem_Shutdown` 等）是否存在；
3. **排查时**：遇到“请求没反应/动作不执行”，先查 NS-003（同步执行/锁）、NS-012（队列），再查 NS-001（Hook 阻塞）；
4. **测试时**：按第 4 节补齐项目动作与队列场景，不要只按 SWS 用例。

> 通用排查见 `06_问题排查/BSWM_快速问题定位.md`；时间类见 `06_问题排查/BSWM_时间类问题排查.md`；历史问题见 `BswM_问题排查记录.md`。

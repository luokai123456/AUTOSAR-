---
tags: [AUTOSAR, BswM, 学习总结]
---

# BswM 在 DaVinci Configurator 中的配置项详解

> [!info] 导航
> 上级：[[BswM]] ｜ 依赖：[[BswM_配置参数表_R21-11]]、[[BswM_D4_动作列表与动作执行调用逻辑]] ｜ 依据：[[BswM_AUTOSAR标准需求表_R21-11]]

> 适用版本：AUTOSAR CP R21-11　依据：AUTOSAR_SWS_BSWModeManager 第 10 章（ECUC 配置规范）
> 工具：Vector DaVinci Configurator Classic（不同版本界面措辞略有差异，但列出的容器/参数名与 AUTOSAR 配置规范一致）
> 最后更新：2026-10-17

## 0. 先明确三件事

1. **BswM 是"配置即代码"的模块**：DaVinci 里配的每个容器，最终生成 `BswM_Cfg.h` / `BswM_Lcfg.c` / `BswM_PBcfg.c`（视配置变体）以及 `BswM` 服务组件的 SWC 描述、`SchM_BswM.h` 调度接口。配置错 → 运行行为错，代码里看不出来。
2. **配置变体**：BswM 支持 `VARIANT-PRE-COMPILE / LINK-TIME / POST-BUILD`，DaVinci 工程里选哪种决定了参数是否能在后装阶段改（`BswM_Init` 带 `BswM_ConfigType*`）。
3. **一个 partition 一份 `BswMConfig`**：多核/多分区工程中，每个分区都有自己的 BswM 实例和配置树（SWS 7.4）。

## 1. 配置树总览（DaVinci 中的节点结构）

```text
BswM
├─ BswMGeneral                        （全局参数，1 个）
└─ BswMConfig                        （每个分区 1 个）
   ├─ BswMPartitionRef                （可选，绑定到 EcucPartition）
   ├─ BswMArbitration                （仲裁：1 个）
   │  ├─ BswMModeRequestPort          0..*
   │  │  ├─ BswMRequestProcessing      IMMEDIATE / DEFERRED
   │  │  ├─ BswMModeInitValue          0..1（初始模式值）
   │  │  └─ BswMModeRequestSource      1（choice：来源模块）
   │  ├─ BswMEventRequestPort         0..*
   │  │  ├─ BswMEventRequestProcessing
   │  │  └─ BswMEventRequestSource     1（choice：事件来源）
   │  ├─ BswMModeCondition            0..*（条件：端口 + 比较值）
   │  │  └─ BswMConditionValue         0..1
   │  ├─ BswMLogicalExpression        0..*（AND/OR/XOR/NOT/NAND）
   │  └─ BswMRule                     0..*（规则）
   │     ├─ BswMNestedExecutionOnly
   │     ├─ BswMRuleInitState
   │     ├─ BswMRuleExpressionRef      → 逻辑表达式
   │     ├─ BswMRuleTrueActionList     → 动作列表
   │     └─ BswMRuleFalseActionList    → 动作列表
   ├─ BswMDataTypeMappingSets         0..1（模式值映射）
   └─ BswMModeControl                 （控制：1 个）
      ├─ BswMActionList               1..*
      │  ├─ BswMActionListExecution    TRIGGER / CONDITION
      │  ├─ BswMActionListPriority     0..255
      │  └─ BswMActionListItem        1..*
      │     ├─ BswMActionListItemIndex
      │     ├─ BswMActionListItemRef   → 动作 / 子列表 / 规则
      │     ├─ BswMAbortOnFail
      │     └─ BswMReportFailRuntimeErrorId
      ├─ BswMAction                   0..*（每个动作实例）
      │  └─ BswMAvailableActions      （choice：动作类型）
      ├─ BswMSwitchPort               0..*（RTE 模式切换 P-Port）
      └─ BswMRteModeRequestPort       0..*（向 SWC 发模式请求）
```

## 2. BswMGeneral（全局参数，最常改的地方）

| 参数 | 类型/取值 | 作用 | 工程建议 |
|---|---|---|---|
| `BswMMainFunctionPeriod` | float，秒，>0 | `BswM_MainFunction` 周期 | **必须等于实际任务周期**（如 0.01 = 10ms）；定时器精度与延迟仲裁都依赖它 |
| `BswMCanSMEnabled` | bool | 使能 CanSM 相关 API/头文件 | 用 CanSM 就 TRUE，否则 `BswM_CanSM.h` 不生成 |
| `BswMComMEnabled` | bool | 使能 ComM 相关 API | 用 ComM 模式/PNC 就 TRUE |
| `BswMDcmEnabled` | bool | 使能 Dcm 相关 API | 有诊断就 TRUE |
| `BswMEcuMEnabled` | bool | 使能 EcuM 相关 API | 用 EcuM 状态/唤醒/下电就 TRUE |
| `BswMEthIfEnabled` | bool | 使能 EthIf 相关 API | 以太网交换机端口组才需要 |
| `BswMEthSMEnabled` | bool | 使能 EthSM 相关 API | 以太网 |
| `BswMFrSMEnabled` | bool | 使能 FrSM 相关 API | FlexRay |
| `BswMGenericRequestEnabled` | bool | 使能 `BswM_RequestMode` 通用请求 | 有 SWC/BSW 用通用请求时 TRUE |
| `BswMJ1939DcmEnabled` | bool | 使能 J1939Dcm | J1939 项目 |
| `BswMJ1939NmEnabled` | bool | 使能 J1939Nm | J1939 项目 |
| `BswMLinSMEnabled` | bool | 使能 LinSM | LIN |
| `BswMLinTPEnabled` | bool | 使能 LinTp | LIN 传输层模式请求 |
| `BswMNmEnabled` | bool | 使能 Nm | 用网络管理 |
| `BswMNvMEnabled` | bool | 使能 NvM | 需要 NvM 状态/读写动作 |
| `BswMSchMEnabled` | bool | 使能 SchM | 需要 `SchM_Switch` |
| `BswMSdEnabled` | bool | 使能 Sd | 服务发现 |
| `BswMWdgMEnabled` | bool（**obsolete**） | 使能 WdgM 相关 API | R21-11 已废弃，不建议使用 |
| `BswMDevErrorDetect` | bool | 开发错误检测（DET） | 开发阶段 TRUE，量产 FALSE |
| `BswMVersionInfoApi` | bool | 使能 `BswM_GetVersionInfo` | 需要版本读取时 TRUE |
| `BswMUserIncludeFiles/BswMUserIncludeFile` | 字符串列表 | 强制包含的头文件 | 自定义 callout 时加 |

> ⚠️ 所有 `BswM<X>Enabled` 默认是 **false**。只配了动作却没把对应开关打开，是"生成代码缺头文件 / 链接报错"的经典原因（SWS_BswM_00279）。

## 3. 仲裁侧配置（BswMArbitration）

### 3.1 BswMModeRequestPort —— 一切输入的入口

每个端口代表"某一个来源的某一种模式"。必配两项：

- `BswMRequestProcessing`：`BSWM_IMMEDIATE`（收到请求当场求值）或 `BSWM_DEFERRED`（等 MainFunction）。
- `BswMModeRequestSource`（choice）：选择来源类型，见下表。
- 可选 `BswMModeInitValue`：给端口一个初始模式值（`BswMBswModeInitValue` 或 `BswMCompuScaleModeValue`）。**不配就是"未定义"，相关规则会被跳过**。

| BswMModeRequestSource 选择 | 来源模块 | 典型用途 | 对应 C-API / 端口 |
|---|---|---|---|
| `BswMCanSMIndication` | CanSM | CAN 通道通信状态 | `BswM_CanSM_CurrentState` |
| `BswMComMIndication` | ComM | 通道通信模式 | `BswM_ComM_CurrentMode` |
| `BswMComMPncRequest` | ComM | 部分网络 PNC 请求 | `BswM_ComM_CurrentPNCMode` |
| `BswMDcmComModeRequest` | Dcm | 诊断要求禁用/恢复通信 | `BswM_Dcm_CommunicationMode_CurrentState` |
| `BswMEcuMIndication` | EcuM | ECU 状态（RUN/POST_RUN…） | `BswM_EcuM_CurrentState` |
| `BswMEcuMRUNRequestIndication` | EcuM | RUN 请求协议状态 | `BswM_EcuM_RequestedState` |
| `BswMEcuMWakeupSource` | EcuM | 唤醒源状态 | `BswM_EcuM_CurrentWakeup` |
| `BswMEthIfPortGroupLinkStateChg` | EthIf | 交换机端口组链路状态 | `BswM_EthIf_PortGroupLinkStateChg` |
| `BswMEthSMIndication` | EthSM | 以太网通信状态 | `BswM_EthSM_CurrentState` |
| `BswMFrSMIndication` | FrSM | FlexRay 状态 | `BswM_FrSM_CurrentState` |
| `BswMGenericRequest` | 任意 | 通用模式请求（`BswM_RequestMode`） | `BswM_RequestMode` + `BswMModeRequesterId` |
| `BswMJ1939DcmBroadcastStatus` | J1939Dcm | 广播状态 | `BswM_J1939DcmBroadcastStatus` |
| `BswMJ1939NmIndication` | J1939Nm | J1939 网络管理状态 | `BswM_J1939Nm_StateChangeNotification` |
| `BswMLinSMIndication` | LinSM | LIN 状态 | `BswM_LinSM_CurrentState` |
| `BswMLinScheduleIndication` | LinSM | 当前 LIN 调度表 | `BswM_LinSM_CurrentSchedule` |
| `BswMLinTpModeRequest` | LinIf | LinTp 模式请求 | `BswM_LinTp_RequestMode` |
| `BswMNmStateChangeNotification` | Nm | NM 状态变化 | `BswM_Nm_StateChangeNotification` |
| `BswMNvMJobModeIndication` | NvM | 多块作业状态（ReadAll/WriteAll…） | `BswM_NvM_CurrentJobMode` |
| `BswMNvMRequest` | NvM | 单块状态 | `BswM_NvM_CurrentBlockMode` |
| `BswMSd*CurrentState` | Sd | 服务发现各类状态 | `BswM_Sd_*` |
| `BswMSoAdSoConModeChg` | SoAd | Socket 连接状态 | `BswM_SoAd_SoConModeChg` |
| `BswMSwcModeRequest` | SWC（RTE） | SWC 的模式请求 R-Port | RTE SenderReceiver |
| `BswMSwcModeNotification` | SWC（RTE） | SWC 的模式切换通知 R-Port | RTE ModeSwitch |
| `BswMBswModeNotification` | BSW（SchM） | 其他 BSW 经 SchM 的模式通知 | `SchM_Mode_*` |
| `BswMTimer` | 内部 | 定时器状态（STOPPED/STARTED/EXPIRED） | 无外部接口，只能被动作控制 |

> 注意：SWC 相关的三种来源（`BswMSwcModeRequest`、`BswMSwcModeNotification`、`BswMBswModeNotification`）要求**先有 RTE/SWC 配置**（接口、端口、ModeDeclarationGroup），否则 DaVinci 里引用选不出来。

### 3.2 BswMEventRequestPort —— 只关心"事件发生"

与模式端口不同，事件端口没有值，只有 SET/CLEAR：

- `BswMEventRequestProcessing`：IMMEDIATE / DEFERRED。
- `BswMEventRequestSource`：`BswMComMInitiateReset`（ComM 请求 ECU 复位）、`BswMDcmApplicationUpdatedIndication`（诊断刷写后应用更新）、`BswMModeSwitchErrorEvent`、`BswMNmCarWakeUpIndication`、`BswMPartitionRestarted`、`BswMSwitchAckNotification`、`BswMWdgMRequestPartitionReset`（obsolete）。
- 事件被置位后，要用动作 `BswMClearEventRequest` 清掉，否则一直保持 SET。

### 3.3 BswMModeCondition —— 条件的写法

| 参数 | 说明 |
|---|---|
| `BswMConditionMode` | 引用一个 `BswMModeRequestPort` 或 `BswMEventRequestPort` |
| `BswMConditionValue` | 比较的目标值（`BswMBswMode` 引用 `BswMModeDeclaration` 里的模式值，或 `BswMCompuScaleModeValue` 文本值） |
| `BswMConditionType` | `BSWM_EQUALS` / `BSWM_EQUALS_NOT`（对模式端口）；`BSWM_EVENT_IS_SET` / `BSWM_EVENT_IS_CLEARED`（对事件端口） |

> 标准明确禁止"模式端口配 EVENT_IS_*、事件端口配 EQUALS"（SWS_BswM_00256），DaVinci 校验会报错。

### 3.4 BswMLogicalExpression —— 条件的布尔组合

- `BswMLogicalOperator`：`BSWM_AND`、`BSWM_OR`、`BSWM_XOR`、`BSWM_NOT`、`BSWM_NAND`。
- `BswMArgumentRef`：1..*，引用条件或子表达式（可嵌套）。
- 约束：`NOT` 只能 1 个参数；`NAND` 只能 2 个参数；`XOR` 为"奇数个 TRUE 即 TRUE"；求值顺序不定义（不要依赖短路顺序写有副作用的逻辑）。

### 3.5 BswMRule —— 规则

| 参数 | 说明 |
|---|---|
| `BswMRuleExpressionRef` | 引用逻辑表达式（也可直接引用单个条件） |
| `BswMRuleTrueActionList` | 结果为 True 时执行的动作列表（可空） |
| `BswMRuleFalseActionList` | 结果为 False 时执行的动作列表（可空） |
| `BswMRuleInitState` | 初始化后首次求值时"上次结果"的假设：`BSWM_UNDEFINED`（视为变化，True/False 列表都按结果执行）/ `BSWM_TRUE` / `BSWM_FALSE`（见 SWS 表 7.1） |
| `BswMNestedExecutionOnly` | TRUE = 只在被动作列表引用时求值（子规则），FALSE = 顶层规则，参与每次仲裁 |

## 4. 控制侧配置（BswMModeControl）

### 4.1 BswMActionList / BswMActionListItem

| 参数 | 说明 |
|---|---|
| `BswMActionListExecution` | `BSWM_TRIGGER`：规则结果**变化**时执行；`BSWM_CONDITION`：每次求值满足条件都执行。被嵌套引用时此参数无效 |
| `BswMActionListPriority` | 0~255，多个顶层列表同时执行时**大者先执行**，默认 0 |
| `BswMActionListItemIndex` | 0~255，同一列表内唯一，按升序执行 |
| `BswMActionListItemRef` | 引用 `BswMAction`（原子动作）/ `BswMActionList`（子列表）/ `BswMRule`（嵌套规则） |
| `BswMAbortOnFail` | 动作返回 E_NOT_OK 时是否中止本列表 |
| `BswMReportFailRuntimeErrorId` | 128~255，失败时上报 DET 的运行时错误号 |

> 级联最多 7 层（SWS_BswM_00037）；DaVinci 校验会检查深度、序号唯一性、引用完整性。

### 4.2 BswMAction → BswMAvailableActions（动作清单）

每个动作在 DaVinci 里是 `BswMAction` 容器下选一种 `BswMAvailableActions`。常用动作与真实 API：

| 动作（容器） | 调用的 API | 典型用途 | 关键参数 |
|---|---|---|---|
| `BswMPduGroupSwitch` | `Com_IpduGroupStart` / `Com_IpduGroupStop` | 开/关通信的 PDU 组 | `BswMEnabledPduGroupRef`、`BswMDisabledPduGroupRef`、`BswMPduGroupSwitchReinit` |
| `BswMDeadlineMonitoringControl` | `Com_EnableReceptionDM` / `Com_DisableReceptionDM` | 开/关接收超时监控 | `BswMEnabledDMPduGroupRef` 等 |
| `BswMTriggerIPduSend` | `Com_TriggerIPDUSend` | 立即触发一帧发送 | I-PDU 引用 |
| `BswMSwitchIPduMode` | `Com_SwitchIpduTxMode` | 切换发送模式 | I-PDU + 模式值 |
| `BswMComMAllowCom` | `ComM_CommunicationAllowed` | 允许/禁止某通道通信 | `BswMComAllowed`、`BswMComMAllowChannelRef` |
| `BswMComMModeSwitch` | `ComM_RequestComMode` | 请求 FULL/NO COMMUNICATION | `BswMComMRequestedMode`、`BswMComMUserRef` |
| `BswMComMModeLimitation` | `ComM_LimitChannelToNoComMode` | 限制通道到 NO_COM | `BswMComMLimitMode` |
| `BswMNMControl` | `Nm_EnableCommunication` / `Nm_DisableCommunication` | 开关 NM 通信 | `BswMNMAction`、网络句柄 |
| `BswMPduRouterControl` | `PduR_EnableRouting` / `PduR_DisableRouting` | 开关路由路径组（网关） | `BswMPduRouterAction`、路由路径组引用 |
| `BswMEcuMStateSwitch` | `EcuM_StateSwitch` | 请求 EcuM 切换状态 | `BswMEcuMState` |
| `BswMEcuMGoDownHaltPoll` | `EcuM_GoDownHaltPoll` | 请求下电并轮询 HALT | `BswMEcuMUserIdRef` |
| `BswMEcuMSelectShutdownTarget` | `EcuM_SelectShutdownTarget` | 选择复位/休眠目标 | `BswMEcuMResetModeRef` / `BswMEcuMSleepModeRef` |
| `BswMEcuMDriverInitListBswM` | 触发 EcuM 驱动初始化列表 | 启动阶段初始化驱动 | 列表引用 |
| `BswMRteStart` / `BswMRteStop` | `Rte_Start` / `Rte_Stop` | 启动/停止 RTE | 无 |
| `BswMRteSwitch` | `Rte_Switch_*` | 通知 SWC 模式切换 | `BswMRteSwitchPortRef`、`BswMSwitchedMode` |
| `BswMSchMSwitch` | `SchM_Switch_*` | 通知 BSW 模式切换 | `BswMSchMSwitchPortRef`、`BswMSchMSwitchedMode` |
| `BswMRteModeRequest` | `Rte_Write_*` | 向 SWC 模式管理器发模式请求 | `BswMRteModeRequestPortRef` |
| `BswMLinScheduleSwitch` | `LinSM_ScheduleRequest` | 切换 LIN 调度表 | `BswMLinScheduleRef` |
| `BswMEthIfStartAllPorts` | `EthIf_StartAllPorts` | 启动所有以太网端口 | 无 |
| `BswMEthIfSwitchPortGroupRequestMode` | `EthIf_SwitchPortGroupRequestMode` | 以太网交换机端口组切换 | `BswMEthIfSwitchPortGroupRef` |
| `BswMFrSMAllSlots` | `FrSM_AllSlots` | 退出 FlexRay KeySlotOnly 模式 | 网络句柄 |
| `BswMJ1939DcmStateSwitch` | `J1939Dcm_SetState` | J1939 诊断状态切换 | 通道/节点/状态 |
| `BswMJ1939RmStateSwitch` | `J1939Rm_SetState` | J1939 请求管理状态 | 通道/节点/状态 |
| `BswMSdClientServiceModeRequest` | `Sd_ClientServiceSetState` | 服务发现客户端服务 | 方法/状态 |
| `BswMSdConsumedEventGroupModeRequest` | `Sd_ConsumedEventGroupSetState` | 消费事件组 | 事件组/状态 |
| `BswMSdServerServiceModeRequest` | `Sd_ServerServiceSetState` | 服务端服务 | 方法/状态 |
| `BswMSdServiceGroupSwitch` | `Sd_ServiceGroupStart` / `Sd_ServiceGroupStop` | 服务组开关 | 引用 |
| `BswMTimerControl` | 内部定时器 | `BSWM_TIMER_START/STOP` 定时/延时 | `BswMTimerRef`、`BswMTimerValue`、`BswMTimerAction` |
| `BswMClearEventRequest` | 内部事件清除 | 清事件端口 | 事件端口引用 |
| `BswMCoreHaltMode` | OS Core Halt | 多核 HALT | 核心引用、HALT 模式名 |
| `BswMUserCallout` | 任意用户函数（含参数） | `NvM_ReadAll/WriteAll`、自定义初始化 | `BswMUserCalloutFunction` 字符串 |
| `BswMIdsMBlockStateChangeRequest` | IdsM 块状态（draft） | 入侵检测 | — |

> **NvM 读写没有独立动作容器**：R21-11 里通常用 `BswMUserCallout` 配 `NvM_ReadAll()` / `NvM_WriteAll()`（SWS 10.2.85 明确给出这个用法示例）。

### 4.3 输出端口类配置

| 容器 | 作用 | 生成物 |
|---|---|---|
| `BswMSwitchPort` | BswM 作为模式管理器对外提供模式 | `BswMModeSwitchInterfaceRef` → SWC P-Port；`BswMSchMModeDeclarationGroupRef` → BSWMD 模式组原型 |
| `BswMRteModeRequestPort` | BswM 向"SWC 模式管理器"发模式请求 | SWC 的 R-Port / 变量数据原型 |
| `BswMDataTypeMappingSets` | 模式值与数据类型的映射集 | 供 RTE 生成映射 |

## 5. DaVinci 中的配置流程（建议顺序）

1. **前置**：EcuM、ComM、Com、PduR、Dcm、NvM、CanSM/LinSM 等模块的配置先完成（BswM 大量引用它们）。
2. 在 BSW Modules 视图添加 **BswM**，选择配置变体（VARIANT）。
3. 配 `BswMGeneral`：周期、各 `*Enabled` 开关、DET。
4. 配 **ModeRequestPort**：按"谁会给 BswM 什么信息"逐个添加，选 `BswMModeRequestSource`，确定 IMMEDIATE/DEFERRED，必要时设初值。
5. 配 **ModeCondition / LogicalExpression**：先建条件，再建表达式（嵌套引用）。
6. 配 **Rule**：引用表达式，挂 True/False 动作列表（先占位后续再补）。
7. 配 **ActionList**：按业务顺序建列表，编号留间隔（10/20/30…）方便插入；再配 **BswMAction** 并引用 BSW 参数（PDU 组、ComM User、NvM block 等）。
8. 配 **SwitchPort / RteModeRequestPort**（需要通知 SWC 模式时）。
9. **校验**（Validate/Consistency Check）：重点看引用是否为空、序号重复、级联超 7 层、条件类型与端口类型不匹配。
10. **生成代码**并检查：
    - `BswM_Cfg.h`：`BSWM_*` 宏、端口数量；
    - `BswM_PBcfg.c` / `BswM_Lcfg.c`：规则表、动作表；
    - `SchM_BswM.h`：`BswM_MainFunction` 调度声明；
    - 生成的服务组件描述里 ModeRequestPort/ModeSwitchPort 是否正确。
11. **集成任务**：把 `BswM_MainFunction` 映射到 OS Task 或 SchM 周期调度，周期与 `BswMMainFunctionPeriod` 一致；`BswM_Init` 由 EcuM 在 `StartPostOS` 阶段调用（SWS_EcuM_04014）。

## 6. 常见配置坑（项目里最容易踩的 10 个）

1. **`BswMMainFunctionPeriod` 和任务周期不一致** → BswMTimer 到期时间整体偏移，延时逻辑失准。
2. **`BswM<X>Enabled` 没开** → 生成代码缺少 `BswM_Xxx.h`，链接报 `BswM_ComM_CurrentMode` 未定义。
3. **ModeRequestPort 没配 `BswMModeInitValue`** → 上电初期该条件"未定义"，相关规则被跳过（通信不开、诊断不响应）。
4. **动作列表用 CONDITION 却期望只执行一次** → 每个周期重复执行（如重复 `ComM_RequestComMode`）。
5. **TRIGGER 列表首次不执行** → 检查 `BswMRuleInitState`（UNDEFINED 才会在首次按结果执行）。
6. **PDU 组开关顺序反了** → 先 `Com_IpduGroupStop` 再停 NM，或先关 ComM 再关 PDU 组，导致总线异常帧/唤醒。
7. **忘记 `BswMClearEventRequest`** → 事件端口一直 SET，规则常真。
8. **IMMEDIATE 端口里挂重动作** → 在中断/高优先级上下文执行，影响实时性。
9. **引用别的模块参数（PDU 组、ComM User、NvM Block）没先配** → DaVinci 引用为空，生成失败。
10. **多分区只配了一个 BswMConfig** → 另一个分区没有 BswM 实例，`BswM_Init` 调用空指针/编译缺失。

## 7. 最常改的 10 个参数速查

| 场景 | 参数 | 位置 |
|---|---|---|
| 调主函数周期 | `BswMMainFunctionPeriod` | BswMGeneral |
| 打开某模块交互 | `BswMComMEnabled` 等 | BswMGeneral |
| 请求处理时机 | `BswMRequestProcessing` | BswMModeRequestPort |
| 端口初值 | `BswMBswModeInitValue` | BswMModeInitValue |
| 条件比较 | `BswMConditionType` + `BswMConditionValue` | BswMModeCondition |
| 逻辑关系 | `BswMLogicalOperator` | BswMLogicalExpression |
| 首次是否执行 | `BswMRuleInitState` | BswMRule |
| 仅变化时执行 | `BswMActionListExecution` | BswMActionList |
| 多列表执行顺序 | `BswMActionListPriority` | BswMActionList |
| 动作失败行为 | `BswMAbortOnFail` / `BswMReportFailRuntimeErrorId` | BswMActionListItem |

## 8. 依据章节

- 配置结构：SWS 第 10.2 章（各容器小节号见第 1 节树状图）
- 配置变体与参数属性：SWS 10.1 及 SWS_BSWGeneral 10.1
- 配置流程/语义：EXP_ModeManagementGuide 3.1、3.2
- 启动/关机配置示例：EXP_ModeManagementGuide 4.1

---
tags: [AUTOSAR, CanNm, 问题排查, 时间分析]
---
# CanNm 时间类问题排查（上下电 / 状态转换 / 首帧报文）

> [!info] 导航
> 上级：[[CanNm]]

> 适用实现：NeuSAR CanNm 3.14.0 / AUTOSAR 4.2.2，2 通道（ch0 ChannelId 6 / NodeId 39，ch1 ChannelId 2 / NodeId 35）
> 代码：`AUTOSAR/AUTOSAT使用NEUSAR生成的代码/002_BSW/Bsw_Src/Autosar_Src/src_CanNm/Source/`
> 最后更新：2026-10-22

> **先统一时间基准**：本工程 `CanNm_ChannelConfig[]` 里的时间参数是 **tick（主函数周期数）**，不是 ms。
> 实际时间 = tick × `CanNmMainFunctionPeriod`（记为 `T`）。`T` 不在生成代码里，由 SchM/OS 任务周期决定；排查前必须先实测或确认 `T`，否则所有“快/慢”判断都无效。

## 1. 时间基准与理论窗口

### 1.1 换算公式

```text
实际时间 = tick 数 × T
T = CanNmMainFunctionPeriod（SchM/OS 任务周期）
```

两个容易算错的点：

1. 代码重装定时器常写 `X + CANNM_ONE`：设置后要等下一次主函数才第一次递减，实际约 `(X+1)` 个周期；
2. 本工程 `CanNm_Cfg.h` 注释里的 `[ms]` 是原 ECUC 参数说明，运行期按 tick 递减，**以 tick 为准**。

### 1.2 本项目时间参数（tick）

| 参数                         | tick | 理论时长     | 用途                    |
| -------------------------- | ---- | -------- | --------------------- |
| `MsgCycleTime`             | 100  | 100T     | Normal/Repeat 周期发送    |
| `ImmediateNmCycleTime`     | 4    | 4T       | 主动唤醒快发间隔              |
| `ImmediateNmTransmissions` | 10 帧 | 约 4T×10  | 主动唤醒快发帧数              |
| `RepeatMessageTime`        | 320  | 321T（+1） | Repeat Message 停留     |
| `TimeoutTime`              | 380  | 381T（+1） | Ready Sleep → Prepare |
| `WaitBusSleepTime`         | 401  | 401T     | Prepare → Bus-Sleep   |
| `MsgTimeoutTime`           | 16   | 17T（+1）  | 发送确认超时                |
| `MsgCycleOffset`           | 0    | 1T（+1）   | 首次发送偏移                |

### 1.3 理论时间窗口（用来判断“是否超时”）

| 指标                    | 从哪到哪                               | 理论窗口                                   | 超出后先怀疑                         |
| --------------------- | ---------------------------------- | -------------------------------------- | ------------------------------ |
| 主动唤醒首帧                | `CanNm_NetworkRequest` 生效 → 总线上第一帧 | ≤ 1T + CanIf/总线延迟（同周期可发）               | 请求未到 CanNm / restart 未置 / 发送链路 |
| 被动唤醒首帧                | 总线上收到第一帧 → 本 ECU 第一帧               | 1~2T + Nm/ComM 往返（取决于 ComM 同步性）        | Rx 映射/唤醒源/Nm/ComM              |
| 上电首帧                  | 电源有效/唤醒事件 → 本 ECU 第一帧              | EcuM 初始化 + CanIf 初始化 + CanNm_Init 后 1T | 初始化顺序、BswM/EcuM、任务调度           |
| Repeat → Normal/Ready | 进入 Repeat Message → 离开             | 约 321T                                 | RepeatMsgTimer/CommState       |
| Ready → Prepare       | 最后一次 TimeoutTimer 重置 → 离开 Ready    | ≤ 381T（有剩余值时更短）                        | 持续收帧、TimeoutTimer 被重置          |
| Prepare → Bus-Sleep   | 进入 Prepare → 进入 Bus-Sleep          | 401T                                   | WaitBusSleepTimer/主函数          |
| Ready/Normal 发送周期     | 上一帧 → 下一帧                          | 100T（快发 4T）                            | MsgTimer/CanIf/总线负载            |

> 以上是**代码理论值**；项目设计预算另算（含 EcuM 启动、CanIf 队列、总线仲裁、其他节点）。

## 2. 先确定“测的是哪一段”

| 场景 | 起点 | 终点 | 关键信号 |
|---|---|---|---|
| 冷启动/上电 | VBAT 有效或唤醒事件 | 本 ECU 第一帧 NM | EcuM 启动、`CanNm_Init`、`CanIf_Transmit` |
| 主动唤醒 | 唤醒源/ComM 请求 | 本 ECU 第一帧 NM | `CanNm_NetworkRequest`、`CanIf_Transmit` |
| 被动唤醒 | 总线上第一帧 NM | 本 ECU 第一帧 NM | `CanNm_RxIndication`、`CanIf_Transmit` |
| 下电/睡眠 | 最后一次 `CanNm_NetworkRelease` | Bus-Sleep（或最后 NM 帧） | `CanNm_NetworkRelease`、`Nm_BusSleepMode` |
| 状态转换 | 触发事件（请求/释放/收到帧/超时） | 目标状态生效 | `CanNm_NmState` 变化 |

> 注意：下电时间通常测“最后 NM 帧 → Bus-Sleep 请求”，ECU 真正断电还包含 EcuM/BswM/电源管理时间，不要混在一起算。

## 3. 场景一：上电/主动唤醒后首帧超时

### 3.1 排查顺序

1. **初始化**：`CanNm_ModuleInitState == CANNM_INIT`；`CanNm_Init` 是否在 CanIf 之后执行（EcuM 初始化序列）；
2. **调度**：`CanNm_MainFunction` 是否按 `T` 执行；任务是否被更高优先级任务长期占用；
3. **请求**：`CanNm_CommState == COMM_NORMAL_OPERATION`；`CanNm_NetworkRestartFlag` 是否置为 `CANNM_ACTIVE_RESTART`；
4. **迁移**：`CanNm_NmState` 是否从 Bus-Sleep 进入 Repeat Message；
5. **发送**：`CanNm_MsgTimer` 是否被置 1、`ImmediateNmMsgCount` 是否 = 9；
6. **出口**：`CanNm_TriggerTransmission` → `CanIf_Transmit` 返回值；CanIf Tx PDU/控制器是否就绪。

### 3.2 首帧超时看哪些变量

| 变量 | 期望 | 异常含义 |
|---|---|---|
| `CanNm_ModuleInitState` | `CANNM_INIT` | 未初始化 → 不会发帧 |
| `CanNm_CommState[ch]` | `COMM_NORMAL_OPERATION` | 仍 `COMM_READY_SLEEP` → 请求没到 CanNm |
| `CanNm_NetworkRestartFlag[ch]` | `CANNM_ACTIVE_RESTART` → 迁移后清 `NO_RESTART` | 一直 `NO_RESTART` → NetworkRequest 条件不满足/未调用 |
| `CanNm_NmState[ch]` | 迁移到 `NM_STATE_REPEAT_MESSAGE` | 仍在 Bus-Sleep → 主函数迁移分支没走到 |
| `CanNm_MsgTimer[ch]` | 1（首帧）→ 4（快发） | 一直 0 或不变 → 发送调度没执行 |
| `CanNm_ImmediateNmMsgCount[ch]` | 初始 9，递减到 0 | 一直 10 → 快发未开始；卡住 → 发送失败 |
| `CanNm_TxControlState[ch]` | `MSG_TX_ENABLED` | DISABLED → 0x28/初始化异常 |
| `CanNm_TxMessageData[ch][8]` | SNI/CBV/用户数据已填 | 内容空/错 → PDU 布局或组包问题 |

### 3.3 常见原因

- `CanNm_Init` 在 CanIf 之前/未调用 → `CANNM_E_NO_INIT`；
- `CanNmMainFunctionPeriod` 与任务周期不一致 → 首帧“看起来慢”；
- ComM 请求没有走到 `CanNm_NetworkRequest`（Nm 通道映射/ComM 用户配置）；
- `TxPduRef` 配置错，`CanIf_Transmit` 仍可能返回 E_OK 但总线上没有帧；
- CanIf 控制器未启动/发送队列满/总线 Bus-Off；
- `VCU_Test_Code_YXP` 测试钩子占用主函数时间；
- 调试断点暂停 CPU 导致时间拉长（先排除人为因素）。

## 4. 场景二：被动唤醒/收帧后不动作

### 4.1 排查顺序

1. **收到没有**：`CanNm_MsgIndicationFlag[ch]` 是否置 1；`CanNm_RxMessageData[ch][0..7]` 是否更新；`CanNM_Message_Receive` 是否变 TRUE；
2. **状态分支**：`CanNm_NmState` 是否 Bus-Sleep/Prepare；Bus-Sleep 分支应调用 `Nm_NetworkStartIndication`；
3. **唤醒请求**：Nm/ComM 是否向 CanNm 发 `CanNm_NetworkRequest`（看 `CanNm_CommState` 是否变 Normal）；
4. **迁移/发送**：后续同第 3 节。

### 4.2 关键判定

| 现象 | 含义 | 范围 |
|---|---|---|
| 总线有帧，`MsgIndicationFlag=0` | CanIf 没回调/ Rx PDU 映射错 | CanIf 配置、`CanNm_ChToRxPduId`、通道号 |
| Flag=1，但下一周期仍为 1 | 主函数没跑 | 调度/初始化 |
| 状态仍是 Bus-Sleep，且 `CommState=READY_SLEEP` | Nm/ComM 没有请求 | Nm 配置、ComM 用户、唤醒源 |
| `CommState=NORMAL`，但 `NetworkRestartFlag=NO_RESTART` | 在 Ready Sleep 下请求（不置 restart，走 Normal 迁移） | 正常路径，查 `BusCommunicationHandling`/首帧 |
| 进入 Repeat 但不发帧 | 发送链路 | 同第 3 节发送部分 |

## 5. 场景三：状态转换时间超时

### 5.1 各转换的“负责人”

| 转换                  | 触发条件                                        | 代码位置                              | 理论时长           |
| ------------------- | ------------------------------------------- | --------------------------------- | -------------- |
| Bus-Sleep → Repeat  | `NetworkRequest`/`PassiveStartUp` 置 restart | 主函数重启分支 `StateTransition(REPEAT)` | 1 个主函数周期内      |
| Prepare → Repeat    | 收到 NM 帧                                     | `MainRxTxConfHandling` Prepare 分支 | 下一主函数周期        |
| Repeat → Normal     | `CommState=NORMAL` 且 RepeatMsgTimer 到期      | `RepeatMessageTimerHandling`      | 约 321T         |
| Repeat → Ready      | `CommState=READY_SLEEP` 且到期                 | 同上                                | 约 321T         |
| Normal → Ready      | `NetworkRelease` 后 `CommState=READY_SLEEP`  | `BusCommunicationHandling`        | 下一主函数周期        |
| Ready → Prepare     | `TimeoutTimer` 到期                           | `TimeoutTimerHandling`            | ≤381T（从最后一次重置） |
| Prepare → Bus-Sleep | `WaitBusSleepTimer` 到期                      | `WaitBusSleepTimerHandling`       | 401T           |

### 5.2 卡住时看什么

1. **状态变量**：`CanNm_NmState` 是否真的没变，还是变了又被切回；
2. **对应定时器**：Repeat 看 `RepeatMsgTimer`；Ready 看 `TimeoutTimer`；Prepare 看 `WaitBusSleepTimer`；
3. **定时器是否被重置**：Ready 状态下每收到一帧都会重置 `TimeoutTimer`（即使网络已释放）——总线上有其他节点持续发帧时，**本 ECU 不会睡**，这是正常行为；
4. **触发条件**：`CommState`、`NetworkRestartFlag`、`TxControlState`、`RepeatMsgTimer` 到 0 时 `CommState` 是否真的是 Normal；
5. **主函数周期**：`T` 变大 → 所有转换时间等比变长；
6. **编译宏**：`CANNM_PASSIVE_MODE_ENABLED`、`CANNM_COM_CONTROL_ENABLED`、`CANNM_REMOTE_SLEEP_IND_ENABLED` 等裁剪了对应逻辑。

## 6. 场景四：下电/睡眠超时

### 6.1 睡眠链路（本项目）

```text
NetworkRelease
  → CommState = COMM_READY_SLEEP
  → BusCommunicationHandling：Normal → Ready Sleep
  → TimeoutTimer 递减（380+1 tick，期间收到 NM 帧会重置）
  → 到期：Ready Sleep → Prepare Bus-Sleep
  → WaitBusSleepTimer 递减（401 tick）
  → 到期：Prepare → Bus-Sleep
  → Nm_BusSleepMode(ChannelId) → ComM
  → EcuM/BswM 继续执行下电流程
```

### 6.2 首先判断“卡在哪一段”

| 观察 | 结论 | 下一步 |
|---|---|---|
| `CommState` 仍 NORMAL | 还有通信请求未释放 | 查 ComM 用户/诊断/应用是否仍请求 |
| `NmState` 仍 Normal | 还没进入 Ready | 查 `NetworkRelease` 是否调用/`BusCommunicationHandling` |
| `NmState` Ready，`TimeoutTimer` 一直很大/被重置 | 仍在收 NM 帧 | 看总线是否有其他节点持续发帧（正常会延迟睡眠） |
| `TimeoutTimer=0` 但不进 Prepare | 主函数未跑/分支未进 | 查主函数、状态、DET |
| 进入 Prepare，`WaitBusSleepTimer` 不减 | 主函数/定时器 | 查 `WaitBusSleepTimerHandling` |
| 已 Bus-Sleep，ECU 不断电 | 不是 CanNm 睡眠问题 | 查 EcuM/BswM/电源管理/BswM 动作 |

### 6.3 重点变量

`CanNm_CommState`、`CanNm_NmState`、`CanNm_TimeoutTimer`、`CanNm_WaitBusSleepTimer`、`CanNm_MsgIndicationFlag`、`CanNm_TxControlState`；同时看 Nm 的 `Nm_BusSleepMode` 是否被调用、ComM 是否收到 Bus-Sleep 通知。

### 6.4 常见原因

- 应用/诊断仍持有网络请求（ComM 未释放）；
- 其他 ECU 持续发 NM 帧，`CanNm_RxIndication` 不断重置 `TimeoutTimer`；
- 0x28 只停发送，不等于释放网络/进入睡眠；
- `TimeoutTime`/`WaitBusSleepTime` 看成了 ms，实际是 tick，换算后与预期不符；
- `T` 被改大（任务周期变更）但配置未同步换算；
- BswM/EcuM 的关机动作链卡住（CanNm 已经 Bus-Sleep，但 ECU 未断电）。

## 7. 时间问题通用观测表

| 变量 | 作用 | 与时间的关系 |
|---|---|---|
| `CanNm_NmState[2]` | 当前状态 | 判断某段转换是否发生 |
| `CanNm_CommState[2]` | 请求状态 | 决定是否应该发帧/睡眠 |
| `CanNm_TimeoutTimer[2]` | Ready → Prepare 计时 | 每次收帧会被重置 |
| `CanNm_RepeatMsgTimer[2]` | Repeat 停留计时 | 320+1 tick |
| `CanNm_WaitBusSleepTimer[2]` | Prepare 停留计时 | 401 tick |
| `CanNm_MsgTimer[2]` | 发送周期/首帧/快发计时 | 决定帧间隔与首帧时机 |
| `CanNm_ImmediateNmMsgCount[2]` | 快发剩余帧数 | 主动唤醒 10 帧 |
| `CanNm_MsgTimeoutTimer[2]` | 发送确认超时 | 16+1 tick，到 0 报发送异常 |
| `CanNm_NetworkRestartFlag[2]` | 主动/被动重启请求 | 决定是否进入 Repeat |
| `CanNm_MsgConfirmationFlag[2]` | 发送确认交接 | 一直 1 → 主函数未消费，时间统计失真 |
| `CanNm_MsgIndicationFlag[2]` | 接收事件交接 | 一直 1 → 主函数未消费，收帧时间失真 |

## 8. 测量手段

1. **CANoe/CANalyzer**：记录第一帧/最后一帧时间戳、周期间隔、方向、CBV/SNI；同时抓其他节点，确认是否被“拖住”；
2. **GPIO 打点**：在 `CanNm_NetworkRequest`、`StateTransition`、`TriggerTransmission`、`CanIf_Transmit`、`Nm_BusSleepMode` 入口翻转 IO，用示波器/逻辑分析仪测真实链路；
3. **OS Trace**：确认 `CanNm_MainFunction` 的任务周期和抖动；`T` 的实际值必须从这里来；
4. **Watchpoint**：`CanNm_TimeoutTimer`、`CanNm_WaitBusSleepTimer`、`CanNm_MsgTimer` 写入点；`CanNm_NmState` 变化点；
5. **DET**：`CANNM_E_NO_INIT`、`CANNM_E_NETWORK_TIMEOUT`、`CANNM_E_PDUR_TRIGGERTX_ERROR` 等；
6. **排除调试干扰**：断点/printf 会显著拉长时间，先确认不是测量手段造成的“超时”。

## 9. 排查流程（30 分钟）

1. 明确测的是哪一段（上电/主动/被动/下电/状态转换）与起止点；
2. 确认 `T` 与 tick 值，算出理论窗口；
3. 抓“起点信号、终点信号、中间变量快照”；
4. 若首帧慢：按第 3/4 节从 Init→请求→迁移→发送逐段排除；
5. 若状态转换慢：对第 5.1 节找负责的 handler，看定时器是否递减/被重置；
6. 若睡眠慢：按第 6.2 节判断卡在 Ready/Prepare/Bus-Sleep/EcuM 哪一段；
7. 用 GPIO/OS Trace 复核，排除断点、任务周期、其他节点影响；
8. 记录 Q-xxx（现象、T、tick、trace、变量值、根因）。

## 10. 提交证据清单

- 现象与场景（上电/主动唤醒/被动唤醒/下电/某次状态转换）；
- `T` 实测值、tick 配置值、换算后的理论窗口；
- trace：起点、终点、帧 ID、周期、方向、其他节点是否在发；
- 变量快照：`NmState`、`CommState`、5 个 timer、`MsgTimer`、`ImmediateNmMsgCount`、两个事件标志；
- DET 记录、CanIf 返回、控制器状态；
- 是否开启 `VCU_Test_Code_YXP`、是否有调试断点。

> 通用快速定位方法见 `06_问题排查/CanNm_快速问题定位.md`；本页专门处理“时间超时”类问题。

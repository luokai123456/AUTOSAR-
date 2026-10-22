---
tags: [AUTOSAR, BswM, 问题排查, 时间分析]
---
# BSWM 时间类问题排查（上下电 / 模式转换 / 定时器）

> [!info] 导航
> 上级：[[BswM]]

> 适用实现：NeuSAR BswM 3.14.0 / AUTOSAR 4.2.2，单分区
> 代码：`AUTOSAR/AUTOSAT使用NEUSAR生成的代码/002_BSW/Bsw_Src/Autosar_Src/src_BswM/Source/`
> 最后更新：2026-10-22

> **时间基准**：`BSWM_MAINFUNCTIONPERIOD=5U` 是生成配置的周期参数；`BswM_TimerState[].Timevalue` 的值由动作写入，`BswM_DecreaseTimer` 每调用一次主函数减 1，因此定时器值按**主函数周期数**理解。实际时长 = 周期数 × 实际任务周期（需在 SchM/OS 集成配置确认，不要直接当 ms）。

## 1. 理论时间窗口

| 指标 | 从哪到哪 | 理论窗口 | 超出先怀疑 |
|---|---|---|---|
| 模式请求响应 | 调用 `BswM_RequestMode`/回调 → 动作执行 | 通常**同步**完成（同一调用栈）；锁/队列忙时 ≤1 个主函数周期 | 信号量锁、动作阻塞、主函数未跑 |
| 延迟规则响应 | 条件成立 → 延迟规则动作 | ≤1 个主函数周期（`ExecuteDeferredRules` 每周期执行） | 延迟规则表/规则返回值/队列 |
| BswM 定时器 | 动作 `BswM_UpdateTimer` 启动 → EXPIRED | `value` 个主函数周期 | 定时器值单位、`DecreaseTimer`、主函数周期 |
| 定时器触发动作 | EXPIRED → 动作 | 没有一个“自动触发”；必须由规则求值消费 | 是否在延迟规则/请求路径里 |
| 启动动作 | `BswM_Init` → `AL_InitToRun` | 初始化内同步执行（可能含外部 Hook） | Init 顺序、动作 Hook 阻塞 |
| 下电动作 | 模式请求 → `AL_RunToPostRun`/`AL_PostRunToShutdown` | 通常同步；外部复位/Dem/CAN 驱动可能阻塞 | 项目 Hook、EcuM 关机链 |
| IPDU 组控制 | 每主函数周期 | 1 个主函数周期 | `BSWM_IPDU_GROUP_CONTROL`、Com/PduR |

> 关键差异：CanNm 的定时器到期会**直接触发状态迁移**；BswM 的定时器到期只是把 `Timestate` 置为 `EXPIRED`，**真正动作要等规则求值**（延迟规则或新的模式请求）。因此“定时器超时但没动作”首先要查规则路径，而不是定时器本身。

## 2. 先确定“测的是哪一段”

| 场景 | 起点 | 终点 | 关键观察 |
|---|---|---|---|
| 冷启动/上电 | EcuM 调用 `BswM_Init` | `AL_InitToRun` 动作完成 | `BswM_Initialized`、动作 Hook |
| 模式切换 | 调用 `BswM_RequestMode` 或端口回调 | 动作列表执行 | 队列状态、信号量、动作函数 |
| 下电 | 关机模式请求 | `AL_RunToPostRun`/`AL_PostRunToShutdown` 完成 | 模式请求、动作 Hook、EcuM |
| 定时器 | `BswM_UpdateTimer` | 动作响应 | TimerState、规则求值路径 |
| 延迟规则 | 条件端口变化 | 动作执行 | DeferredRules、ActionListQueue |

> 下电时间通常测“模式请求 → BswM 动作完成”，ECU 真正断电还包含 EcuM/BswM 后续/电源管理时间，需分开算。

## 3. 场景一：上电/启动动作超时

### 3.1 排查顺序

1. `BswM_Initialized[0].Initialized` 是否 TRUE；
2. `BswM_Init` 是否在 SchM/OS 初始化之后被调用；
3. 初始化期间 `BswM_QueueSemaphore[0]` 是否被锁住（Init 会先锁，最后解锁）；
4. `AL_InitToRun` 是否在 `BswM_ProcessQueuedRequests` 中被执行；
5. 动作函数内部的 Callout Hook（`InitToRun_Action` 等）是否阻塞/依赖未初始化模块；
6. 主函数是否在 Init 后正常调度。

### 3.2 关键变量

| 变量 | 期望 | 异常含义 |
|---|---|---|
| `BswM_Initialized[0].Initialized` | TRUE | FALSE → Init 未完成/未调用 |
| `BswM_QueueSemaphore[0]` | Init 完成后 UNLOCKED | 一直 LOCKED → Init/动作未退出 |
| `BswM_ModeRequestQueue[].RequestMode` | Init 后 IDLE | 一直 QUEUED → 初始化动作未处理 |
| `BswM_ActionListQueue[].ActionListState` | IDLE | PENDING/BLOCKED → 动作阻塞 |
| `BswM_GenericState[0..4]` | 端口初值 | 初值不对 → 配置/映射 |

### 3.3 常见原因

- `BswM_Init` 在 EcuM 启动序列中位置不对/未调用；
- `AL_InitToRun` 的外部 Hook（项目初始化、驱动初始化）耗时或阻塞；
- 初始化期间有请求进来，队列锁未释放导致后续不处理；
- 主函数周期过大，初始化后的规则/动作延迟；
- 多分区配置误判（本项单分区，`BswM_ProcessingState` 不编译）。

## 4. 场景二：模式请求 → 动作响应超时

### 4.1 排查顺序

1. 请求是否到达：`BswM_GenericState[userHandle]` 是否更新；
2. 是否进入队列：`BswM_ModeRequestQueue[].RequestMode` 是否 QUEUED/PENDING；
3. 信号量是否被锁：`BswM_QueueSemaphore[0]`；
4. 规则是否返回动作：`BswM_Rules[i].FctPtrOfRules()` 返回值是否 `<27`；
5. 动作列表是否执行：`BswM_ActionListQueue[].ActionListState`；
6. 动作函数是否阻塞/返回失败（Callout Hook、下游 API）；
7. 主函数是否在跑（锁未释放时只能等主函数收尾）。

### 4.2 关键理解

- `BswM_RequestMode` 内部会调用 `BswM_ImmediateModeRequest`；如果信号量是 UNLOCKED，会**同步**调用 `BswM_ProcessQueuedRequests` 并在同一调用栈执行规则/动作；
- 如果信号量已 LOCKED（另一个请求/动作正在执行），本次请求只排队，等当前执行结束/主函数收尾；
- 因此“请求后过很久才动作”通常不是规则慢，而是队列被长动作/长 Hook 占用。

### 4.3 常见原因

- 动作内部调用 `Dem_Shutdown`、复位、CAN 驱动切换等耗时 Hook，导致信号量长时间不释放；
- 动作函数返回失败，列表进入异常状态；
- 规则函数返回 `>=27`（无动作），看起来像“没响应”；
- 端口值未更新（回调未写/映射错），规则本来就不命中；
- 主函数未运行，锁无法在退出前释放。

## 5. 场景三：BswM 定时器超时

### 5.1 定时器链路

```text
动作 BswM_UpdateTimer(timerId, value)
  → BswM_TimerState[timerId].Timevalue = value
  → Timestate = STARTED（value=0 则 STOPPED）
  → 每个主函数周期 BswM_DecreaseTimer：Timevalue--
  → 到 0：Timestate = EXPIRED
  → 规则函数读取 EXPIRED（延迟规则或新请求触发）
  → 动作执行
```

### 5.2 重点

1. `BswM_UpdateTimer` 是否真的被动作调用（timerId 是否正确、value 是否非 0）；
2. `BswM_DecreaseTimer` 是否每周期执行（主函数是否在跑、`BSWM_SIZE_TIMER>0`）；
3. 值单位：`value` 是主函数周期数，不是 ms；
4. **EXPIRED 不会自动触发规则**：必须在 `BswM_DeferredRules` 或请求路径中求值；
5. 规则函数是否读取了正确的 timerId/状态。

### 5.3 常见原因

- 定时器动作未执行/被跳过（动作列表未命中）；
- `value` 配得过大/过小（单位误判）；
- 主函数停止/周期变长；
- 没有延迟规则消费 EXPIRED，导致“到期无动作”；
- 定时器 ID 越界（`timerId < BSWM_SIZE_TIMER` 不满足）。

## 6. 场景四：下电/关机动作超时

### 6.1 链路

```text
关机模式请求
  → BswM_RequestMode/端口回调
  → ImmediateModeRequest → ProcessQueuedRequests
  → 规则命中 AL_RunToPostRun / AL_PostRunToShutdown
  → ExecuteActionLists → 动作函数
  → 项目 Hook：Dem_Shutdown / CAN 驱动 SLEEP / 复位 / EcuM 关电
```

### 6.2 先判断卡在哪

| 观察 | 结论 | 下一步 |
|---|---|---|
| 请求没进队列 | 调用方/端口映射 | 查 EcuM/ComM/Dcm 的调用 |
| 队列 QUEUED 不执行 | 信号量/主函数 | 先修队列 |
| 动作执行但外部没反应 | 项目 Hook/下游 | 断点 `BswM_Callout_Stubs.c`、Dem/CAN/EcuM |
| BswM 已完成、ECU 不断电 | 不是 BswM | EcuM/BswM 后续/电源管理 |
| 动作顺序不对 | 动作列表配置 | 检查 `AL_*` 顺序/规则结果 |

### 6.3 常见原因

- 关机请求未到 BswM（ComM/EcuM 未发）；
- 动作列表/规则不命中（端口值/规则条件）；
- `Dem_Shutdown`/CAN 驱动/复位 Hook 阻塞；
- 动作顺序导致依赖模块提前关闭；
- 主函数停止，队列收尾未完成。

## 7. 观测变量

| 变量 | 作用 | 与时间的关系 |
|---|---|---|
| `BswM_Initialized[0]` | 初始化 | 未初始化时所有动作不执行 |
| `BswM_QueueSemaphore[0]` | 队列锁 | 锁住时请求等待，响应变慢 |
| `BswM_QueueWritten[0]` | 新请求标志 | 循环处理，影响队列退出时间 |
| `BswM_ModeRequestQueue[].RequestMode` | 请求状态 | 判断请求在排队还是已处理 |
| `BswM_ActionListQueue[].ActionListState` | 动作状态 | 判断动作是否执行/阻塞 |
| `BswM_TimerState[].Timestate/Timevalue` | 定时器 | 判断定时器是否递减/到期 |
| `BswM_GenericState[]` 等端口值 | 规则输入 | 输入更新时机决定规则命中时间 |

## 8. 测量手段

1. **GPIO 打点**：`BswM_RequestMode`、`BswM_ImmediateModeRequest`、`BswM_ProcessQueuedRequests`、`BswM_ExecuteActionLists`、动作 Hook；
2. **OS Trace**：`BswM_MainFunction` 周期/抖动；长动作是否占满任务；
3. **Watchpoint**：`QueueSemaphore`、`ActionListQueue[].ActionListState`、`TimerState[].Timevalue`；
4. **断点/返回值**：规则函数返回值、动作函数返回值；
5. **下游证据**：Com/ComM/EcuM/Dem 是否收到动作、是否阻塞。

## 9. 30 分钟流程

1. 明确测哪一段（启动/模式切换/定时器/下电）与起止点；
2. 确认主函数周期与 `BSWM_MAINFUNCTIONPERIOD` 对应关系；
3. 抓队列/信号量/动作列表/定时器快照；
4. 若模式响应慢：查信号量锁与长动作；
5. 若定时器到期无动作：查延迟规则是否消费 EXPIRED；
6. 若下电慢：查动作 Hook 与 EcuM 关电链；
7. GPIO/OS Trace 复核，排除调试断点；
8. 记录 Q-xxx。

## 10. 提交证据清单

- 场景与起止点、主函数周期；
- `QueueSemaphore`、`ModeRequestQueue`、`ActionListQueue`、`TimerState` 快照；
- 规则/动作返回值、DET；
- 项目 Hook（Dem/复位/CAN 驱动）执行时间；
- 下游模块状态与 EcuM 关机阶段。

> 通用排查见 `06_问题排查/BSWM_快速问题定位.md`；非标准实现见 `07_BSWM非标准问题实现/`。

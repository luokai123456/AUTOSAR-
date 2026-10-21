---
tags: [AUTOSAR, BswM, 调用逻辑, 代码实现]
---
# BswM 函数调用层级（基于本项目生成代码）

> [!info] 导航
> 上级：[[BswM_调用逻辑总览]]

> 适用文档：AUTOSAR CP R21-11　**实现基线**：AUTOSAR 4.2.2 / NeuSAR BswM 3.14.0
> 代码：`src_BswM/Source/BswM.c`（3434 行）、`BswM_Lcfg.c`（1684 行）、`BswM_Cfg.h`（625 行）
> 最后更新：2026-10-21

## 1. 顶层：公开 API 与回调（`BswM.c`）

| 函数 | 行号 | 上下文 | 说明 |
|---|---|---|---|
| `BswM_Init(const BswM_ConfigType*)` | 1051 | 初始化 | 初始化队列/端口值/定时器；`ConfigPtr` 实际未用（空结构） |
| `BswM_Deinit(void)` | 1478 | 关机 | 反初始化 |
| `BswM_RequestMode(BswM_UserType, BswM_ModeType)` | 1523 | 调用者 | 通用模式请求，进入立即请求队列 |
| `BswM_ImmediateModeRequest(start,end,partitionIdx,partitionId)` | 644 | 内部/调用者 | 立即请求入口（非 SWS API，生成代码内部使用） |
| `BswM_GetVersionInfo(versioninfo)` | 2436 | 调用者 | 版本 |
| `BswM_MainFunction(void)` | 3374 | SchM/OS 周期任务 | 队列、定时器、延迟规则、IPDU 组控制 |
| `BswM_ComM_CurrentMode` | 1708 | ComM 回调 | 通信模式 → 端口值 + 立即请求 |
| `BswM_EthSM_CurrentState` | 1790 | EthSM 回调 | 以太网状态（本项 size 0，不生成端口） |
| `BswM_Dcm_ApplicationUpdated` | 1961 | Dcm 回调 | 应用更新事件 |
| `BswM_CanSM_CurrentIcomConfiguration` | 2074 | CanSM 回调 | ICOM 配置（本项 size 0） |
| `BswM_Sd_ClientServiceCurrentState` | 2487 | Sd 回调 | 服务状态 |
| `BswM_Sd_ConsumedEventGroupCurrentState` | 2571 | Sd 回调 | 事件组状态 |
| `BswM_Sd_EventHandlerCurrentState` | 2657 | Sd 回调 | 事件处理状态 |
| `BswM_EcuM_CurrentState` | 2744 | EcuM 回调 | ECU 状态 |
| `BswM_FrSM_CurrentState` | 2906 | FrSM 回调 | FlexRay 状态 |
| `BswM_LinSM_CurrentSchedule` | 2986 | LinSM 回调 | 调度表切换 |
| `BswM_LinSM_CurrentState` | 3061 | LinSM 回调 | 通道状态 |
| `BswM_LinTp_RequestMode` | 3143 | LinTp 回调 | 请求模式 |
| `BswM_J1939DcmBroadcastStatus` | 3230 | J1939Dcm 回调 | 广播状态 |
| `BswM_J1939Nm_StateChangeNotification` | 3300 | J1939Nm 回调 | NM 状态变化 |
| `BswM_MemCmp / MemCpy / MemSet` | 965 / 1001 / 1026 | 工具 | 内存操作 |

> 其他模块回调（`BswM_ComM_CurrentPNCMode`、`BswM_CanSM_CurrentState`、`BswM_NvM_CurrentBlockMode`、`BswM_NvM_CurrentJobMode`、`BswM_J1939DcmBroadcastStatus` 等）声明在各 `BswM_<Module>.h` 中，多数是“写端口值 + `BswM_ImmediateModeRequest`”的薄封装。

## 2. 中层：队列/仲裁/执行（`BswM.c` + `BswM_Lcfg.c`）

| 函数 | 行号 | 职责 |
|---|---|---|
| `BswM_ProcessQueuedRequests(partitionIdx, partitionId)` | 555 | 处理 `BswM_ModeRequestQueue` 中 `BSWM_REQUEST_QUEUED` 的立即请求 → 调用规则函数 → 把返回的动作列表 ID 置 `BSWM_ACTIONLIST_PENDING` |
| `BswM_ReleaseQueue(partitionIdx, partitionId)` | 506 | 请求处理后释放队列（`PROCESSED→IDLE`、`PENDING→QUEUED`） |
| `BswM_ExecuteActionLists(executionLevel, partitionId)` | 762 | 遍历 `BswM_ActionListQueue`，执行匹配状态的动作列表函数 `BswM_ActionLists[i].FctPtrOfActionLists()` |
| `BswM_ExecuteDeferredRules(partitionId)` | 802 | 遍历 `BswM_DeferredRules[20]`，执行延迟规则并排队动作列表 |
| `BswM_DecreaseTimer(partitionId)` | 723 | 遍历 `BswM_TimerState[2]` 递减，到 0 置 `BSWM_TIMER_EXPIRED` |
| `BswM_GetPartitionIdByAppl` / `ByCoreId` | 850 / 912 | 多分区辅助（本项 OFF，不编译） |

**关键实现特征**：

- **规则不在 `BswM_MainFunction` 里遍历**；每条规则被编译成函数 `BswM_Rules[i].FctPtrOfRules()`，由立即请求/延迟规则路径调用；
- **动作也不是通用解释器**；每个动作列表被编译成 `BswM_ActionList_AL_*()` 函数，内部直接调用 ComM/Com/CanSM/EcuM 等 API（`BswM_Lcfg.c`）；
- 仲裁结果 = 规则函数返回的动作列表 ID（`uint8`，`< BSWM_SIZE_ACTIONLIST` 才有效）；
- 项目定制动作在 `BswM_Callout_Stubs.c`（如 `BswM_InitToRun_Action`、`BswM_RunToPostRun_Action`、`BswM_CANDriver_ON/OFF`、`BswUserCallout_SWC_Delay_PowerOffPort`）。

## 3. `BswM_MainFunction` 实际调用顺序（L3374~3429）

```text
BswM_MainFunction()
├─ [多分区 OFF] partitionIdx = partitionId = 0
├─ if (BswM_Initialized[0].Initialized == TRUE)
│   ├─ localSemaphore = BswM_QueueSemaphore[0]
│   ├─ if (UNLOCKED)
│   │   ├─ BswM_QueueSemaphore[0] = LOCKED
│   │   └─ BswM_ProcessQueuedRequests(0,0)        // 处理挂起立即请求
│   ├─ BswM_DecreaseTimer(0)                      // 2 个定时器递减/到期
│   ├─ BswM_ExecuteDeferredRules(0)               // 20 条延迟规则
│   ├─ if (UNLOCKED)
│   │   ├─ BswM_ProcessQueuedRequests(0,0)        // 处理本轮新产生的请求
│   │   └─ BswM_QueueSemaphore[0] = UNLOCKED
│   ├─ [SWCMODEREQUESTUPDATE_FUNC=OFF] 不编译
│   ├─ [MODENOTIFICATION_FUNC=OFF] 不编译
│   └─ BswM_ExecuteIpduGroupControl()             // IPDU_GROUP_CONTROL=ON
└─ 返回
```

**说明**：

- 本实现没有“遍历顶层规则 → 收集动作列表”的显式循环；规则求值在 `BswM_ProcessQueuedRequests`/`BswM_ExecuteDeferredRules` 内部通过函数指针完成；
- 信号量是**队列重入保护**：主函数执行期间到达的立即请求会被 `QUEUED/PENDING` 排队，退出前再处理一轮；
- 延迟规则与定时器到期都通过“规则函数返回动作列表 ID”进入同一执行队列。

## 4. 上下文与可重入

| 类别 | 上下文 | 可重入 |
|---|---|---|
| `BswM_MainFunction` | 任务 | 不可重入 |
| `BswM_Init` / `BswM_Deinit` | 初始化/关机 | 不可重入 |
| `BswM_RequestMode` / `BswM_ImmediateModeRequest` | 调用者任务/中断 | 不同端口可重入；共享队列由信号量保护 |
| 各模块回调 | 调用者上下文 | 同上 |
| 动作列表函数 | 主函数或立即请求上下文 | 由信号量/队列状态保护 |

## 5. 与旧文档（逻辑名）的差异

| 旧文档写法 | 代码实际 |
|---|---|
| `BswM_TimerHandling()` | `BswM_DecreaseTimer()`（L723） |
| 主函数内 `BswM_RuleEvaluation()` 遍历规则 | 无此函数；规则函数 `BswM_Rules[i].FctPtrOfRules()` 在队列/延迟路径调用 |
| `BswM_SelectActionLists()` | 无；规则函数直接返回动作列表 ID |
| `BswM_ExecuteActionList()` 逐项解释执行 | 每个动作列表是生成函数 `BswM_ActionList_AL_*()`，直接调用 BSW API |
| `BswM_ProcessImmediateRequest()` | `BswM_ImmediateModeRequest()`（L644）+ `BswM_ProcessQueuedRequests()`（L555） |
| `BswM_DrainPostponedRequests()` | 主函数退出前再次 `BswM_ProcessQueuedRequests()` |
| `BswM_ConfigPtr` / `BswM_PBcfg.c` | 不存在；`ConfigPtr` 未用，配置在 `BswM_Lcfg.c` |

## 6. 需求依据

SWS_BswM_00002、00003、00046~00058、00104、00119、00120、00131、00148、00152、00157、00158、00165、00193、00194、00204~00212、00217、00235、91001~91005。

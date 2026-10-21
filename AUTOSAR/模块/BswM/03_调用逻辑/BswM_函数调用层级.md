---
tags: [AUTOSAR, BswM, 调用逻辑]
---
# BswM 函数调用层级

> [!info] 导航
> 上级：[[BswM_调用逻辑总览]] ｜ 依赖：[[BswM_MainFunction调用逻辑]] ｜ 依据：[[BswM_AUTOSAR标准需求表_R21-11#SWS_BswM_002xx|需求表]]

> 适用版本：AUTOSAR CP R21-11　依据：SWS_BswM 第 8 章
> 最后更新：2026-10-21

> 说明：SWS 只规定对外 API/回调，内部静态函数名因实现而异；下表内部函数用"逻辑名"。

## 1. 顶层：调度入口、API、回调

| 函数 | 上下文 | 职责 | 依据 |
|---|---|---|---|
| `BswM_MainFunction()` | 周期任务（SchM） | 定时器、仲裁、动作执行（DEFERRED） | 00053、00075 |
| `BswM_Init()` | 初始化（OS/SchM 之后） | 初始化模块与端口/规则/定时器 | 00002、00043~00045 |
| `BswM_Deinit()` | 关机 | 停止模式处理 | 00119、00120 |
| `BswM_RequestMode()` | 调用者 | 通用模式请求 | 00046 |
| `BswM_GetVersionInfo()` | 调用者 | 版本 | 00003 |
| `BswM_EcuM_CurrentState` / `RequestedState` / `CurrentWakeup` | EcuM 调用 | ECU 状态/请求/唤醒源 | 91003、91004、00131 |
| `BswM_ComM_CurrentMode` / `CurrentPNCMode` / `InitiateReset` | ComM 调用 | 通信模式/PNC/复位事件 | 00047、00148、00217 |
| `BswM_Dcm_CommunicationMode_CurrentState` / `ApplicationUpdated` | Dcm 调用 | 诊断模式/应用更新事件 | 00048、00158 |
| `BswM_CanSM_CurrentState` 等总线状态 | 各 SM 调用 | 状态指示 | 00049~00052、00058 |
| `BswM_NvM_CurrentBlockMode` / `CurrentJobMode` | NvM 调用 | 块/作业状态 | 00104、00152 |
| `BswM_Nm_*` / `BswM_Sd_*` / `BswM_SoAd_SoConModeChg` / `BswM_J1939*` | 对应模块 | 状态/事件指示 | 00235、00204~00212、91005、00194 |
| `BswM_BswMPartitionRestarted` | 分区重启 | 分区重启事件 | 00193 |
| `BswM_EthIf_PortGroupLinkStateChg` | EthIf | 端口组链路状态 | 91001 |
| `BswM_WdgM_RequestPartitionReset` | WdgM | **obsolete** | 00157 |

## 2. 中层：内部处理（逻辑名，实现相关）

```text
BswM_MainFunction()
├─ BswM_TimerHandling()          定时器递减/到期收集（D6）
├─ BswM_RuleEvaluation()         遍历顶层规则求值（D3）
│   ├─ BswM_EvaluateCondition()  条件求值（模式端口/事件端口）
│   └─ BswM_EvaluateExpression() 逻辑表达式（AND/OR/XOR/NOT/NAND）
├─ BswM_SelectActionLists()      结果变化 → True/False 列表（D3）
├─ BswM_ExecuteActionLists()     去重/排序/逐列表执行（D4）
│   ├─ BswM_ExecuteActionList()
│   │   ├─ BswM_ExecuteAction()  原子动作 → BSW API（D7）
│   │   ├─ BswM_ExecuteItemRef() 子列表/嵌套规则
│   │   └─ BswM_HandleActionFail() AbortOnFail/Det
│   └─ BswM_DrainPostponedRequests() 处理挂起的 immediate 请求（D2）
└─ BswM_ProcessImmediateRequest()   IMMEDIATE 请求上下文内求值（D2）
```

## 3. 底层：对外接口（BswM 调用）

| 类别 | 接口 | 依据 |
|---|---|---|
| 通信 | Com、ComM、Nm、PduR 的 API（见 [[BswM_D7_输出动作与BSW交互]]） | 7.2.4 |
| 模式 | `Rte_Switch_*`、`SchM_Switch_*`、`Rte_Start/Stop` | 10.2.73~10.2.75 |
| 电源 | EcuM 的 StateSwitch/GoDownHaltPoll/SelectShutdownTarget/DriverInitList | 00269 |
| 总线 | LinSM、EthIf、FrSM、J1939、Sd | 10.2 |
| 错误 | `Det_ReportError` / `Det_ReportRuntimeError` | 00230、00239 |

## 4. 上下文与可重入

| 类别 | 上下文 | 可重入 |
|---|---|---|
| 主函数 | 任务 | 不可重入 |
| Init/Deinit | 初始化/关机 | 不可重入 |
| 大部分 indication API | 调用者任务/中断 | 可重入（不同通道/PDU） |
| 动作执行 | 主函数上下文，或 IMMEDIATE 调用者上下文 | 由实现保护（临界区） |

## 5. 需求依据

SWS_BswM_00002、00003、00046~00058、00104、00119、00120、00131、00148、00152、00157、00158、00165、00193、00194、00204~00212、00217、00235、91001~91005。

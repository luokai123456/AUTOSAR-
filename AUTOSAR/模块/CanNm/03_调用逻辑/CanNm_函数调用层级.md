---
tags: [AUTOSAR, CanNm, 调用逻辑, 代码实现]
---
# CanNm 函数调用层级（基于本项目生成代码）

> [!info] 导航
> 上级：[[CanNm_调用逻辑总览]] ｜ 依赖：[[CanNm_MainFunction调用逻辑]]、[[CanNm_全局变量说明]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11#SWS_CanNm_002xx|需求表]]

> 适用文档：AUTOSAR CP R21-11　**实现基线**：AUTOSAR 4.2.2 / NeuSAR CanNm 3.14.0
> 代码：`AUTOSAR/AUTOSAT使用NEUSAR生成的代码/002_BSW/Bsw_Src/Autosar_Src/src_CanNm/Source/CanNm.c`
> 最后更新：2026-10-21

> 行号以当前 `CanNm.c`（3720 行）为准；此前文档使用“逻辑名”，本页已替换为**实际函数名**。

## 1. 顶层：调度入口、公开 API、回调

| 函数（实际名）                                                                           | 行号   | 上下文             | 说明                                                                  |
| --------------------------------------------------------------------------------- | ---- | --------------- | ------------------------------------------------------------------- |
| `CanNm_MainFunction(void)`                                                        | 3618 | SchM/OS 周期任务    | 主状态机、定时器、收发处理（见 [[CanNm_MainFunction调用逻辑]]）                         |
| `CanNm_Init(const CanNm_ConfigType*)`                                             | 2025 | 初始化（CanIf 之后）   | 调 `CanNm_LocalInit(ch)` 初始化两通道，置 `CanNm_ModuleInitState=CANNM_INIT` |
| `CanNm_PassiveStartUp(nmChannelHandle)`                                           | 2078 | Nm              | 被动启动，置重启请求 → 主函数迁移                                                  |
| `CanNm_NetworkRequest(nmChannelHandle)`                                           | 2146 | Nm              | 通信请求，`CanNm_CommState=COMM_NORMAL_OPERATION`                        |
| `CanNm_NetworkRelease(nmChannelHandle)`                                           | 2218 | Nm              | 通信释放，`CanNm_CommState=COMM_READY_SLEEP`                             |
| `CanNm_DisableCommunication(nmChannelHandle)`                                     | 2280 | Nm/Dcm 链路       | 关闭发送（0x28），改 `TxControlStateRequest`                                |
| `CanNm_EnableCommunication(nmChannelHandle)`                                      | 2342 | Nm/Dcm 链路       | 恢复发送                                                                |
| `CanNm_SetUserData(nmChannelHandle, const uint8* nmUserDataPtr)`                  | 2467 | 应用/上层           | 设置用户数据（**本项 `CANNM_USER_DATA_ENABLED=OFF`，API 未导出**）                |
| `CanNm_GetUserData(nmChannelHandle, uint8* nmUserDataPtr)`                        | 2538 | 应用/上层           | 读取用户数据（**本项未启用**；Com 用户数据走 `PduR_CanNmTriggerTransmit`）             |
| `CanNm_Transmit(PduIdType CanNmTxPduId, const PduInfoType* PduInfoPtr)`           | 2607 | 上层/Com          | Com 用户数据触发发送（`CANNM_COM_USER_DATA_SUPPORT=ON`，可用）                   |
| `CanNm_GetNodeIdentifier(nmChannelHandle, uint8* nmNodeIdPtr)`                    | 2700 | 上层              | 读最近帧 SNI                                                            |
| `CanNm_GetLocalNodeIdentifier(nmChannelHandle, uint8* nmNodeIdPtr)`               | 2765 | 上层              | 返回配置的本地 NodeId                                                      |
| `CanNm_RepeatMessageRequest(nmChannelHandle)`                                     | 2826 | 上层              | 主动请求 Repeat Message（`RepeatMsgReqFlag`）                             |
| `CanNm_GetPduData(nmChannelHandle, uint8* nmPduDataPtr)`                          | 2884 | 上层              | 读最近接收帧（2 参数，无长度出参）                                                  |
| `CanNm_GetState(nmChannelHandle, &state, &mode)`                                  | 2961 | 上层              | 返回 `CanNm_NmState` 与模式                                              |
| `CanNm_GetVersionInfo(versioninfo)`                                               | 3047 | 上层              | 版本                                                                  |
| `CanNm_RequestBusSynchronization(nmChannelHandle)`                                | 3101 | 上层/网关           | 触发单帧总线同步                                                            |
| `CanNm_CheckRemoteSleepIndication(nmChannelHandle, boolean* nmRemoteSleepIndPtr)` | 3160 | 上层              | 查询远程睡眠（**本项 `REMOTE_SLEEP_IND=OFF`，未导出**）                           |
| `CanNm_SetSleepReadyBit(nmChannelHandle, boolean nmSleepReadyBit)`                | 3223 | 上层/协调器          | 协调器睡眠位（**本项 `COORDINATOR_SYNC=OFF`，未导出**）                           |
| `CanNm_TxConfirmation(TxPduId, result)`                                           | 3301 | CanIf 回调（中断/轮询） | 置 `MsgConfirmationFlag`，由主函数处理                                      |
| `CanNm_RxIndication(RxPduId, PduInfoPtr)`                                         | 3362 | CanIf 回调（中断/轮询） | 拷贝 `RxMessageData`、置 `MsgIndicationFlag` 等                          |
| `CanNm_ConfirmPnAvailability(nmChannelHandle)`                                    | 3546 | CanSM 回调        | PN 可用性（**本项 `PN_FEATURE=OFF`，未导出**）                                 |
| `CanNm_GetMessageReceive(void)`                                                   | 3593 | 应用/诊断           | 读取并清零 `CanNM_Message_Receive`（收到过 NM 帧标志）                           |

## 2. 中层：内部处理函数（static，仅本文件可见）

| 函数                                                           | 行号        | 职责                                                  | 被谁调用                                   |
| ------------------------------------------------------------ | --------- | --------------------------------------------------- | -------------------------------------- |
| `CanNm_MainRxTxConfHandling(ch)`                             | 795       | 处理收发事件标志（`MsgIndicationFlag`/`MsgConfirmationFlag`） | MainFunction                           |
| `CanNm_CommunicationControlHandling(ch)`                     | 2409      | 处理 0x28 发送控制状态迁移（`TxControlState`）                  | MainFunction（COM_CONTROL 开启）           |
| `CanNm_RepeatMessageIndHandling(ch)`                         | 885       | 处理 RMR 位（节点检测）                                      | MainFunction（NODE_DETECTION 开启）        |
| `CanNm_BusCommunicationHandling(ch, commState)`              | 940       | 处理通信请求/释放，驱动状态迁移                                    | MainFunction                           |
| `CanNm_StateTransition(ch, nextState)`                       | 1838      | 状态迁移与进入动作（BusSleep/Prepare/Ready/Normal/Repeat）     | 计时器处理、BusCommunicationHandling 等       |
| `CanNm_TransitionToRepeatMessage(ch)`                        | 1350      | 进入 Repeat Message：启动 RepeatMsgTimer、发送处理            | StateTransition 默认分支                   |
| `CanNm_TransitionToNetworkMode(ch, lastState)`               | 1429      | 进入 Network Mode：启动 `TimeoutTimer`、立即发送判断            | StateTransition 默认分支                   |
| `CanNm_TimeoutTimerHandling(ch)`                             | 976       | NM-Timeout 递减/到期处理                                  | MainFunction                           |
| `CanNm_RepeatMessageTimerHandling(ch)`                       | 1031      | Repeat Message 计时/到期迁移                              | MainFunction                           |
| `CanNm_WaitBusSleepTimerHandling(ch)`                        | 1068      | Prepare Bus-Sleep 计时/到期进入 Bus-Sleep                 | MainFunction                           |
| `CanNm_RemoteSleepTimerHandling(ch)`                         | 1100      | 远程睡眠计时（功能关闭）                                        | MainFunction（宏关闭时不编译）                  |
| `CanNm_MessageTimerHandling(ch)`                             | 1137      | 发送周期定时器；到期调 `CanNm_TriggerTransmission`             | MainFunction                           |
| `CanNm_MessageTimeoutTimerHandling(ch)`                      | 1234      | 发送确认超时处理                                            | MainFunction（非立即确认）                    |
| `CanNm_TriggerTransmission(ch)`                              | 1611      | 组包 + `PduR_CanNmTriggerTransmit` + `CanIf_Transmit` | MessageTimerHandling / StateTransition |
| `CanNm_CopyRxMessageData(PduInfoPtr, ch)`                    | 763       | 把收到帧拷入 `RxMessageData`                              | RxIndication                           |
| `CanNm_PnFilterHandling(...)`                                | 686       | PN 过滤（PN 关闭）                                        | RxIndication                           |
| `CanNm_PnEiraCalculation(ch)` / `CanNm_PnEraCalculation(ch)` | 504 / 605 | PN 请求计算（功能关闭）                                       | MainFunction                           |
| `CanNm_CarWakeupIndication(...)`                             | 1274      | CWU 处理（CWU 关闭）                                      | RxIndication                           |
| `CanNm_CoordReadyToSleepHandling(...)`                       | 1314      | 协调器睡眠位处理（协调器同步关闭）                                   | RxIndication                           |
| `CanNm_LocalInit(ch)`                                        | 1716      | 初始化通道状态/定时器/缓冲/PN                                   | Init                                   |
| `CanNm_PnLocal_Init(ch)`                                     | 1508      | PN 局部初始化（PN 关闭）                                     | LocalInit                              |
| `CanNm_DisablePnFilter(ch)`                                  | 1584      | 停用 PN 过滤（PN 关闭）                                     | 状态迁移/PN 逻辑                             |

> 函数原型声明位于 `CanNm.c` L345~467，定义行见上表。

## 3. `CanNm_MainFunction` 实际调用顺序（代码 L3640~3704）

```text
for (channel = 0; channel < CanNm_GetSizeOfChannelConfig(); channel++)   // 2 个通道
├─ CanNm_MainRxTxConfHandling(channel)              // 收发事件（中断置的标志）
├─ CanNm_CommunicationControlHandling(channel)      // 0x28 发送控制（COM_CONTROL=ON）
├─ commState = CanNm_GetCommState(channel)
├─ CanNm_RepeatMessageIndHandling(channel)          // RMR 位（NODE_DETECTION=ON）
├─ if (NetworkRestartFlag != CANNM_NO_RESTART)
│     CanNm_StateTransition(channel, NM_STATE_REPEAT_MESSAGE)
├─ CanNm_BusCommunicationHandling(channel, commState)  // 请求/释放 → 状态迁移
├─ CanNm_TimeoutTimerHandling(channel)
├─ CanNm_RepeatMessageTimerHandling(channel)
├─ CanNm_WaitBusSleepTimerHandling(channel)
├─ CanNm_RemoteSleepTimerHandling(channel)          // REMOTE_SLEEP=OFF，不编译
├─ CanNm_MessageTimerHandling(channel)              // 周期/立即发送
├─ CanNm_MessageTimeoutTimerHandling(channel)       // 立即确认关闭时
├─ CanNm_PnEiraCalculation(channel)                 // PN 关闭，不编译
└─ CanNm_PnEraCalculation(channel)                  // PN 关闭，不编译
```

**说明**：

- 本代码用“每周期递减定时器 + 到期在 handler 内迁移”的写法，没有独立的“规则求值”框架；
- `CanNm_StateTransition` 是所有状态变化的唯一入口（除 Init 直接置 Bus-Sleep）；
- `CanNm_TriggerTransmission` 是唯一组包/发送入口（`CanIf_Transmit` 在 L1685）；
- 中断回调只置标志/拷贝缓冲，重活都在主函数，符合“回调短、主函数处理”的实现习惯。

## 4. 上下文与可重入

| 类别 | 上下文 | 说明 |
|---|---|---|
| `CanNm_MainFunction` | 任务 | 不可重入 |
| `CanNm_Init` | 初始化 | 不可重入，必须在 CanIf 之后 |
| `CanNm_RxIndication` / `CanNm_TxConfirmation` | 中断或轮询 | 只置标志/拷贝数据；不同 PDU 可重入 |
| 其余 API | 任务 | 同一通道不可重入 |

## 5. 与文档旧内容的差异（已修正）

| 旧文档写法 | 代码实际 |
|---|---|
| “中间层逻辑名 `CanNm_TimerHandling`” | 拆成 6 个独立 timer handler（Timeout/Repeat/WaitBusSleep/RemoteSleep/Msg/MsgTimeout） |
| “`CanNm_StateMachine`” | 实际 `CanNm_StateTransition` + 各 handler 内的条件迁移 |
| “`CanNm_BuildPdu`” | 实际 `CanNm_TriggerTransmission`（组包 + PduR 用户数据 + CanIf 发送） |
| “`CanNm_RxHandling`” | 实际 `CanNm_MainRxTxConfHandling` + `CanNm_CopyRxMessageData` + `CanNm_PnFilterHandling` |
| “配置指针 `CanNm_ConfigPtr`” | 本实现 `CanNm_Init` 实际 **忽略** 配置指针（`CANNM_DUMMY_STATEMENT`），配置由 `CanNm_ChannelConfig[]` 常量表直接引用 |
| “`CanNm_ChannelState` 结构体” | 不存在；状态用多个按通道数组（见 [[CanNm_全局变量说明]]） |

## 6. 关联

- 变量清单与读写宏：[[CanNm_全局变量说明]]
- 主函数伪代码与配置值：[[CanNm_MainFunction调用逻辑]]
- 实现路径与需求：[[CanNm_D1_主动唤醒调用逻辑]]、[[CanNm_D3_主状态转移逻辑]]、[[CanNm_D5_周期发送与降载调用逻辑]]

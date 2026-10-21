---
tags: [AUTOSAR, CanNm, 调用逻辑]
---

# CanNm D7：扩展特性调用逻辑

> [!info] 导航
> 上级：[[CanNm_调用逻辑总览]] ｜ 依赖：[[CanNm_D4_状态转换表]]、[[CanNm_D5_周期发送与降载调用逻辑]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11#SWS_CanNm_004xx|需求表]]

> 适用版本：AUTOSAR CP R21-11　依据：SWS_CanNm 7.9~7.13
> 最后更新：2026-10-21　关联：[[CanNm_调用逻辑总览]]、[[CanNm_D2_被动唤醒调用逻辑]]、[[CanNm_D4_状态转换表]]

本方向把不属于"基本唤醒/状态机/周期发送"的附加特性集中说明。按需阅读，各小节可独立成未来更细的方向。

## 7.1 远程睡眠检测（网关）

```text
Normal Operation 中持续收不到 NM 帧
  → CanNmRemoteSleepIndTime 到期
  → Nm_RemoteSleepIndication(ch)          [告诉 Nm：其他节点都 Ready Sleep]
再次收到 NM 帧（Normal/Ready Sleep）
  → Nm_RemoteSleepCancellation(ch)
```
依据：SWS_CanNm_00149~00154。查询：`CanNm_CheckRemoteSleepIndication`（Bus-Sleep/Prepare/Repeat Message 时返回 E_NOT_OK）。

## 7.2 NM 用户数据

两条路径：

| 方式 | 配置 | 数据来源 | API/接口 |
|---|---|---|---|
| 本地 API | `CanNmUserDataEnabled=TRUE` | `CanNm_SetUserData` 设置 | `CanNm_SetUserData/GetUserData`、`CanNm_GetPduData` |
| Com 用户数据 | `CanNmComUserDataSupport=TRUE` | Com 的 NM User Data I-PDU | `PduR_CanNmTriggerTransmit`、`PduR_CanNmTxConfirmation`、`CanNm_TriggerTransmit` |

要点：

- 用户数据占 PDU 中系统字节/PNC 之外的剩余字节；
- 初始化时用户数据置 0xFF、CBV 置 0x00（SWS_CanNm_00025、00085）；
- 降载模式下 Normal Operation 的用户数据**不一定每周期都发**（见 [[CanNm_BusLoadReductionActive说明]]）；
- 长度不匹配在生成期报错（SWS_CanNm_00332）。

## 7.3 被动模式

- `CanNmPassiveModeEnabled=TRUE`：只收不发（监听/测试节点）；
- 与发送相关参数互斥（`BusLoadReductionEnabled`、`ImmediateTxconf` 等必须 FALSE）；
- passive 时 `CanNm_NetworkRequest/Release`、`CanNm_SetUserData` 等发送相关 API 不可用。

## 7.4 Car Wakeup（CWU）

```text
收到 NM 帧 → 检查 CWU 位（位置：CanNmCarWakeUpBytePosition/BitPosition）
  ├─ CanNmCarWakeUpFilterEnabled=FALSE → 直接 Nm_CarWakeUpIndication
  └─ 过滤开启 → 仅当源节点 ID = CanNmCarWakeUpFilterNodeId 时才上报
```
依据：SWS_CanNm_00405~00408。发送侧 CWU 位由应用通过用户数据机制写入。

## 7.5 节点检测（RMR）

- 条件：`CanNmNodeDetectionEnabled=TRUE`（依赖 `CanNmNodeIdEnabled`）；
- 收到 RMR 位或调用 `CanNm_RepeatMessageRequest` → 进入/重启 Repeat Message；
- 收到 RMR 通知上层：`Nm_RepeatMessageIndication`（`CanNmRepeatMsgIndEnabled=TRUE`，每轮只报一次）；
- 离开 Repeat Message 时清 RMR 位。

## 7.6 部分网络（PNC）

R21-11 重构后的 PN 主要流程：

```text
Rx：收到 NM 帧
  ├─ PNI 位=0 且 AllNmMessagesKeepAwake=TRUE → 不丢弃（网关保持唤醒）
  ├─ PNI 位=0 且 AllNmMessagesKeepAwake=FALSE → 丢弃该帧
  └─ PNI 位=1 → 解析 PNC 位向量 → Nm_PncBitVectorRxIndication（供 Nm 聚合外部 PNC 请求）

Tx：发送前
  └─ Nm_PncBitVectorTxIndication（获取聚合的内部 PNC 请求）→ 写入 PNC 位向量
```
扩展：`CanNm_RequestSynchronizedPncShutdown`（同步 PNC 关闭，PNSR 位）、`CanNm_PnLearningRequest`（动态 PNC 映射学习，draft）。

注意：R21-11 中 `CanNmPnInfo`/`CanNmPnFilterMaskByte` 等容器已 obsolete；PNC 位向量位置改由 Nm 的 `NmPncBitVectorOffset/Length` 配置。

## 7.7 协调器同步（多网关）

- `CanNmCoordinatorSyncSupport=TRUE`；
- 收到 CBV "NM Coordinator Sleep" 位置 1 → `Nm_CoordReadyToSleepIndication`；清 0 → `Nm_CoordReadyToSleepCancellation`；
- `CanNm_SetSleepReadyBit` 设置该位并触发一帧。

## 7.8 总线同步

- `CanNmBusSynchronizationEnabled=TRUE` 时，`CanNm_RequestBusSynchronization` 触发单帧 NM PDU（网关用）；
- Bus-Sleep/Prepare Bus-Sleep 下返回 E_NOT_OK；发送能力禁用时返回 E_NOT_OK。

## 7.9 发送错误处理

| 场景 | 动作 | 依据 |
|---|---|---|
| 确认 E_NOT_OK | `Nm_TxTimeoutException` | 00066 |
| PN 发送超时 | `Nm_TxTimeoutException` + `CanSM_TxTimeoutException` | 00066、00446 |
| passive / 立即确认 | 跳过错误处理 | 00073 |
| `CanIf_Transmit` 拒绝 | 下个主函数重试 | 00335 |

## 7.10 状态变化通知与 PDU 接收通知

- `CanNmStateChangeIndEnabled=TRUE` → 每次状态变化 `Nm_StateChangeNotification`；
- `CanNmPduRxIndicationEnabled=TRUE` → 每收到帧 `Nm_PduRxIndication`。

## 7.11 相关需求

SWS_CanNm_00037、00073、00149~00154、00156~00166、00185、00187、00280、00282、00327~00332、00341、00342、00344~00351、00401~00454、91001。

## 7.12 与主线的连接

- 用户数据/PNC/CWU 都在接收与发送处理中，见 [[CanNm_D5_周期发送与降载调用逻辑]]；
- 远程睡眠/协调器同步影响睡眠决策，见 [[CanNm_D4_状态转换表]]；
- 上述特性由配置开关裁剪，见 [[CanNm_DaVinci配置项]]。

## 实现对应（代码）

- **PNC**：`CANNM_PN_FEATURE_ENABLED=STD_OFF`，`PnFilterHandling/PnEiraCalculation/PnEraCalculation/PnLocal_Init` 均不参与实际逻辑；
- **CarWakeup**：`CanNm_CarWakeupIndication` 存在但 `CANNM_CAR_WUP_RX_FEATURE_ENABLED=STD_OFF`；
- **远程睡眠**：`CanNm_RemoteSleepTimerHandling` 在 `CANNM_REMOTE_SLEEP_IND_ENABLED=STD_OFF` 时不编译；
- **协调器同步**：`CANNM_COORDINATOR_SYNC_SUPPORT=STD_OFF`；
- **厂商扩展**：`CanNm_GetMessageReceive`、`Can_NM_UserData_Fill`、`CanNm_GetTxUserNMEnable`、`CANNM_RMR_FAST_TRANSITION` 等不在 SWS 中。

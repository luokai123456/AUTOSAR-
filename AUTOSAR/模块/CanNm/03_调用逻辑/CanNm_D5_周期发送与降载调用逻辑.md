---
tags: [AUTOSAR, CanNm, 调用逻辑]
---

# CanNm D5：周期发送与降载调用逻辑

> [!info] 导航
> 上级：[[CanNm_调用逻辑总览]] ｜ 依赖：[[CanNm_D4_状态转换表]]、[[CanNm_BusLoadReductionActive说明]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11#SWS_CanNm_000xx|需求表]]

> 适用版本：AUTOSAR CP R21-11　依据：SWS_CanNm 7.6、7.7、7.8、7.9.2、7.12
> 最后更新：2026-10-21　关联：[[CanNm_调用逻辑总览]]、[[CanNm_D1_主动唤醒调用逻辑]]、[[CanNm_D4_状态转换表]]

## 1. 范围

本文覆盖主函数里的"发送调度"：Normal Operation / Repeat Message 下的周期发送、立即发送（唤醒突发）、总线负载降低、Com 用户数据发送、PN shutdown 发送、发送确认与错误处理。

## 2. 发送触发条件

| 条件 | 说明 | 依据 |
|---|---|---|
| 当前在 Network Mode | Repeat Message / Normal Operation 发送；Ready Sleep 停发 | SWS 7.7.1 |
| PDU 发送能力使能 | 非 passive 且未被 `DisableCommunication` 禁止 | SWS_CanNm_00072、00170 |
| Message Cycle Timer 到期 | 周期发送的主触发 | SWS_CanNm_00040 |
| 立即发送阶段未结束 | `CanNmImmediateNmTransmissions > 0` 的唤醒突发 | SWS_CanNm_00334、00335 |
| 有待发 PN shutdown | 协调器同步关闭 | SWS 7.11.2 |
| 触发式发送 | `CanIfTxPduTriggerTransmit=TRUE` 时由 CanIf 调 `CanNm_TriggerTransmit` 填充 | SWS_CanNm_00351、91001 |

## 3. 调用链（从上到下）

```text
CanNm_MainFunction()
├─ 定时器处理：Message Cycle Timer 到期（或立即发送未完成）
├─ CanNm_TxPdu(ch)（逻辑名）
│   ├─ 组包 CanNm_BuildPdu()
│   │    ├─ SNI ← CanNmNodeId（CanNmPduNidPosition 指定位置）
│   │    ├─ CBV ← RMR/PNSR/ActiveWakeup/PNL/PNI 位
│   │    ├─ PNC 位向量 ← Nm_PncBitVectorTxIndication（PN 时）
│   │    └─ 用户数据：本地缓存 或 PduR_CanNmTriggerTransmit（Com 模式）
│   ├─ 若需立即发送：使用 CanNmImmediateNmCycleTime 间隔连发 N 帧
│   └─ CanIf_Transmit(TxPduId, &PduInfo)                     [CanIf]
│        └─ Can Driver → 总线
└─ 等待确认：
    ├─ CanNm_TxConfirmation(TxPduId, E_OK)
    │    ├─ 重启 NM-Timeout Timer（00099）
    │    ├─ 重装 Message Cycle Timer = CanNmMsgCycleTime（00040）
    │    └─ Com 用户数据时转发 PduR_CanNmTxConfirmation（00329）
    └─ E_NOT_OK / 超时：
         ├─ Nm_TxTimeoutException（00066）
         └─ PN：CanSM_TxTimeoutException（00446）
```

## 4. 总线负载降低（Bus Load Reduction）

前提：`CanNmBusLoadReductionEnabled=TRUE` 且 `CanNmBusLoadReductionActive=TRUE`（详见 [[CanNm_BusLoadReductionActive说明]]）。

| 事件 | Message Cycle Timer 重装值 |
|---|---|
| 收到其他节点的 NM PDU | `CanNmMsgReducedTime`（节点私有，0.5×Cycle ≤ 它 < Cycle） |
| 自己发出 NM PDU | `CanNmMsgCycleTime`（全网一致） |

效果：`MsgReducedTime` 最小的约两个节点轮流发帧，每 `MsgCycleTime` 最多约 2 帧；状态机在进入 Repeat Message 时停用降载、进入 Normal Operation 时启用（SWS_CanNm_00156、00157）。

## 5. 立即发送（唤醒突发）

- 触发：从 Bus-Sleep/Prepare Bus-Sleep 因 `CanNm_NetworkRequest` 进入 Repeat Message（主动唤醒），且 `CanNmImmediateNmTransmissions > 0`；
- 行为：第 1 帧尽可能快地发出，随后按 `CanNmImmediateNmCycleTime` 连发，共 N 帧；期间**不**使用 `CanNmMsgCycleOffset`，且暂停正常周期发送；
- 失败处理：`CanIf_Transmit` 返回 E_NOT_OK 时下一个主函数重试，之后回到 `CanNmMsgCycleTime` 周期（SWS_CanNm_00335）。

## 6. PN shutdown 报文（协调器）

- 前提：PN 支持 + 协调器同步 + 有待发 PNC（`CanNm_RequestSynchronizedPncShutdown`）；
- 行为：主函数中组装 PNSR=1 的报文，PNC 位向量按待关闭 PNC 置位，发送并等待确认；失败按配置重传（`CanNmPnShutdownMessageRetransmissionDuration`）；
- 发送期间可推迟正常的周期 NM 发送（SWS_CanNm_00460）。

## 7. 发送失败与错误处理

| 场景 | 处理 | 依据 |
|---|---|---|
| `CanIf_Transmit` 返回 E_NOT_OK | 记录失败，下一个主函数重试 | SWS_CanNm_00335 |
| `CanNm_TxConfirmation` = E_NOT_OK | `Nm_TxTimeoutException` | SWS_CanNm_00066 |
| PN 发送超时（`CanNmMsgTimeoutTime`） | `Nm_TxTimeoutException` + `CanSM_TxTimeoutException` | SWS_CanNm_00066、00446 |
| passive 或立即确认开启 | 不做发送错误处理 | SWS_CanNm_00073 |
| 通信被 0x28 禁用 | 停 Message Cycle Timer，不发送 | SWS_CanNm_00173 |

## 8. 状态与数据变化

| 数据 | 变化 |
|---|---|
| Message Cycle Timer | 发帧后重装 `MsgCycleTime`；收帧重装 `MsgReducedTime`；立即发送阶段用 `ImmediateNmCycleTime` |
| NM-Timeout Timer | 发送确认成功后重启；收帧时重启 |
| CBV | 每帧按当前状态设置 RMR/PNSR/ActiveWakeup/PNI 位 |
| 用户数据 | 发送前取最新值（API 设置值或 Com 用户数据） |

## 9. 需求依据

SWS_CanNm_00005、00006、00013、00035、00040、00051、00052、00064~00066、00069、00071、00073、00074、00075、00099、00100、00116、00122、00130、00156、00157、00170、00173、00178、00181、00237、00238、00327~00335、00351、00446、00450、00454、91001。

## 10. 观测点 / 排障

1. 抓总线看 NM 帧间隔：正常 = `MsgCycleTime`；降载 = 两帧靠得近 + 静默交替；Repeat Message 前几帧可能是立即发送；
2. 若"一直不发"：查状态是否 Network Mode、发送能力是否被禁、passive 是否打开；
3. 若"发了但确认超时"：查 CanIf 的 Tx PDU/确认 ID 配置、总线错误；
4. 若"负载降低没效果"：确认全局 Enabled + 通道 Active 都打开（[[CanNm_BusLoadReductionActive说明]]）。

## 实现对应（代码）

- 发送周期：`CanNm_MessageTimerHandling`（L1137）递减 `CanNm_MsgTimer`，到期调 `CanNm_TriggerTransmission`（L1611）；
- 发送：`CanIf_Transmit(CanNm_GetTxPduRef(ch))`（L1685），缓冲 `CanNm_TxMessageData[ch][8]`；
- 立即发送：`CanNm_ImmediateNmMsgCount` 递减、`ImmediateNmCycleTime` 重装（本项目 4ms × 10 帧）；
- 降载：`CanNm_BusLoadReductionActive[ch]` + `CanNm_GetMsgReduceTime()`；本项目配置 `BusLoadReductionActive=FALSE`，降载未启用。

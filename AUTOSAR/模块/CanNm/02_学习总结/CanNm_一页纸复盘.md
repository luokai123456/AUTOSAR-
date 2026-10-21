---
tags: [AUTOSAR, CanNm, 学习总结]
---

# CanNm 一页纸复盘（面试/工作可复述版）

> [!info] 导航
> 上级：[[CanNm]] ｜ 依赖：[[CanNm_调用逻辑总览]]、[[CanNm_D4_状态转换表]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11]]

> 用途：3 分钟讲清 CanNm；10 分钟讲清状态机与配置。依据 R21-11 SWS。

## 1. 30 秒版本

CanNm 是 AUTOSAR 的 CAN 网络管理协议实现，夹在 Nm 和 CanIf 之间。它用周期性的 NM 报文做分散式直接网络管理：节点需要通信就周期发帧表示"保持唤醒"，不需要了就先停发但仍监听；只要还能收到别人的帧就不睡，直到 `CanNmTimeoutTime` 内收不到任何 NM 帧，再进 Prepare Bus-Sleep，静默 `CanNmWaitBusSleepTime` 后进 Bus-Sleep。它自己不做 ECU 电源决策，只通过 `Nm_*` 回调让上层决定。

## 2. 必背的 5 个状态 / 3 个模式

- Network Mode：Repeat Message → Normal Operation → Ready Sleep（内部三状态）
- Prepare Bus-Sleep Mode
- Bus-Sleep Mode
- 另有并行网络状态：requested / released

## 3. 必背的定时参数关系

| 关系 | 说明 |
|---|---|
| `TimeoutTime > MsgCycleTime` | NM-Timeout 必须大于报文周期，且全网一致 |
| `MsgCycleOffset < MsgCycleTime` | 发送偏移不能超过周期 |
| `0.5×MsgCycleTime ≤ MsgReducedTime < MsgCycleTime` | 降载模式 |
| `RepeatMessageTime ≈ n × MsgCycleTime` | 通常为整数倍；=0 表示瞬时 |
| `WaitBusSleepTime` 足够清空 Tx buffer | 全网一致 |
| `MainFunctionPeriod` = 任务周期 | 否则所有定时器整体偏移 |

## 4. 运行时 6 步

1. SchM 周期调用 `CanNm_MainFunction`（处理所有通道）；
2. 所有定时器减一个周期；
3. 到期事件驱动状态机（Repeat/NM-Timeout/WaitBusSleep/RemoteSleep/TxTimeout）；
4. Network Mode + 发送允许 → 组装 NM PDU（SNI/CBV/PNC/UserData）→ `CanIf_Transmit`；
5. 发送确认后重装周期、重启 NM-Timeout；失败触发 Tx Timeout 流程；
6. 处理接收/PNC/CarWakeup，回调 Nm 通知上层。

## 5. CBV 6 个位

RMR（bit0，请求进 Repeat Message）、PNSR（bit1，PN 同步关闭）、Coordinator Sleep（bit3）、Active Wakeup（bit4）、PNL（bit5）、PNI（bit6）。

## 6. 4 个高频故障 → 根因

| 现象 | 优先查 |
|---|---|
| 总线上有 NM 帧但 ECU 不醒 | Bus-Sleep 下只回调 `Nm_NetworkStartIndication`，唤醒决策在 EcuM/ComM |
| 网络反复进入 Prepare Bus-Sleep | `CanNmTimeoutTime` 是否 ≤ `MsgCycleTime`；主函数周期是否偏大/被抢占 |
| 所有节点同时发帧、总线负载高 | 开 `CanNmMsgCycleOffset`；多节点开 Bus Load Reduction |
| 诊断 0x28 后收不到 NM 帧但状态没变 | 检查 `CanNmComControlEnabled`；通信被禁时状态机不变、只停发送与超时监控 |

## 7. 自测题

1. CanNm 的 5 个状态如何迁移？各自的触发条件？（SWS 7.2）
2. requested/released 与状态机的区别？（SWS 7.3）
3. 收到 NM 帧时哪些定时器被重启？（SWS 7.2.1、7.7.2）
4. 降载算法为什么能保证"最多约 2 帧/周期"？（SWS 7.8）
5. 初始化时 CanNm 处于什么状态？CBV/用户数据初值？（SWS 7.4）
6. `CanNm_DisableCommunication` 会停哪些定时器？（SWS 7.9.6）
7. Bus-Sleep 下收到 NM 帧为什么不自动唤醒？（SWS_CanNm_00127 Rationale）
8. CanNm 与 Nm、ComM 的分工？（SWS 5、Nm SWS）
9. PDU 中 SNI/CBV/PNC/用户数据的位置由哪些参数决定？（SWS 7.6）
10. 节点检测依赖哪些配置和 CBV 位？（SWS 7.2.1.1、7.6）

## 8. 讲项目时的模板

> "我们 CAN 网络的 NM 用 CanNm：周期 500ms，Timeout 1500ms，WaitBusSleep 2000ms，RepeatMessageTime 2s，主函数 10ms。ComM 收到网络请求后经 Nm 调 CanNm_NetworkRequest，进 Repeat Message 后开始周期发 NM 帧并回调 Nm_NetworkMode；释放后进 Ready Sleep，收不到帧 1.5s 进 Prepare Bus-Sleep，再 2s 进 Bus-Sleep。多节点网络开了降载，MsgReducedTime 配 300ms，避免 NM 负载随节点数增长。诊断 0x28 通信控制时通过 Nm 调 Disable/Enable，只停 NM 发送和超时监控，状态机保持不变。"

---
tags: [AUTOSAR, CanNm, 学习总结]
---

# CanNm 在 DaVinci Configurator 中的配置项详解

> [!info] 导航
> 上级：[[CanNm]] ｜ 依赖：[[CanNm_配置参数表_R21-11]]、[[CanNm_D4_状态转换表]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11]]

> 适用版本：AUTOSAR CP R21-11　依据：SWS_CanNm 第 10 章（ECUC 配置规范）、第 7 章功能约束
> 工具：Vector DaVinci Configurator Classic（界面措辞随版本略有差异，容器/参数名与 ECUC 规范一致）
> 最后更新：2026-10-20

## 0. 配置前的依赖（必须先在 DaVinci 里配好）

| 依赖对象 | 为什么必须先配 | 在 CanNm 中引用为 |
|---|---|---|
| **CanIf** 的 Tx/Rx PDU（CanIfTxPdu / CanIfRxPdu） | CanNm 的 NM PDU 实际走 CanIf | `CanNmTxPduRef`、`CanNmRxPduRef` |
| **ECUC Pdu** 定义（全局 PDU 集合） | PDU 引用目标 | 上述 `*PduRef` |
| **CanIf** 的 `CanIfTxPduTriggerTransmit`（如需 Com 用户数据/触发式发送） | 决定发送时是否回调 `CanNm_TriggerTransmit` | 影响 `CanNmComUserDataSupport` 行为 |
| **ComM** 的 ComMChannel | CanNm 通过句柄把通道映射到 ComM | `CanNmComMNetworkHandleRef` |
| **ComM** 的 ComMUser（如用通信模式控制） | 上层请求经 Nm 到 CanNm | 间接 |
| **CanSM**（如启用 PN 可用性通知） | `CanNm_ConfirmPnAvailability` | 间接 |
| **Com / PduR**（如用 Com 用户数据） | `CanNmUserDataTxPdu` 引用 NM User Data I-PDU | `CanNmTxUserDataPduRef` |

> 典型报错：`CanNmTxPduRef` 选不到目标 → 先确认 CanIf 里已生成该 Tx PDU；`CanNmComMNetworkHandleRef` 为空 → 先建 ComMChannel。

## 1. 配置树总览

```text
CanNm
└─ CanNmGlobalConfig                       （1 个，全局）
   ├─ 全局开关/周期参数（见 2.1）
   ├─ CanNmPnInfo                          （0..1，R21-11 已 obsolete）
   │  └─ CanNmPnFilterMaskByte             （1..63，已 obsolete）
   └─ CanNmChannelConfig                   （1..*，每个 CAN 通道一个）
      ├─ 通道级参数（见 2.2）
      ├─ CanNmRxPdu                        （1..*）
      │  ├─ CanNmRxPduId
      │  └─ CanNmRxPduRef
      ├─ CanNmTxPdu                        （0..1）
      │  ├─ CanNmTxConfirmationPduId
      │  └─ CanNmTxPduRef
      └─ CanNmUserDataTxPdu                （0..1，仅 CanNmComUserDataSupport=TRUE 时）
         ├─ CanNmTxUserDataPduId
         └─ CanNmTxUserDataPduRef
```

## 2. 参数详解

### 2.1 CanNmGlobalConfig（全局参数）

| 参数 | 类型/范围 | 默认 | 作用 | 工程建议 |
|---|---|---|---|---|
| `CanNmMainFunctionPeriod` | float，秒，>0 | 无 | `CanNm_MainFunction` 调用周期 | **必须等于实际任务周期**；决定所有定时器精度 |
| `CanNmDevErrorDetect` | bool | false | 开发错误检测（DET） | 开发 TRUE，量产 FALSE |
| `CanNmVersionInfoApi` | bool | false | 是否生成 `CanNm_GetVersionInfo` | 需要版本读取时 TRUE |
| `CanNmPassiveModeEnabled` | bool | 无 | 被动模式：只收不发 | 仅监听/测试节点；全网 ECU 必须一致 |
| `CanNmUserDataEnabled` | bool | 无 | 是否支持 NM 用户数据（API 方式） | 有剩余字节且需要用户数据时 TRUE |
| `CanNmComUserDataSupport` | bool | 无 | 用户数据改从 Com 取（走 `PduR_CanNmTriggerTransmit`） | 用 Com 配置用户数据时 TRUE；此时 `CanNm_SetUserData` 不可用 |
| `CanNmBusLoadReductionEnabled` | bool | 无 | **预编译**开关：是否支持总线负载降低 | 多节点网络建议 TRUE；passive/PN 全局支持时必须 FALSE |
| `CanNmImmediateTxconfEnabled` | bool | 无 | 立即发送确认（不等 CanIf 真实确认） | 离线调度工具已规划总线时可用；不能与 passive 同开 |
| `CanNmImmediateRestartEnabled` | bool | 无 | Prepare Bus-Sleep 中被请求时立即发一帧重启网络 | 唤醒实时性要求高时 TRUE；注意突发帧 |
| `CanNmRemoteSleepIndEnabled` | bool | 无 | 远程睡眠检测（网关用） | 网关 ECU TRUE |
| `CanNmStateChangeIndEnabled` | bool | 无 | 状态变化通知 `Nm_StateChangeNotification` | 需要上层跟踪 NM 状态时 TRUE |
| `CanNmPduRxIndicationEnabled` | bool | 无 | 收到 NM 帧时回调 `Nm_PduRxIndication` | 上层需要原始帧时 TRUE |
| `CanNmComControlEnabled` | bool | 无 | 通信控制（0x28 服务） | 有诊断通信控制时 TRUE |
| `CanNmBusSynchronizationEnabled` | bool | 无 | 总线同步（网关） | 网关节点 TRUE |
| `CanNmCoordinatorSyncSupport` | bool | 无 | 协调器同步（多网关协同关闭） | 主/从协调器 TRUE |
| `CanNmGlobalPnSupport` | bool | false | 全局 PNC 支持开关 | 部分网络项目 TRUE；为 TRUE 时 passive 必须 FALSE |
| `CanNmDynamicPncToChannelMappingSupport` | bool | 无 | 动态 PNC→通道映射（draft） | 仅特殊网关需求 |
| `CanNmPnSyncShutdownErrorReactionEnabled` | bool | 无 | 顶层协调器收到冲突 PN shutdown 时的错误反应 | 仅协调器且启用同步关闭时 |
| `CanNmPnShutdownMessageRetransmissionDuration` | float | 无 | PN shutdown 报文重传持续时间 | 需同步关闭；≤ PnResetTime，且为 MainFunctionPeriod 整数倍 |
| `CanNmPnInfo` / `CanNmPnInfoLength` / `CanNmPnInfoOffset` / `CanNmPnFilterMaskByte*` | — | — | **R21-11 已 obsolete**（PN 重做，位置改由 Nm 的 `NmPncBitVectorOffset/Length` 配置） | 新项目不要使用 |

### 2.2 CanNmChannelConfig（每通道参数）

**基础与身份**

| 参数 | 类型/范围 | 作用 | 约束/建议 |
|---|---|---|---|
| `CanNmComMNetworkHandleRef` | 引用 ComMChannel | 本通道对应的 ComM 通道（拿到 ComMChannelId） | 必配 |
| `CanNmNodeId` | 0..255 | 本节点地址（SNI） | 全网唯一；`CanNmNodeIdEnabled=TRUE` 时有效 |
| `CanNmNodeIdEnabled` | bool | 是否在 PDU 中携带 SNI | 需要节点检测/PN 过滤/CarWakeup 过滤时 TRUE |
| `CanNmNodeDetectionEnabled` | bool | 节点检测（处理 RMR 位/API） | 依赖 `CanNmNodeIdEnabled=TRUE`；passive 时必须 FALSE |
| `CanNmRepeatMsgIndEnabled` | bool | RMR 位收到时通知 `Nm_RepeatMessageIndication` | 仅在节点检测或动态 PNC 映射时有效 |

**定时参数**

| 参数 | 类型/范围 | 作用 | 约束/建议 |
|---|---|---|---|
| `CanNmMsgCycleTime` | 0.001..65.535 s | NM 报文周期 | **全网一致**；passive 时不用 |
| `CanNmMsgCycleOffset` | 0..65.535 s | 发送起始偏移（防同时上电突发） | < `MsgCycleTime`；节点私有 |
| `CanNmMsgReducedTime` | 0.001..65.535 s | 负载降低模式下的缩短周期 | `0.5×Cycle ≤ 它 < Cycle`；仅 BL reduction 启用时有效 |
| `CanNmTimeoutTime` | 0.002..65.535 s | NM-Timeout：Ready Sleep 等多久进 Prepare Bus-Sleep | **必须 > MsgCycleTime，全网一致** |
| `CanNmWaitBusSleepTime` | 0.001..65.535 s | Prepare Bus-Sleep 停留时间 | 全网一致；足够清空 Tx buffer |
| `CanNmRepeatMessageTime` | 0..65.535 s | Repeat Message 停留时间 | 通常 = n × MsgCycleTime；=0 表示"瞬时"，启动稳定性差 |
| `CanNmRemoteSleepIndTime` | 0.001..65.535 s | 远程睡眠判定时间 | ≥ MsgCycleTime；仅 `RemoteSleepIndEnabled` 时有效 |
| `CanNmMsgTimeoutTime` | 0.001..65.535 s | PN 发送超时监控（Tx Timeout） | < `MsgCycleTime`；仅 PN 且非 passive/非立即确认时有效 |
| `CanNmImmediateNmTransmissions` | 0..255 | 唤醒时立即发送的 NM 帧数 | 0=不发；`ImmediateRestartEnabled` 时必须 0；`PnHandleMultipleNetworkRequests` 时必须 >0 |
| `CanNmImmediateNmCycleTime` | 0.001..65.535 s | 上述立即发送的帧间隔 | 仅 `ImmediateNmTransmissions > 0` 时有效 |

**PDU 格式**

| 参数 | 取值 | 作用 | 约束 |
|---|---|---|---|
| `CanNmPduNidPosition` | `CANNM_PDU_BYTE_0` / `BYTE_1` / `OFF` | SNI 在 PDU 中的位置 | 与 CBV 位置不能重复；`NodeIdEnabled` 时不能 OFF |
| `CanNmPduCbvPosition` | `CANNM_PDU_BYTE_0` / `BYTE_1` / `OFF` | CBV 位置 | 节点检测开启时不能 OFF；与 NID 不能同字节 |

**功能开关**

| 参数 | 作用 | 约束 |
|---|---|---|
| `CanNmBusLoadReductionActive` | 本通道是否启用负载降低 | 依赖全局 `BusLoadReductionEnabled=TRUE` |
| `CanNmCarWakeUpRxEnabled` | 是否解析 CarWakeup 位 | 需要 CWU 时 TRUE |
| `CanNmCarWakeUpBytePosition` / `CanNmCarWakeUpBitPosition` | CWU 位在 PDU 中的位置 | 仅在 `CarWakeUpRxEnabled` 时；Byte 位置 ≥ 系统字节数 |
| `CanNmCarWakeUpFilterEnabled` / `CanNmCarWakeUpFilterNodeId` | 只接受指定源节点（如中央网关）的 CWU | 仅 `CarWakeUpRxEnabled` 时 |
| `CanNmActiveWakeupBitEnabled` | 是否维护 CBV 的 Active Wakeup 位 | 主动唤醒需要区分时 TRUE |
| `CanNmStayInPbsEnabled` | 停留在 Prepare Bus-Sleep 不自动进 Bus-Sleep | TRUE 时 `WaitBusSleepTime` 不再触发休眠 |
| `CanNmAllNmMessagesKeepAwake` | PN 下不丢弃"无 PNI"的 NM 帧 | 网关保持唤醒时 TRUE |
| `CanNmPnEnabled` | 本通道是否支持部分网络 | 依赖 `GlobalPnSupport=TRUE` |
| `CanNmPnHandleMultipleNetworkRequests` | 多 PNC 请求时再进 Repeat Message | 仅 PN；且要求立即发送帧数 >0 |
| `CanNmDynamicPncToChannelMappingEnabled` | 动态 PNC→通道映射 | 仅 `DynamicPncToChannelMappingSupport=TRUE` |
| `CanNmSynchronizedPncShutdownEnabled` | 同步 PNC 关闭（协调器） | 仅 PN + ERA 计算；draft |

### 2.3 PDU 子容器

| 容器/参数 | 作用 | 注意 |
|---|---|---|
| `CanNmRxPdu/CanNmRxPduId` | CanIf 侧 NM Rx PDU 的句柄 | 由配置工具生成符号名 |
| `CanNmRxPdu/CanNmRxPduRef` | 引用全局 Pdu | 必须与 CanIf 的 Rx PDU 对应 |
| `CanNmTxPdu/CanNmTxConfirmationPduId` | 发送确认句柄（CanIf → `CanNm_TxConfirmation` 传入） | 必须与 CanIf Tx PDU 的 confirmation ID 一致 |
| `CanNmTxPdu/CanNmTxPduRef` | 引用全局 Tx Pdu | — |
| `CanNmUserDataTxPdu/CanNmTxUserDataPduId` | Com 用户数据 I-PDU 句柄 | 仅 `ComUserDataSupport=TRUE` |
| `CanNmUserDataTxPdu/CanNmTxUserDataPduRef` | 引用 NM User Data I-PDU | 数据长度必须匹配 |

## 3. DaVinci 配置流程（建议顺序）

1. **完成 CanIf 配置**：CAN 控制器、收发 PDU、`CanIfTxPduTriggerTransmit`（按需）。
2. **完成 ComM/CanSM/Com**（按项目需要）：ComMChannel、ComMUser、PNC 相关配置。
3. 在 BSW Modules 中添加 **CanNm**，选择配置变体（VARIANT）。
4. 配 `CanNmGlobalConfig`：先定 `CanNmMainFunctionPeriod`，再按功能打开各开关（passive、PN、BL reduction、ComControl 等）。
5. 添加 **CanNmChannelConfig**（每个 CAN 通道一个）：绑定 `CanNmComMNetworkHandleRef`，填写定时参数与 PDU 格式参数。
6. 添加 **CanNmRxPdu / CanNmTxPdu**：引用 CanIf PDU；确认 Tx confirmation ID 与 CanIf 一致。
7. 如需 Com 用户数据：打开 `CanNmComUserDataSupport`，添加 `CanNmUserDataTxPdu` 并引用 I-PDU。
8. 如需 PN：按 R21-11 方式在 Nm 中配 `NmPncBitVectorOffset/Length`，CanNm 侧打开 `GlobalPnSupport`、`PnEnabled`（不要再用 obsolete 的 `CanNmPnInfo`）。
9. **校验（Validate）**：重点看定时参数约束（Timeout>Cycle、Offset<Cycle、ReducedTime 区间）、PDU 引用、passive 与发送参数的互斥。
10. **生成代码**：检查 `CanNm_Cfg.h`（宏开关、通道数 `CANNM_NUMBER_OF_CANNM_CHANNELS`）、`CanNm_Cfg.c`（`CanNm_ChannelConfig[]` / `CanNm_PbChannelConfig[]` 每个字段）、`SchM_CanNm.h`（主函数声明）；本工程实际代码在 `src_CanNm/Source/` 下。
11. **集成**：`CanNm_MainFunction` 映射到 OS 任务/SchM 周期调度（周期 = `CanNmMainFunctionPeriod`）；`CanNm_Init` 放在 CanIf 初始化之后（由 EcuM 初始化序列/集成代码调用）；`CanNm_DeInit` 仅在 Bus-Sleep 时调用。

## 4. 常见配置坑

1. **`CanNmMainFunctionPeriod` 与任务周期不一致**：所有定时器（Timeout/Repeat/WaitBusSleep）误差按比例放大。
2. **`CanNmTimeoutTime ≤ CanNmMsgCycleTime`**：正常收帧也可能判超时 → 网络反复进 Prepare Bus-Sleep。
3. **`CanNmMsgCycleOffset ≥ CanNmMsgCycleTime`**：发送节奏错乱，DaVinci 校验报错。
4. **`CanNmRepeatMessageTime = 0`**：Repeat Message 瞬时结束，节点检测失效、上电网络不稳定。
5. **`CanNmBusLoadReductionActive=TRUE` 但全局 `Enabled=FALSE`**：校验报错；只开全局不开通道则"配置了没效果"。
6. **`CanNmMsgReducedTime` 越界**（<0.5×Cycle 或 ≥Cycle）：负载降低算法失效。
7. **`CanNmMsgTimeoutTime` 配了但没开 PN**：参数无效，属无效配置。
8. **Tx confirmation ID 与 CanIf 不一致**：`CanNm_TxConfirmation` 收到错误 PduId，报文状态机卡住。
9. **passive 模式还配置发送参数**（BusLoadReduction、ImmediateTxconf、MsgCycleTime 等）：标准要求互斥，校验失败。
10. **Com 用户数据长度与 NM PDU 剩余空间不匹配**：生成期报错（SWS_CanNm_00332），或运行期数据错位。
11. **PN 仍使用 `CanNmPnInfo`**：R21-11 已 obsolete，位置应由 Nm 的 PNC 位向量参数决定。
12. **唤醒后立即发包数为 0 却要求快速建网**：考虑 `CanNmImmediateNmTransmissions > 0` + `CanNmImmediateNmCycleTime`。

## 5. 最常改的 10 个参数速查

| 场景 | 参数 | 位置 |
|---|---|---|
| 调主函数周期 | `CanNmMainFunctionPeriod` | CanNmGlobalConfig |
| 被动监听节点 | `CanNmPassiveModeEnabled` | CanNmGlobalConfig |
| 开通信控制（0x28） | `CanNmComControlEnabled` | CanNmGlobalConfig |
| NM 报文周期 | `CanNmMsgCycleTime` | CanNmChannelConfig |
| 防上电突发 | `CanNmMsgCycleOffset` | CanNmChannelConfig |
| 收不到帧多久睡 | `CanNmTimeoutTime` | CanNmChannelConfig |
| 总线静默期 | `CanNmWaitBusSleepTime` | CanNmChannelConfig |
| Repeat Message 停留 | `CanNmRepeatMessageTime` | CanNmChannelConfig |
| 唤醒突发帧数 | `CanNmImmediateNmTransmissions` | CanNmChannelConfig |
| 降载 | `CanNmBusLoadReductionEnabled` + `CanNmBusLoadReductionActive` + `CanNmMsgReducedTime` | 全局 + 通道 |

## 6. 依据章节

- 参数定义：SWS_CanNm 10.2（ECUC_CanNm_00001、00017、00036、00038、00045 等）
- 参数约束：各参数的 "Scope / Dependency" 行
- 定时关系：SWS_CanNm 7.5.2、7.17
- 状态与发送行为：SWS_CanNm 7.2、7.7
- PN 重做说明：SWS_CanNm R21-11 变更历史 + 7.11

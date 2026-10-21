---
tags: [AUTOSAR, CanNm, 标准表格]
---

# CanNm 配置参数表（ECUC，R21-11）

> [!info] 导航
> 上级：[[CanNm]] ｜ 依赖：[[CanNm_DaVinci配置项]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11]]

> 适用版本：AUTOSAR CP R21-11　依据：SWS_CanNm 10.2（ECUC_CanNm_xxxxx）
> 最后更新：2026-10-21　关联：[[CanNm_DaVinci配置项]]、[[CanNm_AUTOSAR标准需求表_R21-11]]

## 1. 说明

- 本表按 ECUC 编号升序整理，中文说明 + 约束/备注；
- 标 **obsolete** 的参数在 R21-11 已废弃（PN 重构），新项目不要使用；
- 容器（container）与参数（parameter）分别标注。

## 2. 全局配置（CanNmGlobalConfig 及模块级）

| ECUC 号 | 名称 | 类型 | 中文说明 | 约束/备注 |
|---|---|---|---|---|
| ECUC_CanNm_00087 | CanNm（模块定义） | Module | CanNm 模块配置根 | 支持 post-build 变体 |
| ECUC_CanNm_00001 | CanNmGlobalConfig | Container | 全局配置容器 | 1 个 |
| ECUC_CanNm_00002 | CanNmDevErrorDetect | Param | 开发错误检测开关 | 默认 false |
| ECUC_CanNm_00003 | CanNmVersionInfoApi | Param | 是否提供版本查询 API | 默认 false |
| ECUC_CanNm_00004 | CanNmUserDataEnabled | Param | 是否支持 NM 用户数据（API 方式） | 无空间时必须 false |
| ECUC_CanNm_00006 | CanNmBusSynchronizationEnabled | Param | 是否支持总线同步（网关用） | 与 Nm 总线同步配置一致 |
| ECUC_CanNm_00009 | CanNmImmediateRestartEnabled | Param | Prepare Bus-Sleep 中被请求时立即发帧重启网络 | 不能与 passive 同时启用 |
| ECUC_CanNm_00010 | CanNmPassiveModeEnabled | Param | 被动模式：只收不发 | 全网一致；与发送参数互斥 |
| ECUC_CanNm_00011 | CanNmPduRxIndicationEnabled | Param | 收到 NM PDU 时是否回调 `Nm_PduRxIndication` | 与 Nm 配置一致 |
| ECUC_CanNm_00012 | CanNmStateChangeIndEnabled | Param | 是否回调状态变化通知 | 与 Nm 状态通知配置一致 |
| ECUC_CanNm_00013 | CanNmComControlEnabled | Param | 是否支持 0x28 通信控制 | 需要 Dcm/ComM 支持 |
| ECUC_CanNm_00032 | CanNmMainFunctionPeriod | Param | 主函数调用周期（秒） | 必须等于任务周期 |
| ECUC_CanNm_00040 | CanNmBusLoadReductionEnabled | Param | **预编译**降载支持开关 | passive/PN 全局支持时必须 false |
| ECUC_CanNm_00041 | CanNmImmediateTxconfEnabled | Param | 是否使用立即发送确认 | 与 passive 互斥 |
| ECUC_CanNm_00044 | CanNmComUserDataSupport | Param | 用户数据改从 Com 获取 | 与 `UserDataEnabled` 二选一 |
| ECUC_CanNm_00055 | CanNmRemoteSleepIndEnabled | Param | 是否启用远程睡眠检测 | 网关节点用 |
| ECUC_CanNm_00059 | CanNmPnResetTime | Param（obsolete） | PN 请求复位时间 | R21-11 已废弃 |
| ECUC_CanNm_00070 | CanNmPnEiraCalcEnabled | Param（obsolete） | 是否计算 EIRA | 已废弃 |
| ECUC_CanNm_00072 | CanNmPnEiraRxNSduRef | Ref（obsolete） | EIRA 接收 PDU 引用 | 已废弃 |
| ECUC_CanNm_00080 | CanNmCoordinatorSyncSupport | Param | 协调器同步支持 | 与 passive 互斥 |
| ECUC_CanNm_00086 | CanNmGlobalPnSupport | Param | 全局部分网络支持 | 为 true 时 passive 必须 false |
| ECUC_CanNm_00094 | CanNmDynamicPncToChannelMappingSupport | Param（draft） | 动态 PNC 映射支持 | 依赖 GlobalPnSupport |
| ECUC_CanNm_00096 | CanNmPnSyncShutdownErrorReactionEnabled | Param（draft） | 顶层协调器收到冲突 PN shutdown 时的错误反应 | 需同步关闭使能 |
| ECUC_CanNm_00098 | CanNmPnShutdownMessageRetransmissionDuration | Param（draft） | PN shutdown 报文重传时长（秒） | 为 MainFunctionPeriod 整数倍；≤ PnResetTime |

## 3. 通道配置（CanNmChannelConfig）

| ECUC 号 | 名称 | 类型 | 中文说明 | 约束/备注 |
|---|---|---|---|---|
| ECUC_CanNm_00017 | CanNmChannelConfig | Container | 通道级配置容器 | 每通道 1 个 |
| ECUC_CanNm_00018 | CanNmComMNetworkHandleRef | Ref | 引用 ComMChannel，取 ComMChannelId | 必配 |
| ECUC_CanNm_00020 | CanNmTimeoutTime | Param | NM-Timeout 时间（秒） | > MsgCycleTime；全网一致 |
| ECUC_CanNm_00021 | CanNmWaitBusSleepTime | Param | Prepare Bus-Sleep 静默期（秒） | 全网一致；足够清空 Tx 缓冲 |
| ECUC_CanNm_00022 | CanNmRepeatMessageTime | Param | Repeat Message 停留时间（秒） | 通常 n×MsgCycleTime；=0 表示瞬时 |
| ECUC_CanNm_00023 | CanNmRemoteSleepIndTime | Param | 远程睡眠判定时间（秒） | ≥ MsgCycleTime |
| ECUC_CanNm_00025 | CanNmPduNidPosition | Param | SNI 位置：Byte0/Byte1/off | 与 CBV 位置不冲突 |
| ECUC_CanNm_00026 | CanNmPduCbvPosition | Param | CBV 位置：Byte0/Byte1/off | 节点检测开启时不能 off |
| ECUC_CanNm_00028 | CanNmMsgCycleTime | Param | NM 报文周期（秒） | 全网一致；passive 时无效 |
| ECUC_CanNm_00029 | CanNmMsgCycleOffset | Param | 发送起始偏移（秒） | < MsgCycleTime |
| ECUC_CanNm_00030 | CanNmMsgTimeoutTime | Param | PN 发送超时监控时间（秒） | < MsgCycleTime；仅 PN、非 passive、非立即确认 |
| ECUC_CanNm_00031 | CanNmNodeId | Param | 本节点 SNI（0..255） | 全网唯一；post-build 可变 |
| ECUC_CanNm_00042 | CanNmBusLoadReductionActive | Param | 本通道是否启用降载 | 依赖全局 Enabled |
| ECUC_CanNm_00043 | CanNmMsgReducedTime | Param | 降载模式下的缩短周期（秒） | 0.5×Cycle ≤ 值 < Cycle |
| ECUC_CanNm_00056 | CanNmImmediateNmTransmissions | Param | 唤醒立即发送帧数（0..255） | 0=不发 |
| ECUC_CanNm_00057 | CanNmImmediateNmCycleTime | Param | 立即发送帧间隔（秒） | 仅帧数>0 时有效 |
| ECUC_CanNm_00066 | CanNmPnEnabled | Param | 本通道 PN 支持 | 依赖 GlobalPnSupport |
| ECUC_CanNm_00067 | CanNmPnEraCalcEnabled | Param（obsolete） | 是否计算 ERA | 已废弃 |
| ECUC_CanNm_00068 | CanNmAllNmMessagesKeepAwake | Param | PN 下不丢弃无 PNI 的帧 | 网关保持唤醒用 |
| ECUC_CanNm_00073 | CanNmPnHandleMultipleNetworkRequests | Param（draft） | 多 PNC 请求时再进 Repeat Message | 需立即发送帧数>0 |
| ECUC_CanNm_00074 | CanNmCarWakeUpRxEnabled | Param | 是否解析 CarWakeup 位 | 需要 CWU 时 true |
| ECUC_CanNm_00075 | CanNmCarWakeUpBitPosition | Param | CWU 位位置（0..7） | 依赖 CWU 接收使能 |
| ECUC_CanNm_00076 | CanNmCarWakeUpBytePosition | Param | CWU 字节位置（0..7） | ≥ 系统字节数 |
| ECUC_CanNm_00077 | CanNmCarWakeUpFilterEnabled | Param | 是否按源节点过滤 CWU | 依赖 CWU 接收使能 |
| ECUC_CanNm_00078 | CanNmCarWakeUpFilterNodeId | Param | CWU 过滤的源节点 ID（0..255） | 依赖过滤使能 |
| ECUC_CanNm_00079 | CanNmPnEraRxNSduRef | Ref（obsolete） | ERA 接收 PDU 引用 | 已废弃 |
| ECUC_CanNm_00084 | CanNmActiveWakeupBitEnabled | Param | 是否维护 CBV Active Wakeup 位 | passive 时无效 |
| ECUC_CanNm_00088 | CanNmNodeDetectionEnabled | Param | 节点检测开关 | 依赖 NodeIdEnabled；passive 时 false |
| ECUC_CanNm_00089 | CanNmRepeatMsgIndEnabled | Param | 收到 RMR 位时是否通知 Nm | 依赖节点检测/动态映射 |
| ECUC_CanNm_00090 | CanNmNodeIdEnabled | Param | 是否在 PDU 中携带 SNI | 节点检测/PN/CWU 过滤的基础 |
| ECUC_CanNm_00092 | CanNmStayInPbsEnabled | Param | 是否停留在 Prepare Bus-Sleep 不自动休眠 | true 时 WaitBusSleepTime 不再触发休眠 |
| ECUC_CanNm_00093 | CanNmDynamicPncToChannelMappingEnabled | Param（draft） | 本通道动态 PNC 映射 | 依赖全局支持 |
| ECUC_CanNm_00097 | CanNmSynchronizedPncShutdownEnabled | Param（draft） | 同步 PNC 关闭（协调器） | 依赖 PN + ERA |

## 4. PDU 与 PN 信息容器

| ECUC 号 | 名称 | 类型 | 中文说明 | 约束/备注 |
|---|---|---|---|---|
| ECUC_CanNm_00036 | CanNmTxPdu | Container | 发送 PDU 配置 | 0..1 |
| ECUC_CanNm_00037 | CanNmTxPduRef | Ref | 引用全局发送 PDU | 必配 |
| ECUC_CanNm_00038 | CanNmRxPdu | Container | 接收 PDU 配置 | 1..* |
| ECUC_CanNm_00039 | CanNmRxPduRef | Ref | 引用全局接收 PDU | 必配 |
| ECUC_CanNm_00045 | CanNmUserDataTxPdu | Container | Com 用户数据 I-PDU 配置 | 仅 ComUserDataSupport |
| ECUC_CanNm_00046 | CanNmTxUserDataPduRef | Ref | 引用 NM User Data I-PDU | 长度需匹配 |
| ECUC_CanNm_00047 | CanNmTxUserDataPduId | Param | 用户数据 I-PDU 句柄 ID | 0..65535 |
| ECUC_CanNm_00048 | CanNmTxConfirmationPduId | Param | 发送确认句柄 ID | 须与 CanIf 一致 |
| ECUC_CanNm_00054 | CanNmRxPduId | Param | 接收 PDU 句柄 ID | 须与 CanIf 一致 |
| ECUC_CanNm_00060 | CanNmPnInfoOffset | Param（obsolete） | PN 信息偏移 | 已废弃，改由 Nm 配置 PNC 位向量 |
| ECUC_CanNm_00061 | CanNmPnInfoLength | Param（obsolete） | PN 信息长度 | 已废弃 |
| ECUC_CanNm_00063 | CanNmPnFilterMaskByteIndex | Param（obsolete） | PN 过滤掩码字节索引 | 已废弃 |
| ECUC_CanNm_00064 | CanNmPnFilterMaskByteValue | Param（obsolete） | PN 过滤掩码值 | 已废弃 |
| ECUC_CanNm_00069 | CanNmPnFilterMaskByte | Container（obsolete） | PN 过滤掩码 | 已废弃 |
| ECUC_CanNm_00071 | CanNmPnInfo | Container（obsolete） | PN 信息配置 | 已废弃 |

## 6. 本项目实例值（NeuSAR 3.14 / AR 4.2.2 生成代码）

> 来源：`CanNm_Cfg.c` L166~295；代码中配置不以 ECUC 名称出现，而是 `CanNm_ChannelConfig[]` 结构体成员。

| 配置项/结构成员 | ch0 | ch1 | 说明 |
|---|---|---|---|
| `ChannelId` | 6 | 2 | ComM 通道 |
| `NodeId` | 39 | 35 | SNI |
| `MsgCycleTime` | 100 ms | 100 ms | NM 周期 |
| `TimeoutTime` | 380 ms | 380 ms | NM-Timeout |
| `WaitBusSleepTime` | 401 ms | 401 ms | 静默期 |
| `RepeatMessageTime` | 320 ms | 320 ms | Repeat Message |
| `ImmediateNmCycleTime` / `ImmediateNmTransmissions` | 4 ms / 10 | 4 ms / 10 | 唤醒突发 |
| `MsgTimeoutTime` | 16 ms | 16 ms | 发送超时 |
| `BusLoadReductionActive` | FALSE | FALSE | 降载未启用（全局 ON） |
| `MsgReducedTime` | 56 ms | 56 ms | 降载缩短周期（未生效） |
| `PduCbvPosition` / `PduNidPosition` | BYTE_1 / BYTE_0 | BYTE_1 / BYTE_0 | PDU 布局 |
| `TxPduId` / `TxPduRef` | 1 / 176 | 0 / 94 | CanIf 发送句柄 |
| `TxUserDataPduId` | 311 | 312 | Com 用户数据 |
| `CANNM_PASSIVE_MODE_ENABLED` | STD_OFF | — | 非被动 |
| `CANNM_PN_FEATURE_ENABLED` | STD_OFF | — | PN 关闭 |
| `CANNM_BUS_LOAD_REDUCTION_ENABLED` | STD_ON | — | 降载支持打开，但通道未启用 |

> 详细变量与读写宏见 [[CanNm_全局变量说明]]。

## 7. 统计

| 类别 | 数量 |
|---|---|
| ECUC 定义总数 | 72 |
| 有名称的参数/容器 | 64 |
| 其中 obsolete（PN 重构） | 12 |
| 全局参数 | 24 |
| 通道参数 | 40（含引用） |
| PDU/PN 容器与参数 | 15 |

> 参数作用与配置流程见 [[CanNm_DaVinci配置项]]；约束来源为 SWS 10.2 各参数的 Scope/Dependency 字段。

---
tags: [AUTOSAR, CanNm, 标准表格]
---
# CanNm AUTOSAR 标准需求表（R21-11）

> [!info] 导航
> 上级：[[CanNm]] ｜ 依赖：[[CanNm_配置参数表_R21-11]]、[[CanNm_需求追溯与覆盖度]] ｜ 依据：AUTOSAR_SWS_CANNetworkManagement.pdf（Document ID 13，117 页）

> 适用版本：AUTOSAR CP R21-11　最后更新：2026-10-21
> 说明：把 SWS 正文需求块整理为中文，**需求号保留官方原文**；按需求号百位分组（组内仍按需求号升序），组标题即 Obsidian 锚点。
> `SWS_CanNm_NA_xxxxx` 表示"不适用需求"（第 12 章），本表不展开。

## 1. 使用说明

- 需求号规则：`SWS_CanNm_xxxxx`（功能/接口需求）；`ECUC_CanNm_xxxxx`（配置参数，见 [[CanNm_配置参数表_R21-11]]）。
- 引用方式：`[[CanNm_AUTOSAR标准需求表_R21-11#SWS_CanNm_000xx|SWS_CanNm_00087]]`（跳到对应需求组）。
- 本 SWS 没有 `CONSTR` 配置约束条目。
- 需求与实现路径的对应：[[CanNm_调用逻辑总览]] 下 D1~D7；需求追溯：[[CanNm_需求追溯与覆盖度]]。

## 2. 分组索引

| 分组 | 需求号范围 | 数量 |
|---|---|---|
| [[#SWS_CanNm_000xx]] | 00005–00099 | 38 |
| [[#SWS_CanNm_001xx]] | 00100–00195 | 71 |
| [[#SWS_CanNm_002xx]] | 00202–00295 | 58 |
| [[#SWS_CanNm_003xx]] | 00305–00385 | 39 |
| [[#SWS_CanNm_004xx]] | 00401–00472 | 52 |
| [[#SWS_CanNm_005xx]] | 00500–00510 | 11 |
| [[#SWS_CanNm_910xx]] | 91001–91004 | 4 |

## 3. 需求表

### SWS_CanNm_000xx

| 需求号 | 章节 | 中文说明 |
|---|---|---|
| SWS_CanNm_00005 | 7.7.1 | 若不是由 NetworkRequest 进入 Repeat Message，或立即发送帧数为 0，则进入后先延迟 `CanNmMsgCycleOffset` 再发帧 |
| SWS_CanNm_00006 | 7.7.1 | 从 Ready Sleep 进入 Normal Operation 时立即开始发送 NM PDU |
| SWS_CanNm_00013 | 7.6 | 使用 `CanNmNodeId` 填充源节点标识（SNI），除非 `CanNmPduNidPosition` 配置为 off |
| SWS_CanNm_00014 | 7.13 | 收到 RMR 位时（`RepeatMsgIndEnabled`）每轮只调用一次 `Nm_RepeatMessageIndication`；PN 学习位置 `pnLearningBitSet` |
| SWS_CanNm_00023 | 7.4 | 初始化时停用总线负载降低 |
| SWS_CanNm_00025 | 7.4 | 初始化时把每个用户数据字节置为 0xFF |
| SWS_CanNm_00032 | 7.7.1 | 发送已启动、Message Cycle Timer 到期且无同步 PNC 关闭请求时，调用 `CanIf_Transmit` 发送 NM PDU |
| SWS_CanNm_00033 | 7.4 | 初始化后停止 Message Cycle Timer，从而停止 NM PDU 发送 |
| SWS_CanNm_00035 | 7.7.2 | `CanNm_RxIndication` 中把收到的 NM PDU 数据拷贝到内部缓冲 |
| SWS_CanNm_00037 | 7.9.4 | 收到 NM PDU 且 `CanNmPduRxIndicationEnabled=TRUE` 时回调 `Nm_PduRxIndication` |
| SWS_CanNm_00040 | 7.7.1 | Message Cycle Timer 到期后以 `CanNmMsgCycleTime` 重新装载 |
| SWS_CanNm_00045 | 7.6 | 定义 CBV：bit0 RMR、bit1 PNSR、bit3 Coordinator Sleep、bit4 ActiveWakeup、bit5 PNL、bit6 PNI，bit2/7 保留 |
| SWS_CanNm_00051 | 7.7.1 | 停止发送 NM PDU 时取消 Message Cycle Timer |
| SWS_CanNm_00052 | 7.8 | 总线负载降低机制由 `CanNmBusLoadReductionEnabled` 静态配置 |
| SWS_CanNm_00060 | 7.4 | `CanNm_Init` 通过配置指针选择当前配置集 |
| SWS_CanNm_00061 | 7.4 | PN 全局支持时，初始化时停止 NM 报文发送超时定时器 |
| SWS_CanNm_00064 | 7.12 | PN 场景下请求发送 NM PDU 时启动 Tx Timeout Timer（`CanNmMsgTimeoutTime`） |
| SWS_CanNm_00065 | 7.12 | PN 场景下收到 `CanNm_TxConfirmation` 时停止 Tx Timeout Timer |
| SWS_CanNm_00066 | 7.12 | 确认 E_NOT_OK 或 Tx Timeout 到期时调用 `Nm_TxTimeoutException` |
| SWS_CanNm_00069 | 7.8 | 降载使能、网络激活、发送能力使能且收到 NM PDU 时，以 `CanNmMsgReducedTime` 重装 Message Cycle Timer |
| SWS_CanNm_00071 | 7.7.1 | 立即发送确认机制由 `CanNmImmediateTxconfEnabled` 配置 |
| SWS_CanNm_00072 | 7.7.1 | NM PDU 发送能力由 `CanNmPassiveModeEnabled` 配置 |
| SWS_CanNm_00073 | 7.12 | passive 模式或立即确认开启时，不做发送错误处理 |
| SWS_CanNm_00074 | 7.6 | SNI 位置可由 `CanNmPduNidPosition` 配置为 Byte0/Byte1/off |
| SWS_CanNm_00075 | 7.6 | CBV 位置可由 `CanNmPduCbvPosition` 配置为 Byte0/Byte1/off |
| SWS_CanNm_00085 | 7.4 | 初始化时 CBV 置为 0x00 |
| SWS_CanNm_00086 | 7.13 | 用户数据使能但无可用字节时，在配置/编译期报错 |
| SWS_CanNm_00087 | 7.1 | 需要总线通信的节点应周期发送 NM PDU；否则不发送 |
| SWS_CanNm_00088 | 7.1 | 通信释放且总线静默 `TimeoutTime+WaitBusSleepTime` 后进入 Bus-Sleep（`StayInPbs` 未使能时） |
| SWS_CanNm_00089 | 7.1 | 状态机应包含 CanNm 算法所需的状态、迁移与触发条件（单节点视角） |
| SWS_CanNm_00091 | 7.2 | `CanNm_GetState` 返回当前 NM 状态与模式 |
| SWS_CanNm_00092 | 7.2 | 对外提供三个运行模式：Network Mode、Prepare Bus-Sleep、Bus-Sleep |
| SWS_CanNm_00093 | 7.2 | 运行模式变化通过回调通知上层 |
| SWS_CanNm_00094 | 7.2.1 | Network Mode 内部包含 Repeat Message、Normal Operation、Ready Sleep 三个状态 |
| SWS_CanNm_00096 | 7.2.1 | 进入 Network Mode 时启动 NM-Timeout 定时器 |
| SWS_CanNm_00097 | 7.2.1 | 进入 Network Mode 时回调 `Nm_NetworkMode` 通知上层 |
| SWS_CanNm_00098 | 7.2.1 | Network Mode 下收到 NM PDU（发送能力使能）时重启 NM-Timeout |
| SWS_CanNm_00099 | 7.2.1 | Network Mode 下发送确认 E_OK 时重启 NM-Timeout |

### SWS_CanNm_001xx

| 需求号 | 章节 | 中文说明 |
|---|---|---|
| SWS_CanNm_00100 | 7.2.1.1 | 进入 Repeat Message 时（重新）启动 NM PDU 发送，passive/通信禁用除外 |
| SWS_CanNm_00101 | 7.2.1.1 | Repeat Message 中 NM-Timeout 到期时重启 NM-Timeout |
| SWS_CanNm_00102 | 7.2.1.1 | Repeat Message 停留时间由 `CanNmRepeatMessageTime` 决定，到期后离开 |
| SWS_CanNm_00103 | 7.2.1.1 | 离开 Repeat Message 时若网络 requested，进入 Normal Operation |
| SWS_CanNm_00104 | 7.3 | `CanNm_NetworkRequest` 把网络状态改为 requested |
| SWS_CanNm_00105 | 7.3 | `CanNm_NetworkRelease` 把网络状态改为 released |
| SWS_CanNm_00106 | 7.2.1.1 | 离开 Repeat Message 时若网络 released，进入 Ready Sleep |
| SWS_CanNm_00107 | 7.2.1.1 | 节点检测使能时，离开 Repeat Message 清除 RMR 位 |
| SWS_CanNm_00108 | 7.2.1.3 | 进入 Ready Sleep 时停止发送 NM PDU |
| SWS_CanNm_00109 | 7.2.1.3 | Ready Sleep 中 NM-Timeout 到期时进入 Prepare Bus-Sleep |
| SWS_CanNm_00110 | 7.2.1.3 | Ready Sleep 中网络被请求时进入 Normal Operation |
| SWS_CanNm_00111 | 7.2.1.3 | 节点检测使能且 Ready Sleep 收到 RMR 位时进入 Repeat Message |
| SWS_CanNm_00112 | 7.2.1.3 | 节点检测使能且 Ready Sleep 调用 `CanNm_RepeatMessageRequest` 时进入 Repeat Message |
| SWS_CanNm_00113 | 7.2.1.3 | Ready Sleep 调用 `CanNm_RepeatMessageRequest` 时置 RMR 位 |
| SWS_CanNm_00114 | 7.2.2 | 进入 Prepare Bus-Sleep 时回调 `Nm_PrepareBusSleepMode` |
| SWS_CanNm_00115 | 7.2.2 | `StayInPbs` 未使能时，停留 `CanNmWaitBusSleepTime` 后离开 Prepare Bus-Sleep |
| SWS_CanNm_00116 | 7.2.1.2 | 从 Ready Sleep 进入 Normal Operation 时启动 NM PDU 发送 |
| SWS_CanNm_00117 | 7.2.1.2 | Normal Operation 中 NM-Timeout 到期时重启 NM-Timeout |
| SWS_CanNm_00118 | 7.2.1.2 | Normal Operation 中网络被释放时进入 Ready Sleep |
| SWS_CanNm_00119 | 7.2.1.2 | 节点检测使能且 Normal Operation 收到 RMR 位时进入 Repeat Message |
| SWS_CanNm_00120 | 7.2.1.2 | 节点检测使能且 Normal Operation 调用 `CanNm_RepeatMessageRequest` 时进入 Repeat Message |
| SWS_CanNm_00121 | 7.2.1.2 | Normal Operation 调用 `CanNm_RepeatMessageRequest` 时置 RMR 位 |
| SWS_CanNm_00122 | 7.2.2 | Prepare Bus-Sleep 中请求网络并进入 Network Mode 后，若 `ImmediateRestartEnabled` 则立即发一帧 |
| SWS_CanNm_00123 | 7.2.2 | Prepare Bus-Sleep 中网络被请求时进入 Network Mode（默认 Repeat Message） |
| SWS_CanNm_00124 | 7.2.2 | Prepare Bus-Sleep 中收到 NM PDU 时进入 Network Mode（默认 Repeat Message） |
| SWS_CanNm_00126 | 7.2.3 | 进入 Bus-Sleep 时回调 `Nm_BusSleepMode`（初始化时除外） |
| SWS_CanNm_00127 | 7.2.3 | Bus-Sleep 中收到 NM PDU 时回调 `Nm_NetworkStartIndication`（不自动进入 Network Mode） |
| SWS_CanNm_00128 | 7.2.3 | Bus-Sleep/Prepare Bus-Sleep 中调用 `CanNm_PassiveStartUp` 时进入 Network Mode（默认 Repeat Message） |
| SWS_CanNm_00129 | 7.2.3 | Bus-Sleep 中网络被请求时进入 Network Mode（默认 Repeat Message） |
| SWS_CanNm_00130 | 8.3.17 | 非 passive 时，`CanNm_RequestBusSynchronization` 触发发送单帧 NM PDU |
| SWS_CanNm_00132 | 8.3.11 | 节点标识使能时，`CanNm_GetNodeIdentifier` 返回最近接收帧的 SNI |
| SWS_CanNm_00133 | 8.3.12 | 节点标识使能时，`CanNm_GetLocalNodeIdentifier` 返回本节点配置的 SNI |
| SWS_CanNm_00137 | 7.2.1.1 | 在 Repeat/Prepare/Bus-Sleep 调用 `CanNm_RepeatMessageRequest` 时不执行并返回 E_NOT_OK |
| SWS_CanNm_00138 | 8.3.14 | `CanNm_GetPduData` 返回最近接收帧的完整数据（SNI/CBV/用户数据） |
| SWS_CanNm_00141 | 7.4 | `CanNm_Init` 成功后将 NM 状态置为 Bus-Sleep |
| SWS_CanNm_00143 | 7.4 | 初始化时默认把网络状态置为 released |
| SWS_CanNm_00144 | 7.4 | 初始化时默认进入 Bus-Sleep Mode |
| SWS_CanNm_00146 | 7.5.1 | CanNm 算法与处理器无关，不依赖特定硬件支持 |
| SWS_CanNm_00147 | 7.2.1 | 在 Network Mode 调用 `CanNm_PassiveStartUp` 时不执行并返回 E_NOT_OK |
| SWS_CanNm_00149 | 7.9.1 | 远程睡眠检测由 `CanNmRemoteSleepIndEnabled` 静态配置 |
| SWS_CanNm_00150 | 7.9.1 | Normal Operation 中 `CanNmRemoteSleepIndTime` 内收不到帧时回调 `Nm_RemoteSleepIndication` |
| SWS_CanNm_00151 | 7.9.1 | 已检测到远程睡眠后又收到 NM PDU 时回调 `Nm_RemoteSleepCancellation` |
| SWS_CanNm_00152 | 7.9.1 | 已检测到远程睡眠后进入 Repeat Message 时回调 `Nm_RemoteSleepCancellation` |
| SWS_CanNm_00153 | 8.3.18 | `CanNm_CheckRemoteSleepIndication` 返回远程睡眠当前是否已检测到 |
| SWS_CanNm_00154 | 7.9.1 | 在 Bus-Sleep/Prepare/Repeat Message 调用 `CanNm_CheckRemoteSleepIndication` 时不执行并返回 E_NOT_OK |
| SWS_CanNm_00156 | 7.8 | 进入 Repeat Message 时停用总线负载降低 |
| SWS_CanNm_00157 | 7.8 | 进入 Normal Operation 且降载使能时启用总线负载降低 |
| SWS_CanNm_00158 | 7.9.2 | NM 用户数据支持由 `CanNmUserDataEnabled` 静态配置 |
| SWS_CanNm_00159 | 7.9.2 | `CanNm_SetUserData` 设置后续发送 NM PDU 的用户数据 |
| SWS_CanNm_00160 | 7.9.2 | `CanNm_GetUserData` 返回最近接收 NM PDU 的用户数据 |
| SWS_CanNm_00161 | 7.9.3 | 被动模式由 `CanNmPassiveModeEnabled` 静态配置 |
| SWS_CanNm_00166 | 7.9.5 | 状态变化使能时通过 `Nm_StateChangeNotification` 通知上层 |
| SWS_CanNm_00170 | 7.9.6 | `CanNm_DisableCommunication` 关闭 NM PDU 发送能力 |
| SWS_CanNm_00172 | 8.3.6 | 非 Network Mode 调用 `CanNm_DisableCommunication` 时返回 E_NOT_OK |
| SWS_CanNm_00173 | 7.9.6 | 发送能力被禁用时停止 Message Cycle Timer，从而停止发送 |
| SWS_CanNm_00174 | 7.9.6 | 发送能力被禁用时停止 NM-Timeout 定时器 |
| SWS_CanNm_00175 | 7.9.6 | 发送能力被禁用时停止远程睡眠检测 |
| SWS_CanNm_00176 | 8.3.7 | 发送能力被禁用时，`CanNm_EnableCommunication` 恢复发送能力 |
| SWS_CanNm_00177 | 8.3.7 | 发送能力已使能时调用 `CanNm_EnableCommunication` 返回 E_NOT_OK |
| SWS_CanNm_00178 | 7.9.6 | 发送能力恢复后，最迟在下一个主函数开始发送 |
| SWS_CanNm_00179 | 7.9.6 | 发送能力恢复后重启 NM-Timeout 定时器 |
| SWS_CanNm_00180 | 7.9.6 | 发送能力恢复后重启远程睡眠检测（若使能） |
| SWS_CanNm_00181 | 7.9.6 | 发送能力禁用时 `CanNm_RequestBusSynchronization` 返回 E_NOT_OK |
| SWS_CanNm_00185 | 7.16.2 | 按需总线同步由 `CanNmBusSynchronizationEnabled` 静态配置 |
| SWS_CanNm_00187 | 8.3.17 | Bus-Sleep/Prepare Bus-Sleep 调用 `CanNm_RequestBusSynchronization` 时不执行并返回 E_NOT_OK |
| SWS_CanNm_00189 | 8 | API 不返回开发错误；出错时中止执行并返回 E_NOT_OK |
| SWS_CanNm_00190 | 8 | API 不返回生产错误；出错时中止执行并返回 E_NOT_OK |
| SWS_CanNm_00192 | 8 | 无效网络句柄时 API 不执行，必要时返回 E_NOT_OK |
| SWS_CanNm_00193 | 7.2.1.1 | Repeat Message 中 NM-Timeout 到期时向 DET 上报 `CANNM_E_NETWORK_TIMEOUT` |
| SWS_CanNm_00194 | 7.2.1.2 | Normal Operation 中 NM-Timeout 到期时向 DET 上报 `CANNM_E_NETWORK_TIMEOUT` |
| SWS_CanNm_00195 | 8 | 无效 PDU ID 时 API 不执行，必要时返回 E_NOT_OK |

### SWS_CanNm_002xx

| 需求号 | 章节 | 中文说明 |
|---|---|---|
| SWS_CanNm_00202 | 10.2.4 | `CanNmChannelConfig` 的参数应放入 `CanNm_ConfigType` 结构 |
| SWS_CanNm_00203 | 10.2.4 | 可运行时配置参数按 NM 集群（通道）分别配置 |
| SWS_CanNm_00206 | 7.2.1 | 每次启动/重启 NM-Timeout 前把定时器清零 |
| SWS_CanNm_00208 | 8.3.1 | 提供 `CanNm_Init` API：初始化模块并选择配置集 |
| SWS_CanNm_00211 | 8.3.3 | 提供 `CanNm_PassiveStartUp` API：被动启动 |
| SWS_CanNm_00213 | 8.3.4 | 提供 `CanNm_NetworkRequest` API：请求网络 |
| SWS_CanNm_00214 | 8.3.5 | 提供 `CanNm_NetworkRelease` API：释放网络 |
| SWS_CanNm_00215 | 8.3.6 | 提供 `CanNm_DisableCommunication` API：禁用 NM 发送 |
| SWS_CanNm_00216 | 8.3.7 | 提供 `CanNm_EnableCommunication` API：恢复 NM 发送 |
| SWS_CanNm_00217 | 8.3.8 | 提供 `CanNm_SetUserData` API：设置用户数据 |
| SWS_CanNm_00218 | 8.3.9 | 提供 `CanNm_GetUserData` API：读取用户数据 |
| SWS_CanNm_00219 | 8.3.11 | 提供 `CanNm_GetNodeIdentifier` API：读最近帧 SNI |
| SWS_CanNm_00220 | 8.3.12 | 提供 `CanNm_GetLocalNodeIdentifier` API：读本地 SNI |
| SWS_CanNm_00221 | 8.3.13 | 提供 `CanNm_RepeatMessageRequest` API：请求重复报文 |
| SWS_CanNm_00222 | 8.3.14 | 提供 `CanNm_GetPduData` API：读最近帧数据 |
| SWS_CanNm_00223 | 8.3.15 | 提供 `CanNm_GetState` API：读状态与模式 |
| SWS_CanNm_00224 | 8.3.16 | 提供 `CanNm_GetVersionInfo` API：读版本 |
| SWS_CanNm_00226 | 8.3.17 | 提供 `CanNm_RequestBusSynchronization` API：请求总线同步 |
| SWS_CanNm_00227 | 8.3.18 | 提供 `CanNm_CheckRemoteSleepIndication` API：查询远程睡眠 |
| SWS_CanNm_00228 | 8.4.1 | 提供 `CanNm_TxConfirmation` 回调：发送确认 |
| SWS_CanNm_00231 | 8.4.2 | 提供 `CanNm_RxIndication` 回调：接收指示 |
| SWS_CanNm_00234 | 8.5.1 | 提供 `CanNm_MainFunction` 调度函数 |
| SWS_CanNm_00237 | 7.7.1 | 提供周期发送模式（按周期发送 NM PDU） |
| SWS_CanNm_00238 | 7.7.1 | 可选提供带总线负载降低的周期发送模式 |
| SWS_CanNm_00244 | 8 | 无效参数调用时拒绝执行并通知 DET |
| SWS_CanNm_00245 | 8.1 | 规定需要导入的类型（NetworkHandleType、PduIdType 等） |
| SWS_CanNm_00246 | 7.5.2 | `CanNmTimeoutTime` 决定 NM-Timeout Time |
| SWS_CanNm_00247 | 7.5.2 | `CanNmRepeatMessageTime` 决定 Repeat Message Time |
| SWS_CanNm_00248 | 7.5.2 | `CanNmWaitBusSleepTime` 决定 Wait Bus-Sleep Time |
| SWS_CanNm_00249 | 7.5.2 | `CanNmRemoteSleepIndTime` 决定远程睡眠指示时间 |
| SWS_CanNm_00253 | 8.3.1 | `CanNm_Init` 必须在 CanIf 初始化之后调用 |
| SWS_CanNm_00254 | 8.3.3 | `CanNm_PassiveStartUp` 要求模块已初始化 |
| SWS_CanNm_00255 | 8.3.4 | `CanNm_NetworkRequest` 把网络状态改为 requested |
| SWS_CanNm_00256 | 8.3.4 | `CanNm_NetworkRequest` 要求模块已初始化 |
| SWS_CanNm_00257 | 8.3.4 | `CanNm_NetworkRequest` 仅在非 passive 时提供 |
| SWS_CanNm_00259 | 8.3.5 | `CanNm_NetworkRelease` 要求模块已初始化 |
| SWS_CanNm_00260 | 8.3.5 | `CanNm_NetworkRelease` 仅在非 passive 时提供 |
| SWS_CanNm_00261 | 8.3.6 | `CanNm_DisableCommunication` 要求模块已初始化 |
| SWS_CanNm_00262 | 8.3.6 | `CanNm_DisableCommunication` 仅在 `CanNmComControlEnabled=TRUE` 时提供 |
| SWS_CanNm_00263 | 8.3.7 | `CanNm_EnableCommunication` 要求模块已初始化 |
| SWS_CanNm_00264 | 8.3.7 | `CanNm_EnableCommunication` 仅在 `CanNmComControlEnabled=TRUE` 时提供 |
| SWS_CanNm_00265 | 8.3.8 | `CanNm_SetUserData` 要求模块已初始化 |
| SWS_CanNm_00266 | 8.3.8 | `CanNm_SetUserData` 仅在用户数据使能且非 passive 时提供 |
| SWS_CanNm_00267 | 8.3.9 | `CanNm_GetUserData` 要求模块已初始化 |
| SWS_CanNm_00268 | 8.3.9 | `CanNm_GetUserData` 仅在用户数据使能时提供 |
| SWS_CanNm_00269 | 8.3.11 | `CanNm_GetNodeIdentifier` 要求模块已初始化 |
| SWS_CanNm_00271 | 8.3.12 | `CanNm_GetLocalNodeIdentifier` 要求模块已初始化 |
| SWS_CanNm_00273 | 8.3.13 | `CanNm_RepeatMessageRequest` 要求模块已初始化 |
| SWS_CanNm_00275 | 8.3.14 | `CanNm_GetPduData` 要求模块已初始化 |
| SWS_CanNm_00277 | 8.3.15 | `CanNm_GetState` 要求模块已初始化 |
| SWS_CanNm_00279 | 8.3.17 | `CanNm_RequestBusSynchronization` 要求模块已初始化 |
| SWS_CanNm_00280 | 8.3.17 | `CanNm_RequestBusSynchronization` 仅在总线同步使能且非 passive 时提供 |
| SWS_CanNm_00281 | 8.3.18 | `CanNm_CheckRemoteSleepIndication` 要求模块已初始化 |
| SWS_CanNm_00282 | 8.3.18 | `CanNm_CheckRemoteSleepIndication` 仅在远程睡眠检测使能时提供 |
| SWS_CanNm_00283 | 8.4.1 | `CanNm_TxConfirmation` 可在中断或任务上下文调用，不同 PDU 可重入 |
| SWS_CanNm_00284 | 8.4.1 | `CanNm_TxConfirmation` 仅在非 passive 且非立即确认时提供 |
| SWS_CanNm_00285 | 8.4.2 | `CanNm_RxIndication` 的缓冲区仅在本回调内有效，回调返回前不得被 CanIf 改写 |
| SWS_CanNm_00295 | 8.3.7 | 非 Network Mode 调用 `CanNm_EnableCommunication` 返回 E_NOT_OK |

### SWS_CanNm_003xx

| 需求号 | 章节 | 中文说明 |
|---|---|---|
| SWS_CanNm_00305 | 5.1.2 | 必须包含 `ComStack_Types.h`（间接包含 Std/Platform/Compiler 类型） |
| SWS_CanNm_00307 | 5.1.2 | 必须包含 `Nm.h` 用于回调 Nm 接口 |
| SWS_CanNm_00308 | 5.1.2 | 必须包含 `Det.h` 用于 DET 接口 |
| SWS_CanNm_00309 | 5.1.2 | 必须包含 `NmStack_Types.h` 用于 NM 公共类型 |
| SWS_CanNm_00312 | 5.1.2 | 必须包含 `CanIf.h` 用于 CanIf 接口 |
| SWS_CanNm_00314 | 7.2.1 | 从 Bus-Sleep 进入 Network Mode 时默认进入 Repeat Message |
| SWS_CanNm_00315 | 7.2.1 | 从 Prepare Bus-Sleep 进入 Network Mode 时默认进入 Repeat Message |
| SWS_CanNm_00316 | 7.14.1 | 定义开发错误码（UNINIT/INVALID_CHANNEL/参数错误等） |
| SWS_CanNm_00317 | 7.14.2 | 定义运行时错误码（NET_START_IND、NETWORK_TIMEOUT 等） |
| SWS_CanNm_00324 | 8.6.1 | 强制外部接口清单（Det/Nm 回调等） |
| SWS_CanNm_00325 | 8.6.2 | 可选外部接口清单（CanIf_Transmit、CanSM_TxTimeoutException、PduR 等） |
| SWS_CanNm_00326 | 5.1.2 | Com 用户数据使能时必须包含 `PduR_CanNm.h` |
| SWS_CanNm_00327 | 7.9.2.1 | Com 用户数据使能时 `CanNm_SetUserData` 不可用 |
| SWS_CanNm_00328 | 7.9.2.1 | Com 用户数据且非触发式发送时，发送前用 `PduR_CanNmTriggerTransmit` 收集数据 |
| SWS_CanNm_00329 | 7.9.2.1 | Com 用户数据时把确认结果转发 `PduR_CanNmTxConfirmation` |
| SWS_CanNm_00330 | 8.3.10 | Com 用户数据或 PN 全局支持时需提供 `CanNm_Transmit` API |
| SWS_CanNm_00331 | 8.3.10 | 提供 `CanNm_Transmit` API：请求附加发送 |
| SWS_CanNm_00332 | 7.9.2.1 | Com 用户数据字节数与 I-PDU 长度不匹配时在生成期报错 |
| SWS_CanNm_00333 | 8.3.10 | Repeat/Normal 下调用 `CanNm_Transmit` 时请求一次附加发送 |
| SWS_CanNm_00334 | 7.7.1 | 主动唤醒进 Repeat Message 且立即发送帧数 >0 时，首帧尽快发、随后按 `ImmediateNmCycleTime` 连发 |
| SWS_CanNm_00335 | 7.7.1 | 立即发送需确保 N 帧成功；请求失败则下个主函数重试，之后回到 `MsgCycleTime` |
| SWS_CanNm_00336 | 7.2.3 | Bus-Sleep 收到 NM PDU 时向 DET 上报 `CANNM_E_NET_START_IND` |
| SWS_CanNm_00338 | 8.3.19 | 提供 `CanNm_SetSleepReadyBit` API：设置协调器睡眠位 |
| SWS_CanNm_00339 | 8.3.19 | `CanNm_SetSleepReadyBit` 要求模块已初始化 |
| SWS_CanNm_00340 | 8.3.19 | `CanNm_SetSleepReadyBit` 仅在协调器同步支持使能时提供 |
| SWS_CanNm_00341 | 7.9.7 | 收到协调器睡眠位置 1 时回调 `Nm_CoordReadyToSleepIndication` |
| SWS_CanNm_00342 | 7.9.7 | `CanNm_SetSleepReadyBit` 设置 CBV 位并触发单帧 NM PDU |
| SWS_CanNm_00344 | 8.4.3 | 提供 `CanNm_ConfirmPnAvailability` 回调：使能 PN 过滤（CanSM 调用） |
| SWS_CanNm_00345 | 8.4.3 | `CanNm_ConfirmPnAvailability` 要求模块已初始化 |
| SWS_CanNm_00346 | 8.4.3 | `CanNm_ConfirmPnAvailability` 仅在 PN 全局支持时提供 |
| SWS_CanNm_00348 | 7.9.7 | 协调器睡眠位清 0 时回调 `Nm_CoordReadyToSleepCancellation` |
| SWS_CanNm_00350 | 8.4.4 | Com 用户数据时通过 `PduR_CanNmTriggerTransmit` 收集并组合用户数据（触发式发送路径） |
| SWS_CanNm_00351 | 8.4.4 | `CanNm_TriggerTransmit` 按 TxPduId 拷贝 NM PDU 数据 |
| SWS_CanNm_00352 | 8.3.2 | 非全部网络 Bus-Sleep 时调用 `CanNm_DeInit` 向 DET 报 `CANNM_E_NOT_IN_BUS_SLEEP` |
| SWS_CanNm_00380 | 7.2.1 | 动态 PNC 映射通道调用 `CanNm_PnLearningRequest` 时置 RMR+PNL 位并进/重启 Repeat Message |
| SWS_CanNm_00381 | 7.2.1 | 收到 PNL 与 RMR 均为 1 时置 PNL 位并进/重启 Repeat Message |
| SWS_CanNm_00382 | 7.2.1.1 | 动态 PNC 映射时离开 Repeat Message 清除 PNL 位 |
| SWS_CanNm_00384 | 8.3.20 | 在 Prepare/Bus-Sleep 调用 `CanNm_PnLearningRequest` 时不执行并返回 E_NOT_OK |
| SWS_CanNm_00385 | 8.3.20 | `CanNm_PnLearningRequest` 仅在动态 PNC 映射支持时提供 |

### SWS_CanNm_004xx

| 需求号 | 章节 | 中文说明 |
|---|---|---|
| SWS_CanNm_00401 | 7.6 | 主动唤醒且 ActiveWakeup 使能时置 CBV Active Wakeup 位 |
| SWS_CanNm_00402 | 7.6 | 离开 Network Mode 时清除 CBV Active Wakeup 位 |
| SWS_CanNm_00403 | 7.11.4 | 初始化时对 `PnEnabled` 通道关闭 NM-PDU 过滤算法 |
| SWS_CanNm_00404 | 7.11.4 | CanSM 调用 `CanNm_ConfirmPnAvailability` 后使能该通道 PN 过滤算法 |
| SWS_CanNm_00405 | 7.10 | Car Wakeup 位位置由 `CanNmCarWakeUpBytePosition/BitPosition` 配置 |
| SWS_CanNm_00406 | 7.10.1 | CWU 位=1、接收使能且未过滤时回调 `Nm_CarWakeUpIndication` 并走标准接收处理 |
| SWS_CanNm_00407 | 7.10.1 | 在 CarWakeUp 回调上下文中，`CanNm_GetPduData` 返回触发该回调的帧数据 |
| SWS_CanNm_00408 | 7.10.1 | CWU 过滤使能时，仅当源节点 ID 等于过滤节点 ID 才上报 CWU |
| SWS_CanNm_00409 | 7.11.1 | `PnEnabled=FALSE` 时不丢弃 NM 帧，PN 扩展关闭 |
| SWS_CanNm_00410 | 7.11.1 | PN 使能、PNI=0 且 `AllNmMessagesKeepAwake=TRUE` 时不丢弃该帧 |
| SWS_CanNm_00411 | 7.11.1 | PN 使能、PNI=0 且 `AllNmMessagesKeepAwake=FALSE` 时忽略该帧 |
| SWS_CanNm_00412 | 7.11.1 | `PnEnabled` 且收到 PNI=1 时按第 7.11 章处理 PNC 信息 |
| SWS_CanNm_00413 | 7.11.2 | PN 使能时发送的 PNI 位为 1 |
| SWS_CanNm_00414 | 7.11.2 | PN 未使能时发送的 PNI 位恒为 0 |
| SWS_CanNm_00415 | 7.11.4 | NM-PDU 过滤算法用 `PnInfoOffset`/`PnInfoLength` 评估 PN 信息范围 |
| SWS_CanNm_00416 | 7.11.4 | PN 信息范围每 bit 对应一个 PNC，1=请求，0=无请求 |
| SWS_CanNm_00417 | 7.11.4 | 用 PN 过滤掩码按位与判断是否存在相关 PNC 请求 |
| SWS_CanNm_00419 | 7.11.4 | 有相关 PNC 请求时不丢弃该帧 |
| SWS_CanNm_00420 | 7.11.4 | 无相关 PNC 请求且 `AllNmMessagesKeepAwake=FALSE` 时丢弃该帧 |
| SWS_CanNm_00421 | 7.11.4 | 无相关 PNC 请求且 `AllNmMessagesKeepAwake=TRUE` 时不丢弃该帧 |
| SWS_CanNm_00424 | 7.11.5 | EIRA 计算使能时，跨通道保存内部+外部请求的 PNC 状态 |
| SWS_CanNm_00426 | 7.11.5 | 收到帧且 PNSR=0 时更新 EIRA 中对应 PNC 为 requested |
| SWS_CanNm_00427 | 7.11.5 | 发送帧时把 EIRA 中 requested 的 PNC 写入待发数据 |
| SWS_CanNm_00428 | 7.11.5 | EIRA 计算时监控每个 PNC 是否仍被请求 |
| SWS_CanNm_00429 | 7.11.5 | PNC 被收/发请求时重启监控计时 |
| SWS_CanNm_00431 | 7.11.5 | PNC 在 `PnResetTime` 内未被再次请求则置为未请求 |
| SWS_CanNm_00432 | 7.11.5 | EIRA 中 PNC 状态变化时通知上层 |
| SWS_CanNm_00435 | 7.11.6 | ERA 计算时按通道保存外部请求 PNC 状态，初始化清零 |
| SWS_CanNm_00437 | 7.11.6 | 收到帧、PNSR=0 时更新 ERA 对应 PNC |
| SWS_CanNm_00438 | 7.11.6 | ERA 计算时监控每个 PNC 是否仍被外部请求 |
| SWS_CanNm_00439 | 7.11.6 | PNC 被请求时重启 ERA 监控计时 |
| SWS_CanNm_00442 | 7.11.6 | PNC 在 `PnResetTime` 内未被再次请求则置为未请求 |
| SWS_CanNm_00443 | 7.11.6 | ERA 中 PNC 状态变化时通知上层 |
| SWS_CanNm_00444 | 7.11.7 | `PnHandleMultipleNetworkRequests` 时，NetworkRequest 在 Network Mode 下进入/重启 Repeat Message |
| SWS_CanNm_00445 | 7.11.6 | EIRA 与 ERA 同时启用时两者的 PN 状态需分开存储 |
| SWS_CanNm_00446 | 7.12 | PN 发送超时到期时调用 `CanSM_TxTimeoutException` |
| SWS_CanNm_00447 | 8.2.1 | `CanNm_ConfigType` 结构至少包含所有 post-build 可配置参数 |
| SWS_CanNm_00450 | 7.9.2.1 | Com 用户数据 `PduR_CanNmTriggerTransmit` 失败时沿用上次发送值 |
| SWS_CanNm_00454 | 7.7.1 | `PnHandleMultipleNetworkRequests` 时 NetworkRequest 触发进 Repeat Message 并用 `ImmediateNmCycleTime` 发送 |
| SWS_CanNm_00460 | 7.7.1 | 同步 PNC 关闭请求待发时，周期发送推迟到下一个主函数 |
| SWS_CanNm_00461 | 7.11.1 | 收到 PNI=1、PNSR=1 的帧时，按 ComMChannel 配置发起同步关闭流程 |
| SWS_CanNm_00462 | 7.11.2 | `CanNm_RequestSynchronizedPncShutdown` 按通道存储待关闭 PNC |
| SWS_CanNm_00463 | 7.11.2 | 有同步关闭请求且无未确认发送时，下一主函数发 PN shutdown 报文（PNSR=1、PNC 位置位） |
| SWS_CanNm_00464 | 7.11.2 | 确认 E_OK 后清除对应待关闭 PNC 并取消重传计时 |
| SWS_CanNm_00465 | 7.11.2 | 确认失败或发送被拒且配置了重传时长时，下个主函数重传 |
| SWS_CanNm_00466 | 7.11.6 | 收到 PNSR=1 的帧时把对应通道 ERA PDU 相应位清 0 |
| SWS_CanNm_00467 | 8.3.21 | 同步 PNC 关闭使能时须提供 `CanNm_RequestSynchronizedPncShutdown` API |
| SWS_CanNm_00468 | 7.11.2 | 首次请求 PN shutdown 发送时按配置启动重传计时 |
| SWS_CanNm_00469 | 8.4.4 | 有同步关闭请求时，发送的报文需包含 PNSR 位与待关闭 PNC 位 |
| SWS_CanNm_00470 | 7.11.2 | 待关闭 PNC 若被重新请求（内部/外部），从待关闭列表移除 |
| SWS_CanNm_00471 | 7.11.2 | 未配置重传时长且发送失败时，清除待关闭请求并上报 DET 运行时错误 |
| SWS_CanNm_00472 | 7.11.2 | 重传计时到期时清除待关闭请求并上报 DET 运行时错误 |

### SWS_CanNm_005xx

| 需求号 | 章节 | 中文说明 |
|---|---|---|
| SWS_CanNm_00500 | 7.4 | 初始化且 `PnEnabled` 时 PNC 位向量各字节清 0 |
| SWS_CanNm_00501 | 7.6 | 除系统字节与 PNC 位向量外的剩余字节用于用户数据 |
| SWS_CanNm_00502 | 7.11.1 | `PnEnabled`、PNI=1、PNSR=0 时从接收帧提取 PNC 位向量 |
| SWS_CanNm_00503 | 7.11.1 | PnEnabled 且已调用 `Nm_PncBitVectorRxIndication` 后，只有满足相关 PNC 条件才继续处理 |
| SWS_CanNm_00504 | 7.11.1 | 同步关闭使能、PNI=1、PNSR=1 时提取 PNC 位向量（PN shutdown 报文） |
| SWS_CanNm_00505 | 7.11.2 | PnEnabled、非触发式发送、无待发同步关闭时，发送前依次取 PNC 位向量、拷贝 PNC、取用户数据、`CanIf_Transmit` |
| SWS_CanNm_00506 | 7.11.2 | 有同步关闭请求且无未确认发送时，下一主函数发送 PN shutdown 报文（PNSR=1） |
| SWS_CanNm_00507 | 8 | 传入空指针时 API 不执行，必要时返回 E_NOT_OK；DET 报参数错误 |
| SWS_CanNm_00508 | 8.4.4 | 触发式发送时按 PNI/同步关闭状态决定数据填充规则 |
| SWS_CanNm_00509 | 8.4.4 | 同步关闭请求待发时，触发式发送需附加 PNSR/PNC 数据 |
| SWS_CanNm_00510 | 8.4.4 | `TriggerTransmit` 且 Com 用户数据时用 `PduR_CanNmTriggerTransmit` 收集数据 |

### SWS_CanNm_910xx

| 需求号 | 章节 | 中文说明 |
|---|---|---|
| SWS_CanNm_91001 | 8.4.4 | 提供 `CanNm_TriggerTransmit` API（触发式发送） |
| SWS_CanNm_91002 | 8.3.2 | 提供 `CanNm_DeInit` API：反初始化 |
| SWS_CanNm_91003 | 8.3.21 | 提供 `CanNm_RequestSynchronizedPncShutdown` API（draft） |
| SWS_CanNm_91004 | 8.3.20 | 提供 `CanNm_PnLearningRequest` API（draft） |


## 4. 覆盖度统计

| 指标 | 数值 | 说明 |
|---|---|---|
| 需求块总数 | 273 | 正文 + 补充（DRAFT/OBSOLETE）全部去重 |
| 分组数 | 7 | 按需求号百位 |
| 配置约束（CONSTR） | 0 | 本 SWS 无 |
| 配置参数（ECUC） | 72 | 见 [[CanNm_配置参数表_R21-11]] |
| 需求追溯条目（RS_Nm） | 45 | 见 [[CanNm_需求追溯与覆盖度]] |
| 覆盖 | 273 / 273 | 全部整理 |

> 统计口径：SWS 正文以 `[SWS_CanNm_xxxxx]` 开头、后接 `⌈` 的需求块（含 `{DRAFT}`/`{OBSOLETE}` 标记行）；第 6 章追溯表中仅被引用的 ID 不计入本表。

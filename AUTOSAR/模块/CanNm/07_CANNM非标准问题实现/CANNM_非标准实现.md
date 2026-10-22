---
tags: [AUTOSAR, CanNm, 非标准实现, 供应商扩展]
---
# CANNM 非标准问题实现（vendor / 项目扩展清单）

> [!info] 导航
> 上级：[[CanNm]]

> 适用实现：NeuSAR CanNm 3.14.0 / AUTOSAR 4.2.2，2 通道（ch0 ChannelId 6 / NodeId 39，ch1 ChannelId 2 / NodeId 35）
> 代码：`AUTOSAR/AUTOSAT使用NEUSAR生成的代码/002_BSW/Bsw_Src/Autosar_Src/src_CanNm/Source/`
> 最后更新：2026-10-22

> 本页只记录**与 AUTOSAR SWS 不一致、或 SWS 没有的 vendor/项目实现**，用于评审、移植和排查。
> 历史问题仍记录在 `CanNm_问题排查记录.md`；时间类问题见 `06_问题排查/CanNm_时间类问题排查.md`。

## 1. 判定口径

| 类型 | 含义 | 本页处理 |
|---|---|---|
| SWS 标准行为 | 标准有明确章节/需求号 | 不收录，见 03/05 文档 |
| Vendor 扩展 | SWS 无此特性，供应商用宏/函数扩展 | 收录（NS-001 起） |
| 项目 Hook | 项目代码插入到标准流程（填充/使能/测试） | 收录 |
| 实现差异 | 标准允许，但实现方式与文档描述不同（如配置指针、tick） | 收录为“差异”类 |
| 配置裁剪 | 特性宏关闭导致代码不生效 | 收录为“配置快照”提醒 |

## 2. 非标准实现总表

| 编号 | 名称 | 开关/入口 | 代码位置 | 影响级别 | 标准对应 |
|---|---|---|---|---|---|
| NS-001 | RMR 触发快发 | `CANNM_RMR_FAST_TRANSITION` | `CanNm_TransitionToRepeatMessage` L1350~1415 | 高（总线负载/唤醒时序） | SWS 无“RMR 快发” |
| NS-002 | RSS→RMS/NOS 的 AWB 更新 | `CANNM_AWB_RSS_UPDATE_SUPPORTED` | `CanNm_StateTransition` L1936、`CanNm_TransitionToNetworkMode` L1469 | 高（唤醒位语义） | SWS 无此更新逻辑 |
| NS-003 | 同睡同醒（跨通道传播） | `CANNM_BOTH_WAKEUP_AND_SLEEP_SUPPORTED` | `CanNm_RxIndication` L3454、L3500 | 高（误唤醒/多通道） | SWS 按通道独立 |
| NS-004 | 用户层 NM 发送使能 | `CANNM_NM_USER_ENABLE_SUPPORTED` + `CanNm_GetTxUserNMEnable()` | `CanNm_TriggerTransmission` L1675~1686 | 高（“发送成功”但无帧） | SWS 无此 API |
| NS-005 | 发送前用户数据填充 Hook | `Can_NM_UserData_Fill()` | `CanNm_TriggerTransmission` L1673 | 中（数据内容/阻塞） | SWS 无此 Hook |
| NS-006 | 主函数测试钩子 | `VCU_Test_Code_YXP` | `CanNm_MainFunction` L3614、L3626 | 中（时序/量产风险） | SWS 无 |
| NS-007 | 收到 NM 帧查询 API | `CanNm_GetMessageReceive()` | L3593；标志 L347/L3521 | 中（非标准 API） | SWS 无 |
| NS-008 | `CanNm_Init` 忽略 ConfigPtr | `CanNm_ConfigType` 空/未用 | `CanNm_Init` L2035 | 中（移植/多配置） | SWS 允许 link-time，但接口参数未用 |
| NS-009 | 时间参数为 tick，注释写 `[ms]` | `CanNm_Cfg.h` L351~384 | 配置结构体 | 中（时间换算） | SWS 参数单位是秒；实现为 tick |
| NS-010 | PN/CWU/远程睡眠代码存在但关闭 | `CANNM_PN_FEATURE_ENABLED` 等 | `CanNm_Cfg.h` L72~106 | 低（误排查） | 属 4.2.2/配置裁剪差异 |
| NS-011 | 项目通道/PDU 固定映射 | `CANNM_NUMBER_OF_CANNM_CHANNELS=2` | `CanNm_Cfg.c` L166~313 | 中（通道串扰） | 项目配置，不是 SWS 行为 |

## 3. 逐项说明

### NS-001 RMR 触发快发（`CANNM_RMR_FAST_TRANSITION`，ON）

**代码行为**（`TransitionToRepeatMessage`）：

```c
#if( CANNM_RMR_FAST_TRANSITION == STD_ON )
    /* 记录本次进入 Repeat 是否由收到 RMR 位触发 */
    boolean immediateTxRequested = FALSE;
#endif
...
if( TRUE == CanNm_IsRepeatMsgBitIndFlag(channel) )
{
    #if( CANNM_RMR_FAST_TRANSITION == STD_ON )
        immediateTxRequested = TRUE;
    #endif
    CanNm_SetRepeatMsgBitIndFlag(channel, FALSE);
    ...
}

if( (CANNM_ZERO < CanNm_GetImmediateNmTransmissions(channel)) &&
    ( (CANNM_ACTIVE_RESTART == CanNm_GetNetworkRestartFlag(channel)) ||
      (TRUE == immediateTxRequested) ) )        /* 关键：RMR 也算快发条件 */
{
    CanNm_SetMsgTimer(channel, CANNM_ONE);
    CanNm_SetImmediateNmMsgCount(channel, ImmediateNmTransmissions - 1);
}
```

**与标准差异**：SWS 的立即发送主要用于主动唤醒（Active Wakeup）；本实现把“收到 RMR”也当成快发触发条件。

**风险**：

- 任一节点发 RMR，本 ECU 会突发 10 帧（`ImmediateNmTransmissions=10`，间隔 4 tick），总线负载和唤醒时序会与标准实现不同；
- 与降载/多通道组合时可能出现额外突发；
- 测试用例必须覆盖“收到 RMR → 是否快发”的预期，不要只按 SWS 判断。

**建议**：量产若不需要，确认 `CANNM_RMR_FAST_TRANSITION=STD_OFF` 后回归 RMR/唤醒/总线负载。

### NS-002 RSS→RMS/NOS 的 AWB 更新（`CANNM_AWB_RSS_UPDATE_SUPPORTED`，ON）

**代码行为**：

- `CanNm_StateTransition` 的 `NORMAL_OPERATION` 分支：若从 `READY_SLEEP` 恢复且 `ActiveWakeupBitEnabled`，按 `CommState` 置/清 AWB；
- `TransitionToNetworkMode` 的 `lastNmState == READY_SLEEP` 分支：主动请求则置 AWB，否则清 AWB。

```c
#if(( CANNM_AWB_RSS_UPDATE_SUPPORTED == STD_ON ) && ( CANNM_ACTIVE_WUP_BIT_FEATURE_ENABLED == STD_ON ))
    if( NM_STATE_READY_SLEEP == lastNmState )
    {
        if( COMM_NORMAL_OPERATION == CanNm_GetCommState(channel) )
            CanNm_SetTxMessageData(channel, CBVIdx, ... | CANNM_ACT_WU_BIT_MASK);  /* 主动：置位 */
        else
            CanNm_SetTxMessageData(channel, CBVIdx, ... & CANNM_ACT_WU_BIT_INV_MASK); /* 被动：清零 */
    }
#endif
```

**与标准差异**：SWS 只规定 AWB 位由主动唤醒配置/行为决定；本实现在“RSS 重新进入 RMS/NOS”时动态改写 AWB。

**风险**：AWB 与真实唤醒源不一致；其他 ECU 可能据此误判主动/被动唤醒。测试需覆盖主动唤醒、被动唤醒、RSS 重入三种路径。

### NS-003 同睡同醒（`CANNM_BOTH_WAKEUP_AND_SLEEP_SUPPORTED`，ON）

**代码行为**（`CanNm_RxIndication`）：

```c
#if ( CANNM_BOTH_WAKEUP_AND_SLEEP_SUPPORTED == STD_ON )
    /* 收到一帧后，把所有处于 Normal/Ready 的通道都置 RMR 标志 */
    for(uint8 channel_LO = 0; channel_LO < CanNm_GetSizeOfChannelConfig(); channel_LO++)
    {
        if( (NM_STATE_NORMAL_OPERATION == CanNm_GetNmState(channel_LO)) ||
            (NM_STATE_READY_SLEEP == CanNm_GetNmState(channel_LO)) )
        {
            if( TRUE == CanNm_IsNodeDetectionEnabled(channel_LO) )
            {
                if( TRUE != CanNm_IsRepeatMsgBitIndFlag(channel_LO) )
                    CanNm_SetRepeatMsgBitIndFlag(channel_LO, controlBitVector & CANNM_REPEAT_MSG_BIT_MASK);
            }
        }
    }
#endif
...
#if ( CANNM_BOTH_WAKEUP_AND_SLEEP_SUPPORTED == STD_ON )
    for(uint8 channel_LO = 0; channel_LO < CanNm_GetSizeOfChannelConfig(); channel_LO++)
        CanNm_SetMsgIndicationFlag(channel_LO, TRUE);   /* 所有通道都置接收标志 */
#else
    CanNm_SetMsgIndicationFlag(channel, TRUE);
#endif
```

**与标准差异**：SWS 的 NM 状态/接收事件按通道独立；本实现把“任一通道收到帧”扩散到所有通道（同睡同醒）。

**风险**：

- 单通道唤醒可能被放大成多通道处理/唤醒，增加功耗；
- 多通道场景下状态机互相影响，排查时必须同时看两个通道；
- 与 `CANNM_PN_FEATURE_ENABLED=STD_OFF` 叠加时，PN 隔离不生效。

**回归**：单通道唤醒、双通道同时唤醒、仅一通道有帧时另一通道是否应保持睡眠。

### NS-004 用户层 NM 发送使能（`CANNM_NM_USER_ENABLE_SUPPORTED`，ON）

**代码行为**（`CanNm_TriggerTransmission`）：

```c
if( CANNM_0XFFFF != CanNm_GetTxPduRef(channel) )
{
    Can_NM_UserData_Fill();
    if( E_NOT_OK == CanNm_GetTxUserNMEnable() )   /* 项目 Hook 返回不允许 */
    {
        retVal = E_OK;                            /* 注意：不发送但返回 E_OK */
    }
    else
    {
        retVal = CanIf_Transmit(...);
    }
    ...
}
```

**与标准差异**：SWS 没有“用户层禁止 NM 发送”的 API；标准里 `E_OK` 表示已提交发送。

**风险**：

- 总线上没有帧，但调用者看到 `E_OK`，容易误判；
- 因为跳过 `CanIf_Transmit`，`MsgTimeoutTimer` 不会启动；后续快发/周期节奏可能异常；
- 排查时必须看 `CanNm_GetTxUserNMEnable()` 的返回值（外部 Hook），不能只看 CanNm 状态。

**建议**：把该 Hook 的输入/输出纳入测试与日志；量产确认默认允许。

### NS-005 发送前用户数据填充 Hook（`Can_NM_UserData_Fill`）

**代码行为**：`CanNm_TriggerTransmission` 在 `CanIf_Transmit` 前调用 `Can_NM_UserData_Fill()`（`CanNm.c` L1673），实现在 `003_RTE/Cus_If/Nm_IF/CAN_NM_Userdata_fill.c`。

**与标准差异**：SWS 的用户数据应通过 `PduR_CanNmTriggerTransmit`/`CanNm_SetUserData` 提供；本实现额外插入项目填充函数。

**风险**：Hook 阻塞/覆盖标准用户数据；未链接时可能链接失败或数据为空；需确认该函数是否依赖其他模块初始化顺序。

### NS-006 主函数测试钩子（`VCU_Test_Code_YXP`）

**代码行为**：

```c
#ifdef VCU_Test_Code_YXP
    Test_IO_Turn_LS10();      /* 主函数开头调用测试 IO */
#endif
```

**与标准差异**：SWS 主函数没有测试 IO 调用。

**风险**：打开后每个主函数周期翻转 IO，影响时序与功耗；量产必须确认未定义该宏。排查时序问题时先检查编译宏。

### NS-007 收到 NM 帧查询 API（`CanNm_GetMessageReceive`）

**代码行为**：`CanNm_RxIndication` 中 `CanNM_Message_Receive = TRUE`（L3521）；`CanNm_GetMessageReceive`（L3593）读取并清零。**不区分通道**。

**与标准差异**：SWS 无此 API；语义是“模块收到过 NM 帧”，不是“当前通道收到帧”。

**风险**：多通道场景下语义模糊；调用方若按通道判断会误用；只能作为“是否收到过”的粗粒度事件。

### NS-008 `CanNm_Init` 忽略 ConfigPtr

**代码行为**：`CanNm_Init` 的 `ConfigPtr` 仅做 `CANNM_DUMMY_STATEMENT(cannmConfigPtr)`（L2035）；实际配置直接引用 `CanNm_ChannelConfig[]`/`CanNm_PbChannelConfig[]` 常量（`CanNm_Cfg.c`）。

**与标准差异**：SWS 允许 link-time 配置，但接口仍保留 `ConfigPtr`；本实现实际不使用该指针；`CanNm_ConfigType` 仍保留完整字段（`CanNm_Cfg.h` L351~384），但初始化不走 ConfigPtr。

**风险**：移植/多配置集项目会误以为可切换配置；post-build 场景需重新确认。

### NS-009 时间参数是 tick，注释写 `[ms]`

**代码行为**：`CanNm_Cfg.h` 的结构体注释仍写 `[ms]`，但 `CanNm_MainFunction` 每周期递减一次，值是**主函数周期数**。

**与标准差异**：SWS 以秒配置，工具应换算成 tick；本实现已完成换算，但注释未同步。

**风险**：按 ms 排查会算错 10 倍/100 倍；必须用 `tick × CanNmMainFunctionPeriod` 换算。详见 `06_问题排查/CanNm_时间类问题排查.md`。

### NS-010 PN/CWU/远程睡眠/协调器同步代码存在但关闭

**配置快照**：`CANNM_PN_FEATURE_ENABLED=STD_OFF`、`CANNM_PN_INFO_LENGTH=0`、`CANNM_CAR_WUP_RX_FEATURE_ENABLED=STD_OFF`、`CANNM_REMOTE_SLEEP_IND_ENABLED=STD_OFF`、`CANNM_COORDINATOR_SYNC_SUPPORT=STD_OFF`。

**说明**：这些变量/函数仍存在（编译条件可能保留），但运行期不参与；不要按 PN/CWU 文档去查本项目的实际行为。

### NS-011 项目通道/PDU 固定映射

**配置快照**：`CANNM_NUMBER_OF_CANNM_CHANNELS=2`；ch0 `ChannelId=6、NodeId=39、TxPduRef=176`；ch1 `ChannelId=2、NodeId=35、TxPduRef=94`；`CanNm_SysToNmChInd[7]` 只映射 idx2→ch1、idx6→ch0。

**风险**：多通道排查时容易只看 ch0；跨通道串扰需同时看 `CanNm_NmState[0/1]` 与 `CanNm_SysToNmChInd`。

## 4. 风险与回归建议

| 编号 | 影响面 | 必测场景 |
|---|---|---|
| NS-001 | 总线负载、唤醒时序 | 收到 RMR、主动唤醒、多节点同时 RMR |
| NS-002 | 唤醒位语义 | 主动唤醒、被动唤醒、Ready→Normal 重入 |
| NS-003 | 多通道功耗/状态 | 单通道有帧、双通道同时有帧、仅一通道请求 |
| NS-004 | 发送成功判定 | Hook 允许/禁止、发送超时、周期恢复 |
| NS-005 | 用户数据内容 | PduR 用户数据、项目填充值、首帧内容 |
| NS-006 | 主函数时序 | 宏关闭/打开对比、任务抖动 |
| NS-007 | 上层判断 | 单/多通道收帧、清零时机 |
| NS-008 | 移植/配置选择 | 多配置集、post-build（如使用） |
| NS-009 | 时间类问题 | 首帧、睡眠、状态转换时间 |
| NS-010 | 排查范围 | PN/CWU/远程睡眠相关现象 |

## 5. 使用建议

1. **评审时**：把本页作为“标准之外”的检查单，确认每个 vendor 扩展是否被项目需要；
2. **移植时**：先确认宏默认值、Hook 是否存在（`Can_NM_UserData_Fill`、`CanNm_GetTxUserNMEnable`、`Test_IO_Turn_LS10`），否则会链接失败或行为漂移；
3. **排查时**：遇到“代码看起来对但总线不对”，先查 NS-004（用户使能）、NS-005（填充 Hook）、NS-006（测试钩子）、NS-001/003（快发/同睡同醒）；
4. **测试时**：按第 4 节补齐 vendor 行为的用例，不要只按 SWS 用例。

> 通用排查见 `06_问题排查/CanNm_快速问题定位.md`；时间类见 `06_问题排查/CanNm_时间类问题排查.md`；历史问题见 `CanNm_问题排查记录.md`。

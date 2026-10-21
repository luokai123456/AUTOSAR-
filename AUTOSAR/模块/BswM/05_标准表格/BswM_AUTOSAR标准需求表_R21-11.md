---
tags: [AUTOSAR, BswM, 标准表格]
---
# BswM AUTOSAR 标准需求表（R21-11）

> [!info] 导航
> 上级：[[BswM]] ｜ 依赖：[[BswM_配置参数表_R21-11]]、[[BswM_需求追溯与覆盖度]] ｜ 依据：AUTOSAR_SWS_BSWModeManager.pdf（Document ID 313，159 页）

> 适用版本：AUTOSAR CP R21-11　最后更新：2026-10-21
> 说明：把 SWS 正文需求块整理为中文，**需求号保留官方原文**；按需求号分组（组标题即 Obsidian 锚点），组内按需求号升序。

## 1. 使用说明

- 需求号：`SWS_BswM_xxxxx`（功能/接口）、`SWS_BswM_CONSTR_xxxxx`（配置约束）。
- 引用：`[[BswM_AUTOSAR标准需求表_R21-11#SWS_BswM_000xx|SWS_BswM_00009]]`。
- 实现路径：[[BswM_调用逻辑总览]] D1~D7；配置：[[BswM_配置参数表_R21-11]]；追溯：[[BswM_需求追溯与覆盖度]]。

## 2. 分组索引

| 分组 | 数量 |
|---|---|
| [[#SWS_BswM_CONSTR]] | 6 |
| [[#SWS_BswM_000xx]] | 64 |
| [[#SWS_BswM_001xx]] | 32 |
| [[#SWS_BswM_002xx]] | 73 |
| [[#SWS_BswM_910xx]] | 6 |

## 3. 需求表

### SWS_BswM_CONSTR

| 需求号 | 章节 | 中文说明 |
|---|---|---|
| SWS_BswM_CONSTR_00001 | 7.2.2 | 同一动作列表内 ItemIndex 不得重复，否则拒绝配置 |
| SWS_BswM_CONSTR_00002 | 10.2.12 | BswMCompuMethodRef 引用的 CompuMethod 类别必须为 TEXTTABLE |
| SWS_BswM_CONSTR_00003 | 10.2.59 | DeadlineMonitoring 动作中禁用/启用组引用同一 PDU 组时拒绝配置 |
| SWS_BswM_CONSTR_00004 | 10.2.71 | PduGroupSwitch 动作中禁用/启用引用同一 PDU 组时拒绝配置 |
| SWS_BswM_CONSTR_00005 | 10.2.81 | SdServiceGroupSwitch 动作中禁用/启用引用同一服务组时拒绝配置 |
| SWS_BswM_CONSTR_00006 | 10.2.89 | SwitchPort 被 RteSwitch/错误事件引用时必须配置 ModeSwitchInterfaceRef |

### SWS_BswM_000xx

| 需求号 | 章节 | 中文说明 |
|---|---|---|
| SWS_BswM_00001 | 8.1 | 规定模块头文件与导入类型（CanSM/Com/ComM/Dcm/EcuM 等） |
| SWS_BswM_00002 | 8.3.16 | BswM_Init 初始化模块并选择配置集 |
| SWS_BswM_00003 | 8.3.15 | BswM_GetVersionInfo 返回版本信息 |
| SWS_BswM_00007 | 8.6.1 | 无强制外部接口 |
| SWS_BswM_00008 | 8.6.2 | 可选外部接口清单（Com/ComM/Nm/NvM/EcuM/RTE 等） |
| SWS_BswM_00009 | 7.1.3 | 基于模式请求进行模式仲裁 |
| SWS_BswM_00010 | 7.1.3 | 使用配置规则进行模式仲裁 |
| SWS_BswM_00011 | 7.2.3 | TRIGGER 的 True 列表仅在规则由 False 变 True 时执行 |
| SWS_BswM_00012 | 7.1.3 | 仲裁规则通过配置参数定义 |
| SWS_BswM_00013 | 7.1.3.1 | 可通过 BswMRequestProcessing=IMMEDIATE 立即处理请求 |
| SWS_BswM_00014 | 7.1.3.1 | 可通过 BSWM_DEFERRED 把仲裁延迟到主函数 |
| SWS_BswM_00015 | 7.2.2 | 每条规则按 True/False 执行不同动作列表 |
| SWS_BswM_00016 | 7.2.2 | 模式控制通过动作列表完成 |
| SWS_BswM_00017 | 7.2.2 | 动作列表内动作按序执行 |
| SWS_BswM_00018 | 7.2.2 | 动作列表可引用其他动作列表 |
| SWS_BswM_00019 | 7.2.2 | 动作列表可引用规则并在列表内求值 |
| SWS_BswM_00023 | 7.2.3 | TRIGGER 的 False 列表仅在规则由 True 变 False 时执行 |
| SWS_BswM_00035 | 7.1.3 | 基于模式指示进行仲裁 |
| SWS_BswM_00037 | 7.2.2 | 级联动作列表/规则最多 7 层 |
| SWS_BswM_00038 | 7.2.4 | 执行 BswMAvailableActions 中的预定义动作 |
| SWS_BswM_00039 | 7.2.4 | 可调用任意 BSW 函数（非预定义动作） |
| SWS_BswM_00040 | 7.2.4 | 可调用用户自定义函数 |
| SWS_BswM_00041 | 8.2 | 规定 API 使用的数据类型 |
| SWS_BswM_00042 | 8.2.1 | BswM_ConfigType 包含所有 post-build 可配置参数 |
| SWS_BswM_00043 | 8.3.16 | BswM_Init 完成后可仲裁模式请求 |
| SWS_BswM_00044 | 8.3.16 | BswM_Init 初始化所有模块全局变量 |
| SWS_BswM_00045 | 8.3.16 | Init 时校验配置边界，失败报 BSWM_E_PARAM_CONFIG |
| SWS_BswM_00046 | 8.3.26 | BswM_RequestMode 通用模式请求 API |
| SWS_BswM_00047 | 8.3.3 | BswM_ComM_CurrentMode 通信模式指示 API |
| SWS_BswM_00048 | 8.3.7 | BswM_Dcm_CommunicationMode_CurrentState 诊断通信模式 API |
| SWS_BswM_00049 | 8.3.2 | BswM_CanSM_CurrentState CAN 状态指示 API |
| SWS_BswM_00050 | 8.3.13 | BswM_EthSM_CurrentState 以太网状态指示 API |
| SWS_BswM_00051 | 8.3.14 | BswM_FrSM_CurrentState FlexRay 状态指示 API |
| SWS_BswM_00052 | 8.3.20 | BswM_LinSM_CurrentState LIN 状态指示 API |
| SWS_BswM_00053 | 8.5.1 | BswM_MainFunction 主函数 API |
| SWS_BswM_00054 | 7.2.4 | 用户函数参数在配置期固定（BswMUserCallout） |
| SWS_BswM_00055 | 7.2.3 | 动作返回 E_NOT_OK 且 AbortOnFail 时中止列表 |
| SWS_BswM_00058 | 8.3.19 | BswM_LinSM_CurrentSchedule LIN 调度表指示 API |
| SWS_BswM_00059 | 7.1.3.1 | 仅在使用该 immediate 条件的上下文中求值相关规则 |
| SWS_BswM_00060 | 7.1.3.1 | 含 deferred 条件的规则每次主函数都求值 |
| SWS_BswM_00061 | 7.1.3.1 | 规则可混合 immediate/deferred 条件 |
| SWS_BswM_00062 | 7.2.2 | 请求上下文命中的动作列表立即执行 |
| SWS_BswM_00064 | 7.1.4 | 无初值且未收到请求的端口条件视为未定义 |
| SWS_BswM_00066 | 7.2.5 | 首次求值行为按表 7.1（BswMRuleInitState） |
| SWS_BswM_00067 | 7.2.2 | 嵌套规则结果列表先执行完再继续父列表 |
| SWS_BswM_00068 | 7.1.3.1 | 主函数执行期间的请求挂起（immediate 退出前处理，deferred 下周期） |
| SWS_BswM_00069 | 7.1.3.1 | immediate 请求处理期间的请求挂起 |
| SWS_BswM_00075 | 8.5.1 | 主函数求值所有含 deferred 条件的规则 |
| SWS_BswM_00077 | 8.3.26 | BswM_RequestMode 初始化检查（未初始化报错并忽略） |
| SWS_BswM_00078 | 8.3.3 | BswM_ComM_CurrentMode 初始化检查 |
| SWS_BswM_00079 | 8.3.7 | BswM_Dcm_CommunicationMode 初始化检查 |
| SWS_BswM_00080 | 8.3.2 | BswM_CanSM_CurrentState 初始化检查 |
| SWS_BswM_00081 | 8.3.13 | BswM_EthSM_CurrentState 初始化检查 |
| SWS_BswM_00082 | 8.3.14 | BswM_FrSM_CurrentState 初始化检查 |
| SWS_BswM_00083 | 8.3.20 | BswM_LinSM_CurrentState 初始化检查 |
| SWS_BswM_00084 | 8.3.9 | BswM_EcuM_CurrentState 初始化检查 |
| SWS_BswM_00086 | 8.3.19 | BswM_LinSM_CurrentSchedule 初始化检查 |
| SWS_BswM_00089 | 8.3.26 | BswM_RequestMode 参数范围检查 |
| SWS_BswM_00090 | 8.3.26 | BswM_RequestMode requesting_user 范围检查 |
| SWS_BswM_00091 | 8.3.3 | BswM_ComM_CurrentMode 参数范围检查 |
| SWS_BswM_00093 | 8.3.7 | BswM_Dcm_CommunicationMode 参数范围检查 |
| SWS_BswM_00095 | 8.3.2 | BswM_CanSM_CurrentState 参数范围检查 |
| SWS_BswM_00097 | 8.3.13 | BswM_EthSM_CurrentState 参数范围检查 |
| SWS_BswM_00099 | 8.3.14 | BswM_FrSM_CurrentState 参数范围检查 |

### SWS_BswM_001xx

| 需求号 | 章节 | 中文说明 |
|---|---|---|
| SWS_BswM_00101 | 8.3.20 | BswM_LinSM_CurrentState 参数范围检查 |
| SWS_BswM_00103 | 8.3.9 | BswM_EcuM_CurrentState 参数范围检查 |
| SWS_BswM_00104 | 8.3.24 | BswM_NvM_CurrentBlockMode 块状态指示 API |
| SWS_BswM_00109 | 8.3.24 | BswM_NvM_CurrentBlockMode 初始化检查 |
| SWS_BswM_00110 | 8.3.24 | BswM_NvM_CurrentBlockMode 参数范围检查 |
| SWS_BswM_00112 | 8.3.21 | BswM_LinTp_RequestMode 初始化检查 |
| SWS_BswM_00113 | 8.3.21 | BswM_LinTp_RequestMode 参数范围检查 |
| SWS_BswM_00115 | 7.2.3 | CONDITION 的 True 列表每次求值为 True 都执行 |
| SWS_BswM_00116 | 7.2.3 | CONDITION 的 False 列表每次求值为 False 都执行 |
| SWS_BswM_00117 | 7.1.3 | 规则不得引用其他规则求值结果作为输入 |
| SWS_BswM_00118 | 8.3.16 | BswM_Init 只要求 OS 与 SchM 已初始化 |
| SWS_BswM_00119 | 8.3.8 | BswM_Deinit 反初始化 API |
| SWS_BswM_00120 | 8.3.8 | Deinit 后不再处理任何模式（含主函数） |
| SWS_BswM_00131 | 8.3.10 | BswM_EcuM_CurrentWakeup 唤醒源指示 API |
| SWS_BswM_00132 | 8.3.10 | BswM_EcuM_CurrentWakeup 初始化检查 |
| SWS_BswM_00133 | 8.3.10 | BswM_EcuM_CurrentWakeup 参数范围检查 |
| SWS_BswM_00134 | 8.3.31 | BswM_WdgM_RequestPartitionReset 初始化检查 |
| SWS_BswM_00147 | 7.1.3 | 动作只能在动作列表上下文中被调用 |
| SWS_BswM_00148 | 8.3.4 | BswM_ComM_CurrentPNCMode PNC 模式指示 API |
| SWS_BswM_00149 | 8.3.4 | BswM_ComM_CurrentPNCMode 初始化检查 |
| SWS_BswM_00150 | 8.3.4 | BswM_ComM_CurrentPNCMode 参数范围检查 |
| SWS_BswM_00152 | 8.3.25 | BswM_NvM_CurrentJobMode 多块作业状态 API |
| SWS_BswM_00153 | 8.3.25 | BswM_NvM_CurrentJobMode 初始化检查 |
| SWS_BswM_00154 | 8.3.25 | BswM_NvM_CurrentJobMode 参数范围检查 |
| SWS_BswM_00156 | 8.3.21 | BswM_LinTp_RequestMode LIN 传输层模式请求 API |
| SWS_BswM_00157 | 8.3.31 | BswM_WdgM_RequestPartitionReset 分区复位 API（obsolete） |
| SWS_BswM_00158 | 8.3.6 | BswM_Dcm_ApplicationUpdated 应用更新事件 API |
| SWS_BswM_00159 | 8.3.6 | BswM_Dcm_ApplicationUpdated 初始化检查 |
| SWS_BswM_00165 | 8.3.17 | BswM_J1939DcmBroadcastStatus 广播状态 API |
| SWS_BswM_00189 | 7.1.3 | 基于模式切换通知进行仲裁 |
| SWS_BswM_00193 | 8.3.1 | BswM_BswMPartitionRestarted 分区重启事件 API |
| SWS_BswM_00194 | 8.3.18 | BswM_J1939Nm_StateChangeNotification J1939 状态通知 API |

### SWS_BswM_002xx

| 需求号 | 章节 | 中文说明 |
|---|---|---|
| SWS_BswM_00200 | 8.7.2.1 | 定义 modeNotificationPort 端口（模式通知 R-Port） |
| SWS_BswM_00201 | 8.7.2.2 | 定义 modeRequestPort 端口（模式请求 R-Port） |
| SWS_BswM_00202 | 8.7.2.3 | 定义 modeSwitchPort 端口（模式切换 P-Port） |
| SWS_BswM_00203 | 7.1.4 | Init 时按 BswMModeInitValue 初始化端口值 |
| SWS_BswM_00204 | 8.3.27 | BswM_Sd_ClientServiceCurrentState 服务发现客户端状态 API |
| SWS_BswM_00205 | 8.3.27 | Sd_ClientService 初始化检查 |
| SWS_BswM_00206 | 8.3.27 | Sd_ClientService 参数范围检查 |
| SWS_BswM_00207 | 8.3.28 | BswM_Sd_ConsumedEventGroupCurrentState 消费事件组状态 API |
| SWS_BswM_00208 | 8.3.28 | Sd_ConsumedEventGroup 初始化检查 |
| SWS_BswM_00209 | 8.3.28 | Sd_ConsumedEventGroup 参数范围检查 |
| SWS_BswM_00210 | 8.3.29 | BswM_Sd_EventHandlerCurrentState 事件处理状态 API |
| SWS_BswM_00211 | 8.3.29 | Sd_EventHandler 初始化检查 |
| SWS_BswM_00212 | 8.3.29 | Sd_EventHandler 参数范围检查 |
| SWS_BswM_00213 | 8.2.1 | BswM_ConfigType 结构定义 |
| SWS_BswM_00214 | 8.2.2 | BswM_ModeType 类型定义 |
| SWS_BswM_00216 | 8.2.3 | BswM_UserType 类型定义 |
| SWS_BswM_00217 | 8.3.5 | BswM_ComM_InitiateReset 复位事件 API |
| SWS_BswM_00220 | 7.3 | BswMTimer 恒按 DEFERRED 处理，忽略 RequestProcessing |
| SWS_BswM_00223 | 7.2.2 | 多条规则触发同一顶层列表时只执行一次 |
| SWS_BswM_00227 | 8.3.11 | BswM_EcuM_RequestedState 初始化检查 |
| SWS_BswM_00228 | 8.3.11 | BswM_EcuM_RequestedState State 参数检查 |
| SWS_BswM_00229 | 8.3.11 | BswM_EcuM_RequestedState CurrentStatus 参数检查 |
| SWS_BswM_00230 | 7.5.1 | 开发错误码表（UNINIT/NULL_POINTER/PARAM_INVALID 等） |
| SWS_BswM_00235 | 8.3.22 | BswM_Nm_CarWakeUpIndication CarWakeup 指示 API |
| SWS_BswM_00236 | 10.2.45 | BswMSwcModeRequest 引用的数据原型必须属于 SenderReceiver 接口 |
| SWS_BswM_00237 | 8.1 | 只能使用 SWS_BswM_00001 列出的导入类型 |
| SWS_BswM_00238 | 7.5.2 | 运行时错误码表（ACTION_FAILED 等） |
| SWS_BswM_00239 | 7.5.2 | 配置了 ReportFailRuntimeErrorId 时失败上报 Det |
| SWS_BswM_00240 | 7.5.2 | ReportFailRuntimeErrorId 越界时拒绝配置 |
| SWS_BswM_00241 | 7.1.4 | 只仲裁不含未定义条件的规则 |
| SWS_BswM_00242 | 10.2.4 | NAND 表达式必须 2 个参数 |
| SWS_BswM_00243 | 10.2.4 | NOT 表达式必须 1 个参数 |
| SWS_BswM_00244 | 10.2.4 | XOR：奇数个 True 结果为 True |
| SWS_BswM_00245 | 10.2.4 | AND：全 True 才 True |
| SWS_BswM_00246 | 10.2.4 | NAND：全 True 为 False，否则 True |
| SWS_BswM_00247 | 10.2.4 | OR：有 True 即 True |
| SWS_BswM_00248 | 10.2.4 | NOT：取反 |
| SWS_BswM_00249 | 8.3.17 | J1939 广播 NetworkMask 位与 ComMChannelId 对应 |
| SWS_BswM_00250 | 10.2.29 | J1939 广播只支持前 16 个 ComMChannelId，越界拒绝 |
| SWS_BswM_00251 | 7.1.4 | 初始化时事件端口全部置 CLEAR |
| SWS_BswM_00252 | 7.1.2 | EVENT_IS_SET 条件语义 |
| SWS_BswM_00253 | 7.1.2 | EVENT_IS_CLEARED 条件语义 |
| SWS_BswM_00254 | 7.1.2 | 事件 API 调用把事件端口置 SET |
| SWS_BswM_00255 | 7.1.2 | ClearEventRequest 动作把事件端口清 CLEAR |
| SWS_BswM_00257 | 7.1.3.1 | 事件可在 SET 时立即处理（BswMEventRequestProcessing=IMMEDIATE） |
| SWS_BswM_00258 | 7.1.3.1 | 事件可延迟到主函数处理（DEFERRED） |
| SWS_BswM_00259 | 10.2.34 | BswMModeSwitchErrorEvent 在 SWCD 中创建错误事件 |
| SWS_BswM_00260 | 7.2.2 | 动作列表从最小 ItemIndex 开始按升序执行 |
| SWS_BswM_00261 | 7.3 | 初始化时所有 BswMTimer 置 STOPPED |
| SWS_BswM_00262 | 7.3 | TimerAction=START 装载并启动定时器 |
| SWS_BswM_00263 | 7.3 | STARTED 定时器在主函数中按周期递减 |
| SWS_BswM_00264 | 7.3 | 定时器到期置 EXPIRED 并在同一主函数参与仲裁 |
| SWS_BswM_00265 | 7.3 | TimerAction=STOP 立即停止定时器 |
| SWS_BswM_00266 | 8.7.2.1 | modeNotificationPort 初始化检查 |
| SWS_BswM_00267 | 8.3.12 | BswM_EthIf_PortGroupLinkStateChg 初始化检查 |
| SWS_BswM_00268 | 8.3.12 | BswM_EthIf_PortGroupLinkStateChg 参数范围检查 |
| SWS_BswM_00269 | 10.2.60 | 执行 EcuM 驱动初始化列表动作时调用 EcuM_AL_DriverInitBswM_* |
| SWS_BswM_00271 | 10.2.74 | BswMRteStart 动作调用 Rte_Start |
| SWS_BswM_00272 | 10.2.75 | BswMRteStop 动作调用 Rte_Stop |
| SWS_BswM_00273 | 10.2.71 | PduGroupSwitch 动作调用 Com_IpduGroupStart/Stop |
| SWS_BswM_00274 | 10.2.59 | DeadlineMonitoring 动作调用 Com_Enable/DisableReceptionDM |
| SWS_BswM_00275 | 7.2.2 | 多个顶层列表按优先级从高到低执行 |
| SWS_BswM_00276 | 7.2.2 | 非顶层列表忽略优先级 |
| SWS_BswM_00277 | 7.2.2 | 未配置优先级按 0 处理 |
| SWS_BswM_00278 | 7.1.3 | 基于事件请求及其清除进行仲裁 |
| SWS_BswM_00279 | 10.2.90 | 私有头文件可用性取决于 BswM<BSWModule>Enabled |
| SWS_BswM_00280 | 10.2.81 | SdServiceGroupSwitch 动作调用 Sd_ServiceGroupStart/Stop |
| SWS_BswM_00281 | 7.1.3.1 | IMMEDIATE 端口值在仲裁前更新 |
| SWS_BswM_00282 | 7.1.3.1 | DEFERRED 端口值在触发时更新 |
| SWS_BswM_00283 | 8.8 | API 与请求端口的映射表 |
| SWS_BswM_00284 | 10.2.46 | SwitchAckNotification 的 ModeSwitch 接口语义 |
| SWS_BswM_00285 | 10.2.46 | SwitchAckNotification 的 SchM 模式组语义 |
| SWS_BswM_00286 | 10.2.64 | EthIfStartAllPorts 动作调用 EthIf_StartAllPorts |

### SWS_BswM_910xx

| 需求号 | 章节 | 中文说明 |
|---|---|---|
| SWS_BswM_09999 | 10.3 | 不适用需求（第 12 章） |
| SWS_BswM_91001 | 8.3.12 | BswM_EthIf_PortGroupLinkStateChg 端口组链路状态 API |
| SWS_BswM_91002 | 8.3.23 | BswM_Nm_StateChangeNotification NM 状态通知 API |
| SWS_BswM_91003 | 8.3.9 | BswM_EcuM_CurrentState ECU 状态指示 API |
| SWS_BswM_91004 | 8.3.11 | BswM_EcuM_RequestedState ECU 请求状态 API |
| SWS_BswM_91005 | 8.3.30 | BswM_SoAd_SoConModeChg Socket 连接模式变化 API |

## 4. 覆盖度统计

| 指标 | 数值 |
|---|---|
| 需求块总数 | 181 |
| 配置约束 CONSTR | 6 |
| 功能/接口需求 | 175 |
| 配置参数（ECUC） | 91 |
| 需求追溯条目 | 25 |

> 统计口径：SWS 正文 `[SWS_BswM_xxxxx]`（含 CONSTR）需求块去重；DRAFT/OBSOLETE 标记已包含在表内。

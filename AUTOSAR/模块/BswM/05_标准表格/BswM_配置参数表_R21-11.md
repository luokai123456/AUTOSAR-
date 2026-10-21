---
tags: [AUTOSAR, BswM, 标准表格]
---
# BswM 配置参数表（ECUC，R21-11）

> [!info] 导航
> 上级：[[BswM]] ｜ 依赖：[[BswM_DaVinci配置项]] ｜ 依据：[[BswM_AUTOSAR标准需求表_R21-11]]

> 适用版本：AUTOSAR CP R21-11　依据：SWS_BswM 第 10 章（ECUC_BswM_xxxxx）
> 最后更新：2026-10-21

## 1. 模块与全局（BswM / BswMGeneral）

| ECUC 号 | 名称 | 类型 | 中文说明 | 备注 |
|---|---|---|---|---|
| ECUC_BswM_01063 | BswM | Module | 模块定义 | 支持 post-build |
| ECUC_BswM_00800 | BswMGeneral | Container | 全局参数容器 | 1 个 |
| ECUC_BswM_00811 | BswMDevErrorDetect | Param | 开发错误检测 | 默认 false |
| ECUC_BswM_00812 | BswMVersionInfoApi | Param | 版本 API 开关 | 默认 false |
| ECUC_BswM_00813 | BswMMainFunctionPeriod | Param | 主函数周期（秒） | 必须等于任务周期 |
| ECUC_BswM_00938 | BswMCanSMEnabled | Param | 使能 CanSM 相关 API/头文件 | 默认 false |
| ECUC_BswM_00939 | BswMComMEnabled | Param | 使能 ComM 相关 API | 默认 false |
| ECUC_BswM_00940 | BswMDcmEnabled | Param | 使能 Dcm 相关 API | 默认 false |
| ECUC_BswM_00941 | BswMEcuMEnabled | Param | 使能 EcuM 相关 API | 默认 false |
| ECUC_BswM_01072 | BswMEthIfEnabled | Param | 使能 EthIf 相关 API | 默认 false |
| ECUC_BswM_00942 | BswMEthSMEnabled | Param | 使能 EthSM 相关 API | 默认 false |
| ECUC_BswM_00943 | BswMFrSMEnabled | Param | 使能 FrSM 相关 API | 默认 false |
| ECUC_BswM_00949 | BswMGenericRequestEnabled | Param | 使能 `BswM_RequestMode` | 默认 false |
| ECUC_BswM_00987 | BswMJ1939DcmEnabled | Param | 使能 J1939Dcm | 默认 false |
| ECUC_BswM_00965 | BswMJ1939NmEnabled | Param | 使能 J1939Nm | 默认 false |
| ECUC_BswM_00944 | BswMLinSMEnabled | Param | 使能 LinSM | 默认 false |
| ECUC_BswM_00945 | BswMLinTPEnabled | Param | 使能 LinTp | 默认 false |
| ECUC_BswM_01071 | BswMNmEnabled | Param | 使能 Nm | 默认 false |
| ECUC_BswM_00946 | BswMNvMEnabled | Param | 使能 NvM | 默认 false |
| ECUC_BswM_00947 | BswMSchMEnabled | Param | 使能 SchM | 默认 false |
| ECUC_BswM_01047 | BswMSdEnabled | Param | 使能 Sd | 默认 false |
| ECUC_BswM_00948 | BswMWdgMEnabled | Param（obsolete） | 使能 WdgM | R21-11 已废弃 |
| ECUC_BswM_00954 | BswMUserIncludeFiles | Container | 强制包含的头文件列表 | 0..1 |
| ECUC_BswM_00955 | BswMUserIncludeFile | Param | 头文件名 | 1..* |

## 2. 配置容器（BswMConfig）

| ECUC 号 | 名称 | 类型 | 中文说明 | 备注 |
|---|---|---|---|---|
| ECUC_BswM_00895 | BswMConfig | Container | 每个分区一份配置 | 1..* |
| ECUC_BswM_00984 | BswMPartitionRef | Ref | 绑定分区 | 0..1 |
| ECUC_BswM_00936 | BswMDataTypeMappingSets | Container | 模式值映射集引用 | 0..1 |
| ECUC_BswM_00937 | BswMDataTypeMappingSetRef | Ref | 引用 DataTypeMappingSet | — |

## 3. 仲裁（BswMArbitration）

### 3.1 端口

| ECUC 号 | 名称 | 类型 | 中文说明 | 备注 |
|---|---|---|---|---|
| ECUC_BswM_00801 | BswMArbitration | Container | 仲裁配置容器 | 1 个 |
| ECUC_BswM_00805 | BswMModeRequestPort | Container | 模式请求/指示端口 | 0..* |
| ECUC_BswM_00822 | BswMRequestProcessing | Param | IMMEDIATE / DEFERRED | 必配 |
| ECUC_BswM_00928 | BswMModeInitValue | Container | 端口初始模式值 | 0..1 |
| ECUC_BswM_00932 | BswMBswModeInitValue | Param | 初始值（文本/模式） | 0..1 |
| ECUC_BswM_01039 | BswMCompuScaleModeValue | Container | 用 CompuMethod 定义初值 | 0..1 |
| ECUC_BswM_01040 | BswMCompuMethodRef | Ref | CompuMethod 引用（TEXTTABLE） | CONSTR_00002 |
| ECUC_BswM_00856 | BswMModeRequestSource | Choice | 端口来源选择（CanSM/ComM/Dcm/EcuM/NvM/Nm/Sd/SoAd/SWC 等） | 1 个 |
| ECUC_BswM_01052 | BswMEventRequestPort | Container | 事件请求端口 | 0..* |
| ECUC_BswM_01056 | BswMEventRequestProcessing | Param | IMMEDIATE / DEFERRED | 必配 |
| ECUC_BswM_01053 | BswMEventRequestSource | Choice | 事件来源选择（ComM 复位/Dcm 更新/Nm 唤醒/分区重启/SwitchAck 等） | 1 个 |

### 3.2 条件与表达式

| ECUC 号 | 名称 | 类型 | 中文说明 | 备注 |
|---|---|---|---|---|
| ECUC_BswM_00807 | BswMModeCondition | Container | 条件定义 | 0..* |
| ECUC_BswM_00815 | BswMConditionType | Param | EQUALS/EQUALS_NOT/EVENT_IS_SET/EVENT_IS_CLEARED | 必配 |
| ECUC_BswM_00821 | BswMConditionMode | Ref | 引用模式端口或事件端口 | 必配 |
| ECUC_BswM_00816 | BswMConditionValue | Container | 条件比较值 | 0..1 |
| ECUC_BswM_00869 | BswMBswRequestedMode | Param | BSW 模式值 | — |
| ECUC_BswM_00868 | BswMModeValueRef | Ref | 引用 ModeDeclaration | — |
| ECUC_BswM_00808 | BswMLogicalExpression | Container | 逻辑表达式 | 0..* |
| ECUC_BswM_00814 | BswMLogicalOperator | Param | AND/OR/XOR/NOT/NAND | NAND=2 参数、NOT=1 参数 |
| ECUC_BswM_00820 | BswMArgumentRef | Ref | 引用条件或子表达式 | 1..* |

### 3.3 规则

| ECUC 号 | 名称 | 类型 | 中文说明 | 备注 |
|---|---|---|---|---|
| ECUC_BswM_00806 | BswMRule | Container | 仲裁规则 | 0..* |
| ECUC_BswM_00819 | BswMRuleExpressionRef | Ref | 引用逻辑表达式 | 必配 |
| ECUC_BswM_00817 | BswMRuleTrueActionList | Ref | True 时执行的动作列表 | 0..1 |
| ECUC_BswM_00818 | BswMRuleFalseActionList | Ref | False 时执行的动作列表 | 0..1 |
| ECUC_BswM_00888 | BswMRuleInitState | Param | UNDEFINED/TRUE/FALSE | 首次求值行为 |
| ECUC_BswM_00935 | BswMNestedExecutionOnly | Param | 仅作为子规则求值 | 默认 false |

## 4. 模式控制（BswMModeControl）

| ECUC 号 | 名称 | 类型 | 中文说明 | 备注 |
|---|---|---|---|---|
| ECUC_BswM_00802 | BswMModeControl | Container | 模式控制配置容器 | 1 个 |
| ECUC_BswM_00809 | BswMActionList | Container | 动作列表 | 1..* |
| ECUC_BswM_00894 | BswMActionListExecution | Param | TRIGGER / CONDITION | 必配 |
| ECUC_BswM_01076 | BswMActionListPriority | Param | 0..255，默认 0 | 顶层列表排序 |
| ECUC_BswM_00823 | BswMActionListItem | Container | 列表项 | 1..* |
| ECUC_BswM_00824 | BswMActionListItemIndex | Param | 0..255，列表内唯一 | 执行顺序 |
| ECUC_BswM_00825 | BswMActionListItemRef | Ref | 引用动作/子列表/规则 | 必配 |
| ECUC_BswM_00902 | BswMAbortOnFail | Param | 失败是否中止列表 | 默认 false |
| ECUC_BswM_01050 | BswMReportFailRuntimeErrorId | Param | 失败上报 Det 的错误号 | 128..255 |
| ECUC_BswM_00810 | BswMAction | Container | 动作实例 | 0..* |
| ECUC_BswM_00826 | BswMAvailableActions | Choice | 可用动作选择 | 1 个 |
| ECUC_BswM_00950 | BswMSwitchPort | Container | 对外模式切换端口 | 0..* |
| ECUC_BswM_00951 | BswMModeSwitchInterfaceRef | Ref | ModeSwitch 接口 | — |
| ECUC_BswM_01031 | BswMSchMModeDeclarationGroupRef | Ref | SchM 模式组 | — |
| ECUC_BswM_01022 | BswMRteModeRequestPort | Container | 向 SWC 发模式请求的端口 | 0..* |
| ECUC_BswM_01025 | BswMRteModeRequestPortInterfaceRef | Ref | 变量数据原型引用 | — |
| ECUC_BswM_01057 | BswMRteModeRequestVariableDataPrototypeSRRef | Ref | 或外部引用 VariableDataPrototype | — |

## 5. 动作（BswMAvailableActions 下）

| ECUC 号 | 名称 | 中文说明 |
|---|---|---|
| ECUC_BswM_01055 | BswMClearEventRequest | 清事件端口 |
| ECUC_BswM_00918 | BswMComMAllowCom | 允许/禁止通道通信（ComM_CommunicationAllowed） |
| ECUC_BswM_00908 | BswMComMModeLimitation | 限制通道（ComM_LimitChannelToNoComMode） |
| ECUC_BswM_00831 | BswMComMModeSwitch | 请求 ComM 模式（ComM_RequestComMode） |
| ECUC_BswM_00970 | BswMCoreHaltMode | 多核 HALT |
| ECUC_BswM_00830 | BswMDeadlineMonitoringControl | 开关接收 DM（Com_Enable/DisableReceptionDM） |
| ECUC_BswM_01064 | BswMEcuMDriverInitListBswM | 触发 EcuM 驱动初始化列表 |
| ECUC_BswM_00963 | BswMEcuMGoDownHaltPoll | 下电/休眠（EcuM_GoDownHaltPoll） |
| ECUC_BswM_00961 | BswMEcuMSelectShutdownTarget | 选择关机目标 |
| ECUC_BswM_01045 | BswMEcuMStateSwitch | EcuM 状态切换 |
| ECUC_BswM_01088 | BswMEthIfStartAllPorts | 启动所有以太网端口 |
| ECUC_BswM_01068 | BswMEthIfSwitchPortGroupRequestMode | 交换机端口组切换 |
| ECUC_BswM_01037 | BswMFrSMAllSlots | 退出 FlexRay KeySlotOnly |
| ECUC_BswM_01032 | BswMJ1939DcmStateSwitch | J1939 诊断状态切换 |
| ECUC_BswM_00998 | BswMJ1939RmStateSwitch | J1939 请求管理状态 |
| ECUC_BswM_00827 | BswMLinScheduleSwitch | 切 LIN 调度表 |
| ECUC_BswM_00837 | BswMNMControl | 开关 NM 通信（Nm_Enable/DisableCommunication） |
| ECUC_BswM_00828 | BswMPduGroupSwitch | 启停 PDU 组（Com_IpduGroupStart/Stop） |
| ECUC_BswM_00853 | BswMPduRouterControl | 开关路由组（PduR_Enable/DisableRouting） |
| ECUC_BswM_01021 | BswMRteModeRequest | 向 SWC 模式管理器发请求 |
| ECUC_BswM_01073 | BswMRteStart | 启动 RTE（Rte_Start） |
| ECUC_BswM_01074 | BswMRteStop | 停止 RTE（Rte_Stop） |
| ECUC_BswM_00803 | BswMRteSwitch | 通知 SWC 模式切换（Rte_Switch） |
| ECUC_BswM_00899 | BswMSchMSwitch | 通知 BSW 模式切换（SchM_Switch） |
| ECUC_BswM_00974 | BswMSdClientServiceModeRequest | Sd 客户端服务状态 |
| ECUC_BswM_01004 | BswMSdConsumedEventGroupModeRequest | Sd 消费事件组状态 |
| ECUC_BswM_01005 | BswMSdServerServiceModeRequest | Sd 服务端服务状态 |
| ECUC_BswM_01077 | BswMSdServiceGroupSwitch | Sd 服务组开关 |
| ECUC_BswM_00958 | BswMSwitchIPduMode | 切 I-PDU 发送模式 |
| ECUC_BswM_01059 | BswMTimerControl | 启动/停止定时器 |
| ECUC_BswM_00906 | BswMTriggerIPduSend | 立即发送一帧（Com_TriggerIPDUSend） |
| ECUC_BswM_00834 | BswMUserCallout | 用户自定义函数（含 NvM_ReadAll/WriteAll） |

## 6. 统计

| 类别 | 数量 |
|---|---|
| ECUC 定义总数 | 91 |
| 本表整理（关键参数/容器/动作） | 约 70 |
| 配置约束 CONSTR | 6 |

> 参数作用与 DaVinci 配置流程见 [[BswM_DaVinci配置项]]；约束来源为 SWS 10.2 的 Scope/Dependency 字段。

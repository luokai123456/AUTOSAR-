---
tags: [AUTOSAR, BswM, 学习总结]
---

# BswM 一页纸复盘（面试/工作可复述版）

> [!info] 导航
> 上级：[[BswM]] ｜ 依赖：[[BswM_调用逻辑总览]]、[[BswM_D5_状态转换表]] ｜ 依据：[[BswM_AUTOSAR标准需求表_R21-11]]

> 用途：3 分钟讲清 BswM；10 分钟讲清配置与运行时序。依据 R21-11 SWS。

## 1. 30 秒版本

BswM 是 AUTOSAR BSW 里的模式管理器。它把 EcuM、ComM、Dcm、各总线状态管理器以及应用的模式请求，按配置好的布尔规则做仲裁，得到"当前该进入什么模式"，然后执行动作列表，去调用 Com、PduR、ComM、NvM、EcuM、RTE 等模块的 API，完成开关通信、切 PDU 组、切路由、读写 NvM、下电休眠、通知应用等动作。它本身没有业务状态机，行为完全由配置决定。

## 2. 三个"为什么"

1. 为什么要有它？把分散在 EcuM/ComM/应用里的模式决策集中成可配置、可评审的规则表。
2. 为什么分两段？仲裁（求值）与控制（执行）解耦，规则可嵌套、动作可复用。
3. 为什么要分 IMMEDIATE/DEFERRED？实时性 vs 执行安全的取舍。

## 3. 必背的 8 个配置对象

| # | 对象 | 一句话 |
|---|---|---|
| 1 | `BswMModeRequestPort` | 一个输入来源（含 `BswMModeRequestSource` 与 IMMEDIATE/DEFERRED） |
| 2 | `BswMEventRequestPort` | 只表示事件 SET/CLEAR 的输入 |
| 3 | `BswMModeCondition` | 对端口的判断：EQUAL/NOT_EQUAL/EVENT_SET/CLEARED |
| 4 | `BswMLogicalExpression` | 条件的 AND/OR/XOR/NOT/NAND 组合 |
| 5 | `BswMRule` | 表达式 + True/False 动作列表 + 初始状态 |
| 6 | `BswMActionList` | 有序动作集合（TRIGGER/CONDITION、优先级） |
| 7 | `BswMAction`/`BswMAvailableActions` | 具体动作（决定调用哪个 BSW API） |
| 8 | `BswMSwitchPort` | 对外模式切换端口（Rte_Switch/SchM_Switch） |

## 4. 运行时的 6 步

1. SchM 周期调用 `BswM_MainFunction`；
2. 定时器衰减、到期置 EXPIRED；
3. 求值所有顶层 deferred 规则（未定义条件跳过）；
4. 结果变化/条件成立 → 选 True/False 动作列表；
5. 按优先级排序、按 ItemIndex 执行动作（子列表/嵌套规则递归，最多 7 层）；
6. 处理执行期间挂起的 IMMEDIATE 请求，返回。

## 5. 5 个常见故障 → 根因定位

| 现象 | 优先查 |
|---|---|
| 上电后通信不开 | ModeRequestPort 初值未配 / 规则因未定义条件被跳过 / ComM 或 PDU 组动作没配 |
| 通信关了但诊断不响应 | 正常通信与诊断通信是否用了不同 PDU 组；动作顺序 |
| 休眠不休 / 反复唤醒 | NM/ComM 模式规则、`Nm_DisableCommunication` 是否执行、唤醒源条件 |
| 模式切换延迟大 | 端口配成 DEFERRED 且 MainFunction 周期长；定时器精度 |
| 生成代码链接报错 | `BswM<X>Enabled` 未打开导致缺头文件；引用模块配置缺失 |

## 6. 自测题（答不上就回读对应文档）

1. 规则能不能引用另一条规则的结果？为什么？（SWS_BswM_00117）
2. `BSWM_TRIGGER` 与 `BSWM_CONDITION` 的区别？首次执行有什么坑？（SWS 7.2.5 表 7.1）
3. 未配置 `BswMModeInitValue` 时，规则会怎样？（SWS_BswM_00064/00241）
4. `BswM_MainFunction` 执行中来了新请求怎么处理？（SWS_BswM_00068）
5. BswMTimer 由谁启动、精度由什么决定？（SWS 7.3）
6. 动作返回 E_NOT_OK 时 BswM 做什么？（SWS 7.2 / 7.5.2）
7. NvM_ReadAll/WriteAll 在 BswM 里怎么配？（`BswMUserCallout`，SWS 10.2.85）
8. IMMEDIATE 和 DEFERRED 各自适合什么动作？（SWS 7.1.3.1）
9. 多分区时 BswM 怎么部署？（SWS 7.4）
10. `BswM_Init` 由谁调用、依赖什么？（SWS_EcuM_04014、SWS_BswM_00118）

## 7. 讲项目时的模板

> "我们 ECU 的模式管理都收在 BswM：EcuM 上报状态和唤醒源，ComM 上报通道/PNC 模式，Dcm 上报诊断通信要求。BswM 按规则仲裁出 ECU 模式和应用模式，动作列表里依次做：ComM 请求通信 → Nm 使能 → Com 启动 PDU 组 → Rte_Switch 通知应用；关机时反过来：NvM_WriteAll → 停 PDU 组 → 停 NM → EcuM_GoDownHaltPoll。周期 10ms，deferred 端口为主，少数紧急请求走 immediate。"

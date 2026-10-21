# AUTOSAR Classic Platform 模块学习路线

> 适用版本：AUTOSAR CP R21-11 为主，DaVinci Configurator Classic 6.x
> 目标：职场学习者，以"能在 DaVinci 里配得出来、能讲清运行时序"为标准，而不是背概念。

## 一、先建立整体骨架（1～2 天）

1. 分层架构：Application SWC → RTE → BSW（Services / ECU Abstraction / MCAL）→ 硬件
2. 一次 ECU 从上电到运行的完整链路：EcuM → BswM → RTE → SWC，及 OS 调度
3. 通信链路：SWC → RTE → Com → PduR → CanIf/CanTp → Can Driver → 总线
4. 诊断链路：Dcm → PduR → CanTp/CanIf；Dem 记录故障
5. 存储链路：NvM → Fee → Fls；MemIf 抽象

配套官方文档：`AUTOSAR_TR_ClassicPlatformReleaseOverview.pdf`、`AUTOSAR_EXP_LayeredSoftwareArchitecture.pdf`

## 二、按依赖关系排序的学习顺序

| 阶段 | 模块 | 为什么先学它 | 核心官方文档 |
|---|---|---|---|
| 1 | **EcuM** | 上电/下电、启动阶段划分，是理解"整个 BSW 怎么启动"的入口 | SWS_ECUStateManager |
| 2 | **BswM** | 模式管理，把 EcuM/ComM/Dcm 等事件转成动作，决定 BSW 行为 | SWS_BSWModeManager |
| 3 | **Os** | 任务/中断/Alarm，MainFunction 的调度者 | SWS_OS |
| 4 | **Com** | 信号打包、发送模式、超时监控，通信核心 | SWS_COM |
| 5 | **PduR** | 网关与路由，串起 Com/Dcm/CanIf/CanTp | SWS_PduR |
| 6 | **CanIf / CanTp** | 报文收发与分段传输 | SWS_CANInterface / SWS_CANTransportLayer |
| 7 | **Dcm / Dem** | 诊断服务与故障管理，工程中高频使用 | SWS_DiagnosticCommunicationManager / SWS_DiagnosticEventManager |
| 8 | **NvM / Fee / Fls** | 数据掉电保存链路 | SWS_NvM / SWS_Fee / SWS_Flash |
| 9 | **WdgM / WdgIf** | 看门狗与程序流监控 | SWS_WatchdogManager |
| 10 | **E2E / Crc / SecOC** | 通信安全与数据校验，功能安全项目必备 | SWS_E2E / SWS_CRC / SWS_SecOC |
| 11 | **RTE / SWC / 方法论** | 从 BSW 走向应用层与集成 | SWS_RTE、TPS_SoftwareComponentTemplate |

## 三、每个模块的学习节奏（建议 1 个模块 2～3 天）

- 第 1 天：读 SWS 的功能概述 + 配置章节，下载文档，写"作用与架构定位"
- 第 2 天：在 DaVinci 中对照配置容器逐项理解，整理配置表
- 第 3 天：画调用关系 + MainFunction 流程，写复盘，登记到 README 进度表

## 四、判断"学会了"的标准

1. 能画出该模块在分层架构中的位置，说清上下游接口
2. 能解释 DaVinci 中主要配置容器的含义，知道改一个参数会影响什么行为
3. 能口述 MainFunction 的一次执行路径：入口 → 处理 → 输出
4. 能举一个项目中的实际问题场景（如信号丢帧、DTC 不置位、休眠不休）并定位到该模块

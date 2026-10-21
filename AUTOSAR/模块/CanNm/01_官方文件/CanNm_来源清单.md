---
tags: [AUTOSAR, CanNm, 官方文件]
---

# CanNm 官方文档来源清单

> [!info] 导航
> 上级：[[CanNm]] ｜ 说明：本页登记官方 PDF 与本地实现代码清单，不参与双链图谱

> 平台：AUTOSAR Classic Platform　版本：R21-11　下载日期：2026-10-20
> 下载站点：<https://www.autosar.org>（路径 `/fileadmin/standards/R21-11/CP/`）
> 说明：官方文档版权归 AUTOSAR 所有，仅用于学习研究，不得商用再分发。

## 已下载文档

| 序号 | 文件名 | 类型 | 大小 | 页数 | 说明 | 来源 URL |
|---|---|---|---|---|---|---|
| 1 | AUTOSAR_SWS_CANNetworkManagement.pdf | SWS | 2.66 MB | 117 | **核心文档**：CanNm 概念、状态机、定时器、PDU 结构、负载降低、PNC、API、配置规范（Document ID 13） | <https://www.autosar.org/fileadmin/standards/R21-11/CP/AUTOSAR_SWS_CANNetworkManagement.pdf> |
| 2 | AUTOSAR_SWS_NetworkManagementInterface.pdf | SWS | 1.18 MB | 133 | 上层 Nm 接口：ComM 请求如何分发到 CanNm、状态如何上报、多通道协调 | <https://www.autosar.org/fileadmin/standards/R21-11/CP/AUTOSAR_SWS_NetworkManagementInterface.pdf> |
| 3 | AUTOSAR_SWS_CANStateManager.pdf | SWS | 1.93 MB | 105 | CanSM：CAN 控制器状态机、PN 可用性通知、发送超时异常处理 | <https://www.autosar.org/fileadmin/standards/R21-11/CP/AUTOSAR_SWS_CANStateManager.pdf> |
| 4 | AUTOSAR_SWS_CANInterface.pdf | SWS | 1.98 MB | 217 | CanIf：NM PDU 的收发通道、Tx/Rx PDU 配置、TriggerTransmit、发送确认 | <https://www.autosar.org/fileadmin/standards/R21-11/CP/AUTOSAR_SWS_CANInterface.pdf> |
| 5 | AUTOSAR_SWS_COMManager.pdf | SWS | 3.22 MB | 192 | ComM：网络请求/释放的源头、通信模式状态机、与 Nm 的交互 | <https://www.autosar.org/fileadmin/standards/R21-11/CP/AUTOSAR_SWS_COMManager.pdf> |

## 建议后续补充（按需）

| 文档 | 用途 |
|---|---|
| `AUTOSAR_PRS_NetworkManagementProtocol.pdf` | NM 协议总体规范（SWS 引用的输入文档 [2]） |
| `AUTOSAR_RS_NetworkManagement.pdf` | NM 需求（需求追溯） |
| `AUTOSAR_SWS_COM.pdf` | NM 用户数据经 Com 的发送路径（`CanNmComUserDataSupport`） |
| `AUTOSAR_SWS_ECUStateManager.pdf` | 初始化顺序与唤醒源管理 |
| `AUTOSAR_SWS_DiagnosticCommunicationManager.pdf` | 0x28 通信控制到 ComM/Nm 的触发链路 |

## 阅读顺序

1. `AUTOSAR_SWS_CANNetworkManagement.pdf` 第 1、4、5 章（概念、限制、依赖）
2. 第 7.1~7.4（算法、状态机、网络状态、初始化）
3. 第 7.5~7.8（定时参数、PDU 结构、发送接收、负载降低）
4. 第 7.9~7.13（附加特性、PNC、CarWakeup、错误处理）
5. 第 8 章（API/回调/主函数）、第 9 章（时序图）
6. 第 10 章（配置规范，对照 DaVinci 逐项看）
7. SWS_Nm：请求/上报链路；SWS_CanIf：PDU 配置与确认；SWS_CanSM：PN 与超时异常

## 本地文本提取

为便于检索，已用 pypdf 将 PDF 提取为文本（仅本地检索用）：
`C:\Users\11401\Desktop\学习\.tools\tmp\AUTOSAR_SWS_CANNetworkManagement.txt` 等 5 个文件。

## 本地实现代码（非官方文档）

| 项目 | 路径/版本 |
|---|---|
| 生成代码根目录 | `AUTOSAR/AUTOSAT使用NEUSAR生成的代码/` |
| CanNm 源码 | `002_BSW/Bsw_Src/Autosar_Src/src_CanNm/Source/`：`CanNm.c`、`CanNm.h`、`CanNm_Cbk.h`、`CanNm_Cfg.c`、`CanNm_Cfg.h` |
| 调度/类型 | `002_BSW/Bsw_Src/Autosar_Src/src_Rte/Source/SchM_CanNm.h`、`Rte_CanNm_Type.h`；`src_Nm/Source/NmStack_Types.h` |
| 版本 | CanNm 3.14.0 / AUTOSAR 4.2.2（NeuSAR，Neusoft Reach） |
| 说明 | 与 R21-11 文档存在版本差异；变量/函数以代码为准，见 [[CanNm_全局变量说明]]、[[CanNm_函数调用层级]] |

---
tags: [AUTOSAR, BswM, 官方文件]
---

# BswM 官方文档来源清单

> [!info] 导航
> 上级：[[BswM]] ｜ 说明：本页只登记官方 PDF，不参与双链图谱


> 平台：AUTOSAR Classic Platform　版本：R21-11　下载日期：2026-10-17
> 下载站点：<https://www.autosar.org>（文件路径 `/fileadmin/standards/R21-11/CP/`）
> 说明：官方文档版权归 AUTOSAR 所有，仅用于学习研究，不得商用再分发。

## 已下载文档

| 序号 | 文件名 | 类型 | 大小 | 页数 | 说明 | 来源 URL |
|---|---|---|---|---|---|---|
| 1 | AUTOSAR_SWS_BSWModeManager.pdf | SWS | 1.38 MB | 159 | **核心文档**：BswM 功能、API、配置规范（Document ID 313） | <https://www.autosar.org/fileadmin/standards/R21-11/CP/AUTOSAR_SWS_BSWModeManager.pdf> |
| 2 | AUTOSAR_EXP_ModeManagementGuide.pdf | EXP | 617 KB | 73 | 模式管理指南：概念、BswM 配置流程、规则/动作列表示例、启动关机示例（Document ID 440） | <https://www.autosar.org/fileadmin/standards/R21-11/CP/AUTOSAR_EXP_ModeManagementGuide.pdf> |
| 3 | AUTOSAR_SWS_ECUStateManager.pdf | SWS | 2.02 MB | 215 | 交互模块：EcuM 调用 `BswM_Init`、状态/唤醒/关机流程（Document ID 78） | <https://www.autosar.org/fileadmin/standards/R21-11/CP/AUTOSAR_SWS_ECUStateManager.pdf> |
| 4 | AUTOSAR_SWS_COMManager.pdf | SWS | 3.22 MB | 192 | 交互模块：ComM 向 BswM 指示通信模式/PNC、请求复位 | <https://www.autosar.org/fileadmin/standards/R21-11/CP/AUTOSAR_SWS_COMManager.pdf> |
| 5 | AUTOSAR_SWS_BSWGeneral.pdf | SWS | 606 KB | 88 | 通用规范：错误分类、配置规范读法、初始化约定 | <https://www.autosar.org/fileadmin/standards/R21-11/CP/AUTOSAR_SWS_BSWGeneral.pdf> |

## 未下载但建议后续补充（按需）

| 文档 | 用途 |
|---|---|
| `AUTOSAR_SWS_RTE.pdf` | 模式切换/模式请求在 RTE 中的生成规则（学习 SwitchPort 时必读） |
| `AUTOSAR_SRS_ModeManagement.pdf` | 模式管理需求条目（对照 SWS 需求追溯） |
| `AUTOSAR_SWS_COM.pdf` | 深入理解 `Com_IpduGroupStart/Stop`、deadline monitoring |
| `AUTOSAR_SWS_PDUR.pdf` | 理解 `PduR_EnableRouting/DisableRouting` 与路由路径组 |
| `AUTOSAR_SWS_NVRAMManager.pdf` | 理解 `NvM_ReadAll/WriteAll` 与 BswM 的配合 |

> 注：`AUTOSAR_SRS_BSWModeManager.pdf`、`AUTOSAR_TR_BSWModeManager.pdf`、`AUTOSAR_SWS_ComManager.pdf`（大小写变体）在 R21-11 CP 目录下**不存在**（404），BswM 没有独立的 SRS/TR 文档，需求分散在 `SRS_ModeManagement` 中。

## 阅读顺序

1. `AUTOSAR_SWS_BSWModeManager.pdf` 第 1 章 → 第 5 章（概览与依赖）
2. 第 7 章（功能：仲裁、控制、定时器、端口）
3. 第 9 章（时序图：immediate vs deferred）
4. 第 10 章（配置规范，对照 DaVinci 配置项逐个看）
5. `AUTOSAR_EXP_ModeManagementGuide.pdf` 第 3 章（配置流程/语义）、第 4 章（完整启动关机示例）
6. `AUTOSAR_SWS_ECUStateManager.pdf` 第 7.9 节（STARTUP 中 BswM 的位置）
7. `AUTOSAR_SWS_COMManager.pdf` 中 `BswM_ComM_*` 相关段落

## 本地文本提取

为便于检索，已用 pypdf 将 PDF 提取为文本（仅本地检索用，未放入交付目录）：
`C:\Users\11401\Desktop\学习\.tools\tmp\*.txt`。

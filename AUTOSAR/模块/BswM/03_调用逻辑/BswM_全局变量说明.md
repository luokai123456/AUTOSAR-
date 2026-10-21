---
tags: [AUTOSAR, BswM, 调用逻辑]
---
# BswM 全局变量说明

> [!info] 导航
> 上级：[[BswM_调用逻辑总览]] ｜ 依赖：[[BswM_函数调用层级]] ｜ 依据：[[BswM_配置参数表_R21-11]]

> 适用版本：AUTOSAR CP R21-11　依据：SWS_BswM 8.2、8.3、10.2；生成代码结构
> 最后更新：2026-10-21

> 说明：AUTOSAR 不规定变量命名，下面是生成代码的典型结构（DaVinci 生成 `BswM_Lcfg.c` / `BswM_PBcfg.c` / `BswM_Cfg.h`）。

## 1. 配置数据（只读）

| 变量/结构 | 典型位置 | 作用 | 写者 | 读者 |
|---|---|---|---|---|
| `BswM_ConfigPtr` | `BswM.c` | 当前选中的配置集（post-build 切换） | `BswM_Init` | 所有函数 |
| `BswMConfig` 实例 | `BswM_PBcfg.c` | 每个分区一份配置（多分区） | 生成时固定 | 主函数/动作执行 |
| Mode Request Port 配置表 | 配置结构 | 端口类型/来源/处理方式/初值 | 生成时固定 | 仲裁、输入 API |
| Event Request Port 配置表 | 配置结构 | 事件来源与处理方式 | 生成时固定 | 事件 API、仲裁 |
| Condition / Expression 表 | 配置结构 | 条件类型、引用端口、比较值；逻辑运算符与参数引用 | 生成时固定 | 规则求值 |
| Rule 表 | 配置结构 | 表达式引用、True/False 列表、`BswMRuleInitState`、`BswMNestedExecutionOnly` | 生成时固定 | 仲裁 |
| ActionList / Item 表 | 配置结构 | 执行方式、优先级、Item 索引与引用类型 | 生成时固定 | 动作调度 |
| Action 表 | 配置结构 | 各动作参数（PDU 组、ComM User、NvM Block…） | 生成时固定 | 动作执行 |
| Timer 配置 | 配置结构 | 定时器句柄与值 | 生成时固定 | 定时器控制 |
| SwitchPort / RteModeRequestPort | 配置结构 | 对外模式切换/请求端口描述 | 生成时固定 | 动作执行/RTE |

> 配置数据与 DaVinci 参数一一对应，见 [[BswM_DaVinci配置项]] 与 [[BswM_配置参数表_R21-11]]。

## 2. 运行状态（可写）

| 变量/结构 | 作用 | 写者 | 读者 | 生命周期 |
|---|---|---|---|---|
| `BswM_Initialized`（模块级标志） | 是否已初始化（未初始化 API 报 `BSWM_E_UNINIT`） | `BswM_Init` / `BswM_Deinit` | 所有 API、主函数 | 初始化→反初始化 |
| Mode Request Port 值数组 | 各端口当前模式值/未定义标志 | 输入 API/回调（D2）；IMMEDIATE 在仲裁前更新、DEFERRED 触发时更新 | 规则求值 | 运行期 |
| Event Port 状态数组 | CLEAR / SET | 事件 API 置 SET、`BswMClearEventRequest` 清 CLEAR | 规则求值 | 运行期 |
| Rule 上次结果数组 | 每条规则的 UNDEFINED/TRUE/FALSE | 规则求值（D3） | 下一轮比较 | 运行期 |
| Timer 状态数组 | STOPPED/STARTED/EXPIRED + 剩余时间 | 定时器动作/主函数递减 | 仲裁 | 运行期 |
| 待执行列表集合 | 本轮命中的动作列表（去重标志） | 仲裁（D3） | 动作调度（D4） | 单个处理周期 |
| 挂起请求标志/队列 | 执行期间到达的 IMMEDIATE/DEFERRED 请求 | 输入 API/回调 | 主函数退出前/下一周期 | 处理周期 |
| ActionList 触发状态 | 避免同一顶层列表重复触发 | 调度（D4） | 调度 | 单轮执行 |

## 3. 读写与并发

1. **主函数 vs 请求上下文**：IMMEDIATE 请求可能在调用者（甚至中断）上下文更新端口/执行动作，与主函数共享数据 → 实现通常用 SchM 临界区/Exclusive Area 保护。
2. **不可重入**：`BswM_MainFunction` 不可重入；主函数执行期间到达的请求会被挂起（00068/00069），避免动作列表执行被打断。
3. **多分区**：每个分区一个 BswM 实例与配置，动作只影响本分区资源（7.4）。
4. **动作返回值**：BswM 不保存动作返回状态，只按 `AbortOnFail`/Det 配置处理（见 D4）。
5. **post-build**：`BswM_ConfigPtr` 在 `BswM_Init` 时选定，运行期不切换。

## 4. 观测建议

- 调试时看：端口值数组、事件端口状态、规则上次结果、待执行列表；
- 上电规则不生效：优先看端口是否"未定义"；
- 动作顺序问题：看 ItemIndex/优先级（配置数据）；
- 定时器行为：看状态数组与 `BswMMainFunctionPeriod` 是否一致。

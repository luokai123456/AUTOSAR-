# -*- coding: utf-8 -*-
"""把 CanNm 标准需求表按需求号百位重构为分组表（便于 Obsidian 锚点跳转）。"""
import re
import os

P = r"C:\Users\11401\Desktop\学习\AUTOSAR\模块\CanNm\05_标准表格\CanNm_AUTOSAR标准需求表_R21-11.md"
text = open(P, encoding="utf-8").read()

rows = []
seen = set()
for line in text.split("\n"):
    m = re.match(r"^\|\s*(SWS_CanNm_(\d{5}))\s*\|(.*)$", line.strip())
    if not m:
        continue
    rid, num, rest = m.group(1), m.group(2), m.group(3)
    if rid in seen:
        continue
    seen.add(rid)
    rows.append((int(num), rid, line.strip()))

rows.sort(key=lambda x: x[0])
print("rows:", len(rows), "range:", rows[0][0], "-", rows[-1][0])

groups = []
for n, rid, line in rows:
    key = "910xx" if n >= 90000 else "%03dxx" % (n // 100)
    if not groups or groups[-1][0] != key:
        groups.append([key, []])
    groups[-1][1].append((n, rid, line))

def short(key):
    if key == "910xx":
        return "910xx"
    return key

header = """---
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
"""

for key, items in groups:
    ids = [i[0] for i in items]
    rng = "%05d–%05d" % (min(ids), max(ids))
    header += "| [[#SWS_CanNm_%s\\|SWS_CanNm_%s]] | %s | %d |\n" % (key, key, rng, len(items))

header += "\n## 3. 需求表\n"

body = ""
for key, items in groups:
    body += "\n### SWS_CanNm_%s\n\n| 需求号 | 章节 | 中文说明 |\n|---|---|---|\n" % key
    for n, rid, line in items:
        # line: | SWS_CanNm_00005 | 7.7.1 | xxx |
        cells = [c.strip() for c in line.strip("|").split("|")]
        if len(cells) < 3:
            cells = [rid, "", ""]
        body += "| %s | %s | %s |\n" % (cells[0], cells[1], cells[2])

tail = """
## 4. 覆盖度统计

| 指标 | 数值 | 说明 |
|---|---|---|
| 需求块总数 | %d | 正文 + 补充（DRAFT/OBSOLETE）全部去重 |
| 分组数 | %d | 按需求号百位 |
| 配置约束（CONSTR） | 0 | 本 SWS 无 |
| 配置参数（ECUC） | 72 | 见 [[CanNm_配置参数表_R21-11]] |
| 需求追溯条目（RS_Nm） | 45 | 见 [[CanNm_需求追溯与覆盖度]] |
| 覆盖 | %d / %d | 全部整理 |

> 统计口径：SWS 正文以 `[SWS_CanNm_xxxxx]` 开头、后接 `⌈` 的需求块（含 `{DRAFT}`/`{OBSOLETE}` 标记行）；第 6 章追溯表中仅被引用的 ID 不计入本表。
""" % (len(rows), len(groups), len(rows), len(rows))

open(P, "w", encoding="utf-8").write(header + body + "\n" + tail)
print("written groups:", [g[0] for g in groups])
print("row count:", len(rows))

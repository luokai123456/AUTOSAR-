# -*- coding: utf-8 -*-
"""为 CanNm 文档添加 v3 导航块（Obsidian 双链）、frontmatter，并移除旧“关联文档”长列表。"""
import os
import re

ROOT = r"C:\Users\11401\Desktop\学习\AUTOSAR\模块\CanNm"

TAGS = {
    "02_学习总结": "学习总结",
    "03_调用逻辑": "调用逻辑",
    "04_MainFunction流程": "主函数",
    "05_标准表格": "标准表格",
}

NAV = {
    "CanNm_模块作用与架构定位.md": (
        "学习总结",
        "> [!info] 导航\n"
        "> 上级：[[CanNm]] ｜ 依赖：[[CanNm_D3_主状态转移逻辑]]、[[CanNm_D4_状态转换表]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11#SWS_CanNm_000xx|需求表]]",
    ),
    "CanNm_DaVinci配置项.md": (
        "学习总结",
        "> [!info] 导航\n"
        "> 上级：[[CanNm]] ｜ 依赖：[[CanNm_配置参数表_R21-11]]、[[CanNm_D4_状态转换表]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11]]",
    ),
    "CanNm_BusLoadReductionActive说明.md": (
        "学习总结",
        "> [!info] 导航\n"
        "> 上级：[[CanNm]] ｜ 依赖：[[CanNm_D5_周期发送与降载调用逻辑]]、[[CanNm_D3_主状态转移逻辑]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11#SWS_CanNm_000xx|需求表]]",
    ),
    "CanNm_一页纸复盘.md": (
        "学习总结",
        "> [!info] 导航\n"
        "> 上级：[[CanNm]] ｜ 依赖：[[CanNm_调用逻辑总览]]、[[CanNm_D4_状态转换表]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11]]",
    ),
    "CanNm_调用逻辑总览.md": (
        "调用逻辑",
        "> [!info] 导航\n"
        "> 上级：[[CanNm]] ｜ 下级：[[CanNm_D1_主动唤醒调用逻辑]]、[[CanNm_D2_被动唤醒调用逻辑]]、[[CanNm_D3_主状态转移逻辑]]、[[CanNm_D4_状态转换表]]、[[CanNm_D5_周期发送与降载调用逻辑]]、[[CanNm_D6_通信控制调用逻辑]]、[[CanNm_D7_扩展特性调用逻辑]]",
    ),
    "CanNm_D1_主动唤醒调用逻辑.md": (
        "调用逻辑",
        "> [!info] 导航\n"
        "> 上级：[[CanNm_调用逻辑总览]] ｜ 依赖：[[CanNm_D3_主状态转移逻辑]]、[[CanNm_D4_状态转换表#从 Bus-Sleep 出发]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11#SWS_CanNm_001xx|需求表]]",
    ),
    "CanNm_D2_被动唤醒调用逻辑.md": (
        "调用逻辑",
        "> [!info] 导航\n"
        "> 上级：[[CanNm_调用逻辑总览]] ｜ 依赖：[[CanNm_D3_主状态转移逻辑]]、[[CanNm_D4_状态转换表#从 Bus-Sleep 出发]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11#SWS_CanNm_001xx|需求表]]",
    ),
    "CanNm_D3_主状态转移逻辑.md": (
        "调用逻辑",
        "> [!info] 导航\n"
        "> 上级：[[CanNm_调用逻辑总览]] ｜ 依赖：[[CanNm_D4_状态转换表]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11#SWS_CanNm_000xx|需求表]]",
    ),
    "CanNm_D5_周期发送与降载调用逻辑.md": (
        "调用逻辑",
        "> [!info] 导航\n"
        "> 上级：[[CanNm_调用逻辑总览]] ｜ 依赖：[[CanNm_D4_状态转换表]]、[[CanNm_BusLoadReductionActive说明]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11#SWS_CanNm_000xx|需求表]]",
    ),
    "CanNm_D6_通信控制调用逻辑.md": (
        "调用逻辑",
        "> [!info] 导航\n"
        "> 上级：[[CanNm_调用逻辑总览]] ｜ 依赖：[[CanNm_D3_主状态转移逻辑]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11#SWS_CanNm_001xx|需求表]]",
    ),
    "CanNm_D7_扩展特性调用逻辑.md": (
        "调用逻辑",
        "> [!info] 导航\n"
        "> 上级：[[CanNm_调用逻辑总览]] ｜ 依赖：[[CanNm_D4_状态转换表]]、[[CanNm_D5_周期发送与降载调用逻辑]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11#SWS_CanNm_004xx|需求表]]",
    ),
    "CanNm_函数调用层级.md": (
        "调用逻辑",
        "> [!info] 导航\n"
        "> 上级：[[CanNm_调用逻辑总览]] ｜ 依赖：[[CanNm_MainFunction调用逻辑]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11#SWS_CanNm_002xx|需求表]]",
    ),
    "CanNm_全局变量说明.md": (
        "调用逻辑",
        "> [!info] 导航\n"
        "> 上级：[[CanNm_调用逻辑总览]] ｜ 依赖：[[CanNm_函数调用层级]] ｜ 依据：[[CanNm_配置参数表_R21-11]]",
    ),
    "CanNm_MainFunction调用逻辑.md": (
        "主函数",
        "> [!info] 导航\n"
        "> 上级：[[CanNm]] ｜ 依赖：[[CanNm_调用逻辑总览]] ｜ 依据：[[CanNm_D4_状态转换表]]",
    ),
    "CanNm_配置参数表_R21-11.md": (
        "标准表格",
        "> [!info] 导航\n"
        "> 上级：[[CanNm]] ｜ 依赖：[[CanNm_DaVinci配置项]] ｜ 依据：[[CanNm_AUTOSAR标准需求表_R21-11]]",
    ),
    "CanNm_需求追溯与覆盖度.md": (
        "标准表格",
        "> [!info] 导航\n"
        "> 上级：[[CanNm]] ｜ 依赖：[[CanNm_AUTOSAR标准需求表_R21-11]] ｜ 依据：SWS 第 6 章（Requirements Traceability）与第 12 章",
    ),
    "CanNm_问题排查记录.md": (
        "问题排查",
        "> [!info] 导航\n"
        "> 上级：[[CanNm]] ｜ 依赖：[[CanNm_DaVinci配置项]]、[[CanNm_调用逻辑总览]]",
    ),
    "CanNm_来源清单.md": (
        "官方文件",
        "> [!info] 导航\n"
        "> 上级：[[CanNm]] ｜ 说明：本页只登记官方 PDF，不参与双链图谱",
    ),
}

SECTION_RE = re.compile(r"\n## (?:\d+\. )?关联文档\s*\n.*?(?=\n## |\Z)", re.S)


def ensure_frontmatter(text, tag):
    if text.startswith("---\n"):
        return text
    fm = "---\ntags: [AUTOSAR, CanNm, %s]\n---\n\n" % tag
    return fm + text


def insert_nav(text, nav):
    if "> [!info] 导航" in text:
        return text
    lines = text.split("\n")
    for i, line in enumerate(lines):
        if line.startswith("# "):
            lines[i + 1:i + 1] = ["", nav, ""]
            return "\n".join(lines)
    return nav + "\n\n" + text


changed = []
for dirpath, _, filenames in os.walk(ROOT):
    for fn in filenames:
        if not fn.endswith(".md"):
            continue
        if fn in ("CanNm.md",):
            continue
        if fn not in NAV:
            continue
        path = os.path.join(dirpath, fn)
        tag, nav = NAV[fn]
        with open(path, encoding="utf-8") as f:
            text = f.read()
        new = insert_nav(ensure_frontmatter(text, tag), nav)
        new = SECTION_RE.sub("\n", new)
        new = re.sub(r"\n{3,}", "\n\n", new).rstrip() + "\n"
        if new != text:
            with open(path, "w", encoding="utf-8") as f:
                f.write(new)
            changed.append(fn)

print("updated:", len(changed))
for c in changed:
    print(" -", c)

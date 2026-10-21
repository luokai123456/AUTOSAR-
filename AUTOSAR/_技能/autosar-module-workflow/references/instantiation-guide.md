# 实例化指南（EcuM / Com 复用）

> 目标：从 `CANNM标准化流程.xlsx` 一键生成 `<模块名>标准化流程.xlsx`，保留流程结构与甘特，替换模块名并清空模块特定内容。

## 1. 命令

```bash
# 在仓库根目录执行（PowerShell/Bash 均可）
python AUTOSAR/_技能/autosar-module-workflow/scripts/instantiate_workbook.py \
  --source "AUTOSAR/00_学习路线/CANNM标准化流程.xlsx" \
  --target "AUTOSAR/00_学习路线/EcuM标准化流程.xlsx" \
  --module EcuM

python AUTOSAR/_技能/autosar-module-workflow/scripts/validate_workbook.py \
  "AUTOSAR/00_学习路线/EcuM标准化流程.xlsx" --module EcuM
```

## 2. 实例化脚本做了什么

1. 替换所有单元格文本：`CANNM` → 模块大写、`CanNm` → 模块名（含需求号 `SWS_CanNm_*` → `SWS_EcuM_*`、`ECUC_CanNm_*` 同理）；
2. **清空并重置**以下 Sheet 的模块内容（保留表头与样式）：
   - `4-需求追溯矩阵`：1 行模板行；
   - `5-差异台账`：`DIF-001` 模板行；
   - `6-测试用例与CAPL`：`TC-001` 模板行；
   - `7-问题台账`：`Q-001` 模板行；
   - `8-评审记录`：日期清空、结论置“待评审”；
   - `10-基线清单`：`BL-001/002` 模板行；
   - `1-文件变更履历`：改为“实例化”记录；
3. 保留 `3-开发计划` 的 P0~P6 结构（任务名称中的模块名已替换），日期沿用模板，按项目调整；
4. 重建 `13-甘特视图`（标题含新模块名）。

## 3. 实例化后必须做

1. `3-开发计划`：按项目改计划开始/完成、责任人、关联需求；
2. `0-使用说明` / `0a-目录说明`：确认模块名、基线、工具版本；
3. `4-需求追溯矩阵`：按该模块 SWS 需求号逐步补全（可先引用 Obsidian 需求表）；
4. `10-基线清单`：填 AUTOSAR / 工具 / BSWMD-ECUC 版本；
5. 修改计划日期后刷新甘特：

```bash
python AUTOSAR/_技能/autosar-module-workflow/scripts/refresh_gantt.py \
  "AUTOSAR/00_学习路线/EcuM标准化流程.xlsx" --module EcuM
```

6. 运行校验，PASS 后提交。

## 4. 与 Obsidian 工作区联动

- 新模块先在 Obsidian 建档：`模块/<模块名>/<模块名>.md`（复制 `_模块模板`），完成 7 项交付物；
- 工作簿是过程管理入口，需求号/用例号与 Obsidian 文档双向引用；
- 建议新增 `06_测试与验证/` 存放 TC 与 CAPL（当前模板未内置，可在模块目录按需建）。

## 5. 注意事项

- 不要在源 `CANNM标准化流程.xlsx` 上直接实例化覆盖；
- 实例化后用 `validate_workbook.py --module <模块名>` 校验前缀；
- 若模块名大小写与需求号前缀不一致（如 `CanNm` vs `CANNM`），以 SWS 文件名中的写法为准（实例化时 `--module` 用 `CanNm`）。

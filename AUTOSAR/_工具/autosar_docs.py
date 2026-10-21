# -*- coding: utf-8 -*-
"""
AUTOSAR 官方文档下载 / 文本提取 小工具（学习工作区专用）

用法示例：
    python autosar_docs.py --module BswM --docs AUTOSAR_SWS_BSWModeManager.pdf
    python autosar_docs.py --module Com --docs AUTOSAR_SWS_COM.pdf AUTOSAR_SWS_PDUR.pdf --no-extract
    python autosar_docs.py --release R22-11 --module Com --docs AUTOSAR_SWS_COM.pdf

说明：
1. 从 https://www.autosar.org/fileadmin/standards/<release>/<platform>/ 下载 PDF 到
   AUTOSAR/模块/<module>/01_官方文件/。
2. 默认顺便用 pypdf 提取文本到 AUTOSAR/../.tools/tmp/<pdf>.txt，方便检索。
3. 官网 TLS 证书在部分网络环境下校验失败，这里统一跳过证书校验（仅下载公开标准文档）。
"""
import argparse
import os
import ssl
import sys
import urllib.request

HERE = os.path.dirname(os.path.abspath(__file__))          # AUTOSAR/_工具
ROOT = os.path.dirname(HERE)                                # AUTOSAR
TOOLS = os.path.dirname(ROOT)                               # 学习
PYPDF_DIR = os.path.join(TOOLS, ".tools", "pypdf")
TXT_DIR = os.path.join(TOOLS, ".tools", "tmp")
URL = "https://www.autosar.org/fileadmin/standards/{release}/{platform}/{name}"


def ctx():
    c = ssl.create_default_context()
    c.check_hostname = False
    c.verify_mode = ssl.CERT_NONE
    return c


def download(release, platform, module, names):
    outdir = os.path.join(ROOT, "模块", module, "01_官方文件")
    os.makedirs(outdir, exist_ok=True)
    ok = 0
    for name in names:
        url = URL.format(release=release, platform=platform, name=name)
        try:
            req = urllib.request.Request(url, headers={"User-Agent": "Mozilla/5.0"})
            data = urllib.request.urlopen(req, timeout=120, context=ctx()).read()
        except Exception as e:                                   # noqa: BLE001
            print("[FAIL] %s -> %s" % (name, e))
            continue
        if not data.startswith(b"%PDF"):
            print("[FAIL] %s 不是 PDF（可能 404 页面），已跳过" % name)
            continue
        path = os.path.join(outdir, name)
        with open(path, "wb") as f:
            f.write(data)
        print("[OK]   %-55s %9d bytes" % (name, len(data)))
        ok += 1
    return ok


def extract(module):
    if not os.path.isdir(PYPDF_DIR):
        print("[warn] 未找到 pypdf，跳过文本提取：%s" % PYPDF_DIR)
        return
    sys.path.insert(0, PYPDF_DIR)
    from pypdf import PdfReader
    srcdir = os.path.join(ROOT, "模块", module, "01_官方文件")
    os.makedirs(TXT_DIR, exist_ok=True)
    for name in sorted(os.listdir(srcdir)):
        if not name.lower().endswith(".pdf"):
            continue
        src = os.path.join(srcdir, name)
        dst = os.path.join(TXT_DIR, os.path.splitext(name)[0] + ".txt")
        try:
            reader = PdfReader(src)
            text = "\n\f\n".join((p.extract_text() or "") for p in reader.pages)
            with open(dst, "w", encoding="utf-8") as f:
                f.write(text)
            print("[TXT]  %-55s %d pages" % (name, len(reader.pages)))
        except Exception as e:                                   # noqa: BLE001
            print("[TXT-FAIL] %s -> %s" % (name, e))


def main():
    ap = argparse.ArgumentParser(description="下载 AUTOSAR 官方 PDF 并提取文本")
    ap.add_argument("--release", default="R21-11")
    ap.add_argument("--platform", default="CP")
    ap.add_argument("--module", required=True, help="模块文件夹名，如 BswM / Com / NvM")
    ap.add_argument("--docs", nargs="+", required=True, help="PDF 文件名列表")
    ap.add_argument("--no-extract", action="store_true")
    args = ap.parse_args()

    print("release=%s platform=%s module=%s" % (args.release, args.platform, args.module))
    ok = download(args.release, args.platform, args.module, args.docs)
    if ok and not args.no_extract:
        extract(args.module)
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())

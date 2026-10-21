# -*- coding: utf-8 -*-
import re, json
P = r"C:\Users\11401\Desktop\学习\.tools\tmp\AUTOSAR_SWS_BSWModeManager.txt"
lines = open(P, encoding="utf-8").read().split("\n")

def is_heading(s):
    if "of 159" in s or "Document ID" in s: return False
    m = re.match(r"^(\d+(?:\.\d+){0,3})\s+([A-Z][A-Za-z].{2,80})$", s)
    return m.group(1) if m else None

page = 1; sec = ""; cur = None; buf = []; out = []
for ln in lines:
    page += ln.count("\f"); s = ln.strip()
    h = is_heading(s)
    if h: sec = h
    if cur is None:
        mm = re.search(r"SWS_BswM_((?:CONSTR_)?\d{5})\]\s*(?:\{[^}]*\}\s*)?[\u2308]", s)
        if mm:
            cur = "SWS_BswM_" + mm.group(1); rest = s[mm.end():]
            if "\u230b" in rest:
                out.append((cur, rest.split("\u230b")[0], sec, page)); cur = None
            else: buf = [rest]
    else:
        if "\u230b" in s:
            buf.append(s.split("\u230b")[0]); out.append((cur, " ".join(buf), sec, page)); cur = None; buf = []
        else: buf.append(s)
uniq = {}
for rid, txt, sc, pg in out:
    if rid not in uniq:
        uniq[rid] = {"id": rid, "text": re.sub(r"\s+", " ", txt).strip(), "section": sc, "page": pg}
reqs = sorted(uniq.values(), key=lambda r: (0 if "CONSTR" in r["id"] else 1, int(r["id"].split("_")[-1])))
json.dump(reqs, open(r"C:\Users\11401\Desktop\学习\.tools\tmp\bswm_reqs.json", "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("requirements:", len(reqs), "constr:", sum(1 for r in reqs if "CONSTR" in r["id"]))
from collections import Counter
print("sections:", Counter(r["section"].split(".")[0] for r in reqs))

with open(r"C:\Users\11401\Desktop\学习\.tools\tmp\bswm_reqs_compact.txt", "w", encoding="utf-8") as f:
    for r in reqs:
        f.write("%s | %s | %s\n" % (r["id"], r["section"], r["text"][:180]))

# ECUC
text = "\n".join(lines)
blocks = re.split(r"(?=SWS Item\s+ECUC_BswM_\d{5})", text)
ecuc = []
for b in blocks:
    m = re.match(r"SWS Item\s+(ECUC_BswM_\d{5})", b.strip())
    if not m: continue
    pid = m.group(1)
    nm = re.search(r"\nName\s*\n+\s*(\w+)\s*\n", b)
    pc = re.search(r"Parent Container\s+([\w\s]+?)\s*\n", b)
    desc = re.search(r"Description\s+(.{5,300}?)(?:\n\s*\n|\nMultiplicity|\nType)", b, re.S)
    ecuc.append({"id": pid, "name": nm.group(1).strip() if nm else "",
                 "container": pc.group(1).strip() if pc else "",
                 "desc": re.sub(r"\s+", " ", desc.group(1)).strip() if desc else ""})
json.dump(ecuc, open(r"C:\Users\11401\Desktop\学习\.tools\tmp\bswm_ecuc.json", "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("ecuc:", len(ecuc), "named:", sum(1 for e in ecuc if e["name"]))
with open(r"C:\Users\11401\Desktop\学习\.tools\tmp\bswm_ecuc_compact.txt", "w", encoding="utf-8") as f:
    for e in ecuc:
        f.write("%s | %s | %s | %s\n" % (e["id"], e["name"], e["container"], e["desc"][:100]))

# trace chapter 6
starts = [i for i, l in enumerate(lines) if l.strip().startswith("6 Requirements")]
end = next(i for i, l in enumerate(lines) if l.strip().startswith("7 Functional specification") and i > starts[-1])
seg = lines[starts[-1]:end]
trace = []; cur = None; desc = []; sws = []
for l in seg:
    s = l.strip()
    m = re.match(r"^\[?(SRS_[A-Za-z]+_\d{5})\]?\s*(.*)", s)
    if m:
        if cur: trace.append({"srs": cur, "desc": " ".join(desc).strip(), "sws": sws})
        cur = m.group(1); desc = [m.group(2)] if m.group(2) else []; sws = []; continue
    if cur:
        ids = re.findall(r"SWS_BswM_(?:CONSTR_)?\d{5}", s)
        if ids: sws.extend(ids)
        elif s and not s.startswith(("Specification of", "AUTOSAR CP", "of 159", "Document ID", "Requirement Description", "Satisfied by")):
            desc.append(s)
if cur: trace.append({"srs": cur, "desc": " ".join(desc).strip(), "sws": sws})
json.dump(trace, open(r"C:\Users\11401\Desktop\学习\.tools\tmp\bswm_trace.json", "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("trace entries:", len(trace))
for t in trace[:5]:
    print(t["srs"], "|", t["desc"][:60], "|", ",".join(t["sws"])[:70])

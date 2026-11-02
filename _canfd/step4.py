import numpy as np
from PIL import Image

src = r"C:\Users\11401\.dsh\attachments\v1\objects\8d\8d62f836478f02f70142fe9408fc6b7e3e3754fd0fd6032988b25d17fa7cee54"
im = np.asarray(Image.open(src).convert("RGB")).astype(int)
g = im.max(axis=2)
H, W = g.shape

top = g[178:184, :].max(axis=0)
bot = g[288:294, :].max(axis=0)
TH = 90
lv = np.full(W, -1, dtype=int)   # -1 unknown
lv[(top > TH) & (bot <= TH)] = 1
lv[(bot > TH) & (top <= TH)] = 0
# both -> edge/transition; neither -> unknown
print("unknown cols:", (lv == -1).sum())

# print runs
runs = []
cur = lv[0]; start = 0
for x in range(1, W):
    if lv[x] != cur:
        runs.append((start, x - start, cur))
        cur = lv[x]; start = x
runs.append((start, W - start, cur))
for s, n, v in runs:
    print(f"x={s:4d} len={n:3d} lvl={'H' if v==1 else ('L' if v==0 else '?')}")

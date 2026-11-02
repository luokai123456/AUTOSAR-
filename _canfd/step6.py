import numpy as np
from PIL import Image

src = r"C:\Users\11401\.dsh\attachments\v1\objects\8d\8d62f836478f02f70142fe9408fc6b7e3e3754fd0fd6032988b25d17fa7cee54"
im = np.asarray(Image.open(src).convert("RGB")).astype(int)
g = im.max(axis=2)
W = g.shape[1]

side = [x for x in range(W) if g[173, x] > 90 and g[174, x] > 90 and g[175, x] > 90]
print("side cols:", side)
print("count:", len(side))
# group consecutive
groups = []
for x in side:
    if groups and x - groups[-1][-1] <= 1:
        groups[-1].append(x)
    else:
        groups.append([x])
print("groups:", [(g0[0], g0[-1]) for g0 in groups])

import numpy as np
from PIL import Image

src = r"C:\Users\11401\.dsh\attachments\v1\objects\8d\8d62f836478f02f70142fe9408fc6b7e3e3754fd0fd6032988b25d17fa7cee54"
im = np.asarray(Image.open(src).convert("RGB")).astype(int)
H, W, _ = im.shape
bright = im.max(axis=2) > 140
rowcount = bright.sum(axis=1)
print("rows with count>4:")
for y in range(H):
    if rowcount[y] > 4:
        print(y, rowcount[y])
print("--- unique colors (most common) ---")
flat = im.reshape(-1,3)
uniq, cnt = np.unique(flat, axis=0, return_counts=True)
idx = np.argsort(-cnt)[:15]
for i in idx:
    print(tuple(uniq[i]), cnt[i])

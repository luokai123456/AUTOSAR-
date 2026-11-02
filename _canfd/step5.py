import numpy as np
from PIL import Image

src = r"C:\Users\11401\.dsh\attachments\v1\objects\8d\8d62f836478f02f70142fe9408fc6b7e3e3754fd0fd6032988b25d17fa7cee54"
im = np.asarray(Image.open(src).convert("RGB")).astype(int)
g = im.max(axis=2)
W = g.shape[1]

# annotation band: find rows of boxes
for y in range(154, 180):
    row = g[y]
    bright = (row > 90).sum()
    print(y, bright, "".join("#" if v>90 else ("." if v>25 else " ") for v in row[:120]))

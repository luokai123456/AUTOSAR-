import numpy as np
from PIL import Image

src = r"C:\Users\11401\.dsh\attachments\v1\objects\8d\8d62f836478f02f70142fe9408fc6b7e3e3754fd0fd6032988b25d17fa7cee54"
im = np.asarray(Image.open(src).convert("RGB")).astype(int)
g = im.max(axis=2)
W = g.shape[1]

top = g[178:184, :].max(axis=0)
bot = g[288:294, :].max(axis=0)
TH = 90
for x in range(985, 1060):
    print(x, int(top[x]), int(bot[x]), "TOP" if top[x]>TH else "", "BOT" if bot[x]>TH else "")

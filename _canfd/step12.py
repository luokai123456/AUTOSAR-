import numpy as np
from PIL import Image

src = r"C:\Users\11401\.dsh\attachments\v1\objects\8d\8d62f836478f02f70142fe9408fc6b7e3e3754fd0fd6032988b25d17fa7cee54"
im = np.asarray(Image.open(src).convert("RGB")).astype(int)
g = im.max(axis=2)
W = g.shape[1]
top = g[178:184, :].max(axis=0)
bot = g[288:294, :].max(axis=0)
TH = 90

def level(x):
    t = top[x] > TH; b = bot[x] > TH
    if t and b: return None
    if t: return 1
    if b: return 0
    return None

def sample_bits(x_start, b, n):
    bits = []
    for k in range(n):
        c = x_start + b*(k+0.5)
        xi = int(round(c))
        # look at a small window around center to avoid edge columns
        vals = [level(x) for x in range(max(0,xi-1), min(W, xi+2))]
        vals = [v for v in vals if v is not None]
        bits.append(sum(vals)/len(vals) if vals else None)
    return bits

def show(name, x_start, b, n):
    bits = sample_bits(x_start, b, n)
    s = "".join("?" if v is None else ("1" if v>0.5 else "0") for v in bits)
    print(f"{name}: start={x_start} bit={b:.3f}")
    print("  " + s)
    return s

# nominal phase fits: frame B grid start 245.5, b=7.14 ; frame C start 901.5
show("B nominal", 245.5, 7.14, 18)
show("C nominal", 901.9, 7.14, 18)
# data phase
show("B data", 367.0, 1.785, 40)

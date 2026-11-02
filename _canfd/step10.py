import numpy as np
from PIL import Image

src = r"C:\Users\11401\.dsh\attachments\v1\objects\8d\8d62f836478f02f70142fe9408fc6b7e3e3754fd0fd6032988b25d17fa7cee54"
im = np.asarray(Image.open(src).convert("RGB")).astype(int)
g = im.max(axis=2)

def dump(x0, x1, y0, y1, label=""):
    print(f"=== {label} x {x0}..{x1} y {y0}..{y1}")
    print("     " + "".join(str((x0+i)//100 % 10) for i in range(x1-x0)))
    print("     " + "".join(str((x0+i)//10 % 10) for i in range(x1-x0)))
    print("     " + "".join(str((x0+i) % 10) for i in range(x1-x0)))
    for y in range(y0, y1):
        row = ""
        for x in range(x0, x1):
            v = g[y, x]
            if v > 200: c = "#"
            elif v > 140: c = "+"
            elif v > 80: c = "*"
            elif v > 40: c = "."
            else: c = " "
            row += c
        print(f"{y:4d} {row}")

dump(0, 80, 155, 180, "frame A tail")
dump(645, 730, 155, 180, "frame B tail")
dump(240, 345, 155, 180, "frame B head")

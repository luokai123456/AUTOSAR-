import os
from PIL import Image

src = r"C:\Users\11401\.dsh\attachments\v1\objects\8d\8d62f836478f02f70142fe9408fc6b7e3e3754fd0fd6032988b25d17fa7cee54"
out = r"C:\Users\11401\Desktop\学习\_canfd"
os.makedirs(out, exist_ok=True)
im = Image.open(src).convert("RGB")
W, H = im.size
print("size", W, H)

def crop(name, box, scale, resample=Image.LANCZOS):
    c = im.crop(box)
    c = c.resize((c.width*scale, c.height*scale), resample)
    p = os.path.join(out, name)
    c.save(p)
    print(p, c.size)

# annotation band
for i, (x0, x1) in enumerate([(0,320),(300,620),(600,920),(900,1216)]):
    crop(f"lab_{i}.png", (x0, 138, x1, 180), 8)

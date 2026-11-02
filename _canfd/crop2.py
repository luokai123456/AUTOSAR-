import os
from PIL import Image

src = r"C:\Users\11401\.dsh\attachments\v1\objects\8d\8d62f836478f02f70142fe9408fc6b7e3e3754fd0fd6032988b25d17fa7cee54"
out = r"C:\Users\11401\Desktop\学习\_canfd"
im = Image.open(src).convert("RGB")

def crop(name, box, scale):
    c = im.crop(box)
    c = c.resize((c.width*scale, c.height*scale), Image.NEAREST)
    c.save(os.path.join(out, name))
    print(name, c.size)

crop("wf_a.png", (0, 145, 200, 300), 6)
crop("wf_b.png", (200, 145, 400, 300), 6)
crop("wf_c.png", (880, 145, 1030, 300), 6)
crop("wf_top.png", (0, 0, 1216, 40), 2)

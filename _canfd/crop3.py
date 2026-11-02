import os
from PIL import Image, ImageDraw

src = r"C:\Users\11401\.dsh\attachments\v1\objects\8d\8d62f836478f02f70142fe9408fc6b7e3e3754fd0fd6032988b25d17fa7cee54"
out = r"C:\Users\11401\Desktop\学习\_canfd"
im = Image.open(src).convert("RGB")

boxes = [(0,8,"A0"), (6,48,"A1 CRC"), (44,62,"A2"), (652,706,"B stuff+CRC"), (700,720,"B tail"),
         (1003,1036,"C E"), (250,330,"B wide"), (336,378,"B x338-375"), (374,400,"B 375-400")]
scale = 12
pad = 6
heights = [ (b[1]-b[0])*scale for b in boxes ]
W = max(heights) + 240
H = sum((b[1]-b[0])*0 for b in boxes) + len(boxes)*( (180-155)*scale + 30 )
img = Image.new("RGB", (W, H), (20,20,24))
d = ImageDraw.Draw(img)
y = 5
for (x0,x1,label) in boxes:
    c = im.crop((x0,155,x1,180)).resize(((x1-x0)*scale, 25*scale), Image.NEAREST)
    img.paste(c, (0,y))
    d.text(( (x1-x0)*scale + 10, y + 40), f"{label}  x={x0}..{x1}", fill=(255,255,0))
    y += 25*scale + 30
img.save(os.path.join(out,"boxes.png"))
print("saved", img.size)

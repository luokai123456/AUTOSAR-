import numpy as np
from PIL import Image

src = r"C:\Users\11401\.dsh\attachments\v1\objects\8d\8d62f836478f02f70142fe9408fc6b7e3e3754fd0fd6032988b25d17fa7cee54"
im = np.asarray(Image.open(src).convert("RGB")).astype(int)
H, W, _ = im.shape

print("colors at selected rows (x=5):")
for y in [0,2,5,8,9,20,30,140,150,155,158,159,160,161,170,175,176,180,200,250,290,291,292,300,320,400,500]:
    print(y, tuple(im[y,5]), tuple(im[y,600]), tuple(im[y,1200]))

print()
print("row 159 colors sample:", [tuple(im[159,x]) for x in [0,5,20,100,200,300,500,700,900,1100,1215]])
print("row 291 colors sample:", [tuple(im[291,x]) for x in [0,5,20,100,200,300,500,700,900,1100,1215]])
print("row 176 colors sample:", [tuple(im[176,x]) for x in [0,5,20,100,200,300,500,700,900,1100,1215]])

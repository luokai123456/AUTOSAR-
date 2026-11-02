import numpy as np
from PIL import Image

src = r"C:\Users\11401\.dsh\attachments\v1\objects\8d\8d62f836478f02f70142fe9408fc6b7e3e3754fd0fd6032988b25d17fa7cee54"
im = np.asarray(Image.open(src).convert("RGB")).astype(int)
R, G, B = im[:,:,0], im[:,:,1], im[:,:,2]

blue = (B > 150) & (B > R + 40) & (R < 150)
green = (G > 150) & (G > R + 40) & (G > B + 40)
print("blue cols:", np.where(blue.any(axis=0))[0])
print("green cols:", np.where(green.any(axis=0))[0])
print("blue rows range:", np.where(blue.any(axis=1))[0].min(), np.where(blue.any(axis=1))[0].max())
print("green rows range:", np.where(green.any(axis=1))[0].min(), np.where(green.any(axis=1))[0].max())
# red-ish
red = (R > 120) & (R > G + 40) & (R > B + 40)
print("red cols:", np.where(red.any(axis=0))[0][:50], "rows:", np.where(red.any(axis=1))[0][:50])

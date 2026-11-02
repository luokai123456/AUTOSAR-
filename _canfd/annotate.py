import os
from PIL import Image, ImageDraw, ImageFont

src = r"C:\Users\11401\.dsh\attachments\v1\objects\8d\8d62f836478f02f70142fe9408fc6b7e3e3754fd0fd6032988b25d17fa7cee54"
out = r"C:\Users\11401\Desktop\学习\_canfd\canfd_error_annotated.png"
S = 2
TOP = 320
im = Image.open(src).convert("RGB")
W, H = im.size
img = Image.new("RGB", (W*S, H*S + TOP), (16, 16, 20))
img.paste(im.resize((W*S, H*S), Image.LANCZOS), (0, TOP))
d = ImageDraw.Draw(img)
f_big = ImageFont.truetype(r"C:\Windows\Fonts\msyhbd.ttc", 30)
f_mid = ImageFont.truetype(r"C:\Windows\Fonts\msyh.ttc", 21)
f_sm  = ImageFont.truetype(r"C:\Windows\Fonts\msyh.ttc", 17)

def X(x): return int(x*S)
def Y(y): return int(y*S) + TOP

d.text((20, 12), "CAN FD 错误帧：位域定位与原因分析", font=f_big, fill=(255,220,90))
d.text((20, 52), "① 标称段 ≈7.2 px/bit，数据段 ≈1.8 px/bit（约 4:1 → BRS 已开启，典型 500k/2M）", font=f_mid, fill=(190,220,255))
d.text((20, 80), "② 正常帧（x≈244）：SOF | ID=0x130 | RRS=0 | IDE=1(标准帧) | FDF=0(FD) | res | BRS=0(切换) | ESI=1(错误被动) | DLC | DATA | S(StuffCnt) | CRC | …  ACK=隐性(无人应答)", font=f_mid, fill=(170,255,170))
d.text((20, 108), "③ 出错帧（x≈902）：前 13 位与②完全相同（SOF+ID+RRS），之后 FDF/EDL 位只剩 ≈1 个数据位宽的显性脉冲，随后总线一直隐性 → 帧被截断", font=f_mid, fill=(255,170,170))
d.text((20, 136), "④ 解码器在 x≈1005…1034 给出 “E”（错误），该帧没有任何字段框 → 错误位域 = FDF/EDL 位及其后的保留位 res（控制段开头）", font=f_mid, fill=(255,180,120))
d.text((20, 164), "⑤ 帧间隔 ≈200 px ≈26 个标称位 ≈ 被动错误帧(6) + 错误界定符(8) + 间歇(3) + 挂起传输(8) → 上一帧很可能因“无应答”报了 ACK 错误", font=f_mid, fill=(200,200,255))
d.text((20, 192), "⑥ 蓝/绿竖线 = 软件里的两组测量光标：正好框住两帧相同的仲裁段（各 94 px），说明是同一个 ID 的重发/周期帧", font=f_mid, fill=(170,170,170))

b = 7.2
x0 = 244.5
for k in range(0, 18):
    xe = x0 + b*k
    d.line([(X(xe), Y(178)), (X(xe), Y(298))], fill=(0,190,255), width=1)
    d.text((X(xe)-5, Y(300)), str(k), font=f_sm, fill=(0,190,255))
d.line([(X(x0), Y(150)), (X(x0+7.2*17), Y(150))], fill=(0,220,255), width=2)
d.text((X(x0+10), Y(150)-28), "标称速率区 17 位：SOF(0) ID(1-11) RRS(12) IDE(13) FDF(14) res(15) BRS(16)", font=f_sm, fill=(0,230,255))

d.line([(X(370), Y(140)), (X(700), Y(140))], fill=(120,255,120), width=2)
d.text((X(378), Y(140)-26), "数据段 @4 倍速率：ESI / DLC / Data / Stuff Count / CRC-21", font=f_sm, fill=(140,255,140))

d.rectangle([X(703), Y(150), X(718), Y(182)], outline=(255,150,0), width=2)
d.text((X(660), Y(120)+TOP-TOP+40-40), "", font=f_sm, fill=(255,160,40))
d.text((X(722), Y(120)), "ACK 槽（应为显性）= 隐性 → 总线上没有节点应答", font=f_sm, fill=(255,160,40))

d.rectangle([X(897), Y(150), X(1040), Y(302)], outline=(255,60,60), width=3)
d.rectangle([X(999), Y(172), X(1008), Y(298)], outline=(255,0,0), width=3)
d.text((X(905), Y(330)), "帧3：仲裁段后停止发送", font=f_sm, fill=(255,80,80))

d.text((X(1005), Y(90)), "FDF/EDL 位只剩 ~1.8 px 显性（≈1 个数据位）", font=f_sm, fill=(255,90,90))
d.text((X(1005), Y(112)), "→ 采样为隐性（被当作经典 CAN 帧）", font=f_sm, fill=(255,90,90))
d.text((X(1005), Y(134)-TOP+TOP), "", font=f_sm, fill=(255,90,90))

for xf, lbl in [(244.5, "帧2 起点"), (901.9, "帧3 起点")]:
    d.line([(X(xf), Y(176)), (X(xf), Y(310))], fill=(255,255,0), width=1)
    d.text((X(xf)+4, Y(312)), lbl, font=f_sm, fill=(255,255,0))

img.save(out)
print("saved", out, img.size)

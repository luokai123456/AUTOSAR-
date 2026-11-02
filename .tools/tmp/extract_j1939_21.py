# -*- coding: utf-8 -*-
import sys
sys.path.insert(0, r'C:\Users\11401\Desktop\学习\.tools\pypdf')
from pypdf import PdfReader

src = r'C:\Users\11401\Desktop\学习\J1939\J1939-21(Dec2010) Data Link Layer.pdf'
out = r'C:\Users\11401\Desktop\学习\.tools\tmp\J1939-21-2010_text.txt'

reader = PdfReader(src)
with open(out, 'w', encoding='utf-8') as f:
    for i, page in enumerate(reader.pages, 1):
        f.write('\n===== PAGE %d =====\n' % i)
        f.write(page.extract_text() or '')
print('pages:', len(reader.pages))
print('out:', out)

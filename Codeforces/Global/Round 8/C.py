import os
from sys import stderr
from math import sqrt, ceil
n = int(input())
k = ceil(sqrt(n))
x, y = 0, 0
i = 1
j = 1
c = 1
d = 0
li = (3 * n + 4) * [None]
s = "{} {}"
li[0] = s.format(-1, -1)
li[1] = s.format(0, -1)
for i in range(n):
    li[2+3 * i] = s.format(x - 1, y)
    li[2+3 * i + 1] = s.format(x, y)
    li[2 + 3 * i + 2] = s.format(x + 1, y)
    x += 1
    y += 1
li[3*n+2] = s.format(x, y)
li[3*n + 3] = s.format(x-1, y)
out = str(3*n+4)+'\n'
out += '\n'.join(li)
out = out.encode(encoding='UTF-8')
os.write(1, out)

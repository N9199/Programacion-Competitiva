import os
from math import pow, ceil

k = int(input())
temp1 = 1
for i in range(1, 41):
    temp1 = pow(i, 10)
    if temp1 >= k:
        break

ans = ""
s = "codeforces"
c = 10*[0]
temp = 1
for j in range(10):
    c[j] = i
    temp1 //= i
    temp *= i
    if pow(i - 1, 9 - j) * temp >= k:
        for l in range(j + 1, 10):
            c[l] = i - 1
        break

for j in range(10):
    ans += c[j] * s[j]

out = ans
out = out.encode(encoding='UTF-8')
os.write(1, out)

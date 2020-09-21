from sys import stderr
import os
t = int(input())
out = ""
for _ in range(t):
    n, s = list(map(int, input().split()))
    temp_s = 0
    temp = n
    while temp > 0:
        temp_s += temp % 10
        temp //= 10
    ans = 0
    temp = n
    i = 0
    while temp_s > s:
        if temp % 10 == 0:
            i += 1
            temp //= 10
            continue
        if temp % 10 == 9:
            ans += 10 ** i
            while temp % 10 == 9:
                i += 1
                temp_s -= 9
                temp //= 10
            temp += 1
            temp_s += 1
        else:
            ans += (10 - temp % 10) * 10 ** i
            temp_s -= (temp % 10) - 1
            temp //= 10
            temp += 1
            i += 1
    
    out += str(ans) + '\n'
out = out.encode(encoding='UTF-8')
os.write(1, out)

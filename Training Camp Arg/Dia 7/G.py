from math import gcd
import os

t = int(input())
out = []
ans = []
for _ in range(t):
    a, b = list(map(int, input().split()))
    g = gcd(a,b)
    a, b = a // g, b // g
    ans.clear()
    # n=k
    if (2 * a) % b == 0:
        if (2 * a) // b >= 2:
            ans.append(((2 * a) // b, (2 * a) // b))
        if (2 * a) // b >= 4:
            ans.append(((2 * a) // b - 2, 1))
    k = a // b  # k'
    # n<k
    # k=2*k'
    k2 = 2 * k
    n = ((k2 - 1) * (2 * b + b * k2 - 2 * a)) // (2 * b) + 1
    if a * (k2 - 1) == b * (k2 * (k2 + 1) // 2 - n) and n <= k2 and 1 <= n and k2>1:
        ans.append((k2, n))
    # k = 2*k'+1
    # k'=floor(a/b)
    k2 = 2 * k + 1
    n = ((k2 - 1) * (2 * b + b * k2 - 2 * a)) // (2 * b) + 1
    if a * (k2 - 1) == b * (k2 * (k2 + 1) // 2 - n) and n <= k2 and 1 <= n and k2>1:
        ans.append((k2, n))
    # k'+1=floor(a/b)
    k -= 1
    k2 = 2 * k + 1
    n = ((k2 - 1) * (2 * b + b * k2 - 2 * a)) // (2 * b) + 1
    if a * (k2 - 1) == b * (k2 * (k2 + 1) // 2 - n) and n <= k2 and 1 <= n and k2>1:
        ans.append((k2, n))
    
    ans = set(ans)
    ans = list(ans)
    ans.sort()
    out.append((len(ans),))
    for e in ans:
        out.append(e)


out = '\n'.join(map(lambda x: ' '.join(map(str, x)), out))
out = out.encode(encoding='UTF-8')
os.write(1, out)


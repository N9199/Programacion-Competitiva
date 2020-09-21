import os

def f(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    i = 0
    while 2 ** i < n:
        i += 1
    i -= 1
    if 2 ** (i + 1) == n:
        return 2 ** (i + 2) - 1
    return (2 ** (i + 1) - 1) + f(n - 2 ** i)

t = int(input())
ans = t*[None]
for i in range(t):
    n = int(input())
    ans[i] = str(f(n))
out = '\n'.join(ans)
out = out.encode(encoding='UTF-8')
os.write(1, out)

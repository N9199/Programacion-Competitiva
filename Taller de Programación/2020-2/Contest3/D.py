import os
t = int(input())
out = ""
for _ in range(t):
    n, u = list(map(int, input().split()))
    a = n * [0]
    for _ in range(u):
        x, y, val = list(map(int, input().split()))
        a[x] += val
        if y + 1 < n:
            a[y + 1] -= val

    for i in range(1, n):
        a[i] += a[i - 1]
    q = int(input())
    for _ in range(q):
        i = int(input())
        out += str(a[i])+'\n'
    
out = out.encode(encoding='UTF-8')
os.write(1, out)
q = int(input())
for _ in range(q):
    n = int(input())
    t = list(map(int, input().split()))
    s = set(t)
    mc = min(len(s), 3)
    c = n*[0]
    for i in range(n):
        if i==0:
            c[i]=1
        elif t[i]!=t[i-1]:
            
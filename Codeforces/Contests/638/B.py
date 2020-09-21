t = int(input())
for _ in range(t):
    n, k = list(map(int, input().split()))
    a = list(map(int, input().split()))
    s = set(a)
    if len(s) > k:
        print(-1)
        continue
    
    accum = 0
    for i in range(k):
        accum += a[i]
    i = k
    while i < len(a):
        

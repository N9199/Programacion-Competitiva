t = int(input())
for _ in range(t):
    n, x = list(map(int, input().split()))
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    accum = 0
    for i in range(n):
        accum += a[i]
        if accum < (i + 1) * x:
            break
    if accum >= (i + 1) * x:
        i += 1
    print(i)

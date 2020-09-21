t = int(input())
for _ in range(t):
    a, b, n = list(map(int, input().split()))
    if b < a:
        a, b = b, a
    i = 0
    while b <= n:
        a += b
        a, b = min(a, b), max(a, b)
        i += 1
    print(i)

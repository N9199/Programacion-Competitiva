t = int(input())
for _ in range(t):
    a, b, x, y, n = list(map(int, input().split()))
    if max(a-n, x) > max(b-n, y):
        a, b = b, a
        x, y = y, x
    d = a - x
    a = max(a - n, x)
    if a > x:
        print(a * b)
        continue
    n -= d
    b = max(b - n, y)
    print(a * b)

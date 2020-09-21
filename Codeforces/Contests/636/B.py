t = int(input())
for _ in range(t):
    n = int(input())
    n //= 2
    if n % 2 == 1:
        print("NO")
    else:
        print("YES")
        a = (2 * n) * [0]
        s = 0
        for i in range(n):
            a[i] = 2 * (i + 1)
            s += a[i]
        for i in range(n - 1):
            a[n + i] = 2 * i + 1
            s -= a[n + i]
        a[-1] = s
        print(' '.join(list(map(lambda x: str(x), a))))
t = int(input())
for _ in range(t):
    a, b = list(map(int, input().split()))
    d = abs(b - a)
    dm = d % 10
    d -= dm
    ans = d // 10
    if dm > 0:
        ans += 1
    print(ans)
    
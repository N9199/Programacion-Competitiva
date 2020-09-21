t = int(input())
for _ in range(t):
    n, m, k = list(map(int, input().split()))
    ans = min(n // k, m)
    ans -= (m - ans + n - 2) // (n - 1)
    print(ans)

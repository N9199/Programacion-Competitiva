t = int(input())
for _ in range(t):
    n, k = list(map(int, input().split()))
    ans = (n // k) * k + min(k // 2, n % k)
    print(ans)

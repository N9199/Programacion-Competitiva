t = int(input())
for _ in range(t):
    n, m = list(map(int, input().split()))
    ans = ""
    for i in range(n - 1):
        ans += m * "B" + "\n"
    ans += (m - 1) * "B" + "W"
    print(ans)

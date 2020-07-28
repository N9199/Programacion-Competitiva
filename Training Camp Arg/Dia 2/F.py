n, k = list(map(int, input().split()))
dp = [[0 for i in range(k+1)] for j in range(n+1)]
MOD = int(1e9)+7
for i in range(n + 1):
    dp[i][0] = 0
    dp[i][1] = 1
for i in range(k + 1):
    dp[0][i] = 0

for j in range(1,k):
    for i in range(1, n + 1):
        for d in range(i, n + 1, i):
            dp[d][j + 1] += dp[i][j]
            dp[d][j + 1] %= MOD

print(dp[n][k])
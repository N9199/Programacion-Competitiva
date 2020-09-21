n, m = list(map(int, input().split()))
mat = n * [None]
for i in range(n):
    mat[i] = list(map(int, input().split()))

dp = (n + 1) * [None]
for i in range(n+1):
    dp[i] = (m+1) * [0]
dp[0][1] = mat[0][0]

for i in range(n):
    for j in range(m):
        dp[i+1][j+1] = max(dp[i][j+1] & mat[i][j],
                           dp[i+1][j] & mat[i][j])
print(dp)
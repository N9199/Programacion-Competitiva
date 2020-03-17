import sys


def p(n):
    global dp
    if n < 0:
        return 0
    if n >= len(dp):
        dp += max(n-len(dp)+1, len(dp)) * [None]
    elif dp[n] is not None:
        return dp[n]
    ans = 0
    k = 1
    while n - (k * (3 * k - 1)) // 2 >= 0:
        # print(n - (k * (3 * k - 1)) // 2, file=sys.stderr)
        if k % 2 == 1:
            ans += p(n - k * (3 * k - 1) // 2) + \
                p(n - k * (3 * k + 1) // 2)
        else:
            ans -= p(n - k * (3 * k - 1) // 2) + \
                p(n - k * (3 * k + 1) // 2)
        k += 1
    dp[n] = ans
    return ans


dp = 100 * [None]
dp[0] = 1

n = 1
while p(n) % 1000000 != 0:
    n += 1
print(n)
print(p(n))
